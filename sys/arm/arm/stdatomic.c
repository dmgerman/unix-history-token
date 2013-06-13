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

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

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
comment|/* !SMP */
end_comment

begin_comment
comment|/*  * Memory barriers.  *  * It turns out __sync_synchronize() does not emit any code when used  * with GCC 4.2. Implement our own version that does work reliably.  *  * Although __sync_lock_test_and_set() should only perform an acquire  * barrier, make it do a full barrier like the other functions. This  * should make<stdatomic.h>'s atomic_exchange_explicit() work reliably.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|do_sync
parameter_list|(
name|void
parameter_list|)
block|{
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
asm|__asm volatile ("" : : : "memory");
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
asm|__asm volatile ("dmb" : : : "memory");
else|#
directive|else
comment|/* __ARM_ARCH_6__ */
asm|__asm volatile ("mcr p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory");
endif|#
directive|endif
block|}
end_function

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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_elif

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
block|{
name|do_sync
argument_list|()
expr_stmt|;
block|}
end_function

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

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__ARM_ARCH_6__&& !__ARM_ARCH_7__&& !_KERNEL */
end_comment

begin_comment
comment|/* XXX: Implement intrinsics for ARMv5 userspace. */
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

begin_comment
comment|/*  * Old __sync_* API.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SYNC_ATOMICS
argument_list|)
end_if

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
value|uintN_t									\ __sync_lock_test_and_set_##N(uintN_t *mem, uintN_t val)			\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, negmask, old;					\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	negmask.v32 = 0xffffffff;					\ 	put_##N(&negmask, mem, 0);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %6\n"
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
value|uintN_t									\ __sync_val_compare_and_swap_##N(uintN_t *mem, uintN_t expected,		\     uintN_t desired)							\ {									\ 	uint32_t *mem32;						\ 	reg_t expected32, desired32, posmask, negmask, old;		\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	expected32.v32 = 0x00000000;					\ 	put_##N(&expected32, mem, expected);				\ 	desired32.v32 = 0x00000000;					\ 	put_##N(&desired32, mem, desired);				\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask.v32 = ~posmask.v32;					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %8\n"
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
value|\ 		"2:"							\ 		: "=&r" (old), "=m" (*mem32), "=&r" (temp1),		\ 		  "=&r" (temp2)						\ 		: "r" (expected32.v32), "r" (desired32.v32),		\ 		  "r" (posmask.v32), "r" (negmask.v32), "m" (*mem32));	\ 	return (get_##N(&old, mem));					\ }
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
value|uintN_t									\ __sync_##name##_##N(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, posmask, negmask, old;				\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask.v32 = ~posmask.v32;					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %7\n"
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
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "r" (posmask.v32),			\ 		  "r" (negmask.v32), "m" (*mem32));			\ 	return (get_##N(&old, mem));					\ }
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
value|uintN_t									\ __sync_##name##_##N(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, old;						\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = idempotence ? 0xffffffff : 0x00000000;		\ 	put_##N(&val32, mem, val);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %5\n"
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
name|__sync_val_compare_and_swap_4
parameter_list|(
name|uint32_t
modifier|*
name|mem
parameter_list|,
name|uint32_t
name|expected
parameter_list|,
name|uint32_t
name|desired
parameter_list|)
block|{
name|uint32_t
name|old
decl_stmt|,
name|temp1
decl_stmt|,
name|temp2
decl_stmt|;
name|do_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tldrex %0, %6\n"
comment|/* Load old value. */
literal|"\tcmp   %0, %4\n"
comment|/* Compare to expected value. */
literal|"\tbne   2f\n"
comment|/* Values are unequal. */
literal|"\tmov   %2, %5\n"
comment|/* Value to store. */
literal|"\tstrex %3, %2, %1\n"
comment|/* Attempt to store. */
literal|"\tcmp   %3, #0\n"
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
name|temp1
operator|)
operator|,
literal|"=&r"
operator|(
name|temp2
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
function|;
end_function

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
value|uint32_t								\ __sync_##name##_4(uint32_t *mem, uint32_t val)				\ {									\ 	uint32_t old, temp1, temp2;					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tldrex %0, %5\n"
comment|/* Load old value. */
value|\ 		"\t"op"\n"
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
name|lock_test_and_set
operator|,
literal|"mov %2, %4"
operator|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_add
argument_list|,
literal|"add %2, %0, %4"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and %2, %0, %4"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"orr %2, %0, %4"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"sub %2, %0, %4"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"eor %2, %0, %4"
argument_list|)
elif|#
directive|elif
name|defined
argument_list|(
name|_KERNEL
argument_list|)
ifdef|#
directive|ifdef
name|SMP
error|#
directive|error
literal|"On SMP systems we should have proper atomic operations."
endif|#
directive|endif
comment|/*  * On uniprocessor systems, we can perform the atomic operations by  * disabling interrupts.  */
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
name|EMIT_ALL_OPS_N
argument_list|(
literal|1
argument_list|,
argument|uint8_t
argument_list|)
name|EMIT_ALL_OPS_N
argument_list|(
literal|2
argument_list|,
argument|uint16_t
argument_list|)
name|EMIT_ALL_OPS_N
argument_list|(
literal|4
argument_list|,
argument|uint32_t
argument_list|)
name|EMIT_ALL_OPS_N
argument_list|(
literal|8
argument_list|,
argument|uint64_t
argument_list|)
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__ARM_ARCH_6__&& !__ARM_ARCH_7__&& !_KERNEL */
end_comment

begin_comment
comment|/* XXX: Implement intrinsics for ARMv5 userspace. */
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

