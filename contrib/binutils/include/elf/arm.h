begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARM ELF support for BFD.    Copyright 1998, 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|EF_INTERWORK
value|0x04
end_define

begin_define
define|#
directive|define
name|EF_APCS_26
value|0x08
end_define

begin_define
define|#
directive|define
name|EF_APCS_FLOAT
value|0x10
end_define

begin_define
define|#
directive|define
name|EF_PIC
value|0x20
end_define

begin_define
define|#
directive|define
name|EF_ALIGN8
value|0x40
end_define

begin_comment
comment|/* 8-bit structure alignment is in use.  */
end_comment

begin_define
define|#
directive|define
name|EF_NEW_ABI
value|0x80
end_define

begin_define
define|#
directive|define
name|EF_OLD_ABI
value|0x100
end_define

begin_define
define|#
directive|define
name|EF_SOFT_FLOAT
value|0x200
end_define

begin_comment
comment|/* Other constants defined in the ARM ELF spec. version A-08.  */
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
name|EF_ARM_EABIMASK
value|0xFF000000
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

begin_comment
comment|/* Local aliases for some flags to match names used by COFF port.  */
end_comment

begin_define
define|#
directive|define
name|F_INTERWORK
value|EF_INTERWORK
end_define

begin_define
define|#
directive|define
name|F_APCS26
value|EF_APCS_26
end_define

begin_define
define|#
directive|define
name|F_APCS_FLOAT
value|EF_APCS_FLOAT
end_define

begin_define
define|#
directive|define
name|F_PIC
value|EF_PIC
end_define

begin_define
define|#
directive|define
name|F_SOFT_FLOAT
value|EF_SOFT_FLOAT
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
comment|/* Relocation types.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_arm_reloc_type
argument_list|)
end_macro

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

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_ARM_ABI
end_ifdef

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_ABS8
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
argument|R_ARM_THM_PC22
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
argument|R_ARM_AMP_VCALL9
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC11
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* Cygnus extension to abi: Thumb unconditional branch.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC9
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* Cygnus extension to abi: Thumb conditional branch.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GNU_VTINHERIT
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GNU_VTENTRY
argument_list|,
literal|14
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not OLD_ARM_ABI */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_PC13
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
argument|R_ARM_THM_PC22
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
argument|R_ARM_AMP_VCALL9
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

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_SWI8
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_XPC25
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_XPC22
argument_list|,
literal|16
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not OLD_ARM_ABI */
end_comment

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
argument|R_ARM_GOTOFF
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
argument|R_ARM_GOTPC
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
argument|R_ARM_GOT32
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
comment|/* 32 bit PLT address.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_ARM_ABI
end_ifdef

begin_macro
name|FAKE_RELOC
argument_list|(
argument|FIRST_INVALID_RELOC
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|LAST_INVALID_RELOC
argument_list|,
literal|249
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not OLD_ARM_ABI */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|FIRST_INVALID_RELOC1
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|LAST_INVALID_RELOC1
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

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_GNU_VTINHERIT
argument_list|,
literal|101
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC11
argument_list|,
literal|102
argument_list|)
end_macro

begin_comment
comment|/* Cygnus extension to abi: Thumb unconditional branch.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_THM_PC9
argument_list|,
literal|103
argument_list|)
end_macro

begin_comment
comment|/* Cygnus extension to abi: Thumb conditional branch.  */
end_comment

begin_macro
name|FAKE_RELOC
argument_list|(
argument|FIRST_INVALID_RELOC2
argument_list|,
literal|104
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|LAST_INVALID_RELOC2
argument_list|,
literal|248
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARM_RXPC25
argument_list|,
literal|249
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not OLD_ARM_ABI */
end_comment

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

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_ARM_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_ARM_H */
end_comment

end_unit

