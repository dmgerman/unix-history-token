begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARM ELF support for BFD.    Copyright 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_ARM_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_ARM_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_RELEXEC
value|0x01
end_define

begin_define
define|#
directive|define
name|EF_ARM_HASENTRY
value|0x02
end_define

begin_define
define|#
directive|define
name|EF_ARM_INTERWORK
value|0x04
end_define

begin_define
define|#
directive|define
name|EF_ARM_APCS_26
value|0x08
end_define

begin_define
define|#
directive|define
name|EF_ARM_APCS_FLOAT
value|0x10
end_define

begin_define
define|#
directive|define
name|EF_ARM_PIC
value|0x20
end_define

begin_define
define|#
directive|define
name|EF_ARM_ALIGN8
value|0x40
end_define

begin_comment
comment|/* 8-bit structure alignment is in use.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_NEW_ABI
value|0x80
end_define

begin_define
define|#
directive|define
name|EF_ARM_OLD_ABI
value|0x100
end_define

begin_define
define|#
directive|define
name|EF_ARM_SOFT_FLOAT
value|0x200
end_define

begin_define
define|#
directive|define
name|EF_ARM_VFP_FLOAT
value|0x400
end_define

begin_define
define|#
directive|define
name|EF_ARM_MAVERICK_FLOAT
value|0x800
end_define

begin_comment
comment|/* Frame unwind information */
end_comment

begin_define
define|#
directive|define
name|PT_ARM_EXIDX
value|(PT_LOPROC + 1)
end_define

begin_comment
comment|/* Other constants defined in the ARM ELF spec. version B-01.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_SYMSARESORTED
value|0x04
end_define

begin_comment
comment|/* NB conflicts with EF_INTERWORK */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_DYNSYMSUSESEGIDX
value|0x08
end_define

begin_comment
comment|/* NB conflicts with EF_APCS26 */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_MAPSYMSFIRST
value|0x10
end_define

begin_comment
comment|/* NB conflicts with EF_APCS_FLOAT */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_EABIMASK
value|0xFF000000
end_define

begin_comment
comment|/* Constants defined in AAELF.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARM_BE8
value|0x00800000
end_define

begin_define
define|#
directive|define
name|EF_ARM_LE8
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VERSION
parameter_list|(
name|flags
parameter_list|)
value|((flags)& EF_ARM_EABIMASK)
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VER1
value|0x01000000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VER2
value|0x02000000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VER3
value|0x03000000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VER4
value|0x04000000
end_define

begin_define
define|#
directive|define
name|EF_ARM_EABI_VER5
value|0x05000000
end_define

begin_comment
comment|/* Local aliases for some flags to match names used by COFF port.  */
end_comment

begin_define
define|#
directive|define
name|F_INTERWORK
value|EF_ARM_INTERWORK
end_define

begin_define
define|#
directive|define
name|F_APCS26
value|EF_ARM_APCS_26
end_define

begin_define
define|#
directive|define
name|F_APCS_FLOAT
value|EF_ARM_APCS_FLOAT
end_define

begin_define
define|#
directive|define
name|F_PIC
value|EF_ARM_PIC
end_define

begin_define
define|#
directive|define
name|F_SOFT_FLOAT
value|EF_ARM_SOFT_FLOAT
end_define

begin_define
define|#
directive|define
name|F_VFP_FLOAT
value|EF_ARM_VFP_FLOAT
end_define

begin_comment
comment|/* Additional symbol types for Thumb.  */
end_comment

begin_define
define|#
directive|define
name|STT_ARM_TFUNC
value|STT_LOPROC
end_define

begin_comment
comment|/* A Thumb function.  */
end_comment

begin_define
define|#
directive|define
name|STT_ARM_16BIT
value|STT_HIPROC
end_define

begin_comment
comment|/* A Thumb label.  */
end_comment

begin_comment
comment|/* Additional section types.  */
end_comment

begin_define
define|#
directive|define
name|SHT_ARM_EXIDX
value|0x70000001
end_define

