/* by pts@fazekas.hu at Tue Jul 11 00:32:05 CEST 2023 */
#ifdef __TINYC__  /* TOOD(pts): Inline it. */
#  include <string.h> /* For memcpy(...). */
#endif
struct s { int a, b, c; };
struct s mks(int a) { struct s r; r.a = a; return r; }
int add(struct s s1, struct s s2) { return s1.a + s2.a; };
int main(int argc, char **argv) {
  (void)argc; (void)argv;
  return (3 + 4) - add(mks(3), mks(4));  /* Should be 0, it's acutally 1 with PCC 1.1.0. */
}
