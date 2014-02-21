begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* COFF (SVR3) Shared library declarations for GDB, the GNU Debugger.    Copyright 1992, 1993, 1998, 1999, 2000, 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CLEAR_SOLIB
value|coff_clear_solib
end_define

begin_endif
unit|extern void coff_clear_solib (void);
endif|#
directive|endif
end_endif

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
value|coff_solib_add (filename, from_tty, targ, readsyms)
end_define

begin_function_decl
specifier|extern
name|void
name|coff_solib_add
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
value|coff_solib_create_inferior_hook()
end_define

begin_function_decl
specifier|extern
name|void
name|coff_solib_create_inferior_hook
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* solib.c */
end_comment

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

begin_comment
comment|/* This function is called by the "catch load" command.  It allows    the debugger to be notified by the dynamic linker when a specified    library file (or any library file, if filename is NULL) is loaded.     Presently, this functionality is not implemented.  */
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
comment|/* This function is called by the "catch unload" command.  It allows    the debugger to be notified by the dynamic linker when a specified    library file (or any library file, if filename is NULL) is unloaded.     Presently, this functionality is not implemented.  */
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
comment|/* This function returns TRUE if the dynamic linker has just reported    a load of a library.     This function must be used only when the inferior has stopped in    the dynamic linker hook, or undefined results are guaranteed.     Presently, this functionality is not implemented.  */
end_comment

begin_comment
comment|/*    #define SOLIB_HAVE_LOAD_EVENT(pid) \    error("catch of library loads/unloads not yet implemented on this platform")  */
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
comment|/* This function returns a pointer to the string representation of the    pathname of the dynamically-linked library that has just been loaded.     This function must be used only when SOLIB_HAVE_LOAD_EVENT is TRUE,    or undefined results are guaranteed.     This string's contents are only valid immediately after the inferior    has stopped in the dynamic linker hook, and becomes invalid as soon    as the inferior is continued.  Clients should make a copy of this    string if they wish to continue the inferior and then access the string.     Presently, this functionality is not implemented.  */
end_comment

begin_comment
comment|/*    #define SOLIB_LOADED_LIBRARY_PATHNAME(pid) \    error("catch of library loads/unloads not yet implemented on this platform")  */
end_comment

begin_define
define|#
directive|define
name|SOLIB_LOADED_LIBRARY_PATHNAME
parameter_list|(
name|pid
parameter_list|)
define|\
value|""
end_define

begin_comment
comment|/* This function returns TRUE if the dynamic linker has just reported    an unload of a library.     This function must be used only when the inferior has stopped in    the dynamic linker hook, or undefined results are guaranteed.     Presently, this functionality is not implemented.  */
end_comment

begin_comment
comment|/*    #define SOLIB_HAVE_UNLOAD_EVENT(pid) \    error("catch of library loads/unloads not yet implemented on this platform")  */
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
comment|/* This function returns a pointer to the string representation of the    pathname of the dynamically-linked library that has just been unloaded.     This function must be used only when SOLIB_HAVE_UNLOAD_EVENT is TRUE,    or undefined results are guaranteed.     This string's contents are only valid immediately after the inferior    has stopped in the dynamic linker hook, and becomes invalid as soon    as the inferior is continued.  Clients should make a copy of this    string if they wish to continue the inferior and then access the string.     Presently, this functionality is not implemented.  */
end_comment

begin_comment
comment|/*    #define SOLIB_UNLOADED_LIBRARY_PATHNAME(pid) \    error("catch of library loads/unloads not yet implemented on this platform")  */
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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|DISABLE_UNSETTABLE_BREAK
parameter_list|(
name|addr
parameter_list|)
value|coff_solib_address(addr)
end_define

begin_comment
unit|extern int solib_address (CORE_ADDR);
comment|/* solib.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

