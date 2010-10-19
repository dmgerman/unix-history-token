begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* picoJava specific support for 32-bit ELF    Copyright 1999, 2000, 2001, 2002, 2005 Free Software Foundation, Inc.    Contributed by Steve Chamberlan of Transmeta (sac@pobox.com).     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"elf/pj.h"
end_include

begin_comment
comment|/* This function is used for normal relocs.  This is like the COFF    function, and is almost certainly incorrect for other ELF targets.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|pj_elf_reloc
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|arelent
modifier|*
name|reloc_entry
parameter_list|,
name|asymbol
modifier|*
name|symbol_in
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd
modifier|*
name|output_bfd
parameter_list|,
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|unsigned
name|long
name|insn
decl_stmt|;
name|bfd_vma
name|sym_value
decl_stmt|;
name|enum
name|elf_pj_reloc_type
name|r_type
decl_stmt|;
name|bfd_vma
name|addr
init|=
name|reloc_entry
operator|->
name|address
decl_stmt|;
name|bfd_byte
modifier|*
name|hit_data
init|=
name|addr
operator|+
operator|(
name|bfd_byte
operator|*
operator|)
name|data
decl_stmt|;
name|r_type
operator|=
operator|(
expr|enum
name|elf_pj_reloc_type
operator|)
name|reloc_entry
operator|->
name|howto
operator|->
name|type
expr_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
block|{
comment|/* Partial linking--do nothing.  */
name|reloc_entry
operator|->
name|address
operator|+=
name|input_section
operator|->
name|output_offset
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
if|if
condition|(
name|symbol_in
operator|!=
name|NULL
operator|&&
name|bfd_is_und_section
argument_list|(
name|symbol_in
operator|->
name|section
argument_list|)
condition|)
return|return
name|bfd_reloc_undefined
return|;
if|if
condition|(
name|bfd_is_com_section
argument_list|(
name|symbol_in
operator|->
name|section
argument_list|)
condition|)
name|sym_value
operator|=
literal|0
expr_stmt|;
else|else
name|sym_value
operator|=
operator|(
name|symbol_in
operator|->
name|value
operator|+
name|symbol_in
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|symbol_in
operator|->
name|section
operator|->
name|output_offset
operator|)
expr_stmt|;
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|R_PJ_DATA_DIR32
case|:
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
name|insn
operator|+=
name|sym_value
operator|+
name|reloc_entry
operator|->
name|addend
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|insn
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
break|break;
comment|/* Relocations in code are always bigendian, no matter what the 	 data endianness is.  */
case|case
name|R_PJ_CODE_DIR32
case|:
name|insn
operator|=
name|bfd_getb32
argument_list|(
name|hit_data
argument_list|)
expr_stmt|;
name|insn
operator|+=
name|sym_value
operator|+
name|reloc_entry
operator|->
name|addend
expr_stmt|;
name|bfd_putb32
argument_list|(
operator|(
name|bfd_vma
operator|)
name|insn
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_PJ_CODE_REL16
case|:
name|insn
operator|=
name|bfd_getb16
argument_list|(
name|hit_data
argument_list|)
expr_stmt|;
name|insn
operator|+=
name|sym_value
operator|+
name|reloc_entry
operator|->
name|addend
operator|-
operator|(
name|input_section
operator|->
name|output_section
operator|->
name|vma
operator|+
name|input_section
operator|->
name|output_offset
operator|)
expr_stmt|;
name|bfd_putb16
argument_list|(
operator|(
name|bfd_vma
operator|)
name|insn
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_PJ_CODE_LO16
case|:
name|insn
operator|=
name|bfd_getb16
argument_list|(
name|hit_data
argument_list|)
expr_stmt|;
name|insn
operator|+=
name|sym_value
operator|+
name|reloc_entry
operator|->
name|addend
expr_stmt|;
name|bfd_putb16
argument_list|(
operator|(
name|bfd_vma
operator|)
name|insn
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_PJ_CODE_HI16
case|:
name|insn
operator|=
name|bfd_getb16
argument_list|(
name|hit_data
argument_list|)
expr_stmt|;
name|insn
operator|+=
operator|(
name|sym_value
operator|+
name|reloc_entry
operator|->
name|addend
operator|)
operator|>>
literal|16
expr_stmt|;
name|bfd_putb16
argument_list|(
operator|(
name|bfd_vma
operator|)
name|insn
argument_list|,
name|hit_data
argument_list|)
expr_stmt|;
break|break;
default|default:
name|abort
argument_list|()
expr_stmt|;
break|break;
block|}
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|pj_elf_howto_table
index|[]
init|=
block|{
comment|/* No relocation.  */
name|HOWTO
argument_list|(
name|R_PJ_NONE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_NONE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit absolute relocation.  Setting partial_inplace to TRUE and      src_mask to a non-zero value is similar to the COFF toolchain.  */
name|HOWTO
argument_list|(
name|R_PJ_DATA_DIR32
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_DIR32"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit PC relative relocation.  */
name|HOWTO
argument_list|(
name|R_PJ_CODE_REL32
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
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_REL32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative relocation.  */
name|HOWTO
argument_list|(
name|R_PJ_CODE_REL16
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
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overf6w */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_REL16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|4
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|5
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_PJ_CODE_DIR32
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_CODE_DIR32"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|7
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|8
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|9
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|10
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|11
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|12
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_PJ_CODE_LO16
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_LO16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PJ_CODE_HI16
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_unsigned
argument_list|,
comment|/* complain_on_overflow */
name|pj_elf_reloc
argument_list|,
comment|/* special_function */
literal|"R_PJ_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* GNU extension to record C++ vtable hierarchy.  */
name|HOWTO
argument_list|(
name|R_PJ_GNU_VTINHERIT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"R_PJ_GNU_VTINHERIT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* GNU extension to record C++ vtable member usage.  */
name|HOWTO
argument_list|(
name|R_PJ_GNU_VTENTRY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|0
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_elf_rel_vtable_reloc_fn
argument_list|,
comment|/* special_function */
literal|"R_PJ_GNU_VTENTRY"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This structure is used to map BFD reloc codes to PJ ELF relocs.  */
end_comment

begin_struct
struct|struct
name|elf_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|unsigned
name|char
name|elf_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An array mapping BFD reloc codes to PJ ELF relocs.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf_reloc_map
name|pj_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_PJ_NONE
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_PJ_DATA_DIR32
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_DIR16
block|,
name|R_PJ_CODE_DIR16
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_DIR32
block|,
name|R_PJ_CODE_DIR32
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_LO16
block|,
name|R_PJ_CODE_LO16
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_HI16
block|,
name|R_PJ_CODE_HI16
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_REL32
block|,
name|R_PJ_CODE_REL32
block|}
block|,
block|{
name|BFD_RELOC_PJ_CODE_REL16
block|,
name|R_PJ_CODE_REL16
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_INHERIT
block|,
name|R_PJ_GNU_VTINHERIT
block|}
block|,
block|{
name|BFD_RELOC_VTABLE_ENTRY
block|,
name|R_PJ_GNU_VTENTRY
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a BFD reloc code, return the howto structure for the    corresponding PJ ELf reloc.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|pj_elf_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bfd_reloc_code_real_type
name|code
parameter_list|)
block|{
name|unsigned
name|int
name|i
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
name|pj_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|elf_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|pj_reloc_map
index|[
name|i
index|]
operator|.
name|bfd_reloc_val
operator|==
name|code
condition|)
return|return
operator|&
name|pj_elf_howto_table
index|[
operator|(
name|int
operator|)
name|pj_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
index|]
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Given an ELF reloc, fill in the howto field of a relent.  */
end_comment

begin_function
specifier|static
name|void
name|pj_elf_info_to_howto
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|unsigned
name|int
name|r
decl_stmt|;
name|r
operator|=
name|ELF32_R_TYPE
argument_list|(
name|dst
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|r
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_PJ_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
operator|&
name|pj_elf_howto_table
index|[
name|r
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Take this moment to fill in the special picoJava bits in the    e_flags field.  */
end_comment

begin_function
specifier|static
name|void
name|pj_elf_final_write_processing
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|bfd_boolean
name|linker
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator||=
name|EF_PICOJAVA_ARCH
expr_stmt|;
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator||=
name|EF_PICOJAVA_GNUCALLS
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_pj_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-pj"
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_pjl_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-pjl"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_pj
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_PJ
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT1
value|EM_PJ_OLD
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_get_relocated_section_contents
value|bfd_generic_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
value|pj_elf_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|pj_elf_final_write_processing
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|pj_elf_info_to_howto
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

