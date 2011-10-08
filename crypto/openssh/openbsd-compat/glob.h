begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: glob.h,v 1.11 2010/09/24 13:32:55 djm Exp $	*/
end_comment

begin_comment
comment|/*	$NetBSD: glob.h,v 1.5 1994/10/26 00:55:56 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Guido van Rossum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)glob.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: include/glob.h */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_GLOB_H
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|GLOB_HAS_ALTDIRFUNC
argument_list|)
operator|||
expr|\
operator|!
name|defined
argument_list|(
name|GLOB_HAS_GL_MATCHC
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|GLOB_HAS_GL_STATV
argument_list|)
operator|||
expr|\
operator|!
name|defined
argument_list|(
name|HAVE_DECL_GLOB_NOMATCH
argument_list|)
operator|||
name|HAVE_DECL_GLOB_NOMATCH
operator|==
literal|0
operator|||
expr|\
name|defined
argument_list|(
name|BROKEN_GLOB
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|_GLOB_H_
end_ifndef

begin_define
define|#
directive|define
name|_GLOB_H_
end_define

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_struct_decl
struct_decl|struct
name|stat
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|gl_pathc
decl_stmt|;
comment|/* Count of total paths so far. */
name|int
name|gl_matchc
decl_stmt|;
comment|/* Count of paths matching pattern. */
name|int
name|gl_offs
decl_stmt|;
comment|/* Reserved at beginning of gl_pathv. */
name|int
name|gl_flags
decl_stmt|;
comment|/* Copy of flags parameter to glob. */
name|char
modifier|*
modifier|*
name|gl_pathv
decl_stmt|;
comment|/* List of paths matching pattern. */
name|struct
name|stat
modifier|*
modifier|*
name|gl_statv
decl_stmt|;
comment|/* Stat entries corresponding to gl_pathv */
comment|/* Copy of errfunc parameter to glob. */
name|int
function_decl|(
modifier|*
name|gl_errfunc
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* 	 * Alternate filesystem access methods for glob; replacement 	 * versions of closedir(3), readdir(3), opendir(3), stat(2) 	 * and lstat(2). 	 */
name|void
function_decl|(
modifier|*
name|gl_closedir
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|struct
name|dirent
modifier|*
function_decl|(
modifier|*
name|gl_readdir
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
function_decl|(
modifier|*
name|gl_opendir
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_lstat
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gl_stat
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|stat
modifier|*
parameter_list|)
function_decl|;
block|}
name|glob_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GLOB_APPEND
value|0x0001
end_define

begin_comment
comment|/* Append to output from previous call. */
end_comment

begin_define
define|#
directive|define
name|GLOB_DOOFFS
value|0x0002
end_define

begin_comment
comment|/* Use gl_offs. */
end_comment

begin_define
define|#
directive|define
name|GLOB_ERR
value|0x0004
end_define

begin_comment
comment|/* Return on error. */
end_comment

begin_define
define|#
directive|define
name|GLOB_MARK
value|0x0008
end_define

begin_comment
comment|/* Append / to matching directories. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOCHECK
value|0x0010
end_define

begin_comment
comment|/* Return pattern itself if nothing matches. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSORT
value|0x0020
end_define

begin_comment
comment|/* Don't sort. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOESCAPE
value|0x1000
end_define

begin_comment
comment|/* Disable backslash escaping. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSPACE
value|(-1)
end_define

begin_comment
comment|/* Malloc call failed. */
end_comment

begin_define
define|#
directive|define
name|GLOB_ABORTED
value|(-2)
end_define

begin_comment
comment|/* Unignored error. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOMATCH
value|(-3)
end_define

begin_comment
comment|/* No match and GLOB_NOCHECK not set. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSYS
value|(-4)
end_define

begin_comment
comment|/* Function not supported. */
end_comment

begin_define
define|#
directive|define
name|GLOB_ALTDIRFUNC
value|0x0040
end_define

begin_comment
comment|/* Use alternately specified directory funcs. */
end_comment

begin_define
define|#
directive|define
name|GLOB_BRACE
value|0x0080
end_define

begin_comment
comment|/* Expand braces ala csh. */
end_comment

begin_define
define|#
directive|define
name|GLOB_MAGCHAR
value|0x0100
end_define

begin_comment
comment|/* Pattern had globbing characters. */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOMAGIC
value|0x0200
end_define

begin_comment
comment|/* GLOB_NOCHECK without magic chars (csh). */
end_comment

begin_define
define|#
directive|define
name|GLOB_QUOTE
value|0x0400
end_define

begin_comment
comment|/* Quote special chars with \. */
end_comment

begin_define
define|#
directive|define
name|GLOB_TILDE
value|0x0800
end_define

begin_comment
comment|/* Expand tilde names from the passwd file. */
end_comment

begin_define
define|#
directive|define
name|GLOB_LIMIT
value|0x2000
end_define

begin_comment
comment|/* Limit pattern match output to ARG_MAX */
end_comment

begin_define
define|#
directive|define
name|GLOB_KEEPSTAT
value|0x4000
end_define

begin_comment
comment|/* Retain stat data for paths in gl_statv. */
end_comment

begin_define
define|#
directive|define
name|GLOB_ABEND
value|GLOB_ABORTED
end_define

begin_comment
comment|/* backward compatibility */
end_comment

begin_function_decl
name|int
name|glob
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|glob_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|globfree
parameter_list|(
name|glob_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GLOB_H_ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_GLOB_H) || !defined(GLOB_HAS_ALTDIRFUNC)  || 	  !defined(GLOB_HAS_GL_MATCHC) || !defined(GLOH_HAS_GL_STATV) */
end_comment

end_unit

