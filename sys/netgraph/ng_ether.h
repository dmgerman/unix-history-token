begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_ether.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Archie Cobbs<archie@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_ether.h,v 1.1 1999/02/02 03:17:22 julian Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NG_ETHER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NG_ETHER_H_
end_define

begin_comment
comment|/* Node type name and magic cookie */
end_comment

begin_define
define|#
directive|define
name|NG_ETHER_NODE_TYPE
value|"ether"
end_define

begin_define
define|#
directive|define
name|NGM_ETHER_COOKIE
value|917786906
end_define

begin_comment
comment|/* Hook names */
end_comment

begin_define
define|#
directive|define
name|NG_ETHER_HOOK_LOWER
value|"lower"
end_define

begin_comment
comment|/* connection to raw device */
end_comment

begin_define
define|#
directive|define
name|NG_ETHER_HOOK_UPPER
value|"upper"
end_define

begin_comment
comment|/* connection to upper layers */
end_comment

begin_define
define|#
directive|define
name|NG_ETHER_HOOK_DIVERT
value|"divert"
end_define

begin_comment
comment|/* alias for lower */
end_comment

begin_define
define|#
directive|define
name|NG_ETHER_HOOK_ORPHAN
value|"orphans"
end_define

begin_comment
comment|/* like lower, unknowns only */
end_comment

begin_comment
comment|/* Netgraph control messages */
end_comment

begin_enum
enum|enum
block|{
name|NGM_ETHER_GET_IFNAME
init|=
literal|1
block|,
comment|/* get the interface name */
name|NGM_ETHER_GET_IFINDEX
block|,
comment|/* get the interface global index # */
name|NGM_ETHER_GET_ENADDR
block|,
comment|/* get Ethernet address */
name|NGM_ETHER_SET_ENADDR
block|,
comment|/* set Ethernet address */
name|NGM_ETHER_GET_PROMISC
block|,
comment|/* get node's promiscuous mode bit */
name|NGM_ETHER_SET_PROMISC
block|,
comment|/* enable/disable promiscuous mode */
name|NGM_ETHER_GET_AUTOSRC
block|,
comment|/* get source address override */
name|NGM_ETHER_SET_AUTOSRC
block|,
comment|/* enable/disable src addr override */
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* Ethernet address parse type */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ng_parse_type
name|ng_ether_enaddr_type
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NG_ETHER_H_ */
end_comment

end_unit

