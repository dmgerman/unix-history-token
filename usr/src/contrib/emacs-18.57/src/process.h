begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for asynchronous process control in GNU Emacs.    Copyright (C) 1985, 1990 Free Software Foundation, Inc.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Structure records pertinent information about open channels.  * There is one channel associated with each process.  */
end_comment

begin_struct
struct|struct
name|Lisp_Process
block|{
name|int
name|size
decl_stmt|;
name|struct
name|Lisp_Vector
modifier|*
name|v_next
decl_stmt|;
comment|/* Descriptor by which we read from this process */
name|Lisp_Object
name|infd
decl_stmt|;
comment|/* Descriptor by which we write to this process */
name|Lisp_Object
name|outfd
decl_stmt|;
comment|/* Name of this process */
name|Lisp_Object
name|name
decl_stmt|;
comment|/* List of command arguments that this process was run with */
name|Lisp_Object
name|command
decl_stmt|;
comment|/* (funcall FILTER PROC STRING)  (if FILTER is non-nil)        to dispose of a bunch of chars from the process all at once */
name|Lisp_Object
name|filter
decl_stmt|;
comment|/* (funcall SENTINEL PROCESS) when process state changes */
name|Lisp_Object
name|sentinel
decl_stmt|;
comment|/* Buffer that output is going to */
name|Lisp_Object
name|buffer
decl_stmt|;
comment|/* Number of this process */
name|Lisp_Object
name|pid
decl_stmt|;
comment|/* Non-nil if this is really a command channel */
name|Lisp_Object
name|command_channel_p
decl_stmt|;
comment|/* Non-nil if this is really a child process */
name|Lisp_Object
name|childp
decl_stmt|;
comment|/* Marker set to end of last buffer-inserted output from this process */
name|Lisp_Object
name|mark
decl_stmt|;
comment|/* Non-nil means kill silently if Emacs is exited.  */
name|Lisp_Object
name|kill_without_query
decl_stmt|;
comment|/* Record the process status in the raw form in which it comes from `wait'.        This is to avoid consing in a signal handler.  */
name|Lisp_Object
name|raw_status_low
decl_stmt|;
name|Lisp_Object
name|raw_status_high
decl_stmt|;
comment|/* Symbol indicating status of process.        This may be a symbol: run, open, or closed.        Or it may be a list, whose car is stop, exit or signal        and whose cdr is a pair (EXIT_CODE . COREDUMP_FLAG)        or (SIGNAL_NUMBER . COREDUMP_FLAG).  */
name|Lisp_Object
name|status
decl_stmt|;
comment|/* Non-nil if communicating through a pty.  */
name|Lisp_Object
name|pty_flag
decl_stmt|;
comment|/* Event-count of last event in which this process changed status.  */
name|Lisp_Object
name|tick
decl_stmt|;
comment|/* Event-count of last such event reported.  */
name|Lisp_Object
name|update_tick
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ChannelMask
parameter_list|(
name|n
parameter_list|)
value|(1<<(n))
end_define

end_unit

