begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8188E_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8188E_H
end_define

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R88E_PUBQ_NPAGES
value|142
end_define

begin_define
define|#
directive|define
name|R88E_TXPKTBUF_COUNT
value|177
end_define

begin_define
define|#
directive|define
name|R88E_TX_PAGE_COUNT
value|169
end_define

begin_define
define|#
directive|define
name|R88E_MACID_MAX
value|63
end_define

begin_define
define|#
directive|define
name|R88E_RX_DMA_BUFFER_SIZE
value|0x2400
end_define

begin_define
define|#
directive|define
name|R88E_INTR_MSG_LEN
value|60
end_define

begin_define
define|#
directive|define
name|R88E_CALIB_THRESHOLD
value|4
end_define

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r88e_beacon.c */
end_comment

begin_function_decl
name|void
name|r88e_beacon_enable
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_calib.c */
end_comment

begin_function_decl
name|void
name|r88e_iq_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_temp_measure
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|r88e_temp_read
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_chan.c */
end_comment

begin_function_decl
name|void
name|r88e_get_txpower
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|,
name|uint8_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_set_bw20
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_set_gain
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_fw.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|int
name|r88e_fw_cmd
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_fw_reset
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_fw_download_enable
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|r88e_macid_enable_link
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_set_media_status
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|int
name|r88e_set_rsvd_page
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r88e_set_pwrmode
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* r88e_init.c */
end_comment

begin_function_decl
name|void
name|r88e_init_bb
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_init_rf
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r88e_power_on
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_led.c */
end_comment

begin_function_decl
name|void
name|r88e_set_led
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_rf.c */
end_comment

begin_function_decl
name|void
name|r88e_rf_write
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_rom.c */
end_comment

begin_function_decl
name|void
name|r88e_parse_rom
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_rx.c */
end_comment

begin_function_decl
name|void
name|r88e_ratectl_tx_complete
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_handle_c2h_report
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int8_t
name|r88e_get_rssi_cck
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int8_t
name|r88e_get_rssi_ofdm
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_get_rx_stats
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211_rx_stats
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r88e_tx.c */
end_comment

begin_function_decl
name|void
name|r88e_tx_enable_ampdu
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_tx_setup_hwseq
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r88e_tx_setup_macid
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTL8188E_H */
end_comment

end_unit

