begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010-2011 Alexander V. Chernikov<melifaro@ipfw.ru>  * Copyright (c) 2004-2005 Gleb Smirnoff<glebius@FreeBSD.org>  * Copyright (c) 2001-2003 Roman V. Palagin<romanp@unshadow.net>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	 $SourceForge: ng_netflow.h,v 1.26 2004/09/04 15:44:55 glebius Exp $  *	 $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NG_NETFLOW_H_
end_ifndef

begin_define
define|#
directive|define
name|_NG_NETFLOW_H_
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_NODE_TYPE
value|"netflow"
end_define

begin_define
define|#
directive|define
name|NGM_NETFLOW_COOKIE
value|1365756954
end_define

begin_define
define|#
directive|define
name|NGM_NETFLOW_V9_COOKIE
value|1349865386
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_MAXIFACES
value|USHRT_MAX
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_HOOK_DATA
value|"iface"
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_HOOK_OUT
value|"out"
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_HOOK_EXPORT
value|"export"
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_HOOK_EXPORT9
value|"export9"
end_define

begin_comment
comment|/* This define effectively disable (v5) netflow export hook! */
end_comment

begin_comment
comment|/* #define COUNTERS_64 */
end_comment

begin_comment
comment|/* Netgraph commands understood by netflow node */
end_comment

begin_enum
enum|enum
block|{
name|NGM_NETFLOW_INFO
init|=
literal|1
operator||
name|NGM_READONLY
operator||
name|NGM_HASREPLY
block|,
comment|/* get node info */
name|NGM_NETFLOW_IFINFO
init|=
literal|2
operator||
name|NGM_READONLY
operator||
name|NGM_HASREPLY
block|,
comment|/* get iface info */
name|NGM_NETFLOW_SHOW
init|=
literal|3
operator||
name|NGM_READONLY
operator||
name|NGM_HASREPLY
block|,
comment|/* show ip cache flow */
name|NGM_NETFLOW_SETDLT
init|=
literal|4
block|,
comment|/* set data-link type */
name|NGM_NETFLOW_SETIFINDEX
init|=
literal|5
block|,
comment|/* set interface index */
name|NGM_NETFLOW_SETTIMEOUTS
init|=
literal|6
block|,
comment|/* set active/inactive flow timeouts */
name|NGM_NETFLOW_SETCONFIG
init|=
literal|7
block|,
comment|/* set flow generation options */
name|NGM_NETFLOW_SETTEMPLATE
init|=
literal|8
block|,
comment|/* set v9 flow template periodic */
name|NGM_NETFLOW_SETMTU
init|=
literal|9
block|,
comment|/* set outgoing interface MTU */
name|NGM_NETFLOW_V9INFO
init|=
literal|10
operator||
name|NGM_READONLY
operator||
name|NGM_HASREPLY
block|,
comment|/* get v9 info */
block|}
enum|;
end_enum

begin_comment
comment|/* This structure is returned by the NGM_NETFLOW_INFO message */
end_comment

begin_struct
struct|struct
name|ng_netflow_info
block|{
name|uint64_t
name|nfinfo_bytes
decl_stmt|;
comment|/* accounted IPv4 bytes */
name|uint64_t
name|nfinfo_packets
decl_stmt|;
comment|/* accounted IPv4 packets */
name|uint64_t
name|nfinfo_bytes6
decl_stmt|;
comment|/* accounted IPv6 bytes */
name|uint64_t
name|nfinfo_packets6
decl_stmt|;
comment|/* accounted IPv6 packets */
name|uint64_t
name|nfinfo_sbytes
decl_stmt|;
comment|/* skipped IPv4 bytes */
name|uint64_t
name|nfinfo_spackets
decl_stmt|;
comment|/* skipped IPv4 packets */
name|uint64_t
name|nfinfo_sbytes6
decl_stmt|;
comment|/* skipped IPv6 bytes */
name|uint64_t
name|nfinfo_spackets6
decl_stmt|;
comment|/* skipped IPv6 packets */
name|uint64_t
name|nfinfo_act_exp
decl_stmt|;
comment|/* active expiries */
name|uint64_t
name|nfinfo_inact_exp
decl_stmt|;
comment|/* inactive expiries */
name|uint32_t
name|nfinfo_used
decl_stmt|;
comment|/* used cache records */
name|uint32_t
name|nfinfo_used6
decl_stmt|;
comment|/* used IPv6 cache records */
name|uint32_t
name|nfinfo_alloc_failed
decl_stmt|;
comment|/* failed allocations */
name|uint32_t
name|nfinfo_export_failed
decl_stmt|;
comment|/* failed exports */
name|uint32_t
name|nfinfo_export9_failed
decl_stmt|;
comment|/* failed exports */
name|uint32_t
name|nfinfo_realloc_mbuf
decl_stmt|;
comment|/* reallocated mbufs */
name|uint32_t
name|nfinfo_alloc_fibs
decl_stmt|;
comment|/* fibs allocated */
name|uint32_t
name|nfinfo_inact_t
decl_stmt|;
comment|/* flow inactive timeout */
name|uint32_t
name|nfinfo_act_t
decl_stmt|;
comment|/* flow active timeout */
block|}
struct|;
end_struct

