begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_SUB_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* high level subtraction (handles signs) */
end_comment

begin_function
name|int
name|mp_sub
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
name|int
name|sa
decl_stmt|,
name|sb
decl_stmt|,
name|res
decl_stmt|;
name|sa
operator|=
name|a
operator|->
name|sign
expr_stmt|;
name|sb
operator|=
name|b
operator|->
name|sign
expr_stmt|;
if|if
condition|(
name|sa
operator|!=
name|sb
condition|)
block|{
comment|/* subtract a negative from a positive, OR */
comment|/* subtract a positive from a negative. */
comment|/* In either case, ADD their magnitudes, */
comment|/* and use the sign of the first number. */
name|c
operator|->
name|sign
operator|=
name|sa
expr_stmt|;
name|res
operator|=
name|s_mp_add
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* subtract a positive from a positive, OR */
comment|/* subtract a negative from a negative. */
comment|/* First, take the difference between their */
comment|/* magnitudes, then... */
if|if
condition|(
name|mp_cmp_mag
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
operator|!=
name|MP_LT
condition|)
block|{
comment|/* Copy the sign from the first */
name|c
operator|->
name|sign
operator|=
name|sa
expr_stmt|;
comment|/* The first has a larger or equal magnitude */
name|res
operator|=
name|s_mp_sub
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* The result has the *opposite* sign from */
comment|/* the first number. */
name|c
operator|->
name|sign
operator|=
operator|(
name|sa
operator|==
name|MP_ZPOS
operator|)
condition|?
name|MP_NEG
else|:
name|MP_ZPOS
expr_stmt|;
comment|/* The second has a larger magnitude */
name|res
operator|=
name|s_mp_sub
argument_list|(
name|b
argument_list|,
name|a
argument_list|,
name|c
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|res
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_sub.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

