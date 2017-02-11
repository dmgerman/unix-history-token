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
name|_IXL_PF_IOV_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXL_PF_IOV_H_
end_define

begin_include
include|#
directive|include
file|"ixl_pf.h"
end_include

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<sys/iov_schema.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pci_iov.h>
end_include

begin_define
define|#
directive|define
name|IXL_GLOBAL_VF_NUM
parameter_list|(
name|hw
parameter_list|,
name|vf
parameter_list|)
define|\
value|(vf->vf_num + hw->func_caps.vf_base_id)
end_define

begin_comment
comment|/* Public functions */
end_comment

begin_comment
comment|/*  * These three are DEVMETHODs required for SR-IOV PF support.  */
end_comment

begin_function_decl
name|int
name|ixl_iov_init
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|num_vfs
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_iov_uninit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixl_add_vf
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|vfnum
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The standard PF driver needs to call these during normal execution when  * SR-IOV mode is active.  */
end_comment

begin_function_decl
name|void
name|ixl_initialize_sriov
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
name|ixl_handle_vf_msg
parameter_list|(
name|struct
name|ixl_pf
modifier|*
name|pf
parameter_list|,
name|struct
name|i40e_arq_event_info
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixl_handle_vflr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|pending
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXL_PF_IOV_H_ */
end_comment

end_unit

