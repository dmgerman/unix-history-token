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

begin_include
include|#
directive|include
file|<sys/queue.h>
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
file|<sys/mutex.h>
end_include

begin_comment
comment|/* The structure for queueing across ISR switches */
end_comment

begin_struct_decl
struct_decl|struct
name|ng_item
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward reference */
end_comment

begin_typedef
typedef|typedef
name|struct
name|ng_item
modifier|*
name|item_p
typedef|;
end_typedef

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

begin_comment
comment|/*  * Structure of a hook  */
end_comment

begin_struct
struct|struct
name|ng_hook
block|{
name|char
name|name
index|[
name|NG_HOOKLEN
operator|+
literal|1
index|]
decl_stmt|;
comment|/* what this node knows this link as */
name|void
modifier|*
name|private
decl_stmt|;
comment|/* node dependant ID for this hook */
name|int
name|flags
decl_stmt|;
comment|/* info about this hook/link */
name|int
name|refs
decl_stmt|;
comment|/* dont actually free this till 0 */
name|struct
name|ng_hook
modifier|*
name|peer
decl_stmt|;
comment|/* the other end of this link */
name|struct
name|ng_node
modifier|*
name|node
decl_stmt|;
comment|/* The node this hook is attached to */
name|LIST_ENTRY
argument_list|(
argument|ng_hook
argument_list|)
name|hooks
expr_stmt|;
comment|/* linked list of all hooks on node */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_hook
modifier|*
name|hook_p
typedef|;
end_typedef

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

begin_comment
comment|/*  * Structure of a node  */
end_comment

begin_struct
struct|struct
name|ng_node
block|{
name|char
name|name
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
name|type
decl_stmt|;
comment|/* the installed 'type' */
name|int
name|flags
decl_stmt|;
comment|/* see below for bit definitions */
name|int
name|refs
decl_stmt|;
comment|/* number of references to this node */
name|int
name|numhooks
decl_stmt|;
comment|/* number of hooks */
name|void
modifier|*
name|private
decl_stmt|;
comment|/* node type dependant node ID */
name|ng_ID_t
name|ID
decl_stmt|;
comment|/* Unique per node */
name|LIST_HEAD
argument_list|(
argument|hooks
argument_list|,
argument|ng_hook
argument_list|)
name|hooks
expr_stmt|;
comment|/* linked list of node hooks */
name|LIST_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|nodes
expr_stmt|;
comment|/* linked list of all nodes */
name|LIST_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|idnodes
expr_stmt|;
comment|/* ID hash collision list */
name|TAILQ_ENTRY
argument_list|(
argument|ng_node
argument_list|)
name|work
expr_stmt|;
comment|/* nodes with work to do */
name|struct
name|ng_queue
name|input_queue
decl_stmt|;
comment|/* input queue for locking */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|ng_node
modifier|*
name|node_p
typedef|;
end_typedef

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
comment|/*  * The structure that holds meta_data about a data packet (e.g. priority)  * Nodes might add or subtract options as needed if there is room.  * They might reallocate the struct to make more room if they need to.  * Meta-data is still experimental.  */
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
block|}
name|body
union|;
define|#
directive|define
name|ITEM_DEBUG
ifdef|#
directive|ifdef
name|ITEM_DEBUG
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
comment|/* ITEM_DEBUG */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|NGQF_D_M
value|0x01
end_define

begin_comment
comment|/* MASK of data/message */
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
name|NGQF_MESG
value|0x00
end_define

begin_comment
comment|/* the queue element is a message */
end_comment

begin_define
define|#
directive|define
name|NGQF_TYPE
value|0x02
end_define

begin_comment
comment|/*  MASK for queue entry type */
end_comment

begin_define
define|#
directive|define
name|NGQF_READER
value|0x02
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
value|0x04
end_define

begin_comment
comment|/*  * This defines the in-kernel binary interface version.  * It is possible to change this but leave the external message  * API the same. Each type also has it's own cookies for versioning as well.  * Change it for ITEM_DEBUG version so we cannot mix debug and non debug  * modules.  */
end_comment

begin_define
define|#
directive|define
name|_NG_ABI_VERSION
value|5
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ITEM_DEBUG
end_ifdef

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
comment|/* ITEM_DEBUG */
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
comment|/* ITEM_DEBUG */
end_comment

begin_comment
comment|/********************************************************************** * Queue item macros.  Peek and extract values. **********************************************************************/
end_comment

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

begin_ifdef
ifdef|#
directive|ifdef
name|ITEM_DEBUG
end_ifdef

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

begin_define
define|#
directive|define
name|NGI_M
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_m(i, __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|NGI_META
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_meta(i, __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|NGI_MSG
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_msg(i, __FILE__, __LINE__))
end_define

begin_define
define|#
directive|define
name|NGI_RETADDR
parameter_list|(
name|i
parameter_list|)
value|(*_ngi_retaddr(i, __FILE__, __LINE__))
end_define

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
value|do {								\ 		m = NGI_M(i);						\ 		_NGI_M(i) = NULL;					\ 	} while (0)
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
value|do {								\ 		m = NGI_META(i);					\ 		_NGI_META(i) = NULL;					\ 	} while (0)
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
value|do {								\ 		m = NGI_MSG(i);						\ 		_NGI_MSG(i) = NULL;					\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_FREE_ITEM
parameter_list|(
name|item
parameter_list|)
define|\
value|do {								\ 		_ngi_check(item, __FILE__, __LINE__);			\ 		ng_free_item((item));					\ 	} while (0)
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
comment|/* ITEM_DEBUG */
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
name|NGI_GET_M
parameter_list|(
name|i
parameter_list|,
name|m
parameter_list|)
value|do {m = NGI_M(i); NGI_M(i) = NULL;      } while (0)
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
value|do {m = NGI_META(i); NGI_META(i) = NULL;} while (0)
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
value|do {m = NGI_MSG(i); NGI_MSG(i) = NULL;  } while (0)
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
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ITEM_DEBUG */
end_comment

begin_comment
comment|/********************************************************************** * Data macros.  Send, manipulate and free. **********************************************************************/
end_comment

begin_comment
comment|/* Send data packet including a possible sync response pointer */
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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_data((m), (meta)))) {		\ 			if (!((error) = ng_address_hook(NULL, item,	\ 							hook, NULL))) {	\ 				SAVE_LINE(item);			\ 				(error) = ng_snd_item((item), 0);	\ 			}						\ 		} else {						\ 			(error) = ENOMEM;				\ 		}							\ 		(m) = NULL;						\ 		(meta) = NULL;						\ 	} while (0)
end_define

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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_data((m), NULL))) {		\ 			if (!((error) = ng_address_hook(NULL, item,	\ 							hook, NULL))) {	\ 				SAVE_LINE(item);			\ 				(error) = ng_snd_item((item), 0);	\ 			}						\ 		} else {						\ 			(error) = ENOMEM;				\ 		}							\ 		(m) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/*  * Forward a data packet with no new meta-data.  * old metadata is passed along without change.  * Mbuf pointer is updated to new value.  */
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
value|do {								\ 		NGI_M(item) = m;					\ 		if (!((error) = ng_address_hook(NULL, (item),		\ 						(hook), NULL))) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		}							\ 		(item) = NULL;						\ 		(m) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/*  * Assuming the data is already ok, just set the new address and send  */
end_comment

