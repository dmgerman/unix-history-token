begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_GET_INT_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* get the lower 32-bits of an mp_int */
end_comment

begin_function
name|unsigned
name|long
name|mp_get_int
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|unsigned
name|long
name|res
decl_stmt|;
if|if
condition|(
name|a
operator|->
name|used
operator|==
literal|0
condition|)
block|{
return|return
literal|0
return|;
block|}
comment|/* get number of digits of the lsb we have to read */
name|i
operator|=
name|MIN
argument_list|(
name|a
operator|->
name|used
argument_list|,
call|(
name|int
call|)
argument_list|(
operator|(
expr|sizeof
operator|(
name|unsigned
name|long
operator|)
operator|*
name|CHAR_BIT
operator|+
name|DIGIT_BIT
operator|-
literal|1
operator|)
operator|/
name|DIGIT_BIT
argument_list|)
argument_list|)
operator|-
literal|1
expr_stmt|;
comment|/* get most significant digit of result */
name|res
operator|=
name|DIGIT
argument_list|(
name|a
argument_list|,
name|i
argument_list|)
expr_stmt|;
while|while
condition|(
operator|--
name|i
operator|>=
literal|0
condition|)
block|{
name|res
operator|=
operator|(
name|res
operator|<<
name|DIGIT_BIT
operator|)
operator||
name|DIGIT
argument_list|(
name|a
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
comment|/* force result to 32-bits always so it is consistent on non 32-bit platforms */
return|return
name|res
operator|&
literal|0xFFFFFFFFUL
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_get_int.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

