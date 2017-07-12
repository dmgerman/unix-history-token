begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith<msmith@freebsd.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_EVENTHANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|SYS_EVENTHANDLER_H
end_define

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_struct
struct|struct
name|eventhandler_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|eventhandler_entry
argument_list|)
name|ee_link
expr_stmt|;
name|int
name|ee_priority
decl_stmt|;
define|#
directive|define
name|EHE_DEAD_PRIORITY
value|(-1)
name|void
modifier|*
name|ee_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_struct
struct|struct
name|eventhandler_entry_vimage
block|{
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Original function registered. */
name|void
modifier|*
name|ee_arg
decl_stmt|;
comment|/* Original argument registered. */
name|void
modifier|*
name|sparep
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|eventhandler_list
block|{
name|char
modifier|*
name|el_name
decl_stmt|;
name|int
name|el_flags
decl_stmt|;
define|#
directive|define
name|EHL_INITTED
value|(1<<0)
name|u_int
name|el_runcount
decl_stmt|;
name|struct
name|mtx
name|el_lock
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|eventhandler_list
argument_list|)
name|el_link
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|eventhandler_entry
argument_list|)
name|el_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|eventhandler_entry
modifier|*
name|eventhandler_tag
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EHL_LOCK
parameter_list|(
name|p
parameter_list|)
value|mtx_lock(&(p)->el_lock)
end_define

begin_define
define|#
directive|define
name|EHL_UNLOCK
parameter_list|(
name|p
parameter_list|)
value|mtx_unlock(&(p)->el_lock)
end_define

begin_define
define|#
directive|define
name|EHL_LOCK_ASSERT
parameter_list|(
name|p
parameter_list|,
name|x
parameter_list|)
value|mtx_assert(&(p)->el_lock, x)
end_define

begin_comment
comment|/*  * Macro to invoke the handlers for a given event.  */
end_comment

