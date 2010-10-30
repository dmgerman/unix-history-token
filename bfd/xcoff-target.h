begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common definitions for backends based on IBM RS/6000 "XCOFF64" files.    Copyright 2000, 2001, 2002, 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by Cygnus Support.     This file is part of BFD, the Binary File Descriptor library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Internalcoff.h and coffcode.h modify themselves based on this flag.  */
end_comment

begin_define
define|#
directive|define
name|RS6000COFF_C
value|1
end_define

begin_define
define|#
directive|define
name|SELECT_RELOC
parameter_list|(
name|internal
parameter_list|,
name|howto
parameter_list|)
define|\
value|{									\     internal.r_type = howto->type;					\     internal.r_size =							\       ((howto->complain_on_overflow == complain_overflow_signed		\ 	? 0x80								\ 	: 0)								\        | (howto->bitsize - 1));						\   }
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|COFF_DEFAULT_SECTION_ALIGNMENT_POWER
value|3
end_define

begin_define
define|#
directive|define
name|COFF_LONG_FILENAMES
end_define

begin_define
define|#
directive|define
name|NO_COFF_SYMBOLS
end_define

begin_define
define|#
directive|define
name|RTYPE2HOWTO
parameter_list|(
name|cache_ptr
parameter_list|,
name|dst
parameter_list|)
value|_bfd_xcoff_rtype2howto (cache_ptr, dst)
end_define

begin_define
define|#
directive|define
name|coff_mkobject
value|_bfd_xcoff_mkobject
end_define

begin_define
define|#
directive|define
name|coff_bfd_copy_private_bfd_data
value|_bfd_xcoff_copy_private_bfd_data
end_define

begin_define
define|#
directive|define
name|coff_bfd_is_local_label_name
value|_bfd_xcoff_is_local_label_name
end_define

begin_define
define|#
directive|define
name|coff_bfd_is_target_special_symbol
value|((bfd_boolean (*) (bfd *, asymbol *)) bfd_false)
end_define

begin_define
define|#
directive|define
name|coff_bfd_reloc_type_lookup
value|_bfd_xcoff_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|coff_relocate_section
value|_bfd_ppc_xcoff_relocate_section
end_define

begin_define
define|#
directive|define
name|coff_core_file_failing_command
value|_bfd_nocore_core_file_failing_command
end_define

begin_define
define|#
directive|define
name|coff_core_file_failing_signal
value|_bfd_nocore_core_file_failing_signal
end_define

begin_define
define|#
directive|define
name|coff_core_file_matches_executable_p
value|_bfd_nocore_core_file_matches_executable_p
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_get_relocated_section_contents
value|coff_bfd_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_relax_section
value|coff_bfd_relax_section
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_gc_sections
value|coff_bfd_gc_sections
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_merge_sections
value|coff_bfd_merge_sections
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_discard_group
value|bfd_generic_discard_group
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_section_already_linked
value|_bfd_generic_section_already_linked
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_bfd_link_split_section
value|coff_bfd_link_split_section
end_define

begin_define
define|#
directive|define
name|CORE_FILE_P
value|_bfd_dummy_target
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AIX_CORE
end_ifdef

begin_undef
undef|#
directive|undef
name|CORE_FILE_P
end_undef

begin_define
define|#
directive|define
name|CORE_FILE_P
value|rs6000coff_core_p
end_define

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|rs6000coff_core_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|rs6000coff_core_file_matches_executable_p
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_matches_executable_p
end_undef

begin_define
define|#
directive|define
name|coff_core_file_matches_executable_p
define|\
value|rs6000coff_core_file_matches_executable_p
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|rs6000coff_core_file_failing_command
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_failing_command
end_undef

begin_define
define|#
directive|define
name|coff_core_file_failing_command
value|rs6000coff_core_file_failing_command
end_define

begin_function_decl
specifier|extern
name|int
name|rs6000coff_core_file_failing_signal
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_failing_signal
end_undef

begin_define
define|#
directive|define
name|coff_core_file_failing_signal
value|rs6000coff_core_file_failing_signal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX_CORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LYNX_CORE
end_ifdef

begin_undef
undef|#
directive|undef
name|CORE_FILE_P
end_undef

begin_define
define|#
directive|define
name|CORE_FILE_P
value|lynx_core_file_p
end_define

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|lynx_core_file_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|lynx_core_file_matches_executable_p
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_matches_executable_p
end_undef

begin_define
define|#
directive|define
name|coff_core_file_matches_executable_p
value|lynx_core_file_matches_executable_p
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|lynx_core_file_failing_command
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_failing_command
end_undef

begin_define
define|#
directive|define
name|coff_core_file_failing_command
value|lynx_core_file_failing_command
end_define

