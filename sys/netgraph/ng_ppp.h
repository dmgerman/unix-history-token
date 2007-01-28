begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ppp.h  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996-2000 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_ppp.h,v 1.8 1999/01/25 02:40:02 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_PPP_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_PPP_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_NODE_TYPE
value|"ppp"
end_define

begin_define
define|#
directive|define
name|NGM_PPP_COOKIE
value|940897795
end_define

begin_comment
comment|/* Maximum number of supported links */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_MAX_LINKS
value|16
end_define

begin_comment
comment|/* Pseudo-link number representing the multi-link bundle */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_BUNDLE_LINKNUM
value|0xffff
end_define

begin_comment
comment|/* Max allowable link latency (miliseconds) and bandwidth (bytes/second/10) */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_MAX_LATENCY
value|1000
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_MAX_BANDWIDTH
value|125000
end_define

begin_comment
comment|/* 10 Mbits / second */
end_comment

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_BYPASS
value|"bypass"
end_define

begin_comment
comment|/* unknown protocols */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_COMPRESS
value|"compress"
end_define

begin_comment
comment|/* outgoing compression */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_DECOMPRESS
value|"decompress"
end_define

begin_comment
comment|/* incoming decompression */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_ENCRYPT
value|"encrypt"
end_define

begin_comment
comment|/* outgoing encryption */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_DECRYPT
value|"decrypt"
end_define

begin_comment
comment|/* incoming decryption */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJC_IP
value|"vjc_ip"
end_define

begin_comment
comment|/* VJC raw IP */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJC_COMP
value|"vjc_vjcomp"
end_define

begin_comment
comment|/* VJC compressed TCP */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJC_UNCOMP
value|"vjc_vjuncomp"
end_define

begin_comment
comment|/* VJC uncompressed TCP */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_VJC_VJIP
value|"vjc_vjip"
end_define

begin_comment
comment|/* VJC uncompressed IP */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_INET
value|"inet"
end_define

begin_comment
comment|/* IP packet data */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_ATALK
value|"atalk"
end_define

begin_comment
comment|/* AppleTalk packet data */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_IPX
value|"ipx"
end_define

begin_comment
comment|/* IPX packet data */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_IPV6
value|"ipv6"
end_define

begin_comment
comment|/* IPv6 packet data */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_HOOK_LINK_PREFIX
value|"link"
end_define

begin_comment
comment|/* append decimal link number */
end_comment

begin_comment
comment|/* Compress hook operation modes */
end_comment

begin_enum
enum|enum
block|{
name|NG_PPP_COMPRESS_NONE
init|=
literal|0
block|,
comment|/* compression disabled */
name|NG_PPP_COMPRESS_SIMPLE
block|,
comment|/* original operation mode */
name|NG_PPP_COMPRESS_FULL
block|,
comment|/* compressor returns proto */
block|}
enum|;
end_enum

begin_comment
comment|/* Decompress hook operation modes */
end_comment

begin_enum
enum|enum
block|{
name|NG_PPP_DECOMPRESS_NONE
init|=
literal|0
block|,
comment|/* decompression disabled */
name|NG_PPP_DECOMPRESS_SIMPLE
block|,
comment|/* original operation mode */
name|NG_PPP_DECOMPRESS_FULL
block|,
comment|/* forward any packet to decompressor */
block|}
enum|;
end_enum

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_PPP_SET_CONFIG
init|=
literal|1
block|,
comment|/* takes struct ng_ppp_node_conf */
name|NGM_PPP_GET_CONFIG
block|,
comment|/* returns ng_ppp_node_conf */
name|NGM_PPP_GET_MP_STATE
block|,
comment|/* returns ng_ppp_mp_state */
name|NGM_PPP_GET_LINK_STATS
block|,
comment|/* takes link #, returns stats struct */
name|NGM_PPP_CLR_LINK_STATS
block|,
comment|/* takes link #, clears link stats */
name|NGM_PPP_GETCLR_LINK_STATS
block|,
comment|/* takes link #, returns& clrs stats */
block|}
enum|;
end_enum

begin_comment
comment|/* Multi-link sequence number state (for debugging) */
end_comment

