begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#) $Header: /tcpdump/master/tcpdump/ospf.h,v 1.16 2004/09/20 14:56:34 hannes Exp $ (LBL) */
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
name|OSPF_TYPE_DD
value|2
end_define

begin_comment
comment|/* Database Description */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LS_REQ
value|3
end_define

begin_comment
comment|/* Link State Request */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LS_UPDATE
value|4
end_define

begin_comment
comment|/* Link State Update */
end_comment

begin_define
define|#
directive|define
name|OSPF_TYPE_LS_ACK
value|5
end_define

begin_comment
comment|/* Link State Ack */
end_comment

begin_comment
comment|/* Options field  *  * +------------------------------------+  * | * | O | DC | EA | N/P | MC | E | T |  * +------------------------------------+  *  */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_T
value|0x01
end_define

begin_comment
comment|/* T bit: TOS support	*/
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_E
value|0x02
end_define

begin_comment
comment|/* E bit: External routes advertised	*/
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_MC
value|0x04
end_define

begin_comment
comment|/* MC bit: Multicast capable */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_NP
value|0x08
end_define

begin_comment
comment|/* N/P bit: NSSA capable */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_EA
value|0x10
end_define

begin_comment
comment|/* EA bit: External Attribute capable */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_DC
value|0x20
end_define

begin_comment
comment|/* DC bit: Demand circuit capable */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_O
value|0x40
end_define

begin_comment
comment|/* O bit: Opaque LSA capable */
end_comment

begin_define
define|#
directive|define
name|OSPF_OPTION_DN
value|0x80
end_define

begin_comment
comment|/* DN bit: Up/Down Bit capable - draft-ietf-ospf-2547-dnbit-04 */
end_comment

begin_comment
comment|/* ospf_authtype	*/
end_comment

begin_define
define|#
directive|define
name|OSPF_AUTH_NONE
value|0
end_define

begin_comment
comment|/* No auth-data */
end_comment

begin_define
define|#
directive|define
name|OSPF_AUTH_SIMPLE
value|1
end_define

begin_comment
comment|/* Simple password */
end_comment

begin_define
define|#
directive|define
name|OSPF_AUTH_MD5
value|2
end_define

begin_comment
comment|/* MD5 authentication */
end_comment

begin_define
define|#
directive|define
name|OSPF_AUTH_MD5_LEN
value|16
end_define

begin_comment
comment|/* length of MD5 authentication */
end_comment

begin_comment
comment|/* db_flags	*/
end_comment

begin_define
define|#
directive|define
name|OSPF_DB_INIT
value|0x04
end_define

begin_comment
comment|/*	*/
end_comment

begin_define
define|#
directive|define
name|OSPF_DB_MORE
value|0x02
end_define

begin_define
define|#
directive|define
name|OSPF_DB_MASTER
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
name|LS_TYPE_SUM_IP
value|3
end_define

begin_comment
comment|/* summary link */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_SUM_ABR
value|4
end_define

begin_comment
comment|/* summary area link */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_ASE
value|5
end_define

begin_comment
comment|/* ASE  */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_GROUP
value|6
end_define

begin_comment
comment|/* Group membership (multicast */
end_comment

begin_comment
comment|/* extensions 23 July 1991) */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_NSSA
value|7
end_define

begin_comment
comment|/* rfc3101 - Not so Stubby Areas */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_OPAQUE_LL
value|9
end_define

begin_comment
comment|/* rfc2370 - Opaque Link Local */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_OPAQUE_AL
value|10
end_define

begin_comment
comment|/* rfc2370 - Opaque Link Local */
end_comment

begin_define
define|#
directive|define
name|LS_TYPE_OPAQUE_DW
value|11
end_define

begin_comment
comment|/* rfc2370 - Opaque Domain Wide */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TYPE_TE
value|1
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TYPE_GRACE
value|3
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TYPE_RI
value|4
end_define

