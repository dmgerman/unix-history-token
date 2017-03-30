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
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<machine/_stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/_stdint.h>
end_include

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

begin_comment
comment|/* GNU and Darwin define this and people seem to think it's portable */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UINTPTR_MAX
argument_list|)
operator|&&
name|defined
argument_list|(
name|UINT64_MAX
argument_list|)
operator|&&
operator|(
name|UINTPTR_MAX
operator|==
name|UINT64_MAX
operator|)
end_if

begin_define
define|#
directive|define
name|__WORDSIZE
value|64
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__WORDSIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Limits of wchar_t. */
end_comment

begin_define
define|#
directive|define
name|WCHAR_MIN
value|__WCHAR_MIN
end_define

begin_define
define|#
directive|define
name|WCHAR_MAX
value|__WCHAR_MAX
end_define

begin_if
if|#
directive|if
name|__EXT1_VISIBLE
end_if

begin_comment
comment|/* ISO/IEC 9899:2011 K.3.4.4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RSIZE_MAX
end_ifndef

begin_define
define|#
directive|define
name|RSIZE_MAX
value|(SIZE_MAX>> 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EXT1_VISIBLE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_STDINT_H_ */
end_comment

end_unit