begin_define
define|#
directive|define
name|_EVENTHANDLER_INVOKE
parameter_list|(
name|name
parameter_list|,
name|list
parameter_list|,
modifier|...
parameter_list|)
value|do {			\ 	struct eventhandler_entry *_ep;					\ 	struct eventhandler_entry_ ## name *_t;				\ 									\ 	KASSERT((list)->el_flags& EHL_INITTED,				\  	   ("eventhandler_invoke: running non-inited list"));		\ 	EHL_LOCK_ASSERT((list), MA_OWNED);				\ 	(list)->el_runcount++;						\ 	KASSERT((list)->el_runcount> 0,				\ 	    ("eventhandler_invoke: runcount overflow"));		\ 	CTR0(KTR_EVH, "eventhandler_invoke(\"" __STRING(name) "\")");	\ 	TAILQ_FOREACH(_ep,&((list)->el_entries), ee_link) {		\ 		if (_ep->ee_priority != EHE_DEAD_PRIORITY) {		\ 			EHL_UNLOCK((list));				\ 			_t = (struct eventhandler_entry_ ## name *)_ep;	\ 			CTR1(KTR_EVH, "eventhandler_invoke: executing %p", \  			    (void *)_t->eh_func);			\ 			_t->eh_func(_ep->ee_arg , ## __VA_ARGS__);	\ 			EHL_LOCK((list));				\ 		}							\ 	}								\ 	KASSERT((list)->el_runcount> 0,				\ 	    ("eventhandler_invoke: runcount underflow"));		\ 	(list)->el_runcount--;						\ 	if ((list)->el_runcount == 0)					\ 		eventhandler_prune_list(list);				\ 	EHL_UNLOCK((list));						\ } while (0)
end_define

begin_comment
comment|/*  * Slow handlers are entirely dynamic; lists are created  * when entries are added to them, and thus have no concept of "owner",  *  * Slow handlers need to be declared, but do not need to be defined. The  * declaration must be in scope wherever the handler is to be invoked.  */
end_comment

begin_define
define|#
directive|define
name|EVENTHANDLER_DECLARE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct eventhandler_entry_ ## name 					\ {									\ 	struct eventhandler_entry	ee;				\ 	type				eh_func;			\ };									\ struct __hack
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_DEFINE
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
value|static eventhandler_tag name ## _tag;				\ 	static void name ## _evh_init(void *ctx)			\ 	{								\ 		name ## _tag = EVENTHANDLER_REGISTER(name, func, ctx,	\ 		    priority);						\ 	}								\ 	SYSINIT(name ## _evh_init, SI_SUB_CONFIGURE, SI_ORDER_ANY,	\ 	    name ## _evh_init, arg);					\ 	struct __hack
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_INVOKE
parameter_list|(
name|name
parameter_list|,
modifier|...
parameter_list|)
define|\
value|do {									\ 	struct eventhandler_list *_el;					\ 									\ 	if ((_el = eventhandler_find_list(#name)) != NULL) 		\ 		_EVENTHANDLER_INVOKE(name, _el , ## __VA_ARGS__);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_REGISTER
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

begin_define
define|#
directive|define
name|EVENTHANDLER_DEREGISTER
parameter_list|(
name|name
parameter_list|,
name|tag
parameter_list|)
define|\
value|do {									\ 	struct eventhandler_list *_el;					\ 									\ 	if ((_el = eventhandler_find_list(#name)) != NULL)		\ 		eventhandler_deregister(_el, tag);			\ } while(0)
end_define

begin_function_decl
name|eventhandler_tag
name|eventhandler_register
parameter_list|(
name|struct
name|eventhandler_list
modifier|*
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|priority
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eventhandler_deregister
parameter_list|(
name|struct
name|eventhandler_list
modifier|*
name|list
parameter_list|,
name|eventhandler_tag
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|eventhandler_list
modifier|*
name|eventhandler_find_list
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|eventhandler_prune_list
parameter_list|(
name|struct
name|eventhandler_list
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|VIMAGE
end_ifdef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vimage_iterator_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|eventhandler_tag
name|vimage_eventhandler_register
parameter_list|(
name|struct
name|eventhandler_list
modifier|*
name|list
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|func
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|priority
parameter_list|,
name|vimage_iterator_func_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Standard system event queues.  */
end_comment

begin_comment
comment|/* Generic priority levels */
end_comment

begin_define
define|#
directive|define
name|EVENTHANDLER_PRI_FIRST
value|0
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_PRI_ANY
value|10000
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_PRI_LAST
value|20000
end_define

begin_comment
comment|/* Shutdown events */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|shutdown_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|SHUTDOWN_PRI_FIRST
value|EVENTHANDLER_PRI_FIRST
end_define

begin_define
define|#
directive|define
name|SHUTDOWN_PRI_DEFAULT
value|EVENTHANDLER_PRI_ANY
end_define

begin_define
define|#
directive|define
name|SHUTDOWN_PRI_LAST
value|EVENTHANDLER_PRI_LAST
end_define

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|shutdown_pre_sync
argument_list|,
name|shutdown_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* before fs sync */
end_comment

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|shutdown_post_sync
argument_list|,
name|shutdown_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* after fs sync */
end_comment

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|shutdown_final
argument_list|,
name|shutdown_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Power state change events */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|power_change_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|power_resume
argument_list|,
name|power_change_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|power_suspend
argument_list|,
name|power_change_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|power_suspend_early
argument_list|,
name|power_change_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Low memory event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vm_lowmem_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|LOWMEM_PRI_DEFAULT
value|EVENTHANDLER_PRI_FIRST
end_define

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|vm_lowmem
argument_list|,
name|vm_lowmem_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Root mounted event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|mountroot_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|mountroot
argument_list|,
name|mountroot_handler_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* File system mount events */
end_comment

begin_struct_decl
struct_decl|struct
name|mount
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vnode
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfs_mounted_notify_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|vnode
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vfs_unmounted_notify_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|mount
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|vfs_mounted
argument_list|,
name|vfs_mounted_notify_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|vfs_unmounted
argument_list|,
name|vfs_unmounted_notify_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* VLAN state change events */
end_comment

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vlan_config_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|vlan_unconfig_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|vlan_config
argument_list|,
name|vlan_config_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|vlan_unconfig
argument_list|,
name|vlan_unconfig_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* BPF attach/detach events */
end_comment

begin_struct_decl
struct_decl|struct
name|ifnet
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bpf_track_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
comment|/* dlt */
parameter_list|,
name|int
comment|/* 1 =>'s attach */
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|bpf_track
argument_list|,
name|bpf_track_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Process events  * process_fork and exit handlers are called without Giant.  * exec handlers are called with Giant, but that is by accident.  */
end_comment

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|image_params
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|exitlist_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|forklist_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|execlist_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|,
name|struct
name|image_params
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_ctor_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_dtor_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_init_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|proc_fini_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_ctor
argument_list|,
name|proc_ctor_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_dtor
argument_list|,
name|proc_dtor_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_init
argument_list|,
name|proc_init_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_fini
argument_list|,
name|proc_fini_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_exit
argument_list|,
name|exitlist_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_fork
argument_list|,
name|forklist_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|process_exec
argument_list|,
name|execlist_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * application dump event  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|app_coredump_start_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|app_coredump_progress_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|byte_count
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|app_coredump_finish_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|app_coredump_error_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|msg
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|app_coredump_start
argument_list|,
name|app_coredump_start_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|app_coredump_progress
argument_list|,
name|app_coredump_progress_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|app_coredump_finish
argument_list|,
name|app_coredump_finish_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|app_coredump_error
argument_list|,
name|app_coredump_error_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|thread_ctor_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|thread_dtor_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|thread_fini_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|thread_init_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|thread_ctor
argument_list|,
name|thread_ctor_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|thread_dtor
argument_list|,
name|thread_dtor_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|thread_init
argument_list|,
name|thread_init_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|thread_fini
argument_list|,
name|thread_fini_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|uma_zone_chfn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|nmbclusters_change
argument_list|,
name|uma_zone_chfn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|nmbufs_change
argument_list|,
name|uma_zone_chfn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|maxsockets_change
argument_list|,
name|uma_zone_chfn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Kernel linker file load and unload events */
end_comment

begin_struct_decl
struct_decl|struct
name|linker_file
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|kld_load_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|linker_file
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|kld_unload_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|kld_unload_try_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|linker_file
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|kld_load
argument_list|,
name|kld_load_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|kld_unload
argument_list|,
name|kld_unload_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|kld_unload_try
argument_list|,
name|kld_unload_try_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Generic graphics framebuffer interface */
end_comment

begin_struct_decl
struct_decl|struct
name|fb_info
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|register_framebuffer_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fb_info
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|unregister_framebuffer_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|fb_info
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|register_framebuffer
argument_list|,
name|register_framebuffer_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|unregister_framebuffer
argument_list|,
name|unregister_framebuffer_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* veto ada probing */
end_comment

begin_struct_decl
struct_decl|struct
name|cam_path
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ata_params
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ada_probe_veto_fn
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|struct
name|cam_path
modifier|*
parameter_list|,
name|struct
name|ata_params
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_expr_stmt
name|EVENTHANDLER_DECLARE
argument_list|(
name|ada_probe_veto
argument_list|,
name|ada_probe_veto_fn
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_EVENTHANDLER_H */
end_comment

end_unit

