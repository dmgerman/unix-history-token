begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Mike Barcroft<mike@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_STDINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_STDINT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_INT8_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int8_t
name|int8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT8_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT16_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int16_t
name|int16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT16_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT32_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int32_t
name|int32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT32_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_INT64_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__int64_t
name|int64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INT64_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT8_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint8_t
name|uint8_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT8_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT16_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint16_t
name|uint16_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT16_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT32_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint32_t
name|uint32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT32_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_UINT64_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__uint64_t
name|uint64_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_UINT64_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|__int_least8_t
name|int_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least16_t
name|int_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least32_t
name|int_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_least64_t
name|int_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least8_t
name|uint_least8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least16_t
name|uint_least16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least32_t
name|uint_least32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_least64_t
name|uint_least64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_fast8_t
name|int_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_fast16_t
name|int_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_fast32_t
name|int_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int_fast64_t
name|int_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_fast8_t
name|uint_fast8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_fast16_t
name|uint_fast16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_fast32_t
name|uint_fast32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uint_fast64_t
name|uint_fast64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__intmax_t
name|intmax_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uintmax_t
name|uintmax_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_INTPTR_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__intptr_t
name|intptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__uintptr_t
name|uintptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_INTPTR_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|defined
argument_list|(
name|__STDC_CONSTANT_MACROS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INT8_C
parameter_list|(
name|c
parameter_list|)
value|__INT8_C(c)
end_define

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|c
parameter_list|)
value|__INT16_C(c)
end_define

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|c
parameter_list|)
value|__INT32_C(c)
end_define

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|c
parameter_list|)
value|__INT64_C(c)
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|c
parameter_list|)
value|__UINT8_C(c)
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|c
parameter_list|)
value|__UINT16_C(c)
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|c
parameter_list|)
value|__UINT32_C(c)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|c
parameter_list|)
value|__UINT64_C(c)
end_define

begin_define
define|#
directive|define
name|INTMAX_C
parameter_list|(
name|c
parameter_list|)
value|__INTMAX_C(c)
end_define

begin_define
define|#
directive|define
name|UINTMAX_C
parameter_list|(
name|c
parameter_list|)
value|__UINTMAX_C(c)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_STDINT_H_ */
end_comment

end_unit

