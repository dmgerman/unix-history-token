begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 390 ELF support for BFD.    Copyright 2000, 2001 Free Software Foundation, Inc.    Contributed by Carl B. Pedersen and Martin Schwidefsky.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_390_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_390_H
end_define

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* Symbol types.  */
end_comment

begin_define
define|#
directive|define
name|STACK_REG
value|15
end_define

begin_comment
comment|/* Global Stack reg */
end_comment

begin_define
define|#
directive|define
name|BACKL_REG
value|14
end_define

begin_comment
comment|/* Global Backlink reg */
end_comment

begin_define
define|#
directive|define
name|BASE_REG
value|13
end_define

begin_comment
comment|/* Global Base reg */
end_comment

begin_define
define|#
directive|define
name|GOT_REG
value|12
end_define

begin_comment
comment|/* Holds addr of GOT */
end_comment

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
argument|elf_s390_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* No reloc.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_comment
comment|/* Direct 8 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_12
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* Direct 12 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_16
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* Direct 16 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_32
argument_list|,
literal|4
argument_list|)
end_macro

begin_comment
comment|/* Direct 32 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PC32
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* PC relative 32 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOT12
argument_list|,
literal|6
argument_list|)
end_macro

begin_comment
comment|/* 12 bit GOT offset.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOT32
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* 32 bit GOT offset.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PLT32
argument_list|,
literal|8
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative PLT address.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_COPY
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* Copy symbol at runtime.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GLOB_DAT
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* Create GOT entry.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_JMP_SLOT
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* Create PLT entry.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_RELATIVE
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* Adjust by program base.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOTOFF
argument_list|,
literal|13
argument_list|)
end_macro

begin_comment
comment|/* 32 bit offset to GOT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOTPC
argument_list|,
literal|14
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC relative offset to GOT.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOT16
argument_list|,
literal|15
argument_list|)
end_macro

begin_comment
comment|/* 16 bit GOT offset.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PC16
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* PC relative 16 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PC16DBL
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* PC relative 16 bit shifted by 1.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PLT16DBL
argument_list|,
literal|18
argument_list|)
end_macro

begin_comment
comment|/* 16 bit PC rel. PLT shifted by 1.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PC32DBL
argument_list|,
literal|19
argument_list|)
end_macro

begin_comment
comment|/* PC relative 32 bit shifted by 1.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PLT32DBL
argument_list|,
literal|20
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC rel. PLT shifted by 1.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOTPCDBL
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC rel. GOT shifted by 1.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_64
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* Direct 64 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PC64
argument_list|,
literal|23
argument_list|)
end_macro

begin_comment
comment|/* PC relative 64 bit.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOT64
argument_list|,
literal|24
argument_list|)
end_macro

begin_comment
comment|/* 64 bit GOT offset.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_PLT64
argument_list|,
literal|25
argument_list|)
end_macro

begin_comment
comment|/* 64 bit PC relative PLT address.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GOTENT
argument_list|,
literal|26
argument_list|)
end_macro

begin_comment
comment|/* 32 bit PC rel. to GOT entry>> 1. */
end_comment

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GNU_VTINHERIT
argument_list|,
literal|250
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_390_GNU_VTENTRY
argument_list|,
literal|251
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_390_max
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_390_H */
end_comment

end_unit

