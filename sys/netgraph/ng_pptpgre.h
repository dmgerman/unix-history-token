begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_pptpgre.h  *  * Copyright (c) 1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_pptpgre.h,v 1.3 1999/12/08 00:11:36 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_PPTPGRE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_PPTPGRE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_PPTPGRE_NODE_TYPE
value|"pptpgre"
end_define

begin_define
define|#
directive|define
name|NGM_PPTPGRE_COOKIE
value|942783547
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PPTPGRE_HOOK_UPPER
value|"upper"
end_define

begin_comment
comment|/* to upper layers */
end_comment

begin_define
define|#
directive|define
name|NG_PPTPGRE_HOOK_LOWER
value|"lower"
end_define

begin_comment
comment|/* to lower layers */
end_comment

begin_comment
comment|/* Configuration for a session */
end_comment

begin_struct
struct|struct
name|ng_pptpgre_conf
block|{
name|u_char
name|enabled
decl_stmt|;
comment|/* enables traffic flow */
name|u_char
name|enableDelayedAck
decl_stmt|;
comment|/* enables delayed acks */
name|u_char
name|enableAlwaysAck
decl_stmt|;
comment|/* always include ack with data */
name|u_int16_t
name|cid
decl_stmt|;
comment|/* my call id */
name|u_int16_t
name|peerCid
decl_stmt|;
comment|/* peer call id */
name|u_int16_t
name|recvWin
decl_stmt|;
comment|/* peer recv window size */
name|u_int16_t
name|peerPpd
decl_stmt|;
comment|/* peer packet processing delay 					   (in units of 1/10 of a second) */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPTPGRE_CONF_TYPE_INFO
value|{			\ 	{							\ 	  { "enabled",&ng_parse_uint8_type	},	\ 	  { "enableDelayedAck",&ng_parse_uint8_type	},	\ 	  { "enableAlwaysAck",&ng_parse_uint8_type	},	\ 	  { "cid",&ng_parse_hint16_type	},	\ 	  { "peerCid",&ng_parse_hint16_type	},	\ 	  { "recvWin",&ng_parse_uint16_type	},	\ 	  { "peerPpd",&ng_parse_uint16_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Statistics struct */
end_comment

begin_struct
struct|struct
name|ng_pptpgre_stats
block|{
name|u_int32_t
name|xmitPackets
decl_stmt|;
comment|/* number of GRE packets xmit */
name|u_int32_t
name|xmitOctets
decl_stmt|;
comment|/* number of GRE octets xmit */
name|u_int32_t
name|xmitLoneAcks
decl_stmt|;
comment|/* ack-only packets transmitted */
name|u_int32_t
name|xmitDrops
decl_stmt|;
comment|/* xmits dropped due to full window */
name|u_int32_t
name|xmitTooBig
decl_stmt|;
comment|/* xmits dropped because too big */
name|u_int32_t
name|recvPackets
decl_stmt|;
comment|/* number of GRE packets rec'd */
name|u_int32_t
name|recvOctets
decl_stmt|;
comment|/* number of GRE octets rec'd */
name|u_int32_t
name|recvRunts
decl_stmt|;
comment|/* too short packets rec'd */
name|u_int32_t
name|recvBadGRE
decl_stmt|;
comment|/* bogus packets rec'd (bad GRE hdr) */
name|u_int32_t
name|recvBadAcks
decl_stmt|;
comment|/* bogus ack's rec'd in GRE header */
name|u_int32_t
name|recvBadCID
decl_stmt|;
comment|/* pkts with unknown call ID rec'd */
name|u_int32_t
name|recvOutOfOrder
decl_stmt|;
comment|/* packets rec'd out of order */
name|u_int32_t
name|recvDuplicates
decl_stmt|;
comment|/* packets rec'd with duplicate seq # */
name|u_int32_t
name|recvLoneAcks
decl_stmt|;
comment|/* ack-only packets rec'd */
name|u_int32_t
name|recvAckTimeouts
decl_stmt|;
comment|/* times peer failed to ack in time */
name|u_int32_t
name|memoryFailures
decl_stmt|;
comment|/* times we couldn't allocate memory */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPTPGRE_STATS_TYPE_INFO
value|{			\ 	{							\ 	  { "xmitPackets",&ng_parse_uint32_type	},	\ 	  { "xmitOctets",&ng_parse_uint32_type	},	\ 	  { "xmitLoneAcks",&ng_parse_uint32_type	},	\ 	  { "xmitDrops",&ng_parse_uint32_type	},	\ 	  { "xmitTooBig",&ng_parse_uint32_type	},	\ 	  { "recvPackets",&ng_parse_uint32_type	},	\ 	  { "recvOctets",&ng_parse_uint32_type	},	\ 	  { "recvRunts",&ng_parse_uint32_type	},	\ 	  { "recvBadGRE",&ng_parse_uint32_type	},	\ 	  { "recvBadAcks",&ng_parse_uint32_type	},	\ 	  { "recvBadCID",&ng_parse_uint32_type	},	\ 	  { "recvOutOfOrder",&ng_parse_uint32_type	},	\ 	  { "recvDuplicates",&ng_parse_uint32_type	},	\ 	  { "recvLoneAcks",&ng_parse_uint32_type	},	\ 	  { "recvAckTimeouts",&ng_parse_uint32_type	},	\ 	  { "memoryFailures",&ng_parse_uint32_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_PPTPGRE_SET_CONFIG
init|=
literal|1
block|,
comment|/* supply a struct ng_pptpgre_conf */
name|NGM_PPTPGRE_GET_CONFIG
block|,
comment|/* returns a struct ng_pptpgre_conf */
name|NGM_PPTPGRE_GET_STATS
block|,
comment|/* returns struct ng_pptpgre_stats */
name|NGM_PPTPGRE_CLR_STATS
block|,
comment|/* clears stats */
name|NGM_PPTPGRE_GETCLR_STATS
block|,
comment|/* returns& clears stats */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_PPTPGRE_H_ */
end_comment

end_unit

