begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_atomic.h  * Atomic operations used in the DRM which may or may not be provided by the OS.  *   * \author Eric Anholt<anholt@FreeBSD.org>  */
end_comment

begin_comment
comment|/*-  * Copyright 2004 Eric Anholt  * Copyright 2013 Jung-uk Kim<jkim@FreeBSD.org>  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
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

begin_typedef
typedef|typedef
name|u_int
name|atomic_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|atomic64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BITS_PER_LONG
value|(sizeof(long) * NBBY)
end_define

begin_define
define|#
directive|define
name|BITS_TO_LONGS
parameter_list|(
name|x
parameter_list|)
value|howmany(x, BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(volatile u_int *)(p))
end_define

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|do { *(u_int *)(p) = (v); } while (0)
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|atomic_add_int(p, v)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|atomic_subtract_int(p, v)
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|atomic_add(1, p)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_sub(1, p)
end_define

begin_define
define|#
directive|define
name|atomic_add_return
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(atomic_fetchadd_int(p, v) + (v))
end_define

begin_define
define|#
directive|define
name|atomic_sub_return
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(atomic_fetchadd_int(p, -(v)) - (v))
end_define

begin_define
define|#
directive|define
name|atomic_inc_return
parameter_list|(
name|p
parameter_list|)
value|atomic_add_return(1, p)
end_define

begin_define
define|#
directive|define
name|atomic_dec_return
parameter_list|(
name|p
parameter_list|)
value|atomic_sub_return(1, p)
end_define

begin_define
define|#
directive|define
name|atomic_add_and_test
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(atomic_add_return(v, p) == 0)
end_define

begin_define
define|#
directive|define
name|atomic_sub_and_test
parameter_list|(
name|v
parameter_list|,
name|p
parameter_list|)
value|(atomic_sub_return(v, p) == 0)
end_define

begin_define
define|#
directive|define
name|atomic_inc_and_test
parameter_list|(
name|p
parameter_list|)
value|(atomic_inc_return(p) == 0)
end_define

begin_define
define|#
directive|define
name|atomic_dec_and_test
parameter_list|(
name|p
parameter_list|)
value|(atomic_dec_return(p) == 0)
end_define

begin_define
define|#
directive|define
name|atomic_xchg
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|atomic_swap_int(p, v)
end_define

begin_define
define|#
directive|define
name|atomic64_xchg
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|atomic_swap_64(p, v)
end_define

begin_define
define|#
directive|define
name|__bit_word
parameter_list|(
name|b
parameter_list|)
value|((b) / BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|__bit_mask
parameter_list|(
name|b
parameter_list|)
value|(1UL<< (b) % BITS_PER_LONG)
end_define

begin_define
define|#
directive|define
name|__bit_addr
parameter_list|(
name|p
parameter_list|,
name|b
parameter_list|)
value|((volatile u_long *)(p) + __bit_word(b))
end_define

begin_define
define|#
directive|define
name|clear_bit
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_clear_long(__bit_addr(p, b), __bit_mask(b))
end_define

begin_define
define|#
directive|define
name|set_bit
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
define|\
value|atomic_set_long(__bit_addr(p, b), __bit_mask(b))
end_define

begin_define
define|#
directive|define
name|test_bit
parameter_list|(
name|b
parameter_list|,
name|p
parameter_list|)
define|\
value|((atomic_read(__bit_addr(p, b))& __bit_mask(b)) != 0)
end_define

begin_function
specifier|static
name|__inline
name|u_long
name|find_first_zero_bit
parameter_list|(
specifier|const
name|u_long
modifier|*
name|p
parameter_list|,
name|u_long
name|max
parameter_list|)
block|{
name|u_long
name|i
decl_stmt|,
name|n
decl_stmt|;
name|KASSERT
argument_list|(
name|max
operator|%
name|BITS_PER_LONG
operator|==
literal|0
argument_list|,
operator|(
literal|"invalid bitmap size %lu"
operator|,
name|max
operator|)
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|max
operator|/
name|BITS_PER_LONG
condition|;
name|i
operator|++
control|)
block|{
name|n
operator|=
operator|~
name|p
index|[
name|i
index|]
expr_stmt|;
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
return|return
operator|(
name|i
operator|*
name|BITS_PER_LONG
operator|+
name|ffsl
argument_list|(
name|n
argument_list|)
operator|-
literal|1
operator|)
return|;
block|}
return|return
operator|(
name|max
operator|)
return|;
block|}
end_function

end_unit

