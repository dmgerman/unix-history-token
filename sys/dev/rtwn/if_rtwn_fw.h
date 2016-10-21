begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IF_RTWN_FW_H
end_ifndef

begin_define
define|#
directive|define
name|IF_RTWN_FW_H
end_define

begin_comment
comment|/*  * Firmware base address.  */
end_comment

begin_define
define|#
directive|define
name|R92C_FW_START_ADDR
value|0x1000
end_define

begin_define
define|#
directive|define
name|R92C_FW_PAGE_SIZE
value|4096
end_define

begin_define
define|#
directive|define
name|R92C_FW_MAX_BLOCK_SIZE
value|196
end_define

begin_comment
comment|/*  * Firmware image header.  */
end_comment

begin_struct
struct|struct
name|r92c_fw_hdr
block|{
comment|/* QWORD0 */
name|uint16_t
name|signature
decl_stmt|;
name|uint8_t
name|category
decl_stmt|;
name|uint8_t
name|function
decl_stmt|;
name|uint16_t
name|version
decl_stmt|;
name|uint16_t
name|subversion
decl_stmt|;
comment|/* QWORD1 */
name|uint8_t
name|month
decl_stmt|;
name|uint8_t
name|date
decl_stmt|;
name|uint8_t
name|hour
decl_stmt|;
name|uint8_t
name|minute
decl_stmt|;
name|uint16_t
name|ramcodesize
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
comment|/* QWORD2 */
name|uint32_t
name|svnidx
decl_stmt|;
name|uint32_t
name|reserved3
decl_stmt|;
comment|/* QWORD3 */
name|uint32_t
name|reserved4
decl_stmt|;
name|uint32_t
name|reserved5
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_function_decl
name|int
name|rtwn_load_firmware
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IF_RTWN_FW_H */
end_comment

end_unit

