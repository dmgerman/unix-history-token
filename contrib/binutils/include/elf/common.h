begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ELF support for BFD.    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000,    2001    Free Software Foundation, Inc.     Written by Fred Fish @ Cygnus Support, from information published    in "UNIX System V Release 4, Programmers Guide: ANSI C and    Programming Support Tools".  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|EI_OSABI
value|7
end_define

begin_comment
comment|/* Operating System/ABI indication */
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
name|ELFOSABI_STANDALONE
value|255
end_define

begin_comment
comment|/* Standalone (embedded) application */
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
comment|/* Start of padding bytes */
end_comment

begin_comment
comment|/* Values for e_type, which identifies the object file type.  */
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
name|ET_LOOS
value|0xFE00
end_define

begin_comment
comment|/* Operating system-specific */
end_comment

begin_define
define|#
directive|define
name|ET_HIOS
value|0xFEFF
end_define

begin_comment
comment|/* Operating system-specific */
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
comment|/* Values for e_machine, which identifies the architecture.  These numbers    are officially assigned by registry@sco.com.  See below for a list of    ad-hoc numbers used during initial development.  */
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
name|EM_486
value|6
end_define

begin_comment
comment|/* Intel 80486 */
end_comment

begin_comment
comment|/* Reserved for future use */
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
name|EM_S370
value|9
end_define

begin_comment
comment|/* IBM System/370 */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_RS3_LE
value|10
end_define

begin_comment
comment|/* MIPS R3000 little-endian (Oct 4 1999 Draft)*/
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
name|EM_VPP550
value|17
end_define

begin_comment
comment|/* Fujitsu VPP500 */
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
name|EM_960
value|19
end_define

begin_comment
comment|/* Intel 80960 */
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
comment|/* 64-bit PowerPC */
end_comment

begin_define
define|#
directive|define
name|EM_V800
value|36
end_define

begin_comment
comment|/* NEC V800 series */
end_comment

begin_define
define|#
directive|define
name|EM_FR20
value|37
end_define

begin_comment
comment|/* Fujitsu FR20 */
end_comment

begin_define
define|#
directive|define
name|EM_RH32
value|38
end_define

begin_comment
comment|/* TRW RH32 */
end_comment

begin_define
define|#
directive|define
name|EM_MCORE
value|39
end_define

begin_comment
comment|/* Motorola M*Core */
end_comment

begin_comment
comment|/* May also be taken by Fujitsu MMA */
end_comment

begin_define
define|#
directive|define
name|EM_RCE
value|39
end_define

begin_comment
comment|/* Old name for MCore */
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
name|EM_OLD_ALPHA
value|41
end_define

begin_comment
comment|/* Digital Alpha */
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
name|EM_TRICORE
value|44
end_define

begin_comment
comment|/* Siemens Tricore embedded processor */
end_comment

begin_define
define|#
directive|define
name|EM_ARC
value|45
end_define

begin_comment
comment|/* ARC Cores */
end_comment

begin_define
define|#
directive|define
name|EM_H8_300
value|46
end_define

begin_comment
comment|/* Hitachi H8/300 */
end_comment

begin_define
define|#
directive|define
name|EM_H8_300H
value|47
end_define

begin_comment
comment|/* Hitachi H8/300H */
end_comment

begin_define
define|#
directive|define
name|EM_H8S
value|48
end_define

begin_comment
comment|/* Hitachi H8S */
end_comment

begin_define
define|#
directive|define
name|EM_H8_500
value|49
end_define

begin_comment
comment|/* Hitachi H8/500 */
end_comment

begin_define
define|#
directive|define
name|EM_IA_64
value|50
end_define

begin_comment
comment|/* Intel IA-64 Processor */
end_comment

begin_define
define|#
directive|define
name|EM_MIPS_X
value|51
end_define

begin_comment
comment|/* Stanford MIPS-X */
end_comment

begin_define
define|#
directive|define
name|EM_COLDFIRE
value|52
end_define

begin_comment
comment|/* Motorola Coldfire */
end_comment

begin_define
define|#
directive|define
name|EM_68HC12
value|53
end_define

begin_comment
comment|/* Motorola M68HC12 */
end_comment

begin_define
define|#
directive|define
name|EM_MMA
value|54
end_define

begin_comment
comment|/* Fujitsu Multimedia Accelerator */
end_comment

