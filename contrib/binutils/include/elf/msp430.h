begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MSP430 ELF support for BFD.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Dmitry Diky<diwil@mail.ru>     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_MSP430_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_MSP430_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_MSP430_MACH
value|0xff
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x11
value|11
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x11x1
value|110
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x12
value|12
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x13
value|13
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x14
value|14
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x15
value|15
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x16
value|16
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x31
value|31
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x32
value|32
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x33
value|33
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x41
value|41
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x42
value|42
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x43
value|43
end_define

begin_define
define|#
directive|define
name|E_MSP430_MACH_MSP430x44
value|44
end_define

begin_comment
comment|/* Relocations.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_msp430_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_10_PCREL
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_16
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_16_PCREL
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_16_BYTE
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MSP430_16_PCREL_BYTE
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MSP430_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MSP430_H */
end_comment

end_unit

