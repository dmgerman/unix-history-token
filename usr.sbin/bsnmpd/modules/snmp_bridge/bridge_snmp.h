begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Shteryana Shopova<syrinx@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Bridge MIB implementation for SNMPd.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SNMP_BRIDGE_H
end_ifndef

begin_define
define|#
directive|define
name|SNMP_BRIDGE_H
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_ID_LEN
value|8
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|port_id
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_char
name|bridge_id
index|[
name|SNMP_BRIDGE_ID_LEN
index|]
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_PRIORITY
value|65535
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MIN_AGE_TIME
value|10
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_AGE_TIME
value|1000000
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MIN_TXHC
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_TXHC
value|10
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MIN_MAGE
value|600
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_MAGE
value|4000
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MIN_HTIME
value|100
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_HTIME
value|1000
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MIN_FDELAY
value|400
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_MAX_FDELAY
value|3000
end_define

begin_define
define|#
directive|define
name|SNMP_PORT_PATHCOST_OBSOLETE
value|65535
end_define

begin_define
define|#
directive|define
name|SNMP_PORT_MIN_PATHCOST
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_PORT_MAX_PATHCOST
value|200000000
end_define

begin_define
define|#
directive|define
name|SNMP_PORT_PATHCOST_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_DATA_MAXAGE
value|10
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_DATA_MAXAGE_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_DATA_MAXAGE_MAX
value|300
end_define

begin_comment
comment|/* By default poll kernel data every 5 minutes. */
end_comment

begin_define
define|#
directive|define
name|SNMP_BRIDGE_POLL_INTERVAL
value|(5 * 60)
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_POLL_INTERVAL_MIN
value|1
end_define

begin_define
define|#
directive|define
name|SNMP_BRIDGE_POLL_INTERVAL_MAX
value|3600
end_define

begin_comment
comment|/* Poll for a topology change once every 30 seconds. */
end_comment

begin_define
define|#
directive|define
name|SNMP_BRIDGE_TC_POLL_INTERVAL
value|30
end_define

begin_function_decl
name|struct
name|bridge_if
modifier|*
name|bridge_get_default
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_set_default
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bridge_get_default_name
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_get_data_maxage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Bridge Addresses Table.  */
end_comment

begin_struct
struct|struct
name|tp_entry
block|{
name|uint32_t
name|sysindex
decl_stmt|;
comment|/* The bridge if sysindex. */
name|int32_t
name|port_no
decl_stmt|;
name|enum
name|TpFdbStatus
name|status
decl_stmt|;
name|uint8_t
name|tp_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|tp_entry
argument_list|)
name|tp_e
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Bridge ports.  * The bridge port system interface index is used for a  * port number. Transparent bridging statistics and STP  * information for a port are also contained here.  */
end_comment

begin_struct
struct|struct
name|bridge_port
block|{
comment|/* dot1dBase subtree objects. */
name|uint32_t
name|sysindex
decl_stmt|;
comment|/* The bridge interface sysindex. */
name|int32_t
name|port_no
decl_stmt|;
comment|/* The bridge member system index. */
name|int32_t
name|if_idx
decl_stmt|;
comment|/* SNMP ifIndex from mibII. */
name|int8_t
name|span_enable
decl_stmt|;
comment|/* Span flag set - private MIB. */
name|struct
name|asn_oid
name|circuit
decl_stmt|;
comment|/* Unused. */
name|uint32_t
name|dly_ex_drops
decl_stmt|;
comment|/* Drops on output. */
name|uint32_t
name|dly_mtu_drops
decl_stmt|;
comment|/* MTU exceeded drops. */
name|int32_t
name|status
decl_stmt|;
comment|/* The entry status. */
comment|/* dot1dStp subtree objects. */
name|int32_t
name|path_cost
decl_stmt|;
name|int32_t
name|priority
decl_stmt|;
name|int32_t
name|design_cost
decl_stmt|;
name|uint32_t
name|fwd_trans
decl_stmt|;
name|char
name|p_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Not in BRIDGE-MIB. */
name|enum
name|StpPortState
name|state
decl_stmt|;
name|enum
name|dot1dStpPortEnable
name|enable
decl_stmt|;
name|port_id
name|design_port
decl_stmt|;
name|bridge_id
name|design_root
decl_stmt|;
name|bridge_id
name|design_bridge
decl_stmt|;
comment|/* rstpMib extensions. */
name|int32_t
name|admin_path_cost
decl_stmt|;
name|enum
name|TruthValue
name|proto_migr
decl_stmt|;
name|enum
name|TruthValue
name|admin_edge
decl_stmt|;
name|enum
name|TruthValue
name|oper_edge
decl_stmt|;
name|enum
name|TruthValue
name|oper_ptp
decl_stmt|;
name|enum
name|StpPortAdminPointToPointType
name|admin_ptp
decl_stmt|;
comment|/* dot1dTp subtree objects. */
name|int32_t
name|max_info
decl_stmt|;
name|int32_t
name|in_frames
decl_stmt|;
name|int32_t
name|out_frames
decl_stmt|;
name|int32_t
name|in_drops
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|bridge_port
argument_list|)
name|b_p
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A bridge interface.  * The system interface index of the bridge is not required neither by the  * standard BRIDGE-MIB nor by the private BEGEMOT-BRIDGE-MIB, but is used  * as key for looking up the other info for this bridge.  */
end_comment

