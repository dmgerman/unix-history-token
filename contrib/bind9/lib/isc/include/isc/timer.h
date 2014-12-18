begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2009, 2012, 2014  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2002  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: timer.h,v 1.43 2009/09/02 23:48:03 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_TIMER_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_TIMER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/timer.h  * \brief Provides timers which are event sources in the task system.  *  * Three types of timers are supported:  *  *\li	'ticker' timers generate a periodic tick event.  *  *\li	'once' timers generate an idle timeout event if they are idle for too  *	long, and generate a life timeout event if their lifetime expires.  *	They are used to implement both (possibly expiring) idle timers and  *	'one-shot' timers.  *  *\li	'limited' timers generate a periodic tick event until they reach  *	their lifetime when they generate a life timeout event.  *  *\li	'inactive' timers generate no events.  *  * Timers can change type.  It is typical to create a timer as  * an 'inactive' timer and then change it into a 'ticker' or  * 'once' timer.  *  *\li MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *	Clients of this module must not be holding a timer's task's lock when  *	making a call that affects that timer.  Failure to follow this rule  *	can result in deadlock.  *	The caller must ensure that isc_timermgr_destroy() is called only  *	once for a given manager.  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	TBS  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/event.h>
end_include

begin_include
include|#
directive|include
file|<isc/eventclass.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/time.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_comment
comment|/*% Timer Type */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_timertype_ticker
init|=
literal|0
block|,
comment|/*%< Ticker */
name|isc_timertype_once
init|=
literal|1
block|,
comment|/*%< Once */
name|isc_timertype_limited
init|=
literal|2
block|,
comment|/*%< Limited */
name|isc_timertype_inactive
init|=
literal|3
comment|/*%< Inactive */
block|}
name|isc_timertype_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_timerevent
block|{
name|struct
name|isc_event
name|common
decl_stmt|;
name|isc_time_t
name|due
decl_stmt|;
block|}
name|isc_timerevent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISC_TIMEREVENT_FIRSTEVENT
value|(ISC_EVENTCLASS_TIMER + 0)
end_define

begin_define
define|#
directive|define
name|ISC_TIMEREVENT_TICK
value|(ISC_EVENTCLASS_TIMER + 1)
end_define

begin_define
define|#
directive|define
name|ISC_TIMEREVENT_IDLE
value|(ISC_EVENTCLASS_TIMER + 2)
end_define

begin_define
define|#
directive|define
name|ISC_TIMEREVENT_LIFE
value|(ISC_EVENTCLASS_TIMER + 3)
end_define

begin_define
define|#
directive|define
name|ISC_TIMEREVENT_LASTEVENT
value|(ISC_EVENTCLASS_TIMER + 65535)
end_define

begin_comment
comment|/*% Timer and timer manager methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_timermgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|timercreate
function_decl|)
parameter_list|(
name|isc_timermgr_t
modifier|*
name|manager
parameter_list|,
name|isc_timertype_t
name|type
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|expires
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|interval
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
block|}
name|isc_timermgrmethods_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|,
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|,
name|isc_timertype_t
name|type
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|expires
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|interval
parameter_list|,
name|isc_boolean_t
name|purge
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|touch
function_decl|)
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|)
function_decl|;
block|}
name|isc_timermethods_t
typedef|;
end_typedef

begin_comment
comment|/*%  * This structure is actually just the common prefix of a timer manager  * object implementation's version of an isc_timermgr_t.  * \brief  * Direct use of this structure by clients is forbidden.  timer implementations  * may change the structure.  'magic' must be ISCAPI_TIMERMGR_MAGIC for any  * of the isc_timer_ routines to work.  timer implementations must maintain  * all timer invariants.  */
end_comment

begin_struct
struct|struct
name|isc_timermgr
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_timermgrmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_TIMERMGR_MAGIC
value|ISC_MAGIC('A','t','m','g')
end_define

begin_define
define|#
directive|define
name|ISCAPI_TIMERMGR_VALID
parameter_list|(
name|m
parameter_list|)
value|((m) != NULL&& \ 					 (m)->magic == ISCAPI_TIMERMGR_MAGIC)
end_define

begin_comment
comment|/*%  * This is the common prefix of a timer object.  The same note as  * that for the timermgr structure applies.  */
end_comment

begin_struct
struct|struct
name|isc_timer
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_timermethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_TIMER_MAGIC
value|ISC_MAGIC('A','t','m','r')
end_define

begin_define
define|#
directive|define
name|ISCAPI_TIMER_VALID
parameter_list|(
name|s
parameter_list|)
value|((s) != NULL&& \ 				 (s)->magic == ISCAPI_TIMER_MAGIC)
end_define

begin_comment
comment|/***  *** Timer and Timer Manager Functions  ***  *** Note: all Ensures conditions apply only if the result is success for  *** those functions which return an isc_result_t.  ***/
end_comment

