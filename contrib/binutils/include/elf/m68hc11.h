begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m68hc11& m68hc12 ELF support for BFD.    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_M68HC11_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_M68HC11_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocation types.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_m68hc11_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_HI8
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_LO8
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_PCREL_8
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_3B
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_PCREL_16
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_GNU_VTINHERIT
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_GNU_VTENTRY
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_M68HC11_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