begin_define
define|#
directive|define
name|EM_PCP
value|55
end_define

begin_comment
comment|/* Siemens PCP */
end_comment

begin_define
define|#
directive|define
name|EM_NCPU
value|56
end_define

begin_comment
comment|/* Sony nCPU embedded RISC processor */
end_comment

begin_define
define|#
directive|define
name|EM_NDR1
value|57
end_define

begin_comment
comment|/* Denso NDR1 microprocesspr */
end_comment

begin_define
define|#
directive|define
name|EM_STARCORE
value|58
end_define

begin_comment
comment|/* Motorola Star*Core processor */
end_comment

begin_define
define|#
directive|define
name|EM_ME16
value|59
end_define

begin_comment
comment|/* Toyota ME16 processor */
end_comment

begin_define
define|#
directive|define
name|EM_ST100
value|60
end_define

begin_comment
comment|/* STMicroelectronics ST100 processor */
end_comment

begin_define
define|#
directive|define
name|EM_TINYJ
value|61
end_define

begin_comment
comment|/* Advanced Logic Corp. TinyJ embedded processor */
end_comment

begin_define
define|#
directive|define
name|EM_X86_64
value|62
end_define

begin_comment
comment|/* Advanced Micro Devices X86-64 processor */
end_comment

begin_define
define|#
directive|define
name|EM_FX66
value|66
end_define

begin_comment
comment|/* Siemens FX66 microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_ST9PLUS
value|67
end_define

begin_comment
comment|/* STMicroelectronics ST9+ 8/16 bit microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_ST7
value|68
end_define

begin_comment
comment|/* STMicroelectronics ST7 8-bit microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_68HC16
value|69
end_define

begin_comment
comment|/* Motorola MC68HC16 Microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_68HC11
value|70
end_define

begin_comment
comment|/* Motorola MC68HC11 Microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_68HC08
value|71
end_define

begin_comment
comment|/* Motorola MC68HC08 Microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_68HC05
value|72
end_define

begin_comment
comment|/* Motorola MC68HC05 Microcontroller */
end_comment

begin_define
define|#
directive|define
name|EM_SVX
value|73
end_define

begin_comment
comment|/* Silicon Graphics SVx */
end_comment

begin_define
define|#
directive|define
name|EM_ST19
value|74
end_define

begin_comment
comment|/* STMicroelectronics ST19 8-bit cpu */
end_comment

begin_define
define|#
directive|define
name|EM_VAX
value|75
end_define

begin_comment
comment|/* Digital VAX */
end_comment

begin_define
define|#
directive|define
name|EM_CRIS
value|76
end_define

begin_comment
comment|/* Axis Communications 32-bit embedded processor */
end_comment

begin_define
define|#
directive|define
name|EM_JAVELIN
value|77
end_define

begin_comment
comment|/* Infineon Technologies 32-bit embedded cpu */
end_comment

begin_define
define|#
directive|define
name|EM_FIREPATH
value|78
end_define

begin_comment
comment|/* Element 14 64-bit DSP processor */
end_comment

begin_define
define|#
directive|define
name|EM_ZSP
value|79
end_define

begin_comment
comment|/* LSI Logic's 16-bit DSP processor */
end_comment

begin_define
define|#
directive|define
name|EM_MMIX
value|80
end_define

begin_comment
comment|/* Donald Knuth's educational 64-bit processor */
end_comment

begin_define
define|#
directive|define
name|EM_HUANY
value|81
end_define

begin_comment
comment|/* Harvard's machine-independent format */
end_comment

begin_define
define|#
directive|define
name|EM_PRISM
value|82
end_define

begin_comment
comment|/* SiTera Prism */
end_comment

begin_comment
comment|/* If it is necessary to assign new unofficial EM_* values, please pick large    random numbers (0x8523, 0xa7f2, etc.) to minimize the chances of collision    with official or non-GNU unofficial values.     NOTE: Do not just increment the most recent number by one.    Somebody else somewhere will do exactly the same thing, and you    will have a collision.  Instead, pick a random number.     Normally, each entity or maintainer responsible for a machine with an    unofficial e_machine number should eventually ask registry@sco.com for    an officially blessed number to be added to the list above.  */
end_comment

begin_define
define|#
directive|define
name|EM_PJ
value|99
end_define

