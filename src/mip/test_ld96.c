/*
 * ld96.c: tests for 96-bit long double emulation, useful for OpenWatcom
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "ld96.h"

int main(int argc, char **argv) {
  const ld96_t ld0 = ld96_from_ll(0);
  const long long a = 1234567890987654321ULL;
  const long long b = -1234567890987654321ULL;
  const ld96_t lda = ld96_from_ll(a);  /* To work around PCC 1.1.0 bug in `return 24'. */
  const ld96_t ldb = ld96_from_ll(b);  /* To work around PCC 1.1.0 bug in `return 24'. */
  const ld96_t ld60 = ld96_from_ll(1LL << 60);  /* To work around PCC 1.1.0 bug in `return 24'. */
  ld96_t ldr;
  const ld96_t ldf = ld96_round_f32(ld96_strtold("12345.6", 0));
  const ld96_t ldd = ld96_round_f64(ld96_strtold("12345678.9", 0));
  char buf[12];
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
  if (ld96_to_ll(ldf) != 12345) return 14;
  if (ld96_to_ll(ldd) != 12345678) return 15;
  if (ld96_to_ll(ld96_neg(ldf)) != -12345) return 16;
  if (ld96_to_ll(ld96_neg(ldd)) != -12345678) return 17;
  ldr = ld96_round_f32(ldf);  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (!ld96_eq(ldr, ldf)) return 56;
  ldr = ld96_round_f64(ldd);  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (!ld96_eq(ldr, ldd)) return 57;
  ldr = ld96_round_f32(ld96_neg(ldf));  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (!ld96_eq(ldr, ld96_neg(ldf))) return 58;
  ldr = ld96_round_f64(ld96_neg(ldd));  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (!ld96_eq(ldr, ld96_neg(ldd))) return 59;
  ldr = ld96_round_f32(ldd);  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (ld96_eq(ldr, ldd)) return 60;
  ldr = ld96_from_half();  /* Using a separate variable to work around PCC 1.1.0 bug. */
  if (ld96_to_ll(ld96_mul(ldr, ld96_from_ll(42))) != 21) return 61;
  if (ld96_to_ll(ld96_strtold("-1234567890987654325.9", 0)) != b - 4) return 22;
  if (ld96_to_ll(ld96_neg(ld96_from_ll(b))) != a) return 23;
  if (ld96_to_ll(ld96_add(lda, ld96_from_ll(b))) != 0) return 24;
  if (ld96_to_ll(ld96_sub(lda, ld96_from_ll(a))) != 0) return 25;
  if (ld96_to_ll(ld96_sub(ld96_from_ll(b), ld0)) != b) return 26;
  if (ld96_to_ll(ld96_sub(ld0, ld96_from_ll(b))) != a) return 27;
  if (ld96_to_ll(ld96_mul(lda, ld96_from_ll(2))) != a * 2) return 28;
  if (ld96_to_ll(ld96_div(ldb, ld96_from_ll(1))) != b) return 29;
  if (ld96_to_ll(ld96_div(lda, ld96_from_ll(2))) != a >> 1) return 30;
  if (ld96_to_ll(ld96_div(ldb, ld96_from_ll(2))) != (b >> 1) + 1) return 31;
  if (ld96_to_ll(ld96_mul(ld60, ld96_div(lda, ld60))) != a) return 32;
  if (!ld96_lt(ld96_from_ll(b), ld0)) return 33;
  if (!ld96_le(ld96_from_ll(b), ld0)) return 34;
  if (ld96_eq(ld96_from_ll(b), ld0)) return 35;
  if (ld96_ge(ld96_from_ll(b), ld0)) return 36;
  if (ld96_gt(ld96_from_ll(b), ld0)) return 37;
  if (!ld96_ne(ld96_from_ll(b), ld0)) return 38;
  if (!ld96_eq(ld96_from_ll(b), ld96_from_ll(b))) return 39;
  if (ld96_eq(lda, ld96_from_ll(b))) return 40;
  if (ld96_eq(ld96_from_ll(b), lda)) return 41;
  if (ld96_ne(ld96_from_ll(b), ld96_from_ll(b))) return 42;
  if (!ld96_ne(lda, ld96_from_ll(b))) return 43;
  if (!ld96_ne(ld96_from_ll(b), lda)) return 44;
  if (ld96_le(lda, ld96_from_ll(b))) return 45;
  if (!ld96_le(lda, lda)) return 46;
  if (ld96_lt(lda, lda)) return 47;
  if (ld96_lt(lda, ld96_from_ll(b))) return 48;
  if (ld96_ge(ld96_from_ll(b), lda)) return 49;
  if (!ld96_ge(ld96_from_ll(b), ld96_from_ll(b))) return 50;
  if (ld96_gt(ld96_from_ll(b), ld96_from_ll(b))) return 51;
  if (ld96_gt(ld96_from_ll(b), lda)) return 52;
  memset(buf, 5, sizeof(buf));
  ld96_dump_f32(buf, ldf);
  if (memcmp(buf, "\x66\xe6\x40\x46\5\5\5\5\5\5\5\5", 12) != 0) return 53;
  memset(buf, 5, sizeof(buf));
  ld96_dump_f64(buf, ldd);
  if (memcmp(buf, "\xcd\xcc\xcc\xdc\x29\x8c\x67\x41\5\5\5\5", 12) != 0) return 54;
  memset(buf, 5, sizeof(buf));
  ld96_dump_f80_96(buf, ldb);
  if (memcmp(buf, "\x88\xe5\x60\x8b\xa5\x87\x10\x89\x3b\xc0", 11) != 0 || buf[11] != '\0') return 55;
  return 0;
}
