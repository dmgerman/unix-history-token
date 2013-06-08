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
file|<sys/types.h>
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
comment|/*  * Memory barriers.  *  * It turns out __sync_synchronize() does not emit any code when used  * with GCC 4.2. Implement our own version that does work reliably.  *  * Although __sync_lock_test_and_set() should only perform an acquire  * barrier, make it do a full barrier like the other functions. This  * should make<stdatomic.h>'s atomic_exchange_explicit() work reliably.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|mips_sync
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
name|uint16_t
name|v16
index|[
literal|2
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
comment|/*  * 8-bit routines.  */
end_comment

begin_function
name|uint8_t
name|__sync_lock_test_and_set_1
parameter_list|(
name|uint8_t
modifier|*
name|mem8
parameter_list|,
name|uint8_t
name|val8
parameter_list|)
block|{
name|uint32_t
modifier|*
name|mem32
decl_stmt|;
name|reg_t
name|val32
decl_stmt|,
name|negmask32
decl_stmt|,
name|old
decl_stmt|;
name|uint32_t
name|temp
decl_stmt|;
name|mem32
operator|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
operator|~
literal|3
operator|)
expr_stmt|;
name|val32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|val32
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|=
name|val8
expr_stmt|;
name|negmask32
operator|.
name|v32
operator|=
literal|0xffffffff
expr_stmt|;
name|negmask32
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|=
literal|0x00
expr_stmt|;
name|mips_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tll	%0, %5\n"
comment|/* Load old value. */
literal|"\tand	%2, %4, %0\n"
comment|/* Trim out affected part. */
literal|"\tor	%2, %3\n"
comment|/* Put in the new value. */
literal|"\tsc	%2, %1\n"
comment|/* Attempt to store. */
literal|"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
operator|:
literal|"=&r"
operator|(
name|old
operator|.
name|v32
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|mem32
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|val32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|negmask32
operator|.
name|v32
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|mem32
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|old
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|)
return|;
end_return

begin_macro
unit|}  uint8_t
name|__sync_val_compare_and_swap_1
argument_list|(
argument|uint8_t *mem8
argument_list|,
argument|uint8_t expected
argument_list|,
argument|uint8_t desired
argument_list|)
end_macro

