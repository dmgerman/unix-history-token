begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999-2002 Robert N. M. Watson  * Copyright (c) 2001 Ilmar S. Habibulin  * Copyright (c) 2001-2004 Networks Associates Technology, Inc.  * Copyright (c) 2006 nCircle Network Security, Inc.  * All rights reserved.  *  * This software was developed by Robert Watson and Ilmar Habibulin for the  * TrustedBSD Project.  *  * This software was developed for the FreeBSD Project in part by Network  * Associates Laboratories, the Security Research Division of Network  * Associates, Inc. under DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"),  * as part of the DARPA CHATS research program.  *  * This software was developed by Robert N. M. Watson for the TrustedBSD  * Project under contract to nCircle Network Security, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_SECURITY_MAC_MAC_INTERNAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_SECURITY_MAC_MAC_INTERNAL_H_
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAC_ALWAYS_LABEL_MBUF
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|mac_labelmbufs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|mac_policy_grab_exclusive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_assert_exclusive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_release_exclusive
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_list_busy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mac_policy_list_conditional_busy
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mac_policy_list_unbusy
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

begin_comment
comment|/*  * MAC Framework per-object type functions.  It's not yet clear how the  * namespaces, etc, should work for these, so for now, sort by object type.  */
end_comment

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
name|int
name|mac_check_cred_relabel
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
name|mac_externalize_cred_label
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
name|mac_internalize_cred_label
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
name|mac_relabel_cred
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
name|mac_copy_pipe_label
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
name|mac_externalize_pipe_label
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
name|mac_internalize_pipe_label
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
name|mac_copy_socket_label
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
name|mac_externalize_socket_label
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
name|mac_internalize_socket_label
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
name|mac_externalize_vnode_label
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
name|mac_internalize_vnode_label
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
name|mac_check_vnode_mmap_downgrade
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
comment|/*  * MAC_CHECK performs the designated check by walking the policy module list  * and checking with each as to how it feels about the request.  Note that it  * returns its value via 'error' in the scope of the caller.  */
end_comment

