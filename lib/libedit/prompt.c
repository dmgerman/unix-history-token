begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Christos Zoulas of Cornell University.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SCCSID
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)prompt.c	8.1 (Berkeley) 6/4/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint&& not SCCSID */
end_comment

begin_comment
comment|/*  * prompt.c: Prompt printing functions  */
end_comment

begin_include
include|#
directive|include
file|"sys.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"el.h"
end_include

begin_decl_stmt
name|private
name|char
modifier|*
name|prompt_default
name|__P
argument_list|(
operator|(
name|EditLine
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* prompt_default():  *	Just a default prompt, in case the user did not provide one  */
end_comment

begin_function
name|private
name|char
modifier|*
comment|/*ARGSUSED*/
name|prompt_default
parameter_list|(
name|el
parameter_list|)
name|EditLine
modifier|*
name|el
decl_stmt|;
block|{
specifier|static
name|char
name|a
index|[
literal|3
index|]
init|=
block|{
literal|'?'
block|,
literal|' '
block|,
literal|'\0'
block|}
decl_stmt|;
return|return
name|a
return|;
block|}
end_function

begin_comment
comment|/* prompt_print():  *	Print the prompt and update the prompt position.  *	We use an array of integers in case we want to pass  * 	literal escape sequences in the prompt and we want a  *	bit to flag them  */
end_comment

begin_function
name|protected
name|void
name|prompt_print
parameter_list|(
name|el
parameter_list|)
name|EditLine
modifier|*
name|el
decl_stmt|;
block|{
name|char
modifier|*
name|p
init|=
call|(
modifier|*
name|el
operator|->
name|el_prompt
operator|.
name|p_func
call|)
argument_list|(
name|el
argument_list|)
decl_stmt|;
while|while
condition|(
operator|*
name|p
condition|)
name|re_putc
argument_list|(
name|el
argument_list|,
operator|*
name|p
operator|++
argument_list|)
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|v
operator|=
name|el
operator|->
name|el_refresh
operator|.
name|r_cursor
operator|.
name|v
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|h
operator|=
name|el
operator|->
name|el_refresh
operator|.
name|r_cursor
operator|.
name|h
expr_stmt|;
block|}
end_function

begin_comment
comment|/* end prompt_print */
end_comment

begin_comment
comment|/* prompt_init():  *	Initialize the prompt stuff  */
end_comment

begin_function
name|protected
name|int
name|prompt_init
parameter_list|(
name|el
parameter_list|)
name|EditLine
modifier|*
name|el
decl_stmt|;
block|{
name|el
operator|->
name|el_prompt
operator|.
name|p_func
operator|=
name|prompt_default
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|v
operator|=
literal|0
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|h
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* end prompt_init */
end_comment

begin_comment
comment|/* prompt_end():  *	Clean up the prompt stuff  */
end_comment

begin_function
name|protected
name|void
comment|/*ARGSUSED*/
name|prompt_end
parameter_list|(
name|el
parameter_list|)
name|EditLine
modifier|*
name|el
decl_stmt|;
block|{ }
end_function

begin_comment
comment|/* end prompt_end */
end_comment

begin_comment
comment|/* prompt_set():  *	Install a prompt printing function  */
end_comment

begin_function
name|protected
name|int
name|prompt_set
parameter_list|(
name|el
parameter_list|,
name|prf
parameter_list|)
name|EditLine
modifier|*
name|el
decl_stmt|;
name|el_pfunc_t
name|prf
decl_stmt|;
block|{
if|if
condition|(
name|prf
operator|==
name|NULL
condition|)
name|el
operator|->
name|el_prompt
operator|.
name|p_func
operator|=
name|prompt_default
expr_stmt|;
else|else
name|el
operator|->
name|el_prompt
operator|.
name|p_func
operator|=
name|prf
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|v
operator|=
literal|0
expr_stmt|;
name|el
operator|->
name|el_prompt
operator|.
name|p_pos
operator|.
name|h
operator|=
literal|0
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* end prompt_set */
end_comment

end_unit

