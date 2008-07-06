begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2007   *	Oleksandr Tymoshenko<gonzo@freebsd.org>. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR HIS RELATIVES BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF MIND, USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_KRREG_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_KRREG_H__
end_define

begin_define
define|#
directive|define
name|KR_ETHINTFC
value|0x0000
end_define

begin_comment
comment|/* Ethernet interface control             */
end_comment

begin_define
define|#
directive|define
name|ETH_INTFC_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|ETH_INTFC_RIP
value|0x0004
end_define

begin_define
define|#
directive|define
name|ETH_INTFC_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|KR_ETHFIFOTT
value|0x0004
end_define

begin_comment
comment|/* Ethernet FIFO transmit threshold       */
end_comment

begin_define
define|#
directive|define
name|KR_ETHARC
value|0x0008
end_define

begin_comment
comment|/* Ethernet address recognition control   */
end_comment

begin_define
define|#
directive|define
name|KR_ETHHASH0
value|0x000C
end_define

begin_comment
comment|/* Ethernet hash table 0                  */
end_comment

begin_define
define|#
directive|define
name|KR_ETHHASH1
value|0x0010
end_define

begin_comment
comment|/* Ethernet hash table 1                  */
end_comment

begin_define
define|#
directive|define
name|KR_ETHPFS
value|0x0024
end_define

begin_comment
comment|/* Ethernet pause frame status            */
end_comment

begin_define
define|#
directive|define
name|KR_ETHMCP
value|0x0028
end_define

begin_comment
comment|/* Ethernet management clock prescalar    */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAL0
value|0x0100
end_define

begin_comment
comment|/* Ethernet station address 0 low         */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAH0
value|0x0104
end_define

begin_comment
comment|/* Ethernet station address 0 high        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAL1
value|0x0108
end_define

begin_comment
comment|/* Ethernet station address 1 low         */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAH1
value|0x010C
end_define

begin_comment
comment|/* Ethernet station address 1 high        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAL2
value|0x0110
end_define

begin_comment
comment|/* Ethernet station address 2 low         */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAH2
value|0x0114
end_define

begin_comment
comment|/* Ethernet station address 2 high        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAL3
value|0x0118
end_define

begin_comment
comment|/* Ethernet station address 3 low         */
end_comment

begin_define
define|#
directive|define
name|KR_ETHSAH3
value|0x011C
end_define

begin_comment
comment|/* Ethernet station address 3 high        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHRBC
value|0x0120
end_define

begin_comment
comment|/* Ethernet receive byte count            */
end_comment

begin_define
define|#
directive|define
name|KR_ETHRPC
value|0x0124
end_define

begin_comment
comment|/* Ethernet receive packet count          */
end_comment

begin_define
define|#
directive|define
name|KR_ETHRUPC
value|0x0128
end_define

begin_comment
comment|/* Ethernet receive undersized packet cnt */
end_comment

begin_define
define|#
directive|define
name|KR_ETHRFC
value|0x012C
end_define

begin_comment
comment|/* Ethernet receive fragment count        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHTBC
value|0x0130
end_define

begin_comment
comment|/* Ethernet transmit byte count           */
end_comment

begin_define
define|#
directive|define
name|KR_ETHGPF
value|0x0134
end_define

begin_comment
comment|/* Ethernet generate pause frame          */
end_comment

begin_define
define|#
directive|define
name|KR_ETHMAC1
value|0x0200
end_define

begin_comment
comment|/* Ethernet MAC configuration 1           */
end_comment

begin_define
define|#
directive|define
name|KR_ETH_MAC1_RE
value|0x01
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC1_PAF
value|0x02
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC1_MR
value|0x80
end_define

begin_define
define|#
directive|define
name|KR_ETHMAC2
value|0x0204
end_define

begin_comment
comment|/* Ethernet MAC configuration 2           */
end_comment

begin_define
define|#
directive|define
name|KR_ETH_MAC2_FD
value|0x01
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_FLC
value|0x02
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_HFE
value|0x04
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_DC
value|0x08
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_CEN
value|0x10
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_PEN
value|0x20
end_define

