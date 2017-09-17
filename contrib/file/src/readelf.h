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
name|Elf32_Word
name|a_type
decl_stmt|;
comment|/* 32-bit id */
name|Elf32_Word
name|a_v
decl_stmt|;
comment|/* 32-bit id */
block|}
name|Aux32Info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|a_type
decl_stmt|;
comment|/* 64-bit id */
name|Elf64_Xword
name|a_v
decl_stmt|;
comment|/* 64-bit id */
block|}
name|Aux64Info
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AT_NULL
value|0
end_define

begin_comment
comment|/* end of vector */
end_comment

begin_define
define|#
directive|define
name|AT_IGNORE
value|1
end_define

begin_comment
comment|/* entry should be ignored */
end_comment

begin_define
define|#
directive|define
name|AT_EXECFD
value|2
end_define

begin_comment
comment|/* file descriptor of program */
end_comment

begin_define
define|#
directive|define
name|AT_PHDR
value|3
end_define

begin_comment
comment|/* program headers for program */
end_comment

begin_define
define|#
directive|define
name|AT_PHENT
value|4
end_define

begin_comment
comment|/* size of program header entry */
end_comment

begin_define
define|#
directive|define
name|AT_PHNUM
value|5
end_define

begin_comment
comment|/* number of program headers */
end_comment

begin_define
define|#
directive|define
name|AT_PAGESZ
value|6
end_define

begin_comment
comment|/* system page size */
end_comment

begin_define
define|#
directive|define
name|AT_BASE
value|7
end_define

begin_comment
comment|/* base address of interpreter */
end_comment

begin_define
define|#
directive|define
name|AT_FLAGS
value|8
end_define

begin_comment
comment|/* flags */
end_comment

begin_define
define|#
directive|define
name|AT_ENTRY
value|9
end_define

begin_comment
comment|/* entry point of program */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_NOTELF
value|10
end_define

begin_comment
comment|/* program is not ELF */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_UID
value|11
end_define

begin_comment
comment|/* real uid */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_EUID
value|12
end_define

begin_comment
comment|/* effective uid */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_GID
value|13
end_define

begin_comment
comment|/* real gid */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_EGID
value|14
end_define

begin_comment
comment|/* effective gid */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_PLATFORM
value|15
end_define

begin_comment
comment|/* string identifying CPU for optimizations */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_HWCAP
value|16
end_define

begin_comment
comment|/* arch dependent hints at CPU capabilities */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_CLKTCK
value|17
end_define

begin_comment
comment|/* frequency at which times() increments */
end_comment

begin_comment
comment|/* AT_* values 18 through 22 are reserved */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_SECURE
value|23
end_define

begin_comment
comment|/* secure mode boolean */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_BASE_PLATFORM
value|24
end_define

begin_comment
comment|/* string identifying real platform, may                                  * differ from AT_PLATFORM. */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_RANDOM
value|25
end_define

begin_comment
comment|/* address of 16 random bytes */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_HWCAP2
value|26
end_define

begin_comment
comment|/* extension of AT_HWCAP */
end_comment

begin_define
define|#
directive|define
name|AT_LINUX_EXECFN
value|31
end_define

begin_comment
comment|/* filename of program */
end_comment

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
name|ET_REL
value|1
end_define

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_define
define|#
directive|define
name|ET_DYN
value|3
end_define

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_comment
comment|/* e_machine (used only for SunOS 5.x hardware capabilities) */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC
value|2
end_define

begin_define
define|#
directive|define
name|EM_386
value|3
end_define

begin_define
define|#
directive|define
name|EM_SPARC32PLUS
value|18
end_define

begin_define
define|#
directive|define
name|EM_SPARCV9
value|43
end_define

begin_define
define|#
directive|define
name|EM_IA_64
value|50
end_define

begin_define
define|#
directive|define
name|EM_AMD64
value|62
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

begin_define
define|#
directive|define
name|SHT_SUNW_cap
value|0x6ffffff5
end_define

begin_comment
comment|/* SunOS 5.x hw/sw capabilities */
end_comment

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

begin_define
define|#
directive|define
name|NT_NETBSD_CORE_PROCINFO
value|1
end_define

begin_define
define|#
directive|define
name|NT_NETBSD_CORE_AUXV
value|2
end_define

