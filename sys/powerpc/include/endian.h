begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)endian.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_QUAD_HIGHWORD
value|0
end_define

begin_define
define|#
directive|define
name|_QUAD_LOWWORD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * GCC defines _BIG_ENDIAN and _LITTLE_ENDIAN equal to __BIG_ENDIAN__  * and __LITTLE_ENDIAN__ (resp).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_BIG_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|_BIG_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_LITTLE_ENDIAN
end_ifdef

begin_undef
undef|#
directive|undef
name|_LITTLE_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef

begin_define
define|#
directive|define
name|_BYTE_ORDER
value|_LITTLE_ENDIAN
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_BYTE_ORDER
value|_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUCLIKE_BUILTIN_CONSTANT_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|__is_constant
parameter_list|(
name|x
parameter_list|)
value|__builtin_constant_p(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__is_constant
parameter_list|(
name|x
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__bswap16_const
parameter_list|(
name|x
parameter_list|)
value|((((__uint16_t)(x)>> 8)& 0xff) |	\ 	(((__uint16_t)(x)<< 8)& 0xff00))
end_define

begin_define
define|#
directive|define
name|__bswap32_const
parameter_list|(
name|x
parameter_list|)
value|((((__uint32_t)(x)>> 24)& 0xff) |	\ 	(((__uint32_t)(x)>> 8)& 0xff00) |				\ 	(((__uint32_t)(x)<< 8)& 0xff0000) |				\ 	(((__uint32_t)(x)<< 24)& 0xff000000))
end_define

begin_define
define|#
directive|define
name|__bswap64_const
parameter_list|(
name|x
parameter_list|)
value|((((__uint64_t)(x)>> 56)& 0xff) |	\ 	(((__uint64_t)(x)>> 40)& 0xff00) |				\ 	(((__uint64_t)(x)>> 24)& 0xff0000) |				\ 	(((__uint64_t)(x)>> 8)& 0xff000000) |				\ 	(((__uint64_t)(x)<< 8)& ((__uint64_t)0xff<< 32)) |		\ 	(((__uint64_t)(x)<< 24)& ((__uint64_t)0xff<< 40)) |		\ 	(((__uint64_t)(x)<< 40)& ((__uint64_t)0xff<< 48)) |		\ 	(((__uint64_t)(x)<< 56)& ((__uint64_t)0xff<< 56)))
end_define

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
operator|(
name|_x
operator|>>
literal|8
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|8
operator|)
operator|&
literal|0xff00
operator|)
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
return|return
operator|(
operator|(
name|_x
operator|>>
literal|24
operator|)
operator||
operator|(
operator|(
name|_x
operator|>>
literal|8
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|8
operator|)
operator|&
literal|0xff0000
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|24
operator|)
operator|&
literal|0xff000000
operator|)
operator|)
return|;
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
return|return
operator|(
operator|(
name|_x
operator|>>
literal|56
operator|)
operator||
operator|(
operator|(
name|_x
operator|>>
literal|40
operator|)
operator|&
literal|0xff00
operator|)
operator||
operator|(
operator|(
name|_x
operator|>>
literal|24
operator|)
operator|&
literal|0xff0000
operator|)
operator||
operator|(
operator|(
name|_x
operator|>>
literal|8
operator|)
operator|&
literal|0xff000000
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|8
operator|)
operator|&
operator|(
operator|(
name|__uint64_t
operator|)
literal|0xff
operator|<<
literal|32
operator|)
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|24
operator|)
operator|&
operator|(
operator|(
name|__uint64_t
operator|)
literal|0xff
operator|<<
literal|40
operator|)
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|40
operator|)
operator|&
operator|(
operator|(
name|__uint64_t
operator|)
literal|0xff
operator|<<
literal|48
operator|)
operator|)
operator||
operator|(
operator|(
name|_x
operator|<<
literal|56
operator|)
operator|)
operator|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|__bswap16
parameter_list|(
name|x
parameter_list|)
value|((__uint16_t)(__is_constant(x) ? __bswap16_const(x) : \ 	__bswap16_var(x)))
end_define

begin_define
define|#
directive|define
name|__bswap32
parameter_list|(
name|x
parameter_list|)
value|(__is_constant(x) ? __bswap32_const(x) : \ 	__bswap32_var(x))
end_define

begin_define
define|#
directive|define
name|__bswap64
parameter_list|(
name|x
parameter_list|)
value|(__is_constant(x) ? __bswap64_const(x) : \ 	__bswap64_var(x))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN__
end_ifdef

begin_define
define|#
directive|define
name|__htonl
parameter_list|(
name|x
parameter_list|)
value|(__bswap32((__uint32_t)(x)))
end_define

begin_define
define|#
directive|define
name|__htons
parameter_list|(
name|x
parameter_list|)
value|(__bswap16((__uint16_t)(x)))
end_define

begin_define
define|#
directive|define
name|__ntohl
parameter_list|(
name|x
parameter_list|)
value|(__bswap32((__uint32_t)(x)))
end_define

begin_define
define|#
directive|define
name|__ntohs
parameter_list|(
name|x
parameter_list|)
value|(__bswap16((__uint16_t)(x)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__htonl
parameter_list|(
name|x
parameter_list|)
value|((__uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|__htons
parameter_list|(
name|x
parameter_list|)
value|((__uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|__ntohl
parameter_list|(
name|x
parameter_list|)
value|((__uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|__ntohs
parameter_list|(
name|x
parameter_list|)
value|((__uint16_t)(x))
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
comment|/* !_MACHINE_ENDIAN_H_ */
end_comment

end_unit

