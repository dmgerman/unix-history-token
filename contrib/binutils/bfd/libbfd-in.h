begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* libbfd.h -- Declarations used by bfd library *implementation*.    (This include file is not for users of the library.)    Copyright 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 1998, 1999,    2000, 2001    Free Software Foundation, Inc.    Written by Cygnus Support.  ** NOTE: libbfd.h is a GENERATED file.  Don't change it; instead, ** change libbfd-in.h or the other BFD source files processed to ** generate this file.  This file is part of BFD, the Binary File Descriptor library.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|((((bfd_vma) (this) + (boundary) - 1)>= (bfd_vma) (this))		\    ? (((bfd_vma) (this) + ((boundary) - 1))& (~((boundary)-1)))	\    : ~ (bfd_vma) 0)
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
value|((bfd)->tdata.any = (PTR) (v))
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
name|PTR
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

begin_decl_stmt
specifier|extern
name|PTR
name|bfd_malloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|bfd_realloc
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|bfd_zmalloc
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_error_handler_type
name|_bfd_error_handler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These routines allocate and free things on the BFD's objalloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|PTR
name|bfd_alloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|bfd_zalloc
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|bfd_release
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|_bfd_create_empty_archive_element_shell
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|obfd
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|_bfd_look_for_bfd_in_cache
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|arch_bfd
operator|,
name|file_ptr
name|index
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_add_bfd_to_archive_cache
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|file_ptr
operator|,
name|bfd
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_generic_mkarchive
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
specifier|const
name|bfd_target
modifier|*
name|bfd_generic_archive_p
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
name|boolean
name|bfd_slurp_armap
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
name|boolean
name|bfd_slurp_bsd_armap_f2
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
name|bfd_slurp_bsd_armap
value|bfd_slurp_armap
end_define

begin_define
define|#
directive|define
name|bfd_slurp_coff_armap
value|bfd_slurp_armap
end_define

begin_decl_stmt
name|boolean
name|_bfd_slurp_extended_name_table
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
name|boolean
name|_bfd_construct_extended_name_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|boolean
operator|,
name|char
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|_bfd_write_archive_contents
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
name|boolean
name|_bfd_compute_and_write_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|unsigned
name|int
name|elength
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|_bfd_get_elt_at_filepos
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|archive
operator|,
name|file_ptr
name|filepos
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd
modifier|*
name|_bfd_generic_get_elt_at_index
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|symindex
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|_bfd_new_bfd
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_false
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bfd_true
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PTR
name|bfd_nullvoidptr
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bfd_0
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|bfd_0u
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|bfd_0l
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|_bfd_n1
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_void
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|ignore
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bfd
modifier|*
name|_bfd_new_bfd_contained_in
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
specifier|const
name|bfd_target
modifier|*
name|_bfd_dummy_target
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
name|void
name|bfd_dont_truncate_arname
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|hdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_bsd_truncate_arname
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|hdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|bfd_gnu_truncate_arname
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|abfd
operator|,
specifier|const
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|hdr
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|bsd_write_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|arch
operator|,
name|unsigned
name|int
name|elength
operator|,
expr|struct
name|orl
operator|*
name|map
operator|,
name|unsigned
name|int
name|orl_count
operator|,
name|int
name|stridx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|boolean
name|coff_write_armap
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|arch
operator|,
name|unsigned
name|int
name|elength
operator|,
expr|struct
name|orl
operator|*
name|map
operator|,
name|unsigned
name|int
name|orl_count
operator|,
name|int
name|stridx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|_bfd_generic_read_ar_hdr
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
name|PTR
name|_bfd_generic_read_ar_hdr_mag
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

