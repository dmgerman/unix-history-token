begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MIPS ELF support for BFD.    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.     By Ian Lance Taylor, Cygnus Support,<ian@cygnus.com>, from    information in the System V Application Binary Interface, MIPS    Processor Supplement.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file holds definitions specific to the MIPS ELF ABI.  Note    that most of this is not actually implemented by BFD.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ELF_MIPS_H
end_ifndef

begin_define
define|#
directive|define
name|_ELF_MIPS_H
end_define

begin_include
include|#
directive|include
file|"elf/reloc-macros.h"
end_include

begin_comment
comment|/* Relocation types.  */
end_comment

begin_macro
name|START_RELOC_NUMBERS
argument_list|(
argument|elf_mips_reloc_type
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_NONE
argument_list|,
literal|0
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_16
argument_list|,
literal|1
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_32
argument_list|,
literal|2
argument_list|)
end_macro

begin_comment
comment|/* In Elf 64: alias R_MIPS_ADD */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_REL32
argument_list|,
literal|3
argument_list|)
end_macro

begin_comment
comment|/* In Elf 64: alias R_MIPS_REL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_26
argument_list|,
literal|4
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_HI16
argument_list|,
literal|5
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_LO16
argument_list|,
literal|6
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GPREL16
argument_list|,
literal|7
argument_list|)
end_macro

begin_comment
comment|/* In Elf 64: alias R_MIPS_GPREL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_LITERAL
argument_list|,
literal|8
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT16
argument_list|,
literal|9
argument_list|)
end_macro

begin_comment
comment|/* In Elf 64: alias R_MIPS_GOT */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_PC16
argument_list|,
literal|10
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_CALL16
argument_list|,
literal|11
argument_list|)
end_macro

begin_comment
comment|/* In Elf 64: alias R_MIPS_CALL */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GPREL32
argument_list|,
literal|12
argument_list|)
end_macro

begin_comment
comment|/* The remaining relocs are defined on Irix, although they are not      in the MIPS ELF ABI.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_UNUSED1
argument_list|,
literal|13
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_UNUSED2
argument_list|,
literal|14
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_UNUSED3
argument_list|,
literal|15
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_SHIFT5
argument_list|,
literal|16
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_SHIFT6
argument_list|,
literal|17
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_64
argument_list|,
literal|18
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT_DISP
argument_list|,
literal|19
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT_PAGE
argument_list|,
literal|20
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT_OFST
argument_list|,
literal|21
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT_HI16
argument_list|,
literal|22
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GOT_LO16
argument_list|,
literal|23
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_SUB
argument_list|,
literal|24
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_INSERT_A
argument_list|,
literal|25
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_INSERT_B
argument_list|,
literal|26
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_DELETE
argument_list|,
literal|27
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_HIGHER
argument_list|,
literal|28
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_HIGHEST
argument_list|,
literal|29
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_CALL_HI16
argument_list|,
literal|30
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_CALL_LO16
argument_list|,
literal|31
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_SCN_DISP
argument_list|,
literal|32
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_REL16
argument_list|,
literal|33
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_ADD_IMMEDIATE
argument_list|,
literal|34
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_PJUMP
argument_list|,
literal|35
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_RELGOT
argument_list|,
literal|36
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_JALR
argument_list|,
literal|37
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_max
argument_list|,
literal|38
argument_list|)
end_macro

begin_comment
comment|/* These relocs are used for the mips16.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS16_26
argument_list|,
literal|100
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS16_GPREL
argument_list|,
literal|101
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to handle embedded-pic.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_PC32
argument_list|,
literal|248
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_PC64
argument_list|,
literal|249
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GNU_REL16_S2
argument_list|,
literal|250
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GNU_REL_LO16
argument_list|,
literal|251
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GNU_REL_HI16
argument_list|,
literal|252
argument_list|)
end_macro

begin_comment
comment|/* These are GNU extensions to enable C++ vtable garbage collection.  */
end_comment

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GNU_VTINHERIT
argument_list|,
literal|253
argument_list|)
end_macro

begin_macro
name|RELOC_NUMBER
argument_list|(
argument|R_MIPS_GNU_VTENTRY
argument_list|,
literal|254
argument_list|)
end_macro

begin_macro
name|END_RELOC_NUMBERS
argument_list|(
argument|R_MIPS_maxext
argument_list|)
end_macro

begin_comment
comment|/* Processor specific flags for the ELF header e_flags field.  */
end_comment

begin_comment
comment|/* At least one .noreorder directive appears in the source.  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_NOREORDER
value|0x00000001
end_define

begin_comment
comment|/* File contains position independent code.  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_PIC
value|0x00000002
end_define

begin_comment
comment|/* Code in file uses the standard calling sequence for calling    position independent code.  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_CPIC
value|0x00000004
end_define

begin_comment
comment|/* Code in file uses UCODE (obsolete) */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_UCODE
value|0x00000010
end_define

begin_comment
comment|/* Code in file uses new ABI (-n32 on Irix 6).  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ABI2
value|0x00000020
end_define

begin_comment
comment|/* Process the .MIPS.options section first by ld */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_OPTIONS_FIRST
value|0x00000080
end_define

begin_comment
comment|/* Architectural Extensions used by this file */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_ASE
value|0x0f000000
end_define

begin_comment
comment|/* Use MDMX multimedia extensions */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_ASE_MDMX
value|0x08000000
end_define

