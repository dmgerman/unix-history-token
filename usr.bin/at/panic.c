begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   *  panic.c - terminate fast in case of error  *  Copyright (C) 1993  Thomas Koenig  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author(s) may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

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

begin_comment
comment|/* System Headers */
end_comment

begin_include
include|#
directive|include
file|<err.h>
end_include

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
comment|/* External variables */
end_comment

begin_comment
comment|/* Global functions */
end_comment

begin_function
name|void
name|panic
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
block|{
comment|/* Something fatal has happened, print error message and exit.  */
if|if
condition|(
name|fcreated
condition|)
name|unlink
argument_list|(
name|atfile
argument_list|)
expr_stmt|;
name|errx
argument_list|(
name|EXIT_FAILURE
argument_list|,
literal|"%s"
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|perr
parameter_list|(
name|char
modifier|*
name|a
parameter_list|)
block|{
comment|/* Some operating system error; print error message and exit.  */
name|int
name|serrno
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|fcreated
condition|)
name|unlink
argument_list|(
name|atfile
argument_list|)
expr_stmt|;
name|errno
operator|=
name|serrno
expr_stmt|;
name|err
argument_list|(
name|EXIT_FAILURE
argument_list|,
literal|"%s"
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

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
literal|"usage: at [-V] [-q x] [-f file] [-m] time\n"
literal|"       at [-V] -c job [job ...]\n"
literal|"       atq [-V] [-q x] [-v]\n"
literal|"       atrm [-V] job [job ...]\n"
literal|"       batch [-V] [-f file] [-m]\n"
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

