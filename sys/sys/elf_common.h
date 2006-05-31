begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ELF_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ELF_COMMON_H_
value|1
end_define

begin_comment
comment|/*  * ELF definitions that are independent of architecture or word size.  */
end_comment

begin_comment
comment|/*  * Note header.  The ".note" section contains an array of notes.  Each  * begins with this header, aligned to a word boundary.  Immediately  * following the note header is n_namesz bytes of name, padded to the  * next word boundary.  Then comes n_descsz bytes of descriptor, again  * padded to a word boundary.  The values of n_namesz and n_descsz do  * not include the padding.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|n_namesz
decl_stmt|;
comment|/* Length of name. */
name|u_int32_t
name|n_descsz
decl_stmt|;
comment|/* Length of descriptor. */
name|u_int32_t
name|n_type
decl_stmt|;
comment|/* Type of this note. */
block|}
name|Elf_Note
typedef|;
end_typedef

begin_comment
comment|/* Indexes into the e_ident array.  Keep synced with    http://www.sco.com/developers/gabi/latest/ch4.eheader.html */
end_comment

begin_define
define|#
directive|define
name|EI_MAG0
value|0
end_define

begin_comment
comment|/* Magic number, byte 0. */
end_comment

begin_define
define|#
directive|define
name|EI_MAG1
value|1
end_define

begin_comment
comment|/* Magic number, byte 1. */
end_comment

begin_define
define|#
directive|define
name|EI_MAG2
value|2
end_define

begin_comment
comment|/* Magic number, byte 2. */
end_comment

begin_define
define|#
directive|define
name|EI_MAG3
value|3
end_define

begin_comment
comment|/* Magic number, byte 3. */
end_comment

begin_define
define|#
directive|define
name|EI_CLASS
value|4
end_define

begin_comment
comment|/* Class of machine. */
end_comment

begin_define
define|#
directive|define
name|EI_DATA
value|5
end_define

begin_comment
comment|/* Data format. */
end_comment

begin_define
define|#
directive|define
name|EI_VERSION
value|6
end_define

begin_comment
comment|/* ELF format version. */
end_comment

begin_define
define|#
directive|define
name|EI_OSABI
value|7
end_define

begin_comment
comment|/* Operating system / ABI identification */
end_comment

begin_define
define|#
directive|define
name|EI_ABIVERSION
value|8
end_define

begin_comment
comment|/* ABI version */
end_comment

begin_define
define|#
directive|define
name|OLD_EI_BRAND
value|8
end_define

begin_comment
comment|/* Start of architecture identification. */
end_comment

begin_define
define|#
directive|define
name|EI_PAD
value|9
end_define

begin_comment
comment|/* Start of padding (per SVR4 ABI). */
end_comment

begin_define
define|#
directive|define
name|EI_NIDENT
value|16
end_define

begin_comment
comment|/* Size of e_ident array. */
end_comment

begin_comment
comment|/* Values for the magic number bytes. */
end_comment

begin_define
define|#
directive|define
name|ELFMAG0
value|0x7f
end_define

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

begin_comment
comment|/* magic string */
end_comment

begin_define
define|#
directive|define
name|SELFMAG
value|4
end_define

begin_comment
comment|/* magic string size */
end_comment

begin_comment
comment|/* Values for e_ident[EI_VERSION] and e_version. */
end_comment

begin_define
define|#
directive|define
name|EV_NONE
value|0
end_define

begin_define
define|#
directive|define
name|EV_CURRENT
value|1
end_define

begin_comment
comment|/* Values for e_ident[EI_CLASS]. */
end_comment

begin_define
define|#
directive|define
name|ELFCLASSNONE
value|0
end_define

begin_comment
comment|/* Unknown class. */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS32
value|1
end_define

begin_comment
comment|/* 32-bit architecture. */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS64
value|2
end_define

begin_comment
comment|/* 64-bit architecture. */
end_comment

begin_comment
comment|/* Values for e_ident[EI_DATA]. */
end_comment

begin_define
define|#
directive|define
name|ELFDATANONE
value|0
end_define

begin_comment
comment|/* Unknown data format. */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2LSB
value|1
end_define

begin_comment
comment|/* 2's complement little-endian. */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2MSB
value|2
end_define

begin_comment
comment|/* 2's complement big-endian. */
end_comment

begin_comment
comment|/* Values for e_ident[EI_OSABI]. */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_NONE
value|0
end_define

begin_comment
comment|/* UNIX System V ABI */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_HPUX
value|1
end_define

begin_comment
comment|/* HP-UX operating system */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_NETBSD
value|2
end_define

begin_comment
comment|/* NetBSD */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_LINUX
value|3
end_define

begin_comment
comment|/* GNU/Linux */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_HURD
value|4
end_define

