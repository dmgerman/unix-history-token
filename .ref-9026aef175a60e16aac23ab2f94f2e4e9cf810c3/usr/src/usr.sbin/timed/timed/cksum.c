begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)cksum.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sgi
end_ifdef

begin_empty
empty|#ident "$Revision: 1.3 $"
end_empty

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  *			I N _ C K S U M  *  * Checksum routine for Internet Protocol family headers (C Version)  *  * There is no profit in a specialized version of the checksum  * function for any machine where int's are 32 bits and shorts are 16.  *  * All timed packets are smaller than 32K shorts, so there is no need to  * worry about carries except at the end.  */
end_comment

begin_function
name|int
name|in_cksum
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|)
name|u_short
modifier|*
name|addr
decl_stmt|;
name|int
name|len
decl_stmt|;
block|{
specifier|register
name|int
name|nleft
init|=
name|len
decl_stmt|;
specifier|register
name|u_short
modifier|*
name|w
init|=
name|addr
decl_stmt|;
specifier|register
name|u_short
name|answer
decl_stmt|;
specifier|register
name|int
name|sum
init|=
literal|0
decl_stmt|;
comment|/* 	 *  Our algorithm is simple, using a 32 bit accumulator (sum), 	 *  we add sequential 16 bit words to it, and at the end, fold 	 *  back all the carry bits from the top 16 bits into the lower 	 *  16 bits. 	 */
while|while
condition|(
name|nleft
operator|>
literal|1
condition|)
block|{
name|sum
operator|+=
operator|*
name|w
operator|++
expr_stmt|;
name|nleft
operator|-=
literal|2
expr_stmt|;
block|}
comment|/* mop up an odd byte, if necessary */
if|if
condition|(
name|nleft
operator|==
literal|1
condition|)
name|sum
operator|+=
operator|(
operator|*
operator|(
name|u_char
operator|*
operator|)
name|w
operator|)
operator|<<
literal|8
expr_stmt|;
comment|/* 	 * add back carry outs from top 16 bits to low 16 bits 	 */
name|sum
operator|=
operator|(
name|sum
operator|>>
literal|16
operator|)
operator|+
operator|(
name|sum
operator|&
literal|0xffff
operator|)
expr_stmt|;
comment|/* add hi 16 to low 16 */
name|sum
operator|+=
operator|(
name|sum
operator|>>
literal|16
operator|)
expr_stmt|;
comment|/* add carry */
name|answer
operator|=
operator|~
name|sum
expr_stmt|;
comment|/* truncate to 16 bits */
return|return
operator|(
name|answer
operator|)
return|;
block|}
end_function

end_unit

