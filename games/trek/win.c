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
unit|static char sccsid[] = "@(#)win.c	8.1 (Berkeley) 5/31/93";
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
file|"trek.h"
end_include

begin_include
include|#
directive|include
file|"getpar.h"
end_include

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_comment
comment|/* **  Signal game won ** **	This routine prints out the win message, arranges to print out **	your score, tells you if you have a promotion coming to you, **	cleans up the current input line, and arranges to have you **	asked whether or not you want another game (via the longjmp() **	call). ** **	Pretty straightforward, although the promotion algorithm is **	pretty off the wall. */
end_comment

begin_macro
name|win
argument_list|()
end_macro

begin_block
block|{
name|long
name|s
decl_stmt|;
specifier|extern
name|jmp_buf
name|env
decl_stmt|;
specifier|extern
name|long
name|score
parameter_list|()
function_decl|;
specifier|extern
name|struct
name|cvntab
name|Skitab
index|[]
decl_stmt|;
name|struct
name|cvntab
modifier|*
name|p
decl_stmt|;
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\nCongratulations, you have saved the Federation\n"
argument_list|)
expr_stmt|;
name|Move
operator|.
name|endgame
operator|=
literal|1
expr_stmt|;
comment|/* print and return the score */
name|s
operator|=
name|score
argument_list|()
expr_stmt|;
comment|/* decide if she gets a promotion */
if|if
condition|(
name|Game
operator|.
name|helps
operator|==
literal|0
operator|&&
name|Game
operator|.
name|killb
operator|==
literal|0
operator|&&
name|Game
operator|.
name|killinhab
operator|==
literal|0
operator|&&
literal|5
operator|*
name|Game
operator|.
name|kills
operator|+
name|Game
operator|.
name|deaths
operator|<
literal|100
operator|&&
name|s
operator|>=
literal|1000
operator|&&
name|Ship
operator|.
name|ship
operator|==
name|ENTERPRISE
condition|)
block|{
name|printf
argument_list|(
literal|"In fact, you are promoted one step in rank,\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|Game
operator|.
name|skill
operator|>=
literal|6
condition|)
name|printf
argument_list|(
literal|"to the exalted rank of Commodore Emeritus\n"
argument_list|)
expr_stmt|;
else|else
block|{
name|p
operator|=
operator|&
name|Skitab
index|[
name|Game
operator|.
name|skill
operator|-
literal|1
index|]
expr_stmt|;
name|printf
argument_list|(
literal|"from %s%s "
argument_list|,
name|p
operator|->
name|abrev
argument_list|,
name|p
operator|->
name|full
argument_list|)
expr_stmt|;
name|p
operator|++
expr_stmt|;
name|printf
argument_list|(
literal|"to %s%s\n"
argument_list|,
name|p
operator|->
name|abrev
argument_list|,
name|p
operator|->
name|full
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* clean out input, and request new game */
name|skiptonl
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|longjmp
argument_list|(
name|env
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