begin_comment
comment|/* picoJava */
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
comment|/* Old version of Sparc v9, from before the ABI; this should be    removed shortly.  */
end_comment

begin_define
define|#
directive|define
name|EM_OLD_SPARCV9
value|11
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
comment|/* Cygnus ARC ELF backend.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_ARC
value|0x9040
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
comment|/* D30V backend magic number.  Written in the absence of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_D30V
value|0x7676
end_define

begin_comment
comment|/* V850 backend magic number.  Written in the absense of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_V850
value|0x9080
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
comment|/* FR30 magic number - no EABI available.  */
end_comment

begin_define
define|#
directive|define
name|EM_CYGNUS_FR30
value|0x3330
end_define

begin_comment
comment|/* AVR magic number    Written in the absense of an ABI.  */
end_comment

begin_define
define|#
directive|define
name|EM_AVR
value|0x1057
end_define

begin_comment
comment|/* See the above comment before you add a new EM_* value here.  */
end_comment

begin_comment
comment|/* Values for e_version.  */
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
comment|/* Values for program header, p_type field.  */
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
name|PT_LOOS
value|0x60000000
end_define

begin_comment
comment|/* OS-specific */
end_comment

begin_define
define|#
directive|define
name|PT_HIOS
value|0x6fffffff
end_define

begin_comment
comment|/* OS-specific */
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
comment|/* Program segment permissions, in program header p_flags field.  */
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

begin_comment
comment|/* #define PF_MASKOS	0x0F000000    */
end_comment

begin_comment
comment|/* OS-specific reserved bits */
end_comment

begin_define
define|#
directive|define
name|PF_MASKOS
value|0x0FF00000
end_define

begin_comment
comment|/* New value, Oct 4, 1999 Draft */
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
comment|/* Values for section header, sh_type field.  */
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

begin_define
define|#
directive|define
name|SHT_INIT_ARRAY
value|14
end_define

begin_comment
comment|/* Array of ptrs to init functions */
end_comment

begin_define
define|#
directive|define
name|SHT_FINI_ARRAY
value|15
end_define

begin_comment
comment|/* Array of ptrs to finish functions */
end_comment

begin_define
define|#
directive|define
name|SHT_PREINIT_ARRAY
value|16
end_define

begin_comment
comment|/* Array of ptrs to pre-init funcs */
end_comment

begin_define
define|#
directive|define
name|SHT_GROUP
value|17
end_define

begin_comment
comment|/* Section contains a section group */
end_comment

begin_define
define|#
directive|define
name|SHT_SYMTAB_SHNDX
value|18
end_define

begin_comment
comment|/* Indicies for SHN_XINDEX entries */
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
name|SHT_HIOS
value|0x6fffffff
end_define

begin_comment
comment|/* Last of OS specific semantics */
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

begin_comment
comment|/* #define SHT_HIUSER	0x8FFFFFFF    */
end_comment

begin_comment
comment|/* Application-specific semantics */
end_comment

begin_define
define|#
directive|define
name|SHT_HIUSER
value|0xFFFFFFFF
end_define

begin_comment
comment|/* New value, defined in Oct 4, 1999 Draft */
end_comment

begin_comment
comment|/* Values for section header, sh_flags field.  */
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
name|SHF_MERGE
value|(1<< 4)
end_define

begin_comment
comment|/* Data in this section can be merged */
end_comment

begin_define
define|#
directive|define
name|SHF_STRINGS
value|(1<< 5)
end_define

begin_comment
comment|/* Contains null terminated character strings */
end_comment

begin_define
define|#
directive|define
name|SHF_INFO_LINK
value|(1<< 6)
end_define

begin_comment
comment|/* sh_info holds section header table index */
end_comment

begin_define
define|#
directive|define
name|SHF_LINK_ORDER
value|(1<< 7)
end_define

begin_comment
comment|/* Preserve section ordering when linking */
end_comment

begin_define
define|#
directive|define
name|SHF_OS_NONCONFORMING
value|(1<< 8)
end_define

begin_comment
comment|/* OS specific processing required */
end_comment

begin_define
define|#
directive|define
name|SHF_GROUP
value|(1<< 9)
end_define

begin_comment
comment|/* Member of a section group */
end_comment

begin_comment
comment|/* #define SHF_MASKOS	0x0F000000    */
end_comment

begin_comment
comment|/* OS-specific semantics */
end_comment

