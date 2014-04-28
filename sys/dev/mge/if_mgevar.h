begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2008 MARVELL INTERNATIONAL LTD.  * All rights reserved.  *  * Developed by Semihalf.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of MARVELL nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_MGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__IF_MGE_H__
end_define

begin_define
define|#
directive|define
name|MGE_INTR_COUNT
value|5
end_define

begin_comment
comment|/* ETH controller occupies 5 IRQ lines */
end_comment

begin_define
define|#
directive|define
name|MGE_TX_DESC_NUM
value|256
end_define

begin_define
define|#
directive|define
name|MGE_RX_DESC_NUM
value|256
end_define

begin_define
define|#
directive|define
name|MGE_RX_QUEUE_NUM
value|8
end_define

begin_define
define|#
directive|define
name|MGE_RX_DEFAULT_QUEUE
value|0
end_define

begin_define
define|#
directive|define
name|MGE_CHECKSUM_FEATURES
value|(CSUM_IP | CSUM_TCP | CSUM_UDP)
end_define

begin_comment
comment|/* Interrupt Coalescing types */
end_comment

begin_define
define|#
directive|define
name|MGE_IC_RX
value|0
end_define

begin_define
define|#
directive|define
name|MGE_IC_TX
value|1
end_define

begin_struct
struct|struct
name|mge_desc
block|{
name|uint32_t
name|cmd_status
decl_stmt|;
name|uint16_t
name|buff_size
decl_stmt|;
name|uint16_t
name|byte_count
decl_stmt|;
name|bus_addr_t
name|buffer
decl_stmt|;
name|bus_addr_t
name|next_desc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mge_desc_wrapper
block|{
name|bus_dmamap_t
name|desc_dmap
decl_stmt|;
name|struct
name|mge_desc
modifier|*
name|mge_desc
decl_stmt|;
name|bus_addr_t
name|mge_desc_paddr
decl_stmt|;
name|bus_dmamap_t
name|buffer_dmap
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|buffer
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mge_softc
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* per-interface network data */
name|phandle_t
name|node
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|struct
name|mii_data
modifier|*
name|mii
decl_stmt|;
name|struct
name|resource
modifier|*
name|res
index|[
literal|1
operator|+
name|MGE_INTR_COUNT
index|]
decl_stmt|;
comment|/* resources */
name|void
modifier|*
name|ih_cookie
index|[
name|MGE_INTR_COUNT
index|]
decl_stmt|;
comment|/* interrupt handlers cookies */
name|struct
name|mtx
name|transmit_lock
decl_stmt|;
comment|/* transmitter lock */
name|struct
name|mtx
name|receive_lock
decl_stmt|;
comment|/* receiver lock */
name|uint32_t
name|mge_if_flags
decl_stmt|;
name|uint32_t
name|mge_media_status
decl_stmt|;
name|struct
name|callout
name|wd_callout
decl_stmt|;
name|int
name|wd_timer
decl_stmt|;
name|bus_dma_tag_t
name|mge_desc_dtag
decl_stmt|;
name|bus_dma_tag_t
name|mge_tx_dtag
decl_stmt|;
name|bus_dma_tag_t
name|mge_rx_dtag
decl_stmt|;
name|bus_addr_t
name|tx_desc_start
decl_stmt|;
name|bus_addr_t
name|rx_desc_start
decl_stmt|;
name|uint32_t
name|tx_desc_curr
decl_stmt|;
name|uint32_t
name|rx_desc_curr
decl_stmt|;
name|uint32_t
name|tx_desc_used_idx
decl_stmt|;
name|uint32_t
name|tx_desc_used_count
decl_stmt|;
name|uint32_t
name|rx_ic_time
decl_stmt|;
name|uint32_t
name|tx_ic_time
decl_stmt|;
name|struct
name|mge_desc_wrapper
name|mge_tx_desc
index|[
name|MGE_TX_DESC_NUM
index|]
decl_stmt|;
name|struct
name|mge_desc_wrapper
name|mge_rx_desc
index|[
name|MGE_RX_DESC_NUM
index|]
decl_stmt|;
name|uint32_t
name|mge_tfut_ipg_max
decl_stmt|;
comment|/* TX FIFO Urgent Threshold */
name|uint32_t
name|mge_rx_ipg_max
decl_stmt|;
name|uint32_t
name|mge_tx_arb_cfg
decl_stmt|;
name|uint32_t
name|mge_tx_tok_cfg
decl_stmt|;
name|uint32_t
name|mge_tx_tok_cnt
decl_stmt|;
name|uint16_t
name|mge_mtu
decl_stmt|;
name|int
name|mge_ver
decl_stmt|;
name|int
name|mge_intr_cnt
decl_stmt|;
name|uint8_t
name|mge_hw_csum
decl_stmt|;
name|struct
name|mge_softc
modifier|*
name|phy_sc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* bus access macros */
end_comment

begin_define
define|#
directive|define
name|MGE_READ
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((sc)->res[0], (reg))
end_define

begin_define
define|#
directive|define
name|MGE_WRITE
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((sc)->res[0], (reg), (val))
end_define

begin_comment
comment|/* Locking macros */
end_comment

begin_define
define|#
directive|define
name|MGE_TRANSMIT_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 			mtx_assert(&(sc)->receive_lock, MA_NOTOWNED);		\ 			mtx_lock(&(sc)->transmit_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|MGE_TRANSMIT_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->transmit_lock)
end_define

begin_define
define|#
directive|define
name|MGE_TRANSMIT_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->transmit_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MGE_RECEIVE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 			mtx_assert(&(sc)->transmit_lock, MA_NOTOWNED);		\ 			mtx_lock(&(sc)->receive_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|MGE_RECEIVE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->receive_lock)
end_define

begin_define
define|#
directive|define
name|MGE_RECEIVE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|mtx_assert(&(sc)->receive_lock, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MGE_GLOBAL_LOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 			if ((mtx_owned(&(sc)->transmit_lock) ? 1 : 0) !=	\ 			    (mtx_owned(&(sc)->receive_lock) ? 1 : 0)) {		\ 				panic("mge deadlock possibility detection!");	\ 			}							\ 			mtx_lock(&(sc)->transmit_lock);				\ 			mtx_lock(&(sc)->receive_lock);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|MGE_GLOBAL_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 			MGE_RECEIVE_UNLOCK(sc);					\ 			MGE_TRANSMIT_UNLOCK(sc);				\ } while (0)
end_define

begin_define
define|#
directive|define
name|MGE_GLOBAL_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|)
value|do {						\ 			MGE_TRANSMIT_LOCK_ASSERT(sc);				\ 			MGE_RECEIVE_LOCK_ASSERT(sc); 				\ } while (0)
end_define

begin_comment
comment|/* SMI-related macros */
end_comment

begin_define
define|#
directive|define
name|MGE_REG_PHYDEV
value|0x000
end_define

begin_define
define|#
directive|define
name|MGE_REG_SMI
value|0x004
end_define

begin_define
define|#
directive|define
name|MGE_SMI_READ
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|MGE_SMI_WRITE
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|MGE_SMI_READVALID
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MGE_SMI_BUSY
value|(1<< 28)
end_define

begin_comment
comment|/* TODO verify the timings and retries count w/specs */
end_comment

begin_define
define|#
directive|define
name|MGE_SMI_READ_RETRIES
value|1000
end_define

begin_define
define|#
directive|define
name|MGE_SMI_READ_DELAY
value|100
end_define

begin_define
define|#
directive|define
name|MGE_SMI_WRITE_RETRIES
value|1000
end_define

begin_define
define|#
directive|define
name|MGE_SMI_WRITE_DELAY
value|100
end_define

begin_comment
comment|/* MGE registers */
end_comment

begin_define
define|#
directive|define
name|MGE_INT_CAUSE
value|0x080
end_define

begin_define
define|#
directive|define
name|MGE_INT_MASK
value|0x084
end_define

begin_define
define|#
directive|define
name|MGE_PORT_CONFIG
value|0x400
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_UPM
value|(1<< 0)
end_define

begin_comment
comment|/* promiscuous */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_DFLT_RXQ
parameter_list|(
name|val
parameter_list|)
value|(((val)& 7)<< 1)
end_define

begin_comment
comment|/* default RX queue */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ARO_RXQ
parameter_list|(
name|val
parameter_list|)
value|(((val)& 7)<< 4)
end_define

begin_comment
comment|/* ARP RX queue */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_REJECT_BCAST
value|(1<< 7)
end_define

begin_comment
comment|/* reject non-ip and non-arp bcast */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_REJECT_IP_BCAST
value|(1<< 8)
end_define

begin_comment
comment|/* reject ip bcast */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_REJECT_ARP__BCAST
value|(1<< 9)
end_define

begin_comment
comment|/* reject arp bcast */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_AMNoTxES
value|(1<< 12)
end_define

begin_comment
comment|/* Automatic mode not updating Error Summary in Tx descriptor */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_TCP_CAP
value|(1<< 14)
end_define

begin_comment
comment|/* capture tcp to a different queue */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_UDP_CAP
value|(1<< 15)
end_define

begin_comment
comment|/* capture udp to a different queue */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_TCPQ
value|(7<< 16)
end_define

begin_comment
comment|/* queue to capture tcp */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_UDPQ
value|(7<< 19)
end_define

begin_comment
comment|/* queue to capture udp */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_BPDUQ
value|(7<< 22)
end_define

begin_comment
comment|/* queue to capture bpdu */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_RXCS
value|(1<< 25)
end_define

begin_comment
comment|/* calculation Rx TCP checksum include pseudo header */
end_comment

begin_define
define|#
directive|define
name|MGE_PORT_EXT_CONFIG
value|0x404
end_define

begin_define
define|#
directive|define
name|MGE_MAC_ADDR_L
value|0x414
end_define

begin_define
define|#
directive|define
name|MGE_MAC_ADDR_H
value|0x418
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_CONFIG
value|0x41c
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_INT_ON_FRAME_BOUND
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_RX_BURST_SIZE
parameter_list|(
name|val
parameter_list|)
value|(((val)& 7)<< 1)
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_TX_BURST_SIZE
parameter_list|(
name|val
parameter_list|)
value|(((val)& 7)<< 22)
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_BURST_1_WORD
value|0x0
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_BURST_2_WORD
value|0x1
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_BURST_4_WORD
value|0x2
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_BURST_8_WORD
value|0x3
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_BURST_16_WORD
value|0x4
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_RX_BYTE_SWAP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_TX_BYTE_SWAP
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGE_SDMA_DESC_SWAP_MODE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_SERIAL_CTRL
value|0x43c
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_ENABLE
value|(1<< 0)
end_define

begin_comment
comment|/* serial port enable */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_FORCE_LINKUP
value|(1<< 1)
end_define

begin_comment
comment|/* force link status to up */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_AUTONEG
value|(1<< 2)
end_define

begin_comment
comment|/* enable autoneg for duplex mode */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_AUTONEG_FC
value|(1<< 3)
end_define

begin_comment
comment|/* enable autoneg for FC */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_PAUSE_ADV
value|(1<< 4)
end_define

begin_comment
comment|/* advertise symmetric FC in autoneg */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_FORCE_FC
parameter_list|(
name|val
parameter_list|)
value|(((val)& 3)<< 5)
end_define

begin_comment
comment|/* pause enable& disable frames conf */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_NO_PAUSE_DIS
value|0x00
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_PAUSE_DIS
value|0x01
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_FORCE_BP
parameter_list|(
name|val
parameter_list|)
value|(((val)& 3)<< 7)
end_define

begin_comment
comment|/* transmitting JAM configuration */
end_comment

begin_define
define|#
directive|define
name|PORT_SERIAL_NO_JAM
value|0x00
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_JAM
value|0x01
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_RES_BIT9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_FORCE_LINK_FAIL
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_SPEED_AUTONEG
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_FORCE_DTE_ADV
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU
parameter_list|(
name|val
parameter_list|)
value|(((val)& 7)<< 17)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_1518
value|0x0
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_1522
value|0x1
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_1552
value|0x2
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_9022
value|0x3
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_9192
value|0x4
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MRU_9700
value|0x5
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_FULL_DUPLEX
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_FULL_DUPLEX_FC
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_GMII_SPEED_1000
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|PORT_SERIAL_MII_SPEED_100
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_STATUS
value|0x444
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_LINKUP
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_FULL_DUPLEX
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_FLOW_CONTROL
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_1000MB
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_100MB
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_TX_IN_PROG
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MGE_STATUS_TX_FIFO_EMPTY
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MGE_TX_QUEUE_CMD
value|0x448
end_define

begin_define
define|#
directive|define
name|MGE_ENABLE_TXQ
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGE_DISABLE_TXQ
value|(1<< 8)
end_define

begin_comment
comment|/* 88F6281 only */
end_comment

begin_define
define|#
directive|define
name|MGE_PORT_SERIAL_CTRL1
value|0x44c
end_define

begin_define
define|#
directive|define
name|MGE_PCS_LOOPBACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGE_RGMII_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_RESET
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MGE_CLK125_BYPASS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|MGE_INBAND_AUTONEG
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MGE_INBAND_AUTONEG_BYPASS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|MGE_INBAND_AUTONEG_RESTART
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|MGE_1000BASEX
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MGE_BP_COLLISION_COUNT
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MGE_COLLISION_LIMIT
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0x3f)<< 16)
end_define

