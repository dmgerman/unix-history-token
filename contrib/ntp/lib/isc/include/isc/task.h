begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009-2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_TASK_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_TASK_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/task.h  * \brief The task system provides a lightweight execution context, which is  * basically an event queue.   * When a task's event queue is non-empty, the  * task is runnable.  A small work crew of threads, typically one per CPU,  * execute runnable tasks by dispatching the events on the tasks' event  * queues.  Context switching between tasks is fast.  *  * \li MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *	The caller must ensure that isc_taskmgr_destroy() is called only  *	once for a given manager.  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	TBS  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  *	None.  *  * \section purge Purging and Unsending  *  * Events which have been queued for a task but not delivered may be removed  * from the task's event queue by purging or unsending.  *  * With both types, the caller specifies a matching pattern that selects  * events based upon their sender, type, and tag.  *  * Purging calls isc_event_free() on the matching events.  *  * Unsending returns a list of events that matched the pattern.  * The caller is then responsible for them.  *  * Consumers of events should purge, not unsend.  *  * Producers of events often want to remove events when the caller indicates  * it is no longer interested in the object, e.g. by canceling a timer.  * Sometimes this can be done by purging, but for some event types, the  * calls to isc_event_free() cause deadlock because the event free routine  * wants to acquire a lock the caller is already holding.  Unsending instead  * of purging solves this problem.  As a general rule, producers should only  * unsend events which they have sent.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

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
file|<isc/stdtime.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_include
include|#
directive|include
file|<isc/xml.h>
end_include

begin_define
define|#
directive|define
name|ISC_TASKEVENT_FIRSTEVENT
value|(ISC_EVENTCLASS_TASK + 0)
end_define

begin_define
define|#
directive|define
name|ISC_TASKEVENT_SHUTDOWN
value|(ISC_EVENTCLASS_TASK + 1)
end_define

begin_define
define|#
directive|define
name|ISC_TASKEVENT_TEST
value|(ISC_EVENTCLASS_TASK + 1)
end_define

begin_define
define|#
directive|define
name|ISC_TASKEVENT_LASTEVENT
value|(ISC_EVENTCLASS_TASK + 65535)
end_define

begin_comment
comment|/*****  ***** Tasks.  *****/
end_comment

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_taskmgrmode_normal
init|=
literal|0
block|,
name|isc_taskmgrmode_privileged
block|}
name|isc_taskmgrmode_t
typedef|;
end_typedef

