begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* M32C ELF support for BFD.    Copyright (C) 2004 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_M32C_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_M32C_H
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
argument|elf_m32c_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_16
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_24
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_8_PCREL
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_16_PCREL
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* 8 bit unsigned address, used for dsp8[a0] etc */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_8
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* Bits 0..15 of an address, for SMOVF's A0, A1A0, etc. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_LO16
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* Bits 16..23 of an address, for SMOVF's R1H etc. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_HI8
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* Bits 16..31 of an address, for LDE's A1A0 etc. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_HI16
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* These are relocs we need when relaxing.  */
end_comment

begin_comment
comment|/* Marks various jump opcodes.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_RL_JUMP
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* Marks standard one-address form.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_RL_1ADDR
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* Marks standard two-address form.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M32C_RL_2ADDR
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_M32C_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EF_M32C_CPU_M16C
value|0x00000075
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|EF_M32C_CPU_M32C
value|0x00000078
end_define

begin_comment
comment|/* m32c */
end_comment

begin_define
define|#
directive|define
name|EF_M32C_CPU_MASK
value|0x0000007F
end_define

begin_comment
comment|/* specific cpu bits */
end_comment

begin_define
define|#
directive|define
name|EF_M32C_ALL_FLAGS
value|(EF_M32C_CPU_MASK)
end_define

begin_comment
comment|/* Define the data& instruction memory discriminator.  In a linked    executable, an symbol should be deemed to point to an instruction    if ((address& M16C_INSN_MASK) == M16C_INSN_VALUE), and similarly    for the data space.  See also `ld/emulparams/elf32m32c.sh'.  */
end_comment

begin_define
define|#
directive|define
name|M32C_DATA_MASK
value|0xffc00000
end_define

begin_define
define|#
directive|define
name|M32C_DATA_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|M32C_INSN_MASK
value|0xffc00000
end_define

begin_define
define|#
directive|define
name|M32C_INSN_VALUE
value|0x00400000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_M32C_H */
end_comment

end_unit

