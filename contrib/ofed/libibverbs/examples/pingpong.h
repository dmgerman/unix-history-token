begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Cisco Systems.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IBV_PINGPONG_H
end_ifndef

begin_define
define|#
directive|define
name|IBV_PINGPONG_H
end_define

begin_include
include|#
directive|include
file|<infiniband/verbs.h>
end_include

begin_function_decl
name|enum
name|ibv_mtu
name|pp_mtu_to_enum
parameter_list|(
name|int
name|mtu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pp_get_port_info
parameter_list|(
name|struct
name|ibv_context
modifier|*
name|context
parameter_list|,
name|int
name|port
parameter_list|,
name|struct
name|ibv_port_attr
modifier|*
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|wire_gid_to_gid
parameter_list|(
specifier|const
name|char
modifier|*
name|wgid
parameter_list|,
name|union
name|ibv_gid
modifier|*
name|gid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gid_to_wire_gid
parameter_list|(
specifier|const
name|union
name|ibv_gid
modifier|*
name|gid
parameter_list|,
name|char
name|wgid
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IBV_PINGPONG_H */
end_comment

end_unit