begin_comment
comment|/* Parse the info structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_INFO_TYPE
value|{					\ 	{ "IPv4 bytes",&ng_parse_uint64_type },\ 	{ "IPv4 packets",&ng_parse_uint64_type },\ 	{ "IPv6 bytes",&ng_parse_uint64_type },\ 	{ "IPv6 packets",&ng_parse_uint64_type },\ 	{ "IPv4 skipped bytes",&ng_parse_uint64_type },\ 	{ "IPv4 skipped packets",&ng_parse_uint64_type },\ 	{ "IPv6 skipped bytes",&ng_parse_uint64_type },\ 	{ "IPv6 skipped packets",&ng_parse_uint64_type },\ 	{ "Active expiries",&ng_parse_uint64_type },\ 	{ "Inactive expiries",&ng_parse_uint64_type },\ 	{ "IPv4 records used",&ng_parse_uint32_type },\ 	{ "IPv6 records used",&ng_parse_uint32_type },\ 	{ "Failed allocations",&ng_parse_uint32_type },\ 	{ "V5 failed exports",&ng_parse_uint32_type },\ 	{ "V9 failed exports",&ng_parse_uint32_type },\ 	{ "mbuf reallocations",&ng_parse_uint32_type },\ 	{ "fibs allocated",&ng_parse_uint32_type },\ 	{ "Inactive timeout",&ng_parse_uint32_type },\ 	{ "Active timeout",&ng_parse_uint32_type },\ 	{ NULL }						\ }
end_define

begin_comment
comment|/* This structure is returned by the NGM_NETFLOW_IFINFO message */
end_comment

