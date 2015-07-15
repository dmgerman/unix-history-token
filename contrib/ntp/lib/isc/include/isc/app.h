begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: app.h,v 1.11 2009/09/02 23:48:03 tbox Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_APP_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_APP_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*! \file isc/app.h  * \brief ISC Application Support  *  * Dealing with program termination can be difficult, especially in a  * multithreaded program.  The routines in this module help coordinate  * the shutdown process.  They are used as follows by the initial (main)  * thread of the application:  *  *\li		isc_app_start();	Call very early in main(), before  *					any other threads have been created.  *  *\li		isc_app_run();		This will post any on-run events,  *					and then block until application  *					shutdown is requested.  A shutdown  *					request is made by calling  *					isc_app_shutdown(), or by sending  *					SIGINT or SIGTERM to the process.  *					After isc_app_run() returns, the  *					application should shutdown itself.  *  *\li		isc_app_finish();	Call very late in main().  *  * Applications that want to use SIGHUP/isc_app_reload() to trigger reloading  * should check the result of isc_app_run() and call the reload routine if  * the result is ISC_R_RELOAD.  They should then call isc_app_run() again  * to resume waiting for reload or termination.  *  * Use of this module is not required.  In particular, isc_app_start() is  * NOT an ISC library initialization routine.  *  * This module also supports per-thread 'application contexts'.  With this  * mode, a thread-based application will have a separate context, in which  * it uses other ISC library services such as tasks or timers.  Signals are  * not caught in this mode, so that the application can handle the signals  * in its preferred way.  *  * \li MP:  *	Clients must ensure that isc_app_start(), isc_app_run(), and  *	isc_app_finish() are called at most once.  isc_app_shutdown()  *	is safe to use by any thread (provided isc_app_start() has been  *	called previously).  *  *	The same note applies to isc_app_ctxXXX() functions, but in this case  *	it's a per-thread restriction.  For example, a thread with an  *	application context must ensure that isc_app_ctxstart() with the  *	context is called at most once.  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	None.  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  *	None.  */
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
file|<isc/magic.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_comment
comment|/***  *** Types  ***/
end_comment

begin_typedef
typedef|typedef
name|isc_event_t
name|isc_appevent_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ISC_APPEVENT_FIRSTEVENT
value|(ISC_EVENTCLASS_APP + 0)
end_define

begin_define
define|#
directive|define
name|ISC_APPEVENT_SHUTDOWN
value|(ISC_EVENTCLASS_APP + 1)
end_define

begin_define
define|#
directive|define
name|ISC_APPEVENT_LASTEVENT
value|(ISC_EVENTCLASS_APP + 65535)
end_define

begin_comment
comment|/*%  * app module methods.  Only app driver implementations use this structure.  * Other clients should use the top-level interfaces (i.e., isc_app_xxx  * functions).  magic must be ISCAPI_APPMETHODS_MAGIC.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|isc_appmethods
block|{
name|void
function_decl|(
modifier|*
name|ctxdestroy
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|ctxstart
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|ctxrun
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|ctxsuspend
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|isc_result_t
function_decl|(
modifier|*
name|ctxshutdown
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ctxfinish
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|settaskmgr
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|timermgr
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setsocketmgr
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|timermgr
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|settimermgr
function_decl|)
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|)
function_decl|;
block|}
name|isc_appmethods_t
typedef|;
end_typedef

begin_comment
comment|/*%  * This structure is actually just the common prefix of an application context  * implementation's version of an isc_appctx_t.  * \brief  * Direct use of this structure by clients is forbidden.  app implementations  * may change the structure.  'magic' must be ISCAPI_APPCTX_MAGIC for any  * of the isc_app_ routines to work.  app implementations must maintain  * all app context invariants.  */
end_comment

