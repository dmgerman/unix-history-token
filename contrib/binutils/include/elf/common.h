begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright (C) 1991, 92, 93, 94, 95, 96, 1997 Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file is part of ELF support for BFD, and contains the portions    that are common to both the internal and external representations.    For example, ELFMAG0 is the byte 0x7F in both the internal (in-memory)    and external (in-file) representations. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_COMMON_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_COMMON_H
end_define

begin_comment
comment|/* Fields in e_ident[] */
end_comment

begin_define
define|#
directive|define
name|EI_MAG0
value|0
end_define

begin_comment
comment|/* File identification byte 0 index */
end_comment

begin_define
define|#
directive|define
name|ELFMAG0
value|0x7F
end_define

begin_comment
comment|/* Magic number byte 0 */
end_comment

begin_define
define|#
directive|define
name|EI_MAG1
value|1
end_define

begin_comment
comment|/* File identification byte 1 index */
end_comment

begin_define
define|#
directive|define
name|ELFMAG1
value|'E'
end_define

begin_comment
comment|/* Magic number byte 1 */
end_comment

begin_define
define|#
directive|define
name|EI_MAG2
value|2
end_define

begin_comment
comment|/* File identification byte 2 index */
end_comment

begin_define
define|#
directive|define
name|ELFMAG2
value|'L'
end_define

begin_comment
comment|/* Magic number byte 2 */
end_comment

begin_define
define|#
directive|define
name|EI_MAG3
value|3
end_define

begin_comment
comment|/* File identification byte 3 index */
end_comment

begin_define
define|#
directive|define
name|ELFMAG3
value|'F'
end_define

begin_comment
comment|/* Magic number byte 3 */
end_comment

begin_define
define|#
directive|define
name|EI_CLASS
value|4
end_define

begin_comment
comment|/* File class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASSNONE
value|0
end_define

begin_comment
comment|/* Invalid class */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS32
value|1
end_define

begin_comment
comment|/* 32-bit objects */
end_comment

begin_define
define|#
directive|define
name|ELFCLASS64
value|2
end_define

begin_comment
comment|/* 64-bit objects */
end_comment

begin_define
define|#
directive|define
name|EI_DATA
value|5
end_define

begin_comment
comment|/* Data encoding */
end_comment

begin_define
define|#
directive|define
name|ELFDATANONE
value|0
end_define

begin_comment
comment|/* Invalid data encoding */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2LSB
value|1
end_define

begin_comment
comment|/* 2's complement, little endian */
end_comment

begin_define
define|#
directive|define
name|ELFDATA2MSB
value|2
end_define

begin_comment
comment|/* 2's complement, big endian */
end_comment

begin_define
define|#
directive|define
name|EI_VERSION
value|6
end_define

begin_comment
comment|/* File version */
end_comment

begin_define
define|#
directive|define
name|EI_PAD
value|7
end_define

begin_comment
comment|/* Start of padding bytes */
end_comment

begin_comment
comment|/* Values for e_type, which identifies the object file type */
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
comment|/* Relocatable file */
end_comment

begin_define
define|#
directive|define
name|ET_EXEC
value|2
end_define

begin_comment
comment|/* Executable file */
end_comment

begin_define
define|#
directive|define
name|ET_DYN
value|3
end_define

begin_comment
comment|/* Shared object file */
end_comment

begin_define
define|#
directive|define
name|ET_CORE
value|4
end_define

begin_comment
comment|/* Core file */
end_comment

begin_define
define|#
directive|define
name|ET_LOPROC
value|0xFF00
end_define

begin_comment
comment|/* Processor-specific */
end_comment

begin_define
define|#
directive|define
name|ET_HIPROC
value|0xFFFF
end_define

begin_comment
comment|/* Processor-specific */
end_comment

begin_comment
comment|/* Values for e_machine, which identifies the architecture */
end_comment

begin_define
define|#
directive|define
name|EM_NONE
value|0
end_define

begin_comment
comment|/* No machine */
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
comment|/* SUN SPARC */
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
comment|/* Motorola m68k family */
end_comment

begin_define
define|#
directive|define
name|EM_88K
value|5
end_define

begin_comment
comment|/* Motorola m88k family */
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
comment|/* MIPS R3000 (officially, big-endian only) */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_RS4_BE
value|10
end_define

begin_comment
comment|/* MIPS R4000 big-endian */
end_comment

begin_define
define|#
directive|define
name|EM_SPARC64
value|11
end_define

begin_comment
comment|/* SPARC v9 (not official) 64-bit */
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
comment|/* Sun's "v8plus" */
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
name|EM_SH
value|42
end_define

