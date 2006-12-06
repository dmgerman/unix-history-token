begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common declarations for the tar program.     Copyright 1988, 1992, 1993, 1994, 1996, 1997, 1999, 2000, 2001 Free    Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published by the    Free Software Foundation; either version 2, or (at your option) any later    version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General    Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation, Inc.,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Declare the GNU tar archive format.  */
end_comment

begin_include
include|#
directive|include
file|"tar.h"
end_include

begin_comment
comment|/* The checksum field is filled with this while the checksum is computed.  */
end_comment

begin_define
define|#
directive|define
name|CHKBLANKS
value|"        "
end_define

begin_comment
comment|/* 8 blanks, no null */
end_comment

begin_comment
comment|/* Some constants from POSIX are given names.  */
end_comment

begin_define
define|#
directive|define
name|NAME_FIELD_SIZE
value|100
end_define

begin_define
define|#
directive|define
name|PREFIX_FIELD_SIZE
value|155
end_define

begin_define
define|#
directive|define
name|UNAME_FIELD_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|GNAME_FIELD_SIZE
value|32
end_define

begin_escape
end_escape

begin_comment
comment|/* Some various global definitions.  */
end_comment

begin_comment
comment|/* Name of file to use for interacting with user.  */
end_comment

begin_if
if|#
directive|if
name|MSDOS
end_if

begin_define
define|#
directive|define
name|TTY_NAME
value|"con"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TTY_NAME
value|"/dev/tty"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GLOBAL is defined to empty in tar.c only, and left alone in other *.c    modules.  Here, we merely set it to "extern" if it is not already set.    GNU tar does depend on the system loader to preset all GLOBAL variables to    neutral (or zero) values, explicit initialization is usually not done.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|GLOBAL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Exit status for GNU tar.  Let's try to keep this list as simple as    possible.  -d option strongly invites a status different for unequal    comparison and other errors.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|exit_status
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TAREXIT_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|TAREXIT_DIFFERS
value|1
end_define

begin_define
define|#
directive|define
name|TAREXIT_FAILURE
value|2
end_define

begin_comment
comment|/* Both WARN and ERROR write a message on stderr and continue processing,    however ERROR manages so tar will exit unsuccessfully.  FATAL_ERROR    writes a message on stderr and aborts immediately, with another message    line telling so.  USAGE_ERROR works like FATAL_ERROR except that the    other message line suggests trying --help.  All four macros accept a    single argument of the form ((0, errno, _("FORMAT"), Args...)).  errno    is zero when the error is not being detected by the system.  */
end_comment

begin_define
define|#
directive|define
name|WARN
parameter_list|(
name|Args
parameter_list|)
define|\
value|error Args
end_define

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, exit_status = TAREXIT_FAILURE)
end_define

begin_define
define|#
directive|define
name|FATAL_ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, fatal_exit ())
end_define

begin_define
define|#
directive|define
name|USAGE_ERROR
parameter_list|(
name|Args
parameter_list|)
define|\
value|(error Args, usage (TAREXIT_FAILURE))
end_define

begin_escape
end_escape

begin_comment
comment|/* Information gleaned from the command line.  */
end_comment

begin_include
include|#
directive|include
file|"arith.h"
end_include

begin_include
include|#
directive|include
file|<backupfile.h>
end_include

begin_include
include|#
directive|include
file|<exclude.h>
end_include

begin_include
include|#
directive|include
file|<modechange.h>
end_include

begin_include
include|#
directive|include
file|<safe-read.h>
end_include

begin_include
include|#
directive|include
file|<full-write.h>
end_include

begin_comment
comment|/* Log base 2 of common values.  */
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
name|LG_64
value|6
end_define

begin_define
define|#
directive|define
name|LG_256
value|8
end_define

begin_comment
comment|/* Name of this program.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Main command option.  */
end_comment

begin_enum
enum|enum
name|subcommand
block|{
name|UNKNOWN_SUBCOMMAND
block|,
comment|/* none of the following */
name|APPEND_SUBCOMMAND
block|,
comment|/* -r */
name|CAT_SUBCOMMAND
block|,
comment|/* -A */
name|CREATE_SUBCOMMAND
block|,
comment|/* -c */
name|DELETE_SUBCOMMAND
block|,
comment|/* -D */
name|DIFF_SUBCOMMAND
block|,
comment|/* -d */
name|EXTRACT_SUBCOMMAND
block|,
comment|/* -x */
name|LIST_SUBCOMMAND
block|,
comment|/* -t */
name|UPDATE_SUBCOMMAND
comment|/* -u */
block|}
enum|;
end_enum

