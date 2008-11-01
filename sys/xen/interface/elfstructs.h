begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_ELFSTRUCTS_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_ELFSTRUCTS_H__
value|1
end_define

begin_comment
comment|/*  * Copyright (c) 1995, 1996 Erik Theisen.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
name|uint8_t
name|Elf_Byte
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Addr
typedef|;
end_typedef

begin_comment
comment|/* Unsigned program address */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Off
typedef|;
end_typedef

begin_comment
comment|/* Unsigned file offset */
end_comment

begin_typedef
typedef|typedef
name|int32_t
name|Elf32_Sword
typedef|;
end_typedef

begin_comment
comment|/* Signed large integer */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|Elf32_Word
typedef|;
end_typedef

begin_comment
comment|/* Unsigned large integer */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|Elf32_Half
typedef|;
end_typedef

begin_comment
comment|/* Unsigned medium integer */
end_comment

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
name|int32_t
name|Elf64_Shalf
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|Elf64_Sword
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
name|int64_t
name|Elf64_Sxword
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
name|uint32_t
name|Elf64_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|Elf64_Quarter
typedef|;
end_typedef

begin_comment
comment|/*  * e_ident[] identification indexes  * See http://www.caldera.com/developers/gabi/2000-07-17/ch4.eheader.html  */
end_comment

begin_define
define|#
directive|define
name|EI_MAG0
value|0
end_define

begin_comment
comment|/* file ID */
end_comment

begin_define
define|#
directive|define
name|EI_MAG1
value|1
end_define

begin_comment
comment|/* file ID */
end_comment

begin_define
define|#
directive|define
name|EI_MAG2
value|2
end_define

begin_comment
comment|/* file ID */
end_comment

begin_define
define|#
directive|define
name|EI_MAG3
value|3
end_define

begin_comment
comment|/* file ID */
end_comment

begin_define
define|#
directive|define
name|EI_CLASS
value|4
end_define

begin_comment
comment|/* file class */
end_comment

begin_define
define|#
directive|define
name|EI_DATA
value|5
end_define

begin_comment
comment|/* data encoding */
end_comment

begin_define
define|#
directive|define
name|EI_VERSION
value|6
end_define

begin_comment
comment|/* ELF header version */
end_comment

begin_define
define|#
directive|define
name|EI_OSABI
value|7
end_define

begin_comment
comment|/* OS/ABI ID */
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
name|EI_PAD
value|9
end_define

begin_comment
comment|/* start of pad bytes */
end_comment

begin_define
define|#
directive|define
name|EI_NIDENT
value|16
end_define

begin_comment
comment|/* Size of e_ident[] */
end_comment

begin_comment
comment|/* e_ident[] magic number */
end_comment

begin_define
define|#
directive|define
name|ELFMAG0
value|0x7f
end_define

begin_comment
comment|/* e_ident[EI_MAG0] */
end_comment

begin_define
define|#
directive|define
name|ELFMAG1
value|'E'
end_define

begin_comment
comment|/* e_ident[EI_MAG1] */
end_comment

begin_define
define|#
directive|define
name|ELFMAG2
value|'L'
end_define

begin_comment
comment|/* e_ident[EI_MAG2] */
end_comment

begin_define
define|#
directive|define
name|ELFMAG3
value|'F'
end_define

begin_comment
comment|/* e_ident[EI_MAG3] */
end_comment

begin_define
define|#
directive|define
name|ELFMAG
value|"\177ELF"
end_define

begin_comment
comment|/* magic */
end_comment

begin_define
define|#
directive|define
name|SELFMAG
value|4
end_define

begin_comment
comment|/* size of magic */
end_comment

begin_comment
comment|/* e_ident[] file class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASSNONE
value|0
end_define

begin_comment
comment|/* invalid */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS32
value|1
end_define

begin_comment
comment|/* 32-bit objs */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS64
value|2
end_define

begin_comment
comment|/* 64-bit objs */
end_comment

begin_define
define|#
directive|define
name|ELFCLASSNUM
value|3
end_define

begin_comment
comment|/* number of classes */
end_comment

begin_comment
comment|/* e_ident[] data encoding */
end_comment

begin_define
define|#
directive|define
name|ELFDATANONE
value|0
end_define

begin_comment
comment|/* invalid */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2LSB
value|1
end_define

begin_comment
comment|/* Little-Endian */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2MSB
value|2
end_define

begin_comment
comment|/* Big-Endian */
end_comment

begin_define
define|#
directive|define
name|ELFDATANUM
value|3
end_define

begin_comment
comment|/* number of data encode defines */
end_comment

