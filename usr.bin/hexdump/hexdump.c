begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1989, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
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
unit|static char sccsid[] = "@(#)hexdump.c	8.1 (Berkeley) 6/6/93";
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"hexdump.h"
end_include

begin_decl_stmt
name|FS
modifier|*
name|fshead
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head of format strings */
end_comment

begin_decl_stmt
name|int
name|blocksize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* data block size */
end_comment

begin_decl_stmt
name|int
name|exitval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* final exit value */
end_comment

begin_decl_stmt
name|int
name|length
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* max bytes to read */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
specifier|register
name|FS
modifier|*
name|tfs
decl_stmt|;
name|char
modifier|*
name|p
decl_stmt|;
operator|(
name|void
operator|)
name|setlocale
argument_list|(
name|LC_CTYPE
argument_list|,
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|p
operator|=
name|rindex
argument_list|(
name|argv
index|[
literal|0
index|]
argument_list|,
literal|'o'
argument_list|)
operator|)
operator|||
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"od"
argument_list|)
condition|)
name|newsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
else|else
name|oldsyntax
argument_list|(
name|argc
argument_list|,
operator|&
name|argv
argument_list|)
expr_stmt|;
comment|/* figure out the data block size */
for|for
control|(
name|blocksize
operator|=
literal|0
operator|,
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
block|{
name|tfs
operator|->
name|bcnt
operator|=
name|size
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
if|if
condition|(
name|blocksize
operator|<
name|tfs
operator|->
name|bcnt
condition|)
name|blocksize
operator|=
name|tfs
operator|->
name|bcnt
expr_stmt|;
block|}
comment|/* rewrite the rules, do syntax checking */
for|for
control|(
name|tfs
operator|=
name|fshead
init|;
name|tfs
condition|;
name|tfs
operator|=
name|tfs
operator|->
name|nextfs
control|)
name|rewrite
argument_list|(
name|tfs
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|next
argument_list|(
name|argv
argument_list|)
expr_stmt|;
name|display
argument_list|()
expr_stmt|;
name|exit
argument_list|(
name|exitval
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

