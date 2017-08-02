begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2015 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  * Copyright (c) 2008 Xsigo Systems Inc.  All rights reserved.  * Copyright (c) 2009 System Fabric Works, Inc. All rights reserved.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  * Copyright (c) 2013 Oracle and/or its affiliates. All rights reserved.  * Copyright (c) 2009-2015 ZIH, TU Dresden, Federal Republic of Germany. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
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
file|<complib/cl_fleximap.h>
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
file|<opensm/osm_db.h>
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

begin_define
define|#
directive|define
name|OSM_PARTITION_ENFORCE_BOTH
value|"both"
end_define

begin_define
define|#
directive|define
name|OSM_PARTITION_ENFORCE_IN
value|"in"
end_define

begin_define
define|#
directive|define
name|OSM_PARTITION_ENFORCE_OUT
value|"out"
end_define

begin_define
define|#
directive|define
name|OSM_PARTITION_ENFORCE_OFF
value|"off"
end_define

begin_typedef
typedef|typedef
enum|enum
name|_osm_partition_enforce_type_enum
block|{
name|OSM_PARTITION_ENFORCE_TYPE_BOTH
block|,
name|OSM_PARTITION_ENFORCE_TYPE_IN
block|,
name|OSM_PARTITION_ENFORCE_TYPE_OUT
block|,
name|OSM_PARTITION_ENFORCE_TYPE_OFF
block|}
name|osm_partition_enforce_type_enum
typedef|;
end_typedef

begin_comment
comment|/* XXX: not actual max, max we're currently going to support */
end_comment

begin_define
define|#
directive|define
name|OSM_CCT_ENTRY_MAX
value|128
end_define

