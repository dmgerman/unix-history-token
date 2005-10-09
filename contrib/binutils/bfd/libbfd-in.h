begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libbfd.h -- Declarations used by bfd library *implementation*.    (This include file is not for users of the library.)     Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     Written by Cygnus Support.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Align an address upward to a boundary, expressed as a number of bytes.    E.g. align to an 8-byte boundary with argument of 8.  Take care never    to wrap around if the address is within boundary-1 of the end of the    address space.  */
end_comment

begin_define
define|#
directive|define
name|BFD_ALIGN
parameter_list|(
name|this
parameter_list|,
name|boundary
parameter_list|)
define|\
value|((((bfd_vma) (this) + (boundary) - 1)>= (bfd_vma) (this))		  \    ? (((bfd_vma) (this) + ((boundary) - 1))& ~ (bfd_vma) ((boundary)-1)) \    : ~ (bfd_vma) 0)
end_define

begin_comment
comment|/* If you want to read and write large blocks, you might want to do it    in quanta of this amount */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_BUFFERSIZE
value|8192
end_define

begin_comment
comment|/* Set a tdata field.  Can't use the other macros for this, since they    do casts, and casting to the left of assignment isn't portable.  */
end_comment

begin_define
define|#
directive|define
name|set_tdata
parameter_list|(
name|bfd
parameter_list|,
name|v
parameter_list|)
value|((bfd)->tdata.any = (v))
end_define

begin_comment
comment|/* If BFD_IN_MEMORY is set for a BFD, then the iostream fields points    to an instance of this structure.  */
end_comment

