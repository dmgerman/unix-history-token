begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Mellanox Technologies LTD. All rights reserved.  * Copyright (c) 2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2007 The Regents of the University of California.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OSM_EVENT_PLUGIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_OSM_EVENT_PLUGIN_H_
end_define

begin_include
include|#
directive|include
file|<time.h>
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
file|<opensm/osm_config.h>
end_include

begin_include
include|#
directive|include
file|<opensm/osm_switch.h>
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
comment|/****h* OpenSM Event plugin interface * DESCRIPTION *       Database interface to record subnet events * *       Implementations of this object _MUST_ be thread safe. * * AUTHOR *	Ira Weiny, LLNL * *********/
end_comment

begin_define
define|#
directive|define
name|OSM_EPI_NODE_NAME_LEN
value|(65)
end_define

begin_struct_decl
struct_decl|struct
name|osm_opensm
struct_decl|;
end_struct_decl

begin_comment
comment|/** =========================================================================  * Event types  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|OSM_EVENT_ID_PORT_ERRORS
init|=
literal|0
block|,
name|OSM_EVENT_ID_PORT_DATA_COUNTERS
block|,
name|OSM_EVENT_ID_PORT_SELECT
block|,
name|OSM_EVENT_ID_TRAP
block|,
name|OSM_EVENT_ID_SUBNET_UP
block|,
name|OSM_EVENT_ID_HEAVY_SWEEP_START
block|,
name|OSM_EVENT_ID_HEAVY_SWEEP_DONE
block|,
name|OSM_EVENT_ID_UCAST_ROUTING_DONE
block|,
name|OSM_EVENT_ID_STATE_CHANGE
block|,
name|OSM_EVENT_ID_SA_DB_DUMPED
block|,
name|OSM_EVENT_ID_LFT_CHANGE
block|,
name|OSM_EVENT_ID_MAX
block|}
name|osm_epi_event_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osm_epi_port_id
block|{
name|uint64_t
name|node_guid
decl_stmt|;
name|uint8_t
name|port_num
decl_stmt|;
name|char
name|node_name
index|[
name|OSM_EPI_NODE_NAME_LEN
index|]
decl_stmt|;
block|}
name|osm_epi_port_id_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|LFT_CHANGED_LFT_TOP
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|LFT_CHANGED_BLOCK
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|}
name|osm_epi_lft_change_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|UCAST_ROUTING_NONE
block|,
name|UCAST_ROUTING_HEAVY_SWEEP
block|,
name|UCAST_ROUTING_REROUTE
block|}
name|osm_epi_ucast_routing_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|osm_epi_lft_change_event
block|{
name|osm_switch_t
modifier|*
name|p_sw
decl_stmt|;
name|osm_epi_lft_change_flags_t
name|flags
decl_stmt|;
name|uint16_t
name|lft_top
decl_stmt|;
name|uint32_t
name|block_num
decl_stmt|;
block|}
name|osm_epi_lft_change_event_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port error event  * OSM_EVENT_ID_PORT_COUNTER  * This is a difference from the last reading.  NOT an absolute reading.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_epi_pe_event
block|{
name|osm_epi_port_id_t
name|port_id
decl_stmt|;
name|uint64_t
name|symbol_err_cnt
decl_stmt|;
name|uint64_t
name|link_err_recover
decl_stmt|;
name|uint64_t
name|link_downed
decl_stmt|;
name|uint64_t
name|rcv_err
decl_stmt|;
name|uint64_t
name|rcv_rem_phys_err
decl_stmt|;
name|uint64_t
name|rcv_switch_relay_err
decl_stmt|;
name|uint64_t
name|xmit_discards
decl_stmt|;
name|uint64_t
name|xmit_constraint_err
decl_stmt|;
name|uint64_t
name|rcv_constraint_err
decl_stmt|;
name|uint64_t
name|link_integrity
decl_stmt|;
name|uint64_t
name|buffer_overrun
decl_stmt|;
name|uint64_t
name|vl15_dropped
decl_stmt|;
name|uint64_t
name|xmit_wait
decl_stmt|;
name|time_t
name|time_diff_s
decl_stmt|;
block|}
name|osm_epi_pe_event_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port data counter event  * This is a difference from the last reading.  NOT an absolute reading.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_epi_dc_event
block|{
name|osm_epi_port_id_t
name|port_id
decl_stmt|;
name|uint64_t
name|xmit_data
decl_stmt|;
name|uint64_t
name|rcv_data
decl_stmt|;
name|uint64_t
name|xmit_pkts
decl_stmt|;
name|uint64_t
name|rcv_pkts
decl_stmt|;
name|uint64_t
name|unicast_xmit_pkts
decl_stmt|;
name|uint64_t
name|unicast_rcv_pkts
decl_stmt|;
name|uint64_t
name|multicast_xmit_pkts
decl_stmt|;
name|uint64_t
name|multicast_rcv_pkts
decl_stmt|;
name|time_t
name|time_diff_s
decl_stmt|;
block|}
name|osm_epi_dc_event_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port select event  * This is a difference from the last reading.  NOT an absolute reading.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_api_ps_event
block|{
name|osm_epi_port_id_t
name|port_id
decl_stmt|;
name|uint64_t
name|xmit_wait
decl_stmt|;
name|time_t
name|time_diff_s
decl_stmt|;
block|}
name|osm_epi_ps_event_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Plugin creators should allocate an object of this type  *    (named OSM_EVENT_PLUGIN_IMPL_NAME)  * The version should be set to OSM_EVENT_PLUGIN_INTERFACE_VER  */
end_comment

