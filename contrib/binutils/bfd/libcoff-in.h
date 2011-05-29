begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD COFF object file private structure.    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001, 2002, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.    Written by Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_comment
comment|/* Object file tdata; access macros.  */
end_comment

begin_define
define|#
directive|define
name|coff_data
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.coff_obj_data)
end_define

begin_define
define|#
directive|define
name|exec_hdr
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->hdr)
end_define

begin_define
define|#
directive|define
name|obj_pe
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->pe)
end_define

begin_define
define|#
directive|define
name|obj_symbols
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->symbols)
end_define

begin_define
define|#
directive|define
name|obj_sym_filepos
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->sym_filepos)
end_define

begin_define
define|#
directive|define
name|obj_relocbase
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->relocbase)
end_define

begin_define
define|#
directive|define
name|obj_raw_syments
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->raw_syments)
end_define

begin_define
define|#
directive|define
name|obj_raw_syment_count
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->raw_syment_count)
end_define

begin_define
define|#
directive|define
name|obj_convert
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->conversion_table)
end_define

begin_define
define|#
directive|define
name|obj_conv_table_size
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->conv_table_size)
end_define

begin_define
define|#
directive|define
name|obj_coff_external_syms
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->external_syms)
end_define

begin_define
define|#
directive|define
name|obj_coff_keep_syms
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->keep_syms)
end_define

begin_define
define|#
directive|define
name|obj_coff_strings
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->strings)
end_define

begin_define
define|#
directive|define
name|obj_coff_keep_strings
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->keep_strings)
end_define

begin_define
define|#
directive|define
name|obj_coff_sym_hashes
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->sym_hashes)
end_define

begin_define
define|#
directive|define
name|obj_coff_strings_written
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->strings_written)
end_define

begin_define
define|#
directive|define
name|obj_coff_local_toc_table
parameter_list|(
name|bfd
parameter_list|)
value|(coff_data (bfd)->local_toc_sym_map)
end_define

begin_comment
comment|/* `Tdata' information kept for COFF files.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|coff_tdata
block|{
name|struct
name|coff_symbol_struct
modifier|*
name|symbols
decl_stmt|;
comment|/* Symtab for input bfd.  */
name|unsigned
name|int
modifier|*
name|conversion_table
decl_stmt|;
name|int
name|conv_table_size
decl_stmt|;
name|file_ptr
name|sym_filepos
decl_stmt|;
name|struct
name|coff_ptr_struct
modifier|*
name|raw_syments
decl_stmt|;
name|unsigned
name|long
name|raw_syment_count
decl_stmt|;
comment|/* These are only valid once writing has begun.  */
name|long
name|int
name|relocbase
decl_stmt|;
comment|/* These members communicate important constants about the symbol table      to GDB's symbol-reading code.  These `constants' unfortunately vary      from coff implementation to implementation...  */
name|unsigned
name|local_n_btmask
decl_stmt|;
name|unsigned
name|local_n_btshft
decl_stmt|;
name|unsigned
name|local_n_tmask
decl_stmt|;
name|unsigned
name|local_n_tshift
decl_stmt|;
name|unsigned
name|local_symesz
decl_stmt|;
name|unsigned
name|local_auxesz
decl_stmt|;
name|unsigned
name|local_linesz
decl_stmt|;
comment|/* The unswapped external symbols.  May be NULL.  Read by      _bfd_coff_get_external_symbols.  */
name|void
modifier|*
name|external_syms
decl_stmt|;
comment|/* If this is TRUE, the external_syms may not be freed.  */
name|bfd_boolean
name|keep_syms
decl_stmt|;
comment|/* The string table.  May be NULL.  Read by      _bfd_coff_read_string_table.  */
name|char
modifier|*
name|strings
decl_stmt|;
comment|/* If this is TRUE, the strings may not be freed.  */
name|bfd_boolean
name|keep_strings
decl_stmt|;
comment|/* If this is TRUE, the strings have been written out already.  */
name|bfd_boolean
name|strings_written
decl_stmt|;
comment|/* Is this a PE format coff file?  */
name|int
name|pe
decl_stmt|;
comment|/* Used by the COFF backend linker.  */
name|struct
name|coff_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
decl_stmt|;
comment|/* Used by the pe linker for PowerPC.  */
name|int
modifier|*
name|local_toc_sym_map
decl_stmt|;
name|struct
name|bfd_link_info
modifier|*
name|link_info
decl_stmt|;
comment|/* Used by coff_find_nearest_line.  */
name|void
modifier|*
name|line_info
decl_stmt|;
comment|/* A place to stash dwarf2 info for this bfd.  */
name|void
modifier|*
name|dwarf2_find_line_info
decl_stmt|;
comment|/* The timestamp from the COFF file header.  */
name|long
name|timestamp
decl_stmt|;
comment|/* Copy of some of the f_flags bits in the COFF filehdr structure,      used by ARM code.  */
name|flagword
name|flags
decl_stmt|;
block|}
name|coff_data_type
typedef|;
end_typedef

