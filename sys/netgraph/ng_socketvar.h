begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * netgraph.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_socketvar.h,v 1.1 1999/01/20 21:35:39 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_SOCKETVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_SOCKETVAR_H_
value|1
end_define

begin_comment
comment|/* Netgraph protocol control block for each socket */
end_comment

begin_struct
struct|struct
name|ngpcb
block|{
name|struct
name|socket
modifier|*
name|ng_socket
decl_stmt|;
comment|/* the socket */
name|struct
name|ngsock
modifier|*
name|sockdata
decl_stmt|;
comment|/* netgraph info */
name|LIST_ENTRY
argument_list|(
argument|ngpcb
argument_list|)
name|socks
expr_stmt|;
comment|/* linked list of sockets */
name|int
name|type
decl_stmt|;
comment|/* NG_CONTROL or NG_DATA */
block|}
struct|;
end_struct

begin_comment
comment|/* Per-node private data */
end_comment

begin_struct
struct|struct
name|ngsock
block|{
name|struct
name|ng_node
modifier|*
name|node
decl_stmt|;
comment|/* the associated netgraph node */
name|struct
name|ngpcb
modifier|*
name|datasock
decl_stmt|;
comment|/* optional data socket */
name|struct
name|ngpcb
modifier|*
name|ctlsock
decl_stmt|;
comment|/* optional control socket */
name|int
name|flags
decl_stmt|;
name|int
name|refs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGS_FLAG_NOLINGER
value|1
end_define

begin_comment
comment|/* close with last hook */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_SOCKETVAR_H_ */
end_comment

end_unit

