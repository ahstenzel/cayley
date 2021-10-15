#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/mat3.h"
#include "cayley/detail/mat2.h"

mat3 make_mat3(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3) {
  mat3 m;
  m.M3X3_X1 = x1; m.M3X3_Y1 = y1; m.M3X3_Z1 = z1;
  m.M3X3_X2 = x2; m.M3X3_Y2 = y2; m.M3X3_Z2 = z2;
  m.M3X3_X3 = x3; m.M3X3_Y3 = y3; m.M3X3_Z3 = z3;
  return m;
}

mat3 mat3_transpose(mat3 a) {
  return make_mat3(a.M3X3_X1, a.M3X3_X2, a.M3X3_X3, 
                   a.M3X3_Y1, a.M3X3_Y2, a.M3X3_Y3, 
                   a.M3X3_Z1, a.M3X3_Z2, a.M3X3_Z3);
}

float mat3_determinant(mat3 a) {
  mat2 sub;
  float det = 0.0f;

  sub.M2X2_X1 = a.M3X3_Y2;
  sub.M2X2_Y1 = a.M3X3_Z2;
  sub.M2X2_X2 = a.M3X3_Y3;
  sub.M2X2_Y2 = a.M3X3_Z3;
  det += (a.M3X3_X1 * mat2_determinant(sub));

  sub.M2X2_X1 = a.M3X3_Y1;
  sub.M2X2_Y1 = a.M3X3_Z1;
  sub.M2X2_X2 = a.M3X3_Y3;
  sub.M2X2_Y2 = a.M3X3_Z3;
  det -= (a.M3X3_X2 * mat2_determinant(sub));

  sub.M2X2_X1 = a.M3X3_Y1;
  sub.M2X2_Y1 = a.M3X3_Z1;
  sub.M2X2_X2 = a.M3X3_Y2;
  sub.M2X2_Y2 = a.M3X3_Z2;
  det += (a.M3X3_X3 * mat2_determinant(sub));
  return det;
}