begin_comment
comment|/* Tdata for pe image files.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pe_tdata
block|{
name|coff_data_type
name|coff
decl_stmt|;
name|struct
name|internal_extra_pe_aouthdr
name|pe_opthdr
decl_stmt|;
name|int
name|dll
decl_stmt|;
name|int
name|has_reloc_section
decl_stmt|;
name|bfd_boolean
function_decl|(
modifier|*
name|in_reloc_p
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|reloc_howto_type
modifier|*
parameter_list|)
function_decl|;
name|flagword
name|real_flags
decl_stmt|;
name|int
name|target_subsystem
decl_stmt|;
name|bfd_boolean
name|force_minimum_alignment
decl_stmt|;
block|}
name|pe_data_type
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pe_data
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.pe_obj_data)
end_define

begin_comment
comment|/* Tdata for XCOFF files.  */
end_comment

begin_struct
struct|struct
name|xcoff_tdata
block|{
comment|/* Basic COFF information.  */
name|coff_data_type
name|coff
decl_stmt|;
comment|/* TRUE if this is an XCOFF64 file. */
name|bfd_boolean
name|xcoff64
decl_stmt|;
comment|/* TRUE if a large a.out header should be generated.  */
name|bfd_boolean
name|full_aouthdr
decl_stmt|;
comment|/* TOC value.  */
name|bfd_vma
name|toc
decl_stmt|;
comment|/* Index of section holding TOC.  */
name|int
name|sntoc
decl_stmt|;
comment|/* Index of section holding entry point.  */
name|int
name|snentry
decl_stmt|;
comment|/* .text alignment from optional header.  */
name|int
name|text_align_power
decl_stmt|;
comment|/* .data alignment from optional header.  */
name|int
name|data_align_power
decl_stmt|;
comment|/* modtype from optional header.  */
name|short
name|modtype
decl_stmt|;
comment|/* cputype from optional header.  */
name|short
name|cputype
decl_stmt|;
comment|/* maxdata from optional header.  */
name|bfd_vma
name|maxdata
decl_stmt|;
comment|/* maxstack from optional header.  */
name|bfd_vma
name|maxstack
decl_stmt|;
comment|/* Used by the XCOFF backend linker.  */
name|asection
modifier|*
modifier|*
name|csects
decl_stmt|;
name|unsigned
name|long
modifier|*
name|debug_indices
decl_stmt|;
name|unsigned
name|int
name|import_file_id
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|xcoff_data
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->tdata.xcoff_obj_data)
end_define

begin_comment
comment|/* We take the address of the first element of an asymbol to ensure that the    macro is only ever applied to an asymbol.  */
end_comment

begin_define
define|#
directive|define
name|coffsymbol
parameter_list|(
name|asymbol
parameter_list|)
value|((coff_symbol_type *)(&((asymbol)->the_bfd)))
end_define

begin_comment
comment|/* The used_by_bfd field of a section may be set to a pointer to this    structure.  */
end_comment

