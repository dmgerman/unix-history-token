begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek.  *  * Redistribution and use in source and binary forms are permitted  * provided that: (1) source distributions retain this entire copyright  * notice and comment, and (2) distributions including binaries display  * the following acknowledgement:  ``This product includes software  * developed by the University of California, Berkeley and its contributors''  * in the documentation or other materials provided with the distribution  * and in all advertising materials mentioning features or use of this  * software. Neither the name of the University nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)div.c	5.1 (Berkeley) 5/16/90"
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

begin_comment
comment|/*  * I AM NOT SURE THIS IS COMPLETELY PORTABLE  * (or that it is even right)  */
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
comment|/* avoid deep thought */
if|if
condition|(
name|num
operator|>
literal|0
operator|&&
name|denom
operator|<
literal|0
condition|)
block|{
name|num
operator|=
operator|-
name|num
expr_stmt|;
name|denom
operator|=
operator|-
name|denom
expr_stmt|;
block|}
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
if|if
condition|(
name|num
operator|<
literal|0
operator|&&
name|denom
operator|>
literal|0
condition|)
block|{
comment|/* 		 * Machine division and remainer may work either way.  The 		 * ANSI standard says that |r.quot|< |n/d| (where n/d 		 * computed in infinite precision).  If the remainder is 		 * positive, we got the `wrong' answer, so fix it. 		 */
if|if
condition|(
name|r
operator|.
name|rem
operator|>
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
block|}
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

end_unit

