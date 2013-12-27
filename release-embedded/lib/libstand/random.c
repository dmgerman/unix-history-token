begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)random.c	8.1 (Berkeley) 6/10/93  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_decl_stmt
specifier|static
name|u_long
name|randseed
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|srandom
parameter_list|(
name|seed
parameter_list|)
name|u_long
name|seed
decl_stmt|;
block|{
name|randseed
operator|=
name|seed
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * Pseudo-random number generator for randomizing the profiling clock,  * and whatever else we might use it for.  The result is uniform on  * [0, 2^31 - 1].  */
end_comment

begin_function
name|u_long
name|random
parameter_list|()
block|{
name|long
name|x
decl_stmt|,
name|hi
decl_stmt|,
name|lo
decl_stmt|,
name|t
decl_stmt|;
comment|/* 	 * Compute x[n + 1] = (7^5 * x[n]) mod (2^31 - 1). 	 * From "Random number generators: good ones are hard to find", 	 * Park and Miller, Communications of the ACM, vol. 31, no. 10, 	 * October 1988, p. 1195. 	 */
name|x
operator|=
name|randseed
expr_stmt|;
name|hi
operator|=
name|x
operator|/
literal|127773
expr_stmt|;
name|lo
operator|=
name|x
operator|%
literal|127773
expr_stmt|;
name|t
operator|=
literal|16807
operator|*
name|lo
operator|-
literal|2836
operator|*
name|hi
expr_stmt|;
if|if
condition|(
name|t
operator|<=
literal|0
condition|)
name|t
operator|+=
literal|0x7fffffff
expr_stmt|;
name|randseed
operator|=
name|t
expr_stmt|;
return|return
operator|(
name|t
operator|)
return|;
block|}
end_function

end_unit

