#! /bin/sh --
# by pts@fazekas.hu at Wed May 29 15:19:46 CEST 2024
set -ex
test "${0%/*}" = "$0" || cd "${0%/*}"

# If we omit --gcc=4.8, we lose 80-bit `long double' support. OpenWatcom only has 64-bit `double'.
# -march=i386 is needed by DOSBox, because it silently fails for cmovne in -march=i686.
# -fno-common is needed by wlink, otherwise it generates buggy code.
# !! Fix gettmp() in src/cc/cc/cc.c , don't hardcode /tmp for Unix.
../minilibc686/pathbin/minicc --gcc=4.8 -march=i386 -c -fno-common -nostdlib -Wadd=shadow -ansi -DCONFIG_NO_FERROR -DCONFIG_STAT64 -DCONFIG_MALLOC_FROM_STDLIB_H -DCONFIG_NO_SIGNAL -DCONFIG_MANUAL_EXEC -DCONFIG_NO_RP3 -DCONFIG_NO_ACCESS -DCONFIG_NO_ERRNO -DCONFIG_USE_IS_DIRECTORY \
    -DGCC_COMPAT -DPCC_DEBUG -Dos_linux -Dmach_i386 \
    -DLIBEXECDIR=\"/dev/null/libexec/\" -DINCLUDEDIR=\"/dev/null/h/\" -DPCCINCDIR=\"/dev/null/hh/\" -DPCCLIBDIR=\"/dev/null/lib/\" -DTARGOSVER=0 -DCPPROGNAME=\"pcpp\" \
    -Ih/cc/driver -Ih/cc/ccom -Ih/cc/cpp -Ih/top -Ih/mip -Ih/arch/i386 -Ih/os/linux \
     src/cc/cc/cc.c src/cc/driver/strlist.c src/cc/driver/xalloc.c \
     src/cc/ccom/builtins.c src/cc/ccom/cgram_auto.c src/arch/i386/code.c src/mip/common.c src/cc/ccom/external_auto.c src/cc/ccom/gcc_compat.c src/cc/ccom/init.c src/cc/ccom/inline.c src/arch/i386/local.c src/arch/i386/local2.c src/cc/ccom/main.c \
        src/mip/match.c src/cc/ccom/optim.c src/mip/optim2.c src/arch/i386/order.c src/cc/ccom/pftn.c src/mip/reader.c src/mip/regs.c src/cc/ccom/scan_auto.c src/cc/ccom/stabs.c src/cc/ccom/symtabs.c src/arch/i386/table.c src/cc/ccom/trees.c src/mip/unicode.c \
     src/cc/cpp/cpp.c src/cc/cpp/cpy_auto.c \
     src/cc/cpp/token.c src/bsd/strlcpy.c src/bsd/strlcat.c \
     src/mip/mkstemp.c src/mip/ld96.c
../minilibc686/pathbin/minicc -march=i386 -c -momf -o win32_adapter.o win32_adapter.c
wlink sys win32 op map=t.map op q runtime console=3.10 op noext l clib3r n pts-pccp.unc.exe f win32_adapter.o f token.o f table.o f reader.o f strlcat.o f scan_auto.o f cgram_auto.o f cpp.o f inline.o f trees.o f strlcpy.o f xalloc.o f cpy_auto.o f symtabs.o f gcc_compat.o f init.o f optim.o f code.o f local.o f builtins.o f main.o f local2.o f cc.o f external_auto.o f optim2.o f common.o f match.o f unicode.o f mkstemp.o f pftn.o f regs.o f stabs.o f order.o f strlist.o f ld96.o \
    f ../minilibc686/build_tmp/ffs.o f ../minilibc686/build_tmp/atoi.o f ../minilibc686/build_tmp/getopt.i386.o f ../minilibc686/build_tmp/i64_divdi3.o f ../minilibc686/build_tmp/i64_moddi3.o f ../minilibc686/build_tmp/i64_udivdi3.o f ../minilibc686/build_tmp/i64_umoddi3.o f ../minilibc686/build_tmp/i64_i8d.o f ../minilibc686/build_tmp/i64_u8d.o f ../minilibc686/build_tmp/isalpha_rp3.o f ../minilibc686/build_tmp/isdigit_rp3.o f ../minilibc686/build_tmp/isspace_rp3.o f ../minilibc686/build_tmp/memcmp.o f ../minilibc686/build_tmp/memcpy.o f ../minilibc686/build_tmp/memset.o f ../minilibc686/build_tmp/strchr.o f ../minilibc686/build_tmp/strcmp.o f ../minilibc686/build_tmp/strlen.o f ../minilibc686/build_tmp/strncmp.o f ../minilibc686/build_tmp/strrchr.i386.o f ../minilibc686/build_tmp/strstr.o f ../minilibc686/build_tmp/strtok.o f ../minilibc686/build_tmp/strtol.o f ../minilibc686/build_tmp/strtold.o
upx.pts --ultra-brute --no-lzma -q -q -f -o pts-pccp.ubr.exe pts-pccp.unc.exe

: "$0" OK.