begin_comment
comment|/* e_ident[] Operating System/ABI */
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
value|((ehdr).e_ident[EI_MAG0] == ELFMAG0&& \                       (ehdr).e_ident[EI_MAG1] == ELFMAG1&& \                       (ehdr).e_ident[EI_MAG2] == ELFMAG2&& \                       (ehdr).e_ident[EI_MAG3] == ELFMAG3)
end_define

begin_comment
comment|/* ELF Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elfhdr
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
comment|/* ELF Identification */
name|Elf32_Half
name|e_type
decl_stmt|;
comment|/* object file type */
name|Elf32_Half
name|e_machine
decl_stmt|;
comment|/* machine */
name|Elf32_Word
name|e_version
decl_stmt|;
comment|/* object file version */
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|/* virtual entry point */
name|Elf32_Off
name|e_phoff
decl_stmt|;
comment|/* program header table offset */
name|Elf32_Off
name|e_shoff
decl_stmt|;
comment|/* section header table offset */
name|Elf32_Word
name|e_flags
decl_stmt|;
comment|/* processor-specific flags */
name|Elf32_Half
name|e_ehsize
decl_stmt|;
comment|/* ELF header size */
name|Elf32_Half
name|e_phentsize
decl_stmt|;
comment|/* program header entry size */
name|Elf32_Half
name|e_phnum
decl_stmt|;
comment|/* number of program header entries */
name|Elf32_Half
name|e_shentsize
decl_stmt|;
comment|/* section header entry size */
name|Elf32_Half
name|e_shnum
decl_stmt|;
comment|/* number of section header entries */
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
comment|/* section header table's "section 					   header string table" entry offset */
block|}
name|Elf32_Ehdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|e_ident
index|[
name|EI_NIDENT
index|]
decl_stmt|;
comment|/* Id bytes */
name|Elf64_Quarter
name|e_type
decl_stmt|;
comment|/* file type */
name|Elf64_Quarter
name|e_machine
decl_stmt|;
comment|/* machine type */
name|Elf64_Half
name|e_version
decl_stmt|;
comment|/* version number */
name|Elf64_Addr
name|e_entry
decl_stmt|;
comment|/* entry point */
name|Elf64_Off
name|e_phoff
decl_stmt|;
comment|/* Program hdr offset */
name|Elf64_Off
name|e_shoff
decl_stmt|;
comment|/* Section hdr offset */
name|Elf64_Half
name|e_flags
decl_stmt|;
comment|/* Processor flags */
name|Elf64_Quarter
name|e_ehsize
decl_stmt|;
comment|/* sizeof ehdr */
name|Elf64_Quarter
name|e_phentsize
decl_stmt|;
comment|/* Program header entry size */
name|Elf64_Quarter
name|e_phnum
decl_stmt|;
comment|/* Number of program headers */
name|Elf64_Quarter
name|e_shentsize
decl_stmt|;
comment|/* Section header entry size */
name|Elf64_Quarter
name|e_shnum
decl_stmt|;
comment|/* Number of section headers */
name|Elf64_Quarter
name|e_shstrndx
decl_stmt|;
comment|/* String table index */
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
name|ET_NONE
value|0
end_define

begin_comment
comment|/* No file type */
end_comment

begin_define
define|#
directive|define
name|ET_REL
value|1
end_define

begin_comment
comment|/* relocatable file */
end_comment

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_comment
comment|/* executable file */
end_comment

begin_define
define|#
directive|define
name|ET_DYN
value|3
end_define

begin_comment
comment|/* shared object file */
end_comment

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_comment
comment|/* core file */
end_comment

begin_define
define|#
directive|define
name|ET_NUM
value|5
end_define

begin_comment
comment|/* number of types */
end_comment

begin_define
define|#
directive|define
name|ET_LOPROC
value|0xff00
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|ET_HIPROC
value|0xffff
end_define

begin_comment
comment|/*  specific e_type */
end_comment

begin_comment
comment|/* e_machine */
end_comment

begin_define
define|#
directive|define
name|EM_NONE
value|0
end_define

begin_comment
comment|/* No Machine */
end_comment

begin_define
define|#
directive|define
name|EM_M32
value|1
end_define

begin_comment
comment|/* AT&T WE 32100 */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC
value|2
end_define

begin_comment
comment|/* SPARC */
end_comment

begin_define
define|#
directive|define
name|EM_386
value|3
end_define

begin_comment
comment|/* Intel 80386 */
end_comment

begin_define
define|#
directive|define
name|EM_68K
value|4
end_define

begin_comment
comment|/* Motorola 68000 */
end_comment

begin_define
define|#
directive|define
name|EM_88K
value|5
end_define

begin_comment
comment|/* Motorola 88000 */
end_comment

begin_define
define|#
directive|define
name|EM_486
value|6
end_define

begin_comment
comment|/* Intel 80486 - unused? */
end_comment

