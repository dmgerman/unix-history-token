begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)error.c	5.3 (Berkeley) 4/16/91"
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
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|PI1
end_ifndef

begin_include
include|#
directive|include
file|"tree_ty.h"
end_include

begin_comment
comment|/* must be included for yy.h */
end_comment

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|errpfx
init|=
literal|'E'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Panic is called when impossible  * (supposedly, anyways) situations  * are encountered.  * Panic messages should be short  * as they do not go to the message  * file.  */
end_comment

begin_macro
name|panic
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
ifdef|#
directive|ifdef
name|PI1
name|printf
argument_list|(
literal|"Snark (%s) line=%d\n"
argument_list|,
name|s
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
else|#
directive|else
name|printf
argument_list|(
literal|"Snark (%s) line=%d, yyline=%d\n"
argument_list|,
name|s
argument_list|,
name|line
argument_list|,
name|yyline
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* die horribly */
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PI1
name|Perror
argument_list|(
literal|"Snark in pi1"
argument_list|,
name|s
argument_list|)
expr_stmt|;
else|#
directive|else
name|Perror
argument_list|(
literal|"Snark in pi"
argument_list|,
name|s
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pexit
argument_list|(
name|DIED
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Error is called for  * semantic errors and  * prints the error and  * a line number.  */
end_comment

begin_comment
comment|/*VARARGS1*/
end_comment

begin_expr_stmt
name|error
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|)
specifier|register
name|char
operator|*
name|a1
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|char
name|errbuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* was extern. why? ...pbk */
specifier|register
name|int
name|i
decl_stmt|;
if|if
condition|(
name|errpfx
operator|==
literal|'w'
operator|&&
name|opt
argument_list|(
literal|'w'
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|errpfx
operator|=
literal|'E'
expr_stmt|;
return|return;
block|}
name|Enocascade
operator|=
name|FALSE
expr_stmt|;
name|geterr
argument_list|(
operator|(
name|int
operator|)
name|a1
argument_list|,
name|errbuf
argument_list|)
expr_stmt|;
name|a1
operator|=
name|errbuf
expr_stmt|;
if|if
condition|(
name|line
operator|<
literal|0
condition|)
name|line
operator|=
operator|-
name|line
expr_stmt|;
ifndef|#
directive|ifndef
name|PI1
if|if
condition|(
name|opt
argument_list|(
literal|'l'
argument_list|)
condition|)
name|yyoutline
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|yysetfile
argument_list|(
name|filename
argument_list|)
expr_stmt|;
if|if
condition|(
name|errpfx
operator|==
literal|' '
condition|)
block|{
name|printf
argument_list|(
literal|"  "
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|line
init|;
name|i
operator|>=
literal|10
condition|;
name|i
operator|/=
literal|10
control|)
name|pchr
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"... "
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|Enoline
condition|)
name|printf
argument_list|(
literal|"  %c - "
argument_list|,
name|errpfx
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"%c %d - "
argument_list|,
name|errpfx
argument_list|,
name|line
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|)
expr_stmt|;
if|if
condition|(
name|errpfx
operator|==
literal|'E'
condition|)
ifndef|#
directive|ifndef
name|PI0
name|eflg
operator|=
name|TRUE
operator|,
name|codeoff
argument_list|()
expr_stmt|;
else|#
directive|else
name|eflg
operator|=
name|TRUE
expr_stmt|;
endif|#
directive|endif
name|errpfx
operator|=
literal|'E'
expr_stmt|;
if|if
condition|(
name|Eholdnl
condition|)
name|Eholdnl
operator|=
name|FALSE
expr_stmt|;
else|else
name|pchr
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*VARARGS1*/
end_comment

begin_macro
name|cerror
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|,
argument|a5
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|a1
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|Enocascade
condition|)
return|return;
name|setpfx
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
name|error
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|PI1
end_ifdef

begin_comment
comment|/*VARARGS*/
end_comment

begin_macro
name|derror
argument_list|(
argument|a1
argument_list|,
argument|a2
argument_list|,
argument|a3
argument_list|,
argument|a4
argument_list|,
argument|a5
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|a1
decl_stmt|,
modifier|*
name|a2
decl_stmt|,
modifier|*
name|a3
decl_stmt|,
modifier|*
name|a4
decl_stmt|,
modifier|*
name|a5
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|holdderr
condition|)
name|error
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
name|a4
argument_list|,
name|a5
argument_list|)
expr_stmt|;
name|errpfx
operator|=
literal|'E'
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|char
modifier|*
name|lastname
decl_stmt|,
name|printed
decl_stmt|,
name|hadsome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	this yysetfile for PI1 only.      *	the real yysetfile is in yyput.c      */
end_comment

begin_macro
name|yysetfile
argument_list|(
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|lastname
operator|==
name|name
condition|)
return|return;
name|printed
operator||=
literal|1
expr_stmt|;
name|gettime
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s  %s:\n"
argument_list|,
name|myctime
argument_list|(
operator|&
name|tvec
argument_list|)
argument_list|,
name|name
argument_list|)
expr_stmt|;
name|lastname
operator|=
name|name
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

