begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldfile.h -    Copyright 1991, 1992, 1993, 1994, 1995, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDFILE_H
end_ifndef

begin_define
define|#
directive|define
name|LDFILE_H
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ldfile_input_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|ldfile_assumed_script
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|ldfile_output_machine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|bfd_architecture
name|ldfile_output_architecture
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|ldfile_output_machine_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure used to hold the list of directories to search for    libraries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|search_dirs
block|{
comment|/* Next directory on list.  */
name|struct
name|search_dirs
modifier|*
name|next
decl_stmt|;
comment|/* Name of directory.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* TRUE if this is from the command line.  */
name|bfd_boolean
name|cmdline
decl_stmt|;
comment|/* true if this is from within the sys-root.  */
name|bfd_boolean
name|sysrooted
decl_stmt|;
block|}
name|search_dirs_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|search_dirs_type
modifier|*
name|search_head
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ldfile_add_arch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldfile_add_library_path
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
name|cmdline
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldfile_open_command_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldfile_open_file
parameter_list|(
name|struct
name|lang_input_statement_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ldfile_try_open_bfd
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|lang_input_statement_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|ldfile_find_command_file
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|extend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ldfile_set_output_arch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|bfd_architecture
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ldfile_open_file_search
parameter_list|(
specifier|const
name|char
modifier|*
name|arch
parameter_list|,
name|struct
name|lang_input_statement_struct
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|lib
parameter_list|,
specifier|const
name|char
modifier|*
name|suffix
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

