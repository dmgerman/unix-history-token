begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FSL_FMAN_DTSEC_H
end_ifndef

begin_define
define|#
directive|define
name|__FSL_FMAN_DTSEC_H
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
comment|/**  * DOC: dTSEC Init sequence  *  * To prepare dTSEC block for transfer use the following call sequence:  *  * - fman_dtsec_defconfig() - This step is optional and yet recommended. Its  * use is to obtain the default dTSEC configuration parameters.  *  * - Change dtsec configuration in&dtsec_cfg. This structure will be used  * to customize the dTSEC behavior.  *  * - fman_dtsec_init() - Applies the configuration on dTSEC hardware.  Note that  * dTSEC is initialized while both Tx and Rx are disabled.  *  * - fman_dtsec_set_mac_address() - Set the station address (mac address).  * This is used by dTSEC to match against received packets.  *  * - fman_dtsec_adjust_link() - Set the link speed and duplex parameters  * after the PHY establishes the link.  *  * - dtsec_enable_tx() and dtsec_enable_rx() to enable transmission and  * reception.  */
end_comment

begin_comment
comment|/**  * DOC: dTSEC Graceful stop  *  * To temporary stop dTSEC activity use fman_dtsec_stop_tx() and  * fman_dtsec_stop_rx(). Note that these functions request dTSEC graceful stop  * but return before this stop is complete.  To query for graceful stop  * completion use fman_dtsec_get_event() and check DTSEC_IEVENT_GTSC and  * DTSEC_IEVENT_GRSC bits. Alternatively the dTSEC interrupt mask can be set to  * enable graceful stop interrupts.  *  * To resume operation after graceful stop use fman_dtsec_start_tx() and  * fman_dtsec_start_rx().  */
end_comment

begin_comment
comment|/**  * DOC: dTSEC interrupt handling  *  * This code does not provide an interrupt handler for dTSEC.  Instead this  * handler should be implemented and registered to the operating system by the  * caller.  Some primitives for accessing the event status and mask registers  * are provided.  *  * See "dTSEC Events" section for a list of events that dTSEC can generate.  */
end_comment

begin_comment
comment|/**  * DOC: dTSEC Events  *  * Interrupt events cause dTSEC event bits to be set.  Software may poll the  * event register at any time to check for pending interrupts.  If an event  * occurs and its corresponding enable bit is set in the interrupt mask  * register, the event also causes a hardware interrupt at the PIC.  *  * To poll for event status use the fman_dtsec_get_event() function.  * To configure the interrupt mask use fman_dtsec_enable_interrupt() and  * fman_dtsec_disable_interrupt() functions.  * After servicing a dTSEC interrupt use fman_dtsec_ack_event to reset the  * serviced event bit.  *  * The following events may be signaled by dTSEC hardware:  *  * %DTSEC_IEVENT_BABR - Babbling receive error.  This bit indicates that  * a frame was received with length in excess of the MAC's maximum frame length  * register.  *  * %DTSEC_IEVENT_RXC - Receive control (pause frame) interrupt.  A pause  * control frame was received while Rx pause frame handling is enabled.  * Also see fman_dtsec_handle_rx_pause().  *  * %DTSEC_IEVENT_MSRO - MIB counter overflow.  The count for one of the MIB  * counters has exceeded the size of its register.  *  * %DTSEC_IEVENT_GTSC - Graceful transmit stop complete.  Graceful stop is now  * complete. The transmitter is in a stopped state, in which only pause frames  * can be transmitted.  * Also see fman_dtsec_stop_tx().  *  * %DTSEC_IEVENT_BABT - Babbling transmit error.  The transmitted frame length  * has exceeded the value in the MAC's Maximum Frame Length register.  *  * %DTSEC_IEVENT_TXC - Transmit control (pause frame) interrupt.  his bit  * indicates that a control frame was transmitted.  *  * %DTSEC_IEVENT_TXE - Transmit error.  This bit indicates that an error  * occurred on the transmitted channel.  This bit is set whenever any transmit  * error occurs which causes the dTSEC to discard all or part of a frame  * (LC, CRL, XFUN).  *  * %DTSEC_IEVENT_LC - Late collision.  This bit indicates that a collision  * occurred beyond the collision window (slot time) in half-duplex mode.  * The frame is truncated with a bad CRC and the remainder of the frame  * is discarded.  *  * %DTSEC_IEVENT_CRL - Collision retry limit.  is bit indicates that the number  * of successive transmission collisions has exceeded the MAC's half-duplex  * register's retransmission maximum count.  The frame is discarded without  * being transmitted and transmission of the next frame commences.  This only  * occurs while in half-duplex mode.  * The number of retransmit attempts can be set in  *&dtsec_halfdup_cfg.@retransmit before calling fman_dtsec_init().  *  * %DTSEC_IEVENT_XFUN - Transmit FIFO underrun.  This bit indicates that the  * transmit FIFO became empty before the complete frame was transmitted.  * The frame is truncated with a bad CRC and the remainder of the frame is  * discarded.  *  * %DTSEC_IEVENT_MAG - TBD  *  * %DTSEC_IEVENT_MMRD - MII management read completion.  *  * %DTSEC_IEVENT_MMWR - MII management write completion.  *  * %DTSEC_IEVENT_GRSC - Graceful receive stop complete.  It allows the user to  * know if the system has completed the stop and it is safe to write to receive  * registers (status, control or configuration registers) that are used by the  * system during normal operation.  *  * %DTSEC_IEVENT_TDPE - Internal data error on transmit.  This bit indicates  * that the dTSEC has detected a parity error on its stored transmit data, which  * is likely to compromise the validity of recently transferred frames.  *  * %DTSEC_IEVENT_RDPE - Internal data error on receive.  This bit indicates that  * the dTSEC has detected a parity error on its stored receive data, which is  * likely to compromise the validity of recently transferred frames.  */
end_comment

begin_comment
comment|/* Interrupt Mask Register (IMASK) */
end_comment

