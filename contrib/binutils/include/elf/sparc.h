begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SPARC ELF support for BFD.    Copyright 1996, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.    By Doug Evans, Cygnus Support,<dje@cygnus.com>.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SPARC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SPARC_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* These are defined by Sun.  */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_32PLUS_MASK
value|0xffff00
end_define

begin_comment
comment|/* bits indicating V8+ type */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_32PLUS
value|0x000100
end_define

begin_comment
comment|/* generic V8+ features */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_SUN_US1
value|0x000200
end_define

begin_comment
comment|/* Sun UltraSPARC1 extensions */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_HAL_R1
value|0x000400
end_define

begin_comment
comment|/* HAL R1 extensions */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_SUN_US3
value|0x000800
end_define

begin_comment
comment|/* Sun UltraSPARCIII extensions */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_LEDATA
value|0x800000
end_define

begin_comment
comment|/* little endian data */
end_comment

begin_comment
comment|/* This name is used in the V9 ABI.  */
end_comment

begin_define
define|#
directive|define
name|EF_SPARC_EXT_MASK
value|0xffff00
end_define

begin_comment
comment|/* reserved for vendor extensions */
end_comment

begin_comment
comment|/* V9 memory models */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_MM
value|0x3
end_define

begin_comment
comment|/* memory model mask */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_TSO
value|0x0
end_define

begin_comment
comment|/* total store ordering */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_PSO
value|0x1
end_define

begin_comment
comment|/* partial store ordering */
end_comment

begin_define
define|#
directive|define
name|EF_SPARCV9_RMO
value|0x2
end_define

begin_comment
comment|/* relaxed store ordering */
end_comment

begin_comment
comment|/* Section indices.  */
end_comment

begin_define
define|#
directive|define
name|SHN_BEFORE
value|0xff00
end_define

begin_comment
comment|/* used with SHF_ORDERED */
end_comment

begin_define
define|#
directive|define
name|SHN_AFTER
value|0xff01
end_define

begin_comment
comment|/* used with SHF_ORDERED */
end_comment

begin_comment
comment|/* Section flags.  */
end_comment

begin_define
define|#
directive|define
name|SHF_EXCLUDE
value|0x80000000
end_define

begin_comment
comment|/* exclude from linking */
end_comment

begin_define
define|#
directive|define
name|SHF_ORDERED
value|0x40000000
end_define

begin_comment
comment|/* treat sh_link,sh_info specially */
end_comment

begin_comment
comment|/* Symbol types.  */
end_comment

begin_define
define|#
directive|define
name|STT_REGISTER
value|13
end_define

begin_comment
comment|/* global reg reserved to app. */
end_comment

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
argument|elf_sparc_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_DISP8
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_DISP16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_DISP32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_WDISP30
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_WDISP22
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_HI22
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_22
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_13
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_LO10
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GOT10
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GOT13
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GOT22
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PC10
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PC22
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_WPLT30
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_COPY
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GLOB_DAT
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_JMP_SLOT
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_RELATIVE
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_UA32
argument_list|,
literal|23
argument_list|)
end_macro

begin_comment
comment|/* ??? These 6 relocs are new but not currently used.  For binary      compatibility in the sparc64-elf toolchain, we leave them out.      A non-binary upward compatible change is expected for sparc64-elf.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SPARC64_OLD_RELOCS
end_ifndef

begin_comment
comment|/* ??? New relocs on the UltraSPARC.  Not sure what they're for yet.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PLT32
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_HIPLT22
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_LOPLT10
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PCPLT32
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PCPLT22
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PCPLT10
argument_list|,
literal|29
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* v9 relocs */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_10
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_11
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_64
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_OLO10
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_HH22
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_HM10
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_LM22
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PC_HH22
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PC_HM10
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PC_LM22
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_WDISP16
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_WDISP19
argument_list|,
literal|41
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_UNUSED_42
argument_list|,
literal|42
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_7
argument_list|,
literal|43
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_5
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_6
argument_list|,
literal|45
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_DISP64
argument_list|,
literal|46
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_PLT64
argument_list|,
literal|47
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_HIX22
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_LOX10
argument_list|,
literal|49
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_H44
argument_list|,
literal|50
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_M44
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_L44
argument_list|,
literal|52
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_REGISTER
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_UA64
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_UA16
argument_list|,
literal|55
argument_list|)
end_macro

begin_comment
comment|/* little endian data relocs */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_REV32
argument_list|,
literal|56
argument_list|)
end_macro

begin_macro
name|EMPTY_RELOC
argument_list|(
argument|R_SPARC_max_std
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GNU_VTINHERIT
argument_list|,
literal|250
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SPARC_GNU_VTENTRY
argument_list|,
literal|251
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_SPARC_max
argument_list|)
end_macro

begin_comment
comment|/* Relocation macros.  */
end_comment

begin_define
define|#
directive|define
name|ELF64_R_TYPE_DATA
parameter_list|(
name|info
parameter_list|)
define|\
value|(((bfd_signed_vma)(ELF64_R_TYPE(info)>> 8) ^ 0x800000) - 0x800000)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_ID
parameter_list|(
name|info
parameter_list|)
define|\
value|((info)& 0xff)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE_INFO
parameter_list|(
name|data
parameter_list|,
name|type
parameter_list|)
define|\
value|(((bfd_vma) ((data)& 0xffffff)<< 8) | (bfd_vma) (type))
end_define

begin_comment
comment|/* Values for Elf64_Dyn.d_tag.  */
end_comment

begin_define
define|#
directive|define
name|DT_SPARC_REGISTER
value|0x70000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_SPARC_H */
end_comment

end_unit

