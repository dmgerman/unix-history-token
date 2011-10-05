begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_2EXPT_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* computes a = 2**b  *  * Simple algorithm which zeroes the int, grows it then just sets one bit  * as required.  */
end_comment

begin_function
name|int
name|mp_2expt
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
comment|/* zero a as per default */
name|mp_zero
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* grow a to accomodate the single bit */
if|if
condition|(
operator|(
name|res
operator|=
name|mp_grow
argument_list|(
name|a
argument_list|,
name|b
operator|/
name|DIGIT_BIT
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
comment|/* set the used count of where the bit will go */
name|a
operator|->
name|used
operator|=
name|b
operator|/
name|DIGIT_BIT
operator|+
literal|1
expr_stmt|;
comment|/* put the single bit in its place */
name|a
operator|->
name|dp
index|[
name|b
operator|/
name|DIGIT_BIT
index|]
operator|=
operator|(
operator|(
name|mp_digit
operator|)
literal|1
operator|)
operator|<<
operator|(
name|b
operator|%
name|DIGIT_BIT
operator|)
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_2expt.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

