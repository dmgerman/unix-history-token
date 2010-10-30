begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MIPS-specific support for 32-bit ELF    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002,    2003, 2004, 2005, 2007 Free Software Foundation, Inc.     Most of the information added by Ian Lance Taylor, Cygnus Support,<ian@cygnus.com>.    N32/64 ABI support added by Mark Mitchell, CodeSourcery, LLC.<mark@codesourcery.com>    Traditional MIPS targets support added by Koundinya.K, Dansk Data    Elektronik& Operations Research Group.<kk@ddeorg.soft.net>  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This file handles MIPS ELF targets.  SGI Irix 5 uses a slightly    different MIPS ELF from other targets.  This matters when linking.    This file supports both, switching at runtime.  */
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

begin_include
include|#
directive|include
file|"elf-vxworks.h"
end_include

begin_comment
comment|/* Get the ECOFF swapping routines.  */
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

begin_include
include|#
directive|include
file|"coff/mips.h"
end_include

begin_define
define|#
directive|define
name|ECOFF_SIGNED_32
end_define

begin_include
include|#
directive|include
file|"ecoffswap.h"
end_include

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|gprel32_with_gp
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|arelent
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_reloc_status_type
name|mips_elf_gprel32_reloc
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
name|mips32_64bit_reloc
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
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_type_lookup
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
name|mips_elf32_rtype_to_howto
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
name|mips_info_to_howto_rel
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
name|mips_info_to_howto_rela
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
name|bfd_boolean
name|mips_elf_sym_is_global
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf32_object_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|bfd_boolean
name|mips_elf_is_local_label_name
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
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
name|bfd_reloc_status_type
name|mips_elf_final_gp
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
name|mips_elf_assign_gp
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
name|bfd_boolean
name|elf32_mips_grok_prstatus
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
name|elf32_mips_grok_psinfo
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
name|irix_compat_t
name|elf32_mips_irix_compat
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|bfd_elf32_bigmips_vec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|bfd_elf32_littlemips_vec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if ABFD is using the N32 ABI.  */
end_comment

begin_define
define|#
directive|define
name|ABI_N32_P
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((elf_elfheader (abfd)->e_flags& EF_MIPS_ABI2) != 0)
end_define

begin_comment
comment|/* Whether we are trying to be compatible with IRIX at all.  */
end_comment

begin_define
define|#
directive|define
name|SGI_COMPAT
parameter_list|(
name|abfd
parameter_list|)
define|\
value|(elf32_mips_irix_compat (abfd) != ict_none)
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
comment|/* In case we're on a 32-bit machine, construct a 64-bit "-1" value    from smaller values.  Start with zero, widen, *then* decrement.  */
end_comment

begin_define
define|#
directive|define
name|MINUS_ONE
value|(((bfd_vma)0) - 1)
end_define

