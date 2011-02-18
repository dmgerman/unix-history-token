begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MS1  ELF support for BFD.    Copyright (C) 2000, 2005 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_MT_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_MT_H
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
argument|elf_mt_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_16
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_32_PCREL
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_PC16
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_HI16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MT_LO16
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MT_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EF_MT_CPU_MRISC
value|0x00000001
end_define

begin_comment
comment|/* default */
end_comment

begin_define
define|#
directive|define
name|EF_MT_CPU_MRISC2
value|0x00000002
end_define

begin_comment
comment|/* MRISC2 */
end_comment

begin_define
define|#
directive|define
name|EF_MT_CPU_MS2
value|0x00000003
end_define

begin_comment
comment|/* MS2 */
end_comment

begin_define
define|#
directive|define
name|EF_MT_CPU_MASK
value|0x00000003
end_define

begin_comment
comment|/* specific cpu bits */
end_comment

begin_define
define|#
directive|define
name|EF_MT_ALL_FLAGS
value|(EF_MT_CPU_MASK)
end_define

begin_comment
comment|/* The location of the memory mapped hardware stack.  */
end_comment

begin_define
define|#
directive|define
name|MT_STACK_VALUE
value|0x0f000000
end_define

begin_define
define|#
directive|define
name|MT_STACK_SIZE
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MT_H */
end_comment

end_unit

