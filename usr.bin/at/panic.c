begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * panic.c - terminate fast in case of error  * Copyright (c) 1993 by Thomas Koenig  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author(s) may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* System Headers */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
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
file|<unistd.h>
end_include

begin_comment
comment|/* Local headers */
end_comment

begin_include
include|#
directive|include
file|"panic.h"
end_include

begin_include
include|#
directive|include
file|"at.h"
end_include

begin_comment
comment|/* File scope variables */
end_comment

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Id: panic.c,v 1.1 1993/12/05 11:36:51 cgd Exp $"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* External variables */
end_comment

begin_comment
comment|/* Global functions */
end_comment

begin_function
name|void
name|panic
parameter_list|(
name|a
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|;
block|{
comment|/* Something fatal has happened, print error message and exit.  */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: %s\n"
argument_list|,
name|namep
argument_list|,
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcreated
condition|)
name|unlink
argument_list|(
name|atfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|perr
parameter_list|(
name|a
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|;
block|{
comment|/* Some operating system error; print error message and exit.  */
name|perror
argument_list|(
name|a
argument_list|)
expr_stmt|;
if|if
condition|(
name|fcreated
condition|)
name|unlink
argument_list|(
name|atfile
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|perr2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|a
argument_list|)
expr_stmt|;
name|perr
argument_list|(
name|b
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|void
name|usage
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Print usage and exit. */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: at [-q x] [-f file] [-m] time\n"
literal|"       atq [-q x] [-v]\n"
literal|"       atrm [-q x] job ...\n"
literal|"       batch [-f file] [-m]\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|EXIT_FAILURE
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