begin_struct
struct|struct
name|bfd_in_memory
block|{
comment|/* Size of buffer.  */
name|bfd_size_type
name|size
decl_stmt|;
comment|/* Buffer holding contents of BFD.  */
name|bfd_byte
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* tdata for an archive.  For an input archive, cache    needs to be free()'d.  For an output archive, symdefs do.  */
end_comment

begin_struct
struct|struct
name|artdata
block|{
name|file_ptr
name|first_file_filepos
decl_stmt|;
comment|/* Speed up searching the armap */
name|struct
name|ar_cache
modifier|*
name|cache
decl_stmt|;
name|bfd
modifier|*
name|archive_head
decl_stmt|;
comment|/* Only interesting in output routines */
name|carsym
modifier|*
name|symdefs
decl_stmt|;
comment|/* the symdef entries */
name|symindex
name|symdef_count
decl_stmt|;
comment|/* how many there are */
name|char
modifier|*
name|extended_names
decl_stmt|;
comment|/* clever intel extension */
comment|/* when more compilers are standard C, this can be a time_t */
name|long
name|armap_timestamp
decl_stmt|;
comment|/* Timestamp value written into armap. 				   This is used for BSD archives to check 				   that the timestamp is recent enough 				   for the BSD linker to not complain, 				   just before we finish writing an 				   archive.  */
name|file_ptr
name|armap_datepos
decl_stmt|;
comment|/* Position within archive to seek to 				   rewrite the date field.  */
name|void
modifier|*
name|tdata
decl_stmt|;
comment|/* Backend specific information.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|bfd_ardata
parameter_list|(
name|bfd
parameter_list|)
value|((bfd)->tdata.aout_ar_data)
end_define

begin_comment
comment|/* Goes in bfd's arelt_data slot */
end_comment

begin_struct
struct|struct
name|areltdata
block|{
name|char
modifier|*
name|arch_header
decl_stmt|;
comment|/* it's actually a string */
name|unsigned
name|int
name|parsed_size
decl_stmt|;
comment|/* octets of filesize not including ar_hdr */
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* null-terminated */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|arelt_size
parameter_list|(
name|bfd
parameter_list|)
value|(((struct areltdata *)((bfd)->arelt_data))->parsed_size)
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|bfd_malloc
parameter_list|(
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|bfd_realloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|bfd_zmalloc
parameter_list|(
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bfd_error_handler_type
name|_bfd_error_handler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These routines allocate and free things on the BFD's objalloc.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|bfd_alloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|bfd_zalloc
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|bfd_release
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|_bfd_create_empty_archive_element_shell
parameter_list|(
name|bfd
modifier|*
name|obfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|_bfd_look_for_bfd_in_cache
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|file_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|_bfd_add_bfd_to_archive_cache
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|file_ptr
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|_bfd_generic_mkarchive
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|bfd_generic_archive_p
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_slurp_armap
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_slurp_bsd_armap_f2
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|bfd_slurp_bsd_armap
value|bfd_slurp_armap
end_define

begin_define
define|#
directive|define
name|bfd_slurp_coff_armap
value|bfd_slurp_armap
end_define

begin_function_decl
name|bfd_boolean
name|_bfd_slurp_extended_name_table
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_construct_extended_name_table
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|_bfd_write_archive_contents
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|_bfd_compute_and_write_armap
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|unsigned
name|int
name|elength
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|_bfd_get_elt_at_filepos
parameter_list|(
name|bfd
modifier|*
name|archive
parameter_list|,
name|file_ptr
name|filepos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd
modifier|*
name|_bfd_generic_get_elt_at_index
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|symindex
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|_bfd_new_bfd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|_bfd_delete_bfd
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_false
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bfd_true
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|bfd_nullvoidptr
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_0
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|bfd_0u
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|bfd_0l
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|_bfd_n1
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bfd_void
parameter_list|(
name|bfd
modifier|*
name|ignore
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd
modifier|*
name|_bfd_new_bfd_contained_in
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|bfd_target
modifier|*
name|_bfd_dummy_target
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bfd_dont_truncate_arname
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bfd_bsd_truncate_arname
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bfd_gnu_truncate_arname
parameter_list|(
name|bfd
modifier|*
name|abfd
parameter_list|,
specifier|const
name|char
modifier|*
name|filename
parameter_list|,
name|char
modifier|*
name|hdr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|bsd_write_armap
parameter_list|(
name|bfd
modifier|*
name|arch
parameter_list|,
name|unsigned
name|int
name|elength
parameter_list|,
name|struct
name|orl
modifier|*
name|map
parameter_list|,
name|unsigned
name|int
name|orl_count
parameter_list|,
name|int
name|stridx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bfd_boolean
name|coff_write_armap
parameter_list|(
name|bfd
modifier|*
name|arch
parameter_list|,
name|unsigned
name|int
name|elength
parameter_list|,
name|struct
name|orl
modifier|*
name|map
parameter_list|,
name|unsigned
name|int
name|orl_count
parameter_list|,
name|int
name|stridx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|_bfd_generic_read_ar_hdr
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
name|_bfd_generic_read_ar_hdr_mag
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
name|bfd
modifier|*
name|bfd_generic_openr_next_archived_file
parameter_list|(
name|bfd
modifier|*
name|archive
parameter_list|,
name|bfd
modifier|*
name|last_file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bfd_generic_stat_arch_elt
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

begin_define
define|#
directive|define
name|_bfd_read_ar_hdr
parameter_list|(
name|abfd
parameter_list|)
define|\
value|BFD_SEND (abfd, _bfd_read_ar_hdr_fn, (abfd))
end_define

begin_escape
end_escape

begin_comment
comment|/* Generic routines to use for BFD_JUMP_TABLE_GENERIC.  Use    BFD_JUMP_TABLE_GENERIC (_bfd_generic).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_close_and_cleanup
value|bfd_true
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_free_cached_info
value|bfd_true
end_define

begin_define
define|#
directive|define
name|_bfd_generic_new_section_hook
define|\
value|((bfd_boolean (*) (bfd *, asection *)) bfd_true)
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_get_section_contents
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|file_ptr
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_get_section_contents_in_window
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_window
modifier|*
parameter_list|,
name|file_ptr
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic routines to use for BFD_JUMP_TABLE_COPY.  Use    BFD_JUMP_TABLE_COPY (_bfd_generic).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_bfd_data
define|\
value|((bfd_boolean (*) (bfd *, bfd *)) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_merge_private_bfd_data
define|\
value|((bfd_boolean (*) (bfd *, bfd *)) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_set_private_flags
define|\
value|((bfd_boolean (*) (bfd *, flagword)) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_section_data
define|\
value|((bfd_boolean (*) (bfd *, asection *, bfd *, asection *)) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_symbol_data
define|\
value|((bfd_boolean (*) (bfd *, asymbol *, bfd *, asymbol *)) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_print_private_bfd_data
define|\
value|((bfd_boolean (*) (bfd *, void *)) bfd_true)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_CORE when there is no core file    support.  Use BFD_JUMP_TABLE_CORE (_bfd_nocore).  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|_bfd_nocore_core_file_failing_command
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_bfd_nocore_core_file_failing_signal
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_nocore_core_file_matches_executable_p
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_ARCHIVE when there is no archive    file support.  Use BFD_JUMP_TABLE_ARCHIVE (_bfd_noarchive).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_noarchive_slurp_armap
value|bfd_false
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_slurp_extended_name_table
value|bfd_false
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_construct_extended_name_table
define|\
value|((bfd_boolean (*) (bfd *, char **, bfd_size_type *, const char **)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_truncate_arname
define|\
value|((void (*) (bfd *, const char *, char *)) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_write_armap
define|\
value|((bfd_boolean (*) (bfd *, unsigned int, struct orl *, unsigned int, int)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_read_ar_hdr
value|bfd_nullvoidptr
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_openr_next_archived_file
define|\
value|((bfd *(*) (bfd *, bfd *)) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_get_elt_at_index
define|\
value|((bfd *(*) (bfd *, symindex)) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_generic_stat_arch_elt
value|bfd_generic_stat_arch_elt
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_update_armap_timestamp
value|bfd_false
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_ARCHIVE to get BSD style    archives.  Use BFD_JUMP_TABLE_ARCHIVE (_bfd_archive_bsd).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_archive_bsd_slurp_armap
value|bfd_slurp_bsd_armap
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_slurp_extended_name_table
define|\
value|_bfd_slurp_extended_name_table
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_archive_bsd_construct_extended_name_table
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_bfd_archive_bsd_truncate_arname
value|bfd_bsd_truncate_arname
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_write_armap
value|bsd_write_armap
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_read_ar_hdr
value|_bfd_generic_read_ar_hdr
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_openr_next_archived_file
define|\
value|bfd_generic_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_get_elt_at_index
value|_bfd_generic_get_elt_at_index
end_define

begin_define
define|#
directive|define
name|_bfd_archive_bsd_generic_stat_arch_elt
define|\
value|bfd_generic_stat_arch_elt
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_archive_bsd_update_armap_timestamp
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_ARCHIVE to get COFF style    archives.  Use BFD_JUMP_TABLE_ARCHIVE (_bfd_archive_coff).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_archive_coff_slurp_armap
value|bfd_slurp_coff_armap
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_slurp_extended_name_table
define|\
value|_bfd_slurp_extended_name_table
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_archive_coff_construct_extended_name_table
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|_bfd_archive_coff_truncate_arname
value|bfd_dont_truncate_arname
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_write_armap
value|coff_write_armap
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_read_ar_hdr
value|_bfd_generic_read_ar_hdr
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_openr_next_archived_file
define|\
value|bfd_generic_openr_next_archived_file
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_get_elt_at_index
value|_bfd_generic_get_elt_at_index
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_generic_stat_arch_elt
define|\
value|bfd_generic_stat_arch_elt
end_define

begin_define
define|#
directive|define
name|_bfd_archive_coff_update_armap_timestamp
value|bfd_true
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_SYMBOLS where there is no symbol    support.  Use BFD_JUMP_TABLE_SYMBOLS (_bfd_nosymbols).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nosymbols_get_symtab_upper_bound
value|_bfd_n1
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_canonicalize_symtab
define|\
value|((long (*) (bfd *, asymbol **)) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_make_empty_symbol
value|_bfd_generic_make_empty_symbol
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_print_symbol
define|\
value|((void (*) (bfd *, void *, asymbol *, bfd_print_symbol_type)) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_get_symbol_info
define|\
value|((void (*) (bfd *, asymbol *, symbol_info *)) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_bfd_is_local_label_name
define|\
value|((bfd_boolean (*) (bfd *, const char *)) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_get_lineno
define|\
value|((alent *(*) (bfd *, asymbol *)) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_find_nearest_line
define|\
value|((bfd_boolean (*) (bfd *, asection *, asymbol **, bfd_vma, const char **, \ 		     const char **, unsigned int *)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_bfd_make_debug_symbol
define|\
value|((asymbol *(*) (bfd *, void *, unsigned long)) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_read_minisymbols
define|\
value|((long (*) (bfd *, bfd_boolean, void **, unsigned int *)) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_minisymbol_to_symbol
define|\
value|((asymbol *(*) (bfd *, bfd_boolean, const void *, asymbol *)) \    bfd_nullvoidptr)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_RELOCS when there is no reloc    support.  Use BFD_JUMP_TABLE_RELOCS (_bfd_norelocs).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_norelocs_get_reloc_upper_bound
define|\
value|((long (*) (bfd *, asection *)) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_norelocs_canonicalize_reloc
define|\
value|((long (*) (bfd *, asection *, arelent **, asymbol **)) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_norelocs_bfd_reloc_type_lookup
define|\
value|((reloc_howto_type *(*) (bfd *, bfd_reloc_code_real_type)) bfd_nullvoidptr)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_WRITE for targets which may not    be written.  Use BFD_JUMP_TABLE_WRITE (_bfd_nowrite).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nowrite_set_arch_mach
define|\
value|((bfd_boolean (*) (bfd *, enum bfd_architecture, unsigned long)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nowrite_set_section_contents
define|\
value|((bfd_boolean (*) (bfd *, asection *, const void *, file_ptr, bfd_size_type)) \    bfd_false)
end_define

begin_comment
comment|/* Generic routines to use for BFD_JUMP_TABLE_WRITE.  Use    BFD_JUMP_TABLE_WRITE (_bfd_generic).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_set_arch_mach
value|bfd_default_set_arch_mach
end_define

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_set_section_contents
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|file_ptr
parameter_list|,
name|bfd_size_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_LINK for targets which do not    support linking.  Use BFD_JUMP_TABLE_LINK (_bfd_nolink).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nolink_sizeof_headers
value|((int (*) (bfd *, bfd_boolean)) bfd_0)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_get_relocated_section_contents
define|\
value|((bfd_byte *(*) (bfd *, struct bfd_link_info *, struct bfd_link_order *, \ 		   bfd_byte *, bfd_boolean, asymbol **)) \    bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_relax_section
define|\
value|((bfd_boolean (*) \     (bfd *, asection *, struct bfd_link_info *, bfd_boolean *)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_gc_sections
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_link_info *)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_merge_sections
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_link_info *)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_discard_group
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_section *)) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_hash_table_create
define|\
value|((struct bfd_link_hash_table *(*) (bfd *)) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_hash_table_free
define|\
value|((void (*) (struct bfd_link_hash_table *)) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_add_symbols
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_link_info *)) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_just_syms
define|\
value|((void (*) (asection *, struct bfd_link_info *)) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_final_link
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_link_info *)) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_split_section
define|\
value|((bfd_boolean (*) (bfd *, struct bfd_section *)) bfd_false)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_DYNAMIC for targets which do not    have dynamic symbols or relocs.  Use BFD_JUMP_TABLE_DYNAMIC    (_bfd_nodynamic).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nodynamic_get_dynamic_symtab_upper_bound
value|_bfd_n1
end_define

begin_define
define|#
directive|define
name|_bfd_nodynamic_canonicalize_dynamic_symtab
define|\
value|((long (*) (bfd *, asymbol **)) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_nodynamic_get_dynamic_reloc_upper_bound
value|_bfd_n1
end_define

begin_define
define|#
directive|define
name|_bfd_nodynamic_canonicalize_dynamic_reloc
define|\
value|((long (*) (bfd *, arelent **, asymbol **)) _bfd_n1)
end_define

begin_escape
end_escape

begin_comment
comment|/* Generic routine to determine of the given symbol is a local    label.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|bfd_generic_is_local_label_name
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

begin_comment
comment|/* Generic minisymbol routines.  */
end_comment

begin_function_decl
specifier|extern
name|long
name|_bfd_generic_read_minisymbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
name|void
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
name|asymbol
modifier|*
name|_bfd_generic_minisymbol_to_symbol
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_boolean
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|asymbol
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the nearest line using .stab/.stabstr sections.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_stab_section_find_nearest_line
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asymbol
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_boolean
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
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the neaderst line using DWARF 1 debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_dwarf1_find_nearest_line
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

begin_comment
comment|/* Find the nearest line using DWARF 2 debugging information.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_dwarf2_find_nearest_line
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
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a new section entry.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|bfd_section_hash_newfunc
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

begin_comment
comment|/* A routine to create entries for a bfd_link_hash_table.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_link_hash_newfunc
parameter_list|(
name|struct
name|bfd_hash_entry
modifier|*
name|entry
parameter_list|,
name|struct
name|bfd_hash_table
modifier|*
name|table
parameter_list|,
specifier|const
name|char
modifier|*
name|string
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize a bfd_link_hash_table.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_boolean
name|_bfd_link_hash_table_init
argument_list|(
expr|struct
name|bfd_link_hash_table
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
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic link hash table creation routine.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|_bfd_generic_link_hash_table_create
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic link hash table destruction routine.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_bfd_generic_link_hash_table_free
parameter_list|(
name|struct
name|bfd_link_hash_table
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic add symbol routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_link_add_symbols
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

begin_comment
comment|/* Generic add symbol routine.  This version is used by targets for    which the linker must collect constructors and destructors by name,    as the collect2 program does.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_link_add_symbols_collect
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

begin_comment
comment|/* Generic archive add symbol routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_link_add_archive_symbols
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd_boolean
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Forward declaration to avoid prototype errors.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bfd_link_hash_entry
name|_bfd_link_hash_entry
typedef|;
end_typedef

begin_comment
comment|/* Generic routine to add a single symbol.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_link_add_one_symbol
parameter_list|(
name|struct
name|bfd_link_info
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|flagword
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
name|copy
parameter_list|,
name|bfd_boolean
name|constructor
parameter_list|,
name|struct
name|bfd_link_hash_entry
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic routine to mark section as supplying symbols only.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_bfd_generic_link_just_syms
parameter_list|(
name|asection
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic link routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_final_link
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
name|_bfd_generic_link_split_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Generic reloc_link_order processing routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_reloc_link_order
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
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

begin_comment
comment|/* Default link order processing routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_default_link_order
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_link_info
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

begin_comment
comment|/* Count the number of reloc entries in a link order list.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|int
name|_bfd_count_link_order_relocs
parameter_list|(
name|struct
name|bfd_link_order
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Final link relocation routine.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_reloc_status_type
name|_bfd_final_link_relocate
parameter_list|(
name|reloc_howto_type
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
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Relocate a particular location by a howto and a value.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_reloc_status_type
name|_bfd_relocate_contents
parameter_list|(
name|reloc_howto_type
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Link stabs in sections in the first pass.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_link_section_stabs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|bfd_size_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Eliminate stabs for discarded functions and symbols.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_discard_section_stabs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_boolean
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|bfd_vma
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out the .stab section when linking stabs in sections.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_write_section_stabs
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out the .stabstr string table when linking stabs in sections.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_write_stab_strings
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find an offset within a .stab section when linking stabs in    sections.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_vma
name|_bfd_stab_section_offset
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attempt to merge a SEC_MERGE section.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_merge_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Attempt to merge SEC_MERGE sections.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_merge_sections
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out a merged section.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_write_merged_section
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find an offset within a modified SEC_MERGE section.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_vma
name|_bfd_merged_section_offset
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a string table.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_strtab_hash
modifier|*
name|_bfd_stringtab_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create an XCOFF .debug section style string table.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|bfd_strtab_hash
modifier|*
name|_bfd_xcoff_stringtab_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free a string table.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|_bfd_stringtab_free
parameter_list|(
name|struct
name|bfd_strtab_hash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the size of a string table.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_size_type
name|_bfd_stringtab_size
parameter_list|(
name|struct
name|bfd_strtab_hash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a string to a string table.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_size_type
name|_bfd_stringtab_add
parameter_list|(
name|struct
name|bfd_strtab_hash
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bfd_boolean
name|hash
parameter_list|,
name|bfd_boolean
name|copy
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write out a string table.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_stringtab_emit
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|struct
name|bfd_strtab_hash
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Check that endianness of input and output file match.  */
end_comment

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_generic_verify_endian_match
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Macros to tell if bfds are read or write enabled.     Note that bfds open for read may be scribbled into if the fd passed    to bfd_fdopenr is actually open both for read and write    simultaneously.  However an output bfd will never be open for    read.  Therefore sometimes you want to check bfd_read_p or    !bfd_read_p, and only sometimes bfd_write_p. */
end_comment

begin_define
define|#
directive|define
name|bfd_read_p
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((abfd)->direction == read_direction || (abfd)->direction == both_direction)
end_define

begin_define
define|#
directive|define
name|bfd_write_p
parameter_list|(
name|abfd
parameter_list|)
define|\
value|((abfd)->direction == write_direction || (abfd)->direction == both_direction)
end_define

begin_function_decl
name|void
name|bfd_assert
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|BFD_ASSERT
parameter_list|(
name|x
parameter_list|)
define|\
value|{ if (!(x)) bfd_assert(__FILE__,__LINE__); }
end_define

begin_define
define|#
directive|define
name|BFD_FAIL
parameter_list|()
define|\
value|{ bfd_assert(__FILE__,__LINE__); }
end_define

begin_decl_stmt
specifier|extern
name|void
name|_bfd_abort
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* if gcc>= 2.6, we can give a function name, too */
end_comment

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|2
operator|||
operator|(
name|__GNUC__
operator|==
literal|2
operator|&&
name|__GNUC_MINOR__
operator|<
literal|6
operator|)
end_if

begin_define
define|#
directive|define
name|__PRETTY_FUNCTION__
value|((char *) NULL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|abort
end_undef

begin_define
define|#
directive|define
name|abort
parameter_list|()
value|_bfd_abort (__FILE__, __LINE__, __PRETTY_FUNCTION__)
end_define

begin_comment
comment|/* Manipulate a system FILE but using BFD's "file_ptr", rather than    the system "off_t" or "off64_t", as the offset.  */
end_comment

begin_function_decl
specifier|extern
name|file_ptr
name|real_ftell
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|real_fseek
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|file_ptr
name|offset
parameter_list|,
name|int
name|whence
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|bfd_cache_lookup_worker
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|bfd_last_cache
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of supported target vectors, and the default vector (if    bfd_default_vector[0] is NULL, there is no default).  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
modifier|*
specifier|const
modifier|*
name|bfd_target_vector
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
modifier|*
name|bfd_default_vector
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of associated target vectors.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|bfd_target
modifier|*
specifier|const
modifier|*
name|bfd_associated_vector
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions shared by the ECOFF and MIPS ELF backends, which have no    other common header files.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|ALMOST_STDC
argument_list|)
end_if

begin_struct_decl
struct_decl|struct
name|ecoff_find_line
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_ecoff_locate_line
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|struct
name|ecoff_debug_info
modifier|*
specifier|const
parameter_list|,
specifier|const
name|struct
name|ecoff_debug_swap
modifier|*
specifier|const
parameter_list|,
name|struct
name|ecoff_find_line
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
name|bfd_boolean
name|_bfd_ecoff_get_accumulated_pdr
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_ecoff_get_accumulated_sym
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_ecoff_get_accumulated_ss
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bfd_vma
name|_bfd_get_gp_value
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|_bfd_set_gp_value
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Function shared by the COFF and ELF SH backends, which have no    other common header files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_bfd_sh_align_load_span
end_ifndef

begin_function_decl
specifier|extern
name|bfd_boolean
name|_bfd_sh_align_load_span
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|bfd_boolean
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|bfd
modifier|*
parameter_list|,
name|asection
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_byte
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|,
name|bfd_vma
modifier|*
modifier|*
parameter_list|,
name|bfd_vma
modifier|*
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_vma
parameter_list|,
name|bfd_boolean
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

