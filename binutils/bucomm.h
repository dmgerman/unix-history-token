begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bucomm.h -- binutils common include file.    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2005, 2006, 2007 Free Software Foundation, Inc.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|_BUCOMM_H
end_ifndef

begin_define
define|#
directive|define
name|_BUCOMM_H
end_define

begin_comment
comment|/* Return the filename in a static buffer.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|bfd_get_archive_filename
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bfd_nonfatal
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|bfd_fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|report
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|ATTRIBUTE_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|0
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|void
name|fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|non_fatal
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|set_default_bfd_target
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_matching_formats
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_supported_targets
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_supported_architectures
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|display_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_arelt_descr
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|make_tempname
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|make_tempdir
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_vma
name|parse_vma
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|off_t
name|get_file_size
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filemode.c */
end_comment

begin_function_decl
name|void
name|mode_string
parameter_list|(
name|unsigned
name|long
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* version.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_version
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* rename.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_times
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|smart_rename
parameter_list|(
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

begin_comment
comment|/* libiberty.  */
end_comment

begin_function_decl
name|void
modifier|*
name|xmalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BUCOMM_H */
end_comment

end_unit

