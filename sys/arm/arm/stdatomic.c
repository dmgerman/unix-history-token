begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/stdatomic.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"opt_global.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Executing statements with interrupts disabled.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|WITHOUT_INTERRUPTS
parameter_list|(
name|s
parameter_list|)
value|do {					\ 	register_t regs;						\ 									\ 	regs = intr_disable();						\ 	do s while (0);							\ 	intr_restore(regs);						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL&& !SMP */
end_comment

begin_comment
comment|/*  * Memory barriers.  *  * It turns out __sync_synchronize() does not emit any code when used  * with GCC 4.2. Implement our own version that does work reliably.  *  * Although __sync_lock_test_and_set() should only perform an acquire  * barrier, make it do a full barrier like the other functions. This  * should make<stdatomic.h>'s atomic_exchange_explicit() work reliably.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

begin_function
specifier|static
specifier|inline
name|void
name|do_sync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm volatile ("" : : : "memory");
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_elif

begin_function
specifier|static
specifier|inline
name|void
name|do_sync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm volatile ("dmb" : : : "memory");
block|}
end_function

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
end_elif

begin_function
specifier|static
specifier|inline
name|void
name|do_sync
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm volatile ("mcr p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory");
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__CLANG_ATOMICS
argument_list|)
operator|||
name|defined
argument_list|(
name|__GNUC_ATOMICS
argument_list|)
end_if

begin_comment
comment|/*  * New C11 __atomic_* API.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_if

begin_comment
comment|/* These systems should be supported by the compiler. */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_ARCH_5__ */
end_comment

begin_comment
comment|/* Clang doesn't allow us to reimplement builtins without this. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_synchronize_ext
name|__sync_synchronize
end_pragma

begin_define
define|#
directive|define
name|__sync_synchronize
value|__sync_synchronize_ext
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|__sync_synchronize
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_error
error|#
directive|error
literal|"On SMP systems we should have proper atomic operations."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On uniprocessor systems, we can perform the atomic operations by  * disabling interrupts.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_LOAD_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|uintN_t									\ __atomic_load_##N(uintN_t *mem, int model __unused)			\ {									\ 	uintN_t ret;							\ 									\ 	WITHOUT_INTERRUPTS({						\ 		ret = *mem;						\ 	});								\ 	return (ret);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_STORE_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|void									\ __atomic_store_##N(uintN_t *mem, uintN_t val, int model __unused)	\ {									\ 									\ 	WITHOUT_INTERRUPTS({						\ 		*mem = val;						\ 	});								\ }
end_define

begin_define
define|#
directive|define
name|EMIT_COMPARE_EXCHANGE_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|_Bool									\ __atomic_compare_exchange_##N(uintN_t *mem, uintN_t *expected,		\     uintN_t desired, int success __unused, int failure __unused)	\ {									\ 	_Bool ret;							\ 									\ 	WITHOUT_INTERRUPTS({						\ 		if (*mem == *expected) {				\ 			*mem = desired;					\ 			ret = 1;					\ 		} else {						\ 			*expected = *mem;				\ 			ret = 0;					\ 		}							\ 	});								\ 	return (ret);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_FETCH_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uintN_t									\ __atomic_##name##_##N(uintN_t *mem, uintN_t val, int model __unused)	\ {									\ 	uintN_t ret;							\ 									\ 	WITHOUT_INTERRUPTS({						\ 		ret = *mem;						\ 		*mem op val;						\ 	});								\ 	return (ret);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_ALL_OPS_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|EMIT_LOAD_N(N, uintN_t)							\ EMIT_STORE_N(N, uintN_t)						\ EMIT_COMPARE_EXCHANGE_N(N, uintN_t)					\ EMIT_FETCH_OP_N(N, uintN_t, exchange, =)				\ EMIT_FETCH_OP_N(N, uintN_t, fetch_add, +=)				\ EMIT_FETCH_OP_N(N, uintN_t, fetch_and,&=)				\ EMIT_FETCH_OP_N(N, uintN_t, fetch_or, |=)				\ EMIT_FETCH_OP_N(N, uintN_t, fetch_sub, -=)				\ EMIT_FETCH_OP_N(N, uintN_t, fetch_xor, ^=)
end_define

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|EMIT_ALL_OPS_N
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * For userspace on uniprocessor systems, we can implement the atomic  * operations by using a Restartable Atomic Sequence. This makes the  * kernel restart the code from the beginning when interrupted.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_LOAD_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|uintN_t									\ __atomic_load_##N(uintN_t *mem, int model __unused)			\ {									\ 									\ 	return (*mem);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_STORE_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|void									\ __atomic_store_##N(uintN_t *mem, uintN_t val, int model __unused)	\ {									\ 									\ 	*mem = val;							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_EXCHANGE_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|)
define|\
value|uintN_t									\ __atomic_exchange_##N(uintN_t *mem, uintN_t val, int model __unused)	\ {									\ 	uint32_t old, temp, ras_start;					\ 									\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%5]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%5, #4]\n"				\ 									\ 		"\t"ldr" %0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"str" %3, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%5]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%5, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem), "r" (ras_start));		\ 	return (old);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_COMPARE_EXCHANGE_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|streq
parameter_list|)
define|\
value|_Bool									\ __atomic_compare_exchange_##N(uintN_t *mem, uintN_t *pexpected,		\     uintN_t desired, int success __unused, int failure __unused)	\ {									\ 	uint32_t expected, old, temp, ras_start;			\ 									\ 	expected = *pexpected;						\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%6]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%6, #4]\n"				\ 									\ 		"\t"ldr" %0, %5\n"
comment|/* Load old value. */
value|\ 		"\tcmp   %0, %3\n"
comment|/* Compare to expected value. */
value|\ 		"\t"streq" %4, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%6]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%6, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (expected), "r" (desired), "m" (*mem),		\ 		  "r" (ras_start));					\ 	if (old == expected) {						\ 		return (1);						\ 	} else {							\ 		*pexpected = old;					\ 		return (0);						\ 	}								\ }
end_define

begin_define
define|#
directive|define
name|EMIT_FETCH_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uintN_t									\ __atomic_##name##_##N(uintN_t *mem, uintN_t val, int model __unused)	\ {									\ 	uint32_t old, temp, ras_start;					\ 									\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%5]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%5, #4]\n"				\ 									\ 		"\t"ldr" %0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"  %2, %0, %3\n"
comment|/* Calculate new value. */
value|\ 		"\t"str" %2, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%5]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%5, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem), "r" (ras_start));		\ 	return (old);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_ALL_OPS_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|,
name|streq
parameter_list|)
define|\
value|EMIT_LOAD_N(N, uintN_t)							\ EMIT_STORE_N(N, uintN_t)						\ EMIT_EXCHANGE_N(N, uintN_t, ldr, str)					\ EMIT_COMPARE_EXCHANGE_N(N, uintN_t, ldr, streq)				\ EMIT_FETCH_OP_N(N, uintN_t, ldr, str, fetch_add, "add")			\ EMIT_FETCH_OP_N(N, uintN_t, ldr, str, fetch_and, "and")			\ EMIT_FETCH_OP_N(N, uintN_t, ldr, str, fetch_or, "orr")			\ EMIT_FETCH_OP_N(N, uintN_t, ldr, str, fetch_sub, "sub")			\ EMIT_FETCH_OP_N(N, uintN_t, ldr, str, fetch_xor, "eor")
end_define

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
literal|"ldrb"
argument_list|,
literal|"strb"
argument_list|,
literal|"strbeq"
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
literal|"ldrh"
argument_list|,
literal|"strh"
argument_list|,
literal|"strheq"
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
literal|"ldr"
argument_list|,
literal|"str"
argument_list|,
literal|"streq"
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|EMIT_ALL_OPS_N
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CLANG_ATOMICS || __GNUC_ATOMICS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SYNC_ATOMICS
argument_list|)
operator|||
name|defined
argument_list|(
name|EMIT_SYNC_ATOMICS
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_lock_test_and_set_1_c
name|__sync_lock_test_and_set_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_lock_test_and_set_2_c
name|__sync_lock_test_and_set_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_lock_test_and_set_4_c
name|__sync_lock_test_and_set_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_val_compare_and_swap_1_c
name|__sync_val_compare_and_swap_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_val_compare_and_swap_2_c
name|__sync_val_compare_and_swap_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_val_compare_and_swap_4_c
name|__sync_val_compare_and_swap_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_add_1_c
name|__sync_fetch_and_add_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_add_2_c
name|__sync_fetch_and_add_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_add_4_c
name|__sync_fetch_and_add_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_and_1_c
name|__sync_fetch_and_and_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_and_2_c
name|__sync_fetch_and_and_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_and_4_c
name|__sync_fetch_and_and_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_or_1_c
name|__sync_fetch_and_or_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_or_2_c
name|__sync_fetch_and_or_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_or_4_c
name|__sync_fetch_and_or_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_xor_1_c
name|__sync_fetch_and_xor_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_xor_2_c
name|__sync_fetch_and_xor_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_xor_4_c
name|__sync_fetch_and_xor_4
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_sub_1_c
name|__sync_fetch_and_sub_1
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_sub_2_c
name|__sync_fetch_and_sub_2
end_pragma

begin_pragma
pragma|#
directive|pragma
name|redefine_extname
name|__sync_fetch_and_sub_4_c
name|__sync_fetch_and_sub_4
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Old __sync_* API.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6J__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6K__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
end_if

begin_comment
comment|/* Implementations for old GCC versions, lacking support for atomics. */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|v8
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|v32
decl_stmt|;
block|}
name|reg_t
typedef|;
end_typedef

