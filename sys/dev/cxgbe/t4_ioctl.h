begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  * Written by: Navdeep Parhar<np@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_IOCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_IOCTL_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_comment
comment|/*  * Ioctl commands specific to this driver.  */
end_comment

begin_enum
enum|enum
block|{
name|T4_GETREG
init|=
literal|0x40
block|,
comment|/* read register */
name|T4_SETREG
block|,
comment|/* write register */
name|T4_REGDUMP
block|,
comment|/* dump of all registers */
name|T4_GET_FILTER_MODE
block|,
comment|/* get global filter mode */
name|T4_SET_FILTER_MODE
block|,
comment|/* set global filter mode */
name|T4_GET_FILTER
block|,
comment|/* get information about a filter */
name|T4_SET_FILTER
block|,
comment|/* program a filter */
name|T4_DEL_FILTER
block|,
comment|/* delete a filter */
name|T4_GET_SGE_CONTEXT
block|,
comment|/* get SGE context for a queue */
name|T4_LOAD_FW
block|,
comment|/* flash firmware */
name|T4_GET_MEM
block|,
comment|/* read memory */
name|T4_GET_I2C
block|,
comment|/* read from i2c addressible device */
name|T4_CLEAR_STATS
block|,
comment|/* clear a port's MAC statistics */
name|T4_SET_OFLD_POLICY
block|,
comment|/* Set offload policy */
name|T4_SET_SCHED_CLASS
block|,
comment|/* set sched class */
name|T4_SET_SCHED_QUEUE
block|,
comment|/* set queue class */
name|T4_GET_TRACER
block|,
comment|/* get information about a tracer */
name|T4_SET_TRACER
block|,
comment|/* program a tracer */
name|T4_LOAD_CFG
block|,
comment|/* copy a config file to card's flash */
name|T4_LOAD_BOOT
block|,
comment|/* flash boot rom */
name|T4_LOAD_BOOTCFG
block|,
comment|/* flash bootcfg */
name|T4_CUDBG_DUMP
block|,
comment|/* debug dump of chip state */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t4_reg
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|size
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T4_REGDUMP_SIZE
value|(160 * 1024)
end_define

begin_define
define|#
directive|define
name|T5_REGDUMP_SIZE
value|(332 * 1024)
end_define

begin_struct
struct|struct
name|t4_regdump
block|{
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
comment|/* bytes */
name|uint32_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_data
block|{
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_bootrom
block|{
name|uint32_t
name|pf_offset
decl_stmt|;
name|uint32_t
name|pfidx_addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_i2c_data
block|{
name|uint8_t
name|port_id
decl_stmt|;
name|uint8_t
name|dev_addr
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|len
decl_stmt|;
name|uint8_t
name|data
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A hardware filter is some valid combination of these.  */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IPv4
value|0x1
end_define

begin_comment
comment|/* IPv4 packet */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IPv6
value|0x2
end_define

begin_comment
comment|/* IPv6 packet */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_SADDR
value|0x4
end_define

begin_comment
comment|/* Source IP address or network */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_DADDR
value|0x8
end_define

begin_comment
comment|/* Destination IP address or network */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_SPORT
value|0x10
end_define

begin_comment
comment|/* Source IP port */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_DPORT
value|0x20
end_define

begin_comment
comment|/* Destination IP port */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_FCoE
value|0x40
end_define

begin_comment
comment|/* Fibre Channel over Ethernet packet */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_PORT
value|0x80
end_define

begin_comment
comment|/* Physical ingress port */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_VNIC
value|0x100
end_define

begin_comment
comment|/* VNIC id or outer VLAN */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_VLAN
value|0x200
end_define

begin_comment
comment|/* VLAN ID */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_TOS
value|0x400
end_define

begin_comment
comment|/* IPv4 TOS/IPv6 Traffic Class */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_PROTO
value|0x800
end_define

begin_comment
comment|/* IP protocol */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_ETH_TYPE
value|0x1000
end_define

begin_comment
comment|/* Ethernet Type */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_MAC_IDX
value|0x2000
end_define

begin_comment
comment|/* MPS MAC address match index */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_MPS_HIT_TYPE
value|0x4000
end_define

begin_comment
comment|/* MPS match type */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IP_FRAGMENT
value|0x8000
end_define

begin_comment
comment|/* IP fragment */
end_comment

begin_define
define|#
directive|define
name|T4_FILTER_IC_VNIC
value|0x80000000
end_define

begin_comment
comment|/* TP Ingress Config's F_VNIC 						   bit.  It indicates whether 						   T4_FILTER_VNIC bit means VNIC 						   id (PF/VF) or outer VLAN. 						   0 = oVLAN, 1 = VNIC */
end_comment

begin_comment
comment|/* Filter action */
end_comment

begin_enum
enum|enum
block|{
name|FILTER_PASS
init|=
literal|0
block|,
comment|/* default */
name|FILTER_DROP
block|,
name|FILTER_SWITCH
block|}
enum|;
end_enum

begin_comment
comment|/* 802.1q manipulation on FILTER_SWITCH */
end_comment

begin_enum
enum|enum
block|{
name|VLAN_NOCHANGE
init|=
literal|0
block|,
comment|/* default */
name|VLAN_REMOVE
block|,
name|VLAN_INSERT
block|,
name|VLAN_REWRITE
block|}
enum|;
end_enum

begin_comment
comment|/* MPS match type */
end_comment

begin_enum
enum|enum
block|{
name|UCAST_EXACT
init|=
literal|0
block|,
comment|/* exact unicast match */
name|UCAST_HASH
init|=
literal|1
block|,
comment|/* inexact (hashed) unicast match */
name|MCAST_EXACT
init|=
literal|2
block|,
comment|/* exact multicast match */
name|MCAST_HASH
init|=
literal|3
block|,
comment|/* inexact (hashed) multicast match */
name|PROMISC
init|=
literal|4
block|,
comment|/* no match but port is promiscuous */
name|HYPPROMISC
init|=
literal|5
block|,
comment|/* port is hypervisor-promisuous + not bcast */
name|BCAST
init|=
literal|6
block|,
comment|/* broadcast packet */
block|}
enum|;
end_enum

begin_comment
comment|/* Rx steering */
end_comment

begin_enum
enum|enum
block|{
name|DST_MODE_QUEUE
block|,
comment|/* queue is directly specified by filter */
name|DST_MODE_RSS_QUEUE
block|,
comment|/* filter specifies RSS entry containing queue */
name|DST_MODE_RSS
block|,
comment|/* queue selected by default RSS hash lookup */
name|DST_MODE_FILT_RSS
comment|/* queue selected by hashing in filter-specified 				  RSS subtable */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t4_filter_tuple
block|{
comment|/* 	 * These are always available. 	 */
name|uint8_t
name|sip
index|[
literal|16
index|]
decl_stmt|;
comment|/* source IP address (IPv4 in [3:0]) */
name|uint8_t
name|dip
index|[
literal|16
index|]
decl_stmt|;
comment|/* destinatin IP address (IPv4 in [3:0]) */
name|uint16_t
name|sport
decl_stmt|;
comment|/* source port */
name|uint16_t
name|dport
decl_stmt|;
comment|/* destination port */
comment|/* 	 * A combination of these (up to 36 bits) is available.  TP_VLAN_PRI_MAP 	 * is used to select the global mode and all filters are limited to the 	 * set of fields allowed by the global mode. 	 */
name|uint16_t
name|vnic
decl_stmt|;
comment|/* VNIC id (PF/VF) or outer VLAN tag */
name|uint16_t
name|vlan
decl_stmt|;
comment|/* VLAN tag */
name|uint16_t
name|ethtype
decl_stmt|;
comment|/* Ethernet type */
name|uint8_t
name|tos
decl_stmt|;
comment|/* TOS/Traffic Type */
name|uint8_t
name|proto
decl_stmt|;
comment|/* protocol type */
name|uint32_t
name|fcoe
range|:
literal|1
decl_stmt|;
comment|/* FCoE packet */
name|uint32_t
name|iport
range|:
literal|3
decl_stmt|;
comment|/* ingress port */
name|uint32_t
name|matchtype
range|:
literal|3
decl_stmt|;
comment|/* MPS match type */
name|uint32_t
name|frag
range|:
literal|1
decl_stmt|;
comment|/* fragmentation extension header */
name|uint32_t
name|macidx
range|:
literal|9
decl_stmt|;
comment|/* exact match MAC index */
name|uint32_t
name|vlan_vld
range|:
literal|1
decl_stmt|;
comment|/* VLAN valid */
name|uint32_t
name|ovlan_vld
range|:
literal|1
decl_stmt|;
comment|/* outer VLAN tag valid, value in "vnic" */
name|uint32_t
name|pfvf_vld
range|:
literal|1
decl_stmt|;
comment|/* VNIC id (PF/VF) valid, value in "vnic" */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_filter_specification
block|{
name|uint32_t
name|hitcnts
range|:
literal|1
decl_stmt|;
comment|/* count filter hits in TCB */
name|uint32_t
name|prio
range|:
literal|1
decl_stmt|;
comment|/* filter has priority over active/server */
name|uint32_t
name|type
range|:
literal|1
decl_stmt|;
comment|/* 0 => IPv4, 1 => IPv6 */
name|uint32_t
name|action
range|:
literal|2
decl_stmt|;
comment|/* drop, pass, switch */
name|uint32_t
name|rpttid
range|:
literal|1
decl_stmt|;
comment|/* report TID in RSS hash field */
name|uint32_t
name|dirsteer
range|:
literal|1
decl_stmt|;
comment|/* 0 => RSS, 1 => steer to iq */
name|uint32_t
name|iq
range|:
literal|10
decl_stmt|;
comment|/* ingress queue */
name|uint32_t
name|maskhash
range|:
literal|1
decl_stmt|;
comment|/* dirsteer=0: store RSS hash in TCB */
name|uint32_t
name|dirsteerhash
range|:
literal|1
decl_stmt|;
comment|/* dirsteer=1: 0 => TCB contains RSS hash */
comment|/*             1 => TCB contains IQ ID */
comment|/* 	 * Switch proxy/rewrite fields.  An ingress packet which matches a 	 * filter with "switch" set will be looped back out as an egress 	 * packet -- potentially with some Ethernet header rewriting. 	 */
name|uint32_t
name|eport
range|:
literal|2
decl_stmt|;
comment|/* egress port to switch packet out */
name|uint32_t
name|newdmac
range|:
literal|1
decl_stmt|;
comment|/* rewrite destination MAC address */
name|uint32_t
name|newsmac
range|:
literal|1
decl_stmt|;
comment|/* rewrite source MAC address */
name|uint32_t
name|newvlan
range|:
literal|2
decl_stmt|;
comment|/* rewrite VLAN Tag */
name|uint8_t
name|dmac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* new destination MAC address */
name|uint8_t
name|smac
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* new source MAC address */
name|uint16_t
name|vlan
decl_stmt|;
comment|/* VLAN Tag to insert */
comment|/* 	 * Filter rule value/mask pairs. 	 */
name|struct
name|t4_filter_tuple
name|val
decl_stmt|;
name|struct
name|t4_filter_tuple
name|mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_filter
block|{
name|uint32_t
name|idx
decl_stmt|;
name|uint16_t
name|l2tidx
decl_stmt|;
name|uint16_t
name|smtidx
decl_stmt|;
name|uint64_t
name|hits
decl_stmt|;
name|struct
name|t4_filter_specification
name|fs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tx Scheduling Class parameters */
end_comment

begin_struct
struct|struct
name|t4_sched_class_params
block|{
name|int8_t
name|level
decl_stmt|;
comment|/* scheduler hierarchy level */
name|int8_t
name|mode
decl_stmt|;
comment|/* per-class or per-flow */
name|int8_t
name|rateunit
decl_stmt|;
comment|/* bit or packet rate */
name|int8_t
name|ratemode
decl_stmt|;
comment|/* %port relative or kbps absolute */
name|int8_t
name|channel
decl_stmt|;
comment|/* scheduler channel [0..N] */
name|int8_t
name|cl
decl_stmt|;
comment|/* scheduler class [0..N] */
name|int32_t
name|minrate
decl_stmt|;
comment|/* minimum rate */
name|int32_t
name|maxrate
decl_stmt|;
comment|/* maximum rate */
name|int16_t
name|weight
decl_stmt|;
comment|/* percent weight */
name|int16_t
name|pktsize
decl_stmt|;
comment|/* average packet size */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Support for "sched-class" command to allow a TX Scheduling Class to be  * programmed with various parameters.  */
end_comment

begin_struct
struct|struct
name|t4_sched_params
block|{
name|int8_t
name|subcmd
decl_stmt|;
comment|/* sub-command */
name|int8_t
name|type
decl_stmt|;
comment|/* packet or flow */
union|union
block|{
struct|struct
block|{
comment|/* sub-command SCHED_CLASS_CONFIG */
name|int8_t
name|minmax
decl_stmt|;
comment|/* minmax enable */
block|}
name|config
struct|;
name|struct
name|t4_sched_class_params
name|params
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|6
operator|+
literal|8
operator|*
literal|8
index|]
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|SCHED_CLASS_SUBCMD_CONFIG
block|,
comment|/* config sub-command */
name|SCHED_CLASS_SUBCMD_PARAMS
block|,
comment|/* params sub-command */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SCHED_CLASS_TYPE_PACKET
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SCHED_CLASS_LEVEL_CL_RL
block|,
comment|/* class rate limiter */
name|SCHED_CLASS_LEVEL_CL_WRR
block|,
comment|/* class weighted round robin */
name|SCHED_CLASS_LEVEL_CH_RL
block|,
comment|/* channel rate limiter */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SCHED_CLASS_MODE_CLASS
block|,
comment|/* per-class scheduling */
name|SCHED_CLASS_MODE_FLOW
block|,
comment|/* per-flow scheduling */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SCHED_CLASS_RATEUNIT_BITS
block|,
comment|/* bit rate scheduling */
name|SCHED_CLASS_RATEUNIT_PKTS
block|,
comment|/* packet rate scheduling */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SCHED_CLASS_RATEMODE_REL
block|,
comment|/* percent of port bandwidth */
name|SCHED_CLASS_RATEMODE_ABS
block|,
comment|/* Kb/s */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Support for "sched_queue" command to allow one or more NIC TX Queues to be  * bound to a TX Scheduling Class.  */
end_comment

begin_struct
struct|struct
name|t4_sched_queue
block|{
name|uint8_t
name|port
decl_stmt|;
name|int8_t
name|queue
decl_stmt|;
comment|/* queue index; -1 => all queues */
name|int8_t
name|cl
decl_stmt|;
comment|/* class index; -1 => unbind */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T4_SGE_CONTEXT_SIZE
value|24
end_define

begin_enum
enum|enum
block|{
name|SGE_CONTEXT_EGRESS
block|,
name|SGE_CONTEXT_INGRESS
block|,
name|SGE_CONTEXT_FLM
block|,
name|SGE_CONTEXT_CNM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|t4_sge_context
block|{
name|uint32_t
name|mem_id
decl_stmt|;
name|uint32_t
name|cid
decl_stmt|;
name|uint32_t
name|data
index|[
name|T4_SGE_CONTEXT_SIZE
operator|/
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_mem_range
block|{
name|uint32_t
name|addr
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint32_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|T4_TRACE_LEN
value|112
end_define

begin_struct
struct|struct
name|t4_trace_params
block|{
name|uint32_t
name|data
index|[
name|T4_TRACE_LEN
operator|/
literal|4
index|]
decl_stmt|;
name|uint32_t
name|mask
index|[
name|T4_TRACE_LEN
operator|/
literal|4
index|]
decl_stmt|;
name|uint16_t
name|snap_len
decl_stmt|;
name|uint16_t
name|min_len
decl_stmt|;
name|uint8_t
name|skip_ofst
decl_stmt|;
name|uint8_t
name|skip_len
decl_stmt|;
name|uint8_t
name|invert
decl_stmt|;
name|uint8_t
name|port
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_tracer
block|{
name|uint8_t
name|idx
decl_stmt|;
name|uint8_t
name|enabled
decl_stmt|;
name|uint8_t
name|valid
decl_stmt|;
name|struct
name|t4_trace_params
name|tp
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|t4_cudbg_dump
block|{
name|uint8_t
name|wr_flash
decl_stmt|;
name|uint8_t
name|bitmap
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|len
decl_stmt|;
name|uint8_t
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CHELSIO_T4_GETREG
value|_IOWR('f', T4_GETREG, struct t4_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SETREG
value|_IOW('f', T4_SETREG, struct t4_reg)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_REGDUMP
value|_IOWR('f', T4_REGDUMP, struct t4_regdump)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_FILTER_MODE
value|_IOWR('f', T4_GET_FILTER_MODE, uint32_t)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SET_FILTER_MODE
value|_IOW('f', T4_SET_FILTER_MODE, uint32_t)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_FILTER
value|_IOWR('f', T4_GET_FILTER, struct t4_filter)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SET_FILTER
value|_IOW('f', T4_SET_FILTER, struct t4_filter)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_DEL_FILTER
value|_IOW('f', T4_DEL_FILTER, struct t4_filter)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_SGE_CONTEXT
value|_IOWR('f', T4_GET_SGE_CONTEXT, \     struct t4_sge_context)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_LOAD_FW
value|_IOW('f', T4_LOAD_FW, struct t4_data)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_MEM
value|_IOW('f', T4_GET_MEM, struct t4_mem_range)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_I2C
value|_IOWR('f', T4_GET_I2C, struct t4_i2c_data)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_CLEAR_STATS
value|_IOW('f', T4_CLEAR_STATS, uint32_t)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SCHED_CLASS
value|_IOW('f', T4_SET_SCHED_CLASS, \     struct t4_sched_params)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SCHED_QUEUE
value|_IOW('f', T4_SET_SCHED_QUEUE, \     struct t4_sched_queue)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_GET_TRACER
value|_IOWR('f', T4_GET_TRACER, struct t4_tracer)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_SET_TRACER
value|_IOW('f', T4_SET_TRACER, struct t4_tracer)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_LOAD_CFG
value|_IOW('f', T4_LOAD_CFG, struct t4_data)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_LOAD_BOOT
value|_IOW('f', T4_LOAD_BOOT, struct t4_bootrom)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_LOAD_BOOTCFG
value|_IOW('f', T4_LOAD_BOOTCFG, struct t4_data)
end_define

begin_define
define|#
directive|define
name|CHELSIO_T4_CUDBG_DUMP
value|_IOWR('f', T4_CUDBG_DUMP, struct t4_cudbg_dump)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

