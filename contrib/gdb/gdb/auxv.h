begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Auxiliary vector support for GDB, the GNU debugger.     Copyright 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AUXV_H
end_ifndef

begin_define
define|#
directive|define
name|AUXV_H
end_define

begin_comment
comment|/* See "include/elf/common.h" for the definition of valid AT_* values.  */
end_comment

begin_comment
comment|/* Avoid miscellaneous includes in this file, so that it can be    included by nm-*.h for the procfs_xfer_auxv decl if that is    used in NATIVE_XFER_AUXV.  */
end_comment

begin_struct_decl
struct_decl|struct
name|target_ops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Forward declaration.  */
end_comment

begin_comment
comment|/* Read all the auxv data into a contiguous xmalloc'd buffer,    stored in *DATA.  Return the size in bytes of this data.    If zero, there is no data and *DATA is null.    if< 0, there was an error and *DATA is null.  */
end_comment

begin_function_decl
specifier|extern
name|LONGEST
name|target_auxv_read
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|char
modifier|*
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Read one auxv entry from *READPTR, not reading locations>= ENDPTR.    Return 0 if *READPTR is already at the end of the buffer.    Return -1 if there is insufficient buffer for a whole entry.    Return 1 if an entry was read into *TYPEP and *VALP.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|target_auxv_parse
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|char
modifier|*
modifier|*
name|readptr
parameter_list|,
name|char
modifier|*
name|endptr
parameter_list|,
name|CORE_ADDR
modifier|*
name|typep
parameter_list|,
name|CORE_ADDR
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract the auxiliary vector entry with a_type matching MATCH.    Return zero if no such entry was found, or -1 if there was    an error getting the information.  On success, return 1 after    storing the entry's value field in *VALP.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|target_auxv_search
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|CORE_ADDR
name|match
parameter_list|,
name|CORE_ADDR
modifier|*
name|valp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print the contents of the target's AUXV on the specified file. */
end_comment

begin_function_decl
specifier|extern
name|int
name|fprint_target_auxv
parameter_list|(
name|struct
name|ui_file
modifier|*
name|file
parameter_list|,
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This function is called like a to_xfer_partial hook,    but must be called with TARGET_OBJECT_AUXV.    It handles access via /proc/PID/auxv, which is the common method.    This function is appropriate for doing: 	   #define NATIVE_XFER_AUXV	procfs_xfer_auxv    for a native target that uses inftarg.c's child_xfer_partial hook.  */
end_comment

begin_function_decl
specifier|extern
name|LONGEST
name|procfs_xfer_auxv
parameter_list|(
name|struct
name|target_ops
modifier|*
name|ops
parameter_list|,
name|int
comment|/* enum target_object */
name|object
parameter_list|,
specifier|const
name|char
modifier|*
name|annex
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|,
name|ULONGEST
name|offset
parameter_list|,
name|LONGEST
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