begin_comment
comment|/*% Task and task manager methods */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_taskmgrmethods
block|{
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_taskmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|,
name|isc_taskmgrmode_t
name|mode
parameter_list|)
function_decl|;
name|isc_taskmgrmode_t
function_decl|(
modifier|*
name|mode
function_decl|)
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|taskcreate
function_decl|)
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|,
name|unsigned
name|int
name|quantum
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
block|}
name|isc_taskmgrmethods_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|isc_taskmethods
block|{
name|void
function_decl|(
modifier|*
name|attach
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|source
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|detach
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|send
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sendanddetach
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|unsend
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|type
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|,
name|isc_eventlist_t
modifier|*
name|events
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|onshutdown
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|shutdown
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setname
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|purgeevents
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|type
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|unsigned
name|int
function_decl|(
modifier|*
name|purgerange
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|first
parameter_list|,
name|isc_eventtype_t
name|last
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|beginexclusive
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|endexclusive
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setprivilege
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_boolean_t
name|priv
parameter_list|)
function_decl|;
name|isc_boolean_t
function_decl|(
modifier|*
name|privilege
function_decl|)
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
block|}
name|isc_taskmethods_t
typedef|;
end_typedef

begin_comment
comment|/*%  * This structure is actually just the common prefix of a task manager  * object implementation's version of an isc_taskmgr_t.  * \brief  * Direct use of this structure by clients is forbidden.  task implementations  * may change the structure.  'magic' must be ISCAPI_TASKMGR_MAGIC for any  * of the isc_task_ routines to work.  task implementations must maintain  * all task invariants.  */
end_comment

begin_struct
struct|struct
name|isc_taskmgr
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_taskmgrmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_TASKMGR_MAGIC
value|ISC_MAGIC('A','t','m','g')
end_define

begin_define
define|#
directive|define
name|ISCAPI_TASKMGR_VALID
parameter_list|(
name|m
parameter_list|)
value|((m) != NULL&& \ 				 (m)->magic == ISCAPI_TASKMGR_MAGIC)
end_define

begin_comment
comment|/*%  * This is the common prefix of a task object.  The same note as  * that for the taskmgr structure applies.  */
end_comment

begin_struct
struct|struct
name|isc_task
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_taskmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_TASK_MAGIC
value|ISC_MAGIC('A','t','s','t')
end_define

begin_define
define|#
directive|define
name|ISCAPI_TASK_VALID
parameter_list|(
name|s
parameter_list|)
value|((s) != NULL&& \ 				 (s)->magic == ISCAPI_TASK_MAGIC)
end_define

begin_function_decl
name|isc_result_t
name|isc_task_create
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|,
name|unsigned
name|int
name|quantum
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a task.  *  * Notes:  *  *\li	If 'quantum' is non-zero, then only that many events can be dispatched  *	before the task must yield to other tasks waiting to execute.  If  *	quantum is zero, then the default quantum of the task manager will  *	be used.  *  *\li	The 'quantum' option may be removed from isc_task_create() in the  *	future.  If this happens, isc_task_getquantum() and  *	isc_task_setquantum() will be provided.  *  * Requires:  *  *\li	'manager' is a valid task manager.  *  *\li	taskp != NULL&& *taskp == NULL  *  * Ensures:  *  *\li	On success, '*taskp' is bound to the new task.  *  * Returns:  *  *\li   #ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  *\li	#ISC_R_SHUTTINGDOWN  */
end_comment

begin_function_decl
name|void
name|isc_task_attach
parameter_list|(
name|isc_task_t
modifier|*
name|source
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach *targetp to source.  *  * Requires:  *  *\li	'source' is a valid task.  *  *\li	'targetp' points to a NULL isc_task_t *.  *  * Ensures:  *  *\li	*targetp is attached to source.  */
end_comment

begin_function_decl
name|void
name|isc_task_detach
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Detach *taskp from its task.  *  * Requires:  *  *\li	'*taskp' is a valid task.  *  * Ensures:  *  *\li	*taskp is NULL.  *  *\li	If '*taskp' is the last reference to the task, the task is idle (has  *	an empty event queue), and has not been shutdown, the task will be  *	shutdown.  *  *\li	If '*taskp' is the last reference to the task and  *	the task has been shutdown,  *		all resources used by the task will be freed.  */
end_comment

begin_function_decl
name|void
name|isc_task_send
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send '*event' to 'task'.  *  * Requires:  *  *\li	'task' is a valid task.  *\li	eventp != NULL&& *eventp != NULL.  *  * Ensures:  *  *\li	*eventp == NULL.  */
end_comment

begin_function_decl
name|void
name|isc_task_sendanddetach
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|,
name|isc_event_t
modifier|*
modifier|*
name|eventp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send '*event' to '*taskp' and then detach '*taskp' from its  * task.  *  * Requires:  *  *\li	'*taskp' is a valid task.  *\li	eventp != NULL&& *eventp != NULL.  *  * Ensures:  *  *\li	*eventp == NULL.  *  *\li	*taskp == NULL.  *  *\li	If '*taskp' is the last reference to the task, the task is  *	idle (has an empty event queue), and has not been shutdown,  *	the task will be shutdown.  *  *\li	If '*taskp' is the last reference to the task and  *	the task has been shutdown,  *		all resources used by the task will be freed.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_task_purgerange
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|first
parameter_list|,
name|isc_eventtype_t
name|last
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Purge events from a task's event queue.  *  * Requires:  *  *\li	'task' is a valid task.  *  *\li	last>= first  *  * Ensures:  *  *\li	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is>= first and<= last, and whose tag is 'tag' will be purged,  *	unless they are marked as unpurgable.  *  *\li	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *\li	The number of events purged.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_task_purge
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|type
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Purge events from a task's event queue.  *  * Notes:  *  *\li	This function is equivalent to  *  *\code  *		isc_task_purgerange(task, sender, type, type, tag);  *\endcode  *  * Requires:  *  *\li	'task' is a valid task.  *  * Ensures:  *  *\li	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is 'type', and whose tag is 'tag' will be purged, unless they  *	are marked as unpurgable.  *  *\li	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *\li	The number of events purged.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_task_purgeevent
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_event_t
modifier|*
name|event
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Purge 'event' from a task's event queue.  *  * XXXRTH:  WARNING:  This method may be removed before beta.  *  * Notes:  *  *\li	If 'event' is on the task's event queue, it will be purged,  * 	unless it is marked as unpurgeable.  'event' does not have to be  *	on the task's event queue; in fact, it can even be an invalid  *	pointer.  Purging only occurs if the event is actually on the task's  *	event queue.  *  * \li	Purging never changes the state of the task.  *  * Requires:  *  *\li	'task' is a valid task.  *  * Ensures:  *  *\li	'event' is not in the event queue for 'task'.  *  * Returns:  *  *\li	#ISC_TRUE			The event was purged.  *\li	#ISC_FALSE			The event was not in the event queue,  *					or was marked unpurgeable.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_task_unsendrange
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|first
parameter_list|,
name|isc_eventtype_t
name|last
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|,
name|isc_eventlist_t
modifier|*
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove events from a task's event queue.  *  * Requires:  *  *\li	'task' is a valid task.  *  *\li	last>= first.  *  *\li	*events is a valid list.  *  * Ensures:  *  *\li	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is>= first and<= last, and whose tag is 'tag' will be dequeued  *	and appended to *events.  *  *\li	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *\li	The number of events unsent.  */
end_comment

begin_function_decl
name|unsigned
name|int
name|isc_task_unsend
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|void
modifier|*
name|sender
parameter_list|,
name|isc_eventtype_t
name|type
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|,
name|isc_eventlist_t
modifier|*
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Remove events from a task's event queue.  *  * Notes:  *  *\li	This function is equivalent to  *  *\code  *		isc_task_unsendrange(task, sender, type, type, tag, events);  *\endcode  *  * Requires:  *  *\li	'task' is a valid task.  *  *\li	*events is a valid list.  *  * Ensures:  *  *\li	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is 'type', and whose tag is 'tag' will be dequeued and appended  *	to *events.  *  * Returns:  *  *\li	The number of events unsent.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_task_onshutdown
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_taskaction_t
name|action
parameter_list|,
specifier|const
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Send a shutdown event with action 'action' and argument 'arg' when  * 'task' is shutdown.  *  * Notes:  *  *\li	Shutdown events are posted in LIFO order.  *  * Requires:  *  *\li	'task' is a valid task.  *  *\li	'action' is a valid task action.  *  * Ensures:  *  *\li	When the task is shutdown, shutdown events requested with  *	isc_task_onshutdown() will be appended to the task's event queue.  *   * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_TASKSHUTTINGDOWN			Task is shutting down.  */
end_comment

begin_function_decl
name|void
name|isc_task_shutdown
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Shutdown 'task'.  *  * Notes:  *  *\li	Shutting down a task causes any shutdown events requested with  *	isc_task_onshutdown() to be posted (in LIFO order).  The task  *	moves into a "shutting down" mode which prevents further calls  *	to isc_task_onshutdown().  *  *\li	Trying to shutdown a task that has already been shutdown has no  *	effect.  *  * Requires:  *  *\li	'task' is a valid task.  *  * Ensures:  *  *\li	Any shutdown events requested with isc_task_onshutdown() have been  *	posted (in LIFO order).  */
end_comment

begin_function_decl
name|void
name|isc_task_destroy
parameter_list|(
name|isc_task_t
modifier|*
modifier|*
name|taskp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy '*taskp'.  *  * Notes:  *  *\li	This call is equivalent to:  *  *\code  *		isc_task_shutdown(*taskp);  *		isc_task_detach(taskp);  *\endcode  *  * Requires:  *  *	'*taskp' is a valid task.  *  * Ensures:  *  *\li	Any shutdown events requested with isc_task_onshutdown() have been  *	posted (in LIFO order).  *  *\li	*taskp == NULL  *  *\li	If '*taskp' is the last reference to the task,  *		all resources used by the task will be freed.  */
end_comment

begin_function_decl
name|void
name|isc_task_setname
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|void
modifier|*
name|tag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Name 'task'.  *  * Notes:  *  *\li	Only the first 15 characters of 'name' will be copied.  *  *\li	Naming a task is currently only useful for debugging purposes.  *  * Requires:  *  *\li	'task' is a valid task.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|isc_task_getname
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the name of 'task', as previously set using isc_task_setname().  *  * Notes:  *\li	This function is for debugging purposes only.  *  * Requires:  *\li	'task' is a valid task.  *  * Returns:  *\li	A non-NULL pointer to a null-terminated string.  * 	If the task has not been named, the string is  * 	empty.  *  */
end_comment

begin_function_decl
name|void
modifier|*
name|isc_task_gettag
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Get the tag value for  'task', as previously set using isc_task_settag().  *  * Notes:  *\li	This function is for debugging purposes only.  *  * Requires:  *\li	'task' is a valid task.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_task_beginexclusive
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Request exclusive access for 'task', which must be the calling  * task.  Waits for any other concurrently executing tasks to finish their  * current event, and prevents any new events from executing in any of the  * tasks sharing a task manager with 'task'.  *  * The exclusive access must be relinquished by calling  * isc_task_endexclusive() before returning from the current event handler.  *  * Requires:  *\li	'task' is the calling task.  *  * Returns:  *\li	#ISC_R_SUCCESS		The current task now has exclusive access.  *\li	#ISC_R_LOCKBUSY		Another task has already requested exclusive  *				access.  */
end_comment

begin_function_decl
name|void
name|isc_task_endexclusive
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Relinquish the exclusive access obtained by isc_task_beginexclusive(),  * allowing other tasks to execute.  *  * Requires:  *\li	'task' is the calling task, and has obtained  *		exclusive access by calling isc_task_spl().  */
end_comment

begin_function_decl
name|void
name|isc_task_getcurrenttime
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_stdtime_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Provide the most recent timestamp on the task.  The timestamp is considered  * as the "current time" in the second-order granularity.  *  * Requires:  *\li	'task' is a valid task.  *\li	't' is a valid non NULL pointer.  *  * Ensures:  *\li	'*t' has the "current time".  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_task_exiting
parameter_list|(
name|isc_task_t
modifier|*
name|t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns ISC_TRUE if the task is in the process of shutting down,  * ISC_FALSE otherwise.  *  * Requires:  *\li	'task' is a valid task.  */
end_comment

begin_function_decl
name|void
name|isc_task_setprivilege
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|,
name|isc_boolean_t
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set or unset the task's "privileged" flag depending on the value of  * 'priv'.  *  * Under normal circumstances this flag has no effect on the task behavior,  * but when the task manager has been set to privileged exeuction mode via  * isc_taskmgr_setmode(), only tasks with the flag set will be executed,  * and all other tasks will wait until they're done.  Once all privileged  * tasks have finished executing, the task manager will automatically  * return to normal execution mode and nonprivileged task can resume.  *  * Requires:  *\li	'task' is a valid task.  */
end_comment

begin_function_decl
name|isc_boolean_t
name|isc_task_privilege
parameter_list|(
name|isc_task_t
modifier|*
name|task
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the current value of the task's privilege flag.  *  * Requires:  *\li	'task' is a valid task.  */
end_comment

begin_comment
comment|/*****  ***** Task Manager.  *****/
end_comment

begin_function_decl
name|isc_result_t
name|isc_taskmgr_createinctx
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
name|actx
parameter_list|,
name|unsigned
name|int
name|workers
parameter_list|,
name|unsigned
name|int
name|default_quantum
parameter_list|,
name|isc_taskmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_taskmgr_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|workers
parameter_list|,
name|unsigned
name|int
name|default_quantum
parameter_list|,
name|isc_taskmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a new task manager.  isc_taskmgr_createinctx() also associates  * the new manager with the specified application context.  *  * Notes:  *  *\li	'workers' in the number of worker threads to create.  In general,  *	the value should be close to the number of processors in the system.  *	The 'workers' value is advisory only.  An attempt will be made to  *	create 'workers' threads, but if at least one thread creation  *	succeeds, isc_taskmgr_create() may return ISC_R_SUCCESS.  *  *\li	If 'default_quantum' is non-zero, then it will be used as the default  *	quantum value when tasks are created.  If zero, then an implementation  *	defined default quantum will be used.  *  * Requires:  *  *\li      'mctx' is a valid memory context.  *  *\li	workers> 0  *  *\li	managerp != NULL&& *managerp == NULL  *  *\li	'actx' is a valid application context (for createinctx()).  *  * Ensures:  *  *\li	On success, '*managerp' will be attached to the newly created task  *	manager.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_NOTHREADS		No threads could be created.  *\li	#ISC_R_UNEXPECTED		An unexpected error occurred.  *\li	#ISC_R_SHUTTINGDOWN      	The non-threaded, shared, task  *					manager shutting down.  */
end_comment

begin_function_decl
name|void
name|isc_taskmgr_setmode
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|,
name|isc_taskmgrmode_t
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_taskmgrmode_t
name|isc_taskmgr_mode
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|manager
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set/get the current operating mode of the task manager.  Valid modes are:  *  *\li  isc_taskmgrmode_normal  *\li  isc_taskmgrmode_privileged  *  * In privileged execution mode, only tasks that have had the "privilege"  * flag set via isc_task_setprivilege() can be executed.  When all such  * tasks are complete, the manager automatically returns to normal mode  * and proceeds with running non-privileged ready tasks.  This means it is  * necessary to have at least one privileged task waiting on the ready  * queue *before* setting the manager into privileged execution mode,  * which in turn means the task which calls this function should be in  * task-exclusive mode when it does so.  *  * Requires:  *  *\li      'manager' is a valid task manager.  */
end_comment

begin_function_decl
name|void
name|isc_taskmgr_destroy
parameter_list|(
name|isc_taskmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy '*managerp'.  *  * Notes:  *  *\li	Calling isc_taskmgr_destroy() will shutdown all tasks managed by  *	*managerp that haven't already been shutdown.  The call will block  *	until all tasks have entered the done state.  *  *\li	isc_taskmgr_destroy() must not be called by a task event action,  *	because it would block forever waiting for the event action to  *	complete.  An event action that wants to cause task manager shutdown  *	should request some non-event action thread of execution to do the  *	shutdown, e.g. by signaling a condition variable or using  *	isc_app_shutdown().  *  *\li	Task manager references are not reference counted, so the caller  *	must ensure that no attempt will be made to use the manager after  *	isc_taskmgr_destroy() returns.  *  * Requires:  *  *\li	'*managerp' is a valid task manager.  *  *\li	isc_taskmgr_destroy() has not be called previously on '*managerp'.  *  * Ensures:  *  *\li	All resources used by the task manager, and any tasks it managed,  *	have been freed.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LIBXML2
end_ifdef

begin_function_decl
name|void
name|isc_taskmgr_renderxml
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|mgr
parameter_list|,
name|xmlTextWriterPtr
name|writer
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*%<  * See isc_taskmgr_create() above.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_taskmgrcreatefunc_t
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|workers
parameter_list|,
name|unsigned
name|int
name|default_quantum
parameter_list|,
name|isc_taskmgr_t
modifier|*
modifier|*
name|managerp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_task_register
parameter_list|(
name|isc_taskmgrcreatefunc_t
name|createfunc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a new task management implementation and add it to the list of  * supported implementations.  This function must be called when a different  * event library is used than the one contained in the ISC library.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc__task_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * A short cut function that specifies the task management module in the ISC  * library for isc_task_register().  An application that uses the ISC library  * usually do not have to care about this function: it would call  * isc_lib_register(), which internally calls this function.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TASK_H */
end_comment

end_unit

