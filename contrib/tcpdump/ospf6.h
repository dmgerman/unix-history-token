begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/ospf6.h,v 1.3 2000/12/17 23:07:50 guy Exp $ (LBL) */
end_comment

begin_comment
comment|/*  * Copyright (c) 1991, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * OSPF support contributed by Jeffrey Honig (jch@mitchell.cit.cornell.edu)  */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_UMD
value|0
end_define

begin_comment
comment|/* UMd's special monitoring packets */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_HELLO
value|1
end_define

begin_comment
comment|/* Hello */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_DB
value|2
end_define

begin_comment
comment|/* Database Description */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LSR
value|3
end_define

begin_comment
comment|/* Link State Request */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LSU
value|4
end_define

begin_comment
comment|/* Link State Update */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LSA
value|5
end_define

begin_comment
comment|/* Link State Ack */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_MAX
value|6
end_define

begin_comment
comment|/* Options *_options	*/
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_V6
value|0x01
end_define

begin_comment
comment|/* V6 bit: A bit for peeping tom */
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_E
value|0x02
end_define

begin_comment
comment|/* E bit: External routes advertised	*/
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_MC
value|0x04
end_define

begin_comment
comment|/* MC bit: Multicast capable */
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_N
value|0x08
end_define

begin_comment
comment|/* N bit: For type-7 LSA */
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_R
value|0x10
end_define

begin_comment
comment|/* R bit: Router bit */
end_comment

begin_define
define|#
directive|define
name|OSPF6_OPTION_DC
value|0x20
end_define

begin_comment
comment|/* DC bit: Demand circuits */
end_comment

begin_comment
comment|/* db_flags	*/
end_comment

begin_define
define|#
directive|define
name|OSPF6_DB_INIT
value|0x04
end_define

begin_comment
comment|/*	*/
end_comment

begin_define
define|#
directive|define
name|OSPF6_DB_MORE
value|0x02
end_define

begin_define
define|#
directive|define
name|OSPF6_DB_MASTER
value|0x01
end_define

begin_comment
comment|/* ls_type	*/
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_ROUTER
value|1
end_define

begin_comment
comment|/* router link */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_NETWORK
value|2
end_define

begin_comment
comment|/* network link */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_INTER_AP
value|3
end_define

begin_comment
comment|/* Inter-Area-Prefix */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_INTER_AR
value|4
end_define

begin_comment
comment|/* Inter-Area-Router */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_ASE
value|5
end_define

begin_comment
comment|/* ASE */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_GROUP
value|6
end_define

begin_comment
comment|/* Group membership */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_TYPE7
value|7
end_define

begin_comment
comment|/* Type 7 LSA */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_LINK
value|8
end_define

begin_comment
comment|/* Link LSA */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_INTRA_AP
value|9
end_define

begin_comment
comment|/* Intra-Area-Prefix */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_MAX
value|10
end_define

begin_define
define|#
directive|define
name|LS_TYPE_MASK
value|0x1fff
end_define

begin_define
define|#
directive|define
name|LS_SCOPE_LINKLOCAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|LS_SCOPE_AREA
value|0x2000
end_define

begin_define
define|#
directive|define
name|LS_SCOPE_AS
value|0x4000
end_define

begin_define
define|#
directive|define
name|LS_SCOPE_MASK
value|0x6000
end_define

begin_comment
comment|/*************************************************  *  * is the above a bug in the documentation?  *  *************************************************/
end_comment

begin_comment
comment|/* rla_link.link_type	*/
end_comment

begin_define
define|#
directive|define
name|RLA_TYPE_ROUTER
value|1
end_define

begin_comment
comment|/* point-to-point to another router	*/
end_comment

begin_define
define|#
directive|define
name|RLA_TYPE_TRANSIT
value|2
end_define

begin_comment
comment|/* connection to transit network	*/
end_comment

begin_define
define|#
directive|define
name|RLA_TYPE_VIRTUAL
value|4
end_define

begin_comment
comment|/* virtual link			*/
end_comment

begin_comment
comment|/* rla_flags	*/
end_comment

begin_define
define|#
directive|define
name|RLA_FLAG_B
value|0x01
end_define

begin_define
define|#
directive|define
name|RLA_FLAG_E
value|0x02
end_define

begin_define
define|#
directive|define
name|RLA_FLAG_V
value|0x04
end_define

begin_define
define|#
directive|define
name|RLA_FLAG_W
value|0x08
end_define

begin_comment
comment|/* sla_tosmetric breakdown	*/
end_comment

begin_define
define|#
directive|define
name|SLA_MASK_TOS
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|SLA_MASK_METRIC
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|SLA_SHIFT_TOS
value|24
end_define