begin_define
define|#
directive|define
name|OSM_CCT_ENTRY_MAD_BLOCKS
value|(OSM_CCT_ENTRY_MAX/64)
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
comment|/****s* OpenSM: Subnet/osm_cct_entry_t * NAME *	osm_cct_entry_t * * DESCRIPTION *	Subnet Congestion Control Table entry.  See A10.2.2.1.1 for format details. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_cct_entry
block|{
name|uint8_t
name|shift
decl_stmt|;
comment|//Alex: shift 2 bits
name|uint16_t
name|multiplier
decl_stmt|;
comment|//Alex multiplier 14 bits
block|}
name|osm_cct_entry_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	shift *		shift field in CCT entry.  See A10.2.2.1.1. * *	multiplier *		multiplier field in CCT entry.  See A10.2.2.1.1. * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_cacongestion_entry_t * NAME *	osm_cacongestion_entry_t * * DESCRIPTION *	Subnet CA Congestion entry.  See A10.4.3.8.4 for format details. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_cacongestion_entry
block|{
name|ib_net16_t
name|ccti_timer
decl_stmt|;
comment|//Alex: ccti_timer and ccti_increase should be replaced
name|uint8_t
name|ccti_increase
decl_stmt|;
name|uint8_t
name|trigger_threshold
decl_stmt|;
name|uint8_t
name|ccti_min
decl_stmt|;
block|}
name|osm_cacongestion_entry_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	ccti_timer *		CCTI Timer * *	ccti_increase *		CCTI Increase * *	trigger_threshold *		CCTI trigger for log message * *	ccti_min *		CCTI Minimum * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_cct_t * NAME *	osm_cct_t * * DESCRIPTION *	Subnet CongestionControlTable.  See A10.4.3.9 for format details. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_cct
block|{
name|osm_cct_entry_t
name|entries
index|[
name|OSM_CCT_ENTRY_MAX
index|]
decl_stmt|;
name|unsigned
name|int
name|entries_len
decl_stmt|;
name|char
modifier|*
name|input_str
decl_stmt|;
block|}
name|osm_cct_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	entries *		Entries in CCT * *	entries_len *		Length of entries * *	input_str *		Original str input * *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_subn_opt_t * NAME *	osm_subn_opt_t * * DESCRIPTION *	Subnet options structure.  This structure contains the various *	site specific configuration parameters for the subnet. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_subn_opt
block|{
specifier|const
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
name|uint8_t
name|m_key_protect_bits
decl_stmt|;
name|boolean_t
name|m_key_lookup
decl_stmt|;
name|uint32_t
name|sweep_interval
decl_stmt|;
name|uint32_t
name|max_wire_smps
decl_stmt|;
name|uint32_t
name|max_wire_smps2
decl_stmt|;
name|uint32_t
name|max_smps_timeout
decl_stmt|;
name|uint32_t
name|transaction_timeout
decl_stmt|;
name|uint32_t
name|transaction_retries
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
name|uint8_t
name|force_link_speed_ext
decl_stmt|;
name|uint8_t
name|fdr10
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
name|boolean_t
name|use_mfttop
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
name|uint32_t
name|log_max_size
decl_stmt|;
name|char
modifier|*
name|partition_config_file
decl_stmt|;
name|boolean_t
name|no_partition_enforcement
decl_stmt|;
name|char
modifier|*
name|part_enforce
decl_stmt|;
name|osm_partition_enforce_type_enum
name|part_enforce_enum
decl_stmt|;
name|boolean_t
name|allow_both_pkeys
decl_stmt|;
name|uint8_t
name|sm_assigned_guid
decl_stmt|;
name|boolean_t
name|qos
decl_stmt|;
name|char
modifier|*
name|qos_policy_file
decl_stmt|;
name|boolean_t
name|suppress_sl2vl_mad_status_errors
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
name|char
modifier|*
name|hop_weights_file
decl_stmt|;
name|char
modifier|*
name|port_search_ordering_file
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
name|io_guid_file
decl_stmt|;
name|boolean_t
name|port_shifting
decl_stmt|;
name|uint32_t
name|scatter_ports
decl_stmt|;
name|uint16_t
name|max_reverse_hops
decl_stmt|;
name|char
modifier|*
name|ids_guid_file
decl_stmt|;
name|char
modifier|*
name|guid_routing_order_file
decl_stmt|;
name|boolean_t
name|guid_routing_order_no_scatter
decl_stmt|;
name|char
modifier|*
name|sa_db_file
decl_stmt|;
name|boolean_t
name|sa_db_dump
decl_stmt|;
name|char
modifier|*
name|torus_conf_file
decl_stmt|;
name|boolean_t
name|do_mesh_analysis
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
name|boolean_t
name|drop_event_subscriptions
decl_stmt|;
name|boolean_t
name|ipoib_mcgroup_creation_validation
decl_stmt|;
name|boolean_t
name|mcgroup_join_validation
decl_stmt|;
name|boolean_t
name|use_optimized_slvl
decl_stmt|;
name|boolean_t
name|fsync_high_avail_files
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
name|congestion_control
decl_stmt|;
name|ib_net64_t
name|cc_key
decl_stmt|;
name|uint32_t
name|cc_max_outstanding_mads
decl_stmt|;
name|ib_net32_t
name|cc_sw_cong_setting_control_map
decl_stmt|;
name|uint8_t
name|cc_sw_cong_setting_victim_mask
index|[
name|IB_CC_PORT_MASK_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|cc_sw_cong_setting_credit_mask
index|[
name|IB_CC_PORT_MASK_DATA_SIZE
index|]
decl_stmt|;
name|uint8_t
name|cc_sw_cong_setting_threshold
decl_stmt|;
name|uint8_t
name|cc_sw_cong_setting_packet_size
decl_stmt|;
name|uint8_t
name|cc_sw_cong_setting_credit_starvation_threshold
decl_stmt|;
name|osm_cct_entry_t
name|cc_sw_cong_setting_credit_starvation_return_delay
decl_stmt|;
name|ib_net16_t
name|cc_sw_cong_setting_marking_rate
decl_stmt|;
name|ib_net16_t
name|cc_ca_cong_setting_port_control
decl_stmt|;
name|ib_net16_t
name|cc_ca_cong_setting_control_map
decl_stmt|;
name|osm_cacongestion_entry_t
name|cc_ca_cong_entries
index|[
name|IB_CA_CONG_ENTRY_DATA_SIZE
index|]
decl_stmt|;
name|osm_cct_t
name|cc_cct
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
name|boolean_t
name|perfmgr_ignore_cas
decl_stmt|;
name|char
modifier|*
name|event_db_dump_file
decl_stmt|;
name|int
name|perfmgr_rm_nodes
decl_stmt|;
name|boolean_t
name|perfmgr_log_errors
decl_stmt|;
name|boolean_t
name|perfmgr_query_cpi
decl_stmt|;
name|boolean_t
name|perfmgr_xmit_wait_log
decl_stmt|;
name|uint32_t
name|perfmgr_xmit_wait_threshold
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
name|event_plugin_options
decl_stmt|;
name|char
modifier|*
name|node_name_map_name
decl_stmt|;
name|char
modifier|*
name|prefix_routes_file
decl_stmt|;
name|char
modifier|*
name|log_prefix
decl_stmt|;
name|boolean_t
name|consolidate_ipv6_snm_req
decl_stmt|;
name|struct
name|osm_subn_opt
modifier|*
name|file_opts
decl_stmt|;
comment|/* used for update */
name|uint8_t
name|lash_start_vl
decl_stmt|;
comment|/* starting vl to use in lash */
name|uint8_t
name|sm_sl
decl_stmt|;
comment|/* which SL to use for SM/SA communication */
name|char
modifier|*
name|per_module_logging_file
decl_stmt|;
name|boolean_t
name|quasi_ftree_indexing
decl_stmt|;
block|}
name|osm_subn_opt_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS * *	config_file *		The name of the config file. * *	guid *		The port guid that the SM is binding to. * *	m_key *		M_Key value sent to all ports qualifying all Set(PortInfo). * *	sm_key *		SM_Key value of the SM used for SM authentication. * *	sa_key *		SM_Key value to qualify rcv SA queries as "trusted". * *	subnet_prefix *		Subnet prefix used on this subnet. * *	m_key_lease_period *		The lease period used for the M_Key on this subnet. * *	sweep_interval *		The number of seconds between subnet sweeps.  A value of 0 *		disables sweeping. * *	max_wire_smps *		The maximum number of SMPs sent in parallel.  Default is 4. * *	max_wire_smps2 *		The maximum number of timeout SMPs allowed to be outstanding. *		Default is same as max_wire_smps which disables the timeout *		mechanism. * *	max_smps_timeout *		The wait time in usec for timeout based SMPs.  Default is *		timeout * retries. * *	transaction_timeout *		The maximum time in milliseconds allowed for a transaction *		to complete.  Default is 200. * *	transaction_retries *		The number of retries for a transaction. Default is 3. * *	sm_priority *		The priority of this SM as specified by the user.  This *		value is made available in the SMInfo attribute. * *	lmc *		The LMC value used on this subnet. * *	lmc_esp0 *		Whether LMC value used on subnet should be used for *		enhanced switch port 0 or not.  If TRUE, it is used. *		Otherwise (the default), LMC is set to 0 for ESP0. * *	max_op_vls *		Limit the maximal operational VLs. default is 1. * *	reassign_lids *		If TRUE cause all lids to be re-assigend. *		Otherwise (the default), *		OpenSM always tries to preserve as LIDs as much as possible. * *	ignore_other_sm_option *		This flag is TRUE if other SMs on the subnet should be ignored. * *	disable_multicast *		This flag is TRUE if OpenSM should disable multicast support. * *	max_msg_fifo_timeout *		The maximal time a message can stay in the incoming message *		queue. If there is more than one message in the queue and the *		last message stayed in the queue more than this value the SA *		request will be immediately returned with a BUSY status. * *	subnet_timeout *		The subnet_timeout that will be set for all the ports in the *		design SubnSet(PortInfo.vl_stall_life)) * *	vl_stall_count *		The number of sequential packets dropped that cause the port *		to enter the VLStalled state. * *	leaf_vl_stall_count *		The number of sequential packets dropped that cause the port *		to enter the VLStalled state. This is for switch ports driving *		a CA or router port. * *	head_of_queue_lifetime *		The maximal time a packet can live at the head of a VL queue *		on any port not driving a CA or router port. * *	leaf_head_of_queue_lifetime *		The maximal time a packet can live at the head of a VL queue *		on switch ports driving a CA or router. * *	local_phy_errors_threshold *		Threshold of local phy errors for sending Trap 129 * *	overrun_errors_threshold *		Threshold of credits overrun errors for sending Trap 129 * *	sminfo_polling_timeout *		Specifies the polling timeout (in milliseconds) - the timeout *		between one poll to another. * *	packet_life_time *		The maximal time a packet can stay in a switch. *		The value is send to all switches as *		SubnSet(SwitchInfo.life_state) * *	dump_files_dir *		The directory to be used for opensm-subnet.lst, opensm.fdbs, *		opensm.mcfdbs, and default log file (the latter for Windows, *		not Linux). * *	log_file *		Name of the log file (or NULL) for stdout. * *	log_max_size *		This option defines maximal log file size in MB. When *		specified the log file will be truncated upon reaching *		this limit. * *	qos *		Boolean that specifies whether the OpenSM QoS functionality *		should be off or on. * *	qos_policy_file *		Name of the QoS policy file. * *	accum_log_file *		If TRUE (default) - the log file will be accumulated. *		If FALSE - the log file will be erased before starting *		current opensm run. * *	port_prof_ignore_file *		Name of file with port guids to be ignored by port profiling. * *	port_profile_switch_nodes *		If TRUE will count the number of switch nodes routed through *		the link. If FALSE - only CA/RT nodes are counted. * *	sweep_on_trap *		Received traps will initiate a new sweep. * *	routing_engine_names *		Name of routing engine(s) to use. * *	connect_roots *		The option which will enforce root to root connectivity with *		up/down and fat-tree routing engines (even if this violates *		"pure" deadlock free up/down or fat-tree algorithm) * *	use_ucast_cache *		When TRUE enables unicast routing cache. * *	lid_matrix_dump_file *		Name of the lid matrix dump file from where switch *		lid matrices (min hops tables) will be loaded * *	lfts_file *		Name of the unicast LFTs routing file from where switch *		forwarding tables will be loaded * *	root_guid_file *		Name of the file that contains list of root guids that *		will be used by fat-tree or up/dn routing (provided by User) * *	cn_guid_file *		Name of the file that contains list of compute node guids that *		will be used by fat-tree routing (provided by User) * *	io_guid_file *		Name of the file that contains list of I/O node guids that *		will be used by fat-tree routing (provided by User) * *	port_shifting *		This option will turn on port_shifting in routing. * *	ids_guid_file *		Name of the file that contains list of ids which should be *		used by Up/Down algorithm instead of node GUIDs * *	guid_routing_order_file *		Name of the file that contains list of guids for routing order *		that will be used by minhop and up/dn routing (provided by User). * *	sa_db_file *		Name of the SA database file. * *	sa_db_dump *		When TRUE causes OpenSM to dump SA DB at the end of every *		light sweep regardless the current verbosity level. * *	torus_conf_file *		Name of the file with extra configuration info for torus-2QoS *		routing engine. * *	exit_on_fatal *		If TRUE (default) - SM will exit on fatal subnet initialization *		issues. *		If FALSE - SM will not exit. *		Fatal initialization issues: *		a. SM recognizes 2 different nodes with the same guid, or *		   12x link with lane reversal badly configured. * *	honor_guid2lid_file *		Always honor the guid2lid file if it exists and is valid. This *		means that the file will be honored when SM is coming out of *		STANDBY. By default this is FALSE. * *	daemon *		OpenSM will run in daemon mode. * *	sm_inactive *		OpenSM will start with SM in not active state. * *	babbling_port_policy *		OpenSM will enforce its "babbling" port policy. * *	drop_event_subscriptions *		OpenSM will drop event subscriptions if the port goes away. * *	ipoib_mcgroup_creation_validation *		OpenSM will validate IPoIB non-broadcast group parameters *		against IPoIB broadcast group. * *	mcgroup_join_validation *		OpenSM will validate multicast join parameters against *		multicast group parameters when MC group already exists. * *	use_optimized_slvl *		Use optimized SLtoVLMappingTable programming if *		device indicates it supports this. * *	fsync_high_avail_files *		Synchronize high availability in memory files *		with storage. * *	perfmgr *		Enable or disable the performance manager * *	perfmgr_redir *		Enable or disable the saving of redirection by PerfMgr * *	perfmgr_sweep_time_s *		Define the period (in seconds) of PerfMgr sweeps * *       event_db_dump_file *               File to dump the event database to * *       event_plugin_name *               Specify the name(s) of the event plugin(s) * *       event_plugin_options *               Options string that would be passed to the plugin(s) * *	qos_options *		Default set of QoS options * *	qos_ca_options *		QoS options for CA ports * *	qos_sw0_options *		QoS options for switches' port 0 * *	qos_swe_options *		QoS options for switches' external ports * *	qos_rtr_options *		QoS options for router ports * *	congestion_control *		Boolean that specifies whether OpenSM congestion control configuration *		should be off or no. * *	cc_key *		CCkey to use when configuring congestion control. * *	cc_max_outstanding_mads *		Max number of outstanding CC mads that can be on the wire. * *	cc_sw_cong_setting_control_map *		Congestion Control Switch Congestion Setting Control Map *		configuration setting. * *	cc_sw_cong_setting_victim_mask *		Congestion Control Switch Congestion Setting Victim Mask *		configuration setting. * *	cc_sw_cong_setting_credit_mask *		Congestion Control Switch Congestion Setting Credit Mask *		configuration setting. * *	cc_sw_cong_setting_threshold *		Congestion Control Switch Congestion Setting Threshold *		configuration setting. * *	cc_sw_cong_setting_packet_size *		Congestion Control Switch Congestion Setting Packet Size *		configuration setting. * *	cc_sw_cong_setting_credit_starvation_threshold *		Congestion Control Switch Congestion Setting Credit Starvation Threshold *		configuration setting. * *	cc_sw_cong_setting_credit_starvation_return_delay *		Congestion Control Switch Congestion Setting Credit Starvation Return Delay *		configuration setting. * *	cc_sw_cong_setting_marking_rate *		Congestion Control Switch Congestion Setting Marking Rate *		configuration setting. * *	cc_ca_cong_setting_port_control *		Congestion Control CA Congestion Setting Port Control * *	cc_ca_cong_setting_control_map *		Congestion Control CA Congestion Setting Control Map  *	cc_ca_cong_entries *		Congestion Control CA Congestion Setting Entries * *	cc_cct *		Congestion Control Table array of entries * *	enable_quirks *		Enable high risk new features and not fully qualified *		hardware specific work arounds * *	no_clients_rereg *		When TRUE disables clients reregistration request * *	scatter_ports *		When not zero, randomize best possible ports chosen *		for a route. The value is used as a random key seed. * *	per_module_logging_file *		File name of per module logging configuration. * * SEE ALSO *	Subnet object *********/
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
name|alias_port_guid_tbl
decl_stmt|;
name|cl_qmap_t
name|assigned_guids_tbl
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
name|cl_qlist_t
name|alias_guid_list
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
name|last_sm_port_state
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
name|uint8_t
name|min_data_vls
decl_stmt|;
name|uint8_t
name|min_sw_data_vls
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
name|force_first_time_master_sweep
decl_stmt|;
name|boolean_t
name|first_time_master_sweep
decl_stmt|;
name|boolean_t
name|coming_out_of_standby
decl_stmt|;
name|boolean_t
name|sweeping_enabled
decl_stmt|;
name|unsigned
name|need_update
decl_stmt|;
name|cl_fmap_t
name|mgrp_mgid_tbl
decl_stmt|;
name|osm_db_domain_t
modifier|*
name|p_g2m
decl_stmt|;
name|osm_db_domain_t
modifier|*
name|p_neighbor
decl_stmt|;
name|void
modifier|*
name|mboxes
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
comment|/* * FIELDS *	sw_guid_tbl *		Container of pointers to all Switch objects in the subnet. *		Indexed by node GUID. * *	node_guid_tbl *		Container of pointers to all Node objects in the subnet. *		Indexed by node GUID. * *	port_guid_tbl *		Container of pointers to all Port objects in the subnet. *		Indexed by port GUID. * *	rtr_guid_tbl *		Container of pointers to all Router objects in the subnet. *		Indexed by node GUID. * *	prtn_pkey_tbl *		Container of pointers to all Partition objects in the subnet. *		Indexed by P_KEY. * *	sm_guid_tbl *		Container of pointers to SM objects representing other SMs *		on the subnet. * *	port_lid_tbl *		Container of pointers to all Port objects in the subnet. *		Indexed by port LID. * *	master_sm_base_lid *		The base LID owned by the subnet's master SM. * *	sm_base_lid *		The base LID of the local port where the SM is. * *	sm_port_guid *		This SM's own port GUID. * *	last_sm_port_state *		Last state of this SM's port. *		0 is down and 1 is up. * *	sm_state *		The high-level state of the SM.  This value is made available *		in the SMInfo attribute. * *	opt *		Subnet options structure contains site specific configuration. * *	p_qos_policy *		Subnet QoS policy structure. * *	max_ucast_lid_ho *		The minimal max unicast lid reported by all switches * *	max_mcast_lid_ho *		The minimal max multicast lid reported by all switches * *	min_ca_mtu *		The minimal MTU reported by all CAs ports on the subnet * *	min_ca_rate *		The minimal rate reported by all CA ports on the subnet * *	ignore_existing_lfts *		This flag is a dynamic flag to instruct the LFT assignment to *		ignore existing legal LFT settings. *		The value will be set according to : *		- Any change to the list of switches will set it to high *		- Coming out of STANDBY it will be cleared (other SM worked) *		- Set to FALSE upon end of all lft assignments. * *	subnet_initalization_error *		Similar to the force_heavy_sweep flag. If TRUE - means that *		we had errors during initialization (due to SubnSet requests *		that failed). We want to declare the subnet as unhealthy, and *		force another heavy sweep. * *	force_heavy_sweep *		If TRUE - we want to force a heavy sweep. This can be done *		either due to receiving of trap - meaning there is some change *		on the subnet, or we received a handover from a remote sm. *		In this case we want to sweep and reconfigure the entire *		subnet. This will cause another heavy sweep to occure when *		the current sweep is done. * *	force_reroute *		If TRUE - we want to force switches in the fabric to be *		rerouted. * *	in_sweep_hop_0 *		When in_sweep_hop_0 flag is set to TRUE - this means we are *		in sweep_hop_0 - meaning we do not want to continue beyond *		the current node. *		This is relevant for the case of SM on switch, since in the *		switch info we need to signal somehow not to continue *		the sweeping. * *	force_first_time_master_sweep *		This flag is used to avoid race condition when Master SM being *		in the middle of very long configuration stage of the heavy sweep, *		receives HANDOVER from another MASTER SM. When the current heavy sweep *		is finished, new heavy sweep will be started immediately. *		At the beginning of the sweep, opensm will set first_time_master_sweep, *		force_heavy_sweep and coming_out_of_standby flags in order to allow full *		reconfiguration of the fabric. This is required as another MASTER SM could *		change configuration of the fabric before sending HANDOVER to MASTER SM. * *	first_time_master_sweep *		This flag is used for the PortInfo setting. On the first *		sweep as master (meaning after moving from Standby|Discovering *		state), the SM must send a PortInfoSet to all ports. After *		that - we want to minimize the number of PortInfoSet requests *		sent, and to send only requests that change the value from *		what is updated in the port (or send a first request if this *		is a new port). We will set this flag to TRUE when entering *		the master state, and set it back to FALSE at the end of the *		drop manager. This is done since at the end of the drop manager *		we have updated all the ports that are reachable, and from now *		on these are the only ports we have data of. We don't want *		to send extra set requests to these ports anymore. * *	coming_out_of_standby *		TRUE on the first sweep after the SM was in standby. *		Used for nulling any cache of LID and Routing. *		The flag is set true if the SM state was standby and now *		changed to MASTER it is reset at the end of the sweep. * *	sweeping_enabled *		FALSE - sweeping is administratively disabled, all *		sweeping is inhibited, TRUE - sweeping is done *		normally * *	need_update *		This flag should be on during first non-master heavy *		(including pre-master discovery stage) * *	mgrp_mgid_tbl *		Container of pointers to all Multicast group objects in *		the subnet. Indexed by MGID. * *	mboxes *		Array of pointers to all Multicast MLID box objects in the *		subnet. Indexed by MLID offset from base MLID. * * SEE ALSO *	Subnet object *********/
end_comment

