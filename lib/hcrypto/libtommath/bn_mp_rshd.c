begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_RSHD_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* shift right a certain amount of digits */
end_comment

begin_function
name|void
name|mp_rshd
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
decl_stmt|;
comment|/* if b<= 0 then ignore it */
if|if
condition|(
name|b
operator|<=
literal|0
condition|)
block|{
return|return;
block|}
comment|/* if b> used then simply zero it and return */
if|if
condition|(
name|a
operator|->
name|used
operator|<=
name|b
condition|)
block|{
name|mp_zero
argument_list|(
name|a
argument_list|)
expr_stmt|;
return|return;
block|}
block|{
specifier|register
name|mp_digit
modifier|*
name|bottom
decl_stmt|,
modifier|*
name|top
decl_stmt|;
comment|/* shift the digits down */
comment|/* bottom */
name|bottom
operator|=
name|a
operator|->
name|dp
expr_stmt|;
comment|/* top [offset into digits] */
name|top
operator|=
name|a
operator|->
name|dp
operator|+
name|b
expr_stmt|;
comment|/* this is implemented as a sliding window where      * the window is b-digits long and digits from      * the top of the window are copied to the bottom      *      * e.g.       b-2 | b-1 | b0 | b1 | b2 | ... | bb |   ---->                  /\                   |      ---->                   \-------------------/      ---->      */
for|for
control|(
name|x
operator|=
literal|0
init|;
name|x
operator|<
operator|(
name|a
operator|->
name|used
operator|-
name|b
operator|)
condition|;
name|x
operator|++
control|)
block|{
operator|*
name|bottom
operator|++
operator|=
operator|*
name|top
operator|++
expr_stmt|;
block|}
comment|/* zero the top digits */
for|for
control|(
init|;
name|x
operator|<
name|a
operator|->
name|used
condition|;
name|x
operator|++
control|)
block|{
operator|*
name|bottom
operator|++
operator|=
literal|0
expr_stmt|;
block|}
block|}
comment|/* remove excess digits */
name|a
operator|->
name|used
operator|-=
name|b
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_rshd.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