begin_function_decl
specifier|extern
name|int
name|lynx_core_file_failing_signal
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|coff_core_file_failing_signal
end_undef

begin_define
define|#
directive|define
name|coff_core_file_failing_signal
value|lynx_core_file_failing_signal
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LYNX_CORE */
end_comment

begin_comment
comment|/* XCOFF archives do not have anything which corresponds to an    extended name table.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_xcoff_slurp_extended_name_table
value|bfd_false
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_construct_extended_name_table
define|\
value|((bfd_boolean (*) (bfd *, char **, bfd_size_type *, const char **)) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_xcoff_truncate_arname
value|bfd_dont_truncate_arname
end_define

begin_comment
comment|/* We can use the standard get_elt_at_index routine.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_xcoff_get_elt_at_index
value|_bfd_generic_get_elt_at_index
end_define

begin_comment
comment|/* XCOFF archives do not have a timestamp.  */
end_comment

begin_define
define|#
directive|define
name|_bfd_xcoff_update_armap_timestamp
value|bfd_true
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_mkobject
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_copy_private_bfd_data
parameter_list|(
name|bfd
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
name|_bfd_xcoff_is_local_label_name
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
name|void
name|_bfd_xcoff_rtype2howto
parameter_list|(
name|arelent
modifier|*
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
name|_bfd_xcoff_slurp_armap
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|_bfd_xcoff_read_ar_hdr
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd
modifier|*
name|_bfd_xcoff_openr_next_archived_file
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_xcoff_generic_stat_arch_elt
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_write_armap
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|struct
name|orl
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_xcoff_write_archive_contents
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_xcoff_sizeof_headers
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
name|void
name|_bfd_xcoff_swap_sym_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|_bfd_xcoff_swap_sym_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_bfd_xcoff_swap_aux_in
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|_bfd_xcoff_swap_aux_out
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|reloc_howto_type
modifier|*
name|_bfd_xcoff_reloc_type_lookup
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_reloc_code_real_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|_bfd_xcoff_archive_p
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|coff_SWAP_sym_in
end_ifndef

begin_define
define|#
directive|define
name|coff_SWAP_sym_in
value|_bfd_xcoff_swap_sym_in
end_define

begin_define
define|#
directive|define
name|coff_SWAP_sym_out
value|_bfd_xcoff_swap_sym_out
end_define

begin_define
define|#
directive|define
name|coff_SWAP_aux_in
value|_bfd_xcoff_swap_aux_in
end_define

begin_define
define|#
directive|define
name|coff_SWAP_aux_out
value|_bfd_xcoff_swap_aux_out
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"coffcode.h"
end_include

begin_comment
comment|/* The transfer vector that leads the outside world to all of the above.  */
end_comment

begin_decl_stmt
specifier|const
name|bfd_target
name|TARGET_SYM
init|=
block|{
name|TARGET_NAME
block|,
name|bfd_target_xcoff_flavour
block|,
name|BFD_ENDIAN_BIG
block|,
comment|/* Data byte order is big.  */
name|BFD_ENDIAN_BIG
block|,
comment|/* Header byte order is big.  */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
comment|/* Object flags.  */
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|DYNAMIC
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|WP_TEXT
operator|)
block|,
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator|)
block|,
comment|/* Section flags.  */
literal|0
block|,
comment|/* Leading char.  */
literal|'/'
block|,
comment|/* AR_pad_char.  */
literal|15
block|,
comment|/* AR_max_namelen??? FIXME.  */
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* Data.  */
name|bfd_getb64
block|,
name|bfd_getb_signed_64
block|,
name|bfd_putb64
block|,
name|bfd_getb32
block|,
name|bfd_getb_signed_32
block|,
name|bfd_putb32
block|,
name|bfd_getb16
block|,
name|bfd_getb_signed_16
block|,
name|bfd_putb16
block|,
comment|/* Headers.  */
block|{
name|_bfd_dummy_target
block|,
name|coff_object_p
block|,
comment|/* bfd_check_format.  */
name|_bfd_xcoff_archive_p
block|,
name|CORE_FILE_P
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_mkobject
block|,
comment|/* bfd_set_format.  */
name|_bfd_generic_mkarchive
block|,
name|bfd_false
block|}
block|,
block|{
name|bfd_false
block|,
name|coff_write_object_contents
block|,
comment|/* bfd_write_contents.  */
name|_bfd_xcoff_write_archive_contents
block|,
name|bfd_false
block|}
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_xcoff
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|_bfd_xcoff
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|_bfd_xcoff
argument_list|)
block|,
name|NULL
block|,
name|COFF_SWAP_TABLE
block|}
decl_stmt|;
end_decl_stmt

end_unit

