begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 David Chisnall  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<float.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_comment
comment|/*  * If long double is not the same size as double, then these will lose  * precision and we should emit a warning whenever something links against  * them.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|LDBL_MANT_DIG
operator|>
literal|53
operator|)
end_if

begin_define
define|#
directive|define
name|WARN_IMPRECISE
parameter_list|(
name|x
parameter_list|)
define|\
value|__warn_references(x, # x " has lower than advertised precision");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WARN_IMPRECISE
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Declare the functions as weak variants so that other libraries providing  * real versions can override them.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_WEAK
parameter_list|(
name|x
parameter_list|)
define|\
value|__weak_reference(imprecise_## x, x);\ 	WARN_IMPRECISE(x)
end_define

begin_function
name|long
name|double
name|imprecise_powl
parameter_list|(
name|long
name|double
name|x
parameter_list|,
name|long
name|double
name|y
parameter_list|)
block|{
return|return
name|pow
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_expr_stmt
name|DECLARE_WEAK
argument_list|(
name|powl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DECLARE_IMPRECISE
parameter_list|(
name|f
parameter_list|)
define|\
value|long double imprecise_ ## f ## l(long double v) { return f(v); }\ 	DECLARE_WEAK(f ## l)
end_define

begin_expr_stmt
name|DECLARE_IMPRECISE
argument_list|(
name|lgamma
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DECLARE_IMPRECISE
argument_list|(
name|tgamma
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

