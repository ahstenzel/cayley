#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/mat4.h"
#include "cayley/detail/mat3.h"

mat4 make_mat4(float x1, float y1, float z1, float w1,
               float x2, float y2, float z2, float w2,
               float x3, float y3, float z3, float w3,
               float x4, float y4, float z4, float w4) {
  mat4 m;
  m.M4X4_X1 = x1; m.M4X4_Y1 = y1; m.M4X4_Z1 = z1; m.M4X4_W1 = w1;
  m.M4X4_X2 = x2; m.M4X4_Y2 = y2; m.M4X4_Z2 = z2; m.M4X4_W2 = w2;
  m.M4X4_X3 = x3; m.M4X4_Y3 = y3; m.M4X4_Z3 = z3; m.M4X4_W3 = w3;
  m.M4X4_X4 = x4; m.M4X4_Y4 = y4; m.M4X4_Z4 = z4; m.M4X4_W4 = w4;
  return m;
}

mat4 mat4_transpose(mat4 a) {
  return make_mat4(a.M4X4_X1, a.M4X4_X2, a.M4X4_X3, a.M4X4_X4,
                   a.M4X4_Y1, a.M4X4_Y2, a.M4X4_Y3, a.M4X4_Y4,
                   a.M4X4_Z1, a.M4X4_Z2, a.M4X4_Z3, a.M4X4_Z4,
                   a.M4X4_W1, a.M4X4_W2, a.M4X4_W3, a.M4X4_W4);
}

float mat4_determinant(mat4 a) {
  mat3 sub;
  float det = 0.0f;

  sub.M3X3_X1 = a.M4X4_Y2;
  sub.M3X3_Y1 = a.M4X4_Z2;
  sub.M3X3_Z1 = a.M4X4_W2;
  sub.M3X3_X2 = a.M4X4_Y3;
  sub.M3X3_Y2 = a.M4X4_Z3;
  sub.M3X3_Z2 = a.M4X4_W3;
  sub.M3X3_X3 = a.M4X4_Y4;
  sub.M3X3_Y3 = a.M4X4_Z4;
  sub.M3X3_Z3 = a.M4X4_W4;
  det += (a.M4X4_X1 * mat3_determinant(sub));

  sub.M3X3_X1 = a.M4X4_Y1;
  sub.M3X3_Y1 = a.M4X4_Z1;
  sub.M3X3_Z1 = a.M4X4_W1;
  sub.M3X3_X2 = a.M4X4_Y3;
  sub.M3X3_Y2 = a.M4X4_Z3;
  sub.M3X3_Z2 = a.M4X4_W3;
  sub.M3X3_X3 = a.M4X4_Y4;
  sub.M3X3_Y3 = a.M4X4_Z4;
  sub.M3X3_Z3 = a.M4X4_W4;
  det -= (a.M4X4_X2 * mat3_determinant(sub));

  sub.M3X3_X1 = a.M4X4_Y1;
  sub.M3X3_Y1 = a.M4X4_Z1;
  sub.M3X3_Z1 = a.M4X4_W1;
  sub.M3X3_X2 = a.M4X4_Y2;
  sub.M3X3_Y2 = a.M4X4_Z2;
  sub.M3X3_Z2 = a.M4X4_W2;
  sub.M3X3_X3 = a.M4X4_Y4;
  sub.M3X3_Y3 = a.M4X4_Z4;
  sub.M3X3_Z3 = a.M4X4_W4;
  det += (a.M4X4_X3 * mat3_determinant(sub));

  sub.M3X3_X1 = a.M4X4_Y1;
  sub.M3X3_Y1 = a.M4X4_Z1;
  sub.M3X3_Z1 = a.M4X4_W1;
  sub.M3X3_X2 = a.M4X4_Y2;
  sub.M3X3_Y2 = a.M4X4_Z2;
  sub.M3X3_Z2 = a.M4X4_W2;
  sub.M3X3_X3 = a.M4X4_Y3;
  sub.M3X3_Y3 = a.M4X4_Z3;
  sub.M3X3_Z3 = a.M4X4_W3;
  det -= (a.M4X4_X4 * mat3_determinant(sub));
  return det;
}