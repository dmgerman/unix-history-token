begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Christos Zoulas 2003.  * All Rights Reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice immediately at the beginning of the file, without modification,  *    this list of conditions, and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *    * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * @(#)Id: readelf.h,v 1.9 2002/05/16 18:45:56 christos Exp  *  * Provide elf data structures for non-elf machines, allowing file  * non-elf hosts to determine if an elf binary is stripped.  * Note: cobbled from the linux header file, with modifications  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__fake_elf_h__
end_ifndef

begin_define
define|#
directive|define
name|__fake_elf_h__
end_define

begin_if
if|#
directive|if
name|HAVE_STDINT_H
end_if

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|Elf32_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|Elf32_Char
typedef|;
end_typedef

begin_if
if|#
directive|if
name|SIZEOF_UINT64_T
operator|!=
literal|8
end_if

begin_define
define|#
directive|define
name|USE_ARRAY_FOR_64BIT_TYPES
end_define

begin_typedef
typedef|typedef
name|uint32_t
name|Elf64_Addr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf64_Off
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf64_Xword
index|[
literal|2
index|]
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|Elf64_Xword
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint16_t
name|Elf64_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf64_Word
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|Elf64_Char
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EI_NIDENT
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
name|Elf32_Half
name|e_type
decl_stmt|;
name|Elf32_Half
name|e_machine
decl_stmt|;
name|Elf32_Word
name|e_version
decl_stmt|;
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point */
name|Elf32_Off
name|e_phoff
decl_stmt|;
name|Elf32_Off
name|e_shoff
decl_stmt|;
name|Elf32_Word
name|e_flags
decl_stmt|;
name|Elf32_Half
name|e_ehsize
decl_stmt|;
name|Elf32_Half
name|e_phentsize
decl_stmt|;
name|Elf32_Half
name|e_phnum
decl_stmt|;
name|Elf32_Half
name|e_shentsize
decl_stmt|;
name|Elf32_Half
name|e_shnum
decl_stmt|;
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
block|}
name|Elf32_Ehdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
name|Elf64_Half
name|e_type
decl_stmt|;
name|Elf64_Half
name|e_machine
decl_stmt|;
name|Elf64_Word
name|e_version
decl_stmt|;
name|Elf64_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point */
name|Elf64_Off
name|e_phoff
decl_stmt|;
name|Elf64_Off
name|e_shoff
decl_stmt|;
name|Elf64_Word
name|e_flags
decl_stmt|;
name|Elf64_Half
name|e_ehsize
decl_stmt|;
name|Elf64_Half
name|e_phentsize
decl_stmt|;
name|Elf64_Half
name|e_phnum
decl_stmt|;
name|Elf64_Half
name|e_shentsize
decl_stmt|;
name|Elf64_Half
name|e_shnum
decl_stmt|;
name|Elf64_Half
name|e_shstrndx
decl_stmt|;
block|}
name|Elf64_Ehdr
typedef|;
end_typedef

begin_comment
comment|/* e_type */
end_comment

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_comment
comment|/* sh_type */
end_comment

begin_define
define|#
directive|define
name|SHT_SYMTAB
value|2
end_define

begin_define
define|#
directive|define
name|SHT_NOTE
value|7
end_define

begin_define
define|#
directive|define
name|SHT_DYNSYM
value|11
end_define

begin_comment
comment|/* elf type */
end_comment

begin_define
define|#
directive|define
name|ELFDATANONE
value|0
end_define

begin_comment
comment|/* e_ident[EI_DATA] */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2LSB
value|1
end_define

begin_define
define|#
directive|define
name|ELFDATA2MSB
value|2
end_define

begin_comment
comment|/* elf class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASSNONE
value|0
end_define

begin_define
define|#
directive|define
name|ELFCLASS32
value|1
end_define

begin_define
define|#
directive|define
name|ELFCLASS64
value|2
end_define

begin_comment
comment|/* magic number */
end_comment

begin_define
define|#
directive|define
name|EI_MAG0
value|0
end_define

begin_comment
comment|/* e_ident[] indexes */
end_comment

begin_define
define|#
directive|define
name|EI_MAG1
value|1
end_define

begin_define
define|#
directive|define
name|EI_MAG2
value|2
end_define

begin_define
define|#
directive|define
name|EI_MAG3
value|3
end_define

begin_define
define|#
directive|define
name|EI_CLASS
value|4
end_define

begin_define
define|#
directive|define
name|EI_DATA
value|5
end_define

begin_define
define|#
directive|define
name|EI_VERSION
value|6
end_define

begin_define
define|#
directive|define
name|EI_PAD
value|7
end_define

begin_define
define|#
directive|define
name|ELFMAG0
value|0x7f
end_define

begin_comment
comment|/* EI_MAG */
end_comment

begin_define
define|#
directive|define
name|ELFMAG1
value|'E'
end_define

begin_define
define|#
directive|define
name|ELFMAG2
value|'L'
end_define

begin_define
define|#
directive|define
name|ELFMAG3
value|'F'
end_define

begin_define
define|#
directive|define
name|ELFMAG
value|"\177ELF"
end_define

begin_define
define|#
directive|define
name|OLFMAG1
value|'O'
end_define

