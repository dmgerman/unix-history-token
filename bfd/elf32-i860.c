begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel i860 specific support for 32-bit ELF.    Copyright 1993, 1995, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2007    Free Software Foundation, Inc.     Full i860 support contributed by Jason Eckhardt<jle@cygnus.com>.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"bfd.h"
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
file|"elf/i860.h"
end_include

begin_comment
comment|/* special_function for R_860_PC26 relocation.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|i860_howto_pc26_reloc
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|reloc_entry
parameter_list|,
name|asymbol
modifier|*
name|symbol
parameter_list|,
name|void
modifier|*
name|data
name|ATTRIBUTE_UNUSED
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
name|bfd_vma
name|insn
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_byte
modifier|*
name|addr
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
operator|!
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
operator|||
name|reloc_entry
operator|->
name|addend
operator|==
literal|0
operator|)
condition|)
block|{
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
comment|/* Used elf32-mips.c as an example.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
if|if
condition|(
name|bfd_is_com_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
else|else
name|relocation
operator|=
name|symbol
operator|->
name|value
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|address
operator|>
name|bfd_get_section_limit
argument_list|(
name|abfd
argument_list|,
name|input_section
argument_list|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
comment|/* Adjust for PC-relative relocation.  */
name|relocation
operator|-=
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
operator|+
name|reloc_entry
operator|->
name|address
operator|+
literal|4
operator|)
expr_stmt|;
comment|/* Check for target out of range.  */
if|if
condition|(
operator|(
name|bfd_signed_vma
operator|)
name|relocation
operator|>
operator|(
literal|0x3ffffff
operator|<<
literal|2
operator|)
operator|||
operator|(
name|bfd_signed_vma
operator|)
name|relocation
operator|<
operator|(
operator|-
literal|0x4000000
operator|<<
literal|2
operator|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|addr
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|relocation
operator|>>=
name|reloc_entry
operator|->
name|howto
operator|->
name|rightshift
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
operator|)
operator||
operator|(
name|relocation
operator|&
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
operator|)
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
name|addr
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* special_function for R_860_PC16 relocation.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|i860_howto_pc16_reloc
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
name|symbol
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
name|bfd_vma
name|insn
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_byte
modifier|*
name|addr
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
operator|!
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
operator|||
name|reloc_entry
operator|->
name|addend
operator|==
literal|0
operator|)
condition|)
block|{
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
comment|/* Used elf32-mips.c as an example.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
if|if
condition|(
name|bfd_is_com_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
else|else
name|relocation
operator|=
name|symbol
operator|->
name|value
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|address
operator|>
name|bfd_get_section_limit
argument_list|(
name|abfd
argument_list|,
name|input_section
argument_list|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
comment|/* Adjust for PC-relative relocation.  */
name|relocation
operator|-=
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
operator|+
name|reloc_entry
operator|->
name|address
operator|+
literal|4
operator|)
expr_stmt|;
comment|/* Check for target out of range.  */
if|if
condition|(
operator|(
name|bfd_signed_vma
operator|)
name|relocation
operator|>
operator|(
literal|0x7fff
operator|<<
literal|2
operator|)
operator|||
operator|(
name|bfd_signed_vma
operator|)
name|relocation
operator|<
operator|(
operator|-
literal|0x8000
operator|<<
literal|2
operator|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|addr
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|relocation
operator|>>=
name|reloc_entry
operator|->
name|howto
operator|->
name|rightshift
expr_stmt|;
name|relocation
operator|=
operator|(
operator|(
operator|(
name|relocation
operator|&
literal|0xf800
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|relocation
operator|&
literal|0x7ff
operator|)
operator|)
operator|&
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
operator|)
operator||
name|relocation
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
name|addr
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* special_function for R_860_HIGHADJ relocation.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|i860_howto_highadj_reloc
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
name|symbol
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
name|bfd_vma
name|insn
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_byte
modifier|*
name|addr
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
operator|!
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
operator|||
name|reloc_entry
operator|->
name|addend
operator|==
literal|0
operator|)
condition|)
block|{
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
comment|/* Used elf32-mips.c as an example.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
if|if
condition|(
name|bfd_is_com_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
else|else
name|relocation
operator|=
name|symbol
operator|->
name|value
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
name|relocation
operator|+=
literal|0x8000
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|address
operator|>
name|bfd_get_section_limit
argument_list|(
name|abfd
argument_list|,
name|input_section
argument_list|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|addr
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|relocation
operator|=
operator|(
operator|(
name|relocation
operator|>>
literal|16
operator|)
operator|&
literal|0xffff
operator|)
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
literal|0xffff0000
operator|)
operator||
name|relocation
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
name|addr
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* special_function for R_860_SPLITn relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|i860_howto_splitn_reloc
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
name|symbol
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
name|bfd_vma
name|insn
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_byte
modifier|*
name|addr
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
operator|!
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
operator|||
name|reloc_entry
operator|->
name|addend
operator|==
literal|0
operator|)
condition|)
block|{
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
comment|/* Used elf32-mips.c as an example.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_undefined
return|;
if|if
condition|(
name|bfd_is_com_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
condition|)
name|relocation
operator|=
literal|0
expr_stmt|;
else|else
name|relocation
operator|=
name|symbol
operator|->
name|value
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|address
operator|>
name|bfd_get_section_limit
argument_list|(
name|abfd
argument_list|,
name|input_section
argument_list|)
condition|)
return|return
name|bfd_reloc_outofrange
return|;
name|addr
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
expr_stmt|;
name|relocation
operator|=
operator|(
operator|(
operator|(
name|relocation
operator|&
literal|0xf800
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|relocation
operator|&
literal|0x7ff
operator|)
operator|)
operator|&
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|reloc_entry
operator|->
name|howto
operator|->
name|dst_mask
operator|)
operator||
name|relocation
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
name|addr
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* This howto table is preliminary.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_i860_howto_table
index|[]
init|=
block|{
comment|/* This relocation does nothing.  */
name|HOWTO
argument_list|(
name|R_860_NONE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_NONE"
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
comment|/* A 32-bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_860_32
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_32"
argument_list|,
comment|/* name */
name|FALSE
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
name|HOWTO
argument_list|(
name|R_860_COPY
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_COPY"
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
name|HOWTO
argument_list|(
name|R_860_GLOB_DAT
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_GLOB_DAT"
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
name|HOWTO
argument_list|(
name|R_860_JUMP_SLOT
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_JUMP_SLOT"
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
name|HOWTO
argument_list|(
name|R_860_RELATIVE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_RELATIVE"
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
comment|/* A 26-bit PC-relative relocation.  */
name|HOWTO
argument_list|(
name|R_860_PC26
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|26
argument_list|,
comment|/* bitsize */
name|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_pc26_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_PC26"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffffff
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_PLT26
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
name|TRUE
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
literal|"R_860_PLT26"
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
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 16-bit PC-relative relocation.  */
name|HOWTO
argument_list|(
name|R_860_PC16
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_pc16_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_PC16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x1f07ff
argument_list|,
comment|/* src_mask */
literal|0x1f07ff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_LOW0
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
name|FALSE
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
literal|"R_860_LOW0"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_SPLIT0
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_splitn_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_SPLIT0"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x1f07ff
argument_list|,
comment|/* src_mask */
literal|0x1f07ff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_LOW1
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
name|FALSE
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
literal|"R_860_LOW1"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xfffe
argument_list|,
comment|/* src_mask */
literal|0xfffe
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_SPLIT1
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_splitn_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_SPLIT1"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x1f07fe
argument_list|,
comment|/* src_mask */
literal|0x1f07fe
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_LOW2
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
name|FALSE
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
literal|"R_860_LOW2"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xfffc
argument_list|,
comment|/* src_mask */
literal|0xfffc
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_SPLIT2
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_splitn_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_SPLIT2"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x1f07fc
argument_list|,
comment|/* src_mask */
literal|0x1f07fc
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_LOW3
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
name|FALSE
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
literal|"R_860_LOW3"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xfff8
argument_list|,
comment|/* src_mask */
literal|0xfff8
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_LOGOT0
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
name|FALSE
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
literal|"R_860_LOGOT0"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_SPGOT0
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
name|FALSE
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
literal|"R_860_SPGOT0"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_LOGOT1
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
name|FALSE
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
literal|"R_860_LOGOT1"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_SPGOT1
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
name|FALSE
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
literal|"R_860_SPGOT1"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_LOGOTOFF0
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_LOGOTOFF0"
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
name|HOWTO
argument_list|(
name|R_860_SPGOTOFF0
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_SPGOTOFF0"
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
name|HOWTO
argument_list|(
name|R_860_LOGOTOFF1
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_LOGOTOFF1"
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
name|HOWTO
argument_list|(
name|R_860_SPGOTOFF1
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_SPGOTOFF1"
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
name|HOWTO
argument_list|(
name|R_860_LOGOTOFF2
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_LOGOTOFF2"
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
name|HOWTO
argument_list|(
name|R_860_LOGOTOFF3
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_LOGOTOFF3"
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
name|HOWTO
argument_list|(
name|R_860_LOPC
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
name|TRUE
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
literal|"R_860_LOPC"
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
name|R_860_HIGHADJ
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|i860_howto_highadj_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_HIGHADJ"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_HAGOT
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
name|FALSE
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
literal|"R_860_HAGOT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_HAGOTOFF
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_HAGOTOFF"
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
name|HOWTO
argument_list|(
name|R_860_HAPC
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
name|TRUE
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
literal|"R_860_HAPC"
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
name|R_860_HIGH
argument_list|,
comment|/* type */
literal|16
argument_list|,
comment|/* rightshift */
literal|2
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_HIGH"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_860_HIGOT
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
name|FALSE
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
literal|"R_860_HIGOT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_860_HIGOTOFF
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_860_HIGOTOFF"
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
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|elf_code_to_howto_index
index|[
name|R_860_max
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|lookup_howto
parameter_list|(
name|unsigned
name|int
name|rtype
parameter_list|)
block|{
specifier|static
name|int
name|initialized
init|=
literal|0
decl_stmt|;
name|int
name|i
decl_stmt|;
name|int
name|howto_tbl_size
init|=
call|(
name|int
call|)
argument_list|(
sizeof|sizeof
argument_list|(
name|elf32_i860_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf32_i860_howto_table
index|[
literal|0
index|]
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|initialized
condition|)
block|{
name|initialized
operator|=
literal|1
expr_stmt|;
name|memset
argument_list|(
name|elf_code_to_howto_index
argument_list|,
literal|0xff
argument_list|,
sizeof|sizeof
argument_list|(
name|elf_code_to_howto_index
argument_list|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|howto_tbl_size
condition|;
name|i
operator|++
control|)
name|elf_code_to_howto_index
index|[
name|elf32_i860_howto_table
index|[
name|i
index|]
operator|.
name|type
index|]
operator|=
name|i
expr_stmt|;
block|}
name|BFD_ASSERT
argument_list|(
name|rtype
operator|<=
name|R_860_max
argument_list|)
expr_stmt|;
name|i
operator|=
name|elf_code_to_howto_index
index|[
name|rtype
index|]
expr_stmt|;
if|if
condition|(
name|i
operator|>=
name|howto_tbl_size
condition|)
return|return
literal|0
return|;
return|return
name|elf32_i860_howto_table
operator|+
name|i
return|;
block|}
end_function

begin_comment
comment|/* Given a BFD reloc, return the matching HOWTO structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_i860_reloc_type_lookup
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
name|rtype
decl_stmt|;
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|BFD_RELOC_NONE
case|:
name|rtype
operator|=
name|R_860_NONE
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_32
case|:
name|rtype
operator|=
name|R_860_32
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_COPY
case|:
name|rtype
operator|=
name|R_860_COPY
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_GLOB_DAT
case|:
name|rtype
operator|=
name|R_860_GLOB_DAT
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_JUMP_SLOT
case|:
name|rtype
operator|=
name|R_860_JUMP_SLOT
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_RELATIVE
case|:
name|rtype
operator|=
name|R_860_RELATIVE
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_PC26
case|:
name|rtype
operator|=
name|R_860_PC26
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_PLT26
case|:
name|rtype
operator|=
name|R_860_PLT26
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_PC16
case|:
name|rtype
operator|=
name|R_860_PC16
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOW0
case|:
name|rtype
operator|=
name|R_860_LOW0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPLIT0
case|:
name|rtype
operator|=
name|R_860_SPLIT0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOW1
case|:
name|rtype
operator|=
name|R_860_LOW1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPLIT1
case|:
name|rtype
operator|=
name|R_860_SPLIT1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOW2
case|:
name|rtype
operator|=
name|R_860_LOW2
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPLIT2
case|:
name|rtype
operator|=
name|R_860_SPLIT2
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOW3
case|:
name|rtype
operator|=
name|R_860_LOW3
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOT0
case|:
name|rtype
operator|=
name|R_860_LOGOT0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPGOT0
case|:
name|rtype
operator|=
name|R_860_SPGOT0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOT1
case|:
name|rtype
operator|=
name|R_860_LOGOT1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPGOT1
case|:
name|rtype
operator|=
name|R_860_SPGOT1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOTOFF0
case|:
name|rtype
operator|=
name|R_860_LOGOTOFF0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPGOTOFF0
case|:
name|rtype
operator|=
name|R_860_SPGOTOFF0
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOTOFF1
case|:
name|rtype
operator|=
name|R_860_LOGOTOFF1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_SPGOTOFF1
case|:
name|rtype
operator|=
name|R_860_SPGOTOFF1
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOTOFF2
case|:
name|rtype
operator|=
name|R_860_LOGOTOFF2
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOGOTOFF3
case|:
name|rtype
operator|=
name|R_860_LOGOTOFF3
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_LOPC
case|:
name|rtype
operator|=
name|R_860_LOPC
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HIGHADJ
case|:
name|rtype
operator|=
name|R_860_HIGHADJ
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HAGOT
case|:
name|rtype
operator|=
name|R_860_HAGOT
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HAGOTOFF
case|:
name|rtype
operator|=
name|R_860_HAGOTOFF
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HAPC
case|:
name|rtype
operator|=
name|R_860_HAPC
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HIGH
case|:
name|rtype
operator|=
name|R_860_HIGH
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HIGOT
case|:
name|rtype
operator|=
name|R_860_HIGOT
expr_stmt|;
break|break;
case|case
name|BFD_RELOC_860_HIGOTOFF
case|:
name|rtype
operator|=
name|R_860_HIGOTOFF
expr_stmt|;
break|break;
default|default:
name|rtype
operator|=
literal|0
expr_stmt|;
break|break;
block|}
return|return
name|lookup_howto
argument_list|(
name|rtype
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_i860_reloc_name_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
specifier|const
name|char
modifier|*
name|r_name
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
operator|(
sizeof|sizeof
argument_list|(
name|elf32_i860_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf32_i860_howto_table
index|[
literal|0
index|]
argument_list|)
operator|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|elf32_i860_howto_table
index|[
name|i
index|]
operator|.
name|name
operator|!=
name|NULL
operator|&&
name|strcasecmp
argument_list|(
name|elf32_i860_howto_table
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|r_name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|&
name|elf32_i860_howto_table
index|[
name|i
index|]
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Given a ELF reloc, return the matching HOWTO structure.  */
end_comment

begin_function
specifier|static
name|void
name|elf32_i860_info_to_howto_rela
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|bfd_reloc
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|elf_reloc
parameter_list|)
block|{
name|bfd_reloc
operator|->
name|howto
operator|=
name|lookup_howto
argument_list|(
operator|(
name|unsigned
operator|)
name|ELF32_R_TYPE
argument_list|(
name|elf_reloc
operator|->
name|r_info
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Specialized relocation handler for R_860_SPLITn.  These relocations    involves a 16-bit field that is split into two contiguous parts.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_i860_relocate_splitn
parameter_list|(
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|rello
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
block|{
name|bfd_vma
name|insn
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|howto
operator|=
name|lookup_howto
argument_list|(
operator|(
name|unsigned
operator|)
name|ELF32_R_TYPE
argument_list|(
name|rello
operator|->
name|r_info
argument_list|)
argument_list|)
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|input_bfd
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
comment|/* Relocate.  */
name|value
operator|+=
name|rello
operator|->
name|r_addend
expr_stmt|;
comment|/* Separate the fields and insert.  */
name|value
operator|=
operator|(
operator|(
operator|(
name|value
operator|&
literal|0xf800
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|value
operator|&
literal|0x7ff
operator|)
operator|)
operator|&
name|howto
operator|->
name|dst_mask
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|howto
operator|->
name|dst_mask
operator|)
operator||
name|value
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* Specialized relocation handler for R_860_PC16.  This relocation    involves a 16-bit, PC-relative field that is split into two contiguous    parts.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_i860_relocate_pc16
parameter_list|(
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|rello
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
block|{
name|bfd_vma
name|insn
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|howto
operator|=
name|lookup_howto
argument_list|(
operator|(
name|unsigned
operator|)
name|ELF32_R_TYPE
argument_list|(
name|rello
operator|->
name|r_info
argument_list|)
argument_list|)
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|input_bfd
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
comment|/* Adjust for PC-relative relocation.  */
name|value
operator|-=
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
name|value
operator|-=
name|rello
operator|->
name|r_offset
expr_stmt|;
comment|/* Relocate.  */
name|value
operator|+=
name|rello
operator|->
name|r_addend
expr_stmt|;
comment|/* Adjust the value by 4, then separate the fields and insert.  */
name|value
operator|=
operator|(
name|value
operator|-
literal|4
operator|)
operator|>>
name|howto
operator|->
name|rightshift
expr_stmt|;
name|value
operator|=
operator|(
operator|(
operator|(
name|value
operator|&
literal|0xf800
operator|)
operator|<<
literal|5
operator|)
operator||
operator|(
name|value
operator|&
literal|0x7ff
operator|)
operator|)
operator|&
name|howto
operator|->
name|dst_mask
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|howto
operator|->
name|dst_mask
operator|)
operator||
name|value
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* Specialized relocation handler for R_860_PC26.  This relocation    involves a 26-bit, PC-relative field which must be adjusted by 4.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_i860_relocate_pc26
parameter_list|(
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|rello
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
block|{
name|bfd_vma
name|insn
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|howto
operator|=
name|lookup_howto
argument_list|(
operator|(
name|unsigned
operator|)
name|ELF32_R_TYPE
argument_list|(
name|rello
operator|->
name|r_info
argument_list|)
argument_list|)
expr_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|input_bfd
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
comment|/* Adjust for PC-relative relocation.  */
name|value
operator|-=
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
name|value
operator|-=
name|rello
operator|->
name|r_offset
expr_stmt|;
comment|/* Relocate.  */
name|value
operator|+=
name|rello
operator|->
name|r_addend
expr_stmt|;
comment|/* Adjust value by 4 and insert the field.  */
name|value
operator|=
operator|(
operator|(
name|value
operator|-
literal|4
operator|)
operator|>>
name|howto
operator|->
name|rightshift
operator|)
operator|&
name|howto
operator|->
name|dst_mask
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
operator|~
name|howto
operator|->
name|dst_mask
operator|)
operator||
name|value
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|rello
operator|->
name|r_offset
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* Specialized relocation handler for R_860_HIGHADJ.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|elf32_i860_relocate_highadj
parameter_list|(
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|rel
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|bfd_vma
name|value
parameter_list|)
block|{
name|bfd_vma
name|insn
decl_stmt|;
name|insn
operator|=
name|bfd_get_32
argument_list|(
name|input_bfd
argument_list|,
name|contents
operator|+
name|rel
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|value
operator|+=
name|rel
operator|->
name|r_addend
expr_stmt|;
name|value
operator|+=
literal|0x8000
expr_stmt|;
name|value
operator|=
operator|(
operator|(
name|value
operator|>>
literal|16
operator|)
operator|&
literal|0xffff
operator|)
expr_stmt|;
name|insn
operator|=
operator|(
name|insn
operator|&
literal|0xffff0000
operator|)
operator||
name|value
expr_stmt|;
name|bfd_put_32
argument_list|(
name|input_bfd
argument_list|,
name|insn
argument_list|,
name|contents
operator|+
name|rel
operator|->
name|r_offset
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* Perform a single relocation.  By default we use the standard BFD    routines. However, we handle some specially.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|i860_final_link_relocate
parameter_list|(
name|reloc_howto_type
modifier|*
name|howto
parameter_list|,
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|rel
parameter_list|,
name|bfd_vma
name|relocation
parameter_list|)
block|{
return|return
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
name|rel
operator|->
name|r_offset
argument_list|,
name|relocation
argument_list|,
name|rel
operator|->
name|r_addend
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Relocate an i860 ELF section.     This is boiler-plate code copied from fr30.     The RELOCATE_SECTION function is called by the new ELF backend linker    to handle the relocations for a section.     The relocs are always passed as Rela structures; if the section    actually uses Rel structures, the r_addend field will always be    zero.     This function is responsible for adjusting the section contents as    necessary, and (if using Rela relocs and generating a relocatable    output file) adjusting the reloc addend as necessary.     This function does not have to worry about setting the reloc    address or the reloc symbol index.     LOCAL_SYMS is a pointer to the swapped in local symbols.     LOCAL_SECTIONS is an array giving the section in the input file    corresponding to the st_shndx field of each local symbol.     The global hash table entry for the global symbols can be found    via elf_sym_hashes (input_bfd).     When generating relocatable output, this function must handle    STB_LOCAL/STT_SECTION symbols specially.  The output symbol is    going to be the section symbol corresponding to the output    section, which means that the addend must be adjusted    accordingly.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|elf32_i860_relocate_section
parameter_list|(
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
name|info
parameter_list|,
name|bfd
modifier|*
name|input_bfd
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd_byte
modifier|*
name|contents
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|relocs
parameter_list|,
name|Elf_Internal_Sym
modifier|*
name|local_syms
parameter_list|,
name|asection
modifier|*
modifier|*
name|local_sections
parameter_list|)
block|{
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
name|Elf_Internal_Rela
modifier|*
name|rel
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|relend
decl_stmt|;
name|symtab_hdr
operator|=
operator|&
name|elf_tdata
argument_list|(
name|input_bfd
argument_list|)
operator|->
name|symtab_hdr
expr_stmt|;
name|sym_hashes
operator|=
name|elf_sym_hashes
argument_list|(
name|input_bfd
argument_list|)
expr_stmt|;
name|relend
operator|=
name|relocs
operator|+
name|input_section
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
name|relend
condition|;
name|rel
operator|++
control|)
block|{
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|unsigned
name|long
name|r_symndx
decl_stmt|;
name|Elf_Internal_Sym
modifier|*
name|sym
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|struct
name|elf_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_reloc_status_type
name|r
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
init|=
name|NULL
decl_stmt|;
name|int
name|r_type
decl_stmt|;
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
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
name|howto
operator|=
name|lookup_howto
argument_list|(
operator|(
name|unsigned
operator|)
name|ELF32_R_TYPE
argument_list|(
name|rel
operator|->
name|r_info
argument_list|)
argument_list|)
expr_stmt|;
name|h
operator|=
name|NULL
expr_stmt|;
name|sym
operator|=
name|NULL
expr_stmt|;
name|sec
operator|=
name|NULL
expr_stmt|;
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
name|relocation
operator|=
name|_bfd_elf_rela_local_sym
argument_list|(
name|output_bfd
argument_list|,
name|sym
argument_list|,
operator|&
name|sec
argument_list|,
name|rel
argument_list|)
expr_stmt|;
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
name|name
operator|=
operator|(
name|name
operator|==
name|NULL
operator|)
condition|?
name|bfd_section_name
argument_list|(
name|input_bfd
argument_list|,
name|sec
argument_list|)
else|:
name|name
expr_stmt|;
block|}
else|else
block|{
name|bfd_boolean
name|unresolved_reloc
decl_stmt|,
name|warned
decl_stmt|;
name|RELOC_FOR_GLOBAL_SYMBOL
argument_list|(
name|info
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
argument_list|,
name|r_symndx
argument_list|,
name|symtab_hdr
argument_list|,
name|sym_hashes
argument_list|,
name|h
argument_list|,
name|sec
argument_list|,
name|relocation
argument_list|,
name|unresolved_reloc
argument_list|,
name|warned
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|sec
operator|!=
name|NULL
operator|&&
name|elf_discarded_section
argument_list|(
name|sec
argument_list|)
condition|)
block|{
comment|/* For relocs against symbols from removed linkonce sections, 	     or sections discarded by a linker script, we just want the 	     section contents zeroed.  Avoid any special processing.  */
name|_bfd_clear_contents
argument_list|(
name|howto
argument_list|,
name|input_bfd
argument_list|,
name|contents
operator|+
name|rel
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|rel
operator|->
name|r_info
operator|=
literal|0
expr_stmt|;
name|rel
operator|->
name|r_addend
operator|=
literal|0
expr_stmt|;
continue|continue;
block|}
if|if
condition|(
name|info
operator|->
name|relocatable
condition|)
continue|continue;
switch|switch
condition|(
name|r_type
condition|)
block|{
default|default:
name|r
operator|=
name|i860_final_link_relocate
argument_list|(
name|howto
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|contents
argument_list|,
name|rel
argument_list|,
name|relocation
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_860_HIGHADJ
case|:
name|r
operator|=
name|elf32_i860_relocate_highadj
argument_list|(
name|input_bfd
argument_list|,
name|rel
argument_list|,
name|contents
argument_list|,
name|relocation
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_860_PC16
case|:
name|r
operator|=
name|elf32_i860_relocate_pc16
argument_list|(
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
argument_list|,
name|contents
argument_list|,
name|relocation
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_860_PC26
case|:
name|r
operator|=
name|elf32_i860_relocate_pc26
argument_list|(
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
argument_list|,
name|contents
argument_list|,
name|relocation
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_860_SPLIT0
case|:
case|case
name|R_860_SPLIT1
case|:
case|case
name|R_860_SPLIT2
case|:
name|r
operator|=
name|elf32_i860_relocate_splitn
argument_list|(
name|input_bfd
argument_list|,
name|rel
argument_list|,
name|contents
argument_list|,
name|relocation
argument_list|)
expr_stmt|;
break|break;
comment|/* We do not yet handle GOT/PLT/Dynamic relocations.  */
case|case
name|R_860_COPY
case|:
case|case
name|R_860_GLOB_DAT
case|:
case|case
name|R_860_JUMP_SLOT
case|:
case|case
name|R_860_RELATIVE
case|:
case|case
name|R_860_PLT26
case|:
case|case
name|R_860_LOGOT0
case|:
case|case
name|R_860_SPGOT0
case|:
case|case
name|R_860_LOGOT1
case|:
case|case
name|R_860_SPGOT1
case|:
case|case
name|R_860_LOGOTOFF0
case|:
case|case
name|R_860_SPGOTOFF0
case|:
case|case
name|R_860_LOGOTOFF1
case|:
case|case
name|R_860_SPGOTOFF1
case|:
case|case
name|R_860_LOGOTOFF2
case|:
case|case
name|R_860_LOGOTOFF3
case|:
case|case
name|R_860_LOPC
case|:
case|case
name|R_860_HAGOT
case|:
case|case
name|R_860_HAGOTOFF
case|:
case|case
name|R_860_HAPC
case|:
case|case
name|R_860_HIGOT
case|:
case|case
name|R_860_HIGOTOFF
case|:
name|r
operator|=
name|bfd_reloc_notsupported
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|r
operator|!=
name|bfd_reloc_ok
condition|)
block|{
specifier|const
name|char
modifier|*
name|msg
init|=
operator|(
specifier|const
name|char
operator|*
operator|)
name|NULL
decl_stmt|;
switch|switch
condition|(
name|r
condition|)
block|{
case|case
name|bfd_reloc_overflow
case|:
name|r
operator|=
name|info
operator|->
name|callbacks
operator|->
name|reloc_overflow
argument_list|(
name|info
argument_list|,
operator|(
name|h
condition|?
operator|&
name|h
operator|->
name|root
else|:
name|NULL
operator|)
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
name|rel
operator|->
name|r_offset
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_reloc_undefined
case|:
name|r
operator|=
name|info
operator|->
name|callbacks
operator|->
name|undefined_symbol
argument_list|(
name|info
argument_list|,
name|name
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
operator|->
name|r_offset
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_reloc_outofrange
case|:
name|msg
operator|=
name|_
argument_list|(
literal|"internal error: out of range error"
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_reloc_notsupported
case|:
name|msg
operator|=
name|_
argument_list|(
literal|"internal error: unsupported relocation error"
argument_list|)
expr_stmt|;
break|break;
case|case
name|bfd_reloc_dangerous
case|:
name|msg
operator|=
name|_
argument_list|(
literal|"internal error: dangerous relocation"
argument_list|)
expr_stmt|;
break|break;
default|default:
name|msg
operator|=
name|_
argument_list|(
literal|"internal error: unknown error"
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|msg
condition|)
name|r
operator|=
name|info
operator|->
name|callbacks
operator|->
name|warning
argument_list|(
name|info
argument_list|,
name|msg
argument_list|,
name|name
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
if|if
condition|(
operator|!
name|r
condition|)
return|return
name|FALSE
return|;
block|}
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Return whether a symbol name implies a local label.  SVR4/860 compilers    generate labels of the form ".ep.function_name" to denote the end of a    function prolog. These should be local.    ??? Do any other SVR4 compilers have this convention? If so, this should    be added to the generic routine.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|elf32_i860_is_local_label_name
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'.'
operator|&&
name|name
index|[
literal|1
index|]
operator|==
literal|'e'
operator|&&
name|name
index|[
literal|2
index|]
operator|==
literal|'p'
operator|&&
name|name
index|[
literal|3
index|]
operator|==
literal|'.'
condition|)
return|return
name|TRUE
return|;
return|return
name|_bfd_elf_is_local_label_name
argument_list|(
name|abfd
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_i860_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-i860"
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_i860_little_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-i860-little"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_i860
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_860
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|4096
end_define

begin_define
define|#
directive|define
name|elf_backend_rela_normal
value|1
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|NULL
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|elf32_i860_info_to_howto_rela
end_define

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|elf32_i860_relocate_section
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
value|elf32_i860_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_name_lookup
value|elf32_i860_reloc_name_lookup
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_is_local_label_name
value|elf32_i860_is_local_label_name
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

