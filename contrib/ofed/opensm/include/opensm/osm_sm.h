begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2011 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_sm_t.  *	This object represents an IBA subnet.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SM_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_passivelock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_event.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_thread.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_event_wheel.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor_api.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_stats.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_vl15intf.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_log.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_sm_mad_ctrl.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_lid_mgr.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_ucast_mgr.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_db.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_remote_sm.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_multicast.h>
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
comment|/****h* OpenSM/SM * NAME *	SM * * DESCRIPTION *	The SM object encapsulates the information needed by the *	OpenSM to instantiate a subnet manager.  The OpenSM allocates *	one SM object per subnet manager. * *	The SM object is thread safe. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: SM/osm_sm_t * NAME *  osm_sm_t * * DESCRIPTION *  Subnet Manager structure. * *  This object should be treated as opaque and should *  be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_sm
block|{
name|osm_thread_state_t
name|thread_state
decl_stmt|;
name|unsigned
name|signal_mask
decl_stmt|;
name|cl_spinlock_t
name|signal_lock
decl_stmt|;
name|cl_spinlock_t
name|state_lock
decl_stmt|;
name|cl_event_t
name|signal_event
decl_stmt|;
name|cl_event_t
name|subnet_up_event
decl_stmt|;
name|cl_timer_t
name|sweep_timer
decl_stmt|;
name|cl_timer_t
name|polling_timer
decl_stmt|;
name|cl_event_wheel_t
name|trap_aging_tracker
decl_stmt|;
name|cl_thread_t
name|sweeper
decl_stmt|;
name|unsigned
name|master_sm_found
decl_stmt|;
name|uint32_t
name|retry_number
decl_stmt|;
name|ib_net64_t
name|master_sm_guid
decl_stmt|;
name|ib_net64_t
name|polling_sm_guid
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
name|osm_db_t
modifier|*
name|p_db
decl_stmt|;
name|osm_vendor_t
modifier|*
name|p_vendor
decl_stmt|;
name|osm_log_t
modifier|*
name|p_log
decl_stmt|;
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
decl_stmt|;
name|osm_vl15_t
modifier|*
name|p_vl15
decl_stmt|;
name|cl_dispatcher_t
modifier|*
name|p_disp
decl_stmt|;
name|cl_plock_t
modifier|*
name|p_lock
decl_stmt|;
name|atomic32_t
name|sm_trans_id
decl_stmt|;
name|uint16_t
name|mlids_init_max
decl_stmt|;
name|unsigned
name|mlids_req_max
decl_stmt|;
name|uint8_t
modifier|*
name|mlids_req
decl_stmt|;
name|osm_sm_mad_ctrl_t
name|mad_ctrl
decl_stmt|;
name|osm_lid_mgr_t
name|lid_mgr
decl_stmt|;
name|osm_ucast_mgr_t
name|ucast_mgr
decl_stmt|;
name|cl_disp_reg_handle_t
name|sweep_fail_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|ni_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|pi_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|gi_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|nd_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|si_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|lft_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|mft_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|sm_info_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|trap_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|slvl_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|vla_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|pkey_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|mlnx_epi_disp_h
decl_stmt|;
block|}
name|osm_sm_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_subn *		Pointer to the Subnet object for this subnet. * *	p_db *		Pointer to the database (persistency) object * *	p_vendor *		Pointer to the vendor specific interfaces object. * *	p_log *		Pointer to the log object. * *	p_mad_pool *		Pointer to the MAD pool. * *	p_vl15 *		Pointer to the VL15 interface. * *	mad_ctrl *		MAD Controller. * *	p_disp *		Pointer to the Dispatcher. * *	p_lock *		Pointer to the serializing lock. * * SEE ALSO *	SM object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_construct * NAME *	osm_sm_construct * * DESCRIPTION *	This function constructs an SM object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_construct
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to a SM object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_sm_init, osm_sm_destroy * *	Calling osm_sm_construct is a prerequisite to calling any other *	method except osm_sm_init. * * SEE ALSO *	SM object, osm_sm_init, osm_sm_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_shutdown * NAME *	osm_sm_shutdown * * DESCRIPTION *	The osm_sm_shutdown function shutdowns an SM, stopping the sweeper *	and unregistering all messages from the dispatcher * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_shutdown
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to a SM object to shutdown. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	SM object, osm_sm_construct, osm_sm_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_destroy * NAME *	osm_sm_destroy * * DESCRIPTION *	The osm_sm_destroy function destroys an SM, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_destroy
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to a SM object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified SM object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_sm_construct or *	osm_sm_init. * * SEE ALSO *	SM object, osm_sm_construct, osm_sm_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_init * NAME *	osm_sm_init * * DESCRIPTION *	The osm_sm_init function initializes a SM object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_init
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|osm_db_t
modifier|*
name|p_db
parameter_list|,
name|IN
name|osm_vendor_t
modifier|*
name|p_vendor
parameter_list|,
name|IN
name|osm_mad_pool_t
modifier|*
name|p_mad_pool
parameter_list|,
name|IN
name|osm_vl15_t
modifier|*
name|p_vl15
parameter_list|,
name|IN
name|osm_log_t
modifier|*
name|p_log
parameter_list|,
name|IN
name|osm_stats_t
modifier|*
name|p_stats
parameter_list|,
name|IN
name|cl_dispatcher_t
modifier|*
name|p_disp
parameter_list|,
name|IN
name|cl_plock_t
modifier|*
name|p_lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to an osm_sm_t object to initialize. * *	p_subn *		[in] Pointer to the Subnet object for this subnet. * *	p_vendor *		[in] Pointer to the vendor specific interfaces object. * *	p_mad_pool *		[in] Pointer to the MAD pool. * *	p_vl15 *		[in] Pointer to the VL15 interface. * *	p_log *		[in] Pointer to the log object. * *	p_stats *		[in] Pointer to the statistics object. * *	p_disp *		[in] Pointer to the OpenSM central Dispatcher. * *	p_lock *		[in] Pointer to the OpenSM serializing lock. * * RETURN VALUES *	IB_SUCCESS if the SM object was initialized successfully. * * NOTES *	Allows calling other SM methods. * * SEE ALSO *	SM object, osm_sm_construct, osm_sm_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_signal * NAME *	osm_sm_signal * * DESCRIPTION *	Signal event to SM * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_signal
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|,
name|osm_signal_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to an osm_sm_t object. * *	signal *		[in] sm signal number. * * NOTES * * SEE ALSO *	SM object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_sweep * NAME *	osm_sm_sweep * * DESCRIPTION *	Initiates a subnet sweep. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_sweep
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to an osm_sm_t object. * * RETURN VALUES *	IB_SUCCESS if the sweep completed successfully. * * NOTES * * SEE ALSO *	SM object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_bind * NAME *	osm_sm_bind * * DESCRIPTION *	Binds the sm object to a port guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_bind
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to an osm_sm_t object to bind. * *	port_guid *		[in] Local port GUID with which to bind. * * * RETURN VALUES *	None * * NOTES *	A given SM object can only be bound to one port at a time. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_req_get * NAME *	osm_req_get * * DESCRIPTION *	Starts the process to transmit a directed route request for *	the attribute. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_req_get
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
specifier|const
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|,
name|IN
name|ib_net16_t
name|attr_id
parameter_list|,
name|IN
name|ib_net32_t
name|attr_mod
parameter_list|,
name|IN
name|boolean_t
name|find_mkey
parameter_list|,
name|ib_net64_t
name|m_key
parameter_list|,
name|IN
name|cl_disp_msgid_t
name|err_msg
parameter_list|,
name|IN
specifier|const
name|osm_madw_context_t
modifier|*
name|p_context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	p_path *		[in] Pointer to the directed route path to the node *		from which to retrieve the attribute. * *	attr_id *		[in] Attribute ID to request. * *	attr_mod *		[in] Attribute modifier for this request. * *	find_mkey *		[in] Flag to indicate whether the M_Key should be looked up for *		     this MAD. * 	m_key * 		[in] M_Key value to be send with this MAD. Applied, only when * 		     find_mkey is FALSE. * *	err_msg *		[in] Message id with which to post this MAD if an error occurs. * *	p_context *		[in] Mad wrapper context structure to be copied into the wrapper *		context, and thus visible to the recipient of the response. * * RETURN VALUES *	IB_SUCCESS if the request was successful. * * NOTES *	This function asynchronously requests the specified attribute. *	The response from the node will be routed through the Dispatcher *	to the appropriate receive controller object. *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_send_req_mad * NAME *       osm_send_req_mad * * DESCRIPTION *	Starts the process to transmit a preallocated/predefined directed route *	Set() request. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_send_req_mad
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. *	p_madw *		[in] Pointer to a preallocated MAD buffer * *********/
end_comment

