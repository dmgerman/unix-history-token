begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Guido van Rossum.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)glob.h	5.6 (Berkeley) 4/3/91  */
end_comment

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

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|gl_pathc
decl_stmt|;
comment|/* count of total paths so far */
name|int
name|gl_matchc
decl_stmt|;
comment|/* count of paths matching pattern */
name|int
name|gl_offs
decl_stmt|;
comment|/* reserved at beginning of gl_pathv */
name|int
name|gl_flags
decl_stmt|;
comment|/* copy of flags parameter to glob() */
comment|/* copy of errfunc parameter to glob() */
name|int
argument_list|(
argument|*gl_errfunc
argument_list|)
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
name|char
modifier|*
modifier|*
name|gl_pathv
decl_stmt|;
comment|/* list of paths matching pattern */
block|}
name|glob_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GLOB_APPEND
value|0x001
end_define

begin_comment
comment|/* append to output from previous call */
end_comment

begin_define
define|#
directive|define
name|GLOB_DOOFFS
value|0x002
end_define

begin_comment
comment|/* use gl_offs */
end_comment

begin_define
define|#
directive|define
name|GLOB_ERR
value|0x004
end_define

begin_comment
comment|/* return on error */
end_comment

begin_define
define|#
directive|define
name|GLOB_MAGCHAR
value|0x008
end_define

begin_comment
comment|/* pattern had globbing characters */
end_comment

begin_define
define|#
directive|define
name|GLOB_MARK
value|0x010
end_define

begin_comment
comment|/* append / to matching directories */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOCHECK
value|0x020
end_define

begin_comment
comment|/* return pattern itself if nothing matches */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSORT
value|0x040
end_define

begin_comment
comment|/* don't sort */
end_comment

begin_define
define|#
directive|define
name|GLOB_QUOTE
value|0x080
end_define

begin_comment
comment|/* quote special chars with \ */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOMAGIC
value|0x100
end_define

begin_comment
comment|/* like GLOB_NOCHECK but only if the pattern 				 * did not have any magic characters */
end_comment

begin_define
define|#
directive|define
name|GLOB_ALTNOT
value|0x200
end_define

begin_comment
comment|/* use alternate glob character [^ not !] */
end_comment

begin_define
define|#
directive|define
name|GLOB_NOSPACE
value|(-1)
end_define

begin_comment
comment|/* malloc call failed */
end_comment

begin_define
define|#
directive|define
name|GLOB_ABEND
value|(-2)
end_define

begin_comment
comment|/* unignored error */
end_comment

begin_decl_stmt
name|int
name|glob
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|,
name|int
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|glob_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|globfree
name|__P
argument_list|(
operator|(
name|glob_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|globcharcoll
name|__P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GLOB_H_ */
end_comment

end_unit

