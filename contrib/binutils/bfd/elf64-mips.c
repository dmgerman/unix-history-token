begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MIPS-specific support for 64-bit ELF    Copyright 1996, 1997, 1998, 1999 Free Software Foundation, Inc.    Ian Lance Taylor, Cygnus Support    Linker support added by Mark Mitchell, CodeSourcery, LLC.<mark@codesourcery.com>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file supports the 64-bit MIPS ELF ABI.     The MIPS 64-bit ELF ABI uses an unusual reloc format.  This file    overrides the usual ELF reloc handling, and handles reading and    writing the relocations here.     The MIPS 64-bit ELF ABI also uses an unusual archive map format.  */
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
file|"aout/ar.h"
end_include

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_include
include|#
directive|include
file|"genlink.h"
end_include

begin_include
include|#
directive|include
file|"elf-bfd.h"
end_include

begin_include
include|#
directive|include
file|"elf/mips.h"
end_include

begin_comment
comment|/* Get the ECOFF swapping routines.  The 64-bit ABI is not supposed to    use ECOFF.  However, we support it anyhow for an easier changeover.  */
end_comment

begin_include
include|#
directive|include
file|"coff/sym.h"
end_include

begin_include
include|#
directive|include
file|"coff/symconst.h"
end_include

begin_include
include|#
directive|include
file|"coff/internal.h"
end_include

begin_include
include|#
directive|include
file|"coff/ecoff.h"
end_include

begin_comment
comment|/* The 64 bit versions of the mdebug data structures are in alpha.h.  */
end_comment

begin_include
include|#
directive|include
file|"coff/alpha.h"
end_include

begin_define
define|#
directive|define
name|ECOFF_64
end_define

begin_include
include|#
directive|include
file|"ecoffswap.h"
end_include

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_swap_reloc_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_Mips_External_Rel
operator|*
operator|,
name|Elf64_Mips_Internal_Rel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_swap_reloca_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_Mips_External_Rela
operator|*
operator|,
name|Elf64_Mips_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_swap_reloc_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_Mips_Internal_Rel
operator|*
operator|,
name|Elf64_Mips_External_Rel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_swap_reloca_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_Mips_Internal_Rela
operator|*
operator|,
name|Elf64_Mips_External_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_be_swap_reloc_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|bfd_byte
operator|*
operator|,
name|Elf_Internal_Rel
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_be_swap_reloc_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf_Internal_Rel
operator|*
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_be_swap_reloca_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|bfd_byte
operator|*
operator|,
name|Elf_Internal_Rela
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_be_swap_reloca_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf_Internal_Rela
operator|*
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|mips_elf64_reloc_type_lookup
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
name|long
name|mips_elf64_get_reloc_upper_bound
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|mips_elf64_slurp_one_reloc_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
specifier|const
name|Elf_Internal_Shdr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|mips_elf64_slurp_reloc_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|boolean
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|mips_elf64_write_relocs
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|boolean
name|mips_elf64_slurp_armap
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
name|mips_elf64_write_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|unsigned
name|int
operator|,
expr|struct
name|orl
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In case we're on a 32-bit machine, construct a 64-bit "-1" value    from smaller values.  Start with zero, widen, *then* decrement.  */
end_comment

begin_define
define|#
directive|define
name|MINUS_ONE
value|(((bfd_vma)0) - 1)
end_define