begin_comment
comment|/* GNU/Hurd */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_86OPEN
value|5
end_define

begin_comment
comment|/* 86Open common IA32 ABI */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_SOLARIS
value|6
end_define

begin_comment
comment|/* Solaris */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_AIX
value|7
end_define

begin_comment
comment|/* AIX */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_IRIX
value|8
end_define

begin_comment
comment|/* IRIX */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_FREEBSD
value|9
end_define

begin_comment
comment|/* FreeBSD */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_TRU64
value|10
end_define

begin_comment
comment|/* TRU64 UNIX */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_MODESTO
value|11
end_define

begin_comment
comment|/* Novell Modesto */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_OPENBSD
value|12
end_define

begin_comment
comment|/* OpenBSD */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_OPENVMS
value|13
end_define

begin_comment
comment|/* Open VMS */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_NSK
value|14
end_define

begin_comment
comment|/* HP Non-Stop Kernel */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_ARM
value|97
end_define

begin_comment
comment|/* ARM */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_STANDALONE
value|255
end_define

begin_comment
comment|/* Standalone (embedded) application */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_SYSV
value|ELFOSABI_NONE
end_define

begin_comment
comment|/* symbol used in old spec */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_MONTEREY
value|ELFOSABI_AIX
end_define

begin_comment
comment|/* Monterey */
end_comment

begin_comment
comment|/* e_ident */
end_comment

begin_define
define|#
directive|define
name|IS_ELF
parameter_list|(
name|ehdr
parameter_list|)
value|((ehdr).e_ident[EI_MAG0] == ELFMAG0&& \ 			 (ehdr).e_ident[EI_MAG1] == ELFMAG1&& \ 			 (ehdr).e_ident[EI_MAG2] == ELFMAG2&& \ 			 (ehdr).e_ident[EI_MAG3] == ELFMAG3)
end_define

begin_comment
comment|/* Values for e_type. */
end_comment

begin_define
define|#
directive|define
name|ET_NONE
value|0
end_define

begin_comment
comment|/* Unknown type. */
end_comment

begin_define
define|#
directive|define
name|ET_REL
value|1
end_define

begin_comment
comment|/* Relocatable. */
end_comment

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_comment
comment|/* Executable. */
end_comment

begin_define
define|#
directive|define
name|ET_DYN
value|3
end_define

begin_comment
comment|/* Shared object. */
end_comment

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_comment
comment|/* Core file. */
end_comment

begin_define
define|#
directive|define
name|ET_LOOS
value|0xfe00
end_define

begin_comment
comment|/* First operating system specific. */
end_comment

begin_define
define|#
directive|define
name|ET_HIOS
value|0xfeff
end_define

begin_comment
comment|/* Last operating system-specific. */
end_comment

begin_define
define|#
directive|define
name|ET_LOPROC
value|0xff00
end_define

begin_comment
comment|/* First processor-specific. */
end_comment

begin_define
define|#
directive|define
name|ET_HIPROC
value|0xffff
end_define

begin_comment
comment|/* Last processor-specific. */
end_comment

begin_comment
comment|/* Values for e_machine. */
end_comment

begin_define
define|#
directive|define
name|EM_NONE
value|0
end_define

begin_comment
comment|/* Unknown machine. */
end_comment

begin_define
define|#
directive|define
name|EM_M32
value|1
end_define

begin_comment
comment|/* AT&T WE32100. */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC
value|2
end_define

begin_comment
comment|/* Sun SPARC. */
end_comment

begin_define
define|#
directive|define
name|EM_386
value|3
end_define

begin_comment
comment|/* Intel i386. */
end_comment

begin_define
define|#
directive|define
name|EM_68K
value|4
end_define

begin_comment
comment|/* Motorola 68000. */
end_comment

begin_define
define|#
directive|define
name|EM_88K
value|5
end_define

begin_comment
comment|/* Motorola 88000. */
end_comment

begin_define
define|#
directive|define
name|EM_860
value|7
end_define

begin_comment
comment|/* Intel i860. */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS
value|8
end_define

begin_comment
comment|/* MIPS R3000 Big-Endian only. */
end_comment

begin_define
define|#
directive|define
name|EM_S370
value|9
end_define

begin_comment
comment|/* IBM System/370. */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_RS3_LE
value|10
end_define

begin_comment
comment|/* MIPS R3000 Little-Endian. */
end_comment

begin_define
define|#
directive|define
name|EM_PARISC
value|15
end_define

begin_comment
comment|/* HP PA-RISC. */
end_comment

begin_define
define|#
directive|define
name|EM_VPP500
value|17
end_define

begin_comment
comment|/* Fujitsu VPP500. */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC32PLUS
value|18
end_define

begin_comment
comment|/* SPARC v8plus. */
end_comment