begin_comment
comment|/* The relocation table used for SHT_REL sections.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_howto_table_rel
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
comment|/* This needs complex overflow 				   detection, because the upper four 				   bits must match the PC + 4.  */
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
name|_bfd_mips_elf32_gprel16_reloc
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
name|_bfd_mips_elf32_gprel16_reloc
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
name|mips_elf_gprel32_reloc
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
comment|/* The remaining relocs are defined on Irix 5, although they are      not defined by the ABI.  */
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
comment|/* A 64 bit relocation.  */
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
name|mips32_64bit_reloc
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
comment|/* 64 bit subtraction.  Used in the N32 ABI.  */
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
comment|/* Used to cause the linker to insert and delete instructions?  */
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_INSERT_A
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_INSERT_B
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_DELETE
argument_list|)
block|,
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
comment|/* Section displacement.  */
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
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_REL16
argument_list|)
block|,
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
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_RELGOT
argument_list|)
block|,
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
literal|0x00000000
argument_list|,
comment|/* src_mask */
literal|0x00000000
argument_list|,
comment|/* dst_mask */
name|FALSE
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* TLS GD/LD dynamic relocations.  */
name|HOWTO
argument_list|(
name|R_MIPS_TLS_DTPMOD32
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
literal|"R_MIPS_TLS_DTPMOD32"
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
name|R_MIPS_TLS_DTPREL32
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
literal|"R_MIPS_TLS_DTPREL32"
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
name|R_MIPS_TLS_DTPMOD64
argument_list|)
block|,
name|EMPTY_HOWTO
argument_list|(
name|R_MIPS_TLS_DTPREL64
argument_list|)
block|,
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
name|HOWTO
argument_list|(
name|R_MIPS_TLS_TPREL32
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
literal|"R_MIPS_TLS_TPREL32"
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

begin_comment
comment|/* The reloc used for BFD_RELOC_CTOR when doing a 64 bit link.  This    is a hack to make the linker think that we need 64 bit values.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_ctor64_howto
init|=
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
literal|32
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
name|mips32_64bit_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_64"
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips16_howto_table_rel
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
literal|0xffff
argument_list|,
comment|/* src_mask */
literal|0xffff
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
comment|/* 32 bit pc-relative.  This was a GNU extension used by embedded-PIC.    It was co-opted by mips-linux for exception-handling data.  It is no    longer used, but should continue to be supported by the linker for    backward compatibility.  (GCC stopped using it in May, 2004.)  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf_mips_gnu_pcrel32
init|=
name|HOWTO
argument_list|(
name|R_MIPS_PC32
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
name|_bfd_mips_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_PC32"
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

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

begin_comment
comment|/* Set the GP value for OUTPUT_BFD.  Returns FALSE if this is a    dangerous relocation.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf_assign_gp
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
name|mips_elf_final_gp
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
operator|+
literal|0x4000
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
name|mips_elf_assign_gp
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
comment|/* Do a R_MIPS_GPREL16 relocation.  This is a 16 bit value which must    become the offset from the gp register.  This function also handles    R_MIPS_LITERAL relocations, although those can be handled more    cleverly because the entries in the .lit8 and .lit4 sections can be    merged.  */
end_comment

begin_function
name|bfd_reloc_status_type
name|_bfd_mips_elf32_gprel16_reloc
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
name|reloc_entry
operator|->
name|howto
operator|->
name|type
operator|==
name|R_MIPS_LITERAL
operator|&&
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
name|mips_elf_final_gp
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
name|mips_elf_gprel32_reloc
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
name|mips_elf_final_gp
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
name|gprel32_with_gp
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

begin_function
specifier|static
name|bfd_reloc_status_type
name|gprel32_with_gp
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|asymbol
modifier|*
name|symbol
parameter_list|,
name|arelent
modifier|*
name|reloc_entry
parameter_list|,
name|asection
modifier|*
name|input_section
parameter_list|,
name|bfd_boolean
name|relocatable
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|bfd_vma
name|gp
parameter_list|)
block|{
name|bfd_vma
name|relocation
decl_stmt|;
name|bfd_vma
name|val
decl_stmt|;
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
comment|/* Handle a 64 bit reloc in a 32 bit MIPS ELF file.  These are    generated when addresses are 64 bits.  The upper 32 bits are a simple    sign extension.  */
end_comment

begin_function
specifier|static
name|bfd_reloc_status_type
name|mips32_64bit_reloc
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
name|ATTRIBUTE_UNUSED
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
name|bfd_reloc_status_type
name|r
decl_stmt|;
name|arelent
name|reloc32
decl_stmt|;
name|unsigned
name|long
name|val
decl_stmt|;
name|bfd_size_type
name|addr
decl_stmt|;
comment|/* Do a normal 32 bit relocation on the lower 32 bits.  */
name|reloc32
operator|=
operator|*
name|reloc_entry
expr_stmt|;
if|if
condition|(
name|bfd_big_endian
argument_list|(
name|abfd
argument_list|)
condition|)
name|reloc32
operator|.
name|address
operator|+=
literal|4
expr_stmt|;
name|reloc32
operator|.
name|howto
operator|=
operator|&
name|elf_mips_howto_table_rel
index|[
name|R_MIPS_32
index|]
expr_stmt|;
name|r
operator|=
name|bfd_perform_relocation
argument_list|(
name|abfd
argument_list|,
operator|&
name|reloc32
argument_list|,
name|data
argument_list|,
name|input_section
argument_list|,
name|output_bfd
argument_list|,
name|error_message
argument_list|)
expr_stmt|;
comment|/* Sign extend into the upper 32 bits.  */
name|val
operator|=
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
name|reloc32
operator|.
name|address
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|val
operator|&
literal|0x80000000
operator|)
operator|!=
literal|0
condition|)
name|val
operator|=
literal|0xffffffff
expr_stmt|;
else|else
name|val
operator|=
literal|0
expr_stmt|;
name|addr
operator|=
name|reloc_entry
operator|->
name|address
expr_stmt|;
if|if
condition|(
name|bfd_little_endian
argument_list|(
name|abfd
argument_list|)
condition|)
name|addr
operator|+=
literal|4
expr_stmt|;
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
name|addr
argument_list|)
expr_stmt|;
return|return
name|r
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
name|mips_elf_final_gp
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
name|BFD_RELOC_GPREL16
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
name|BFD_RELOC_16_PCREL_S2
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
name|BFD_RELOC_GPREL32
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
name|bfd_elf32_bfd_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|bfd_reloc_code_real_type
name|code
parameter_list|)
block|{
name|unsigned
name|int
name|i
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto_table
init|=
name|elf_mips_howto_table_rel
decl_stmt|;
name|reloc_howto_type
modifier|*
name|howto16_table
init|=
name|elf_mips16_howto_table_rel
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
default|default:
name|bfd_set_error
argument_list|(
name|bfd_error_bad_value
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
case|case
name|BFD_RELOC_CTOR
case|:
comment|/* We need to handle BFD_RELOC_CTOR specially. 	 Select the right relocation (R_MIPS_32 or R_MIPS_64) based on the 	 size of addresses of the ABI.  */
if|if
condition|(
operator|(
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
operator|->
name|e_flags
operator|&
operator|(
name|E_MIPS_ABI_O64
operator||
name|E_MIPS_ABI_EABI64
operator|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|&
name|elf_mips_ctor64_howto
return|;
else|else
return|return
operator|&
name|howto_table
index|[
operator|(
name|int
operator|)
name|R_MIPS_32
index|]
return|;
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
case|case
name|BFD_RELOC_32_PCREL
case|:
return|return
operator|&
name|elf_mips_gnu_pcrel32
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|bfd_elf32_bfd_reloc_name_lookup
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
name|elf_mips_howto_table_rel
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf_mips_howto_table_rel
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
name|elf_mips_howto_table_rel
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
name|elf_mips_howto_table_rel
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
name|elf_mips_howto_table_rel
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
name|elf_mips16_howto_table_rel
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|elf_mips16_howto_table_rel
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
name|elf_mips16_howto_table_rel
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
name|elf_mips16_howto_table_rel
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
name|elf_mips16_howto_table_rel
index|[
name|i
index|]
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|elf_mips_gnu_pcrel32
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
name|elf_mips_gnu_pcrel32
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
name|mips_elf32_rtype_to_howto
parameter_list|(
name|unsigned
name|int
name|r_type
parameter_list|,
name|bfd_boolean
name|rela_p
name|ATTRIBUTE_UNUSED
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
return|return
operator|&
name|elf_mips_gnu_rel16_s2
return|;
case|case
name|R_MIPS_PC32
case|:
return|return
operator|&
name|elf_mips_gnu_pcrel32
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
return|return
operator|&
name|elf_mips16_howto_table_rel
index|[
name|r_type
operator|-
name|R_MIPS16_min
index|]
return|;
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
return|return
operator|&
name|elf_mips_howto_table_rel
index|[
name|r_type
index|]
return|;
block|}
block|}
end_function

begin_comment
comment|/* Given a MIPS Elf_Internal_Rel, fill in an arelent structure.  */
end_comment

begin_function
specifier|static
name|void
name|mips_info_to_howto_rel
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
specifier|const
name|struct
name|elf_backend_data
modifier|*
name|bed
decl_stmt|;
name|unsigned
name|int
name|r_type
decl_stmt|;
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|dst
operator|->
name|r_info
argument_list|)
expr_stmt|;
name|bed
operator|=
name|get_elf_backend_data
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
name|cache_ptr
operator|->
name|howto
operator|=
name|bed
operator|->
name|elf_backend_mips_rtype_to_howto
argument_list|(
name|r_type
argument_list|,
name|FALSE
argument_list|)
expr_stmt|;
comment|/* The addend for a GPREL16 or LITERAL relocation comes from the GP      value for the object file.  We get the addend now, rather than      when we do the relocation, because the symbol manipulations done      by the linker may cause us to lose track of the input BFD.  */
if|if
condition|(
operator|(
operator|(
operator|*
name|cache_ptr
operator|->
name|sym_ptr_ptr
operator|)
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|!=
literal|0
operator|&&
operator|(
name|r_type
operator|==
operator|(
name|unsigned
name|int
operator|)
name|R_MIPS_GPREL16
operator|||
name|r_type
operator|==
operator|(
name|unsigned
name|int
operator|)
name|R_MIPS_LITERAL
operator|)
condition|)
name|cache_ptr
operator|->
name|addend
operator|=
name|elf_gp
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Given a MIPS Elf_Internal_Rela, fill in an arelent structure.  */
end_comment

begin_function
specifier|static
name|void
name|mips_info_to_howto_rela
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|arelent
modifier|*
name|cache_ptr
parameter_list|,
name|Elf_Internal_Rela
modifier|*
name|dst
parameter_list|)
block|{
name|mips_info_to_howto_rel
argument_list|(
name|abfd
argument_list|,
name|cache_ptr
argument_list|,
name|dst
argument_list|)
expr_stmt|;
comment|/* If we ever need to do any extra processing with dst->r_addend      (the field omitted in an Elf_Internal_Rel) we can do it here.  */
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Determine whether a symbol is global for the purposes of splitting    the symbol table into global symbols and local symbols.  At least    on Irix 5, this split must be between section symbols and all other    symbols.  On most ELF targets the split is between static symbols    and externally visible symbols.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf_sym_is_global
parameter_list|(
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
parameter_list|,
name|asymbol
modifier|*
name|sym
parameter_list|)
block|{
if|if
condition|(
name|SGI_COMPAT
argument_list|(
name|abfd
argument_list|)
condition|)
return|return
operator|(
name|sym
operator|->
name|flags
operator|&
name|BSF_SECTION_SYM
operator|)
operator|==
literal|0
return|;
else|else
return|return
operator|(
operator|(
name|sym
operator|->
name|flags
operator|&
operator|(
name|BSF_GLOBAL
operator||
name|BSF_WEAK
operator|)
operator|)
operator|!=
literal|0
operator|||
name|bfd_is_und_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
operator|||
name|bfd_is_com_section
argument_list|(
name|bfd_get_section
argument_list|(
name|sym
argument_list|)
argument_list|)
operator|)
return|;
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
name|mips_elf32_object_p
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
comment|/* Irix 5 and 6 are broken.  Object file symbol tables are not always      sorted correctly such that local symbols precede global symbols,      and the sh_info field in the symbol table is not always right.  */
if|if
condition|(
name|SGI_COMPAT
argument_list|(
name|abfd
argument_list|)
condition|)
name|elf_bad_symtab
argument_list|(
name|abfd
argument_list|)
operator|=
name|TRUE
expr_stmt|;
if|if
condition|(
name|ABI_N32_P
argument_list|(
name|abfd
argument_list|)
condition|)
return|return
name|FALSE
return|;
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

begin_escape
end_escape

begin_comment
comment|/* MIPS ELF local labels start with '$', not 'L'.  */
end_comment

begin_function
specifier|static
name|bfd_boolean
name|mips_elf_is_local_label_name
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
block|{
if|if
condition|(
name|name
index|[
literal|0
index|]
operator|==
literal|'$'
condition|)
return|return
name|TRUE
return|;
comment|/* On Irix 6, the labels go back to starting with '.', so we accept      the generic ELF local label syntax as well.  */
return|return
name|_bfd_elf_is_local_label_name
argument_list|(
name|abfd
argument_list|,
name|name
argument_list|)
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
name|elf32_mips_grok_prstatus
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
literal|256
case|:
comment|/* Linux/MIPS */
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
literal|24
argument_list|)
expr_stmt|;
comment|/* pr_reg */
name|offset
operator|=
literal|72
expr_stmt|;
name|size
operator|=
literal|180
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
name|elf32_mips_grok_psinfo
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
literal|128
case|:
comment|/* Linux/MIPS elf_prpsinfo */
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
literal|32
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
literal|48
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
comment|/* Depending on the target vector we generate some version of Irix    executables or "normal" MIPS ELF ABI executables.  */
end_comment

begin_function
specifier|static
name|irix_compat_t
name|elf32_mips_irix_compat
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
name|bfd_elf32_bigmips_vec
operator|)
operator|||
operator|(
name|abfd
operator|->
name|xvec
operator|==
operator|&
name|bfd_elf32_littlemips_vec
operator|)
condition|)
return|return
name|ict_irix5
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
comment|/* ECOFF swapping routines.  These are used when dealing with the    .mdebug section, which is in the ECOFF debugging format.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|ecoff_debug_swap
name|mips_elf32_ecoff_debug_swap
init|=
block|{
comment|/* Symbol table magic number.  */
name|magicSym
block|,
comment|/* Alignment of debugging information.  E.g., 4.  */
literal|4
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
value|mips_info_to_howto_rela
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|mips_info_to_howto_rel
end_define

begin_define
define|#
directive|define
name|elf_backend_sym_is_global
value|mips_elf_sym_is_global
end_define

begin_define
define|#
directive|define
name|elf_backend_object_p
value|mips_elf32_object_p
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
name|elf_backend_grok_prstatus
value|elf32_mips_grok_prstatus
end_define

begin_define
define|#
directive|define
name|elf_backend_grok_psinfo
value|elf32_mips_grok_psinfo
end_define

begin_define
define|#
directive|define
name|elf_backend_ecoff_debug_swap
value|&mips_elf32_ecoff_debug_swap
end_define

begin_define
define|#
directive|define
name|elf_backend_got_header_size
value|(4 * MIPS_RESERVED_GOTNO)
end_define

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
value|0
end_define

begin_define
define|#
directive|define
name|elf_backend_default_use_rela_p
value|0
end_define

begin_define
define|#
directive|define
name|elf_backend_sign_extend_vma
value|TRUE
end_define

begin_define
define|#
directive|define
name|elf_backend_discard_info
value|_bfd_mips_elf_discard_info
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
value|elf32_mips_irix_compat
end_define

begin_define
define|#
directive|define
name|elf_backend_mips_rtype_to_howto
value|mips_elf32_rtype_to_howto
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_is_local_label_name
define|\
value|mips_elf_is_local_label_name
end_define

begin_define
define|#
directive|define
name|bfd_elf32_find_nearest_line
value|_bfd_mips_elf_find_nearest_line
end_define

begin_define
define|#
directive|define
name|bfd_elf32_find_inliner_info
value|_bfd_mips_elf_find_inliner_info
end_define

begin_define
define|#
directive|define
name|bfd_elf32_new_section_hook
value|_bfd_mips_elf_new_section_hook
end_define

begin_define
define|#
directive|define
name|bfd_elf32_set_section_contents
value|_bfd_mips_elf_set_section_contents
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_get_relocated_section_contents
define|\
value|_bfd_elf_mips_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_create
define|\
value|_bfd_mips_elf_link_hash_table_create
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_final_link
value|_bfd_mips_elf_final_link
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_merge_private_bfd_data
define|\
value|_bfd_mips_elf_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_set_private_flags
value|_bfd_mips_elf_set_private_flags
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_print_private_bfd_data
define|\
value|_bfd_mips_elf_print_private_bfd_data
end_define

begin_comment
comment|/* Support for SGI-ish mips targets.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_littlemips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-littlemips"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_bigmips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-bigmips"
end_define

begin_comment
comment|/* The SVR4 MIPS ABI says that this should be 0x10000, but Irix 5 uses    a value of 0x1000, and we are compatible.  */
end_comment

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1000
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
file|"elf32-target.h"
end_include

begin_comment
comment|/* Support for traditional mips targets.  */
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
value|bfd_elf32_tradlittlemips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-tradlittlemips"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_tradbigmips_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-tradbigmips"
end_define

begin_comment
comment|/* The MIPS ABI says at Page 5-1:    Virtual addresses and file offsets for MIPS segments are congruent    modulo 64 KByte (0x10000) or larger powers of 2.  Because 64 KBytes    is the maximum page size, the files are suitable for paging    regardless of physical page size.  */
end_comment

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
name|elf32_bed
value|elf32_tradbed
end_define

begin_comment
comment|/* Include the target file again for this target.  */
end_comment

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

begin_comment
comment|/* Specific to VxWorks.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips_vxworks_copy_howto_rela
init|=
name|HOWTO
argument_list|(
name|R_MIPS_COPY
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_COPY"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0x0
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
comment|/* Specific to VxWorks.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|mips_vxworks_jump_slot_howto_rela
init|=
name|HOWTO
argument_list|(
name|R_MIPS_JUMP_SLOT
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_MIPS_JUMP_SLOT"
argument_list|,
comment|/* name */
name|FALSE
argument_list|,
comment|/* partial_inplace */
literal|0x0
argument_list|,
comment|/* src_mask */
literal|0x0
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
comment|/* Implement elf_backend_bfd_reloc_type_lookup for VxWorks.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mips_vxworks_bfd_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
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
name|BFD_RELOC_MIPS_COPY
case|:
return|return
operator|&
name|mips_vxworks_copy_howto_rela
return|;
case|case
name|BFD_RELOC_MIPS_JUMP_SLOT
case|:
return|return
operator|&
name|mips_vxworks_jump_slot_howto_rela
return|;
default|default:
return|return
name|bfd_elf32_bfd_reloc_type_lookup
argument_list|(
name|abfd
argument_list|,
name|code
argument_list|)
return|;
block|}
block|}
end_function

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mips_vxworks_bfd_reloc_name_lookup
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|r_name
parameter_list|)
block|{
if|if
condition|(
name|strcasecmp
argument_list|(
name|mips_vxworks_copy_howto_rela
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
name|mips_vxworks_copy_howto_rela
return|;
if|if
condition|(
name|strcasecmp
argument_list|(
name|mips_vxworks_jump_slot_howto_rela
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
name|mips_vxworks_jump_slot_howto_rela
return|;
return|return
name|bfd_elf32_bfd_reloc_name_lookup
argument_list|(
name|abfd
argument_list|,
name|r_name
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Implement elf_backend_mips_rtype_to_lookup for VxWorks.  */
end_comment

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|mips_vxworks_rtype_to_howto
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
name|R_MIPS_COPY
case|:
return|return
operator|&
name|mips_vxworks_copy_howto_rela
return|;
case|case
name|R_MIPS_JUMP_SLOT
case|:
return|return
operator|&
name|mips_vxworks_jump_slot_howto_rela
return|;
default|default:
return|return
name|mips_elf32_rtype_to_howto
argument_list|(
name|r_type
argument_list|,
name|rela_p
argument_list|)
return|;
block|}
block|}
end_function

begin_comment
comment|/* Implement elf_backend_final_write_processing for VxWorks.  */
end_comment

begin_function
specifier|static
name|void
name|mips_vxworks_final_write_processing
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
name|bfd_boolean
name|linker
parameter_list|)
block|{
name|_bfd_mips_elf_final_write_processing
argument_list|(
name|abfd
argument_list|,
name|linker
argument_list|)
expr_stmt|;
name|elf_vxworks_final_write_processing
argument_list|(
name|abfd
argument_list|,
name|linker
argument_list|)
expr_stmt|;
block|}
end_function

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
value|bfd_elf32_littlemips_vxworks_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-littlemips-vxworks"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_bigmips_vxworks_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-bigmips-vxworks"
end_define

