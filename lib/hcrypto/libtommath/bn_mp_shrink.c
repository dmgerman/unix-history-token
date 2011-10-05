begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_SHRINK_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* shrink a bignum */
end_comment

begin_function
name|int
name|mp_shrink
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|mp_digit
modifier|*
name|tmp
decl_stmt|;
if|if
condition|(
name|a
operator|->
name|alloc
operator|!=
name|a
operator|->
name|used
operator|&&
name|a
operator|->
name|used
operator|>
literal|0
condition|)
block|{
if|if
condition|(
operator|(
name|tmp
operator|=
name|OPT_CAST
argument_list|(
argument|mp_digit
argument_list|)
name|XREALLOC
argument_list|(
name|a
operator|->
name|dp
argument_list|,
sizeof|sizeof
argument_list|(
name|mp_digit
argument_list|)
operator|*
name|a
operator|->
name|used
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
return|return
name|MP_MEM
return|;
block|}
name|a
operator|->
name|dp
operator|=
name|tmp
expr_stmt|;
name|a
operator|->
name|alloc
operator|=
name|a
operator|->
name|used
expr_stmt|;
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_shrink.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

