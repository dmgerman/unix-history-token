begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CR16 ELF support for BFD.    Copyright 2007 Free Software Foundation, Inc.    Contributed by M R Swami Reddy.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_CR16_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_CR16_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Creating indices for reloc_map_index array.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_cr16_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_NUM8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_NUM16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_NUM32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_NUM32a
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL4
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL4a
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL14
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL14a
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL16
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL20
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_REGREL20a
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_ABS20
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_ABS24
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM4
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM8
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM16
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM20
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM24
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM32
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_IMM32a
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_DISP4
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_DISP8
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_DISP16
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_DISP24
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CR16_DISP24a
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_CR16_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_CR16_H */
end_comment

end_unit

