begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001, 2002 Mike Barcroft<mike@FreeBSD.org>  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Klaus Klein.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE__STDINT_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE__STDINT_H_
end_define

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
value|(c)
end_define

begin_define
define|#
directive|define
name|INT16_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|INT32_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|INT64_C
parameter_list|(
name|c
parameter_list|)
value|(c ## L)
end_define

begin_define
define|#
directive|define
name|UINT8_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|UINT16_C
parameter_list|(
name|c
parameter_list|)
value|(c)
end_define

begin_define
define|#
directive|define
name|UINT32_C
parameter_list|(
name|c
parameter_list|)
value|(c ## U)
end_define

begin_define
define|#
directive|define
name|UINT64_C
parameter_list|(
name|c
parameter_list|)
value|(c ## UL)
end_define

begin_define
define|#
directive|define
name|INTMAX_C
parameter_list|(
name|c
parameter_list|)
value|(c ## L)
end_define

begin_define
define|#
directive|define
name|UINTMAX_C
parameter_list|(
name|c
parameter_list|)
value|(c ## UL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__cplusplus) || defined(__STDC_CONSTANT_MACROS) */
end_comment

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
name|__STDC_LIMIT_MACROS
argument_list|)
end_if

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.2.1 Limits of exact-width integer types  */
end_comment

begin_comment
comment|/* Minimum values of exact-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT8_MIN
value|(-0x7f-1)
end_define

begin_define
define|#
directive|define
name|INT16_MIN
value|(-0x7fff-1)
end_define

begin_define
define|#
directive|define
name|INT32_MIN
value|(-0x7fffffff-1)
end_define

begin_define
define|#
directive|define
name|INT64_MIN
value|(-0x7fffffffffffffffL-1)
end_define

begin_comment
comment|/* Maximum values of exact-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT8_MAX
value|0x7f
end_define

begin_define
define|#
directive|define
name|INT16_MAX
value|0x7fff
end_define

begin_define
define|#
directive|define
name|INT32_MAX
value|0x7fffffff
end_define

begin_define
define|#
directive|define
name|INT64_MAX
value|0x7fffffffffffffffL
end_define

begin_comment
comment|/* Maximum values of exact-width unsigned integer types. */
end_comment

begin_define
define|#
directive|define
name|UINT8_MAX
value|0xff
end_define

begin_define
define|#
directive|define
name|UINT16_MAX
value|0xffff
end_define

begin_define
define|#
directive|define
name|UINT32_MAX
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|UINT64_MAX
value|0xffffffffffffffffUL
end_define

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.2.2  Limits of minimum-width integer types  */
end_comment

begin_comment
comment|/* Minimum values of minimum-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT_LEAST8_MIN
value|INT8_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MIN
value|INT16_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MIN
value|INT64_MIN
end_define

begin_comment
comment|/* Maximum values of minimum-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT_LEAST8_MAX
value|INT8_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST16_MAX
value|INT16_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|INT_LEAST64_MAX
value|INT64_MAX
end_define

begin_comment
comment|/* Maximum values of minimum-width unsigned integer types. */
end_comment

begin_define
define|#
directive|define
name|UINT_LEAST8_MAX
value|UINT8_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST16_MAX
value|UINT16_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_LEAST64_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.2.3  Limits of fastest minimum-width integer types  */
end_comment

begin_comment
comment|/* Minimum values of fastest minimum-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT_FAST8_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MIN
value|INT64_MIN
end_define

begin_comment
comment|/* Maximum values of fastest minimum-width signed integer types. */
end_comment

begin_define
define|#
directive|define
name|INT_FAST8_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST16_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST32_MAX
value|INT32_MAX
end_define

begin_define
define|#
directive|define
name|INT_FAST64_MAX
value|INT64_MAX
end_define

begin_comment
comment|/* Maximum values of fastest minimum-width unsigned integer types. */
end_comment

begin_define
define|#
directive|define
name|UINT_FAST8_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST16_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST32_MAX
value|UINT32_MAX
end_define

begin_define
define|#
directive|define
name|UINT_FAST64_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.2.4  Limits of integer types capable of holding object pointers  */
end_comment

begin_define
define|#
directive|define
name|INTPTR_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|INTPTR_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|UINTPTR_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.2.5  Limits of greatest-width integer types  */
end_comment

begin_define
define|#
directive|define
name|INTMAX_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|INTMAX_MAX
value|INT64_MAX
end_define

begin_define
define|#
directive|define
name|UINTMAX_MAX
value|UINT64_MAX
end_define

begin_comment
comment|/*  * ISO/IEC 9899:1999  * 7.18.3  Limits of other integer types  */
end_comment

begin_comment
comment|/* Limits of ptrdiff_t. */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_MIN
value|INT64_MIN
end_define

begin_define
define|#
directive|define
name|PTRDIFF_MAX
value|INT64_MAX
end_define

begin_comment
comment|/* Limits of sig_atomic_t. */
end_comment

begin_define
define|#
directive|define
name|SIG_ATOMIC_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|SIG_ATOMIC_MAX
value|INT32_MAX
end_define

begin_comment
comment|/* Limit of size_t. */
end_comment

begin_define
define|#
directive|define
name|SIZE_MAX
value|UINT64_MAX
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_MIN
end_ifndef

begin_comment
comment|/* Also possibly defined in<wchar.h> */
end_comment

begin_comment
comment|/* Limits of wchar_t. */
end_comment

begin_define
define|#
directive|define
name|WCHAR_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|WCHAR_MAX
value|INT32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Limits of wint_t. */
end_comment

begin_define
define|#
directive|define
name|WINT_MIN
value|INT32_MIN
end_define

begin_define
define|#
directive|define
name|WINT_MAX
value|INT32_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE__STDINT_H_ */
end_comment

end_unit

