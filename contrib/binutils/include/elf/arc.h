begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ARC ELF support for BFD.    Copyright 1995, 1997, 1998, 2000, 2001 Free Software Foundation, Inc.    Contributed by Doug Evans, (dje@cygnus.com)  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the ARC ELF ABI.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_ARC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_ARC_H
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
argument|elf_arc_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARC_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARC_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARC_B26
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_ARC_B22_PCREL
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_ARC_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Four bit ARC machine type field.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARC_MACH
value|0x0000000f
end_define

begin_comment
comment|/* Various CPU types.  */
end_comment

begin_define
define|#
directive|define
name|E_ARC_MACH_ARC5
value|0
end_define

begin_define
define|#
directive|define
name|E_ARC_MACH_ARC6
value|1
end_define

begin_define
define|#
directive|define
name|E_ARC_MACH_ARC7
value|2
end_define

begin_define
define|#
directive|define
name|E_ARC_MACH_ARC8
value|3
end_define

begin_comment
comment|/* Leave bits 0xf0 alone in case we ever have more than 16 cpu types.  */
end_comment

begin_comment
comment|/* File contains position independent code.  */
end_comment

begin_define
define|#
directive|define
name|EF_ARC_PIC
value|0x00000100
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_ARC_H */
end_comment

end_unit

