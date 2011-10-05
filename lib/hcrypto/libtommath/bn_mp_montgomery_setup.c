begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_MONTGOMERY_SETUP_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* setups the montgomery reduction stuff */
end_comment

begin_function
name|int
name|mp_montgomery_setup
parameter_list|(
name|mp_int
modifier|*
name|n
parameter_list|,
name|mp_digit
modifier|*
name|rho
parameter_list|)
block|{
name|mp_digit
name|x
decl_stmt|,
name|b
decl_stmt|;
comment|/* fast inversion mod 2**k  *  * Based on the fact that  *  * XA = 1 (mod 2**n)  =>  (X(2-XA)) A = 1 (mod 2**2n)  *                    =>  2*X*A - X*X*A*A = 1  *                    =>  2*(1) - (1)     = 1  */
name|b
operator|=
name|n
operator|->
name|dp
index|[
literal|0
index|]
expr_stmt|;
if|if
condition|(
operator|(
name|b
operator|&
literal|1
operator|)
operator|==
literal|0
condition|)
block|{
return|return
name|MP_VAL
return|;
block|}
name|x
operator|=
operator|(
operator|(
operator|(
name|b
operator|+
literal|2
operator|)
operator|&
literal|4
operator|)
operator|<<
literal|1
operator|)
operator|+
name|b
expr_stmt|;
comment|/* here x*a==1 mod 2**4 */
name|x
operator|*=
literal|2
operator|-
name|b
operator|*
name|x
expr_stmt|;
comment|/* here x*a==1 mod 2**8 */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MP_8BIT
argument_list|)
name|x
operator|*=
literal|2
operator|-
name|b
operator|*
name|x
expr_stmt|;
comment|/* here x*a==1 mod 2**16 */
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|MP_64BIT
argument_list|)
operator|||
operator|!
operator|(
name|defined
argument_list|(
name|MP_8BIT
argument_list|)
operator|||
name|defined
argument_list|(
name|MP_16BIT
argument_list|)
operator|)
name|x
operator|*=
literal|2
operator|-
name|b
operator|*
name|x
expr_stmt|;
comment|/* here x*a==1 mod 2**32 */
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MP_64BIT
name|x
operator|*=
literal|2
operator|-
name|b
operator|*
name|x
expr_stmt|;
comment|/* here x*a==1 mod 2**64 */
endif|#
directive|endif
comment|/* rho = -1/m mod b */
operator|*
name|rho
operator|=
call|(
name|unsigned
name|long
call|)
argument_list|(
operator|(
operator|(
name|mp_word
operator|)
literal|1
operator|<<
operator|(
operator|(
name|mp_word
operator|)
name|DIGIT_BIT
operator|)
operator|)
operator|-
name|x
argument_list|)
operator|&
name|MP_MASK
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_montgomery_setup.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.5 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

