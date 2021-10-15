#ifndef CAYLEY_COMMON_H
#define CAYLEY_COMMON_H

#define _USE_MATH_DEFINES
#include <math.h>

#define X _vecdata[0]
#define Y _vecdata[1]
#define Z _vecdata[2]
#define W _vecdata[3]

#define M2X2_X1 _matdata[0]
#define M2X2_Y1 _matdata[1]
#define M2X2_X2 _matdata[2]
#define M2X2_Y2 _matdata[3]

#define M3X3_X1 _matdata[0]
#define M3X3_Y1 _matdata[1]
#define M3X3_Z1 _matdata[2]
#define M3X3_X2 _matdata[3]
#define M3X3_Y2 _matdata[4]
#define M3X3_Z2 _matdata[5]
#define M3X3_X3 _matdata[6]
#define M3X3_Y3 _matdata[7]
#define M3X3_Z3 _matdata[8]

#define M4X4_X1 _matdata[0]
#define M4X4_Y1 _matdata[1]
#define M4X4_Z1 _matdata[2]
#define M4X4_W1 _matdata[3]
#define M4X4_X2 _matdata[4]
#define M4X4_Y2 _matdata[5]
#define M4X4_Z2 _matdata[6]
#define M4X4_W2 _matdata[7]
#define M4X4_X3 _matdata[8]
#define M4X4_Y3 _matdata[9]
#define M4X4_Z3 _matdata[10]
#define M4X4_W3 _matdata[11]
#define M4X4_X4 _matdata[12]
#define M4X4_Y4 _matdata[13]
#define M4X4_Z4 _matdata[14]
#define M4X4_W4 _matdata[15]

#define radtodeg(a) (a * (180.0 / M_PI))
#define degtorad(a) (a * (M_PI / 180.0))

#ifdef CAYLEY_SHARED_DEFINE
#ifdef CAYLEY_EXPORTS
#define CAYLEY_API __declspec(dllexport)
#else
#define CAYLEY_API __declspec(dllimport)
#endif
#else
#define CAYLEY_API
#endif

CAYLEY_API double fclamp(double x, double min, double max);

#endif