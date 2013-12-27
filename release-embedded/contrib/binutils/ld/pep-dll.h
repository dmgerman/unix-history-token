begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pep-dll.h: Header file for routines used to build Windows DLLs.    Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.        Written by Kai Tietz, OneVision Software GmbH&CoKg.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PEP_DLL_H
end_ifndef

begin_define
define|#
directive|define
name|PEP_DLL_H
end_define

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
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
name|pep_def_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_export_everything
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_do_default_excludes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_kill_ats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_stdcall_aliases
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_warn_dup_exports
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_compat_implib
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pep_dll_extra_pe_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pep_dll_id_target
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
name|pep_dll_add_excludes
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_dll_generate_def_file
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
name|pep_dll_generate_implib
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

begin_function_decl
specifier|extern
name|void
name|pep_process_import_defs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|pep_implied_import_dll
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
name|pep_dll_build_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_exe_build_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_dll_fill_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_exe_fill_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_walk_relocs_of_symbol
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|arelent
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pep_create_import_fixup
parameter_list|(
name|arelent
modifier|*
name|rel
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|pep_bfd_is_dll
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEP_DLL_H */
end_comment

end_unit

