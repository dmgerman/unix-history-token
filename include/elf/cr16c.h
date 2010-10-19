begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CR16C ELF support for BFD.    Copyright 2004 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_CR16C_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_CR16C_H
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Creating indices for reloc_map_index array.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_cr16c_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM08
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM08_C
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM16_C
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM32
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_NUM32_C
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP04
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP04_C
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP08
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP08_C
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP16
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP16_C
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP24
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP24_C
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP24a
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_DISP24a_C
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG04
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG04_C
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG04a
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG04a_C
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG14
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG14_C
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG16
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG16_C
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG20
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_REG20_C
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_ABS20
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_ABS20_C
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_ABS24
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_ABS24_C
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM04
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM04_C
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM16
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM16_C
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM20
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM20_C
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM24
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM24_C
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM32
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|RINDEX_16C_IMM32_C
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|RINDEX_16C_MAX
argument_list|)
end_macro

begin_comment
comment|/* CR16C Relocation Types ('cr_reloc_type' entry in the reloc_map structure).    The relocation constant name is determined as follows :     R_16C_<format><size>[_C]     Where :<format> is one of the following: 	NUM  - R_NUMBER mnemonic, 	DISP - R_16C_DISPL mnemonic, 	REG  - R_16C_REGREL mnemonic, 	ABS  - R_16C_ABS mnemonic, 	IMM  - R_16C_IMMED mnemonic,<size> stands for R_S_16C_<size>       _C means 'code label' and is only added when R_ADDRTYPE subfield       is of type R_CODE_ADDR.  */
end_comment

begin_comment
comment|/* The table below shows what the hex digits in the definition of the    relocation type constants correspond to.    ------------------------------------------------------------------ 	R_SIZESP	R_FORMAT	R_RELTO	      R_ADDRTYPE    ------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*	R_S_16C_08	R_NUMBER 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM08
value|0X0001
end_define

begin_comment
comment|/*	R_S_16C_08	R_NUMBER 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM08_C
value|0X0006
end_define

begin_comment
comment|/*	R_S_16C_16	R_NUMBER 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM16
value|0X1001
end_define

begin_comment
comment|/*	R_S_16C_16	R_NUMBER 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM16_C
value|0X1006
end_define

begin_comment
comment|/*      R_S_16C_32      R_NUMBER	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM32
value|0X2001
end_define

begin_comment
comment|/*      R_S_16C_32      R_NUMBER	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_NUM32_C
value|0X2006
end_define

begin_comment
comment|/*	R_S_16C_04	R_16C_DISPL 	R_PCREL	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP04
value|0X5411
end_define

begin_comment
comment|/*	R_S_16C_04	R_16C_DISPL 	R_PCREL	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP04_C
value|0X5416
end_define

begin_comment
comment|/*	R_S_16C_08	R_16C_DISPL 	R_PCREL	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP08
value|0X0411
end_define

begin_comment
comment|/*	R_S_16C_08	R_16C_DISPL 	R_PCREL	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP08_C
value|0X0416
end_define

begin_comment
comment|/*	R_S_16C_16	R_16C_DISPL 	R_PCREL	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP16
value|0X1411
end_define

begin_comment
comment|/*	R_S_16C_16	R_16C_DISPL 	R_PCREL	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP16_C
value|0X1416
end_define

begin_comment
comment|/*	R_S_16C_24	R_16C_DISPL 	R_PCREL	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP24
value|0X7411
end_define

begin_comment
comment|/*	R_S_16C_24	R_16C_DISPL 	R_PCREL	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP24_C
value|0X7416
end_define

begin_comment
comment|/*	R_S_16C_24a	R_16C_DISPL 	R_PCREL	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP24a
value|0X6411
end_define

begin_comment
comment|/*	R_S_16C_24a	R_16C_DISPL 	R_PCREL	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISP24a_C
value|0X6416
end_define

begin_comment
comment|/*	R_S_16C_04	R_16C_REGREL 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG04
value|0X5201
end_define

begin_comment
comment|/*	R_S_16C_04	R_16C_REGREL 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG04_C
value|0X5206
end_define

begin_comment
comment|/*	R_S_16C_04_a	R_16C_REGREL 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG04a
value|0X4201
end_define

begin_comment
comment|/*	R_S_16C_04_a	R_16C_REGREL 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG04a_C
value|0X4206
end_define

begin_comment
comment|/*	R_S_16C_14	R_16C_REGREL 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG14
value|0X3201
end_define

begin_comment
comment|/*	R_S_16C_14	R_16C_REGREL 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG14_C
value|0X3206
end_define

begin_comment
comment|/*	R_S_16C_16	R_16C_REGREL 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG16
value|0X1201
end_define

begin_comment
comment|/*	R_S_16C_16	R_16C_REGREL 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG16_C
value|0X1206
end_define

begin_comment
comment|/*	R_S_16C_20	R_16C_REGREL 	R_ABS 	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG20
value|0X8201
end_define

begin_comment
comment|/*	R_S_16C_20	R_16C_REGREL 	R_ABS 	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_REG20_C
value|0X8206
end_define

begin_comment
comment|/*      R_S_16C_20      R_16C_ABS	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_ABS20
value|0X8101
end_define

begin_comment
comment|/*      R_S_16C_20      R_16C_ABS	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_ABS20_C
value|0X8106
end_define

begin_comment
comment|/*      R_S_16C_24      R_16C_ABS	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_ABS24
value|0X7101
end_define

begin_comment
comment|/*      R_S_16C_24      R_16C_ABS	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_ABS24_C
value|0X7106
end_define

begin_comment
comment|/*      R_S_16C_04      R_16C_IMMED	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM04
value|0X5301
end_define

begin_comment
comment|/*      R_S_16C_04      R_16C_IMMED	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM04_C
value|0X5306
end_define

begin_comment
comment|/*      R_S_16C_16      R_16C_IMMED	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM16
value|0X1301
end_define

begin_comment
comment|/*      R_S_16C_16      R_16C_IMMED	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM16_C
value|0X1306
end_define

begin_comment
comment|/*      R_S_16C_20      R_16C_IMMED	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM20
value|0X8301
end_define

begin_comment
comment|/*      R_S_16C_20      R_16C_IMMED	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM20_C
value|0X8306
end_define

begin_comment
comment|/*      R_S_16C_24      R_16C_IMMED	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM24
value|0X7301
end_define

begin_comment
comment|/*      R_S_16C_24      R_16C_IMMED	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM24_C
value|0X7306
end_define

begin_comment
comment|/*      R_S_16C_32      R_16C_IMMED	R_ABS	      R_ADDRESS */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM32
value|0X2301
end_define

