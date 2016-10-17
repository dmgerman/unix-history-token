begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R12A_FW_CMD_H
end_ifndef

begin_define
define|#
directive|define
name|R12A_FW_CMD_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8188e/r88e_fw_cmd.h>
end_include

begin_comment
comment|/*  * Host to firmware commands.  */
end_comment

begin_comment
comment|/* Note: some parts are shared with RTL8188EU. */
end_comment

begin_define
define|#
directive|define
name|R12A_CMD_MSR_RPT
value|0x01
end_define

begin_define
define|#
directive|define
name|R12A_CMD_SET_PWRMODE
value|0x20
end_define

begin_define
define|#
directive|define
name|R12A_CMD_IQ_CALIBRATE
value|0x45
end_define

begin_comment
comment|/* Structure for R12A_CMD_MSR_RPT. */
end_comment

begin_struct
struct|struct
name|r12a_fw_cmd_msrrpt
block|{
name|uint8_t
name|msrb0
decl_stmt|;
define|#
directive|define
name|R12A_MSRRPT_B0_DISASSOC
value|0x00
define|#
directive|define
name|R12A_MSRRPT_B0_ASSOC
value|0x01
define|#
directive|define
name|R12A_MSRRPT_B0_MACID_IND
value|0x02
name|uint8_t
name|macid
decl_stmt|;
name|uint8_t
name|macid_end
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R12A_CMD_SET_PWRMODE. */
end_comment

begin_struct
struct|struct
name|r12a_fw_cmd_pwrmode
block|{
name|uint8_t
name|mode
decl_stmt|;
name|uint8_t
name|pwrb1
decl_stmt|;
name|uint8_t
name|bcn_pass
decl_stmt|;
name|uint8_t
name|queue_uapsd
decl_stmt|;
name|uint8_t
name|pwr_state
decl_stmt|;
name|uint8_t
name|pwrb5
decl_stmt|;
define|#
directive|define
name|R12A_PWRMODE_B5_NO_BTCOEX
value|0x40
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R12A_CMD_IQ_CALIBRATE. */
end_comment

begin_struct
struct|struct
name|r12a_fw_cmd_iq_calib
block|{
name|uint8_t
name|chan
decl_stmt|;
name|uint8_t
name|band_bw
decl_stmt|;
define|#
directive|define
name|RTWN_CMD_IQ_CHAN_WIDTH_20
value|0x01
define|#
directive|define
name|RTWN_CMD_IQ_CHAN_WIDTH_40
value|0x02
define|#
directive|define
name|RTWN_CMD_IQ_CHAN_WIDTH_80
value|0x04
define|#
directive|define
name|RTWN_CMD_IQ_CHAN_WIDTH_160
value|0x08
define|#
directive|define
name|RTWN_CMD_IQ_BAND_2GHZ
value|0x10
define|#
directive|define
name|RTWN_CMD_IQ_BAND_5GHZ
value|0x20
name|uint8_t
name|ext_5g_pa_lna
decl_stmt|;
define|#
directive|define
name|RTWN_CMD_IQ_EXT_PA_5G
parameter_list|(
name|pa
parameter_list|)
value|(pa)
define|#
directive|define
name|RTWN_CMD_IQ_EXT_LNA_5G
parameter_list|(
name|lna
parameter_list|)
value|((lna)<< 1)
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * C2H event types.  */
end_comment

begin_define
define|#
directive|define
name|R12A_C2H_DEBUG
value|0x00
end_define

begin_define
define|#
directive|define
name|R12A_C2H_TX_REPORT
value|0x03
end_define

begin_define
define|#
directive|define
name|R12A_C2H_BT_INFO
value|0x09
end_define

begin_define
define|#
directive|define
name|R12A_C2H_RA_REPORT
value|0x0c
end_define

begin_define
define|#
directive|define
name|R12A_C2H_IQK_FINISHED
value|0x11
end_define

begin_comment
comment|/* Structure for R12A_C2H_TX_REPORT event. */
end_comment

begin_struct
struct|struct
name|r12a_c2h_tx_rpt
block|{
name|uint8_t
name|txrptb0
decl_stmt|;
define|#
directive|define
name|R12A_TXRPTB0_QSEL_M
value|0x1f
define|#
directive|define
name|R12A_TXRPTB0_QSEL_S
value|0
define|#
directive|define
name|R12A_TXRPTB0_BC
value|0x20
define|#
directive|define
name|R12A_TXRPTB0_LIFE_EXPIRE
value|0x40
define|#
directive|define
name|R12A_TXRPTB0_RETRY_OVER
value|0x80
name|uint8_t
name|macid
decl_stmt|;
name|uint8_t
name|txrptb2
decl_stmt|;
define|#
directive|define
name|R12A_TXRPTB2_RETRY_CNT_M
value|0x3f
define|#
directive|define
name|R12A_TXRPTB2_RETRY_CNT_S
value|0
name|uint8_t
name|queue_time_low
decl_stmt|;
comment|/* 256 msec unit */
name|uint8_t
name|queue_time_high
decl_stmt|;
name|uint8_t
name|final_rate
decl_stmt|;
name|uint16_t
name|reserved
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R12A_C2H_RA_REPORT event. */
end_comment

begin_struct
struct|struct
name|r12a_c2h_ra_report
block|{
name|uint8_t
name|rarptb0
decl_stmt|;
define|#
directive|define
name|R12A_RARPTB0_RATE_M
value|0x3f
define|#
directive|define
name|R12A_RARPTB0_RATE_S
value|0
name|uint8_t
name|macid
decl_stmt|;
name|uint8_t
name|rarptb2
decl_stmt|;
define|#
directive|define
name|R12A_RARPTB0_LDPC
value|0x01
define|#
directive|define
name|R12A_RARPTB0_TXBF
value|0x02
define|#
directive|define
name|R12A_RARPTB0_NOISE
value|0x04
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R12A_FW_CMD_H */
end_comment

end_unit

