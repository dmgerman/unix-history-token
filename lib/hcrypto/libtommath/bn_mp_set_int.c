begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_SET_INT_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* set a 32-bit const */
end_comment

begin_function
name|int
name|mp_set_int
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|unsigned
name|long
name|b
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|res
decl_stmt|;
name|mp_zero
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|/* set four bits at a time */
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
literal|8
condition|;
name|x
operator|++
control|)
block|{
comment|/* shift the number up four bits */
if|if
condition|(
operator|(
name|res
operator|=
name|mp_mul_2d
argument_list|(
name|a
argument_list|,
literal|4
argument_list|,
name|a
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
comment|/* OR in the top four bits of the source */
name|a
operator|->
name|dp
index|[
literal|0
index|]
operator||=
operator|(
name|b
operator|>>
literal|28
operator|)
operator|&
literal|15
expr_stmt|;
comment|/* shift the source up to the next four bits */
name|b
operator|<<=
literal|4
expr_stmt|;
comment|/* ensure that digits are not clamped off */
name|a
operator|->
name|used
operator|+=
literal|1
expr_stmt|;
block|}
name|mp_clamp
argument_list|(
name|a
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_set_int.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

