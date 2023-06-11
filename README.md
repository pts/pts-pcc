# pts-pcc: a self-contained port of PCC to Linux i386

pts-pcc is a self-contained port of PCC (Portable C Compiler) to Linux i386.
Self-contained means that the driver, preprocessor and compiler are in the
same executable program, so they don't have to find each other. pts-tcc also
contains some bugfixes and convenience features.

pts-tcc is based on PCC 1.1.0 (released on 2014-12-10). Important changes:

* The *pcc*, *cpp* and *ccom* executables were merged, all into *pcc*. It
  still calls fork(2), but instead of exec(...), it runs another main(...)
  function in the child process. This makes it easier to ship TCC, because
  now it's a single executable, and there is no need to set up the `$PATH`
  if only assembly .s output is needed (with `-S`). (For ELF object .o
  output, it still needs GNU as(1) (`as`) on `$PATH`.)

* Some bugs were fixed (see *bugfix* in the commit history).

* Some convenience features were added, such as the `-ansi` flag (currently
  it doesn't do anything).

* The original build system using Makefiles were replaced with a single
  shell script, rebuilding th project in one C compiler run.

* It has been ported to many compilers in addition to GCC and Clang: TinyCC
  and OpenWatcom.

* Lots of GCC and OpenWatcom compilation warnings have been pacified (i.e.
  fixed, eliminated). Now it compiles cleanly, without warning. See
  `compile.sh` for details.

* Some warnings flags were added for GCC compatibility, e.g. `-Wextra`, and
  for GCC 4.1: `-Werror-implicit-function-declaration` (without an `=` in
  the middle).

* Implementation of BSD-specific functions (strlcpy(3) and strlcat(3)) were
  added.

To compile it, run these commands without the leading `$`:

```
$ git clone --depth 1 https://github.com/pts/pts-pcc
$ cd pts-pcc
$ ./compile.sh
...
$ ./pts-pcc
$ pccbin/pcc -v
pts-pcc 1.1.0 20141014 + 20230610 for i386-pc-linux-gnu
error: no input files
```
