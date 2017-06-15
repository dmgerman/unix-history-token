begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Network Appliance, Inc. All rights reserved.  * Copyright (c) 2005 Open Grid Computing, Inc. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IWCM_H
end_ifndef

begin_define
define|#
directive|define
name|IWCM_H
end_define

begin_enum
enum|enum
name|iw_cm_state
block|{
name|IW_CM_STATE_IDLE
block|,
comment|/* unbound, inactive */
name|IW_CM_STATE_LISTEN
block|,
comment|/* listen waiting for connect */
name|IW_CM_STATE_CONN_RECV
block|,
comment|/* inbound waiting for user accept */
name|IW_CM_STATE_CONN_SENT
block|,
comment|/* outbound waiting for peer accept */
name|IW_CM_STATE_ESTABLISHED
block|,
comment|/* established */
name|IW_CM_STATE_CLOSING
block|,
comment|/* disconnect */
name|IW_CM_STATE_DESTROYING
comment|/* object being deleted */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|iwcm_id_private
block|{
name|struct
name|iw_cm_id
name|id
decl_stmt|;
name|enum
name|iw_cm_state
name|state
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|struct
name|ib_qp
modifier|*
name|qp
decl_stmt|;
name|struct
name|completion
name|destroy_comp
decl_stmt|;
name|wait_queue_head_t
name|connect_wait
decl_stmt|;
name|struct
name|list_head
name|work_list
decl_stmt|;
name|spinlock_t
name|lock
decl_stmt|;
name|atomic_t
name|refcount
decl_stmt|;
name|struct
name|list_head
name|work_free_list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IWCM_F_DROP_EVENTS
value|1
end_define

begin_define
define|#
directive|define
name|IWCM_F_CONNECT_WAIT
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IWCM_H */
end_comment

end_unit