begin_define
define|#
directive|define
name|EM_960
value|19
end_define

begin_comment
comment|/* Intel 80960. */
end_comment

begin_define
define|#
directive|define
name|EM_PPC
value|20
end_define

begin_comment
comment|/* PowerPC 32-bit. */
end_comment

begin_define
define|#
directive|define
name|EM_PPC64
value|21
end_define

begin_comment
comment|/* PowerPC 64-bit. */
end_comment

begin_define
define|#
directive|define
name|EM_S390
value|22
end_define

begin_comment
comment|/* IBM System/390. */
end_comment

begin_define
define|#
directive|define
name|EM_V800
value|36
end_define

begin_comment
comment|/* NEC V800. */
end_comment

begin_define
define|#
directive|define
name|EM_FR20
value|37
end_define

begin_comment
comment|/* Fujitsu FR20. */
end_comment

begin_define
define|#
directive|define
name|EM_RH32
value|38
end_define

begin_comment
comment|/* TRW RH-32. */
end_comment

begin_define
define|#
directive|define
name|EM_RCE
value|39
end_define

begin_comment
comment|/* Motorola RCE. */
end_comment

begin_define
define|#
directive|define
name|EM_ARM
value|40
end_define

begin_comment
comment|/* ARM. */
end_comment

begin_define
define|#
directive|define
name|EM_SH
value|42
end_define

begin_comment
comment|/* Hitachi SH. */
end_comment

begin_define
define|#
directive|define
name|EM_SPARCV9
value|43
end_define

begin_comment
comment|/* SPARC v9 64-bit. */
end_comment

begin_define
define|#
directive|define
name|EM_TRICORE
value|44
end_define

begin_comment
comment|/* Siemens TriCore embedded processor. */
end_comment

begin_define
define|#
directive|define
name|EM_ARC
value|45
end_define

begin_comment
comment|/* Argonaut RISC Core. */
end_comment

begin_define
define|#
directive|define
name|EM_H8_300
value|46
end_define

begin_comment
comment|/* Hitachi H8/300. */
end_comment

begin_define
define|#
directive|define
name|EM_H8_300H
value|47
end_define

begin_comment
comment|/* Hitachi H8/300H. */
end_comment

begin_define
define|#
directive|define
name|EM_H8S
value|48
end_define

begin_comment
comment|/* Hitachi H8S. */
end_comment

begin_define
define|#
directive|define
name|EM_H8_500
value|49
end_define

begin_comment
comment|/* Hitachi H8/500. */
end_comment

begin_define
define|#
directive|define
name|EM_IA_64
value|50
end_define

begin_comment
comment|/* Intel IA-64 Processor. */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_X
value|51
end_define

begin_comment
comment|/* Stanford MIPS-X. */
end_comment

begin_define
define|#
directive|define
name|EM_COLDFIRE
value|52
end_define

begin_comment
comment|/* Motorola ColdFire. */
end_comment

begin_define
define|#
directive|define
name|EM_68HC12
value|53
end_define

begin_comment
comment|/* Motorola M68HC12. */
end_comment

begin_define
define|#
directive|define
name|EM_MMA
value|54
end_define

begin_comment
comment|/* Fujitsu MMA. */
end_comment

begin_define
define|#
directive|define
name|EM_PCP
value|55
end_define

begin_comment
comment|/* Siemens PCP. */
end_comment

begin_define
define|#
directive|define
name|EM_NCPU
value|56
end_define

begin_comment
comment|/* Sony nCPU. */
end_comment

begin_define
define|#
directive|define
name|EM_NDR1
value|57
end_define

begin_comment
comment|/* Denso NDR1 microprocessor. */
end_comment

begin_define
define|#
directive|define
name|EM_STARCORE
value|58
end_define

begin_comment
comment|/* Motorola Star*Core processor. */
end_comment

begin_define
define|#
directive|define
name|EM_ME16
value|59
end_define

begin_comment
comment|/* Toyota ME16 processor. */
end_comment

begin_define
define|#
directive|define
name|EM_ST100
value|60
end_define

begin_comment
comment|/* STMicroelectronics ST100 processor. */
end_comment

begin_define
define|#
directive|define
name|EM_TINYJ
value|61
end_define

begin_comment
comment|/* Advanced Logic Corp. TinyJ processor. */
end_comment

begin_define
define|#
directive|define
name|EM_X86_64
value|62
end_define

begin_comment
comment|/* Advanced Micro Devices x86-64 */
end_comment

begin_comment
comment|/* Non-standard or deprecated. */
end_comment

begin_define
define|#
directive|define
name|EM_486
value|6
end_define

begin_comment
comment|/* Intel i486. */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_RS4_BE
value|10
end_define

