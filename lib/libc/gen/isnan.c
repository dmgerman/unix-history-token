begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|"fpmath.h"
end_include

begin_comment
comment|/*  * XXX These routines belong in libm, but they must remain in libc for  *     binary compat until we can bump libm's major version number.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PIC
end_ifdef

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__isnan
argument_list|,
name|isnan
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|__weak_reference
argument_list|(
name|__isnanf
argument_list|,
name|isnanf
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|int
name|__isnan
parameter_list|(
name|double
name|d
parameter_list|)
block|{
name|union
name|IEEEd2bits
name|u
decl_stmt|;
name|u
operator|.
name|d
operator|=
name|d
expr_stmt|;
return|return
operator|(
name|u
operator|.
name|bits
operator|.
name|exp
operator|==
literal|2047
operator|&&
operator|(
name|u
operator|.
name|bits
operator|.
name|manl
operator|!=
literal|0
operator|||
name|u
operator|.
name|bits
operator|.
name|manh
operator|!=
literal|0
operator|)
operator|)
return|;
block|}
end_function

begin_function
name|int
name|__isnanf
parameter_list|(
name|float
name|f
parameter_list|)
block|{
name|union
name|IEEEf2bits
name|u
decl_stmt|;
name|u
operator|.
name|f
operator|=
name|f
expr_stmt|;
return|return
operator|(
name|u
operator|.
name|bits
operator|.
name|exp
operator|==
literal|255
operator|&&
name|u
operator|.
name|bits
operator|.
name|man
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PIC */
end_comment

end_unit

