begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for 32-bit Alpha NLM (NetWare Loadable Module)    Copyright (C) 1993 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file describes the 32 bit Alpha NLM format.  You might think    that an Alpha chip would use a 64 bit format, but, for some reason,    it doesn't.  */
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

begin_define
define|#
directive|define
name|ARCH_SIZE
value|32
end_define

begin_include
include|#
directive|include
file|"nlm/alpha-ext.h"
end_include

begin_define
define|#
directive|define
name|Nlm_External_Fixed_Header
value|Nlm32_alpha_External_Fixed_Header
end_define

begin_include
include|#
directive|include
file|"libnlm.h"
end_include

begin_decl_stmt
specifier|static
name|boolean
name|nlm_alpha_backend_object_p
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
name|nlm_alpha_write_prefix
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
name|nlm_alpha_read_reloc
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
name|nlm_alpha_mangle_relocs
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
name|nlm_alpha_read_import
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
name|boolean
name|nlm_alpha_write_import
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
name|nlm_alpha_set_public_section
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
name|nlm_alpha_get_public_offset
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

begin_decl_stmt
specifier|static
name|boolean
name|nlm_alpha_write_external
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

begin_escape
end_escape

begin_comment
comment|/* Alpha NLM's have a prefix header before the standard NLM.  This    function reads it in, verifies the version, and seeks the bfd to    the location before the regular NLM header.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_alpha_backend_object_p
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|nlm32_alpha_external_prefix_header
name|s
decl_stmt|;
name|bfd_size_type
name|size
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
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|s
operator|.
name|magic
argument_list|)
operator|!=
name|NLM32_ALPHA_MAGIC
condition|)
return|return
name|false
return|;
comment|/* FIXME: Should we check the format number?  */
comment|/* Skip to the end of the header.  */
name|size
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
name|s
operator|.
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_seek
argument_list|(
name|abfd
argument_list|,
name|size
argument_list|,
name|SEEK_SET
argument_list|)
operator|!=
literal|0
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
name|nlm_alpha_write_prefix
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|nlm32_alpha_external_prefix_header
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
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
name|NLM32_ALPHA_MAGIC
argument_list|,
name|s
operator|.
name|magic
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
literal|2
argument_list|,
name|s
operator|.
name|format
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_vma
operator|)
sizeof|sizeof
name|s
argument_list|,
name|s
operator|.
name|size
argument_list|)
expr_stmt|;
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

begin_escape
end_escape

