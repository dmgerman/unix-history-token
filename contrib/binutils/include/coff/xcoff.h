begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Internal format of XCOFF object file data structures for BFD.     Copyright 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003    Free Software Foundation, Inc.    Written by Ian Lance Taylor<ian@cygnus.com>, Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INTERNAL_XCOFF_H
end_ifndef

begin_define
define|#
directive|define
name|_INTERNAL_XCOFF_H
end_define

begin_comment
comment|/* Linker */
end_comment

begin_comment
comment|/* Names of "special" sections.  */
end_comment

begin_define
define|#
directive|define
name|_TEXT
value|".text"
end_define

begin_define
define|#
directive|define
name|_DATA
value|".data"
end_define

begin_define
define|#
directive|define
name|_BSS
value|".bss"
end_define

begin_define
define|#
directive|define
name|_PAD
value|".pad"
end_define

begin_define
define|#
directive|define
name|_LOADER
value|".loader"
end_define

begin_define
define|#
directive|define
name|_EXCEPT
value|".except"
end_define

begin_define
define|#
directive|define
name|_TYPCHK
value|".typchk"
end_define

begin_comment
comment|/* XCOFF uses a special .loader section with type STYP_LOADER.  */
end_comment

begin_define
define|#
directive|define
name|STYP_LOADER
value|0x1000
end_define

begin_comment
comment|/* XCOFF uses a special .debug section with type STYP_DEBUG.  */
end_comment

begin_define
define|#
directive|define
name|STYP_DEBUG
value|0x2000
end_define

begin_comment
comment|/* XCOFF handles line number or relocation overflow by creating    another section header with STYP_OVRFLO set.  */
end_comment

begin_define
define|#
directive|define
name|STYP_OVRFLO
value|0x8000
end_define

begin_comment
comment|/* Specifies an exception section.  A section of this type provides     information to identify the reason that a trap or ececptin occured within     and executable object program */
end_comment

begin_define
define|#
directive|define
name|STYP_EXCEPT
value|0x0100
end_define

begin_comment
comment|/* Specifies a type check section.  A section of this type contains parameter     argument type check strings used by the AIX binder.  */
end_comment

begin_define
define|#
directive|define
name|STYP_TYPCHK
value|0x4000
end_define

begin_define
define|#
directive|define
name|RS6K_AOUTHDR_OMAGIC
value|0x0107
end_define

begin_comment
comment|/* old: text& data writeable */
end_comment

begin_define
define|#
directive|define
name|RS6K_AOUTHDR_NMAGIC
value|0x0108
end_define

begin_comment
comment|/* new: text r/o, data r/w */
end_comment

begin_define
define|#
directive|define
name|RS6K_AOUTHDR_ZMAGIC
value|0x010B
end_define

begin_comment
comment|/* paged: text r/o, both page-aligned */
end_comment

begin_comment
comment|/* XCOFF relocation types.      The relocations are described in the function      xcoff[64]_ppc_relocate_section in coff64-rs6000.c and coff-rs6000.c  */
end_comment

begin_define
define|#
directive|define
name|R_POS
value|(0x00)
end_define

begin_define
define|#
directive|define
name|R_NEG
value|(0x01)
end_define

begin_define
define|#
directive|define
name|R_REL
value|(0x02)
end_define

begin_define
define|#
directive|define
name|R_TOC
value|(0x03)
end_define

begin_define
define|#
directive|define
name|R_RTB
value|(0x04)
end_define

begin_define
define|#
directive|define
name|R_GL
value|(0x05)
end_define

begin_define
define|#
directive|define
name|R_TCL
value|(0x06)
end_define

begin_define
define|#
directive|define
name|R_BA
value|(0x08)
end_define

begin_define
define|#
directive|define
name|R_BR
value|(0x0a)
end_define

begin_define
define|#
directive|define
name|R_RL
value|(0x0c)
end_define

