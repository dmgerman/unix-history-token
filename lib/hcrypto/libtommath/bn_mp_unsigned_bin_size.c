begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_UNSIGNED_BIN_SIZE_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* get the size for an unsigned equivalent */
end_comment

begin_function
name|int
name|mp_unsigned_bin_size
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|)
block|{
name|int
name|size
init|=
name|mp_count_bits
argument_list|(
name|a
argument_list|)
decl_stmt|;
return|return
operator|(
name|size
operator|/
literal|8
operator|+
operator|(
operator|(
name|size
operator|&
literal|7
operator|)
operator|!=
literal|0
condition|?
literal|1
else|:
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_unsigned_bin_size.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

