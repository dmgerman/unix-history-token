begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1999 WIDE Project.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the project nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT8_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_CHAR
operator|==
literal|1
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int8_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_INT
operator|==
literal|1
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int8_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX */
end_comment

begin_error
error|#
directive|error
literal|"there's no appropriate type for u_int8_t"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_U_INT8_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT16_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_SHORT
operator|==
literal|2
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int16_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_INT
operator|==
literal|2
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int16_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_CHAR
operator|==
literal|2
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_int16_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX */
end_comment

begin_error
error|#
directive|error
literal|"there's no appropriate type for u_int16_t"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_U_INT16_T */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_U_INT32_T
end_ifndef

begin_if
if|#
directive|if
name|SIZEOF_INT
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_LONG
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_int32_t
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|SIZEOF_SHORT
operator|==
literal|4
end_elif

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_int32_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX */
end_comment

begin_error
error|#
directive|error
literal|"there's no appropriate type for u_int32_t"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_U_INT32_T */
end_comment

end_unit

