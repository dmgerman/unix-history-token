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
comment|/* Indexes into the e_ident array.  Keep synced with     http://www.sco.com/developer/gabi/ch4.eheader.html */
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
name|ELFOSABI_SYSV
value|0
end_define

begin_comment
comment|/* UNIX System V ABI */
end_comment

begin_define
define|#
directive|define
name|ELFOSABI_NONE
value|ELFOSABI_SYSV
end_define

begin_comment
comment|/* symbol used in old spec */
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
name|ELFOSABI_MONTEREY
value|7
end_define

begin_comment
comment|/* Monterey */
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
name|EM_486
value|6
end_define

begin_comment
comment|/* Intel i486. */
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
comment|/* MIPS R3000 Big-Endian only */
end_comment

begin_comment
comment|/* Extensions.  This list is not complete. */
end_comment

begin_define
define|#
directive|define
name|EM_S370
value|9
end_define

begin_comment
comment|/* IBM System/370 */
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

begin_comment
comment|/* Depreciated */
end_comment

begin_define
define|#
directive|define
name|EM_PARISC
value|15
end_define

begin_comment
comment|/* HPPA */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC32PLUS
value|18
end_define

begin_comment
comment|/* SPARC v8plus */
end_comment

begin_define
define|#
directive|define
name|EM_PPC
value|20
end_define

begin_comment
comment|/* PowerPC 32-bit */
end_comment

begin_define
define|#
directive|define
name|EM_PPC64
value|21
end_define

begin_comment
comment|/* PowerPC 64-bit */
end_comment

begin_define
define|#
directive|define
name|EM_ARM
value|40
end_define

begin_comment
comment|/* ARM */
end_comment

begin_define
define|#
directive|define
name|EM_SPARCV9
value|43
end_define

begin_comment
comment|/* SPARC v9 64-bit */
end_comment

begin_define
define|#
directive|define
name|EM_IA_64
value|50
end_define

begin_comment
comment|/* Intel IA-46 Processor */
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

begin_define
define|#
directive|define
name|EM_ALPHA
value|0x9026
end_define

begin_comment
comment|/* Alpha (written in the absence of an ABI */
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
comment|/* relocation section with addends*/
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
comment|/* relation section without addends */
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
name|SHF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/* Reserved for processor-specific. */
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
name|PT_COUNT
value|7
end_define

begin_comment
comment|/* Number of defined p_type values. */
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
comment|/* String table offset of library path. */
end_comment

begin_define
define|#
directive|define
name|DT_SYMBOLIC
value|16
end_define

begin_comment
comment|/* Indicates "symbolic" linking. */
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
comment|/* Indicates there may be relocations in 				   non-writable segments. */
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
name|DT_COUNT
value|24
end_define

begin_comment
comment|/* Number of defined d_tag values. */
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
comment|/*  specific symbol bindings */
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
comment|/*  specific symbol types */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_ELF_COMMON_H_ */
end_comment

end_unit

