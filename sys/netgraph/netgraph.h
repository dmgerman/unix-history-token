begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * netgraph.h  *  * Copyright (c) 1996-1999 Whistle Communications, Inc.  * All rights reserved.  *   * Subject to the following obligations and disclaimer of warranty, use and  * redistribution of this software, in source or object code forms, with or  * without modifications are expressly permitted by Whistle Communications;  * provided, however, that:  * 1. Any and all reproductions of the source or object code must include the  *    copyright notice above and the following disclaimer of warranties; and  * 2. No rights are granted, in any manner or form, to use Whistle  *    Communications, Inc. trademarks, including the mark "WHISTLE  *    COMMUNICATIONS" on advertising, endorsements, or otherwise except as  *    such appears in the above copyright notice or in the software.  *   * THIS SOFTWARE IS BEING PROVIDED BY WHISTLE COMMUNICATIONS "AS IS", AND  * TO THE MAXIMUM EXTENT PERMITTED BY LAW, WHISTLE COMMUNICATIONS MAKES NO  * REPRESENTATIONS OR WARRANTIES, EXPRESS OR IMPLIED, REGARDING THIS SOFTWARE,  * INCLUDING WITHOUT LIMITATION, ANY AND ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.  * WHISTLE COMMUNICATIONS DOES NOT WARRANT, GUARANTEE, OR MAKE ANY  * REPRESENTATIONS REGARDING THE USE OF, OR THE RESULTS OF THE USE OF THIS  * SOFTWARE IN TERMS OF ITS CORRECTNESS, ACCURACY, RELIABILITY OR OTHERWISE.  * IN NO EVENT SHALL WHISTLE COMMUNICATIONS BE LIABLE FOR ANY DAMAGES  * RESULTING FROM OR ARISING OUT OF ANY USE OF THIS SOFTWARE, INCLUDING  * WITHOUT LIMITATION, ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * PUNITIVE, OR CONSEQUENTIAL DAMAGES, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES, LOSS OF USE, DATA OR PROFITS, HOWEVER CAUSED AND UNDER ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF WHISTLE COMMUNICATIONS IS ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  *  * Author: Julian Elischer<julian@whistle.com>  *  * $FreeBSD$  * $Whistle: netgraph.h,v 1.29 1999/11/01 07:56:13 julian Exp $  */
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
name|KERNEL
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

begin_comment
comment|/*  * Structure of a hook  */
end_comment