begin_decl_stmt
name|bfd
modifier|*
name|bfd_generic_openr_next_archived_file
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
name|archive
operator|,
name|bfd
operator|*
name|last_file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bfd_generic_stat_arch_elt
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|((boolean (*) PARAMS ((bfd *, asection *))) bfd_true)
end_define

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_get_section_contents
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
name|offset
operator|,
name|bfd_size_type
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_get_section_contents_in_window
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_window
operator|*
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic routines to use for BFD_JUMP_TABLE_COPY.  Use    BFD_JUMP_TABLE_COPY (_bfd_generic).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_bfd_data
define|\
value|((boolean (*) PARAMS ((bfd *, bfd *))) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_merge_private_bfd_data
define|\
value|((boolean (*) PARAMS ((bfd *, bfd *))) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_set_private_flags
define|\
value|((boolean (*) PARAMS ((bfd *, flagword))) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_section_data
define|\
value|((boolean (*) PARAMS ((bfd *, asection *, bfd *, asection *))) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_copy_private_symbol_data
define|\
value|((boolean (*) PARAMS ((bfd *, asymbol *, bfd *, asymbol *))) bfd_true)
end_define

begin_define
define|#
directive|define
name|_bfd_generic_bfd_print_private_bfd_data
define|\
value|((boolean (*) PARAMS ((bfd *, PTR))) bfd_true)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_CORE when there is no core file    support.  Use BFD_JUMP_TABLE_CORE (_bfd_nocore).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|_bfd_nocore_core_file_failing_command
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
name|int
name|_bfd_nocore_core_file_failing_signal
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
name|_bfd_nocore_core_file_matches_executable_p
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
value|((boolean (*) PARAMS ((bfd *, char **, bfd_size_type *, const char **))) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_truncate_arname
define|\
value|((void (*) PARAMS ((bfd *, const char *, char *))) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_write_armap
define|\
value|((boolean (*) \     PARAMS ((bfd *, unsigned int, struct orl *, unsigned int, int))) \    bfd_false)
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
value|((bfd *(*) PARAMS ((bfd *, bfd *))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_noarchive_get_elt_at_index
define|\
value|((bfd *(*) PARAMS ((bfd *, symindex))) bfd_nullvoidptr)
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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_archive_bsd_construct_extended_name_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_archive_bsd_update_armap_timestamp
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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_archive_coff_construct_extended_name_table
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|bfd_size_type
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|_bfd_nosymbols_get_symtab
define|\
value|((long (*) PARAMS ((bfd *, asymbol **))) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_make_empty_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_print_symbol
define|\
value|((void (*) PARAMS ((bfd *, PTR, asymbol *, bfd_print_symbol_type))) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_get_symbol_info
define|\
value|((void (*) PARAMS ((bfd *, asymbol *, symbol_info *))) bfd_void)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_bfd_is_local_label_name
define|\
value|((boolean (*) PARAMS ((bfd *, const char *))) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_get_lineno
define|\
value|((alent *(*) PARAMS ((bfd *, asymbol *))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_find_nearest_line
define|\
value|((boolean (*) \     PARAMS ((bfd *, asection *, asymbol **, bfd_vma, const char **, \ 	     const char **, unsigned int *))) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_bfd_make_debug_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *, PTR, unsigned long))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_read_minisymbols
define|\
value|((long (*) PARAMS ((bfd *, boolean, PTR *, unsigned int *))) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_nosymbols_minisymbol_to_symbol
define|\
value|((asymbol *(*) PARAMS ((bfd *, boolean, const PTR, asymbol *))) \    bfd_nullvoidptr)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_RELOCS when there is no reloc    support.  Use BFD_JUMP_TABLE_RELOCS (_bfd_norelocs).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_norelocs_get_reloc_upper_bound
define|\
value|((long (*) PARAMS ((bfd *, asection *))) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_norelocs_canonicalize_reloc
define|\
value|((long (*) PARAMS ((bfd *, asection *, arelent **, asymbol **))) _bfd_n1)
end_define

begin_define
define|#
directive|define
name|_bfd_norelocs_bfd_reloc_type_lookup
define|\
value|((reloc_howto_type *(*) PARAMS ((bfd *, bfd_reloc_code_real_type))) \    bfd_nullvoidptr)
end_define

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_WRITE for targets which may not    be written.  Use BFD_JUMP_TABLE_WRITE (_bfd_nowrite).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nowrite_set_arch_mach
define|\
value|((boolean (*) PARAMS ((bfd *, enum bfd_architecture, unsigned long))) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nowrite_set_section_contents
define|\
value|((boolean (*) PARAMS ((bfd *, asection *, PTR, file_ptr, bfd_size_type))) \    bfd_false)
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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_set_section_contents
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
operator|,
name|file_ptr
operator|,
name|bfd_size_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Routines to use for BFD_JUMP_TABLE_LINK for targets which do not    support linking.  Use BFD_JUMP_TABLE_LINK (_bfd_nolink).  */
end_comment

begin_define
define|#
directive|define
name|_bfd_nolink_sizeof_headers
value|((int (*) PARAMS ((bfd *, boolean))) bfd_0)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_get_relocated_section_contents
define|\
value|((bfd_byte *(*) \     PARAMS ((bfd *, struct bfd_link_info *, struct bfd_link_order *, \ 	     bfd_byte *, boolean, asymbol **))) \    bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_relax_section
define|\
value|((boolean (*) \     PARAMS ((bfd *, asection *, struct bfd_link_info *, boolean *))) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_gc_sections
define|\
value|((boolean (*) \     PARAMS ((bfd *, struct bfd_link_info *))) \    bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_hash_table_create
define|\
value|((struct bfd_link_hash_table *(*) PARAMS ((bfd *))) bfd_nullvoidptr)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_add_symbols
define|\
value|((boolean (*) PARAMS ((bfd *, struct bfd_link_info *))) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_final_link
define|\
value|((boolean (*) PARAMS ((bfd *, struct bfd_link_info *))) bfd_false)
end_define

begin_define
define|#
directive|define
name|_bfd_nolink_bfd_link_split_section
define|\
value|((boolean (*) PARAMS ((bfd *, struct sec *))) bfd_false)
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
value|((long (*) PARAMS ((bfd *, asymbol **))) _bfd_n1)
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
value|((long (*) PARAMS ((bfd *, arelent **, asymbol **))) _bfd_n1)
end_define

begin_escape
end_escape

begin_comment
comment|/* Generic routine to determine of the given symbol is a local    label.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|bfd_generic_is_local_label_name
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

begin_comment
comment|/* Generic minisymbol routines.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|_bfd_generic_read_minisymbols
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|boolean
operator|,
name|PTR
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|asymbol
modifier|*
name|_bfd_generic_minisymbol_to_symbol
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|boolean
operator|,
specifier|const
name|PTR
operator|,
name|asymbol
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the nearest line using .stab/.stabstr sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_stab_section_find_nearest_line
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asymbol
operator|*
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|,
name|boolean
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|,
name|PTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the neaderst line using DWARF 1 debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_dwarf1_find_nearest_line
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
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the nearest line using DWARF 2 debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_dwarf2_find_nearest_line
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
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|,
name|unsigned
name|int
operator|,
name|PTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A routine to create entries for a bfd_link_hash_table.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_hash_entry
modifier|*
name|_bfd_link_hash_newfunc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_hash_entry
operator|*
name|entry
operator|,
expr|struct
name|bfd_hash_table
operator|*
name|table
operator|,
specifier|const
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize a bfd_link_hash_table.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_link_hash_table_init
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_hash_table
operator|*
operator|,
name|bfd
operator|*
operator|,
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
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic link hash table creation routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_link_hash_table
modifier|*
name|_bfd_generic_link_hash_table_create
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
comment|/* Generic add symbol routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_add_symbols
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
comment|/* Generic add symbol routine.  This version is used by targets for    which the linker must collect constructors and destructors by name,    as the collect2 program does.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_add_symbols_collect
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
comment|/* Generic archive add symbol routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_add_archive_symbols
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|boolean
argument_list|(
operator|*
name|checkfn
argument_list|)
argument_list|(
name|bfd
operator|*
argument_list|,
expr|struct
name|bfd_link_info
operator|*
argument_list|,
name|boolean
operator|*
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_link_add_one_symbol
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_info
operator|*
operator|,
name|bfd
operator|*
operator|,
specifier|const
name|char
operator|*
name|name
operator|,
name|flagword
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|,
specifier|const
name|char
operator|*
operator|,
name|boolean
name|copy
operator|,
name|boolean
name|constructor
operator|,
expr|struct
name|bfd_link_hash_entry
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic link routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_final_link
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
name|_bfd_generic_link_split_section
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|sec
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generic reloc_link_order processing routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_reloc_link_order
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|bfd_link_order
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default link order processing routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_default_link_order
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_link_info
operator|*
operator|,
name|asection
operator|*
operator|,
expr|struct
name|bfd_link_order
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count the number of reloc entries in a link order list.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|_bfd_count_link_order_relocs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_link_order
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Final link relocation routine.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_reloc_status_type
name|_bfd_final_link_relocate
name|PARAMS
argument_list|(
operator|(
name|reloc_howto_type
operator|*
operator|,
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_byte
operator|*
operator|,
name|bfd_vma
name|address
operator|,
name|bfd_vma
name|value
operator|,
name|bfd_vma
name|addend
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relocate a particular location by a howto and a value.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_reloc_status_type
name|_bfd_relocate_contents
name|PARAMS
argument_list|(
operator|(
name|reloc_howto_type
operator|*
operator|,
name|bfd
operator|*
operator|,
name|bfd_vma
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Link stabs in sections in the first pass.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_link_section_stabs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|*
operator|,
name|asection
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out the .stab section when linking stabs in sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_write_section_stabs
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
operator|*
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out the .stabstr string table when linking stabs in sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_write_stab_strings
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find an offset within a .stab section when linking stabs in    sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_vma
name|_bfd_stab_section_offset
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|PTR
operator|*
operator|,
name|asection
operator|*
operator|,
name|PTR
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create a string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_strtab_hash
modifier|*
name|_bfd_stringtab_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create an XCOFF .debug section style string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|bfd_strtab_hash
modifier|*
name|_bfd_xcoff_stringtab_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Free a string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_bfd_stringtab_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_strtab_hash
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the size of a string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_size_type
name|_bfd_stringtab_size
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_strtab_hash
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a string to a string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|bfd_size_type
name|_bfd_stringtab_add
name|PARAMS
argument_list|(
operator|(
expr|struct
name|bfd_strtab_hash
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|boolean
name|hash
operator|,
name|boolean
name|copy
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write out a string table.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_stringtab_emit
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
expr|struct
name|bfd_strtab_hash
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check that endianness of input and output file match.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_generic_verify_endian_match
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
value|((abfd)->direction == read_direction || (abfd)->direction == both_direction)
end_define

begin_define
define|#
directive|define
name|bfd_write_p
parameter_list|(
name|abfd
parameter_list|)
value|((abfd)->direction == write_direction || (abfd)->direction == both_direction)
end_define

begin_decl_stmt
name|void
name|bfd_assert
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
specifier|const
name|char
operator|*
operator|)
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

begin_decl_stmt
name|FILE
modifier|*
name|bfd_cache_lookup_worker
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

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_locate_line
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_vma
operator|,
expr|struct
name|ecoff_debug_info
operator|*
specifier|const
operator|,
specifier|const
expr|struct
name|ecoff_debug_swap
operator|*
specifier|const
operator|,
expr|struct
name|ecoff_find_line
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
specifier|const
name|char
operator|*
operator|*
operator|,
name|unsigned
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_get_accumulated_pdr
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_get_accumulated_sym
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_ecoff_get_accumulated_ss
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
name|bfd_byte
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bfd_vma
name|_bfd_get_gp_value
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
name|void
name|_bfd_set_gp_value
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|bfd_vma
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Function shared by the COFF and ELF SH backends, which have no    other common header files.  */
end_comment

begin_decl_stmt
specifier|extern
name|boolean
name|_bfd_sh_align_load_span
name|PARAMS
argument_list|(
operator|(
name|bfd
operator|*
operator|,
name|asection
operator|*
operator|,
name|bfd_byte
operator|*
operator|,
name|boolean
argument_list|(
operator|*
argument_list|)
argument_list|(
name|bfd
operator|*
argument_list|,
name|asection
operator|*
argument_list|,
name|PTR
argument_list|,
name|bfd_byte
operator|*
argument_list|,
name|bfd_vma
argument_list|)
operator|,
name|PTR
operator|,
name|bfd_vma
operator|*
operator|*
operator|,
name|bfd_vma
operator|*
operator|,
name|bfd_vma
operator|,
name|bfd_vma
operator|,
name|boolean
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* And more follows */
end_comment

end_unit

