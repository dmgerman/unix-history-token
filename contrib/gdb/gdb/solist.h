begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Shared library declarations for GDB, the GNU Debugger.    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1998, 1999, 2000,    2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SOLIST_H
end_ifndef

begin_define
define|#
directive|define
name|SOLIST_H
end_define

begin_define
define|#
directive|define
name|SO_NAME_MAX_PATH_SIZE
value|512
end_define

begin_comment
comment|/* FIXME: Should be dynamic */
end_comment

begin_comment
comment|/* Forward declaration for target specific link map information.  This    struct is opaque to all but the target specific file.  */
end_comment

begin_struct_decl
struct_decl|struct
name|lm_info
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|so_list
block|{
comment|/* The following fields of the structure come directly from the        dynamic linker's tables in the inferior, and are initialized by        current_sos.  */
name|struct
name|so_list
modifier|*
name|next
decl_stmt|;
comment|/* next structure in linked list */
comment|/* A pointer to target specific link map information.  Often this        will be a copy of struct link_map from the user process, but        it need not be; it can be any collection of data needed to        traverse the dynamic linker's data structures. */
name|struct
name|lm_info
modifier|*
name|lm_info
decl_stmt|;
comment|/* Shared object file name, exactly as it appears in the        inferior's link map.  This may be a relative path, or something        which needs to be looked up in LD_LIBRARY_PATH, etc.  We use it        to tell which entries in the inferior's dynamic linker's link        map we've already loaded.  */
name|char
name|so_original_name
index|[
name|SO_NAME_MAX_PATH_SIZE
index|]
decl_stmt|;
comment|/* shared object file name, expanded to something GDB can open */
name|char
name|so_name
index|[
name|SO_NAME_MAX_PATH_SIZE
index|]
decl_stmt|;
comment|/* The following fields of the structure are built from        information gathered from the shared object file itself, and        are set when we actually add it to our symbol tables.         current_sos must initialize these fields to 0.  */
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|char
name|symbols_loaded
decl_stmt|;
comment|/* flag: symbols read in yet? */
name|char
name|from_tty
decl_stmt|;
comment|/* flag: print msgs? */
name|struct
name|objfile
modifier|*
name|objfile
decl_stmt|;
comment|/* objfile for loaded lib */
name|struct
name|section_table
modifier|*
name|sections
decl_stmt|;
name|struct
name|section_table
modifier|*
name|sections_end
decl_stmt|;
name|struct
name|section_table
modifier|*
name|textsection
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|target_so_ops
block|{
comment|/* Adjust the section binding addresses by the base address at        which the object was actually mapped.  */
name|void
function_decl|(
modifier|*
name|relocate_section_addresses
function_decl|)
parameter_list|(
name|struct
name|so_list
modifier|*
name|so
parameter_list|,
name|struct
name|section_table
modifier|*
parameter_list|)
function_decl|;
comment|/* Free the the link map info and any other private data        structures associated with a so_list entry.  */
name|void
function_decl|(
modifier|*
name|free_so
function_decl|)
parameter_list|(
name|struct
name|so_list
modifier|*
name|so
parameter_list|)
function_decl|;
comment|/* Reset or free private data structures not associated with        so_list entries.  */
name|void
function_decl|(
modifier|*
name|clear_solib
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Target dependent code to run after child process fork.  */
name|void
function_decl|(
modifier|*
name|solib_create_inferior_hook
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Do additional symbol handling, lookup, etc. after symbols        for a shared object have been loaded.  */
name|void
function_decl|(
modifier|*
name|special_symbol_handling
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Construct a list of the currently loaded shared objects.  */
name|struct
name|so_list
modifier|*
function_decl|(
modifier|*
name|current_sos
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Find, open, and read the symbols for the main executable.  */
name|int
function_decl|(
modifier|*
name|open_symbol_file_object
function_decl|)
parameter_list|(
name|void
modifier|*
name|from_ttyp
parameter_list|)
function_decl|;
comment|/* Determine if PC lies in the dynamic symbol resolution code of        the run time loader */
name|int
function_decl|(
modifier|*
name|in_dynsym_resolve_code
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
comment|/* Extra hook for finding and opening a solib.  Convenience function        for remote debuggers finding host libs */
name|int
function_decl|(
modifier|*
name|find_and_open_solib
function_decl|)
parameter_list|(
name|char
modifier|*
name|soname
parameter_list|,
name|unsigned
name|o_flags
parameter_list|,
name|char
modifier|*
modifier|*
name|temp_pathname
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|free_so
parameter_list|(
name|struct
name|so_list
modifier|*
name|so
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find solib binary file and open it.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|solib_open
parameter_list|(
name|char
modifier|*
name|in_pathname
parameter_list|,
name|char
modifier|*
modifier|*
name|found_pathname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: gdbarch needs to control this variable */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|target_so_ops
modifier|*
name|current_target_so_ops
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_SO_RELOCATE_SECTION_ADDRESSES
define|\
value|(current_target_so_ops->relocate_section_addresses)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_FREE_SO
value|(current_target_so_ops->free_so)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_CLEAR_SOLIB
value|(current_target_so_ops->clear_solib)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_SOLIB_CREATE_INFERIOR_HOOK
define|\
value|(current_target_so_ops->solib_create_inferior_hook)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_SPECIAL_SYMBOL_HANDLING
define|\
value|(current_target_so_ops->special_symbol_handling)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_CURRENT_SOS
value|(current_target_so_ops->current_sos)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_OPEN_SYMBOL_FILE_OBJECT
define|\
value|(current_target_so_ops->open_symbol_file_object)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_IN_DYNSYM_RESOLVE_CODE
define|\
value|(current_target_so_ops->in_dynsym_resolve_code)
end_define

begin_define
define|#
directive|define
name|TARGET_SO_FIND_AND_OPEN_SOLIB
define|\
value|(current_target_so_ops->find_and_open_solib)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

