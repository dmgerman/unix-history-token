begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: i80321_intr.h,v 1.5 2004/01/12 10:25:06 scw Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001, 2002 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Jason R. Thorpe for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed for the NetBSD Project by  *	Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I80321_INTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_I80321_INTR_H_
end_define

begin_define
define|#
directive|define
name|ARM_IRQ_HANDLER
value|_C_LABEL(i80321_intr_dispatch)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_LOCORE
end_ifndef

begin_include
include|#
directive|include
file|<machine/armreg.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/i80321/i80321reg.h>
end_include

begin_function_decl
name|void
name|i80321_do_pending
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|__volatile
name|uint32_t
name|intr_enabled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|intr_steer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline
name|void
name|__attribute__
argument_list|(
operator|(
name|__unused__
operator|)
argument_list|)
name|i80321_set_intrmask
argument_list|(
name|void
argument_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c0, c0, 0"
block|: 		:
literal|"r"
operator|(
name|intr_enabled
operator|&
name|ICU_INT_HWMASK
operator|)
block|)
decl_stmt|;
end_decl_stmt

begin_function
unit|}  static
name|__inline
name|void
name|i80321_set_intrsteer
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("mcr p6, 0, %0, c4, c0, 0"
block|: 	    :
literal|"r"
operator|(
name|intr_steer
operator|&
name|ICU_INT_HWMASK
operator|)
block|)
function|;
end_function

begin_if
unit|}
if|#
directive|if
name|defined
argument_list|(
name|CPU_XSCALE_80219
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT_SWMASK
define|\
value|((1U<< ICU_INT_bit26) |											\ 	 (1U<< ICU_INT_bit25) |											\ 	 (1U<< ICU_INT_bit23) |											\ 	 (1U<< ICU_INT_bit22) |											\ 	 (1U<< ICU_INT_bit7)  |											\ 	 (1U<< ICU_INT_bit6)  |											\ 	 (1U<< ICU_INT_bit5)  |											\ 	 (1U<< ICU_INT_bit4))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INT_SWMASK
define|\
value|((1U<< ICU_INT_bit26) | (1U<< ICU_INT_bit22) |                \          (1U<< ICU_INT_bit5)  | (1U<< ICU_INT_bit4))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|static __inline void __attribute__((__unused__)) i80321_splx(int new) { 	extern __volatile uint32_t intr_enabled; 	extern __volatile int current_spl_level; 	extern __volatile int i80321_ipending; 	extern void i80321_do_pending(void); 	int oldirqstate, hwpend;
comment|/* Don't let the compiler re-order this code with preceding code */
end_comment

begin_comment
unit|__insn_barrier();  	current_spl_level = new;  	hwpend = (i80321_ipending& ICU_INT_HWMASK)& ~new; 	if (hwpend != 0) { 		oldirqstate = disable_interrupts(PSR_I); 		intr_enabled |= hwpend; 		i80321_set_intrmask(); 		restore_interrupts(oldirqstate); 	}  	if ((i80321_ipending& INT_SWMASK)& ~new) 		i80321_do_pending(); }  static __inline int __attribute__((__unused__)) i80321_splraise(int ipl) { 	extern __volatile int current_spl_level; 	extern int i80321_imask[]; 	int	old;  	old = current_spl_level; 	current_spl_level |= i80321_imask[ipl];
comment|/* Don't let the compiler re-order this code with subsequent code */
end_comment

begin_endif
unit|__insn_barrier();  	return (old); }  static __inline int __attribute__((__unused__)) i80321_spllower(int ipl) { 	extern __volatile int current_spl_level; 	extern int i80321_imask[]; 	int old = current_spl_level;  	i80321_splx(i80321_imask[ipl]); 	return(old); }
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EVBARM_SPL_NOINLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|splx
parameter_list|(
name|new
parameter_list|)
value|i80321_splx(new)
end_define

begin_define
define|#
directive|define
name|_spllower
parameter_list|(
name|ipl
parameter_list|)
value|i80321_spllower(ipl)
end_define

begin_define
define|#
directive|define
name|_splraise
parameter_list|(
name|ipl
parameter_list|)
value|i80321_splraise(ipl)
end_define

begin_expr_stmt
unit|void
name|_setsoftintr
argument_list|(
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int
name|_splraise
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_spllower
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|splx
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_setsoftintr
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! EVBARM_SPL_NOINLINE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I80321_INTR_H_ */
end_comment

end_unit

