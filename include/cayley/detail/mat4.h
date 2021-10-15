#ifndef CAYLEY_MAT4_H
#define CAYLEY_MAT4_H

#include "cayley/detail/common.h"
#include "cayley/detail/vec4.h"

#define mat4_identity make_mat4(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
#define mat4_isidentity(a) (a.M4X4_X1 == 1.0f && a.M4X4_Y1 == 0.0f && a.M4X4_Z1 == 0.0f && a.M4X4_W1 == 0.0f && \
                            a.M4X4_X2 == 0.0f && a.M4X4_Y2 == 1.0f && a.M4X4_Z2 == 0.0f && a.M4X4_W2 == 0.0f && \
                            a.M4X4_X3 == 0.0f && a.M4X4_Y3 == 0.0f && a.M4X4_Z3 == 1.0f && a.M4X4_W3 == 0.0f && \
                            a.M4X4_X4 == 0.0f && a.M4X4_Y4 == 0.0f && a.M4X4_Z4 == 0.0f && a.M4X4_W4 == 1.0f)
#define mat4_equal(a, b) (a.M4X4_X1 == b.M4X4_X1 && a.M4X4_Y1 == b.M4X4_Y1 && a.M4X4_Z1 == b.M4X4_Z1 && a.M4X4_W1 == b.M4X4_W1 && \
                          a.M4X4_X2 == b.M4X4_X2 && a.M4X4_Y2 == b.M4X4_Y2 && a.M4X4_Z2 == b.M4X4_Z2 && a.M4X4_W2 == b.M4X4_W2 && \
                          a.M4X4_X3 == b.M4X4_X3 && a.M4X4_Y3 == b.M4X4_Y3 && a.M4X4_Z3 == b.M4X4_Z3 && a.M4X4_W3 == b.M4X4_W3 && \
                          a.M4X4_X4 == b.M4X4_X4 && a.M4X4_Y4 == b.M4X4_Y4 && a.M4X4_Z4 == b.M4X4_Z4 && a.M4X4_W4 == b.M4X4_W4)
#define mat4_add(a, b) make_mat4(a.M4X4_X1 + b.M4X4_X1, a.M4X4_Y1 + b.M4X4_Y1, a.M4X4_Z1 + b.M4X4_Z1, a.M4X4_W1 + b.M4X4_W1,\
                                 a.M4X4_X2 + b.M4X4_X2, a.M4X4_Y2 + b.M4X4_Y2, a.M4X4_Z2 + b.M4X4_Z2, a.M4X4_W2 + b.M4X4_W2,\
                                 a.M4X4_X3 + b.M4X4_X3, a.M4X4_Y3 + b.M4X4_Y3, a.M4X4_Z3 + b.M4X4_Z3, a.M4X4_W3 + b.M4X4_W3,\
                                 a.M4X4_X4 + b.M4X4_X4, a.M4X4_Y4 + b.M4X4_Y4, a.M4X4_Z4 + b.M4X4_Z4, a.M4X4_W4 + b.M4X4_W4)
#define mat4_sub(a, b) make_mat4(a.M4X4_X1 - b.M4X4_X1, a.M4X4_Y1 - b.M4X4_Y1, a.M4X4_Z1 - b.M4X4_Z1, a.M4X4_W1 - b.M4X4_W1,\
                                 a.M4X4_X2 - b.M4X4_X2, a.M4X4_Y2 - b.M4X4_Y2, a.M4X4_Z2 - b.M4X4_Z2, a.M4X4_W2 - b.M4X4_W2,\
                                 a.M4X4_X3 - b.M4X4_X3, a.M4X4_Y3 - b.M4X4_Y3, a.M4X4_Z3 - b.M4X4_Z3, a.M4X4_W3 - b.M4X4_W3,\
                                 a.M4X4_X4 - b.M4X4_X4, a.M4X4_Y4 - b.M4X4_Y4, a.M4X4_Z4 - b.M4X4_Z4, a.M4X4_W4 - b.M4X4_W4)
#define mat4_scale(a, s) make_mat4(a.M4X4_X1 * s, a.M4X4_Y1 * s, a.M4X4_Z1 * s, a.M4X4_W1 * s,\
                                   a.M4X4_X2 * s, a.M4X4_Y2 * s, a.M4X4_Z2 * s, a.M4X4_W2 * s,\
                                   a.M4X4_X3 * s, a.M4X4_Y3 * s, a.M4X4_Z3 * s, a.M4X4_W3 * s,\
                                   a.M4X4_X4 * s, a.M4X4_Y4 * s, a.M4X4_Z4 * s, a.M4X4_W4 * s)