begin_comment
comment|/* Section holds ARM unwind info.  */
end_comment

begin_define
define|#
directive|define
name|SHT_ARM_PREEMPTMAP
value|0x70000002
end_define

begin_comment
comment|/* Section pre-emption details.  */
end_comment

begin_define
define|#
directive|define
name|SHT_ARM_ATTRIBUTES
value|0x70000003
end_define

begin_comment
comment|/* Section holds attributes.  */
end_comment

begin_comment
comment|/* ARM-specific values for sh_flags.  */
end_comment

begin_define
define|#
directive|define
name|SHF_ENTRYSECT
value|0x10000000
end_define

begin_comment
comment|/* Section contains an entry point.  */
end_comment

begin_define
define|#
directive|define
name|SHF_COMDEF
value|0x80000000
end_define

begin_comment
comment|/* Section may be multiply defined in the input to a link step.  */
end_comment

begin_comment
comment|/* ARM-specific program header flags.  */
end_comment

begin_define
define|#
directive|define
name|PF_ARM_SB
value|0x10000000
end_define

begin_comment
comment|/* Segment contains the location addressed by the static base.  */
end_comment

begin_define
define|#
directive|define
name|PF_ARM_PI
value|0x20000000
end_define

begin_comment
comment|/* Segment is position-independent.  */
end_comment

begin_define
define|#
directive|define
name|PF_ARM_ABS
value|0x40000000
end_define

begin_comment
comment|/* Segment must be loaded at its base address.  */
end_comment

begin_comment
comment|/* Values for the Tag_CPU_arch EABI attribute.  */
end_comment

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_PRE_V4
value|0
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V4
value|1
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V4T
value|2
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V5T
value|3
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V5TE
value|4
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V5TEJ
value|5
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V6
value|6
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V6KZ
value|7
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V6T2
value|8
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V6K
value|9
end_define

begin_define
define|#
directive|define
name|TAG_CPU_ARCH_V7
value|10
end_define

begin_comment
comment|/* Relocation types.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_arm_reloc_type
argument_list|)
end_macro

begin_comment
comment|/* AAELF official names and numbers.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_PC24
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* deprecated */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_REL32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_PC_G0
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS12
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_ABS5
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS8
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_SBREL32
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_CALL
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC8
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_BREL_ADJ
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_SWI24
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_SWI8
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_XPC25
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_XPC22
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_DTPMOD32
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_DTPOFF32
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_TPOFF32
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_COPY
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* Copy symbol at runtime.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GLOB_DAT
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* Create GOT entry.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_JUMP_SLOT
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* Create PLT entry.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RELATIVE
argument_list|,
literal|23
argument_list|)
end_macro

begin_comment
comment|/* Adjust by program base.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOTOFF32
argument_list|,
literal|24
argument_list|)
end_macro

begin_comment
comment|/* 32 bit offset to GOT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_BASE_PREL
argument_list|,
literal|25
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative offset to GOT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOT_BREL
argument_list|,
literal|26
argument_list|)
end_macro

begin_comment
comment|/* 32 bit GOT entry.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_PLT32
argument_list|,
literal|27
argument_list|)
end_macro

begin_comment
comment|/* deprecated - 32 bit PLT address.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_CALL
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_JUMP24
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_JUMP24
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_BASE_ABS
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PCREL7_0
argument_list|,
literal|32
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PCREL15_8
argument_list|,
literal|33
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PCREL23_15
argument_list|,
literal|34
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_SBREL_11_0
argument_list|,
literal|35
argument_list|)
end_macro

begin_comment
comment|/* deprecated, should have _NC suffix */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SBREL_19_12
argument_list|,
literal|36
argument_list|)
end_macro

begin_comment
comment|/* deprecated, should have _NC suffix */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SBREL_27_20
argument_list|,
literal|37
argument_list|)
end_macro

begin_comment
comment|/* deprecated, should have _CK suffix */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TARGET1
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_SBREL31
argument_list|,
literal|39
argument_list|)
end_macro

