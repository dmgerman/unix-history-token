begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R92C_FW_CMD_H
end_ifndef

begin_define
define|#
directive|define
name|R92C_FW_CMD_H
end_define

begin_comment
comment|/*  * Host to firmware commands.  */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd
block|{
name|uint8_t
name|id
decl_stmt|;
define|#
directive|define
name|R92C_CMD_SET_PWRMODE
value|1
define|#
directive|define
name|R92C_CMD_JOINBSS_RPT
value|2
define|#
directive|define
name|R92C_CMD_RSVD_PAGE
value|3
define|#
directive|define
name|R92C_CMD_RSSI_SETTING
value|5
define|#
directive|define
name|R92C_CMD_MACID_CONFIG
value|6
define|#
directive|define
name|R92C_CMD_FLAG_EXT
value|0x80
name|uint8_t
name|msg
index|[
literal|5
index|]
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

begin_comment
comment|/* Structure for R92C_CMD_JOINBSS_RPT. */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd_joinbss_rpt
block|{
name|uint8_t
name|mstatus
decl_stmt|;
define|#
directive|define
name|R92C_MSTATUS_DISASSOC
value|0x00
define|#
directive|define
name|R92C_MSTATUS_ASSOC
value|0x01
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92C_CMD_SET_PWRMODE. */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd_pwrmode
block|{
name|uint8_t
name|mode
decl_stmt|;
define|#
directive|define
name|R92C_PWRMODE_CAM
value|0
define|#
directive|define
name|R92C_PWRMODE_MIN
value|1
define|#
directive|define
name|R92C_PWRMODE_MAX
value|2
define|#
directive|define
name|R92C_PWRMODE_DTIM
value|3
define|#
directive|define
name|R92C_PWRMODE_UAPSD_WMM
value|5
define|#
directive|define
name|R92C_PWRMODE_UAPSD
value|6
define|#
directive|define
name|R92C_PWRMODE_IBSS
value|7
name|uint8_t
name|smart_ps
decl_stmt|;
comment|/* XXX undocumented */
define|#
directive|define
name|R92C_PWRMODE_SMARTPS_NULLDATA
value|2
name|uint8_t
name|bcn_pass
decl_stmt|;
comment|/* unit: beacon interval */
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92C_CMD_RSVD_PAGE. */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd_rsvdpage
block|{
name|uint8_t
name|probe_resp
decl_stmt|;
name|uint8_t
name|ps_poll
decl_stmt|;
name|uint8_t
name|null_data
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92C_CMD_RSSI_SETTING. */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd_rssi
block|{
name|uint8_t
name|macid
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
name|uint8_t
name|pwdb
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/* Structure for R92C_CMD_MACID_CONFIG. */
end_comment

begin_struct
struct|struct
name|r92c_fw_cmd_macid_cfg
block|{
name|uint32_t
name|mask
decl_stmt|;
name|uint8_t
name|macid
decl_stmt|;
define|#
directive|define
name|R92C_CMD_MACID_VALID
value|0x80
block|}
name|__packed
struct|;
end_struct

begin_comment
comment|/*  * C2H event structure.  */
end_comment

begin_comment
comment|/* Bigger value is used to prevent buffer overrun. */
end_comment

begin_define
define|#
directive|define
name|R92C_C2H_MSG_MAX_LEN
value|16
end_define

begin_struct
struct|struct
name|r92c_c2h_evt
block|{
name|uint8_t
name|evtb0
decl_stmt|;
define|#
directive|define
name|R92C_C2H_EVTB0_ID_M
value|0x0f
define|#
directive|define
name|R92C_C2H_EVTB0_ID_S
value|0
define|#
directive|define
name|R92C_C2H_EVTB0_LEN_M
value|0xf0
define|#
directive|define
name|R92C_C2H_EVTB0_LEN_S
value|4
name|uint8_t
name|seq
decl_stmt|;
comment|/* Followed by payload (see below). */
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
name|R92C_C2H_EVT_DEBUG
value|0
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_TX_REPORT
value|3
end_define

begin_define
define|#
directive|define
name|R92C_C2H_EVT_EXT_RA_RPT
value|6
end_define

begin_comment
comment|/* Structure for R92C_C2H_EVT_TX_REPORT event. */
end_comment

begin_struct
struct|struct
name|r92c_c2h_tx_rpt
block|{
name|uint8_t
name|rptb0
decl_stmt|;
define|#
directive|define
name|R92C_RPTB0_RETRY_CNT_M
value|0x3f
define|#
directive|define
name|R92C_RPTB0_RETRY_CNT_S
value|0
name|uint8_t
name|rptb1
decl_stmt|;
comment|/* XXX junk */
define|#
directive|define
name|R92C_RPTB1_RTS_RETRY_CNT_M
value|0x3f
define|#
directive|define
name|R92C_RPTB1_RTS_RETRY_CNT_S
value|0
name|uint8_t
name|queue_time_low
decl_stmt|;
name|uint8_t
name|queue_time_high
decl_stmt|;
name|uint8_t
name|rptb4
decl_stmt|;
define|#
directive|define
name|R92C_RPTB4_MISSED_PKT_NUM_M
value|0x1f
define|#
directive|define
name|R92C_RPTB4_MISSED_PKT_NUM_S
value|0
name|uint8_t
name|rptb5
decl_stmt|;
define|#
directive|define
name|R92C_RPTB5_MACID_M
value|0x1f
define|#
directive|define
name|R92C_RPTB5_MACID_S
value|0
define|#
directive|define
name|R92C_RPTB5_DES1_FRAGSSN_M
value|0xe0
define|#
directive|define
name|R92C_RPTB5_DES1_FRAGSSN_S
value|5
name|uint8_t
name|rptb6
decl_stmt|;
define|#
directive|define
name|R92C_RPTB6_RPT_PKT_NUM_M
value|0x1f
define|#
directive|define
name|R92C_RPTB6_RPT_PKT_NUM_S
value|0
define|#
directive|define
name|R92C_RPTB6_PKT_DROP
value|0x20
define|#
directive|define
name|R92C_RPTB6_LIFE_EXPIRE
value|0x40
define|#
directive|define
name|R92C_RPTB6_RETRY_OVER
value|0x80
name|uint8_t
name|rptb7
decl_stmt|;
define|#
directive|define
name|R92C_RPTB7_EDCA_M
value|0x0f
define|#
directive|define
name|R92C_RPTB7_EDCA_S
value|0
define|#
directive|define
name|R92C_RPTB7_BMC
value|0x20
define|#
directive|define
name|R92C_RPTB7_PKT_OK
value|0x40
define|#
directive|define
name|R92C_RPTB7_INT_CCX
value|0x80
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R92C_FW_CMD_H */
end_comment

end_unit

