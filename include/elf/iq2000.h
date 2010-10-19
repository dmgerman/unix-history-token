begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* IQ2000 ELF support for BFD.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_IQ2000_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_IQ2000_H
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
argument|elf_iq2000_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_16
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_26
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_PC16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_HI16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_LO16
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_OFFSET_16
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_OFFSET_21
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_UHI16
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_32_DEBUG
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_GNU_VTINHERIT
argument_list|,
literal|200
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_IQ2000_GNU_VTENTRY
argument_list|,
literal|201
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_IQ2000_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EF_IQ2000_CPU_IQ2000
value|0x00000001
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|EF_IQ2000_CPU_IQ10
value|0x00000002
end_define

begin_comment
comment|/* IQ10 */
end_comment

begin_define
define|#
directive|define
name|EF_IQ2000_CPU_MASK
value|0x00000003
end_define

begin_comment
comment|/* specific cpu bits */
end_comment

begin_define
define|#
directive|define
name|EF_IQ2000_ALL_FLAGS
value|(EF_IQ2000_CPU_MASK)
end_define

begin_comment
comment|/* Define the data& instruction memory discriminator.  In a linked    executable, an symbol should be deemed to point to an instruction    if ((address& IQ2000_INSN_MASK) == IQ2000_INSN_VALUE), and similarly    for the data space.  */
end_comment

begin_define
define|#
directive|define
name|IQ2000_DATA_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IQ2000_DATA_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IQ2000_INSN_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IQ2000_INSN_VALUE
value|0x80000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_IQ2000_H */
end_comment

end_unit

