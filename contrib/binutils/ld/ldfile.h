begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldfile.h -    Copyright 1991, 1992 Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
name|boolean
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
comment|/* true if this is from the command line.  */
name|boolean
name|cmdline
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

begin_if
if|#
directive|if
name|ANSI_PROTOTYPES
end_if

begin_struct_decl
struct_decl|struct
name|lang_input_statement_struct
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|ldfile_add_arch
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldfile_add_library_path
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|boolean
name|cmdline
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldfile_open_command_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldfile_open_file
name|PARAMS
argument_list|(
operator|(
expr|struct
name|lang_input_statement_struct
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|ldfile_try_open_bfd
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
expr|struct
name|lang_input_statement_struct
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|ldfile_find_command_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|name
operator|,
specifier|const
name|char
operator|*
name|extend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|ldfile_set_output_arch
name|PARAMS
argument_list|(
operator|(
name|CONST
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

