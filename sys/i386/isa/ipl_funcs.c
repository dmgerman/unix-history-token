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
file|<sys/bus.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/icu.h>
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
value|void name(void)					\ {						\ 	atomic_set_int(var, bits);		\ 	sched_ithd((void *) SOFTINTR);		\ }
end_define

begin_define
define|#
directive|define
name|DO_SETBITS_AND_NO_MORE
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
argument|&spending
argument_list|,
argument|loadandclear(&idelayed)
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftcamnet
argument_list|,
argument|&spending
argument_list|,
argument|SWI_CAMNET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftcambio
argument_list|,
argument|&spending
argument_list|,
argument|SWI_CAMBIO_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftclock
argument_list|,
argument|&spending
argument_list|,
argument|SWI_CLOCK_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftnet
argument_list|,
argument|&spending
argument_list|,
argument|SWI_NET_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsofttty
argument_list|,
argument|&spending
argument_list|,
argument|SWI_TTY_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsoftvm
argument_list|,
argument|&spending
argument_list|,
argument|SWI_VM_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS
argument_list|(
argument|setsofttq
argument_list|,
argument|&spending
argument_list|,
argument|SWI_TQ_PENDING
argument_list|)
end_macro

begin_macro
name|DO_SETBITS_AND_NO_MORE
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
name|spending
operator|&
name|SWI_CLOCK_PENDING
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Dummy spl calls.  The only reason for these is to not break  * all the code which expects to call them.  */
end_comment

begin_function
name|void
name|spl0
parameter_list|(
name|void
parameter_list|)
block|{}
end_function

begin_function
name|void
name|splx
parameter_list|(
name|intrmask_t
name|x
parameter_list|)
block|{}
end_function

begin_function
name|intrmask_t
name|splq
parameter_list|(
name|intrmask_t
name|mask
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splbio
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splcam
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splhigh
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splimp
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splnet
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsoftcam
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsoftcambio
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsoftcamnet
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsoftclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsofttty
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsoftvm
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splsofttq
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splstatclock
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|spltty
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|intrmask_t
name|splvm
parameter_list|(
name|void
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

end_unit