begin_comment
comment|/* Hitachi SH */
end_comment

begin_comment
comment|/* If it is necessary to assign new unofficial EM_* values, please pick large    random numbers (0x8523, 0xa7f2, etc.) to minimize the chances of collision    with official or non-GNU unofficial values.     NOTE: Do not just increment the most recent number by one.    Somebody else somewhere will do exactly the same thing, and you    will have a collision.  Instead, pick a random number.  */
end_comment

begin_comment
comment|/* Cygnus PowerPC ELF backend.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_POWERPC
value|0x9025
end_define

begin_comment
comment|/* Old version of PowerPC, this should be removed shortly. */
end_comment

begin_define
define|#
directive|define
name|EM_PPC_OLD
value|17
end_define

begin_comment
comment|/* Cygnus M32R ELF backend.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_M32R
value|0x9041
end_define

begin_comment
comment|/* Alpha backend magic number.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_ALPHA
value|0x9026
end_define

begin_comment
comment|/* D10V backend magic number.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_D10V
value|0x7650
end_define

begin_comment
comment|/* mn10200 and mn10300 backend magic numbers.    Written in the absense of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_MN10200
value|0xdead
end_define

begin_define
define|#
directive|define
name|EM_CYGNUS_MN10300
value|0xbeef
end_define

begin_comment
comment|/* See the above comment before you add a new EM_* value here.  */
end_comment

begin_comment
comment|/* Values for e_version */
end_comment

begin_define
define|#
directive|define
name|EV_NONE
value|0
end_define

begin_comment
comment|/* Invalid ELF version */
end_comment

begin_define
define|#
directive|define
name|EV_CURRENT
value|1
end_define

begin_comment
comment|/* Current version */
end_comment

begin_comment
comment|/* Values for program header, p_type field */
end_comment

begin_define
define|#
directive|define
name|PT_NULL
value|0
end_define

begin_comment
comment|/* Program header table entry unused */
end_comment

begin_define
define|#
directive|define
name|PT_LOAD
value|1
end_define

begin_comment
comment|/* Loadable program segment */
end_comment

begin_define
define|#
directive|define
name|PT_DYNAMIC
value|2
end_define

begin_comment
comment|/* Dynamic linking information */
end_comment

begin_define
define|#
directive|define
name|PT_INTERP
value|3
end_define

begin_comment
comment|/* Program interpreter */
end_comment

begin_define
define|#
directive|define
name|PT_NOTE
value|4
end_define

begin_comment
comment|/* Auxiliary information */
end_comment

begin_define
define|#
directive|define
name|PT_SHLIB
value|5
end_define

begin_comment
comment|/* Reserved, unspecified semantics */
end_comment

begin_define
define|#
directive|define
name|PT_PHDR
value|6
end_define

begin_comment
comment|/* Entry for header table itself */
end_comment

begin_define
define|#
directive|define
name|PT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* Processor-specific */
end_comment

begin_define
define|#
directive|define
name|PT_HIPROC
value|0x7FFFFFFF
end_define

begin_comment
comment|/* Processor-specific */
end_comment

begin_comment
comment|/* Program segment permissions, in program header p_flags field */
end_comment

begin_define
define|#
directive|define
name|PF_X
value|(1<< 0)
end_define

begin_comment
comment|/* Segment is executable */
end_comment

begin_define
define|#
directive|define
name|PF_W
value|(1<< 1)
end_define

begin_comment
comment|/* Segment is writable */
end_comment

begin_define
define|#
directive|define
name|PF_R
value|(1<< 2)
end_define

begin_comment
comment|/* Segment is readable */
end_comment

begin_define
define|#
directive|define
name|PF_MASKPROC
value|0xF0000000
end_define

begin_comment
comment|/* Processor-specific reserved bits */
end_comment

begin_comment
comment|/* Values for section header, sh_type field */
end_comment

begin_define
define|#
directive|define
name|SHT_NULL
value|0
end_define

begin_comment
comment|/* Section header table entry unused */
end_comment

begin_define
define|#
directive|define
name|SHT_PROGBITS
value|1
end_define

begin_comment
comment|/* Program specific (private) data */
end_comment

begin_define
define|#
directive|define
name|SHT_SYMTAB
value|2
end_define

begin_comment
comment|/* Link editing symbol table */
end_comment

begin_define
define|#
directive|define
name|SHT_STRTAB
value|3
end_define

begin_comment
comment|/* A string table */
end_comment

