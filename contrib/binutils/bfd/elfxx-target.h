begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for NN-bit ELF    Copyright 1993, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This structure contains everything that BFD knows about a target.    It includes things like its byte order, name, what routines to call    to do various operations, etc.  Every BFD points to a target structure    with its "xvec" member.     There are two such structures here:  one for big-endian machines and    one for little-endian machines.   */
end_comment

begin_define
define|#
directive|define
name|bfd_elfNN_close_and_cleanup
value|_bfd_elf_close_and_cleanup
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_free_cached_info
value|_bfd_generic_bfd_free_cached_info
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_get_section_contents
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_get_section_contents
value|_bfd_generic_get_section_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_canonicalize_dynamic_symtab
value|_bfd_elf_canonicalize_dynamic_symtab
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_canonicalize_reloc
value|_bfd_elf_canonicalize_reloc
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_find_nearest_line
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_find_nearest_line
value|_bfd_elf_find_nearest_line
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_read_minisymbols
value|_bfd_elf_read_minisymbols
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_minisymbol_to_symbol
value|_bfd_elf_minisymbol_to_symbol
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_get_dynamic_symtab_upper_bound
value|_bfd_elf_get_dynamic_symtab_upper_bound
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_get_lineno
value|_bfd_elf_get_lineno
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_get_reloc_upper_bound
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_get_reloc_upper_bound
value|_bfd_elf_get_reloc_upper_bound
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_get_symbol_info
value|_bfd_elf_get_symbol_info
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_get_symtab
value|_bfd_elf_get_symtab
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_get_symtab_upper_bound
value|_bfd_elf_get_symtab_upper_bound
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* done in elf-bfd.h */
end_comment

begin_define
define|#
directive|define
name|bfd_elfNN_link_record_dynamic_symbol
value|_bfd_elf_link_record_dynamic_symbol
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_make_empty_symbol
value|_bfd_elf_make_empty_symbol
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_new_section_hook
value|_bfd_elf_new_section_hook
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_set_arch_mach
value|_bfd_elf_set_arch_mach
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_set_section_contents
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_set_section_contents
value|_bfd_elf_set_section_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_sizeof_headers
value|_bfd_elf_sizeof_headers
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_write_object_contents
value|_bfd_elf_write_object_contents
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_write_corefile_contents
value|_bfd_elf_write_corefile_contents
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_get_section_contents_in_window
define|\
value|_bfd_generic_get_section_contents_in_window
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_got_symbol_offset
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_got_symbol_offset
value|(bfd_vma) 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_can_refcount
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_can_refcount
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_want_got_plt
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_want_got_plt
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_plt_readonly
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_plt_readonly
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_want_plt_sym
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_want_plt_sym
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_plt_not_loaded
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_plt_not_loaded
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_plt_alignment
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_plt_alignment
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_want_dynbss
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_want_dynbss
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_debug_info_start
value|bfd_void
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_debug_info_end
value|bfd_void
end_define

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_debug_info_accumulate
define|\
value|(void (*) PARAMS ((bfd*, struct sec *))) bfd_void
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_get_relocated_section_contents
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_get_relocated_section_contents
define|\
value|bfd_generic_get_relocated_section_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_relax_section
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_relax_section
value|bfd_generic_relax_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_can_gc_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_can_gc_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_can_refcount
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_can_refcount
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_want_got_sym
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_want_got_sym
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_gc_mark_hook
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_gc_mark_hook
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_gc_sweep_hook
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_gc_sweep_hook
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_gc_sections
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_gc_sections
value|_bfd_elfNN_gc_sections
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_merge_sections
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_merge_sections
define|\
value|_bfd_elf_merge_sections
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_make_debug_symbol
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_make_debug_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *, void *, unsigned long))) bfd_nullvoidptr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_copy_private_symbol_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_copy_private_symbol_data
define|\
value|_bfd_elf_copy_private_symbol_data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_copy_private_section_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_copy_private_section_data
define|\
value|_bfd_elf_copy_private_section_data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_copy_private_bfd_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_copy_private_bfd_data
define|\
value|_bfd_elf_copy_private_bfd_data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_print_private_bfd_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_print_private_bfd_data
define|\
value|_bfd_elf_print_private_bfd_data
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_merge_private_bfd_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_merge_private_bfd_data
define|\
value|((boolean (*) PARAMS ((bfd *, bfd *))) bfd_true)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_set_private_flags
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_set_private_flags
define|\
value|((boolean (*) PARAMS ((bfd *, flagword))) bfd_true)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_is_local_label_name
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_is_local_label_name
value|_bfd_elf_is_local_label_name
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_get_dynamic_reloc_upper_bound
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_get_dynamic_reloc_upper_bound
define|\
value|_bfd_elf_get_dynamic_reloc_upper_bound
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_canonicalize_dynamic_reloc
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_canonicalize_dynamic_reloc
define|\
value|_bfd_elf_canonicalize_dynamic_reloc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|elf_backend_relocate_section
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_link_hash_table_create
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_link_hash_table_create
value|_bfd_elf_link_hash_table_create
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! defined (elf_backend_relocate_section) */
end_comment