begin_struct
struct|struct
name|isc_appctx
block|{
name|unsigned
name|int
name|impmagic
decl_stmt|;
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_appmethods_t
modifier|*
name|methods
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ISCAPI_APPCTX_MAGIC
value|ISC_MAGIC('A','a','p','c')
end_define

begin_define
define|#
directive|define
name|ISCAPI_APPCTX_VALID
parameter_list|(
name|c
parameter_list|)
value|((c) != NULL&& \ 					 (c)->magic == ISCAPI_APPCTX_MAGIC)
end_define

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_app_ctxstart
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_app_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Start an ISC library application.  *  * Notes:  *	This call should be made before any other ISC library call, and as  *	close to the beginning of the application as possible.  *  * Requires:  *	'ctx' is a valid application context (for app_ctxstart()).  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_onrun
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
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
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Request delivery of an event when the application is run.  *  * Requires:  *\li	isc_app_start() has been called.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_ctxrun
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_app_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Run an ISC library application.  *  * Notes:  *\li	The caller (typically the initial thread of an application) will  *	block until shutdown is requested.  When the call returns, the  *	caller should start shutting down the application.  *  * Requires:  *\li	isc_app_[ctx]start() has been called.  *  * Ensures:  *\li	Any events requested via isc_app_onrun() will have been posted (in  *	FIFO order) before isc_app_run() blocks.  *\li	'ctx' is a valid application context (for app_ctxrun()).  *  * Returns:  *\li	ISC_R_SUCCESS			Shutdown has been requested.  *\li	ISC_R_RELOAD			Reload has been requested.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_ctxshutdown
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_app_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Request application shutdown.  *  * Notes:  *\li	It is safe to call isc_app_shutdown() multiple times.  Shutdown will  *	only be triggered once.  *  * Requires:  *\li	isc_app_[ctx]run() has been called.  *\li	'ctx' is a valid application context (for app_ctxshutdown()).  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_ctxsuspend
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief This has the same behavior as isc_app_ctxsuspend().  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_reload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Request application reload.  *  * Requires:  *\li	isc_app_run() has been called.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_UNEXPECTED  */
end_comment

begin_function_decl
name|void
name|isc_app_ctxfinish
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_app_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Finish an ISC library application.  *  * Notes:  *\li	This call should be made at or near the end of main().  *  * Requires:  *\li	isc_app_start() has been called.  *\li	'ctx' is a valid application context (for app_ctxfinish()).  *  * Ensures:  *\li	Any resources allocated by isc_app_start() have been released.  */
end_comment

begin_function_decl
name|void
name|isc_app_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Indicate that a blocking operation will be performed.  *  * Notes:  *\li	If a blocking operation is in process, a call to isc_app_shutdown()  *	or an external signal will abort the program, rather than allowing  *	clean shutdown.  This is primarily useful for reading user input.  *  * Requires:  * \li	isc_app_start() has been called.  * \li	No other blocking operations are in progress.  */
end_comment

begin_function_decl
name|void
name|isc_app_unblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Indicate that a blocking operation is complete.  *  * Notes:  * \li	When a blocking operation has completed, return the program to a  * 	state where a call to isc_app_shutdown() or an external signal will  * 	shutdown normally.  *  * Requires:  * \li	isc_app_start() has been called.  * \li	isc_app_block() has been called by the same thread.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_appctx_create
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Create an application context.  *  * Requires:  *\li	'mctx' is a valid memory context.  *\li	'ctxp' != NULL&& *ctxp == NULL.  */
end_comment

begin_function_decl
name|void
name|isc_appctx_destroy
parameter_list|(
name|isc_appctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Destroy an application context.  *  * Requires:  *\li	'*ctxp' is a valid application context.  *  * Ensures:  *\li	*ctxp == NULL.  */
end_comment

begin_function_decl
name|void
name|isc_appctx_settaskmgr
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_taskmgr_t
modifier|*
name|taskmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Associate a task manager with an application context.  *  * This must be done before running tasks within the application context.  *  * Requires:  *\li	'ctx' is a valid application context.  *\li	'taskmgr' is a valid task manager.  */
end_comment

begin_function_decl
name|void
name|isc_appctx_setsocketmgr
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_socketmgr_t
modifier|*
name|socketmgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Associate a socket manager with an application context.  *  * This must be done before handling socket events within the application  * context.  *  * Requires:  *\li	'ctx' is a valid application context.  *\li	'socketmgr' is a valid socket manager.  */
end_comment

begin_function_decl
name|void
name|isc_appctx_settimermgr
parameter_list|(
name|isc_appctx_t
modifier|*
name|ctx
parameter_list|,
name|isc_timermgr_t
modifier|*
name|timermgr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Associate a socket timer with an application context.  *  * This must be done before handling timer events within the application  * context.  *  * Requires:  *\li	'ctx' is a valid application context.  *\li	'timermgr' is a valid timer manager.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_APPIMPREGISTER
end_ifdef

begin_comment
comment|/*%<  * See isc_appctx_create() above.  */
end_comment

begin_typedef
typedef|typedef
name|isc_result_t
function_decl|(
modifier|*
name|isc_appctxcreatefunc_t
function_decl|)
parameter_list|(
name|isc_mem_t
modifier|*
name|mctx
parameter_list|,
name|isc_appctx_t
modifier|*
modifier|*
name|ctxp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|isc_result_t
name|isc_app_register
parameter_list|(
name|isc_appctxcreatefunc_t
name|createfunc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * Register a new application implementation and add it to the list of  * supported implementations.  This function must be called when a different  * event library is used than the one contained in the ISC library.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc__app_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*%<  * A short cut function that specifies the application module in the ISC  * library for isc_app_register().  An application that uses the ISC library  * usually do not have to care about this function: it would call  * isc_lib_register(), which internally calls this function.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USE_APPIMPREGISTER */
end_comment

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_APP_H */
end_comment

end_unit

