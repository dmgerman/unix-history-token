begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Berkeley Software Design, Inc. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Berkeley Software Design Inc's name may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN INC BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI Id: intr.c,v 1.6.2.5 1999/07/06 19:16:52 cp Exp  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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
file|<amd64/isa/icu.h>
end_include

begin_include
include|#
directive|include
file|<amd64/isa/intr_machdep.h>
end_include

begin_include
include|#
directive|include
file|<amd64/isa/isa.h>
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

begin_decl_stmt
specifier|static
name|u_int
name|glitchcount7
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|u_int
name|glitchcount15
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
name|uintptr_t
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
decl_stmt|,
name|isr
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
block|{
comment|/* Determine if it is a stray interrupt or simply a glitch */
if|if
condition|(
name|irq
operator|==
literal|7
condition|)
block|{
name|outb
argument_list|(
name|IO_ICU1
argument_list|,
name|OCW3_SEL
argument_list|)
expr_stmt|;
comment|/* select IS register */
name|isr
operator|=
name|inb
argument_list|(
name|IO_ICU1
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU1
argument_list|,
name|OCW3_SEL
operator||
name|OCW3_RIS
argument_list|)
expr_stmt|;
comment|/* reselect IIR */
if|if
condition|(
operator|(
name|isr
operator|&
literal|0x80
operator|)
operator|==
literal|0
condition|)
block|{
name|glitchcount7
operator|++
expr_stmt|;
return|return;
block|}
block|}
if|if
condition|(
name|irq
operator|==
literal|15
condition|)
block|{
name|outb
argument_list|(
name|IO_ICU2
argument_list|,
name|OCW3_SEL
argument_list|)
expr_stmt|;
comment|/* select IS register */
name|isr
operator|=
name|inb
argument_list|(
name|IO_ICU2
argument_list|)
expr_stmt|;
name|outb
argument_list|(
name|IO_ICU2
argument_list|,
name|OCW3_SEL
operator||
name|OCW3_RIS
argument_list|)
expr_stmt|;
comment|/* reselect IIR */
if|if
condition|(
operator|(
name|isr
operator|&
literal|0x80
operator|)
operator|==
literal|0
condition|)
block|{
name|glitchcount15
operator|++
expr_stmt|;
return|return;
block|}
block|}
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
block|}
end_function

end_unit

