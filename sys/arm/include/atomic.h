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
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<machine/cpuconf.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
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
name|__ARM_ARCH_6T2__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6Z__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_6ZK__
argument_list|)
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
value|dsb()
end_define

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

begin_comment
comment|/*  * It would be nice to use _HAVE_ARMv6_INSTRUCTIONS from machine/asm.h  * here, but that header can't be included here because this is C  * code.  I would like to move the _HAVE_ARMv6_INSTRUCTIONS definition  * out of asm.h so it can be used in both asm and C code. - kientzle@  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6__
argument_list|)
operator|||
expr|\
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
expr|\
name|defined
argument_list|(
name|__ARM_ARCH_6T2__
argument_list|)
operator|||
expr|\
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
end_if

begin_define
define|#
directive|define
name|ARM_HAVE_ATOMIC64
end_define

begin_function
specifier|static
name|__inline
name|void
name|__do_dmb
parameter_list|(
name|void
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__ARM_ARCH_7__
argument_list|)
operator|||
name|defined
argument_list|(
name|__ARM_ARCH_7A__
argument_list|)
asm|__asm __volatile("dmb" : : : "memory");
else|#
directive|else
asm|__asm __volatile("mcr p15, 0, r0, c7, c10, 5" : : : "memory");
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|ATOMIC_ACQ_REL_LONG
parameter_list|(
name|NAME
parameter_list|)
define|\
value|static __inline void							\ atomic_##NAME##_acq_long(__volatile u_long *p, u_long v)		\ {									\ 	atomic_##NAME##_long(p, v);					\ 	__do_dmb();							\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_long(__volatile u_long *p, u_long v)		\ {									\ 	__do_dmb();							\ 	atomic_##NAME##_long(p, v);					\ }
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
value|static __inline  void							\ atomic_##NAME##_acq_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	atomic_##NAME##_##WIDTH(p, v);					\ 	__do_dmb();							\ }									\ 									\ static __inline  void							\ atomic_##NAME##_rel_##WIDTH(__volatile uint##WIDTH##_t *p, uint##WIDTH##_t v)\ {									\ 	__do_dmb();							\ 	atomic_##NAME##_##WIDTH(p, v);					\ }
end_define

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
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"orr %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   orr      %Q[tmp], %Q[val]\n"
literal|"   orr      %R[tmp], %R[val]\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
name|u_long
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"orr %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"bic %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   bic      %Q[tmp], %Q[val]\n"
literal|"   bic      %R[tmp], %R[val]\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
name|u_long
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"bic %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
name|u_int32_t
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%1]\n"
literal|"cmp %0, %2\n"
literal|"itt ne\n"
literal|"movne %0, #0\n"
literal|"bne 2f\n"
literal|"strex %0, %3, [%1]\n"
literal|"cmp %0, #0\n"
literal|"ite eq\n"
literal|"moveq %0, #1\n"
literal|"bne	1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   teq      %Q[tmp], %Q[cmpval]\n"
literal|"   itee eq  \n"
literal|"   teqeq    %R[tmp], %R[cmpval]\n"
literal|"   movne    %[ret], #0\n"
literal|"   bne      2f\n"
literal|"   strexd   %[ret], %[newval], [%[ptr]]\n"
literal|"   teq      %[ret], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
literal|"   mov      %[ret], #1\n"
literal|"2:          \n"
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
specifier|volatile
name|u_long
name|cmpval
parameter_list|,
specifier|volatile
name|u_long
name|newval
parameter_list|)
block|{
name|u_long
name|ret
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%1]\n"
literal|"cmp %0, %2\n"
literal|"itt ne\n"
literal|"movne %0, #0\n"
literal|"bne 2f\n"
literal|"strex %0, %3, [%1]\n"
literal|"cmp %0, #0\n"
literal|"ite eq\n"
literal|"moveq %0, #1\n"
literal|"bne	1b\n"
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
name|u_int32_t
name|atomic_cmpset_acq_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
name|u_int32_t
name|ret
init|=
name|atomic_cmpset_32
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
decl_stmt|;
name|__do_dmb
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
specifier|volatile
name|uint64_t
name|cmpval
parameter_list|,
specifier|volatile
name|uint64_t
name|newval
parameter_list|)
block|{
name|uint64_t
name|ret
init|=
name|atomic_cmpset_64
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
decl_stmt|;
name|__do_dmb
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
specifier|volatile
name|u_long
name|cmpval
parameter_list|,
specifier|volatile
name|u_long
name|newval
parameter_list|)
block|{
name|u_long
name|ret
init|=
name|atomic_cmpset_long
argument_list|(
name|p
argument_list|,
name|cmpval
argument_list|,
name|newval
argument_list|)
decl_stmt|;
name|__do_dmb
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
name|u_int32_t
name|atomic_cmpset_rel_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
name|__do_dmb
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
specifier|volatile
name|uint64_t
name|cmpval
parameter_list|,
specifier|volatile
name|uint64_t
name|newval
parameter_list|)
block|{
name|__do_dmb
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
specifier|volatile
name|u_long
name|cmpval
parameter_list|,
specifier|volatile
name|u_long
name|newval
parameter_list|)
block|{
name|__do_dmb
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
name|void
name|atomic_add_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
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
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"add %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   adds     %Q[tmp], %Q[val]\n"
literal|"   adc      %R[tmp], %R[val]\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
name|u_long
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"add %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
name|atomic_subtract_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
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
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"sub %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   subs     %Q[tmp], %Q[val]\n"
literal|"   sbc      %R[tmp], %R[val]\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
name|u_long
name|tmp
init|=
literal|0
decl_stmt|,
name|tmp2
init|=
literal|0
decl_stmt|;
asm|__asm __volatile("1: ldrex %0, [%2]\n"
literal|"sub %0, %0, %3\n"
literal|"strex %1, %0, [%2]\n"
literal|"cmp %1, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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

begin_expr_stmt
unit|}  ATOMIC_ACQ_REL
operator|(
name|clear
operator|,
literal|32
operator|)
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
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|32
argument_list|)
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
name|ATOMIC_ACQ_REL
argument_list|(
argument|set
argument_list|,
literal|64
argument_list|)
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|clear
argument_list|)
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|add
argument_list|)
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|subtract
argument_list|)
name|ATOMIC_ACQ_REL_LONG
argument_list|(
argument|set
argument_list|)
undef|#
directive|undef
name|ATOMIC_ACQ_REL
undef|#
directive|undef
name|ATOMIC_ACQ_REL_LONG
specifier|static
name|__inline
name|uint32_t
name|atomic_fetchadd_32
argument_list|(
argument|volatile uint32_t *p
argument_list|,
argument|uint32_t val
argument_list|)
block|{
name|uint32_t
name|tmp
operator|=
literal|0
block|,
name|tmp2
operator|=
literal|0
block|,
name|ret
operator|=
literal|0
block|;
asm|__asm __volatile("1: ldrex %0, [%3]\n"
literal|"add %1, %0, %4\n"
literal|"strex %2, %1, [%3]\n"
literal|"cmp %2, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
operator|:
literal|"+r"
operator|(
name|ret
operator|)
block|,
literal|"=&r"
operator|(
name|tmp
operator|)
block|,
literal|"+r"
operator|(
name|tmp2
operator|)
block|,
literal|"+r"
operator|(
name|p
operator|)
block|,
literal|"+r"
operator|(
name|val
operator|)
operator|:
operator|:
literal|"cc"
block|,
literal|"memory"
block|)
expr_stmt|;
end_expr_stmt

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
name|u_int32_t
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
asm|__asm __volatile("1: ldrex %0, [%3]\n"
literal|"mov %1, #0\n"
literal|"strex %2, %1, [%3]\n"
literal|"cmp %2, #0\n"
literal|"it ne\n"
literal|"bne 1b\n"
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
name|__do_dmb
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
name|__do_dmb
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
literal|"1:          \n"
literal|"   ldrexd   %[ret], [%[ptr]]\n"
literal|"   adds     %Q[tmp], %Q[ret], %Q[val]\n"
literal|"   adc      %R[tmp], %R[ret], %R[val]\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
literal|"1:          \n"
literal|"   ldrexd   %[ret], [%[ptr]]\n"
literal|"   mov      %Q[tmp], #0\n"
literal|"   mov      %R[tmp], #0\n"
literal|"   strexd   %[exf], %[tmp], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
comment|/* 	 * The only way to atomically load 64 bits is with LDREXD which puts the 	 * exclusive monitor into the open state, so reset it with CLREX because 	 * we don't actually need to store anything. 	 */
asm|__asm __volatile(
literal|"1:          \n"
literal|"   ldrexd   %[ret], [%[ptr]]\n"
literal|"   clrex    \n"
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
name|__do_dmb
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
literal|"1:          \n"
literal|"   ldrexd   %[tmp], [%[ptr]]\n"
literal|"   strexd   %[exf], %[val], [%[ptr]]\n"
literal|"   teq      %[exf], #0\n"
literal|"   it ne    \n"
literal|"   bne      1b\n"
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
name|__do_dmb
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
name|u_long
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
asm|__asm __volatile("1: ldrex %0, [%3]\n"
literal|"add %1, %0, %4\n"
literal|"strex %2, %1, [%3]\n"
literal|"cmp %2, #0\n"
literal|"it ne\n"
literal|"bne	1b\n"
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
name|u_long
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|)
block|{
name|u_long
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
asm|__asm __volatile("1: ldrex %0, [%3]\n"
literal|"mov %1, #0\n"
literal|"strex %2, %1, [%3]\n"
literal|"cmp %2, #0\n"
literal|"it ne\n"
literal|"bne 1b\n"
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
name|__do_dmb
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
name|__do_dmb
argument_list|()
expr_stmt|;
operator|*
name|p
operator|=
name|v
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*< armv6 */
end_comment

begin_define
define|#
directive|define
name|__with_interrupts_disabled
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {						\ 		u_int cpsr_save, tmp;			\ 							\ 		__asm __volatile(			\ 			"mrs  %0, cpsr;"		\ 			"orr  %1, %0, %2;"		\ 			"msr  cpsr_fsxc, %1;"		\ 			: "=r" (cpsr_save), "=r" (tmp)	\ 			: "I" (PSR_I | PSR_F)		\ 		        : "cc" );		\ 		(expr);				\ 		 __asm __volatile(		\ 			"msr  cpsr_fsxc, %0"	\ 			:
comment|/* no output */
value|\ 			: "r" (cpsr_save)	\ 			: "cc" );		\ 	} while(0)
end_define

begin_function
specifier|static
name|__inline
name|uint32_t
name|__swp
parameter_list|(
name|uint32_t
name|val
parameter_list|,
specifier|volatile
name|uint32_t
modifier|*
name|ptr
parameter_list|)
block|{
asm|__asm __volatile("swp	%0, %2, [%3]"
block|:
literal|"=&r"
operator|(
name|val
operator|)
operator|,
literal|"=m"
operator|(
operator|*
name|ptr
operator|)
operator|:
literal|"r"
operator|(
name|val
operator|)
operator|,
literal|"r"
operator|(
name|ptr
operator|)
operator|,
literal|"m"
operator|(
operator|*
name|ptr
operator|)
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|val
operator|)
return|;
end_return

begin_ifdef
unit|}
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|ARM_HAVE_ATOMIC64
end_define

begin_function
unit|static
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
name|__with_interrupts_disabled
argument_list|(
operator|*
name|address
operator||=
name|setmask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|address
parameter_list|,
name|uint64_t
name|setmask
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|address
operator||=
name|setmask
argument_list|)
expr_stmt|;
block|}
end_function

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
name|clearmask
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|address
operator|&=
operator|~
name|clearmask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_clear_64
parameter_list|(
specifier|volatile
name|uint64_t
modifier|*
name|address
parameter_list|,
name|uint64_t
name|clearmask
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|address
operator|&=
operator|~
name|clearmask
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	    	if (*p == cmpval) { 			*p = newval; 			ret =
literal|1
argument|; 		} else { 			ret =
literal|0
argument|; 		} 	}
argument_list|)
empty_stmt|;
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
name|u_int64_t
name|atomic_cmpset_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int64_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int64_t
name|newval
parameter_list|)
block|{
name|int
name|ret
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	    	if (*p == cmpval) { 			*p = newval; 			ret =
literal|1
argument|; 		} else { 			ret =
literal|0
argument|; 		} 	}
argument_list|)
empty_stmt|;
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
name|atomic_add_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|p
operator|+=
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
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
name|val
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|p
operator|+=
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
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
name|val
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|p
operator|-=
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
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
name|val
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|p
operator|-=
name|val
argument_list|)
expr_stmt|;
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
name|v
parameter_list|)
block|{
name|uint32_t
name|value
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	    	value = *p; 		*p += v; 	}
argument_list|)
empty_stmt|;
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

