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

begin_include
include|#
directive|include
file|<machine/intr.h>
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
specifier|extern
name|struct
name|sa11x0_softc
modifier|*
name|sa11x0_softc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|sa11x0_irq_mask
init|=
literal|0xfffffff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|vm_offset_t
name|saipic_base
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|arm_get_next_irq
parameter_list|()
block|{
name|int
name|irq
decl_stmt|;
if|if
condition|(
operator|(
name|irq
operator|=
operator|(
name|bus_space_read_4
argument_list|(
name|sa11x0_softc
operator|->
name|sc_iot
argument_list|,
name|sa11x0_softc
operator|->
name|sc_ioh
argument_list|,
name|SAIPIC_IP
argument_list|)
operator|&
name|sa11x0_irq_mask
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|ffs
argument_list|(
name|irq
argument_list|)
operator|-
literal|1
operator|)
return|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_function
name|void
name|arm_mask_irq
parameter_list|(
name|uintptr_t
name|irq
parameter_list|)
block|{
name|sa11x0_irq_mask
operator|&=
operator|~
operator|(
literal|1
operator|<<
name|irq
operator|)
expr_stmt|;
asm|__asm __volatile("str	%0, [%1, #0x04]"
comment|/* SAIPIC_MR */
block|: :
literal|"r"
operator|(
name|sa11x0_irq_mask
operator|)
operator|,
literal|"r"
operator|(
name|saipic_base
operator|)
block|)
function|;
end_function

begin_macro
unit|}  void
name|arm_unmask_irq
argument_list|(
argument|uintptr_t irq
argument_list|)
end_macro

begin_block
block|{
name|sa11x0_irq_mask
operator||=
operator|(
literal|1
operator|<<
name|irq
operator|)
expr_stmt|;
asm|__asm __volatile("str	%0, [%1, #0x04]"
comment|/* SAIPIC_MR */
block|: :
literal|"r"
operator|(
name|sa11x0_irq_mask
operator|)
operator|,
literal|"r"
operator|(
name|saipic_base
operator|)
block|)
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|}  void
name|stray_irqhandler
argument_list|(
name|void
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
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
block|}
end_function

begin_comment
comment|/* End of irqhandler.c */
end_comment

end_unit

