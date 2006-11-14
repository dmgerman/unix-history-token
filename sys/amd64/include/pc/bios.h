begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Michael Smith  * Copyright (c) 1998 Jonathan Lemon  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PC_BIOS_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PC_BIOS_H_
end_define

begin_function_decl
specifier|extern
name|u_int32_t
name|bios_sigsearch
parameter_list|(
name|u_int32_t
name|start
parameter_list|,
name|u_char
modifier|*
name|sig
parameter_list|,
name|int
name|siglen
parameter_list|,
name|int
name|paralen
parameter_list|,
name|int
name|sigofs
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BIOS_PADDRTOVADDR
parameter_list|(
name|x
parameter_list|)
value|((x) + KERNBASE)
end_define

begin_define
define|#
directive|define
name|BIOS_VADDRTOPADDR
parameter_list|(
name|x
parameter_list|)
value|((x) - KERNBASE)
end_define

begin_comment
comment|/*  * Int 15:E820 'SMAP' structure  *  * XXX add constants for type  */
end_comment

begin_define
define|#
directive|define
name|SMAP_SIG
value|0x534D4150
end_define

begin_comment
comment|/* 'SMAP' */
end_comment

begin_struct
struct|struct
name|bios_smap
block|{
name|u_int64_t
name|base
decl_stmt|;
name|u_int64_t
name|length
decl_stmt|;
name|u_int32_t
name|type
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
specifier|const
name|u_char
modifier|*
name|bios_string
parameter_list|(
name|u_int
name|from
parameter_list|,
name|u_int
name|to
parameter_list|,
specifier|const
name|u_char
modifier|*
name|string
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_PC_BIOS_H_ */
end_comment

end_unit

