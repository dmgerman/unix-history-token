begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2009 University of Zagreb  * Copyright (c) 2006-2009 FreeBSD Foundation  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VIMAGE_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VIMAGE_H_
end_define

begin_comment
comment|/*  * struct vnet describes a virtualized network stack, and is primarily a  * pointer to storage for virtualized global variables.  Expose to userspace  * as required for libkvm.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|_WANT_VNET
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|vnet
block|{
name|LIST_ENTRY
argument_list|(
argument|vnet
argument_list|)
name|vnet_le
expr_stmt|;
comment|/* all vnets list */
name|u_int
name|vnet_magic_n
decl_stmt|;
name|u_int
name|vnet_ifcnt
decl_stmt|;
name|u_int
name|vnet_sockcnt
decl_stmt|;
name|void
modifier|*
name|vnet_data_mem
decl_stmt|;
name|uintptr_t
name|vnet_data_base
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VNET_MAGIC_N
value|0x3e0d8f29
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|VNET_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|vnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|vnet_attach_fn
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|vnet_detach_fn
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_struct
struct|struct
name|vnet_modinfo
block|{
name|u_int
name|vmi_id
decl_stmt|;
name|u_int
name|vmi_dependson
decl_stmt|;
name|char
modifier|*
name|vmi_name
decl_stmt|;
name|vnet_attach_fn
modifier|*
name|vmi_iattach
decl_stmt|;
name|vnet_detach_fn
modifier|*
name|vmi_idetach
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vnet_modinfo
name|vnet_modinfo_t
typedef|;
end_typedef

begin_struct
struct|struct
name|vnet_modlink
block|{
name|TAILQ_ENTRY
argument_list|(
argument|vnet_modlink
argument_list|)
name|vml_mod_le
expr_stmt|;
specifier|const
name|struct
name|vnet_modinfo
modifier|*
name|vml_modinfo
decl_stmt|;
specifier|const
name|void
modifier|*
name|vml_iarg
decl_stmt|;
specifier|const
name|char
modifier|*
name|vml_iname
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Stateful modules. */
end_comment

begin_define
define|#
directive|define
name|VNET_MOD_NET
value|0
end_define

begin_comment
comment|/* MUST be 0 - implicit dependency */
end_comment

begin_define
define|#
directive|define
name|VNET_MOD_NETGRAPH
value|1
end_define

begin_define
define|#
directive|define
name|VNET_MOD_INET
value|2
end_define

begin_define
define|#
directive|define
name|VNET_MOD_INET6
value|3
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IPSEC
value|4
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IPFW
value|5
end_define

begin_define
define|#
directive|define
name|VNET_MOD_DUMMYNET
value|6
end_define

begin_define
define|#
directive|define
name|VNET_MOD_PF
value|7
end_define

begin_define
define|#
directive|define
name|VNET_MOD_ALTQ
value|8
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IPX
value|9
end_define

begin_define
define|#
directive|define
name|VNET_MOD_ATALK
value|10
end_define

begin_define
define|#
directive|define
name|VNET_MOD_ACCF_HTTP
value|11
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IGMP
value|12
end_define

begin_define
define|#
directive|define
name|VNET_MOD_MLD
value|13
end_define

begin_define
define|#
directive|define
name|VNET_MOD_RTABLE
value|14
end_define

begin_comment
comment|/* Stateless modules. */
end_comment

begin_define
define|#
directive|define
name|VNET_MOD_IF_CLONE
value|19
end_define

begin_define
define|#
directive|define
name|VNET_MOD_NG_ETHER
value|20
end_define

begin_define
define|#
directive|define
name|VNET_MOD_NG_IFACE
value|21
end_define

begin_define
define|#
directive|define
name|VNET_MOD_NG_EIFACE
value|22
end_define

begin_define
define|#
directive|define
name|VNET_MOD_ESP
value|23
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IPIP
value|24
end_define

begin_define
define|#
directive|define
name|VNET_MOD_AH
value|25
end_define

begin_define
define|#
directive|define
name|VNET_MOD_IPCOMP
value|26
end_define

begin_define
define|#
directive|define
name|VNET_MOD_GIF
value|27
end_define

begin_comment
comment|/*	 		28 */
end_comment

begin_define
define|#
directive|define
name|VNET_MOD_FLOWTABLE
value|29
end_define

begin_define
define|#
directive|define
name|VNET_MOD_LOIF
value|30
end_define

begin_define
define|#
directive|define
name|VNET_MOD_DOMAIN
value|31
end_define

begin_define
define|#
directive|define
name|VNET_MOD_DYNAMIC_START
value|32
end_define

begin_define
define|#
directive|define
name|VNET_MOD_MAX
value|64
end_define

begin_function_decl
name|int
name|vi_if_move
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_mod_register
parameter_list|(
specifier|const
name|struct
name|vnet_modinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_mod_register_multi
parameter_list|(
specifier|const
name|struct
name|vnet_modinfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_mod_deregister
parameter_list|(
specifier|const
name|struct
name|vnet_modinfo
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_mod_deregister_multi
parameter_list|(
specifier|const
name|struct
name|vnet_modinfo
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vnet
modifier|*
name|vnet_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_destroy
parameter_list|(
name|struct
name|vnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_foreach
parameter_list|(
name|void
function_decl|(
modifier|*
name|vnet_foreach_fn
function_decl|)
parameter_list|(
name|struct
name|vnet
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
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
comment|/* VIMAGE */
end_comment

begin_define
define|#
directive|define
name|curvnet
value|curthread->td_vnet
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|VNET_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|condition
parameter_list|)
define|\
value|if (!(condition)) {						\ 		printf("VNET_ASSERT @ %s:%d %s():\n",			\ 			__FILE__, __LINE__, __FUNCTION__);		\ 		panic(#condition);					\ 	}
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
define|\
value|VNET_ASSERT((arg)->vnet_magic_n == VNET_MAGIC_N);		\ 	struct vnet *saved_vnet = curvnet;				\ 	const char *saved_vnet_lpush = curthread->td_vnet_lpush;	\ 	curvnet = arg;							\ 	curthread->td_vnet_lpush = __FUNCTION__;
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_VERBOSE
parameter_list|(
name|arg
parameter_list|)
define|\
value|CURVNET_SET_QUIET(arg)						\ 	if (saved_vnet)							\ 		printf("CURVNET_SET(%p) in %s() on cpu %d, prev %p in %s()\n", \ 		       curvnet,	curthread->td_vnet_lpush, curcpu,	\ 		       saved_vnet, saved_vnet_lpush);
end_define

begin_define
define|#
directive|define
name|CURVNET_SET
parameter_list|(
name|arg
parameter_list|)
value|CURVNET_SET_VERBOSE(arg)
end_define

begin_define
define|#
directive|define
name|CURVNET_RESTORE
parameter_list|()
define|\
value|VNET_ASSERT(saved_vnet == NULL ||				\ 		    saved_vnet->vnet_magic_n == VNET_MAGIC_N);		\ 	curvnet = saved_vnet;						\ 	curthread->td_vnet_lpush = saved_vnet_lpush;
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VNET_DEBUG */
end_comment

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|condition
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_SET
parameter_list|(
name|arg
parameter_list|)
define|\
value|struct vnet *saved_vnet = curvnet;				\ 	curvnet = arg;
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_VERBOSE
parameter_list|(
name|arg
parameter_list|)
value|CURVNET_SET(arg)
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
value|CURVNET_SET(arg)
end_define

begin_define
define|#
directive|define
name|CURVNET_RESTORE
parameter_list|()
define|\
value|curvnet = saved_vnet;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VNET_DEBUG */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|condition
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_SET
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CURVNET_RESTORE
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VIMAGE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_comment
comment|/*  * Global linked list of all virtual network stacks, along with read locks to  * access it.  If a caller may sleep while accessing the list, it must use  * the sleepable lock macros.  */
end_comment

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|vnet_list_head
argument_list|,
name|vnet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vnet_list_head
name|vnet_head
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|rwlock
name|vnet_rwlock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sx
name|vnet_sxlock
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VNET_LIST_RLOCK
parameter_list|()
value|sx_slock(&vnet_sxlock)
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RLOCK_NOSLEEP
parameter_list|()
value|rw_rlock(&vnet_rwlock)
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RUNLOCK
parameter_list|()
value|sx_sunlock(&vnet_sxlock)
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RUNLOCK_NOSLEEP
parameter_list|()
value|rw_runlock(&vnet_rwlock)
end_define

begin_comment
comment|/*  * Iteration macros to walk the global list of virtual network stacks.  */
end_comment

begin_define
define|#
directive|define
name|VNET_ITERATOR_DECL
parameter_list|(
name|arg
parameter_list|)
value|struct vnet *arg
end_define

begin_define
define|#
directive|define
name|VNET_FOREACH
parameter_list|(
name|arg
parameter_list|)
value|LIST_FOREACH((arg),&vnet_head, vnet_le)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_comment
comment|/*  * No-op macros for the !VIMAGE case.  */
end_comment

begin_define
define|#
directive|define
name|VNET_LIST_RLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RLOCK_NOSLEEP
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RUNLOCK
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_LIST_RUNLOCK_NOSLEEP
parameter_list|()
end_define

begin_define
define|#
directive|define
name|VNET_ITERATOR_DECL
parameter_list|(
name|arg
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VNET_FOREACH
parameter_list|(
name|arg
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIMAGE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|vnet
modifier|*
name|vnet0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IS_DEFAULT_VNET
parameter_list|(
name|arg
parameter_list|)
value|((arg) == vnet0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_DEFAULT_VNET
parameter_list|(
name|arg
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_define
define|#
directive|define
name|CRED_TO_VNET
parameter_list|(
name|cr
parameter_list|)
value|(cr)->cr_prison->pr_vnet
end_define

begin_define
define|#
directive|define
name|TD_TO_VNET
parameter_list|(
name|td
parameter_list|)
value|CRED_TO_VNET((td)->td_ucred)
end_define

begin_define
define|#
directive|define
name|P_TO_VNET
parameter_list|(
name|p
parameter_list|)
value|CRED_TO_VNET((p)->p_ucred)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_define
define|#
directive|define
name|CRED_TO_VNET
parameter_list|(
name|cr
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|TD_TO_VNET
parameter_list|(
name|td
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|P_TO_VNET
parameter_list|(
name|p
parameter_list|)
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIMAGE */
end_comment

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
comment|/* !_SYS_VIMAGE_H_ */
end_comment

end_unit

