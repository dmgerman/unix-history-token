begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared library declarations for GDB, the GNU Debugger.    Copyright (C) 1992, 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* Function to be called to remove the connection between debugger and    dynamic linker that was established by SOLIB_CREATE_INFERIOR_HOOK.    (This operation does not remove shared library information from    the debugger, as CLEAR_SOLIB does.)     This functionality is presently not implemented for this target.    */
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
comment|/* This function is called by the "catch load" command.  It allows    the debugger to be notified by the dynamic linker when a specified    library file (or any library file, if filename is NULL) is loaded.     Presently, this functionality is not implemented.    */
end_comment

begin_define
define|#
directive|define
name|SOLIB_CREATE_CATCH_LOAD_HOOK
parameter_list|(
name|pid
parameter_list|,
name|tempflag
parameter_list|,
name|filename
parameter_list|,
name|cond_string
parameter_list|)
define|\
value|error("catch of library loads/unloads not yet implemented on this platform")
end_define

begin_comment
comment|/* This function is called by the "catch unload" command.  It allows    the debugger to be notified by the dynamic linker when a specified    library file (or any library file, if filename is NULL) is unloaded.     Presently, this functionality is not implemented.    */
end_comment

begin_define
define|#
directive|define
name|SOLIB_CREATE_CATCH_UNLOAD_HOOK
parameter_list|(
name|pid
parameter_list|,
name|tempflag
parameter_list|,
name|filename
parameter_list|,
name|cond_string
parameter_list|)
define|\
value|error("catch of library loads/unloads not yet implemented on this platform")
end_define

begin_comment
comment|/* This function returns TRUE if the dynamic linker has just reported    a load of a library.     This function must be used only when the inferior has stopped in    the dynamic linker hook, or undefined results are guaranteed.     Presently, this functionality is not implemented.    */
end_comment

begin_comment
comment|/* #define SOLIB_HAVE_LOAD_EVENT(pid) \     error("catch of library loads/unloads not yet implemented on this platform") */
end_comment

begin_define
define|#
directive|define
name|SOLIB_HAVE_LOAD_EVENT
parameter_list|(
name|pid
parameter_list|)
define|\
value|(0)
end_define

begin_comment
comment|/* This function returns a pointer to the string representation of the    pathname of the dynamically-linked library that has just been loaded.     This function must be used only when SOLIB_HAVE_LOAD_EVENT is TRUE,    or undefined results are guaranteed.     This string's contents are only valid immediately after the inferior    has stopped in the dynamic linker hook, and becomes invalid as soon    as the inferior is continued.  Clients should make a copy of this    string if they wish to continue the inferior and then access the string.     Presently, this functionality is not implemented.    */
end_comment

begin_comment
comment|/* #define SOLIB_LOADED_LIBRARY_PATHNAME(pid) \    error("catch of library loads/unloads not yet implemented on this platform") */
end_comment

begin_define
define|#
directive|define
name|SOLIB_LOADED_LIBRARY_PATHNAME
parameter_list|(
name|pid
parameter_list|)
define|\
value|(0)
end_define

begin_comment
comment|/* This function returns TRUE if the dynamic linker has just reported    an unload of a library.     This function must be used only when the inferior has stopped in    the dynamic linker hook, or undefined results are guaranteed.     Presently, this functionality is not implemented.    */
end_comment

begin_comment
comment|/* #define SOLIB_HAVE_UNLOAD_EVENT(pid) \    error("catch of library loads/unloads not yet implemented on this platform") */
end_comment

begin_define
define|#
directive|define
name|SOLIB_HAVE_UNLOAD_EVENT
parameter_list|(
name|pid
parameter_list|)
define|\
value|(0)
end_define

begin_comment
comment|/* This function returns a pointer to the string representation of the    pathname of the dynamically-linked library that has just been unloaded.     This function must be used only when SOLIB_HAVE_UNLOAD_EVENT is TRUE,    or undefined results are guaranteed.     This string's contents are only valid immediately after the inferior    has stopped in the dynamic linker hook, and becomes invalid as soon    as the inferior is continued.  Clients should make a copy of this    string if they wish to continue the inferior and then access the string.     Presently, this functionality is not implemented.    */
end_comment

begin_comment
comment|/* #define SOLIB_UNLOADED_LIBRARY_PATHNAME(pid) \    error("catch of library loads/unloads not yet implemented on this platform") */
end_comment

begin_define
define|#
directive|define
name|SOLIB_UNLOADED_LIBRARY_PATHNAME
parameter_list|(
name|pid
parameter_list|)
define|\
value|(0)
end_define

begin_comment
comment|/* This function returns TRUE if pc is the address of an instruction that    lies within the dynamic linker (such as the event hook, or the dld    itself).     This function must be used only when a dynamic linker event has been    caught, and the inferior is being stepped out of the hook, or undefined    results are guaranteed.     Presently, this functionality is not implemented.    */
end_comment

begin_comment
comment|/* #define SOLIB_IN_DYNAMIC_LINKER(pid,pc) \    error("catch of library loads/unloads not yet implemented on this platform") */
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
comment|/* This function must be called when the inferior is killed, and the program    restarted.  This is not the same as CLEAR_SOLIB, in that it doesn't discard    any symbol tables.     Presently, this functionality is not implemented.    */
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

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4_SHARED_LIBS
end_ifdef

begin_comment
comment|/* Return 1 if PC lies in the dynamic symbol resolution code of the    SVR4 run time loader.  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_DYNSYM_RESOLVE_CODE
parameter_list|(
name|pc
parameter_list|)
value|in_svr4_dynsym_resolve_code (pc)
end_define

begin_decl_stmt
specifier|extern
name|int
name|in_svr4_dynsym_resolve_code
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

