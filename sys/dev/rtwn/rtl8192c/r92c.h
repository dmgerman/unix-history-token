begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Damien Bergamini<damien.bergamini@free.fr>  * Copyright (c) 2015-2016 Andriy Voskoboinyk<avos@FreeBSD.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $OpenBSD: if_urtwnreg.h,v 1.3 2010/11/16 18:02:59 damien Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8192C_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8192C_H
end_define

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R92C_TXPKTBUF_COUNT
value|256
end_define

begin_define
define|#
directive|define
name|R92C_TX_PAGE_SIZE
value|128
end_define

begin_define
define|#
directive|define
name|R92C_RX_DMA_BUFFER_SIZE
value|0x2800
end_define

begin_define
define|#
directive|define
name|R92C_MAX_FW_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|R92C_MACID_MAX
value|31
end_define

begin_define
define|#
directive|define
name|R92C_CAM_ENTRY_COUNT
value|32
end_define

begin_define
define|#
directive|define
name|R92C_CALIB_THRESHOLD
value|2
end_define

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r92c_attach.c */
end_comment

begin_function_decl
name|void
name|r92c_detach_private
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_read_chipid_vendor
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92c_beacon.c */
end_comment

begin_function_decl
name|void
name|r92c_beacon_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_beacon_enable
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
comment|/* r92c_calib.c */
end_comment

begin_function_decl
name|void
name|r92c_iq_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_lc_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_temp_measure
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|r92c_temp_read
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92c_chan.c */
end_comment

begin_function_decl
name|void
name|r92c_get_txpower
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
name|r92c_set_bw20
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
name|r92c_set_chan
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_set_gain
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
name|r92c_scan_start
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_scan_end
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92c_fw.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|void
name|r92c_fw_reset
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
name|r92c_fw_download_enable
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
name|r92c_joinbss_rpt
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
name|r92c_set_rsvd_page
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
name|r92c_set_pwrmode
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

begin_function_decl
name|void
name|r92c_set_rssi
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_handle_c2h_report
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* r92c_init.c */
end_comment

begin_function_decl
name|int
name|r92c_check_condition
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r92c_llt_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r92c_set_page_size
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_init_bb_common
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r92c_init_rf_chain
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|rtwn_rf_prog
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_init_rf
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_init_edca
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_init_ampdu
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_init_antsel
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_pa_bias_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92c_llt.c */
end_comment

begin_function_decl
name|int
name|r92c_llt_write
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92c_rf.c */
end_comment

begin_function_decl
name|uint32_t
name|r92c_rf_read
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_rf_write
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
comment|/* r92c_rom.c */
end_comment

begin_function_decl
name|void
name|r92c_efuse_postread
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_parse_rom
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
comment|/* r92c_rx.c */
end_comment

begin_function_decl
name|int8_t
name|r92c_get_rssi_cck
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
name|r92c_get_rssi_ofdm
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
name|uint8_t
name|r92c_rx_radiotap_flags
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_get_rx_stats
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
comment|/* r92c_tx.c */
end_comment

begin_function_decl
name|void
name|r92c_tx_enable_ampdu
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
name|r92c_tx_setup_hwseq
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_tx_setup_macid
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
name|r92c_fill_tx_desc
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|uint8_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_fill_tx_desc_raw
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211_node
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|struct
name|ieee80211_bpf_params
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92c_fill_tx_desc_null
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|void
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
name|uint8_t
name|r92c_tx_radiotap_flags
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTL8192C_H */
end_comment

end_unit

