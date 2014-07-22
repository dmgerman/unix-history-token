begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ACPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_ACPI_H_
end_define

begin_define
define|#
directive|define
name|SCI_INT
value|9
end_define

begin_define
define|#
directive|define
name|SMI_CMD
value|0xb2
end_define

begin_define
define|#
directive|define
name|BHYVE_ACPI_ENABLE
value|0xa0
end_define

begin_define
define|#
directive|define
name|BHYVE_ACPI_DISABLE
value|0xa1
end_define

begin_define
define|#
directive|define
name|PM1A_EVT_ADDR
value|0x400
end_define

begin_define
define|#
directive|define
name|PM1A_CNT_ADDR
value|0x404
end_define

begin_define
define|#
directive|define
name|IO_PMTMR
value|0x408
end_define

begin_comment
comment|/* 4-byte i/o port for the timer */
end_comment

begin_struct_decl
struct_decl|struct
name|vmctx
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|acpi_build
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|ncpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_line
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_fixed_ioport
parameter_list|(
name|uint16_t
name|iobase
parameter_list|,
name|uint16_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_fixed_irq
parameter_list|(
name|uint8_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_fixed_mem32
parameter_list|(
name|uint32_t
name|base
parameter_list|,
name|uint32_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_indent
parameter_list|(
name|int
name|levels
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dsdt_unindent
parameter_list|(
name|int
name|levels
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sci_init
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ACPI_H_ */
end_comment

end_unit

