begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2009-2012  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCAPI_NAMESPACE_H
end_ifndef

begin_define
define|#
directive|define
name|ISCAPI_NAMESPACE_H
value|1
end_define

begin_comment
comment|/*%  * name space conversions  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BIND9
end_ifdef

begin_define
define|#
directive|define
name|isc_app_start
value|isc__app_start
end_define

begin_define
define|#
directive|define
name|isc_app_ctxstart
value|isc__app_ctxstart
end_define

begin_define
define|#
directive|define
name|isc_app_onrun
value|isc__app_onrun
end_define

begin_define
define|#
directive|define
name|isc_app_run
value|isc__app_run
end_define

begin_define
define|#
directive|define
name|isc_app_ctxrun
value|isc__app_ctxrun
end_define

begin_define
define|#
directive|define
name|isc_app_shutdown
value|isc__app_shutdown
end_define

begin_define
define|#
directive|define
name|isc_app_ctxfinish
value|isc__app_ctxfinish
end_define

begin_define
define|#
directive|define
name|isc_app_ctxshutdown
value|isc__app_ctxshutdown
end_define

begin_define
define|#
directive|define
name|isc_app_ctxsuspend
value|isc__app_ctxsuspend
end_define

begin_define
define|#
directive|define
name|isc_app_reload
value|isc__app_reload
end_define

begin_define
define|#
directive|define
name|isc_app_finish
value|isc__app_finish
end_define

begin_define
define|#
directive|define
name|isc_app_block
value|isc__app_block
end_define

begin_define
define|#
directive|define
name|isc_app_unblock
value|isc__app_unblock
end_define

begin_define
define|#
directive|define
name|isc_appctx_create
value|isc__appctx_create
end_define

begin_define
define|#
directive|define
name|isc_appctx_destroy
value|isc__appctx_destroy
end_define

begin_define
define|#
directive|define
name|isc_appctx_settaskmgr
value|isc__appctx_settaskmgr
end_define

begin_define
define|#
directive|define
name|isc_appctx_setsocketmgr
value|isc__appctx_setsocketmgr
end_define

begin_define
define|#
directive|define
name|isc_appctx_settimermgr
value|isc__appctx_settimermgr
end_define

begin_define
define|#
directive|define
name|isc_mem_checkdestroyed
value|isc__mem_checkdestroyed
end_define

begin_define
define|#
directive|define
name|isc_mem_createx
value|isc__mem_createx
end_define

begin_define
define|#
directive|define
name|isc_mem_createx2
value|isc__mem_createx2
end_define

begin_define
define|#
directive|define
name|isc_mem_create
value|isc__mem_create
end_define

begin_define
define|#
directive|define
name|isc_mem_create2
value|isc__mem_create2
end_define

begin_define
define|#
directive|define
name|isc_mem_attach
value|isc__mem_attach
end_define

begin_define
define|#
directive|define
name|isc_mem_detach
value|isc__mem_detach
end_define

begin_define
define|#
directive|define
name|isc__mem_putanddetach
value|isc___mem_putanddetach
end_define

begin_define
define|#
directive|define
name|isc_mem_destroy
value|isc__mem_destroy
end_define

begin_define
define|#
directive|define
name|isc_mem_ondestroy
value|isc__mem_ondestroy
end_define

begin_define
define|#
directive|define
name|isc__mem_get
value|isc___mem_get
end_define

begin_define
define|#
directive|define
name|isc__mem_put
value|isc___mem_put
end_define

begin_define
define|#
directive|define
name|isc_mem_stats
value|isc__mem_stats
end_define

begin_define
define|#
directive|define
name|isc__mem_allocate
value|isc___mem_allocate
end_define

begin_define
define|#
directive|define
name|isc__mem_free
value|isc___mem_free
end_define

begin_define
define|#
directive|define
name|isc__mem_strdup
value|isc___mem_strdup
end_define

begin_define
define|#
directive|define
name|isc__mem_reallocate
value|isc___mem_reallocate
end_define

begin_define
define|#
directive|define
name|isc_mem_references
value|isc__mem_references
end_define

begin_define
define|#
directive|define
name|isc_mem_setdestroycheck
value|isc__mem_setdestroycheck
end_define

begin_define
define|#
directive|define
name|isc_mem_setquota
value|isc__mem_setquota
end_define

begin_define
define|#
directive|define
name|isc_mem_getname
value|isc__mem_getname
end_define

begin_define
define|#
directive|define
name|isc_mem_getquota
value|isc__mem_getquota
end_define

begin_define
define|#
directive|define
name|isc_mem_gettag
value|isc__mem_gettag
end_define

begin_define
define|#
directive|define
name|isc_mem_inuse
value|isc__mem_inuse
end_define

begin_define
define|#
directive|define
name|isc_mem_isovermem
value|isc__mem_isovermem
end_define

begin_define
define|#
directive|define
name|isc_mem_setname
value|isc__mem_setname
end_define

begin_define
define|#
directive|define
name|isc_mem_setwater
value|isc__mem_setwater
end_define

begin_define
define|#
directive|define
name|isc_mem_printallactive
value|isc__mem_printallactive
end_define

begin_define
define|#
directive|define
name|isc_mem_waterack
value|isc__mem_waterack
end_define

begin_define
define|#
directive|define
name|isc_mempool_create
value|isc__mempool_create
end_define

begin_define
define|#
directive|define
name|isc_mempool_setname
value|isc__mempool_setname
end_define

begin_define
define|#
directive|define
name|isc_mempool_destroy
value|isc__mempool_destroy
end_define

begin_define
define|#
directive|define
name|isc_mempool_associatelock
value|isc__mempool_associatelock
end_define

begin_define
define|#
directive|define
name|isc__mempool_get
value|isc___mempool_get
end_define

begin_define
define|#
directive|define
name|isc__mempool_put
value|isc___mempool_put
end_define

begin_define
define|#
directive|define
name|isc_mempool_setfreemax
value|isc__mempool_setfreemax
end_define

begin_define
define|#
directive|define
name|isc_mempool_getfreemax
value|isc__mempool_getfreemax
end_define

begin_define
define|#
directive|define
name|isc_mempool_getfreecount
value|isc__mempool_getfreecount
end_define

begin_define
define|#
directive|define
name|isc_mempool_setmaxalloc
value|isc__mempool_setmaxalloc
end_define

begin_define
define|#
directive|define
name|isc_mempool_getmaxalloc
value|isc__mempool_getmaxalloc
end_define

begin_define
define|#
directive|define
name|isc_mempool_getallocated
value|isc__mempool_getallocated
end_define

begin_define
define|#
directive|define
name|isc_mempool_setfillcount
value|isc__mempool_setfillcount
end_define

begin_define
define|#
directive|define
name|isc_mempool_getfillcount
value|isc__mempool_getfillcount
end_define

begin_define
define|#
directive|define
name|isc_socket_create
value|isc__socket_create
end_define

begin_define
define|#
directive|define
name|isc_socket_dup
value|isc__socket_dup
end_define

begin_define
define|#
directive|define
name|isc_socket_attach
value|isc__socket_attach
end_define

begin_define
define|#
directive|define
name|isc_socket_detach
value|isc__socket_detach
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_create
value|isc__socketmgr_create
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_create2
value|isc__socketmgr_create2
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_destroy
value|isc__socketmgr_destroy
end_define

begin_define
define|#
directive|define
name|isc_socket_open
value|isc__socket_open
end_define

begin_define
define|#
directive|define
name|isc_socket_close
value|isc__socket_close
end_define

begin_define
define|#
directive|define
name|isc_socket_recvv
value|isc__socket_recvv
end_define

begin_define
define|#
directive|define
name|isc_socket_recv
value|isc__socket_recv
end_define

begin_define
define|#
directive|define
name|isc_socket_recv2
value|isc__socket_recv2
end_define

begin_define
define|#
directive|define
name|isc_socket_send
value|isc__socket_send
end_define

begin_define
define|#
directive|define
name|isc_socket_sendto
value|isc__socket_sendto
end_define

begin_define
define|#
directive|define
name|isc_socket_sendv
value|isc__socket_sendv
end_define

begin_define
define|#
directive|define
name|isc_socket_sendtov
value|isc__socket_sendtov
end_define

begin_define
define|#
directive|define
name|isc_socket_sendto2
value|isc__socket_sendto2
end_define

begin_define
define|#
directive|define
name|isc_socket_cleanunix
value|isc__socket_cleanunix
end_define

begin_define
define|#
directive|define
name|isc_socket_permunix
value|isc__socket_permunix
end_define

begin_define
define|#
directive|define
name|isc_socket_bind
value|isc__socket_bind
end_define

begin_define
define|#
directive|define
name|isc_socket_filter
value|isc__socket_filter
end_define

begin_define
define|#
directive|define
name|isc_socket_listen
value|isc__socket_listen
end_define

begin_define
define|#
directive|define
name|isc_socket_accept
value|isc__socket_accept
end_define

begin_define
define|#
directive|define
name|isc_socket_connect
value|isc__socket_connect
end_define

begin_define
define|#
directive|define
name|isc_socket_getfd
value|isc__socket_getfd
end_define

begin_define
define|#
directive|define
name|isc_socket_getname
value|isc__socket_getname
end_define

begin_define
define|#
directive|define
name|isc_socket_gettag
value|isc__socket_gettag
end_define

begin_define
define|#
directive|define
name|isc_socket_getpeername
value|isc__socket_getpeername
end_define

begin_define
define|#
directive|define
name|isc_socket_getsockname
value|isc__socket_getsockname
end_define

begin_define
define|#
directive|define
name|isc_socket_cancel
value|isc__socket_cancel
end_define

begin_define
define|#
directive|define
name|isc_socket_gettype
value|isc__socket_gettype
end_define

begin_define
define|#
directive|define
name|isc_socket_isbound
value|isc__socket_isbound
end_define

begin_define
define|#
directive|define
name|isc_socket_ipv6only
value|isc__socket_ipv6only
end_define

begin_define
define|#
directive|define
name|isc_socket_setname
value|isc__socket_setname
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_getmaxsockets
value|isc__socketmgr_getmaxsockets
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_setstats
value|isc__socketmgr_setstats
end_define

begin_define
define|#
directive|define
name|isc_socketmgr_setreserved
value|isc__socketmgr_setreserved
end_define

begin_define
define|#
directive|define
name|isc__socketmgr_maxudp
value|isc___socketmgr_maxudp
end_define

begin_define
define|#
directive|define
name|isc_socket_fdwatchcreate
value|isc__socket_fdwatchcreate
end_define

begin_define
define|#
directive|define
name|isc_socket_fdwatchpoke
value|isc__socket_fdwatchpoke
end_define

begin_define
define|#
directive|define
name|isc_task_create
value|isc__task_create
end_define

begin_define
define|#
directive|define
name|isc_task_attach
value|isc__task_attach
end_define

begin_define
define|#
directive|define
name|isc_task_detach
value|isc__task_detach
end_define

begin_comment
comment|/* #define isc_task_exiting isc__task_exiting XXXMPA */
end_comment

