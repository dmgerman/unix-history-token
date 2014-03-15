begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Tycho Nightingale<tycho.nightingale@pluribusnetworks.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VATPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_VATPIC_H_
end_define

begin_include
include|#
directive|include
file|<isa/isareg.h>
end_include

begin_define
define|#
directive|define
name|ICU_IMR_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|IO_ELCR1
value|0x4d0
end_define

begin_define
define|#
directive|define
name|IO_ELCR2
value|0x4d1
end_define

begin_function_decl
name|struct
name|vatpic
modifier|*
name|vatpic_init
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vatpic_cleanup
parameter_list|(
name|struct
name|vatpic
modifier|*
name|vatpic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_master_handler
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|struct
name|vm_exit
modifier|*
name|vmexit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_slave_handler
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|struct
name|vm_exit
modifier|*
name|vmexit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_elc_handler
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|struct
name|vm_exit
modifier|*
name|vmexit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_assert_irq
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_deassert_irq
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vatpic_pulse_irq
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vatpic_pending_intr
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
modifier|*
name|vecptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vatpic_intr_accepted
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VATPIC_H_ */
end_comment

end_unit

