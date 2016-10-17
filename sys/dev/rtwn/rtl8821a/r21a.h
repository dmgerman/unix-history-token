begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Andriy Voskoboinyk<avos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTL8821A_H
end_ifndef

begin_define
define|#
directive|define
name|RTL8821A_H
end_define

begin_comment
comment|/*  * Global definitions.  */
end_comment

begin_define
define|#
directive|define
name|R21A_TX_PAGE_COUNT
value|243
end_define

begin_define
define|#
directive|define
name|R21A_BCNQ0_PAGE_COUNT
value|8
end_define

begin_define
define|#
directive|define
name|R21A_BCNQ0_BOUNDARY
define|\
value|(R21A_TX_PAGE_COUNT + R21A_BCNQ0_PAGE_COUNT + 1)
end_define

begin_define
define|#
directive|define
name|R21A_TX_PAGE_SIZE
value|256
end_define

begin_comment
comment|/*  * Function declarations.  */
end_comment

begin_comment
comment|/* r21a_beacon.c */
end_comment

begin_function_decl
name|void
name|r21a_beacon_init
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
name|r21a_beacon_select
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r21a_calib.c */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTWN_WITHOUT_UCODE
end_ifndef

begin_function_decl
name|int
name|r21a_iq_calib_fw_supported
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
name|r21a_iq_calib_sw
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r21a_chan.c */
end_comment

begin_function_decl
name|void
name|r21a_set_band_2ghz
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
name|r21a_set_band_5ghz
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
comment|/* r21a_fw.c */
end_comment

begin_function_decl
name|void
name|r21a_fw_reset
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r21a_init.c */
end_comment

begin_function_decl
name|int
name|r21a_power_on
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r21a_power_off
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r21a_check_condition
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
name|void
name|r21a_crystalcap_write
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|r21a_init_bcnq1_boundary
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|r21a_init_ampdu_fwhw
parameter_list|(
name|struct
name|rtwn_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* r21a_led.c */
end_comment

begin_function_decl
name|void
name|r21a_set_led
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
comment|/* r21a_rom.c */
end_comment

begin_function_decl
name|void
name|r21a_parse_rom
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
comment|/* r21a_rx.c */
end_comment

begin_function_decl
name|int8_t
name|r21a_get_rssi_cck
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
comment|/* RTL8821A_H */
end_comment

end_unit

