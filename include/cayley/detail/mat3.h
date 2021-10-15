#ifndef CAYLEY_MAT3_H
#define CAYLEY_MAT3_H

#include "cayley/detail/common.h"
#include "cayley/detail/vec3.h"

#define mat3_identity make_mat3(1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f);
#define mat3_isidentity(a) (a.M3X3_X1 == 1.0f && a.M3X3_Y1 == 0.0f && a.M3X3_Z1 == 0.0f && \
                            a.M3X3_X2 == 0.0f && a.M3X3_Y2 == 1.0f && a.M3X3_Z2 == 0.0f && \
                            a.M3X3_X3 == 0.0f && a.M3X3_Y3 == 0.0f && a.M3X3_Z3 == 1.0f)
#define mat3_equal(a, b) (a.M3X3_X1 == b.M3X3_X1 && a.M3X3_Y1 == b.M3X3_Y1 && a.M3X3_Z1 == b.M3X3_Z1 && \
                          a.M3X3_X2 == b.M3X3_X2 && a.M3X3_Y2 == b.M3X3_Y2 && a.M3X3_Z2 == b.M3X3_Z2 && \
                          a.M3X3_X3 == b.M3X3_X3 && a.M3X3_Y3 == b.M3X3_Y3 && a.M3X3_Z3 == b.M3X3_Z3)
#define mat3_add(a, b) make_mat3(a.M3X3_X1 + b.M3X3_X1, a.M3X3_Y1 + b.M3X3_Y1, a.M3X3_Z1 + b.M3X3_Z1,\
                                 a.M3X3_X2 + b.M3X3_X2, a.M3X3_Y2 + b.M3X3_Y2, a.M3X3_Z2 + b.M3X3_Z2,\
                                 a.M3X3_X3 + b.M3X3_X3, a.M3X3_Y3 + b.M3X3_Y3, a.M3X3_Z3 + b.M3X3_Z3)
#define mat3_sub(a, b) make_mat3(a.M3X3_X1 - b.M3X3_X1, a.M3X3_Y1 - b.M3X3_Y1, a.M3X3_Z1 - b.M3X3_Z1,\
                                 a.M3X3_X2 - b.M3X3_X2, a.M3X3_Y2 - b.M3X3_Y2, a.M3X3_Z2 - b.M3X3_Z2,\
                                 a.M3X3_X3 - b.M3X3_X3, a.M3X3_Y3 - b.M3X3_Y3, a.M3X3_Z3 - b.M3X3_Z3)
#define mat3_scale(a, s) make_mat3(a.M3X3_X1 * s, a.M3X3_Y1 * s, a.M3X3_Z1 * s,\
                                   a.M3X3_X2 * s, a.M3X3_Y2 * s, a.M3X3_Z2 * s,\
                                   a.M3X3_X3 * s, a.M3X3_Y3 * s, a.M3X3_Z3 * s)
#define mat3_multiply(a, b) make_mat3(a.M3X3_X1*b.M3X3_X1 + a.M3X3_X2*b.M3X3_Y1 + a.M3X3_X3*b.M3X3_Z1,\
                                      a.M3X3_Y1*b.M3X3_X1 + a.M3X3_Y2*b.M3X3_Y1 + a.M3X3_Y3*b.M3X3_Z1,\
                                      a.M3X3_Z1*b.M3X3_X1 + a.M3X3_Z2*b.M3X3_Y1 + a.M3X3_Z3*b.M3X3_Z1,\
                                      a.M3X3_X1*b.M3X3_X2 + a.M3X3_X2*b.M3X3_Y2 + a.M3X3_X3*b.M3X3_Z2,\
                                      a.M3X3_Y1*b.M3X3_X2 + a.M3X3_Y2*b.M3X3_Y2 + a.M3X3_Y3*b.M3X3_Z2,\
                                      a.M3X3_Z1*b.M3X3_X2 + a.M3X3_Z2*b.M3X3_Y2 + a.M3X3_Z3*b.M3X3_Z2,\
                                      a.M3X3_X1*b.M3X3_X3 + a.M3X3_X2*b.M3X3_Y3 + a.M3X3_X3*b.M3X3_Z3,\
                                      a.M3X3_Y1*b.M3X3_X3 + a.M3X3_Y2*b.M3X3_Y3 + a.M3X3_Y3*b.M3X3_Z3,\
                                      a.M3X3_Z1*b.M3X3_X3 + a.M3X3_Z2*b.M3X3_Y3 + a.M3X3_Z3*b.M3X3_Z3)
#define mat3_vec3_multiply(m, v) make_vec3(m.M3X3_X1*v.X + m.M3X3_X2*v.Y + m.M3X3_X3*v.Z,\
                                           m.M3X3_Y1*v.X + m.M3X3_Y2*v.Y + m.M3X3_Y3*v.Z,\
                                           m.M3X3_Z1*v.X + m.M3X3_Z2*v.Y + m.M3X3_Z3*v.Z)

typedef struct {
  float _matdata[9];
} mat3;

CAYLEY_API mat3 make_mat3(float x1, float y1, float z1,
               float x2, float y2, float z2, 
               float x3, float y3, float z3);
CAYLEY_API mat3 mat3_transpose(mat3 a);
CAYLEY_API float mat3_determinant(mat3 a);

#endif