begin_comment
comment|/*  * Given a memory address pointing to an 8-bit or 16-bit integer, return  * the address of the 32-bit word containing it.  */
end_comment

begin_function
specifier|static
specifier|inline
name|uint32_t
modifier|*
name|round_to_word
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|ptr
operator|&
operator|~
literal|3
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Utility functions for loading and storing 8-bit and 16-bit integers  * in 32-bit words at an offset corresponding with the location of the  * atomic variable.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|put_1
parameter_list|(
name|reg_t
modifier|*
name|r
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|offset_ptr
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
name|size_t
name|offset
decl_stmt|;
name|offset
operator|=
operator|(
name|intptr_t
operator|)
name|offset_ptr
operator|&
literal|3
expr_stmt|;
name|r
operator|->
name|v8
index|[
name|offset
index|]
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint8_t
name|get_1
parameter_list|(
specifier|const
name|reg_t
modifier|*
name|r
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|offset_ptr
parameter_list|)
block|{
name|size_t
name|offset
decl_stmt|;
name|offset
operator|=
operator|(
name|intptr_t
operator|)
name|offset_ptr
operator|&
literal|3
expr_stmt|;
return|return
operator|(
name|r
operator|->
name|v8
index|[
name|offset
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|put_2
parameter_list|(
name|reg_t
modifier|*
name|r
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|offset_ptr
parameter_list|,
name|uint16_t
name|val
parameter_list|)
block|{
name|size_t
name|offset
decl_stmt|;
union|union
block|{
name|uint16_t
name|in
decl_stmt|;
name|uint8_t
name|out
index|[
literal|2
index|]
decl_stmt|;
block|}
name|bytes
union|;
name|offset
operator|=
operator|(
name|intptr_t
operator|)
name|offset_ptr
operator|&
literal|3
expr_stmt|;
name|bytes
operator|.
name|in
operator|=
name|val
expr_stmt|;
name|r
operator|->
name|v8
index|[
name|offset
index|]
operator|=
name|bytes
operator|.
name|out
index|[
literal|0
index|]
expr_stmt|;
name|r
operator|->
name|v8
index|[
name|offset
operator|+
literal|1
index|]
operator|=
name|bytes
operator|.
name|out
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint16_t
name|get_2
parameter_list|(
specifier|const
name|reg_t
modifier|*
name|r
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|offset_ptr
parameter_list|)
block|{
name|size_t
name|offset
decl_stmt|;
union|union
block|{
name|uint8_t
name|in
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|out
decl_stmt|;
block|}
name|bytes
union|;
name|offset
operator|=
operator|(
name|intptr_t
operator|)
name|offset_ptr
operator|&
literal|3
expr_stmt|;
name|bytes
operator|.
name|in
index|[
literal|0
index|]
operator|=
name|r
operator|->
name|v8
index|[
name|offset
index|]
expr_stmt|;
name|bytes
operator|.
name|in
index|[
literal|1
index|]
operator|=
name|r
operator|->
name|v8
index|[
name|offset
operator|+
literal|1
index|]
expr_stmt|;
return|return
operator|(
name|bytes
operator|.
name|out
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * 8-bit and 16-bit routines.  *  * These operations are not natively supported by the CPU, so we use  * some shifting and bitmasking on top of the 32-bit instructions.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_LOCK_TEST_AND_SET_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|uintN_t									\ __sync_lock_test_and_set_##N##_c(uintN_t *mem, uintN_t val)			\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, negmask, old;					\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	negmask.v32 = 0xffffffff;					\ 	put_##N(&negmask, mem, 0);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %6\n"
comment|/* Load old value. */
value|\ 		"\tand   %2, %5, %0\n"
comment|/* Remove the old value. */
value|\ 		"\torr   %2, %2, %4\n"
comment|/* Put in the new value. */
value|\ 		"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tcmp   %3, #0\n"
comment|/* Did it succeed? */
value|\ 		"\tbne   1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "r" (negmask.v32), "m" (*mem32));	\ 	return (get_##N(&old, mem));					\ }
end_define

begin_macro
name|EMIT_LOCK_TEST_AND_SET_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|EMIT_LOCK_TEST_AND_SET_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EMIT_VAL_COMPARE_AND_SWAP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|uintN_t									\ __sync_val_compare_and_swap_##N##_c(uintN_t *mem, uintN_t expected,		\     uintN_t desired)							\ {									\ 	uint32_t *mem32;						\ 	reg_t expected32, desired32, posmask, old;			\ 	uint32_t negmask, temp1, temp2;					\ 									\ 	mem32 = round_to_word(mem);					\ 	expected32.v32 = 0x00000000;					\ 	put_##N(&expected32, mem, expected);				\ 	desired32.v32 = 0x00000000;					\ 	put_##N(&desired32, mem, desired);				\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask = ~posmask.v32;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %8\n"
comment|/* Load old value. */
value|\ 		"\tand   %2, %6, %0\n"
comment|/* Isolate the old value. */
value|\ 		"\tcmp   %2, %4\n"
comment|/* Compare to expected value. */
value|\ 		"\tbne   2f\n"
comment|/* Values are unequal. */
value|\ 		"\tand   %2, %7, %0\n"
comment|/* Remove the old value. */
value|\ 		"\torr   %2, %5\n"
comment|/* Put in the new value. */
value|\ 		"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tcmp   %3, #0\n"
comment|/* Did it succeed? */
value|\ 		"\tbne   1b\n"
comment|/* Spin if failed. */
value|\ 		"2:"							\ 		: "=&r" (old), "=m" (*mem32), "=&r" (temp1),		\ 		  "=&r" (temp2)						\ 		: "r" (expected32.v32), "r" (desired32.v32),		\ 		  "r" (posmask.v32), "r" (negmask), "m" (*mem32));	\ 	return (get_##N(&old, mem));					\ }
end_define

begin_macro
name|EMIT_VAL_COMPARE_AND_SWAP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|EMIT_VAL_COMPARE_AND_SWAP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EMIT_ARITHMETIC_FETCH_AND_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uintN_t									\ __sync_##name##_##N##_c(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, posmask, old;					\ 	uint32_t negmask, temp1, temp2;					\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask = ~posmask.v32;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %7\n"
comment|/* Load old value. */
value|\ 		"\t"op"  %2, %0, %4\n"
comment|/* Calculate new value. */
value|\ 		"\tand   %2, %5\n"
comment|/* Isolate the new value. */
value|\ 		"\tand   %3, %6, %0\n"
comment|/* Remove the old value. */
value|\ 		"\torr   %2, %2, %3\n"
comment|/* Put in the new value. */
value|\ 		"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tcmp   %3, #0\n"
comment|/* Did it succeed? */
value|\ 		"\tbne   1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "r" (posmask.v32), "r" (negmask),	\ 		  "m" (*mem32));					\ 	return (get_##N(&old, mem));					\ }
end_define

begin_macro
name|EMIT_ARITHMETIC_FETCH_AND_OP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|fetch_and_add
argument_list|,
literal|"add"
argument_list|)
end_macro

begin_macro
name|EMIT_ARITHMETIC_FETCH_AND_OP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|fetch_and_sub
argument_list|,
literal|"sub"
argument_list|)
end_macro

begin_macro
name|EMIT_ARITHMETIC_FETCH_AND_OP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|fetch_and_add
argument_list|,
literal|"add"
argument_list|)
end_macro

begin_macro
name|EMIT_ARITHMETIC_FETCH_AND_OP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|fetch_and_sub
argument_list|,
literal|"sub"
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EMIT_BITWISE_FETCH_AND_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|,
name|idempotence
parameter_list|)
define|\
value|uintN_t									\ __sync_##name##_##N##_c(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, old;						\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = idempotence ? 0xffffffff : 0x00000000;		\ 	put_##N(&val32, mem, val);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %5\n"
comment|/* Load old value. */
value|\ 		"\t"op"  %2, %4, %0\n"
comment|/* Calculate new value. */
value|\ 		"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tcmp   %3, #0\n"
comment|/* Did it succeed? */
value|\ 		"\tbne   1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "m" (*mem32));			\ 	return (get_##N(&old, mem));					\ }
end_define

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|fetch_and_and
argument_list|,
literal|"and"
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|fetch_and_or
argument_list|,
literal|"orr"
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
argument|fetch_and_xor
argument_list|,
literal|"eor"
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|fetch_and_and
argument_list|,
literal|"and"
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|fetch_and_or
argument_list|,
literal|"orr"
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|EMIT_BITWISE_FETCH_AND_OP_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
argument|fetch_and_xor
argument_list|,
literal|"eor"
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/*  * 32-bit routines.  */
end_comment

begin_function
name|uint32_t
name|__sync_lock_test_and_set_4_c
parameter_list|(
name|uint32_t
modifier|*
name|mem
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|old
decl_stmt|,
name|temp
decl_stmt|;
name|do_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tldrex %0, %4\n"
comment|/* Load old value. */
literal|"\tstrex %2, %3, %1\n"
comment|/* Attempt to store. */
literal|"\tcmp   %2, #0\n"
comment|/* Did it succeed? */
literal|"\tbne   1b\n"
comment|/* Spin if failed. */
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|mem
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|mem
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|old
operator|)
return|;
end_return

begin_macro
unit|}  uint32_t
name|__sync_val_compare_and_swap_4_c
argument_list|(
argument|uint32_t *mem
argument_list|,
argument|uint32_t expected
argument_list|,
argument|uint32_t desired
argument_list|)
end_macro

begin_block
block|{
name|uint32_t
name|old
decl_stmt|,
name|temp
decl_stmt|;
name|do_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tldrex %0, %5\n"
comment|/* Load old value. */
literal|"\tcmp   %0, %3\n"
comment|/* Compare to expected value. */
literal|"\tbne   2f\n"
comment|/* Values are unequal. */
literal|"\tstrex %2, %4, %1\n"
comment|/* Attempt to store. */
literal|"\tcmp   %2, #0\n"
comment|/* Did it succeed? */
literal|"\tbne   1b\n"
comment|/* Spin if failed. */
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|mem
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|expected
operator|)
operator|,
literal|"r"
operator|(
name|desired
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|mem
operator|)
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_return
return|return
operator|(
name|old
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|EMIT_FETCH_AND_OP_4
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uint32_t								\ __sync_##name##_4##_c(uint32_t *mem, uint32_t val)				\ {									\ 	uint32_t old, temp1, temp2;					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %5\n"
comment|/* Load old value. */
value|\ 		"\t"op"  %2, %0, %4\n"
comment|/* Calculate new value. */
value|\ 		"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tcmp   %3, #0\n"
comment|/* Did it succeed? */
value|\ 		"\tbne   1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp1),		\ 		  "=&r" (temp2)						\ 		: "r" (val), "m" (*mem));				\ 	return (old);							\ }
end_define

begin_expr_stmt
unit|EMIT_FETCH_AND_OP_4
operator|(
name|fetch_and_add
operator|,
literal|"add"
operator|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"orr"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"sub"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"eor"
argument_list|)
ifndef|#
directive|ifndef
name|__clang__
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_1_c
argument_list|,
name|__sync_lock_test_and_set_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_2_c
argument_list|,
name|__sync_lock_test_and_set_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_4_c
argument_list|,
name|__sync_lock_test_and_set_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_1_c
argument_list|,
name|__sync_val_compare_and_swap_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_2_c
argument_list|,
name|__sync_val_compare_and_swap_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_4_c
argument_list|,
name|__sync_val_compare_and_swap_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_1_c
argument_list|,
name|__sync_fetch_and_add_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_2_c
argument_list|,
name|__sync_fetch_and_add_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_4_c
argument_list|,
name|__sync_fetch_and_add_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_1_c
argument_list|,
name|__sync_fetch_and_and_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_2_c
argument_list|,
name|__sync_fetch_and_and_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_4_c
argument_list|,
name|__sync_fetch_and_and_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_1_c
argument_list|,
name|__sync_fetch_and_sub_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_2_c
argument_list|,
name|__sync_fetch_and_sub_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_4_c
argument_list|,
name|__sync_fetch_and_sub_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_1_c
argument_list|,
name|__sync_fetch_and_or_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_2_c
argument_list|,
name|__sync_fetch_and_or_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_4_c
argument_list|,
name|__sync_fetch_and_or_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_1_c
argument_list|,
name|__sync_fetch_and_xor_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_2_c
argument_list|,
name|__sync_fetch_and_xor_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_4_c
argument_list|,
name|__sync_fetch_and_xor_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_ARCH_5__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SMP
end_ifdef

begin_error
error|#
directive|error
literal|"On SMP systems we should have proper atomic operations."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On uniprocessor systems, we can perform the atomic operations by  * disabling interrupts.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_VAL_COMPARE_AND_SWAP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|uintN_t									\ __sync_val_compare_and_swap_##N(uintN_t *mem, uintN_t expected,		\     uintN_t desired)							\ {									\ 	uintN_t ret;							\ 									\ 	WITHOUT_INTERRUPTS({						\ 		ret = *mem;						\ 		if (*mem == expected)					\ 			*mem = desired;					\ 	});								\ 	return (ret);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_FETCH_AND_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uintN_t									\ __sync_##name##_##N(uintN_t *mem, uintN_t val)				\ {									\ 	uintN_t ret;							\ 									\ 	WITHOUT_INTERRUPTS({						\ 		ret = *mem;						\ 		*mem op val;						\ 	});								\ 	return (ret);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_ALL_OPS_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|)
define|\
value|EMIT_VAL_COMPARE_AND_SWAP_N(N, uintN_t)					\ EMIT_FETCH_AND_OP_N(N, uintN_t, lock_test_and_set, =)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, fetch_and_add, +=)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, fetch_and_and,&=)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, fetch_and_or, |=)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, fetch_and_sub, -=)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, fetch_and_xor, ^=)
end_define

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|EMIT_ALL_OPS_N
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_comment
comment|/*  * For userspace on uniprocessor systems, we can implement the atomic  * operations by using a Restartable Atomic Sequence. This makes the  * kernel restart the code from the beginning when interrupted.  */
end_comment

