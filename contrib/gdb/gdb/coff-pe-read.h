begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface to coff-pe-read.c (portable-executable-specific symbol reader).     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.     Contributed by Raoul M. Gough (RaoulGough@yahoo.co.uk). */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|COFF_PE_READ_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|COFF_PE_READ_H
end_define

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_comment
comment|/* Read the export table and convert it to minimal symbol table entries */
end_comment

begin_function_decl
specifier|extern
name|void
name|read_pe_exported_syms
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (COFF_PE_READ_H) */
end_comment

end_unit

