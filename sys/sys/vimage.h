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

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* Interim userspace API. */
end_comment

begin_struct
struct|struct
name|vi_req
block|{
name|int
name|vi_api_cookie
decl_stmt|;
comment|/* Catch API mismatch. */
name|int
name|vi_req_action
decl_stmt|;
comment|/* What to do with this request? */
name|u_short
name|vi_proc_count
decl_stmt|;
comment|/* Current number of processes. */
name|int
name|vi_if_count
decl_stmt|;
comment|/* Current number of ifnets. */
name|int
name|vi_sock_count
decl_stmt|;
name|char
name|vi_name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
name|char
name|vi_if_xname
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
comment|/* XXX should be IFNAMSIZ */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VI_CREATE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|VI_DESTROY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|VI_SWITCHTO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|VI_IFACE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|VI_GET
value|0x00000100
end_define

begin_define
define|#
directive|define
name|VI_GETNEXT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|VI_GETNEXT_RECURSE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|VI_API_VERSION
value|1
end_define

begin_comment
comment|/* Bump on struct changes. */
end_comment

begin_define
define|#
directive|define
name|VI_API_COOKIE
value|((sizeof(struct vi_req)<< 16) | VI_API_VERSION)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VIMAGE
argument_list|)
operator|&&
name|defined
argument_list|(
name|VIMAGE_GLOBALS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"You cannot have both option VIMAGE and option VIMAGE_GLOBALS!"
end_error

begin_endif
endif|#
directive|endif
end_endif

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
name|vprocg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vi_req
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|kld_sym_lookup
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

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE_GLOBALS
end_ifndef

begin_struct
struct|struct
name|vnet_symmap
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|size_t
name|offset
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vnet_symmap
name|vnet_symmap_t
typedef|;
end_typedef

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
name|size_t
name|vmi_size
decl_stmt|;
name|struct
name|vnet_symmap
modifier|*
name|vmi_symmap
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

begin_define
define|#
directive|define
name|VNET_MOD_ARP
value|28
end_define

begin_define
define|#
directive|define
name|VNET_MOD_RTABLE
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

begin_comment
comment|/* Major module IDs for vimage sysctl virtualization. */
end_comment

begin_define
define|#
directive|define
name|V_GLOBAL
value|0
end_define

begin_comment
comment|/* global variable - no indirection */
end_comment

begin_define
define|#
directive|define
name|V_NET
value|1
end_define

begin_define
define|#
directive|define
name|V_PROCG
value|2
end_define

begin_comment
comment|/* Name mappings for minor module IDs in vimage sysctl virtualization. */
end_comment

begin_define
define|#
directive|define
name|V_MOD_vnet_net
value|VNET_MOD_NET
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_netgraph
value|VNET_MOD_NETGRAPH
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_inet
value|VNET_MOD_INET
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_inet6
value|VNET_MOD_INET6
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_ipfw
value|VNET_MOD_IPFW
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_pf
value|VNET_MOD_PF
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_gif
value|VNET_MOD_GIF
end_define

begin_define
define|#
directive|define
name|V_MOD_vnet_ipsec
value|VNET_MOD_IPSEC
end_define

begin_define
define|#
directive|define
name|V_MOD_vprocg
value|0
end_define

begin_comment
comment|/* no minor module ids like in vnet */
end_comment

begin_function_decl
name|int
name|vi_symlookup
parameter_list|(
name|struct
name|kld_sym_lookup
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vi_td_ioctl
parameter_list|(
name|u_long
parameter_list|,
name|struct
name|vi_req
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vi_if_move
parameter_list|(
name|struct
name|vi_req
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|vimage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vi_child_of
parameter_list|(
name|struct
name|vimage
modifier|*
parameter_list|,
name|struct
name|vimage
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vimage
modifier|*
name|vimage_by_name
parameter_list|(
name|struct
name|vimage
modifier|*
parameter_list|,
name|char
modifier|*
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VIMAGE_GLOBALS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|VSYM
parameter_list|(
name|base
parameter_list|,
name|sym
parameter_list|)
value|(sym)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE_GLOBALS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_define
define|#
directive|define
name|VSYM
parameter_list|(
name|base
parameter_list|,
name|sym
parameter_list|)
value|((base)->_ ## sym)
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
name|VSYM
parameter_list|(
name|base
parameter_list|,
name|sym
parameter_list|)
value|(base ## _0._ ## sym)
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
comment|/* VIMAGE_GLOBALS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE_GLOBALS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_comment
comment|/*  * Casted NULL hack is needed for harvesting sizeofs() of fields inside  * struct vnet_* containers at compile time.  */
end_comment

begin_define
define|#
directive|define
name|VNET_SYMMAP
parameter_list|(
name|mod
parameter_list|,
name|name
parameter_list|)
define|\
value|{ #name, offsetof(struct vnet_ ## mod, _ ## name),		\ 	sizeof(((struct vnet_ ## mod *) NULL)->_ ## name) }
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
name|VNET_SYMMAP
parameter_list|(
name|mod
parameter_list|,
name|name
parameter_list|)
define|\
value|{ #name, (size_t)&(vnet_ ## mod ## _0._ ## name),		\ 	sizeof(vnet_ ## mod ## _0._ ## name) }
end_define

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
name|VNET_SYMMAP_END
value|{ NULL, 0 }
end_define

begin_struct
struct|struct
name|vimage
block|{
name|LIST_ENTRY
argument_list|(
argument|vimage
argument_list|)
name|vi_le
expr_stmt|;
comment|/* all vimage list */
name|LIST_ENTRY
argument_list|(
argument|vimage
argument_list|)
name|vi_sibling
expr_stmt|;
comment|/* vimages with same parent */
name|LIST_HEAD
argument_list|(
argument_list|,
argument|vimage
argument_list|)
name|vi_child_head
expr_stmt|;
comment|/* direct offspring list */
name|struct
name|vimage
modifier|*
name|vi_parent
decl_stmt|;
comment|/* ptr to parent vimage */
name|u_int
name|vi_id
decl_stmt|;
comment|/* ID num */
name|u_int
name|vi_ucredrefc
decl_stmt|;
comment|/* # of ucreds pointing to us */
name|char
name|vi_name
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|struct
name|vnet
modifier|*
name|v_net
decl_stmt|;
name|struct
name|vprocg
modifier|*
name|v_procg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vnet
block|{
name|void
modifier|*
name|mod_data
index|[
name|VNET_MOD_MAX
index|]
decl_stmt|;
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
name|vnet_id
decl_stmt|;
comment|/* ID num */
name|u_int
name|ifcnt
decl_stmt|;
name|u_int
name|sockcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vprocg
block|{
name|LIST_ENTRY
argument_list|(
argument|vprocg
argument_list|)
name|vprocg_le
expr_stmt|;
name|u_int
name|vprocg_id
decl_stmt|;
comment|/* ID num */
name|u_int
name|nprocs
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|vimage_list_head
argument_list|,
name|vimage
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vimage_list_head
name|vimage_head
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vprocg
name|vprocg_0
decl_stmt|;
end_decl_stmt

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
comment|/* !VIMAGE_GLOBALS */
end_comment

begin_define
define|#
directive|define
name|curvnet
value|curthread->td_vnet
end_define

begin_define
define|#
directive|define
name|VNET_MAGIC_N
value|0x3e0d8f29
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

begin_ifdef
ifdef|#
directive|ifdef
name|VNET_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|INIT_FROM_VNET
parameter_list|(
name|vnet
parameter_list|,
name|modindex
parameter_list|,
name|modtype
parameter_list|,
name|sym
parameter_list|)
define|\
value|if (vnet == NULL || vnet != curvnet)				\ 		panic("in %s:%d %s()\n vnet=%p curvnet=%p",		\ 		    __FILE__, __LINE__, __FUNCTION__,			\ 		    vnet, curvnet);					\ 	modtype *sym = (vnet)->mod_data[modindex];
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
name|INIT_FROM_VNET
parameter_list|(
name|vnet
parameter_list|,
name|modindex
parameter_list|,
name|modtype
parameter_list|,
name|sym
parameter_list|)
define|\
value|modtype *sym = (vnet)->mod_data[modindex];
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VNET_DEBUG */
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
name|INIT_FROM_VNET
parameter_list|(
name|vnet
parameter_list|,
name|modindex
parameter_list|,
name|modtype
parameter_list|,
name|sym
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
name|vnet
modifier|*
name|vnet0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VNET_ITERATOR_DECL
parameter_list|(
name|arg
parameter_list|)
value|struct vnet *arg;
end_define

begin_define
define|#
directive|define
name|VNET_FOREACH
parameter_list|(
name|arg
parameter_list|)
value|LIST_FOREACH(arg,&vnet_head, vnet_le)
end_define

begin_else
else|#
directive|else
end_else

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

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|vprocg_list_head
argument_list|,
name|vprocg
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|vprocg_list_head
name|vprocg_head
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INIT_VPROCG
parameter_list|(
name|arg
parameter_list|)
value|struct vprocg *vprocg = (arg);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INIT_VPROCG
parameter_list|(
name|arg
parameter_list|)
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
name|IS_DEFAULT_VIMAGE
parameter_list|(
name|arg
parameter_list|)
value|((arg)->vi_id == 0)
end_define

begin_define
define|#
directive|define
name|IS_DEFAULT_VNET
parameter_list|(
name|arg
parameter_list|)
value|((arg)->vnet_id == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IS_DEFAULT_VIMAGE
parameter_list|(
name|arg
parameter_list|)
value|1
end_define

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
name|TD_TO_VIMAGE
parameter_list|(
name|td
parameter_list|)
value|(td)->td_ucred->cr_vimage
end_define

begin_define
define|#
directive|define
name|TD_TO_VNET
parameter_list|(
name|td
parameter_list|)
value|(td)->td_ucred->cr_vimage->v_net
end_define

begin_define
define|#
directive|define
name|TD_TO_VPROCG
parameter_list|(
name|td
parameter_list|)
value|(td)->td_ucred->cr_vimage->v_procg
end_define

begin_define
define|#
directive|define
name|P_TO_VIMAGE
parameter_list|(
name|p
parameter_list|)
value|(p)->p_ucred->cr_vimage
end_define

begin_define
define|#
directive|define
name|P_TO_VNET
parameter_list|(
name|p
parameter_list|)
value|(p)->p_ucred->cr_vimage->v_net
end_define

begin_define
define|#
directive|define
name|P_TO_VPROCG
parameter_list|(
name|p
parameter_list|)
value|(p)->p_ucred->cr_vimage->v_procg
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
name|TD_TO_VIMAGE
parameter_list|(
name|td
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
name|P_TO_VIMAGE
parameter_list|(
name|p
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

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE_GLOBALS
end_ifdef

begin_define
define|#
directive|define
name|TD_TO_VPROCG
parameter_list|(
name|td
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|P_TO_VPROCG
parameter_list|(
name|p
parameter_list|)
value|NULL
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE_GLOBALS */
end_comment

begin_define
define|#
directive|define
name|TD_TO_VPROCG
parameter_list|(
name|td
parameter_list|)
value|&vprocg_0
end_define

begin_define
define|#
directive|define
name|P_TO_VPROCG
parameter_list|(
name|p
parameter_list|)
value|&vprocg_0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIMAGE_GLOBALS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VIMAGE */
end_comment

begin_comment
comment|/* Non-VIMAGE null-macros */
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
name|VNET_LIST_RUNLOCK
parameter_list|()
end_define

begin_comment
comment|/* XXX those defines bellow should probably go into vprocg.h and vcpu.h */
end_comment

begin_define
define|#
directive|define
name|VPROCG
parameter_list|(
name|sym
parameter_list|)
value|VSYM(vprocg, sym)
end_define

begin_comment
comment|/*  * Size-guards for the vimage structures.  * If you need to update the values you MUST increment __FreeBSD_version.  * See description further down to see how to get the new values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|184
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|4424
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8808
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|31160
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__arm__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|100
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|2616
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8524
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_comment
comment|/* incl. pc98 */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|100
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|2612
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8512
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|31024
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__ia64__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|184
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|4424
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8808
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|31160
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__mips__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|100
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|2648
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8544
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__powerpc__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|100
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|2640
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8520
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|31048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__sparc64__
end_ifdef

begin_comment
comment|/* incl. sun4v */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_vnet_net
value|184
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet
value|4424
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_inet6
value|8808
end_define

begin_define
define|#
directive|define
name|SIZEOF_vnet_ipsec
value|31160
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZEOF_vnet_net
end_ifndef

begin_error
error|#
directive|error
literal|"SIZEOF_vnet_net no defined for this architecture."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZEOF_vnet_inet
end_ifndef

begin_error
error|#
directive|error
literal|"SIZEOF_vnet_inet no defined for this architecture."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZEOF_vnet_inet6
end_ifndef

begin_error
error|#
directive|error
literal|"SIZEOF_vnet_inet6 no defined for this architecture."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SIZEOF_vnet_ipsec
end_ifndef

begin_error
error|#
directive|error
literal|"SIZEOF_vnet_ipsec no defined for this architecture."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * x must be a positive integer constant (expected value),  * y must be compile-time evaluated to a positive integer,  * e.g. CTASSERT_EQUAL(FOO_EXPECTED_SIZE, sizeof (struct foo));  * One needs to compile with -Wuninitialized and thus at least -O  * for this to trigger and -Werror if it should be fatal.  */
end_comment

begin_define
define|#
directive|define
name|CTASSERT_EQUAL
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|static int __attribute__((__used__))				\ 	    __attribute__((__section__(".debug_ctassert_equal")))	\ 	__CONCAT(__ctassert_equal_at_line_, __LINE__)(void);		\ 									\ 	static int __attribute__((__used__))				\ 	    __attribute__((__section__(".debug_ctassert_equal")))	\ 	__CONCAT(__ctassert_equal_at_line_, __LINE__)(void)		\ 	{								\ 		int __CONCAT(__CONCAT(__expected_, x),			\ 		    _but_got)[(y) + (x)];				\ 		__CONCAT(__CONCAT(__expected_, x), _but_got)[(x)] = 1;	\ 		return (__CONCAT(__CONCAT(__expected_, x),		\ 		    _but_got)[(y)]);					\ 	}								\ 	struct __hack
end_define

begin_comment
comment|/*  * x shall be the expected value (SIZEOF_vnet_* from above)  * and y shall be the real size (sizeof(struct vnet_*)).  * If you run into the CTASSERT() you want to compile a universe  * with COPTFLAGS+="-O -Wuninitialized -DVIMAGE_CHECK_SIZES".  * This should give you the errors for the proper values defined above.  * Make sure to re-run universe with the proper values afterwards -  * -DMAKE_JUST_KERNELS should be enough.  *   * Note:   * CTASSERT() takes precedence in the current FreeBSD world thus the  * CTASSERT_EQUAL() will not neccessarily trigger if one uses both.  * But as CTASSERT_EQUAL() needs special compile time options, we  * want the default case to be backed by CTASSERT().  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|VIMAGE_CTASSERT
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE_CHECK_SIZES
end_ifdef

begin_define
define|#
directive|define
name|VIMAGE_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|CTASSERT_EQUAL(x, y)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VIMAGE_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|CTASSERT_EQUAL(x, y);						\ 	CTASSERT(x == 0 || x == y)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VIMAGE_CTASSERT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

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

