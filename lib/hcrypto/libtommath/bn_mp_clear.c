begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_CLEAR_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* clear one (frees)  */
end_comment

begin_function
name|void
name|mp_clear
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
comment|/* only do anything if a hasn't been freed previously */
if|if
condition|(
name|a
operator|->
name|dp
operator|!=
name|NULL
condition|)
block|{
comment|/* first zero the digits */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|a
operator|->
name|used
condition|;
name|i
operator|++
control|)
block|{
name|a
operator|->
name|dp
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
block|}
comment|/* free ram */
name|XFREE
argument_list|(
name|a
operator|->
name|dp
argument_list|)
expr_stmt|;
comment|/* reset members to make debugging easier */
name|a
operator|->
name|dp
operator|=
name|NULL
expr_stmt|;
name|a
operator|->
name|alloc
operator|=
name|a
operator|->
name|used
operator|=
literal|0
expr_stmt|;
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_clear.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

