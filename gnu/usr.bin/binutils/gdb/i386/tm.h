begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Target macro definitions for i386 running FreeBSD    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|TM_FBSD_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386bsd.h"
end_include

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|16
end_define

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|setup_arbitrary_frame
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SETUP_ARBITRARY_FRAME
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|setup_arbitrary_frame (argc, argv)
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_float_info
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FLOAT_INFO
value|i386_float_info ()
end_define

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|STREQ (name, "_DYNAMIC")
end_define

begin_comment
comment|/* Saved Pc.  Get it from sigcontext if within sigtramp.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|fbsd_kern_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|(kernel_debugging ? fbsd_kern_frame_saved_pc(FRAME) : \   (((FRAME)->signal_handler_caller \     ? sigtramp_saved_pc (FRAME) \     : read_memory_integer ((FRAME)->frame + 4, 4)) \    ))
end_define

begin_comment
comment|/* On FreeBSD, sigtramp has size 0x18 and is immediately below the    ps_strings struct which has size 0x10 and is at the top of the    user stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIGTRAMP_START
end_undef

begin_undef
undef|#
directive|undef
name|SIGTRAMP_END
end_undef

begin_define
define|#
directive|define
name|SIGTRAMP_START
parameter_list|(
name|pc
parameter_list|)
value|0xbfbfdfd8
end_define

begin_define
define|#
directive|define
name|SIGTRAMP_END
parameter_list|(
name|pc
parameter_list|)
value|0xbfbfdff0
end_define

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|freebsd_uthread_new_objfile
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
name|objfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|target_new_objfile
parameter_list|(
name|OBJFILE
parameter_list|)
value|freebsd_uthread_new_objfile (OBJFILE)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|freebsd_uthread_pid_to_str
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
value|freebsd_uthread_pid_to_str (PID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_FBSD_H */
end_comment

end_unit

