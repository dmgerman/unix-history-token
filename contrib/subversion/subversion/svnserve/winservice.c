begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * winservice.c : Implementation of Windows Service support  *  * ====================================================================  *    Licensed to the Apache Software Foundation (ASF) under one  *    or more contributor license agreements.  See the NOTICE file  *    distributed with this work for additional information  *    regarding copyright ownership.  The ASF licenses this file  *    to you under the Apache License, Version 2.0 (the  *    "License"); you may not use this file except in compliance  *    with the License.  You may obtain a copy of the License at  *  *      http://www.apache.org/licenses/LICENSE-2.0  *  *    Unless required by applicable law or agreed to in writing,  *    software distributed under the License is distributed on an  *    "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY  *    KIND, either express or implied.  See the License for the  *    specific language governing permissions and limitations  *    under the License.  * ====================================================================  */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|APR_WANT_STRFUNC
end_define

begin_include
include|#
directive|include
file|<apr_want.h>
end_include

begin_include
include|#
directive|include
file|<apr_errno.h>
end_include

begin_include
include|#
directive|include
file|"svn_error.h"
end_include

begin_include
include|#
directive|include
file|"svn_private_config.h"
end_include

begin_include
include|#
directive|include
file|"winservice.h"
end_include

begin_comment
comment|/* Design Notes ------------  The code in this file allows svnserve to run as a Windows service. Windows Services are only supported on operating systems derived from Windows NT, which is basically all modern versions of Windows (2000, XP, Server, Vista, etc.) and excludes the Windows 9x line.  Windows Services are processes that are started and controlled by the Service Control Manager.  When the SCM wants to start a service, it creates the process, then waits for the process to connect to the SCM, so that the SCM and service process can communicate. This is done using the StartServiceCtrlDispatcher function.  In order to minimize changes to the svnserve startup logic, this implementation differs slightly from most service implementations. In most services, main() immediately calls StartServiceCtrlDispatcher, which does not return control to main() until the SCM sends the "stop" request to the service, and the service stops.   Installing the Service ----------------------  Installation is beyond the scope of source code comments.  There is a separate document that describes how to install and uninstall the service.  Basically, you create a Windows Service, give it a binary path that points to svnserve.exe, and make sure that you specify --service on the command line.   Starting the Service --------------------  First, the SCM decides that it wants to start a service.  It creates the process for the service, passing it the command-line that is stored in the service configuration (stored in the registry).  Next, main() runs.  The command-line should contain the --service argument, which is the hint that svnserve is running under the SCM, not as a standalone process.  main() calls winservice_start().  winservice_start() creates an event object (winservice_start_event), and creates and starts a separate thread, the "dispatcher" thread. winservice_start() then waits for either winservice_start_event to fire (meaning: "the dispatcher thread successfully connected to the SCM, and now the service is starting") or for the dispatcher thread to exit (meaning: "failed to connect to SCM").  If the dispatcher thread quit, then winservice_start returns an error. If the start event fired, then winservice_start returns a success code (SVN_NO_ERROR).  At this point, the service is now in the "starting" state, from the perspective of the SCM.  winservice_start also registers an atexit handler, which handles cleaning up some of the service logic, as explained below in "Stopping the Service".  Next, control returns to main(), which performs the usual startup logic for svnserve.  Mostly, it creates the listener socket.  If main() was able to start the service, then it calls the function winservice_running().  winservice_running() informs the SCM that the service has finished starting, and is now in the "running" state.  main() then does its work, accepting client sockets and processing SVN requests.  Stopping the Service --------------------  At some point, the SCM will decide to stop the service, either because an administrator chose to stop the service, or the system is shutting down.  To do this, the SCM calls winservice_handler() with the SERVICE_CONTROL_STOP control code.  When this happens, winservice_handler() will inform the SCM that the service is now in the "stopping" state, and will call winservice_notify_stop().  winservice_notify_stop() is responsible for cleanly shutting down the svnserve logic (waiting for client requests to finish, stopping database access, etc.).  Right now, all it does is close the listener socket, which causes the apr_socket_accept() call in main() to fail.  main() then calls exit(), which processes all atexit() handlers, which results in winservice_stop() being called.  winservice_stop() notifies the SCM that the service is now stopped, and then waits for the dispatcher thread to exit.  Because all services in the process have now stopped, the call to StartServiceCtrlDispatcher (in the dispatcher thread) finally returns, and winservice_stop() returns, and the process finally exits. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<winsvc.h>
end_include

begin_comment
comment|/* This is just a placeholder, and doesn't actually constrain the   service name.  You have to provide *some* service name to the SCM   API, but for services that are marked SERVICE_WIN32_OWN_PROCESS (as   is the case for svnserve), the service name is ignored.  It *is*   relevant for service binaries that run more than one service in a   single process. */
end_comment

