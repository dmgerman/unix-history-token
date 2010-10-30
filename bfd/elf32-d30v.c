begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* D30V-specific support for 32-bit ELF    Copyright 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2007    Free Software Foundation, Inc.    Contributed by Martin Hunt (hunt@cygnus.com).     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,    MA 02110-1301, USA.  */
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
file|"elf/d30v.h"
end_include

begin_define
define|#
directive|define
name|MAX32
value|((bfd_signed_vma) 0x7fffffff)
end_define

begin_define
define|#
directive|define
name|MIN32
value|(- MAX32 - 1)
end_define

begin_function
specifier|static
name|bfd_reloc_status_type
name|bfd_elf_d30v_reloc
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
parameter_list|)
block|{
name|bfd_signed_vma
name|relocation
decl_stmt|;
name|bfd_vma
name|in1
decl_stmt|,
name|in2
decl_stmt|,
name|num
decl_stmt|;
name|bfd_vma
name|tmp_addr
init|=
literal|0
decl_stmt|;
name|bfd_reloc_status_type
name|r
decl_stmt|;
name|asection
modifier|*
name|reloc_target_output_section
decl_stmt|;
name|bfd_size_type
name|addr
init|=
name|reloc_entry
operator|->
name|address
decl_stmt|;
name|bfd_reloc_status_type
name|flag
init|=
name|bfd_reloc_ok
decl_stmt|;
name|bfd_vma
name|output_base
init|=
literal|0
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
name|int
name|make_absolute
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
block|{
comment|/* Partial linking -- do nothing.  */
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
name|r
operator|=
name|bfd_elf_generic_reloc
argument_list|(
name|abfd
argument_list|,
name|reloc_entry
argument_list|,
name|symbol
argument_list|,
name|data
argument_list|,
name|input_section
argument_list|,
name|output_bfd
argument_list|,
name|error_message
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|bfd_reloc_continue
condition|)
return|return
name|r
return|;
comment|/* A hacked-up version of bfd_perform_reloc() follows.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_WEAK
operator|)
operator|==
literal|0
operator|&&
name|output_bfd
operator|==
name|NULL
condition|)
name|flag
operator|=
name|bfd_reloc_undefined
expr_stmt|;
comment|/* Is the address of the relocation really within the section?  */
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
comment|/* Work out which section the relocation is targeted at and the      initial relocation command value.  */
comment|/* Get symbol value.  (Common symbols are special.)  */
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
name|reloc_target_output_section
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
expr_stmt|;
comment|/* Convert input-section-relative symbol value to absolute.  */
name|output_base
operator|=
name|reloc_target_output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|output_base
operator|+
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
comment|/* Add in supplied addend.  */
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
comment|/* Here the variable relocation holds the final address of the      symbol we are relocating against, plus any addend.  */
if|if
condition|(
name|howto
operator|->
name|pc_relative
condition|)
block|{
name|tmp_addr
operator|=
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
expr_stmt|;
name|relocation
operator|-=
name|tmp_addr
expr_stmt|;
block|}
name|in1
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
argument_list|)
expr_stmt|;
name|in2
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
operator|+
literal|4
argument_list|)
expr_stmt|;
comment|/* Extract the addend.  */
name|num
operator|=
operator|(
operator|(
name|in2
operator|&
literal|0x3FFFF
operator|)
operator||
operator|(
operator|(
name|in2
operator|&
literal|0xFF00000
operator|)
operator|>>
literal|2
operator|)
operator||
operator|(
operator|(
name|in1
operator|&
literal|0x3F
operator|)
operator|<<
literal|26
operator|)
operator|)
expr_stmt|;
name|in1
operator|&=
literal|0xFFFFFFC0
expr_stmt|;
name|in2
operator|=
literal|0x80000000
expr_stmt|;
name|relocation
operator|+=
name|num
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|pc_relative
operator|&&
name|howto
operator|->
name|bitsize
operator|==
literal|32
condition|)
block|{
comment|/* The D30V has a PC that doesn't wrap and PC-relative jumps are 	 signed, so a PC-relative jump can't be more than +/- 2^31 bytes. 	 If one exceeds this, change it to an absolute jump.  */
if|if
condition|(
name|relocation
operator|>
name|MAX32
operator|||
name|relocation
operator|<
name|MIN32
condition|)
block|{
name|relocation
operator|=
operator|(
name|relocation
operator|+
name|tmp_addr
operator|)
operator|&
literal|0xffffffff
expr_stmt|;
name|make_absolute
operator|=
literal|1
expr_stmt|;
block|}
block|}
name|in1
operator||=
operator|(
name|relocation
operator|>>
literal|26
operator|)
operator|&
literal|0x3F
expr_stmt|;
comment|/* Top 6 bits.  */
name|in2
operator||=
operator|(
operator|(
name|relocation
operator|&
literal|0x03FC0000
operator|)
operator|<<
literal|2
operator|)
expr_stmt|;
comment|/* Next 8 bits.  */
name|in2
operator||=
name|relocation
operator|&
literal|0x0003FFFF
expr_stmt|;
comment|/* Bottom 18 bits.  */
comment|/* Change a PC-relative instruction to its      absolute equivalent with this simple hack.  */
if|if
condition|(
name|make_absolute
condition|)
name|in1
operator||=
literal|0x00100000
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|in1
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
argument_list|)
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|in2
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
operator|+
literal|4
argument_list|)
expr_stmt|;
return|return
name|flag
return|;
block|}
end_function

