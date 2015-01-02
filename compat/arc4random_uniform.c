begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*      $OpenBSD: arc4random_uniform.c,v 1.1 2014/07/12 13:24:54 deraadt Exp $  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, Damien Miller<djm@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/*  * Calculate a uniformly distributed random number less than upper_bound  * avoiding "modulo bias".  *  * Uniformity is achieved by generating new random numbers until the one  * returned is outside the range [0, 2**32 % upper_bound).  This  * guarantees the selected random number will be inside  * [2**32 % upper_bound, 2**32) which maps back to [0, upper_bound)  * after reduction modulo upper_bound.  */
end_comment

begin_function
name|uint32_t
name|arc4random_uniform
parameter_list|(
name|uint32_t
name|upper_bound
parameter_list|)
block|{
name|uint32_t
name|r
decl_stmt|,
name|min
decl_stmt|;
if|if
condition|(
name|upper_bound
operator|<
literal|2
condition|)
return|return
literal|0
return|;
comment|/* 2**32 % x == (2**32 - x) % x */
name|min
operator|=
operator|-
name|upper_bound
operator|%
name|upper_bound
expr_stmt|;
comment|/* 	 * This could theoretically loop forever but each retry has 	 * p> 0.5 (worst case, usually far better) of selecting a 	 * number inside the range we need, so it should rarely need 	 * to re-roll. 	 */
for|for
control|(
init|;
condition|;
control|)
block|{
name|r
operator|=
name|arc4random
argument_list|()
expr_stmt|;
if|if
condition|(
name|r
operator|>=
name|min
condition|)
break|break;
block|}
return|return
name|r
operator|%
name|upper_bound
return|;
block|}
end_function

end_unit

