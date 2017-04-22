begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ===-- int_lib.h - configuration header for compiler-rt  -----------------===  *  *                     The LLVM Compiler Infrastructure  *  * This file is dual licensed under the MIT and the University of Illinois Open  * Source Licenses. See LICENSE.TXT for details.  *  * ===----------------------------------------------------------------------===  *  * This file is a configuration header for compiler-rt.  * This file is not part of the interface of this library.  *  * ===----------------------------------------------------------------------===  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INT_LIB_H
end_ifndef

begin_define
define|#
directive|define
name|INT_LIB_H
end_define

begin_comment
comment|/* Assumption: Signed integral is 2's complement. */
end_comment

begin_comment
comment|/* Assumption: Right shift of signed negative is arithmetic shift. */
end_comment

begin_comment
comment|/* Assumption: Endianness is little or big (not mixed). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ELF__
argument_list|)
end_if

begin_define
define|#
directive|define
name|FNALIAS
parameter_list|(
name|alias_name
parameter_list|,
name|original_name
parameter_list|)
define|\
value|void alias_name() __attribute__((alias(#original_name)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FNALIAS
parameter_list|(
name|alias
parameter_list|,
name|name
parameter_list|)
value|_Pragma("GCC error(\"alias unsupported on this file format\")")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ABI macro definitions */
end_comment

begin_if
if|#
directive|if
name|__ARM_EABI__
end_if

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
define|\
value|void __aeabi_##aeabi_name() __attribute__((alias("__" #name)));
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|COMPILER_RT_ARMHF_TARGET
argument_list|)
operator|||
operator|(
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
name|__GNUC__
operator|<
literal|4
operator|||
name|__GNUC__
operator|==
literal|4
operator|&&
name|__GNUC_MINOR__
operator|<
literal|5
operator|)
operator|)
end_if

begin_comment
comment|/* The pcs attribute was introduced in GCC 4.5.0 */
end_comment

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
value|__attribute__((pcs("aapcs")))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_EABI_FNALIAS
parameter_list|(
name|aeabi_name
parameter_list|,
name|name
parameter_list|)
end_define

begin_define
define|#
directive|define
name|COMPILER_RT_ABI
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_MSC_VER
end_ifdef

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__forceinline
end_define

begin_define
define|#
directive|define
name|NOINLINE
value|__declspec(noinline)
end_define

begin_define
define|#
directive|define
name|NORETURN
value|__declspec(noreturn)
end_define

begin_define
define|#
directive|define
name|UNUSED
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ALWAYS_INLINE
value|__attribute__((always_inline))
end_define

begin_define
define|#
directive|define
name|NOINLINE
value|__attribute__((noinline))
end_define

begin_define
define|#
directive|define
name|NORETURN
value|__attribute__((noreturn))
end_define

begin_define
define|#
directive|define
name|UNUSED
value|__attribute__((unused))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_STANDALONE
argument_list|)
operator|)
end_if

begin_comment
comment|/*  * Kernel and boot environment can't use normal headers,  * so use the equivalent system headers.  */
end_comment

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Include the standard compiler builtin headers we use functionality from. */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include the commonly used internal type definitions. */
end_comment

begin_include
include|#
directive|include
file|"int_types.h"
end_include

begin_comment
comment|/* Include internal utility function declarations. */
end_comment

begin_include
include|#
directive|include
file|"int_util.h"
end_include

