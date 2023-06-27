#! /bin/sh --
#
# compile.sh: build script for PCC 1.1.0 on Linux, targeting Linux i386
# by pts@fazekas.hu at Sat Jun 10 12:46:04 CEST 2023
#
# minicc with the `--gcc=4.8' flag creates shorter output (272876 bytes)
# than with `--wcc' or `--tcc' or GCC 7.5.0 or Clang 6.0.0.
#
# It compiles cleanly (without warnings) with GCC 4.1 .. 4.9, GCC 7.5.0, Clang 6.0.0 and OpenWatcom 2023-03-04.
# It works with GCC -std=c99 and -std=gnu99, but it doesn't work with `-ansi (== -std=c89) -pedantic' or `-std=gnu89 -pedantic', mostly because `long long'.
# Compile with: ./compile.sh gcc   -s -Os -W -Wall -Wshadow -Wno-unused-parameter -Werror-implicit-function-declaration -std=c99 -pedantic
# Compile with: ./compile.sh clang -s -Os -W -Wall -Wshadow -Wno-unused-parameter -Werror-implicit-function-declaration -std=c99 -pedantic
# Compile with: ./compile.sh owcc -blinux -march=i386 -s -O2 -I"$WATCOM"/lh -fsigned-char -fno-stack-protector -W -Wextra -Wno-n303 -std=c99 -fo=.obj && -f *.obj  # But silently breaks for `long long'.
# Compile with: ./compile.sh minicc --gcc --diet -Wno-unused-parameter -std=c99 -pedantic
# Compile with: ./compile.sh minicc --wcc --diet -Wno-unused-parameter -std=c99 -pedantic  # But silently breaks for `long long'.
# Compile with: ./compile.sh minicc --tcc --diet -Wno-unused-parameter -std=c99 -pedantic
# Compile with: ./compile.sh minicc --pcc --diet -Wno-unused-parameter -std=c99 -pedantic
#
# !! TODO(pts): Disable more debug printfs (but not assertions), even those which are currently unaffected by PCC_DEBUG. Look for %p.
# !! TODO(pts): There is also libpcc with divdi3 in a separate download: http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/pcc-libs-1.1.0.tgz
#

set -ex


CC='gcc -s -Os -W -Wall -Wshadow -Wno-unused-parameter'
test $# = 0 || CC="$*"
I386_CCLD="${I386_CCLD:-gcc -m32}"
#CFLAGS=''  # -DPCC_DEBUG
CFLAGS='-DPCC_DEBUG'

test -d pccbin || mkdir pccbin
$CC -DGCC_COMPAT $CFLAGS -Dos_linux -Dmach_i386 \
    -DLIBEXECDIR=\"/dev/null/libexec/\" -DINCLUDEDIR=\"/dev/null/h/\" -DPCCINCDIR=\"/dev/null/hh/\" -DPCCLIBDIR=\"/dev/null/lib/\" -DTARGOSVER=0 -DCPPROGNAME=\"pcpp\" \
    -Ih/cc/driver -Ih/cc/ccom -Ih/cc/cpp -Ih/top -Ih/mip -Ih/arch/i386 -Ih/os/linux \
     src/cc/cc/cc.c src/mip/compat.c src/cc/driver/strlist.c src/cc/driver/xalloc.c \
     src/cc/ccom/builtins.c src/cc/ccom/cgram_auto.c src/arch/i386/code.c src/mip/common.c src/mip/compat.c src/cc/ccom/external_auto.c src/cc/ccom/gcc_compat.c src/cc/ccom/init.c src/cc/ccom/inline.c src/arch/i386/local.c src/arch/i386/local2.c src/cc/ccom/main.c \
        src/mip/match.c src/cc/ccom/optim.c src/mip/optim2.c src/arch/i386/order.c src/cc/ccom/pftn.c src/mip/reader.c src/mip/regs.c src/cc/ccom/scan_auto.c src/cc/ccom/stabs.c src/cc/ccom/symtabs.c src/arch/i386/table.c src/cc/ccom/trees.c src/mip/unicode.c \
     src/mip/compat.c src/cc/cpp/cpp.c src/cc/cpp/cpy_auto.c \
     src/cc/cpp/token.c src/bsd/strlcpy.c src/bsd/strlcat.c \
     -o pccbin/pcc

ls -ld pccbin/pcc

# !!! Does OpenBSD or NetBSD have an ELF linker other than GNU ld(1)?
# Without -static: Calling ld -o hello -v -d -dynamic-linker /lib/ld-linux.so.2 -e _start crt1.o crti.o crtbegin.o /tmp/ctm.dgee2t -L/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/lib/ -L/usr/lib/ -lpcc -lc -lpcc crtend.o crtn.o
# With -static: ld -o hello -v -d -Bstatic crt1.o crti.o crtbeginT.o /tmp/ctm.98t5r2 -L/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/lib/ -L/usr/lib/ -lpcc -lc -lpcc crtendT.o crtn.o
#pcc -v -static -o hello demo_c_hello_noinc.c
# The original $PATH is needed for as(1) called by pcc(1).
pccbin/pcc -W -Wall -WW -Werror -v -c -o examples/hello.o examples/demo_c_hello_noinc.c
$I386_CCLD -s -o examples/hello examples/hello.o
examples/hello
test "$(examples/hello)" = "Hello, World!"

if test -f examples/mininasm_noh.c && test -f examples/mininasm.c; then
  PATH=/dev/null/nopath pccbin/pcc -O2 -S -W -Wall -Wshadow -Wno-unused-parameter -Werror-implicit-function-declaration -Werror -o examples/mininasm.tmp.s examples/mininasm_noh.c
  $I386_CCLD -s -o examples/mininasm examples/mininasm.tmp.s
  examples/mininasm -O9 -f bin -o examples/minnnasm.com -l examples/minnnasm.lst examples/minnnasm.na
  cmp examples/minnnasm.com.good examples/minnnasm.com
  diff examples/minnnasm.lst.good examples/minnnasm.lst
fi

: "$0" OK.