begin_define
define|#
directive|define
name|EMIT_LOCK_TEST_AND_SET_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|)
define|\
value|uintN_t									\ __sync_lock_test_and_set_##N##_c(uintN_t *mem, uintN_t val)			\ {									\ 	uint32_t old, temp, ras_start;					\ 									\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%5]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%5, #4]\n"				\ 									\ 		"\t"ldr" %0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"str" %3, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%5]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%5, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem), "r" (ras_start));		\ 	return (old);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_VAL_COMPARE_AND_SWAP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|streq
parameter_list|)
define|\
value|uintN_t									\ __sync_val_compare_and_swap_##N##_c(uintN_t *mem, uintN_t expected,		\     uintN_t desired)							\ {									\ 	uint32_t old, temp, ras_start;					\ 									\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%6]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%6, #4]\n"				\ 									\ 		"\t"ldr" %0, %5\n"
comment|/* Load old value. */
value|\ 		"\tcmp   %0, %3\n"
comment|/* Compare to expected value. */
value|\ 		"\t"streq" %4, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%6]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%6, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (expected), "r" (desired), "m" (*mem),		\ 		  "r" (ras_start));					\ 	return (old);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_FETCH_AND_OP_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|,
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uintN_t									\ __sync_##name##_##N##_c(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t old, temp, ras_start;					\ 									\ 	ras_start = ARM_RAS_START;					\ 	__asm volatile (						\
comment|/* Set up Restartable Atomic Sequence. */
value|\ 		"1:"							\ 		"\tadr   %2, 1b\n"					\ 		"\tstr   %2, [%5]\n"					\ 		"\tadr   %2, 2f\n"					\ 		"\tstr   %2, [%5, #4]\n"				\ 									\ 		"\t"ldr" %0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"  %2, %0, %3\n"
comment|/* Calculate new value. */
value|\ 		"\t"str" %2, %1\n"
comment|/* Store new value. */
value|\ 									\
comment|/* Tear down Restartable Atomic Sequence. */
value|\ 		"2:"							\ 		"\tmov   %2, #0x00000000\n"				\ 		"\tstr   %2, [%5]\n"					\ 		"\tmov   %2, #0xffffffff\n"				\ 		"\tstr   %2, [%5, #4]\n"				\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem), "r" (ras_start));		\ 	return (old);							\ }
end_define