begin_define
define|#
directive|define
name|MGE_DROP_ODD_PREAMBLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_CAUSE
value|0x460
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_MASK
value|0x468
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_RX
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXTEND
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_RXQ0
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_RXERR
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_RXERRQ0
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_SUM
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_CAUSE_EXT
value|0x464
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_MASK_EXT
value|0x46C
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_TXBUF0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_TXERR0
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_PHYSC
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_RXOR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_TXUR
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_LC
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_IAR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MGE_PORT_INT_EXT_SUM
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MGE_RX_FIFO_URGENT_TRSH
value|0x470
end_define

begin_define
define|#
directive|define
name|MGE_TX_FIFO_URGENT_TRSH
value|0x474
end_define

begin_define
define|#
directive|define
name|MGE_FIXED_PRIO_CONF
value|0x4dc
end_define

begin_define
define|#
directive|define
name|MGE_FIXED_PRIO_EN
parameter_list|(
name|q
parameter_list|)
value|(1<< (q))
end_define

begin_define
define|#
directive|define
name|MGE_RX_CUR_DESC_PTR
parameter_list|(
name|q
parameter_list|)
value|(0x60c + ((q)<<4))
end_define

begin_define
define|#
directive|define
name|MGE_RX_QUEUE_CMD
value|0x680
end_define