begin_struct
struct|struct
name|NetBSD_elfcore_procinfo
block|{
comment|/* Version 1 fields start here. */
name|uint32_t
name|cpi_version
decl_stmt|;
comment|/* our version */
name|uint32_t
name|cpi_cpisize
decl_stmt|;
comment|/* sizeof(this struct) */
name|uint32_t
name|cpi_signo
decl_stmt|;
comment|/* killing signal */
name|uint32_t
name|cpi_sigcode
decl_stmt|;
comment|/* signal code */
name|uint32_t
name|cpi_sigpend
index|[
literal|4
index|]
decl_stmt|;
comment|/* pending signals */
name|uint32_t
name|cpi_sigmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* blocked signals */
name|uint32_t
name|cpi_sigignore
index|[
literal|4
index|]
decl_stmt|;
comment|/* ignored signals */
name|uint32_t
name|cpi_sigcatch
index|[
literal|4
index|]
decl_stmt|;
comment|/* caught signals */
name|int32_t
name|cpi_pid
decl_stmt|;
comment|/* process ID */
name|int32_t
name|cpi_ppid
decl_stmt|;
comment|/* parent process ID */
name|int32_t
name|cpi_pgrp
decl_stmt|;
comment|/* process group ID */
name|int32_t
name|cpi_sid
decl_stmt|;
comment|/* session ID */
name|uint32_t
name|cpi_ruid
decl_stmt|;
comment|/* real user ID */
name|uint32_t
name|cpi_euid
decl_stmt|;
comment|/* effective user ID */
name|uint32_t
name|cpi_svuid
decl_stmt|;
comment|/* saved user ID */
name|uint32_t
name|cpi_rgid
decl_stmt|;
comment|/* real group ID */
name|uint32_t
name|cpi_egid
decl_stmt|;
comment|/* effective group ID */
name|uint32_t
name|cpi_svgid
decl_stmt|;
comment|/* saved group ID */
name|uint32_t
name|cpi_nlwps
decl_stmt|;
comment|/* number of LWPs */
name|int8_t
name|cpi_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* copy of p->p_comm */
comment|/* Add version 2 fields below here. */
name|int32_t
name|cpi_siglwp
decl_stmt|;
comment|/* LWP target of killing signal */
block|}
struct|;
end_struct

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
name|NT_PRXREG
value|4
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

begin_define
define|#
directive|define
name|NT_DRAGONFLY_VERSION
value|1
end_define

begin_comment
comment|/*  * GNU executables (name = "GNU")  * word[0]: GNU OS tags  * word[1]: major version  * word[2]: minor version  * word[3]: tiny version  */
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

begin_define
define|#
directive|define
name|GNU_OS_KFREEBSD
value|3
end_define

begin_define
define|#
directive|define
name|GNU_OS_KNETBSD
value|4
end_define

begin_comment
comment|/*  * GNU Hardware capability information   * word[0]: Number of entries  * word[1]: Bitmask of enabled entries  * Followed by a byte id, and a NUL terminated string per entry  */
end_comment

begin_define
define|#
directive|define
name|NT_GNU_HWCAP
value|2
end_define

begin_comment
comment|/*  * GNU Build ID generated by ld  * 160 bit SHA1 [default]   * 128 bit md5 or uuid  */
end_comment

begin_define
define|#
directive|define
name|NT_GNU_BUILD_ID
value|3
end_define

begin_comment
comment|/*  * NetBSD-specific note type: PaX.  * There should be 1 NOTE per executable.  * name: PaX\0  * namesz: 4  * desc:  *	word[0]: capability bitmask  * descsz: 4  */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX
value|3
end_define

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_MPROTECT
value|0x01
end_define

begin_comment
comment|/* Force enable Mprotect */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_NOMPROTECT
value|0x02
end_define

begin_comment
comment|/* Force disable Mprotect */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_GUARD
value|0x04
end_define

begin_comment
comment|/* Force enable Segvguard */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_NOGUARD
value|0x08
end_define

begin_comment
comment|/* Force disable Servguard */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_ASLR
value|0x10
end_define

begin_comment
comment|/* Force enable ASLR */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_PAX_NOASLR
value|0x20
end_define

begin_comment
comment|/* Force disable ASLR */
end_comment

begin_comment
comment|/*  * NetBSD-specific note type: MACHINE_ARCH.  * There should be 1 NOTE per executable.  * name:	NetBSD\0  * namesz:	7  * desc:	string  * descsz:	variable  */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_MARCH
value|5
end_define

begin_comment
comment|/*  * NetBSD-specific note type: COMPILER MODEL.  * There should be 1 NOTE per executable.  * name:	NetBSD\0  * namesz:	7  * desc:	string  * descsz:	variable  */
end_comment