begin_define
define|#
directive|define
name|R_RLA
value|(0x0d)
end_define

begin_define
define|#
directive|define
name|R_REF
value|(0x0f)
end_define

begin_define
define|#
directive|define
name|R_TRL
value|(0x12)
end_define

begin_define
define|#
directive|define
name|R_TRLA
value|(0x13)
end_define

begin_define
define|#
directive|define
name|R_RRTBI
value|(0x14)
end_define

begin_define
define|#
directive|define
name|R_RRTBA
value|(0x15)
end_define

begin_define
define|#
directive|define
name|R_CAI
value|(0x16)
end_define

begin_define
define|#
directive|define
name|R_CREL
value|(0x17)
end_define

begin_define
define|#
directive|define
name|R_RBA
value|(0x18)
end_define

begin_define
define|#
directive|define
name|R_RBAC
value|(0x19)
end_define

begin_define
define|#
directive|define
name|R_RBR
value|(0x1a)
end_define

begin_define
define|#
directive|define
name|R_RBRC
value|(0x1b)
end_define

begin_comment
comment|/* Storage class #defines, from /usr/include/storclass.h that are not already     defined in internal.h */
end_comment

begin_comment
comment|/* Comment string in .info section */
end_comment

begin_define
define|#
directive|define
name|C_INFO
value|110
end_define

begin_comment
comment|/* Auxillary Symbol Entries  */
end_comment

begin_comment
comment|/* x_smtyp values:  */
end_comment

begin_define
define|#
directive|define
name|SMTYP_ALIGN
parameter_list|(
name|x
parameter_list|)
value|((x)>> 3)
end_define

begin_comment
comment|/* log2 of alignment */
end_comment

begin_define
define|#
directive|define
name|SMTYP_SMTYP
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x7)
end_define

begin_comment
comment|/* symbol type */
end_comment

begin_comment
comment|/* Symbol type values:  */
end_comment

begin_define
define|#
directive|define
name|XTY_ER
value|0
end_define

begin_comment
comment|/* External reference */
end_comment

begin_define
define|#
directive|define
name|XTY_SD
value|1
end_define

begin_comment
comment|/* Csect definition */
end_comment

begin_define
define|#
directive|define
name|XTY_LD
value|2
end_define

begin_comment
comment|/* Label definition */
end_comment

begin_define
define|#
directive|define
name|XTY_CM
value|3
end_define

begin_comment
comment|/* .BSS */
end_comment

begin_define
define|#
directive|define
name|XTY_EM
value|4
end_define

begin_comment
comment|/* Error message */
end_comment

begin_define
define|#
directive|define
name|XTY_US
value|5
end_define

begin_comment
comment|/* "Reserved for internal use" */
end_comment

begin_comment
comment|/* x_smclas values:  */
end_comment

begin_define
define|#
directive|define
name|XMC_PR
value|0
end_define

begin_comment
comment|/* Read-only program code */
end_comment

begin_define
define|#
directive|define
name|XMC_RO
value|1
end_define

begin_comment
comment|/* Read-only constant */
end_comment

begin_define
define|#
directive|define
name|XMC_DB
value|2
end_define

begin_comment
comment|/* Read-only debug dictionary table */
end_comment

begin_define
define|#
directive|define
name|XMC_TC
value|3
end_define

begin_comment
comment|/* Read-write general TOC entry */
end_comment

begin_define
define|#
directive|define
name|XMC_UA
value|4
end_define

begin_comment
comment|/* Read-write unclassified */
end_comment

begin_define
define|#
directive|define
name|XMC_RW
value|5
end_define

begin_comment
comment|/* Read-write data */
end_comment

begin_define
define|#
directive|define
name|XMC_GL
value|6
end_define

begin_comment
comment|/* Read-only global linkage */
end_comment

begin_define
define|#
directive|define
name|XMC_XO
value|7
end_define