begin_struct
struct|struct
name|ng_ppp_mp_state
block|{
name|int32_t
name|rseq
index|[
name|NG_PPP_MAX_LINKS
index|]
decl_stmt|;
comment|/* highest rec'd MP seq # */
name|int32_t
name|mseq
decl_stmt|;
comment|/* min rseq[i] */
name|int32_t
name|xseq
decl_stmt|;
comment|/* next xmit MP seq # */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_MP_STATE_TYPE_INFO
parameter_list|(
name|atype
parameter_list|)
value|{		\ 	  { "rseq",	(atype)			},		\ 	  { "mseq",&ng_parse_hint32_type	},		\ 	  { "xseq",&ng_parse_hint32_type	},		\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Per-link config structure */
end_comment

begin_struct
struct|struct
name|ng_ppp_link_conf
block|{
name|u_char
name|enableLink
decl_stmt|;
comment|/* enable this link */
name|u_char
name|enableProtoComp
decl_stmt|;
comment|/* enable protocol field compression */
name|u_char
name|enableACFComp
decl_stmt|;
comment|/* enable addr/ctrl field compression */
name|u_int16_t
name|mru
decl_stmt|;
comment|/* peer MRU */
name|u_int32_t
name|latency
decl_stmt|;
comment|/* link latency (in milliseconds) */
name|u_int32_t
name|bandwidth
decl_stmt|;
comment|/* link bandwidth (in bytes/sec/10) */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_LINK_TYPE_INFO
value|{				\ 	  { "enableLink",&ng_parse_uint8_type	},	\ 	  { "enableProtoComp",&ng_parse_uint8_type	},	\ 	  { "enableACFComp",&ng_parse_uint8_type	},	\ 	  { "mru",&ng_parse_uint16_type	},	\ 	  { "latency",&ng_parse_uint32_type	},	\ 	  { "bandwidth",&ng_parse_uint32_type	},	\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Bundle config structure */
end_comment

begin_struct
struct|struct
name|ng_ppp_bund_conf
block|{
name|u_int16_t
name|mrru
decl_stmt|;
comment|/* multilink peer MRRU */
name|u_char
name|enableMultilink
decl_stmt|;
comment|/* enable multilink */
name|u_char
name|recvShortSeq
decl_stmt|;
comment|/* recv multilink short seq # */
name|u_char
name|xmitShortSeq
decl_stmt|;
comment|/* xmit multilink short seq # */
name|u_char
name|enableRoundRobin
decl_stmt|;
comment|/* xmit whole packets */
name|u_char
name|enableIP
decl_stmt|;
comment|/* enable IP data flow */
name|u_char
name|enableIPv6
decl_stmt|;
comment|/* enable IPv6 data flow */
name|u_char
name|enableAtalk
decl_stmt|;
comment|/* enable AppleTalk data flow */
name|u_char
name|enableIPX
decl_stmt|;
comment|/* enable IPX data flow */
name|u_char
name|enableCompression
decl_stmt|;
comment|/* enable PPP compression */
name|u_char
name|enableDecompression
decl_stmt|;
comment|/* enable PPP decompression */
name|u_char
name|enableEncryption
decl_stmt|;
comment|/* enable PPP encryption */
name|u_char
name|enableDecryption
decl_stmt|;
comment|/* enable PPP decryption */
name|u_char
name|enableVJCompression
decl_stmt|;
comment|/* enable VJ compression */
name|u_char
name|enableVJDecompression
decl_stmt|;
comment|/* enable VJ decompression */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_BUND_TYPE_INFO
value|{					\ 	  { "mrru",&ng_parse_uint16_type	},	\ 	  { "enableMultilink",&ng_parse_uint8_type	},	\ 	  { "recvShortSeq",&ng_parse_uint8_type	},	\ 	  { "xmitShortSeq",&ng_parse_uint8_type	},	\ 	  { "enableRoundRobin",&ng_parse_uint8_type	},	\ 	  { "enableIP",&ng_parse_uint8_type	},	\ 	  { "enableIPv6",&ng_parse_uint8_type	},	\ 	  { "enableAtalk",&ng_parse_uint8_type	},	\ 	  { "enableIPX",&ng_parse_uint8_type	},	\ 	  { "enableCompression",&ng_parse_uint8_type	},	\ 	  { "enableDecompression",&ng_parse_uint8_type	},	\ 	  { "enableEncryption",&ng_parse_uint8_type	},	\ 	  { "enableDecryption",&ng_parse_uint8_type	},	\ 	  { "enableVJCompression",&ng_parse_uint8_type	},	\ 	  { "enableVJDecompression",&ng_parse_uint8_type	},	\ 	  { NULL }							\ }
end_define

begin_comment
comment|/* Total node config structure */
end_comment

begin_struct
struct|struct
name|ng_ppp_node_conf
block|{
name|struct
name|ng_ppp_bund_conf
name|bund
decl_stmt|;
name|struct
name|ng_ppp_link_conf
name|links
index|[
name|NG_PPP_MAX_LINKS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_CONFIG_TYPE_INFO
parameter_list|(
name|bctype
parameter_list|,
name|arytype
parameter_list|)
value|{	\ 	  { "bund",		(bctype)	},		\ 	  { "links",		(arytype)	},		\ 	  { NULL }						\ }
end_define

begin_comment
comment|/* Statistics struct for a link (or the bundle if NG_PPP_BUNDLE_LINKNUM) */
end_comment

begin_struct
struct|struct
name|ng_ppp_link_stat
block|{
name|u_int32_t
name|xmitFrames
decl_stmt|;
comment|/* xmit frames on link */
name|u_int32_t
name|xmitOctets
decl_stmt|;
comment|/* xmit octets on link */
name|u_int32_t
name|recvFrames
decl_stmt|;
comment|/* recv frames on link */
name|u_int32_t
name|recvOctets
decl_stmt|;
comment|/* recv octets on link */
name|u_int32_t
name|badProtos
decl_stmt|;
comment|/* frames rec'd with bogus protocol */
name|u_int32_t
name|runts
decl_stmt|;
comment|/* Too short MP fragments */
name|u_int32_t
name|dupFragments
decl_stmt|;
comment|/* MP frames with duplicate seq # */
name|u_int32_t
name|dropFragments
decl_stmt|;
comment|/* MP fragments we had to drop */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_PPP_STATS_TYPE_INFO
value|{				\ 	  { "xmitFrames",&ng_parse_uint32_type	},	\ 	  { "xmitOctets",&ng_parse_uint32_type	},	\ 	  { "recvFrames",&ng_parse_uint32_type	},	\ 	  { "recvOctets",&ng_parse_uint32_type	},	\ 	  { "badProtos",&ng_parse_uint32_type	},	\ 	  { "runts",&ng_parse_uint32_type	},	\ 	  { "dupFragments",&ng_parse_uint32_type	},	\ 	  { "dropFragments",&ng_parse_uint32_type	},	\ 	  { NULL }						\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_PPP_H_ */
end_comment

end_unit

