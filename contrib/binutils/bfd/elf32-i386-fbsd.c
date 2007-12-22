begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Intel IA-32 specific support for 32-bit ELF on FreeBSD.    Copyright 2002 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LITTLE_SYM
value|bfd_elf32_i386_freebsd_vec
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_NAME
value|"elf32-i386-freebsd"
end_define

begin_define
define|#
directive|define
name|ELF_ARCH
value|bfd_arch_i386
end_define

begin_define
define|#
directive|define
name|ELF_MACHINE_CODE
value|EM_386
end_define

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|0x1000
end_define

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
file|"elf-bfd.h"
end_include

begin_comment
comment|/* The kernel recognizes executables as valid only if they carry a    "FreeBSD" label in the ELF header.  So we put this label on all    executables and (for simplicity) also all other object files.  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|elf_i386_post_process_headers
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|elf_i386_post_process_headers
parameter_list|(
name|abfd
parameter_list|,
name|link_info
parameter_list|)
name|bfd
modifier|*
name|abfd
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|link_info
name|ATTRIBUTE_UNUSED
decl_stmt|;
block|{
name|Elf_Internal_Ehdr
modifier|*
name|i_ehdrp
decl_stmt|;
comment|/* ELF file header, internal form.  */
name|i_ehdrp
operator|=
name|elf_elfheader
argument_list|(
name|abfd
argument_list|)
expr_stmt|;
comment|/* Put an ABI label supported by FreeBSD>= 4.1.  */
name|i_ehdrp
operator|->
name|e_ident
index|[
name|EI_OSABI
index|]
operator|=
name|ELFOSABI_FREEBSD
expr_stmt|;
ifdef|#
directive|ifdef
name|OLD_FREEBSD_ABI_LABEL
comment|/* The ABI label supported by FreeBSD<= 4.0 is quite nonstandard.  */
name|memcpy
argument_list|(
operator|&
name|i_ehdrp
operator|->
name|e_ident
index|[
name|EI_ABIVERSION
index|]
argument_list|,
literal|"FreeBSD"
argument_list|,
literal|8
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|elf_backend_post_process_headers
value|elf_i386_post_process_headers
end_define

begin_include
include|#
directive|include
file|"elf32-i386.c"
end_include

end_unit