begin_comment
comment|/* How to process the various reloc types.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|nlm32_alpha_howto_table
index|[]
init|=
block|{
comment|/* Reloc type 0 is ignored by itself.  However, it appears after a      GPDISP reloc to identify the location where the low order 16 bits      of the gp register are loaded.  */
name|HOWTO
argument_list|(
name|ALPHA_R_IGNORE
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"IGNORE"
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
comment|/* A 32 bit reference to a symbol.  */
name|HOWTO
argument_list|(
name|ALPHA_R_REFLONG
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
literal|"REFLONG"
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
comment|/* A 64 bit reference to a symbol.  */
name|HOWTO
argument_list|(
name|ALPHA_R_REFQUAD
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
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
literal|"REFQUAD"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffffffffffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffffffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 32 bit GP relative offset.  This is just like REFLONG except      that when the value is used the value of the gp register will be      added in.  */
name|HOWTO
argument_list|(
name|ALPHA_R_GPREL32
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
literal|"GPREL32"
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
comment|/* Used for an instruction that refers to memory off the GP      register.  The offset is 16 bits of the 32 bit instruction.  This      reloc always seems to be against the .lita section.  */
name|HOWTO
argument_list|(
name|ALPHA_R_LITERAL
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"LITERAL"
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
comment|/* This reloc only appears immediately following a LITERAL reloc.      It identifies a use of the literal.  It seems that the linker can      use this to eliminate a portion of the .lita section.  The symbol      index is special: 1 means the literal address is in the base      register of a memory format instruction; 2 means the literal      address is in the byte offset register of a byte-manipulation      instruction; 3 means the literal address is in the target      register of a jsr instruction.  This does not actually do any      relocation.  */
name|HOWTO
argument_list|(
name|ALPHA_R_LITUSE
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"LITUSE"
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
comment|/* Load the gp register.  This is always used for a ldah instruction      which loads the upper 16 bits of the gp register.  The next reloc      will be an IGNORE reloc which identifies the location of the lda      instruction which loads the lower 16 bits.  The symbol index of      the GPDISP instruction appears to actually be the number of bytes      between the ldah and lda instructions.  This gives two different      ways to determine where the lda instruction is; I don't know why      both are used.  The value to use for the relocation is the      difference between the GP value and the current location; the      load will always be done against a register holding the current      address.  */
name|HOWTO
argument_list|(
name|ALPHA_R_GPDISP
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
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"GPDISP"
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
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 21 bit branch.  The native assembler generates these for      branches within the text segment, and also fills in the PC      relative offset in the instruction.  It seems to me that this      reloc, unlike the others, is not partial_inplace.  */
name|HOWTO
argument_list|(
name|ALPHA_R_BRADDR
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|21
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
literal|"BRADDR"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x1fffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A hint for a jump to a register.  */
name|HOWTO
argument_list|(
name|ALPHA_R_HINT
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|14
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
literal|0
argument_list|,
comment|/* special_function */
literal|"HINT"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x3fff
argument_list|,
comment|/* src_mask */
literal|0x3fff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative offset.  */
name|HOWTO
argument_list|(
name|ALPHA_R_SREL16
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
literal|0
argument_list|,
comment|/* special_function */
literal|"SREL16"
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
comment|/* 32 bit PC relative offset.  */
name|HOWTO
argument_list|(
name|ALPHA_R_SREL32
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
literal|"SREL32"
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
comment|/* A 64 bit PC relative offset.  */
name|HOWTO
argument_list|(
name|ALPHA_R_SREL64
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
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
literal|"SREL64"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0xffffffffffffffff
argument_list|,
comment|/* src_mask */
literal|0xffffffffffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Push a value on the reloc evaluation stack.  */
name|HOWTO
argument_list|(
name|ALPHA_R_OP_PUSH
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"OP_PUSH"
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
comment|/* Store the value from the stack at the given address.  Store it in      a bitfield of size r_size starting at bit position r_offset.  */
name|HOWTO
argument_list|(
name|ALPHA_R_OP_STORE
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|4
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|64
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
literal|0
argument_list|,
comment|/* special_function */
literal|"OP_STORE"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffffffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Subtract the reloc address from the value on the top of the      relocation stack.  */
name|HOWTO
argument_list|(
name|ALPHA_R_OP_PSUB
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"OP_PSUB"
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
comment|/* Shift the value on the top of the relocation stack right by the      given value.  */
name|HOWTO
argument_list|(
name|ALPHA_R_OP_PRSHIFT
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"OP_PRSHIFT"
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
comment|/* Adjust the GP value for a new range in the object file.  */
name|HOWTO
argument_list|(
argument|ALPHA_R_GPVALUE
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
argument|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
argument|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"GPVALUE"
argument_list|,
comment|/* name */
argument|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0
argument_list|,
comment|/* dst_mask */
argument|false
argument_list|)
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|nlm32_alpha_nw_howto
init|=
name|HOWTO
argument_list|(
name|ALPHA_R_NW_RELOC
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
literal|0
argument_list|,
comment|/* special_function */
literal|"NW_RELOC"
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* Read an Alpha NLM reloc.  This routine keeps some static data which    it uses when handling local relocs.  This only works correctly    because all the local relocs are read at once.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_alpha_read_reloc
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
specifier|static
name|bfd_vma
name|gp_value
decl_stmt|;
specifier|static
name|bfd_vma
name|lita_address
decl_stmt|;
name|struct
name|nlm32_alpha_external_reloc
name|ext
decl_stmt|;
name|bfd_vma
name|r_vaddr
decl_stmt|;
name|long
name|r_symndx
decl_stmt|;
name|int
name|r_type
decl_stmt|,
name|r_extern
decl_stmt|,
name|r_offset
decl_stmt|,
name|r_size
decl_stmt|;
name|asection
modifier|*
name|code_sec
decl_stmt|,
modifier|*
name|data_sec
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
comment|/* Swap in the reloc information.  */
name|r_vaddr
operator|=
name|bfd_h_get_64
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|ext
operator|.
name|r_vaddr
argument_list|)
expr_stmt|;
name|r_symndx
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|ext
operator|.
name|r_symndx
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|bfd_little_endian
argument_list|(
name|abfd
argument_list|)
argument_list|)
expr_stmt|;
name|r_type
operator|=
operator|(
operator|(
name|ext
operator|.
name|r_bits
index|[
literal|0
index|]
operator|&
name|RELOC_BITS0_TYPE_LITTLE
operator|)
operator|>>
name|RELOC_BITS0_TYPE_SH_LITTLE
operator|)
expr_stmt|;
name|r_extern
operator|=
operator|(
name|ext
operator|.
name|r_bits
index|[
literal|1
index|]
operator|&
name|RELOC_BITS1_EXTERN_LITTLE
operator|)
operator|!=
literal|0
expr_stmt|;
name|r_offset
operator|=
operator|(
operator|(
name|ext
operator|.
name|r_bits
index|[
literal|1
index|]
operator|&
name|RELOC_BITS1_OFFSET_LITTLE
operator|)
operator|>>
name|RELOC_BITS1_OFFSET_SH_LITTLE
operator|)
expr_stmt|;
comment|/* Ignore the reserved bits.  */
name|r_size
operator|=
operator|(
operator|(
name|ext
operator|.
name|r_bits
index|[
literal|3
index|]
operator|&
name|RELOC_BITS3_SIZE_LITTLE
operator|)
operator|>>
name|RELOC_BITS3_SIZE_SH_LITTLE
operator|)
expr_stmt|;
comment|/* Fill in the BFD arelent structure.  */
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
if|if
condition|(
name|r_extern
condition|)
block|{
comment|/* External relocations are only used for imports.  */
name|BFD_ASSERT
argument_list|(
name|sym
operator|!=
name|NULL
argument_list|)
expr_stmt|;
comment|/* We don't need to set sym_ptr_ptr for this case.  It is set in 	 nlm_canonicalize_reloc.  */
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|NULL
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* Internal relocations are only used for local relocation 	 fixups.  If they are not NW_RELOC or GPDISP or IGNORE, they 	 must be against .text or .data.  */
name|BFD_ASSERT
argument_list|(
name|r_type
operator|==
name|ALPHA_R_NW_RELOC
operator|||
name|sym
operator|==
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|r_type
operator|==
name|ALPHA_R_NW_RELOC
operator|||
name|r_type
operator|==
name|ALPHA_R_GPDISP
operator|||
name|r_type
operator|==
name|ALPHA_R_IGNORE
condition|)
block|{
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|r_symndx
operator|==
name|ALPHA_RELOC_SECTION_TEXT
condition|)
block|{
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|code_sec
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|bfd_get_section_vma
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
operator|==
literal|0
argument_list|)
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|r_symndx
operator|==
name|ALPHA_RELOC_SECTION_DATA
condition|)
block|{
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|data_sec
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
operator|-
name|bfd_get_section_vma
argument_list|(
name|abfd
argument_list|,
name|data_sec
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/* We use the address to determine whether the reloc is in the .text      or .data section.  R_NW_RELOC relocs don't really have a section,      so we put them in .text.  */
if|if
condition|(
name|r_type
operator|==
name|ALPHA_R_NW_RELOC
operator|||
name|r_vaddr
operator|<
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
condition|)
block|{
operator|*
name|secp
operator|=
name|code_sec
expr_stmt|;
name|rel
operator|->
name|address
operator|=
name|r_vaddr
expr_stmt|;
block|}
else|else
block|{
operator|*
name|secp
operator|=
name|data_sec
expr_stmt|;
name|rel
operator|->
name|address
operator|=
name|r_vaddr
operator|-
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
expr_stmt|;
block|}
comment|/* We must adjust the addend based on the type.  */
name|BFD_ASSERT
argument_list|(
operator|(
name|r_type
operator|>=
literal|0
operator|&&
name|r_type
operator|<=
name|ALPHA_R_GPVALUE
operator|)
operator|||
name|r_type
operator|==
name|ALPHA_R_NW_RELOC
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|ALPHA_R_BRADDR
case|:
case|case
name|ALPHA_R_SREL16
case|:
case|case
name|ALPHA_R_SREL32
case|:
case|case
name|ALPHA_R_SREL64
case|:
comment|/* The PC relative relocs do not seem to use the section VMA as 	 a negative addend.  */
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|ALPHA_R_GPREL32
case|:
comment|/* Copy the gp value for this object file into the addend, to 	 ensure that we are not confused by the linker.  */
if|if
condition|(
operator|!
name|r_extern
condition|)
name|rel
operator|->
name|addend
operator|+=
name|gp_value
expr_stmt|;
break|break;
case|case
name|ALPHA_R_LITERAL
case|:
name|BFD_ASSERT
argument_list|(
operator|!
name|r_extern
argument_list|)
expr_stmt|;
name|rel
operator|->
name|addend
operator|+=
name|lita_address
expr_stmt|;
break|break;
case|case
name|ALPHA_R_LITUSE
case|:
case|case
name|ALPHA_R_GPDISP
case|:
comment|/* The LITUSE and GPDISP relocs do not use a symbol, or an 	 addend, but they do use a special code.  Put this code in the 	 addend field.  */
name|rel
operator|->
name|addend
operator|=
name|r_symndx
expr_stmt|;
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
break|break;
case|case
name|ALPHA_R_OP_STORE
case|:
comment|/* The STORE reloc needs the size and offset fields.  We store 	 them in the addend.  */
name|BFD_ASSERT
argument_list|(
name|r_offset
operator|<
literal|256
operator|&&
name|r_size
operator|<
literal|256
argument_list|)
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
operator|(
name|r_offset
operator|<<
literal|8
operator|)
operator|+
name|r_size
expr_stmt|;
break|break;
case|case
name|ALPHA_R_OP_PUSH
case|:
case|case
name|ALPHA_R_OP_PSUB
case|:
case|case
name|ALPHA_R_OP_PRSHIFT
case|:
comment|/* The PUSH, PSUB and PRSHIFT relocs do not actually use an 	 address.  I believe that the address supplied is really an 	 addend.  */
name|rel
operator|->
name|addend
operator|=
name|r_vaddr
expr_stmt|;
break|break;
case|case
name|ALPHA_R_GPVALUE
case|:
comment|/* Record the new gp value.  */
name|gp_value
operator|+=
name|r_symndx
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
name|gp_value
expr_stmt|;
break|break;
case|case
name|ALPHA_R_IGNORE
case|:
comment|/* If the type is ALPHA_R_IGNORE, make sure this is a reference 	 to the absolute section so that the reloc is ignored.  For 	 some reason the address of this reloc type is not adjusted by 	 the section vma.  We record the gp value for this object file 	 here, for convenience when doing the GPDISP relocation.  */
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|rel
operator|->
name|address
operator|=
name|r_vaddr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
name|gp_value
expr_stmt|;
break|break;
case|case
name|ALPHA_R_NW_RELOC
case|:
comment|/* If this is SETGP, we set the addend to 0.  Otherwise we set 	 the addend to the size of the .lita section (this is 	 r_symndx) plus 1.  We have already set the address of the 	 reloc to r_vaddr.  */
if|if
condition|(
name|r_size
operator|==
name|ALPHA_R_NW_RELOC_SETGP
condition|)
block|{
name|gp_value
operator|=
name|r_vaddr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|r_size
operator|==
name|ALPHA_R_NW_RELOC_LITA
condition|)
block|{
name|lita_address
operator|=
name|r_vaddr
expr_stmt|;
name|rel
operator|->
name|addend
operator|=
name|r_symndx
operator|+
literal|1
expr_stmt|;
block|}
else|else
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|rel
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
break|break;
default|default:
break|break;
block|}
if|if
condition|(
name|r_type
operator|==
name|ALPHA_R_NW_RELOC
condition|)
name|rel
operator|->
name|howto
operator|=
operator|&
name|nlm32_alpha_nw_howto
expr_stmt|;
else|else
name|rel
operator|->
name|howto
operator|=
operator|&
name|nlm32_alpha_howto_table
index|[
name|r_type
index|]
expr_stmt|;
return|return
name|true
return|;
block|}
end_block

begin_comment
comment|/* Mangle Alpha NLM relocs for output.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_alpha_mangle_relocs
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
comment|/* Read an ALPHA NLM import record */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_alpha_read_import
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
name|false
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
name|false
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
name|false
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
operator|!
name|nlm_relocs
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
name|nlm_alpha_read_reloc
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

begin_comment
comment|/* Write an Alpha NLM reloc.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_alpha_write_import
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
name|r_vaddr
decl_stmt|;
name|long
name|r_symndx
decl_stmt|;
name|int
name|r_type
decl_stmt|,
name|r_extern
decl_stmt|,
name|r_offset
decl_stmt|,
name|r_size
decl_stmt|;
name|struct
name|nlm32_alpha_external_reloc
name|ext
decl_stmt|;
name|sym
operator|=
operator|*
name|rel
operator|->
name|sym_ptr_ptr
expr_stmt|;
comment|/* Get values for the relocation fields.  */
name|r_type
operator|=
name|rel
operator|->
name|howto
operator|->
name|type
expr_stmt|;
if|if
condition|(
name|r_type
operator|!=
name|ALPHA_R_NW_RELOC
condition|)
block|{
name|r_vaddr
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
name|sec
operator|->
name|flags
operator|&
name|SEC_CODE
operator|)
operator|==
literal|0
condition|)
name|r_vaddr
operator|+=
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|bfd_get_section_by_name
argument_list|(
name|abfd
argument_list|,
name|NLM_CODE_NAME
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
condition|)
block|{
name|r_extern
operator|=
literal|1
expr_stmt|;
name|r_symndx
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|r_extern
operator|=
literal|0
expr_stmt|;
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
name|r_symndx
operator|=
name|ALPHA_RELOC_SECTION_TEXT
expr_stmt|;
else|else
name|r_symndx
operator|=
name|ALPHA_RELOC_SECTION_DATA
expr_stmt|;
block|}
name|r_offset
operator|=
literal|0
expr_stmt|;
name|r_size
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|ALPHA_R_LITUSE
case|:
case|case
name|ALPHA_R_GPDISP
case|:
name|r_symndx
operator|=
name|rel
operator|->
name|addend
expr_stmt|;
break|break;
case|case
name|ALPHA_R_OP_STORE
case|:
name|r_size
operator|=
name|rel
operator|->
name|addend
operator|&
literal|0xff
expr_stmt|;
name|r_offset
operator|=
operator|(
name|rel
operator|->
name|addend
operator|>>
literal|8
operator|)
operator|&
literal|0xff
expr_stmt|;
break|break;
case|case
name|ALPHA_R_OP_PUSH
case|:
case|case
name|ALPHA_R_OP_PSUB
case|:
case|case
name|ALPHA_R_OP_PRSHIFT
case|:
name|r_vaddr
operator|=
name|rel
operator|->
name|addend
expr_stmt|;
break|break;
case|case
name|ALPHA_R_IGNORE
case|:
name|r_vaddr
operator|=
name|rel
operator|->
name|address
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
else|else
block|{
comment|/* r_type == ALPHA_R_NW_RELOC */
name|r_vaddr
operator|=
name|rel
operator|->
name|address
expr_stmt|;
if|if
condition|(
name|rel
operator|->
name|addend
operator|==
literal|0
condition|)
block|{
name|r_symndx
operator|=
literal|0
expr_stmt|;
name|r_size
operator|=
name|ALPHA_R_NW_RELOC_SETGP
expr_stmt|;
block|}
else|else
block|{
name|r_symndx
operator|=
name|rel
operator|->
name|addend
operator|-
literal|1
expr_stmt|;
name|r_size
operator|=
name|ALPHA_R_NW_RELOC_LITA
expr_stmt|;
block|}
name|r_extern
operator|=
literal|0
expr_stmt|;
name|r_offset
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Swap out the relocation fields.  */
name|bfd_h_put_64
argument_list|(
name|abfd
argument_list|,
name|r_vaddr
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|ext
operator|.
name|r_vaddr
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
name|r_symndx
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|ext
operator|.
name|r_symndx
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|bfd_little_endian
argument_list|(
name|abfd
argument_list|)
argument_list|)
expr_stmt|;
name|ext
operator|.
name|r_bits
index|[
literal|0
index|]
operator|=
operator|(
operator|(
name|r_type
operator|<<
name|RELOC_BITS0_TYPE_SH_LITTLE
operator|)
operator|&
name|RELOC_BITS0_TYPE_LITTLE
operator|)
expr_stmt|;
name|ext
operator|.
name|r_bits
index|[
literal|1
index|]
operator|=
operator|(
operator|(
name|r_extern
condition|?
name|RELOC_BITS1_EXTERN_LITTLE
else|:
literal|0
operator|)
operator||
operator|(
operator|(
name|r_offset
operator|<<
name|RELOC_BITS1_OFFSET_SH_LITTLE
operator|)
operator|&
name|RELOC_BITS1_OFFSET_LITTLE
operator|)
operator|)
expr_stmt|;
name|ext
operator|.
name|r_bits
index|[
literal|2
index|]
operator|=
literal|0
expr_stmt|;
name|ext
operator|.
name|r_bits
index|[
literal|3
index|]
operator|=
operator|(
operator|(
name|r_size
operator|<<
name|RELOC_BITS3_SIZE_SH_LITTLE
operator|)
operator|&
name|RELOC_BITS3_SIZE_LITTLE
operator|)
expr_stmt|;
comment|/* Write out the relocation.  */
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

begin_escape
end_escape

begin_comment
comment|/* Alpha NetWare does not use the high bit to determine whether a    public symbol is in the code segment or the data segment.  Instead,    it just uses the address.  The set_public_section and    get_public_offset routines override the default code which uses the    high bit.  */
end_comment

begin_comment
comment|/* Set the section for a public symbol.  */
end_comment

begin_decl_stmt
specifier|static
name|boolean
name|nlm_alpha_set_public_section
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
name|asection
modifier|*
name|code_sec
decl_stmt|,
modifier|*
name|data_sec
decl_stmt|;
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
if|if
condition|(
name|sym
operator|->
name|symbol
operator|.
name|value
operator|<
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
condition|)
block|{
name|sym
operator|->
name|symbol
operator|.
name|section
operator|=
name|code_sec
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|flags
operator||=
name|BSF_FUNCTION
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
name|data_sec
expr_stmt|;
name|sym
operator|->
name|symbol
operator|.
name|value
operator|-=
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
expr_stmt|;
comment|/* The data segment had better be aligned.  */
name|BFD_ASSERT
argument_list|(
operator|(
name|bfd_section_size
argument_list|(
name|abfd
argument_list|,
name|code_sec
argument_list|)
operator|&
literal|0xf
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
block|}
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
name|nlm_alpha_get_public_offset
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
return|return
name|bfd_asymbol_value
argument_list|(
name|sym
argument_list|)
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Write an Alpha NLM external symbol.  */
end_comment

begin_function
specifier|static
name|boolean
name|nlm_alpha_write_external
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
name|arelent
name|r
decl_stmt|;
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
operator|+
literal|2
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
comment|/* The first two relocs for each external symbol are the .lita      address and the GP value.  */
name|r
operator|.
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
name|r
operator|.
name|howto
operator|=
operator|&
name|nlm32_alpha_nw_howto
expr_stmt|;
name|r
operator|.
name|address
operator|=
name|nlm_alpha_backend_data
argument_list|(
name|abfd
argument_list|)
operator|->
name|lita_address
expr_stmt|;
name|r
operator|.
name|addend
operator|=
name|nlm_alpha_backend_data
argument_list|(
name|abfd
argument_list|)
operator|->
name|lita_size
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|nlm_alpha_write_import
argument_list|(
name|abfd
argument_list|,
operator|(
name|asection
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|r
argument_list|)
operator|==
name|false
condition|)
return|return
name|false
return|;
name|r
operator|.
name|address
operator|=
name|nlm_alpha_backend_data
argument_list|(
name|abfd
argument_list|)
operator|->
name|gp
expr_stmt|;
name|r
operator|.
name|addend
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|nlm_alpha_write_import
argument_list|(
name|abfd
argument_list|,
operator|(
name|asection
operator|*
operator|)
name|NULL
argument_list|,
operator|&
name|r
argument_list|)
operator|==
name|false
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
if|if
condition|(
name|nlm_alpha_write_import
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
operator|==
name|false
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
end_function

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
name|nlm32_alpha_backend
init|=
block|{
literal|"NetWare Alpha Module   \032"
block|,
sizeof|sizeof
argument_list|(
name|Nlm32_alpha_External_Fixed_Header
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|nlm32_alpha_external_prefix_header
argument_list|)
block|,
name|bfd_arch_alpha
block|,
literal|0
block|,
name|true
block|,
comment|/* no uninitialized data permitted by Alpha NetWare.  */
name|nlm_alpha_backend_object_p
block|,
name|nlm_alpha_write_prefix
block|,
name|nlm_alpha_read_reloc
block|,
name|nlm_alpha_mangle_relocs
block|,
name|nlm_alpha_read_import
block|,
name|nlm_alpha_write_import
block|,
name|nlm_alpha_set_public_section
block|,
name|nlm_alpha_get_public_offset
block|,
name|nlm_swap_fixed_header_in
block|,
name|nlm_swap_fixed_header_out
block|,
name|nlm_alpha_write_external
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
name|TARGET_LITTLE_NAME
value|"nlm32-alpha"
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|nlmNAME(alpha_vec)
end_define

begin_define
define|#
directive|define
name|TARGET_BACKEND_DATA
value|&nlm32_alpha_backend
end_define

begin_include
include|#
directive|include
file|"nlm-target.h"
end_include

end_unit

