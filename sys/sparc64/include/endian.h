begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)endian.h	8.1 (Berkeley) 6/10/93  * $FreeBSD$  */
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

begin_comment
comment|/*  * Define the order of 32-bit words in 64-bit words.  */
end_comment

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
value|BIG_ENDIAN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_decl_stmt
name|__BEGIN_DECLS
name|__uint32_t
name|htonl
name|__P
argument_list|(
operator|(
name|__uint32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint16_t
name|htons
name|__P
argument_list|(
operator|(
name|__uint16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint32_t
name|ntohl
name|__P
argument_list|(
operator|(
name|__uint32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint16_t
name|ntohs
name|__P
argument_list|(
operator|(
name|__uint16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint16_t
name|bswap16
name|__P
argument_list|(
operator|(
name|__uint16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint32_t
name|bswap32
name|__P
argument_list|(
operator|(
name|__uint32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__uint64_t
name|bswap64
name|__P
argument_list|(
operator|(
name|__uint64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_macro
name|__END_DECLS
end_macro

begin_comment
comment|/*  * Macros for network/external number representation conversion.  */
end_comment

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_define
define|#
directive|define
name|ntohl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|ntohs
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htonl
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|htons
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NTOHL
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohl((in_addr_t)x)
end_define

begin_define
define|#
directive|define
name|NTOHS
parameter_list|(
name|x
parameter_list|)
value|(x) = ntohs((in_port_t)x)
end_define

begin_define
define|#
directive|define
name|HTONL
parameter_list|(
name|x
parameter_list|)
value|(x) = htonl((in_addr_t)x)
end_define

begin_define
define|#
directive|define
name|HTONS
parameter_list|(
name|x
parameter_list|)
value|(x) = htons((in_port_t)x)
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
comment|/* !_POSIX_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_ENDIAN_H_ */
end_comment

end_unit

