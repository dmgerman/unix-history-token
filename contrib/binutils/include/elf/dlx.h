begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* DLX support for BFD.    Copyright 2002 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_DLX_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_DLX_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_if
if|#
directive|if
literal|0
end_if

begin_else
unit|START_RELOC_NUMBERS (elf_dlx_reloc_type)      RELOC_NUMBER (R_DLX_NONE,            0)      RELOC_NUMBER (R_DLX_RELOC_16,        1)      RELOC_NUMBER (R_DLX_RELOC_26,        2)      RELOC_NUMBER (R_DLX_RELOC_32,        3)      RELOC_NUMBER (R_DLX_GNU_VTINHERIT,   4)      RELOC_NUMBER (R_DLX_GNU_VTENTRY,     5)      RELOC_NUMBER (R_DLX_RELOC_16_HI,     6)      RELOC_NUMBER (R_DLX_RELOC_16_LO,     7)      RELOC_NUMBER (R_DLX_RELOC_16_PCREL,  8)      RELOC_NUMBER (R_DLX_RELOC_26_PCREL,  9) END_RELOC_NUMBERS (R_DLX_max)
else|#
directive|else
end_else

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_dlx_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_32
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_GNU_VTINHERIT
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_GNU_VTENTRY
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_16_HI
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_16_LO
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_16_PCREL
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_DLX_RELOC_26_PCREL
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_DLX_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_DLX_H */
end_comment

end_unit

