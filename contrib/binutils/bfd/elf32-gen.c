begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic support for 32-bit ELF    Copyright 1993 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* This does not include any relocations, but should be good enough    for GDB to read the file.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_little_generic_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-little"
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_big_generic_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-big"
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
name|bfd_elf32_bfd_reloc_type_lookup
value|bfd_default_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|elf_info_to_howto
value|_bfd_elf_no_info_to_howto
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