begin_block
block|{
name|uint32_t
modifier|*
name|mem32
decl_stmt|;
name|reg_t
name|expected32
decl_stmt|,
name|desired32
decl_stmt|,
name|posmask32
decl_stmt|,
name|negmask32
decl_stmt|,
name|old
decl_stmt|;
name|uint32_t
name|temp
decl_stmt|;
name|mem32
operator|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
operator|~
literal|3
operator|)
expr_stmt|;
name|expected32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|expected32
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|=
name|expected
expr_stmt|;
name|desired32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|desired32
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|=
name|desired
expr_stmt|;
name|posmask32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|posmask32
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|=
literal|0xff
expr_stmt|;
name|negmask32
operator|.
name|v32
operator|=
operator|~
name|posmask32
operator|.
name|v32
expr_stmt|;
name|mips_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tll	%0, %7\n"
comment|/* Load old value. */
literal|"\tand	%2, %5, %0\n"
comment|/* Isolate affected part. */
literal|"\tbne	%2, %3, 2f\n"
comment|/* Compare to expected value. */
literal|"\tand	%2, %6, %0\n"
comment|/* Trim out affected part. */
literal|"\tor	%2, %4\n"
comment|/* Put in the new value. */
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
name|mem32
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|expected32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|desired32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|posmask32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|negmask32
operator|.
name|v32
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|mem32
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
operator|.
name|v8
index|[
operator|(
name|intptr_t
operator|)
name|mem8
operator|&
literal|3
index|]
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|EMIT_ARITHMETIC_FETCH_AND_OP_1
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uint8_t									\ __sync_##name##_1(uint8_t *mem8, uint8_t val8)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, posmask32, negmask32, old;				\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = (uint32_t *)((intptr_t)mem8& ~3);			\ 	val32.v32 = 0x00000000;						\ 	val32.v8[(intptr_t)mem8& 3] = val8;				\ 	posmask32.v32 = 0x00000000;					\ 	posmask32.v8[(intptr_t)mem8& 3] = 0xff;			\ 	negmask32.v32 = ~posmask32.v32;					\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %7\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %0, %4\n"
comment|/* Calculate new value. */
value|\ 		"\tand	%2, %5\n"
comment|/* Isolate affected part. */
value|\ 		"\tand	%3, %6, %0\n"
comment|/* Trim out affected part. */
value|\ 		"\tor	%2, %3\n"
comment|/* Put in the new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "r" (posmask32.v32),			\ 		  "r" (negmask32.v32), "m" (*mem32));			\ 	return (old.v8[(intptr_t)mem8& 3]);				\ }
end_define

begin_expr_stmt
unit|EMIT_ARITHMETIC_FETCH_AND_OP_1
operator|(
name|fetch_and_add
operator|,
literal|"addu"
operator|)
name|EMIT_ARITHMETIC_FETCH_AND_OP_1
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"subu"
argument_list|)
define|#
directive|define
name|EMIT_BITWISE_FETCH_AND_OP_1
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|,
name|idempotence
parameter_list|)
define|\
value|uint8_t									\ __sync_##name##_1(uint8_t *mem8, uint8_t val8)				\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, old;						\ 	uint32_t temp;							\ 									\ 	mem32 = (uint32_t *)((intptr_t)mem8& ~3);			\ 	val32.v32 = idempotence ? 0xffffffff : 0x00000000;		\ 	val32.v8[(intptr_t)mem8& 3] = val8;				\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %3, %0\n"
comment|/* Calculate new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp)		\ 		: "r" (val32.v32), "m" (*mem32));			\ 	return (old.v8[(intptr_t)mem8& 3]);				\ }
name|EMIT_BITWISE_FETCH_AND_OP_1
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and"
argument_list|,
literal|1
argument_list|)
name|EMIT_BITWISE_FETCH_AND_OP_1
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"or"
argument_list|,
literal|0
argument_list|)
name|EMIT_BITWISE_FETCH_AND_OP_1
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"xor"
argument_list|,
literal|0
argument_list|)
comment|/*  * 16-bit routines.  */
name|uint16_t
name|__sync_lock_test_and_set_2
argument_list|(
argument|uint16_t *mem16
argument_list|,
argument|uint16_t val16
argument_list|)
block|{
name|uint32_t
operator|*
name|mem32
block|;
name|reg_t
name|val32
block|,
name|negmask32
block|,
name|old
block|;
name|uint32_t
name|temp
block|;
name|mem32
operator|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
operator|~
literal|1
operator|)
block|;
name|val32
operator|.
name|v32
operator|=
literal|0x00000000
block|;
name|val32
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|=
name|val16
block|;
name|negmask32
operator|.
name|v32
operator|=
literal|0xffffffff
block|;
name|negmask32
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|=
literal|0x0000
block|;
name|mips_sync
argument_list|()
block|;
asm|__asm volatile (
literal|"1:"
literal|"\tll	%0, %5\n"
comment|/* Load old value. */
literal|"\tand	%2, %4, %0\n"
comment|/* Trim out affected part. */
literal|"\tor	%2, %3\n"
comment|/* Combine to new value. */
literal|"\tsc	%2, %1\n"
comment|/* Attempt to store. */
literal|"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
operator|:
literal|"=&r"
operator|(
name|old
operator|.
name|v32
operator|)
block|,
literal|"=m"
operator|(
operator|*
name|mem32
operator|)
block|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|val32
operator|.
name|v32
operator|)
block|,
literal|"r"
operator|(
name|negmask32
operator|.
name|v32
operator|)
block|,
literal|"m"
operator|(
operator|*
name|mem32
operator|)
block|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
name|old
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|)
return|;
end_return

begin_macro
unit|}  uint16_t
name|__sync_val_compare_and_swap_2
argument_list|(
argument|uint16_t *mem16
argument_list|,
argument|uint16_t expected
argument_list|,
argument|uint16_t desired
argument_list|)
end_macro

