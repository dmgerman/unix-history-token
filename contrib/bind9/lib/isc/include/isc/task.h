begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: task.h,v 1.49.206.3 2004/03/09 05:21:09 marka Exp $ */
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
comment|/*  * Task System  *  * The task system provides a lightweight execution context, which is  * basically an event queue.  When a task's event queue is non-empty, the  * task is runnable.  A small work crew of threads, typically one per CPU,  * execute runnable tasks by dispatching the events on the tasks' event  * queues.  Context switching between tasks is fast.  *  * MP:  *	The module ensures appropriate synchronization of data structures it  *	creates and manipulates.  *  *	The caller must ensure that isc_taskmgr_destroy() is called only  *	once for a given manager.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *<TBS>  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
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
name|ISC_TASKEVENT_LASTEVENT
value|(ISC_EVENTCLASS_TASK + 65535)
end_define

begin_comment
comment|/*****  ***** Tasks.  *****/
end_comment

begin_function_decl
name|ISC_LANG_BEGINDECLS
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
comment|/*  * Create a task.  *  * Notes:  *  *	If 'quantum' is non-zero, then only that many events can be dispatched  *	before the task must yield to other tasks waiting to execute.  If  *	quantum is zero, then the default quantum of the task manager will  *	be used.  *  *	The 'quantum' option may be removed from isc_task_create() in the  *	future.  If this happens, isc_task_getquantum() and  *	isc_task_setquantum() will be provided.  *  * Requires:  *  *	'manager' is a valid task manager.  *  *	taskp != NULL&& *taskp == NULL  *  * Ensures:  *  *	On success, '*taskp' is bound to the new task.  *  * Returns:  *  *     	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_UNEXPECTED  *	ISC_R_SHUTTINGDOWN  */
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
comment|/*  * Attach *targetp to source.  *  * Requires:  *  *	'source' is a valid task.  *  *	'targetp' points to a NULL isc_task_t *.  *  * Ensures:  *  *	*targetp is attached to source.  */
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
comment|/*  * Detach *taskp from its task.  *  * Requires:  *  *	'*taskp' is a valid task.  *  * Ensures:  *  *	*taskp is NULL.  *  *	If '*taskp' is the last reference to the task, the task is idle (has  *	an empty event queue), and has not been shutdown, the task will be  *	shutdown.  *  *	If '*taskp' is the last reference to the task and  *	the task has been shutdown,  *  *		All resources used by the task will be freed.  */
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
comment|/*  * Send '*event' to 'task'.  *  * Requires:  *  *	'task' is a valid task.  *	eventp != NULL&& *eventp != NULL.  *  * Ensures:  *  *	*eventp == NULL.  */
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
comment|/*  * Send '*event' to '*taskp' and then detach '*taskp' from its  * task.  *  * Requires:  *  *	'*taskp' is a valid task.  *	eventp != NULL&& *eventp != NULL.  *  * Ensures:  *  *	*eventp == NULL.  *  *	*taskp == NULL.  *  *	If '*taskp' is the last reference to the task, the task is  *	idle (has an empty event queue), and has not been shutdown,  *	the task will be shutdown.  *  *	If '*taskp' is the last reference to the task and  *	the task has been shutdown,  *  *		All resources used by the task will be freed.  */
end_comment

