begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1994, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/decnet.h,v 1.7 2000/10/03 02:54:55 itojun Exp $ (LBL)  */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|byte
index|[
literal|1
index|]
typedef|;
end_typedef

begin_comment
comment|/* single byte field */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|word
index|[
literal|2
index|]
typedef|;
end_typedef

begin_comment
comment|/* 2 byte field */
end_comment

begin_typedef
typedef|typedef
name|u_int8_t
name|longword
index|[
literal|4
index|]
typedef|;
end_typedef

begin_comment
comment|/* 4 bytes field */
end_comment

begin_comment
comment|/*  * Definitions for DECNET Phase IV protocol headers  */
end_comment

begin_union
union|union
name|etheraddress
block|{
name|u_int8_t
name|dne_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* full ethernet address */
struct|struct
block|{
name|u_int8_t
name|dne_hiord
index|[
literal|4
index|]
decl_stmt|;
comment|/* DECnet HIORD prefix */
name|u_int8_t
name|dne_nodeaddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* DECnet node address */
block|}
name|dne_remote
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|etheraddress
name|etheraddr
typedef|;
end_typedef

begin_comment
comment|/* Ethernet address */
end_comment

begin_define
define|#
directive|define
name|HIORD
value|0x000400aa
end_define

begin_comment
comment|/* high 32-bits of address (swapped) */
end_comment

begin_define
define|#
directive|define
name|AREAMASK
value|0176000
end_define

begin_comment
comment|/* mask for area field */
end_comment

begin_define
define|#
directive|define
name|AREASHIFT
value|10
end_define

begin_comment
comment|/* bit-offset for area field */
end_comment

begin_define
define|#
directive|define
name|NODEMASK
value|01777
end_define

begin_comment
comment|/* mask for node address field */
end_comment

begin_define
define|#
directive|define
name|DN_MAXADDL
value|20
end_define

begin_comment
comment|/* max size of DECnet address */
end_comment

begin_struct
struct|struct
name|dn_naddr
block|{
name|u_int16_t
name|a_len
decl_stmt|;
comment|/* length of address */
name|u_int8_t
name|a_addr
index|[
name|DN_MAXADDL
index|]
decl_stmt|;
comment|/* address as bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Define long and short header formats.  */
end_comment

begin_struct
struct|struct
name|shorthdr
block|{
name|byte
name|sh_flags
decl_stmt|;
comment|/* route flags */
name|word
name|sh_dst
decl_stmt|;
comment|/* destination node address */
name|word
name|sh_src
decl_stmt|;
comment|/* source node address */
name|byte
name|sh_visits
decl_stmt|;
comment|/* visit count */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|longhdr
block|{
name|byte
name|lg_flags
decl_stmt|;
comment|/* route flags */
name|byte
name|lg_darea
decl_stmt|;
comment|/* destination area (reserved) */
name|byte
name|lg_dsarea
decl_stmt|;
comment|/* destination subarea (reserved) */
name|etheraddr
name|lg_dst
decl_stmt|;
comment|/* destination id */
name|byte
name|lg_sarea
decl_stmt|;
comment|/* source area (reserved) */
name|byte
name|lg_ssarea
decl_stmt|;
comment|/* source subarea (reserved) */
name|etheraddr
name|lg_src
decl_stmt|;
comment|/* source id */
name|byte
name|lg_nextl2
decl_stmt|;
comment|/* next level 2 router (reserved) */
name|byte
name|lg_visits
decl_stmt|;
comment|/* visit count */
name|byte
name|lg_service
decl_stmt|;
comment|/* service class (reserved) */
name|byte
name|lg_pt
decl_stmt|;
comment|/* protocol type (reserved) */
block|}
struct|;
end_struct

begin_union
union|union
name|routehdr
block|{
name|struct
name|shorthdr
name|rh_short
decl_stmt|;
comment|/* short route header */
name|struct
name|longhdr
name|rh_long
decl_stmt|;
comment|/* long route header */
block|}
union|;
end_union

begin_comment
comment|/*  * Define the values of various fields in the protocol messages.  *  * 1. Data packet formats.  */
end_comment

begin_define
define|#
directive|define
name|RMF_MASK
value|7
end_define

begin_comment
comment|/* mask for message type */
end_comment

begin_define
define|#
directive|define
name|RMF_SHORT
value|2
end_define

begin_comment
comment|/* short message format */
end_comment

begin_define
define|#
directive|define
name|RMF_LONG
value|6
end_define

begin_comment
comment|/* long message format */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RMF_RQR
end_ifndef

begin_define
define|#
directive|define
name|RMF_RQR
value|010
end_define

begin_comment
comment|/* request return to sender */
end_comment

begin_define
define|#
directive|define
name|RMF_RTS
value|020
end_define

begin_comment
comment|/* returning to sender */
end_comment

begin_define
define|#
directive|define
name|RMF_IE
value|040
end_define

begin_comment
comment|/* intra-ethernet packet */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RMR_RQR */
end_comment

begin_define
define|#
directive|define
name|RMF_FVER
value|0100
end_define

begin_comment
comment|/* future version flag */
end_comment

begin_define
define|#
directive|define
name|RMF_PAD
value|0200
end_define

begin_comment
comment|/* pad field */
end_comment

begin_define
define|#
directive|define
name|RMF_PADMASK
value|0177
end_define

begin_comment
comment|/* pad field mask */
end_comment

begin_define
define|#
directive|define
name|VIS_MASK
value|077
end_define

begin_comment
comment|/* visit field mask */
end_comment

begin_comment
comment|/*  * 2. Control packet formats.  */
end_comment

begin_define
define|#
directive|define
name|RMF_CTLMASK
value|017
end_define

begin_comment
comment|/* mask for message type */
end_comment

begin_define
define|#
directive|define
name|RMF_CTLMSG
value|01
end_define

begin_comment
comment|/* control message indicator */
end_comment

begin_define
define|#
directive|define
name|RMF_INIT
value|01
end_define

begin_comment
comment|/* initialization message */
end_comment

begin_define
define|#
directive|define
name|RMF_VER
value|03
end_define

begin_comment
comment|/* verification message */
end_comment

begin_define
define|#
directive|define
name|RMF_TEST
value|05
end_define

begin_comment
comment|/* hello and test message */
end_comment

begin_define
define|#
directive|define
name|RMF_L1ROUT
value|07
end_define

begin_comment
comment|/* level 1 routing message */
end_comment

begin_define
define|#
directive|define
name|RMF_L2ROUT
value|011
end_define

begin_comment
comment|/* level 2 routing message */
end_comment

begin_define
define|#
directive|define
name|RMF_RHELLO
value|013
end_define

begin_comment
comment|/* router hello message */
end_comment

begin_define
define|#
directive|define
name|RMF_EHELLO
value|015
end_define

begin_comment
comment|/* endnode hello message */
end_comment

begin_define
define|#
directive|define
name|TI_L2ROUT
value|01
end_define

begin_comment
comment|/* level 2 router */
end_comment

begin_define
define|#
directive|define
name|TI_L1ROUT
value|02
end_define

begin_comment
comment|/* level 1 router */
end_comment

begin_define
define|#
directive|define
name|TI_ENDNODE
value|03
end_define

begin_comment
comment|/* endnode */
end_comment

begin_define
define|#
directive|define
name|TI_VERIF
value|04
end_define

begin_comment
comment|/* verification required */
end_comment

begin_define
define|#
directive|define
name|TI_BLOCK
value|010
end_define

begin_comment
comment|/* blocking requested */
end_comment

begin_define
define|#
directive|define
name|VE_VERS
value|2
end_define

begin_comment
comment|/* version number (2) */
end_comment

begin_define
define|#
directive|define
name|VE_ECO
value|0
end_define

begin_comment
comment|/* ECO number */
end_comment

begin_define
define|#
directive|define
name|VE_UECO
value|0
end_define

begin_comment
comment|/* user ECO number (0) */
end_comment

begin_define
define|#
directive|define
name|P3_VERS
value|1
end_define

begin_comment
comment|/* phase III version number (1) */
end_comment

begin_define
define|#
directive|define
name|P3_ECO
value|3
end_define

begin_comment
comment|/* ECO number (3) */
end_comment

begin_define
define|#
directive|define
name|P3_UECO
value|0
end_define

begin_comment
comment|/* user ECO number (0) */
end_comment

begin_define
define|#
directive|define
name|II_L2ROUT
value|01
end_define

begin_comment
comment|/* level 2 router */
end_comment

begin_define
define|#
directive|define
name|II_L1ROUT
value|02
end_define

begin_comment
comment|/* level 1 router */
end_comment

begin_define
define|#
directive|define
name|II_ENDNODE
value|03
end_define

begin_comment
comment|/* endnode */
end_comment

begin_define
define|#
directive|define
name|II_VERIF
value|04
end_define

begin_comment
comment|/* verification required */
end_comment

begin_define
define|#
directive|define
name|II_NOMCAST
value|040
end_define

begin_comment
comment|/* no multicast traffic accepted */
end_comment

begin_define
define|#
directive|define
name|II_BLOCK
value|0100
end_define

begin_comment
comment|/* blocking requested */
end_comment

begin_define
define|#
directive|define
name|II_TYPEMASK
value|03
end_define

begin_comment
comment|/* mask for node type */
end_comment

begin_define
define|#
directive|define
name|TESTDATA
value|0252
end_define

begin_comment
comment|/* test data bytes */
end_comment

begin_define
define|#
directive|define
name|TESTLEN
value|1
end_define

begin_comment
comment|/* length of transmitted test data */
end_comment

begin_comment
comment|/*  * Define control message formats.  */
end_comment

begin_struct
struct|struct
name|initmsgIII
comment|/* phase III initialization message */
block|{
name|byte
name|inIII_flags
decl_stmt|;
comment|/* route flags */
name|word
name|inIII_src
decl_stmt|;
comment|/* source node address */
name|byte
name|inIII_info
decl_stmt|;
comment|/* routing layer information */
name|word
name|inIII_blksize
decl_stmt|;
comment|/* maximum data link block size */
name|byte
name|inIII_vers
decl_stmt|;
comment|/* version number */
name|byte
name|inIII_eco
decl_stmt|;
comment|/* ECO number */
name|byte
name|inIII_ueco
decl_stmt|;
comment|/* user ECO number */
name|byte
name|inIII_rsvd
decl_stmt|;
comment|/* reserved image field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|initmsg
comment|/* initialization message */
block|{
name|byte
name|in_flags
decl_stmt|;
comment|/* route flags */
name|word
name|in_src
decl_stmt|;
comment|/* source node address */
name|byte
name|in_info
decl_stmt|;
comment|/* routing layer information */
name|word
name|in_blksize
decl_stmt|;
comment|/* maximum data link block size */
name|byte
name|in_vers
decl_stmt|;
comment|/* version number */
name|byte
name|in_eco
decl_stmt|;
comment|/* ECO number */
name|byte
name|in_ueco
decl_stmt|;
comment|/* user ECO number */
name|word
name|in_hello
decl_stmt|;
comment|/* hello timer */
name|byte
name|in_rsvd
decl_stmt|;
comment|/* reserved image field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|verifmsg
comment|/* verification message */
block|{
name|byte
name|ve_flags
decl_stmt|;
comment|/* route flags */
name|word
name|ve_src
decl_stmt|;
comment|/* source node address */
name|byte
name|ve_fcnval
decl_stmt|;
comment|/* function value image field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|testmsg
comment|/* hello and test message */
block|{
name|byte
name|te_flags
decl_stmt|;
comment|/* route flags */
name|word
name|te_src
decl_stmt|;
comment|/* source node address */
name|byte
name|te_data
decl_stmt|;
comment|/* test data image field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l1rout
comment|/* level 1 routing message */
block|{
name|byte
name|r1_flags
decl_stmt|;
comment|/* route flags */
name|word
name|r1_src
decl_stmt|;
comment|/* source node address */
name|byte
name|r1_rsvd
decl_stmt|;
comment|/* reserved field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|l2rout
comment|/* level 2 routing message */
block|{
name|byte
name|r2_flags
decl_stmt|;
comment|/* route flags */
name|word
name|r2_src
decl_stmt|;
comment|/* source node address */
name|byte
name|r2_rsvd
decl_stmt|;
comment|/* reserved field */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rhellomsg
comment|/* router hello message */
block|{
name|byte
name|rh_flags
decl_stmt|;
comment|/* route flags */
name|byte
name|rh_vers
decl_stmt|;
comment|/* version number */
name|byte
name|rh_eco
decl_stmt|;
comment|/* ECO number */
name|byte
name|rh_ueco
decl_stmt|;
comment|/* user ECO number */
name|etheraddr
name|rh_src
decl_stmt|;
comment|/* source id */
name|byte
name|rh_info
decl_stmt|;
comment|/* routing layer information */
name|word
name|rh_blksize
decl_stmt|;
comment|/* maximum data link block size */
name|byte
name|rh_priority
decl_stmt|;
comment|/* router's priority */
name|byte
name|rh_area
decl_stmt|;
comment|/* reserved */
name|word
name|rh_hello
decl_stmt|;
comment|/* hello timer */
name|byte
name|rh_mpd
decl_stmt|;
comment|/* reserved */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ehellomsg
comment|/* endnode hello message */
block|{
name|byte
name|eh_flags
decl_stmt|;
comment|/* route flags */
name|byte
name|eh_vers
decl_stmt|;
comment|/* version number */
name|byte
name|eh_eco
decl_stmt|;
comment|/* ECO number */
name|byte
name|eh_ueco
decl_stmt|;
comment|/* user ECO number */
name|etheraddr
name|eh_src
decl_stmt|;
comment|/* source id */
name|byte
name|eh_info
decl_stmt|;
comment|/* routing layer information */
name|word
name|eh_blksize
decl_stmt|;
comment|/* maximum data link block size */
name|byte
name|eh_area
decl_stmt|;
comment|/* area (reserved) */
name|byte
name|eh_seed
index|[
literal|8
index|]
decl_stmt|;
comment|/* verification seed */
name|etheraddr
name|eh_router
decl_stmt|;
comment|/* designated router */
name|word
name|eh_hello
decl_stmt|;
comment|/* hello timer */
name|byte
name|eh_mpd
decl_stmt|;
comment|/* (reserved) */
name|byte
name|eh_data
decl_stmt|;
comment|/* test data image field */
block|}
struct|;
end_struct

begin_union
union|union
name|controlmsg
block|{
name|struct
name|initmsg
name|cm_init
decl_stmt|;
comment|/* initialization message */
name|struct
name|verifmsg
name|cm_ver
decl_stmt|;
comment|/* verification message */
name|struct
name|testmsg
name|cm_test
decl_stmt|;
comment|/* hello and test message */
name|struct
name|l1rout
name|cm_l1rou
decl_stmt|;
comment|/* level 1 routing message */
name|struct
name|l2rout
name|cm_l2rout
decl_stmt|;
comment|/* level 2 routing message */
name|struct
name|rhellomsg
name|cm_rhello
decl_stmt|;
comment|/* router hello message */
name|struct
name|ehellomsg
name|cm_ehello
decl_stmt|;
comment|/* endnode hello message */
block|}
union|;
end_union

begin_comment
comment|/* Macros for decoding routing-info fields */
end_comment

begin_define
define|#
directive|define
name|RI_COST
parameter_list|(
name|x
parameter_list|)
value|((x)&0777)
end_define

begin_define
define|#
directive|define
name|RI_HOPS
parameter_list|(
name|x
parameter_list|)
value|(((x)>>10)&037)
end_define

begin_escape
end_escape

begin_comment
comment|/*  * NSP protocol fields and values.  */
end_comment

begin_define
define|#
directive|define
name|NSP_TYPEMASK
value|014
end_define

begin_comment
comment|/* mask to isolate type code */
end_comment

begin_define
define|#
directive|define
name|NSP_SUBMASK
value|0160
end_define

begin_comment
comment|/* mask to isolate subtype code */
end_comment

begin_define
define|#
directive|define
name|NSP_SUBSHFT
value|4
end_define

begin_comment
comment|/* shift to move subtype code */
end_comment

begin_define
define|#
directive|define
name|MFT_DATA
value|0
end_define

begin_comment
comment|/* data message */
end_comment

begin_define
define|#
directive|define
name|MFT_ACK
value|04
end_define

begin_comment
comment|/* acknowledgement message */
end_comment

begin_define
define|#
directive|define
name|MFT_CTL
value|010
end_define

begin_comment
comment|/* control message */
end_comment

begin_define
define|#
directive|define
name|MFS_ILS
value|020
end_define

begin_comment
comment|/* data or I/LS indicator */
end_comment

begin_define
define|#
directive|define
name|MFS_BOM
value|040
end_define

begin_comment
comment|/* beginning of message (data) */
end_comment

begin_define
define|#
directive|define
name|MFS_MOM
value|0
end_define

begin_comment
comment|/* middle of message (data) */
end_comment

begin_define
define|#
directive|define
name|MFS_EOM
value|0100
end_define

begin_comment
comment|/* end of message (data) */
end_comment

begin_define
define|#
directive|define
name|MFS_INT
value|040
end_define

begin_comment
comment|/* interrupt message */
end_comment

begin_define
define|#
directive|define
name|MFS_DACK
value|0
end_define

begin_comment
comment|/* data acknowledgement */
end_comment

begin_define
define|#
directive|define
name|MFS_IACK
value|020
end_define

begin_comment
comment|/* I/LS acknowledgement */
end_comment

begin_define
define|#
directive|define
name|MFS_CACK
value|040
end_define

begin_comment
comment|/* connect acknowledgement */
end_comment

begin_define
define|#
directive|define
name|MFS_NOP
value|0
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|MFS_CI
value|020
end_define

begin_comment
comment|/* connect initiate */
end_comment

begin_define
define|#
directive|define
name|MFS_CC
value|040
end_define

begin_comment
comment|/* connect confirm */
end_comment

begin_define
define|#
directive|define
name|MFS_DI
value|060
end_define

begin_comment
comment|/* disconnect initiate */
end_comment

begin_define
define|#
directive|define
name|MFS_DC
value|0100
end_define

begin_comment
comment|/* disconnect confirm */
end_comment

begin_define
define|#
directive|define
name|MFS_RCI
value|0140
end_define

begin_comment
comment|/* retransmitted connect initiate */
end_comment

begin_define
define|#
directive|define
name|SGQ_ACK
value|0100000
end_define

begin_comment
comment|/* ack */
end_comment

begin_define
define|#
directive|define
name|SGQ_NAK
value|0110000
end_define

begin_comment
comment|/* negative ack */
end_comment

begin_define
define|#
directive|define
name|SGQ_OACK
value|0120000
end_define

begin_comment
comment|/* other channel ack */
end_comment

begin_define
define|#
directive|define
name|SGQ_ONAK
value|0130000
end_define

begin_comment
comment|/* other channel negative ack */
end_comment

begin_define
define|#
directive|define
name|SGQ_MASK
value|07777
end_define

begin_comment
comment|/* mask to isolate seq # */
end_comment

begin_define
define|#
directive|define
name|SGQ_OTHER
value|020000
end_define

begin_comment
comment|/* other channel qualifier */
end_comment

begin_define
define|#
directive|define
name|SGQ_DELAY
value|010000
end_define

begin_comment
comment|/* ack delay flag */
end_comment

begin_define
define|#
directive|define
name|SGQ_EOM
value|0100000
end_define

begin_comment
comment|/* pseudo flag for end-of-message */
end_comment

begin_define
define|#
directive|define
name|LSM_MASK
value|03
end_define

begin_comment
comment|/* mask for modifier field */
end_comment

begin_define
define|#
directive|define
name|LSM_NOCHANGE
value|0
end_define

begin_comment
comment|/* no change */
end_comment

begin_define
define|#
directive|define
name|LSM_DONOTSEND
value|1
end_define

begin_comment
comment|/* do not send data */
end_comment

begin_define
define|#
directive|define
name|LSM_SEND
value|2
end_define

begin_comment
comment|/* send data */
end_comment

begin_define
define|#
directive|define
name|LSI_MASK
value|014
end_define

begin_comment
comment|/* mask for interpretation field */
end_comment

begin_define
define|#
directive|define
name|LSI_DATA
value|0
end_define

begin_comment
comment|/* data segment or message count */
end_comment

begin_define
define|#
directive|define
name|LSI_INTR
value|4
end_define

begin_comment
comment|/* interrupt request count */
end_comment

begin_define
define|#
directive|define
name|LSI_INTM
value|0377
end_define

begin_comment
comment|/* funny marker for int. message */
end_comment

begin_define
define|#
directive|define
name|COS_MASK
value|014
end_define

begin_comment
comment|/* mask for flow control field */
end_comment

begin_define
define|#
directive|define
name|COS_NONE
value|0
end_define

begin_comment
comment|/* no flow control */
end_comment

begin_define
define|#
directive|define
name|COS_SEGMENT
value|04
end_define

begin_comment
comment|/* segment flow control */
end_comment

begin_define
define|#
directive|define
name|COS_MESSAGE
value|010
end_define

begin_comment
comment|/* message flow control */
end_comment

begin_define
define|#
directive|define
name|COS_CRYPTSER
value|020
end_define

begin_comment
comment|/* cryptographic services requested */
end_comment

begin_define
define|#
directive|define
name|COS_DEFAULT
value|1
end_define

begin_comment
comment|/* default value for field */
end_comment

begin_define
define|#
directive|define
name|COI_MASK
value|3
end_define

begin_comment
comment|/* mask for version field */
end_comment

begin_define
define|#
directive|define
name|COI_32
value|0
end_define

begin_comment
comment|/* version 3.2 */
end_comment

begin_define
define|#
directive|define
name|COI_31
value|1
end_define

begin_comment
comment|/* version 3.1 */
end_comment

begin_define
define|#
directive|define
name|COI_40
value|2
end_define

begin_comment
comment|/* version 4.0 */
end_comment

begin_define
define|#
directive|define
name|COI_41
value|3
end_define

begin_comment
comment|/* version 4.1 */
end_comment

begin_define
define|#
directive|define
name|MNU_MASK
value|140
end_define

begin_comment
comment|/* mask for session control version */
end_comment

begin_define
define|#
directive|define
name|MNU_10
value|000
end_define

begin_comment
comment|/* session V1.0 */
end_comment

begin_define
define|#
directive|define
name|MNU_20
value|040
end_define

begin_comment
comment|/* session V2.0 */
end_comment

begin_define
define|#
directive|define
name|MNU_ACCESS
value|1
end_define

begin_comment
comment|/* access control present */
end_comment

begin_define
define|#
directive|define
name|MNU_USRDATA
value|2
end_define

begin_comment
comment|/* user data field present */
end_comment

begin_define
define|#
directive|define
name|MNU_INVKPROXY
value|4
end_define

begin_comment
comment|/* invoke proxy field present */
end_comment

begin_define
define|#
directive|define
name|MNU_UICPROXY
value|8
end_define

begin_comment
comment|/* use uic-based proxy */
end_comment

begin_define
define|#
directive|define
name|DC_NORESOURCES
value|1
end_define

begin_comment
comment|/* no resource reason code */
end_comment

begin_define
define|#
directive|define
name|DC_NOLINK
value|41
end_define

begin_comment
comment|/* no link terminate reason code */
end_comment

begin_define
define|#
directive|define
name|DC_COMPLETE
value|42
end_define

begin_comment
comment|/* disconnect complete reason code */
end_comment

begin_define
define|#
directive|define
name|DI_NOERROR
value|0
end_define

begin_comment
comment|/* user disconnect */
end_comment

begin_define
define|#
directive|define
name|DI_SHUT
value|3
end_define

begin_comment
comment|/* node is shutting down */
end_comment

begin_define
define|#
directive|define
name|DI_NOUSER
value|4
end_define

begin_comment
comment|/* destination end user does not exist */
end_comment

begin_define
define|#
directive|define
name|DI_INVDEST
value|5
end_define

begin_comment
comment|/* invalid end user destination */
end_comment

begin_define
define|#
directive|define
name|DI_REMRESRC
value|6
end_define

begin_comment
comment|/* insufficient remote resources */
end_comment

begin_define
define|#
directive|define
name|DI_TPA
value|8
end_define

begin_comment
comment|/* third party abort */
end_comment

begin_define
define|#
directive|define
name|DI_PROTOCOL
value|7
end_define

begin_comment
comment|/* protocol error discovered */
end_comment

begin_define
define|#
directive|define
name|DI_ABORT
value|9
end_define

begin_comment
comment|/* user abort */
end_comment

begin_define
define|#
directive|define
name|DI_LOCALRESRC
value|32
end_define

begin_comment
comment|/* insufficient local resources */
end_comment

begin_define
define|#
directive|define
name|DI_REMUSERRESRC
value|33
end_define

begin_comment
comment|/* insufficient remote user resources */
end_comment

begin_define
define|#
directive|define
name|DI_BADACCESS
value|34
end_define

begin_comment
comment|/* bad access control information */
end_comment

begin_define
define|#
directive|define
name|DI_BADACCNT
value|36
end_define

begin_comment
comment|/* bad ACCOUNT information */
end_comment

begin_define
define|#
directive|define
name|DI_CONNECTABORT
value|38
end_define

begin_comment
comment|/* connect request cancelled */
end_comment

begin_define
define|#
directive|define
name|DI_TIMEDOUT
value|38
end_define

begin_comment
comment|/* remote node or user crashed */
end_comment

begin_define
define|#
directive|define
name|DI_UNREACHABLE
value|39
end_define

begin_comment
comment|/* local timers expired due to ... */
end_comment

begin_define
define|#
directive|define
name|DI_BADIMAGE
value|43
end_define

begin_comment
comment|/* bad image data in connect */
end_comment

begin_define
define|#
directive|define
name|DI_SERVMISMATCH
value|54
end_define

begin_comment
comment|/* cryptographic service mismatch */
end_comment

begin_define
define|#
directive|define
name|UC_OBJREJECT
value|0
end_define

begin_comment
comment|/* object rejected connect */
end_comment

begin_define
define|#
directive|define
name|UC_USERDISCONNECT
value|0
end_define

begin_comment
comment|/* user disconnect */
end_comment

begin_define
define|#
directive|define
name|UC_RESOURCES
value|1
end_define

begin_comment
comment|/* insufficient resources (local or remote) */
end_comment

begin_define
define|#
directive|define
name|UC_NOSUCHNODE
value|2
end_define

begin_comment
comment|/* unrecognized node name */
end_comment

begin_define
define|#
directive|define
name|UC_REMOTESHUT
value|3
end_define

begin_comment
comment|/* remote node shutting down */
end_comment

begin_define
define|#
directive|define
name|UC_NOSUCHOBJ
value|4
end_define

begin_comment
comment|/* unrecognized object */
end_comment

begin_define
define|#
directive|define
name|UC_INVOBJFORMAT
value|5
end_define

begin_comment
comment|/* invalid object name format */
end_comment

begin_define
define|#
directive|define
name|UC_OBJTOOBUSY
value|6
end_define

begin_comment
comment|/* object too busy */
end_comment

begin_define
define|#
directive|define
name|UC_NETWORKABORT
value|8
end_define

begin_comment
comment|/* network abort */
end_comment

begin_define
define|#
directive|define
name|UC_USERABORT
value|9
end_define

begin_comment
comment|/* user abort */
end_comment

begin_define
define|#
directive|define
name|UC_INVNODEFORMAT
value|10
end_define

begin_comment
comment|/* invalid node name format */
end_comment

begin_define
define|#
directive|define
name|UC_LOCALSHUT
value|11
end_define

begin_comment
comment|/* local node shutting down */
end_comment

begin_define
define|#
directive|define
name|UC_ACCESSREJECT
value|34
end_define

begin_comment
comment|/* invalid access control information */
end_comment

begin_define
define|#
directive|define
name|UC_NORESPONSE
value|38
end_define

begin_comment
comment|/* no response from object */
end_comment

begin_define
define|#
directive|define
name|UC_UNREACHABLE
value|39
end_define

begin_comment
comment|/* node unreachable */
end_comment

begin_comment
comment|/*  * NSP message formats.  */
end_comment

begin_struct
struct|struct
name|nsphdr
comment|/* general nsp header */
block|{
name|byte
name|nh_flags
decl_stmt|;
comment|/* message flags */
name|word
name|nh_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|nh_src
decl_stmt|;
comment|/* source link address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|seghdr
comment|/* data segment header */
block|{
name|byte
name|sh_flags
decl_stmt|;
comment|/* message flags */
name|word
name|sh_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|sh_src
decl_stmt|;
comment|/* source link address */
name|word
name|sh_seq
index|[
literal|3
index|]
decl_stmt|;
comment|/* sequence numbers */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|minseghdr
comment|/* minimum data segment header */
block|{
name|byte
name|ms_flags
decl_stmt|;
comment|/* message flags */
name|word
name|ms_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|ms_src
decl_stmt|;
comment|/* source link address */
name|word
name|ms_seq
decl_stmt|;
comment|/* sequence number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|lsmsg
comment|/* link service message (after hdr) */
block|{
name|byte
name|ls_lsflags
decl_stmt|;
comment|/* link service flags */
name|byte
name|ls_fcval
decl_stmt|;
comment|/* flow control value */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ackmsg
comment|/* acknowledgement message */
block|{
name|byte
name|ak_flags
decl_stmt|;
comment|/* message flags */
name|word
name|ak_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|ak_src
decl_stmt|;
comment|/* source link address */
name|word
name|ak_acknum
index|[
literal|2
index|]
decl_stmt|;
comment|/* acknowledgement numbers */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|minackmsg
comment|/* minimum acknowledgement message */
block|{
name|byte
name|mk_flags
decl_stmt|;
comment|/* message flags */
name|word
name|mk_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|mk_src
decl_stmt|;
comment|/* source link address */
name|word
name|mk_acknum
decl_stmt|;
comment|/* acknowledgement number */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ciackmsg
comment|/* connect acknowledgement message */
block|{
name|byte
name|ck_flags
decl_stmt|;
comment|/* message flags */
name|word
name|ck_dst
decl_stmt|;
comment|/* destination link address */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cimsg
comment|/* connect initiate message */
block|{
name|byte
name|ci_flags
decl_stmt|;
comment|/* message flags */
name|word
name|ci_dst
decl_stmt|;
comment|/* destination link address (0) */
name|word
name|ci_src
decl_stmt|;
comment|/* source link address */
name|byte
name|ci_services
decl_stmt|;
comment|/* requested services */
name|byte
name|ci_info
decl_stmt|;
comment|/* information */
name|word
name|ci_segsize
decl_stmt|;
comment|/* maximum segment size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccmsg
comment|/* connect confirm message */
block|{
name|byte
name|cc_flags
decl_stmt|;
comment|/* message flags */
name|word
name|cc_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|cc_src
decl_stmt|;
comment|/* source link address */
name|byte
name|cc_services
decl_stmt|;
comment|/* requested services */
name|byte
name|cc_info
decl_stmt|;
comment|/* information */
name|word
name|cc_segsize
decl_stmt|;
comment|/* maximum segment size */
name|byte
name|cc_optlen
decl_stmt|;
comment|/* optional data length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cnmsg
comment|/* generic connect message */
block|{
name|byte
name|cn_flags
decl_stmt|;
comment|/* message flags */
name|word
name|cn_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|cn_src
decl_stmt|;
comment|/* source link address */
name|byte
name|cn_services
decl_stmt|;
comment|/* requested services */
name|byte
name|cn_info
decl_stmt|;
comment|/* information */
name|word
name|cn_segsize
decl_stmt|;
comment|/* maximum segment size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dimsg
comment|/* disconnect initiate message */
block|{
name|byte
name|di_flags
decl_stmt|;
comment|/* message flags */
name|word
name|di_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|di_src
decl_stmt|;
comment|/* source link address */
name|word
name|di_reason
decl_stmt|;
comment|/* reason code */
name|byte
name|di_optlen
decl_stmt|;
comment|/* optional data length */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dcmsg
comment|/* disconnect confirm message */
block|{
name|byte
name|dc_flags
decl_stmt|;
comment|/* message flags */
name|word
name|dc_dst
decl_stmt|;
comment|/* destination link address */
name|word
name|dc_src
decl_stmt|;
comment|/* source link address */
name|word
name|dc_reason
decl_stmt|;
comment|/* reason code */
block|}
struct|;
end_struct

end_unit

