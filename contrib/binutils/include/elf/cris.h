begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* CRIS ELF support for BFD.    Copyright 2000, 2001 Free Software Foundation, Inc.    Contributed by Axis Communications AB, Lund, Sweden.    Written by Hans-Peter Nilsson.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_CRIS_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_CRIS_H
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
argument|elf_cris_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_8_PCREL
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_16_PCREL
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_32_PCREL
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_GNU_VTINHERIT
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_CRIS_GNU_VTENTRY
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* No other relocs must be visible outside the assembler.  */
end_comment

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_CRIS_max
argument_list|)
end_macro

begin_comment
comment|/* User symbols in this file have a leading underscore.  */
end_comment

begin_define
define|#
directive|define
name|EF_CRIS_UNDERSCORE
value|0x00000001
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_CRIS_H */
end_comment

end_unit

