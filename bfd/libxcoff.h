begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD XCOFF object file private structure.    Copyright 2001, 2002, 2005 Free Software Foundation, Inc.    Written by Tom Rix, Redhat.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LIBXCOFF_H
end_ifndef

begin_define
define|#
directive|define
name|LIBXCOFF_H
end_define

begin_comment
comment|/* This is the backend information kept for XCOFF files.  This    structure is constant for a particular backend.  The first element    is the COFF backend data structure, so that XCOFF targets can use    the generic COFF code.  */
end_comment

begin_struct
struct|struct
name|xcoff_backend_data_rec
block|{
comment|/* COFF backend information.  */
name|bfd_coff_backend_data
name|coff
decl_stmt|;
comment|/* Magic number.  */
name|unsigned
name|short
name|_xcoff_magic_number
decl_stmt|;
comment|/* Architecture and machine for coff_set_arch_mach_hook.  */
name|enum
name|bfd_architecture
name|_xcoff_architecture
decl_stmt|;
name|long
name|_xcoff_machine
decl_stmt|;
comment|/* Function pointers to xcoff specific swap routines.  */
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldhdr_in
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|struct
name|internal_ldhdr
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldhdr_out
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|struct
name|internal_ldhdr
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldsym_in
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|struct
name|internal_ldsym
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldsym_out
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|struct
name|internal_ldsym
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldrel_in
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|struct
name|internal_ldrel
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|_xcoff_swap_ldrel_out
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|struct
name|internal_ldrel
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
comment|/* Size of the external struct.  */
name|unsigned
name|int
name|_xcoff_ldhdrsz
decl_stmt|;
name|unsigned
name|int
name|_xcoff_ldsymsz
decl_stmt|;
name|unsigned
name|int
name|_xcoff_ldrelsz
decl_stmt|;
comment|/* Size an entry in a descriptor section.  */
name|unsigned
name|int
name|_xcoff_function_descriptor_size
decl_stmt|;
comment|/* Size of the small aout file header.  */
name|unsigned
name|int
name|_xcoff_small_aout_header_size
decl_stmt|;
comment|/* Loader version      1 : XCOFF32      2 : XCOFF64.  */
name|unsigned
name|long
name|_xcoff_ldhdr_version
decl_stmt|;
name|bfd_boolean
function_decl|(
modifier|*
name|_xcoff_put_symbol_name
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_strtab_hash
modifier|*
parameter_list|,
name|struct
name|internal_syment
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|bfd_boolean
function_decl|(
modifier|*
name|_xcoff_put_ldsymbol_name
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|xcoff_loader_info
modifier|*
parameter_list|,
name|struct
name|internal_ldsym
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|reloc_howto_type
modifier|*
name|_xcoff_dynamic_reloc
decl_stmt|;
name|asection
modifier|*
function_decl|(
modifier|*
name|_xcoff_create_csect_from_smclas
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|union
name|internal_auxent
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Line number and relocation overflow.      XCOFF32 overflows to another section when the line number or the       relocation count exceeds 0xffff.  XCOFF64 does not overflow.  */
name|bfd_boolean
function_decl|(
modifier|*
name|_xcoff_is_lineno_count_overflow
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
name|bfd_boolean
function_decl|(
modifier|*
name|_xcoff_is_reloc_count_overflow
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
comment|/* Loader section symbol and relocation table offset      XCOFF32 is after the .loader header      XCOFF64 is offset in .loader header.  */
name|bfd_vma
function_decl|(
modifier|*
name|_xcoff_loader_symbol_offset
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|internal_ldhdr
modifier|*
parameter_list|)
function_decl|;
name|bfd_vma
function_decl|(
modifier|*
name|_xcoff_loader_reloc_offset
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|internal_ldhdr
modifier|*
parameter_list|)
function_decl|;
comment|/* Global linkage.  The first word of global linkage code must be be       modified by filling in the correct TOC offset.  */
name|unsigned
name|long
modifier|*
name|_xcoff_glink_code
decl_stmt|;
comment|/* Size of the global link code in bytes of the xcoff_glink_code table.  */
name|unsigned
name|long
name|_xcoff_glink_size
decl_stmt|;
comment|/* rtinit.  */
name|unsigned
name|int
name|_xcoff_rtinit_size
decl_stmt|;
name|bfd_boolean
function_decl|(
modifier|*
name|_xcoff_generate_rtinit
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* Look up an entry in an XCOFF link hash table.  */
end_comment

begin_define
define|#
directive|define
name|xcoff_link_hash_lookup
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
value|((struct xcoff_link_hash_entry *) \    bfd_link_hash_lookup (&(table)->root, (string), (create), (copy),\ 			 (follow)))
end_define

begin_comment
comment|/* Traverse an XCOFF link hash table.  */
end_comment

begin_define
define|#
directive|define
name|xcoff_link_hash_traverse
parameter_list|(
name|table
parameter_list|,
name|func
parameter_list|,
name|info
parameter_list|)
define|\
value|(bfd_link_hash_traverse						\    (&(table)->root,							\     (bfd_boolean (*) (struct bfd_link_hash_entry *, void *)) (func),	\     (info)))
end_define

begin_comment
comment|/* Get the XCOFF link hash table from the info structure.  This is    just a cast.  */
end_comment

begin_define
define|#
directive|define
name|xcoff_hash_table
parameter_list|(
name|p
parameter_list|)
value|((struct xcoff_link_hash_table *) ((p)->hash))
end_define

begin_define
define|#
directive|define
name|xcoff_backend
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((struct xcoff_backend_data_rec *) (abfd)->xvec->backend_data)
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_magic_number
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_magic_number))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_architecture
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_architecture))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_machine
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_machine))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldhdr_in
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldhdr_in) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldhdr_out
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldhdr_out) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldsym_in
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldsym_in) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldsym_out
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldsym_out) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldrel_in
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldrel_in) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_swap_ldrel_out
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_swap_ldrel_out) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldhdrsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_ldhdrsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldsymsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_ldsymsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldrelsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_ldrelsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_function_descriptor_size
parameter_list|(
name|a
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_function_descriptor_size))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_small_aout_header_size
parameter_list|(
name|a
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_small_aout_header_size))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldhdr_version
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_ldhdr_version))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_put_symbol_name
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_put_symbol_name) ((a), (b), (c), (d)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_put_ldsymbol_name
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_put_ldsymbol_name) ((a), (b), (c), (d)))
end_define