begin_comment
comment|/*  * Workaround for LLVM bug 11663.  Prevent endless recursion in  * __c?zdi2(), where calls to __builtin_c?z() are expanded to  * __c?zdi2() instead of __c?zsi2().  *  * Instead of placing this workaround in c?zdi2.c, put it in this  * global header to prevent other C files from making the detour  * through __c?zdi2() as well.  *  * This problem has been observed on FreeBSD for sparc64 and  * mips64 with GCC 4.2.1, and for riscv with GCC 5.2.0.  * Presumably it's any version of GCC, and targeting an arch that  * does not have dedicated bit counting instructions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|__sparc64__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__mips_n64
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_o64
argument_list|)
operator|||
name|defined
argument_list|(
name|__riscv__
argument_list|)
operator|)
end_if

begin_function_decl
name|si_int
name|__clzsi2
parameter_list|(
name|si_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|si_int
name|__ctzsi2
parameter_list|(
name|si_int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|__builtin_clz
value|__clzsi2
end_define

begin_define
define|#
directive|define
name|__builtin_ctz
value|__ctzsi2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FreeBSD&& (sparc64 || mips_n64 || mips_o64) */
end_comment

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__paritysi2
parameter_list|(
name|si_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__paritydi2
parameter_list|(
name|di_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
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

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__divsi3
parameter_list|(
name|si_int
name|a
parameter_list|,
name|si_int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|su_int
name|__udivsi3
parameter_list|(
name|su_int
name|n
parameter_list|,
name|su_int
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|su_int
name|__udivmodsi4
parameter_list|(
name|su_int
name|a
parameter_list|,
name|su_int
name|b
parameter_list|,
name|su_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRT_HAS_128BIT
end_ifdef

begin_function_decl
name|COMPILER_RT_ABI
name|si_int
name|__clzti2
parameter_list|(
name|ti_int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|COMPILER_RT_ABI
name|tu_int
name|__udivmodti4
parameter_list|(
name|tu_int
name|a
parameter_list|,
name|tu_int
name|b
parameter_list|,
name|tu_int
modifier|*
name|rem
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Definitions for builtins unavailable on MSVC */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__clang__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<intrin.h>
end_include

begin_function
name|uint32_t
name|__inline
name|__builtin_ctz
parameter_list|(
name|uint32_t
name|value
parameter_list|)
block|{
name|unsigned
name|long
name|trailing_zero
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_BitScanForward
argument_list|(
operator|&
name|trailing_zero
argument_list|,
name|value
argument_list|)
condition|)
return|return
name|trailing_zero
return|;
return|return
literal|32
return|;
block|}
end_function

begin_function
name|uint32_t
name|__inline
name|__builtin_clz
parameter_list|(
name|uint32_t
name|value
parameter_list|)
block|{
name|unsigned
name|long
name|leading_zero
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_BitScanReverse
argument_list|(
operator|&
name|leading_zero
argument_list|,
name|value
argument_list|)
condition|)
return|return
literal|31
operator|-
name|leading_zero
return|;
return|return
literal|32
return|;
block|}
end_function

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_M_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|_M_X64
argument_list|)
end_if

begin_function
name|uint32_t
name|__inline
name|__builtin_clzll
parameter_list|(
name|uint64_t
name|value
parameter_list|)
block|{
name|unsigned
name|long
name|leading_zero
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|_BitScanReverse64
argument_list|(
operator|&
name|leading_zero
argument_list|,
name|value
argument_list|)
condition|)
return|return
literal|63
operator|-
name|leading_zero
return|;
return|return
literal|64
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
name|uint32_t
name|__inline
name|__builtin_clzll
parameter_list|(
name|uint64_t
name|value
parameter_list|)
block|{
if|if
condition|(
name|value
operator|==
literal|0
condition|)
return|return
literal|64
return|;
name|uint32_t
name|msh
init|=
call|(
name|uint32_t
call|)
argument_list|(
name|value
operator|>>
literal|32
argument_list|)
decl_stmt|;
name|uint32_t
name|lsh
init|=
call|(
name|uint32_t
call|)
argument_list|(
name|value
operator|&
literal|0xFFFFFFFF
argument_list|)
decl_stmt|;
if|if
condition|(
name|msh
operator|!=
literal|0
condition|)
return|return
name|__builtin_clz
argument_list|(
name|msh
argument_list|)
return|;
return|return
literal|32
operator|+
name|__builtin_clz
argument_list|(
name|lsh
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__builtin_clzl
value|__builtin_clzll
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(_MSC_VER)&& !defined(__clang__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INT_LIB_H */
end_comment

end_unit