begin_define
define|#
directive|define
name|EM_860
value|7
end_define

begin_comment
comment|/* Intel 80860 */
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
comment|/*  * Don't know if EM_MIPS_RS4_BE,  * EM_SPARC64, EM_PARISC,  * or EM_PPC are ABI compliant  */
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
name|EM_SPARC64
value|11
end_define

begin_comment
comment|/* SPARC v9 64-bit unoffical */
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
comment|/* Enhanced instruction set SPARC */
end_comment

begin_define
define|#
directive|define
name|EM_PPC
value|20
end_define

begin_comment
comment|/* PowerPC */
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
comment|/* Advanced RISC Machines ARM */
end_comment

begin_define
define|#
directive|define
name|EM_ALPHA
value|41
end_define

begin_comment
comment|/* DEC ALPHA */
end_comment

begin_define
define|#
directive|define
name|EM_SPARCV9
value|43
end_define

begin_comment
comment|/* SPARC version 9 */
end_comment

begin_define
define|#
directive|define
name|EM_ALPHA_EXP
value|0x9026
end_define

begin_comment
comment|/* DEC ALPHA */
end_comment

begin_define
define|#
directive|define
name|EM_IA_64
value|50
end_define

begin_comment
comment|/* Intel Merced */
end_comment

begin_define
define|#
directive|define
name|EM_X86_64
value|62
end_define

begin_comment
comment|/* AMD x86-64 architecture */
end_comment

begin_define
define|#
directive|define
name|EM_VAX
value|75
end_define

begin_comment
comment|/* DEC VAX */
end_comment

begin_comment
comment|/* Version */
end_comment

begin_define
define|#
directive|define
name|EV_NONE
value|0
end_define

begin_comment
comment|/* Invalid */
end_comment

begin_define
define|#
directive|define
name|EV_CURRENT
value|1
end_define

begin_comment
comment|/* Current */
end_comment

begin_define
define|#
directive|define
name|EV_NUM
value|2
end_define

begin_comment
comment|/* number of versions */
end_comment

begin_comment
comment|/* Section Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|sh_name
decl_stmt|;
comment|/* name - index into section header 					   string table section */
name|Elf32_Word
name|sh_type
decl_stmt|;
comment|/* type */
name|Elf32_Word
name|sh_flags
decl_stmt|;
comment|/* flags */
name|Elf32_Addr
name|sh_addr
decl_stmt|;
comment|/* address */
name|Elf32_Off
name|sh_offset
decl_stmt|;
comment|/* file offset */
name|Elf32_Word
name|sh_size
decl_stmt|;
comment|/* section size */
name|Elf32_Word
name|sh_link
decl_stmt|;
comment|/* section header table index link */
name|Elf32_Word
name|sh_info
decl_stmt|;
comment|/* extra information */
name|Elf32_Word
name|sh_addralign
decl_stmt|;
comment|/* address alignment */
name|Elf32_Word
name|sh_entsize
decl_stmt|;
comment|/* section entry size */
block|}
name|Elf32_Shdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|sh_name
decl_stmt|;
comment|/* section name */
name|Elf64_Half
name|sh_type
decl_stmt|;
comment|/* section type */
name|Elf64_Xword
name|sh_flags
decl_stmt|;
comment|/* section flags */
name|Elf64_Addr
name|sh_addr
decl_stmt|;
comment|/* virtual address */
name|Elf64_Off
name|sh_offset
decl_stmt|;
comment|/* file offset */
name|Elf64_Xword
name|sh_size
decl_stmt|;
comment|/* section size */
name|Elf64_Half
name|sh_link
decl_stmt|;
comment|/* link to another */
name|Elf64_Half
name|sh_info
decl_stmt|;
comment|/* misc info */
name|Elf64_Xword
name|sh_addralign
decl_stmt|;
comment|/* memory alignment */
name|Elf64_Xword
name|sh_entsize
decl_stmt|;
comment|/* table entry size */
block|}
name|Elf64_Shdr
typedef|;
end_typedef

begin_comment
comment|/* Special Section Indexes */
end_comment

begin_define
define|#
directive|define
name|SHN_UNDEF
value|0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_define
define|#
directive|define
name|SHN_LORESERVE
value|0xff00
end_define

begin_comment
comment|/* lower bounds of reserved indexes */
end_comment

begin_define
define|#
directive|define
name|SHN_LOPROC
value|0xff00
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|SHN_HIPROC
value|0xff1f
end_define

begin_comment
comment|/*   specific section indexes */
end_comment

begin_define
define|#
directive|define
name|SHN_ABS
value|0xfff1
end_define

begin_comment
comment|/* absolute value */
end_comment

begin_define
define|#
directive|define
name|SHN_COMMON
value|0xfff2
end_define

