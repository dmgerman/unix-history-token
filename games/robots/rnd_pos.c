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
literal|"@(#)rnd_pos.c	8.1 (Berkeley) 5/31/93"
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
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"robots.h"
end_include

begin_define
define|#
directive|define
name|IS_SAME
parameter_list|(
name|p
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|((p).y != -1&& (p).y == y&& (p).x == x)
end_define

begin_comment
comment|/*  * rnd_pos:  *	Pick a random, unoccupied position  */
end_comment

begin_function
name|COORD
modifier|*
name|rnd_pos
parameter_list|()
block|{
specifier|static
name|COORD
name|pos
decl_stmt|;
specifier|static
name|int
name|call
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
do|do
block|{
name|pos
operator|.
name|y
operator|=
name|rnd
argument_list|(
name|Y_FIELDSIZE
operator|-
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
name|pos
operator|.
name|x
operator|=
name|rnd
argument_list|(
name|X_FIELDSIZE
operator|-
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|Field
index|[
name|pos
operator|.
name|y
index|]
index|[
name|pos
operator|.
name|x
index|]
operator|!=
literal|0
condition|)
do|;
name|call
operator|++
expr_stmt|;
return|return
operator|&
name|pos
return|;
block|}
end_function

begin_macro
name|rnd
argument_list|(
argument|range
argument_list|)
end_macro

begin_decl_stmt
name|int
name|range
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|random
argument_list|()
operator|%
name|range
return|;
block|}
end_block

end_unit

