begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * netgraph.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@freebsd.org>  *  * $FreeBSD$  * $Whistle: netgraph.h,v 1.29 1999/11/01 07:56:13 julian Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETGRAPH_NETGRAPH_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETGRAPH_NETGRAPH_H_
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"This file should not be included in user level programs"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_comment
comment|/* debugging options */
end_comment

begin_define
define|#
directive|define
name|NETGRAPH_DEBUG
end_define

begin_define
define|#
directive|define
name|NG_SEPARATE_MALLOC
end_define

begin_comment
comment|/* make modules use their own malloc types */
end_comment

begin_comment
comment|/*  * This defines the in-kernel binary interface version.  * It is possible to change this but leave the external message  * API the same. Each type also has it's own cookies for versioning as well.  * Change it for NETGRAPH_DEBUG version so we cannot mix debug and non debug  * modules.  */
end_comment

begin_define
define|#
directive|define
name|_NG_ABI_VERSION
value|6
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
end_ifdef

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_ABI_VERSION
value|(_NG_ABI_VERSION + 0x10000)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_ABI_VERSION
value|_NG_ABI_VERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_comment
comment|/*  * Forward references for the basic structures so we can  * define the typedefs and use them in the structures themselves.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_hook
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_node
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ng_item
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|ng_item
modifier|*
name|item_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_node
modifier|*
name|node_p
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ng_hook
modifier|*
name|hook_p
typedef|;
end_typedef

begin_comment
comment|/* node method definitions */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_constructor_t
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_shutdown_t
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_newhook_t
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|hook_p
name|ng_findhook_t
parameter_list|(
name|node_p
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_connect_t
parameter_list|(
name|hook_p
name|hook
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_rcvmsg_t
parameter_list|(
name|node_p
name|node
parameter_list|,
name|item_p
name|item
parameter_list|,
name|hook_p
name|lasthook
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_rcvdata_t
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|item_p
name|item
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_disconnect_t
parameter_list|(
name|hook_p
name|hook
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|ng_rcvitem
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|item_p
name|item
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/***********************************************************************  ***************** Hook Structure and Methods **************************  ***********************************************************************  *  * Structure of a hook  */
end_comment

begin_struct
struct|struct
name|ng_hook
block|{
name|char
name|hk_name
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* what this node knows this link as */
name|void
modifier|*
name|hk_private
decl_stmt|;
comment|/* node dependant ID for this hook */
name|int
name|hk_flags
decl_stmt|;
comment|/* info about this hook/link */
name|int
name|hk_refs
decl_stmt|;
comment|/* dont actually free this till 0 */
name|struct
name|ng_hook
modifier|*
name|hk_peer
decl_stmt|;
comment|/* the other end of this link */
name|struct
name|ng_node
modifier|*
name|hk_node
decl_stmt|;
comment|/* The node this hook is attached to */
name|LIST_ENTRY
argument_list|(
argument|ng_hook
argument_list|)
name|hk_hooks
expr_stmt|;
comment|/* linked list of all hooks on node */
name|ng_rcvmsg_t
modifier|*
name|hk_rcvmsg
decl_stmt|;
comment|/* control messages come here */
name|ng_rcvdata_t
modifier|*
name|hk_rcvdata
decl_stmt|;
comment|/* data comes here */
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
comment|/*----------------------------------------------*/
define|#
directive|define
name|HK_MAGIC
value|0x78573011
name|int
name|hk_magic
decl_stmt|;
name|char
modifier|*
name|lastfile
decl_stmt|;
name|int
name|lastline
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ng_hook
argument_list|)
name|hk_all
expr_stmt|;
comment|/* all existing items */
endif|#
directive|endif
comment|/* NETGRAPH_DEBUG */
comment|/*----------------------------------------------*/
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for a hook */
end_comment

begin_define
define|#
directive|define
name|HK_INVALID
value|0x0001
end_define

begin_comment
comment|/* don't trust it! */
end_comment

begin_define
define|#
directive|define
name|HK_QUEUE
value|0x0002
end_define

begin_comment
comment|/* queue for later delivery */
end_comment

begin_define
define|#
directive|define
name|HK_FORCE_WRITER
value|0x0004
end_define

begin_comment
comment|/* Incoming data queued as a writer */
end_comment

begin_define
define|#
directive|define
name|HK_DEAD
value|0x0008
end_define

begin_comment
comment|/* This is the dead hook.. don't free */
end_comment

begin_comment
comment|/*  * Public Methods for hook  * If you can't do it with these you probably shouldn;t be doing it.  */
end_comment

begin_function_decl
name|void
name|ng_unref_hook
parameter_list|(
name|hook_p
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* don't move this */
end_comment

begin_define
define|#
directive|define
name|_NG_HOOK_REF
parameter_list|(
name|hook
parameter_list|)
value|atomic_add_int(&(hook)->hk_refs, 1)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_NAME
parameter_list|(
name|hook
parameter_list|)
value|((hook)->hk_name)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_UNREF
parameter_list|(
name|hook
parameter_list|)
value|ng_unref_hook(hook)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_SET_PRIVATE
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|do {(hook)->hk_private = val;} while (0)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_SET_RCVMSG
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|do {(hook)->hk_rcvmsg = val;} while (0)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_SET_RCVDATA
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|do {(hook)->hk_rcvdata = val;} while (0)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_PRIVATE
parameter_list|(
name|hook
parameter_list|)
value|((hook)->hk_private)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_NOT_VALID
parameter_list|(
name|hook
parameter_list|)
value|((hook)->hk_flags& HK_INVALID)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_IS_VALID
parameter_list|(
name|hook
parameter_list|)
value|(!((hook)->hk_flags& HK_INVALID))
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_NODE
parameter_list|(
name|hook
parameter_list|)
value|((hook)->hk_node)
end_define

begin_comment
comment|/* only rvalue! */
end_comment

begin_define
define|#
directive|define
name|_NG_HOOK_PEER
parameter_list|(
name|hook
parameter_list|)
value|((hook)->hk_peer)
end_define

begin_comment
comment|/* only rvalue! */
end_comment

begin_define
define|#
directive|define
name|_NG_HOOK_FORCE_WRITER
parameter_list|(
name|hook
parameter_list|)
define|\
value|do { hook->hk_flags |= HK_FORCE_WRITER; } while (0)
end_define

begin_define
define|#
directive|define
name|_NG_HOOK_FORCE_QUEUE
parameter_list|(
name|hook
parameter_list|)
value|do { hook->hk_flags |= HK_QUEUE; } while (0)
end_define

begin_comment
comment|/* Some shortcuts */
end_comment

begin_define
define|#
directive|define
name|NG_PEER_NODE
parameter_list|(
name|hook
parameter_list|)
value|NG_HOOK_NODE(NG_HOOK_PEER(hook))
end_define

begin_define
define|#
directive|define
name|NG_PEER_HOOK_NAME
parameter_list|(
name|hook
parameter_list|)
value|NG_HOOK_NAME(NG_HOOK_PEER(hook))
end_define

begin_define
define|#
directive|define
name|NG_PEER_NODE_NAME
parameter_list|(
name|hook
parameter_list|)
value|NG_NODE_NAME(NG_PEER_NODE(hook))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
end_ifdef

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|_NN_
value|__FILE__,__LINE__
end_define

begin_function_decl
name|void
name|dumphook
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_chkhook
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_ref
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|char
modifier|*
name|_ng_hook_name
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_unref
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_set_private
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_set_rcvmsg
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|ng_rcvmsg_t
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_set_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|ng_rcvdata_t
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|_ng_hook_private
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_hook_not_valid
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_hook_is_valid
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|node_p
name|_ng_hook_node
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|hook_p
name|_ng_hook_peer
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_force_writer
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_hook_force_queue
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|__inline
name|_chkhook
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
if|if
condition|(
name|hook
operator|->
name|hk_magic
operator|!=
name|HK_MAGIC
condition|)
block|{
name|printf
argument_list|(
literal|"Accessing freed hook "
argument_list|)
expr_stmt|;
name|dumphook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
name|hook
operator|->
name|lastline
operator|=
name|line
expr_stmt|;
name|hook
operator|->
name|lastfile
operator|=
name|file
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_ref
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_REF
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|char
modifier|*
name|_ng_hook_name
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_NAME
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_unref
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_UNREF
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_set_private
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_SET_PRIVATE
argument_list|(
name|hook
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_set_rcvmsg
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|ng_rcvmsg_t
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_SET_RCVMSG
argument_list|(
name|hook
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_set_rcvdata
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|ng_rcvdata_t
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_SET_RCVDATA
argument_list|(
name|hook
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|_ng_hook_private
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_PRIVATE
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_hook_not_valid
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_NOT_VALID
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_hook_is_valid
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_IS_VALID
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|node_p
name|_ng_hook_node
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_NODE
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|hook_p
name|_ng_hook_peer
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_HOOK_PEER
argument_list|(
name|hook
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_force_writer
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_FORCE_WRITER
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_hook_force_queue
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chkhook
argument_list|(
name|hook
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_HOOK_FORCE_QUEUE
argument_list|(
name|hook
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|NG_HOOK_REF
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_ref(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NAME
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_name(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_UNREF
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_unref(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_PRIVATE
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_ng_hook_set_private(hook, val, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_RCVMSG
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_ng_hook_set_rcvmsg(hook, val, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_RCVDATA
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_ng_hook_set_rcvdata(hook, val, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_PRIVATE
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_private(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NOT_VALID
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_not_valid(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_IS_VALID
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_is_valid(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NODE
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_node(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_PEER
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_peer(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_FORCE_WRITER
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_force_writer(hook, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_FORCE_QUEUE
parameter_list|(
name|hook
parameter_list|)
value|_ng_hook_force_queue(hook, _NN_)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_HOOK_REF
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_REF(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NAME
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_NAME(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_UNREF
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_UNREF(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_PRIVATE
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_NG_HOOK_SET_PRIVATE(hook, val)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_RCVMSG
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_NG_HOOK_SET_RCVMSG(hook, val)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_SET_RCVDATA
parameter_list|(
name|hook
parameter_list|,
name|val
parameter_list|)
value|_NG_HOOK_SET_RCVDATA(hook, val)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_PRIVATE
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_PRIVATE(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NOT_VALID
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_NOT_VALID(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_IS_VALID
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_IS_VALID(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_NODE
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_NODE(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_PEER
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_PEER(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_FORCE_WRITER
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_FORCE_WRITER(hook)
end_define

begin_define
define|#
directive|define
name|NG_HOOK_FORCE_QUEUE
parameter_list|(
name|hook
parameter_list|)
value|_NG_HOOK_FORCE_QUEUE(hook)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_comment
comment|/***********************************************************************  ***************** Node Structure and Methods **************************  ***********************************************************************  * Structure of a node  * including the eembedded queue structure.  *  * The structure for queueing Netgraph request items   * embedded in the node structure  */
end_comment

begin_struct
struct|struct
name|ng_queue
block|{
name|u_long
name|q_flags
decl_stmt|;
name|struct
name|mtx
name|q_mtx
decl_stmt|;
name|item_p
name|queue
decl_stmt|;
name|item_p
modifier|*
name|last
decl_stmt|;
name|struct
name|ng_node
modifier|*
name|q_node
decl_stmt|;
comment|/* find the front of the node.. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ng_node
block|{
name|char
name|nd_name
index|[
name|NG_NODELEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* optional globally unique name */
name|struct
name|ng_type
modifier|*
name|nd_type
decl_stmt|;
comment|/* the installed 'type' */
name|int
name|nd_flags
decl_stmt|;
comment|/* see below for bit definitions */
name|int
name|nd_refs
decl_stmt|;
comment|/* # of references to this node */
name|int
name|nd_numhooks
decl_stmt|;
comment|/* number of hooks */
name|void
modifier|*
name|nd_private
decl_stmt|;
comment|/* node type dependant node ID */
name|ng_ID_t
name|nd_ID
decl_stmt|;
comment|/* Unique per node */
name|LIST_HEAD
argument_list|(
argument|hooks
argument_list|,
argument|ng_hook
argument_list|)
name|nd_hooks
expr_stmt|;
comment|/* linked list of node hooks */
name|LIST_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|nd_nodes
expr_stmt|;
comment|/* linked list of all nodes */
name|LIST_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|nd_idnodes
expr_stmt|;
comment|/* ID hash collision list */
name|TAILQ_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|nd_work
expr_stmt|;
comment|/* nodes with work to do */
name|struct
name|ng_queue
name|nd_input_queue
decl_stmt|;
comment|/* input queue for locking */
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
comment|/*----------------------------------------------*/
define|#
directive|define
name|ND_MAGIC
value|0x59264837
name|int
name|nd_magic
decl_stmt|;
name|char
modifier|*
name|lastfile
decl_stmt|;
name|int
name|lastline
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|nd_all
expr_stmt|;
comment|/* all existing nodes */
endif|#
directive|endif
comment|/* NETGRAPH_DEBUG */
comment|/*----------------------------------------------*/
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for a node */
end_comment

begin_define
define|#
directive|define
name|NG_INVALID
value|0x00000001
end_define

begin_comment
comment|/* free when refs go to 0 */
end_comment

begin_define
define|#
directive|define
name|NG_WORKQ
value|0x00000002
end_define

begin_comment
comment|/* node is on the work queue */
end_comment

begin_define
define|#
directive|define
name|NG_FORCE_WRITER
value|0x00000004
end_define

begin_comment
comment|/* Never multithread this node */
end_comment

begin_define
define|#
directive|define
name|NG_CLOSING
value|0x00000008
end_define

begin_comment
comment|/* ng_rmnode() at work */
end_comment

begin_define
define|#
directive|define
name|NG_REALLY_DIE
value|0x00000010
end_define

begin_comment
comment|/* "persistant" node is unloading */
end_comment

begin_define
define|#
directive|define
name|NGF_TYPE1
value|0x10000000
end_define

begin_comment
comment|/* reserved for type specific storage */
end_comment

begin_define
define|#
directive|define
name|NGF_TYPE2
value|0x20000000
end_define

begin_comment
comment|/* reserved for type specific storage */
end_comment

begin_define
define|#
directive|define
name|NGF_TYPE3
value|0x40000000
end_define

begin_comment
comment|/* reserved for type specific storage */
end_comment

begin_define
define|#
directive|define
name|NGF_TYPE4
value|0x80000000
end_define

begin_comment
comment|/* reserved for type specific storage */
end_comment

begin_comment
comment|/*  * Public methods for nodes.  * If you can't do it with these you probably shouldn't be doing it.  */
end_comment

begin_function_decl
name|int
name|ng_unref_node
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* don't move this */
end_comment

begin_define
define|#
directive|define
name|_NG_NODE_NAME
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_name + 0)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_HAS_NAME
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_name[0] + 0)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_ID
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_ID + 0)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_REF
parameter_list|(
name|node
parameter_list|)
value|atomic_add_int(&(node)->nd_refs, 1)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_UNREF
parameter_list|(
name|node
parameter_list|)
value|ng_unref_node(node)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_SET_PRIVATE
parameter_list|(
name|node
parameter_list|,
name|val
parameter_list|)
value|do {(node)->nd_private = val;} while (0)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_PRIVATE
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_private)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_IS_VALID
parameter_list|(
name|node
parameter_list|)
value|(!((node)->nd_flags& NG_INVALID))
end_define

begin_define
define|#
directive|define
name|_NG_NODE_NOT_VALID
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_flags& NG_INVALID)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_NUMHOOKS
parameter_list|(
name|node
parameter_list|)
value|((node)->nd_numhooks + 0)
end_define

begin_comment
comment|/* rvalue */
end_comment

begin_define
define|#
directive|define
name|_NG_NODE_FORCE_WRITER
parameter_list|(
name|node
parameter_list|)
define|\
value|do{ node->nd_flags |= NG_FORCE_WRITER; }while (0)
end_define

begin_define
define|#
directive|define
name|_NG_NODE_REALLY_DIE
parameter_list|(
name|node
parameter_list|)
define|\
value|do{ node->nd_flags |= (NG_REALLY_DIE|NG_INVALID); }while (0)
end_define

begin_comment
comment|/*  * The hook iterator.  * This macro will call a function of type ng_fn_eachhook for each  * hook attached to the node. If the function returns 0, then the  * iterator will stop and return a pointer to the hook that returned 0.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ng_fn_eachhook
parameter_list|(
name|hook_p
name|hook
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|_NG_NODE_FOREACH_HOOK
parameter_list|(
name|node
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|rethook
parameter_list|)
define|\
value|do {								\ 		hook_p hook;						\ 		LIST_FOREACH(hook,&((node)->nd_hooks), hk_hooks) {	\ 			if ((fn)(hook, arg) == 0) {			\ 				(rethook) = hook;			\ 				break;					\ 			}						\ 		}							\ 	} while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
end_ifdef

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_function_decl
name|void
name|dumpnode
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|__inline
name|_chknode
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|char
modifier|*
name|_ng_node_name
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_node_has_name
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|ng_ID_t
name|_ng_node_id
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_ref_node
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_node_ref
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_node_unref
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_node_set_private
parameter_list|(
name|node_p
name|node
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
name|_ng_node_private
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_node_is_valid
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_node_not_valid
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
name|_ng_node_numhooks
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ng_node_force_writer
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|hook_p
name|_ng_node_foreach_hook
parameter_list|(
name|node_p
name|node
parameter_list|,
name|ng_fn_eachhook
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|void
name|__inline
name|_chknode
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
if|if
condition|(
name|node
operator|->
name|nd_magic
operator|!=
name|ND_MAGIC
condition|)
block|{
name|printf
argument_list|(
literal|"Accessing freed node "
argument_list|)
expr_stmt|;
name|dumpnode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
block|}
name|node
operator|->
name|lastline
operator|=
name|line
expr_stmt|;
name|node
operator|->
name|lastfile
operator|=
name|file
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|char
modifier|*
name|_ng_node_name
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_NAME
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_node_has_name
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_HAS_NAME
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|ng_ID_t
name|_ng_node_id
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_ID
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_node_ref
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
comment|/*_NG_NODE_REF(node);*/
name|ng_ref_node
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_node_unref
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_UNREF
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_node_set_private
parameter_list|(
name|node_p
name|node
parameter_list|,
name|void
modifier|*
name|val
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_NODE_SET_PRIVATE
argument_list|(
name|node
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
name|_ng_node_private
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_PRIVATE
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_node_is_valid
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_IS_VALID
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_node_not_valid
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_NOT_VALID
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|_ng_node_numhooks
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NG_NODE_NUMHOOKS
argument_list|(
name|node
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_node_force_writer
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_NODE_FORCE_WRITER
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|_ng_node_really_die
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_NODE_REALLY_DIE
argument_list|(
name|node
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|hook_p
name|_ng_node_foreach_hook
parameter_list|(
name|node_p
name|node
parameter_list|,
name|ng_fn_eachhook
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|hook_p
name|hook
decl_stmt|;
name|_chknode
argument_list|(
name|node
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|_NG_NODE_FOREACH_HOOK
argument_list|(
name|node
argument_list|,
name|fn
argument_list|,
name|arg
argument_list|,
name|hook
argument_list|)
expr_stmt|;
return|return
operator|(
name|hook
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NG_NODE_NAME
parameter_list|(
name|node
parameter_list|)
value|_ng_node_name(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_HAS_NAME
parameter_list|(
name|node
parameter_list|)
value|_ng_node_has_name(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_ID
parameter_list|(
name|node
parameter_list|)
value|_ng_node_id(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_REF
parameter_list|(
name|node
parameter_list|)
value|_ng_node_ref(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_UNREF
parameter_list|(
name|node
parameter_list|)
value|_ng_node_unref(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_SET_PRIVATE
parameter_list|(
name|node
parameter_list|,
name|val
parameter_list|)
value|_ng_node_set_private(node, val, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_PRIVATE
parameter_list|(
name|node
parameter_list|)
value|_ng_node_private(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_IS_VALID
parameter_list|(
name|node
parameter_list|)
value|_ng_node_is_valid(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_NOT_VALID
parameter_list|(
name|node
parameter_list|)
value|_ng_node_not_valid(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_FORCE_WRITER
parameter_list|(
name|node
parameter_list|)
value|_ng_node_force_writer(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_REALLY_DIE
parameter_list|(
name|node
parameter_list|)
value|_ng_node_really_die(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_NUMHOOKS
parameter_list|(
name|node
parameter_list|)
value|_ng_node_numhooks(node, _NN_)
end_define

begin_define
define|#
directive|define
name|NG_NODE_FOREACH_HOOK
parameter_list|(
name|node
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|rethook
parameter_list|)
define|\
value|do {								      \ 		rethook = _ng_node_foreach_hook(node, fn, (void *)arg, _NN_); \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NG_NODE_NAME
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_NAME(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_HAS_NAME
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_HAS_NAME(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_ID
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_ID(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_REF
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_REF(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_UNREF
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_UNREF(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_SET_PRIVATE
parameter_list|(
name|node
parameter_list|,
name|val
parameter_list|)
value|_NG_NODE_SET_PRIVATE(node, val)
end_define

begin_define
define|#
directive|define
name|NG_NODE_PRIVATE
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_PRIVATE(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_IS_VALID
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_IS_VALID(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_NOT_VALID
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_NOT_VALID(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_FORCE_WRITER
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_FORCE_WRITER(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_REALLY_DIE
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_REALLY_DIE(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_NUMHOOKS
parameter_list|(
name|node
parameter_list|)
value|_NG_NODE_NUMHOOKS(node)
end_define

begin_define
define|#
directive|define
name|NG_NODE_FOREACH_HOOK
parameter_list|(
name|node
parameter_list|,
name|fn
parameter_list|,
name|arg
parameter_list|,
name|rethook
parameter_list|)
define|\
value|_NG_NODE_FOREACH_HOOK(node, fn, arg, rethook)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_comment
comment|/***********************************************************************  ***************** Meta Data Structures and Methods ********************  ***********************************************************************  *  * The structure that holds meta_data about a data packet (e.g. priority)  * Nodes might add or subtract options as needed if there is room.  * They might reallocate the struct to make more room if they need to.  * Meta-data is still experimental.  */
end_comment

begin_struct
struct|struct
name|meta_field_header
block|{
name|u_long
name|cookie
decl_stmt|;
comment|/* cookie for the field. Skip fields you don't 				 * know about (same cookie as in messgaes) */
name|u_short
name|type
decl_stmt|;
comment|/* field ID */
name|u_short
name|len
decl_stmt|;
comment|/* total len of this field including extra 				 * data */
name|char
name|data
index|[
literal|0
index|]
decl_stmt|;
comment|/* data starts here */
block|}
struct|;
end_struct

begin_comment
comment|/* To zero out an option 'in place' set it's cookie to this */
end_comment

begin_define
define|#
directive|define
name|NGM_INVALID_COOKIE
value|865455152
end_define

begin_comment
comment|/* This part of the metadata is always present if the pointer is non NULL */
end_comment

begin_struct
struct|struct
name|ng_meta
block|{
name|char
name|priority
decl_stmt|;
comment|/* -ve is less priority,  0 is default */
name|char
name|discardability
decl_stmt|;
comment|/* higher is less valuable.. discard first */
name|u_short
name|allocated_len
decl_stmt|;
comment|/* amount malloc'd */
name|u_short
name|used_len
decl_stmt|;
comment|/* sum of all fields, options etc. */
name|u_short
name|flags
decl_stmt|;
comment|/* see below.. generic flags */
name|struct
name|meta_field_header
name|options
index|[
literal|0
index|]
decl_stmt|;
comment|/* add as (if) needed */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_meta
modifier|*
name|meta_p
typedef|;
end_typedef

begin_comment
comment|/* Flags for meta-data */
end_comment

begin_define
define|#
directive|define
name|NGMF_TEST
value|0x01
end_define

begin_comment
comment|/* discard at the last moment before sending */
end_comment

begin_define
define|#
directive|define
name|NGMF_TRACE
value|0x02
end_define

begin_comment
comment|/* trace when handing this data to a node */
end_comment

begin_comment
comment|/***********************************************************************  ************* Node Queue and Item Structures and Methods **************  ***********************************************************************  *  */
end_comment

begin_typedef
typedef|typedef
name|void
name|ng_item_fn
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|int
name|arg2
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ng_item
block|{
name|u_long
name|el_flags
decl_stmt|;
name|item_p
name|el_next
decl_stmt|;
name|node_p
name|el_dest
decl_stmt|;
comment|/* The node it will be applied against (or NULL) */
name|hook_p
name|el_hook
decl_stmt|;
comment|/* Entering hook. Optional in Control messages */
union|union
block|{
struct|struct
block|{
name|struct
name|mbuf
modifier|*
name|da_m
decl_stmt|;
name|meta_p
name|da_meta
decl_stmt|;
block|}
name|data
struct|;
struct|struct
block|{
name|struct
name|ng_mesg
modifier|*
name|msg_msg
decl_stmt|;
name|ng_ID_t
name|msg_retaddr
decl_stmt|;
block|}
name|msg
struct|;
struct|struct
block|{
name|ng_item_fn
modifier|*
name|fn_fn
decl_stmt|;
name|void
modifier|*
name|fn_arg1
decl_stmt|;
name|int
name|fn_arg2
decl_stmt|;
block|}
name|fn
struct|;
block|}
name|body
union|;
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
comment|/*----------------------------------------------*/
name|char
modifier|*
name|lastfile
decl_stmt|;
name|int
name|lastline
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|ng_item
argument_list|)
name|all
expr_stmt|;
comment|/* all existing items */
endif|#
directive|endif
comment|/* NETGRAPH_DEBUG */
comment|/*----------------------------------------------*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGQF_TYPE
value|0x03
end_define

begin_comment
comment|/* MASK of content definition */
end_comment

begin_define
define|#
directive|define
name|NGQF_MESG
value|0x00
end_define

begin_comment
comment|/* the queue element is a message */
end_comment

begin_define
define|#
directive|define
name|NGQF_DATA
value|0x01
end_define

begin_comment
comment|/* the queue element is data */
end_comment

begin_define
define|#
directive|define
name|NGQF_FN
value|0x02
end_define

begin_comment
comment|/* the queue element is a function */
end_comment

begin_define
define|#
directive|define
name|NGQF_UNDEF
value|0x03
end_define

begin_comment
comment|/* UNDEFINED */
end_comment

begin_define
define|#
directive|define
name|NGQF_RW
value|0x04
end_define

begin_comment
comment|/* MASK for queue entry read/write */
end_comment

begin_define
define|#
directive|define
name|NGQF_READER
value|0x04
end_define

begin_comment
comment|/* queued as a reader */
end_comment

begin_define
define|#
directive|define
name|NGQF_WRITER
value|0x00
end_define

begin_comment
comment|/* queued as a writer */
end_comment

begin_define
define|#
directive|define
name|NGQF_FREE
value|0x08
end_define

begin_comment
comment|/*  * Get the mbuf (etc) out of an item.  * Sets the value in the item to NULL in case we need to call NG_FREE_ITEM()  * with it, (to avoid freeing the things twice).  * If you don't want to zero out the item then realise that the  * item still owns it.  * Retaddr is different. There are no references on that. It's just a number.  * The debug versions must be either all used everywhere or not at all.  */
end_comment

begin_define
define|#
directive|define
name|_NGI_M
parameter_list|(
name|i
parameter_list|)
value|((i)->body.data.da_m)
end_define

begin_define
define|#
directive|define
name|_NGI_META
parameter_list|(
name|i
parameter_list|)
value|((i)->body.data.da_meta)
end_define

begin_define
define|#
directive|define
name|_NGI_MSG
parameter_list|(
name|i
parameter_list|)
value|((i)->body.msg.msg_msg)
end_define

begin_define
define|#
directive|define
name|_NGI_RETADDR
parameter_list|(
name|i
parameter_list|)
value|((i)->body.msg.msg_retaddr)
end_define

begin_define
define|#
directive|define
name|_NGI_FN
parameter_list|(
name|i
parameter_list|)
value|((i)->body.fn.fn_fn)
end_define

begin_define
define|#
directive|define
name|_NGI_ARG1
parameter_list|(
name|i
parameter_list|)
value|((i)->body.fn.fn_arg1)
end_define

begin_define
define|#
directive|define
name|_NGI_ARG2
parameter_list|(
name|i
parameter_list|)
value|((i)->body.fn.fn_arg2)
end_define

begin_define
define|#
directive|define
name|_NGI_NODE
parameter_list|(
name|i
parameter_list|)
value|((i)->el_dest)
end_define

begin_define
define|#
directive|define
name|_NGI_HOOK
parameter_list|(
name|i
parameter_list|)
value|((i)->el_hook)
end_define

begin_define
define|#
directive|define
name|_NGI_SET_HOOK
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|do { _NGI_HOOK(i) = h; h = NULL;} while (0)
end_define

begin_define
define|#
directive|define
name|_NGI_CLR_HOOK
parameter_list|(
name|i
parameter_list|)
value|do {						\ 		hook_p hook = _NGI_HOOK(i);				\ 		if (hook) {						\ 			_NG_HOOK_UNREF(hook);				\ 			_NGI_HOOK(i) = NULL;				\ 		}							\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|_NGI_SET_NODE
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|do { _NGI_NODE(i) = n; n = NULL;} while (0)
end_define

begin_define
define|#
directive|define
name|_NGI_CLR_NODE
parameter_list|(
name|i
parameter_list|)
value|do {						\ 		node_p node = _NGI_NODE(i);				\ 		if (node) {						\ 			_NG_NODE_UNREF(node);				\ 			_NGI_NODE(i) = NULL;				\ 		}							\ 	} while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NETGRAPH_DEBUG
end_ifdef

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_function_decl
name|void
name|dumpitem
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
name|_ngi_check
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
operator|*
name|_ngi_m
argument_list|(
argument|item_p item
argument_list|,
argument|char *file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|__inline
name|meta_p
modifier|*
name|_ngi_meta
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|ng_ID_t
modifier|*
name|_ngi_retaddr
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ng_mesg
operator|*
operator|*
name|_ngi_msg
argument_list|(
argument|item_p item
argument_list|,
argument|char *file
argument_list|,
argument|int line
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|static
name|__inline
name|ng_item_fn
modifier|*
modifier|*
name|_ngi_fn
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|void
modifier|*
modifier|*
name|_ngi_arg1
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|int
modifier|*
name|_ngi_arg2
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|node_p
name|_ngi_node
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|__inline
name|hook_p
name|_ngi_hook
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|_ngi_check
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
if|if
condition|(
name|item
operator|->
name|el_flags
operator|&
name|NGQF_FREE
condition|)
block|{
name|dumpitem
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|panic
argument_list|(
literal|"free item!"
argument_list|)
expr_stmt|;
block|}
operator|(
name|item
operator|)
operator|->
name|lastline
operator|=
name|line
expr_stmt|;
operator|(
name|item
operator|)
operator|->
name|lastfile
operator|=
name|file
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|mbuf
operator|*
operator|*
name|_ngi_m
argument_list|(
argument|item_p item
argument_list|,
argument|char *file
argument_list|,
argument|int line
argument_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
block|;
return|return
operator|(
operator|&
name|_NGI_M
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|meta_p
modifier|*
name|_ngi_meta
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|_NGI_META
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|ng_mesg
operator|*
operator|*
name|_ngi_msg
argument_list|(
argument|item_p item
argument_list|,
argument|char *file
argument_list|,
argument|int line
argument_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
block|;
return|return
operator|(
operator|&
name|_NGI_MSG
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|__inline
name|ng_ID_t
modifier|*
name|_ngi_retaddr
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|_NGI_RETADDR
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|ng_item_fn
modifier|*
modifier|*
name|_ngi_fn
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|_NGI_FN
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
modifier|*
modifier|*
name|_ngi_arg1
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|_NGI_ARG1
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
modifier|*
name|_ngi_arg2
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
operator|&
name|_NGI_ARG2
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|node_p
name|_ngi_node
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NGI_NODE
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|hook_p
name|_ngi_hook
parameter_list|(
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|line
parameter_list|)
block|{
name|_ngi_check
argument_list|(
name|item
argument_list|,
name|file
argument_list|,
name|line
argument_list|)
expr_stmt|;
return|return
operator|(
name|_NGI_HOOK
argument_list|(
name|item
argument_list|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|NGI_M
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_m(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_META
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_meta(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_MSG
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_msg(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_RETADDR
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_retaddr(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_FN
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_fn(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_ARG1
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_arg1(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_ARG2
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_arg2(i, _NN_))
end_define

begin_define
define|#
directive|define
name|NGI_HOOK
parameter_list|(
name|i
parameter_list|)
value|_ngi_hook(i, _NN_)
end_define

begin_define
define|#
directive|define
name|NGI_NODE
parameter_list|(
name|i
parameter_list|)
value|_ngi_node(i, _NN_)
end_define

begin_define
define|#
directive|define
name|NGI_SET_HOOK
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
define|\
value|do { _ngi_check(i, _NN_); _NGI_SET_HOOK(i, h); } while (0)
end_define

begin_define
define|#
directive|define
name|NGI_CLR_HOOK
parameter_list|(
name|i
parameter_list|)
define|\
value|do { _ngi_check(i, _NN_); _NGI_CLR_HOOK(i); } while (0)
end_define

begin_define
define|#
directive|define
name|NGI_SET_NODE
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
define|\
value|do { _ngi_check(i, _NN_); _NGI_SET_NODE(i, n); } while (0)
end_define

begin_define
define|#
directive|define
name|NGI_CLR_NODE
parameter_list|(
name|i
parameter_list|)
define|\
value|do { _ngi_check(i, _NN_); _NGI_CLR_NODE(i); } while (0)
end_define

begin_define
define|#
directive|define
name|NG_FREE_ITEM
parameter_list|(
name|item
parameter_list|)
define|\
value|do {								\ 		_ngi_check(item, _NN_);					\ 		ng_free_item((item));					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|SAVE_LINE
parameter_list|(
name|item
parameter_list|)
define|\
value|do {								\ 		(item)->lastline = __LINE__;				\ 		(item)->lastfile = __FILE__;				\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NGI_M
parameter_list|(
name|i
parameter_list|)
value|_NGI_M(i)
end_define

begin_define
define|#
directive|define
name|NGI_META
parameter_list|(
name|i
parameter_list|)
value|_NGI_META(i)
end_define

begin_define
define|#
directive|define
name|NGI_MSG
parameter_list|(
name|i
parameter_list|)
value|_NGI_MSG(i)
end_define

begin_define
define|#
directive|define
name|NGI_RETADDR
parameter_list|(
name|i
parameter_list|)
value|_NGI_RETADDR(i)
end_define

begin_define
define|#
directive|define
name|NGI_FN
parameter_list|(
name|i
parameter_list|)
value|_NGI_FN(i)
end_define

begin_define
define|#
directive|define
name|NGI_ARG1
parameter_list|(
name|i
parameter_list|)
value|_NGI_ARG1(i)
end_define

begin_define
define|#
directive|define
name|NGI_ARG2
parameter_list|(
name|i
parameter_list|)
value|_NGI_ARG2(i)
end_define

begin_define
define|#
directive|define
name|NGI_NODE
parameter_list|(
name|i
parameter_list|)
value|_NGI_NODE(i)
end_define

begin_define
define|#
directive|define
name|NGI_HOOK
parameter_list|(
name|i
parameter_list|)
value|_NGI_HOOK(i)
end_define

begin_define
define|#
directive|define
name|NGI_SET_HOOK
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
value|_NGI_SET_HOOK(i,h)
end_define

begin_define
define|#
directive|define
name|NGI_CLR_HOOK
parameter_list|(
name|i
parameter_list|)
value|_NGI_CLR_HOOK(i)
end_define

begin_define
define|#
directive|define
name|NGI_SET_NODE
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
value|_NGI_SET_NODE(i,n)
end_define

begin_define
define|#
directive|define
name|NGI_CLR_NODE
parameter_list|(
name|i
parameter_list|)
value|_NGI_CLR_NODE(i)
end_define

begin_define
define|#
directive|define
name|NG_FREE_ITEM
parameter_list|(
name|item
parameter_list|)
value|ng_free_item((item))
end_define

begin_define
define|#
directive|define
name|SAVE_LINE
parameter_list|(
name|item
parameter_list|)
value|do {} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NETGRAPH_DEBUG */
end_comment

begin_comment
comment|/*----------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|NGI_GET_M
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		(m) = NGI_M(i);						\ 		_NGI_M(i) = NULL;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NGI_GET_META
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		(m) = NGI_META(i);					\ 		_NGI_META(i) = NULL;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NGI_GET_MSG
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		(m) = NGI_MSG(i);					\ 		_NGI_MSG(i) = NULL;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NGI_GET_NODE
parameter_list|(
name|i
parameter_list|,
name|n
parameter_list|)
comment|/* YOU NOW HAVE THE REFERENCE */
define|\
value|do {								\ 		(n) = NGI_NODE(i);					\ 		_NGI_NODE(i) = NULL;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NGI_GET_HOOK
parameter_list|(
name|i
parameter_list|,
name|h
parameter_list|)
define|\
value|do {								\ 		(h) = NGI_HOOK(i);					\ 		_NGI_HOOK(i) = NULL;					\ 	} while (0)
end_define

begin_comment
comment|/********************************************************************** * Data macros.  Send, manipulate and free. **********************************************************************/
end_comment

begin_comment
comment|/*  * Assuming the data is already ok, just set the new address and send  */
end_comment

begin_define
define|#
directive|define
name|NG_FWD_ITEM_HOOK
parameter_list|(
name|error
parameter_list|,
name|item
parameter_list|,
name|hook
parameter_list|)
define|\
value|do {								\ 		(error) =						\ 		    ng_address_hook(NULL, (item), (hook), NULL);	\ 		if (error == 0) {					\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(item) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/*  * Forward a data packet with no new meta-data.  * old metadata is passed along without change.  * Mbuf pointer is updated to new value. We presume you dealt with the  * old one when you update it to the new one (or it maybe the old one).  * We got a packet and possibly had to modify the mbuf.  * You should probably use NGI_GET_M() if you are going to use this too  */
end_comment

begin_define
define|#
directive|define
name|NG_FWD_NEW_DATA
parameter_list|(
name|error
parameter_list|,
name|item
parameter_list|,
name|hook
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		NGI_M(item) = (m);					\ 		(m) = NULL;						\ 		NG_FWD_ITEM_HOOK(error, item, hook);			\ 	} while (0)
end_define

begin_comment
comment|/* Send a previously unpackaged mbuf when we have no metadata to send */
end_comment

begin_define
define|#
directive|define
name|NG_SEND_DATA_ONLY
parameter_list|(
name|error
parameter_list|,
name|hook
parameter_list|,
name|m
parameter_list|)
define|\
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_data((m), NULL))) {		\ 			NG_FWD_ITEM_HOOK(error, item, hook);		\ 		} else {						\ 			(error) = ENOMEM;				\ 		}							\ 		(m) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/* Send previously unpackeged data and metadata. */
end_comment

begin_define
define|#
directive|define
name|NG_SEND_DATA
parameter_list|(
name|error
parameter_list|,
name|hook
parameter_list|,
name|m
parameter_list|,
name|meta
parameter_list|)
define|\
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_data((m), (meta)))) {		\ 			NG_FWD_ITEM_HOOK(error, item, hook);		\ 		} else {						\ 			(error) = ENOMEM;				\ 		}							\ 		(m) = NULL;						\ 		(meta) = NULL;						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_FREE_MSG
parameter_list|(
name|msg
parameter_list|)
define|\
value|do {								\ 		if ((msg)) {						\ 			FREE((msg), M_NETGRAPH_MSG);			\ 			(msg) = NULL;					\ 		}	 						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_FREE_META
parameter_list|(
name|meta
parameter_list|)
define|\
value|do {								\ 		if ((meta)) {						\ 			FREE((meta), M_NETGRAPH_META);			\ 			(meta) = NULL;					\ 		}	 						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_FREE_M
parameter_list|(
name|m
parameter_list|)
define|\
value|do {								\ 		if ((m)) {						\ 			m_freem((m));					\ 			(m) = NULL;					\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/***************************************** * Message macros *****************************************/
end_comment

begin_define
define|#
directive|define
name|NG_SEND_MSG_HOOK
parameter_list|(
name|error
parameter_list|,
name|here
parameter_list|,
name|msg
parameter_list|,
name|hook
parameter_list|,
name|retaddr
parameter_list|)
define|\
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg)) == NULL) {		\ 			(msg) = NULL;					\ 			(error) = ENOMEM;				\ 			break;						\ 		}							\ 		if (((error) = ng_address_hook((here), (item),		\ 					(hook), (retaddr))) == 0) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_SEND_MSG_PATH
parameter_list|(
name|error
parameter_list|,
name|here
parameter_list|,
name|msg
parameter_list|,
name|path
parameter_list|,
name|retaddr
parameter_list|)
define|\
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg)) == NULL) {		\ 			(msg) = NULL;					\ 			(error) = ENOMEM;				\ 			break;						\ 		}							\ 		if (((error) = ng_address_path((here), (item),		\ 					(path), (retaddr))) == 0) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_SEND_MSG_ID
parameter_list|(
name|error
parameter_list|,
name|here
parameter_list|,
name|msg
parameter_list|,
name|ID
parameter_list|,
name|retaddr
parameter_list|)
define|\
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg)) == NULL) {		\ 			(msg) = NULL;					\ 			(error) = ENOMEM;				\ 			break;						\ 		}							\ 		if (((error) = ng_address_ID((here), (item),		\ 					(ID), (retaddr))) == 0) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/*  * Redirect the message to the next hop using the given hook.  * ng_retarget_msg() frees the item if there is an error  * and returns an error code.  It returns 0 on success.  */
end_comment

begin_define
define|#
directive|define
name|NG_FWD_MSG_HOOK
parameter_list|(
name|error
parameter_list|,
name|here
parameter_list|,
name|item
parameter_list|,
name|hook
parameter_list|,
name|retaddr
parameter_list|)
define|\
value|do {								\ 		if (((error) = ng_address_hook((here), (item),		\ 					(hook), (retaddr))) == 0) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(item) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/*  * Send a queue item back to it's originator with a response message.  * Assume original message was removed and freed separatly.  */
end_comment

begin_define
define|#
directive|define
name|NG_RESPOND_MSG
parameter_list|(
name|error
parameter_list|,
name|here
parameter_list|,
name|item
parameter_list|,
name|resp
parameter_list|)
define|\
value|do {								\ 		if (resp) {						\ 			ng_ID_t dest = NGI_RETADDR(item);		\ 			NGI_RETADDR(item) = NULL;			\ 			NGI_MSG(item) = resp;				\ 			if ((ng_address_ID((here), (item),		\ 					dest, NULL )) == 0) {		\ 				SAVE_LINE(item);			\ 				(error) = ng_snd_item((item), 1);	\ 			} else {					\ 				(error) = EINVAL;			\ 			}						\ 		} else {						\ 			NG_FREE_ITEM(item);				\ 		}							\ 		(item) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/***********************************************************************  ******** Structures Definitions and Macros for defining a node  *******  ***********************************************************************  *   * Here we define the structures needed to actually define a new node  * type.  */
end_comment

begin_comment
comment|/*  * Command list -- each node type specifies the command that it knows  * how to convert between ASCII and binary using an array of these.  * The last element in the array must be a terminator with cookie=0.  */
end_comment

begin_struct
struct|struct
name|ng_cmdlist
block|{
name|u_int32_t
name|cookie
decl_stmt|;
comment|/* command typecookie */
name|int
name|cmd
decl_stmt|;
comment|/* command number */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* command name */
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|mesgType
decl_stmt|;
comment|/* args if !NGF_RESP */
specifier|const
name|struct
name|ng_parse_type
modifier|*
name|respType
decl_stmt|;
comment|/* args if NGF_RESP */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a node type  * If data is sent to the "rcvdata()" entrypoint then the system  * may decide to defer it until later by queing it with the normal netgraph  * input queuing system.  This is decidde by the HK_QUEUE flag being set in  * the flags word of the peer (receiving) hook. The dequeuing mechanism will  * ensure it is not requeued again.  * Note the input queueing system is to allow modules  * to 'release the stack' or to pass data across spl layers.  * The data will be redelivered as soon as the NETISR code runs  * which may be almost immediatly.  A node may also do it's own queueing  * for other reasons (e.g. device output queuing).  */
end_comment

begin_struct
struct|struct
name|ng_type
block|{
name|u_int32_t
name|version
decl_stmt|;
comment|/* must equal NG_API_VERSION */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Unique type name */
name|modeventhand_t
name|mod_event
decl_stmt|;
comment|/* Module event handler (optional) */
name|ng_constructor_t
modifier|*
name|constructor
decl_stmt|;
comment|/* Node constructor */
name|ng_rcvmsg_t
modifier|*
name|rcvmsg
decl_stmt|;
comment|/* control messages come here */
name|ng_shutdown_t
modifier|*
name|shutdown
decl_stmt|;
comment|/* reset, and free resources */
name|ng_newhook_t
modifier|*
name|newhook
decl_stmt|;
comment|/* first notification of new hook */
name|ng_findhook_t
modifier|*
name|findhook
decl_stmt|;
comment|/* only if you have lots of hooks */
name|ng_connect_t
modifier|*
name|connect
decl_stmt|;
comment|/* final notification of new hook */
name|ng_rcvdata_t
modifier|*
name|rcvdata
decl_stmt|;
comment|/* data comes here */
name|ng_disconnect_t
modifier|*
name|disconnect
decl_stmt|;
comment|/* notify on disconnect */
specifier|const
name|struct
name|ng_cmdlist
modifier|*
name|cmdlist
decl_stmt|;
comment|/* commands we can convert */
comment|/* R/W data private to the base netgraph code DON'T TOUCH! */
name|LIST_ENTRY
argument_list|(
argument|ng_type
argument_list|)
name|types
expr_stmt|;
comment|/* linked list of all types */
name|int
name|refs
decl_stmt|;
comment|/* number of instances */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Use the NETGRAPH_INIT() macro to link a node type into the  * netgraph system. This works for types compiled into the kernel  * as well as KLD modules. The first argument should be the type  * name (eg, echo) and the second a pointer to the type struct.  *  * If a different link time is desired, e.g., a device driver that  * needs to install its netgraph type before probing, use the  * NETGRAPH_INIT_ORDERED() macro instead. Deivce drivers probably  * want to use SI_SUB_DRIVERS instead of SI_SUB_PSEUDO.  */
end_comment

begin_define
define|#
directive|define
name|NETGRAPH_INIT_ORDERED
parameter_list|(
name|typename
parameter_list|,
name|typestructp
parameter_list|,
name|sub
parameter_list|,
name|order
parameter_list|)
define|\
value|static moduledata_t ng_##typename##_mod = {				\ 	"ng_" #typename,						\ 	ng_mod_event,							\ 	(typestructp)							\ };									\ DECLARE_MODULE(ng_##typename, ng_##typename##_mod, sub, order);		\ MODULE_DEPEND(ng_##typename, netgraph,	NG_ABI_VERSION,			\ 					NG_ABI_VERSION,			\ 					NG_ABI_VERSION)
end_define

begin_define
define|#
directive|define
name|NETGRAPH_INIT
parameter_list|(
name|tn
parameter_list|,
name|tp
parameter_list|)
define|\
value|NETGRAPH_INIT_ORDERED(tn, tp, SI_SUB_PSEUDO, SI_ORDER_ANY)
end_define

begin_comment
comment|/* Special malloc() type for netgraph structs and ctrl messages */
end_comment

begin_comment
comment|/* Only these two types should be visible to nodes */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH_MSG
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH_META
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* declare the base of the netgraph sysclt hierarchy */
end_comment

begin_comment
comment|/* but only if this file cares about sysctls */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_net_graph
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Methods that the nodes can use.  * Many of these methods should usually NOT be used directly but via   * Macros above.  */
end_comment

begin_function_decl
name|int
name|ng_address_ID
parameter_list|(
name|node_p
name|here
parameter_list|,
name|item_p
name|item
parameter_list|,
name|ng_ID_t
name|ID
parameter_list|,
name|ng_ID_t
name|retaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_address_hook
parameter_list|(
name|node_p
name|here
parameter_list|,
name|item_p
name|item
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|ng_ID_t
name|retaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_address_path
parameter_list|(
name|node_p
name|here
parameter_list|,
name|item_p
name|item
parameter_list|,
name|char
modifier|*
name|address
parameter_list|,
name|ng_ID_t
name|raddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|meta_p
name|ng_copy_meta
parameter_list|(
name|meta_p
name|meta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|hook_p
name|ng_findhook
parameter_list|(
name|node_p
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_make_node_common
parameter_list|(
name|struct
name|ng_type
modifier|*
name|typep
parameter_list|,
name|node_p
modifier|*
name|nodep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_name_node
parameter_list|(
name|node_p
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_newtype
parameter_list|(
name|struct
name|ng_type
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ng_ID_t
name|ng_node2ID
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|item_p
name|ng_package_data
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|meta_p
name|meta
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|item_p
name|ng_package_msg
parameter_list|(
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|item_p
name|ng_package_msg_self
parameter_list|(
name|node_p
name|here
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_replace_retaddr
parameter_list|(
name|node_p
name|here
parameter_list|,
name|item_p
name|item
parameter_list|,
name|ng_ID_t
name|retaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_rmhook_self
parameter_list|(
name|hook_p
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if a node wants to kill a hook */
end_comment

begin_function_decl
name|int
name|ng_rmnode_self
parameter_list|(
name|node_p
name|here
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* if a node wants to suicide */
end_comment

begin_function_decl
name|int
name|ng_rmtype
parameter_list|(
name|struct
name|ng_type
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_snd_item
parameter_list|(
name|item_p
name|item
parameter_list|,
name|int
name|queue
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_send_fn
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|ng_item_fn
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|int
name|arg2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_untimeout
parameter_list|(
name|struct
name|callout_handle
name|handle
parameter_list|,
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|callout_handle
name|ng_timeout
parameter_list|(
name|node_p
name|node
parameter_list|,
name|hook_p
name|hook
parameter_list|,
name|int
name|ticks
parameter_list|,
name|ng_item_fn
modifier|*
name|fn
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|int
name|arg2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * prototypes the user should DEFINITLY not use directly  */
end_comment

begin_function_decl
name|void
name|ng_free_item
parameter_list|(
name|item_p
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use NG_FREE_ITEM instead */
end_comment

begin_function_decl
name|int
name|ng_mod_event
parameter_list|(
name|module_t
name|mod
parameter_list|,
name|int
name|what
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NETGRAPH_H_ */
end_comment

end_unit