begin_comment
comment|/* common symbol */
end_comment

begin_define
define|#
directive|define
name|SHN_HIRESERVE
value|0xffff
end_define

begin_comment
comment|/* upper bounds of reserved indexes */
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
name|SHT_NUM
value|12
end_define

begin_comment
comment|/* number of section types */
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
comment|/*  specific section header types */
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
comment|/*  specific indexes */
end_comment

begin_comment
comment|/* Section names */
end_comment

begin_define
define|#
directive|define
name|ELF_BSS
value|".bss"
end_define

begin_comment
comment|/* uninitialized data */
end_comment

begin_define
define|#
directive|define
name|ELF_DATA
value|".data"
end_define

begin_comment
comment|/* initialized data */
end_comment

begin_define
define|#
directive|define
name|ELF_DEBUG
value|".debug"
end_define

begin_comment
comment|/* debug */
end_comment

begin_define
define|#
directive|define
name|ELF_DYNAMIC
value|".dynamic"
end_define

begin_comment
comment|/* dynamic linking information */
end_comment

begin_define
define|#
directive|define
name|ELF_DYNSTR
value|".dynstr"
end_define

begin_comment
comment|/* dynamic string table */
end_comment

begin_define
define|#
directive|define
name|ELF_DYNSYM
value|".dynsym"
end_define

begin_comment
comment|/* dynamic symbol table */
end_comment

begin_define
define|#
directive|define
name|ELF_FINI
value|".fini"
end_define

begin_comment
comment|/* termination code */
end_comment

begin_define
define|#
directive|define
name|ELF_GOT
value|".got"
end_define

begin_comment
comment|/* global offset table */
end_comment

begin_define
define|#
directive|define
name|ELF_HASH
value|".hash"
end_define

begin_comment
comment|/* symbol hash table */
end_comment

begin_define
define|#
directive|define
name|ELF_INIT
value|".init"
end_define

begin_comment
comment|/* initialization code */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_DATA
value|".rel.data"
end_define

begin_comment
comment|/* relocation data */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_FINI
value|".rel.fini"
end_define

begin_comment
comment|/* relocation termination code */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_INIT
value|".rel.init"
end_define

begin_comment
comment|/* relocation initialization code */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_DYN
value|".rel.dyn"
end_define

begin_comment
comment|/* relocaltion dynamic link info */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_RODATA
value|".rel.rodata"
end_define

begin_comment
comment|/* relocation read-only data */
end_comment

begin_define
define|#
directive|define
name|ELF_REL_TEXT
value|".rel.text"
end_define

begin_comment
comment|/* relocation code */
end_comment

begin_define
define|#
directive|define
name|ELF_RODATA
value|".rodata"
end_define

begin_comment
comment|/* read-only data */
end_comment

begin_define
define|#
directive|define
name|ELF_SHSTRTAB
value|".shstrtab"
end_define

begin_comment
comment|/* section header string table */
end_comment

begin_define
define|#
directive|define
name|ELF_STRTAB
value|".strtab"
end_define

begin_comment
comment|/* string table */
end_comment

begin_define
define|#
directive|define
name|ELF_SYMTAB
value|".symtab"
end_define

begin_comment
comment|/* symbol table */
end_comment

begin_define
define|#
directive|define
name|ELF_TEXT
value|".text"
end_define

begin_comment
comment|/* code */
end_comment

begin_comment
comment|/* Section Attribute Flags - sh_flags */
end_comment

begin_define
define|#
directive|define
name|SHF_WRITE
value|0x1
end_define

begin_comment
comment|/* Writable */
end_comment

begin_define
define|#
directive|define
name|SHF_ALLOC
value|0x2
end_define

begin_comment
comment|/* occupies memory */
end_comment

begin_define
define|#
directive|define
name|SHF_EXECINSTR
value|0x4
end_define

begin_comment
comment|/* executable */
end_comment

begin_define
define|#
directive|define
name|SHF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/* reserved bits for processor */
end_comment

begin_comment
comment|/*  specific section attributes */
end_comment

begin_comment
comment|/* Symbol Table Entry */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|elf32_sym
block|{
name|Elf32_Word
name|st_name
decl_stmt|;
comment|/* name - index into string table */
name|Elf32_Addr
name|st_value
decl_stmt|;
comment|/* symbol value */
name|Elf32_Word
name|st_size
decl_stmt|;
comment|/* symbol size */
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|/* type and binding */
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|/* 0 - no defined meaning */
name|Elf32_Half
name|st_shndx
decl_stmt|;
comment|/* section header index */
block|}
name|Elf32_Sym
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|st_name
decl_stmt|;
comment|/* Symbol name index in str table */
name|Elf_Byte
name|st_info
decl_stmt|;
comment|/* type / binding attrs */
name|Elf_Byte
name|st_other
decl_stmt|;
comment|/* unused */
name|Elf64_Quarter
name|st_shndx
decl_stmt|;
comment|/* section index of symbol */
name|Elf64_Xword
name|st_value
decl_stmt|;
comment|/* value of symbol */
name|Elf64_Xword
name|st_size
decl_stmt|;
comment|/* size of symbol */
block|}
name|Elf64_Sym
typedef|;
end_typedef

