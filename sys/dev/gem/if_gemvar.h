begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Eduardo Horvath.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: gemvar.h,v 1.8 2002/05/15 02:36:12 matt Exp  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_GEMVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_GEMVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/*  * Misc. definitions for the Sun ``Gem'' Ethernet controller family driver.  */
end_comment

begin_comment
comment|/*  * Transmit descriptor list size.  This is arbitrary, but allocate  * enough descriptors for 64 pending transmissions and 16 segments  * per packet. This limit is not actually enforced (packets with more segments  * can be sent, depending on the busdma backend); it is however used as an  * estimate for the tx window size.  */
end_comment

begin_define
define|#
directive|define
name|GEM_NTXSEGS
value|16
end_define

begin_define
define|#
directive|define
name|GEM_TXQUEUELEN
value|64
end_define

begin_define
define|#
directive|define
name|GEM_NTXDESC
value|(GEM_TXQUEUELEN * GEM_NTXSEGS)
end_define

begin_define
define|#
directive|define
name|GEM_MAXTXFREE
value|(GEM_NTXDESC - 1)
end_define

begin_define
define|#
directive|define
name|GEM_NTXDESC_MASK
value|(GEM_NTXDESC - 1)
end_define

begin_define
define|#
directive|define
name|GEM_NEXTTX
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& GEM_NTXDESC_MASK)
end_define

begin_comment
comment|/*  * Receive descriptor list size.  We have one Rx buffer per incoming  * packet, so this logic is a little simpler.  */
end_comment

begin_define
define|#
directive|define
name|GEM_NRXDESC
value|128
end_define

begin_define
define|#
directive|define
name|GEM_NRXDESC_MASK
value|(GEM_NRXDESC - 1)
end_define

begin_define
define|#
directive|define
name|GEM_PREVRX
parameter_list|(
name|x
parameter_list|)
value|((x - 1)& GEM_NRXDESC_MASK)
end_define

begin_define
define|#
directive|define
name|GEM_NEXTRX
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& GEM_NRXDESC_MASK)
end_define

begin_comment
comment|/*  * How many ticks to wait until to retry on a RX descriptor that is still owned  * by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|GEM_RXOWN_TICKS
value|(hz / 50)
end_define

begin_comment
comment|/*  * Control structures are DMA'd to the GEM chip.  We allocate them in  * a single clump that maps to a single DMA segment to make several things  * easier.  */
end_comment

