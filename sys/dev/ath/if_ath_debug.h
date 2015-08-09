begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2009 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ATH_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ATH_DEBUG_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ATH_DEBUG
end_ifdef

begin_enum
enum|enum
block|{
name|ATH_DEBUG_XMIT
init|=
literal|0x000000001ULL
block|,
comment|/* basic xmit operation */
name|ATH_DEBUG_XMIT_DESC
init|=
literal|0x000000002ULL
block|,
comment|/* xmit descriptors */
name|ATH_DEBUG_RECV
init|=
literal|0x000000004ULL
block|,
comment|/* basic recv operation */
name|ATH_DEBUG_RECV_DESC
init|=
literal|0x000000008ULL
block|,
comment|/* recv descriptors */
name|ATH_DEBUG_RATE
init|=
literal|0x000000010ULL
block|,
comment|/* rate control */
name|ATH_DEBUG_RESET
init|=
literal|0x000000020ULL
block|,
comment|/* reset processing */
name|ATH_DEBUG_MODE
init|=
literal|0x000000040ULL
block|,
comment|/* mode init/setup */
name|ATH_DEBUG_BEACON
init|=
literal|0x000000080ULL
block|,
comment|/* beacon handling */
name|ATH_DEBUG_WATCHDOG
init|=
literal|0x000000100ULL
block|,
comment|/* watchdog timeout */
name|ATH_DEBUG_INTR
init|=
literal|0x000001000ULL
block|,
comment|/* ISR */
name|ATH_DEBUG_TX_PROC
init|=
literal|0x000002000ULL
block|,
comment|/* tx ISR proc */
name|ATH_DEBUG_RX_PROC
init|=
literal|0x000004000ULL
block|,
comment|/* rx ISR proc */
name|ATH_DEBUG_BEACON_PROC
init|=
literal|0x000008000ULL
block|,
comment|/* beacon ISR proc */
name|ATH_DEBUG_CALIBRATE
init|=
literal|0x000010000ULL
block|,
comment|/* periodic calibration */
name|ATH_DEBUG_KEYCACHE
init|=
literal|0x000020000ULL
block|,
comment|/* key cache management */
name|ATH_DEBUG_STATE
init|=
literal|0x000040000ULL
block|,
comment|/* 802.11 state transitions */
name|ATH_DEBUG_NODE
init|=
literal|0x000080000ULL
block|,
comment|/* node management */
name|ATH_DEBUG_LED
init|=
literal|0x000100000ULL
block|,
comment|/* led management */
name|ATH_DEBUG_FF
init|=
literal|0x000200000ULL
block|,
comment|/* fast frames */
name|ATH_DEBUG_DFS
init|=
literal|0x000400000ULL
block|,
comment|/* DFS processing */
name|ATH_DEBUG_TDMA
init|=
literal|0x000800000ULL
block|,
comment|/* TDMA processing */
name|ATH_DEBUG_TDMA_TIMER
init|=
literal|0x001000000ULL
block|,
comment|/* TDMA timer processing */
name|ATH_DEBUG_REGDOMAIN
init|=
literal|0x002000000ULL
block|,
comment|/* regulatory processing */
name|ATH_DEBUG_SW_TX
init|=
literal|0x004000000ULL
block|,
comment|/* per-packet software TX */
name|ATH_DEBUG_SW_TX_BAW
init|=
literal|0x008000000ULL
block|,
comment|/* BAW handling */
name|ATH_DEBUG_SW_TX_CTRL
init|=
literal|0x010000000ULL
block|,
comment|/* queue control */
name|ATH_DEBUG_SW_TX_AGGR
init|=
literal|0x020000000ULL
block|,
comment|/* aggregate TX */
name|ATH_DEBUG_SW_TX_RETRIES
init|=
literal|0x040000000ULL
block|,
comment|/* software TX retries */
name|ATH_DEBUG_FATAL
init|=
literal|0x080000000ULL
block|,
comment|/* fatal errors */
name|ATH_DEBUG_SW_TX_BAR
init|=
literal|0x100000000ULL
block|,
comment|/* BAR TX */
name|ATH_DEBUG_EDMA_RX
init|=
literal|0x200000000ULL
block|,
comment|/* RX EDMA state */
name|ATH_DEBUG_SW_TX_FILT
init|=
literal|0x400000000ULL
block|,
comment|/* SW TX FF */
name|ATH_DEBUG_NODE_PWRSAVE
init|=
literal|0x800000000ULL
block|,
comment|/* node powersave */
name|ATH_DEBUG_DIVERSITY
init|=
literal|0x1000000000ULL
block|,
comment|/* Diversity logic */
name|ATH_DEBUG_PWRSAVE
init|=
literal|0x2000000000ULL
block|,
name|ATH_DEBUG_ANY
init|=
literal|0xffffffffffffffffULL
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ATH_KTR_RXPROC
init|=
literal|0x00000001
block|,
name|ATH_KTR_TXPROC
init|=
literal|0x00000002
block|,
name|ATH_KTR_TXCOMP
init|=
literal|0x00000004
block|,
name|ATH_KTR_SWQ
init|=
literal|0x00000008
block|,
name|ATH_KTR_INTERRUPTS
init|=
literal|0x00000010
block|,
name|ATH_KTR_ERROR
init|=
literal|0x00000020
block|,
name|ATH_KTR_NODE
init|=
literal|0x00000040
block|,
name|ATH_KTR_TX
init|=
literal|0x00000080
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|ATH_KTR
parameter_list|(
name|_sc
parameter_list|,
name|_km
parameter_list|,
name|_kf
parameter_list|,
modifier|...
parameter_list|)
value|do {	\ 	if (sc->sc_ktrdebug& (_km))		\ 		CTR##_kf(KTR_DEV, __VA_ARGS__);	\ 	} while (0)
end_define

begin_decl_stmt
specifier|extern
name|uint64_t
name|ath_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IFF_DUMPPKTS
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
define|\
value|((sc->sc_debug& (m)) || \ 	    (sc->sc_ifp->if_flags& (IFF_DEBUG|IFF_LINK2)) == (IFF_DEBUG|IFF_LINK2))
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	if (sc->sc_debug& (m))					\ 		device_printf(sc->sc_dev, fmt, __VA_ARGS__);		\ } while (0)
end_define

begin_define
define|#
directive|define
name|KEYPRINTF
parameter_list|(
name|sc
parameter_list|,
name|ix
parameter_list|,
name|hk
parameter_list|,
name|mac
parameter_list|)
value|do {				\ 	if (sc->sc_debug& ATH_DEBUG_KEYCACHE)			\ 		ath_keyprint(sc, __func__, ix, hk, mac);	\ } while (0)
end_define

begin_function_decl
specifier|extern
name|void
name|ath_printrxbuf
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|u_int
name|ix
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_printtxbuf
parameter_list|(
name|struct
name|ath_softc
modifier|*
parameter_list|,
specifier|const
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
name|u_int
name|qnum
parameter_list|,
name|u_int
name|ix
parameter_list|,
name|int
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_printtxstatbuf
parameter_list|(
name|struct
name|ath_softc
modifier|*
name|sc
parameter_list|,
specifier|const
name|struct
name|ath_buf
modifier|*
name|bf
parameter_list|,
specifier|const
name|uint32_t
modifier|*
name|ds
parameter_list|,
name|u_int
name|qnum
parameter_list|,
name|u_int
name|ix
parameter_list|,
name|int
name|done
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ATH_DEBUG */
end_comment

begin_define
define|#
directive|define
name|ATH_KTR
parameter_list|(
name|_sc
parameter_list|,
name|_km
parameter_list|,
name|_kf
parameter_list|,
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|IFF_DUMPPKTS
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|)
define|\
value|((sc->sc_ifp->if_flags& (IFF_DEBUG|IFF_LINK2)) == (IFF_DEBUG|IFF_LINK2))
end_define

begin_define
define|#
directive|define
name|DPRINTF
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {				\ 	(void) sc;						\ } while (0)
end_define

begin_define
define|#
directive|define
name|KEYPRINTF
parameter_list|(
name|sc
parameter_list|,
name|k
parameter_list|,
name|ix
parameter_list|,
name|mac
parameter_list|)
value|do {				\ 	(void) sc;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATH_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

