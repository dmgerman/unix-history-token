begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD: src/usr.bin/tar/bsdtar.h,v 1.37 2008/12/06 07:37:14 kientzle Exp $  */
end_comment

begin_include
include|#
directive|include
file|"bsdtar_platform.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|DEFAULT_BYTES_PER_BLOCK
value|(20*512)
end_define

begin_define
define|#
directive|define
name|ENV_READER_OPTIONS
value|"TAR_READER_OPTIONS"
end_define

begin_define
define|#
directive|define
name|ENV_WRITER_OPTIONS
value|"TAR_WRITER_OPTIONS"
end_define

begin_define
define|#
directive|define
name|IGNORE_WRONG_MODULE_NAME
value|"__ignore_wrong_module_name__,"
end_define

begin_struct_decl
struct_decl|struct
name|creation_set
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The internal state for the "bsdtar" program.  *  * Keeping all of the state in a structure like this simplifies memory  * leak testing (at exit, anything left on the heap is suspect).  A  * pointer to this structure is passed to most bsdtar internal  * functions.  */
end_comment

begin_struct
struct|struct
name|bsdtar
block|{
comment|/* Options */
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
comment|/* -f filename */
name|char
modifier|*
name|pending_chdir
decl_stmt|;
comment|/* -C dir */
specifier|const
name|char
modifier|*
name|names_from_file
decl_stmt|;
comment|/* -T file */
name|int
name|bytes_per_block
decl_stmt|;
comment|/* -b block_size */
name|int
name|bytes_in_last_block
decl_stmt|;
comment|/* See -b handling. */
name|int
name|verbose
decl_stmt|;
comment|/* -v */
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* Bitfield of boolean options */
name|int
name|extract_flags
decl_stmt|;
comment|/* Flags for extract operation */
name|int
name|readdisk_flags
decl_stmt|;
comment|/* Flags for read disk operation */
name|int
name|strip_components
decl_stmt|;
comment|/* Remove this many leading dirs */
name|int
name|gid
decl_stmt|;
comment|/* --gid */
specifier|const
name|char
modifier|*
name|gname
decl_stmt|;
comment|/* --gname */
name|int
name|uid
decl_stmt|;
comment|/* --uid */
specifier|const
name|char
modifier|*
name|uname
decl_stmt|;
comment|/* --uname */
specifier|const
name|char
modifier|*
name|passphrase
decl_stmt|;
comment|/* --passphrase */
name|char
name|mode
decl_stmt|;
comment|/* Program mode: 'c', 't', 'r', 'u', 'x' */
name|char
name|symlink_mode
decl_stmt|;
comment|/* H or L, per BSD conventions */
specifier|const
name|char
modifier|*
name|option_options
decl_stmt|;
comment|/* --options */
name|char
name|day_first
decl_stmt|;
comment|/* show day before month in -tv output */
name|struct
name|creation_set
modifier|*
name|cset
decl_stmt|;
comment|/* Option parser state */
name|int
name|getopt_state
decl_stmt|;
name|char
modifier|*
name|getopt_word
decl_stmt|;
comment|/* If>= 0, then close this when done. */
name|int
name|fd
decl_stmt|;
comment|/* Miscellaneous state information */
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
specifier|const
name|char
modifier|*
name|argument
decl_stmt|;
name|size_t
name|gs_width
decl_stmt|;
comment|/* For 'list_item' in read.c */
name|size_t
name|u_width
decl_stmt|;
comment|/* for 'list_item' in read.c */
name|uid_t
name|user_uid
decl_stmt|;
comment|/* UID running this program */
name|int
name|return_value
decl_stmt|;
comment|/* Value returned by main() */
name|char
name|warned_lead_slash
decl_stmt|;
comment|/* Already displayed warning */
name|char
name|next_line_is_dir
decl_stmt|;
comment|/* Used for -C parsing in -cT */
comment|/* 	 * Data for various subsystems.  Full definitions are located in 	 * the file where they are used. 	 */
name|struct
name|archive
modifier|*
name|diskreader
decl_stmt|;
comment|/* for write.c */
name|struct
name|archive_entry_linkresolver
modifier|*
name|resolver
decl_stmt|;
comment|/* for write.c */
name|struct
name|archive_dir
modifier|*
name|archive_dir
decl_stmt|;
comment|/* for write.c */
name|struct
name|name_cache
modifier|*
name|gname_cache
decl_stmt|;
comment|/* for write.c */
name|char
modifier|*
name|buff
decl_stmt|;
comment|/* for write.c */
name|size_t
name|buff_size
decl_stmt|;
comment|/* for write.c */
name|int
name|first_fs
decl_stmt|;
comment|/* for write.c */
name|struct
name|archive
modifier|*
name|matching
decl_stmt|;
comment|/* for matching.c */
name|struct
name|security
modifier|*
name|security
decl_stmt|;
comment|/* for read.c */
name|struct
name|name_cache
modifier|*
name|uname_cache
decl_stmt|;
comment|/* for write.c */
name|struct
name|siginfo_data
modifier|*
name|siginfo
decl_stmt|;
comment|/* for siginfo.c */
name|struct
name|substitution
modifier|*
name|substitution
decl_stmt|;
comment|/* for subst.c */
name|char
modifier|*
name|ppbuff
decl_stmt|;
comment|/* for util.c */
block|}
struct|;
end_struct

