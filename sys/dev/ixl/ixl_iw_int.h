begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXL_IW_INT_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXL_IW_INT_H_
end_define

begin_enum
enum|enum
name|ixl_iw_pf_state
block|{
name|IXL_IW_PF_STATE_OFF
block|,
name|IXL_IW_PF_STATE_ON
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ixl_iw_pf_entry_state
block|{
name|enum
name|ixl_iw_pf_state
name|pf
decl_stmt|;
name|enum
name|ixl_iw_pf_state
name|iw_scheduled
decl_stmt|;
name|enum
name|ixl_iw_pf_state
name|iw_current
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ixl_iw_pf_entry
block|{
name|LIST_ENTRY
argument_list|(
argument|ixl_iw_pf_entry
argument_list|)
name|node
expr_stmt|;
name|struct
name|ixl_pf
modifier|*
name|pf
decl_stmt|;
name|struct
name|ixl_iw_pf_entry_state
name|state
decl_stmt|;
name|struct
name|ixl_iw_pf
name|pf_info
decl_stmt|;
name|struct
name|task
name|iw_task
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|ixl_iw_pfs_head
argument_list|,
name|ixl_iw_pf_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|ixl_iw_state
block|{
name|struct
name|ixl_iw_ops
modifier|*
name|ops
decl_stmt|;
name|bool
name|registered
decl_stmt|;
name|struct
name|ixl_iw_pfs_head
name|pfs
decl_stmt|;
name|struct
name|mtx
name|mtx
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|ixl_iw_pf_init
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_iw_pf_stop
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_iw_pf_attach
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_iw_pf_detach
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXL_IW_INT_H_ */
end_comment

end_unit