begin_struct
struct|struct
name|bridge_if
block|{
comment|/* dot1dBase subtree objects. */
name|uint32_t
name|sysindex
decl_stmt|;
comment|/* The system interface index. */
name|int32_t
name|num_ports
decl_stmt|;
comment|/* Number of ports. */
name|enum
name|BaseType
name|br_type
decl_stmt|;
comment|/* Bridge type. */
name|enum
name|RowStatus
name|if_status
decl_stmt|;
comment|/* Bridge status. */
name|char
name|bif_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Bridge interface name. */
name|struct
name|ether_addr
name|br_addr
decl_stmt|;
comment|/* Bridge address. */
name|struct
name|bridge_port
modifier|*
name|f_bp
decl_stmt|;
comment|/* This bridge's first entry 					 * in the base ports TAILQ. */
comment|/* dot1dStp subtree objects. */
name|int32_t
name|priority
decl_stmt|;
name|int32_t
name|root_cost
decl_stmt|;
name|int32_t
name|root_port
decl_stmt|;
name|int32_t
name|max_age
decl_stmt|;
comment|/* Current max age. */
name|int32_t
name|hello_time
decl_stmt|;
comment|/* Current hello time. */
name|int32_t
name|fwd_delay
decl_stmt|;
comment|/* Current forward delay. */
name|int32_t
name|hold_time
decl_stmt|;
name|int32_t
name|bridge_max_age
decl_stmt|;
comment|/* Configured max age. */
name|int32_t
name|bridge_hello_time
decl_stmt|;
comment|/* Configured hello time. */
name|int32_t
name|bridge_fwd_delay
decl_stmt|;
comment|/* Configured forward delay. */
name|int32_t
name|tx_hold_count
decl_stmt|;
name|uint32_t
name|top_changes
decl_stmt|;
name|enum
name|dot1dStpVersion
name|stp_version
decl_stmt|;
name|enum
name|dot1dStpProtocolSpecification
name|prot_spec
decl_stmt|;
name|struct
name|timeval
name|last_tc_time
decl_stmt|;
name|bridge_id
name|design_root
decl_stmt|;
comment|/* dot1dTp subtree objects. */
name|int32_t
name|lrnt_drops
decl_stmt|;
comment|/* Dropped addresses. */
name|int32_t
name|age_time
decl_stmt|;
comment|/* Address entry timeout. */
name|int32_t
name|num_addrs
decl_stmt|;
comment|/* Current # of addresses in cache. */
name|int32_t
name|max_addrs
decl_stmt|;
comment|/* Max # of addresses in cache. */
name|struct
name|tp_entry
modifier|*
name|f_tpa
decl_stmt|;
comment|/* This bridge's first entry in 					 * the tp addresses TAILQ. */
name|time_t
name|entry_age
decl_stmt|;
name|time_t
name|ports_age
decl_stmt|;
name|time_t
name|addrs_age
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|bridge_if
argument_list|)
name|b_if
expr_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|bridge_ifs_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_if
modifier|*
name|bridge_if_find_ifs
parameter_list|(
name|uint32_t
name|sysindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_if
modifier|*
name|bridge_if_find_ifname
parameter_list|(
specifier|const
name|char
modifier|*
name|b_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|bridge_if_find_name
parameter_list|(
name|uint32_t
name|sysindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_compare_sysidx
parameter_list|(
name|uint32_t
name|i1
parameter_list|,
name|uint32_t
name|i2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_attach_newif
parameter_list|(
name|struct
name|mibif
modifier|*
name|ifp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_if
modifier|*
name|bridge_first_bif
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_if
modifier|*
name|bridge_next_bif
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|b_pr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_remove_bif
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_update_all_ports
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_update_all_addrs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_update_all_ifs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_update_all
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_update_tc_time
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_ifs_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bridge ports. */
end_comment

begin_function_decl
name|void
name|bridge_ports_update_listage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_ports_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_members_free
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_port
modifier|*
name|bridge_new_port
parameter_list|(
name|struct
name|mibif
modifier|*
name|mif
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_port_remove
parameter_list|(
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_port
modifier|*
name|bridge_port_bif_first
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_port
modifier|*
name|bridge_port_bif_next
parameter_list|(
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|bridge_port
modifier|*
name|bridge_port_find
parameter_list|(
name|int32_t
name|if_idx
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_port_getinfo_mibif
parameter_list|(
name|struct
name|mibif
modifier|*
name|m_if
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_getinfo_bif_ports
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_update_memif
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_ports_dump
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bridge addresses. */
end_comment

begin_function_decl
name|void
name|bridge_addrs_update_listage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_addrs_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_addrs_free
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tp_entry
modifier|*
name|bridge_new_addrs
parameter_list|(
name|uint8_t
modifier|*
name|mac
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_addrs_remove
parameter_list|(
name|struct
name|tp_entry
modifier|*
name|te
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tp_entry
modifier|*
name|bridge_addrs_find
parameter_list|(
name|uint8_t
modifier|*
name|mac
parameter_list|,
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tp_entry
modifier|*
name|bridge_addrs_bif_first
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tp_entry
modifier|*
name|bridge_addrs_bif_next
parameter_list|(
name|struct
name|tp_entry
modifier|*
name|te
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_getinfo_bif_addrs
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bridge_update_addrs
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bridge_addrs_dump
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Bridge PF. */
end_comment

begin_function_decl
name|void
name|bridge_pf_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* System specific. */
end_comment

begin_comment
comment|/* Open the socket for the ioctls. */
end_comment

begin_function_decl
name|int
name|bridge_ioctl_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Load bridge kernel module. */
end_comment

begin_function_decl
name|int
name|bridge_kmod_load
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the bridge interface information. */
end_comment

begin_function_decl
name|int
name|bridge_getinfo_bif
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the bridge interface STP parameters. */
end_comment

begin_function_decl
name|int
name|bridge_get_op_param
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge priority. */
end_comment

begin_function_decl
name|int
name|bridge_set_priority
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge max age. */
end_comment

begin_function_decl
name|int
name|bridge_set_maxage
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|max_age
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge hello time.*/
end_comment

begin_function_decl
name|int
name|bridge_set_hello_time
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|hello_time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge forward delay.*/
end_comment

begin_function_decl
name|int
name|bridge_set_forward_delay
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|fwd_delay
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge address cache max age. */
end_comment

begin_function_decl
name|int
name|bridge_set_aging_time
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|age_time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the max number of entries in the bridge address cache. */
end_comment

begin_function_decl
name|int
name|bridge_set_max_cache
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|max_cache
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge TX hold count. */
end_comment

begin_function_decl
name|int
name|bridge_set_tx_hold_count
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|tx_hc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge STP protocol version. */
end_comment

begin_function_decl
name|int
name|bridge_set_stp_version
parameter_list|(
name|struct
name|bridge_if
modifier|*
name|bif
parameter_list|,
name|int32_t
name|stp_proto
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the bridge interface status to up/down. */
end_comment

begin_function_decl
name|int
name|bridge_set_if_up
parameter_list|(
specifier|const
name|char
modifier|*
name|b_name
parameter_list|,
name|int8_t
name|up
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a bridge interface. */
end_comment

begin_function_decl
name|int
name|bridge_create
parameter_list|(
specifier|const
name|char
modifier|*
name|b_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Destroy a bridge interface. */
end_comment

begin_function_decl
name|int
name|bridge_destroy
parameter_list|(
specifier|const
name|char
modifier|*
name|b_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the bridge mac address. */
end_comment

begin_function_decl
name|u_char
modifier|*
name|bridge_get_basemac
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|u_char
modifier|*
name|mac
parameter_list|,
name|size_t
name|mlen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a bridge member priority. */
end_comment

begin_function_decl
name|int
name|bridge_port_set_priority
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|int32_t
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a bridge member STP-enabled flag. */
end_comment

begin_function_decl
name|int
name|bridge_port_set_stp_enable
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|uint32_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set a bridge member STP path cost. */
end_comment

begin_function_decl
name|int
name|bridge_port_set_path_cost
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|int32_t
name|path_cost
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set admin point-to-point link. */
end_comment

begin_function_decl
name|int
name|bridge_port_set_admin_ptp
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|uint32_t
name|admin_ptp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set admin edge. */
end_comment

begin_function_decl
name|int
name|bridge_port_set_admin_edge
parameter_list|(
specifier|const
name|char
modifier|*
name|bif_name
parameter_list|,
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
name|uint32_t
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a bridge member port. */
end_comment

begin_function_decl
name|int
name|bridge_port_addm
parameter_list|(
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|b_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Delete a bridge member port. */
end_comment

begin_function_decl
name|int
name|bridge_port_delm
parameter_list|(
name|struct
name|bridge_port
modifier|*
name|bp
parameter_list|,
specifier|const
name|char
modifier|*
name|b_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the current value from the module for bridge PF control. */
end_comment

begin_function_decl
name|int32_t
name|bridge_get_pfval
parameter_list|(
name|uint8_t
name|which
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get/Set a bridge PF control. */
end_comment

begin_function_decl
name|int32_t
name|bridge_do_pfctl
parameter_list|(
name|int32_t
name|bridge_ctl
parameter_list|,
name|enum
name|snmp_op
name|op
parameter_list|,
name|int32_t
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SNMP_BRIDGE_H */
end_comment

end_unit

