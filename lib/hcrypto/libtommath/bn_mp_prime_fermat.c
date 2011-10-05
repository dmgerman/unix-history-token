begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_PRIME_FERMAT_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* performs one Fermat test.  *  * If "a" were prime then b**a == b (mod a) since the order of  * the multiplicative sub-group would be phi(a) = a-1.  That means  * it would be the same as b**(a mod (a-1)) == b**1 == b (mod a).  *  * Sets result to 1 if the congruence holds, or zero otherwise.  */
end_comment

begin_function
name|int
name|mp_prime_fermat
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|b
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
block|{
name|mp_int
name|t
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* default to composite  */
operator|*
name|result
operator|=
name|MP_NO
expr_stmt|;
comment|/* ensure b> 1 */
if|if
condition|(
name|mp_cmp_d
argument_list|(
name|b
argument_list|,
literal|1
argument_list|)
operator|!=
name|MP_GT
condition|)
block|{
return|return
name|MP_VAL
return|;
block|}
comment|/* init t */
if|if
condition|(
operator|(
name|err
operator|=
name|mp_init
argument_list|(
operator|&
name|t
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
return|return
name|err
return|;
block|}
comment|/* compute t = b**a mod a */
if|if
condition|(
operator|(
name|err
operator|=
name|mp_exptmod
argument_list|(
name|b
argument_list|,
name|a
argument_list|,
name|a
argument_list|,
operator|&
name|t
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
goto|goto
name|LBL_T
goto|;
block|}
comment|/* is it equal to b? */
if|if
condition|(
name|mp_cmp
argument_list|(
operator|&
name|t
argument_list|,
name|b
argument_list|)
operator|==
name|MP_EQ
condition|)
block|{
operator|*
name|result
operator|=
name|MP_YES
expr_stmt|;
block|}
name|err
operator|=
name|MP_OKAY
expr_stmt|;
name|LBL_T
label|:
name|mp_clear
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
name|err
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_prime_fermat.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

