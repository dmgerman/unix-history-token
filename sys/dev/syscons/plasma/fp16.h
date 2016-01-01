begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Dag-Erling SmÃ¸rgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FP16_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|FP16_H_INCLUDED
end_define

begin_typedef
typedef|typedef
name|signed
name|long
name|long
name|fp16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ItoFP16
parameter_list|(
name|n
parameter_list|)
value|((signed long long)(n)<< 16)
end_define

begin_define
define|#
directive|define
name|FP16toI
parameter_list|(
name|n
parameter_list|)
value|((signed long long)(n)>> 16)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_define
define|#
directive|define
name|FP16toF
parameter_list|(
name|n
parameter_list|)
value|((n) / 65536.0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* add a and b */
end_comment

begin_function
specifier|static
specifier|inline
name|fp16_t
name|fp16_add
parameter_list|(
name|fp16_t
name|a
parameter_list|,
name|fp16_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|+
name|b
operator|)
return|;
block|}
end_function

begin_comment
comment|/* subtract b from a */
end_comment

begin_function
specifier|static
specifier|inline
name|fp16_t
name|fp16_sub
parameter_list|(
name|fp16_t
name|a
parameter_list|,
name|fp16_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|-
name|b
operator|)
return|;
block|}
end_function

begin_comment
comment|/* multiply a by b */
end_comment

begin_function
specifier|static
specifier|inline
name|fp16_t
name|fp16_mul
parameter_list|(
name|fp16_t
name|a
parameter_list|,
name|fp16_t
name|b
parameter_list|)
block|{
return|return
operator|(
name|a
operator|*
name|b
operator|>>
literal|16
operator|)
return|;
block|}
end_function

begin_comment
comment|/* divide a by b */
end_comment

begin_function
specifier|static
specifier|inline
name|fp16_t
name|fp16_div
parameter_list|(
name|fp16_t
name|a
parameter_list|,
name|fp16_t
name|b
parameter_list|)
block|{
return|return
operator|(
operator|(
name|a
operator|<<
literal|16
operator|)
operator|/
name|b
operator|)
return|;
block|}
end_function

begin_comment
comment|/* square root */
end_comment

begin_function_decl
name|fp16_t
name|fp16_sqrt
parameter_list|(
name|fp16_t
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FP16_2PI
value|411774
end_define

begin_define
define|#
directive|define
name|FP16_PI
value|205887
end_define

begin_define
define|#
directive|define
name|FP16_PI_2
value|102943
end_define

begin_define
define|#
directive|define
name|FP16_PI_4
value|51471
end_define

begin_comment
comment|/* cosine */
end_comment

begin_function_decl
name|fp16_t
name|fp16_cos
parameter_list|(
name|fp16_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

