begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2006 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2009-2011 ZIH, TU Dresden, Federal Republic of Germany. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  * 	Declaration of osm_opensm_t.  *	This object represents the OpenSM super object.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_OPENSM_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_OPENSM_H_
end_define

begin_include
include|#
directive|include
file|<stdio.h>
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
file|<complib/cl_passivelock.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_atomic.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_nodenamemap.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_console_io.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_stats.h>
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
file|<opensm/osm_sa.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_perfmgr.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_event_plugin.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_db.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_subnet.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_mad_pool.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_vl15intf.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_congestion_control.h>
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
comment|/****h* OpenSM/OpenSM * NAME *	OpenSM * * DESCRIPTION *	The OpenSM object encapsulates the information needed by the *	OpenSM to govern itself.  The OpenSM is one OpenSM object. * *	The OpenSM object is thread safe. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****d* OpenSM: OpenSM/osm_routing_engine_type_t * NAME *       osm_routing_engine_type_t * * DESCRIPTION *       Enumerates the possible routing engines that *       could be used to route a subnet. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_osm_routing_engine_type
block|{
name|OSM_ROUTING_ENGINE_TYPE_NONE
init|=
literal|0
block|,
name|OSM_ROUTING_ENGINE_TYPE_MINHOP
block|,
name|OSM_ROUTING_ENGINE_TYPE_UPDN
block|,
name|OSM_ROUTING_ENGINE_TYPE_DNUP
block|,
name|OSM_ROUTING_ENGINE_TYPE_FILE
block|,
name|OSM_ROUTING_ENGINE_TYPE_FTREE
block|,
name|OSM_ROUTING_ENGINE_TYPE_LASH
block|,
name|OSM_ROUTING_ENGINE_TYPE_DOR
block|,
name|OSM_ROUTING_ENGINE_TYPE_TORUS_2QOS
block|,
name|OSM_ROUTING_ENGINE_TYPE_SSSP
block|,
name|OSM_ROUTING_ENGINE_TYPE_DFSSSP
block|,
name|OSM_ROUTING_ENGINE_TYPE_UNKNOWN
block|}
name|osm_routing_engine_type_t
typedef|;
end_typedef

begin_comment
comment|/***********/
end_comment

begin_comment
comment|/****s* OpenSM: OpenSM/osm_routing_engine * NAME *	struct osm_routing_engine * * DESCRIPTION *	OpenSM routing engine module definition. * NOTES *	routing engine structure - multicast callbacks may be *	added later. */
end_comment

