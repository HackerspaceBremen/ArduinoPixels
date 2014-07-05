
#ifndef PNGHACK_H
#define PNGHACK_H

#include <vector>
#include <string>

using namespace std;

typedef struct PNG_TYP
{
    string png_name;
    unsigned w;
    unsigned h;
    unsigned bytes;
    unsigned char* parray;
    std::vector<unsigned char> vector_array;
} PNG;

void init_png_array(void);
int get_png(vector<unsigned char>* image, unsigned* w, unsigned* h, string sprite_path);

#endif
