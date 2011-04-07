begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: grep.h,v 1.15 2010/04/05 03:03:55 tedu Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 James Howard and Dag-Erling CoÃ¯dan SmÃ¸rgrav  * Copyright (c) 2008-2009 Gabor Kovesdan<gabor@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<bzlib.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<zlib.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|WITHOUT_NLS
end_ifdef

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|n
parameter_list|)
value|errstr[n]
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<nl_types.h>
end_include

begin_decl_stmt
specifier|extern
name|nl_catd
name|catalog
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|getstr
parameter_list|(
name|n
parameter_list|)
value|catgets(catalog, 1, n, errstr[n])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|errstr
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|VERSION
value|"2.5.1-FreeBSD"
end_define

begin_define
define|#
directive|define
name|GREP_FIXED
value|0
end_define

begin_define
define|#
directive|define
name|GREP_BASIC
value|1
end_define

begin_define
define|#
directive|define
name|GREP_EXTENDED
value|2
end_define

begin_define
define|#
directive|define
name|BINFILE_BIN
value|0
end_define

begin_define
define|#
directive|define
name|BINFILE_SKIP
value|1
end_define

begin_define
define|#
directive|define
name|BINFILE_TEXT
value|2
end_define

begin_define
define|#
directive|define
name|FILE_STDIO
value|0
end_define

begin_define
define|#
directive|define
name|FILE_GZIP
value|1
end_define

begin_define
define|#
directive|define
name|FILE_BZIP
value|2
end_define

begin_define
define|#
directive|define
name|DIR_READ
value|0
end_define

begin_define
define|#
directive|define
name|DIR_SKIP
value|1
end_define

begin_define
define|#
directive|define
name|DIR_RECURSE
value|2
end_define

begin_define
define|#
directive|define
name|DEV_READ
value|0
end_define

begin_define
define|#
directive|define
name|DEV_SKIP
value|1
end_define

begin_define
define|#
directive|define
name|LINK_READ
value|0
end_define

begin_define
define|#
directive|define
name|LINK_EXPLICIT
value|1
end_define

begin_define
define|#
directive|define
name|LINK_SKIP
value|2
end_define

begin_define
define|#
directive|define
name|EXCL_PAT
value|0
end_define

begin_define
define|#
directive|define
name|INCL_PAT
value|1
end_define

begin_define
define|#
directive|define
name|MAX_LINE_MATCHES
value|32
end_define

begin_struct
struct|struct
name|file
block|{
name|int
name|fd
decl_stmt|;
name|bool
name|binary
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|str
block|{
name|off_t
name|off
decl_stmt|;
name|size_t
name|len
decl_stmt|;
name|char
modifier|*
name|dat
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
name|int
name|line_no
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epat
block|{
name|char
modifier|*
name|pat
decl_stmt|;
name|int
name|mode
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|size_t
name|len
decl_stmt|;
name|unsigned
name|char
modifier|*
name|pattern
decl_stmt|;
name|int
name|qsBc
index|[
name|UCHAR_MAX
operator|+
literal|1
index|]
decl_stmt|;
comment|/* flags */
name|bool
name|bol
decl_stmt|;
name|bool
name|eol
decl_stmt|;
name|bool
name|reversed
decl_stmt|;
name|bool
name|word
decl_stmt|;
block|}
name|fastgrep_t
typedef|;
end_typedef

begin_comment
comment|/* Flags passed to regcomp() and regexec() */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cflags
decl_stmt|,
name|eflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Command line flags */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|Eflag
decl_stmt|,
name|Fflag
decl_stmt|,
name|Gflag
decl_stmt|,
name|Hflag
decl_stmt|,
name|Lflag
decl_stmt|,
name|bflag
decl_stmt|,
name|cflag
decl_stmt|,
name|hflag
decl_stmt|,
name|iflag
decl_stmt|,
name|lflag
decl_stmt|,
name|mflag
decl_stmt|,
name|nflag
decl_stmt|,
name|oflag
decl_stmt|,
name|qflag
decl_stmt|,
name|sflag
decl_stmt|,
name|vflag
decl_stmt|,
name|wflag
decl_stmt|,
name|xflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|dexclude
decl_stmt|,
name|dinclude
decl_stmt|,
name|fexclude
decl_stmt|,
name|finclude
decl_stmt|,
name|lbflag
decl_stmt|,
name|nullflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|long
name|Aflag
decl_stmt|,
name|Bflag
decl_stmt|,
name|mcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|binbehave
decl_stmt|,
name|devbehave
decl_stmt|,
name|dirbehave
decl_stmt|,
name|filebehave
decl_stmt|,
name|grepbehave
decl_stmt|,
name|linkbehave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|first
decl_stmt|,
name|matchall
decl_stmt|,
name|notfound
decl_stmt|,
name|prev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tail
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|dpatterns
decl_stmt|,
name|fpatterns
decl_stmt|,
name|patterns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|pattern
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|epat
modifier|*
name|dpattern
decl_stmt|,
modifier|*
name|fpattern
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|regex_t
modifier|*
name|er_pattern
decl_stmt|,
modifier|*
name|r_pattern
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fastgrep_t
modifier|*
name|fg_pattern
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For regex errors  */
end_comment

begin_define
define|#
directive|define
name|RE_ERROR_BUF
value|512
end_define

begin_decl_stmt
specifier|extern
name|char
name|re_error
index|[
name|RE_ERROR_BUF
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Seems big enough */
end_comment

begin_comment
comment|/* util.c */
end_comment

begin_function_decl
name|bool
name|file_matching
parameter_list|(
specifier|const
name|char
modifier|*
name|fname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|procfile
parameter_list|(
specifier|const
name|char
modifier|*
name|fn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|grep_tree
parameter_list|(
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|grep_malloc
parameter_list|(
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|grep_calloc
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|grep_realloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|grep_strdup
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printline
parameter_list|(
name|struct
name|str
modifier|*
name|line
parameter_list|,
name|int
name|sep
parameter_list|,
name|regmatch_t
modifier|*
name|matches
parameter_list|,
name|int
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* queue.c */
end_comment

begin_function_decl
name|void
name|enqueue
parameter_list|(
name|struct
name|str
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|printqueue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clearqueue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* file.c */
end_comment

begin_function_decl
name|void
name|grep_close
parameter_list|(
name|struct
name|file
modifier|*
name|f
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|file
modifier|*
name|grep_open
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|grep_fgetln
parameter_list|(
name|struct
name|file
modifier|*
name|f
parameter_list|,
name|size_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* fastgrep.c */
end_comment

begin_function_decl
name|int
name|fastcomp
parameter_list|(
name|fastgrep_t
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
name|fgrepcomp
parameter_list|(
name|fastgrep_t
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
name|grep_search
parameter_list|(
name|fastgrep_t
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|regmatch_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

