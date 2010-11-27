begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: if_admswvar.h,v 1.1 2007/03/20 08:52:02 dyoung Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2007 Ruslan Ermilov and Vsevolod Lobko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or  * without modification, are permitted provided that the following  * conditions are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above  *    copyright notice, this list of conditions and the following  *    disclaimer in the documentation and/or other materials provided  *    with the distribution.  * 3. The names of the authors may not be used to endorse or promote  *    products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,  * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A  * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR  * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY  * OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_ADMSWVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_IF_ADMSWVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/if_mib.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/bpfdesc.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_include
include|#
directive|include
file|<mips/adm5120/adm5120reg.h>
end_include

begin_include
include|#
directive|include
file|<mips/adm5120/if_admswreg.h>
end_include

begin_define
define|#
directive|define
name|MAC_BUFLEN
value|0x07ff
end_define

begin_define
define|#
directive|define
name|ADMSW_NTXHDESC
value|4
end_define

begin_define
define|#
directive|define
name|ADMSW_NRXHDESC
value|32
end_define

begin_define
define|#
directive|define
name|ADMSW_NTXLDESC
value|32
end_define

begin_define
define|#
directive|define
name|ADMSW_NRXLDESC
value|32
end_define

begin_define
define|#
directive|define
name|ADMSW_NTXHDESC_MASK
value|(ADMSW_NTXHDESC - 1)
end_define

begin_define
define|#
directive|define
name|ADMSW_NRXHDESC_MASK
value|(ADMSW_NRXHDESC - 1)
end_define

begin_define
define|#
directive|define
name|ADMSW_NTXLDESC_MASK
value|(ADMSW_NTXLDESC - 1)
end_define

begin_define
define|#
directive|define
name|ADMSW_NRXLDESC_MASK
value|(ADMSW_NRXLDESC - 1)
end_define

begin_define
define|#
directive|define
name|ADMSW_NEXTTXH
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)& ADMSW_NTXHDESC_MASK)
end_define

begin_define
define|#
directive|define
name|ADMSW_NEXTRXH
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)& ADMSW_NRXHDESC_MASK)
end_define

begin_define
define|#
directive|define
name|ADMSW_NEXTTXL
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)& ADMSW_NTXLDESC_MASK)
end_define

begin_define
define|#
directive|define
name|ADMSW_NEXTRXL
parameter_list|(
name|x
parameter_list|)
value|(((x) + 1)& ADMSW_NRXLDESC_MASK)
end_define

begin_define
define|#
directive|define
name|ADMSW_IRQ
value|9
end_define

begin_struct
struct|struct
name|admsw_control_data
block|{
comment|/* The transmit descriptors. */
name|struct
name|admsw_desc
name|acd_txhdescs
index|[
name|ADMSW_NTXHDESC
index|]
decl_stmt|;
comment|/* The receive descriptors. */
name|struct
name|admsw_desc
name|acd_rxhdescs
index|[
name|ADMSW_NRXHDESC
index|]
decl_stmt|;
comment|/* The transmit descriptors. */
name|struct
name|admsw_desc
name|acd_txldescs
index|[
name|ADMSW_NTXLDESC
index|]
decl_stmt|;
comment|/* The receive descriptors. */
name|struct
name|admsw_desc
name|acd_rxldescs
index|[
name|ADMSW_NRXLDESC
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADMSW_CDOFF
parameter_list|(
name|x
parameter_list|)
value|offsetof(struct admsw_control_data, x)
end_define

begin_define
define|#
directive|define
name|ADMSW_CDTXHOFF
parameter_list|(
name|x
parameter_list|)
value|ADMSW_CDOFF(acd_txhdescs[(x)])
end_define

begin_define
define|#
directive|define
name|ADMSW_CDTXLOFF
parameter_list|(
name|x
parameter_list|)
value|ADMSW_CDOFF(acd_txldescs[(x)])
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXHOFF
parameter_list|(
name|x
parameter_list|)
value|ADMSW_CDOFF(acd_rxhdescs[(x)])
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXLOFF
parameter_list|(
name|x
parameter_list|)
value|ADMSW_CDOFF(acd_rxldescs[(x)])
end_define

begin_struct
struct|struct
name|admsw_descsoft
block|{
name|struct
name|mbuf
modifier|*
name|ds_mbuf
decl_stmt|;
name|bus_dmamap_t
name|ds_dmamap
decl_stmt|;
comment|/* Up to 2 segments */
name|uint32_t
name|ds_addr
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ds_len
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|ds_nsegs
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|admsw_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* generic device information */
name|uint8_t
name|sc_enaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|bus_dma_tag_t
name|sc_control_dmat
decl_stmt|;
comment|/* bus DMA tag for control structs*/
name|bus_dma_tag_t
name|sc_bufs_dmat
decl_stmt|;
comment|/* bus DMA tag for buffers */
name|struct
name|ifmedia
name|sc_ifmedia
index|[
name|SW_DEVS
index|]
decl_stmt|;
name|int
name|ndevs
decl_stmt|;
comment|/* number of IFF_RUNNING interfaces */
name|struct
name|ifnet
modifier|*
name|sc_ifnet
index|[
name|SW_DEVS
index|]
decl_stmt|;
name|struct
name|callout
name|sc_watchdog
decl_stmt|;
name|int
name|sc_timer
decl_stmt|;
comment|/* Ethernet common data */
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt cookie */
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|bus_dmamap_t
name|sc_cddmamap
decl_stmt|;
comment|/* control data DMA map */
name|uint32_t
name|sc_cddma
decl_stmt|;
name|struct
name|admsw_control_data
modifier|*
name|sc_control_data
decl_stmt|;
name|struct
name|admsw_descsoft
name|sc_txhsoft
index|[
name|ADMSW_NTXHDESC
index|]
decl_stmt|;
name|struct
name|admsw_descsoft
name|sc_rxhsoft
index|[
name|ADMSW_NRXHDESC
index|]
decl_stmt|;
name|struct
name|admsw_descsoft
name|sc_txlsoft
index|[
name|ADMSW_NTXLDESC
index|]
decl_stmt|;
name|struct
name|admsw_descsoft
name|sc_rxlsoft
index|[
name|ADMSW_NRXLDESC
index|]
decl_stmt|;
define|#
directive|define
name|sc_txhdescs
value|sc_control_data->acd_txhdescs
define|#
directive|define
name|sc_rxhdescs
value|sc_control_data->acd_rxhdescs
define|#
directive|define
name|sc_txldescs
value|sc_control_data->acd_txldescs
define|#
directive|define
name|sc_rxldescs
value|sc_control_data->acd_rxldescs
name|int
name|sc_txfree
decl_stmt|;
comment|/* number of free Tx descriptors */
name|int
name|sc_txnext
decl_stmt|;
comment|/* next Tx descriptor to use */
name|int
name|sc_txdirty
decl_stmt|;
comment|/* first dirty Tx descriptor */
name|int
name|sc_rxptr
decl_stmt|;
comment|/* next ready Rx descriptor */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADMSW_CDTXHADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + ADMSW_CDTXHOFF((x)))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDTXLADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + ADMSW_CDTXLOFF((x)))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXHADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + ADMSW_CDRXHOFF((x)))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXLADDR
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
value|((sc)->sc_cddma + ADMSW_CDRXLOFF((x)))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDTXHSYNC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_control_dmat, (sc)->sc_cddmamap, (ops))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDTXLSYNC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_control_dmat, (sc)->sc_cddmamap, (ops))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXHSYNC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_control_dmat, (sc)->sc_cddmamap, (ops))
end_define

