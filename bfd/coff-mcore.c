begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD back-end for Motorola MCore COFF/PE    Copyright 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2007    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"coff/mcore.h"
end_include

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"coff/pe.h"
end_include

begin_include
include|#
directive|include
file|"libcoff.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BADMAG
end_ifdef

begin_undef
undef|#
directive|undef
name|BADMAG
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|MCOREBADMAG(x)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NUM_ELEM
end_ifndef

begin_define
define|#
directive|define
name|NUM_ELEM
parameter_list|(
name|A
parameter_list|)
value|(sizeof (A) / sizeof (A)[0])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This file is compiled more than once, but we only compile the    final_link routine once.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|mcore_bfd_coff_final_link
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
name|bfd_reloc_status_type
name|mcore_coff_unsupported_reloc
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
name|coff_mcore_relocate_section
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
name|mcore_coff_reloc_type_lookup
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

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|coff_mcore_rtype_to_howto
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
name|void
name|mcore_emit_base_file_entry
name|PARAMS
argument_list|(
operator|(
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
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_boolean
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

begin_escape
end_escape

begin_comment
comment|/* The NT loader points the toc register to&toc + 32768, in order to    use the complete range of a 16-bit displacement. We have to adjust    for this when we fix up loads displaced off the toc reg.  */
end_comment

begin_define
define|#
directive|define
name|TOC_LOAD_ADJUSTMENT
value|(-32768)
end_define

begin_define
define|#
directive|define
name|TOC_SECTION_NAME
value|".private.toc"
end_define

begin_comment
comment|/* The main body of code is in coffcode.h.  */
end_comment

begin_define
define|#
directive|define
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
value|2
end_define

begin_comment
comment|/* In case we're on a 32-bit machine, construct a 64-bit "-1" value    from smaller values.  Start with zero, widen, *then* decrement.  */
end_comment

begin_define
define|#
directive|define
name|MINUS_ONE
value|(((bfd_vma)0) - 1)
end_define

begin_escape
end_escape

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mcore_coff_howto_table
index|[]
init|=
block|{
comment|/* Unused: */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_ABSOLUTE
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
comment|/* dont complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"ABSOLUTE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x00
argument_list|,
comment|/* src_mask */
literal|0x00
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_ADDR32
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
literal|"ADDR32"
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
comment|/* 8 bits + 2 zero bits; jmpi/jsri/lrw instructions.      Should not appear in object files.  */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_PCREL_IMM8BY4
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|1
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|mcore_coff_unsupported_reloc
argument_list|,
comment|/* special_function */
literal|"IMM8BY4"
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
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* bsr/bt/bf/br instructions; 11 bits + 1 zero bit      Span 2k instructions == 4k bytes.      Only useful pieces at the relocated address are the opcode (5 bits) */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_PCREL_IMM11BY2
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|11
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
literal|"IMM11BY2"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0x7ff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 4 bits + 1 zero bit; 'loopt' instruction only; unsupported.  */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_PCREL_IMM4BY2
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|4
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
name|mcore_coff_unsupported_reloc
argument_list|,
comment|/* special_function */
literal|"IMM4BY2"
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
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32-bit pc-relative. Eventually this will help support PIC code.  */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_PCREL_32
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"PCREL_32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Like PCREL_IMM11BY2, this relocation indicates that there is a      'jsri' at the specified address. There is a separate relocation      entry for the literal pool entry that it references, but we      might be able to change the jsri to a bsr if the target turns out      to be close enough [even though we won't reclaim the literal pool      entry, we'll get some runtime efficiency back]. Note that this      is a relocation that we are allowed to safely ignore.  */
name|HOWTO
argument_list|(
name|IMAGE_REL_MCORE_PCREL_JSR_IMM11BY2
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|11
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
literal|"JSR_IMM11BY2"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0x7ff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
argument|IMAGE_REL_MCORE_RVA
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
argument|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
argument|NULL
argument_list|,
comment|/* special_function */
literal|"MCORE_RVA"
argument_list|,
comment|/* name */
argument|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0xffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
argument|TRUE
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Extend the coff_link_hash_table structure with a few M*Core specific fields.    This allows us to store global data here without actually creating any    global variables, which is a no-no in the BFD world.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coff_mcore_link_hash_table
block|{
comment|/* The original coff_link_hash_table structure.  MUST be first field.  */
name|struct
name|coff_link_hash_table
name|root
decl_stmt|;
name|bfd
modifier|*
name|bfd_of_toc_owner
decl_stmt|;
name|long
name|int
name|global_toc_size
decl_stmt|;
name|long
name|int
name|import_table_size
decl_stmt|;
name|long
name|int
name|first_thunk_address
decl_stmt|;
name|long
name|int
name|thunk_size
decl_stmt|;
block|}
name|mcore_hash_table
typedef|;
end_typedef

begin_comment
comment|/* Get the MCore coff linker hash table from a link_info structure.  */
end_comment

begin_define
define|#
directive|define
name|coff_mcore_hash_table
parameter_list|(
name|info
parameter_list|)
define|\
value|((mcore_hash_table *) ((info)->hash))
end_define

begin_escape
end_escape

begin_comment
comment|/* Add an entry to the base file.  */
end_comment

begin_function
specifier|static
name|void
name|mcore_emit_base_file_entry
parameter_list|(
name|info
parameter_list|,
name|output_bfd
parameter_list|,
name|input_section
parameter_list|,
name|reloc_offset
parameter_list|)
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
name|asection
modifier|*
name|input_section
decl_stmt|;
name|bfd_vma
name|reloc_offset
decl_stmt|;
block|{
name|bfd_vma
name|addr
init|=
name|reloc_offset
operator|-
name|input_section
operator|->
name|vma
operator|+
name|input_section
operator|->
name|output_offset
operator|+
name|input_section
operator|->
name|output_section
operator|->
name|vma
decl_stmt|;
if|if
condition|(
name|coff_data
argument_list|(
name|output_bfd
argument_list|)
operator|->
name|pe
condition|)
name|addr
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
name|fwrite
argument_list|(
operator|&
name|addr
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
name|addr
argument_list|)
argument_list|,
operator|(
name|FILE
operator|*
operator|)
name|info
operator|->
name|base_file
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_function
specifier|static
name|bfd_reloc_status_type
name|mcore_coff_unsupported_reloc
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
name|BFD_ASSERT
argument_list|(
name|reloc_entry
operator|->
name|howto
operator|!=
operator|(
name|reloc_howto_type
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
name|_bfd_error_handler
argument_list|(
name|_
argument_list|(
literal|"%B: Relocation %s (%d) is not currently supported.\n"
argument_list|)
argument_list|,
name|abfd
argument_list|,
name|reloc_entry
operator|->
name|howto
operator|->
name|name
argument_list|,
name|reloc_entry
operator|->
name|howto
operator|->
name|type
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_notsupported
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* A cheesy little macro to make the code a little more readable.  */
end_comment

begin_define
define|#
directive|define
name|HOW2MAP
parameter_list|(
name|bfd_rtype
parameter_list|,
name|mcore_rtype
parameter_list|)
define|\
value|case bfd_rtype: return& mcore_coff_howto_table [mcore_rtype]
end_define

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mcore_coff_reloc_type_lookup
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
name|HOW2MAP
argument_list|(
name|BFD_RELOC_32
argument_list|,
name|IMAGE_REL_MCORE_ADDR32
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_MCORE_PCREL_IMM8BY4
argument_list|,
name|IMAGE_REL_MCORE_PCREL_IMM8BY4
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_MCORE_PCREL_IMM11BY2
argument_list|,
name|IMAGE_REL_MCORE_PCREL_IMM11BY2
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_MCORE_PCREL_IMM4BY2
argument_list|,
name|IMAGE_REL_MCORE_PCREL_IMM4BY2
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_32_PCREL
argument_list|,
name|IMAGE_REL_MCORE_PCREL_32
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_MCORE_PCREL_JSR_IMM11BY2
argument_list|,
name|IMAGE_REL_MCORE_PCREL_JSR_IMM11BY2
argument_list|)
expr_stmt|;
name|HOW2MAP
argument_list|(
name|BFD_RELOC_RVA
argument_list|,
name|IMAGE_REL_MCORE_RVA
argument_list|)
expr_stmt|;
default|default:
return|return
name|NULL
return|;
block|}
comment|/*NOTREACHED*/
block|}
end_function

begin_undef
undef|#
directive|undef
name|HOW2MAP
end_undef

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mcore_coff_reloc_name_lookup
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
name|mcore_coff_howto_table
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mcore_coff_howto_table
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
name|mcore_coff_howto_table
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
name|mcore_coff_howto_table
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
name|mcore_coff_howto_table
index|[
name|i
index|]
return|;
return|return
name|NULL
return|;
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
define|\
value|(cache_ptr)->howto = mcore_coff_howto_table + (dst)->r_type;
end_define

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|coff_mcore_rtype_to_howto
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
operator|>=
name|NUM_ELEM
argument_list|(
name|mcore_coff_howto_table
argument_list|)
condition|)
return|return
name|NULL
return|;
name|howto
operator|=
name|mcore_coff_howto_table
operator|+
name|rel
operator|->
name|r_type
expr_stmt|;
if|if
condition|(
name|rel
operator|->
name|r_type
operator|==
name|IMAGE_REL_MCORE_RVA
condition|)
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
elseif|else
if|if
condition|(
name|howto
operator|->
name|pc_relative
condition|)
block|{
operator|*
name|addendp
operator|=
name|sec
operator|->
name|vma
operator|-
literal|2
expr_stmt|;
comment|/* XXX guess - is this right ? */
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
else|else
operator|*
name|addendp
operator|=
literal|0
expr_stmt|;
return|return
name|howto
return|;
block|}
end_function

begin_comment
comment|/* Return TRUE if this relocation should appear in the output .reloc section.    This function is referenced in pe_mkobject in peicode.h.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
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
name|IMAGE_REL_MCORE_RVA
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* The reloc processing routine for the optimized COFF linker.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|coff_mcore_relocate_section
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
name|bfd_boolean
name|hihalf
decl_stmt|;
name|bfd_vma
name|hihalf_val
decl_stmt|;
comment|/* If we are performing a relocatable link, we don't need to do a      thing.  The caller will take care of adjusting the reloc      addresses and symbol indices.  */
if|if
condition|(
name|info
operator|->
name|relocatable
condition|)
return|return
name|TRUE
return|;
comment|/* Check if we have the same endianess */
if|if
condition|(
name|input_bfd
operator|->
name|xvec
operator|->
name|byteorder
operator|!=
name|output_bfd
operator|->
name|xvec
operator|->
name|byteorder
operator|&&
name|output_bfd
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
name|_
argument_list|(
literal|"%B: compiled for a %s system and target is %s.\n"
argument_list|)
argument_list|,
name|input_bfd
argument_list|,
name|bfd_big_endian
argument_list|(
name|input_bfd
argument_list|)
condition|?
name|_
argument_list|(
literal|"big endian"
argument_list|)
else|:
name|_
argument_list|(
literal|"little endian"
argument_list|)
argument_list|,
name|bfd_big_endian
argument_list|(
name|output_bfd
argument_list|)
condition|?
name|_
argument_list|(
literal|"big endian"
argument_list|)
else|:
name|_
argument_list|(
literal|"little endian"
argument_list|)
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_wrong_format
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
name|hihalf
operator|=
name|FALSE
expr_stmt|;
name|hihalf_val
operator|=
literal|0
expr_stmt|;
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
name|internal_syment
modifier|*
name|sym
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
name|bfd_vma
name|addend
decl_stmt|;
name|bfd_reloc_status_type
name|rstat
decl_stmt|;
name|bfd_byte
modifier|*
name|loc
decl_stmt|;
name|unsigned
name|short
name|r_type
init|=
name|rel
operator|->
name|r_type
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
init|=
name|NULL
decl_stmt|;
name|struct
name|coff_link_hash_entry
modifier|*
name|h
decl_stmt|;
specifier|const
name|char
modifier|*
name|my_name
decl_stmt|;
name|symndx
operator|=
name|rel
operator|->
name|r_symndx
expr_stmt|;
name|loc
operator|=
name|contents
operator|+
name|rel
operator|->
name|r_vaddr
operator|-
name|input_section
operator|->
name|vma
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
name|addend
operator|=
literal|0
expr_stmt|;
comment|/* Get the howto and initialise the addend.  */
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
if|if
condition|(
name|symndx
operator|==
operator|-
literal|1
condition|)
name|my_name
operator|=
literal|"*ABS*"
expr_stmt|;
else|else
block|{
name|asection
modifier|*
name|sec
init|=
name|sections
index|[
name|symndx
index|]
decl_stmt|;
name|val
operator|=
operator|(
name|sym
operator|->
name|n_value
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
if|if
condition|(
name|sym
operator|==
name|NULL
condition|)
name|my_name
operator|=
literal|"*unknown*"
expr_stmt|;
elseif|else
if|if
condition|(
name|sym
operator|->
name|_n
operator|.
name|_n_n
operator|.
name|_n_zeroes
operator|==
literal|0
operator|&&
name|sym
operator|->
name|_n
operator|.
name|_n_n
operator|.
name|_n_offset
operator|!=
literal|0
condition|)
name|my_name
operator|=
name|obj_coff_strings
argument_list|(
name|input_bfd
argument_list|)
operator|+
name|sym
operator|->
name|_n
operator|.
name|_n_n
operator|.
name|_n_offset
expr_stmt|;
else|else
block|{
specifier|static
name|char
name|buf
index|[
name|SYMNMLEN
operator|+
literal|1
index|]
decl_stmt|;
name|strncpy
argument_list|(
name|buf
argument_list|,
name|sym
operator|->
name|_n
operator|.
name|_n_name
argument_list|,
name|SYMNMLEN
argument_list|)
expr_stmt|;
name|buf
index|[
name|SYMNMLEN
index|]
operator|=
literal|'\0'
expr_stmt|;
name|my_name
operator|=
name|buf
expr_stmt|;
block|}
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
init|=
name|h
operator|->
name|root
operator|.
name|u
operator|.
name|def
operator|.
name|section
decl_stmt|;
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
else|else
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
name|my_name
operator|=
name|h
operator|->
name|root
operator|.
name|root
operator|.
name|string
expr_stmt|;
block|}
name|rstat
operator|=
name|bfd_reloc_ok
expr_stmt|;
comment|/* Each case must do its own relocation, setting rstat appropriately.  */
switch|switch
condition|(
name|r_type
condition|)
block|{
default|default:
name|_bfd_error_handler
argument_list|(
name|_
argument_list|(
literal|"%B: unsupported relocation type 0x%02x"
argument_list|)
argument_list|,
name|input_bfd
argument_list|,
name|r_type
argument_list|)
expr_stmt|;
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
case|case
name|IMAGE_REL_MCORE_ABSOLUTE
case|:
name|_bfd_error_handler
argument_list|(
name|_
argument_list|(
literal|"Warning: unsupported reloc %s<file %B, section %A>\n"
literal|"sym %ld (%s), r_vaddr %ld (%lx)"
argument_list|)
argument_list|,
name|input_bfd
argument_list|,
name|input_section
argument_list|,
name|howto
operator|->
name|name
argument_list|,
name|rel
operator|->
name|r_symndx
argument_list|,
name|my_name
argument_list|,
operator|(
name|long
operator|)
name|rel
operator|->
name|r_vaddr
argument_list|,
operator|(
name|unsigned
name|long
operator|)
name|rel
operator|->
name|r_vaddr
argument_list|)
expr_stmt|;
break|break;
case|case
name|IMAGE_REL_MCORE_PCREL_IMM8BY4
case|:
case|case
name|IMAGE_REL_MCORE_PCREL_IMM11BY2
case|:
case|case
name|IMAGE_REL_MCORE_PCREL_IMM4BY2
case|:
case|case
name|IMAGE_REL_MCORE_PCREL_32
case|:
case|case
name|IMAGE_REL_MCORE_PCREL_JSR_IMM11BY2
case|:
case|case
name|IMAGE_REL_MCORE_ADDR32
case|:
comment|/* XXX fixme - shouldn't this be like the code for the RVA reloc ? */
name|rstat
operator|=
name|_bfd_relocate_contents
argument_list|(
name|howto
argument_list|,
name|input_bfd
argument_list|,
name|val
argument_list|,
name|loc
argument_list|)
expr_stmt|;
break|break;
case|case
name|IMAGE_REL_MCORE_RVA
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
name|rel
operator|->
name|r_vaddr
operator|-
name|input_section
operator|->
name|vma
argument_list|,
name|val
argument_list|,
name|addend
argument_list|)
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|info
operator|->
name|base_file
condition|)
block|{
comment|/* Emit a reloc if the backend thinks it needs it.  */
if|if
condition|(
name|sym
operator|&&
name|pe_data
argument_list|(
name|output_bfd
argument_list|)
operator|->
name|in_reloc_p
argument_list|(
name|output_bfd
argument_list|,
name|howto
argument_list|)
condition|)
name|mcore_emit_base_file_entry
argument_list|(
name|info
argument_list|,
name|output_bfd
argument_list|,
name|input_section
argument_list|,
name|rel
operator|->
name|r_vaddr
argument_list|)
expr_stmt|;
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
name|bfd_reloc_overflow
case|:
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
name|my_name
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
return|return
name|TRUE
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Tailor coffcode.h -- macro heaven.  */
end_comment

begin_comment
comment|/* We use the special COFF backend linker, with our own special touch.  */
end_comment

begin_define
define|#
directive|define
name|coff_bfd_reloc_type_lookup
value|mcore_coff_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|coff_bfd_reloc_name_lookup
value|mcore_coff_reloc_name_lookup
end_define

begin_define
define|#
directive|define
name|coff_relocate_section
value|coff_mcore_relocate_section
end_define

begin_define
define|#
directive|define
name|coff_rtype_to_howto
value|coff_mcore_rtype_to_howto
end_define

begin_define
define|#
directive|define
name|SELECT_RELOC
parameter_list|(
name|internal
parameter_list|,
name|howto
parameter_list|)
value|{internal.r_type = howto->type;}
end_define

begin_comment
comment|/* Make sure that the 'r_offset' field is copied properly    so that identical binaries will compare the same.  */
end_comment

begin_define
define|#
directive|define
name|SWAP_IN_RELOC_OFFSET
value|H_GET_32
end_define

begin_define
define|#
directive|define
name|SWAP_OUT_RELOC_OFFSET
value|H_PUT_32
end_define

begin_define
define|#
directive|define
name|COFF_PAGE_SIZE
value|0x1000
end_define

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Forward declaration to initialise alternative_target field.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|TARGET_LITTLE_SYM
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The transfer vectors that lead the outside world to all of the above.  */
end_comment

begin_macro
name|CREATE_BIG_COFF_TARGET_VEC
argument_list|(
argument|TARGET_BIG_SYM
argument_list|,
argument|TARGET_BIG_NAME
argument_list|,
argument|D_PAGED
argument_list|,
argument|(SEC_CODE | SEC_DATA | SEC_DEBUGGING | SEC_READONLY | SEC_LINK_ONCE | SEC_LINK_DUPLICATES)
argument_list|,
literal|0
argument_list|,
argument|& TARGET_LITTLE_SYM
argument_list|,
argument|COFF_SWAP_TABLE
argument_list|)
end_macro

begin_macro
name|CREATE_LITTLE_COFF_TARGET_VEC
argument_list|(
argument|TARGET_LITTLE_SYM
argument_list|,
argument|TARGET_LITTLE_NAME
argument_list|,
argument|D_PAGED
argument_list|,
argument|(SEC_CODE | SEC_DATA | SEC_DEBUGGING | SEC_READONLY | SEC_LINK_ONCE | SEC_LINK_DUPLICATES)
argument_list|,
literal|0
argument_list|,
argument|& TARGET_BIG_SYM
argument_list|,
argument|COFF_SWAP_TABLE
argument_list|)
end_macro

end_unit

