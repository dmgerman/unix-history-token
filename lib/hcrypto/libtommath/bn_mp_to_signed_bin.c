begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_TO_SIGNED_BIN_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* store in signed [big endian] format */
end_comment

begin_function
name|int
name|mp_to_signed_bin
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|unsigned
name|char
modifier|*
name|b
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
if|if
condition|(
operator|(
name|res
operator|=
name|mp_to_unsigned_bin
argument_list|(
name|a
argument_list|,
name|b
operator|+
literal|1
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
name|b
index|[
literal|0
index|]
operator|=
call|(
name|unsigned
name|char
call|)
argument_list|(
operator|(
name|a
operator|->
name|sign
operator|==
name|MP_ZPOS
operator|)
condition|?
literal|0
else|:
literal|1
argument_list|)
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_to_signed_bin.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

