begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|R12A_RX_DESC_H
end_ifndef

begin_define
define|#
directive|define
name|R12A_RX_DESC_H
end_define

begin_include
include|#
directive|include
file|<dev/rtwn/rtl8192c/r92c_rx_desc.h>
end_include

begin_comment
comment|/* Rx MAC descriptor defines (chip-specific). */
end_comment

begin_comment
comment|/* Rx dword 1 */
end_comment

begin_define
define|#
directive|define
name|R12A_RXDW1_AMSDU
value|0x00002000
end_define

begin_define
define|#
directive|define
name|R12A_RXDW1_AMPDU
value|0x00008000
end_define

begin_define
define|#
directive|define
name|R12A_RXDW1_CKSUM_ERR
value|0x00100000
end_define

begin_define
define|#
directive|define
name|R12A_RXDW1_IPV6
value|0x00200000
end_define

begin_define
define|#
directive|define
name|R12A_RXDW1_UDP
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R12A_RXDW1_CKSUM
value|0x00800000
end_define

begin_comment
comment|/* Rx dword 2 */
end_comment

begin_define
define|#
directive|define
name|R12A_RXDW2_RPT_C2H
value|0x10000000
end_define

begin_comment
comment|/* Rx dword 3 */
end_comment

begin_define
define|#
directive|define
name|R12A_RXDW3_RATE_M
value|0x0000007f
end_define

begin_define
define|#
directive|define
name|R12A_RXDW3_RATE_S
value|0
end_define

begin_comment
comment|/* Rx dword 4 */
end_comment

begin_define
define|#
directive|define
name|R12A_RXDW4_SPLCP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_LDPC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_STBC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW_M
value|0x00000030
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW_S
value|4
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW20
value|0
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW40
value|1
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW80
value|2
end_define

begin_define
define|#
directive|define
name|R12A_RXDW4_BW160
value|3
end_define

begin_comment
comment|/* Rx PHY descriptor. */
end_comment

begin_struct
struct|struct
name|r12a_rx_phystat
block|{
name|uint8_t
name|gain_trsw
index|[
literal|2
index|]
decl_stmt|;
name|uint16_t
name|phyw1
decl_stmt|;
define|#
directive|define
name|R12A_PHYW1_CHAN_M
value|0x03ff
define|#
directive|define
name|R12A_PHYW1_CHAN_S
value|0
define|#
directive|define
name|R12A_PHYW1_CHAN_EXT_M
value|0x3c00
define|#
directive|define
name|R12A_PHYW1_CHAN_EXT_S
value|10
define|#
directive|define
name|R12A_PHYW1_RFMOD_M
value|0xc000
define|#
directive|define
name|R12A_PHYW1_RFMOD_S
value|14
name|uint8_t
name|pwdb_all
decl_stmt|;
name|uint8_t
name|cfosho
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|cfotail
index|[
literal|4
index|]
decl_stmt|;
name|uint8_t
name|rxevm
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|rxsnr
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|pcts_msk_rpt
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|pdsnr
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|csi_current
index|[
literal|2
index|]
decl_stmt|;
name|uint8_t
name|rx_gain_c
decl_stmt|;
name|uint8_t
name|rx_gain_d
decl_stmt|;
name|uint8_t
name|sigevm
decl_stmt|;
name|uint16_t
name|phyw13
decl_stmt|;
define|#
directive|define
name|R12A_PHYW13_ANTIDX_A_M
value|0x0700
define|#
directive|define
name|R12A_PHYW13_ANTIDX_A_S
value|8
define|#
directive|define
name|R12A_PHYW13_ANTIDX_B_M
value|0x3800
define|#
directive|define
name|R12A_PHYW13_ANTIDX_B_S
value|11
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* R12A_RX_DESC_H */
end_comment

end_unit

