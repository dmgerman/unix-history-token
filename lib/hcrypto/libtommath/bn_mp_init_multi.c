begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_INIT_MULTI_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_function
name|int
name|mp_init_multi
parameter_list|(
name|mp_int
modifier|*
name|mp
parameter_list|,
modifier|...
parameter_list|)
block|{
name|mp_err
name|res
init|=
name|MP_OKAY
decl_stmt|;
comment|/* Assume ok until proven otherwise */
name|int
name|n
init|=
literal|0
decl_stmt|;
comment|/* Number of ok inits */
name|mp_int
modifier|*
name|cur_arg
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
comment|/* init args to next argument from caller */
while|while
condition|(
name|cur_arg
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|mp_init
argument_list|(
name|cur_arg
argument_list|)
operator|!=
name|MP_OKAY
condition|)
block|{
comment|/* Oops - error! Back-track and mp_clear what we already                succeeded in init-ing, then return error.             */
name|va_list
name|clean_args
decl_stmt|;
comment|/* end the current list */
name|va_end
argument_list|(
name|args
argument_list|)
expr_stmt|;
comment|/* now start cleaning up */
name|cur_arg
operator|=
name|mp
expr_stmt|;
name|va_start
argument_list|(
name|clean_args
argument_list|,
name|mp
argument_list|)
expr_stmt|;
while|while
condition|(
name|n
operator|--
condition|)
block|{
name|mp_clear
argument_list|(
name|cur_arg
argument_list|)
expr_stmt|;
name|cur_arg
operator|=
name|va_arg
argument_list|(
name|clean_args
argument_list|,
name|mp_int
operator|*
argument_list|)
expr_stmt|;
block|}
name|va_end
argument_list|(
name|clean_args
argument_list|)
expr_stmt|;
name|res
operator|=
name|MP_MEM
expr_stmt|;
break|break;
block|}
name|n
operator|++
expr_stmt|;
name|cur_arg
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
return|return
name|res
return|;
comment|/* Assumed ok, if error flagged above. */
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_init_multi.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

