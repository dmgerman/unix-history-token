begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pe-dll.h: Header file for routines used to build Windows DLLs.    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PE_DLL_H
end_ifndef

begin_define
define|#
directive|define
name|PE_DLL_H
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_include
include|#
directive|include
file|"deffile.h"
end_include

begin_decl_stmt
specifier|extern
name|def_file
modifier|*
name|pe_def_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_export_everything
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_do_default_excludes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_kill_ats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_stdcall_aliases
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_warn_dup_exports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pe_dll_compat_implib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_id_target
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_add_excludes
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_generate_def_file
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_generate_implib
name|PARAMS
argument_list|(
operator|(
name|def_file
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_process_import_defs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|pe_implied_import_dll
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_build_sections
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_exe_build_sections
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_dll_fill_sections
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|pe_exe_fill_sections
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PE_DLL_H */
end_comment

end_unit

