begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Matthew N. Dodd<winter@jurai.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|smapi_softc
block|{
name|dev_t
name|cdev
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|u_int32_t
name|smapi32_entry
decl_stmt|;
name|struct
name|smapi_bios_header
modifier|*
name|header
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|u_long
name|smapi32_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
name|smapi32_segment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|devclass_t
name|smapi_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|smapi_attach
parameter_list|(
name|struct
name|smapi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|smapi_detach
parameter_list|(
name|struct
name|smapi_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smapi32
parameter_list|(
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smapi32_new
parameter_list|(
name|u_long
parameter_list|,
name|u_short
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|,
name|struct
name|smapi_bios_parameter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

