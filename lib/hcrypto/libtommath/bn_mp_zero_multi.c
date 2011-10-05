begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_ZERO_MULTI_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/* set to zero */
end_comment

begin_function
name|void
name|mp_zero_multi
parameter_list|(
name|mp_int
modifier|*
name|mp
parameter_list|,
modifier|...
parameter_list|)
block|{
name|mp_int
modifier|*
name|next_mp
init|=
name|mp
decl_stmt|;
name|va_list
name|args
decl_stmt|;
name|va_start
argument_list|(
name|args
argument_list|,
name|mp
argument_list|)
expr_stmt|;
while|while
condition|(
name|next_mp
operator|!=
name|NULL
condition|)
block|{
name|mp_zero
argument_list|(
name|next_mp
argument_list|)
expr_stmt|;
name|next_mp
operator|=
name|va_arg
argument_list|(
name|args
argument_list|,
name|mp_int
operator|*
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_zero.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

