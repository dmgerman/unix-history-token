begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * dns64/dns64.h - DNS64 module  *  * Copyright (c) 2009, ViagÃ©nie. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a module that performs DNS64 query processing.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DNS64_DNS64_H
end_ifndef

begin_define
define|#
directive|define
name|DNS64_DNS64_H
end_define

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_comment
comment|/**  * Get the dns64 function block.  * @return: function block with function pointers to dns64 methods.  */
end_comment

begin_function_decl
name|struct
name|module_func_block
modifier|*
name|dns64_get_funcblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** dns64 init */
end_comment

begin_function_decl
name|int
name|dns64_init
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** dns64 deinit */
end_comment

begin_function_decl
name|void
name|dns64_deinit
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** dns64 operate on a query */
end_comment

begin_function_decl
name|void
name|dns64_operate
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|enum
name|module_ev
name|event
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|outbound
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dns64_inform_super
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|super
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** dns64 cleanup query state */
end_comment

begin_function_decl
name|void
name|dns64_clear
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** dns64 alloc size routine */
end_comment

begin_function_decl
name|size_t
name|dns64_get_mem
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DNS64_DNS64_H */
end_comment

end_unit

