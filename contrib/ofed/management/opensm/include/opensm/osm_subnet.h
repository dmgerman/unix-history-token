begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2008 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2008 Xsigo Systems Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *	Declaration of osm_subn_t.  *	This object represents an IBA subnet.  *	This object is part of the OpenSM family of objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_SUBNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_SUBNET_H_
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_map.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_ptr_vector.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_list.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_base.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_prefix_route.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_define
define|#
directive|define
name|OSM_SUBNET_VECTOR_MIN_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|OSM_SUBNET_VECTOR_GROW_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|OSM_SUBNET_VECTOR_CAPACITY
value|256
end_define

begin_struct_decl
struct_decl|struct
name|osm_opensm
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_qos_policy
struct_decl|;
end_struct_decl

begin_comment
comment|/****h* OpenSM/Subnet * NAME *	Subnet * * DESCRIPTION *	The Subnet object encapsulates the information needed by the *	OpenSM to manage a subnet.  The OpenSM allocates one Subnet object *	per IBA subnet. * *	The Subnet object is not thread safe, thus callers must provide *	serialization. * *	This object is essentially a container for the various components *	of a subnet.  Callers may directly access the member variables. * * AUTHOR *	Steve King, Intel * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_qos_options_t * NAME *	osm_qos_options_t * * DESCRIPTION *	Subnet QoS options structure.  This structure contains the various *	QoS specific configuration parameters for the subnet. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_options
block|{
name|unsigned
name|max_vls
decl_stmt|;
name|int
name|high_limit
decl_stmt|;
name|char
modifier|*
name|vlarb_high
decl_stmt|;
name|char
modifier|*
name|vlarb_low
decl_stmt|;
name|char
modifier|*
name|sl2vl
decl_stmt|;
block|}
name|osm_qos_options_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	max_vls *		The number of maximum VLs on the Subnet (0 == use default) * *	high_limit *		The limit of High Priority component of VL Arbitration *		table (IBA 7.6.9) (-1 == use default) * *	vlarb_high *		High priority VL Arbitration table template. (NULL == use default) * *	vlarb_low *		Low priority VL Arbitration table template. (NULL == use default) * *	sl2vl *		SL2VL Mapping table (IBA 7.6.6) template. (NULL == use default) * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_subn_opt_t * NAME *	osm_subn_opt_t * * DESCRIPTION *	Subnet options structure.  This structure contains the various *	site specific configuration parameters for the subnet. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_subn_opt
block|{
name|char
modifier|*
name|config_file
decl_stmt|;
name|ib_net64_t
name|guid
decl_stmt|;
name|ib_net64_t
name|m_key
decl_stmt|;
name|ib_net64_t
name|sm_key
decl_stmt|;
name|ib_net64_t
name|sa_key
decl_stmt|;
name|ib_net64_t
name|subnet_prefix
decl_stmt|;
name|ib_net16_t
name|m_key_lease_period
decl_stmt|;
name|uint32_t
name|sweep_interval
decl_stmt|;
name|uint32_t
name|max_wire_smps
decl_stmt|;
name|uint32_t
name|transaction_timeout
decl_stmt|;
name|uint8_t
name|sm_priority
decl_stmt|;
name|uint8_t
name|lmc
decl_stmt|;
name|boolean_t
name|lmc_esp0
decl_stmt|;
name|uint8_t
name|max_op_vls
decl_stmt|;
name|uint8_t
name|force_link_speed
decl_stmt|;
name|boolean_t
name|reassign_lids
decl_stmt|;
name|boolean_t
name|ignore_other_sm
decl_stmt|;
name|boolean_t
name|single_thread
decl_stmt|;
name|boolean_t
name|disable_multicast
decl_stmt|;
name|boolean_t
name|force_log_flush
decl_stmt|;
name|uint8_t
name|subnet_timeout
decl_stmt|;
name|uint8_t
name|packet_life_time
decl_stmt|;
name|uint8_t
name|vl_stall_count
decl_stmt|;
name|uint8_t
name|leaf_vl_stall_count
decl_stmt|;
name|uint8_t
name|head_of_queue_lifetime
decl_stmt|;
name|uint8_t
name|leaf_head_of_queue_lifetime
decl_stmt|;
name|uint8_t
name|local_phy_errors_threshold
decl_stmt|;
name|uint8_t
name|overrun_errors_threshold
decl_stmt|;
name|uint32_t
name|sminfo_polling_timeout
decl_stmt|;
name|uint32_t
name|polling_retry_number
decl_stmt|;
name|uint32_t
name|max_msg_fifo_timeout
decl_stmt|;
name|boolean_t
name|force_heavy_sweep
decl_stmt|;
name|uint8_t
name|log_flags
decl_stmt|;
name|char
modifier|*
name|dump_files_dir
decl_stmt|;
name|char
modifier|*
name|log_file
decl_stmt|;
name|unsigned
name|long
name|log_max_size
decl_stmt|;
name|char
modifier|*
name|partition_config_file
decl_stmt|;
name|boolean_t
name|no_partition_enforcement
decl_stmt|;
name|boolean_t
name|qos
decl_stmt|;
name|char
modifier|*
name|qos_policy_file
decl_stmt|;
name|boolean_t
name|accum_log_file
decl_stmt|;
name|char
modifier|*
name|console
decl_stmt|;
name|uint16_t
name|console_port
decl_stmt|;
name|char
modifier|*
name|port_prof_ignore_file
decl_stmt|;
name|boolean_t
name|port_profile_switch_nodes
decl_stmt|;
name|boolean_t
name|sweep_on_trap
decl_stmt|;
name|char
modifier|*
name|routing_engine_names
decl_stmt|;
name|boolean_t
name|use_ucast_cache
decl_stmt|;
name|boolean_t
name|connect_roots
decl_stmt|;
name|char
modifier|*
name|lid_matrix_dump_file
decl_stmt|;
name|char
modifier|*
name|lfts_file
decl_stmt|;
name|char
modifier|*
name|root_guid_file
decl_stmt|;
name|char
modifier|*
name|cn_guid_file
decl_stmt|;
name|char
modifier|*
name|ids_guid_file
decl_stmt|;
name|char
modifier|*
name|guid_routing_order_file
decl_stmt|;
name|char
modifier|*
name|sa_db_file
decl_stmt|;
name|boolean_t
name|exit_on_fatal
decl_stmt|;
name|boolean_t
name|honor_guid2lid_file
decl_stmt|;
name|boolean_t
name|daemon
decl_stmt|;
name|boolean_t
name|sm_inactive
decl_stmt|;
name|boolean_t
name|babbling_port_policy
decl_stmt|;
name|osm_qos_options_t
name|qos_options
decl_stmt|;
name|osm_qos_options_t
name|qos_ca_options
decl_stmt|;
name|osm_qos_options_t
name|qos_sw0_options
decl_stmt|;
name|osm_qos_options_t
name|qos_swe_options
decl_stmt|;
name|osm_qos_options_t
name|qos_rtr_options
decl_stmt|;
name|boolean_t
name|enable_quirks
decl_stmt|;
name|boolean_t
name|no_clients_rereg
decl_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_OSM_PERF_MGR
name|boolean_t
name|perfmgr
decl_stmt|;
name|boolean_t
name|perfmgr_redir
decl_stmt|;
name|uint16_t
name|perfmgr_sweep_time_s
decl_stmt|;
name|uint32_t
name|perfmgr_max_outstanding_queries
decl_stmt|;
name|char
modifier|*
name|event_db_dump_file
decl_stmt|;
endif|#
directive|endif
comment|/* ENABLE_OSM_PERF_MGR */
name|char
modifier|*
name|event_plugin_name
decl_stmt|;
name|char
modifier|*
name|node_name_map_name
decl_stmt|;
name|char
modifier|*
name|prefix_routes_file
decl_stmt|;
name|boolean_t
name|consolidate_ipv6_snm_req
decl_stmt|;
block|}
name|osm_subn_opt_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	config_file *		The name of the config file. * *	guid *		The port guid that the SM is binding to. * *	m_key *		M_Key value sent to all ports qualifying all Set(PortInfo). * *	sm_key *		SM_Key value of the SM used for SM authentication. * *	sa_key *		SM_Key value to qualify rcv SA queries as "trusted". * *	subnet_prefix *		Subnet prefix used on this subnet. * *	m_key_lease_period *		The lease period used for the M_Key on this subnet. * *	sweep_interval *		The number of seconds between subnet sweeps.  A value of 0 *		disables sweeping. * *	max_wire_smps *		The maximum number of SMPs sent in parallel.  Default is 4. * *	transaction_timeout *		The maximum time in milliseconds allowed for a transaction *		to complete.  Default is 200. * *	sm_priority *		The priority of this SM as specified by the user.  This *		value is made available in the SMInfo attribute. * *	lmc *		The LMC value used on this subnet. * *	lmc_esp0 *		Whether LMC value used on subnet should be used for *		enhanced switch port 0 or not.  If TRUE, it is used. *		Otherwise (the default), LMC is set to 0 for ESP0. * *	max_op_vls *		Limit the maximal operational VLs. default is 1. * *	reassign_lids *		If TRUE cause all lids to be re-assigend. *		Otherwise (the default), *		OpenSM always tries to preserve as LIDs as much as possible. * *	ignore_other_sm_option *		This flag is TRUE if other SMs on the subnet should be ignored. * *	disable_multicast *		This flag is TRUE if OpenSM should disable multicast support. * *	max_msg_fifo_timeout *		The maximal time a message can stay in the incoming message *		queue. If there is more than one message in the queue and the *		last message stayed in the queue more than this value the SA *		request will be immediately returned with a BUSY status. * *	subnet_timeout *		The subnet_timeout that will be set for all the ports in the *		design SubnSet(PortInfo.vl_stall_life)) * *	vl_stall_count *		The number of sequential packets dropped that cause the port *		to enter the VLStalled state. * *	leaf_vl_stall_count *		The number of sequential packets dropped that cause the port *		to enter the VLStalled state. This is for switch ports driving *		a CA or router port. * *	head_of_queue_lifetime *		The maximal time a packet can live at the head of a VL queue *		on any port not driving a CA or router port. * *	leaf_head_of_queue_lifetime *		The maximal time a packet can live at the head of a VL queue *		on switch ports driving a CA or router. * *	local_phy_errors_threshold *		Threshold of local phy errors for sending Trap 129 * *	overrun_errors_threshold *		Threshold of credits overrun errors for sending Trap 129 * *	sminfo_polling_timeout *		Specifies the polling timeout (in milliseconds) - the timeout *		between one poll to another. * *	packet_life_time *		The maximal time a packet can stay in a switch. *		The value is send to all switches as *		SubnSet(SwitchInfo.life_state) * *	dump_files_dir *		The directory to be used for opensm-subnet.lst, opensm.fdbs, *		opensm.mcfdbs, and default log file (the latter for Windows, *		not Linux). * *	log_file *		Name of the log file (or NULL) for stdout. * *	log_max_size *		This option defines maximal log file size in MB. When *		specified the log file will be truncated upon reaching *		this limit. * *	qos *		Boolean that specifies whether the OpenSM QoS functionality *		should be off or on. * *	qos_policy_file *		Name of the QoS policy file. * *	accum_log_file *		If TRUE (default) - the log file will be accumulated. *		If FALSE - the log file will be erased before starting *		current opensm run. * *	port_prof_ignore_file *		Name of file with port guids to be ignored by port profiling. * *	port_profile_switch_nodes *		If TRUE will count the number of switch nodes routed through *		the link. If FALSE - only CA/RT nodes are counted. * *	sweep_on_trap *		Received traps will initiate a new sweep. * *	routing_engine_names *		Name of routing engine(s) to use. * *	connect_roots *		The option which will enforce root to root connectivity with *		up/down routing engine (even if this violates "pure" deadlock *		free up/down algorithm) * *	use_ucast_cache *		When TRUE enables unicast routing cache. * *	lid_matrix_dump_file *		Name of the lid matrix dump file from where switch *		lid matrices (min hops tables) will be loaded * *	lfts_file *		Name of the unicast LFTs routing file from where switch *		forwarding tables will be loaded * *	root_guid_file *		Name of the file that contains list of root guids that *		will be used by fat-tree or up/dn routing (provided by User) * *	cn_guid_file *		Name of the file that contains list of compute node guids that *		will be used by fat-tree routing (provided by User) * *	ids_guid_file *		Name of the file that contains list of ids which should be *		used by Up/Down algorithm instead of node GUIDs * *	guid_routing_order_file *		Name of the file that contains list of guids for routing order *		that will be used by minhop and up/dn routing (provided by User). * *	sa_db_file *		Name of the SA database file. * *	exit_on_fatal *		If TRUE (default) - SM will exit on fatal subnet initialization *		issues. *		If FALSE - SM will not exit. *		Fatal initialization issues: *		a. SM recognizes 2 different nodes with the same guid, or *		   12x link with lane reversal badly configured. * *	honor_guid2lid_file *		Always honor the guid2lid file if it exists and is valid. This *		means that the file will be honored when SM is coming out of *		STANDBY. By default this is FALSE. * *	daemon *		OpenSM will run in daemon mode. * *	sm_inactive *		OpenSM will start with SM in not active state. * *	babbling_port_policy *		OpenSM will enforce its "babbling" port policy. * *	perfmgr *		Enable or disable the performance manager * *	perfmgr_redir *		Enable or disable the saving of redirection by PerfMgr * *	perfmgr_sweep_time_s *		Define the period (in seconds) of PerfMgr sweeps * *       event_db_dump_file *               File to dump the event database to * *       event_db_plugin *               Specify the name of the event plugin * *	qos_options *		Default set of QoS options * *	qos_ca_options *		QoS options for CA ports * *	qos_sw0_options *		QoS options for switches' port 0 * *	qos_swe_options *		QoS options for switches' external ports * *	qos_rtr_options *		QoS options for router ports * *	enable_quirks *		Enable high risk new features and not fully qualified *		hardware specific work arounds * *	no_clients_rereg *		When TRUE disables clients reregistration request. * * SEE ALSO *	Subnet object *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_subn_t * NAME *	osm_subn_t * * DESCRIPTION *	Subnet structure.  Callers may directly access member components, *	after grabbing a lock. * * TO DO *	This structure should probably be volatile. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_subn
block|{
name|struct
name|osm_opensm
modifier|*
name|p_osm
decl_stmt|;
name|cl_qmap_t
name|sw_guid_tbl
decl_stmt|;
name|cl_qmap_t
name|node_guid_tbl
decl_stmt|;
name|cl_qmap_t
name|port_guid_tbl
decl_stmt|;
name|cl_qmap_t
name|rtr_guid_tbl
decl_stmt|;
name|cl_qlist_t
name|prefix_routes_list
decl_stmt|;
name|cl_qmap_t
name|prtn_pkey_tbl
decl_stmt|;
name|cl_qmap_t
name|sm_guid_tbl
decl_stmt|;
name|cl_qlist_t
name|sa_sr_list
decl_stmt|;
name|cl_qlist_t
name|sa_infr_list
decl_stmt|;
name|cl_ptr_vector_t
name|port_lid_tbl
decl_stmt|;
name|ib_net16_t
name|master_sm_base_lid
decl_stmt|;
name|ib_net16_t
name|sm_base_lid
decl_stmt|;
name|ib_net64_t
name|sm_port_guid
decl_stmt|;
name|uint8_t
name|sm_state
decl_stmt|;
name|osm_subn_opt_t
name|opt
decl_stmt|;
name|struct
name|osm_qos_policy
modifier|*
name|p_qos_policy
decl_stmt|;
name|uint16_t
name|max_ucast_lid_ho
decl_stmt|;
name|uint16_t
name|max_mcast_lid_ho
decl_stmt|;
name|uint8_t
name|min_ca_mtu
decl_stmt|;
name|uint8_t
name|min_ca_rate
decl_stmt|;
name|boolean_t
name|ignore_existing_lfts
decl_stmt|;
name|boolean_t
name|subnet_initialization_error
decl_stmt|;
name|boolean_t
name|force_heavy_sweep
decl_stmt|;
name|boolean_t
name|force_reroute
decl_stmt|;
name|boolean_t
name|in_sweep_hop_0
decl_stmt|;
name|boolean_t
name|first_time_master_sweep
decl_stmt|;
name|boolean_t
name|coming_out_of_standby
decl_stmt|;
name|unsigned
name|need_update
decl_stmt|;
name|void
modifier|*
name|mgroups
index|[
name|IB_LID_MCAST_END_HO
operator|-
name|IB_LID_MCAST_START_HO
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|osm_subn_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	sw_guid_tbl *		Container of pointers to all Switch objects in the subent. *		Indexed by node GUID. * *	node_guid_tbl *		Container of pointers to all Node objects in the subent. *		Indexed by node GUID. * *	port_guid_tbl *		Container of pointers to all Port objects in the subent. *		Indexed by port GUID - network order! * *	rtr_guid_tbl *		Container of pointers to all Router objects in the subent. *		Indexed by node GUID. * *	prtn_pkey_tbl *		Container of pointers to all Partition objects in the subnet. *		Indexed by P_KEY. * *	sm_guid_tbl *		Container of pointers to SM objects representing other SMs *		on the subnet. * *	port_lid_tbl *		Container of pointers to all Port objects in the subent. *		Indexed by port LID. * *	master_sm_base_lid *		The base LID owned by the subnet's master SM. * *	sm_base_lid *		The base LID of the local port where the SM is. * *	sm_port_guid *		This SM's own port GUID. * *	sm_state *		The high-level state of the SM.  This value is made available *		in the SMInfo attribute. * *	opt *		Subnet options structure contains site specific configuration. * *	p_qos_policy *		Subnet QoS policy structure. * *	max_ucast_lid_ho *		The minimal max unicast lid reported by all switches * *	max_mcast_lid_ho *		The minimal max multicast lid reported by all switches * *	min_ca_mtu *		The minimal MTU reported by all CAs ports on the subnet * *	min_ca_rate *		The minimal rate reported by all CA ports on the subnet * *	ignore_existing_lfts *		This flag is a dynamic flag to instruct the LFT assignment to *		ignore existing legal LFT settings. *		The value will be set according to : *		- Any change to the list of switches will set it to high *		- Coming out of STANDBY it will be cleared (other SM worked) *		- Set to FALSE upon end of all lft assignments. * *	subnet_initalization_error *		Similar to the force_heavy_sweep flag. If TRUE - means that *		we had errors during initialization (due to SubnSet requests *		that failed). We want to declare the subnet as unhealthy, and *		force another heavy sweep. * *	force_heavy_sweep *		If TRUE - we want to force a heavy sweep. This can be done *		either due to receiving of trap - meaning there is some change *		on the subnet, or we received a handover from a remote sm. *		In this case we want to sweep and reconfigure the entire *		subnet. This will cause another heavy sweep to occure when *		the current sweep is done. * *	force_reroute *		If TRUE - we want to force switches in the fabric to be *		rerouted. * *	in_sweep_hop_0 *		When in_sweep_hop_0 flag is set to TRUE - this means we are *		in sweep_hop_0 - meaning we do not want to continue beyond *		the current node. *		This is relevant for the case of SM on switch, since in the *		switch info we need to signal somehow not to continue *		the sweeping. * *	first_time_master_sweep *		This flag is used for the PortInfo setting. On the first *		sweep as master (meaning after moving from Standby|Discovering *		state), the SM must send a PortInfoSet to all ports. After *		that - we want to minimize the number of PortInfoSet requests *		sent, and to send only requests that change the value from *		what is updated in the port (or send a first request if this *		is a new port). We will set this flag to TRUE when entering *		the master state, and set it back to FALSE at the end of the *		drop manager. This is done since at the end of the drop manager *		we have updated all the ports that are reachable, and from now *		on these are the only ports we have data of. We don't want *		to send extra set requests to these ports anymore. * *	coming_out_of_standby *		TRUE on the first sweep after the SM was in standby. *		Used for nulling any cache of LID and Routing. *		The flag is set true if the SM state was standby and now *		changed to MASTER it is reset at the end of the sweep. * *	need_update *		This flag should be on during first non-master heavy *		(including pre-master discovery stage) * *	mgroups *		Array of pointers to all Multicast Group objects in the subnet. *		Indexed by MLID offset from base MLID. * * SEE ALSO *	Subnet object *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_construct * NAME *	osm_subn_construct * * DESCRIPTION *	This function constructs a Subnet object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_subn_construct
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
specifier|const
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to a Subnet object to construct. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Allows calling osm_subn_init, and osm_subn_destroy. * *	Calling osm_subn_construct is a prerequisite to calling any other *	method except osm_subn_init. * * SEE ALSO *	Subnet object, osm_subn_init, osm_subn_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_destroy * NAME *	osm_subn_destroy * * DESCRIPTION *	The osm_subn_destroy function destroys a subnet, releasing *	all resources. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_subn_destroy
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
specifier|const
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to a Subnet object to destroy. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified Subnet object. *	Further operations should not be attempted on the destroyed object. *	This function should only be called after a call to osm_subn_construct *	or osm_subn_init. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_init *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_init * NAME *	osm_subn_init * * DESCRIPTION *	The osm_subn_init function initializes a Subnet object for use. * * SYNOPSIS */
end_comment

begin_function_decl
name|ib_api_status_t
name|osm_subn_init
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
specifier|const
name|p_subn
parameter_list|,
name|IN
name|struct
name|osm_opensm
modifier|*
specifier|const
name|p_osm
parameter_list|,
name|IN
specifier|const
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object to initialize. * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	IB_SUCCESS if the Subnet object was initialized successfully. * * NOTES *	Allows calling other Subnet methods. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy *********/
end_comment

begin_comment
comment|/*   Forward references. */
end_comment

begin_struct_decl
struct_decl|struct
name|osm_mad_addr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_log
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_switch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_physp
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_port
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|osm_mgrp
struct_decl|;
end_struct_decl

begin_comment
comment|/****f* OpenSM: Helper/osm_get_gid_by_mad_addr * NAME *	osm_get_gid_by_mad_addr * * DESCRIPTION *	Looks for the requester gid in the mad address. * * Note: This code is not thread safe. Need to grab the lock before * calling it. * * SYNOPSIS */
end_comment

begin_decl_stmt
name|ib_api_status_t
name|osm_get_gid_by_mad_addr
argument_list|(
name|IN
expr|struct
name|osm_log
operator|*
name|p_log
argument_list|,
name|IN
specifier|const
name|osm_subn_t
operator|*
name|p_subn
argument_list|,
name|IN
specifier|const
expr|struct
name|osm_mad_addr
operator|*
name|p_mad_addr
argument_list|,
name|OUT
name|ib_gid_t
operator|*
name|p_gid
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to subnet object. * *	p_mad_addr *		[in] Pointer to mad address object. * *	p_gid *		[out] Pointer to the GID structure to fill in. * * RETURN VALUES *     IB_SUCCESS if able to find the GID by address given. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_get_physp_by_mad_addr * NAME *	osm_get_physp_by_mad_addr * * DESCRIPTION *	Looks for the requester physical port in the mad address. * * Note: This code is not thread safe. Need to grab the lock before * calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_physp
modifier|*
name|osm_get_physp_by_mad_addr
parameter_list|(
name|IN
name|struct
name|osm_log
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|struct
name|osm_mad_addr
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to subnet object. * *	p_mad_addr *		[in] Pointer to mad address object. * * RETURN VALUES *	Pointer to requester physical port object if found. Null otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_get_port_by_mad_addr * NAME *	osm_get_port_by_mad_addr * * DESCRIPTION *	Looks for the requester port in the mad address. * * Note: This code is not thread safe. Need to grab the lock before * calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_port
modifier|*
name|osm_get_port_by_mad_addr
parameter_list|(
name|IN
name|struct
name|osm_log
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|struct
name|osm_mad_addr
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to subnet object. * *	p_mad_addr *		[in] Pointer to mad address object. * * RETURN VALUES *	Pointer to requester port object if found. Null otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_switch_by_guid * NAME *	osm_get_switch_by_guid * * DESCRIPTION *	Looks for the given switch guid in the subnet table of switches by guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_switch
modifier|*
name|osm_get_switch_by_guid
parameter_list|(
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The node guid in host order * * RETURN VALUES *	The switch structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_switch_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_node_by_guid * NAME *	osm_get_node_by_guid * * DESCRIPTION *	The looks for the given node giud in the subnet table of nodes by guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_node
modifier|*
name|osm_get_node_by_guid
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The node guid in host order * * RETURN VALUES *	The node structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_node_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_port_by_guid * NAME *	osm_get_port_by_guid * * DESCRIPTION *	The looks for the given port guid in the subnet table of ports by guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_port
modifier|*
name|osm_get_port_by_guid
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|ib_net64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The port guid in network order * * RETURN VALUES *	The port structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_port_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_mgrp_by_mlid * NAME *	osm_get_mgrp_by_mlid * * DESCRIPTION *	The looks for the given multicast group in the subnet table by mlid. *	NOTE: this code is not thread safe. Need to grab the lock before *	calling it. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|osm_mgrp
modifier|*
name|osm_get_mgrp_by_mlid
parameter_list|(
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|ib_net16_t
name|mlid
parameter_list|)
block|{
return|return
name|p_subn
operator|->
name|mgroups
index|[
name|cl_ntoh16
argument_list|(
name|mlid
argument_list|)
operator|-
name|IB_LID_MCAST_START_HO
index|]
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	mlid *		[in] The multicast group mlid in network order * * RETURN VALUES *	The multicast group structure pointer if found. NULL otherwise. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Helper/osm_get_physp_by_mad_addr * NAME *	osm_get_physp_by_mad_addr * * DESCRIPTION *	Looks for the requester physical port in the mad address. * * Note: This code is not thread safe. Need to grab the lock before * calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_physp
modifier|*
name|osm_get_physp_by_mad_addr
parameter_list|(
name|IN
name|struct
name|osm_log
modifier|*
name|p_log
parameter_list|,
name|IN
specifier|const
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|,
name|IN
name|struct
name|osm_mad_addr
modifier|*
name|p_mad_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_log *		[in] Pointer to a log object. * *	p_subn *		[in] Pointer to subnet object. * *	p_mad_addr *		[in] Pointer to mad address object. * * RETURN VALUES *	Pointer to requester physical port object if found. Null otherwise. * * NOTES * * SEE ALSO *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_set_default_opt * NAME *	osm_subn_set_default_opt * * DESCRIPTION *	The osm_subn_set_default_opt function sets the default options. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_subn_set_default_opt
parameter_list|(
name|IN
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	None * * NOTES * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_parse_conf_file * NAME *	osm_subn_parse_conf_file * * DESCRIPTION *	The osm_subn_parse_conf_file function parses the configuration file *	and sets the defaults accordingly. * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_subn_parse_conf_file
parameter_list|(
name|char
modifier|*
name|conf_file
parameter_list|,
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	0 on success, positive value if file doesn't exist, *	negative value otherwise *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_rescan_conf_files * NAME *	osm_subn_rescan_conf_files * * DESCRIPTION *	The osm_subn_rescan_conf_files function parses the configuration *	files and update selected subnet options * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_subn_rescan_conf_files
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
specifier|const
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_subn *		[in] Pointer to the subnet structure. * * RETURN VALUES *	0 on success, positive value if file doesn't exist, *	negative value otherwise * *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_output_conf * NAME *	osm_subn_output_conf * * DESCRIPTION *	Output configuration info * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_subn_output_conf
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|,
name|IN
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	out *		[in] File stream to output to. * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	0 on success, negative value otherwise *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_subn_write_conf_file * NAME *	osm_subn_write_conf_file * * DESCRIPTION *	Write the configuration file into the cache * * SYNOPSIS */
end_comment

begin_function_decl
name|int
name|osm_subn_write_conf_file
parameter_list|(
name|char
modifier|*
name|file_name
parameter_list|,
name|IN
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	0 on success, negative value otherwise * * NOTES *	Assumes the conf file is part of the cache dir which defaults to *	OSM_DEFAULT_CACHE_DIR or OSM_CACHE_DIR the name is opensm.opts *********/
end_comment

begin_function_decl
name|int
name|osm_subn_verify_config
parameter_list|(
name|osm_subn_opt_t
modifier|*
specifier|const
name|p_opt
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
comment|/* _OSM_SUBNET_H_ */
end_comment

end_unit