begin_comment
comment|/* deprecated */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_V4BX
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TARGET2
argument_list|,
literal|41
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_PREL31
argument_list|,
literal|42
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVW_ABS_NC
argument_list|,
literal|43
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVT_ABS
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVW_PREL_NC
argument_list|,
literal|45
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVT_PREL
argument_list|,
literal|46
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVW_ABS_NC
argument_list|,
literal|47
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVT_ABS
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVW_PREL_NC
argument_list|,
literal|49
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVT_PREL
argument_list|,
literal|50
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_JUMP19
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_JUMP6
argument_list|,
literal|52
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_ALU_PREL_11_0
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC12
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS32_NOI
argument_list|,
literal|55
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_REL32_NOI
argument_list|,
literal|56
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PC_G0_NC
argument_list|,
literal|57
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PC_G0
argument_list|,
literal|58
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PC_G1_NC
argument_list|,
literal|59
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PC_G1
argument_list|,
literal|60
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_PC_G2
argument_list|,
literal|61
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_PC_G1
argument_list|,
literal|62
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_PC_G2
argument_list|,
literal|63
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_PC_G0
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_PC_G1
argument_list|,
literal|65
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_PC_G2
argument_list|,
literal|66
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_PC_G0
argument_list|,
literal|67
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_PC_G1
argument_list|,
literal|68
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_PC_G2
argument_list|,
literal|69
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SB_G0_NC
argument_list|,
literal|70
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SB_G0
argument_list|,
literal|71
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SB_G1_NC
argument_list|,
literal|72
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SB_G1
argument_list|,
literal|73
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ALU_SB_G2
argument_list|,
literal|74
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_SB_G0
argument_list|,
literal|75
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_SB_G1
argument_list|,
literal|76
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDR_SB_G2
argument_list|,
literal|77
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_SB_G0
argument_list|,
literal|78
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_SB_G1
argument_list|,
literal|79
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDRS_SB_G2
argument_list|,
literal|80
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_SB_G0
argument_list|,
literal|81
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_SB_G1
argument_list|,
literal|82
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_LDC_SB_G2
argument_list|,
literal|83
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVW_BREL_NC
argument_list|,
literal|84
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVT_BREL
argument_list|,
literal|85
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_MOVW_BREL
argument_list|,
literal|86
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVW_BREL_NC
argument_list|,
literal|87
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVT_BREL
argument_list|,
literal|88
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_MOVW_BREL
argument_list|,
literal|89
argument_list|)
end_macro

begin_comment
comment|/* 90-93 unallocated */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_PLT32_ABS
argument_list|,
literal|94
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOT_ABS
argument_list|,
literal|95
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOT_PREL
argument_list|,
literal|96
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOT_BREL12
argument_list|,
literal|97
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOTOFF12
argument_list|,
literal|98
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GOTRELAX
argument_list|,
literal|99
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GNU_VTENTRY
argument_list|,
literal|100
argument_list|)
end_macro

begin_comment
comment|/* deprecated - old C++ abi */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GNU_VTINHERIT
argument_list|,
literal|101
argument_list|)
end_macro

begin_comment
comment|/* deprecated - old C++ abi */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_JUMP11
argument_list|,
literal|102
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_JUMP8
argument_list|,
literal|103
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_GD32
argument_list|,
literal|104
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_LDM32
argument_list|,
literal|105
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_LDO32
argument_list|,
literal|106
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_IE32
argument_list|,
literal|107
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_LE32
argument_list|,
literal|108
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_LDO12
argument_list|,
literal|109
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_LE12
argument_list|,
literal|110
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_TLS_IE12GP
argument_list|,
literal|111
argument_list|)
end_macro

begin_comment
comment|/* 112 - 127 private range */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ME_TOO
argument_list|,
literal|128
argument_list|)
end_macro

begin_comment
comment|/* obsolete */
end_comment

