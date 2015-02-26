begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE   * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMI_INTERRUPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_RMI_INTERRUPT_H_
end_define

begin_comment
comment|/* Defines for the IRQ numbers */
end_comment

begin_define
define|#
directive|define
name|IRQ_IPI
value|41
end_define

begin_comment
comment|/* 8-39 are used by PIC interrupts */
end_comment

begin_define
define|#
directive|define
name|IRQ_MSGRING
value|6
end_define

begin_define
define|#
directive|define
name|IRQ_TIMER
value|7
end_define

begin_define
define|#
directive|define
name|PIC_IRQ_BASE
value|8
end_define

begin_define
define|#
directive|define
name|PIC_IRT_LAST_IRQ
value|39
end_define

begin_define
define|#
directive|define
name|XLP_IRQ_IS_PICINTR
parameter_list|(
name|irq
parameter_list|)
value|((irq)>= PIC_IRQ_BASE&& \ 				    (irq)<= PIC_IRT_LAST_IRQ)
end_define

begin_define
define|#
directive|define
name|PIC_UART_0_IRQ
value|9
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_0_IRQ
value|11
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_1_IRQ
value|12
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_2_IRQ
value|13
end_define

begin_define
define|#
directive|define
name|PIC_PCIE_3_IRQ
value|14
end_define

begin_define
define|#
directive|define
name|PIC_EHCI_0_IRQ
value|16
end_define

begin_define
define|#
directive|define
name|PIC_MMC_IRQ
value|21
end_define

begin_comment
comment|/*  * XLR needs custom pre and post handlers for PCI/PCI-e interrupts  * XXX: maybe follow i386 intsrc model  */
end_comment

begin_function_decl
name|void
name|xlp_establish_intr
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|driver_filter_t
name|filt
parameter_list|,
name|driver_intr_t
name|handler
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|,
name|void
function_decl|(
modifier|*
name|busack
function_decl|)
parameter_list|(
name|int
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlp_enable_irq
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RMI_INTERRUPT_H_ */
end_comment

end_unit

