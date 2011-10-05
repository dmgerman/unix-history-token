begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_SQRMOD_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* c = a * a (mod b) */
end_comment

begin_function
name|int
name|mp_sqrmod
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|b
parameter_list|,
name|mp_int
modifier|*
name|c
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|mp_int
name|t
decl_stmt|;
if|if
condition|(
operator|(
name|res
operator|=
name|mp_init
argument_list|(
operator|&
name|t
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
if|if
condition|(
operator|(
name|res
operator|=
name|mp_sqr
argument_list|(
name|a
argument_list|,
operator|&
name|t
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
name|mp_clear
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
name|res
operator|=
name|mp_mod
argument_list|(
operator|&
name|t
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
name|mp_clear
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
return|return
name|res
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_sqrmod.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

