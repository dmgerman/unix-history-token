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
unit|static char sccsid[] = "@(#)rest.c	8.1 (Berkeley) 5/31/93";
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

begin_comment
comment|/* **  REST FOR REPAIRS ** **	You sit around and wait for repairs to happen.  Actually, you **	sit around and wait for anything to happen.  I do want to point **	out however, that Klingons are not as patient as you are, and **	they tend to attack you while you are resting. ** **	You can never rest through a long range tractor beam. ** **	In events() you will be given an opportunity to cancel the **	rest period if anything momentous happens. */
end_comment

begin_macro
name|rest
argument_list|()
end_macro

begin_block
block|{
name|double
name|t
decl_stmt|;
name|int
name|percent
decl_stmt|;
comment|/* get the time to rest */
name|t
operator|=
name|getfltpar
argument_list|(
literal|"How long"
argument_list|)
expr_stmt|;
if|if
condition|(
name|t
operator|<=
literal|0.0
condition|)
return|return;
name|percent
operator|=
literal|100
operator|*
name|t
operator|/
name|Now
operator|.
name|time
operator|+
literal|0.5
expr_stmt|;
if|if
condition|(
name|percent
operator|>=
literal|70
condition|)
block|{
name|printf
argument_list|(
literal|"Spock: That would take %d%% of our remaining time.\n"
argument_list|,
name|percent
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|getynpar
argument_list|(
literal|"Are you really certain that is wise"
argument_list|)
condition|)
return|return;
block|}
name|Move
operator|.
name|time
operator|=
name|t
expr_stmt|;
comment|/* boundary condition is the LRTB */
name|t
operator|=
name|Now
operator|.
name|eventptr
index|[
name|E_LRTB
index|]
operator|->
name|date
operator|-
name|Now
operator|.
name|date
expr_stmt|;
if|if
condition|(
name|Ship
operator|.
name|cond
operator|!=
name|DOCKED
operator|&&
name|Move
operator|.
name|time
operator|>
name|t
condition|)
name|Move
operator|.
name|time
operator|=
name|t
operator|+
literal|0.0001
expr_stmt|;
name|Move
operator|.
name|free
operator|=
literal|0
expr_stmt|;
name|Move
operator|.
name|resting
operator|=
literal|1
expr_stmt|;
block|}
end_block

end_unit

