begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* extern.h - External declarations for cpio.  Requires system.h.    Copyright (C) 1990, 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_enum
enum|enum
name|archive_format
block|{
name|arf_unknown
block|,
name|arf_binary
block|,
name|arf_oldascii
block|,
name|arf_newascii
block|,
name|arf_crcascii
block|,
name|arf_tar
block|,
name|arf_ustar
block|,
name|arf_hpoldascii
block|,
name|arf_hpbinary
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|archive_format
name|archive_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reset_time_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|io_block_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|create_dir_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rename_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|rename_batch_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|table_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|unconditional_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbose_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dot_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|link_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|retain_time_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|crc_i_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|append_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swap_bytes_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swap_halfwords_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swapping_bytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|swapping_halfwords
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|set_owner_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uid_t
name|set_owner
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|set_group_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gid_t
name|set_group
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_chown_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sparse_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|quiet_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|only_verify_crc_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_abs_paths_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|last_header_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|copy_matching_files
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numeric_uid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pattern_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|new_media_message
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|new_media_message_with_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|new_media_message_after_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|archive_des
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|archive_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|crc
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_CPIO
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|debug_flag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|input_buffer
decl_stmt|,
modifier|*
name|output_buffer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|in_buff
decl_stmt|,
modifier|*
name|out_buff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|input_buffer_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|input_size
decl_stmt|,
name|output_size
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|long
name|input_bytes
decl_stmt|,
name|output_bytes
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|long
name|input_bytes
decl_stmt|,
name|output_bytes
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|zeros_512
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|directory_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|save_patterns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_patterns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|name_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|input_is_special
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|output_is_special
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|input_is_seekable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|output_is_seekable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|f_force_local
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|xstat
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|copy_function
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
end_if

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|P_
parameter_list|(
name|s
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* copyin.c */
end_comment

begin_decl_stmt
name|void
name|read_in_header
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|in_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_in_old_ascii
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|in_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_in_new_ascii
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|in_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_in_binary
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|in_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swab_array
name|P_
argument_list|(
operator|(
name|char
operator|*
name|arg
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|process_copy_in
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|long_format
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|char
operator|*
name|link_name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_name_with_quoting
name|P_
argument_list|(
operator|(
name|char
operator|*
name|p
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* copyout.c */
end_comment

begin_decl_stmt
name|void
name|write_out_header
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|out_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|process_copy_out
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* copypass.c */
end_comment

begin_decl_stmt
name|void
name|process_copy_pass
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|link_to_maj_min_ino
name|P_
argument_list|(
operator|(
name|char
operator|*
name|file_name
operator|,
name|int
name|st_dev_maj
operator|,
name|int
name|st_dev_min
operator|,
name|int
name|st_ino
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|link_to_name
name|P_
argument_list|(
operator|(
name|char
operator|*
name|link_name
operator|,
name|char
operator|*
name|link_target
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dirname.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|dirname
name|P_
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* error.c */
end_comment

begin_decl_stmt
name|void
name|error
name|P_
argument_list|(
operator|(
name|int
name|status
operator|,
name|int
name|errnum
operator|,
name|char
operator|*
name|message
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* filemode.c */
end_comment

begin_decl_stmt
name|void
name|mode_string
name|P_
argument_list|(
operator|(
name|unsigned
name|int
name|mode
operator|,
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* idcache.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MSDOS__
end_ifndef

begin_function_decl
name|char
modifier|*
name|getgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|getuser
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|uid_t
modifier|*
name|getuidbyname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|gid_t
modifier|*
name|getgidbyname
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lchown.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LCHOWN
end_ifdef

begin_decl_stmt
name|int
name|lchown
name|P_
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|path
operator|,
name|uid_t
name|owner
operator|,
name|gid_t
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* main.c */
end_comment

begin_decl_stmt
name|void
name|process_args
name|P_
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
name|argv
index|[]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|initialize_buffers
name|P_
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* makepath.c */
end_comment

begin_decl_stmt
name|int
name|make_path
name|P_
argument_list|(
operator|(
name|char
operator|*
name|argpath
operator|,
name|int
name|mode
operator|,
name|int
name|parent_mode
operator|,
name|uid_t
name|owner
operator|,
name|gid_t
name|group
operator|,
name|char
operator|*
name|verbose_fmt_string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stripslash.c */
end_comment

begin_decl_stmt
name|void
name|strip_trailing_slashes
name|P_
argument_list|(
operator|(
name|char
operator|*
name|path
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* tar.c */
end_comment

begin_decl_stmt
name|void
name|write_out_tar_header
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|out_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|null_block
name|P_
argument_list|(
operator|(
name|long
operator|*
name|block
operator|,
name|int
name|size
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_in_tar_header
name|P_
argument_list|(
operator|(
expr|struct
name|new_cpio_header
operator|*
name|file_hdr
operator|,
name|int
name|in_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|otoa
name|P_
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|unsigned
name|long
operator|*
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_tar_header
name|P_
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_tar_filename_too_long
name|P_
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* userspec.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MSDOS__
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|parse_user_spec
name|P_
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|uid_t
operator|*
name|uid
operator|,
name|gid_t
operator|*
name|gid
operator|,
name|char
operator|*
operator|*
name|username
operator|,
name|char
operator|*
operator|*
name|groupname
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* util.c */
end_comment

begin_decl_stmt
name|void
name|tape_empty_output_buffer
name|P_
argument_list|(
operator|(
name|int
name|out_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|disk_empty_output_buffer
name|P_
argument_list|(
operator|(
name|int
name|out_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|swahw_array
name|P_
argument_list|(
operator|(
name|char
operator|*
name|ptr
operator|,
name|int
name|count
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tape_buffered_write
name|P_
argument_list|(
operator|(
name|char
operator|*
name|in_buf
operator|,
name|int
name|out_des
operator|,
name|long
name|num_bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tape_buffered_read
name|P_
argument_list|(
operator|(
name|char
operator|*
name|in_buf
operator|,
name|int
name|in_des
operator|,
name|long
name|num_bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|tape_buffered_peek
name|P_
argument_list|(
operator|(
name|char
operator|*
name|peek_buf
operator|,
name|int
name|in_des
operator|,
name|int
name|num_bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tape_toss_input
name|P_
argument_list|(
operator|(
name|int
name|in_des
operator|,
name|long
name|num_bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_files_tape_to_disk
name|P_
argument_list|(
operator|(
name|int
name|in_des
operator|,
name|int
name|out_des
operator|,
name|long
name|num_bytes
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_files_disk_to_tape
name|P_
argument_list|(
operator|(
name|int
name|in_des
operator|,
name|int
name|out_des
operator|,
name|long
name|num_bytes
operator|,
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|copy_files_disk_to_disk
name|P_
argument_list|(
operator|(
name|int
name|in_des
operator|,
name|int
name|out_des
operator|,
name|long
name|num_bytes
operator|,
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|create_all_directories
name|P_
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|prepare_append
name|P_
argument_list|(
operator|(
name|int
name|out_file_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|find_inode_file
name|P_
argument_list|(
operator|(
name|unsigned
name|long
name|node_num
operator|,
name|unsigned
name|long
name|major_num
operator|,
name|unsigned
name|long
name|minor_num
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_inode
name|P_
argument_list|(
operator|(
name|unsigned
name|long
name|node_num
operator|,
name|char
operator|*
name|file_name
operator|,
name|unsigned
name|long
name|major_num
operator|,
name|unsigned
name|long
name|minor_num
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|open_archive
name|P_
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|tape_offline
name|P_
argument_list|(
operator|(
name|int
name|tape_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|get_next_reel
name|P_
argument_list|(
operator|(
name|int
name|tape_des
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_new_media_message
name|P_
argument_list|(
operator|(
name|char
operator|*
name|message
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_decl_stmt
name|int
name|chown
name|P_
argument_list|(
operator|(
name|char
operator|*
name|path
operator|,
name|int
name|owner
operator|,
name|int
name|group
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_decl_stmt
name|int
name|utime
name|P_
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
expr|struct
name|utimbuf
operator|*
name|utb
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_CDF
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|add_cdf_double_slashes
name|P_
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* xmalloc.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xmalloc
name|P_
argument_list|(
operator|(
name|unsigned
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|xrealloc
name|P_
argument_list|(
operator|(
name|char
operator|*
name|p
operator|,
name|unsigned
name|n
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* xstrdup.c */
end_comment

begin_decl_stmt
name|char
modifier|*
name|xstrdup
name|P_
argument_list|(
operator|(
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DISK_IO_BLOCK_SIZE
value|(512)
end_define

end_unit