begin_comment
comment|/* Read-only extended operation */
end_comment

begin_define
define|#
directive|define
name|XMC_SV
value|8
end_define

begin_comment
comment|/* Read-only supervisor call */
end_comment

begin_define
define|#
directive|define
name|XMC_BS
value|9
end_define

begin_comment
comment|/* Read-write BSS */
end_comment

begin_define
define|#
directive|define
name|XMC_DS
value|10
end_define

begin_comment
comment|/* Read-write descriptor csect */
end_comment

begin_define
define|#
directive|define
name|XMC_UC
value|11
end_define

begin_comment
comment|/* Read-write unnamed Fortran common */
end_comment

begin_define
define|#
directive|define
name|XMC_TI
value|12
end_define

begin_comment
comment|/* Read-only traceback index csect */
end_comment

begin_define
define|#
directive|define
name|XMC_TB
value|13
end_define

begin_comment
comment|/* Read-only traceback table csect */
end_comment

begin_comment
comment|/* 		14	??? */
end_comment

begin_define
define|#
directive|define
name|XMC_TC0
value|15
end_define

begin_comment
comment|/* Read-write TOC anchor */
end_comment

begin_define
define|#
directive|define
name|XMC_TD
value|16
end_define

begin_comment
comment|/* Read-write data in TOC */
end_comment

begin_define
define|#
directive|define
name|XMC_SV64
value|17
end_define

begin_comment
comment|/* Read-only 64 bit supervisor call */
end_comment

begin_define
define|#
directive|define
name|XMC_SV3264
value|18
end_define

begin_comment
comment|/* Read-only 32 or 64 bit supervisor call */
end_comment

begin_comment
comment|/* The ldhdr structure.  This appears at the start of the .loader    section.  */
end_comment

