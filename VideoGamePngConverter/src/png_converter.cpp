/*
file:			png_converter.cpp
description:	converter to generate a static compilable source file from a directory with png images.
				pass assest directory as argument.
author:			matthias
*/

// to work around C4996 compiler warning under vc11 (VS2012)
#define _CRT_SECURE_NO_DEPRECATE

#include <vector>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <streambuf>

#include "..\..\VideoGameLibs\lodepng\lodepng.h"
#include "..\..\VideoGameLibs\dirent\include\dirent.h"

using namespace std;

#define NUM_COUNT	12

string file_png_convert_in = "../src/png_converted_source.cpp";
string file_png_converted_out = "../src/png_converted.cpp";
string replace_marker = "/*[MARKER_FOR_ASSETS]*/";

string element_draft = " \
\tPNG* element[NUM] = new PNG(); \n\
\telement[NUM]->png_name = \"[FILE_NAME]\"; \n\
\telement[NUM]->w = [W]; \n\
\telement[NUM]->h = [H]; \n\
\telement[NUM]->bytes = element[NUM]->w * element[NUM]->h * 4; \n\
\tint element[NUM]_image_raw[] = {[ARRAY]}; \n\
\telement[NUM]->vector_array.assign(&element[NUM]_image_raw[0], &element[NUM]_image_raw[0] + element[NUM]->bytes); \n\
\tpng_array.push_back(*element[NUM]);\n";

string replace_string(string str, string marker, string replaced_with)
{
	size_t f = str.find(marker);
	return str.replace(f, marker.length(), replaced_with);
}

string convert_png_and_write_to_header(int num, char * path, char* assest_name)
{
	vector<unsigned char> image;
	image.clear();

	unsigned width = 0;
	unsigned height = 0;

	// build path togehter
	char asset_file[300];
	strcpy(asset_file, path);
	strcat(asset_file, assest_name);
	
	// load png
	unsigned error = lodepng::decode(image, width, height, asset_file);
				
	if(error != 0)
	{
		printf("error %d loading png %s\n", error, asset_file);
	}
	else
	{
		// get size of assest
		int size_in_bytes = width * height * 4;

		// do all string replacements
		string content = element_draft;
		for(int i = 0; i <= NUM_COUNT; i++)
		{
			content = replace_string(content, "[NUM]", to_string(num));
		}
		content = replace_string(content, "[FILE_NAME]", assest_name);
		content = replace_string(content, "[W]", to_string(width));
		content = replace_string(content, "[H]", to_string(height));

		string content_array = "";
		for(int i = 0; i < size_in_bytes; i++)
		{
			content_array = content_array + to_string(image.at(i));
			if(i < size_in_bytes - 1)
			{
				content_array = content_array + ", ";
			}
		}
		content = replace_string(content, "[ARRAY]", content_array);

		return content + "\n";
	}

	return "error loading png.";
}

int main(int argc, char **argv)
{
	// parse arguments
    if (argc != 1)
	{
		printf("parsing arguments ...\n\n");
		printf("folder to parse: %s\n\n", argv[1]);
		printf("file to use as templace: %s\n\n", file_png_convert_in.c_str());
		printf("file to write to: %s\n\n", file_png_converted_out.c_str());
    }

	DIR *dir;
	struct dirent *entry;
	string content_assests = "";
	int num = 0;

	printf("working ...\n");
	if((dir = opendir(argv[1])) != NULL) 
	{
		// iterate over items in source folder and write array to header file
		while((entry = readdir (dir)) != NULL) 
		{
			// exclude "." and ".." entries
			if(strcmp(entry->d_name, ".") == 1 && strcmp(entry->d_name, "..") == 1)
			{
				printf("converting: %s\n", entry->d_name);
				content_assests = content_assests + convert_png_and_write_to_header(num, argv[1], entry->d_name);
				num++;
			}
		}
		closedir(dir);

		ifstream inFile;
		inFile.open(file_png_convert_in);
		if(inFile != NULL)
		{
			stringstream strStream;
			strStream << inFile.rdbuf();
			string str = strStream.str();
		
			str = replace_string(str, replace_marker, content_assests);

			std::ofstream out(file_png_converted_out);
			out << str;
			out.close();

			printf("\nconverted %d files successfully.\n", num);
		}
		else
		{
			printf("\nerror opening template file.\n");
		}
	}
	else
	{
		printf("\ncould not open asset directory.\n");
	}

	// wait
	printf("\npress any key");
	getchar();


	return 0;
}
