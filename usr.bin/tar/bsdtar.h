begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2004 Tim Kientzle  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name(s) of the author(s) may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<archive.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
specifier|const
name|char
modifier|*
name|create_format
decl_stmt|;
comment|/* -F format */
specifier|const
name|char
modifier|*
name|start_dir
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
name|verbose
decl_stmt|;
comment|/* -v */
name|int
name|extract_flags
decl_stmt|;
comment|/* Flags for extract operation */
name|char
name|symlink_mode
decl_stmt|;
comment|/* H or L, per BSD conventions */
name|char
name|create_compression
decl_stmt|;
comment|/* j, y, or z */
name|char
name|option_absolute_paths
decl_stmt|;
comment|/* -P */
name|char
name|option_dont_traverse_mounts
decl_stmt|;
comment|/* -X */
name|char
name|option_fast_read
decl_stmt|;
comment|/* --fast-read */
name|char
name|option_honor_nodump
decl_stmt|;
comment|/* --nodump */
name|char
name|option_interactive
decl_stmt|;
comment|/* -w */
name|char
name|option_no_subdirs
decl_stmt|;
comment|/* -d */
name|char
name|option_stdout
decl_stmt|;
comment|/* -p */
name|char
name|option_warn_links
decl_stmt|;
comment|/* -l */
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
name|size_t
name|gs_width
decl_stmt|;
comment|/* For 'list_item' in read.c */
name|size_t
name|u_width
decl_stmt|;
comment|/* for 'list_item' in read.c */
name|char
modifier|*
name|user_uname
decl_stmt|;
comment|/* User running this program */
name|uid_t
name|user_uid
decl_stmt|;
comment|/* UID running this program */
comment|/* 	 * Data for various subsystems.  Full definitions are located in 	 * the file where they are used. 	 */
name|struct
name|archive_dir
modifier|*
name|archive_dir
decl_stmt|;
comment|/* for write.c */
name|struct
name|gname_cache
modifier|*
name|gname_cache
decl_stmt|;
comment|/* for write.c */
name|struct
name|links_cache
modifier|*
name|links_cache
decl_stmt|;
comment|/* for write.c */
name|struct
name|matching
modifier|*
name|matching
decl_stmt|;
comment|/* for matching.c */
name|struct
name|uname_cache
modifier|*
name|uname_cache
decl_stmt|;
comment|/* for write.c */
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|bsdtar_progname
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bsdtar_errc
parameter_list|(
name|int
name|_eval
parameter_list|,
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
name|void
name|bsdtar_warnc
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
name|void
name|cleanup_exclusions
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exclude
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|excluded
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|pathname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|include
parameter_list|(
name|struct
name|bsdtar
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
name|pattern
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

begin_function_decl
name|int
name|unmatched_inclusions
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
name|usage
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
function_decl|;
end_function_decl

end_unit

