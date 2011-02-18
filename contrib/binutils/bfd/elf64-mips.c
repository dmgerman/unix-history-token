begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MIPS-specific support for 64-bit ELF    Copyright 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005,    2007 Free Software Foundation, Inc.    Ian Lance Taylor, Cygnus Support    Linker support added by Mark Mitchell, CodeSourcery, LLC.<mark@codesourcery.com>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file supports the 64-bit MIPS ELF ABI.     The MIPS 64-bit ELF ABI uses an unusual reloc format.  This file    overrides the usual ELF reloc handling, and handles reading and    writing the relocations here.  */
end_comment

begin_comment
comment|/* TODO: Many things are unsupported, even if there is some code for it  .       (which was mostly stolen from elf32-mips.c and slightly adapted).  .  .   - Relocation handling for REL relocs is wrong in many cases and  .     generally untested.  .   - Relocation handling for RELA relocs related to GOT support are  .     also likely to be wrong.  .   - Support for MIPS16 is untested.  .   - Combined relocs with RSS_* entries are unsupported.  .   - The whole GOT handling for NewABI is missing, some parts of  .     the OldABI version is still lying around and should be removed.  */
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
file|"elfxx-mips.h"
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
name|ECOFF_SIGNED_64
end_define

begin_include
include|#
directive|include
file|"ecoffswap.h"
end_include

begin_function_decl
specifier|static
name|void
name|mips_elf64_swap_reloc_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf64_Mips_External_Rel
modifier|*
parameter_list|,
name|Elf64_Mips_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_swap_reloca_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf64_Mips_External_Rela
modifier|*
parameter_list|,
name|Elf64_Mips_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_swap_reloc_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf64_Mips_Internal_Rela
modifier|*
parameter_list|,
name|Elf64_Mips_External_Rel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_swap_reloca_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf64_Mips_Internal_Rela
modifier|*
parameter_list|,
name|Elf64_Mips_External_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_be_swap_reloc_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|bfd_byte
modifier|*
parameter_list|,
name|Elf_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_be_swap_reloc_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf_Internal_Rela
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_be_swap_reloca_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|bfd_byte
modifier|*
parameter_list|,
name|Elf_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_be_swap_reloca_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|Elf_Internal_Rela
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf64_bfd_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_reloc_code_real_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|reloc_howto_type
modifier|*
name|mips_elf64_rtype_to_howto
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_info_to_howto_rel
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|Elf_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_info_to_howto_rela
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|Elf_Internal_Rela
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|long
name|mips_elf64_get_reloc_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|long
name|mips_elf64_canonicalize_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|arelent
modifier|*
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|long
name|mips_elf64_get_dynamic_reloc_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|long
name|mips_elf64_canonicalize_dynamic_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf64_slurp_one_reloc_table
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
parameter_list|,
name|bfd_size_type
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf64_slurp_reloc_table
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_write_relocs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_write_rel
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|mips_elf64_write_rela
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_gprel16_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_literal_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_gprel32_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_shift6_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips16_gprel_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf64_assign_gp
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_final_gp
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|bfd_vma
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf64_object_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|irix_compat_t
name|elf64_mips_irix_compat
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|elf64_mips_grok_prstatus
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|Elf_Internal_Note
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|elf64_mips_grok_psinfo
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|Elf_Internal_Note
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|bfd_elf64_bigmips_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|bfd_elf64_littlemips_vec
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

