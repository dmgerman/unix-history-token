begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** matherr.c copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/*$Log: matherr.c,v $  * Revision 1.2  1992/06/02  05:07:35  rich  * Ported to 386bsd.  Changes from vax BSD4.3 include usage of  * fmod in libm.a, usage of void pointers, and usage of vfprintf  * in libc.a.  Floating point exceptions are not raised when  * they should be, which causes the last fpe test to fail.  *  * Revision 5.1  91/12/05  07:56:18  brennan  * 1.1 pre-release  *  */
end_comment

begin_include
include|#
directive|include
file|"mawk.h"
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_if
if|#
directive|if
name|FPE_TRAPS_ON
end_if

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* machine dependent changes might be needed here */
end_comment

begin_function
specifier|static
name|void
name|fpe_catch
parameter_list|(
name|signal
parameter_list|,
name|why
parameter_list|)
name|int
name|signal
decl_stmt|,
name|why
decl_stmt|;
block|{
if|#
directive|if
name|NOINFO_SIGFPE
comment|/* some systems give no hook to find out what the exception     was -- stuff like this is why people still use fortran       If this fits, #define NOINFO_SIGFPE 1 in  your config.h */
name|rt_error
argument_list|(
literal|"floating point exception, probably overflow"
argument_list|)
expr_stmt|;
else|#
directive|else
switch|switch
condition|(
name|why
condition|)
block|{
case|case
name|FPE_INTDIV_TRAP
case|:
case|case
name|FPE_FLTDIV_TRAP
case|:
name|rt_error
argument_list|(
literal|"division by zero"
argument_list|)
expr_stmt|;
case|case
name|FPE_INTOVF_TRAP
case|:
case|case
name|FPE_FLTOVF_TRAP
case|:
name|rt_error
argument_list|(
literal|"floating point overflow"
argument_list|)
expr_stmt|;
default|default :
name|rt_error
argument_list|(
literal|"floating point exception"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|fpe_init
parameter_list|()
block|{
operator|(
name|void
operator|)
name|signal
argument_list|(
name|SIGFPE
argument_list|,
name|fpe_catch
argument_list|)
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FPE_TRAPS_ON==0 */
end_comment

begin_function
name|void
name|fpe_init
parameter_list|()
block|{
name|TURN_OFF_FPE_TRAPS
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_MATHERR
end_if

begin_if
if|#
directive|if
operator|!
name|FPE_TRAPS_ON
end_if

begin_comment
comment|/* If we are not trapping math errors, we will shutup the library calls */
end_comment

begin_function
name|int
name|matherr
parameter_list|(
name|e
parameter_list|)
name|struct
name|exception
modifier|*
name|e
decl_stmt|;
block|{
return|return
literal|1
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* print error message and exit */
end_comment

begin_function
name|int
name|matherr
parameter_list|(
name|e
parameter_list|)
name|struct
name|exception
modifier|*
name|e
decl_stmt|;
block|{
name|char
modifier|*
name|error
decl_stmt|;
switch|switch
condition|(
name|e
operator|->
name|type
condition|)
block|{
case|case
name|DOMAIN
case|:
case|case
name|SING
case|:
name|error
operator|=
literal|"domain error"
expr_stmt|;
break|break ;
case|case
name|OVERFLOW
case|:
name|error
operator|=
literal|"overflow"
expr_stmt|;
break|break ;
case|case
name|TLOSS
case|:
case|case
name|PLOSS
case|:
name|error
operator|=
literal|"loss of significance"
expr_stmt|;
break|break ;
case|case
name|UNDERFLOW
case|:
name|e
operator|->
name|retval
operator|=
literal|0.0
expr_stmt|;
return|return
literal|1
return|;
comment|/* ignore it */
block|}
if|if
condition|(
name|strcmp
argument_list|(
name|e
operator|->
name|name
argument_list|,
literal|"atan2"
argument_list|)
operator|==
literal|0
condition|)
name|rt_error
argument_list|(
literal|"atan2(%g,%g) : %s"
argument_list|,
name|e
operator|->
name|arg1
argument_list|,
name|e
operator|->
name|arg2
argument_list|,
name|error
argument_list|)
expr_stmt|;
else|else
name|rt_error
argument_list|(
literal|"%s(%g) : %s"
argument_list|,
name|e
operator|->
name|name
argument_list|,
name|e
operator|->
name|arg1
argument_list|,
name|error
argument_list|)
expr_stmt|;
comment|/* won't get here */
return|return
literal|0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FPE_TRAPS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  HAVE_MATHERR */
end_comment

begin_comment
comment|/* this is how one gets the libm calls to do the right thing on bsd43_vax */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD43_VAX
end_ifdef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_function
name|double
name|infnan
parameter_list|(
name|arg
parameter_list|)
name|int
name|arg
decl_stmt|;
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|ERANGE
case|:
name|errno
operator|=
name|ERANGE
expr_stmt|;
return|return
name|HUGE
return|;
case|case
operator|-
name|ERANGE
case|:
name|errno
operator|=
name|EDOM
expr_stmt|;
return|return
operator|-
name|HUGE
return|;
default|default :
name|errno
operator|=
name|EDOM
expr_stmt|;
block|}
return|return
literal|0.0
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD43_VAX */
end_comment

begin_comment
comment|/* This routine is for XENIX-68K 2.3A.     Error check routine to be called after fp arithmetic. */
end_comment

begin_if
if|#
directive|if
name|SW_FP_CHECK
end_if

begin_comment
comment|/* Definitions of bit values in iserr() return value */
end_comment

begin_define
define|#
directive|define
name|OVFLOW
value|2
end_define

begin_define
define|#
directive|define
name|UFLOW
value|4
end_define

begin_define
define|#
directive|define
name|ZERODIV
value|8
end_define

begin_define
define|#
directive|define
name|OVFLFIX
value|32
end_define

begin_define
define|#
directive|define
name|INFNAN
value|64
end_define

begin_function
name|void
name|fpcheck
parameter_list|()
block|{
specifier|register
name|int
name|fperrval
decl_stmt|;
name|char
modifier|*
name|errdesc
decl_stmt|;
if|if
condition|(
operator|(
name|fperrval
operator|=
name|iserr
argument_list|()
operator|)
operator|==
literal|0
condition|)
return|return ;
comment|/* no error */
name|errdesc
operator|=
operator|(
name|char
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|fperrval
operator|&
name|INFNAN
condition|)
name|errdesc
operator|=
literal|"arg is infinity or NAN"
expr_stmt|;
elseif|else
if|if
condition|(
name|fperrval
operator|&
name|ZERODIV
condition|)
name|errdesc
operator|=
literal|"division by zero"
expr_stmt|;
elseif|else
if|if
condition|(
name|fperrval
operator|&
name|OVFLOW
condition|)
name|errdesc
operator|=
literal|"overflow"
expr_stmt|;
elseif|else
if|if
condition|(
name|fperrval
operator|&
name|UFLOW
condition|)
empty_stmt|;
comment|/* ignored */
if|if
condition|(
name|errdesc
condition|)
name|rt_error
argument_list|(
literal|"%s"
argument_list|,
name|errdesc
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

