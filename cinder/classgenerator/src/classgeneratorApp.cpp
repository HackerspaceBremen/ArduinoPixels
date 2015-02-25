//
//  classgeneratorApp.cpp
//
//  Created by Kris Temmerman
//  Modified by Hans Robeers: - Replace cinder dependency by boost::gil
//                            - Stack allocation of data (lower memory footprint & increased performance)
//

#include <fstream>
#include <iostream>
#include <stdint.h>
#include <boost/filesystem.hpp>

#define int_p_NULL (int*)NULL
#include <boost/gil/extension/io/png_io.hpp>
#include <libpng16/png.h>

using namespace std;
using namespace boost::gil;
namespace fs = boost::filesystem;

void setFile(rgba8_image_t &image, string name);
int getIndex(int r, int g,int b,int a);
vector<int> colorData;

int main(int argc, char *argv[])
{
    string filetype = ".png";
    string assetFolder;

    if (argc == 2)
        assetFolder = argv[1];
    else
        assetFolder = string(GENERATOR_DIR) + "/../../assets/";

    fs::path p( assetFolder );
    cout << "Parsing " << p.string() << endl;
    for( fs::directory_iterator it( p ); it != fs::directory_iterator(); ++it ) {
        if( ! is_directory( *it ) )
        {
            if (filetype.compare(it->path().extension().string()) == 0)
            {
                cout << "   " << it->path().string()<<endl;;

                rgba8_image_t image;
                png_read_and_convert_image(it->path().string(), image);

                string myString=it->path().filename().string();
                string name  = myString.substr(0, myString.size()-4);

                setFile(image, name);
            }
        }
    }

    return 0;
}

void setFile(rgba8_image_t &image, string name)
{
    colorData.clear();

    int w = image.width();
    int h = image.height();

    // skip files that don't fit the screen
    if (h > 20 || w > 90)
        return;

    ofstream oStream ;
    string filename= string(GENERATOR_DIR) + "/../../libraries/PixelShared/Data";
//    string filename= "/tmp/libraries/PixelShared/";
    filename += name + ".h";
     cout <<"writing:  "<<filename<<" "<<endl;
    oStream.open(filename.c_str() );
     oStream << "//generated pixeldata"<< endl;
    oStream << "#ifndef _Data" <<name <<"_h"<< endl;
    oStream <<  "#define _Data" <<name <<"_h"<< endl;
     oStream <<  "#include \"PixelData.h\""<< endl;

     oStream << "namespace _" << name << "_ {" << endl;
    oStream << "    const uint8_t indices[" << w*h << "] = {"<<endl;

    for (int j=0;j<w*h;j++)
    {
         oStream << "        ";
         if (j!=0) oStream << ",";
         oStream << getIndex(image._view[j][0],
                             image._view[j][1],
                             image._view[j][2],
                             image._view[j][3]);
         oStream << endl;
    }
    oStream << "    };"<<endl;


    oStream << "    const uint8_t color[" << colorData.size() << "] = {" <<endl;
    for (unsigned int j=0;j<colorData.size();j+=4)
    {
        oStream << "        ";
        if (j!=0) oStream << ",";
        oStream << colorData[j] <<endl;
        oStream << "        ,"<< colorData[j+1] <<endl;
        oStream << "        ,"<< colorData[j+2] <<endl;
        oStream << "        ,"<< colorData[j+3] <<endl;
    }
    oStream << "    };"<<endl;
    oStream << "}" << endl;

    oStream << "template<int8_t WidthOffset=0, int8_t HeightOffset=0>" << endl;
    oStream << "struct Data"<< name <<" : public PixelDataImpl<Data" << name << "<WidthOffset, HeightOffset> > {"<< endl;
    oStream << "       static constexpr uint8_t width() { return "<< w <<"; }"<<endl;
    oStream << "       static constexpr uint8_t height() { return "<< h <<"; }" <<endl;
    oStream << "       static constexpr int8_t widthOffset() { return WidthOffset; }"<<endl;
    oStream << "       static constexpr int8_t heightOffset() { return HeightOffset; }" <<endl;
    oStream << "       static constexpr const uint8_t* indices() { return _" << name << "_::indices; }" <<endl;
    oStream << "       static constexpr const uint8_t* color() { return _" << name << "_::color; }" <<endl;
    oStream << "       constexpr Data"<< name <<"(){}" <<endl;
    oStream << "};"<< endl;
    oStream << "#endif" << endl;

    oStream.close();


}

int getIndex(int r, int g,int b,int a)
{
    if(a==0)return 255;

    for (unsigned int j=0;j<colorData.size();j+=4)
    {
        if(colorData[j]==r  && colorData[j+1]==g && colorData[j+2]==b && colorData[j+3]==a )
        {
            return j;
        }
    }

    colorData.push_back(r);
    colorData.push_back(g);
    colorData.push_back(b);
    colorData.push_back(a);
   
    return colorData.size()-4;
}