begin_define
define|#
directive|define
name|SHF_MASKOS
value|0x0FF00000
end_define

begin_comment
comment|/* New value, Oct 4, 1999 Draft */
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
comment|/* Values of note segment descriptor types for core files.  */
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

begin_define
define|#
directive|define
name|NT_TASKSTRUCT
value|4
end_define

begin_comment
comment|/* Contains copy of task struct */
end_comment

begin_define
define|#
directive|define
name|NT_PRXFPREG
value|0x46e62b7f
end_define

begin_comment
comment|/* Contains a user_xfpregs_struct; */
end_comment

begin_comment
comment|/*   note name must be "LINUX".  */
end_comment

begin_comment
comment|/* Note segments for core files on dir-style procfs systems.  */
end_comment

begin_define
define|#
directive|define
name|NT_PSTATUS
value|10
end_define

begin_comment
comment|/* Has a struct pstatus */
end_comment

begin_define
define|#
directive|define
name|NT_FPREGS
value|12
end_define

begin_comment
comment|/* Has a struct fpregset */
end_comment

begin_define
define|#
directive|define
name|NT_PSINFO
value|13
end_define

begin_comment
comment|/* Has a struct psinfo */
end_comment

begin_define
define|#
directive|define
name|NT_LWPSTATUS
value|16
end_define

begin_comment
comment|/* Has a struct lwpstatus_t */
end_comment

begin_define
define|#
directive|define
name|NT_LWPSINFO
value|17
end_define

begin_comment
comment|/* Has a struct lwpsinfo_t */
end_comment

begin_define
define|#
directive|define
name|NT_WIN32PSTATUS
value|18
end_define

begin_comment
comment|/* Has a struct win32_pstatus */
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
comment|/* These three macros disassemble and assemble a symbol table st_info field,    which contains the symbol binding and symbol type.  The STB_ and STT_    defines identify the binding and type.  */
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

begin_comment
comment|/* The 64bit and 32bit versions of these macros are identical, but    the ELF spec defines them, so here they are.  */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_BIND
value|ELF_ST_BIND
end_define

begin_define
define|#
directive|define
name|ELF32_ST_TYPE
value|ELF_ST_TYPE
end_define

begin_define
define|#
directive|define
name|ELF32_ST_INFO
value|ELF_ST_INFO
end_define

begin_define
define|#
directive|define
name|ELF64_ST_BIND
value|ELF_ST_BIND
end_define

begin_define
define|#
directive|define
name|ELF64_ST_TYPE
value|ELF_ST_TYPE
end_define

begin_define
define|#
directive|define
name|ELF64_ST_INFO
value|ELF_ST_INFO
end_define

begin_comment
comment|/* This macro disassembles and assembles a symbol's visibility into    the st_other field.  The STV_ defines specificy the actual visibility.  */
end_comment

begin_define
define|#
directive|define
name|ELF_ST_VISIBILITY
parameter_list|(
name|v
parameter_list|)
value|((v)& 0x3)
end_define

begin_comment
comment|/* The remaining bits in the st_other field are not currently used.    They should be set to zero.  */
end_comment

begin_define
define|#
directive|define
name|ELF32_ST_VISIBILITY
value|ELF_ST_VISIBILITY
end_define

begin_define
define|#
directive|define
name|ELF64_ST_VISIBILITY
value|ELF_ST_VISIBILITY
end_define

begin_define
define|#
directive|define
name|STN_UNDEF
value|0
end_define

begin_comment
comment|/* Undefined symbol index */
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
name|STB_LOOS
value|10
end_define

begin_comment
comment|/* OS-specific semantics */
end_comment

begin_define
define|#
directive|define
name|STB_HIOS
value|12
end_define

begin_comment
comment|/* OS-specific semantics */
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
name|STT_COMMON
value|5
end_define

begin_comment
comment|/* An uninitialised common block */
end_comment

begin_define
define|#
directive|define
name|STT_LOOS
value|10
end_define

begin_comment
comment|/* OS-specific semantics */
end_comment

begin_define
define|#
directive|define
name|STT_HIOS
value|12
end_define

begin_comment
comment|/* OS-specific semantics */
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
comment|/* Special section indices, which may show up in st_shndx fields, among    other places.  */
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
name|SHN_LOOS
value|0xFF20
end_define

begin_comment
comment|/* OS specific semantics, lo */
end_comment