begin_struct
struct|struct
name|ng_hook
block|{
name|char
modifier|*
name|name
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

begin_comment
comment|/*  * Structure of a node  */
end_comment

begin_struct
struct|struct
name|ng_node
block|{
name|char
modifier|*
name|name
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
name|sleepers
decl_stmt|;
comment|/* #procs sleeping on this node */
name|int
name|refs
decl_stmt|;
comment|/* number of references to this node */
name|int
name|numhooks
decl_stmt|;
comment|/* number of hooks */
name|int
name|colour
decl_stmt|;
comment|/* for graph colouring algorithms */
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
value|0x001
end_define

begin_comment
comment|/* free when all sleepers and refs go to 0 */
end_comment

begin_define
define|#
directive|define
name|NG_BUSY
value|0x002
end_define

begin_comment
comment|/* callers should sleep or wait */
end_comment

begin_define
define|#
directive|define
name|NG_TOUCHED
value|0x004
end_define

begin_comment
comment|/* to avoid cycles when 'flooding' */
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
modifier|*
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
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|retaddr
parameter_list|,
name|struct
name|ng_mesg
modifier|*
modifier|*
name|resp
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
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|meta_p
name|meta
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
comment|/*  * Structure of a node type  */
end_comment

begin_struct
struct|struct
name|ng_type
block|{
name|u_int32_t
name|version
decl_stmt|;
comment|/* must equal NG_VERSION */
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
comment|/* only if you have 23000 hooks */
name|ng_connect_t
modifier|*
name|connect
decl_stmt|;
comment|/* final notification of new hook */
name|ng_rcvdata_t
modifier|*
name|rcvdata
decl_stmt|;
comment|/* date comes here */
name|ng_rcvdata_t
modifier|*
name|rcvdataq
decl_stmt|;
comment|/* or here if been queued */
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
comment|/* Send data packet with meta-data */
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
name|a
parameter_list|)
define|\
value|do {								\ 		(error) = ng_send_data((hook), (m), (a));		\ 		(m) = NULL;						\ 		(a) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/* Send  queued data packet with meta-data */
end_comment

begin_define
define|#
directive|define
name|NG_SEND_DATAQ
parameter_list|(
name|error
parameter_list|,
name|hook
parameter_list|,
name|m
parameter_list|,
name|a
parameter_list|)
define|\
value|do {								\ 		(error) = ng_send_dataq((hook), (m), (a));		\ 		(m) = NULL;						\ 		(a) = NULL;						\ 	} while (0)
end_define

begin_comment
comment|/* Free metadata */
end_comment

begin_define
define|#
directive|define
name|NG_FREE_META
parameter_list|(
name|a
parameter_list|)
define|\
value|do {								\ 		if ((a)) {						\ 			FREE((a), M_NETGRAPH);				\ 			a = NULL;					\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Free any data packet and/or meta-data */
end_comment

begin_define
define|#
directive|define
name|NG_FREE_DATA
parameter_list|(
name|m
parameter_list|,
name|a
parameter_list|)
define|\
value|do {								\ 		if ((m)) {						\ 			m_freem((m));					\ 			m = NULL;					\ 		}							\ 		NG_FREE_META((a));					\ 	} while (0)
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
value|static moduledata_t ng_##typename##_mod = {				\ 	"ng_" #typename,						\ 	ng_mod_event,							\ 	(typestructp)							\ };									\ DECLARE_MODULE(ng_##typename, ng_##typename##_mod, sub, order)
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

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_NETGRAPH
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ng_bypass
parameter_list|(
name|hook_p
name|hook1
parameter_list|,
name|hook_p
name|hook2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_cutlinks
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_con_nodes
parameter_list|(
name|node_p
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|node_p
name|node2
parameter_list|,
specifier|const
name|char
modifier|*
name|name2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_destroy_hook
parameter_list|(
name|hook_p
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|node_p
name|ng_findname
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
name|struct
name|ng_type
modifier|*
name|ng_findtype
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_make_node
parameter_list|(
specifier|const
name|char
modifier|*
name|type
parameter_list|,
name|node_p
modifier|*
name|nodepp
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
name|ng_mkpeer
parameter_list|(
name|node_p
name|node
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|name2
parameter_list|,
name|char
modifier|*
name|type
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
name|int
name|ng_path2node
parameter_list|(
name|node_p
name|here
parameter_list|,
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|node_p
modifier|*
name|dest
parameter_list|,
name|char
modifier|*
modifier|*
name|rtnp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_path_parse
parameter_list|(
name|char
modifier|*
name|addr
parameter_list|,
name|char
modifier|*
modifier|*
name|node
parameter_list|,
name|char
modifier|*
modifier|*
name|path
parameter_list|,
name|char
modifier|*
modifier|*
name|hook
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_queue_data
parameter_list|(
name|hook_p
name|hook
parameter_list|,
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
name|int
name|ng_queue_msg
parameter_list|(
name|node_p
name|here
parameter_list|,
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_release_node
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ng_rmnode
parameter_list|(
name|node_p
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ng_send_data
parameter_list|(
name|hook_p
name|hook
parameter_list|,
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
name|int
name|ng_send_dataq
parameter_list|(
name|hook_p
name|hook
parameter_list|,
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
name|int
name|ng_send_msg
parameter_list|(
name|node_p
name|here
parameter_list|,
name|struct
name|ng_mesg
modifier|*
name|msg
parameter_list|,
specifier|const
name|char
modifier|*
name|address
parameter_list|,
name|struct
name|ng_mesg
modifier|*
modifier|*
name|resp
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

begin_function_decl
name|int
name|ng_wait_node
parameter_list|(
name|node_p
name|node
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX stuck here till we get the correct stuff in libkern etc. */
end_comment

begin_function_decl
name|unsigned
name|long
name|strtoul
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|strtol
parameter_list|(
specifier|const
name|char
modifier|*
name|nptr
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|endptr
parameter_list|,
name|int
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*-  * Copyright (c) 1982, 1988, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_CTYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_CTYPE_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_define
define|#
directive|define
name|isspace
parameter_list|(
name|c
parameter_list|)
value|((c) == ' ' || ((c)>= '\t'&& (c)<= '\r'))
end_define

begin_define
define|#
directive|define
name|isascii
parameter_list|(
name|c
parameter_list|)
value|(((c)& ~0x7f) == 0)
end_define

begin_define
define|#
directive|define
name|isupper
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'A'&& (c)<= 'Z')
end_define

begin_define
define|#
directive|define
name|islower
parameter_list|(
name|c
parameter_list|)
value|((c)>= 'a'&& (c)<= 'z')
end_define

begin_define
define|#
directive|define
name|isalpha
parameter_list|(
name|c
parameter_list|)
value|(isupper(c) || islower(c))
end_define

begin_define
define|#
directive|define
name|isdigit
parameter_list|(
name|c
parameter_list|)
value|((c)>= '0'&& (c)<= '9')
end_define

begin_define
define|#
directive|define
name|isxdigit
parameter_list|(
name|c
parameter_list|)
value|(isdigit(c) \ 			  || ((c)>= 'A'&& (c)<= 'F') \ 			  || ((c)>= 'a'&& (c)<= 'f'))
end_define

begin_define
define|#
directive|define
name|toupper
parameter_list|(
name|c
parameter_list|)
value|((c) - 0x20 * (((c)>= 'a')&& ((c)<= 'z')))
end_define

begin_define
define|#
directive|define
name|tolower
parameter_list|(
name|c
parameter_list|)
value|((c) + 0x20 * (((c)>= 'A')&& ((c)<= 'Z')))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_CTYPE_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NETGRAPH_NETGRAPH_H_ */
end_comment

end_unit

