begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: sa11x0_irqhandler.c,v 1.5 2003/08/07 16:26:54 agc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to the NetBSD Foundation  * by IWAMOTO Toshihiro.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Charles M. Hannum and by Jason R. Thorpe of the Numerical Aerospace  * Simulation Facility, NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)isa.c	7.2 (Berkeley) 5/13/91  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<arm/sa11x0/sa11x0_reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/sa11x0/sa11x0_var.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_define
define|#
directive|define
name|NIRQS
value|0x20
end_define

begin_decl_stmt
name|struct
name|intrhand
modifier|*
name|irqhandlers
index|[
name|NIRQS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|current_intr_depth
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|actual_mask
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IPL_LEVELS
value|13
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|hpcarm
end_ifdef

begin_define
define|#
directive|define
name|IPL_LEVELS
value|(NIPL+1)
end_define

begin_decl_stmt
name|u_int
name|imask
index|[
name|NIPL
index|]
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|u_int
name|spl_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|irqmasks
index|[
name|IPL_LEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|u_int
name|irqblock
index|[
name|NIRQS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int
name|levels
index|[
name|IPL_LEVELS
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|set_spl_masks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static int fakeintr(void *);
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|static
name|int
name|dumpirqhandlers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Recalculate the interrupt masks from scratch.  * We could code special registry and deregistry versions of this function that  * would be faster, but the code would be nastier, and we don't expect this to  * happen very much anyway.  */
end_comment

begin_function_decl
name|void
name|intr_calculatemasks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|intr_calculatemasks
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|irq
decl_stmt|;
name|int
name|intrlevel
index|[
name|ICU_LEN
index|]
decl_stmt|;
name|int
name|level
decl_stmt|;
comment|/* First, figure out which levels each IRQ uses. */
for|for
control|(
name|irq
operator|=
literal|0
init|;
name|irq
operator|<
name|ICU_LEN
condition|;
name|irq
operator|++
control|)
block|{
name|intrlevel
index|[
name|irq
index|]
operator|=
name|levels
index|[
name|irq
index|]
expr_stmt|;
block|}
comment|/* Then figure out which IRQs use each level. */
ifdef|#
directive|ifdef
name|hpcarm
for|for
control|(
name|level
operator|=
literal|0
init|;
name|level
operator|<
name|NIPL
condition|;
name|level
operator|++
control|)
block|{
else|#
directive|else
for|for
control|(
name|level
operator|=
literal|0
init|;
name|level
operator|<=
name|IPL_LEVELS
condition|;
name|level
operator|++
control|)
block|{
endif|#
directive|endif
name|int
name|irqs
init|=
literal|0
decl_stmt|;
for|for
control|(
name|irq
operator|=
literal|0
init|;
name|irq
operator|<
name|ICU_LEN
condition|;
name|irq
operator|++
control|)
block|{
if|if
condition|(
name|intrlevel
index|[
name|irq
index|]
operator|&
operator|(
literal|1
operator|<<
name|level
operator|)
condition|)
block|{
name|irqs
operator||=
literal|1
operator|<<
name|irq
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|hpcarm
name|imask
index|[
name|level
index|]
operator|=
name|irqs
expr_stmt|;
else|#
directive|else
name|irqmasks
index|[
name|level
index|]
operator|=
name|irqs
expr_stmt|;
name|printf
argument_list|(
literal|"level %d set to %x\n"
argument_list|,
name|level
argument_list|,
name|irqs
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/*        		 * Enforce a hierarchy that gives slow devices a better chance at not 		 * dropping data.                                      		 */
ifdef|#
directive|ifdef
name|hpcarm
for|for
control|(
name|level
operator|=
name|NIPL
operator|-
literal|1
init|;
name|level
operator|>
literal|0
condition|;
name|level
operator|--
control|)
name|imask
index|[
name|level
operator|-
literal|1
index|]
operator||=
name|imask
index|[
name|level
index|]
expr_stmt|;
else|#
directive|else
for|for
control|(
name|level
operator|=
name|IPL_LEVELS
init|;
name|level
operator|>
literal|0
condition|;
name|level
operator|--
control|)
name|irqmasks
index|[
name|level
operator|-
literal|1
index|]
operator||=
name|irqmasks
index|[
name|level
index|]
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Calculate irqblock[], which emulates hardware interrupt levels. 	 */
if|#
directive|if
literal|0
block|for (irq = 0; irq< ICU_LEN; irq++) { 		int irqs = 1<< irq; 		for (q = irqhandlers[irq]; q; q = q->ih_next)
ifdef|#
directive|ifdef
name|hpcarm
block|irqs |= ~imask[q->ih_level];
else|#
directive|else
block|irqs |= ~irqmasks[q->ih_level];
endif|#
directive|endif
block|irqblock[irq] = irqs; 	}
endif|#
directive|endif
block|}
specifier|const
name|struct
name|evcnt
modifier|*
name|sa11x0_intr_evcnt
argument_list|(
name|sa11x0_chipset_tag_t
argument_list|,
name|int
argument_list|)
decl_stmt|;
name|void
name|stray_irqhandler
argument_list|(
name|void
operator|*
argument_list|)
decl_stmt|;
specifier|const
name|struct
name|evcnt
modifier|*
name|sa11x0_intr_evcnt
parameter_list|(
name|sa11x0_chipset_tag_t
name|ic
parameter_list|,
name|int
name|irq
parameter_list|)
block|{
comment|/* XXX for now, no evcnt parent reported */
return|return
name|NULL
return|;
block|}
name|void
name|stray_irqhandler
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
name|printf
argument_list|(
literal|"stray interrupt %p\n"
argument_list|,
name|p
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"bla\n"
argument_list|)
expr_stmt|;
block|}
if|#
directive|if
literal|0
block|int fakeintr(void *p) {  	return 0; }
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DEBUG
name|int
name|dumpirqhandlers
parameter_list|()
block|{
name|int
name|irq
decl_stmt|;
name|struct
name|irqhandler
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|irq
operator|=
literal|0
init|;
name|irq
operator|<
name|ICU_LEN
condition|;
name|irq
operator|++
control|)
block|{
name|printf
argument_list|(
literal|"irq %d:"
argument_list|,
name|irq
argument_list|)
expr_stmt|;
name|p
operator|=
name|irqhandlers
index|[
name|irq
index|]
expr_stmt|;
for|for
control|(
init|;
name|p
condition|;
name|p
operator|=
name|p
operator|->
name|ih_next
control|)
name|printf
argument_list|(
literal|"ih_func: 0x%lx, "
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|p
operator|->
name|ih_func
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* End of irqhandler.c */
end_comment

end_unit

