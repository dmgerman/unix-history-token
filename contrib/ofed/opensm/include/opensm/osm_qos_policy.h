begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2009 Voltaire, Inc. All rights reserved.  * Copyright (c) 2002-2012 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 1996-2003 Intel Corporation. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_comment
comment|/*  * Abstract:  *    Declaration of OSM QoS Policy data types and functions.  *  * Author:  *    Yevgeny Kliteynik, Mellanox  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OSM_QOS_POLICY_H
end_ifndef

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_H
end_define

begin_include
include|#
directive|include
file|<iba/ib_types.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_list.h>
end_include

begin_include
include|#
directive|include
file|<opensm/st.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_port.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_partition.h>
end_include

begin_define
define|#
directive|define
name|YYSTYPE
value|char *
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH
value|128
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_DEFAULT_LEVEL_NAME
value|"default"
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_ULP_SDP_SERVICE_ID
value|0x0000000000010000ULL
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_ULP_RDS_SERVICE_ID
value|0x0000000001060000ULL
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_ULP_RDS_PORT
value|0x48CA
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_ULP_ISER_SERVICE_ID
value|0x0000000001060000ULL
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_ULP_ISER_PORT
value|0x0CBC
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_NODE_TYPE_CA
value|(((uint8_t)1)<<IB_NODE_TYPE_CA)
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_NODE_TYPE_SWITCH
value|(((uint8_t)1)<<IB_NODE_TYPE_SWITCH)
end_define

begin_define
define|#
directive|define
name|OSM_QOS_POLICY_NODE_TYPE_ROUTER
value|(((uint8_t)1)<<IB_NODE_TYPE_ROUTER)
end_define

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_port
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
name|osm_physp_t
modifier|*
name|p_physp
decl_stmt|;
block|}
name|osm_qos_port_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_port_group
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* single string (this port group name) */
name|char
modifier|*
name|use
decl_stmt|;
comment|/* single string (description) */
name|uint8_t
name|node_types
decl_stmt|;
comment|/* node types bitmask */
name|cl_qmap_t
name|port_map
decl_stmt|;
block|}
name|osm_qos_port_group_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_vlarb_scope
block|{
name|cl_list_t
name|group_list
decl_stmt|;
comment|/* list of group names (strings) */
name|cl_list_t
name|across_list
decl_stmt|;
comment|/* list of 'across' group names (strings) */
name|cl_list_t
name|vlarb_high_list
decl_stmt|;
comment|/* list of num pairs (n:m,...), 32-bit values */
name|cl_list_t
name|vlarb_low_list
decl_stmt|;
comment|/* list of num pairs (n:m,...), 32-bit values */
name|uint32_t
name|vl_high_limit
decl_stmt|;
comment|/* single integer */
name|boolean_t
name|vl_high_limit_set
decl_stmt|;
block|}
name|osm_qos_vlarb_scope_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_sl2vl_scope
block|{
name|cl_list_t
name|group_list
decl_stmt|;
comment|/* list of strings (port group names) */
name|boolean_t
name|from
index|[
name|OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH
index|]
decl_stmt|;
name|boolean_t
name|to
index|[
name|OSM_QOS_POLICY_MAX_PORTS_ON_SWITCH
index|]
decl_stmt|;
name|cl_list_t
name|across_from_list
decl_stmt|;
comment|/* list of strings (port group names) */
name|cl_list_t
name|across_to_list
decl_stmt|;
comment|/* list of strings (port group names) */
name|uint8_t
name|sl2vl_table
index|[
literal|16
index|]
decl_stmt|;
comment|/* array of sl2vl values */
name|boolean_t
name|sl2vl_table_set
decl_stmt|;
block|}
name|osm_qos_sl2vl_scope_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_level
block|{
name|char
modifier|*
name|use
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|uint8_t
name|sl
decl_stmt|;
name|boolean_t
name|sl_set
decl_stmt|;
name|uint8_t
name|mtu_limit
decl_stmt|;
name|boolean_t
name|mtu_limit_set
decl_stmt|;
name|uint8_t
name|rate_limit
decl_stmt|;
name|boolean_t
name|rate_limit_set
decl_stmt|;
name|uint8_t
name|pkt_life
decl_stmt|;
name|boolean_t
name|pkt_life_set
decl_stmt|;
name|uint64_t
modifier|*
modifier|*
name|path_bits_range_arr
decl_stmt|;
comment|/* array of bit ranges (real values are 32bits) */
name|unsigned
name|path_bits_range_len
decl_stmt|;
comment|/* num of bit ranges in the array */
name|uint64_t
modifier|*
modifier|*
name|pkey_range_arr
decl_stmt|;
comment|/* array of PKey ranges (real values are 16bits) */
name|unsigned
name|pkey_range_len
decl_stmt|;
block|}
name|osm_qos_level_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_match_rule
block|{
name|char
modifier|*
name|use
decl_stmt|;
name|cl_list_t
name|source_list
decl_stmt|;
comment|/* list of strings */
name|cl_list_t
name|source_group_list
decl_stmt|;
comment|/* list of pointers to relevant port-group */
name|cl_list_t
name|destination_list
decl_stmt|;
comment|/* list of strings */
name|cl_list_t
name|destination_group_list
decl_stmt|;
comment|/* list of pointers to relevant port-group */
name|char
modifier|*
name|qos_level_name
decl_stmt|;
name|osm_qos_level_t
modifier|*
name|p_qos_level
decl_stmt|;
name|uint64_t
modifier|*
modifier|*
name|service_id_range_arr
decl_stmt|;
comment|/* array of SID ranges (64-bit values) */
name|unsigned
name|service_id_range_len
decl_stmt|;
name|uint64_t
modifier|*
modifier|*
name|qos_class_range_arr
decl_stmt|;
comment|/* array of QoS Class ranges (real values are 16bits) */
name|unsigned
name|qos_class_range_len
decl_stmt|;
name|uint64_t
modifier|*
modifier|*
name|pkey_range_arr
decl_stmt|;
comment|/* array of PKey ranges (real values are 16bits) */
name|unsigned
name|pkey_range_len
decl_stmt|;
block|}
name|osm_qos_match_rule_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_qos_policy
block|{
name|cl_list_t
name|port_groups
decl_stmt|;
comment|/* list of osm_qos_port_group_t */
name|cl_list_t
name|sl2vl_tables
decl_stmt|;
comment|/* list of osm_qos_sl2vl_scope_t */
name|cl_list_t
name|vlarb_tables
decl_stmt|;
comment|/* list of osm_qos_vlarb_scope_t */
name|cl_list_t
name|qos_levels
decl_stmt|;
comment|/* list of osm_qos_level_t */
name|cl_list_t
name|qos_match_rules
decl_stmt|;
comment|/* list of osm_qos_match_rule_t */
name|osm_qos_level_t
modifier|*
name|p_default_qos_level
decl_stmt|;
comment|/* default QoS level */
name|osm_subn_t
modifier|*
name|p_subn
decl_stmt|;
comment|/* osm subnet object */
name|st_table
modifier|*
name|p_node_hash
decl_stmt|;
comment|/* node by name hash */
block|}
name|osm_qos_policy_t
typedef|;
end_typedef

