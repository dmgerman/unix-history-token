begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEVENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEVENT_H_
end_define

begin_enum
enum|enum
name|ev_type
block|{
name|EVF_READ
block|,
name|EVF_WRITE
block|,
name|EVF_TIMER
block|,
name|EVF_SIGNAL
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|mevent
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|mevent
modifier|*
name|mevent_add
parameter_list|(
name|int
name|fd
parameter_list|,
name|enum
name|ev_type
name|type
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|enum
name|ev_type
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mevent_enable
parameter_list|(
name|struct
name|mevent
modifier|*
name|evp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mevent_disable
parameter_list|(
name|struct
name|mevent
modifier|*
name|evp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mevent_delete
parameter_list|(
name|struct
name|mevent
modifier|*
name|evp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mevent_delete_close
parameter_list|(
name|struct
name|mevent
modifier|*
name|evp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mevent_dispatch
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
comment|/* _MEVENT_H_ */
end_comment

end_unit

