begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2008 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2012 Lawrence Livermore National Lab.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *    OSM Congestion Control types and prototypes  *  * Author:  *    Albert Chu, LLNL  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_CONGESTION_CONTROL_H
end_ifndef

begin_define
define|#
directive|define
name|OSM_CONGESTION_CONTROL_H
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_types_osd.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_sm.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_opensm.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_comment
comment|/****s* OpenSM: Base/OSM_DEFAULT_CC_KEY  * NAME  *       OSM_DEFAULT_CC_KEY  *  * DESCRIPTION  *       Congestion Control Key used by OpenSM.  *  * SYNOPSIS  */
end_comment

begin_define
define|#
directive|define
name|OSM_DEFAULT_CC_KEY
value|0
end_define

begin_define
define|#
directive|define
name|OSM_CC_DEFAULT_MAX_OUTSTANDING_QUERIES
value|500
end_define

begin_define
define|#
directive|define
name|OSM_CC_TIMEOUT_COUNT_THRESHOLD
value|3
end_define

begin_comment
comment|/****s* OpenSM: CongestionControl/osm_congestion_control_t *  This object should be treated as opaque and should *  be manipulated only through the provided functions. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_congestion_control
block|{
name|struct
name|osm_opensm
modifier|*
name|osm
decl_stmt|;
name|osm_subn_t
modifier|*
name|subn
decl_stmt|;
name|osm_sm_t
modifier|*
name|sm
decl_stmt|;
name|osm_log_t
modifier|*
name|log
decl_stmt|;
name|osm_mad_pool_t
modifier|*
name|mad_pool
decl_stmt|;
name|atomic32_t
name|trans_id
decl_stmt|;
name|osm_vendor_t
modifier|*
name|vendor
decl_stmt|;
name|osm_bind_handle_t
name|bind_handle
decl_stmt|;
name|cl_disp_reg_handle_t
name|cc_disp_h
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|atomic32_t
name|outstanding_mads
decl_stmt|;
name|atomic32_t
name|outstanding_mads_on_wire
decl_stmt|;
name|cl_qlist_t
name|mad_queue
decl_stmt|;
name|cl_spinlock_t
name|mad_queue_lock
decl_stmt|;
name|cl_event_t
name|cc_poller_wakeup
decl_stmt|;
name|cl_event_t
name|outstanding_mads_done_event
decl_stmt|;
name|cl_event_t
name|sig_mads_on_wire_continue
decl_stmt|;
name|cl_thread_t
name|cc_poller
decl_stmt|;
name|osm_thread_state_t
name|thread_state
decl_stmt|;
name|ib_sw_cong_setting_t
name|sw_cong_setting
decl_stmt|;
name|ib_ca_cong_setting_t
name|ca_cong_setting
decl_stmt|;
name|ib_cc_tbl_t
name|cc_tbl
index|[
name|OSM_CCT_ENTRY_MAD_BLOCKS
index|]
decl_stmt|;
name|unsigned
name|int
name|cc_tbl_mads
decl_stmt|;
block|}
name|osm_congestion_control_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *       subn *             Subnet object for this subnet. * *       log *             Pointer to the log object. * *       mad_pool *             Pointer to the MAD pool. * *       mad_ctrl *             Mad Controller *********/
end_comment

begin_struct_decl
struct_decl|struct
name|osm_opensm
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|osm_congestion_control_setup
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|osm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osm_congestion_control_wait_pending_transactions
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|osm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_api_status_t
name|osm_congestion_control_init
parameter_list|(
name|osm_congestion_control_t
modifier|*
name|p_cc
parameter_list|,
name|struct
name|osm_opensm
modifier|*
name|osm
parameter_list|,
specifier|const
name|osm_subn_opt_t
modifier|*
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_api_status_t
name|osm_congestion_control_bind
parameter_list|(
name|osm_congestion_control_t
modifier|*
name|p_cc
parameter_list|,
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_congestion_control_shutdown
parameter_list|(
name|osm_congestion_control_t
modifier|*
name|p_cc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_congestion_control_destroy
parameter_list|(
name|osm_congestion_control_t
modifier|*
name|p_cc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef OSM_CONGESTION_CONTROL_H */
end_comment

end_unit

