begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic support for 64-bit ELF    Copyright 1993, 1995, 1998 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"elf-bfd.h"
end_include

begin_comment
comment|/* This does not include any relocation information, but should be    good enough for GDB or objdump to read the file.  */
end_comment

begin_decl_stmt
specifier|static
name|reloc_howto_type
name|dummy
init|=
name|HOWTO
argument_list|(
literal|0
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
name|NULL
argument_list|,
comment|/* special_function */
literal|"UNKNOWN"
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

begin_function
specifier|static
name|void
name|elf_generic_info_to_howto
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
decl_stmt|;
name|arelent
modifier|*
name|bfd_reloc
decl_stmt|;
name|Elf64_Internal_Rela
modifier|*
name|elf_reloc
decl_stmt|;
block|{
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|dummy
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|elf_generic_info_to_howto_rel
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
decl_stmt|;
name|arelent
modifier|*
name|bfd_reloc
decl_stmt|;
name|Elf64_Internal_Rel
modifier|*
name|elf_reloc
decl_stmt|;
block|{
name|bfd_reloc
operator|->
name|howto
operator|=
operator|&
name|dummy
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf64_little_generic_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf64-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf64_big_generic_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf64-big"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_unknown
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_NONE
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1
end_define

begin_define
define|#
directive|define
name|bfd_elf64_bfd_reloc_type_lookup
value|bfd_default_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|elf_generic_info_to_howto
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|elf_generic_info_to_howto_rel
end_define

begin_include
include|#
directive|include
file|"elf64-target.h"
end_include

end_unit

