begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<fenv.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/*  * We save and restore the floating-point environment to avoid raising  * an inexact exception.  We can get away with using fesetenv()  * instead of feclearexcept()/feupdateenv() to restore the environment  * because the only exception defined for rint() is overflow, and  * rounding can't overflow as long as emax>= p.  */
end_comment

begin_define
define|#
directive|define
name|DECL
parameter_list|(
name|type
parameter_list|,
name|fn
parameter_list|,
name|rint
parameter_list|)
define|\
value|type				\ fn(type x)			\ {				\ 	type ret;		\ 	fenv_t env;		\ 				\ 	fegetenv(&env);		\ 	ret = rint(x);		\ 	fesetenv(&env);		\ 	return (ret);		\ }
end_define

begin_macro
name|DECL
argument_list|(
argument|double
argument_list|,
argument|nearbyint
argument_list|,
argument|rint
argument_list|)
end_macro

begin_macro
name|DECL
argument_list|(
argument|float
argument_list|,
argument|nearbyintf
argument_list|,
argument|rintf
argument_list|)
end_macro

end_unit

