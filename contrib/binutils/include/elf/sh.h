begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* SH ELF support for BFD.    Copyright 1998, 2000 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_SH_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_SH_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_SH_MACH_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|EF_SH_UNKNOWN
value|0
end_define

begin_comment
comment|/* For backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|EF_SH1
value|1
end_define

begin_define
define|#
directive|define
name|EF_SH2
value|2
end_define

begin_define
define|#
directive|define
name|EF_SH3
value|3
end_define

begin_define
define|#
directive|define
name|EF_SH_HAS_DSP
parameter_list|(
name|flags
parameter_list|)
value|((flags)& 4)
end_define

begin_define
define|#
directive|define
name|EF_SH_DSP
value|4
end_define

begin_define
define|#
directive|define
name|EF_SH3_DSP
value|5
end_define

begin_define
define|#
directive|define
name|EF_SH_HAS_FP
parameter_list|(
name|flags
parameter_list|)
value|((flags)& 8)
end_define

begin_define
define|#
directive|define
name|EF_SH3E
value|8
end_define

begin_define
define|#
directive|define
name|EF_SH4
value|9
end_define

begin_define
define|#
directive|define
name|EF_SH_MERGE_MACH
parameter_list|(
name|mach1
parameter_list|,
name|mach2
parameter_list|)
define|\
value|(((((mach1) == EF_SH3 || (mach1) == EF_SH_UNKNOWN)&& (mach2) == EF_SH_DSP) \     || ((mach1) == EF_SH_DSP \&& ((mach2) == EF_SH3 || (mach2) == EF_SH_UNKNOWN))) \    ? EF_SH3_DSP \    : (((mach1)< EF_SH3&& (mach2) == EF_SH_UNKNOWN) \       || ((mach2)< EF_SH3&& (mach1) == EF_SH_UNKNOWN)) \    ? EF_SH3 \    : (((mach1) == EF_SH3E&& (mach2) == EF_SH_UNKNOWN) \       || ((mach2) == EF_SH3E&& (mach1) == EF_SH_UNKNOWN)) \    ? EF_SH4 \    : ((mach1)> (mach2) ? (mach1) : (mach2)))
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocations.  */
end_comment

begin_comment
comment|/* Relocations 25ff are GNU extensions.    25..33 are used for relaxation and use the same constants as COFF uses.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_sh_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_REL32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPN
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_IND12W
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPL
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8WPZ
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8BP
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8W
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DIR8L
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH16
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH32
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_USES
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_COUNT
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_ALIGN
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_CODE
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_DATA
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LABEL
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_SWITCH8
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GNU_VTINHERIT
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GNU_VTENTRY
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LOOP_START
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_LOOP_END
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_FIRST_INVALID_RELOC_2
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_SH_LAST_INVALID_RELOC_2
argument_list|,
literal|159
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOT32
argument_list|,
literal|160
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_PLT32
argument_list|,
literal|161
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_COPY
argument_list|,
literal|162
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GLOB_DAT
argument_list|,
literal|163
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_JMP_SLOT
argument_list|,
literal|164
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_RELATIVE
argument_list|,
literal|165
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTOFF
argument_list|,
literal|166
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_SH_GOTPC
argument_list|,
literal|167
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_SH_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

end_unit

