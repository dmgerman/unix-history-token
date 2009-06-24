begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2001 Eduardo Horvath.  * Copyright (c) 2008 Marius Strobl<marius@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR  ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR  BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	from: NetBSD: gemvar.h,v 1.8 2002/05/15 02:36:12 matt Exp  *	from: FreeBSD: if_gemvar.h 177560 2008-03-24 17:23:53Z marius  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_CASVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_CASVAR_H
end_define

begin_comment
comment|/*  * The page size is configurable, but needs to be at least 8k (the  * default) in order to also support jumbo buffers.  */
end_comment

begin_define
define|#
directive|define
name|CAS_PAGE_SIZE
value|8192
end_define

begin_comment
comment|/*  * Transmit descriptor ring size - this is arbitrary, but allocate  * enough descriptors for 64 pending transmissions and 16 segments  * per packet.  This limit is not actually enforced (packets with  * more segments can be sent, depending on the busdma backend); it  * is however used as an estimate for the TX window size.  */
end_comment

begin_define
define|#
directive|define
name|CAS_NTXSEGS
value|16
end_define

begin_define
define|#
directive|define
name|CAS_TXQUEUELEN
value|64
end_define

begin_define
define|#
directive|define
name|CAS_NTXDESC
value|(CAS_TXQUEUELEN * CAS_NTXSEGS)
end_define

begin_define
define|#
directive|define
name|CAS_MAXTXFREE
value|(CAS_NTXDESC - 1)
end_define

begin_define
define|#
directive|define
name|CAS_NTXDESC_MASK
value|(CAS_NTXDESC - 1)
end_define

begin_define
define|#
directive|define
name|CAS_NEXTTX
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& CAS_NTXDESC_MASK)
end_define

begin_comment
comment|/*  * Receive completion ring size - we have one completion per  * incoming packet (though the opposite isn't necesarrily true),  * so this logic is a little simpler.  */
end_comment

begin_define
define|#
directive|define
name|CAS_NRXCOMP
value|4096
end_define

begin_define
define|#
directive|define
name|CAS_NRXCOMP_MASK
value|(CAS_NRXCOMP - 1)
end_define

begin_define
define|#
directive|define
name|CAS_NEXTRXCOMP
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& CAS_NRXCOMP_MASK)
end_define

begin_comment
comment|/*  * Receive descriptor ring sizes - for Cassini+ and Saturn both  * rings must be at least initialized.  */
end_comment

begin_define
define|#
directive|define
name|CAS_NRXDESC
value|1024
end_define

begin_define
define|#
directive|define
name|CAS_NRXDESC_MASK
value|(CAS_NRXDESC - 1)
end_define

begin_define
define|#
directive|define
name|CAS_NEXTRXDESC
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& CAS_NRXDESC_MASK)
end_define

begin_define
define|#
directive|define
name|CAS_NRXDESC2
value|32
end_define

begin_define
define|#
directive|define
name|CAS_NRXDESC2_MASK
value|(CAS_NRXDESC2 - 1)
end_define

begin_define
define|#
directive|define
name|CAS_NEXTRXDESC2
parameter_list|(
name|x
parameter_list|)
value|((x + 1)& CAS_NRXDESC2_MASK)
end_define

begin_comment
comment|/*  * How many ticks to wait until to retry on a RX descriptor that is  * still owned by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|CAS_RXOWN_TICKS
value|(hz / 50)
end_define

begin_comment
comment|/*  * Control structures are DMA'd to the chip.  We allocate them  * in a single clump that maps to a single DMA segment to make  * several things easier.  */
end_comment

