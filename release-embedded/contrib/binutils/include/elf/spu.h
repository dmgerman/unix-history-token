begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPU ELF support for BFD.     Copyright 2006, 2007 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SPU_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SPU_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* elf32-spu.c depends on these being consecutive. */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_spu_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR10
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR16_HI
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR16_LO
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR18
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_REL16
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR7
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_REL9
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_REL9I
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR10I
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR16I
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_REL32
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_ADDR16X
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_PPU32
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPU_PPU64
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_SPU_max
argument_list|)
end_macro

begin_comment
comment|/* Program header extensions */
end_comment

begin_comment
comment|/* Mark a PT_LOAD segment as containing an overlay which should not    initially be loaded.  */
end_comment

begin_define
define|#
directive|define
name|PF_OVERLAY
value|(1<< 27)
end_define

begin_comment
comment|/* SPU Dynamic Object Information.  */
end_comment

begin_define
define|#
directive|define
name|PT_SPU_INFO
value|0x70000000
end_define

begin_comment
comment|/* SPU plugin information */
end_comment

begin_define
define|#
directive|define
name|SPU_PLUGIN_NAME
value|"SPUNAME"
end_define

begin_define
define|#
directive|define
name|SPU_PTNOTE_SPUNAME
value|".note.spu_name"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_SPU_H */
end_comment

end_unit

