begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Chelsio Communications, Inc.  * All rights reserved.  * Written by: Navdeep Parhar<np@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__T4_ADAPTER_H__
end_ifndef

begin_define
define|#
directive|define
name|__T4_ADAPTER_H__
end_define

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
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
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<netinet/tcp_lro.h>
end_include

begin_include
include|#
directive|include
file|"offload.h"
end_include

begin_include
include|#
directive|include
file|"firmware/t4fw_interface.h"
end_include

begin_define
define|#
directive|define
name|T4_CFGNAME
value|"t4fw_cfg"
end_define

begin_define
define|#
directive|define
name|T4_FWNAME
value|"t4fw"
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CXGBE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|CXGBE_UNIMPLEMENTED
parameter_list|(
name|s
parameter_list|)
define|\
value|panic("%s (%s, line %d) not implemented yet.", s, __FILE__, __LINE__)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|prefetch
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SYSCTL_ADD_UQUAD
end_ifndef

begin_define
define|#
directive|define
name|SYSCTL_ADD_UQUAD
value|SYSCTL_ADD_QUAD
end_define

begin_define
define|#
directive|define
name|sysctl_handle_64
value|sysctl_handle_quad
end_define

begin_define
define|#
directive|define
name|CTLTYPE_U64
value|CTLTYPE_QUAD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|900030
operator|)
operator|||
expr|\
operator|(
operator|(
name|__FreeBSD_version
operator|>=
literal|802507
operator|)
operator|&&
operator|(
name|__FreeBSD_version
operator|<
literal|900000
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|SBUF_DRAIN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_comment
comment|/* XXX: need systemwide bus_space_read_8/bus_space_write_8 */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|t4_bus_space_read_8
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|tag
operator|==
name|AMD64_BUS_SPACE_MEM
argument_list|,
operator|(
literal|"%s: can only handle mem space"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
operator|*
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|handle
operator|+
name|offset
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|t4_bus_space_write_8
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|tag
operator|==
name|AMD64_BUS_SPACE_MEM
argument_list|,
operator|(
literal|"%s: can only handle mem space"
operator|,
name|__func__
operator|)
argument_list|)
expr_stmt|;
operator|*
operator|(
specifier|volatile
name|uint64_t
operator|*
operator|)
operator|(
name|bsh
operator|+
name|offset
operator|)
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
name|__inline
name|uint64_t
name|t4_bus_space_read_8
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|handle
parameter_list|,
name|bus_size_t
name|offset
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|bus_space_read_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
name|offset
argument_list|)
operator|+
operator|(
operator|(
name|uint64_t
operator|)
name|bus_space_read_4
argument_list|(
name|tag
argument_list|,
name|handle
argument_list|,
name|offset
operator|+
literal|4
argument_list|)
operator|<<
literal|32
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|t4_bus_space_write_8
parameter_list|(
name|bus_space_tag_t
name|tag
parameter_list|,
name|bus_space_handle_t
name|bsh
parameter_list|,
name|bus_size_t
name|offset
parameter_list|,
name|uint64_t
name|value
parameter_list|)
block|{
name|bus_space_write_4
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
argument_list|,
name|value
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|tag
argument_list|,
name|bsh
argument_list|,
name|offset
operator|+
literal|4
argument_list|,
name|value
operator|>>
literal|32
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|adapter
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|adapter
name|adapter_t
typedef|;
end_typedef

begin_enum
enum|enum
block|{
name|FW_IQ_QSIZE
init|=
literal|256
block|,
name|FW_IQ_ESIZE
init|=
literal|64
block|,
comment|/* At least 64 mandated by the firmware spec */
name|RX_IQ_QSIZE
init|=
literal|1024
block|,
name|RX_IQ_ESIZE
init|=
literal|64
block|,
comment|/* At least 64 so CPL_RX_PKT will fit */
name|EQ_ESIZE
init|=
literal|64
block|,
comment|/* All egress queues use this entry size */
name|RX_FL_ESIZE
init|=
name|EQ_ESIZE
block|,
comment|/* 8 64bit addresses */
if|#
directive|if
name|MJUMPAGESIZE
operator|!=
name|MCLBYTES
name|FL_BUF_SIZES
init|=
literal|4
block|,
comment|/* cluster, jumbop, jumbo9k, jumbo16k */
else|#
directive|else
name|FL_BUF_SIZES
init|=
literal|3
block|,
comment|/* cluster, jumbo9k, jumbo16k */
endif|#
directive|endif
name|CTRL_EQ_QSIZE
init|=
literal|128
block|,
name|TX_EQ_QSIZE
init|=
literal|1024
block|,
name|TX_SGL_SEGS
init|=
literal|36
block|,
name|TX_WR_FLITS
init|=
name|SGE_MAX_WR_LEN
operator|/
literal|8
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* adapter intr_type */
name|INTR_INTX
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|INTR_MSI
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|INTR_MSIX
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* adapter flags */
name|FULL_INIT_DONE
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|FW_OK
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|INTR_DIRECT
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* direct interrupts for everything */
name|MASTER_PF
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
name|ADAP_SYSCTL_CTX
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
name|CXGBE_BUSY
init|=
operator|(
literal|1
operator|<<
literal|9
operator|)
block|,
comment|/* port flags */
name|DOOMED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
name|PORT_INIT_DONE
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
name|PORT_SYSCTL_CTX
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|IS_DOOMED
parameter_list|(
name|pi
parameter_list|)
value|(pi->flags& DOOMED)
end_define

begin_define
define|#
directive|define
name|SET_DOOMED
parameter_list|(
name|pi
parameter_list|)
value|do {pi->flags |= DOOMED;} while (0)
end_define

begin_define
define|#
directive|define
name|IS_BUSY
parameter_list|(
name|sc
parameter_list|)
value|(sc->flags& CXGBE_BUSY)
end_define

begin_define
define|#
directive|define
name|SET_BUSY
parameter_list|(
name|sc
parameter_list|)
value|do {sc->flags |= CXGBE_BUSY;} while (0)
end_define

begin_define
define|#
directive|define
name|CLR_BUSY
parameter_list|(
name|sc
parameter_list|)
value|do {sc->flags&= ~CXGBE_BUSY;} while (0)
end_define

begin_struct
struct|struct
name|port_info
block|{
name|device_t
name|dev
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
name|struct
name|ifmedia
name|media
decl_stmt|;
name|struct
name|mtx
name|pi_lock
decl_stmt|;
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|int
name|if_flags
decl_stmt|;
name|uint16_t
name|viid
decl_stmt|;
name|int16_t
name|xact_addr_filt
decl_stmt|;
comment|/* index of exact MAC address filter */
name|uint16_t
name|rss_size
decl_stmt|;
comment|/* size of VI's RSS table slice */
name|uint8_t
name|lport
decl_stmt|;
comment|/* associated offload logical port */
name|int8_t
name|mdio_addr
decl_stmt|;
name|uint8_t
name|port_type
decl_stmt|;
name|uint8_t
name|mod_type
decl_stmt|;
name|uint8_t
name|port_id
decl_stmt|;
name|uint8_t
name|tx_chan
decl_stmt|;
comment|/* These need to be int as they are used in sysctl */
name|int
name|ntxq
decl_stmt|;
comment|/* # of tx queues */
name|int
name|first_txq
decl_stmt|;
comment|/* index of first tx queue */
name|int
name|nrxq
decl_stmt|;
comment|/* # of rx queues */
name|int
name|first_rxq
decl_stmt|;
comment|/* index of first rx queue */
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|int
name|nofldtxq
decl_stmt|;
comment|/* # of offload tx queues */
name|int
name|first_ofld_txq
decl_stmt|;
comment|/* index of first offload tx queue */
name|int
name|nofldrxq
decl_stmt|;
comment|/* # of offload rx queues */
name|int
name|first_ofld_rxq
decl_stmt|;
comment|/* index of first offload rx queue */
endif|#
directive|endif
name|int
name|tmr_idx
decl_stmt|;
name|int
name|pktc_idx
decl_stmt|;
name|int
name|qsize_rxq
decl_stmt|;
name|int
name|qsize_txq
decl_stmt|;
name|struct
name|link_config
name|link_cfg
decl_stmt|;
name|struct
name|port_stats
name|stats
decl_stmt|;
name|struct
name|callout
name|tick
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
comment|/* from ifconfig up to driver detach */
name|uint8_t
name|hw_addr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
comment|/* factory MAC address, won't change */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fl_sdesc
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|caddr_t
name|cl
decl_stmt|;
name|uint8_t
name|tag_idx
decl_stmt|;
comment|/* the sc->fl_tag this map comes from */
ifdef|#
directive|ifdef
name|INVARIANTS
name|__be64
name|ba_tag
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tx_desc
block|{
name|__be64
name|flit
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tx_map
block|{
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* DMA maps used for tx */
end_comment

begin_struct
struct|struct
name|tx_maps
block|{
name|struct
name|tx_map
modifier|*
name|maps
decl_stmt|;
name|uint32_t
name|map_total
decl_stmt|;
comment|/* # of DMA maps */
name|uint32_t
name|map_pidx
decl_stmt|;
comment|/* next map to be used */
name|uint32_t
name|map_cidx
decl_stmt|;
comment|/* reclaimed up to this index */
name|uint32_t
name|map_avail
decl_stmt|;
comment|/* # of available maps */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tx_sdesc
block|{
name|uint8_t
name|desc_used
decl_stmt|;
comment|/* # of hardware descriptors used by the WR */
name|uint8_t
name|credits
decl_stmt|;
comment|/* NIC txq: # of frames sent out in the WR */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
comment|/* iq flags */
name|IQ_ALLOCATED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/* firmware resources allocated */
name|IQ_HAS_FL
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* iq associated with a freelist */
name|IQ_INTR
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* iq takes direct interrupt */
name|IQ_LRO_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/* iq is an eth rxq with LRO enabled */
comment|/* iq state */
name|IQS_DISABLED
init|=
literal|0
block|,
name|IQS_BUSY
init|=
literal|1
block|,
name|IQS_IDLE
init|=
literal|2
block|, }
enum|;
end_enum

begin_comment
comment|/*  * Ingress Queue: T4 is producer, driver is consumer.  */
end_comment

begin_struct
struct|struct
name|sge_iq
block|{
name|bus_dma_tag_t
name|desc_tag
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_addr_t
name|ba
decl_stmt|;
comment|/* bus address of descriptor ring */
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|flags
decl_stmt|;
name|uint16_t
name|abs_id
decl_stmt|;
comment|/* absolute SGE id for the iq */
name|int8_t
name|intr_pktc_idx
decl_stmt|;
comment|/* packet count threshold index */
name|int8_t
name|pad0
decl_stmt|;
name|__be64
modifier|*
name|desc
decl_stmt|;
comment|/* KVA of descriptor ring */
specifier|volatile
name|int
name|state
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
specifier|const
name|__be64
modifier|*
name|cdesc
decl_stmt|;
comment|/* current descriptor */
name|uint8_t
name|gen
decl_stmt|;
comment|/* generation bit */
name|uint8_t
name|intr_params
decl_stmt|;
comment|/* interrupt holdoff parameters */
name|uint8_t
name|intr_next
decl_stmt|;
comment|/* XXX: holdoff for next interrupt */
name|uint8_t
name|esize
decl_stmt|;
comment|/* size (bytes) of each entry in the queue */
name|uint16_t
name|qsize
decl_stmt|;
comment|/* size (# of entries) of the queue */
name|uint16_t
name|cidx
decl_stmt|;
comment|/* consumer index */
name|uint16_t
name|cntxt_id
decl_stmt|;
comment|/* SGE context id for the iq */
name|STAILQ_ENTRY
argument_list|(
argument|sge_iq
argument_list|)
name|link
expr_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|EQ_CTRL
init|=
literal|1
block|,
name|EQ_ETH
init|=
literal|2
block|,
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|EQ_OFLD
init|=
literal|3
block|,
endif|#
directive|endif
comment|/* eq flags */
name|EQ_TYPEMASK
init|=
literal|7
block|,
comment|/* 3 lsbits hold the type */
name|EQ_ALLOCATED
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/* firmware resources allocated */
name|EQ_DOOMED
init|=
operator|(
literal|1
operator|<<
literal|4
operator|)
block|,
comment|/* about to be destroyed */
name|EQ_CRFLUSHED
init|=
operator|(
literal|1
operator|<<
literal|5
operator|)
block|,
comment|/* expecting an update from SGE */
name|EQ_STALLED
init|=
operator|(
literal|1
operator|<<
literal|6
operator|)
block|,
comment|/* out of hw descriptors or dmamaps */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Egress Queue: driver is producer, T4 is consumer.  *  * Note: A free list is an egress queue (driver produces the buffers and T4  * consumes them) but it's special enough to have its own struct (see sge_fl).  */
end_comment

begin_struct
struct|struct
name|sge_eq
block|{
name|unsigned
name|int
name|flags
decl_stmt|;
comment|/* MUST be first */
name|unsigned
name|int
name|cntxt_id
decl_stmt|;
comment|/* SGE context id for the eq */
name|bus_dma_tag_t
name|desc_tag
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
name|struct
name|mtx
name|eq_lock
decl_stmt|;
name|struct
name|tx_desc
modifier|*
name|desc
decl_stmt|;
comment|/* KVA of descriptor ring */
name|bus_addr_t
name|ba
decl_stmt|;
comment|/* bus address of descriptor ring */
name|struct
name|sge_qstat
modifier|*
name|spg
decl_stmt|;
comment|/* status page, for convenience */
name|uint16_t
name|cap
decl_stmt|;
comment|/* max # of desc, for convenience */
name|uint16_t
name|avail
decl_stmt|;
comment|/* available descriptors, for convenience */
name|uint16_t
name|qsize
decl_stmt|;
comment|/* size (# of entries) of the queue */
name|uint16_t
name|cidx
decl_stmt|;
comment|/* consumer idx (desc idx) */
name|uint16_t
name|pidx
decl_stmt|;
comment|/* producer idx (desc idx) */
name|uint16_t
name|pending
decl_stmt|;
comment|/* # of descriptors used since last doorbell */
name|uint16_t
name|iqid
decl_stmt|;
comment|/* iq that gets egr_update for the eq */
name|uint8_t
name|tx_chan
decl_stmt|;
comment|/* tx channel used by the eq */
name|struct
name|task
name|tx_task
decl_stmt|;
name|struct
name|callout
name|tx_callout
decl_stmt|;
comment|/* stats */
name|uint32_t
name|egr_update
decl_stmt|;
comment|/* # of SGE_EGR_UPDATE notifications for eq */
name|uint32_t
name|unstalled
decl_stmt|;
comment|/* recovered from stall */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|FL_STARVING
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|,
comment|/* on the adapter's list of starving fl's */
name|FL_DOOMED
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* about to be destroyed */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|FL_RUNNING_LOW
parameter_list|(
name|fl
parameter_list|)
value|(fl->cap - fl->needed<= fl->lowat)
end_define

begin_define
define|#
directive|define
name|FL_NOT_RUNNING_LOW
parameter_list|(
name|fl
parameter_list|)
value|(fl->cap - fl->needed>= 2 * fl->lowat)
end_define

begin_struct
struct|struct
name|sge_fl
block|{
name|bus_dma_tag_t
name|desc_tag
decl_stmt|;
name|bus_dmamap_t
name|desc_map
decl_stmt|;
name|bus_dma_tag_t
name|tag
index|[
name|FL_BUF_SIZES
index|]
decl_stmt|;
name|uint8_t
name|tag_idx
decl_stmt|;
name|struct
name|mtx
name|fl_lock
decl_stmt|;
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|__be64
modifier|*
name|desc
decl_stmt|;
comment|/* KVA of descriptor ring, ptr to addresses */
name|bus_addr_t
name|ba
decl_stmt|;
comment|/* bus address of descriptor ring */
name|struct
name|fl_sdesc
modifier|*
name|sdesc
decl_stmt|;
comment|/* KVA of software descriptor ring */
name|uint32_t
name|cap
decl_stmt|;
comment|/* max # of buffers, for convenience */
name|uint16_t
name|qsize
decl_stmt|;
comment|/* size (# of entries) of the queue */
name|uint16_t
name|cntxt_id
decl_stmt|;
comment|/* SGE context id for the freelist */
name|uint32_t
name|cidx
decl_stmt|;
comment|/* consumer idx (buffer idx, NOT hw desc idx) */
name|uint32_t
name|pidx
decl_stmt|;
comment|/* producer idx (buffer idx, NOT hw desc idx) */
name|uint32_t
name|needed
decl_stmt|;
comment|/* # of buffers needed to fill up fl. */
name|uint32_t
name|lowat
decl_stmt|;
comment|/* # of buffers<= this means fl needs help */
name|uint32_t
name|pending
decl_stmt|;
comment|/* # of bufs allocated since last doorbell */
name|unsigned
name|int
name|dmamap_failed
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|sge_fl
argument_list|)
name|link
expr_stmt|;
comment|/* All starving freelists */
block|}
struct|;
end_struct

begin_comment
comment|/* txq: SGE egress queue + what's needed for Ethernet NIC */
end_comment

begin_struct
struct|struct
name|sge_txq
block|{
name|struct
name|sge_eq
name|eq
decl_stmt|;
comment|/* MUST be first */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* the interface this txq belongs to */
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
comment|/* tag for transmit buffers */
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* tx buffer ring */
name|struct
name|tx_sdesc
modifier|*
name|sdesc
decl_stmt|;
comment|/* KVA of software descriptor ring */
name|struct
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* held up due to temporary resource shortage */
name|struct
name|tx_maps
name|txmaps
decl_stmt|;
comment|/* stats for common events first */
name|uint64_t
name|txcsum
decl_stmt|;
comment|/* # of times hardware assisted with checksum */
name|uint64_t
name|tso_wrs
decl_stmt|;
comment|/* # of IPv4 TSO work requests */
name|uint64_t
name|vlan_insertion
decl_stmt|;
comment|/* # of times VLAN tag was inserted */
name|uint64_t
name|imm_wrs
decl_stmt|;
comment|/* # of work requests with immediate data */
name|uint64_t
name|sgl_wrs
decl_stmt|;
comment|/* # of work requests with direct SGL */
name|uint64_t
name|txpkt_wrs
decl_stmt|;
comment|/* # of txpkt work requests (not coalesced) */
name|uint64_t
name|txpkts_wrs
decl_stmt|;
comment|/* # of coalesced tx work requests */
name|uint64_t
name|txpkts_pkts
decl_stmt|;
comment|/* # of frames in coalesced tx work requests */
comment|/* stats for not-that-common events */
name|uint32_t
name|no_dmamap
decl_stmt|;
comment|/* no DMA map to load the mbuf */
name|uint32_t
name|no_desc
decl_stmt|;
comment|/* out of hardware descriptors */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_comment
comment|/* rxq: SGE ingress queue + SGE free list + miscellaneous items */
end_comment

begin_struct
struct|struct
name|sge_rxq
block|{
name|struct
name|sge_iq
name|iq
decl_stmt|;
comment|/* MUST be first */
name|struct
name|sge_fl
name|fl
decl_stmt|;
comment|/* MUST follow iq */
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* the interface this rxq belongs to */
ifdef|#
directive|ifdef
name|INET
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
comment|/* LRO state */
endif|#
directive|endif
comment|/* stats for common events first */
name|uint64_t
name|rxcsum
decl_stmt|;
comment|/* # of times hardware assisted with checksum */
name|uint64_t
name|vlan_extraction
decl_stmt|;
comment|/* # of times VLAN tag was extracted */
comment|/* stats for not-that-common events */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
end_ifndef

begin_comment
comment|/* ofld_rxq: SGE ingress queue + SGE free list + miscellaneous items */
end_comment

begin_struct
struct|struct
name|sge_ofld_rxq
block|{
name|struct
name|sge_iq
name|iq
decl_stmt|;
comment|/* MUST be first */
name|struct
name|sge_fl
name|fl
decl_stmt|;
comment|/* MUST follow iq */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * wrq: SGE egress queue that is given prebuilt work requests.  Both the control  * and offload tx queues are of this type.  */
end_comment

begin_struct
struct|struct
name|sge_wrq
block|{
name|struct
name|sge_eq
name|eq
decl_stmt|;
comment|/* MUST be first */
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|head
decl_stmt|;
comment|/* held up due to lack of descriptors */
name|struct
name|mbuf
modifier|*
name|tail
decl_stmt|;
comment|/* valid only if head is valid */
comment|/* stats for common events first */
name|uint64_t
name|tx_wrs
decl_stmt|;
comment|/* # of tx work requests */
comment|/* stats for not-that-common events */
name|uint32_t
name|no_desc
decl_stmt|;
comment|/* out of hardware descriptors */
block|}
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|sge
block|{
name|int
name|timer_val
index|[
name|SGE_NTIMERS
index|]
decl_stmt|;
name|int
name|counter_val
index|[
name|SGE_NCOUNTERS
index|]
decl_stmt|;
name|int
name|fl_starve_threshold
decl_stmt|;
name|int
name|nrxq
decl_stmt|;
comment|/* total # of Ethernet rx queues */
name|int
name|ntxq
decl_stmt|;
comment|/* total # of Ethernet tx tx queues */
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|int
name|nofldrxq
decl_stmt|;
comment|/* total # of TOE rx queues */
name|int
name|nofldtxq
decl_stmt|;
comment|/* total # of TOE tx queues */
endif|#
directive|endif
name|int
name|niq
decl_stmt|;
comment|/* total # of ingress queues */
name|int
name|neq
decl_stmt|;
comment|/* total # of egress queues */
name|struct
name|sge_iq
name|fwq
decl_stmt|;
comment|/* Firmware event queue */
name|struct
name|sge_wrq
name|mgmtq
decl_stmt|;
comment|/* Management queue (control queue) */
name|struct
name|sge_wrq
modifier|*
name|ctrlq
decl_stmt|;
comment|/* Control queues */
name|struct
name|sge_txq
modifier|*
name|txq
decl_stmt|;
comment|/* NIC tx queues */
name|struct
name|sge_rxq
modifier|*
name|rxq
decl_stmt|;
comment|/* NIC rx queues */
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|struct
name|sge_wrq
modifier|*
name|ofld_txq
decl_stmt|;
comment|/* TOE tx queues */
name|struct
name|sge_ofld_rxq
modifier|*
name|ofld_rxq
decl_stmt|;
comment|/* TOE rx queues */
endif|#
directive|endif
name|uint16_t
name|iq_start
decl_stmt|;
name|int
name|eq_start
decl_stmt|;
name|struct
name|sge_iq
modifier|*
modifier|*
name|iqmap
decl_stmt|;
comment|/* iq->cntxt_id to iq mapping */
name|struct
name|sge_eq
modifier|*
modifier|*
name|eqmap
decl_stmt|;
comment|/* eq->cntxt_id to eq mapping */
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|rss_header
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|cpl_handler_t
function_decl|)
parameter_list|(
name|struct
name|sge_iq
modifier|*
parameter_list|,
specifier|const
name|struct
name|rss_header
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|adapter
block|{
name|SLIST_ENTRY
argument_list|(
argument|adapter
argument_list|)
name|link
expr_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|cdev
modifier|*
name|cdev
decl_stmt|;
comment|/* PCIe register resources */
name|int
name|regs_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|regs_res
decl_stmt|;
name|int
name|msix_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|msix_res
decl_stmt|;
name|bus_space_handle_t
name|bh
decl_stmt|;
name|bus_space_tag_t
name|bt
decl_stmt|;
name|bus_size_t
name|mmio_len
decl_stmt|;
name|unsigned
name|int
name|pf
decl_stmt|;
name|unsigned
name|int
name|mbox
decl_stmt|;
comment|/* Interrupt information */
name|int
name|intr_type
decl_stmt|;
name|int
name|intr_count
decl_stmt|;
struct|struct
name|irq
block|{
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|int
name|rid
decl_stmt|;
name|void
modifier|*
name|tag
decl_stmt|;
block|}
modifier|*
name|irq
struct|;
name|bus_dma_tag_t
name|dmat
decl_stmt|;
comment|/* Parent DMA tag */
name|struct
name|sge
name|sge
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|tq
index|[
name|NCHAN
index|]
decl_stmt|;
comment|/* taskqueues that flush data out */
name|struct
name|port_info
modifier|*
name|port
index|[
name|MAX_NPORTS
index|]
decl_stmt|;
name|uint8_t
name|chan_map
index|[
name|NCHAN
index|]
decl_stmt|;
name|uint32_t
name|filter_mode
decl_stmt|;
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|struct
name|uld_softc
name|tom
decl_stmt|;
name|struct
name|tom_tunables
name|tt
decl_stmt|;
endif|#
directive|endif
name|struct
name|l2t_data
modifier|*
name|l2t
decl_stmt|;
comment|/* L2 table */
name|struct
name|tid_info
name|tids
decl_stmt|;
name|int
name|open_device_map
decl_stmt|;
ifndef|#
directive|ifndef
name|TCP_OFFLOAD_DISABLE
name|int
name|offload_map
decl_stmt|;
endif|#
directive|endif
name|int
name|flags
decl_stmt|;
name|char
name|fw_version
index|[
literal|32
index|]
decl_stmt|;
name|unsigned
name|int
name|cfcsum
decl_stmt|;
name|struct
name|adapter_params
name|params
decl_stmt|;
name|struct
name|t4_virt_res
name|vres
decl_stmt|;
name|uint16_t
name|linkcaps
decl_stmt|;
name|uint16_t
name|niccaps
decl_stmt|;
name|uint16_t
name|toecaps
decl_stmt|;
name|uint16_t
name|rdmacaps
decl_stmt|;
name|uint16_t
name|iscsicaps
decl_stmt|;
name|uint16_t
name|fcoecaps
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
comment|/* from adapter_full_init to full_uninit */
name|struct
name|mtx
name|sc_lock
decl_stmt|;
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
comment|/* Starving free lists */
name|struct
name|mtx
name|sfl_lock
decl_stmt|;
comment|/* same cache-line as sc_lock? but that's ok */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|sge_fl
argument_list|)
name|sfl
expr_stmt|;
name|struct
name|callout
name|sfl_callout
decl_stmt|;
name|cpl_handler_t
name|cpl_handler
index|[
literal|256
index|]
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ADAPTER_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|ADAPTER_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->sc_lock)
end_define

begin_define
define|#
directive|define
name|ADAPTER_LOCK_ASSERT_OWNED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|ADAPTER_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->sc_lock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|PORT_LOCK
parameter_list|(
name|pi
parameter_list|)
value|mtx_lock(&(pi)->pi_lock)
end_define

begin_define
define|#
directive|define
name|PORT_UNLOCK
parameter_list|(
name|pi
parameter_list|)
value|mtx_unlock(&(pi)->pi_lock)
end_define

begin_define
define|#
directive|define
name|PORT_LOCK_ASSERT_OWNED
parameter_list|(
name|pi
parameter_list|)
value|mtx_assert(&(pi)->pi_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|PORT_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|pi
parameter_list|)
value|mtx_assert(&(pi)->pi_lock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|FL_LOCK
parameter_list|(
name|fl
parameter_list|)
value|mtx_lock(&(fl)->fl_lock)
end_define

begin_define
define|#
directive|define
name|FL_TRYLOCK
parameter_list|(
name|fl
parameter_list|)
value|mtx_trylock(&(fl)->fl_lock)
end_define

begin_define
define|#
directive|define
name|FL_UNLOCK
parameter_list|(
name|fl
parameter_list|)
value|mtx_unlock(&(fl)->fl_lock)
end_define

begin_define
define|#
directive|define
name|FL_LOCK_ASSERT_OWNED
parameter_list|(
name|fl
parameter_list|)
value|mtx_assert(&(fl)->fl_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|FL_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|fl
parameter_list|)
value|mtx_assert(&(fl)->fl_lock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|RXQ_FL_LOCK
parameter_list|(
name|rxq
parameter_list|)
value|FL_LOCK(&(rxq)->fl)
end_define

begin_define
define|#
directive|define
name|RXQ_FL_UNLOCK
parameter_list|(
name|rxq
parameter_list|)
value|FL_UNLOCK(&(rxq)->fl)
end_define

begin_define
define|#
directive|define
name|RXQ_FL_LOCK_ASSERT_OWNED
parameter_list|(
name|rxq
parameter_list|)
value|FL_LOCK_ASSERT_OWNED(&(rxq)->fl)
end_define

begin_define
define|#
directive|define
name|RXQ_FL_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|rxq
parameter_list|)
value|FL_LOCK_ASSERT_NOTOWNED(&(rxq)->fl)
end_define

begin_define
define|#
directive|define
name|EQ_LOCK
parameter_list|(
name|eq
parameter_list|)
value|mtx_lock(&(eq)->eq_lock)
end_define

begin_define
define|#
directive|define
name|EQ_TRYLOCK
parameter_list|(
name|eq
parameter_list|)
value|mtx_trylock(&(eq)->eq_lock)
end_define

begin_define
define|#
directive|define
name|EQ_UNLOCK
parameter_list|(
name|eq
parameter_list|)
value|mtx_unlock(&(eq)->eq_lock)
end_define

begin_define
define|#
directive|define
name|EQ_LOCK_ASSERT_OWNED
parameter_list|(
name|eq
parameter_list|)
value|mtx_assert(&(eq)->eq_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|EQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|eq
parameter_list|)
value|mtx_assert(&(eq)->eq_lock, MA_NOTOWNED)
end_define

begin_define
define|#
directive|define
name|TXQ_LOCK
parameter_list|(
name|txq
parameter_list|)
value|EQ_LOCK(&(txq)->eq)
end_define

begin_define
define|#
directive|define
name|TXQ_TRYLOCK
parameter_list|(
name|txq
parameter_list|)
value|EQ_TRYLOCK(&(txq)->eq)
end_define

begin_define
define|#
directive|define
name|TXQ_UNLOCK
parameter_list|(
name|txq
parameter_list|)
value|EQ_UNLOCK(&(txq)->eq)
end_define

begin_define
define|#
directive|define
name|TXQ_LOCK_ASSERT_OWNED
parameter_list|(
name|txq
parameter_list|)
value|EQ_LOCK_ASSERT_OWNED(&(txq)->eq)
end_define

begin_define
define|#
directive|define
name|TXQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|txq
parameter_list|)
value|EQ_LOCK_ASSERT_NOTOWNED(&(txq)->eq)
end_define

begin_define
define|#
directive|define
name|for_each_txq
parameter_list|(
name|pi
parameter_list|,
name|iter
parameter_list|,
name|txq
parameter_list|)
define|\
value|txq =&pi->adapter->sge.txq[pi->first_txq]; \ 	for (iter = 0; iter< pi->ntxq; ++iter, ++txq)
end_define

begin_define
define|#
directive|define
name|for_each_rxq
parameter_list|(
name|pi
parameter_list|,
name|iter
parameter_list|,
name|rxq
parameter_list|)
define|\
value|rxq =&pi->adapter->sge.rxq[pi->first_rxq]; \ 	for (iter = 0; iter< pi->nrxq; ++iter, ++rxq)
end_define

begin_define
define|#
directive|define
name|for_each_ofld_txq
parameter_list|(
name|pi
parameter_list|,
name|iter
parameter_list|,
name|ofld_txq
parameter_list|)
define|\
value|ofld_txq =&pi->adapter->sge.ofld_txq[pi->first_ofld_txq]; \ 	for (iter = 0; iter< pi->nofldtxq; ++iter, ++ofld_txq)
end_define

begin_define
define|#
directive|define
name|for_each_ofld_rxq
parameter_list|(
name|pi
parameter_list|,
name|iter
parameter_list|,
name|ofld_rxq
parameter_list|)
define|\
value|ofld_rxq =&pi->adapter->sge.ofld_rxq[pi->first_ofld_rxq]; \ 	for (iter = 0; iter< pi->nofldrxq; ++iter, ++ofld_rxq)
end_define

begin_comment
comment|/* One for errors, one for firmware events */
end_comment

begin_define
define|#
directive|define
name|T4_EXTRA_INTR
value|2
end_define

begin_function
specifier|static
specifier|inline
name|uint32_t
name|t4_read_reg
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
name|bus_space_read_4
argument_list|(
name|sc
operator|->
name|bt
argument_list|,
name|sc
operator|->
name|bh
argument_list|,
name|reg
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_write_reg
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|bus_space_write_4
argument_list|(
name|sc
operator|->
name|bt
argument_list|,
name|sc
operator|->
name|bh
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|uint64_t
name|t4_read_reg64
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
return|return
name|t4_bus_space_read_8
argument_list|(
name|sc
operator|->
name|bt
argument_list|,
name|sc
operator|->
name|bh
argument_list|,
name|reg
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_write_reg64
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|t4_bus_space_write_8
argument_list|(
name|sc
operator|->
name|bt
argument_list|,
name|sc
operator|->
name|bh
argument_list|,
name|reg
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_read_cfg1
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
name|pci_read_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_write_cfg1
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint8_t
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
name|val
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_read_cfg2
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint16_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
name|pci_read_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_write_cfg2
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint16_t
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
name|val
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_read_cfg4
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
modifier|*
name|val
parameter_list|)
block|{
operator|*
name|val
operator|=
name|pci_read_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_pci_write_cfg4
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|)
block|{
name|pci_write_config
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
name|reg
argument_list|,
name|val
argument_list|,
literal|4
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|struct
name|port_info
modifier|*
name|adap2pinfo
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|idx
parameter_list|)
block|{
return|return
operator|(
name|sc
operator|->
name|port
index|[
name|idx
index|]
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|t4_os_set_hw_addr
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|int
name|idx
parameter_list|,
name|uint8_t
name|hw_addr
index|[]
parameter_list|)
block|{
name|bcopy
argument_list|(
name|hw_addr
argument_list|,
name|sc
operator|->
name|port
index|[
name|idx
index|]
operator|->
name|hw_addr
argument_list|,
name|ETHER_ADDR_LEN
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|bool
name|is_10G_port
parameter_list|(
specifier|const
name|struct
name|port_info
modifier|*
name|pi
parameter_list|)
block|{
return|return
operator|(
operator|(
name|pi
operator|->
name|link_cfg
operator|.
name|supported
operator|&
name|FW_PORT_CAP_SPEED_10G
operator|)
operator|!=
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|tx_resume_threshold
parameter_list|(
name|struct
name|sge_eq
modifier|*
name|eq
parameter_list|)
block|{
return|return
operator|(
name|eq
operator|->
name|qsize
operator|/
literal|4
operator|)
return|;
block|}
end_function

begin_comment
comment|/* t4_main.c */
end_comment

begin_function_decl
name|void
name|t4_tx_task
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_tx_callout
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_os_find_pci_capability
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_os_pci_save_state
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_os_pci_restore_state
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_os_portmod_changed
parameter_list|(
specifier|const
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_os_link_changed
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_iterate
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_register_cpl_handler
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|int
parameter_list|,
name|cpl_handler_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* t4_sge.c */
end_comment

begin_function_decl
name|void
name|t4_sge_modload
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_sge_init
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_create_dma_tag
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_destroy_dma_tag
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_setup_adapter_queues
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_teardown_adapter_queues
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_setup_port_queues
parameter_list|(
name|struct
name|port_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_teardown_port_queues
parameter_list|(
name|struct
name|port_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_alloc_tx_maps
parameter_list|(
name|struct
name|tx_maps
modifier|*
parameter_list|,
name|bus_dma_tag_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_free_tx_maps
parameter_list|(
name|struct
name|tx_maps
modifier|*
parameter_list|,
name|bus_dma_tag_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_intr_all
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_intr_err
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_intr_evt
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_mgmt_tx
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_wrq_tx_locked
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|,
name|struct
name|sge_wrq
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_eth_tx
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|struct
name|sge_txq
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|t4_update_fl_bufsize
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|can_resume_tx
parameter_list|(
name|struct
name|sge_eq
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|int
name|t4_wrq_tx
parameter_list|(
name|struct
name|adapter
modifier|*
name|sc
parameter_list|,
name|struct
name|sge_wrq
modifier|*
name|wrq
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
block|{
name|int
name|rc
decl_stmt|;
name|TXQ_LOCK
argument_list|(
name|wrq
argument_list|)
expr_stmt|;
name|rc
operator|=
name|t4_wrq_tx_locked
argument_list|(
name|sc
argument_list|,
name|wrq
argument_list|,
name|m
argument_list|)
expr_stmt|;
name|TXQ_UNLOCK
argument_list|(
name|wrq
argument_list|)
expr_stmt|;
return|return
operator|(
name|rc
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

