begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)REMOVE.c	8.1 (Berkeley) 6/6/93"
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
file|"h00vars.h"
end_include

begin_macro
name|REMOVE
argument_list|(
argument|name
argument_list|,
argument|namlim
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|namlim
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|cnt
decl_stmt|;
specifier|register
name|int
name|maxnamlen
init|=
name|namlim
decl_stmt|;
name|char
name|namebuf
index|[
name|NAMSIZ
index|]
decl_stmt|;
comment|/* 	 * trim trailing blanks, and insure that the name  	 * will fit into the file structure 	 */
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|maxnamlen
condition|;
name|cnt
operator|++
control|)
if|if
condition|(
name|name
index|[
name|cnt
index|]
operator|==
literal|'\0'
operator|||
name|name
index|[
name|cnt
index|]
operator|==
literal|' '
condition|)
break|break;
if|if
condition|(
name|cnt
operator|>=
name|NAMSIZ
condition|)
block|{
name|ERROR
argument_list|(
literal|"%s: File name too long\n"
argument_list|,
name|name
argument_list|)
expr_stmt|;
return|return;
block|}
name|maxnamlen
operator|=
name|cnt
expr_stmt|;
comment|/* 	 * put the name into the buffer with null termination 	 */
for|for
control|(
name|cnt
operator|=
literal|0
init|;
name|cnt
operator|<
name|maxnamlen
condition|;
name|cnt
operator|++
control|)
name|namebuf
index|[
name|cnt
index|]
operator|=
name|name
index|[
name|cnt
index|]
expr_stmt|;
name|namebuf
index|[
name|cnt
index|]
operator|=
literal|'\0'
expr_stmt|;
comment|/* 	 * unlink the file 	 */
if|if
condition|(
name|unlink
argument_list|(
name|namebuf
argument_list|)
condition|)
block|{
name|PERROR
argument_list|(
literal|"Could not remove "
argument_list|,
name|namebuf
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

