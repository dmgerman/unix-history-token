begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 32-bit ELF support for ARM new abi option.    Copyright 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"elf/arm.h"
end_include

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
file|"elf-bfd.h"
end_include

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
name|a
parameter_list|)
value|(sizeof (a) / (sizeof (a)[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|USE_REL
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_littlearm_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-littlearm"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_bigarm_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-bigarm"
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|0
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|elf32_arm_info_to_howto
end_define

begin_define
define|#
directive|define
name|ARM_ELF_ABI_VERSION
value|0
end_define

begin_define
define|#
directive|define
name|ARM_ELF_OS_ABI_VERSION
value|ELFOSABI_ARM
end_define

begin_decl_stmt
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_arm_reloc_type_lookup
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|bfd_reloc_code_real_type
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Note: code such as elf32_arm_reloc_type_lookup expect to use e.g.    R_ARM_PC24 as an index into this, and find the R_ARM_PC24 HOWTO    in that slot.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_arm_howto_table
index|[]
init|=
block|{
comment|/* No relocation */
name|HOWTO
argument_list|(
name|R_ARM_NONE
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
literal|"R_ARM_NONE"
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
name|R_ARM_PC24
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|24
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
literal|"R_ARM_PC24"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x00ffffff
argument_list|,
comment|/* src_mask */
literal|0x00ffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 32 bit absolute */
name|HOWTO
argument_list|(
name|R_ARM_ABS32
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
literal|"R_ARM_ABS32"
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
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* standard 32bit pc-relative reloc */
name|HOWTO
argument_list|(
name|R_ARM_REL32
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_REL32"
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
comment|/* 8 bit absolute */
name|HOWTO
argument_list|(
name|R_ARM_PC13
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_PC13"
argument_list|,
comment|/* name */
name|false
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
comment|/* 16 bit absolute */
name|HOWTO
argument_list|(
name|R_ARM_ABS16
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
literal|"R_ARM_ABS16"
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
comment|/* 12 bit absolute */
name|HOWTO
argument_list|(
name|R_ARM_ABS12
argument_list|,
comment|/* type */
literal|0
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|12
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
literal|"R_ARM_ABS12"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000008ff
argument_list|,
comment|/* src_mask */
literal|0x000008ff
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_ARM_THM_ABS5
argument_list|,
comment|/* type */
literal|6
argument_list|,
comment|/* rightshift */
literal|1
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|5
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
literal|"R_ARM_THM_ABS5"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000007e0
argument_list|,
comment|/* src_mask */
literal|0x000007e0
argument_list|,
comment|/* dst_mask */
name|false
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* 8 bit absolute */
name|HOWTO
argument_list|(
name|R_ARM_ABS8
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_ABS8"
argument_list|,
comment|/* name */
name|false
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
name|R_ARM_SBREL32
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
literal|"R_ARM_SBREL32"
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
name|R_ARM_THM_PC22
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|23
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
literal|"R_ARM_THM_PC22"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x07ff07ff
argument_list|,
comment|/* src_mask */
literal|0x07ff07ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_ARM_THM_PC8
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_THM_PC8"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_ARM_AMP_VCALL9
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_AMP_VCALL9"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
name|HOWTO
argument_list|(
name|R_ARM_SWI24
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_SWI24"
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
name|HOWTO
argument_list|(
name|R_ARM_THM_SWI8
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
name|complain_overflow_signed
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_SWI8"
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
comment|/* BLX instruction for the ARM.  */
name|HOWTO
argument_list|(
name|R_ARM_XPC25
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|25
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
literal|"R_ARM_XPC25"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x00ffffff
argument_list|,
comment|/* src_mask */
literal|0x00ffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* BLX instruction for the Thumb.  */
name|HOWTO
argument_list|(
name|R_ARM_THM_XPC22
argument_list|,
comment|/* type */
literal|2
argument_list|,
comment|/* rightshift */
literal|2
argument_list|,
comment|/* size (0 = byte, 1 = short, 2 = long) */
literal|22
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
literal|"R_ARM_THM_XPC22"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x07ff07ff
argument_list|,
comment|/* src_mask */
literal|0x07ff07ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* These next three relocs are not defined, but we need to fill the space.  */
name|HOWTO
argument_list|(
name|R_ARM_NONE
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
literal|"R_ARM_unknown_17"
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
name|R_ARM_NONE
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
literal|"R_ARM_unknown_18"
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
name|R_ARM_NONE
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
literal|"R_ARM_unknown_19"
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
comment|/* Relocs used in ARM Linux */
name|HOWTO
argument_list|(
name|R_ARM_COPY
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
literal|"R_ARM_COPY"
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
name|R_ARM_GLOB_DAT
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
literal|"R_ARM_GLOB_DAT"
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
name|R_ARM_JUMP_SLOT
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
literal|"R_ARM_JUMP_SLOT"
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
name|R_ARM_RELATIVE
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
literal|"R_ARM_RELATIVE"
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
name|R_ARM_GOTOFF
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
literal|"R_ARM_GOTOFF"
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
name|R_ARM_GOTPC
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
name|complain_overflow_bitfield
argument_list|,
comment|/* complain_on_overflow */
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_GOTPC"
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
name|HOWTO
argument_list|(
name|R_ARM_GOT32
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
literal|"R_ARM_GOT32"
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
name|R_ARM_PLT32
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
name|true
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
literal|"R_ARM_PLT32"
argument_list|,
comment|/* name */
name|true
argument_list|,
comment|/* partial_inplace */
literal|0x00ffffff
argument_list|,
comment|/* src_mask */
literal|0x00ffffff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
block|,
comment|/* pcrel_offset */
comment|/* End of relocs used in ARM Linux */
name|HOWTO
argument_list|(
name|R_ARM_RREL32
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
literal|"R_ARM_RREL32"
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
name|R_ARM_RABS32
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
literal|"R_ARM_RABS32"
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
name|R_ARM_RPC24
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
literal|"R_ARM_RPC24"
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
name|R_ARM_RBASE
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
literal|"R_ARM_RBASE"
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
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GNU extension to record C++ vtable hierarchy */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_arm_vtinherit_howto
init|=
name|HOWTO
argument_list|(
name|R_ARM_GNU_VTINHERIT
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
name|false
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
literal|"R_ARM_GNU_VTINHERIT"
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
comment|/* GNU extension to record C++ vtable member usage */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_arm_vtentry_howto
init|=
name|HOWTO
argument_list|(
name|R_ARM_GNU_VTENTRY
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
name|false
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
literal|"R_ARM_GNU_VTENTRY"
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
comment|/* 12 bit pc relative */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_arm_thm_pc11_howto
init|=
name|HOWTO
argument_list|(
name|R_ARM_THM_PC11
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
literal|"R_ARM_THM_PC11"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000007ff
argument_list|,
comment|/* src_mask */
literal|0x000007ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_comment
comment|/* 12 bit pc relative */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|elf32_arm_thm_pc9_howto
init|=
name|HOWTO
argument_list|(
name|R_ARM_THM_PC9
argument_list|,
comment|/* type */
literal|1
argument_list|,
comment|/* rightshift */
literal|1
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
name|bfd_elf_generic_reloc
argument_list|,
comment|/* special_function */
literal|"R_ARM_THM_PC9"
argument_list|,
comment|/* name */
name|false
argument_list|,
comment|/* partial_inplace */
literal|0x000000ff
argument_list|,
comment|/* src_mask */
literal|0x000000ff
argument_list|,
comment|/* dst_mask */
name|true
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcrel_offset */
end_comment

begin_function
specifier|static
name|void
name|elf32_arm_info_to_howto
parameter_list|(
name|abfd
parameter_list|,
name|bfd_reloc
parameter_list|,
name|elf_reloc
parameter_list|)
name|bfd
modifier|*
name|abfd
name|ATTRIBUTE_UNUSED
decl_stmt|;
name|arelent
modifier|*
name|bfd_reloc
decl_stmt|;
name|Elf32_Internal_Rel
modifier|*
name|elf_reloc
decl_stmt|;
block|{
name|unsigned
name|int
name|r_type
decl_stmt|;
name|r_type
operator|=
name|ELF32_R_TYPE
argument_list|(
name|elf_reloc
operator|->
name|r_info
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|r_type
condition|)
block|{
case|case
name|R_ARM_GNU_VTINHERIT
case|:
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|elf32_arm_vtinherit_howto
expr_stmt|;
break|break;
case|case
name|R_ARM_GNU_VTENTRY
case|:
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|elf32_arm_vtentry_howto
expr_stmt|;
break|break;
case|case
name|R_ARM_THM_PC11
case|:
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|elf32_arm_thm_pc11_howto
expr_stmt|;
break|break;
case|case
name|R_ARM_THM_PC9
case|:
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|elf32_arm_thm_pc9_howto
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|r_type
operator|>=
name|NUM_ELEM
argument_list|(
name|elf32_arm_howto_table
argument_list|)
condition|)
name|bfd_reloc
operator|->
name|howto
operator|=
name|NULL
expr_stmt|;
else|else
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|elf32_arm_howto_table
index|[
name|r_type
index|]
expr_stmt|;
break|break;
block|}
block|}
end_function

begin_struct
struct|struct
name|elf32_arm_reloc_map
block|{
name|bfd_reloc_code_real_type
name|bfd_reloc_val
decl_stmt|;
name|unsigned
name|char
name|elf_reloc_val
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf32_arm_reloc_map
name|elf32_arm_reloc_map
index|[]
init|=
block|{
block|{
name|BFD_RELOC_NONE
block|,
name|R_ARM_NONE
block|}
block|,
block|{
name|BFD_RELOC_ARM_PCREL_BRANCH
block|,
name|R_ARM_PC24
block|}
block|,
block|{
name|BFD_RELOC_ARM_PCREL_BLX
block|,
name|R_ARM_XPC25
block|}
block|,
block|{
name|BFD_RELOC_THUMB_PCREL_BLX
block|,
name|R_ARM_THM_XPC22
block|}
block|,
block|{
name|BFD_RELOC_32
block|,
name|R_ARM_ABS32
block|}
block|,
block|{
name|BFD_RELOC_32_PCREL
block|,
name|R_ARM_REL32
block|}
block|,
block|{
name|BFD_RELOC_8
block|,
name|R_ARM_ABS8
block|}
block|,
block|{
name|BFD_RELOC_16
block|,
name|R_ARM_ABS16
block|}
block|,
block|{
name|BFD_RELOC_ARM_OFFSET_IMM
block|,
name|R_ARM_ABS12
block|}
block|,
block|{
name|BFD_RELOC_ARM_THUMB_OFFSET
block|,
name|R_ARM_THM_ABS5
block|}
block|,
block|{
name|BFD_RELOC_THUMB_PCREL_BRANCH23
block|,
name|R_ARM_THM_PC22
block|}
block|,
block|{
name|BFD_RELOC_ARM_COPY
block|,
name|R_ARM_COPY
block|}
block|,
block|{
name|BFD_RELOC_ARM_GLOB_DAT
block|,
name|R_ARM_GLOB_DAT
block|}
block|,
block|{
name|BFD_RELOC_ARM_JUMP_SLOT
block|,
name|R_ARM_JUMP_SLOT
block|}
block|,
block|{
name|BFD_RELOC_ARM_RELATIVE
block|,
name|R_ARM_RELATIVE
block|}
block|,
block|{
name|BFD_RELOC_ARM_GOTOFF
block|,
name|R_ARM_GOTOFF
block|}
block|,
block|{
name|BFD_RELOC_ARM_GOTPC
block|,
name|R_ARM_GOTPC
block|}
block|,
block|{
name|BFD_RELOC_ARM_GOT32
block|,
name|R_ARM_GOT32
block|}
block|,
block|{
name|BFD_RELOC_ARM_PLT32
block|,
name|R_ARM_PLT32
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|reloc_howto_type
modifier|*
name|elf32_arm_reloc_type_lookup
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
name|unsigned
name|int
name|i
decl_stmt|;
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
name|elf32_arm_vtinherit_howto
return|;
case|case
name|BFD_RELOC_VTABLE_ENTRY
case|:
return|return
operator|&
name|elf32_arm_vtentry_howto
return|;
case|case
name|BFD_RELOC_THUMB_PCREL_BRANCH12
case|:
return|return
operator|&
name|elf32_arm_thm_pc11_howto
return|;
case|case
name|BFD_RELOC_THUMB_PCREL_BRANCH9
case|:
return|return
operator|&
name|elf32_arm_thm_pc9_howto
return|;
default|default:
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|NUM_ELEM
argument_list|(
name|elf32_arm_reloc_map
argument_list|)
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|elf32_arm_reloc_map
index|[
name|i
index|]
operator|.
name|bfd_reloc_val
operator|==
name|code
condition|)
return|return
operator|&
name|elf32_arm_howto_table
index|[
name|elf32_arm_reloc_map
index|[
name|i
index|]
operator|.
name|elf_reloc_val
index|]
return|;
return|return
name|NULL
return|;
block|}
block|}
end_function

begin_include
include|#
directive|include
file|"elf32-arm.h"
end_include

end_unit