begin_comment
comment|/* Use MIPS-16 ISA extensions */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH_ASE_M16
value|0x04000000
end_define

begin_comment
comment|/* Indicates code compiled for a 64-bit machine in 32-bit mode.    (regs are 32-bits wide.) */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_32BITMODE
value|0x00000100
end_define

begin_comment
comment|/* Four bit MIPS architecture field.  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ARCH
value|0xf0000000
end_define

begin_comment
comment|/* -mips1 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_1
value|0x00000000
end_define

begin_comment
comment|/* -mips2 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_2
value|0x10000000
end_define

begin_comment
comment|/* -mips3 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_3
value|0x20000000
end_define

begin_comment
comment|/* -mips4 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_4
value|0x30000000
end_define

begin_comment
comment|/* -mips5 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_5
value|0x40000000
end_define

begin_comment
comment|/* -mips32 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_32
value|0x50000000
end_define

begin_comment
comment|/* -mips64 code.  */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ARCH_64
value|0x60000000
end_define

begin_comment
comment|/* The ABI of the file.  Also see EF_MIPS_ABI2 above. */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ABI
value|0x0000F000
end_define

begin_comment
comment|/* The original o32 abi. */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ABI_O32
value|0x00001000
end_define

begin_comment
comment|/* O32 extended to work on 64 bit architectures */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ABI_O64
value|0x00002000
end_define

begin_comment
comment|/* EABI in 32 bit mode */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ABI_EABI32
value|0x00003000
end_define

begin_comment
comment|/* EABI in 64 bit mode */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_ABI_EABI64
value|0x00004000
end_define

begin_comment
comment|/* Machine variant if we know it.  This field was invented at Cygnus,    but it is hoped that other vendors will adopt it.  If some standard    is developed, this code should be changed to follow it. */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_MACH
value|0x00FF0000
end_define

begin_comment
comment|/* Cygnus is choosing values between 80 and 9F;    00 - 7F should be left for a future standard;    the rest are open. */
end_comment

begin_define
define|#
directive|define
name|E_MIPS_MACH_3900
value|0x00810000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_4010
value|0x00820000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_4100
value|0x00830000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_4650
value|0x00850000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_4111
value|0x00880000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_MIPS32_4K
value|0x00890000
end_define

begin_define
define|#
directive|define
name|E_MIPS_MACH_SB1
value|0x008a0000
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific section indices.  These sections do not actually    exist.  Symbols with a st_shndx field corresponding to one of these    values have a special meaning.  */
end_comment

begin_comment
comment|/* Defined and allocated common symbol.  Value is virtual address.  If    relocated, alignment must be preserved.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_ACOMMON
value|0xff00
end_define

begin_comment
comment|/* Defined and allocated text symbol.  Value is virtual address.    Occur in the dynamic symbol table of Alpha OSF/1 and Irix 5 executables.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_TEXT
value|0xff01
end_define

begin_comment
comment|/* Defined and allocated data symbol.  Value is virtual address.    Occur in the dynamic symbol table of Alpha OSF/1 and Irix 5 executables.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_DATA
value|0xff02
end_define

begin_comment
comment|/* Small common symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_SCOMMON
value|0xff03
end_define

begin_comment
comment|/* Small undefined symbol.  */
end_comment

begin_define
define|#
directive|define
name|SHN_MIPS_SUNDEFINED
value|0xff04
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific section types.  */
end_comment

begin_comment
comment|/* Section contains the set of dynamic shared objects used when    statically linking.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_LIBLIST
value|0x70000000
end_define

begin_comment
comment|/* I'm not sure what this is, but it's used on Irix 5.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_MSYM
value|0x70000001
end_define

begin_comment
comment|/* Section contains list of symbols whose definitions conflict with    symbols defined in shared objects.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_CONFLICT
value|0x70000002
end_define

begin_comment
comment|/* Section contains the global pointer table.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_GPTAB
value|0x70000003
end_define

begin_comment
comment|/* Section contains microcode information.  The exact format is    unspecified.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_UCODE
value|0x70000004
end_define

begin_comment
comment|/* Section contains some sort of debugging information.  The exact    format is unspecified.  It's probably ECOFF symbols.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DEBUG
value|0x70000005
end_define

begin_comment
comment|/* Section contains register usage information.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_REGINFO
value|0x70000006
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_PACKAGE
value|0x70000007
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_PACKSYM
value|0x70000008
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_RELD
value|0x70000009
end_define

begin_comment
comment|/* Section contains interface information.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_IFACE
value|0x7000000b
end_define

begin_comment
comment|/* Section contains description of contents of another section.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_CONTENT
value|0x7000000c
end_define

begin_comment
comment|/* Section contains miscellaneous options.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_OPTIONS
value|0x7000000d
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_SHDR
value|0x70000010
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_FDESC
value|0x70000011
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_EXTSYM
value|0x70000012
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DENSE
value|0x70000013
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_PDESC
value|0x70000014
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_LOCSYM
value|0x70000015
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_AUXSYM
value|0x70000016
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_OPTSYM
value|0x70000017
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_LOCSTR
value|0x70000018
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_LINE
value|0x70000019
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_RFDESC
value|0x7000001a
end_define

begin_comment
comment|/* Delta C++: symbol table */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DELTASYM
value|0x7000001b
end_define

begin_comment
comment|/* Delta C++: instance table */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DELTAINST
value|0x7000001c
end_define