begin_function
specifier|static
name|bfd_reloc_status_type
name|bfd_elf_d30v_reloc_21
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
parameter_list|)
block|{
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_vma
name|in1
decl_stmt|,
name|num
decl_stmt|;
name|bfd_reloc_status_type
name|r
decl_stmt|;
name|asection
modifier|*
name|reloc_target_output_section
decl_stmt|;
name|bfd_size_type
name|addr
init|=
name|reloc_entry
operator|->
name|address
decl_stmt|;
name|bfd_reloc_status_type
name|flag
init|=
name|bfd_reloc_ok
decl_stmt|;
name|bfd_vma
name|output_base
init|=
literal|0
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
name|int
name|mask
decl_stmt|,
name|max
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
block|{
comment|/* Partial linking -- do nothing.  */
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
name|r
operator|=
name|bfd_elf_generic_reloc
argument_list|(
name|abfd
argument_list|,
name|reloc_entry
argument_list|,
name|symbol
argument_list|,
name|data
argument_list|,
name|input_section
argument_list|,
name|output_bfd
argument_list|,
name|error_message
argument_list|)
expr_stmt|;
if|if
condition|(
name|r
operator|!=
name|bfd_reloc_continue
condition|)
return|return
name|r
return|;
comment|/* A hacked-up version of bfd_perform_reloc() follows.  */
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_WEAK
operator|)
operator|==
literal|0
operator|&&
name|output_bfd
operator|==
name|NULL
condition|)
name|flag
operator|=
name|bfd_reloc_undefined
expr_stmt|;
comment|/* Is the address of the relocation really within the section?  */
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
comment|/* Work out which section the relocation is targeted at and the      initial relocation command value.  */
comment|/* Get symbol value.  (Common symbols are special.)  */
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
name|reloc_target_output_section
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
expr_stmt|;
comment|/* Convert input-section-relative symbol value to absolute.  */
name|output_base
operator|=
name|reloc_target_output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|output_base
operator|+
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
comment|/* Add in supplied addend.  */
name|relocation
operator|+=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
comment|/* Here the variable relocation holds the final address of the      symbol we are relocating against, plus any addend.  */
if|if
condition|(
name|howto
operator|->
name|pc_relative
condition|)
block|{
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
operator|)
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|pcrel_offset
condition|)
name|relocation
operator|-=
name|reloc_entry
operator|->
name|address
expr_stmt|;
block|}
name|in1
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
argument_list|)
expr_stmt|;
name|mask
operator|=
operator|(
literal|1
operator|<<
name|howto
operator|->
name|bitsize
operator|)
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|bitsize
operator|==
literal|6
condition|)
name|mask
operator|<<=
literal|12
expr_stmt|;
name|max
operator|=
operator|(
literal|1
operator|<<
operator|(
name|howto
operator|->
name|bitsize
operator|+
literal|2
operator|)
operator|)
operator|-
literal|1
expr_stmt|;
comment|/* Extract the addend.  */
name|num
operator|=
name|in1
operator|&
name|mask
expr_stmt|;
comment|/* 18 bits.  */
if|if
condition|(
name|howto
operator|->
name|bitsize
operator|==
literal|6
condition|)
name|num
operator|>>=
literal|12
expr_stmt|;
name|num
operator|<<=
literal|3
expr_stmt|;
comment|/* shift left 3.  */
name|in1
operator|&=
operator|~
name|mask
expr_stmt|;
comment|/* Mask out addend.  */
name|relocation
operator|+=
name|num
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|type
operator|==
name|R_D30V_21_PCREL_R
operator|||
name|howto
operator|->
name|type
operator|==
name|R_D30V_15_PCREL_R
operator|||
name|howto
operator|->
name|type
operator|==
name|R_D30V_9_PCREL_R
condition|)
name|relocation
operator|+=
literal|4
expr_stmt|;
if|if
condition|(
operator|(
name|int
operator|)
name|relocation
operator|<
literal|0
condition|)
block|{
if|if
condition|(
operator|~
operator|(
name|int
operator|)
name|relocation
operator|>
name|max
condition|)
name|flag
operator|=
name|bfd_reloc_overflow
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
operator|(
name|int
operator|)
name|relocation
operator|>
name|max
condition|)
name|flag
operator|=
name|bfd_reloc_overflow
expr_stmt|;
block|}
name|relocation
operator|>>=
literal|3
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|bitsize
operator|==
literal|6
condition|)
name|in1
operator||=
operator|(
operator|(
name|relocation
operator|&
operator|(
name|mask
operator|>>
literal|12
operator|)
operator|)
operator|<<
literal|12
operator|)
expr_stmt|;
else|else
name|in1
operator||=
name|relocation
operator|&
name|mask
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|in1
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|addr
argument_list|)
expr_stmt|;
return|return
name|flag
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_d30v_howto_table
index|[]
init|=
block|{
comment|/* This reloc does nothing.  */
name|HOWTO
argument_list|(
name|R_D30V_NONE
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_NONE"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0
argument_list|,
comment|/* Src_mask.  */
literal|0
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A 6 bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_D30V_6
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|6
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_6"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3f
argument_list|,
comment|/* Src_mask.  */
literal|0x3f
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 9 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_9_PCREL
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|6
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_9_PCREL"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3f
argument_list|,
comment|/* Src_mask.  */
literal|0x3f
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 9 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_9_PCREL_R
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|6
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_9_PCREL_R"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3f
argument_list|,
comment|/* Src_mask.  */
literal|0x3f
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* An absolute 15 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_15
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|12
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_15"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xfff
argument_list|,
comment|/* Src_mask.  */
literal|0xfff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 15 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_15_PCREL
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|12
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_15_PCREL"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xfff
argument_list|,
comment|/* Src_mask.  */
literal|0xfff
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 15 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_15_PCREL_R
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|12
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_15_PCREL_R"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xfff
argument_list|,
comment|/* Src_mask.  */
literal|0xfff
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* An absolute 21 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_21
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|18
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_21"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3ffff
argument_list|,
comment|/* Src_mask.  */
literal|0x3ffff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 21 bit relocation, right shifted by 3.  */
name|HOWTO
argument_list|(
name|R_D30V_21_PCREL
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|18
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_21_PCREL"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3ffff
argument_list|,
comment|/* Src_mask.  */
literal|0x3ffff
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 21 bit relocation, right shifted by 3, in the Right container.  */
name|HOWTO
argument_list|(
name|R_D30V_21_PCREL_R
argument_list|,
comment|/* Type.  */
literal|3
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|18
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc_21
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_21_PCREL_R"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0x3ffff
argument_list|,
comment|/* Src_mask.  */
literal|0x3ffff
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A D30V 32 bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_D30V_32
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|4
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_32"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xffffffff
argument_list|,
comment|/* Src_mask.  */
literal|0xffffffff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A relative 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_D30V_32_PCREL
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|4
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|TRUE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_signed
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_d30v_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_32_PCREL"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xffffffff
argument_list|,
comment|/* Src_mask.  */
literal|0xffffffff
argument_list|,
comment|/* Dst_mask.  */
name|TRUE
argument_list|)
block|,
comment|/* PCrel_offset.  */
comment|/* A regular 32 bit absolute relocation.  */
name|HOWTO
argument_list|(
name|R_D30V_32_NORMAL
argument_list|,
comment|/* Type.  */
literal|0
argument_list|,
comment|/* Rightshift.  */
literal|2
argument_list|,
comment|/* Size (0 = byte, 1 = short, 2 = long).  */
literal|32
argument_list|,
comment|/* Bitsize.  */
name|FALSE
argument_list|,
comment|/* PC_relative.  */
literal|0
argument_list|,
comment|/* Bitpos.  */
name|complain_overflow_bitfield
argument_list|,
comment|/* Complain_on_overflow.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* Special_function.  */
literal|"R_D30V_32_NORMAL"
argument_list|,
comment|/* Name.  */
name|FALSE
argument_list|,
comment|/* Partial_inplace.  */
literal|0xffffffff
argument_list|,
comment|/* Src_mask.  */
literal|0xffffffff
argument_list|,
comment|/* Dst_mask.  */
name|FALSE
argument_list|)
block|,
comment|/* PCrel_offset.  */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Map BFD reloc types to D30V ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|d30v_reloc_map
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

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|d30v_reloc_map
name|d30v_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_D30V_NONE
block|, }
block|,
block|{
name|BFD_RELOC_D30V_6
block|,
name|R_D30V_6
block|}
block|,
block|{
name|BFD_RELOC_D30V_9_PCREL
block|,
name|R_D30V_9_PCREL
block|}
block|,
block|{
name|BFD_RELOC_D30V_9_PCREL_R
block|,
name|R_D30V_9_PCREL_R
block|}
block|,
block|{
name|BFD_RELOC_D30V_15
block|,
name|R_D30V_15
block|}
block|,
block|{
name|BFD_RELOC_D30V_15_PCREL
block|,
name|R_D30V_15_PCREL
block|}
block|,
block|{
name|BFD_RELOC_D30V_15_PCREL_R
block|,
name|R_D30V_15_PCREL_R
block|}
block|,
block|{
name|BFD_RELOC_D30V_21
block|,
name|R_D30V_21
block|}
block|,
block|{
name|BFD_RELOC_D30V_21_PCREL
block|,
name|R_D30V_21_PCREL
block|}
block|,
block|{
name|BFD_RELOC_D30V_21_PCREL_R
block|,
name|R_D30V_21_PCREL_R
block|}
block|,
block|{
name|BFD_RELOC_D30V_32
block|,
name|R_D30V_32
block|}
block|,
block|{
name|BFD_RELOC_D30V_32_PCREL
block|,
name|R_D30V_32_PCREL
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_D30V_32_NORMAL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_type_lookup
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
name|d30v_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|d30v_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|d30v_reloc_map
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
name|elf_d30v_howto_table
index|[
name|d30v_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
index|]
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_name_lookup
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
sizeof|sizeof
argument_list|(
name|elf_d30v_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf_d30v_howto_table
index|[
literal|0
index|]
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|elf_d30v_howto_table
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
name|elf_d30v_howto_table
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
name|elf_d30v_howto_table
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
comment|/* Set the howto pointer for an D30V ELF reloc (type REL).  */
end_comment

begin_function
specifier|static
name|void
name|d30v_info_to_howto_rel
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
name|r_type
decl_stmt|;
name|r_type
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
name|r_type
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_D30V_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
operator|&
name|elf_d30v_howto_table
index|[
name|r_type
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set the howto pointer for an D30V ELF reloc (type RELA).  */
end_comment

begin_function
specifier|static
name|void
name|d30v_info_to_howto_rela
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
name|r_type
decl_stmt|;
name|r_type
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
name|r_type
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_D30V_max
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
operator|&
name|elf_d30v_howto_table
index|[
name|r_type
index|]
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_d30v
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_D30V
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT1
value|EM_CYGNUS_D30V
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
name|TARGET_BIG_SYM
value|bfd_elf32_d30v_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-d30v"
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|d30v_info_to_howto_rela
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|d30v_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|0
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|0
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