begin_decl_stmt
name|GLOBAL
name|enum
name|subcommand
name|subcommand_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Selected format for output archive.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|enum
name|archive_format
name|archive_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Either NL or NUL, as decided by the --null option.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
name|filename_terminator
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Size of each record, once in blocks, once in bytes.  Those two variables    are always related, the second being BLOCKSIZE times the first.  They do    not have _option in their name, even if their values is derived from    option decoding, as these are especially important in tar.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|blocking_factor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|size_t
name|record_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|absolute_names_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allow GNUTYPE_NAMES type? */
end_comment

begin_decl_stmt
name|GLOBAL
name|bool
name|allow_name_mangling_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This variable tells how to interpret newer_mtime_option, below.  If zero,    files get archived if their mtime is not less than newer_mtime_option.    If nonzero, files get archived if *either* their ctime or mtime is not less    than newer_mtime_option.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|after_date_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|atime_preserve_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|backup_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type of backups being made.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|enum
name|backup_type
name|backup_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|block_number_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|checkpoint_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified name of compression program, or "gzip" as implied by -z.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|use_compress_program_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|dereference_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Patterns that match file names to be excluded.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|exclude
modifier|*
name|excluded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|fast_read_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified file containing names to work on.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|files_from_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|force_local_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified value to be put into tar file in place of stat () results, or    just -1 if such an override should not take place.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|gid_t
name|group_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|ignore_failed_read_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|ignore_zeros_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|incremental_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified name of script to run at end of each tape change.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|info_script_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|interactive_option
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|old_files
block|{
name|DEFAULT_OLD_FILES
block|,
comment|/* default */
name|UNLINK_FIRST_OLD_FILES
block|,
comment|/* --unlink-first */
name|KEEP_OLD_FILES
block|,
comment|/* --keep-old-files */
name|OVERWRITE_OLD_DIRS
block|,
comment|/* --overwrite-dir */
name|OVERWRITE_OLD_FILES
comment|/* --overwrite */
block|}
enum|;
end_enum

begin_decl_stmt
name|GLOBAL
name|enum
name|old_files
name|old_files_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified file name for incremental list.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|listed_incremental_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified mode change string.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|mode_change
modifier|*
name|mode_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|multi_volume_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|namelist_freed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The same variable hold the time, whether mtime or ctime.  Just fake a    non-existing option, for making the code clearer, elsewhere.  */
end_comment

begin_define
define|#
directive|define
name|newer_ctime_option
value|newer_mtime_option
end_define

begin_comment
comment|/* Specified threshold date and time.  Files having an older time stamp    do not get archived (also see after_date_option above).  */
end_comment

begin_decl_stmt
name|GLOBAL
name|time_t
name|newer_mtime_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero if there is no recursion, otherwise FNM_LEADING_DIR.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|recursion_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|numeric_owner_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|one_file_system_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified value to be put into tar file in place of stat () results, or    just -1 if such an override should not take place.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|uid_t
name|owner_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|recursive_unlink_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|read_full_records_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|remove_files_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified remote shell command.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|rsh_command_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|same_order_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If positive, preserve ownership when extracting.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|same_owner_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If positive, preserve permissions when extracting.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|same_permissions_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|show_omitted_dirs_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|sparse_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|starting_file_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified maximum byte length of each tape volume (multiple of 1024).  */
end_comment

begin_decl_stmt
name|GLOBAL
name|tarlong
name|tape_length_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|to_stdout_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|totals_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|touch_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Count how many times the option has been set, multiple setting yields    more verbose behavior.  Value 0 means no verbosity, 1 means file name    only, 2 means file name and all attributes.  More than 2 is just like 2.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|verbose_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean value.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|verify_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified name of file containing the volume number.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|volno_file_option
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specified value or pattern.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
name|volume_label_option
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Other global variables.  */
end_comment

begin_comment
comment|/* File descriptor for archive file.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|archive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero when outputting to /dev/null.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|dev_null_output
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Timestamp for when we started execution.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CLOCK_GETTIME
end_if

begin_decl_stmt
name|GLOBAL
name|struct
name|timespec
name|start_timespec
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|start_time
value|(start_timespec.tv_sec)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|GLOBAL
name|time_t
name|start_time
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Name of file for the current archive entry.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|current_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of link for the current archive entry.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|current_link_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List of tape drive names, number of such tape drives, allocated number,    and current cursor in list.  */
end_comment

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
modifier|*
name|archive_name_array
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|archive_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
name|int
name|allocated_archive_names
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
specifier|const
name|char
modifier|*
modifier|*
name|archive_name_cursor
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure for keeping track of filenames and lists thereof.  */
end_comment