begin_struct
struct|struct
name|cas_control_data
block|{
name|struct
name|cas_desc
name|ccd_txdescs
index|[
name|CAS_NTXDESC
index|]
decl_stmt|;
comment|/* TX descriptors */
name|struct
name|cas_rx_comp
name|ccd_rxcomps
index|[
name|CAS_NRXCOMP
index|]
decl_stmt|;
comment|/* RX completions */
name|struct
name|cas_desc
name|ccd_rxdescs
index|[
name|CAS_NRXDESC
index|]
decl_stmt|;
comment|/* RX descriptors */
name|struct
name|cas_desc
name|ccd_rxdescs2
index|[
name|CAS_NRXDESC2
index|]
decl_stmt|;
comment|/* RX descriptors 2 */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAS_CDOFF
parameter_list|(
name|x
parameter_list|)
value|offsetof(struct cas_control_data, x)
end_define

begin_define
define|#
directive|define
name|CAS_CDTXDOFF
parameter_list|(
name|x
parameter_list|)
value|CAS_CDOFF(ccd_txdescs[(x)])
end_define

begin_define
define|#
directive|define
name|CAS_CDRXCOFF
parameter_list|(
name|x
parameter_list|)
value|CAS_CDOFF(ccd_rxcomps[(x)])
end_define

begin_define
define|#
directive|define
name|CAS_CDRXDOFF
parameter_list|(
name|x
parameter_list|)
value|CAS_CDOFF(ccd_rxdescs[(x)])
end_define

begin_define
define|#
directive|define
name|CAS_CDRXD2OFF
parameter_list|(
name|x
parameter_list|)
value|CAS_CDOFF(ccd_rxdescs2[(x)])
end_define

begin_comment
comment|/*  * software state for transmit job mbufs (may be elements of mbuf chains)  */
end_comment

begin_struct
struct|struct
name|cas_txsoft
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
name|u_int
name|txs_firstdesc
decl_stmt|;
comment|/* first descriptor in packet */
name|u_int
name|txs_lastdesc
decl_stmt|;
comment|/* last descriptor in packet */
name|u_int
name|txs_ndescs
decl_stmt|;
comment|/* number of descriptors */
name|STAILQ_ENTRY
argument_list|(
argument|cas_txsoft
argument_list|)
name|txs_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|cas_txsq
argument_list|,
name|cas_txsoft
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * software state for receive descriptors  */
end_comment

begin_struct
struct|struct
name|cas_rxdsoft
block|{
name|void
modifier|*
name|rxds_buf
decl_stmt|;
comment|/* receive buffer */
name|bus_dmamap_t
name|rxds_dmamap
decl_stmt|;
comment|/* our DMA map */
name|bus_addr_t
name|rxds_paddr
decl_stmt|;
comment|/* physical address of the segment */
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800016
name|struct
name|cas_softc
modifier|*
name|rxds_sc
decl_stmt|;
comment|/* softc pointer */
name|u_int
name|rxds_idx
decl_stmt|;
comment|/* our index */
endif|#
directive|endif
name|u_int
name|rxds_refcount
decl_stmt|;
comment|/* hardware + mbuf references */
block|}
struct|;
end_struct

begin_comment
comment|/*  * software state per device  */
end_comment

begin_struct
struct|struct
name|cas_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|mtx
name|sc_mtx
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
name|ETHER_ADDR_LEN
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
comment|/* delayed RX callout */
name|struct
name|task
name|sc_intr_task
decl_stmt|;
name|struct
name|task
name|sc_tx_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|sc_tq
decl_stmt|;
name|u_int
name|sc_wdog_timer
decl_stmt|;
comment|/* watchdog timer */
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_res
index|[
literal|2
index|]
decl_stmt|;
define|#
directive|define
name|CAS_RES_INTR
value|0
define|#
directive|define
name|CAS_RES_MEM
value|1
name|bus_dma_tag_t
name|sc_pdmatag
decl_stmt|;
comment|/* parent bus DMA tag */
name|bus_dma_tag_t
name|sc_rdmatag
decl_stmt|;
comment|/* RX bus DMA tag */
name|bus_dma_tag_t
name|sc_tdmatag
decl_stmt|;
comment|/* TX bus DMA tag */
name|bus_dma_tag_t
name|sc_cdmatag
decl_stmt|;
comment|/* control data bus DMA tag */
name|bus_dmamap_t
name|sc_dmamap
decl_stmt|;
comment|/* bus DMA handle */
name|u_int
name|sc_phyad
decl_stmt|;
comment|/* PHY to use or -1 for any */
name|u_int
name|sc_variant
decl_stmt|;
define|#
directive|define
name|CAS_UNKNOWN
value|0
comment|/* don't know */
define|#
directive|define
name|CAS_CAS
value|1
comment|/* Sun Cassini */
define|#
directive|define
name|CAS_CASPLUS
value|2
comment|/* Sun Cassini+ */
define|#
directive|define
name|CAS_SATURN
value|3
comment|/* National Semiconductor Saturn */
name|u_int
name|sc_flags
decl_stmt|;
define|#
directive|define
name|CAS_INITED
value|(1<< 0)
comment|/* reset persistent regs init'ed */
define|#
directive|define
name|CAS_NO_CSUM
value|(1<< 1)
comment|/* don't use hardware checksumming */
define|#
directive|define
name|CAS_LINK
value|(1<< 2)
comment|/* link is up */
define|#
directive|define
name|CAS_REG_PLUS
value|(1<< 3)
comment|/* has Cassini+ registers */
define|#
directive|define
name|CAS_SERDES
value|(1<< 4)
comment|/* use the SERDES */
define|#
directive|define
name|CAS_TABORT
value|(1<< 5)
comment|/* has target abort issues */
name|bus_dmamap_t
name|sc_cddmamap
decl_stmt|;
comment|/* control data DMA map */
name|bus_addr_t
name|sc_cddma
decl_stmt|;
comment|/* 	 * software state for transmit and receive descriptors 	 */
name|struct
name|cas_txsoft
name|sc_txsoft
index|[
name|CAS_TXQUEUELEN
index|]
decl_stmt|;
name|struct
name|cas_rxdsoft
name|sc_rxdsoft
index|[
name|CAS_NRXDESC
index|]
decl_stmt|;
comment|/* 	 * control data structures 	 */
name|struct
name|cas_control_data
modifier|*
name|sc_control_data
decl_stmt|;
define|#
directive|define
name|sc_txdescs
value|sc_control_data->ccd_txdescs
define|#
directive|define
name|sc_rxcomps
value|sc_control_data->ccd_rxcomps
define|#
directive|define
name|sc_rxdescs
value|sc_control_data->ccd_rxdescs
define|#
directive|define
name|sc_rxdescs2
value|sc_control_data->ccd_rxdescs2
name|u_int
name|sc_txfree
decl_stmt|;
comment|/* number of free TX descriptors */
name|u_int
name|sc_txnext
decl_stmt|;
comment|/* next ready TX descriptor */
name|u_int
name|sc_txwin
decl_stmt|;
comment|/* TX desc. since last TX intr. */
name|struct
name|cas_txsq
name|sc_txfreeq
decl_stmt|;
comment|/* free software TX descriptors */
name|struct
name|cas_txsq
name|sc_txdirtyq
decl_stmt|;
comment|/* dirty software TX descriptors */
name|u_int
name|sc_rxcptr
decl_stmt|;
comment|/* next ready RX completion */
name|u_int
name|sc_rxdptr
decl_stmt|;
comment|/* next ready RX descriptor */
name|int
name|sc_ifflags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAS_BARRIER
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
define|\
value|bus_barrier((sc)->sc_res[CAS_RES_MEM], (offs), (len), (flags))
end_define

begin_define
define|#
directive|define
name|CAS_READ_N
parameter_list|(
name|n
parameter_list|,
name|sc
parameter_list|,
name|offs
parameter_list|)
define|\
value|bus_read_ ## n((sc)->sc_res[CAS_RES_MEM], (offs))
end_define

begin_define
define|#
directive|define
name|CAS_READ_1
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|)
value|CAS_READ_N(1, (sc), (offs))
end_define

