begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Mellanox Technologies Ltd.  All rights reserved.  * Copyright (c) 2004 Infinicon Corporation.  All rights reserved.  * Copyright (c) 2004 Intel Corporation.  All rights reserved.  * Copyright (c) 2004 Topspin Corporation.  All rights reserved.  * Copyright (c) 2004 Voltaire Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AGENT_H_
end_ifndef

begin_define
define|#
directive|define
name|__AGENT_H_
end_define

begin_include
include|#
directive|include
file|<linux/err.h>
end_include

begin_include
include|#
directive|include
file|<rdma/ib_mad.h>
end_include

begin_function_decl
specifier|extern
name|int
name|ib_agent_port_open
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|int
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ib_agent_port_close
parameter_list|(
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|int
name|port_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|agent_send_response
parameter_list|(
specifier|const
name|struct
name|ib_mad_hdr
modifier|*
name|mad_hdr
parameter_list|,
specifier|const
name|struct
name|ib_grh
modifier|*
name|grh
parameter_list|,
specifier|const
name|struct
name|ib_wc
modifier|*
name|wc
parameter_list|,
specifier|const
name|struct
name|ib_device
modifier|*
name|device
parameter_list|,
name|int
name|port_num
parameter_list|,
name|int
name|qpn
parameter_list|,
name|size_t
name|resp_mad_len
parameter_list|,
name|bool
name|opa
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AGENT_H_ */
end_comment

end_unit