begin_comment
comment|/* Options for flags bitfield */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_AUTO_COMPRESS
value|(0x00000001)
end_define

begin_comment
comment|/* -a */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_ABSOLUTE_PATHS
value|(0x00000002)
end_define

begin_comment
comment|/* -P */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_CHROOT
value|(0x00000004)
end_define

begin_comment
comment|/* --chroot */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_FAST_READ
value|(0x00000008)
end_define

begin_comment
comment|/* --fast-read */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_IGNORE_ZEROS
value|(0x00000010)
end_define

begin_comment
comment|/* --ignore-zeros */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_INTERACTIVE
value|(0x00000020)
end_define

begin_comment
comment|/* -w */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_OWNER
value|(0x00000040)
end_define

begin_comment
comment|/* -o */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_SUBDIRS
value|(0x00000080)
end_define

begin_comment
comment|/* -n */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NULL
value|(0x00000100)
end_define

begin_comment
comment|/* --null */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NUMERIC_OWNER
value|(0x00000200)
end_define

begin_comment
comment|/* --numeric-owner */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_O
value|(0x00000400)
end_define

begin_comment
comment|/* -o */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_STDOUT
value|(0x00000800)
end_define

begin_comment
comment|/* -O */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_TOTALS
value|(0x00001000)
end_define

begin_comment
comment|/* --totals */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_UNLINK_FIRST
value|(0x00002000)
end_define

begin_comment
comment|/* -U */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_WARN_LINKS
value|(0x00004000)
end_define

begin_comment
comment|/* --check-links */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_XATTRS
value|(0x00008000)
end_define

begin_comment
comment|/* --no-xattrs */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_XATTRS
value|(0x00010000)
end_define

begin_comment
comment|/* --xattrs */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_ACLS
value|(0x00020000)
end_define

begin_comment
comment|/* --no-acls */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_ACLS
value|(0x00040000)
end_define

begin_comment
comment|/* --acls */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_FFLAGS
value|(0x00080000)
end_define

begin_comment
comment|/* --no-fflags */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_FFLAGS
value|(0x00100000)
end_define

begin_comment
comment|/* --fflags */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_NO_MAC_METADATA
value|(0x00200000)
end_define

begin_comment
comment|/* --no-mac-metadata */
end_comment

begin_define
define|#
directive|define
name|OPTFLAG_MAC_METADATA
value|(0x00400000)
end_define

begin_comment
comment|/* --mac-metadata */
end_comment

begin_comment
comment|/* Fake short equivalents for long options that otherwise lack them. */
end_comment

