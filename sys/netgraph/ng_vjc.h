begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_vjc.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_vjc.h,v 1.6 1999/01/25 02:40:22 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_VJC_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_VJC_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_NODE_TYPE
value|"vjc"
end_define

begin_define
define|#
directive|define
name|NGM_VJC_COOKIE
value|868219210
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_HOOK_IP
value|"ip"
end_define

begin_comment
comment|/* normal IP traffic */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_HOOK_VJCOMP
value|"vjcomp"
end_define

begin_comment
comment|/* compressed TCP */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_HOOK_VJUNCOMP
value|"vjuncomp"
end_define

begin_comment
comment|/* uncompressed TCP */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_HOOK_VJIP
value|"vjip"
end_define

begin_comment
comment|/* uncompressed IP */
end_comment

begin_comment
comment|/* Minimum and maximum number of compression channels */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_MIN_CHANNELS
value|4
end_define

begin_define
define|#
directive|define
name|NG_VJC_MAX_CHANNELS
value|16
end_define

begin_comment
comment|/* Configure struct */
end_comment

begin_struct
struct|struct
name|ngm_vjc_config
block|{
name|u_char
name|enableComp
decl_stmt|;
comment|/* Enable compression */
name|u_char
name|enableDecomp
decl_stmt|;
comment|/* Enable decompression */
name|u_char
name|maxChannel
decl_stmt|;
comment|/* Number of compression channels - 1 */
name|u_char
name|compressCID
decl_stmt|;
comment|/* OK to compress outgoing CID's */
block|}
struct|;
end_struct

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_VJC_CONFIG_TYPE_INFO
value|{				\ 	{							\ 	  { "enableComp",&ng_parse_uint8_type	},	\ 	  { "enableDecomp",&ng_parse_uint8_type	},	\ 	  { "maxChannel",&ng_parse_uint8_type	},	\ 	  { "compressCID",&ng_parse_uint8_type	},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_VJC_SET_CONFIG
block|,
comment|/* Supply a struct ngm_vjc_config */
name|NGM_VJC_GET_CONFIG
block|,
comment|/* Returns a struct ngm_vjc_config */
name|NGM_VJC_GET_STATE
block|,
comment|/* Returns current struct slcompress */
name|NGM_VJC_CLR_STATS
block|,
comment|/* Clears statistics counters */
name|NGM_VJC_RECV_ERROR
block|,
comment|/* Indicate loss of incoming frame */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_VJC_H_ */
end_comment

end_unit

