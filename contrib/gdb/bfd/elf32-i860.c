begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel 860 specific support for 32-bit ELF    Copyright 1993 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|TARGET_BIG_SYM
value|bfd_elf32_i860_vec
end_define

begin_define
define|#
directive|define
name|TARGET_BIG_NAME
value|"elf32-i860"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_i860
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_860
end_define

begin_include
include|#
directive|include
file|"elf32-target.h"
end_include

end_unit

