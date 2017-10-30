begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_TGEC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_TGEC_H
end_define

begin_include
include|#
directive|include
file|"common/general.h"
end_include

begin_include
include|#
directive|include
file|"fsl_enet.h"
end_include

begin_comment
comment|/* Transmit Inter-Packet Gap Length Register (TX_IPG_LENGTH) */
end_comment

begin_define
define|#
directive|define
name|TGEC_TX_IPG_LENGTH_MASK
value|0x000003ff
end_define

begin_enum
enum|enum
name|tgec_counters
block|{
name|E_TGEC_COUNTER_R64
block|,
name|E_TGEC_COUNTER_R127
block|,
name|E_TGEC_COUNTER_R255
block|,
name|E_TGEC_COUNTER_R511
block|,
name|E_TGEC_COUNTER_R1023
block|,
name|E_TGEC_COUNTER_R1518
block|,
name|E_TGEC_COUNTER_R1519X
block|,
name|E_TGEC_COUNTER_TRFRG
block|,
name|E_TGEC_COUNTER_TRJBR
block|,
name|E_TGEC_COUNTER_RDRP
block|,
name|E_TGEC_COUNTER_RALN
block|,
name|E_TGEC_COUNTER_TRUND
block|,
name|E_TGEC_COUNTER_TROVR
block|,
name|E_TGEC_COUNTER_RXPF
block|,
name|E_TGEC_COUNTER_TXPF
block|,
name|E_TGEC_COUNTER_ROCT
block|,
name|E_TGEC_COUNTER_RMCA
block|,
name|E_TGEC_COUNTER_RBCA
block|,
name|E_TGEC_COUNTER_RPKT
block|,
name|E_TGEC_COUNTER_RUCA
block|,
name|E_TGEC_COUNTER_RERR
block|,
name|E_TGEC_COUNTER_TOCT
block|,
name|E_TGEC_COUNTER_TMCA
block|,
name|E_TGEC_COUNTER_TBCA
block|,
name|E_TGEC_COUNTER_TUCA
block|,
name|E_TGEC_COUNTER_TERR
block|}
enum|;
end_enum

begin_comment
comment|/* Command and Configuration Register (COMMAND_CONFIG) */
end_comment

begin_define
define|#
directive|define
name|CMD_CFG_EN_TIMESTAMP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_TX_ADDR_INS_SEL
value|0x00080000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_NO_LEN_CHK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_SEND_IDLE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_RX_ER_DISC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_CMD_FRM_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_STAT_CLR
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CMD_CFG_LOOPBACK_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CMD_CFG_TX_ADDR_INS
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_IGNORE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CMD_CFG_PAUSE_FWD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CMD_CFG_PROMIS_EN
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CMD_CFG_WAN_MODE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CMD_CFG_RX_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CMD_CFG_TX_EN
value|0x00000001
end_define

begin_comment
comment|/* Interrupt Mask Register (IMASK) */
end_comment

begin_define
define|#
directive|define
name|TGEC_IMASK_MDIO_SCAN_EVENT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_MDIO_CMD_CMPL
value|0x00008000
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_REM_FAULT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_LOC_FAULT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_TX_ECC_ER
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_TX_FIFO_UNFL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_TX_FIFO_OVFL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_TX_ER
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_FIFO_OVFL
value|0x00000100
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_ECC_ER
value|0x00000080
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_JAB_FRM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_OVRSZ_FRM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_RUNT_FRM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_FRAG_FRM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_LEN_ER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_CRC_ER
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TGEC_IMASK_RX_ALIGN_ER
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TGEC_EVENTS_MASK
define|\
value|((uint32_t)(TGEC_IMASK_MDIO_SCAN_EVENT			| \ 				TGEC_IMASK_MDIO_CMD_CMPL	| \ 				TGEC_IMASK_REM_FAULT		| \ 				TGEC_IMASK_LOC_FAULT		| \ 				TGEC_IMASK_TX_ECC_ER		| \ 				TGEC_IMASK_TX_FIFO_UNFL		| \ 				TGEC_IMASK_TX_FIFO_OVFL		| \ 				TGEC_IMASK_TX_ER		| \ 				TGEC_IMASK_RX_FIFO_OVFL		| \ 				TGEC_IMASK_RX_ECC_ER		| \ 				TGEC_IMASK_RX_JAB_FRM		| \ 				TGEC_IMASK_RX_OVRSZ_FRM		| \ 				TGEC_IMASK_RX_RUNT_FRM		| \ 				TGEC_IMASK_RX_FRAG_FRM		| \ 				TGEC_IMASK_RX_LEN_ER		| \ 				TGEC_IMASK_RX_CRC_ER		| \ 				TGEC_IMASK_RX_ALIGN_ER))
end_define

