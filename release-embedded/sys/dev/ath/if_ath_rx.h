begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_RX_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_RX_H__
end_define

begin_function_decl
specifier|extern
name|u_int32_t
name|ath_calcrxfilter
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
name|void
name|ath_recv_mgmt
parameter_list|(
name|struct
name|ieee80211_node
modifier|*
name|ni
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|,
name|int
name|subtype
parameter_list|,
name|int
name|rssi
parameter_list|,
name|int
name|nf
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ath_stoprecv
parameter_list|(
name|_sc
parameter_list|,
name|_dodelay
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_stop((_sc), (_dodelay))
end_define

begin_define
define|#
directive|define
name|ath_startrecv
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_start((_sc))
end_define

begin_define
define|#
directive|define
name|ath_rx_flush
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_flush((_sc))
end_define

begin_define
define|#
directive|define
name|ath_rxbuf_init
parameter_list|(
name|_sc
parameter_list|,
name|_bf
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_rxbuf_init((_sc), (_bf))
end_define

begin_define
define|#
directive|define
name|ath_rxdma_setup
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_setup(_sc)
end_define

begin_define
define|#
directive|define
name|ath_rxdma_teardown
parameter_list|(
name|_sc
parameter_list|)
define|\
value|(_sc)->sc_rx.recv_teardown(_sc)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|extern	int ath_rxbuf_init(struct ath_softc *sc, struct ath_buf *bf); extern	void ath_rx_tasklet(void *arg, int npending); extern	void ath_rx_proc(struct ath_softc *sc, int resched); extern	void ath_stoprecv(struct ath_softc *sc, int dodelay); extern	int ath_startrecv(struct ath_softc *sc);
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|ath_rx_pkt
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ath_rx_status
modifier|*
name|rs
parameter_list|,
name|HAL_STATUS
name|status
parameter_list|,
name|uint64_t
name|tsf
parameter_list|,
name|int
name|nf
parameter_list|,
name|HAL_RX_QUEUE
name|qtype
parameter_list|,
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_recv_setup_legacy
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

