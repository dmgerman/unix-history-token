begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* i860 ELF support for BFD.    Copyright 2000 Free Software Foundation, Inc.     Contributed by Jason Eckhardt<jle@cygnus.com>.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_I860_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_I860_H
end_define

begin_comment
comment|/* Note: i860 ELF is defined to use only RELA relocations.  */
end_comment

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_i860_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_NONE
argument_list|,
literal|0x00
argument_list|)
end_macro

begin_comment
comment|/* No reloc */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_32
argument_list|,
literal|0x01
argument_list|)
end_macro

begin_comment
comment|/* S+A  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_COPY
argument_list|,
literal|0x02
argument_list|)
end_macro

begin_comment
comment|/* No calculation */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_GLOB_DAT
argument_list|,
literal|0x03
argument_list|)
end_macro

begin_comment
comment|/* S, Create GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_JUMP_SLOT
argument_list|,
literal|0x04
argument_list|)
end_macro

begin_comment
comment|/* S+A, Create PLT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_RELATIVE
argument_list|,
literal|0x05
argument_list|)
end_macro

begin_comment
comment|/* B+A, Adj by program base */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_PC26
argument_list|,
literal|0x30
argument_list|)
end_macro

begin_comment
comment|/* (S+A-P)>> 2 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_PLT26
argument_list|,
literal|0x31
argument_list|)
end_macro

begin_comment
comment|/* (L+A-P)>> 2 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_PC16
argument_list|,
literal|0x32
argument_list|)
end_macro

begin_comment
comment|/* (S+A-P)>> 2 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOW0
argument_list|,
literal|0x40
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPLIT0
argument_list|,
literal|0x42
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOW1
argument_list|,
literal|0x44
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPLIT1
argument_list|,
literal|0x46
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOW2
argument_list|,
literal|0x48
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPLIT2
argument_list|,
literal|0x4A
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOW3
argument_list|,
literal|0x4C
argument_list|)
end_macro

begin_comment
comment|/* S+A */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOT0
argument_list|,
literal|0x50
argument_list|)
end_macro

begin_comment
comment|/* G */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPGOT0
argument_list|,
literal|0x52
argument_list|)
end_macro

begin_comment
comment|/* G */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOT1
argument_list|,
literal|0x54
argument_list|)
end_macro

begin_comment
comment|/* G */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPGOT1
argument_list|,
literal|0x56
argument_list|)
end_macro

begin_comment
comment|/* G */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOTOFF0
argument_list|,
literal|0x60
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPGOTOFF0
argument_list|,
literal|0x62
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOTOFF1
argument_list|,
literal|0x64
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_SPGOTOFF1
argument_list|,
literal|0x66
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOTOFF2
argument_list|,
literal|0x68
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOGOTOFF3
argument_list|,
literal|0x6C
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_LOPC
argument_list|,
literal|0x70
argument_list|)
end_macro

begin_comment
comment|/* (S+A-P)>> 2 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HIGHADJ
argument_list|,
literal|0x80
argument_list|)
end_macro

begin_comment
comment|/* hiadj(S+A) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HAGOT
argument_list|,
literal|0x90
argument_list|)
end_macro

begin_comment
comment|/* hiadj(G) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HAGOTOFF
argument_list|,
literal|0xA0
argument_list|)
end_macro

begin_comment
comment|/* hiadj(O) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HAPC
argument_list|,
literal|0xB0
argument_list|)
end_macro

begin_comment
comment|/* hiadj((S+A-P)>> 2) */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HIGH
argument_list|,
literal|0xC0
argument_list|)
end_macro

begin_comment
comment|/* (S+A)>> 16 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HIGOT
argument_list|,
literal|0xD0
argument_list|)
end_macro

begin_comment
comment|/* G>> 16 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_860_HIGOTOFF
argument_list|,
literal|0xE0
argument_list|)
end_macro

begin_comment
comment|/* O */
end_comment

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_860_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

