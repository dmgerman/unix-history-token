begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From BSDI: intr.c,v 1.6.2.5 1999/07/06 19:16:52 cp Exp  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Interrupt thread code. */
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
file|<sys/interrupt.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/vmmeter.h>
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

begin_struct
struct|struct
name|int_entropy
block|{
name|struct
name|proc
modifier|*
name|p
decl_stmt|;
name|int
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|u_int
name|straycount
index|[
name|ICU_LEN
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAX_STRAY_LOG
value|5
end_define

begin_comment
comment|/*  * Schedule a heavyweight interrupt process.  This function is called  * from the interrupt handlers Xintr<num>.  */
end_comment

begin_function
name|void
name|sched_ithd
parameter_list|(
name|void
modifier|*
name|cookie
parameter_list|)
block|{
name|int
name|irq
init|=
operator|(
name|int
operator|)
name|cookie
decl_stmt|;
comment|/* IRQ we're handling */
name|struct
name|ithd
modifier|*
name|ithd
init|=
name|ithds
index|[
name|irq
index|]
decl_stmt|;
comment|/* and the process that does it */
name|int
name|error
decl_stmt|;
comment|/* This used to be in icu_vector.s */
comment|/* 	 * We count software interrupts when we process them.  The 	 * code here follows previous practice, but there's an 	 * argument for counting hardware interrupts when they're 	 * processed too. 	 */
name|atomic_add_long
argument_list|(
name|intr_countp
index|[
name|irq
index|]
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* one more for this IRQ */
name|atomic_add_int
argument_list|(
operator|&
name|cnt
operator|.
name|v_intr
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|/* one more global interrupt */
comment|/* 	 * Schedule the interrupt thread to run if needed and switch to it 	 * if we schedule it if !cold. 	 */
name|error
operator|=
name|ithread_schedule
argument_list|(
name|ithd
argument_list|,
operator|!
name|cold
argument_list|)
expr_stmt|;
comment|/* 	 * Log stray interrupts. 	 */
if|if
condition|(
name|error
operator|==
name|EINVAL
condition|)
if|if
condition|(
name|straycount
index|[
name|irq
index|]
operator|<
name|MAX_STRAY_LOG
condition|)
block|{
name|printf
argument_list|(
literal|"stray irq %d\n"
argument_list|,
name|irq
argument_list|)
expr_stmt|;
if|if
condition|(
operator|++
name|straycount
index|[
name|irq
index|]
operator|==
name|MAX_STRAY_LOG
condition|)
name|printf
argument_list|(
literal|"got %d stray irq %d's: not logging anymore\n"
argument_list|,
name|MAX_STRAY_LOG
argument_list|,
name|irq
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

