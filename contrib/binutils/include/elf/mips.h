begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* MIPS ELF support for BFD.    Copyright (C) 1993, 1994, 1995, 1996 Free Software Foundation, Inc.     By Ian Lance Taylor, Cygnus Support,<ian@cygnus.com>, from    information in the System V Application Binary Interface, MIPS    Processor Supplement.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Code in file uses new ABI (-n32 on Irix 6).  */
end_comment

begin_define
define|#
directive|define
name|EF_MIPS_ABI2
value|0x00000020
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
comment|/* DWARF debugging section.  */
end_comment

begin_define
define|#
directive|define
name|SHT_MIPS_DWARF
value|0x7000001e
end_define

begin_comment
comment|/* I'm not sure what this is, but it appears on Irix 6.  */
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
comment|/* A section of type SHT_MIPS_CONFLICT is an array of indices into the    .dynsym section.  Each element has the following type.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|Elf32_Conflict
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
comment|/* This section contains 32 bit addresses.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_ADDR32
value|0x40000000
end_define

begin_comment
comment|/* This section contains 64 bit addresses.  */
end_comment

begin_define
define|#
directive|define
name|SHF_MIPS_ADDR64
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
define|\
value|0x00000004
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
value|0x00
end_define

begin_define
define|#
directive|define
name|STO_INTERNAL
value|0x01
end_define

begin_define
define|#
directive|define
name|STO_HIDDEN
value|0x02
end_define

begin_define
define|#
directive|define
name|STO_PROTECTED
value|0x03
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
comment|/* In the 32 bit ABI, an ODK_REGINFO option is just a Elf32_Reginfo    structure.  In the 64 bit ABI, it is the following structure.  The    info field of the options header is not used.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ELF_MIPS_H */
end_comment

end_unit