begin_define
define|#
directive|define
name|SHT_RELA
value|4
end_define

begin_comment
comment|/* Relocation entries with addends */
end_comment

begin_define
define|#
directive|define
name|SHT_HASH
value|5
end_define

begin_comment
comment|/* A symbol hash table */
end_comment

begin_define
define|#
directive|define
name|SHT_DYNAMIC
value|6
end_define

begin_comment
comment|/* Information for dynamic linking */
end_comment

begin_define
define|#
directive|define
name|SHT_NOTE
value|7
end_define

begin_comment
comment|/* Information that marks file */
end_comment

begin_define
define|#
directive|define
name|SHT_NOBITS
value|8
end_define

begin_comment
comment|/* Section occupies no space in file */
end_comment

begin_define
define|#
directive|define
name|SHT_REL
value|9
end_define

begin_comment
comment|/* Relocation entries, no addends */
end_comment

begin_define
define|#
directive|define
name|SHT_SHLIB
value|10
end_define

begin_comment
comment|/* Reserved, unspecified semantics */
end_comment

begin_define
define|#
directive|define
name|SHT_DYNSYM
value|11
end_define

begin_comment
comment|/* Dynamic linking symbol table */
end_comment

begin_comment
comment|/* The next three section types are defined by Solaris, and are named    SHT_SUNW*.  We use them in GNU code, so we also define SHT_GNU*    versions.  */
end_comment

begin_define
define|#
directive|define
name|SHT_SUNW_verdef
value|0x6ffffffd
end_define

begin_comment
comment|/* Versions defined by file */
end_comment

begin_define
define|#
directive|define
name|SHT_SUNW_verneed
value|0x6ffffffe
end_define

begin_comment
comment|/* Versions needed by file */
end_comment

begin_define
define|#
directive|define
name|SHT_SUNW_versym
value|0x6fffffff
end_define

begin_comment
comment|/* Symbol versions */
end_comment

begin_define
define|#
directive|define
name|SHT_GNU_verdef
value|SHT_SUNW_verdef
end_define

begin_define
define|#
directive|define
name|SHT_GNU_verneed
value|SHT_SUNW_verneed
end_define

begin_define
define|#
directive|define
name|SHT_GNU_versym
value|SHT_SUNW_versym
end_define

begin_define
define|#
directive|define
name|SHT_LOPROC
value|0x70000000
end_define

begin_comment
comment|/* Processor-specific semantics, lo */
end_comment

begin_define
define|#
directive|define
name|SHT_HIPROC
value|0x7FFFFFFF
end_define

begin_comment
comment|/* Processor-specific semantics, hi */
end_comment

begin_define
define|#
directive|define
name|SHT_LOUSER
value|0x80000000
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_define
define|#
directive|define
name|SHT_HIUSER
value|0x8FFFFFFF
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_comment
comment|/* Values for section header, sh_flags field */
end_comment

begin_define
define|#
directive|define
name|SHF_WRITE
value|(1<< 0)
end_define

begin_comment
comment|/* Writable data during execution */
end_comment

begin_define
define|#
directive|define
name|SHF_ALLOC
value|(1<< 1)
end_define

begin_comment
comment|/* Occupies memory during execution */
end_comment

begin_define
define|#
directive|define
name|SHF_EXECINSTR
value|(1<< 2)
end_define

begin_comment
comment|/* Executable machine instructions */
end_comment

begin_define
define|#
directive|define
name|SHF_MASKPROC
value|0xF0000000
end_define

begin_comment
comment|/* Processor-specific semantics */
end_comment

begin_comment
comment|/* Values of note segment descriptor types for core files. */
end_comment

begin_define
define|#
directive|define
name|NT_PRSTATUS
value|1
end_define

begin_comment
comment|/* Contains copy of prstatus struct */
end_comment

begin_define
define|#
directive|define
name|NT_FPREGSET
value|2
end_define

begin_comment
comment|/* Contains copy of fpregset struct */
end_comment

begin_define
define|#
directive|define
name|NT_PRPSINFO
value|3
end_define

begin_comment
comment|/* Contains copy of prpsinfo struct */
end_comment

begin_comment
comment|/* Values of note segment descriptor types for object files.  */
end_comment

begin_comment
comment|/* (Only for hppa right now.  Should this be moved elsewhere?)  */
end_comment

begin_define
define|#
directive|define
name|NT_VERSION
value|1
end_define

begin_comment
comment|/* Contains a version string.  */
end_comment

begin_comment
comment|/* These three macros disassemble and assemble a symbol table st_info field,    which contains the symbol binding and symbol type.  The STB_ and STT_    defines identify the binding and type. */
end_comment

