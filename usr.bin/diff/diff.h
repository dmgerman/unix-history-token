begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*ROR  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)diff.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_comment
comment|/*  * Output format options  */
end_comment

begin_define
define|#
directive|define
name|D_NORMAL
value|0
end_define

begin_comment
comment|/* Normal output */
end_comment

begin_define
define|#
directive|define
name|D_EDIT
value|-1
end_define

begin_comment
comment|/* Editor script out */
end_comment

begin_define
define|#
directive|define
name|D_REVERSE
value|1
end_define

begin_comment
comment|/* Reverse editor script */
end_comment

begin_define
define|#
directive|define
name|D_CONTEXT
value|2
end_define

begin_comment
comment|/* Diff with context */
end_comment

begin_define
define|#
directive|define
name|D_UNIFIED
value|3
end_define

begin_comment
comment|/* Unified context diff */
end_comment

begin_define
define|#
directive|define
name|D_IFDEF
value|4
end_define

begin_comment
comment|/* Diff with merged #ifdef's */
end_comment

begin_define
define|#
directive|define
name|D_NREVERSE
value|5
end_define

begin_comment
comment|/* Reverse ed script with numbered 				   lines and no trailing . */
end_comment

begin_define
define|#
directive|define
name|D_BRIEF
value|6
end_define

begin_comment
comment|/* Say if the files differ */
end_comment

begin_define
define|#
directive|define
name|D_GFORMAT
value|7
end_define

begin_comment
comment|/* Diff with defined changed group format */
end_comment

begin_comment
comment|/*  * Output flags  */
end_comment

begin_define
define|#
directive|define
name|D_HEADER
value|0x001
end_define

begin_comment
comment|/* Print a header/footer between files */
end_comment

begin_define
define|#
directive|define
name|D_EMPTY1
value|0x002
end_define

begin_comment
comment|/* Treat first file as empty (/dev/null) */
end_comment

begin_define
define|#
directive|define
name|D_EMPTY2
value|0x004
end_define

begin_comment
comment|/* Treat second file as empty (/dev/null) */
end_comment

begin_comment
comment|/*  * Command line flags  */
end_comment

begin_define
define|#
directive|define
name|D_FORCEASCII
value|0x008
end_define

begin_comment
comment|/* Treat file as ascii regardless of content */
end_comment

begin_define
define|#
directive|define
name|D_FOLDBLANKS
value|0x010
end_define

begin_comment
comment|/* Treat all white space as equal */
end_comment

begin_define
define|#
directive|define
name|D_MINIMAL
value|0x020
end_define

begin_comment
comment|/* Make diff as small as possible */
end_comment

begin_define
define|#
directive|define
name|D_IGNORECASE
value|0x040
end_define

begin_comment
comment|/* Case-insensitive matching */
end_comment

begin_define
define|#
directive|define
name|D_PROTOTYPE
value|0x080
end_define

begin_comment
comment|/* Display C function prototype */
end_comment

begin_define
define|#
directive|define
name|D_EXPANDTABS
value|0x100
end_define

begin_comment
comment|/* Expand tabs to spaces */
end_comment

begin_define
define|#
directive|define
name|D_IGNOREBLANKS
value|0x200
end_define

begin_comment
comment|/* Ignore white space changes */
end_comment

begin_define
define|#
directive|define
name|D_STRIPCR
value|0x400
end_define

begin_comment
comment|/* Strip trailing cr */
end_comment

begin_comment
comment|/*  * Status values for print_status() and diffreg() return values  */
end_comment

begin_define
define|#
directive|define
name|D_SAME
value|0
end_define

begin_comment
comment|/* Files are the same */
end_comment

begin_define
define|#
directive|define
name|D_DIFFER
value|1
end_define

begin_comment
comment|/* Files are different */
end_comment

begin_define
define|#
directive|define
name|D_BINARY
value|2
end_define

begin_comment
comment|/* Binary files are different */
end_comment

begin_define
define|#
directive|define
name|D_MISMATCH1
value|3
end_define

begin_comment
comment|/* path1 was a dir, path2 a file */
end_comment

begin_define
define|#
directive|define
name|D_MISMATCH2
value|4
end_define

begin_comment
comment|/* path1 was a file, path2 a dir */
end_comment

begin_define
define|#
directive|define
name|D_SKIPPED1
value|5
end_define

begin_comment
comment|/* path1 was a special file */
end_comment

begin_define
define|#
directive|define
name|D_SKIPPED2
value|6
end_define

begin_comment
comment|/* path2 was a special file */
end_comment

begin_struct
struct|struct
name|excludes
block|{
name|char
modifier|*
name|pattern
decl_stmt|;
name|struct
name|excludes
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|lflag
decl_stmt|,
name|Nflag
decl_stmt|,
name|Pflag
decl_stmt|,
name|rflag
decl_stmt|,
name|sflag
decl_stmt|,
name|Tflag
decl_stmt|,
name|cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diff_format
decl_stmt|,
name|diff_context
decl_stmt|,
name|status
decl_stmt|,
name|ignore_file_case
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tabsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|start
decl_stmt|,
modifier|*
name|ifdefname
decl_stmt|,
modifier|*
name|diffargs
decl_stmt|,
modifier|*
name|label
index|[
literal|2
index|]
decl_stmt|,
modifier|*
name|ignore_pats
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|group_format
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|stat
name|stb1
decl_stmt|,
name|stb2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|excludes
modifier|*
name|excludes_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|regex_t
name|ignore_re
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|splice
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|diffreg
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|easprintf
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|emalloc
parameter_list|(
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|erealloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|diffdir
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_only
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_status
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

