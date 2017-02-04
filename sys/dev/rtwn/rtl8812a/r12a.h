begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8812A_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8812A_H
end_define

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R12A_PUBQ_NPAGES
value|219
end_define

begin_define
define|#
directive|define
name|R12A_TXPKTBUF_COUNT
value|255
end_define

begin_define
define|#
directive|define
name|R12A_TX_PAGE_COUNT
value|248
end_define

begin_define
define|#
directive|define
name|R12A_TX_PAGE_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|R12A_RX_DMA_BUFFER_SIZE
value|0x3e80
end_define

begin_define
define|#
directive|define
name|R12A_MAX_FW_SIZE
value|0x8000
end_define

begin_define
define|#
directive|define
name|R12A_MACID_MAX
value|127
end_define

begin_define
define|#
directive|define
name|R12A_CAM_ENTRY_COUNT
value|64
end_define

begin_define
define|#
directive|define
name|R12A_INTR_MSG_LEN
value|60
end_define

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|r12a_chan_5ghz_0
index|[]
init|=
block|{
literal|36
block|,
literal|40
block|,
literal|44
block|,
literal|48
block|,
literal|52
block|,
literal|56
block|,
literal|60
block|,
literal|64
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|r12a_chan_5ghz_1
index|[]
init|=
block|{
literal|100
block|,
literal|104
block|,
literal|108
block|,
literal|112
block|,
literal|116
block|,
literal|120
block|,
literal|124
block|,
literal|128
block|,
literal|132
block|,
literal|136
block|,
literal|140
block|,
literal|144
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|uint8_t
name|r12a_chan_5ghz_2
index|[]
init|=
block|{
literal|149
block|,
literal|153
block|,
literal|157
block|,
literal|161
block|,
literal|165
block|,
literal|169
block|,
literal|173
block|,
literal|177
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r12a_attach.c */
end_comment

begin_function_decl
name|void
name|r12a_vap_preattach
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211vap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_detach_private
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r12a_beacon.c */
end_comment

begin_function_decl
name|void
name|r12a_beacon_init
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
name|r12a_beacon_set_rate
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r12a_calib.c */
end_comment

begin_function_decl
name|void
name|r12a_save_bb_afe_vals
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
index|[]
parameter_list|,
specifier|const
name|uint16_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_restore_bb_afe_vals
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
index|[]
parameter_list|,
specifier|const
name|uint16_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_save_rf_vals
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
index|[]
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_restore_rf_vals
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
index|[]
parameter_list|,
specifier|const
name|uint8_t
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_lc_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
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
name|r12a_iq_calib_fw_supported
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|r12a_iq_calib_sw
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_iq_calib
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r12a_caps.c */
end_comment

begin_function_decl
name|int
name|r12a_ioctl_net
parameter_list|(
name|struct
name|ieee80211com
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r12a_chan.c */
end_comment

begin_function_decl
name|void
name|r12a_fix_spur
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
name|r12a_set_chan
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
name|r12a_set_band_2ghz
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_set_band_5ghz
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
comment|/* r12a_fw.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|void
name|r12a_fw_reset
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
name|r12a_fw_download_enable
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
name|r12a_set_media_status
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
name|int
name|r12a_set_pwrmode
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
name|r12a_iq_calib_fw
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* r12a_init.c */
end_comment

begin_function_decl
name|int
name|r12a_check_condition
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
name|r12a_set_page_size
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_init_edca
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_init_bb
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_init_rf
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_crystalcap_write
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r12a_power_on
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_power_off
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_init_intr
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_init_antsel
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r12a_led.c */
end_comment

begin_function_decl
name|void
name|r12a_set_led
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
comment|/* r12a_rf.c */
end_comment

begin_function_decl
name|uint32_t
name|r12a_rf_read
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
name|uint32_t
name|r12a_c_cut_rf_read
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
name|r12a_rf_write
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
comment|/* r12a_rom.c */
end_comment

begin_function_decl
name|void
name|r12a_parse_rom_common
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

begin_function_decl
name|void
name|r12a_parse_rom
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
comment|/* r12a_rx.c */
end_comment

begin_function_decl
name|void
name|r12a_ratectl_tx_complete
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
name|r12a_handle_c2h_report
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
name|int
name|r12a_check_frame_checksum
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|r12a_rx_radiotap_flags
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r12a_get_rx_stats
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
comment|/* r12a_tx.c */
end_comment

begin_function_decl
name|void
name|r12a_fill_tx_desc
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
name|r12a_fill_tx_desc_raw
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
name|r12a_fill_tx_desc_null
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
name|r12a_tx_radiotap_flags
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
comment|/* RTL8812A_H */
end_comment

end_unit

