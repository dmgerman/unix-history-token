begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1996-1997 John D. Polstra.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $Id: elf32.h,v 1.2 1997/08/30 18:58:31 peter Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ELF32_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ELF32_H_
value|1
end_define

begin_comment
comment|/*  * ELF definitions common to all 32-bit architectures.  */
end_comment

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Addr
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|Elf32_Half
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Off
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|Elf32_Sword
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|Elf32_Word
typedef|;
end_typedef

begin_comment
comment|/*  * ELF header.  */
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
comment|/* File identification. */
name|Elf32_Half
name|e_type
decl_stmt|;
comment|/* File type. */
name|Elf32_Half
name|e_machine
decl_stmt|;
comment|/* Machine architecture. */
name|Elf32_Word
name|e_version
decl_stmt|;
comment|/* ELF format version. */
name|Elf32_Addr
name|e_entry
decl_stmt|;
comment|/* Entry point. */
name|Elf32_Off
name|e_phoff
decl_stmt|;
comment|/* Program header file offset. */
name|Elf32_Off
name|e_shoff
decl_stmt|;
comment|/* Section header file offset. */
name|Elf32_Word
name|e_flags
decl_stmt|;
comment|/* Architecture-specific flags. */
name|Elf32_Half
name|e_ehsize
decl_stmt|;
comment|/* Size of ELF header in bytes. */
name|Elf32_Half
name|e_phentsize
decl_stmt|;
comment|/* Size of program header entry. */
name|Elf32_Half
name|e_phnum
decl_stmt|;
comment|/* Number of program header entries. */
name|Elf32_Half
name|e_shentsize
decl_stmt|;
comment|/* Size of section header entry. */
name|Elf32_Half
name|e_shnum
decl_stmt|;
comment|/* Number of section header entries. */
name|Elf32_Half
name|e_shstrndx
decl_stmt|;
comment|/* Section name strings section. */
block|}
name|Elf32_Ehdr
typedef|;
end_typedef

begin_comment
comment|/* Indexes into the e_ident array. */
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
name|EI_PAD
value|7
end_define

begin_comment
comment|/* Start of padding (per SVR4 ABI). */
end_comment

begin_define
define|#
directive|define
name|EI_BRAND
value|8
end_define

begin_comment
comment|/* Start of architecture identification. */
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
comment|/* Extensions */
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
name|EM_PPC
value|20
end_define

begin_comment
comment|/* PowerPC */
end_comment

begin_comment
comment|/*  * Section header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|sh_name
decl_stmt|;
comment|/* Section name (index into the 					   section header string table). */
name|Elf32_Word
name|sh_type
decl_stmt|;
comment|/* Section type. */
name|Elf32_Word
name|sh_flags
decl_stmt|;
comment|/* Section flags. */
name|Elf32_Addr
name|sh_addr
decl_stmt|;
comment|/* Address in memory image. */
name|Elf32_Off
name|sh_offset
decl_stmt|;
comment|/* Offset in file. */
name|Elf32_Word
name|sh_size
decl_stmt|;
comment|/* Size in bytes. */
name|Elf32_Word
name|sh_link
decl_stmt|;
comment|/* Index of a related section. */
name|Elf32_Word
name|sh_info
decl_stmt|;
comment|/* Depends on section type. */
name|Elf32_Word
name|sh_addralign
decl_stmt|;
comment|/* Alignment in bytes. */
name|Elf32_Word
name|sh_entsize
decl_stmt|;
comment|/* Size of each entry in section. */
block|}
name|Elf32_Shdr
typedef|;
end_typedef

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
comment|/*  * Program header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|p_type
decl_stmt|;
comment|/* Entry type. */
name|Elf32_Off
name|p_offset
decl_stmt|;
comment|/* File offset of contents. */
name|Elf32_Addr
name|p_vaddr
decl_stmt|;
comment|/* Virtual address in memory image. */
name|Elf32_Addr
name|p_paddr
decl_stmt|;
comment|/* Physical address (not used). */
name|Elf32_Word
name|p_filesz
decl_stmt|;
comment|/* Size of contents in file. */
name|Elf32_Word
name|p_memsz
decl_stmt|;
comment|/* Size of contents in memory. */
name|Elf32_Word
name|p_flags
decl_stmt|;
comment|/* Access permission flags. */
name|Elf32_Word
name|p_align
decl_stmt|;
comment|/* Alignment in memory and file. */
block|}
name|Elf32_Phdr
typedef|;
end_typedef

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
comment|/*  * Dynamic structure.  The ".dynamic" section contains an array of them.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Sword
name|d_tag
decl_stmt|;
comment|/* Entry type. */
union|union
block|{
name|Elf32_Word
name|d_val
decl_stmt|;
comment|/* Integer value. */
name|Elf32_Addr
name|d_ptr
decl_stmt|;
comment|/* Address value. */
block|}
name|d_un
union|;
block|}
name|Elf32_Dyn
typedef|;
end_typedef

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
comment|/* Address of Elf32_Rela relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELASZ
value|8
end_define

begin_comment
comment|/* Total size of Elf32_Rela relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELAENT
value|9
end_define

begin_comment
comment|/* Size of each Elf32_Rela relocation entry. */
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
comment|/* Address of Elf32_Rel relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELSZ
value|18
end_define

begin_comment
comment|/* Total size of Elf32_Rel relocations. */
end_comment

