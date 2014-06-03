begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006-2009 University of Zagreb  * Copyright (c) 2006-2009 FreeBSD Foundation  * All rights reserved.  *  * This software was developed by the University of Zagreb and the  * FreeBSD Foundation under sponsorship by the Stichting NLnet and the  * FreeBSD Foundation.  *  * Copyright (c) 2009 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2009 Robert N. M. Watson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * This header file defines several sets of interfaces supporting virtualized  * network stacks:  *  * - Definition of 'struct vnet' and functions and macros to allocate/free/  *   manipulate it.  *  * - A virtual network stack memory allocator, which provides support for  *   virtualized global variables via a special linker set, set_vnet.  *  * - Virtualized sysinits/sysuninits, which allow constructors and  *   destructors to be run for each network stack subsystem as virtual  *   instances are created and destroyed.  *  * If VIMAGE isn't compiled into the kernel, virtualized global variables  * compile to normal global variables, and virtualized sysinits to regular  * sysinits.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_VNET_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_VNET_H_
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

begin_comment
comment|/*  * These two virtual network stack allocator definitions are also required  * for libkvm so that it can evaluate virtualized global variables.  */
end_comment

begin_define
define|#
directive|define
name|VNET_SETNAME
value|"set_vnet"
end_define

begin_define
define|#
directive|define
name|VNET_SYMPREFIX
value|"vnet_entry_"
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

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_DECLARE
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|VNET_DECLARE(counter_u64_t, name[sizeof(type) / sizeof(uint64_t)])
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_DEFINE
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|VNET_DEFINE(counter_u64_t, name[sizeof(type) / sizeof(uint64_t)])
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_ALLOC
parameter_list|(
name|name
parameter_list|,
name|wait
parameter_list|)
define|\
value|COUNTER_ARRAY_ALLOC(VNET(name), \ 	sizeof(VNET(name)) / sizeof(counter_u64_t), (wait))
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_FREE
parameter_list|(
name|name
parameter_list|)
define|\
value|COUNTER_ARRAY_FREE(VNET(name), sizeof(VNET(name)) / sizeof(counter_u64_t))
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_ADD
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
define|\
value|counter_u64_add(VNET(name)[offsetof(type, f) / sizeof(uint64_t)], (v))
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_SYSINIT
parameter_list|(
name|name
parameter_list|)
define|\
value|static void				\ vnet_##name##_init(const void *unused)	\ {					\ 	VNET_PCPUSTAT_ALLOC(name, M_WAITOK);	\ }					\ VNET_SYSINIT(vnet_ ## name ## _init, SI_SUB_PROTO_IFATTACHDOMAIN,	\     SI_ORDER_ANY, vnet_ ## name ## _init, NULL)
end_define

begin_define
define|#
directive|define
name|VNET_PCPUSTAT_SYSUNINIT
parameter_list|(
name|name
parameter_list|)
define|\
value|static void								\ vnet_##name##_uninit(const void *unused)				\ {									\ 	VNET_PCPUSTAT_FREE(name);					\ }									\ VNET_SYSUNINIT(vnet_ ## name ## _uninit, SI_SUB_PROTO_IFATTACHDOMAIN,	\     SI_ORDER_ANY, vnet_ ## name ## _uninit, NULL)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_PCPUSTAT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|type
parameter_list|,
name|array
parameter_list|,
name|desc
parameter_list|)
define|\
value|static int								\ array##_sysctl(SYSCTL_HANDLER_ARGS)					\ {									\ 	type s;								\ 	CTASSERT((sizeof(type) / sizeof(uint64_t)) ==			\ 	    (sizeof(VNET(array)) / sizeof(counter_u64_t)));		\ 	COUNTER_ARRAY_COPY(VNET(array),&s, sizeof(type) / sizeof(uint64_t));\ 	if (req->newptr)						\ 		COUNTER_ARRAY_ZERO(VNET(array),				\ 		    sizeof(type) / sizeof(uint64_t));			\ 	return (SYSCTL_OUT(req,&s, sizeof(type)));			\ }									\ SYSCTL_VNET_PROC(parent, nbr, name, CTLTYPE_OPAQUE | CTLFLAG_RW, NULL,	\     0, array ## _sysctl, "I", desc)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_comment
comment|/* for struct thread */
end_comment

