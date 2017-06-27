begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_define
define|#
directive|define
name|fence
parameter_list|()
value|__asm __volatile("fence" ::: "memory");
end_define

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|fence()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|fence()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|fence()
end_define

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL
parameter_list|(
name|NAME
parameter_list|,
name|WIDTH
parameter_list|)
define|\
value|static __inline  void							\ atomic_##NAME##_acq_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	fence(); 							\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	fence();							\ 	atomic_##NAME##_##WIDTH(p, v);					\ }
end_define

begin_function
specifier|static
name|__inline
name|void
name|atomic_add_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoadd.w zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
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
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoadd.w zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
operator|-
name|val
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
name|atomic_set_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoor.w zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
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
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoand.w zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
operator|~
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
name|res
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"0:"
literal|"li   %1, 1\n"
comment|/* Preset to fail */
literal|"lr.w %0, %2\n"
literal|"bne  %0, %z3, 1f\n"
literal|"sc.w %1, %z4, %2\n"
literal|"bnez %1, 0b\n"
literal|"1:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"rJ"
operator|(
name|cmpval
operator|)
operator|,
literal|"rJ"
operator|(
name|newval
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|atomic_fcmpset_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
modifier|*
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
name|res
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"0:"
literal|"li   %1, 1\n"
comment|/* Preset to fail */
literal|"lr.w %0, %2\n"
comment|/* Load old value */
literal|"bne  %0, %z4, 1f\n"
comment|/* Compare */
literal|"sc.w %1, %z5, %2\n"
comment|/* Try to store new value */
literal|"j 2f\n"
literal|"1:"
literal|"sw   %0, %3\n"
comment|/* Save old value */
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|cmpval
operator|)
operator|:
literal|"rJ"
operator|(
operator|*
name|cmpval
operator|)
operator|,
literal|"rJ"
operator|(
name|newval
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile("amoadd.w %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|uint32_t
name|val
decl_stmt|;
name|val
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile("amoswap.w %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|atomic_add_int
value|atomic_add_32
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
name|atomic_cmpset_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_int
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_int
value|atomic_fetchadd_32
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
name|atomic_set_int
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_expr_stmt
unit|ATOMIC_ACQ_REL
operator|(
name|set
operator|,
literal|32
operator|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|32
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|32
argument_list|)
specifier|static
name|__inline
name|int
name|atomic_cmpset_acq_32
argument_list|(
argument|volatile uint32_t *p
argument_list|,
argument|uint32_t cmpval
argument_list|,
argument|uint32_t newval
argument_list|)
block|{
name|int
name|res
block|;
name|res
operator|=
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
block|;
name|fence
argument_list|()
block|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_fcmpset_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
modifier|*
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|res
operator|=
name|atomic_fcmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_fcmpset_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
modifier|*
name|cmpval
parameter_list|,
name|uint32_t
name|newval
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_fcmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_load_acq_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
name|ret
operator|=
operator|*
name|p
expr_stmt|;
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_int
value|atomic_fcmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_int
value|atomic_set_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_add_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_int
value|atomic_fcmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_rel_32
end_define

begin_function
specifier|static
name|__inline
name|void
name|atomic_add_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoadd.d zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
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
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoadd.d zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
operator|-
name|val
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
name|atomic_set_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoor.d zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
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
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
asm|__asm __volatile("amoand.d zero, %1, %0"
block|:
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
operator|~
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|int
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
name|res
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"0:"
literal|"li   %1, 1\n"
comment|/* Preset to fail */
literal|"lr.d %0, %2\n"
literal|"bne  %0, %z3, 1f\n"
literal|"sc.d %1, %z4, %2\n"
literal|"bnez %1, 0b\n"
literal|"1:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"rJ"
operator|(
name|cmpval
operator|)
operator|,
literal|"rJ"
operator|(
name|newval
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|atomic_fcmpset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
modifier|*
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|int
name|res
decl_stmt|;
name|res
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"0:"
literal|"li   %1, 1\n"
comment|/* Preset to fail */
literal|"lr.d %0, %2\n"
comment|/* Load old value */
literal|"bne  %0, %z4, 1f\n"
comment|/* Compare */
literal|"sc.d %1, %z5, %2\n"
comment|/* Try to store new value */
literal|"j 2f\n"
literal|"1:"
literal|"sd   %0, %3\n"
comment|/* Save old value */
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|cmpval
operator|)
operator|:
literal|"rJ"
operator|(
operator|*
name|cmpval
operator|)
operator|,
literal|"rJ"
operator|(
name|newval
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|!
name|res
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_fetchadd_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
asm|__asm __volatile("amoadd.d %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_readandclear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
name|val
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile("amoswap.d %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint32_t
name|atomic_swap_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|uint32_t
name|old
decl_stmt|;
asm|__asm __volatile("amoswap.w %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
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

begin_function
unit|}  static
name|__inline
name|uint64_t
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|old
decl_stmt|;
asm|__asm __volatile("amoswap.d %0, %2, %1"
block|:
literal|"=&r"
operator|(
name|old
operator|)
operator|,
literal|"+A"
operator|(
operator|*
name|p
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"memory"
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
name|atomic_add_long
value|atomic_add_64
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
name|atomic_cmpset_long
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_long
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_long
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_long
value|atomic_readandclear_64
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
name|atomic_subtract_long
value|atomic_subtract_64
end_define

begin_define
define|#
directive|define
name|atomic_add_ptr
value|atomic_add_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_ptr
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fetchadd_ptr
value|atomic_fetchadd_64
end_define

begin_define
define|#
directive|define
name|atomic_readandclear_ptr
value|atomic_readandclear_64
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_ptr
value|atomic_subtract_64
end_define

begin_expr_stmt
unit|ATOMIC_ACQ_REL
operator|(
name|set
operator|,
literal|64
operator|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|64
argument_list|)
specifier|static
name|__inline
name|int
name|atomic_cmpset_acq_64
argument_list|(
argument|volatile uint64_t *p
argument_list|,
argument|uint64_t cmpval
argument_list|,
argument|uint64_t newval
argument_list|)
block|{
name|int
name|res
block|;
name|res
operator|=
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
block|;
name|fence
argument_list|()
block|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_fcmpset_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
modifier|*
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|res
operator|=
name|atomic_fcmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|res
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_fcmpset_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
modifier|*
name|cmpval
parameter_list|,
name|uint64_t
name|newval
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_fcmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_load_acq_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|ret
operator|=
operator|*
name|p
expr_stmt|;
name|fence
argument_list|()
expr_stmt|;
return|return
operator|(
name|ret
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|val
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_long
value|atomic_fcmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_ptr
value|atomic_add_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_ptr
value|atomic_fcmpset_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_ptr
value|atomic_load_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_ptr
value|atomic_set_acq_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_ptr
value|atomic_subtract_acq_64
end_define

begin_undef
undef|#
directive|undef
name|ATOMIC_ACQ_REL
end_undef

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_acq_rel
parameter_list|(
name|void
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_seq_cst
parameter_list|(
name|void
parameter_list|)
block|{
name|fence
argument_list|()
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_long
value|atomic_fcmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_ptr
value|atomic_add_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_ptr
value|atomic_clear_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_ptr
value|atomic_fcmpset_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_ptr
value|atomic_set_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_ptr
value|atomic_subtract_rel_64
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

