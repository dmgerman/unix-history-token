begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Pyun YongHyeon<yongari@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IF_JMEVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_IF_JMEVAR_H
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

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_comment
comment|/*  * JMC250 supports upto 1024 descriptors and the number of  * descriptors should be multiple of 16.  */
end_comment

begin_define
define|#
directive|define
name|JME_TX_RING_CNT
value|384
end_define

begin_define
define|#
directive|define
name|JME_RX_RING_CNT
value|256
end_define

begin_comment
comment|/*  * Tx/Rx descriptor queue base should be 16bytes aligned and  * should not cross 4G bytes boundary on the 64bits address  * mode.  */
end_comment

begin_define
define|#
directive|define
name|JME_TX_RING_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|JME_RX_RING_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|JME_TSO_MAXSEGSIZE
value|4096
end_define

begin_define
define|#
directive|define
name|JME_TSO_MAXSIZE
value|(65535 + sizeof(struct ether_vlan_header))
end_define

begin_define
define|#
directive|define
name|JME_MAXTXSEGS
value|35
end_define

begin_define
define|#
directive|define
name|JME_RX_BUF_ALIGN
value|sizeof(uint64_t)
end_define

begin_define
define|#
directive|define
name|JME_SSB_ALIGN
value|16
end_define

begin_define
define|#
directive|define
name|JME_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|JME_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)>> 32)
end_define

begin_define
define|#
directive|define
name|JME_MSI_MESSAGES
value|8
end_define

begin_define
define|#
directive|define
name|JME_MSIX_MESSAGES
value|8
end_define

begin_comment
comment|/* Water mark to kick reclaiming Tx buffers. */
end_comment

begin_define
define|#
directive|define
name|JME_TX_DESC_HIWAT
value|(JME_TX_RING_CNT - (((JME_TX_RING_CNT) * 3) / 10))
end_define

begin_comment
comment|/*  * JMC250 can send 9K jumbo frame on Tx path and can receive  * 65535 bytes.  */
end_comment

begin_define
define|#
directive|define
name|JME_JUMBO_FRAMELEN
value|9216
end_define

begin_define
define|#
directive|define
name|JME_JUMBO_MTU
define|\
value|(JME_JUMBO_FRAMELEN - sizeof(struct ether_vlan_header) -	\ 	 ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|JME_MAX_MTU
define|\
value|(ETHER_MAX_LEN + sizeof(struct ether_vlan_header) -		\ 	 ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_comment
comment|/*  * JMC250 can't handle Tx checksum offload/TSO if frame length  * is larger than its FIFO size(2K). It's also good idea to not  * use jumbo frame if hardware is running at half-duplex media.  * Because the jumbo frame may not fit into the Tx FIFO,  * collisions make hardware fetch frame from host memory with  * DMA again which in turn slows down Tx performance  * significantly.  */
end_comment

begin_define
define|#
directive|define
name|JME_TX_FIFO_SIZE
value|2000
end_define

begin_comment
comment|/*  * JMC250 has just 4K Rx FIFO. To support jumbo frame that is  * larger than 4K bytes in length, Rx FIFO threshold should be  * adjusted to minimize Rx FIFO overrun.  */
end_comment

begin_define
define|#
directive|define
name|JME_RX_FIFO_SIZE
value|4000
end_define

begin_define
define|#
directive|define
name|JME_DESC_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x) = ((x) + 1) % (y))
end_define

begin_define
define|#
directive|define
name|JME_PROC_MIN
value|10
end_define

begin_define
define|#
directive|define
name|JME_PROC_DEFAULT
value|(JME_RX_RING_CNT / 2)
end_define

begin_define
define|#
directive|define
name|JME_PROC_MAX
value|(JME_RX_RING_CNT - 1)
end_define

