begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MMIX support for BFD.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the MMIX ELF ABI. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_MMIX_H
end_ifndef

begin_define
define|#
directive|define
name|ELF_MMIX_H
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
argument|elf_mmix_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_comment
comment|/* Standard absolute relocations.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_8
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_16
argument_list|,
literal|2
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_24
argument_list|,
literal|3
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_32
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_64
argument_list|,
literal|5
argument_list|)
end_macro

begin_comment
comment|/* Standard relative relocations.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PC_8
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PC_16
argument_list|,
literal|7
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PC_24
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PC_32
argument_list|,
literal|9
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PC_64
argument_list|,
literal|10
argument_list|)
end_macro

begin_comment
comment|/* GNU extensions for C++ vtables.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GNU_VTINHERIT
argument_list|,
literal|11
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GNU_VTENTRY
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* A GETA instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GETA
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GETA_1
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GETA_2
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_GETA_3
argument_list|,
literal|16
argument_list|)
end_macro

begin_comment
comment|/* A conditional branch instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_CBRANCH
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_CBRANCH_J
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_CBRANCH_1
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_CBRANCH_2
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_CBRANCH_3
argument_list|,
literal|21
argument_list|)
end_macro

begin_comment
comment|/* A PUSHJ instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PUSHJ
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PUSHJ_1
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PUSHJ_2
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_PUSHJ_3
argument_list|,
literal|25
argument_list|)
end_macro

begin_comment
comment|/* A JMP instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_JMP
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_JMP_1
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_JMP_2
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_JMP_3
argument_list|,
literal|29
argument_list|)
end_macro

begin_comment
comment|/* A relative address such as in a GETA or a branch.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_ADDR19
argument_list|,
literal|30
argument_list|)
end_macro

begin_comment
comment|/* A relative address such as in a JMP (only).  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_ADDR27
argument_list|,
literal|31
argument_list|)
end_macro

begin_comment
comment|/* A general register or a number 0..255.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_REG_OR_BYTE
argument_list|,
literal|32
argument_list|)
end_macro

begin_comment
comment|/* A general register. */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_REG
argument_list|,
literal|33
argument_list|)
end_macro

begin_comment
comment|/* A global register and an offset, the global register (allocated at      link time) contents plus the offset made equivalent to the relocation      expression at link time.  The relocation must point at the Y field of      an instruction.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_BASE_PLUS_OFFSET
argument_list|,
literal|34
argument_list|)
end_macro

begin_comment
comment|/* A LOCAL assertion.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MMIX_LOCAL
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MMIX_max
argument_list|)
end_macro

begin_comment
comment|/* Section Attributes.  */
end_comment

begin_comment
comment|/* A section containing necessary information for relaxation.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MMIX_CANRELAX
value|0x80000000
end_define

begin_comment
comment|/* Symbol attributes.  */
end_comment

begin_comment
comment|/* A symbol with this section-index is a register.  */
end_comment

begin_define
define|#
directive|define
name|SHN_REGISTER
value|SHN_LOPROC
end_define

begin_comment
comment|/* This section holds contents for each initialized register, at VMA    regno*8.  A symbol relative to this section will be transformed to an    absolute symbol with the value corresponding to the register number at    final link time.  A symbol with a value outside the inclusive range    32*8 .. 254*8 is an error.  It is highly recommended to only use an    upper bound of 253*8 or lower as specified in the (currently    unspecified) ABI.  */
end_comment

begin_define
define|#
directive|define
name|MMIX_REG_CONTENTS_SECTION_NAME
value|".MMIX.reg_contents"
end_define

begin_comment
comment|/* At link time, a section by this name is created, expected to be    included in MMIX_REG_CONTENTS_SECTION_NAME in the output.  */
end_comment

begin_define
define|#
directive|define
name|MMIX_LD_ALLOCATED_REG_CONTENTS_SECTION_NAME
define|\
value|".MMIX.reg_contents.linker_allocated"
end_define

begin_comment
comment|/* This is a faked section holding symbols with SHN_REGISTER.  Don't    confuse it with MMIX_REG_CONTENTS_SECTION_NAME; this one has no    contents, just values.  It is an error for a value in this section to    be outside the range 32..255 and it must never become an actual section    in an object file.  */
end_comment

begin_define
define|#
directive|define
name|MMIX_REG_SECTION_NAME
value|"*REG*"
end_define

begin_comment
comment|/* Appended with a number N=0..65535, this is a representation of the    mmixal "BSPEC N" ... "ESPEC" directive pair; the contents go into an    ELF section by name ".MMIX.spec_data.N".  */
end_comment

begin_define
define|#
directive|define
name|MMIX_OTHER_SPEC_SECTION_PREFIX
value|".MMIX.spec_data."
end_define

begin_comment
comment|/* A section SECNAME is noted to start at "__.MMIX.start.SECNAME" by the    presence of this symbol.  Currently only implemented for ".text"    through the symbol "__.MMIX.start..text".  */
end_comment

begin_define
define|#
directive|define
name|MMIX_LOC_SECTION_START_SYMBOL_PREFIX
value|"__.MMIX.start."
end_define

begin_comment
comment|/* This symbol is always a function.  */
end_comment

begin_define
define|#
directive|define
name|MMIX_START_SYMBOL_NAME
value|"Main"
end_define

begin_comment
comment|/* We smuggle in a few MMO specifics here.  We don't make a specific MMO    file, since we can't reasonably support MMO without ELF; we have to    include this file anyway.  */
end_comment

begin_define
define|#
directive|define
name|MMO_TEXT_SECTION_NAME
value|".text"
end_define

begin_define
define|#
directive|define
name|MMO_DATA_SECTION_NAME
value|".data"
end_define

begin_comment
comment|/* A definition for the flags we put in spec data in files.  A copy of our    own of some flags to keep immune to BFD flag changes.  See section.c of    2001-07-18 for flag documentation.  */
end_comment

begin_define
define|#
directive|define
name|MMO_SEC_ALLOC
value|0x001
end_define

begin_define
define|#
directive|define
name|MMO_SEC_LOAD
value|0x002
end_define

begin_define
define|#
directive|define
name|MMO_SEC_RELOC
value|0x004
end_define

begin_define
define|#
directive|define
name|MMO_SEC_READONLY
value|0x010
end_define

begin_define
define|#
directive|define
name|MMO_SEC_CODE
value|0x020
end_define

begin_define
define|#
directive|define
name|MMO_SEC_DATA
value|0x040
end_define

begin_define
define|#
directive|define
name|MMO_SEC_NEVER_LOAD
value|0x400
end_define

begin_define
define|#
directive|define
name|MMO_SEC_IS_COMMON
value|0x8000
end_define

begin_define
define|#
directive|define
name|MMO_SEC_DEBUGGING
value|0x10000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BFD_ARCH_SIZE
end_ifdef

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_mmix_prepare_linker_allocated_gregs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_mmix_finalize_linker_allocated_gregs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_mmix_check_all_relocs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ELF_MMIX_H */
end_comment

end_unit

