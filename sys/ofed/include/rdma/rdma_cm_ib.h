begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Intel Corporation.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RDMA_CM_IB_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|RDMA_CM_IB_H
end_define

begin_include
include|#
directive|include
file|<rdma/rdma_cm.h>
end_include

begin_comment
comment|/**  * rdma_set_ib_paths - Manually sets the path records used to establish a  *   connection.  * @id: Connection identifier associated with the request.  * @path_rec: Reference to the path record  *  * This call permits a user to specify routing information for rdma_cm_id's  * bound to Infiniband devices.  It is called on the client side of a  * connection and replaces the call to rdma_resolve_route.  */
end_comment

begin_function_decl
name|int
name|rdma_set_ib_paths
parameter_list|(
name|struct
name|rdma_cm_id
modifier|*
name|id
parameter_list|,
name|struct
name|ib_sa_path_rec
modifier|*
name|path_rec
parameter_list|,
name|int
name|num_paths
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global qkey for UDP QPs and multicast groups. */
end_comment

begin_define
define|#
directive|define
name|RDMA_UDP_QKEY
value|0x01234567
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RDMA_CM_IB_H */
end_comment

end_unit

