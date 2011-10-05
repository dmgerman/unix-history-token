begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_TO_UNSIGNED_BIN_N_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* store in unsigned [big endian] format */
end_comment

begin_function
name|int
name|mp_to_unsigned_bin_n
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
name|b
parameter_list|,
name|unsigned
name|long
modifier|*
name|outlen
parameter_list|)
block|{
if|if
condition|(
operator|*
name|outlen
operator|<
operator|(
name|unsigned
name|long
operator|)
name|mp_unsigned_bin_size
argument_list|(
name|a
argument_list|)
condition|)
block|{
return|return
name|MP_VAL
return|;
block|}
operator|*
name|outlen
operator|=
name|mp_unsigned_bin_size
argument_list|(
name|a
argument_list|)
expr_stmt|;
return|return
name|mp_to_unsigned_bin
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_to_unsigned_bin_n.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