begin_comment
comment|/* MIPS R4000 Big-Endian */
end_comment

begin_define
define|#
directive|define
name|EM_ALPHA_STD
value|41
end_define

begin_comment
comment|/* Digital Alpha (standard value). */
end_comment

begin_define
define|#
directive|define
name|EM_ALPHA
value|0x9026
end_define

begin_comment
comment|/* Alpha (written in the absence of an ABI) */
end_comment

begin_comment
comment|/* Special section indexes. */
end_comment

begin_define
define|#
directive|define
name|SHN_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined, missing, irrelevant. */
end_comment

begin_define
define|#
directive|define
name|SHN_LORESERVE
value|0xff00
end_define

begin_comment
comment|/* First of reserved range. */
end_comment

begin_define
define|#
directive|define
name|SHN_LOPROC
value|0xff00
end_define

begin_comment
comment|/* First processor-specific. */
end_comment

begin_define
define|#
directive|define
name|SHN_HIPROC
value|0xff1f
end_define

begin_comment
comment|/* Last processor-specific. */
end_comment

begin_define
define|#
directive|define
name|SHN_LOOS
value|0xff20
end_define

begin_comment
comment|/* First operating system-specific. */
end_comment

begin_define
define|#
directive|define
name|SHN_HIOS
value|0xff3f
end_define

begin_comment
comment|/* Last operating system-specific. */
end_comment

begin_define
define|#
directive|define
name|SHN_ABS
value|0xfff1
end_define

begin_comment
comment|/* Absolute values. */
end_comment

begin_define
define|#
directive|define
name|SHN_COMMON
value|0xfff2
end_define

begin_comment
comment|/* Common data. */
end_comment

begin_define
define|#
directive|define
name|SHN_XINDEX
value|0xffff
end_define

begin_comment
comment|/* Escape -- index stored elsewhere. */
end_comment

begin_define
define|#
directive|define
name|SHN_HIRESERVE
value|0xffff
end_define

begin_comment
comment|/* Last of reserved range. */
end_comment

begin_comment
comment|/* sh_type */
end_comment

begin_define
define|#
directive|define
name|SHT_NULL
value|0
end_define

begin_comment
comment|/* inactive */
end_comment

begin_define
define|#
directive|define
name|SHT_PROGBITS
value|1
end_define

begin_comment
comment|/* program defined information */
end_comment

begin_define
define|#
directive|define
name|SHT_SYMTAB
value|2
end_define

begin_comment
comment|/* symbol table section */
end_comment

begin_define
define|#
directive|define
name|SHT_STRTAB
value|3
end_define

begin_comment
comment|/* string table section */
end_comment

begin_define
define|#
directive|define
name|SHT_RELA
value|4
end_define

begin_comment
comment|/* relocation section with addends */
end_comment

begin_define
define|#
directive|define
name|SHT_HASH
value|5
end_define

begin_comment
comment|/* symbol hash table section */
end_comment

begin_define
define|#
directive|define
name|SHT_DYNAMIC
value|6
end_define

begin_comment
comment|/* dynamic section */
end_comment

begin_define
define|#
directive|define
name|SHT_NOTE
value|7
end_define

begin_comment
comment|/* note section */
end_comment

begin_define
define|#
directive|define
name|SHT_NOBITS
value|8
end_define

begin_comment
comment|/* no space section */
end_comment

begin_define
define|#
directive|define
name|SHT_REL
value|9
end_define

begin_comment
comment|/* relocation section - no addends */
end_comment

begin_define
define|#
directive|define
name|SHT_SHLIB
value|10
end_define

begin_comment
comment|/* reserved - purpose unknown */
end_comment

begin_define
define|#
directive|define
name|SHT_DYNSYM
value|11
end_define

begin_comment
comment|/* dynamic symbol table section */
end_comment

begin_define
define|#
directive|define
name|SHT_INIT_ARRAY
value|14
end_define

begin_comment
comment|/* Initialization function pointers. */
end_comment

begin_define
define|#
directive|define
name|SHT_FINI_ARRAY
value|15
end_define

begin_comment
comment|/* Termination function pointers. */
end_comment

begin_define
define|#
directive|define
name|SHT_PREINIT_ARRAY
value|16
end_define

begin_comment
comment|/* Pre-initialization function ptrs. */
end_comment

begin_define
define|#
directive|define
name|SHT_GROUP
value|17
end_define

begin_comment
comment|/* Section group. */
end_comment

begin_define
define|#
directive|define
name|SHT_SYMTAB_SHNDX
value|18
end_define

begin_comment
comment|/* Section indexes (see SHN_XINDEX). */
end_comment

begin_define
define|#
directive|define
name|SHT_LOOS
value|0x60000000
end_define

begin_comment
comment|/* First of OS specific semantics */
end_comment

