begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts and SMP safe.  */
end_comment

begin_function_decl
name|void
name|atomic_set_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_8
parameter_list|(
specifier|volatile
name|u_int8_t
modifier|*
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_set_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_clear_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_add_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atomic_subtract_16
parameter_list|(
specifier|volatile
name|u_int16_t
modifier|*
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldl_l %0, %2\n\t"
comment|/* load old value */
literal|"bis %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stl_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldl_l %0, %2\n\t"
comment|/* load old value */
literal|"bic %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stl_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_add_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldl_l %0, %2\n\t"
comment|/* load old value */
literal|"addl %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stl_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|v
parameter_list|)
block|{
name|u_int32_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldl_l %0, %2\n\t"
comment|/* load old value */
literal|"subl %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stl_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|u_int32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|addr
parameter_list|)
block|{
name|u_int32_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"wmb\n"
comment|/* ensure pending writes have drained */
literal|"1:\tldl_l %0,%3\n\t"
comment|/* load current value, asserting lock */
literal|"ldiq %1,0\n\t"
comment|/* value to store */
literal|"stl_c %1,%2\n\t"
comment|/* attempt to store */
literal|"beq %1,2f\n\t"
comment|/* if the store failed, spin */
literal|"br 3f\n"
comment|/* it worked, exit */
literal|"2:\tbr 1b\n"
comment|/* *addr not updated, loop */
literal|"3:\tmb\n"
comment|/* it worked */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
name|u_int64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldq_l %0, %2\n\t"
comment|/* load old value */
literal|"bis %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stq_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
name|u_int64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldq_l %0, %2\n\t"
comment|/* load old value */
literal|"bic %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stq_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_add_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
name|u_int64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldq_l %0, %2\n\t"
comment|/* load old value */
literal|"addq %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stq_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
name|u_int64_t
name|v
parameter_list|)
block|{
name|u_int64_t
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldq_l %0, %2\n\t"
comment|/* load old value */
literal|"subq %0, %3, %0\n\t"
comment|/* calculate new value */
literal|"stq_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 2f\n\t"
comment|/* spin if failed */
literal|"mb\n\t"
comment|/* drain to memory */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"2:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"r"
operator|(
name|v
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|u_int64_t
name|atomic_readandclear_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|addr
parameter_list|)
block|{
name|u_int64_t
name|result
decl_stmt|,
name|temp
decl_stmt|;
asm|__asm __volatile (
literal|"wmb\n"
comment|/* ensure pending writes have drained */
literal|"1:\tldq_l %0,%3\n\t"
comment|/* load current value, asserting lock */
literal|"ldiq %1,0\n\t"
comment|/* value to store */
literal|"stq_c %1,%2\n\t"
comment|/* attempt to store */
literal|"beq %1,2f\n\t"
comment|/* if the store failed, spin */
literal|"br 3f\n"
comment|/* it worked, exit */
literal|"2:\tbr 1b\n"
comment|/* *addr not updated, loop */
literal|"3:\tmb\n"
comment|/* it worked */
operator|:
literal|"=&r"
operator|(
name|result
operator|)
operator|,
literal|"=&r"
operator|(
name|temp
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"m"
operator|(
operator|*
name|addr
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|result
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_set_char
value|atomic_set_8
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
value|atomic_clear_8
end_define

begin_define
define|#
directive|define
name|atomic_add_char
value|atomic_add_8
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
value|atomic_subtract_8
end_define

begin_define
define|#
directive|define
name|atomic_set_short
value|atomic_set_16
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
value|atomic_clear_16
end_define

begin_define
define|#
directive|define
name|atomic_add_short
value|atomic_add_16
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
value|atomic_subtract_16
end_define

begin_define
define|#
directive|define
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_int
value|atomic_readandclear_32
end_define

begin_define
define|#
directive|define
name|atomic_set_long
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_add_long
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_64
end_define

begin_comment
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
unit|static
name|__inline
name|u_int32_t
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|cmpval
parameter_list|,
name|u_int32_t
name|newval
parameter_list|)
block|{
name|u_int32_t
name|ret
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldl_l %0, %4\n\t"
comment|/* load old value */
literal|"cmpeq %0, %2, %0\n\t"
comment|/* compare */
literal|"beq %0, 2f\n\t"
comment|/* exit if not equal */
literal|"mov %3, %0\n\t"
comment|/* value to store */
literal|"stl_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 3f\n\t"
comment|/* if it failed, spin */
literal|"2:\n"
comment|/* done */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"3:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|cmpval
operator|)
operator|,
literal|"r"
operator|(
name|newval
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|ret
return|;
end_return

begin_comment
unit|}
comment|/*  * Atomically compare the value stored at *p with cmpval and if the  * two values are equal, update the value of *p with newval. Returns  * zero if the compare failed, nonzero otherwise.  */
end_comment

begin_function
unit|static
name|__inline
name|u_int64_t
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
name|u_int64_t
name|cmpval
parameter_list|,
name|u_int64_t
name|newval
parameter_list|)
block|{
name|u_int64_t
name|ret
decl_stmt|;
asm|__asm __volatile (
literal|"1:\tldq_l %0, %4\n\t"
comment|/* load old value */
literal|"cmpeq %0, %2, %0\n\t"
comment|/* compare */
literal|"beq %0, 2f\n\t"
comment|/* exit if not equal */
literal|"mov %3, %0\n\t"
comment|/* value to store */
literal|"stq_c %0, %1\n\t"
comment|/* attempt to store */
literal|"beq %0, 3f\n\t"
comment|/* if it failed, spin */
literal|"2:\n"
comment|/* done */
literal|".section .text3,\"ax\"\n"
comment|/* improve branch prediction */
literal|"3:\tbr 1b\n"
comment|/* try again */
literal|".previous\n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|cmpval
operator|)
operator|,
literal|"r"
operator|(
name|newval
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
name|ret
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_long
value|atomic_cmpset_64
end_define

begin_function
unit|static
name|__inline
name|int
name|atomic_cmpset_ptr
parameter_list|(
specifier|volatile
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|exp
parameter_list|,
name|void
modifier|*
name|src
parameter_list|)
block|{
return|return
operator|(
name|atomic_cmpset_long
argument_list|(
operator|(
specifier|volatile
name|u_long
operator|*
operator|)
name|dst
argument_list|,
operator|(
name|u_long
operator|)
name|exp
argument_list|,
operator|(
name|u_long
operator|)
name|src
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

