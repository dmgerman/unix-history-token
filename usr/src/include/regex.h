begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 Henry Spencer.  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Henry Spencer of the University of Toronto.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)regex.h	8.2 (Berkeley) 1/3/94  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEX_H_
end_ifndef

begin_define
define|#
directive|define
name|_REGEX_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* types */
end_comment

begin_typedef
typedef|typedef
name|off_t
name|regoff_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|re_magic
decl_stmt|;
name|size_t
name|re_nsub
decl_stmt|;
comment|/* number of parenthesized subexpressions */
name|__const
name|char
modifier|*
name|re_endp
decl_stmt|;
comment|/* end pointer for REG_PEND */
name|struct
name|re_guts
modifier|*
name|re_g
decl_stmt|;
comment|/* none of your business :-) */
block|}
name|regex_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|regoff_t
name|rm_so
decl_stmt|;
comment|/* start of match */
name|regoff_t
name|rm_eo
decl_stmt|;
comment|/* end of match */
block|}
name|regmatch_t
typedef|;
end_typedef

begin_comment
comment|/* regcomp() flags */
end_comment

begin_define
define|#
directive|define
name|REG_BASIC
value|0000
end_define

begin_define
define|#
directive|define
name|REG_EXTENDED
value|0001
end_define

begin_define
define|#
directive|define
name|REG_ICASE
value|0002
end_define

begin_define
define|#
directive|define
name|REG_NOSUB
value|0004
end_define

begin_define
define|#
directive|define
name|REG_NEWLINE
value|0010
end_define

begin_define
define|#
directive|define
name|REG_NOSPEC
value|0020
end_define

begin_define
define|#
directive|define
name|REG_PEND
value|0040
end_define

begin_define
define|#
directive|define
name|REG_DUMP
value|0200
end_define

begin_comment
comment|/* regerror() flags */
end_comment

begin_define
define|#
directive|define
name|REG_NOMATCH
value|1
end_define

begin_define
define|#
directive|define
name|REG_BADPAT
value|2
end_define

begin_define
define|#
directive|define
name|REG_ECOLLATE
value|3
end_define

begin_define
define|#
directive|define
name|REG_ECTYPE
value|4
end_define

begin_define
define|#
directive|define
name|REG_EESCAPE
value|5
end_define

begin_define
define|#
directive|define
name|REG_ESUBREG
value|6
end_define

begin_define
define|#
directive|define
name|REG_EBRACK
value|7
end_define

begin_define
define|#
directive|define
name|REG_EPAREN
value|8
end_define

begin_define
define|#
directive|define
name|REG_EBRACE
value|9
end_define

begin_define
define|#
directive|define
name|REG_BADBR
value|10
end_define

begin_define
define|#
directive|define
name|REG_ERANGE
value|11
end_define

begin_define
define|#
directive|define
name|REG_ESPACE
value|12
end_define

begin_define
define|#
directive|define
name|REG_BADRPT
value|13
end_define

begin_define
define|#
directive|define
name|REG_EMPTY
value|14
end_define

begin_define
define|#
directive|define
name|REG_ASSERT
value|15
end_define

begin_define
define|#
directive|define
name|REG_INVARG
value|16
end_define

begin_define
define|#
directive|define
name|REG_ATOI
value|255
end_define

begin_comment
comment|/* convert name to number (!) */
end_comment

begin_define
define|#
directive|define
name|REG_ITOA
value|0400
end_define

begin_comment
comment|/* convert number to name (!) */
end_comment

begin_comment
comment|/* regexec() flags */
end_comment

begin_define
define|#
directive|define
name|REG_NOTBOL
value|00001
end_define

begin_define
define|#
directive|define
name|REG_NOTEOL
value|00002
end_define

begin_define
define|#
directive|define
name|REG_STARTEND
value|00004
end_define

begin_define
define|#
directive|define
name|REG_TRACE
value|00400
end_define

begin_comment
comment|/* tracing of execution */
end_comment

begin_define
define|#
directive|define
name|REG_LARGE
value|01000
end_define

begin_comment
comment|/* force large representation */
end_comment

begin_define
define|#
directive|define
name|REG_BACKR
value|02000
end_define

begin_comment
comment|/* force use of backref code */
end_comment

begin_decl_stmt
name|__BEGIN_DECLS
name|int
name|regcomp
name|__P
argument_list|(
operator|(
name|regex_t
operator|*
operator|,
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
name|size_t
name|regerror
name|__P
argument_list|(
operator|(
name|int
operator|,
specifier|const
name|regex_t
operator|*
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
name|int
name|regexec
name|__P
argument_list|(
operator|(
specifier|const
name|regex_t
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|size_t
operator|,
name|regmatch_t
index|[]
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regfree
name|__P
argument_list|(
operator|(
name|regex_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_REGEX_H_ */
end_comment

end_unit

