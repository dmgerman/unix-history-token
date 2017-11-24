begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2006 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2011 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of Dispatcher message values.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MSGDEF_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MSGDEF_H_
end_define

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

begin_decl_stmt
name|BEGIN_C_DECLS
comment|/****h* OpenSM/Dispatcher Messages * NAME *	Dispatcher Messages * * DESCRIPTION *	These constants define the messages sent between OpenSM controllers *	attached to the Dispatcher. * *	Each message description contains the following information: *	Sent by: which controller(s) send this message *	Received by: which controller receives this message *	Delivery notice: Indicates if the sender requires confirmation *		that the message has been delivered.  Typically a "yes" here *		means that some resources associated with sending the *		message must be freed. * * AUTHOR *	Steve King, Intel * *********/
comment|/****s* OpenSM: Dispatcher Messages/OSM_MSG_MAD_NODE_INFO * NAME *	OSM_MSG_MAD_NODE_INFO * * DESCRIPTION *	Message for received NodeInfo MADs. * * NOTES *	Sent by:			osm_mad_ctrl_t *	Received by:			osm_ni_rcv_ctrl_t *	Delivery notice:		yes * * ***********/
comment|/****s* OpenSM: Dispatcher Messages/OSM_MSG_MAD_PORT_INFO * NAME *	OSM_MSG_MAD_PORT_INFO * * DESCRIPTION *	Message for received PortInfo MADs. * * NOTES *	Sent by:			osm_mad_ctrl_t *	Received by:			osm_pi_rcv_ctrl_t *	Delivery notice:		yes * * ***********/
comment|/****s* OpenSM: Dispatcher Messages/OSM_MSG_MAD_SWITCH_INFO * NAME *	OSM_MSG_MAD_SWITCH_INFO * * DESCRIPTION *	Message for received SwitchInfo MADs. * * NOTES *	Sent by:			osm_mad_ctrl_t *	Received by:			osm_si_rcv_ctrl_t *	Delivery notice:		yes * ***********/
comment|/****s* OpenSM: Dispatcher Messages/OSM_MSG_MAD_NODE_DESC * NAME *	OSM_MSG_MAD_NODE_DESC * * DESCRIPTION *	Message for received NodeDescription MADs. * * NOTES *	Sent by:			osm_mad_ctrl_t *	Received by:			osm_nd_rcv_ctrl_t *	Delivery notice:		yes * * SOURCE ***********/
name|enum
type|{
name|OSM_MSG_NONE
init|=
literal|0
decl_stmt|,
name|OSM_MSG_MAD_NODE_INFO
decl_stmt|,
name|OSM_MSG_MAD_PORT_INFO
decl_stmt|,
name|OSM_MSG_MAD_SWITCH_INFO
decl_stmt|,
name|OSM_MSG_MAD_GUID_INFO
decl_stmt|,
name|OSM_MSG_MAD_NODE_DESC
decl_stmt|,
name|OSM_MSG_MAD_NODE_RECORD
decl_stmt|,
name|OSM_MSG_MAD_PORTINFO_RECORD
decl_stmt|,
name|OSM_MSG_MAD_SERVICE_RECORD
decl_stmt|,
name|OSM_MSG_MAD_PATH_RECORD
decl_stmt|,
name|OSM_MSG_MAD_MCMEMBER_RECORD
decl_stmt|,
name|OSM_MSG_MAD_LINK_RECORD
decl_stmt|,
name|OSM_MSG_MAD_SMINFO_RECORD
decl_stmt|,
name|OSM_MSG_MAD_CLASS_PORT_INFO
decl_stmt|,
name|OSM_MSG_MAD_INFORM_INFO
decl_stmt|,
name|OSM_MSG_MAD_LFT_RECORD
decl_stmt|,
name|OSM_MSG_MAD_LFT
decl_stmt|,
name|OSM_MSG_MAD_SM_INFO
decl_stmt|,
name|OSM_MSG_MAD_NOTICE
decl_stmt|,
name|OSM_MSG_LIGHT_SWEEP_FAIL
decl_stmt|,
name|OSM_MSG_MAD_MFT
decl_stmt|,
name|OSM_MSG_MAD_PKEY_TBL_RECORD
decl_stmt|,
name|OSM_MSG_MAD_VL_ARB_RECORD
decl_stmt|,
name|OSM_MSG_MAD_SLVL_TBL_RECORD
decl_stmt|,
name|OSM_MSG_MAD_PKEY
decl_stmt|,
name|OSM_MSG_MAD_VL_ARB
decl_stmt|,
name|OSM_MSG_MAD_SLVL
decl_stmt|,
name|OSM_MSG_MAD_GUIDINFO_RECORD
decl_stmt|,
name|OSM_MSG_MAD_INFORM_INFO_RECORD
decl_stmt|,
name|OSM_MSG_MAD_SWITCH_INFO_RECORD
decl_stmt|,
name|OSM_MSG_MAD_MFT_RECORD
decl_stmt|,
if|#
directive|if
name|defined
argument_list|(
name|VENDOR_RMPP_SUPPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|DUAL_SIDED_RMPP
argument_list|)
name|OSM_MSG_MAD_MULTIPATH_RECORD
decl_stmt|,
endif|#
directive|endif
name|OSM_MSG_MAD_PORT_COUNTERS
decl_stmt|,
name|OSM_MSG_MAD_MLNX_EXT_PORT_INFO
decl_stmt|,
name|OSM_MSG_MAD_CC
decl_stmt|,
name|OSM_MSG_MAX
end_decl_stmt

begin_macro
unit|};
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MSGDEF_H_ */
end_comment

end_unit

