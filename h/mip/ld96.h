/*
 * ld96.h: 96-bit long double emulation, useful for OpenWatcom
 * by pts@fazekas.hu at Thu Jul  6 16:46:03 CEST 2023
 */
#ifndef _MIP_LD96_H
#define _MIP_LD96_H

#ifdef __WATCOMC__
#  define ld96_watcall __watcall
#else
#  define ld96_watcall
#endif
#define ld96_id(x) (x)
#ifdef CONFIG_LD96
#  ifdef __WATCOMC__
  _Packed  /* This is needed in case `wcc386 -zp4' wasn't specified. The default is `-zp8'. */
#  endif
#  if !defined(__WATCOMC__) && !defined(CONFIG_LD96_S) && __SIZEOF_LONG_DOUBLE__ > 12  /* GCC >=4.2 has __SIZEOF_LONG_DOUBLE__, and it's 16 for __amd64__. */
    /* We add a `long double' member just for the alignment. */
    typedef union ld96 { struct { unsigned a, b, c; } s; long double ld; } ld96_t;
#  else
    typedef struct ld96 { unsigned a, b, c; } ld96_t;
#  endif
  typedef char assert_ld96_size[sizeof(ld96_t) >= 12 ? 1 : -1];
#  ifdef __WATCOMC__
    void __watcall ld96_set_ld_precision(void);
#  else
#    define ld96_set_ld_precision()
#  endif
  ld96_t ld96_watcall ld96_from_ull(unsigned long long u);
  ld96_t ld96_watcall ld96_from_ll(long long v);
  ld96_t ld96_watcall ld96_from_f32(float f);
  ld96_t ld96_watcall ld96_from_f64(double d);
  long long ld96_watcall ld96_to_ll(ld96_t ld);
  unsigned long long ld96_watcall ld96_to_ull(ld96_t ld);
  float  ld96_watcall ld96_to_f32(ld96_t ld);
  double ld96_watcall ld96_to_f64(ld96_t ld);
  ld96_t ld96_watcall ld96_strtold(const char *nptr, char **endptr);
  int    ld96_watcall ld96_iszero(ld96_t ld);
  ld96_t ld96_watcall ld96_neg(ld96_t ld);
  ld96_t ld96_watcall ld96_add(ld96_t a, ld96_t b);
  ld96_t ld96_watcall ld96_sub(ld96_t a, ld96_t b);
  ld96_t ld96_watcall ld96_mul(ld96_t a, ld96_t b);
  ld96_t ld96_watcall ld96_div(ld96_t a, ld96_t b);
  int    ld96_watcall ld96_eq (ld96_t a, ld96_t b);
  int    ld96_watcall ld96_lt (ld96_t a, ld96_t b);
#else
  typedef long double ld96_t;
  /* This fails for OpenWatcom, because it has sizeof(double) ==
   * sizeof(long_double) == 8. The solution: specify -DCONFIG_LD96, which
   * enables the `long double' emulation.
   */
  typedef char assert_ld96_size[sizeof(ld96_t) == 10 || sizeof(ld96_t) == 12 || sizeof(ld96_t) == 16 ? 1 : -1];
#  include <stdlib.h>  /* For strtold(3). */
  /* __STRICT_ANSI__ is by `gcc -ansi', _NO_EXT_KEYS is by OpenWatcom `wcc386 -za'. */
#  if defined(__STRICT_ANSI__) || defined(_NO_EXT_KEYS)
    ld96_t strtold(const char *nptr, char **endptr);
#  endif
#  define ld96_set_ld_precision()
#  define ld96_from_ll(v) ((ld96_t)(long long)(v))
#  define ld96_from_ull(u) ((ld96_t)(unsigned long long)(u))
#  define ld96_from_f32(f) ((ld96_t)(float)(f))
#  define ld96_from_f64(d) ((ld96_t)(double)(d))
#  define ld96_to_f32(ld) ((float) (ld))
#  define ld96_to_f64(ld) ((double)(ld))
#  define ld96_to_ll(ld)  ((long long)(ld))
  unsigned long long ld96_to_ull(ld96_t d);  /* Make sure that it returns 0 for negative input. */
#  define ld96_strtold(nptr, endptr) strtold(nptr, endptr)
#  define ld96_iszero(ld) ((ld96_t)(ld) == 0.0)
#  define ld96_neg(ld) (-(ld96_t)(ld))
#  define ld96_add(a, b) ((ld96_t)(a) + (ld96_t)(b))
#  define ld96_sub(a, b) ((ld96_t)(a) - (ld96_t)(b))
#  define ld96_mul(a, b) ((ld96_t)(a) * (ld96_t)(b))
#  define ld96_div(a, b) ((ld96_t)(a) / (ld96_t)(b))
#  define ld96_eq(a, b) ((ld96_t)(a) == (ld96_t)(b))
#  define ld96_lt(a, b) ((ld96_t)(a) < (ld96_t)(b))
#endif
#define ld96_ne(a, b) (!ld96_eq((a), (b)))
#define ld96_ge(a, b) (!ld96_lt((a), (b)))
#define ld96_le(a, b) (!ld96_lt((b), (a)))
#define ld96_gt(a, b) (ld96_lt((b), (a)))

#endif  /* _MIP_LD96_H */
