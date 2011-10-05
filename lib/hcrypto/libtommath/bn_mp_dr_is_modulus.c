begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_DR_IS_MODULUS_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* determines if a number is a valid DR modulus */
end_comment

begin_function
name|int
name|mp_dr_is_modulus
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|ix
decl_stmt|;
comment|/* must be at least two digits */
if|if
condition|(
name|a
operator|->
name|used
operator|<
literal|2
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|/* must be of the form b**k - a [a<= b] so all     * but the first digit must be equal to -1 (mod b).     */
for|for
control|(
name|ix
operator|=
literal|1
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
if|if
condition|(
name|a
operator|->
name|dp
index|[
name|ix
index|]
operator|!=
name|MP_MASK
condition|)
block|{
return|return
literal|0
return|;
block|}
block|}
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_dr_is_modulus.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

