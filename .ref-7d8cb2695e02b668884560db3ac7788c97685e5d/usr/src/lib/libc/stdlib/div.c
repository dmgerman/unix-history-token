begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * %sccs.include.redist.c%  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)div.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* div_t */
end_comment

begin_function
name|div_t
name|div
parameter_list|(
name|num
parameter_list|,
name|denom
parameter_list|)
name|int
name|num
decl_stmt|,
name|denom
decl_stmt|;
block|{
name|div_t
name|r
decl_stmt|;
name|r
operator|.
name|quot
operator|=
name|num
operator|/
name|denom
expr_stmt|;
name|r
operator|.
name|rem
operator|=
name|num
operator|%
name|denom
expr_stmt|;
comment|/* 	 * The ANSI standard says that |r.quot|<= |n/d|, where 	 * n/d is to be computed in infinite precision.  In other 	 * words, we should always truncate the quotient towards 	 * 0, never -infinity. 	 * 	 * Machine division and remainer may work either way when 	 * one or both of n or d is negative.  If only one is 	 * negative and r.quot has been truncated towards -inf, 	 * r.rem will have the same sign as denom and the opposite 	 * sign of num; if both are negative and r.quot has been 	 * truncated towards -inf, r.rem will be positive (will 	 * have the opposite sign of num).  These are considered 	 * `wrong'. 	 * 	 * If both are num and denom are positive, r will always 	 * be positive. 	 * 	 * This all boils down to: 	 *	if num>= 0, but r.rem< 0, we got the wrong answer. 	 * In that case, to get the right answer, add 1 to r.quot and 	 * subtract denom from r.rem. 	 */
if|if
condition|(
name|num
operator|>=
literal|0
operator|&&
name|r
operator|.
name|rem
operator|<
literal|0
condition|)
block|{
name|r
operator|.
name|quot
operator|++
expr_stmt|;
name|r
operator|.
name|rem
operator|-=
name|denom
expr_stmt|;
block|}
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

end_unit

