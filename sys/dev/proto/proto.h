begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_PROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_PROTO_H_
end_define

begin_define
define|#
directive|define
name|PROTO_RES_MAX
value|16
end_define

begin_define
define|#
directive|define
name|PROTO_RES_UNUSED
value|0
end_define

begin_define
define|#
directive|define
name|PROTO_RES_PCICFG
value|10
end_define

begin_struct
struct|struct
name|proto_res
block|{
name|int
name|r_type
decl_stmt|;
name|int
name|r_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_res
decl_stmt|;
name|u_long
name|r_size
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|cookie
decl_stmt|;
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
block|}
name|r_u
union|;
name|uintptr_t
name|r_opened
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|proto_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|struct
name|proto_res
name|sc_res
index|[
name|PROTO_RES_MAX
index|]
decl_stmt|;
name|int
name|sc_rescnt
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|proto_devclass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|proto_driver_name
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|proto_add_resource
parameter_list|(
name|struct
name|proto_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|struct
name|resource
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_PROTO_H_ */
end_comment

end_unit