begin_define
define|#
directive|define
name|SHT_GNU_verdef
value|0x6ffffffd
end_define

begin_comment
comment|/* Symbol versions provided */
end_comment

begin_define
define|#
directive|define
name|SHT_GNU_verneed
value|0x6ffffffe
end_define

begin_comment
comment|/* Symbol versions required */
end_comment

begin_define
define|#
directive|define
name|SHT_GNU_versym
value|0x6fffffff
end_define

begin_comment
comment|/* Symbol version table */
end_comment

begin_define
define|#
directive|define
name|SHT_HIOS
value|0x6fffffff
end_define

begin_comment
comment|/* Last of OS specific semantics */
end_comment

begin_define
define|#
directive|define
name|SHT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|SHT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/* specific section header types */
end_comment

begin_define
define|#
directive|define
name|SHT_LOUSER
value|0x80000000
end_define

begin_comment
comment|/* reserved range for application */
end_comment

begin_define
define|#
directive|define
name|SHT_HIUSER
value|0xffffffff
end_define

begin_comment
comment|/* specific indexes */
end_comment

begin_comment
comment|/* Flags for sh_flags. */
end_comment

begin_define
define|#
directive|define
name|SHF_WRITE
value|0x1
end_define

begin_comment
comment|/* Section contains writable data. */
end_comment

begin_define
define|#
directive|define
name|SHF_ALLOC
value|0x2
end_define

begin_comment
comment|/* Section occupies memory. */
end_comment

begin_define
define|#
directive|define
name|SHF_EXECINSTR
value|0x4
end_define

begin_comment
comment|/* Section contains instructions. */
end_comment

begin_define
define|#
directive|define
name|SHF_MERGE
value|0x10
end_define

begin_comment
comment|/* Section may be merged. */
end_comment

begin_define
define|#
directive|define
name|SHF_STRINGS
value|0x20
end_define

begin_comment
comment|/* Section contains strings. */
end_comment

begin_define
define|#
directive|define
name|SHF_INFO_LINK
value|0x40
end_define

begin_comment
comment|/* sh_info holds section index. */
end_comment

begin_define
define|#
directive|define
name|SHF_LINK_ORDER
value|0x80
end_define

begin_comment
comment|/* Special ordering requirements. */
end_comment

begin_define
define|#
directive|define
name|SHF_OS_NONCONFORMING
value|0x100
end_define

begin_comment
comment|/* OS-specific processing required. */
end_comment

begin_define
define|#
directive|define
name|SHF_GROUP
value|0x200
end_define

begin_comment
comment|/* Member of section group. */
end_comment

begin_define
define|#
directive|define
name|SHF_TLS
value|0x400
end_define

begin_comment
comment|/* Section contains TLS data. */
end_comment

begin_define
define|#
directive|define
name|SHF_MASKOS
value|0x0ff00000
end_define

begin_comment
comment|/* OS-specific semantics. */
end_comment

begin_define
define|#
directive|define
name|SHF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/* Processor-specific semantics. */
end_comment

begin_comment
comment|/* Values for p_type. */
end_comment

begin_define
define|#
directive|define
name|PT_NULL
value|0
end_define

begin_comment
comment|/* Unused entry. */
end_comment

begin_define
define|#
directive|define
name|PT_LOAD
value|1
end_define

begin_comment
comment|/* Loadable segment. */
end_comment

begin_define
define|#
directive|define
name|PT_DYNAMIC
value|2
end_define

begin_comment
comment|/* Dynamic linking information segment. */
end_comment

begin_define
define|#
directive|define
name|PT_INTERP
value|3
end_define

begin_comment
comment|/* Pathname of interpreter. */
end_comment

begin_define
define|#
directive|define
name|PT_NOTE
value|4
end_define

begin_comment
comment|/* Auxiliary information. */
end_comment

begin_define
define|#
directive|define
name|PT_SHLIB
value|5
end_define

begin_comment
comment|/* Reserved (not used). */
end_comment

begin_define
define|#
directive|define
name|PT_PHDR
value|6
end_define

begin_comment
comment|/* Location of program header itself. */
end_comment

begin_define
define|#
directive|define
name|PT_TLS
value|7
end_define

begin_comment
comment|/* Thread local storage segment */
end_comment

begin_define
define|#
directive|define
name|PT_LOOS
value|0x60000000
end_define

begin_comment
comment|/* First OS-specific. */
end_comment

begin_define
define|#
directive|define
name|PT_HIOS
value|0x6fffffff
end_define

begin_comment
comment|/* Last OS-specific. */
end_comment

begin_define
define|#
directive|define
name|PT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* First processor-specific type. */
end_comment

begin_define
define|#
directive|define
name|PT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/* Last processor-specific type. */
end_comment

