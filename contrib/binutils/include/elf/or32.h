begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* OR1K ELF support for BFD. Derived from ppc.h.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Ivan Guzvinec<ivang@opencores.org>     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_OR1K_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_OR1K_H
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
argument|elf_or32_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_8
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_CONST
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_CONSTH
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_JUMPTARG
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_GNU_VTENTRY
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_OR32_GNU_VTINHERIT
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_OR32_max
argument_list|)
end_macro

begin_comment
comment|/* Four bit OR32 machine type field.  */
end_comment

begin_define
define|#
directive|define
name|EF_OR32_MACH
value|0x0000000f
end_define

begin_comment
comment|/* Various CPU types.  */
end_comment

begin_define
define|#
directive|define
name|E_OR32_MACH_BASE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|E_OR32_MACH_UNUSED1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|E_OR32_MACH_UNUSED2
value|0x00000002
end_define

begin_define
define|#
directive|define
name|E_OR32_MACH_UNUSED4
value|0x00000003
end_define

begin_comment
comment|/* Processor specific section headers, sh_type field */
end_comment

begin_define
define|#
directive|define
name|SHT_ORDERED
value|SHT_HIPROC
end_define

begin_comment
comment|/* Link editor is to sort the \ 						   entries in this section \ 						   based on the address \ 						   specified in the associated \ 						   symbol table entry.  */
end_comment

begin_comment
comment|/* Processor specific section flags, sh_flags field */
end_comment

begin_define
define|#
directive|define
name|SHF_EXCLUDE
value|0x80000000
end_define

begin_comment
comment|/* Link editor is to exclude \ 						   this section from executable \ 						   and shared objects that it \ 						   builds when those objects \ 						   are not to be furhter \ 						   relocated.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_OR1K_H */
end_comment

end_unit

