begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* M32R ELF support for BFD.    Copyright 1996, 1997, 1998, 1999, 2000, 2003 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_M32R_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_M32R_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocations.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_m32r_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* REL relocations */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_16
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_32
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_24
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_10_PCREL
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_18_PCREL
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_26_PCREL
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_HI16_ULO
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_HI16_SLO
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_LO16
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_SDA16
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GNU_VTINHERIT
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GNU_VTENTRY
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* For backwards compatibility. */
end_comment

begin_comment
comment|/* RELA relocations */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_16_RELA
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_32_RELA
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_24_RELA
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_10_PCREL_RELA
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_18_PCREL_RELA
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_26_PCREL_RELA
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_HI16_ULO_RELA
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_HI16_SLO_RELA
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_LO16_RELA
argument_list|,
literal|41
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_SDA16_RELA
argument_list|,
literal|42
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_RELA_GNU_VTINHERIT
argument_list|,
literal|43
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_RELA_GNU_VTENTRY
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOT24
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_26_PLTREL
argument_list|,
literal|49
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_COPY
argument_list|,
literal|50
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GLOB_DAT
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_JMP_SLOT
argument_list|,
literal|52
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_RELATIVE
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOTOFF
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOTPC24
argument_list|,
literal|55
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOT16_HI_ULO
argument_list|,
literal|56
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOT16_HI_SLO
argument_list|,
literal|57
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOT16_LO
argument_list|,
literal|58
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOTPC_HI_ULO
argument_list|,
literal|59
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOTPC_HI_SLO
argument_list|,
literal|60
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32R_GOTPC_LO
argument_list|,
literal|61
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_M32R_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific section indices.  These sections do not actually    exist.  Symbols with a st_shndx field corresponding to one of these    values have a special meaning.  */
end_comment

begin_comment
comment|/* Small common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_M32R_SCOMMON
value|0xff00
end_define

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* This section contains sufficient relocs to be relaxed.    When relaxing, even relocs of branch instructions the assembler could    complete must be present because relaxing may cause the branch target to    move.  */
end_comment

begin_define
define|#
directive|define
name|SHF_M32R_CAN_RELAX
value|0x10000000
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Two bit m32r architecture field.  */
end_comment

begin_define
define|#
directive|define
name|EF_M32R_ARCH
value|0x30000000
end_define

begin_comment
comment|/* m32r code.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R_ARCH
value|0x00000000
end_define

begin_comment
comment|/* m32rx code.  */
end_comment

begin_define
define|#
directive|define
name|E_M32RX_ARCH
value|0x10000000
end_define

begin_comment
comment|/* m32r2 code.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R2_ARCH
value|0x20000000
end_define

begin_comment
comment|/* 12 bit m32r new instructions field.  */
end_comment

begin_define
define|#
directive|define
name|EF_M32R_INST
value|0x0FFF0000
end_define

begin_comment
comment|/* Parallel instructions.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R_HAS_PARALLEL
value|0x00010000
end_define

begin_comment
comment|/* Hidden instructions for m32rx:    jc, jnc, macwhi-a, macwlo-a, mulwhi-a, mulwlo-a, sth+, shb+, sat, pcmpbz,    sc, snc.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R_HAS_HIDDEN_INST
value|0x00020000
end_define

begin_comment
comment|/* New bit instructions:    clrpsw, setpsw, bset, bclr, btst.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R_HAS_BIT_INST
value|0x00040000
end_define

begin_comment
comment|/* Floating point instructions.  */
end_comment

begin_define
define|#
directive|define
name|E_M32R_HAS_FLOAT_INST
value|0x00080000
end_define

begin_comment
comment|/* 4 bit m32r ignore to check field.  */
end_comment

begin_define
define|#
directive|define
name|EF_M32R_IGNORE
value|0x0000000F
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