begin_comment
comment|/* draft-ietf-ospf-cap-03 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_TLV_ROUTER
value|1
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_TLV_LINK
value|2
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_TYPE
value|1
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_ID
value|2
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LOCAL_IP
value|3
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_REMOTE_IP
value|4
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_TE_METRIC
value|5
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_MAX_BW
value|6
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_MAX_RES_BW
value|7
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_UNRES_BW
value|8
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_ADMIN_GROUP
value|9
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_LOCAL_REMOTE_ID
value|11
end_define

begin_comment
comment|/* draft-ietf-ccamp-ospf-gmpls-extensions */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_PROTECTION_TYPE
value|14
end_define

begin_comment
comment|/* draft-ietf-ccamp-ospf-gmpls-extensions */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_INTF_SW_CAP_DESCR
value|15
end_define

begin_comment
comment|/* draft-ietf-ccamp-ospf-gmpls-extensions */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_SHARED_RISK_GROUP
value|16
end_define

begin_comment
comment|/* draft-ietf-ccamp-ospf-gmpls-extensions */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_DIFFSERV_TE
value|17
end_define

begin_comment
comment|/* draft-ietf-tewg-diff-te-proto-06 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_TYPE_PTP
value|1
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_TE_LINK_SUBTLV_LINK_TYPE_MA
value|2
end_define

begin_comment
comment|/* rfc3630 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_PERIOD
value|1
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_REASON
value|2
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_INT_ADDRESS
value|3
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_REASON_UNKNOWN
value|0
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_REASON_SW_RESTART
value|1
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_REASON_SW_UPGRADE
value|2
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_GRACE_TLV_REASON_CP_SWITCH
value|3
end_define

begin_comment
comment|/* rfc3623 */
end_comment

begin_define
define|#
directive|define
name|LS_OPAQUE_RI_TLV_CAP
value|1
end_define

begin_comment
comment|/* draft-ietf-ospf-cap-03 */
end_comment

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
name|RLA_TYPE_STUB
value|3
end_define

begin_comment
comment|/* connection to stub network	*/
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
name|RLA_FLAG_W1
value|0x04
end_define

begin_define
define|#
directive|define
name|RLA_FLAG_W2
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
comment|/* asla_tosmetric breakdown	*/
end_comment

begin_define
define|#
directive|define
name|ASLA_FLAG_EXTERNAL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|ASLA_MASK_TOS
value|0x7f000000
end_define