begin_comment
comment|/* Symbol table index */
end_comment

begin_define
define|#
directive|define
name|STN_UNDEF
value|0
end_define

begin_comment
comment|/* undefined */
end_comment

begin_comment
comment|/* Extract symbol info - st_info */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_BIND
parameter_list|(
name|x
parameter_list|)
value|((x)>> 4)
end_define

begin_define
define|#
directive|define
name|ELF32_ST_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((unsigned int) x)& 0xf)
end_define

begin_define
define|#
directive|define
name|ELF32_ST_INFO
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|(((b)<< 4) + ((t)& 0xf))
end_define

begin_define
define|#
directive|define
name|ELF64_ST_BIND
parameter_list|(
name|x
parameter_list|)
value|((x)>> 4)
end_define

begin_define
define|#
directive|define
name|ELF64_ST_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((unsigned int) x)& 0xf)
end_define

begin_define
define|#
directive|define
name|ELF64_ST_INFO
parameter_list|(
name|b
parameter_list|,
name|t
parameter_list|)
value|(((b)<< 4) + ((t)& 0xf))
end_define

begin_comment
comment|/* Symbol Binding - ELF32_ST_BIND - st_info */
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
name|STB_NUM
value|3
end_define

begin_comment
comment|/* number of symbol bindings */
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
comment|/* Symbol type - ELF32_ST_TYPE - st_info */
end_comment

begin_define
define|#
directive|define
name|STT_NOTYPE
value|0
end_define

begin_comment
comment|/* not specified */
end_comment

begin_define
define|#
directive|define
name|STT_OBJECT
value|1
end_define

begin_comment
comment|/* data object */
end_comment

begin_define
define|#
directive|define
name|STT_FUNC
value|2
end_define

begin_comment
comment|/* function */
end_comment

begin_define
define|#
directive|define
name|STT_SECTION
value|3
end_define

begin_comment
comment|/* section */
end_comment

begin_define
define|#
directive|define
name|STT_FILE
value|4
end_define

begin_comment
comment|/* file */
end_comment

begin_define
define|#
directive|define
name|STT_NUM
value|5
end_define

begin_comment
comment|/* number of symbol types */
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
comment|/* Relocation entry with implicit addend */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* offset of relocation */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* symbol table index and type */
block|}
name|Elf32_Rel
typedef|;
end_typedef

begin_comment
comment|/* Relocation entry with explicit addend */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* offset of relocation */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* symbol table index and type */
name|Elf32_Sword
name|r_addend
decl_stmt|;
block|}
name|Elf32_Rela
typedef|;
end_typedef

begin_comment
comment|/* Extract relocation info - r_info */
end_comment

begin_define
define|#
directive|define
name|ELF32_R_SYM
parameter_list|(
name|i
parameter_list|)
value|((i)>> 8)
end_define

begin_define
define|#
directive|define
name|ELF32_R_TYPE
parameter_list|(
name|i
parameter_list|)
value|((unsigned char) (i))
end_define

begin_define
define|#
directive|define
name|ELF32_R_INFO
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(((s)<< 8) + (unsigned char)(t))
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|r_offset
decl_stmt|;
comment|/* where to do it */
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|/* index& type of relocation */
block|}
name|Elf64_Rel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|r_offset
decl_stmt|;
comment|/* where to do it */
name|Elf64_Xword
name|r_info
decl_stmt|;
comment|/* index& type of relocation */
name|Elf64_Sxword
name|r_addend
decl_stmt|;
comment|/* adjustment value */
block|}
name|Elf64_Rela
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF64_R_SYM
parameter_list|(
name|info
parameter_list|)
value|((info)>> 32)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE
parameter_list|(
name|info
parameter_list|)
value|((info)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|ELF64_R_INFO
parameter_list|(
name|s
parameter_list|,
name|t
parameter_list|)
value|(((s)<< 32) + (u_int32_t)(t))
end_define

begin_comment
comment|/* Program Header */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
comment|/* segment type */
name|Elf32_Off
name|p_offset
decl_stmt|;
comment|/* segment offset */
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
comment|/* virtual address of segment */
name|Elf32_Addr
name|p_paddr
decl_stmt|;
comment|/* physical address - ignored? */
name|Elf32_Word
name|p_filesz
decl_stmt|;
comment|/* number of bytes in file for seg. */
name|Elf32_Word
name|p_memsz
decl_stmt|;
comment|/* number of bytes in mem. for seg. */
name|Elf32_Word
name|p_flags
decl_stmt|;
comment|/* flags */
name|Elf32_Word
name|p_align
decl_stmt|;
comment|/* memory alignment */
block|}
name|Elf32_Phdr
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|p_type
decl_stmt|;
comment|/* entry type */
name|Elf64_Half
name|p_flags
decl_stmt|;
comment|/* flags */
name|Elf64_Off
name|p_offset
decl_stmt|;
comment|/* offset */
name|Elf64_Addr
name|p_vaddr
decl_stmt|;
comment|/* virtual address */
name|Elf64_Addr
name|p_paddr
decl_stmt|;
comment|/* physical address */
name|Elf64_Xword
name|p_filesz
decl_stmt|;
comment|/* file size */
name|Elf64_Xword
name|p_memsz
decl_stmt|;
comment|/* memory size */
name|Elf64_Xword
name|p_align
decl_stmt|;
comment|/* memory& file alignment */
block|}
name|Elf64_Phdr
typedef|;
end_typedef

