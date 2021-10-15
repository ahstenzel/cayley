#ifndef CAYLEY_VEC4_H
#define CAYLEY_VEC4_H

#include "cayley/detail/common.h"

#define vec4_zero make_vec4(0.0f, 0.0f, 0.0f, 0.0f)
#define vec4_iszero(a) (a.X == 0.0f && a.Y == 0.0f && a.Z == 0.0f && a.W = 0.0f)
#define vec4_equal(a, b) (a.X == b.X && a.Y == b.Y && a.Z == b.Z && a.W == b.W)
#define vec4_add(a, b) make_vec4(a.X + b.X, a.Y + b.Y, a.Z + b.Z, a.W + b.W)
#define vec4_sub(a, b) make_vec4(a.X - b.X, a.Y - b.Y, a.Z - b.Z, a.W - b.W)
#define vec4_scale(a, s) make_vec4(a.X * s, a.Y * s, a.Z * s, a.W * s)
#define vec4_dot(a, b) ((a.X*b.X) + (a.Y*b.Y) + (a.Z*a.Z) + (a.W*b.W))
#define vec4_dist(a, b) vec4_magnitude(vec4_sub(a, b))

typedef struct {
  float _vecdata[4];
} vec4;

CAYLEY_API vec4 make_vec4(float x, float y, float z, float w);
CAYLEY_API float vec4_magnitude(vec4 a);
CAYLEY_API vec4 vec4_normalize(vec4 a);
CAYLEY_API vec4 vec4_mix(vec4 a, vec4 b, float s);
CAYLEY_API vec4 vec4_smoothstep(vec4 a, vec4 b, vec4 s);

#endif