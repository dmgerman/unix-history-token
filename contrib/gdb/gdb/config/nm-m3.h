begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Mach 3.0 common definitions and global vars.     Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_M3_H
end_ifndef

begin_define
define|#
directive|define
name|NM_M3_H
end_define

begin_include
include|#
directive|include
file|<mach.h>
end_include

begin_comment
comment|/* Mach3 doesn't declare errno in<errno.h>.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Task port of our debugged inferior. */
end_comment

begin_decl_stmt
specifier|extern
name|task_t
name|inferior_task
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Thread port of the current thread in the inferior. */
end_comment

begin_decl_stmt
specifier|extern
name|thread_t
name|current_thread
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If nonzero, we must suspend/abort&& resume threads  * when setting or getting the state.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|must_suspend_thread
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PREPARE_TO_PROCEED
parameter_list|(
name|select_it
parameter_list|)
value|mach3_prepare_to_proceed(select_it)
end_define

begin_comment
comment|/* Try to get the privileged host port for authentication to machid  *  * If you can get this, you may debug anything on this host.  *  * If you can't, gdb gives it's own task port as the  * authentication port  */
end_comment

begin_define
define|#
directive|define
name|mach_privileged_host_port
parameter_list|()
value|task_by_pid(-1)
end_define

begin_comment
comment|/*  * This is the MIG ID number of the emulator/server bsd_execve() RPC call.  *  * It SHOULD never change, but if it does, gdb `run'  * command won't work until you fix this define.  *   */
end_comment

begin_define
define|#
directive|define
name|MIG_EXEC_SYSCALL_ID
value|101000
end_define

begin_comment
comment|/* If our_message_port gets a msg with this ID,  * GDB suspends it's inferior and enters command level.  * (Useful at least if ^C does not work)  */
end_comment

begin_define
define|#
directive|define
name|GDB_MESSAGE_ID_STOP
value|0x41151
end_define

begin_comment
comment|/* wait3 WNOHANG is defined in<sys/wait.h> but  * for some reason gdb does not want to include  * that file.  *  * If your system defines WNOHANG differently, this has to be changed.  */
end_comment

begin_define
define|#
directive|define
name|WNOHANG
value|1
end_define

begin_comment
comment|/* Before storing, we need to read all the registers.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_comment
comment|/* Check if the inferior exists */
end_comment

begin_define
define|#
directive|define
name|MACH_ERROR_NO_INFERIOR
define|\
value|do if (!MACH_PORT_VALID (inferior_task)) \   	error ("Inferior task does not exist."); while(0)
end_define

begin_comment
comment|/* Error handler for mach calls */
end_comment

begin_define
define|#
directive|define
name|CHK
parameter_list|(
name|str
parameter_list|,
name|ret
parameter_list|)
define|\
value|do if (ret != KERN_SUCCESS) \        error ("Gdb %s [%d] %s : %s\n",__FILE__,__LINE__,str, \ 	      mach_error_string(ret)); while(0)
end_define

begin_comment
comment|/* This is from POE9 emulator/emul_stack.h  */
end_comment

begin_comment
comment|/*  * Top of emulator stack holds link and reply port.  */
end_comment

begin_struct
struct|struct
name|emul_stack_top
block|{
name|struct
name|emul_stack_top
modifier|*
name|link
decl_stmt|;
name|mach_port_t
name|reply_port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|EMULATOR_STACK_SIZE
value|(4096*4)
end_define

begin_define
define|#
directive|define
name|THREAD_ALLOWED_TO_BREAK
parameter_list|(
name|mid
parameter_list|)
value|mach_thread_for_breakpoint (mid)
end_define

begin_define
define|#
directive|define
name|THREAD_PARSE_ID
parameter_list|(
name|arg
parameter_list|)
value|mach_thread_parse_id (arg)
end_define

begin_define
define|#
directive|define
name|THREAD_OUTPUT_ID
parameter_list|(
name|mid
parameter_list|)
value|mach_thread_output_id (mid)
end_define

begin_define
define|#
directive|define
name|ATTACH_TO_THREAD
value|attach_to_thread
end_define

begin_comment
comment|/* Don't do wait_for_inferior on attach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_NO_WAIT
end_define

begin_comment
comment|/* Do Mach 3 dependent operations when ^C or a STOP is requested */
end_comment

begin_define
define|#
directive|define
name|DO_QUIT
parameter_list|()
value|mach3_quit ()
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* This is bogus.  It is NOT OK to quit out of target_wait.  */
end_comment

begin_comment
comment|/* If in mach_msg() and ^C is typed set immediate_quit */
end_comment

begin_define
define|#
directive|define
name|REQUEST_QUIT
parameter_list|()
value|mach3_request_quit ()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_M3_H */
end_comment

end_unit

