begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under the win32 API Unix.    Copyright 1995, 1996, 1997, 1998, 1999, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Use SSE registers if winnt.h contains information about them.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONTEXT_EXTENDED_REGISTERS
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SSE_REGS
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|HAVE_SSE_REGS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONTEXT_EXTENDED_REGISTERS */
end_comment

begin_define
define|#
directive|define
name|HAVE_I387_REGS
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|skip_trampoline_code (pc, name)
end_define

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|skip_trampoline_code (pc, 0)
end_define

begin_endif
unit|extern CORE_ADDR skip_trampoline_code (CORE_ADDR pc, char *name);
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ATTACH_NO_WAIT
end_define

begin_define
define|#
directive|define
name|SOLIB_ADD
parameter_list|(
name|filename
parameter_list|,
name|from_tty
parameter_list|,
name|targ
parameter_list|,
name|readsyms
parameter_list|)
value|child_solib_add(filename, from_tty, targ, readsyms)
end_define

begin_define
define|#
directive|define
name|SOLIB_LOADED_LIBRARY_PATHNAME
parameter_list|(
name|pid
parameter_list|)
value|child_solib_loaded_library_pathname(pid)
end_define

begin_define
define|#
directive|define
name|CLEAR_SOLIB
value|child_clear_solibs
end_define

begin_define
define|#
directive|define
name|ADD_SHARED_SYMBOL_FILES
value|dll_symbol_command
end_define

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|cygwin_pid_to_str
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|child_solib_add
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|target_ops
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|child_solib_loaded_library_pathname
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|child_clear_solibs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dll_symbol_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

