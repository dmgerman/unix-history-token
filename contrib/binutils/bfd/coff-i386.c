begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Intel 386 COFF files.    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001    Free Software Foundation, Inc.    Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"coff/i386.h"
end_include

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_include
include|#
directive|include
file|"coff/pe.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_GO32_EXE
end_ifdef

begin_include
include|#
directive|include
file|"coff/go32exe.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

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
name|reloc_howto_type
modifier|*
name|coff_i386_rtype_to_howto
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
modifier|*
name|coff_i386_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_reloc_code_real_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|char
modifier|*
modifier|*
name|error_message
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|symvalue
name|diff
decl_stmt|;
ifndef|#
directive|ifndef
name|COFF_WITH_PE
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
endif|#
directive|endif
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
ifndef|#
directive|ifndef
name|COFF_WITH_PE
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
else|#
directive|else
comment|/* In PE mode, we do not offset the common symbol.  */
name|diff
operator|=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
endif|#
directive|endif
block|}
else|else
block|{
comment|/* For some reason bfd_perform_relocation always effectively 	 ignores the addend for a COFF target when producing 	 relocateable output.  This seems to be always wrong for 386 	 COFF, so we handle the addend here instead.  */
ifdef|#
directive|ifdef
name|COFF_WITH_PE
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
block|{
name|reloc_howto_type
modifier|*
name|howto
init|=
name|reloc_entry
operator|->
name|howto
decl_stmt|;
comment|/* Although PC relative relocations are very similar between 	     PE and non-PE formats, but they are off by 1<< howto->size 	     bytes. For the external relocation, PE is very different 	     from others. See md_apply_fix3 () in gas/config/tc-i386.c. 	     When we link PE and non-PE object files together to 	     generate a non-PE executable, we have to compensate it 	     here.  */
if|if
condition|(
name|howto
operator|->
name|pc_relative
operator|==
name|true
operator|&&
name|howto
operator|->
name|pcrel_offset
operator|==
name|true
condition|)
name|diff
operator|=
operator|-
operator|(
literal|1
operator|<<
name|howto
operator|->
name|size
operator|)
expr_stmt|;
else|else
name|diff
operator|=
operator|-
name|reloc_entry
operator|->
name|addend
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|diff
operator|=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|COFF_WITH_PE
comment|/* FIXME: How should this case be handled?  */
if|if
condition|(
name|reloc_entry
operator|->
name|howto
operator|->
name|type
operator|==
name|R_IMAGEBASE
operator|&&
name|output_bfd
operator|!=
name|NULL
operator|&&
name|bfd_get_flavour
argument_list|(
name|output_bfd
argument_list|)
operator|==
name|bfd_target_coff_flavour
condition|)
name|diff
operator|-=
name|pe_data
argument_list|(
name|output_bfd
argument_list|)
operator|->
name|pe_opthdr
operator|.
name|ImageBase
expr_stmt|;
endif|#
directive|endif
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

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_WITH_PE
end_ifdef

begin_comment
comment|/* Return true if this relocation should appear in the output .reloc    section.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|in_reloc_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|reloc_howto_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|boolean
name|in_reloc_p
parameter_list|(
name|abfd
parameter_list|,
name|howto
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
block|{
return|return
operator|!
name|howto
operator|->
name|pc_relative
operator|&&
name|howto
operator|->
name|type
operator|!=
name|R_IMAGEBASE
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_WITH_PE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCRELOFFSET
end_ifndef

begin_define
define|#
directive|define
name|PCRELOFFSET
value|false
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
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* PE IMAGE_REL_I386_DIR32NB relocation (7).	*/
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
literal|"rva32"
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
comment|/* Byte relocation (017).  */
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16-bit word relocation (020).  */
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit longword relocation (021).	*/
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Byte PC relative relocation (022).	 */
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16-bit word PC relative relocation (023).	*/
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
name|PCRELOFFSET
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit longword PC relative relocation (024).  */
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
argument|PCRELOFFSET
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
value|((cache_ptr)->howto =							\    ((dst)->r_type< sizeof (howto_table) / sizeof (howto_table[0])	\     ? howto_table + (dst)->r_type					\     : NULL))
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

begin_comment
comment|/* We use the special COFF backend linker.  For normal i386 COFF, we    can use the generic relocate_section routine.  For PE, we need our    own routine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_WITH_PE
end_ifndef

begin_define
define|#
directive|define
name|coff_relocate_section
value|_bfd_coff_generic_relocate_section
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* COFF_WITH_PE */
end_comment

begin_comment
comment|/* The PE relocate section routine.  The only difference between this    and the regular routine is that we don't want to do anything for a    relocateable link.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|coff_pe_i386_relocate_section
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

begin_function
specifier|static
name|boolean
name|coff_pe_i386_relocate_section
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
if|if
condition|(
name|info
operator|->
name|relocateable
condition|)
return|return
name|true
return|;
return|return
name|_bfd_coff_generic_relocate_section
argument_list|(
name|output_bfd
argument_list|,
name|info
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|contents
argument_list|,
name|relocs
argument_list|,
name|syms
argument_list|,
name|sections
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|coff_relocate_section
value|coff_pe_i386_relocate_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_WITH_PE */
end_comment

begin_comment
comment|/* Convert an rtype to howto for the COFF backend linker.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_i386_rtype_to_howto
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
decl_stmt|;
name|struct
name|internal_syment
modifier|*
name|sym
decl_stmt|;
name|bfd_vma
modifier|*
name|addendp
decl_stmt|;
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
ifdef|#
directive|ifdef
name|COFF_WITH_PE
comment|/* Cancel out code in _bfd_coff_generic_relocate_section.  */
operator|*
name|addendp
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
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
ifndef|#
directive|ifndef
name|COFF_WITH_PE
comment|/* I think we *do* want to bypass this.  If we don't, I have 	 seen some data parameters get the wrong relocation address. 	 If I link two versions with and without this section bypassed 	 and then do a binary comparison, the addresses which are 	 different can be looked up in the map.  The case in which 	 this section has been bypassed has addresses which correspond 	 to values I can find in the map.  */
operator|*
name|addendp
operator|-=
name|sym
operator|->
name|n_value
expr_stmt|;
endif|#
directive|endif
block|}
ifndef|#
directive|ifndef
name|COFF_WITH_PE
comment|/* If the output symbol is common (in which case this must be a      relocateable link), we need to add in the final size of the      common symbol.  */
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|COFF_WITH_PE
if|if
condition|(
name|howto
operator|->
name|pc_relative
condition|)
block|{
operator|*
name|addendp
operator|-=
literal|4
expr_stmt|;
comment|/* If the symbol is defined, then the generic code is going to          add back the symbol value in order to cancel out an          adjustment it made to the addend.  However, we set the addend          to 0 at the start of this function.  We need to adjust here,          to avoid the adjustment the generic code will make.  FIXME:          This is getting a bit hackish.  */
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
operator|*
name|addendp
operator|-=
name|sym
operator|->
name|n_value
expr_stmt|;
block|}
if|if
condition|(
name|rel
operator|->
name|r_type
operator|==
name|R_IMAGEBASE
operator|&&
operator|(
name|bfd_get_flavour
argument_list|(
name|sec
operator|->
name|output_section
operator|->
name|owner
argument_list|)
operator|==
name|bfd_target_coff_flavour
operator|)
condition|)
block|{
operator|*
name|addendp
operator|-=
name|pe_data
argument_list|(
name|sec
operator|->
name|output_section
operator|->
name|owner
argument_list|)
operator|->
name|pe_opthdr
operator|.
name|ImageBase
expr_stmt|;
block|}
endif|#
directive|endif
return|return
name|howto
return|;
block|}
end_function