begin_define
define|#
directive|define
name|isc_task_send
value|isc__task_send
end_define

begin_define
define|#
directive|define
name|isc_task_sendanddetach
value|isc__task_sendanddetach
end_define

begin_define
define|#
directive|define
name|isc_task_purgerange
value|isc__task_purgerange
end_define

begin_define
define|#
directive|define
name|isc_task_purge
value|isc__task_purge
end_define

begin_define
define|#
directive|define
name|isc_task_purgeevent
value|isc__task_purgeevent
end_define

begin_define
define|#
directive|define
name|isc_task_unsendrange
value|isc__task_unsendrange
end_define

begin_define
define|#
directive|define
name|isc_task_unsend
value|isc__task_unsend
end_define

begin_define
define|#
directive|define
name|isc_task_onshutdown
value|isc__task_onshutdown
end_define

begin_define
define|#
directive|define
name|isc_task_shutdown
value|isc__task_shutdown
end_define

begin_define
define|#
directive|define
name|isc_task_destroy
value|isc__task_destroy
end_define

begin_define
define|#
directive|define
name|isc_task_setname
value|isc__task_setname
end_define

begin_define
define|#
directive|define
name|isc_task_getname
value|isc__task_getname
end_define

begin_define
define|#
directive|define
name|isc_task_gettag
value|isc__task_gettag
end_define

