#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/mat2.h"

mat2 make_mat2(float x1, float y1, float x2, float y2) {
  mat2 m;
  m.M2X2_X1 = x1;
  m.M2X2_Y1 = y1;
  m.M2X2_X2 = x2;
  m.M2X2_Y2 = y2;
  return m;
}

mat2 mat2_transpose(mat2 a) {
  return make_mat2(a.M2X2_X1, a.M2X2_X2, 
                   a.M2X2_Y1, a.M2X2_Y2);
}

float mat2_determinant(mat2 a) {
  return (a.M2X2_X1 * a.M2X2_Y2 - a.M2X2_X2 * a.M2X2_Y1);
}