begin_define
define|#
directive|define
name|DT_RELENT
value|19
end_define

begin_comment
comment|/* Size of each Elf32_Rel relocation. */
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
comment|/*  * Relocation entries.  */
end_comment

begin_comment
comment|/* Relocations that don't need an addend field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
block|}
name|Elf32_Rel
typedef|;
end_typedef

begin_comment
comment|/* Relocations that need an addend field. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Addr
name|r_offset
decl_stmt|;
comment|/* Location to be relocated. */
name|Elf32_Word
name|r_info
decl_stmt|;
comment|/* Relocation type and symbol index. */
name|Elf32_Sword
name|r_addend
decl_stmt|;
comment|/* Addend. */
block|}
name|Elf32_Rela
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of r_info. */
end_comment

begin_define
define|#
directive|define
name|ELF32_R_SYM
parameter_list|(
name|info
parameter_list|)
value|((info)>> 8)
end_define

begin_define
define|#
directive|define
name|ELF32_R_TYPE
parameter_list|(
name|info
parameter_list|)
value|((unsigned char)(info))
end_define

begin_comment
comment|/* Macro for constructing r_info from field values. */
end_comment

begin_define
define|#
directive|define
name|ELF32_R_INFO
parameter_list|(
name|sym
parameter_list|,
name|type
parameter_list|)
value|(((sym)<< 8) + (unsigned char)(type))
end_define

begin_comment
comment|/*  * Symbol table entries.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Elf32_Word
name|st_name
decl_stmt|;
comment|/* String table index of name. */
name|Elf32_Addr
name|st_value
decl_stmt|;
comment|/* Symbol value. */
name|Elf32_Word
name|st_size
decl_stmt|;
comment|/* Size of associated object. */
name|unsigned
name|char
name|st_info
decl_stmt|;
comment|/* Type and binding information. */
name|unsigned
name|char
name|st_other
decl_stmt|;
comment|/* Reserved (not used). */
name|Elf32_Half
name|st_shndx
decl_stmt|;
comment|/* Section index of symbol. */
block|}
name|Elf32_Sym
typedef|;
end_typedef

begin_comment
comment|/* Macros for accessing the fields of st_info. */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_BIND
parameter_list|(
name|info
parameter_list|)
value|((info)>> 4)
end_define

begin_define
define|#
directive|define
name|ELF32_ST_TYPE
parameter_list|(
name|info
parameter_list|)
value|((info)& 0xf)
end_define

begin_comment
comment|/* Macro for constructing st_info from field values. */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_INFO
parameter_list|(
name|bind
parameter_list|,
name|type
parameter_list|)
value|(((bind)<< 4) + ((type)& 0xf))
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
comment|/* !_SYS_ELF32_H_ */
end_comment

end_unit