begin_define
define|#
directive|define
name|MGE_ENABLE_RXQ
parameter_list|(
name|q
parameter_list|)
value|(1<< ((q)& 0x7))
end_define

begin_define
define|#
directive|define
name|MGE_ENABLE_RXQ_ALL
value|(0xff)
end_define

begin_define
define|#
directive|define
name|MGE_DISABLE_RXQ
parameter_list|(
name|q
parameter_list|)
value|(1<< (((q)& 0x7) + 8))
end_define

begin_define
define|#
directive|define
name|MGE_DISABLE_RXQ_ALL
value|(0xff00)
end_define

begin_define
define|#
directive|define
name|MGE_TX_CUR_DESC_PTR
value|0x6c0
end_define

begin_define
define|#
directive|define
name|MGE_TX_TOKEN_COUNT
parameter_list|(
name|q
parameter_list|)
value|(0x700 + ((q)<<4))
end_define

begin_define
define|#
directive|define
name|MGE_TX_TOKEN_CONF
parameter_list|(
name|q
parameter_list|)
value|(0x704 + ((q)<<4))
end_define

begin_define
define|#
directive|define
name|MGE_TX_ARBITER_CONF
parameter_list|(
name|q
parameter_list|)
value|(0x704 + ((q)<<4))
end_define

