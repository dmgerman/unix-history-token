begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 by University of Toronto.  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley  * by Henry Spencer.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)regexp.h	8.1 (Berkeley) 6/2/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_REGEXP_H_
end_ifndef

begin_define
define|#
directive|define
name|_REGEXP_H_
end_define

begin_comment
comment|/*  * Definitions etc. for regexp(3) routines.  *  * Caveat:  this is V8 regexp(3) [actually, a reimplementation thereof],  * not the System V one.  */
end_comment

begin_define
define|#
directive|define
name|NSUBEXP
value|10
end_define

begin_typedef
typedef|typedef
struct|struct
name|regexp
block|{
name|char
modifier|*
name|startp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
modifier|*
name|endp
index|[
name|NSUBEXP
index|]
decl_stmt|;
name|char
name|regstart
decl_stmt|;
comment|/* Internal use only. */
name|char
name|reganch
decl_stmt|;
comment|/* Internal use only. */
name|char
modifier|*
name|regmust
decl_stmt|;
comment|/* Internal use only. */
name|int
name|regmlen
decl_stmt|;
comment|/* Internal use only. */
name|char
name|program
index|[
literal|1
index|]
decl_stmt|;
comment|/* Unwarranted chumminess with compiler. */
block|}
name|regexp
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|regexp
modifier|*
name|regcomp
name|__P
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
name|regexec
name|__P
argument_list|(
operator|(
specifier|const
name|regexp
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
name|regsub
name|__P
argument_list|(
operator|(
specifier|const
name|regexp
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|regerror
name|__P
argument_list|(
operator|(
specifier|const
name|char
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
comment|/* !_REGEXP_H_ */
end_comment

end_unit

