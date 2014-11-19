begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
file|<sys/stdatomic.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__SYNC_ATOMICS
argument_list|)
end_if

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
asm|__asm volatile (
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|SMP
argument_list|)
literal|".set noreorder\n"
literal|"\tsync\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|"\tnop\n"
literal|".set reorder\n"
else|#
directive|else
comment|/* _KERNEL&& !SMP */
literal|""
endif|#
directive|endif
comment|/* !KERNEL || SMP */
operator|:
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_union
unit|}  typedef
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
union|;
end_union

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
value|uintN_t									\ __sync_lock_test_and_set_##N(uintN_t *mem, uintN_t val)			\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, negmask, old;					\ 	uint32_t temp;							\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	negmask.v32 = 0xffffffff;					\ 	put_##N(&negmask, mem, 0);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %5\n"
comment|/* Load old value. */
value|\ 		"\tand	%2, %4, %0\n"
comment|/* Remove the old value. */
value|\ 		"\tor	%2, %3\n"
comment|/* Put in the new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp)		\ 		: "r" (val32.v32), "r" (negmask.v32), "m" (*mem32));	\ 	return (get_##N(&old, mem));					\ }
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
value|uintN_t									\ __sync_val_compare_and_swap_##N(uintN_t *mem, uintN_t expected,		\     uintN_t desired)							\ {									\ 	uint32_t *mem32;						\ 	reg_t expected32, desired32, posmask, old;			\ 	uint32_t negmask, temp;						\ 									\ 	mem32 = round_to_word(mem);					\ 	expected32.v32 = 0x00000000;					\ 	put_##N(&expected32, mem, expected);				\ 	desired32.v32 = 0x00000000;					\ 	put_##N(&desired32, mem, desired);				\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask = ~posmask.v32;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %7\n"
comment|/* Load old value. */
value|\ 		"\tand	%2, %5, %0\n"
comment|/* Isolate the old value. */
value|\ 		"\tbne	%2, %3, 2f\n"
comment|/* Compare to expected value. */
value|\ 		"\tand	%2, %6, %0\n"
comment|/* Remove the old value. */
value|\ 		"\tor	%2, %4\n"
comment|/* Put in the new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		"2:"							\ 		: "=&r" (old), "=m" (*mem32), "=&r" (temp)		\ 		: "r" (expected32.v32), "r" (desired32.v32),		\ 		  "r" (posmask.v32), "r" (negmask), "m" (*mem32));	\ 	return (get_##N(&old, mem));					\ }
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
value|uintN_t									\ __sync_##name##_##N(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, posmask, old;					\ 	uint32_t negmask, temp1, temp2;					\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = 0x00000000;						\ 	put_##N(&val32, mem, val);					\ 	posmask.v32 = 0x00000000;					\ 	put_##N(&posmask, mem, ~0);					\ 	negmask = ~posmask.v32;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %7\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %0, %4\n"
comment|/* Calculate new value. */
value|\ 		"\tand	%2, %5\n"
comment|/* Isolate the new value. */
value|\ 		"\tand	%3, %6, %0\n"
comment|/* Remove the old value. */
value|\ 		"\tor	%2, %3\n"
comment|/* Put in the new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
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
literal|"addu"
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
literal|"subu"
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
literal|"addu"
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
literal|"subu"
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
value|uintN_t									\ __sync_##name##_##N(uintN_t *mem, uintN_t val)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, old;						\ 	uint32_t temp;							\ 									\ 	mem32 = round_to_word(mem);					\ 	val32.v32 = idempotence ? 0xffffffff : 0x00000000;		\ 	put_##N(&val32, mem, val);					\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %3, %0\n"
comment|/* Calculate new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp)		\ 		: "r" (val32.v32), "m" (*mem32));			\ 	return (get_##N(&old, mem));					\ }
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
literal|"or"
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
literal|"xor"
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
literal|"or"
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
literal|"xor"
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
name|temp
decl_stmt|;
name|do_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tll	%0, %5\n"
comment|/* Load old value. */
literal|"\tbne	%0, %3, 2f\n"
comment|/* Compare to expected value. */
literal|"\tmove	%2, %4\n"
comment|/* Value to store. */
literal|"\tsc	%2, %1\n"
comment|/* Attempt to store. */
literal|"\tbeqz	%2, 1b\n"
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
value|uint32_t								\ __sync_##name##_4(uint32_t *mem, uint32_t val)				\ {									\ 	uint32_t old, temp;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"\n"
comment|/* Calculate new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem));				\ 	return (old);							\ }
end_define

begin_expr_stmt
unit|EMIT_FETCH_AND_OP_4
operator|(
name|lock_test_and_set
operator|,
literal|"move %2, %3"
operator|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_add
argument_list|,
literal|"addu %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"or %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"subu %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_4
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"xor %2, %0, %3"
argument_list|)
comment|/*  * 64-bit routines.  *  * Note: All the 64-bit atomic operations are only atomic when running  * in 64-bit mode. It is assumed that code compiled for n32 and n64 fits  * into this definition and no further safeties are needed.  */
if|#
directive|if
name|defined
argument_list|(
name|__mips_n32
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips_n64
argument_list|)
name|uint64_t
name|__sync_val_compare_and_swap_8
argument_list|(
argument|uint64_t *mem
argument_list|,
argument|uint64_t expected
argument_list|,
argument|uint64_t desired
argument_list|)
block|{
name|uint64_t
name|old
block|,
name|temp
block|;
name|do_sync
argument_list|()
block|;
asm|__asm volatile (
literal|"1:"
literal|"\tlld	%0, %5\n"
comment|/* Load old value. */
literal|"\tbne	%0, %3, 2f\n"
comment|/* Compare to expected value. */
literal|"\tmove	%2, %4\n"
comment|/* Value to store. */
literal|"\tscd	%2, %1\n"
comment|/* Attempt to store. */
literal|"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|old
operator|)
block|,
literal|"=m"
operator|(
operator|*
name|mem
operator|)
block|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|expected
operator|)
block|,
literal|"r"
operator|(
name|desired
operator|)
block|,
literal|"m"
operator|(
operator|*
name|mem
operator|)
block|)
expr_stmt|;
end_expr_stmt

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
name|EMIT_FETCH_AND_OP_8
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uint64_t								\ __sync_##name##_8(uint64_t *mem, uint64_t val)				\ {									\ 	uint64_t old, temp;						\ 									\ 	do_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tlld	%0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"\n"
comment|/* Calculate new value. */
value|\ 		"\tscd	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old), "=m" (*mem), "=&r" (temp)		\ 		: "r" (val), "m" (*mem));				\ 	return (old);							\ }
end_define

begin_expr_stmt
unit|EMIT_FETCH_AND_OP_8
operator|(
name|lock_test_and_set
operator|,
literal|"move %2, %3"
operator|)
name|EMIT_FETCH_AND_OP_8
argument_list|(
argument|fetch_and_add
argument_list|,
literal|"daddu %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_8
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_8
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"or %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_8
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"dsubu %2, %0, %3"
argument_list|)
name|EMIT_FETCH_AND_OP_8
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"xor %2, %0, %3"
argument_list|)
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __mips_n32 || __mips_n64 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __SYNC_ATOMICS */
end_comment

end_unit