begin_function
specifier|static
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
name|v
parameter_list|)
block|{
name|uint64_t
name|value
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	    	value = *p; 		*p += v; 	}
argument_list|)
empty_stmt|;
return|return
operator|(
name|value
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
name|value
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
name|value
operator|=
operator|*
name|p
argument_list|)
expr_stmt|;
return|return
operator|(
name|value
operator|)
return|;
block|}
end_function

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
name|value
parameter_list|)
block|{
name|__with_interrupts_disabled
argument_list|(
operator|*
name|p
operator|=
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_function
specifier|static
name|__inline
name|u_int32_t
name|atomic_cmpset_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
specifier|register
name|int
name|done
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%2]\n"
literal|"cmp	%1, %3\n"
literal|"streq	%4, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"mov	%1, #0xffffffff\n"
literal|"str	%1, [%0, #4]\n"
literal|"moveq	%1, #1\n"
literal|"movne	%1, #0\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|done
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
name|done
operator|)
return|;
end_return

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
name|val
parameter_list|)
block|{
name|int
name|start
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%2]\n"
literal|"add	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"mov	%1, #0xffffffff\n"
literal|"str	%1, [%0, #4]\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|start
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
name|val
parameter_list|)
block|{
name|int
name|start
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%2]\n"
literal|"sub	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"mov	%1, #0xffffffff\n"
literal|"str	%1, [%0, #4]\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|start
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
name|address
parameter_list|,
name|uint32_t
name|setmask
parameter_list|)
block|{
name|int
name|start
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%2]\n"
literal|"orr	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"mov	%1, #0xffffffff\n"
literal|"str	%1, [%0, #4]\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|start
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
name|address
parameter_list|,
name|uint32_t
name|clearmask
parameter_list|)
block|{
name|int
name|start
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%2]\n"
literal|"bic	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"mov	%1, #0xffffffff\n"
literal|"str	%1, [%0, #4]\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|start
operator|)
operator|,
literal|"+r"
operator|(
name|address
operator|)
operator|,
literal|"+r"
operator|(
name|clearmask
operator|)
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

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
name|v
parameter_list|)
block|{
name|uint32_t
name|start
decl_stmt|,
name|tmp
decl_stmt|,
name|ras_start
init|=
name|ARM_RAS_START
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"adr	%1, 1b\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0, #4]\n"
literal|"ldr	%1, [%3]\n"
literal|"mov	%2, %1\n"
literal|"add	%2, %2, %4\n"
literal|"str	%2, [%3]\n"
literal|"2:\n"
literal|"mov	%2, #0\n"
literal|"str	%2, [%0]\n"
literal|"mov	%2, #0xffffffff\n"
literal|"str	%2, [%0, #4]\n"
operator|:
literal|"+r"
operator|(
name|ras_start
operator|)
operator|,
literal|"=r"
operator|(
name|start
operator|)
operator|,
literal|"=r"
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
name|v
operator|)
operator|:
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|start
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_function
unit|static
name|__inline
name|uint32_t
name|atomic_readandclear_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
name|__swp
argument_list|(
literal|0
argument_list|,
name|p
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_cmpset_rel_32
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_32
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_32
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_32
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_32
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_32
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_32
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_32
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_32
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_32
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_32
value|atomic_store_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_long
value|atomic_store_long
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_32
value|atomic_load_32
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_long
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_long
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_add_rel_long
value|atomic_add_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_long
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_long
value|atomic_subtract_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_acq_long
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_long
value|atomic_clear_long
end_define

begin_define
define|#
directive|define
name|atomic_set_acq_long
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_set_rel_long
value|atomic_set_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_long
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_long
value|atomic_cmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_long
value|atomic_load_long
end_define

begin_undef
undef|#
directive|undef
name|__with_interrupts_disabled
end_undef

begin_function
specifier|static
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
name|v
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
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_clear_long
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
name|atomic_clear_32
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
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
name|old
parameter_list|,
name|u_long
name|newe
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
name|dst
argument_list|,
name|old
argument_list|,
name|newe
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
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
name|v
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
name|v
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_readandclear_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|p
parameter_list|)
block|{
name|atomic_readandclear_32
argument_list|(
operator|(
specifier|volatile
name|uint32_t
operator|*
operator|)
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_set_long
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
name|atomic_set_32
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
expr_stmt|;
block|}
end_function

begin_function
specifier|static
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
name|v
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
name|v
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Arch>= v6 */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_load_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|v
parameter_list|)
block|{
return|return
operator|(
operator|*
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_32
parameter_list|(
specifier|volatile
name|uint32_t
modifier|*
name|dst
parameter_list|,
name|uint32_t
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|atomic_load_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|v
parameter_list|)
block|{
return|return
operator|(
operator|*
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|atomic_store_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
name|src
parameter_list|)
block|{
operator|*
name|dst
operator|=
name|src
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|atomic_clear_ptr
value|atomic_clear_32
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
value|atomic_set_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_rel_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_store_ptr
value|atomic_store_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_rel_32
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
name|atomic_add_acq_int
value|atomic_add_acq_32
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
name|atomic_subtract_int
value|atomic_subtract_32
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
name|atomic_subtract_rel_int
value|atomic_subtract_rel_32
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
name|atomic_clear_acq_int
value|atomic_clear_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_rel_int
value|atomic_clear_rel_32
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
name|atomic_set_acq_int
value|atomic_set_acq_32
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
name|atomic_cmpset_int
value|atomic_cmpset_32
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
name|atomic_cmpset_rel_int
value|atomic_cmpset_rel_32
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
name|atomic_load_acq_int
value|atomic_load_acq_32
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_rel_32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

