begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)random.c	7.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<libkern/libkern.h>
end_include

begin_comment
comment|/*  * Pseudo-random number generator for randomizing the profiling clock,  * and whatever else we might use it for.  The result is uniform on  * [0, 2^31 - 1].  */
end_comment

begin_function
name|u_long
name|random
parameter_list|()
block|{
specifier|static
name|u_long
name|randseed
init|=
literal|1
decl_stmt|;
specifier|register
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