begin_function_decl
name|isc_result_t
name|isc_timer_create
parameter_list|(
name|isc_timermgr_t
modifier|*
name|manager
parameter_list|,
name|isc_timertype_t
name|type
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|expires
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|interval
parameter_list|,
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a new 'type' timer managed by 'manager'.  The timers parameters  * are specified by 'expires' and 'interval'.  Events will be posted to  * 'task' and when dispatched 'action' will be called with 'arg' as the  * arg value.  The new timer is returned in 'timerp'.  *  * Notes:  *  *\li	For ticker timers, the timer will generate a 'tick' event every  *	'interval' seconds.  The value of 'expires' is ignored.  *  *\li	For once timers, 'expires' specifies the time when a life timeout  *	event should be generated.  If 'expires' is 0 (the epoch), then no life  *	timeout will be generated.  'interval' specifies how long the timer  *	can be idle before it generates an idle timeout.  If 0, then no  *	idle timeout will be generated.  *  *\li	If 'expires' is NULL, the epoch will be used.  *  *	If 'interval' is NULL, the zero interval will be used.  *  * Requires:  *  *\li	'manager' is a valid manager  *  *\li	'task' is a valid task  *  *\li	'action' is a valid action  *  *\li	'expires' points to a valid time, or is NULL.  *  *\li	'interval' points to a valid interval, or is NULL.  *  *\li	type == isc_timertype_inactive ||  *	('expires' and 'interval' are not both 0)  *  *\li	'timerp' is a valid pointer, and *timerp == NULL  *  * Ensures:  *  *\li	'*timerp' is attached to the newly created timer  *  *\li	The timer is attached to the task  *  *\li	An idle timeout will not be generated until at least Now + the  *	timer's interval if 'timer' is a once timer with a non-zero  *	interval.  *  * Returns:  *  *\li	Success  *\li	No memory  *\li	Unexpected error  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_timer_reset
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|,
name|isc_timertype_t
name|type
parameter_list|,
specifier|const
name|isc_time_t
modifier|*
name|expires
parameter_list|,
specifier|const
name|isc_interval_t
modifier|*
name|interval
parameter_list|,
name|isc_boolean_t
name|purge
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Change the timer's type, expires, and interval values to the given  * values.  If 'purge' is TRUE, any pending events from this timer  * are purged from its task's event queue.  *  * Notes:  *  *\li	If 'expires' is NULL, the epoch will be used.  *  *\li	If 'interval' is NULL, the zero interval will be used.  *  * Requires:  *  *\li	'timer' is a valid timer  *  *\li	The same requirements that isc_timer_create() imposes on 'type',  *	'expires' and 'interval' apply.  *  * Ensures:  *  *\li	An idle timeout will not be generated until at least Now + the  *	timer's interval if 'timer' is a once timer with a non-zero  *	interval.  *  * Returns:  *  *\li	Success  *\li	No memory  *\li	Unexpected error  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_timer_touch
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the last-touched time of 'timer' to the current time.  *  * Requires:  *  *\li	'timer' is a valid once timer.  *  * Ensures:  *  *\li	An idle timeout will not be generated until at least Now + the  *	timer's interval if 'timer' is a once timer with a non-zero  *	interval.  *  * Returns:  *  *\li	Success  *\li	Unexpected error  */
end_comment

begin_function_decl
name|void
name|isc_timer_attach
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|,
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach *timerp to timer.  *  * Requires:  *  *\li	'timer' is a valid timer.  *  *\li	'timerp' points to a NULL timer.  *  * Ensures:  *  *\li	*timerp is attached to timer.  */
end_comment

begin_function_decl
name|void
name|isc_timer_detach
parameter_list|(
name|isc_timer_t
modifier|*
modifier|*
name|timerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach *timerp from its timer.  *  * Requires:  *  *\li	'timerp' points to a valid timer.  *  * Ensures:  *  *\li	*timerp is NULL.  *  *\li	If '*timerp' is the last reference to the timer,  *	then:  *  *\code  *		The timer will be shutdown  *  *		The timer will detach from its task  *  *		All resources used by the timer have been freed  *  *		Any events already posted by the timer will be purged.  *		Therefore, if isc_timer_detach() is called in the context  *		of the timer's task, it is guaranteed that no more  *		timer event callbacks will run after the call.  *\endcode  */
end_comment

begin_function_decl
name|isc_timertype_t
name|isc_timer_gettype
parameter_list|(
name|isc_timer_t
modifier|*
name|timer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Return the timer type.  *  * Requires:  *  *\li	'timer' to be a valid timer.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_timermgr_createinctx
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
name|actx
parameter_list|,
name|isc_timermgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_timermgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_timermgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a timer manager.  isc_timermgr_createinctx() also associates  * the new manager with the specified application context.  *  * Notes:  *  *\li	All memory will be allocated in memory context 'mctx'.  *  * Requires:  *  *\li	'mctx' is a valid memory context.  *  *\li	'managerp' points to a NULL isc_timermgr_t.  *  *\li	'actx' is a valid application context (for createinctx()).  *  * Ensures:  *  *\li	'*managerp' is a valid isc_timermgr_t.  *  * Returns:  *  *\li	Success  *\li	No memory  *\li	Unexpected error  */
end_comment

begin_function_decl
name|void
name|isc_timermgr_destroy
parameter_list|(
name|isc_timermgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a timer manager.  *  * Notes:  *  *\li	This routine blocks until there are no timers left in the manager,  *	so if the caller holds any timer references using the manager, it  *	must detach them before calling isc_timermgr_destroy() or it will  *	block forever.  *  * Requires:  *  *\li	'*managerp' is a valid isc_timermgr_t.  *  * Ensures:  *  *\li	*managerp == NULL  *  *\li	All resources used by the manager have been freed.  */
end_comment

begin_function_decl
name|void
name|isc_timermgr_poke
parameter_list|(
name|isc_timermgr_t
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|USE_TIMERIMPREGISTER
end_ifdef

begin_comment
comment|/*%<  * See isc_timermgr_create() above.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_timermgrcreatefunc_t
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_timermgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc__timer_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a new timer management implementation and add it to the list of  * supported implementations.  This function must be called when a different  * event library is used than the one contained in the ISC library.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_timer_register
parameter_list|(
name|isc_timermgrcreatefunc_t
name|createfunc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * A short cut function that specifies the timer management module in the ISC  * library for isc_timer_register().  An application that uses the ISC library  * usually do not have to care about this function: it would call  * isc_lib_register(), which internally calls this function.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_TIMERIMPREGISTER */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TIMER_H */
end_comment

end_unit