begin_struct
struct|struct
name|osm_routing_engine
block|{
name|osm_routing_engine_type_t
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
name|int
function_decl|(
modifier|*
name|build_lid_matrices
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ucast_build_fwd_tables
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ucast_dump_tables
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|update_sl2vl
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|osm_physp_t
modifier|*
name|port
parameter_list|,
name|IN
name|uint8_t
name|in_port_num
parameter_list|,
name|IN
name|uint8_t
name|out_port_num
parameter_list|,
name|IN
name|OUT
name|ib_slvl_table_t
modifier|*
name|t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|update_vlarb
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|osm_physp_t
modifier|*
name|port
parameter_list|,
name|IN
name|uint8_t
name|port_num
parameter_list|,
name|IN
name|OUT
name|ib_vl_arb_table_t
modifier|*
name|block
parameter_list|,
name|unsigned
name|block_length
parameter_list|,
name|unsigned
name|block_num
parameter_list|)
function_decl|;
name|uint8_t
function_decl|(
modifier|*
name|path_sl
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|uint8_t
name|path_sl_hint
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|slid
parameter_list|,
name|IN
specifier|const
name|ib_net16_t
name|dlid
parameter_list|)
function_decl|;
name|ib_api_status_t
function_decl|(
modifier|*
name|mcast_build_stree
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|,
name|IN
name|OUT
name|osm_mgrp_box_t
modifier|*
name|mgb
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
name|struct
name|osm_routing_engine
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* * FIELDS *	name *		The routing engine name (will be used in logs). * *	context *		The routing engine context. Will be passed as parameter *		to the callback functions. * *	build_lid_matrices *		The callback for lid matrices generation. * *	ucast_build_fwd_tables *		The callback for unicast forwarding table generation. * *	ucast_dump_tables *		The callback for dumping unicast routing tables. * *	update_sl2vl(void *context, IN osm_physp_t *port, *		     IN uint8_t in_port_num, IN uint8_t out_port_num, *		     OUT ib_slvl_table_t *t) *		The callback to allow routing engine input for SL2VL maps. *		*port is the physical port for which the SL2VL map is to be *		updated. For switches, in_port_num/out_port_num identify *		which part of the SL2VL map to update.  For router/HCA ports, *		in_port_num/out_port_num should be ignored. * *	update_vlarb(void *context, IN osm_physp_t *port, *		     IN uint8_t port_num, *		     IN OUT ib_vl_arb_table_t *block, *		     unsigned block_length, unsigned block_num) *		The callback to allow routing engine input for VLArbitration. *		*port is the physical port for which the VLArb table is to be *		updated. * *	path_sl *		The callback for computing path SL. * *	mcast_build_stree *		The callback for building the spanning tree for multicast *		forwarding, called per MLID. * *	destroy *		The destroy method, may be used for routing engine *		internals cleanup. * *	next *		Pointer to next routing engine in the list. */
end_comment

begin_comment
comment|/****s* OpenSM: OpenSM/osm_opensm_t * NAME *	osm_opensm_t * * DESCRIPTION *	OpenSM structure. * *	This object should be treated as opaque and should *	be manipulated only through the provided functions. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_opensm
block|{
specifier|const
name|char
modifier|*
name|osm_version
decl_stmt|;
name|osm_subn_t
name|subn
decl_stmt|;
name|osm_sm_t
name|sm
decl_stmt|;
name|osm_sa_t
name|sa
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_OSM_PERF_MGR
name|osm_perfmgr_t
name|perfmgr
decl_stmt|;
endif|#
directive|endif
comment|/* ENABLE_OSM_PERF_MGR */
name|osm_congestion_control_t
name|cc
decl_stmt|;
name|cl_qlist_t
name|plugin_list
decl_stmt|;
name|osm_db_t
name|db
decl_stmt|;
name|boolean_t
name|mad_pool_constructed
decl_stmt|;
name|osm_mad_pool_t
name|mad_pool
decl_stmt|;
name|osm_vendor_t
modifier|*
name|p_vendor
decl_stmt|;
name|boolean_t
name|vl15_constructed
decl_stmt|;
name|osm_vl15_t
name|vl15
decl_stmt|;
name|osm_log_t
name|log
decl_stmt|;
name|cl_dispatcher_t
name|disp
decl_stmt|;
name|cl_dispatcher_t
name|sa_set_disp
decl_stmt|;
name|boolean_t
name|sa_set_disp_initialized
decl_stmt|;
name|cl_plock_t
name|lock
decl_stmt|;
name|struct
name|osm_routing_engine
modifier|*
name|routing_engine_list
decl_stmt|;
name|struct
name|osm_routing_engine
modifier|*
name|routing_engine_used
decl_stmt|;
name|struct
name|osm_routing_engine
modifier|*
name|default_routing_engine
decl_stmt|;
name|boolean_t
name|no_fallback_routing_engine
decl_stmt|;
name|osm_stats_t
name|stats
decl_stmt|;
name|osm_console_t
name|console
decl_stmt|;
name|nn_map_t
modifier|*
name|node_name_map
decl_stmt|;
block|}
name|osm_opensm_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * 	osm_version * 		OpenSM version (as generated in osm_version.h) * *	subn *		Subnet object for this subnet. * *	sm *		The Subnet Manager (SM) object for this subnet. * *	sa *		The Subnet Administration (SA) object for this subnet. * *	db *		Persistant storage of some data required between sessions. * *	mad_pool *		Pool of Management Datagram (MAD) objects. * *	p_vendor *		Pointer to the Vendor specific adapter for various *		transport interfaces, such as UMADT, AL, etc.  The *		particular interface is set at compile time. * *	vl15 *		The VL15 interface. * *	log *		Log facility used by all OpenSM components. * *	disp *		Central dispatcher containing the OpenSM worker threads. * *	sa_set_disp *		Dispatcher for SA Set and Delete requests. * *	sa_set_disp_initialized. *		Indicator that sa_set_disp dispatcher was initialized. * *	lock *		Shared lock guarding most OpenSM structures. * *	routing_engine_list *		List of routing engines that should be tried for use. * *	routing_engine_used *		Indicates which routing engine was used to route a subnet. * *	no_fallback_routing_engine *		Indicates if default routing engine should not be used. * *	stats *		Open SM statistics block * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_construct * NAME *	osm_opensm_construct * * DESCRIPTION *	This function constructs an OpenSM object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_opensm_construct
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to a OpenSM object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_opensm_init, osm_opensm_destroy * *	Calling osm_opensm_construct is a prerequisite to calling any other *	method except osm_opensm_init. * * SEE ALSO *	SM object, osm_opensm_init, osm_opensm_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_construct_finish * NAME *	osm_opensm_construct_finish * * DESCRIPTION *	The osm_opensm_construct_finish function completes *	the second phase of constucting an OpenSM object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_opensm_construct_finish
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to a OpenSM object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Calling osm_opensm_construct/osm_construct_finish is a prerequisite *	to calling any other method except osm_opensm_init/osm_opensm_init_finish. * * SEE ALSO *	SM object, osm_opensm_init, osm_opensm_construct_finish, *	osm_opensm_destroy, osm_opensm_destroy_finish *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_destroy * NAME *	osm_opensm_destroy * * DESCRIPTION *	The osm_opensm_destroy function destroys an SM, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_opensm_destroy
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to a OpenSM object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified OpenSM object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_opensm_construct or *	osm_opensm_init. * * SEE ALSO *	SM object, osm_opensm_construct, osm_opensm_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_destroy_finish * NAME *	osm_opensm_destroy_finish * * DESCRIPTION *	The osm_opensm_destroy_finish function handles the second phase *	of destroying an SM, releasing all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_opensm_destroy_finish
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to a OpenSM object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs second phase of any necessary cleanup of the specified OpenSM object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to *	osm_opensm_construct_finish or osm_opensm_init_finish. * * SEE ALSO *	SM object, osm_opensm_construct, osm_opensm_construct_finish, *	osm_opensm_init, osm_opensm_init_finish *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_init * NAME *	osm_opensm_init * * DESCRIPTION *	The osm_opensm_init function initializes a OpenSM object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_opensm_init
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|,
name|IN
specifier|const
name|osm_subn_opt_t
modifier|*
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object to initialize. * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	IB_SUCCESS if the OpenSM object was initialized successfully. * * NOTES *	Allows calling other OpenSM methods. * * SEE ALSO *	SM object, osm_opensm_construct, osm_opensm_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_init_finish * NAME *	osm_opensm_init_finish * * DESCRIPTION *	The osm_opensm_init_finish function performs the second phase *	of initialization of an OpenSM object. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_opensm_init_finish
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|,
name|IN
specifier|const
name|osm_subn_opt_t
modifier|*
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object to initialize. * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	IB_SUCCESS if the OpenSM object was initialized successfully. * * NOTES *	Allows calling other OpenSM methods. * * SEE ALSO *	SM object, osm_opensm_construct, osm_opensm_construct_finish, *	osm_opensm_destroy, osm_opensm_destroy_finish *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_sweep * NAME *	osm_opensm_sweep * * DESCRIPTION *	Initiates a subnet sweep. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_opensm_sweep
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|)
block|{
name|osm_sm_sweep
argument_list|(
operator|&
name|p_osm
operator|->
name|sm
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object on which to *		initiate a sweep. * * RETURN VALUES *	None * * NOTES *	If the OpenSM object is not bound to a port, this function *	does nothing. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_set_log_flags * NAME *	osm_opensm_set_log_flags * * DESCRIPTION *	Sets the log level. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_opensm_set_log_flags
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|,
name|IN
name|osm_log_level_t
name|log_flags
parameter_list|)
block|{
name|osm_log_set_level
argument_list|(
operator|&
name|p_osm
operator|->
name|log
argument_list|,
name|log_flags
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object. * *	log_flags *		[in] Log level flags to set. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_bind * NAME *	osm_opensm_bind * * DESCRIPTION *	Binds the opensm object to a port guid. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_opensm_bind
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|,
name|IN
name|ib_net64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object to bind. * *	guid *		[in] Local port GUID with which to bind. * * RETURN VALUES *	None * * NOTES *	A given opensm object can only be bound to one port at a time. * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_opensm_wait_for_subnet_up * NAME *	osm_opensm_wait_for_subnet_up * * DESCRIPTION *	Blocks the calling thread until the subnet is up. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|cl_status_t
name|osm_opensm_wait_for_subnet_up
parameter_list|(
name|IN
name|osm_opensm_t
modifier|*
name|p_osm
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
name|osm_sm_wait_for_subnet_up
argument_list|(
operator|&
name|p_osm
operator|->
name|sm
argument_list|,
name|wait_us
argument_list|,
name|interruptible
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_osm *		[in] Pointer to an osm_opensm_t object. * *	wait_us *		[in] Number of microseconds to wait. * *	interruptible *		[in] Indicates whether the wait operation can be interrupted *		by external signals. * * RETURN VALUES *	CL_SUCCESS if the wait operation succeeded in response to the event *	being set. * *	CL_TIMEOUT if the specified time period elapses. * *	CL_NOT_DONE if the wait was interrupted by an external signal. * *	CL_ERROR if the wait operation failed. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_routing_engine_type_str * NAME *	osm_routing_engine_type_str * * DESCRIPTION *	Returns a string for the specified routing engine type. * * SYNOPSIS */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|osm_routing_engine_type_str
parameter_list|(
name|IN
name|osm_routing_engine_type_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	type *		[in] routing engine type. * * RETURN VALUES *	Pointer to routing engine name. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: OpenSM/osm_routing_engine_type * NAME *	osm_routing_engine_type * * DESCRIPTION *	Returns a routing engine type specified routing engine name string. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_routing_engine_type_t
name|osm_routing_engine_type
parameter_list|(
name|IN
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	str *		[in] routing engine name string. * * RETURN VALUES *	Routing engine type. * * NOTES * * SEE ALSO *********/
end_comment

begin_function_decl
name|void
name|osm_opensm_report_event
parameter_list|(
name|osm_opensm_t
modifier|*
name|osm
parameter_list|,
name|osm_epi_event_id_t
name|event_id
parameter_list|,
name|void
modifier|*
name|event_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dump helpers */
end_comment

begin_function_decl
name|void
name|osm_dump_mcast_routes
parameter_list|(
name|osm_opensm_t
modifier|*
name|osm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_all
parameter_list|(
name|osm_opensm_t
modifier|*
name|osm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_dump_qmap_to_file
parameter_list|(
name|osm_opensm_t
modifier|*
name|p_osm
parameter_list|,
specifier|const
name|char
modifier|*
name|file_name
parameter_list|,
name|cl_qmap_t
modifier|*
name|map
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|cl_map_item_t
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cxt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****v* OpenSM/osm_exit_flag */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|unsigned
name|int
name|osm_exit_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * DESCRIPTION *  Set to one to cause all threads to leave *********/
end_comment

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_OPENSM_H_ */
end_comment

end_unit

