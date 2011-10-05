begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<tommath.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BN_MP_REDUCE_2K_SETUP_L_C
end_ifdef

begin_comment
comment|/* LibTomMath, multiple-precision integer library -- Tom St Denis  *  * LibTomMath is a library that provides multiple-precision  * integer arithmetic as well as number theoretic functionality.  *  * The library was designed directly after the MPI library by  * Michael Fromberger but has been written from scratch with  * additional optimizations in place.  *  * The library is free for all purposes without any express  * guarantee it works.  *  * Tom St Denis, tomstdenis@gmail.com, http://libtom.org  */
end_comment

begin_comment
comment|/* determines the setup value */
end_comment

begin_function
name|int
name|mp_reduce_2k_setup_l
parameter_list|(
name|mp_int
modifier|*
name|a
parameter_list|,
name|mp_int
modifier|*
name|d
parameter_list|)
block|{
name|int
name|res
decl_stmt|;
name|mp_int
name|tmp
decl_stmt|;
if|if
condition|(
operator|(
name|res
operator|=
name|mp_init
argument_list|(
operator|&
name|tmp
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
name|mp_2expt
argument_list|(
operator|&
name|tmp
argument_list|,
name|mp_count_bits
argument_list|(
name|a
argument_list|)
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
goto|goto
name|ERR
goto|;
block|}
if|if
condition|(
operator|(
name|res
operator|=
name|s_mp_sub
argument_list|(
operator|&
name|tmp
argument_list|,
name|a
argument_list|,
name|d
argument_list|)
operator|)
operator|!=
name|MP_OKAY
condition|)
block|{
goto|goto
name|ERR
goto|;
block|}
name|ERR
label|:
name|mp_clear
argument_list|(
operator|&
name|tmp
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
comment|/* $Source: /cvs/libtom/libtommath/bn_mp_reduce_2k_setup_l.c,v $ */
end_comment

begin_comment
comment|/* $Revision: 1.4 $ */
end_comment

begin_comment
comment|/* $Date: 2006/12/28 01:25:13 $ */
end_comment

end_unit

