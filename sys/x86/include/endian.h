begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 1987, 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)endian.h	7.8 (Berkeley) 4/3/91  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ENDIAN_H_
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

begin_comment
comment|/*  * Define the order of 32-bit words in 64-bit words.  */
end_comment

begin_define
define|#
directive|define
name|_QUAD_HIGHWORD
value|1
end_define

begin_define
define|#
directive|define
name|_QUAD_LOWWORD
value|0
end_define

begin_comment
comment|/*  * Definitions for byte order, according to byte significance from low  * address to high.  */
end_comment

begin_define
define|#
directive|define
name|_LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* LSB first: i386, vax */
end_comment

begin_define
define|#
directive|define
name|_BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* MSB first: 68000, ibm, net */
end_comment

begin_define
define|#
directive|define
name|_PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long */
end_comment

begin_define
define|#
directive|define
name|_BYTE_ORDER
value|_LITTLE_ENDIAN
end_define

begin_comment
comment|/*  * Deprecated variants that don't have enough underscores to be useful in more  * strict namespaces.  */
end_comment

begin_if
if|#
directive|if
name|__BSD_VISIBLE
end_if

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|_LITTLE_ENDIAN
end_define

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|_PDP_ENDIAN
end_define

begin_define
define|#
directive|define
name|BYTE_ORDER
value|_BYTE_ORDER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__bswap16_gen
parameter_list|(
name|x
parameter_list|)
value|(__uint16_t)((x)<< 8 | (x)>> 8)
end_define

begin_define
define|#
directive|define
name|__bswap32_gen
parameter_list|(
name|x
parameter_list|)
define|\
value|(((__uint32_t)__bswap16((x)& 0xffff)<< 16) | __bswap16((x)>> 16))
end_define

begin_define
define|#
directive|define
name|__bswap64_gen
parameter_list|(
name|x
parameter_list|)
define|\
value|(((__uint64_t)__bswap32((x)& 0xffffffff)<< 32) | __bswap32((x)>> 32))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUCLIKE_BUILTIN_CONSTANT_P
end_ifdef

begin_define
define|#
directive|define
name|__bswap16
parameter_list|(
name|x
parameter_list|)
define|\
value|((__uint16_t)(__builtin_constant_p(x) ?	\ 	    __bswap16_gen((__uint16_t)(x)) : __bswap16_var(x)))
end_define

begin_define
define|#
directive|define
name|__bswap32
parameter_list|(
name|x
parameter_list|)
define|\
value|(__builtin_constant_p(x) ?	\ 	    __bswap32_gen((__uint32_t)(x)) : __bswap32_var(x))
end_define

begin_define
define|#
directive|define
name|__bswap64
parameter_list|(
name|x
parameter_list|)
define|\
value|(__builtin_constant_p(x) ?	\ 	    __bswap64_gen((__uint64_t)(x)) : __bswap64_var(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* XXX these are broken for use in static initializers. */
end_comment

begin_define
define|#
directive|define
name|__bswap16
parameter_list|(
name|x
parameter_list|)
value|__bswap16_var(x)
end_define

begin_define
define|#
directive|define
name|__bswap32
parameter_list|(
name|x
parameter_list|)
value|__bswap32_var(x)
end_define

begin_define
define|#
directive|define
name|__bswap64
parameter_list|(
name|x
parameter_list|)
value|__bswap64_var(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These are defined as functions to avoid multiple evaluation of x. */
end_comment

begin_function
specifier|static
name|__inline
name|__uint16_t
name|__bswap16_var
parameter_list|(
name|__uint16_t
name|_x
parameter_list|)
block|{
return|return
operator|(
name|__bswap16_gen
argument_list|(
name|_x
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__uint32_t
name|__bswap32_var
parameter_list|(
name|__uint32_t
name|_x
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|__GNUCLIKE_ASM
asm|__asm("bswap %0" : "+r" (_x));
return|return
operator|(
name|_x
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|__bswap32_gen
argument_list|(
name|_x
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|__uint64_t
name|__bswap64_var
parameter_list|(
name|__uint64_t
name|_x
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|&&
name|defined
argument_list|(
name|__GNUCLIKE_ASM
argument_list|)
asm|__asm("bswap %0" : "+r" (_x));
return|return
operator|(
name|_x
operator|)
return|;
else|#
directive|else
comment|/* 	 * It is important for the optimizations that the following is not 	 * really generic, but expands to 2 __bswap32_var()'s. 	 */
return|return
operator|(
name|__bswap64_gen
argument_list|(
name|_x
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_define
define|#
directive|define
name|__htonl
parameter_list|(
name|x
parameter_list|)
value|__bswap32(x)
end_define

begin_define
define|#
directive|define
name|__htons
parameter_list|(
name|x
parameter_list|)
value|__bswap16(x)
end_define

begin_define
define|#
directive|define
name|__ntohl
parameter_list|(
name|x
parameter_list|)
value|__bswap32(x)
end_define

begin_define
define|#
directive|define
name|__ntohs
parameter_list|(
name|x
parameter_list|)
value|__bswap16(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ENDIAN_H_ */
end_comment

end_unit