begin_define
define|#
directive|define
name|DTSEC_IMASK_BREN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_RXCEN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_MSROEN
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_GTSCEN
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_BTEN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_TXCEN
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_TXEEN
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_LCEN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_CRLEN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_XFUNEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_ABRTEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_IFERREN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_MAGEN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_MMRDEN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_MMWREN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_GRSCEN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_TDPEEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DTSEC_IMASK_RDPEEN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DTSEC_EVENTS_MASK
define|\
value|((uint32_t)(DTSEC_IMASK_BREN    | \ 				DTSEC_IMASK_RXCEN   | \ 				DTSEC_IMASK_BTEN    | \ 				DTSEC_IMASK_TXCEN   | \ 				DTSEC_IMASK_TXEEN   | \ 				DTSEC_IMASK_ABRTEN  | \ 				DTSEC_IMASK_LCEN    | \ 				DTSEC_IMASK_CRLEN   | \ 				DTSEC_IMASK_XFUNEN  | \ 				DTSEC_IMASK_IFERREN | \ 				DTSEC_IMASK_MAGEN   | \ 				DTSEC_IMASK_TDPEEN  | \ 				DTSEC_IMASK_RDPEEN))
end_define

begin_comment
comment|/* dtsec timestamp event bits */
end_comment

begin_define
define|#
directive|define
name|TMR_PEMASK_TSREEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|TMR_PEVENT_TSRE
value|0x00010000
end_define

begin_comment
comment|/* Group address bit indication */
end_comment

begin_define
define|#
directive|define
name|MAC_GROUP_ADDRESS
value|0x0000010000000000ULL
end_define

begin_comment
comment|/* size in bytes of L2 address */
end_comment

begin_define
define|#
directive|define
name|MAC_ADDRLEN
value|6
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_ON
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_RETRANSMIT
value|0xf
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_COLL_WINDOW
value|0x37
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_EXCESS_DEFER
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_NO_BACKOFF
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_BP_NO_BACKOFF
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_ALT_BACKOFF_VAL
value|0x0A
end_define

begin_define
define|#
directive|define
name|DEFAULT_HALFDUP_ALT_BACKOFF_EN
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_DROP_BCAST
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_SHORT_FRM
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_LEN_CHECK
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_PAD_CRC
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_CRC
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_CTRL_ACC
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_PAUSE_TIME
value|0xf000
end_define

begin_define
define|#
directive|define
name|DEFAULT_TBIPA
value|5
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_PREPEND
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_PTP_TSU_EN
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PTP_EXCEPTION_EN
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_PREAMBLE_LEN
value|7
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_PREAMBLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_PREAMBLE
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_LOOPBACK
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_TIME_STAMP_EN
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_TIME_STAMP_EN
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_FLOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_FLOW
value|TRUE
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_GROUP_HASH_EXD
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_TX_PAUSE_TIME_EXTD
value|0
end_define

begin_define
define|#
directive|define
name|DEFAULT_RX_PROMISC
value|FALSE
end_define

begin_define
define|#
directive|define
name|DEFAULT_NON_BACK_TO_BACK_IPG1
value|0x40
end_define

begin_define
define|#
directive|define
name|DEFAULT_NON_BACK_TO_BACK_IPG2
value|0x60
end_define

begin_define
define|#
directive|define
name|DEFAULT_MIN_IFG_ENFORCEMENT
value|0x50
end_define

begin_define
define|#
directive|define
name|DEFAULT_BACK_TO_BACK_IPG
value|0x60
end_define

begin_define
define|#
directive|define
name|DEFAULT_MAXIMUM_FRAME
value|0x600
end_define

begin_define
define|#
directive|define
name|DEFAULT_TBI_PHY_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|DEFAULT_WAKE_ON_LAN
value|FALSE
end_define

begin_comment
comment|/* register related defines (bits, field offsets..) */
end_comment

begin_define
define|#
directive|define
name|DTSEC_ID1_ID
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|DTSEC_ID1_REV_MJ
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|DTSEC_ID1_REV_MN
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|DTSEC_ID2_INT_REDUCED_OFF
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DTSEC_ID2_INT_NORMAL_OFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_CLRCNT
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_AUTOZ
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_STEN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_CFG_RO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_GMIIM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_TBIM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_SGMIIM
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_RPM
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_R100M
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_RMM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DTSEC_ECNTRL_QSGMIIM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DTSEC_TCTRL_THDF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DTSEC_TCTRL_TTSE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DTSEC_TCTRL_GTS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DTSEC_TCTRL_TFC_PAUSE
value|0x00000010
end_define

begin_comment
comment|/* PTV offsets */
end_comment

begin_define
define|#
directive|define
name|PTV_PTE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|RCTRL_CFA
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RCTRL_GHTX
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RCTRL_RTSE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RCTRL_GRS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RCTRL_BC_REJ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RCTRL_MPROM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RCTRL_RSF
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RCTRL_UPROM
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RCTRL_PROM
value|(RCTRL_UPROM | RCTRL_MPROM)
end_define

begin_define
define|#
directive|define
name|TMR_CTL_ESFDP
value|0x00000800
end_define

begin_define
define|#
directive|define
name|TMR_CTL_ESFDE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|MACCFG1_SOFT_RESET
value|0x80000000
end_define

begin_define
define|#
directive|define
name|MACCFG1_LOOPBACK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MACCFG1_RX_FLOW
value|0x00000020
end_define

begin_define
define|#
directive|define
name|MACCFG1_TX_FLOW
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACCFG1_TX_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MACCFG1_RX_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_RxMC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_TxMC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_RxFUN
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MACCFG1_RESET_TxFUN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MACCFG2_NIBBLE_MODE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|MACCFG2_BYTE_MODE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|MACCFG2_PRE_AM_Rx_EN
value|0x00000080
end_define

begin_define
define|#
directive|define
name|MACCFG2_PRE_AM_Tx_EN
value|0x00000040
end_define

begin_define
define|#
directive|define
name|MACCFG2_LENGTH_CHECK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|MACCFG2_MAGIC_PACKET_EN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MACCFG2_PAD_CRC_EN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MACCFG2_CRC_EN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MACCFG2_FULL_DUPLEX
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PREAMBLE_LENGTH_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_1_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|IPGIFG_MIN_IFG_ENFORCEMENT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_1
value|0x7F000000
end_define

begin_define
define|#
directive|define
name|IPGIFG_NON_BACK_TO_BACK_IPG_2
value|0x007F0000
end_define

begin_define
define|#
directive|define
name|IPGIFG_MIN_IFG_ENFORCEMENT
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|IPGIFG_BACK_TO_BACK_IPG
value|0x0000007F
end_define

