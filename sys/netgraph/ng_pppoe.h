begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_pppoe.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_pppoe.h,v 1.7 1999/10/16 10:16:43 julian Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_PPPOE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_PPPOE_H_
end_define

begin_comment
comment|/********************************************************************  * Netgraph hook constants etc.  ********************************************************************/
end_comment

begin_comment
comment|/* Node type name. This should be unique among all netgraph node types */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_NODE_TYPE
value|"pppoe"
end_define

begin_define
define|#
directive|define
name|NGM_PPPOE_COOKIE
value|939032003
end_define

begin_comment
comment|/* Number of active sessions we can handle */
end_comment

begin_define
define|#
directive|define
name|PPPOE_NUM_SESSIONS
value|16
end_define

begin_comment
comment|/* for now */
end_comment

begin_define
define|#
directive|define
name|PPPOE_SERVICE_NAME_SIZE
value|64
end_define

begin_comment
comment|/* for now */
end_comment

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_HOOK_ETHERNET
value|"ethernet"
end_define

begin_define
define|#
directive|define
name|NG_PPPOE_HOOK_PADI
value|"PADI"
end_define

begin_comment
comment|/* default PADI requests come here */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_HOOK_S_LEADIN
value|"service"
end_define

begin_comment
comment|/* PADO responses from PADI */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_HOOK_C_LEADIN
value|"client"
end_define

begin_comment
comment|/* Connect message starts this */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_HOOK_DEBUG
value|"debug"
end_define

begin_comment
comment|/**********************************************************************  * Netgraph commands understood by this node type.  * FAIL, SUCCESS, CLOSE and ACNAME are sent by the node rather than received.  ********************************************************************/
end_comment

begin_enum
enum|enum
name|cmd
block|{
name|NGM_PPPOE_SET_FLAG
init|=
literal|1
block|,
name|NGM_PPPOE_CONNECT
init|=
literal|2
block|,
comment|/* Client, Try find this service */
name|NGM_PPPOE_LISTEN
init|=
literal|3
block|,
comment|/* Server, Await a request for this service */
name|NGM_PPPOE_OFFER
init|=
literal|4
block|,
comment|/* Server, hook X should respond (*) */
name|NGM_PPPOE_SUCCESS
init|=
literal|5
block|,
comment|/* State machine connected */
name|NGM_PPPOE_FAIL
init|=
literal|6
block|,
comment|/* State machine could not connect */
name|NGM_PPPOE_CLOSE
init|=
literal|7
block|,
comment|/* Session closed down */
name|NGM_PPPOE_SERVICE
init|=
literal|8
block|,
comment|/* additional Service to advertise (in PADO) */
name|NGM_PPPOE_ACNAME
init|=
literal|9
block|,
comment|/* AC_NAME for informational purposes */
name|NGM_PPPOE_GET_STATUS
block|}
enum|;
end_enum

begin_comment
comment|/***********************  * Structures passed in the various netgraph command messages.  ***********************/
end_comment

begin_comment
comment|/* This structure is returned by the NGM_PPPOE_GET_STATUS command */
end_comment

