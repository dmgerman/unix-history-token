begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__IB_CM_TYPES_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__IB_CM_TYPES_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__WIN__
end_ifndef

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !__cplusplus */
end_comment

begin_define
define|#
directive|define
name|BEGIN_C_DECLS
end_define

begin_define
define|#
directive|define
name|END_C_DECLS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/*  * Defines known Communication management class versions  */
end_comment

begin_define
define|#
directive|define
name|IB_MCLASS_CM_VER_2
value|2
end_define

begin_define
define|#
directive|define
name|IB_MCLASS_CM_VER_1
value|1
end_define

begin_comment
comment|/*  *	Defines the size of user available data in communication management MADs  */
end_comment

begin_define
define|#
directive|define
name|IB_REQ_PDATA_SIZE_VER2
value|92
end_define

begin_define
define|#
directive|define
name|IB_MRA_PDATA_SIZE_VER2
value|222
end_define

begin_define
define|#
directive|define
name|IB_REJ_PDATA_SIZE_VER2
value|148
end_define

begin_define
define|#
directive|define
name|IB_REP_PDATA_SIZE_VER2
value|196
end_define

begin_define
define|#
directive|define
name|IB_RTU_PDATA_SIZE_VER2
value|224
end_define

begin_define
define|#
directive|define
name|IB_LAP_PDATA_SIZE_VER2
value|168
end_define

begin_define
define|#
directive|define
name|IB_APR_PDATA_SIZE_VER2
value|148
end_define

begin_define
define|#
directive|define
name|IB_DREQ_PDATA_SIZE_VER2
value|220
end_define

begin_define
define|#
directive|define
name|IB_DREP_PDATA_SIZE_VER2
value|224
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REQ_PDATA_SIZE_VER2
value|216
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REP_PDATA_SIZE_VER2
value|136
end_define

begin_define
define|#
directive|define
name|IB_REQ_PDATA_SIZE_VER1
value|92
end_define

begin_define
define|#
directive|define
name|IB_MRA_PDATA_SIZE_VER1
value|222
end_define

begin_define
define|#
directive|define
name|IB_REJ_PDATA_SIZE_VER1
value|148
end_define

begin_define
define|#
directive|define
name|IB_REP_PDATA_SIZE_VER1
value|204
end_define

begin_define
define|#
directive|define
name|IB_RTU_PDATA_SIZE_VER1
value|224
end_define

begin_define
define|#
directive|define
name|IB_LAP_PDATA_SIZE_VER1
value|168
end_define

begin_define
define|#
directive|define
name|IB_APR_PDATA_SIZE_VER1
value|151
end_define

begin_define
define|#
directive|define
name|IB_DREQ_PDATA_SIZE_VER1
value|220
end_define

begin_define
define|#
directive|define
name|IB_DREP_PDATA_SIZE_VER1
value|224
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REQ_PDATA_SIZE_VER1
value|216
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REP_PDATA_SIZE_VER1
value|140
end_define

begin_define
define|#
directive|define
name|IB_ARI_SIZE
value|72
end_define

begin_comment
comment|// redefine
end_comment

begin_define
define|#
directive|define
name|IB_APR_INFO_SIZE
value|72
end_define

begin_comment
comment|/****d* Access Layer/ib_rej_status_t * NAME *	ib_rej_status_t * * DESCRIPTION *	Rejection reasons. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|ib_net16_t
name|ib_rej_status_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_cm_rej, ib_cm_rej_rec_t * * SOURCE */
end_comment

begin_define
define|#
directive|define
name|IB_REJ_INSUF_QP
value|CL_HTON16(1)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INSUF_EEC
value|CL_HTON16(2)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INSUF_RESOURCES
value|CL_HTON16(3)
end_define

begin_define
define|#
directive|define
name|IB_REJ_TIMEOUT
value|CL_HTON16(4)
end_define

begin_define
define|#
directive|define
name|IB_REJ_UNSUPPORTED
value|CL_HTON16(5)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_COMM_ID
value|CL_HTON16(6)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_COMM_INSTANCE
value|CL_HTON16(7)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_SID
value|CL_HTON16(8)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_XPORT
value|CL_HTON16(9)
end_define

begin_define
define|#
directive|define
name|IB_REJ_STALE_CONN
value|CL_HTON16(10)
end_define