begin_comment
comment|/* Extensions?  R=read-only?  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RXPC25
argument_list|,
literal|249
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RSBREL32
argument_list|,
literal|250
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_RPC22
argument_list|,
literal|251
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RREL32
argument_list|,
literal|252
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RABS32
argument_list|,
literal|253
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RPC24
argument_list|,
literal|254
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RBASE
argument_list|,
literal|255
argument_list|)
end_macro

begin_comment
comment|/* Unofficial names for some of the relocs.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_GOTOFF
argument_list|,
argument|R_ARM_GOTOFF32
argument_list|)
end_macro

begin_comment
comment|/* 32 bit offset to GOT.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_THM_PC22
argument_list|,
argument|R_ARM_THM_CALL
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_THM_PC11
argument_list|,
argument|R_ARM_THM_JUMP11
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_THM_PC9
argument_list|,
argument|R_ARM_THM_JUMP8
argument_list|)
end_macro

begin_comment
comment|/* Relocs with both a different name, and (apparently) different meaning in      GNU usage.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_GOTPC
argument_list|,
argument|R_ARM_BASE_PREL
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative offset to GOT.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_GOT32
argument_list|,
argument|R_ARM_GOT_BREL
argument_list|)
end_macro

begin_comment
comment|/* 32 bit GOT entry.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_ROSEGREL32
argument_list|,
argument|R_ARM_SBREL31
argument_list|)
end_macro

begin_comment
comment|/* ??? */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_ARM_AMP_VCALL9
argument_list|,
argument|R_ARM_BREL_ADJ
argument_list|)
end_macro

begin_comment
comment|/* Thumb-something.  Not used.  */
end_comment

begin_expr_stmt
name|END_RELOC_NUMBERS
argument_list|(
name|R_ARM_max
argument_list|)
ifdef|#
directive|ifdef
name|BFD_ARCH_SIZE
comment|/* EABI object attributes.  */
expr|enum
block|{
comment|/* 0-3 are generic.  */
name|Tag_CPU_raw_name
operator|=
literal|4
block|,
name|Tag_CPU_name
block|,
name|Tag_CPU_arch
block|,
name|Tag_CPU_arch_profile
block|,
name|Tag_ARM_ISA_use
block|,
name|Tag_THUMB_ISA_use
block|,
name|Tag_VFP_arch
block|,
name|Tag_WMMX_arch
block|,
name|Tag_NEON_arch
block|,
name|Tag_PCS_config
block|,
name|Tag_ABI_PCS_R9_use
block|,
name|Tag_ABI_PCS_RW_data
block|,
name|Tag_ABI_PCS_RO_data
block|,
name|Tag_ABI_PCS_GOT_use
block|,
name|Tag_ABI_PCS_wchar_t
block|,
name|Tag_ABI_FP_rounding
block|,
name|Tag_ABI_FP_denormal
block|,
name|Tag_ABI_FP_exceptions
block|,
name|Tag_ABI_FP_user_exceptions
block|,
name|Tag_ABI_FP_number_model
block|,
name|Tag_ABI_align8_needed
block|,
name|Tag_ABI_align8_preserved
block|,
name|Tag_ABI_enum_size
block|,
name|Tag_ABI_HardFP_use
block|,
name|Tag_ABI_VFP_args
block|,
name|Tag_ABI_WMMX_args
block|,
name|Tag_ABI_optimization_goals
block|,
name|Tag_ABI_FP_optimization_goals
block|,
comment|/* 32 is generic.  */
name|Tag_Virtualization_use
operator|=
literal|68
block|, }
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The name of the note section used to identify arm variants.  */
end_comment

begin_define
define|#
directive|define
name|ARM_NOTE_SECTION
value|".note.gnu.arm.ident"
end_define

begin_comment
comment|/* Special section names.  */
end_comment

begin_define
define|#
directive|define
name|ELF_STRING_ARM_unwind
value|".ARM.exidx"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ARM_unwind_info
value|".ARM.extab"
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ARM_unwind_once
value|".gnu.linkonce.armexidx."
end_define

begin_define
define|#
directive|define
name|ELF_STRING_ARM_unwind_info_once
value|".gnu.linkonce.armextab."
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_ARM_H */
end_comment

end_unit