begin_define
define|#
directive|define
name|coff_bfd_reloc_type_lookup
value|coff_i386_reloc_type_lookup
end_define

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_i386_reloc_type_lookup
parameter_list|(
name|abfd
parameter_list|,
name|code
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|bfd_reloc_code_real_type
name|code
decl_stmt|;
block|{
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|BFD_RELOC_RVA
case|:
return|return
name|howto_table
operator|+
name|R_IMAGEBASE
return|;
case|case
name|BFD_RELOC_32
case|:
return|return
name|howto_table
operator|+
name|R_DIR32
return|;
case|case
name|BFD_RELOC_32_PCREL
case|:
return|return
name|howto_table
operator|+
name|R_PCRLONG
return|;
case|case
name|BFD_RELOC_16
case|:
return|return
name|howto_table
operator|+
name|R_RELWORD
return|;
case|case
name|BFD_RELOC_16_PCREL
case|:
return|return
name|howto_table
operator|+
name|R_PCRWORD
return|;
case|case
name|BFD_RELOC_8
case|:
return|return
name|howto_table
operator|+
name|R_RELBYTE
return|;
case|case
name|BFD_RELOC_8_PCREL
case|:
return|return
name|howto_table
operator|+
name|R_PCRBYTE
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

begin_define
define|#
directive|define
name|coff_rtype_to_howto
value|coff_i386_rtype_to_howto
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_UNDERSCORE
end_ifdef

begin_comment
comment|/* If i386 gcc uses underscores for symbol names, then it does not use    a leading dot for local labels, so if TARGET_UNDERSCORE is defined    we treat all symbols starting with L as local.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|coff_i386_is_local_label_name
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|boolean
name|coff_i386_is_local_label_name
parameter_list|(
name|abfd
parameter_list|,
name|name
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'L'
condition|)
return|return
name|true
return|;
return|return
name|_bfd_coff_is_local_label_name
argument_list|(
name|abfd
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|coff_bfd_is_local_label_name
value|coff_i386_is_local_label_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TARGET_UNDERSCORE */
end_comment

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

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
comment|/* section flags */
ifdef|#
directive|ifdef
name|COFF_WITH_PE
operator||
name|SEC_LINK_ONCE
operator||
name|SEC_LINK_DUPLICATES
operator||
name|SEC_READONLY
endif|#
directive|endif
operator||
name|SEC_CODE
operator||
name|SEC_DATA
operator|)
block|,
ifdef|#
directive|ifdef
name|TARGET_UNDERSCORE
name|TARGET_UNDERSCORE
block|,
comment|/* leading underscore */
else|#
directive|else
literal|0
block|,
comment|/* leading underscore */
endif|#
directive|endif
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
name|coff_object_p
block|,
comment|/* bfd_check_format */
name|bfd_generic_archive_p
block|,
name|coff_object_p
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

