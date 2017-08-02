begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2005 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_sa_t.  *	This object represents an IBA subnet.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SA_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SA_H_
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
file|<complib/cl_timer.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
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
file|<vendor/osm_vendor_api.h>
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
file|<opensm/osm_sa_mad_ctrl.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_sm.h>
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
comment|/****h* OpenSM/SA * NAME *	SA * * DESCRIPTION *	The SA object encapsulates the information needed by the *	OpenSM to instantiate subnet administration.  The OpenSM *	allocates one SA object per subnet manager. * *	The SA object is thread safe. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * AUTHOR *	Ranjit Pandit, Intel *	Anil Keshavamurthy, Intel * *********/
end_comment

begin_comment
comment|/****d* OpenSM: SA/osm_sa_state_t * NAME *	osm_sa_state_t * * DESCRIPTION *	Enumerates the possible states of SA object. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_sa_state
block|{
name|OSM_SA_STATE_INIT
init|=
literal|0
block|,
name|OSM_SA_STATE_READY
block|}
name|osm_sa_state_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: SA/osm_mpr_rec_t * NAME *	osm_mpr_rec_t * * DESCRIPTION *	SA MultiPathRecord response. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mpr_rec
block|{
name|ib_path_rec_t
name|path_rec
decl_stmt|;
specifier|const
name|osm_port_t
modifier|*
name|p_src_port
decl_stmt|;
specifier|const
name|osm_port_t
modifier|*
name|p_dest_port
decl_stmt|;
name|int
name|hops
decl_stmt|;
block|}
name|osm_mpr_rec_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****d* OpenSM: SA/osm_sa_item_t * NAME *	osm_sa_item_t * * DESCRIPTION *	SA response item. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_sa_item
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
union|union
block|{
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
name|ib_guidinfo_record_t
name|guid_rec
decl_stmt|;
name|ib_inform_info_t
name|inform
decl_stmt|;
name|ib_inform_info_record_t
name|inform_rec
decl_stmt|;
name|ib_lft_record_t
name|lft_rec
decl_stmt|;
name|ib_link_record_t
name|link_rec
decl_stmt|;
name|ib_member_rec_t
name|mc_rec
decl_stmt|;
name|ib_mft_record_t
name|mft_rec
decl_stmt|;
name|osm_mpr_rec_t
name|mpr_rec
decl_stmt|;
name|ib_node_record_t
name|node_rec
decl_stmt|;
name|ib_path_rec_t
name|path_rec
decl_stmt|;
name|ib_pkey_table_record_t
name|pkey_rec
decl_stmt|;
name|ib_portinfo_record_t
name|port_rec
decl_stmt|;
name|ib_service_record_t
name|service_rec
decl_stmt|;
name|ib_slvl_table_record_t
name|slvl_rec
decl_stmt|;
name|ib_sminfo_record_t
name|sminfo_rec
decl_stmt|;
name|ib_switch_info_record_t
name|swinfo_rec
decl_stmt|;
name|ib_vl_arb_table_record_t
name|vlarb_rec
decl_stmt|;
block|}
name|resp
union|;
block|}
name|osm_sa_item_t
typedef|;
end_typedef

begin_comment
comment|/* * NOTES *	Actual structure allocated is based on SA attribute *	type. As such, it is variable sized. The allocation *	occurs in the SA attribute handling code. *	Note also that the size is specified external *	to this structure (It's passed as a parameter to *	osm_sa_respond). The SA_ITEM_RESP_SIZE macro *	facilitates determining the size required. * ***********/
end_comment

begin_define
define|#
directive|define
name|SA_ITEM_RESP_SIZE
parameter_list|(
name|_m
parameter_list|)
value|offsetof(osm_sa_item_t, resp._m) + \ 			      sizeof(((osm_sa_item_t *)NULL)->resp._m)
end_define

