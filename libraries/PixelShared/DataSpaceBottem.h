//generated pixeldata
#ifndef _DataSpaceBottem_h
#define _DataSpaceBottem_h
#include "PixelData.h"
class DataSpaceBottem:public PixelData{ 
public:
    DataSpaceBottem()
   {
       width =20;
        height=7;
       centerX=10;
        centerY=7;
        int size =width*height;
        indices= new uint8_t[size];
        indices[0]=255;
        indices[1]=255;
        indices[2]=255;
        indices[3]=255;
        indices[4]=255;
        indices[5]=255;
        indices[6]=0;
        indices[7]=4;
        indices[8]=8;
        indices[9]=4;
        indices[10]=0;
        indices[11]=0;
        indices[12]=12;
        indices[13]=12;
        indices[14]=12;
        indices[15]=255;
        indices[16]=255;
        indices[17]=255;
        indices[18]=255;
        indices[19]=255;
        indices[20]=255;
        indices[21]=255;
        indices[22]=255;
        indices[23]=16;
        indices[24]=16;
        indices[25]=16;
        indices[26]=20;
        indices[27]=24;
        indices[28]=20;
        indices[29]=16;
        indices[30]=16;
        indices[31]=16;
        indices[32]=28;
        indices[33]=28;
        indices[34]=28;
        indices[35]=28;
        indices[36]=32;
        indices[37]=255;
        indices[38]=255;
        indices[39]=255;
        indices[40]=255;
        indices[41]=36;
        indices[42]=36;
        indices[43]=36;
        indices[44]=36;
        indices[45]=40;
        indices[46]=44;
        indices[47]=40;
        indices[48]=36;
        indices[49]=36;
        indices[50]=36;
        indices[51]=36;
        indices[52]=36;
        indices[53]=48;
        indices[54]=48;
        indices[55]=48;
        indices[56]=52;
        indices[57]=52;
        indices[58]=52;
        indices[59]=255;
        indices[60]=56;
        indices[61]=56;
        indices[62]=60;
        indices[63]=64;
        indices[64]=68;
        indices[65]=72;
        indices[66]=76;
        indices[67]=56;
        indices[68]=56;
        indices[69]=56;
        indices[70]=56;
        indices[71]=56;
        indices[72]=56;
        indices[73]=56;
        indices[74]=80;
        indices[75]=84;
        indices[76]=84;
        indices[77]=84;
        indices[78]=84;
        indices[79]=88;
        indices[80]=56;
        indices[81]=56;
        indices[82]=60;
        indices[83]=64;
        indices[84]=92;
        indices[85]=96;
        indices[86]=76;
        indices[87]=56;
        indices[88]=56;
        indices[89]=56;
        indices[90]=56;
        indices[91]=56;
        indices[92]=56;
        indices[93]=56;
        indices[94]=80;
        indices[95]=84;
        indices[96]=84;
        indices[97]=84;
        indices[98]=84;
        indices[99]=88;
        indices[100]=255;
        indices[101]=36;
        indices[102]=36;
        indices[103]=36;
        indices[104]=36;
        indices[105]=40;
        indices[106]=100;
        indices[107]=40;
        indices[108]=36;
        indices[109]=36;
        indices[110]=36;
        indices[111]=36;
        indices[112]=48;
        indices[113]=48;
        indices[114]=48;
        indices[115]=48;
        indices[116]=48;
        indices[117]=48;
        indices[118]=48;
        indices[119]=255;
        indices[120]=255;
        indices[121]=255;
        indices[122]=255;
        indices[123]=104;
        indices[124]=255;
        indices[125]=255;
        indices[126]=255;
        indices[127]=255;
        indices[128]=255;
        indices[129]=255;
        indices[130]=255;
        indices[131]=255;
        indices[132]=255;
        indices[133]=255;
        indices[134]=255;
        indices[135]=255;
        indices[136]=104;
        indices[137]=255;
        indices[138]=255;
        indices[139]=255;
        color= new uint8_t[108];
        color[0] =39;
        color[1] =45;
        color[2] =67;
        color[3] =255;
        color[4] =60;
        color[5] =65;
        color[6] =76;
        color[7] =255;
        color[8] =67;
        color[9] =72;
        color[10] =76;
        color[11] =255;
        color[12] =33;
        color[13] =40;
        color[14] =60;
        color[15] =255;
        color[16] =100;
        color[17] =108;
        color[18] =132;
        color[19] =255;
        color[20] =127;
        color[21] =131;
        color[22] =134;
        color[23] =255;
        color[24] =153;
        color[25] =155;
        color[26] =134;
        color[27] =255;
        color[28] =84;
        color[29] =90;
        color[30] =113;
        color[31] =255;
        color[32] =71;
        color[33] =77;
        color[34] =99;
        color[35] =255;
        color[36] =43;
        color[37] =50;
        color[38] =79;
        color[39] =255;
        color[40] =64;
        color[41] =71;
        color[42] =86;
        color[43] =255;
        color[44] =91;
        color[45] =96;
        color[46] =92;
        color[47] =255;
        color[48] =36;
        color[49] =43;
        color[50] =70;
        color[51] =255;
        color[52] =31;
        color[53] =37;
        color[54] =60;
        color[55] =255;
        color[56] =100;
        color[57] =108;
        color[58] =136;
        color[59] =255;
        color[60] =128;
        color[61] =132;
        color[62] =138;
        color[63] =255;
        color[64] =161;
        color[65] =161;
        color[66] =142;
        color[67] =255;
        color[68] =204;
        color[69] =200;
        color[70] =142;
        color[71] =255;
        color[72] =160;
        color[73] =160;
        color[74] =136;
        color[75] =255;
        color[76] =118;
        color[77] =123;
        color[78] =136;
        color[79] =255;
        color[80] =84;
        color[81] =90;
        color[82] =117;
        color[83] =255;
        color[84] =71;
        color[85] =77;
        color[86] =102;
        color[87] =255;
        color[88] =59;
        color[89] =65;
        color[90] =89;
        color[91] =255;
        color[92] =209;
        color[93] =204;
        color[94] =142;
        color[95] =255;
        color[96] =149;
        color[97] =150;
        color[98] =136;
        color[99] =255;
        color[100] =89;
        color[101] =94;
        color[102] =92;
        color[103] =255;
        color[104] =23;
        color[105] =27;
        color[106] =45;
        color[107] =255;
   };
};
#endif
