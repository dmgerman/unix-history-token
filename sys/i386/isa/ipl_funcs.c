begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Bruce Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: ipl_funcs.c,v 1.8 1997/09/07 22:03:05 fsmp Exp $  */
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
argument|setsoftcamnet
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CAMNET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftcambio
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CAMBIO_PENDING
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

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftcamnet
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_CAMNET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftcambio
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_CAMBIO_PENDING
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
argument|splcam
argument_list|,
argument|cpl |= cam_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcam
argument_list|,
argument|cpl |= SWI_CAMBIO_MASK | SWI_CAMNET_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcambio
argument_list|,
argument|cpl |= SWI_CAMBIO_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcamnet
argument_list|,
argument|cpl |= SWI_CAMNET_MASK
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

begin_include
include|#
directive|include
file|<machine/smptests.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|SPL_DEBUG_POSTCODE
end_ifndef

begin_undef
undef|#
directive|undef
name|POSTCODE
end_undef

begin_undef
undef|#
directive|undef
name|POSTCODE_LO
end_undef

begin_undef
undef|#
directive|undef
name|POSTCODE_HI
end_undef

begin_define
define|#
directive|define
name|POSTCODE
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|POSTCODE_LO
parameter_list|(
name|X
parameter_list|)
end_define

begin_define
define|#
directive|define
name|POSTCODE_HI
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPL_DEBUG_POSTCODE */
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
argument|setsoftcamnet
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CAMNET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftcambio
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_CAMBIO_PENDING
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

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftcamnet
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_CAMNET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsoftcambio
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_CAMBIO_PENDING
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
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This version has to check for bsp_apic_ready,  * as calling simple_lock() (ie ss_lock) before then deadlocks the system.  * A sample count of GENSPL calls before bsp_apic_ready was set: 2193  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INTR_SPL
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SPL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|MAXZ
value|100000000
end_define

begin_define
define|#
directive|define
name|SPIN_COUNT
value|unsigned z = 0;
end_define

begin_define
define|#
directive|define
name|SPIN_SPL
define|\
value|if (++z>= MAXZ) {				\ 				bsp_apic_ready = 0;			\ 				panic("\ncil: 0x%08x", cil);		\ 			}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SPL_DEBUG */
end_comment

begin_define
define|#
directive|define
name|SPIN_COUNT
end_define

begin_define
define|#
directive|define
name|SPIN_SPL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SPL_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTR_SPL
end_ifdef

begin_define
define|#
directive|define
name|GENSPL
parameter_list|(
name|NAME
parameter_list|,
name|OP
parameter_list|,
name|MODIFIER
parameter_list|,
name|PC
parameter_list|)
define|\
value|unsigned NAME(void)							\ {									\ 	unsigned x, y;							\ 	SPIN_COUNT;							\ 									\ 	if (!bsp_apic_ready) {						\ 		x = cpl;						\ 		cpl OP MODIFIER;					\ 		return (x);						\ 	}								\ 									\ 	for (;;) {							\ 		IFCPL_LOCK();
comment|/* MP-safe */
value|\ 		x = y = cpl;
comment|/* current value */
value|\ 		POSTCODE(0x20 | PC);					\ 		if (inside_intr)					\ 			break;
comment|/* XXX only 1 INT allowed */
value|\ 		y OP MODIFIER;
comment|/* desired value */
value|\ 		if (cil& y) {
comment|/* not now */
value|\ 			IFCPL_UNLOCK();
comment|/* allow cil to change */
value|\ 			while (cil& y)					\ 				SPIN_SPL				\ 			continue;
comment|/* try again */
value|\ 		}							\ 		break;							\ 	}								\ 	cpl OP MODIFIER;
comment|/* make the change */
value|\ 	IFCPL_UNLOCK();							\ 									\ 	return (x);							\ }
end_define

begin_comment
comment|/*    NAME:            OP:     MODIFIER:				PC: */
end_comment