begin_comment
comment|/* Segment types - p_type */
end_comment

begin_define
define|#
directive|define
name|PT_NULL
value|0
end_define

begin_comment
comment|/* unused */
end_comment

begin_define
define|#
directive|define
name|PT_LOAD
value|1
end_define

begin_comment
comment|/* loadable segment */
end_comment

begin_define
define|#
directive|define
name|PT_DYNAMIC
value|2
end_define

begin_comment
comment|/* dynamic linking section */
end_comment

begin_define
define|#
directive|define
name|PT_INTERP
value|3
end_define

begin_comment
comment|/* the RTLD */
end_comment

begin_define
define|#
directive|define
name|PT_NOTE
value|4
end_define

begin_comment
comment|/* auxiliary information */
end_comment

begin_define
define|#
directive|define
name|PT_SHLIB
value|5
end_define

begin_comment
comment|/* reserved - purpose undefined */
end_comment

begin_define
define|#
directive|define
name|PT_PHDR
value|6
end_define

begin_comment
comment|/* program header */
end_comment

begin_define
define|#
directive|define
name|PT_NUM
value|7
end_define

begin_comment
comment|/* Number of segment types */
end_comment

begin_define
define|#
directive|define
name|PT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|PT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/*  specific segment types */
end_comment

begin_comment
comment|/* Segment flags - p_flags */
end_comment

begin_define
define|#
directive|define
name|PF_X
value|0x1
end_define

begin_comment
comment|/* Executable */
end_comment

begin_define
define|#
directive|define
name|PF_W
value|0x2
end_define

begin_comment
comment|/* Writable */
end_comment

begin_define
define|#
directive|define
name|PF_R
value|0x4
end_define

begin_comment
comment|/* Readable */
end_comment

begin_define
define|#
directive|define
name|PF_MASKPROC
value|0xf0000000
end_define

begin_comment
comment|/* reserved bits for processor */
end_comment

begin_comment
comment|/*  specific segment flags */
end_comment

begin_comment
comment|/* Dynamic structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|d_tag
decl_stmt|;
comment|/* controls meaning of d_val */
union|union
block|{
name|Elf32_Word
name|d_val
decl_stmt|;
comment|/* Multiple meanings - see d_tag */
name|Elf32_Addr
name|d_ptr
decl_stmt|;
comment|/* program virtual address */
block|}
name|d_un
union|;
block|}
name|Elf32_Dyn
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Xword
name|d_tag
decl_stmt|;
comment|/* controls meaning of d_val */
union|union
block|{
name|Elf64_Addr
name|d_ptr
decl_stmt|;
name|Elf64_Xword
name|d_val
decl_stmt|;
block|}
name|d_un
union|;
block|}
name|Elf64_Dyn
typedef|;
end_typedef

begin_comment
comment|/* Dynamic Array Tags - d_tag */
end_comment

begin_define
define|#
directive|define
name|DT_NULL
value|0
end_define

begin_comment
comment|/* marks end of _DYNAMIC array */
end_comment

begin_define
define|#
directive|define
name|DT_NEEDED
value|1
end_define

begin_comment
comment|/* string table offset of needed lib */
end_comment

begin_define
define|#
directive|define
name|DT_PLTRELSZ
value|2
end_define

begin_comment
comment|/* size of relocation entries in PLT */
end_comment

begin_define
define|#
directive|define
name|DT_PLTGOT
value|3
end_define

begin_comment
comment|/* address PLT/GOT */
end_comment

begin_define
define|#
directive|define
name|DT_HASH
value|4
end_define

