begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2008 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<dt_impl.h>
end_include

begin_define
define|#
directive|define
name|DT_MASK_LO
value|0x00000000FFFFFFFFULL
end_define

begin_comment
comment|/*  * We declare this here because (1) we need it and (2) we want to avoid a  * dependency on libm in libdtrace.  */
end_comment

begin_function
specifier|static
name|long
name|double
name|dt_fabsl
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
if|if
condition|(
name|x
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
name|x
operator|)
return|;
return|return
operator|(
name|x
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * 128-bit arithmetic functions needed to support the stddev() aggregating  * action.  */
end_comment

begin_function
specifier|static
name|int
name|dt_gt_128
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64_t
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|1
index|]
operator|>
name|b
index|[
literal|1
index|]
operator|||
operator|(
name|a
index|[
literal|1
index|]
operator|==
name|b
index|[
literal|1
index|]
operator|&&
name|a
index|[
literal|0
index|]
operator|>
name|b
index|[
literal|0
index|]
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dt_ge_128
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64_t
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|1
index|]
operator|>
name|b
index|[
literal|1
index|]
operator|||
operator|(
name|a
index|[
literal|1
index|]
operator|==
name|b
index|[
literal|1
index|]
operator|&&
name|a
index|[
literal|0
index|]
operator|>=
name|b
index|[
literal|0
index|]
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dt_le_128
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64_t
modifier|*
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
index|[
literal|1
index|]
operator|<
name|b
index|[
literal|1
index|]
operator|||
operator|(
name|a
index|[
literal|1
index|]
operator|==
name|b
index|[
literal|1
index|]
operator|&&
name|a
index|[
literal|0
index|]
operator|<=
name|b
index|[
literal|0
index|]
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Shift the 128-bit value in a by b. If b is positive, shift left.  * If b is negative, shift right.  */
end_comment

begin_function
specifier|static
name|void
name|dt_shift_128
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|uint64_t
name|mask
decl_stmt|;
if|if
condition|(
name|b
operator|==
literal|0
condition|)
return|return;
if|if
condition|(
name|b
operator|<
literal|0
condition|)
block|{
name|b
operator|=
operator|-
name|b
expr_stmt|;
if|if
condition|(
name|b
operator|>=
literal|64
condition|)
block|{
name|a
index|[
literal|0
index|]
operator|=
name|a
index|[
literal|1
index|]
operator|>>
operator|(
name|b
operator|-
literal|64
operator|)
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|a
index|[
literal|0
index|]
operator|>>=
name|b
expr_stmt|;
name|mask
operator|=
literal|1LL
operator|<<
operator|(
literal|64
operator|-
name|b
operator|)
expr_stmt|;
name|mask
operator|-=
literal|1
expr_stmt|;
name|a
index|[
literal|0
index|]
operator||=
operator|(
operator|(
name|a
index|[
literal|1
index|]
operator|&
name|mask
operator|)
operator|<<
operator|(
literal|64
operator|-
name|b
operator|)
operator|)
expr_stmt|;
name|a
index|[
literal|1
index|]
operator|>>=
name|b
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|b
operator|>=
literal|64
condition|)
block|{
name|a
index|[
literal|1
index|]
operator|=
name|a
index|[
literal|0
index|]
operator|<<
operator|(
name|b
operator|-
literal|64
operator|)
expr_stmt|;
name|a
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|a
index|[
literal|1
index|]
operator|<<=
name|b
expr_stmt|;
name|mask
operator|=
name|a
index|[
literal|0
index|]
operator|>>
operator|(
literal|64
operator|-
name|b
operator|)
expr_stmt|;
name|a
index|[
literal|1
index|]
operator||=
name|mask
expr_stmt|;
name|a
index|[
literal|0
index|]
operator|<<=
name|b
expr_stmt|;
block|}
block|}
block|}
end_function

begin_function
specifier|static
name|int
name|dt_nbits_128
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
name|int
name|nbits
init|=
literal|0
decl_stmt|;
name|uint64_t
name|tmp
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|zero
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|tmp
index|[
literal|0
index|]
operator|=
name|a
index|[
literal|0
index|]
expr_stmt|;
name|tmp
index|[
literal|1
index|]
operator|=
name|a
index|[
literal|1
index|]
expr_stmt|;
name|dt_shift_128
argument_list|(
name|tmp
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
while|while
condition|(
name|dt_gt_128
argument_list|(
name|tmp
argument_list|,
name|zero
argument_list|)
condition|)
block|{
name|dt_shift_128
argument_list|(
name|tmp
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|nbits
operator|++
expr_stmt|;
block|}
return|return
operator|(
name|nbits
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|dt_subtract_128
parameter_list|(
name|uint64_t
modifier|*
name|minuend
parameter_list|,
name|uint64_t
modifier|*
name|subtrahend
parameter_list|,
name|uint64_t
modifier|*
name|difference
parameter_list|)
block|{
name|uint64_t
name|result
index|[
literal|2
index|]
decl_stmt|;
name|result
index|[
literal|0
index|]
operator|=
name|minuend
index|[
literal|0
index|]
operator|-
name|subtrahend
index|[
literal|0
index|]
expr_stmt|;
name|result
index|[
literal|1
index|]
operator|=
name|minuend
index|[
literal|1
index|]
operator|-
name|subtrahend
index|[
literal|1
index|]
operator|-
operator|(
name|minuend
index|[
literal|0
index|]
operator|<
name|subtrahend
index|[
literal|0
index|]
condition|?
literal|1
else|:
literal|0
operator|)
expr_stmt|;
name|difference
index|[
literal|0
index|]
operator|=
name|result
index|[
literal|0
index|]
expr_stmt|;
name|difference
index|[
literal|1
index|]
operator|=
name|result
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|dt_add_128
parameter_list|(
name|uint64_t
modifier|*
name|addend1
parameter_list|,
name|uint64_t
modifier|*
name|addend2
parameter_list|,
name|uint64_t
modifier|*
name|sum
parameter_list|)
block|{
name|uint64_t
name|result
index|[
literal|2
index|]
decl_stmt|;
name|result
index|[
literal|0
index|]
operator|=
name|addend1
index|[
literal|0
index|]
operator|+
name|addend2
index|[
literal|0
index|]
expr_stmt|;
name|result
index|[
literal|1
index|]
operator|=
name|addend1
index|[
literal|1
index|]
operator|+
name|addend2
index|[
literal|1
index|]
operator|+
operator|(
name|result
index|[
literal|0
index|]
operator|<
name|addend1
index|[
literal|0
index|]
operator|||
name|result
index|[
literal|0
index|]
operator|<
name|addend2
index|[
literal|0
index|]
condition|?
literal|1
else|:
literal|0
operator|)
expr_stmt|;
name|sum
index|[
literal|0
index|]
operator|=
name|result
index|[
literal|0
index|]
expr_stmt|;
name|sum
index|[
literal|1
index|]
operator|=
name|result
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * The basic idea is to break the 2 64-bit values into 4 32-bit values,  * use native multiplication on those, and then re-combine into the  * resulting 128-bit value.  *  * (hi1<< 32 + lo1) * (hi2<< 32 + lo2) =  *     hi1 * hi2<< 64 +  *     hi1 * lo2<< 32 +  *     hi2 * lo1<< 32 +  *     lo1 * lo2  */
end_comment

begin_function
specifier|static
name|void
name|dt_multiply_128
parameter_list|(
name|uint64_t
name|factor1
parameter_list|,
name|uint64_t
name|factor2
parameter_list|,
name|uint64_t
modifier|*
name|product
parameter_list|)
block|{
name|uint64_t
name|hi1
decl_stmt|,
name|hi2
decl_stmt|,
name|lo1
decl_stmt|,
name|lo2
decl_stmt|;
name|uint64_t
name|tmp
index|[
literal|2
index|]
decl_stmt|;
name|hi1
operator|=
name|factor1
operator|>>
literal|32
expr_stmt|;
name|hi2
operator|=
name|factor2
operator|>>
literal|32
expr_stmt|;
name|lo1
operator|=
name|factor1
operator|&
name|DT_MASK_LO
expr_stmt|;
name|lo2
operator|=
name|factor2
operator|&
name|DT_MASK_LO
expr_stmt|;
name|product
index|[
literal|0
index|]
operator|=
name|lo1
operator|*
name|lo2
expr_stmt|;
name|product
index|[
literal|1
index|]
operator|=
name|hi1
operator|*
name|hi2
expr_stmt|;
name|tmp
index|[
literal|0
index|]
operator|=
name|hi1
operator|*
name|lo2
expr_stmt|;
name|tmp
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|dt_shift_128
argument_list|(
name|tmp
argument_list|,
literal|32
argument_list|)
expr_stmt|;
name|dt_add_128
argument_list|(
name|product
argument_list|,
name|tmp
argument_list|,
name|product
argument_list|)
expr_stmt|;
name|tmp
index|[
literal|0
index|]
operator|=
name|hi2
operator|*
name|lo1
expr_stmt|;
name|tmp
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|dt_shift_128
argument_list|(
name|tmp
argument_list|,
literal|32
argument_list|)
expr_stmt|;
name|dt_add_128
argument_list|(
name|product
argument_list|,
name|tmp
argument_list|,
name|product
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This is long-hand division.  *  * We initialize subtrahend by shifting divisor left as far as possible. We  * loop, comparing subtrahend to dividend:  if subtrahend is smaller, we  * subtract and set the appropriate bit in the result.  We then shift  * subtrahend right by one bit for the next comparison.  */
end_comment

begin_function
specifier|static
name|void
name|dt_divide_128
parameter_list|(
name|uint64_t
modifier|*
name|dividend
parameter_list|,
name|uint64_t
name|divisor
parameter_list|,
name|uint64_t
modifier|*
name|quotient
parameter_list|)
block|{
name|uint64_t
name|result
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|uint64_t
name|remainder
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|subtrahend
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|divisor_128
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|mask
index|[
literal|2
index|]
init|=
block|{
literal|1
block|,
literal|0
block|}
decl_stmt|;
name|int
name|log
init|=
literal|0
decl_stmt|;
name|assert
argument_list|(
name|divisor
operator|!=
literal|0
argument_list|)
expr_stmt|;
name|divisor_128
index|[
literal|0
index|]
operator|=
name|divisor
expr_stmt|;
name|divisor_128
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|remainder
index|[
literal|0
index|]
operator|=
name|dividend
index|[
literal|0
index|]
expr_stmt|;
name|remainder
index|[
literal|1
index|]
operator|=
name|dividend
index|[
literal|1
index|]
expr_stmt|;
name|subtrahend
index|[
literal|0
index|]
operator|=
name|divisor
expr_stmt|;
name|subtrahend
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|divisor
operator|>
literal|0
condition|)
block|{
name|log
operator|++
expr_stmt|;
name|divisor
operator|>>=
literal|1
expr_stmt|;
block|}
name|dt_shift_128
argument_list|(
name|subtrahend
argument_list|,
literal|128
operator|-
name|log
argument_list|)
expr_stmt|;
name|dt_shift_128
argument_list|(
name|mask
argument_list|,
literal|128
operator|-
name|log
argument_list|)
expr_stmt|;
while|while
condition|(
name|dt_ge_128
argument_list|(
name|remainder
argument_list|,
name|divisor_128
argument_list|)
condition|)
block|{
if|if
condition|(
name|dt_ge_128
argument_list|(
name|remainder
argument_list|,
name|subtrahend
argument_list|)
condition|)
block|{
name|dt_subtract_128
argument_list|(
name|remainder
argument_list|,
name|subtrahend
argument_list|,
name|remainder
argument_list|)
expr_stmt|;
name|result
index|[
literal|0
index|]
operator||=
name|mask
index|[
literal|0
index|]
expr_stmt|;
name|result
index|[
literal|1
index|]
operator||=
name|mask
index|[
literal|1
index|]
expr_stmt|;
block|}
name|dt_shift_128
argument_list|(
name|subtrahend
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
name|dt_shift_128
argument_list|(
name|mask
argument_list|,
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|quotient
index|[
literal|0
index|]
operator|=
name|result
index|[
literal|0
index|]
expr_stmt|;
name|quotient
index|[
literal|1
index|]
operator|=
name|result
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  * This is the long-hand method of calculating a square root.  * The algorithm is as follows:  *  * 1. Group the digits by 2 from the right.  * 2. Over the leftmost group, find the largest single-digit number  *    whose square is less than that group.  * 3. Subtract the result of the previous step (2 or 4, depending) and  *    bring down the next two-digit group.  * 4. For the result R we have so far, find the largest single-digit number  *    x such that 2 * R * 10 * x + x^2 is less than the result from step 3.  *    (Note that this is doubling R and performing a decimal left-shift by 1  *    and searching for the appropriate decimal to fill the one's place.)  *    The value x is the next digit in the square root.  * Repeat steps 3 and 4 until the desired precision is reached.  (We're  * dealing with integers, so the above is sufficient.)  *  * In decimal, the square root of 582,734 would be calculated as so:  *  *     __7__6__3  *    | 58 27 34  *     -49       (7^2 == 49 => 7 is the first digit in the square root)  *      --  *       9 27    (Subtract and bring down the next group.)  * 146   8 76    (2 * 7 * 10 * 6 + 6^2 == 876 => 6 is the next digit in  *      -----     the square root)  *         51 34 (Subtract and bring down the next group.)  * 1523    45 69 (2 * 76 * 10 * 3 + 3^2 == 4569 => 3 is the next digit in  *         -----  the square root)  *          5 65 (remainder)  *  * The above algorithm applies similarly in binary, but note that the  * only possible non-zero value for x in step 4 is 1, so step 4 becomes a  * simple decision: is 2 * R * 2 * 1 + 1^2 (aka R<< 2 + 1) less than the  * preceding difference?  *  * In binary, the square root of 11011011 would be calculated as so:  *  *     __1__1__1__0  *    | 11 01 10 11  *      01          (0<< 2 + 1 == 1< 11 => this bit is 1)  *      --  *      10 01 10 11  * 101   1 01       (1<< 2 + 1 == 101< 1001 => next bit is 1)  *      -----  *       1 00 10 11  * 1101    11 01    (11<< 2 + 1 == 1101< 10010 => next bit is 1)  *       -------  *          1 01 11  * 11101    1 11 01 (111<< 2 + 1 == 11101> 10111 => last bit is 0)  *  */
end_comment

begin_function
specifier|static
name|uint64_t
name|dt_sqrt_128
parameter_list|(
name|uint64_t
modifier|*
name|square
parameter_list|)
block|{
name|uint64_t
name|result
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|uint64_t
name|diff
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
name|uint64_t
name|one
index|[
literal|2
index|]
init|=
block|{
literal|1
block|,
literal|0
block|}
decl_stmt|;
name|uint64_t
name|next_pair
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|next_try
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|bit_pairs
decl_stmt|,
name|pair_shift
decl_stmt|;
name|int
name|i
decl_stmt|;
name|bit_pairs
operator|=
name|dt_nbits_128
argument_list|(
name|square
argument_list|)
operator|/
literal|2
expr_stmt|;
name|pair_shift
operator|=
name|bit_pairs
operator|*
literal|2
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|bit_pairs
condition|;
name|i
operator|++
control|)
block|{
comment|/* 		 * Bring down the next pair of bits. 		 */
name|next_pair
index|[
literal|0
index|]
operator|=
name|square
index|[
literal|0
index|]
expr_stmt|;
name|next_pair
index|[
literal|1
index|]
operator|=
name|square
index|[
literal|1
index|]
expr_stmt|;
name|dt_shift_128
argument_list|(
name|next_pair
argument_list|,
operator|-
name|pair_shift
argument_list|)
expr_stmt|;
name|next_pair
index|[
literal|0
index|]
operator|&=
literal|0x3
expr_stmt|;
name|next_pair
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
name|dt_shift_128
argument_list|(
name|diff
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|dt_add_128
argument_list|(
name|diff
argument_list|,
name|next_pair
argument_list|,
name|diff
argument_list|)
expr_stmt|;
comment|/* 		 * next_try = R<< 2 + 1 		 */
name|next_try
index|[
literal|0
index|]
operator|=
name|result
index|[
literal|0
index|]
expr_stmt|;
name|next_try
index|[
literal|1
index|]
operator|=
name|result
index|[
literal|1
index|]
expr_stmt|;
name|dt_shift_128
argument_list|(
name|next_try
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|dt_add_128
argument_list|(
name|next_try
argument_list|,
name|one
argument_list|,
name|next_try
argument_list|)
expr_stmt|;
if|if
condition|(
name|dt_le_128
argument_list|(
name|next_try
argument_list|,
name|diff
argument_list|)
condition|)
block|{
name|dt_subtract_128
argument_list|(
name|diff
argument_list|,
name|next_try
argument_list|,
name|diff
argument_list|)
expr_stmt|;
name|dt_shift_128
argument_list|(
name|result
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|dt_add_128
argument_list|(
name|result
argument_list|,
name|one
argument_list|,
name|result
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|dt_shift_128
argument_list|(
name|result
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|pair_shift
operator|-=
literal|2
expr_stmt|;
block|}
name|assert
argument_list|(
name|result
index|[
literal|1
index|]
operator|==
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|result
index|[
literal|0
index|]
operator|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|dt_stddev
parameter_list|(
name|uint64_t
modifier|*
name|data
parameter_list|,
name|uint64_t
name|normal
parameter_list|)
block|{
name|uint64_t
name|avg_of_squares
index|[
literal|2
index|]
decl_stmt|;
name|uint64_t
name|square_of_avg
index|[
literal|2
index|]
decl_stmt|;
name|int64_t
name|norm_avg
decl_stmt|;
name|uint64_t
name|diff
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * The standard approximation for standard deviation is 	 * sqrt(average(x**2) - average(x)**2), i.e. the square root 	 * of the average of the squares minus the square of the average. 	 */
name|dt_divide_128
argument_list|(
name|data
operator|+
literal|2
argument_list|,
name|normal
argument_list|,
name|avg_of_squares
argument_list|)
expr_stmt|;
name|dt_divide_128
argument_list|(
name|avg_of_squares
argument_list|,
name|data
index|[
literal|0
index|]
argument_list|,
name|avg_of_squares
argument_list|)
expr_stmt|;
name|norm_avg
operator|=
operator|(
name|int64_t
operator|)
name|data
index|[
literal|1
index|]
operator|/
operator|(
name|int64_t
operator|)
name|normal
operator|/
operator|(
name|int64_t
operator|)
name|data
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
name|norm_avg
operator|<
literal|0
condition|)
name|norm_avg
operator|=
operator|-
name|norm_avg
expr_stmt|;
name|dt_multiply_128
argument_list|(
operator|(
name|uint64_t
operator|)
name|norm_avg
argument_list|,
operator|(
name|uint64_t
operator|)
name|norm_avg
argument_list|,
name|square_of_avg
argument_list|)
expr_stmt|;
name|dt_subtract_128
argument_list|(
name|avg_of_squares
argument_list|,
name|square_of_avg
argument_list|,
name|diff
argument_list|)
expr_stmt|;
return|return
operator|(
name|dt_sqrt_128
argument_list|(
name|diff
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dt_flowindent
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|dtrace_probedata_t
modifier|*
name|data
parameter_list|,
name|dtrace_epid_t
name|last
parameter_list|,
name|dtrace_bufdesc_t
modifier|*
name|buf
parameter_list|,
name|size_t
name|offs
parameter_list|)
block|{
name|dtrace_probedesc_t
modifier|*
name|pd
init|=
name|data
operator|->
name|dtpda_pdesc
decl_stmt|,
modifier|*
name|npd
decl_stmt|;
name|dtrace_eprobedesc_t
modifier|*
name|epd
init|=
name|data
operator|->
name|dtpda_edesc
decl_stmt|,
modifier|*
name|nepd
decl_stmt|;
name|char
modifier|*
name|p
init|=
name|pd
operator|->
name|dtpd_provider
decl_stmt|,
modifier|*
name|n
init|=
name|pd
operator|->
name|dtpd_name
decl_stmt|,
modifier|*
name|sub
decl_stmt|;
name|dtrace_flowkind_t
name|flow
init|=
name|DTRACEFLOW_NONE
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
init|=
name|NULL
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|e_str
index|[
literal|2
index|]
init|=
block|{
literal|" -> "
block|,
literal|" => "
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|r_str
index|[
literal|2
index|]
init|=
block|{
literal|"<- "
block|,
literal|"<= "
block|}
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|ent
init|=
literal|"entry"
decl_stmt|,
modifier|*
name|ret
init|=
literal|"return"
decl_stmt|;
specifier|static
name|int
name|entlen
init|=
literal|0
decl_stmt|,
name|retlen
init|=
literal|0
decl_stmt|;
name|dtrace_epid_t
name|next
decl_stmt|,
name|id
init|=
name|epd
operator|->
name|dtepd_epid
decl_stmt|;
name|int
name|rval
decl_stmt|;
if|if
condition|(
name|entlen
operator|==
literal|0
condition|)
block|{
name|assert
argument_list|(
name|retlen
operator|==
literal|0
argument_list|)
expr_stmt|;
name|entlen
operator|=
name|strlen
argument_list|(
name|ent
argument_list|)
expr_stmt|;
name|retlen
operator|=
name|strlen
argument_list|(
name|ret
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * If the name of the probe is "entry" or ends with "-entry", we 	 * treat it as an entry; if it is "return" or ends with "-return", 	 * we treat it as a return.  (This allows application-provided probes 	 * like "method-entry" or "function-entry" to participate in flow 	 * indentation -- without accidentally misinterpreting popular probe 	 * names like "carpentry", "gentry" or "Coventry".) 	 */
if|if
condition|(
operator|(
name|sub
operator|=
name|strstr
argument_list|(
name|n
argument_list|,
name|ent
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
name|sub
index|[
name|entlen
index|]
operator|==
literal|'\0'
operator|&&
operator|(
name|sub
operator|==
name|n
operator|||
name|sub
index|[
operator|-
literal|1
index|]
operator|==
literal|'-'
operator|)
condition|)
block|{
name|flow
operator|=
name|DTRACEFLOW_ENTRY
expr_stmt|;
name|str
operator|=
name|e_str
index|[
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"syscall"
argument_list|)
operator|==
literal|0
index|]
expr_stmt|;
block|}
elseif|else
if|if
condition|(
operator|(
name|sub
operator|=
name|strstr
argument_list|(
name|n
argument_list|,
name|ret
argument_list|)
operator|)
operator|!=
name|NULL
operator|&&
name|sub
index|[
name|retlen
index|]
operator|==
literal|'\0'
operator|&&
operator|(
name|sub
operator|==
name|n
operator|||
name|sub
index|[
operator|-
literal|1
index|]
operator|==
literal|'-'
operator|)
condition|)
block|{
name|flow
operator|=
name|DTRACEFLOW_RETURN
expr_stmt|;
name|str
operator|=
name|r_str
index|[
name|strcmp
argument_list|(
name|p
argument_list|,
literal|"syscall"
argument_list|)
operator|==
literal|0
index|]
expr_stmt|;
block|}
comment|/* 	 * If we're going to indent this, we need to check the ID of our last 	 * call.  If we're looking at the same probe ID but a different EPID, 	 * we _don't_ want to indent.  (Yes, there are some minor holes in 	 * this scheme -- it's a heuristic.) 	 */
if|if
condition|(
name|flow
operator|==
name|DTRACEFLOW_ENTRY
condition|)
block|{
if|if
condition|(
operator|(
name|last
operator|!=
name|DTRACE_EPIDNONE
operator|&&
name|id
operator|!=
name|last
operator|&&
name|pd
operator|->
name|dtpd_id
operator|==
name|dtp
operator|->
name|dt_pdesc
index|[
name|last
index|]
operator|->
name|dtpd_id
operator|)
condition|)
name|flow
operator|=
name|DTRACEFLOW_NONE
expr_stmt|;
block|}
comment|/* 	 * If we're going to unindent this, it's more difficult to see if 	 * we don't actually want to unindent it -- we need to look at the 	 * _next_ EPID. 	 */
if|if
condition|(
name|flow
operator|==
name|DTRACEFLOW_RETURN
condition|)
block|{
name|offs
operator|+=
name|epd
operator|->
name|dtepd_size
expr_stmt|;
do|do
block|{
if|if
condition|(
name|offs
operator|>=
name|buf
operator|->
name|dtbd_size
condition|)
block|{
comment|/* 				 * We're at the end -- maybe.  If the oldest 				 * record is non-zero, we need to wrap. 				 */
if|if
condition|(
name|buf
operator|->
name|dtbd_oldest
operator|!=
literal|0
condition|)
block|{
name|offs
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
goto|goto
name|out
goto|;
block|}
block|}
name|next
operator|=
operator|*
operator|(
name|uint32_t
operator|*
operator|)
operator|(
operator|(
name|uintptr_t
operator|)
name|buf
operator|->
name|dtbd_data
operator|+
name|offs
operator|)
expr_stmt|;
if|if
condition|(
name|next
operator|==
name|DTRACE_EPIDNONE
condition|)
name|offs
operator|+=
sizeof|sizeof
argument_list|(
name|id
argument_list|)
expr_stmt|;
block|}
do|while
condition|(
name|next
operator|==
name|DTRACE_EPIDNONE
condition|)
do|;
if|if
condition|(
operator|(
name|rval
operator|=
name|dt_epid_lookup
argument_list|(
name|dtp
argument_list|,
name|next
argument_list|,
operator|&
name|nepd
argument_list|,
operator|&
name|npd
argument_list|)
operator|)
operator|!=
literal|0
condition|)
return|return
operator|(
name|rval
operator|)
return|;
if|if
condition|(
name|next
operator|!=
name|id
operator|&&
name|npd
operator|->
name|dtpd_id
operator|==
name|pd
operator|->
name|dtpd_id
condition|)
name|flow
operator|=
name|DTRACEFLOW_NONE
expr_stmt|;
block|}
name|out
label|:
if|if
condition|(
name|flow
operator|==
name|DTRACEFLOW_ENTRY
operator|||
name|flow
operator|==
name|DTRACEFLOW_RETURN
condition|)
block|{
name|data
operator|->
name|dtpda_prefix
operator|=
name|str
expr_stmt|;
block|}
else|else
block|{
name|data
operator|->
name|dtpda_prefix
operator|=
literal|"| "
expr_stmt|;
block|}
if|if
condition|(
name|flow
operator|==
name|DTRACEFLOW_RETURN
operator|&&
name|data
operator|->
name|dtpda_indent
operator|>
literal|0
condition|)
name|data
operator|->
name|dtpda_indent
operator|-=
literal|2
expr_stmt|;
name|data
operator|->
name|dtpda_flow
operator|=
name|flow
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dt_nullprobe
parameter_list|()
block|{
return|return
operator|(
name|DTRACE_CONSUME_THIS
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dt_nullrec
parameter_list|()
block|{
return|return
operator|(
name|DTRACE_CONSUME_NEXT
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dt_print_quantline
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|int64_t
name|val
parameter_list|,
name|uint64_t
name|normal
parameter_list|,
name|long
name|double
name|total
parameter_list|,
name|char
name|positives
parameter_list|,
name|char
name|negatives
parameter_list|)
block|{
name|long
name|double
name|f
decl_stmt|;
name|uint_t
name|depth
decl_stmt|,
name|len
init|=
literal|40
decl_stmt|;
specifier|const
name|char
modifier|*
name|ats
init|=
literal|"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"
decl_stmt|;
specifier|const
name|char
modifier|*
name|spaces
init|=
literal|"                                        "
decl_stmt|;
name|assert
argument_list|(
name|strlen
argument_list|(
name|ats
argument_list|)
operator|==
name|len
operator|&&
name|strlen
argument_list|(
name|spaces
argument_list|)
operator|==
name|len
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|total
operator|==
literal|0
operator|&&
operator|(
name|positives
operator|||
name|negatives
operator|)
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|val
operator|<
literal|0
operator|&&
operator|!
name|negatives
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|val
operator|>
literal|0
operator|&&
operator|!
name|positives
operator|)
argument_list|)
expr_stmt|;
name|assert
argument_list|(
operator|!
operator|(
name|val
operator|!=
literal|0
operator|&&
name|total
operator|==
literal|0
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|negatives
condition|)
block|{
if|if
condition|(
name|positives
condition|)
block|{
name|f
operator|=
operator|(
name|dt_fabsl
argument_list|(
operator|(
name|long
name|double
operator|)
name|val
argument_list|)
operator|*
name|len
operator|)
operator|/
name|total
expr_stmt|;
name|depth
operator|=
call|(
name|uint_t
call|)
argument_list|(
name|f
operator|+
literal|0.5
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|depth
operator|=
literal|0
expr_stmt|;
block|}
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"|%s%s %-9lld\n"
argument_list|,
name|ats
operator|+
name|len
operator|-
name|depth
argument_list|,
name|spaces
operator|+
name|depth
argument_list|,
operator|(
name|long
name|long
operator|)
name|val
operator|/
name|normal
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
operator|!
name|positives
condition|)
block|{
name|f
operator|=
operator|(
name|dt_fabsl
argument_list|(
operator|(
name|long
name|double
operator|)
name|val
argument_list|)
operator|*
name|len
operator|)
operator|/
name|total
expr_stmt|;
name|depth
operator|=
call|(
name|uint_t
call|)
argument_list|(
name|f
operator|+
literal|0.5
argument_list|)
expr_stmt|;
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%s%s| %-9lld\n"
argument_list|,
name|spaces
operator|+
name|depth
argument_list|,
name|ats
operator|+
name|len
operator|-
name|depth
argument_list|,
operator|(
name|long
name|long
operator|)
name|val
operator|/
name|normal
argument_list|)
operator|)
return|;
block|}
comment|/* 	 * If we're here, we have both positive and negative bucket values. 	 * To express this graphically, we're going to generate both positive 	 * and negative bars separated by a centerline.  These bars are half 	 * the size of normal quantize()/lquantize() bars, so we divide the 	 * length in half before calculating the bar length. 	 */
name|len
operator|/=
literal|2
expr_stmt|;
name|ats
operator|=
operator|&
name|ats
index|[
name|len
index|]
expr_stmt|;
name|spaces
operator|=
operator|&
name|spaces
index|[
name|len
index|]
expr_stmt|;
name|f
operator|=
operator|(
name|dt_fabsl
argument_list|(
operator|(
name|long
name|double
operator|)
name|val
argument_list|)
operator|*
name|len
operator|)
operator|/
name|total
expr_stmt|;
name|depth
operator|=
call|(
name|uint_t
call|)
argument_list|(
name|f
operator|+
literal|0.5
argument_list|)
expr_stmt|;
if|if
condition|(
name|val
operator|<=
literal|0
condition|)
block|{
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%s%s|%*s %-9lld\n"
argument_list|,
name|spaces
operator|+
name|depth
argument_list|,
name|ats
operator|+
name|len
operator|-
name|depth
argument_list|,
name|len
argument_list|,
literal|""
argument_list|,
operator|(
name|long
name|long
operator|)
name|val
operator|/
name|normal
argument_list|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%20s|%s%s %-9lld\n"
argument_list|,
literal|""
argument_list|,
name|ats
operator|+
name|len
operator|-
name|depth
argument_list|,
name|spaces
operator|+
name|depth
argument_list|,
operator|(
name|long
name|long
operator|)
name|val
operator|/
name|normal
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_function
name|int
name|dt_print_quantize
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint64_t
name|normal
parameter_list|)
block|{
specifier|const
name|int64_t
modifier|*
name|data
init|=
name|addr
decl_stmt|;
name|int
name|i
decl_stmt|,
name|first_bin
init|=
literal|0
decl_stmt|,
name|last_bin
init|=
name|DTRACE_QUANTIZE_NBUCKETS
operator|-
literal|1
decl_stmt|;
name|long
name|double
name|total
init|=
literal|0
decl_stmt|;
name|char
name|positives
init|=
literal|0
decl_stmt|,
name|negatives
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|size
operator|!=
name|DTRACE_QUANTIZE_NBUCKETS
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
condition|)
return|return
operator|(
name|dt_set_errno
argument_list|(
name|dtp
argument_list|,
name|EDT_DMISMATCH
argument_list|)
operator|)
return|;
while|while
condition|(
name|first_bin
operator|<
name|DTRACE_QUANTIZE_NBUCKETS
operator|-
literal|1
operator|&&
name|data
index|[
name|first_bin
index|]
operator|==
literal|0
condition|)
name|first_bin
operator|++
expr_stmt|;
if|if
condition|(
name|first_bin
operator|==
name|DTRACE_QUANTIZE_NBUCKETS
operator|-
literal|1
condition|)
block|{
comment|/* 		 * There isn't any data.  This is possible if (and only if) 		 * negative increment values have been used.  In this case, 		 * we'll print the buckets around 0. 		 */
name|first_bin
operator|=
name|DTRACE_QUANTIZE_ZEROBUCKET
operator|-
literal|1
expr_stmt|;
name|last_bin
operator|=
name|DTRACE_QUANTIZE_ZEROBUCKET
operator|+
literal|1
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|first_bin
operator|>
literal|0
condition|)
name|first_bin
operator|--
expr_stmt|;
while|while
condition|(
name|last_bin
operator|>
literal|0
operator|&&
name|data
index|[
name|last_bin
index|]
operator|==
literal|0
condition|)
name|last_bin
operator|--
expr_stmt|;
if|if
condition|(
name|last_bin
operator|<
name|DTRACE_QUANTIZE_NBUCKETS
operator|-
literal|1
condition|)
name|last_bin
operator|++
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
name|first_bin
init|;
name|i
operator|<=
name|last_bin
condition|;
name|i
operator|++
control|)
block|{
name|positives
operator||=
operator|(
name|data
index|[
name|i
index|]
operator|>
literal|0
operator|)
expr_stmt|;
name|negatives
operator||=
operator|(
name|data
index|[
name|i
index|]
operator|<
literal|0
operator|)
expr_stmt|;
name|total
operator|+=
name|dt_fabsl
argument_list|(
operator|(
name|long
name|double
operator|)
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n%16s %41s %-9s\n"
argument_list|,
literal|"value"
argument_list|,
literal|"------------- Distribution -------------"
argument_list|,
literal|"count"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
name|first_bin
init|;
name|i
operator|<=
name|last_bin
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%16lld "
argument_list|,
operator|(
name|long
name|long
operator|)
name|DTRACE_QUANTIZE_BUCKETVAL
argument_list|(
name|i
argument_list|)
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|dt_print_quantline
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
name|data
index|[
name|i
index|]
argument_list|,
name|normal
argument_list|,
name|total
argument_list|,
name|positives
argument_list|,
name|negatives
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dt_print_lquantize
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint64_t
name|normal
parameter_list|)
block|{
specifier|const
name|int64_t
modifier|*
name|data
init|=
name|addr
decl_stmt|;
name|int
name|i
decl_stmt|,
name|first_bin
decl_stmt|,
name|last_bin
decl_stmt|,
name|base
decl_stmt|;
name|uint64_t
name|arg
decl_stmt|;
name|long
name|double
name|total
init|=
literal|0
decl_stmt|;
name|uint16_t
name|step
decl_stmt|,
name|levels
decl_stmt|;
name|char
name|positives
init|=
literal|0
decl_stmt|,
name|negatives
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|size
operator|<
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
condition|)
return|return
operator|(
name|dt_set_errno
argument_list|(
name|dtp
argument_list|,
name|EDT_DMISMATCH
argument_list|)
operator|)
return|;
name|arg
operator|=
operator|*
name|data
operator|++
expr_stmt|;
name|size
operator|-=
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
expr_stmt|;
name|base
operator|=
name|DTRACE_LQUANTIZE_BASE
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|step
operator|=
name|DTRACE_LQUANTIZE_STEP
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|levels
operator|=
name|DTRACE_LQUANTIZE_LEVELS
argument_list|(
name|arg
argument_list|)
expr_stmt|;
name|first_bin
operator|=
literal|0
expr_stmt|;
name|last_bin
operator|=
name|levels
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|size
operator|!=
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
operator|*
operator|(
name|levels
operator|+
literal|2
operator|)
condition|)
return|return
operator|(
name|dt_set_errno
argument_list|(
name|dtp
argument_list|,
name|EDT_DMISMATCH
argument_list|)
operator|)
return|;
while|while
condition|(
name|first_bin
operator|<=
name|levels
operator|+
literal|1
operator|&&
name|data
index|[
name|first_bin
index|]
operator|==
literal|0
condition|)
name|first_bin
operator|++
expr_stmt|;
if|if
condition|(
name|first_bin
operator|>
name|levels
operator|+
literal|1
condition|)
block|{
name|first_bin
operator|=
literal|0
expr_stmt|;
name|last_bin
operator|=
literal|2
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|first_bin
operator|>
literal|0
condition|)
name|first_bin
operator|--
expr_stmt|;
while|while
condition|(
name|last_bin
operator|>
literal|0
operator|&&
name|data
index|[
name|last_bin
index|]
operator|==
literal|0
condition|)
name|last_bin
operator|--
expr_stmt|;
if|if
condition|(
name|last_bin
operator|<
name|levels
operator|+
literal|1
condition|)
name|last_bin
operator|++
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
name|first_bin
init|;
name|i
operator|<=
name|last_bin
condition|;
name|i
operator|++
control|)
block|{
name|positives
operator||=
operator|(
name|data
index|[
name|i
index|]
operator|>
literal|0
operator|)
expr_stmt|;
name|negatives
operator||=
operator|(
name|data
index|[
name|i
index|]
operator|<
literal|0
operator|)
expr_stmt|;
name|total
operator|+=
name|dt_fabsl
argument_list|(
operator|(
name|long
name|double
operator|)
name|data
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n%16s %41s %-9s\n"
argument_list|,
literal|"value"
argument_list|,
literal|"------------- Distribution -------------"
argument_list|,
literal|"count"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
name|first_bin
init|;
name|i
operator|<=
name|last_bin
condition|;
name|i
operator|++
control|)
block|{
name|char
name|c
index|[
literal|32
index|]
decl_stmt|;
name|int
name|err
decl_stmt|;
if|if
condition|(
name|i
operator|==
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"< %d"
argument_list|,
name|base
operator|/
operator|(
name|uint32_t
operator|)
name|normal
argument_list|)
expr_stmt|;
name|err
operator|=
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%16s "
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|i
operator|==
name|levels
operator|+
literal|1
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|">= %d"
argument_list|,
name|base
operator|+
operator|(
name|levels
operator|*
name|step
operator|)
argument_list|)
expr_stmt|;
name|err
operator|=
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%16s "
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|err
operator|=
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%16d "
argument_list|,
name|base
operator|+
operator|(
name|i
operator|-
literal|1
operator|)
operator|*
name|step
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|err
operator|<
literal|0
operator|||
name|dt_print_quantline
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
name|data
index|[
name|i
index|]
argument_list|,
name|normal
argument_list|,
name|total
argument_list|,
name|positives
argument_list|,
name|negatives
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|dt_print_average
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint64_t
name|normal
parameter_list|)
block|{
comment|/* LINTED - alignment */
name|int64_t
modifier|*
name|data
init|=
operator|(
name|int64_t
operator|*
operator|)
name|addr
decl_stmt|;
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|" %16lld"
argument_list|,
name|data
index|[
literal|0
index|]
condition|?
call|(
name|long
name|long
call|)
argument_list|(
name|data
index|[
literal|1
index|]
operator|/
operator|(
name|int64_t
operator|)
name|normal
operator|/
name|data
index|[
literal|0
index|]
argument_list|)
else|:
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
specifier|static
name|int
name|dt_print_stddev
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|,
name|uint64_t
name|normal
parameter_list|)
block|{
comment|/* LINTED - alignment */
name|uint64_t
modifier|*
name|data
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|addr
decl_stmt|;
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|" %16llu"
argument_list|,
name|data
index|[
literal|0
index|]
condition|?
operator|(
name|unsigned
name|long
name|long
operator|)
name|dt_stddev
argument_list|(
name|data
argument_list|,
name|normal
argument_list|)
else|:
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|dt_print_bytes
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|size_t
name|nbytes
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|quiet
parameter_list|,
name|int
name|raw
parameter_list|)
block|{
comment|/* 	 * If the byte stream is a series of printable characters, followed by 	 * a terminating byte, we print it out as a string.  Otherwise, we 	 * assume that it's something else and just print the bytes. 	 */
name|int
name|i
decl_stmt|,
name|j
decl_stmt|,
name|margin
init|=
literal|5
decl_stmt|;
name|char
modifier|*
name|c
init|=
operator|(
name|char
operator|*
operator|)
name|addr
decl_stmt|;
if|if
condition|(
name|nbytes
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
name|raw
operator|||
name|dtp
operator|->
name|dt_options
index|[
name|DTRACEOPT_RAWBYTES
index|]
operator|!=
name|DTRACEOPT_UNSET
condition|)
goto|goto
name|raw
goto|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nbytes
condition|;
name|i
operator|++
control|)
block|{
comment|/* 		 * We define a "printable character" to be one for which 		 * isprint(3C) returns non-zero, isspace(3C) returns non-zero, 		 * or a character which is either backspace or the bell. 		 * Backspace and the bell are regrettably special because 		 * they fail the first two tests -- and yet they are entirely 		 * printable.  These are the only two control characters that 		 * have meaning for the terminal and for which isprint(3C) and 		 * isspace(3C) return 0. 		 */
if|if
condition|(
name|isprint
argument_list|(
name|c
index|[
name|i
index|]
argument_list|)
operator|||
name|isspace
argument_list|(
name|c
index|[
name|i
index|]
argument_list|)
operator|||
name|c
index|[
name|i
index|]
operator|==
literal|'\b'
operator|||
name|c
index|[
name|i
index|]
operator|==
literal|'\a'
condition|)
continue|continue;
if|if
condition|(
name|c
index|[
name|i
index|]
operator|==
literal|'\0'
operator|&&
name|i
operator|>
literal|0
condition|)
block|{
comment|/* 			 * This looks like it might be a string.  Before we 			 * assume that it is indeed a string, check the 			 * remainder of the byte range; if it contains 			 * additional non-nul characters, we'll assume that 			 * it's a binary stream that just happens to look like 			 * a string, and we'll print out the individual bytes. 			 */
for|for
control|(
name|j
operator|=
name|i
operator|+
literal|1
init|;
name|j
operator|<
name|nbytes
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|c
index|[
name|j
index|]
operator|!=
literal|'\0'
condition|)
break|break;
block|}
if|if
condition|(
name|j
operator|!=
name|nbytes
condition|)
break|break;
if|if
condition|(
name|quiet
condition|)
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%s"
argument_list|,
name|c
argument_list|)
operator|)
return|;
else|else
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"  %-*s"
argument_list|,
name|width
argument_list|,
name|c
argument_list|)
operator|)
return|;
block|}
break|break;
block|}
if|if
condition|(
name|i
operator|==
name|nbytes
condition|)
block|{
comment|/* 		 * The byte range is all printable characters, but there is 		 * no trailing nul byte.  We'll assume that it's a string and 		 * print it as such. 		 */
name|char
modifier|*
name|s
init|=
name|alloca
argument_list|(
name|nbytes
operator|+
literal|1
argument_list|)
decl_stmt|;
name|bcopy
argument_list|(
name|c
argument_list|,
name|s
argument_list|,
name|nbytes
argument_list|)
expr_stmt|;
name|s
index|[
name|nbytes
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
operator|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"  %-*s"
argument_list|,
name|width
argument_list|,
name|s
argument_list|)
operator|)
return|;
block|}
name|raw
label|:
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n%*s      "
argument_list|,
name|margin
argument_list|,
literal|""
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|16
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"  %c"
argument_list|,
literal|"0123456789abcdef"
index|[
name|i
index|]
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"  0123456789abcdef\n"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nbytes
condition|;
name|i
operator|+=
literal|16
control|)
block|{
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%*s%5x:"
argument_list|,
name|margin
argument_list|,
literal|""
argument_list|,
name|i
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|j
operator|=
name|i
init|;
name|j
operator|<
name|i
operator|+
literal|16
operator|&&
name|j
operator|<
name|nbytes
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|" %02x"
argument_list|,
operator|(
name|uchar_t
operator|)
name|c
index|[
name|j
index|]
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
while|while
condition|(
name|j
operator|++
operator|%
literal|16
condition|)
block|{
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"   "
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"  "
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
for|for
control|(
name|j
operator|=
name|i
init|;
name|j
operator|<
name|i
operator|+
literal|16
operator|&&
name|j
operator|<
name|nbytes
condition|;
name|j
operator|++
control|)
block|{
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%c"
argument_list|,
name|c
index|[
name|j
index|]
operator|<
literal|' '
operator|||
name|c
index|[
name|j
index|]
operator|>
literal|'~'
condition|?
literal|'.'
else|:
name|c
index|[
name|j
index|]
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dt_print_stack
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|depth
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|dtrace_syminfo_t
name|dts
decl_stmt|;
name|GElf_Sym
name|sym
decl_stmt|;
name|int
name|i
decl_stmt|,
name|indent
decl_stmt|;
name|char
name|c
index|[
name|PATH_MAX
operator|*
literal|2
index|]
decl_stmt|;
name|uint64_t
name|pc
decl_stmt|;
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|format
operator|==
name|NULL
condition|)
name|format
operator|=
literal|"%s"
expr_stmt|;
if|if
condition|(
name|dtp
operator|->
name|dt_options
index|[
name|DTRACEOPT_STACKINDENT
index|]
operator|!=
name|DTRACEOPT_UNSET
condition|)
name|indent
operator|=
operator|(
name|int
operator|)
name|dtp
operator|->
name|dt_options
index|[
name|DTRACEOPT_STACKINDENT
index|]
expr_stmt|;
else|else
name|indent
operator|=
name|_dtrace_stkindent
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|depth
condition|;
name|i
operator|++
control|)
block|{
switch|switch
condition|(
name|size
condition|)
block|{
case|case
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
case|:
comment|/* LINTED - alignment */
name|pc
operator|=
operator|*
operator|(
operator|(
name|uint32_t
operator|*
operator|)
name|addr
operator|)
expr_stmt|;
break|break;
case|case
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
case|:
comment|/* LINTED - alignment */
name|pc
operator|=
operator|*
operator|(
operator|(
name|uint64_t
operator|*
operator|)
name|addr
operator|)
expr_stmt|;
break|break;
default|default:
return|return
operator|(
name|dt_set_errno
argument_list|(
name|dtp
argument_list|,
name|EDT_BADSTACKPC
argument_list|)
operator|)
return|;
block|}
if|if
condition|(
name|pc
operator|==
literal|0
condition|)
break|break;
name|addr
operator|+=
name|size
expr_stmt|;
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%*s"
argument_list|,
name|indent
argument_list|,
literal|""
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|dtrace_lookup_by_addr
argument_list|(
name|dtp
argument_list|,
name|pc
argument_list|,
operator|&
name|sym
argument_list|,
operator|&
name|dts
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|pc
operator|>
name|sym
operator|.
name|st_value
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"%s`%s+0x%llx"
argument_list|,
name|dts
operator|.
name|dts_object
argument_list|,
name|dts
operator|.
name|dts_name
argument_list|,
name|pc
operator|-
name|sym
operator|.
name|st_value
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"%s`%s"
argument_list|,
name|dts
operator|.
name|dts_object
argument_list|,
name|dts
operator|.
name|dts_name
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
comment|/* 			 * We'll repeat the lookup, but this time we'll specify 			 * a NULL GElf_Sym -- indicating that we're only 			 * interested in the containing module. 			 */
if|if
condition|(
name|dtrace_lookup_by_addr
argument_list|(
name|dtp
argument_list|,
name|pc
argument_list|,
name|NULL
argument_list|,
operator|&
name|dts
argument_list|)
operator|==
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"%s`0x%llx"
argument_list|,
name|dts
operator|.
name|dts_object
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"0x%llx"
argument_list|,
name|pc
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
name|format
argument_list|,
name|c
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
name|int
name|dt_print_ustack
parameter_list|(
name|dtrace_hdl_t
modifier|*
name|dtp
parameter_list|,
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|uint64_t
name|arg
parameter_list|)
block|{
comment|/* LINTED - alignment */
name|uint64_t
modifier|*
name|pc
init|=
operator|(
name|uint64_t
operator|*
operator|)
name|addr
decl_stmt|;
name|uint32_t
name|depth
init|=
name|DTRACE_USTACK_NFRAMES
argument_list|(
name|arg
argument_list|)
decl_stmt|;
name|uint32_t
name|strsize
init|=
name|DTRACE_USTACK_STRSIZE
argument_list|(
name|arg
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|strbase
init|=
name|addr
operator|+
operator|(
name|depth
operator|+
literal|1
operator|)
operator|*
sizeof|sizeof
argument_list|(
name|uint64_t
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
init|=
name|strsize
condition|?
name|strbase
else|:
name|NULL
decl_stmt|;
name|int
name|err
init|=
literal|0
decl_stmt|;
name|char
name|name
index|[
name|PATH_MAX
index|]
decl_stmt|,
name|objname
index|[
name|PATH_MAX
index|]
decl_stmt|,
name|c
index|[
name|PATH_MAX
operator|*
literal|2
index|]
decl_stmt|;
name|struct
name|ps_prochandle
modifier|*
name|P
decl_stmt|;
name|GElf_Sym
name|sym
decl_stmt|;
name|int
name|i
decl_stmt|,
name|indent
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
if|if
condition|(
name|depth
operator|==
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|pid
operator|=
operator|(
name|pid_t
operator|)
operator|*
name|pc
operator|++
expr_stmt|;
if|if
condition|(
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"\n"
argument_list|)
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
if|if
condition|(
name|format
operator|==
name|NULL
condition|)
name|format
operator|=
literal|"%s"
expr_stmt|;
if|if
condition|(
name|dtp
operator|->
name|dt_options
index|[
name|DTRACEOPT_STACKINDENT
index|]
operator|!=
name|DTRACEOPT_UNSET
condition|)
name|indent
operator|=
operator|(
name|int
operator|)
name|dtp
operator|->
name|dt_options
index|[
name|DTRACEOPT_STACKINDENT
index|]
expr_stmt|;
else|else
name|indent
operator|=
name|_dtrace_stkindent
expr_stmt|;
comment|/* 	 * Ultimately, we need to add an entry point in the library vector for 	 * determining<symbol, offset> from<pid, address>.  For now, if 	 * this is a vector open, we just print the raw address or string. 	 */
if|if
condition|(
name|dtp
operator|->
name|dt_vector
operator|==
name|NULL
condition|)
name|P
operator|=
name|dt_proc_grab
argument_list|(
name|dtp
argument_list|,
name|pid
argument_list|,
name|PGRAB_RDONLY
operator||
name|PGRAB_FORCE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
name|P
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|P
operator|!=
name|NULL
condition|)
name|dt_proc_lock
argument_list|(
name|dtp
argument_list|,
name|P
argument_list|)
expr_stmt|;
comment|/* lock handle while we perform lookups */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|depth
operator|&&
name|pc
index|[
name|i
index|]
operator|!=
literal|0
condition|;
name|i
operator|++
control|)
block|{
specifier|const
name|prmap_t
modifier|*
name|map
decl_stmt|;
if|if
condition|(
operator|(
name|err
operator|=
name|dt_printf
argument_list|(
name|dtp
argument_list|,
name|fp
argument_list|,
literal|"%*s"
argument_list|,
name|indent
argument_list|,
literal|""
argument_list|)
operator|)
operator|<
literal|0
condition|)
break|break;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
if|if
condition|(
name|P
operator|!=
name|NULL
operator|&&
name|Plookup_by_addr
argument_list|(
argument|P
argument_list|,
argument|pc[i]
argument_list|,
else|#
directive|else
argument|if (P != NULL&& proc_addr2sym(P, pc[i],
endif|#
directive|endif
argument|name, sizeof (name),&sym) ==
literal|0
argument|) {
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|(void) Pobjname(P, pc[i], objname, sizeof (objname));
else|#
directive|else
argument|(void) proc_objname(P, pc[i], objname, sizeof (objname));
endif|#
directive|endif
argument|if (pc[i]> sym.st_value) { 				(void) snprintf(c, sizeof (c),
literal|"%s`%s+0x%llx"
argument|, dt_basename(objname), name, 				    (u_longlong_t)(pc[i] - sym.st_value)); 			} else { 				(void) snprintf(c, sizeof (c),
literal|"%s`%s"
argument|, dt_basename(objname), name); 			} 		} else if (str != NULL&& str[
literal|0
argument|] !=
literal|'\0'
argument|&& str[
literal|0
argument|] !=
literal|'@'
argument|&&
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|(P != NULL&& ((map = Paddr_to_map(P, pc[i])) == NULL || 		    (map->pr_mflags& MA_WRITE)))) {
else|#
directive|else
argument|(P != NULL&& ((map = proc_addr2map(P, pc[i])) == NULL))
argument_list|)
block|{
endif|#
directive|endif
comment|/* 			 * If the current string pointer in the string table 			 * does not point to an empty string _and_ the program 			 * counter falls in a writable region, we'll use the 			 * string from the string table instead of the raw 			 * address.  This last condition is necessary because 			 * some (broken) ustack helpers will return a string 			 * even for a program counter that they can't 			 * identify.  If we have a string for a program 			 * counter that falls in a segment that isn't 			 * writable, we assume that we have fallen into this 			 * case and we refuse to use the string. 			 */
operator|(
name|void
operator|)
name|snprintf
argument_list|(
name|c
argument_list|,
sizeof|sizeof
argument_list|(
name|c
argument_list|)
argument_list|,
literal|"%s"
argument_list|,
name|str
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
if|if
condition|(
name|P
operator|!=
name|NULL
operator|&&
name|Pobjname
argument_list|(
argument|P
argument_list|,
argument|pc[i]
argument_list|,
argument|objname
argument_list|,
else|#
directive|else
argument|if (P != NULL&& proc_objname(P, pc[i], objname,
endif|#
directive|endif
argument|sizeof (objname)) !=
literal|0
argument|) { 				(void) snprintf(c, sizeof (c),
literal|"%s`0x%llx"
argument|, 				    dt_basename(objname), (u_longlong_t)pc[i]); 			} else { 				(void) snprintf(c, sizeof (c),
literal|"0x%llx"
argument|, 				    (u_longlong_t)pc[i]); 			} 		}  		if ((err = dt_printf(dtp, fp, format, c))<
literal|0
argument|) 			break;  		if ((err = dt_printf(dtp, fp,
literal|"\n"
argument|))<
literal|0
argument|) 			break;  		if (str != NULL&& str[
literal|0
argument|] ==
literal|'@'
argument|) {
comment|/* 			 * If the first character of the string is an "at" sign, 			 * then the string is inferred to be an annotation -- 			 * and it is printed out beneath the frame and offset 			 * with brackets. 			 */
argument|if ((err = dt_printf(dtp, fp,
literal|"%*s"
argument|, indent,
literal|""
argument|))<
literal|0
argument|) 				break;  			(void) snprintf(c, sizeof (c),
literal|"  [ %s ]"
argument|,&str[
literal|1
argument|]);  			if ((err = dt_printf(dtp, fp, format, c))<
literal|0
argument|) 				break;  			if ((err = dt_printf(dtp, fp,
literal|"\n"
argument|))<
literal|0
argument|) 				break; 		}  		if (str != NULL) { 			str += strlen(str) +
literal|1
argument|; 			if (str - strbase>= strsize) 				str = NULL; 		} 	}  	if (P != NULL) { 		dt_proc_unlock(dtp, P); 		dt_proc_release(dtp, P); 	}  	return (err); }  static int dt_print_usym(dtrace_hdl_t *dtp, FILE *fp, caddr_t addr, dtrace_actkind_t act) {
comment|/* LINTED - alignment */
argument|uint64_t pid = ((uint64_t *)addr)[
literal|0
argument|];
comment|/* LINTED - alignment */
argument|uint64_t pc = ((uint64_t *)addr)[
literal|1
argument|]; 	const char *format =
literal|"  %-50s"
argument|; 	char *s; 	int n
argument_list|,
argument|len =
literal|256
argument|;  	if (act == DTRACEACT_USYM&& dtp->dt_vector == NULL) { 		struct ps_prochandle *P;  		if ((P = dt_proc_grab(dtp, pid, 		    PGRAB_RDONLY | PGRAB_FORCE,
literal|0
argument|)) != NULL) { 			GElf_Sym sym;  			dt_proc_lock(dtp, P);
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (Plookup_by_addr(P, pc, NULL,
literal|0
argument|,&sym) ==
literal|0
argument|)
else|#
directive|else
argument|if (proc_addr2sym(P, pc, NULL,
literal|0
argument|,&sym) ==
literal|0
argument|)
endif|#
directive|endif
argument|pc = sym.st_value;  			dt_proc_unlock(dtp, P); 			dt_proc_release(dtp, P); 		} 	}  	do { 		n = len; 		s = alloca(n); 	} while ((len = dtrace_uaddr2str(dtp, pid, pc, s, n))>= n);  	return (dt_printf(dtp, fp, format, s)); }  int dt_print_umod(dtrace_hdl_t *dtp, FILE *fp, const char *format, caddr_t addr) {
comment|/* LINTED - alignment */
argument|uint64_t pid = ((uint64_t *)addr)[
literal|0
argument|];
comment|/* LINTED - alignment */
argument|uint64_t pc = ((uint64_t *)addr)[
literal|1
argument|]; 	int err =
literal|0
argument|;  	char objname[PATH_MAX]
argument_list|,
argument|c[PATH_MAX *
literal|2
argument|]; 	struct ps_prochandle *P;  	if (format == NULL) 		format =
literal|"  %-50s"
argument|;
comment|/* 	 * See the comment in dt_print_ustack() for the rationale for 	 * printing raw addresses in the vectored case. 	 */
argument|if (dtp->dt_vector == NULL) 		P = dt_proc_grab(dtp, pid, PGRAB_RDONLY | PGRAB_FORCE,
literal|0
argument|); 	else 		P = NULL;  	if (P != NULL) 		dt_proc_lock(dtp, P);
comment|/* lock handle while we perform lookups */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (P != NULL&& Pobjname(P, pc, objname, sizeof (objname)) !=
literal|0
argument|) {
else|#
directive|else
argument|if (P != NULL&& proc_objname(P, pc, objname, sizeof (objname)) !=
literal|0
argument|) {
endif|#
directive|endif
argument|(void) snprintf(c, sizeof (c),
literal|"%s"
argument|, dt_basename(objname)); 	} else { 		(void) snprintf(c, sizeof (c),
literal|"0x%llx"
argument|, (u_longlong_t)pc); 	}  	err = dt_printf(dtp, fp, format, c);  	if (P != NULL) { 		dt_proc_unlock(dtp, P); 		dt_proc_release(dtp, P); 	}  	return (err); }  int dt_print_memory(dtrace_hdl_t *dtp, FILE *fp, caddr_t addr) { 	int quiet = (dtp->dt_options[DTRACEOPT_QUIET] != DTRACEOPT_UNSET); 	size_t nbytes = *((uintptr_t *) addr);  	return (dt_print_bytes(dtp, fp, addr + sizeof(uintptr_t), 	    nbytes,
literal|50
argument|, quiet,
literal|1
argument|)); }  typedef struct dt_type_cbdata { 	dtrace_hdl_t		*dtp; 	dtrace_typeinfo_t	dtt; 	caddr_t			addr; 	caddr_t			addrend; 	const char		*name; 	int			f_type; 	int			indent; 	int			type_width; 	int			name_width; 	FILE			*fp; } dt_type_cbdata_t;  static int	dt_print_type_data(dt_type_cbdata_t *, ctf_id_t);  static int dt_print_type_member(const char *name, ctf_id_t type, ulong_t off, void *arg) { 	dt_type_cbdata_t cbdata; 	dt_type_cbdata_t *cbdatap = arg; 	ssize_t ssz;  	if ((ssz = ctf_type_size(cbdatap->dtt.dtt_ctfp, type))<=
literal|0
argument|) 		return (
literal|0
argument|);  	off /=
literal|8
argument|;  	cbdata = *cbdatap; 	cbdata.name = name; 	cbdata.addr += off; 	cbdata.addrend = cbdata.addr + ssz;  	return (dt_print_type_data(&cbdata, type)); }  static int dt_print_type_width(const char *name, ctf_id_t type, ulong_t off, void *arg) { 	char buf[DT_TYPE_NAMELEN]; 	char *p; 	dt_type_cbdata_t *cbdatap = arg; 	size_t sz = strlen(name);  	ctf_type_name(cbdatap->dtt.dtt_ctfp, type, buf, sizeof (buf));  	if ((p = strchr(buf,
literal|'['
argument|)) != NULL) 		p[-
literal|1
argument|] =
literal|'\0'
argument|; 	else 		p =
literal|""
argument|;  	sz += strlen(p);  	if (sz> cbdatap->name_width) 		cbdatap->name_width = sz;  	sz = strlen(buf);  	if (sz> cbdatap->type_width) 		cbdatap->type_width = sz;  	return (
literal|0
argument|); }  static int dt_print_type_data(dt_type_cbdata_t *cbdatap, ctf_id_t type) { 	caddr_t addr = cbdatap->addr; 	caddr_t addrend = cbdatap->addrend; 	char buf[DT_TYPE_NAMELEN]; 	char *p; 	int cnt =
literal|0
argument|; 	uint_t kind = ctf_type_kind(cbdatap->dtt.dtt_ctfp, type); 	ssize_t ssz = ctf_type_size(cbdatap->dtt.dtt_ctfp, type);  	ctf_type_name(cbdatap->dtt.dtt_ctfp, type, buf, sizeof (buf));  	if ((p = strchr(buf,
literal|'['
argument|)) != NULL) 		p[-
literal|1
argument|] =
literal|'\0'
argument|; 	else 		p =
literal|""
argument|;  	if (cbdatap->f_type) { 		int type_width = roundup(cbdatap->type_width +
literal|1
argument|,
literal|4
argument|); 		int name_width = roundup(cbdatap->name_width +
literal|1
argument|,
literal|4
argument|);  		name_width -= strlen(cbdatap->name);  		dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%*s%-*s%s%-*s	= "
argument|,cbdatap->indent *
literal|4
argument|,
literal|""
argument|,type_width,buf,cbdatap->name,name_width,p); 	}  	while (addr< addrend) { 		dt_type_cbdata_t cbdata; 		ctf_arinfo_t arinfo; 		ctf_encoding_t cte; 		uintptr_t *up; 		void *vp = addr; 		cbdata = *cbdatap; 		cbdata.name =
literal|""
argument|; 		cbdata.addr = addr; 		cbdata.addrend = addr + ssz; 		cbdata.f_type =
literal|0
argument|; 		cbdata.indent++; 		cbdata.type_width =
literal|0
argument|; 		cbdata.name_width =
literal|0
argument|;  		if (cnt>
literal|0
argument|) 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%*s"
argument|, cbdatap->indent *
literal|4
argument|,
literal|""
argument|);  		switch (kind) { 		case CTF_K_INTEGER: 			if (ctf_type_encoding(cbdatap->dtt.dtt_ctfp, type,&cte) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			if ((cte.cte_format& CTF_INT_SIGNED) !=
literal|0
argument|) 				switch (cte.cte_bits) { 				case
literal|8
argument|: 					if (isprint(*((char *) vp))) 						dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"'%c', "
argument|, *((char *) vp)); 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%d (0x%x);\n"
argument|, *((char *) vp), *((char *) vp)); 					break; 				case
literal|16
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%hd (0x%hx);\n"
argument|, *((short *) vp), *((u_short *) vp)); 					break; 				case
literal|32
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%d (0x%x);\n"
argument|, *((int *) vp), *((u_int *) vp)); 					break; 				case
literal|64
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%jd (0x%jx);\n"
argument|, *((long long *) vp), *((unsigned long long *) vp)); 					break; 				default: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"CTF_K_INTEGER: format %x offset %u bits %u\n"
argument|,cte.cte_format,cte.cte_offset,cte.cte_bits); 					break; 				} 			else 				switch (cte.cte_bits) { 				case
literal|8
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%u (0x%x);\n"
argument|, *((uint8_t *) vp)&
literal|0xff
argument|, *((uint8_t *) vp)&
literal|0xff
argument|); 					break; 				case
literal|16
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%hu (0x%hx);\n"
argument|, *((u_short *) vp), *((u_short *) vp)); 					break; 				case
literal|32
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%u (0x%x);\n"
argument|, *((u_int *) vp), *((u_int *) vp)); 					break; 				case
literal|64
argument|: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%ju (0x%jx);\n"
argument|, *((unsigned long long *) vp), *((unsigned long long *) vp)); 					break; 				default: 					dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"CTF_K_INTEGER: format %x offset %u bits %u\n"
argument|,cte.cte_format,cte.cte_offset,cte.cte_bits); 					break; 				} 			break; 		case CTF_K_FLOAT: 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"CTF_K_FLOAT: format %x offset %u bits %u\n"
argument|,cte.cte_format,cte.cte_offset,cte.cte_bits); 			break; 		case CTF_K_POINTER: 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%p;\n"
argument|, *((void **) addr)); 			break; 		case CTF_K_ARRAY: 			if (ctf_array_info(cbdatap->dtt.dtt_ctfp, type,&arinfo) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"{\n%*s"
argument|,cbdata.indent *
literal|4
argument|,
literal|""
argument|); 			dt_print_type_data(&cbdata, arinfo.ctr_contents); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%*s};\n"
argument|,cbdatap->indent *
literal|4
argument|,
literal|""
argument|); 			break; 		case CTF_K_FUNCTION: 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"CTF_K_FUNCTION:\n"
argument|); 			break; 		case CTF_K_STRUCT: 			cbdata.f_type =
literal|1
argument|; 			if (ctf_member_iter(cbdatap->dtt.dtt_ctfp, type, 			    dt_print_type_width,&cbdata) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"{\n"
argument|); 			if (ctf_member_iter(cbdatap->dtt.dtt_ctfp, type, 			    dt_print_type_member,&cbdata) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%*s};\n"
argument|,cbdatap->indent *
literal|4
argument|,
literal|""
argument|); 			break; 		case CTF_K_UNION: 			cbdata.f_type =
literal|1
argument|; 			if (ctf_member_iter(cbdatap->dtt.dtt_ctfp, type, 			    dt_print_type_width,&cbdata) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"{\n"
argument|); 			if (ctf_member_iter(cbdatap->dtt.dtt_ctfp, type, 			    dt_print_type_member,&cbdata) !=
literal|0
argument|) 				return (-
literal|1
argument|); 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%*s};\n"
argument|,cbdatap->indent *
literal|4
argument|,
literal|""
argument|); 			break; 		case CTF_K_ENUM: 			dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"%s;\n"
argument|, ctf_enum_name(cbdatap->dtt.dtt_ctfp, type, *((int *) vp))); 			break; 		case CTF_K_TYPEDEF: 			dt_print_type_data(&cbdata, ctf_type_reference(cbdatap->dtt.dtt_ctfp,type)); 			break; 		case CTF_K_VOLATILE: 			if (cbdatap->f_type) 				dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"volatile "
argument|); 			dt_print_type_data(&cbdata, ctf_type_reference(cbdatap->dtt.dtt_ctfp,type)); 			break; 		case CTF_K_CONST: 			if (cbdatap->f_type) 				dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"const "
argument|); 			dt_print_type_data(&cbdata, ctf_type_reference(cbdatap->dtt.dtt_ctfp,type)); 			break; 		case CTF_K_RESTRICT: 			if (cbdatap->f_type) 				dt_printf(cbdatap->dtp, cbdatap->fp,
literal|"restrict "
argument|); 			dt_print_type_data(&cbdata, ctf_type_reference(cbdatap->dtt.dtt_ctfp,type)); 			break; 		default: 			break; 		}  		addr += ssz; 		cnt++; 	}  	return (
literal|0
argument|); }  static int dt_print_type(dtrace_hdl_t *dtp, FILE *fp, caddr_t addr) { 	caddr_t addrend; 	char *p; 	dtrace_typeinfo_t dtt; 	dt_type_cbdata_t cbdata; 	int num =
literal|0
argument|; 	int quiet = (dtp->dt_options[DTRACEOPT_QUIET] != DTRACEOPT_UNSET); 	ssize_t ssz;  	if (!quiet) 		dt_printf(dtp, fp,
literal|"\n"
argument|);
comment|/* Get the total number of bytes of data buffered. */
argument|size_t nbytes = *((uintptr_t *) addr); 	addr += sizeof(uintptr_t);
comment|/* 	 * Get the size of the type so that we can check that it matches 	 * the CTF data we look up and so that we can figure out how many 	 * type elements are buffered. 	 */
argument|size_t typs = *((uintptr_t *) addr); 	addr += sizeof(uintptr_t);
comment|/* 	 * Point to the type string in the buffer. Get it's string 	 * length and round it up to become the offset to the start 	 * of the buffered type data which we would like to be aligned 	 * for easy access. 	 */
argument|char *strp = (char *) addr; 	int offset = roundup(strlen(strp) +
literal|1
argument|, sizeof(uintptr_t));
comment|/* 	 * The type string might have a format such as 'int [20]'. 	 * Check if there is an array dimension present. 	 */
argument|if ((p = strchr(strp,
literal|'['
argument|)) != NULL) {
comment|/* Strip off the array dimension. */
argument|*p++ =
literal|'\0'
argument|;  		for (; *p !=
literal|'\0'
argument|&& *p !=
literal|']'
argument|; p++) 			num = num *
literal|10
argument|+ *p -
literal|'0'
argument|; 	} else
comment|/* No array dimension, so default. */
argument|num =
literal|1
argument|;
comment|/* Lookup the CTF type from the type string. */
argument|if (dtrace_lookup_by_type(dtp,  DTRACE_OBJ_EVERY, strp,&dtt)<
literal|0
argument|) 		return (-
literal|1
argument|);
comment|/* Offset the buffer address to the start of the data... */
argument|addr += offset;  	ssz = ctf_type_size(dtt.dtt_ctfp, dtt.dtt_type);  	if (typs != ssz) { 		printf(
literal|"Expected type size from buffer (%lu) to match type size looked up now (%ld)\n"
argument|, (u_long) typs, (long) ssz); 		return (-
literal|1
argument|); 	}  	cbdata.dtp = dtp; 	cbdata.dtt = dtt; 	cbdata.name =
literal|""
argument|; 	cbdata.addr = addr; 	cbdata.addrend = addr + nbytes; 	cbdata.indent =
literal|1
argument|; 	cbdata.f_type =
literal|1
argument|; 	cbdata.type_width =
literal|0
argument|; 	cbdata.name_width =
literal|0
argument|; 	cbdata.fp = fp;  	return (dt_print_type_data(&cbdata, dtt.dtt_type)); }  static int dt_print_sym(dtrace_hdl_t *dtp, FILE *fp, const char *format, caddr_t addr) {
comment|/* LINTED - alignment */
argument|uint64_t pc = *((uint64_t *)addr); 	dtrace_syminfo_t dts; 	GElf_Sym sym; 	char c[PATH_MAX *
literal|2
argument|];  	if (format == NULL) 		format =
literal|"  %-50s"
argument|;  	if (dtrace_lookup_by_addr(dtp, pc,&sym,&dts) ==
literal|0
argument|) { 		(void) snprintf(c, sizeof (c),
literal|"%s`%s"
argument|, 		    dts.dts_object, dts.dts_name); 	} else {
comment|/* 		 * We'll repeat the lookup, but this time we'll specify a 		 * NULL GElf_Sym -- indicating that we're only interested in 		 * the containing module. 		 */
argument|if (dtrace_lookup_by_addr(dtp, pc, NULL,&dts) ==
literal|0
argument|) { 			(void) snprintf(c, sizeof (c),
literal|"%s`0x%llx"
argument|, 			    dts.dts_object, (u_longlong_t)pc); 		} else { 			(void) snprintf(c, sizeof (c),
literal|"0x%llx"
argument|, 			    (u_longlong_t)pc); 		} 	}  	if (dt_printf(dtp, fp, format, c)<
literal|0
argument|) 		return (-
literal|1
argument|);  	return (
literal|0
argument|); }  int dt_print_mod(dtrace_hdl_t *dtp, FILE *fp, const char *format, caddr_t addr) {
comment|/* LINTED - alignment */
argument|uint64_t pc = *((uint64_t *)addr); 	dtrace_syminfo_t dts; 	char c[PATH_MAX *
literal|2
argument|];  	if (format == NULL) 		format =
literal|"  %-50s"
argument|;  	if (dtrace_lookup_by_addr(dtp, pc, NULL,&dts) ==
literal|0
argument|) { 		(void) snprintf(c, sizeof (c),
literal|"%s"
argument|, dts.dts_object); 	} else { 		(void) snprintf(c, sizeof (c),
literal|"0x%llx"
argument|, (u_longlong_t)pc); 	}  	if (dt_printf(dtp, fp, format, c)<
literal|0
argument|) 		return (-
literal|1
argument|);  	return (
literal|0
argument|); }  typedef struct dt_normal { 	dtrace_aggvarid_t dtnd_id; 	uint64_t dtnd_normal; } dt_normal_t;  static int dt_normalize_agg(const dtrace_aggdata_t *aggdata, void *arg) { 	dt_normal_t *normal = arg; 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	dtrace_aggvarid_t id = normal->dtnd_id;  	if (agg->dtagd_nrecs ==
literal|0
argument|) 		return (DTRACE_AGGWALK_NEXT);  	if (agg->dtagd_varid != id) 		return (DTRACE_AGGWALK_NEXT);  	((dtrace_aggdata_t *)aggdata)->dtada_normal = normal->dtnd_normal; 	return (DTRACE_AGGWALK_NORMALIZE); }  static int dt_normalize(dtrace_hdl_t *dtp, caddr_t base, dtrace_recdesc_t *rec) { 	dt_normal_t normal; 	caddr_t addr;
comment|/* 	 * We (should) have two records:  the aggregation ID followed by the 	 * normalization value. 	 */
argument|addr = base + rec->dtrd_offset;  	if (rec->dtrd_size != sizeof (dtrace_aggvarid_t)) 		return (dt_set_errno(dtp, EDT_BADNORMAL));
comment|/* LINTED - alignment */
argument|normal.dtnd_id = *((dtrace_aggvarid_t *)addr); 	rec++;  	if (rec->dtrd_action != DTRACEACT_LIBACT) 		return (dt_set_errno(dtp, EDT_BADNORMAL));  	if (rec->dtrd_arg != DT_ACT_NORMALIZE) 		return (dt_set_errno(dtp, EDT_BADNORMAL));  	addr = base + rec->dtrd_offset;  	switch (rec->dtrd_size) { 	case sizeof (uint64_t):
comment|/* LINTED - alignment */
argument|normal.dtnd_normal = *((uint64_t *)addr); 		break; 	case sizeof (uint32_t):
comment|/* LINTED - alignment */
argument|normal.dtnd_normal = *((uint32_t *)addr); 		break; 	case sizeof (uint16_t):
comment|/* LINTED - alignment */
argument|normal.dtnd_normal = *((uint16_t *)addr); 		break; 	case sizeof (uint8_t): 		normal.dtnd_normal = *((uint8_t *)addr); 		break; 	default: 		return (dt_set_errno(dtp, EDT_BADNORMAL)); 	}  	(void) dtrace_aggregate_walk(dtp, dt_normalize_agg,&normal);  	return (
literal|0
argument|); }  static int dt_denormalize_agg(const dtrace_aggdata_t *aggdata, void *arg) { 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	dtrace_aggvarid_t id = *((dtrace_aggvarid_t *)arg);  	if (agg->dtagd_nrecs ==
literal|0
argument|) 		return (DTRACE_AGGWALK_NEXT);  	if (agg->dtagd_varid != id) 		return (DTRACE_AGGWALK_NEXT);  	return (DTRACE_AGGWALK_DENORMALIZE); }  static int dt_clear_agg(const dtrace_aggdata_t *aggdata, void *arg) { 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	dtrace_aggvarid_t id = *((dtrace_aggvarid_t *)arg);  	if (agg->dtagd_nrecs ==
literal|0
argument|) 		return (DTRACE_AGGWALK_NEXT);  	if (agg->dtagd_varid != id) 		return (DTRACE_AGGWALK_NEXT);  	return (DTRACE_AGGWALK_CLEAR); }  typedef struct dt_trunc { 	dtrace_aggvarid_t dttd_id; 	uint64_t dttd_remaining; } dt_trunc_t;  static int dt_trunc_agg(const dtrace_aggdata_t *aggdata, void *arg) { 	dt_trunc_t *trunc = arg; 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	dtrace_aggvarid_t id = trunc->dttd_id;  	if (agg->dtagd_nrecs ==
literal|0
argument|) 		return (DTRACE_AGGWALK_NEXT);  	if (agg->dtagd_varid != id) 		return (DTRACE_AGGWALK_NEXT);  	if (trunc->dttd_remaining ==
literal|0
argument|) 		return (DTRACE_AGGWALK_REMOVE);  	trunc->dttd_remaining--; 	return (DTRACE_AGGWALK_NEXT); }  static int dt_trunc(dtrace_hdl_t *dtp, caddr_t base, dtrace_recdesc_t *rec) { 	dt_trunc_t trunc; 	caddr_t addr; 	int64_t remaining; 	int (*func)(dtrace_hdl_t *, dtrace_aggregate_f *, void *);
comment|/* 	 * We (should) have two records:  the aggregation ID followed by the 	 * number of aggregation entries after which the aggregation is to be 	 * truncated. 	 */
argument|addr = base + rec->dtrd_offset;  	if (rec->dtrd_size != sizeof (dtrace_aggvarid_t)) 		return (dt_set_errno(dtp, EDT_BADTRUNC));
comment|/* LINTED - alignment */
argument|trunc.dttd_id = *((dtrace_aggvarid_t *)addr); 	rec++;  	if (rec->dtrd_action != DTRACEACT_LIBACT) 		return (dt_set_errno(dtp, EDT_BADTRUNC));  	if (rec->dtrd_arg != DT_ACT_TRUNC) 		return (dt_set_errno(dtp, EDT_BADTRUNC));  	addr = base + rec->dtrd_offset;  	switch (rec->dtrd_size) { 	case sizeof (uint64_t):
comment|/* LINTED - alignment */
argument|remaining = *((int64_t *)addr); 		break; 	case sizeof (uint32_t):
comment|/* LINTED - alignment */
argument|remaining = *((int32_t *)addr); 		break; 	case sizeof (uint16_t):
comment|/* LINTED - alignment */
argument|remaining = *((int16_t *)addr); 		break; 	case sizeof (uint8_t): 		remaining = *((int8_t *)addr); 		break; 	default: 		return (dt_set_errno(dtp, EDT_BADNORMAL)); 	}  	if (remaining<
literal|0
argument|) { 		func = dtrace_aggregate_walk_valsorted; 		remaining = -remaining; 	} else { 		func = dtrace_aggregate_walk_valrevsorted; 	}  	assert(remaining>=
literal|0
argument|); 	trunc.dttd_remaining = remaining;  	(void) func(dtp, dt_trunc_agg,&trunc);  	return (
literal|0
argument|); }  static int dt_print_datum(dtrace_hdl_t *dtp, FILE *fp, dtrace_recdesc_t *rec,     caddr_t addr, size_t size, uint64_t normal) { 	int err; 	dtrace_actkind_t act = rec->dtrd_action;  	switch (act) { 	case DTRACEACT_STACK: 		return (dt_print_stack(dtp, fp, NULL, addr, 		    rec->dtrd_arg, rec->dtrd_size / rec->dtrd_arg));  	case DTRACEACT_USTACK: 	case DTRACEACT_JSTACK: 		return (dt_print_ustack(dtp, fp, NULL, addr, rec->dtrd_arg));  	case DTRACEACT_USYM: 	case DTRACEACT_UADDR: 		return (dt_print_usym(dtp, fp, addr, act));  	case DTRACEACT_UMOD: 		return (dt_print_umod(dtp, fp, NULL, addr));  	case DTRACEACT_SYM: 		return (dt_print_sym(dtp, fp, NULL, addr));  	case DTRACEACT_MOD: 		return (dt_print_mod(dtp, fp, NULL, addr));  	case DTRACEAGG_QUANTIZE: 		return (dt_print_quantize(dtp, fp, addr, size, normal));  	case DTRACEAGG_LQUANTIZE: 		return (dt_print_lquantize(dtp, fp, addr, size, normal));  	case DTRACEAGG_AVG: 		return (dt_print_average(dtp, fp, addr, size, normal));  	case DTRACEAGG_STDDEV: 		return (dt_print_stddev(dtp, fp, addr, size, normal));  	default: 		break; 	}  	switch (size) { 	case sizeof (uint64_t): 		err = dt_printf(dtp, fp,
literal|" %16lld"
argument|,
comment|/* LINTED - alignment */
argument|(long long)*((uint64_t *)addr) / normal); 		break; 	case sizeof (uint32_t):
comment|/* LINTED - alignment */
argument|err = dt_printf(dtp, fp,
literal|" %8d"
argument|, *((uint32_t *)addr) / 		    (uint32_t)normal); 		break; 	case sizeof (uint16_t):
comment|/* LINTED - alignment */
argument|err = dt_printf(dtp, fp,
literal|" %5d"
argument|, *((uint16_t *)addr) / 		    (uint32_t)normal); 		break; 	case sizeof (uint8_t): 		err = dt_printf(dtp, fp,
literal|" %3d"
argument|, *((uint8_t *)addr) / 		    (uint32_t)normal); 		break; 	default: 		err = dt_print_bytes(dtp, fp, addr, size,
literal|50
argument|,
literal|0
argument|,
literal|0
argument|); 		break; 	}  	return (err); }  int dt_print_aggs(const dtrace_aggdata_t **aggsdata, int naggvars, void *arg) { 	int i
argument_list|,
argument|aggact =
literal|0
argument|; 	dt_print_aggdata_t *pd = arg; 	const dtrace_aggdata_t *aggdata = aggsdata[
literal|0
argument|]; 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	FILE *fp = pd->dtpa_fp; 	dtrace_hdl_t *dtp = pd->dtpa_dtp; 	dtrace_recdesc_t *rec; 	dtrace_actkind_t act; 	caddr_t addr; 	size_t size;
comment|/* 	 * Iterate over each record description in the key, printing the traced 	 * data, skipping the first datum (the tuple member created by the 	 * compiler). 	 */
argument|for (i =
literal|1
argument|; i< agg->dtagd_nrecs; i++) { 		rec =&agg->dtagd_rec[i]; 		act = rec->dtrd_action; 		addr = aggdata->dtada_data + rec->dtrd_offset; 		size = rec->dtrd_size;  		if (DTRACEACT_ISAGG(act)) { 			aggact = i; 			break; 		}  		if (dt_print_datum(dtp, fp, rec, addr, size,
literal|1
argument|)<
literal|0
argument|) 			return (-
literal|1
argument|);  		if (dt_buffered_flush(dtp, NULL, rec, aggdata, 		    DTRACE_BUFDATA_AGGKEY)<
literal|0
argument|) 			return (-
literal|1
argument|); 	}  	assert(aggact !=
literal|0
argument|);  	for (i = (naggvars ==
literal|1
argument|?
literal|0
argument|:
literal|1
argument|); i< naggvars; i++) { 		uint64_t normal;  		aggdata = aggsdata[i]; 		agg = aggdata->dtada_desc; 		rec =&agg->dtagd_rec[aggact]; 		act = rec->dtrd_action; 		addr = aggdata->dtada_data + rec->dtrd_offset; 		size = rec->dtrd_size;  		assert(DTRACEACT_ISAGG(act)); 		normal = aggdata->dtada_normal;  		if (dt_print_datum(dtp, fp, rec, addr, size, normal)<
literal|0
argument|) 			return (-
literal|1
argument|);  		if (dt_buffered_flush(dtp, NULL, rec, aggdata, 		    DTRACE_BUFDATA_AGGVAL)<
literal|0
argument|) 			return (-
literal|1
argument|);  		if (!pd->dtpa_allunprint) 			agg->dtagd_flags |= DTRACE_AGD_PRINTED; 	}  	if (dt_printf(dtp, fp,
literal|"\n"
argument|)<
literal|0
argument|) 		return (-
literal|1
argument|);  	if (dt_buffered_flush(dtp, NULL, NULL, aggdata, 	    DTRACE_BUFDATA_AGGFORMAT | DTRACE_BUFDATA_AGGLAST)<
literal|0
argument|) 		return (-
literal|1
argument|);  	return (
literal|0
argument|); }  int dt_print_agg(const dtrace_aggdata_t *aggdata, void *arg) { 	dt_print_aggdata_t *pd = arg; 	dtrace_aggdesc_t *agg = aggdata->dtada_desc; 	dtrace_aggvarid_t aggvarid = pd->dtpa_id;  	if (pd->dtpa_allunprint) { 		if (agg->dtagd_flags& DTRACE_AGD_PRINTED) 			return (
literal|0
argument|); 	} else {
comment|/* 		 * If we're not printing all unprinted aggregations, then the 		 * aggregation variable ID denotes a specific aggregation 		 * variable that we should print -- skip any other aggregations 		 * that we encounter. 		 */
argument|if (agg->dtagd_nrecs ==
literal|0
argument|) 			return (
literal|0
argument|);  		if (aggvarid != agg->dtagd_varid) 			return (
literal|0
argument|); 	}  	return (dt_print_aggs(&aggdata,
literal|1
argument|, arg)); }  int dt_setopt(dtrace_hdl_t *dtp, const dtrace_probedata_t *data,     const char *option, const char *value) { 	int len
argument_list|,
argument|rval; 	char *msg; 	const char *errstr; 	dtrace_setoptdata_t optdata;  	bzero(&optdata, sizeof (optdata)); 	(void) dtrace_getopt(dtp, option,&optdata.dtsda_oldval);  	if (dtrace_setopt(dtp, option, value) ==
literal|0
argument|) { 		(void) dtrace_getopt(dtp, option,&optdata.dtsda_newval); 		optdata.dtsda_probe = data; 		optdata.dtsda_option = option; 		optdata.dtsda_handle = dtp;  		if ((rval = dt_handle_setopt(dtp,&optdata)) !=
literal|0
argument|) 			return (rval);  		return (
literal|0
argument|); 	}  	errstr = dtrace_errmsg(dtp, dtrace_errno(dtp)); 	len = strlen(option) + strlen(value) + strlen(errstr) +
literal|80
argument|; 	msg = alloca(len);  	(void) snprintf(msg, len,
literal|"couldn't set option \"%s\" to \"%s\": %s\n"
argument|, 	    option, value, errstr);  	if ((rval = dt_handle_liberr(dtp, data, msg)) ==
literal|0
argument|) 		return (
literal|0
argument|);  	return (rval); }  static int dt_consume_cpu(dtrace_hdl_t *dtp, FILE *fp, int cpu, dtrace_bufdesc_t *buf,     dtrace_consume_probe_f *efunc, dtrace_consume_rec_f *rfunc, void *arg) { 	dtrace_epid_t id; 	size_t offs
argument_list|,
argument|start = buf->dtbd_oldest
argument_list|,
argument|end = buf->dtbd_size; 	int flow = (dtp->dt_options[DTRACEOPT_FLOWINDENT] != DTRACEOPT_UNSET); 	int quiet = (dtp->dt_options[DTRACEOPT_QUIET] != DTRACEOPT_UNSET); 	int rval
argument_list|,
argument|i
argument_list|,
argument|n; 	dtrace_epid_t last = DTRACE_EPIDNONE; 	dtrace_probedata_t data; 	uint64_t drops; 	caddr_t addr;  	bzero(&data, sizeof (data)); 	data.dtpda_handle = dtp; 	data.dtpda_cpu = cpu;  again: 	for (offs = start; offs< end; ) { 		dtrace_eprobedesc_t *epd;
comment|/* 		 * We're guaranteed to have an ID. 		 */
argument|id = *(uint32_t *)((uintptr_t)buf->dtbd_data + offs);  		if (id == DTRACE_EPIDNONE) {
comment|/* 			 * This is filler to assure proper alignment of the 			 * next record; we simply ignore it. 			 */
argument|offs += sizeof (id); 			continue; 		}  		if ((rval = dt_epid_lookup(dtp, id,&data.dtpda_edesc,&data.dtpda_pdesc)) !=
literal|0
argument|) 			return (rval);  		epd = data.dtpda_edesc; 		data.dtpda_data = buf->dtbd_data + offs;  		if (data.dtpda_edesc->dtepd_uarg != DT_ECB_DEFAULT) { 			rval = dt_handle(dtp,&data);  			if (rval == DTRACE_CONSUME_NEXT) 				goto nextepid;  			if (rval == DTRACE_CONSUME_ERROR) 				return (-
literal|1
argument|); 		}  		if (flow) 			(void) dt_flowindent(dtp,&data, last, buf, offs);  		rval = (*efunc)(&data, arg);  		if (flow) { 			if (data.dtpda_flow == DTRACEFLOW_ENTRY) 				data.dtpda_indent +=
literal|2
argument|; 		}  		if (rval == DTRACE_CONSUME_NEXT) 			goto nextepid;  		if (rval == DTRACE_CONSUME_ABORT) 			return (dt_set_errno(dtp, EDT_DIRABORT));  		if (rval != DTRACE_CONSUME_THIS) 			return (dt_set_errno(dtp, EDT_BADRVAL));  		for (i =
literal|0
argument|; i< epd->dtepd_nrecs; i++) { 			dtrace_recdesc_t *rec =&epd->dtepd_rec[i]; 			dtrace_actkind_t act = rec->dtrd_action;  			data.dtpda_data = buf->dtbd_data + offs + 			    rec->dtrd_offset; 			addr = data.dtpda_data;  			if (act == DTRACEACT_LIBACT) { 				uint64_t arg = rec->dtrd_arg; 				dtrace_aggvarid_t id;  				switch (arg) { 				case DT_ACT_CLEAR:
comment|/* LINTED - alignment */
argument|id = *((dtrace_aggvarid_t *)addr); 					(void) dtrace_aggregate_walk(dtp, 					    dt_clear_agg,&id); 					continue;  				case DT_ACT_DENORMALIZE:
comment|/* LINTED - alignment */
argument|id = *((dtrace_aggvarid_t *)addr); 					(void) dtrace_aggregate_walk(dtp, 					    dt_denormalize_agg,&id); 					continue;  				case DT_ACT_FTRUNCATE: 					if (fp == NULL) 						continue;  					(void) fflush(fp); 					(void) ftruncate(fileno(fp),
literal|0
argument|); 					(void) fseeko(fp,
literal|0
argument|, SEEK_SET); 					continue;  				case DT_ACT_NORMALIZE: 					if (i == epd->dtepd_nrecs -
literal|1
argument|) 						return (dt_set_errno(dtp, 						    EDT_BADNORMAL));  					if (dt_normalize(dtp, 					    buf->dtbd_data + offs, rec) !=
literal|0
argument|) 						return (-
literal|1
argument|);  					i++; 					continue;  				case DT_ACT_SETOPT: { 					uint64_t *opts = dtp->dt_options; 					dtrace_recdesc_t *valrec; 					uint32_t valsize; 					caddr_t val; 					int rv;  					if (i == epd->dtepd_nrecs -
literal|1
argument|) { 						return (dt_set_errno(dtp, 						    EDT_BADSETOPT)); 					}  					valrec =&epd->dtepd_rec[++i]; 					valsize = valrec->dtrd_size;  					if (valrec->dtrd_action != act || 					    valrec->dtrd_arg != arg) { 						return (dt_set_errno(dtp, 						    EDT_BADSETOPT)); 					}  					if (valsize> sizeof (uint64_t)) { 						val = buf->dtbd_data + offs + 						    valrec->dtrd_offset; 					} else { 						val =
literal|"1"
argument|; 					}  					rv = dt_setopt(dtp,&data, addr, val);  					if (rv !=
literal|0
argument|) 						return (-
literal|1
argument|);  					flow = (opts[DTRACEOPT_FLOWINDENT] != 					    DTRACEOPT_UNSET); 					quiet = (opts[DTRACEOPT_QUIET] != 					    DTRACEOPT_UNSET);  					continue; 				}  				case DT_ACT_TRUNC: 					if (i == epd->dtepd_nrecs -
literal|1
argument|) 						return (dt_set_errno(dtp, 						    EDT_BADTRUNC));  					if (dt_trunc(dtp, 					    buf->dtbd_data + offs, rec) !=
literal|0
argument|) 						return (-
literal|1
argument|);  					i++; 					continue;  				default: 					continue; 				} 			}  			rval = (*rfunc)(&data, rec, arg);  			if (rval == DTRACE_CONSUME_NEXT) 				continue;  			if (rval == DTRACE_CONSUME_ABORT) 				return (dt_set_errno(dtp, EDT_DIRABORT));  			if (rval != DTRACE_CONSUME_THIS) 				return (dt_set_errno(dtp, EDT_BADRVAL));  			if (act == DTRACEACT_STACK) { 				int depth = rec->dtrd_arg;  				if (dt_print_stack(dtp, fp, NULL, addr, depth, 				    rec->dtrd_size / depth)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_USTACK || 			    act == DTRACEACT_JSTACK) { 				if (dt_print_ustack(dtp, fp, NULL, 				    addr, rec->dtrd_arg)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_SYM) { 				if (dt_print_sym(dtp, fp, NULL, addr)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_MOD) { 				if (dt_print_mod(dtp, fp, NULL, addr)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_USYM || act == DTRACEACT_UADDR) { 				if (dt_print_usym(dtp, fp, addr, act)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_UMOD) { 				if (dt_print_umod(dtp, fp, NULL, addr)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_PRINTM) { 				if (dt_print_memory(dtp, fp, addr)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (act == DTRACEACT_PRINTT) { 				if (dt_print_type(dtp, fp, addr)<
literal|0
argument|) 					return (-
literal|1
argument|); 				goto nextrec; 			}  			if (DTRACEACT_ISPRINTFLIKE(act)) { 				void *fmtdata; 				int (*func)(dtrace_hdl_t *, FILE *, void *, 				    const dtrace_probedata_t *, 				    const dtrace_recdesc_t *, uint_t, 				    const void *buf, size_t);  				if ((fmtdata = dt_format_lookup(dtp, 				    rec->dtrd_format)) == NULL) 					goto nofmt;  				switch (act) { 				case DTRACEACT_PRINTF: 					func = dtrace_fprintf; 					break; 				case DTRACEACT_PRINTA: 					func = dtrace_fprinta; 					break; 				case DTRACEACT_SYSTEM: 					func = dtrace_system; 					break; 				case DTRACEACT_FREOPEN: 					func = dtrace_freopen; 					break; 				}  				n = (*func)(dtp, fp, fmtdata,&data, 				    rec, epd->dtepd_nrecs - i, 				    (uchar_t *)buf->dtbd_data + offs, 				    buf->dtbd_size - offs);  				if (n<
literal|0
argument|) 					return (-
literal|1
argument|);
comment|/* errno is set for us */
argument|if (n>
literal|0
argument|) 					i += n -
literal|1
argument|; 				goto nextrec; 			}  nofmt: 			if (act == DTRACEACT_PRINTA) { 				dt_print_aggdata_t pd; 				dtrace_aggvarid_t *aggvars; 				int j
argument_list|,
argument|naggvars =
literal|0
argument|; 				size_t size = ((epd->dtepd_nrecs - i) * 				    sizeof (dtrace_aggvarid_t));  				if ((aggvars = dt_alloc(dtp, size)) == NULL) 					return (-
literal|1
argument|);
comment|/* 				 * This might be a printa() with multiple 				 * aggregation variables.  We need to scan 				 * forward through the records until we find 				 * a record from a different statement. 				 */
argument|for (j = i; j< epd->dtepd_nrecs; j++) { 					dtrace_recdesc_t *nrec; 					caddr_t naddr;  					nrec =&epd->dtepd_rec[j];  					if (nrec->dtrd_uarg != rec->dtrd_uarg) 						break;  					if (nrec->dtrd_action != act) { 						return (dt_set_errno(dtp, 						    EDT_BADAGG)); 					}  					naddr = buf->dtbd_data + offs + 					    nrec->dtrd_offset;  					aggvars[naggvars++] =
comment|/* LINTED - alignment */
argument|*((dtrace_aggvarid_t *)naddr); 				}  				i = j -
literal|1
argument|; 				bzero(&pd, sizeof (pd)); 				pd.dtpa_dtp = dtp; 				pd.dtpa_fp = fp;  				assert(naggvars>=
literal|1
argument|);  				if (naggvars ==
literal|1
argument|) { 					pd.dtpa_id = aggvars[
literal|0
argument|]; 					dt_free(dtp, aggvars);  					if (dt_printf(dtp, fp,
literal|"\n"
argument|)<
literal|0
argument||| 					    dtrace_aggregate_walk_sorted(dtp, 					    dt_print_agg,&pd)<
literal|0
argument|) 						return (-
literal|1
argument|); 					goto nextrec; 				}  				if (dt_printf(dtp, fp,
literal|"\n"
argument|)<
literal|0
argument||| 				    dtrace_aggregate_walk_joined(dtp, aggvars, 				    naggvars, dt_print_aggs,&pd)<
literal|0
argument|) { 					dt_free(dtp, aggvars); 					return (-
literal|1
argument|); 				}  				dt_free(dtp, aggvars); 				goto nextrec; 			}  			switch (rec->dtrd_size) { 			case sizeof (uint64_t): 				n = dt_printf(dtp, fp, 				    quiet ?
literal|"%lld"
argument|:
literal|" %16lld"
argument|,
comment|/* LINTED - alignment */
argument|*((unsigned long long *)addr)); 				break; 			case sizeof (uint32_t): 				n = dt_printf(dtp, fp, quiet ?
literal|"%d"
argument|:
literal|" %8d"
argument|,
comment|/* LINTED - alignment */
argument|*((uint32_t *)addr)); 				break; 			case sizeof (uint16_t): 				n = dt_printf(dtp, fp, quiet ?
literal|"%d"
argument|:
literal|" %5d"
argument|,
comment|/* LINTED - alignment */
argument|*((uint16_t *)addr)); 				break; 			case sizeof (uint8_t): 				n = dt_printf(dtp, fp, quiet ?
literal|"%d"
argument|:
literal|" %3d"
argument|, 				    *((uint8_t *)addr)); 				break; 			default: 				n = dt_print_bytes(dtp, fp, addr, 				    rec->dtrd_size,
literal|33
argument|, quiet,
literal|0
argument|); 				break; 			}  			if (n<
literal|0
argument|) 				return (-
literal|1
argument|);
comment|/* errno is set for us */
argument|nextrec: 			if (dt_buffered_flush(dtp,&data, rec, NULL,
literal|0
argument|)<
literal|0
argument|) 				return (-
literal|1
argument|);
comment|/* errno is set for us */
argument|}
comment|/* 		 * Call the record callback with a NULL record to indicate 		 * that we're done processing this EPID. 		 */
argument|rval = (*rfunc)(&data, NULL, arg); nextepid: 		offs += epd->dtepd_size; 		last = id; 	}  	if (buf->dtbd_oldest !=
literal|0
argument|&& start == buf->dtbd_oldest) { 		end = buf->dtbd_oldest; 		start =
literal|0
argument|; 		goto again; 	}  	if ((drops = buf->dtbd_drops) ==
literal|0
argument|) 		return (
literal|0
argument|);
comment|/* 	 * Explicitly zero the drops to prevent us from processing them again. 	 */
argument|buf->dtbd_drops =
literal|0
argument|;  	return (dt_handle_cpudrop(dtp, cpu, DTRACEDROP_PRINCIPAL, drops)); }  typedef struct dt_begin { 	dtrace_consume_probe_f *dtbgn_probefunc; 	dtrace_consume_rec_f *dtbgn_recfunc; 	void *dtbgn_arg; 	dtrace_handle_err_f *dtbgn_errhdlr; 	void *dtbgn_errarg; 	int dtbgn_beginonly; } dt_begin_t;  static int dt_consume_begin_probe(const dtrace_probedata_t *data, void *arg) { 	dt_begin_t *begin = (dt_begin_t *)arg; 	dtrace_probedesc_t *pd = data->dtpda_pdesc;  	int r1 = (strcmp(pd->dtpd_provider,
literal|"dtrace"
argument|) ==
literal|0
argument|); 	int r2 = (strcmp(pd->dtpd_name,
literal|"BEGIN"
argument|) ==
literal|0
argument|);  	if (begin->dtbgn_beginonly) { 		if (!(r1&& r2)) 			return (DTRACE_CONSUME_NEXT); 	} else { 		if (r1&& r2) 			return (DTRACE_CONSUME_NEXT); 	}
comment|/* 	 * We have a record that we're interested in.  Now call the underlying 	 * probe function... 	 */
argument|return (begin->dtbgn_probefunc(data, begin->dtbgn_arg)); }  static int dt_consume_begin_record(const dtrace_probedata_t *data,     const dtrace_recdesc_t *rec, void *arg) { 	dt_begin_t *begin = (dt_begin_t *)arg;  	return (begin->dtbgn_recfunc(data, rec, begin->dtbgn_arg)); }  static int dt_consume_begin_error(const dtrace_errdata_t *data, void *arg) { 	dt_begin_t *begin = (dt_begin_t *)arg; 	dtrace_probedesc_t *pd = data->dteda_pdesc;  	int r1 = (strcmp(pd->dtpd_provider,
literal|"dtrace"
argument|) ==
literal|0
argument|); 	int r2 = (strcmp(pd->dtpd_name,
literal|"BEGIN"
argument|) ==
literal|0
argument|);  	if (begin->dtbgn_beginonly) { 		if (!(r1&& r2)) 			return (DTRACE_HANDLE_OK); 	} else { 		if (r1&& r2) 			return (DTRACE_HANDLE_OK); 	}  	return (begin->dtbgn_errhdlr(data, begin->dtbgn_errarg)); }  static int dt_consume_begin(dtrace_hdl_t *dtp, FILE *fp, dtrace_bufdesc_t *buf,     dtrace_consume_probe_f *pf, dtrace_consume_rec_f *rf, void *arg) {
comment|/* 	 * There's this idea that the BEGIN probe should be processed before 	 * everything else, and that the END probe should be processed after 	 * anything else.  In the common case, this is pretty easy to deal 	 * with.  However, a situation may arise where the BEGIN enabling and 	 * END enabling are on the same CPU, and some enabling in the middle 	 * occurred on a different CPU.  To deal with this (blech!) we need to 	 * consume the BEGIN buffer up until the end of the BEGIN probe, and 	 * then set it aside.  We will then process every other CPU, and then 	 * we'll return to the BEGIN CPU and process the rest of the data 	 * (which will inevitably include the END probe, if any).  Making this 	 * even more complicated (!) is the library's ERROR enabling.  Because 	 * this enabling is processed before we even get into the consume call 	 * back, any ERROR firing would result in the library's ERROR enabling 	 * being processed twice -- once in our first pass (for BEGIN probes), 	 * and again in our second pass (for everything but BEGIN probes).  To 	 * deal with this, we interpose on the ERROR handler to assure that we 	 * only process ERROR enablings induced by BEGIN enablings in the 	 * first pass, and that we only process ERROR enablings _not_ induced 	 * by BEGIN enablings in the second pass. 	 */
argument|dt_begin_t begin; 	processorid_t cpu = dtp->dt_beganon; 	dtrace_bufdesc_t nbuf;
if|#
directive|if
operator|!
name|defined
argument_list|(
name|sun
argument_list|)
argument|dtrace_bufdesc_t *pbuf;
endif|#
directive|endif
argument|int rval
argument_list|,
argument|i; 	static int max_ncpus; 	dtrace_optval_t size;  	dtp->dt_beganon = -
literal|1
argument|;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP, buf) == -
literal|1
argument|) {
else|#
directive|else
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP,&buf) == -
literal|1
argument|) {
endif|#
directive|endif
comment|/* 		 * We really don't expect this to fail, but it is at least 		 * technically possible for this to fail with ENOENT.  In this 		 * case, we just drive on... 		 */
argument|if (errno == ENOENT) 			return (
literal|0
argument|);  		return (dt_set_errno(dtp, errno)); 	}  	if (!dtp->dt_stopped || buf->dtbd_cpu != dtp->dt_endedon) {
comment|/* 		 * This is the simple case.  We're either not stopped, or if 		 * we are, we actually processed any END probes on another 		 * CPU.  We can simply consume this buffer and return. 		 */
argument|return (dt_consume_cpu(dtp, fp, cpu, buf, pf, rf, arg)); 	}  	begin.dtbgn_probefunc = pf; 	begin.dtbgn_recfunc = rf; 	begin.dtbgn_arg = arg; 	begin.dtbgn_beginonly =
literal|1
argument|;
comment|/* 	 * We need to interpose on the ERROR handler to be sure that we 	 * only process ERRORs induced by BEGIN. 	 */
argument|begin.dtbgn_errhdlr = dtp->dt_errhdlr; 	begin.dtbgn_errarg = dtp->dt_errarg; 	dtp->dt_errhdlr = dt_consume_begin_error; 	dtp->dt_errarg =&begin;  	rval = dt_consume_cpu(dtp, fp, cpu, buf, dt_consume_begin_probe, 	    dt_consume_begin_record,&begin);  	dtp->dt_errhdlr = begin.dtbgn_errhdlr; 	dtp->dt_errarg = begin.dtbgn_errarg;  	if (rval !=
literal|0
argument|) 		return (rval);
comment|/* 	 * Now allocate a new buffer.  We'll use this to deal with every other 	 * CPU. 	 */
argument|bzero(&nbuf, sizeof (dtrace_bufdesc_t)); 	(void) dtrace_getopt(dtp,
literal|"bufsize"
argument|,&size); 	if ((nbuf.dtbd_data = malloc(size)) == NULL) 		return (dt_set_errno(dtp, EDT_NOMEM));  	if (max_ncpus ==
literal|0
argument|) 		max_ncpus = dt_sysconf(dtp, _SC_CPUID_MAX) +
literal|1
argument|;  	for (i =
literal|0
argument|; i< max_ncpus; i++) { 		nbuf.dtbd_cpu = i;  		if (i == cpu) 			continue;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP,&nbuf) == -
literal|1
argument|) {
else|#
directive|else
argument|pbuf =&nbuf; 		if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP,&pbuf) == -
literal|1
argument|) {
endif|#
directive|endif
comment|/* 			 * If we failed with ENOENT, it may be because the 			 * CPU was unconfigured -- this is okay.  Any other 			 * error, however, is unexpected. 			 */
argument|if (errno == ENOENT) 				continue;  			free(nbuf.dtbd_data);  			return (dt_set_errno(dtp, errno)); 		}  		if ((rval = dt_consume_cpu(dtp, fp, 		    i,&nbuf, pf, rf, arg)) !=
literal|0
argument|) { 			free(nbuf.dtbd_data); 			return (rval); 		} 	}  	free(nbuf.dtbd_data);
comment|/* 	 * Okay -- we're done with the other buffers.  Now we want to 	 * reconsume the first buffer -- but this time we're looking for 	 * everything _but_ BEGIN.  And of course, in order to only consume 	 * those ERRORs _not_ associated with BEGIN, we need to reinstall our 	 * ERROR interposition function... 	 */
argument|begin.dtbgn_beginonly =
literal|0
argument|;  	assert(begin.dtbgn_errhdlr == dtp->dt_errhdlr); 	assert(begin.dtbgn_errarg == dtp->dt_errarg); 	dtp->dt_errhdlr = dt_consume_begin_error; 	dtp->dt_errarg =&begin;  	rval = dt_consume_cpu(dtp, fp, cpu, buf, dt_consume_begin_probe, 	    dt_consume_begin_record,&begin);  	dtp->dt_errhdlr = begin.dtbgn_errhdlr; 	dtp->dt_errarg = begin.dtbgn_errarg;  	return (rval); }  int dtrace_consume(dtrace_hdl_t *dtp, FILE *fp,     dtrace_consume_probe_f *pf, dtrace_consume_rec_f *rf, void *arg) { 	dtrace_bufdesc_t *buf =&dtp->dt_buf; 	dtrace_optval_t size; 	static int max_ncpus; 	int i
argument_list|,
argument|rval; 	dtrace_optval_t interval = dtp->dt_options[DTRACEOPT_SWITCHRATE]; 	hrtime_t now = gethrtime();  	if (dtp->dt_lastswitch !=
literal|0
argument|) { 		if (now - dtp->dt_lastswitch< interval) 			return (
literal|0
argument|);  		dtp->dt_lastswitch += interval; 	} else { 		dtp->dt_lastswitch = now; 	}  	if (!dtp->dt_active) 		return (dt_set_errno(dtp, EINVAL));  	if (max_ncpus ==
literal|0
argument|) 		max_ncpus = dt_sysconf(dtp, _SC_CPUID_MAX) +
literal|1
argument|;  	if (pf == NULL) 		pf = (dtrace_consume_probe_f *)dt_nullprobe;  	if (rf == NULL) 		rf = (dtrace_consume_rec_f *)dt_nullrec;  	if (buf->dtbd_data == NULL) { 		(void) dtrace_getopt(dtp,
literal|"bufsize"
argument|,&size); 		if ((buf->dtbd_data = malloc(size)) == NULL) 			return (dt_set_errno(dtp, EDT_NOMEM));  		buf->dtbd_size = size; 	}
comment|/* 	 * If we have just begun, we want to first process the CPU that 	 * executed the BEGIN probe (if any). 	 */
argument|if (dtp->dt_active&& dtp->dt_beganon != -
literal|1
argument|) { 		buf->dtbd_cpu = dtp->dt_beganon; 		if ((rval = dt_consume_begin(dtp, fp, buf, pf, rf, arg)) !=
literal|0
argument|) 			return (rval); 	}  	for (i =
literal|0
argument|; i< max_ncpus; i++) { 		buf->dtbd_cpu = i;
comment|/* 		 * If we have stopped, we want to process the CPU on which the 		 * END probe was processed only _after_ we have processed 		 * everything else. 		 */
argument|if (dtp->dt_stopped&& (i == dtp->dt_endedon)) 			continue;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP, buf) == -
literal|1
argument|) {
else|#
directive|else
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP,&buf) == -
literal|1
argument|) {
endif|#
directive|endif
comment|/* 			 * If we failed with ENOENT, it may be because the 			 * CPU was unconfigured -- this is okay.  Any other 			 * error, however, is unexpected. 			 */
argument|if (errno == ENOENT) 				continue;  			return (dt_set_errno(dtp, errno)); 		}  		if ((rval = dt_consume_cpu(dtp, fp, i, buf, pf, rf, arg)) !=
literal|0
argument|) 			return (rval); 	}  	if (!dtp->dt_stopped) 		return (
literal|0
argument|);  	buf->dtbd_cpu = dtp->dt_endedon;
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP, buf) == -
literal|1
argument|) {
else|#
directive|else
argument|if (dt_ioctl(dtp, DTRACEIOC_BUFSNAP,&buf) == -
literal|1
argument|) {
endif|#
directive|endif
comment|/* 		 * This _really_ shouldn't fail, but it is strictly speaking 		 * possible for this to return ENOENT if the CPU that called 		 * the END enabling somehow managed to become unconfigured. 		 * It's unclear how the user can possibly expect anything 		 * rational to happen in this case -- the state has been thrown 		 * out along with the unconfigured CPU -- so we'll just drive 		 * on... 		 */
argument|if (errno == ENOENT) 			return (
literal|0
argument|);  		return (dt_set_errno(dtp, errno)); 	}  	return (dt_consume_cpu(dtp, fp, dtp->dt_endedon, buf, pf, rf, arg)); }
end_function

end_unit

