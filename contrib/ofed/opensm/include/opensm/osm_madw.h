begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_mad_wrapper_t.  *	This object represents the context wrapper for OpenSM MAD processing.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_MADW_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_MADW_H_
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qlist.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_dispatcher.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<vendor/osm_vendor.h>
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
comment|/****s* OpenSM: MAD Wrapper/osm_bind_info_t * NAME *   osm_bind_info_t * * DESCRIPTION * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_bind_info
block|{
name|ib_net64_t
name|port_guid
decl_stmt|;
name|uint8_t
name|mad_class
decl_stmt|;
name|uint8_t
name|class_version
decl_stmt|;
name|boolean_t
name|is_responder
decl_stmt|;
name|boolean_t
name|is_trap_processor
decl_stmt|;
name|boolean_t
name|is_report_processor
decl_stmt|;
name|uint32_t
name|send_q_size
decl_stmt|;
name|uint32_t
name|recv_q_size
decl_stmt|;
name|uint32_t
name|timeout
decl_stmt|;
name|uint32_t
name|retries
decl_stmt|;
block|}
name|osm_bind_info_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	portguid *		PortGuid of local port * *	mad_class *		Mgmt Class ID * *	class_version *		Mgmt Class version * *	is_responder *		True if this is a GSI Agent * *	is_trap_processor *		True if GSI Trap msgs are handled * *	is_report_processor *		True if GSI Report msgs are handled * *	send_q_size *		SendQueueSize * *	recv_q_size *		Receive Queue Size * *	timeout *		Transaction timeout * *	retries *		Number of retries for transaction * * SEE ALSO *********/
end_comment

