begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* picoJava ELF support for BFD.    Copyright 1999, 2000 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_PJ_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_PJ_H
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
argument|elf_pj_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_DATA_DIR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_REL32
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_REL16
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_DIR32
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_DIR16
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_LO16
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_CODE_HI16
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_GNU_VTINHERIT
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PJ_GNU_VTENTRY
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_PJ_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|EF_PICOJAVA_ARCH
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|EF_PICOJAVA_NEWCALLS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EF_PICOJAVA_GNUCALLS
value|0x00000020
end_define

begin_comment
comment|/* The (currently) non standard GNU calling convention */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

