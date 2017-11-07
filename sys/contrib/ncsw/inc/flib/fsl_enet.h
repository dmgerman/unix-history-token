begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_ENET_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_ENET_H
end_define

begin_comment
comment|/**  @Description  Ethernet MAC-PHY Interface */
end_comment

begin_enum
enum|enum
name|enet_interface
block|{
name|E_ENET_IF_MII
init|=
literal|0x00010000
block|,
comment|/**< MII interface */
name|E_ENET_IF_RMII
init|=
literal|0x00020000
block|,
comment|/**< RMII interface */
name|E_ENET_IF_SMII
init|=
literal|0x00030000
block|,
comment|/**< SMII interface */
name|E_ENET_IF_GMII
init|=
literal|0x00040000
block|,
comment|/**< GMII interface */
name|E_ENET_IF_RGMII
init|=
literal|0x00050000
block|,
comment|/**< RGMII interface */
name|E_ENET_IF_TBI
init|=
literal|0x00060000
block|,
comment|/**< TBI interface */
name|E_ENET_IF_RTBI
init|=
literal|0x00070000
block|,
comment|/**< RTBI interface */
name|E_ENET_IF_SGMII
init|=
literal|0x00080000
block|,
comment|/**< SGMII interface */
name|E_ENET_IF_XGMII
init|=
literal|0x00090000
block|,
comment|/**< XGMII interface */
name|E_ENET_IF_QSGMII
init|=
literal|0x000a0000
block|,
comment|/**< QSGMII interface */
name|E_ENET_IF_XFI
init|=
literal|0x000b0000
comment|/**< XFI interface */
block|}
enum|;
end_enum

begin_comment
comment|/**  @Description  Ethernet Speed (nominal data rate) */
end_comment

