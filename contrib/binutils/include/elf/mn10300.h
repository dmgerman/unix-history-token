begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MN10300 ELF support for BFD.    Copyright 1998, 1999, 2000, 2003 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the MN10300 ELF ABI. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_MN10300_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_MN10300_H
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
argument|elf_mn10300_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_8
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_PCREL32
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_PCREL16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_PCREL8
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GNU_VTINHERIT
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GNU_VTENTRY
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_24
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOTPC32
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOTPC16
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOTOFF32
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOTOFF24
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOTOFF16
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_PLT32
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_PLT16
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOT32
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOT24
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GOT16
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_COPY
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_GLOB_DAT
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_JMP_SLOT
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MN10300_RELATIVE
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MN10300_MAX
argument_list|)
end_macro

begin_comment
comment|/* Machine variant if we know it.  This field was invented at Cygnus,    but it is hoped that other vendors will adopt it.  If some standard    is developed, this code should be changed to follow it. */
end_comment

begin_define
define|#
directive|define
name|EF_MN10300_MACH
value|0x00FF0000
end_define

begin_comment
comment|/* Cygnus is choosing values between 80 and 9F;    00 - 7F should be left for a future standard;    the rest are open. */
end_comment

begin_define
define|#
directive|define
name|E_MN10300_MACH_MN10300
value|0x00810000
end_define

begin_define
define|#
directive|define
name|E_MN10300_MACH_AM33
value|0x00820000
end_define

begin_define
define|#
directive|define
name|E_MN10300_MACH_AM33_2
value|0x00830000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MN10300_H */
end_comment

end_unit

