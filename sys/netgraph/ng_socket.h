begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_socket.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_socket.h,v 1.5 1999/01/20 00:22:14 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_SOCKET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_SOCKET_H_
value|1
end_define

begin_comment
comment|/* Netgraph node type name and cookie */
end_comment

begin_define
define|#
directive|define
name|NG_SOCKET_NODE_TYPE
value|"socket"
end_define

begin_define
define|#
directive|define
name|NGM_SOCKET_COOKIE
value|851601233
end_define

begin_comment
comment|/* Netgraph socket(2) constants */
end_comment

begin_define
define|#
directive|define
name|NG_DATA
value|1
end_define

begin_define
define|#
directive|define
name|NG_CONTROL
value|2
end_define

begin_comment
comment|/* Commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_SOCK_CMD_NOLINGER
init|=
literal|1
block|,
comment|/* close the socket with last hook */
name|NGM_SOCK_CMD_LINGER
comment|/* Keep socket even if 0 hooks */
block|}
enum|;
end_enum

begin_comment
comment|/* Netgraph version of struct sockaddr */
end_comment

begin_struct
struct|struct
name|sockaddr_ng
block|{
name|u_char
name|sg_len
decl_stmt|;
comment|/* total length */
name|u_char
name|sg_family
decl_stmt|;
comment|/* address family */
name|char
name|sg_data
index|[
literal|14
index|]
decl_stmt|;
comment|/* actually longer; address value */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_SOCKET_H_ */
end_comment

end_unit

