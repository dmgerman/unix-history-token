begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* global.c - global variables and initial values for cpio.    Copyright (C) 1990, 1991, 1992 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"cpiohdr.h"
end_include

begin_include
include|#
directive|include
file|"dstring.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_comment
comment|/* If TRUE, reset access times after reading files (-a).  */
end_comment

begin_decl_stmt
name|int
name|reset_time_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Block size value, initially 512.  -B sets to 5120.  */
end_comment

begin_decl_stmt
name|int
name|io_block_size
init|=
literal|512
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The header format to recognize and produce.  */
end_comment

begin_decl_stmt
name|enum
name|archive_format
name|archive_format
init|=
name|arf_unknown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, create directories as needed. (-d with -i or -p) */
end_comment

begin_decl_stmt
name|int
name|create_dir_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, interactively rename files. (-r) */
end_comment

begin_decl_stmt
name|int
name|rename_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-NULL, the name of a file that will be read to    rename all of the files in the archive.  --rename-batch-file.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rename_batch_file
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, print a table of contents of input. (-t) */
end_comment

begin_decl_stmt
name|int
name|table_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, copy unconditionally (older replaces newer). (-u) */
end_comment

begin_decl_stmt
name|int
name|unconditional_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, list the files processed, or ls -l style output with -t. (-v) */
end_comment

begin_decl_stmt
name|int
name|verbose_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, print a . for each file processed. (-V) */
end_comment

begin_decl_stmt
name|int
name|dot_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, link files whenever possible.  Used with -p option. (-l) */
end_comment

begin_decl_stmt
name|int
name|link_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, retain previous file modification time. (-m) */
end_comment

begin_decl_stmt
name|int
name|retain_time_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set TRUE if crc_flag is TRUE and we are doing a cpio -i.  Used    by copy_files so it knows whether to compute the crc.  */
end_comment

begin_decl_stmt
name|int
name|crc_i_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, append to end of archive. (-A) */
end_comment

begin_decl_stmt
name|int
name|append_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, swap bytes of each file during cpio -i.  */
end_comment

begin_decl_stmt
name|int
name|swap_bytes_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, swap halfwords of each file during cpio -i.  */
end_comment

begin_decl_stmt
name|int
name|swap_halfwords_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, we are swapping halfwords on the current file.  */
end_comment

begin_decl_stmt
name|int
name|swapping_halfwords
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, we are swapping bytes on the current file.  */
end_comment

begin_decl_stmt
name|int
name|swapping_bytes
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, set ownership of all files to UID `set_owner'.  */
end_comment

begin_decl_stmt
name|int
name|set_owner_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uid_t
name|set_owner
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, set group ownership of all files to GID `set_group'.  */
end_comment

begin_decl_stmt
name|int
name|set_group_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gid_t
name|set_group
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, do not chown the files.  */
end_comment

begin_decl_stmt
name|int
name|no_chown_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, try to write sparse ("holey") files.  */
end_comment

begin_decl_stmt
name|int
name|sparse_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, don't report number of blocks copied.  */
end_comment

begin_decl_stmt
name|int
name|quiet_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, only read the archive and verify the files' CRC's, don't    actually extract the files. */
end_comment

begin_decl_stmt
name|int
name|only_verify_crc_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If TRUE, don't use any absolute paths, prefix them by `./'.  */
end_comment

begin_decl_stmt
name|int
name|no_abs_paths_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_CPIO
end_ifdef

begin_comment
comment|/* If TRUE, print debugging information.  */
end_comment

begin_decl_stmt
name|int
name|debug_flag
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* File position of last header read.  Only used during -A to determine    where the old TRAILER!!! record started.  */
end_comment

begin_decl_stmt
name|int
name|last_header_start
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* With -i; if TRUE, copy only files that match any of the given patterns;    if FALSE, copy only files that do not match any of the patterns. (-f) */
end_comment

begin_decl_stmt
name|int
name|copy_matching_files
init|=
name|TRUE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* With -itv; if TRUE, list numeric uid and gid instead of translating them    into names.  */
end_comment

begin_decl_stmt
name|int
name|numeric_uid
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of file containing additional patterns (-E).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pattern_file_name
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Message to print when end of medium is reached (-M).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|new_media_message
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* With -M with %d, message to print when end of medium is reached.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|new_media_message_with_number
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|new_media_message_after_number
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* File descriptor containing the archive.  */
end_comment

begin_decl_stmt
name|int
name|archive_des
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of file containing the archive, if known; NULL if stdin/out.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|archive_name
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CRC checksum.  */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|crc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Input and output buffers.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|input_buffer
decl_stmt|,
modifier|*
name|output_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The size of the input buffer.  */
end_comment

begin_decl_stmt
name|long
name|input_buffer_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current locations in `input_buffer' and `output_buffer'.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|in_buff
decl_stmt|,
modifier|*
name|out_buff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current number of bytes stored at `input_buff' and `output_buff'.  */
end_comment

begin_decl_stmt
name|long
name|input_size
decl_stmt|,
name|output_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Total number of bytes read and written for all files.      Now that many tape drives hold more than 4Gb we need more than 32    bits to hold input_bytes and output_bytes.  But it's not worth    the trouble of adding special multi-precision arithmetic if the     compiler doesn't support 64 bit ints since input_bytes and    output_bytes are only used to print the number of blocks copied.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_decl_stmt
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

begin_comment
comment|/* 512 bytes of 0; used for various padding operations.  */
end_comment

begin_decl_stmt
name|char
name|zeros_512
index|[
literal|512
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Saving of argument values for later reference.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|directory_name
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|save_patterns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|num_patterns
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Character that terminates file names read from stdin.  */
end_comment

begin_decl_stmt
name|char
name|name_end
init|=
literal|'\n'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if input (cpio -i) or output (cpio -o) is a device node.  */
end_comment

begin_decl_stmt
name|char
name|input_is_special
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|output_is_special
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if lseek works on the input.  */
end_comment

begin_decl_stmt
name|char
name|input_is_seekable
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TRUE if lseek works on the output.  */
end_comment

begin_decl_stmt
name|char
name|output_is_seekable
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If nonzero, don't consider file names that contain a `:' to be    on remote hosts; all files are local.  */
end_comment

begin_decl_stmt
name|int
name|f_force_local
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The name this program was run with.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A pointer to either lstat or stat, depending on whether    dereferencing of symlinks is done for input files.  */
end_comment

begin_function_decl
name|int
function_decl|(
modifier|*
name|xstat
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Which copy operation to perform. (-i, -o, -p) */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|copy_function
function_decl|)
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

end_unit

