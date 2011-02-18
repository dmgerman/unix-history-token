begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Score ELF support for BFD.    Copyright 2006 Free Software Foundation, Inc.    Contributed by     Mei Ligang (ligang@sunnorth.com.cn)    Pei-Lin Tsai (pltsai@sunplus.com)     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SCORE_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SCORE_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_define
define|#
directive|define
name|SCORE_SIMULATOR_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|OPC_PTMASK
value|0xc0000000
end_define

begin_comment
comment|/* Parity-bit Mask.  */
end_comment

begin_define
define|#
directive|define
name|OPC16_PTMASK
value|0x00008000
end_define

begin_comment
comment|/* The parity-bit denotes.  */
end_comment

begin_define
define|#
directive|define
name|OPC_32
value|0xc0000000
end_define

begin_comment
comment|/* Denotes 32b instruction, (default).  */
end_comment

begin_define
define|#
directive|define
name|OPC_16
value|0x00000000
end_define

begin_comment
comment|/* Denotes 16b instruction.  */
end_comment

begin_define
define|#
directive|define
name|OPC_PE
value|0x8000
end_define

begin_comment
comment|/* Denotes parallel-execution instructions.  */
end_comment

begin_define
define|#
directive|define
name|GP_DISP_LABEL
value|"_gp_disp"
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field:  */
end_comment

begin_comment
comment|/* File contains position independent code.  */
end_comment

begin_define
define|#
directive|define
name|EF_SCORE_PIC
value|0x80000000
end_define

begin_comment
comment|/* Fix data dependency.  */
end_comment

begin_define
define|#
directive|define
name|EF_SCORE_FIXDEP
value|0x40000000
end_define

begin_comment
comment|/* Defined and allocated common symbol.  Value is virtual address.  If    relocated, alignment must be preserved.  */
end_comment

begin_define
define|#
directive|define
name|SHN_SCORE_TEXT
value|0xff01
end_define

begin_define
define|#
directive|define
name|SHN_SCORE_DATA
value|0xff02
end_define

begin_comment
comment|/* Small common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_SCORE_SCOMMON
value|0xff03
end_define

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* This section must be in the global data area.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_GPREL
value|0x10000000
end_define

begin_comment
comment|/* This section should be merged.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_MERGE
value|0x20000000
end_define

begin_comment
comment|/* This section contains address data of size implied by section    element size.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_ADDR
value|0x40000000
end_define

begin_comment
comment|/* This section contains string data.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_STRING
value|0x80000000
end_define

begin_comment
comment|/* This section may not be stripped.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_NOSTRIP
value|0x08000000
end_define

begin_comment
comment|/* This section is local to threads.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_LOCAL
value|0x04000000
end_define

begin_comment
comment|/* Linker should generate implicit weak names for this section.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_NAMES
value|0x02000000
end_define

begin_comment
comment|/* Section contais text/data which may be replicated in other sections.    Linker should retain only one copy.  */
end_comment

begin_define
define|#
directive|define
name|SHF_SCORE_NODUPES
value|0x01000000
end_define

begin_comment
comment|/* Processor specific dynamic array tags.  */
end_comment

begin_comment
comment|/* Base address of the segment.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_BASE_ADDRESS
value|0x70000001
end_define

begin_comment
comment|/* Number of local global offset table entries.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_LOCAL_GOTNO
value|0x70000002
end_define

begin_comment
comment|/* Number of entries in the .dynsym section.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_SYMTABNO
value|0x70000003
end_define

begin_comment
comment|/* Index of first dynamic symbol in global offset table.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_GOTSYM
value|0x70000004
end_define

begin_comment
comment|/* Index of first external dynamic symbol not referenced locally.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_UNREFEXTNO
value|0x70000005
end_define

begin_comment
comment|/* Number of page table entries in global offset table.  */
end_comment

begin_define
define|#
directive|define
name|DT_SCORE_HIPAGENO
value|0x70000006
end_define

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_comment
comment|/* Relocation types.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_score_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_HI16
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_LO16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_DUMMY1
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_24
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_PC19
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE16_11
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE16_PC8
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_ABS32
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_ABS16
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_DUMMY2
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GP15
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GNU_VTINHERIT
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GNU_VTENTRY
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GOT15
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GOT_LO16
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_CALL15
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_GPREL32
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_REL32
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SCORE_DUMMY_HI16
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_SCORE_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_SCORE_H */
end_comment

end_unit