begin_undef
undef|#
directive|undef
name|elf32_bed
end_undef

begin_define
define|#
directive|define
name|elf32_bed
value|elf32_mips_vxworks_bed
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
name|ELF_COMMONPAGESIZE
value|0x1000
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_want_got_plt
end_undef

begin_define
define|#
directive|define
name|elf_backend_want_got_plt
value|1
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_want_plt_sym
end_undef

begin_define
define|#
directive|define
name|elf_backend_want_plt_sym
value|1
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_got_symbol_offset
end_undef

begin_define
define|#
directive|define
name|elf_backend_got_symbol_offset
value|0
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_want_dynbss
end_undef

begin_define
define|#
directive|define
name|elf_backend_want_dynbss
value|1
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_may_use_rel_p
end_undef

begin_define
define|#
directive|define
name|elf_backend_may_use_rel_p
value|0
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_may_use_rela_p
end_undef

begin_define
define|#
directive|define
name|elf_backend_may_use_rela_p
value|1
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_default_use_rela_p
end_undef

begin_define
define|#
directive|define
name|elf_backend_default_use_rela_p
value|1
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_got_header_size
end_undef

begin_define
define|#
directive|define
name|elf_backend_got_header_size
value|(4 * 3)
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_plt_readonly
end_undef

begin_define
define|#
directive|define
name|elf_backend_plt_readonly
value|1
end_define

