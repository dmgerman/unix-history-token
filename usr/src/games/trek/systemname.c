begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)systemname.c	8.1 (Berkeley) 5/31/93"
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
comment|/* **  RETRIEVE THE STARSYSTEM NAME ** **	Very straightforward, this routine just gets the starsystem **	name.  It returns zero if none in the specified quadrant **	(which, by the way, is passed it). ** **	This routine knows all about such things as distressed **	starsystems, etc. */
end_comment

begin_function
name|char
modifier|*
name|systemname
parameter_list|(
name|q1
parameter_list|)
name|struct
name|quad
modifier|*
name|q1
decl_stmt|;
block|{
specifier|register
name|struct
name|quad
modifier|*
name|q
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|q
operator|=
name|q1
expr_stmt|;
name|i
operator|=
name|q
operator|->
name|qsystemname
expr_stmt|;
if|if
condition|(
name|i
operator|&
name|Q_DISTRESSED
condition|)
name|i
operator|=
name|Event
index|[
name|i
operator|&
name|Q_SYSTEM
index|]
operator|.
name|systemname
expr_stmt|;
name|i
operator|&=
name|Q_SYSTEM
expr_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
return|return
operator|(
name|Systemname
index|[
name|i
index|]
operator|)
return|;
block|}
end_function

end_unit

