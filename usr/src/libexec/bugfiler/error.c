begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986, 1987, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)error.c	8.1 (Berkeley) 6/4/93"
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
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|"bug.h"
end_include

begin_include
include|#
directive|include
file|"extern.h"
end_include

begin_decl_stmt
specifier|static
name|short
name|err_redir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stderr redirected */
end_comment

begin_comment
comment|/*  * seterr --  *	redirect stderr for error processing  */
end_comment

begin_function
name|void
name|seterr
parameter_list|()
block|{
if|if
condition|(
operator|!
name|freopen
argument_list|(
name|ERROR_FILE
argument_list|,
literal|"a"
argument_list|,
name|stderr
argument_list|)
condition|)
name|error
argument_list|(
literal|"can't open error file %s."
argument_list|,
name|ERROR_FILE
argument_list|)
expr_stmt|;
name|err_redir
operator|=
name|YES
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * error --  *	write errors to log file and die  */
end_comment

begin_function
name|void
name|error
parameter_list|(
name|fmt
parameter_list|,
name|arg
parameter_list|)
specifier|register
name|char
modifier|*
name|fmt
decl_stmt|,
decl|*
name|arg
decl_stmt|;
end_function

begin_block
block|{
specifier|static
name|char
name|logmsg
index|[
name|MAXLINELEN
index|]
decl_stmt|;
comment|/* syslog message */
if|if
condition|(
name|err_redir
condition|)
block|{
comment|/* don't combine these, "fmt" may not require "arg" */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\t%s\n\t"
argument_list|,
name|tmpname
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|sprintf
argument_list|(
name|logmsg
argument_list|,
literal|"bugfiler: %s"
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
name|logmsg
argument_list|,
name|arg
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|METOO
name|exit
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
else|#
directive|else
name|exit
argument_list|(
name|OK
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_block

end_unit

