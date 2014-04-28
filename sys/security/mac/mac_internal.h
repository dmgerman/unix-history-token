begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002, 2006, 2009 Robert N. M. Watson  * Copyright (c) 2001 Ilmar S. Habibulin  * Copyright (c) 2001-2004 Networks Associates Technology, Inc.  * Copyright (c) 2006 nCircle Network Security, Inc.  * Copyright (c) 2006 SPARTA, Inc.  * Copyright (c) 2009 Apple, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson and Ilmar Habibulin for the  * TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * This software was enhanced by SPARTA ISSO under SPAWAR contract  * N66001-04-C-6019 ("SEFOS").  *  * This software was developed at the University of Cambridge Computer  * Laboratory with support from a grant from Google, Inc.   *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SECURITY_MAC_MAC_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SECURITY_MAC_MAC_INTERNAL_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/rmlock.h>
end_include

begin_comment
comment|/*  * MAC Framework sysctl namespace.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_DECL
end_ifdef

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_security_mac
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_DECL */
end_comment

begin_comment
comment|/*  * MAC Framework SDT DTrace probe namespace, macros for declaring entry  * point probes, macros for invoking them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SDT_PROVIDER_DECLARE
end_ifdef

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|mac
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* MAC Framework-level events. */
end_comment

begin_expr_stmt
name|SDT_PROVIDER_DECLARE
argument_list|(
name|mac_framework
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Entry points to MAC. */
end_comment

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE_DEFINE4
parameter_list|(
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|SDT_PROBE_DEFINE5(mac_framework, kernel, name, mac__check__err,	\ 	    "int", arg0, arg1, arg2, arg3);				\ 	SDT_PROBE_DEFINE5(mac_framework, kernel, name, mac__check__ok,	\ 	    "int", arg0, arg1, arg2, arg3);
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE_DEFINE3
parameter_list|(
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|SDT_PROBE_DEFINE4(mac_framework, kernel, name, mac__check__err,	\ 	    "int", arg0, arg1, arg2);					\ 	SDT_PROBE_DEFINE4(mac_framework, kernel, name, mac__check__ok,	\ 	    "int", arg0, arg1, arg2);
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE_DEFINE2
parameter_list|(
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE_DEFINE3(mac_framework, kernel, name, mac__check__err,	\ 	    "int", arg0, arg1);						\ 	SDT_PROBE_DEFINE3(mac_framework, kernel, name, mac__check__ok,	\ 	    "int", arg0, arg1);
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE_DEFINE1
parameter_list|(
name|name
parameter_list|,
name|arg0
parameter_list|)
define|\
value|SDT_PROBE_DEFINE2(mac_framework, kernel, name, mac__check__err,	\ 	    "int", arg0);						\ 	SDT_PROBE_DEFINE2(mac_framework, kernel, name, mac__check__ok,	\ 	    "int", arg0);
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE4
parameter_list|(
name|name
parameter_list|,
name|error
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
value|do {	\ 	if (error) {							\ 		SDT_PROBE(mac_framework, kernel, name, mac__check__err,	\ 		    error, arg0, arg1, arg2, arg3);			\ 	} else {							\ 		SDT_PROBE(mac_framework, kernel, name, mac__check__ok,	\ 		    0, arg0, arg1, arg2, arg3);				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE3
parameter_list|(
name|name
parameter_list|,
name|error
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|,
name|arg2
parameter_list|)
define|\
value|MAC_CHECK_PROBE4(name, error, arg0, arg1, arg2, 0)
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE2
parameter_list|(
name|name
parameter_list|,
name|error
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|MAC_CHECK_PROBE3(name, error, arg0, arg1, 0)
end_define

begin_define
define|#
directive|define
name|MAC_CHECK_PROBE1
parameter_list|(
name|name
parameter_list|,
name|error
parameter_list|,
name|arg0
parameter_list|)
define|\
value|MAC_CHECK_PROBE2(name, error, arg0, 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAC_GRANT_PROBE_DEFINE2
parameter_list|(
name|name
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
define|\
value|SDT_PROBE_DEFINE3(mac_framework, kernel, name, mac__grant__err,	\ 	    "int", arg0, arg1);						\ 	SDT_PROBE_DEFINE3(mac_framework, kernel, name, mac__grant__ok,	\ 	    "int", arg0, arg1);
end_define

begin_define
define|#
directive|define
name|MAC_GRANT_PROBE2
parameter_list|(
name|name
parameter_list|,
name|error
parameter_list|,
name|arg0
parameter_list|,
name|arg1
parameter_list|)
value|do {		\ 	if (error) {							\ 		SDT_PROBE(mac_framework, kernel, name, mac__grant__err,	\ 		    error, arg0, arg1, 0, 0);				\ 	} else {							\ 		SDT_PROBE(mac_framework, kernel, name, mac__grant__ok,	\ 		    error, arg0, arg1, 0, 0);				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC Framework global types and typedefs.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|mac_policy_list_head
argument_list|,
name|mac_policy_conf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MALLOC_DECLARE
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_MACTEMP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * MAC labels -- in-kernel storage format.  *  * In general, struct label pointers are embedded in kernel data structures  * representing objects that may be labeled (and protected).  Struct label is  * opaque to both kernel services that invoke the MAC Framework and MAC  * policy modules.  In particular, we do not wish to encode the layout of the  * label structure into any ABIs.  Historically, the slot array contained  * unions of {long, void} but now contains uintptr_t.  */
end_comment

begin_define
define|#
directive|define
name|MAC_MAX_SLOTS
value|4
end_define

begin_define
define|#
directive|define
name|MAC_FLAG_INITIALIZED
value|0x0000001
end_define

begin_comment
comment|/* Is initialized for use. */
end_comment

begin_struct
struct|struct
name|label
block|{
name|int
name|l_flags
decl_stmt|;
name|intptr_t
name|l_perpolicy
index|[
name|MAC_MAX_SLOTS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flags for mac_labeled, a bitmask of object types need across the union of  * all policies currently registered with the MAC Framework, used to key  * whether or not labels are allocated and constructors for the type are  * invoked.  */
end_comment

begin_define
define|#
directive|define
name|MPC_OBJECT_CRED
value|0x0000000000000001
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_PROC
value|0x0000000000000002
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_VNODE
value|0x0000000000000004
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_INPCB
value|0x0000000000000008
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SOCKET
value|0x0000000000000010
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_DEVFS
value|0x0000000000000020
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_MBUF
value|0x0000000000000040
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_IPQ
value|0x0000000000000080
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_IFNET
value|0x0000000000000100
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_BPFDESC
value|0x0000000000000200
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_PIPE
value|0x0000000000000400
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_MOUNT
value|0x0000000000000800
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_POSIXSEM
value|0x0000000000001000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_POSIXSHM
value|0x0000000000002000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SYSVMSG
value|0x0000000000004000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SYSVMSQ
value|0x0000000000008000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SYSVSEM
value|0x0000000000010000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SYSVSHM
value|0x0000000000020000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_SYNCACHE
value|0x0000000000040000
end_define

begin_define
define|#
directive|define
name|MPC_OBJECT_IP6Q
value|0x0000000000080000
end_define

begin_comment
comment|/*  * MAC Framework global variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|mac_policy_list_head
name|mac_policy_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mac_policy_list_head
name|mac_static_policy_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|mac_policy_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
name|mac_labeled
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|mtx
name|mac_ifnet_mtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * MAC Framework infrastructure functions.  */
end_comment

begin_function_decl
name|int
name|mac_error_select
parameter_list|(
name|int
name|error1
parameter_list|,
name|int
name|error2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_slock_nosleep
parameter_list|(
name|struct
name|rm_priotracker
modifier|*
name|tracker
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_slock_sleep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_sunlock_nosleep
parameter_list|(
name|struct
name|rm_priotracker
modifier|*
name|tracker
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_sunlock_sleep
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|mac_labelzone_alloc
parameter_list|(
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_labelzone_free
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_labelzone_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_init_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_destroy_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_check_structmac_consistent
parameter_list|(
name|struct
name|mac
modifier|*
name|mac
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_allocate_slot
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MAC_IFNET_LOCK
parameter_list|(
name|ifp
parameter_list|)
value|mtx_lock(&mac_ifnet_mtx)
end_define

begin_define
define|#
directive|define
name|MAC_IFNET_UNLOCK
parameter_list|(
name|ifp
parameter_list|)
value|mtx_unlock(&mac_ifnet_mtx)
end_define

begin_comment
comment|/*  * MAC Framework per-object type functions.  It's not yet clear how the  * namespaces, etc, should work for these, so for now, sort by object type.  */
end_comment

begin_function_decl
name|struct
name|label
modifier|*
name|mac_cred_label_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_cred_label_free
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|mac_pipe_label_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_pipe_label_free
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|mac_socket_label_alloc
parameter_list|(
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_socket_label_free
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|mac_vnode_label_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_vnode_label_free
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_cred_check_relabel
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|label
modifier|*
name|newlabel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_cred_externalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|elements
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_cred_internalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_cred_relabel
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|label
modifier|*
name|newlabel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|label
modifier|*
name|mac_mbuf_to_label
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_pipe_copy_label
parameter_list|(
name|struct
name|label
modifier|*
name|src
parameter_list|,
name|struct
name|label
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_pipe_externalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|elements
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_pipe_internalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_socket_label_set
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|label
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_socket_copy_label
parameter_list|(
name|struct
name|label
modifier|*
name|src
parameter_list|,
name|struct
name|label
modifier|*
name|dest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_socket_externalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|elements
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_socket_internalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_vnode_externalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|elements
parameter_list|,
name|char
modifier|*
name|outbuf
parameter_list|,
name|size_t
name|outbuflen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_vnode_internalize_label
parameter_list|(
name|struct
name|label
modifier|*
name|label
parameter_list|,
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_vnode_check_mmap_downgrade
parameter_list|(
name|struct
name|ucred
modifier|*
name|cred
parameter_list|,
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|int
modifier|*
name|prot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vn_setlabel
parameter_list|(
name|struct
name|vnode
modifier|*
name|vp
parameter_list|,
name|struct
name|label
modifier|*
name|intlabel
parameter_list|,
name|struct
name|ucred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * MAC Framework composition macros invoke all registered MAC policies for a  * specific entry point.  They come in two forms: one which permits policies  * to sleep/block, and another that does not.  *  * MAC_POLICY_CHECK performs the designated check by walking the policy  * module list and checking with each as to how it feels about the request.  * Note that it returns its value via 'error' in the scope of the caller.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_CHECK
parameter_list|(
name|check
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\ 	struct mac_policy_conf *mpc;					\ 									\ 	error = 0;							\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## check != NULL)		\ 			error = mac_error_select(			\ 			    mpc->mpc_ops->mpo_ ## check (args),		\ 			    error);					\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		mac_policy_slock_sleep();				\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## check != NULL)	\ 				error = mac_error_select(		\ 				    mpc->mpc_ops->mpo_ ## check (args),	\ 				    error);				\ 		}							\ 		mac_policy_sunlock_sleep();				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MAC_POLICY_CHECK_NOSLEEP
parameter_list|(
name|check
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {			\ 	struct mac_policy_conf *mpc;					\ 									\ 	error = 0;							\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## check != NULL)		\ 			error = mac_error_select(			\ 			    mpc->mpc_ops->mpo_ ## check (args),		\ 			    error);					\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		struct rm_priotracker tracker;				\ 									\ 		mac_policy_slock_nosleep(&tracker);			\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## check != NULL)	\ 				error = mac_error_select(		\ 				    mpc->mpc_ops->mpo_ ## check (args),	\ 				    error);				\ 		}							\ 		mac_policy_sunlock_nosleep(&tracker);			\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_POLICY_GRANT performs the designated check by walking the policy  * module list and checking with each as to how it feels about the request.  * Unlike MAC_POLICY_CHECK, it grants if any policies return '0', and  * otherwise returns EPERM.  Note that it returns its value via 'error' in  * the scope of the caller.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_GRANT_NOSLEEP
parameter_list|(
name|check
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {			\ 	struct mac_policy_conf *mpc;					\ 									\ 	error = EPERM;							\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## check != NULL) {		\ 			if (mpc->mpc_ops->mpo_ ## check(args) == 0)	\ 				error = 0;				\ 		}							\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		struct rm_priotracker tracker;				\ 									\ 		mac_policy_slock_nosleep(&tracker);			\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## check != NULL) {	\ 				if (mpc->mpc_ops->mpo_ ## check (args)	\ 				    == 0)				\ 					error = 0;			\ 			}						\ 		}							\ 		mac_policy_sunlock_nosleep(&tracker);			\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_POLICY_BOOLEAN performs the designated boolean composition by walking  * the module list, invoking each instance of the operation, and combining  * the results using the passed C operator.  Note that it returns its value  * via 'result' in the scope of the caller, which should be initialized by  * the caller in a meaningful way to get a meaningful result.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_BOOLEAN
parameter_list|(
name|operation
parameter_list|,
name|composition
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {	\ 	struct mac_policy_conf *mpc;					\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			result = result composition			\ 			    mpc->mpc_ops->mpo_ ## operation (args);	\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		mac_policy_slock_sleep();				\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				result = result composition		\ 				    mpc->mpc_ops->mpo_ ## operation	\ 				    (args);				\ 		}							\ 		mac_policy_sunlock_sleep();				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MAC_POLICY_BOOLEAN_NOSLEEP
parameter_list|(
name|operation
parameter_list|,
name|composition
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {\ 	struct mac_policy_conf *mpc;					\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			result = result composition			\ 			    mpc->mpc_ops->mpo_ ## operation (args);	\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		struct rm_priotracker tracker;				\ 									\ 		mac_policy_slock_nosleep(&tracker);			\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				result = result composition		\ 				    mpc->mpc_ops->mpo_ ## operation	\ 				    (args);				\ 		}							\ 		mac_policy_sunlock_nosleep(&tracker);			\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_POLICY_EXTERNALIZE queries each policy to see if it can generate an  * externalized version of a label element by name.  Policies declare whether  * they have matched a particular element name, parsed from the string by  * MAC_POLICY_EXTERNALIZE, and an error is returned if any element is matched  * by no policy.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_EXTERNALIZE
parameter_list|(
name|type
parameter_list|,
name|label
parameter_list|,
name|elementlist
parameter_list|,
name|outbuf
parameter_list|, 	\
name|outbuflen
parameter_list|)
value|do {							\ 	int claimed, first, ignorenotfound, savedlen;			\ 	char *element_name, *element_temp;				\ 	struct sbuf sb;							\ 									\ 	error = 0;							\ 	first = 1;							\ 	sbuf_new(&sb, outbuf, outbuflen, SBUF_FIXEDLEN);		\ 	element_temp = elementlist;					\ 	while ((element_name = strsep(&element_temp, ",")) != NULL) {	\ 		if (element_name[0] == '?') {				\ 			element_name++;					\ 			ignorenotfound = 1;				\ 		 } else							\ 			ignorenotfound = 0;				\ 		savedlen = sbuf_len(&sb);				\ 		if (first)						\ 			error = sbuf_printf(&sb, "%s/", element_name);	\ 		else							\ 			error = sbuf_printf(&sb, ",%s/", element_name);	\ 		if (error == -1) {					\ 			error = EINVAL;
comment|/* XXX: E2BIG? */
value|\ 			break;						\ 		}							\ 		claimed = 0;						\ 		MAC_POLICY_CHECK(type ## _externalize_label, label,	\ 		    element_name,&sb,&claimed);			\ 		if (error)						\ 			break;						\ 		if (claimed == 0&& ignorenotfound) {			\
comment|/* Revert last label name. */
value|\ 			sbuf_setpos(&sb, savedlen);			\ 		} else if (claimed != 1) {				\ 			error = EINVAL;
comment|/* XXX: ENOLABEL? */
value|\ 			break;						\ 		} else {						\ 			first = 0;					\ 		}							\ 	}								\ 	sbuf_finish(&sb);						\ } while (0)
end_define

begin_comment
comment|/*  * MAC_POLICY_INTERNALIZE presents parsed element names and data to each  * policy to see if any is willing to claim it and internalize the label  * data.  If no policies match, an error is returned.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_INTERNALIZE
parameter_list|(
name|type
parameter_list|,
name|label
parameter_list|,
name|instring
parameter_list|)
value|do {		\ 	char *element, *element_name, *element_data;			\ 	int claimed;							\ 									\ 	error = 0;							\ 	element = instring;						\ 	while ((element_name = strsep(&element, ",")) != NULL) {	\ 		element_data = element_name;				\ 		element_name = strsep(&element_data, "/");		\ 		if (element_data == NULL) {				\ 			error = EINVAL;					\ 			break;						\ 		}							\ 		claimed = 0;						\ 		MAC_POLICY_CHECK(type ## _internalize_label, label,	\ 		    element_name, element_data,&claimed);		\ 		if (error)						\ 			break;						\ 		if (claimed != 1) {					\
comment|/* XXXMAC: Another error here? */
value|\ 			error = EINVAL;					\ 			break;						\ 		}							\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_POLICY_PERFORM performs the designated operation by walking the policy  * module list and invoking that operation for each policy.  */
end_comment

begin_define
define|#
directive|define
name|MAC_POLICY_PERFORM
parameter_list|(
name|operation
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {			\ 	struct mac_policy_conf *mpc;					\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			mpc->mpc_ops->mpo_ ## operation (args);		\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		mac_policy_slock_sleep();				\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				mpc->mpc_ops->mpo_ ## operation (args);	\ 		}							\ 		mac_policy_sunlock_sleep();				\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|MAC_POLICY_PERFORM_NOSLEEP
parameter_list|(
name|operation
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {		\ 	struct mac_policy_conf *mpc;					\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			mpc->mpc_ops->mpo_ ## operation (args);		\ 	}								\ 	if (!LIST_EMPTY(&mac_policy_list)) {				\ 		struct rm_priotracker tracker;				\ 									\ 		mac_policy_slock_nosleep(&tracker);			\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				mpc->mpc_ops->mpo_ ## operation (args);	\ 		}							\ 		mac_policy_sunlock_nosleep(&tracker);			\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SECURITY_MAC_MAC_INTERNAL_H_ */
end_comment

end_unit