begin_struct
struct|struct
name|internal_ldhdr
block|{
comment|/* The version number:       1 : 32 bit      2 : 64 bit */
name|unsigned
name|long
name|l_version
decl_stmt|;
comment|/* The number of symbol table entries.  */
name|bfd_size_type
name|l_nsyms
decl_stmt|;
comment|/* The number of relocation table entries.  */
name|bfd_size_type
name|l_nreloc
decl_stmt|;
comment|/* The length of the import file string table.  */
name|bfd_size_type
name|l_istlen
decl_stmt|;
comment|/* The number of import files.  */
name|bfd_size_type
name|l_nimpid
decl_stmt|;
comment|/* The offset from the start of the .loader section to the first      entry in the import file table.  */
name|bfd_size_type
name|l_impoff
decl_stmt|;
comment|/* The length of the string table.  */
name|bfd_size_type
name|l_stlen
decl_stmt|;
comment|/* The offset from the start of the .loader section to the first      entry in the string table.  */
name|bfd_size_type
name|l_stoff
decl_stmt|;
comment|/* The offset to start of the symbol table, only in XCOFF64 */
name|bfd_vma
name|l_symoff
decl_stmt|;
comment|/* The offset to the start of the relocation table, only in XCOFF64 */
name|bfd_vma
name|l_rldoff
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The ldsym structure.  This is used to represent a symbol in the    .loader section.  */
end_comment

begin_struct
struct|struct
name|internal_ldsym
block|{
union|union
block|{
comment|/* The symbol name if<= SYMNMLEN characters.  */
name|char
name|_l_name
index|[
name|SYMNMLEN
index|]
decl_stmt|;
struct|struct
block|{
comment|/* Zero if the symbol name is more than SYMNMLEN characters.  */
name|long
name|_l_zeroes
decl_stmt|;
comment|/* The offset in the string table if the symbol name is more 	 than SYMNMLEN characters.  */
name|long
name|_l_offset
decl_stmt|;
block|}
name|_l_l
struct|;
block|}
name|_l
union|;
comment|/* The symbol value.  */
name|bfd_vma
name|l_value
decl_stmt|;
comment|/* The symbol section number.  */
name|short
name|l_scnum
decl_stmt|;
comment|/* The symbol type and flags.  */
name|char
name|l_smtype
decl_stmt|;
comment|/* The symbol storage class.  */
name|char
name|l_smclas
decl_stmt|;
comment|/* The import file ID.  */
name|bfd_size_type
name|l_ifile
decl_stmt|;
comment|/* Offset to the parameter type check string.  */
name|bfd_size_type
name|l_parm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These flags are for the l_smtype field (the lower three bits are an    XTY_* value).  */
end_comment

begin_comment
comment|/* Imported symbol.  */
end_comment

begin_define
define|#
directive|define
name|L_IMPORT
value|(0x40)
end_define

begin_comment
comment|/* Entry point.  */
end_comment

begin_define
define|#
directive|define
name|L_ENTRY
value|(0x20)
end_define

begin_comment
comment|/* Exported symbol.  */
end_comment

begin_define
define|#
directive|define
name|L_EXPORT
value|(0x10)
end_define

begin_comment
comment|/* The ldrel structure.  This is used to represent a reloc in the    .loader section.  */
end_comment

begin_struct
struct|struct
name|internal_ldrel
block|{
comment|/* The reloc address.  */
name|bfd_vma
name|l_vaddr
decl_stmt|;
comment|/* The symbol table index in the .loader section symbol table.  */
name|bfd_size_type
name|l_symndx
decl_stmt|;
comment|/* The relocation type and size.  */
name|short
name|l_rtype
decl_stmt|;
comment|/* The section number this relocation applies to.  */
name|short
name|l_rsecnm
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An entry in the XCOFF linker hash table.  */
end_comment

begin_struct
struct|struct
name|xcoff_link_hash_entry
block|{
name|struct
name|bfd_link_hash_entry
name|root
decl_stmt|;
comment|/* Symbol index in output file.  Set to -1 initially.  Set to -2 if      there is a reloc against this symbol.  */
name|long
name|indx
decl_stmt|;
comment|/* If we have created a TOC entry for this symbol, this is the .tc      section which holds it.  */
name|asection
modifier|*
name|toc_section
decl_stmt|;
union|union
block|{
comment|/* If we have created a TOC entry (the XCOFF_SET_TOC flag is        set), this is the offset in toc_section.  */
name|bfd_vma
name|toc_offset
decl_stmt|;
comment|/* If the TOC entry comes from an input file, this is set to the        symbol index of the C_HIDEXT XMC_TC or XMC_TD symbol.  */
name|long
name|toc_indx
decl_stmt|;
block|}
name|u
union|;
comment|/* If this symbol is a function entry point which is called, this      field holds a pointer to the function descriptor.  If this symbol      is a function descriptor, this field holds a pointer to the      function entry point.  */
name|struct
name|xcoff_link_hash_entry
modifier|*
name|descriptor
decl_stmt|;
comment|/* The .loader symbol table entry, if there is one.  */
name|struct
name|internal_ldsym
modifier|*
name|ldsym
decl_stmt|;
comment|/* If XCOFF_BUILT_LDSYM is set, this is the .loader symbol table      index.  If XCOFF_BUILD_LDSYM is clear, and XCOFF_IMPORT is set,      this is the l_ifile value.  */
name|long
name|ldindx
decl_stmt|;
comment|/* Some linker flags.  */
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* The storage mapping class.  */
name|unsigned
name|char
name|smclas
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  Flags for xcoff_link_hash_entry.  */
end_comment

begin_comment
comment|/* Symbol is referenced by a regular object. */
end_comment

begin_define
define|#
directive|define
name|XCOFF_REF_REGULAR
value|0x00000001
end_define

begin_comment
comment|/* Symbol is defined by a regular object. */
end_comment

begin_define
define|#
directive|define
name|XCOFF_DEF_REGULAR
value|0x00000002
end_define

begin_comment
comment|/* Symbol is defined by a dynamic object. */
end_comment

begin_define
define|#
directive|define
name|XCOFF_DEF_DYNAMIC
value|0x00000004
end_define

begin_comment
comment|/* Symbol is used in a reloc being copied into the .loader section.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_LDREL
value|0x00000008
end_define

begin_comment
comment|/* Symbol is the entry point.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_ENTRY
value|0x00000010
end_define

begin_comment
comment|/* Symbol is called; this is, it appears in a R_BR reloc.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_CALLED
value|0x00000020
end_define

begin_comment
comment|/* Symbol needs the TOC entry filled in.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_SET_TOC
value|0x00000040
end_define

begin_comment
comment|/* Symbol is explicitly imported.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_IMPORT
value|0x00000080
end_define

begin_comment
comment|/* Symbol is explicitly exported.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_EXPORT
value|0x00000100
end_define

begin_comment
comment|/* Symbol has been processed by xcoff_build_ldsyms.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_BUILT_LDSYM
value|0x00000200
end_define

begin_comment
comment|/* Symbol is mentioned by a section which was not garbage collected. */
end_comment

begin_define
define|#
directive|define
name|XCOFF_MARK
value|0x00000400
end_define

begin_comment
comment|/* Symbol size is recorded in size_list list from hash table.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_HAS_SIZE
value|0x00000800
end_define

begin_comment
comment|/* Symbol is a function descriptor.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_DESCRIPTOR
value|0x00001000
end_define

begin_comment
comment|/* Multiple definitions have been for the symbol. */
end_comment

begin_define
define|#
directive|define
name|XCOFF_MULTIPLY_DEFINED
value|0x00002000
end_define

begin_comment
comment|/* Symbol is the __rtinit symbol.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_RTINIT
value|0x00004000
end_define

begin_comment
comment|/* Symbol is an imported 32 bit syscall.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_SYSCALL32
value|0x00008000
end_define

begin_comment
comment|/* Symbol is an imported 64 bit syscall.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_SYSCALL64
value|0x00010000
end_define

begin_comment
comment|/* The XCOFF linker hash table.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_NUMBER_OF_SPECIAL_SECTIONS
value|6
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_TEXT
value|0
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_ETEXT
value|1
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_DATA
value|2
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_EDATA
value|3
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_END
value|4
end_define

begin_define
define|#
directive|define
name|XCOFF_SPECIAL_SECTION_END2
value|5
end_define

begin_struct
struct|struct
name|xcoff_link_hash_table
block|{
name|struct
name|bfd_link_hash_table
name|root
decl_stmt|;
comment|/* The .debug string hash table.  We need to compute this while      reading the input files, so that we know how large the .debug      section will be before we assign section positions.  */
name|struct
name|bfd_strtab_hash
modifier|*
name|debug_strtab
decl_stmt|;
comment|/* The .debug section we will use for the final output.  */
name|asection
modifier|*
name|debug_section
decl_stmt|;
comment|/* The .loader section we will use for the final output.  */
name|asection
modifier|*
name|loader_section
decl_stmt|;
comment|/* A count of non TOC relative relocs which will need to be      allocated in the .loader section.  */
name|size_t
name|ldrel_count
decl_stmt|;
comment|/* The .loader section header.  */
name|struct
name|internal_ldhdr
name|ldhdr
decl_stmt|;
comment|/* The .gl section we use to hold global linkage code.  */
name|asection
modifier|*
name|linkage_section
decl_stmt|;
comment|/* The .tc section we use to hold toc entries we build for global      linkage code.  */
name|asection
modifier|*
name|toc_section
decl_stmt|;
comment|/* The .ds section we use to hold function descriptors which we      create for exported symbols.  */
name|asection
modifier|*
name|descriptor_section
decl_stmt|;
comment|/* The list of import files.  */
name|struct
name|xcoff_import_file
modifier|*
name|imports
decl_stmt|;
comment|/* Required alignment of sections within the output file.  */
name|unsigned
name|long
name|file_align
decl_stmt|;
comment|/* Whether the .text section must be read-only.  */
name|bfd_boolean
name|textro
decl_stmt|;
comment|/* Whether garbage collection was done.  */
name|bfd_boolean
name|gc
decl_stmt|;
comment|/* A linked list of symbols for which we have size information.  */
struct|struct
name|xcoff_link_size_list
block|{
name|struct
name|xcoff_link_size_list
modifier|*
name|next
decl_stmt|;
name|struct
name|xcoff_link_hash_entry
modifier|*
name|h
decl_stmt|;
name|bfd_size_type
name|size
decl_stmt|;
block|}
modifier|*
name|size_list
struct|;
comment|/* Magic sections: _text, _etext, _data, _edata, _end, end. */
name|asection
modifier|*
name|special_sections
index|[
name|XCOFF_NUMBER_OF_SPECIAL_SECTIONS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure is used to pass information through    xcoff_link_hash_traverse.  */
end_comment

begin_struct
struct|struct
name|xcoff_loader_info
block|{
comment|/* Set if a problem occurred.  */
name|bfd_boolean
name|failed
decl_stmt|;
comment|/* Output BFD.  */
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
comment|/* Link information structure.  */
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
comment|/* Whether all defined symbols should be exported.  */
name|bfd_boolean
name|export_defineds
decl_stmt|;
comment|/* Number of ldsym structures.  */
name|size_t
name|ldsym_count
decl_stmt|;
comment|/* Size of string table.  */
name|size_t
name|string_size
decl_stmt|;
comment|/* String table.  */
name|bfd_byte
modifier|*
name|strings
decl_stmt|;
comment|/* Allocated size of string table.  */
name|size_t
name|string_alc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* In case we're on a 32-bit machine, construct a 64-bit "-1" value    from smaller values.  Start with zero, widen, *then* decrement.  */
end_comment

begin_define
define|#
directive|define
name|MINUS_ONE
value|(((bfd_vma) 0) - 1)
end_define

begin_comment
comment|/* __rtinit, from /usr/include/rtinit.h.  */
end_comment

begin_struct
struct|struct
name|__rtinit
block|{
comment|/* Pointer to runtime linker.           XXX: Is the parameter really void?  */
name|int
function_decl|(
modifier|*
name|rtl
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Offset to array of init functions, 0 if none. */
name|int
name|init_offset
decl_stmt|;
comment|/* Offset to array of fini functions, 0 if none. */
name|int
name|fini_offset
decl_stmt|;
comment|/* Size of __RTINIT_DESCRIPTOR. This value should be used instead of       sizeof(__RTINIT_DESCRIPTOR). */
name|int
name|__rtinit_descriptor_size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RTINIT_DESCRIPTOR_SIZE
value|(12)
end_define

begin_struct
struct|struct
name|__rtinit_descriptor
block|{
comment|/* Init/fini function. */
name|int
name|f
decl_stmt|;
comment|/* Offset, relative to the start of the __rtinit symbol, to name of the       function. */
name|int
name|name_offset
decl_stmt|;
comment|/* Flags */
name|unsigned
name|char
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Archive */
end_comment

begin_define
define|#
directive|define
name|XCOFFARMAG
value|"<aiaff>\012"
end_define

begin_define
define|#
directive|define
name|XCOFFARMAGBIG
value|"<bigaf>\012"
end_define

begin_define
define|#
directive|define
name|SXCOFFARMAG
value|8
end_define

begin_comment
comment|/* The size of the ascii archive elements */
end_comment

begin_define
define|#
directive|define
name|XCOFFARMAG_ELEMENT_SIZE
value|12
end_define

begin_define
define|#
directive|define
name|XCOFFARMAGBIG_ELEMENT_SIZE
value|20
end_define

begin_comment
comment|/* This terminates an XCOFF archive member name.  */
end_comment

begin_define
define|#
directive|define
name|XCOFFARFMAG
value|"`\012"
end_define

begin_define
define|#
directive|define
name|SXCOFFARFMAG
value|2
end_define

begin_comment
comment|/* XCOFF archives start with this (printable) structure.  */
end_comment

begin_struct
struct|struct
name|xcoff_ar_file_hdr
block|{
comment|/* Magic string.  */
name|char
name|magic
index|[
name|SXCOFFARMAG
index|]
decl_stmt|;
comment|/* Offset of the member table (decimal ASCII string).  */
name|char
name|memoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the global symbol table (decimal ASCII string).  */
name|char
name|symoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the first member in the archive (decimal ASCII string).  */
name|char
name|firstmemoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the last member in the archive (decimal ASCII string).  */
name|char
name|lastmemoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the first member on the free list (decimal ASCII      string).  */
name|char
name|freeoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_AR_FILE_HDR
value|(SXCOFFARMAG + 5 * XCOFFARMAG_ELEMENT_SIZE)
end_define

begin_comment
comment|/* This is the equivalent data structure for the big archive format.  */
end_comment

begin_struct
struct|struct
name|xcoff_ar_file_hdr_big
block|{
comment|/* Magic string.  */
name|char
name|magic
index|[
name|SXCOFFARMAG
index|]
decl_stmt|;
comment|/* Offset of the member table (decimal ASCII string).  */
name|char
name|memoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the global symbol table for 32-bit objects (decimal ASCII      string).  */
name|char
name|symoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the global symbol table for 64-bit objects (decimal ASCII      string).  */
name|char
name|symoff64
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the first member in the archive (decimal ASCII string).  */
name|char
name|firstmemoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the last member in the archive (decimal ASCII string).  */
name|char
name|lastmemoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* Offset of the first member on the free list (decimal ASCII      string).  */
name|char
name|freeoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_AR_FILE_HDR_BIG
value|(SXCOFFARMAG + 6 * XCOFFARMAGBIG_ELEMENT_SIZE)
end_define

begin_comment
comment|/* Each XCOFF archive member starts with this (printable) structure.  */
end_comment

begin_struct
struct|struct
name|xcoff_ar_hdr
block|{
comment|/* File size not including the header (decimal ASCII string).  */
name|char
name|size
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File offset of next archive member (decimal ASCII string).  */
name|char
name|nextoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File offset of previous archive member (decimal ASCII string).  */
name|char
name|prevoff
index|[
name|XCOFFARMAG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File mtime (decimal ASCII string).  */
name|char
name|date
index|[
literal|12
index|]
decl_stmt|;
comment|/* File UID (decimal ASCII string).  */
name|char
name|uid
index|[
literal|12
index|]
decl_stmt|;
comment|/* File GID (decimal ASCII string).  */
name|char
name|gid
index|[
literal|12
index|]
decl_stmt|;
comment|/* File mode (octal ASCII string).  */
name|char
name|mode
index|[
literal|12
index|]
decl_stmt|;
comment|/* Length of file name (decimal ASCII string).  */
name|char
name|namlen
index|[
literal|4
index|]
decl_stmt|;
comment|/* This structure is followed by the file name.  The length of the      name is given in the namlen field.  If the length of the name is      odd, the name is followed by a null byte.  The name and optional      null byte are followed by XCOFFARFMAG, which is not included in      namlen.  The contents of the archive member follow; the number of      bytes is given in the size field.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_AR_HDR
value|(3 * XCOFFARMAG_ELEMENT_SIZE + 4 * 12 + 4)
end_define

begin_comment
comment|/* The equivalent for the big archive format.  */
end_comment

begin_struct
struct|struct
name|xcoff_ar_hdr_big
block|{
comment|/* File size not including the header (decimal ASCII string).  */
name|char
name|size
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File offset of next archive member (decimal ASCII string).  */
name|char
name|nextoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File offset of previous archive member (decimal ASCII string).  */
name|char
name|prevoff
index|[
name|XCOFFARMAGBIG_ELEMENT_SIZE
index|]
decl_stmt|;
comment|/* File mtime (decimal ASCII string).  */
name|char
name|date
index|[
literal|12
index|]
decl_stmt|;
comment|/* File UID (decimal ASCII string).  */
name|char
name|uid
index|[
literal|12
index|]
decl_stmt|;
comment|/* File GID (decimal ASCII string).  */
name|char
name|gid
index|[
literal|12
index|]
decl_stmt|;
comment|/* File mode (octal ASCII string).  */
name|char
name|mode
index|[
literal|12
index|]
decl_stmt|;
comment|/* Length of file name (decimal ASCII string).  */
name|char
name|namlen
index|[
literal|4
index|]
decl_stmt|;
comment|/* This structure is followed by the file name.  The length of the      name is given in the namlen field.  If the length of the name is      odd, the name is followed by a null byte.  The name and optional      null byte are followed by XCOFFARFMAG, which is not included in      namlen.  The contents of the archive member follow; the number of      bytes is given in the size field.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SIZEOF_AR_HDR_BIG
value|(3 * XCOFFARMAGBIG_ELEMENT_SIZE + 4 * 12 + 4)
end_define

begin_comment
comment|/* We often have to distinguish between the old and big file format.    Make it a bit cleaner.  We can use `xcoff_ardata' here because the    `hdr' member has the same size and position in both formats.<bigaf> is the default format, return TRUE even when xcoff_ardata is     NULL. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMALL_ARCHIVE
end_ifndef

begin_comment
comment|/* Creates big archives by default */
end_comment

begin_define
define|#
directive|define
name|xcoff_big_format_p
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((NULL != bfd_ardata (abfd)&& NULL == xcoff_ardata (abfd)) || \    ((NULL != bfd_ardata (abfd))&& \     (NULL != xcoff_ardata (abfd))&& \     (xcoff_ardata (abfd)->magic[1] == 'b')))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Creates small archives by default. */
end_comment

begin_define
define|#
directive|define
name|xcoff_big_format_p
parameter_list|(
name|abfd
parameter_list|)
define|\
value|(((NULL != bfd_ardata (abfd))&& \     (NULL != xcoff_ardata (abfd))&& \     (xcoff_ardata (abfd)->magic[1] == 'b')))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We store a copy of the xcoff_ar_file_hdr in the tdata field of the    artdata structure.  Similar for the big archive.  */
end_comment

begin_define
define|#
directive|define
name|xcoff_ardata
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((struct xcoff_ar_file_hdr *) bfd_ardata (abfd)->tdata)
end_define

begin_define
define|#
directive|define
name|xcoff_ardata_big
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((struct xcoff_ar_file_hdr_big *) bfd_ardata (abfd)->tdata)
end_define

begin_comment
comment|/* We store a copy of the xcoff_ar_hdr in the arelt_data field of an    archive element.  Similar for the big archive.  */
end_comment

begin_define
define|#
directive|define
name|arch_eltdata
parameter_list|(
name|bfd
parameter_list|)
value|((struct areltdata *) ((bfd)->arelt_data))
end_define

begin_define
define|#
directive|define
name|arch_xhdr
parameter_list|(
name|bfd
parameter_list|)
define|\
value|((struct xcoff_ar_hdr *) arch_eltdata (bfd)->arch_header)
end_define

begin_define
define|#
directive|define
name|arch_xhdr_big
parameter_list|(
name|bfd
parameter_list|)
define|\
value|((struct xcoff_ar_hdr_big *) arch_eltdata (bfd)->arch_header)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INTERNAL_XCOFF_H */
end_comment

end_unit

