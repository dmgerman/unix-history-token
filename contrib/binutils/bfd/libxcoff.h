begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* BFD XCOFF object file private structure.    Copyright 2001, 2002 Free Software Foundation, Inc.    Written by Tom Rix, Redhat.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
argument_list|(
argument|* _xcoff_swap_ldhdr_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|PTR
operator|,
expr|struct
name|internal_ldhdr
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* _xcoff_swap_ldhdr_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
expr|struct
name|internal_ldhdr
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* _xcoff_swap_ldsym_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|PTR
operator|,
expr|struct
name|internal_ldsym
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* _xcoff_swap_ldsym_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
expr|struct
name|internal_ldsym
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* _xcoff_swap_ldrel_in
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|PTR
operator|,
expr|struct
name|internal_ldrel
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|* _xcoff_swap_ldrel_out
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
expr|struct
name|internal_ldrel
operator|*
operator|,
name|PTR
operator|)
argument_list|)
expr_stmt|;
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
argument_list|(
argument|* _xcoff_put_symbol_name
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_strtab_hash
operator|*
operator|,
expr|struct
name|internal_syment
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_boolean
argument_list|(
argument|* _xcoff_put_ldsymbol_name
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|xcoff_loader_info
operator|*
operator|,
expr|struct
name|internal_ldsym
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
name|reloc_howto_type
modifier|*
name|_xcoff_dynamic_reloc
decl_stmt|;
name|asection
operator|*
operator|(
operator|*
name|_xcoff_create_csect_from_smclas
operator|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|union
name|internal_auxent
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Line number and relocation overflow.      XCOFF32 overflows to another section when the line number or the       relocation count exceeds 0xffff.  XCOFF64 does not overflow.  */
name|bfd_boolean
argument_list|(
argument|*_xcoff_is_lineno_count_overflow
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
name|bfd_boolean
argument_list|(
argument|*_xcoff_is_reloc_count_overflow
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
expr_stmt|;
comment|/* Loader section symbol and relocation table offset      XCOFF32 is after the .loader header      XCOFF64 is offset in .loader header.  */
name|bfd_vma
argument_list|(
argument|*_xcoff_loader_symbol_offset
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|internal_ldhdr
operator|*
operator|)
argument_list|)
expr_stmt|;
name|bfd_vma
argument_list|(
argument|*_xcoff_loader_reloc_offset
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|internal_ldhdr
operator|*
operator|)
argument_list|)
expr_stmt|;
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
argument_list|(
argument|*_xcoff_generate_rtinit
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|bfd_boolean
operator|)
argument_list|)
expr_stmt|;
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
value|(bfd_link_hash_traverse						\    (&(table)->root,							\     (bfd_boolean (*) PARAMS ((struct bfd_link_hash_entry *, PTR))) (func),	\     (info)))
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
value|((xcoff_backend(a)->_xcoff_magic_number))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_architecture
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_architecture))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_machine
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_machine))
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
value|((xcoff_backend(a)->_xcoff_swap_ldhdr_in) ((a), (b), (c)))
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
value|((xcoff_backend(a)->_xcoff_swap_ldhdr_out) ((a), (b), (c)))
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
value|((xcoff_backend(a)->_xcoff_swap_ldsym_in) ((a), (b), (c)))
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
value|((xcoff_backend(a)->_xcoff_swap_ldsym_out) ((a), (b), (c)))
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
value|((xcoff_backend(a)->_xcoff_swap_ldrel_in) ((a), (b), (c)))
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
value|((xcoff_backend(a)->_xcoff_swap_ldrel_out) ((a), (b), (c)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldhdrsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_ldhdrsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldsymsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_ldsymsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldrelsz
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_ldrelsz))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_function_descriptor_size
parameter_list|(
name|a
parameter_list|)
define|\
value|((xcoff_backend(a)->_xcoff_function_descriptor_size))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_small_aout_header_size
parameter_list|(
name|a
parameter_list|)
define|\
value|((xcoff_backend(a)->_xcoff_small_aout_header_size))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_ldhdr_version
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_ldhdr_version))
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
value|((xcoff_backend(a)->_xcoff_put_symbol_name) ((a), (b), (c), (d)))
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
value|((xcoff_backend(a)->_xcoff_put_ldsymbol_name) ((a), (b), (c), (d)))
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
value|((xcoff_backend(a)->_xcoff_dynamic_reloc))
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
value|((xcoff_backend(a)->_xcoff_create_csect_from_smclas((a), (b), (c))))
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
value|((xcoff_backend(a)->_xcoff_is_lineno_count_overflow((a), (b))))
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
value|((xcoff_backend(a)->_xcoff_is_reloc_count_overflow((a), (b))))
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
value|((xcoff_backend(a)->_xcoff_loader_symbol_offset((a), (b))))
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
value|((xcoff_backend(a)->_xcoff_loader_reloc_offset((a), (b))))
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
value|((xcoff_backend(a)->_xcoff_glink_code[(b)]))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_glink_code_size
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_glink_size))
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
value|(   (0x01EF == (bfd_xcoff_magic_number(a))) \    || (0x01F7 == (bfd_xcoff_magic_number(a))))
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
value|(0x01DF == (bfd_xcoff_magic_number(a)))
end_define

begin_define
define|#
directive|define
name|bfd_xcoff_rtinit_size
parameter_list|(
name|a
parameter_list|)
value|((xcoff_backend(a)->_xcoff_rtinit_size))
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
value|((xcoff_backend(a)->_xcoff_generate_rtinit ((a), (b), (c), (d))))
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

begin_extern
extern|extern bfd_boolean (*xcoff_calculate_relocation[XCOFF_MAX_CALCULATE_RELOCATION]
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern bfd_boolean (*xcoff_complain_overflow[XCOFF_MAX_COMPLAIN_OVERFLOW]
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|XCOFF_COMPLAIN_FUNCTION_ARGS
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Relocation functions */
end_comment

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_noop
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_fail
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_pos
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_neg
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_rel
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_toc
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_ba
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd_boolean
name|xcoff_reloc_type_crel
name|PARAMS
argument_list|(
operator|(
name|XCOFF_RELOC_FUNCTION_ARGS
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBXCOFF_H */
end_comment

end_unit

