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
name|_MACHINE_ATOMIC_V4_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_V4_H_
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
operator|<=
literal|5
end_if

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

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|Only use this file with ARMv5 and earlier
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
name|int
name|atomic_fcmpset_32
parameter_list|(
specifier|volatile
name|u_int32_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int32_t
modifier|*
name|cmpval
parameter_list|,
specifier|volatile
name|u_int32_t
name|newval
parameter_list|)
block|{
name|u_int32_t
name|ret
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	 	ret = *p; 	    	if (*p == *cmpval) { 			*p = newval; 			ret =
literal|1
argument|; 		} else { 			*cmpval = *p; 			ret =
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
name|int
name|atomic_fcmpset_64
parameter_list|(
specifier|volatile
name|u_int64_t
modifier|*
name|p
parameter_list|,
specifier|volatile
name|u_int64_t
modifier|*
name|cmpval
parameter_list|,
specifier|volatile
name|u_int64_t
name|newval
parameter_list|)
block|{
name|u_int64_t
name|ret
decl_stmt|;
name|__with_interrupts_disabled
argument_list|(
argument|{ 	    	if (*p == *cmpval) { 			*p = newval; 			ret =
literal|1
argument|; 		} else { 			*cmpval = *p; 			ret =
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

begin_function
specifier|static
name|__inline
name|uint32_t
name|atomic_swap_32
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
return|return
operator|(
name|__swp
argument_list|(
name|v
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
name|atomic_fcmpset_rel_32
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_32
value|atomic_fcmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_64
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_64
value|atomic_fcmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_acq_long
value|atomic_fcmpset_long
end_define

begin_define
define|#
directive|define
name|atomic_fcmpset_rel_long
value|atomic_fcmpset_long
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
name|atomic_cmpset_acq_32
value|atomic_cmpset_32
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_rel_64
value|atomic_cmpset_64
end_define

begin_define
define|#
directive|define
name|atomic_cmpset_acq_64
value|atomic_cmpset_64
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* atomic_fcmpset_32 is only defined for the kernel */
end_comment

begin_function
specifier|static
name|__inline
name|u_long
name|atomic_fcmpset_long
parameter_list|(
specifier|volatile
name|u_long
modifier|*
name|dst
parameter_list|,
name|u_long
modifier|*
name|old
parameter_list|,
name|u_long
name|newe
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
name|dst
argument_list|,
operator|(
name|uint32_t
operator|*
operator|)
name|old
argument_list|,
name|newe
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/*  * ARMv5 does not support SMP.  For both kernel and user modes, only a  * compiler barrier is needed for fences, since CPU is always  * self-consistent.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|atomic_thread_fence_acq
parameter_list|(
name|void
parameter_list|)
block|{
name|__compiler_membar
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
name|__compiler_membar
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
name|__compiler_membar
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
name|__compiler_membar
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_ATOMIC_H_ */
end_comment

end_unit

