begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Adrian Chadd, Xenion Pty Ltd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATHDFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATHDFS_H__
end_define

begin_function_decl
specifier|extern
name|int
name|ath_dfs_attach
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_dfs_detach
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_dfs_radar_enable
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_dfs_process_phy_err
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
name|rxstat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_dfs_process_radar_event
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_dfs_tasklet_needed
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ieee80211_channel
modifier|*
name|chan
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_ioctl_phyerr
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_diag
modifier|*
name|ad
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ath_dfs_get_thresholds
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|HAL_PHYERR_PARAM
modifier|*
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_ATHDFS_H__ */
end_comment

end_unit