begin_define
define|#
directive|define
name|ASLA_SHIFT_TOS
value|24
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
name|u_int8_t
name|ls_options
decl_stmt|;
name|u_int8_t
name|ls_type
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|lsa_id
decl_stmt|;
struct|struct
block|{
comment|/* opaque LSAs change the LSA-ID field */
name|u_int8_t
name|opaque_type
decl_stmt|;
name|u_int8_t
name|opaque_id
index|[
literal|3
index|]
decl_stmt|;
block|}
name|opaque_field
struct|;
block|}
name|un_lsa_id
union|;
name|struct
name|in_addr
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
name|u_int8_t
name|rla_flags
decl_stmt|;
name|u_int8_t
name|rla_zero
index|[
literal|1
index|]
decl_stmt|;
name|u_int16_t
name|rla_count
decl_stmt|;
struct|struct
name|rlalink
block|{
name|struct
name|in_addr
name|link_id
decl_stmt|;
name|struct
name|in_addr
name|link_data
decl_stmt|;
name|u_int8_t
name|link_type
decl_stmt|;
name|u_int8_t
name|link_toscount
decl_stmt|;
name|u_int16_t
name|link_tos0metric
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
name|struct
name|in_addr
name|nla_mask
decl_stmt|;
name|struct
name|in_addr
name|nla_router
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_nla
struct|;
comment|/* Summary links advertisements */
struct|struct
block|{
name|struct
name|in_addr
name|sla_mask
decl_stmt|;
name|u_int32_t
name|sla_tosmetric
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat	*/
block|}
name|un_sla
struct|;
comment|/* AS external links advertisements */
struct|struct
block|{
name|struct
name|in_addr
name|asla_mask
decl_stmt|;
struct|struct
name|aslametric
block|{
name|u_int32_t
name|asla_tosmetric
decl_stmt|;
name|struct
name|in_addr
name|asla_forward
decl_stmt|;
name|struct
name|in_addr
name|asla_tag
decl_stmt|;
block|}
name|asla_metric
index|[
literal|1
index|]
struct|;
comment|/* may repeat	*/
block|}
name|un_asla
struct|;
comment|/* Multicast group membership */
struct|struct
name|mcla
block|{
name|u_int32_t
name|mcla_vtype
decl_stmt|;
name|struct
name|in_addr
name|mcla_vid
decl_stmt|;
block|}
name|un_mcla
index|[
literal|1
index|]
struct|;
comment|/* Opaque TE LSA */
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat   */
block|}
name|un_te_lsa_tlv
struct|;
comment|/* Opaque Grace LSA */
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat   */
block|}
name|un_grace_tlv
struct|;
comment|/* Opaque Router information LSA */
struct|struct
block|{
name|u_int16_t
name|type
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat   */
block|}
name|un_ri_tlv
struct|;
comment|/* Unknown LSA */
struct|struct
name|unknown
block|{
name|u_int8_t
name|data
index|[
literal|1
index|]
decl_stmt|;
comment|/* may repeat   */
block|}
name|un_unknown
index|[
literal|1
index|]
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
name|ospfhdr
block|{
name|u_int8_t
name|ospf_version
decl_stmt|;
name|u_int8_t
name|ospf_type
decl_stmt|;
name|u_int16_t
name|ospf_len
decl_stmt|;
name|struct
name|in_addr
name|ospf_routerid
decl_stmt|;
name|struct
name|in_addr
name|ospf_areaid
decl_stmt|;
name|u_int16_t
name|ospf_chksum
decl_stmt|;
name|u_int16_t
name|ospf_authtype
decl_stmt|;
name|u_int8_t
name|ospf_authdata
index|[
name|OSPF_AUTH_SIZE
index|]
decl_stmt|;
union|union
block|{
comment|/* Hello packet */
struct|struct
block|{
name|struct
name|in_addr
name|hello_mask
decl_stmt|;
name|u_int16_t
name|hello_helloint
decl_stmt|;
name|u_int8_t
name|hello_options
decl_stmt|;
name|u_int8_t
name|hello_priority
decl_stmt|;
name|u_int32_t
name|hello_deadint
decl_stmt|;
name|struct
name|in_addr
name|hello_dr
decl_stmt|;
name|struct
name|in_addr
name|hello_bdr
decl_stmt|;
name|struct
name|in_addr
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
name|u_int8_t
name|db_zero
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|db_options
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
name|u_int8_t
name|ls_type
index|[
literal|4
index|]
decl_stmt|;
union|union
block|{
name|struct
name|in_addr
name|ls_stateid
decl_stmt|;
struct|struct
block|{
comment|/* opaque LSAs change the LSA-ID field */
name|u_int8_t
name|opaque_type
decl_stmt|;
name|u_int8_t
name|opaque_id
index|[
literal|3
index|]
decl_stmt|;
block|}
name|opaque_field
struct|;
block|}
name|un_ls_stateid
union|;
name|struct
name|in_addr
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
name|ospf_un
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ospf_hello
value|ospf_un.un_hello
end_define

begin_define
define|#
directive|define
name|ospf_db
value|ospf_un.un_db
end_define

begin_define
define|#
directive|define
name|ospf_lsr
value|ospf_un.un_lsr
end_define

begin_define
define|#
directive|define
name|ospf_lsu
value|ospf_un.un_lsu
end_define

begin_define
define|#
directive|define
name|ospf_lsa
value|ospf_un.un_lsa
end_define

end_unit

