begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_GROW_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* grow as required */
end_comment

begin_function
name|int
name|mp_grow
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
name|mp_digit
modifier|*
name|tmp
decl_stmt|;
comment|/* if the alloc size is smaller alloc more ram */
if|if
condition|(
name|a
operator|->
name|alloc
operator|<
name|size
condition|)
block|{
comment|/* ensure there are always at least MP_PREC digits extra on top */
name|size
operator|+=
operator|(
name|MP_PREC
operator|*
literal|2
operator|)
operator|-
operator|(
name|size
operator|%
name|MP_PREC
operator|)
expr_stmt|;
comment|/* reallocate the array a->dp      *      * We store the return in a temporary variable      * in case the operation failed we don't want      * to overwrite the dp member of a.      */
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
name|size
argument_list|)
expr_stmt|;
if|if
condition|(
name|tmp
operator|==
name|NULL
condition|)
block|{
comment|/* reallocation failed but "a" is still valid [can be freed] */
return|return
name|MP_MEM
return|;
block|}
comment|/* reallocation succeeded so set a->dp */
name|a
operator|->
name|dp
operator|=
name|tmp
expr_stmt|;
comment|/* zero excess digits */
name|i
operator|=
name|a
operator|->
name|alloc
expr_stmt|;
name|a
operator|->
name|alloc
operator|=
name|size
expr_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|a
operator|->
name|alloc
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_grow.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

