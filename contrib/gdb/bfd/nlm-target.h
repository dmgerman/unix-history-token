begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for 32/64-bit NLM (NetWare Loadable Module)    Copyright (C) 1993, 1994 Free Software Foundation, Inc.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|nlm_core_file_p
value|_bfd_dummy_target
end_define

begin_define
define|#
directive|define
name|nlm_get_symtab_upper_bound
value|nlmNAME(get_symtab_upper_bound)
end_define

begin_define
define|#
directive|define
name|nlm_get_symtab
value|nlmNAME(get_symtab)
end_define

begin_define
define|#
directive|define
name|nlm_make_empty_symbol
value|nlmNAME(make_empty_symbol)
end_define

begin_define
define|#
directive|define
name|nlm_print_symbol
value|nlmNAME(print_symbol)
end_define

begin_define
define|#
directive|define
name|nlm_get_symbol_info
value|nlmNAME(get_symbol_info)
end_define

begin_define
define|#
directive|define
name|nlm_bfd_is_local_label
value|bfd_generic_is_local_label
end_define

begin_define
define|#
directive|define
name|nlm_get_lineno
value|_bfd_nosymbols_get_lineno
end_define

begin_define
define|#
directive|define
name|nlm_find_nearest_line
value|_bfd_nosymbols_find_nearest_line
end_define

begin_define
define|#
directive|define
name|nlm_bfd_make_debug_symbol
value|_bfd_nosymbols_bfd_make_debug_symbol
end_define

begin_define
define|#
directive|define
name|nlm_read_minisymbols
value|_bfd_generic_read_minisymbols
end_define

begin_define
define|#
directive|define
name|nlm_minisymbol_to_symbol
value|_bfd_generic_minisymbol_to_symbol
end_define

begin_define
define|#
directive|define
name|nlm_get_reloc_upper_bound
value|nlmNAME(get_reloc_upper_bound)
end_define

begin_define
define|#
directive|define
name|nlm_canonicalize_reloc
value|nlmNAME(canonicalize_reloc)
end_define

begin_define
define|#
directive|define
name|nlm_bfd_reloc_type_lookup
value|bfd_default_reloc_type_lookup
end_define

begin_define
define|#
directive|define
name|nlm_set_section_contents
value|nlmNAME(set_section_contents)
end_define

begin_define
define|#
directive|define
name|nlm_sizeof_headers
value|_bfd_nolink_sizeof_headers
end_define

begin_define
define|#
directive|define
name|nlm_bfd_get_relocated_section_contents
define|\
value|bfd_generic_get_relocated_section_contents
end_define

begin_define
define|#
directive|define
name|nlm_bfd_relax_section
value|bfd_generic_relax_section
end_define

begin_define
define|#
directive|define
name|nlm_bfd_link_hash_table_create
value|_bfd_generic_link_hash_table_create
end_define

begin_define
define|#
directive|define
name|nlm_bfd_link_add_symbols
value|_bfd_generic_link_add_symbols
end_define

begin_define
define|#
directive|define
name|nlm_bfd_final_link
value|_bfd_generic_final_link
end_define

begin_define
define|#
directive|define
name|nlm_bfd_link_split_section
value|_bfd_generic_link_split_section
end_define

begin_comment
comment|/* This structure contains everything that BFD knows about a target.    It includes things like its byte order, name, what routines to call    to do various operations, etc.  Every BFD points to a target structure    with its "xvec" member.     There are two such structures here:  one for big-endian machines and    one for little-endian machines.   */
end_comment

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
name|bfd_target_nlm_flavour
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
name|WP_TEXT
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
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
literal|0
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with NLM, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with NLM, this is a characteristic      of the archiver and should be independently tunable.  This value is      a WAG (wild a** guess) */
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
name|nlmNAME
argument_list|(
name|object_p
argument_list|)
block|,
comment|/* assembler/linker output (object file) */
name|bfd_generic_archive_p
block|,
comment|/* an archive */
name|nlm_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|nlm_mkobject
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
name|nlmNAME
argument_list|(
name|write_object_contents
argument_list|)
block|,
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
block|,
comment|/* Initialize a jump table with the standard macro.  All names start with      "nlm" */
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|_bfd_generic
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|_bfd_generic
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|_bfd_nocore
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_noarchive
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|_bfd_nodynamic
argument_list|)
block|,
comment|/* backend_data: */
operator|(
name|PTR
operator|)
name|TARGET_BACKEND_DATA
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
name|bfd_target_nlm_flavour
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
name|WP_TEXT
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
name|SEC_DATA
operator|)
block|,
comment|/* leading_symbol_char: is the first char of a user symbol       predictable, and if so what is it */
literal|0
block|,
comment|/* ar_pad_char: pad character for filenames within an archive header      FIXME:  this really has nothing to do with NLM, this is a characteristic      of the archiver and/or os and should be independently tunable */
literal|'/'
block|,
comment|/* ar_max_namelen: maximum number of characters in an archive header      FIXME:  this really has nothing to do with NLM, this is a characteristic      of the archiver and should be independently tunable.  This value is      a WAG (wild a** guess) */
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
name|nlmNAME
argument_list|(
name|object_p
argument_list|)
block|,
comment|/* assembler/linker output (object file) */
name|bfd_generic_archive_p
block|,
comment|/* an archive */
name|nlm_core_file_p
comment|/* a core file */
block|}
block|,
comment|/* bfd_set_format: set the format of a file being written */
block|{
name|bfd_false
block|,
name|nlm_mkobject
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
name|nlmNAME
argument_list|(
name|write_object_contents
argument_list|)
block|,
name|_bfd_write_archive_contents
block|,
name|bfd_false
block|}
block|,
comment|/* Initialize a jump table with the standard macro.  All names start with      "nlm" */
name|BFD_JUMP_TABLE_GENERIC
argument_list|(
name|_bfd_generic
argument_list|)
block|,
name|BFD_JUMP_TABLE_COPY
argument_list|(
name|_bfd_generic
argument_list|)
block|,
name|BFD_JUMP_TABLE_CORE
argument_list|(
name|_bfd_nocore
argument_list|)
block|,
name|BFD_JUMP_TABLE_ARCHIVE
argument_list|(
name|_bfd_noarchive
argument_list|)
block|,
name|BFD_JUMP_TABLE_SYMBOLS
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_RELOCS
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_WRITE
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_LINK
argument_list|(
name|nlm
argument_list|)
block|,
name|BFD_JUMP_TABLE_DYNAMIC
argument_list|(
name|_bfd_nodynamic
argument_list|)
block|,
comment|/* backend_data: */
operator|(
name|PTR
operator|)
name|TARGET_BACKEND_DATA
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

