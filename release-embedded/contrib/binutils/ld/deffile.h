begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* deffile.h - header for .DEF file parser    Copyright 1998, 1999, 2000, 2002, 2003 Free Software Foundation, Inc.    Written by DJ Delorie dj@cygnus.com     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA    02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFFILE_H
end_ifndef

begin_define
define|#
directive|define
name|DEFFILE_H
end_define

begin_comment
comment|/* DEF storage definitions.  Note that any ordinal may be zero, and    any pointer may be NULL, if not defined by the DEF file.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|def_file_section
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* always set */
name|char
modifier|*
name|class
decl_stmt|;
comment|/* may be NULL */
name|char
name|flag_read
decl_stmt|,
name|flag_write
decl_stmt|,
name|flag_execute
decl_stmt|,
name|flag_shared
decl_stmt|;
block|}
name|def_file_section
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|def_file_export
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* always set */
name|char
modifier|*
name|internal_name
decl_stmt|;
comment|/* always set, may == name */
name|int
name|ordinal
decl_stmt|;
comment|/* -1 if not specified */
name|int
name|hint
decl_stmt|;
name|char
name|flag_private
decl_stmt|,
name|flag_constant
decl_stmt|,
name|flag_noname
decl_stmt|,
name|flag_data
decl_stmt|,
name|flag_forward
decl_stmt|;
block|}
name|def_file_export
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|def_file_module
block|{
name|struct
name|def_file_module
modifier|*
name|next
decl_stmt|;
name|void
modifier|*
name|user_data
decl_stmt|;
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
comment|/* extended via malloc */
block|}
name|def_file_module
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|def_file_import
block|{
name|char
modifier|*
name|internal_name
decl_stmt|;
comment|/* always set */
name|def_file_module
modifier|*
name|module
decl_stmt|;
comment|/* always set */
name|char
modifier|*
name|name
decl_stmt|;
comment|/* may be NULL; either this or ordinal will be set */
name|int
name|ordinal
decl_stmt|;
comment|/* may be -1 */
name|int
name|data
decl_stmt|;
comment|/* = 1 if data */
block|}
name|def_file_import
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|def_file
block|{
comment|/* From the NAME or LIBRARY command.  */
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|is_dll
decl_stmt|;
comment|/* -1 if NAME/LIBRARY not given */
name|bfd_vma
name|base_address
decl_stmt|;
comment|/* (bfd_vma)(-1) if unspecified */
comment|/* From the DESCRIPTION command.  */
name|char
modifier|*
name|description
decl_stmt|;
comment|/* From the STACK/HEAP command, -1 if unspecified.  */
name|int
name|stack_reserve
decl_stmt|,
name|stack_commit
decl_stmt|;
name|int
name|heap_reserve
decl_stmt|,
name|heap_commit
decl_stmt|;
comment|/* From the SECTION/SEGMENT commands.  */
name|int
name|num_section_defs
decl_stmt|;
name|def_file_section
modifier|*
name|section_defs
decl_stmt|;
comment|/* From the EXPORTS commands.  */
name|int
name|num_exports
decl_stmt|;
name|def_file_export
modifier|*
name|exports
decl_stmt|;
comment|/* Used by imports for module names.  */
name|def_file_module
modifier|*
name|modules
decl_stmt|;
comment|/* From the IMPORTS commands.  */
name|int
name|num_imports
decl_stmt|;
name|def_file_import
modifier|*
name|imports
decl_stmt|;
comment|/* From the VERSION command, -1 if not specified.  */
name|int
name|version_major
decl_stmt|,
name|version_minor
decl_stmt|;
block|}
name|def_file
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|def_file
modifier|*
name|def_file_empty
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The second arg may be NULL.  If not, this .def is appended to it.  */
end_comment

begin_function_decl
specifier|extern
name|def_file
modifier|*
name|def_file_parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|def_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|def_file_free
parameter_list|(
name|def_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|def_file_export
modifier|*
name|def_file_add_export
parameter_list|(
name|def_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|def_file_import
modifier|*
name|def_file_add_import
parameter_list|(
name|def_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|def_file_add_directive
parameter_list|(
name|def_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|def_file_module
modifier|*
name|def_get_module
parameter_list|(
name|def_file
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEF_FILE_PRINT
end_ifdef

begin_function_decl
specifier|extern
name|void
name|def_file_print
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|def_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEFFILE_H */
end_comment

end_unit

