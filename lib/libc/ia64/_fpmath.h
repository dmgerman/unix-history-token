begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Mike Barcroft<mike@FreeBSD.org>  * Copyright (c) 2002, 2003 David Schultz<das@FreeBSD.ORG>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_union
union|union
name|IEEEl2bits
block|{
name|long
name|double
name|e
decl_stmt|;
struct|struct
block|{
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
name|unsigned
name|int
name|manl
range|:
literal|32
decl_stmt|;
name|unsigned
name|int
name|manh
range|:
literal|32
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
literal|15
decl_stmt|;
name|unsigned
name|int
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|long
name|junk
range|:
literal|48
decl_stmt|;
else|#
directive|else
comment|/* _BIG_ENDIAN */
name|unsigned
name|long
name|junk
range|:
literal|48
decl_stmt|;
name|unsigned
name|int
name|sign
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|exp
range|:
literal|15
decl_stmt|;
name|unsigned
name|int
name|manh
range|:
literal|32
decl_stmt|;
name|unsigned
name|int
name|manl
range|:
literal|32
decl_stmt|;
endif|#
directive|endif
block|}
name|bits
struct|;
block|}
union|;
end_union

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
name|LDBL_NBIT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|mask_nbit_l
parameter_list|(
name|u
parameter_list|)
value|((u).bits.manh&= ~LDBL_NBIT)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BIG_ENDIAN */
end_comment

begin_comment
comment|/*  * XXX This doesn't look right.  Very few machines have a different  *     endianness for integers and floating-point, and in nextafterl()  *     we assume that none do.  If you have an environment for testing  *     this, please let me know. --das  */
end_comment

begin_define
define|#
directive|define
name|LDBL_NBIT
value|0x80
end_define

begin_define
define|#
directive|define
name|mask_nbit_l
parameter_list|(
name|u
parameter_list|)
value|((u).bits.manh&= ~LDBL_NBIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LDBL_MANH_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LDBL_MANL_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LDBL_TO_ARRAY32
parameter_list|(
name|u
parameter_list|,
name|a
parameter_list|)
value|do {			\ 	(a)[0] = (uint32_t)(u).bits.manl;		\ 	(a)[1] = (uint32_t)(u).bits.manh;		\ } while(0)
end_define

end_unit