begin_define
define|#
directive|define
name|EMIT_ALL_OPS_N
parameter_list|(
name|N
parameter_list|,
name|uintN_t
parameter_list|,
name|ldr
parameter_list|,
name|str
parameter_list|,
name|streq
parameter_list|)
define|\
value|EMIT_LOCK_TEST_AND_SET_N(N, uintN_t, ldr, str)				\ EMIT_VAL_COMPARE_AND_SWAP_N(N, uintN_t, ldr, streq)			\ EMIT_FETCH_AND_OP_N(N, uintN_t, ldr, str, fetch_and_add, "add")		\ EMIT_FETCH_AND_OP_N(N, uintN_t, ldr, str, fetch_and_and, "and")		\ EMIT_FETCH_AND_OP_N(N, uintN_t, ldr, str, fetch_and_or, "orr")		\ EMIT_FETCH_AND_OP_N(N, uintN_t, ldr, str, fetch_and_sub, "sub")		\ EMIT_FETCH_AND_OP_N(N, uintN_t, ldr, str, fetch_and_xor, "eor")
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__clang__
end_ifdef

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
literal|"ldrb"
argument_list|,
literal|"strb"
argument_list|,
literal|"strbeq"
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
literal|"ldrh"
argument_list|,
literal|"strh"
argument_list|,
literal|"strheq"
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|,
literal|"ldrb"
argument_list|,
literal|"strb"
argument_list|,
literal|"streqb"
argument_list|)
end_macro

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|,
literal|"ldrh"
argument_list|,
literal|"strh"
argument_list|,
literal|"streqh"
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|EMIT_ALL_OPS_N
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|,
literal|"ldr"
argument_list|,
literal|"str"
argument_list|,
literal|"streq"
argument_list|)
end_macro

