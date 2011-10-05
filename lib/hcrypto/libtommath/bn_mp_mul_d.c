begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_MUL_D_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* multiply by a digit */
end_comment

begin_function
name|int
name|mp_mul_d
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_digit
name|b
parameter_list|,
name|mp_int
modifier|*
name|c
parameter_list|)
block|{
name|mp_digit
name|u
decl_stmt|,
modifier|*
name|tmpa
decl_stmt|,
modifier|*
name|tmpc
decl_stmt|;
name|mp_word
name|r
decl_stmt|;
name|int
name|ix
decl_stmt|,
name|res
decl_stmt|,
name|olduse
decl_stmt|;
comment|/* make sure c is big enough to hold a*b */
if|if
condition|(
name|c
operator|->
name|alloc
operator|<
name|a
operator|->
name|used
operator|+
literal|1
condition|)
block|{
if|if
condition|(
operator|(
name|res
operator|=
name|mp_grow
argument_list|(
name|c
argument_list|,
name|a
operator|->
name|used
operator|+
literal|1
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
return|return
name|res
return|;
block|}
block|}
comment|/* get the original destinations used count */
name|olduse
operator|=
name|c
operator|->
name|used
expr_stmt|;
comment|/* set the sign */
name|c
operator|->
name|sign
operator|=
name|a
operator|->
name|sign
expr_stmt|;
comment|/* alias for a->dp [source] */
name|tmpa
operator|=
name|a
operator|->
name|dp
expr_stmt|;
comment|/* alias for c->dp [dest] */
name|tmpc
operator|=
name|c
operator|->
name|dp
expr_stmt|;
comment|/* zero carry */
name|u
operator|=
literal|0
expr_stmt|;
comment|/* compute columns */
for|for
control|(
name|ix
operator|=
literal|0
init|;
name|ix
operator|<
name|a
operator|->
name|used
condition|;
name|ix
operator|++
control|)
block|{
comment|/* compute product and carry sum for this term */
name|r
operator|=
operator|(
operator|(
name|mp_word
operator|)
name|u
operator|)
operator|+
operator|(
operator|(
name|mp_word
operator|)
operator|*
name|tmpa
operator|++
operator|)
operator|*
operator|(
operator|(
name|mp_word
operator|)
name|b
operator|)
expr_stmt|;
comment|/* mask off higher bits to get a single digit */
operator|*
name|tmpc
operator|++
operator|=
call|(
name|mp_digit
call|)
argument_list|(
name|r
operator|&
operator|(
operator|(
name|mp_word
operator|)
name|MP_MASK
operator|)
argument_list|)
expr_stmt|;
comment|/* send carry into next iteration */
name|u
operator|=
call|(
name|mp_digit
call|)
argument_list|(
name|r
operator|>>
operator|(
operator|(
name|mp_word
operator|)
name|DIGIT_BIT
operator|)
argument_list|)
expr_stmt|;
block|}
comment|/* store final carry [if any] and increment ix offset  */
operator|*
name|tmpc
operator|++
operator|=
name|u
expr_stmt|;
operator|++
name|ix
expr_stmt|;
comment|/* now zero digits above the top */
while|while
condition|(
name|ix
operator|++
operator|<
name|olduse
condition|)
block|{
operator|*
name|tmpc
operator|++
operator|=
literal|0
expr_stmt|;
block|}
comment|/* set used count */
name|c
operator|->
name|used
operator|=
name|a
operator|->
name|used
operator|+
literal|1
expr_stmt|;
name|mp_clamp
argument_list|(
name|c
argument_list|)
expr_stmt|;
return|return
name|MP_OKAY
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_mul_d.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

