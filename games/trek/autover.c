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
unit|static char sccsid[] = "@(#)autover.c	8.1 (Berkeley) 5/31/93";
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

begin_comment
comment|/* **  Automatic Override ** **	If we should be so unlucky as to be caught in a quadrant **	with a supernova in it, this routine is called.  It is **	called from checkcond(). ** **	It sets you to a random warp (guaranteed to be over 6.0) **	and starts sending you off "somewhere" (whereever that is). ** **	Please note that it is VERY important that you reset your **	warp speed after the automatic override is called.  The new **	warp factor does not stay in effect for just this routine. ** **	This routine will never try to send you more than sqrt(2) **	quadrants, since that is all that is needed. */
end_comment

begin_macro
name|autover
argument_list|()
end_macro

begin_block
block|{
name|double
name|dist
decl_stmt|;
name|int
name|course
decl_stmt|;
name|printf
argument_list|(
literal|"\07RED ALERT:  The %s is in a supernova quadrant\n"
argument_list|,
name|Ship
operator|.
name|shipname
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"***  Emergency override attempts to hurl %s to safety\n"
argument_list|,
name|Ship
operator|.
name|shipname
argument_list|)
expr_stmt|;
comment|/* let's get our ass out of here */
name|Ship
operator|.
name|warp
operator|=
literal|6.0
operator|+
literal|2.0
operator|*
name|franf
argument_list|()
expr_stmt|;
name|Ship
operator|.
name|warp2
operator|=
name|Ship
operator|.
name|warp
operator|*
name|Ship
operator|.
name|warp
expr_stmt|;
name|Ship
operator|.
name|warp3
operator|=
name|Ship
operator|.
name|warp2
operator|*
name|Ship
operator|.
name|warp
expr_stmt|;
name|dist
operator|=
literal|0.75
operator|*
name|Ship
operator|.
name|energy
operator|/
operator|(
name|Ship
operator|.
name|warp3
operator|*
operator|(
name|Ship
operator|.
name|shldup
operator|+
literal|1
operator|)
operator|)
expr_stmt|;
if|if
condition|(
name|dist
operator|>
literal|1.4142
condition|)
name|dist
operator|=
literal|1.4142
expr_stmt|;
name|course
operator|=
name|ranf
argument_list|(
literal|360
argument_list|)
expr_stmt|;
name|Etc
operator|.
name|nkling
operator|=
operator|-
literal|1
expr_stmt|;
name|Ship
operator|.
name|cond
operator|=
name|RED
expr_stmt|;
name|warp
argument_list|(
operator|-
literal|1
argument_list|,
name|course
argument_list|,
name|dist
argument_list|)
expr_stmt|;
name|attack
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

