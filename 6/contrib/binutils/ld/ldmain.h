begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldmain.h -    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1999, 2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of GLD, the Gnu Linker.     GLD is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 1, or (at your option)    any later version.     GLD is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GLD; see the file COPYING.  If not, write to the Free    Software Foundation, 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LDMAIN_H
end_ifndef

begin_define
define|#
directive|define
name|LDMAIN_H
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_sysroot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ld_canon_sysroot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ld_canon_sysroot_len
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|default_target
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|trace_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|trace_file_tries
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|version_printed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|whole_archive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|as_needed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|demangling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|g_switch_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|output_filename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_info
name|link_info
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|overflow_cutoff_limit
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|add_ysym
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
name|add_wrap
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
name|add_keepsyms_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