begin_define
define|#
directive|define
name|MAC_CHECK
parameter_list|(
name|check
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {					\ 	struct mac_policy_conf *mpc;					\ 	int entrycount;							\ 									\ 	error = 0;							\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## check != NULL)		\ 			error = mac_error_select(			\ 			    mpc->mpc_ops->mpo_ ## check (args),		\ 			    error);					\ 	}								\ 	if ((entrycount = mac_policy_list_conditional_busy()) != 0) {	\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## check != NULL)	\ 				error = mac_error_select(		\ 				    mpc->mpc_ops->mpo_ ## check (args),	\ 				    error);				\ 		}							\ 		mac_policy_list_unbusy();				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_GRANT performs the designated check by walking the policy module list  * and checking with each as to how it feels about the request.  Unlike  * MAC_CHECK, it grants if any policies return '0', and otherwise returns  * EPERM.  Note that it returns its value via 'error' in the scope of the  * caller.  */
end_comment

begin_define
define|#
directive|define
name|MAC_GRANT
parameter_list|(
name|check
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {					\ 	struct mac_policy_conf *mpc;					\ 	int entrycount;							\ 									\ 	error = EPERM;							\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## check != NULL) {		\ 			if (mpc->mpc_ops->mpo_ ## check(args) == 0)	\ 				error = 0;				\ 		}							\ 	}								\ 	if ((entrycount = mac_policy_list_conditional_busy()) != 0) {	\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## check != NULL) {	\ 				if (mpc->mpc_ops->mpo_ ## check (args)	\ 				    == 0)				\ 					error = 0;			\ 			}						\ 		}							\ 		mac_policy_list_unbusy();				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_BOOLEAN performs the designated boolean composition by walking the  * module list, invoking each instance of the operation, and combining the  * results using the passed C operator.  Note that it returns its value via  * 'result' in the scope of the caller, which should be initialized by the  * caller in a meaningful way to get a meaningful result.  */
end_comment

begin_define
define|#
directive|define
name|MAC_BOOLEAN
parameter_list|(
name|operation
parameter_list|,
name|composition
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {		\ 	struct mac_policy_conf *mpc;					\ 	int entrycount;							\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			result = result composition			\ 			    mpc->mpc_ops->mpo_ ## operation (args);	\ 	}								\ 	if ((entrycount = mac_policy_list_conditional_busy()) != 0) {	\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				result = result composition		\ 				    mpc->mpc_ops->mpo_ ## operation	\ 				    (args);				\ 		}							\ 		mac_policy_list_unbusy();				\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_EXTERNALIZE queries each policy to see if it can generate an  * externalized version of a label element by name.  Policies declare whether  * they have matched a particular element name, parsed from the string by  * MAC_EXTERNALIZE, and an error is returned if any element is matched by no  * policy.  */
end_comment

begin_define
define|#
directive|define
name|MAC_EXTERNALIZE
parameter_list|(
name|type
parameter_list|,
name|label
parameter_list|,
name|elementlist
parameter_list|,
name|outbuf
parameter_list|, 		\
name|outbuflen
parameter_list|)
value|do {							\ 	int claimed, first, ignorenotfound, savedlen;			\ 	char *element_name, *element_temp;				\ 	struct sbuf sb;							\ 									\ 	error = 0;							\ 	first = 1;							\ 	sbuf_new(&sb, outbuf, outbuflen, SBUF_FIXEDLEN);		\ 	element_temp = elementlist;					\ 	while ((element_name = strsep(&element_temp, ",")) != NULL) {	\ 		if (element_name[0] == '?') {				\ 			element_name++;					\ 			ignorenotfound = 1;				\ 		 } else							\ 			ignorenotfound = 0;				\ 		savedlen = sbuf_len(&sb);				\ 		if (first)						\ 			error = sbuf_printf(&sb, "%s/", element_name);	\ 		else							\ 			error = sbuf_printf(&sb, ",%s/", element_name);	\ 		if (error == -1) {					\ 			error = EINVAL;
comment|/* XXX: E2BIG? */
value|\ 			break;						\ 		}							\ 		claimed = 0;						\ 		MAC_CHECK(externalize_ ## type ## _label, label,	\ 		    element_name,&sb,&claimed);			\ 		if (error)						\ 			break;						\ 		if (claimed == 0&& ignorenotfound) {			\
comment|/* Revert last label name. */
value|\ 			sbuf_setpos(&sb, savedlen);			\ 		} else if (claimed != 1) {				\ 			error = EINVAL;
comment|/* XXX: ENOLABEL? */
value|\ 			break;						\ 		} else {						\ 			first = 0;					\ 		}							\ 	}								\ 	sbuf_finish(&sb);						\ } while (0)
end_define

begin_comment
comment|/*  * MAC_INTERNALIZE presents parsed element names and data to each policy to  * see if any is willing to claim it and internalize the label data.  If no  * policies match, an error is returned.  */
end_comment

begin_define
define|#
directive|define
name|MAC_INTERNALIZE
parameter_list|(
name|type
parameter_list|,
name|label
parameter_list|,
name|instring
parameter_list|)
value|do {			\ 	char *element, *element_name, *element_data;			\ 	int claimed;							\ 									\ 	error = 0;							\ 	element = instring;						\ 	while ((element_name = strsep(&element, ",")) != NULL) {	\ 		element_data = element_name;				\ 		element_name = strsep(&element_data, "/");		\ 		if (element_data == NULL) {				\ 			error = EINVAL;					\ 			break;						\ 		}							\ 		claimed = 0;						\ 		MAC_CHECK(internalize_ ## type ## _label, label,	\ 		    element_name, element_data,&claimed);		\ 		if (error)						\ 			break;						\ 		if (claimed != 1) {					\
comment|/* XXXMAC: Another error here? */
value|\ 			error = EINVAL;					\ 			break;						\ 		}							\ 	}								\ } while (0)
end_define

begin_comment
comment|/*  * MAC_PERFORM performs the designated operation by walking the policy module  * list and invoking that operation for each policy.  */
end_comment

begin_define
define|#
directive|define
name|MAC_PERFORM
parameter_list|(
name|operation
parameter_list|,
name|args
modifier|...
parameter_list|)
value|do {				\ 	struct mac_policy_conf *mpc;					\ 	int entrycount;							\ 									\ 	LIST_FOREACH(mpc,&mac_static_policy_list, mpc_list) {		\ 		if (mpc->mpc_ops->mpo_ ## operation != NULL)		\ 			mpc->mpc_ops->mpo_ ## operation (args);		\ 	}								\ 	if ((entrycount = mac_policy_list_conditional_busy()) != 0) {	\ 		LIST_FOREACH(mpc,&mac_policy_list, mpc_list) {		\ 			if (mpc->mpc_ops->mpo_ ## operation != NULL)	\ 				mpc->mpc_ops->mpo_ ## operation (args);	\ 		}							\ 		mac_policy_list_unbusy();				\ 	}								\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_SECURITY_MAC_MAC_INTERNAL_H_ */
end_comment

end_unit

