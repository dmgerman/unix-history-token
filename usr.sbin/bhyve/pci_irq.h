begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Hudson River Trading LLC  * Written by: John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PCI_IRQ_H__
end_ifndef

begin_define
define|#
directive|define
name|__PCI_IRQ_H__
end_define

begin_struct_decl
struct_decl|struct
name|pci_devinst
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|pci_irq_assert
parameter_list|(
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_irq_deassert
parameter_list|(
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_irq_init
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_irq_reserve
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pci_irq_use
parameter_list|(
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pirq_alloc_pin
parameter_list|(
name|struct
name|pci_devinst
modifier|*
name|pi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pirq_irq
parameter_list|(
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|pirq_read
parameter_list|(
name|int
name|pin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pirq_write
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|pin
parameter_list|,
name|uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