begin_define
define|#
directive|define
name|KR_ETH_MAC2_VPE
value|0x08
end_define

begin_define
define|#
directive|define
name|KR_ETHIPGT
value|0x0208
end_define

begin_comment
comment|/* Ethernet back-to-back inter-packet gap */
end_comment

begin_define
define|#
directive|define
name|KR_ETHIPGR
value|0x020C
end_define

begin_comment
comment|/* Ethernet non back-to-back inter-packet gap */
end_comment

begin_define
define|#
directive|define
name|KR_ETHCLRT
value|0x0210
end_define

begin_comment
comment|/* Ethernet collision window retry        */
end_comment

begin_define
define|#
directive|define
name|KR_ETHMAXF
value|0x0214
end_define

begin_comment
comment|/* Ethernet maximum frame length          */
end_comment

begin_define
define|#
directive|define
name|KR_ETHMTEST
value|0x021C
end_define

begin_comment
comment|/* Ethernet MAC test                      */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMCFG
value|0x0220
end_define

begin_comment
comment|/* MII management configuration           */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMCFG_R
value|0x8000
end_define

begin_define
define|#
directive|define
name|KR_MIIMCMD
value|0x0224
end_define

begin_comment
comment|/* MII management command                 */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMCMD_RD
value|0x01
end_define

begin_define
define|#
directive|define
name|KR_MIIMCMD_SCN
value|0x02
end_define

begin_define
define|#
directive|define
name|KR_MIIMADDR
value|0x0228
end_define

begin_comment
comment|/* MII management address                 */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMWTD
value|0x022C
end_define

begin_comment
comment|/* MII management write data              */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMRDD
value|0x0230
end_define

begin_comment
comment|/* MII management read data               */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMIND
value|0x0234
end_define

begin_comment
comment|/* MII management indicators              */
end_comment

begin_define
define|#
directive|define
name|KR_MIIMIND_BSY
value|0x1
end_define

begin_define
define|#
directive|define
name|KR_MIIMIND_SCN
value|0x2
end_define

begin_define
define|#
directive|define
name|KR_MIIMIND_NV
value|0x4
end_define

begin_define
define|#
directive|define
name|KR_ETHCFSA0
value|0x0240
end_define

begin_comment
comment|/* Ethernet control frame station address 0   */
end_comment

begin_define
define|#
directive|define
name|KR_ETHCFSA1
value|0x0244
end_define

begin_comment
comment|/* Ethernet control frame station address 1   */
end_comment

begin_define
define|#
directive|define
name|KR_ETHCFSA2
value|0x0248
end_define

begin_comment
comment|/* Ethernet control frame station address 2   */
end_comment

begin_define
define|#
directive|define
name|KR_ETHIPGT_HALF_DUPLEX
value|0x12
end_define

begin_define
define|#
directive|define
name|KR_ETHIPGT_FULL_DUPLEX
value|0x15
end_define

begin_define
define|#
directive|define
name|KR_TIMEOUT
value|0xf000
end_define

begin_define
define|#
directive|define
name|KR_MII_TIMEOUT
value|0xf000
end_define

begin_define
define|#
directive|define
name|KR_RX_IRQ
value|40
end_define

begin_define
define|#
directive|define
name|KR_TX_IRQ
value|41
end_define

begin_define
define|#
directive|define
name|KR_RX_UND_IRQ
value|42
end_define

begin_define
define|#
directive|define
name|KR_TX_OVR_IRQ
value|43
end_define

begin_define
define|#
directive|define
name|RC32434_DMA_BASE_ADDR
value|MIPS_PHYS_TO_KSEG1(0x18040000)
end_define

begin_define
define|#
directive|define
name|DMA_C
value|0x00
end_define

begin_define
define|#
directive|define
name|DMA_C_R
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_C_ABORT
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_S
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_S_F
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_S_D
value|0x02
end_define

begin_define
define|#
directive|define
name|DMA_S_C
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_S_E
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_S_H
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_SM
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_SM_F
value|0x01
end_define

begin_define
define|#
directive|define
name|DMA_SM_D
value|0x02
end_define

begin_define
define|#
directive|define
name|DMA_SM_C
value|0x04
end_define