begin_define
define|#
directive|define
name|MGE_MCAST_REG_NUMBER
value|64
end_define

begin_define
define|#
directive|define
name|MGE_DA_FILTER_SPEC_MCAST
parameter_list|(
name|i
parameter_list|)
value|(0x1400 + ((i)<< 2))
end_define

begin_define
define|#
directive|define
name|MGE_DA_FILTER_OTH_MCAST
parameter_list|(
name|i
parameter_list|)
value|(0x1500 + ((i)<< 2))
end_define

begin_define
define|#
directive|define
name|MGE_UCAST_REG_NUMBER
value|4
end_define

begin_define
define|#
directive|define
name|MGE_DA_FILTER_UCAST
parameter_list|(
name|i
parameter_list|)
value|(0x1600 + ((i)<< 2))
end_define

begin_comment
comment|/* TX descriptor bits */
end_comment

begin_define
define|#
directive|define
name|MGE_TX_LLC_SNAP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|MGE_TX_NOT_FRAGMENT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|MGE_TX_VLAN_TAGGED
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|MGE_TX_UDP
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|MGE_TX_GEN_L4_CSUM
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|MGE_TX_GEN_IP_CSUM
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|MGE_TX_PADDING
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|MGE_TX_LAST
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|MGE_TX_FIRST
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|MGE_TX_ETH_CRC
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|MGE_TX_EN_INT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|MGE_TX_IP_HDR_SIZE
parameter_list|(
name|size
parameter_list|)
value|((size<< 11)& 0xFFFF)
end_define

