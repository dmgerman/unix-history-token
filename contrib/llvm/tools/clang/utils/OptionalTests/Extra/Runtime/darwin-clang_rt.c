begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file tests that we can succesfully call each compiler-rt function. It is    designed to check that the runtime libraries are available for linking and    that they contain the expected contents. It is not designed to test the    correctness of the individual functions in compiler-rt.     This test is assumed to be run on a 10.6 machine. The two environment    variables below should be set to 10.4 and 10.5 machines which can be directly    ssh/rsync'd to in order to actually test the executables can run on the    desired targets. */
end_comment

begin_comment
comment|// RUN: export TENFOUR_X86_MACHINE=localhost
end_comment

begin_comment
comment|// RUN: export TENFIVE_X86_MACHINE=localhost
end_comment

begin_comment
comment|// RUN: export ARM_MACHINE=localhost
end_comment

begin_comment
comment|// RUN: export ARM_SYSROOT=$(xcodebuild -sdk iphoneos -version Path)
end_comment

begin_comment
comment|// RUN: echo iPhoneOS, ARM, v6, thumb
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv6 -mthumb -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv6 -mthumb -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: rsync -arv %t $ARM_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $ARM_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo iPhoneOS, ARM, v6, no-thumb
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv6 -mno-thumb -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv6 -mno-thumb -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: rsync -arv %t $ARM_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $ARM_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo iPhoneOS, ARM, v7, thumb
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv7 -mthumb -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv7 -mthumb -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: rsync -arv %t $ARM_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $ARM_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo iPhoneOS, ARM, v7, no-thumb
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv7 -mno-thumb -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -isysroot $ARM_SYSROOT -arch armv7 -mno-thumb -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: rsync -arv %t $ARM_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $ARM_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.4, i386
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.4 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.4 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: rsync -arv %t $TENFOUR_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $TENFOUR_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUX: rsync -arv %t $TENFIVE_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUX: ssh $TENFIVE_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.5, i386
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.5 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.5 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: rsync -arv %t $TENFIVE_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $TENFIVE_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.6, i386
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.6 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch i386 -mmacosx-version-min=10.6 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.4, x86_64
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.4 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.4 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: rsync -arv %t $TENFOUR_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $TENFOUR_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: rsync -arv %t $TENFIVE_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $TENFIVE_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.5, x86_64
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.5 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.5 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: rsync -arv %t $TENFIVE_X86_MACHINE:/tmp/a.out
end_comment

begin_comment
comment|// RUN: ssh $TENFIVE_X86_MACHINE /tmp/a.out
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_comment
comment|// RUN: echo 10.6, x86_64
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.6 -c %s -o %t.o
end_comment

begin_comment
comment|// RUN: %clang -arch x86_64 -mmacosx-version-min=10.6 -v -Wl,-t,-v -o %t %t.o 1>&2
end_comment

begin_comment
comment|// RUN: %t
end_comment

begin_comment
comment|// RUN: echo
end_comment

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/utsname.h>
end_include

begin_typedef
typedef|typedef
name|int
name|si_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|su_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|di_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|du_int
typedef|;
end_typedef

begin_comment
comment|// Integral bit manipulation
end_comment

begin_function_decl
name|di_int
name|__ashldi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a<< b
end_comment

begin_function_decl
name|di_int
name|__ashrdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a>> b  arithmetic (sign fill)
end_comment

begin_function_decl
name|di_int
name|__lshrdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a>> b  logical    (zero fill)
end_comment

begin_function_decl
name|si_int
name|__clzsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// count leading zeros
end_comment

begin_function_decl
name|si_int
name|__clzdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// count leading zeros
end_comment

begin_function_decl
name|si_int
name|__ctzsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// count trailing zeros
end_comment

begin_function_decl
name|si_int
name|__ctzdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// count trailing zeros
end_comment

begin_function_decl
name|si_int
name|__ffsdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// find least significant 1 bit
end_comment

begin_function_decl
name|si_int
name|__paritysi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// bit parity
end_comment

begin_function_decl
name|si_int
name|__paritydi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// bit parity
end_comment

