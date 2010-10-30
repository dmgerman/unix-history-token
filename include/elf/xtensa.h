begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Xtensa ELF support for BFD.    Copyright 2003, 2004 Free Software Foundation, Inc.    Contributed by Bob Wilson (bwilson@tensilica.com) at Tensilica.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
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
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_DIFF8
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_DIFF16
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_DIFF32
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT0_OP
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT1_OP
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT2_OP
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT3_OP
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT4_OP
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT5_OP
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT6_OP
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT7_OP
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT8_OP
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT9_OP
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT10_OP
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT11_OP
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT12_OP
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT13_OP
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT14_OP
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT0_ALT
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT1_ALT
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT2_ALT
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT3_ALT
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT4_ALT
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT5_ALT
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT6_ALT
argument_list|,
literal|41
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT7_ALT
argument_list|,
literal|42
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT8_ALT
argument_list|,
literal|43
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT9_ALT
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT10_ALT
argument_list|,
literal|45
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT11_ALT
argument_list|,
literal|46
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT12_ALT
argument_list|,
literal|47
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT13_ALT
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_XTENSA_SLOT14_ALT
argument_list|,
literal|49
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

begin_define
define|#
directive|define
name|XTENSA_PROP_SEC_NAME
value|".xt.prop"
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
name|flagword
name|flags
decl_stmt|;
block|}
name|property_table_entry
typedef|;
end_typedef

begin_comment
comment|/* Flags in the property tables to specify whether blocks of memory are    literals, instructions, data, or unreachable.  For instructions,    blocks that begin loop targets and branch targets are designated.    Blocks that do not allow density instructions, instruction reordering    or transformation are also specified.  Finally, for branch targets,    branch target alignment priority is included.  Alignment of the next    block is specified in the current block and the size of the current    block does not include any fill required to align to the next    block.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_LITERAL
value|0x00000001
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_DATA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_UNREACHABLE
value|0x00000008
end_define

begin_comment
comment|/* Instruction-only properties at beginning of code. */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN_LOOP_TARGET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN_BRANCH_TARGET
value|0x00000020
end_define

begin_comment
comment|/* Instruction-only properties about code. */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN_NO_DENSITY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN_NO_REORDER
value|0x00000080
end_define

begin_comment
comment|/* Historically, NO_TRANSFORM was a property of instructions,     but it should apply to literals under certain circumstances.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_NO_TRANSFORM
value|0x00000100
end_define

begin_comment
comment|/*  Branch target alignment information.  This transmits information     to the linker optimization about the priority of aligning a     particular block for branch target alignment: None, low priority,     high priority, or required.  These only need to be checked in     instruction blocks marked as XTENSA_PROP_INSN_BRANCH_TARGET.     Common usage is:      switch (GET_XTENSA_PROP_BT_ALIGN(flags))     case XTENSA_PROP_BT_ALIGN_NONE:     case XTENSA_PROP_BT_ALIGN_LOW:     case XTENSA_PROP_BT_ALIGN_HIGH:     case XTENSA_PROP_BT_ALIGN_REQUIRE: */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_BT_ALIGN_MASK
value|0x00000600
end_define

begin_comment
comment|/* No branch target alignment.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_BT_ALIGN_NONE
value|0x0
end_define

begin_comment
comment|/* Low priority branch target alignment.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_BT_ALIGN_LOW
value|0x1
end_define

begin_comment
comment|/* High priority branch target alignment. */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_BT_ALIGN_HIGH
value|0x2
end_define

begin_comment
comment|/* Required branch target alignment.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_BT_ALIGN_REQUIRE
value|0x3
end_define

begin_define
define|#
directive|define
name|GET_XTENSA_PROP_BT_ALIGN
parameter_list|(
name|flag
parameter_list|)
define|\
value|(((unsigned)((flag)& (XTENSA_PROP_BT_ALIGN_MASK)))>> 9)
end_define

begin_define
define|#
directive|define
name|SET_XTENSA_PROP_BT_ALIGN
parameter_list|(
name|flag
parameter_list|,
name|align
parameter_list|)
define|\
value|(((flag)& (~XTENSA_PROP_BT_ALIGN_MASK)) | \     (((align)<< 9)& XTENSA_PROP_BT_ALIGN_MASK))
end_define

begin_comment
comment|/* Alignment is specified in the block BEFORE the one that needs    alignment.  Up to 5 bits.  Use GET_XTENSA_PROP_ALIGNMENT(flags) to    get the required alignment specified as a power of 2.  Use    SET_XTENSA_PROP_ALIGNMENT(flags, pow2) to set the required    alignment.  Be careful of side effects since the SET will evaluate    flags twice.  Also, note that the SIZE of a block in the property    table does not include the alignment size, so the alignment fill    must be calculated to determine if two blocks are contiguous.    TEXT_ALIGN is not currently implemented but is a placeholder for a    possible future implementation.  */
end_comment

begin_define
define|#
directive|define
name|XTENSA_PROP_ALIGN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_ALIGNMENT_MASK
value|0x0001f000
end_define

begin_define
define|#
directive|define
name|GET_XTENSA_PROP_ALIGNMENT
parameter_list|(
name|flag
parameter_list|)
define|\
value|(((unsigned)((flag)& (XTENSA_PROP_ALIGNMENT_MASK)))>> 12)
end_define

begin_define
define|#
directive|define
name|SET_XTENSA_PROP_ALIGNMENT
parameter_list|(
name|flag
parameter_list|,
name|align
parameter_list|)
define|\
value|(((flag)& (~XTENSA_PROP_ALIGNMENT_MASK)) | \     (((align)<< 12)& XTENSA_PROP_ALIGNMENT_MASK))
end_define

begin_define
define|#
directive|define
name|XTENSA_PROP_INSN_ABSLIT
value|0x00020000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_XTENSA_H */
end_comment

end_unit