begin_comment
comment|/*  * Purging and Unsending  *  * Events which have been queued for a task but not delivered may be removed  * from the task's event queue by purging or unsending.  *  * With both types, the caller specifies a matching pattern that selects  * events based upon their sender, type, and tag.  *  * Purging calls isc_event_free() on the matching events.  *  * Unsending returns a list of events that matched the pattern.  * The caller is then responsible for them.  *  * Consumers of events should purge, not unsend.  *  * Producers of events often want to remove events when the caller indicates  * it is no longer interested in the object, e.g. by cancelling a timer.  * Sometimes this can be done by purging, but for some event types, the  * calls to isc_event_free() cause deadlock because the event free routine  * wants to acquire a lock the caller is already holding.  Unsending instead  * of purging solves this problem.  As a general rule, producers should only  * unsend events which they have sent.  */
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
comment|/*  * Purge events from a task's event queue.  *  * Requires:  *  *	'task' is a valid task.  *  *	last>= first  *  * Ensures:  *  *	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is>= first and<= last, and whose tag is 'tag' will be purged,  *	unless they are marked as unpurgable.  *  *	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *	The number of events purged.  */
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
comment|/*  * Purge events from a task's event queue.  *  * Notes:  *  *	This function is equivalent to  *  *		isc_task_purgerange(task, sender, type, type, tag);  *  * Requires:  *  *	'task' is a valid task.  *  * Ensures:  *  *	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is 'type', and whose tag is 'tag' will be purged, unless they  *	are marked as unpurgable.  *  *	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *	The number of events purged.  */
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
comment|/*  * Purge 'event' from a task's event queue.  *  * XXXRTH:  WARNING:  This method may be removed before beta.  *  * Notes:  *  *	If 'event' is on the task's event queue, it will be purged,  * 	unless it is marked as unpurgeable.  'event' does not have to be  *	on the task's event queue; in fact, it can even be an invalid  *	pointer.  Purging only occurs if the event is actually on the task's  *	event queue.  *  * 	Purging never changes the state of the task.  *  * Requires:  *  *	'task' is a valid task.  *  * Ensures:  *  *	'event' is not in the event queue for 'task'.  *  * Returns:  *  *	ISC_TRUE			The event was purged.  *	ISC_FALSE			The event was not in the event queue,  *					or was marked unpurgeable.  */
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
comment|/*  * Remove events from a task's event queue.  *  * Requires:  *  *	'task' is a valid task.  *  *	last>= first.  *  *	*events is a valid list.  *  * Ensures:  *  *	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is>= first and<= last, and whose tag is 'tag' will be dequeued  *	and appended to *events.  *  *	A sender of NULL will match any sender.  A NULL tag matches any  *	tag.  *  * Returns:  *  *	The number of events unsent.  */
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
comment|/*  * Remove events from a task's event queue.  *  * Notes:  *  *	This function is equivalent to  *  *		isc_task_unsendrange(task, sender, type, type, tag, events);  *  * Requires:  *  *	'task' is a valid task.  *  *	*events is a valid list.  *  * Ensures:  *  *	Events in the event queue of 'task' whose sender is 'sender', whose  *	type is 'type', and whose tag is 'tag' will be dequeued and appended  *	to *events.  *  * Returns:  *  *	The number of events unsent.  */
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
comment|/*  * Send a shutdown event with action 'action' and argument 'arg' when  * 'task' is shutdown.  *  * Notes:  *  *	Shutdown events are posted in LIFO order.  *  * Requires:  *  *	'task' is a valid task.  *  *	'action' is a valid task action.  *  * Ensures:  *  *	When the task is shutdown, shutdown events requested with  *	isc_task_onshutdown() will be appended to the task's event queue.  *   * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_TASKSHUTTINGDOWN			Task is shutting down.  */
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
comment|/*  * Shutdown 'task'.  *  * Notes:  *  *	Shutting down a task causes any shutdown events requested with  *	isc_task_onshutdown() to be posted (in LIFO order).  The task  *	moves into a "shutting down" mode which prevents further calls  *	to isc_task_onshutdown().  *  *	Trying to shutdown a task that has already been shutdown has no  *	effect.  *  * Requires:  *  *	'task' is a valid task.  *  * Ensures:  *  *	Any shutdown events requested with isc_task_onshutdown() have been  *	posted (in LIFO order).  */
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
comment|/*  * Destroy '*taskp'.  *  * Notes:  *  *	This call is equivalent to:  *  *		isc_task_shutdown(*taskp);  *		isc_task_detach(taskp);  *  * Requires:  *  *	'*taskp' is a valid task.  *  * Ensures:  *  *	Any shutdown events requested with isc_task_onshutdown() have been  *	posted (in LIFO order).  *  *	*taskp == NULL  *  *	If '*taskp' is the last reference to the task,  *  *		All resources used by the task will be freed.  */
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
comment|/*  * Name 'task'.  *  * Notes:  *  *	Only the first 15 characters of 'name' will be copied.  *  *	Naming a task is currently only useful for debugging purposes.  *  * Requires:  *  *	'task' is a valid task.  */
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
comment|/*  * Get the name of 'task', as previously set using isc_task_setname().  *  * Notes:  *	This function is for debugging purposes only.  *  * Requires:  *	'task' is a valid task.  *  * Returns:  *	A non-NULL pointer to a null-terminated string.  * 	If the task has not been named, the string is  * 	empty.  *  */
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
comment|/*  * Get the tag value for  'task', as previously set using isc_task_settag().  *  * Notes:  *	This function is for debugging purposes only.  *  * Requires:  *	'task' is a valid task.  */
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
comment|/*  * Request exclusive access for 'task', which must be the calling  * task.  Waits for any other concurrently executing tasks to finish their  * current event, and prevents any new events from executing in any of the  * tasks sharing a task manager with 'task'.  *  * The exclusive access must be relinquished by calling   * isc_task_endexclusive() before returning from the current event handler.  *  * Requires:  *	'task' is the calling task.  *  * Returns:  *	ISC_R_SUCCESS		The current task now has exclusive access.  *	ISC_R_LOCKBUSY		Another task has already requested exclusive  *				access.  */
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
comment|/*  * Relinquish the exclusive access obtained by isc_task_beginexclusive(),   * allowing other tasks to execute.  *  * Requires:  *	'task' is the calling task, and has obtained  *		exclusive access by calling isc_task_spl().  */
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
comment|/*  * Provide the most recent timestamp on the task.  The timestamp is considered  * as the "current time" in the second-order granularity.  *  * Requires:  *	'task' is a valid task.  *	't' is a valid non NULL pointer.  *  * Ensures:  *	'*t' has the "current time".  */
end_comment