begin_define
define|#
directive|define
name|WINSERVICE_SERVICE_NAME
value|"svnserve"
end_define

begin_comment
comment|/* Win32 handle to the dispatcher thread. */
end_comment

begin_decl_stmt
specifier|static
name|HANDLE
name|winservice_dispatcher_thread
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Win32 event handle, used to notify winservice_start() that we have    successfully connected to the SCM. */
end_comment

begin_decl_stmt
specifier|static
name|HANDLE
name|winservice_start_event
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* RPC handle that allows us to notify the SCM of changes in our    service status. */
end_comment

begin_decl_stmt
specifier|static
name|SERVICE_STATUS_HANDLE
name|winservice_status_handle
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Our current idea of the service status (stopped, running, controls    accepted, exit code, etc.) */
end_comment

begin_decl_stmt
specifier|static
name|SERVICE_STATUS
name|winservice_status
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SVN_DEBUG
end_ifdef

begin_function
specifier|static
name|void
name|dbg_print
parameter_list|(
specifier|const
name|char
modifier|*
name|text
parameter_list|)
block|{
name|OutputDebugStringA
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Make sure dbg_print compiles to nothing in release builds. */
end_comment

begin_define
define|#
directive|define
name|dbg_print
parameter_list|(
name|text
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|winservice_atexit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Notifies the Service Control Manager of the current state of the    service. */
end_comment

begin_function
specifier|static
name|void
name|winservice_update_state
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|winservice_status_handle
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|SetServiceStatus
argument_list|(
name|winservice_status_handle
argument_list|,
operator|&
name|winservice_status
argument_list|)
condition|)
block|{
name|dbg_print
argument_list|(
literal|"SetServiceStatus - FAILED\r\n"
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/* This function cleans up state associated with the service support.    If the dispatcher thread handle is non-NULL, then this function    will wait for the dispatcher thread to exit. */
end_comment

begin_function
specifier|static
name|void
name|winservice_cleanup
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|winservice_start_event
operator|!=
name|NULL
condition|)
block|{
name|CloseHandle
argument_list|(
name|winservice_start_event
argument_list|)
expr_stmt|;
name|winservice_start_event
operator|=
name|NULL
expr_stmt|;
block|}
if|if
condition|(
name|winservice_dispatcher_thread
operator|!=
name|NULL
condition|)
block|{
name|dbg_print
argument_list|(
literal|"winservice_cleanup:"
literal|" waiting for dispatcher thread to exit\r\n"
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|winservice_dispatcher_thread
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|winservice_dispatcher_thread
argument_list|)
expr_stmt|;
name|winservice_dispatcher_thread
operator|=
name|NULL
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/* The SCM invokes this function to cause state changes in the    service. */
end_comment

begin_function
specifier|static
name|void
name|WINAPI
name|winservice_handler
parameter_list|(
name|DWORD
name|control
parameter_list|)
block|{
switch|switch
condition|(
name|control
condition|)
block|{
case|case
name|SERVICE_CONTROL_INTERROGATE
case|:
comment|/* The SCM just wants to check our state.  We are required to          call SetServiceStatus, but we don't need to make any state          changes. */
name|dbg_print
argument_list|(
literal|"SERVICE_CONTROL_INTERROGATE\r\n"
argument_list|)
expr_stmt|;
name|winservice_update_state
argument_list|()
expr_stmt|;
break|break;
case|case
name|SERVICE_CONTROL_STOP
case|:
name|dbg_print
argument_list|(
literal|"SERVICE_CONTROL_STOP\r\n"
argument_list|)
expr_stmt|;
name|winservice_status
operator|.
name|dwCurrentState
operator|=
name|SERVICE_STOP_PENDING
expr_stmt|;
name|winservice_update_state
argument_list|()
expr_stmt|;
name|winservice_notify_stop
argument_list|()
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* This is the "service main" routine (in the Win32 terminology).     Normally, this function (thread) implements the "main" loop of a    service.  However, in order to minimize changes to the svnserve    main() function, this function is running in a different thread,    and main() is blocked in winservice_start(), waiting for    winservice_start_event.  So this function (thread) only needs to    signal that event to "start" the service.     If this function succeeds, it signals winservice_start_event, which    wakes up the winservice_start() frame that is blocked. */
end_comment

begin_function
specifier|static
name|void
name|WINAPI
name|winservice_service_main
parameter_list|(
name|DWORD
name|argc
parameter_list|,
name|LPTSTR
modifier|*
name|argv
parameter_list|)
block|{
name|DWORD
name|error
decl_stmt|;
name|assert
argument_list|(
name|winservice_start_event
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|winservice_status_handle
operator|=
name|RegisterServiceCtrlHandler
argument_list|(
name|WINSERVICE_SERVICE_NAME
argument_list|,
name|winservice_handler
argument_list|)
expr_stmt|;
if|if
condition|(
name|winservice_status_handle
operator|==
name|NULL
condition|)
block|{
comment|/* Ok, that's not fair.  We received a request to start a service,          and now we cannot bind to the SCM in order to update status?          Bring down the app. */
name|error
operator|=
name|GetLastError
argument_list|()
expr_stmt|;
name|dbg_print
argument_list|(
literal|"RegisterServiceCtrlHandler FAILED\r\n"
argument_list|)
expr_stmt|;
comment|/* Put the error code somewhere where winservice_start can find it. */
name|winservice_status
operator|.
name|dwWin32ExitCode
operator|=
name|error
expr_stmt|;
name|SetEvent
argument_list|(
name|winservice_start_event
argument_list|)
expr_stmt|;
return|return;
block|}
name|winservice_status
operator|.
name|dwCurrentState
operator|=
name|SERVICE_START_PENDING
expr_stmt|;
name|winservice_status
operator|.
name|dwWin32ExitCode
operator|=
name|ERROR_SUCCESS
expr_stmt|;
name|winservice_update_state
argument_list|()
expr_stmt|;
name|dbg_print
argument_list|(
literal|"winservice_service_main: service is starting\r\n"
argument_list|)
expr_stmt|;
name|SetEvent
argument_list|(
name|winservice_start_event
argument_list|)
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|static
specifier|const
name|SERVICE_TABLE_ENTRY
name|winservice_service_table
index|[]
init|=
block|{
block|{
name|WINSERVICE_SERVICE_NAME
block|,
name|winservice_service_main
block|}
block|,
block|{
name|NULL
block|,
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is the thread routine for the "dispatcher" thread.  The    purpose of this thread is to connect this process with the Service    Control Manager, which allows this process to receive control    requests from the SCM, and allows this process to update the SCM    with status information.     The StartServiceCtrlDispatcher connects this process to the SCM.    If it succeeds, then it will not return until all of the services    running in this process have stopped.  (In our case, there is only    one service per process.) */
end_comment

begin_function
specifier|static
name|DWORD
name|WINAPI
name|winservice_dispatcher_thread_routine
parameter_list|(
name|PVOID
name|arg
parameter_list|)
block|{
name|dbg_print
argument_list|(
literal|"winservice_dispatcher_thread_routine: starting\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|StartServiceCtrlDispatcher
argument_list|(
name|winservice_service_table
argument_list|)
condition|)
block|{
comment|/* This is a common error.  Usually, it means the user has          invoked the service with the --service flag directly.  This          is incorrect.  The only time the --service flag is passed is          when the process is being started by the SCM. */
name|DWORD
name|error
init|=
name|GetLastError
argument_list|()
decl_stmt|;
name|dbg_print
argument_list|(
literal|"dispatcher: FAILED to connect to SCM\r\n"
argument_list|)
expr_stmt|;
return|return
name|error
return|;
block|}
name|dbg_print
argument_list|(
literal|"dispatcher: SCM is done using this process -- exiting\r\n"
argument_list|)
expr_stmt|;
return|return
name|ERROR_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/* If svnserve needs to run as a Win32 service, then we need to    coordinate with the Service Control Manager (SCM) before    continuing.  This function call registers the svnserve.exe process    with the SCM, waits for the "start" command from the SCM (which    will come very quickly), and confirms that those steps succeeded.     After this call succeeds, the service should perform whatever work    it needs to start the service, and then the service should call    winservice_running() (if no errors occurred) or winservice_stop()    (if something failed during startup). */
end_comment

begin_function
name|svn_error_t
modifier|*
name|winservice_start
parameter_list|(
name|void
parameter_list|)
block|{
name|HANDLE
name|handles
index|[
literal|2
index|]
decl_stmt|;
name|DWORD
name|thread_id
decl_stmt|;
name|DWORD
name|error_code
decl_stmt|;
name|apr_status_t
name|apr_status
decl_stmt|;
name|DWORD
name|wait_status
decl_stmt|;
name|dbg_print
argument_list|(
literal|"winservice_start: starting svnserve as a service...\r\n"
argument_list|)
expr_stmt|;
name|ZeroMemory
argument_list|(
operator|&
name|winservice_status
argument_list|,
sizeof|sizeof
argument_list|(
name|winservice_status
argument_list|)
argument_list|)
expr_stmt|;
name|winservice_status
operator|.
name|dwServiceType
operator|=
name|SERVICE_WIN32_OWN_PROCESS
expr_stmt|;
name|winservice_status
operator|.
name|dwControlsAccepted
operator|=
name|SERVICE_ACCEPT_STOP
expr_stmt|;
name|winservice_status
operator|.
name|dwCurrentState
operator|=
name|SERVICE_STOPPED
expr_stmt|;
comment|/* Create the event that will wake up this thread when the SCM      creates the ServiceMain thread. */
name|winservice_start_event
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|FALSE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|winservice_start_event
operator|==
name|NULL
condition|)
block|{
name|apr_status
operator|=
name|apr_get_os_error
argument_list|()
expr_stmt|;
return|return
name|svn_error_wrap_apr
argument_list|(
name|apr_status
argument_list|,
name|_
argument_list|(
literal|"Failed to create winservice_start_event"
argument_list|)
argument_list|)
return|;
block|}
name|winservice_dispatcher_thread
operator|=
operator|(
name|HANDLE
operator|)
name|CreateThread
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|,
name|winservice_dispatcher_thread_routine
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|thread_id
argument_list|)
expr_stmt|;
if|if
condition|(
name|winservice_dispatcher_thread
operator|==
name|NULL
condition|)
block|{
name|apr_status
operator|=
name|apr_get_os_error
argument_list|()
expr_stmt|;
name|winservice_cleanup
argument_list|()
expr_stmt|;
return|return
name|svn_error_wrap_apr
argument_list|(
name|apr_status
argument_list|,
name|_
argument_list|(
literal|"The service failed to start"
argument_list|)
argument_list|)
return|;
block|}
comment|/* Next, we wait for the "start" event to fire (meaning the service      logic has successfully started), or for the dispatch thread to      exit (meaning the service logic could not start). */
name|handles
index|[
literal|0
index|]
operator|=
name|winservice_start_event
expr_stmt|;
name|handles
index|[
literal|1
index|]
operator|=
name|winservice_dispatcher_thread
expr_stmt|;
name|wait_status
operator|=
name|WaitForMultipleObjects
argument_list|(
literal|2
argument_list|,
name|handles
argument_list|,
name|FALSE
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|wait_status
condition|)
block|{
case|case
name|WAIT_OBJECT_0
case|:
name|dbg_print
argument_list|(
literal|"winservice_start: service is now starting\r\n"
argument_list|)
expr_stmt|;
comment|/* We no longer need the start event. */
name|CloseHandle
argument_list|(
name|winservice_start_event
argument_list|)
expr_stmt|;
name|winservice_start_event
operator|=
name|NULL
expr_stmt|;
comment|/* Register our cleanup logic. */
name|atexit
argument_list|(
name|winservice_atexit
argument_list|)
expr_stmt|;
return|return
name|SVN_NO_ERROR
return|;
case|case
name|WAIT_OBJECT_0
operator|+
literal|1
case|:
comment|/* The dispatcher thread exited without starting the service.          This happens when the dispatcher fails to connect to the SCM. */
name|dbg_print
argument_list|(
literal|"winservice_start: dispatcher thread has failed\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|GetExitCodeThread
argument_list|(
name|winservice_dispatcher_thread
argument_list|,
operator|&
name|error_code
argument_list|)
condition|)
block|{
name|dbg_print
argument_list|(
literal|"winservice_start: dispatcher thread failed\r\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|error_code
operator|==
name|ERROR_SUCCESS
condition|)
name|error_code
operator|=
name|ERROR_INTERNAL_ERROR
expr_stmt|;
block|}
else|else
block|{
name|error_code
operator|=
name|ERROR_INTERNAL_ERROR
expr_stmt|;
block|}
name|CloseHandle
argument_list|(
name|winservice_dispatcher_thread
argument_list|)
expr_stmt|;
name|winservice_dispatcher_thread
operator|=
name|NULL
expr_stmt|;
name|winservice_cleanup
argument_list|()
expr_stmt|;
return|return
name|svn_error_wrap_apr
argument_list|(
name|APR_FROM_OS_ERROR
argument_list|(
name|error_code
argument_list|)
argument_list|,
name|_
argument_list|(
literal|"Failed to connect to Service Control Manager"
argument_list|)
argument_list|)
return|;
default|default:
comment|/* This should never happen! This indicates that our handles are          broken, or some other highly unusual error.  There is nothing          rational that we can do to recover. */
name|apr_status
operator|=
name|apr_get_os_error
argument_list|()
expr_stmt|;
name|dbg_print
argument_list|(
literal|"winservice_start: WaitForMultipleObjects failed!\r\n"
argument_list|)
expr_stmt|;
name|winservice_cleanup
argument_list|()
expr_stmt|;
return|return
name|svn_error_wrap_apr
argument_list|(
name|apr_status
argument_list|,
name|_
argument_list|(
literal|"The service failed to start; an internal error"
literal|" occurred while starting the service"
argument_list|)
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* main() calls this function in order to inform the SCM that the    service has successfully started.  This is required; otherwise, the    SCM will believe that the service is stuck in the "starting" state,    and management tools will also believe that the service is stuck. */
end_comment

begin_function
name|void
name|winservice_running
parameter_list|(
name|void
parameter_list|)
block|{
name|winservice_status
operator|.
name|dwCurrentState
operator|=
name|SERVICE_RUNNING
expr_stmt|;
name|winservice_update_state
argument_list|()
expr_stmt|;
name|dbg_print
argument_list|(
literal|"winservice_notify_running: service is now running\r\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* main() calls this function in order to notify the SCM that the    service has stopped.  This function also handles cleaning up the    dispatcher thread (the one that we created above in    winservice_start. */
end_comment

begin_function
specifier|static
name|void
name|winservice_stop
parameter_list|(
name|DWORD
name|exit_code
parameter_list|)
block|{
name|dbg_print
argument_list|(
literal|"winservice_stop - notifying SCM that service has stopped\r\n"
argument_list|)
expr_stmt|;
name|winservice_status
operator|.
name|dwCurrentState
operator|=
name|SERVICE_STOPPED
expr_stmt|;
name|winservice_status
operator|.
name|dwWin32ExitCode
operator|=
name|exit_code
expr_stmt|;
name|winservice_update_state
argument_list|()
expr_stmt|;
if|if
condition|(
name|winservice_dispatcher_thread
operator|!=
name|NULL
condition|)
block|{
name|dbg_print
argument_list|(
literal|"waiting for dispatcher thread to exit...\r\n"
argument_list|)
expr_stmt|;
name|WaitForSingleObject
argument_list|(
name|winservice_dispatcher_thread
argument_list|,
name|INFINITE
argument_list|)
expr_stmt|;
name|dbg_print
argument_list|(
literal|"dispatcher thread has exited.\r\n"
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|winservice_dispatcher_thread
argument_list|)
expr_stmt|;
name|winservice_dispatcher_thread
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
comment|/* There was no dispatcher thread.  So we never started in          the first place. */
name|exit_code
operator|=
name|winservice_status
operator|.
name|dwWin32ExitCode
expr_stmt|;
name|dbg_print
argument_list|(
literal|"dispatcher thread was not running\r\n"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|winservice_start_event
operator|!=
name|NULL
condition|)
block|{
name|CloseHandle
argument_list|(
name|winservice_start_event
argument_list|)
expr_stmt|;
name|winservice_start_event
operator|=
name|NULL
expr_stmt|;
block|}
name|dbg_print
argument_list|(
literal|"winservice_stop - service has stopped\r\n"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This function is installed as an atexit-handler.  This is done so   that we don't need to alter every exit() call in main(). */
end_comment

begin_function
specifier|static
name|void
name|winservice_atexit
parameter_list|(
name|void
parameter_list|)
block|{
name|dbg_print
argument_list|(
literal|"winservice_atexit - stopping\r\n"
argument_list|)
expr_stmt|;
name|winservice_stop
argument_list|(
name|ERROR_SUCCESS
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|svn_boolean_t
name|winservice_is_stopping
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|winservice_status
operator|.
name|dwCurrentState
operator|==
name|SERVICE_STOP_PENDING
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WIN32 */
end_comment

end_unit

