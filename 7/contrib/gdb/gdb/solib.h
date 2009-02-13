begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared library declarations for GDB, the GNU Debugger.    Copyright 1992, 1993, 1995, 1998, 1999, 2000, 2001, 2003    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOLIB_H
end_ifndef

begin_define
define|#
directive|define
name|SOLIB_H
end_define

begin_comment
comment|/* Forward decl's for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Called when we free all symtabs, to free the shared library information    as well. */
end_comment

begin_define
define|#
directive|define
name|CLEAR_SOLIB
value|clear_solib
end_define

begin_function_decl
specifier|extern
name|void
name|clear_solib
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
parameter_list|,
name|readsyms
parameter_list|)
define|\
value|solib_add (filename, from_tty, targ, readsyms)
end_define

begin_function_decl
specifier|extern
name|void
name|solib_add
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

begin_comment
comment|/* Function to be called to remove the connection between debugger and    dynamic linker that was established by SOLIB_CREATE_INFERIOR_HOOK.    (This operation does not remove shared library information from    the debugger, as CLEAR_SOLIB does.)     This functionality is presently not implemented for this target.  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_REMOVE_INFERIOR_HOOK
parameter_list|(
name|PID
parameter_list|)
value|(0)
end_define

begin_function_decl
specifier|extern
name|void
name|solib_create_inferior_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* solib.c */
end_comment

begin_comment
comment|/* This function returns TRUE if pc is the address of an instruction that    lies within the dynamic linker (such as the event hook, or the dld    itself).     This function must be used only when a dynamic linker event has been    caught, and the inferior is being stepped out of the hook, or undefined    results are guaranteed.     Presently, this functionality is not implemented.  */
end_comment

begin_comment
comment|/*    #define SOLIB_IN_DYNAMIC_LINKER(pid,pc) \    error("catch of library loads/unloads not yet implemented on this platform")  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_IN_DYNAMIC_LINKER
parameter_list|(
name|pid
parameter_list|,
name|pc
parameter_list|)
define|\
value|(0)
end_define

begin_comment
comment|/* This function must be called when the inferior is killed, and the program    restarted.  This is not the same as CLEAR_SOLIB, in that it doesn't discard    any symbol tables.     Presently, this functionality is not implemented.  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_RESTART
parameter_list|()
define|\
value|(0)
end_define

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

begin_function_decl
specifier|extern
name|char
modifier|*
name|solib_address
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* Return 1 if PC lies in the dynamic symbol resolution code of the    run time loader.  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_DYNSYM_RESOLVE_CODE
parameter_list|(
name|pc
parameter_list|)
value|in_solib_dynsym_resolve_code (pc)
end_define

begin_function_decl
specifier|extern
name|int
name|in_solib_dynsym_resolve_code
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* solib.c */
end_comment

begin_comment
comment|/* Discard symbols that were auto-loaded from shared libraries. */
end_comment

begin_function_decl
specifier|extern
name|void
name|no_shared_libraries
parameter_list|(
name|char
modifier|*
name|ignored
parameter_list|,
name|int
name|from_tty
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLIB_H */
end_comment

end_unit

