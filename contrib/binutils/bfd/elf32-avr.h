begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* AVR-specific support for 32-bit ELF.    Copyright 2006 Free Software Foundation, Inc.     Written by Bjoern Haase<bjoern.m.haase@web.de>     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor,     Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* These four functions will be called from the ld back-end.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|elf32_avr_setup_params
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|elf32_avr_setup_section_lists
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
name|elf32_avr_size_stubs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|elf32_avr_build_stubs
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

