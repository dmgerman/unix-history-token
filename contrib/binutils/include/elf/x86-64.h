begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* x86_64 ELF support for BFD.    Copyright (C) 2000, 2001, 2002, 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by Jan Hubicka<jh@suse.cz>     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_X86_64_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_X86_64_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_x86_64_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* No reloc */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_64
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* Direct 64 bit  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PC32
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* PC relative 32 bit signed */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOT32
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* 32 bit GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PLT32
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PLT address */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_COPY
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* Copy symbol at runtime */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GLOB_DAT
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* Create GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_JUMP_SLOT
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* Create PLT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_RELATIVE
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* Adjust by program base */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPCREL
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* 32 bit signed pc relative                                                  offset to GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_32
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* Direct 32 bit zero extended */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_32S
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* Direct 32 bit sign extended */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_16
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* Direct 16 bit zero extended */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PC16
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* 16 bit sign extended pc relative*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_8
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* Direct 8 bit sign extended */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PC8
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* 8 bit sign extended pc relative*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_DTPMOD64
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* ID of module containing symbol */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_DTPOFF64
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* Offset in TLS block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TPOFF64
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* Offset in initial TLS block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TLSGD
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* PC relative offset to GD GOT block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TLSLD
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* PC relative offset to LD GOT block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_DTPOFF32
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* Offset in TLS block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTTPOFF
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* PC relative offset to IE GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TPOFF32
argument_list|,
literal|23
argument_list|)
end_macro

begin_comment
comment|/* Offset in initial TLS block */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PC64
argument_list|,
literal|24
argument_list|)
end_macro

begin_comment
comment|/* PC relative 64 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTOFF64
argument_list|,
literal|25
argument_list|)
end_macro

begin_comment
comment|/* 64 bit offset to GOT */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPC32
argument_list|,
literal|26
argument_list|)
end_macro

begin_comment
comment|/* 32 bit signed pc relative                                                  offset to GOT */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOT64
argument_list|,
literal|27
argument_list|)
end_macro

begin_comment
comment|/* 64 bit GOT entry offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPCREL64
argument_list|,
literal|28
argument_list|)
end_macro

begin_comment
comment|/* 64 bit signed pc relative      						 offset to GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPC64
argument_list|,
literal|29
argument_list|)
end_macro

begin_comment
comment|/* 64 bit signed pc relative      						 offset to GOT */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPLT64
argument_list|,
literal|30
argument_list|)
end_macro

begin_comment
comment|/* like GOT64, but indicates      						 that PLT entry is needed */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_PLTOFF64
argument_list|,
literal|31
argument_list|)
end_macro

begin_comment
comment|/* 64 bit GOT relative offset      						 to PLT entry */
end_comment

begin_comment
comment|/* 32 .. 33 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GOTPC32_TLSDESC
argument_list|,
literal|34
argument_list|)
end_macro

begin_comment
comment|/* 32 bit signed pc relative 						 offset to TLS descriptor 						 in the GOT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TLSDESC_CALL
argument_list|,
literal|35
argument_list|)
end_macro

begin_comment
comment|/* Relaxable call through TLS 						 descriptor.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_TLSDESC
argument_list|,
literal|36
argument_list|)
end_macro

begin_comment
comment|/* 2x64-bit TLS descriptor.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GNU_VTINHERIT
argument_list|,
literal|250
argument_list|)
end_macro

begin_comment
comment|/* GNU C++ hack  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_X86_64_GNU_VTENTRY
argument_list|,
literal|251
argument_list|)
end_macro

begin_comment
comment|/* GNU C++ hack  */
end_comment

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_X86_64_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_define
define|#
directive|define
name|SHT_X86_64_UNWIND
value|0x70000001
end_define

begin_comment
comment|/* unwind information */
end_comment

begin_comment
comment|/* Like SHN_COMMON but the symbol will be allocated in the .lbss    section.  */
end_comment

begin_define
define|#
directive|define
name|SHN_X86_64_LCOMMON
value|0xff02
end_define

begin_define
define|#
directive|define
name|SHF_X86_64_LARGE
value|0x10000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

