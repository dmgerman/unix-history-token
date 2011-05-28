begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004-2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1999-2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: app.h,v 1.8 2007-06-19 23:47:18 tbox Exp $ */
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
comment|/*! \file isc/app.h  * \brief ISC Application Support  *  * Dealing with program termination can be difficult, especially in a  * multithreaded program.  The routines in this module help coordinate  * the shutdown process.  They are used as follows by the initial (main)  * thread of the application:  *  *\li		isc_app_start();	Call very early in main(), before  *					any other threads have been created.  *  *\li		isc_app_run();		This will post any on-run events,  *					and then block until application  *					shutdown is requested.  A shutdown  *					request is made by calling  *					isc_app_shutdown(), or by sending  *					SIGINT or SIGTERM to the process.  *					After isc_app_run() returns, the  *					application should shutdown itself.  *  *\li		isc_app_finish();	Call very late in main().  *  * Applications that want to use SIGHUP/isc_app_reload() to trigger reloading  * should check the result of isc_app_run() and call the reload routine if  * the result is ISC_R_RELOAD.  They should then call isc_app_run() again  * to resume waiting for reload or termination.  *  * Use of this module is not required.  In particular, isc_app_start() is  * NOT an ISC library initialization routine.  *  * \li MP:  *	Clients must ensure that isc_app_start(), isc_app_run(), and  *	isc_app_finish() are called at most once.  isc_app_shutdown()  *	is safe to use by any thread (provided isc_app_start() has been  *	called previously).  *  * \li Reliability:  *	No anticipated impact.  *  * \li Resources:  *	None.  *  * \li Security:  *	No anticipated impact.  *  * \li Standards:  *	None.  */
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
file|<isc/result.h>
end_include

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

begin_function_decl
name|ISC_LANG_BEGINDECLS
name|isc_result_t
name|isc_app_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Start an ISC library application.  *  * Notes:  *	This call should be made before any other ISC library call, and as  *	close to the beginning of the application as possible.  */
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
comment|/*!<  * \brief Request delivery of an event when the application is run.  *  * Requires:  *	isc_app_start() has been called.  *  * Returns:  *	ISC_R_SUCCESS  *	ISC_R_NOMEMORY  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_run
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Run an ISC library application.  *  * Notes:  *\li	The caller (typically the initial thread of an application) will  *	block until shutdown is requested.  When the call returns, the  *	caller should start shutting down the application.  *  * Requires:  *\li	isc_app_start() has been called.  *  * Ensures:  *\li	Any events requested via isc_app_onrun() will have been posted (in  *	FIFO order) before isc_app_run() blocks.  *  * Returns:  *\li	ISC_R_SUCCESS			Shutdown has been requested.  *\li	ISC_R_RELOAD			Reload has been requested.  */
end_comment

begin_function_decl
name|isc_result_t
name|isc_app_shutdown
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Request application shutdown.  *  * Notes:  *\li	It is safe to call isc_app_shutdown() multiple times.  Shutdown will  *	only be triggered once.  *  * Requires:  *\li	isc_app_run() has been called.  *  * Returns:  *\li	ISC_R_SUCCESS  *\li	ISC_R_UNEXPECTED  */
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
name|isc_app_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*!<  * \brief Finish an ISC library application.  *  * Notes:  *\li	This call should be made at or near the end of main().  *  * Requires:  *\li	isc_app_start() has been called.  *  * Ensures:  *\li	Any resources allocated by isc_app_start() have been released.  */
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