begin_define
define|#
directive|define
name|HAFDUP_ALT_BEB
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HAFDUP_BP_NO_BACKOFF
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HAFDUP_NO_BACKOFF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HAFDUP_EXCESS_DEFER
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HAFDUP_COLLISION_WINDOW
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|HAFDUP_ALTERNATE_BEB_TRUNCATION_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HAFDUP_RETRANSMISSION_MAX_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HAFDUP_RETRANSMISSION_MAX
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|NUM_OF_HASH_REGS
value|8
end_define

begin_comment
comment|/* Number of hash table registers */
end_comment

begin_comment
comment|/* CAR1/2 bits */
end_comment

begin_define
define|#
directive|define
name|DTSEC_CAR1_TR64
value|0x80000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TR127
value|0x40000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TR255
value|0x20000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TR511
value|0x10000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TRK1
value|0x08000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TRMAX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_TRMGV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RBYT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RPKT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RFCS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RMCA
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RBCA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RXCF
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RXPF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RXUO
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RALN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RFLR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RCDE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RCSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RUND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_ROVR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RFRG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RJBR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR1_RDRP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TJBR
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TFCS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TXCF
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TOVR
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TUND
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TFRG
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TBYT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TPKT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TMCA
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TBCA
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TXPF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TDFR
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TEDF
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TSCL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TMCL
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TLCL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TXCL
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TNCL
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DTSEC_CAR2_TDRP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CAM1_ERRORS_ONLY
define|\
value|(DTSEC_CAR1_RXPF | DTSEC_CAR1_RALN | DTSEC_CAR1_RFLR \ 	| DTSEC_CAR1_RCDE | DTSEC_CAR1_RCSE | DTSEC_CAR1_RUND \ 	| DTSEC_CAR1_ROVR | DTSEC_CAR1_RFRG | DTSEC_CAR1_RJBR \ 	| DTSEC_CAR1_RDRP)
end_define

begin_define
define|#
directive|define
name|CAM2_ERRORS_ONLY
value|(DTSEC_CAR2_TFCS | DTSEC_CAR2_TXPF | DTSEC_CAR2_TDRP)
end_define

begin_comment
comment|/*  * Group of dTSEC specific counters relating to the standard RMON MIB Group 1  * (or Ethernet) statistics.  */
end_comment

begin_define
define|#
directive|define
name|CAM1_MIB_GRP_1
define|\
value|(DTSEC_CAR1_RDRP | DTSEC_CAR1_RBYT | DTSEC_CAR1_RPKT | DTSEC_CAR1_RMCA\ 	| DTSEC_CAR1_RBCA | DTSEC_CAR1_RALN | DTSEC_CAR1_RUND | DTSEC_CAR1_ROVR\ 	| DTSEC_CAR1_RFRG | DTSEC_CAR1_RJBR \ 	| DTSEC_CAR1_TR64 | DTSEC_CAR1_TR127 | DTSEC_CAR1_TR255 \ 	| DTSEC_CAR1_TR511 | DTSEC_CAR1_TRMAX)
end_define

begin_define
define|#
directive|define
name|CAM2_MIB_GRP_1
value|(DTSEC_CAR2_TNCL | DTSEC_CAR2_TDRP)
end_define

begin_comment
comment|/* memory map */
end_comment

