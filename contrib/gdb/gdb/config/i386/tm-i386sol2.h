begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i386 running Solaris 2.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386SOL2_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386SOL2_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386v4.h"
end_include

begin_comment
comment|/* Signal handler frames under Solaris 2 are recognized by a return address    of 0xFFFFFFFF, the third parameter on the signal handler stack is    a pointer to an ucontext.  */
end_comment

begin_undef
undef|#
directive|undef
name|sigtramp_saved_pc
end_undef

begin_undef
undef|#
directive|undef
name|I386V4_SIGTRAMP_SAVED_PC
end_undef

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|(36 + 14 * 4)
end_define

begin_undef
undef|#
directive|undef
name|IN_SIGTRAMP
end_undef

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(pc == 0xFFFFFFFF)
end_define

begin_comment
comment|/* The SunPRO compiler puts out 0 instead of the address in N_SO symbols,    and for SunPRO 3.0, N_FUN symbols too.  */
end_comment

begin_define
define|#
directive|define
name|SOFUN_ADDRESS_MAYBE_MISSING
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sunpro_static_transform_name
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STATIC_TRANSFORM_NAME
parameter_list|(
name|x
parameter_list|)
value|sunpro_static_transform_name (x)
end_define

begin_define
define|#
directive|define
name|IS_STATIC_TRANSFORM_NAME
parameter_list|(
name|name
parameter_list|)
value|((name)[0] == '.')
end_define

begin_define
define|#
directive|define
name|FAULTED_USE_SIGINFO
end_define

begin_comment
comment|/* Macros to extract process id and thread id from a composite pid/tid */
end_comment

begin_define
define|#
directive|define
name|PIDGET
parameter_list|(
name|pid
parameter_list|)
value|((pid)& 0xffff)
end_define

begin_define
define|#
directive|define
name|TIDGET
parameter_list|(
name|pid
parameter_list|)
value|(((pid)>> 16)& 0xffff)
end_define

begin_comment
comment|/* Macro to extract carry from given regset.  */
end_comment

begin_define
define|#
directive|define
name|PS_FLAG_CARRY
value|0x1
end_define

begin_comment
comment|/* Carry bit in PS */
end_comment

begin_define
define|#
directive|define
name|PROCFS_GET_CARRY
parameter_list|(
name|regset
parameter_list|)
value|((regset)[EFL]& PS_FLAG_CARRY)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_THREAD_DB_LIB
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|solaris_pid_to_str
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
value|solaris_pid_to_str (PID)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|procfs_pid_to_str
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
value|procfs_pid_to_str (PID)
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
comment|/* ifndef TM_I386SOL2_H */
end_comment

end_unit

