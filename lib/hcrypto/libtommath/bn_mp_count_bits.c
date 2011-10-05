begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_COUNT_BITS_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* returns the number of bits in an int */
end_comment

begin_function
name|int
name|mp_count_bits
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|r
decl_stmt|;
name|mp_digit
name|q
decl_stmt|;
comment|/* shortcut */
if|if
condition|(
name|a
operator|->
name|used
operator|==
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|/* get number of digits and add that */
name|r
operator|=
operator|(
name|a
operator|->
name|used
operator|-
literal|1
operator|)
operator|*
name|DIGIT_BIT
expr_stmt|;
comment|/* take the last digit and count the bits in it */
name|q
operator|=
name|a
operator|->
name|dp
index|[
name|a
operator|->
name|used
operator|-
literal|1
index|]
expr_stmt|;
while|while
condition|(
name|q
operator|>
operator|(
operator|(
name|mp_digit
operator|)
literal|0
operator|)
condition|)
block|{
operator|++
name|r
expr_stmt|;
name|q
operator|>>=
operator|(
operator|(
name|mp_digit
operator|)
literal|1
operator|)
expr_stmt|;
block|}
return|return
name|r
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_count_bits.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

