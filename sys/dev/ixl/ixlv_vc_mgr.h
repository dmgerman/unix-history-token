begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2014, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXLV_VC_MGR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXLV_VC_MGR_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct_decl
struct_decl|struct
name|ixl_vc_cmd
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
name|ixl_vc_callback_t
parameter_list|(
name|struct
name|ixl_vc_cmd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|i40e_status_code
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|IXLV_VC_CMD_FLAG_BUSY
value|0x0001
end_define

begin_struct
struct|struct
name|ixl_vc_cmd
block|{
name|uint32_t
name|request
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|ixl_vc_callback_t
modifier|*
name|callback
decl_stmt|;
name|void
modifier|*
name|arg
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ixl_vc_cmd
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixl_vc_mgr
block|{
name|struct
name|ixlv_sc
modifier|*
name|sc
decl_stmt|;
name|struct
name|ixl_vc_cmd
modifier|*
name|current
decl_stmt|;
name|struct
name|callout
name|callout
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ixl_vc_cmd
argument_list|)
name|pending
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXLV_VC_TIMEOUT
value|(2 * hz)
end_define

begin_function_decl
name|void
name|ixl_vc_init_mgr
parameter_list|(
name|struct
name|ixlv_sc
modifier|*
parameter_list|,
name|struct
name|ixl_vc_mgr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_vc_enqueue
parameter_list|(
name|struct
name|ixl_vc_mgr
modifier|*
parameter_list|,
name|struct
name|ixl_vc_cmd
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|ixl_vc_callback_t
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_vc_flush
parameter_list|(
name|struct
name|ixl_vc_mgr
modifier|*
name|mgr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