begin_struct
struct|struct
name|coff_section_tdata
block|{
comment|/* The relocs, swapped into COFF internal form.  This may be NULL.  */
name|struct
name|internal_reloc
modifier|*
name|relocs
decl_stmt|;
comment|/* If this is TRUE, the relocs entry may not be freed.  */
name|bfd_boolean
name|keep_relocs
decl_stmt|;
comment|/* The section contents.  This may be NULL.  */
name|bfd_byte
modifier|*
name|contents
decl_stmt|;
comment|/* If this is TRUE, the contents entry may not be freed.  */
name|bfd_boolean
name|keep_contents
decl_stmt|;
comment|/* Information cached by coff_find_nearest_line.  */
name|bfd_vma
name|offset
decl_stmt|;
name|unsigned
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|function
decl_stmt|;
comment|/* Optional information about a COMDAT entry; NULL if not COMDAT. */
name|struct
name|coff_comdat_info
modifier|*
name|comdat
decl_stmt|;
name|int
name|line_base
decl_stmt|;
comment|/* A pointer used for .stab linking optimizations.  */
name|void
modifier|*
name|stab_info
decl_stmt|;
comment|/* Available for individual backends.  */
name|void
modifier|*
name|tdata
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An accessor macro for the coff_section_tdata structure.  */
end_comment

begin_define
define|#
directive|define
name|coff_section_data
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
define|\
value|((struct coff_section_tdata *) (sec)->used_by_bfd)
end_define

begin_comment
comment|/* Tdata for sections in XCOFF files.  This is used by the linker.  */
end_comment

begin_struct
struct|struct
name|xcoff_section_tdata
block|{
comment|/* Used for XCOFF csects created by the linker; points to the real      XCOFF section which contains this csect.  */
name|asection
modifier|*
name|enclosing
decl_stmt|;
comment|/* The lineno_count field for the enclosing section, because we are      going to clobber it there.  */
name|unsigned
name|int
name|lineno_count
decl_stmt|;
comment|/* The first and one past the last symbol indices for symbols used      by this csect.  */
name|unsigned
name|long
name|first_symndx
decl_stmt|;
name|unsigned
name|long
name|last_symndx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An accessor macro the xcoff_section_tdata structure.  */
end_comment

begin_define
define|#
directive|define
name|xcoff_section_data
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
define|\
value|((struct xcoff_section_tdata *) coff_section_data ((abfd), (sec))->tdata)
end_define

begin_comment
comment|/* Tdata for sections in PE files.  */
end_comment

begin_struct
struct|struct
name|pei_section_tdata
block|{
comment|/* The virtual size of the section.  */
name|bfd_size_type
name|virt_size
decl_stmt|;
comment|/* The PE section flags.  */
name|long
name|pe_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An accessor macro for the pei_section_tdata structure.  */
end_comment

begin_define
define|#
directive|define
name|pei_section_data
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
define|\
value|((struct pei_section_tdata *) coff_section_data ((abfd), (sec))->tdata)
end_define

begin_comment
comment|/* COFF linker hash table entries.  */
end_comment

begin_struct
struct|struct
name|coff_link_hash_entry
block|{
name|struct
name|bfd_link_hash_entry
name|root
decl_stmt|;
comment|/* Symbol index in output file.  Set to -1 initially.  Set to -2 if      there is a reloc against this symbol.  */
name|long
name|indx
decl_stmt|;
comment|/* Symbol type.  */
name|unsigned
name|short
name|type
decl_stmt|;
comment|/* Symbol class.  */
name|unsigned
name|char
name|class
decl_stmt|;
comment|/* Number of auxiliary entries.  */
name|char
name|numaux
decl_stmt|;
comment|/* BFD to take auxiliary entries from.  */
name|bfd
modifier|*
name|auxbfd
decl_stmt|;
comment|/* Pointer to array of auxiliary entries, if any.  */
name|union
name|internal_auxent
modifier|*
name|aux
decl_stmt|;
comment|/* Flag word; legal values follow.  */
name|unsigned
name|short
name|coff_link_hash_flags
decl_stmt|;
comment|/* Symbol is a PE section symbol.  */
define|#
directive|define
name|COFF_LINK_HASH_PE_SECTION_SYMBOL
value|(01)
block|}
struct|;
end_struct

begin_comment
comment|/* COFF linker hash table.  */
end_comment

begin_struct
struct|struct
name|coff_link_hash_table
block|{
name|struct
name|bfd_link_hash_table
name|root
decl_stmt|;
comment|/* A pointer to information used to link stabs in sections.  */
name|struct
name|stab_info
name|stab_info
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in a COFF linker hash table.  */
end_comment

begin_define
define|#
directive|define
name|coff_link_hash_lookup
parameter_list|(
name|table
parameter_list|,
name|string
parameter_list|,
name|create
parameter_list|,
name|copy
parameter_list|,
name|follow
parameter_list|)
define|\
value|((struct coff_link_hash_entry *)					\    bfd_link_hash_lookup (&(table)->root, (string), (create),		\ 			 (copy), (follow)))
end_define

begin_comment
comment|/* Traverse a COFF linker hash table.  */
end_comment

begin_define
define|#
directive|define
name|coff_link_hash_traverse
parameter_list|(
name|table
parameter_list|,
name|func
parameter_list|,
name|info
parameter_list|)
define|\
value|(bfd_link_hash_traverse						\    (&(table)->root,							\     (bfd_boolean (*) (struct bfd_link_hash_entry *, void *)) (func), \     (info)))
end_define

begin_comment
comment|/* Get the COFF linker hash table from a link_info structure.  */
end_comment

begin_define
define|#
directive|define
name|coff_hash_table
parameter_list|(
name|p
parameter_list|)
value|((struct coff_link_hash_table *) ((p)->hash))
end_define

begin_comment
comment|/* Functions in coffgen.c.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|coff_object_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|bfd_section
modifier|*
name|coff_section_from_bfd_index
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|coff_get_symtab_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|coff_canonicalize_symtab
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coff_count_linenumbers
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|coff_symbol_struct
modifier|*
name|coff_symbol_from
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|coff_renumber_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coff_mangle_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|coff_write_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|coff_write_linenumbers
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|alent
modifier|*
name|coff_get_lineno
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|coff_section_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_get_external_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|_bfd_coff_read_string_table
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_free_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|coff_ptr_struct
modifier|*
name|coff_get_normalized_symtab
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|coff_get_reloc_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|sec_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|coff_make_empty_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coff_print_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
name|filep
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|bfd_print_symbol_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|coff_get_symbol_info
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|,
name|symbol_info
modifier|*
name|ret
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_is_local_label_name
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|asymbol
modifier|*
name|coff_bfd_make_debug_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|coff_find_nearest_line
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|coff_find_inliner_info
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coff_sizeof_headers
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|bfd_coff_reloc16_relax_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_byte
modifier|*
name|bfd_coff_reloc16_get_relocated_section_contents
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|struct
name|bfd_link_order
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_vma
name|bfd_coff_reloc16_get_value
parameter_list|(
name|arelent
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bfd_perform_slip
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions and types in cofflink.c.  */
end_comment

begin_define
define|#
directive|define
name|STRING_SIZE_SIZE
value|4
end_define

begin_comment
comment|/* We use a hash table to merge identical enum, struct, and union    definitions in the linker.  */
end_comment

begin_comment
comment|/* Information we keep for a single element (an enum value, a    structure or union field) in the debug merge hash table.  */
end_comment

begin_struct
struct|struct
name|coff_debug_merge_element
block|{
comment|/* Next element.  */
name|struct
name|coff_debug_merge_element
modifier|*
name|next
decl_stmt|;
comment|/* Name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Type.  */
name|unsigned
name|int
name|type
decl_stmt|;
comment|/* Symbol index for complex type.  */
name|long
name|tagndx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A linked list of debug merge entries for a given name.  */
end_comment

begin_struct
struct|struct
name|coff_debug_merge_type
block|{
comment|/* Next type with the same name.  */
name|struct
name|coff_debug_merge_type
modifier|*
name|next
decl_stmt|;
comment|/* Class of type.  */
name|int
name|class
decl_stmt|;
comment|/* Symbol index where this type is defined.  */
name|long
name|indx
decl_stmt|;
comment|/* List of elements.  */
name|struct
name|coff_debug_merge_element
modifier|*
name|elements
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information we store in the debug merge hash table.  */
end_comment

begin_struct
struct|struct
name|coff_debug_merge_hash_entry
block|{
name|struct
name|bfd_hash_entry
name|root
decl_stmt|;
comment|/* A list of types with this name.  */
name|struct
name|coff_debug_merge_type
modifier|*
name|types
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The debug merge hash table.  */
end_comment

begin_struct
struct|struct
name|coff_debug_merge_hash_table
block|{
name|struct
name|bfd_hash_table
name|root
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Initialize a COFF debug merge hash table.  */
end_comment

begin_define
define|#
directive|define
name|coff_debug_merge_hash_table_init
parameter_list|(
name|table
parameter_list|)
define|\
value|(bfd_hash_table_init (&(table)->root, _bfd_coff_debug_merge_hash_newfunc, \ 			sizeof (struct coff_debug_merge_hash_entry)))
end_define

begin_comment
comment|/* Free a COFF debug merge hash table.  */
end_comment

begin_define
define|#
directive|define
name|coff_debug_merge_hash_table_free
parameter_list|(
name|table
parameter_list|)
define|\
value|(bfd_hash_table_free (&(table)->root))
end_define

begin_comment
comment|/* Look up an entry in a COFF debug merge hash table.  */
end_comment

begin_define
define|#
directive|define
name|coff_debug_merge_hash_lookup
parameter_list|(
name|table
parameter_list|,
name|string
parameter_list|,
name|create
parameter_list|,
name|copy
parameter_list|)
define|\
value|((struct coff_debug_merge_hash_entry *) \    bfd_hash_lookup (&(table)->root, (string), (create), (copy)))
end_define

begin_comment
comment|/* Information we keep for each section in the output file when doing    a relocatable link.  */
end_comment

begin_struct
struct|struct
name|coff_link_section_info
block|{
comment|/* The relocs to be output.  */
name|struct
name|internal_reloc
modifier|*
name|relocs
decl_stmt|;
comment|/* For each reloc against a global symbol whose index was not known      when the reloc was handled, the global hash table entry.  */
name|struct
name|coff_link_hash_entry
modifier|*
modifier|*
name|rel_hashes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information that we pass around while doing the final link step.  */
end_comment

begin_struct
struct|struct
name|coff_final_link_info
block|{
comment|/* General link information.  */
name|struct
name|bfd_link_info
modifier|*
name|info
decl_stmt|;
comment|/* Output BFD.  */
name|bfd
modifier|*
name|output_bfd
decl_stmt|;
comment|/* Used to indicate failure in traversal routine.  */
name|bfd_boolean
name|failed
decl_stmt|;
comment|/* If doing "task linking" set only during the time when we want the      global symbol writer to convert the storage class of defined global      symbols from global to static. */
name|bfd_boolean
name|global_to_static
decl_stmt|;
comment|/* Hash table for long symbol names.  */
name|struct
name|bfd_strtab_hash
modifier|*
name|strtab
decl_stmt|;
comment|/* When doing a relocatable link, an array of information kept for      each output section, indexed by the target_index field.  */
name|struct
name|coff_link_section_info
modifier|*
name|section_info
decl_stmt|;
comment|/* Symbol index of last C_FILE symbol (-1 if none).  */
name|long
name|last_file_index
decl_stmt|;
comment|/* Contents of last C_FILE symbol.  */
name|struct
name|internal_syment
name|last_file
decl_stmt|;
comment|/* Symbol index of first aux entry of last .bf symbol with an empty      endndx field (-1 if none).  */
name|long
name|last_bf_index
decl_stmt|;
comment|/* Contents of last_bf_index aux entry.  */
name|union
name|internal_auxent
name|last_bf
decl_stmt|;
comment|/* Hash table used to merge debug information.  */
name|struct
name|coff_debug_merge_hash_table
name|debug_merge
decl_stmt|;
comment|/* Buffer large enough to hold swapped symbols of any input file.  */
name|struct
name|internal_syment
modifier|*
name|internal_syms
decl_stmt|;
comment|/* Buffer large enough to hold sections of symbols of any input file.  */
name|asection
modifier|*
modifier|*
name|sec_ptrs
decl_stmt|;
comment|/* Buffer large enough to hold output indices of symbols of any      input file.  */
name|long
modifier|*
name|sym_indices
decl_stmt|;
comment|/* Buffer large enough to hold output symbols for any input file.  */
name|bfd_byte
modifier|*
name|outsyms
decl_stmt|;
comment|/* Buffer large enough to hold external line numbers for any input      section.  */
name|bfd_byte
modifier|*
name|linenos
decl_stmt|;
comment|/* Buffer large enough to hold any input section.  */
name|bfd_byte
modifier|*
name|contents
decl_stmt|;
comment|/* Buffer large enough to hold external relocs of any input section.  */
name|bfd_byte
modifier|*
name|external_relocs
decl_stmt|;
comment|/* Buffer large enough to hold swapped relocs of any input section.  */
name|struct
name|internal_reloc
modifier|*
name|internal_relocs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Most COFF variants have no way to record the alignment of a    section.  This struct is used to set a specific alignment based on    the name of the section.  */
end_comment

begin_struct
struct|struct
name|coff_section_alignment_entry
block|{
comment|/* The section name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* This is either (unsigned int) -1, indicating that the section      name must match exactly, or it is the number of letters which      must match at the start of the name.  */
name|unsigned
name|int
name|comparison_length
decl_stmt|;
comment|/* These macros may be used to fill in the first two fields in a      structure initialization.  */
define|#
directive|define
name|COFF_SECTION_NAME_EXACT_MATCH
parameter_list|(
name|name
parameter_list|)
value|(name), ((unsigned int) -1)
define|#
directive|define
name|COFF_SECTION_NAME_PARTIAL_MATCH
parameter_list|(
name|name
parameter_list|)
value|(name), (sizeof (name) - 1)
comment|/* Only use this entry if the default section alignment for this      target is at least that much (as a power of two).  If this field      is COFF_ALIGNMENT_FIELD_EMPTY, it should be ignored.  */
name|unsigned
name|int
name|default_alignment_min
decl_stmt|;
comment|/* Only use this entry if the default section alignment for this      target is no greater than this (as a power of two).  If this      field is COFF_ALIGNMENT_FIELD_EMPTY, it should be ignored.  */
name|unsigned
name|int
name|default_alignment_max
decl_stmt|;
define|#
directive|define
name|COFF_ALIGNMENT_FIELD_EMPTY
value|((unsigned int) -1)
comment|/* The desired alignment for this section (as a power of two).  */
name|unsigned
name|int
name|alignment_power
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_coff_link_hash_newfunc
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
parameter_list|,
name|struct
name|bfd_hash_table
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|_bfd_coff_link_hash_table_init
argument_list|(
expr|struct
name|coff_link_hash_table
operator|*
argument_list|,
name|bfd
operator|*
argument_list|,
expr|struct
name|bfd_hash_entry
operator|*
call|(
modifier|*
call|)
argument_list|(
expr|struct
name|bfd_hash_entry
operator|*
argument_list|,
expr|struct
name|bfd_hash_table
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
argument_list|,
name|unsigned
name|int
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|_bfd_coff_link_hash_table_create
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|_bfd_coff_internal_syment_name
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|struct
name|internal_syment
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_link_add_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_final_link
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|internal_reloc
modifier|*
name|_bfd_coff_read_internal_relocs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|struct
name|internal_reloc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_generic_relocate_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|struct
name|internal_reloc
modifier|*
parameter_list|,
name|struct
name|internal_syment
modifier|*
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_coff_debug_merge_hash_newfunc
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
parameter_list|,
name|struct
name|bfd_hash_table
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_write_global_sym
parameter_list|(
name|struct
name|coff_link_hash_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_write_task_globals
parameter_list|(
name|struct
name|coff_link_hash_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_link_input_bfd
parameter_list|(
name|struct
name|coff_final_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_coff_reloc_link_order
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|coff_final_link_info
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|struct
name|bfd_link_order
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|coff_get_section_contents_in_window
define|\
value|_bfd_generic_get_section_contents_in_window
end_define

begin_comment
comment|/* Functions in xcofflink.c.  */
end_comment

begin_function_decl
specifier|extern
name|long
name|_bfd_xcoff_get_dynamic_symtab_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|_bfd_xcoff_canonicalize_dynamic_symtab
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|_bfd_xcoff_get_dynamic_reloc_upper_bound
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|_bfd_xcoff_canonicalize_dynamic_reloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|arelent
modifier|*
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|_bfd_xcoff_bfd_link_hash_table_create
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_bfd_xcoff_bfd_link_hash_table_free
parameter_list|(
name|struct
name|bfd_link_hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_bfd_link_add_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_bfd_final_link
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_ppc_xcoff_relocate_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|struct
name|internal_reloc
modifier|*
parameter_list|,
name|struct
name|internal_syment
modifier|*
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in coff-ppc.c.  FIXME: These are called be pe.em in the    linker, and so should start with bfd and be declared in bfd.h.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|ppc_allocate_toc_section
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|ppc_process_before_allocation
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