begin_struct
struct|struct
name|ng_netflow_ifinfo
block|{
name|uint32_t
name|ifinfo_packets
decl_stmt|;
comment|/* number of packets for this iface */
name|uint8_t
name|ifinfo_dlt
decl_stmt|;
comment|/* Data Link Type, DLT_XXX */
define|#
directive|define
name|MAXDLTNAMELEN
value|20
name|uint16_t
name|ifinfo_index
decl_stmt|;
comment|/* connected iface index */
name|uint32_t
name|conf
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETDLT message */
end_comment

begin_struct
struct|struct
name|ng_netflow_setdlt
block|{
name|uint16_t
name|iface
decl_stmt|;
comment|/* which iface dlt change */
name|uint8_t
name|dlt
decl_stmt|;
comment|/* DLT_XXX from bpf.h */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETIFINDEX */
end_comment

begin_struct
struct|struct
name|ng_netflow_setifindex
block|{
name|uint16_t
name|iface
decl_stmt|;
comment|/* which iface index change */
name|uint16_t
name|index
decl_stmt|;
comment|/* new index */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETTIMEOUTS */
end_comment

begin_struct
struct|struct
name|ng_netflow_settimeouts
block|{
name|uint32_t
name|inactive_timeout
decl_stmt|;
comment|/* flow inactive timeout */
name|uint32_t
name|active_timeout
decl_stmt|;
comment|/* flow active timeout */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_INGRESS
value|0x01
end_define

begin_comment
comment|/* Account on ingress */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_EGRESS
value|0x02
end_define

begin_comment
comment|/* Account on egress */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_ONCE
value|0x04
end_define

begin_comment
comment|/* Add tag to account only once */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_THISONCE
value|0x08
end_define

begin_comment
comment|/* Account once in current node */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_NOSRCLOOKUP
value|0x10
end_define

begin_comment
comment|/* No radix lookup on src */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_CONF_NODSTLOOKUP
value|0x20
end_define

begin_comment
comment|/* No radix lookup on dst */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_IS_FRAG
value|0x01
end_define

begin_define
define|#
directive|define
name|NG_NETFLOW_FLOW_FLAGS
value|(NG_NETFLOW_CONF_NOSRCLOOKUP|\ 					NG_NETFLOW_CONF_NODSTLOOKUP)
end_define

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETCONFIG */
end_comment

begin_struct
struct|struct
name|ng_netflow_setconfig
block|{
name|uint16_t
name|iface
decl_stmt|;
comment|/* which iface config change */
name|uint32_t
name|conf
decl_stmt|;
comment|/* new config */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETTEMPLATE */
end_comment

begin_struct
struct|struct
name|ng_netflow_settemplate
block|{
name|uint16_t
name|time
decl_stmt|;
comment|/* max time between announce */
name|uint16_t
name|packets
decl_stmt|;
comment|/* max packets between announce */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is passed to NGM_NETFLOW_SETMTU */
end_comment

begin_struct
struct|struct
name|ng_netflow_setmtu
block|{
name|uint16_t
name|mtu
decl_stmt|;
comment|/* MTU for packet */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used in NGM_NETFLOW_SHOW request/responce */
end_comment

begin_struct
struct|struct
name|ngnf_show_header
block|{
name|u_char
name|version
decl_stmt|;
comment|/* IPv4 or IPv6 */
name|uint32_t
name|hash_id
decl_stmt|;
comment|/* current hash index */
name|uint32_t
name|list_id
decl_stmt|;
comment|/* current record number in hash */
name|uint32_t
name|nentries
decl_stmt|;
comment|/* number of records in response */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used in NGM_NETFLOW_V9INFO message */
end_comment

begin_struct
struct|struct
name|ng_netflow_v9info
block|{
name|uint16_t
name|templ_packets
decl_stmt|;
comment|/* v9 template packets */
name|uint16_t
name|templ_time
decl_stmt|;
comment|/* v9 template time */
name|uint16_t
name|mtu
decl_stmt|;
comment|/* v9 MTU */
block|}
struct|;
end_struct

begin_comment
comment|/* XXXGL  * Somewhere flow_rec6 is casted to flow_rec, and flow6_entry_data is  * casted to flow_entry_data. After casting, fle->r.fib is accessed.  * So beginning of these structs up to fib should be kept common.  */
end_comment

begin_comment
comment|/* This is unique data, which identifies flow */
end_comment

begin_struct
struct|struct
name|flow_rec
block|{
name|uint16_t
name|flow_type
decl_stmt|;
name|uint16_t
name|fib
decl_stmt|;
name|struct
name|in_addr
name|r_src
decl_stmt|;
name|struct
name|in_addr
name|r_dst
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|s_port
decl_stmt|;
comment|/* source TCP/UDP port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* destination TCP/UDP port */
block|}
name|dir
struct|;
name|uint32_t
name|both
decl_stmt|;
block|}
name|ports
union|;
union|union
block|{
struct|struct
block|{
name|u_char
name|prot
decl_stmt|;
comment|/* IP protocol */
name|u_char
name|tos
decl_stmt|;
comment|/* IP TOS */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* input interface index */
block|}
name|i
struct|;
name|uint32_t
name|all
decl_stmt|;
block|}
name|misc
union|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is unique data, which identifies flow */
end_comment

begin_struct
struct|struct
name|flow6_rec
block|{
name|uint16_t
name|flow_type
decl_stmt|;
name|uint16_t
name|fib
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|r_src
decl_stmt|;
name|struct
name|in6_addr
name|r_src6
decl_stmt|;
block|}
name|src
union|;
union|union
block|{
name|struct
name|in_addr
name|r_dst
decl_stmt|;
name|struct
name|in6_addr
name|r_dst6
decl_stmt|;
block|}
name|dst
union|;
union|union
block|{
struct|struct
block|{
name|uint16_t
name|s_port
decl_stmt|;
comment|/* source TCP/UDP port */
name|uint16_t
name|d_port
decl_stmt|;
comment|/* destination TCP/UDP port */
block|}
name|dir
struct|;
name|uint32_t
name|both
decl_stmt|;
block|}
name|ports
union|;
union|union
block|{
struct|struct
block|{
name|u_char
name|prot
decl_stmt|;
comment|/* IP protocol */
name|u_char
name|tos
decl_stmt|;
comment|/* IP TOS */
name|uint16_t
name|i_ifx
decl_stmt|;
comment|/* input interface index */
block|}
name|i
struct|;
name|uint32_t
name|all
decl_stmt|;
block|}
name|misc
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|r_ip_p
value|misc.i.prot
end_define

begin_define
define|#
directive|define
name|r_tos
value|misc.i.tos
end_define

begin_define
define|#
directive|define
name|r_i_ifx
value|misc.i.i_ifx
end_define

begin_define
define|#
directive|define
name|r_misc
value|misc.all
end_define

begin_define
define|#
directive|define
name|r_ports
value|ports.both
end_define

begin_define
define|#
directive|define
name|r_sport
value|ports.dir.s_port
end_define

begin_define
define|#
directive|define
name|r_dport
value|ports.dir.d_port
end_define

begin_comment
comment|/* A flow entry which accumulates statistics */
end_comment

begin_struct
struct|struct
name|flow_entry_data
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* Protocol version */
name|struct
name|flow_rec
name|r
decl_stmt|;
name|struct
name|in_addr
name|next_hop
decl_stmt|;
name|uint16_t
name|fle_o_ifx
decl_stmt|;
comment|/* output interface index */
define|#
directive|define
name|fle_i_ifx
value|r.misc.i.i_ifx
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* destination route mask bits */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* source route mask bits */
name|u_long
name|packets
decl_stmt|;
name|u_long
name|bytes
decl_stmt|;
name|long
name|first
decl_stmt|;
comment|/* uptime on first packet */
name|long
name|last
decl_stmt|;
comment|/* uptime on last packet */
name|u_char
name|tcp_flags
decl_stmt|;
comment|/* cumulative OR */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|flow6_entry_data
block|{
name|uint16_t
name|version
decl_stmt|;
comment|/* Protocol version */
name|struct
name|flow6_rec
name|r
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|next_hop
decl_stmt|;
name|struct
name|in6_addr
name|next_hop6
decl_stmt|;
block|}
name|n
union|;
name|uint16_t
name|fle_o_ifx
decl_stmt|;
comment|/* output interface index */
define|#
directive|define
name|fle_i_ifx
value|r.misc.i.i_ifx
name|uint8_t
name|dst_mask
decl_stmt|;
comment|/* destination route mask bits */
name|uint8_t
name|src_mask
decl_stmt|;
comment|/* source route mask bits */
name|u_long
name|packets
decl_stmt|;
name|u_long
name|bytes
decl_stmt|;
name|long
name|first
decl_stmt|;
comment|/* uptime on first packet */
name|long
name|last
decl_stmt|;
comment|/* uptime on last packet */
name|u_char
name|tcp_flags
decl_stmt|;
comment|/* cumulative OR */
block|}
struct|;
end_struct

begin_comment
comment|/*  * How many flow records we will transfer at once  * without overflowing socket receive buffer  */
end_comment

begin_define
define|#
directive|define
name|NREC_AT_ONCE
value|1000
end_define

begin_define
define|#
directive|define
name|NREC6_AT_ONCE
value|(NREC_AT_ONCE * sizeof(struct flow_entry_data) / \ 			sizeof(struct flow6_entry_data))
end_define

begin_define
define|#
directive|define
name|NGRESP_SIZE
value|(sizeof(struct ngnf_show_header) + (NREC_AT_ONCE * \ 			sizeof(struct flow_entry_data)))
end_define

begin_define
define|#
directive|define
name|SORCVBUF_SIZE
value|(NGRESP_SIZE + 2 * sizeof(struct ng_mesg))
end_define

begin_comment
comment|/* Everything below is for kernel */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|flow_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|flow_entry
argument_list|)
name|fle_hash
expr_stmt|;
comment|/* entries in hash slot */
name|struct
name|flow_entry_data
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|flow6_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|flow_entry
argument_list|)
name|fle_hash
expr_stmt|;
comment|/* entries in hash slot */
name|struct
name|flow6_entry_data
name|f
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Parsing declarations */
end_comment

begin_comment
comment|/* Parse the ifinfo structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_IFINFO_TYPE
value|{			\ 	{ "packets",&ng_parse_uint32_type },\ 	{ "data link type",&ng_parse_uint8_type },	\ 	{ "index",&ng_parse_uint16_type },\ 	{ "conf",&ng_parse_uint32_type },\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the setdlt structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETDLT_TYPE
value|{			\ 	{ "iface",&ng_parse_uint16_type },	\ 	{ "dlt",&ng_parse_uint8_type },		\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the setifindex structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETIFINDEX_TYPE
value|{			\ 	{ "iface",&ng_parse_uint16_type },	\ 	{ "index",&ng_parse_uint16_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the settimeouts structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETTIMEOUTS_TYPE
value|{			\ 	{ "inactive",&ng_parse_uint32_type },	\ 	{ "active",&ng_parse_uint32_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the setifindex structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETCONFIG_TYPE
value|{			\ 	{ "iface",&ng_parse_uint16_type },	\ 	{ "conf",&ng_parse_uint32_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the settemplate structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETTEMPLATE_TYPE
value|{		\ 	{ "time",&ng_parse_uint16_type },	\ 	{ "packets",&ng_parse_uint16_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the setmtu structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_SETMTU_TYPE
value|{			\ 	{ "mtu",&ng_parse_uint16_type },	\ 	{ NULL }					\ }
end_define

begin_comment
comment|/* Parse the v9info structure */
end_comment

begin_define
define|#
directive|define
name|NG_NETFLOW_V9INFO_TYPE
value|{				\ 	{ "v9 template packets",&ng_parse_uint16_type },\ 	{ "v9 template time",&ng_parse_uint16_type },\ 	{ "v9 MTU",&ng_parse_uint16_type },\ 	{ NULL }						\ }
end_define

begin_comment
comment|/* Private hook data */
end_comment

begin_struct
struct|struct
name|ng_netflow_iface
block|{
name|hook_p
name|hook
decl_stmt|;
comment|/* NULL when disconnected */
name|hook_p
name|out
decl_stmt|;
comment|/* NULL when no bypass hook */
name|struct
name|ng_netflow_ifinfo
name|info
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_netflow_iface
modifier|*
name|iface_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_netflow_ifinfo
modifier|*
name|ifinfo_p
typedef|;
end_typedef

begin_struct
struct|struct
name|netflow_export_item
block|{
name|item_p
name|item
decl_stmt|;
name|item_p
name|item9
decl_stmt|;
name|struct
name|netflow_v9_packet_opt
modifier|*
name|item9_opt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Structure contatining fib-specific data */
end_comment

begin_struct
struct|struct
name|fib_export
block|{
name|uint32_t
name|fib
decl_stmt|;
comment|/* kernel fib id */
comment|/* Various data used for export */
name|struct
name|netflow_export_item
name|exp
decl_stmt|;
name|struct
name|mtx
name|export_mtx
decl_stmt|;
comment|/* exp.item mutex */
name|struct
name|mtx
name|export9_mtx
decl_stmt|;
comment|/* exp.item9 mutex */
name|uint32_t
name|flow_seq
decl_stmt|;
comment|/* current V5 flow sequence */
name|uint32_t
name|flow9_seq
decl_stmt|;
comment|/* current V9 flow sequence */
name|uint32_t
name|domain_id
decl_stmt|;
comment|/* Observartion domain id */
comment|/* Netflow V9 counters */
name|uint32_t
name|templ_last_ts
decl_stmt|;
comment|/* unixtime of last template announce */
name|uint32_t
name|templ_last_pkt
decl_stmt|;
comment|/* packet count on last announce */
name|uint32_t
name|sent_packets
decl_stmt|;
comment|/* packets sent by exporter; */
comment|/* Current packet specific options */
name|struct
name|netflow_v9_packet_opt
modifier|*
name|export9_opt
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fib_export
modifier|*
name|fib_export_p
typedef|;
end_typedef

begin_comment
comment|/* Structure describing our flow engine */
end_comment

begin_struct
struct|struct
name|netflow
block|{
name|node_p
name|node
decl_stmt|;
comment|/* link to the node itself */
name|hook_p
name|export
decl_stmt|;
comment|/* export data goes there */
name|hook_p
name|export9
decl_stmt|;
comment|/* Netflow V9 export data goes there */
name|struct
name|callout
name|exp_callout
decl_stmt|;
comment|/* expiry periodic job */
comment|/* 	 * Flow entries are allocated in uma(9) zone zone. They are 	 * indexed by hash hash. Each hash element consist of tailqueue 	 * head and mutex to protect this element. 	 */
define|#
directive|define
name|CACHESIZE
value|(65536*16)
define|#
directive|define
name|CACHELOWAT
value|(CACHESIZE * 3/4)
define|#
directive|define
name|CACHEHIGHWAT
value|(CACHESIZE * 9/10)
name|uma_zone_t
name|zone
decl_stmt|;
name|struct
name|flow_hash_entry
modifier|*
name|hash
decl_stmt|;
comment|/* 	 * NetFlow data export 	 * 	 * export_item is a data item, it has an mbuf with cluster 	 * attached to it. A thread detaches export_item from priv 	 * and works with it. If the export is full it is sent, and 	 * a new one is allocated. Before exiting thread re-attaches 	 * its current item back to priv. If there is item already, 	 * current incomplete datagram is sent. 	 * export_mtx is used for attaching/detaching. 	 */
comment|/* IPv6 support */
ifdef|#
directive|ifdef
name|INET6
name|uma_zone_t
name|zone6
decl_stmt|;
name|struct
name|flow_hash_entry
modifier|*
name|hash6
decl_stmt|;
endif|#
directive|endif
comment|/* Statistics. */
name|counter_u64_t
name|nfinfo_bytes
decl_stmt|;
comment|/* accounted IPv4 bytes */
name|counter_u64_t
name|nfinfo_packets
decl_stmt|;
comment|/* accounted IPv4 packets */
name|counter_u64_t
name|nfinfo_bytes6
decl_stmt|;
comment|/* accounted IPv6 bytes */
name|counter_u64_t
name|nfinfo_packets6
decl_stmt|;
comment|/* accounted IPv6 packets */
name|counter_u64_t
name|nfinfo_sbytes
decl_stmt|;
comment|/* skipped IPv4 bytes */
name|counter_u64_t
name|nfinfo_spackets
decl_stmt|;
comment|/* skipped IPv4 packets */
name|counter_u64_t
name|nfinfo_sbytes6
decl_stmt|;
comment|/* skipped IPv6 bytes */
name|counter_u64_t
name|nfinfo_spackets6
decl_stmt|;
comment|/* skipped IPv6 packets */
name|counter_u64_t
name|nfinfo_act_exp
decl_stmt|;
comment|/* active expiries */
name|counter_u64_t
name|nfinfo_inact_exp
decl_stmt|;
comment|/* inactive expiries */
name|uint32_t
name|nfinfo_alloc_failed
decl_stmt|;
comment|/* failed allocations */
name|uint32_t
name|nfinfo_export_failed
decl_stmt|;
comment|/* failed exports */
name|uint32_t
name|nfinfo_export9_failed
decl_stmt|;
comment|/* failed exports */
name|uint32_t
name|nfinfo_realloc_mbuf
decl_stmt|;
comment|/* reallocated mbufs */
name|uint32_t
name|nfinfo_alloc_fibs
decl_stmt|;
comment|/* fibs allocated */
name|uint32_t
name|nfinfo_inact_t
decl_stmt|;
comment|/* flow inactive timeout */
name|uint32_t
name|nfinfo_act_t
decl_stmt|;
comment|/* flow active timeout */
comment|/* Multiple FIB support */
name|fib_export_p
modifier|*
name|fib_data
decl_stmt|;
comment|/* vector to per-fib data */
name|uint16_t
name|maxfibs
decl_stmt|;
comment|/* number of allocated fibs */
comment|/* Netflow v9 configuration options */
comment|/* 	 * RFC 3954 clause 7.3 	 * "Both options MUST be configurable by the user on the Exporter." 	 */
name|uint16_t
name|templ_time
decl_stmt|;
comment|/* time between sending templates */
name|uint16_t
name|templ_packets
decl_stmt|;
comment|/* packets between sending templates */
define|#
directive|define
name|NETFLOW_V9_MAX_FLOWSETS
value|2
name|u_char
name|flowsets_count
decl_stmt|;
comment|/* current flowsets used */
comment|/* Count of records in each flowset */
name|u_char
name|flowset_records
index|[
name|NETFLOW_V9_MAX_FLOWSETS
operator|-
literal|1
index|]
decl_stmt|;
name|uint16_t
name|mtu
decl_stmt|;
comment|/* export interface MTU */
comment|/* Pointers to pre-compiled flowsets */
name|struct
name|netflow_v9_flowset_header
modifier|*
name|v9_flowsets
index|[
name|NETFLOW_V9_MAX_FLOWSETS
operator|-
literal|1
index|]
decl_stmt|;
name|struct
name|ng_netflow_iface
name|ifaces
index|[
name|NG_NETFLOW_MAXIFACES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|netflow
modifier|*
name|priv_p
typedef|;
end_typedef

begin_comment
comment|/* Header of a small list in hash cell */
end_comment

begin_struct
struct|struct
name|flow_hash_entry
block|{
name|struct
name|mtx
name|mtx
decl_stmt|;
name|TAILQ_HEAD
argument_list|(
argument|fhead
argument_list|,
argument|flow_entry
argument_list|)
name|head
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ERROUT
parameter_list|(
name|x
parameter_list|)
value|{ error = (x); goto done; }
end_define

begin_define
define|#
directive|define
name|MTAG_NETFLOW
value|1221656444
end_define

begin_define
define|#
directive|define
name|MTAG_NETFLOW_CALLED
value|0
end_define

begin_define
define|#
directive|define
name|m_pktlen
parameter_list|(
name|m
parameter_list|)
value|((m)->m_pkthdr.len)
end_define

begin_define
define|#
directive|define
name|IP6VERSION
value|6
end_define

begin_define
define|#
directive|define
name|priv_to_fib
parameter_list|(
name|priv
parameter_list|,
name|fib
parameter_list|)
value|(priv)->fib_data[(fib)]
end_define

begin_comment
comment|/*  * Cisco uses milliseconds for uptime. Bad idea, since it overflows  * every 48+ days. But we will do same to keep compatibility. This macro  * does overflowable multiplication to 1000.  */
end_comment

begin_define
define|#
directive|define
name|MILLIUPTIME
parameter_list|(
name|t
parameter_list|)
value|(((t)<< 9) +
comment|/* 512 */
value|\ 			 ((t)<< 8) +
comment|/* 256 */
value|\ 			 ((t)<< 7) +
comment|/* 128 */
value|\ 			 ((t)<< 6) +
comment|/* 64  */
value|\ 			 ((t)<< 5) +
comment|/* 32  */
value|\ 			 ((t)<< 3))
end_define

begin_comment
comment|/* 8   */
end_comment

begin_comment
comment|/* Prototypes for netflow.c */
end_comment

begin_function_decl
name|void
name|ng_netflow_cache_init
parameter_list|(
name|priv_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_netflow_cache_flush
parameter_list|(
name|priv_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_netflow_fib_init
parameter_list|(
name|priv_p
name|priv
parameter_list|,
name|int
name|fib
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_netflow_copyinfo
parameter_list|(
name|priv_p
parameter_list|,
name|struct
name|ng_netflow_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_netflow_copyv9info
parameter_list|(
name|priv_p
parameter_list|,
name|struct
name|ng_netflow_v9info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|timeout_t
name|ng_netflow_expire
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|ng_netflow_flow_add
parameter_list|(
name|priv_p
parameter_list|,
name|fib_export_p
parameter_list|,
name|struct
name|ip
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_netflow_flow6_add
parameter_list|(
name|priv_p
parameter_list|,
name|fib_export_p
parameter_list|,
name|struct
name|ip6_hdr
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|uint8_t
parameter_list|,
name|uint8_t
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_netflow_flow_show
parameter_list|(
name|priv_p
parameter_list|,
name|struct
name|ngnf_show_header
modifier|*
name|req
parameter_list|,
name|struct
name|ngnf_show_header
modifier|*
name|resp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_netflow_v9_cache_init
parameter_list|(
name|priv_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_netflow_v9_cache_flush
parameter_list|(
name|priv_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|item_p
name|get_export9_dgram
parameter_list|(
name|priv_p
parameter_list|,
name|fib_export_p
parameter_list|,
name|struct
name|netflow_v9_packet_opt
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|return_export9_dgram
parameter_list|(
name|priv_p
parameter_list|,
name|fib_export_p
parameter_list|,
name|item_p
parameter_list|,
name|struct
name|netflow_v9_packet_opt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|export9_add
parameter_list|(
name|item_p
parameter_list|,
name|struct
name|netflow_v9_packet_opt
modifier|*
parameter_list|,
name|struct
name|flow_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|export9_send
parameter_list|(
name|priv_p
parameter_list|,
name|fib_export_p
parameter_list|,
name|item_p
parameter_list|,
name|struct
name|netflow_v9_packet_opt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NG_NETFLOW_H_ */
end_comment

end_unit

