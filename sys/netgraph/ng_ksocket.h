begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ksocket.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_ksocket.h,v 1.1 1999/11/16 20:04:40 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_KSOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_KSOCKET_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_KSOCKET_NODE_TYPE
value|"ksocket"
end_define

begin_define
define|#
directive|define
name|NGM_KSOCKET_COOKIE
value|942710669
end_define

begin_comment
comment|/* For NGM_KSOCKET_SETOPT and NGM_KSOCKET_GETOPT control messages */
end_comment

begin_struct
struct|struct
name|ng_ksocket_sockopt
block|{
name|int32_t
name|level
decl_stmt|;
comment|/* second arg of [gs]etsockopt() */
name|int32_t
name|name
decl_stmt|;
comment|/* third arg of [gs]etsockopt() */
name|u_char
name|value
index|[
literal|0
index|]
decl_stmt|;
comment|/* fourth arg of [gs]etsockopt() */
block|}
struct|;
end_struct

begin_comment
comment|/* Max length socket option we can return via NGM_KSOCKET_GETOPT    XXX This should not be necessary, we should dynamically size    XXX the response. Until then.. */
end_comment

begin_define
define|#
directive|define
name|NG_KSOCKET_MAX_OPTLEN
value|1024
end_define

begin_comment
comment|/* Keep this in sync with the above structure definition */
end_comment

begin_define
define|#
directive|define
name|NG_KSOCKET_SOCKOPT_INFO
parameter_list|(
name|svtype
parameter_list|)
value|{			\ 	{							\ 	  { "level",&ng_parse_int32_type	},	\ 	  { "name",&ng_parse_int32_type	},	\ 	  { "value",		(svtype)		},	\ 	  { NULL },						\ 	}							\ }
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_KSOCKET_BIND
init|=
literal|1
block|,
name|NGM_KSOCKET_LISTEN
block|,
name|NGM_KSOCKET_ACCEPT
block|,
name|NGM_KSOCKET_CONNECT
block|,
name|NGM_KSOCKET_GETNAME
block|,
name|NGM_KSOCKET_GETPEERNAME
block|,
name|NGM_KSOCKET_SETOPT
block|,
name|NGM_KSOCKET_GETOPT
block|, }
enum|;
end_enum

begin_comment
comment|/* Meta information ID's */
end_comment

begin_define
define|#
directive|define
name|NG_KSOCKET_META_SOCKADDR
value|1
end_define

begin_comment
comment|/* data is struct sockaddr */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_KSOCKET_H_ */
end_comment

end_unit

