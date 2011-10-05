begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_SET_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* set to a digit */
end_comment

begin_function
name|void
name|mp_set
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_digit
name|b
parameter_list|)
block|{
name|mp_zero
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|a
operator|->
name|dp
index|[
literal|0
index|]
operator|=
name|b
operator|&
name|MP_MASK
expr_stmt|;
name|a
operator|->
name|used
operator|=
operator|(
name|a
operator|->
name|dp
index|[
literal|0
index|]
operator|!=
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_set.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

