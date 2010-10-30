begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Routines to help build PEPI-format DLLs (Win64 etc)    Copyright 2006 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.        Written by Kai Tietz, OneVision Software GmbH&CoKg.  */
end_comment

begin_define
define|#
directive|define
name|COFF_IMAGE_WITH_PE
end_define

begin_define
define|#
directive|define
name|COFF_WITH_PE
end_define

begin_define
define|#
directive|define
name|COFF_WITH_pex64
end_define

begin_comment
comment|/* Local defined globals.  */
end_comment

begin_define
define|#
directive|define
name|pe_def_file
value|pep_def_file
end_define

begin_define
define|#
directive|define
name|pe_details
value|pep_details
end_define

begin_define
define|#
directive|define
name|pe_dll_compat_implib
value|pep_dll_compat_implib
end_define

begin_define
define|#
directive|define
name|pe_dll_extra_pe_debug
value|pep_dll_extra_pe_debug
end_define

begin_define
define|#
directive|define
name|pe_dll_export_everything
value|pep_dll_export_everything
end_define

begin_define
define|#
directive|define
name|pe_dll_do_default_excludes
value|pep_dll_do_default_excludes
end_define

begin_define
define|#
directive|define
name|pe_dll_kill_ats
value|pep_dll_kill_ats
end_define

begin_define
define|#
directive|define
name|pe_dll_stdcall_aliases
value|pep_dll_stdcall_aliases
end_define

begin_define
define|#
directive|define
name|pe_dll_warn_dup_exports
value|pep_dll_warn_dup_exports
end_define

begin_comment
comment|/* External globals.  */
end_comment

begin_define
define|#
directive|define
name|pe_data_import_dll
value|pep_data_import_dll
end_define

begin_comment
comment|/* Unique global name for functions to avoid double defined symbols.  */
end_comment

begin_define
define|#
directive|define
name|pe_create_import_fixup
value|pep_create_import_fixup
end_define

begin_define
define|#
directive|define
name|pe_dll_generate_def_file
value|pep_dll_generate_def_file
end_define

begin_define
define|#
directive|define
name|pe_process_import_defs
value|pep_process_import_defs
end_define

begin_define
define|#
directive|define
name|pe_dll_id_target
value|pep_dll_id_target
end_define

begin_define
define|#
directive|define
name|pe_implied_import_dll
value|pep_implied_import_dll
end_define

begin_define
define|#
directive|define
name|pe_dll_build_sections
value|pep_dll_build_sections
end_define

begin_define
define|#
directive|define
name|pe_exe_build_sections
value|pep_exe_build_sections
end_define

begin_define
define|#
directive|define
name|pe_dll_fill_sections
value|pep_dll_fill_sections
end_define

begin_define
define|#
directive|define
name|pe_exe_fill_sections
value|pep_exe_fill_sections
end_define

begin_define
define|#
directive|define
name|pe_dll_generate_implib
value|pep_dll_generate_implib
end_define

begin_define
define|#
directive|define
name|pe_dll_add_excludes
value|pep_dll_add_excludes
end_define

begin_define
define|#
directive|define
name|pe_walk_relocs_of_symbol
value|pep_walk_relocs_of_symbol
end_define

begin_define
define|#
directive|define
name|pe_bfd_is_dll
value|pep_bfd_is_dll
end_define

begin_comment
comment|/* Uses x86_64 PE+.  */
end_comment

begin_define
define|#
directive|define
name|pe_use_x86_64
end_define

begin_include
include|#
directive|include
file|"pe-dll.c"
end_include

end_unit

