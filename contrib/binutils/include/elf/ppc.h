begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PPC ELF support for BFD.    Copyright 1995, 1996, 1998, 2000 Free Software Foundation, Inc.     By Michael Meissner, Cygnus Support,<meissner@cygnus.com>, from information    in the System V Application Binary Interface, PowerPC Processor Supplement    and the PowerPC Embedded Application Binary Interface (eabi).  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the PPC ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_PPC_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_PPC_H
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
argument|elf_ppc_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR24
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR16
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR16_LO
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR16_HI
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR16_HA
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR14
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR14_BRTAKEN
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_ADDR14_BRNTAKEN
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_REL24
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_REL14
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_REL14_BRTAKEN
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_REL14_BRNTAKEN
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GOT16
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GOT16_LO
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GOT16_HI
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GOT16_HA
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLTREL24
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_COPY
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GLOB_DAT
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_JMP_SLOT
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_RELATIVE
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_LOCAL24PC
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_UADDR32
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_UADDR16
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_REL32
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLT32
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLTREL32
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLT16_LO
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLT16_HI
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_PLT16_HA
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_SDAREL16
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_SECTOFF
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_SECTOFF_LO
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_SECTOFF_HI
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_SECTOFF_HA
argument_list|,
literal|36
argument_list|)
end_macro

begin_comment
comment|/* The remaining relocs are from the Embedded ELF ABI, and are not    in the SVR4 ELF ABI.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_NADDR32
argument_list|,
literal|101
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_NADDR16
argument_list|,
literal|102
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_NADDR16_LO
argument_list|,
literal|103
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_NADDR16_HI
argument_list|,
literal|104
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_NADDR16_HA
argument_list|,
literal|105
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_SDAI16
argument_list|,
literal|106
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_SDA2I16
argument_list|,
literal|107
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_SDA2REL
argument_list|,
literal|108
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_SDA21
argument_list|,
literal|109
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_MRKREF
argument_list|,
literal|110
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_RELSEC16
argument_list|,
literal|111
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_RELST_LO
argument_list|,
literal|112
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_RELST_HI
argument_list|,
literal|113
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_RELST_HA
argument_list|,
literal|114
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_BIT_FLD
argument_list|,
literal|115
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_EMB_RELSDA
argument_list|,
literal|116
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GNU_VTINHERIT
argument_list|,
literal|253
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_GNU_VTENTRY
argument_list|,
literal|254
argument_list|)
end_macro

begin_comment
comment|/* This is a phony reloc to handle any old fashioned TOC16 references    that may still be in object files.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC_TOC16
argument_list|,
literal|255
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_PPC_max
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_EMB
value|0x80000000
end_define

begin_comment
comment|/* PowerPC embedded flag.  */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_RELOCATABLE
value|0x00010000
end_define

begin_comment
comment|/* PowerPC -mrelocatable flag.  */
end_comment

begin_define
define|#
directive|define
name|EF_PPC_RELOCATABLE_LIB
value|0x00008000
end_define

begin_comment
comment|/* PowerPC -mrelocatable-lib flag.  */
end_comment

begin_comment
comment|/* Processor specific section headers, sh_type field.  */
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
comment|/* Processor specific section flags, sh_flags field.  */
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
comment|/* _ELF_PPC_H */
end_comment

end_unit

