begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_iface.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_iface.h,v 1.5 1999/01/20 00:22:13 archie Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_IFACE_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_IFACE_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_IFACE_NODE_TYPE
value|"iface"
end_define

begin_define
define|#
directive|define
name|NGM_IFACE_COOKIE
value|858821773
end_define

begin_comment
comment|/* Interface base name */
end_comment

begin_define
define|#
directive|define
name|NG_IFACE_IFACE_NAME
value|"ng"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_IFACE_NAME_MAX
value|15
end_define

begin_comment
comment|/* My hook names */
end_comment

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_INET
value|"inet"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_INET6
value|"inet6"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_ATALK
value|"atalk"
end_define

begin_comment
comment|/* AppleTalk phase 2 */
end_comment

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_IPX
value|"ipx"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_ATM
value|"atm"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_NATM
value|"natm"
end_define

begin_define
define|#
directive|define
name|NG_IFACE_HOOK_NS
value|"ns"
end_define

begin_comment
comment|/* MTU bounds */
end_comment

begin_define
define|#
directive|define
name|NG_IFACE_MTU_MIN
value|72
end_define

begin_define
define|#
directive|define
name|NG_IFACE_MTU_MAX
value|65535
end_define

begin_define
define|#
directive|define
name|NG_IFACE_MTU_DEFAULT
value|1500
end_define

begin_comment
comment|/* Netgraph commands */
end_comment

begin_enum
enum|enum
block|{
name|NGM_IFACE_GET_IFNAME
init|=
literal|1
block|,
comment|/* returns struct ng_iface_ifname */
name|NGM_IFACE_POINT2POINT
block|,
name|NGM_IFACE_BROADCAST
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ng_iface_ifname
block|{
name|char
name|ngif_name
index|[
name|NG_IFACE_IFACE_NAME_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_IFACE_H_ */
end_comment

end_unit