begin_comment
comment|/* Delta C++: class table */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DELTACLASS
value|0x7000001d
end_define

begin_comment
comment|/* DWARF debugging section.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DWARF
value|0x7000001e
end_define

begin_comment
comment|/* Delta C++: declarations */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DELTADECL
value|0x7000001f
end_define

begin_comment
comment|/* List of libraries the binary depends on.  Includes a time stamp, version    number.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_SYMBOL_LIB
value|0x70000020
end_define

begin_comment
comment|/* Events section.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_EVENTS
value|0x70000021
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_TRANSLATE
value|0x70000022
end_define

begin_comment
comment|/* Special pixie sections */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_PIXIE
value|0x70000023
end_define

begin_comment
comment|/* Address translation table (for debug info) */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_XLATE
value|0x70000024
end_define

begin_comment
comment|/* SGI internal address translation table (for debug info) */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_XLATE_DEBUG
value|0x70000025
end_define

begin_comment
comment|/* Intermediate code */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_WHIRL
value|0x70000026
end_define

begin_comment
comment|/* C++ exception handling region info */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_EH_REGION
value|0x70000027
end_define

begin_comment
comment|/* Obsolete address translation table (for debug info) */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_XLATE_OLD
value|0x70000028
end_define

begin_comment
comment|/* Runtime procedure descriptor table exception information (ucode) ??? */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_PDR_EXCEPTION
value|0x70000029
end_define

begin_comment
comment|/* A section of type SHT_MIPS_LIBLIST contains an array of the    following structure.  The sh_link field is the section index of the    string table.  The sh_info field is the number of entries in the    section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* String table index for name of shared object.  */
name|unsigned
name|long
name|l_name
decl_stmt|;
comment|/* Time stamp.  */
name|unsigned
name|long
name|l_time_stamp
decl_stmt|;
comment|/* Checksum of symbol names and common sizes.  */
name|unsigned
name|long
name|l_checksum
decl_stmt|;
comment|/* String table index for version.  */
name|unsigned
name|long
name|l_version
decl_stmt|;
comment|/* Flags.  */
name|unsigned
name|long
name|l_flags
decl_stmt|;
block|}
name|Elf32_Lib
typedef|;
end_typedef

begin_comment
comment|/* The external version of Elf32_Lib.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|l_name
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|l_time_stamp
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|l_checksum
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|l_version
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|l_flags
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf32_External_Lib
typedef|;
end_typedef

begin_comment
comment|/* The l_flags field of an Elf32_Lib structure may contain the    following flags.  */
end_comment

begin_comment
comment|/* Require an exact match at runtime.  */
end_comment

begin_define
define|#
directive|define
name|LL_EXACT_MATCH
value|0x00000001
end_define

begin_comment
comment|/* Ignore version incompatibilities at runtime.  */
end_comment

begin_define
define|#
directive|define
name|LL_IGNORE_INT_VER
value|0x00000002
end_define

begin_comment
comment|/* Require matching minor version number.  */
end_comment

begin_define
define|#
directive|define
name|LL_REQUIRE_MINOR
value|0x00000004
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|LL_EXPORTS
value|0x00000008
end_define

begin_comment
comment|/* Delay loading of this library until really needed.  */
end_comment

begin_define
define|#
directive|define
name|LL_DELAY_LOAD
value|0x00000010
end_define

begin_comment
comment|/* ??? Delta C++ stuff ??? */
end_comment

begin_define
define|#
directive|define
name|LL_DELTA
value|0x00000020
end_define

begin_comment
comment|/* A section of type SHT_MIPS_CONFLICT is an array of indices into the    .dynsym section.  Each element has the following type.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf32_Conflict
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Elf32_External_Conflict
index|[
literal|4
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf64_Conflict
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|Elf64_External_Conflict
index|[
literal|8
index|]
typedef|;
end_typedef

begin_comment
comment|/* A section of type SHT_MIPS_GPTAB contains information about how    much GP space would be required for different -G arguments.  This    information is only used so that the linker can provide informative    suggestions as to the best -G value to use.  The sh_info field is    the index of the section for which this information applies.  The    contents of the section are an array of the following union.  The    first element uses the gt_header field.  The remaining elements use    the gt_entry field.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
comment|/* -G value actually used for this object file.  */
name|unsigned
name|long
name|gt_current_g_value
decl_stmt|;
comment|/* Unused.  */
name|unsigned
name|long
name|gt_unused
decl_stmt|;
block|}
name|gt_header
struct|;
struct|struct
block|{
comment|/* If this -G argument has been used...  */
name|unsigned
name|long
name|gt_g_value
decl_stmt|;
comment|/* ...this many GP section bytes would be required.  */
name|unsigned
name|long
name|gt_bytes
decl_stmt|;
block|}
name|gt_entry
struct|;
block|}
name|Elf32_gptab
typedef|;
end_typedef

begin_comment
comment|/* The external version of Elf32_gptab.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|unsigned
name|char
name|gt_current_g_value
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|gt_unused
index|[
literal|4
index|]
decl_stmt|;
block|}
name|gt_header
struct|;
struct|struct
block|{
name|unsigned
name|char
name|gt_g_value
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|gt_bytes
index|[
literal|4
index|]
decl_stmt|;
block|}
name|gt_entry
struct|;
block|}
name|Elf32_External_gptab
typedef|;
end_typedef

begin_comment
comment|/* A section of type SHT_MIPS_REGINFO contains the following    structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Mask of general purpose registers used.  */
name|unsigned
name|long
name|ri_gprmask
decl_stmt|;
comment|/* Mask of co-processor registers used.  */
name|unsigned
name|long
name|ri_cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* GP register value for this object file.  */
name|long
name|ri_gp_value
decl_stmt|;
block|}
name|Elf32_RegInfo
typedef|;
end_typedef

