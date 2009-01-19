begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PPC64 ELF support for BFD.    Copyright 2003 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_PPC64_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_PPC64_H
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
argument|elf_ppc64_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR32
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR24
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_LO
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HI
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HA
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR14
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR14_BRTAKEN
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR14_BRNTAKEN
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL24
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL14
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL14_BRTAKEN
argument_list|,
literal|12
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL14_BRNTAKEN
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16_LO
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16_HI
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16_HA
argument_list|,
literal|17
argument_list|)
end_macro

begin_comment
comment|/* 18 unused.  32-bit reloc is R_PPC_PLTREL24.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_COPY
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GLOB_DAT
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_JMP_SLOT
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_RELATIVE
argument_list|,
literal|22
argument_list|)
end_macro

begin_comment
comment|/* 23 unused.  32-bit reloc is R_PPC_LOCAL24PC.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_UADDR32
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_UADDR16
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL32
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT32
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTREL32
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT16_LO
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT16_HI
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT16_HA
argument_list|,
literal|31
argument_list|)
end_macro

begin_comment
comment|/* 32 unused.  32-bit reloc is R_PPC_SDAREL16.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF_LO
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF_HI
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF_HA
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL30
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR64
argument_list|,
literal|38
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HIGHER
argument_list|,
literal|39
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HIGHERA
argument_list|,
literal|40
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HIGHEST
argument_list|,
literal|41
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_HIGHESTA
argument_list|,
literal|42
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_UADDR64
argument_list|,
literal|43
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_REL64
argument_list|,
literal|44
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT64
argument_list|,
literal|45
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTREL64
argument_list|,
literal|46
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16
argument_list|,
literal|47
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16_LO
argument_list|,
literal|48
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16_HI
argument_list|,
literal|49
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16_HA
argument_list|,
literal|50
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC
argument_list|,
literal|51
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16
argument_list|,
literal|52
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16_LO
argument_list|,
literal|53
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16_HI
argument_list|,
literal|54
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16_HA
argument_list|,
literal|55
argument_list|)
end_macro

begin_comment
comment|/* The following relocs were added in the 64-bit PowerPC ELF ABI      revision 1.2. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_DS
argument_list|,
literal|56
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_ADDR16_LO_DS
argument_list|,
literal|57
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16_DS
argument_list|,
literal|58
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT16_LO_DS
argument_list|,
literal|59
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLT16_LO_DS
argument_list|,
literal|60
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF_DS
argument_list|,
literal|61
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_SECTOFF_LO_DS
argument_list|,
literal|62
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16_DS
argument_list|,
literal|63
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TOC16_LO_DS
argument_list|,
literal|64
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16_DS
argument_list|,
literal|65
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_PLTGOT16_LO_DS
argument_list|,
literal|66
argument_list|)
end_macro

begin_comment
comment|/* Relocs added to support TLS.  PowerPC64 ELF ABI revision 1.5.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TLS
argument_list|,
literal|67
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPMOD64
argument_list|,
literal|68
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16
argument_list|,
literal|69
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_LO
argument_list|,
literal|70
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HI
argument_list|,
literal|71
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HA
argument_list|,
literal|72
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL64
argument_list|,
literal|73
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16
argument_list|,
literal|74
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_LO
argument_list|,
literal|75
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HI
argument_list|,
literal|76
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HA
argument_list|,
literal|77
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL64
argument_list|,
literal|78
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSGD16
argument_list|,
literal|79
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSGD16_LO
argument_list|,
literal|80
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSGD16_HI
argument_list|,
literal|81
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSGD16_HA
argument_list|,
literal|82
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSLD16
argument_list|,
literal|83
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSLD16_LO
argument_list|,
literal|84
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSLD16_HI
argument_list|,
literal|85
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TLSLD16_HA
argument_list|,
literal|86
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TPREL16_DS
argument_list|,
literal|87
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TPREL16_LO_DS
argument_list|,
literal|88
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TPREL16_HI
argument_list|,
literal|89
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_TPREL16_HA
argument_list|,
literal|90
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_DTPREL16_DS
argument_list|,
literal|91
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_DTPREL16_LO_DS
argument_list|,
literal|92
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_DTPREL16_HI
argument_list|,
literal|93
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GOT_DTPREL16_HA
argument_list|,
literal|94
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_DS
argument_list|,
literal|95
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_LO_DS
argument_list|,
literal|96
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HIGHER
argument_list|,
literal|97
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HIGHERA
argument_list|,
literal|98
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HIGHEST
argument_list|,
literal|99
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_TPREL16_HIGHESTA
argument_list|,
literal|100
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_DS
argument_list|,
literal|101
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_LO_DS
argument_list|,
literal|102
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HIGHER
argument_list|,
literal|103
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HIGHERA
argument_list|,
literal|104
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HIGHEST
argument_list|,
literal|105
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_DTPREL16_HIGHESTA
argument_list|,
literal|106
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GNU_VTINHERIT
argument_list|,
literal|253
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_PPC64_GNU_VTENTRY
argument_list|,
literal|254
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_PPC64_max
argument_list|)
end_macro

begin_define
define|#
directive|define
name|IS_PPC64_TLS_RELOC
parameter_list|(
name|R
parameter_list|)
define|\
value|((R)>= R_PPC64_TLS&& (R)<= R_PPC64_DTPREL16_HIGHESTA)
end_define

begin_comment
comment|/* Specify the start of the .glink section.  */
end_comment

begin_define
define|#
directive|define
name|DT_PPC64_GLINK
value|DT_LOPROC
end_define

begin_comment
comment|/* Specify the start and size of the .opd section.  */
end_comment

begin_define
define|#
directive|define
name|DT_PPC64_OPD
value|(DT_LOPROC + 1)
end_define

begin_define
define|#
directive|define
name|DT_PPC64_OPDSZ
value|(DT_LOPROC + 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_PPC64_H */
end_comment

end_unit