begin_comment
comment|/* asla_metric */
end_comment

begin_define
define|#
directive|define
name|ASLA_FLAG_EXTERNAL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|ASLA_FLAG_FWDADDR
value|0x02000000
end_define

begin_define
define|#
directive|define
name|ASLA_FLAG_ROUTETAG
value|0x01000000
end_define

begin_define
define|#
directive|define
name|ASLA_MASK_METRIC
value|0x00ffffff
end_define

begin_comment
comment|/* multicast vertex type */
end_comment

begin_define
define|#
directive|define
name|MCLA_VERTEX_ROUTER
value|1
end_define

begin_define
define|#
directive|define
name|MCLA_VERTEX_NETWORK
value|2
end_define

begin_typedef
typedef|typedef
name|u_int32_t
name|rtrid_t
typedef|;
end_typedef

begin_comment
comment|/* link state advertisement header */
end_comment

begin_struct
struct|struct
name|lsa_hdr
block|{
name|u_int16_t
name|ls_age
decl_stmt|;
name|u_int16_t
name|ls_type
decl_stmt|;
name|rtrid_t
name|ls_stateid
decl_stmt|;
name|rtrid_t
name|ls_router
decl_stmt|;
name|u_int32_t
name|ls_seq
decl_stmt|;
name|u_int16_t
name|ls_chksum
decl_stmt|;
name|u_int16_t
name|ls_length
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lsa_prefix
block|{
name|u_int8_t
name|lsa_p_len
decl_stmt|;
name|u_int8_t
name|lsa_p_opt
decl_stmt|;
name|u_int16_t
name|lsa_p_mbz
decl_stmt|;
name|u_int8_t
name|lsa_p_prefix
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* link state advertisement */
end_comment

begin_struct
struct|struct
name|lsa
block|{
name|struct
name|lsa_hdr
name|ls_hdr
decl_stmt|;
comment|/* Link state types */
union|union
block|{
comment|/* Router links advertisements */
struct|struct
block|{
union|union
block|{
name|u_int8_t
name|flg
decl_stmt|;
name|u_int32_t
name|opt
decl_stmt|;
block|}
name|rla_flgandopt
union|;
define|#
directive|define
name|rla_flags
value|rla_flgandopt.flg
define|#
directive|define
name|rla_options
value|rla_flgandopt.opt
struct|struct
name|rlalink
block|{
name|u_int8_t
name|link_type
decl_stmt|;
name|u_int8_t
name|link_zero
index|[
literal|1
index|]
decl_stmt|;
name|u_int16_t
name|link_metric
decl_stmt|;
name|u_int32_t
name|link_ifid
decl_stmt|;
name|u_int32_t
name|link_nifid
decl_stmt|;
name|rtrid_t
name|link_nrtid
decl_stmt|;
block|}
name|rla_link
index|[
literal|1
index|]
struct|;
comment|/* may repeat	*/
block|}
name|un_rla
struct|;
comment|/* Network links advertisements */
struct|struct
block|{
name|u_int32_t
name|nla_options
decl_stmt|;
name|rtrid_t
name|nla_router
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_nla
struct|;
comment|/* Inter Area Prefix LSA */
struct|struct
block|{
name|u_int32_t
name|inter_ap_metric
decl_stmt|;
name|struct
name|lsa_prefix
name|inter_ap_prefix
index|[
literal|1
index|]
decl_stmt|;
block|}
name|un_inter_ap
struct|;
comment|/* AS external links advertisements */
struct|struct
block|{
name|u_int32_t
name|asla_metric
decl_stmt|;
name|struct
name|lsa_prefix
name|asla_prefix
index|[
literal|1
index|]
decl_stmt|;
comment|/* some optional fields follow */
block|}
name|un_asla
struct|;
if|#
directive|if
literal|0
comment|/* Summary links advertisements */
block|struct { 	    struct in_addr sla_mask; 	    u_int32_t sla_tosmetric[1];
comment|/* may repeat	*/
block|} un_sla;
comment|/* Multicast group membership */
block|struct mcla { 	    u_int32_t mcla_vtype; 	    struct in_addr mcla_vid; 	} un_mcla[1];
endif|#
directive|endif
comment|/* Type 7 LSA */
comment|/* Link LSA */
struct|struct
name|llsa
block|{
union|union
block|{
name|u_int8_t
name|pri
decl_stmt|;
name|u_int32_t
name|opt
decl_stmt|;
block|}
name|llsa_priandopt
union|;
define|#
directive|define
name|llsa_priority
value|llsa_priandopt.pri
define|#
directive|define
name|llsa_options
value|llsa_priandopt.opt
name|struct
name|in6_addr
name|llsa_lladdr
decl_stmt|;
name|u_int32_t
name|llsa_nprefix
decl_stmt|;
name|struct
name|lsa_prefix
name|llsa_prefix
index|[
literal|1
index|]
decl_stmt|;
block|}
name|un_llsa
struct|;
comment|/* Intra-Area-Prefix */
struct|struct
block|{
name|u_int16_t
name|intra_ap_nprefix
decl_stmt|;
name|u_int16_t
name|intra_ap_lstype
decl_stmt|;
name|rtrid_t
name|intra_ap_lsid
decl_stmt|;
name|rtrid_t
name|intra_ap_rtid
decl_stmt|;
name|struct
name|lsa_prefix
name|intra_ap_prefix
index|[
literal|1
index|]
decl_stmt|;
block|}
name|un_intra_ap
struct|;
block|}
name|lsa_un
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * TOS metric struct (will be 0 or more in router links update)  */
end_comment

begin_struct
struct|struct
name|tos_metric
block|{
name|u_int8_t
name|tos_type
decl_stmt|;
name|u_int8_t
name|tos_zero
decl_stmt|;
name|u_int16_t
name|tos_metric
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OSPF_AUTH_SIZE
value|8
end_define

begin_comment
comment|/*  * the main header  */
end_comment

begin_struct
struct|struct
name|ospf6hdr
block|{
name|u_int8_t
name|ospf6_version
decl_stmt|;
name|u_int8_t
name|ospf6_type
decl_stmt|;
name|u_int16_t
name|ospf6_len
decl_stmt|;
name|rtrid_t
name|ospf6_routerid
decl_stmt|;
name|rtrid_t
name|ospf6_areaid
decl_stmt|;
name|u_int16_t
name|ospf6_chksum
decl_stmt|;
name|u_int8_t
name|ospf6_instanceid
decl_stmt|;
name|u_int8_t
name|ospf6_rsvd
decl_stmt|;
union|union
block|{
comment|/* Hello packet */
struct|struct
block|{
name|u_int32_t
name|hello_ifid
decl_stmt|;
union|union
block|{
name|u_int8_t
name|pri
decl_stmt|;
name|u_int32_t
name|opt
decl_stmt|;
block|}
name|hello_priandopt
union|;
define|#
directive|define
name|hello_priority
value|hello_priandopt.pri
define|#
directive|define
name|hello_options
value|hello_priandopt.opt
name|u_int16_t
name|hello_helloint
decl_stmt|;
name|u_int16_t
name|hello_deadint
decl_stmt|;
name|rtrid_t
name|hello_dr
decl_stmt|;
name|rtrid_t
name|hello_bdr
decl_stmt|;
name|rtrid_t
name|hello_neighbor
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_hello
struct|;
comment|/* Database Description packet */
struct|struct
block|{
name|u_int32_t
name|db_options
decl_stmt|;
name|u_int16_t
name|db_mtu
decl_stmt|;
name|u_int8_t
name|db_mbz
decl_stmt|;
name|u_int8_t
name|db_flags
decl_stmt|;
name|u_int32_t
name|db_seq
decl_stmt|;
name|struct
name|lsa_hdr
name|db_lshdr
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_db
struct|;
comment|/* Link State Request */
struct|struct
name|lsr
block|{
name|u_int16_t
name|ls_mbz
decl_stmt|;
name|u_int16_t
name|ls_type
decl_stmt|;
name|rtrid_t
name|ls_stateid
decl_stmt|;
name|rtrid_t
name|ls_router
decl_stmt|;
block|}
name|un_lsr
index|[
literal|1
index|]
struct|;
comment|/* may repeat	*/
comment|/* Link State Update */
struct|struct
block|{
name|u_int32_t
name|lsu_count
decl_stmt|;
name|struct
name|lsa
name|lsu_lsa
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_lsu
struct|;
comment|/* Link State Acknowledgement */
struct|struct
block|{
name|struct
name|lsa_hdr
name|lsa_lshdr
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_lsa
struct|;
block|}
name|ospf6_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ospf6_hello
value|ospf6_un.un_hello
end_define

begin_define
define|#
directive|define
name|ospf6_db
value|ospf6_un.un_db
end_define

begin_define
define|#
directive|define
name|ospf6_lsr
value|ospf6_un.un_lsr
end_define

begin_define
define|#
directive|define
name|ospf6_lsu
value|ospf6_un.un_lsu
end_define

begin_define
define|#
directive|define
name|ospf6_lsa
value|ospf6_un.un_lsa
end_define

end_unit