begin_comment
comment|/* Get the XCOFF hash table entries for a BFD.  */
end_comment

begin_define
define|#
directive|define
name|obj_xcoff_sym_hashes
parameter_list|(
name|bfd
parameter_list|)
define|\
value|((struct xcoff_link_hash_entry **) obj_coff_sym_hashes (bfd))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_dynamic_reloc_howto
parameter_list|(
name|a
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_dynamic_reloc))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_create_csect_from_smclas
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_create_csect_from_smclas((a), (b), (c))))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_is_lineno_count_overflow
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_is_lineno_count_overflow((a), (b))))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_is_reloc_count_overflow
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_is_reloc_count_overflow((a), (b))))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_loader_symbol_offset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_loader_symbol_offset((a), (b))))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_loader_reloc_offset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
define|\
value|((xcoff_backend (a)->_xcoff_loader_reloc_offset((a), (b))))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_glink_code
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((xcoff_backend (a)->_xcoff_glink_code[(b)]))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_glink_code_size
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_glink_size))
end_define

begin_comment
comment|/* Check for the magic number U803XTOCMAGIC or U64_TOCMAGIC for 64 bit     targets.  */
end_comment

begin_define
define|#
directive|define
name|bfd_xcoff_is_xcoff64
parameter_list|(
name|a
parameter_list|)
define|\
value|(   (0x01EF == (bfd_xcoff_magic_number (a))) \    || (0x01F7 == (bfd_xcoff_magic_number (a))))
end_define

begin_comment
comment|/* Check for the magic number U802TOMAGIC for 32 bit targets.  */
end_comment

begin_define
define|#
directive|define
name|bfd_xcoff_is_xcoff32
parameter_list|(
name|a
parameter_list|)
value|(0x01DF == (bfd_xcoff_magic_number (a)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_rtinit_size
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend (a)->_xcoff_rtinit_size))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_generate_rtinit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((xcoff_backend (a)->_xcoff_generate_rtinit ((a), (b), (c), (d))))
end_define

begin_comment
comment|/* Accessor macros for tdata.  */
end_comment

begin_define
define|#
directive|define
name|bfd_xcoff_text_align_power
parameter_list|(
name|a
parameter_list|)
value|((xcoff_data (a)->text_align_power))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_data_align_power
parameter_list|(
name|a
parameter_list|)
value|((xcoff_data (a)->data_align_power))
end_define

begin_comment
comment|/* xcoff*_ppc_relocate_section macros  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_MAX_CALCULATE_RELOCATION
value|(0x1c)
end_define

begin_define
define|#
directive|define
name|XCOFF_MAX_COMPLAIN_OVERFLOW
value|(4)
end_define

begin_comment
comment|/* N_ONES produces N one bits, without overflowing machine arithmetic.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|N_ONES
end_ifdef

begin_undef
undef|#
directive|undef
name|N_ONES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|N_ONES
parameter_list|(
name|n
parameter_list|)
value|(((((bfd_vma) 1<< ((n) - 1)) - 1)<< 1) | 1)
end_define

begin_define
define|#
directive|define
name|XCOFF_RELOC_FUNCTION_ARGS
define|\
value|bfd *, asection *, bfd *, struct internal_reloc *, \   struct internal_syment *, struct reloc_howto_struct *, bfd_vma, bfd_vma, \   bfd_vma *relocation, bfd_byte *contents
end_define

begin_define
define|#
directive|define
name|XCOFF_COMPLAIN_FUNCTION_ARGS
define|\
value|bfd *, bfd_vma, bfd_vma, struct reloc_howto_struct *howto
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
function_decl|(
modifier|*
name|xcoff_calculate_relocation
index|[
name|XCOFF_MAX_CALCULATE_RELOCATION
index|]
function_decl|)
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
function_decl|(
modifier|*
name|xcoff_complain_overflow
index|[
name|XCOFF_MAX_COMPLAIN_OVERFLOW
index|]
function_decl|)
parameter_list|(
name|XCOFF_COMPLAIN_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Relocation functions */
end_comment

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_noop
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_fail
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_pos
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_neg
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_rel
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_toc
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_ba
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|xcoff_reloc_type_crel
parameter_list|(
name|XCOFF_RELOC_FUNCTION_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBXCOFF_H */
end_comment

end_unit