begin_comment
comment|/* If no backend relocate_section routine, use the generic linker.    Note - this will prevent the port from being able to use some of    the other features of the ELF linker, because the generic hash structure    does not have the fields needed by the ELF linker.  In particular it    means that linking directly to S-records will not work.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_link_hash_table_create
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_link_hash_table_create
define|\
value|_bfd_generic_link_hash_table_create
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_link_add_symbols
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_link_add_symbols
value|_bfd_generic_link_add_symbols
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_final_link
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_final_link
value|_bfd_generic_final_link
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! defined (elf_backend_relocate_section) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_bfd_link_split_section
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_bfd_link_split_section
value|_bfd_generic_link_split_section
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_archive_p
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_archive_p
value|bfd_generic_archive_p
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_write_archive_contents
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_write_archive_contents
value|_bfd_write_archive_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_mkobject
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_mkobject
value|bfd_elf_mkobject
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_mkcorefile
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_mkcorefile
value|bfd_elf_mkcorefile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elfNN_mkarchive
end_ifndef

begin_define
define|#
directive|define
name|bfd_elfNN_mkarchive
value|_bfd_generic_mkarchive
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_symbol_leading_char
end_ifndef

begin_define
define|#
directive|define
name|elf_symbol_leading_char
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_info_to_howto
end_ifndef

begin_define
define|#
directive|define
name|elf_info_to_howto
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_info_to_howto_rel
end_ifndef

begin_define
define|#
directive|define
name|elf_info_to_howto_rel
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_MAXPAGESIZE
end_ifndef

begin_error
error|#
directive|error
error|ELF_MAXPAGESIZE is not defined
end_error

begin_define
define|#
directive|define
name|ELF_MAXPAGESIZE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_collect
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_collect
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_type_change_ok
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_type_change_ok
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_sym_is_global
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_sym_is_global
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_object_p
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_object_p
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_symbol_processing
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_symbol_processing
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_symbol_table_processing
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_symbol_table_processing
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_get_symbol_type
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_get_symbol_type
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_section_processing
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_section_processing
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_section_from_shdr
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_section_from_shdr
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_section_flags
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_section_flags
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_section_from_phdr
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_section_from_phdr
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_fake_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_fake_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_section_from_bfd_section
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_section_from_bfd_section
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_add_symbol_hook
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_add_symbol_hook
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_link_output_symbol_hook
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_link_output_symbol_hook
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_create_dynamic_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_create_dynamic_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_check_relocs
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_check_relocs
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_adjust_dynamic_symbol
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_adjust_dynamic_symbol
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_always_size_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_always_size_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_size_dynamic_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_size_dynamic_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_relocate_section
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_relocate_section
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_finish_dynamic_symbol
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_symbol
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_finish_dynamic_sections
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_finish_dynamic_sections
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_begin_write_processing
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_begin_write_processing
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_final_write_processing
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_final_write_processing
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_additional_program_headers
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_additional_program_headers
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_modify_segment_map
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_modify_segment_map
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_ecoff_debug_swap
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_ecoff_debug_swap
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_got_header_size
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_got_header_size
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_plt_header_size
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_plt_header_size
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_post_process_headers
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_post_process_headers
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_print_symbol_all
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_print_symbol_all
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_output_arch_syms
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_output_arch_syms
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_copy_indirect_symbol
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_copy_indirect_symbol
value|_bfd_elf_link_hash_copy_indirect
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_hide_symbol
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_hide_symbol
value|_bfd_elf_link_hash_hide_symbol
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_emit_relocs
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_emit_relocs
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_count_relocs
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_count_relocs
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_grok_prstatus
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_grok_prstatus
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_grok_psinfo
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_grok_psinfo
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_sprintf_vma
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_sprintf_vma
value|_bfd_elf_sprintf_vma
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_fprintf_vma
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_fprintf_vma
value|_bfd_elf_fprintf_vma
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_reloc_type_class
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_reloc_type_class
value|_bfd_elf_reloc_type_class
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_discard_info
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_discard_info
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_ignore_discarded_relocs
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_ignore_discarded_relocs
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_write_section
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_write_section
value|NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Previously, backends could only use SHT_REL or SHT_RELA relocation    sections, but not both.  They defined USE_REL to indicate SHT_REL    sections, and left it undefined to indicated SHT_RELA sections.    For backwards compatibility, we still support this usage.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_REL
end_ifndef

begin_define
define|#
directive|define
name|USE_REL
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|USE_REL
end_undef

begin_define
define|#
directive|define
name|USE_REL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use these in new code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_may_use_rel_p
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_may_use_rel_p
value|USE_REL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_may_use_rela_p
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_may_use_rela_p
value|!USE_REL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_default_use_rela_p
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_default_use_rela_p
value|!USE_REL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_MACHINE_ALT1
end_ifndef

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT1
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ELF_MACHINE_ALT2
end_ifndef

begin_define
define|#
directive|define
name|ELF_MACHINE_ALT2
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_size_info
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_size_info
value|_bfd_elfNN_size_info
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|elf_backend_sign_extend_vma
end_ifndef

begin_define
define|#
directive|define
name|elf_backend_sign_extend_vma
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|elf_size_info
name|_bfd_elfNN_size_info
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|INCLUDED_TARGET_FILE
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|struct
name|elf_backend_data
name|elfNN_bed
init|=
block|{
name|ELF_ARCH
block|,
comment|/* arch */
name|ELF_MACHINE_CODE
block|,
comment|/* elf_machine_code */
name|ELF_MAXPAGESIZE
block|,
comment|/* maxpagesize */
name|elf_info_to_howto
block|,
name|elf_info_to_howto_rel
block|,
name|elf_backend_sym_is_global
block|,
name|elf_backend_object_p
block|,
name|elf_backend_symbol_processing
block|,
name|elf_backend_symbol_table_processing
block|,
name|elf_backend_get_symbol_type
block|,
name|elf_backend_section_processing
block|,
name|elf_backend_section_from_shdr
block|,
name|elf_backend_section_flags
block|,
name|elf_backend_section_from_phdr
block|,
name|elf_backend_fake_sections
block|,
name|elf_backend_section_from_bfd_section
block|,
name|elf_backend_add_symbol_hook
block|,
name|elf_backend_link_output_symbol_hook
block|,
name|elf_backend_create_dynamic_sections
block|,
name|elf_backend_check_relocs
block|,
name|elf_backend_adjust_dynamic_symbol
block|,
name|elf_backend_always_size_sections
block|,
name|elf_backend_size_dynamic_sections
block|,
name|elf_backend_relocate_section
block|,
name|elf_backend_finish_dynamic_symbol
block|,
name|elf_backend_finish_dynamic_sections
block|,
name|elf_backend_begin_write_processing
block|,
name|elf_backend_final_write_processing
block|,
name|elf_backend_additional_program_headers
block|,
name|elf_backend_modify_segment_map
block|,
name|elf_backend_gc_mark_hook
block|,
name|elf_backend_gc_sweep_hook
block|,
name|elf_backend_post_process_headers
block|,
name|elf_backend_print_symbol_all
block|,
name|elf_backend_output_arch_syms
block|,
name|elf_backend_copy_indirect_symbol
block|,
name|elf_backend_hide_symbol
block|,
name|elf_backend_emit_relocs
block|,
name|elf_backend_count_relocs
block|,
name|elf_backend_grok_prstatus
block|,
name|elf_backend_grok_psinfo
block|,
name|elf_backend_sprintf_vma
block|,
name|elf_backend_fprintf_vma
block|,
name|elf_backend_reloc_type_class
block|,
name|elf_backend_discard_info
block|,
name|elf_backend_ignore_discarded_relocs
block|,
name|elf_backend_write_section
block|,
name|elf_backend_ecoff_debug_swap
block|,
name|ELF_MACHINE_ALT1
block|,
name|ELF_MACHINE_ALT2
block|,
operator|&
name|elf_backend_size_info
block|,
name|elf_backend_got_symbol_offset
block|,
name|elf_backend_got_header_size
block|,
name|elf_backend_plt_header_size
block|,
name|elf_backend_collect
block|,
name|elf_backend_type_change_ok
block|,
name|elf_backend_may_use_rel_p
block|,
name|elf_backend_may_use_rela_p
block|,
name|elf_backend_default_use_rela_p
block|,
name|elf_backend_sign_extend_vma
block|,
name|elf_backend_want_got_plt
block|,
name|elf_backend_plt_readonly
block|,
name|elf_backend_want_plt_sym
block|,
name|elf_backend_plt_not_loaded
block|,
name|elf_backend_plt_alignment
block|,
name|elf_backend_can_gc_sections
block|,
name|elf_backend_can_refcount
block|,
name|elf_backend_want_got_sym
block|,
name|elf_backend_want_dynbss
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Forward declaration for use when initialising alternative_target field.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LITTLE_SYM
end_ifdef

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
name|TARGET_LITTLE_SYM
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_BIG_SYM
end_ifdef