begin_comment
comment|/* The external version of the Elf_RegInfo structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|ri_gprmask
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|ri_cprmask
index|[
literal|4
index|]
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|ri_gp_value
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf32_External_RegInfo
typedef|;
end_typedef

begin_comment
comment|/* MIPS ELF .reginfo swapping routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf32_swap_reginfo_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf32_External_RegInfo
operator|*
operator|,
name|Elf32_RegInfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf32_swap_reginfo_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf32_RegInfo
operator|*
operator|,
name|Elf32_External_RegInfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Processor specific section flags.  */
end_comment

begin_comment
comment|/* This section must be in the global data area.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_GPREL
value|0x10000000
end_define

begin_comment
comment|/* This section should be merged.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_MERGE
value|0x20000000
end_define

begin_comment
comment|/* This section contains address data of size implied by section    element size.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_ADDR
value|0x40000000
end_define

begin_comment
comment|/* This section contains string data.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_STRING
value|0x80000000
end_define

begin_comment
comment|/* This section may not be stripped.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_NOSTRIP
value|0x08000000
end_define

begin_comment
comment|/* This section is local to threads.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_LOCAL
value|0x04000000
end_define

begin_comment
comment|/* Linker should generate implicit weak names for this section.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_NAMES
value|0x02000000
end_define

begin_comment
comment|/* Section contais text/data which may be replicated in other sections.    Linker should retain only one copy.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_NODUPES
value|0x01000000
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific program header types.  */
end_comment

begin_comment
comment|/* Register usage information.  Identifies one .reginfo section.  */
end_comment

begin_define
define|#
directive|define
name|PT_MIPS_REGINFO
value|0x70000000
end_define

begin_comment
comment|/* Runtime procedure table.  */
end_comment

begin_define
define|#
directive|define
name|PT_MIPS_RTPROC
value|0x70000001
end_define

begin_comment
comment|/* .MIPS.options section.  */
end_comment

begin_define
define|#
directive|define
name|PT_MIPS_OPTIONS
value|0x70000002
end_define

begin_escape
end_escape

begin_comment
comment|/* Processor specific dynamic array tags.  */
end_comment

begin_comment
comment|/* 32 bit version number for runtime linker interface.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_VERSION
value|0x70000001
end_define

begin_comment
comment|/* Time stamp.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_TIME_STAMP
value|0x70000002
end_define

begin_comment
comment|/* Checksum of external strings and common sizes.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_ICHECKSUM
value|0x70000003
end_define

begin_comment
comment|/* Index of version string in string table.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_IVERSION
value|0x70000004
end_define

begin_comment
comment|/* 32 bits of flags.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_FLAGS
value|0x70000005
end_define

begin_comment
comment|/* Base address of the segment.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_BASE_ADDRESS
value|0x70000006
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_MSYM
value|0x70000007
end_define

begin_comment
comment|/* Address of .conflict section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICT
value|0x70000008
end_define

begin_comment
comment|/* Address of .liblist section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LIBLIST
value|0x70000009
end_define

begin_comment
comment|/* Number of local global offset table entries.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LOCAL_GOTNO
value|0x7000000a
end_define

begin_comment
comment|/* Number of entries in the .conflict section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_CONFLICTNO
value|0x7000000b
end_define

begin_comment
comment|/* Number of entries in the .liblist section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LIBLISTNO
value|0x70000010
end_define

begin_comment
comment|/* Number of entries in the .dynsym section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_SYMTABNO
value|0x70000011
end_define

begin_comment
comment|/* Index of first external dynamic symbol not referenced locally.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_UNREFEXTNO
value|0x70000012
end_define

begin_comment
comment|/* Index of first dynamic symbol in global offset table.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_GOTSYM
value|0x70000013
end_define

begin_comment
comment|/* Number of page table entries in global offset table.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_HIPAGENO
value|0x70000014
end_define

begin_comment
comment|/* Address of run time loader map, used for debugging.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_MAP
value|0x70000016
end_define

begin_comment
comment|/* Delta C++ class definition.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_CLASS
value|0x70000017
end_define

begin_comment
comment|/* Number of entries in DT_MIPS_DELTA_CLASS.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_CLASS_NO
value|0x70000018
end_define

begin_comment
comment|/* Delta C++ class instances.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_INSTANCE
value|0x70000019
end_define

begin_comment
comment|/* Number of entries in DT_MIPS_DELTA_INSTANCE.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_INSTANCE_NO
value|0x7000001a
end_define

begin_comment
comment|/* Delta relocations.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_RELOC
value|0x7000001b
end_define

begin_comment
comment|/* Number of entries in DT_MIPS_DELTA_RELOC.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_RELOC_NO
value|0x7000001c
end_define

begin_comment
comment|/* Delta symbols that Delta relocations refer to.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_SYM
value|0x7000001d
end_define

begin_comment
comment|/* Number of entries in DT_MIPS_DELTA_SYM.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_SYM_NO
value|0x7000001e
end_define

begin_comment
comment|/* Delta symbols that hold class declarations.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_CLASSSYM
value|0x70000020
end_define

begin_comment
comment|/* Number of entries in DT_MIPS_DELTA_CLASSSYM.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DELTA_CLASSSYM_NO
value|0x70000021
end_define

begin_comment
comment|/* Flags indicating information about C++ flavor.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_CXX_FLAGS
value|0x70000022
end_define

begin_comment
comment|/* Pixie information (???).  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_PIXIE_INIT
value|0x70000023
end_define

begin_comment
comment|/* Address of .MIPS.symlib */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_SYMBOL_LIB
value|0x70000024
end_define

