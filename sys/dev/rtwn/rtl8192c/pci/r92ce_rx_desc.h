begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_rtwnreg.h,v 1.3 2015/06/14 08:02:47 stsp Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015 Stefan Sperling<stsp@openbsd.org>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92CE_RX_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|R92CE_RX_DESC_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_rx_desc.h>
end_include

begin_comment
comment|/* Rx MAC descriptor (PCIe). */
end_comment

begin_struct
struct|struct
name|r92ce_rx_stat
block|{
name|uint32_t
name|rxdw0
decl_stmt|;
name|uint32_t
name|rxdw1
decl_stmt|;
name|uint32_t
name|rxdw2
decl_stmt|;
name|uint32_t
name|rxdw3
decl_stmt|;
name|uint32_t
name|rxdw4
decl_stmt|;
name|uint32_t
name|tsf_low
decl_stmt|;
name|uint32_t
name|rxbufaddr
decl_stmt|;
name|uint32_t
name|rxbufaddr64
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
comment|/* R92CE_RX_DESC_H */
end_comment

end_unit