begin_enum
enum|enum
name|enet_speed
block|{
name|E_ENET_SPEED_10
init|=
literal|10
block|,
comment|/**< 10 Mbps */
name|E_ENET_SPEED_100
init|=
literal|100
block|,
comment|/**< 100 Mbps */
name|E_ENET_SPEED_1000
init|=
literal|1000
block|,
comment|/**< 1000 Mbps = 1 Gbps */
name|E_ENET_SPEED_2500
init|=
literal|2500
block|,
comment|/**< 2500 Mbps = 2.5 Gbps */
name|E_ENET_SPEED_10000
init|=
literal|10000
comment|/**< 10000 Mbps = 10 Gbps */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|mac_type
block|{
name|E_MAC_DTSEC
block|,
name|E_MAC_TGEC
block|,
name|E_MAC_MEMAC
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for inter-module interrupts registration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_event_modules
block|{
name|E_FMAN_MOD_PRS
block|,
comment|/**< Parser event */
name|E_FMAN_MOD_KG
block|,
comment|/**< Keygen event */
name|E_FMAN_MOD_PLCR
block|,
comment|/**< Policer event */
name|E_FMAN_MOD_10G_MAC
block|,
comment|/**< 10G MAC event */
name|E_FMAN_MOD_1G_MAC
block|,
comment|/**< 1G MAC event */
name|E_FMAN_MOD_TMR
block|,
comment|/**< Timer event */
name|E_FMAN_MOD_FMAN_CTRL
block|,
comment|/**< FMAN Controller  Timer event */
name|E_FMAN_MOD_MACSEC
block|,
name|E_FMAN_MOD_DUMMY_LAST
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Enum for interrupts types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_intr_type
block|{
name|E_FMAN_INTR_TYPE_ERR
block|,
name|E_FMAN_INTR_TYPE_NORMAL
block|}
enum|;
end_enum

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   enum for defining MAC types */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_enum
enum|enum
name|fman_mac_type
block|{
name|E_FMAN_MAC_10G
init|=
literal|0
block|,
comment|/**< 10G MAC */
name|E_FMAN_MAC_1G
comment|/**< 1G MAC */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fman_mac_exceptions
block|{
name|E_FMAN_MAC_EX_10G_MDIO_SCAN_EVENTMDIO
init|=
literal|0
block|,
comment|/**< 10GEC MDIO scan event interrupt */
name|E_FMAN_MAC_EX_10G_MDIO_CMD_CMPL
block|,
comment|/**< 10GEC MDIO command completion interrupt */
name|E_FMAN_MAC_EX_10G_REM_FAULT
block|,
comment|/**< 10GEC, mEMAC Remote fault interrupt */
name|E_FMAN_MAC_EX_10G_LOC_FAULT
block|,
comment|/**< 10GEC, mEMAC Local fault interrupt */
name|E_FMAN_MAC_EX_10G_1TX_ECC_ER
block|,
comment|/**< 10GEC, mEMAC Transmit frame ECC error interrupt */
name|E_FMAN_MAC_EX_10G_TX_FIFO_UNFL
block|,
comment|/**< 10GEC, mEMAC Transmit FIFO underflow interrupt */
name|E_FMAN_MAC_EX_10G_TX_FIFO_OVFL
block|,
comment|/**< 10GEC, mEMAC Transmit FIFO overflow interrupt */
name|E_FMAN_MAC_EX_10G_TX_ER
block|,
comment|/**< 10GEC Transmit frame error interrupt */
name|E_FMAN_MAC_EX_10G_RX_FIFO_OVFL
block|,
comment|/**< 10GEC, mEMAC Receive FIFO overflow interrupt */
name|E_FMAN_MAC_EX_10G_RX_ECC_ER
block|,
comment|/**< 10GEC, mEMAC Receive frame ECC error interrupt */
name|E_FMAN_MAC_EX_10G_RX_JAB_FRM
block|,
comment|/**< 10GEC Receive jabber frame interrupt */
name|E_FMAN_MAC_EX_10G_RX_OVRSZ_FRM
block|,
comment|/**< 10GEC Receive oversized frame interrupt */
name|E_FMAN_MAC_EX_10G_RX_RUNT_FRM
block|,
comment|/**< 10GEC Receive runt frame interrupt */
name|E_FMAN_MAC_EX_10G_RX_FRAG_FRM
block|,
comment|/**< 10GEC Receive fragment frame interrupt */
name|E_FMAN_MAC_EX_10G_RX_LEN_ER
block|,
comment|/**< 10GEC Receive payload length error interrupt */
name|E_FMAN_MAC_EX_10G_RX_CRC_ER
block|,
comment|/**< 10GEC Receive CRC error interrupt */
name|E_FMAN_MAC_EX_10G_RX_ALIGN_ER
block|,
comment|/**< 10GEC Receive alignment error interrupt */
name|E_FMAN_MAC_EX_1G_BAB_RX
block|,
comment|/**< dTSEC Babbling receive error */
name|E_FMAN_MAC_EX_1G_RX_CTL
block|,
comment|/**< dTSEC Receive control (pause frame) interrupt */
name|E_FMAN_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET
block|,
comment|/**< dTSEC Graceful transmit stop complete */
name|E_FMAN_MAC_EX_1G_BAB_TX
block|,
comment|/**< dTSEC Babbling transmit error */
name|E_FMAN_MAC_EX_1G_TX_CTL
block|,
comment|/**< dTSEC Transmit control (pause frame) interrupt */
name|E_FMAN_MAC_EX_1G_TX_ERR
block|,
comment|/**< dTSEC Transmit error */
name|E_FMAN_MAC_EX_1G_LATE_COL
block|,
comment|/**< dTSEC Late collision */
name|E_FMAN_MAC_EX_1G_COL_RET_LMT
block|,
comment|/**< dTSEC Collision retry limit */
name|E_FMAN_MAC_EX_1G_TX_FIFO_UNDRN
block|,
comment|/**< dTSEC Transmit FIFO underrun */
name|E_FMAN_MAC_EX_1G_MAG_PCKT
block|,
comment|/**< dTSEC Magic Packet detection */
name|E_FMAN_MAC_EX_1G_MII_MNG_RD_COMPLET
block|,
comment|/**< dTSEC MII management read completion */
name|E_FMAN_MAC_EX_1G_MII_MNG_WR_COMPLET
block|,
comment|/**< dTSEC MII management write completion */
name|E_FMAN_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET
block|,
comment|/**< dTSEC Graceful receive stop complete */
name|E_FMAN_MAC_EX_1G_TX_DATA_ERR
block|,
comment|/**< dTSEC Internal data error on transmit */
name|E_FMAN_MAC_EX_1G_RX_DATA_ERR
block|,
comment|/**< dTSEC Internal data error on receive */
name|E_FMAN_MAC_EX_1G_1588_TS_RX_ERR
block|,
comment|/**< dTSEC Time-Stamp Receive Error */
name|E_FMAN_MAC_EX_1G_RX_MIB_CNT_OVFL
block|,
comment|/**< dTSEC MIB counter overflow */
name|E_FMAN_MAC_EX_TS_FIFO_ECC_ERR
block|,
comment|/**< mEMAC Time-stamp FIFO ECC error interrupt; 		not supported on T4240/B4860 rev1 chips */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|ENET_IF_SGMII_BASEX
value|0x80000000
end_define

begin_comment
comment|/**< SGMII/QSGII interface with 1000BaseX auto-negotiation between MAC 	and phy or backplane; 	Note: 1000BaseX auto-negotiation relates only to interface between MAC 	and phy/backplane, SGMII phy can still synchronize with far-end phy at 	10Mbps, 100Mbps or 1000Mbps */
end_comment

begin_enum
enum|enum
name|enet_mode
block|{
name|E_ENET_MODE_INVALID
init|=
literal|0
block|,
comment|/**< Invalid Ethernet mode */
name|E_ENET_MODE_MII_10
init|=
operator|(
name|E_ENET_IF_MII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps MII   */
name|E_ENET_MODE_MII_100
init|=
operator|(
name|E_ENET_IF_MII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps MII   */
name|E_ENET_MODE_RMII_10
init|=
operator|(
name|E_ENET_IF_RMII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps RMII  */
name|E_ENET_MODE_RMII_100
init|=
operator|(
name|E_ENET_IF_RMII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps RMII  */
name|E_ENET_MODE_SMII_10
init|=
operator|(
name|E_ENET_IF_SMII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps SMII  */
name|E_ENET_MODE_SMII_100
init|=
operator|(
name|E_ENET_IF_SMII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps SMII  */
name|E_ENET_MODE_GMII_1000
init|=
operator|(
name|E_ENET_IF_GMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps GMII  */
name|E_ENET_MODE_RGMII_10
init|=
operator|(
name|E_ENET_IF_RGMII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**<    10 Mbps RGMII */
name|E_ENET_MODE_RGMII_100
init|=
operator|(
name|E_ENET_IF_RGMII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**<   100 Mbps RGMII */
name|E_ENET_MODE_RGMII_1000
init|=
operator|(
name|E_ENET_IF_RGMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps RGMII */
name|E_ENET_MODE_TBI_1000
init|=
operator|(
name|E_ENET_IF_TBI
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps TBI   */
name|E_ENET_MODE_RTBI_1000
init|=
operator|(
name|E_ENET_IF_RTBI
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**<  1000 Mbps RTBI  */
name|E_ENET_MODE_SGMII_10
init|=
operator|(
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**< 10 Mbps SGMII with auto-negotiation between MAC and 		SGMII phy according to Cisco SGMII specification */
name|E_ENET_MODE_SGMII_100
init|=
operator|(
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**< 100 Mbps SGMII with auto-negotiation between MAC and 		SGMII phy according to Cisco SGMII specification */
name|E_ENET_MODE_SGMII_1000
init|=
operator|(
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**< 1000 Mbps SGMII with auto-negotiation between MAC and 		SGMII phy according to Cisco SGMII specification */
name|E_ENET_MODE_SGMII_BASEX_10
init|=
operator|(
name|ENET_IF_SGMII_BASEX
operator||
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_10
operator|)
block|,
comment|/**< 10 Mbps SGMII with 1000BaseX auto-negotiation between 		MAC and SGMII phy or backplane */
name|E_ENET_MODE_SGMII_BASEX_100
init|=
operator|(
name|ENET_IF_SGMII_BASEX
operator||
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_100
operator|)
block|,
comment|/**< 100 Mbps SGMII with 1000BaseX auto-negotiation between 		MAC and SGMII phy or backplane */
name|E_ENET_MODE_SGMII_BASEX_1000
init|=
operator|(
name|ENET_IF_SGMII_BASEX
operator||
name|E_ENET_IF_SGMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**< 1000 Mbps SGMII with 1000BaseX auto-negotiation between 		MAC and SGMII phy or backplane */
name|E_ENET_MODE_QSGMII_1000
init|=
operator|(
name|E_ENET_IF_QSGMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**< 1000 Mbps QSGMII with auto-negotiation between MAC and 		QSGMII phy according to Cisco QSGMII specification */
name|E_ENET_MODE_QSGMII_BASEX_1000
init|=
operator|(
name|ENET_IF_SGMII_BASEX
operator||
name|E_ENET_IF_QSGMII
operator||
name|E_ENET_SPEED_1000
operator|)
block|,
comment|/**< 1000 Mbps QSGMII with 1000BaseX auto-negotiation between 		MAC and QSGMII phy or backplane */
name|E_ENET_MODE_XGMII_10000
init|=
operator|(
name|E_ENET_IF_XGMII
operator||
name|E_ENET_SPEED_10000
operator|)
block|,
comment|/**< 10000 Mbps XGMII */
name|E_ENET_MODE_XFI_10000
init|=
operator|(
name|E_ENET_IF_XFI
operator||
name|E_ENET_SPEED_10000
operator|)
comment|/**< 10000 Mbps XFI */
block|}
enum|;
end_enum

begin_enum
enum|enum
name|fmam_mac_statistics_level
block|{
name|E_FMAN_MAC_NONE_STATISTICS
block|,
comment|/**< No statistics */
name|E_FMAN_MAC_PARTIAL_STATISTICS
block|,
comment|/**< Only error counters are available; 					Optimized for performance */
name|E_FMAN_MAC_FULL_STATISTICS
comment|/**< All counters available; Not 					optimized for performance */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_MAKE_ENET_MODE
parameter_list|(
name|_interface
parameter_list|,
name|_speed
parameter_list|)
value|(enum enet_mode)((_interface) \ 	| (_speed))
end_define

begin_define
define|#
directive|define
name|_ENET_INTERFACE_FROM_MODE
parameter_list|(
name|mode
parameter_list|)
value|(enum enet_interface) \ 	((mode)& 0x0FFF0000)
end_define

begin_define
define|#
directive|define
name|_ENET_SPEED_FROM_MODE
parameter_list|(
name|mode
parameter_list|)
value|(enum enet_speed)((mode)& 0x0000FFFF)
end_define

begin_define
define|#
directive|define
name|_ENET_ADDR_TO_UINT64
parameter_list|(
name|_enet_addr
parameter_list|)
define|\
value|(uint64_t)(((uint64_t)(_enet_addr)[0]<< 40) |	\ 		((uint64_t)(_enet_addr)[1]<< 32) |	\ 		((uint64_t)(_enet_addr)[2]<< 24) |	\ 		((uint64_t)(_enet_addr)[3]<< 16) |	\ 		((uint64_t)(_enet_addr)[4]<< 8) |	\ 		((uint64_t)(_enet_addr)[5]))
end_define

begin_define
define|#
directive|define
name|_MAKE_ENET_ADDR_FROM_UINT64
parameter_list|(
name|_addr64
parameter_list|,
name|_enet_addr
parameter_list|)
define|\
value|do {								\ 		int i;							\ 		for (i = 0; i< ENET_NUM_OCTETS_PER_ADDRESS; i++)	\ 			(_enet_addr)[i] = (uint8_t)((_addr64)>> ((5-i)*8));\ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_ENET_H */
end_comment

end_unit