begin_comment
comment|/* The GOT index of the first PTE for a segment */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LOCALPAGE_GOTIDX
value|0x70000025
end_define

begin_comment
comment|/* The GOT index of the first PTE for a local symbol */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_LOCAL_GOTIDX
value|0x70000026
end_define

begin_comment
comment|/* The GOT index of the first PTE for a hidden symbol */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_HIDDEN_GOTIDX
value|0x70000027
end_define

begin_comment
comment|/* The GOT index of the first PTE for a protected symbol */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_PROTECTED_GOTIDX
value|0x70000028
end_define

begin_comment
comment|/* Address of `.MIPS.options'.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_OPTIONS
value|0x70000029
end_define

begin_comment
comment|/* Address of `.interface'.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_INTERFACE
value|0x7000002a
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_DYNSTR_ALIGN
value|0x7000002b
end_define

begin_comment
comment|/* Size of the .interface section.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_INTERFACE_SIZE
value|0x7000002c
end_define

begin_comment
comment|/* Size of rld_text_resolve function stored in the GOT.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_RLD_TEXT_RESOLVE_ADDR
value|0x7000002d
end_define

begin_comment
comment|/* Default suffix of DSO to be added by rld on dlopen() calls.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_PERF_SUFFIX
value|0x7000002e
end_define

begin_comment
comment|/* Size of compact relocation section (O32).  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_COMPACT_SIZE
value|0x7000002f
end_define

begin_comment
comment|/* GP value for auxiliary GOTs.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_GP_VALUE
value|0x70000030
end_define

begin_comment
comment|/* Address of auxiliary .dynamic.  */
end_comment

begin_define
define|#
directive|define
name|DT_MIPS_AUX_DYNAMIC
value|0x70000031
end_define

begin_escape
end_escape

begin_comment
comment|/* Flags which may appear in a DT_MIPS_FLAGS entry.  */
end_comment

begin_comment
comment|/* No flags.  */
end_comment

begin_define
define|#
directive|define
name|RHF_NONE
value|0x00000000
end_define

begin_comment
comment|/* Uses shortcut pointers.  */
end_comment

begin_define
define|#
directive|define
name|RHF_QUICKSTART
value|0x00000001
end_define

begin_comment
comment|/* Hash size is not a power of two.  */
end_comment

begin_define
define|#
directive|define
name|RHF_NOTPOT
value|0x00000002
end_define

begin_comment
comment|/* Ignore LD_LIBRARY_PATH.  */
end_comment

begin_define
define|#
directive|define
name|RHS_NO_LIBRARY_REPLACEMENT
value|0x00000004
end_define

begin_comment
comment|/* DSO address may not be relocated. */
end_comment

begin_define
define|#
directive|define
name|RHF_NO_MOVE
value|0x00000008
end_define

begin_comment
comment|/* SGI specific features. */
end_comment

begin_define
define|#
directive|define
name|RHF_SGI_ONLY
value|0x00000010
end_define

begin_comment
comment|/* Guarantee that .init will finish executing before any non-init    code in DSO is called. */
end_comment

begin_define
define|#
directive|define
name|RHF_GUARANTEE_INIT
value|0x00000020
end_define

begin_comment
comment|/* Contains Delta C++ code. */
end_comment

begin_define
define|#
directive|define
name|RHF_DELTA_C_PLUS_PLUS
value|0x00000040
end_define

begin_comment
comment|/* Guarantee that .init will start executing before any non-init    code in DSO is called. */
end_comment

begin_define
define|#
directive|define
name|RHF_GUARANTEE_START_INIT
value|0x00000080
end_define

begin_comment
comment|/* Generated by pixie. */
end_comment

begin_define
define|#
directive|define
name|RHF_PIXIE
value|0x00000100
end_define

begin_comment
comment|/* Delay-load DSO by default. */
end_comment

begin_define
define|#
directive|define
name|RHF_DEFAULT_DELAY_LOAD
value|0x00000200
end_define

begin_comment
comment|/* Object may be requickstarted */
end_comment

begin_define
define|#
directive|define
name|RHF_REQUICKSTART
value|0x00000400
end_define

begin_comment
comment|/* Object has been requickstarted */
end_comment

begin_define
define|#
directive|define
name|RHF_REQUICKSTARTED
value|0x00000800
end_define

begin_comment
comment|/* Generated by cord. */
end_comment

begin_define
define|#
directive|define
name|RHF_CORD
value|0x00001000
end_define

begin_comment
comment|/* Object contains no unresolved undef symbols. */
end_comment

begin_define
define|#
directive|define
name|RHF_NO_UNRES_UNDEF
value|0x00002000
end_define

begin_comment
comment|/* Symbol table is in a safe order. */
end_comment

begin_define
define|#
directive|define
name|RHF_RLD_ORDER_SAFE
value|0x00004000
end_define

begin_escape
end_escape