begin_comment
comment|/* RX descriptor bits */
end_comment

begin_define
define|#
directive|define
name|MGE_ERR_SUMMARY
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|MGE_ERR_MASK
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_PROTO_MASK
value|(3<< 21)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_PROTO_TCP
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_PROTO_UDP
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L3_IS_IP
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|MGE_RX_IP_OK
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|MGE_RX_DESC_LAST
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|MGE_RX_DESC_FIRST
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|MGE_RX_ENABLE_INT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_CSUM_OK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|MGE_DMA_OWNED
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|MGE_RX_IP_FRAGMENT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_IS_TCP
parameter_list|(
name|status
parameter_list|)
value|((status& MGE_RX_L4_PROTO_MASK) \ 					    == MGE_RX_L4_PROTO_TCP)
end_define

begin_define
define|#
directive|define
name|MGE_RX_L4_IS_UDP
parameter_list|(
name|status
parameter_list|)
value|((status& MGE_RX_L4_PROTO_MASK) \ 					    == MGE_RX_L4_PROTO_UDP)
end_define

begin_comment
comment|/* TX error codes */
end_comment

begin_define
define|#
directive|define
name|MGE_TX_ERROR_LC
value|(0<< 1)
end_define

begin_comment
comment|/* Late collision */
end_comment

begin_define
define|#
directive|define
name|MGE_TX_ERROR_UR
value|(1<< 1)
end_define

begin_comment
comment|/* Underrun error */
end_comment

begin_define
define|#
directive|define
name|MGE_TX_ERROR_RL
value|(2<< 1)
end_define

begin_comment
comment|/* Excessive collision */
end_comment

begin_comment
comment|/* RX error codes */
end_comment

begin_define
define|#
directive|define
name|MGE_RX_ERROR_CE
value|(0<< 1)
end_define

begin_comment
comment|/* CRC error */
end_comment

begin_define
define|#
directive|define
name|MGE_RX_ERROR_OR
value|(1<< 1)
end_define

begin_comment
comment|/* Overrun error */
end_comment

begin_define
define|#
directive|define
name|MGE_RX_ERROR_MF
value|(2<< 1)
end_define

begin_comment
comment|/* Max frame lenght error */
end_comment

begin_define
define|#
directive|define
name|MGE_RX_ERROR_RE
value|(3<< 1)
end_define

begin_comment
comment|/* Resource error */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IF_MGE_H__ */
end_comment

end_unit