begin_define
define|#
directive|define
name|isc_task_getcurrenttime
value|isc__task_getcurrenttime
end_define

begin_define
define|#
directive|define
name|isc_taskmgr_create
value|isc__taskmgr_create
end_define

begin_define
define|#
directive|define
name|isc_taskmgr_setmode
value|isc__taskmgr_setmode
end_define

begin_define
define|#
directive|define
name|isc_taskmgr_mode
value|isc__taskmgr_mode
end_define

begin_define
define|#
directive|define
name|isc_taskmgr_destroy
value|isc__taskmgr_destroy
end_define

begin_define
define|#
directive|define
name|isc_task_beginexclusive
value|isc__task_beginexclusive
end_define

begin_define
define|#
directive|define
name|isc_task_endexclusive
value|isc__task_endexclusive
end_define

begin_define
define|#
directive|define
name|isc_task_setprivilege
value|isc__task_setprivilege
end_define

begin_define
define|#
directive|define
name|isc_task_privilege
value|isc__task_privilege
end_define

begin_define
define|#
directive|define
name|isc_timer_create
value|isc__timer_create
end_define

begin_define
define|#
directive|define
name|isc_timer_reset
value|isc__timer_reset
end_define

begin_define
define|#
directive|define
name|isc_timer_gettype
value|isc__timer_gettype
end_define

begin_define
define|#
directive|define
name|isc_timer_touch
value|isc__timer_touch
end_define

begin_define
define|#
directive|define
name|isc_timer_attach
value|isc__timer_attach
end_define

begin_define
define|#
directive|define
name|isc_timer_detach
value|isc__timer_detach
end_define

begin_define
define|#
directive|define
name|isc_timermgr_create
value|isc__timermgr_create
end_define

begin_define
define|#
directive|define
name|isc_timermgr_poke
value|isc__timermgr_poke
end_define

begin_define
define|#
directive|define
name|isc_timermgr_destroy
value|isc__timermgr_destroy
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BIND9 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCAPI_NAMESPACE_H */
end_comment

end_unit