begin_struct
struct|struct
name|name
block|{
name|struct
name|name
modifier|*
name|next
decl_stmt|;
name|size_t
name|length
decl_stmt|;
comment|/* cached strlen(name) */
name|char
name|found
decl_stmt|;
comment|/* a matching file has been found */
name|char
name|firstch
decl_stmt|;
comment|/* first char is literally matched */
name|char
name|regexp
decl_stmt|;
comment|/* this name is a regexp, not literal */
name|int
name|change_dir
decl_stmt|;
comment|/* set with the -C option */
name|char
specifier|const
modifier|*
name|dir_contents
decl_stmt|;
comment|/* for incremental_option */
name|char
name|fake
decl_stmt|;
comment|/* dummy entry */
name|char
name|name
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information about a sparse file.  */
end_comment

begin_struct
struct|struct
name|sp_array
block|{
name|off_t
name|offset
decl_stmt|;
name|size_t
name|numbytes
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|GLOBAL
name|struct
name|sp_array
modifier|*
name|sparsearray
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of elements in sparsearray.  */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|sp_array_size
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Declarations for each module.  */
end_comment

begin_comment
comment|/* FIXME: compare.c should not directly handle the following variable,    instead, this should be done in buffer.c only.  */
end_comment

begin_enum
enum|enum
name|access_mode
block|{
name|ACCESS_READ
block|,
name|ACCESS_WRITE
block|,
name|ACCESS_UPDATE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|access_mode
name|access_mode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module buffer.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdlis
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|save_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|save_sizeleft
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|off_t
name|save_totsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|write_archive_to_stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|available_space_after
name|PARAMS
argument_list|(
operator|(
expr|union
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|current_block_ordinal
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|close_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|closeout_volume_number
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|block
modifier|*
name|find_next_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|flush_read
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|flush_write
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|flush_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_volume_number
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|open_archive
name|PARAMS
argument_list|(
operator|(
expr|enum
name|access_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_total_written
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|reset_eof
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|set_next_block_after
name|PARAMS
argument_list|(
operator|(
expr|union
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module create.c.  */
end_comment

begin_decl_stmt
name|void
name|create_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dump_file
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|dev_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|finish_header
name|PARAMS
argument_list|(
operator|(
expr|union
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_eot
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GID_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|gid_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MAJOR_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|major_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MINOR_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|minor_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MODE_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|mode_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|OFF_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|off_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|SIZE_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|size_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|TIME_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|time_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|UID_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|uid_to_chars (val, where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|UINTMAX_TO_CHARS
parameter_list|(
name|val
parameter_list|,
name|where
parameter_list|)
value|uintmax_to_chars (val, where, sizeof (where))
end_define

begin_decl_stmt
name|void
name|gid_to_chars
name|PARAMS
argument_list|(
operator|(
name|gid_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|major_to_chars
name|PARAMS
argument_list|(
operator|(
name|major_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|minor_to_chars
name|PARAMS
argument_list|(
operator|(
name|minor_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mode_to_chars
name|PARAMS
argument_list|(
operator|(
name|mode_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|off_to_chars
name|PARAMS
argument_list|(
operator|(
name|off_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|size_to_chars
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|time_to_chars
name|PARAMS
argument_list|(
operator|(
name|time_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uid_to_chars
name|PARAMS
argument_list|(
operator|(
name|uid_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uintmax_to_chars
name|PARAMS
argument_list|(
operator|(
name|uintmax_t
operator|,
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module diffarch.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|now_verifying
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|diff_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|diff_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|verify_volume
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module extract.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|we_are_root
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|extr_init
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|extract_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|extract_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|fatal_exit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module delete.c.  */
end_comment

begin_decl_stmt
name|void
name|delete_archive_members
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module incremen.c.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|get_directory_contents
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|dev_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_directory_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_directory_file
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gnu_restore
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module list.c.  */
end_comment

begin_enum
enum|enum
name|read_header
block|{
name|HEADER_STILL_UNREAD
block|,
comment|/* for when read_header has not been called */
name|HEADER_SUCCESS
block|,
comment|/* header successfully read and checksummed */
name|HEADER_SUCCESS_EXTENDED
block|,
comment|/* likewise, but we got an extended header */
name|HEADER_ZERO_BLOCK
block|,
comment|/* zero block where header expected */
name|HEADER_END_OF_FILE
block|,
comment|/* true end of file while header expected */
name|HEADER_FAILURE
comment|/* ill-formed header, or bad checksum */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|union
name|block
modifier|*
name|current_header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|current_stat
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|archive_format
name|current_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|decode_header
name|PARAMS
argument_list|(
operator|(
expr|union
name|block
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|,
expr|enum
name|archive_format
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
name|STRINGIFY_BIGINT
parameter_list|(
name|i
parameter_list|,
name|b
parameter_list|)
define|\
value|stringify_uintmax_t_backwards ((uintmax_t) (i), (b) + UINTMAX_STRSIZE_BOUND)
end_define

begin_decl_stmt
name|char
modifier|*
name|stringify_uintmax_t_backwards
name|PARAMS
argument_list|(
operator|(
name|uintmax_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|tartime
name|PARAMS
argument_list|(
operator|(
name|time_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|GID_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|gid_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MAJOR_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|major_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MINOR_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|minor_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|MODE_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|mode_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|OFF_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|off_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|SIZE_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|size_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|TIME_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|time_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|UID_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|uid_from_header (where, sizeof (where))
end_define

begin_define
define|#
directive|define
name|UINTMAX_FROM_HEADER
parameter_list|(
name|where
parameter_list|)
value|uintmax_from_header (where, sizeof (where))
end_define

begin_decl_stmt
name|gid_t
name|gid_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|major_t
name|major_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|minor_t
name|minor_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|mode_t
name|mode_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|off_t
name|off_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|size_t
name|size_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|time_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uid_t
name|uid_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|uintmax_t
name|uintmax_from_header
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|list_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_for_mkdir
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_header
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_and
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
operator|*
name|do_
argument_list|)
argument_list|()
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|enum
name|read_header
name|read_header
name|PARAMS
argument_list|(
operator|(
name|bool
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|skip_file
name|PARAMS
argument_list|(
operator|(
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|skip_member
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module mangle.c.  */
end_comment

begin_decl_stmt
name|void
name|extract_mangle
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module misc.c.  */
end_comment

begin_decl_stmt
name|void
name|assign_string
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
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
name|char
modifier|*
name|quote_copy_string
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|unquote_string
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|contains_dot_dot
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|remove_any_file
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

begin_decl_stmt
name|int
name|maybe_backup_file
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

begin_decl_stmt
name|void
name|undo_last_backup
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|deref_stat
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|,
expr|struct
name|stat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chdir_arg
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|chdir_do
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|decode_mode
name|PARAMS
argument_list|(
operator|(
name|mode_t
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|chdir_fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|chmod_error_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|chown_error_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|uid_t
operator|,
name|gid_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|close_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|close_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|exec_fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|link_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mkdir_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mkfifo_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|mknod_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|open_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|open_fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|open_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_error_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|off_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_fatal_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|off_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_warn_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|off_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|readlink_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|readlink_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|savedir_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|savedir_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seek_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seek_error_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seek_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|seek_warn_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|off_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stat_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|stat_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|symlink_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|truncate_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|truncate_warn
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unlink_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|utime_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|waitpid_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_error
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_error_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|ssize_t
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_fatal
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|write_fatal_details
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|ssize_t
operator|,
name|size_t
operator|)
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|noreturn
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|pid_t
name|xfork
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|xpipe
name|PARAMS
argument_list|(
operator|(
name|int
index|[
literal|2
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|quote
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
specifier|const
modifier|*
name|quote_n
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module names.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|name
modifier|*
name|gnu_list_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gid_to_gname
name|PARAMS
argument_list|(
operator|(
name|gid_t
operator|,
name|char
name|gname
index|[
name|GNAME_FIELD_SIZE
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gname_to_gid
name|PARAMS
argument_list|(
operator|(
name|char
name|gname
index|[
name|GNAME_FIELD_SIZE
index|]
operator|,
name|gid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|uid_to_uname
name|PARAMS
argument_list|(
operator|(
name|uid_t
operator|,
name|char
name|uname
index|[
name|UNAME_FIELD_SIZE
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|uname_to_uid
name|PARAMS
argument_list|(
operator|(
name|char
name|uname
index|[
name|UNAME_FIELD_SIZE
index|]
operator|,
name|uid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|init_names
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|name_add
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|name_init
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|name_term
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name_next
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|name_close
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|name_gather
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|name
modifier|*
name|addname
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|name_match
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|names_notfound
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|collect_and_sort_names
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|name
modifier|*
name|name_scan
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name_from_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|blank_name_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|new_name
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
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
name|bool
name|excluded_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|add_avoided_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|is_avoided_name
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module tar.c.  */
end_comment

begin_decl_stmt
name|int
name|confirm
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
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
name|void
name|request_stdin
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Module update.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|output_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|update_archive
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