begin_function_decl
name|si_int
name|__popcountsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// bit population
end_comment

begin_function_decl
name|si_int
name|__popcountdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// bit population
end_comment

begin_comment
comment|// Integral arithmetic
end_comment

begin_function_decl
name|di_int
name|__negdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// -a
end_comment

begin_function_decl
name|di_int
name|__muldi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a * b
end_comment

begin_function_decl
name|di_int
name|__divdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a / b   signed
end_comment

begin_function_decl
name|du_int
name|__udivdi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a / b   unsigned
end_comment

begin_function_decl
name|di_int
name|__moddi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a % b   signed
end_comment

begin_function_decl
name|du_int
name|__umoddi3
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a % b   unsigned
end_comment

begin_function_decl
name|du_int
name|__udivmoddi4
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|,
name|du_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a / b, *rem = a % b
end_comment

begin_comment
comment|//  Integral arithmetic with trapping overflow
end_comment

begin_function_decl
name|si_int
name|__absvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// abs(a)
end_comment

begin_function_decl
name|di_int
name|__absvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// abs(a)
end_comment

begin_function_decl
name|si_int
name|__negvsi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// -a
end_comment

begin_function_decl
name|di_int
name|__negvdi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// -a
end_comment

begin_function_decl
name|si_int
name|__addvsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a + b
end_comment

begin_function_decl
name|di_int
name|__addvdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a + b
end_comment

begin_function_decl
name|si_int
name|__subvsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a - b
end_comment

begin_function_decl
name|di_int
name|__subvdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a - b
end_comment

begin_function_decl
name|si_int
name|__mulvsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a * b
end_comment

begin_function_decl
name|di_int
name|__mulvdi3
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a * b
end_comment

begin_comment
comment|//  Integral comparison: a< b -> 0
end_comment

begin_comment
comment|//                       a == b -> 1
end_comment

begin_comment
comment|//                       a> b -> 2
end_comment