begin_comment
comment|/****s* OpenSM: Subnet/osm_assigned_guids_t * NAME *	osm_assigned_guids_t * * DESCRIPTION *	SA assigned GUIDs structure. * * SYNOPSIS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_assigned_guids
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|ib_net64_t
name|port_guid
decl_stmt|;
name|ib_net64_t
name|assigned_guid
index|[
literal|1
index|]
decl_stmt|;
block|}
name|osm_assigned_guids_t
typedef|;
end_typedef

begin_comment
comment|/* * FIELDS *	map_item *		Linkage structure for cl_qmap.  MUST BE FIRST MEMBER! * *	port_guid *		Base port GUID. * *	assigned_guids *		Table of persistent SA assigned GUIDs. * * SEE ALSO *	Subnet object *********/
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
name|p_subn
parameter_list|,
name|IN
name|struct
name|osm_opensm
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

begin_function_decl
name|ib_api_status_t
name|osm_get_gid_by_mad_addr
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
parameter_list|,
name|OUT
name|ib_gid_t
modifier|*
name|p_gid
parameter_list|)
function_decl|;
end_function_decl

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
name|ib_net64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The node guid in network byte order * * RETURN VALUES *	The switch structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_switch_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_node_by_guid * NAME *	osm_get_node_by_guid * * DESCRIPTION *	This looks for the given node guid in the subnet table of nodes by guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
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
name|ib_net64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The node guid in network byte order * * RETURN VALUES *	The node structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_node_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_port_by_guid * NAME *	osm_get_port_by_guid * * DESCRIPTION *	This looks for the given port guid in the subnet table of ports by guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
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
comment|/****f* OpenSM: Port/osm_get_port_by_lid_ho * NAME *	osm_get_port_by_lid_ho * * DESCRIPTION *	Returns a pointer of the port object for given lid value. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_port
modifier|*
name|osm_get_port_by_lid_ho
parameter_list|(
specifier|const
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|uint16_t
name|lid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	subn *		[in] Pointer to the subnet data structure. * *	lid *		[in] LID requested in host byte order. * * RETURN VALUES *	The port structure pointer if found. NULL otherwise. * * SEE ALSO *       Subnet object, osm_port_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_alias_guid_by_guid * NAME *	osm_get_alias_guid_by_guid * * DESCRIPTION *	This looks for the given port guid in the subnet table of ports by *	alias guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_alias_guid
modifier|*
name|osm_get_alias_guid_by_guid
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
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The alias port guid in network order * * RETURN VALUES *	The alias guid structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_alias_guid_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_port_by_alias_guid * NAME *	osm_get_port_by_alias_guid * * DESCRIPTION *	This looks for the given port guid in the subnet table of ports by *	alias guid. *  NOTE: this code is not thread safe. Need to grab the lock before *  calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_port
modifier|*
name|osm_get_port_by_alias_guid
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
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	guid *		[in] The alias port guid in network order * * RETURN VALUES *	The port structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_subn_construct, osm_subn_destroy, *	osm_port_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_assigned_guids_new * NAME *	osm_assigned_guids_new * * DESCRIPTION *	This function allocates and initializes an assigned guids object. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_assigned_guids_t
modifier|*
name|osm_assigned_guids_new
parameter_list|(
name|IN
specifier|const
name|ib_net64_t
name|port_guid
parameter_list|,
name|IN
specifier|const
name|uint32_t
name|num_guids
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *       port_guid *               [in] Base port GUID in network order * * RETURN VALUE *       Pointer to the initialized assigned alias guid object. * * SEE ALSO *	Subnet object, osm_assigned_guids_t, osm_assigned_guids_delete, *	osm_get_assigned_guids_by_guid *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_assigned_guids_delete * NAME *	osm_assigned_guids_delete * * DESCRIPTION *	This function destroys and deallocates an assigned guids object. * * SYNOPSIS */
end_comment

