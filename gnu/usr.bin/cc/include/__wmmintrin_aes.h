begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2013 John-Mark Gurney  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WMMINTRIN_AES_H_
end_ifndef

begin_define
define|#
directive|define
name|_WMMINTRIN_AES_H_
end_define

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_define
define|#
directive|define
name|MAKE_AES
parameter_list|(
name|name
parameter_list|)
define|\
value|static __inline__ __m128i __attribute__((__always_inline__, __nodebug__)) \ _mm_## name ##_si128(__m128i __V, __m128i __R) \ { \   __m128i v = __V; \  \   __asm__ (#name " %2, %0": "=x" (v): "0" (v), "xm" (__R)); \  \   return v; \ }
end_define

begin_macro
name|MAKE_AES
argument_list|(
argument|aesimc
argument_list|)
end_macro

begin_macro
name|MAKE_AES
argument_list|(
argument|aesenc
argument_list|)
end_macro

begin_macro
name|MAKE_AES
argument_list|(
argument|aesenclast
argument_list|)
end_macro

begin_macro
name|MAKE_AES
argument_list|(
argument|aesdec
argument_list|)
end_macro

begin_macro
name|MAKE_AES
argument_list|(
argument|aesdeclast
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|MAKE_AES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WMMINTRIN_AES_H_ */
end_comment

end_unit

