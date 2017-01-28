begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: atomic.h,v 1.1 2002/10/19 12:22:34 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (C) 2003-2004 Olivier Houchard  * Copyright (C) 1994-1997 Mark Brinicombe  * Copyright (C) 1994 Brini  * All rights reserved.  *  * This code is derived from software written for Brini by Mark Brinicombe  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Brini.  * 4. The name of Brini may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BRINI ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL BRINI BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_V6_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_V6_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_error
error|#
directive|error
error|Do not include this file directly, use<machine/atomic.h>
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
end_if

begin_define
define|#
directive|define
name|isb
parameter_list|()
value|__asm __volatile("isb" : : : "memory")
end_define

begin_define
define|#
directive|define
name|dsb
parameter_list|()
value|__asm __volatile("dsb" : : : "memory")
end_define

begin_define
define|#
directive|define
name|dmb
parameter_list|()
value|__asm __volatile("dmb" : : : "memory")
end_define

begin_elif
elif|#
directive|elif
name|__ARM_ARCH
operator|>=
literal|6
end_elif

begin_define
define|#
directive|define
name|isb
parameter_list|()
value|__asm __volatile("mcr p15, 0, %0, c7, c5, 4" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|dsb
parameter_list|()
value|__asm __volatile("mcr p15, 0, %0, c7, c10, 4" : : "r" (0) : "memory")
end_define

begin_define
define|#
directive|define
name|dmb
parameter_list|()
value|__asm __volatile("mcr p15, 0, %0, c7, c10, 5" : : "r" (0) : "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Only use this file with ARMv6 and later
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|dmb()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|dmb()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|dmb()
end_define

begin_define
define|#
directive|define
name|ARM_HAVE_ATOMIC64
end_define

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL_LONG
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static __inline void							\ atomic_##NAME##_acq_long(__volatile u_long *p, u_long v)		\ {									\ 	atomic_##NAME##_long(p, v);					\ 	dmb();								\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_long(__volatile u_long *p, u_long v)		\ {									\ 	dmb();								\ 	atomic_##NAME##_long(p, v);					\ }
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
value|static __inline  void							\ atomic_##NAME##_acq_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	dmb();								\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	dmb();								\ 	atomic_##NAME##_##WIDTH(p, v);					\ }
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
name|uint32_t
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%2]	\n"
literal|"   add	%0, %0, %3	\n"
literal|"   strex	%1, %0, [%2]	\n"
literal|"   cmp	%1, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|uint64_t
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   adds	%Q[tmp], %Q[val]			\n"
literal|"   adc	%R[tmp], %R[tmp], %R[val]		\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_add_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|val
parameter_list|)
block|{
name|atomic_add_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|add
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|add
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|void
name|atomic_clear_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|address
parameter_list|,
name|uint32_t
name|setmask
parameter_list|)
block|{
name|uint32_t
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%2]	\n"
literal|"   bic	%0, %0, %3	\n"
literal|"   strex	%1, %0, [%2]	\n"
literal|"   cmp	%1, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|address
operator|)
operator|,
literal|"+r"
operator|(
name|setmask
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
name|uint64_t
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   bic	%Q[tmp], %Q[val]			\n"
literal|"   bic	%R[tmp], %R[val]			\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_clear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|address
parameter_list|,
name|u_long
name|setmask
parameter_list|)
block|{
name|atomic_clear_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|address
argument_list|,
name|setmask
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|clear
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|clear
argument_list|)
end_macro

