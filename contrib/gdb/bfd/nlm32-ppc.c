begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for 32-bit PowerPC NLM (NetWare Loadable Module)    Copyright (C) 1994, 1995 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_comment
comment|/* The format of a PowerPC NLM changed.  Define OLDFORMAT to get the    old format.  */
end_comment

begin_define
define|#
directive|define
name|ARCH_SIZE
value|32
end_define

begin_include
include|#
directive|include
file|"nlm/ppc-ext.h"
end_include

begin_define
define|#
directive|define
name|Nlm_External_Fixed_Header
value|Nlm32_powerpc_External_Fixed_Header
end_define

begin_include
include|#
directive|include
file|"libnlm.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|OLDFORMAT
end_ifdef

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_backend_object_p
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
name|nlm_powerpc_write_prefix
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_read_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|,
name|asection
operator|*
operator|*
operator|,
name|arelent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_mangle_relocs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
operator|,
name|bfd_vma
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_read_import
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|OLDFORMAT
end_ifdef

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_write_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|arelent
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_write_import
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|arelent
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_write_external
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_size_type
operator|,
name|asymbol
operator|*
operator|,
expr|struct
name|reloc_and_sec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|OLDFORMAT
end_ifndef

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_set_public_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|bfd_vma
name|nlm_powerpc_get_public_offset
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|OLDFORMAT
end_ifdef

begin_comment
comment|/* The prefix header is only used in the old format.  */
end_comment

begin_comment
comment|/* PowerPC NLM's have a prefix header before the standard NLM.  This    function reads it in, verifies the version, and seeks the bfd to    the location before the regular NLM header.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_backend_object_p
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|nlm32_powerpc_external_prefix_header
name|s
decl_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
operator|(
name|PTR
operator|)
operator|&
name|s
argument_list|,
sizeof|sizeof
name|s
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
name|s
condition|)
return|return
name|false
return|;
if|if
condition|(
name|memcmp
argument_list|(
name|s
operator|.
name|signature
argument_list|,
name|NLM32_POWERPC_SIGNATURE
argument_list|,
sizeof|sizeof
name|s
operator|.
name|signature
argument_list|)
operator|!=
literal|0
operator|||
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|s
operator|.
name|headerVersion
argument_list|)
operator|!=
name|NLM32_POWERPC_HEADER_VERSION
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Write out the prefix.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_write_prefix
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|nlm32_powerpc_external_prefix_header
name|s
decl_stmt|;
name|memset
argument_list|(
operator|&
name|s
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
name|s
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
name|s
operator|.
name|signature
argument_list|,
name|NLM32_POWERPC_SIGNATURE
argument_list|,
sizeof|sizeof
name|s
operator|.
name|signature
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|NLM32_POWERPC_HEADER_VERSION
argument_list|,
name|s
operator|.
name|headerVersion
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
literal|0
argument_list|,
name|s
operator|.
name|origins
argument_list|)
expr_stmt|;
comment|/* FIXME: What should we do about the date?  */
if|if
condition|(
name|bfd_write
argument_list|(
operator|(
name|PTR
operator|)
operator|&
name|s
argument_list|,
sizeof|sizeof
name|s
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
name|s
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|OLDFORMAT
end_ifndef

begin_comment
comment|/* There is only one type of reloc in a PowerPC NLM.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|nlm_powerpc_howto
init|=
name|HOWTO
argument_list|(
literal|0
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
literal|0
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* Read a PowerPC NLM reloc.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_read_reloc
argument_list|(
name|abfd
argument_list|,
name|sym
argument_list|,
name|secp
argument_list|,
name|rel
argument_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
name|sym
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|asection
modifier|*
modifier|*
name|secp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|arelent
modifier|*
name|rel
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|bfd_byte
name|temp
index|[
literal|4
index|]
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
name|temp
argument_list|,
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
condition|)
return|return
name|false
return|;
name|val
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|temp
argument_list|)
expr_stmt|;
comment|/* The value is a word offset into either the code or data segment.      This is the location which needs to be adjusted.       The high bit is 0 if the value is an offset into the data      segment, or 1 if the value is an offset into the text segment.       If this is a relocation fixup rather than an imported symbol (the      sym argument is NULL), then the second most significant bit is 0      if the address of the data segment should be added to the      location addressed by the value, or 1 if the address of the text      segment should be added.       If this is an imported symbol, the second most significant bit is      not used and must be 0.  */
if|if
condition|(
operator|(
name|val
operator|&
name|NLM_HIBIT
operator|)
operator|==
literal|0
condition|)
name|name
operator|=
name|NLM_INITIALIZED_DATA_NAME
expr_stmt|;
else|else
block|{
name|name
operator|=
name|NLM_CODE_NAME
expr_stmt|;
name|val
operator|&=
operator|~
name|NLM_HIBIT
expr_stmt|;
block|}
operator|*
name|secp
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
name|sym
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|val
operator|&
operator|(
name|NLM_HIBIT
operator|>>
literal|1
operator|)
operator|)
operator|==
literal|0
condition|)
name|name
operator|=
name|NLM_INITIALIZED_DATA_NAME
expr_stmt|;
else|else
block|{
name|name
operator|=
name|NLM_CODE_NAME
expr_stmt|;
name|val
operator|&=
operator|~
operator|(
name|NLM_HIBIT
operator|>>
literal|1
operator|)
expr_stmt|;
block|}
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|name
argument_list|)
operator|->
name|symbol_ptr_ptr
expr_stmt|;
block|}
name|rel
operator|->
name|howto
operator|=
operator|&
name|nlm_powerpc_howto
expr_stmt|;
name|rel
operator|->
name|address
operator|=
name|val
operator|<<
literal|2
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
return|return
name|true
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_comment
comment|/* This reloc handling is only applicable to the old format.  */
end_comment