#define mat4_multiply(a, b) make_mat4(a.M4X4_X1*b.M4X4_X1 + a.M4X4_X2*b.M4X4_Y1 + a.M4X4_X3*b.M4X4_Z1 + a.M4X4_X4*b.M4X4_W1,\
                                      a.M4X4_Y1*b.M4X4_X1 + a.M4X4_Y2*b.M4X4_Y1 + a.M4X4_Y3*b.M4X4_Z1 + a.M4X4_Y4*b.M4X4_W1,\
                                      a.M4X4_Z1*b.M4X4_X1 + a.M4X4_Z2*b.M4X4_Y1 + a.M4X4_Z3*b.M4X4_Z1 + a.M4X4_Z4*b.M4X4_W1,\
                                      a.M4X4_W1*b.M4X4_X1 + a.M4X4_W2*b.M4X4_Y1 + a.M4X4_W3*b.M4X4_Z1 + a.M4X4_W4*b.M4X4_W1,\
                                      a.M4X4_X1*b.M4X4_X2 + a.M4X4_X2*b.M4X4_Y2 + a.M4X4_X3*b.M4X4_Z2 + a.M4X4_X4*b.M4X4_W2,\
                                      a.M4X4_Y1*b.M4X4_X2 + a.M4X4_Y2*b.M4X4_Y2 + a.M4X4_Y3*b.M4X4_Z2 + a.M4X4_Y4*b.M4X4_W2,\
                                      a.M4X4_Z1*b.M4X4_X2 + a.M4X4_Z2*b.M4X4_Y2 + a.M4X4_Z3*b.M4X4_Z2 + a.M4X4_Z4*b.M4X4_W2,\
                                      a.M4X4_W1*b.M4X4_X2 + a.M4X4_W2*b.M4X4_Y2 + a.M4X4_W3*b.M4X4_Z2 + a.M4X4_W4*b.M4X4_W2,\
                                      a.M4X4_X1*b.M4X4_X3 + a.M4X4_X2*b.M4X4_Y3 + a.M4X4_X3*b.M4X4_Z3 + a.M4X4_X4*b.M4X4_W3,\
                                      a.M4X4_Y1*b.M4X4_X3 + a.M4X4_Y2*b.M4X4_Y3 + a.M4X4_Y3*b.M4X4_Z3 + a.M4X4_Y4*b.M4X4_W3,\
                                      a.M4X4_Z1*b.M4X4_X3 + a.M4X4_Z2*b.M4X4_Y3 + a.M4X4_Z3*b.M4X4_Z3 + a.M4X4_Z4*b.M4X4_W3,\
                                      a.M4X4_W1*b.M4X4_X3 + a.M4X4_W2*b.M4X4_Y3 + a.M4X4_W3*b.M4X4_Z3 + a.M4X4_W4*b.M4X4_W3,\
                                      a.M4X4_X1*b.M4X4_X4 + a.M4X4_X2*b.M4X4_Y4 + a.M4X4_X3*b.M4X4_Z4 + a.M4X4_X4*b.M4X4_W4,\
                                      a.M4X4_Y1*b.M4X4_X4 + a.M4X4_Y2*b.M4X4_Y4 + a.M4X4_Y3*b.M4X4_Z4 + a.M4X4_Y4*b.M4X4_W4,\
                                      a.M4X4_Z1*b.M4X4_X4 + a.M4X4_Z2*b.M4X4_Y4 + a.M4X4_Z3*b.M4X4_Z4 + a.M4X4_Z4*b.M4X4_W4,\
                                      a.M4X4_W1*b.M4X4_X4 + a.M4X4_W2*b.M4X4_Y4 + a.M4X4_W3*b.M4X4_Z4 + a.M4X4_W4*b.M4X4_W4)
#define mat4_vec3_multiply(m, v) make_vec4(m.M4X4_X1*v.X + m.M4X4_X2*v.Y + m.M4X4_X3*v.Z + m.M4X4_X4*v.W,\
                                           m.M4X4_Y1*v.X + m.M4X4_Y2*v.Y + m.M4X4_Y3*v.Z + m.M4X4_Y4*v.W,\
                                           m.M4X4_Z1*v.X + m.M4X4_Z2*v.Y + m.M4X4_Z3*v.Z + m.M4X4_Z4*v.W,\
                                           m.M4X4_W1*v.X + m.M4X4_W2*v.Y + m.M4X4_W3*v.Z + m.M4X4_W4*v.W)

typedef struct {
  float _matdata[16];
} mat4;

CAYLEY_API mat4 make_mat4(float x1, float y1, float z1, float w1,
               float x2, float y2, float z2, float w2,
               float x3, float y3, float z3, float w3,
               float x4, float y4, float z4, float w4);
CAYLEY_API mat4 mat4_transpose(mat4 a);
CAYLEY_API float mat4_determinant(mat4 a);

#endif