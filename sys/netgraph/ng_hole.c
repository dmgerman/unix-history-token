begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ng_hole.c  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elisher<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: ng_hole.c,v 1.10 1999/11/01 09:24:51 julian Exp $  */
end_comment

begin_comment
comment|/*  * This node is a 'black hole' that simply discards everything it receives  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_message.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/netgraph.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_hole.h>
end_include

begin_comment
comment|/* Netgraph methods */
end_comment

begin_decl_stmt
specifier|static
name|ng_constructor_t
name|ngh_cons
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_rcvdata_t
name|ngh_rcvdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|ng_disconnect_t
name|ngh_disconnect
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|struct
name|ng_type
name|typestruct
init|=
block|{
name|NG_ABI_VERSION
block|,
name|NG_HOLE_NODE_TYPE
block|,
name|NULL
block|,
comment|/* modeventhand_t */
name|ngh_cons
block|,
comment|/* ng_constructor_t */
name|NULL
block|,
comment|/* ng_rcvmsg_t */
name|NULL
block|,
comment|/* ng_shutdown_t */
name|NULL
block|,
comment|/* ng_newhook_t */
name|NULL
block|,
comment|/* ng_findhook_t */
name|NULL
block|,
comment|/* ng_connect_t */
name|ngh_rcvdata
block|,
comment|/* ng_rcvdata_t */
name|ngh_disconnect
block|,
comment|/* ng_disconnect_t */
name|NULL
comment|/* ng_cmdlist */
block|}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|NETGRAPH_INIT
argument_list|(
name|hole
argument_list|,
operator|&
name|typestruct
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*   * Be obliging. but no work to do.  */
end_comment

begin_function
specifier|static
name|int
name|ngh_cons
parameter_list|(
name|node_p
name|node
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Receive data  */
end_comment

begin_function
specifier|static
name|int
name|ngh_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|item_p
name|item
parameter_list|)
block|{
name|NG_FREE_ITEM
argument_list|(
name|item
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * Hook disconnection  */
end_comment

begin_function
specifier|static
name|int
name|ngh_disconnect
parameter_list|(
name|hook_p
name|hook
parameter_list|)
block|{
if|if
condition|(
name|NG_NODE_NUMHOOKS
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
operator|==
literal|0
condition|)
name|ng_rmnode_self
argument_list|(
name|NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