begin_define
define|#
directive|define
name|CAS_READ_2
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|)
value|CAS_READ_N(2, (sc), (offs))
end_define

begin_define
define|#
directive|define
name|CAS_READ_4
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|)
value|CAS_READ_N(4, (sc), (offs))
end_define

begin_define
define|#
directive|define
name|CAS_WRITE_N
parameter_list|(
name|n
parameter_list|,
name|sc
parameter_list|,
name|offs
parameter_list|,
name|v
parameter_list|)
define|\
value|bus_write_ ## n((sc)->sc_res[CAS_RES_MEM], (offs), (v))
end_define

begin_define
define|#
directive|define
name|CAS_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|,
name|v
parameter_list|)
value|CAS_WRITE_N(1, (sc), (offs), (v))
end_define

begin_define
define|#
directive|define
name|CAS_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|,
name|v
parameter_list|)
value|CAS_WRITE_N(2, (sc), (offs), (v))
end_define

begin_define
define|#
directive|define
name|CAS_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|offs
parameter_list|,
name|v
parameter_list|)
value|CAS_WRITE_N(4, (sc), (offs), (v))
end_define

begin_define
define|#
directive|define
name|CAS_CDTXDADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + CAS_CDTXDOFF((x)))
end_define

begin_define
define|#
directive|define
name|CAS_CDRXCADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + CAS_CDRXCOFF((x)))
end_define