begin_function_decl
name|void
name|osm_assigned_guids_delete
parameter_list|(
name|IN
name|OUT
name|osm_assigned_guids_t
modifier|*
modifier|*
name|pp_assigned_guids
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *       pp_assigned_guids *		[in][out] Pointer to a pointer to an assigned guids object to delete. *		On return, this pointer is NULL. * * RETURN VALUE *	This function does not return a value. * * NOTES *	Performs any necessary cleanup of the specified assigned guids object. * * SEE ALSO *	Subnet object, osm_assigned_guids_new, osm_get_assigned_guids_by_guid *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_assigned_guids_by_guid * NAME *	osm_get_assigned_guids_by_guid * * DESCRIPTION *	This looks for the given port guid and returns a pointer *	to the guid table of SA assigned alias guids for that port. * * SYNOPSIS */
end_comment

begin_function_decl
name|osm_assigned_guids_t
modifier|*
name|osm_get_assigned_guids_by_guid
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|p_subn
parameter_list|,
name|IN
name|ib_net64_t
name|port_guid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	p_subn *		[in] Pointer to an osm_subn_t object * *	port_guid *		[in] The base port guid in network order * * RETURN VALUES *	The osm_assigned_guids structure pointer if found. NULL otherwise. * * SEE ALSO *	Subnet object, osm_assigned_guids_new, osm_assigned_guids_delete, *	osm_assigned_guids_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Port/osm_get_port_by_lid * NAME *	osm_get_port_by_lid * * DESCRIPTION *	Returns a pointer of the port object for given lid value. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|osm_port
modifier|*
name|osm_get_port_by_lid
parameter_list|(
name|IN
name|osm_subn_t
specifier|const
modifier|*
name|subn
parameter_list|,
name|IN
name|ib_net16_t
name|lid
parameter_list|)
block|{
return|return
name|osm_get_port_by_lid_ho
argument_list|(
name|subn
argument_list|,
name|cl_ntoh16
argument_list|(
name|lid
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* * PARAMETERS *	subn *		[in] Pointer to the subnet data structure. * *	lid *		[in] LID requested in network byte order. * * RETURN VALUES *	The port structure pointer if found. NULL otherwise. * * SEE ALSO *       Subnet object, osm_port_t *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_mgrp_by_mgid * NAME *	osm_get_mgrp_by_mgid * * DESCRIPTION *	This looks for the given multicast group in the subnet table by mgid. *	NOTE: this code is not thread safe. Need to grab the lock before *	calling it. * * SYNOPSIS */
end_comment

begin_function_decl
name|struct
name|osm_mgrp
modifier|*
name|osm_get_mgrp_by_mgid
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|subn
parameter_list|,
name|IN
name|ib_gid_t
modifier|*
name|mgid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS *	subn *		[in] Pointer to an osm_subn_t object * *	mgid *		[in] The multicast group MGID value * * RETURN VALUES *	The multicast group structure pointer if found. NULL otherwise. *********/
end_comment

begin_comment
comment|/****f* OpenSM: Subnet/osm_get_mbox_by_mlid * NAME *	osm_get_mbox_by_mlid * * DESCRIPTION *	This looks for the given multicast group in the subnet table by mlid. *	NOTE: this code is not thread safe. Need to grab the lock before *	calling it. * * SYNOPSIS */
end_comment

begin_function
specifier|static
specifier|inline
name|struct
name|osm_mgrp_box
modifier|*
name|osm_get_mbox_by_mlid
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
operator|(
expr|struct
name|osm_mgrp_box
operator|*
operator|)
name|p_subn
operator|->
name|mboxes
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

begin_function_decl
name|int
name|is_mlnx_ext_port_info_supported
parameter_list|(
name|ib_net32_t
name|vendid
parameter_list|,
name|ib_net16_t
name|devid
parameter_list|)
function_decl|;
end_function_decl

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
specifier|const
name|char
modifier|*
name|conf_file
parameter_list|,
name|osm_subn_opt_t
modifier|*
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
name|void
name|osm_subn_output_conf
parameter_list|(
name|FILE
modifier|*
name|out
parameter_list|,
name|IN
name|osm_subn_opt_t
modifier|*
name|p_opt
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* * PARAMETERS * *	out *		[in] File stream to output to. * *	p_opt *		[in] Pointer to the subnet options structure. * * RETURN VALUES *	This method does not return a value *********/
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

