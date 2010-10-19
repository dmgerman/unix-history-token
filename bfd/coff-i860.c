begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Intel i860 COFF files.    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1999, 2000, 2001, 2002,    2003, 2004, 2005 Free Software Foundation, Inc.    Created mostly by substituting "860" for "386" in coff-i386.c    Harry Dolan<dolan@ssd.intel.com>, October 1995  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"libbfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/i860.h"
end_include

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"libcoff.h"
end_include

begin_define
define|#
directive|define
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
value|(2)
end_define

begin_comment
comment|/* The page size is a guess based on ELF.  */
end_comment

begin_define
define|#
directive|define
name|COFF_PAGE_SIZE
value|0x1000
end_define

begin_comment
comment|/* For some reason when using i860 COFF the value stored in the .text    section for a reference to a common symbol is the value itself plus    any desired offset.  Ian Taylor, Cygnus Support.  */
end_comment

begin_comment
comment|/* If we are producing relocatable output, we need to do some    adjustments to the object file that are not done by the    bfd_perform_relocation function.  This function is called by every    reloc type to make any required adjustments.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|coff_i860_reloc
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
name|ATTRIBUTE_UNUSED
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
name|symvalue
name|diff
decl_stmt|;
if|if
condition|(
name|output_bfd
operator|==
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
return|return
name|bfd_reloc_continue
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
block|{
comment|/* We are relocating a common symbol.  The current value in the 	 object file is ORIG + OFFSET, where ORIG is the value of the 	 common symbol as seen by the object file when it was compiled 	 (this may be zero if the symbol was undefined) and OFFSET is 	 the offset into the common symbol (normally zero, but may be 	 non-zero when referring to a field in a common structure). 	 ORIG is the negative of reloc_entry->addend, which is set by 	 the CALC_ADDEND macro below.  We want to replace the value in 	 the object file with NEW + OFFSET, where NEW is the value of 	 the common symbol which we are going to put in the final 	 object file.  NEW is symbol->value.  */
name|diff
operator|=
name|symbol
operator|->
name|value
operator|+
name|reloc_entry
operator|->
name|addend
expr_stmt|;
block|}
else|else
block|{
comment|/* For some reason bfd_perform_relocation always effectively 	 ignores the addend for a COFF target when producing 	 relocatable output.  This seems to be always wrong for 860 	 COFF, so we handle the addend here instead.  */
name|diff
operator|=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
block|}
define|#
directive|define
name|DOIT
parameter_list|(
name|x
parameter_list|)
define|\
value|x = ((x& ~howto->dst_mask) | (((x& howto->src_mask) + diff)& howto->dst_mask))
if|if
condition|(
name|diff
operator|!=
literal|0
condition|)
block|{
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
name|unsigned
name|char
modifier|*
name|addr
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
decl_stmt|;
switch|switch
condition|(
name|howto
operator|->
name|size
condition|)
block|{
case|case
literal|0
case|:
block|{
name|char
name|x
init|=
name|bfd_get_8
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
decl_stmt|;
name|DOIT
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|bfd_put_8
argument_list|(
name|abfd
argument_list|,
name|x
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|1
case|:
block|{
name|short
name|x
init|=
name|bfd_get_16
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
decl_stmt|;
name|DOIT
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|bfd_put_16
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|x
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
literal|2
case|:
block|{
name|long
name|x
init|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|addr
argument_list|)
decl_stmt|;
name|DOIT
argument_list|(
name|x
argument_list|)
expr_stmt|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|x
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
name|abort
argument_list|()
expr_stmt|;
block|}
block|}
comment|/* Now let bfd_perform_relocation finish everything up.  */
return|return
name|bfd_reloc_continue
return|;
block|}
end_function

begin_comment
comment|/* This is just a temporary measure until we teach bfd to generate     these relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|coff_i860_reloc_nyi
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
name|ATTRIBUTE_UNUSED
parameter_list|,
name|void
modifier|*
name|data
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
parameter_list|,
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"Relocation `%s' not yet implemented\n"
argument_list|)
argument_list|,
name|howto
operator|->
name|name
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_notsupported
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|PCRELOFFSET
end_ifndef

begin_define
define|#
directive|define
name|PCRELOFFSET
value|FALSE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|howto_table
index|[]
init|=
block|{
name|EMPTY_HOWTO
argument_list|(
literal|0
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|1
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|2
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|3
argument_list|)
block|,
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
name|R_DIR32
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"dir32"
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
comment|/* {7}, */
name|HOWTO
argument_list|(
name|R_IMAGEBASE
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"rva32"
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
literal|010
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|011
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|012
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|013
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|014
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|015
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|016
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_RELBYTE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"8"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_RELWORD
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"16"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_RELLONG
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"32"
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PCRBYTE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|0
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|8
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"DISP8"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PCRWORD
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
comment|/* complain_on_overflow */
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"DISP16"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PCRLONG
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"DISP32"
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
literal|0x15
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x16
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x17
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x18
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x19
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x1a
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|0x1b
argument_list|)
block|,
name|HOWTO
argument_list|(
name|COFF860_R_PAIR
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
name|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"PAIR"
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
name|EMPTY_HOWTO
argument_list|(
literal|0x1d
argument_list|)
block|,
name|HOWTO
argument_list|(
name|COFF860_R_HIGH
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"HIGH"
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
name|COFF860_R_LOW0
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"LOW0"
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
name|COFF860_R_LOW1
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"LOW1"
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
name|COFF860_R_LOW2
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"LOW2"
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
name|COFF860_R_LOW3
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"LOW3"
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
name|COFF860_R_LOW4
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
name|coff_i860_reloc
argument_list|,
comment|/* special_function */
literal|"LOW4"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0xfff0
argument_list|,
comment|/* src_mask */
literal|0xfff0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|COFF860_R_SPLIT0
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
name|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"SPLIT0"
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
name|COFF860_R_SPLIT1
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
name|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"SPLIT1"
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
name|COFF860_R_SPLIT2
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
name|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"SPLIT2"
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
name|COFF860_R_HIGHADJ
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
name|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"HIGHADJ"
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
argument|COFF860_R_BRADDR
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
argument|TRUE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
argument|coff_i860_reloc_nyi
argument_list|,
comment|/* special_function */
literal|"BRADDR"
argument_list|,
comment|/* name */
argument|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffffff
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
argument|TRUE
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn a howto into a reloc number.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_RELOC
parameter_list|(
name|x
parameter_list|,
name|howto
parameter_list|)
value|{ x.r_type = howto->type; }
end_define

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|I860BADMAG(x)
end_define

begin_define
define|#
directive|define
name|I860
value|1
end_define

begin_comment
comment|/* Customize coffcode.h */
end_comment

begin_define
define|#
directive|define
name|RTYPE2HOWTO
parameter_list|(
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
define|\
value|((cache_ptr)->howto =							\    ((dst)->r_type< sizeof (howto_table) / sizeof (howto_table[0])	\     ? howto_table + (dst)->r_type					\     : NULL))
end_define

begin_comment
comment|/* For 860 COFF a STYP_NOLOAD | STYP_BSS section is part of a shared    library.  On some other COFF targets STYP_BSS is normally    STYP_NOLOAD.  */
end_comment

begin_define
define|#
directive|define
name|BSS_NOLOAD_IS_SHARED_LIBRARY
end_define

begin_comment
comment|/* Compute the addend of a reloc.  If the reloc is to a common symbol,    the object file contains the value of the common symbol.  By the    time this is called, the linker may be using a different symbol    from a different object file with a different value.  Therefore, we    hack wildly to locate the original symbol from this file so that we    can make the correct adjustment.  This macro sets coffsym to the    symbol from the original file, and uses it to set the addend value    correctly.  If this is not a common symbol, the usual addend    calculation is done, except that an additional tweak is needed for    PC relative relocs.    FIXME: This macro refers to symbols and asect; these are from the    calling function, not the macro arguments.  */
end_comment

begin_define
define|#
directive|define
name|CALC_ADDEND
parameter_list|(
name|abfd
parameter_list|,
name|ptr
parameter_list|,
name|reloc
parameter_list|,
name|cache_ptr
parameter_list|)
end_define

begin_comment
comment|/* We use the special COFF backend linker.  */
end_comment

begin_define
define|#
directive|define
name|coff_relocate_section
value|_bfd_coff_generic_relocate_section
end_define

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_i860_rtype_to_howto
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|struct
name|internal_reloc
modifier|*
name|rel
parameter_list|,
name|struct
name|coff_link_hash_entry
modifier|*
name|h
parameter_list|,
name|struct
name|internal_syment
modifier|*
name|sym
parameter_list|,
name|bfd_vma
modifier|*
name|addendp
parameter_list|)
block|{
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
if|if
condition|(
name|rel
operator|->
name|r_type
operator|>
sizeof|sizeof
argument_list|(
name|howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|howto_table
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|howto
operator|=
name|howto_table
operator|+
name|rel
operator|->
name|r_type
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|pc_relative
condition|)
operator|*
name|addendp
operator|+=
name|sec
operator|->
name|vma
expr_stmt|;
if|if
condition|(
name|sym
operator|!=
name|NULL
operator|&&
name|sym
operator|->
name|n_scnum
operator|==
literal|0
operator|&&
name|sym
operator|->
name|n_value
operator|!=
literal|0
condition|)
block|{
comment|/* This is a common symbol.  The section contents include the 	 size (sym->n_value) as an addend.  The relocate_section 	 function will be adding in the final value of the symbol.  We 	 need to subtract out the current size in order to get the 	 correct result.  */
name|BFD_ASSERT
argument_list|(
name|h
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* I think we *do* want to bypass this.  If we don't, I have seen some data 	 parameters get the wrong relocation address.  If I link two versions 	 with and without this section bypassed and then do a binary comparison, 	 the addresses which are different can be looked up in the map.  The 	 case in which this section has been bypassed has addresses which correspond 	 to values I can find in the map.  */
operator|*
name|addendp
operator|-=
name|sym
operator|->
name|n_value
expr_stmt|;
block|}
comment|/* If the output symbol is common (in which case this must be a      relocatable link), we need to add in the final size of the      common symbol.  */
if|if
condition|(
name|h
operator|!=
name|NULL
operator|&&
name|h
operator|->
name|root
operator|.
name|type
operator|==
name|bfd_link_hash_common
condition|)
operator|*
name|addendp
operator|+=
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|c
operator|.
name|size
expr_stmt|;
return|return
name|howto
return|;
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_i860_reloc_type_lookup
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
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|BFD_RELOC_32
case|:
return|return
name|howto_table
operator|+
name|R_DIR32
return|;
case|case
name|BFD_RELOC_860_PC26
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_BRADDR
return|;
case|case
name|BFD_RELOC_860_PC16
case|:
comment|/* ??? How to handle PC16 for COFF?  SPLIT0 is close for now.  */
return|return
name|howto_table
operator|+
name|COFF860_R_SPLIT0
return|;
case|case
name|BFD_RELOC_860_LOW0
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_LOW0
return|;
case|case
name|BFD_RELOC_860_SPLIT0
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_SPLIT0
return|;
case|case
name|BFD_RELOC_860_LOW1
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_LOW1
return|;
case|case
name|BFD_RELOC_860_SPLIT1
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_SPLIT1
return|;
case|case
name|BFD_RELOC_860_LOW2
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_LOW2
return|;
case|case
name|BFD_RELOC_860_SPLIT2
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_SPLIT2
return|;
case|case
name|BFD_RELOC_860_LOW3
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_LOW3
return|;
case|case
name|BFD_RELOC_860_HIGHADJ
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_HIGHADJ
return|;
case|case
name|BFD_RELOC_860_HIGH
case|:
return|return
name|howto_table
operator|+
name|COFF860_R_HIGH
return|;
default|default:
name|BFD_FAIL
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|/* This is called from coff_slurp_reloc_table for each relocation    entry.  This special handling is due to the `PAIR' relocation    which has a different meaning for the `r_symndx' field.  */
end_comment

begin_function
specifier|static
name|void
name|i860_reloc_processing
parameter_list|(
name|arelent
modifier|*
name|cache_ptr
parameter_list|,
name|struct
name|internal_reloc
modifier|*
name|dst
parameter_list|,
name|asymbol
modifier|*
modifier|*
name|symbols
parameter_list|,
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|asect
parameter_list|)
block|{
if|if
condition|(
name|dst
operator|->
name|r_type
operator|==
name|COFF860_R_PAIR
condition|)
block|{
comment|/* Handle the PAIR relocation specially.  */
name|cache_ptr
operator|->
name|howto
operator|=
name|howto_table
operator|+
name|dst
operator|->
name|r_type
expr_stmt|;
name|cache_ptr
operator|->
name|address
operator|=
name|dst
operator|->
name|r_vaddr
expr_stmt|;
name|cache_ptr
operator|->
name|addend
operator|=
name|dst
operator|->
name|r_symndx
expr_stmt|;
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
block|}
else|else
block|{
comment|/* For every other relocation, do exactly what coff_slurp_reloc_table          would do (which this code is taken directly from).  */
name|asymbol
modifier|*
name|ptr
init|=
name|NULL
decl_stmt|;
name|cache_ptr
operator|->
name|address
operator|=
name|dst
operator|->
name|r_vaddr
expr_stmt|;
if|if
condition|(
name|dst
operator|->
name|r_symndx
operator|!=
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|dst
operator|->
name|r_symndx
operator|<
literal|0
operator|||
name|dst
operator|->
name|r_symndx
operator|>=
name|obj_conv_table_size
argument_list|(
name|abfd
argument_list|)
condition|)
block|{
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"%B: warning: illegal symbol index %ld in relocs"
argument_list|)
argument_list|,
name|abfd
argument_list|,
name|dst
operator|->
name|r_symndx
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|ptr
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|=
operator|(
name|symbols
operator|+
name|obj_convert
argument_list|(
name|abfd
argument_list|)
index|[
name|dst
operator|->
name|r_symndx
index|]
operator|)
expr_stmt|;
name|ptr
operator|=
operator|*
operator|(
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|)
expr_stmt|;
block|}
block|}
else|else
block|{
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|ptr
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* The symbols definitions that we have read in have been 	 relocated as if their sections started at 0. But the offsets 	 refering to the symbols in the raw data have not been 	 modified, so we have to have a negative addend to compensate.  	 Note that symbols which used to be common must be left alone.  */
comment|/* Calculate any reloc addend by looking at the symbol.  */
name|CALC_ADDEND
argument_list|(
name|abfd
argument_list|,
name|ptr
argument_list|,
operator|(
operator|*
name|dst
operator|)
argument_list|,
name|cache_ptr
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|address
operator|-=
name|asect
operator|->
name|vma
expr_stmt|;
comment|/* Fill in the cache_ptr->howto field from dst->r_type.  */
name|RTYPE2HOWTO
argument_list|(
name|cache_ptr
argument_list|,
name|dst
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_escape
end_escape

begin_define
define|#
directive|define
name|coff_rtype_to_howto
value|coff_i860_rtype_to_howto
end_define

begin_define
define|#
directive|define
name|coff_bfd_reloc_type_lookup
value|coff_i860_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|RELOC_PROCESSING
parameter_list|(
name|relent
parameter_list|,
name|reloc
parameter_list|,
name|symbols
parameter_list|,
name|abfd
parameter_list|,
name|section
parameter_list|)
define|\
value|i860_reloc_processing (relent, reloc, symbols, abfd, section)
end_define

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_function
specifier|static
specifier|const
name|bfd_target
modifier|*
name|i3coff_object_p
parameter_list|(
name|bfd
modifier|*
name|a
parameter_list|)
block|{
return|return
name|coff_object_p
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|bfd_target
ifdef|#
directive|ifdef
name|TARGET_SYM
name|TARGET_SYM
init|=
else|#
directive|else
name|i860coff_vec
operator|=
endif|#
directive|endif
block|{
ifdef|#
directive|ifdef
name|TARGET_NAME
name|TARGET_NAME
block|,
else|#
directive|else
literal|"coff-i860"
block|,
comment|/* name */
endif|#
directive|endif
name|bfd_target_coff_flavour
block|,
name|BFD_ENDIAN_LITTLE
block|,
comment|/* data byte order is little */
name|BFD_ENDIAN_LITTLE
block|,
comment|/* header byte order is little */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* object flags */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|WP_TEXT
operator||
name|D_PAGED
operator|)
block|,
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* section flags */
literal|'_'
block|,
comment|/* leading underscore */
literal|'/'
block|,
comment|/* ar_pad_char */
literal|15
block|,
comment|/* ar_max_namelen */
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* data */
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* hdrs */
comment|/* Note that we allow an object file to be treated as a core file as well.  */
block|{
name|_bfd_dummy_target
block|,
name|i3coff_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|i3coff_object_p
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_mkobject
block|,
name|_bfd_generic_mkarchive
block|,
comment|/* bfd_set_format */
name|bfd_false
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_write_object_contents
block|,
comment|/* bfd_write_contents */
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|_bfd_nocore
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_archive_coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|_bfd_nodynamic
argument_list|)
block|,
name|NULL
block|,
name|COFF_SWAP_TABLE
block|}
decl_stmt|;
end_decl_stmt

end_unit

