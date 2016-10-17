begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92C_ROM_DEFS_H
end_ifndef

begin_define
define|#
directive|define
name|R92C_ROM_DEFS_H
end_define

begin_define
define|#
directive|define
name|R92C_MAX_CHAINS
value|2
end_define

begin_define
define|#
directive|define
name|R92C_GROUP_2G
value|3
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_MAX_LEN
value|512
end_define

begin_define
define|#
directive|define
name|R92C_EFUSE_MAP_LEN
value|128
end_define

begin_comment
comment|/*  * Some generic rom parsing macros.  */
end_comment

begin_define
define|#
directive|define
name|RTWN_GET_ROM_VAR
parameter_list|(
name|var
parameter_list|,
name|def
parameter_list|)
value|(((var) != 0xff) ? (var) : (def))
end_define

begin_define
define|#
directive|define
name|RTWN_SIGN4TO8
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0x08) ? (val) | 0xf0 : (val))
end_define

begin_define
define|#
directive|define
name|LOW_PART_M
value|0x0f
end_define

begin_define
define|#
directive|define
name|LOW_PART_S
value|0
end_define

begin_define
define|#
directive|define
name|HIGH_PART_M
value|0xf0
end_define

begin_define
define|#
directive|define
name|HIGH_PART_S
value|4
end_define

begin_comment
comment|/* Bits for rf_board_opt (rf_opt1) field. */
end_comment

begin_define
define|#
directive|define
name|R92C_ROM_RF1_REGULATORY_M
value|0x07
end_define

begin_define
define|#
directive|define
name|R92C_ROM_RF1_REGULATORY_S
value|0
end_define

begin_define
define|#
directive|define
name|R92C_ROM_RF1_BOARD_TYPE_M
value|0xe0
end_define

begin_define
define|#
directive|define
name|R92C_ROM_RF1_BOARD_TYPE_S
value|5
end_define

begin_comment
comment|/* Generic board types. */
end_comment

begin_define
define|#
directive|define
name|R92C_BOARD_TYPE_DONGLE
value|0
end_define

begin_define
define|#
directive|define
name|R92C_BOARD_TYPE_HIGHPA
value|1
end_define

begin_define
define|#
directive|define
name|R92C_BOARD_TYPE_MINICARD
value|2
end_define

begin_define
define|#
directive|define
name|R92C_BOARD_TYPE_SOLO
value|3
end_define

begin_define
define|#
directive|define
name|R92C_BOARD_TYPE_COMBO
value|4
end_define

begin_comment
comment|/* Bits for channel_plan field. */
end_comment

begin_define
define|#
directive|define
name|R92C_CHANNEL_PLAN_BY_HW
value|0x80
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R92C_ROM_DEFS_H */
end_comment

end_unit

