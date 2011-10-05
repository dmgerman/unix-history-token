begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_REVERSE_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* reverse an array, used for radix code */
end_comment

begin_function
name|void
name|bn_reverse
parameter_list|(
name|unsigned
name|char
modifier|*
name|s
parameter_list|,
name|int
name|len
parameter_list|)
block|{
name|int
name|ix
decl_stmt|,
name|iy
decl_stmt|;
name|unsigned
name|char
name|t
decl_stmt|;
name|ix
operator|=
literal|0
expr_stmt|;
name|iy
operator|=
name|len
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|ix
operator|<
name|iy
condition|)
block|{
name|t
operator|=
name|s
index|[
name|ix
index|]
expr_stmt|;
name|s
index|[
name|ix
index|]
operator|=
name|s
index|[
name|iy
index|]
expr_stmt|;
name|s
index|[
name|iy
index|]
operator|=
name|t
expr_stmt|;
operator|++
name|ix
expr_stmt|;
operator|--
name|iy
expr_stmt|;
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_reverse.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