begin_define
define|#
directive|define
name|ELF_ST_BIND
parameter_list|(
name|val
parameter_list|)
value|(((unsigned int)(val))>> 4)
end_define

begin_define
define|#
directive|define
name|ELF_ST_TYPE
parameter_list|(
name|val
parameter_list|)
value|((val)& 0xF)
end_define

begin_define
define|#
directive|define
name|ELF_ST_INFO
parameter_list|(
name|bind
parameter_list|,
name|type
parameter_list|)
value|(((bind)<< 4) + ((type)& 0xF))
end_define

begin_define
define|#
directive|define
name|STN_UNDEF
value|0
end_define

begin_comment
comment|/* undefined symbol index */
end_comment

begin_define
define|#
directive|define
name|STB_LOCAL
value|0
end_define

begin_comment
comment|/* Symbol not visible outside obj */
end_comment

begin_define
define|#
directive|define
name|STB_GLOBAL
value|1
end_define

begin_comment
comment|/* Symbol visible outside obj */
end_comment

begin_define
define|#
directive|define
name|STB_WEAK
value|2
end_define

begin_comment
comment|/* Like globals, lower precedence */
end_comment

begin_define
define|#
directive|define
name|STB_LOPROC
value|13
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_define
define|#
directive|define
name|STB_HIPROC
value|15
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_define
define|#
directive|define
name|STT_NOTYPE
value|0
end_define

begin_comment
comment|/* Symbol type is unspecified */
end_comment

begin_define
define|#
directive|define
name|STT_OBJECT
value|1
end_define

begin_comment
comment|/* Symbol is a data object */
end_comment

begin_define
define|#
directive|define
name|STT_FUNC
value|2
end_define

begin_comment
comment|/* Symbol is a code object */
end_comment

begin_define
define|#
directive|define
name|STT_SECTION
value|3
end_define

begin_comment
comment|/* Symbol associated with a section */
end_comment

begin_define
define|#
directive|define
name|STT_FILE
value|4
end_define

begin_comment
comment|/* Symbol gives a file name */
end_comment

begin_define
define|#
directive|define
name|STT_LOPROC
value|13
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_define
define|#
directive|define
name|STT_HIPROC
value|15
end_define

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_comment
comment|/* Special section indices, which may show up in st_shndx fields, among    other places. */
end_comment

begin_define
define|#
directive|define
name|SHN_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined section reference */
end_comment

begin_define
define|#
directive|define
name|SHN_LORESERVE
value|0xFF00
end_define

begin_comment
comment|/* Begin range of reserved indices */
end_comment

begin_define
define|#
directive|define
name|SHN_LOPROC
value|0xFF00
end_define

begin_comment
comment|/* Begin range of appl-specific */
end_comment

begin_define
define|#
directive|define
name|SHN_HIPROC
value|0xFF1F
end_define

begin_comment
comment|/* End range of appl-specific */
end_comment

begin_define
define|#
directive|define
name|SHN_ABS
value|0xFFF1
end_define

begin_comment
comment|/* Associated symbol is absolute */
end_comment

begin_define
define|#
directive|define
name|SHN_COMMON
value|0xFFF2
end_define

begin_comment
comment|/* Associated symbol is in common */
end_comment

begin_define
define|#
directive|define
name|SHN_HIRESERVE
value|0xFFFF
end_define

begin_comment
comment|/* End range of reserved indices */
end_comment

begin_comment
comment|/* relocation info handling macros */
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
value|((i)& 0xff)
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
value|(((s)<< 8) + ((t)& 0xff))
end_define

begin_define
define|#
directive|define
name|ELF64_R_SYM
parameter_list|(
name|i
parameter_list|)
value|((i)>> 32)
end_define

begin_define
define|#
directive|define
name|ELF64_R_TYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xffffffff)
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
value|(((bfd_vma) (s)<< 32) + (bfd_vma) (t))
end_define

begin_comment
comment|/* Dynamic section tags */
end_comment

begin_define
define|#
directive|define
name|DT_NULL
value|0
end_define

begin_define
define|#
directive|define
name|DT_NEEDED
value|1
end_define

begin_define
define|#
directive|define
name|DT_PLTRELSZ
value|2
end_define

begin_define
define|#
directive|define
name|DT_PLTGOT
value|3
end_define

begin_define
define|#
directive|define
name|DT_HASH
value|4
end_define

begin_define
define|#
directive|define
name|DT_STRTAB
value|5
end_define

