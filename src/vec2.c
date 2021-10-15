#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/vec2.h"

vec2 make_vec2(float x, float y) {
  vec2 v;
  v.X = x;
  v.Y = y;
  return v;
}

float vec2_magnitude(vec2 a) {
  double x = a.X;
  double y = a.Y;
  return (float)sqrt((x * x) + (y * y));
}

vec2 vec2_normalize(vec2 a) {
  float mag = vec2_magnitude(a);
  return make_vec2(a.X / mag, a.Y / mag);
}

vec2 vec2_mix(vec2 a, vec2 b, float s) {
  a.X *= 1.0f - s;
  a.Y *= 1.0f - s;
  b.X *= s;
  b.Y *= s;
  return vec2_add(a, b);
}

vec2 vec2_smoothstep(vec2 a, vec2 b, vec2 s) {
  float v_x = (float)fclamp((s.X - a.X) / (b.X - a.X), 0.0f, 1.0f);
  float v_y = (float)fclamp((s.Y - a.Y) / (b.Y - a.Y), 0.0f, 1.0f);
  v_x = v_x * v_x * (3.0f - (2.0f * v_x));
  v_y = v_y * v_y * (3.0f - (2.0f * v_y));
  return make_vec2(v_x, v_y);
}