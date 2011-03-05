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
file|"common/t4fw_interface.h"
end_include

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
name|X86_BUS_SPACE_MEM
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
name|X86_BUS_SPACE_MEM
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
name|RX_FL_ESIZE
init|=
literal|64
block|,
comment|/* 8 64bit addresses */
name|FL_BUF_SIZES
init|=
literal|4
block|,
name|TX_EQ_QSIZE
init|=
literal|1024
block|,
name|TX_EQ_ESIZE
init|=
literal|64
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
name|INTR_FWD
init|=
operator|(
literal|1
operator|<<
literal|2
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
name|VI_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|1
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
name|taskqueue
modifier|*
name|tq
decl_stmt|;
name|struct
name|callout
name|tick
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|ctx
decl_stmt|;
comment|/* lives from ifconfig up to down */
name|struct
name|sysctl_oid
modifier|*
name|oid_rxq
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|oid_txq
decl_stmt|;
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

begin_struct
struct|struct
name|tx_sdesc
block|{
name|uint8_t
name|desc_used
decl_stmt|;
comment|/* # of hardware descriptors used by the WR */
name|uint8_t
name|map_used
decl_stmt|;
comment|/* # of frames sent out in the WR */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
function_decl|(
name|iq_intr_handler_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
block|{
comment|/* iq flags */
name|IQ_ALLOCATED
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* firmware resources allocated */
name|IQ_STARTED
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* started */
block|}
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
name|struct
name|mtx
name|iq_lock
decl_stmt|;
name|char
name|lockname
index|[
literal|16
index|]
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|struct
name|adapter
modifier|*
name|adapter
decl_stmt|;
name|__be64
modifier|*
name|desc
decl_stmt|;
comment|/* KVA of descriptor ring */
name|bus_addr_t
name|ba
decl_stmt|;
comment|/* bus address of descriptor ring */
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
name|int8_t
name|intr_pktc_idx
decl_stmt|;
comment|/* packet count threshold index */
name|uint8_t
name|intr_next
decl_stmt|;
comment|/* holdoff for next interrupt */
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
comment|/* SGE context id  for the iq */
name|uint16_t
name|abs_id
decl_stmt|;
comment|/* absolute SGE id for the iq */
name|iq_intr_handler_t
modifier|*
name|handler
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
comment|/* eq flags */
name|EQ_ALLOCATED
init|=
operator|(
literal|1
operator|<<
literal|1
operator|)
block|,
comment|/* firmware resources allocated */
name|EQ_STARTED
init|=
operator|(
literal|1
operator|<<
literal|2
operator|)
block|,
comment|/* started */
name|EQ_STALLED
init|=
operator|(
literal|1
operator|<<
literal|3
operator|)
block|,
comment|/* currently stalled */
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
name|bus_dma_tag_t
name|tx_tag
decl_stmt|;
comment|/* tag for transmit buffers */
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
name|unsigned
name|int
name|flags
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
name|tx_sdesc
modifier|*
name|sdesc
decl_stmt|;
comment|/* KVA of software descriptor ring */
name|struct
name|buf_ring
modifier|*
name|br
decl_stmt|;
comment|/* tx buffer ring */
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
name|uint32_t
name|cntxt_id
decl_stmt|;
comment|/* SGE context id for the eq */
comment|/* DMA maps used for tx */
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
name|__aligned
argument_list|(
name|CACHE_LINE_SIZE
argument_list|)
struct|;
end_struct

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
name|pending
decl_stmt|;
comment|/* # of bufs allocated since last doorbell */
name|unsigned
name|int
name|dmamap_failed
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* txq: SGE egress queue + miscellaneous items */
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
name|mbuf
modifier|*
name|m
decl_stmt|;
comment|/* held up due to temporary resource shortage */
name|struct
name|task
name|resume_tx
decl_stmt|;
name|struct
name|port_info
modifier|*
name|port
decl_stmt|;
comment|/* the port this txq belongs to */
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
name|uint32_t
name|egr_update
decl_stmt|;
comment|/* # of SGE_EGR_UPDATE notifications for txq */
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|RXQ_LRO_ENABLED
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|}
enum|;
end_enum

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
name|unsigned
name|int
name|flags
decl_stmt|;
name|struct
name|port_info
modifier|*
name|port
decl_stmt|;
comment|/* the port this rxq belongs to */
name|struct
name|lro_ctrl
name|lro
decl_stmt|;
comment|/* LRO state */
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

begin_struct
struct|struct
name|sge
block|{
name|uint16_t
name|timer_val
index|[
name|SGE_NTIMERS
index|]
decl_stmt|;
name|uint8_t
name|counter_val
index|[
name|SGE_NCOUNTERS
index|]
decl_stmt|;
name|int
name|nrxq
decl_stmt|;
comment|/* total rx queues (all ports and the rest) */
name|int
name|ntxq
decl_stmt|;
comment|/* total tx queues (all ports and the rest) */
name|int
name|niq
decl_stmt|;
comment|/* total ingress queues */
name|int
name|neq
decl_stmt|;
comment|/* total egress queues */
name|struct
name|sge_iq
name|fwq
decl_stmt|;
comment|/* Firmware event queue */
name|struct
name|sge_iq
modifier|*
name|fiq
decl_stmt|;
comment|/* Forwarded interrupt queues (INTR_FWD) */
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

begin_struct
struct|struct
name|adapter
block|{
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
name|struct
name|tid_info
name|tids
decl_stmt|;
name|int
name|registered_device_map
decl_stmt|;
name|int
name|open_device_map
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
name|fw_version
index|[
literal|32
index|]
decl_stmt|;
name|struct
name|adapter_params
name|params
decl_stmt|;
name|struct
name|t4_virt_res
name|vres
decl_stmt|;
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
name|IQ_LOCK
parameter_list|(
name|iq
parameter_list|)
value|mtx_lock(&(iq)->iq_lock)
end_define

begin_define
define|#
directive|define
name|IQ_UNLOCK
parameter_list|(
name|iq
parameter_list|)
value|mtx_unlock(&(iq)->iq_lock)
end_define

begin_define
define|#
directive|define
name|IQ_LOCK_ASSERT_OWNED
parameter_list|(
name|iq
parameter_list|)
value|mtx_assert(&(iq)->iq_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|IQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|iq
parameter_list|)
value|mtx_assert(&(iq)->iq_lock, MA_NOTOWNED)
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
name|RXQ_LOCK
parameter_list|(
name|rxq
parameter_list|)
value|IQ_LOCK(&(rxq)->iq)
end_define

begin_define
define|#
directive|define
name|RXQ_UNLOCK
parameter_list|(
name|rxq
parameter_list|)
value|IQ_UNLOCK(&(rxq)->iq)
end_define

begin_define
define|#
directive|define
name|RXQ_LOCK_ASSERT_OWNED
parameter_list|(
name|rxq
parameter_list|)
value|IQ_LOCK_ASSERT_OWNED(&(rxq)->iq)
end_define

begin_define
define|#
directive|define
name|RXQ_LOCK_ASSERT_NOTOWNED
parameter_list|(
name|rxq
parameter_list|)
value|IQ_LOCK_ASSERT_NOTOWNED(&(rxq)->iq)
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
name|NFIQ
parameter_list|(
name|sc
parameter_list|)
value|((sc)->intr_count> 1 ? (sc)->intr_count - 1 : 1)
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

begin_comment
comment|/* t4_main.c */
end_comment

begin_function_decl
name|void
name|cxgbe_txq_start
parameter_list|(
name|void
modifier|*
parameter_list|,
name|int
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

begin_comment
comment|/* t4_sge.c */
end_comment

begin_function_decl
name|void
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
name|t4_setup_adapter_iqs
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_teardown_adapter_iqs
parameter_list|(
name|struct
name|adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_setup_eth_queues
parameter_list|(
name|struct
name|port_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|t4_teardown_eth_queues
parameter_list|(
name|struct
name|port_info
modifier|*
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
name|t4_intr_fwd
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
name|void
name|t4_intr_data
parameter_list|(
name|void
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

