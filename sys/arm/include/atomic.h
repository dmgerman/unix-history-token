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

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|I32_bit
end_ifndef

begin_define
define|#
directive|define
name|I32_bit
value|(1<< 7)
end_define

begin_comment
comment|/* IRQ disable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|F32_bit
end_ifndef

begin_define
define|#
directive|define
name|F32_bit
value|(1<< 6)
end_define

begin_comment
comment|/* FIQ disable */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__with_interrupts_disabled
parameter_list|(
name|expr
parameter_list|)
define|\
value|do {						\ 		u_int cpsr_save, tmp;			\ 							\ 		__asm __volatile(			\ 			"mrs  %0, cpsr;"		\ 			"orr  %1, %0, %2;"		\ 			"msr  cpsr_all, %1;"		\ 			: "=r" (cpsr_save), "=r" (tmp)	\ 			: "I" (I32_bit)		\ 		        : "cc" );		\ 		(expr);				\ 		 __asm __volatile(		\ 			"msr  cpsr_all, %0"	\ 			:
comment|/* no output */
value|\ 			: "r" (cpsr_save)	\ 			: "cc" );		\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|ARM_RAS_START
value|0xe0000004
end_define

begin_define
define|#
directive|define
name|ARM_RAS_END
value|0xe0000008
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
asm|__asm __volatile("swp	%0, %1, [%2]"
block|:
literal|"=&r"
operator|(
name|val
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
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"cmp	%1, %3\n"
literal|"streq	%4, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
literal|"moveq	%1, #1\n"
literal|"movne	%1, #0\n"
operator|:
literal|"=r"
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
name|ras_start
decl_stmt|,
name|start
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"add	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
operator|:
literal|"=r"
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
name|ras_start
decl_stmt|,
name|start
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"sub	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
operator|:
literal|"=r"
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
name|ras_start
decl_stmt|,
name|start
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"orr	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
operator|:
literal|"=r"
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
name|ras_start
decl_stmt|,
name|start
decl_stmt|;
asm|__asm __volatile("1:\n"
literal|"mov	%0, #0xe0000008\n"
literal|"adr	%1, 2f\n"
literal|"str	%1, [%0]\n"
literal|"adr	%1, 1b\n"
literal|"mov	%0, #0xe0000004\n"
literal|"str	%1, [%0]\n"
literal|"ldr	%1, [%2]\n"
literal|"bic	%1, %1, %3\n"
literal|"str	%1, [%2]\n"
literal|"2:\n"
literal|"mov	%1, #0\n"
literal|"str	%1, [%0]\n"
operator|:
literal|"=r"
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
block|)
function|;
end_function

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

begin_undef
undef|#
directive|undef
name|__with_interrupts_disabled
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_define
define|#
directive|define
name|atomic_set_rel_int
value|atomic_set_32
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
name|atomic_readandclear_int
value|atomic_readandclear_32
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
name|atomic_subtract_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_rel_int
value|atomic_subtract_32
end_define

begin_define
define|#
directive|define
name|atomic_subtract_acq_int
value|atomic_subtract_32
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
name|atomic_add_rel_int
value|atomic_add_32
end_define

begin_define
define|#
directive|define
name|atomic_add_acq_int
value|atomic_add_32
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
name|atomic_cmpset_rel_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_ptr
value|atomic_cmpset_ptr
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_int
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_ptr
value|atomic_cmpset_ptr
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_ptr
value|atomic_store_ptr
end_define

begin_define
define|#
directive|define
name|atomic_store_rel_int
value|atomic_store_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_32
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_smpset_rel_ptr
value|atomic_cmpset_ptr
end_define

begin_define
define|#
directive|define
name|atomic_load_acq_int
value|atomic_load_32
end_define

begin_define
define|#
directive|define
name|atomic_clear_ptr
parameter_list|(
name|ptr
parameter_list|,
name|bit
parameter_list|)
value|atomic_clear_32( \     (volatile uint32_t *)ptr, (uint32_t)bit)
end_define

begin_define
define|#
directive|define
name|atomic_store_ptr
parameter_list|(
name|ptr
parameter_list|,
name|bit
parameter_list|)
value|atomic_store_32( \     (volatile uint32_t *)ptr, (uint32_t)bit)
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_ptr
parameter_list|(
name|dst
parameter_list|,
name|exp
parameter_list|,
name|s
parameter_list|)
value|atomic_cmpset_32( \     (volatile uint32_t *)dst, (uint32_t)exp, (uint32_t)s)
end_define

begin_define
define|#
directive|define
name|atomic_set_ptr
parameter_list|(
name|ptr
parameter_list|,
name|src
parameter_list|)
value|atomic_set_32( \     (volatile uint32_t *)ptr,  (uint32_t)src)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

