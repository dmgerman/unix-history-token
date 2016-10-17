begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R12AU_TX_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|R12AU_TX_DESC_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8812a/r12a_tx_desc.h>
end_include

begin_comment
comment|/* Tx MAC descriptor (USB). */
end_comment

begin_struct
struct|struct
name|r12au_tx_desc
block|{
name|uint16_t
name|pktlen
decl_stmt|;
name|uint8_t
name|offset
decl_stmt|;
name|uint8_t
name|flags0
decl_stmt|;
name|uint32_t
name|txdw1
decl_stmt|;
name|uint32_t
name|txdw2
decl_stmt|;
name|uint32_t
name|txdw3
decl_stmt|;
name|uint32_t
name|txdw4
decl_stmt|;
name|uint32_t
name|txdw5
decl_stmt|;
name|uint32_t
name|txdw6
decl_stmt|;
name|uint16_t
name|txdsum
decl_stmt|;
name|uint16_t
name|flags7
decl_stmt|;
define|#
directive|define
name|R12AU_FLAGS7_AGGNUM_M
value|0xff00
define|#
directive|define
name|R12AU_FLAGS7_AGGNUM_S
value|8
name|uint32_t
name|txdw8
decl_stmt|;
name|uint32_t
name|txdw9
decl_stmt|;
block|}
name|__packed
name|__attribute__
argument_list|(
operator|(
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R12AU_TX_DESC_H */
end_comment

end_unit

