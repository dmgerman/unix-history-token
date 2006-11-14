begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* budbg.c -- Interfaces to the generic debugging information routines.    Copyright 1995, 1996, 2002, 2003 Free Software Foundation, Inc.    Written by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BUDBG_H
end_ifndef

begin_define
define|#
directive|define
name|BUDBG_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* Routine used to read generic debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|read_debugging_info
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routine used to print generic debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|print_debugging_info
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines used to read and write stabs information.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|start_stab
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|finish_stab
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|parse_stab
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|bfd_vma
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|write_stabs_in_sections_debugging_info
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines used to read and write IEEE debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|parse_ieee
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
specifier|const
name|bfd_byte
modifier|*
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|write_ieee_debugging_info
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routine used to read COFF debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|parse_coff
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

