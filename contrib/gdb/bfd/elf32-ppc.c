begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* PowerPC-specific support for 32-bit ELF    Copyright 1994, 1995, 1996 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is based on a preliminary PowerPC ELF ABI.  The    information may not match the final PowerPC ELF ABI.  It includes    suggestions from the in-progress Embedded PowerPC ABI, and that    information may also not match.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_include
include|#
directive|include
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"elf-bfd.h"
end_include

begin_include
include|#
directive|include
file|"elf/ppc.h"
end_include

begin_define
define|#
directive|define
name|USE_RELA
end_define

begin_comment
comment|/* we want RELA relocations, not REL */
end_comment

begin_comment
comment|/* PowerPC relocations defined by the ABIs */
end_comment

begin_enum
enum|enum
name|ppc_reloc_type
block|{
name|R_PPC_NONE
init|=
literal|0
block|,
name|R_PPC_ADDR32
init|=
literal|1
block|,
name|R_PPC_ADDR24
init|=
literal|2
block|,
name|R_PPC_ADDR16
init|=
literal|3
block|,
name|R_PPC_ADDR16_LO
init|=
literal|4
block|,
name|R_PPC_ADDR16_HI
init|=
literal|5
block|,
name|R_PPC_ADDR16_HA
init|=
literal|6
block|,
name|R_PPC_ADDR14
init|=
literal|7
block|,
name|R_PPC_ADDR14_BRTAKEN
init|=
literal|8
block|,
name|R_PPC_ADDR14_BRNTAKEN
init|=
literal|9
block|,
name|R_PPC_REL24
init|=
literal|10
block|,
name|R_PPC_REL14
init|=
literal|11
block|,
name|R_PPC_REL14_BRTAKEN
init|=
literal|12
block|,
name|R_PPC_REL14_BRNTAKEN
init|=
literal|13
block|,
name|R_PPC_GOT16
init|=
literal|14
block|,
name|R_PPC_GOT16_LO
init|=
literal|15
block|,
name|R_PPC_GOT16_HI
init|=
literal|16
block|,
name|R_PPC_GOT16_HA
init|=
literal|17
block|,
name|R_PPC_PLTREL24
init|=
literal|18
block|,
name|R_PPC_COPY
init|=
literal|19
block|,
name|R_PPC_GLOB_DAT
init|=
literal|20
block|,
name|R_PPC_JMP_SLOT
init|=
literal|21
block|,
name|R_PPC_RELATIVE
init|=
literal|22
block|,
name|R_PPC_LOCAL24PC
init|=
literal|23
block|,
name|R_PPC_UADDR32
init|=
literal|24
block|,
name|R_PPC_UADDR16
init|=
literal|25
block|,
name|R_PPC_REL32
init|=
literal|26
block|,
name|R_PPC_PLT32
init|=
literal|27
block|,
name|R_PPC_PLTREL32
init|=
literal|28
block|,
name|R_PPC_PLT16_LO
init|=
literal|29
block|,
name|R_PPC_PLT16_HI
init|=
literal|30
block|,
name|R_PPC_PLT16_HA
init|=
literal|31
block|,
name|R_PPC_SDAREL16
init|=
literal|32
block|,
name|R_PPC_SECTOFF
init|=
literal|33
block|,
name|R_PPC_SECTOFF_LO
init|=
literal|34
block|,
name|R_PPC_SECTOFF_HI
init|=
literal|35
block|,
name|R_PPC_SECTOFF_HA
init|=
literal|36
block|,
comment|/* The remaining relocs are from the Embedded ELF ABI, and are not      in the SVR4 ELF ABI.  */
name|R_PPC_EMB_NADDR32
init|=
literal|101
block|,
name|R_PPC_EMB_NADDR16
init|=
literal|102
block|,
name|R_PPC_EMB_NADDR16_LO
init|=
literal|103
block|,
name|R_PPC_EMB_NADDR16_HI
init|=
literal|104
block|,
name|R_PPC_EMB_NADDR16_HA
init|=
literal|105
block|,
name|R_PPC_EMB_SDAI16
init|=
literal|106
block|,
name|R_PPC_EMB_SDA2I16
init|=
literal|107
block|,
name|R_PPC_EMB_SDA2REL
init|=
literal|108
block|,
name|R_PPC_EMB_SDA21
init|=
literal|109
block|,
name|R_PPC_EMB_MRKREF
init|=
literal|110
block|,
name|R_PPC_EMB_RELSEC16
init|=
literal|111
block|,
name|R_PPC_EMB_RELST_LO
init|=
literal|112
block|,
name|R_PPC_EMB_RELST_HI
init|=
literal|113
block|,
name|R_PPC_EMB_RELST_HA
init|=
literal|114
block|,
name|R_PPC_EMB_BIT_FLD
init|=
literal|115
block|,
name|R_PPC_EMB_RELSDA
init|=
literal|116
block|,
comment|/* This is a phony reloc to handle any old fashioned TOC16 references      that may still be in object files.  */
name|R_PPC_TOC16
init|=
literal|255
block|,
name|R_PPC_max
block|}
enum|;
end_enum

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|ppc_elf_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ppc_elf_info_to_howto
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|arelent
operator|*
name|cache_ptr
operator|,
name|Elf32_Internal_Rela
operator|*
name|dst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ppc_elf_howto_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_set_private_flags
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|flagword
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_copy_private_bfd_data
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_merge_private_bfd_data
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|ppc_elf_additional_program_headers
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_modify_segment_map
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_section_from_shdr
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|Elf32_Internal_Shdr
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|elf_linker_section_t
modifier|*
name|ppc_elf_create_linker_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
expr|struct
name|bfd_link_info
operator|*
name|info
operator|,
expr|enum
name|elf_linker_section_enum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_check_relocs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|asection
operator|*
operator|,
specifier|const
name|Elf_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_adjust_dynamic_symbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
expr|struct
name|elf_link_hash_entry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_adjust_dynindx
name|PARAMS
argument_list|(
operator|(
expr|struct
name|elf_link_hash_entry
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_size_dynamic_sections
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
specifier|static
name|boolean
name|ppc_elf_relocate_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
name|info
operator|,
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_byte
operator|*
operator|,
name|Elf_Internal_Rela
operator|*
name|relocs
operator|,
name|Elf_Internal_Sym
operator|*
name|local_syms
operator|,
name|asection
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_add_symbol_hook
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
specifier|const
name|Elf_Internal_Sym
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|flagword
operator|*
operator|,
name|asection
operator|*
operator|*
operator|,
name|bfd_vma
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_finish_dynamic_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
expr|struct
name|elf_link_hash_entry
operator|*
operator|,
name|Elf_Internal_Sym
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|ppc_elf_finish_dynamic_sections
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

begin_define
define|#
directive|define
name|BRANCH_PREDICT_BIT
value|0x200000
end_define

begin_comment
comment|/* branch prediction bit for branch taken relocs */
end_comment

begin_define
define|#
directive|define
name|RA_REGISTER_MASK
value|0x001f0000
end_define

begin_comment
comment|/* mask to set RA in memory instructions */
end_comment

begin_define
define|#
directive|define
name|RA_REGISTER_SHIFT
value|16
end_define

begin_comment
comment|/* value to shift register by to insert RA */
end_comment

begin_comment
comment|/* The name of the dynamic interpreter.  This is put in the .interp    section.  */
end_comment

begin_define
define|#
directive|define
name|ELF_DYNAMIC_INTERPRETER
value|"/usr/lib/ld.so.1"
end_define

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|R_PPC_max
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|ppc_elf_howto_raw
index|[]
init|=
block|{
comment|/* This reloc does nothing.  */
name|HOWTO
argument_list|(
name|R_PPC_NONE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_NONE"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A standard 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* An absolute 26 bit branch; the lower two bits must be zero.      FIXME: we don't check that, we just clear them.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR24
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR24"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A standard 16 bit relocation.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16 bit relocation without overflow.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR16_LO
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR16_LO"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The high order 16 bits of an address.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR16_HI
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR16_HI"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The high order 16 bits of an address, plus 1 if the contents of      the low 16 bits, treated as a signed number, is negative.	*/
name|HOWTO
argument_list|(
name|R_PPC_ADDR16_HA
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR16_HA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* An absolute 16 bit branch; the lower two bits must be zero.      FIXME: we don't check that, we just clear them.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR14
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR14"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* An absolute 16 bit branch, for which bit 10 should be set to      indicate that the branch is expected to be taken.	The lower two      bits must be zero.	 */
name|HOWTO
argument_list|(
name|R_PPC_ADDR14_BRTAKEN
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR14_BRTAKEN"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* An absolute 16 bit branch, for which bit 10 should be set to      indicate that the branch is not expected to be taken.  The lower      two bits must be zero.  */
name|HOWTO
argument_list|(
name|R_PPC_ADDR14_BRNTAKEN
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_ADDR14_BRNTAKEN"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A relative 26 bit branch; the lower two bits must be zero.	 */
name|HOWTO
argument_list|(
name|R_PPC_REL24
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_REL24"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A relative 16 bit branch; the lower two bits must be zero.	 */
name|HOWTO
argument_list|(
name|R_PPC_REL14
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_REL14"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A relative 16 bit branch.	Bit 10 should be set to indicate that      the branch is expected to be taken.  The lower two bits must be      zero.  */
name|HOWTO
argument_list|(
name|R_PPC_REL14_BRTAKEN
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_REL14_BRTAKEN"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A relative 16 bit branch.	Bit 10 should be set to indicate that      the branch is not expected to be taken.  The lower two bits must      be zero.  */
name|HOWTO
argument_list|(
name|R_PPC_REL14_BRNTAKEN
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_REL14_BRNTAKEN"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16, but referring to the GOT table entry for the      symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_GOT16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_GOT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_LO, but referring to the GOT table entry for      the symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_GOT16_LO
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_GOT16_LO"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_HI, but referring to the GOT table entry for      the symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_GOT16_HI
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_GOT16_HI"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_HA, but referring to the GOT table entry for      the symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_GOT16_HA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_GOT16_HA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_REL24, but referring to the procedure linkage table      entry for the symbol.  FIXME: Not supported.  */
name|HOWTO
argument_list|(
name|R_PPC_PLTREL24
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLTREL24"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* This is used only by the dynamic linker.  The symbol should exist      both in the object being run and in some shared library.  The      dynamic linker copies the data addressed by the symbol from the      shared library into the object.  I have no idea what the purpose      of this is.  */
name|HOWTO
argument_list|(
name|R_PPC_COPY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_COPY"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR32, but used when setting global offset table      entries.  */
name|HOWTO
argument_list|(
name|R_PPC_GLOB_DAT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_GLOB_DAT"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Marks a procedure linkage table entry for a symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_JMP_SLOT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_JMP_SLOT"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Used only by the dynamic linker.  When the object is run, this      longword is set to the load address of the object, plus the      addend.  */
name|HOWTO
argument_list|(
name|R_PPC_RELATIVE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_RELATIVE"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_REL24, but uses the value of the symbol within the      object rather than the final value.  Normally used for      _GLOBAL_OFFSET_TABLE_.  FIXME: Not supported.  */
name|HOWTO
argument_list|(
name|R_PPC_LOCAL24PC
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_LOCAL24PC"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR32, but may be unaligned.  */
name|HOWTO
argument_list|(
name|R_PPC_UADDR32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_UADDR32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16, but may be unaligned.  */
name|HOWTO
argument_list|(
name|R_PPC_UADDR16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_UADDR16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit PC relative */
name|HOWTO
argument_list|(
name|R_PPC_REL32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_REL32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit relocation to the symbol's procedure linkage table.      FIXEME: not supported. */
name|HOWTO
argument_list|(
name|R_PPC_PLT32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLT32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit PC relative relocation to the symbol's procedure linkage table.      FIXEME: not supported. */
name|HOWTO
argument_list|(
name|R_PPC_PLTREL32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLTREL32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_LO, but referring to the PLT table entry for      the symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_PLT16_LO
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLT16_LO"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_HI, but referring to the PLT table entry for      the symbol.  */
name|HOWTO
argument_list|(
name|R_PPC_PLT16_HI
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLT16_HI"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like R_PPC_ADDR16_HA, but referring to the PLT table entry for      the symbol.  FIXME: Not supported.	 */
name|HOWTO
argument_list|(
name|R_PPC_PLT16_HA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_PLT16_HA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A sign-extended 16 bit value relative to _SDA_BASE_, for use with      small data items.  */
name|HOWTO
argument_list|(
name|R_PPC_SDAREL16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_SDAREL16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit section relative relocation. */
name|HOWTO
argument_list|(
name|R_PPC_SECTOFF
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_SECTOFF"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16-bit lower half section relative relocation. */
name|HOWTO
argument_list|(
name|R_PPC_SECTOFF_LO
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_SECTOFF_LO"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16-bit upper half section relative relocation. */
name|HOWTO
argument_list|(
name|R_PPC_SECTOFF_HI
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_SECTOFF_HI"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16-bit upper half adjusted section relative relocation. */
name|HOWTO
argument_list|(
name|R_PPC_SECTOFF_HA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_SECTOFF_HA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The remaining relocs are from the Embedded ELF ABI, and are not      in the SVR4 ELF ABI.  */
comment|/* 32 bit value resulting from the addend minus the symbol */
name|HOWTO
argument_list|(
name|R_PPC_EMB_NADDR32
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|32
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_NADDR32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit value resulting from the addend minus the symbol */
name|HOWTO
argument_list|(
name|R_PPC_EMB_NADDR16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_NADDR16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit value resulting from the addend minus the symbol */
name|HOWTO
argument_list|(
name|R_PPC_EMB_NADDR16_LO
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_ADDR16_LO"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The high order 16 bits of the addend minus the symbol */
name|HOWTO
argument_list|(
name|R_PPC_EMB_NADDR16_HI
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_NADDR16_HI"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The high order 16 bits of the result of the addend minus the address,      plus 1 if the contents of the low 16 bits, treated as a signed number,      is negative.  */
name|HOWTO
argument_list|(
name|R_PPC_EMB_NADDR16_HA
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_NADDR16_HA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit value resulting from allocating a 4 byte word to hold an      address in the .sdata section, and returning the offset from      _SDA_BASE_ for that relocation */
name|HOWTO
argument_list|(
name|R_PPC_EMB_SDAI16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_SDAI16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit value resulting from allocating a 4 byte word to hold an      address in the .sdata2 section, and returning the offset from      _SDA2_BASE_ for that relocation */
name|HOWTO
argument_list|(
name|R_PPC_EMB_SDA2I16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_SDA2I16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A sign-extended 16 bit value relative to _SDA2_BASE_, for use with      small data items.	 */
name|HOWTO
argument_list|(
name|R_PPC_EMB_SDA2REL
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_SDA2REL"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Relocate against either _SDA_BASE_ or _SDA2_BASE_, filling in the 16 bit      signed offset from the appropriate base, and filling in the register      field with the appropriate register (0, 2, or 13).  */
name|HOWTO
argument_list|(
name|R_PPC_EMB_SDA21
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_SDA21"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Relocation not handled: R_PPC_EMB_MRKREF */
comment|/* Relocation not handled: R_PPC_EMB_RELSEC16 */
comment|/* Relocation not handled: R_PPC_EMB_RELST_LO */
comment|/* Relocation not handled: R_PPC_EMB_RELST_HI */
comment|/* Relocation not handled: R_PPC_EMB_RELST_HA */
comment|/* Relocation not handled: R_PPC_EMB_BIT_FLD */
comment|/* PC relative relocation against either _SDA_BASE_ or _SDA2_BASE_, filling      in the 16 bit signed offset from the appropriate base, and filling in the      register field with the appropriate register (0, 2, or 13).  */
name|HOWTO
argument_list|(
name|R_PPC_EMB_RELSDA
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_EMB_RELSDA"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Phony reloc to handle AIX style TOC entries */
name|HOWTO
argument_list|(
name|R_PPC_TOC16
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_PPC_TOC16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Initialize the ppc_elf_howto_table, so that linear accesses can be done.  */
end_comment

begin_function
specifier|static
name|void
name|ppc_elf_howto_init
parameter_list|()
block|{
name|unsigned
name|int
name|i
decl_stmt|,
name|type
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
sizeof|sizeof
argument_list|(
name|ppc_elf_howto_raw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ppc_elf_howto_raw
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
name|type
operator|=
name|ppc_elf_howto_raw
index|[
name|i
index|]
operator|.
name|type
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|type
operator|<
sizeof|sizeof
argument_list|(
name|ppc_elf_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|ppc_elf_howto_table
index|[
literal|0
index|]
argument_list|)
argument_list|)
expr_stmt|;
name|ppc_elf_howto_table
index|[
name|type
index|]
operator|=
operator|&
name|ppc_elf_howto_raw
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|ppc_elf_reloc_type_lookup
parameter_list|(
name|abfd
parameter_list|,
name|code
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|bfd_reloc_code_real_type
name|code
decl_stmt|;
block|{
name|enum
name|ppc_reloc_type
name|ppc_reloc
init|=
name|R_PPC_NONE
decl_stmt|;
if|if
condition|(
operator|!
name|ppc_elf_howto_table
index|[
name|R_PPC_ADDR32
index|]
condition|)
comment|/* Initialize howto table if needed */
name|ppc_elf_howto_init
argument_list|()
expr_stmt|;
switch|switch
condition|(
operator|(
name|int
operator|)
name|code
condition|)
block|{
default|default:
return|return
operator|(
name|reloc_howto_type
operator|*
operator|)
name|NULL
return|;
case|case
name|BFD_RELOC_NONE
case|:
name|ppc_reloc
operator|=
name|R_PPC_NONE
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_BA26
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR24
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_16
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_LO16
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR16_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR16_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_S
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR16_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_BA16
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR14
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_BA16_BRTAKEN
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR14_BRTAKEN
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_BA16_BRNTAKEN
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR14_BRNTAKEN
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_B26
case|:
name|ppc_reloc
operator|=
name|R_PPC_REL24
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_B16
case|:
name|ppc_reloc
operator|=
name|R_PPC_REL14
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_B16_BRTAKEN
case|:
name|ppc_reloc
operator|=
name|R_PPC_REL14_BRTAKEN
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_B16_BRNTAKEN
case|:
name|ppc_reloc
operator|=
name|R_PPC_REL14_BRNTAKEN
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_16_GOTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_GOT16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_LO16_GOTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_GOT16_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_GOTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_GOT16_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_S_GOTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_GOT16_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_24_PLT_PCREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLTREL24
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_COPY
case|:
name|ppc_reloc
operator|=
name|R_PPC_COPY
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_GLOB_DAT
case|:
name|ppc_reloc
operator|=
name|R_PPC_GLOB_DAT
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_LOCAL24PC
case|:
name|ppc_reloc
operator|=
name|R_PPC_LOCAL24PC
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32_PCREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_REL32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32_PLTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLT32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32_PLT_PCREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLTREL32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_LO16_PLTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLT16_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_PLTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLT16_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_S_PLTOFF
case|:
name|ppc_reloc
operator|=
name|R_PPC_PLT16_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_GPREL16
case|:
name|ppc_reloc
operator|=
name|R_PPC_SDAREL16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32_BASEREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_SECTOFF
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_LO16_BASEREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_SECTOFF_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_BASEREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_SECTOFF_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_HI16_S_BASEREL
case|:
name|ppc_reloc
operator|=
name|R_PPC_SECTOFF_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_CTOR
case|:
name|ppc_reloc
operator|=
name|R_PPC_ADDR32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_TOC16
case|:
name|ppc_reloc
operator|=
name|R_PPC_TOC16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_NADDR32
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_NADDR32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_NADDR16
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_NADDR16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_NADDR16_LO
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_NADDR16_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_NADDR16_HI
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_NADDR16_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_NADDR16_HA
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_NADDR16_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_SDAI16
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_SDAI16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_SDA2I16
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_SDA2I16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_SDA2REL
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_SDA2REL
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_SDA21
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_SDA21
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_MRKREF
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_MRKREF
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_RELSEC16
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_RELSEC16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_RELST_LO
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_RELST_LO
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_RELST_HI
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_RELST_HI
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_RELST_HA
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_RELST_HA
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_BIT_FLD
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_BIT_FLD
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_PPC_EMB_RELSDA
case|:
name|ppc_reloc
operator|=
name|R_PPC_EMB_RELSDA
expr_stmt|;
break|break;
block|}
return|return
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|ppc_reloc
index|]
return|;
block|}
end_function

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Set the howto pointer for a PowerPC ELF reloc.  */
end_comment

begin_function
specifier|static
name|void
name|ppc_elf_info_to_howto
parameter_list|(
name|abfd
parameter_list|,
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|arelent
modifier|*
name|cache_ptr
decl_stmt|;
name|Elf32_Internal_Rela
modifier|*
name|dst
decl_stmt|;
block|{
if|if
condition|(
operator|!
name|ppc_elf_howto_table
index|[
name|R_PPC_ADDR32
index|]
condition|)
comment|/* Initialize howto table if needed */
name|ppc_elf_howto_init
argument_list|()
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|ELF32_R_TYPE
argument_list|(
name|dst
operator|->
name|r_info
argument_list|)
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_PPC_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
name|ppc_elf_howto_table
index|[
name|ELF32_R_TYPE
argument_list|(
name|dst
operator|->
name|r_info
argument_list|)
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Function to set whether a module needs the -mrelocatable bit set. */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_set_private_flags
parameter_list|(
name|abfd
parameter_list|,
name|flags
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|flagword
name|flags
decl_stmt|;
block|{
name|BFD_ASSERT
argument_list|(
operator|!
name|elf_flags_init
argument_list|(
name|abfd
argument_list|)
operator|||
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator|==
name|flags
argument_list|)
expr_stmt|;
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator|=
name|flags
expr_stmt|;
name|elf_flags_init
argument_list|(
name|abfd
argument_list|)
operator|=
name|true
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Copy backend specific data from one object module to another */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_copy_private_bfd_data
parameter_list|(
name|ibfd
parameter_list|,
name|obfd
parameter_list|)
name|bfd
modifier|*
name|ibfd
decl_stmt|;
name|bfd
modifier|*
name|obfd
decl_stmt|;
block|{
comment|/* This function is selected based on the input vector.  We only      want to copy information over if the output BFD also uses Elf      format.  */
if|if
condition|(
name|bfd_get_flavour
argument_list|(
name|obfd
argument_list|)
operator|!=
name|bfd_target_elf_flavour
condition|)
return|return
name|true
return|;
name|BFD_ASSERT
argument_list|(
operator|!
name|elf_flags_init
argument_list|(
name|obfd
argument_list|)
operator|||
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
operator|==
name|elf_elfheader
argument_list|(
name|ibfd
argument_list|)
operator|->
name|e_flags
argument_list|)
expr_stmt|;
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
operator|=
name|elf_elfheader
argument_list|(
name|ibfd
argument_list|)
operator|->
name|e_flags
expr_stmt|;
name|elf_flags_init
argument_list|(
name|obfd
argument_list|)
operator|=
name|true
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Merge backend specific data from an object file to the output    object file when linking */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_merge_private_bfd_data
parameter_list|(
name|ibfd
parameter_list|,
name|obfd
parameter_list|)
name|bfd
modifier|*
name|ibfd
decl_stmt|;
name|bfd
modifier|*
name|obfd
decl_stmt|;
block|{
name|flagword
name|old_flags
decl_stmt|;
name|flagword
name|new_flags
decl_stmt|;
name|boolean
name|error
decl_stmt|;
comment|/* Check if we have the same endianess */
if|if
condition|(
name|ibfd
operator|->
name|xvec
operator|->
name|byteorder
operator|!=
name|obfd
operator|->
name|xvec
operator|->
name|byteorder
operator|&&
name|obfd
operator|->
name|xvec
operator|->
name|byteorder
operator|!=
name|BFD_ENDIAN_UNKNOWN
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: compiled for a %s endian system and target is %s endian"
argument_list|,
name|bfd_get_filename
argument_list|(
name|ibfd
argument_list|)
argument_list|,
name|bfd_big_endian
argument_list|(
name|ibfd
argument_list|)
condition|?
literal|"big"
else|:
literal|"little"
argument_list|,
name|bfd_big_endian
argument_list|(
name|obfd
argument_list|)
condition|?
literal|"big"
else|:
literal|"little"
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_wrong_format
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/* This function is selected based on the input vector.  We only      want to copy information over if the output BFD also uses Elf      format.  */
if|if
condition|(
name|bfd_get_flavour
argument_list|(
name|obfd
argument_list|)
operator|!=
name|bfd_target_elf_flavour
condition|)
return|return
name|true
return|;
name|new_flags
operator|=
name|elf_elfheader
argument_list|(
name|ibfd
argument_list|)
operator|->
name|e_flags
expr_stmt|;
name|old_flags
operator|=
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
expr_stmt|;
if|if
condition|(
operator|!
name|elf_flags_init
argument_list|(
name|obfd
argument_list|)
condition|)
comment|/* First call, no flags set */
block|{
name|elf_flags_init
argument_list|(
name|obfd
argument_list|)
operator|=
name|true
expr_stmt|;
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
operator|=
name|new_flags
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|new_flags
operator|==
name|old_flags
condition|)
comment|/* Compatible flags are ok */
empty_stmt|;
else|else
comment|/* Incompatible flags */
block|{
comment|/* Warn about -mrelocatable mismatch.  Allow -mrelocatable-lib to be linked          with either.  */
name|error
operator|=
name|false
expr_stmt|;
if|if
condition|(
operator|(
name|new_flags
operator|&
name|EF_PPC_RELOCATABLE
operator|)
operator|!=
literal|0
operator|&&
operator|(
name|old_flags
operator|&
operator|(
name|EF_PPC_RELOCATABLE
operator||
name|EF_PPC_RELOCATABLE_LIB
operator|)
operator|)
operator|==
literal|0
condition|)
block|{
name|error
operator|=
name|true
expr_stmt|;
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: compiled with -mrelocatable and linked with modules compiled normally"
argument_list|,
name|bfd_get_filename
argument_list|(
name|ibfd
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|new_flags
operator|&
operator|(
name|EF_PPC_RELOCATABLE
operator||
name|EF_PPC_RELOCATABLE_LIB
operator|)
operator|)
operator|==
literal|0
operator|&&
operator|(
name|old_flags
operator|&
name|EF_PPC_RELOCATABLE
operator|)
operator|!=
literal|0
condition|)
block|{
name|error
operator|=
name|true
expr_stmt|;
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: compiled normally and linked with modules compiled with -mrelocatable"
argument_list|,
name|bfd_get_filename
argument_list|(
name|ibfd
argument_list|)
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|new_flags
operator|&
name|EF_PPC_RELOCATABLE_LIB
operator|)
operator|!=
literal|0
condition|)
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
operator||=
name|EF_PPC_RELOCATABLE_LIB
expr_stmt|;
comment|/* Do not warn about eabi vs. V.4 mismatch, just or in the bit if any module uses it */
name|elf_elfheader
argument_list|(
name|obfd
argument_list|)
operator|->
name|e_flags
operator||=
operator|(
name|new_flags
operator|&
name|EF_PPC_EMB
operator|)
expr_stmt|;
name|new_flags
operator|&=
operator|~
operator|(
name|EF_PPC_RELOCATABLE
operator||
name|EF_PPC_RELOCATABLE_LIB
operator||
name|EF_PPC_EMB
operator|)
expr_stmt|;
name|old_flags
operator|&=
operator|~
operator|(
name|EF_PPC_RELOCATABLE
operator||
name|EF_PPC_RELOCATABLE_LIB
operator||
name|EF_PPC_EMB
operator|)
expr_stmt|;
comment|/* Warn about any other mismatches */
if|if
condition|(
name|new_flags
operator|!=
name|old_flags
condition|)
block|{
name|error
operator|=
name|true
expr_stmt|;
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: uses different e_flags (0x%lx) fields than previous modules (0x%lx)"
argument_list|,
name|bfd_get_filename
argument_list|(
name|ibfd
argument_list|)
argument_list|,
operator|(
name|long
operator|)
name|new_flags
argument_list|,
operator|(
name|long
operator|)
name|old_flags
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|error
condition|)
block|{
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Handle a PowerPC specific section when reading an object file.  This    is called when elfcode.h finds a section with an unknown type.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_section_from_shdr
parameter_list|(
name|abfd
parameter_list|,
name|hdr
parameter_list|,
name|name
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|Elf32_Internal_Shdr
modifier|*
name|hdr
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|{
name|asection
modifier|*
name|newsect
decl_stmt|;
name|flagword
name|flags
decl_stmt|;
if|if
condition|(
operator|!
name|_bfd_elf_make_section_from_shdr
argument_list|(
name|abfd
argument_list|,
name|hdr
argument_list|,
name|name
argument_list|)
condition|)
return|return
name|false
return|;
name|newsect
operator|=
name|hdr
operator|->
name|bfd_section
expr_stmt|;
name|flags
operator|=
name|bfd_get_section_flags
argument_list|(
name|abfd
argument_list|,
name|newsect
argument_list|)
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|sh_flags
operator|&
name|SHF_EXCLUDE
condition|)
name|flags
operator||=
name|SEC_EXCLUDE
expr_stmt|;
if|if
condition|(
name|hdr
operator|->
name|sh_type
operator|==
name|SHT_ORDERED
condition|)
name|flags
operator||=
name|SEC_SORT_ENTRIES
expr_stmt|;
name|bfd_set_section_flags
argument_list|(
name|abfd
argument_list|,
name|newsect
argument_list|,
name|flags
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Set up any other section flags and such that may be necessary.  */
end_comment

begin_function
name|boolean
name|ppc_elf_fake_sections
parameter_list|(
name|abfd
parameter_list|,
name|shdr
parameter_list|,
name|asect
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|Elf32_Internal_Shdr
modifier|*
name|shdr
decl_stmt|;
name|asection
modifier|*
name|asect
decl_stmt|;
block|{
if|if
condition|(
operator|(
name|asect
operator|->
name|flags
operator|&
name|SEC_EXCLUDE
operator|)
operator|!=
literal|0
condition|)
name|shdr
operator|->
name|sh_flags
operator||=
name|SHF_EXCLUDE
expr_stmt|;
if|if
condition|(
operator|(
name|asect
operator|->
name|flags
operator|&
name|SEC_SORT_ENTRIES
operator|)
operator|!=
literal|0
condition|)
name|shdr
operator|->
name|sh_type
operator|=
name|SHT_ORDERED
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Create a special linker section */
end_comment

begin_function
specifier|static
name|elf_linker_section_t
modifier|*
name|ppc_elf_create_linker_section
parameter_list|(
name|abfd
parameter_list|,
name|info
parameter_list|,
name|which
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|enum
name|elf_linker_section_enum
name|which
decl_stmt|;
block|{
name|bfd
modifier|*
name|dynobj
init|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|lsect
decl_stmt|;
comment|/* Record the first bfd section that needs the special section */
if|if
condition|(
operator|!
name|dynobj
condition|)
name|dynobj
operator|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
operator|=
name|abfd
expr_stmt|;
comment|/* If this is the first time, create the section */
name|lsect
operator|=
name|elf_linker_section
argument_list|(
name|dynobj
argument_list|,
name|which
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|lsect
condition|)
block|{
name|elf_linker_section_t
name|defaults
decl_stmt|;
specifier|static
name|elf_linker_section_t
name|zero_section
decl_stmt|;
name|defaults
operator|=
name|zero_section
expr_stmt|;
name|defaults
operator|.
name|which
operator|=
name|which
expr_stmt|;
name|defaults
operator|.
name|hole_written_p
operator|=
name|false
expr_stmt|;
name|defaults
operator|.
name|alignment
operator|=
literal|2
expr_stmt|;
name|defaults
operator|.
name|flags
operator|=
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_HAS_CONTENTS
operator||
name|SEC_IN_MEMORY
expr_stmt|;
switch|switch
condition|(
name|which
condition|)
block|{
default|default:
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: Unknown special linker type %d"
argument_list|,
name|bfd_get_filename
argument_list|(
name|abfd
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|which
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
operator|(
name|elf_linker_section_t
operator|*
operator|)
literal|0
return|;
case|case
name|LINKER_SECTION_GOT
case|:
comment|/* .got section */
name|defaults
operator|.
name|name
operator|=
literal|".got"
expr_stmt|;
name|defaults
operator|.
name|rel_name
operator|=
literal|".rela.got"
expr_stmt|;
name|defaults
operator|.
name|sym_name
operator|=
literal|"_GLOBAL_OFFSET_TABLE_"
expr_stmt|;
name|defaults
operator|.
name|max_hole_offset
operator|=
literal|32764
expr_stmt|;
name|defaults
operator|.
name|hole_size
operator|=
literal|16
expr_stmt|;
name|defaults
operator|.
name|sym_offset
operator|=
literal|4
expr_stmt|;
break|break;
case|case
name|LINKER_SECTION_SDATA
case|:
comment|/* .sdata/.sbss section */
name|defaults
operator|.
name|name
operator|=
literal|".sdata"
expr_stmt|;
name|defaults
operator|.
name|rel_name
operator|=
literal|".rela.sdata"
expr_stmt|;
name|defaults
operator|.
name|bss_name
operator|=
literal|".sbss"
expr_stmt|;
name|defaults
operator|.
name|sym_name
operator|=
literal|"_SDA_BASE_"
expr_stmt|;
name|defaults
operator|.
name|sym_offset
operator|=
literal|32768
expr_stmt|;
break|break;
case|case
name|LINKER_SECTION_SDATA2
case|:
comment|/* .sdata2/.sbss2 section */
name|defaults
operator|.
name|name
operator|=
literal|".sdata2"
expr_stmt|;
name|defaults
operator|.
name|rel_name
operator|=
literal|".rela.sdata2"
expr_stmt|;
name|defaults
operator|.
name|bss_name
operator|=
literal|".sbss2"
expr_stmt|;
name|defaults
operator|.
name|sym_name
operator|=
literal|"_SDA2_BASE_"
expr_stmt|;
name|defaults
operator|.
name|sym_offset
operator|=
literal|32768
expr_stmt|;
name|defaults
operator|.
name|flags
operator||=
name|SEC_READONLY
expr_stmt|;
break|break;
block|}
name|lsect
operator|=
name|_bfd_elf_create_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|which
argument_list|,
operator|&
name|defaults
argument_list|)
expr_stmt|;
block|}
return|return
name|lsect
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* If we have a non-zero sized .sbss2 or .PPC.EMB.sbss0 sections, we need to bump up    the number of section headers.  */
end_comment

begin_function
specifier|static
name|int
name|ppc_elf_additional_program_headers
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|asection
modifier|*
name|s
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
literal|".sbss2"
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
operator|&&
operator|(
name|s
operator|->
name|flags
operator|&
name|SEC_LOAD
operator|)
operator|!=
literal|0
operator|&&
name|s
operator|->
name|_raw_size
operator|>
literal|0
condition|)
operator|++
name|ret
expr_stmt|;
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
literal|".PPC.EMB.sbss0"
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
operator|&&
operator|(
name|s
operator|->
name|flags
operator|&
name|SEC_LOAD
operator|)
operator|!=
literal|0
operator|&&
name|s
operator|->
name|_raw_size
operator|>
literal|0
condition|)
operator|++
name|ret
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* Modify the segment map if needed */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_modify_segment_map
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Adjust a symbol defined by a dynamic object and referenced by a    regular object.  The current definition is in some section of the    dynamic object, but we're not including those sections.  We have to    change the definition to something the rest of the link can    understand.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_adjust_dynamic_symbol
parameter_list|(
name|info
parameter_list|,
name|h
parameter_list|)
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
block|{
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_adjust_dynamic_symbol called\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Increment the index of a dynamic symbol by a given amount.  Called    via elf_link_hash_traverse.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_adjust_dynindx
parameter_list|(
name|h
parameter_list|,
name|cparg
parameter_list|)
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|PTR
name|cparg
decl_stmt|;
block|{
name|int
modifier|*
name|cp
init|=
operator|(
name|int
operator|*
operator|)
name|cparg
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_adjust_dynindx called, h->dynindx = %d, *cp = %d\n"
argument_list|,
name|h
operator|->
name|dynindx
argument_list|,
operator|*
name|cp
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|h
operator|->
name|dynindx
operator|!=
operator|-
literal|1
condition|)
name|h
operator|->
name|dynindx
operator|+=
operator|*
name|cp
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Set the sizes of the dynamic sections.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_size_dynamic_sections
parameter_list|(
name|output_bfd
parameter_list|,
name|info
parameter_list|)
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
block|{
name|bfd
modifier|*
name|dynobj
decl_stmt|;
name|asection
modifier|*
name|s
decl_stmt|;
name|boolean
name|reltext
decl_stmt|;
name|boolean
name|relplt
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_size_dynamic_sections called\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dynobj
operator|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|dynobj
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynamic_sections_created
condition|)
block|{
comment|/* Set the contents of the .interp section to the interpreter.  */
if|if
condition|(
operator|!
name|info
operator|->
name|shared
condition|)
block|{
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".interp"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|s
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|s
operator|->
name|_raw_size
operator|=
sizeof|sizeof
name|ELF_DYNAMIC_INTERPRETER
expr_stmt|;
name|s
operator|->
name|contents
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|ELF_DYNAMIC_INTERPRETER
expr_stmt|;
block|}
comment|/* Make space for the trailing nop in .plt.  */
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".plt"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|s
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|_raw_size
operator|>
literal|0
condition|)
name|s
operator|->
name|_raw_size
operator|+=
literal|4
expr_stmt|;
block|}
else|else
block|{
comment|/* We may have created entries in the .rela.got, .rela.sdata, and 	 .rela.sdata2 section2.  However, if we are not creating the 	 dynamic sections, we will not actually use these entries.  Reset 	 the size of .rela.got, et al, which will cause it to get 	 stripped from the output file below.  */
specifier|static
name|char
modifier|*
name|rela_sections
index|[]
init|=
block|{
literal|".rela.got"
block|,
literal|".rela.sdata"
block|,
literal|".rela.sdata"
block|,
operator|(
name|char
operator|*
operator|)
literal|0
block|}
decl_stmt|;
name|char
modifier|*
modifier|*
name|p
decl_stmt|;
for|for
control|(
name|p
operator|=
name|rela_sections
init|;
operator|*
name|p
operator|!=
operator|(
name|char
operator|*
operator|)
literal|0
condition|;
name|p
operator|++
control|)
block|{
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
operator|*
name|p
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|!=
name|NULL
condition|)
name|s
operator|->
name|_raw_size
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/* The check_relocs and adjust_dynamic_symbol entry points have      determined the sizes of the various dynamic sections.  Allocate      memory for them.  */
name|reltext
operator|=
name|false
expr_stmt|;
name|relplt
operator|=
name|false
expr_stmt|;
for|for
control|(
name|s
operator|=
name|dynobj
operator|->
name|sections
init|;
name|s
operator|!=
name|NULL
condition|;
name|s
operator|=
name|s
operator|->
name|next
control|)
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|boolean
name|strip
decl_stmt|;
if|if
condition|(
operator|(
name|s
operator|->
name|flags
operator|&
name|SEC_IN_MEMORY
operator|)
operator|==
literal|0
condition|)
continue|continue;
comment|/* It's OK to base decisions on the section name, because none 	 of the dynobj section names depend upon the input files.  */
name|name
operator|=
name|bfd_get_section_name
argument_list|(
name|dynobj
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|strip
operator|=
name|false
expr_stmt|;
if|#
directive|if
literal|0
block|if (strncmp (name, ".rela", 5) == 0) 	{ 	  if (s->_raw_size == 0) 	    {
comment|/* If we don't need this section, strip it from the 		 output file.  This is to handle .rela.bss and 		 .rel.plt.  We must create it in 		 create_dynamic_sections, because it must be created 		 before the linker maps input sections to output 		 sections.  The linker does that before 		 adjust_dynamic_symbol is called, and it is that 		 function which decides whether anything needs to go 		 into these sections.  */
block|strip = true; 	    } 	  else 	    { 	      asection *target;
comment|/* If this relocation section applies to a read only 		 section, then we probably need a DT_TEXTREL entry.  */
block|target = bfd_get_section_by_name (output_bfd, name + 5); 	      if (target != NULL&& (target->flags& SEC_READONLY) != 0) 		reltext = true;  	      if (strcmp (name, ".rela.plt") == 0) 		relplt = true;
comment|/* We use the reloc_count field as a counter if we need 		 to copy relocs into the output file.  */
block|s->reloc_count = 0; 	    } 	}       else
endif|#
directive|endif
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".plt"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".got"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sdata"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sdata2"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".rela.sdata"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".rela.sdata2"
argument_list|)
operator|!=
literal|0
condition|)
block|{
comment|/* It's not one of our sections, so don't allocate space.  */
continue|continue;
block|}
if|if
condition|(
name|strip
condition|)
block|{
name|asection
modifier|*
modifier|*
name|spp
decl_stmt|;
for|for
control|(
name|spp
operator|=
operator|&
name|s
operator|->
name|output_section
operator|->
name|owner
operator|->
name|sections
init|;
operator|*
name|spp
operator|!=
name|s
operator|->
name|output_section
condition|;
name|spp
operator|=
operator|&
operator|(
operator|*
name|spp
operator|)
operator|->
name|next
control|)
empty_stmt|;
operator|*
name|spp
operator|=
name|s
operator|->
name|output_section
operator|->
name|next
expr_stmt|;
operator|--
name|s
operator|->
name|output_section
operator|->
name|owner
operator|->
name|section_count
expr_stmt|;
continue|continue;
block|}
comment|/* Allocate memory for the section contents.  */
name|s
operator|->
name|contents
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|bfd_zalloc
argument_list|(
name|dynobj
argument_list|,
name|s
operator|->
name|_raw_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|->
name|contents
operator|==
name|NULL
operator|&&
name|s
operator|->
name|_raw_size
operator|!=
literal|0
condition|)
return|return
name|false
return|;
block|}
if|if
condition|(
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynamic_sections_created
condition|)
block|{
comment|/* Add some entries to the .dynamic section.  We fill in the 	 values later, in ppc_elf_finish_dynamic_sections, but we 	 must add the entries now so that we get the correct size for 	 the .dynamic section.  The DT_DEBUG entry is filled in by the 	 dynamic linker and used by the debugger.  */
if|if
condition|(
operator|!
name|info
operator|->
name|shared
condition|)
block|{
if|if
condition|(
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_DEBUG
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|false
return|;
block|}
if|if
condition|(
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_PLTGOT
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|relplt
condition|)
block|{
if|if
condition|(
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_PLTRELSZ
argument_list|,
literal|0
argument_list|)
operator|||
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_PLTREL
argument_list|,
name|DT_RELA
argument_list|)
operator|||
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_JMPREL
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|false
return|;
block|}
if|if
condition|(
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_RELA
argument_list|,
literal|0
argument_list|)
operator|||
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_RELASZ
argument_list|,
literal|0
argument_list|)
operator|||
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_RELAENT
argument_list|,
sizeof|sizeof
argument_list|(
name|Elf32_External_Rela
argument_list|)
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|reltext
condition|)
block|{
if|if
condition|(
operator|!
name|bfd_elf32_add_dynamic_entry
argument_list|(
name|info
argument_list|,
name|DT_TEXTREL
argument_list|,
literal|0
argument_list|)
condition|)
return|return
name|false
return|;
block|}
block|}
comment|/* If we are generating a shared library, we generate a section      symbol for each output section.  These are local symbols, which      means that they must come first in the dynamic symbol table.      That means we must increment the dynamic symbol index of every      other dynamic symbol.  */
if|if
condition|(
name|info
operator|->
name|shared
condition|)
block|{
name|int
name|c
decl_stmt|,
name|i
decl_stmt|;
name|c
operator|=
name|bfd_count_sections
argument_list|(
name|output_bfd
argument_list|)
expr_stmt|;
name|elf_link_hash_traverse
argument_list|(
name|elf_hash_table
argument_list|(
name|info
argument_list|)
argument_list|,
name|ppc_elf_adjust_dynindx
argument_list|,
operator|(
name|PTR
operator|)
operator|&
name|c
argument_list|)
expr_stmt|;
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynsymcount
operator|+=
name|c
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
operator|,
name|s
operator|=
name|output_bfd
operator|->
name|sections
init|;
name|s
operator|!=
name|NULL
condition|;
name|s
operator|=
name|s
operator|->
name|next
operator|,
name|i
operator|++
control|)
block|{
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|dynindx
operator|=
name|i
expr_stmt|;
comment|/* These symbols will have no names, so we don't need to              fiddle with dynstr_index.  */
block|}
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Look through the relocs for a section during the first phase, and    allocate space in the global offset table or procedure linkage    table.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_check_relocs
parameter_list|(
name|abfd
parameter_list|,
name|info
parameter_list|,
name|sec
parameter_list|,
name|relocs
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|relocs
decl_stmt|;
block|{
name|bfd
modifier|*
name|dynobj
decl_stmt|;
name|Elf_Internal_Shdr
modifier|*
name|symtab_hdr
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|rel
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|rel_end
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|got
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|sdata
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|sdata2
decl_stmt|;
name|asection
modifier|*
name|sreloc
decl_stmt|;
if|if
condition|(
name|info
operator|->
name|relocateable
condition|)
return|return
name|true
return|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_check_relocs called for section %s\n"
argument_list|,
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Create the linker generated sections all the time so that the special      symbols are created.  */
if|if
condition|(
operator|(
name|got
operator|=
name|elf_linker_section
argument_list|(
name|abfd
argument_list|,
name|LINKER_SECTION_GOT
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|got
operator|=
name|ppc_elf_create_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|LINKER_SECTION_GOT
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|got
condition|)
return|return
name|false
return|;
block|}
if|if
condition|(
operator|(
name|sdata
operator|=
name|elf_linker_section
argument_list|(
name|abfd
argument_list|,
name|LINKER_SECTION_SDATA
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|sdata
operator|=
name|ppc_elf_create_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|LINKER_SECTION_SDATA
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sdata
condition|)
return|return
name|false
return|;
block|}
if|if
condition|(
operator|(
name|sdata2
operator|=
name|elf_linker_section
argument_list|(
name|abfd
argument_list|,
name|LINKER_SECTION_SDATA2
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|sdata2
operator|=
name|ppc_elf_create_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|LINKER_SECTION_SDATA2
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|sdata2
condition|)
return|return
name|false
return|;
block|}
name|dynobj
operator|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
expr_stmt|;
name|symtab_hdr
operator|=
operator|&
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|symtab_hdr
expr_stmt|;
name|sym_hashes
operator|=
name|elf_sym_hashes
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|sreloc
operator|=
name|NULL
expr_stmt|;
name|rel_end
operator|=
name|relocs
operator|+
name|sec
operator|->
name|reloc_count
expr_stmt|;
for|for
control|(
name|rel
operator|=
name|relocs
init|;
name|rel
operator|<
name|rel_end
condition|;
name|rel
operator|++
control|)
block|{
name|unsigned
name|long
name|r_symndx
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|r_symndx
operator|=
name|ELF32_R_SYM
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
expr_stmt|;
if|if
condition|(
name|r_symndx
operator|<
name|symtab_hdr
operator|->
name|sh_info
condition|)
name|h
operator|=
name|NULL
expr_stmt|;
else|else
name|h
operator|=
name|sym_hashes
index|[
name|r_symndx
operator|-
name|symtab_hdr
operator|->
name|sh_info
index|]
expr_stmt|;
switch|switch
condition|(
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
condition|)
block|{
default|default:
break|break;
comment|/* GOT16 relocations */
case|case
name|R_PPC_GOT16
case|:
case|case
name|R_PPC_GOT16_LO
case|:
case|case
name|R_PPC_GOT16_HI
case|:
case|case
name|R_PPC_GOT16_HA
case|:
if|if
condition|(
name|got
operator|->
name|rel_section
operator|==
name|NULL
operator|&&
operator|(
name|h
operator|!=
name|NULL
operator|||
name|info
operator|->
name|shared
operator|)
operator|&&
operator|!
name|_bfd_elf_make_linker_section_rela
argument_list|(
name|dynobj
argument_list|,
name|got
argument_list|,
literal|2
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|bfd_elf32_create_pointer_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|got
argument_list|,
name|h
argument_list|,
name|rel
argument_list|)
condition|)
return|return
name|false
return|;
break|break;
comment|/* Indirect .sdata relocation */
case|case
name|R_PPC_EMB_SDAI16
case|:
if|if
condition|(
name|got
operator|->
name|rel_section
operator|==
name|NULL
operator|&&
operator|(
name|h
operator|!=
name|NULL
operator|||
name|info
operator|->
name|shared
operator|)
operator|&&
operator|!
name|_bfd_elf_make_linker_section_rela
argument_list|(
name|dynobj
argument_list|,
name|got
argument_list|,
literal|2
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|bfd_elf32_create_pointer_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|sdata
argument_list|,
name|h
argument_list|,
name|rel
argument_list|)
condition|)
return|return
name|false
return|;
break|break;
comment|/* Indirect .sdata2 relocation */
case|case
name|R_PPC_EMB_SDA2I16
case|:
if|if
condition|(
name|got
operator|->
name|rel_section
operator|==
name|NULL
operator|&&
operator|(
name|h
operator|!=
name|NULL
operator|||
name|info
operator|->
name|shared
operator|)
operator|&&
operator|!
name|_bfd_elf_make_linker_section_rela
argument_list|(
name|dynobj
argument_list|,
name|got
argument_list|,
literal|2
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
operator|!
name|bfd_elf32_create_pointer_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|sdata2
argument_list|,
name|h
argument_list|,
name|rel
argument_list|)
condition|)
return|return
name|false
return|;
break|break;
if|#
directive|if
literal|0
block|case R_PPC_PLT32: 	case R_PPC_PLTREL24: 	case R_PPC_PLT16_LO: 	case R_PPC_PLT16_HI: 	case R_PPC_PLT16_HA:
ifdef|#
directive|ifdef
name|DEBUG
block|fprintf (stderr, "Reloc requires a PLT entry\n");
endif|#
directive|endif
comment|/* This symbol requires a procedure linkage table entry.  We              actually build the entry in adjust_dynamic_symbol,              because this might be a case of linking PIC code without              linking in any dynamic objects, in which case we don't              need to generate a procedure linkage table after all.  */
block|if (h == NULL) 	    {
comment|/* It does not make sense to have a procedure linkage                  table entry for a local symbol.  */
block|bfd_set_error (bfd_error_bad_value); 	      return false; 	    }
comment|/* Make sure this symbol is output as a dynamic symbol.  */
block|if (h->dynindx == -1) 	    { 	      if (! bfd_elf32_link_record_dynamic_symbol (info, h)) 		return false; 	    }  	  h->elf_link_hash_flags |= ELF_LINK_HASH_NEEDS_PLT; 	  break;  	case R_SPARC_PC10: 	case R_SPARC_PC22: 	  if (h != NULL&& strcmp (h->root.root.string, "_GLOBAL_OFFSET_TABLE_") == 0) 	    break;
comment|/* Fall through.  */
block|case R_SPARC_DISP8: 	case R_SPARC_DISP16: 	case R_SPARC_DISP32: 	case R_SPARC_WDISP30: 	case R_SPARC_WDISP22: 	  if (h == NULL) 	    break;
comment|/* Fall through.  */
block|case R_SPARC_8: 	case R_SPARC_16: 	case R_SPARC_32: 	case R_SPARC_HI22: 	case R_SPARC_22: 	case R_SPARC_13: 	case R_SPARC_LO10: 	case R_SPARC_UA32: 	  if (info->shared&& (sec->flags& SEC_ALLOC) != 0) 	    {
comment|/* When creating a shared object, we must copy these                  relocs into the output file.  We create a reloc                  section in dynobj and make room for the reloc.  */
block|if (sreloc == NULL) 		{ 		  const char *name;  		  name = (bfd_elf_string_from_elf_section 			  (abfd, 			   elf_elfheader (abfd)->e_shstrndx, 			   elf_section_data (sec)->rel_hdr.sh_name)); 		  if (name == NULL) 		    return false;  		  BFD_ASSERT (strncmp (name, ".rela", 5) == 0&& strcmp (bfd_get_section_name (abfd, sec), 					 name + 5) == 0);  		  sreloc = bfd_get_section_by_name (dynobj, name); 		  if (sreloc == NULL) 		    { 		      sreloc = bfd_make_section (dynobj, name); 		      if (sreloc == NULL 			  || ! bfd_set_section_flags (dynobj, sreloc, 						      (SEC_ALLOC 						       | SEC_LOAD 						       | SEC_HAS_CONTENTS 						       | SEC_IN_MEMORY 						       | SEC_READONLY)) 			  || ! bfd_set_section_alignment (dynobj, sreloc, 2)) 			return false; 		    } 		}  	      sreloc->_raw_size += sizeof (Elf32_External_Rela); 	    }  	  break;
endif|#
directive|endif
block|}
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Hook called by the linker routine which adds symbols from an object    file.  We use it to put .comm items in .sbss, and not .bss.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_add_symbol_hook
parameter_list|(
name|abfd
parameter_list|,
name|info
parameter_list|,
name|sym
parameter_list|,
name|namep
parameter_list|,
name|flagsp
parameter_list|,
name|secp
parameter_list|,
name|valp
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
specifier|const
name|Elf_Internal_Sym
modifier|*
name|sym
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|namep
decl_stmt|;
name|flagword
modifier|*
name|flagsp
decl_stmt|;
name|asection
modifier|*
modifier|*
name|secp
decl_stmt|;
name|bfd_vma
modifier|*
name|valp
decl_stmt|;
block|{
if|if
condition|(
name|sym
operator|->
name|st_shndx
operator|==
name|SHN_COMMON
operator|&&
name|sym
operator|->
name|st_size
operator|<=
name|bfd_get_gp_size
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
comment|/* Common symbols less than or equal to -G nn bytes are automatically 	 put into .sdata.  */
name|elf_linker_section_t
modifier|*
name|sdata
init|=
name|ppc_elf_create_linker_section
argument_list|(
name|abfd
argument_list|,
name|info
argument_list|,
name|LINKER_SECTION_SDATA
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|sdata
operator|->
name|bss_section
condition|)
block|{
name|sdata
operator|->
name|bss_section
operator|=
name|bfd_make_section
argument_list|(
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
argument_list|,
name|sdata
operator|->
name|bss_name
argument_list|)
expr_stmt|;
name|sdata
operator|->
name|bss_section
operator|->
name|flags
operator|=
operator|(
name|sdata
operator|->
name|bss_section
operator|->
name|flags
operator|&
operator|~
name|SEC_LOAD
operator|)
operator||
name|SEC_IS_COMMON
expr_stmt|;
block|}
operator|*
name|secp
operator|=
name|sdata
operator|->
name|bss_section
expr_stmt|;
operator|*
name|valp
operator|=
name|sym
operator|->
name|st_size
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Finish up dynamic symbol handling.  We set the contents of various    dynamic sections here.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_finish_dynamic_symbol
parameter_list|(
name|output_bfd
parameter_list|,
name|info
parameter_list|,
name|h
parameter_list|,
name|sym
parameter_list|)
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|Elf_Internal_Sym
modifier|*
name|sym
decl_stmt|;
block|{
name|bfd
modifier|*
name|dynobj
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_finish_dynamic_symbol called for %s\n"
argument_list|,
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|dynobj
operator|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|dynobj
operator|!=
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|h
operator|->
name|plt_offset
operator|!=
operator|(
name|bfd_vma
operator|)
operator|-
literal|1
condition|)
block|{
name|asection
modifier|*
name|splt
decl_stmt|;
name|asection
modifier|*
name|srela
decl_stmt|;
name|Elf_Internal_Rela
name|rela
decl_stmt|;
comment|/* This symbol has an entry in the procedure linkage table.  Set          it up.  */
name|BFD_ASSERT
argument_list|(
name|h
operator|->
name|dynindx
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|splt
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".plt"
argument_list|)
expr_stmt|;
name|srela
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".rela.plt"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|splt
operator|!=
name|NULL
operator|&&
name|srela
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* Fill in the entry in the procedure linkage table.  */
if|#
directive|if
literal|0
block|bfd_put_32 (output_bfd, 		  PLT_ENTRY_WORD0 + h->plt_offset, 		  splt->contents + h->plt_offset);       bfd_put_32 (output_bfd, 		  (PLT_ENTRY_WORD1 		   + (((- (h->plt_offset + 4))>> 2)& 0x3fffff)), 		  splt->contents + h->plt_offset + 4);       bfd_put_32 (output_bfd, PLT_ENTRY_WORD2, 		  splt->contents + h->plt_offset + 8);
comment|/* Fill in the entry in the .rela.plt section.  */
block|rela.r_offset = (splt->output_section->vma 		       + splt->output_offset 		       + h->plt_offset);       rela.r_info = ELF32_R_INFO (h->dynindx, R_SPARC_JMP_SLOT);       rela.r_addend = 0;       bfd_elf32_swap_reloca_out (output_bfd,&rela, 				 ((Elf32_External_Rela *) srela->contents 				  + h->plt_offset / PLT_ENTRY_SIZE - 4));
endif|#
directive|endif
if|if
condition|(
operator|(
name|h
operator|->
name|elf_link_hash_flags
operator|&
name|ELF_LINK_HASH_DEF_REGULAR
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* Mark the symbol as undefined, rather than as defined in 	     the .plt section.  Leave the value alone.  */
name|sym
operator|->
name|st_shndx
operator|=
name|SHN_UNDEF
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|(
name|h
operator|->
name|elf_link_hash_flags
operator|&
name|ELF_LINK_HASH_NEEDS_COPY
operator|)
operator|!=
literal|0
condition|)
block|{
name|asection
modifier|*
name|s
decl_stmt|;
name|Elf_Internal_Rela
name|rela
decl_stmt|;
comment|/* This symbols needs a copy reloc.  Set it up.  */
name|BFD_ASSERT
argument_list|(
name|h
operator|->
name|dynindx
operator|!=
operator|-
literal|1
argument_list|)
expr_stmt|;
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|owner
argument_list|,
literal|".rela.bss"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|s
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|rela
operator|.
name|r_offset
operator|=
operator|(
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
name|rela
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|h
operator|->
name|dynindx
argument_list|,
name|R_PPC_COPY
argument_list|)
expr_stmt|;
name|rela
operator|.
name|r_addend
operator|=
literal|0
expr_stmt|;
name|bfd_elf32_swap_reloca_out
argument_list|(
name|output_bfd
argument_list|,
operator|&
name|rela
argument_list|,
operator|(
operator|(
name|Elf32_External_Rela
operator|*
operator|)
name|s
operator|->
name|contents
operator|+
name|s
operator|->
name|reloc_count
operator|)
argument_list|)
expr_stmt|;
operator|++
name|s
operator|->
name|reloc_count
expr_stmt|;
block|}
comment|/* Mark some specially defined symbols as absolute.  */
if|if
condition|(
name|strcmp
argument_list|(
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
argument_list|,
literal|"_DYNAMIC"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
argument_list|,
literal|"_GLOBAL_OFFSET_TABLE_"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
argument_list|,
literal|"_PROCEDURE_LINKAGE_TABLE_"
argument_list|)
operator|==
literal|0
condition|)
name|sym
operator|->
name|st_shndx
operator|=
name|SHN_ABS
expr_stmt|;
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Finish up the dynamic sections.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_finish_dynamic_sections
parameter_list|(
name|output_bfd
parameter_list|,
name|info
parameter_list|)
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
block|{
name|asection
modifier|*
name|sdyn
decl_stmt|;
name|bfd
modifier|*
name|dynobj
init|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|got
init|=
name|elf_linker_section
argument_list|(
name|dynobj
argument_list|,
name|LINKER_SECTION_GOT
argument_list|)
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_finish_dynamic_sections called\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|sdyn
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".dynamic"
argument_list|)
expr_stmt|;
if|if
condition|(
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynamic_sections_created
condition|)
block|{
name|asection
modifier|*
name|splt
decl_stmt|;
name|Elf32_External_Dyn
modifier|*
name|dyncon
decl_stmt|,
modifier|*
name|dynconend
decl_stmt|;
name|splt
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".plt"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|splt
operator|!=
name|NULL
operator|&&
name|sdyn
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|dyncon
operator|=
operator|(
name|Elf32_External_Dyn
operator|*
operator|)
name|sdyn
operator|->
name|contents
expr_stmt|;
name|dynconend
operator|=
operator|(
name|Elf32_External_Dyn
operator|*
operator|)
operator|(
name|sdyn
operator|->
name|contents
operator|+
name|sdyn
operator|->
name|_raw_size
operator|)
expr_stmt|;
for|for
control|(
init|;
name|dyncon
operator|<
name|dynconend
condition|;
name|dyncon
operator|++
control|)
block|{
name|Elf_Internal_Dyn
name|dyn
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|boolean
name|size
decl_stmt|;
name|bfd_elf32_swap_dyn_in
argument_list|(
name|dynobj
argument_list|,
name|dyncon
argument_list|,
operator|&
name|dyn
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|dyn
operator|.
name|d_tag
condition|)
block|{
case|case
name|DT_PLTGOT
case|:
name|name
operator|=
literal|".plt"
expr_stmt|;
name|size
operator|=
name|false
expr_stmt|;
break|break;
case|case
name|DT_PLTRELSZ
case|:
name|name
operator|=
literal|".rela.plt"
expr_stmt|;
name|size
operator|=
name|true
expr_stmt|;
break|break;
case|case
name|DT_JMPREL
case|:
name|name
operator|=
literal|".rela.plt"
expr_stmt|;
name|size
operator|=
name|false
expr_stmt|;
break|break;
default|default:
name|name
operator|=
name|NULL
expr_stmt|;
name|size
operator|=
name|false
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|name
operator|!=
name|NULL
condition|)
block|{
name|asection
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|bfd_get_section_by_name
argument_list|(
name|output_bfd
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
name|dyn
operator|.
name|d_un
operator|.
name|d_val
operator|=
literal|0
expr_stmt|;
else|else
block|{
if|if
condition|(
operator|!
name|size
condition|)
name|dyn
operator|.
name|d_un
operator|.
name|d_ptr
operator|=
name|s
operator|->
name|vma
expr_stmt|;
else|else
block|{
if|if
condition|(
name|s
operator|->
name|_cooked_size
operator|!=
literal|0
condition|)
name|dyn
operator|.
name|d_un
operator|.
name|d_val
operator|=
name|s
operator|->
name|_cooked_size
expr_stmt|;
else|else
name|dyn
operator|.
name|d_un
operator|.
name|d_val
operator|=
name|s
operator|->
name|_raw_size
expr_stmt|;
block|}
block|}
name|bfd_elf32_swap_dyn_out
argument_list|(
name|output_bfd
argument_list|,
operator|&
name|dyn
argument_list|,
name|dyncon
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/* Add a blrl instruction at _GLOBAL_OFFSET_TABLE_-4 so that a function can      easily find the address of the _GLOBAL_OFFSET_TABLE_.  */
if|if
condition|(
name|got
condition|)
block|{
name|unsigned
name|char
modifier|*
name|contents
init|=
name|got
operator|->
name|section
operator|->
name|contents
operator|+
name|got
operator|->
name|hole_offset
decl_stmt|;
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
literal|0x4e800021
comment|/* blrl */
argument_list|,
name|contents
argument_list|)
expr_stmt|;
if|if
condition|(
name|sdyn
operator|==
name|NULL
condition|)
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
operator|(
name|bfd_vma
operator|)
literal|0
argument_list|,
name|contents
operator|+
literal|4
argument_list|)
expr_stmt|;
else|else
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
name|sdyn
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sdyn
operator|->
name|output_offset
argument_list|,
name|contents
operator|+
literal|4
argument_list|)
expr_stmt|;
name|elf_section_data
argument_list|(
name|got
operator|->
name|section
operator|->
name|output_section
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_entsize
operator|=
literal|4
expr_stmt|;
block|}
if|if
condition|(
name|info
operator|->
name|shared
condition|)
block|{
name|asection
modifier|*
name|sdynsym
decl_stmt|;
name|asection
modifier|*
name|s
decl_stmt|;
name|Elf_Internal_Sym
name|sym
decl_stmt|;
comment|/* Set up the section symbols for the output sections.  */
name|sdynsym
operator|=
name|bfd_get_section_by_name
argument_list|(
name|dynobj
argument_list|,
literal|".dynsym"
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|sdynsym
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|sym
operator|.
name|st_size
operator|=
literal|0
expr_stmt|;
name|sym
operator|.
name|st_name
operator|=
literal|0
expr_stmt|;
name|sym
operator|.
name|st_info
operator|=
name|ELF_ST_INFO
argument_list|(
name|STB_LOCAL
argument_list|,
name|STT_SECTION
argument_list|)
expr_stmt|;
name|sym
operator|.
name|st_other
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|s
operator|=
name|output_bfd
operator|->
name|sections
init|;
name|s
operator|!=
name|NULL
condition|;
name|s
operator|=
name|s
operator|->
name|next
control|)
block|{
name|int
name|indx
decl_stmt|;
name|sym
operator|.
name|st_value
operator|=
name|s
operator|->
name|vma
expr_stmt|;
name|indx
operator|=
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|this_idx
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|indx
operator|>
literal|0
argument_list|)
expr_stmt|;
name|sym
operator|.
name|st_shndx
operator|=
name|indx
expr_stmt|;
name|bfd_elf32_swap_symbol_out
argument_list|(
name|output_bfd
argument_list|,
operator|&
name|sym
argument_list|,
call|(
name|PTR
call|)
argument_list|(
operator|(
operator|(
name|Elf32_External_Sym
operator|*
operator|)
name|sdynsym
operator|->
name|contents
operator|)
operator|+
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|dynindx
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/* Set the sh_info field of the output .dynsym section to the          index of the first global symbol.  */
name|elf_section_data
argument_list|(
name|sdynsym
operator|->
name|output_section
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_info
operator|=
name|bfd_count_sections
argument_list|(
name|output_bfd
argument_list|)
operator|+
literal|1
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* The RELOCATE_SECTION function is called by the ELF backend linker    to handle the relocations for a section.     The relocs are always passed as Rela structures; if the section    actually uses Rel structures, the r_addend field will always be    zero.     This function is responsible for adjust the section contents as    necessary, and (if using Rela relocs and generating a    relocateable output file) adjusting the reloc addend as    necessary.     This function does not have to worry about setting the reloc    address or the reloc symbol index.     LOCAL_SYMS is a pointer to the swapped in local symbols.     LOCAL_SECTIONS is an array giving the section in the input file    corresponding to the st_shndx field of each local symbol.     The global hash table entry for the global symbols can be found    via elf_sym_hashes (input_bfd).     When generating relocateable output, this function must handle    STB_LOCAL/STT_SECTION symbols specially.  The output symbol is    going to be the section symbol corresponding to the output    section, which means that the addend must be adjusted    accordingly.  */
end_comment

begin_function
specifier|static
name|boolean
name|ppc_elf_relocate_section
parameter_list|(
name|output_bfd
parameter_list|,
name|info
parameter_list|,
name|input_bfd
parameter_list|,
name|input_section
parameter_list|,
name|contents
parameter_list|,
name|relocs
parameter_list|,
name|local_syms
parameter_list|,
name|local_sections
parameter_list|)
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|bfd
modifier|*
name|input_bfd
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd_byte
modifier|*
name|contents
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|relocs
decl_stmt|;
name|Elf_Internal_Sym
modifier|*
name|local_syms
decl_stmt|;
name|asection
modifier|*
modifier|*
name|local_sections
decl_stmt|;
block|{
name|Elf_Internal_Shdr
modifier|*
name|symtab_hdr
init|=
operator|&
name|elf_tdata
argument_list|(
name|input_bfd
argument_list|)
operator|->
name|symtab_hdr
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
init|=
name|elf_sym_hashes
argument_list|(
name|input_bfd
argument_list|)
decl_stmt|;
name|bfd
modifier|*
name|dynobj
init|=
name|elf_hash_table
argument_list|(
name|info
argument_list|)
operator|->
name|dynobj
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|got
init|=
operator|(
name|dynobj
operator|)
condition|?
name|elf_linker_section
argument_list|(
name|dynobj
argument_list|,
name|LINKER_SECTION_GOT
argument_list|)
else|:
name|NULL
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|sdata
init|=
operator|(
name|dynobj
operator|)
condition|?
name|elf_linker_section
argument_list|(
name|dynobj
argument_list|,
name|LINKER_SECTION_SDATA
argument_list|)
else|:
name|NULL
decl_stmt|;
name|elf_linker_section_t
modifier|*
name|sdata2
init|=
operator|(
name|dynobj
operator|)
condition|?
name|elf_linker_section
argument_list|(
name|dynobj
argument_list|,
name|LINKER_SECTION_SDATA2
argument_list|)
else|:
name|NULL
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|rel
init|=
name|relocs
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|relend
init|=
name|relocs
operator|+
name|input_section
operator|->
name|reloc_count
decl_stmt|;
name|boolean
name|ret
init|=
name|true
decl_stmt|;
name|long
name|insn
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ppc_elf_relocate_section called for %s section %s, %ld relocations%s\n"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
name|bfd_section_name
argument_list|(
name|input_bfd
argument_list|,
name|input_section
argument_list|)
argument_list|,
operator|(
name|long
operator|)
name|input_section
operator|->
name|reloc_count
argument_list|,
operator|(
name|info
operator|->
name|relocateable
operator|)
condition|?
literal|" (relocatable)"
else|:
literal|""
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|ppc_elf_howto_table
index|[
name|R_PPC_ADDR32
index|]
condition|)
comment|/* Initialize howto table if needed */
name|ppc_elf_howto_init
argument_list|()
expr_stmt|;
for|for
control|(
init|;
name|rel
operator|<
name|relend
condition|;
name|rel
operator|++
control|)
block|{
name|enum
name|ppc_reloc_type
name|r_type
init|=
operator|(
expr|enum
name|ppc_reloc_type
operator|)
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
decl_stmt|;
name|bfd_vma
name|offset
init|=
name|rel
operator|->
name|r_offset
decl_stmt|;
name|bfd_vma
name|addend
init|=
name|rel
operator|->
name|r_addend
decl_stmt|;
name|bfd_reloc_status_type
name|r
init|=
name|bfd_reloc_other
decl_stmt|;
name|Elf_Internal_Sym
modifier|*
name|sym
init|=
operator|(
name|Elf_Internal_Sym
operator|*
operator|)
literal|0
decl_stmt|;
name|asection
modifier|*
name|sec
init|=
operator|(
name|asection
operator|*
operator|)
literal|0
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
init|=
operator|(
expr|struct
name|elf_link_hash_entry
operator|*
operator|)
literal|0
decl_stmt|;
specifier|const
name|char
modifier|*
name|sym_name
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
literal|0
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|unsigned
name|long
name|r_symndx
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
comment|/* Unknown relocation handling */
if|if
condition|(
operator|(
name|unsigned
operator|)
name|r_type
operator|>=
operator|(
name|unsigned
operator|)
name|R_PPC_max
operator|||
operator|!
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: unknown relocation type %d"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|r_type
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
name|howto
operator|=
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
expr_stmt|;
name|r_symndx
operator|=
name|ELF32_R_SYM
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|->
name|relocateable
condition|)
block|{
comment|/* This is a relocateable link.  We don't have to change 	     anything, unless the reloc is against a section symbol, 	     in which case we have to adjust according to where the 	     section symbol winds up in the output section.  */
if|if
condition|(
name|r_symndx
operator|<
name|symtab_hdr
operator|->
name|sh_info
condition|)
block|{
name|sym
operator|=
name|local_syms
operator|+
name|r_symndx
expr_stmt|;
if|if
condition|(
operator|(
name|unsigned
operator|)
name|ELF_ST_TYPE
argument_list|(
name|sym
operator|->
name|st_info
argument_list|)
operator|==
name|STT_SECTION
condition|)
block|{
name|sec
operator|=
name|local_sections
index|[
name|r_symndx
index|]
expr_stmt|;
name|addend
operator|=
name|rel
operator|->
name|r_addend
operator|+=
name|sec
operator|->
name|output_offset
operator|+
name|sym
operator|->
name|st_value
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\ttype = %s (%d), symbol index = %ld, offset = %ld, addend = %ld\n"
argument_list|,
name|howto
operator|->
name|name
argument_list|,
operator|(
name|int
operator|)
name|r_type
argument_list|,
name|r_symndx
argument_list|,
operator|(
name|long
operator|)
name|offset
argument_list|,
operator|(
name|long
operator|)
name|addend
argument_list|)
expr_stmt|;
endif|#
directive|endif
continue|continue;
block|}
comment|/* This is a final link.  */
if|if
condition|(
name|r_symndx
operator|<
name|symtab_hdr
operator|->
name|sh_info
condition|)
block|{
name|sym
operator|=
name|local_syms
operator|+
name|r_symndx
expr_stmt|;
name|sec
operator|=
name|local_sections
index|[
name|r_symndx
index|]
expr_stmt|;
name|sym_name
operator|=
literal|"<local symbol>"
expr_stmt|;
name|relocation
operator|=
operator|(
name|sec
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sec
operator|->
name|output_offset
operator|+
name|sym
operator|->
name|st_value
operator|)
expr_stmt|;
block|}
else|else
block|{
name|h
operator|=
name|sym_hashes
index|[
name|r_symndx
operator|-
name|symtab_hdr
operator|->
name|sh_info
index|]
expr_stmt|;
while|while
condition|(
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_indirect
operator|||
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_warning
condition|)
name|h
operator|=
operator|(
expr|struct
name|elf_link_hash_entry
operator|*
operator|)
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|i
operator|.
name|link
expr_stmt|;
name|sym_name
operator|=
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
expr_stmt|;
if|if
condition|(
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_defined
operator|||
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_defweak
condition|)
block|{
name|sec
operator|=
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
expr_stmt|;
name|relocation
operator|=
operator|(
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|sec
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sec
operator|->
name|output_offset
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_undefweak
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|info
operator|->
name|shared
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
else|else
block|{
call|(
modifier|*
name|info
operator|->
name|callbacks
operator|->
name|undefined_symbol
call|)
argument_list|(
name|info
argument_list|,
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
block|}
switch|switch
condition|(
operator|(
name|int
operator|)
name|r_type
condition|)
block|{
default|default:
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: unknown relocation type %d for symbol %s"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
operator|(
name|int
operator|)
name|r_type
argument_list|,
name|sym_name
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
comment|/* relocations that need no special processing */
case|case
operator|(
name|int
operator|)
name|R_PPC_NONE
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR32
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR24
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR16
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR16_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR16_HI
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR14
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_REL24
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_REL14
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_UADDR32
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_UADDR16
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_REL32
case|:
break|break;
comment|/* branch taken prediction relocations */
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR14_BRTAKEN
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_REL14_BRTAKEN
case|:
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|output_bfd
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|relocation
operator|-
name|offset
operator|)
operator|&
literal|0x8000
condition|)
name|insn
operator|&=
operator|~
name|BRANCH_PREDICT_BIT
expr_stmt|;
else|else
name|insn
operator||=
name|BRANCH_PREDICT_BIT
expr_stmt|;
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
break|break;
comment|/* branch not taken predicition relocations */
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR14_BRNTAKEN
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_REL14_BRNTAKEN
case|:
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|output_bfd
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|relocation
operator|-
name|offset
operator|)
operator|&
literal|0x8000
condition|)
name|insn
operator||=
name|BRANCH_PREDICT_BIT
expr_stmt|;
else|else
name|insn
operator|&=
operator|~
name|BRANCH_PREDICT_BIT
expr_stmt|;
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
break|break;
comment|/* GOT16 relocations */
case|case
operator|(
name|int
operator|)
name|R_PPC_GOT16
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_GOT16_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_GOT16_HI
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_GOT16_HA
case|:
name|relocation
operator|=
name|bfd_elf32_finish_pointer_linker_section
argument_list|(
name|output_bfd
argument_list|,
name|input_bfd
argument_list|,
name|info
argument_list|,
name|got
argument_list|,
name|h
argument_list|,
name|relocation
argument_list|,
name|rel
argument_list|,
name|R_PPC_RELATIVE
argument_list|)
expr_stmt|;
break|break;
comment|/* Indirect .sdata relocation */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_SDAI16
case|:
name|BFD_ASSERT
argument_list|(
name|sdata
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|relocation
operator|=
name|bfd_elf32_finish_pointer_linker_section
argument_list|(
name|output_bfd
argument_list|,
name|input_bfd
argument_list|,
name|info
argument_list|,
name|sdata
argument_list|,
name|h
argument_list|,
name|relocation
argument_list|,
name|rel
argument_list|,
name|R_PPC_RELATIVE
argument_list|)
expr_stmt|;
break|break;
comment|/* Indirect .sdata2 relocation */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_SDA2I16
case|:
name|BFD_ASSERT
argument_list|(
name|sdata2
operator|!=
name|NULL
argument_list|)
expr_stmt|;
name|relocation
operator|=
name|bfd_elf32_finish_pointer_linker_section
argument_list|(
name|output_bfd
argument_list|,
name|input_bfd
argument_list|,
name|info
argument_list|,
name|sdata2
argument_list|,
name|h
argument_list|,
name|relocation
argument_list|,
name|rel
argument_list|,
name|R_PPC_RELATIVE
argument_list|)
expr_stmt|;
break|break;
comment|/* Handle the TOC16 reloc.  We want to use the offset within the .got 	   section, not the actual VMA.  This is appropriate when generating 	   an embedded ELF object, for which the .got section acts like the 	   AIX .toc section.  */
case|case
operator|(
name|int
operator|)
name|R_PPC_TOC16
case|:
comment|/* phony GOT16 relocations */
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
argument|bfd_is_und_section (sec) 		      || strcmp (bfd_get_section_name (abfd, sec),
literal|".got"
argument|) ==
literal|0
argument||| strcmp (bfd_get_section_name (abfd, sec),
literal|".cgot"
argument|) ==
literal|0
argument_list|)
name|addend
operator|-=
name|sec
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sec
operator|->
name|output_offset
operator|+
literal|0x8000
expr_stmt|;
break|break;
comment|/* arithmetic adjust relocations */
case|case
operator|(
name|int
operator|)
name|R_PPC_ADDR16_HA
case|:
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|addend
operator|+=
operator|(
operator|(
name|relocation
operator|+
name|addend
operator|)
operator|&
literal|0x8000
operator|)
operator|<<
literal|1
expr_stmt|;
break|break;
comment|/* relocate against _SDA_BASE_ */
case|case
operator|(
name|int
operator|)
name|R_PPC_SDAREL16
case|:
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|,
literal|".sdata"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|,
literal|".sbss"
argument_list|)
operator|!=
literal|0
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: The target (%s) of a %s relocation is in the wrong section (%s)"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
name|sym_name
argument_list|,
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
operator|->
name|name
argument_list|,
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
name|addend
operator|-=
operator|(
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
break|break;
comment|/* relocate against _SDA2_BASE_ */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_SDA2REL
case|:
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|,
literal|".sdata2"
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|,
literal|".sbss2"
argument_list|)
operator|!=
literal|0
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: The target (%s) of a %s relocation is in the wrong section (%s)"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
name|sym_name
argument_list|,
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
operator|->
name|name
argument_list|,
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
name|addend
operator|-=
operator|(
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
break|break;
comment|/* relocate against either _SDA_BASE_, _SDA2_BASE_, or 0 */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_SDA21
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_RELSDA
case|:
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sdata"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sbss"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reg
operator|=
literal|13
expr_stmt|;
name|addend
operator|-=
operator|(
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sdata
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sdata2"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".sbss2"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reg
operator|=
literal|2
expr_stmt|;
name|addend
operator|-=
operator|(
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|value
operator|+
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|sdata2
operator|->
name|sym_hash
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".PPC.EMB.sdata0"
argument_list|)
operator|==
literal|0
operator|||
name|strcmp
argument_list|(
name|name
argument_list|,
literal|".PPC.EMB.sbss0"
argument_list|)
operator|==
literal|0
condition|)
block|{
name|reg
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: The target (%s) of a %s relocation is in the wrong section (%s)"
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
name|sym_name
argument_list|,
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
operator|->
name|name
argument_list|,
name|bfd_get_section_name
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|r_type
operator|==
name|R_PPC_EMB_SDA21
condition|)
block|{
comment|/* fill in register field */
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|output_bfd
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|RA_REGISTER_MASK
operator|)
operator||
operator|(
name|reg
operator|<<
name|RA_REGISTER_SHIFT
operator|)
expr_stmt|;
name|bfd_put_32
argument_list|(
name|output_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|offset
argument_list|)
expr_stmt|;
block|}
block|}
break|break;
comment|/* Relocate against the beginning of the section */
case|case
operator|(
name|int
operator|)
name|R_PPC_SECTOFF
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_SECTOFF_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_SECTOFF_HI
case|:
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|addend
operator|-=
name|sec
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
break|break;
case|case
operator|(
name|int
operator|)
name|R_PPC_SECTOFF_HA
case|:
name|BFD_ASSERT
argument_list|(
name|sec
operator|!=
operator|(
name|asection
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|addend
operator|-=
name|sec
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|addend
operator|+=
operator|(
operator|(
name|relocation
operator|+
name|addend
operator|)
operator|&
literal|0x8000
operator|)
operator|<<
literal|1
expr_stmt|;
break|break;
comment|/* Negative relocations */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_NADDR32
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_NADDR16
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_NADDR16_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_NADDR16_HI
case|:
name|addend
operator|-=
literal|2
operator|*
name|relocation
expr_stmt|;
break|break;
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_NADDR16_HA
case|:
name|addend
operator|-=
literal|2
operator|*
name|relocation
expr_stmt|;
name|addend
operator|+=
operator|(
operator|(
name|relocation
operator|+
name|addend
operator|)
operator|&
literal|0x8000
operator|)
operator|<<
literal|1
expr_stmt|;
break|break;
comment|/* NOP relocation that prevents garbage collecting linkers from omitting a 	   reference.  */
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_MRKREF
case|:
continue|continue;
case|case
operator|(
name|int
operator|)
name|R_PPC_PLTREL24
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_COPY
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_GLOB_DAT
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_JMP_SLOT
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_RELATIVE
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_LOCAL24PC
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_PLT32
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_PLTREL32
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_PLT16_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_PLT16_HI
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_PLT16_HA
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_RELSEC16
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_RELST_LO
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_RELST_HI
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_RELST_HA
case|:
case|case
operator|(
name|int
operator|)
name|R_PPC_EMB_BIT_FLD
case|:
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
literal|"%s: Relocation %s is not yet supported for symbol %s."
argument_list|,
name|bfd_get_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
name|ppc_elf_howto_table
index|[
operator|(
name|int
operator|)
name|r_type
index|]
operator|->
name|name
argument_list|,
name|sym_name
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_invalid_operation
argument_list|)
expr_stmt|;
name|ret
operator|=
name|false
expr_stmt|;
continue|continue;
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\ttype = %s (%d), name = %s, symbol index = %ld, offset = %ld, addend = %ld\n"
argument_list|,
name|howto
operator|->
name|name
argument_list|,
operator|(
name|int
operator|)
name|r_type
argument_list|,
name|sym_name
argument_list|,
name|r_symndx
argument_list|,
operator|(
name|long
operator|)
name|offset
argument_list|,
operator|(
name|long
operator|)
name|addend
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|r
operator|=
name|_bfd_final_link_relocate
argument_list|(
name|howto
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|contents
argument_list|,
name|offset
argument_list|,
name|relocation
argument_list|,
name|addend
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|bfd_reloc_ok
condition|)
block|{
name|ret
operator|=
name|false
expr_stmt|;
switch|switch
condition|(
name|r
condition|)
block|{
default|default:
break|break;
case|case
name|bfd_reloc_overflow
case|:
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
if|if
condition|(
name|h
operator|!=
name|NULL
condition|)
name|name
operator|=
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
expr_stmt|;
else|else
block|{
name|name
operator|=
name|bfd_elf_string_from_elf_section
argument_list|(
name|input_bfd
argument_list|,
name|symtab_hdr
operator|->
name|sh_link
argument_list|,
name|sym
operator|->
name|st_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
break|break;
if|if
condition|(
operator|*
name|name
operator|==
literal|'\0'
condition|)
name|name
operator|=
name|bfd_section_name
argument_list|(
name|input_bfd
argument_list|,
name|sec
argument_list|)
expr_stmt|;
block|}
call|(
modifier|*
name|info
operator|->
name|callbacks
operator|->
name|reloc_overflow
call|)
argument_list|(
name|info
argument_list|,
name|name
argument_list|,
name|howto
operator|->
name|name
argument_list|,
operator|(
name|bfd_vma
operator|)
literal|0
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|offset
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|ret
return|;
block|}
end_function

begin_escape
end_escape

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_powerpcle_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-powerpcle"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_powerpc_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-powerpc"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_powerpc
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_PPC
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|ppc_elf_info_to_howto
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|EM_CYGNUS_POWERPC
end_ifdef

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT1
value|EM_CYGNUS_POWERPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EM_PPC_OLD
end_ifdef

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT2
value|EM_PPC_OLD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elf32_bfd_copy_private_bfd_data
value|ppc_elf_copy_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_merge_private_bfd_data
value|ppc_elf_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_set_private_flags
value|ppc_elf_set_private_flags
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
value|ppc_elf_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_backend_section_from_shdr
value|ppc_elf_section_from_shdr
end_define

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|ppc_elf_relocate_section
end_define

begin_define
define|#
directive|define
name|elf_backend_create_dynamic_sections
value|_bfd_elf_create_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_check_relocs
value|ppc_elf_check_relocs
end_define

begin_define
define|#
directive|define
name|elf_backend_adjust_dynamic_symbol
value|ppc_elf_adjust_dynamic_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_add_symbol_hook
value|ppc_elf_add_symbol_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_size_dynamic_sections
value|ppc_elf_size_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_symbol
value|ppc_elf_finish_dynamic_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_sections
value|ppc_elf_finish_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_fake_sections
value|ppc_elf_fake_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_additional_program_headers
value|ppc_elf_additional_program_headers
end_define

begin_define
define|#
directive|define
name|elf_backend_modify_segment_map
value|ppc_elf_modify_segment_map
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

