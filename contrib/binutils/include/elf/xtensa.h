begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Xtensa ELF support for BFD.    Copyright 2003 Free Software Foundation, Inc.    Contributed by Bob Wilson (bwilson@tensilica.com) at Tensilica.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307,    USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the Xtensa ELF ABI.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_XTENSA_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_XTENSA_H
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
argument|elf_xtensa_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_RTLD
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_GLOB_DAT
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_JMP_SLOT
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_RELATIVE
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_PLT
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_OP0
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_OP1
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_OP2
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_ASM_EXPAND
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_ASM_SIMPLIFY
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_GNU_VTINHERIT
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_GNU_VTENTRY
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_XTENSA_max
argument_list|)
end_macro

begin_comment
comment|/* Processor-specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Four-bit Xtensa machine type field.  */
end_comment

begin_define
define|#
directive|define
name|EF_XTENSA_MACH
value|0x0000000f
end_define

begin_comment
comment|/* Various CPU types.  */
end_comment

begin_define
define|#
directive|define
name|E_XTENSA_MACH
value|0x00000000
end_define

begin_comment
comment|/* Leave bits 0xf0 alone in case we ever have more than 16 cpu types.    Highly unlikely, but what the heck.  */
end_comment

begin_define
define|#
directive|define
name|EF_XTENSA_XT_INSN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|EF_XTENSA_XT_LIT
value|0x00000200
end_define

begin_comment
comment|/* Processor-specific dynamic array tags.  */
end_comment

begin_comment
comment|/* Offset of the table that records the GOT location(s).  */
end_comment

begin_define
define|#
directive|define
name|DT_XTENSA_GOT_LOC_OFF
value|0x70000000
end_define

begin_comment
comment|/* Number of entries in the GOT location table.  */
end_comment

begin_define
define|#
directive|define
name|DT_XTENSA_GOT_LOC_SZ
value|0x70000001
end_define

begin_comment
comment|/* Definitions for instruction and literal property tables.  The    tables for ".gnu.linkonce.*" sections are placed in the following    sections:     instruction tables:	.gnu.linkonce.x.*    literal tables:	.gnu.linkonce.p.* */
end_comment

begin_define
define|#
directive|define
name|XTENSA_INSN_SEC_NAME
value|".xt.insn"
end_define

begin_define
define|#
directive|define
name|XTENSA_LIT_SEC_NAME
value|".xt.lit"
end_define

begin_typedef
typedef|typedef
struct|struct
name|property_table_entry_t
block|{
name|bfd_vma
name|address
decl_stmt|;
name|bfd_vma
name|size
decl_stmt|;
block|}
name|property_table_entry
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_XTENSA_H */
end_comment

end_unit

