begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Sequent Symmetry under ptx    with Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"nm-sysv4.h"
end_include

begin_undef
undef|#
directive|undef
name|USE_PROC_FS
end_undef

begin_include
include|#
directive|include
file|"nm-symmetry.h"
end_include

begin_define
define|#
directive|define
name|PTRACE_READ_REGS
parameter_list|(
name|pid
parameter_list|,
name|regaddr
parameter_list|)
value|mptrace (XPT_RREGS, (pid), (regaddr), 0)
end_define

begin_define
define|#
directive|define
name|PTRACE_WRITE_REGS
parameter_list|(
name|pid
parameter_list|,
name|regaddr
parameter_list|)
define|\
value|mptrace (XPT_WREGS, (pid), (regaddr), 0)
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* We must fetch all the regs before storing, since we store all at once.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_define
define|#
directive|define
name|CHILD_WAIT
end_define

begin_struct_decl
struct_decl|struct
name|target_waitstatus
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|int
name|child_wait
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|target_waitstatus
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * ptx does attach as of ptx version 2.1.  Prior to that, the interface  * exists but does not work.  *  * FIXME: Using attach/detach requires using the ptx MPDEBUGGER  * interface.  There are still problems with that, so for now don't  * enable attach/detach.  If you turn it on anyway, it will mostly  * work, but has a number of bugs. -fubar, 2/94.  */
end_comment

begin_comment
comment|/*#define ATTACH_DETACH 1*/
end_comment

begin_undef
undef|#
directive|undef
name|ATTACH_DETACH
end_undef

begin_define
define|#
directive|define
name|PTRACE_ATTACH
value|XPT_DEBUG
end_define

begin_define
define|#
directive|define
name|PTRACE_DETACH
value|XPT_UNDEBUG
end_define

begin_comment
comment|/*  * The following drivel is needed because there are two ptrace-ish  * calls on ptx: ptrace() and mptrace(), each of which does about half  * of the ptrace functions.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ATTACH_CALL
parameter_list|(
name|pid
parameter_list|)
value|ptx_do_attach(pid)
end_define

begin_define
define|#
directive|define
name|PTRACE_DETACH_CALL
parameter_list|(
name|pid
parameter_list|,
name|signo
parameter_list|)
value|ptx_do_detach(pid, signo)
end_define

end_unit