begin_comment
comment|/****s* OpenSM: SM/osm_sa_t * NAME *	osm_sa_t * * DESCRIPTION *	Subnet Administration structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_sa
block|{
name|osm_sa_state_t
name|state
decl_stmt|;
name|osm_sm_t
modifier|*
name|sm
decl_stmt|;
name|osm_subn_t
modifier|*
name|p_subn
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
name|cl_dispatcher_t
modifier|*
name|p_disp
decl_stmt|;
name|cl_dispatcher_t
modifier|*
name|p_set_disp
decl_stmt|;
name|cl_plock_t
modifier|*
name|p_lock
decl_stmt|;
name|atomic32_t
name|sa_trans_id
decl_stmt|;
name|osm_sa_mad_ctrl_t
name|mad_ctrl
decl_stmt|;
name|cl_timer_t
name|sr_timer
decl_stmt|;
name|boolean_t
name|dirty
decl_stmt|;
name|cl_disp_reg_handle_t
name|cpi_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|nr_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|pir_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|gir_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|lr_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|pr_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|smir_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|mcmr_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|sr_disp_h
decl_stmt|;
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
name|cl_disp_reg_handle_t
name|mpr_disp_h
decl_stmt|;
endif|#
directive|endif
name|cl_disp_reg_handle_t
name|infr_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|infir_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|vlarb_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|slvl_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|pkey_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|lft_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|sir_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|mft_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|infr_set_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|gir_set_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|mcmr_set_disp_h
decl_stmt|;
name|cl_disp_reg_handle_t
name|sr_set_disp_h
decl_stmt|;
block|}
name|osm_sa_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	state *		State of this SA object * *	sm *		Pointer to the Subnet Manager object. * *	p_subn *		Pointer to the Subnet object for this subnet. * *	p_vendor *		Pointer to the vendor specific interfaces object. * *	p_log *		Pointer to the log object. * *	p_mad_pool *		Pointer to the MAD pool. * *	p_disp *		Pointer to dispatcher * *	p_set_disp *		Pointer to dispatcher for Set requests. * *	p_lock *		Pointer to Lock for serialization * *	sa_trans_id *		Transaction ID * *	mad_ctrl *		Mad Controller * *	dirty *		A flag that denotes that SA DB is dirty and needs *		to be written to the dump file (if dumping is enabled) * * SEE ALSO *	SM object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_construct * NAME *	osm_sa_construct * * DESCRIPTION *	This function constructs an SA object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sa_construct
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|p_sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to a SA object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_sa_destroy. * *	Calling osm_sa_construct is a prerequisite to calling any other *	method except osm_sa_init. * * SEE ALSO *	SA object, osm_sa_init, osm_sa_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_shutdown * NAME *	osm_sa_shutdown * * DESCRIPTION *	The osm_sa_shutdown function shutdowns an SA, unregistering from all *  dispatcher messages and unbinding the QP1 mad service * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sa_shutdown
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|p_sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to a SA object to shutdown. * * RETURN VALUE *	This function does not return a value. * * SEE ALSO *	SA object, osm_sa_construct, osm_sa_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_destroy * NAME *	osm_sa_destroy * * DESCRIPTION *	The osm_sa_destroy function destroys an SA, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sa_destroy
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|p_sa
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to a SA object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified SA object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_sa_construct or *	osm_sa_init. * * SEE ALSO *	SA object, osm_sa_construct, osm_sa_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_init * NAME *	osm_sa_init * * DESCRIPTION *	The osm_sa_init function initializes a SA object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sa_init
parameter_list|(
name|IN
name|osm_sm_t
modifier|*
name|p_sm
parameter_list|,
name|IN
name|osm_sa_t
modifier|*
name|p_sa
parameter_list|,
name|IN
name|osm_subn_t
modifier|*
name|p_subn
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
name|cl_dispatcher_t
modifier|*
name|p_set_disp
parameter_list|,
name|IN
name|cl_plock_t
modifier|*
name|p_lock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to an osm_sa_t object to initialize. * *	p_subn *		[in] Pointer to the Subnet object for this subnet. * *	p_vendor *		[in] Pointer to the vendor specific interfaces object. * *	p_mad_pool *		[in] Pointer to the MAD pool. * *	p_log *		[in] Pointer to the log object. * *	p_stats *		[in] Pointer to the statistics object. * *	p_disp *		[in] Pointer to the OpenSM central Dispatcher. * *	p_set_disp *		[in] Pointer to the OpenSM Dispatcher for Set requests. * *	p_lock *		[in] Pointer to the OpenSM serializing lock. * * RETURN VALUES *	CL_SUCCESS if the SA object was initialized successfully. * * NOTES *	Allows calling other SA methods. * * SEE ALSO *	SA object, osm_sa_construct, osm_sa_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_bind * NAME *	osm_sa_bind * * DESCRIPTION *	Binds the SA object to a port guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sa_bind
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|p_sa
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to an osm_sa_t object to bind. * *	port_guid *		[in] Local port GUID with which to bind. * * * RETURN VALUES *	None * * NOTES *	A given SA object can only be bound to one port at a time. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_send * NAME *	osm_sa_send * * DESCRIPTION *	Sends SA MAD via osm_vendor_send and maintains the QP1 sent statistic * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_sa_send
parameter_list|(
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|,
name|IN
name|boolean_t
name|resp_expected
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****f* IBA Base: Types/osm_sa_send_error * NAME *	osm_sa_send_error * * DESCRIPTION *	Sends a generic SA response with the specified error status. *	The payload is simply replicated from the request MAD. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_sa_send_error
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|,
name|IN
name|ib_net16_t
name|sa_status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sa *		[in] Pointer to an osm_sa_t object. * *	p_madw *		[in] Original MAD to which the response must be sent. * *	sa_status *		[in] Status to send in the response. * * RETURN VALUES *	None. * * SEE ALSO *	SA object *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_respond * NAME *	osm_sa_respond * * DESCRIPTION *	Sends SA MAD response */
end_comment

