begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R88E_REG_H
end_ifndef

begin_define
define|#
directive|define
name|R88E_REG_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_reg.h>
end_include

begin_comment
comment|/*  * MAC registers.  */
end_comment

begin_comment
comment|/* System Configuration. */
end_comment

begin_define
define|#
directive|define
name|R88E_BB_PAD_CTRL
value|0x064
end_define

begin_define
define|#
directive|define
name|R88E_HIMR
value|0x0b0
end_define

begin_define
define|#
directive|define
name|R88E_HISR
value|0x0b4
end_define

begin_define
define|#
directive|define
name|R88E_HIMRE
value|0x0b8
end_define

begin_define
define|#
directive|define
name|R88E_HISRE
value|0x0bc
end_define

begin_comment
comment|/* MAC General Configuration. */
end_comment

begin_define
define|#
directive|define
name|R88E_32K_CTRL
value|0x194
end_define

begin_define
define|#
directive|define
name|R88E_HMEBOX_EXT
parameter_list|(
name|idx
parameter_list|)
value|(0x1f0 + (idx) * 4)
end_define

begin_comment
comment|/* Protocol Configuration. */
end_comment

begin_define
define|#
directive|define
name|R88E_TXPKTBUF_BCNQ1_BDNY
value|0x457
end_define

begin_define
define|#
directive|define
name|R88E_MACID_NO_LINK
value|0x484
end_define

begin_define
define|#
directive|define
name|R88E_TX_RPT_CTRL
value|0x4ec
end_define

begin_define
define|#
directive|define
name|R88E_TX_RPT_MACID_MAX
value|0x4ed
end_define

begin_define
define|#
directive|define
name|R88E_TX_RPT_TIME
value|0x4f0
end_define

begin_define
define|#
directive|define
name|R88E_SCH_TXCMD
value|0x5f8
end_define

begin_comment
comment|/* Bits for R88E_HIMR. */
end_comment

begin_define
define|#
directive|define
name|R88E_HIMR_CPWM
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R88E_HIMR_CPWM2
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R88E_HIMR_TBDER
value|0x04000000
end_define

begin_define
define|#
directive|define
name|R88E_HIMR_PSTIMEOUT
value|0x20000000
end_define

begin_comment
comment|/* Bits for R88E_HIMRE.*/
end_comment

begin_define
define|#
directive|define
name|R88E_HIMRE_RXFOVW
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R88E_HIMRE_TXFOVW
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R88E_HIMRE_RXERR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R88E_HIMRE_TXERR
value|0x00000800
end_define

begin_comment
comment|/* Bits for R88E_TX_RPT_CTRL. */
end_comment

begin_define
define|#
directive|define
name|R88E_TX_RPT1_ENA
value|0x01
end_define

begin_define
define|#
directive|define
name|R88E_TX_RPT2_ENA
value|0x02
end_define

begin_comment
comment|/* Bits for R92C_MBID_NUM. */
end_comment

begin_define
define|#
directive|define
name|R88E_MBID_TXBCN_RPT
parameter_list|(
name|id
parameter_list|)
value|(0x08<< (id))
end_define

begin_comment
comment|/* Bits for R92C_SECCFG. */
end_comment

begin_define
define|#
directive|define
name|R88E_SECCFG_CHK_KEYID
value|0x0100
end_define

begin_comment
comment|/*  * Baseband registers.  */
end_comment

begin_comment
comment|/* Bits for R92C_LSSI_PARAM(i). */
end_comment

begin_define
define|#
directive|define
name|R88E_LSSI_PARAM_ADDR_M
value|0x0ff00000
end_define

begin_define
define|#
directive|define
name|R88E_LSSI_PARAM_ADDR_S
value|20
end_define

begin_comment
comment|/*  * RF (6052) registers.  */
end_comment

begin_define
define|#
directive|define
name|R88E_RF_T_METER
value|0x42
end_define

begin_comment
comment|/* Bits for R92C_RF_CHNLBW. */
end_comment

begin_define
define|#
directive|define
name|R88E_RF_CHNLBW_BW20
value|0x00c00
end_define

begin_comment
comment|/* Bits for R88E_RF_T_METER. */
end_comment

begin_define
define|#
directive|define
name|R88E_RF_T_METER_VAL_M
value|0x0fc00
end_define

begin_define
define|#
directive|define
name|R88E_RF_T_METER_VAL_S
value|10
end_define

begin_define
define|#
directive|define
name|R88E_RF_T_METER_START
value|0x30000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R88E_REG_H */
end_comment

end_unit

