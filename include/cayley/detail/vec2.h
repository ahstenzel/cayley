#ifndef CAYLEY_VEC2_H
#define CAYLEY_VEC2_H

#include "cayley/detail/common.h"

#define vec2_zero make_vec2(0.0f, 0.0f)
#define vec2_iszero(a) (a.X == 0.0f && a.Y == 0.0f)
#define vec2_equal(a, b) (a.X == b.X && a.Y == b.Y)
#define vec2_add(a, b) make_vec2(a.X + b.X, a.Y + b.Y)
#define vec2_sub(a, b) make_vec2(a.X - b.X, a.Y - b.Y)
#define vec2_scale(a, s) make_vec2(a.X * s, a.Y * s)
#define vec2_dot(a, b) ((a.X*b.X) + (a.Y*b.Y))
#define vec2_dist(a, b) vec2_magnitude(vec2_sub(a, b))

typedef struct {
  float _vecdata[2];
} vec2;

CAYLEY_API vec2 make_vec2(float x, float y);
CAYLEY_API float vec2_magnitude(vec2 a);
CAYLEY_API vec2 vec2_normalize(vec2 a);
CAYLEY_API vec2 vec2_mix(vec2 a, vec2 b, float s);
CAYLEY_API vec2 vec2_smoothstep(vec2 a, vec2 b, vec2 s);

#endif