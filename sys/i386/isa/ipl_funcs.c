begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Bruce Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ipl_funcs.c,v 1.6 1997/08/29 18:45:23 fsmp Exp $  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_comment
comment|/*  * The volatile bitmap variables must be set atomically.  This normally  * involves using a machine-dependent bit-set or `or' instruction.  */
end_comment

begin_define
define|#
directive|define
name|DO_SETBITS
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|bits
parameter_list|)
define|\
value|void name(void)					\ {						\ 	setbits(var, bits);			\ }
end_define

begin_macro
name|DO_SETBITS
argument_list|(
argument|setdelayed
argument_list|,
argument|&ipending
argument_list|,
argument|loadandclear((unsigned *)&idelayed)
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftast
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_AST_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftclock
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CLOCK_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftnet
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_NET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsofttty
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_TTY_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftnet
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_NET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsofttty
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_TTY_PENDING
argument_list|)
end_macro

begin_function
name|unsigned
name|softclockpending
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|ipending
operator|&
name|SWI_CLOCK_PENDING
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|GENSPL
parameter_list|(
name|name
parameter_list|,
name|set_cpl
parameter_list|)
define|\
value|unsigned name(void)				\ {						\ 	unsigned x;				\ 						\ 	x = cpl;				\ 	set_cpl;				\ 	return (x);				\ }
end_define

begin_macro
name|GENSPL
argument_list|(
argument|splbio
argument_list|,
argument|cpl |= bio_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splclock
argument_list|,
argument|cpl = HWI_MASK | SWI_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splhigh
argument_list|,
argument|cpl = HWI_MASK | SWI_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splimp
argument_list|,
argument|cpl |= net_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splnet
argument_list|,
argument|cpl |= SWI_NET_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftclock
argument_list|,
argument|cpl = SWI_CLOCK_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsofttty
argument_list|,
argument|cpl |= SWI_TTY_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splstatclock
argument_list|,
argument|cpl |= stat_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|spltty
argument_list|,
argument|cpl |= tty_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splvm
argument_list|,
argument|cpl |= net_imask | bio_imask
argument_list|)
end_macro

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
name|cpl
operator|=
name|SWI_AST_MASK
expr_stmt|;
if|if
condition|(
name|ipending
operator|&
operator|~
name|SWI_AST_MASK
condition|)
name|splz
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splx
parameter_list|(
name|unsigned
name|ipl
parameter_list|)
block|{
name|cpl
operator|=
name|ipl
expr_stmt|;
if|if
condition|(
name|ipending
operator|&
operator|~
name|ipl
condition|)
name|splz
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !SMP */
end_comment

begin_include
include|#
directive|include
file|<machine/smp.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|bspEarly
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_IFCPL
end_ifdef

begin_define
define|#
directive|define
name|IFCPL_LOCK
parameter_list|()
value|SCPL_LOCK()
end_define

begin_define
define|#
directive|define
name|IFCPL_UNLOCK
parameter_list|()
value|SCPL_UNLOCK()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* REAL_IFCPL */
end_comment

begin_define
define|#
directive|define
name|IFCPL_LOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|IFCPL_UNLOCK
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REAL_IFCPL */
end_comment

begin_comment
comment|/*  * The volatile bitmap variables must be set atomically.  This normally  * involves using a machine-dependent bit-set or `or' instruction.  */
end_comment

begin_define
define|#
directive|define
name|DO_SETBITS
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|,
name|bits
parameter_list|)
define|\
value|void name(void)					\ {						\ 	IFCPL_LOCK();				\ 	setbits(var, bits);			\ 	IFCPL_UNLOCK();				\ }
end_define

begin_macro
name|DO_SETBITS
argument_list|(
argument|setdelayed
argument_list|,
argument|&ipending
argument_list|,
argument|loadandclear((unsigned *)&idelayed)
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftast
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_AST_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftclock
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CLOCK_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftnet
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_NET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsofttty
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_TTY_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftnet
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_NET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsofttty
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_TTY_PENDING
argument_list|)
end_macro

