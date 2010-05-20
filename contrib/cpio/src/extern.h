begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* extern.h - External declarations for cpio.  Requires system.h.    Copyright (C) 1990, 1991, 1992, 2001, 2006 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public    License along with this program; if not, write to the Free    Software Foundation, Inc., 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301 USA.  */
end_comment

begin_include
include|#
directive|include
file|"paxlib.h"
end_include

begin_include
include|#
directive|include
file|"quotearg.h"
end_include

begin_include
include|#
directive|include
file|"quote.h"
end_include

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
name|abs_paths_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|warn_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values for warn_option */
end_comment

begin_define
define|#
directive|define
name|CPIO_WARN_NONE
value|0
end_define

begin_define
define|#
directive|define
name|CPIO_WARN_TRUNCATE
value|0x01
end_define

begin_define
define|#
directive|define
name|CPIO_WARN_ALL
value|(unsigned int)-1
end_define

begin_decl_stmt
specifier|extern
name|bool
name|to_stdout_option
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
name|char
modifier|*
name|rsh_command_option
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|crc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|delayed_seek_count
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

begin_comment
comment|/* copyin.c */
end_comment

begin_function_decl
name|void
name|warn_junk_bytes
parameter_list|(
name|long
name|bytes_skipped
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: make read_* static in copyin.c */
end_comment

begin_function_decl
name|void
name|read_in_header
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|in_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_in_old_ascii
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|in_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_in_new_ascii
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|in_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_in_binary
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|struct
name|old_cpio_header
modifier|*
name|short_hdr
parameter_list|,
name|int
name|in_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swab_array
parameter_list|(
name|char
modifier|*
name|arg
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_copy_in
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|long_format
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|char
modifier|*
name|link_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_name_with_quoting
parameter_list|(
name|char
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* copyout.c */
end_comment

begin_function_decl
name|int
name|write_out_header
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|out_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_copy_out
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* copypass.c */
end_comment

begin_function_decl
name|void
name|process_copy_pass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link_to_maj_min_ino
parameter_list|(
name|char
modifier|*
name|file_name
parameter_list|,
name|int
name|st_dev_maj
parameter_list|,
name|int
name|st_dev_min
parameter_list|,
name|int
name|st_ino
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|link_to_name
parameter_list|(
name|char
modifier|*
name|link_name
parameter_list|,
name|char
modifier|*
name|link_target
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dirname.c */
end_comment

begin_function_decl
name|char
modifier|*
name|dirname
parameter_list|(
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* filemode.c */
end_comment

begin_function_decl
name|void
name|mode_string
parameter_list|(
name|unsigned
name|int
name|mode
parameter_list|,
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* main.c */
end_comment

begin_function_decl
name|void
name|process_args
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initialize_buffers
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* makepath.c */
end_comment

begin_function_decl
name|int
name|make_path
parameter_list|(
name|char
modifier|*
name|argpath
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|parent_mode
parameter_list|,
name|uid_t
name|owner
parameter_list|,
name|gid_t
name|group
parameter_list|,
name|char
modifier|*
name|verbose_fmt_string
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* tar.c */
end_comment

begin_function_decl
name|void
name|write_out_tar_header
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|out_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|null_block
parameter_list|(
name|long
modifier|*
name|block
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|read_in_tar_header
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|file_hdr
parameter_list|,
name|int
name|in_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|otoa
parameter_list|(
name|char
modifier|*
name|s
parameter_list|,
name|unsigned
name|long
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_tar_header
parameter_list|(
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_tar_filename_too_long
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* userspec.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__MSDOS__
end_ifndef

begin_function_decl
name|char
modifier|*
name|parse_user_spec
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|uid_t
modifier|*
name|uid
parameter_list|,
name|gid_t
modifier|*
name|gid
parameter_list|,
name|char
modifier|*
modifier|*
name|username
parameter_list|,
name|char
modifier|*
modifier|*
name|groupname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* util.c */
end_comment

begin_function_decl
name|void
name|tape_empty_output_buffer
parameter_list|(
name|int
name|out_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|disk_empty_output_buffer
parameter_list|(
name|int
name|out_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|swahw_array
parameter_list|(
name|char
modifier|*
name|ptr
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tape_buffered_write
parameter_list|(
name|char
modifier|*
name|in_buf
parameter_list|,
name|int
name|out_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tape_buffered_read
parameter_list|(
name|char
modifier|*
name|in_buf
parameter_list|,
name|int
name|in_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tape_buffered_peek
parameter_list|(
name|char
modifier|*
name|peek_buf
parameter_list|,
name|int
name|in_des
parameter_list|,
name|int
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tape_toss_input
parameter_list|(
name|int
name|in_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_files_tape_to_disk
parameter_list|(
name|int
name|in_des
parameter_list|,
name|int
name|out_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_files_disk_to_tape
parameter_list|(
name|int
name|in_des
parameter_list|,
name|int
name|out_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|copy_files_disk_to_disk
parameter_list|(
name|int
name|in_des
parameter_list|,
name|int
name|out_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|,
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|warn_if_file_changed
parameter_list|(
name|char
modifier|*
name|file_name
parameter_list|,
name|unsigned
name|long
name|old_file_size
parameter_list|,
name|off_t
name|old_file_mtime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|create_all_directories
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|prepare_append
parameter_list|(
name|int
name|out_file_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|find_inode_file
parameter_list|(
name|unsigned
name|long
name|node_num
parameter_list|,
name|unsigned
name|long
name|major_num
parameter_list|,
name|unsigned
name|long
name|minor_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_inode
parameter_list|(
name|unsigned
name|long
name|node_num
parameter_list|,
name|char
modifier|*
name|file_name
parameter_list|,
name|unsigned
name|long
name|major_num
parameter_list|,
name|unsigned
name|long
name|minor_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|open_archive
parameter_list|(
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tape_offline
parameter_list|(
name|int
name|tape_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_next_reel
parameter_list|(
name|int
name|tape_des
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_new_media_message
parameter_list|(
name|char
modifier|*
name|message
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
name|int
name|chown
parameter_list|(
name|char
modifier|*
name|path
parameter_list|,
name|int
name|owner
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__TURBOC__
end_ifdef

begin_function_decl
name|int
name|utime
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|,
name|struct
name|utimbuf
modifier|*
name|utb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_CDF
end_ifdef

begin_function_decl
name|char
modifier|*
name|add_cdf_double_slashes
parameter_list|(
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|write_nuls_to_file
parameter_list|(
name|off_t
name|num_bytes
parameter_list|,
name|int
name|out_des
parameter_list|,
name|void
function_decl|(
modifier|*
name|writer
function_decl|)
parameter_list|(
name|char
modifier|*
name|in_buf
parameter_list|,
name|int
name|out_des
parameter_list|,
name|off_t
name|num_bytes
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DISK_IO_BLOCK_SIZE
value|512
end_define

begin_comment
comment|/* FIXME: Move to system.h? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMLINK_USES_UMASK
end_ifndef

begin_define
define|#
directive|define
name|UMASKED_SYMLINK
parameter_list|(
name|name1
parameter_list|,
name|name2
parameter_list|,
name|mode
parameter_list|)
value|symlink(name1,name2)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMASKED_SYMLINK
parameter_list|(
name|name1
parameter_list|,
name|name2
parameter_list|,
name|mode
parameter_list|)
value|umasked_symlink(name1,name2,mode)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYMLINK_USES_UMASK */
end_comment

begin_function_decl
name|void
name|set_perms
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|cpio_file_stat
modifier|*
name|header
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_file_times
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|long
name|atime
parameter_list|,
name|unsigned
name|long
name|mtime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|stat_to_cpio
parameter_list|(
name|struct
name|cpio_file_stat
modifier|*
name|hdr
parameter_list|,
name|struct
name|stat
modifier|*
name|st
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpio_safer_name_suffix
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|bool
name|link_target
parameter_list|,
name|bool
name|absolute_names
parameter_list|,
name|bool
name|strip_leading_dots
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: These two defines should be defined in paxutils */
end_comment

begin_define
define|#
directive|define
name|LG_8
value|3
end_define

begin_define
define|#
directive|define
name|LG_16
value|4
end_define

begin_function_decl
name|uintmax_t
name|from_ascii
parameter_list|(
name|char
specifier|const
modifier|*
name|where
parameter_list|,
name|size_t
name|digs
parameter_list|,
name|unsigned
name|logbase
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FROM_OCTAL
parameter_list|(
name|f
parameter_list|)
value|from_ascii (f, sizeof f, LG_8)
end_define

begin_define
define|#
directive|define
name|FROM_HEX
parameter_list|(
name|f
parameter_list|)
value|from_ascii (f, sizeof f, LG_16)
end_define

end_unit