begin_comment
comment|/* Hashtable Control Register (HASHTABLE_CTRL) */
end_comment

begin_define
define|#
directive|define
name|TGEC_HASH_MCAST_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|TGEC_HASH_MCAST_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|TGEC_HASH_ADR_MSK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|DEFAULT_WAN_MODE_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROMISCUOUS_MODE_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PAUSE_FORWARD_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PAUSE_IGNORE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_ADDR_INS_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOOPBACK_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_CMD_FRAME_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_ERROR_DISCARD
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_SEND_IDLE_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_NO_LENGTH_CHECK_ENABLE
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_LGTH_CHECK_NOSTDR
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TIME_STAMP_ENABLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_IPG_LENGTH
value|12
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAX_FRAME_LENGTH
value|0x600
end_define

begin_define
define|#
directive|define
name|DEFAULT_PAUSE_QUANT
value|0xf000
end_define

begin_comment
comment|/*  * 10G memory map  */
end_comment

begin_struct
struct|struct
name|tgec_regs
block|{
name|uint32_t
name|tgec_id
decl_stmt|;
comment|/* 0x000 Controller ID */
name|uint32_t
name|reserved001
index|[
literal|1
index|]
decl_stmt|;
comment|/* 0x004 */
name|uint32_t
name|command_config
decl_stmt|;
comment|/* 0x008 Control and configuration */
name|uint32_t
name|mac_addr_0
decl_stmt|;
comment|/* 0x00c Lower 32 bits of the MAC adr */
name|uint32_t
name|mac_addr_1
decl_stmt|;
comment|/* 0x010 Upper 16 bits of the MAC adr */
name|uint32_t
name|maxfrm
decl_stmt|;
comment|/* 0x014 Maximum frame length */
name|uint32_t
name|pause_quant
decl_stmt|;
comment|/* 0x018 Pause quanta */
name|uint32_t
name|rx_fifo_sections
decl_stmt|;
comment|/* 0x01c  */
name|uint32_t
name|tx_fifo_sections
decl_stmt|;
comment|/* 0x020  */
name|uint32_t
name|rx_fifo_almost_f_e
decl_stmt|;
comment|/* 0x024  */
name|uint32_t
name|tx_fifo_almost_f_e
decl_stmt|;
comment|/* 0x028  */
name|uint32_t
name|hashtable_ctrl
decl_stmt|;
comment|/* 0x02c Hash table control*/
name|uint32_t
name|mdio_cfg_status
decl_stmt|;
comment|/* 0x030  */
name|uint32_t
name|mdio_command
decl_stmt|;
comment|/* 0x034  */
name|uint32_t
name|mdio_data
decl_stmt|;
comment|/* 0x038  */
name|uint32_t
name|mdio_regaddr
decl_stmt|;
comment|/* 0x03c  */
name|uint32_t
name|status
decl_stmt|;
comment|/* 0x040  */
name|uint32_t
name|tx_ipg_len
decl_stmt|;
comment|/* 0x044 Transmitter inter-packet-gap */
name|uint32_t
name|mac_addr_2
decl_stmt|;
comment|/* 0x048 Lower 32 bits of 2nd MAC adr */
name|uint32_t
name|mac_addr_3
decl_stmt|;
comment|/* 0x04c Upper 16 bits of 2nd MAC adr */
name|uint32_t
name|rx_fifo_ptr_rd
decl_stmt|;
comment|/* 0x050  */
name|uint32_t
name|rx_fifo_ptr_wr
decl_stmt|;
comment|/* 0x054  */
name|uint32_t
name|tx_fifo_ptr_rd
decl_stmt|;
comment|/* 0x058  */
name|uint32_t
name|tx_fifo_ptr_wr
decl_stmt|;
comment|/* 0x05c  */
name|uint32_t
name|imask
decl_stmt|;
comment|/* 0x060 Interrupt mask */
name|uint32_t
name|ievent
decl_stmt|;
comment|/* 0x064 Interrupt event */
name|uint32_t
name|udp_port
decl_stmt|;
comment|/* 0x068 Defines a UDP Port number */
name|uint32_t
name|type_1588v2
decl_stmt|;
comment|/* 0x06c Type field for 1588v2 */
name|uint32_t
name|reserved070
index|[
literal|4
index|]
decl_stmt|;
comment|/* 0x070 */
comment|/*10Ge Statistics Counter */
name|uint32_t
name|tfrm_u
decl_stmt|;
comment|/* 80 aFramesTransmittedOK */
name|uint32_t
name|tfrm_l
decl_stmt|;
comment|/* 84 aFramesTransmittedOK */
name|uint32_t
name|rfrm_u
decl_stmt|;
comment|/* 88 aFramesReceivedOK */
name|uint32_t
name|rfrm_l
decl_stmt|;
comment|/* 8c aFramesReceivedOK */
name|uint32_t
name|rfcs_u
decl_stmt|;
comment|/* 90 aFrameCheckSequenceErrors */
name|uint32_t
name|rfcs_l
decl_stmt|;
comment|/* 94 aFrameCheckSequenceErrors */
name|uint32_t
name|raln_u
decl_stmt|;
comment|/* 98 aAlignmentErrors */
name|uint32_t
name|raln_l
decl_stmt|;
comment|/* 9c aAlignmentErrors */
name|uint32_t
name|txpf_u
decl_stmt|;
comment|/* A0 aPAUSEMACCtrlFramesTransmitted */
name|uint32_t
name|txpf_l
decl_stmt|;
comment|/* A4 aPAUSEMACCtrlFramesTransmitted */
name|uint32_t
name|rxpf_u
decl_stmt|;
comment|/* A8 aPAUSEMACCtrlFramesReceived */
name|uint32_t
name|rxpf_l
decl_stmt|;
comment|/* Ac aPAUSEMACCtrlFramesReceived */
name|uint32_t
name|rlong_u
decl_stmt|;
comment|/* B0 aFrameTooLongErrors */
name|uint32_t
name|rlong_l
decl_stmt|;
comment|/* B4 aFrameTooLongErrors */
name|uint32_t
name|rflr_u
decl_stmt|;
comment|/* B8 aInRangeLengthErrors */
name|uint32_t
name|rflr_l
decl_stmt|;
comment|/* Bc aInRangeLengthErrors */
name|uint32_t
name|tvlan_u
decl_stmt|;
comment|/* C0 VLANTransmittedOK */
name|uint32_t
name|tvlan_l
decl_stmt|;
comment|/* C4 VLANTransmittedOK */
name|uint32_t
name|rvlan_u
decl_stmt|;
comment|/* C8 VLANReceivedOK */
name|uint32_t
name|rvlan_l
decl_stmt|;
comment|/* Cc VLANReceivedOK */
name|uint32_t
name|toct_u
decl_stmt|;
comment|/* D0 ifOutOctets */
name|uint32_t
name|toct_l
decl_stmt|;
comment|/* D4 ifOutOctets */
name|uint32_t
name|roct_u
decl_stmt|;
comment|/* D8 ifInOctets */
name|uint32_t
name|roct_l
decl_stmt|;
comment|/* Dc ifInOctets */
name|uint32_t
name|ruca_u
decl_stmt|;
comment|/* E0 ifInUcastPkts */
name|uint32_t
name|ruca_l
decl_stmt|;
comment|/* E4 ifInUcastPkts */
name|uint32_t
name|rmca_u
decl_stmt|;
comment|/* E8 ifInMulticastPkts */
name|uint32_t
name|rmca_l
decl_stmt|;
comment|/* Ec ifInMulticastPkts */
name|uint32_t
name|rbca_u
decl_stmt|;
comment|/* F0 ifInBroadcastPkts */
name|uint32_t
name|rbca_l
decl_stmt|;
comment|/* F4 ifInBroadcastPkts */
name|uint32_t
name|terr_u
decl_stmt|;
comment|/* F8 ifOutErrors */
name|uint32_t
name|terr_l
decl_stmt|;
comment|/* Fc ifOutErrors */
name|uint32_t
name|reserved100
index|[
literal|2
index|]
decl_stmt|;
comment|/* 100-108*/
name|uint32_t
name|tuca_u
decl_stmt|;
comment|/* 108 ifOutUcastPkts */
name|uint32_t
name|tuca_l
decl_stmt|;
comment|/* 10c ifOutUcastPkts */
name|uint32_t
name|tmca_u
decl_stmt|;
comment|/* 110 ifOutMulticastPkts */
name|uint32_t
name|tmca_l
decl_stmt|;
comment|/* 114 ifOutMulticastPkts */
name|uint32_t
name|tbca_u
decl_stmt|;
comment|/* 118 ifOutBroadcastPkts */
name|uint32_t
name|tbca_l
decl_stmt|;
comment|/* 11c ifOutBroadcastPkts */
name|uint32_t
name|rdrp_u
decl_stmt|;
comment|/* 120 etherStatsDropEvents */
name|uint32_t
name|rdrp_l
decl_stmt|;
comment|/* 124 etherStatsDropEvents */
name|uint32_t
name|reoct_u
decl_stmt|;
comment|/* 128 etherStatsOctets */
name|uint32_t
name|reoct_l
decl_stmt|;
comment|/* 12c etherStatsOctets */
name|uint32_t
name|rpkt_u
decl_stmt|;
comment|/* 130 etherStatsPkts */
name|uint32_t
name|rpkt_l
decl_stmt|;
comment|/* 134 etherStatsPkts */
name|uint32_t
name|trund_u
decl_stmt|;
comment|/* 138 etherStatsUndersizePkts */
name|uint32_t
name|trund_l
decl_stmt|;
comment|/* 13c etherStatsUndersizePkts */
name|uint32_t
name|r64_u
decl_stmt|;
comment|/* 140 etherStatsPkts64Octets */
name|uint32_t
name|r64_l
decl_stmt|;
comment|/* 144 etherStatsPkts64Octets */
name|uint32_t
name|r127_u
decl_stmt|;
comment|/* 148 etherStatsPkts65to127Octets */
name|uint32_t
name|r127_l
decl_stmt|;
comment|/* 14c etherStatsPkts65to127Octets */
name|uint32_t
name|r255_u
decl_stmt|;
comment|/* 150 etherStatsPkts128to255Octets */
name|uint32_t
name|r255_l
decl_stmt|;
comment|/* 154 etherStatsPkts128to255Octets */
name|uint32_t
name|r511_u
decl_stmt|;
comment|/* 158 etherStatsPkts256to511Octets */
name|uint32_t
name|r511_l
decl_stmt|;
comment|/* 15c etherStatsPkts256to511Octets */
name|uint32_t
name|r1023_u
decl_stmt|;
comment|/* 160 etherStatsPkts512to1023Octets */
name|uint32_t
name|r1023_l
decl_stmt|;
comment|/* 164 etherStatsPkts512to1023Octets */
name|uint32_t
name|r1518_u
decl_stmt|;
comment|/* 168 etherStatsPkts1024to1518Octets */
name|uint32_t
name|r1518_l
decl_stmt|;
comment|/* 16c etherStatsPkts1024to1518Octets */
name|uint32_t
name|r1519x_u
decl_stmt|;
comment|/* 170 etherStatsPkts1519toX */
name|uint32_t
name|r1519x_l
decl_stmt|;
comment|/* 174 etherStatsPkts1519toX */
name|uint32_t
name|trovr_u
decl_stmt|;
comment|/* 178 etherStatsOversizePkts */
name|uint32_t
name|trovr_l
decl_stmt|;
comment|/* 17c etherStatsOversizePkts */
name|uint32_t
name|trjbr_u
decl_stmt|;
comment|/* 180 etherStatsJabbers */
name|uint32_t
name|trjbr_l
decl_stmt|;
comment|/* 184 etherStatsJabbers */
name|uint32_t
name|trfrg_u
decl_stmt|;
comment|/* 188 etherStatsFragments */
name|uint32_t
name|trfrg_l
decl_stmt|;
comment|/* 18C etherStatsFragments */
name|uint32_t
name|rerr_u
decl_stmt|;
comment|/* 190 ifInErrors */
name|uint32_t
name|rerr_l
decl_stmt|;
comment|/* 194 ifInErrors */
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct tgec_cfg - TGEC configuration  *  * @rx_error_discard:    Receive Erroneous Frame Discard Enable. When set to 1  *            any frame received with an error is discarded in the  *            Core and not forwarded to the Client interface.  *            When set to 0 (Reset value), erroneous Frames are  *            forwarded to the Client interface with ff_rx_err  *            asserted.  * @pause_ignore:    Ignore Pause Frame Quanta. If set to 1 received pause  *            frames are ignored by the MAC. When set to 0  *            (Reset value) the transmit process is stopped for the  *            amount of time specified in the pause quanta received  *            within a pause frame.  * @pause_forward_enable:  *            Terminate / Forward Pause Frames. If set to 1 pause  *            frames are forwarded to the user application. When set  *            to 0 (Reset value) pause frames are terminated and  *            discarded within the MAC.  * @no_length_check_enable:  *            Payload Length Check Disable. When set to 0  *            (Reset value), the Core checks the frame's payload  *            length with the Frame Length/Type field, when set to 1  *            the payload length check is disabled.  * @cmd_frame_enable:    Enables reception of all command frames. When set to 1  *            all Command Frames are accepted, when set to 0  *            (Reset Value) only Pause Frames are accepted and all  *            other Command Frames are rejected.  * @send_idle_enable:    Force Idle Generation. When set to 1, the MAC  *            permanently sends XGMII Idle sequences even when faults  *            are received.  * @wan_mode_enable:    WAN Mode Enable. Sets WAN mode (1) or LAN mode  *            (0, default) of operation.  * @promiscuous_mode_enable:  *            Enables MAC promiscuous operation. When set to 1, all  *            frames are received without any MAC address filtering,  *            when set to 0 (Reset value) Unicast Frames with a  *            destination address not matching the Core MAC Address  *            (MAC Address programmed in Registers MAC_ADDR_0 and  *            MAC_ADDR_1 or the MAC address programmed in Registers  *            MAC_ADDR_2 and MAC_ADDR_3) are rejected.  * @tx_addr_ins_enable:    Set Source MAC Address on Transmit. If set to 1 the  *            MAC overwrites the source MAC address received from the  *            Client Interface with one of the MAC addresses. If set  *            to 0 (Reset value), the source MAC address from the  *            Client Interface is transmitted unmodified to the line.  * @loopback_enable:    PHY Interface Loopback. When set to 1, the signal  *            loop_ena is set to '1', when set to 0 (Reset value)  *            the signal loop_ena is set to 0.  * @lgth_check_nostdr:    The Core interprets the Length/Type field differently  *            depending on the value of this Bit  * @time_stamp_enable:    This bit selects between enabling and disabling the  *            IEEE 1588 functionality. 1: IEEE 1588 is enabled  *            0: IEEE 1588 is disabled  * @max_frame_length:    Maximum supported received frame length.  *            The 10GEC MAC supports reception of any frame size up  *            to 16,352 bytes (0x3FE0). Typical settings are  *            0x05EE (1,518 bytes) for standard frames.  *            Default setting is 0x0600 (1,536 bytes).  *            Received frames that exceed this stated maximum  *            are truncated.  * @pause_quant:    Pause quanta value used with transmitted pause frames.  *            Each quanta represents a 512 bit-times.  * @tx_ipg_length:    Transmit Inter-Packet-Gap (IPG) value. A 6-bit value:  *            Depending on LAN or WAN mode of operation the value has  *            the following meaning: - LAN Mode: Number of octets in  *            steps of 4. Valid values are 8, 12, 16, ... 100. DIC is  *            fully supported (see 10.6.1 page 49) for any setting. A  *            default of 12 (reset value) must be set to conform to  *            IEEE802.3ae. Warning: When set to 8, PCS layers may not  *            be able to perform clock rate compensation. - WAN Mode:  *            Stretch factor. Valid values are 4..15. The stretch  *            factor is calculated as (value+1)*8. A default of 12  *            (reset value) must be set to conform to IEEE 802.3ae  *            (i.e. 13*8=104). A larger value shrinks the IPG  *            (increasing bandwidth).  *  * This structure contains basic TGEC configuration and must be passed to  * fman_tgec_init() function.  A default set of configuration values can be  * obtained by calling fman_tgec_defconfig().  */
end_comment

begin_struct
struct|struct
name|tgec_cfg
block|{
name|bool
name|rx_error_discard
decl_stmt|;
name|bool
name|pause_ignore
decl_stmt|;
name|bool
name|pause_forward_enable
decl_stmt|;
name|bool
name|no_length_check_enable
decl_stmt|;
name|bool
name|cmd_frame_enable
decl_stmt|;
name|bool
name|send_idle_enable
decl_stmt|;
name|bool
name|wan_mode_enable
decl_stmt|;
name|bool
name|promiscuous_mode_enable
decl_stmt|;
name|bool
name|tx_addr_ins_enable
decl_stmt|;
name|bool
name|loopback_enable
decl_stmt|;
name|bool
name|lgth_check_nostdr
decl_stmt|;
name|bool
name|time_stamp_enable
decl_stmt|;
name|uint16_t
name|max_frame_length
decl_stmt|;
name|uint16_t
name|pause_quant
decl_stmt|;
name|uint32_t
name|tx_ipg_length
decl_stmt|;
name|bool
name|skip_fman11_workaround
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|fman_tgec_defconfig
parameter_list|(
name|struct
name|tgec_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_init() - Init tgec hardware block  * @regs:        Pointer to tgec register block  * @cfg:        tgec configuration data  * @exceptions_mask:    initial exceptions mask  *  * This function initializes the tgec controller and applies its  * basic configuration.  *  * Returns: 0 if successful, an error code otherwise.  */
end_comment

begin_function_decl
name|int
name|fman_tgec_init
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|struct
name|tgec_cfg
modifier|*
name|cfg
parameter_list|,
name|uint32_t
name|exception_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_enable
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|apply_rx
parameter_list|,
name|bool
name|apply_tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_disable
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|apply_rx
parameter_list|,
name|bool
name|apply_tx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_tgec_get_revision
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_set_mac_address
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
modifier|*
name|macaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_set_promiscuous
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_reset_stat() - Completely resets all TGEC HW counters  * @regs:    Pointer to TGEC register block  */
end_comment

begin_function_decl
name|void
name|fman_tgec_reset_stat
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_get_counter() - Reads TGEC HW counters  * @regs:    Pointer to TGEC register block  * @reg_name:    Counter name according to the appropriate enum  *  * Returns:    Required counter value  */
end_comment

begin_function_decl
name|uint64_t
name|fman_tgec_get_counter
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|tgec_counters
name|reg_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_set_hash_table() - Sets the Hashtable Control Register  * @regs:    Pointer to TGEC register block  * @value:    Value to be written in Hashtable Control Register  */
end_comment

begin_function_decl
name|void
name|fman_tgec_set_hash_table
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_set_tx_pause_frames() - Sets the Pause Quanta Register  * @regs:    Pointer to TGEC register block  * @pause_time:    Pause quanta value used with transmitted pause frames.  *        Each quanta represents a 512 bit-times  */
end_comment

begin_function_decl
name|void
name|fman_tgec_set_tx_pause_frames
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|pause_time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_set_rx_ignore_pause_frames() - Changes the policy WRT pause frames  * @regs:    Pointer to TGEC register block  * @en:        Ignore/Respond to pause frame quanta  *  * Sets the value of PAUSE_IGNORE field in the COMMAND_CONFIG Register  * 0 - MAC stops transmit process for the duration specified  * in the Pause frame quanta of a received Pause frame.  * 1 - MAC ignores received Pause frames.  */
end_comment

begin_function_decl
name|void
name|fman_tgec_set_rx_ignore_pause_frames
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_enable_1588_time_stamp() - change timestamp functionality  * @regs:    Pointer to TGEC register block  * @en:        enable/disable timestamp functionality  *  * Sets the value of EN_TIMESTAMP field in the COMMAND_CONFIG Register  * IEEE 1588 timestamp functionality control:  * 0 disabled, 1 enabled  */
end_comment

begin_function_decl
name|void
name|fman_tgec_enable_1588_time_stamp
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_tgec_get_event
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_ack_event
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_tgec_get_interrupt_mask
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_add_addr_in_paddr() - Sets additional exact match MAC address  * @regs:    Pointer to TGEC register block  * @addr_ptr:    Pointer to 6-byte array containing the MAC address  *  * Sets the additional station MAC address  */
end_comment

begin_function_decl
name|void
name|fman_tgec_add_addr_in_paddr
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
modifier|*
name|addr_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_clear_addr_in_paddr
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_enable_interrupt
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_disable_interrupt
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_reset_filter_table
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_tgec_set_hash_table_entry
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|crc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_get_max_frame_len() - Returns the maximum frame length value  * @regs:    Pointer to TGEC register block  */
end_comment

begin_function_decl
name|uint16_t
name|fman_tgec_get_max_frame_len
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_tgec_set_erratum_tx_fifo_corruption_10gmac_a007() - Initialize the  * main tgec configuration parameters  * @regs:    Pointer to TGEC register block  *  * TODO  */
end_comment

begin_function_decl
name|void
name|fman_tgec_set_erratum_tx_fifo_corruption_10gmac_a007
parameter_list|(
name|struct
name|tgec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FSL_FMAN_TGEC_H */
end_comment

end_unit