begin_function_decl
name|void
name|osm_sa_respond
parameter_list|(
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|osm_madw_t
modifier|*
name|madw
parameter_list|,
name|size_t
name|attr_size
parameter_list|,
name|cl_qlist_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	sa *		[in] Pointer to an osm_sa_t object. * *	p_madw *		[in] Original MAD to which the response must be sent. * *	attr_size *		[in] Size of this SA attribute. * *	list *		[in] List of attribute to respond - it will be freed after *		sending. * * RETURN VALUES *	None. * * SEE ALSO *	SA object *********/
end_comment

begin_struct_decl
struct_decl|struct
name|osm_opensm
struct_decl|;
end_struct_decl

begin_comment
comment|/****f* OpenSM: SA/osm_sa_db_file_dump * NAME *	osm_sa_db_file_dump * * DESCRIPTION *	Dumps the SA DB to the dump file. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_sa_db_file_dump
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object. * * RETURN VALUES *	 0 if the SA DB was actually dumped *>0 if there was no need to dump the SA DB *<0 if some error occurred. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: SA/osm_sa_db_file_load * NAME *	osm_sa_db_file_load * * DESCRIPTION *	Loads SA DB from the file. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_sa_db_file_load
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object. * * RETURN VALUES *	0 on success, other value on failure. * *********/
end_comment

begin_comment
comment|/****f* OpenSM: MC Member Record Receiver/osm_mcmr_rcv_find_or_create_new_mgrp * NAME *	osm_mcmr_rcv_find_or_create_new_mgrp * * DESCRIPTION *	Create new Multicast group * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_mgrp_t
modifier|*
name|osm_mcmr_rcv_find_or_create_new_mgrp
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
name|ib_net64_t
name|comp_mask
parameter_list|,
name|IN
name|ib_member_rec_t
modifier|*
name|p_recvd_mcmember_rec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_sa *		[in] Pointer to an osm_sa_t object. *	comp_mask *		[in] SA query component mask *	p_recvd_mcmember_rec *		[in] Received Multicast member record * * RETURN VALUES *	The pointer to MC group object found or created, NULL in case of errors * *********/
end_comment

begin_comment
comment|/**  * The following expose functionality of osm_sa_path_record.c for internal use  * by sub managers  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_path_parms
block|{
name|ib_net16_t
name|pkey
decl_stmt|;
name|uint8_t
name|mtu
decl_stmt|;
name|uint8_t
name|rate
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|uint8_t
name|pkt_life
decl_stmt|;
name|boolean_t
name|reversible
decl_stmt|;
name|int
name|hops
decl_stmt|;
block|}
name|osm_path_parms_t
typedef|;
end_typedef

begin_function_decl
name|ib_api_status_t
name|osm_get_path_params
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_src_port
parameter_list|,
name|IN
specifier|const
name|uint16_t
name|slid_ho
parameter_list|,
name|IN
specifier|const
name|osm_port_t
modifier|*
name|p_dest_port
parameter_list|,
name|IN
specifier|const
name|uint16_t
name|dlid_ho
parameter_list|,
name|OUT
name|osm_path_parms_t
modifier|*
name|p_parms
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_net16_t
name|osm_pr_get_end_points
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
specifier|const
name|ib_sa_mad_t
modifier|*
name|sa_mad
parameter_list|,
name|OUT
specifier|const
name|osm_alias_guid_t
modifier|*
modifier|*
name|pp_src_alias_guid
parameter_list|,
name|OUT
specifier|const
name|osm_alias_guid_t
modifier|*
modifier|*
name|pp_dest_alias_guid
parameter_list|,
name|OUT
specifier|const
name|osm_port_t
modifier|*
modifier|*
name|pp_src_port
parameter_list|,
name|OUT
specifier|const
name|osm_port_t
modifier|*
modifier|*
name|pp_dest_port
parameter_list|,
name|OUT
specifier|const
name|ib_gid_t
modifier|*
modifier|*
name|pp_sgid
parameter_list|,
name|OUT
specifier|const
name|ib_gid_t
modifier|*
modifier|*
name|pp_dgid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_pr_process_pair
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
specifier|const
name|ib_sa_mad_t
modifier|*
name|sa_mad
parameter_list|,
name|IN
specifier|const
name|osm_port_t
modifier|*
name|requester_port
parameter_list|,
name|IN
specifier|const
name|osm_alias_guid_t
modifier|*
name|p_src_alias_guid
parameter_list|,
name|IN
specifier|const
name|osm_alias_guid_t
modifier|*
name|p_dest_alias_guid
parameter_list|,
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_sgid
parameter_list|,
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_dgid
parameter_list|,
name|IN
name|cl_qlist_t
modifier|*
name|p_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_pr_process_half
parameter_list|(
name|IN
name|osm_sa_t
modifier|*
name|sa
parameter_list|,
name|IN
specifier|const
name|ib_sa_mad_t
modifier|*
name|sa_mad
parameter_list|,
name|IN
specifier|const
name|osm_port_t
modifier|*
name|requester_port
parameter_list|,
name|IN
specifier|const
name|osm_alias_guid_t
modifier|*
name|p_src_alias_guid
parameter_list|,
name|IN
specifier|const
name|osm_alias_guid_t
modifier|*
name|p_dest_alias_guid
parameter_list|,
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_sgid
parameter_list|,
name|IN
specifier|const
name|ib_gid_t
modifier|*
name|p_dgid
parameter_list|,
name|IN
name|cl_qlist_t
modifier|*
name|p_list
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
comment|/* _OSM_SA_H_ */
end_comment

end_unit