begin_include
include|#
directive|include
file|<sys/rwlock.h>
end_include

begin_include
include|#
directive|include
file|<sys/sx.h>
end_include

begin_comment
comment|/*  * Location of the kernel's 'set_vnet' linker set.  */
end_comment

begin_decl_stmt
specifier|extern
name|uintptr_t
modifier|*
name|__start_set_vnet
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__GLOBL
argument_list|(
name|__start_set_vnet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|uintptr_t
modifier|*
name|__stop_set_vnet
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|__GLOBL
argument_list|(
name|__stop_set_vnet
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VNET_START
value|(uintptr_t)&__start_set_vnet
end_define

begin_define
define|#
directive|define
name|VNET_STOP
value|(uintptr_t)&__stop_set_vnet
end_define

begin_comment
comment|/*  * Functions to allocate and destroy virtual network stacks.  */
end_comment

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
name|vnet
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * The current virtual network stack -- we may wish to move this to struct  * pcpu in the future.  */
end_comment

begin_define
define|#
directive|define
name|curvnet
value|curthread->td_vnet
end_define

begin_comment
comment|/*  * Various macros -- get and set the current network stack, but also  * assertions.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
operator|||
name|defined
argument_list|(
name|VNET_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
value|do {					\ 	if (!(exp))							\ 		panic msg;						\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
parameter_list|)
value|do {					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VNET_DEBUG
end_ifdef

begin_function_decl
name|void
name|vnet_log_recursion
parameter_list|(
name|struct
name|vnet
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
define|\
value|VNET_ASSERT((arg) != NULL&& (arg)->vnet_magic_n == VNET_MAGIC_N, \ 	    ("CURVNET_SET at %s:%d %s() curvnet=%p vnet=%p",		\ 	    __FILE__, __LINE__, __func__, curvnet, (arg)));		\ 	struct vnet *saved_vnet = curvnet;				\ 	const char *saved_vnet_lpush = curthread->td_vnet_lpush;	\ 	curvnet = arg;							\ 	curthread->td_vnet_lpush = __func__;
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_VERBOSE
parameter_list|(
name|arg
parameter_list|)
define|\
value|CURVNET_SET_QUIET(arg)						\ 	if (saved_vnet)							\ 		vnet_log_recursion(saved_vnet, saved_vnet_lpush, __LINE__);
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
value|VNET_ASSERT(curvnet != NULL&& (saved_vnet == NULL ||		\ 	    saved_vnet->vnet_magic_n == VNET_MAGIC_N),			\ 	    ("CURVNET_RESTORE at %s:%d %s() curvnet=%p saved_vnet=%p",	\ 	    __FILE__, __LINE__, __func__, curvnet, saved_vnet));	\ 	curvnet = saved_vnet;						\ 	curthread->td_vnet_lpush = saved_vnet_lpush;
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
name|CURVNET_SET_QUIET
parameter_list|(
name|arg
parameter_list|)
define|\
value|VNET_ASSERT((arg) != NULL&& (arg)->vnet_magic_n == VNET_MAGIC_N, \ 	    ("CURVNET_SET at %s:%d %s() curvnet=%p vnet=%p",		\ 	    __FILE__, __LINE__, __func__, curvnet, (arg)));		\ 	struct vnet *saved_vnet = curvnet;				\ 	curvnet = arg;
end_define

begin_define
define|#
directive|define
name|CURVNET_SET_VERBOSE
parameter_list|(
name|arg
parameter_list|)
define|\
value|CURVNET_SET_QUIET(arg)
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
value|VNET_ASSERT(curvnet != NULL&& (saved_vnet == NULL ||		\ 	    saved_vnet->vnet_magic_n == VNET_MAGIC_N),			\ 	    ("CURVNET_RESTORE at %s:%d %s() curvnet=%p saved_vnet=%p",	\ 	    __FILE__, __LINE__, __func__, curvnet, saved_vnet));	\ 	curvnet = saved_vnet;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VNET_DEBUG */
end_comment

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

begin_comment
comment|/*  * Virtual network stack memory allocator, which allows global variables to  * be automatically instantiated for each network stack instance.  */
end_comment

begin_define
define|#
directive|define
name|VNET_NAME
parameter_list|(
name|n
parameter_list|)
value|vnet_entry_##n
end_define

begin_define
define|#
directive|define
name|VNET_DECLARE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|extern t VNET_NAME(n)
end_define

begin_define
define|#
directive|define
name|VNET_DEFINE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|t VNET_NAME(n) __section(VNET_SETNAME) __used
end_define

begin_define
define|#
directive|define
name|_VNET_PTR
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|(__typeof(VNET_NAME(n))*)		\ 				    ((b) + (uintptr_t)&VNET_NAME(n))
end_define

begin_define
define|#
directive|define
name|_VNET
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|(*_VNET_PTR(b, n))
end_define

begin_comment
comment|/*  * Virtualized global variable accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|VNET_VNET_PTR
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|_VNET_PTR((vnet)->vnet_data_base, n)
end_define

begin_define
define|#
directive|define
name|VNET_VNET
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(*VNET_VNET_PTR((vnet), n))
end_define

begin_define
define|#
directive|define
name|VNET_PTR
parameter_list|(
name|n
parameter_list|)
value|VNET_VNET_PTR(curvnet, n)
end_define

begin_define
define|#
directive|define
name|VNET
parameter_list|(
name|n
parameter_list|)
value|VNET_VNET(curvnet, n)
end_define

begin_comment
comment|/*  * Virtual network stack allocator interfaces from the kernel linker.  */
end_comment

begin_function_decl
name|void
modifier|*
name|vnet_data_alloc
parameter_list|(
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_data_copy
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_data_free
parameter_list|(
name|void
modifier|*
name|start_arg
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Sysctl variants for vnet-virtualized global variables.  Include  *<sys/sysctl.h> to expose these definitions.  *  * Note: SYSCTL_PROC() handler functions will need to resolve pointer  * arguments themselves, if required.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_OID
end_ifdef

begin_define
define|#
directive|define
name|SYSCTL_VNET_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_INT|CTLFLAG_MPSAFE|CTLFLAG_VNET|(access),		\ 	    ptr, val, sysctl_handle_int, "I", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,	\
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|CTASSERT(((access)& CTLTYPE) != 0);				\ 	SYSCTL_OID(parent, nbr, name, CTLFLAG_VNET|(access), ptr, arg, 	\ 	    handler, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_OPAQUE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,    \
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_OPAQUE|CTLFLAG_VNET|(access), ptr, len, 		\ 	    sysctl_handle_opaque, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_STRING|CTLFLAG_VNET|(access),			\ 	    arg, len, sysctl_handle_string, "A", descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_OPAQUE|CTLFLAG_VNET|(access), ptr,			\ 	    sizeof(struct type), sysctl_handle_opaque, "S," #type,	\ 	    descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_UINT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_OID(parent, nbr, name,					\ 	    CTLTYPE_UINT|CTLFLAG_MPSAFE|CTLFLAG_VNET|(access),		\ 	    ptr, val, sysctl_handle_int, "IU", descr)
end_define

begin_define
define|#
directive|define
name|VNET_SYSCTL_ARG
parameter_list|(
name|req
parameter_list|,
name|arg1
parameter_list|)
value|do {					\ 	if (arg1 != NULL)						\ 		arg1 = (void *)(TD_TO_VNET((req)->td)->vnet_data_base +	\ 		    (uintptr_t)(arg1));					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_OID */
end_comment

begin_comment
comment|/*  * Virtual sysinit mechanism, allowing network stack components to declare  * startup and shutdown methods to be run when virtual network stack  * instances are created and destroyed.  */
end_comment

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/*  * SYSINIT/SYSUNINIT variants that provide per-vnet constructors and  * destructors.  */
end_comment

begin_struct
struct|struct
name|vnet_sysinit
block|{
name|enum
name|sysinit_sub_id
name|subsystem
decl_stmt|;
name|enum
name|sysinit_elem_order
name|order
decl_stmt|;
name|sysinit_cfunc_t
name|func
decl_stmt|;
specifier|const
name|void
modifier|*
name|arg
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|vnet_sysinit
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VNET_SYSINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct vnet_sysinit ident ## _vnet_init = {		\ 		subsystem,						\ 		order,							\ 		(sysinit_cfunc_t)(sysinit_nfunc_t)func,			\ 		(arg)							\ 	};								\ 	SYSINIT(vnet_init_ ## ident, subsystem, order,			\ 	    vnet_register_sysinit,&ident ## _vnet_init);		\ 	SYSUNINIT(vnet_init_ ## ident, subsystem, order,		\ 	    vnet_deregister_sysinit,&ident ## _vnet_init)
end_define

begin_define
define|#
directive|define
name|VNET_SYSUNINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|static struct vnet_sysinit ident ## _vnet_uninit = {		\ 		subsystem,						\ 		order,							\ 		(sysinit_cfunc_t)(sysinit_nfunc_t)func,			\ 		(arg)							\ 	};								\ 	SYSINIT(vnet_uninit_ ## ident, subsystem, order,		\ 	    vnet_register_sysuninit,&ident ## _vnet_uninit);		\ 	SYSUNINIT(vnet_uninit_ ## ident, subsystem, order,		\ 	    vnet_deregister_sysuninit,&ident ## _vnet_uninit)
end_define

begin_comment
comment|/*  * Run per-vnet sysinits or sysuninits during vnet creation/destruction.  */
end_comment

begin_function_decl
name|void
name|vnet_sysinit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_sysuninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Interfaces for managing per-vnet constructors and destructors.  */
end_comment

begin_function_decl
name|void
name|vnet_register_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_register_sysuninit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_deregister_sysinit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vnet_deregister_sysuninit
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * EVENTHANDLER(9) extensions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_function_decl
name|void
name|vnet_global_eventhandler_iterator_func
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VNET_GLOBAL_EVENTHANDLER_REGISTER_TAG
parameter_list|(
name|tag
parameter_list|,
name|name
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|priority
parameter_list|)
define|\
value|do {									\ 	if (IS_DEFAULT_VNET(curvnet)) {					\ 		(tag) = vimage_eventhandler_register(NULL, #name, func,	\ 		    arg, priority,					\ 		    vnet_global_eventhandler_iterator_func);		\ 	}								\ } while(0)
end_define

begin_define
define|#
directive|define
name|VNET_GLOBAL_EVENTHANDLER_REGISTER
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|priority
parameter_list|)
define|\
value|do {									\ 	if (IS_DEFAULT_VNET(curvnet)) {					\ 		vimage_eventhandler_register(NULL, #name, func,		\ 		    arg, priority,					\ 		    vnet_global_eventhandler_iterator_func);		\ 	}								\ } while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !VIMAGE */
end_comment

begin_comment
comment|/*  * Various virtual network stack macros compile to no-ops without VIMAGE.  */
end_comment

begin_define
define|#
directive|define
name|curvnet
value|NULL
end_define

begin_define
define|#
directive|define
name|VNET_ASSERT
parameter_list|(
name|exp
parameter_list|,
name|msg
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

begin_define
define|#
directive|define
name|IS_DEFAULT_VNET
parameter_list|(
name|arg
parameter_list|)
value|1
end_define

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

begin_comment
comment|/*  * Versions of the VNET macros that compile to normal global variables and  * standard sysctl definitions.  */
end_comment

begin_define
define|#
directive|define
name|VNET_NAME
parameter_list|(
name|n
parameter_list|)
value|n
end_define

begin_define
define|#
directive|define
name|VNET_DECLARE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|extern t n
end_define

begin_define
define|#
directive|define
name|VNET_DEFINE
parameter_list|(
name|t
parameter_list|,
name|n
parameter_list|)
value|t n
end_define

begin_define
define|#
directive|define
name|_VNET_PTR
parameter_list|(
name|b
parameter_list|,
name|n
parameter_list|)
value|&VNET_NAME(n)
end_define

begin_comment
comment|/*  * Virtualized global variable accessor macros.  */
end_comment

begin_define
define|#
directive|define
name|VNET_VNET_PTR
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(&(n))
end_define

begin_define
define|#
directive|define
name|VNET_VNET
parameter_list|(
name|vnet
parameter_list|,
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|VNET_PTR
parameter_list|(
name|n
parameter_list|)
value|(&(n))
end_define

begin_define
define|#
directive|define
name|VNET
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_comment
comment|/*  * When VIMAGE isn't compiled into the kernel, virtaulized SYSCTLs simply  * become normal SYSCTLs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSCTL_OID
end_ifdef

begin_define
define|#
directive|define
name|SYSCTL_VNET_INT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_INT(parent, nbr, name, access, ptr, val, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_PROC
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|arg
parameter_list|,
name|handler
parameter_list|,	\
name|fmt
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_PROC(parent, nbr, name, access, ptr, arg, handler, fmt,	\ 	    descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_OPAQUE
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|len
parameter_list|,
name|fmt
parameter_list|,    \
name|descr
parameter_list|)
define|\
value|SYSCTL_OPAQUE(parent, nbr, name, access, ptr, len, fmt, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRING
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|arg
parameter_list|,
name|len
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_STRING(parent, nbr, name, access, arg, len, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_STRUCT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|type
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_STRUCT(parent, nbr, name, access, ptr, type, descr)
end_define

begin_define
define|#
directive|define
name|SYSCTL_VNET_UINT
parameter_list|(
name|parent
parameter_list|,
name|nbr
parameter_list|,
name|name
parameter_list|,
name|access
parameter_list|,
name|ptr
parameter_list|,
name|val
parameter_list|,
name|descr
parameter_list|)
define|\
value|SYSCTL_UINT(parent, nbr, name, access, ptr, val, descr)
end_define

begin_define
define|#
directive|define
name|VNET_SYSCTL_ARG
parameter_list|(
name|req
parameter_list|,
name|arg1
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSCTL_OID */
end_comment

begin_comment
comment|/*  * When VIMAGE isn't compiled into the kernel, VNET_SYSINIT/VNET_SYSUNINIT  * map into normal sysinits, which have the same ordering properties.  */
end_comment

begin_define
define|#
directive|define
name|VNET_SYSINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|SYSINIT(ident, subsystem, order, func, arg)
end_define

begin_define
define|#
directive|define
name|VNET_SYSUNINIT
parameter_list|(
name|ident
parameter_list|,
name|subsystem
parameter_list|,
name|order
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|)
define|\
value|SYSUNINIT(ident, subsystem, order, func, arg)
end_define

begin_comment
comment|/*  * Without VIMAGE revert to the default implementation.  */
end_comment

begin_define
define|#
directive|define
name|VNET_GLOBAL_EVENTHANDLER_REGISTER_TAG
parameter_list|(
name|tag
parameter_list|,
name|name
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|priority
parameter_list|)
define|\
value|(tag) = eventhandler_register(NULL, #name, func, arg, priority)
end_define

begin_define
define|#
directive|define
name|VNET_GLOBAL_EVENTHANDLER_REGISTER
parameter_list|(
name|name
parameter_list|,
name|func
parameter_list|,
name|arg
parameter_list|,
name|priority
parameter_list|)
define|\
value|eventhandler_register(NULL, #name, func, arg, priority)
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
comment|/* !_NET_VNET_H_ */
end_comment

end_unit

