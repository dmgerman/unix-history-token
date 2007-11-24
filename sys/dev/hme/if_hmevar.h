begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Paul Kranenburg.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  *	from: NetBSD: hmevar.h,v 1.5 2000/06/25 01:10:04 eeh Exp  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/callout.h>
end_include

begin_comment
comment|/*  * Number of receive and transmit descriptors. For each receive descriptor,  * an mbuf cluster is allocated and set up to receive a packet, and a dma map  * is created. Therefore, this number should not be too high to not waste  * memory.  * TX descriptors have no static cost, except for the memory directly allocated  * for them. TX queue elements (the number of which is fixed by HME_NTXQ) hold  * the software state for a transmit job; each has a dmamap allocated for it.  * There may be multiple descriptors allocated to a single queue element.  * HME_NTXQ is completely arbitrary.  */
end_comment

begin_define
define|#
directive|define
name|HME_NRXDESC
value|128
end_define

begin_define
define|#
directive|define
name|HME_NTXDESC
value|128
end_define

begin_define
define|#
directive|define
name|HME_NTXQ
value|(HME_NTXDESC / 2)
end_define

begin_comment
comment|/* Maximum size of a mapped RX buffer. */
end_comment

begin_define
define|#
directive|define
name|HME_BUFSZ
value|1600
end_define

begin_comment
comment|/*  * RX DMA descriptor. The descriptors are preallocated; the dma map is  * reused.  */
end_comment

begin_struct
struct|struct
name|hme_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|hrx_m
decl_stmt|;
name|bus_dmamap_t
name|hrx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Lazily leave at least one burst size grace space. */
end_comment

begin_define
define|#
directive|define
name|HME_DESC_RXLEN
parameter_list|(
name|sc
parameter_list|,
name|d
parameter_list|)
define|\
value|ulmin(HME_BUFSZ, (d)->hrx_m->m_len - (sc)->sc_burst)
end_define

begin_struct
struct|struct
name|hme_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|htx_m
decl_stmt|;
name|bus_dmamap_t
name|htx_dmamap
decl_stmt|;
name|int
name|htx_lastdesc
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|hme_txdesc
argument_list|)
name|htx_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|hme_txdq
argument_list|,
name|hme_txdesc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Value for htx_flags */
end_comment

begin_define
define|#
directive|define
name|HTXF_MAPPED
value|1
end_define

begin_struct
struct|struct
name|hme_ring
block|{
comment|/* Ring Descriptors */
name|caddr_t
name|rb_membase
decl_stmt|;
comment|/* Packet buffer: CPU address */
name|bus_addr_t
name|rb_dmabase
decl_stmt|;
comment|/* Packet buffer: DMA address */
name|caddr_t
name|rb_txd
decl_stmt|;
comment|/* Transmit descriptors */
name|bus_addr_t
name|rb_txddma
decl_stmt|;
comment|/* DMA address of same */
name|caddr_t
name|rb_rxd
decl_stmt|;
comment|/* Receive descriptors */
name|bus_addr_t
name|rb_rxddma
decl_stmt|;
comment|/* DMA address of same */
comment|/* Ring Descriptor state */
name|int
name|rb_tdhead
decl_stmt|,
name|rb_tdtail
decl_stmt|;
name|int
name|rb_rdtail
decl_stmt|;
name|int
name|rb_td_nbusy
decl_stmt|;
comment|/* Descriptors */
name|struct
name|hme_rxdesc
name|rb_rxdesc
index|[
name|HME_NRXDESC
index|]
decl_stmt|;
name|struct
name|hme_txdesc
name|rb_txdesc
index|[
name|HME_NTXQ
index|]
decl_stmt|;
name|bus_dma_segment_t
name|rb_txsegs
index|[
name|HME_NTXQ
index|]
decl_stmt|;
name|struct
name|hme_txdq
name|rb_txfreeq
decl_stmt|;
name|struct
name|hme_txdq
name|rb_txbusyq
decl_stmt|;
name|bus_dmamap_t
name|rb_spare_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hme_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
name|struct
name|ifmedia
name|sc_ifmedia
decl_stmt|;
name|device_t
name|sc_dev
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
name|int
name|sc_wdog_timer
decl_stmt|;
comment|/* watchdog timer */
comment|/* The following bus handles are to be provided by the bus front-end */
name|bus_dma_tag_t
name|sc_pdmatag
decl_stmt|;
comment|/* bus dma parent tag */
name|bus_dma_tag_t
name|sc_cdmatag
decl_stmt|;
comment|/* control bus dma tag */
name|bus_dmamap_t
name|sc_cdmamap
decl_stmt|;
comment|/* control bus dma handle */
name|bus_dma_tag_t
name|sc_rdmatag
decl_stmt|;
comment|/* RX bus dma tag */
name|bus_dma_tag_t
name|sc_tdmatag
decl_stmt|;
comment|/* RX bus dma tag */
name|bus_space_handle_t
name|sc_sebh
decl_stmt|;
comment|/* HME Global registers */
name|bus_space_handle_t
name|sc_erxh
decl_stmt|;
comment|/* HME ERX registers */
name|bus_space_handle_t
name|sc_etxh
decl_stmt|;
comment|/* HME ETX registers */
name|bus_space_handle_t
name|sc_mach
decl_stmt|;
comment|/* HME MAC registers */
name|bus_space_handle_t
name|sc_mifh
decl_stmt|;
comment|/* HME MIF registers */
name|bus_space_tag_t
name|sc_sebt
decl_stmt|;
comment|/* HME Global registers */
name|bus_space_tag_t
name|sc_erxt
decl_stmt|;
comment|/* HME ERX registers */
name|bus_space_tag_t
name|sc_etxt
decl_stmt|;
comment|/* HME ETX registers */
name|bus_space_tag_t
name|sc_mact
decl_stmt|;
comment|/* HME MAC registers */
name|bus_space_tag_t
name|sc_mift
decl_stmt|;
comment|/* HME MIF registers */
name|int
name|sc_burst
decl_stmt|;
comment|/* DVMA burst size in effect */
name|int
name|sc_phys
index|[
literal|2
index|]
decl_stmt|;
comment|/* MII instance -> PHY map */
name|int
name|sc_pci
decl_stmt|;
comment|/* XXXXX -- PCI buses are LE. */
name|int
name|sc_csum_features
decl_stmt|;
comment|/* Ring descriptor */
name|struct
name|hme_ring
name|sc_rb
decl_stmt|;
name|int
name|sc_debug
decl_stmt|;
name|struct
name|mtx
name|sc_lock
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|HME_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|HME_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|HME_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|,
name|_what
parameter_list|)
value|mtx_assert(&(_sc)->sc_lock, (_what))
end_define

begin_decl_stmt
specifier|extern
name|devclass_t
name|hme_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|hme_config
parameter_list|(
name|struct
name|hme_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hme_detach
parameter_list|(
name|struct
name|hme_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hme_suspend
parameter_list|(
name|struct
name|hme_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hme_resume
parameter_list|(
name|struct
name|hme_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hme_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MII methods& callbacks */
end_comment

begin_function_decl
name|int
name|hme_mii_readreg
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
name|hme_mii_writereg
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
name|hme_mii_statchg
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