begin_function
specifier|static
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
name|uint32_t
name|_cmpval
init|=
operator|*
name|cmpval
decl_stmt|;
name|int
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"1: mov 	%0, #1		\n"
literal|"   ldrex	%1, [%2]	\n"
literal|"   cmp	%1, %3		\n"
literal|"   it	eq		\n"
literal|"   strexeq	%0, %4, [%2]	\n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|_cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_expr_stmt
operator|*
name|cmpval
operator|=
name|tmp
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
operator|!
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|uint64_t
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
name|uint64_t
name|_cmpval
init|=
operator|*
name|cmpval
decl_stmt|;
name|int
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"1:	mov	%[ret], #1				\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   teq	%Q[tmp], %Q[_cmpval]			\n"
literal|"   itee	eq					\n"
literal|"   teqeq	%R[tmp], %R[_cmpval]			\n"
literal|"   bne	2f					\n"
literal|"   strexd	%[ret], %Q[newval], %R[newval], [%[ptr]]\n"
literal|"2:							\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|_cmpval
index|]
literal|"r"
operator|(
name|_cmpval
operator|)
operator|,
index|[
name|newval
index|]
literal|"r"
operator|(
name|newval
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_expr_stmt
operator|*
name|cmpval
operator|=
name|tmp
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
operator|!
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|u_long
name|atomic_fcmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
modifier|*
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
return|return
operator|(
name|atomic_fcmpset_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
operator|(
name|uint32_t
operator|*
operator|)
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
name|uint64_t
name|ret
decl_stmt|;
name|ret
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
name|dmb
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
name|u_long
name|atomic_fcmpset_acq_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
modifier|*
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|u_long
name|ret
decl_stmt|;
name|ret
operator|=
name|atomic_fcmpset_long
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|dmb
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
name|uint32_t
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
name|uint32_t
name|ret
decl_stmt|;
name|ret
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
name|dmb
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
name|uint32_t
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
name|dmb
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
name|uint64_t
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
name|dmb
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
name|u_long
name|atomic_fcmpset_rel_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
modifier|*
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|dmb
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_fcmpset_long
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
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%1]	\n"
literal|"   cmp	%0, %2		\n"
literal|"   itt	ne		\n"
literal|"   movne	%0, #0		\n"
literal|"   bne	2f		\n"
literal|"   strex	%0, %3, [%1]	\n"
literal|"   cmp	%0, #0		\n"
literal|"   ite	eq		\n"
literal|"   moveq	%0, #1		\n"
literal|"   bne	1b		\n"
literal|"2:"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|cmpval
operator|)
operator|,
literal|"+r"
operator|(
name|newval
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   teq	%Q[tmp], %Q[cmpval]			\n"
literal|"   itee	eq					\n"
literal|"   teqeq	%R[tmp], %R[cmpval]			\n"
literal|"   movne	%[ret], #0				\n"
literal|"   bne	2f					\n"
literal|"   strexd	%[ret], %Q[newval], %R[newval], [%[ptr]]\n"
literal|"   teq	%[ret], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
literal|"   mov	%[ret], #1				\n"
literal|"2:							\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|cmpval
index|]
literal|"r"
operator|(
name|cmpval
operator|)
operator|,
index|[
name|newval
index|]
literal|"r"
operator|(
name|newval
operator|)
operator|:
literal|"cc"
operator|,
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
name|u_long
name|atomic_cmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
return|return
operator|(
name|atomic_cmpset_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
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
name|atomic_cmpset_acq_32
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
name|ret
decl_stmt|;
name|ret
operator|=
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|dmb
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
name|uint64_t
name|atomic_cmpset_acq_64
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
name|ret
decl_stmt|;
name|ret
operator|=
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|dmb
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
name|u_long
name|atomic_cmpset_acq_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|u_long
name|ret
decl_stmt|;
name|ret
operator|=
name|atomic_cmpset_long
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
expr_stmt|;
name|dmb
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
name|uint32_t
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
name|dmb
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
name|uint64_t
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
name|dmb
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
name|u_long
name|atomic_cmpset_rel_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|cmpval
parameter_list|,
name|u_long
name|newval
parameter_list|)
block|{
name|dmb
argument_list|()
expr_stmt|;
return|return
operator|(
name|atomic_cmpset_long
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
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|,
name|ret
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%3]	\n"
literal|"   add	%1, %0, %4	\n"
literal|"   strex	%2, %1, [%3]	\n"
literal|"   cmp	%2, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"+r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
decl_stmt|,
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   adds	%Q[tmp], %Q[ret], %Q[val]		\n"
literal|"   adc	%R[tmp], %R[ret], %R[val]		\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
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
name|u_long
name|atomic_fetchadd_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|val
parameter_list|)
block|{
return|return
operator|(
name|atomic_fetchadd_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
name|val
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
name|v
decl_stmt|;
name|v
operator|=
operator|*
name|p
expr_stmt|;
name|dmb
argument_list|()
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|atomic_load_64
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
comment|/* 	 * The only way to atomically load 64 bits is with LDREXD which puts the 	 * exclusive monitor into the exclusive state, so reset it to open state 	 * with CLREX because we don't actually need to store anything. 	 */
asm|__asm __volatile(
literal|"ldrexd	%Q[ret], %R[ret], [%[ptr]]	\n"
literal|"clrex					\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"cc"
operator|,
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
name|atomic_load_64
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|dmb
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
name|u_long
name|atomic_load_acq_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|)
block|{
name|u_long
name|v
decl_stmt|;
name|v
operator|=
operator|*
name|p
expr_stmt|;
name|dmb
argument_list|()
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
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
decl_stmt|,
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%3]	\n"
literal|"   mov	%1, #0		\n"
literal|"   strex	%2, %1, [%3]	\n"
literal|"   cmp	%2, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"=r"
operator|(
name|ret
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
decl_stmt|,
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[ret], %R[ret], [%[ptr]]		\n"
literal|"   mov	%Q[tmp], #0				\n"
literal|"   mov	%R[tmp], #0				\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"cc"
operator|,
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
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|atomic_readandclear_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|address
parameter_list|,
name|uint32_t
name|setmask
parameter_list|)
block|{
name|uint32_t
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%2]	\n"
literal|"   orr	%0, %0, %3	\n"
literal|"   strex	%1, %0, [%2]	\n"
literal|"   cmp	%1, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|address
operator|)
operator|,
literal|"+r"
operator|(
name|setmask
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
name|uint64_t
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   orr	%Q[tmp], %Q[val]			\n"
literal|"   orr	%R[tmp], %R[val]			\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_set_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|address
parameter_list|,
name|u_long
name|setmask
parameter_list|)
block|{
name|atomic_set_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|address
argument_list|,
name|setmask
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|set
argument_list|)
end_macro

begin_function
specifier|static
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
name|uint32_t
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%0, [%2]	\n"
literal|"   sub	%0, %0, %3	\n"
literal|"   strex	%1, %0, [%2]	\n"
literal|"   cmp	%1, #0		\n"
literal|"   it	ne		\n"
literal|"   bne	1b		\n"
operator|:
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"+r"
operator|(
name|tmp2
operator|)
operator|,
literal|"+r"
operator|(
name|p
operator|)
operator|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
operator|,
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
name|uint64_t
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   subs	%Q[tmp], %Q[val]			\n"
literal|"   sbc	%R[tmp], %R[tmp], %R[val]		\n"
literal|"   strexd	%[exf], %Q[tmp], %R[tmp], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|,
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|atomic_subtract_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|val
parameter_list|)
block|{
name|atomic_subtract_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL
argument_list|(
argument|subtract
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|subtract
argument_list|)
end_macro

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_64
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
name|tmp
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
comment|/* 	 * The only way to atomically store 64 bits is with STREXD, which will 	 * succeed only if paired up with a preceeding LDREXD using the same 	 * address, so we read and discard the existing value before storing. 	 */
asm|__asm __volatile(
literal|"1:							\n"
literal|"   ldrexd	%Q[tmp], %R[tmp], [%[ptr]]		\n"
literal|"   strexd	%[exf], %Q[val], %R[val], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|tmp
index|]
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|:
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|,
index|[
name|val
index|]
literal|"r"
operator|(
name|val
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_function
unit|}  static
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
name|v
parameter_list|)
block|{
name|dmb
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|v
expr_stmt|;
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
name|dmb
argument_list|()
expr_stmt|;
name|atomic_store_64
argument_list|(
name|p
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_rel_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|v
parameter_list|)
block|{
name|dmb
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_testandset_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
name|uint32_t
name|tmp
decl_stmt|,
name|tmp2
decl_stmt|,
name|res
decl_stmt|,
name|mask
decl_stmt|;
name|mask
operator|=
literal|1u
operator|<<
operator|(
name|v
operator|&
literal|0x1f
operator|)
expr_stmt|;
name|tmp
operator|=
name|tmp2
operator|=
literal|0
expr_stmt|;
asm|__asm __volatile(
literal|"1:	ldrex	%0, [%4]	\n"
literal|"	orr	%1, %0, %3	\n"
literal|"	strex	%2, %1, [%4]	\n"
literal|"	cmp	%2, #0		\n"
literal|"	it	ne		\n"
literal|"	bne	1b		\n"
operator|:
literal|"=&r"
operator|(
name|res
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp
operator|)
operator|,
literal|"=&r"
operator|(
name|tmp2
operator|)
operator|:
literal|"r"
operator|(
name|mask
operator|)
operator|,
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"cc"
operator|,
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
operator|(
name|res
operator|&
name|mask
operator|)
operator|!=
literal|0
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|int
name|atomic_testandset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_testandset_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_testandset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
return|return
operator|(
name|atomic_testandset_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_testandset_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|u_int
name|v
parameter_list|)
block|{
specifier|volatile
name|uint32_t
modifier|*
name|p32
decl_stmt|;
name|p32
operator|=
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
expr_stmt|;
comment|/* Assume little-endian */
if|if
condition|(
name|v
operator|>=
literal|32
condition|)
block|{
name|v
operator|&=
literal|0x1f
expr_stmt|;
name|p32
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|atomic_testandset_32
argument_list|(
name|p32
argument_list|,
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
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
name|v
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|,
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrex	%[ret], [%[ptr]]		\n"
literal|"   strex	%[exf], %[val], [%[ptr]]	\n"
literal|"   teq	%[exf], #0			\n"
literal|"   it	ne				\n"
literal|"   bne	1b				\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|:
index|[
name|val
index|]
literal|"r"
operator|(
name|v
operator|)
operator|,
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"cc"
operator|,
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
name|atomic_swap_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|p
parameter_list|,
name|uint64_t
name|v
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
name|uint32_t
name|exflag
decl_stmt|;
asm|__asm __volatile(
literal|"1: ldrexd	%Q[ret], %R[ret], [%[ptr]]		\n"
literal|"   strexd	%[exf], %Q[val], %R[val], [%[ptr]]	\n"
literal|"   teq	%[exf], #0				\n"
literal|"   it	ne					\n"
literal|"   bne	1b					\n"
operator|:
index|[
name|ret
index|]
literal|"=&r"
operator|(
name|ret
operator|)
operator|,
index|[
name|exf
index|]
literal|"=&r"
operator|(
name|exflag
operator|)
operator|:
index|[
name|val
index|]
literal|"r"
operator|(
name|v
operator|)
operator|,
index|[
name|ptr
index|]
literal|"r"
operator|(
name|p
operator|)
operator|:
literal|"cc"
operator|,
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

begin_undef
unit|}
undef|#
directive|undef
name|ATOMIC_ACQ_REL
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_ACQ_REL_LONG
end_undef

begin_function
unit|static
name|__inline
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
block|{
name|dmb
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
name|dmb
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
name|dmb
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
name|dmb
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_V6_H_ */
end_comment

end_unit