begin_decl_stmt
specifier|const
name|bfd_target
name|TARGET_BIG_SYM
init|=
block|{
comment|/* name: identify kind of target */
name|TARGET_BIG_NAME
block|,
comment|/* flavour: general indication about file */
name|bfd_target_elf_flavour
block|,
comment|/* byteorder: data is big endian */
name|BFD_ENDIAN_BIG
block|,
comment|/* header_byteorder: header is also big endian */
name|BFD_ENDIAN_BIG
block|,
comment|/* object_flags: mask of all file flags */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator||
name|D_PAGED
operator|)
block|,
comment|/* section_flags: mask of all section flags */
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator||
name|SEC_READONLY
operator||
name|SEC_CODE
operator||
name|SEC_DATA
operator||
name|SEC_DEBUGGING
operator||
name|SEC_EXCLUDE
operator||
name|SEC_SORT_ENTRIES
operator||
name|SEC_ARCH_BIT_0
operator||
name|SEC_SMALL_DATA
operator||
name|SEC_MERGE
operator||
name|SEC_STRINGS
operator||
name|SEC_GROUP
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
name|elf_symbol_leading_char
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and should be independently tunable.  The System V ABI,      Chapter 7 (Formats& Protocols), Archive section sets this as 15.  */
literal|15
block|,
comment|/* Routines to byte-swap various sized integers from the data sections */
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
comment|/* Routines to byte-swap various sized integers from the file headers */
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
comment|/* bfd_check_format: check the format of a file being read */
block|{
name|_bfd_dummy_target
block|,
comment|/* unknown format */
name|bfd_elfNN_object_p
block|,
comment|/* assembler/linker output (object file) */
name|bfd_elfNN_archive_p
block|,
comment|/* an archive */
name|bfd_elfNN_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|bfd_elfNN_mkobject
block|,
name|bfd_elfNN_mkarchive
block|,
name|bfd_elfNN_mkcorefile
block|}
block|,
comment|/* bfd_write_contents: write cached information into a file being written */
block|{
name|bfd_false
block|,
name|bfd_elfNN_write_object_contents
block|,
name|bfd_elfNN_write_archive_contents
block|,
name|bfd_elfNN_write_corefile_contents
block|,   }
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
ifdef|#
directive|ifdef
name|bfd_elfNN_archive_functions
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|bfd_elfNN_archive
argument_list|)
block|,
else|#
directive|else
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_archive_coff
argument_list|)
block|,
endif|#
directive|endif
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
comment|/* Alternative endian target.  */
ifdef|#
directive|ifdef
name|TARGET_LITTLE_SYM
operator|&
name|TARGET_LITTLE_SYM
block|,
else|#
directive|else
name|NULL
block|,
endif|#
directive|endif
comment|/* backend_data: */
operator|(
name|PTR
operator|)
operator|&
name|elfNN_bed
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LITTLE_SYM
end_ifdef

