#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/vec4.h"

vec4 make_vec4(float x, float y, float z, float w) {
  vec4 v;
  v.X = x;
  v.Y = y;
  v.Z = z;
  v.W = w;
  return v;
}

float vec4_magnitude(vec4 a) {
  double x = a.X;
  double y = a.Y;
  double z = a.Z;
  double w = a.W;
  return (float)sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

vec4 vec4_normalize(vec4 a) {
  float mag = vec4_magnitude(a);
  return make_vec4(a.X / mag, a.Y / mag, a.Z / mag, a.W / mag);
}

vec4 vec4_mix(vec4 a, vec4 b, float s) {
  a.X *= 1.0f - s;
  a.Y *= 1.0f - s;
  a.Z *= 1.0f - s;
  a.W *= 1.0f - s;
  b.X *= s;
  b.Y *= s;
  b.Z *= s;
  b.W *= s;
  return vec4_add(a, b);
}

vec4 vec4_smoothstep(vec4 a, vec4 b, vec4 s) {
  float v_x = (float)fclamp((s.X - a.X) / (b.X - a.X), 0.0f, 1.0f);
  float v_y = (float)fclamp((s.Y - a.Y) / (b.Y - a.Y), 0.0f, 1.0f);
  float v_z = (float)fclamp((s.Z - a.Z) / (b.Z - a.Z), 0.0f, 1.0f);
  float v_w = (float)fclamp((s.W - a.W) / (b.W - a.W), 0.0f, 1.0f);
  v_x = v_x * v_x * (3.0f - (2.0f * v_x));
  v_y = v_y * v_y * (3.0f - (2.0f * v_y));
  v_z = v_z * v_z * (3.0f - (2.0f * v_z));
  v_w = v_w * v_w * (3.0f - (2.0f * v_w));
  return make_vec4(v_x, v_y, v_z, v_w);
}