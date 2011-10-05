begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_INVMOD_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* hac 14.61, pp608 */
end_comment

begin_function
name|int
name|mp_invmod
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|b
parameter_list|,
name|mp_int
modifier|*
name|c
parameter_list|)
block|{
comment|/* b cannot be negative */
if|if
condition|(
name|b
operator|->
name|sign
operator|==
name|MP_NEG
operator|||
name|mp_iszero
argument_list|(
name|b
argument_list|)
operator|==
literal|1
condition|)
block|{
return|return
name|MP_VAL
return|;
block|}
ifdef|#
directive|ifdef
name|BN_FAST_MP_INVMOD_C
comment|/* if the modulus is odd we can use a faster routine instead */
if|if
condition|(
name|mp_isodd
argument_list|(
name|b
argument_list|)
operator|==
literal|1
condition|)
block|{
return|return
name|fast_mp_invmod
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
endif|#
directive|endif
ifdef|#
directive|ifdef
name|BN_MP_INVMOD_SLOW_C
return|return
name|mp_invmod_slow
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
else|#
directive|else
return|return
name|MP_VAL
return|;
endif|#
directive|endif
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_invmod.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

