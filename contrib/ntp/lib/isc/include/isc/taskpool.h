begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2011, 2012  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_TASKPOOL_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_TASKPOOL_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/taskpool.h  * \brief A task pool is a mechanism for sharing a small number of tasks  * among a large number of objects such that each object is  * assigned a unique task, but each task may be shared by several  * objects.  *  * Task pools are used to let objects that can exist in large  * numbers (e.g., zones) use tasks for synchronization without  * the memory overhead and unfair scheduling competition that  * could result from creating a separate task for each object.  */
end_comment

begin_comment
comment|/***  *** Imports.  ***/
end_comment

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/task.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_comment
comment|/*****  ***** Types.  *****/
end_comment

begin_typedef
typedef|typedef
name|struct
name|isc_taskpool
name|isc_taskpool_t
typedef|;
end_typedef

begin_comment
comment|/*****  ***** Functions.  *****/
end_comment

begin_function_decl
name|isc_result_t
name|isc_taskpool_create
parameter_list|(
name|isc_taskmgr_t
modifier|*
name|tmgr
parameter_list|,
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|unsigned
name|int
name|ntasks
parameter_list|,
name|unsigned
name|int
name|quantum
parameter_list|,
name|isc_taskpool_t
modifier|*
modifier|*
name|poolp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Create a task pool of "ntasks" tasks, each with quantum  * "quantum".  *  * Requires:  *  *\li	'tmgr' is a valid task manager.  *  *\li	'mctx' is a valid memory context.  *  *\li	poolp != NULL&& *poolp == NULL  *  * Ensures:  *  *\li	On success, '*taskp' points to the new task pool.  *  * Returns:  *  *\li	#ISC_R_SUCCESS  *\li	#ISC_R_NOMEMORY  *\li	#ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|isc_taskpool_gettask
parameter_list|(
name|isc_taskpool_t
modifier|*
name|pool
parameter_list|,
name|isc_task_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Attach to a task from the pool.  Currently the next task is chosen  * from the pool at random.  (This may be changed in the future to  * something that guaratees balance.)  */
end_comment

begin_function_decl
name|int
name|isc_taskpool_size
parameter_list|(
name|isc_taskpool_t
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Returns the number of tasks in the task pool 'pool'.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_taskpool_expand
parameter_list|(
name|isc_taskpool_t
modifier|*
modifier|*
name|sourcep
parameter_list|,
name|unsigned
name|int
name|size
parameter_list|,
name|isc_taskpool_t
modifier|*
modifier|*
name|targetp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * If 'size' is larger than the number of tasks in the pool pointed to by  * 'sourcep', then a new taskpool of size 'size' is allocated, the existing  * tasks from are moved into it, additional tasks are created to bring the  * total number up to 'size', and the resulting pool is attached to  * 'targetp'.  *  * If 'size' is less than or equal to the tasks in pool 'source', then  * 'sourcep' is attached to 'targetp' without any other action being taken.  *  * In either case, 'sourcep' is detached.  *  * Requires:  *  * \li	'sourcep' is not NULL and '*source' is not NULL  * \li	'targetp' is not NULL and '*source' is NULL  *  * Ensures:  *  * \li	On success, '*targetp' points to a valid task pool.  * \li	On success, '*sourcep' points to NULL.  *  * Returns:  *  * \li	#ISC_R_SUCCESS  * \li	#ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|void
name|isc_taskpool_destroy
parameter_list|(
name|isc_taskpool_t
modifier|*
modifier|*
name|poolp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Destroy a task pool.  The tasks in the pool are detached but not  * shut down.  *  * Requires:  * \li	'*poolp' is a valid task pool.  */
end_comment

begin_function_decl
name|void
name|isc_taskpool_setprivilege
parameter_list|(
name|isc_taskpool_t
modifier|*
name|pool
parameter_list|,
name|isc_boolean_t
name|priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Set the privilege flag on all tasks in 'pool' to 'priv'.  If 'priv' is  * true, then when the task manager is set into privileged mode, only  * tasks wihin this pool will be able to execute.  (Note:  It is important  * to turn the pool tasks' privilege back off before the last task finishes  * executing.)  *  * Requires:  * \li	'pool' is a valid task pool.  */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_TASKPOOL_H */
end_comment

end_unit

