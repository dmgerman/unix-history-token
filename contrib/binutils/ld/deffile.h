begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* deffile.h - header for .DEF file parser    Copyright 1998, 1999, 2000 Free Software Foundation, Inc.    Written by DJ Delorie dj@cygnus.com     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

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
block|}
name|def_file_import
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|def_file
block|{
comment|/* from the NAME or LIBRARY command */
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
comment|/* from the DESCRIPTION command */
name|char
modifier|*
name|description
decl_stmt|;
comment|/* from the STACK/HEAP command, -1 if unspecified */
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
comment|/* from the SECTION/SEGMENT commands */
name|int
name|num_section_defs
decl_stmt|;
name|def_file_section
modifier|*
name|section_defs
decl_stmt|;
comment|/* from the EXPORTS commands */
name|int
name|num_exports
decl_stmt|;
name|def_file_export
modifier|*
name|exports
decl_stmt|;
comment|/* used by imports for module names */
name|def_file_module
modifier|*
name|modules
decl_stmt|;
comment|/* from the IMPORTS commands */
name|int
name|num_imports
decl_stmt|;
name|def_file_import
modifier|*
name|imports
decl_stmt|;
comment|/* from the VERSION command, -1 if not specified */
name|int
name|version_major
decl_stmt|,
name|version_minor
decl_stmt|;
block|}
name|def_file
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|def_file
modifier|*
name|def_file_empty
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* add_to may be NULL.  If not, this .def is appended to it */
end_comment

begin_decl_stmt
specifier|extern
name|def_file
modifier|*
name|def_file_parse
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|_filename
operator|,
name|def_file
operator|*
name|_add_to
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|def_file_free
name|PARAMS
argument_list|(
operator|(
name|def_file
operator|*
name|_def
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|def_file_export
modifier|*
name|def_file_add_export
name|PARAMS
argument_list|(
operator|(
name|def_file
operator|*
name|_def
operator|,
specifier|const
name|char
operator|*
name|_name
operator|,
specifier|const
name|char
operator|*
name|_internal_name
operator|,
name|int
name|_ordinal
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|def_file_import
modifier|*
name|def_file_add_import
name|PARAMS
argument_list|(
operator|(
name|def_file
operator|*
name|_def
operator|,
specifier|const
name|char
operator|*
name|_name
operator|,
specifier|const
name|char
operator|*
name|_from
operator|,
name|int
name|_ordinal
operator|,
specifier|const
name|char
operator|*
name|_imported_name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|def_file_add_directive
name|PARAMS
argument_list|(
operator|(
name|def_file
operator|*
name|_def
operator|,
specifier|const
name|char
operator|*
name|param
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEF_FILE_PRINT
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|def_file_print
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|_file
operator|,
name|def_file
operator|*
name|_def
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

