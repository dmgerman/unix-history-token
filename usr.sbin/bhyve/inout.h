begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INOUT_H_
end_ifndef

begin_define
define|#
directive|define
name|_INOUT_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_struct_decl
struct_decl|struct
name|vmctx
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vm_exit
struct_decl|;
end_struct_decl

begin_comment
comment|/* Handler return values. */
end_comment

begin_define
define|#
directive|define
name|INOUT_ERROR
value|-1
end_define

begin_define
define|#
directive|define
name|INOUT_OK
value|0
end_define

begin_define
define|#
directive|define
name|INOUT_RESTART
value|1
end_define

begin_define
define|#
directive|define
name|INOUT_RESET
value|2
end_define

begin_define
define|#
directive|define
name|INOUT_POWEROFF
value|3
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|inout_func_t
function_decl|)
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|int
name|in
parameter_list|,
name|int
name|port
parameter_list|,
name|int
name|bytes
parameter_list|,
name|uint32_t
modifier|*
name|eax
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|inout_port
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|port
decl_stmt|;
name|int
name|size
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|inout_func_t
name|handler
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOPORT_F_IN
value|0x1
end_define

begin_define
define|#
directive|define
name|IOPORT_F_OUT
value|0x2
end_define

begin_define
define|#
directive|define
name|IOPORT_F_INOUT
value|(IOPORT_F_IN | IOPORT_F_OUT)
end_define

begin_comment
comment|/*  * The following flags are used internally and must not be used by  * device models.  */
end_comment

begin_define
define|#
directive|define
name|IOPORT_F_DEFAULT
value|0x80000000
end_define

begin_comment
comment|/* claimed by default handler */
end_comment

begin_define
define|#
directive|define
name|INOUT_PORT
parameter_list|(
name|name
parameter_list|,
name|port
parameter_list|,
name|flags
parameter_list|,
name|handler
parameter_list|)
define|\
value|static struct inout_port __CONCAT(__inout_port, __LINE__) = {	\ 		#name,							\ 		(port),							\ 		1,							\ 		(flags),						\ 		(handler),						\ 		0							\ 	};								\ 	DATA_SET(inout_port_set, __CONCAT(__inout_port, __LINE__))
end_define

begin_function_decl
name|void
name|init_inout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emulate_inout
parameter_list|(
name|struct
name|vmctx
modifier|*
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|struct
name|vm_exit
modifier|*
name|vmexit
parameter_list|,
name|int
name|strict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_inout
parameter_list|(
name|struct
name|inout_port
modifier|*
name|iop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unregister_inout
parameter_list|(
name|struct
name|inout_port
modifier|*
name|iop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_bvmcons
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
comment|/* _INOUT_H_ */
end_comment

end_unit