begin_comment
comment|/* Values for p_flags. */
end_comment

begin_define
define|#
directive|define
name|PF_X
value|0x1
end_define

begin_comment
comment|/* Executable. */
end_comment

begin_define
define|#
directive|define
name|PF_W
value|0x2
end_define

begin_comment
comment|/* Writable. */
end_comment

begin_define
define|#
directive|define
name|PF_R
value|0x4
end_define

begin_comment
comment|/* Readable. */
end_comment

begin_define
define|#
directive|define
name|PF_MASKOS
value|0x0ff00000
end_define

begin_comment
comment|/* Operating system-specific. */
end_comment

begin_define
define|#
directive|define
name|PF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/* Processor-specific. */
end_comment

begin_comment
comment|/* Values for d_tag. */
end_comment

begin_define
define|#
directive|define
name|DT_NULL
value|0
end_define

begin_comment
comment|/* Terminating entry. */
end_comment

begin_define
define|#
directive|define
name|DT_NEEDED
value|1
end_define

begin_comment
comment|/* String table offset of a needed shared 				   library. */
end_comment

begin_define
define|#
directive|define
name|DT_PLTRELSZ
value|2
end_define

begin_comment
comment|/* Total size in bytes of PLT relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_PLTGOT
value|3
end_define

begin_comment
comment|/* Processor-dependent address. */
end_comment

begin_define
define|#
directive|define
name|DT_HASH
value|4
end_define

begin_comment
comment|/* Address of symbol hash table. */
end_comment

begin_define
define|#
directive|define
name|DT_STRTAB
value|5
end_define

begin_comment
comment|/* Address of string table. */
end_comment

begin_define
define|#
directive|define
name|DT_SYMTAB
value|6
end_define

begin_comment
comment|/* Address of symbol table. */
end_comment

begin_define
define|#
directive|define
name|DT_RELA
value|7
end_define

begin_comment
comment|/* Address of ElfNN_Rela relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELASZ
value|8
end_define

begin_comment
comment|/* Total size of ElfNN_Rela relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELAENT
value|9
end_define

begin_comment
comment|/* Size of each ElfNN_Rela relocation entry. */
end_comment

begin_define
define|#
directive|define
name|DT_STRSZ
value|10
end_define

begin_comment
comment|/* Size of string table. */
end_comment

begin_define
define|#
directive|define
name|DT_SYMENT
value|11
end_define

begin_comment
comment|/* Size of each symbol table entry. */
end_comment

begin_define
define|#
directive|define
name|DT_INIT
value|12
end_define

begin_comment
comment|/* Address of initialization function. */
end_comment

begin_define
define|#
directive|define
name|DT_FINI
value|13
end_define

begin_comment
comment|/* Address of finalization function. */
end_comment

begin_define
define|#
directive|define
name|DT_SONAME
value|14
end_define

begin_comment
comment|/* String table offset of shared object 				   name. */
end_comment

begin_define
define|#
directive|define
name|DT_RPATH
value|15
end_define

begin_comment
comment|/* String table offset of library path. [sup] */
end_comment

begin_define
define|#
directive|define
name|DT_SYMBOLIC
value|16
end_define

begin_comment
comment|/* Indicates "symbolic" linking. [sup] */
end_comment

begin_define
define|#
directive|define
name|DT_REL
value|17
end_define

begin_comment
comment|/* Address of ElfNN_Rel relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELSZ
value|18
end_define

begin_comment
comment|/* Total size of ElfNN_Rel relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELENT
value|19
end_define

begin_comment
comment|/* Size of each ElfNN_Rel relocation. */
end_comment

begin_define
define|#
directive|define
name|DT_PLTREL
value|20
end_define

begin_comment
comment|/* Type of relocation used for PLT. */
end_comment

begin_define
define|#
directive|define
name|DT_DEBUG
value|21
end_define

begin_comment
comment|/* Reserved (not used). */
end_comment

begin_define
define|#
directive|define
name|DT_TEXTREL
value|22
end_define

begin_comment
comment|/* Indicates there may be relocations in 				   non-writable segments. [sup] */
end_comment

begin_define
define|#
directive|define
name|DT_JMPREL
value|23
end_define

begin_comment
comment|/* Address of PLT relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_BIND_NOW
value|24
end_define

begin_comment
comment|/* [sup] */
end_comment

begin_define
define|#
directive|define
name|DT_INIT_ARRAY
value|25
end_define

begin_comment
comment|/* Address of the array of pointers to 				   initialization functions */
end_comment

begin_define
define|#
directive|define
name|DT_FINI_ARRAY
value|26
end_define

begin_comment
comment|/* Address of the array of pointers to 				   termination functions */
end_comment

