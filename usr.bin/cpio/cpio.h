begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2007 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPIO_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|CPIO_H_INCLUDED
end_define

begin_include
include|#
directive|include
file|"cpio_platform.h"
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

begin_comment
comment|/*  * The internal state for the "cpio" program.  *  * Keeping all of the state in a structure like this simplifies memory  * leak testing (at exit, anything left on the heap is suspect).  A  * pointer to this structure is passed to most cpio internal  * functions.  */
end_comment

begin_struct
struct|struct
name|cpio
block|{
comment|/* Option parsing */
specifier|const
name|char
modifier|*
name|optarg
decl_stmt|;
comment|/* Options */
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
name|char
name|mode
decl_stmt|;
comment|/* -i -o -p */
name|char
name|compress
decl_stmt|;
comment|/* -j, -y, or -z */
specifier|const
name|char
modifier|*
name|format
decl_stmt|;
comment|/* -H format */
name|int
name|bytes_per_block
decl_stmt|;
comment|/* -b block_size */
name|int
name|verbose
decl_stmt|;
comment|/* -v */
name|int
name|dot
decl_stmt|;
comment|/* -V */
name|int
name|quiet
decl_stmt|;
comment|/* --quiet */
name|int
name|extract_flags
decl_stmt|;
comment|/* Flags for extract operation */
name|char
name|symlink_mode
decl_stmt|;
comment|/* H or L, per BSD conventions */
specifier|const
name|char
modifier|*
name|compress_program
decl_stmt|;
name|char
name|line_separator
decl_stmt|;
comment|/* --null ? '\0' : '\n' */
name|int
name|option_append
decl_stmt|;
comment|/* -A, only relevant for -o */
name|int
name|option_atime_restore
decl_stmt|;
comment|/* -a */
name|int
name|option_follow_links
decl_stmt|;
comment|/* -L */
name|int
name|option_link
decl_stmt|;
comment|/* -l */
name|int
name|option_list
decl_stmt|;
comment|/* -t */
name|int
name|option_numeric_uid_gid
decl_stmt|;
comment|/* -n */
name|int
name|option_rename
decl_stmt|;
comment|/* -r */
name|char
modifier|*
name|destdir
decl_stmt|;
name|size_t
name|pass_destpath_alloc
decl_stmt|;
name|char
modifier|*
name|pass_destpath
decl_stmt|;
name|int
name|uid_override
decl_stmt|;
name|int
name|gid_override
decl_stmt|;
name|int
name|day_first
decl_stmt|;
comment|/* true if locale prefers day/mon */
comment|/* If>= 0, then close this when done. */
name|int
name|fd
decl_stmt|;
comment|/* Miscellaneous state information */
name|struct
name|archive
modifier|*
name|archive
decl_stmt|;
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|int
name|return_value
decl_stmt|;
comment|/* Value returned by main() */
name|struct
name|archive_entry_linkresolver
modifier|*
name|linkresolver
decl_stmt|;
name|struct
name|name_cache
modifier|*
name|uname_cache
decl_stmt|;
name|struct
name|name_cache
modifier|*
name|gname_cache
decl_stmt|;
comment|/* Work data. */
name|struct
name|matching
modifier|*
name|matching
decl_stmt|;
name|char
modifier|*
name|buff
decl_stmt|;
name|size_t
name|buff_size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Name of this program; used in error reporting, initialized in main(). */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|cpio_progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cpio_errc
argument_list|(
name|int
name|_eval
argument_list|,
name|int
name|_code
argument_list|,
specifier|const
name|char
operator|*
name|fmt
argument_list|,
operator|...
argument_list|)
name|__LA_DEAD
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|cpio_warnc
parameter_list|(
name|int
name|_code
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|owner_parse
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fake short equivalents for long options that otherwise lack them. */
end_comment

begin_enum
enum|enum
block|{
name|OPTION_INSECURE
init|=
literal|1
block|,
name|OPTION_NO_PRESERVE_OWNER
block|,
name|OPTION_QUIET
block|,
name|OPTION_VERSION
block|}
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|line_reader
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|line_reader
modifier|*
name|process_lines_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
name|separator
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|process_lines_next
parameter_list|(
name|struct
name|line_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|process_lines_free
parameter_list|(
name|struct
name|line_reader
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cpio_getopt
parameter_list|(
name|struct
name|cpio
modifier|*
name|cpio
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|include_from_file
parameter_list|(
name|struct
name|cpio
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

