begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_define
define|#
directive|define
name|NETDISSECT_REWORKED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<tcpdump-stdinc.h>
end_include

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtentry
struct_decl|;
end_struct_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETDNET_DNETDB_H
end_ifdef

begin_include
include|#
directive|include
file|<netdnet/dnetdb.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_include
include|#
directive|include
file|"interface.h"
end_include

begin_include
include|#
directive|include
file|"addrtoname.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|char
name|tstr
index|[]
init|=
literal|"[|decnet]"
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|WIN32
end_ifndef

begin_typedef
typedef|typedef
name|uint8_t
name|byte
index|[
literal|1
index|]
typedef|;
end_typedef

begin_comment
comment|/* single byte field */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * the keyword 'byte' generates conflicts in Windows  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Byte
index|[
literal|1
index|]
typedef|;
end_typedef

begin_comment
comment|/* single byte field */
end_comment

begin_define
define|#
directive|define
name|byte
value|Byte
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
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
name|uint8_t
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
name|uint8_t
name|dne_addr
index|[
literal|6
index|]
decl_stmt|;
comment|/* full ethernet address */
struct|struct
block|{
name|uint8_t
name|dne_hiord
index|[
literal|4
index|]
decl_stmt|;
comment|/* DECnet HIORD prefix */
name|uint8_t
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
name|uint16_t
name|a_len
decl_stmt|;
comment|/* length of address */
name|uint8_t
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

begin_comment
comment|/* Forwards */
end_comment

begin_function_decl
specifier|static
name|int
name|print_decnet_ctlmsg
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|union
name|routehdr
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_t_info
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|print_l1_routes
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|print_l2_routes
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_i_info
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|print_elist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|print_nsp
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|print_reason
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
end_ifdef

begin_function_decl
specifier|static
name|void
name|pdata
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_NETDNET_DNETDB_H_DNET_HTOA
end_ifndef

begin_function_decl
specifier|extern
name|char
modifier|*
name|dnet_htoa
parameter_list|(
name|struct
name|dn_naddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|decnet_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|ap
parameter_list|,
specifier|register
name|u_int
name|length
parameter_list|,
specifier|register
name|u_int
name|caplen
parameter_list|)
block|{
specifier|register
specifier|const
name|union
name|routehdr
modifier|*
name|rhp
decl_stmt|;
specifier|register
name|int
name|mflags
decl_stmt|;
name|int
name|dst
decl_stmt|,
name|src
decl_stmt|,
name|hops
decl_stmt|;
name|u_int
name|nsplen
decl_stmt|,
name|pktlen
decl_stmt|;
specifier|const
name|u_char
modifier|*
name|nspp
decl_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|shorthdr
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ND_TCHECK2
argument_list|(
operator|*
name|ap
argument_list|,
sizeof|sizeof
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
name|pktlen
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|pktlen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|shorthdr
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|pktlen
operator|>
name|length
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|length
operator|=
name|pktlen
expr_stmt|;
name|rhp
operator|=
operator|(
specifier|const
expr|union
name|routehdr
operator|*
operator|)
operator|&
operator|(
name|ap
index|[
sizeof|sizeof
argument_list|(
name|short
argument_list|)
index|]
operator|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_flags
argument_list|)
expr_stmt|;
name|mflags
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_flags
argument_list|)
expr_stmt|;
if|if
condition|(
name|mflags
operator|&
name|RMF_PAD
condition|)
block|{
comment|/* pad bytes of some sort in front of message */
name|u_int
name|padlen
init|=
name|mflags
operator|&
name|RMF_PADMASK
decl_stmt|;
if|if
condition|(
name|ndo
operator|->
name|ndo_vflag
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[pad:%d] "
operator|,
name|padlen
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
name|padlen
operator|+
literal|2
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ND_TCHECK2
argument_list|(
name|ap
index|[
sizeof|sizeof
argument_list|(
name|short
argument_list|)
index|]
argument_list|,
name|padlen
argument_list|)
expr_stmt|;
name|ap
operator|+=
name|padlen
expr_stmt|;
name|length
operator|-=
name|padlen
expr_stmt|;
name|caplen
operator|-=
name|padlen
expr_stmt|;
name|rhp
operator|=
operator|(
specifier|const
expr|union
name|routehdr
operator|*
operator|)
operator|&
operator|(
name|ap
index|[
sizeof|sizeof
argument_list|(
name|short
argument_list|)
index|]
operator|)
expr_stmt|;
name|mflags
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_flags
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|mflags
operator|&
name|RMF_FVER
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"future-version-decnet"
operator|)
argument_list|)
expr_stmt|;
name|ND_DEFAULTPRINT
argument_list|(
name|ap
argument_list|,
name|min
argument_list|(
name|length
argument_list|,
name|caplen
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
comment|/* is it a control message? */
if|if
condition|(
name|mflags
operator|&
name|RMF_CTLMSG
condition|)
block|{
if|if
condition|(
operator|!
name|print_decnet_ctlmsg
argument_list|(
name|ndo
argument_list|,
name|rhp
argument_list|,
name|length
argument_list|,
name|caplen
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
return|return;
block|}
switch|switch
condition|(
name|mflags
operator|&
name|RMF_MASK
condition|)
block|{
case|case
name|RMF_LONG
case|:
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|longhdr
argument_list|)
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ND_TCHECK
argument_list|(
name|rhp
operator|->
name|rh_long
argument_list|)
expr_stmt|;
name|dst
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rhp
operator|->
name|rh_long
operator|.
name|lg_dst
operator|.
name|dne_remote
operator|.
name|dne_nodeaddr
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rhp
operator|->
name|rh_long
operator|.
name|lg_src
operator|.
name|dne_remote
operator|.
name|dne_nodeaddr
argument_list|)
expr_stmt|;
name|hops
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|rhp
operator|->
name|rh_long
operator|.
name|lg_visits
argument_list|)
expr_stmt|;
name|nspp
operator|=
operator|&
operator|(
name|ap
index|[
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|longhdr
argument_list|)
index|]
operator|)
expr_stmt|;
name|nsplen
operator|=
name|length
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|longhdr
argument_list|)
expr_stmt|;
break|break;
case|case
name|RMF_SHORT
case|:
name|ND_TCHECK
argument_list|(
name|rhp
operator|->
name|rh_short
argument_list|)
expr_stmt|;
name|dst
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_dst
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_src
argument_list|)
expr_stmt|;
name|hops
operator|=
operator|(
name|EXTRACT_LE_8BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_visits
argument_list|)
operator|&
name|VIS_MASK
operator|)
operator|+
literal|1
expr_stmt|;
name|nspp
operator|=
operator|&
operator|(
name|ap
index|[
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|shorthdr
argument_list|)
index|]
operator|)
expr_stmt|;
name|nsplen
operator|=
name|length
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|shorthdr
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"unknown message flags under mask"
operator|)
argument_list|)
expr_stmt|;
name|ND_DEFAULTPRINT
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|ap
argument_list|,
name|min
argument_list|(
name|length
argument_list|,
name|caplen
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s> %s %d "
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|dst
argument_list|)
operator|,
name|pktlen
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|ndo
operator|->
name|ndo_vflag
condition|)
block|{
if|if
condition|(
name|mflags
operator|&
name|RMF_RQR
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RQR "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|mflags
operator|&
name|RMF_RTS
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"RTS "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|mflags
operator|&
name|RMF_IE
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"IE "
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%d hops "
operator|,
name|hops
operator|)
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|print_nsp
argument_list|(
name|ndo
argument_list|,
name|nspp
argument_list|,
name|nsplen
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s"
operator|,
name|tstr
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|int
name|print_decnet_ctlmsg
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
specifier|const
name|union
name|routehdr
modifier|*
name|rhp
parameter_list|,
name|u_int
name|length
parameter_list|,
name|u_int
name|caplen
parameter_list|)
block|{
name|int
name|mflags
init|=
name|EXTRACT_LE_8BITS
argument_list|(
name|rhp
operator|->
name|rh_short
operator|.
name|sh_flags
argument_list|)
decl_stmt|;
specifier|register
name|union
name|controlmsg
modifier|*
name|cmp
init|=
operator|(
expr|union
name|controlmsg
operator|*
operator|)
name|rhp
decl_stmt|;
name|int
name|src
decl_stmt|,
name|dst
decl_stmt|,
name|info
decl_stmt|,
name|blksize
decl_stmt|,
name|eco
decl_stmt|,
name|ueco
decl_stmt|,
name|hello
decl_stmt|,
name|other
decl_stmt|,
name|vers
decl_stmt|;
name|etheraddr
name|srcea
decl_stmt|,
name|rtea
decl_stmt|;
name|int
name|priority
decl_stmt|;
name|char
modifier|*
name|rhpx
init|=
operator|(
name|char
operator|*
operator|)
name|rhp
decl_stmt|;
name|int
name|ret
decl_stmt|;
switch|switch
condition|(
name|mflags
operator|&
name|RMF_CTLMASK
condition|)
block|{
case|case
name|RMF_INIT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"init "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|initmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_init
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_src
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_info
argument_list|)
expr_stmt|;
name|blksize
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_blksize
argument_list|)
expr_stmt|;
name|vers
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_vers
argument_list|)
expr_stmt|;
name|eco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_eco
argument_list|)
expr_stmt|;
name|ueco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_ueco
argument_list|)
expr_stmt|;
name|hello
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_init
operator|.
name|in_hello
argument_list|)
expr_stmt|;
name|print_t_info
argument_list|(
name|ndo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"src %sblksize %d vers %d eco %d ueco %d hello %d"
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|blksize
operator|,
name|vers
operator|,
name|eco
operator|,
name|ueco
operator|,
name|hello
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|RMF_VER
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"verification "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|verifmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_ver
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_ver
operator|.
name|ve_src
argument_list|)
expr_stmt|;
name|other
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ver
operator|.
name|ve_fcnval
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"src %s fcnval %o"
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|other
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|RMF_TEST
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"test "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|testmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_test
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_test
operator|.
name|te_src
argument_list|)
expr_stmt|;
name|other
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_test
operator|.
name|te_data
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"src %s data %o"
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|other
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|RMF_L1ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"lev-1-routing "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|l1rout
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_l1rou
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_l1rou
operator|.
name|r1_src
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"src %s "
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|print_l1_routes
argument_list|(
name|ndo
argument_list|,
operator|&
operator|(
name|rhpx
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|l1rout
argument_list|)
index|]
operator|)
argument_list|,
name|length
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|l1rout
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RMF_L2ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"lev-2-routing "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|l2rout
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_l2rout
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_l2rout
operator|.
name|r2_src
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"src %s "
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|print_l2_routes
argument_list|(
name|ndo
argument_list|,
operator|&
operator|(
name|rhpx
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|l2rout
argument_list|)
index|]
operator|)
argument_list|,
name|length
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|l2rout
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RMF_RHELLO
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"router-hello "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|rhellomsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_rhello
argument_list|)
expr_stmt|;
name|vers
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_vers
argument_list|)
expr_stmt|;
name|eco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_eco
argument_list|)
expr_stmt|;
name|ueco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_ueco
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|srcea
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_src
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|srcea
argument_list|)
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|srcea
operator|.
name|dne_remote
operator|.
name|dne_nodeaddr
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_info
argument_list|)
expr_stmt|;
name|blksize
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_blksize
argument_list|)
expr_stmt|;
name|priority
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_priority
argument_list|)
expr_stmt|;
name|hello
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_rhello
operator|.
name|rh_hello
argument_list|)
expr_stmt|;
name|print_i_info
argument_list|(
name|ndo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"vers %d eco %d ueco %d src %s blksize %d pri %d hello %d"
operator|,
name|vers
operator|,
name|eco
operator|,
name|ueco
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|blksize
operator|,
name|priority
operator|,
name|hello
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
name|print_elist
argument_list|(
operator|&
operator|(
name|rhpx
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|rhellomsg
argument_list|)
index|]
operator|)
argument_list|,
name|length
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|rhellomsg
argument_list|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|RMF_EHELLO
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"endnode-hello "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|length
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|ehellomsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|cmp
operator|->
name|cm_ehello
argument_list|)
expr_stmt|;
name|vers
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_vers
argument_list|)
expr_stmt|;
name|eco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_eco
argument_list|)
expr_stmt|;
name|ueco
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_ueco
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|srcea
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_src
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|srcea
argument_list|)
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|srcea
operator|.
name|dne_remote
operator|.
name|dne_nodeaddr
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_info
argument_list|)
expr_stmt|;
name|blksize
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_blksize
argument_list|)
expr_stmt|;
comment|/*seed*/
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|rtea
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
operator|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_router
operator|)
argument_list|,
sizeof|sizeof
argument_list|(
name|rtea
argument_list|)
argument_list|)
expr_stmt|;
name|dst
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rtea
operator|.
name|dne_remote
operator|.
name|dne_nodeaddr
argument_list|)
expr_stmt|;
name|hello
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_hello
argument_list|)
expr_stmt|;
name|other
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cmp
operator|->
name|cm_ehello
operator|.
name|eh_data
argument_list|)
expr_stmt|;
name|print_i_info
argument_list|(
name|ndo
argument_list|,
name|info
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"vers %d eco %d ueco %d src %s blksize %d rtr %s hello %d data %o"
operator|,
name|vers
operator|,
name|eco
operator|,
name|ueco
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|src
argument_list|)
operator|,
name|blksize
operator|,
name|dnaddr_string
argument_list|(
name|ndo
argument_list|,
name|dst
argument_list|)
operator|,
name|hello
operator|,
name|other
operator|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"unknown control message"
operator|)
argument_list|)
expr_stmt|;
name|ND_DEFAULTPRINT
argument_list|(
operator|(
name|u_char
operator|*
operator|)
name|rhp
argument_list|,
name|min
argument_list|(
name|length
argument_list|,
name|caplen
argument_list|)
argument_list|)
expr_stmt|;
name|ret
operator|=
literal|1
expr_stmt|;
break|break;
block|}
return|return
operator|(
name|ret
operator|)
return|;
name|trunc
label|:
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_t_info
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|int
name|info
parameter_list|)
block|{
name|int
name|ntype
init|=
name|info
operator|&
literal|3
decl_stmt|;
switch|switch
condition|(
name|ntype
condition|)
block|{
case|case
literal|0
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-ntype? "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TI_L2ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"l2rout "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TI_L1ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"l1rout "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|TI_ENDNODE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"endnode "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|info
operator|&
name|TI_VERIF
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"verif "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|&
name|TI_BLOCK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"blo "
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_l1_routes
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|char
modifier|*
name|rp
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|int
name|count
decl_stmt|;
name|int
name|id
decl_stmt|;
name|int
name|info
decl_stmt|;
comment|/* The last short is a checksum */
while|while
condition|(
name|len
operator|>
operator|(
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|)
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
name|rp
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
name|count
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|>
literal|1024
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* seems to be bogus from here on */
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|id
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"{ids %d-%d cost %d hops %d} "
operator|,
name|id
operator|,
name|id
operator|+
name|count
operator|,
name|RI_COST
argument_list|(
name|info
argument_list|)
operator|,
name|RI_HOPS
argument_list|(
name|info
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
name|trunc
label|:
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_l2_routes
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|char
modifier|*
name|rp
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|int
name|count
decl_stmt|;
name|int
name|area
decl_stmt|;
name|int
name|info
decl_stmt|;
comment|/* The last short is a checksum */
while|while
condition|(
name|len
operator|>
operator|(
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|short
argument_list|)
operator|)
condition|)
block|{
name|ND_TCHECK2
argument_list|(
operator|*
name|rp
argument_list|,
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
name|count
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
if|if
condition|(
name|count
operator|>
literal|1024
condition|)
return|return
operator|(
literal|1
operator|)
return|;
comment|/* seems to be bogus from here on */
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|area
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|rp
argument_list|)
expr_stmt|;
name|rp
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|len
operator|-=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"{areas %d-%d cost %d hops %d} "
operator|,
name|area
operator|,
name|area
operator|+
name|count
operator|,
name|RI_COST
argument_list|(
name|info
argument_list|)
operator|,
name|RI_HOPS
argument_list|(
name|info
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
name|trunc
label|:
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|print_i_info
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|int
name|info
parameter_list|)
block|{
name|int
name|ntype
init|=
name|info
operator|&
name|II_TYPEMASK
decl_stmt|;
switch|switch
condition|(
name|ntype
condition|)
block|{
case|case
literal|0
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-ntype? "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|II_L2ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"l2rout "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|II_L1ROUT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"l1rout "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|II_ENDNODE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"endnode "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|info
operator|&
name|II_VERIF
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"verif "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|&
name|II_NOMCAST
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nomcast "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|&
name|II_BLOCK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"blo "
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_elist
parameter_list|(
specifier|const
name|char
modifier|*
name|elp
name|_U_
parameter_list|,
name|u_int
name|len
name|_U_
parameter_list|)
block|{
comment|/* Not enough examples available for me to debug this */
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|print_nsp
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|nspp
parameter_list|,
name|u_int
name|nsplen
parameter_list|)
block|{
specifier|const
name|struct
name|nsphdr
modifier|*
name|nsphp
init|=
operator|(
expr|struct
name|nsphdr
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|dst
decl_stmt|,
name|src
decl_stmt|,
name|flags
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|nsphdr
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|nsphp
argument_list|)
expr_stmt|;
name|flags
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|nsphp
operator|->
name|nh_flags
argument_list|)
expr_stmt|;
name|dst
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|nsphp
operator|->
name|nh_dst
argument_list|)
expr_stmt|;
name|src
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|nsphp
operator|->
name|nh_src
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|flags
operator|&
name|NSP_TYPEMASK
condition|)
block|{
case|case
name|MFT_DATA
case|:
switch|switch
condition|(
name|flags
operator|&
name|NSP_SUBMASK
condition|)
block|{
case|case
name|MFS_BOM
case|:
case|case
name|MFS_MOM
case|:
case|case
name|MFS_EOM
case|:
case|case
name|MFS_BOM
operator|+
name|MFS_EOM
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"data %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|seghdr
modifier|*
name|shp
init|=
operator|(
expr|struct
name|seghdr
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|ack
decl_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
name|u_char
modifier|*
name|dp
decl_stmt|;
endif|#
directive|endif
name|u_int
name|data_off
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|minseghdr
argument_list|)
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_ACK
condition|)
block|{
comment|/* acknum field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_NAK
operator|)
operator|==
name|SGQ_NAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|data_off
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_OACK
condition|)
block|{
comment|/* ackoth field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_ONAK
operator|)
operator|==
name|SGQ_ONAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"onak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"oack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|data_off
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"seg %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
if|if
condition|(
name|nsplen
operator|>
name|data_off
condition|)
block|{
name|dp
operator|=
operator|&
operator|(
name|nspp
index|[
name|data_off
index|]
operator|)
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|dp
argument_list|,
name|nsplen
operator|-
name|data_off
argument_list|)
expr_stmt|;
name|pdata
argument_list|(
name|ndo
argument_list|,
name|dp
argument_list|,
name|nsplen
operator|-
name|data_off
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
break|break;
case|case
name|MFS_ILS
operator|+
name|MFS_INT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"intr "
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|seghdr
modifier|*
name|shp
init|=
operator|(
expr|struct
name|seghdr
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|ack
decl_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
name|u_char
modifier|*
name|dp
decl_stmt|;
endif|#
directive|endif
name|u_int
name|data_off
init|=
sizeof|sizeof
argument_list|(
expr|struct
name|minseghdr
argument_list|)
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_ACK
condition|)
block|{
comment|/* acknum field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_NAK
operator|)
operator|==
name|SGQ_NAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|data_off
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_OACK
condition|)
block|{
comment|/* ackdat field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_ONAK
operator|)
operator|==
name|SGQ_ONAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nakdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ackdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|data_off
operator|+=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
if|if
condition|(
name|nsplen
operator|<
name|data_off
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"seg %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
if|if
condition|(
name|nsplen
operator|>
name|data_off
condition|)
block|{
name|dp
operator|=
operator|&
operator|(
name|nspp
index|[
name|data_off
index|]
operator|)
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|dp
argument_list|,
name|nsplen
operator|-
name|data_off
argument_list|)
expr_stmt|;
name|pdata
argument_list|(
name|ndo
argument_list|,
name|dp
argument_list|,
name|nsplen
operator|-
name|data_off
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
break|break;
case|case
name|MFS_ILS
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"link-service %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|seghdr
modifier|*
name|shp
init|=
operator|(
expr|struct
name|seghdr
operator|*
operator|)
name|nspp
decl_stmt|;
name|struct
name|lsmsg
modifier|*
name|lsmp
init|=
operator|(
expr|struct
name|lsmsg
operator|*
operator|)
operator|&
operator|(
name|nspp
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|seghdr
argument_list|)
index|]
operator|)
decl_stmt|;
name|int
name|ack
decl_stmt|;
name|int
name|lsflags
decl_stmt|,
name|fcval
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|seghdr
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|lsmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_ACK
condition|)
block|{
comment|/* acknum field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_NAK
operator|)
operator|==
name|SGQ_NAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_OACK
condition|)
block|{
comment|/* ackdat field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_ONAK
operator|)
operator|==
name|SGQ_ONAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nakdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ackdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|shp
operator|->
name|sh_seq
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"seg %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
name|lsmp
argument_list|)
expr_stmt|;
name|lsflags
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|lsmp
operator|->
name|ls_lsflags
argument_list|)
expr_stmt|;
name|fcval
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|lsmp
operator|->
name|ls_fcval
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|lsflags
operator|&
name|LSI_MASK
condition|)
block|{
case|case
name|LSI_DATA
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"dat seg count %d "
operator|,
name|fcval
operator|)
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|lsflags
operator|&
name|LSM_MASK
condition|)
block|{
case|case
name|LSM_NOCHANGE
case|:
break|break;
case|case
name|LSM_DONOTSEND
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"donotsend-data "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|LSM_SEND
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"send-data "
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-fcmod? %x"
operator|,
name|lsflags
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|LSI_INTR
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"intr req count %d "
operator|,
name|fcval
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-fcval-int? %x"
operator|,
name|lsflags
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-subtype? %x %d> %d"
operator|,
name|flags
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|MFT_ACK
case|:
switch|switch
condition|(
name|flags
operator|&
name|NSP_SUBMASK
condition|)
block|{
case|case
name|MFS_DACK
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"data-ack %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|ackmsg
modifier|*
name|amp
init|=
operator|(
expr|struct
name|ackmsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|ack
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|ackmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|amp
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|amp
operator|->
name|ak_acknum
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_ACK
condition|)
block|{
comment|/* acknum field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_NAK
operator|)
operator|==
name|SGQ_NAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|amp
operator|->
name|ak_acknum
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_OACK
condition|)
block|{
comment|/* ackoth field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_ONAK
operator|)
operator|==
name|SGQ_ONAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"onak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"oack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
break|break;
case|case
name|MFS_IACK
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ils-ack %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|ackmsg
modifier|*
name|amp
init|=
operator|(
expr|struct
name|ackmsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|ack
decl_stmt|;
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|ackmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|amp
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|amp
operator|->
name|ak_acknum
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_ACK
condition|)
block|{
comment|/* acknum field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_NAK
operator|)
operator|==
name|SGQ_NAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nak %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ack %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
name|ND_TCHECK
argument_list|(
name|amp
operator|->
name|ak_acknum
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|ack
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|amp
operator|->
name|ak_acknum
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
if|if
condition|(
name|ack
operator|&
name|SGQ_OACK
condition|)
block|{
comment|/* ackdat field */
if|if
condition|(
operator|(
name|ack
operator|&
name|SGQ_ONAK
operator|)
operator|==
name|SGQ_ONAK
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"nakdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ackdat %d "
operator|,
name|ack
operator|&
name|SGQ_MASK
operator|)
argument_list|)
expr_stmt|;
block|}
block|}
block|}
break|break;
case|case
name|MFS_CACK
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"conn-ack %d"
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-acktype? %x %d> %d"
operator|,
name|flags
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
case|case
name|MFT_CTL
case|:
switch|switch
condition|(
name|flags
operator|&
name|NSP_SUBMASK
condition|)
block|{
case|case
name|MFS_CI
case|:
case|case
name|MFS_RCI
case|:
if|if
condition|(
operator|(
name|flags
operator|&
name|NSP_SUBMASK
operator|)
operator|==
name|MFS_CI
condition|)
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"conn-initiate "
operator|)
argument_list|)
expr_stmt|;
else|else
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"retrans-conn-initiate "
operator|)
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|cimsg
modifier|*
name|cimp
init|=
operator|(
expr|struct
name|cimsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|services
decl_stmt|,
name|info
decl_stmt|,
name|segsize
decl_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
name|u_char
modifier|*
name|dp
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|cimsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|cimp
argument_list|)
expr_stmt|;
name|services
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cimp
operator|->
name|ci_services
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|cimp
operator|->
name|ci_info
argument_list|)
expr_stmt|;
name|segsize
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|cimp
operator|->
name|ci_segsize
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|services
operator|&
name|COS_MASK
condition|)
block|{
case|case
name|COS_NONE
case|:
break|break;
case|case
name|COS_SEGMENT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"seg "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COS_MESSAGE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"msg "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COS_CRYPTSER
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"crypt "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|info
operator|&
name|COI_MASK
condition|)
block|{
case|case
name|COI_32
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 3.2 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_31
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 3.1 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_40
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 4.0 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_41
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 4.1 "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"segsize %d "
operator|,
name|segsize
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
if|if
condition|(
name|nsplen
operator|>
sizeof|sizeof
argument_list|(
expr|struct
name|cimsg
argument_list|)
condition|)
block|{
name|dp
operator|=
operator|&
operator|(
name|nspp
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|cimsg
argument_list|)
index|]
operator|)
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|dp
argument_list|,
name|nsplen
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|cimsg
argument_list|)
argument_list|)
expr_stmt|;
name|pdata
argument_list|(
name|ndo
argument_list|,
name|dp
argument_list|,
name|nsplen
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|cimsg
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
break|break;
case|case
name|MFS_CC
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"conn-confirm %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|ccmsg
modifier|*
name|ccmp
init|=
operator|(
expr|struct
name|ccmsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|services
decl_stmt|,
name|info
decl_stmt|;
name|u_int
name|segsize
decl_stmt|,
name|optlen
decl_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
name|u_char
modifier|*
name|dp
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|ccmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|ccmp
argument_list|)
expr_stmt|;
name|services
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|ccmp
operator|->
name|cc_services
argument_list|)
expr_stmt|;
name|info
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|ccmp
operator|->
name|cc_info
argument_list|)
expr_stmt|;
name|segsize
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|ccmp
operator|->
name|cc_segsize
argument_list|)
expr_stmt|;
name|optlen
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|ccmp
operator|->
name|cc_optlen
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|services
operator|&
name|COS_MASK
condition|)
block|{
case|case
name|COS_NONE
case|:
break|break;
case|case
name|COS_SEGMENT
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"seg "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COS_MESSAGE
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"msg "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COS_CRYPTSER
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"crypt "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|info
operator|&
name|COI_MASK
condition|)
block|{
case|case
name|COI_32
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 3.2 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_31
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 3.1 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_40
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 4.0 "
operator|)
argument_list|)
expr_stmt|;
break|break;
case|case
name|COI_41
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"ver 4.1 "
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"segsize %d "
operator|,
name|segsize
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|optlen
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"optlen %d "
operator|,
name|optlen
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
if|if
condition|(
name|optlen
operator|>
name|nsplen
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|ccmsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|dp
operator|=
operator|&
operator|(
name|nspp
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|ccmsg
argument_list|)
index|]
operator|)
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|dp
argument_list|,
name|optlen
argument_list|)
expr_stmt|;
name|pdata
argument_list|(
name|ndo
argument_list|,
name|dp
argument_list|,
name|optlen
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
break|break;
case|case
name|MFS_DI
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"disconn-initiate %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|dimsg
modifier|*
name|dimp
init|=
operator|(
expr|struct
name|dimsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|reason
decl_stmt|;
name|u_int
name|optlen
decl_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
name|u_char
modifier|*
name|dp
decl_stmt|;
endif|#
directive|endif
if|if
condition|(
name|nsplen
operator|<
sizeof|sizeof
argument_list|(
expr|struct
name|dimsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|dimp
argument_list|)
expr_stmt|;
name|reason
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|dimp
operator|->
name|di_reason
argument_list|)
expr_stmt|;
name|optlen
operator|=
name|EXTRACT_LE_8BITS
argument_list|(
name|dimp
operator|->
name|di_optlen
argument_list|)
expr_stmt|;
name|print_reason
argument_list|(
name|ndo
argument_list|,
name|reason
argument_list|)
expr_stmt|;
if|if
condition|(
name|optlen
condition|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"optlen %d "
operator|,
name|optlen
operator|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
if|if
condition|(
name|optlen
operator|>
name|nsplen
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|dimsg
argument_list|)
condition|)
goto|goto
name|trunc
goto|;
name|dp
operator|=
operator|&
operator|(
name|nspp
index|[
sizeof|sizeof
argument_list|(
expr|struct
name|dimsg
argument_list|)
index|]
operator|)
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|dp
argument_list|,
name|optlen
argument_list|)
expr_stmt|;
name|pdata
argument_list|(
name|ndo
argument_list|,
name|dp
argument_list|,
name|optlen
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
break|break;
case|case
name|MFS_DC
case|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"disconn-confirm %d>%d "
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
block|{
name|struct
name|dcmsg
modifier|*
name|dcmp
init|=
operator|(
expr|struct
name|dcmsg
operator|*
operator|)
name|nspp
decl_stmt|;
name|int
name|reason
decl_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
name|dcmp
argument_list|)
expr_stmt|;
name|reason
operator|=
name|EXTRACT_LE_16BITS
argument_list|(
name|dcmp
operator|->
name|dc_reason
argument_list|)
expr_stmt|;
name|print_reason
argument_list|(
name|ndo
argument_list|,
name|reason
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-ctltype? %x %d> %d"
operator|,
name|flags
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
break|break;
default|default:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"reserved-type? %x %d> %d"
operator|,
name|flags
operator|,
name|src
operator|,
name|dst
operator|)
argument_list|)
expr_stmt|;
break|break;
block|}
return|return
operator|(
literal|1
operator|)
return|;
name|trunc
label|:
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|tok
name|reason2str
index|[]
init|=
block|{
block|{
name|UC_OBJREJECT
block|,
literal|"object rejected connect"
block|}
block|,
block|{
name|UC_RESOURCES
block|,
literal|"insufficient resources"
block|}
block|,
block|{
name|UC_NOSUCHNODE
block|,
literal|"unrecognized node name"
block|}
block|,
block|{
name|DI_SHUT
block|,
literal|"node is shutting down"
block|}
block|,
block|{
name|UC_NOSUCHOBJ
block|,
literal|"unrecognized object"
block|}
block|,
block|{
name|UC_INVOBJFORMAT
block|,
literal|"invalid object name format"
block|}
block|,
block|{
name|UC_OBJTOOBUSY
block|,
literal|"object too busy"
block|}
block|,
block|{
name|DI_PROTOCOL
block|,
literal|"protocol error discovered"
block|}
block|,
block|{
name|DI_TPA
block|,
literal|"third party abort"
block|}
block|,
block|{
name|UC_USERABORT
block|,
literal|"user abort"
block|}
block|,
block|{
name|UC_INVNODEFORMAT
block|,
literal|"invalid node name format"
block|}
block|,
block|{
name|UC_LOCALSHUT
block|,
literal|"local node shutting down"
block|}
block|,
block|{
name|DI_LOCALRESRC
block|,
literal|"insufficient local resources"
block|}
block|,
block|{
name|DI_REMUSERRESRC
block|,
literal|"insufficient remote user resources"
block|}
block|,
block|{
name|UC_ACCESSREJECT
block|,
literal|"invalid access control information"
block|}
block|,
block|{
name|DI_BADACCNT
block|,
literal|"bad ACCOUNT information"
block|}
block|,
block|{
name|UC_NORESPONSE
block|,
literal|"no response from object"
block|}
block|,
block|{
name|UC_UNREACHABLE
block|,
literal|"node unreachable"
block|}
block|,
block|{
name|DC_NOLINK
block|,
literal|"no link terminate"
block|}
block|,
block|{
name|DC_COMPLETE
block|,
literal|"disconnect complete"
block|}
block|,
block|{
name|DI_BADIMAGE
block|,
literal|"bad image data in connect"
block|}
block|,
block|{
name|DI_SERVMISMATCH
block|,
literal|"cryptographic service mismatch"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|print_reason
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
name|int
name|reason
parameter_list|)
block|{
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"%s "
operator|,
name|tok2str
argument_list|(
name|reason2str
argument_list|,
literal|"reason-%d"
argument_list|,
name|reason
argument_list|)
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|dnnum_string
parameter_list|(
name|u_short
name|dnaddr
parameter_list|)
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|size_t
name|siz
decl_stmt|;
name|int
name|area
init|=
call|(
name|u_short
call|)
argument_list|(
name|dnaddr
operator|&
name|AREAMASK
argument_list|)
operator|>>
name|AREASHIFT
decl_stmt|;
name|int
name|node
init|=
name|dnaddr
operator|&
name|NODEMASK
decl_stmt|;
name|str
operator|=
operator|(
name|char
operator|*
operator|)
name|malloc
argument_list|(
name|siz
operator|=
sizeof|sizeof
argument_list|(
literal|"00.0000"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|str
operator|==
name|NULL
condition|)
name|error
argument_list|(
literal|"dnnum_string: malloc"
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|str
argument_list|,
name|siz
argument_list|,
literal|"%d.%d"
argument_list|,
name|area
argument_list|,
name|node
argument_list|)
expr_stmt|;
return|return
operator|(
name|str
operator|)
return|;
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|dnname_string
parameter_list|(
name|u_short
name|dnaddr
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_DNET_HTOA
name|struct
name|dn_naddr
name|dna
decl_stmt|;
name|dna
operator|.
name|a_len
operator|=
sizeof|sizeof
argument_list|(
name|short
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
name|dna
operator|.
name|a_addr
argument_list|,
operator|(
name|char
operator|*
operator|)
operator|&
name|dnaddr
argument_list|,
sizeof|sizeof
argument_list|(
name|short
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|strdup
argument_list|(
name|dnet_htoa
argument_list|(
operator|&
name|dna
argument_list|)
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|dnnum_string
argument_list|(
name|dnaddr
argument_list|)
operator|)
return|;
comment|/* punt */
endif|#
directive|endif
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|PRINT_NSPDATA
end_ifdef

begin_function
specifier|static
name|void
name|pdata
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|u_char
modifier|*
name|dp
parameter_list|,
name|u_int
name|maxlen
parameter_list|)
block|{
name|char
name|c
decl_stmt|;
name|u_int
name|x
init|=
name|maxlen
decl_stmt|;
while|while
condition|(
name|x
operator|--
operator|>
literal|0
condition|)
block|{
name|c
operator|=
operator|*
name|dp
operator|++
expr_stmt|;
name|safeputchar
argument_list|(
name|ndo
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