begin_comment
comment|/* address of symbol hash table */
end_comment

begin_define
define|#
directive|define
name|DT_STRTAB
value|5
end_define

begin_comment
comment|/* address of string table */
end_comment

begin_define
define|#
directive|define
name|DT_SYMTAB
value|6
end_define

begin_comment
comment|/* address of symbol table */
end_comment

begin_define
define|#
directive|define
name|DT_RELA
value|7
end_define

begin_comment
comment|/* address of relocation table */
end_comment

begin_define
define|#
directive|define
name|DT_RELASZ
value|8
end_define

begin_comment
comment|/* size of relocation table */
end_comment

begin_define
define|#
directive|define
name|DT_RELAENT
value|9
end_define

begin_comment
comment|/* size of relocation entry */
end_comment

begin_define
define|#
directive|define
name|DT_STRSZ
value|10
end_define

begin_comment
comment|/* size of string table */
end_comment

begin_define
define|#
directive|define
name|DT_SYMENT
value|11
end_define

begin_comment
comment|/* size of symbol table entry */
end_comment

begin_define
define|#
directive|define
name|DT_INIT
value|12
end_define

begin_comment
comment|/* address of initialization func. */
end_comment

begin_define
define|#
directive|define
name|DT_FINI
value|13
end_define

begin_comment
comment|/* address of termination function */
end_comment

begin_define
define|#
directive|define
name|DT_SONAME
value|14
end_define

begin_comment
comment|/* string table offset of shared obj */
end_comment

begin_define
define|#
directive|define
name|DT_RPATH
value|15
end_define

begin_comment
comment|/* string table offset of library 					   search path */
end_comment

begin_define
define|#
directive|define
name|DT_SYMBOLIC
value|16
end_define

begin_comment
comment|/* start sym search in shared obj. */
end_comment

begin_define
define|#
directive|define
name|DT_REL
value|17
end_define

begin_comment
comment|/* address of rel. tbl. w addends */
end_comment

begin_define
define|#
directive|define
name|DT_RELSZ
value|18
end_define

begin_comment
comment|/* size of DT_REL relocation table */
end_comment

begin_define
define|#
directive|define
name|DT_RELENT
value|19
end_define

begin_comment
comment|/* size of DT_REL relocation entry */
end_comment

begin_define
define|#
directive|define
name|DT_PLTREL
value|20
end_define

begin_comment
comment|/* PLT referenced relocation entry */
end_comment

begin_define
define|#
directive|define
name|DT_DEBUG
value|21
end_define

begin_comment
comment|/* bugger */
end_comment

begin_define
define|#
directive|define
name|DT_TEXTREL
value|22
end_define

begin_comment
comment|/* Allow rel. mod. to unwritable seg */
end_comment

begin_define
define|#
directive|define
name|DT_JMPREL
value|23
end_define

begin_comment
comment|/* add. of PLT's relocation entries */
end_comment

begin_define
define|#
directive|define
name|DT_BIND_NOW
value|24
end_define

begin_comment
comment|/* Bind now regardless of env setting */
end_comment

begin_define
define|#
directive|define
name|DT_NUM
value|25
end_define

begin_comment
comment|/* Number used. */
end_comment

begin_define
define|#
directive|define
name|DT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* reserved range for processor */
end_comment

begin_define
define|#
directive|define
name|DT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/*  specific dynamic array tags */
end_comment

begin_comment
comment|/* Standard ELF hashing function */
end_comment

begin_function_decl
name|unsigned
name|int
name|elf_hash
parameter_list|(
specifier|const
name|unsigned
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Note Definitions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|namesz
decl_stmt|;
name|Elf32_Word
name|descsz
decl_stmt|;
name|Elf32_Word
name|type
decl_stmt|;
block|}
name|Elf32_Note
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf64_Half
name|namesz
decl_stmt|;
name|Elf64_Half
name|descsz
decl_stmt|;
name|Elf64_Half
name|type
decl_stmt|;
block|}
name|Elf64_Note
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ELFSIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONCAT
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|__CONCAT(x,y)
end_define

begin_define
define|#
directive|define
name|ELFNAME
parameter_list|(
name|x
parameter_list|)
value|CONCAT(elf,CONCAT(ELFSIZE,CONCAT(_,x)))
end_define

begin_define
define|#
directive|define
name|ELFNAME2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|CONCAT(x,CONCAT(_elf,CONCAT(ELFSIZE,CONCAT(_,y))))
end_define

begin_define
define|#
directive|define
name|ELFNAMEEND
parameter_list|(
name|x
parameter_list|)
value|CONCAT(x,CONCAT(_elf,ELFSIZE))
end_define

