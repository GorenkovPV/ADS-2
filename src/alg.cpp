// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double res = 1;
  while (n > 0) {
    res *= value;
    n--;
  }
  return res;
}

uint64_t fact(uint16_t n) {
  if (n == 1 || n == 0) {
    return 1;
  } else {
    return n * fact(n - 1);
  }
}

double calcItem(double x, uint16_t n) {
  return pown(x, n) / fact(n);
}

double expn(double x, uint16_t count) {
  double e = 0;
  for (int a = 0; a <= count; a++) {
    e += calcItem(x, a);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double sin = 0;
  for (int a = 1; a <= count; a++) {
    sin += pown(-1, a - 1) * calcItem(x, 2 * a - 1);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 0;
  for (int a = 1; a <= count; a++) {
    cos += pown(-1, a - 1) * calcItem(x, 2 * a - 2);
  }
  return cos;
}
