begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 David E. O'Brien  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)endian.h	8.1 (Berkeley) 6/10/93  * $NetBSD: endian.h,v 1.7 1999/08/21 05:53:51 simonb Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_ENDIAN_H_
end_define

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

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
name|_QUAD_HIGHWORD
value|1
end_define

begin_define
define|#
directive|define
name|_QUAD_LOWWORD
value|0
end_define

begin_define
define|#
directive|define
name|__ntohl
parameter_list|(
name|x
parameter_list|)
value|(__bswap32(x))
end_define

begin_define
define|#
directive|define
name|__ntohs
parameter_list|(
name|x
parameter_list|)
value|(__bswap16(x))
end_define

begin_define
define|#
directive|define
name|__htonl
parameter_list|(
name|x
parameter_list|)
value|(__bswap16(x))
end_define

begin_define
define|#
directive|define
name|__htons
parameter_list|(
name|x
parameter_list|)
value|(__bswap32(x))
end_define

begin_function
specifier|static
name|__inline
name|__uint64_t
name|__bswap64
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

begin_function
specifier|static
name|__inline
name|__uint32_t
name|__bswap32
parameter_list|(
name|__uint32_t
name|v
parameter_list|)
block|{
name|__uint32_t
name|t1
decl_stmt|;
name|t1
operator|=
name|v
operator|^
operator|(
operator|(
name|v
operator|<<
literal|16
operator|)
operator||
operator|(
name|v
operator|>>
literal|16
operator|)
operator|)
expr_stmt|;
name|t1
operator|&=
literal|0xff00ffffU
expr_stmt|;
name|v
operator|=
operator|(
name|v
operator|>>
literal|8
operator|)
operator||
operator|(
name|v
operator|<<
literal|24
operator|)
expr_stmt|;
name|v
operator|^=
operator|(
name|t1
operator|>>
literal|8
operator|)
expr_stmt|;
return|return
operator|(
name|v
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|__uint16_t
name|__bswap16
parameter_list|(
name|__uint32_t
name|v
parameter_list|)
block|{
asm|__asm __volatile(
literal|"mov    %0, %1, ror #8\n"
literal|"orr    %0, %0, %0, lsr #16\n"
literal|"bic    %0, %0, %0, lsl #16"
operator|:
literal|"=r"
operator|(
name|v
operator|)
operator|:
literal|"0"
operator|(
name|v
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|v
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_ENDIAN_H_ */
end_comment

end_unit

