#! /bin/sh --
#
# compile.sh: build script for PCC 1.1.0 on Linux, targeting Linux i386
# by pts@fazekas.hu at Sat Jun 10 12:46:04 CEST 2023
#
# Compile with: ./compile.sh gcc   -s -Os -W -Wall -Wmissing-prototypes -Wshadow -Wsign-compare -Wno-unused-parameter -Werror-implicit-function-declaration
# Compile with: ./compile.sh clang -s -Os -W -Wall -Wmissing-prototypes -Wshadow -Wsign-compare -Wno-unused-parameter -Werror-implicit-function-declaration
# Compile with: ./compile.sh owcc -blinux -march=i386 -s -O2 -I"$WATCOM"/lh -fsigned-char -fno-stack-protector -W -Wextra -Wno-n303
# Compile with: ./compile.sh minicc --gcc --diet -Wno-unused-parameter
# Compile with: ./compile.sh minicc --wcc --diet -Wno-unused-parameter
# Compile with: ./compile.sh minicc --tcc --diet -Wno-unused-parameter
#

set -ex

# !! There is also libpcc with divdi3 in a separate download: http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/pcc-libs-1.1.0.tgz

CC='gcc -s -Os -W -Wall -Wmissing-prototypes -Wshadow -Wsign-compare'
test $# = 0 || CC="$*"
I386_CCLD="${I386_CCLD:-gcc -m32}"

test -d pccbin || mkdir pccbin
$CC -DLIBEXECDIR=\"/usr/local/libexec/\" -DGCC_COMPAT -DPCC_DEBUG -DINCLUDEDIR=\"/usr/local/h/\" -DPCCINCDIR=\"/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/h/\" -DPCCLIBDIR=\"/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/lib/\" -Dos_linux -Dmach_i386 -DTARGOSVER=0 -DCPPROGNAME=\"pcpp\" \
    -Ih/cc/driver -Ih/top -Ih/os/linux -Ih/mip -Ih/arch/i386 \
    src/cc/cc/cc.c src/mip/compat.c src/cc/driver/strlist.c src/cc/driver/xalloc.c src/bsd/strlcpy.c src/bsd/strlcat.c \
    -o pccbin/pcc
$CC -DGCC_COMPAT -DPCC_DEBUG -D_ISOC99_SOURCE -Dos_linux -Dmach_i386 \
   -Ih/cc/ccom -Ih/top -Ih/mip -Ih/arch/i386 -Ih/os/linux \
    src/cc/ccom/builtins.c src/cc/ccom/cgram_auto.c src/arch/i386/code.c src/mip/common.c src/mip/compat.c src/cc/ccom/external_auto.c src/cc/ccom/gcc_compat.c src/cc/ccom/init.c src/cc/ccom/inline.c src/arch/i386/local.c src/arch/i386/local2.c src/cc/ccom/main.c \
    src/mip/match.c src/cc/ccom/optim.c src/mip/optim2.c src/arch/i386/order.c src/cc/ccom/pftn.c src/mip/reader.c src/mip/regs.c src/cc/ccom/scan_auto.c src/cc/ccom/stabs.c src/cc/ccom/symtabs.c src/arch/i386/table.c src/cc/ccom/trees.c src/mip/unicode.c src/bsd/strlcpy.c src/bsd/strlcat.c \
    -o pccbin/ccom
$CC -DGCC_COMPAT -DPCC_DEBUG -D_ISOC99_SOURCE -Dos_linux -Dmach_i386 \
    -Ih/cc/cpp -Ih/top -Ih/mip -Ih/arch/i386 \
    src/mip/compat.c src/cc/cpp/cpp.c src/cc/cpp/cpy_auto.c src/cc/cpp/token.c src/bsd/strlcpy.c src/bsd/strlcat.c \
    -o pccbin/cpp

ls -ld pccbin/pcc pccbin/ccom pccbin/cpp

# !!! Does OpenBSD or NetBSD have an ELF linker other than GNU ld(1)?
# Without -static: Calling ld -o hello -v -d -dynamic-linker /lib/ld-linux.so.2 -e _start crt1.o crti.o crtbegin.o /tmp/ctm.dgee2t -L/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/lib/ -L/usr/lib/ -lpcc -lc -lpcc crtend.o crtn.o
# With -static: ld -o hello -v -d -Bstatic crt1.o crti.o crtbeginT.o /tmp/ctm.98t5r2 -L/usr/local/lib/pcc/i386-pc-linux-gnu/1.1.0/lib/ -L/usr/lib/ -lpcc -lc -lpcc crtendT.o crtn.o
#pcc -v -static -o hello demo_c_hello_noinc.c
# The original $PATH is needed for as(1) called by pcc(1).
PATH="$PWD/pccbin.mini:$PATH" pcc -v -c -o examples/hello.o examples/demo_c_hello_noinc.c
$I386_CCLD -s -o examples/hello examples/hello.o
examples/hello
test "$(examples/hello)" = "Hello, World!"

: "$0" OK.
