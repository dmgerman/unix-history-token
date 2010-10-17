begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Matsushita AM33/2.0 support for 32-bit GNU/Linux ELF    Copyright 2003    Free Software Foundation, Inc.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|elf_symbol_leading_char
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_am33lin_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-am33lin"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_mn10300
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_MN10300
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT1
value|EM_CYGNUS_MN10300
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1000
end_define

begin_comment
comment|/* Rename global functions.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_mn10300_elf_merge_private_bfd_data
value|_bfd_am33_elf_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|_bfd_mn10300_elf_object_p
value|_bfd_am33_elf_object_p
end_define

begin_define
define|#
directive|define
name|_bfd_mn10300_elf_final_write_processing
value|_bfd_am33_elf_final_write_processing
end_define

begin_include
include|#
directive|include
file|"elf-m10300.c"
end_include

end_unit

