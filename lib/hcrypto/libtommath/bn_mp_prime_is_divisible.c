begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_PRIME_IS_DIVISIBLE_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* determines if an integers is divisible by one  * of the first PRIME_SIZE primes or not  *  * sets result to 0 if not, 1 if yes  */
end_comment

begin_function
name|int
name|mp_prime_is_divisible
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|result
parameter_list|)
block|{
name|int
name|err
decl_stmt|,
name|ix
decl_stmt|;
name|mp_digit
name|res
decl_stmt|;
comment|/* default to not */
operator|*
name|result
operator|=
name|MP_NO
expr_stmt|;
for|for
control|(
name|ix
operator|=
literal|0
init|;
name|ix
operator|<
name|PRIME_SIZE
condition|;
name|ix
operator|++
control|)
block|{
comment|/* what is a mod LBL_prime_tab[ix] */
if|if
condition|(
operator|(
name|err
operator|=
name|mp_mod_d
argument_list|(
name|a
argument_list|,
name|ltm_prime_tab
index|[
name|ix
index|]
argument_list|,
operator|&
name|res
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
comment|/* is the residue zero? */
if|if
condition|(
name|res
operator|==
literal|0
condition|)
block|{
operator|*
name|result
operator|=
name|MP_YES
expr_stmt|;
return|return
name|MP_OKAY
return|;
block|}
block|}
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_prime_is_divisible.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

