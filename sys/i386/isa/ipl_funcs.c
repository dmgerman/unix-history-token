begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Bruce Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/ipl.h>
end_include

begin_include
include|#
directive|include
file|<machine/globals.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/intr_machdep.h>
end_include

begin_comment
comment|/*  * Bits in the ipending bitmap variable must be set atomically because  * ipending may be manipulated by interrupts or other cpu's without holding   * any locks.  *  * Note: setbits uses a locked or, making simple cases MP safe.  */
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
value|void name(void)					\ {						\ 	atomic_set_int(var, bits);		\ }
end_define

begin_macro
name|DO_SETBITS
argument_list|(
argument|setdelayed
argument_list|,
argument|&ipending
argument_list|,
argument|loadandclear(&idelayed)
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
argument|setsoftvm
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_VM_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsofttq
argument_list|,
argument|&ipending
argument_list|,
argument|SWI_TQ_PENDING
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
argument|schedsoftvm
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_VM_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|schedsofttq
argument_list|,
argument|&idelayed
argument_list|,
argument|SWI_TQ_PENDING
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

begin_comment
comment|/*  * Support for SPL assertions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANT_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|SPLASSERT_IGNORE
value|0
end_define

begin_define
define|#
directive|define
name|SPLASSERT_LOG
value|1
end_define

begin_define
define|#
directive|define
name|SPLASSERT_PANIC
value|2
end_define

begin_decl_stmt
specifier|static
name|int
name|splassertmode
init|=
name|SPLASSERT_LOG
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_kern
argument_list|,
name|OID_AUTO
argument_list|,
name|splassertmode
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|splassertmode
argument_list|,
literal|0
argument_list|,
literal|"Set the mode of SPLASSERT"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|TUNABLE_INT
argument_list|(
literal|"kern.splassertmode"
argument_list|,
operator|&
name|splassertmode
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|splassertfail
parameter_list|(
name|char
modifier|*
name|str
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|level
parameter_list|)
block|{
switch|switch
condition|(
name|splassertmode
condition|)
block|{
case|case
name|SPLASSERT_IGNORE
case|:
break|break;
case|case
name|SPLASSERT_LOG
case|:
name|printf
argument_list|(
name|str
argument_list|,
name|msg
argument_list|,
name|name
argument_list|,
name|level
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
break|break;
case|case
name|SPLASSERT_PANIC
case|:
name|panic
argument_list|(
name|str
argument_list|,
name|msg
argument_list|,
name|name
argument_list|,
name|level
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|GENSPLASSERT
parameter_list|(
name|NAME
parameter_list|,
name|MODIFIER
parameter_list|)
define|\
value|void							\ NAME##assert(const char *msg)				\ {							\ 	if ((cpl& (MODIFIER)) != (MODIFIER))		\ 		splassertfail("%s: not %s, cpl == %#x",	\ 		    msg, __XSTRING(NAME) + 3, cpl);	\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GENSPLASSERT
parameter_list|(
name|NAME
parameter_list|,
name|MODIFIER
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************************************************************  *			GENERAL SPL CODE				*  ************************************************************************  *  *  Implement splXXX(), spl0(), splx(), and splq().  splXXX() disables a  *  set of interrupts (e.g. splbio() disables interrupts relating to   *  device I/O) and returns the previous interrupt mask.  splx() restores  *  the previous interrupt mask, spl0() is a special case which enables  *  all interrupts and is typically used inside i386/i386 swtch.s and  *  fork_trampoline.  splq() is a generic version of splXXX().  *  *  The SPL routines mess around with the 'cpl' global, which masks   *  interrupts.  Interrupts are not *actually* masked.  What happens is   *  that if an interrupt masked by the cpl occurs, the appropriate bit  *  in 'ipending' is set and the interrupt is defered.  When we clear  *  bits in the cpl we must check to see if any ipending interrupts have  *  been unmasked and issue the synchronously, which is what the splz()  *  call does.  *  *  Because the cpl is often saved and restored in a nested fashion, cpl  *  modifications are only allowed in the SMP case when the MP lock is held  *  to prevent multiple processes from tripping over each other's masks.  *  The cpl is saved when you do a context switch (mi_switch()) and restored  *  when your process gets cpu again.  *  *  An interrupt routine is allowed to modify the cpl as long as it restores  *  it prior to returning (thus the interrupted mainline code doesn't notice  *  anything amiss).  For the SMP case, the interrupt routine must hold   *  the MP lock for any cpl manipulation.  *  *  Likewise, due to the deterministic nature of cpl modifications, we do  *  NOT need to use locked instructions to modify it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

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
value|GENSPLASSERT(NAME, MODIFIER)			\ unsigned NAME(void)				\ {						\ 	unsigned x;				\ 						\ 	x = cpl;				\ 	cpl OP MODIFIER;			\ 	return (x);				\ }
end_define

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
name|cpl
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ipending
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
init|=
name|cpl
decl_stmt|;
name|cpl
operator||=
name|mask
expr_stmt|;
return|return
operator|(
name|tmp
operator|)
return|;
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

begin_comment
comment|/*  *	SMP CASE  *  *	Mostly the same as the non-SMP case now, but it didn't used to be  *	this clean.  */
end_comment

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
value|GENSPLASSERT(NAME, MODIFIER)			\ unsigned NAME(void)				\ {						\ 	unsigned x;				\ 						\ 	x = cpl;				\ 	cpl OP MODIFIER;			\ 						\ 	return (x);				\ }
end_define

begin_comment
comment|/*  * spl0() -	unmask all interrupts  *  *	The MP lock must be held on entry  *	This routine may only be called from mainline code.  */
end_comment

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|inside_intr
operator|==
literal|0
argument_list|,
operator|(
literal|"spl0: called from interrupt"
operator|)
argument_list|)
expr_stmt|;
name|cpl
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|ipending
condition|)
name|splz
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * splx() -	restore previous interrupt mask  *  *	The MP lock must be held on entry  */
end_comment

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
name|inside_intr
operator|==
literal|0
operator|&&
operator|(
name|ipending
operator|&
operator|~
name|cpl
operator|)
operator|!=
literal|0
condition|)
name|splz
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * splq() -	blocks specified interrupts  *  *	The MP lock must be held on entry  */
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
init|=
name|cpl
decl_stmt|;
name|cpl
operator||=
name|mask
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

begin_comment
comment|/* Finally, generate the actual spl*() functions */
end_comment

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
argument_list|,
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
argument|splsoftvm
argument_list|,
argument||=
argument_list|,
argument|SWI_VM_MASK
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|GENSPL
argument_list|(
argument|splsofttq
argument_list|,
argument||=
argument_list|,
argument|SWI_TQ_MASK
argument_list|,
literal|17
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
argument|net_imask | bio_imask | cam_imask
argument_list|,
literal|15
argument_list|)
end_macro

end_unit