begin_define
define|#
directive|define
name|DMA_SM_E
value|0x08
end_define

begin_define
define|#
directive|define
name|DMA_SM_H
value|0x10
end_define

begin_define
define|#
directive|define
name|DMA_DPTR
value|0x0C
end_define

begin_define
define|#
directive|define
name|DMA_NDPTR
value|0x10
end_define

begin_define
define|#
directive|define
name|RC32434_DMA_CHAN_SIZE
value|0x14
end_define

begin_define
define|#
directive|define
name|KR_DMA_RXCHAN
value|0
end_define

begin_define
define|#
directive|define
name|KR_DMA_TXCHAN
value|1
end_define

begin_define
define|#
directive|define
name|KR_DMA_READ_REG
parameter_list|(
name|chan
parameter_list|,
name|reg
parameter_list|)
define|\
value|(*(volatile uint32_t *)	\ 	    (RC32434_DMA_BASE_ADDR + chan * RC32434_DMA_CHAN_SIZE + reg))
end_define

begin_define
define|#
directive|define
name|KR_DMA_WRITE_REG
parameter_list|(
name|chan
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|((*(volatile uint32_t *)	\ 	    (RC32434_DMA_BASE_ADDR + chan * RC32434_DMA_CHAN_SIZE + reg)) = val)
end_define

begin_define
define|#
directive|define
name|KR_DMA_SETBITS_REG
parameter_list|(
name|chan
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|KR_DMA_WRITE_REG((chan), (reg), KR_DMA_READ_REG((chan), (reg)) | (bits))
end_define

begin_define
define|#
directive|define
name|KR_DMA_CLEARBITS_REG
parameter_list|(
name|chan
parameter_list|,
name|reg
parameter_list|,
name|bits
parameter_list|)
define|\
value|KR_DMA_WRITE_REG((chan), (reg),			\ 	    KR_DMA_READ_REG((chan), (reg))& ~(bits))
end_define

begin_struct
struct|struct
name|kr_desc
block|{
name|uint32_t
name|kr_ctl
decl_stmt|;
name|uint32_t
name|kr_ca
decl_stmt|;
name|uint32_t
name|kr_devcs
decl_stmt|;
name|uint32_t
name|kr_link
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KR_DMASIZE
parameter_list|(
name|len
parameter_list|)
value|((len)& ((1<< 18)-1))
end_define

begin_define
define|#
directive|define
name|KR_PKTSIZE
parameter_list|(
name|len
parameter_list|)
value|((len& 0xffff0000)>> 16)
end_define

begin_define
define|#
directive|define
name|KR_CTL_COF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_COD
value|0x04000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_IOF
value|0x08000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_IOD
value|0x10000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_T
value|0x20000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_D
value|0x40000000
end_define

begin_define
define|#
directive|define
name|KR_CTL_F
value|0x80000000
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_RSV
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_LD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_ROK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_FM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_MP
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_BP
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_VLT
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_CF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_OVR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_CRC
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_CV
value|0x00000400
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_DB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_LE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_LOR
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KR_DMARX_DEVCS_CES
value|0x00004000
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_FD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_LD
value|0x00000002
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_OEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_PEN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_CEN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_HEN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_TOK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_MP
value|0x00000080
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_BP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_UND
value|0x00000200
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_OF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_ED
value|0x00000800
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_EC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_LC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_TD
value|0x00004000
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_CRC
value|0x00008000
end_define

begin_define
define|#
directive|define
name|KR_DMATX_DEVCS_LE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|KR_RX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|KR_TX_RING_CNT
value|128
end_define

begin_define
define|#
directive|define
name|KR_TX_RING_SIZE
value|sizeof(struct kr_desc) * KR_TX_RING_CNT
end_define

begin_define
define|#
directive|define
name|KR_RX_RING_SIZE
value|sizeof(struct kr_desc) * KR_RX_RING_CNT
end_define

begin_define
define|#
directive|define
name|KR_RING_ALIGN
value|sizeof(struct kr_desc)
end_define

begin_define
define|#
directive|define
name|KR_RX_ALIGN
value|sizeof(uint32_t)
end_define

begin_define
define|#
directive|define
name|KR_MAXFRAGS
value|8
end_define

begin_define
define|#
directive|define
name|KR_TX_INTR_THRESH
value|8
end_define

begin_define
define|#
directive|define
name|KR_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->kr_rdata.kr_tx_ring_paddr + sizeof(struct kr_desc) * (i))
end_define

begin_define
define|#
directive|define
name|KR_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->kr_rdata.kr_rx_ring_paddr + sizeof(struct kr_desc) * (i))
end_define

begin_define
define|#
directive|define
name|KR_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (((x) + 1) % y)
end_define

begin_struct
struct|struct
name|kr_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kr_rxdesc
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
name|kr_desc
modifier|*
name|desc
decl_stmt|;
comment|/* Use this values on error instead of allocating new mbuf */
name|uint32_t
name|saved_ctl
decl_stmt|,
name|saved_ca
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kr_chain_data
block|{
name|bus_dma_tag_t
name|kr_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|kr_tx_tag
decl_stmt|;
name|struct
name|kr_txdesc
name|kr_txdesc
index|[
name|KR_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|kr_rx_tag
decl_stmt|;
name|struct
name|kr_rxdesc
name|kr_rxdesc
index|[
name|KR_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|kr_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|kr_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|kr_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|kr_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|kr_rx_sparemap
decl_stmt|;
name|int
name|kr_tx_pkts
decl_stmt|;
name|int
name|kr_tx_prod
decl_stmt|;
name|int
name|kr_tx_cons
decl_stmt|;
name|int
name|kr_tx_cnt
decl_stmt|;
name|int
name|kr_rx_cons
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kr_ring_data
block|{
name|struct
name|kr_desc
modifier|*
name|kr_rx_ring
decl_stmt|;
name|struct
name|kr_desc
modifier|*
name|kr_tx_ring
decl_stmt|;
name|bus_addr_t
name|kr_rx_ring_paddr
decl_stmt|;
name|bus_addr_t
name|kr_tx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|kr_softc
block|{
name|struct
name|ifnet
modifier|*
name|kr_ifp
decl_stmt|;
comment|/* interface info */
name|bus_space_handle_t
name|kr_bhandle
decl_stmt|;
comment|/* bus space handle */
name|bus_space_tag_t
name|kr_btag
decl_stmt|;
comment|/* bus space tag */
name|device_t
name|kr_dev
decl_stmt|;
name|struct
name|resource
modifier|*
name|kr_res
decl_stmt|;
name|int
name|kr_rid
decl_stmt|;
name|struct
name|resource
modifier|*
name|kr_rx_irq
decl_stmt|;
name|void
modifier|*
name|kr_rx_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|kr_tx_irq
decl_stmt|;
name|void
modifier|*
name|kr_tx_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|kr_rx_und_irq
decl_stmt|;
name|void
modifier|*
name|kr_rx_und_intrhand
decl_stmt|;
name|struct
name|resource
modifier|*
name|kr_tx_ovr_irq
decl_stmt|;
name|void
modifier|*
name|kr_tx_ovr_intrhand
decl_stmt|;
name|device_t
name|kr_miibus
decl_stmt|;
name|bus_dma_tag_t
name|kr_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|kr_tag
decl_stmt|;
name|struct
name|mtx
name|kr_mtx
decl_stmt|;
name|struct
name|callout
name|kr_stat_callout
decl_stmt|;
name|struct
name|task
name|kr_link_task
decl_stmt|;
name|struct
name|kr_chain_data
name|kr_cdata
decl_stmt|;
name|struct
name|kr_ring_data
name|kr_rdata
decl_stmt|;
name|int
name|kr_link_status
decl_stmt|;
name|int
name|kr_detach
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|KR_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->kr_mtx)
end_define

begin_define
define|#
directive|define
name|KR_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->kr_mtx)
end_define

begin_define
define|#
directive|define
name|KR_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->kr_mtx, MA_OWNED)
end_define

begin_comment
comment|/*  * register space access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_4(sc->kr_btag, sc->kr_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(sc->kr_btag, sc->kr_bhandle, reg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_KRREG_H__ */
end_comment

end_unit