begin_comment
comment|/****h* OpenSM/MAD Wrapper * NAME *	MAD Wrapper * * DESCRIPTION *	The MAD Wrapper object encapsulates the information needed by the *	OpenSM to manage individual MADs.  The OpenSM allocates one MAD Wrapper *	per MAD. * *	The MAD Wrapper is not thread safe, thus callers must provide *	serialization. * *	This object should be treated as opaque and should be *	manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_ni_context_t * NAME *	osm_ni_context_t * * DESCRIPTION *	Context needed by recipient of NodeInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_ni_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|ib_net64_t
name|dup_node_guid
decl_stmt|;
name|uint8_t
name|dup_port_num
decl_stmt|;
name|unsigned
name|dup_count
decl_stmt|;
block|}
name|osm_ni_context_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	p_node *		Pointer to the node thru which we got to this node. * *	p_sw *		Pointer to the switch object (if any) of the switch *		thru which we got to this node. * *	port_num *		Port number on the node or switch thru which we got *		to this node. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_pi_context_t * NAME *	osm_pi_context_t * * DESCRIPTION *	Context needed by recipient of PortInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_pi_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
name|boolean_t
name|light_sweep
decl_stmt|;
name|boolean_t
name|active_transition
decl_stmt|;
name|boolean_t
name|client_rereg
decl_stmt|;
block|}
name|osm_pi_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_gi_context_t * NAME *	osm_gi_context_t * * DESCRIPTION *	Context needed by recipient of GUIDInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_gi_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
block|}
name|osm_gi_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_nd_context_t * NAME *	osm_nd_context_t * * DESCRIPTION *	Context needed by recipient of NodeDescription attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_nd_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
block|}
name|osm_nd_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_si_context_t * NAME *	osm_si_context_t * * DESCRIPTION *	Context needed by recipient of SwitchInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_si_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
name|boolean_t
name|light_sweep
decl_stmt|;
name|boolean_t
name|lft_top_change
decl_stmt|;
block|}
name|osm_si_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_lft_context_t * NAME *	osm_lft_context_t * * DESCRIPTION *	Context needed by recipient of LinearForwardingTable attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_lft_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
block|}
name|osm_lft_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_mft_context_t * NAME *	osm_mft_context_t * * DESCRIPTION *	Context needed by recipient of MulticastForwardingTable attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mft_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
block|}
name|osm_mft_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_smi_context_t * NAME *	osm_smi_context_t * * DESCRIPTION *	Context needed by recipient of SMInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_smi_context
block|{
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
name|boolean_t
name|light_sweep
decl_stmt|;
block|}
name|osm_smi_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_pkey_context_t * NAME *	osm_pkey_context_t * * DESCRIPTION *	Context needed by recipient of P_Key attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_pkey_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
block|}
name|osm_pkey_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_slvl_context_t * NAME *	osm_slvl_context_t * * DESCRIPTION *	Context needed by recipient of PortInfo attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_slvl_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
block|}
name|osm_slvl_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_vla_context_t * NAME *	osm_vla_context_t * * DESCRIPTION *	Context needed by recipient of VL Arb attribute. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_vla_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|boolean_t
name|set_method
decl_stmt|;
block|}
name|osm_vla_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_perfmgr_context_t * DESCRIPTION *	Context for Performance manager queries */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_perfmgr_context
block|{
name|uint64_t
name|node_guid
decl_stmt|;
name|uint16_t
name|port
decl_stmt|;
name|uint8_t
name|mad_method
decl_stmt|;
comment|/* was this a get or a set */
name|ib_net16_t
name|mad_attr_id
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_OSM_PERF_MGR_PROFILE
name|struct
name|timeval
name|query_start
decl_stmt|;
endif|#
directive|endif
block|}
name|osm_perfmgr_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_cc_context_t * DESCRIPTION *	Context for Congestion Control MADs */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_cc_context
block|{
name|ib_net64_t
name|node_guid
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|uint8_t
name|port
decl_stmt|;
name|uint8_t
name|mad_method
decl_stmt|;
comment|/* was this a get or a set */
name|ib_net32_t
name|attr_mod
decl_stmt|;
block|}
name|osm_cc_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_OPENIB
end_ifndef

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_arbitrary_context_t * NAME *	osm_arbitrary_context_t * * DESCRIPTION *	Context needed by arbitrary recipient. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_arbitrary_context
block|{
name|void
modifier|*
name|context1
decl_stmt|;
name|void
modifier|*
name|context2
decl_stmt|;
block|}
name|osm_arbitrary_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_madw_context_t * NAME *	osm_madw_context_t * * DESCRIPTION *	Context needed by recipients of MAD responses. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
union|union
name|_osm_madw_context
block|{
name|osm_ni_context_t
name|ni_context
decl_stmt|;
name|osm_pi_context_t
name|pi_context
decl_stmt|;
name|osm_gi_context_t
name|gi_context
decl_stmt|;
name|osm_nd_context_t
name|nd_context
decl_stmt|;
name|osm_si_context_t
name|si_context
decl_stmt|;
name|osm_lft_context_t
name|lft_context
decl_stmt|;
name|osm_mft_context_t
name|mft_context
decl_stmt|;
name|osm_smi_context_t
name|smi_context
decl_stmt|;
name|osm_slvl_context_t
name|slvl_context
decl_stmt|;
name|osm_pkey_context_t
name|pkey_context
decl_stmt|;
name|osm_vla_context_t
name|vla_context
decl_stmt|;
name|osm_perfmgr_context_t
name|perfmgr_context
decl_stmt|;
name|osm_cc_context_t
name|cc_context
decl_stmt|;
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_OPENIB
name|osm_arbitrary_context_t
name|arb_context
decl_stmt|;
endif|#
directive|endif
block|}
name|osm_madw_context_t
typedef|;
end_typedef

begin_comment
comment|/*********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_mad_addr_t * NAME *   osm_mad_addr_t * * DESCRIPTION * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_mad_addr
block|{
name|ib_net16_t
name|dest_lid
decl_stmt|;
name|uint8_t
name|path_bits
decl_stmt|;
name|uint8_t
name|static_rate
decl_stmt|;
union|union
name|addr_type
block|{
struct|struct
name|_smi
block|{
name|ib_net16_t
name|source_lid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
block|}
name|smi
struct|;
struct|struct
name|_gsi
block|{
name|ib_net32_t
name|remote_qp
decl_stmt|;
name|ib_net32_t
name|remote_qkey
decl_stmt|;
name|uint16_t
name|pkey_ix
decl_stmt|;
name|uint8_t
name|service_level
decl_stmt|;
name|boolean_t
name|global_route
decl_stmt|;
name|ib_grh_t
name|grh_info
decl_stmt|;
block|}
name|gsi
struct|;
block|}
name|addr_type
union|;
block|}
name|osm_mad_addr_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * * SEE ALSO *********/
end_comment