begin_define
define|#
directive|define
name|DT_SYMTAB
value|6
end_define

begin_define
define|#
directive|define
name|DT_RELA
value|7
end_define

begin_define
define|#
directive|define
name|DT_RELASZ
value|8
end_define

begin_define
define|#
directive|define
name|DT_RELAENT
value|9
end_define

begin_define
define|#
directive|define
name|DT_STRSZ
value|10
end_define

begin_define
define|#
directive|define
name|DT_SYMENT
value|11
end_define

begin_define
define|#
directive|define
name|DT_INIT
value|12
end_define

begin_define
define|#
directive|define
name|DT_FINI
value|13
end_define

begin_define
define|#
directive|define
name|DT_SONAME
value|14
end_define

begin_define
define|#
directive|define
name|DT_RPATH
value|15
end_define

begin_define
define|#
directive|define
name|DT_SYMBOLIC
value|16
end_define

begin_define
define|#
directive|define
name|DT_REL
value|17
end_define

begin_define
define|#
directive|define
name|DT_RELSZ
value|18
end_define

begin_define
define|#
directive|define
name|DT_RELENT
value|19
end_define

begin_define
define|#
directive|define
name|DT_PLTREL
value|20
end_define

begin_define
define|#
directive|define
name|DT_DEBUG
value|21
end_define

begin_define
define|#
directive|define
name|DT_TEXTREL
value|22
end_define

begin_define
define|#
directive|define
name|DT_JMPREL
value|23
end_define

begin_comment
comment|/* The next four dynamic tags are used on Solaris.  We support them    everywhere.  */
end_comment

begin_define
define|#
directive|define
name|DT_VERDEF
value|0x6ffffffc
end_define

begin_define
define|#
directive|define
name|DT_VERDEFNUM
value|0x6ffffffd
end_define

begin_define
define|#
directive|define
name|DT_VERNEED
value|0x6ffffffe
end_define

begin_define
define|#
directive|define
name|DT_VERNEEDNUM
value|0x6fffffff
end_define

begin_comment
comment|/* This tag is a GNU extension to the Solaris version scheme.  */
end_comment

begin_define
define|#
directive|define
name|DT_VERSYM
value|0x6ffffff0
end_define

begin_define
define|#
directive|define
name|DT_LOPROC
value|0x70000000
end_define

begin_define
define|#
directive|define
name|DT_HIPROC
value|0x7fffffff
end_define

begin_comment
comment|/* These section tags are used on Solaris.  We support them    everywhere, and hope they do not conflict.  */
end_comment

begin_define
define|#
directive|define
name|DT_AUXILIARY
value|0x7ffffffd
end_define

begin_define
define|#
directive|define
name|DT_FILTER
value|0x7fffffff
end_define

begin_comment
comment|/* These constants are used for the version number of a Elf32_Verdef    structure.  */
end_comment

begin_define
define|#
directive|define
name|VER_DEF_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VER_DEF_CURRENT
value|1
end_define

begin_comment
comment|/* These constants appear in the vd_flags field of a Elf32_Verdef    structure.  */
end_comment

begin_define
define|#
directive|define
name|VER_FLG_BASE
value|0x1
end_define

begin_define
define|#
directive|define
name|VER_FLG_WEAK
value|0x2
end_define

begin_comment
comment|/* These special constants can be found in an Elf32_Versym field.  */
end_comment

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

begin_comment
comment|/* These constants are used for the version number of a Elf32_Verneed    structure.  */
end_comment

begin_define
define|#
directive|define
name|VER_NEED_NONE
value|0
end_define

begin_define
define|#
directive|define
name|VER_NEED_CURRENT
value|1
end_define

begin_comment
comment|/* This flag appears in a Versym structure.  It means that the symbol    is hidden, and is only visible with an explicit version number.    This is a GNU extension.  */
end_comment

begin_define
define|#
directive|define
name|VERSYM_HIDDEN
value|0x8000
end_define

begin_comment
comment|/* This is the mask for the rest of the Versym information.  */
end_comment

begin_define
define|#
directive|define
name|VERSYM_VERSION
value|0x7fff
end_define

begin_comment
comment|/* This is a special token which appears as part of a symbol name.  It    indictes that the rest of the name is actually the name of a    version node, and is not part of the actual name.  This is a GNU    extension.  For example, the symbol name `stat@ver2' is taken to    mean the symbol `stat' in version `ver2'.  */
end_comment

begin_define
define|#
directive|define
name|ELF_VER_CHR
value|'@'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_COMMON_H */
end_comment

end_unit

