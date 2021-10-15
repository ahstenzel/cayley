#ifndef CAYLEY_EXPORTS
#define CAYLEY_EXPORTS
#endif
#include "cayley/detail/common.h"

double fclamp(double x, double min, double max) {
  return (x < min) ? min : ((x > max) ? max : x);
}