begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* H8300/h8500 ELF support for BFD.    Copyright 2001 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_H8_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_H8_H
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
comment|/* Relocations 59..63 are GNU extensions.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_h8_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32_28
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32_24
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32_16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32U
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32U_28
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32U_24
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32U_20
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32U_16
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24_20
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24_16
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24U
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24U_20
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24U_16
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16U
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16S_32
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16S_28
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16S_24
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16S_20
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16S
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8U
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8Z_32
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8Z_28
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8Z_24
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8Z_20
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR8Z_16
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_PCREL16
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_PCREL8
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_BPOS
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_H8_FIRST_INVALID_DIR_RELOC
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|FAKE_RELOC
argument_list|(
argument|R_H8_LAST_INVALID_DIR_RELOC
argument_list|,
literal|58
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16A8
argument_list|,
literal|59
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR16R8
argument_list|,
literal|60
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24A8
argument_list|,
literal|61
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR24R8
argument_list|,
literal|62
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_DIR32A16
argument_list|,
literal|63
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_ABS32
argument_list|,
literal|65
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_ABS32A16
argument_list|,
literal|127
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_SYM
argument_list|,
literal|128
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPneg
argument_list|,
literal|129
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPadd
argument_list|,
literal|130
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPsub
argument_list|,
literal|131
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPmul
argument_list|,
literal|132
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPdiv
argument_list|,
literal|133
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPshla
argument_list|,
literal|134
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPshra
argument_list|,
literal|135
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPsctsize
argument_list|,
literal|136
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPhword
argument_list|,
literal|137
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPlword
argument_list|,
literal|138
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPhigh
argument_list|,
literal|139
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPlow
argument_list|,
literal|140
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_H8_OPscttop
argument_list|,
literal|141
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_H8_max
argument_list|)
end_macro

begin_comment
comment|/* Machine variant if we know it.  This field was invented at Cygnus,    but it is hoped that other vendors will adopt it.  If some standard    is developed, this code should be changed to follow it. */
end_comment

begin_define
define|#
directive|define
name|EF_H8_MACH
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|E_H8_MACH_H8300
value|0x00800000
end_define

begin_define
define|#
directive|define
name|E_H8_MACH_H8300H
value|0x00810000
end_define

begin_define
define|#
directive|define
name|E_H8_MACH_H8300S
value|0x00820000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