begin_comment
comment|/* Special values for the st_other field in the symbol table.  These    are used in an Irix 5 dynamic symbol table.  */
end_comment

begin_define
define|#
directive|define
name|STO_DEFAULT
value|STV_DEFAULT
end_define

begin_define
define|#
directive|define
name|STO_INTERNAL
value|STV_INTERNAL
end_define

begin_define
define|#
directive|define
name|STO_HIDDEN
value|STV_HIDDEN
end_define

begin_define
define|#
directive|define
name|STO_PROTECTED
value|STV_PROTECTED
end_define

begin_comment
comment|/* This value is used for a mips16 .text symbol.  */
end_comment

begin_define
define|#
directive|define
name|STO_MIPS16
value|0xf0
end_define

begin_escape
end_escape

begin_comment
comment|/* The 64-bit MIPS ELF ABI uses an unusual reloc format.  Each    relocation entry specifies up to three actual relocations, all at    the same address.  The first relocation which required a symbol    uses the symbol in the r_sym field.  The second relocation which    requires a symbol uses the symbol in the r_ssym field.  If all    three relocations require a symbol, the third one uses a zero    value.  */
end_comment

begin_comment
comment|/* An entry in a 64 bit SHT_REL section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Address of relocation.  */
name|unsigned
name|char
name|r_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Symbol index.  */
name|unsigned
name|char
name|r_sym
index|[
literal|4
index|]
decl_stmt|;
comment|/* Special symbol.  */
name|unsigned
name|char
name|r_ssym
index|[
literal|1
index|]
decl_stmt|;
comment|/* Third relocation.  */
name|unsigned
name|char
name|r_type3
index|[
literal|1
index|]
decl_stmt|;
comment|/* Second relocation.  */
name|unsigned
name|char
name|r_type2
index|[
literal|1
index|]
decl_stmt|;
comment|/* First relocation.  */
name|unsigned
name|char
name|r_type
index|[
literal|1
index|]
decl_stmt|;
block|}
name|Elf64_Mips_External_Rel
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Address of relocation.  */
name|bfd_vma
name|r_offset
decl_stmt|;
comment|/* Symbol index.  */
name|unsigned
name|long
name|r_sym
decl_stmt|;
comment|/* Special symbol.  */
name|unsigned
name|char
name|r_ssym
decl_stmt|;
comment|/* Third relocation.  */
name|unsigned
name|char
name|r_type3
decl_stmt|;
comment|/* Second relocation.  */
name|unsigned
name|char
name|r_type2
decl_stmt|;
comment|/* First relocation.  */
name|unsigned
name|char
name|r_type
decl_stmt|;
block|}
name|Elf64_Mips_Internal_Rel
typedef|;
end_typedef

begin_comment
comment|/* An entry in a 64 bit SHT_RELA section.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Address of relocation.  */
name|unsigned
name|char
name|r_offset
index|[
literal|8
index|]
decl_stmt|;
comment|/* Symbol index.  */
name|unsigned
name|char
name|r_sym
index|[
literal|4
index|]
decl_stmt|;
comment|/* Special symbol.  */
name|unsigned
name|char
name|r_ssym
index|[
literal|1
index|]
decl_stmt|;
comment|/* Third relocation.  */
name|unsigned
name|char
name|r_type3
index|[
literal|1
index|]
decl_stmt|;
comment|/* Second relocation.  */
name|unsigned
name|char
name|r_type2
index|[
literal|1
index|]
decl_stmt|;
comment|/* First relocation.  */
name|unsigned
name|char
name|r_type
index|[
literal|1
index|]
decl_stmt|;
comment|/* Addend.  */
name|unsigned
name|char
name|r_addend
index|[
literal|8
index|]
decl_stmt|;
block|}
name|Elf64_Mips_External_Rela
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Address of relocation.  */
name|bfd_vma
name|r_offset
decl_stmt|;
comment|/* Symbol index.  */
name|unsigned
name|long
name|r_sym
decl_stmt|;
comment|/* Special symbol.  */
name|unsigned
name|char
name|r_ssym
decl_stmt|;
comment|/* Third relocation.  */
name|unsigned
name|char
name|r_type3
decl_stmt|;
comment|/* Second relocation.  */
name|unsigned
name|char
name|r_type2
decl_stmt|;
comment|/* First relocation.  */
name|unsigned
name|char
name|r_type
decl_stmt|;
comment|/* Addend.  */
name|bfd_signed_vma
name|r_addend
decl_stmt|;
block|}
name|Elf64_Mips_Internal_Rela
typedef|;
end_typedef

begin_comment
comment|/* MIPS ELF 64 relocation info access macros.  */
end_comment

begin_define
define|#
directive|define
name|ELF64_MIPS_R_SSYM
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 24)& 0xff)
end_define