begin_define
define|#
directive|define
name|SHN_HIOS
value|0xFF3F
end_define

begin_comment
comment|/* OS specific semantics, hi */
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
name|SHN_XINDEX
value|0xFFFF
end_define

begin_comment
comment|/* Section index it held elsewhere */
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
comment|/* The following constants control how a symbol may be accessed once it has    become part of an executable or shared library.  */
end_comment

begin_define
define|#
directive|define
name|STV_DEFAULT
value|0
end_define

begin_comment
comment|/* Visibility is specified by binding type */
end_comment

begin_define
define|#
directive|define
name|STV_INTERNAL
value|1
end_define

begin_comment
comment|/* OS specific version of STV_HIDDEN */
end_comment

begin_define
define|#
directive|define
name|STV_HIDDEN
value|2
end_define

begin_comment
comment|/* Can only be seen inside currect component */
end_comment

begin_define
define|#
directive|define
name|STV_PROTECTED
value|3
end_define

begin_comment
comment|/* Treat as STB_LOCAL inside current component */
end_comment

begin_comment
comment|/* Relocation info handling macros.  */
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
comment|/* Dynamic section tags.  */
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

begin_define
define|#
directive|define
name|DT_BIND_NOW
value|24
end_define

begin_define
define|#
directive|define
name|DT_INIT_ARRAY
value|25
end_define

begin_define
define|#
directive|define
name|DT_FINI_ARRAY
value|26
end_define

begin_define
define|#
directive|define
name|DT_INIT_ARRAYSZ
value|27
end_define

begin_define
define|#
directive|define
name|DT_FINI_ARRAYSZ
value|28
end_define

begin_define
define|#
directive|define
name|DT_RUNPATH
value|29
end_define

begin_define
define|#
directive|define
name|DT_FLAGS
value|30
end_define

begin_define
define|#
directive|define
name|DT_ENCODING
value|32
end_define

begin_define
define|#
directive|define
name|DT_PREINIT_ARRAY
value|32
end_define

begin_define
define|#
directive|define
name|DT_PREINIT_ARRAYSZ
value|33
end_define

begin_comment
comment|/* Note, the Oct 4, 1999 draft of the ELF ABI changed the values    for DT_LOOS and DT_HIOS.  Some implementations however, use    values outside of the new range (see below).  */
end_comment

begin_define
define|#
directive|define
name|OLD_DT_LOOS
value|0x60000000
end_define

begin_define
define|#
directive|define
name|DT_LOOS
value|0x6000000d
end_define

begin_define
define|#
directive|define
name|DT_HIOS
value|0x6fff0000
end_define

begin_define
define|#
directive|define
name|OLD_DT_HIOS
value|0x6fffffff
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
comment|/* The next four dynamic tags are used on Solaris.  We support them    everywhere.  Note these values lie outside of the (new) range for    OS specific values.  This is a deliberate special case and we    maintain it for backwards compatability.  */
end_comment

begin_define
define|#
directive|define
name|DT_VALRNGLO
value|0x6ffffd00
end_define

begin_define
define|#
directive|define
name|DT_CHECKSUM
value|0x6ffffdf8
end_define

begin_define
define|#
directive|define
name|DT_PLTPADSZ
value|0x6ffffdf9
end_define

begin_define
define|#
directive|define
name|DT_MOVEENT
value|0x6ffffdfa
end_define

begin_define
define|#
directive|define
name|DT_MOVESZ
value|0x6ffffdfb
end_define

begin_define
define|#
directive|define
name|DT_FEATURE
value|0x6ffffdfc
end_define

begin_define
define|#
directive|define
name|DT_POSFLAG_1
value|0x6ffffdfd
end_define

begin_define
define|#
directive|define
name|DT_SYMINSZ
value|0x6ffffdfe
end_define

begin_define
define|#
directive|define
name|DT_SYMINENT
value|0x6ffffdff
end_define

begin_define
define|#
directive|define
name|DT_VALRNGHI
value|0x6ffffdff
end_define

begin_define
define|#
directive|define
name|DT_ADDRRNGLO
value|0x6ffffe00
end_define

begin_define
define|#
directive|define
name|DT_CONFIG
value|0x6ffffefa
end_define

begin_define
define|#
directive|define
name|DT_DEPAUDIT
value|0x6ffffefb
end_define