begin_struct
struct|struct
name|ngpppoestat
block|{
name|u_int
name|packets_in
decl_stmt|;
comment|/* packets in from ethernet */
name|u_int
name|packets_out
decl_stmt|;
comment|/* packets out towards ethernet */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOESTAT_TYPE_INFO
value|{				\ 	{							\ 	  { "packets_in",&ng_parse_uint_type	},	\ 	  { "packets_out",&ng_parse_uint_type	},	\ 	  { NULL }						\ 	}							\ }
end_define

begin_comment
comment|/*  * When this structure is accepted by the NGM_PPPOE_CONNECT command :  * The data field is MANDATORY.  * The session sends out a PADI request for the named service.  *  *  * When this structure is accepted by the NGM_PPPOE_LISTEN command.  * If no service is given this is assumed to accept ALL PADI requests.  * This may at some time take a regexp expression, but not yet.  * Matching PADI requests will be passed up the named hook.  *  *  * When this structure is accepted by the NGM_PPPOE_OFFER command:  * The AC-NAme field is set from that given and a PADI  * packet is expected to arrive from the session control daemon, on the  * named hook. The session will then issue the appropriate PADO  * and begin negotiation.  */
end_comment

begin_struct
struct|struct
name|ngpppoe_init_data
block|{
name|char
name|hook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook to monitor on */
name|u_int16_t
name|data_len
decl_stmt|;
comment|/* Length of the service name */
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* init data goes here */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_INIT_DATA_TYPE_INFO
value|{		\ 	{						\ 	  { "hook",&ng_parse_hookbuf_type	},	\ 	  { "data",&ng_parse_sizedstring_type },	\ 	  { NULL }					\ 	}						\ }
end_define

begin_comment
comment|/*  * This structure is used by the asychronous success and failure messages.  * (to report which hook has failed or connected). The message is sent  * to whoever requested the connection. (close may use this too).  */
end_comment

begin_struct
struct|struct
name|ngpppoe_sts
block|{
name|char
name|hook
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* hook associated with event session */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPPOE_STS_TYPE_INFO
value|{		\ 	{						\ 	  { "hook",&ng_parse_hookbuf_type	},	\ 	  { NULL }					\ 	}						\ }
end_define

begin_comment
comment|/********************************************************************  * Constants and definitions specific to pppoe  ********************************************************************/
end_comment

begin_define
define|#
directive|define
name|PPPOE_TIMEOUT_LIMIT
value|64
end_define

begin_define
define|#
directive|define
name|PPPOE_OFFER_TIMEOUT
value|16
end_define

begin_define
define|#
directive|define
name|PPPOE_INITIAL_TIMEOUT
value|2
end_define

begin_comment
comment|/* Codes to identify message types */
end_comment

begin_define
define|#
directive|define
name|PADI_CODE
value|0x09
end_define

begin_define
define|#
directive|define
name|PADO_CODE
value|0x07
end_define

begin_define
define|#
directive|define
name|PADR_CODE
value|0x19
end_define

begin_define
define|#
directive|define
name|PADS_CODE
value|0x65
end_define

begin_define
define|#
directive|define
name|PADT_CODE
value|0xa7
end_define

begin_comment
comment|/* Tag identifiers */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|PTT_EOL
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|PTT_SRV_NAME
value|(0x0101)
end_define

begin_define
define|#
directive|define
name|PTT_AC_NAME
value|(0x0102)
end_define

begin_define
define|#
directive|define
name|PTT_HOST_UNIQ
value|(0x0103)
end_define

begin_define
define|#
directive|define
name|PTT_AC_COOKIE
value|(0x0104)
end_define

begin_define
define|#
directive|define
name|PTT_VENDOR
value|(0x0105)
end_define

begin_define
define|#
directive|define
name|PTT_RELAY_SID
value|(0x0106)
end_define

begin_define
define|#
directive|define
name|PTT_SRV_ERR
value|(0x0201)
end_define

begin_define
define|#
directive|define
name|PTT_SYS_ERR
value|(0x0202)
end_define

begin_define
define|#
directive|define
name|PTT_GEN_ERR
value|(0x0203)
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_DISC
value|0x8863
end_define

begin_comment
comment|/* pppoe discovery packets     */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_SESS
value|0x8864
end_define

begin_comment
comment|/* pppoe session packets       */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_STUPID_DISC
value|0x3c12
end_define

begin_comment
comment|/* pppoe discovery packets 3com? */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_STUPID_SESS
value|0x3c13
end_define

begin_comment
comment|/* pppoe session packets   3com? */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PTT_EOL
value|(0x0000)
end_define

begin_define
define|#
directive|define
name|PTT_SRV_NAME
value|(0x0101)
end_define

begin_define
define|#
directive|define
name|PTT_AC_NAME
value|(0x0201)
end_define

begin_define
define|#
directive|define
name|PTT_HOST_UNIQ
value|(0x0301)
end_define

begin_define
define|#
directive|define
name|PTT_AC_COOKIE
value|(0x0401)
end_define

begin_define
define|#
directive|define
name|PTT_VENDOR
value|(0x0501)
end_define

begin_define
define|#
directive|define
name|PTT_RELAY_SID
value|(0x0601)
end_define

begin_define
define|#
directive|define
name|PTT_SRV_ERR
value|(0x0102)
end_define

begin_define
define|#
directive|define
name|PTT_SYS_ERR
value|(0x0202)
end_define

begin_define
define|#
directive|define
name|PTT_GEN_ERR
value|(0x0302)
end_define

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_DISC
value|0x6388
end_define

begin_comment
comment|/* pppoe discovery packets     */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_SESS
value|0x6488
end_define

begin_comment
comment|/* pppoe session packets       */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_STUPID_DISC
value|0x123c
end_define

begin_comment
comment|/* pppoe discovery packets 3com? */
end_comment

begin_define
define|#
directive|define
name|ETHERTYPE_PPPOE_STUPID_SESS
value|0x133c
end_define

begin_comment
comment|/* pppoe session packets   3com? */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|pppoe_tag
block|{
name|u_int16_t
name|tag_type
decl_stmt|;
name|u_int16_t
name|tag_len
decl_stmt|;
name|char
name|tag_data
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|pppoe_hdr
block|{
name|u_int8_t
name|ver
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|type
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|code
decl_stmt|;
name|u_int16_t
name|sid
decl_stmt|;
name|u_int16_t
name|length
decl_stmt|;
name|struct
name|pppoe_tag
name|tag
index|[
literal|0
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|pppoe_full_hdr
block|{
name|struct
name|ether_header
name|eh
decl_stmt|;
name|struct
name|pppoe_hdr
name|ph
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_union
union|union
name|packet
block|{
name|struct
name|pppoe_full_hdr
name|pkt_header
decl_stmt|;
name|u_int8_t
name|bytes
index|[
literal|2048
index|]
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|datatag
block|{
name|struct
name|pppoe_tag
name|hdr
decl_stmt|;
name|u_int8_t
name|data
index|[
name|PPPOE_SERVICE_NAME_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Define the order in which we will place tags in packets  * this may be ignored  */
end_comment

begin_comment
comment|/* for PADI */
end_comment

begin_define
define|#
directive|define
name|TAGI_SVC
value|0
end_define

begin_define
define|#
directive|define
name|TAGI_HUNIQ
value|1
end_define

begin_comment
comment|/* for PADO */
end_comment

begin_define
define|#
directive|define
name|TAGO_ACNAME
value|0
end_define

begin_define
define|#
directive|define
name|TAGO_SVC
value|1
end_define

begin_define
define|#
directive|define
name|TAGO_COOKIE
value|2
end_define

begin_define
define|#
directive|define
name|TAGO_HUNIQ
value|3
end_define

begin_comment
comment|/* for PADR */
end_comment

begin_define
define|#
directive|define
name|TAGR_SVC
value|0
end_define

begin_define
define|#
directive|define
name|TAGR_HUNIQ
value|1
end_define

begin_define
define|#
directive|define
name|TAGR_COOKIE
value|2
end_define

begin_comment
comment|/* for PADS */
end_comment

begin_define
define|#
directive|define
name|TAGS_ACNAME
value|0
end_define

begin_define
define|#
directive|define
name|TAGS_SVC
value|1
end_define

begin_define
define|#
directive|define
name|TAGS_COOKIE
value|2
end_define

begin_define
define|#
directive|define
name|TAGS_HUNIQ
value|3
end_define

begin_comment
comment|/* for PADT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_PPPOE_H_ */
end_comment

end_unit