begin_comment
comment|/***************************************************/
end_comment

begin_function_decl
name|osm_qos_port_t
modifier|*
name|osm_qos_policy_port_create
parameter_list|(
name|osm_physp_t
modifier|*
name|p_physp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_port_group_t
modifier|*
name|osm_qos_policy_port_group_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_port_group_destroy
parameter_list|(
name|osm_qos_port_group_t
modifier|*
name|p_port_group
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_vlarb_scope_t
modifier|*
name|osm_qos_policy_vlarb_scope_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_vlarb_scope_destroy
parameter_list|(
name|osm_qos_vlarb_scope_t
modifier|*
name|p_vlarb_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_sl2vl_scope_t
modifier|*
name|osm_qos_policy_sl2vl_scope_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_sl2vl_scope_destroy
parameter_list|(
name|osm_qos_sl2vl_scope_t
modifier|*
name|p_sl2vl_scope
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_level_t
modifier|*
name|osm_qos_policy_qos_level_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_qos_level_destroy
parameter_list|(
name|osm_qos_level_t
modifier|*
name|p_qos_level
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|boolean_t
name|osm_qos_level_has_pkey
parameter_list|(
name|IN
specifier|const
name|osm_qos_level_t
modifier|*
name|p_qos_level
parameter_list|,
name|IN
name|ib_net16_t
name|pkey
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ib_net16_t
name|osm_qos_level_get_shared_pkey
parameter_list|(
name|IN
specifier|const
name|osm_qos_level_t
modifier|*
name|p_qos_level
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_src_physp
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_dest_physp
parameter_list|,
name|IN
specifier|const
name|boolean_t
name|allow_both_pkeys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_match_rule_t
modifier|*
name|osm_qos_policy_match_rule_create
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_match_rule_destroy
parameter_list|(
name|osm_qos_match_rule_t
modifier|*
name|p_match_rule
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_policy_t
modifier|*
name|osm_qos_policy_create
parameter_list|(
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_qos_policy_destroy
parameter_list|(
name|osm_qos_policy_t
modifier|*
name|p_qos_policy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|osm_qos_policy_validate
parameter_list|(
name|osm_qos_policy_t
modifier|*
name|p_qos_policy
parameter_list|,
name|osm_log_t
modifier|*
name|p_log
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_level_t
modifier|*
name|osm_qos_policy_get_qos_level_by_pr
parameter_list|(
name|IN
specifier|const
name|osm_qos_policy_t
modifier|*
name|p_qos_policy
parameter_list|,
name|IN
specifier|const
name|ib_path_rec_t
modifier|*
name|p_pr
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_src_physp
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_dest_physp
parameter_list|,
name|IN
name|ib_net64_t
name|comp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|osm_qos_level_t
modifier|*
name|osm_qos_policy_get_qos_level_by_mpr
parameter_list|(
name|IN
specifier|const
name|osm_qos_policy_t
modifier|*
name|p_qos_policy
parameter_list|,
name|IN
specifier|const
name|ib_multipath_rec_t
modifier|*
name|p_mpr
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_src_physp
parameter_list|,
name|IN
specifier|const
name|osm_physp_t
modifier|*
name|p_dest_physp
parameter_list|,
name|IN
name|ib_net64_t
name|comp_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************/
end_comment

begin_function_decl
name|int
name|osm_qos_parse_policy_file
parameter_list|(
name|IN
name|osm_subn_t
modifier|*
name|p_subn
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/***************************************************/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef OSM_QOS_POLICY_H */
end_comment

end_unit

