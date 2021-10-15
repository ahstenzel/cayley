#ifndef CAYLEY_MAT2_H
#define CAYLEY_MAT2_H

#include "cayley/detail/common.h"
#include "cayley/detail/vec2.h"

#define mat2_identity make_mat2(1.0f, 0.0f, 0.0f, 1.0f);
#define mat2_isidentity(a) (a.M2X2_X1 == 1.0f && a.M2X2_Y1 == 0.0f && a.M2X2_X2 == 0.0f && a.M2X2_Y2 == 1.0f)
#define mat2_equal(a, b) (a.M2X2_X1 == b.M2X2_X1 && a.M2X2_Y1 == b.M2X2_Y1 && a.M2X2_X2 == b.M2X2_X2 && a.M2X2_Y2 == b.M2X2_Y2)
#define mat2_add(a, b) make_mat2(a.M2X2_X1 + b.M2X2_X1, a.M2X2_Y1 + b.M2X2_Y1,\
                                 a.M2X2_X2 + b.M2X2_X2, a.M2X2_Y2 + b.M2X2_Y2)
#define mat2_sub(a, b) make_mat2(a.M2X2_X1 - b.M2X2_X1, a.M2X2_Y1 - b.M2X2_Y1,\
                                 a.M2X2_X2 - b.M2X2_X2, a.M2X2_Y2 - b.M2X2_Y2)
#define mat2_scale(a, s) make_mat2(a.M2X2_X1 * s, a.M2X2_Y1 * s,\
                                   a.M2X2_X2 * s, a.M2X2_Y2 * s)
#define mat2_multiply(a, b) make_mat2(a.M2X2_X1*b.M2X2_X1 + a.M2X2_X2*b.M2X2_Y1,\
                                      a.M2X2_Y1*b.M2X2_X1 + a.M2X2_Y2*b.M2X2_Y1,\
                                      a.M2X2_X1*b.M2X2_X2 + a.M2X2_X2*b.M2X2_Y2,\
                                      a.M2X2_Y1*b.M2X2_X2 + a.M2X2_Y2*b.M2X2_Y2)
#define mat2_vec2_multiply(m, v) make_vec2(m.M2X2_X1*v.X + m.M2X2_X2*v.Y, m.M2X2_Y1*v.X + m.M2X2_Y2*v.Y)

typedef struct {
  float _matdata[4];
} mat2;

CAYLEY_API mat2 make_mat2(float x1, float y1,
               float x2, float y2);
CAYLEY_API mat2 mat2_transpose(mat2 a);
CAYLEY_API float mat2_determinant(mat2 a);

#endif