begin_escape
end_escape

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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_NONE"
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
name|FALSE
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_16"
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
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_32"
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL32"
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
comment|/* 26 bit jump address.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper 36 				   bits must match the PC + 4.  */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_26"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x03ffffff
argument_list|,
comment|/* src_mask */
literal|0x03ffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* R_MIPS_HI16 and R_MIPS_LO16 are unsupported for NewABI REL.      However, the native IRIX6 tools use them, so we try our best. */
comment|/* High 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS_HI16
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
name|_bfd_mips_elf_hi16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HI16"
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
name|FALSE
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
name|FALSE
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
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL16"
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
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_literal_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LITERAL"
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
name|FALSE
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
name|FALSE
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
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative reference.  Note that the ABI document has a typo      and claims R_MIPS_PC16 to be not rightshifted, rendering it useless.      We do the right thing here.  */
name|HOWTO
argument_list|(
name|R_MIPS_PC16
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PC16"
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
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit call through global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL16"
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
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_gprel32_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL32"
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
literal|13
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|14
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|15
argument_list|)
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT5"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x000007c0
argument_list|,
comment|/* src_mask */
literal|0x000007c0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 6 bit shift field.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_shift6_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT6"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x000007c4
argument_list|,
comment|/* src_mask */
literal|0x000007c4
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_64"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_DISP"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement to page pointer in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_PAGE"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Offset from page pointer in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_OFST"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 64 bit subtraction.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SUB"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_A"
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_B"
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_DELETE"
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
comment|/* The MIPS ELF64 ABI Draft wants us to support these for REL relocations.      We don't, because        a) It means building the addend from a R_MIPS_HIGHEST/R_MIPS_HIGHER/ 	  R_MIPS_HI16/R_MIPS_LO16 sequence with varying ordering, using 	  fallable heuristics.        b) No other NewABI toolchain actually emits such relocations.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_HIGHER
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_HIGHEST
argument_list|)
block|,
comment|/* High 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Section displacement, used by an associated event location section.  */
name|HOWTO
argument_list|(
name|R_MIPS_SCN_DISP
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SCN_DISP"
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
name|R_MIPS_REL16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL16"
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
comment|/* These two are obsolete.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_ADD_IMMEDIATE
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_PJUMP
argument_list|)
block|,
comment|/* Similiar to R_MIPS_REL32, but used for relocations in a GOT section.      It must be used for multigot GOT's (and only there).  */
name|HOWTO
argument_list|(
name|R_MIPS_RELGOT
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_RELGOT"
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
comment|/* Protected jump conversion.  This is an optimization hint.  No      relocation is required for correctness.  */
name|HOWTO
argument_list|(
name|R_MIPS_JALR
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_JALR"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x00000000
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS relocations.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPMOD32
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL32
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPMOD64
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPMOD64"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL64
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL64"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS general dynamic variable reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_GD
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_GD"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic variable reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_LDM
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_LDM"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL_HI16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL_LO16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_GOTTPREL
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_GOTTPREL"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS IE dynamic relocations.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL32
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL64
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_TPREL64"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL_HI16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_TPREL_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL_LO16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_TPREL_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit relocation with no addend.  */
name|HOWTO
argument_list|(
name|R_MIPS_GLOB_DAT
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GLOB_DAT"
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
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_NONE"
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
name|FALSE
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 26 bit jump address.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper 36 				   bits must match the PC + 4.  */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_26"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x03ffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LO16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_gprel16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_literal_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_LITERAL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit PC relative reference.  Note that the ABI document has a typo      and claims R_MIPS_PC16 to be not rightshifted, rendering it useless.      We do the right thing here.  */
name|HOWTO
argument_list|(
name|R_MIPS_PC16
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PC16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 16 bit call through global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_gprel32_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GPREL32"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
literal|13
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|14
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
literal|15
argument_list|)
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT5"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x000007c0
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A 6 bit shift field.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|6
argument_list|,
comment|/* bitpos */
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|mips_elf64_shift6_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SHIFT6"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x000007c4
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_64"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_DISP"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Displacement to page pointer in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_PAGE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Offset from page pointer in the global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_OFST"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GOT_LO16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 64 bit subtraction.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SUB"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_A"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_INSERT_B"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_DELETE"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Get the higher value of a 64 bit addend.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHER"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Get the highest value of a 64 bit addend.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_HIGHEST"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* High 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Low 16 bits of displacement in global offset table.  */
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_CALL_LO16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Section displacement, used by an associated event location section.  */
name|HOWTO
argument_list|(
name|R_MIPS_SCN_DISP
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_SCN_DISP"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
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
name|R_MIPS_REL16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_REL16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* These two are obsolete.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_ADD_IMMEDIATE
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_PJUMP
argument_list|)
block|,
comment|/* Similiar to R_MIPS_REL32, but used for relocations in a GOT section.      It must be used for multigot GOT's (and only there).  */
name|HOWTO
argument_list|(
name|R_MIPS_RELGOT
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_RELGOT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0xffffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* Protected jump conversion.  This is an optimization hint.  No      relocation is required for correctness.  */
name|HOWTO
argument_list|(
name|R_MIPS_JALR
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_JALR"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x00000000
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS relocations.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPMOD32
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL32
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPMOD64
argument_list|)
block|,
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL64
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL64"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
name|MINUS_ONE
argument_list|,
comment|/* src_mask */
name|MINUS_ONE
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS general dynamic variable reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_GD
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_GD"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic variable reference.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_LDM
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_LDM"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL_HI16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS local dynamic offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL_LO16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_DTPREL_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_GOTTPREL
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_GOTTPREL"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL32
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL64
argument_list|)
block|,
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL_HI16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_TPREL_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS thread pointer offset.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL_LO16
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_TLS_TPREL_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit relocation with no addend.  */
name|HOWTO
argument_list|(
name|R_MIPS_GLOB_DAT
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GLOB_DAT"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips16_elf64_howto_table_rel
index|[]
init|=
block|{
comment|/* The reloc used for the mips16 jump instruction.  */
name|HOWTO
argument_list|(
name|R_MIPS16_26
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper four 				   bits must match the PC.  */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_26"
argument_list|,
comment|/* name */
name|TRUE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffffff
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The reloc used for the mips16 gprel instruction.  */
name|HOWTO
argument_list|(
name|R_MIPS16_GPREL
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips16_gprel_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_GPREL"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A placeholder for MIPS16 reference to global offset table.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS16_GOT16
argument_list|)
block|,
comment|/* A placeholder for MIPS16 16 bit call through global offset table.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS16_CALL16
argument_list|)
block|,
comment|/* MIPS16 high 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS16_HI16
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
name|_bfd_mips_elf_hi16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_HI16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* MIPS16 low 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS16_LO16
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
name|_bfd_mips_elf_lo16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_LO16"
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
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips16_elf64_howto_table_rela
index|[]
init|=
block|{
comment|/* The reloc used for the mips16 jump instruction.  */
name|HOWTO
argument_list|(
name|R_MIPS16_26
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
name|FALSE
argument_list|,
comment|/* pc_relative */
literal|0
argument_list|,
comment|/* bitpos */
name|complain_overflow_dont
argument_list|,
comment|/* complain_on_overflow */
comment|/* This needs complex overflow 				   detection, because the upper four 				   bits must match the PC.  */
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_26"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x3ffffff
argument_list|,
comment|/* src_mask */
literal|0x3ffffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* The reloc used for the mips16 gprel instruction.  */
name|HOWTO
argument_list|(
name|R_MIPS16_GPREL
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|mips16_gprel_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_GPREL"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* A placeholder for MIPS16 reference to global offset table.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS16_GOT16
argument_list|)
block|,
comment|/* A placeholder for MIPS16 16 bit call through global offset table.  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS16_CALL16
argument_list|)
block|,
comment|/* MIPS16 high 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS16_HI16
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
name|_bfd_mips_elf_hi16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_HI16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* MIPS16 low 16 bits of symbol value.  */
name|HOWTO
argument_list|(
name|R_MIPS16_LO16
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
name|_bfd_mips_elf_lo16_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS16_LO16"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0000ffff
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GNU extension to record C++ vtable hierarchy */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_gnu_vtinherit_howto
init|=
name|HOWTO
argument_list|(
name|R_MIPS_GNU_VTINHERIT
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
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
comment|/* complain_on_overflow */
name|NULL
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GNU_VTINHERIT"
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
name|FALSE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* GNU extension to record C++ vtable member usage */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_gnu_vtentry_howto
init|=
name|HOWTO
argument_list|(
name|R_MIPS_GNU_VTENTRY
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
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
comment|/* complain_on_overflow */
name|_bfd_elf_rel_vtable_reloc_fn
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GNU_VTENTRY"
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
name|FALSE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_escape
end_escape

begin_comment
comment|/* 16 bit offset for pc-relative branches.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_gnu_rel16_s2
init|=
name|HOWTO
argument_list|(
name|R_MIPS_GNU_REL16_S2
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GNU_REL16_S2"
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
name|TRUE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* 16 bit offset for pc-relative branches.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_gnu_rela16_s2
init|=
name|HOWTO
argument_list|(
name|R_MIPS_GNU_REL16_S2
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_GNU_REL16_S2"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0
argument_list|,
comment|/* src_mask */
literal|0x0000ffff
argument_list|,
comment|/* dst_mask */
name|TRUE
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Swap in a MIPS 64-bit Rel reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_swap_reloc_in
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf64_Mips_External_Rel
modifier|*
name|src
parameter_list|,
name|Elf64_Mips_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|dst
operator|->
name|r_offset
operator|=
name|H_GET_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_sym
operator|=
name|H_GET_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_ssym
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type3
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type2
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_addend
operator|=
literal|0
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf64_Mips_External_Rela
modifier|*
name|src
parameter_list|,
name|Elf64_Mips_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|dst
operator|->
name|r_offset
operator|=
name|H_GET_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_sym
operator|=
name|H_GET_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_ssym
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type3
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type2
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_type
operator|=
name|H_GET_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|dst
operator|->
name|r_addend
operator|=
name|H_GET_S64
argument_list|(
name|abfd
argument_list|,
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf64_Mips_Internal_Rela
modifier|*
name|src
parameter_list|,
name|Elf64_Mips_External_Rel
modifier|*
name|dst
parameter_list|)
block|{
name|H_PUT_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|,
name|dst
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|H_PUT_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|,
name|dst
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|,
name|dst
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|,
name|dst
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|,
name|dst
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|,
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf64_Mips_Internal_Rela
modifier|*
name|src
parameter_list|,
name|Elf64_Mips_External_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|H_PUT_64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_offset
argument_list|,
name|dst
operator|->
name|r_offset
argument_list|)
expr_stmt|;
name|H_PUT_32
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_sym
argument_list|,
name|dst
operator|->
name|r_sym
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_ssym
argument_list|,
name|dst
operator|->
name|r_ssym
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type3
argument_list|,
name|dst
operator|->
name|r_type3
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type2
argument_list|,
name|dst
operator|->
name|r_type2
argument_list|)
expr_stmt|;
name|H_PUT_8
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_type
argument_list|,
name|dst
operator|->
name|r_type
argument_list|)
expr_stmt|;
name|H_PUT_S64
argument_list|(
name|abfd
argument_list|,
name|src
operator|->
name|r_addend
argument_list|,
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|bfd_byte
modifier|*
name|src
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|Elf64_Mips_Internal_Rela
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
name|ELF64_R_INFO
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
literal|0
index|]
operator|.
name|r_addend
operator|=
literal|0
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
name|ELF64_R_INFO
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
name|ELF64_R_INFO
argument_list|(
name|STN_UNDEF
argument_list|,
name|mirel
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
comment|/* Swap in a MIPS 64-bit Rela reloc.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_be_swap_reloca_in
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|bfd_byte
modifier|*
name|src
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
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
name|ELF64_R_INFO
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
name|ELF64_R_INFO
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
name|ELF64_R_INFO
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf_Internal_Rela
modifier|*
name|src
parameter_list|,
name|bfd_byte
modifier|*
name|dst
parameter_list|)
block|{
name|Elf64_Mips_Internal_Rela
name|mirel
decl_stmt|;
name|mirel
operator|.
name|r_offset
operator|=
name|src
index|[
literal|0
index|]
operator|.
name|r_offset
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_offset
operator|==
name|src
index|[
literal|1
index|]
operator|.
name|r_offset
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_type
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_sym
operator|=
name|ELF64_R_SYM
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_type2
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|1
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_ssym
operator|=
name|ELF64_MIPS_R_SSYM
argument_list|(
name|src
index|[
literal|1
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirel
operator|.
name|r_type3
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|2
index|]
operator|.
name|r_info
argument_list|)
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
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|Elf_Internal_Rela
modifier|*
name|src
parameter_list|,
name|bfd_byte
modifier|*
name|dst
parameter_list|)
block|{
name|Elf64_Mips_Internal_Rela
name|mirela
decl_stmt|;
name|mirela
operator|.
name|r_offset
operator|=
name|src
index|[
literal|0
index|]
operator|.
name|r_offset
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_offset
operator|==
name|src
index|[
literal|1
index|]
operator|.
name|r_offset
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_offset
operator|==
name|src
index|[
literal|2
index|]
operator|.
name|r_offset
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_type
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_sym
operator|=
name|ELF64_R_SYM
argument_list|(
name|src
index|[
literal|0
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_addend
operator|=
name|src
index|[
literal|0
index|]
operator|.
name|r_addend
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|src
index|[
literal|1
index|]
operator|.
name|r_addend
operator|==
literal|0
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|src
index|[
literal|2
index|]
operator|.
name|r_addend
operator|==
literal|0
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_type2
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|1
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_ssym
operator|=
name|ELF64_MIPS_R_SSYM
argument_list|(
name|src
index|[
literal|1
index|]
operator|.
name|r_info
argument_list|)
expr_stmt|;
name|mirela
operator|.
name|r_type3
operator|=
name|ELF64_MIPS_R_TYPE
argument_list|(
name|src
index|[
literal|2
index|]
operator|.
name|r_info
argument_list|)
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

begin_escape
end_escape

begin_comment
comment|/* Set the GP value for OUTPUT_BFD.  Returns FALSE if this is a    dangerous relocation.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf64_assign_gp
parameter_list|(
name|bfd
modifier|*
name|output_bfd
parameter_list|,
name|bfd_vma
modifier|*
name|pgp
parameter_list|)
block|{
name|unsigned
name|int
name|count
decl_stmt|;
name|asymbol
modifier|*
modifier|*
name|sym
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
comment|/* If we've already figured out what GP will be, just return it.  */
operator|*
name|pgp
operator|=
name|_bfd_get_gp_value
argument_list|(
name|output_bfd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pgp
condition|)
return|return
name|TRUE
return|;
name|count
operator|=
name|bfd_get_symcount
argument_list|(
name|output_bfd
argument_list|)
expr_stmt|;
name|sym
operator|=
name|bfd_get_outsymbols
argument_list|(
name|output_bfd
argument_list|)
expr_stmt|;
comment|/* The linker script will have created a symbol named `_gp' with the      appropriate value.  */
if|if
condition|(
name|sym
operator|==
name|NULL
condition|)
name|i
operator|=
name|count
expr_stmt|;
else|else
block|{
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
name|sym
operator|++
control|)
block|{
specifier|register
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|name
operator|=
name|bfd_asymbol_name
argument_list|(
operator|*
name|sym
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|name
operator|==
literal|'_'
operator|&&
name|strcmp
argument_list|(
name|name
argument_list|,
literal|"_gp"
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|*
name|pgp
operator|=
name|bfd_asymbol_value
argument_list|(
operator|*
name|sym
argument_list|)
expr_stmt|;
name|_bfd_set_gp_value
argument_list|(
name|output_bfd
argument_list|,
operator|*
name|pgp
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
block|}
if|if
condition|(
name|i
operator|>=
name|count
condition|)
block|{
comment|/* Only get the error once.  */
operator|*
name|pgp
operator|=
literal|4
expr_stmt|;
name|_bfd_set_gp_value
argument_list|(
name|output_bfd
argument_list|,
operator|*
name|pgp
argument_list|)
expr_stmt|;
return|return
name|FALSE
return|;
block|}
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* We have to figure out the gp value, so that we can adjust the    symbol value correctly.  We look up the symbol _gp in the output    BFD.  If we can't find it, we're stuck.  We cache it in the ELF    target data.  We don't need to adjust the symbol value for an    external symbol if we are producing relocatable output.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_final_gp
parameter_list|(
name|bfd
modifier|*
name|output_bfd
parameter_list|,
name|asymbol
modifier|*
name|symbol
parameter_list|,
name|bfd_boolean
name|relocatable
parameter_list|,
name|char
modifier|*
modifier|*
name|error_message
parameter_list|,
name|bfd_vma
modifier|*
name|pgp
parameter_list|)
block|{
if|if
condition|(
name|bfd_is_und_section
argument_list|(
name|symbol
operator|->
name|section
argument_list|)
operator|&&
operator|!
name|relocatable
condition|)
block|{
operator|*
name|pgp
operator|=
literal|0
expr_stmt|;
return|return
name|bfd_reloc_undefined
return|;
block|}
operator|*
name|pgp
operator|=
name|_bfd_get_gp_value
argument_list|(
name|output_bfd
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|pgp
operator|==
literal|0
operator|&&
operator|(
operator|!
name|relocatable
operator|||
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|!=
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|relocatable
condition|)
block|{
comment|/* Make up a value.  */
operator|*
name|pgp
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
comment|/*+ 0x4000*/
expr_stmt|;
name|_bfd_set_gp_value
argument_list|(
name|output_bfd
argument_list|,
operator|*
name|pgp
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|!
name|mips_elf64_assign_gp
argument_list|(
name|output_bfd
argument_list|,
name|pgp
argument_list|)
condition|)
block|{
operator|*
name|error_message
operator|=
operator|(
name|char
operator|*
operator|)
name|_
argument_list|(
literal|"GP relative relocation when _gp not defined"
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_dangerous
return|;
block|}
block|}
return|return
name|bfd_reloc_ok
return|;
block|}
end_function

begin_comment
comment|/* Do a R_MIPS_GPREL16 relocation.  This is a 16 bit value which must    become the offset from the gp register.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_gprel16_reloc
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
name|bfd_boolean
name|relocatable
decl_stmt|;
name|bfd_reloc_status_type
name|ret
decl_stmt|;
name|bfd_vma
name|gp
decl_stmt|;
comment|/* If we're relocating, and this is an external symbol, we don't want      to change anything.  */
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_LOCAL
operator|)
operator|!=
literal|0
condition|)
block|{
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
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
name|relocatable
operator|=
name|TRUE
expr_stmt|;
else|else
block|{
name|relocatable
operator|=
name|FALSE
expr_stmt|;
name|output_bfd
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|owner
expr_stmt|;
block|}
name|ret
operator|=
name|mips_elf64_final_gp
argument_list|(
name|output_bfd
argument_list|,
name|symbol
argument_list|,
name|relocatable
argument_list|,
name|error_message
argument_list|,
operator|&
name|gp
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|bfd_reloc_ok
condition|)
return|return
name|ret
return|;
return|return
name|_bfd_mips_elf_gprel16_with_gp
argument_list|(
name|abfd
argument_list|,
name|symbol
argument_list|,
name|reloc_entry
argument_list|,
name|input_section
argument_list|,
name|relocatable
argument_list|,
name|data
argument_list|,
name|gp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Do a R_MIPS_LITERAL relocation.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_literal_reloc
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
name|bfd_boolean
name|relocatable
decl_stmt|;
name|bfd_reloc_status_type
name|ret
decl_stmt|;
name|bfd_vma
name|gp
decl_stmt|;
comment|/* R_MIPS_LITERAL relocations are defined for local symbols only.  */
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_LOCAL
operator|)
operator|!=
literal|0
condition|)
block|{
operator|*
name|error_message
operator|=
operator|(
name|char
operator|*
operator|)
name|_
argument_list|(
literal|"literal relocation occurs for an external symbol"
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_outofrange
return|;
block|}
comment|/* FIXME: The entries in the .lit8 and .lit4 sections should be merged.  */
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
name|relocatable
operator|=
name|TRUE
expr_stmt|;
else|else
block|{
name|relocatable
operator|=
name|FALSE
expr_stmt|;
name|output_bfd
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|owner
expr_stmt|;
block|}
name|ret
operator|=
name|mips_elf64_final_gp
argument_list|(
name|output_bfd
argument_list|,
name|symbol
argument_list|,
name|relocatable
argument_list|,
name|error_message
argument_list|,
operator|&
name|gp
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|bfd_reloc_ok
condition|)
return|return
name|ret
return|;
return|return
name|_bfd_mips_elf_gprel16_with_gp
argument_list|(
name|abfd
argument_list|,
name|symbol
argument_list|,
name|reloc_entry
argument_list|,
name|input_section
argument_list|,
name|relocatable
argument_list|,
name|data
argument_list|,
name|gp
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Do a R_MIPS_GPREL32 relocation.  This is a 32 bit value which must    become the offset from the gp register.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_gprel32_reloc
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
name|bfd_boolean
name|relocatable
decl_stmt|;
name|bfd_reloc_status_type
name|ret
decl_stmt|;
name|bfd_vma
name|gp
decl_stmt|;
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
comment|/* R_MIPS_GPREL32 relocations are defined for local symbols only.  */
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_LOCAL
operator|)
operator|!=
literal|0
condition|)
block|{
operator|*
name|error_message
operator|=
operator|(
name|char
operator|*
operator|)
name|_
argument_list|(
literal|"32bits gp relative relocation occurs for an external symbol"
argument_list|)
expr_stmt|;
return|return
name|bfd_reloc_outofrange
return|;
block|}
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
name|relocatable
operator|=
name|TRUE
expr_stmt|;
else|else
block|{
name|relocatable
operator|=
name|FALSE
expr_stmt|;
name|output_bfd
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|owner
expr_stmt|;
block|}
name|ret
operator|=
name|mips_elf64_final_gp
argument_list|(
name|output_bfd
argument_list|,
name|symbol
argument_list|,
name|relocatable
argument_list|,
name|error_message
argument_list|,
operator|&
name|gp
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|bfd_reloc_ok
condition|)
return|return
name|ret
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
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|vma
expr_stmt|;
name|relocation
operator|+=
name|symbol
operator|->
name|section
operator|->
name|output_offset
expr_stmt|;
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
comment|/* Set val to the offset into the section or symbol.  */
name|val
operator|=
name|reloc_entry
operator|->
name|addend
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
condition|)
name|val
operator|+=
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
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
comment|/* Adjust val for the final section location and GP value.  If we      are producing relocatable output, we don't want to do this for      an external symbol.  */
if|if
condition|(
operator|!
name|relocatable
operator|||
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|!=
literal|0
condition|)
name|val
operator|+=
name|relocation
operator|-
name|gp
expr_stmt|;
if|if
condition|(
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
condition|)
name|bfd_put_32
argument_list|(
name|abfd
argument_list|,
name|val
argument_list|,
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
argument_list|)
expr_stmt|;
else|else
name|reloc_entry
operator|->
name|addend
operator|=
name|val
expr_stmt|;
if|if
condition|(
name|relocatable
condition|)
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
end_function

begin_comment
comment|/* Do a R_MIPS_SHIFT6 relocation. The MSB of the shift is stored at bit 2,    the rest is at bits 6-10. The bitpos already got right by the howto.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips_elf64_shift6_reloc
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
if|if
condition|(
name|reloc_entry
operator|->
name|howto
operator|->
name|partial_inplace
condition|)
block|{
name|reloc_entry
operator|->
name|addend
operator|=
operator|(
operator|(
name|reloc_entry
operator|->
name|addend
operator|&
literal|0x00007c0
operator|)
operator||
operator|(
name|reloc_entry
operator|->
name|addend
operator|&
literal|0x00000800
operator|)
operator|>>
literal|9
operator|)
expr_stmt|;
block|}
return|return
name|_bfd_mips_elf_generic_reloc
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
return|;
block|}
end_function

begin_comment
comment|/* Handle a mips16 GP relative reloc.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips16_gprel_reloc
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
name|bfd_boolean
name|relocatable
decl_stmt|;
name|bfd_reloc_status_type
name|ret
decl_stmt|;
name|bfd_byte
modifier|*
name|location
decl_stmt|;
name|bfd_vma
name|gp
decl_stmt|;
comment|/* If we're relocating, and this is an external symbol, we don't want      to change anything.  */
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
operator|&&
operator|(
name|symbol
operator|->
name|flags
operator|&
name|BSF_LOCAL
operator|)
operator|!=
literal|0
condition|)
block|{
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
if|if
condition|(
name|output_bfd
operator|!=
name|NULL
condition|)
name|relocatable
operator|=
name|TRUE
expr_stmt|;
else|else
block|{
name|relocatable
operator|=
name|FALSE
expr_stmt|;
name|output_bfd
operator|=
name|symbol
operator|->
name|section
operator|->
name|output_section
operator|->
name|owner
expr_stmt|;
block|}
name|ret
operator|=
name|mips_elf64_final_gp
argument_list|(
name|output_bfd
argument_list|,
name|symbol
argument_list|,
name|relocatable
argument_list|,
name|error_message
argument_list|,
operator|&
name|gp
argument_list|)
expr_stmt|;
if|if
condition|(
name|ret
operator|!=
name|bfd_reloc_ok
condition|)
return|return
name|ret
return|;
name|location
operator|=
operator|(
name|bfd_byte
operator|*
operator|)
name|data
operator|+
name|reloc_entry
operator|->
name|address
expr_stmt|;
name|_bfd_mips16_elf_reloc_unshuffle
argument_list|(
name|abfd
argument_list|,
name|reloc_entry
operator|->
name|howto
operator|->
name|type
argument_list|,
name|FALSE
argument_list|,
name|location
argument_list|)
expr_stmt|;
name|ret
operator|=
name|_bfd_mips_elf_gprel16_with_gp
argument_list|(
name|abfd
argument_list|,
name|symbol
argument_list|,
name|reloc_entry
argument_list|,
name|input_section
argument_list|,
name|relocatable
argument_list|,
name|data
argument_list|,
name|gp
argument_list|)
expr_stmt|;
name|_bfd_mips16_elf_reloc_shuffle
argument_list|(
name|abfd
argument_list|,
name|reloc_entry
operator|->
name|howto
operator|->
name|type
argument_list|,
operator|!
name|relocatable
argument_list|,
name|location
argument_list|)
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* A mapping from BFD reloc types to MIPS ELF reloc types.  */
end_comment

begin_struct
struct|struct
name|elf_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_val
decl_stmt|;
name|enum
name|elf_mips_reloc_type
name|elf_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf_reloc_map
name|mips_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_MIPS_NONE
block|}
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
comment|/* There is no BFD reloc for R_MIPS_REL32.  */
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
name|BFD_RELOC_16_PCREL_S2
block|,
name|R_MIPS_PC16
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
name|BFD_RELOC_GPREL16
block|,
name|R_MIPS_GPREL16
block|}
block|,
block|{
name|BFD_RELOC_GPREL32
block|,
name|R_MIPS_GPREL32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_JMP
block|,
name|R_MIPS_26
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
name|BFD_RELOC_MIPS_CALL16
block|,
name|R_MIPS_CALL16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_SHIFT5
block|,
name|R_MIPS_SHIFT5
block|}
block|,
block|{
name|BFD_RELOC_MIPS_SHIFT6
block|,
name|R_MIPS_SHIFT6
block|}
block|,
block|{
name|BFD_RELOC_MIPS_GOT_DISP
block|,
name|R_MIPS_GOT_DISP
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
name|BFD_RELOC_MIPS_SUB
block|,
name|R_MIPS_SUB
block|}
block|,
block|{
name|BFD_RELOC_MIPS_INSERT_A
block|,
name|R_MIPS_INSERT_A
block|}
block|,
block|{
name|BFD_RELOC_MIPS_INSERT_B
block|,
name|R_MIPS_INSERT_B
block|}
block|,
block|{
name|BFD_RELOC_MIPS_DELETE
block|,
name|R_MIPS_DELETE
block|}
block|,
block|{
name|BFD_RELOC_MIPS_HIGHEST
block|,
name|R_MIPS_HIGHEST
block|}
block|,
block|{
name|BFD_RELOC_MIPS_HIGHER
block|,
name|R_MIPS_HIGHER
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
name|BFD_RELOC_MIPS_SCN_DISP
block|,
name|R_MIPS_SCN_DISP
block|}
block|,
block|{
name|BFD_RELOC_MIPS_REL16
block|,
name|R_MIPS_REL16
block|}
block|,
comment|/* Use of R_MIPS_ADD_IMMEDIATE and R_MIPS_PJUMP is deprecated.  */
block|{
name|BFD_RELOC_MIPS_RELGOT
block|,
name|R_MIPS_RELGOT
block|}
block|,
block|{
name|BFD_RELOC_MIPS_JALR
block|,
name|R_MIPS_JALR
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPMOD32
block|,
name|R_MIPS_TLS_DTPMOD32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPREL32
block|,
name|R_MIPS_TLS_DTPREL32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPMOD64
block|,
name|R_MIPS_TLS_DTPMOD64
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPREL64
block|,
name|R_MIPS_TLS_DTPREL64
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_GD
block|,
name|R_MIPS_TLS_GD
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_LDM
block|,
name|R_MIPS_TLS_LDM
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPREL_HI16
block|,
name|R_MIPS_TLS_DTPREL_HI16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_DTPREL_LO16
block|,
name|R_MIPS_TLS_DTPREL_LO16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_GOTTPREL
block|,
name|R_MIPS_TLS_GOTTPREL
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_TPREL32
block|,
name|R_MIPS_TLS_TPREL32
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_TPREL64
block|,
name|R_MIPS_TLS_TPREL64
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_TPREL_HI16
block|,
name|R_MIPS_TLS_TPREL_HI16
block|}
block|,
block|{
name|BFD_RELOC_MIPS_TLS_TPREL_LO16
block|,
name|R_MIPS_TLS_TPREL_LO16
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf_reloc_map
name|mips16_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_MIPS16_JMP
block|,
name|R_MIPS16_26
operator|-
name|R_MIPS16_min
block|}
block|,
block|{
name|BFD_RELOC_MIPS16_GPREL
block|,
name|R_MIPS16_GPREL
operator|-
name|R_MIPS16_min
block|}
block|,
block|{
name|BFD_RELOC_MIPS16_HI16_S
block|,
name|R_MIPS16_HI16
operator|-
name|R_MIPS16_min
block|}
block|,
block|{
name|BFD_RELOC_MIPS16_LO16
block|,
name|R_MIPS16_LO16
operator|-
name|R_MIPS16_min
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Given a BFD reloc type, return a howto structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf64_bfd_reloc_type_lookup
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
comment|/* FIXME: We default to RELA here instead of choosing the right      relocation variant.  */
name|reloc_howto_type
modifier|*
name|howto_table
init|=
name|mips_elf64_howto_table_rela
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto16_table
init|=
name|mips16_elf64_howto_table_rela
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
name|bfd_val
operator|==
name|code
condition|)
return|return
operator|&
name|howto_table
index|[
operator|(
name|int
operator|)
name|mips_reloc_map
index|[
name|i
index|]
operator|.
name|elf_val
index|]
return|;
block|}
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
name|mips16_reloc_map
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
name|mips16_reloc_map
index|[
name|i
index|]
operator|.
name|bfd_val
operator|==
name|code
condition|)
return|return
operator|&
name|howto16_table
index|[
operator|(
name|int
operator|)
name|mips16_reloc_map
index|[
name|i
index|]
operator|.
name|elf_val
index|]
return|;
block|}
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|BFD_RELOC_VTABLE_INHERIT
case|:
return|return
operator|&
name|elf_mips_gnu_vtinherit_howto
return|;
case|case
name|BFD_RELOC_VTABLE_ENTRY
case|:
return|return
operator|&
name|elf_mips_gnu_vtentry_howto
return|;
default|default:
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf64_bfd_reloc_name_lookup
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
name|mips_elf64_howto_table_rela
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mips_elf64_howto_table_rela
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
name|mips_elf64_howto_table_rela
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
name|mips_elf64_howto_table_rela
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
name|mips_elf64_howto_table_rela
index|[
name|i
index|]
return|;
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
name|mips16_elf64_howto_table_rela
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|mips16_elf64_howto_table_rela
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
name|mips16_elf64_howto_table_rela
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
name|mips16_elf64_howto_table_rela
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
name|mips16_elf64_howto_table_rela
index|[
name|i
index|]
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|elf_mips_gnu_vtinherit_howto
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
name|elf_mips_gnu_vtinherit_howto
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|elf_mips_gnu_vtentry_howto
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
name|elf_mips_gnu_vtentry_howto
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|elf_mips_gnu_rel16_s2
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
name|elf_mips_gnu_rel16_s2
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|elf_mips_gnu_rela16_s2
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
name|elf_mips_gnu_rela16_s2
return|;
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Given a MIPS Elf_Internal_Rel, fill in an arelent structure.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mips_elf64_rtype_to_howto
parameter_list|(
name|unsigned
name|int
name|r_type
parameter_list|,
name|bfd_boolean
name|rela_p
parameter_list|)
block|{
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|R_MIPS_GNU_VTINHERIT
case|:
return|return
operator|&
name|elf_mips_gnu_vtinherit_howto
return|;
case|case
name|R_MIPS_GNU_VTENTRY
case|:
return|return
operator|&
name|elf_mips_gnu_vtentry_howto
return|;
case|case
name|R_MIPS_GNU_REL16_S2
case|:
if|if
condition|(
name|rela_p
condition|)
return|return
operator|&
name|elf_mips_gnu_rela16_s2
return|;
else|else
return|return
operator|&
name|elf_mips_gnu_rel16_s2
return|;
default|default:
if|if
condition|(
name|r_type
operator|>=
name|R_MIPS16_min
operator|&&
name|r_type
operator|<
name|R_MIPS16_max
condition|)
block|{
if|if
condition|(
name|rela_p
condition|)
return|return
operator|&
name|mips16_elf64_howto_table_rela
index|[
name|r_type
operator|-
name|R_MIPS16_min
index|]
return|;
else|else
return|return
operator|&
name|mips16_elf64_howto_table_rel
index|[
name|r_type
operator|-
name|R_MIPS16_min
index|]
return|;
block|}
name|BFD_ASSERT
argument_list|(
name|r_type
operator|<
operator|(
name|unsigned
name|int
operator|)
name|R_MIPS_max
argument_list|)
expr_stmt|;
if|if
condition|(
name|rela_p
condition|)
return|return
operator|&
name|mips_elf64_howto_table_rela
index|[
name|r_type
index|]
return|;
else|else
return|return
operator|&
name|mips_elf64_howto_table_rel
index|[
name|r_type
index|]
return|;
break|break;
block|}
block|}
end_function

begin_comment
comment|/* Prevent relocation handling by bfd for MIPS ELF64.  */
end_comment

begin_function
specifier|static
name|void
name|mips_elf64_info_to_howto_rel
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
name|ATTRIBUTE_UNUSED
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|mips_elf64_info_to_howto_rela
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
name|ATTRIBUTE_UNUSED
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
name|ATTRIBUTE_UNUSED
parameter_list|)
block|{
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
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
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|)
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

begin_function
specifier|static
name|long
name|mips_elf64_get_dynamic_reloc_upper_bound
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
return|return
name|_bfd_elf_get_dynamic_reloc_upper_bound
argument_list|(
name|abfd
argument_list|)
operator|*
literal|3
return|;
block|}
end_function

begin_comment
comment|/* We must also copy more relocations than the corresponding functions    in elf.c would, so the two following functions are slightly    modified from elf.c, that multiply the external relocation count by    3 to obtain the internal relocation count.  */
end_comment

begin_function
specifier|static
name|long
name|mips_elf64_canonicalize_reloc
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|sec_ptr
name|section
parameter_list|,
name|arelent
modifier|*
modifier|*
name|relptr
parameter_list|,
name|asymbol
modifier|*
modifier|*
name|symbols
parameter_list|)
block|{
name|arelent
modifier|*
name|tblptr
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
specifier|const
name|struct
name|elf_backend_data
modifier|*
name|bed
init|=
name|get_elf_backend_data
argument_list|(
name|abfd
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|bed
operator|->
name|s
operator|->
name|slurp_reloc_table
argument_list|(
name|abfd
argument_list|,
name|section
argument_list|,
name|symbols
argument_list|,
name|FALSE
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|tblptr
operator|=
name|section
operator|->
name|relocation
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|section
operator|->
name|reloc_count
operator|*
literal|3
condition|;
name|i
operator|++
control|)
operator|*
name|relptr
operator|++
operator|=
name|tblptr
operator|++
expr_stmt|;
operator|*
name|relptr
operator|=
name|NULL
expr_stmt|;
return|return
name|section
operator|->
name|reloc_count
operator|*
literal|3
return|;
block|}
end_function

begin_function
specifier|static
name|long
name|mips_elf64_canonicalize_dynamic_reloc
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|arelent
modifier|*
modifier|*
name|storage
parameter_list|,
name|asymbol
modifier|*
modifier|*
name|syms
parameter_list|)
block|{
name|bfd_boolean
function_decl|(
modifier|*
name|slurp_relocs
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
name|asection
modifier|*
name|s
decl_stmt|;
name|long
name|ret
decl_stmt|;
if|if
condition|(
name|elf_dynsymtab
argument_list|(
name|abfd
argument_list|)
operator|==
literal|0
condition|)
block|{
name|bfd_set_error
argument_list|(
name|bfd_error_invalid_operation
argument_list|)
expr_stmt|;
return|return
operator|-
literal|1
return|;
block|}
name|slurp_relocs
operator|=
name|get_elf_backend_data
argument_list|(
name|abfd
argument_list|)
operator|->
name|s
operator|->
name|slurp_reloc_table
expr_stmt|;
name|ret
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|s
operator|=
name|abfd
operator|->
name|sections
init|;
name|s
operator|!=
name|NULL
condition|;
name|s
operator|=
name|s
operator|->
name|next
control|)
block|{
if|if
condition|(
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_link
operator|==
name|elf_dynsymtab
argument_list|(
name|abfd
argument_list|)
operator|&&
operator|(
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_type
operator|==
name|SHT_REL
operator|||
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_type
operator|==
name|SHT_RELA
operator|)
condition|)
block|{
name|arelent
modifier|*
name|p
decl_stmt|;
name|long
name|count
decl_stmt|,
name|i
decl_stmt|;
if|if
condition|(
operator|!
call|(
modifier|*
name|slurp_relocs
call|)
argument_list|(
name|abfd
argument_list|,
name|s
argument_list|,
name|syms
argument_list|,
name|TRUE
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
name|count
operator|=
name|s
operator|->
name|size
operator|/
name|elf_section_data
argument_list|(
name|s
argument_list|)
operator|->
name|this_hdr
operator|.
name|sh_entsize
operator|*
literal|3
expr_stmt|;
name|p
operator|=
name|s
operator|->
name|relocation
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
control|)
operator|*
name|storage
operator|++
operator|=
name|p
operator|++
expr_stmt|;
name|ret
operator|+=
name|count
expr_stmt|;
block|}
block|}
operator|*
name|storage
operator|=
name|NULL
expr_stmt|;
return|return
name|ret
return|;
block|}
end_function

begin_comment
comment|/* Read the relocations from one reloc section.  This is mostly copied    from elfcode.h, except for the changes to expand one external    relocation to 3 internal ones.  We must unfortunately set    reloc_count to the number of external relocations, because a lot of    generic code seems to depend on this.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf64_slurp_one_reloc_table
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|asect
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr
parameter_list|,
name|bfd_size_type
name|reloc_count
parameter_list|,
name|arelent
modifier|*
name|relents
parameter_list|,
name|asymbol
modifier|*
modifier|*
name|symbols
parameter_list|,
name|bfd_boolean
name|dynamic
parameter_list|)
block|{
name|void
modifier|*
name|allocated
decl_stmt|;
name|bfd_byte
modifier|*
name|native_relocs
decl_stmt|;
name|arelent
modifier|*
name|relent
decl_stmt|;
name|bfd_vma
name|i
decl_stmt|;
name|int
name|entsize
decl_stmt|;
name|bfd_boolean
name|rela_p
decl_stmt|;
name|allocated
operator|=
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
return|return
name|FALSE
return|;
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
name|bfd_bread
argument_list|(
name|allocated
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
name|allocated
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
if|if
condition|(
name|entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rel
argument_list|)
condition|)
name|rela_p
operator|=
name|FALSE
expr_stmt|;
else|else
name|rela_p
operator|=
name|TRUE
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
operator|,
name|relent
operator|=
name|relents
init|;
name|i
operator|<
name|reloc_count
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
name|bfd_boolean
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
name|rela
argument_list|)
expr_stmt|;
comment|/* Each entry represents exactly three actual relocations.  */
name|used_sym
operator|=
name|FALSE
expr_stmt|;
name|used_ssym
operator|=
name|FALSE
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
name|TRUE
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
comment|/* FIXME: I think these need to be handled using 			 special howto structures.  */
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
name|TRUE
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
operator|||
name|dynamic
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
name|mips_elf64_rtype_to_howto
argument_list|(
name|type
argument_list|,
name|rela_p
argument_list|)
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
operator|(
name|relent
operator|-
name|relents
operator|)
operator|/
literal|3
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
name|TRUE
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
name|FALSE
return|;
block|}
end_function

begin_comment
comment|/* Read the relocations.  On Irix 6, there can be two reloc sections    associated with a single data section.  This is copied from    elfcode.h as well, with changes as small as accounting for 3    internal relocs per external reloc and resetting reloc_count to    zero before processing the relocs of a section.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf64_slurp_reloc_table
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|asect
parameter_list|,
name|asymbol
modifier|*
modifier|*
name|symbols
parameter_list|,
name|bfd_boolean
name|dynamic
parameter_list|)
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
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr
decl_stmt|;
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr2
decl_stmt|;
name|bfd_size_type
name|reloc_count
decl_stmt|;
name|bfd_size_type
name|reloc_count2
decl_stmt|;
name|arelent
modifier|*
name|relents
decl_stmt|;
name|bfd_size_type
name|amt
decl_stmt|;
if|if
condition|(
name|asect
operator|->
name|relocation
operator|!=
name|NULL
condition|)
return|return
name|TRUE
return|;
if|if
condition|(
operator|!
name|dynamic
condition|)
block|{
if|if
condition|(
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
name|TRUE
return|;
name|rel_hdr
operator|=
operator|&
name|d
operator|->
name|rel_hdr
expr_stmt|;
name|reloc_count
operator|=
name|NUM_SHDR_ENTRIES
argument_list|(
name|rel_hdr
argument_list|)
expr_stmt|;
name|rel_hdr2
operator|=
name|d
operator|->
name|rel_hdr2
expr_stmt|;
name|reloc_count2
operator|=
operator|(
name|rel_hdr2
condition|?
name|NUM_SHDR_ENTRIES
argument_list|(
name|rel_hdr2
argument_list|)
else|:
literal|0
operator|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|asect
operator|->
name|reloc_count
operator|==
name|reloc_count
operator|+
name|reloc_count2
argument_list|)
expr_stmt|;
name|BFD_ASSERT
argument_list|(
name|asect
operator|->
name|rel_filepos
operator|==
name|rel_hdr
operator|->
name|sh_offset
operator|||
operator|(
name|rel_hdr2
operator|&&
name|asect
operator|->
name|rel_filepos
operator|==
name|rel_hdr2
operator|->
name|sh_offset
operator|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* Note that ASECT->RELOC_COUNT tends not to be accurate in this 	 case because relocations against this section may use the 	 dynamic symbol table, and in that case bfd_section_from_shdr 	 in elf.c does not update the RELOC_COUNT.  */
if|if
condition|(
name|asect
operator|->
name|size
operator|==
literal|0
condition|)
return|return
name|TRUE
return|;
name|rel_hdr
operator|=
operator|&
name|d
operator|->
name|this_hdr
expr_stmt|;
name|reloc_count
operator|=
name|NUM_SHDR_ENTRIES
argument_list|(
name|rel_hdr
argument_list|)
expr_stmt|;
name|rel_hdr2
operator|=
name|NULL
expr_stmt|;
name|reloc_count2
operator|=
literal|0
expr_stmt|;
block|}
comment|/* Allocate space for 3 arelent structures for each Rel structure.  */
name|amt
operator|=
operator|(
name|reloc_count
operator|+
name|reloc_count2
operator|)
operator|*
literal|3
operator|*
sizeof|sizeof
argument_list|(
name|arelent
argument_list|)
expr_stmt|;
name|relents
operator|=
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|amt
argument_list|)
expr_stmt|;
if|if
condition|(
name|relents
operator|==
name|NULL
condition|)
return|return
name|FALSE
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
name|rel_hdr
argument_list|,
name|reloc_count
argument_list|,
name|relents
argument_list|,
name|symbols
argument_list|,
name|dynamic
argument_list|)
condition|)
return|return
name|FALSE
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
name|rel_hdr2
argument_list|,
name|reloc_count2
argument_list|,
name|relents
operator|+
name|reloc_count
operator|*
literal|3
argument_list|,
name|symbols
argument_list|,
name|dynamic
argument_list|)
condition|)
return|return
name|FALSE
return|;
block|}
name|asect
operator|->
name|relocation
operator|=
name|relents
expr_stmt|;
return|return
name|TRUE
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
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|bfd_boolean
modifier|*
name|failedp
init|=
name|data
decl_stmt|;
name|int
name|count
decl_stmt|;
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr
decl_stmt|;
name|unsigned
name|int
name|idx
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
name|rel_hdr
operator|=
operator|&
name|elf_section_data
argument_list|(
name|sec
argument_list|)
operator|->
name|rel_hdr
expr_stmt|;
comment|/* Do the actual relocation.  */
if|if
condition|(
name|rel_hdr
operator|->
name|sh_entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rel
argument_list|)
condition|)
name|mips_elf64_write_rel
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|,
name|rel_hdr
argument_list|,
operator|&
name|count
argument_list|,
name|data
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|rel_hdr
operator|->
name|sh_entsize
operator|==
sizeof|sizeof
argument_list|(
name|Elf64_Mips_External_Rela
argument_list|)
condition|)
name|mips_elf64_write_rela
argument_list|(
name|abfd
argument_list|,
name|sec
argument_list|,
name|rel_hdr
argument_list|,
operator|&
name|count
argument_list|,
name|data
argument_list|)
expr_stmt|;
else|else
name|BFD_ASSERT
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|mips_elf64_write_rel
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
name|rel_hdr
parameter_list|,
name|int
modifier|*
name|count
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|bfd_boolean
modifier|*
name|failedp
init|=
name|data
decl_stmt|;
name|Elf64_Mips_External_Rel
modifier|*
name|ext_rel
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
name|rel_hdr
operator|->
name|sh_size
operator|=
name|rel_hdr
operator|->
name|sh_entsize
operator|*
operator|*
name|count
expr_stmt|;
name|rel_hdr
operator|->
name|contents
operator|=
name|bfd_alloc
argument_list|(
name|abfd
argument_list|,
name|rel_hdr
operator|->
name|sh_size
argument_list|)
expr_stmt|;
if|if
condition|(
name|rel_hdr
operator|->
name|contents
operator|==
name|NULL
condition|)
block|{
operator|*
name|failedp
operator|=
name|TRUE
expr_stmt|;
return|return;
block|}
name|ext_rel
operator|=
operator|(
name|Elf64_Mips_External_Rel
operator|*
operator|)
name|rel_hdr
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
name|ext_rel
operator|++
control|)
block|{
name|arelent
modifier|*
name|ptr
decl_stmt|;
name|Elf64_Mips_Internal_Rela
name|int_rel
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
name|int_rel
operator|.
name|r_offset
operator|=
name|ptr
operator|->
name|address
expr_stmt|;
else|else
name|int_rel
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
elseif|else
if|if
condition|(
name|bfd_is_abs_section
argument_list|(
name|sym
operator|->
name|section
argument_list|)
operator|&&
name|sym
operator|->
name|value
operator|==
literal|0
condition|)
name|n
operator|=
name|STN_UNDEF
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
name|TRUE
expr_stmt|;
return|return;
block|}
name|last_sym_idx
operator|=
name|n
expr_stmt|;
block|}
name|int_rel
operator|.
name|r_sym
operator|=
name|n
expr_stmt|;
name|int_rel
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
name|TRUE
expr_stmt|;
return|return;
block|}
name|int_rel
operator|.
name|r_type
operator|=
name|ptr
operator|->
name|howto
operator|->
name|type
expr_stmt|;
name|int_rel
operator|.
name|r_type2
operator|=
operator|(
name|int
operator|)
name|R_MIPS_NONE
expr_stmt|;
name|int_rel
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
name|int_rel
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
name|int_rel
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
name|mips_elf64_swap_reloc_out
argument_list|(
name|abfd
argument_list|,
operator|&
name|int_rel
argument_list|,
name|ext_rel
argument_list|)
expr_stmt|;
block|}
name|BFD_ASSERT
argument_list|(
name|ext_rel
operator|-
operator|(
name|Elf64_Mips_External_Rel
operator|*
operator|)
name|rel_hdr
operator|->
name|contents
operator|==
operator|*
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|mips_elf64_write_rela
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asection
modifier|*
name|sec
parameter_list|,
name|Elf_Internal_Shdr
modifier|*
name|rela_hdr
parameter_list|,
name|int
modifier|*
name|count
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
block|{
name|bfd_boolean
modifier|*
name|failedp
init|=
name|data
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
name|rela_hdr
operator|->
name|sh_size
operator|=
name|rela_hdr
operator|->
name|sh_entsize
operator|*
operator|*
name|count
expr_stmt|;
name|rela_hdr
operator|->
name|contents
operator|=
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
name|TRUE
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
elseif|else
if|if
condition|(
name|bfd_is_abs_section
argument_list|(
name|sym
operator|->
name|section
argument_list|)
operator|&&
name|sym
operator|->
name|value
operator|==
literal|0
condition|)
name|n
operator|=
name|STN_UNDEF
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
name|TRUE
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
name|TRUE
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
operator|*
name|count
argument_list|)
expr_stmt|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Set the right machine number for a MIPS ELF file.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf64_object_p
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
name|unsigned
name|long
name|mach
decl_stmt|;
comment|/* Irix 6 is broken.  Object file symbol tables are not always      sorted correctly such that local symbols precede global symbols,      and the sh_info field in the symbol table is not always right.  */
if|if
condition|(
name|elf64_mips_irix_compat
argument_list|(
name|abfd
argument_list|)
operator|!=
name|ict_none
condition|)
name|elf_bad_symtab
argument_list|(
name|abfd
argument_list|)
operator|=
name|TRUE
expr_stmt|;
name|mach
operator|=
name|_bfd_elf_mips_mach
argument_list|(
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
argument_list|)
expr_stmt|;
name|bfd_default_set_arch_mach
argument_list|(
name|abfd
argument_list|,
name|bfd_arch_mips
argument_list|,
name|mach
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/* Depending on the target vector we generate some version of Irix    executables or "normal" MIPS ELF ABI executables.  */
end_comment

begin_function
specifier|static
name|irix_compat_t
name|elf64_mips_irix_compat
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
block|{
if|if
condition|(
operator|(
name|abfd
operator|->
name|xvec
operator|==
operator|&
name|bfd_elf64_bigmips_vec
operator|)
operator|||
operator|(
name|abfd
operator|->
name|xvec
operator|==
operator|&
name|bfd_elf64_littlemips_vec
operator|)
condition|)
return|return
name|ict_irix6
return|;
else|else
return|return
name|ict_none
return|;
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Support for core dump NOTE sections.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|elf64_mips_grok_prstatus
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|Elf_Internal_Note
modifier|*
name|note
parameter_list|)
block|{
name|int
name|offset
decl_stmt|;
name|unsigned
name|int
name|size
decl_stmt|;
switch|switch
condition|(
name|note
operator|->
name|descsz
condition|)
block|{
default|default:
return|return
name|FALSE
return|;
case|case
literal|480
case|:
comment|/* Linux/MIPS - N64 kernel */
comment|/* pr_cursig */
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|core_signal
operator|=
name|bfd_get_16
argument_list|(
name|abfd
argument_list|,
name|note
operator|->
name|descdata
operator|+
literal|12
argument_list|)
expr_stmt|;
comment|/* pr_pid */
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|core_pid
operator|=
name|bfd_get_32
argument_list|(
name|abfd
argument_list|,
name|note
operator|->
name|descdata
operator|+
literal|32
argument_list|)
expr_stmt|;
comment|/* pr_reg */
name|offset
operator|=
literal|112
expr_stmt|;
name|size
operator|=
literal|360
expr_stmt|;
break|break;
block|}
comment|/* Make a ".reg/999" section.  */
return|return
name|_bfd_elfcore_make_pseudosection
argument_list|(
name|abfd
argument_list|,
literal|".reg"
argument_list|,
name|size
argument_list|,
name|note
operator|->
name|descpos
operator|+
name|offset
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bfd_boolean
name|elf64_mips_grok_psinfo
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|Elf_Internal_Note
modifier|*
name|note
parameter_list|)
block|{
switch|switch
condition|(
name|note
operator|->
name|descsz
condition|)
block|{
default|default:
return|return
name|FALSE
return|;
case|case
literal|136
case|:
comment|/* Linux/MIPS - N64 kernel elf_prpsinfo */
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|core_program
operator|=
name|_bfd_elfcore_strndup
argument_list|(
name|abfd
argument_list|,
name|note
operator|->
name|descdata
operator|+
literal|40
argument_list|,
literal|16
argument_list|)
expr_stmt|;
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|core_command
operator|=
name|_bfd_elfcore_strndup
argument_list|(
name|abfd
argument_list|,
name|note
operator|->
name|descdata
operator|+
literal|56
argument_list|,
literal|80
argument_list|)
expr_stmt|;
block|}
comment|/* Note that for some reason, a spurious space is tacked      onto the end of the args in some (at least one anyway)      implementations, so strip it off if it exists.  */
block|{
name|char
modifier|*
name|command
init|=
name|elf_tdata
argument_list|(
name|abfd
argument_list|)
operator|->
name|core_command
decl_stmt|;
name|int
name|n
init|=
name|strlen
argument_list|(
name|command
argument_list|)
decl_stmt|;
if|if
condition|(
literal|0
operator|<
name|n
operator|&&
name|command
index|[
name|n
operator|-
literal|1
index|]
operator|==
literal|' '
condition|)
name|command
index|[
name|n
operator|-
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
return|return
name|TRUE
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
literal|3
block|,
comment|/* log_file_align */
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
name|bfd_elf64_swap_symbol_in
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
name|elf_backend_collect
value|TRUE
end_define

begin_define
define|#
directive|define
name|elf_backend_type_change_ok
value|TRUE
end_define

begin_define
define|#
directive|define
name|elf_backend_can_gc_sections
value|TRUE
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|mips_elf64_info_to_howto_rela
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|mips_elf64_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|mips_elf64_object_p
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
name|elf_backend_section_processing
value|_bfd_mips_elf_section_processing
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
name|elf_backend_add_symbol_hook
value|_bfd_mips_elf_add_symbol_hook
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
name|elf_backend_merge_symbol_attribute
define|\
value|_bfd_mips_elf_merge_symbol_attribute
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
name|elf_backend_init_index_section
value|_bfd_elf_init_1_index_section
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
name|elf_backend_final_write_processing
define|\
value|_bfd_mips_elf_final_write_processing
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
name|elf_backend_copy_indirect_symbol
define|\
value|_bfd_mips_elf_copy_indirect_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_hide_symbol
value|_bfd_mips_elf_hide_symbol
end_define

begin_define
define|#
directive|define
name|elf_backend_ignore_discarded_relocs
define|\
value|_bfd_mips_elf_ignore_discarded_relocs
end_define

begin_define
define|#
directive|define
name|elf_backend_mips_irix_compat
value|elf64_mips_irix_compat
end_define

begin_define
define|#
directive|define
name|elf_backend_mips_rtype_to_howto
value|mips_elf64_rtype_to_howto
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
name|elf_backend_size_info
value|mips_elf64_size_info
end_define

begin_define
define|#
directive|define
name|elf_backend_grok_prstatus
value|elf64_mips_grok_prstatus
end_define

begin_define
define|#
directive|define
name|elf_backend_grok_psinfo
value|elf64_mips_grok_psinfo
end_define

begin_define
define|#
directive|define
name|elf_backend_got_header_size
value|(4 * MIPS_RESERVED_GOTNO)
end_define

begin_comment
comment|/* MIPS ELF64 can use a mixture of REL and RELA, but some Relocations    work better/work only in RELA, so we default to this.  */
end_comment

begin_define
define|#
directive|define
name|elf_backend_may_use_rel_p
value|1
end_define

begin_define
define|#
directive|define
name|elf_backend_may_use_rela_p
value|1
end_define

begin_define
define|#
directive|define
name|elf_backend_default_use_rela_p
value|1
end_define

begin_define
define|#
directive|define
name|elf_backend_write_section
value|_bfd_mips_elf_write_section
end_define

begin_comment
comment|/* We don't set bfd_elf64_bfd_is_local_label_name because the 32-bit    MIPS-specific function only applies to IRIX5, which had no 64-bit    ABI.  */
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
name|bfd_elf64_find_inliner_info
value|_bfd_mips_elf_find_inliner_info
end_define

begin_define
define|#
directive|define
name|bfd_elf64_new_section_hook
value|_bfd_mips_elf_new_section_hook
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
name|bfd_elf64_bfd_get_relocated_section_contents
define|\
value|_bfd_elf_mips_get_relocated_section_contents
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
name|bfd_elf64_canonicalize_reloc
value|mips_elf64_canonicalize_reloc
end_define

begin_define
define|#
directive|define
name|bfd_elf64_get_dynamic_reloc_upper_bound
value|mips_elf64_get_dynamic_reloc_upper_bound
end_define

begin_define
define|#
directive|define
name|bfd_elf64_canonicalize_dynamic_reloc
value|mips_elf64_canonicalize_dynamic_reloc
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_relax_section
value|_bfd_mips_relax_section
end_define

begin_comment
comment|/* MIPS ELF64 archive functions.  */
end_comment

begin_define
define|#
directive|define
name|bfd_elf64_archive_functions
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|bfd_elf64_archive_slurp_armap
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|bfd_elf64_archive_write_armap
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|struct
name|orl
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* The SGI style (n)64 NewABI.  */
end_comment

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
name|ELF_MAXPAGESIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|ELF_COMMONPAGESIZE
value|0x1000
end_define

begin_include
include|#
directive|include
file|"elf64-target.h"
end_include

begin_comment
comment|/* The SYSV-style 'traditional' (n)64 NewABI.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LITTLE_SYM
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_LITTLE_NAME
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_BIG_SYM
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_BIG_NAME
end_undef

begin_undef
undef|#
directive|undef
name|ELF_MAXPAGESIZE
end_undef

begin_undef
undef|#
directive|undef
name|ELF_COMMONPAGESIZE
end_undef

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf64_tradlittlemips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf64-tradlittlemips"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf64_tradbigmips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf64-tradbigmips"
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|ELF_COMMONPAGESIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|elf64_bed
value|elf64_tradbed
end_define

begin_comment
comment|/* Include the target file again for this target.  */
end_comment

begin_include
include|#
directive|include
file|"elf64-target.h"
end_include

end_unit