begin_define
define|#
directive|define
name|CAS_CDRXDADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + CAS_CDRXDOFF((x)))
end_define

begin_define
define|#
directive|define
name|CAS_CDRXD2ADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + CAS_CDRXD2OFF((x)))
end_define

begin_define
define|#
directive|define
name|CAS_CDSYNC
parameter_list|(
name|sc
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_cdmatag, (sc)->sc_cddmamap, (ops));
end_define

begin_define
define|#
directive|define
name|__CAS_UPDATE_RXDESC
parameter_list|(
name|rxd
parameter_list|,
name|rxds
parameter_list|,
name|s
parameter_list|)
define|\
value|do {									\ 									\ 	refcount_init(&(rxds)->rxds_refcount, 1);			\ 	(rxd)->cd_buf_ptr = htole64((rxds)->rxds_paddr);		\ 	KASSERT((s)< CAS_RD_BUF_INDEX_MASK>> CAS_RD_BUF_INDEX_SHFT,	\ 	    ("%s: RX buffer index too large!", __func__));		\ 	(rxd)->cd_flags =						\ 	    htole64((uint64_t)((s)<< CAS_RD_BUF_INDEX_SHFT));		\ } while (0)
end_define

begin_define
define|#
directive|define
name|CAS_UPDATE_RXDESC
parameter_list|(
name|sc
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
define|\
value|__CAS_UPDATE_RXDESC(&(sc)->sc_rxdescs[(d)],			\&(sc)->sc_rxdsoft[(s)], (s))
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800016
end_if

begin_define
define|#
directive|define
name|CAS_INIT_RXDESC
parameter_list|(
name|sc
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
define|\
value|do {									\ 	struct cas_rxdsoft *__rxds =&(sc)->sc_rxdsoft[(s)];		\ 									\ 	__rxds->rxds_sc = (sc);						\ 	__rxds->rxds_idx = (s);						\ 	__CAS_UPDATE_RXDESC(&(sc)->sc_rxdescs[(d)], __rxds, (s));	\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CAS_INIT_RXDESC
parameter_list|(
name|sc
parameter_list|,
name|d
parameter_list|,
name|s
parameter_list|)
value|CAS_UPDATE_RXDESC(sc, d, s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CAS_LOCK_INIT
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
name|CAS_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CAS_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CAS_LOCK_ASSERT
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
name|CAS_LOCK_DESTROY
parameter_list|(
name|_sc
parameter_list|)
value|mtx_destroy(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|CAS_LOCK_OWNED
parameter_list|(
name|_sc
parameter_list|)
value|mtx_owned(&(_sc)->sc_mtx)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

