begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014-2017, Matthew Macy (mmacy@nextbsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *  *  1. Redistributions of source code must retain the above copyright notice,  *     this list of conditions and the following disclaimer.  *  *  2. Neither the name of Matthew Macy nor the names of its  *     contributors may be used to endorse or promote products derived from  *     this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IFLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|__IFLIB_H_
end_define

begin_include
include|#
directive|include
file|<sys/kobj.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/cpuset.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/nv.h>
end_include

begin_include
include|#
directive|include
file|<sys/gtaskqueue.h>
end_include

begin_comment
comment|/*  * The value type for indexing, limits max descriptors  * to 65535 can be conditionally redefined to uint32_t  * in the future if the need arises.  */
end_comment

begin_typedef
typedef|typedef
name|uint16_t
name|qidx_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|QIDX_INVALID
value|0xFFFF
end_define

begin_comment
comment|/*  * Most cards can handle much larger TSO requests  * but the FreeBSD TCP stack will break on larger  * values  */
end_comment

begin_define
define|#
directive|define
name|FREEBSD_TSO_SIZE_MAX
value|65518
end_define

begin_struct_decl
struct_decl|struct
name|iflib_ctx
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|iflib_ctx
modifier|*
name|if_ctx_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|if_shared_ctx
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|if_shared_ctx
modifier|*
name|if_shared_ctx_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|if_int_delay_info
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|if_int_delay_info
modifier|*
name|if_int_delay_info_t
typedef|;
end_typedef

begin_comment
comment|/*  * File organization:  *  - public structures  *  - iflib accessors  *  - iflib utility functions  *  - iflib core functions  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|if_rxd_frag
block|{
name|uint8_t
name|irf_flid
decl_stmt|;
name|qidx_t
name|irf_idx
decl_stmt|;
name|uint16_t
name|irf_len
decl_stmt|;
block|}
typedef|*
name|if_rxd_frag_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|if_rxd_info
block|{
comment|/* set by iflib */
name|uint16_t
name|iri_qsidx
decl_stmt|;
comment|/* qset index */
name|uint16_t
name|iri_vtag
decl_stmt|;
comment|/* vlan tag - if flag set */
comment|/* XXX redundant with the new irf_len field */
name|uint16_t
name|iri_len
decl_stmt|;
comment|/* packet length */
name|qidx_t
name|iri_cidx
decl_stmt|;
comment|/* consumer index of cq */
name|struct
name|ifnet
modifier|*
name|iri_ifp
decl_stmt|;
comment|/* some drivers>1 interface per softc */
comment|/* updated by driver */
name|if_rxd_frag_t
name|iri_frags
decl_stmt|;
name|uint32_t
name|iri_flowid
decl_stmt|;
comment|/* RSS hash for packet */
name|uint32_t
name|iri_csum_flags
decl_stmt|;
comment|/* m_pkthdr csum flags */
name|uint32_t
name|iri_csum_data
decl_stmt|;
comment|/* m_pkthdr csum data */
name|uint8_t
name|iri_flags
decl_stmt|;
comment|/* mbuf flags for packet */
name|uint8_t
name|iri_nfrags
decl_stmt|;
comment|/* number of fragments in packet */
name|uint8_t
name|iri_rsstype
decl_stmt|;
comment|/* RSS hash type */
name|uint8_t
name|iri_pad
decl_stmt|;
comment|/* any padding in the received data */
block|}
typedef|*
name|if_rxd_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|if_rxd_update
block|{
name|uint64_t
modifier|*
name|iru_paddrs
decl_stmt|;
name|caddr_t
modifier|*
name|iru_vaddrs
decl_stmt|;
name|qidx_t
modifier|*
name|iru_idxs
decl_stmt|;
name|qidx_t
name|iru_pidx
decl_stmt|;
name|uint16_t
name|iru_qsidx
decl_stmt|;
name|uint16_t
name|iru_count
decl_stmt|;
name|uint16_t
name|iru_buf_size
decl_stmt|;
name|uint8_t
name|iru_flidx
decl_stmt|;
block|}
typedef|*
name|if_rxd_update_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IPI_TX_INTR
value|0x1
end_define

