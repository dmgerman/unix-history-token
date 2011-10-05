begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_LSHD_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* shift left a certain amount of digits */
end_comment

begin_function
name|int
name|mp_lshd
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|int
name|x
decl_stmt|,
name|res
decl_stmt|;
comment|/* if its less than zero return */
if|if
condition|(
name|b
operator|<=
literal|0
condition|)
block|{
return|return
name|MP_OKAY
return|;
block|}
comment|/* grow to fit the new digits */
if|if
condition|(
name|a
operator|->
name|alloc
operator|<
name|a
operator|->
name|used
operator|+
name|b
condition|)
block|{
if|if
condition|(
operator|(
name|res
operator|=
name|mp_grow
argument_list|(
name|a
argument_list|,
name|a
operator|->
name|used
operator|+
name|b
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
block|{
specifier|register
name|mp_digit
modifier|*
name|top
decl_stmt|,
modifier|*
name|bottom
decl_stmt|;
comment|/* increment the used by the shift amount then copy upwards */
name|a
operator|->
name|used
operator|+=
name|b
expr_stmt|;
comment|/* top */
name|top
operator|=
name|a
operator|->
name|dp
operator|+
name|a
operator|->
name|used
operator|-
literal|1
expr_stmt|;
comment|/* base */
name|bottom
operator|=
name|a
operator|->
name|dp
operator|+
name|a
operator|->
name|used
operator|-
literal|1
operator|-
name|b
expr_stmt|;
comment|/* much like mp_rshd this is implemented using a sliding window      * except the window goes the otherway around.  Copying from      * the bottom to the top.  see bn_mp_rshd.c for more info.      */
for|for
control|(
name|x
operator|=
name|a
operator|->
name|used
operator|-
literal|1
init|;
name|x
operator|>=
name|b
condition|;
name|x
operator|--
control|)
block|{
operator|*
name|top
operator|--
operator|=
operator|*
name|bottom
operator|--
expr_stmt|;
block|}
comment|/* zero the lower digits */
name|top
operator|=
name|a
operator|->
name|dp
expr_stmt|;
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
name|b
condition|;
name|x
operator|++
control|)
block|{
operator|*
name|top
operator|++
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_lshd.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

