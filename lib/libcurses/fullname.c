begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1981, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)fullname.c	8.1 (Berkeley) 6/4/93"
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
comment|/*  * fullname --  *	This routine fills in "def" with the full name of the terminal.  *	This is assumed to be the last name in the list of aliases.  */
end_comment

begin_function
name|char
modifier|*
name|fullname
parameter_list|(
name|bp
parameter_list|,
name|def
parameter_list|)
specifier|register
name|char
modifier|*
name|bp
decl_stmt|,
decl|*
name|def
decl_stmt|;
end_function

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
operator|*
name|def
operator|=
literal|'\0'
expr_stmt|;
comment|/* In case no name. */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
condition|)
block|{
name|cp
operator|=
name|def
expr_stmt|;
comment|/* Start of answer. */
while|while
condition|(
operator|*
name|bp
operator|&&
operator|*
name|bp
operator|!=
literal|':'
operator|&&
operator|*
name|bp
operator|!=
literal|'|'
condition|)
operator|*
name|cp
operator|++
operator|=
operator|*
name|bp
operator|++
expr_stmt|;
comment|/* Copy name over. */
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
comment|/* Zero end of name. */
if|if
condition|(
operator|*
name|bp
operator|==
literal|'|'
condition|)
name|bp
operator|++
expr_stmt|;
comment|/* Skip over '|' if that is case. */
block|}
return|return
operator|(
name|def
operator|)
return|;
block|}
end_block

end_unit

