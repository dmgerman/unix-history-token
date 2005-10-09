begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Handling of inferior events for the event loop for GDB, the GNU debugger.    Copyright 1999 Free Software Foundation, Inc.    Written by Elena Zannoni<ezannoni@cygnus.com> of Cygnus Solutions.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"inferior.h"
end_include

begin_comment
comment|/* For fetch_inferior_event. */
end_comment

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_comment
comment|/* For enum inferior_event_type. */
end_comment

begin_include
include|#
directive|include
file|"event-loop.h"
end_include

begin_include
include|#
directive|include
file|"event-top.h"
end_include

begin_include
include|#
directive|include
file|"inf-loop.h"
end_include

begin_include
include|#
directive|include
file|"remote.h"
end_include

begin_function_decl
specifier|static
name|int
name|fetch_inferior_event_wrapper
parameter_list|(
name|gdb_client_data
name|client_data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|complete_execution
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|inferior_event_handler_wrapper
parameter_list|(
name|gdb_client_data
name|client_data
parameter_list|)
block|{
name|inferior_event_handler
argument_list|(
name|INF_QUIT_REQ
argument_list|,
name|client_data
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* General function to handle events in the inferior. So far it just    takes care of detecting errors reported by select() or poll(),    otherwise it assumes that all is OK, and goes on reading data from    the fd. This however may not always be what we want to do. */
end_comment

begin_function
name|void
name|inferior_event_handler
parameter_list|(
name|enum
name|inferior_event_type
name|event_type
parameter_list|,
name|gdb_client_data
name|client_data
parameter_list|)
block|{
switch|switch
condition|(
name|event_type
condition|)
block|{
case|case
name|INF_ERROR
case|:
name|printf_unfiltered
argument_list|(
literal|"error detected from target.\n"
argument_list|)
expr_stmt|;
name|target_async
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pop_target
argument_list|()
expr_stmt|;
name|discard_all_continuations
argument_list|()
expr_stmt|;
name|do_exec_error_cleanups
argument_list|(
name|ALL_CLEANUPS
argument_list|)
expr_stmt|;
break|break;
case|case
name|INF_REG_EVENT
case|:
comment|/* Use catch errors for now, until the inner layers of 	 fetch_inferior_event (i.e. readchar) can return meaningful 	 error status.  If an error occurs while getting an event from 	 the target, just get rid of the target. */
if|if
condition|(
operator|!
name|catch_errors
argument_list|(
name|fetch_inferior_event_wrapper
argument_list|,
name|client_data
argument_list|,
literal|""
argument_list|,
name|RETURN_MASK_ALL
argument_list|)
condition|)
block|{
name|target_async
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|pop_target
argument_list|()
expr_stmt|;
name|discard_all_continuations
argument_list|()
expr_stmt|;
name|do_exec_error_cleanups
argument_list|(
name|ALL_CLEANUPS
argument_list|)
expr_stmt|;
name|display_gdb_prompt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|INF_EXEC_COMPLETE
case|:
comment|/* Is there anything left to do for the command issued to          complete? */
name|do_all_continuations
argument_list|()
expr_stmt|;
comment|/* Reset things after target has stopped for the async commands. */
name|complete_execution
argument_list|()
expr_stmt|;
break|break;
case|case
name|INF_EXEC_CONTINUE
case|:
comment|/* Is there anything left to do for the command issued to          complete? */
name|do_all_intermediate_continuations
argument_list|()
expr_stmt|;
break|break;
case|case
name|INF_QUIT_REQ
case|:
comment|/* FIXME: ezannoni 1999-10-04. This call should really be a 	 target vector entry, so that it can be used for any kind of 	 targets. */
name|async_remote_interrupt_twice
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
break|break;
case|case
name|INF_TIMER
case|:
default|default:
name|printf_unfiltered
argument_list|(
literal|"Event type not recognized.\n"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|fetch_inferior_event_wrapper
parameter_list|(
name|gdb_client_data
name|client_data
parameter_list|)
block|{
name|fetch_inferior_event
argument_list|(
name|client_data
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Reset proper settings after an asynchronous command has finished.    If the execution command was in synchronous mode, register stdin    with the event loop, and reset the prompt. */
end_comment

begin_function
specifier|static
name|void
name|complete_execution
parameter_list|(
name|void
parameter_list|)
block|{
name|target_executing
operator|=
literal|0
expr_stmt|;
comment|/* Unregister the inferior from the event loop. This is done so that      when the inferior is not running we don't get distracted by      spurious inferior output. */
name|target_async
argument_list|(
name|NULL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sync_execution
condition|)
block|{
name|do_exec_error_cleanups
argument_list|(
name|ALL_CLEANUPS
argument_list|)
expr_stmt|;
name|display_gdb_prompt
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|exec_done_display_p
condition|)
name|printf_unfiltered
argument_list|(
literal|"completed.\n"
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

