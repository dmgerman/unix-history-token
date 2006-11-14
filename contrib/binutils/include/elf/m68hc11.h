begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m68hc11& m68hc12 ELF support for BFD.    Copyright 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_M68HC11_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_M68HC11_H
end_define

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
argument|elf_m68hc11_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_HI8
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_LO8
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_PCREL_8
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_3B
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_PCREL_16
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_GNU_VTINHERIT
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_GNU_VTENTRY
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_24
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_LO16
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_PAGE
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* GNU extension for linker relaxation.         Mark beginning of a jump instruction (any form).  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_RL_JUMP
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* Mark beginning of Gcc relaxation group instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_M68HC11_RL_GROUP
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_M68HC11_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* ABI identification.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68HC11_ABI
value|0x00000000F
end_define

begin_comment
comment|/* Integers are 32-bit long.  */
end_comment

begin_define
define|#
directive|define
name|E_M68HC11_I32
value|0x000000001
end_define

begin_comment
comment|/* Doubles are 64-bit long.  */
end_comment

begin_define
define|#
directive|define
name|E_M68HC11_F64
value|0x000000002
end_define

begin_comment
comment|/* Uses 68HC12 memory banks.  */
end_comment

begin_define
define|#
directive|define
name|E_M68HC12_BANKS
value|0x000000004
end_define

begin_define
define|#
directive|define
name|EF_M68HC11_MACH_MASK
value|0xF0
end_define

begin_define
define|#
directive|define
name|EF_M68HC11_GENERIC
value|0x00
end_define

begin_comment
comment|/* Generic 68HC12/backward compatibility.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68HC12_MACH
value|0x10
end_define

begin_comment
comment|/* 68HC12 microcontroller.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68HCS12_MACH
value|0x20
end_define

begin_comment
comment|/* 68HCS12 microcontroller.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68HC11_MACH
parameter_list|(
name|mach
parameter_list|)
value|((mach)& EF_M68HC11_MACH_MASK)
end_define

begin_comment
comment|/* True if we can merge machines.  A generic HC12 can work on any proc    but once we have specific code, merge is not possible.  */
end_comment

begin_define
define|#
directive|define
name|EF_M68HC11_CAN_MERGE_MACH
parameter_list|(
name|mach1
parameter_list|,
name|mach2
parameter_list|)
define|\
value|((EF_M68HC11_MACH (mach1) == EF_M68HC11_MACH (mach2)) \    || (EF_M68HC11_MACH (mach1) == EF_M68HC11_GENERIC) \    || (EF_M68HC11_MACH (mach2) == EF_M68HC11_GENERIC))
end_define

begin_define
define|#
directive|define
name|EF_M68HC11_MERGE_MACH
parameter_list|(
name|mach1
parameter_list|,
name|mach2
parameter_list|)
define|\
value|(((EF_M68HC11_MACH (mach1) == EF_M68HC11_MACH (mach2)) \     || (EF_M68HC11_MACH (mach1) == EF_M68HC11_GENERIC)) ? \       EF_M68HC11_MACH (mach2) : EF_M68HC11_MACH (mach1))
end_define

begin_escape
end_escape

begin_comment
comment|/* Special values for the st_other field in the symbol table.  These    are used for 68HC12 to identify far functions (must be called with    'call' and returns with 'rtc').  */
end_comment

begin_define
define|#
directive|define
name|STO_M68HC12_FAR
value|0x80
end_define

begin_comment
comment|/* Identify interrupt handlers.  This is used by the debugger to    correctly compute the stack frame.  */
end_comment

begin_define
define|#
directive|define
name|STO_M68HC12_INTERRUPT
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

