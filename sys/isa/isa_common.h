begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Parts of the ISA bus implementation common to all architectures.  *  * Drivers must not depend on information in this file as it can change  * without notice.  */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ISADEV
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * The structure used to attach devices to the isa bus.  */
end_comment

begin_struct
struct|struct
name|isa_device
block|{
name|struct
name|resource_list
name|id_resources
decl_stmt|;
name|int
name|id_flags
decl_stmt|;
name|u_int32_t
name|id_vendorid
decl_stmt|;
comment|/* pnp vendor id */
name|u_int32_t
name|id_serial
decl_stmt|;
comment|/* pnp serial */
name|u_int32_t
name|id_logicalid
decl_stmt|;
comment|/* pnp logical device id */
name|u_int32_t
name|id_compatid
decl_stmt|;
comment|/* pnp compat device id */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEVTOISA
parameter_list|(
name|dev
parameter_list|)
value|((struct isa_device *) device_get_ivars(dev))
end_define

begin_comment
comment|/*  * These functions are architecture dependant.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|isa_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|resource
modifier|*
name|isa_alloc_resource
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isa_release_resource
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX alphe declares these elsewhere */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__alpha__
end_ifndef

begin_function_decl
specifier|extern
name|int
name|isa_setup_intr
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|int
name|flags
parameter_list|,
name|void
function_decl|(
modifier|*
name|ihand
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isa_teardown_intr
parameter_list|(
name|device_t
name|bus
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

