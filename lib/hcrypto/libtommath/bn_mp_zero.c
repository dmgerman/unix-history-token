begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_ZERO_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* set to zero */
end_comment

begin_function
name|void
name|mp_zero
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|n
decl_stmt|;
name|mp_digit
modifier|*
name|tmp
decl_stmt|;
name|a
operator|->
name|sign
operator|=
name|MP_ZPOS
expr_stmt|;
name|a
operator|->
name|used
operator|=
literal|0
expr_stmt|;
name|tmp
operator|=
name|a
operator|->
name|dp
expr_stmt|;
for|for
control|(
name|n
operator|=
literal|0
init|;
name|n
operator|<
name|a
operator|->
name|alloc
condition|;
name|n
operator|++
control|)
block|{
operator|*
name|tmp
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_zero.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

