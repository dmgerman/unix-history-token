begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_REDUCE_IS_2K_L_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* determines if reduce_2k_l can be used */
end_comment

begin_function
name|int
name|mp_reduce_is_2k_l
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|ix
decl_stmt|,
name|iy
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
name|MP_NO
return|;
block|}
elseif|else
if|if
condition|(
name|a
operator|->
name|used
operator|==
literal|1
condition|)
block|{
return|return
name|MP_YES
return|;
block|}
elseif|else
if|if
condition|(
name|a
operator|->
name|used
operator|>
literal|1
condition|)
block|{
comment|/* if more than half of the digits are -1 we're sold */
for|for
control|(
name|iy
operator|=
name|ix
operator|=
literal|0
init|;
name|ix
operator|<
name|a
operator|->
name|used
condition|;
name|ix
operator|++
control|)
block|{
if|if
condition|(
name|a
operator|->
name|dp
index|[
name|ix
index|]
operator|==
name|MP_MASK
condition|)
block|{
operator|++
name|iy
expr_stmt|;
block|}
block|}
return|return
operator|(
name|iy
operator|>=
operator|(
name|a
operator|->
name|used
operator|/
literal|2
operator|)
operator|)
condition|?
name|MP_YES
else|:
name|MP_NO
return|;
block|}
return|return
name|MP_NO
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_reduce_is_2k_l.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