begin_define
define|#
directive|define
name|OLFMAG
value|"\177OLF"
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
name|Elf32_Off
name|p_offset
decl_stmt|;
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
name|Elf32_Addr
name|p_paddr
decl_stmt|;
name|Elf32_Word
name|p_filesz
decl_stmt|;
name|Elf32_Word
name|p_memsz
decl_stmt|;
name|Elf32_Word
name|p_flags
decl_stmt|;
name|Elf32_Word
name|p_align
decl_stmt|;
block|}
name|Elf32_Phdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|p_type
decl_stmt|;
name|Elf64_Word
name|p_flags
decl_stmt|;
name|Elf64_Off
name|p_offset
decl_stmt|;
name|Elf64_Addr
name|p_vaddr
decl_stmt|;
name|Elf64_Addr
name|p_paddr
decl_stmt|;
name|Elf64_Xword
name|p_filesz
decl_stmt|;
name|Elf64_Xword
name|p_memsz
decl_stmt|;
name|Elf64_Xword
name|p_align
decl_stmt|;
block|}
name|Elf64_Phdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PT_NULL
value|0
end_define

begin_comment
comment|/* p_type */
end_comment

begin_define
define|#
directive|define
name|PT_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|PT_DYNAMIC
value|2
end_define

begin_define
define|#
directive|define
name|PT_INTERP
value|3
end_define

begin_define
define|#
directive|define
name|PT_NOTE
value|4
end_define

begin_define
define|#
directive|define
name|PT_SHLIB
value|5
end_define

begin_define
define|#
directive|define
name|PT_PHDR
value|6
end_define

begin_define
define|#
directive|define
name|PT_NUM
value|7
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|sh_name
decl_stmt|;
name|Elf32_Word
name|sh_type
decl_stmt|;
name|Elf32_Word
name|sh_flags
decl_stmt|;
name|Elf32_Addr
name|sh_addr
decl_stmt|;
name|Elf32_Off
name|sh_offset
decl_stmt|;
name|Elf32_Word
name|sh_size
decl_stmt|;
name|Elf32_Word
name|sh_link
decl_stmt|;
name|Elf32_Word
name|sh_info
decl_stmt|;
name|Elf32_Word
name|sh_addralign
decl_stmt|;
name|Elf32_Word
name|sh_entsize
decl_stmt|;
block|}
name|Elf32_Shdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|sh_name
decl_stmt|;
name|Elf64_Word
name|sh_type
decl_stmt|;
name|Elf64_Off
name|sh_flags
decl_stmt|;
name|Elf64_Addr
name|sh_addr
decl_stmt|;
name|Elf64_Off
name|sh_offset
decl_stmt|;
name|Elf64_Off
name|sh_size
decl_stmt|;
name|Elf64_Word
name|sh_link
decl_stmt|;
name|Elf64_Word
name|sh_info
decl_stmt|;
name|Elf64_Off
name|sh_addralign
decl_stmt|;
name|Elf64_Off
name|sh_entsize
decl_stmt|;
block|}
name|Elf64_Shdr
typedef|;
end_typedef

begin_comment
comment|/* Notes used in ET_CORE */
end_comment

begin_define
define|#
directive|define
name|NT_PRSTATUS
value|1
end_define

begin_define
define|#
directive|define
name|NT_PRFPREG
value|2
end_define

begin_define
define|#
directive|define
name|NT_PRPSINFO
value|3
end_define

begin_define
define|#
directive|define
name|NT_TASKSTRUCT
value|4
end_define

begin_define
define|#
directive|define
name|NT_NETBSD_CORE_PROCINFO
value|1
end_define

begin_comment
comment|/* Note header in a PT_NOTE section */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf_note
block|{
name|Elf32_Word
name|n_namesz
decl_stmt|;
comment|/* Name size */
name|Elf32_Word
name|n_descsz
decl_stmt|;
comment|/* Content size */
name|Elf32_Word
name|n_type
decl_stmt|;
comment|/* Content type */
block|}
name|Elf32_Nhdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Word
name|n_namesz
decl_stmt|;
name|Elf64_Word
name|n_descsz
decl_stmt|;
name|Elf64_Word
name|n_type
decl_stmt|;
block|}
name|Elf64_Nhdr
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NT_PRSTATUS
value|1
end_define

begin_define
define|#
directive|define
name|NT_PRFPREG
value|2
end_define

begin_define
define|#
directive|define
name|NT_PRPSINFO
value|3
end_define

begin_define
define|#
directive|define
name|NT_PRXREG
value|4
end_define

begin_define
define|#
directive|define
name|NT_PLATFORM
value|5
end_define

begin_define
define|#
directive|define
name|NT_AUXV
value|6
end_define

begin_comment
comment|/* Note types used in executables */
end_comment

begin_comment
comment|/* NetBSD executables (name = "NetBSD") */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NT_NETBSD_EMULATION
value|2
end_define

begin_define
define|#
directive|define
name|NT_FREEBSD_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NT_OPENBSD_VERSION
value|1
end_define

begin_comment
comment|/* GNU executables (name = "GNU") */
end_comment

begin_define
define|#
directive|define
name|NT_GNU_VERSION
value|1
end_define

begin_comment
comment|/* GNU OS tags */
end_comment

begin_define
define|#
directive|define
name|GNU_OS_LINUX
value|0
end_define

begin_define
define|#
directive|define
name|GNU_OS_HURD
value|1
end_define

begin_define
define|#
directive|define
name|GNU_OS_SOLARIS
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

