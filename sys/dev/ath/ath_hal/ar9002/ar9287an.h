begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2010 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR9287AN_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR9287AN_H__
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_CH0
value|0x7808
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_CH1
value|0x785c
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_DB1
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_DB1_S
value|29
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_DB2
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_DB2_S
value|26
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_CCK
value|0x03800000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_CCK_S
value|23
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_PSK
value|0x00700000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_PSK_S
value|20
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_QAM
value|0x000E0000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_QAM_S
value|17
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_PAL_OFF
value|0x0001C000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_RF2G3_OB_PAL_OFF_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0
value|0x7898
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE_S
value|14
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE_TEST
value|1
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE_TEMPSENSE
value|2
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TXPC0_TXPCMODE_ATBTEST
value|3
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TOP2
value|0x78b4
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TOP2_XPABIAS_LVL
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|AR9287_AN_TOP2_XPABIAS_LVL_S
value|30
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

