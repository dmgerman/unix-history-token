begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: dispatch.h,v 1.12 2015/01/19 20:07:45 markus Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DISPATCH_H
end_ifndef

begin_define
define|#
directive|define
name|DISPATCH_H
end_define

begin_define
define|#
directive|define
name|DISPATCH_MAX
value|255
end_define

begin_enum
enum|enum
block|{
name|DISPATCH_BLOCK
block|,
name|DISPATCH_NONBLOCK
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|ssh
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|dispatch_fn
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|dispatch_protocol_error
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dispatch_protocol_ignore
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_dispatch_init
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_dispatch_set
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|int
parameter_list|,
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_dispatch_range
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|dispatch_fn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_dispatch_run
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|volatile
name|sig_atomic_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_dispatch_run_fatal
parameter_list|(
name|struct
name|ssh
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|volatile
name|sig_atomic_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|dispatch_init
parameter_list|(
name|dflt
parameter_list|)
define|\
value|ssh_dispatch_init(active_state, (dflt))
end_define

begin_define
define|#
directive|define
name|dispatch_range
parameter_list|(
name|from
parameter_list|,
name|to
parameter_list|,
name|fn
parameter_list|)
define|\
value|ssh_dispatch_range(active_state, (from), (to), (fn))
end_define

begin_define
define|#
directive|define
name|dispatch_set
parameter_list|(
name|type
parameter_list|,
name|fn
parameter_list|)
define|\
value|ssh_dispatch_set(active_state, (type), (fn))
end_define

begin_define
define|#
directive|define
name|dispatch_run
parameter_list|(
name|mode
parameter_list|,
name|done
parameter_list|,
name|ctxt
parameter_list|)
define|\
value|ssh_dispatch_run_fatal(active_state, (mode), (done), (ctxt))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

