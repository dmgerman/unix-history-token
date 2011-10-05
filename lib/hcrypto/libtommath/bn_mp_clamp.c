begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_CLAMP_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* trim unused digits  *  * This is used to ensure that leading zero digits are  * trimed and the leading "used" digit will be non-zero  * Typically very fast.  Also fixes the sign if there  * are no more leading digits  */
end_comment

begin_function
name|void
name|mp_clamp
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
comment|/* decrease used while the most significant digit is    * zero.    */
while|while
condition|(
name|a
operator|->
name|used
operator|>
literal|0
operator|&&
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
operator|==
literal|0
condition|)
block|{
operator|--
operator|(
name|a
operator|->
name|used
operator|)
expr_stmt|;
block|}
comment|/* reset the sign flag if used == 0 */
if|if
condition|(
name|a
operator|->
name|used
operator|==
literal|0
condition|)
block|{
name|a
operator|->
name|sign
operator|=
name|MP_ZPOS
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_clamp.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