begin_define
define|#
directive|define
name|ADMSW_CDRXLSYNC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|,
name|ops
parameter_list|)
define|\
value|bus_dmamap_sync((sc)->sc_control_dmat, (sc)->sc_cddmamap, (ops))
end_define

begin_define
define|#
directive|define
name|ADMSW_INIT_RXHDESC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|do {								\ 	struct admsw_descsoft *__ds =&(sc)->sc_rxhsoft[(x)];	\ 	struct admsw_desc *__desc =&(sc)->sc_rxhdescs[(x)];	\ 	struct mbuf *__m = __ds->ds_mbuf;			\ 								\ 	__m->m_data = __m->m_ext.ext_buf + 2;			\ 	__desc->data = __ds->ds_addr[0] + 2;	\ 	__desc->cntl = 0;					\ 	__desc->len = min(MCLBYTES - 2, MAC_BUFLEN - 2);	\ 	__desc->status = 0;					\ 	if ((x) == ADMSW_NRXHDESC - 1)				\ 		__desc->data |= ADM5120_DMA_RINGEND;		\ 	__desc->data |= ADM5120_DMA_OWN;			\ 	ADMSW_CDRXHSYNC((sc), (x), BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE); \ } while (0)
end_define

begin_define
define|#
directive|define
name|ADMSW_INIT_RXLDESC
parameter_list|(
name|sc
parameter_list|,
name|x
parameter_list|)
define|\
value|do {								\ 	struct admsw_descsoft *__ds =&(sc)->sc_rxlsoft[(x)];	\ 	struct admsw_desc *__desc =&(sc)->sc_rxldescs[(x)];	\ 	struct mbuf *__m = __ds->ds_mbuf;			\ 								\ 	__m->m_data = __m->m_ext.ext_buf + 2;			\ 	__desc->data = __ds->ds_addr[0] + 2;	\ 	__desc->cntl = 0;					\ 	__desc->len = min(MCLBYTES - 2, MAC_BUFLEN - 2);	\ 	__desc->status = 0;					\ 	if ((x) == ADMSW_NRXLDESC - 1)				\ 		__desc->data |= ADM5120_DMA_RINGEND;		\ 	__desc->data |= ADM5120_DMA_OWN;			\ 	ADMSW_CDRXLSYNC((sc), (x), BUS_DMASYNC_PREREAD|BUS_DMASYNC_PREWRITE); \ } while (0)
end_define

begin_function_decl
name|void
name|admwdog_attach
parameter_list|(
name|struct
name|admsw_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IF_ADMSWVAR_H_ */
end_comment

end_unit

