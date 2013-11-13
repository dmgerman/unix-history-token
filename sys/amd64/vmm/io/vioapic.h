begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Tycho Nightingale<tycho.nightingale@pluribusnetworks.com>  * Copyright (c) 2013 Neel Natu<neel@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIOAPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_VIOAPIC_H_
end_define

begin_struct_decl
struct_decl|struct
name|vm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vioapic
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|VIOAPIC_BASE
value|0xFEC00000
end_define

begin_define
define|#
directive|define
name|VIOAPIC_SIZE
value|4096
end_define

begin_function_decl
name|struct
name|vioapic
modifier|*
name|vioapic_init
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
name|vioapic_cleanup
parameter_list|(
name|struct
name|vioapic
modifier|*
name|vioapic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vioapic_assert_irq
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
name|vioapic_deassert_irq
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
name|vioapic_mmio_write
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|uint64_t
name|gpa
parameter_list|,
name|uint64_t
name|wval
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vioapic_mmio_read
parameter_list|(
name|void
modifier|*
name|vm
parameter_list|,
name|int
name|vcpuid
parameter_list|,
name|uint64_t
name|gpa
parameter_list|,
name|uint64_t
modifier|*
name|rval
parameter_list|,
name|int
name|size
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

