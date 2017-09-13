begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Netflix, Inc  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CAM_NVME_NVME_ALL_H
end_ifndef

begin_define
define|#
directive|define
name|CAM_NVME_NVME_ALL_H
value|1
end_define

begin_include
include|#
directive|include
file|<dev/nvme/nvme.h>
end_include

begin_struct_decl
struct_decl|struct
name|ccb_nvmeio
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|NVME_REV_1
value|1
end_define

begin_comment
comment|/* Supports NVMe 1.2 or earlier */
end_comment

begin_function_decl
name|void
name|nvme_ns_cmd
parameter_list|(
name|struct
name|ccb_nvmeio
modifier|*
name|nvmeio
parameter_list|,
name|uint8_t
name|cmd
parameter_list|,
name|uint32_t
name|nsid
parameter_list|,
name|uint32_t
name|cdw10
parameter_list|,
name|uint32_t
name|cdw11
parameter_list|,
name|uint32_t
name|cdw12
parameter_list|,
name|uint32_t
name|cdw13
parameter_list|,
name|uint32_t
name|cdw14
parameter_list|,
name|uint32_t
name|cdw15
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nvme_identify_match
parameter_list|(
name|caddr_t
name|identbuffer
parameter_list|,
name|caddr_t
name|table_entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|nvme_print_ident
parameter_list|(
specifier|const
name|struct
name|nvme_controller_data
modifier|*
parameter_list|,
specifier|const
name|struct
name|nvme_namespace_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nvme_op_string
parameter_list|(
specifier|const
name|struct
name|nvme_command
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|nvme_cmd_string
parameter_list|(
specifier|const
name|struct
name|nvme_command
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|nvme_get_identify_cntrl
parameter_list|(
name|struct
name|cam_periph
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|nvme_get_identify_ns
parameter_list|(
name|struct
name|cam_periph
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAM_NVME_NVME_ALL_H */
end_comment

end_unit

