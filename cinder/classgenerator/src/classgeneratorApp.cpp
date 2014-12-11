//
//  classgeneratorApp.cpp
//
//  Created by Kris Temmerman
//  Modified by Hans Robeers: Replace cinder dependency by boost::gil
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
    oStream << "class Data"<<name <<":public PixelData{ "<< endl;
    oStream << "public:"<< endl;


     oStream <<"    Data"<<name<< "()"<< endl;
     oStream << "   {"<< endl;

    oStream << "       width ="<< w<<";"<<endl;
    oStream << "        height="<< h<<";" <<endl;
    int w2  =w/2;

    oStream << "       centerX="<< w2<<";"<<endl;
    oStream << "        centerY="<< h<<";" <<endl;
    oStream << "        int size =width*height;"<<endl;
    oStream << "        indices= new uint8_t[size];"<<endl;
    //oStream << "        alpha = new uint8_t[size];"<<endl;

    for (int j=0;j<w*h;j++)
    {
        int r = image._view[j][0];
        int g = image._view[j][1];
        int b = image._view[j][2];
        int a = image._view[j][3];

         oStream << "        indices["<<j<<"]="<< getIndex(r,g,b,a)<<";"<<endl;

    }
     oStream << "        color= new uint8_t["<<colorData.size() <<"];"<<endl;


    for (unsigned int j=0;j<colorData.size();j+=4)
    {
        int r=colorData[j ];
        int g=colorData[j+1 ];
        int b=colorData[j+2 ];
        int a=colorData[j +3];
        oStream << "        color["<< (j)<<"] ="<< r<<";"<<endl;
        oStream << "        color["<< (j+1)<<"] ="<< g<<";"<<endl;
        oStream << "        color["<< (j+2)<<"] ="<< b<<";"<<endl;
        oStream << "        color["<< (j+3)<<"] ="<< a<<";"<<endl;
    }



     oStream << "   };"<< endl;

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
