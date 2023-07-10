__attribute__((__packed__)) struct s {
  char c;
  __attribute__((__packed__)) short s;  /* PCC 1.1.0: bug/bug1.c, line 3: compiler error: strmemb */
  __attribute__((__packed__)) int i;
  __attribute__((__packed__)) long long ll;
} __attribute__((__packed__));
int main(int argc, char **argv) {
  (void)argc; (void)argv;
  return sizeof(struct s) != 1 + sizeof(short) + sizeof(int) + sizeof(long long);  /* Expected return: 0. */
}
