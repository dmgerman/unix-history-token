begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1987, 1991 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)endian.h	7.8 (Berkeley) 4/3/91  * $FreeBSD$  */
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
file|<machine/ansi.h>
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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_SOURCE
end_ifndef

begin_comment
comment|/*  * Definitions for byte order, according to byte significance from low  * address to high.  */
end_comment

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
value|1234
end_define

begin_comment
comment|/* LSB first: i386, vax */
end_comment

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_comment
comment|/* MSB first: 68000, ibm, net */
end_comment

begin_define
define|#
directive|define
name|PDP_ENDIAN
value|3412
end_define

begin_comment
comment|/* LSB first in word, MSW first in long */
end_comment

begin_define
define|#
directive|define
name|BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _POSIX_SOURCE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|__word_swap_int
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__ ({ register __uint32_t __X = (x); \    __asm ("rorl $16, %0" : "+r" (__X)); \    __X; })
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|(
name|defined
argument_list|(
name|I486_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|||
name|defined
argument_list|(
name|I686_CPU
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|I386_CPU
argument_list|)
end_if

begin_define
define|#
directive|define
name|__byte_swap_int
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__ ({ register __uint32_t __X = (x); \    __asm ("bswap %0" : "+r" (__X)); \    __X; })
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__byte_swap_int
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__ ({ register __uint32_t __X = (x); \    __asm ("xchgb %h0, %b0\n\trorl $16, %0\n\txchgb %h0, %b0" \        : "+q" (__X)); \    __X; })
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__byte_swap_word
parameter_list|(
name|x
parameter_list|)
define|\
value|__extension__ ({ register __uint16_t __X = (x); \    __asm ("xchgb %h0, %b0" : "+q" (__X)); \    __X; })
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
name|_x
parameter_list|)
block|{
return|return
operator|(
name|__byte_swap_int
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
name|__uint16_t
name|__bswap16
parameter_list|(
name|__uint16_t
name|_x
parameter_list|)
block|{
return|return
operator|(
name|__byte_swap_word
argument_list|(
name|_x
argument_list|)
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

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

