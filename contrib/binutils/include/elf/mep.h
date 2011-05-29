begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Toshiba MeP ELF support for BFD.    Copyright (C) 2001, 2004, 2005 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_MEP_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_MEP_H
end_define

begin_comment
comment|/* Bits in the sh_flags field of Elf32_Shdr:  */
end_comment

begin_define
define|#
directive|define
name|SHF_MEP_VLIW
value|0x10000000
end_define

begin_comment
comment|/* contains vliw code */
end_comment

begin_comment
comment|/* This bit is reserved by BFD for processor specific stuff.  Name    it properly so that we can easily stay consistent elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|SEC_MEP_VLIW
value|SEC_TIC54X_BLOCK
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Note: The comments in this file are used by bfd/mep-relocs.pl to    build parts of bfd/elf32-mep.c.  */
end_comment

begin_comment
comment|/* Relocations.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_mep_reloc_type
argument_list|)
end_macro

begin_comment
comment|/* These two must appear first so that they are not processed by bfd/mep-relocs.pl.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_RELC
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_8
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* 7654 3210                               U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_16
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* fedc ba98 7654 3210                     U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_32
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* vuts rqpo nmlk jihg fedc ba98 7654 3210 U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_PCREL8A2
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- 7654 321-                     S PC-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_PCREL12A2
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* ---- ba98 7654 321-                     S PC-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_PCREL17A2
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- gfed cba9 8765 4321 S PC-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_PCREL24A2
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* ---- -765 4321 ---- nmlk jihg fedc ba98 S PC-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_PCABS24A2
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* ---- -765 4321 ---- nmlk jihg fedc ba98 U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_LOW16
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- fedc ba98 7654 3210 U no-overflow */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_HI16U
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- vuts rqpo nmlk jihg U no-overflow */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_HI16S
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- vuts rqpo nmlk jihg S no-overflow */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_GPREL
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- fedc ba98 7654 3210 S GP-REL*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_TPREL
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ---- fedc ba98 7654 3210 S TP-REL*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_TPREL7
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- -654 3210                     U TP-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_TPREL7A2
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- -654 321-                     U TP-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_TPREL7A4
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- -654 32--                     U TP-REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_UIMM24
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- 7654 3210 nmlk jihg fedc ba98 U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_ADDR24A4
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- 7654 32-- nmlk jihg fedc ba98 U */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_GNU_VTINHERIT
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ----                     U no-overflow */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MEP_GNU_VTENTRY
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* ---- ---- ---- ----                     U no-overflow */
end_comment

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MEP_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EF_MEP_CPU_MASK
value|0xff000000
end_define

begin_comment
comment|/* specific cpu bits */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_CPU_MEP
value|0x00000000
end_define

begin_comment
comment|/* generic MEP */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_CPU_C2
value|0x01000000
end_define

begin_comment
comment|/* MEP c2 */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_CPU_C3
value|0x02000000
end_define

begin_comment
comment|/* MEP c3 */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_CPU_C4
value|0x04000000
end_define

begin_comment
comment|/* MEP c4 */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_CPU_H1
value|0x10000000
end_define

begin_comment
comment|/* MEP h1 */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_LIBRARY
value|0x00000100
end_define

begin_comment
comment|/* Built as a library */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_INDEX_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Configuration index */
end_comment

begin_define
define|#
directive|define
name|EF_MEP_ALL_FLAGS
value|0xff0001ff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MEP_H */
end_comment

end_unit