begin_define
define|#
directive|define
name|NG_FWD_DATA
parameter_list|(
name|error
parameter_list|,
name|item
parameter_list|,
name|hook
parameter_list|)
define|\
value|do {								\ 		if (!((error) = ng_address_hook(NULL, (item),		\ 						(hook), NULL))) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = ENXIO;				\ 		}							\ 		(item) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/* Note that messages can be static (e.g. in ng_rmnode_self()) */
end_comment

begin_comment
comment|/* XXX flag should not be user visible  */
end_comment

begin_define
define|#
directive|define
name|NG_FREE_MSG
parameter_list|(
name|msg
parameter_list|)
define|\
value|do {								\ 		if ((msg)) {						\ 			if ((msg->header.flags& NGF_STATIC) == 0) {	\ 				FREE((msg), M_NETGRAPH_MSG);		\ 			}						\ 			(msg) = NULL;					\ 		}	 						\ 	} while (0)
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
comment|/* Free any data packet and/or meta-data */
end_comment

begin_define
define|#
directive|define
name|NG_FREE_DATAX
parameter_list|(
name|m
parameter_list|,
name|meta
parameter_list|)
define|\
value|do {								\ 		NG_FREE_M((m));						\ 		NG_FREE_META((meta));					\ 	} while (0)
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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg))			\&& (ng_address_hook((here), (item),			\ 					(hook), (retaddr)) == 0)) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = EINVAL;				\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg))			\&& (ng_address_path((here), (item),			\ 					(path), (retaddr)) == 0)) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = EINVAL;				\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg))			\&& (ng_address_ID((here), (item),			\ 					(ID), (retaddr)) == 0)) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = EINVAL;				\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NG_QUEUE_MSG
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
value|do {								\ 		item_p item;						\ 		if ((item = ng_package_msg(msg))			\&& (ng_address_path((here), (item),			\ 					(path), (retaddr)) == 0)) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = EINVAL;				\ 		}							\ 		(msg) = NULL;						\ 	} while (0)
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
value|do {								\ 		if ((ng_address_hook((here), (item),			\ 					(hook), (retaddr))) == 0) {	\ 			SAVE_LINE(item);				\ 			(error) = ng_snd_item((item), 0);		\ 		} else {						\ 			(error) = EINVAL;				\ 		}							\ 		(item) = NULL;						\ 	} while (0)
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
value|static moduledata_t ng_##typename##_mod = {				\ 	"ng_" #typename,						\ 	ng_mod_event,							\ 	(typestructp)							\ };									\ DECLARE_MODULE(ng_##typename, ng_##typename##_mod, sub, order);		\ MODULE_DEPEND(ng_##typename, netgraph, 1, 1, 1)
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
comment|/* Methods that should go away (or become private)*/
end_comment

begin_comment
comment|/* Methods that should exist */
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
name|retaddr
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
name|void
name|ng_free_item
parameter_list|(
name|item_p
name|item
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
name|ng_rmnode_self
parameter_list|(
name|node_p
name|here
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
name|void
name|ng_unname
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_unref
parameter_list|(
name|node_p
name|node
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

