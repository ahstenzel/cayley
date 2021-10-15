#ifndef CAYLEY_VEC3_H
#define CAYLEY_VEC3_H

#include "cayley/detail/common.h"

#define vec3_zero make_vec3(0.0f, 0.0f, 0.0f)
#define vec3_iszero(a) (a.X == 0.0f && a.Y == 0.0f && a.Z == 0.0f)
#define vec3_equal(a, b) (a.X == b.X && a.Y == b.Y && a.Z == b.Z)
#define vec3_add(a, b) make_vec3(a.X + b.X, a.Y + b.Y, a.Z + b.Z)
#define vec3_sub(a, b) make_vec3(a.X - b.X, a.Y - b.Y, a.Z - b.Z)
#define vec3_scale(a, s) make_vec3(a.X * s, a.Y * s, a.Z * s)
#define vec3_dot(a, b) ((a.X*b.X) + (a.Y*b.Y) + (a.Z*b.Z))
#define vec3_cross(a, b) make_vec3(a.Y*b.Z - a.Z*b.Y, a.Z*b.X - a.X*b.Z, a.X*b.Y - a.Y*b.X)
#define vec3_dist(a, b) vec3_magnitude(vec3_sub(a, b))

typedef struct {
  float _vecdata[3];
} vec3;

CAYLEY_API vec3 make_vec3(float x, float y, float z);
CAYLEY_API float vec3_magnitude(vec3 a);
CAYLEY_API vec3 vec3_normalize(vec3 a);
CAYLEY_API vec3 vec3_mix(vec3 a, vec3 b, float s);
CAYLEY_API vec3 vec3_smoothstep(vec3 a, vec3 b, vec3 s);

#endif