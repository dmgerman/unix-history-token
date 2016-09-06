begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_eth_mac_regs.h  *  * @brief Ethernet MAC registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_ETH_MAC_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_ETH_MAC_REGS_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* * Unit Registers */
struct|struct
name|al_eth_mac_1g_stats
block|{
name|uint32_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
name|uint32_t
name|aFramesTransmittedOK
decl_stmt|;
comment|/* 0x68 */
name|uint32_t
name|aFramesReceivedOK
decl_stmt|;
comment|/* 0x6c */
name|uint32_t
name|aFrameCheckSequenceErrors
decl_stmt|;
comment|/* 0x70 */
name|uint32_t
name|aAlignmentErrors
decl_stmt|;
comment|/* 0x74 */
name|uint32_t
name|aOctetsTransmittedOK
decl_stmt|;
comment|/* 0x78 */
name|uint32_t
name|aOctetsReceivedOK
decl_stmt|;
comment|/* 0x7c */
name|uint32_t
name|aPAUSEMACCtrlFramesTransmitted
decl_stmt|;
comment|/* 0x80 */
name|uint32_t
name|aPAUSEMACCtrlFramesReceived
decl_stmt|;
comment|/* 0x84 */
name|uint32_t
name|ifInErrors
decl_stmt|;
comment|/* 0x88 */
name|uint32_t
name|ifOutErrors
decl_stmt|;
comment|/* 0x8c */
name|uint32_t
name|ifInUcastPkts
decl_stmt|;
comment|/* 0x90 */
name|uint32_t
name|ifInMulticastPkts
decl_stmt|;
comment|/* 0x94 */
name|uint32_t
name|ifInBroadcastPkts
decl_stmt|;
comment|/* 0x98 */
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|ifOutUcastPkts
decl_stmt|;
comment|/* 0xa0 */
name|uint32_t
name|ifOutMulticastPkts
decl_stmt|;
comment|/* 0xa4 */
name|uint32_t
name|ifOutBroadcastPkts
decl_stmt|;
comment|/* 0xa8 */
name|uint32_t
name|etherStatsDropEvents
decl_stmt|;
comment|/* 0xac */
name|uint32_t
name|etherStatsOctets
decl_stmt|;
comment|/* 0xb0 */
name|uint32_t
name|etherStatsPkts
decl_stmt|;
comment|/* 0xb4 */
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
comment|/* 0xb8 */
name|uint32_t
name|etherStatsOversizePkts
decl_stmt|;
comment|/* 0xbc */
name|uint32_t
name|etherStatsPkts64Octets
decl_stmt|;
comment|/* 0xc0 */
name|uint32_t
name|etherStatsPkts65to127Octets
decl_stmt|;
comment|/* 0xc4 */
name|uint32_t
name|etherStatsPkts128to255Octets
decl_stmt|;
comment|/* 0xc8 */
name|uint32_t
name|etherStatsPkts256to511Octets
decl_stmt|;
comment|/* 0xcc */
name|uint32_t
name|etherStatsPkts512to1023Octets
decl_stmt|;
comment|/* 0xd0 */
name|uint32_t
name|etherStatsPkts1024to1518Octets
decl_stmt|;
comment|/* 0xd4 */
name|uint32_t
name|etherStatsPkts1519toX
decl_stmt|;
comment|/* 0xd8 */
name|uint32_t
name|etherStatsJabbers
decl_stmt|;
comment|/* 0xdc */
name|uint32_t
name|etherStatsFragments
decl_stmt|;
comment|/* 0xe0 */
name|uint32_t
name|reserved3
index|[
literal|71
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_1g
block|{
comment|/* [0x0] */
name|uint32_t
name|rev
decl_stmt|;
name|uint32_t
name|scratch
decl_stmt|;
name|uint32_t
name|cmd_cfg
decl_stmt|;
name|uint32_t
name|mac_0
decl_stmt|;
comment|/* [0x10] */
name|uint32_t
name|mac_1
decl_stmt|;
name|uint32_t
name|frm_len
decl_stmt|;
name|uint32_t
name|pause_quant
decl_stmt|;
name|uint32_t
name|rx_section_empty
decl_stmt|;
comment|/* [0x20] */
name|uint32_t
name|rx_section_full
decl_stmt|;
name|uint32_t
name|tx_section_empty
decl_stmt|;
name|uint32_t
name|tx_section_full
decl_stmt|;
name|uint32_t
name|rx_almost_empty
decl_stmt|;
comment|/* [0x30] */
name|uint32_t
name|rx_almost_full
decl_stmt|;
name|uint32_t
name|tx_almost_empty
decl_stmt|;
name|uint32_t
name|tx_almost_full
decl_stmt|;
name|uint32_t
name|mdio_addr0
decl_stmt|;
comment|/* [0x40] */
name|uint32_t
name|mdio_addr1
decl_stmt|;
name|uint32_t
name|Reserved
index|[
literal|5
index|]
decl_stmt|;
comment|/* [0x58] */
name|uint32_t
name|reg_stat
decl_stmt|;
name|uint32_t
name|tx_ipg_len
decl_stmt|;
comment|/* [0x60] */
name|struct
name|al_eth_mac_1g_stats
name|stats
decl_stmt|;
comment|/* [0x200] */
name|uint32_t
name|phy_regs_base
decl_stmt|;
name|uint32_t
name|Reserved2
index|[
literal|127
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_10g_stats_v2
block|{
name|uint32_t
name|aFramesTransmittedOK
decl_stmt|;
comment|/* 0x80 */
name|uint32_t
name|reserved1
decl_stmt|;
name|uint32_t
name|aFramesReceivedOK
decl_stmt|;
comment|/* 0x88 */
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|aFrameCheckSequenceErrors
decl_stmt|;
comment|/* 0x90 */
name|uint32_t
name|reserved3
decl_stmt|;
name|uint32_t
name|aAlignmentErrors
decl_stmt|;
comment|/* 0x98 */
name|uint32_t
name|reserved4
decl_stmt|;
name|uint32_t
name|aPAUSEMACCtrlFramesTransmitted
decl_stmt|;
comment|/* 0xa0 */
name|uint32_t
name|reserved5
decl_stmt|;
name|uint32_t
name|aPAUSEMACCtrlFramesReceived
decl_stmt|;
comment|/* 0xa8 */
name|uint32_t
name|reserved6
decl_stmt|;
name|uint32_t
name|aFrameTooLongErrors
decl_stmt|;
comment|/* 0xb0 */
name|uint32_t
name|reserved7
decl_stmt|;
name|uint32_t
name|aInRangeLengthErrors
decl_stmt|;
comment|/* 0xb8 */
name|uint32_t
name|reserved8
decl_stmt|;
name|uint32_t
name|VLANTransmittedOK
decl_stmt|;
comment|/* 0xc0 */
name|uint32_t
name|reserved9
decl_stmt|;
name|uint32_t
name|VLANReceivedOK
decl_stmt|;
comment|/* 0xc8 */
name|uint32_t
name|reserved10
decl_stmt|;
name|uint32_t
name|ifOutOctetsL
decl_stmt|;
comment|/* 0xd0 */
name|uint32_t
name|ifOutOctetsH
decl_stmt|;
comment|/* 0xd4 */
name|uint32_t
name|ifInOctetsL
decl_stmt|;
comment|/* 0xd8 */
name|uint32_t
name|ifInOctetsH
decl_stmt|;
comment|/* 0xdc */
name|uint32_t
name|ifInUcastPkts
decl_stmt|;
comment|/* 0xe0 */
name|uint32_t
name|reserved11
decl_stmt|;
name|uint32_t
name|ifInMulticastPkts
decl_stmt|;
comment|/* 0xe8 */
name|uint32_t
name|reserved12
decl_stmt|;
name|uint32_t
name|ifInBroadcastPkts
decl_stmt|;
comment|/* 0xf0 */
name|uint32_t
name|reserved13
decl_stmt|;
name|uint32_t
name|ifOutErrors
decl_stmt|;
comment|/* 0xf8 */
name|uint32_t
name|reserved14
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|ifOutUcastPkts
decl_stmt|;
comment|/* 0x108 */
name|uint32_t
name|reserved15
decl_stmt|;
name|uint32_t
name|ifOutMulticastPkts
decl_stmt|;
comment|/* 0x110 */
name|uint32_t
name|reserved16
decl_stmt|;
name|uint32_t
name|ifOutBroadcastPkts
decl_stmt|;
comment|/* 0x118 */
name|uint32_t
name|reserved17
decl_stmt|;
name|uint32_t
name|etherStatsDropEvents
decl_stmt|;
comment|/* 0x120 */
name|uint32_t
name|reserved18
decl_stmt|;
name|uint32_t
name|etherStatsOctets
decl_stmt|;
comment|/* 0x128 */
name|uint32_t
name|reserved19
decl_stmt|;
name|uint32_t
name|etherStatsPkts
decl_stmt|;
comment|/* 0x130 */
name|uint32_t
name|reserved20
decl_stmt|;
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
comment|/* 0x138 */
name|uint32_t
name|reserved21
decl_stmt|;
name|uint32_t
name|etherStatsPkts64Octets
decl_stmt|;
comment|/* 0x140 */
name|uint32_t
name|reserved22
decl_stmt|;
name|uint32_t
name|etherStatsPkts65to127Octets
decl_stmt|;
comment|/* 0x148 */
name|uint32_t
name|reserved23
decl_stmt|;
name|uint32_t
name|etherStatsPkts128to255Octets
decl_stmt|;
comment|/* 0x150 */
name|uint32_t
name|reserved24
decl_stmt|;
name|uint32_t
name|etherStatsPkts256to511Octets
decl_stmt|;
comment|/* 0x158 */
name|uint32_t
name|reserved25
decl_stmt|;
name|uint32_t
name|etherStatsPkts512to1023Octets
decl_stmt|;
comment|/* 0x160 */
name|uint32_t
name|reserved26
decl_stmt|;
name|uint32_t
name|etherStatsPkts1024to1518Octets
decl_stmt|;
comment|/* 0x168 */
name|uint32_t
name|reserved27
decl_stmt|;
name|uint32_t
name|etherStatsPkts1519toX
decl_stmt|;
comment|/* 0x170 */
name|uint32_t
name|reserved28
decl_stmt|;
name|uint32_t
name|etherStatsOversizePkts
decl_stmt|;
comment|/* 0x178 */
name|uint32_t
name|reserved29
decl_stmt|;
name|uint32_t
name|etherStatsJabbers
decl_stmt|;
comment|/* 0x180 */
name|uint32_t
name|reserved30
decl_stmt|;
name|uint32_t
name|etherStatsFragments
decl_stmt|;
comment|/* 0x188 */
name|uint32_t
name|reserved31
decl_stmt|;
name|uint32_t
name|ifInErrors
decl_stmt|;
comment|/* 0x190 */
name|uint32_t
name|reserved32
index|[
literal|91
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_10g_stats_v3_rx
block|{
name|uint32_t
name|etherStatsOctets
decl_stmt|;
comment|/* 0x00 */
name|uint32_t
name|reserved2
decl_stmt|;
name|uint32_t
name|ifOctetsL
decl_stmt|;
comment|/* 0x08 */
name|uint32_t
name|ifOctetsH
decl_stmt|;
comment|/* 0x0c */
name|uint32_t
name|aAlignmentErrors
decl_stmt|;
comment|/* 0x10 */
name|uint32_t
name|reserved4
decl_stmt|;
name|uint32_t
name|aPAUSEMACCtrlFrames
decl_stmt|;
comment|/* 0x18 */
name|uint32_t
name|reserved5
decl_stmt|;
name|uint32_t
name|FramesOK
decl_stmt|;
comment|/* 0x20 */
name|uint32_t
name|reserved6
decl_stmt|;
name|uint32_t
name|CRCErrors
decl_stmt|;
comment|/* 0x28 */
name|uint32_t
name|reserved7
decl_stmt|;
name|uint32_t
name|VLANOK
decl_stmt|;
comment|/* 0x30 */
name|uint32_t
name|reserved8
decl_stmt|;
name|uint32_t
name|ifInErrors
decl_stmt|;
comment|/* 0x38 */
name|uint32_t
name|reserved9
decl_stmt|;
name|uint32_t
name|ifInUcastPkts
decl_stmt|;
comment|/* 0x40 */
name|uint32_t
name|reserved10
decl_stmt|;
name|uint32_t
name|ifInMulticastPkts
decl_stmt|;
comment|/* 0x48 */
name|uint32_t
name|reserved11
decl_stmt|;
name|uint32_t
name|ifInBroadcastPkts
decl_stmt|;
comment|/* 0x50 */
name|uint32_t
name|reserved12
decl_stmt|;
name|uint32_t
name|etherStatsDropEvents
decl_stmt|;
comment|/* 0x58 */
name|uint32_t
name|reserved13
decl_stmt|;
name|uint32_t
name|etherStatsPkts
decl_stmt|;
comment|/* 0x60 */
name|uint32_t
name|reserved14
decl_stmt|;
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
comment|/* 0x68 */
name|uint32_t
name|reserved15
decl_stmt|;
name|uint32_t
name|etherStatsPkts64Octets
decl_stmt|;
comment|/* 0x70 */
name|uint32_t
name|reserved16
decl_stmt|;
name|uint32_t
name|etherStatsPkts65to127Octets
decl_stmt|;
comment|/* 0x78 */
name|uint32_t
name|reserved17
decl_stmt|;
name|uint32_t
name|etherStatsPkts128to255Octets
decl_stmt|;
comment|/* 0x80 */
name|uint32_t
name|reserved18
decl_stmt|;
name|uint32_t
name|etherStatsPkts256to511Octets
decl_stmt|;
comment|/* 0x88 */
name|uint32_t
name|reserved19
decl_stmt|;
name|uint32_t
name|etherStatsPkts512to1023Octets
decl_stmt|;
comment|/* 0x90 */
name|uint32_t
name|reserved20
decl_stmt|;
name|uint32_t
name|etherStatsPkts1024to1518Octets
decl_stmt|;
comment|/* 0x98 */
name|uint32_t
name|reserved21
decl_stmt|;
name|uint32_t
name|etherStatsPkts1519toMax
decl_stmt|;
comment|/* 0xa0 */
name|uint32_t
name|reserved22
decl_stmt|;
name|uint32_t
name|etherStatsOversizePkts
decl_stmt|;
comment|/* 0xa8 */
name|uint32_t
name|reserved23
decl_stmt|;
name|uint32_t
name|etherStatsJabbers
decl_stmt|;
comment|/* 0xb0 */
name|uint32_t
name|reserved24
decl_stmt|;
name|uint32_t
name|etherStatsFragments
decl_stmt|;
comment|/* 0xb8 */
name|uint32_t
name|reserved25
decl_stmt|;
name|uint32_t
name|aMACControlFramesReceived
decl_stmt|;
comment|/* 0xc0 */
name|uint32_t
name|reserved26
decl_stmt|;
name|uint32_t
name|aFrameTooLong
decl_stmt|;
comment|/* 0xc8 */
name|uint32_t
name|reserved27
decl_stmt|;
name|uint32_t
name|aInRangeLengthErrors
decl_stmt|;
comment|/* 0xd0 */
name|uint32_t
name|reserved28
decl_stmt|;
name|uint32_t
name|reserved29
index|[
literal|10
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_10g_stats_v3_tx
block|{
name|uint32_t
name|etherStatsOctets
decl_stmt|;
comment|/* 0x00 */
name|uint32_t
name|reserved30
decl_stmt|;
name|uint32_t
name|ifOctetsL
decl_stmt|;
comment|/* 0x08 */
name|uint32_t
name|ifOctetsH
decl_stmt|;
comment|/* 0x0c */
name|uint32_t
name|aAlignmentErrors
decl_stmt|;
comment|/* 0x10 */
name|uint32_t
name|reserved32
decl_stmt|;
name|uint32_t
name|aPAUSEMACCtrlFrames
decl_stmt|;
comment|/* 0x18 */
name|uint32_t
name|reserved33
decl_stmt|;
name|uint32_t
name|FramesOK
decl_stmt|;
comment|/* 0x20 */
name|uint32_t
name|reserved34
decl_stmt|;
name|uint32_t
name|CRCErrors
decl_stmt|;
comment|/* 0x28 */
name|uint32_t
name|reserved35
decl_stmt|;
name|uint32_t
name|VLANOK
decl_stmt|;
comment|/* 0x30 */
name|uint32_t
name|reserved36
decl_stmt|;
name|uint32_t
name|ifOutErrors
decl_stmt|;
comment|/* 0x38 */
name|uint32_t
name|reserved37
decl_stmt|;
name|uint32_t
name|ifUcastPkts
decl_stmt|;
comment|/* 0x40 */
name|uint32_t
name|reserved38
decl_stmt|;
name|uint32_t
name|ifMulticastPkts
decl_stmt|;
comment|/* 0x48 */
name|uint32_t
name|reserved39
decl_stmt|;
name|uint32_t
name|ifBroadcastPkts
decl_stmt|;
comment|/* 0x50 */
name|uint32_t
name|reserved40
decl_stmt|;
name|uint32_t
name|etherStatsDropEvents
decl_stmt|;
comment|/* 0x58 */
name|uint32_t
name|reserved41
decl_stmt|;
name|uint32_t
name|etherStatsPkts
decl_stmt|;
comment|/* 0x60 */
name|uint32_t
name|reserved42
decl_stmt|;
name|uint32_t
name|etherStatsUndersizePkts
decl_stmt|;
comment|/* 0x68 */
name|uint32_t
name|reserved43
decl_stmt|;
name|uint32_t
name|etherStatsPkts64Octets
decl_stmt|;
comment|/* 0x70 */
name|uint32_t
name|reserved44
decl_stmt|;
name|uint32_t
name|etherStatsPkts65to127Octets
decl_stmt|;
comment|/* 0x78 */
name|uint32_t
name|reserved45
decl_stmt|;
name|uint32_t
name|etherStatsPkts128to255Octets
decl_stmt|;
comment|/* 0x80 */
name|uint32_t
name|reserved46
decl_stmt|;
name|uint32_t
name|etherStatsPkts256to511Octets
decl_stmt|;
comment|/* 0x88 */
name|uint32_t
name|reserved47
decl_stmt|;
name|uint32_t
name|etherStatsPkts512to1023Octets
decl_stmt|;
comment|/* 0x90 */
name|uint32_t
name|reserved48
decl_stmt|;
name|uint32_t
name|etherStatsPkts1024to1518Octets
decl_stmt|;
comment|/* 0x98 */
name|uint32_t
name|reserved49
decl_stmt|;
name|uint32_t
name|etherStatsPkts1519toTX_MTU
decl_stmt|;
comment|/* 0xa0 */
name|uint32_t
name|reserved50
decl_stmt|;
name|uint32_t
name|reserved51
index|[
literal|4
index|]
decl_stmt|;
name|uint32_t
name|aMACControlFrames
decl_stmt|;
comment|/* 0xc0 */
name|uint32_t
name|reserved52
index|[
literal|15
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_10g_stats_v3
block|{
name|uint32_t
name|reserved1
index|[
literal|32
index|]
decl_stmt|;
comment|/* 0x100 */
name|struct
name|al_eth_mac_10g_stats_v3_rx
name|rx
decl_stmt|;
comment|/* 0x200 */
name|struct
name|al_eth_mac_10g_stats_v3_tx
name|tx
decl_stmt|;
block|}
struct|;
union|union
name|al_eth_mac_10g_stats
block|{
name|struct
name|al_eth_mac_10g_stats_v2
name|v2
decl_stmt|;
name|struct
name|al_eth_mac_10g_stats_v3
name|v3
decl_stmt|;
block|}
union|;
struct|struct
name|al_eth_mac_10g
block|{
comment|/* [0x0] */
name|uint32_t
name|rev
decl_stmt|;
name|uint32_t
name|scratch
decl_stmt|;
name|uint32_t
name|cmd_cfg
decl_stmt|;
name|uint32_t
name|mac_0
decl_stmt|;
comment|/* [0x10] */
name|uint32_t
name|mac_1
decl_stmt|;
name|uint32_t
name|frm_len
decl_stmt|;
name|uint32_t
name|Reserved
decl_stmt|;
name|uint32_t
name|rx_fifo_sections
decl_stmt|;
comment|/* [0x20] */
name|uint32_t
name|tx_fifo_sections
decl_stmt|;
name|uint32_t
name|rx_fifo_almost_f_e
decl_stmt|;
name|uint32_t
name|tx_fifo_almost_f_e
decl_stmt|;
name|uint32_t
name|hashtable_load
decl_stmt|;
comment|/* [0x30] */
name|uint32_t
name|mdio_cfg_status
decl_stmt|;
name|uint16_t
name|mdio_cmd
decl_stmt|;
name|uint16_t
name|reserved1
decl_stmt|;
name|uint16_t
name|mdio_data
decl_stmt|;
name|uint16_t
name|reserved2
decl_stmt|;
name|uint16_t
name|mdio_regaddr
decl_stmt|;
name|uint16_t
name|reserved3
decl_stmt|;
comment|/* [0x40] */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|tx_ipg_len
decl_stmt|;
name|uint32_t
name|Reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x54] */
name|uint32_t
name|cl01_pause_quanta
decl_stmt|;
name|uint32_t
name|cl23_pause_quanta
decl_stmt|;
name|uint32_t
name|cl45_pause_quanta
decl_stmt|;
comment|/* [0x60] */
name|uint32_t
name|cl67_pause_quanta
decl_stmt|;
name|uint32_t
name|cl01_quanta_thresh
decl_stmt|;
name|uint32_t
name|cl23_quanta_thresh
decl_stmt|;
name|uint32_t
name|cl45_quanta_thresh
decl_stmt|;
comment|/* [0x70] */
name|uint32_t
name|cl67_quanta_thresh
decl_stmt|;
name|uint32_t
name|rx_pause_status
decl_stmt|;
name|uint32_t
name|Reserved2
decl_stmt|;
name|uint32_t
name|ts_timestamp
decl_stmt|;
comment|/* [0x80] */
name|union
name|al_eth_mac_10g_stats
name|stats
decl_stmt|;
comment|/* [0x300] */
name|uint32_t
name|control
decl_stmt|;
name|uint32_t
name|status_reg
decl_stmt|;
name|uint32_t
name|phy_id
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0x310] */
name|uint32_t
name|dev_ability
decl_stmt|;
name|uint32_t
name|partner_ability
decl_stmt|;
name|uint32_t
name|an_expansion
decl_stmt|;
name|uint32_t
name|device_np
decl_stmt|;
comment|/* [0x320] */
name|uint32_t
name|partner_np
decl_stmt|;
name|uint32_t
name|Reserved4
index|[
literal|9
index|]
decl_stmt|;
comment|/* [0x348] */
name|uint32_t
name|link_timer_lo
decl_stmt|;
name|uint32_t
name|link_timer_hi
decl_stmt|;
comment|/* [0x350] */
name|uint32_t
name|if_mode
decl_stmt|;
name|uint32_t
name|Reserved5
index|[
literal|43
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_gen
block|{
comment|/* [0x0]  Ethernet Controller Version */
name|uint32_t
name|version
decl_stmt|;
name|uint32_t
name|rsrvd_0
index|[
literal|2
index|]
decl_stmt|;
comment|/* [0xc] MAC selection configuration */
name|uint32_t
name|cfg
decl_stmt|;
comment|/* [0x10] 10/100/1000 MAC external configuration */
name|uint32_t
name|mac_1g_cfg
decl_stmt|;
comment|/* [0x14] 10/100/1000 MAC status */
name|uint32_t
name|mac_1g_stat
decl_stmt|;
comment|/* [0x18] RGMII external configuration */
name|uint32_t
name|rgmii_cfg
decl_stmt|;
comment|/* [0x1c] RGMII status */
name|uint32_t
name|rgmii_stat
decl_stmt|;
comment|/* [0x20] 1/2.5/10G MAC external configuration */
name|uint32_t
name|mac_10g_cfg
decl_stmt|;
comment|/* [0x24] 1/2.5/10G MAC status */
name|uint32_t
name|mac_10g_stat
decl_stmt|;
comment|/* [0x28] XAUI PCS configuration */
name|uint32_t
name|xaui_cfg
decl_stmt|;
comment|/* [0x2c] XAUI PCS status */
name|uint32_t
name|xaui_stat
decl_stmt|;
comment|/* [0x30] RXAUI PCS configuration */
name|uint32_t
name|rxaui_cfg
decl_stmt|;
comment|/* [0x34] RXAUI PCS status */
name|uint32_t
name|rxaui_stat
decl_stmt|;
comment|/* [0x38] Signal detect configuration */
name|uint32_t
name|sd_cfg
decl_stmt|;
comment|/* [0x3c] MDIO control register for MDIO interface 1 */
name|uint32_t
name|mdio_ctrl_1
decl_stmt|;
comment|/* [0x40] MDIO information register for MDIO interface 1 */
name|uint32_t
name|mdio_1
decl_stmt|;
comment|/* [0x44] MDIO control register for MDIO interface 2 */
name|uint32_t
name|mdio_ctrl_2
decl_stmt|;
comment|/* [0x48] MDIO information register for MDIO interface 2 */
name|uint32_t
name|mdio_2
decl_stmt|;
comment|/* [0x4c] XGMII 32 to 64 data FIFO control */
name|uint32_t
name|xgmii_dfifo_32_64
decl_stmt|;
comment|/* [0x50] Reserved 1 out */
name|uint32_t
name|mac_res_1_out
decl_stmt|;
comment|/* [0x54] XGMII 64 to 32 data FIFO control */
name|uint32_t
name|xgmii_dfifo_64_32
decl_stmt|;
comment|/* [0x58] Reserved 1 in */
name|uint32_t
name|mac_res_1_in
decl_stmt|;
comment|/* [0x5c] SerDes TX FIFO control */
name|uint32_t
name|sd_fifo_ctrl
decl_stmt|;
comment|/* [0x60] SerDes TX FIFO status */
name|uint32_t
name|sd_fifo_stat
decl_stmt|;
comment|/* [0x64] SerDes in/out selection */
name|uint32_t
name|mux_sel
decl_stmt|;
comment|/* [0x68] Clock configuration */
name|uint32_t
name|clk_cfg
decl_stmt|;
name|uint32_t
name|rsrvd_1
decl_stmt|;
comment|/* [0x70] LOS and SD selection */
name|uint32_t
name|los_sel
decl_stmt|;
comment|/* [0x74] RGMII selection configuration */
name|uint32_t
name|rgmii_sel
decl_stmt|;
comment|/* [0x78] Ethernet LED configuration */
name|uint32_t
name|led_cfg
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|33
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_kr
block|{
comment|/* [0x0] PCS register file address */
name|uint32_t
name|pcs_addr
decl_stmt|;
comment|/* [0x4] PCS register file data */
name|uint32_t
name|pcs_data
decl_stmt|;
comment|/* [0x8] AN register file address */
name|uint32_t
name|an_addr
decl_stmt|;
comment|/* [0xc] AN register file data */
name|uint32_t
name|an_data
decl_stmt|;
comment|/* [0x10] PMA register file address */
name|uint32_t
name|pma_addr
decl_stmt|;
comment|/* [0x14] PMA register file data */
name|uint32_t
name|pma_data
decl_stmt|;
comment|/* [0x18] MTIP register file address */
name|uint32_t
name|mtip_addr
decl_stmt|;
comment|/* [0x1c] MTIP register file data */
name|uint32_t
name|mtip_data
decl_stmt|;
comment|/* [0x20] KR PCS config  */
name|uint32_t
name|pcs_cfg
decl_stmt|;
comment|/* [0x24] KR PCS status  */
name|uint32_t
name|pcs_stat
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|54
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_sgmii
block|{
comment|/* [0x0] PCS register file address */
name|uint32_t
name|reg_addr
decl_stmt|;
comment|/* [0x4] PCS register file data */
name|uint32_t
name|reg_data
decl_stmt|;
comment|/* [0x8] PCS clock divider configuration */
name|uint32_t
name|clk_div
decl_stmt|;
comment|/* [0xc] PCS Status */
name|uint32_t
name|link_stat
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|60
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_stat
block|{
comment|/* [0x0] Receive rate matching error */
name|uint32_t
name|match_fault
decl_stmt|;
comment|/* [0x4] EEE, number of times the MAC went into low power mode */
name|uint32_t
name|eee_in
decl_stmt|;
comment|/* [0x8] EEE, number of times the MAC went out of low power mode */
name|uint32_t
name|eee_out
decl_stmt|;
comment|/* 	 * [0xc] 40G PCS, 	 * FEC corrected error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_cerr_0
decl_stmt|;
comment|/* 	 * [0x10] 40G PCS, 	 * FEC corrected error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_cerr_1
decl_stmt|;
comment|/* 	 * [0x14] 40G PCS, 	 * FEC corrected error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_cerr_2
decl_stmt|;
comment|/* 	 * [0x18] 40G PCS, 	 * FEC corrected error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_cerr_3
decl_stmt|;
comment|/* 	 * [0x1c] 40G PCS, 	 * FEC uncorrectable error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_ncerr_0
decl_stmt|;
comment|/* 	 * [0x20] 40G PCS, 	 * FEC uncorrectable error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_ncerr_1
decl_stmt|;
comment|/* 	 * [0x24] 40G PCS, 	 * FEC uncorrectable error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_ncerr_2
decl_stmt|;
comment|/* 	 * [0x28] 40G PCS, 	 * FEC uncorrectable error indication 	 */
name|uint32_t
name|v3_pcs_40g_ll_ncerr_3
decl_stmt|;
comment|/* 	 * [0x2c] 10G_LL PCS, 	 * FEC corrected error indication 	 */
name|uint32_t
name|v3_pcs_10g_ll_cerr
decl_stmt|;
comment|/* 	 * [0x30] 10G_LL PCS, 	 * FEC uncorrectable error indication 	 */
name|uint32_t
name|v3_pcs_10g_ll_ncerr
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|51
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_stat_lane
block|{
comment|/* [0x0] Character error */
name|uint32_t
name|char_err
decl_stmt|;
comment|/* [0x4] Disparity error */
name|uint32_t
name|disp_err
decl_stmt|;
comment|/* [0x8] Comma detection */
name|uint32_t
name|pat
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|13
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_gen_v3
block|{
comment|/* [0x0] ASYNC FIFOs control */
name|uint32_t
name|afifo_ctrl
decl_stmt|;
comment|/* [0x4] TX ASYNC FIFO configuration */
name|uint32_t
name|tx_afifo_cfg_1
decl_stmt|;
comment|/* [0x8] TX ASYNC FIFO configuration */
name|uint32_t
name|tx_afifo_cfg_2
decl_stmt|;
comment|/* [0xc] TX ASYNC FIFO configuration */
name|uint32_t
name|tx_afifo_cfg_3
decl_stmt|;
comment|/* [0x10] TX ASYNC FIFO configuration */
name|uint32_t
name|tx_afifo_cfg_4
decl_stmt|;
comment|/* [0x14] TX ASYNC FIFO configuration */
name|uint32_t
name|tx_afifo_cfg_5
decl_stmt|;
comment|/* [0x18] RX ASYNC FIFO configuration */
name|uint32_t
name|rx_afifo_cfg_1
decl_stmt|;
comment|/* [0x1c] RX ASYNC FIFO configuration */
name|uint32_t
name|rx_afifo_cfg_2
decl_stmt|;
comment|/* [0x20] RX ASYNC FIFO configuration */
name|uint32_t
name|rx_afifo_cfg_3
decl_stmt|;
comment|/* [0x24] RX ASYNC FIFO configuration */
name|uint32_t
name|rx_afifo_cfg_4
decl_stmt|;
comment|/* [0x28] RX ASYNC FIFO configuration */
name|uint32_t
name|rx_afifo_cfg_5
decl_stmt|;
comment|/* [0x2c] MAC selection configuration */
name|uint32_t
name|mac_sel
decl_stmt|;
comment|/* [0x30] 10G LL MAC configuration */
name|uint32_t
name|mac_10g_ll_cfg
decl_stmt|;
comment|/* [0x34] 10G LL MAC control */
name|uint32_t
name|mac_10g_ll_ctrl
decl_stmt|;
comment|/* [0x38] 10G LL PCS configuration */
name|uint32_t
name|pcs_10g_ll_cfg
decl_stmt|;
comment|/* [0x3c] 10G LL PCS status */
name|uint32_t
name|pcs_10g_ll_status
decl_stmt|;
comment|/* [0x40] 40G LL PCS configuration */
name|uint32_t
name|pcs_40g_ll_cfg
decl_stmt|;
comment|/* [0x44] 40G LL PCS status */
name|uint32_t
name|pcs_40g_ll_status
decl_stmt|;
comment|/* [0x48] PCS 40G  register file address */
name|uint32_t
name|pcs_40g_ll_addr
decl_stmt|;
comment|/* [0x4c] PCS 40G register file data */
name|uint32_t
name|pcs_40g_ll_data
decl_stmt|;
comment|/* [0x50] 40G LL MAC configuration */
name|uint32_t
name|mac_40g_ll_cfg
decl_stmt|;
comment|/* [0x54] 40G LL MAC status */
name|uint32_t
name|mac_40g_ll_status
decl_stmt|;
comment|/* [0x58] Preamble configuration (high [55:32]) */
name|uint32_t
name|preamble_cfg_high
decl_stmt|;
comment|/* [0x5c] Preamble configuration (low [31:0]) */
name|uint32_t
name|preamble_cfg_low
decl_stmt|;
comment|/* [0x60] MAC 40G register file address */
name|uint32_t
name|mac_40g_ll_addr
decl_stmt|;
comment|/* [0x64] MAC 40G register file data */
name|uint32_t
name|mac_40g_ll_data
decl_stmt|;
comment|/* [0x68] 40G LL MAC control */
name|uint32_t
name|mac_40g_ll_ctrl
decl_stmt|;
comment|/* [0x6c] PCS 40G  register file address */
name|uint32_t
name|pcs_40g_fec_91_ll_addr
decl_stmt|;
comment|/* [0x70] PCS 40G register file data */
name|uint32_t
name|pcs_40g_fec_91_ll_data
decl_stmt|;
comment|/* [0x74] 40G LL PCS EEE configuration */
name|uint32_t
name|pcs_40g_ll_eee_cfg
decl_stmt|;
comment|/* [0x78] 40G LL PCS EEE status */
name|uint32_t
name|pcs_40g_ll_eee_status
decl_stmt|;
comment|/* 	 * [0x7c] SERDES 32-bit interface shift configuration (when swap is 	 * enabled) 	 */
name|uint32_t
name|serdes_32_tx_shift
decl_stmt|;
comment|/* 	 * [0x80] SERDES 32-bit interface shift configuration (when swap is 	 * enabled) 	 */
name|uint32_t
name|serdes_32_rx_shift
decl_stmt|;
comment|/* 	 * [0x84] SERDES 32-bit interface bit selection 	 */
name|uint32_t
name|serdes_32_tx_sel
decl_stmt|;
comment|/* 	 * [0x88] SERDES 32-bit interface bit selection 	 */
name|uint32_t
name|serdes_32_rx_sel
decl_stmt|;
comment|/* [0x8c] AN/LT wrapper  control */
name|uint32_t
name|an_lt_ctrl
decl_stmt|;
comment|/* [0x90] AN/LT wrapper  register file address */
name|uint32_t
name|an_lt_0_addr
decl_stmt|;
comment|/* [0x94] AN/LT wrapper register file data */
name|uint32_t
name|an_lt_0_data
decl_stmt|;
comment|/* [0x98] AN/LT wrapper  register file address */
name|uint32_t
name|an_lt_1_addr
decl_stmt|;
comment|/* [0x9c] AN/LT wrapper register file data */
name|uint32_t
name|an_lt_1_data
decl_stmt|;
comment|/* [0xa0] AN/LT wrapper  register file address */
name|uint32_t
name|an_lt_2_addr
decl_stmt|;
comment|/* [0xa4] AN/LT wrapper register file data */
name|uint32_t
name|an_lt_2_data
decl_stmt|;
comment|/* [0xa8] AN/LT wrapper  register file address */
name|uint32_t
name|an_lt_3_addr
decl_stmt|;
comment|/* [0xac] AN/LT wrapper register file data */
name|uint32_t
name|an_lt_3_data
decl_stmt|;
comment|/* [0xb0] External SERDES control */
name|uint32_t
name|ext_serdes_ctrl
decl_stmt|;
comment|/* [0xb4] spare bits */
name|uint32_t
name|spare
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|18
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_eth_mac_regs
block|{
name|struct
name|al_eth_mac_1g
name|mac_1g
decl_stmt|;
comment|/* [0x000] */
name|struct
name|al_eth_mac_10g
name|mac_10g
decl_stmt|;
comment|/* [0x400] */
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
comment|/* [0x800] */
name|struct
name|al_eth_mac_gen
name|gen
decl_stmt|;
comment|/* [0x900] */
name|struct
name|al_eth_mac_kr
name|kr
decl_stmt|;
comment|/* [0xa00] */
name|struct
name|al_eth_mac_sgmii
name|sgmii
decl_stmt|;
comment|/* [0xb00] */
name|struct
name|al_eth_mac_stat
name|stat
decl_stmt|;
comment|/* [0xc00] */
name|struct
name|al_eth_mac_stat_lane
name|stat_lane
index|[
literal|4
index|]
decl_stmt|;
comment|/* [0xd00] */
name|struct
name|al_eth_mac_gen_v3
name|gen_v3
decl_stmt|;
comment|/* [0xe00] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** 1G MAC registers ****/
comment|/* cmd_cfg */
define|#
directive|define
name|ETH_1G_MAC_CMD_CFG_TX_ENA
value|(1<< 0)
define|#
directive|define
name|ETH_1G_MAC_CMD_CFG_RX_ENA
value|(1<< 1)
comment|/* enable Half Duplex */
define|#
directive|define
name|ETH_1G_MAC_CMD_CFG_HD_EN
value|(1<< 10)
comment|/* enable 1G speed */
define|#
directive|define
name|ETH_1G_MAC_CMD_CFG_1G_SPD
value|(1<< 3)
comment|/* enable 10M speed */
define|#
directive|define
name|ETH_1G_MAC_CMD_CFG_10M_SPD
value|(1<< 25)
comment|/**** 10G MAC registers ****/
comment|/* cmd_cfg */
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_TX_ENA
value|(1<< 0)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_RX_ENA
value|(1<< 1)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_WAN_MODE
value|(1<< 3)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PROMIS_EN
value|(1<< 4)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PAD_EN
value|(1<< 5)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_CRC_FWD
value|(1<< 6)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PAUSE_FWD
value|(1<< 7)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PAUSE_IGNORE
value|(1<< 8)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_TX_ADDR_INS
value|(1<< 9)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_LOOP_ENA
value|(1<< 10)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_TX_PAD_EN
value|(1<< 11)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_SW_RESET
value|(1<< 12)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_CNTL_FRM_ENA
value|(1<< 13)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_RX_ERR_DISC
value|(1<< 14)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PHY_TXENA
value|(1<< 15)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_FORCE_SEND_IDLE
value|(1<< 16)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_NO_LGTH_CHECK
value|(1<< 17)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_COL_CNT_EXT
value|(1<< 18)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PFC_MODE
value|(1<< 19)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_PAUSE_PFC_COMP
value|(1<< 20)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_SFD_ANY
value|(1<< 21)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_TX_FLUSH
value|(1<< 22)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_TX_LOWP_ENA
value|(1<< 23)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_REG_LOWP_RXEMPTY
value|(1<< 24)
define|#
directive|define
name|ETH_10G_MAC_CMD_CFG_SHORT_DISCARD
value|(1<< 25)
comment|/* mdio_cfg_status */
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_MASK
value|0x0000001c
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_SHIFT
value|2
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_1_CLK
value|0
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_3_CLK
value|1
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_5_CLK
value|2
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_7_CLK
value|3
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_9_CLK
value|4
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_11_CLK
value|5
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_13_CLK
value|6
define|#
directive|define
name|ETH_10G_MAC_MDIO_CFG_HOLD_TIME_15_CLK
value|7
comment|/* control */
define|#
directive|define
name|ETH_10G_MAC_CONTROL_AN_EN_MASK
value|0x00001000
define|#
directive|define
name|ETH_10G_MAC_CONTROL_AN_EN_SHIFT
value|12
comment|/* if_mode */
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_EN_MASK
value|0x00000001
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_EN_SHIFT
value|0
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_AN_MASK
value|0x00000002
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_AN_SHIFT
value|1
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_SPEED_MASK
value|0x0000000c
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_SPEED_SHIFT
value|2
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_DUPLEX_MASK
value|0x00000010
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_DUPLEX_SHIFT
value|4
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_SPEED_10M
value|0
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_SPEED_100M
value|1
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_SPEED_1G
value|2
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_DUPLEX_FULL
value|0
define|#
directive|define
name|ETH_10G_MAC_IF_MODE_SGMII_DUPLEX_HALF
value|1
comment|/**** version register ****/
comment|/*  Revision number (Minor) */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/*  Revision number (Major) */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/*  Date of release */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATE_DAY_SHIFT
value|16
comment|/*  Month of release */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATA_MONTH_SHIFT
value|21
comment|/*  Year of release (starting from 2000) */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|ETH_MAC_GEN_VERSION_DATE_YEAR_SHIFT
value|25
comment|/*  Reserved */
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|ETH_MAC_GEN_VERSION_RESERVED_SHIFT
value|30
comment|/**** cfg register ****/
comment|/*  * Selects between the 10/100/1000 MAC and the 1/2.5/10G MAC:  * 0 - 10/100/1000  * 1 - 1/2.5/10G  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_MAC_1_10
value|(1<< 0)
comment|/*  * Selects the operation mode of the 1/2.5/10G MAC:  * 00 - 1/2.5G SGMII  * 01 - 10G XAUI/RXAUI  * 10 â 10G KR  * 11 â Reserved  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_XGMII_SGMII_MASK
value|0x00000006
define|#
directive|define
name|ETH_MAC_GEN_CFG_XGMII_SGMII_SHIFT
value|1
comment|/*  * Selects the operation mode of the PCS:  * 0 - XAUI  * 1 - RXAUI  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_XAUI_RXAUI
value|(1<< 3)
comment|/* Swap bits of TBI (SGMII mode) interface */
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_TBI_RX
value|(1<< 4)
comment|/*  * Determines the offset of the TBI bus on the SerDes interface:  * 0 - LSB  * 1 - MSB  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_TBI_MSB_RX
value|(1<< 5)
comment|/*  * Selects the SGMII PCS/MAC:  * 0 â 10G MAC with SGMII  * 1 â 1G MAC with SGMII  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_SGMII_SEL
value|(1<< 6)
comment|/*  * Selects between RGMII and SGMII for the 1G MAC:  * 0 â RGMII  * 1 â SGMII  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_RGMII_SGMII_SEL
value|(1<< 7)
comment|/* Swap bits of TBI (SGMII mode) interface */
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_TBI_TX
value|(1<< 8)
comment|/*  * Determines the offset of the TBI bus on the SerDes interface:  *  0 - LSB  * 1 - MSB  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_TBI_MSB_TX
value|(1<< 9)
comment|/*  * Selection between the MDIO from 10/100/1000 MAC or the 1/2.5/10G MAC  * 0 - 10/100/1000  * 1 - 1/2.5/10G  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_MDIO_1_10
value|(1<< 10)
comment|/*  * Swap MDC output  * 0 â Normal  * 1 â Flipped  */
define|#
directive|define
name|ETH_MAC_GEN_CFG_MDIO_POL
value|(1<< 11)
comment|/* Swap bits on SerDes interface */
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_SERDES_RX_MASK
value|0x000F0000
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_SERDES_RX_SHIFT
value|16
comment|/* Swap bits on SerDes interface */
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_SERDES_TX_MASK
value|0x0F000000
define|#
directive|define
name|ETH_MAC_GEN_CFG_SWAP_SERDES_TX_SHIFT
value|24
comment|/**** mac_1g_cfg register ****/
comment|/*  * Selection of the input for the "set_1000" input of the Ethernet 10/100/1000  * MAC:  * 0 - From RGMII converter (automatic speed selection)  * 1 - From register set_1000_def  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SET_1000_SEL
value|(1<< 0)
comment|/* Default value for the 10/100/1000 MAC "set_1000" input */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SET_1000_DEF
value|(1<< 1)
comment|/*  * Selection of the input for the "set_10" input of the Ethernet 10/100/1000  * MAC:  * 0 - From RGMII converter (automatic speed selection)  * 1 - From register set_10_def  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SET_10_SEL
value|(1<< 4)
comment|/* Default value for the 10/100/1000 MAC "set_10" input */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SET_10_DEF
value|(1<< 5)
comment|/* Transmit low power enable */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_LOWP_ENA
value|(1<< 8)
comment|/*  * Enable magic packet mode:  * 0 - Sleep mode  * 1 - Normal operation  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SLEEPN
value|(1<< 9)
comment|/* Swap ff_tx_crc input */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_CFG_SWAP_FF_TX_CRC
value|(1<< 12)
comment|/**** mac_1g_stat register ****/
comment|/* Status of the en_10 output form the 10/100/1000 MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_STAT_EN_10
value|(1<< 0)
comment|/* Status of the eth_mode output from th 10/100/1000 MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_STAT_ETH_MODE
value|(1<< 1)
comment|/* Status of the lowp output from the 10/100/1000 MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_STAT_LOWP
value|(1<< 4)
comment|/* Status of the wakeup output from the 10/100/1000 MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_1G_STAT_WAKEUP
value|(1<< 5)
comment|/**** rgmii_cfg register ****/
comment|/*  * Selection of the input for the "set_1000" input of the RGMII converter  * 0 - From MAC  * 1 - From register set_1000_def (automatic speed selection)  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_SET_1000_SEL
value|(1<< 0)
comment|/* Default value for the RGMII converter "set_1000" input */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_SET_1000_DEF
value|(1<< 1)
comment|/*  * Selection of the input for the "set_10" input of the RGMII converter:  * 0 - From MAC  * 1 - From register set_10_def (automatic speed selection)  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_SET_10_SEL
value|(1<< 4)
comment|/* Default value for the 10/100/1000 MAC "set_10" input  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_SET_10_DEF
value|(1<< 5)
comment|/* Enable automatic speed selection (based on PHY in-band status information) */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_ENA_AUTO
value|(1<< 8)
comment|/* Force full duplex, only valid when ena_auto is '1'. */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_CFG_SET_FD
value|(1<< 9)
comment|/**** rgmii_stat register ****/
comment|/*  * Status of the speed output form the RGMII converter  * 00 - 10 Mbps  * 01 - 100 Mbps  * 10 - 1000 Mbps  * 11 - Reserved  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_STAT_SPEED_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_RGMII_STAT_SPEED_SHIFT
value|0
comment|/*  * Link indication from the RGMII converter (valid only if the external PHY  * supports in-band status signaling)  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_STAT_LINK
value|(1<< 4)
comment|/*  * Full duplex indication from the RGMII converter (valid only if the external  * PHY supports in-band status signaling)  */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_STAT_DUP
value|(1<< 5)
comment|/**** mac_10g_cfg register ****/
comment|/* Instruct the XGMII to transmit local fault. */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_TX_LOC_FAULT
value|(1<< 0)
comment|/* Instruct the XGMII to transmit remote fault. */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_TX_REM_FAULT
value|(1<< 1)
comment|/* Instruct the XGMII to transmit link fault. */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_TX_LI_FAULT
value|(1<< 2)
comment|/*  * Synchronous reset for the PCS layer. Can be used after SerDes lock assertion  * to reset the PCS state machine.  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_SG_SRESET
value|(1<< 3)
comment|/*  * PHY LOS indication selection  * 00 - Select register value from phy_los_def  * 01 - Select input from the SerDes  * 10 - Select input from GPIO  * 11 - Select inverted input from GPIO  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_PHY_LOS_SEL_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_PHY_LOS_SEL_SHIFT
value|4
comment|/*  * Default value for PHY LOS indication. Reflects the LOS indication from the  * SerDes. ('0' if not used)  */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_PHY_LOS_DEF
value|(1<< 6)
comment|/* Reverse polarity of the LOS signal from the SerDes */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_PHY_LOS_POL
value|(1<< 7)
comment|/* Transmit low power enable */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_LOWP_ENA
value|(1<< 8)
comment|/* Swap ff_tx_crc input */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_CFG_SWAP_FF_TX_CRC
value|(1<< 12)
comment|/**** mac_10g_stat register ****/
comment|/* XGMII RS detects local fault */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_LOC_FAULT
value|(1<< 0)
comment|/* XGMII RS detects remote fault */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_REM_FAULT
value|(1<< 1)
comment|/* XGMII RS detects link fault */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_LI_FAULT
value|(1<< 2)
comment|/* PFC mode */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_PFC_MODE
value|(1<< 3)
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_SG_ENA
value|(1<< 4)
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_SG_ANDONE
value|(1<< 5)
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_SG_SYNC
value|(1<< 6)
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_SG_SPEED_MASK
value|0x00000180
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_SG_SPEED_SHIFT
value|7
comment|/* Status of the lowp output form the 1/2.5/10G MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_LOWP
value|(1<< 9)
comment|/* Status of the ts_avail output from th 1/2.5/10G MAC */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_TS_AVAIL
value|(1<< 10)
comment|/* Transmit pause indication */
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_PAUSE_ON_MASK
value|0xFF000000
define|#
directive|define
name|ETH_MAC_GEN_MAC_10G_STAT_PAUSE_ON_SHIFT
value|24
comment|/**** xaui_cfg register ****/
comment|/* Increase rate matching FIFO threshold */
define|#
directive|define
name|ETH_MAC_GEN_XAUI_CFG_JUMBO_EN
value|(1<< 0)
comment|/**** xaui_stat register ****/
comment|/* Lane alignment status */
define|#
directive|define
name|ETH_MAC_GEN_XAUI_STAT_ALIGN_DONE
value|(1<< 0)
comment|/* Lane synchronization */
define|#
directive|define
name|ETH_MAC_GEN_XAUI_STAT_SYNC_MASK
value|0x000000F0
define|#
directive|define
name|ETH_MAC_GEN_XAUI_STAT_SYNC_SHIFT
value|4
comment|/* Code group alignment indication */
define|#
directive|define
name|ETH_MAC_GEN_XAUI_STAT_CG_ALIGN_MASK
value|0x00000F00
define|#
directive|define
name|ETH_MAC_GEN_XAUI_STAT_CG_ALIGN_SHIFT
value|8
comment|/**** rxaui_cfg register ****/
comment|/* Increase rate matching FIFO threshold */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_CFG_JUMBO_EN
value|(1<< 0)
comment|/* Scrambler enable */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_CFG_SRBL_EN
value|(1<< 1)
comment|/* Disparity calculation across lanes enabled */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_CFG_DISP_ACROSS_LANE
value|(1<< 2)
comment|/**** rxaui_stat register ****/
comment|/* Lane alignment status */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_STAT_ALIGN_DONE
value|(1<< 0)
comment|/* Lane synchronization */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_STAT_SYNC_MASK
value|0x000000F0
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_STAT_SYNC_SHIFT
value|4
comment|/* Code group alignment indication */
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_STAT_CG_ALIGN_MASK
value|0x00000F00
define|#
directive|define
name|ETH_MAC_GEN_RXAUI_STAT_CG_ALIGN_SHIFT
value|8
comment|/**** sd_cfg register ****/
comment|/*  * Signal detect selection  * 0 - from register  * 1 - from SerDes  */
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_SEL_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_SEL_SHIFT
value|0
comment|/* Signal detect value */
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_VAL_MASK
value|0x000000F0
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_VAL_SHIFT
value|4
comment|/* Signal detect revers polarity (reverse polarity of signal from the SerDes */
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_POL_MASK
value|0x00000F00
define|#
directive|define
name|ETH_MAC_GEN_SD_CFG_POL_SHIFT
value|8
comment|/**** mdio_ctrl_1 register ****/
comment|/*  * Available indication  * 0 - The port was available and it is captured by this Ethernet controller.  * 1 - The port is used by another Ethernet controller.  */
define|#
directive|define
name|ETH_MAC_GEN_MDIO_CTRL_1_AVAIL
value|(1<< 0)
comment|/**** mdio_1 register ****/
comment|/* Current Ethernet interface number that controls the MDIO port */
define|#
directive|define
name|ETH_MAC_GEN_MDIO_1_INFO_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_MDIO_1_INFO_SHIFT
value|0
comment|/**** mdio_ctrl_2 register ****/
comment|/*  * Available indication  * 0 - The port was available and it is captured by this Ethernet controller.  * 1 - The port is used by another Ethernet controller.  */
define|#
directive|define
name|ETH_MAC_GEN_MDIO_CTRL_2_AVAIL
value|(1<< 0)
comment|/**** mdio_2 register ****/
comment|/* Current Ethernet interface number that controls the MDIO port */
define|#
directive|define
name|ETH_MAC_GEN_MDIO_2_INFO_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_MDIO_2_INFO_SHIFT
value|0
comment|/**** xgmii_dfifo_32_64 register ****/
comment|/* FIFO enable */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_ENABLE
value|(1<< 0)
comment|/* Read Write command every 2 cycles */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_RW_2_CYCLES
value|(1<< 1)
comment|/* Swap LSB MSB when creating wider bus */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_SWAP_LSB_MSB
value|(1<< 2)
comment|/* Software reset */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_SW_RESET
value|(1<< 4)
comment|/* Read threshold */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_READ_TH_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_READ_TH_SHIFT
value|8
comment|/* FIFO used */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_USED_MASK
value|0x00FF0000
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_32_64_USED_SHIFT
value|16
comment|/**** xgmii_dfifo_64_32 register ****/
comment|/* FIFO enable */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_ENABLE
value|(1<< 0)
comment|/* Read Write command every 2 cycles */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_RW_2_CYCLES
value|(1<< 1)
comment|/* Swap LSB MSB when creating wider bus */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_SWAP_LSB_MSB
value|(1<< 2)
comment|/* Software reset */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_SW_RESET
value|(1<< 4)
comment|/* Read threshold */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_READ_TH_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_READ_TH_SHIFT
value|8
comment|/* FIFO used */
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_USED_MASK
value|0x00FF0000
define|#
directive|define
name|ETH_MAC_GEN_XGMII_DFIFO_64_32_USED_SHIFT
value|16
comment|/**** sd_fifo_ctrl register ****/
comment|/* FIFO enable */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_ENABLE_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_ENABLE_SHIFT
value|0
comment|/* Software reset */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_SW_RESET_MASK
value|0x000000F0
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_SW_RESET_SHIFT
value|4
comment|/* Read threshold */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_READ_TH_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_CTRL_READ_TH_SHIFT
value|8
comment|/**** sd_fifo_stat register ****/
comment|/* FIFO 0 used */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_0_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_0_SHIFT
value|0
comment|/* FIFO 1 used */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_1_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_1_SHIFT
value|8
comment|/* FIFO 2 used */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_2_MASK
value|0x00FF0000
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_2_SHIFT
value|16
comment|/* FIFO 3 used */
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_3_MASK
value|0xFF000000
define|#
directive|define
name|ETH_MAC_GEN_SD_FIFO_STAT_USED_3_SHIFT
value|24
comment|/**** mux_sel register ****/
comment|/*  * SGMII input selection selector  * 00 â SerDes 0  * 01 â SerDes 1  * 10 â SerDes 2  * 11 â SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SGMII_IN_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SGMII_IN_SHIFT
value|0
comment|/*  * RXAUI Lane 0 Input  * 00 â SerDes 0  * 01 â SerDes 1  * 10 â SerDes 2  * 11 â SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_RXAUI_0_IN_MASK
value|0x0000000C
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_RXAUI_0_IN_SHIFT
value|2
comment|/*  * RXAUI Lane 1 Input  * 00 â SERDES 0  * 01 â SERDES 1  * 10 â SERDES 2  * 11 â SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_RXAUI_1_IN_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_RXAUI_1_IN_SHIFT
value|4
comment|/*  * XAUI Lane 0 Input  * 00 â SERDES 0  * 01 â SERDES 1  * 10 â SERDES 2  * 11 â SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_0_IN_MASK
value|0x000000C0
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_0_IN_SHIFT
value|6
comment|/*  * XAUI Lane 1 Input  * 00 â SERDES 0  * 01 â SERDES 1  * 10 â SERDES 2  * 11 â SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_1_IN_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_1_IN_SHIFT
value|8
comment|/*  * XAUI Lane 2 Input  * 00 â SERDES 0  * 01 â SERDES 1  * 10 â SERDES 2  * 11 â SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_2_IN_MASK
value|0x00000C00
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_2_IN_SHIFT
value|10
comment|/*  * XAUI Lane 3 Input  * 00 â SERDES 0  * 01 â SERDES 1  * 10 â SERDES 2  * 11 â SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_3_IN_MASK
value|0x00003000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_XAUI_3_IN_SHIFT
value|12
comment|/*  * KR PCS Input  * 00 - SERDES 0  * 01 - SERDES 1  * 10 - SERDES 2  * 11 - SERDES 3  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_KR_IN_MASK
value|0x0000C000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_KR_IN_SHIFT
value|14
comment|/*  * SerDes 0 input selection (TX)  * 000 â XAUI lane 0  * 001 â XAUI lane 1  * 010 â XAUI lane 2  * 011 â XAUI lane 3  * 100 â RXAUI lane 0  * 101 â RXAUI lane 1  * 110 â SGMII  * 111 â KR  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_0_TX_MASK
value|0x00070000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_0_TX_SHIFT
value|16
comment|/*  * SERDES 1 input selection (Tx)  * 000 â XAUI lane 0  * 001 â XAUI lane 1  * 010 â XAUI lane 2  * 011 â XAUI lane 3  * 100 â RXAUI lane 0  * 101 â RXAUI lane 1  * 110 â SGMII  * 111 â KR  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_1_TX_MASK
value|0x00380000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_1_TX_SHIFT
value|19
comment|/*  * SerDes 2 input selection (Tx)  * 000 â XAUI lane 0  * 001 â XAUI lane 1  * 010 â XAUI lane 2  * 011 â XAUI lane 3  * 100 â RXAUI lane 0  * 101 â RXAUI lane 1  * 110 â SGMII  * 111 â KR  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_2_TX_MASK
value|0x01C00000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_2_TX_SHIFT
value|22
comment|/*  * SerDes 3 input selection (Tx)  * 000 â XAUI lane 0  * 001 â XAUI lane 1  * 010 â XAUI lane 2  * 011 â XAUI lane 3  * 100 â RXAUI lane 0  * 101 â RXAUI lane 1  * 110 â SGMII  * 111 â KR  */
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_3_TX_MASK
value|0x0E000000
define|#
directive|define
name|ETH_MAC_GEN_MUX_SEL_SERDES_3_TX_SHIFT
value|25
comment|/**** clk_cfg register ****/
comment|/*  * Rx/Tx lane 0 clock MUX select  * must be aligned with data selector MUXs)  * 0 â SerDes 0 clock  * 0 â SerDes 1 clock  * 2 â SerDes 2 clock  * 3 â SerDes 3 clock  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_0_CLK_SEL_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_0_CLK_SEL_SHIFT
value|0
comment|/*  * Rx/Tx lane 0 clock MUX select must be aligned with data selector MUXs)  * 0 - SerDes 0 clock  * 1 - SerDes 1 clock  * 2 - SerDes 2 clock  * 3 - SerDes 3 clock  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_1_CLK_SEL_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_1_CLK_SEL_SHIFT
value|4
comment|/*  * RX/TX lane 0 clock MUX select (should be aligned with data selector MUXs)  * 0 - SERDES 0 clock  * 1 - SERDES 1 clock  * 2 - SERDES 2 clock  * 3 - SERDES 3 clock  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_2_CLK_SEL_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_2_CLK_SEL_SHIFT
value|8
comment|/*  * Rx/Tx lane 0 clock MUX select must be aligned with data selector MUXs)  * 0 - SerDes 0 clock  * 1 - SerDes 1 clock  * 2 - SerDes 2 clock  * 3 - SerDes 3 clock  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_3_CLK_SEL_MASK
value|0x00003000
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_LANE_3_CLK_SEL_SHIFT
value|12
comment|/*  * MAC GMII Rx clock MUX select must be aligned with data selector MUXs)  * 0 â RGMII  * 1 â SGMII  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_GMII_RX_CLK_SEL
value|(1<< 16)
comment|/*  * MAC GMII Tx clock MUX select (should be aligned with data selector MUXs)  * 0 - RGMII  * 1 - SGMII  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_GMII_TX_CLK_SEL
value|(1<< 18)
comment|/*  * Tx clock MUX select,  * Selects the internal clock for the Tx data path  * 0 â SerDes[0] TX DWORD CLK REF (for RXAUI and SGMII)  * 1 â SerDes[0] TX WORD CLK REF (for XAUI and KR)  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_TX_CLK_SEL
value|(1<< 28)
comment|/*  * Rxclock MUX select  * Selects the internal clock for the Rx data path  * 0 â XGMII TX CLK 32 LOCAL (for XAUI and RXAUI and KR)  * 1 â SerDes[0] RX DWORD CLK GENERATED (125M)  * (for SGMII)  */
define|#
directive|define
name|ETH_MAC_GEN_CLK_CFG_RX_CLK_SEL
value|(1<< 30)
comment|/**** los_sel register ****/
comment|/*  * Selected LOS/SD select  * 00 â SerDes 0  * 01 â SerDes 1  * 10 â SerDes 2  * 11 â SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_0_SEL_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_0_SEL_SHIFT
value|0
comment|/*  * Selected LOS/SD select  * 00 - SerDes 0  * 01 - SerDes 1  * 10 - SerDes 2  * 11 - SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_1_SEL_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_1_SEL_SHIFT
value|4
comment|/*  * Selected LOS/SD select  * 00 - SerDes 0  * 01 - SerDes 1  * 10 - SerDes 2  * 11 - SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_2_SEL_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_2_SEL_SHIFT
value|8
comment|/*  * Selected LOS/SD select  * 00 - SerDes 0  * 01 - SerDes 1  * 10 - SerDes 2  * 11 - SerDes 3  */
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_3_SEL_MASK
value|0x00003000
define|#
directive|define
name|ETH_MAC_GEN_LOS_SEL_LANE_3_SEL_SHIFT
value|12
comment|/**** rgmii_sel register ****/
comment|/* Swap [3:0] input with [7:4] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_RX_SWAP_3_0
value|(1<< 0)
comment|/* Swap [4] input with [9] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_RX_SWAP_4
value|(1<< 1)
comment|/* Swap [7:4] input with [3:0] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_RX_SWAP_7_3
value|(1<< 2)
comment|/* Swap [9] input with [4] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_RX_SWAP_9
value|(1<< 3)
comment|/* Swap [3:0] input with [7:4] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_TX_SWAP_3_0
value|(1<< 4)
comment|/* Swap [4] input with [9] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_TX_SWAP_4
value|(1<< 5)
comment|/* Swap [7:4] input with [3:0] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_TX_SWAP_7_3
value|(1<< 6)
comment|/* Swap [9] input with [4] */
define|#
directive|define
name|ETH_MAC_GEN_RGMII_SEL_TX_SWAP_9
value|(1<< 7)
comment|/**** led_cfg register ****/
comment|/*  * LED source selection:  * 0 â Default reg  * 1 â Rx activity  * 2 â Tx activity  * 3 â Rx | Tx activity  * 4-9 â SGMII LEDs  */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_SHIFT
value|0
comment|/* turn the led on/off based on default value field (ETH_MAC_GEN_LED_CFG_DEF) */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_DEFAULT_REG
value|0
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_RX_ACTIVITY_DEPRECIATED
value|1
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_TX_ACTIVITY_DEPRECIATED
value|2
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_RX_TX_ACTIVITY_DEPRECIATED
value|3
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_SEL_LINK_ACTIVITY
value|10
comment|/* LED default value */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_DEF
value|(1<< 4)
comment|/* LED signal polarity */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_POL
value|(1<< 5)
comment|/*  * activity timer (MSB)  * 32 bit timer @SB clock  */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_ACT_TIMER_MASK
value|0x00FF0000
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_ACT_TIMER_SHIFT
value|16
comment|/*  * activity timer (MSB)  * 32 bit timer @SB clock  */
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_BLINK_TIMER_MASK
value|0xFF000000
define|#
directive|define
name|ETH_MAC_GEN_LED_CFG_BLINK_TIMER_SHIFT
value|24
comment|/**** pcs_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_KR_PCS_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_PCS_ADDR_VAL_SHIFT
value|0
comment|/**** pcs_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_KR_PCS_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_PCS_DATA_VAL_SHIFT
value|0
comment|/**** an_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_KR_AN_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_AN_ADDR_VAL_SHIFT
value|0
comment|/**** an_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_KR_AN_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_AN_DATA_VAL_SHIFT
value|0
comment|/**** pma_addr register ****/
comment|/* Dddress value */
define|#
directive|define
name|ETH_MAC_KR_PMA_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_PMA_ADDR_VAL_SHIFT
value|0
comment|/**** pma_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_KR_PMA_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_PMA_DATA_VAL_SHIFT
value|0
comment|/**** mtip_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_KR_MTIP_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_MTIP_ADDR_VAL_SHIFT
value|0
comment|/**** mtip_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_KR_MTIP_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_KR_MTIP_DATA_VAL_SHIFT
value|0
comment|/**** pcs_cfg register ****/
comment|/* Enable Auto-Negotiation after Reset */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_STRAP_AN_ENA
value|(1<< 0)
comment|/*  * Signal detect selector for the EEE  * 0 â Register default value  * 1 â SerDes value  */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_EEE_SD_SEL
value|(1<< 4)
comment|/* Signal detect default value for the EEE */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_EEE_DEF_VAL
value|(1<< 5)
comment|/* Signal detect polarity reversal for the EEE */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_EEE_SD_POL
value|(1<< 6)
comment|/* EEE timer value  */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_EEE_TIMER_VAL_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_EEE_TIMER_VAL_SHIFT
value|8
comment|/*  * Selects source for the enable SerDes DME signal  * 0 â Register value  * 1 â PCS output  */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_DME_SEL
value|(1<< 16)
comment|/* DME default value */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_DME_VAL
value|(1<< 17)
comment|/* DME default polarity reversal when selecting PCS output */
define|#
directive|define
name|ETH_MAC_KR_PCS_CFG_DME_POL
value|(1<< 18)
comment|/**** pcs_stat register ****/
comment|/* Link enable by the Auto-Negotiation */
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_AN_LINK_CONTROL_MASK
value|0x0000003F
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_AN_LINK_CONTROL_SHIFT
value|0
comment|/* Block lock */
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_BLOCK_LOCK
value|(1<< 8)
comment|/* hi BER */
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_HI_BER
value|(1<< 9)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_RX_WAKE_ERR
value|(1<< 16)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_PMA_TXMODE_ALERT
value|(1<< 17)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_PMA_TXMODE_QUIET
value|(1<< 18)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_PMA_RXMODE_QUIET
value|(1<< 19)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_RX_LPI_ACTIVE
value|(1<< 20)
define|#
directive|define
name|ETH_MAC_KR_PCS_STAT_TX_LPI_ACTIVE
value|(1<< 21)
comment|/**** reg_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_SGMII_REG_ADDR_VAL_MASK
value|0x0000001F
define|#
directive|define
name|ETH_MAC_SGMII_REG_ADDR_VAL_SHIFT
value|0
define|#
directive|define
name|ETH_MAC_SGMII_REG_ADDR_CTRL_REG
value|0x0
define|#
directive|define
name|ETH_MAC_SGMII_REG_ADDR_IF_MODE_REG
value|0x14
comment|/**** reg_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_VAL_SHIFT
value|0
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_CTRL_AN_ENABLE
value|(1<< 12)
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_EN
value|(1<< 0)
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_AN
value|(1<< 1)
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_SPEED_MASK
value|0xC
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_SPEED_SHIFT
value|2
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_SPEED_10
value|0x0
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_SPEED_100
value|0x1
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_SPEED_1000
value|0x2
define|#
directive|define
name|ETH_MAC_SGMII_REG_DATA_IF_MODE_SGMII_DUPLEX
value|(1<< 4)
comment|/**** clk_div register ****/
comment|/* Value for 1000M selection */
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_1000_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_1000_SHIFT
value|0
comment|/* Value for 100M selection */
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_100_MASK
value|0x0000FF00
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_100_SHIFT
value|8
comment|/* Value for 10M selection */
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_10_MASK
value|0x00FF0000
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_VAL_10_SHIFT
value|16
comment|/* Bypass PCS selection */
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_BYPASS
value|(1<< 24)
comment|/*  * Divider selection when bypass field is '1', one hot  * 001 â 1000M  * 010 â 100M  * 100 â 10M  */
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_SEL_MASK
value|0x0E000000
define|#
directive|define
name|ETH_MAC_SGMII_CLK_DIV_SEL_SHIFT
value|25
comment|/**** link_stat register ****/
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_SET_1000
value|(1<< 0)
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_SET_100
value|(1<< 1)
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_SET_10
value|(1<< 2)
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_LED_AN
value|(1<< 3)
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_HD_ENA
value|(1<< 4)
define|#
directive|define
name|ETH_MAC_SGMII_LINK_STAT_LED_LINK
value|(1<< 5)
comment|/**** afifo_ctrl register ****/
comment|/* enable tx input operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_TX_IN
value|(1<< 0)
comment|/* enable tx output operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_TX_OUT
value|(1<< 1)
comment|/* enable rx input operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_RX_IN
value|(1<< 4)
comment|/* enable rx output operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_RX_OUT
value|(1<< 5)
comment|/* enable tx FIFO input operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_TX_FIFO_IN
value|(1<< 8)
comment|/* enable tx FIFO output operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_TX_FIFO_OUT
value|(1<< 9)
comment|/* enable rx FIFO input operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_RX_FIFO_IN
value|(1<< 12)
comment|/* enable rx FIFO output operation */
define|#
directive|define
name|ETH_MAC_GEN_V3_AFIFO_CTRL_EN_RX_FIFO_OUT
value|(1<< 13)
comment|/**** tx_afifo_cfg_1 register ****/
comment|/* minimum packet size configuration */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_1_MIN_PKT_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_1_MIN_PKT_SIZE_SHIFT
value|0
comment|/**** tx_afifo_cfg_2 register ****/
comment|/* maximum packet size configuration */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_2_MAX_PKT_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_2_MAX_PKT_SIZE_SHIFT
value|0
comment|/**** tx_afifo_cfg_3 register ****/
comment|/* input bus width */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_3_INPUT_BUS_W_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_3_INPUT_BUS_W_SHIFT
value|0
comment|/* input bus width divide factor */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_3_INPUT_BUS_W_F_MASK
value|0xFFFF0000
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_3_INPUT_BUS_W_F_SHIFT
value|16
comment|/**** tx_afifo_cfg_4 register ****/
comment|/* output bus width */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_4_OUTPUT_BUS_W_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_4_OUTPUT_BUS_W_SHIFT
value|0
comment|/* output bus width divide factor */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_4_OUTPUT_BUS_W_F_MASK
value|0xFFFF0000
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_4_OUTPUT_BUS_W_F_SHIFT
value|16
comment|/**** tx_afifo_cfg_5 register ****/
comment|/*  * determines if the input bus is valid/read or âwrite enableâ.  * 0 â write enable  * 1 â valid/ready  */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_5_INPUT_BUS_VALID_RDY
value|(1<< 0)
comment|/*  * determines if the output bus is valid/read or âwrite enableâ.  * 0 â write enable  * 1 â valid/ready  */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_5_OUTPUT_BUS_VALID_RDY
value|(1<< 1)
comment|/* Swap input bus bytes */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_5_INPUT_BUS_SWAP_BYTES
value|(1<< 4)
comment|/* Swap output bus bytes */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_5_OUTPUT_BUS_SWAP_BYTES
value|(1<< 5)
comment|/*  * output clock select  * 0 â mac_ll_tx_clk  * 1 â clk_mac_sys_clk  */
define|#
directive|define
name|ETH_MAC_GEN_V3_TX_AFIFO_CFG_5_OUTPUT_CLK_SEL
value|(1<< 8)
comment|/**** rx_afifo_cfg_1 register ****/
comment|/* minimum packet size configuration */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_1_MIN_PKT_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_1_MIN_PKT_SIZE_SHIFT
value|0
comment|/**** rx_afifo_cfg_2 register ****/
comment|/* maximum packet size configuration */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_2_MAX_PKT_SIZE_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_2_MAX_PKT_SIZE_SHIFT
value|0
comment|/**** rx_afifo_cfg_3 register ****/
comment|/* input bus width */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_3_INPUT_BUS_W_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_3_INPUT_BUS_W_SHIFT
value|0
comment|/* input bus width divide factor */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_3_INPUT_BUS_W_F_MASK
value|0xFFFF0000
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_3_INPUT_BUS_W_F_SHIFT
value|16
comment|/**** rx_afifo_cfg_4 register ****/
comment|/* output bus width */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_4_OUTPUT_BUS_W_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_4_OUTPUT_BUS_W_SHIFT
value|0
comment|/* output bus width divide factor */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_4_OUTPUT_BUS_W_F_MASK
value|0xFFFF0000
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_4_OUTPUT_BUS_W_F_SHIFT
value|16
comment|/**** rx_afifo_cfg_5 register ****/
comment|/*  * determines if the input bus is valid/read or âwrite enableâ.  * 0 â write enable  * 1 â valid/ready  */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_INPUT_BUS_VALID_RDY
value|(1<< 0)
comment|/*  * determines if the output bus is valid/read or âwrite enableâ.  * 0 â write enable  * 1 â valid/ready  */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_OUTPUT_BUS_VALID_RDY
value|(1<< 1)
comment|/* Swap input bus bytes */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_INPUT_BUS_SWAP_BYTES
value|(1<< 4)
comment|/* Swap output bus bytes */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_OUTPUT_BUS_SWAP_BYTES
value|(1<< 5)
comment|/*  * input clock select  * 0 â mac_ll_rx_clk  * 1 â clk_serdes_int_0_tx_dword_ref  * 2 â clk_mac_sys_clk  * 3 â mac_ll_tx_clk  */
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_INPUT_CLK_SEL_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_V3_RX_AFIFO_CFG_5_INPUT_CLK_SEL_SHIFT
value|8
comment|/**** mac_sel register ****/
comment|/*  * Select the MAC that is connected to the SGMII PCS.  * 0 â 1G MAC  * 1 â 10G MAC  */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_SEL_MAC_10G_SGMII
value|(1<< 0)
comment|/*  * Select between the 10G and 40G MAC  * 0 â 10G MAC  * 1 â 40G MAC  */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_SEL_MAC_10G_40G
value|(1<< 4)
comment|/**** mac_10g_ll_cfg register ****/
comment|/*  * select between 10G (KR PCS) and 1G (SGMII) mode.  * 0 â 10G  * 1 â 1G  */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_10G_LL_CFG_MODE_1G
value|(1<< 0)
comment|/* enable Magic packet detection in the MAC (all other packets are dropped) */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_10G_LL_CFG_MAGIC_ENA
value|(1<< 5)
comment|/**** mac_10g_ll_ctrl register ****/
comment|/* Force the MAC to stop TX transmission after low power mode. */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_10G_LL_CTRL_LPI_TXHOLD
value|(1<< 0)
comment|/**** pcs_10g_ll_cfg register ****/
comment|/* RX FEC Enable */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_FEC_EN_RX
value|(1<< 0)
comment|/* TX FEC enable */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_FEC_EN_TX
value|(1<< 1)
comment|/*  * RX FEC error propagation enable,  * (debug, always 0)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_FEC_ERR_ENA
value|(1<< 2)
comment|/*  * Gearbox configuration:  * 00 -16  * 01 â 20  * 10 â 32  * 11 â reserved  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_TX_GB_CFG_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_TX_GB_CFG_SHIFT
value|4
comment|/*  * Gearbox configuration:  * 00 -16  * 01 â 20  * 10 â 32  * 11 â reserved  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_RX_GB_CFG_MASK
value|0x000000C0
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_CFG_RX_GB_CFG_SHIFT
value|6
comment|/**** pcs_10g_ll_status register ****/
comment|/* FEC locked indication */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_10G_LL_STATUS_FEC_LOCKED
value|(1<< 0)
comment|/**** pcs_40g_ll_cfg register ****/
comment|/* RX FEC Enable */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_EN_RX_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_EN_RX_SHIFT
value|0
comment|/* TX FEC enable */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_EN_TX_MASK
value|0x000000F0
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_EN_TX_SHIFT
value|4
comment|/*  * RX FEC error propagation enable,  * (debug, always 0)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_ERR_EN_MASK
value|0x00000F00
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC_ERR_EN_SHIFT
value|8
comment|/*  * SERDES width, 16 bit enable  * 1 â 16  * 2 â 32  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_SD_16B
value|(1<< 12)
comment|/* FEC 91 enable */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_FEC91_ENA
value|(1<< 13)
comment|/*  * PHY LOS indication selection  * 00 - Select register value from phy_los_def  * 01 - Select input from the SerDes  * 10 - Select input from GPIO  * 11 - Select inverted input from GPIO  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_PHY_LOS_SEL_MASK
value|0x00030000
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_PHY_LOS_SEL_SHIFT
value|16
comment|/* PHY LOS default value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_PHY_LOS_DEF
value|(1<< 18)
comment|/* PHY LOS polarity */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_PHY_LOS_POL
value|(1<< 19)
comment|/*  * Energy detect  indication selection  * 00 - Select register value from phy_los_def  * 01 - Select input from the SerDes  * 10 - Select input from GPIO  * 11 - Select inverted input from GPIO  */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_ENERGY_DETECT_SEL_MASK
value|0x00300000
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_ENERGY_DETECT_SEL_SHIFT
value|20
comment|/* Energy detect default value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_ENERGY_DETECT_DEF
value|(1<< 22)
comment|/* Energy detect polarity */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_CFG_ENERGY_DETECT_POL
value|(1<< 23)
comment|/**** pcs_40g_ll_status register ****/
comment|/* Block lock */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_BLOCK_LOCK_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_BLOCK_LOCK_SHIFT
value|0
comment|/* align done */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_ALIGN_DONE
value|(1<< 4)
comment|/* high BER */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_HIGH_BER
value|(1<< 8)
comment|/* FEC locked indication */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_FEC_LOCKED_MASK
value|0x0000F000
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_STATUS_FEC_LOCKED_SHIFT
value|12
comment|/**** pcs_40g_ll_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_ADDR_VAL_MASK
value|0x0001FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_ADDR_VAL_SHIFT
value|0
comment|/**** pcs_40g_ll_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_DATA_VAL_SHIFT
value|0
comment|/**** mac_40g_ll_cfg register ****/
comment|/* change TX CRC polarity */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_SWAP_FF_TX_CRC
value|(1<< 0)
comment|/* force TX remote fault */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_TX_REM_FAULT
value|(1<< 4)
comment|/* force TX local fault */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_TX_LOC_FAULT
value|(1<< 5)
comment|/* force TX Link fault */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_TX_LI_FAULT
value|(1<< 6)
comment|/*  * PHY LOS indication selection  * 00 - Select register value from phy_los_def  * 01 - Select input from the SerDes  * 10 - Select input from GPIO  * 11 - Select inverted input from GPIO  */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_PHY_LOS_SEL_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_PHY_LOS_SEL_SHIFT
value|8
comment|/* PHY LOS default value */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_PHY_LOS_DEF
value|(1<< 10)
comment|/* PHY LOS polarity */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CFG_PHY_LOS_POL
value|(1<< 11)
comment|/**** mac_40g_ll_status register ****/
comment|/* pause on indication */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_STATUS_PAUSE_ON_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_STATUS_PAUSE_ON_SHIFT
value|0
comment|/* local fault indication received */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_STATUS_LOC_FAULT
value|(1<< 8)
comment|/* remote fault indication received */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_STATUS_REM_FAULT
value|(1<< 9)
comment|/* Link fault indication */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_STATUS_LI_FAULT
value|(1<< 10)
comment|/**** preamble_cfg_high register ****/
comment|/* preamble value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PREAMBLE_CFG_HIGH_VAL_MASK
value|0x00FFFFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_PREAMBLE_CFG_HIGH_VAL_SHIFT
value|0
comment|/**** mac_40g_ll_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_ADDR_VAL_MASK
value|0x000003FF
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_ADDR_VAL_SHIFT
value|0
comment|/**** mac_40g_ll_ctrl register ****/
comment|/* Force the MAC to stop TX transmission after low power mode. */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CTRL_LPI_TXHOLD
value|(1<< 0)
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_LL_CTRL_REG_LOWP_ENA
value|(1<< 1)
comment|/**** pcs_40g_fec_91_ll_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_FEC_91_LL_ADDR_VAL_MASK
value|0x000001FF
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_FEC_91_LL_ADDR_VAL_SHIFT
value|0
comment|/**** pcs_40g_fec_91_ll_data register ****/
comment|/* Data value */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_FEC_91_LL_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_FEC_91_LL_DATA_VAL_SHIFT
value|0
comment|/**** pcs_40g_ll_eee_cfg register ****/
comment|/* Low power timer configuration */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_CFG_TIMER_VAL_MASK
value|0x000000FF
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_CFG_TIMER_VAL_SHIFT
value|0
comment|/* Low power Fast wake */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_CFG_LPI_FW
value|(1<< 8)
comment|/**** pcs_40g_ll_eee_status register ****/
comment|/* TX LPI mode */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_TX_LPI_MODE_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_TX_LPI_MODE_SHIFT
value|0
comment|/* TX LPI state */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_TX_LPI_STATE_MASK
value|0x00000070
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_TX_LPI_STATE_SHIFT
value|4
comment|/* TX LPI mode */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_RX_LPI_MODE
value|(1<< 8)
comment|/* TX LPI state */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_RX_LPI_STATE_MASK
value|0x00007000
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_RX_LPI_STATE_SHIFT
value|12
comment|/* TX LPI active */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_LL_EEE_STATUS_RX_LPI_ACTIVE
value|(1<< 15)
comment|/**** serdes_32_tx_shift register ****/
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_0_MASK
value|0x0000001F
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_0_SHIFT
value|0
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_1_MASK
value|0x000003E0
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_1_SHIFT
value|5
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_2_MASK
value|0x00007C00
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_2_SHIFT
value|10
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_3_MASK
value|0x000F8000
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SHIFT_SERDES_3_SHIFT
value|15
comment|/**** serdes_32_rx_shift register ****/
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_0_MASK
value|0x0000001F
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_0_SHIFT
value|0
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_1_MASK
value|0x000003E0
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_1_SHIFT
value|5
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_2_MASK
value|0x00007C00
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_2_SHIFT
value|10
comment|/* bit shift */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_3_MASK
value|0x000F8000
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SHIFT_SERDES_3_SHIFT
value|15
comment|/**** serdes_32_tx_sel register ****/
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_0_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_0_SHIFT
value|0
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_1_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_1_SHIFT
value|4
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_2_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_2_SHIFT
value|8
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_3_MASK
value|0x00003000
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_TX_SEL_SERDES_3_SHIFT
value|12
comment|/**** serdes_32_rx_sel register ****/
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_0_MASK
value|0x00000003
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_0_SHIFT
value|0
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_1_MASK
value|0x00000030
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_1_SHIFT
value|4
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_2_MASK
value|0x00000300
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_2_SHIFT
value|8
comment|/*  * 0 â directly from serdes  * 1 â swapped  * 2 â swapped with shift  * 3 - legacy (based on gen cfg register)  */
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_3_MASK
value|0x00003000
define|#
directive|define
name|ETH_MAC_GEN_V3_SERDES_32_RX_SEL_SERDES_3_SHIFT
value|12
comment|/**** an_lt_ctrl register ****/
comment|/* reset lane [3:0] */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_SW_RESET_MASK
value|0x0000000F
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_SW_RESET_SHIFT
value|0
comment|/* PHY LOS indication input selection  * 0 - from serdes  * 1 - from an_lt  */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_PHY_LOS_SEL_LANE_0
value|(1<< 8)
comment|/* PHY LOS indication input selection  * 0 - from serdes  * 1 - from an_lt  */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_PHY_LOS_SEL_LANE_1
value|(1<< 9)
comment|/* PHY LOS indication input selection  * 0 - from serdes  * 1 - from an_lt  */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_PHY_LOS_SEL_LANE_2
value|(1<< 10)
comment|/* PHY LOS indication input selection  * 0 - from serdes  * 1 - from an_lt  */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_CTRL_PHY_LOS_SEL_LANE_3
value|(1<< 11)
comment|/**** an_lt_0_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_0_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_0_ADDR_VAL_SHIFT
value|0
comment|/**** an_lt_1_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_1_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_1_ADDR_VAL_SHIFT
value|0
comment|/**** an_lt_2_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_2_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_2_ADDR_VAL_SHIFT
value|0
comment|/**** an_lt_3_addr register ****/
comment|/* Address value */
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_3_ADDR_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|ETH_MAC_GEN_V3_AN_LT_3_ADDR_VAL_SHIFT
value|0
comment|/**** ext_serdes_ctrl register ****/
comment|/*  * Lane 0, SERDES selection:  * 0 â 10G SERDES, lane 0  * 1 â 25G SERDES, lane 0  */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_0_SEL_25_10
value|(1<< 0)
comment|/*  * Lane 1, SERDES selection:  * 0 â 10G SERDES, lane 1  * 1 â 25G SERDES, lane 1  */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_1_SEL_25_10
value|(1<< 1)
comment|/*  * Lane 2, SERDES selection:  * 0 â 10G SERDES, lane 2  * 1 â 25G SERDES, lane 0  */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_2_SEL_25_10
value|(1<< 2)
comment|/*  * Lane 3, SERDES selection:  * 0 â 10G SERDES, lane 3  * 1 â 25G SERDES, lane 1  */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_3_SEL_25_10
value|(1<< 3)
comment|/* Lane 0 Rx, 25G 40bit-32bit gearshitf sw reset */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_0_RX_25_GS_SW_RESET
value|(1<< 4)
comment|/* Lane 0 Tx, 25G 40bit-32bit gearshitf sw reset */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_0_TX_25_GS_SW_RESET
value|(1<< 5)
comment|/* Lane 1 Rx, 25G 40bit-32bit gearshitf sw reset */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_1_RX_25_GS_SW_RESET
value|(1<< 6)
comment|/* Lane 1 Tx, 25G 40bit-32bit gearshitf sw reset */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_LANE_1_TX_25_GS_SW_RESET
value|(1<< 7)
comment|/* SerDes 25G gear shift Tx lane selector */
define|#
directive|define
name|ETH_MAC_GEN_V3_EXT_SERDES_CTRL_SRDS25_GS_TX_LANE_CLK_SEL
value|(1<< 8)
comment|/*** MAC Core registers addresses ***/
comment|/* command config */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_COMMAND_CONFIG_ADDR
value|0x00000008
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_COMMAND_CONFIG_TX_ENA
value|(1<< 0)
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_COMMAND_CONFIG_RX_ENA
value|(1<< 1)
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_COMMAND_CONFIG_PFC_MODE
value|(1<< 19)
comment|/* frame length */
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_FRM_LENGTH_ADDR
value|0x00000014
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL01_PAUSE_QUANTA_ADDR
value|0x00000054
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL23_PAUSE_QUANTA_ADDR
value|0x00000058
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL45_PAUSE_QUANTA_ADDR
value|0x0000005C
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL67_PAUSE_QUANTA_ADDR
value|0x00000060
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL01_QUANTA_THRESH_ADDR
value|0x00000064
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL23_QUANTA_THRESH_ADDR
value|0x00000068
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL45_QUANTA_THRESH_ADDR
value|0x0000006C
define|#
directive|define
name|ETH_MAC_GEN_V3_MAC_40G_CL67_QUANTA_THRESH_ADDR
value|0x00000070
comment|/* spare */
define|#
directive|define
name|ETH_MAC_GEN_V3_SPARE_CHICKEN_DISABLE_TIMESTAMP_STRETCH
value|(1<< 0)
comment|/*** PCS Core registers addresses ***/
comment|/* 40g control/status */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_CONTROL_STATUS_ADDR
value|0x00000000
comment|/* 40g EEE control and capability */
define|#
directive|define
name|ETH_MAC_GEN_V3_PCS_40G_EEE_CONTROL_ADDR
value|0x00000028
comment|/* 10g control_1 */
define|#
directive|define
name|ETH_MAC_KR_PCS_CONTROL_1_ADDR
value|0x00000000
define|#
directive|define
name|ETH_MAC_KR_PCS_BASE_R_STATUS2
value|0x00000021
define|#
directive|define
name|ETH_MAC_KR_AN_MILLISECONDS_COUNTER_ADDR
value|0x00008000
define|#
directive|define
name|ETH_MAC_AN_LT_MILLISECONDS_COUNTER_ADDR
value|0x00000020
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_ETH_MAC_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of Ethernet group */
end_comment

end_unit

