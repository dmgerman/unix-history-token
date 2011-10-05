begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_COPY_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* copy, b = a */
end_comment

begin_function
name|int
name|mp_copy
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|b
parameter_list|)
block|{
name|int
name|res
decl_stmt|,
name|n
decl_stmt|;
comment|/* if dst == src do nothing */
if|if
condition|(
name|a
operator|==
name|b
condition|)
block|{
return|return
name|MP_OKAY
return|;
block|}
comment|/* grow dest */
if|if
condition|(
name|b
operator|->
name|alloc
operator|<
name|a
operator|->
name|used
condition|)
block|{
if|if
condition|(
operator|(
name|res
operator|=
name|mp_grow
argument_list|(
name|b
argument_list|,
name|a
operator|->
name|used
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
return|return
name|res
return|;
block|}
block|}
comment|/* zero b and copy the parameters over */
block|{
specifier|register
name|mp_digit
modifier|*
name|tmpa
decl_stmt|,
modifier|*
name|tmpb
decl_stmt|;
comment|/* pointer aliases */
comment|/* source */
name|tmpa
operator|=
name|a
operator|->
name|dp
expr_stmt|;
comment|/* destination */
name|tmpb
operator|=
name|b
operator|->
name|dp
expr_stmt|;
comment|/* copy all the digits */
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
name|used
condition|;
name|n
operator|++
control|)
block|{
operator|*
name|tmpb
operator|++
operator|=
operator|*
name|tmpa
operator|++
expr_stmt|;
block|}
comment|/* clear high digits */
for|for
control|(
init|;
name|n
operator|<
name|b
operator|->
name|used
condition|;
name|n
operator|++
control|)
block|{
operator|*
name|tmpb
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/* copy used count and sign */
name|b
operator|->
name|used
operator|=
name|a
operator|->
name|used
expr_stmt|;
name|b
operator|->
name|sign
operator|=
name|a
operator|->
name|sign
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_copy.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