begin_comment
comment|/* send an interrupt when this packet is sent */
end_comment

begin_define
define|#
directive|define
name|IPI_TX_IPV4
value|0x2
end_define

begin_comment
comment|/* ethertype IPv4 */
end_comment

begin_define
define|#
directive|define
name|IPI_TX_IPV6
value|0x4
end_define

begin_comment
comment|/* ethertype IPv6 */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|if_pkt_info
block|{
name|bus_dma_segment_t
modifier|*
name|ipi_segs
decl_stmt|;
comment|/* physical addresses */
name|uint32_t
name|ipi_len
decl_stmt|;
comment|/* packet length */
name|uint16_t
name|ipi_qsidx
decl_stmt|;
comment|/* queue set index */
name|qidx_t
name|ipi_nsegs
decl_stmt|;
comment|/* number of segments */
name|qidx_t
name|ipi_ndescs
decl_stmt|;
comment|/* number of descriptors used by encap */
name|uint16_t
name|ipi_flags
decl_stmt|;
comment|/* iflib per-packet flags */
name|qidx_t
name|ipi_pidx
decl_stmt|;
comment|/* start pidx for encap */
name|qidx_t
name|ipi_new_pidx
decl_stmt|;
comment|/* next available pidx post-encap */
comment|/* offload handling */
name|uint8_t
name|ipi_ehdrlen
decl_stmt|;
comment|/* ether header length */
name|uint8_t
name|ipi_ip_hlen
decl_stmt|;
comment|/* ip header length */
name|uint8_t
name|ipi_tcp_hlen
decl_stmt|;
comment|/* tcp header length */
name|uint8_t
name|ipi_ipproto
decl_stmt|;
comment|/* ip protocol */
name|uint32_t
name|ipi_csum_flags
decl_stmt|;
comment|/* packet checksum flags */
name|uint16_t
name|ipi_tso_segsz
decl_stmt|;
comment|/* tso segment size */
name|uint16_t
name|ipi_vtag
decl_stmt|;
comment|/* VLAN tag */
name|uint16_t
name|ipi_etype
decl_stmt|;
comment|/* ether header type */
name|uint8_t
name|ipi_tcp_hflags
decl_stmt|;
comment|/* tcp header flags */
name|uint8_t
name|ipi_mflags
decl_stmt|;
comment|/* packet mbuf flags */
name|uint32_t
name|ipi_tcp_seq
decl_stmt|;
comment|/* tcp seqno */
name|uint32_t
name|ipi_tcp_sum
decl_stmt|;
comment|/* tcp csum */
block|}
typedef|*
name|if_pkt_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|if_irq
block|{
name|struct
name|resource
modifier|*
name|ii_res
decl_stmt|;
name|int
name|ii_rid
decl_stmt|;
name|void
modifier|*
name|ii_tag
decl_stmt|;
block|}
typedef|*
name|if_irq_t
typedef|;
end_typedef

begin_struct
struct|struct
name|if_int_delay_info
block|{
name|if_ctx_t
name|iidi_ctx
decl_stmt|;
comment|/* Back-pointer to the iflib ctx (softc) */
name|int
name|iidi_offset
decl_stmt|;
comment|/* Register offset to read/write */
name|int
name|iidi_value
decl_stmt|;
comment|/* Current value in usecs */
name|struct
name|sysctl_oid
modifier|*
name|iidi_oidp
decl_stmt|;
name|struct
name|sysctl_req
modifier|*
name|iidi_req
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|IFLIB_INTR_LEGACY
block|,
name|IFLIB_INTR_MSI
block|,
name|IFLIB_INTR_MSIX
block|}
name|iflib_intr_mode_t
typedef|;
end_typedef