begin_function
name|unsigned
name|softclockpending
parameter_list|(
name|void
parameter_list|)
block|{
name|unsigned
name|x
decl_stmt|;
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
name|x
operator|=
name|ipending
operator|&
name|SWI_CLOCK_PENDING
expr_stmt|;
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
return|return
name|x
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|notneeded
end_ifdef

begin_define
define|#
directive|define
name|GENSPL
parameter_list|(
name|name
parameter_list|,
name|set_cpl
parameter_list|)
define|\
value|unsigned name(void)				\ {						\ 	unsigned x;				\ 						\ 	IFCPL_LOCK();				\ 	x = cpl;				\
comment|/* XXX test cil */
value|\ 	set_cpl;				\ 	IFCPL_UNLOCK();				\ 						\ 	return (x);				\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* notneeded */
end_comment

begin_comment
comment|/*  * This version has to check for bsp_apic_ready,  * as calling simple_lock() (ie ss_lock) before then deadlocks the system.  * A sample count of GENSPLR calls before bsp_apic_ready was set: 2193  */
end_comment

begin_define
define|#
directive|define
name|GENSPLR
parameter_list|(
name|name
parameter_list|,
name|set_cpl
parameter_list|)
define|\
value|unsigned name(void)				\ {						\ 	unsigned x;				\ 						\ 	if (bsp_apic_ready)			\ 		IFCPL_LOCK();			\ 	x = cpl;				\
comment|/* XXX test cil */
value|\ 	set_cpl;				\ 	if (bsp_apic_ready)			\ 		IFCPL_UNLOCK();			\ 						\ 	return (x);				\ }
end_define

begin_macro
name|GENSPLR
argument_list|(
argument|splbio
argument_list|,
argument|cpl |= bio_imask
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splclock
argument_list|,
argument|cpl = HWI_MASK | SWI_MASK
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splhigh
argument_list|,
argument|cpl = HWI_MASK | SWI_MASK
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splimp
argument_list|,
argument|cpl |= net_imask
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splnet
argument_list|,
argument|cpl |= SWI_NET_MASK
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splsoftclock
argument_list|,
argument|cpl = SWI_CLOCK_MASK
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splsofttty
argument_list|,
argument|cpl |= SWI_TTY_MASK
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splstatclock
argument_list|,
argument|cpl |= stat_imask
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|spltty
argument_list|,
argument|cpl |= tty_imask
argument_list|)
end_macro

begin_macro
name|GENSPLR
argument_list|(
argument|splvm
argument_list|,
argument|cpl |= net_imask | bio_imask
argument_list|)
end_macro

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
comment|/* XXX test cil */
name|cpl
operator|=
name|SWI_AST_MASK
expr_stmt|;
if|if
condition|(
name|ipending
operator|&
operator|~
name|SWI_AST_MASK
condition|)
block|{
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
name|splz
argument_list|()
expr_stmt|;
block|}
else|else
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|splx
parameter_list|(
name|unsigned
name|ipl
parameter_list|)
block|{
if|if
condition|(
name|bsp_apic_ready
condition|)
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
comment|/* XXX test cil */
name|cpl
operator|=
name|ipl
expr_stmt|;
if|if
condition|(
name|ipending
operator|&
operator|~
name|ipl
condition|)
block|{
if|if
condition|(
name|bsp_apic_ready
condition|)
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
name|splz
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bsp_apic_ready
condition|)
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Replaces UP specific inline found in (?) pci/pci_support.c.  *  * Stefan said:  * You know, that splq() is used in the shared interrupt multiplexer, and that  * the SMP version should not have too much overhead. If it is significantly  * slower, then moving the splq() out of the loop in intr_mux() and passing in  * the logical OR of all mask values might be a better solution than the  * current code. (This logical OR could of course be pre-calculated whenever  * another shared interrupt is registered ...)  */
end_comment

begin_function
name|intrmask_t
name|splq
parameter_list|(
name|intrmask_t
name|mask
parameter_list|)
block|{
name|intrmask_t
name|tmp
decl_stmt|;
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
name|tmp
operator|=
name|cpl
expr_stmt|;
name|cpl
operator||=
name|mask
expr_stmt|;
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
return|return
operator|(
name|tmp
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !SMP */
end_comment

end_unit