begin_enum
enum|enum
block|{
name|OPTION_ACLS
init|=
literal|1
block|,
name|OPTION_B64ENCODE
block|,
name|OPTION_CHECK_LINKS
block|,
name|OPTION_CHROOT
block|,
name|OPTION_CLEAR_NOCHANGE_FFLAGS
block|,
name|OPTION_EXCLUDE
block|,
name|OPTION_FFLAGS
block|,
name|OPTION_FORMAT
block|,
name|OPTION_GID
block|,
name|OPTION_GNAME
block|,
name|OPTION_GRZIP
block|,
name|OPTION_HELP
block|,
name|OPTION_HFS_COMPRESSION
block|,
name|OPTION_IGNORE_ZEROS
block|,
name|OPTION_INCLUDE
block|,
name|OPTION_KEEP_NEWER_FILES
block|,
name|OPTION_LRZIP
block|,
name|OPTION_LZ4
block|,
name|OPTION_LZIP
block|,
name|OPTION_LZMA
block|,
name|OPTION_LZOP
block|,
name|OPTION_MAC_METADATA
block|,
name|OPTION_NEWER_CTIME
block|,
name|OPTION_NEWER_CTIME_THAN
block|,
name|OPTION_NEWER_MTIME
block|,
name|OPTION_NEWER_MTIME_THAN
block|,
name|OPTION_NODUMP
block|,
name|OPTION_NOPRESERVE_HFS_COMPRESSION
block|,
name|OPTION_NO_ACLS
block|,
name|OPTION_NO_FFLAGS
block|,
name|OPTION_NO_MAC_METADATA
block|,
name|OPTION_NO_SAME_OWNER
block|,
name|OPTION_NO_SAME_PERMISSIONS
block|,
name|OPTION_NO_XATTRS
block|,
name|OPTION_NULL
block|,
name|OPTION_NUMERIC_OWNER
block|,
name|OPTION_OLDER_CTIME
block|,
name|OPTION_OLDER_CTIME_THAN
block|,
name|OPTION_OLDER_MTIME
block|,
name|OPTION_OLDER_MTIME_THAN
block|,
name|OPTION_ONE_FILE_SYSTEM
block|,
name|OPTION_OPTIONS
block|,
name|OPTION_PASSPHRASE
block|,
name|OPTION_POSIX
block|,
name|OPTION_SAME_OWNER
block|,
name|OPTION_STRIP_COMPONENTS
block|,
name|OPTION_TOTALS
block|,
name|OPTION_UID
block|,
name|OPTION_UNAME
block|,
name|OPTION_USE_COMPRESS_PROGRAM
block|,
name|OPTION_UUENCODE
block|,
name|OPTION_VERSION
block|,
name|OPTION_XATTRS
block|,
name|OPTION_ZSTD
block|, }
enum|;
end_enum

begin_function_decl
name|int
name|bsdtar_getopt
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_chdir
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edit_pathname
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|need_report
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pathcmp
parameter_list|(
specifier|const
name|char
modifier|*
name|a
parameter_list|,
specifier|const
name|char
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|safe_fprintf
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__LA_PRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|set_chdir
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|newdir
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|tar_i64toa
parameter_list|(
name|int64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tar_mode_c
parameter_list|(
name|struct
name|bsdtar
modifier|*
name|bsdtar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tar_mode_r
parameter_list|(
name|struct
name|bsdtar
modifier|*
name|bsdtar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tar_mode_t
parameter_list|(
name|struct
name|bsdtar
modifier|*
name|bsdtar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tar_mode_u
parameter_list|(
name|struct
name|bsdtar
modifier|*
name|bsdtar
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tar_mode_x
parameter_list|(
name|struct
name|bsdtar
modifier|*
name|bsdtar
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|usage
argument_list|(
name|void
argument_list|)
name|__LA_DEAD
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|yes
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|__LA_PRINTF
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_REGEX_H
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_PCREPOSIX_H
argument_list|)
end_if

begin_function_decl
name|void
name|add_substitution
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|apply_substitution
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cleanup_substitution
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|cset_add_filter
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cset_add_filter_program
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cset_auto_compress
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cset_free
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|cset_get_format
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|creation_set
modifier|*
name|cset_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cset_read_support_filter_program
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
name|struct
name|archive
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cset_set_format
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cset_write_add_filters
parameter_list|(
name|struct
name|creation_set
modifier|*
parameter_list|,
name|struct
name|archive
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|passphrase_callback
parameter_list|(
name|struct
name|archive
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|passphrase_free
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|list_item_verbose
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|struct
name|archive_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