begin_comment
comment|/*  * This really belongs in pciio.h or some place more general  * but this is the only consumer for now.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pci_vendor_info
block|{
name|uint32_t
name|pvi_vendor_id
decl_stmt|;
name|uint32_t
name|pvi_device_id
decl_stmt|;
name|uint32_t
name|pvi_subvendor_id
decl_stmt|;
name|uint32_t
name|pvi_subdevice_id
decl_stmt|;
name|uint32_t
name|pvi_rev_id
decl_stmt|;
name|uint32_t
name|pvi_class_mask
decl_stmt|;
name|caddr_t
name|pvi_name
decl_stmt|;
block|}
name|pci_vendor_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PVID
parameter_list|(
name|vendor
parameter_list|,
name|devid
parameter_list|,
name|name
parameter_list|)
value|{vendor, devid, 0, 0, 0, 0, name}
end_define

begin_define
define|#
directive|define
name|PVID_OEM
parameter_list|(
name|vendor
parameter_list|,
name|devid
parameter_list|,
name|svid
parameter_list|,
name|sdevid
parameter_list|,
name|revid
parameter_list|,
name|name
parameter_list|)
value|{vendor, devid, svid, sdevid, revid, 0, name}
end_define

begin_define
define|#
directive|define
name|PVID_END
value|{0, 0, 0, 0, 0, 0, NULL}
end_define

begin_typedef
typedef|typedef
struct|struct
name|if_txrx
block|{
name|int
function_decl|(
modifier|*
name|ift_txd_encap
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|if_pkt_info_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ift_txd_flush
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|qidx_t
name|pidx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ift_txd_credits_update
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint16_t
name|qsidx
parameter_list|,
name|bool
name|clear
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ift_rxd_available
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint16_t
name|qsidx
parameter_list|,
name|qidx_t
name|pidx
parameter_list|,
name|qidx_t
name|budget
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ift_rxd_pkt_get
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|if_rxd_info_t
name|ri
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ift_rxd_refill
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|if_rxd_update_t
name|iru
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ift_rxd_flush
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|uint16_t
name|qsidx
parameter_list|,
name|uint8_t
name|flidx
parameter_list|,
name|qidx_t
name|pidx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ift_legacy_intr
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
block|}
typedef|*
name|if_txrx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|if_softc_ctx
block|{
name|int
name|isc_vectors
decl_stmt|;
name|int
name|isc_nrxqsets
decl_stmt|;
name|int
name|isc_ntxqsets
decl_stmt|;
name|int
name|isc_msix_bar
decl_stmt|;
comment|/* can be model specific - initialize in attach_pre */
name|int
name|isc_tx_nsegments
decl_stmt|;
comment|/* can be model specific - initialize in attach_pre */
name|int
name|isc_ntxd
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_nrxd
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|isc_txqsizes
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|isc_rxqsizes
index|[
literal|8
index|]
decl_stmt|;
comment|/* is there such thing as a descriptor that is more than 248 bytes ? */
name|uint8_t
name|isc_txd_size
index|[
literal|8
index|]
decl_stmt|;
name|uint8_t
name|isc_rxd_size
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_max_txqsets
decl_stmt|;
name|int
name|isc_max_rxqsets
decl_stmt|;
name|int
name|isc_tx_tso_segments_max
decl_stmt|;
name|int
name|isc_tx_tso_size_max
decl_stmt|;
name|int
name|isc_tx_tso_segsize_max
decl_stmt|;
name|int
name|isc_tx_csum_flags
decl_stmt|;
name|int
name|isc_capenable
decl_stmt|;
name|int
name|isc_rss_table_size
decl_stmt|;
name|int
name|isc_rss_table_mask
decl_stmt|;
name|int
name|isc_nrxqsets_max
decl_stmt|;
name|int
name|isc_ntxqsets_max
decl_stmt|;
name|iflib_intr_mode_t
name|isc_intr
decl_stmt|;
name|uint16_t
name|isc_max_frame_size
decl_stmt|;
comment|/* set at init time by driver */
name|uint32_t
name|isc_pause_frames
decl_stmt|;
comment|/* set by driver for iflib_timer to detect */
name|pci_vendor_info_t
name|isc_vendor_info
decl_stmt|;
comment|/* set by iflib prior to attach_pre */
name|int
name|isc_disable_msix
decl_stmt|;
name|if_txrx_t
name|isc_txrx
decl_stmt|;
block|}
typedef|*
name|if_softc_ctx_t
typedef|;
end_typedef