begin_struct
struct|struct
name|gem_control_data
block|{
comment|/* 	 * The transmit descriptors. 	 */
name|struct
name|gem_desc
name|gcd_txdescs
index|[
name|GEM_NTXDESC
index|]
decl_stmt|;
comment|/* 	 * The receive descriptors. 	 */
name|struct
name|gem_desc
name|gcd_rxdescs
index|[
name|GEM_NRXDESC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GEM_CDOFF
parameter_list|(
name|x
parameter_list|)
value|offsetof(struct gem_control_data, x)
end_define

begin_define
define|#
directive|define
name|GEM_CDTXOFF
parameter_list|(
name|x
parameter_list|)
value|GEM_CDOFF(gcd_txdescs[(x)])
end_define

begin_define
define|#
directive|define
name|GEM_CDRXOFF
parameter_list|(
name|x
parameter_list|)
value|GEM_CDOFF(gcd_rxdescs[(x)])
end_define

begin_comment
comment|/*  * Software state for transmit job mbufs (may be elements of mbuf chains).  */
end_comment

begin_struct
struct|struct
name|gem_txsoft
block|{
name|struct
name|mbuf
modifier|*
name|txs_mbuf
decl_stmt|;
comment|/* head of our mbuf chain */
name|bus_dmamap_t
name|txs_dmamap
decl_stmt|;
comment|/* our DMA map */
name|int
name|txs_firstdesc
decl_stmt|;
comment|/* first descriptor in packet */
name|int
name|txs_lastdesc
decl_stmt|;
comment|/* last descriptor in packet */
name|int
name|txs_ndescs
decl_stmt|;
comment|/* number of descriptors */
name|STAILQ_ENTRY
argument_list|(
argument|gem_txsoft
argument_list|)
name|txs_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|gem_txsq
argument_list|,
name|gem_txsoft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Argument structure for busdma callback */
end_comment

begin_struct
struct|struct
name|gem_txdma
block|{
name|struct
name|gem_softc
modifier|*
name|txd_sc
decl_stmt|;
name|struct
name|gem_txsoft
modifier|*
name|txd_txs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state for receive jobs.  */
end_comment

begin_struct
struct|struct
name|gem_rxsoft
block|{
name|struct
name|mbuf
modifier|*
name|rxs_mbuf
decl_stmt|;
comment|/* head of our mbuf chain */
name|bus_dmamap_t
name|rxs_dmamap
decl_stmt|;
comment|/* our DMA map */
name|bus_addr_t
name|rxs_paddr
decl_stmt|;
comment|/* physical address of the segment */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|gem_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|device_t
name|sc_miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|sc_mii
decl_stmt|;
comment|/* MII media control */
name|device_t
name|sc_dev
decl_stmt|;
comment|/* generic device information */
name|u_char
name|sc_enaddr
index|[
literal|6
index|]
decl_stmt|;
name|struct
name|callout
name|sc_tick_ch
decl_stmt|;
comment|/* tick callout */
name|struct
name|callout
name|sc_rx_ch
decl_stmt|;
comment|/* delayed rx callout */
name|int
name|sc_wdog_timer
decl_stmt|;
comment|/* watchdog timer */
comment|/* The following bus handles are to be provided by the bus front-end */
name|bus_space_tag_t
name|sc_bustag
decl_stmt|;
comment|/* bus tag */
name|bus_dma_tag_t
name|sc_pdmatag
decl_stmt|;
comment|/* parent bus dma tag */
name|bus_dma_tag_t
name|sc_rdmatag
decl_stmt|;
comment|/* RX bus dma tag */
name|bus_dma_tag_t
name|sc_tdmatag
decl_stmt|;
comment|/* TX bus dma tag */
name|bus_dma_tag_t
name|sc_cdmatag
decl_stmt|;
comment|/* control data bus dma tag */
name|bus_dmamap_t
name|sc_dmamap
decl_stmt|;
comment|/* bus dma handle */
name|bus_space_handle_t
name|sc_h
decl_stmt|;
comment|/* bus space handle for all regs */
name|int
name|sc_phys
index|[
literal|2
index|]
decl_stmt|;
comment|/* MII instance -> PHY map */
name|int
name|sc_mif_config
decl_stmt|;
comment|/* Selected MII reg setting */
name|int
name|sc_pci
decl_stmt|;
comment|/* XXXXX -- PCI buses are LE. */
name|u_int
name|sc_variant
decl_stmt|;
comment|/* which GEM are we dealing with? */
define|#
directive|define
name|GEM_UNKNOWN
value|0
comment|/* don't know */
define|#
directive|define
name|GEM_SUN_GEM
value|1
comment|/* Sun GEM variant */
define|#
directive|define
name|GEM_APPLE_GMAC
value|2
comment|/* Apple GMAC variant */
name|u_int
name|sc_flags
decl_stmt|;
comment|/* */
define|#
directive|define
name|GEM_GIGABIT
value|0x0001
comment|/* has a gigabit PHY */
comment|/* 	 * Ring buffer DMA stuff. 	 */
name|bus_dma_segment_t
name|sc_cdseg
decl_stmt|;
comment|/* control data memory */
name|int
name|sc_cdnseg
decl_stmt|;
comment|/* number of segments */
name|bus_dmamap_t
name|sc_cddmamap
decl_stmt|;
comment|/* control data DMA map */
name|bus_addr_t
name|sc_cddma
decl_stmt|;
comment|/* 	 * Software state for transmit and receive descriptors. 	 */
name|struct
name|gem_txsoft
name|sc_txsoft
index|[
name|GEM_TXQUEUELEN
index|]
decl_stmt|;
name|struct
name|gem_rxsoft
name|sc_rxsoft
index|[
name|GEM_NRXDESC
index|]
decl_stmt|;
comment|/* 	 * Control data structures. 	 */
name|struct
name|gem_control_data
modifier|*
name|sc_control_data
decl_stmt|;
define|#
directive|define
name|sc_txdescs
value|sc_control_data->gcd_txdescs
define|#
directive|define
name|sc_rxdescs
value|sc_control_data->gcd_rxdescs
name|int
name|sc_txfree
decl_stmt|;
comment|/* number of free Tx descriptors */
name|int
name|sc_txnext
decl_stmt|;
comment|/* next ready Tx descriptor */
name|int
name|sc_txwin
decl_stmt|;
comment|/* Tx descriptors since last Tx int */
name|struct
name|gem_txsq
name|sc_txfreeq
decl_stmt|;
comment|/* free Tx descsofts */
name|struct
name|gem_txsq
name|sc_txdirtyq
decl_stmt|;
comment|/* dirty Tx descsofts */
name|int
name|sc_rxptr
decl_stmt|;
comment|/* next ready RX descriptor/descsoft */
name|int
name|sc_rxfifosize
decl_stmt|;
comment|/* Rx FIFO size (bytes) */
comment|/* ========== */
name|int
name|sc_inited
decl_stmt|;
name|int
name|sc_debug
decl_stmt|;
name|int
name|sc_ifflags
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GEM_DMA_READ
parameter_list|(
name|sc
parameter_list|,
name|v
parameter_list|)
value|(((sc)->sc_pci) ? le64toh(v) : be64toh(v))
end_define

begin_define
define|#
directive|define
name|GEM_DMA_WRITE
parameter_list|(
name|sc
parameter_list|,
name|v
parameter_list|)
value|(((sc)->sc_pci) ? htole64(v) : htobe64(v))
end_define

begin_define
define|#
directive|define
name|GEM_CDTXADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + GEM_CDTXOFF((x)))
end_define

begin_define
define|#
directive|define
name|GEM_CDRXADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + GEM_CDRXOFF((x)))
end_define

begin_define
define|#
directive|define
name|GEM_CDSYNC
parameter_list|(
name|sc
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_cdmatag, (sc)->sc_cddmamap, (ops));	\  #define	GEM_INIT_RXDESC(sc, x)						\ do {									\ 	struct gem_rxsoft *__rxs =&sc->sc_rxsoft[(x)];			\ 	struct gem_desc *__rxd =&sc->sc_rxdescs[(x)];			\ 	struct mbuf *__m = __rxs->rxs_mbuf;				\ 									\ 	__m->m_data = __m->m_ext.ext_buf;				\ 	__rxd->gd_addr =						\ 	    GEM_DMA_WRITE((sc), __rxs->rxs_paddr);			\ 	__rxd->gd_flags =						\ 	    GEM_DMA_WRITE((sc),						\ 			(((__m->m_ext.ext_size)<<GEM_RD_BUFSHIFT)	\& GEM_RD_BUFSIZE) | GEM_RD_OWN);	\ } while (0)
end_define

begin_define
define|#
directive|define
name|GEM_LOCK_INIT
parameter_list|(
name|_sc
parameter_list|,
name|_name
parameter_list|)
define|\
value|mtx_init(&(_sc)->sc_mtx, _name, MTX_NETWORK_LOCK, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|GEM_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|GEM_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|GEM_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|_what
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, (_what))
end_define

begin_define
define|#
directive|define
name|GEM_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_mtx)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|devclass_t
name|gem_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|gem_attach
parameter_list|(
name|struct
name|gem_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_detach
parameter_list|(
name|struct
name|gem_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_suspend
parameter_list|(
name|struct
name|gem_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_resume
parameter_list|(
name|struct
name|gem_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gem_mediachange
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_mediastatus
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|ifmediareq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gem_reset
parameter_list|(
name|struct
name|gem_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MII methods& callbacks */
end_comment

begin_function_decl
name|int
name|gem_mii_readreg
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gem_mii_writereg
parameter_list|(
name|device_t
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
name|void
name|gem_mii_statchg
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