begin_define
define|#
directive|define
name|ELF64_MIPS_R_TYPE3
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|ELF64_MIPS_R_TYPE2
parameter_list|(
name|i
parameter_list|)
value|(((i)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|ELF64_MIPS_R_TYPE
parameter_list|(
name|i
parameter_list|)
value|((i)& 0xff)
end_define

begin_comment
comment|/* Values found in the r_ssym field of a relocation entry.  */
end_comment

begin_comment
comment|/* No relocation.  */
end_comment

begin_define
define|#
directive|define
name|RSS_UNDEF
value|0
end_define

begin_comment
comment|/* Value of GP.  */
end_comment

begin_define
define|#
directive|define
name|RSS_GP
value|1
end_define

begin_comment
comment|/* Value of GP in object being relocated.  */
end_comment

begin_define
define|#
directive|define
name|RSS_GP0
value|2
end_define

begin_comment
comment|/* Address of location being relocated.  */
end_comment

begin_define
define|#
directive|define
name|RSS_LOC
value|3
end_define

begin_escape
end_escape

begin_comment
comment|/* A SHT_MIPS_OPTIONS section contains a series of options, each of    which starts with this header.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Type of option.  */
name|unsigned
name|char
name|kind
index|[
literal|1
index|]
decl_stmt|;
comment|/* Size of option descriptor, including header.  */
name|unsigned
name|char
name|size
index|[
literal|1
index|]
decl_stmt|;
comment|/* Section index of affected section, or 0 for global option.  */
name|unsigned
name|char
name|section
index|[
literal|2
index|]
decl_stmt|;
comment|/* Information specific to this kind of option.  */
name|unsigned
name|char
name|info
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf_External_Options
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Type of option.  */
name|unsigned
name|char
name|kind
decl_stmt|;
comment|/* Size of option descriptor, including header.  */
name|unsigned
name|char
name|size
decl_stmt|;
comment|/* Section index of affected section, or 0 for global option.  */
name|unsigned
name|short
name|section
decl_stmt|;
comment|/* Information specific to this kind of option.  */
name|unsigned
name|long
name|info
decl_stmt|;
block|}
name|Elf_Internal_Options
typedef|;
end_typedef

begin_comment
comment|/* MIPS ELF option header swapping routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf_swap_options_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf_External_Options
operator|*
operator|,
name|Elf_Internal_Options
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf_swap_options_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf_Internal_Options
operator|*
operator|,
name|Elf_External_Options
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values which may appear in the kind field of an Elf_Options    structure.  */
end_comment

begin_comment
comment|/* Undefined.  */
end_comment

begin_define
define|#
directive|define
name|ODK_NULL
value|0
end_define

begin_comment
comment|/* Register usage and GP value.  */
end_comment

begin_define
define|#
directive|define
name|ODK_REGINFO
value|1
end_define

begin_comment
comment|/* Exception processing information.  */
end_comment

begin_define
define|#
directive|define
name|ODK_EXCEPTIONS
value|2
end_define

begin_comment
comment|/* Section padding information.  */
end_comment

begin_define
define|#
directive|define
name|ODK_PAD
value|3
end_define

begin_comment
comment|/* Hardware workarounds performed.  */
end_comment

begin_define
define|#
directive|define
name|ODK_HWPATCH
value|4
end_define

begin_comment
comment|/* Fill value used by the linker.  */
end_comment

begin_define
define|#
directive|define
name|ODK_FILL
value|5
end_define

begin_comment
comment|/* Reserved space for desktop tools.  */
end_comment

begin_define
define|#
directive|define
name|ODK_TAGS
value|6
end_define

begin_comment
comment|/* Hardware workarounds, AND bits when merging.  */
end_comment

begin_define
define|#
directive|define
name|ODK_HWAND
value|7
end_define

begin_comment
comment|/* Hardware workarounds, OR bits when merging.  */
end_comment

begin_define
define|#
directive|define
name|ODK_HWOR
value|8
end_define

begin_comment
comment|/* GP group to use for text/data sections.  */
end_comment

begin_define
define|#
directive|define
name|ODK_GP_GROUP
value|9
end_define

begin_comment
comment|/* ID information.  */
end_comment

begin_define
define|#
directive|define
name|ODK_IDENT
value|10
end_define

begin_comment
comment|/* In the 32 bit ABI, an ODK_REGINFO option is just a Elf32_RegInfo    structure.  In the 64 bit ABI, it is the following structure.  The    info field of the options header is not used.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Mask of general purpose registers used.  */
name|unsigned
name|char
name|ri_gprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* Padding.  */
name|unsigned
name|char
name|ri_pad
index|[
literal|4
index|]
decl_stmt|;
comment|/* Mask of co-processor registers used.  */
name|unsigned
name|char
name|ri_cprmask
index|[
literal|4
index|]
index|[
literal|4
index|]
decl_stmt|;
comment|/* GP register value for this object file.  */
name|unsigned
name|char
name|ri_gp_value
index|[
literal|8
index|]
decl_stmt|;
block|}
name|Elf64_External_RegInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Mask of general purpose registers used.  */
name|unsigned
name|long
name|ri_gprmask
decl_stmt|;
comment|/* Padding.  */
name|unsigned
name|long
name|ri_pad
decl_stmt|;
comment|/* Mask of co-processor registers used.  */
name|unsigned
name|long
name|ri_cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* GP register value for this object file.  */
name|bfd_vma
name|ri_gp_value
decl_stmt|;
block|}
name|Elf64_Internal_RegInfo
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The hash value computed from the name of the corresponding      dynamic symbol.  */
name|unsigned
name|char
name|ms_hash_value
index|[
literal|4
index|]
decl_stmt|;
comment|/* Contains both the dynamic relocation index and the symbol flags      field.  The macros ELF32_MS_REL_INDEX and ELF32_MS_FLAGS are used      to access the individual values.  The dynamic relocation index      identifies the first entry in the .rel.dyn section that      references the dynamic symbol corresponding to this msym entry.      If the index is 0, no dynamic relocations are associated with the      symbol.  The symbol flags field is reserved for future use.  */
name|unsigned
name|char
name|ms_info
index|[
literal|4
index|]
decl_stmt|;
block|}
name|Elf32_External_Msym
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The hash value computed from the name of the corresponding      dynamic symbol.  */
name|unsigned
name|long
name|ms_hash_value
decl_stmt|;
comment|/* Contains both the dynamic relocation index and the symbol flags      field.  The macros ELF32_MS_REL_INDEX and ELF32_MS_FLAGS are used      to access the individual values.  The dynamic relocation index      identifies the first entry in the .rel.dyn section that      references the dynamic symbol corresponding to this msym entry.      If the index is 0, no dynamic relocations are associated with the      symbol.  The symbol flags field is reserved for future use.  */
name|unsigned
name|long
name|ms_info
decl_stmt|;
block|}
name|Elf32_Internal_Msym
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ELF32_MS_REL_INDEX
parameter_list|(
name|i
parameter_list|)
value|((i)>> 8)
end_define

