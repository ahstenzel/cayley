#ifndef CAYLEY_TRANS_H
#define CAYLEY_TRANS_H

#include "cayley/detail/common.h"
#include "cayley/detail/vec3.h"
#include "cayley/detail/vec4.h"
#include "cayley/detail/mat4.h"

mat4 matrix_translate(vec3 v);
mat4 matrix_rotate(float a, vec3 v);
mat4 matrix_scale(vec3 s);
mat4 matrix_ortho(float left, float right, float near, float far, float top, float bottom);
mat4 matrix_perspecive(float fov, float aspect, float near, float far);

#endif