begin_undef
undef|#
directive|undef
name|bfd_elf32_bfd_reloc_type_lookup
end_undef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_type_lookup
define|\
value|mips_vxworks_bfd_reloc_type_lookup
end_define

begin_undef
undef|#
directive|undef
name|bfd_elf32_bfd_reloc_name_lookup
end_undef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_reloc_name_lookup
define|\
value|mips_vxworks_bfd_reloc_name_lookup
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_mips_rtype_to_howto
end_undef

begin_define
define|#
directive|define
name|elf_backend_mips_rtype_to_howto
define|\
value|mips_vxworks_rtype_to_howto
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_adjust_dynamic_symbol
end_undef

begin_define
define|#
directive|define
name|elf_backend_adjust_dynamic_symbol
define|\
value|_bfd_mips_vxworks_adjust_dynamic_symbol
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_finish_dynamic_symbol
end_undef

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_symbol
define|\
value|_bfd_mips_vxworks_finish_dynamic_symbol
end_define

begin_undef
undef|#
directive|undef
name|bfd_elf32_bfd_link_hash_table_create
end_undef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_create
define|\
value|_bfd_mips_vxworks_link_hash_table_create
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_add_symbol_hook
end_undef

begin_define
define|#
directive|define
name|elf_backend_add_symbol_hook
define|\
value|elf_vxworks_add_symbol_hook
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_link_output_symbol_hook
end_undef

begin_define
define|#
directive|define
name|elf_backend_link_output_symbol_hook
define|\
value|elf_vxworks_link_output_symbol_hook
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_emit_relocs
end_undef

begin_define
define|#
directive|define
name|elf_backend_emit_relocs
define|\
value|elf_vxworks_emit_relocs
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_final_write_processing
end_undef

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
define|\
value|mips_vxworks_final_write_processing
end_define

begin_undef
undef|#
directive|undef
name|elf_backend_additional_program_headers
end_undef

begin_undef
undef|#
directive|undef
name|elf_backend_modify_segment_map
end_undef

begin_undef
undef|#
directive|undef
name|elf_backend_symbol_processing
end_undef

begin_comment
comment|/* NOTE: elf_backend_rela_normal is not defined for MIPS.  */
end_comment

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

