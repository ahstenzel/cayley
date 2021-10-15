#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/vec3.h"

vec3 make_vec3(float x, float y, float z) {
  vec3 v;
  v.X = x;
  v.Y = y;
  v.Z = z;
  return v;
}

float vec3_magnitude(vec3 a) {
  double x = a.X;
  double y = a.Y;
  double z = a.Z;
  return (float)sqrt((x * x) + (y * y) + (z * z));
}

vec3 vec3_normalize(vec3 a) {
  float mag = vec3_magnitude(a);
  return make_vec3(a.X / mag, a.Y / mag, a.Z / mag);
}

vec3 vec3_mix(vec3 a, vec3 b, float s) {
  a.X *= 1.0f - s;
  a.Y *= 1.0f - s;
  a.Z *= 1.0f - s;
  b.X *= s;
  b.Y *= s;
  b.Z *= s;
  return vec3_add(a, b);
}

vec3 vec3_smoothstep(vec3 a, vec3 b, vec3 s) {
  float v_x = (float)fclamp((s.X - a.X) / (b.X - a.X), 0.0f, 1.0f);
  float v_y = (float)fclamp((s.Y - a.Y) / (b.Y - a.Y), 0.0f, 1.0f);
  float v_z = (float)fclamp((s.Z - a.Z) / (b.Z - a.Z), 0.0f, 1.0f);
  v_x = v_x * v_x * (3.0f - (2.0f * v_x));
  v_y = v_y * v_y * (3.0f - (2.0f * v_y));
  v_z = v_z * v_z * (3.0f - (2.0f * v_z));
  return make_vec3(v_x, v_y, v_z);
}