begin_comment
comment|/*****  ***** Task Manager.  *****/
end_comment

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
comment|/*  * Create a new task manager.  *  * Notes:  *  *	'workers' in the number of worker threads to create.  In general,  *	the value should be close to the number of processors in the system.  *	The 'workers' value is advisory only.  An attempt will be made to  *	create 'workers' threads, but if at least one thread creation  *	succeeds, isc_taskmgr_create() may return ISC_R_SUCCESS.  *  *	If 'default_quantum' is non-zero, then it will be used as the default  *	quantum value when tasks are created.  If zero, then an implementation  *	defined default quantum will be used.  *  * Requires:  *  *      'mctx' is a valid memory context.  *  *	workers> 0  *  *	managerp != NULL&& *managerp == NULL  *  * Ensures:  *  *	On success, '*managerp' will be attached to the newly created task  *	manager.  *  * Returns:  *  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  *	ISC_R_NOTHREADS			No threads could be created.  *	ISC_R_UNEXPECTED		An unexpected error occurred.  */
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
comment|/*  * Destroy '*managerp'.  *  * Notes:  *  *	Calling isc_taskmgr_destroy() will shutdown all tasks managed by  *	*managerp that haven't already been shutdown.  The call will block  *	until all tasks have entered the done state.  *  *	isc_taskmgr_destroy() must not be called by a task event action,  *	because it would block forever waiting for the event action to  *	complete.  An event action that wants to cause task manager shutdown  *	should request some non-event action thread of execution to do the  *	shutdown, e.g. by signalling a condition variable or using  *	isc_app_shutdown().  *  *	Task manager references are not reference counted, so the caller  *	must ensure that no attempt will be made to use the manager after  *	isc_taskmgr_destroy() returns.  *  * Requires:  *  *	'*managerp' is a valid task manager.  *  *	isc_taskmgr_destroy() has not be called previously on '*managerp'.  *  * Ensures:  *  *	All resources used by the task manager, and any tasks it managed,  *	have been freed.  */
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