begin_struct
struct|struct
name|dtsec_regs
block|{
comment|/* dTSEC General Control and Status Registers */
name|uint32_t
name|tsec_id
decl_stmt|;
comment|/* 0x000 ETSEC_ID register */
name|uint32_t
name|tsec_id2
decl_stmt|;
comment|/* 0x004 ETSEC_ID2 register */
name|uint32_t
name|ievent
decl_stmt|;
comment|/* 0x008 Interrupt event register */
name|uint32_t
name|imask
decl_stmt|;
comment|/* 0x00C Interrupt mask register */
name|uint32_t
name|reserved0010
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|ecntrl
decl_stmt|;
comment|/* 0x014 E control register */
name|uint32_t
name|ptv
decl_stmt|;
comment|/* 0x018 Pause time value register */
name|uint32_t
name|tbipa
decl_stmt|;
comment|/* 0x01C TBI PHY address register */
name|uint32_t
name|tmr_ctrl
decl_stmt|;
comment|/* 0x020 Time-stamp Control register */
name|uint32_t
name|tmr_pevent
decl_stmt|;
comment|/* 0x024 Time-stamp event register */
name|uint32_t
name|tmr_pemask
decl_stmt|;
comment|/* 0x028 Timer event mask register */
name|uint32_t
name|reserved002c
index|[
literal|5
index|]
decl_stmt|;
name|uint32_t
name|tctrl
decl_stmt|;
comment|/* 0x040 Transmit control register */
name|uint32_t
name|reserved0044
index|[
literal|3
index|]
decl_stmt|;
name|uint32_t
name|rctrl
decl_stmt|;
comment|/* 0x050 Receive control register */
name|uint32_t
name|reserved0054
index|[
literal|11
index|]
decl_stmt|;
name|uint32_t
name|igaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x080-0x09C Individual/group address */
name|uint32_t
name|gaddr
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0x0A0-0x0BC Group address registers 0-7 */
name|uint32_t
name|reserved00c0
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|maccfg1
decl_stmt|;
comment|/* 0x100 MAC configuration #1 */
name|uint32_t
name|maccfg2
decl_stmt|;
comment|/* 0x104 MAC configuration #2 */
name|uint32_t
name|ipgifg
decl_stmt|;
comment|/* 0x108 IPG/IFG */
name|uint32_t
name|hafdup
decl_stmt|;
comment|/* 0x10C Half-duplex */
name|uint32_t
name|maxfrm
decl_stmt|;
comment|/* 0x110 Maximum frame */
name|uint32_t
name|reserved0114
index|[
literal|10
index|]
decl_stmt|;
name|uint32_t
name|ifstat
decl_stmt|;
comment|/* 0x13C Interface status */
name|uint32_t
name|macstnaddr1
decl_stmt|;
comment|/* 0x140 Station Address,part 1 */
name|uint32_t
name|macstnaddr2
decl_stmt|;
comment|/* 0x144 Station Address,part 2  */
struct|struct
block|{
name|uint32_t
name|exact_match1
decl_stmt|;
comment|/* octets 1-4 */
name|uint32_t
name|exact_match2
decl_stmt|;
comment|/* octets 5-6 */
block|}
name|macaddr
index|[
literal|15
index|]
struct|;
comment|/* 0x148-0x1BC mac exact match addresses 1-15 */
name|uint32_t
name|reserved01c0
index|[
literal|16
index|]
decl_stmt|;
name|uint32_t
name|tr64
decl_stmt|;
comment|/* 0x200 transmit and receive 64 byte frame counter */
name|uint32_t
name|tr127
decl_stmt|;
comment|/* 0x204 transmit and receive 65 to 127 byte frame 			 * counter */
name|uint32_t
name|tr255
decl_stmt|;
comment|/* 0x208 transmit and receive 128 to 255 byte frame 			 * counter */
name|uint32_t
name|tr511
decl_stmt|;
comment|/* 0x20C transmit and receive 256 to 511 byte frame 			 * counter */
name|uint32_t
name|tr1k
decl_stmt|;
comment|/* 0x210 transmit and receive 512 to 1023 byte frame 			 * counter */
name|uint32_t
name|trmax
decl_stmt|;
comment|/* 0x214 transmit and receive 1024 to 1518 byte frame 			 * counter */
name|uint32_t
name|trmgv
decl_stmt|;
comment|/* 0x218 transmit and receive 1519 to 1522 byte good 			 * VLAN frame count */
name|uint32_t
name|rbyt
decl_stmt|;
comment|/* 0x21C receive byte counter */
name|uint32_t
name|rpkt
decl_stmt|;
comment|/* 0x220 receive packet counter */
name|uint32_t
name|rfcs
decl_stmt|;
comment|/* 0x224 receive FCS error counter */
name|uint32_t
name|rmca
decl_stmt|;
comment|/* 0x228 RMCA receive multicast packet counter */
name|uint32_t
name|rbca
decl_stmt|;
comment|/* 0x22C receive broadcast packet counter */
name|uint32_t
name|rxcf
decl_stmt|;
comment|/* 0x230 receive control frame packet counter */
name|uint32_t
name|rxpf
decl_stmt|;
comment|/* 0x234 receive pause frame packet counter */
name|uint32_t
name|rxuo
decl_stmt|;
comment|/* 0x238 receive unknown OP code counter */
name|uint32_t
name|raln
decl_stmt|;
comment|/* 0x23C receive alignment error counter */
name|uint32_t
name|rflr
decl_stmt|;
comment|/* 0x240 receive frame length error counter */
name|uint32_t
name|rcde
decl_stmt|;
comment|/* 0x244 receive code error counter */
name|uint32_t
name|rcse
decl_stmt|;
comment|/* 0x248 receive carrier sense error counter */
name|uint32_t
name|rund
decl_stmt|;
comment|/* 0x24C receive undersize packet counter */
name|uint32_t
name|rovr
decl_stmt|;
comment|/* 0x250 receive oversize packet counter */
name|uint32_t
name|rfrg
decl_stmt|;
comment|/* 0x254 receive fragments counter */
name|uint32_t
name|rjbr
decl_stmt|;
comment|/* 0x258 receive jabber counter */
name|uint32_t
name|rdrp
decl_stmt|;
comment|/* 0x25C receive drop */
name|uint32_t
name|tbyt
decl_stmt|;
comment|/* 0x260 transmit byte counter */
name|uint32_t
name|tpkt
decl_stmt|;
comment|/* 0x264 transmit packet counter */
name|uint32_t
name|tmca
decl_stmt|;
comment|/* 0x268 transmit multicast packet counter */
name|uint32_t
name|tbca
decl_stmt|;
comment|/* 0x26C transmit broadcast packet counter */
name|uint32_t
name|txpf
decl_stmt|;
comment|/* 0x270 transmit pause control frame counter */
name|uint32_t
name|tdfr
decl_stmt|;
comment|/* 0x274 transmit deferral packet counter */
name|uint32_t
name|tedf
decl_stmt|;
comment|/* 0x278 transmit excessive deferral packet counter */
name|uint32_t
name|tscl
decl_stmt|;
comment|/* 0x27C transmit single collision packet counter */
name|uint32_t
name|tmcl
decl_stmt|;
comment|/* 0x280 transmit multiple collision packet counter */
name|uint32_t
name|tlcl
decl_stmt|;
comment|/* 0x284 transmit late collision packet counter */
name|uint32_t
name|txcl
decl_stmt|;
comment|/* 0x288 transmit excessive collision packet counter */
name|uint32_t
name|tncl
decl_stmt|;
comment|/* 0x28C transmit total collision counter */
name|uint32_t
name|reserved0290
index|[
literal|1
index|]
decl_stmt|;
name|uint32_t
name|tdrp
decl_stmt|;
comment|/* 0x294 transmit drop frame counter */
name|uint32_t
name|tjbr
decl_stmt|;
comment|/* 0x298 transmit jabber frame counter */
name|uint32_t
name|tfcs
decl_stmt|;
comment|/* 0x29C transmit FCS error counter */
name|uint32_t
name|txcf
decl_stmt|;
comment|/* 0x2A0 transmit control frame counter */
name|uint32_t
name|tovr
decl_stmt|;
comment|/* 0x2A4 transmit oversize frame counter */
name|uint32_t
name|tund
decl_stmt|;
comment|/* 0x2A8 transmit undersize frame counter */
name|uint32_t
name|tfrg
decl_stmt|;
comment|/* 0x2AC transmit fragments frame counter */
name|uint32_t
name|car1
decl_stmt|;
comment|/* 0x2B0 carry register one register* */
name|uint32_t
name|car2
decl_stmt|;
comment|/* 0x2B4 carry register two register* */
name|uint32_t
name|cam1
decl_stmt|;
comment|/* 0x2B8 carry register one mask register */
name|uint32_t
name|cam2
decl_stmt|;
comment|/* 0x2BC carry register two mask register */
name|uint32_t
name|reserved02c0
index|[
literal|848
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * struct dtsec_mib_grp_1_counters - MIB counter overflows  *  * @tr64:	Transmit and Receive 64 byte frame count.  Increment for each  *		good or bad frame, of any type, transmitted or received, which  *		is 64 bytes in length.  * @tr127:	Transmit and Receive 65 to 127 byte frame count.  Increments for  *		each good or bad frame of any type, transmitted or received,  *		which is 65-127 bytes in length.  * @tr255:	Transmit and Receive 128 to 255 byte frame count.  Increments  *		for each good or bad frame, of any type, transmitted or  *		received, which is 128-255 bytes in length.  * @tr511:	Transmit and Receive 256 to 511 byte frame count.  Increments  *		for each good or bad frame, of any type, transmitted or  *		received, which is 256-511 bytes in length.  * @tr1k:	Transmit and Receive 512 to 1023 byte frame count.  Increments  *		for each good or bad frame, of any type, transmitted or  *		received, which is 512-1023 bytes in length.  * @trmax:	Transmit and Receive 1024 to 1518 byte frame count.  Increments  *		for each good or bad frame, of any type, transmitted or  *		received, which is 1024-1518 bytes in length.  * @rfrg:	Receive fragments count.  Increments for each received frame  *		which is less than 64 bytes in length and contains an invalid  *		FCS.  This includes integral and non-integral lengths.  * @rjbr:	Receive jabber count.  Increments for received frames which  *		exceed 1518 (non VLAN) or 1522 (VLAN) bytes and contain an  *		invalid FCS.  This includes alignment errors.  * @rdrp:	Receive dropped packets count.  Increments for received frames  *		which are streamed to system but are later dropped due to lack  *		of system resources.  Does not increment for frames rejected due  *		to address filtering.  * @raln:	Receive alignment error count.  Increments for each received  *		frame from 64 to 1518 (non VLAN) or 1522 (VLAN) which contains  *		an invalid FCS and is not an integral number of bytes.  * @rund:	Receive undersize packet count.  Increments each time a frame is  *		received which is less than 64 bytes in length and contains a  *		valid FCS and is otherwise well formed.  This count does not  *		include range length errors.  * @rovr:	Receive oversize packet count.  Increments each time a frame is  *		received which exceeded 1518 (non VLAN) or 1522 (VLAN) and  *		contains a valid FCS and is otherwise well formed.  * @rbyt:	Receive byte count.  Increments by the byte count of frames  *		received, including those in bad packets, excluding preamble and  *		SFD but including FCS bytes.  * @rpkt:	Receive packet count.  Increments for each received frame  *		(including bad packets, all unicast, broadcast, and multicast  *		packets).  * @rmca:	Receive multicast packet count.  Increments for each multicast  *		frame with valid CRC and of lengths 64 to 1518 (non VLAN) or  *		1522 (VLAN), excluding broadcast frames. This count does not  *		include range/length errors.  * @rbca:	Receive broadcast packet count.  Increments for each broadcast  *		frame with valid CRC and of lengths 64 to 1518 (non VLAN) or  *		1522 (VLAN), excluding multicast frames. Does not include  *		range/length errors.  * @tdrp:	Transmit drop frame count.  Increments each time a memory error  *		or an underrun has occurred.  * @tncl:	Transmit total collision counter. Increments by the number of  *		collisions experienced during the transmission of a frame. Does  *		not increment for aborted frames.  *  * The structure contains a group of dTSEC HW specific counters relating to the  * standard RMON MIB Group 1 (or Ethernet statistics) counters.  This structure  * is counting only the carry events of the corresponding HW counters.  *  * tr64 to trmax notes: Frame sizes specified are considered excluding preamble  * and SFD but including FCS bytes.  */
end_comment

begin_struct
struct|struct
name|dtsec_mib_grp_1_counters
block|{
name|uint64_t
name|rdrp
decl_stmt|;
name|uint64_t
name|tdrp
decl_stmt|;
name|uint64_t
name|rbyt
decl_stmt|;
name|uint64_t
name|rpkt
decl_stmt|;
name|uint64_t
name|rbca
decl_stmt|;
name|uint64_t
name|rmca
decl_stmt|;
name|uint64_t
name|raln
decl_stmt|;
name|uint64_t
name|rund
decl_stmt|;
name|uint64_t
name|rovr
decl_stmt|;
name|uint64_t
name|rfrg
decl_stmt|;
name|uint64_t
name|rjbr
decl_stmt|;
name|uint64_t
name|tncl
decl_stmt|;
name|uint64_t
name|tr64
decl_stmt|;
name|uint64_t
name|tr127
decl_stmt|;
name|uint64_t
name|tr255
decl_stmt|;
name|uint64_t
name|tr511
decl_stmt|;
name|uint64_t
name|tr1k
decl_stmt|;
name|uint64_t
name|trmax
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|dtsec_stat_counters
block|{
name|E_DTSEC_STAT_TR64
block|,
name|E_DTSEC_STAT_TR127
block|,
name|E_DTSEC_STAT_TR255
block|,
name|E_DTSEC_STAT_TR511
block|,
name|E_DTSEC_STAT_TR1K
block|,
name|E_DTSEC_STAT_TRMAX
block|,
name|E_DTSEC_STAT_TRMGV
block|,
name|E_DTSEC_STAT_RBYT
block|,
name|E_DTSEC_STAT_RPKT
block|,
name|E_DTSEC_STAT_RMCA
block|,
name|E_DTSEC_STAT_RBCA
block|,
name|E_DTSEC_STAT_RXPF
block|,
name|E_DTSEC_STAT_RALN
block|,
name|E_DTSEC_STAT_RFLR
block|,
name|E_DTSEC_STAT_RCDE
block|,
name|E_DTSEC_STAT_RCSE
block|,
name|E_DTSEC_STAT_RUND
block|,
name|E_DTSEC_STAT_ROVR
block|,
name|E_DTSEC_STAT_RFRG
block|,
name|E_DTSEC_STAT_RJBR
block|,
name|E_DTSEC_STAT_RDRP
block|,
name|E_DTSEC_STAT_TFCS
block|,
name|E_DTSEC_STAT_TBYT
block|,
name|E_DTSEC_STAT_TPKT
block|,
name|E_DTSEC_STAT_TMCA
block|,
name|E_DTSEC_STAT_TBCA
block|,
name|E_DTSEC_STAT_TXPF
block|,
name|E_DTSEC_STAT_TNCL
block|,
name|E_DTSEC_STAT_TDRP
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dtsec_stat_level
block|{
comment|/* No statistics */
name|E_MAC_STAT_NONE
init|=
literal|0
block|,
comment|/* Only RMON MIB group 1 (ether stats). Optimized for performance */
name|E_MAC_STAT_MIB_GRP1
block|,
comment|/* Only error counters are available. Optimized for performance */
name|E_MAC_STAT_PARTIAL
block|,
comment|/* All counters available. Not optimized for performance */
name|E_MAC_STAT_FULL
block|}
enum|;
end_enum

begin_comment
comment|/**  * struct dtsec_cfg - dTSEC configuration  *  * @halfdup_on:		Transmit half-duplex flow control, under software  *			control for 10/100-Mbps half-duplex media. If set,  *			back pressure is applied to media by raising carrier.  * @halfdup_retransmit:	Number of retransmission attempts following a collision.  *			If this is exceeded dTSEC aborts transmission due to  *			excessive collisions. The standard specifies the  *			attempt limit to be 15.  * @halfdup_coll_window:The number of bytes of the frame during which  *			collisions may occur. The default value of 55  *			corresponds to the frame byte at the end of the  *			standard 512-bit slot time window. If collisions are  *			detected after this byte, the late collision event is  *			asserted and transmission of current frame is aborted.  * @rx_drop_bcast:	Discard broadcast frames.  If set, all broadcast frames  *			will be discarded by dTSEC.  * @rx_short_frm:	Accept short frames.  If set, dTSEC will accept frames  *			of length 14..63 bytes.  * @rx_len_check:	Length check for received frames.  If set, the MAC  *			checks the frame's length field on receive to ensure it  *			matches the actual data field length. This only works  *			for received frames with length field less than 1500.  *			No check is performed for larger frames.  * @tx_pad_crc:		Pad and append CRC.  If set, the MAC pads all  *			transmitted short frames and appends a CRC to every  *			frame regardless of padding requirement.  * @tx_crc:		Transmission CRC enable.  If set, the MAC appends a CRC  *			to all frames.  If frames presented to the MAC have a  *			valid length and contain a valid CRC, @tx_crc should be  *			reset.  *			This field is ignored if @tx_pad_crc is set.  * @rx_ctrl_acc:	Control frame accept.  If set, this overrides 802.3  *			standard control frame behavior, and all Ethernet frames  *			that have an ethertype of 0x8808 are treated as normal  *			Ethernet frames and passed up to the packet interface on  *			a DA match.  Received pause control frames are passed to  *			the packet interface only if Rx flow control is also  *			disabled.  See fman_dtsec_handle_rx_pause() function.  * @tx_pause_time:	Transmit pause time value.  This pause value is used as  *			part of the pause frame to be sent when a transmit pause  *			frame is initiated.  If set to 0 this disables  *			transmission of pause frames.  * @rx_preamble:	Receive preamble enable.  If set, the MAC recovers the  *			received Ethernet 7-byte preamble and passes it to the  *			packet interface at the start of each received frame.  *			This field should be reset for internal MAC loop-back  *			mode.  * @tx_preamble:	User defined preamble enable for transmitted frames.  *			If set, a user-defined preamble must passed to the MAC  *			and it is transmitted instead of the standard preamble.  * @preamble_len:	Length, in bytes, of the preamble field preceding each  *			Ethernet start-of-frame delimiter byte.  The default  *			value of 0x7 should be used in order to guarantee  *			reliable operation with IEEE 802.3 compliant hardware.  * @rx_prepend:		Packet alignment padding length.  The specified number  *			of bytes (1-31) of zero padding are inserted before the  *			start of each received frame.  For Ethernet, where  *			optional preamble extraction is enabled, the padding  *			appears before the preamble, otherwise the padding  *			precedes the layer 2 header.  *  * This structure contains basic dTSEC configuration and must be passed to  * fman_dtsec_init() function.  A default set of configuration values can be  * obtained by calling fman_dtsec_defconfig().  */
end_comment

begin_struct
struct|struct
name|dtsec_cfg
block|{
name|bool
name|halfdup_on
decl_stmt|;
name|bool
name|halfdup_alt_backoff_en
decl_stmt|;
name|bool
name|halfdup_excess_defer
decl_stmt|;
name|bool
name|halfdup_no_backoff
decl_stmt|;
name|bool
name|halfdup_bp_no_backoff
decl_stmt|;
name|uint8_t
name|halfdup_alt_backoff_val
decl_stmt|;
name|uint16_t
name|halfdup_retransmit
decl_stmt|;
name|uint16_t
name|halfdup_coll_window
decl_stmt|;
name|bool
name|rx_drop_bcast
decl_stmt|;
name|bool
name|rx_short_frm
decl_stmt|;
name|bool
name|rx_len_check
decl_stmt|;
name|bool
name|tx_pad_crc
decl_stmt|;
name|bool
name|tx_crc
decl_stmt|;
name|bool
name|rx_ctrl_acc
decl_stmt|;
name|unsigned
name|short
name|tx_pause_time
decl_stmt|;
name|unsigned
name|short
name|tbipa
decl_stmt|;
name|bool
name|ptp_tsu_en
decl_stmt|;
name|bool
name|ptp_exception_en
decl_stmt|;
name|bool
name|rx_preamble
decl_stmt|;
name|bool
name|tx_preamble
decl_stmt|;
name|unsigned
name|char
name|preamble_len
decl_stmt|;
name|unsigned
name|char
name|rx_prepend
decl_stmt|;
name|bool
name|loopback
decl_stmt|;
name|bool
name|rx_time_stamp_en
decl_stmt|;
name|bool
name|tx_time_stamp_en
decl_stmt|;
name|bool
name|rx_flow
decl_stmt|;
name|bool
name|tx_flow
decl_stmt|;
name|bool
name|rx_group_hash_exd
decl_stmt|;
name|bool
name|rx_promisc
decl_stmt|;
name|uint8_t
name|tbi_phy_addr
decl_stmt|;
name|uint16_t
name|tx_pause_time_extd
decl_stmt|;
name|uint16_t
name|maximum_frame
decl_stmt|;
name|uint32_t
name|non_back_to_back_ipg1
decl_stmt|;
name|uint32_t
name|non_back_to_back_ipg2
decl_stmt|;
name|uint32_t
name|min_ifg_enforcement
decl_stmt|;
name|uint32_t
name|back_to_back_ipg
decl_stmt|;
name|bool
name|wake_on_lan
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * fman_dtsec_defconfig() - Get default dTSEC configuration  * @cfg:	pointer to configuration structure.  *  * Call this function to obtain a default set of configuration values for  * initializing dTSEC.  The user can overwrite any of the values before calling  * fman_dtsec_init(), if specific configuration needs to be applied.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_defconfig
parameter_list|(
name|struct
name|dtsec_cfg
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_init() - Init dTSEC hardware block  * @regs:		Pointer to dTSEC register block  * @cfg:		dTSEC configuration data  * @iface_mode:		dTSEC interface mode, the type of MAC - PHY interface.  * @iface_speed:	1G or 10G  * @macaddr:		MAC station address to be assigned to the device  * @fm_rev_maj:		major rev number  * @fm_rev_min:		minor rev number  * @exceptions_mask:	initial exceptions mask  *  * This function initializes dTSEC and applies basic configuration.  *  * dTSEC initialization sequence:  * Before enabling Rx/Tx call dtsec_set_address() to set MAC address,  * fman_dtsec_adjust_link() to configure interface speed and duplex and finally  * dtsec_enable_tx()/dtsec_enable_rx() to start transmission and reception.  *  * Returns: 0 if successful, an error code otherwise.  */
end_comment

begin_function_decl
name|int
name|fman_dtsec_init
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|struct
name|dtsec_cfg
modifier|*
name|cfg
parameter_list|,
name|enum
name|enet_interface
name|iface_mode
parameter_list|,
name|enum
name|enet_speed
name|iface_speed
parameter_list|,
name|uint8_t
modifier|*
name|macaddr
parameter_list|,
name|uint8_t
name|fm_rev_maj
parameter_list|,
name|uint8_t
name|fm_rev_min
parameter_list|,
name|uint32_t
name|exception_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_enable() - Enable dTSEC Tx and Tx  * @regs:	Pointer to dTSEC register block  * @apply_rx:	enable rx side  * @apply_tx:	enable tx side  *  * This function resets Tx and Rx graceful stop bit and enables dTSEC Tx and Rx.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_enable
parameter_list|(
name|struct
name|dtsec_regs
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

begin_comment
comment|/**  * fman_dtsec_disable() - Disable dTSEC Tx and Rx  * @regs:	Pointer to dTSEC register block  * @apply_rx:	disable rx side  * @apply_tx:	disable tx side  *  * This function disables Tx and Rx in dTSEC.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_disable
parameter_list|(
name|struct
name|dtsec_regs
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

begin_comment
comment|/**  * fman_dtsec_get_revision() - Get dTSEC hardware revision  * @regs:   Pointer to dTSEC register block  *  * Returns dtsec_id content  *  * Call this function to obtain the dTSEC hardware version.  */
end_comment

begin_function_decl
name|uint32_t
name|fman_dtsec_get_revision
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_mac_address() - Set MAC station address  * @regs:   Pointer to dTSEC register block  * @macaddr:    MAC address array  *  * This function sets MAC station address.  To enable unicast reception call  * this after fman_dtsec_init().  While promiscuous mode is disabled dTSEC will  * match the destination address of received unicast frames against this  * address.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_mac_address
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
modifier|*
name|macaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_get_mac_address() - Query MAC station address  * @regs:   Pointer to dTSEC register block  * @macaddr:    MAC address array  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_get_mac_address
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
modifier|*
name|macaddr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_uc_promisc() - Sets unicast promiscuous mode  * @regs:	Pointer to dTSEC register block  * @enable:	Enable unicast promiscuous mode  *  * Use this function to enable/disable dTSEC L2 address filtering.  If the  * address filtering is disabled all unicast packets are accepted.  * To set dTSEC in promiscuous mode call both fman_dtsec_set_uc_promisc() and  * fman_dtsec_set_mc_promisc() to disable filtering for both unicast and  * multicast addresses.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_uc_promisc
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_wol() - Enable/Disable wake on lan  *                        (magic packet support)  * @regs:   Pointer to dTSEC register block  * @en:     Enable Wake On Lan support in dTSEC  *  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_wol
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_adjust_link() - Adjust dTSEC speed/duplex settings  * @regs:	Pointer to dTSEC register block  * @iface_mode: dTSEC interface mode  * @speed:	Link speed  * @full_dx:	True for full-duplex, false for half-duplex.  *  * This function configures the MAC to function and the desired rates.  Use it  * to configure dTSEC after fman_dtsec_init() and whenever the link speed  * changes (for instance following PHY auto-negociation).  *  * Returns: 0 if successful, an error code otherwise.  */
end_comment

begin_function_decl
name|int
name|fman_dtsec_adjust_link
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|enet_interface
name|iface_mode
parameter_list|,
name|enum
name|enet_speed
name|speed
parameter_list|,
name|bool
name|full_dx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_tbi_phy_addr() - Updates TBI address field  * @regs:	Pointer to dTSEC register block  * @address:	Valid PHY address in the range of 1 to 31. 0 is reserved.  *  * In SGMII mode, the dTSEC's TBIPA field must contain a valid TBI PHY address  * so that the associated TBI PHY (i.e. the link) may be initialized.  *  * Returns: 0 if successful, an error code otherwise.  */
end_comment

begin_function_decl
name|int
name|fman_dtsec_set_tbi_phy_addr
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_max_frame_len() - Set max frame length  * @regs:	Pointer to dTSEC register block  * @length:	Max frame length.  *  * Sets maximum frame length for received and transmitted frames.  Frames that  * exceeds this length are truncated.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_max_frame_len
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_get_max_frame_len() - Query max frame length  * @regs:	Pointer to dTSEC register block  *  * Returns: the current value of the maximum frame length.  */
end_comment

begin_function_decl
name|uint16_t
name|fman_dtsec_get_max_frame_len
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_handle_rx_pause() - Configure pause frame handling  * @regs:	Pointer to dTSEC register block  * @en:		Enable pause frame handling in dTSEC  *  * If enabled, dTSEC will handle pause frames internally.  This must be disabled  * if dTSEC is set in half-duplex mode.  * If pause frame handling is disabled and&dtsec_cfg.rx_ctrl_acc is set, pause  * frames will be transferred to the packet interface just like regular Ethernet  * frames.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_handle_rx_pause
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_tx_pause_frames() - Configure Tx pause time  * @regs:	Pointer to dTSEC register block  * @time:	Time value included in pause frames  *  * Call this function to set the time value used in transmitted pause frames.  * If time is 0, transmission of pause frames is disabled  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_tx_pause_frames
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint16_t
name|time
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_ack_event() - Acknowledge handled events  * @regs:	Pointer to dTSEC register block  * @ev_mask:	Events to acknowledge  *  * After handling events signaled by dTSEC in either polling or interrupt mode,  * call this function to reset the associated status bits in dTSEC event  * register.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_ack_event
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_get_event() - Returns currently asserted events  * @regs:	Pointer to dTSEC register block  * @ev_mask:	Mask of relevant events  *  * Call this function to obtain a bit-mask of events that are currently asserted  * in dTSEC, taken from IEVENT register.  *  * Returns: a bit-mask of events asserted in dTSEC.  */
end_comment

begin_function_decl
name|uint32_t
name|fman_dtsec_get_event
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_get_interrupt_mask() - Returns a bit-mask of enabled interrupts  * @regs:   Pointer to dTSEC register block  *  * Call this function to obtain a bit-mask of enabled interrupts  * in dTSEC, taken from IMASK register.  *  * Returns: a bit-mask of enabled interrupts in dTSEC.  */
end_comment

begin_function_decl
name|uint32_t
name|fman_dtsec_get_interrupt_mask
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_clear_addr_in_paddr
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint8_t
name|paddr_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_add_addr_in_paddr
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|uint8_t
name|paddr_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_enable_tmr_interrupt
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_disable_tmr_interrupt
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_disable_interrupt() - Disables interrupts for the specified events  * @regs:	Pointer to dTSEC register block  * @ev_mask:	Mask of relevant events  *  * Call this function to disable interrupts in dTSEC for the specified events.  * To enable interrupts use fman_dtsec_enable_interrupt().  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_disable_interrupt
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_enable_interrupt() - Enable interrupts for the specified events  * @regs:	Pointer to dTSEC register block  * @ev_mask:	Mask of relevant events  *  * Call this function to enable interrupts in dTSEC for the specified events.  * To disable interrupts use fman_dtsec_disable_interrupt().  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_enable_interrupt
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|ev_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_ts() - Enables dTSEC timestamps  * @regs:	Pointer to dTSEC register block  * @en:		true to enable timestamps, false to disable them  *  * Call this function to enable/disable dTSEC timestamps.  This affects both  * Tx and Rx.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_ts
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_bucket() - Enables/disables a filter bucket  * @regs:   Pointer to dTSEC register block  * @bucket: Bucket index  * @enable: true/false to enable/disable this bucket  *  * This function enables or disables the specified bucket.  Enabling a bucket  * associated with an address configures dTSEC to accept received packets  * with that destination address.  * Multiple addresses may be associated with the same bucket.  Disabling a  * bucket will affect all addresses associated with that bucket. A bucket that  * is enabled requires further filtering and verification in the upper layers  *  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_bucket
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|int
name|bucket
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * dtsec_set_hash_table() - insert a crc code into thr filter table  * @regs:	Pointer to dTSEC register block  * @crc:	crc to insert  * @mcast:	true is this is a multicast address  * @ghtx:	true if we are in ghtx mode  *  * This function inserts a crc code into the filter table.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_hash_table
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
name|crc
parameter_list|,
name|bool
name|mcast
parameter_list|,
name|bool
name|ghtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_reset_filter_table() - Resets the address filtering table  * @regs:	Pointer to dTSEC register block  * @mcast:	Reset multicast entries  * @ucast:	Reset unicast entries  *  * Resets all entries in L2 address filter table.  After calling this function  * all buckets enabled using fman_dtsec_set_bucket() will be disabled.  * If dtsec_init_filter_table() was called with @unicast_hash set to false,  * @ucast argument is ignored.  * This does not affect the primary nor the 15 additional addresses configured  * using dtsec_set_address() or dtsec_set_match_address().  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_reset_filter_table
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|mcast
parameter_list|,
name|bool
name|ucast
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_set_mc_promisc() - Set multicast promiscuous mode  * @regs:	Pointer to dTSEC register block  * @enable:	Enable multicast promiscuous mode  *  * Call this to enable/disable L2 address filtering for multicast packets.  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_set_mc_promisc
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|bool
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* statistics APIs */
end_comment

begin_comment
comment|/**  * fman_dtsec_set_stat_level() - Enable a group of MIB statistics counters  * @regs:	Pointer to dTSEC register block  * @level:	Specifies a certain group of dTSEC MIB HW counters or _all_,  *		to specify all the existing counters.  *		If set to _none_, it disables all the counters.  *  * Enables the MIB statistics hw counters and sets up the carry interrupt  * masks for the counters corresponding to the @level input parameter.  *  * Returns: error if invalid @level value given.  */
end_comment

begin_function_decl
name|int
name|fman_dtsec_set_stat_level
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|dtsec_stat_level
name|level
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_reset_stat() - Completely resets all dTSEC HW counters  * @regs:	Pointer to dTSEC register block  */
end_comment

begin_function_decl
name|void
name|fman_dtsec_reset_stat
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * fman_dtsec_get_clear_carry_regs() - Read and clear carry bits (CAR1-2 registers)  * @regs:	Pointer to dTSEC register block  * @car1:	car1 register value  * @car2:	car2 register value  *  * When set, the carry bits signal that an overflow occurred on the  * corresponding counters.  * Note that the carry bits (CAR1-2 registers) will assert the  * %DTSEC_IEVENT_MSRO interrupt if unmasked (via CAM1-2 regs).  *  * Returns: true if overflow occurred, otherwise - false  */
end_comment

begin_function_decl
name|bool
name|fman_dtsec_get_clear_carry_regs
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|uint32_t
modifier|*
name|car1
parameter_list|,
name|uint32_t
modifier|*
name|car2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_dtsec_check_and_clear_tmr_event
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_dtsec_get_stat_counter
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|,
name|enum
name|dtsec_stat_counters
name|reg_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_start_tx
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_start_rx
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_stop_tx
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fman_dtsec_stop_rx
parameter_list|(
name|struct
name|dtsec_regs
modifier|*
name|regs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|fman_dtsec_get_rctrl
parameter_list|(
name|struct
name|dtsec_regs
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
comment|/* __FSL_FMAN_DTSEC_H */
end_comment

end_unit