begin_define
define|#
directive|define
name|DT_INIT_ARRAYSZ
value|27
end_define

begin_comment
comment|/* Size in bytes of the array of 				   initialization functions. */
end_comment

begin_define
define|#
directive|define
name|DT_FINI_ARRAYSZ
value|28
end_define

begin_comment
comment|/* Size in bytes of the array of 				   terminationfunctions. */
end_comment

begin_define
define|#
directive|define
name|DT_RUNPATH
value|29
end_define

begin_comment
comment|/* String table offset of a null-terminated 				   library search path string. */
end_comment

begin_define
define|#
directive|define
name|DT_FLAGS
value|30
end_define

begin_comment
comment|/* Object specific flag values. */
end_comment

begin_define
define|#
directive|define
name|DT_ENCODING
value|32
end_define

begin_comment
comment|/* Values greater than or equal to DT_ENCODING 				   and less than DT_LOOS follow the rules for 				   the interpretation of the d_un union 				   as follows: even == 'd_ptr', even == 'd_val' 				   or none */
end_comment

begin_define
define|#
directive|define
name|DT_PREINIT_ARRAY
value|32
end_define

begin_comment
comment|/* Address of the array of pointers to 				   pre-initialization functions. */
end_comment

begin_define
define|#
directive|define
name|DT_PREINIT_ARRAYSZ
value|33
end_define

begin_comment
comment|/* Size in bytes of the array of 				   pre-initialization functions. */
end_comment

begin_define
define|#
directive|define
name|DT_LOOS
value|0x6000000d
end_define

begin_comment
comment|/* First OS-specific */
end_comment

begin_define
define|#
directive|define
name|DT_HIOS
value|0x6ffff000
end_define

begin_comment
comment|/* Last OS-specific */
end_comment

begin_define
define|#
directive|define
name|DT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* First processor-specific type. */
end_comment

begin_define
define|#
directive|define
name|DT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/* Last processor-specific type. */
end_comment

begin_define
define|#
directive|define
name|DT_VERSYM
value|0x6ffffff0
end_define

begin_comment
comment|/* Address of versym section. */
end_comment

begin_define
define|#
directive|define
name|DT_VERDEF
value|0x6ffffffc
end_define

begin_comment
comment|/* Address of verdef section. */
end_comment

begin_define
define|#
directive|define
name|DT_VERDEFNUM
value|0x6ffffffd
end_define

begin_comment
comment|/* Number of elems in verdef section */
end_comment

begin_define
define|#
directive|define
name|DT_VERNEED
value|0x6ffffffe
end_define

begin_comment
comment|/* Address of verneed section. */
end_comment

begin_define
define|#
directive|define
name|DT_VERNEEDNUM
value|0x6fffffff
end_define

begin_comment
comment|/* Number of elems in verneed section */
end_comment

begin_comment
comment|/* Values for DT_FLAGS */
end_comment

begin_define
define|#
directive|define
name|DF_ORIGIN
value|0x0001
end_define

begin_comment
comment|/* Indicates that the object being loaded may 				   make reference to the $ORIGIN substitution 				   string */
end_comment

begin_define
define|#
directive|define
name|DF_SYMBOLIC
value|0x0002
end_define

begin_comment
comment|/* Indicates "symbolic" linking. */
end_comment

begin_define
define|#
directive|define
name|DF_TEXTREL
value|0x0004
end_define

begin_comment
comment|/* Indicates there may be relocations in 				   non-writable segments. */
end_comment

begin_define
define|#
directive|define
name|DF_BIND_NOW
value|0x0008
end_define

begin_comment
comment|/* Indicates that the dynamic linker should 				   process all relocations for the object 				   containing this entry before transferring 				   control to the program. */
end_comment

begin_define
define|#
directive|define
name|DF_STATIC_TLS
value|0x0010
end_define

begin_comment
comment|/* Indicates that the shared object or 				   executable contains code using a static 				   thread-local storage scheme. */
end_comment

begin_comment
comment|/* Values for n_type.  Used in core files. */
end_comment

begin_define
define|#
directive|define
name|NT_PRSTATUS
value|1
end_define

begin_comment
comment|/* Process status. */
end_comment

begin_define
define|#
directive|define
name|NT_FPREGSET
value|2
end_define

begin_comment
comment|/* Floating point registers. */
end_comment

begin_define
define|#
directive|define
name|NT_PRPSINFO
value|3
end_define

begin_comment
comment|/* Process state info. */
end_comment

begin_comment
comment|/* Symbol Binding - ELFNN_ST_BIND - st_info */
end_comment

begin_define
define|#
directive|define
name|STB_LOCAL
value|0
end_define

begin_comment
comment|/* Local symbol */
end_comment

begin_define
define|#
directive|define
name|STB_GLOBAL
value|1
end_define

