begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R88E_TX_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|R88E_TX_DESC_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_tx_desc.h>
end_include

begin_comment
comment|/* Tx MAC descriptor defines (chip-specific). */
end_comment

begin_comment
comment|/* Tx dword 1. */
end_comment

begin_define
define|#
directive|define
name|R88E_TXDW1_MACID_M
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|R88E_TXDW1_MACID_S
value|0
end_define

begin_comment
comment|/* Tx dword 2. */
end_comment

begin_define
define|#
directive|define
name|R88E_TXDW2_AGGEN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|R88E_TXDW2_AGGBK
value|0x00010000
end_define

begin_comment
comment|/* Tx dword 3. */
end_comment

begin_define
define|#
directive|define
name|R88E_TXDSEQ_HWSEQ_EN
value|0x8000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R88E_TX_DESC_H */
end_comment

end_unit

