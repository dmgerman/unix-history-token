begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for asynchronous process control in GNU Emacs.    Copyright (C) 1985 Richard M. Stallman.  This file is part of GNU Emacs.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Emacs General Public License for full details.  Everyone is granted permission to copy, modify and redistribute GNU Emacs, but only under the conditions described in the GNU Emacs General Public License.   A copy of this license is supposed to have been given to you along with GNU Emacs so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
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
comment|/* The state of the process, expressed by flags 	(RUNNING, STOPPED, etc.)  */
name|Lisp_Object
name|flags
decl_stmt|;
comment|/* # of signal that the process got, that stopped it,        or code it exited with.  */
name|Lisp_Object
name|reason
decl_stmt|;
comment|/* Marker set to end of last buffer-inserted output from this process */
name|Lisp_Object
name|mark
decl_stmt|;
comment|/* Non-nil means kill silently if Emacs is exited.  */
name|Lisp_Object
name|kill_without_query
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Process status, found in the flags component */
end_comment

begin_define
define|#
directive|define
name|PROC_STATUS
value|3
end_define

begin_comment
comment|/* Values of process status */
end_comment

begin_define
define|#
directive|define
name|RUNNING
value|0
end_define

begin_comment
comment|/* process is running */
end_comment

begin_define
define|#
directive|define
name|STOPPED
value|1
end_define

begin_comment
comment|/* process has stopped */
end_comment

begin_define
define|#
directive|define
name|EXITED
value|2
end_define

begin_comment
comment|/* process has exited */
end_comment

begin_define
define|#
directive|define
name|SIGNALED
value|3
end_define

begin_comment
comment|/* process was signalled */
end_comment

begin_comment
comment|/* Additional bits in the flags component */
end_comment

begin_define
define|#
directive|define
name|CHANGED
value|4
end_define

begin_comment
comment|/* This bit is set when state changes; 			   cleared when a change message has been given */
end_comment

begin_define
define|#
directive|define
name|COREDUMPED
value|8
end_define

begin_comment
comment|/* This bit is set if core was dumped */
end_comment

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

