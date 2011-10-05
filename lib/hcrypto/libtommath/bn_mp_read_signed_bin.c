begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_READ_SIGNED_BIN_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* read signed bin, big endian, first byte is 0==positive or 1==negative */
end_comment

begin_function
name|int
name|mp_read_signed_bin
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|b
parameter_list|,
name|int
name|c
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
comment|/* read magnitude */
if|if
condition|(
operator|(
name|res
operator|=
name|mp_read_unsigned_bin
argument_list|(
name|a
argument_list|,
name|b
operator|+
literal|1
argument_list|,
name|c
operator|-
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
comment|/* first byte is 0 for positive, non-zero for negative */
if|if
condition|(
name|b
index|[
literal|0
index|]
operator|==
literal|0
condition|)
block|{
name|a
operator|->
name|sign
operator|=
name|MP_ZPOS
expr_stmt|;
block|}
else|else
block|{
name|a
operator|->
name|sign
operator|=
name|MP_NEG
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_read_signed_bin.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.5 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

