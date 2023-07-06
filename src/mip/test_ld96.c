/*
 * ld96.c: tests for 96-bit long double emulation, useful for OpenWatcom
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 */

#include <stdio.h>

#include "ld96.h"

int main(int argc, char **argv) {
  const ld96_t ld0 = ld96_from_ll(0);
  const long long a = 1234567890987654321ULL;
  const long long b = -1234567890987654321ULL;
  const float f = 12345.6f;
  const double d = 12345678.9;
  (void)argc; (void)argv;
  ld96_set_ld_precision();  /* Needed by the OpenWatcom libc. */
  if (!ld96_iszero(ld96_from_ull(0))) return 1;
  if (!ld96_iszero(ld96_from_ll(0))) return 2;
  if (ld96_iszero(ld96_from_ull(a))) return 3;
  if (ld96_iszero(ld96_from_ll(b))) return 4;
  if (ld96_to_ull(ld96_from_ull(a)) != (unsigned long long)a) return 5;
  if (ld96_to_ull(ld96_from_ull(b)) != (unsigned long long)b) return 6;
  if (ld96_to_ull(ld96_from_ll(b)) != 0) return 7;
  if (ld96_to_ll(ld96_from_ll(a)) != a) return 8;
  if (ld96_to_ll(ld96_from_ll(b)) != b) return 9;
  if (ld96_le(ld96_from_ull(a), ld0)) return 10;
  if (ld96_le(ld96_from_ull(b), ld0)) return 11;
  if (ld96_le(ld96_from_ll(a), ld0)) return 12;
  if (ld96_ge(ld96_from_ll(b), ld0)) return 13;
  if (ld96_to_ll(ld96_from_f32(f)) != 12345) return 14;
  if (ld96_to_ll(ld96_from_f64(d)) != 12345678) return 15;
  if (ld96_to_ll(ld96_from_f32(-f)) != -12345) return 16;
  if (ld96_to_ll(ld96_from_f64(-d)) != -12345678) return 17;
  if (ld96_to_f32(ld96_from_f32(f)) != f) return 18;
  if (ld96_to_f64(ld96_from_f64(d)) != d) return 19;
  if (ld96_to_f32(ld96_from_f32(-f)) != -f) return 20;
  if (ld96_to_f64(ld96_from_f64(-d)) != -d) return 21;
  if (ld96_to_ll(ld96_strtold("-1234567890987654325.9", 0)) != b - 4) return 22;
  if (ld96_to_ll(ld96_neg(ld96_from_ll(b))) != a) return 23;
  if (ld96_to_ll(ld96_add(ld96_from_ll(a), ld96_from_ll(b))) != 0) return 24;
  if (ld96_to_ll(ld96_sub(ld96_from_ll(a), ld96_from_ll(a))) != 0) return 25;
  if (ld96_to_ll(ld96_sub(ld96_from_ll(b), ld0)) != b) return 26;
  if (ld96_to_ll(ld96_sub(ld0, ld96_from_ll(b))) != a) return 27;
  if (ld96_to_ll(ld96_mul(ld96_from_ll(a), ld96_from_ll(2))) != a * 2) return 28;
  if (ld96_to_ll(ld96_div(ld96_from_ll(b), ld96_from_ll(1))) != b) return 29;
  if (ld96_to_ll(ld96_div(ld96_from_ll(a), ld96_from_ll(2))) != a >> 1) return 30;
  if (ld96_to_ll(ld96_div(ld96_from_ll(b), ld96_from_ll(2))) != (b >> 1) + 1) return 31;
  if (ld96_to_ll(ld96_mul(ld96_from_ll(1ULL << 60), ld96_div(ld96_from_ll(a), ld96_from_ll(1ULL << 60)))) != a) return 32;
  if (!ld96_lt(ld96_from_ll(b), ld0)) return 33;
  if (!ld96_le(ld96_from_ll(b), ld0)) return 34;
  if (ld96_eq(ld96_from_ll(b), ld0)) return 35;
  if (ld96_ge(ld96_from_ll(b), ld0)) return 36;
  if (ld96_gt(ld96_from_ll(b), ld0)) return 37;
  if (!ld96_ne(ld96_from_ll(b), ld0)) return 38;
  if (!ld96_eq(ld96_from_ll(b), ld96_from_ll(b))) return 39;
  if (ld96_eq(ld96_from_ll(a), ld96_from_ll(b))) return 40;
  if (ld96_eq(ld96_from_ll(b), ld96_from_ll(a))) return 41;
  if (ld96_ne(ld96_from_ll(b), ld96_from_ll(b))) return 42;
  if (!ld96_ne(ld96_from_ll(a), ld96_from_ll(b))) return 43;
  if (!ld96_ne(ld96_from_ll(b), ld96_from_ll(a))) return 44;
  if (ld96_le(ld96_from_ll(a), ld96_from_ll(b))) return 45;
  if (!ld96_le(ld96_from_ll(a), ld96_from_ll(a))) return 46;
  if (ld96_lt(ld96_from_ll(a), ld96_from_ll(a))) return 47;
  if (ld96_lt(ld96_from_ll(a), ld96_from_ll(b))) return 48;
  if (ld96_ge(ld96_from_ll(b), ld96_from_ll(a))) return 49;
  if (!ld96_ge(ld96_from_ll(b), ld96_from_ll(b))) return 50;
  if (ld96_gt(ld96_from_ll(b), ld96_from_ll(b))) return 51;
  if (ld96_gt(ld96_from_ll(b), ld96_from_ll(a))) return 52;
  return 0;
}
