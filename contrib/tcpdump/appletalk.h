begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * AppleTalk protocol formats (courtesy Bill Croft of Stanford/SUMEX).  *  * @(#) $Header: /tcpdump/master/tcpdump/appletalk.h,v 1.13 2000/10/03 02:54:54 itojun Exp $ (LBL)  */
end_comment

begin_struct
struct|struct
name|LAP
block|{
name|u_int8_t
name|dst
decl_stmt|;
name|u_int8_t
name|src
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|lapShortDDP
value|1
end_define

begin_comment
comment|/* short DDP type */
end_comment

begin_define
define|#
directive|define
name|lapDDP
value|2
end_define

begin_comment
comment|/* DDP type */
end_comment

begin_define
define|#
directive|define
name|lapKLAP
value|'K'
end_define

begin_comment
comment|/* Kinetics KLAP type */
end_comment

begin_comment
comment|/* Datagram Delivery Protocol */
end_comment

begin_struct
struct|struct
name|atDDP
block|{
name|u_int16_t
name|length
decl_stmt|;
name|u_int16_t
name|checksum
decl_stmt|;
name|u_int16_t
name|dstNet
decl_stmt|;
name|u_int16_t
name|srcNet
decl_stmt|;
name|u_int8_t
name|dstNode
decl_stmt|;
name|u_int8_t
name|srcNode
decl_stmt|;
name|u_int8_t
name|dstSkt
decl_stmt|;
name|u_int8_t
name|srcSkt
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atShortDDP
block|{
name|u_int16_t
name|length
decl_stmt|;
name|u_int8_t
name|dstSkt
decl_stmt|;
name|u_int8_t
name|srcSkt
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ddpMaxWKS
value|0x7F
end_define

begin_define
define|#
directive|define
name|ddpMaxData
value|586
end_define

begin_define
define|#
directive|define
name|ddpLengthMask
value|0x3FF
end_define

begin_define
define|#
directive|define
name|ddpHopShift
value|10
end_define

begin_define
define|#
directive|define
name|ddpSize
value|13
end_define

begin_comment
comment|/* size of DDP header (avoid struct padding) */
end_comment

begin_define
define|#
directive|define
name|ddpSSize
value|5
end_define

begin_define
define|#
directive|define
name|ddpWKS
value|128
end_define

begin_comment
comment|/* boundary of DDP well known sockets */
end_comment

begin_define
define|#
directive|define
name|ddpRTMP
value|1
end_define

begin_comment
comment|/* RTMP type */
end_comment

begin_define
define|#
directive|define
name|ddpRTMPrequest
value|5
end_define

begin_comment
comment|/* RTMP request type */
end_comment

begin_define
define|#
directive|define
name|ddpNBP
value|2
end_define

begin_comment
comment|/* NBP type */
end_comment

begin_define
define|#
directive|define
name|ddpATP
value|3
end_define

begin_comment
comment|/* ATP type */
end_comment

begin_define
define|#
directive|define
name|ddpECHO
value|4
end_define

begin_comment
comment|/* ECHO type */
end_comment

begin_define
define|#
directive|define
name|ddpIP
value|22
end_define

begin_comment
comment|/* IP type */
end_comment

begin_define
define|#
directive|define
name|ddpARP
value|23
end_define

begin_comment
comment|/* ARP type */
end_comment

begin_define
define|#
directive|define
name|ddpKLAP
value|0x4b
end_define

begin_comment
comment|/* Kinetics KLAP type */
end_comment

begin_comment
comment|/* AppleTalk Transaction Protocol */
end_comment

begin_struct
struct|struct
name|atATP
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|bitmap
decl_stmt|;
name|u_int16_t
name|transID
decl_stmt|;
name|int32_t
name|userData
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|atpReqCode
value|0x40
end_define

begin_define
define|#
directive|define
name|atpRspCode
value|0x80
end_define

begin_define
define|#
directive|define
name|atpRelCode
value|0xC0
end_define

begin_define
define|#
directive|define
name|atpXO
value|0x20
end_define

begin_define
define|#
directive|define
name|atpEOM
value|0x10
end_define

begin_define
define|#
directive|define
name|atpSTS
value|0x08
end_define

begin_define
define|#
directive|define
name|atpFlagMask
value|0x3F
end_define

begin_define
define|#
directive|define
name|atpControlMask
value|0xF8
end_define

begin_define
define|#
directive|define
name|atpMaxNum
value|8
end_define

begin_define
define|#
directive|define
name|atpMaxData
value|578
end_define

begin_comment
comment|/* AppleTalk Echo Protocol */
end_comment

begin_struct
struct|struct
name|atEcho
block|{
name|u_int8_t
name|echoFunction
decl_stmt|;
name|u_int8_t
modifier|*
name|echoData
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|echoSkt
value|4
end_define

begin_comment
comment|/* the echoer socket */
end_comment

begin_define
define|#
directive|define
name|echoSize
value|1
end_define

begin_comment
comment|/* size of echo header */
end_comment

begin_define
define|#
directive|define
name|echoRequest
value|1
end_define

begin_comment
comment|/* echo request */
end_comment

begin_define
define|#
directive|define
name|echoReply
value|2
end_define

begin_comment
comment|/* echo request */
end_comment

begin_comment
comment|/* Name Binding Protocol */
end_comment

begin_struct
struct|struct
name|atNBP
block|{
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|id
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|atNBPtuple
block|{
name|u_int16_t
name|net
decl_stmt|;
name|u_int8_t
name|node
decl_stmt|;
name|u_int8_t
name|skt
decl_stmt|;
name|u_int8_t
name|enumerator
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|nbpBrRq
value|0x10
end_define

begin_define
define|#
directive|define
name|nbpLkUp
value|0x20
end_define

begin_define
define|#
directive|define
name|nbpLkUpReply
value|0x30
end_define

begin_define
define|#
directive|define
name|nbpNIS
value|2
end_define

begin_define
define|#
directive|define
name|nbpTupleMax
value|15
end_define

begin_define
define|#
directive|define
name|nbpHeaderSize
value|2
end_define

begin_define
define|#
directive|define
name|nbpTupleSize
value|5
end_define

begin_define
define|#
directive|define
name|nbpSkt
value|2
end_define

begin_comment
comment|/* NIS */
end_comment

begin_comment
comment|/* Routing Table Maint. Protocol */
end_comment

begin_define
define|#
directive|define
name|rtmpSkt
value|1
end_define

begin_comment
comment|/* number of RTMP socket */
end_comment

begin_define
define|#
directive|define
name|rtmpSize
value|4
end_define

begin_comment
comment|/* minimum size */
end_comment

begin_define
define|#
directive|define
name|rtmpTupleSize
value|3
end_define

begin_comment
comment|/* Zone Information Protocol */
end_comment

begin_struct
struct|struct
name|zipHeader
block|{
name|u_int8_t
name|command
decl_stmt|;
name|u_int8_t
name|netcount
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|zipHeaderSize
value|2
end_define

begin_define
define|#
directive|define
name|zipQuery
value|1
end_define

begin_define
define|#
directive|define
name|zipReply
value|2
end_define

begin_define
define|#
directive|define
name|zipTakedown
value|3
end_define

begin_define
define|#
directive|define
name|zipBringup
value|4
end_define

begin_define
define|#
directive|define
name|ddpZIP
value|6
end_define

begin_define
define|#
directive|define
name|zipSkt
value|6
end_define

begin_define
define|#
directive|define
name|GetMyZone
value|7
end_define

begin_define
define|#
directive|define
name|GetZoneList
value|8
end_define

begin_comment
comment|/*  * UDP port range used for ddp-in-udp encapsulation is 16512-16639  * for client sockets (128-255) and 200-327 for server sockets  * (0-127).  We also try to recognize the pre-April 88 server  * socket range of 768-895.  */
end_comment

begin_define
define|#
directive|define
name|atalk_port
parameter_list|(
name|p
parameter_list|)
define|\
value|(((unsigned)((p) - 16512)< 128) || \ 	 ((unsigned)((p) - 200)< 128) || \ 	 ((unsigned)((p) - 768)< 128))
end_define

end_unit