begin_comment
comment|/*      R_S_16C_32      R_16C_IMMED	R_ABS	      R_CODE_ADDR */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMM32_C
value|0X2306
end_define

begin_comment
comment|/* Relocation item type.  */
end_comment

begin_define
define|#
directive|define
name|R_ADDRTYPE
value|0x000f
end_define

begin_define
define|#
directive|define
name|R_ADDRESS
value|0x0001
end_define

begin_comment
comment|/* Take address of symbol.  */
end_comment

begin_define
define|#
directive|define
name|R_CODE_ADDR
value|0x0006
end_define

begin_comment
comment|/* Take address of symbol divided by 2.  */
end_comment

begin_comment
comment|/* Relocation action.  */
end_comment

begin_define
define|#
directive|define
name|R_RELTO
value|0x00f0
end_define

begin_define
define|#
directive|define
name|R_ABS
value|0x0000
end_define

begin_comment
comment|/* Keep symbol's address as such.  */
end_comment

begin_define
define|#
directive|define
name|R_PCREL
value|0x0010
end_define

begin_comment
comment|/* Subtract the pc address of hole.  */
end_comment

begin_comment
comment|/* Relocation item data format.  */
end_comment

begin_define
define|#
directive|define
name|R_FORMAT
value|0x0f00
end_define

begin_define
define|#
directive|define
name|R_NUMBER
value|0x0000
end_define

begin_comment
comment|/* Retain as two's complement value.  */
end_comment

begin_define
define|#
directive|define
name|R_16C_DISPL
value|0x0400
end_define

begin_comment
comment|/* CR16C displacement type.  */
end_comment

begin_define
define|#
directive|define
name|R_16C_ABS
value|0x0100
end_define

begin_comment
comment|/* CR16C absolute type.  */
end_comment

begin_define
define|#
directive|define
name|R_16C_REGREL
value|0x0200
end_define

begin_comment
comment|/* CR16C register-relative type.  */
end_comment

begin_define
define|#
directive|define
name|R_16C_IMMED
value|0x0300
end_define

begin_comment
comment|/* CR16C immediate type.  */
end_comment

begin_comment
comment|/* Relocation item size. */
end_comment

begin_define
define|#
directive|define
name|R_SIZESP
value|0xf000
end_define

begin_define
define|#
directive|define
name|R_S_16C_04
value|0x5000
end_define

begin_define
define|#
directive|define
name|R_S_16C_04_a
value|0x4000
end_define

begin_define
define|#
directive|define
name|R_S_16C_08
value|0x0000
end_define

begin_define
define|#
directive|define
name|R_S_16C_14
value|0x3000
end_define

begin_define
define|#
directive|define
name|R_S_16C_16
value|0x1000
end_define

begin_define
define|#
directive|define
name|R_S_16C_20
value|0x8000
end_define

begin_define
define|#
directive|define
name|R_S_16C_24_a
value|0x6000
end_define

begin_define
define|#
directive|define
name|R_S_16C_24
value|0x7000
end_define

begin_define
define|#
directive|define
name|R_S_16C_32
value|0x2000
end_define

begin_comment
comment|/* Processor specific section indices.  These sections do not actually    exist.  Symbols with a st_shndx field corresponding to one of these    values have a special meaning.  */
end_comment

begin_comment
comment|/* Far common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_CR16C_FCOMMON
value|0xff00
end_define

begin_define
define|#
directive|define
name|SHN_CR16C_NCOMMON
value|0xff01
end_define

begin_typedef
typedef|typedef
struct|struct
name|reloc_map
block|{
name|unsigned
name|short
name|cr_reloc_type
decl_stmt|;
comment|/* CR relocation type.  */
name|bfd_reloc_code_real_type
name|bfd_reloc_enum
decl_stmt|;
comment|/* BFD relocation enum.  */
block|}
name|RELOC_MAP
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_CR16C_H */
end_comment

end_unit