begin_define
define|#
directive|define
name|ELFDEFNNAME
parameter_list|(
name|x
parameter_list|)
value|CONCAT(ELF,CONCAT(ELFSIZE,CONCAT(_,x)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ELFSIZE
argument_list|)
operator|&&
operator|(
name|ELFSIZE
operator|==
literal|32
operator|)
end_if

begin_define
define|#
directive|define
name|Elf_Ehdr
value|Elf32_Ehdr
end_define

begin_define
define|#
directive|define
name|Elf_Phdr
value|Elf32_Phdr
end_define

begin_define
define|#
directive|define
name|Elf_Shdr
value|Elf32_Shdr
end_define

begin_define
define|#
directive|define
name|Elf_Sym
value|Elf32_Sym
end_define

begin_define
define|#
directive|define
name|Elf_Rel
value|Elf32_Rel
end_define

begin_define
define|#
directive|define
name|Elf_RelA
value|Elf32_Rela
end_define

begin_define
define|#
directive|define
name|Elf_Dyn
value|Elf32_Dyn
end_define

begin_define
define|#
directive|define
name|Elf_Word
value|Elf32_Word
end_define

begin_define
define|#
directive|define
name|Elf_Sword
value|Elf32_Sword
end_define

begin_define
define|#
directive|define
name|Elf_Addr
value|Elf32_Addr
end_define

begin_define
define|#
directive|define
name|Elf_Off
value|Elf32_Off
end_define

begin_define
define|#
directive|define
name|Elf_Nhdr
value|Elf32_Nhdr
end_define

begin_define
define|#
directive|define
name|Elf_Note
value|Elf32_Note
end_define

begin_define
define|#
directive|define
name|ELF_R_SYM
value|ELF32_R_SYM
end_define

begin_define
define|#
directive|define
name|ELF_R_TYPE
value|ELF32_R_TYPE
end_define

begin_define
define|#
directive|define
name|ELF_R_INFO
value|ELF32_R_INFO
end_define

begin_define
define|#
directive|define
name|ELFCLASS
value|ELFCLASS32
end_define

begin_define
define|#
directive|define
name|ELF_ST_BIND
value|ELF32_ST_BIND
end_define

begin_define
define|#
directive|define
name|ELF_ST_TYPE
value|ELF32_ST_TYPE
end_define

begin_define
define|#
directive|define
name|ELF_ST_INFO
value|ELF32_ST_INFO
end_define

begin_define
define|#
directive|define
name|AuxInfo
value|Aux32Info
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ELFSIZE
argument_list|)
operator|&&
operator|(
name|ELFSIZE
operator|==
literal|64
operator|)
end_elif

begin_define
define|#
directive|define
name|Elf_Ehdr
value|Elf64_Ehdr
end_define

begin_define
define|#
directive|define
name|Elf_Phdr
value|Elf64_Phdr
end_define

begin_define
define|#
directive|define
name|Elf_Shdr
value|Elf64_Shdr
end_define

begin_define
define|#
directive|define
name|Elf_Sym
value|Elf64_Sym
end_define

begin_define
define|#
directive|define
name|Elf_Rel
value|Elf64_Rel
end_define

begin_define
define|#
directive|define
name|Elf_RelA
value|Elf64_Rela
end_define

begin_define
define|#
directive|define
name|Elf_Dyn
value|Elf64_Dyn
end_define

begin_define
define|#
directive|define
name|Elf_Word
value|Elf64_Word
end_define

begin_define
define|#
directive|define
name|Elf_Sword
value|Elf64_Sword
end_define

begin_define
define|#
directive|define
name|Elf_Addr
value|Elf64_Addr
end_define

begin_define
define|#
directive|define
name|Elf_Off
value|Elf64_Off
end_define

begin_define
define|#
directive|define
name|Elf_Nhdr
value|Elf64_Nhdr
end_define

begin_define
define|#
directive|define
name|Elf_Note
value|Elf64_Note
end_define

begin_define
define|#
directive|define
name|ELF_R_SYM
value|ELF64_R_SYM
end_define

begin_define
define|#
directive|define
name|ELF_R_TYPE
value|ELF64_R_TYPE
end_define

begin_define
define|#
directive|define
name|ELF_R_INFO
value|ELF64_R_INFO
end_define

begin_define
define|#
directive|define
name|ELFCLASS
value|ELFCLASS64
end_define

begin_define
define|#
directive|define
name|ELF_ST_BIND
value|ELF64_ST_BIND
end_define

begin_define
define|#
directive|define
name|ELF_ST_TYPE
value|ELF64_ST_TYPE
end_define

begin_define
define|#
directive|define
name|ELF_ST_INFO
value|ELF64_ST_INFO
end_define

begin_define
define|#
directive|define
name|AuxInfo
value|Aux64Info
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_ELFSTRUCTS_H__ */
end_comment

end_unit

