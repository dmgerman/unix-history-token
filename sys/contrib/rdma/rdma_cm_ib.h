begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2006 Intel Corporation.  All rights reserved.  *  * This Software is licensed under one of the following licenses:  *  * 1) under the terms of the "Common Public License 1.0" a copy of which is  *    available from the Open Source Initiative, see  *    http://www.opensource.org/licenses/cpl.php.  *  * 2) under the terms of the "The BSD License" a copy of which is  *    available from the Open Source Initiative, see  *    http://www.opensource.org/licenses/bsd-license.php.  *  * 3) under the terms of the "GNU General Public License (GPL) Version 2" a  *    copy of which is available from the Open Source Initiative, see  *    http://www.opensource.org/licenses/gpl-license.php.  *  * Licensee has the right to choose one of the above licenses.  *  * Redistributions of source code must retain the above copyright  * notice and one of the license notices.  *  * Redistributions in binary form must reproduce both the above copyright  * notice, one of the license notices in the documentation  * and/or other materials provided with the distribution.  *  * $FreeBSD$  */
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

