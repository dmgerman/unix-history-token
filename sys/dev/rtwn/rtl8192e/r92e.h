begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Kevin Lo<kevlo@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8192E_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8192E_H
end_define

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R92E_PUBQ_NPAGES
value|222
end_define

begin_define
define|#
directive|define
name|R92E_TX_PAGE_COUNT
value|243
end_define

begin_define
define|#
directive|define
name|R92E_TX_PAGE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|R92E_RX_DMA_BUFFER_SIZE
value|0x3d00
end_define

begin_define
define|#
directive|define
name|R92E_MAX_FW_SIZE
value|0x8000
end_define

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r92e_attach.c */
end_comment

begin_function_decl
name|void
name|r92e_detach_private
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92e_chan.c */
end_comment

begin_function_decl
name|void
name|r92e_set_chan
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

begin_comment
comment|/* r92e_fw.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|void
name|r92e_fw_reset
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
name|r92e_set_media_status
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
name|r92e_set_pwrmode
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
comment|/* r92e_init.c */
end_comment

begin_function_decl
name|int
name|r92e_llt_init
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92e_init_bb
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92e_init_rf
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r92e_power_on
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r92e_power_off
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r92e_led.c */
end_comment

begin_function_decl
name|void
name|r92e_set_led
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
comment|/* r92e_rf.c */
end_comment

begin_function_decl
name|uint32_t
name|r92e_rf_read
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
name|r92e_rf_write
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
comment|/* r92e_rom.c */
end_comment

begin_function_decl
name|void
name|r92e_parse_rom_common
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
name|r92e_parse_rom
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
comment|/* r92e_rx.c */
end_comment

begin_function_decl
name|void
name|r92e_handle_c2h_report
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
name|r92e_get_rssi_cck
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTL8192E_H */
end_comment

end_unit

