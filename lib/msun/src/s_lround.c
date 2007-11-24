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
file|<sys/limits.h>
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
value|round
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
name|DTYPE_MIN
value|LONG_MIN
end_define

begin_define
define|#
directive|define
name|DTYPE_MAX
value|LONG_MAX
end_define

begin_define
define|#
directive|define
name|fn
value|lround
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If type has more precision than dtype, the endpoints dtype_(min|max) are  * of the form xxx.5; they are "out of range" because lround() rounds away  * from 0.  On the other hand, if type has less precision than dtype, then  * all values that are out of range are integral, so we might as well assume  * that everything is in range.  At compile time, INRANGE(x) should reduce to  * two floating-point comparisons in the former case, or TRUE otherwise.  */
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|type
name|dtype_min
init|=
name|DTYPE_MIN
operator|-
literal|0.5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|type
name|dtype_max
init|=
name|DTYPE_MAX
operator|+
literal|0.5
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|INRANGE
parameter_list|(
name|x
parameter_list|)
value|(dtype_max - DTYPE_MAX != 0.5 || \ 			 ((x)> dtype_min&& (x)< dtype_max))
end_define

begin_function
name|dtype
name|fn
parameter_list|(
name|type
name|x
parameter_list|)
block|{
if|if
condition|(
name|INRANGE
argument_list|(
name|x
argument_list|)
condition|)
block|{
name|x
operator|=
name|roundit
argument_list|(
name|x
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|dtype
operator|)
name|x
operator|)
return|;
block|}
else|else
block|{
name|feraiseexcept
argument_list|(
name|FE_INVALID
argument_list|)
expr_stmt|;
return|return
operator|(
name|DTYPE_MAX
operator|)
return|;
block|}
block|}
end_function

end_unit

