begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * William Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: @(#)icu.h	5.6 (Berkeley) 5/9/91  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * AT/386 Interrupt Control constants  * W. Jolitz 8/89  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86_ISA_ICU_H_
end_ifndef

begin_define
define|#
directive|define
name|_X86_ISA_ICU_H_
end_define

begin_define
define|#
directive|define
name|ICU_IMR_OFFSET
value|1
end_define

begin_comment
comment|/*  * PC-AT machines wire the slave PIC to pin 2 on the master PIC.  */
end_comment

begin_define
define|#
directive|define
name|ICU_SLAVEID
value|2
end_define

begin_comment
comment|/*  * Determine the base master and slave modes not including auto EOI support.  * All machines that FreeBSD supports use 8086 mode.  */
end_comment

begin_define
define|#
directive|define
name|BASE_MASTER_MODE
value|ICW4_8086
end_define

begin_define
define|#
directive|define
name|BASE_SLAVE_MODE
value|ICW4_8086
end_define

begin_comment
comment|/* Enable automatic EOI if requested. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTO_EOI_1
end_ifdef

begin_define
define|#
directive|define
name|MASTER_MODE
value|(BASE_MASTER_MODE | ICW4_AEOI)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MASTER_MODE
value|BASE_MASTER_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AUTO_EOI_2
end_ifdef

begin_define
define|#
directive|define
name|SLAVE_MODE
value|(BASE_SLAVE_MODE | ICW4_AEOI)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SLAVE_MODE
value|BASE_SLAVE_MODE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IRQ_MASK
parameter_list|(
name|irq
parameter_list|)
value|(1<< (irq))
end_define

begin_define
define|#
directive|define
name|IMEN_MASK
parameter_list|(
name|ai
parameter_list|)
value|(IRQ_MASK((ai)->at_irq))
end_define

begin_function_decl
name|void
name|atpic_handle_intr
parameter_list|(
name|u_int
name|vector
parameter_list|,
name|struct
name|trapframe
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|atpic_startup
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
comment|/* !_X86_ISA_ICU_H_ */
end_comment

end_unit