begin_define
define|#
directive|define
name|ELF32_MS_FLAGS
parameter_list|(
name|i
parameter_list|)
value|(i)& 0xff)
end_define

begin_define
define|#
directive|define
name|ELF32_MS_INFO
parameter_list|(
name|r
parameter_list|,
name|f
parameter_list|)
value|(((r)<< 8) + ((f)& 0xff))
end_define

begin_comment
comment|/* MIPS ELF reginfo swapping routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf64_swap_reginfo_in
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_External_RegInfo
operator|*
operator|,
name|Elf64_Internal_RegInfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bfd_mips_elf64_swap_reginfo_out
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|Elf64_Internal_RegInfo
operator|*
operator|,
name|Elf64_External_RegInfo
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Masks for the info work of an ODK_EXCEPTIONS descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_MIN
value|0x1f
end_define

begin_comment
comment|/* FPEs which must be enabled.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_MAX
value|0x1f00
end_define

begin_comment
comment|/* FPEs which may be enabled.  */
end_comment

begin_define
define|#
directive|define
name|OEX_PAGE0
value|0x10000
end_define

begin_comment
comment|/* Page zero must be mapped.  */
end_comment

begin_define
define|#
directive|define
name|OEX_SMM
value|0x20000
end_define

begin_comment
comment|/* Force sequential memory mode.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPDBUG
value|0x40000
end_define

begin_comment
comment|/* Force precise floating-point 				   exceptions (debug mode).  */
end_comment

begin_define
define|#
directive|define
name|OEX_DISMISS
value|0x80000
end_define

begin_comment
comment|/* Dismiss invalid address faults.  */
end_comment

begin_comment
comment|/* Masks of the FP exceptions for OEX_FPU_MIN and OEX_FPU_MAX.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_INVAL
value|0x10
end_define

begin_comment
comment|/* Invalid operation exception.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_DIV0
value|0x08
end_define

begin_comment
comment|/* Division by zero exception.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_OFLO
value|0x04
end_define

begin_comment
comment|/* Overflow exception.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_UFLO
value|0x02
end_define

begin_comment
comment|/* Underflow exception.  */
end_comment

begin_define
define|#
directive|define
name|OEX_FPU_INEX
value|0x01
end_define

begin_comment
comment|/* Inexact exception.  */
end_comment

begin_comment
comment|/* Masks for the info word of an ODK_PAD descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OPAD_PREFIX
value|0x01
end_define

begin_define
define|#
directive|define
name|OPAD_POSTFIX
value|0x02
end_define

begin_define
define|#
directive|define
name|OPAD_SYMBOL
value|0x04
end_define

begin_comment
comment|/* Masks for the info word of an ODK_HWPATCH descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OHW_R4KEOP
value|0x00000001
end_define

begin_comment
comment|/* R4000 end-of-page patch.  */
end_comment

begin_define
define|#
directive|define
name|OHW_R8KPFETCH
value|0x00000002
end_define

begin_comment
comment|/* May need R8000 prefetch patch.  */
end_comment

begin_define
define|#
directive|define
name|OHW_R5KEOP
value|0x00000004
end_define

begin_comment
comment|/* R5000 end-of-page patch.  */
end_comment

begin_define
define|#
directive|define
name|OHW_R5KCVTL
value|0x00000008
end_define

begin_comment
comment|/* R5000 cvt.[ds].l bug 					   (clean == 1).  */
end_comment

begin_define
define|#
directive|define
name|OHW_R10KLDL
value|0x00000010
end_define

begin_comment
comment|/* Needs R10K misaligned 					   load patch. */
end_comment

begin_comment
comment|/* Masks for the info word of an ODK_IDENT/ODK_GP_GROUP descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OGP_GROUP
value|0x0000ffff
end_define

begin_comment
comment|/* GP group number.  */
end_comment

begin_define
define|#
directive|define
name|OGP_SELF
value|0xffff0000
end_define

begin_comment
comment|/* Self-contained GP groups.  */
end_comment

begin_comment
comment|/* Masks for the info word of an ODK_HWAND/ODK_HWOR descriptor.  */
end_comment

begin_define
define|#
directive|define
name|OHWA0_R4KEOP_CHECKED
value|0x00000001
end_define

begin_define
define|#
directive|define
name|OHWA0_R4KEOP_CLEAN
value|0x00000002
end_define

begin_escape
end_escape

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MIPS_H */
end_comment

end_unit

