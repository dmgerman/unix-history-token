begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2012 Mellanox Technologies LTD. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_file_ids_enum.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_FILE_ID_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_FILE_ID_H_
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

begin_macro
name|BEGIN_C_DECLS
end_macro

begin_comment
comment|/****d* OpenSM: osm_file_ids_enum * NAME *	osm_file_ids_enum * * DESCRIPTION *	Enumerates all FILE_IDs used for logging support. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_file_ids_enum
block|{
name|OSM_FILE_MAIN_C
init|=
literal|0
block|,
name|OSM_FILE_CONSOLE_C
block|,
name|OSM_FILE_CONSOLE_IO_C
block|,
name|OSM_FILE_DB_FILES_C
block|,
name|OSM_FILE_DB_PACK_C
block|,
name|OSM_FILE_DROP_MGR_C
block|,
name|OSM_FILE_DUMP_C
block|,
name|OSM_FILE_EVENT_PLUGIN_C
block|,
name|OSM_FILE_GUID_INFO_RCV_C
block|,
name|OSM_FILE_GUID_MGR_C
block|,
name|OSM_FILE_HELPER_C
block|,
name|OSM_FILE_INFORM_C
block|,
name|OSM_FILE_LID_MGR_C
block|,
name|OSM_FILE_LIN_FWD_RCV_C
block|,
name|OSM_FILE_LINK_MGR_C
block|,
name|OSM_FILE_LOG_C
block|,
name|OSM_FILE_MAD_POOL_C
block|,
name|OSM_FILE_MCAST_FWD_RCV_C
block|,
name|OSM_FILE_MCAST_MGR_C
block|,
name|OSM_FILE_MCAST_TBL_C
block|,
name|OSM_FILE_MCM_PORT_C
block|,
name|OSM_FILE_MESH_C
block|,
name|OSM_FILE_MLNX_EXT_PORT_INFO_RCV_C
block|,
name|OSM_FILE_MTREE_C
block|,
name|OSM_FILE_MULTICAST_C
block|,
name|OSM_FILE_NODE_C
block|,
name|OSM_FILE_NODE_DESC_RCV_C
block|,
name|OSM_FILE_NODE_INFO_RCV_C
block|,
name|OSM_FILE_OPENSM_C
block|,
name|OSM_FILE_PERFMGR_C
block|,
name|OSM_FILE_PERFMGR_DB_C
block|,
name|OSM_FILE_PKEY_C
block|,
name|OSM_FILE_PKEY_MGR_C
block|,
name|OSM_FILE_PKEY_RCV_C
block|,
name|OSM_FILE_PORT_C
block|,
name|OSM_FILE_PORT_INFO_RCV_C
block|,
name|OSM_FILE_PRTN_C
block|,
name|OSM_FILE_PRTN_CONFIG_C
block|,
name|OSM_FILE_QOS_C
block|,
name|OSM_FILE_QOS_PARSER_L_L
block|,
name|OSM_FILE_QOS_PARSER_Y_Y
block|,
name|OSM_FILE_QOS_POLICY_C
block|,
name|OSM_FILE_REMOTE_SM_C
block|,
name|OSM_FILE_REQ_C
block|,
name|OSM_FILE_RESP_C
block|,
name|OSM_FILE_ROUTER_C
block|,
name|OSM_FILE_SA_C
block|,
name|OSM_FILE_SA_CLASS_PORT_INFO_C
block|,
name|OSM_FILE_SA_GUIDINFO_RECORD_C
block|,
name|OSM_FILE_SA_INFORMINFO_C
block|,
name|OSM_FILE_SA_LFT_RECORD_C
block|,
name|OSM_FILE_SA_LINK_RECORD_C
block|,
name|OSM_FILE_SA_MAD_CTRL_C
block|,
name|OSM_FILE_SA_MCMEMBER_RECORD_C
block|,
name|OSM_FILE_SA_MFT_RECORD_C
block|,
name|OSM_FILE_SA_MULTIPATH_RECORD_C
block|,
name|OSM_FILE_SA_NODE_RECORD_C
block|,
name|OSM_FILE_SA_PATH_RECORD_C
block|,
name|OSM_FILE_SA_PKEY_RECORD_C
block|,
name|OSM_FILE_SA_PORTINFO_RECORD_C
block|,
name|OSM_FILE_SA_SERVICE_RECORD_C
block|,
name|OSM_FILE_SA_SLVL_RECORD_C
block|,
name|OSM_FILE_SA_SMINFO_RECORD_C
block|,
name|OSM_FILE_SA_SW_INFO_RECORD_C
block|,
name|OSM_FILE_SA_VLARB_RECORD_C
block|,
name|OSM_FILE_SERVICE_C
block|,
name|OSM_FILE_SLVL_MAP_RCV_C
block|,
name|OSM_FILE_SM_C
block|,
name|OSM_FILE_SMINFO_RCV_C
block|,
name|OSM_FILE_SM_MAD_CTRL_C
block|,
name|OSM_FILE_SM_STATE_MGR_C
block|,
name|OSM_FILE_STATE_MGR_C
block|,
name|OSM_FILE_SUBNET_C
block|,
name|OSM_FILE_SW_INFO_RCV_C
block|,
name|OSM_FILE_SWITCH_C
block|,
name|OSM_FILE_TORUS_C
block|,
name|OSM_FILE_TRAP_RCV_C
block|,
name|OSM_FILE_UCAST_CACHE_C
block|,
name|OSM_FILE_UCAST_DNUP_C
block|,
name|OSM_FILE_UCAST_FILE_C
block|,
name|OSM_FILE_UCAST_FTREE_C
block|,
name|OSM_FILE_UCAST_LASH_C
block|,
name|OSM_FILE_UCAST_MGR_C
block|,
name|OSM_FILE_UCAST_UPDN_C
block|,
name|OSM_FILE_VENDOR_IBUMAD_C
block|,
name|OSM_FILE_VL15INTF_C
block|,
name|OSM_FILE_VL_ARB_RCV_C
block|,
name|OSM_FILE_ST_C
block|,
name|OSM_FILE_UCAST_DFSSSP_C
block|,
name|OSM_FILE_CONGESTION_CONTROL_C
block|, }
name|osm_file_ids_enum
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_FILE_ID_H_ */
end_comment

end_unit