begin_define
define|#
directive|define
name|OSM_EVENT_PLUGIN_IMPL_NAME
value|"osm_event_plugin"
end_define

begin_define
define|#
directive|define
name|OSM_ORIG_EVENT_PLUGIN_INTERFACE_VER
value|1
end_define

begin_define
define|#
directive|define
name|OSM_EVENT_PLUGIN_INTERFACE_VER
value|2
end_define

begin_typedef
typedef|typedef
struct|struct
name|osm_event_plugin
block|{
specifier|const
name|char
modifier|*
name|osm_version
decl_stmt|;
name|void
modifier|*
function_decl|(
modifier|*
name|create
function_decl|)
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|osm
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|delete
function_decl|)
parameter_list|(
name|void
modifier|*
name|plugin_data
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|report
function_decl|)
parameter_list|(
name|void
modifier|*
name|plugin_data
parameter_list|,
name|osm_epi_event_id_t
name|event_id
parameter_list|,
name|void
modifier|*
name|event_data
parameter_list|)
function_decl|;
block|}
name|osm_event_plugin_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * The plugin structure should be considered opaque  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|osm_epi_plugin
block|{
name|cl_list_item_t
name|list
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|osm_event_plugin_t
modifier|*
name|impl
decl_stmt|;
name|void
modifier|*
name|plugin_data
decl_stmt|;
name|char
modifier|*
name|plugin_name
decl_stmt|;
block|}
name|osm_epi_plugin_t
typedef|;
end_typedef

begin_comment
comment|/**  * functions  */
end_comment

begin_function_decl
name|osm_epi_plugin_t
modifier|*
name|osm_epi_construct
parameter_list|(
name|struct
name|osm_opensm
modifier|*
name|osm
parameter_list|,
name|char
modifier|*
name|plugin_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|osm_epi_destroy
parameter_list|(
name|osm_epi_plugin_t
modifier|*
name|plugin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** =========================================================================  * Helper functions  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|osm_epi_create_port_id
parameter_list|(
name|osm_epi_port_id_t
modifier|*
name|port_id
parameter_list|,
name|uint64_t
name|node_guid
parameter_list|,
name|uint8_t
name|port_num
parameter_list|,
name|char
modifier|*
name|node_name
parameter_list|)
block|{
name|port_id
operator|->
name|node_guid
operator|=
name|node_guid
expr_stmt|;
name|port_id
operator|->
name|port_num
operator|=
name|port_num
expr_stmt|;
name|strncpy
argument_list|(
name|port_id
operator|->
name|node_name
argument_list|,
name|node_name
argument_list|,
name|OSM_EPI_NODE_NAME_LEN
argument_list|)
expr_stmt|;
name|port_id
operator|->
name|node_name
index|[
name|OSM_EPI_NODE_NAME_LEN
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
end_function

begin_macro
name|END_C_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OSM_EVENT_PLUGIN_H_ */
end_comment

end_unit

