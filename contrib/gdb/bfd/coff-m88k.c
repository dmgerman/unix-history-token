begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Motorola 88000 COFF "Binary Compatability Standard" files.    Copyright 1990, 1991, 1992, 1993, 1994 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|M88
value|1
end_define

begin_comment
comment|/* Customize various include files */
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
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"coff/m88k.h"
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

begin_decl_stmt
specifier|static
name|bfd_reloc_status_type
name|m88k_special_reloc
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
name|void
name|rtype2howto
name|PARAMS
argument_list|(
operator|(
name|arelent
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|reloc_processing
name|PARAMS
argument_list|(
operator|(
name|arelent
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
value|(3)
end_define

begin_function
specifier|static
name|bfd_reloc_status_type
name|m88k_special_reloc
parameter_list|(
name|abfd
parameter_list|,
name|reloc_entry
parameter_list|,
name|symbol
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
decl_stmt|;
name|arelent
modifier|*
name|reloc_entry
decl_stmt|;
name|asymbol
modifier|*
name|symbol
decl_stmt|;
name|PTR
name|data
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
decl_stmt|;
block|{
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
switch|switch
condition|(
name|howto
operator|->
name|type
condition|)
block|{
case|case
name|R_HVRT16
case|:
case|case
name|R_LVRT16
case|:
if|if
condition|(
name|output_bfd
operator|!=
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
block|{
comment|/* This is a partial relocation, and we want to apply the 	     relocation to the reloc entry rather than the raw data. 	     Modify the reloc inplace to reflect what we now know.  */
name|reloc_entry
operator|->
name|address
operator|+=
name|input_section
operator|->
name|output_offset
expr_stmt|;
block|}
else|else
block|{
name|bfd_vma
name|output_base
init|=
literal|0
decl_stmt|;
name|bfd_vma
name|addr
init|=
name|reloc_entry
operator|->
name|address
decl_stmt|;
name|bfd_vma
name|x
init|=
name|bfd_get_16
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
decl_stmt|;
name|asection
modifier|*
name|reloc_target_output_section
decl_stmt|;
name|long
name|relocation
init|=
literal|0
decl_stmt|;
comment|/* Work out which section the relocation is targetted at and the 	     initial relocation command value.  */
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
if|if
condition|(
name|output_bfd
condition|)
name|output_base
operator|=
literal|0
expr_stmt|;
else|else
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
operator|(
operator|(
name|reloc_entry
operator|->
name|addend
operator|<<
name|howto
operator|->
name|bitsize
operator|)
operator|+
name|x
operator|)
expr_stmt|;
name|reloc_entry
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
name|relocation
operator|>>=
operator|(
name|bfd_vma
operator|)
name|howto
operator|->
name|rightshift
expr_stmt|;
comment|/* Shift everything up to where it's going to be used */
name|relocation
operator|<<=
operator|(
name|bfd_vma
operator|)
name|howto
operator|->
name|bitpos
expr_stmt|;
if|if
condition|(
name|relocation
condition|)
name|bfd_put_16
argument_list|(
name|abfd
argument_list|,
name|relocation
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|data
operator|+
name|addr
argument_list|)
expr_stmt|;
block|}
return|return
name|bfd_reloc_ok
return|;
break|break;
default|default:
if|if
condition|(
name|output_bfd
operator|!=
operator|(
name|bfd
operator|*
operator|)
name|NULL
condition|)
block|{
comment|/* This is a partial relocation, and we want to apply the 	     relocation to the reloc entry rather than the raw data. 	     Modify the reloc inplace to reflect what we now know.  */
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
break|break;
block|}
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
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|howto_table
index|[]
init|=
block|{
name|HOWTO
argument_list|(
name|R_PCR16L
argument_list|,
comment|/* type */
literal|02
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"PCR16L"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_PCR26L
argument_list|,
comment|/* type */
literal|02
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"PCR26L"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x03ffffff
argument_list|,
comment|/* src_mask */
literal|0x03ffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_VRT16
argument_list|,
comment|/* type */
literal|00
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"VRT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_HVRT16
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"HVRT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_LVRT16
argument_list|,
comment|/* type */
literal|00
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"LVRT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_VRT32
argument_list|,
comment|/* type */
literal|00
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
name|m88k_special_reloc
argument_list|,
comment|/* special_function */
literal|"VRT32"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Code to turn an external r_type into a pointer to an entry in the    above howto table.  */
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
if|if
condition|(
name|dst
operator|->
name|r_type
operator|>=
name|R_PCR16L
operator|&&
name|dst
operator|->
name|r_type
operator|<=
name|R_VRT32
condition|)
block|{
name|cache_ptr
operator|->
name|howto
operator|=
name|howto_table
operator|+
name|dst
operator|->
name|r_type
operator|-
name|R_PCR16L
expr_stmt|;
block|}
else|else
block|{
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
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

begin_comment
comment|/* Code to swap in the reloc offset */
end_comment

begin_define
define|#
directive|define
name|SWAP_IN_RELOC_OFFSET
value|bfd_h_get_16
end_define

begin_define
define|#
directive|define
name|SWAP_OUT_RELOC_OFFSET
value|bfd_h_put_16
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
value|reloc_processing(relent, reloc, symbols, abfd, section)
end_define

begin_function
specifier|static
name|void
name|reloc_processing
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
name|arelent
modifier|*
name|relent
decl_stmt|;
name|struct
name|internal_reloc
modifier|*
name|reloc
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|;
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|section
decl_stmt|;
block|{
name|relent
operator|->
name|address
operator|=
name|reloc
operator|->
name|r_vaddr
expr_stmt|;
name|rtype2howto
argument_list|(
name|relent
argument_list|,
name|reloc
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
operator|(
name|int
operator|)
name|reloc
operator|->
name|r_symndx
operator|)
operator|>
literal|0
condition|)
block|{
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|symbols
operator|+
name|obj_convert
argument_list|(
name|abfd
argument_list|)
index|[
name|reloc
operator|->
name|r_symndx
index|]
expr_stmt|;
block|}
else|else
block|{
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
block|}
name|relent
operator|->
name|addend
operator|=
name|reloc
operator|->
name|r_offset
expr_stmt|;
name|relent
operator|->
name|address
operator|-=
name|section
operator|->
name|vma
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|MC88BADMAG(x)
end_define

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_undef
undef|#
directive|undef
name|coff_write_armap
end_undef

begin_decl_stmt
specifier|const
name|bfd_target
name|m88kbcs_vec
init|=
block|{
literal|"coff-m88kbcs"
block|,
comment|/* name */
name|bfd_target_coff_flavour
block|,
name|BFD_ENDIAN_BIG
block|,
comment|/* data byte order is big */
name|BFD_ENDIAN_BIG
block|,
comment|/* header byte order is big */
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
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* data */
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* hdrs */
block|{
name|_bfd_dummy_target
block|,
name|coff_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|_bfd_dummy_target
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
name|COFF_SWAP_TABLE
block|, }
decl_stmt|;
end_decl_stmt

end_unit

