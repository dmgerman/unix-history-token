begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* V850 ELF support for BFD.    Copyright 1997, 1998, 2000 Free Software Foundation, Inc.    Created by Michael Meissner, Cygnus Support<meissner@cygnus.com>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the MIPS ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_V850_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_V850_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Four bit V850 architecture field.  */
end_comment

begin_define
define|#
directive|define
name|EF_V850_ARCH
value|0xf0000000
end_define

begin_comment
comment|/* v850 code.  */
end_comment

begin_define
define|#
directive|define
name|E_V850_ARCH
value|0x00000000
end_define

begin_comment
comment|/* v850e code.  */
end_comment

begin_define
define|#
directive|define
name|E_V850E_ARCH
value|0x10000000
end_define

begin_comment
comment|/* v850ea code.  */
end_comment

begin_define
define|#
directive|define
name|E_V850EA_ARCH
value|0x20000000
end_define

begin_comment
comment|/* Flags for the st_other field */
end_comment

begin_define
define|#
directive|define
name|V850_OTHER_SDA
value|0x01
end_define

begin_comment
comment|/* symbol had SDA relocations */
end_comment

begin_define
define|#
directive|define
name|V850_OTHER_ZDA
value|0x02
end_define

begin_comment
comment|/* symbol had ZDA relocations */
end_comment

begin_define
define|#
directive|define
name|V850_OTHER_TDA
value|0x04
end_define

begin_comment
comment|/* symbol had TDA relocations */
end_comment

begin_define
define|#
directive|define
name|V850_OTHER_TDA_BYTE
value|0x08
end_define

begin_comment
comment|/* symbol had TDA byte relocations */
end_comment

begin_define
define|#
directive|define
name|V850_OTHER_ERROR
value|0x80
end_define

begin_comment
comment|/* symbol had an error reported */
end_comment

begin_comment
comment|/* V850 relocations */
end_comment

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|v850_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_9_PCREL
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_22_PCREL
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_HI16_S
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_HI16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_LO16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_16
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_8
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_SDA_16_16_OFFSET
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* For ld.b, st.b, set1, clr1, not1, tst1, movea, movhi */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_SDA_15_16_OFFSET
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* For ld.w, ld.h, ld.hu, st.w, st.h */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_ZDA_16_16_OFFSET
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* For ld.b, st.b, set1, clr1, not1, tst1, movea, movhi */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_ZDA_15_16_OFFSET
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* For ld.w, ld.h, ld.hu, st.w, st.h */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_6_8_OFFSET
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* For sst.w, sld.w */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_7_8_OFFSET
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* For sst.h, sld.h */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_7_7_OFFSET
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* For sst.b, sld.b */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_16_16_OFFSET
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* For set1, clr1, not1, tst1, movea, movhi */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_4_5_OFFSET
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* For sld.hu */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_TDA_4_4_OFFSET
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* For sld.bu */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_SDA_16_16_SPLIT_OFFSET
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* For ld.bu */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_ZDA_16_16_SPLIT_OFFSET
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* For ld.bu */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_CALLT_6_7_OFFSET
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* For callt */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_CALLT_16_16_OFFSET
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* For callt */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_GNU_VTINHERIT
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_V850_GNU_VTENTRY
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_V850_max
argument_list|)
end_macro

begin_escape
end_escape

begin_comment
comment|/* Processor specific section indices.  These sections do not actually    exist.  Symbols with a st_shndx field corresponding to one of these    values have a special meaning.  */
end_comment

begin_comment
comment|/* Small data area common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_V850_SCOMMON
value|0xff00
end_define

begin_comment
comment|/* Tiny data area common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_V850_TCOMMON
value|0xff01
end_define

begin_comment
comment|/* Zero data area common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_V850_ZCOMMON
value|0xff02
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_comment
comment|/* Section contains the .scommon data.  */
end_comment

begin_define
define|#
directive|define
name|SHT_V850_SCOMMON
value|0x70000000
end_define

begin_comment
comment|/* Section contains the .scommon data.  */
end_comment

begin_define
define|#
directive|define
name|SHT_V850_TCOMMON
value|0x70000001
end_define

begin_comment
comment|/* Section contains the .scommon data.  */
end_comment

begin_define
define|#
directive|define
name|SHT_V850_ZCOMMON
value|0x70000002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_V850_H */
end_comment

end_unit

