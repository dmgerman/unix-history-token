begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static char sccsid[] = "@(#)query.c	8.1 (Berkeley) 5/31/93";
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"robots.h"
end_include

begin_comment
comment|/*  * query:  *	Ask a question and get a yes or no answer.  Default is "no".  */
end_comment

begin_macro
name|query
argument_list|(
argument|prompt
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|prompt
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|c
decl_stmt|,
name|retval
decl_stmt|;
name|int
name|y
decl_stmt|,
name|x
decl_stmt|;
name|getyx
argument_list|(
name|stdscr
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|Y_PROMPT
argument_list|,
name|X_PROMPT
argument_list|)
expr_stmt|;
name|addstr
argument_list|(
name|prompt
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
name|retval
operator|=
operator|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|==
literal|'y'
operator|||
name|c
operator|==
literal|'Y'
operator|)
expr_stmt|;
name|move
argument_list|(
name|Y_PROMPT
argument_list|,
name|X_PROMPT
argument_list|)
expr_stmt|;
name|clrtoeol
argument_list|()
expr_stmt|;
name|move
argument_list|(
name|y
argument_list|,
name|x
argument_list|)
expr_stmt|;
return|return
name|retval
return|;
block|}
end_block

end_unit

