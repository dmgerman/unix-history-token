begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Intel 386 COFF files.    Copyright 1990, 1991, 1992, 1993, 1994 Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
file|"coff/i386.h"
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
name|coff_i386_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|arelent
operator|*
name|reloc_entry
operator|,
name|asymbol
operator|*
name|symbol
operator|,
name|PTR
name|data
operator|,
name|asection
operator|*
name|input_section
operator|,
name|bfd
operator|*
name|output_bfd
operator|,
name|char
operator|*
operator|*
name|error_message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* For some reason when using i386 COFF the value stored in the .text    section for a reference to a common symbol is the value itself plus    any desired offset.  Ian Taylor, Cygnus Support.  */
end_comment

begin_comment
comment|/* If we are producing relocateable output, we need to do some    adjustments to the object file that are not done by the    bfd_perform_relocation function.  This function is called by every    reloc type to make any required adjustments.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|coff_i386_reloc
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
comment|/* For some reason bfd_perform_relocation always effectively 	 ignores the addend for a COFF target when producing 	 relocateable output.  This seems to be always wrong for 386 	 COFF, so we handle the addend here instead.  */
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
specifier|const
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

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|howto_table
index|[]
init|=
block|{
block|{
literal|0
block|}
block|,
block|{
literal|1
block|}
block|,
block|{
literal|2
block|}
block|,
block|{
literal|3
block|}
block|,
block|{
literal|4
block|}
block|,
block|{
literal|5
block|}
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"dir32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|{
literal|7
block|}
block|,
block|{
literal|010
block|}
block|,
block|{
literal|011
block|}
block|,
block|{
literal|012
block|}
block|,
block|{
literal|013
block|}
block|,
block|{
literal|014
block|}
block|,
block|{
literal|015
block|}
block|,
block|{
literal|016
block|}
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"8"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|false
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
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
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"DISP8"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|false
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
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"DISP16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
argument|R_PCRLONG
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
argument|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
argument|coff_i386_reloc
argument_list|,
comment|/* special_function */
literal|"DISP32"
argument_list|,
comment|/* name */
argument|true
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
argument|false
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Turn a howto into a reloc  nunmber */
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
value|I386BADMAG(x)
end_define

begin_define
define|#
directive|define
name|I386
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
value|cache_ptr->howto = howto_table + (dst)->r_type;
end_define

begin_comment
comment|/* On SCO Unix 3.2.2 the native assembler generates two .data    sections.  We handle that by renaming the second one to .data2.  It    does no harm to do this for any 386 COFF target.  */
end_comment

begin_define
define|#
directive|define
name|TWO_DATA_SECS
end_define

begin_comment
comment|/* For 386 COFF a STYP_NOLOAD | STYP_BSS section is part of a shared    library.  On some other COFF targets STYP_BSS is normally    STYP_NOLOAD.  */
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
define|\
value|{								\     coff_symbol_type *coffsym = (coff_symbol_type *) NULL;	\     if (ptr&& bfd_asymbol_bfd (ptr) != abfd)			\       coffsym = (obj_symbols (abfd)				\ 	         + (cache_ptr->sym_ptr_ptr - symbols));		\     else if (ptr)						\       coffsym = coff_symbol_from (abfd, ptr);			\     if (coffsym != (coff_symbol_type *) NULL			\&& coffsym->native->u.syment.n_scnum == 0)		\       cache_ptr->addend = - coffsym->native->u.syment.n_value;	\     else if (ptr&& bfd_asymbol_bfd (ptr) == abfd		\&& ptr->section != (asection *) NULL)		\       cache_ptr->addend = - (ptr->section->vma + ptr->value);	\     else							\       cache_ptr->addend = 0;					\     if (ptr&& howto_table[reloc.r_type].pc_relative)		\       cache_ptr->addend += asect->vma;				\   }
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
name|a
parameter_list|)
name|bfd
modifier|*
name|a
decl_stmt|;
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
name|i386coff_vec
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
literal|"coff-i386"
block|,
comment|/* name */
endif|#
directive|endif
name|bfd_target_coff_flavour
block|,
name|false
block|,
comment|/* data byte order is little */
name|false
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
literal|0
block|,
comment|/* leading underscore */
literal|'/'
block|,
comment|/* ar_pad_char */
literal|15
block|,
comment|/* ar_max_namelen */
literal|2
block|,
comment|/* minimum alignment power */
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
comment|/* Note that we allow an object file to be treated as a core file as well. */
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
name|COFF_SWAP_TABLE
block|, }
decl_stmt|;
end_decl_stmt

end_unit