begin_define
define|#
directive|define
name|IB_REJ_RDC_NOT_EXIST
value|CL_HTON16(11)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_GID
value|CL_HTON16(12)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_LID
value|CL_HTON16(13)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_SL
value|CL_HTON16(14)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_TRAFFIC_CLASS
value|CL_HTON16(15)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_HOP_LIMIT
value|CL_HTON16(16)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_PKT_RATE
value|CL_HTON16(17)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_GID
value|CL_HTON16(18)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_LID
value|CL_HTON16(19)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_SL
value|CL_HTON16(20)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_TRAFFIC_CLASS
value|CL_HTON16(21)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_HOP_LIMIT
value|CL_HTON16(22)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_PKT_RATE
value|CL_HTON16(23)
end_define

begin_define
define|#
directive|define
name|IB_REJ_PORT_REDIRECT
value|CL_HTON16(24)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_MTU
value|CL_HTON16(26)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INSUFFICIENT_RESP_RES
value|CL_HTON16(27)
end_define

begin_define
define|#
directive|define
name|IB_REJ_USER_DEFINED
value|CL_HTON16(28)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_RNR_RETRY
value|CL_HTON16(29)
end_define

begin_define
define|#
directive|define
name|IB_REJ_DUPLICATE_LOCAL_COMM_ID
value|CL_HTON16(30)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_CLASS_VER
value|CL_HTON16(31)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_FLOW_LBL
value|CL_HTON16(32)
end_define

begin_define
define|#
directive|define
name|IB_REJ_INVALID_ALT_FLOW_LBL
value|CL_HTON16(33)
end_define

begin_define
define|#
directive|define
name|IB_REJ_SERVICE_HANDOFF
value|CL_HTON16(65535)
end_define

begin_comment
comment|/******/
end_comment

begin_comment
comment|/****d* Access Layer/ib_apr_status_t * NAME *	ib_apr_status_t * * DESCRIPTION *	Automatic path migration status information. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|ib_apr_status_t
typedef|;
end_typedef

begin_comment
comment|/* * SEE ALSO *	ib_cm_apr, ib_cm_apr_rec_t * * SOURCE  */
end_comment

begin_define
define|#
directive|define
name|IB_AP_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_COMM_ID
value|1
end_define

begin_define
define|#
directive|define
name|IB_AP_UNSUPPORTED
value|2
end_define

begin_define
define|#
directive|define
name|IB_AP_REJECT
value|3
end_define

begin_define
define|#
directive|define
name|IB_AP_REDIRECT
value|4
end_define

begin_define
define|#
directive|define
name|IB_AP_IS_CURRENT
value|5
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_QPN_EECN
value|6
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_LID
value|7
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_GID
value|8
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_FLOW_LBL
value|9
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_TCLASS
value|10
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_HOP_LIMIT
value|11
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_PKT_RATE
value|12
end_define

begin_define
define|#
directive|define
name|IB_AP_INVALID_SL
value|13
end_define

begin_comment
comment|/******/
end_comment

begin_comment
comment|/****d* Access Layer/ib_cm_cap_mask_t * NAME *	ib_cm_cap_mask_t * * DESCRIPTION *	Capability mask values in ClassPortInfo. * * SYNOPSIS */
end_comment

begin_define
define|#
directive|define
name|IB_CM_RELIABLE_CONN_CAPABLE
value|CL_HTON16(9)
end_define

begin_define
define|#
directive|define
name|IB_CM_RELIABLE_DGRM_CAPABLE
value|CL_HTON16(10)
end_define

begin_define
define|#
directive|define
name|IB_CM_RDGRM_CAPABLE
value|CL_HTON16(11)
end_define

begin_define
define|#
directive|define
name|IB_CM_UNRELIABLE_CONN_CAPABLE
value|CL_HTON16(12)
end_define

begin_define
define|#
directive|define
name|IB_CM_SIDR_CAPABLE
value|CL_HTON16(13)
end_define

begin_comment
comment|/* * SEE ALSO *	ib_cm_rep, ib_class_port_info_t * * SOURCE * *******/
end_comment

begin_comment
comment|/*  *	Service ID resolution status  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|ib_sidr_status_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IB_SIDR_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|IB_SIDR_UNSUPPORTED
value|1
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REJECT
value|2
end_define

begin_define
define|#
directive|define
name|IB_SIDR_NO_QP
value|3
end_define

begin_define
define|#
directive|define
name|IB_SIDR_REDIRECT
value|4
end_define

begin_define
define|#
directive|define
name|IB_SIDR_UNSUPPORTED_VER
value|5
end_define

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ndef __WIN__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IB_CM_TYPES_H__ */
end_comment

end_unit