begin_block
block|{
name|uint32_t
modifier|*
name|mem32
decl_stmt|;
name|reg_t
name|expected32
decl_stmt|,
name|desired32
decl_stmt|,
name|posmask32
decl_stmt|,
name|negmask32
decl_stmt|,
name|old
decl_stmt|;
name|uint32_t
name|temp
decl_stmt|;
name|mem32
operator|=
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
operator|~
literal|1
operator|)
expr_stmt|;
name|expected32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|expected32
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|=
name|expected
expr_stmt|;
name|desired32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|desired32
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|=
name|desired
expr_stmt|;
name|posmask32
operator|.
name|v32
operator|=
literal|0x00000000
expr_stmt|;
name|posmask32
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|=
literal|0xffff
expr_stmt|;
name|negmask32
operator|.
name|v32
operator|=
operator|~
name|posmask32
operator|.
name|v32
expr_stmt|;
name|mips_sync
argument_list|()
expr_stmt|;
asm|__asm volatile (
literal|"1:"
literal|"\tll	%0, %7\n"
comment|/* Load old value. */
literal|"\tand	%2, %5, %0\n"
comment|/* Isolate affected part. */
literal|"\tbne	%2, %3, 2f\n"
comment|/* Compare to expected value. */
literal|"\tand	%2, %6, %0\n"
comment|/* Trim out affected part. */
literal|"\tor	%2, %4\n"
comment|/* Put in the new value. */
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
name|mem32
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|:
literal|"r"
operator|(
name|expected32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|desired32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|posmask32
operator|.
name|v32
operator|)
operator|,
literal|"r"
operator|(
name|negmask32
operator|.
name|v32
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|mem32
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
operator|.
name|v16
index|[
operator|(
name|intptr_t
operator|)
name|mem16
operator|&
literal|1
index|]
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|EMIT_ARITHMETIC_FETCH_AND_OP_2
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uint16_t								\ __sync_##name##_2(uint16_t *mem16, uint16_t val16)			\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, posmask32, negmask32, old;				\ 	uint32_t temp1, temp2;						\ 									\ 	mem32 = (uint32_t *)((intptr_t)mem16& ~3);			\ 	val32.v32 = 0x00000000;						\ 	val32.v16[(intptr_t)mem16& 1] = val16;				\ 	posmask32.v32 = 0x00000000;					\ 	posmask32.v16[(intptr_t)mem16& 1] = 0xffff;			\ 	negmask32.v32 = ~posmask32.v32;					\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %7\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %0, %4\n"
comment|/* Calculate new value. */
value|\ 		"\tand	%2, %5\n"
comment|/* Isolate affected part. */
value|\ 		"\tand	%3, %6, %0\n"
comment|/* Trim out affected part. */
value|\ 		"\tor	%2, %3\n"
comment|/* Combine to new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp1),	\ 		  "=&r" (temp2)						\ 		: "r" (val32.v32), "r" (posmask32.v32),			\ 		  "r" (negmask32.v32), "m" (*mem32));			\ 	return (old.v16[(intptr_t)mem16& 1]);				\ }
end_define

begin_expr_stmt
unit|EMIT_ARITHMETIC_FETCH_AND_OP_2
operator|(
name|fetch_and_add
operator|,
literal|"addu"
operator|)
name|EMIT_ARITHMETIC_FETCH_AND_OP_2
argument_list|(
argument|fetch_and_sub
argument_list|,
literal|"subu"
argument_list|)
define|#
directive|define
name|EMIT_BITWISE_FETCH_AND_OP_2
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|,
name|idempotence
parameter_list|)
define|\
value|uint16_t								\ __sync_##name##_2(uint16_t *mem16, uint16_t val16)			\ {									\ 	uint32_t *mem32;						\ 	reg_t val32, old;						\ 	uint32_t temp;							\ 									\ 	mem32 = (uint32_t *)((intptr_t)mem16& ~1);			\ 	val32.v32 = idempotence ? 0xffffffff : 0x00000000;		\ 	val32.v16[(intptr_t)mem16& 1] = val16;				\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %4\n"
comment|/* Load old value. */
value|\ 		"\t"op"	%2, %3, %0\n"
comment|/* Calculate new value. */
value|\ 		"\tsc	%2, %1\n"
comment|/* Attempt to store. */
value|\ 		"\tbeqz	%2, 1b\n"
comment|/* Spin if failed. */
value|\ 		: "=&r" (old.v32), "=m" (*mem32), "=&r" (temp)		\ 		: "r" (val32.v32), "m" (*mem32));			\ 	return (old.v16[(intptr_t)mem16& 1]);				\ }
name|EMIT_BITWISE_FETCH_AND_OP_2
argument_list|(
argument|fetch_and_and
argument_list|,
literal|"and"
argument_list|,
literal|1
argument_list|)
name|EMIT_BITWISE_FETCH_AND_OP_2
argument_list|(
argument|fetch_and_or
argument_list|,
literal|"or"
argument_list|,
literal|0
argument_list|)
name|EMIT_BITWISE_FETCH_AND_OP_2
argument_list|(
argument|fetch_and_xor
argument_list|,
literal|"xor"
argument_list|,
literal|0
argument_list|)
comment|/*  * 32-bit routines.  */
name|uint32_t
name|__sync_val_compare_and_swap_4
argument_list|(
argument|uint32_t *mem
argument_list|,
argument|uint32_t expected
argument_list|,
argument|uint32_t desired
argument_list|)
block|{
name|uint32_t
name|old
block|,
name|temp
block|;
name|mips_sync
argument_list|()
block|;
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
name|EMIT_FETCH_AND_OP_4
parameter_list|(
name|name
parameter_list|,
name|op
parameter_list|)
define|\
value|uint32_t								\ __sync_##name##_4(uint32_t *mem, uint32_t val)				\ {									\ 	uint32_t old, temp;						\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tll	%0, %4\n"
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
name|mips_sync
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
value|uint64_t								\ __sync_##name##_8(uint64_t *mem, uint64_t val)				\ {									\ 	uint64_t old, temp;						\ 									\ 	mips_sync();							\ 	__asm volatile (						\ 		"1:"							\ 		"\tlld	%0, %4\n"
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

end_unit

