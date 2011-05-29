begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MC68k ELF support for BFD.    Copyright 1998, 1999, 2000, 2002, 2005, 2006 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_M68K_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_M68K_H
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
argument|elf_m68k_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_NONE
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
argument|R_68K_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* Direct 32 bit  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* Direct 16 bit  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_8
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* Direct 8 bit  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PC32
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* PC relative 32 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PC16
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* PC relative 16 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PC8
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* PC relative 8 bit */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT32
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT16
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* 16 bit PC relative GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT8
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* 8 bit PC relative GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT32O
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* 32 bit GOT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT16O
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* 16 bit GOT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GOT8O
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* 8 bit GOT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT32
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative PLT address */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT16
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* 16 bit PC relative PLT address */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT8
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* 8 bit PC relative PLT address */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT32O
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PLT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT16O
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* 16 bit PLT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_PLT8O
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* 8 bit PLT offset */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_COPY
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* Copy symbol at runtime */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GLOB_DAT
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* Create GOT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_JMP_SLOT
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* Create PLT entry */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_RELATIVE
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* Adjust by program base */
end_comment

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GNU_VTINHERIT
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_68K_GNU_VTENTRY
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_68K_max
argument_list|)
end_macro

begin_comment
comment|/* We use the top 24 bits to encode information about the    architecture variant.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CPU32
value|0x00810000
end_define

begin_define
define|#
directive|define
name|EF_M68K_M68000
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EF_M68K_CFV4E
value|0x00008000
end_define

begin_define
define|#
directive|define
name|EF_M68K_FIDO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EF_M68K_ARCH_MASK
define|\
value|(EF_M68K_M68000 | EF_M68K_CPU32 | EF_M68K_CFV4E | EF_M68K_FIDO)
end_define

begin_comment
comment|/* We use the bottom 8 bits to encode information about the    coldfire variant.  If we use any of these bits, the top 24 bits are    either 0 or EF_M68K_CFV4E.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_MASK
value|0x0F
end_define

begin_comment
comment|/* Which ISA */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_A_NODIV
value|0x01
end_define

begin_comment
comment|/* ISA A except for div */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_A
value|0x02
end_define

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_A_PLUS
value|0x03
end_define

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_B_NOUSP
value|0x04
end_define

begin_comment
comment|/* ISA_B except for USP */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_B
value|0x05
end_define

begin_define
define|#
directive|define
name|EF_M68K_CF_ISA_C
value|0x06
end_define

begin_define
define|#
directive|define
name|EF_M68K_CF_MAC_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|EF_M68K_CF_MAC
value|0x10
end_define

begin_comment
comment|/* MAC */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_EMAC
value|0x20
end_define

begin_comment
comment|/* EMAC */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_EMAC_B
value|0x30
end_define

begin_comment
comment|/* EMAC_B */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_FLOAT
value|0x40
end_define

begin_comment
comment|/* Has float insns */
end_comment

begin_define
define|#
directive|define
name|EF_M68K_CF_MASK
value|0xFF
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