begin_ifndef
ifndef|#
directive|ifndef
name|__clang__
end_ifndef

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_1_c
argument_list|,
name|__sync_lock_test_and_set_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_2_c
argument_list|,
name|__sync_lock_test_and_set_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_lock_test_and_set_4_c
argument_list|,
name|__sync_lock_test_and_set_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_1_c
argument_list|,
name|__sync_val_compare_and_swap_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_2_c
argument_list|,
name|__sync_val_compare_and_swap_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_val_compare_and_swap_4_c
argument_list|,
name|__sync_val_compare_and_swap_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_1_c
argument_list|,
name|__sync_fetch_and_add_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_2_c
argument_list|,
name|__sync_fetch_and_add_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_add_4_c
argument_list|,
name|__sync_fetch_and_add_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_1_c
argument_list|,
name|__sync_fetch_and_and_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_2_c
argument_list|,
name|__sync_fetch_and_and_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_and_4_c
argument_list|,
name|__sync_fetch_and_and_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_1_c
argument_list|,
name|__sync_fetch_and_sub_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_2_c
argument_list|,
name|__sync_fetch_and_sub_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_sub_4_c
argument_list|,
name|__sync_fetch_and_sub_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_1_c
argument_list|,
name|__sync_fetch_and_or_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_2_c
argument_list|,
name|__sync_fetch_and_or_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_or_4_c
argument_list|,
name|__sync_fetch_and_or_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_1_c
argument_list|,
name|__sync_fetch_and_xor_1
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_2_c
argument_list|,
name|__sync_fetch_and_xor_2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__strong_reference
argument_list|(
name|__sync_fetch_and_xor_4_c
argument_list|,
name|__sync_fetch_and_xor_4
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYNC_ATOMICS */
end_comment

end_unit