begin_decl_stmt
specifier|const
name|bfd_target
name|TARGET_LITTLE_SYM
init|=
block|{
comment|/* name: identify kind of target */
name|TARGET_LITTLE_NAME
block|,
comment|/* flavour: general indication about file */
name|bfd_target_elf_flavour
block|,
comment|/* byteorder: data is little endian */
name|BFD_ENDIAN_LITTLE
block|,
comment|/* header_byteorder: header is also little endian */
name|BFD_ENDIAN_LITTLE
block|,
comment|/* object_flags: mask of all file flags */
operator|(
name|HAS_RELOC
operator||
name|EXEC_P
operator||
name|HAS_LINENO
operator||
name|HAS_DEBUG
operator||
name|HAS_SYMS
operator||
name|HAS_LOCALS
operator||
name|DYNAMIC
operator||
name|WP_TEXT
operator||
name|D_PAGED
operator|)
block|,
comment|/* section_flags: mask of all section flags */
operator|(
name|SEC_HAS_CONTENTS
operator||
name|SEC_ALLOC
operator||
name|SEC_LOAD
operator||
name|SEC_RELOC
operator||
name|SEC_READONLY
operator||
name|SEC_CODE
operator||
name|SEC_DATA
operator||
name|SEC_DEBUGGING
operator||
name|SEC_EXCLUDE
operator||
name|SEC_SORT_ENTRIES
operator||
name|SEC_ARCH_BIT_0
operator||
name|SEC_SMALL_DATA
operator||
name|SEC_MERGE
operator||
name|SEC_STRINGS
operator||
name|SEC_GROUP
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
name|elf_symbol_leading_char
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and should be independently tunable.  The System V ABI,      Chapter 7 (Formats& Protocols), Archive section sets this as 15.  */
literal|15
block|,
comment|/* Routines to byte-swap various sized integers from the data sections */
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* Routines to byte-swap various sized integers from the file headers */
name|bfd_getl64
block|,
name|bfd_getl_signed_64
block|,
name|bfd_putl64
block|,
name|bfd_getl32
block|,
name|bfd_getl_signed_32
block|,
name|bfd_putl32
block|,
name|bfd_getl16
block|,
name|bfd_getl_signed_16
block|,
name|bfd_putl16
block|,
comment|/* bfd_check_format: check the format of a file being read */
block|{
name|_bfd_dummy_target
block|,
comment|/* unknown format */
name|bfd_elfNN_object_p
block|,
comment|/* assembler/linker output (object file) */
name|bfd_elfNN_archive_p
block|,
comment|/* an archive */
name|bfd_elfNN_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|bfd_elfNN_mkobject
block|,
name|bfd_elfNN_mkarchive
block|,
name|bfd_elfNN_mkcorefile
block|}
block|,
comment|/* bfd_write_contents: write cached information into a file being written */
block|{
name|bfd_false
block|,
name|bfd_elfNN_write_object_contents
block|,
name|bfd_elfNN_write_archive_contents
block|,
name|bfd_elfNN_write_corefile_contents
block|,   }
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
ifdef|#
directive|ifdef
name|bfd_elfNN_archive_functions
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|bfd_elfNN_archive
argument_list|)
block|,
else|#
directive|else
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_archive_coff
argument_list|)
block|,
endif|#
directive|endif
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|bfd_elfNN
argument_list|)
block|,
comment|/* Alternative endian target.  */
ifdef|#
directive|ifdef
name|TARGET_BIG_SYM
operator|&
name|TARGET_BIG_SYM
block|,
else|#
directive|else
name|NULL
block|,
endif|#
directive|endif
comment|/* backend_data: */
operator|(
name|PTR
operator|)
operator|&
name|elfNN_bed
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

