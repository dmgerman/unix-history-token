begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for 32-bit ELF    Copyright 1993, 1994 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This structure contains everything that BFD knows about a target.    It includes things like its byte order, name, what routines to call    to do various operations, etc.  Every BFD points to a target structure    with its "xvec" member.     There are two such structures here:  one for big-endian machines and    one for little-endian machines.   */
end_comment

begin_define
define|#
directive|define
name|bfd_elf32_close_and_cleanup
value|_bfd_generic_close_and_cleanup
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_free_cached_info
value|_bfd_generic_bfd_free_cached_info
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_get_section_contents
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_get_section_contents
value|_bfd_generic_get_section_contents
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|bfd_elf32_bfd_get_relocated_section_contents
define|\
value|bfd_generic_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_relax_section
value|bfd_generic_relax_section
end_define

begin_define
define|#
directive|define
name|bfd_elf32_bfd_make_debug_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *, void *, unsigned long))) bfd_nullvoidptr)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_bfd_copy_private_section_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_copy_private_section_data
define|\
value|((boolean (*) PARAMS ((bfd *, asection *, bfd *, asection *))) bfd_true)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_bfd_copy_private_bfd_data
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_copy_private_bfd_data
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
name|bfd_elf32_bfd_is_local_label
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_is_local_label
value|bfd_generic_is_local_label
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_get_dynamic_reloc_upper_bound
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_get_dynamic_reloc_upper_bound
define|\
value|_bfd_nodynamic_get_dynamic_reloc_upper_bound
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_canonicalize_dynamic_reloc
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_canonicalize_dynamic_reloc
define|\
value|_bfd_nodynamic_canonicalize_dynamic_reloc
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
name|bfd_elf32_bfd_link_hash_table_create
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_create
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
comment|/* If no backend relocate_section routine, use the generic linker.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_bfd_link_hash_table_create
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_hash_table_create
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
name|bfd_elf32_bfd_link_add_symbols
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_link_add_symbols
value|_bfd_generic_link_add_symbols
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|bfd_elf32_bfd_final_link
end_ifndef

begin_define
define|#
directive|define
name|bfd_elf32_bfd_final_link
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

begin_expr_stmt
specifier|static
name|CONST
expr|struct
name|elf_backend_data
name|elf32_bed
operator|=
block|{
ifdef|#
directive|ifdef
name|USE_REL
literal|0
block|,
comment|/* use_rela_p */
else|#
directive|else
literal|1
block|,
comment|/* use_rela_p */
endif|#
directive|endif
literal|0
block|,
comment|/* elf_64_p */
name|ELF_ARCH
block|,
comment|/* arch */
name|ELF_MACHINE_CODE
block|,
comment|/* elf_machine_code */
name|ELF_MAXPAGESIZE
block|,
comment|/* maxpagesize */
name|elf_backend_collect
block|,
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
name|elf_backend_section_processing
block|,
name|elf_backend_section_from_shdr
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
name|elf_backend_adjust_dynamic_symbol
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
name|elf_backend_ecoff_debug_swap
block|}
expr_stmt|;
end_expr_stmt

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
comment|/* byteorder_big_p: data is big endian */
name|true
block|,
comment|/* header_byteorder_big_p: header is also big endian */
name|true
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
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
literal|0
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and should be independently tunable.  This value is      a WAG (wild a** guess) */
literal|14
block|,
comment|/* align_power_min: minimum alignment restriction for any section      FIXME:  this value may be target machine dependent */
literal|3
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
name|bfd_elf32_object_p
block|,
comment|/* assembler/linker output (object file) */
name|bfd_generic_archive_p
block|,
comment|/* an archive */
name|bfd_elf32_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|bfd_elf_mkobject
block|,
name|_bfd_generic_mkarchive
block|,
name|bfd_false
block|}
block|,
comment|/* bfd_write_contents: write cached information into a file being written */
block|{
name|bfd_false
block|,
name|bfd_elf32_write_object_contents
block|,
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_archive_coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|bfd_elf32
argument_list|)
block|,
comment|/* backend_data: */
operator|(
name|PTR
operator|)
operator|&
name|elf32_bed
block|, }
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
comment|/* byteorder_big_p: data is big endian */
name|false
block|,
comment|/* Nope -- this one's little endian */
comment|/* header_byteorder_big_p: header is also big endian */
name|false
block|,
comment|/* Nope -- this one's little endian */
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
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
literal|0
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with ELF, this is a characteristic      of the archiver and should be independently tunable.  This value is      a WAG (wild a** guess) */
literal|14
block|,
comment|/* align_power_min: minimum alignment restriction for any section      FIXME:  this value may be target machine dependent */
literal|3
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
name|bfd_elf32_object_p
block|,
comment|/* assembler/linker output (object file) */
name|bfd_generic_archive_p
block|,
comment|/* an archive */
name|bfd_elf32_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|bfd_elf_mkobject
block|,
name|_bfd_generic_mkarchive
block|,
name|bfd_false
block|}
block|,
comment|/* bfd_write_contents: write cached information into a file being written */
block|{
name|bfd_false
block|,
name|bfd_elf32_write_object_contents
block|,
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
block|,
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_archive_coff
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|bfd_elf32
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|bfd_elf32
argument_list|)
block|,
comment|/* backend_data: */
operator|(
name|PTR
operator|)
operator|&
name|elf32_bed
block|, }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

