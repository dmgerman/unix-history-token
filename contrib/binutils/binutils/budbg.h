begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* budbg.c -- Interfaces to the generic debugging information routines.    Copyright (C) 1995, 1996 Free Software Foundation, Inc.    Written by Ian Lance Taylor<ian@cygnus.com>.     This file is part of GNU Binutils.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
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

begin_decl_stmt
specifier|extern
name|PTR
name|read_debugging_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routine used to print generic debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|print_debugging_info
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines used to read and write stabs information.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|start_stab
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd
operator|*
operator|,
name|boolean
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|finish_stab
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|parse_stab
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|PTR
operator|,
name|int
operator|,
name|int
operator|,
name|bfd_vma
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
name|boolean
name|write_stabs_in_sections_debugging_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
name|bfd_byte
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|,
name|bfd_byte
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines used to read and write IEEE debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|parse_ieee
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd
operator|*
operator|,
specifier|const
name|bfd_byte
operator|*
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|write_ieee_debugging_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routine used to read COFF debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|parse_coff
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|long
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

