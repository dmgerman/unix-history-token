begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002 Thomas Moestl<tmm@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_ENDIAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ENDIAN_H_
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
file|<machine/endian.h>
end_include

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

begin_comment
comment|/*  * General byte order swapping functions.  */
end_comment

begin_define
define|#
directive|define
name|bswap16
parameter_list|(
name|x
parameter_list|)
value|__bswap16(x)
end_define

begin_define
define|#
directive|define
name|bswap32
parameter_list|(
name|x
parameter_list|)
value|__bswap32(x)
end_define

begin_define
define|#
directive|define
name|bswap64
parameter_list|(
name|x
parameter_list|)
value|__bswap64(x)
end_define

begin_comment
comment|/*  * Host to big endian, host to little endian, big endian to host, and little  * endian to host byte order functions as detailed in byteorder(9).  */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|htobe16
parameter_list|(
name|x
parameter_list|)
value|bswap16((x))
end_define

begin_define
define|#
directive|define
name|htobe32
parameter_list|(
name|x
parameter_list|)
value|bswap32((x))
end_define

begin_define
define|#
directive|define
name|htobe64
parameter_list|(
name|x
parameter_list|)
value|bswap64((x))
end_define

begin_define
define|#
directive|define
name|htole16
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htole32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htole64
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|be16toh
parameter_list|(
name|x
parameter_list|)
value|bswap16((x))
end_define

begin_define
define|#
directive|define
name|be32toh
parameter_list|(
name|x
parameter_list|)
value|bswap32((x))
end_define

begin_define
define|#
directive|define
name|be64toh
parameter_list|(
name|x
parameter_list|)
value|bswap64((x))
end_define

begin_define
define|#
directive|define
name|le16toh
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|le32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|le64toh
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BYTE_ORDER != _LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|htobe16
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe32
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|htobe64
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|htole16
parameter_list|(
name|x
parameter_list|)
value|bswap16((x))
end_define

begin_define
define|#
directive|define
name|htole32
parameter_list|(
name|x
parameter_list|)
value|bswap32((x))
end_define

begin_define
define|#
directive|define
name|htole64
parameter_list|(
name|x
parameter_list|)
value|bswap64((x))
end_define

begin_define
define|#
directive|define
name|be16toh
parameter_list|(
name|x
parameter_list|)
value|((uint16_t)(x))
end_define

begin_define
define|#
directive|define
name|be32toh
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)(x))
end_define

begin_define
define|#
directive|define
name|be64toh
parameter_list|(
name|x
parameter_list|)
value|((uint64_t)(x))
end_define

begin_define
define|#
directive|define
name|le16toh
parameter_list|(
name|x
parameter_list|)
value|bswap16((x))
end_define

begin_define
define|#
directive|define
name|le32toh
parameter_list|(
name|x
parameter_list|)
value|bswap32((x))
end_define

begin_define
define|#
directive|define
name|le64toh
parameter_list|(
name|x
parameter_list|)
value|bswap64((x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER == _LITTLE_ENDIAN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_ENDIAN_H_ */
end_comment

end_unit