begin_comment
comment|/*  * Initialization values for device  */
end_comment

begin_struct
struct|struct
name|if_shared_ctx
block|{
name|int
name|isc_magic
decl_stmt|;
name|driver_t
modifier|*
name|isc_driver
decl_stmt|;
name|bus_size_t
name|isc_q_align
decl_stmt|;
name|bus_size_t
name|isc_tx_maxsize
decl_stmt|;
name|bus_size_t
name|isc_tx_maxsegsize
decl_stmt|;
name|bus_size_t
name|isc_rx_maxsize
decl_stmt|;
name|bus_size_t
name|isc_rx_maxsegsize
decl_stmt|;
name|int
name|isc_rx_nsegments
decl_stmt|;
name|int
name|isc_admin_intrcnt
decl_stmt|;
comment|/* # of admin/link interrupts */
comment|/* fields necessary for probe */
name|pci_vendor_info_t
modifier|*
name|isc_vendor_info
decl_stmt|;
name|char
modifier|*
name|isc_driver_version
decl_stmt|;
comment|/* optional function to transform the read values to match the table*/
name|void
function_decl|(
modifier|*
name|isc_parse_devinfo
function_decl|)
parameter_list|(
name|uint16_t
modifier|*
name|device_id
parameter_list|,
name|uint16_t
modifier|*
name|subvendor_id
parameter_list|,
name|uint16_t
modifier|*
name|subdevice_id
parameter_list|,
name|uint16_t
modifier|*
name|rev_id
parameter_list|)
function_decl|;
name|int
name|isc_nrxd_min
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_nrxd_default
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_nrxd_max
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_ntxd_min
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_ntxd_default
index|[
literal|8
index|]
decl_stmt|;
name|int
name|isc_ntxd_max
index|[
literal|8
index|]
decl_stmt|;
comment|/* actively used during operation */
name|int
name|isc_nfl
name|__aligned
parameter_list|(
name|CACHE_LINE_SIZE
parameter_list|)
function_decl|;
name|int
name|isc_ntxqs
decl_stmt|;
comment|/* # of tx queues per tx qset - usually 1 */
name|int
name|isc_nrxqs
decl_stmt|;
comment|/* # of rx queues per rx qset - intel 1, chelsio 2, broadcom 3 */
name|int
name|isc_rx_process_limit
decl_stmt|;
name|int
name|isc_tx_reclaim_thresh
decl_stmt|;
name|int
name|isc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|iflib_dma_info
block|{
name|bus_addr_t
name|idi_paddr
decl_stmt|;
name|caddr_t
name|idi_vaddr
decl_stmt|;
name|bus_dma_tag_t
name|idi_tag
decl_stmt|;
name|bus_dmamap_t
name|idi_map
decl_stmt|;
name|uint32_t
name|idi_size
decl_stmt|;
block|}
typedef|*
name|iflib_dma_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IFLIB_MAGIC
value|0xCAFEF00D
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|IFLIB_INTR_RX
block|,
name|IFLIB_INTR_TX
block|,
name|IFLIB_INTR_RXTX
block|,
name|IFLIB_INTR_ADMIN
block|,
name|IFLIB_INTR_IOV
block|, }
name|iflib_intr_type_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|ETH_ADDR_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETH_ADDR_LEN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Interface has a separate command queue for RX  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_HAS_RXCQ
value|0x01
end_define

begin_comment
comment|/*  * Driver has already allocated vectors  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_SKIP_MSIX
value|0x02
end_define

begin_comment
comment|/*  * Interface is a virtual function  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_IS_VF
value|0x04
end_define

begin_comment
comment|/*  * Interface has a separate command queue for TX  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_HAS_TXCQ
value|0x08
end_define

begin_comment
comment|/*  * Interface does checksum in place  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_NEED_SCRATCH
value|0x10
end_define

begin_comment
comment|/*  * Interface doesn't expect in_pseudo for th_sum  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_TSO_INIT_IP
value|0x20
end_define

begin_comment
comment|/*  * Interface doesn't align IP header  */
end_comment

