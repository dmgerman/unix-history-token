begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Blackfin ELF support for BFD.    Copyright (C) 2005 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_BFIN_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_BFIN_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_bfin_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_unused0
argument_list|,
literal|0x00
argument_list|)
end_macro

begin_comment
comment|/* relocation type 0 is not defined*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel5m2
argument_list|,
literal|0x01
argument_list|)
end_macro

begin_comment
comment|/*LSETUP part a*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_unused1
argument_list|,
literal|0x02
argument_list|)
end_macro

begin_comment
comment|/* relocation type 2 is not defined*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel10
argument_list|,
literal|0x03
argument_list|)
end_macro

begin_comment
comment|/* type 3, 0x00) if cc jump<target>  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel12_jump
argument_list|,
literal|0x04
argument_list|)
end_macro

begin_comment
comment|/* type 4, 0x00) jump<target> */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_rimm16
argument_list|,
literal|0x05
argument_list|)
end_macro

begin_comment
comment|/* type 0x5, 0x00) rN =<target> */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_luimm16
argument_list|,
literal|0x06
argument_list|)
end_macro

begin_comment
comment|/* # 0x6, 0x00) preg.l=<target> Load imm 16 to lower half */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_huimm16
argument_list|,
literal|0x07
argument_list|)
end_macro

begin_comment
comment|/* # 0x7, 0x00) preg.h=<target> Load imm 16 to upper half*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel12_jump_s
argument_list|,
literal|0x08
argument_list|)
end_macro

begin_comment
comment|/* # 0x8 jump.s<target> */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel24_jump_x
argument_list|,
literal|0x09
argument_list|)
end_macro

begin_comment
comment|/* # 0x9 jump.x<target> */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel24
argument_list|,
literal|0x0a
argument_list|)
end_macro

begin_comment
comment|/* # 0xa call<target> , 0x00) not expandable*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_unusedb
argument_list|,
literal|0x0b
argument_list|)
end_macro

begin_comment
comment|/* # 0xb not generated */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_unusedc
argument_list|,
literal|0x0c
argument_list|)
end_macro

begin_comment
comment|/* # 0xc  not used */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel24_jump_l
argument_list|,
literal|0x0d
argument_list|)
end_macro

begin_comment
comment|/*0xd jump.l<target>*/
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel24_call_x
argument_list|,
literal|0x0e
argument_list|)
end_macro

begin_comment
comment|/* 0xE, 0x00) call.x<target> if<target> is above 24 bit limit call through P1 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_var_eq_symb
argument_list|,
literal|0x0f
argument_list|)
end_macro

begin_comment
comment|/* 0xf, 0x00) linker should treat it same as 0x12 */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_byte_data
argument_list|,
literal|0x10
argument_list|)
end_macro

begin_comment
comment|/* 0x10, 0x00) .byte var = symbol */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_byte2_data
argument_list|,
literal|0x11
argument_list|)
end_macro

begin_comment
comment|/* 0x11, 0x00) .byte2 var = symbol */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_byte4_data
argument_list|,
literal|0x12
argument_list|)
end_macro

begin_comment
comment|/* 0x12, 0x00) .byte4 var = symbol and .var var=symbol */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pcrel11
argument_list|,
literal|0x13
argument_list|)
end_macro

begin_comment
comment|/* 0x13, 0x00) lsetup part b */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOT17M4
argument_list|,
literal|0x14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOTHI
argument_list|,
literal|0x15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOTLO
argument_list|,
literal|0x16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC
argument_list|,
literal|0x17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOT17M4
argument_list|,
literal|0x18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOTHI
argument_list|,
literal|0x19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOTLO
argument_list|,
literal|0x1a
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_VALUE
argument_list|,
literal|0x1b
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOTOFF17M4
argument_list|,
literal|0x1c
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOTOFFHI
argument_list|,
literal|0x1d
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_FUNCDESC_GOTOFFLO
argument_list|,
literal|0x1e
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOTOFF17M4
argument_list|,
literal|0x1f
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOTOFFHI
argument_list|,
literal|0x20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GOTOFFLO
argument_list|,
literal|0x21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_push
argument_list|,
literal|0xE0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_const
argument_list|,
literal|0xE1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_add
argument_list|,
literal|0xE2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_sub
argument_list|,
literal|0xE3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_mult
argument_list|,
literal|0xE4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_div
argument_list|,
literal|0xE5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_mod
argument_list|,
literal|0xE6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_lshift
argument_list|,
literal|0xE7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_rshift
argument_list|,
literal|0xE8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_and
argument_list|,
literal|0xE9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_or
argument_list|,
literal|0xEA
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_xor
argument_list|,
literal|0xEB
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_land
argument_list|,
literal|0xEC
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_lor
argument_list|,
literal|0xED
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_len
argument_list|,
literal|0xEE
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_neg
argument_list|,
literal|0xEF
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_comp
argument_list|,
literal|0xF0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_page
argument_list|,
literal|0xF1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_hwpage
argument_list|,
literal|0xF2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_addr
argument_list|,
literal|0xF3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_pltpc
argument_list|,
literal|0x40
argument_list|)
end_macro

begin_comment
comment|/* PLT gnu only relocation */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_got
argument_list|,
literal|0x41
argument_list|)
end_macro

begin_comment
comment|/* GOT gnu only relocation */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GNU_VTINHERIT
argument_list|,
literal|0x42
argument_list|)
end_macro

begin_comment
comment|/* C++, gnu only */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_BFIN_GNU_VTENTRY
argument_list|,
literal|0x43
argument_list|)
end_macro

begin_comment
comment|/* C++, gnu only */
end_comment

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_BFIN_PIC
value|0x00000001
end_define

begin_comment
comment|/* -fpic */
end_comment

begin_define
define|#
directive|define
name|EF_BFIN_FDPIC
value|0x00000002
end_define

begin_comment
comment|/* -mfdpic */
end_comment

begin_define
define|#
directive|define
name|EF_BFIN_PIC_FLAGS
value|(EF_BFIN_PIC | EF_BFIN_FDPIC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_BFIN_H */
end_comment

end_unit

