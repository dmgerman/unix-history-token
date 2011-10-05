begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_DR_SETUP_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* determines the setup value */
end_comment

begin_function
name|void
name|mp_dr_setup
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_digit
modifier|*
name|d
parameter_list|)
block|{
comment|/* the casts are required if DIGIT_BIT is one less than     * the number of bits in a mp_digit [e.g. DIGIT_BIT==31]     */
operator|*
name|d
operator|=
call|(
name|mp_digit
call|)
argument_list|(
operator|(
operator|(
operator|(
name|mp_word
operator|)
literal|1
operator|)
operator|<<
operator|(
operator|(
name|mp_word
operator|)
name|DIGIT_BIT
operator|)
operator|)
operator|-
operator|(
operator|(
name|mp_word
operator|)
name|a
operator|->
name|dp
index|[
literal|0
index|]
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_dr_setup.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

