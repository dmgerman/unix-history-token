begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Mark Nudleman  * Copyright (c) 1988, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)ttyin.c	8.1 (Berkeley) 6/6/93"
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
comment|/*  * Routines dealing with getting input from the keyboard (i.e. from the user).  */
end_comment

begin_include
include|#
directive|include
file|<less.h>
end_include

begin_decl_stmt
specifier|static
name|int
name|tty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Open keyboard for input.  * (Just use file descriptor 2.)  */
end_comment

begin_macro
name|open_getchr
argument_list|()
end_macro

begin_block
block|{
name|tty
operator|=
literal|2
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Get a character from the keyboard.  */
end_comment

begin_macro
name|getchr
argument_list|()
end_macro

begin_block
block|{
name|char
name|c
decl_stmt|;
name|int
name|result
decl_stmt|;
do|do
block|{
name|result
operator|=
name|iread
argument_list|(
name|tty
argument_list|,
operator|&
name|c
argument_list|,
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|result
operator|==
name|READ_INTR
condition|)
return|return
operator|(
name|READ_INTR
operator|)
return|;
if|if
condition|(
name|result
operator|<
literal|0
condition|)
block|{
comment|/* 			 * Don't call error() here, 			 * because error calls getchr! 			 */
name|quit
argument_list|()
expr_stmt|;
block|}
block|}
do|while
condition|(
name|result
operator|!=
literal|1
operator|||
name|c
operator|==
literal|0
condition|)
do|;
return|return
operator|(
operator|(
name|unsigned
name|char
operator|)
name|c
operator|)
return|;
block|}
end_block

end_unit