begin_comment
comment|/* How to process the various reloc types.  PowerPC NLMs use XCOFF    reloc types, and I have just copied the XCOFF reloc table here.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|nlm_powerpc_howto_table
index|[]
init|=
block|{
comment|/* Standard 32 bit relocation.  */
name|HOWTO
argument_list|(
literal|0
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_POS"
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
comment|/* 32 bit relocation, but store negative value.  */
name|HOWTO
argument_list|(
literal|1
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
operator|-
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_NEG"
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
comment|/* 32 bit PC relative relocation.  */
name|HOWTO
argument_list|(
literal|2
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"R_REL"
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
comment|/* 16 bit TOC relative relocation.  */
name|HOWTO
argument_list|(
literal|3
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_TOC"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* I don't really know what this is.  */
name|HOWTO
argument_list|(
literal|4
argument_list|,
comment|/* type */
literal|1
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RTB"
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
comment|/* External TOC relative symbol.  */
name|HOWTO
argument_list|(
literal|5
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_GL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Local TOC relative symbol.  */
name|HOWTO
argument_list|(
literal|6
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_TCL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
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
comment|/* Non modifiable absolute branch.  */
name|HOWTO
argument_list|(
literal|8
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_BA"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x3fffffc
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|{
literal|9
block|}
block|,
comment|/* Non modifiable relative branch.  */
name|HOWTO
argument_list|(
literal|0xa
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_BR"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x3fffffc
argument_list|,
comment|/* src_mask */
literal|0x3fffffc
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|{
literal|0xb
block|}
block|,
comment|/* Indirect load.  */
name|HOWTO
argument_list|(
literal|0xc
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Load address.  */
name|HOWTO
argument_list|(
literal|0xd
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RLA"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|{
literal|0xe
block|}
block|,
comment|/* Non-relocating reference.  */
name|HOWTO
argument_list|(
literal|0xf
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_REF"
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
block|{
literal|0x10
block|}
block|,
block|{
literal|0x11
block|}
block|,
comment|/* TOC relative indirect load.  */
name|HOWTO
argument_list|(
literal|0x12
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_TRL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TOC relative load address.  */
name|HOWTO
argument_list|(
literal|0x13
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_TRLA"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable relative branch.  */
name|HOWTO
argument_list|(
literal|0x14
argument_list|,
comment|/* type */
literal|1
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RRTBI"
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
comment|/* Modifiable absolute branch.  */
name|HOWTO
argument_list|(
literal|0x15
argument_list|,
comment|/* type */
literal|1
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RRTBA"
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
comment|/* Modifiable call absolute indirect.  */
name|HOWTO
argument_list|(
literal|0x16
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_CAI"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable call relative.  */
name|HOWTO
argument_list|(
literal|0x17
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_REL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable branch absolute.  */
name|HOWTO
argument_list|(
literal|0x18
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RBA"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable branch absolute.  */
name|HOWTO
argument_list|(
literal|0x19
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
literal|0
argument_list|,
comment|/* special_function */
literal|"R_RBAC"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable branch relative.  */
name|HOWTO
argument_list|(
literal|0x1a
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"R_REL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Modifiable branch absolute.  */
name|HOWTO
argument_list|(
literal|0x1b
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
argument|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"R_REL"
argument_list|,
comment|/* name */
argument|true
argument_list|,
comment|/* partial_inplace */
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
argument|false
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|HOWTO_COUNT
value|(sizeof nlm_powerpc_howto_table		\ 		     / sizeof nlm_powerpc_howto_table[0])
end_define

begin_comment
comment|/* Read a PowerPC NLM reloc.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_read_reloc
argument_list|(
name|abfd
argument_list|,
name|sym
argument_list|,
name|secp
argument_list|,
name|rel
argument_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
name|sym
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|asection
modifier|*
modifier|*
name|secp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|arelent
modifier|*
name|rel
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|nlm32_powerpc_external_reloc
name|ext
decl_stmt|;
name|bfd_vma
name|l_vaddr
decl_stmt|;
name|unsigned
name|long
name|l_symndx
decl_stmt|;
name|int
name|l_rtype
decl_stmt|;
name|int
name|l_rsecnm
decl_stmt|;
name|asection
modifier|*
name|code_sec
decl_stmt|,
modifier|*
name|data_sec
decl_stmt|,
modifier|*
name|bss_sec
decl_stmt|;
comment|/* Read the reloc from the file.  */
if|if
condition|(
name|bfd_read
argument_list|(
operator|&
name|ext
argument_list|,
sizeof|sizeof
name|ext
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
name|ext
condition|)
return|return
name|false
return|;
comment|/* Swap in the fields.  */
name|l_vaddr
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|ext
operator|.
name|l_vaddr
argument_list|)
expr_stmt|;
name|l_symndx
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|ext
operator|.
name|l_symndx
argument_list|)
expr_stmt|;
name|l_rtype
operator|=
name|bfd_h_get_16
argument_list|(
name|abfd
argument_list|,
name|ext
operator|.
name|l_rtype
argument_list|)
expr_stmt|;
name|l_rsecnm
operator|=
name|bfd_h_get_16
argument_list|(
name|abfd
argument_list|,
name|ext
operator|.
name|l_rsecnm
argument_list|)
expr_stmt|;
comment|/* Get the sections now, for convenience.  */
name|code_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_CODE_NAME
argument_list|)
expr_stmt|;
name|data_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_INITIALIZED_DATA_NAME
argument_list|)
expr_stmt|;
name|bss_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_UNINITIALIZED_DATA_NAME
argument_list|)
expr_stmt|;
comment|/* Work out the arelent fields.  */
if|if
condition|(
name|sym
operator|!=
name|NULL
condition|)
block|{
comment|/* This is an import.  sym_ptr_ptr is filled in by 	 nlm_canonicalize_reloc.  */
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|NULL
expr_stmt|;
block|}
else|else
block|{
name|asection
modifier|*
name|sec
decl_stmt|;
if|if
condition|(
name|l_symndx
operator|==
literal|0
condition|)
name|sec
operator|=
name|code_sec
expr_stmt|;
elseif|else
if|if
condition|(
name|l_symndx
operator|==
literal|1
condition|)
name|sec
operator|=
name|data_sec
expr_stmt|;
elseif|else
if|if
condition|(
name|l_symndx
operator|==
literal|2
condition|)
name|sec
operator|=
name|bss_sec
expr_stmt|;
else|else
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
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|sec
operator|->
name|symbol_ptr_ptr
expr_stmt|;
block|}
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
name|BFD_ASSERT
argument_list|(
operator|(
name|l_rtype
operator|&
literal|0xff
operator|)
operator|<
name|HOWTO_COUNT
argument_list|)
expr_stmt|;
name|rel
operator|->
name|howto
operator|=
name|nlm_powerpc_howto_table
operator|+
operator|(
name|l_rtype
operator|&
literal|0xff
operator|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|rel
operator|->
name|howto
operator|->
name|name
operator|!=
name|NULL
operator|&&
operator|(
operator|(
name|l_rtype
operator|&
literal|0x8000
operator|)
operator|!=
literal|0
condition|?
operator|(
name|rel
operator|->
name|howto
operator|->
name|complain_on_overflow
operator|==
name|complain_overflow_signed
operator|)
else|:
operator|(
name|rel
operator|->
name|howto
operator|->
name|complain_on_overflow
operator|==
name|complain_overflow_bitfield
operator|)
operator|)
operator|&&
operator|(
operator|(
name|l_rtype
operator|>>
literal|8
operator|)
operator|&
literal|0x1f
operator|)
operator|==
name|rel
operator|->
name|howto
operator|->
name|bitsize
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|l_rsecnm
operator|==
literal|0
condition|)
operator|*
name|secp
operator|=
name|code_sec
expr_stmt|;
elseif|else
if|if
condition|(
name|l_rsecnm
operator|==
literal|1
condition|)
block|{
operator|*
name|secp
operator|=
name|data_sec
expr_stmt|;
name|l_vaddr
operator|-=
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
expr_stmt|;
block|}
else|else
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
name|rel
operator|->
name|address
operator|=
name|l_vaddr
expr_stmt|;
return|return
name|true
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_comment
comment|/* Mangle PowerPC NLM relocs for output.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_mangle_relocs
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|data
parameter_list|,
name|offset
parameter_list|,
name|count
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|PTR
name|data
decl_stmt|;
name|bfd_vma
name|offset
decl_stmt|;
name|bfd_size_type
name|count
decl_stmt|;
block|{
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Read a PowerPC NLM import record */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_read_import
argument_list|(
name|abfd
argument_list|,
name|sym
argument_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
name|sym
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|struct
name|nlm_relent
modifier|*
name|nlm_relocs
decl_stmt|;
comment|/* relocation records for symbol */
name|bfd_size_type
name|rcount
decl_stmt|;
comment|/* number of relocs */
name|bfd_byte
name|temp
index|[
name|NLM_TARGET_LONG_SIZE
index|]
decl_stmt|;
comment|/* temporary 32-bit value */
name|unsigned
name|char
name|symlength
decl_stmt|;
comment|/* length of symbol name */
name|char
modifier|*
name|name
decl_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
operator|(
name|PTR
operator|)
operator|&
name|symlength
argument_list|,
sizeof|sizeof
argument_list|(
name|symlength
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|symlength
argument_list|)
condition|)
return|return
operator|(
name|false
operator|)
return|;
name|sym
operator|->
name|symbol
operator|.
name|the_bfd
operator|=
name|abfd
expr_stmt|;
name|name
operator|=
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|symlength
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
return|return
name|false
return|;
if|if
condition|(
name|bfd_read
argument_list|(
name|name
argument_list|,
name|symlength
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
name|symlength
condition|)
return|return
operator|(
name|false
operator|)
return|;
name|name
index|[
name|symlength
index|]
operator|=
literal|'\0'
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|name
operator|=
name|name
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|flags
operator|=
literal|0
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|value
operator|=
literal|0
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|section
operator|=
name|bfd_und_section_ptr
expr_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
operator|(
name|PTR
operator|)
name|temp
argument_list|,
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
condition|)
return|return
operator|(
name|false
operator|)
return|;
name|rcount
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|temp
argument_list|)
expr_stmt|;
name|nlm_relocs
operator|=
operator|(
operator|(
expr|struct
name|nlm_relent
operator|*
operator|)
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|rcount
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|nlm_relent
argument_list|)
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|nlm_relocs
operator|==
operator|(
expr|struct
name|nlm_relent
operator|*
operator|)
name|NULL
condition|)
return|return
name|false
return|;
name|sym
operator|->
name|relocs
operator|=
name|nlm_relocs
expr_stmt|;
name|sym
operator|->
name|rcnt
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|sym
operator|->
name|rcnt
operator|<
name|rcount
condition|)
block|{
name|asection
modifier|*
name|section
decl_stmt|;
if|if
condition|(
name|nlm_powerpc_read_reloc
argument_list|(
name|abfd
argument_list|,
name|sym
argument_list|,
operator|&
name|section
argument_list|,
operator|&
name|nlm_relocs
operator|->
name|reloc
argument_list|)
operator|==
name|false
condition|)
return|return
name|false
return|;
name|nlm_relocs
operator|->
name|section
operator|=
name|section
expr_stmt|;
name|nlm_relocs
operator|++
expr_stmt|;
name|sym
operator|->
name|rcnt
operator|++
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|OLDFORMAT
end_ifndef

begin_comment
comment|/* Write a PowerPC NLM reloc.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_write_import
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|rel
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|arelent
modifier|*
name|rel
decl_stmt|;
block|{
name|asymbol
modifier|*
name|sym
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
name|bfd_byte
name|temp
index|[
literal|4
index|]
decl_stmt|;
comment|/* PowerPC NetWare only supports one kind of reloc.  */
if|if
condition|(
name|rel
operator|->
name|addend
operator|!=
literal|0
operator|||
name|rel
operator|->
name|howto
operator|==
name|NULL
operator|||
name|rel
operator|->
name|howto
operator|->
name|rightshift
operator|!=
literal|0
operator|||
name|rel
operator|->
name|howto
operator|->
name|size
operator|!=
literal|2
operator|||
name|rel
operator|->
name|howto
operator|->
name|bitsize
operator|!=
literal|32
operator|||
name|rel
operator|->
name|howto
operator|->
name|bitpos
operator|!=
literal|0
operator|||
name|rel
operator|->
name|howto
operator|->
name|pc_relative
operator|||
operator|(
name|rel
operator|->
name|howto
operator|->
name|src_mask
operator|!=
literal|0xffffffff
operator|&&
name|rel
operator|->
name|addend
operator|!=
literal|0
operator|)
operator|||
name|rel
operator|->
name|howto
operator|->
name|dst_mask
operator|!=
literal|0xffffffff
condition|)
block|{
name|bfd_set_error
argument_list|(
name|bfd_error_invalid_operation
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|sym
operator|=
operator|*
name|rel
operator|->
name|sym_ptr_ptr
expr_stmt|;
comment|/* The value we write out is the offset into the appropriate      segment, rightshifted by two.  This offset is the section vma,      adjusted by the vma of the lowest section in that segment, plus      the address of the relocation.  */
name|val
operator|=
name|bfd_get_section_vma
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
operator|+
name|rel
operator|->
name|address
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
literal|3
operator|)
operator|!=
literal|0
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
name|val
operator|>>=
literal|2
expr_stmt|;
comment|/* The high bit is 0 if the reloc is in the data section, or 1 if      the reloc is in the code section.  */
if|if
condition|(
name|bfd_get_section_flags
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|)
operator|&
name|SEC_DATA
condition|)
name|val
operator|-=
name|nlm_get_data_low
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
else|else
block|{
name|val
operator|-=
name|nlm_get_text_low
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|val
operator||=
name|NLM_HIBIT
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|bfd_is_und_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
condition|)
block|{
comment|/* This is an internal relocation fixup.  The second most 	 significant bit is 0 if this is a reloc against the data 	 segment, or 1 if it is a reloc against the text segment.  */
if|if
condition|(
name|bfd_get_section_flags
argument_list|(
name|abfd
argument_list|,
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
operator|&
name|SEC_CODE
condition|)
name|val
operator||=
name|NLM_HIBIT
operator|>>
literal|1
expr_stmt|;
block|}
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|val
argument_list|,
name|temp
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
name|temp
argument_list|,
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_comment
comment|/* This is used for the reloc handling in the old format.  */
end_comment

begin_comment
comment|/* Write a PowerPC NLM reloc.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_write_reloc
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|rel
parameter_list|,
name|indx
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|arelent
modifier|*
name|rel
decl_stmt|;
name|int
name|indx
decl_stmt|;
block|{
name|struct
name|nlm32_powerpc_external_reloc
name|ext
decl_stmt|;
name|asection
modifier|*
name|code_sec
decl_stmt|,
modifier|*
name|data_sec
decl_stmt|,
modifier|*
name|bss_sec
decl_stmt|;
name|asymbol
modifier|*
name|sym
decl_stmt|;
name|asection
modifier|*
name|symsec
decl_stmt|;
name|unsigned
name|long
name|l_symndx
decl_stmt|;
name|int
name|l_rtype
decl_stmt|;
name|int
name|l_rsecnm
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto
decl_stmt|;
name|bfd_size_type
name|address
decl_stmt|;
comment|/* Get the sections now, for convenience.  */
name|code_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_CODE_NAME
argument_list|)
expr_stmt|;
name|data_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_INITIALIZED_DATA_NAME
argument_list|)
expr_stmt|;
name|bss_sec
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_UNINITIALIZED_DATA_NAME
argument_list|)
expr_stmt|;
name|sym
operator|=
operator|*
name|rel
operator|->
name|sym_ptr_ptr
expr_stmt|;
name|symsec
operator|=
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
expr_stmt|;
if|if
condition|(
name|indx
operator|!=
operator|-
literal|1
condition|)
block|{
name|BFD_ASSERT
argument_list|(
name|bfd_is_und_section
argument_list|(
name|symsec
argument_list|)
argument_list|)
expr_stmt|;
name|l_symndx
operator|=
name|indx
operator|+
literal|3
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|symsec
operator|==
name|code_sec
condition|)
name|l_symndx
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|symsec
operator|==
name|data_sec
condition|)
name|l_symndx
operator|=
literal|1
expr_stmt|;
elseif|else
if|if
condition|(
name|symsec
operator|==
name|bss_sec
condition|)
name|l_symndx
operator|=
literal|2
expr_stmt|;
else|else
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
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|l_symndx
argument_list|,
name|ext
operator|.
name|l_symndx
argument_list|)
expr_stmt|;
for|for
control|(
name|howto
operator|=
name|nlm_powerpc_howto_table
init|;
name|howto
operator|<
name|nlm_powerpc_howto_table
operator|+
name|HOWTO_COUNT
condition|;
name|howto
operator|++
control|)
block|{
if|if
condition|(
name|howto
operator|->
name|rightshift
operator|==
name|rel
operator|->
name|howto
operator|->
name|rightshift
operator|&&
name|howto
operator|->
name|size
operator|==
name|rel
operator|->
name|howto
operator|->
name|size
operator|&&
name|howto
operator|->
name|bitsize
operator|==
name|rel
operator|->
name|howto
operator|->
name|bitsize
operator|&&
name|howto
operator|->
name|pc_relative
operator|==
name|rel
operator|->
name|howto
operator|->
name|pc_relative
operator|&&
name|howto
operator|->
name|bitpos
operator|==
name|rel
operator|->
name|howto
operator|->
name|bitpos
operator|&&
operator|(
name|howto
operator|->
name|partial_inplace
operator|==
name|rel
operator|->
name|howto
operator|->
name|partial_inplace
operator|||
operator|(
operator|!
name|rel
operator|->
name|howto
operator|->
name|partial_inplace
operator|&&
name|rel
operator|->
name|addend
operator|==
literal|0
operator|)
operator|)
operator|&&
operator|(
name|howto
operator|->
name|src_mask
operator|==
name|rel
operator|->
name|howto
operator|->
name|src_mask
operator|||
operator|(
name|rel
operator|->
name|howto
operator|->
name|src_mask
operator|==
literal|0
operator|&&
name|rel
operator|->
name|addend
operator|==
literal|0
operator|)
operator|)
operator|&&
name|howto
operator|->
name|dst_mask
operator|==
name|rel
operator|->
name|howto
operator|->
name|dst_mask
operator|&&
name|howto
operator|->
name|pcrel_offset
operator|==
name|rel
operator|->
name|howto
operator|->
name|pcrel_offset
condition|)
break|break;
block|}
if|if
condition|(
name|howto
operator|>=
name|nlm_powerpc_howto_table
operator|+
name|HOWTO_COUNT
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
name|l_rtype
operator|=
name|howto
operator|->
name|type
expr_stmt|;
if|if
condition|(
name|howto
operator|->
name|complain_on_overflow
operator|==
name|complain_overflow_signed
condition|)
name|l_rtype
operator||=
literal|0x8000
expr_stmt|;
name|l_rtype
operator||=
operator|(
name|howto
operator|->
name|bitsize
operator|-
literal|1
operator|)
operator|<<
literal|8
expr_stmt|;
name|bfd_h_put_16
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|l_rtype
argument_list|,
name|ext
operator|.
name|l_rtype
argument_list|)
expr_stmt|;
name|address
operator|=
name|rel
operator|->
name|address
expr_stmt|;
if|if
condition|(
name|sec
operator|==
name|code_sec
condition|)
name|l_rsecnm
operator|=
literal|0
expr_stmt|;
elseif|else
if|if
condition|(
name|sec
operator|==
name|data_sec
condition|)
block|{
name|l_rsecnm
operator|=
literal|1
expr_stmt|;
name|address
operator|+=
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
expr_stmt|;
block|}
else|else
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
name|bfd_h_put_16
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|l_rsecnm
argument_list|,
name|ext
operator|.
name|l_rsecnm
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|address
argument_list|,
name|ext
operator|.
name|l_vaddr
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
operator|&
name|ext
argument_list|,
sizeof|sizeof
name|ext
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
name|ext
condition|)
return|return
name|false
return|;
return|return
name|true
return|;
block|}
end_function

begin_comment
comment|/* Write a PowerPC NLM import.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_write_import
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|rel
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|arelent
modifier|*
name|rel
decl_stmt|;
block|{
return|return
name|nlm_powerpc_write_reloc
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|,
name|rel
argument_list|,
operator|-
literal|1
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OLDFORMAT */
end_comment

begin_comment
comment|/* Write a PowerPC NLM external symbol.  This routine keeps a static    count of the symbol index.  FIXME: I don't know if this is    necessary, and the index never gets reset.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_powerpc_write_external
parameter_list|(
name|abfd
parameter_list|,
name|count
parameter_list|,
name|sym
parameter_list|,
name|relocs
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|bfd_size_type
name|count
decl_stmt|;
name|asymbol
modifier|*
name|sym
decl_stmt|;
name|struct
name|reloc_and_sec
modifier|*
name|relocs
decl_stmt|;
block|{
name|unsigned
name|int
name|i
decl_stmt|;
name|bfd_byte
name|len
decl_stmt|;
name|unsigned
name|char
name|temp
index|[
name|NLM_TARGET_LONG_SIZE
index|]
decl_stmt|;
ifdef|#
directive|ifdef
name|OLDFORMAT
specifier|static
name|int
name|indx
decl_stmt|;
endif|#
directive|endif
name|len
operator|=
name|strlen
argument_list|(
name|sym
operator|->
name|name
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|bfd_write
argument_list|(
operator|&
name|len
argument_list|,
sizeof|sizeof
argument_list|(
name|bfd_byte
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|bfd_byte
argument_list|)
operator|)
operator|||
name|bfd_write
argument_list|(
name|sym
operator|->
name|name
argument_list|,
name|len
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
name|len
condition|)
return|return
name|false
return|;
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|count
argument_list|,
name|temp
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
name|temp
argument_list|,
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
argument_list|,
literal|1
argument_list|,
name|abfd
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
name|temp
argument_list|)
condition|)
return|return
name|false
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|count
condition|;
name|i
operator|++
control|)
block|{
ifndef|#
directive|ifndef
name|OLDFORMAT
if|if
condition|(
operator|!
name|nlm_powerpc_write_import
argument_list|(
name|abfd
argument_list|,
name|relocs
index|[
name|i
index|]
operator|.
name|sec
argument_list|,
name|relocs
index|[
name|i
index|]
operator|.
name|rel
argument_list|)
condition|)
return|return
name|false
return|;
else|#
directive|else
if|if
condition|(
operator|!
name|nlm_powerpc_write_reloc
argument_list|(
name|abfd
argument_list|,
name|relocs
index|[
name|i
index|]
operator|.
name|sec
argument_list|,
name|relocs
index|[
name|i
index|]
operator|.
name|rel
argument_list|,
name|indx
argument_list|)
condition|)
return|return
name|false
return|;
endif|#
directive|endif
block|}
ifdef|#
directive|ifdef
name|OLDFORMAT
operator|++
name|indx
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

begin_ifndef
ifndef|#
directive|ifndef
name|OLDFORMAT
end_ifndef

begin_comment
comment|/* PowerPC Netware uses a word offset, not a byte offset, for public    symbols.  */
end_comment

begin_comment
comment|/* Set the section for a public symbol.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_powerpc_set_public_section
argument_list|(
name|abfd
argument_list|,
name|sym
argument_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|nlmNAME
argument_list|(
name|symbol_type
argument_list|)
operator|*
name|sym
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|if
condition|(
name|sym
operator|->
name|symbol
operator|.
name|value
operator|&
name|NLM_HIBIT
condition|)
block|{
name|sym
operator|->
name|symbol
operator|.
name|value
operator|&=
operator|~
name|NLM_HIBIT
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|flags
operator||=
name|BSF_FUNCTION
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|section
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_CODE_NAME
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sym
operator|->
name|symbol
operator|.
name|section
operator|=
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_INITIALIZED_DATA_NAME
argument_list|)
expr_stmt|;
block|}
name|sym
operator|->
name|symbol
operator|.
name|value
operator|<<=
literal|2
expr_stmt|;
return|return
name|true
return|;
block|}
end_block

begin_comment
comment|/* Get the offset to write out for a public symbol.  */
end_comment

begin_function
specifier|static
name|bfd_vma
name|nlm_powerpc_get_public_offset
parameter_list|(
name|abfd
parameter_list|,
name|sym
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asymbol
modifier|*
name|sym
decl_stmt|;
block|{
name|bfd_vma
name|offset
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
name|offset
operator|=
name|bfd_asymbol_value
argument_list|(
name|sym
argument_list|)
expr_stmt|;
name|sec
operator|=
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
expr_stmt|;
if|if
condition|(
name|sec
operator|->
name|flags
operator|&
name|SEC_CODE
condition|)
block|{
name|offset
operator|-=
name|nlm_get_text_low
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|offset
operator||=
name|NLM_HIBIT
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|sec
operator|->
name|flags
operator|&
operator|(
name|SEC_DATA
operator||
name|SEC_ALLOC
operator|)
condition|)
block|{
comment|/* SEC_ALLOC is for the .bss section.  */
name|offset
operator|-=
name|nlm_get_data_low
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* We can't handle an exported symbol that is not in the code or 	 data segment.  */
name|bfd_set_error
argument_list|(
name|bfd_error_invalid_operation
argument_list|)
expr_stmt|;
comment|/* FIXME: No way to return error.  */
name|abort
argument_list|()
expr_stmt|;
block|}
return|return
name|offset
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (OLDFORMAT) */
end_comment

begin_escape
end_escape

begin_include
include|#
directive|include
file|"nlmswap.h"
end_include

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|nlm_backend_data
name|nlm32_powerpc_backend
init|=
block|{
literal|"NetWare PowerPC Module \032"
block|,
sizeof|sizeof
argument_list|(
name|Nlm32_powerpc_External_Fixed_Header
argument_list|)
block|,
ifndef|#
directive|ifndef
name|OLDFORMAT
literal|0
block|,
comment|/* optional_prefix_size */
else|#
directive|else
sizeof|sizeof
argument_list|(
expr|struct
name|nlm32_powerpc_external_prefix_header
argument_list|)
block|,
endif|#
directive|endif
name|bfd_arch_powerpc
block|,
literal|0
block|,
name|false
block|,
ifndef|#
directive|ifndef
name|OLDFORMAT
literal|0
block|,
comment|/* backend_object_p */
literal|0
block|,
comment|/* write_prefix */
else|#
directive|else
name|nlm_powerpc_backend_object_p
block|,
name|nlm_powerpc_write_prefix
block|,
endif|#
directive|endif
name|nlm_powerpc_read_reloc
block|,
name|nlm_powerpc_mangle_relocs
block|,
name|nlm_powerpc_read_import
block|,
name|nlm_powerpc_write_import
block|,
ifndef|#
directive|ifndef
name|OLDFORMAT
name|nlm_powerpc_set_public_section
block|,
name|nlm_powerpc_get_public_offset
block|,
else|#
directive|else
literal|0
block|,
comment|/* set_public_section */
literal|0
block|,
comment|/* get_public_offset */
endif|#
directive|endif
name|nlm_swap_fixed_header_in
block|,
name|nlm_swap_fixed_header_out
block|,
name|nlm_powerpc_write_external
block|,
literal|0
block|,
comment|/* write_export */
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"nlm32-powerpc"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|nlmNAME(powerpc_vec)
end_define

begin_define
define|#
directive|define
name|TARGET_BACKEND_DATA
value|&nlm32_powerpc_backend
end_define

begin_include
include|#
directive|include
file|"nlm-target.h"
end_include

end_unit