begin_comment
comment|/***f* OpenSM: SM/osm_prepare_req_set * NAME *	osm_prepare_req_set * * DESCRIPTION *	Preallocate and fill a directed route Set() MAD w/o sending it. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_madw_t
modifier|*
name|osm_prepare_req_set
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
specifier|const
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|,
name|IN
specifier|const
name|uint8_t
modifier|*
name|p_payload
parameter_list|,
name|IN
name|size_t
name|payload_size
parameter_list|,
name|IN
name|ib_net16_t
name|attr_id
parameter_list|,
name|IN
name|ib_net32_t
name|attr_mod
parameter_list|,
name|IN
name|boolean_t
name|find_mkey
parameter_list|,
name|IN
name|ib_net64_t
name|m_key
parameter_list|,
name|IN
name|cl_disp_msgid_t
name|err_msg
parameter_list|,
name|IN
specifier|const
name|osm_madw_context_t
modifier|*
name|p_context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	p_path *		[in] Pointer to the directed route path of the recipient. * *	p_payload *		[in] Pointer to the SMP payload to send. * *	payload_size *		[in] The size of the payload to be copied to the SMP data field. * *	attr_id *		[in] Attribute ID to request. * *	attr_mod *		[in] Attribute modifier for this request. * *	find_mkey *		[in] Flag to indicate whether the M_Key should be looked up for *		     this MAD. * 	m_key * 		[in] M_Key value to be send with this MAD. Applied, only when * 		     find_mkey is FALSE. * *	err_msg *		[in] Message id with which to post this MAD if an error occurs. * *	p_context *		[in] Mad wrapper context structure to be copied into the wrapper *		     context, and thus visible to the recipient of the response. * * RETURN VALUES *	Pointer the MAD buffer in case of success and NULL in case of failure. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_req_set * NAME *	osm_req_set * * DESCRIPTION *	Starts the process to transmit a directed route Set() request. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_req_set
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
specifier|const
name|osm_dr_path_t
modifier|*
name|p_path
parameter_list|,
name|IN
specifier|const
name|uint8_t
modifier|*
name|p_payload
parameter_list|,
name|IN
name|size_t
name|payload_size
parameter_list|,
name|IN
name|ib_net16_t
name|attr_id
parameter_list|,
name|IN
name|ib_net32_t
name|attr_mod
parameter_list|,
name|IN
name|boolean_t
name|find_mkey
parameter_list|,
name|IN
name|ib_net64_t
name|m_key
parameter_list|,
name|IN
name|cl_disp_msgid_t
name|err_msg
parameter_list|,
name|IN
specifier|const
name|osm_madw_context_t
modifier|*
name|p_context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	p_path *		[in] Pointer to the directed route path of the recipient. * *	p_payload *		[in] Pointer to the SMP payload to send. * *	payload_size *		[in] The size of the payload to be copied to the SMP data field. * *	attr_id *		[in] Attribute ID to request. * *	attr_mod *		[in] Attribute modifier for this request. * *	find_mkey *		[in] Flag to indicate whether the M_Key should be looked up for *		     this MAD. * * 	m_key * 		[in] M_Key value to be send with this MAD. Applied, only when * 		     find_mkey is FALSE. * *	err_msg *		[in] Message id with which to post this MAD if an error occurs. * *	p_context *		[in] Mad wrapper context structure to be copied into the wrapper *		context, and thus visible to the recipient of the response. * * RETURN VALUES *	IB_SUCCESS if the request was successful. * * NOTES *	This function asynchronously requests the specified attribute. *	The response from the node will be routed through the Dispatcher *	to the appropriate receive controller object. *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_resp_send * NAME *	osm_resp_send * * DESCRIPTION *	Starts the process to transmit a directed route response. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_resp_send
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_req_madw
parameter_list|,
name|IN
name|ib_net16_t
name|status
parameter_list|,
name|IN
specifier|const
name|uint8_t
modifier|*
name|p_payload
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_resp *		[in] Pointer to an osm_resp_t object. * *	p_madw *		[in] Pointer to the MAD Wrapper object for the requesting MAD *		to which this response is generated. * *	status *		[in] Status for this response. * *	p_payload *		[in] Pointer to the payload of the response MAD. * * RETURN VALUES *	IB_SUCCESS if the response was successful. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM/osm_sm_reroute_mlid * NAME *	osm_sm_reroute_mlid * * DESCRIPTION *	Requests (schedules) MLID rerouting * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_reroute_mlid
parameter_list|(
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|ib_net16_t
name|mlid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	mlid *		[in] MLID value * * RETURN VALUES *	None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_sm_wait_for_subnet_up * NAME *	osm_sm_wait_for_subnet_up * * DESCRIPTION *	Blocks the calling thread until the subnet is up. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|osm_sm_wait_for_subnet_up
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|,
name|IN
name|uint32_t
name|wait_us
parameter_list|,
name|IN
name|boolean_t
name|interruptible
parameter_list|)
block|{
return|return
name|cl_event_wait_on
argument_list|(
operator|&
name|p_sm
operator|->
name|subnet_up_event
argument_list|,
name|wait_us
argument_list|,
name|interruptible
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_sm *		[in] Pointer to an osm_sm_t object. * *	wait_us *		[in] Number of microseconds to wait. * *	interruptible *		[in] Indicates whether the wait operation can be interrupted *		by external signals. * * RETURN VALUES *	CL_SUCCESS if the wait operation succeeded in response to the event *	being set. * *	CL_TIMEOUT if the specified time period elapses. * *	CL_NOT_DONE if the wait was interrupted by an external signal. * *	CL_ERROR if the wait operation failed. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: State Manager/osm_sm_is_greater_than * NAME *	osm_sm_is_greater_than * * DESCRIPTION *	Compares two SM's (14.4.1.2) * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|boolean_t
name|osm_sm_is_greater_than
parameter_list|(
name|IN
name|uint8_t
name|l_priority
parameter_list|,
name|IN
name|ib_net64_t
name|l_guid
parameter_list|,
name|IN
name|uint8_t
name|r_priority
parameter_list|,
name|IN
name|ib_net64_t
name|r_guid
parameter_list|)
block|{
return|return
operator|(
name|l_priority
operator|>
name|r_priority
operator|||
operator|(
name|l_priority
operator|==
name|r_priority
operator|&&
name|cl_ntoh64
argument_list|(
name|l_guid
argument_list|)
operator|<
name|cl_ntoh64
argument_list|(
name|r_guid
argument_list|)
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	l_priority *		[in] Priority of the SM on the "left" * *	l_guid *		[in] GUID of the SM on the "left" * *	r_priority *		[in] Priority of the SM on the "right" * *	r_guid *		[in] GUID of the SM on the "right" * * RETURN VALUES *	Return TRUE if an sm with l_priority and l_guid is higher than an sm *	with r_priority and r_guid, return FALSE otherwise. * * NOTES * * SEE ALSO *	State Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM State Manager/osm_sm_state_mgr_process * NAME *	osm_sm_state_mgr_process * * DESCRIPTION *	Processes and maintains the states of the SM. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_state_mgr_process
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
name|osm_sm_signal_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	signal *		[in] Signal to the state SM engine. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	State Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM State Manager/osm_sm_state_mgr_signal_master_is_alive * NAME *	osm_sm_state_mgr_signal_master_is_alive * * DESCRIPTION *	Signals that the remote Master SM is alive. *	Need to clear the retry_number variable. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sm_state_mgr_signal_master_is_alive
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	State Manager *********/
end_comment

begin_comment
comment|/****f* OpenSM: SM State Manager/osm_sm_state_mgr_check_legality * NAME *	osm_sm_state_mgr_check_legality * * DESCRIPTION *	Checks the legality of the signal received, according to the *  current state of the SM state machine. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sm_state_mgr_check_legality
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|IN
name|osm_sm_signal_t
name|signal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	signal *		[in] Signal to the state SM engine. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *	State Manager *********/
end_comment

begin_function_decl
name|void
name|osm_report_sm_state
parameter_list|(
name|osm_sm_t
modifier|*
name|sm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* OpenSM: SM State Manager/osm_send_trap144 * NAME *	osm_send_trap144 * * DESCRIPTION *	Send trap 144 to the master SM. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_send_trap144
parameter_list|(
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|ib_net16_t
name|local
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sm *		[in] Pointer to an osm_sm_t object. * *	local *		[in] OtherLocalChanges mask in network byte order. * * RETURN VALUES *	0 on success, non-zero value otherwise. * *********/
end_comment

begin_function_decl
name|void
name|osm_set_sm_priority
parameter_list|(
name|osm_sm_t
modifier|*
name|sm
parameter_list|,
name|uint8_t
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_SM_H_ */
end_comment

end_unit

