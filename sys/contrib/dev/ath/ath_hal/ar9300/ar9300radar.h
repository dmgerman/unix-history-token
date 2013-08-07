begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AR9300_RADAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AR9300_RADAR_H_
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_SMASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Sequence number mask */
end_comment

begin_define
define|#
directive|define
name|HAL_RADAR_SSHIFT
value|16
end_define

begin_comment
comment|/* Shift for Reader seq # stored in upper 						   16 bits, writer's is lower 16 bits */
end_comment

begin_define
define|#
directive|define
name|HAL_RADAR_IMASK
value|0x0000FFFF
end_define

begin_comment
comment|/* Index number mask */
end_comment

begin_define
define|#
directive|define
name|HAL_RADAR_ISHIFT
value|16
end_define

begin_comment
comment|/* Shift for index stored in upper 16 bits 						   of reader reset value */
end_comment

begin_define
define|#
directive|define
name|HAL_RADAR_FIRPWR
value|-45
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_RRSSI
value|14
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_HEIGHT
value|20
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_PRSSI
value|24
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_INBAND
value|6
end_define

begin_define
define|#
directive|define
name|HAL_RADAR_TSMASK
value|0x7FFF
end_define

begin_comment
comment|/* Mask for time stamp from descriptor */
end_comment

begin_define
define|#
directive|define
name|HAL_RADAR_TSSHIFT
value|15
end_define

begin_comment
comment|/* Shift for time stamp from descriptor */
end_comment

begin_define
define|#
directive|define
name|HAL_AR_RADAR_RSSI_THR
value|5
end_define

begin_comment
comment|/* in dB */
end_comment

begin_define
define|#
directive|define
name|HAL_AR_RADAR_RESET_INT
value|1
end_define

begin_comment
comment|/* in secs */
end_comment

begin_define
define|#
directive|define
name|HAL_AR_RADAR_MAX_HISTORY
value|500
end_define

begin_define
define|#
directive|define
name|HAL_AR_REGION_WIDTH
value|128
end_define

begin_define
define|#
directive|define
name|HAL_AR_RSSI_THRESH_STRONG_PKTS
value|17
end_define

begin_comment
comment|/* in dB */
end_comment

begin_define
define|#
directive|define
name|HAL_AR_RSSI_DOUBLE_THRESHOLD
value|15
end_define

begin_comment
comment|/* in dB */
end_comment

begin_define
define|#
directive|define
name|HAL_AR_MAX_NUM_ACK_REGIONS
value|9
end_define

begin_define
define|#
directive|define
name|HAL_AR_ACK_DETECT_PAR_THRESH
value|20
end_define

begin_define
define|#
directive|define
name|HAL_AR_PKT_COUNT_THRESH
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

