begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_SAPICVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_SAPICVAR_H_
end_define

begin_struct
struct|struct
name|sapic
block|{
name|int
name|sa_id
decl_stmt|;
comment|/* I/O SAPIC Id */
name|int
name|sa_base
decl_stmt|;
comment|/* ACPI vector base */
name|int
name|sa_limit
decl_stmt|;
comment|/* last ACPI vector handled here */
name|vm_offset_t
name|sa_registers
decl_stmt|;
comment|/* virtual address of sapic */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SAPIC_TRIGGER_EDGE
value|0
end_define

begin_define
define|#
directive|define
name|SAPIC_TRIGGER_LEVEL
value|1
end_define

begin_define
define|#
directive|define
name|SAPIC_POLARITY_HIGH
value|0
end_define

begin_define
define|#
directive|define
name|SAPIC_POLARITY_LOW
value|1
end_define

begin_function_decl
name|struct
name|sapic
modifier|*
name|sapic_create
parameter_list|(
name|int
name|id
parameter_list|,
name|int
name|base
parameter_list|,
name|u_int64_t
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sapic_enable
parameter_list|(
name|struct
name|sapic
modifier|*
name|sa
parameter_list|,
name|int
name|input
parameter_list|,
name|int
name|vector
parameter_list|,
name|int
name|trigger_mode
parameter_list|,
name|int
name|polarity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sapic_eoi
parameter_list|(
name|struct
name|sapic
modifier|*
name|sa
parameter_list|,
name|int
name|vector
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_function_decl
name|void
name|sapic_print
parameter_list|(
name|struct
name|sapic
modifier|*
name|sa
parameter_list|,
name|int
name|input
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_SAPICVAR_H_ */
end_comment

end_unit

