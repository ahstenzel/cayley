#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/transforms.h"

mat4 matrix_translate(mat4 m, vec3 v) {
  mat4 t = mat4_identity;
  t.M4X4_X4 = v.X;
  t.M4X4_Y4 = v.Y;
  t.M4X4_Z4 = v.Z;
  return mat4_multiply(t, m);
}

mat4 matrix_rotate(mat4 m, float a, vec3 v) {
  mat4 t = mat4_identity;
  float c = (float)cos(a);
  float s = (float)sin(a);
  t.M4X4_X1 = c + (v.X * v.X * (1.0f - c));
  t.M4X4_Y1 = (v.Y * v.X * (1.0f - c)) + (v.Z * s);
  t.M4X4_Z1 = (v.Z * v.X * (1.0f - c)) - (v.Y * s);
  t.M4X4_X2 = (v.X * v.Y * (1.0f - c)) - (v.Z * s);
  t.M4X4_Y2 = c + (v.Y * v.Y * (1.0f - c));
  t.M4X4_Z2 = (v.Z * v.Y * (1.0f - c)) + (v.X * s);
  t.M4X4_X3 = (v.X * v.Z * (1.0f - c)) + (v.Y * s);
  t.M4X4_Y3 = (v.Y * v.Z * (1.0f - c)) - (v.X * s);
  t.M4X4_Z3 = c + (v.Z * v.Z * (1.0f - c));
  return mat4_multiply(t, m);
}

mat4 matrix_scale(mat4 m, vec3 s) {
  mat4 t = mat4_identity;
  t.M4X4_X1 = s.X;
  t.M4X4_Y2 = s.Y;
  t.M4X4_Z3 = s.Z;
  return mat4_multiply(t, m);
}

mat4 matrix_ortho(float left, float right, float near, float far, float top, float bottom) {
  mat4 m = mat4_identity;
  m.M4X4_X1 = 2.0f / (right - left);
  m.M4X4_Y2 = 2.0f / (top - bottom);
  m.M4X4_Z3 = -2.0f / (far - near);
  m.M4X4_X4 = (right + left) / (right - left);
  m.M4X4_Y4 = (top + bottom) / (top - bottom);
  m.M4X4_Z4 = (far + near) / (far - near);
  return m;
}

mat4 matrix_perspecive(float fov, float aspect, float near, float far) {
  mat4 m = mat4_identity;
  float top = (float)tan(fov / 2.0f) * near;
  float bottom = -top;
  float right = top * aspect;
  float left = bottom * aspect;

  m.M4X4_X1 = (2.0f * near) / (right - left);
  m.M4X4_Y2 = (2.0f * near) / (top - bottom);
  m.M4X4_X3 = (right + left) / (right - left);
  m.M4X4_Y3 = (top + bottom) / (top - bottom);
  m.M4X4_Z3 = -(far + near) / (far - near);
  m.M4X4_W3 = -1.0f;
  m.M4X4_Z4 = (-2.0f * far * near) / (far - near);
  m.M4X4_W4 = 0;
  return m;
}