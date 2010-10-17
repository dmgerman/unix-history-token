begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Texas Instruments TMS320C80 Multimedia Video Processor (MVP).    Copyright 1996, 1997, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.     Written by Fred Fish (fnf@cygnus.com)     There is nothing new under the sun. This file draws a lot on other    coff files.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bfdlink.h"
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
file|"coff/tic80.h"
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

begin_define
define|#
directive|define
name|COFF_ALIGN_IN_SECTION_HEADER
value|1
end_define

begin_define
define|#
directive|define
name|COFF_ALIGN_IN_SFLAGS
value|1
end_define

begin_define
define|#
directive|define
name|GET_SCNHDR_FLAGS
value|H_GET_16
end_define

begin_define
define|#
directive|define
name|PUT_SCNHDR_FLAGS
value|H_PUT_16
end_define

begin_decl_stmt
specifier|static
name|void
name|rtype2howto
name|PARAMS
argument_list|(
operator|(
name|arelent
operator|*
name|cache_ptr
operator|,
expr|struct
name|internal_reloc
operator|*
name|dst
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|ppbase_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|glob15_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|glob16_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|local16_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|arelent
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|PTR
operator|,
name|asection
operator|*
operator|,
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_boolean
name|coff_tic80_relocate_section
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
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_byte
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|,
expr|struct
name|internal_syment
operator|*
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
name|reloc_howto_type
modifier|*
name|coff_tic80_rtype_to_howto
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|,
expr|struct
name|coff_link_hash_entry
operator|*
operator|,
expr|struct
name|internal_syment
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
name|reloc_howto_type
name|tic80_howto_table
index|[]
init|=
block|{
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
name|NULL
argument_list|,
comment|/* special_function */
literal|"RELLONG"
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
name|R_MPPCR
argument_list|,
comment|/* type */
literal|2
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
name|NULL
argument_list|,
comment|/* special_function */
literal|"MPPCR"
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
name|HOWTO
argument_list|(
name|R_ABS
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
name|NULL
argument_list|,
comment|/* special_function */
literal|"ABS"
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
name|R_PPBASE
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
name|ppbase_reloc
argument_list|,
comment|/* special_function */
literal|"PPBASE"
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
name|R_PPLBASE
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
name|ppbase_reloc
argument_list|,
comment|/* special_function */
literal|"PPLBASE"
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
name|R_PP15
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PP15"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PP15W
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PP15W"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PP15H
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PP15H"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PP16B
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
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob16_reloc
argument_list|,
comment|/* special_function */
literal|"PP16B"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffc0
argument_list|,
comment|/* src_mask */
literal|0x3ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPL15
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPL15"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPL15W
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPL15W"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPL15H
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPL15H"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPL16B
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
name|local16_reloc
argument_list|,
comment|/* special_function */
literal|"PPL16B"
argument_list|,
comment|/* name */
name|TRUE
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
name|R_PPN15
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PPN15"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPN15W
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PPN15W"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPN15H
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob15_reloc
argument_list|,
comment|/* special_function */
literal|"PPN15H"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x1ffc0
argument_list|,
comment|/* src_mask */
literal|0x1ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPN16B
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|16
argument_list|,
comment|/* bitsize */
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|glob16_reloc
argument_list|,
comment|/* special_function */
literal|"PPN16B"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffc0
argument_list|,
comment|/* src_mask */
literal|0x3ffc0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPLN15
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPLN15"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPLN15W
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPLN15W"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PPLN15H
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
operator|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
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
literal|"PPLN15H"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x7fff
argument_list|,
comment|/* src_mask */
literal|0x7fff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
argument|R_PPLN16B
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
argument|-
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|15
argument_list|,
comment|/* bitsize */
argument|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
argument|local16_reloc
argument_list|,
comment|/* special_function */
literal|"PPLN16B"
argument_list|,
comment|/* name */
argument|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
argument|FALSE
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Special relocation functions, used when the output file is not    itself a COFF TIc80 file.  */
end_comment

begin_comment
comment|/* This special function is used for the base address type    relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|ppbase_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol_in
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asymbol
modifier|*
name|symbol_in
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|PTR
name|data
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
comment|/* FIXME.  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This special function is used for the global 15 bit relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|glob15_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol_in
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asymbol
modifier|*
name|symbol_in
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|PTR
name|data
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
comment|/* FIXME.  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This special function is used for the global 16 bit relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|glob16_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol_in
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asymbol
modifier|*
name|symbol_in
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|PTR
name|data
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
comment|/* FIXME.  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* This special function is used for the local 16 bit relocations.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|local16_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol_in
parameter_list|,
name|data
parameter_list|,
name|input_section
parameter_list|,
name|output_bfd
parameter_list|,
name|error_message
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asymbol
modifier|*
name|symbol_in
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|PTR
name|data
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asection
modifier|*
name|input_section
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
comment|/* FIXME.  */
name|abort
argument_list|()
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Code to turn an external r_type into a pointer to an entry in the howto_table.    If passed an r_type we don't recognize the abort rather than silently failing    to generate an output file.  */
end_comment

begin_function
specifier|static
name|void
name|rtype2howto
parameter_list|(
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
name|arelent
modifier|*
name|cache_ptr
decl_stmt|;
name|struct
name|internal_reloc
modifier|*
name|dst
decl_stmt|;
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
name|tic80_howto_table
operator|/
sizeof|sizeof
name|tic80_howto_table
index|[
literal|0
index|]
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|tic80_howto_table
index|[
name|i
index|]
operator|.
name|type
operator|==
name|dst
operator|->
name|r_type
condition|)
block|{
name|cache_ptr
operator|->
name|howto
operator|=
name|tic80_howto_table
operator|+
name|i
expr_stmt|;
return|return;
block|}
block|}
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"Unrecognized reloc type 0x%x"
argument_list|)
argument_list|,
operator|(
name|unsigned
name|int
operator|)
name|dst
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
name|tic80_howto_table
operator|+
literal|0
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|RTYPE2HOWTO
parameter_list|(
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
value|rtype2howto (cache_ptr, dst)
end_define

begin_define
define|#
directive|define
name|coff_rtype_to_howto
value|coff_tic80_rtype_to_howto
end_define

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_tic80_rtype_to_howto
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|rel
parameter_list|,
name|h
parameter_list|,
name|sym
parameter_list|,
name|addendp
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|struct
name|internal_reloc
modifier|*
name|rel
decl_stmt|;
name|struct
name|coff_link_hash_entry
modifier|*
name|h
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|struct
name|internal_syment
modifier|*
name|sym
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd_vma
modifier|*
name|addendp
decl_stmt|;
block|{
name|arelent
name|genrel
decl_stmt|;
if|if
condition|(
name|rel
operator|->
name|r_symndx
operator|==
operator|-
literal|1
operator|&&
name|addendp
operator|!=
name|NULL
condition|)
block|{
comment|/* This is a TI "internal relocation", which means that the relocation 	 amount is the amount by which the current section is being relocated 	 in the output section.  */
operator|*
name|addendp
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
operator|)
operator|-
name|sec
operator|->
name|vma
expr_stmt|;
block|}
name|RTYPE2HOWTO
argument_list|(
operator|&
name|genrel
argument_list|,
name|rel
argument_list|)
expr_stmt|;
return|return
name|genrel
operator|.
name|howto
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|BADMAG
end_ifndef

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|TIC80BADMAG(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|coff_relocate_section
value|coff_tic80_relocate_section
end_define

begin_comment
comment|/* We need a special relocation routine to handle the PP relocs.  Most    of this is a copy of _bfd_coff_generic_relocate_section.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|coff_tic80_relocate_section
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
name|syms
parameter_list|,
name|sections
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
name|struct
name|internal_reloc
modifier|*
name|relocs
decl_stmt|;
name|struct
name|internal_syment
modifier|*
name|syms
decl_stmt|;
name|asection
modifier|*
modifier|*
name|sections
decl_stmt|;
block|{
name|struct
name|internal_reloc
modifier|*
name|rel
decl_stmt|;
name|struct
name|internal_reloc
modifier|*
name|relend
decl_stmt|;
name|rel
operator|=
name|relocs
expr_stmt|;
name|relend
operator|=
name|rel
operator|+
name|input_section
operator|->
name|reloc_count
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
name|long
name|symndx
decl_stmt|;
name|struct
name|coff_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|struct
name|internal_syment
modifier|*
name|sym
decl_stmt|;
name|bfd_vma
name|addend
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|bfd_reloc_status_type
name|rstat
decl_stmt|;
name|bfd_vma
name|addr
decl_stmt|;
name|symndx
operator|=
name|rel
operator|->
name|r_symndx
expr_stmt|;
if|if
condition|(
name|symndx
operator|==
operator|-
literal|1
condition|)
block|{
name|h
operator|=
name|NULL
expr_stmt|;
name|sym
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|h
operator|=
name|obj_coff_sym_hashes
argument_list|(
name|input_bfd
argument_list|)
index|[
name|symndx
index|]
expr_stmt|;
name|sym
operator|=
name|syms
operator|+
name|symndx
expr_stmt|;
block|}
comment|/* COFF treats common symbols in one of two ways.  Either the          size of the symbol is included in the section contents, or it          is not.  We assume that the size is not included, and force          the rtype_to_howto function to adjust the addend as needed.  */
if|if
condition|(
name|sym
operator|!=
name|NULL
operator|&&
name|sym
operator|->
name|n_scnum
operator|!=
literal|0
condition|)
name|addend
operator|=
operator|-
name|sym
operator|->
name|n_value
expr_stmt|;
else|else
name|addend
operator|=
literal|0
expr_stmt|;
name|howto
operator|=
name|bfd_coff_rtype_to_howto
argument_list|(
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
argument_list|,
name|h
argument_list|,
name|sym
argument_list|,
operator|&
name|addend
argument_list|)
expr_stmt|;
if|if
condition|(
name|howto
operator|==
name|NULL
condition|)
return|return
name|FALSE
return|;
name|val
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|h
operator|==
name|NULL
condition|)
block|{
name|asection
modifier|*
name|sec
decl_stmt|;
if|if
condition|(
name|symndx
operator|==
operator|-
literal|1
condition|)
block|{
name|sec
operator|=
name|bfd_abs_section_ptr
expr_stmt|;
name|val
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|sec
operator|=
name|sections
index|[
name|symndx
index|]
expr_stmt|;
name|val
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
name|n_value
operator|)
expr_stmt|;
if|if
condition|(
operator|!
name|obj_pe
argument_list|(
name|output_bfd
argument_list|)
condition|)
name|val
operator|-=
name|sec
operator|->
name|vma
expr_stmt|;
block|}
block|}
else|else
block|{
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
name|asection
modifier|*
name|sec
decl_stmt|;
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
name|val
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
operator|!
name|info
operator|->
name|relocatable
condition|)
block|{
if|if
condition|(
operator|!
operator|(
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
name|r_vaddr
operator|-
name|input_section
operator|->
name|vma
argument_list|,
name|TRUE
argument_list|)
operator|)
condition|)
return|return
name|FALSE
return|;
block|}
block|}
name|addr
operator|=
name|rel
operator|->
name|r_vaddr
operator|-
name|input_section
operator|->
name|vma
expr_stmt|;
comment|/* FIXME: This code assumes little endian, but the PP can          apparently be bi-endian.  I don't know if the bi-endianness          applies to the instruction set or just to the data.  */
switch|switch
condition|(
name|howto
operator|->
name|type
condition|)
block|{
default|default:
case|case
name|R_ABS
case|:
case|case
name|R_RELLONGX
case|:
case|case
name|R_PPL15
case|:
case|case
name|R_PPL15W
case|:
case|case
name|R_PPL15H
case|:
case|case
name|R_PPLN15
case|:
case|case
name|R_PPLN15W
case|:
case|case
name|R_PPLN15H
case|:
name|rstat
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
name|addr
argument_list|,
name|val
argument_list|,
name|addend
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_PP15
case|:
case|case
name|R_PP15W
case|:
case|case
name|R_PP15H
case|:
case|case
name|R_PPN15
case|:
case|case
name|R_PPN15W
case|:
case|case
name|R_PPN15H
case|:
comment|/* Offset the address so that we can use 4 byte relocations.  */
name|rstat
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
operator|+
literal|2
argument_list|,
name|addr
argument_list|,
name|val
argument_list|,
name|addend
argument_list|)
expr_stmt|;
break|break;
case|case
name|R_PP16B
case|:
case|case
name|R_PPN16B
case|:
block|{
comment|/* The most significant bit is stored in bit 6.  */
name|bfd_byte
name|hold
decl_stmt|;
name|hold
operator|=
name|contents
index|[
name|addr
operator|+
literal|4
index|]
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|4
index|]
operator|&=
operator|~
literal|0x20
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|4
index|]
operator||=
operator|(
name|contents
index|[
name|addr
index|]
operator|>>
literal|1
operator|)
operator|&
literal|0x20
expr_stmt|;
name|rstat
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
operator|+
literal|2
argument_list|,
name|addr
argument_list|,
name|val
argument_list|,
name|addend
argument_list|)
expr_stmt|;
name|contents
index|[
name|addr
index|]
operator|&=
operator|~
literal|0x40
expr_stmt|;
name|contents
index|[
name|addr
index|]
operator||=
operator|(
name|contents
index|[
name|addr
operator|+
literal|4
index|]
operator|<<
literal|1
operator|)
operator|&
literal|0x40
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|4
index|]
operator|&=
operator|~
literal|0x20
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|4
index|]
operator||=
name|hold
operator|&
literal|0x20
expr_stmt|;
break|break;
block|}
case|case
name|R_PPL16B
case|:
case|case
name|R_PPLN16B
case|:
block|{
comment|/* The most significant bit is stored in bit 28.  */
name|bfd_byte
name|hold
decl_stmt|;
name|hold
operator|=
name|contents
index|[
name|addr
operator|+
literal|1
index|]
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|1
index|]
operator|&=
operator|~
literal|0x80
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|1
index|]
operator||=
operator|(
name|contents
index|[
name|addr
operator|+
literal|3
index|]
operator|<<
literal|3
operator|)
operator|&
literal|0x80
expr_stmt|;
name|rstat
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
name|addr
argument_list|,
name|val
argument_list|,
name|addend
argument_list|)
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|3
index|]
operator|&=
operator|~
literal|0x10
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|3
index|]
operator||=
operator|(
name|contents
index|[
name|addr
operator|+
literal|1
index|]
operator|>>
literal|3
operator|)
operator|&
literal|0x10
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|1
index|]
operator|&=
operator|~
literal|0x80
expr_stmt|;
name|contents
index|[
name|addr
operator|+
literal|1
index|]
operator||=
name|hold
operator|&
literal|0x80
expr_stmt|;
break|break;
block|}
case|case
name|R_PPBASE
case|:
comment|/* Parameter RAM is from 0x1000000 to 0x1000800.  */
name|contents
index|[
name|addr
index|]
operator|&=
operator|~
literal|0x3
expr_stmt|;
if|if
condition|(
name|val
operator|>=
literal|0x1000000
operator|&&
name|val
operator|<
literal|0x1000800
condition|)
name|contents
index|[
name|addr
index|]
operator||=
literal|0x3
expr_stmt|;
else|else
name|contents
index|[
name|addr
index|]
operator||=
literal|0x2
expr_stmt|;
name|rstat
operator|=
name|bfd_reloc_ok
expr_stmt|;
break|break;
case|case
name|R_PPLBASE
case|:
comment|/* Parameter RAM is from 0x1000000 to 0x1000800.  */
name|contents
index|[
name|addr
operator|+
literal|2
index|]
operator|&=
operator|~
literal|0xc0
expr_stmt|;
if|if
condition|(
name|val
operator|>=
literal|0x1000000
operator|&&
name|val
operator|<
literal|0x1000800
condition|)
name|contents
index|[
name|addr
operator|+
literal|2
index|]
operator||=
literal|0xc0
expr_stmt|;
else|else
name|contents
index|[
name|addr
operator|+
literal|2
index|]
operator||=
literal|0x80
expr_stmt|;
name|rstat
operator|=
name|bfd_reloc_ok
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|rstat
condition|)
block|{
default|default:
name|abort
argument_list|()
expr_stmt|;
case|case
name|bfd_reloc_ok
case|:
break|break;
case|case
name|bfd_reloc_outofrange
case|:
call|(
modifier|*
name|_bfd_error_handler
call|)
argument_list|(
name|_
argument_list|(
literal|"%s: bad reloc address 0x%lx in section `%s'"
argument_list|)
argument_list|,
name|bfd_archive_filename
argument_list|(
name|input_bfd
argument_list|)
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|rel
operator|->
name|r_vaddr
argument_list|,
name|bfd_get_section_name
argument_list|(
name|input_bfd
argument_list|,
name|input_section
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
case|case
name|bfd_reloc_overflow
case|:
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|char
name|buf
index|[
name|SYMNMLEN
operator|+
literal|1
index|]
decl_stmt|;
if|if
condition|(
name|symndx
operator|==
operator|-
literal|1
condition|)
name|name
operator|=
literal|"*ABS*"
expr_stmt|;
elseif|else
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
name|_bfd_coff_internal_syment_name
argument_list|(
name|input_bfd
argument_list|,
name|sym
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
return|return
name|FALSE
return|;
block|}
if|if
condition|(
operator|!
operator|(
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
name|rel
operator|->
name|r_vaddr
operator|-
name|input_section
operator|->
name|vma
argument_list|)
operator|)
condition|)
return|return
name|FALSE
return|;
block|}
block|}
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_escape
end_escape

begin_define
define|#
directive|define
name|TIC80COFF
value|1
end_define

begin_comment
comment|/* Customize coffcode.h */
end_comment

begin_undef
undef|#
directive|undef
name|C_AUTOARG
end_undef

begin_comment
comment|/* Clashes with TIc80's C_UEXT */
end_comment

begin_undef
undef|#
directive|undef
name|C_LASTENT
end_undef

begin_comment
comment|/* Clashes with TIc80's C_STATLAB */
end_comment

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_macro
name|CREATE_LITTLE_COFF_TARGET_VEC
argument_list|(
argument|tic80coff_vec
argument_list|,
literal|"coff-tic80"
argument_list|,
argument|D_PAGED
argument_list|,
literal|0
argument_list|,
literal|'_'
argument_list|,
argument|NULL
argument_list|,
argument|COFF_SWAP_TABLE
argument_list|)
end_macro

end_unit

