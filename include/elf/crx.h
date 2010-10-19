begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CRX ELF support for BFD.    Copyright 2004 Free Software Foundation, Inc.    Contributed by Tomer Levi, NSC, Israel.    Originally written for GAS 2.12 by Tomer Levi, NSC, Israel.    Updates, BFDizing, GNUifying and ELF support by Tomer Levi.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_CRX_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_CRX_H
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
argument|elf_crx_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL4
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL8
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL8_CMP
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL24
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REL32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REGREL12
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REGREL22
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REGREL28
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_REGREL32
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_ABS16
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_ABS32
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_NUM8
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_NUM16
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_NUM32
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_IMM16
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_IMM32
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_SWITCH8
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_SWITCH16
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRX_SWITCH32
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_CRX_MAX
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_CRX_H */
end_comment

end_unit