begin_function_decl
name|si_int
name|__cmpdi2
parameter_list|(
name|di_int
name|a
parameter_list|,
name|di_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|si_int
name|__ucmpdi2
parameter_list|(
name|du_int
name|a
parameter_list|,
name|du_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//  Integral / floating point conversion
end_comment

begin_function_decl
name|di_int
name|__fixsfdi
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|di_int
name|__fixdfdi
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|di_int
name|__fixxfdi
parameter_list|(
name|long
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|su_int
name|__fixunssfsi
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|su_int
name|__fixunsdfsi
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|su_int
name|__fixunsxfsi
parameter_list|(
name|long
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|du_int
name|__fixunssfdi
parameter_list|(
name|float
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|du_int
name|__fixunsdfdi
parameter_list|(
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|du_int
name|__fixunsxfdi
parameter_list|(
name|long
name|double
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__floatdisf
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__floatdidf
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|__floatdixf
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|float
name|__floatundisf
parameter_list|(
name|du_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
name|__floatundidf
parameter_list|(
name|du_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|__floatundixf
parameter_list|(
name|du_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//  Floating point raised to integer power
end_comment

begin_function_decl
name|float
name|__powisf2
parameter_list|(
name|float
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a ^ b
end_comment

begin_function_decl
name|double
name|__powidf2
parameter_list|(
name|double
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a ^ b
end_comment

begin_function_decl
name|long
name|double
name|__powixf2
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// a ^ b
end_comment

begin_comment
comment|//  Complex arithmetic
end_comment

begin_comment
comment|//  (a + ib) * (c + id)
end_comment

begin_function_decl
name|float
specifier|_Complex
name|__mulsc3
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
specifier|_Complex
name|__muldc3
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
specifier|_Complex
name|__mulxc3
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|,
name|long
name|double
name|c
parameter_list|,
name|long
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//  (a + ib) / (c + id)
end_comment

begin_function_decl
name|float
specifier|_Complex
name|__divsc3
parameter_list|(
name|float
name|a
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|,
name|float
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|double
specifier|_Complex
name|__divdc3
parameter_list|(
name|double
name|a
parameter_list|,
name|double
name|b
parameter_list|,
name|double
name|c
parameter_list|,
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
specifier|_Complex
name|__divxc3
parameter_list|(
name|long
name|double
name|a
parameter_list|,
name|long
name|double
name|b
parameter_list|,
name|long
name|double
name|c
parameter_list|,
name|long
name|double
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|__arm
end_ifndef

begin_define
define|#
directive|define
name|HAS_LONG_DOUBLE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
name|du_int
name|du_tmp
decl_stmt|;
name|struct
name|utsname
name|name
decl_stmt|;
ifdef|#
directive|ifdef
name|__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
specifier|const
name|char
modifier|*
name|target_name
init|=
literal|"OS X"
decl_stmt|;
name|unsigned
name|target_version
init|=
name|__ENVIRONMENT_MAC_OS_X_VERSION_MIN_REQUIRED__
decl_stmt|;
name|unsigned
name|target_maj
init|=
name|target_version
operator|/
literal|100
decl_stmt|;
name|unsigned
name|target_min
init|=
operator|(
name|target_version
operator|/
literal|10
operator|)
operator|%
literal|10
decl_stmt|;
name|unsigned
name|target_micro
init|=
name|target_version
operator|%
literal|10
decl_stmt|;
else|#
directive|else
specifier|const
name|char
modifier|*
name|target_name
init|=
literal|"iPhoneOS"
decl_stmt|;
name|unsigned
name|target_version
init|=
name|__ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__
decl_stmt|;
name|unsigned
name|target_maj
init|=
name|target_version
operator|/
literal|10000
decl_stmt|;
name|unsigned
name|target_min
init|=
operator|(
name|target_version
operator|/
literal|100
operator|)
operator|%
literal|100
decl_stmt|;
name|unsigned
name|target_micro
init|=
name|target_version
operator|%
literal|100
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|uname
argument_list|(
operator|&
name|name
argument_list|)
condition|)
return|return
literal|1
return|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: clang_rt test:\n"
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  target  : %s %d.%d.%d\n\n"
argument_list|,
name|target_name
argument_list|,
name|target_maj
argument_list|,
name|target_min
argument_list|,
name|target_micro
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  sysname : %s\n"
argument_list|,
name|name
operator|.
name|sysname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  nodename: %s\n"
argument_list|,
name|name
operator|.
name|nodename
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  release : %s\n"
argument_list|,
name|name
operator|.
name|release
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  version : %s\n"
argument_list|,
name|name
operator|.
name|version
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"  machine : %s\n"
argument_list|,
name|name
operator|.
name|machine
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ashldi3
argument_list|(
literal|1
argument_list|,
literal|1
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ashrdi3
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__lshrdi3
argument_list|(
literal|2
argument_list|,
literal|1
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__clzsi2
argument_list|(
literal|1
argument_list|)
operator|==
literal|31
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__clzdi2
argument_list|(
literal|1
argument_list|)
operator|==
literal|63
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ctzsi2
argument_list|(
literal|2
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ctzdi2
argument_list|(
literal|2
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ffsdi2
argument_list|(
literal|12
argument_list|)
operator|==
literal|3
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__paritysi2
argument_list|(
literal|13
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__paritydi2
argument_list|(
literal|13
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__popcountsi2
argument_list|(
literal|13
argument_list|)
operator|==
literal|3
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__popcountdi2
argument_list|(
literal|13
argument_list|)
operator|==
literal|3
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__negdi2
argument_list|(
literal|3
argument_list|)
operator|==
operator|-
literal|3
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__muldi3
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
operator|==
literal|4
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__divdi3
argument_list|(
operator|-
literal|4
argument_list|,
literal|2
argument_list|)
operator|==
operator|-
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__udivdi3
argument_list|(
literal|4
argument_list|,
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__moddi3
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__umoddi3
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__udivmoddi4
argument_list|(
literal|5
argument_list|,
literal|2
argument_list|,
operator|&
name|du_tmp
argument_list|)
operator|==
literal|2
operator|&&
name|du_tmp
operator|==
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__absvsi2
argument_list|(
operator|-
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__absvdi2
argument_list|(
operator|-
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__negvsi2
argument_list|(
literal|2
argument_list|)
operator|==
operator|-
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__negvdi2
argument_list|(
literal|2
argument_list|)
operator|==
operator|-
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__addvsi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
literal|5
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__addvdi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
literal|5
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__subvsi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__subvdi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
operator|-
literal|1
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__mulvsi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
literal|6
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__mulvdi3
argument_list|(
literal|2
argument_list|,
literal|3
argument_list|)
operator|==
literal|6
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__cmpdi2
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__ucmpdi2
argument_list|(
literal|3
argument_list|,
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixsfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixdfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunssfsi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunsdfsi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunssfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunsdfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatdisf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatdidf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatundisf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatundidf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__powisf2
argument_list|(
literal|2.0
argument_list|,
literal|2
argument_list|)
operator|==
literal|4.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__powidf2
argument_list|(
literal|2.0
argument_list|,
literal|2
argument_list|)
operator|==
literal|4.0
argument_list|)
expr_stmt|;
comment|// FIXME: Clang/LLVM seems to be miscompiling _Complex currently, probably an
comment|// ABI issue.
ifndef|#
directive|ifndef
name|__arm
block|{
specifier|_Complex
name|float
name|a
init|=
name|__mulsc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
decl_stmt|;
specifier|_Complex
name|float
name|b
init|=
operator|(
operator|-
literal|12.0
operator|+
literal|16.0j
operator|)
decl_stmt|;
name|fprintf
argument_list|(
argument|stderr
argument_list|,
literal|"a: (%f + %f), b: (%f + %f)\n"
argument_list|,
argument|__real a
argument_list|,
argument|__imag a
argument_list|,
argument|__real b
argument_list|,
argument|__imag b
argument_list|)
empty_stmt|;
block|}
name|assert
argument_list|(
name|__mulsc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
operator|-
literal|12.0
operator|+
literal|16.0j
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__muldc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
operator|-
literal|12.0
operator|+
literal|16.0j
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__divsc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
literal|0.25
operator|+
literal|0j
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__divdc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
literal|0.25
operator|+
literal|0j
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAS_LONG_DOUBLE
name|assert
argument_list|(
name|__divxc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
literal|0.25
operator|+
literal|0j
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunsxfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixunsxfsi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__fixxfdi
argument_list|(
literal|2.0
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatdixf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2.0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__floatundixf
argument_list|(
literal|2
argument_list|)
operator|==
literal|2
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__mulxc3
argument_list|(
literal|1.0
argument_list|,
literal|2.0
argument_list|,
literal|4.0
argument_list|,
literal|8.0
argument_list|)
operator|==
operator|(
operator|-
literal|12.0
operator|+
literal|16.0j
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|__powixf2
argument_list|(
literal|2.0
argument_list|,
literal|2
argument_list|)
operator|==
literal|4.0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Test some calls which are used on armv6/thumb. The calls/prototypes are
comment|// fake, it would be nice to test correctness, but mostly we just want to
comment|// make sure we resolve symbols correctly.
if|#
directive|if
name|defined
argument_list|(
name|__arm
argument_list|)
operator|&&
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__thumb__
argument_list|)
if|if
condition|(
name|argc
operator|==
literal|100
condition|)
block|{
specifier|extern
name|void
name|__restore_vfp_d8_d15_regs
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|__save_vfp_d8_d15_regs
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|__switch8
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|__switchu8
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|__switch16
argument_list|(
name|void
argument_list|)
decl_stmt|,
name|__switch32
argument_list|(
name|void
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|__addsf3vfp
argument_list|(
name|void
argument_list|)
decl_stmt|;
name|__addsf3vfp
argument_list|()
expr_stmt|;
name|__restore_vfp_d8_d15_regs
argument_list|()
expr_stmt|;
name|__save_vfp_d8_d15_regs
argument_list|()
expr_stmt|;
name|__switch8
argument_list|()
expr_stmt|;
name|__switchu8
argument_list|()
expr_stmt|;
name|__switch16
argument_list|()
expr_stmt|;
name|__switch32
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"    OK!\n"
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

