begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|type
end_ifndef

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|type
value|double
end_define

begin_define
define|#
directive|define
name|roundit
value|rint
end_define

begin_define
define|#
directive|define
name|dtype
value|long
end_define

begin_define
define|#
directive|define
name|fn
value|lrint
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * C99 says we should not raise a spurious inexact exception when an  * invalid exception is raised.  Unfortunately, the set of inputs  * that overflows depends on the rounding mode when 'dtype' has more  * significant bits than 'type'.  Hence, we bend over backwards for the  * sake of correctness; an MD implementation could be more efficient.  */
end_comment

begin_function
name|dtype
name|fn
parameter_list|(
name|type
name|x
parameter_list|)
block|{
name|fenv_t
name|env
decl_stmt|;
name|dtype
name|d
decl_stmt|;
name|feholdexcept
argument_list|(
operator|&
name|env
argument_list|)
expr_stmt|;
name|d
operator|=
operator|(
name|dtype
operator|)
name|roundit
argument_list|(
name|x
argument_list|)
expr_stmt|;
if|if
condition|(
name|fetestexcept
argument_list|(
name|FE_INVALID
argument_list|)
condition|)
name|feclearexcept
argument_list|(
name|FE_INEXACT
argument_list|)
expr_stmt|;
name|feupdateenv
argument_list|(
operator|&
name|env
argument_list|)
expr_stmt|;
return|return
operator|(
name|d
operator|)
return|;
block|}
end_function

end_unit

