begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared library declarations for GDB, the GNU Debugger.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward decl's for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Called when we free all symtabs, to free the shared library information    as well. */
end_comment

begin_define
define|#
directive|define
name|CLEAR_SOLIB
value|clear_solib
end_define

begin_decl_stmt
specifier|extern
name|void
name|clear_solib
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called to add symbols from a shared library to gdb's symbol table. */
end_comment

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
parameter_list|)
define|\
value|solib_add (filename, from_tty, targ)
end_define

begin_decl_stmt
specifier|extern
name|void
name|solib_add
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
expr|struct
name|target_ops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function to be called when the inferior starts up, to discover the names    of shared libraries that are dynamically linked, the base addresses to    which they are linked, and sufficient information to read in their symbols    at a later time. */
end_comment

begin_define
define|#
directive|define
name|SOLIB_CREATE_INFERIOR_HOOK
parameter_list|(
name|PID
parameter_list|)
value|solib_create_inferior_hook()
end_define

begin_decl_stmt
specifier|extern
name|void
name|solib_create_inferior_hook
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* solib.c */
end_comment

begin_comment
comment|/* If we can't set a breakpoint, and it's in a shared library, just    disable it.  */
end_comment

begin_define
define|#
directive|define
name|DISABLE_UNSETTABLE_BREAK
parameter_list|(
name|addr
parameter_list|)
value|(solib_address(addr) != NULL)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|solib_address
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* solib.c */
end_comment

begin_comment
comment|/* If ADDR lies in a shared library, return its name.  */
end_comment

begin_define
define|#
directive|define
name|PC_SOLIB
parameter_list|(
name|addr
parameter_list|)
value|solib_address (addr)
end_define

end_unit

