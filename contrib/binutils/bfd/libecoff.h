begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD ECOFF object file private structure.    Copyright (C) 1993, 94, 95, 96, 1997 Free Software Foundation, Inc.    Written by Ian Lance Taylor, Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bfdlink.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|ECOFF_H
end_ifndef

begin_include
include|#
directive|include
file|"coff/ecoff.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the backend information kept for ECOFF files.  This    structure is constant for a particular backend.  The first element    is the COFF backend data structure, so that ECOFF targets can use    the generic COFF code.  */
end_comment

begin_define
define|#
directive|define
name|ecoff_backend
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((struct ecoff_backend_data *) (abfd)->xvec->backend_data)
end_define

begin_struct
struct|struct
name|ecoff_backend_data
block|{
comment|/* COFF backend information.  This must be the first field.  */
name|bfd_coff_backend_data
name|coff
decl_stmt|;
comment|/* Supported architecture.  */
name|enum
name|bfd_architecture
name|arch
decl_stmt|;
comment|/* Initial portion of armap string.  */
specifier|const
name|char
modifier|*
name|armap_start
decl_stmt|;
comment|/* The page boundary used to align sections in a demand-paged      executable file.  E.g., 0x1000.  */
name|bfd_vma
name|round
decl_stmt|;
comment|/* True if the .rdata section is part of the text segment, as on the      Alpha.  False if .rdata is part of the data segment, as on the      MIPS.  */
name|boolean
name|rdata_in_text
decl_stmt|;
comment|/* Bitsize of constructor entries.  */
name|unsigned
name|int
name|constructor_bitsize
decl_stmt|;
comment|/* Reloc to use for constructor entries.  */
name|reloc_howto_type
modifier|*
name|constructor_reloc
decl_stmt|;
comment|/* How to swap debugging information.  */
name|struct
name|ecoff_debug_swap
name|debug_swap
decl_stmt|;
comment|/* External reloc size.  */
name|bfd_size_type
name|external_reloc_size
decl_stmt|;
comment|/* Reloc swapping functions.  */
name|void
argument_list|(
argument|*swap_reloc_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|,
expr|struct
name|internal_reloc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*swap_reloc_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
expr|struct
name|internal_reloc
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
comment|/* Backend reloc tweaking.  */
name|void
argument_list|(
argument|*adjust_reloc_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
expr|struct
name|internal_reloc
operator|*
operator|,
name|arelent
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*adjust_reloc_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|arelent
operator|*
operator|,
expr|struct
name|internal_reloc
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Relocate section contents while linking.  */
name|boolean
argument_list|(
argument|*relocate_section
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|output_bfd
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|bfd
operator|*
name|input_bfd
operator|,
name|asection
operator|*
name|input_section
operator|,
name|bfd_byte
operator|*
name|contents
operator|,
name|PTR
name|external_relocs
operator|)
argument_list|)
expr_stmt|;
comment|/* Do final adjustments to filehdr and aouthdr.  */
name|boolean
argument_list|(
argument|*adjust_headers
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|internal_filehdr
operator|*
operator|,
expr|struct
name|internal_aouthdr
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Read an element from an archive at a given file position.  This      is needed because OSF/1 3.2 uses a weird archive format.  */
name|bfd
operator|*
operator|(
operator|*
name|get_elt_at_filepos
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|file_ptr
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This is the target specific information kept for ECOFF files.  */
end_comment

begin_define
define|#
directive|define
name|ecoff_data
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->tdata.ecoff_obj_data)
end_define

begin_typedef
typedef|typedef
struct|struct
name|ecoff_tdata
block|{
comment|/* The reloc file position, set by      ecoff_compute_section_file_positions.  */
name|file_ptr
name|reloc_filepos
decl_stmt|;
comment|/* The symbol table file position, set by _bfd_ecoff_mkobject_hook.  */
name|file_ptr
name|sym_filepos
decl_stmt|;
comment|/* The start and end of the text segment.  Only valid for an      existing file, not for one we are creating.  */
name|unsigned
name|long
name|text_start
decl_stmt|;
name|unsigned
name|long
name|text_end
decl_stmt|;
comment|/* The cached gp value.  This is used when relocating.  */
name|bfd_vma
name|gp
decl_stmt|;
comment|/* The maximum size of objects to optimize using gp.  This is      typically set by the -G option to the compiler, assembler or      linker.  */
name|unsigned
name|int
name|gp_size
decl_stmt|;
comment|/* The register masks.  When linking, all the masks found in the      input files are combined into the masks of the output file.      These are not all used for all targets, but that's OK, because      the relevant ones are the only ones swapped in and out.  */
name|unsigned
name|long
name|gprmask
decl_stmt|;
name|unsigned
name|long
name|fprmask
decl_stmt|;
name|unsigned
name|long
name|cprmask
index|[
literal|4
index|]
decl_stmt|;
comment|/* The ECOFF symbolic debugging information.  */
name|struct
name|ecoff_debug_info
name|debug_info
decl_stmt|;
comment|/* The unswapped ECOFF symbolic information.  */
name|PTR
name|raw_syments
decl_stmt|;
comment|/* The canonical BFD symbols.  */
name|struct
name|ecoff_symbol_struct
modifier|*
name|canonical_symbols
decl_stmt|;
comment|/* A mapping from external symbol numbers to entries in the linker      hash table, used when linking.  */
name|struct
name|ecoff_link_hash_entry
modifier|*
modifier|*
name|sym_hashes
decl_stmt|;
comment|/* A mapping from reloc symbol indices to sections, used when      linking.  */
name|asection
modifier|*
modifier|*
name|symndx_to_section
decl_stmt|;
comment|/* True if this BFD was written by the backend linker.  */
name|boolean
name|linker
decl_stmt|;
comment|/* True if a warning that multiple global pointer values are      needed in the output binary was issued already.  */
name|boolean
name|issued_multiple_gp_warning
decl_stmt|;
comment|/* Used by find_nearest_line entry point.  The structure could be      included directly in this one, but there's no point to wasting      the memory just for the infrequently called find_nearest_line.  */
name|struct
name|ecoff_find_line
modifier|*
name|find_line_info
decl_stmt|;
comment|/* Whether the .rdata section is in the text segment for this      particular ECOFF file.  This is not valid until      ecoff_compute_section_file_positions is called.  */
name|boolean
name|rdata_in_text
decl_stmt|;
block|}
name|ecoff_data_type
typedef|;
end_typedef

begin_comment
comment|/* Each canonical asymbol really looks like this.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ecoff_symbol_struct
block|{
comment|/* The actual symbol which the rest of BFD works with */
name|asymbol
name|symbol
decl_stmt|;
comment|/* The fdr for this symbol.  */
name|FDR
modifier|*
name|fdr
decl_stmt|;
comment|/* true if this is a local symbol rather than an external one.  */
name|boolean
name|local
decl_stmt|;
comment|/* A pointer to the unswapped hidden information for this symbol.      This is either a struct sym_ext or a struct ext_ext, depending on      the value of the local field above.  */
name|PTR
name|native
decl_stmt|;
block|}
name|ecoff_symbol_type
typedef|;
end_typedef

begin_comment
comment|/* We take the address of the first element of a asymbol to ensure that the    macro is only ever applied to an asymbol.  */
end_comment

begin_define
define|#
directive|define
name|ecoffsymbol
parameter_list|(
name|asymbol
parameter_list|)
value|((ecoff_symbol_type *) (&((asymbol)->the_bfd)))
end_define

begin_comment
comment|/* We need to save the index of an external symbol when we write it    out so that can set the symbol index correctly when we write out    the relocs.  */
end_comment

begin_define
define|#
directive|define
name|ecoff_get_sym_index
parameter_list|(
name|symbol
parameter_list|)
value|((symbol)->udata.i)
end_define

begin_define
define|#
directive|define
name|ecoff_set_sym_index
parameter_list|(
name|symbol
parameter_list|,
name|idx
parameter_list|)
value|((symbol)->udata.i = (idx))
end_define

begin_comment
comment|/* When generating MIPS embedded PIC code, the linker relaxes the code    to turn PC relative branches into longer code sequences when the PC    relative branch is out of range.  This involves reading the relocs    in bfd_relax_section as well as in bfd_final_link, and requires the    code to keep track of which relocs have been expanded.  A pointer    to this structure is put in the used_by_bfd pointer of a section to    keep track of this information.  The user_by_bfd pointer will be    NULL if the information was not needed.  */
end_comment

begin_struct
struct|struct
name|ecoff_section_tdata
block|{
comment|/* The unswapped relocs for this section.  These are stored in      memory so the input file does not have to be read twice.  */
name|PTR
name|external_relocs
decl_stmt|;
comment|/* The contents of the section.  These bytes may or may not be saved      in memory, but if it is this is a pointer to them.  */
name|bfd_byte
modifier|*
name|contents
decl_stmt|;
comment|/* Offset adjustments for PC relative branches.  A number other than      1 is an addend for a PC relative branch, or a switch table entry      which is the difference of two .text locations; this addend      arises because the branch or difference crosses one or more      branches which were expanded into a larger code sequence.  A 1      means that this branch was itself expanded into a larger code      sequence.  1 is not a possible offset, since all offsets must be      multiples of the instruction size, which is 4; also, the only      relocs with non-zero offsets will be PC relative branches or      switch table entries within the same object file.  If this field      is NULL, no branches were expanded and no offsets are required.      Otherwise there are as many entries as there are relocs in the      section, and the entry for any reloc that is not PC relative is      zero.  */
name|long
modifier|*
name|offsets
decl_stmt|;
comment|/* When producing an executable (i.e., final, non-relocatable link)      on the Alpha, we may need to use multiple global pointer values      to span the entire .lita section.  In essence, we allow each      input .lita section to have its own gp value.  To support this,      we need to keep track of the gp values that we picked for each      input .lita section . */
name|bfd_vma
name|gp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* An accessor macro for the ecoff_section_tdata structure.  */
end_comment

begin_define
define|#
directive|define
name|ecoff_section_data
parameter_list|(
name|abfd
parameter_list|,
name|sec
parameter_list|)
define|\
value|((struct ecoff_section_tdata *) (sec)->used_by_bfd)
end_define

begin_comment
comment|/* ECOFF linker hash table entries.  */
end_comment

begin_struct
struct|struct
name|ecoff_link_hash_entry
block|{
name|struct
name|bfd_link_hash_entry
name|root
decl_stmt|;
comment|/* Symbol index in output file.  */
name|long
name|indx
decl_stmt|;
comment|/* BFD that ext field value came from.  */
name|bfd
modifier|*
name|abfd
decl_stmt|;
comment|/* ECOFF external symbol information.  */
name|EXTR
name|esym
decl_stmt|;
comment|/* Nonzero if this symbol has been written out.  */
name|char
name|written
decl_stmt|;
comment|/* Nonzero if this symbol was referred to as small undefined.  */
name|char
name|small
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ECOFF linker hash table.  */
end_comment

begin_struct
struct|struct
name|ecoff_link_hash_table
block|{
name|struct
name|bfd_link_hash_table
name|root
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Make an ECOFF object.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_mkobject
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Read in the ECOFF symbolic debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_slurp_symbolic_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|ecoff_debug_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic ECOFF BFD backend vectors.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_write_object_contents
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|_bfd_ecoff_archive_p
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_close_and_cleanup
value|_bfd_generic_close_and_cleanup
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_free_cached_info
value|_bfd_generic_bfd_free_cached_info
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_new_section_hook
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_get_section_contents
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
name|location
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_link_split_section
value|_bfd_generic_link_split_section
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_bfd_copy_private_bfd_data
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_copy_private_section_data
define|\
value|_bfd_generic_bfd_copy_private_section_data
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_copy_private_symbol_data
define|\
value|_bfd_generic_bfd_copy_private_symbol_data
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_print_private_bfd_data
define|\
value|_bfd_generic_bfd_print_private_bfd_data
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_merge_private_bfd_data
define|\
value|_bfd_generic_bfd_merge_private_bfd_data
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_set_private_flags
value|_bfd_generic_bfd_set_private_flags
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_slurp_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_slurp_extended_name_table
value|_bfd_slurp_extended_name_table
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_construct_extended_name_table
define|\
value|_bfd_archive_bsd_construct_extended_name_table
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_truncate_arname
value|bfd_dont_truncate_arname
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_write_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|unsigned
name|int
operator|,
expr|struct
name|orl
operator|*
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_read_ar_hdr
value|_bfd_generic_read_ar_hdr
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_openr_next_archived_file
define|\
value|bfd_generic_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_get_elt_at_index
value|_bfd_generic_get_elt_at_index
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_generic_stat_arch_elt
value|bfd_generic_stat_arch_elt
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_update_armap_timestamp
value|bfd_true
end_define

begin_decl_stmt
specifier|extern
name|long
name|_bfd_ecoff_get_symtab_upper_bound
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|_bfd_ecoff_get_symtab
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|asymbol
operator|*
operator|*
name|alocation
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|asymbol
modifier|*
name|_bfd_ecoff_make_empty_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_print_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
name|filep
operator|,
name|asymbol
operator|*
operator|,
name|bfd_print_symbol_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_get_symbol_info
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|,
name|symbol_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_bfd_is_local_label_name
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_get_lineno
value|_bfd_nosymbols_get_lineno
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_find_nearest_line
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|bfd_vma
name|offset
operator|,
specifier|const
name|char
operator|*
operator|*
name|filename_ptr
operator|,
specifier|const
name|char
operator|*
operator|*
name|fnname_ptr
operator|,
name|unsigned
name|int
operator|*
name|retline_ptr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_bfd_make_debug_symbol
value|_bfd_nosymbols_bfd_make_debug_symbol
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_read_minisymbols
value|_bfd_generic_read_minisymbols
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_minisymbol_to_symbol
value|_bfd_generic_minisymbol_to_symbol
end_define

begin_define
define|#
directive|define
name|_bfd_ecoff_get_reloc_upper_bound
value|coff_get_reloc_upper_bound
end_define

begin_decl_stmt
specifier|extern
name|long
name|_bfd_ecoff_canonicalize_reloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|arelent
operator|*
operator|*
operator|,
name|asymbol
operator|*
operator|*
name|symbols
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ecoff_bfd_reloc_type_lookup defined by backend. */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_set_arch_mach
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|enum
name|bfd_architecture
operator|,
name|unsigned
name|long
name|machine
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_set_section_contents
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
name|location
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_bfd_ecoff_sizeof_headers
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|boolean
name|reloc
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ecoff_bfd_get_relocated_section_contents defined by backend.  */
end_comment

begin_comment
comment|/* ecoff_bfd_relax_section defined by backend.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|_bfd_ecoff_bfd_link_hash_table_create
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_bfd_link_add_symbols
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_bfd_final_link
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hook functions for the generic COFF section reading code.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|_bfd_ecoff_mkobject_hook
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
name|filehdr
operator|,
name|PTR
name|aouthdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_bfd_ecoff_set_alignment_hook
define|\
value|((void (*) PARAMS ((bfd *, asection *, PTR))) bfd_void)
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_set_arch_mach_hook
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|PTR
name|filehdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|flagword
name|_bfd_ecoff_styp_to_sec_flags
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
name|PTR
name|hdr
operator|,
specifier|const
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_slurp_symbol_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ECOFF auxiliary information swapping routines.  These are the same    for all ECOFF targets, so they are defined in ecofflink.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_swap_tir_in
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|tir_ext
operator|*
operator|,
name|TIR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_swap_tir_out
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|TIR
operator|*
operator|,
expr|struct
name|tir_ext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_swap_rndx_in
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
expr|struct
name|rndx_ext
operator|*
operator|,
name|RNDXR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_bfd_ecoff_swap_rndx_out
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|RNDXR
operator|*
operator|,
expr|struct
name|rndx_ext
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