begin_macro
name|GENSPL
argument_list|(
argument|splbio
argument_list|,
argument||=
argument_list|,
argument|bio_imask
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splclock
argument_list|,
argument|=
argument_list|,
argument|HWI_MASK | SWI_MASK
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splhigh
argument_list|,
argument|=
argument_list|,
argument|HWI_MASK | SWI_MASK
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splimp
argument_list|,
argument||=
argument_list|,
argument|net_imask
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splnet
argument_list|,
argument||=
argument_list|,
argument|SWI_NET_MASK
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splcam
argument_list|,
argument||=
argument_list|,
argument|cam_imask
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcam
argument_list|,
argument||=
argument_list|,
argument|SWI_CAMBIO_MASK | SWI_CAMNET_MASK
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcambio
argument_list|,
argument||=
argument_list|,
argument|SWI_CAMBIO_MASK
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcamnet
argument_list|,
argument||=
argument_list|,
argument|SWI_CAMNET_MASK
literal|10
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftclock
argument_list|,
argument|=
argument_list|,
argument|SWI_CLOCK_MASK
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsofttty
argument_list|,
argument||=
argument_list|,
argument|SWI_TTY_MASK
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splstatclock
argument_list|,
argument||=
argument_list|,
argument|stat_imask
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|spltty
argument_list|,
argument||=
argument_list|,
argument|tty_imask
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splvm
argument_list|,
argument||=
argument_list|,
argument|net_imask | bio_imask
argument_list|,
literal|15
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* INTR_SPL */
end_comment

begin_define
define|#
directive|define
name|GENSPL
parameter_list|(
name|NAME
parameter_list|,
name|set_cpl
parameter_list|)
define|\
value|unsigned NAME(void)				\ {						\ 	unsigned x;				\ 						\ 	if (!bsp_apic_ready) {			\ 		x = cpl;			\ 		set_cpl;			\ 	}					\ 	else {					\ 		IFCPL_LOCK();			\ 		x = cpl;			\ 		set_cpl;			\ 		IFCPL_UNLOCK();			\ 	}					\ 						\ 	return (x);				\ }
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
argument|splcam
argument_list|,
argument|cpl |= cam_imask
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcam
argument_list|,
argument|cpl |= SWI_CAMBIO_MASK | SWI_CAMNET_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcambio
argument_list|,
argument|cpl |= SWI_CAMBIO_MASK
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsoftcamnet
argument_list|,
argument|cpl |= SWI_CAMNET_MASK
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTR_SPL */
end_comment

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|unpend
decl_stmt|;
ifdef|#
directive|ifdef
name|INTR_SPL
name|SPIN_COUNT
expr_stmt|;
for|for
control|(
init|;
condition|;
control|)
block|{
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
name|POSTCODE_HI
argument_list|(
literal|0xc
argument_list|)
expr_stmt|;
if|if
condition|(
name|cil
operator|&
name|SWI_AST_MASK
condition|)
block|{
comment|/* not now */
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
comment|/* allow cil to change */
while|while
condition|(
name|cil
operator|&
name|SWI_AST_MASK
condition|)
name|SPIN_SPL
continue|continue;
comment|/* try again */
block|}
break|break;
block|}
else|#
directive|else
comment|/* INTR_SPL */
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* INTR_SPL */
name|cpl
operator|=
name|SWI_AST_MASK
expr_stmt|;
name|unpend
operator|=
name|ipending
operator|&
operator|~
name|SWI_AST_MASK
expr_stmt|;
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
if|if
condition|(
name|unpend
operator|&&
operator|!
name|inside_intr
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
name|int
name|unpend
decl_stmt|;
ifdef|#
directive|ifdef
name|INTR_SPL
name|SPIN_COUNT
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|bsp_apic_ready
condition|)
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
return|return;
block|}
ifdef|#
directive|ifdef
name|INTR_SPL
for|for
control|(
init|;
condition|;
control|)
block|{
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
name|POSTCODE_HI
argument_list|(
literal|0xe
argument_list|)
expr_stmt|;
if|if
condition|(
name|inside_intr
condition|)
break|break;
comment|/* XXX only 1 INT allowed */
name|POSTCODE_HI
argument_list|(
literal|0xf
argument_list|)
expr_stmt|;
if|if
condition|(
name|cil
operator|&
name|ipl
condition|)
block|{
comment|/* not now */
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
comment|/* allow cil to change */
while|while
condition|(
name|cil
operator|&
name|ipl
condition|)
name|SPIN_SPL
continue|continue;
comment|/* try again */
block|}
break|break;
block|}
else|#
directive|else
comment|/* INTR_SPL */
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* INTR_SPL */
name|cpl
operator|=
name|ipl
expr_stmt|;
name|unpend
operator|=
name|ipending
operator|&
operator|~
name|ipl
expr_stmt|;
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
if|if
condition|(
name|unpend
operator|&&
operator|!
name|inside_intr
condition|)
name|splz
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
decl_stmt|,
name|tmp2
decl_stmt|;
ifdef|#
directive|ifdef
name|INTR_SPL
for|for
control|(
init|;
condition|;
control|)
block|{
name|IFCPL_LOCK
argument_list|()
expr_stmt|;
name|tmp
operator|=
name|tmp2
operator|=
name|cpl
expr_stmt|;
name|tmp2
operator||=
name|mask
expr_stmt|;
if|if
condition|(
name|cil
operator|&
name|tmp2
condition|)
block|{
comment|/* not now */
name|IFCPL_UNLOCK
argument_list|()
expr_stmt|;
comment|/* allow cil to change */
while|while
condition|(
name|cil
operator|&
name|tmp2
condition|)
comment|/* spin */
empty_stmt|;
continue|continue;
comment|/* try again */
block|}
break|break;
block|}
name|cpl
operator|=
name|tmp2
expr_stmt|;
else|#
directive|else
comment|/* INTR_SPL */
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
endif|#
directive|endif
comment|/* INTR_SPL */
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

