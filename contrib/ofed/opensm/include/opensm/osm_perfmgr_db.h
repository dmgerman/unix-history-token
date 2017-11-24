begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Voltaire, Inc. All rights reserved.  * Copyright (c) 2007 The Regents of the University of California.  * Copyright (c) 2009 HNR Consulting. All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PERFMGR_EVENT_DB_H_
end_ifndef

begin_define
define|#
directive|define
name|_PERFMGR_EVENT_DB_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_OSM_PERF_MGR
end_ifdef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
file|<complib/cl_qmap.h>
end_include

begin_include
include|#
directive|include
file|<complib/cl_passivelock.h>
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

begin_struct_decl
struct_decl|struct
name|osm_perfmgr
struct_decl|;
end_struct_decl

begin_comment
comment|/****h* OpenSM/PerfMgr Event Database * DESCRIPTION *       Database interface to record subnet events * *       Implementations of this object _MUST_ be thread safe. * * AUTHOR *	Ira Weiny, LLNL * *********/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PERFMGR_EVENT_DB_SUCCESS
init|=
literal|0
block|,
name|PERFMGR_EVENT_DB_FAIL
block|,
name|PERFMGR_EVENT_DB_NOMEM
block|,
name|PERFMGR_EVENT_DB_GUIDNOTFOUND
block|,
name|PERFMGR_EVENT_DB_PORTNOTFOUND
block|,
name|PERFMGR_EVENT_DB_NOT_IMPL
block|}
name|perfmgr_db_err_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port error reading  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
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
name|time
decl_stmt|;
block|}
name|perfmgr_db_err_reading_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port data count reading  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|uint64_t
name|xmit_data
decl_stmt|;
comment|/* can be used for std or extended */
name|uint64_t
name|rcv_data
decl_stmt|;
comment|/* can be used for std or extended */
name|uint64_t
name|xmit_pkts
decl_stmt|;
comment|/* can be used for std or extended */
name|uint64_t
name|rcv_pkts
decl_stmt|;
comment|/* can be used for std or extended */
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
name|time
decl_stmt|;
block|}
name|perfmgr_db_data_cnt_reading_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Dump output options  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|PERFMGR_EVENT_DB_DUMP_HR
init|=
literal|0
block|,
comment|/* Human readable */
name|PERFMGR_EVENT_DB_DUMP_MR
comment|/* Machine readable */
block|}
name|perfmgr_db_dump_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * Port counter object.  * Store all the port counters for a single port.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|db_port
block|{
name|perfmgr_db_err_reading_t
name|err_total
decl_stmt|;
name|perfmgr_db_err_reading_t
name|err_previous
decl_stmt|;
name|perfmgr_db_data_cnt_reading_t
name|dc_total
decl_stmt|;
name|perfmgr_db_data_cnt_reading_t
name|dc_previous
decl_stmt|;
name|time_t
name|last_reset
decl_stmt|;
name|boolean_t
name|valid
decl_stmt|;
block|}
name|db_port_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * group port counters for ports into the nodes  */
end_comment

begin_define
define|#
directive|define
name|NODE_NAME_SIZE
value|(IB_NODE_DESCRIPTION_SIZE + 1)
end_define

begin_typedef
typedef|typedef
struct|struct
name|db_node
block|{
name|cl_map_item_t
name|map_item
decl_stmt|;
comment|/* must be first */
name|uint64_t
name|node_guid
decl_stmt|;
name|boolean_t
name|active
decl_stmt|;
comment|/* activly being monitored */
name|boolean_t
name|esp0
decl_stmt|;
name|db_port_t
modifier|*
name|ports
decl_stmt|;
name|uint8_t
name|num_ports
decl_stmt|;
name|char
name|node_name
index|[
name|NODE_NAME_SIZE
index|]
decl_stmt|;
block|}
name|db_node_t
typedef|;
end_typedef

begin_comment
comment|/** =========================================================================  * all nodes in the subnet.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|perfmgr_db
block|{
name|cl_qmap_t
name|pc_data
decl_stmt|;
comment|/* stores type (db_node_t *) */
name|cl_plock_t
name|lock
decl_stmt|;
name|struct
name|osm_perfmgr
modifier|*
name|perfmgr
decl_stmt|;
block|}
name|perfmgr_db_t
typedef|;
end_typedef

begin_comment
comment|/**  * functions  */
end_comment

begin_function_decl
name|perfmgr_db_t
modifier|*
name|perfmgr_db_construct
parameter_list|(
name|struct
name|osm_perfmgr
modifier|*
name|perfmgr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_destroy
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_create_entry
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|boolean_t
name|esp0
parameter_list|,
name|uint8_t
name|num_ports
parameter_list|,
name|char
modifier|*
name|node_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_delete_entry
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_delete_inactive
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|unsigned
modifier|*
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_update_name
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|node_guid
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_add_err_reading
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|perfmgr_db_err_reading_t
modifier|*
name|reading
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_get_prev_err
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|perfmgr_db_err_reading_t
modifier|*
name|reading
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_clear_prev_err
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_add_dc_reading
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|perfmgr_db_data_cnt_reading_t
modifier|*
name|reading
parameter_list|,
name|int
name|ietf_sup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_get_prev_dc
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|,
name|perfmgr_db_data_cnt_reading_t
modifier|*
name|reading
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_clear_prev_dc
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|uint8_t
name|port
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_mark_active
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|boolean_t
name|active
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_clear_counters
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|perfmgr_db_err_t
name|perfmgr_db_dump
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|perfmgr_db_dump_t
name|dump_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_print_all
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|int
name|err_only
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_print_by_name
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|char
modifier|*
name|nodename
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|port
parameter_list|,
name|int
name|err_only
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_print_by_guid
parameter_list|(
name|perfmgr_db_t
modifier|*
name|db
parameter_list|,
name|uint64_t
name|guid
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|char
modifier|*
name|port
parameter_list|,
name|int
name|err_only
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** =========================================================================  * helper functions to fill in the various db objects from wire objects  */
end_comment

begin_function_decl
name|void
name|perfmgr_db_fill_err_read
parameter_list|(
name|ib_port_counters_t
modifier|*
name|wire_read
parameter_list|,
name|perfmgr_db_err_reading_t
modifier|*
name|reading
parameter_list|,
name|boolean_t
name|xmit_wait_sup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_fill_data_cnt_read_pc
parameter_list|(
name|ib_port_counters_t
modifier|*
name|wire_read
parameter_list|,
name|perfmgr_db_data_cnt_reading_t
modifier|*
name|reading
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|perfmgr_db_fill_data_cnt_read_pce
parameter_list|(
name|ib_port_counters_ext_t
modifier|*
name|wire_read
parameter_list|,
name|perfmgr_db_data_cnt_reading_t
modifier|*
name|reading
parameter_list|,
name|int
name|ietf_sup
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
comment|/* ENABLE_OSM_PERF_MGR */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PERFMGR_PM_DB_H_ */
end_comment

end_unit