begin_comment
comment|/* Global symbol */
end_comment

begin_define
define|#
directive|define
name|STB_WEAK
value|2
end_define

begin_comment
comment|/* like global - lower precedence */
end_comment

begin_define
define|#
directive|define
name|STB_LOOS
value|10
end_define

begin_comment
comment|/* Reserved range for operating system */
end_comment

begin_define
define|#
directive|define
name|STB_HIOS
value|12
end_define

begin_comment
comment|/*   specific semantics. */
end_comment

begin_define
define|#
directive|define
name|STB_LOPROC
value|13
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|STB_HIPROC
value|15
end_define

begin_comment
comment|/*   specific semantics. */
end_comment

begin_comment
comment|/* Symbol type - ELFNN_ST_TYPE - st_info */
end_comment

begin_define
define|#
directive|define
name|STT_NOTYPE
value|0
end_define

begin_comment
comment|/* Unspecified type. */
end_comment

begin_define
define|#
directive|define
name|STT_OBJECT
value|1
end_define

begin_comment
comment|/* Data object. */
end_comment

begin_define
define|#
directive|define
name|STT_FUNC
value|2
end_define

begin_comment
comment|/* Function. */
end_comment

begin_define
define|#
directive|define
name|STT_SECTION
value|3
end_define

begin_comment
comment|/* Section. */
end_comment

begin_define
define|#
directive|define
name|STT_FILE
value|4
end_define

begin_comment
comment|/* Source file. */
end_comment

begin_define
define|#
directive|define
name|STT_COMMON
value|5
end_define

begin_comment
comment|/* Uninitialized common block. */
end_comment

begin_define
define|#
directive|define
name|STT_TLS
value|6
end_define

begin_comment
comment|/* TLS object. */
end_comment

begin_define
define|#
directive|define
name|STT_LOOS
value|10
end_define

begin_comment
comment|/* Reserved range for operating system */
end_comment

begin_define
define|#
directive|define
name|STT_HIOS
value|12
end_define

begin_comment
comment|/*   specific semantics. */
end_comment

begin_define
define|#
directive|define
name|STT_LOPROC
value|13
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|STT_HIPROC
value|15
end_define

begin_comment
comment|/*   specific semantics. */
end_comment

begin_comment
comment|/* Symbol visibility - ELFNN_ST_VISIBILITY - st_other */
end_comment

begin_define
define|#
directive|define
name|STV_DEFAULT
value|0x0
end_define

begin_comment
comment|/* Default visibility (see binding). */
end_comment

begin_define
define|#
directive|define
name|STV_INTERNAL
value|0x1
end_define

begin_comment
comment|/* Special meaning in relocatable objects. */
end_comment

begin_define
define|#
directive|define
name|STV_HIDDEN
value|0x2
end_define

begin_comment
comment|/* Not visible. */
end_comment

begin_define
define|#
directive|define
name|STV_PROTECTED
value|0x3
end_define

begin_comment
comment|/* Visible but not preemptible. */
end_comment

begin_comment
comment|/* Special symbol table indexes. */
end_comment

begin_define
define|#
directive|define
name|STN_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined symbol index. */
end_comment

begin_comment
comment|/* Symbol versioning flags. */
end_comment

begin_define
define|#
directive|define
name|VER_DEF_CURRENT
value|1
end_define

begin_define
define|#
directive|define
name|VER_DEF_IDX
parameter_list|(
name|x
parameter_list|)
value|VER_NDX(x)
end_define

begin_define
define|#
directive|define
name|VER_FLG_BASE
value|0x01
end_define

begin_define
define|#
directive|define
name|VER_FLG_WEAK
value|0x02
end_define

begin_define
define|#
directive|define
name|VER_NEED_CURRENT
value|1
end_define

begin_define
define|#
directive|define
name|VER_NEED_WEAK
value|(1u<< 15)
end_define

begin_define
define|#
directive|define
name|VER_NEED_HIDDEN
value|VER_NDX_HIDDEN
end_define

begin_define
define|#
directive|define
name|VER_NEED_IDX
parameter_list|(
name|x
parameter_list|)
value|VER_NDX(x)
end_define

begin_define
define|#
directive|define
name|VER_NDX_LOCAL
value|0
end_define

begin_define
define|#
directive|define
name|VER_NDX_GLOBAL
value|1
end_define

begin_define
define|#
directive|define
name|VER_NDX_GIVEN
value|2
end_define

begin_define
define|#
directive|define
name|VER_NDX_HIDDEN
value|(1u<< 15)
end_define

begin_define
define|#
directive|define
name|VER_NDX
parameter_list|(
name|x
parameter_list|)
value|((x)& ~(1u<< 15))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ELF_COMMON_H_ */
end_comment

end_unit

