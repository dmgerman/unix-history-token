begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_CMP_MAG_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* compare maginitude of two ints (unsigned) */
end_comment

begin_function
name|int
name|mp_cmp_mag
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|b
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
name|mp_digit
modifier|*
name|tmpa
decl_stmt|,
modifier|*
name|tmpb
decl_stmt|;
comment|/* compare based on # of non-zero digits */
if|if
condition|(
name|a
operator|->
name|used
operator|>
name|b
operator|->
name|used
condition|)
block|{
return|return
name|MP_GT
return|;
block|}
if|if
condition|(
name|a
operator|->
name|used
operator|<
name|b
operator|->
name|used
condition|)
block|{
return|return
name|MP_LT
return|;
block|}
comment|/* alias for a */
name|tmpa
operator|=
name|a
operator|->
name|dp
operator|+
operator|(
name|a
operator|->
name|used
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* alias for b */
name|tmpb
operator|=
name|b
operator|->
name|dp
operator|+
operator|(
name|a
operator|->
name|used
operator|-
literal|1
operator|)
expr_stmt|;
comment|/* compare based on digits  */
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|a
operator|->
name|used
condition|;
operator|++
name|n
operator|,
operator|--
name|tmpa
operator|,
operator|--
name|tmpb
control|)
block|{
if|if
condition|(
operator|*
name|tmpa
operator|>
operator|*
name|tmpb
condition|)
block|{
return|return
name|MP_GT
return|;
block|}
if|if
condition|(
operator|*
name|tmpa
operator|<
operator|*
name|tmpb
condition|)
block|{
return|return
name|MP_LT
return|;
block|}
block|}
return|return
name|MP_EQ
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_cmp_mag.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