begin_struct
struct|struct
name|jme_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
name|int
name|tx_ndesc
decl_stmt|;
name|struct
name|jme_desc
modifier|*
name|tx_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jme_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|struct
name|jme_desc
modifier|*
name|rx_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jme_chain_data
block|{
name|bus_dma_tag_t
name|jme_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|jme_buffer_tag
decl_stmt|;
name|bus_dma_tag_t
name|jme_ssb_tag
decl_stmt|;
name|bus_dmamap_t
name|jme_ssb_map
decl_stmt|;
name|bus_dma_tag_t
name|jme_tx_tag
decl_stmt|;
name|struct
name|jme_txdesc
name|jme_txdesc
index|[
name|JME_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|jme_rx_tag
decl_stmt|;
name|struct
name|jme_rxdesc
name|jme_rxdesc
index|[
name|JME_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|jme_tx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|jme_tx_ring_map
decl_stmt|;
name|bus_dma_tag_t
name|jme_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|jme_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|jme_rx_sparemap
decl_stmt|;
name|int
name|jme_tx_prod
decl_stmt|;
name|int
name|jme_tx_cons
decl_stmt|;
name|int
name|jme_tx_cnt
decl_stmt|;
name|int
name|jme_rx_cons
decl_stmt|;
name|int
name|jme_rxlen
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|jme_rxhead
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|jme_rxtail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jme_ring_data
block|{
name|struct
name|jme_desc
modifier|*
name|jme_tx_ring
decl_stmt|;
name|bus_addr_t
name|jme_tx_ring_paddr
decl_stmt|;
name|struct
name|jme_desc
modifier|*
name|jme_rx_ring
decl_stmt|;
name|bus_addr_t
name|jme_rx_ring_paddr
decl_stmt|;
name|struct
name|jme_ssb
modifier|*
name|jme_ssb_block
decl_stmt|;
name|bus_addr_t
name|jme_ssb_block_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|JME_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->jme_rdata.jme_tx_ring_paddr + sizeof(struct jme_desc) * (i))
end_define

begin_define
define|#
directive|define
name|JME_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->jme_rdata.jme_rx_ring_paddr + sizeof(struct jme_desc) * (i))
end_define

begin_define
define|#
directive|define
name|JME_TX_RING_SIZE
define|\
value|(sizeof(struct jme_desc) * JME_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|JME_RX_RING_SIZE
define|\
value|(sizeof(struct jme_desc) * JME_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|JME_SSB_SIZE
value|sizeof(struct jme_ssb)
end_define

begin_comment
comment|/* Statistics counters. */
end_comment

begin_struct
struct|struct
name|jme_hw_stats
block|{
name|uint32_t
name|rx_good_frames
decl_stmt|;
name|uint32_t
name|rx_crc_errs
decl_stmt|;
name|uint32_t
name|rx_mii_errs
decl_stmt|;
name|uint32_t
name|rx_fifo_oflows
decl_stmt|;
name|uint32_t
name|rx_desc_empty
decl_stmt|;
name|uint32_t
name|rx_bad_frames
decl_stmt|;
name|uint32_t
name|tx_good_frames
decl_stmt|;
name|uint32_t
name|tx_bad_frames
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|jme_softc
block|{
name|struct
name|ifnet
modifier|*
name|jme_ifp
decl_stmt|;
name|device_t
name|jme_dev
decl_stmt|;
name|device_t
name|jme_miibus
decl_stmt|;
name|struct
name|resource
modifier|*
name|jme_res
index|[
literal|1
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|jme_res_spec
decl_stmt|;
name|struct
name|resource
modifier|*
name|jme_irq
index|[
name|JME_MSI_MESSAGES
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|jme_irq_spec
decl_stmt|;
name|void
modifier|*
name|jme_intrhand
index|[
name|JME_MSI_MESSAGES
index|]
decl_stmt|;
name|int
name|jme_rev
decl_stmt|;
name|int
name|jme_chip_rev
decl_stmt|;
name|int
name|jme_phyaddr
decl_stmt|;
name|uint8_t
name|jme_eaddr
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|uint32_t
name|jme_tx_dma_size
decl_stmt|;
name|uint32_t
name|jme_rx_dma_size
decl_stmt|;
name|int
name|jme_flags
decl_stmt|;
define|#
directive|define
name|JME_FLAG_FPGA
value|0x00000001
define|#
directive|define
name|JME_FLAG_PCIE
value|0x00000002
define|#
directive|define
name|JME_FLAG_PCIX
value|0x00000004
define|#
directive|define
name|JME_FLAG_MSI
value|0x00000008
define|#
directive|define
name|JME_FLAG_MSIX
value|0x00000010
define|#
directive|define
name|JME_FLAG_PMCAP
value|0x00000020
define|#
directive|define
name|JME_FLAG_FASTETH
value|0x00000040
define|#
directive|define
name|JME_FLAG_NOJUMBO
value|0x00000080
define|#
directive|define
name|JME_FLAG_RXCLK
value|0x00000100
define|#
directive|define
name|JME_FLAG_TXCLK
value|0x00000200
define|#
directive|define
name|JME_FLAG_DMA32BIT
value|0x00000400
define|#
directive|define
name|JME_FLAG_HWMIB
value|0x00000800
define|#
directive|define
name|JME_FLAG_EFUSE
value|0x00001000
define|#
directive|define
name|JME_FLAG_PCCPCD
value|0x00002000
define|#
directive|define
name|JME_FLAG_DETACH
value|0x40000000
define|#
directive|define
name|JME_FLAG_LINK
value|0x80000000
name|struct
name|jme_hw_stats
name|jme_ostats
decl_stmt|;
name|struct
name|jme_hw_stats
name|jme_stats
decl_stmt|;
name|struct
name|callout
name|jme_tick_ch
decl_stmt|;
name|struct
name|jme_chain_data
name|jme_cdata
decl_stmt|;
name|struct
name|jme_ring_data
name|jme_rdata
decl_stmt|;
name|int
name|jme_if_flags
decl_stmt|;
name|int
name|jme_watchdog_timer
decl_stmt|;
name|uint32_t
name|jme_txcsr
decl_stmt|;
name|uint32_t
name|jme_rxcsr
decl_stmt|;
name|int
name|jme_process_limit
decl_stmt|;
name|int
name|jme_tx_coal_to
decl_stmt|;
name|int
name|jme_tx_pcd_to
decl_stmt|;
name|int
name|jme_tx_coal_pkt
decl_stmt|;
name|int
name|jme_rx_coal_to
decl_stmt|;
name|int
name|jme_rx_pcd_to
decl_stmt|;
name|int
name|jme_rx_coal_pkt
decl_stmt|;
specifier|volatile
name|int
name|jme_morework
decl_stmt|;
name|struct
name|task
name|jme_int_task
decl_stmt|;
name|struct
name|task
name|jme_link_task
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|jme_tq
decl_stmt|;
name|struct
name|mtx
name|jme_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Register access macros. */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((_sc)->jme_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((_sc)->jme_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|JME_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->jme_mtx)
end_define

begin_define
define|#
directive|define
name|JME_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->jme_mtx)
end_define

begin_define
define|#
directive|define
name|JME_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->jme_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|JME_MAXERR
value|5
end_define

begin_define
define|#
directive|define
name|JME_RXCHAIN_RESET
parameter_list|(
name|_sc
parameter_list|)
define|\
value|do {									\ 	(_sc)->jme_cdata.jme_rxhead = NULL;				\ 	(_sc)->jme_cdata.jme_rxtail = NULL;				\ 	(_sc)->jme_cdata.jme_rxlen = 0;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|JME_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|JME_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|JME_PHY_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|JME_EEPROM_TIMEOUT
value|1000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

