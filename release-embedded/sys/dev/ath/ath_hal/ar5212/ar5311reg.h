begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_ATH_AR5311REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_ATH_AR5311REG_H_
end_define

begin_comment
comment|/*  * Definitions for the Atheros 5311 chipset.  */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE
value|0x005c
end_define

begin_comment
comment|/* MAC QCU/DCU clock gating control */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE_QCU_M
value|0x0000FFFF
end_define

begin_comment
comment|/* QCU clock disable */
end_comment

begin_define
define|#
directive|define
name|AR5311_QDCLKGATE_DCU_M
value|0x07FF0000
end_define

begin_comment
comment|/* DCU clock disable */
end_comment

begin_define
define|#
directive|define
name|AR5311_RXCFG_DEF_RX_ANTENNA
value|0x00000008
end_define

begin_comment
comment|/* Default Receive Antenna */
end_comment

begin_comment
comment|/*  * NOTE: MAC_5211/MAC_5311 difference  * On Oahu the TX latency field has increased from 6 bits to 9 bits.  * The RX latency field is unchanged but is shifted over 3 bits.  */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_TX_LAT_M
value|0x000FC000
end_define

begin_comment
comment|/* tx latency (usec) */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_TX_LAT_S
value|14
end_define

begin_define
define|#
directive|define
name|AR5311_USEC_RX_LAT_M
value|0x03F00000
end_define

begin_comment
comment|/* rx latency (usec) */
end_comment

begin_define
define|#
directive|define
name|AR5311_USEC_RX_LAT_S
value|20
end_define

begin_comment
comment|/*  * NOTE: MAC_5211/MAC_5311 difference  * On Maui2/Spirit the frame sequence number is controlled per DCU.  * On Oahu the frame sequence number is global across all DCUs and  * is controlled  */
end_comment

begin_define
define|#
directive|define
name|AR5311_D_MISC_SEQ_NUM_CONTROL
value|0x01000000
end_define

begin_comment
comment|/* seq num local or global */
end_comment

begin_define
define|#
directive|define
name|AR5311_DIAG_USE_ECO
value|0x00000400
end_define

begin_comment
comment|/* "super secret" enable ECO */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_ATH_AR5311REG_H_ */
end_comment

end_unit