begin_define
define|#
directive|define
name|IFLIB_DO_RX_FIXUP
value|0x40
end_define

begin_comment
comment|/*  * field accessors  */
end_comment

begin_function_decl
name|void
modifier|*
name|iflib_get_softc
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|device_t
name|iflib_get_dev
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|if_t
name|iflib_get_ifp
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ifmedia
modifier|*
name|iflib_get_media
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|if_softc_ctx_t
name|iflib_get_softc_ctx
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|if_shared_ctx_t
name|iflib_get_sctx
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_set_mac
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|uint8_t
name|mac
index|[
name|ETHER_ADDR_LEN
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the driver can plug cleanly in to newbus use these  */
end_comment

begin_function_decl
name|int
name|iflib_device_probe
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_detach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_suspend
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_resume
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_shutdown
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_iov_init
parameter_list|(
name|device_t
parameter_list|,
name|uint16_t
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_device_iov_uninit
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_iov_add_vf
parameter_list|(
name|device_t
parameter_list|,
name|uint16_t
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * If the driver can't plug cleanly in to newbus  * use these  */
end_comment

begin_function_decl
name|int
name|iflib_device_register
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|softc
parameter_list|,
name|if_shared_ctx_t
name|sctx
parameter_list|,
name|if_ctx_t
modifier|*
name|ctxp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_device_deregister
parameter_list|(
name|if_ctx_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_irq_alloc
parameter_list|(
name|if_ctx_t
parameter_list|,
name|if_irq_t
parameter_list|,
name|int
parameter_list|,
name|driver_filter_t
parameter_list|,
name|void
modifier|*
name|filter_arg
parameter_list|,
name|driver_intr_t
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_irq_alloc_generic
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|if_irq_t
name|irq
parameter_list|,
name|int
name|rid
parameter_list|,
name|iflib_intr_type_t
name|type
parameter_list|,
name|driver_filter_t
modifier|*
name|filter
parameter_list|,
name|void
modifier|*
name|filter_arg
parameter_list|,
name|int
name|qid
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_softirq_alloc_generic
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
name|rid
parameter_list|,
name|iflib_intr_type_t
name|type
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|qid
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_irq_free
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|if_irq_t
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_io_tqg_attach
parameter_list|(
name|struct
name|grouptask
modifier|*
name|gt
parameter_list|,
name|void
modifier|*
name|uniq
parameter_list|,
name|int
name|cpu
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_config_gtask_init
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|struct
name|grouptask
modifier|*
name|gtask
parameter_list|,
name|gtask_fn_t
modifier|*
name|fn
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_config_gtask_deinit
parameter_list|(
name|struct
name|grouptask
modifier|*
name|gtask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_tx_intr_deferred
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
name|txqid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_rx_intr_deferred
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
name|rxqid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_admin_intr_deferred
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_iov_intr_deferred
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_link_state_change
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
name|linkstate
parameter_list|,
name|uint64_t
name|baudrate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_dma_alloc
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
name|size
parameter_list|,
name|iflib_dma_info_t
name|dma
parameter_list|,
name|int
name|mapflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_dma_free
parameter_list|(
name|iflib_dma_info_t
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|iflib_dma_alloc_multi
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|,
name|int
modifier|*
name|sizes
parameter_list|,
name|iflib_dma_info_t
modifier|*
name|dmalist
parameter_list|,
name|int
name|mapflags
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_dma_free_multi
parameter_list|(
name|iflib_dma_info_t
modifier|*
name|dmalist
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mtx
modifier|*
name|iflib_ctx_lock_get
parameter_list|(
name|if_ctx_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mtx
modifier|*
name|iflib_qset_lock_get
parameter_list|(
name|if_ctx_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_led_create
parameter_list|(
name|if_ctx_t
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|iflib_add_int_delay_sysctl
parameter_list|(
name|if_ctx_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|if_int_delay_info_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  __IFLIB_H_ */
end_comment

end_unit

