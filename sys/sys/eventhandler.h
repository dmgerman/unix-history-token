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

begin_comment
comment|/*  * XXX - compatability until lockmgr() goes away or all the #includes are  * updated.  */
end_comment

begin_include
include|#
directive|include
file|<sys/lockmgr.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/_lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/_mutex.h>
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
name|void
modifier|*
name|ee_arg
decl_stmt|;
block|}
struct|;
end_struct

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
name|EHE_INITTED
value|(1<<0)
name|struct
name|lock
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

begin_comment
comment|/*   * Fast handler lists require the eventhandler list be present  * at link time.  They don't allow addition of entries to  * unknown eventhandler lists, ie. each list must have an   * "owner".  *  * Fast handler lists must be defined once by the owner   * of the eventhandler list, and the declaration must be in   * scope at any point the list is manipulated.  */
end_comment

begin_define
define|#
directive|define
name|EVENTHANDLER_FAST_DECLARE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|extern struct eventhandler_list Xeventhandler_list_ ## name ;	\ struct eventhandler_entry_ ## name 				\ {								\     struct eventhandler_entry	ee;				\     type		eh_func;				\ };								\ struct __hack
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_FAST_DEFINE
parameter_list|(
name|name
parameter_list|,
name|type
parameter_list|)
define|\
value|struct eventhandler_list Xeventhandler_list_ ## name = { #name };	\ struct __hack
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_FAST_INVOKE
parameter_list|(
name|name
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {										\     struct eventhandler_list *_el =&Xeventhandler_list_ ## name ;		\     struct eventhandler_entry *_ep, *_en;					\ 										\     if (_el->el_flags& EHE_INITTED) {						\ 	lockmgr(&_el->el_lock, LK_EXCLUSIVE, NULL, curthread);			\ 	_ep = TAILQ_FIRST(&(_el->el_entries));					\ 	while (_ep != NULL) {							\ 	    _en = TAILQ_NEXT(_ep, ee_link);					\ 	    ((struct eventhandler_entry_ ## name *)_ep)->eh_func(_ep->ee_arg , 	\ 								 ## args); 	\ 	    _ep = _en;								\ 	}									\ 	lockmgr(&_el->el_lock, LK_RELEASE, NULL, curthread);			\     }										\ } while (0)
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_FAST_REGISTER
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
value|eventhandler_register(&Xeventhandler_list_ ## name, #name, func, arg, priority)
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_FAST_DEREGISTER
parameter_list|(
name|name
parameter_list|,
name|tag
parameter_list|)
define|\
value|eventhandler_deregister(&Xeventhandler_list_ ## name, tag)
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
value|struct eventhandler_entry_ ## name 		\ {						\     struct eventhandler_entry	ee;		\     type		eh_func;		\ };						\ struct __hack
end_define

begin_define
define|#
directive|define
name|EVENTHANDLER_INVOKE
parameter_list|(
name|name
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|do {										\     struct eventhandler_list *_el;						\     struct eventhandler_entry *_ep, *_en;					\ 										\     if (((_el = eventhandler_find_list(#name)) != NULL)&& 			\ 	(_el->el_flags& EHE_INITTED)) {					\ 	lockmgr(&_el->el_lock, LK_EXCLUSIVE, NULL, curthread);			\ 	_ep = TAILQ_FIRST(&(_el->el_entries));					\ 	while (_ep != NULL) {							\ 	    _en = TAILQ_NEXT(_ep, ee_link);					\ 	    ((struct eventhandler_entry_ ## name *)_ep)->eh_func(_ep->ee_arg , 	\ 								 ## args); 	\ 	    _ep = _en;								\ 	}									\ 	lockmgr(&_el->el_lock, LK_RELEASE, NULL, curthread);			\     }										\ } while (0)
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
value|do {							\     struct eventhandler_list *_el;			\ 							\     if ((_el = eventhandler_find_list(#name)) != NULL)	\ 	eventhandler_deregister(_el, tag);		\ } while(0)
end_define

begin_function_decl
specifier|extern
name|eventhandler_tag
name|eventhandler_register
parameter_list|(
name|struct
name|eventhandler_list
modifier|*
name|list
parameter_list|,
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
specifier|extern
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
specifier|extern
name|struct
name|eventhandler_list
modifier|*
name|eventhandler_find_list
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Standard system event queues.  */
end_comment

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
value|0
end_define

begin_define
define|#
directive|define
name|SHUTDOWN_PRI_DEFAULT
value|10000
end_define

begin_define
define|#
directive|define
name|SHUTDOWN_PRI_LAST
value|20000
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
comment|/* Idle process event */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|idle_eventhandler_t
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
name|IDLE_PRI_FIRST
value|10000
end_define

begin_define
define|#
directive|define
name|IDLE_PRI_LAST
value|20000
end_define

begin_expr_stmt
name|EVENTHANDLER_FAST_DECLARE
argument_list|(
name|idle_event
argument_list|,
name|idle_eventhandler_t
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