begin_define
define|#
directive|define
name|NT_NETBSD_CMODEL
value|6
end_define

begin_comment
comment|/*  * FreeBSD specific notes  */
end_comment

begin_define
define|#
directive|define
name|NT_FREEBSD_PROCSTAT_AUXV
value|16
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ELFSIZE
argument_list|)
operator|&&
name|defined
argument_list|(
name|ARCH_ELFSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELFSIZE
value|ARCH_ELFSIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SunOS 5.x hardware/software capabilities */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|c_tag
decl_stmt|;
union|union
block|{
name|Elf32_Word
name|c_val
decl_stmt|;
name|Elf32_Addr
name|c_ptr
decl_stmt|;
block|}
name|c_un
union|;
block|}
name|Elf32_Cap
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|c_tag
decl_stmt|;
union|union
block|{
name|Elf64_Xword
name|c_val
decl_stmt|;
name|Elf64_Addr
name|c_ptr
decl_stmt|;
block|}
name|c_un
union|;
block|}
name|Elf64_Cap
typedef|;
end_typedef

begin_comment
comment|/* SunOS 5.x hardware/software capability tags */
end_comment

begin_define
define|#
directive|define
name|CA_SUNW_NULL
value|0
end_define

begin_define
define|#
directive|define
name|CA_SUNW_HW_1
value|1
end_define

begin_define
define|#
directive|define
name|CA_SUNW_SF_1
value|2
end_define

begin_comment
comment|/* SunOS 5.x software capabilities */
end_comment

begin_define
define|#
directive|define
name|SF1_SUNW_FPKNWN
value|0x01
end_define

begin_define
define|#
directive|define
name|SF1_SUNW_FPUSED
value|0x02
end_define

begin_define
define|#
directive|define
name|SF1_SUNW_MASK
value|0x03
end_define

begin_comment
comment|/* SunOS 5.x hardware capabilities: sparc */
end_comment

begin_define
define|#
directive|define
name|AV_SPARC_MUL32
value|0x0001
end_define

begin_define
define|#
directive|define
name|AV_SPARC_DIV32
value|0x0002
end_define

begin_define
define|#
directive|define
name|AV_SPARC_FSMULD
value|0x0004
end_define

begin_define
define|#
directive|define
name|AV_SPARC_V8PLUS
value|0x0008
end_define

begin_define
define|#
directive|define
name|AV_SPARC_POPC
value|0x0010
end_define

begin_define
define|#
directive|define
name|AV_SPARC_VIS
value|0x0020
end_define

begin_define
define|#
directive|define
name|AV_SPARC_VIS2
value|0x0040
end_define

begin_define
define|#
directive|define
name|AV_SPARC_ASI_BLK_INIT
value|0x0080
end_define

begin_define
define|#
directive|define
name|AV_SPARC_FMAF
value|0x0100
end_define

begin_define
define|#
directive|define
name|AV_SPARC_FJFMAU
value|0x4000
end_define

begin_define
define|#
directive|define
name|AV_SPARC_IMA
value|0x8000
end_define

begin_comment
comment|/* SunOS 5.x hardware capabilities: 386 */
end_comment

begin_define
define|#
directive|define
name|AV_386_FPU
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AV_386_TSC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|AV_386_CX8
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AV_386_SEP
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_SYSC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AV_386_CMOV
value|0x00000020
end_define

begin_define
define|#
directive|define
name|AV_386_MMX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_MMX
value|0x00000080
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_3DNow
value|0x00000100
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_3DNowx
value|0x00000200
end_define

begin_define
define|#
directive|define
name|AV_386_FXSR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|AV_386_SSE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|AV_386_SSE2
value|0x00001000
end_define

begin_define
define|#
directive|define
name|AV_386_PAUSE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|AV_386_SSE3
value|0x00004000
end_define

begin_define
define|#
directive|define
name|AV_386_MON
value|0x00008000
end_define

begin_define
define|#
directive|define
name|AV_386_CX16
value|0x00010000
end_define

begin_define
define|#
directive|define
name|AV_386_AHF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|AV_386_TSCP
value|0x00040000
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_SSE4A
value|0x00080000
end_define

begin_define
define|#
directive|define
name|AV_386_POPCNT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|AV_386_AMD_LZCNT
value|0x00200000
end_define

begin_define
define|#
directive|define
name|AV_386_SSSE3
value|0x00400000
end_define

begin_define
define|#
directive|define
name|AV_386_SSE4_1
value|0x00800000
end_define

begin_define
define|#
directive|define
name|AV_386_SSE4_2
value|0x01000000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