begin_comment
comment|/* The number of local .got entries we reserve.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_RESERVED_GOTNO
value|(2)
end_define

begin_comment
comment|/* The relocation table used for SHT_REL sections.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips_elf64_howto_table_rel
index|[]
init|=
block|{
comment|/* No relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_NONE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_NONE"
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
comment|/* 16 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_16"
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
comment|/* 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_32
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_32"
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
comment|/* 32 bit symbol relative relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_REL32
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL32"
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
comment|/* 26 bit branch address.  */
name|HOWTO
argument_list|(
name|R_MIPS_26
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper four 				   bits must match the PC.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_26"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x3ffffff
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_hi16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HI16"
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
comment|/* Low 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_lo16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LO16"
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
comment|/* GP relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_GPREL16
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
name|_bfd_mips_elf_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL16"
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
comment|/* Reference to literal section.  */
name|HOWTO
argument_list|(
name|R_MIPS_LITERAL
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
name|_bfd_mips_elf_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LITERAL"
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
comment|/* Reference to global offset table.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT16
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
name|_bfd_mips_elf_got16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_PC16
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
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PC16"
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
comment|/* 16 bit call through global offset table.  */
comment|/* FIXME: This is not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit GP relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_GPREL32
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
name|_bfd_mips_elf_gprel32_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL32"
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
literal|13
block|}
block|,
block|{
literal|14
block|}
block|,
block|{
literal|15
block|}
block|,
comment|/* A 5 bit shift field.  */
name|HOWTO
argument_list|(
name|R_MIPS_SHIFT5
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|5
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT5"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x000007c0
argument_list|,
comment|/* src_mask */
literal|0x000007c0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 6 bit shift field.  */
comment|/* FIXME: This is not handled correctly; a special function is      needed to put the most significant bit in the right place.  */
name|HOWTO
argument_list|(
name|R_MIPS_SHIFT6
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|6
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT6"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x000007c4
argument_list|,
comment|/* src_mask */
literal|0x000007c4
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 64 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_64
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_64"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_DISP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_DISP"
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
comment|/* Displacement to page pointer in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_PAGE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_PAGE"
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
comment|/* Offset from page pointer in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_OFST
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_OFST"
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
comment|/* High 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_HI16"
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
comment|/* Low 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_LO16"
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
comment|/* 64 bit substraction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_SUB
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SUB"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Insert the addend as an instruction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_INSERT_A
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_A"
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
comment|/* Insert the addend as an instruction, and change all relocations      to refer to the old instruction at the address.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_INSERT_B
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_B"
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
comment|/* Delete a 32 bit instruction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_DELETE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_DELETE"
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
comment|/* Get the higher value of a 64 bit addend.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_HIGHER
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHER"
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
comment|/* Get the highest value of a 64 bit addend.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_HIGHEST
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHEST"
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
comment|/* High 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_HI16"
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
comment|/* Low 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_LO16"
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
comment|/* I'm not sure what the remaining relocs are, but they are defined      on Irix 6.  */
name|HOWTO
argument_list|(
name|R_MIPS_SCN_DISP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SCN_DISP"
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
name|HOWTO
argument_list|(
name|R_MIPS_REL16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL16"
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
name|HOWTO
argument_list|(
name|R_MIPS_ADD_IMMEDIATE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_ADD_IMMEDIATE"
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
name|HOWTO
argument_list|(
name|R_MIPS_PJUMP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PJUMP"
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
name|HOWTO
argument_list|(
name|R_MIPS_RELGOT
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_RELGOT"
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
comment|/* Protected jump conversion.  This is an optimization hint.  No       relocation is required for correctness.  */
name|HOWTO
argument_list|(
name|R_MIPS_JALR
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_JALR"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0x00000000
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The relocation table used for SHT_RELA sections.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips_elf64_howto_table_rela
index|[]
init|=
block|{
comment|/* No relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_NONE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_NONE"
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
comment|/* 16 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_32
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit symbol relative relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_REL32
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 26 bit branch address.  */
name|HOWTO
argument_list|(
name|R_MIPS_26
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
name|false
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper four 				   bits must match the PC.  */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_26"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HI16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LO16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* GP relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_GPREL16
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
name|_bfd_mips_elf_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Reference to literal section.  */
name|HOWTO
argument_list|(
name|R_MIPS_LITERAL
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
name|_bfd_mips_elf_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LITERAL"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Reference to global offset table.  */
comment|/* FIXME: This is not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_PC16
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
name|true
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PC16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit call through global offset table.  */
comment|/* FIXME: This is not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL16"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit GP relative reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_GPREL32
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
name|_bfd_mips_elf_gprel32_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
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
literal|13
block|}
block|,
block|{
literal|14
block|}
block|,
block|{
literal|15
block|}
block|,
comment|/* A 5 bit shift field.  */
name|HOWTO
argument_list|(
name|R_MIPS_SHIFT5
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|5
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT5"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x000007c0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 6 bit shift field.  */
comment|/* FIXME: This is not handled correctly; a special function is      needed to put the most significant bit in the right place.  */
name|HOWTO
argument_list|(
name|R_MIPS_SHIFT6
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|6
argument_list|,
comment|/* bitsize */
name|false
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT6"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x000007c4
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 64 bit relocation.  */
name|HOWTO
argument_list|(
name|R_MIPS_64
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_64"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_DISP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_DISP"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement to page pointer in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_PAGE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_PAGE"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Offset from page pointer in the global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_OFST
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_OFST"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_HI16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_GOT_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_LO16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 64 bit substraction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_SUB
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SUB"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Insert the addend as an instruction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_INSERT_A
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_A"
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
comment|/* Insert the addend as an instruction, and change all relocations      to refer to the old instruction at the address.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_INSERT_B
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_B"
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
comment|/* Delete a 32 bit instruction.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_DELETE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_DELETE"
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
comment|/* Get the higher value of a 64 bit addend.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_HIGHER
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHER"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Get the highest value of a 64 bit addend.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_HIGHEST
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHEST"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL_HI16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_HI16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
comment|/* FIXME: Not handled correctly.  */
name|HOWTO
argument_list|(
name|R_MIPS_CALL_LO16
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
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_LO16"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* I'm not sure what the remaining relocs are, but they are defined      on Irix 6.  */
name|HOWTO
argument_list|(
name|R_MIPS_SCN_DISP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SCN_DISP"
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
name|HOWTO
argument_list|(
name|R_MIPS_REL16
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL16"
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
name|HOWTO
argument_list|(
name|R_MIPS_ADD_IMMEDIATE
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_ADD_IMMEDIATE"
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
name|HOWTO
argument_list|(
name|R_MIPS_PJUMP
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PJUMP"
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
name|HOWTO
argument_list|(
name|R_MIPS_RELGOT
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_RELGOT"
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
comment|/* Protected jump conversion.  This is an optimization hint.  No       relocation is required for correctness.  */
name|HOWTO
argument_list|(
name|R_MIPS_JALR
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_JALR"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0x00000000
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Swap in a MIPS 64-bit Rel reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_swap_reloc_in
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf64_Mips_External_Rel
modifier|*
name|src
decl_stmt|;
name|Elf64_Mips_Internal_Rel
modifier|*
name|dst
decl_stmt|;
block|{
name|dst
operator|->
name|r_offset
operator|=
name|bfd_h_get_64
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_sym
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_ssym
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type3
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type2
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap in a MIPS 64-bit Rela reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_swap_reloca_in
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf64_Mips_External_Rela
modifier|*
name|src
decl_stmt|;
name|Elf64_Mips_Internal_Rela
modifier|*
name|dst
decl_stmt|;
block|{
name|dst
operator|->
name|r_offset
operator|=
name|bfd_h_get_64
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_sym
operator|=
name|bfd_h_get_32
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_ssym
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type3
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type2
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type
operator|=
name|bfd_h_get_8
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_addend
operator|=
name|bfd_h_get_signed_64
argument_list|(
name|abfd
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|src
operator|->
name|r_addend
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap out a MIPS 64-bit Rel reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_swap_reloc_out
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf64_Mips_Internal_Rel
modifier|*
name|src
decl_stmt|;
name|Elf64_Mips_External_Rel
modifier|*
name|dst
decl_stmt|;
block|{
name|bfd_h_put_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap out a MIPS 64-bit Rela reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_swap_reloca_out
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf64_Mips_Internal_Rela
modifier|*
name|src
decl_stmt|;
name|Elf64_Mips_External_Rela
modifier|*
name|dst
decl_stmt|;
block|{
name|bfd_h_put_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|bfd_h_put_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|bfd_h_put_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|bfd_h_put_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_addend
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|dst
operator|->
name|r_addend
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap in a MIPS 64-bit Rel reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_be_swap_reloc_in
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|bfd_byte
modifier|*
name|src
decl_stmt|;
name|Elf_Internal_Rel
modifier|*
name|dst
decl_stmt|;
block|{
name|Elf64_Mips_Internal_Rel
name|mirel
decl_stmt|;
name|mips_elf64_swap_reloc_in
argument_list|(
name|abfd
argument_list|,
operator|(
specifier|const
name|Elf64_Mips_External_Rel
operator|*
operator|)
name|src
argument_list|,
operator|&
name|mirel
argument_list|)
expr_stmt|;
name|dst
index|[
literal|0
index|]
operator|.
name|r_offset
operator|=
name|mirel
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|0
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|mirel
operator|.
name|r_sym
argument_list|,
name|mirel
operator|.
name|r_type
argument_list|)
expr_stmt|;
name|dst
index|[
literal|1
index|]
operator|.
name|r_offset
operator|=
name|mirel
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|1
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|mirel
operator|.
name|r_ssym
argument_list|,
name|mirel
operator|.
name|r_type2
argument_list|)
expr_stmt|;
name|dst
index|[
literal|2
index|]
operator|.
name|r_offset
operator|=
name|mirel
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|2
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|STN_UNDEF
argument_list|,
name|mirel
operator|.
name|r_type3
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap in a MIPS 64-bit Rela reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_be_swap_reloca_in
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|bfd_byte
modifier|*
name|src
decl_stmt|;
name|Elf_Internal_Rela
modifier|*
name|dst
decl_stmt|;
block|{
name|Elf64_Mips_Internal_Rela
name|mirela
decl_stmt|;
name|mips_elf64_swap_reloca_in
argument_list|(
name|abfd
argument_list|,
operator|(
specifier|const
name|Elf64_Mips_External_Rela
operator|*
operator|)
name|src
argument_list|,
operator|&
name|mirela
argument_list|)
expr_stmt|;
name|dst
index|[
literal|0
index|]
operator|.
name|r_offset
operator|=
name|mirela
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|0
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|mirela
operator|.
name|r_sym
argument_list|,
name|mirela
operator|.
name|r_type
argument_list|)
expr_stmt|;
name|dst
index|[
literal|0
index|]
operator|.
name|r_addend
operator|=
name|mirela
operator|.
name|r_addend
expr_stmt|;
name|dst
index|[
literal|1
index|]
operator|.
name|r_offset
operator|=
name|mirela
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|1
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|mirela
operator|.
name|r_ssym
argument_list|,
name|mirela
operator|.
name|r_type2
argument_list|)
expr_stmt|;
name|dst
index|[
literal|1
index|]
operator|.
name|r_addend
operator|=
literal|0
expr_stmt|;
name|dst
index|[
literal|2
index|]
operator|.
name|r_offset
operator|=
name|mirela
operator|.
name|r_offset
expr_stmt|;
name|dst
index|[
literal|2
index|]
operator|.
name|r_info
operator|=
name|ELF32_R_INFO
argument_list|(
name|STN_UNDEF
argument_list|,
name|mirela
operator|.
name|r_type3
argument_list|)
expr_stmt|;
name|dst
index|[
literal|2
index|]
operator|.
name|r_addend
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap out a MIPS 64-bit Rel reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_be_swap_reloc_out
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf_Internal_Rel
modifier|*
name|src
decl_stmt|;
name|bfd_byte
modifier|*
name|dst
decl_stmt|;
block|{
name|Elf64_Mips_Internal_Rel
name|mirel
decl_stmt|;
name|mirel
operator|.
name|r_offset
operator|=
name|src
operator|->
name|r_offset
expr_stmt|;
name|mirel
operator|.
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|src
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_sym
operator|=
name|ELF32_R_SYM
argument_list|(
name|src
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_type2
operator|=
name|R_MIPS_NONE
expr_stmt|;
name|mirel
operator|.
name|r_ssym
operator|=
name|STN_UNDEF
expr_stmt|;
name|mirel
operator|.
name|r_type3
operator|=
name|R_MIPS_NONE
expr_stmt|;
name|mips_elf64_swap_reloc_out
argument_list|(
name|abfd
argument_list|,
operator|&
name|mirel
argument_list|,
operator|(
name|Elf64_Mips_External_Rel
operator|*
operator|)
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Swap out a MIPS 64-bit Rela reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_be_swap_reloca_out
parameter_list|(
name|abfd
parameter_list|,
name|src
parameter_list|,
name|dst
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
specifier|const
name|Elf_Internal_Rela
modifier|*
name|src
decl_stmt|;
name|bfd_byte
modifier|*
name|dst
decl_stmt|;
block|{
name|Elf64_Mips_Internal_Rela
name|mirela
decl_stmt|;
name|mirela
operator|.
name|r_offset
operator|=
name|src
operator|->
name|r_offset
expr_stmt|;
name|mirela
operator|.
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|src
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_addend
operator|=
name|src
operator|->
name|r_addend
expr_stmt|;
name|mirela
operator|.
name|r_sym
operator|=
name|ELF32_R_SYM
argument_list|(
name|src
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_type2
operator|=
name|R_MIPS_NONE
expr_stmt|;
name|mirela
operator|.
name|r_ssym
operator|=
name|STN_UNDEF
expr_stmt|;
name|mirela
operator|.
name|r_type3
operator|=
name|R_MIPS_NONE
expr_stmt|;
name|mips_elf64_swap_reloca_out
argument_list|(
name|abfd
argument_list|,
operator|&
name|mirela
argument_list|,
operator|(
name|Elf64_Mips_External_Rela
operator|*
operator|)
name|dst
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* A mapping from BFD reloc types to MIPS ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|elf_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|enum
name|elf_mips_reloc_type
name|elf_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
specifier|static
name|CONST
expr|struct
name|elf_reloc_map
name|mips_reloc_map
index|[]
operator|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_MIPS_NONE
block|, }
block|,
block|{
name|BFD_RELOC_16
block|,
name|R_MIPS_16
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_MIPS_32
block|}
block|,
block|{
name|BFD_RELOC_64
block|,
name|R_MIPS_64
block|}
block|,
block|{
name|BFD_RELOC_CTOR
block|,
name|R_MIPS_64
block|}
block|,
block|{
name|BFD_RELOC_32_PCREL
block|,
name|R_MIPS_REL32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_JMP
block|,
name|R_MIPS_26
block|}
block|,
block|{
name|BFD_RELOC_HI16_S
block|,
name|R_MIPS_HI16
block|}
block|,
block|{
name|BFD_RELOC_LO16
block|,
name|R_MIPS_LO16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GPREL
block|,
name|R_MIPS_GPREL16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_LITERAL
block|,
name|R_MIPS_LITERAL
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT16
block|,
name|R_MIPS_GOT16
block|}
block|,
block|{
name|BFD_RELOC_16_PCREL
block|,
name|R_MIPS_PC16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_CALL16
block|,
name|R_MIPS_CALL16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GPREL32
block|,
name|R_MIPS_GPREL32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_HI16
block|,
name|R_MIPS_GOT_HI16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_LO16
block|,
name|R_MIPS_GOT_LO16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_CALL_HI16
block|,
name|R_MIPS_CALL_HI16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_CALL_LO16
block|,
name|R_MIPS_CALL_LO16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_SUB
block|,
name|R_MIPS_SUB
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_PAGE
block|,
name|R_MIPS_GOT_PAGE
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_OFST
block|,
name|R_MIPS_GOT_OFST
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_DISP
block|,
name|R_MIPS_GOT_DISP
block|}
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Given a BFD reloc type, return a howto structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mips_elf64_reloc_type_lookup
parameter_list|(
name|abfd
parameter_list|,
name|code
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|bfd_reloc_code_real_type
name|code
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
argument_list|(
name|mips_reloc_map
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
expr|struct
name|elf_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|mips_reloc_map
index|[
name|i
index|]
operator|.
name|bfd_reloc_val
operator|==
name|code
condition|)
block|{
name|int
name|v
decl_stmt|;
name|v
operator|=
operator|(
name|int
operator|)
name|mips_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
expr_stmt|;
return|return
operator|&
name|mips_elf64_howto_table_rel
index|[
name|v
index|]
return|;
block|}
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Since each entry in an SHT_REL or SHT_RELA section can represent up    to three relocs, we must tell the user to allocate more space.  */
end_comment

begin_function
specifier|static
name|long
name|mips_elf64_get_reloc_upper_bound
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|sec
decl_stmt|;
block|{
return|return
operator|(
name|sec
operator|->
name|reloc_count
operator|*
literal|3
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|arelent
operator|*
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Read the relocations from one reloc section.  */
end_comment

begin_function
specifier|static
name|boolean
name|mips_elf64_slurp_one_reloc_table
parameter_list|(
name|abfd
parameter_list|,
name|asect
parameter_list|,
name|symbols
parameter_list|,
name|rel_hdr
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|asect
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|;
specifier|const
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr
decl_stmt|;
block|{
name|PTR
name|allocated
init|=
name|NULL
decl_stmt|;
name|bfd_byte
modifier|*
name|native_relocs
decl_stmt|;
name|arelent
modifier|*
name|relents
decl_stmt|;
name|arelent
modifier|*
name|relent
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
name|int
name|entsize
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto_table
decl_stmt|;
name|allocated
operator|=
operator|(
name|PTR
operator|)
name|bfd_malloc
argument_list|(
name|rel_hdr
operator|->
name|sh_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|allocated
operator|==
name|NULL
condition|)
goto|goto
name|error_return
goto|;
if|if
condition|(
name|bfd_seek
argument_list|(
name|abfd
argument_list|,
name|rel_hdr
operator|->
name|sh_offset
argument_list|,
name|SEEK_SET
argument_list|)
operator|!=
literal|0
operator|||
operator|(
name|bfd_read
argument_list|(
name|allocated
argument_list|,
literal|1
argument_list|,
name|rel_hdr
operator|->
name|sh_size
argument_list|,
name|abfd
argument_list|)
operator|!=
name|rel_hdr
operator|->
name|sh_size
operator|)
condition|)
goto|goto
name|error_return
goto|;
name|native_relocs
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|allocated
expr_stmt|;
name|relents
operator|=
name|asect
operator|->
name|relocation
operator|+
name|asect
operator|->
name|reloc_count
expr_stmt|;
name|entsize
operator|=
name|rel_hdr
operator|->
name|sh_entsize
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rel
argument_list|)
operator|||
name|entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rela
argument_list|)
argument_list|)
expr_stmt|;
name|count
operator|=
name|rel_hdr
operator|->
name|sh_size
operator|/
name|entsize
expr_stmt|;
if|if
condition|(
name|entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rel
argument_list|)
condition|)
name|howto_table
operator|=
name|mips_elf64_howto_table_rel
expr_stmt|;
else|else
name|howto_table
operator|=
name|mips_elf64_howto_table_rela
expr_stmt|;
name|relent
operator|=
name|relents
expr_stmt|;
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
operator|,
name|native_relocs
operator|+=
name|entsize
control|)
block|{
name|Elf64_Mips_Internal_Rela
name|rela
decl_stmt|;
name|boolean
name|used_sym
decl_stmt|,
name|used_ssym
decl_stmt|;
name|int
name|ir
decl_stmt|;
if|if
condition|(
name|entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rela
argument_list|)
condition|)
name|mips_elf64_swap_reloca_in
argument_list|(
name|abfd
argument_list|,
operator|(
name|Elf64_Mips_External_Rela
operator|*
operator|)
name|native_relocs
argument_list|,
operator|&
name|rela
argument_list|)
expr_stmt|;
else|else
block|{
name|Elf64_Mips_Internal_Rel
name|rel
decl_stmt|;
name|mips_elf64_swap_reloc_in
argument_list|(
name|abfd
argument_list|,
operator|(
name|Elf64_Mips_External_Rel
operator|*
operator|)
name|native_relocs
argument_list|,
operator|&
name|rel
argument_list|)
expr_stmt|;
name|rela
operator|.
name|r_offset
operator|=
name|rel
operator|.
name|r_offset
expr_stmt|;
name|rela
operator|.
name|r_sym
operator|=
name|rel
operator|.
name|r_sym
expr_stmt|;
name|rela
operator|.
name|r_ssym
operator|=
name|rel
operator|.
name|r_ssym
expr_stmt|;
name|rela
operator|.
name|r_type3
operator|=
name|rel
operator|.
name|r_type3
expr_stmt|;
name|rela
operator|.
name|r_type2
operator|=
name|rel
operator|.
name|r_type2
expr_stmt|;
name|rela
operator|.
name|r_type
operator|=
name|rel
operator|.
name|r_type
expr_stmt|;
name|rela
operator|.
name|r_addend
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Each entry represents up to three actual relocations.  */
name|used_sym
operator|=
name|false
expr_stmt|;
name|used_ssym
operator|=
name|false
expr_stmt|;
for|for
control|(
name|ir
operator|=
literal|0
init|;
name|ir
operator|<
literal|3
condition|;
name|ir
operator|++
control|)
block|{
name|enum
name|elf_mips_reloc_type
name|type
decl_stmt|;
switch|switch
condition|(
name|ir
condition|)
block|{
default|default:
name|abort
argument_list|()
expr_stmt|;
case|case
literal|0
case|:
name|type
operator|=
operator|(
expr|enum
name|elf_mips_reloc_type
operator|)
name|rela
operator|.
name|r_type
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|type
operator|=
operator|(
expr|enum
name|elf_mips_reloc_type
operator|)
name|rela
operator|.
name|r_type2
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|type
operator|=
operator|(
expr|enum
name|elf_mips_reloc_type
operator|)
name|rela
operator|.
name|r_type3
expr_stmt|;
break|break;
block|}
if|if
condition|(
name|type
operator|==
name|R_MIPS_NONE
condition|)
block|{
comment|/* There are no more relocations in this entry.  If this                  is the first entry, we need to generate a dummy                  relocation so that the generic linker knows that                  there has been a break in the sequence of relocations                  applying to a particular address.  */
if|if
condition|(
name|ir
operator|==
literal|0
condition|)
block|{
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
if|if
condition|(
operator|(
name|abfd
operator|->
name|flags
operator|&
operator|(
name|EXEC_P
operator||
name|DYNAMIC
operator|)
operator|)
operator|==
literal|0
condition|)
name|relent
operator|->
name|address
operator|=
name|rela
operator|.
name|r_offset
expr_stmt|;
else|else
name|relent
operator|->
name|address
operator|=
name|rela
operator|.
name|r_offset
operator|-
name|asect
operator|->
name|vma
expr_stmt|;
name|relent
operator|->
name|addend
operator|=
literal|0
expr_stmt|;
name|relent
operator|->
name|howto
operator|=
operator|&
name|howto_table
index|[
operator|(
name|int
operator|)
name|R_MIPS_NONE
index|]
expr_stmt|;
operator|++
name|relent
expr_stmt|;
block|}
break|break;
block|}
comment|/* Some types require symbols, whereas some do not.  */
switch|switch
condition|(
name|type
condition|)
block|{
case|case
name|R_MIPS_NONE
case|:
case|case
name|R_MIPS_LITERAL
case|:
case|case
name|R_MIPS_INSERT_A
case|:
case|case
name|R_MIPS_INSERT_B
case|:
case|case
name|R_MIPS_DELETE
case|:
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
break|break;
default|default:
if|if
condition|(
operator|!
name|used_sym
condition|)
block|{
if|if
condition|(
name|rela
operator|.
name|r_sym
operator|==
literal|0
condition|)
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
else|else
block|{
name|asymbol
modifier|*
modifier|*
name|ps
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|ps
operator|=
name|symbols
operator|+
name|rela
operator|.
name|r_sym
operator|-
literal|1
expr_stmt|;
name|s
operator|=
operator|*
name|ps
expr_stmt|;
if|if
condition|(
operator|(
name|s
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
condition|)
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|ps
expr_stmt|;
else|else
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|s
operator|->
name|section
operator|->
name|symbol_ptr_ptr
expr_stmt|;
block|}
name|used_sym
operator|=
name|true
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|used_ssym
condition|)
block|{
switch|switch
condition|(
name|rela
operator|.
name|r_ssym
condition|)
block|{
case|case
name|RSS_UNDEF
case|:
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
break|break;
case|case
name|RSS_GP
case|:
case|case
name|RSS_GP0
case|:
case|case
name|RSS_LOC
case|:
comment|/* FIXME: I think these need to be handled using                          special howto structures.  */
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
default|default:
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
break|break;
block|}
name|used_ssym
operator|=
name|true
expr_stmt|;
block|}
else|else
name|relent
operator|->
name|sym_ptr_ptr
operator|=
name|bfd_abs_section_ptr
operator|->
name|symbol_ptr_ptr
expr_stmt|;
break|break;
block|}
comment|/* The address of an ELF reloc is section relative for an 	     object file, and absolute for an executable file or 	     shared library.  The address of a BFD reloc is always 	     section relative.  */
if|if
condition|(
operator|(
name|abfd
operator|->
name|flags
operator|&
operator|(
name|EXEC_P
operator||
name|DYNAMIC
operator|)
operator|)
operator|==
literal|0
condition|)
name|relent
operator|->
name|address
operator|=
name|rela
operator|.
name|r_offset
expr_stmt|;
else|else
name|relent
operator|->
name|address
operator|=
name|rela
operator|.
name|r_offset
operator|-
name|asect
operator|->
name|vma
expr_stmt|;
name|relent
operator|->
name|addend
operator|=
name|rela
operator|.
name|r_addend
expr_stmt|;
name|relent
operator|->
name|howto
operator|=
operator|&
name|howto_table
index|[
operator|(
name|int
operator|)
name|type
index|]
expr_stmt|;
operator|++
name|relent
expr_stmt|;
block|}
block|}
name|asect
operator|->
name|reloc_count
operator|+=
name|relent
operator|-
name|relents
expr_stmt|;
if|if
condition|(
name|allocated
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocated
argument_list|)
expr_stmt|;
return|return
name|true
return|;
name|error_return
label|:
if|if
condition|(
name|allocated
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|allocated
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Read the relocations.  On Irix 6, there can be two reloc sections    associated with a single data section.  */
end_comment

begin_function
specifier|static
name|boolean
name|mips_elf64_slurp_reloc_table
parameter_list|(
name|abfd
parameter_list|,
name|asect
parameter_list|,
name|symbols
parameter_list|,
name|dynamic
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|asection
modifier|*
name|asect
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|symbols
decl_stmt|;
name|boolean
name|dynamic
decl_stmt|;
block|{
name|struct
name|bfd_elf_section_data
modifier|*
specifier|const
name|d
init|=
name|elf_section_data
argument_list|(
name|asect
argument_list|)
decl_stmt|;
if|if
condition|(
name|dynamic
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
if|if
condition|(
name|asect
operator|->
name|relocation
operator|!=
name|NULL
operator|||
operator|(
name|asect
operator|->
name|flags
operator|&
name|SEC_RELOC
operator|)
operator|==
literal|0
operator|||
name|asect
operator|->
name|reloc_count
operator|==
literal|0
condition|)
return|return
name|true
return|;
comment|/* Allocate space for 3 arelent structures for each Rel structure.  */
name|asect
operator|->
name|relocation
operator|=
operator|(
operator|(
name|arelent
operator|*
operator|)
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|asect
operator|->
name|reloc_count
operator|*
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|arelent
argument_list|)
argument_list|)
operator|)
expr_stmt|;
if|if
condition|(
name|asect
operator|->
name|relocation
operator|==
name|NULL
condition|)
return|return
name|false
return|;
comment|/* The slurp_one_reloc_table routine increments reloc_count.  */
name|asect
operator|->
name|reloc_count
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|mips_elf64_slurp_one_reloc_table
argument_list|(
name|abfd
argument_list|,
name|asect
argument_list|,
name|symbols
argument_list|,
operator|&
name|d
operator|->
name|rel_hdr
argument_list|)
condition|)
return|return
name|false
return|;
if|if
condition|(
name|d
operator|->
name|rel_hdr2
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|mips_elf64_slurp_one_reloc_table
argument_list|(
name|abfd
argument_list|,
name|asect
argument_list|,
name|symbols
argument_list|,
name|d
operator|->
name|rel_hdr2
argument_list|)
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

begin_comment
comment|/* Write out the relocations.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_write_relocs
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|,
name|data
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
block|{
name|boolean
modifier|*
name|failedp
init|=
operator|(
name|boolean
operator|*
operator|)
name|data
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|Elf_Internal_Shdr
modifier|*
name|rela_hdr
decl_stmt|;
name|Elf64_Mips_External_Rela
modifier|*
name|ext_rela
decl_stmt|;
name|unsigned
name|int
name|idx
decl_stmt|;
name|asymbol
modifier|*
name|last_sym
init|=
literal|0
decl_stmt|;
name|int
name|last_sym_idx
init|=
literal|0
decl_stmt|;
comment|/* If we have already failed, don't do anything.  */
if|if
condition|(
operator|*
name|failedp
condition|)
return|return;
if|if
condition|(
operator|(
name|sec
operator|->
name|flags
operator|&
name|SEC_RELOC
operator|)
operator|==
literal|0
condition|)
return|return;
comment|/* The linker backend writes the relocs out itself, and sets the      reloc_count field to zero to inhibit writing them here.  Also,      sometimes the SEC_RELOC flag gets set even when there aren't any      relocs.  */
if|if
condition|(
name|sec
operator|->
name|reloc_count
operator|==
literal|0
condition|)
return|return;
comment|/* We can combine up to three relocs that refer to the same address      if the latter relocs have no associated symbol.  */
name|count
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|sec
operator|->
name|reloc_count
condition|;
name|idx
operator|++
control|)
block|{
name|bfd_vma
name|addr
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
operator|++
name|count
expr_stmt|;
name|addr
operator|=
name|sec
operator|->
name|orelocation
index|[
name|idx
index|]
operator|->
name|address
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|arelent
modifier|*
name|r
decl_stmt|;
if|if
condition|(
name|idx
operator|+
literal|1
operator|>=
name|sec
operator|->
name|reloc_count
condition|)
break|break;
name|r
operator|=
name|sec
operator|->
name|orelocation
index|[
name|idx
operator|+
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|address
operator|!=
name|addr
operator|||
operator|!
name|bfd_is_abs_section
argument_list|(
operator|(
operator|*
name|r
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|section
argument_list|)
operator|||
operator|(
operator|*
name|r
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|value
operator|!=
literal|0
condition|)
break|break;
comment|/* We can merge the reloc at IDX + 1 with the reloc at IDX.  */
operator|++
name|idx
expr_stmt|;
block|}
block|}
name|rela_hdr
operator|=
operator|&
name|elf_section_data
argument_list|(
name|sec
argument_list|)
operator|->
name|rel_hdr
expr_stmt|;
name|rela_hdr
operator|->
name|sh_size
operator|=
name|rela_hdr
operator|->
name|sh_entsize
operator|*
name|count
expr_stmt|;
name|rela_hdr
operator|->
name|contents
operator|=
operator|(
name|PTR
operator|)
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|rela_hdr
operator|->
name|sh_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|rela_hdr
operator|->
name|contents
operator|==
name|NULL
condition|)
block|{
operator|*
name|failedp
operator|=
name|true
expr_stmt|;
return|return;
block|}
name|ext_rela
operator|=
operator|(
name|Elf64_Mips_External_Rela
operator|*
operator|)
name|rela_hdr
operator|->
name|contents
expr_stmt|;
for|for
control|(
name|idx
operator|=
literal|0
init|;
name|idx
operator|<
name|sec
operator|->
name|reloc_count
condition|;
name|idx
operator|++
operator|,
name|ext_rela
operator|++
control|)
block|{
name|arelent
modifier|*
name|ptr
decl_stmt|;
name|Elf64_Mips_Internal_Rela
name|int_rela
decl_stmt|;
name|asymbol
modifier|*
name|sym
decl_stmt|;
name|int
name|n
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
name|ptr
operator|=
name|sec
operator|->
name|orelocation
index|[
name|idx
index|]
expr_stmt|;
comment|/* The address of an ELF reloc is section relative for an object 	 file, and absolute for an executable file or shared library. 	 The address of a BFD reloc is always section relative.  */
if|if
condition|(
operator|(
name|abfd
operator|->
name|flags
operator|&
operator|(
name|EXEC_P
operator||
name|DYNAMIC
operator|)
operator|)
operator|==
literal|0
condition|)
name|int_rela
operator|.
name|r_offset
operator|=
name|ptr
operator|->
name|address
expr_stmt|;
else|else
name|int_rela
operator|.
name|r_offset
operator|=
name|ptr
operator|->
name|address
operator|+
name|sec
operator|->
name|vma
expr_stmt|;
name|sym
operator|=
operator|*
name|ptr
operator|->
name|sym_ptr_ptr
expr_stmt|;
if|if
condition|(
name|sym
operator|==
name|last_sym
condition|)
name|n
operator|=
name|last_sym_idx
expr_stmt|;
else|else
block|{
name|last_sym
operator|=
name|sym
expr_stmt|;
name|n
operator|=
name|_bfd_elf_symbol_from_bfd_symbol
argument_list|(
name|abfd
argument_list|,
operator|&
name|sym
argument_list|)
expr_stmt|;
if|if
condition|(
name|n
operator|<
literal|0
condition|)
block|{
operator|*
name|failedp
operator|=
name|true
expr_stmt|;
return|return;
block|}
name|last_sym_idx
operator|=
name|n
expr_stmt|;
block|}
name|int_rela
operator|.
name|r_sym
operator|=
name|n
expr_stmt|;
name|int_rela
operator|.
name|r_addend
operator|=
name|ptr
operator|->
name|addend
expr_stmt|;
name|int_rela
operator|.
name|r_ssym
operator|=
name|RSS_UNDEF
expr_stmt|;
if|if
condition|(
operator|(
operator|*
name|ptr
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|the_bfd
operator|->
name|xvec
operator|!=
name|abfd
operator|->
name|xvec
operator|&&
operator|!
name|_bfd_elf_validate_reloc
argument_list|(
name|abfd
argument_list|,
name|ptr
argument_list|)
condition|)
block|{
operator|*
name|failedp
operator|=
name|true
expr_stmt|;
return|return;
block|}
name|int_rela
operator|.
name|r_type
operator|=
name|ptr
operator|->
name|howto
operator|->
name|type
expr_stmt|;
name|int_rela
operator|.
name|r_type2
operator|=
operator|(
name|int
operator|)
name|R_MIPS_NONE
expr_stmt|;
name|int_rela
operator|.
name|r_type3
operator|=
operator|(
name|int
operator|)
name|R_MIPS_NONE
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|2
condition|;
name|i
operator|++
control|)
block|{
name|arelent
modifier|*
name|r
decl_stmt|;
if|if
condition|(
name|idx
operator|+
literal|1
operator|>=
name|sec
operator|->
name|reloc_count
condition|)
break|break;
name|r
operator|=
name|sec
operator|->
name|orelocation
index|[
name|idx
operator|+
literal|1
index|]
expr_stmt|;
if|if
condition|(
name|r
operator|->
name|address
operator|!=
name|ptr
operator|->
name|address
operator|||
operator|!
name|bfd_is_abs_section
argument_list|(
operator|(
operator|*
name|r
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|section
argument_list|)
operator|||
operator|(
operator|*
name|r
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|value
operator|!=
literal|0
condition|)
break|break;
comment|/* We can merge the reloc at IDX + 1 with the reloc at IDX.  */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|int_rela
operator|.
name|r_type2
operator|=
name|r
operator|->
name|howto
operator|->
name|type
expr_stmt|;
else|else
name|int_rela
operator|.
name|r_type3
operator|=
name|r
operator|->
name|howto
operator|->
name|type
expr_stmt|;
operator|++
name|idx
expr_stmt|;
block|}
name|mips_elf64_swap_reloca_out
argument_list|(
name|abfd
argument_list|,
operator|&
name|int_rela
argument_list|,
name|ext_rela
argument_list|)
expr_stmt|;
block|}
name|BFD_ASSERT
argument_list|(
name|ext_rela
operator|-
operator|(
name|Elf64_Mips_External_Rela
operator|*
operator|)
name|rela_hdr
operator|->
name|contents
operator|==
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Irix 6 defines a brand new archive map format, so that they can    have archives more than 4 GB in size.  */
end_comment

begin_comment
comment|/* Read an Irix 6 armap.  */
end_comment

begin_function
specifier|static
name|boolean
name|mips_elf64_slurp_armap
parameter_list|(
name|abfd
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
block|{
name|struct
name|artdata
modifier|*
name|ardata
init|=
name|bfd_ardata
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
name|char
name|nextname
index|[
literal|17
index|]
decl_stmt|;
name|file_ptr
name|arhdrpos
decl_stmt|;
name|bfd_size_type
name|i
decl_stmt|,
name|parsed_size
decl_stmt|,
name|nsymz
decl_stmt|,
name|stringsize
decl_stmt|,
name|carsym_size
decl_stmt|,
name|ptrsize
decl_stmt|;
name|struct
name|areltdata
modifier|*
name|mapdata
decl_stmt|;
name|bfd_byte
name|int_buf
index|[
literal|8
index|]
decl_stmt|;
name|char
modifier|*
name|stringbase
decl_stmt|;
name|bfd_byte
modifier|*
name|raw_armap
init|=
name|NULL
decl_stmt|;
name|carsym
modifier|*
name|carsyms
decl_stmt|;
name|ardata
operator|->
name|symdefs
operator|=
name|NULL
expr_stmt|;
comment|/* Get the name of the first element.  */
name|arhdrpos
operator|=
name|bfd_tell
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|i
operator|=
name|bfd_read
argument_list|(
operator|(
name|PTR
operator|)
name|nextname
argument_list|,
literal|1
argument_list|,
literal|16
argument_list|,
name|abfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
name|true
return|;
if|if
condition|(
name|i
operator|!=
literal|16
condition|)
return|return
name|false
return|;
if|if
condition|(
name|bfd_seek
argument_list|(
name|abfd
argument_list|,
operator|(
name|file_ptr
operator|)
operator|-
literal|16
argument_list|,
name|SEEK_CUR
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|false
return|;
comment|/* Archives with traditional armaps are still permitted.  */
if|if
condition|(
name|strncmp
argument_list|(
name|nextname
argument_list|,
literal|"/               "
argument_list|,
literal|16
argument_list|)
operator|==
literal|0
condition|)
return|return
name|bfd_slurp_armap
argument_list|(
name|abfd
argument_list|)
return|;
if|if
condition|(
name|strncmp
argument_list|(
name|nextname
argument_list|,
literal|"/SYM64/         "
argument_list|,
literal|16
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|bfd_has_map
argument_list|(
name|abfd
argument_list|)
operator|=
name|false
expr_stmt|;
return|return
name|true
return|;
block|}
name|mapdata
operator|=
operator|(
expr|struct
name|areltdata
operator|*
operator|)
name|_bfd_read_ar_hdr
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
if|if
condition|(
name|mapdata
operator|==
name|NULL
condition|)
return|return
name|false
return|;
name|parsed_size
operator|=
name|mapdata
operator|->
name|parsed_size
expr_stmt|;
name|bfd_release
argument_list|(
name|abfd
argument_list|,
operator|(
name|PTR
operator|)
name|mapdata
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_read
argument_list|(
name|int_buf
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
name|abfd
argument_list|)
operator|!=
literal|8
condition|)
block|{
if|if
condition|(
name|bfd_get_error
argument_list|()
operator|!=
name|bfd_error_system_call
condition|)
name|bfd_set_error
argument_list|(
name|bfd_error_malformed_archive
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
name|nsymz
operator|=
name|bfd_getb64
argument_list|(
name|int_buf
argument_list|)
expr_stmt|;
name|stringsize
operator|=
name|parsed_size
operator|-
literal|8
operator|*
name|nsymz
operator|-
literal|8
expr_stmt|;
name|carsym_size
operator|=
name|nsymz
operator|*
sizeof|sizeof
argument_list|(
name|carsym
argument_list|)
expr_stmt|;
name|ptrsize
operator|=
literal|8
operator|*
name|nsymz
expr_stmt|;
name|ardata
operator|->
name|symdefs
operator|=
operator|(
name|carsym
operator|*
operator|)
name|bfd_zalloc
argument_list|(
name|abfd
argument_list|,
name|carsym_size
operator|+
name|stringsize
operator|+
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|ardata
operator|->
name|symdefs
operator|==
name|NULL
condition|)
return|return
name|false
return|;
name|carsyms
operator|=
name|ardata
operator|->
name|symdefs
expr_stmt|;
name|stringbase
operator|=
operator|(
operator|(
name|char
operator|*
operator|)
name|ardata
operator|->
name|symdefs
operator|)
operator|+
name|carsym_size
expr_stmt|;
name|raw_armap
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|ptrsize
argument_list|)
expr_stmt|;
if|if
condition|(
name|raw_armap
operator|==
name|NULL
condition|)
goto|goto
name|error_return
goto|;
if|if
condition|(
name|bfd_read
argument_list|(
name|raw_armap
argument_list|,
literal|1
argument_list|,
name|ptrsize
argument_list|,
name|abfd
argument_list|)
operator|!=
name|ptrsize
operator|||
name|bfd_read
argument_list|(
name|stringbase
argument_list|,
literal|1
argument_list|,
name|stringsize
argument_list|,
name|abfd
argument_list|)
operator|!=
name|stringsize
condition|)
block|{
if|if
condition|(
name|bfd_get_error
argument_list|()
operator|!=
name|bfd_error_system_call
condition|)
name|bfd_set_error
argument_list|(
name|bfd_error_malformed_archive
argument_list|)
expr_stmt|;
goto|goto
name|error_return
goto|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nsymz
condition|;
name|i
operator|++
control|)
block|{
name|carsyms
operator|->
name|file_offset
operator|=
name|bfd_getb64
argument_list|(
name|raw_armap
operator|+
name|i
operator|*
literal|8
argument_list|)
expr_stmt|;
name|carsyms
operator|->
name|name
operator|=
name|stringbase
expr_stmt|;
name|stringbase
operator|+=
name|strlen
argument_list|(
name|stringbase
argument_list|)
operator|+
literal|1
expr_stmt|;
operator|++
name|carsyms
expr_stmt|;
block|}
operator|*
name|stringbase
operator|=
literal|'\0'
expr_stmt|;
name|ardata
operator|->
name|symdef_count
operator|=
name|nsymz
expr_stmt|;
name|ardata
operator|->
name|first_file_filepos
operator|=
name|arhdrpos
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
operator|+
name|parsed_size
expr_stmt|;
name|bfd_has_map
argument_list|(
name|abfd
argument_list|)
operator|=
name|true
expr_stmt|;
name|bfd_release
argument_list|(
name|abfd
argument_list|,
name|raw_armap
argument_list|)
expr_stmt|;
return|return
name|true
return|;
name|error_return
label|:
if|if
condition|(
name|raw_armap
operator|!=
name|NULL
condition|)
name|bfd_release
argument_list|(
name|abfd
argument_list|,
name|raw_armap
argument_list|)
expr_stmt|;
if|if
condition|(
name|ardata
operator|->
name|symdefs
operator|!=
name|NULL
condition|)
name|bfd_release
argument_list|(
name|abfd
argument_list|,
name|ardata
operator|->
name|symdefs
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Write out an Irix 6 armap.  The Irix 6 tools are supposed to be    able to handle ordinary ELF armaps, but at least on Irix 6.2 the    linker crashes.  */
end_comment

begin_function
specifier|static
name|boolean
name|mips_elf64_write_armap
parameter_list|(
name|arch
parameter_list|,
name|elength
parameter_list|,
name|map
parameter_list|,
name|symbol_count
parameter_list|,
name|stridx
parameter_list|)
name|bfd
modifier|*
name|arch
decl_stmt|;
name|unsigned
name|int
name|elength
decl_stmt|;
name|struct
name|orl
modifier|*
name|map
decl_stmt|;
name|unsigned
name|int
name|symbol_count
decl_stmt|;
name|int
name|stridx
decl_stmt|;
block|{
name|unsigned
name|int
name|ranlibsize
init|=
operator|(
name|symbol_count
operator|*
literal|8
operator|)
operator|+
literal|8
decl_stmt|;
name|unsigned
name|int
name|stringsize
init|=
name|stridx
decl_stmt|;
name|unsigned
name|int
name|mapsize
init|=
name|stringsize
operator|+
name|ranlibsize
decl_stmt|;
name|file_ptr
name|archive_member_file_ptr
decl_stmt|;
name|bfd
modifier|*
name|current
init|=
name|arch
operator|->
name|archive_head
decl_stmt|;
name|unsigned
name|int
name|count
decl_stmt|;
name|struct
name|ar_hdr
name|hdr
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
name|int
name|padding
decl_stmt|;
name|bfd_byte
name|buf
index|[
literal|8
index|]
decl_stmt|;
name|padding
operator|=
name|BFD_ALIGN
argument_list|(
name|mapsize
argument_list|,
literal|8
argument_list|)
operator|-
name|mapsize
expr_stmt|;
name|mapsize
operator|+=
name|padding
expr_stmt|;
comment|/* work out where the first object file will go in the archive */
name|archive_member_file_ptr
operator|=
operator|(
name|mapsize
operator|+
name|elength
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
operator|+
name|SARMAG
operator|)
expr_stmt|;
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|hdr
operator|)
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|hdr
operator|.
name|ar_name
argument_list|,
literal|"/SYM64/"
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|hdr
operator|.
name|ar_size
argument_list|,
literal|"%-10d"
argument_list|,
operator|(
name|int
operator|)
name|mapsize
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|hdr
operator|.
name|ar_date
argument_list|,
literal|"%ld"
argument_list|,
operator|(
name|long
operator|)
name|time
argument_list|(
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
comment|/* This, at least, is what Intel coff sets the values to.: */
name|sprintf
argument_list|(
operator|(
name|hdr
operator|.
name|ar_uid
operator|)
argument_list|,
literal|"%d"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
operator|(
name|hdr
operator|.
name|ar_gid
operator|)
argument_list|,
literal|"%d"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
operator|(
name|hdr
operator|.
name|ar_mode
operator|)
argument_list|,
literal|"%-7o"
argument_list|,
operator|(
name|unsigned
operator|)
literal|0
argument_list|)
expr_stmt|;
name|strncpy
argument_list|(
name|hdr
operator|.
name|ar_fmag
argument_list|,
name|ARFMAG
argument_list|,
literal|2
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
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|hdr
operator|)
operator|)
index|[
name|i
index|]
operator|==
literal|'\0'
condition|)
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
operator|&
name|hdr
operator|)
operator|)
index|[
name|i
index|]
operator|)
operator|=
literal|' '
expr_stmt|;
comment|/* Write the ar header for this item and the number of symbols */
if|if
condition|(
name|bfd_write
argument_list|(
operator|(
name|PTR
operator|)
operator|&
name|hdr
argument_list|,
literal|1
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
argument_list|,
name|arch
argument_list|)
operator|!=
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
condition|)
return|return
name|false
return|;
name|bfd_putb64
argument_list|(
name|symbol_count
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
name|buf
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
name|arch
argument_list|)
operator|!=
literal|8
condition|)
return|return
name|false
return|;
comment|/* Two passes, first write the file offsets for each symbol -      remembering that each offset is on a two byte boundary.  */
comment|/* Write out the file offset for the file associated with each      symbol, and remember to keep the offsets padded out.  */
name|current
operator|=
name|arch
operator|->
name|archive_head
expr_stmt|;
name|count
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|current
operator|!=
operator|(
name|bfd
operator|*
operator|)
name|NULL
operator|&&
name|count
operator|<
name|symbol_count
condition|)
block|{
comment|/* For each symbol which is used defined in this object, write out 	 the object file's address in the archive */
while|while
condition|(
operator|(
operator|(
name|bfd
operator|*
operator|)
operator|(
name|map
index|[
name|count
index|]
operator|)
operator|.
name|pos
operator|)
operator|==
name|current
condition|)
block|{
name|bfd_putb64
argument_list|(
name|archive_member_file_ptr
argument_list|,
name|buf
argument_list|)
expr_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
name|buf
argument_list|,
literal|1
argument_list|,
literal|8
argument_list|,
name|arch
argument_list|)
operator|!=
literal|8
condition|)
return|return
name|false
return|;
name|count
operator|++
expr_stmt|;
block|}
comment|/* Add size of this archive entry */
name|archive_member_file_ptr
operator|+=
operator|(
name|arelt_size
argument_list|(
name|current
argument_list|)
operator|+
sizeof|sizeof
argument_list|(
expr|struct
name|ar_hdr
argument_list|)
operator|)
expr_stmt|;
comment|/* remember about the even alignment */
name|archive_member_file_ptr
operator|+=
name|archive_member_file_ptr
operator|%
literal|2
expr_stmt|;
name|current
operator|=
name|current
operator|->
name|next
expr_stmt|;
block|}
comment|/* now write the strings themselves */
for|for
control|(
name|count
operator|=
literal|0
init|;
name|count
operator|<
name|symbol_count
condition|;
name|count
operator|++
control|)
block|{
name|size_t
name|len
init|=
name|strlen
argument_list|(
operator|*
name|map
index|[
name|count
index|]
operator|.
name|name
argument_list|)
operator|+
literal|1
decl_stmt|;
if|if
condition|(
name|bfd_write
argument_list|(
operator|*
name|map
index|[
name|count
index|]
operator|.
name|name
argument_list|,
literal|1
argument_list|,
name|len
argument_list|,
name|arch
argument_list|)
operator|!=
name|len
condition|)
return|return
name|false
return|;
block|}
comment|/* The spec says that this should be padded to an 8 byte boundary.      However, the Irix 6.2 tools do not appear to do this.  */
while|while
condition|(
name|padding
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|bfd_write
argument_list|(
literal|""
argument_list|,
literal|1
argument_list|,
literal|1
argument_list|,
name|arch
argument_list|)
operator|!=
literal|1
condition|)
return|return
name|false
return|;
operator|--
name|padding
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* ECOFF swapping routines.  These are used when dealing with the    .mdebug section, which is in the ECOFF debugging format.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ecoff_debug_swap
name|mips_elf64_ecoff_debug_swap
init|=
block|{
comment|/* Symbol table magic number.  */
name|magicSym2
block|,
comment|/* Alignment of debugging information.  E.g., 4.  */
literal|8
block|,
comment|/* Sizes of external symbolic information.  */
sizeof|sizeof
argument_list|(
expr|struct
name|hdr_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|dnr_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|pdr_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|sym_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|opt_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|fdr_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|rfd_ext
argument_list|)
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|ext_ext
argument_list|)
block|,
comment|/* Functions to swap in external symbolic data.  */
name|ecoff_swap_hdr_in
block|,
name|ecoff_swap_dnr_in
block|,
name|ecoff_swap_pdr_in
block|,
name|ecoff_swap_sym_in
block|,
name|ecoff_swap_opt_in
block|,
name|ecoff_swap_fdr_in
block|,
name|ecoff_swap_rfd_in
block|,
name|ecoff_swap_ext_in
block|,
name|_bfd_ecoff_swap_tir_in
block|,
name|_bfd_ecoff_swap_rndx_in
block|,
comment|/* Functions to swap out external symbolic data.  */
name|ecoff_swap_hdr_out
block|,
name|ecoff_swap_dnr_out
block|,
name|ecoff_swap_pdr_out
block|,
name|ecoff_swap_sym_out
block|,
name|ecoff_swap_opt_out
block|,
name|ecoff_swap_fdr_out
block|,
name|ecoff_swap_rfd_out
block|,
name|ecoff_swap_ext_out
block|,
name|_bfd_ecoff_swap_tir_out
block|,
name|_bfd_ecoff_swap_rndx_out
block|,
comment|/* Function to read in symbolic data.  */
name|_bfd_mips_elf_read_ecoff_info
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Relocations in the 64 bit MIPS ELF ABI are more complex than in    standard ELF.  This structure is used to redirect the relocation    handling routines.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|elf_size_info
name|mips_elf64_size_info
init|=
block|{
sizeof|sizeof
argument_list|(
name|Elf64_External_Ehdr
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_External_Phdr
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_External_Shdr
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rel
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rela
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_External_Sym
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf64_External_Dyn
argument_list|)
block|,
sizeof|sizeof
argument_list|(
name|Elf_External_Note
argument_list|)
block|,
literal|4
block|,
comment|/* hash-table entry size */
literal|3
block|,
comment|/* internal relocations per external relocations */
literal|64
block|,
comment|/* arch_size */
literal|8
block|,
comment|/* file_align */
name|ELFCLASS64
block|,
name|EV_CURRENT
block|,
name|bfd_elf64_write_out_phdrs
block|,
name|bfd_elf64_write_shdrs_and_ehdr
block|,
name|mips_elf64_write_relocs
block|,
name|bfd_elf64_swap_symbol_out
block|,
name|mips_elf64_slurp_reloc_table
block|,
name|bfd_elf64_slurp_symbol_table
block|,
name|bfd_elf64_swap_dyn_in
block|,
name|bfd_elf64_swap_dyn_out
block|,
name|mips_elf64_be_swap_reloc_in
block|,
name|mips_elf64_be_swap_reloc_out
block|,
name|mips_elf64_be_swap_reloca_in
block|,
name|mips_elf64_be_swap_reloca_out
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf64_littlemips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf64-littlemips"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf64_bigmips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf64-bigmips"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_mips
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_MIPS
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
name|elf_backend_collect
value|true
end_define

begin_define
define|#
directive|define
name|elf_backend_type_change_ok
value|true
end_define

begin_define
define|#
directive|define
name|elf_backend_can_gc_sections
value|true
end_define

begin_define
define|#
directive|define
name|elf_backend_size_info
value|mips_elf64_size_info
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|_bfd_mips_elf_object_p
end_define

begin_define
define|#
directive|define
name|elf_backend_section_from_shdr
value|_bfd_mips_elf_section_from_shdr
end_define

begin_define
define|#
directive|define
name|elf_backend_fake_sections
value|_bfd_mips_elf_fake_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_section_from_bfd_section
define|\
value|_bfd_mips_elf_section_from_bfd_section
end_define

begin_define
define|#
directive|define
name|elf_backend_section_processing
value|_bfd_mips_elf_section_processing
end_define

begin_define
define|#
directive|define
name|elf_backend_symbol_processing
value|_bfd_mips_elf_symbol_processing
end_define

begin_define
define|#
directive|define
name|elf_backend_additional_program_headers
define|\
value|_bfd_mips_elf_additional_program_headers
end_define

begin_define
define|#
directive|define
name|elf_backend_modify_segment_map
value|_bfd_mips_elf_modify_segment_map
end_define

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
define|\
value|_bfd_mips_elf_final_write_processing
end_define

begin_define
define|#
directive|define
name|elf_backend_ecoff_debug_swap
value|&mips_elf64_ecoff_debug_swap
end_define

begin_define
define|#
directive|define
name|elf_backend_add_symbol_hook
value|_bfd_mips_elf_add_symbol_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_create_dynamic_sections
define|\
value|_bfd_mips_elf_create_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_check_relocs
value|_bfd_mips_elf_check_relocs
end_define

begin_define
define|#
directive|define
name|elf_backend_adjust_dynamic_symbol
define|\
value|_bfd_mips_elf_adjust_dynamic_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_always_size_sections
define|\
value|_bfd_mips_elf_always_size_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_size_dynamic_sections
define|\
value|_bfd_mips_elf_size_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|_bfd_mips_elf_relocate_section
end_define

begin_define
define|#
directive|define
name|elf_backend_link_output_symbol_hook
define|\
value|_bfd_mips_elf_link_output_symbol_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_symbol
define|\
value|_bfd_mips_elf_finish_dynamic_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_sections
define|\
value|_bfd_mips_elf_finish_dynamic_sections
end_define

begin_define
define|#
directive|define
name|elf_backend_gc_mark_hook
value|_bfd_mips_elf_gc_mark_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_gc_sweep_hook
value|_bfd_mips_elf_gc_sweep_hook
end_define

begin_define
define|#
directive|define
name|elf_backend_got_header_size
value|(4*MIPS_RESERVED_GOTNO)
end_define

begin_define
define|#
directive|define
name|elf_backend_plt_header_size
value|0
end_define

begin_define
define|#
directive|define
name|elf_backend_may_use_rel_p
value|1
end_define

begin_comment
comment|/* We don't set bfd_elf64_bfd_is_local_label_name because the 32-bit     MIPS-specific function only applies to IRIX5, which had no 64-bit    ABI.  */
end_comment

begin_define
define|#
directive|define
name|bfd_elf64_find_nearest_line
value|_bfd_mips_elf_find_nearest_line
end_define

begin_define
define|#
directive|define
name|bfd_elf64_set_section_contents
value|_bfd_mips_elf_set_section_contents
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_link_hash_table_create
define|\
value|_bfd_mips_elf_link_hash_table_create
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_final_link
value|_bfd_mips_elf_final_link
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_copy_private_bfd_data
define|\
value|_bfd_mips_elf_copy_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_merge_private_bfd_data
define|\
value|_bfd_mips_elf_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_set_private_flags
value|_bfd_mips_elf_set_private_flags
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_print_private_bfd_data
define|\
value|_bfd_mips_elf_print_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf64_get_reloc_upper_bound
value|mips_elf64_get_reloc_upper_bound
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_reloc_type_lookup
value|mips_elf64_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_functions
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_slurp_armap
value|mips_elf64_slurp_armap
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_slurp_extended_name_table
define|\
value|_bfd_archive_coff_slurp_extended_name_table
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_construct_extended_name_table
define|\
value|_bfd_archive_coff_construct_extended_name_table
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_truncate_arname
define|\
value|_bfd_archive_coff_truncate_arname
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_write_armap
value|mips_elf64_write_armap
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_read_ar_hdr
value|_bfd_archive_coff_read_ar_hdr
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_openr_next_archived_file
define|\
value|_bfd_archive_coff_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_get_elt_at_index
define|\
value|_bfd_archive_coff_get_elt_at_index
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_generic_stat_arch_elt
define|\
value|_bfd_archive_coff_generic_stat_arch_elt
end_define

begin_define
define|#
directive|define
name|bfd_elf64_archive_update_armap_timestamp
define|\
value|_bfd_archive_coff_update_armap_timestamp
end_define

begin_include
include|#
directive|include
file|"elf64-target.h"
end_include

end_unit

