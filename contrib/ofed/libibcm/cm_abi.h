begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INFINIBAND_CM_ABI_H
end_ifndef

begin_define
define|#
directive|define
name|INFINIBAND_CM_ABI_H
end_define

begin_warning
warning|#
directive|warning
literal|"This header is obsolete, use rdma/ib_user_cm.h instead"
end_warning

begin_include
include|#
directive|include
file|<rdma/ib_user_cm.h>
end_include

begin_define
define|#
directive|define
name|cm_abi_cmd_hdr
value|ib_ucm_cmd_hdr
end_define

begin_define
define|#
directive|define
name|cm_abi_create_id
value|ib_ucm_create_id
end_define

begin_define
define|#
directive|define
name|cm_abi_create_id_resp
value|ib_ucm_create_id_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_destroy_id
value|ib_ucm_destroy_id
end_define

begin_define
define|#
directive|define
name|cm_abi_destroy_id_resp
value|ib_ucm_destroy_id_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_attr_id
value|ib_ucm_attr_id
end_define

begin_define
define|#
directive|define
name|cm_abi_attr_id_resp
value|ib_ucm_attr_id_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_init_qp_attr
value|ib_ucm_init_qp_attr
end_define

begin_define
define|#
directive|define
name|cm_abi_listen
value|ib_ucm_listen
end_define

begin_define
define|#
directive|define
name|cm_abi_establish
value|ib_ucm_establish
end_define

begin_define
define|#
directive|define
name|cm_abi_notify
value|ib_ucm_notify
end_define

begin_define
define|#
directive|define
name|cm_abi_private_data
value|ib_ucm_private_data
end_define

begin_define
define|#
directive|define
name|cm_abi_req
value|ib_ucm_req
end_define

begin_define
define|#
directive|define
name|cm_abi_rep
value|ib_ucm_rep
end_define

begin_define
define|#
directive|define
name|cm_abi_info
value|ib_ucm_info
end_define

begin_define
define|#
directive|define
name|cm_abi_mra
value|ib_ucm_mra
end_define

begin_define
define|#
directive|define
name|cm_abi_lap
value|ib_ucm_lap
end_define

begin_define
define|#
directive|define
name|cm_abi_sidr_req
value|ib_ucm_sidr_req
end_define

begin_define
define|#
directive|define
name|cm_abi_sidr_rep
value|ib_ucm_sidr_rep
end_define

begin_define
define|#
directive|define
name|cm_abi_event_get
value|ib_ucm_event_get
end_define

begin_define
define|#
directive|define
name|cm_abi_req_event_resp
value|ib_ucm_req_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_rep_event_resp
value|ib_ucm_rep_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_rej_event_resp
value|ib_ucm_rej_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_mra_event_resp
value|ib_ucm_mra_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_lap_event_resp
value|ib_ucm_lap_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_apr_event_resp
value|ib_ucm_apr_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_sidr_req_event_resp
value|ib_ucm_sidr_req_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_sidr_rep_event_resp
value|ib_ucm_sidr_rep_event_resp
end_define

begin_define
define|#
directive|define
name|cm_abi_event_resp
value|ib_ucm_event_resp
end_define

begin_define
define|#
directive|define
name|CM_ABI_PRES_DATA
value|IB_UCM_PRES_DATA
end_define

begin_define
define|#
directive|define
name|CM_ABI_PRES_INFO
value|IB_UCM_PRES_INFO
end_define

begin_define
define|#
directive|define
name|CM_ABI_PRES_PRIMARY
value|IB_UCM_PRES_PRIMARY
end_define

begin_define
define|#
directive|define
name|CM_ABI_PRES_ALTERNATE
value|IB_UCM_PRES_ALTERNATE
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