begin_comment
comment|/****s* OpenSM: MAD Wrapper/osm_madw_t * NAME *	osm_madw_t * * DESCRIPTION *	Context needed for processing individual MADs * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_madw
block|{
name|cl_list_item_t
name|list_item
decl_stmt|;
name|osm_bind_handle_t
name|h_bind
decl_stmt|;
name|osm_vend_wrap_t
name|vend_wrap
decl_stmt|;
name|osm_mad_addr_t
name|mad_addr
decl_stmt|;
name|osm_bind_info_t
name|bind_info
decl_stmt|;
name|osm_madw_context_t
name|context
decl_stmt|;
name|uint32_t
name|mad_size
decl_stmt|;
name|ib_api_status_t
name|status
decl_stmt|;
name|cl_disp_msgid_t
name|fail_msg
decl_stmt|;
name|boolean_t
name|resp_expected
decl_stmt|;
specifier|const
name|ib_mad_t
modifier|*
name|p_mad
decl_stmt|;
block|}
name|osm_madw_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	list_item *		List linkage for lists.  MUST BE FIRST MEMBER! * *	h_bind *		Bind handle for the port on which this MAD will be sent *		or was received. * *	vend_wrap *		Transport vendor specific context.  This structure is not *		used outside MAD transport vendor specific code. * *	context *		Union of controller specific contexts needed for this MAD. *		This structure allows controllers to indirectly communicate *		with each other through the dispatcher. * *	mad_size *		Size of this MAD in bytes. * *	status *		Status of completed operation on the MAD. *		CL_SUCCESS if the operation was successful. * *	fail_msg *		Dispatcher message with which to post this MAD on failure. *		This value is set by the originator of the MAD. *		If an operation on this MAD fails, for example due to a timeout, *		then the transport layer will dispose of the MAD by sending *		it through the Dispatcher with this message type.  Presumably, *		there is a controller listening for the failure message that can *		properly clean up. * *	resp_expected *		TRUE if a response is expected to this MAD. *		FALSE otherwise. * *	p_mad *		Pointer to the wire MAD.  The MAD itself cannot be part of the *		wrapper, since wire MADs typically reside in special memory *		registered with the local HCA. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_init * NAME *	osm_madw_init * * DESCRIPTION *	Initializes a MAD Wrapper object for use. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_madw_init
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|,
name|IN
name|osm_bind_handle_t
name|h_bind
parameter_list|,
name|IN
name|uint32_t
name|mad_size
parameter_list|,
name|IN
specifier|const
name|osm_mad_addr_t
modifier|*
name|p_mad_addr
parameter_list|)
block|{
name|memset
argument_list|(
name|p_madw
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
operator|*
name|p_madw
argument_list|)
argument_list|)
expr_stmt|;
name|p_madw
operator|->
name|h_bind
operator|=
name|h_bind
expr_stmt|;
name|p_madw
operator|->
name|fail_msg
operator|=
name|CL_DISP_MSGID_NONE
expr_stmt|;
name|p_madw
operator|->
name|mad_size
operator|=
name|mad_size
expr_stmt|;
if|if
condition|(
name|p_mad_addr
condition|)
name|p_madw
operator|->
name|mad_addr
operator|=
operator|*
name|p_mad_addr
expr_stmt|;
name|p_madw
operator|->
name|resp_expected
operator|=
name|FALSE
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object to initialize. * *	h_bind *		[in] Pointer to the wire MAD. * *	p_mad_addr *		[in] Pointer to the MAD address structure.  This parameter may *		be NULL for directed route MADs. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_smp_ptr * NAME *	osm_madw_get_smp_ptr * * DESCRIPTION *	Gets a pointer to the SMP in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_smp_t
modifier|*
name|osm_madw_get_smp_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_smp_t
operator|*
operator|)
name|p_madw
operator|->
name|p_mad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object to initialize. * * RETURN VALUES *	Pointer to the start of the SMP MAD. * * NOTES * * SEE ALSO *	MAD Wrapper object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_sa_mad_ptr * NAME *	osm_madw_get_sa_mad_ptr * * DESCRIPTION *	Gets a pointer to the SA MAD in this MAD wrapper. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_sa_mad_t
modifier|*
name|osm_madw_get_sa_mad_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_sa_mad_t
operator|*
operator|)
name|p_madw
operator|->
name|p_mad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the SA MAD. * * NOTES * * SEE ALSO *	MAD Wrapper object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_perfmgt_mad_ptr * DESCRIPTION *	Gets a pointer to the PerfMgt MAD in this MAD wrapper. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_perfmgt_mad_t
modifier|*
name|osm_madw_get_perfmgt_mad_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_perfmgt_mad_t
operator|*
operator|)
name|p_madw
operator|->
name|p_mad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the PerfMgt MAD. * * NOTES * * SEE ALSO *	MAD Wrapper object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_cc_mad_ptr * DESCRIPTION *	Gets a pointer to the Congestion Control MAD in this MAD wrapper. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_cc_mad_t
modifier|*
name|osm_madw_get_cc_mad_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_cc_mad_t
operator|*
operator|)
name|p_madw
operator|->
name|p_mad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the Congestion Control MAD. * * NOTES * * SEE ALSO *	MAD Wrapper object *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_ni_context_ptr * NAME *	osm_madw_get_ni_context_ptr * * DESCRIPTION *	Gets a pointer to the NodeInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_ni_context_t
modifier|*
name|osm_madw_get_ni_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_ni_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_pi_context_ptr * NAME *	osm_madw_get_pi_context_ptr * * DESCRIPTION *	Gets a pointer to the PortInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_pi_context_t
modifier|*
name|osm_madw_get_pi_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_pi_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_gi_context_ptr * NAME *	osm_madw_get_gi_context_ptr * * DESCRIPTION *	Gets a pointer to the GUIDInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_gi_context_t
modifier|*
name|osm_madw_get_gi_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_gi_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_nd_context_ptr * NAME *	osm_madw_get_nd_context_ptr * * DESCRIPTION *	Gets a pointer to the NodeDescription context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_nd_context_t
modifier|*
name|osm_madw_get_nd_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_nd_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_lft_context_ptr * NAME *	osm_madw_get_lft_context_ptr * * DESCRIPTION *	Gets a pointer to the LFT context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_lft_context_t
modifier|*
name|osm_madw_get_lft_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_lft_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_mft_context_ptr * NAME *	osm_madw_get_mft_context_ptr * * DESCRIPTION *	Gets a pointer to the MFT context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_mft_context_t
modifier|*
name|osm_madw_get_mft_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_mft_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_si_context_ptr * NAME *	osm_madw_get_si_context_ptr * * DESCRIPTION *	Gets a pointer to the SwitchInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_si_context_t
modifier|*
name|osm_madw_get_si_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_si_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_smi_context_ptr * NAME *	osm_madw_get_smi_context_ptr * * DESCRIPTION *	Gets a pointer to the SMInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_smi_context_t
modifier|*
name|osm_madw_get_smi_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_smi_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_pkey_context_ptr * NAME *	osm_madw_get_pkey_context_ptr * * DESCRIPTION *	Gets a pointer to the P_Key context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_pkey_context_t
modifier|*
name|osm_madw_get_pkey_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_pkey_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_slvl_context_ptr * NAME *	osm_madw_get_slvl_context_ptr * * DESCRIPTION *	Gets a pointer to the PortInfo context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_slvl_context_t
modifier|*
name|osm_madw_get_slvl_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_slvl_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_vla_context_ptr * NAME *	osm_madw_get_vla_context_ptr * * DESCRIPTION *	Gets a pointer to the Vl Arb context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_vla_context_t
modifier|*
name|osm_madw_get_vla_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_vla_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_VENDOR_INTF_OPENIB
end_ifndef

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_arbitrary_context_ptr * NAME *	osm_madw_get_arbitrary_context_ptr * * DESCRIPTION *	Gets a pointer to the arbitrary context in this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_arbitrary_context_t
modifier|*
name|osm_madw_get_arbitrary_context_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
specifier|const
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_arbitrary_context_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|context
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Pointer to the start of the context structure. * * NOTES * * SEE ALSO *********/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_vend_ptr * NAME *	osm_madw_get_vend_ptr * * DESCRIPTION *	Gets a pointer to the vendor specific MAD wrapper component. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_vend_wrap_t
modifier|*
name|osm_madw_get_vend_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_vend_wrap_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|vend_wrap
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Gets a pointer to the vendor specific MAD wrapper component. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_bind_handle * NAME *	osm_madw_get_bind_handle * * DESCRIPTION *	Returns the bind handle associated with this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_bind_handle_t
name|osm_madw_get_bind_handle
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_bind_handle_t
operator|)
name|p_madw
operator|->
name|h_bind
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Returns the bind handle associated with this MAD. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_mad_addr_ptr * NAME *	osm_madw_get_mad_addr_ptr * * DESCRIPTION *	Returns the mad address structure associated with this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|osm_mad_addr_t
modifier|*
name|osm_madw_get_mad_addr_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|osm_mad_addr_t
operator|*
operator|)
operator|&
name|p_madw
operator|->
name|mad_addr
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Returns the mad address structure associated with this MAD. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_mad_ptr * NAME *	osm_madw_get_mad_ptr * * DESCRIPTION *	Returns the mad address structure associated with this MAD. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|ib_mad_t
modifier|*
name|osm_madw_get_mad_ptr
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|ib_mad_t
operator|*
operator|)
name|p_madw
operator|->
name|p_mad
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Returns the mad address structure associated with this MAD. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_get_err_msg * NAME *	osm_madw_get_err_msg * * DESCRIPTION *	Returns the message with which to post this mad wrapper if *	an error occurs during processing the mad. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_disp_msgid_t
name|osm_madw_get_err_msg
parameter_list|(
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|)
block|{
return|return
operator|(
operator|(
name|cl_disp_msgid_t
operator|)
name|p_madw
operator|->
name|fail_msg
operator|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * * RETURN VALUES *	Returns the message with which to post this mad wrapper if *	an error occurs during processing the mad. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_set_mad * NAME *	osm_madw_set_mad * * DESCRIPTION *	Associates a wire MAD with this MAD Wrapper object. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_madw_set_mad
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_madw
parameter_list|,
name|IN
specifier|const
name|ib_mad_t
modifier|*
name|p_mad
parameter_list|)
block|{
name|p_madw
operator|->
name|p_mad
operator|=
name|p_mad
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_madw *		[in] Pointer to an osm_madw_t object. * *	p_mad *		[in] Pointer to the wire MAD to attach to this wrapper. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: MAD Wrapper/osm_madw_copy_context * NAME *	osm_madw_copy_context * * DESCRIPTION *	Copies the controller context from one MAD Wrapper to another. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_madw_copy_context
parameter_list|(
name|IN
name|osm_madw_t
modifier|*
name|p_dest
parameter_list|,
name|IN
specifier|const
name|osm_madw_t
modifier|*
name|p_src
parameter_list|)
block|{
name|p_dest
operator|->
name|context
operator|=
name|p_src
operator|->
name|context
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_dest *		[in] Pointer to the destination osm_madw_t object. * *	p_src *		[in] Pointer to the source osm_madw_t object. * * RETURN VALUES *	None. * * NOTES * * SEE ALSO *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_MADW_H_ */
end_comment

end_unit