begin_define
define|#
directive|define
name|DT_AUDIT
value|0x6ffffefc
end_define

begin_define
define|#
directive|define
name|DT_PLTPAD
value|0x6ffffefd
end_define

begin_define
define|#
directive|define
name|DT_MOVETAB
value|0x6ffffefe
end_define

begin_define
define|#
directive|define
name|DT_SYMINFO
value|0x6ffffeff
end_define

begin_define
define|#
directive|define
name|DT_ADDRRNGHI
value|0x6ffffeff
end_define

begin_define
define|#
directive|define
name|DT_RELACOUNT
value|0x6ffffff9
end_define

begin_define
define|#
directive|define
name|DT_RELCOUNT
value|0x6ffffffa
end_define

begin_define
define|#
directive|define
name|DT_FLAGS_1
value|0x6ffffffb
end_define

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
name|DT_USED
value|0x7ffffffe
end_define

begin_define
define|#
directive|define
name|DT_FILTER
value|0x7fffffff
end_define

begin_comment
comment|/* Values used in DT_FEATURE .dynamic entry.  */
end_comment

begin_define
define|#
directive|define
name|DTF_1_PARINIT
value|0x00000001
end_define

begin_comment
comment|/* From     http://docs.sun.com:80/ab2/coll.45.13/LLM/@Ab2PageView/21165?Ab2Lang=C&Ab2Enc=iso-8859-1     DTF_1_CONFEXP is the same as DTF_1_PARINIT. It is a typo. The value    defined here is the same as the one in<sys/link.h> on Solaris 8.  */
end_comment

begin_define
define|#
directive|define
name|DTF_1_CONFEXP
value|0x00000002
end_define

begin_comment
comment|/* Flag values used in the DT_POSFLAG_1 .dynamic entry.  */
end_comment

begin_define
define|#
directive|define
name|DF_P1_LAZYLOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DF_P1_GROUPPERM
value|0x00000002
end_define

begin_comment
comment|/* Flag value in in the DT_FLAGS_1 .dynamic entry.  */
end_comment

begin_define
define|#
directive|define
name|DF_1_NOW
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DF_1_GLOBAL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DF_1_GROUP
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DF_1_NODELETE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DF_1_LOADFLTR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DF_1_INITFIRST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DF_1_NOOPEN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DF_1_ORIGIN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DF_1_DIRECT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DF_1_TRANS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DF_1_INTERPOSE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DF_1_NODEFLIB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DF_1_NODUMP
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DF_1_CONLFAT
value|0x00002000
end_define

begin_comment
comment|/* Flag values for the DT_FLAGS entry.  */
end_comment

begin_define
define|#
directive|define
name|DF_ORIGIN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DF_SYMBOLIC
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DF_TEXTREL
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|DF_BIND_NOW
value|(1<< 3)
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

begin_comment
comment|/* Possible values for si_boundto.  */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_BT_SELF
value|0xffff
end_define

begin_comment
comment|/* Symbol bound to self */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_BT_PARENT
value|0xfffe
end_define

begin_comment
comment|/* Symbol bound to parent */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_BT_LOWRESERVE
value|0xff00
end_define

begin_comment
comment|/* Beginning of reserved entries */
end_comment

begin_comment
comment|/* Possible bitmasks for si_flags.  */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_FLG_DIRECT
value|0x0001
end_define

begin_comment
comment|/* Direct bound symbol */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_FLG_PASSTHRU
value|0x0002
end_define

begin_comment
comment|/* Pass-thru symbol for translator */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_FLG_COPY
value|0x0004
end_define

begin_comment
comment|/* Symbol is a copy-reloc */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_FLG_LAZYLOAD
value|0x0008
end_define

begin_comment
comment|/* Symbol bound to object to be lazy loaded */
end_comment

begin_comment
comment|/* Syminfo version values.  */
end_comment

begin_define
define|#
directive|define
name|SYMINFO_NONE
value|0
end_define

begin_define
define|#
directive|define
name|SYMINFO_CURRENT
value|1
end_define

begin_define
define|#
directive|define
name|SYMINFO_NUM
value|2
end_define

begin_comment
comment|/* Section Group Flags.  */
end_comment

begin_define
define|#
directive|define
name|GRP_COMDAT
value|0x1
end_define

begin_comment
comment|/* A COMDAT group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_COMMON_H */
end_comment

end_unit

