begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: if_txvar.h,v 1.7 1999/11/17 05:21:19 jason Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Configuration  */
end_comment

begin_comment
comment|/*#define	EPIC_DEBUG	1*/
end_comment

begin_comment
comment|/*#define	EPIC_USEIOSPACE	1*/
end_comment

begin_define
define|#
directive|define
name|EARLY_RX
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_MAX_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_MAX_LEN
value|1518
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_MIN_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_MIN_LEN
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_CRC_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_CRC_LEN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TX_RING_SIZE
value|16
end_define

begin_comment
comment|/* Leave this a power of 2 */
end_comment

begin_define
define|#
directive|define
name|RX_RING_SIZE
value|16
end_define

begin_comment
comment|/* And this too, to do not */
end_comment

begin_comment
comment|/* confuse RX(TX)_RING_MASK */
end_comment

begin_define
define|#
directive|define
name|TX_RING_MASK
value|(TX_RING_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|RX_RING_MASK
value|(RX_RING_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|ETHER_MAX_FRAME_LEN
value|(ETHER_MAX_LEN + ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|EPIC_MAX_MTU
value|1600
end_define

begin_comment
comment|/* This is experiment-derived value */
end_comment

begin_comment
comment|/* PCI aux configuration registers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|PCIR_BASEIO
value|(PCIR_MAPS + 0x0)
end_define

begin_comment
comment|/* Base IO Address */
end_comment

begin_define
define|#
directive|define
name|PCIR_BASEMEM
value|(PCIR_MAPS + 0x4)
end_define

begin_comment
comment|/* Base Memory Address */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_define
define|#
directive|define
name|PCI_BASEIO
value|(PCI_MAPS + 0x0)
end_define

begin_comment
comment|/* Base IO Address */
end_comment

begin_define
define|#
directive|define
name|PCI_BASEMEM
value|(PCI_MAPS + 0x4)
end_define

begin_comment
comment|/* Base Memory Address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_comment
comment|/* PCI identification */
end_comment

begin_define
define|#
directive|define
name|SMC_VENDORID
value|0x10B8
end_define

begin_define
define|#
directive|define
name|SMC_DEVICEID_83C170
value|0x0005
end_define

begin_comment
comment|/* EPIC's registers */
end_comment

begin_define
define|#
directive|define
name|COMMAND
value|0x0000
end_define

begin_define
define|#
directive|define
name|INTSTAT
value|0x0004
end_define

begin_comment
comment|/* Interrupt status. See below */
end_comment

begin_define
define|#
directive|define
name|INTMASK
value|0x0008
end_define

begin_comment
comment|/* Interrupt mask. See below */
end_comment

begin_define
define|#
directive|define
name|GENCTL
value|0x000C
end_define

begin_define
define|#
directive|define
name|NVCTL
value|0x0010
end_define

begin_define
define|#
directive|define
name|EECTL
value|0x0014
end_define

begin_comment
comment|/* EEPROM control **/
end_comment

begin_define
define|#
directive|define
name|TEST1
value|0x001C
end_define

begin_comment
comment|/* XXXXX */
end_comment

begin_define
define|#
directive|define
name|CRCCNT
value|0x0020
end_define

begin_comment
comment|/* CRC error counter */
end_comment

begin_define
define|#
directive|define
name|ALICNT
value|0x0024
end_define

begin_comment
comment|/* FrameTooLang error counter */
end_comment

begin_define
define|#
directive|define
name|MPCNT
value|0x0028
end_define

begin_comment
comment|/* MissedFrames error counters */
end_comment

begin_define
define|#
directive|define
name|MIICTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|MIIDATA
value|0x0034
end_define

begin_define
define|#
directive|define
name|MIICFG
value|0x0038
end_define

begin_define
define|#
directive|define
name|IPG
value|0x003C
end_define

begin_define
define|#
directive|define
name|LAN0
value|0x0040
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_define
define|#
directive|define
name|LAN1
value|0x0044
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_define
define|#
directive|define
name|LAN2
value|0x0048
end_define

begin_comment
comment|/* MAC address */
end_comment

begin_define
define|#
directive|define
name|ID_CHK
value|0x004C
end_define

begin_define
define|#
directive|define
name|MC0
value|0x0050
end_define

begin_comment
comment|/* Multicast filter table */
end_comment

begin_define
define|#
directive|define
name|MC1
value|0x0054
end_define

begin_comment
comment|/* Multicast filter table */
end_comment

begin_define
define|#
directive|define
name|MC2
value|0x0058
end_define

begin_comment
comment|/* Multicast filter table */
end_comment

begin_define
define|#
directive|define
name|MC3
value|0x005C
end_define

begin_comment
comment|/* Multicast filter table */
end_comment

begin_define
define|#
directive|define
name|RXCON
value|0x0060
end_define

begin_comment
comment|/* Rx control register */
end_comment

begin_define
define|#
directive|define
name|TXCON
value|0x0070
end_define

begin_comment
comment|/* Tx control register */
end_comment

begin_define
define|#
directive|define
name|TXSTAT
value|0x0074
end_define

begin_define
define|#
directive|define
name|PRCDAR
value|0x0084
end_define

begin_comment
comment|/* RxRing bus address */
end_comment

begin_define
define|#
directive|define
name|PRSTAT
value|0x00A4
end_define

begin_define
define|#
directive|define
name|PRCPTHR
value|0x00B0
end_define

begin_define
define|#
directive|define
name|PTCDAR
value|0x00C4
end_define

begin_comment
comment|/* TxRing bus address */
end_comment

begin_define
define|#
directive|define
name|ETXTHR
value|0x00DC
end_define

begin_define
define|#
directive|define
name|COMMAND_STOP_RX
value|0x01
end_define

begin_define
define|#
directive|define
name|COMMAND_START_RX
value|0x02
end_define

begin_define
define|#
directive|define
name|COMMAND_TXQUEUED
value|0x04
end_define

begin_define
define|#
directive|define
name|COMMAND_RXQUEUED
value|0x08
end_define

begin_define
define|#
directive|define
name|COMMAND_NEXTFRAME
value|0x10
end_define

begin_define
define|#
directive|define
name|COMMAND_STOP_TDMA
value|0x20
end_define

begin_define
define|#
directive|define
name|COMMAND_STOP_RDMA
value|0x40
end_define

begin_define
define|#
directive|define
name|COMMAND_TXUGO
value|0x80
end_define

begin_comment
comment|/* Interrupt register bits */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_RCC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|INTSTAT_HCC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|INTSTAT_RQE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|INTSTAT_OVW
value|0x00000008
end_define

begin_define
define|#
directive|define
name|INTSTAT_RXE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|INTSTAT_TXC
value|0x00000020
end_define

begin_define
define|#
directive|define
name|INTSTAT_TCC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|INTSTAT_TQE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|INTSTAT_TXU
value|0x00000100
end_define

begin_define
define|#
directive|define
name|INTSTAT_CNT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|INTSTAT_PREI
value|0x00000400
end_define

begin_define
define|#
directive|define
name|INTSTAT_RCT
value|0x00000800
end_define

begin_define
define|#
directive|define
name|INTSTAT_FATAL
value|0x00001000
end_define

begin_comment
comment|/* One of DPE,APE,PMA,PTA happend */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_UNUSED1
value|0x00002000
end_define

begin_define
define|#
directive|define
name|INTSTAT_UNUSED2
value|0x00004000
end_define

begin_define
define|#
directive|define
name|INTSTAT_GP2
value|0x00008000
end_define

begin_comment
comment|/* PHY Event */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_INT_ACTV
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INTSTAT_RXIDLE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|INTSTAT_TXIDLE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INTSTAT_RCIP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|INTSTAT_TCIP
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INTSTAT_RBE
value|0x00200000
end_define

begin_define
define|#
directive|define
name|INTSTAT_RCTS
value|0x00400000
end_define

begin_define
define|#
directive|define
name|INTSTAT_RSV
value|0x00800000
end_define

begin_define
define|#
directive|define
name|INTSTAT_DPE
value|0x01000000
end_define

begin_comment
comment|/* PCI Fatal error */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_APE
value|0x02000000
end_define

begin_comment
comment|/* PCI Fatal error */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_PMA
value|0x04000000
end_define

begin_comment
comment|/* PCI Fatal error */
end_comment

begin_define
define|#
directive|define
name|INTSTAT_PTA
value|0x08000000
end_define

begin_comment
comment|/* PCI Fatal error */
end_comment

begin_define
define|#
directive|define
name|GENCTL_SOFT_RESET
value|0x00000001
end_define

begin_define
define|#
directive|define
name|GENCTL_ENABLE_INTERRUPT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|GENCTL_SOFTWARE_INTERRUPT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|GENCTL_POWER_DOWN
value|0x00000008
end_define

begin_define
define|#
directive|define
name|GENCTL_ONECOPY
value|0x00000010
end_define

begin_define
define|#
directive|define
name|GENCTL_BIG_ENDIAN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|GENCTL_RECEIVE_DMA_PRIORITY
value|0x00000040
end_define

begin_define
define|#
directive|define
name|GENCTL_TRANSMIT_DMA_PRIORITY
value|0x00000080
end_define

begin_define
define|#
directive|define
name|GENCTL_RECEIVE_FIFO_THRESHOLD128
value|0x00000300
end_define

begin_define
define|#
directive|define
name|GENCTL_RECEIVE_FIFO_THRESHOLD96
value|0x00000200
end_define

begin_define
define|#
directive|define
name|GENCTL_RECEIVE_FIFO_THRESHOLD64
value|0x00000100
end_define

begin_define
define|#
directive|define
name|GENCTL_RECEIVE_FIFO_THRESHOLD32
value|0x00000000
end_define

begin_define
define|#
directive|define
name|GENCTL_MEMORY_READ_LINE
value|0x00000400
end_define

begin_define
define|#
directive|define
name|GENCTL_MEMORY_READ_MULTIPLE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|GENCTL_SOFTWARE1
value|0x00001000
end_define

begin_define
define|#
directive|define
name|GENCTL_SOFTWARE2
value|0x00002000
end_define

begin_define
define|#
directive|define
name|GENCTL_RESET_PHY
value|0x00004000
end_define

begin_define
define|#
directive|define
name|NVCTL_ENABLE_MEMORY_MAP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|NVCTL_CLOCK_RUN_SUPPORTED
value|0x00000002
end_define

begin_define
define|#
directive|define
name|NVCTL_GP1_OUTPUT_ENABLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|NVCTL_GP2_OUTPUT_ENABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|NVCTL_GP1
value|0x00000010
end_define

begin_define
define|#
directive|define
name|NVCTL_GP2
value|0x00000020
end_define

begin_define
define|#
directive|define
name|NVCTL_CARDBUS_MODE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|NVCTL_IPG_DELAY_MASK
parameter_list|(
name|x
parameter_list|)
value|((x&0xF)<<7)
end_define

begin_define
define|#
directive|define
name|RXCON_SAVE_ERRORED_PACKETS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RXCON_RECEIVE_RUNT_FRAMES
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RXCON_RECEIVE_BROADCAST_FRAMES
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RXCON_RECEIVE_MULTICAST_FRAMES
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RXCON_RECEIVE_INVERSE_INDIVIDUAL_ADDRESS_FRAMES
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RXCON_PROMISCUOUS_MODE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RXCON_MONITOR_MODE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RXCON_EARLY_RECEIVE_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RXCON_EXTERNAL_BUFFER_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RXCON_EXTERNAL_BUFFER_16K
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RXCON_EXTERNAL_BUFFER_32K
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RXCON_EXTERNAL_BUFFER_128K
value|0x00000300
end_define

begin_define
define|#
directive|define
name|TXCON_EARLY_TRANSMIT_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TXCON_LOOPBACK_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|TXCON_LOOPBACK_MODE_INT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|TXCON_LOOPBACK_MODE_PHY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|TXCON_LOOPBACK_MODE
value|0x00000006
end_define

begin_define
define|#
directive|define
name|TXCON_FULL_DUPLEX
value|0x00000006
end_define

begin_define
define|#
directive|define
name|TXCON_SLOT_TIME
value|0x00000078
end_define

begin_define
define|#
directive|define
name|MIICFG_SERIAL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MIICFG_694_ENABLE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|MIICFG_694_STATUS
value|0x00000004
end_define

begin_define
define|#
directive|define
name|MIICFG_PHY_PRESENT
value|0x00000008
end_define

begin_define
define|#
directive|define
name|MIICFG_SMI_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|TEST1_CLOCK_TEST
value|0x00000008
end_define

begin_comment
comment|/*  * Some default values  */
end_comment

begin_define
define|#
directive|define
name|TXCON_DEFAULT
value|(TXCON_SLOT_TIME | TXCON_EARLY_TRANSMIT_ENABLE)
end_define

begin_define
define|#
directive|define
name|TRANSMIT_THRESHOLD
value|0x300
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EARLY_RX
argument_list|)
end_if

begin_define
define|#
directive|define
name|RXCON_EARLY
value|(RXCON_EARLY_RECEIVE_ENABLE | \ 				 RXCON_SAVE_ERRORED_PACKETS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RXCON_EARLY
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|RXCON_DEFAULT
value|(RXCON_EARLY | \ 				 RXCON_RECEIVE_MULTICAST_FRAMES | \ 				 RXCON_RECEIVE_BROADCAST_FRAMES)
end_define

begin_comment
comment|/*  * EEPROM structure  * SMC9432* eeprom is organized by words and only first 8 words  * have distinctive meaning (according to datasheet)  */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MAC0
value|0x0000
end_define

begin_comment
comment|/* Byte 0 / Byte 1 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MAC1
value|0x0001
end_define

begin_comment
comment|/* Byte 2 / Byte 3 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_MAC2
value|0x0002
end_define

begin_comment
comment|/* Byte 4 / Byte 5 */
end_comment

begin_define
define|#
directive|define
name|EEPROM_BID_CSUM
value|0x0003
end_define

begin_comment
comment|/* Board Id / Check Sum */
end_comment

begin_define
define|#
directive|define
name|EEPROM_NVCTL
value|0x0004
end_define

begin_comment
comment|/* NVCTL (bits 0-5) / nothing */
end_comment

begin_define
define|#
directive|define
name|EEPROM_PCI_MGD_MLD
value|0x0005
end_define

begin_comment
comment|/* PCI MinGrant / MaxLatency. Desired */
end_comment

begin_define
define|#
directive|define
name|EEPROM_SSVENDID
value|0x0006
end_define

begin_comment
comment|/* Subsystem Vendor Id */
end_comment

begin_define
define|#
directive|define
name|EEPROM_SSID
value|0x0006
end_define

begin_comment
comment|/* Subsystem Id */
end_comment

begin_comment
comment|/*  * Structures definition and Functions prototypes  */
end_comment

begin_comment
comment|/* EPIC's hardware descriptors, must be aligned on dword in memory */
end_comment

begin_comment
comment|/* NB: to make driver happy, this two structures MUST have thier sizes */
end_comment

begin_comment
comment|/* be divisor of PAGE_SIZE */
end_comment

begin_struct
struct|struct
name|epic_tx_desc
block|{
specifier|volatile
name|u_int16_t
name|status
decl_stmt|;
specifier|volatile
name|u_int16_t
name|txlength
decl_stmt|;
specifier|volatile
name|u_int32_t
name|bufaddr
decl_stmt|;
specifier|volatile
name|u_int16_t
name|buflength
decl_stmt|;
specifier|volatile
name|u_int16_t
name|control
decl_stmt|;
specifier|volatile
name|u_int32_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epic_rx_desc
block|{
specifier|volatile
name|u_int16_t
name|status
decl_stmt|;
specifier|volatile
name|u_int16_t
name|rxlength
decl_stmt|;
specifier|volatile
name|u_int32_t
name|bufaddr
decl_stmt|;
specifier|volatile
name|u_int32_t
name|buflength
decl_stmt|;
specifier|volatile
name|u_int32_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure defines EPIC's fragment list, maximum number of frags */
end_comment

begin_comment
comment|/* is 63. Let use maximum, becouse size of struct MUST be divisor of */
end_comment

begin_comment
comment|/* PAGE_SIZE, and sometimes come mbufs with more then 30 frags */
end_comment

begin_define
define|#
directive|define
name|EPIC_MAX_FRAGS
value|63
end_define

begin_struct
struct|struct
name|epic_frag_list
block|{
specifier|volatile
name|u_int32_t
name|numfrags
decl_stmt|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|fragaddr
decl_stmt|;
specifier|volatile
name|u_int32_t
name|fraglen
decl_stmt|;
block|}
name|frag
index|[
name|EPIC_MAX_FRAGS
index|]
struct|;
specifier|volatile
name|u_int32_t
name|pad
decl_stmt|;
comment|/* align on 256 bytes */
block|}
struct|;
end_struct

begin_comment
comment|/* This is driver's structure to define EPIC descriptors */
end_comment

begin_struct
struct|struct
name|epic_rx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* mbuf receiving packet */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epic_tx_buffer
block|{
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* mbuf contained packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * NB: ALIGN OF ABOVE STRUCTURES  * epic_rx_desc, epic_tx_desc, epic_frag_list - must be aligned on dword  */
end_comment

begin_comment
comment|/* PHY, known by tx driver */
end_comment

begin_define
define|#
directive|define
name|EPIC_UNKN_PHY
value|0x0000
end_define

begin_define
define|#
directive|define
name|EPIC_QS6612_PHY
value|0x0001
end_define

begin_define
define|#
directive|define
name|EPIC_AC101_PHY
value|0x0002
end_define

begin_define
define|#
directive|define
name|EPIC_LXT970_PHY
value|0x0003
end_define

begin_define
define|#
directive|define
name|EPIC_SERIAL
value|0x0004
end_define

begin_define
define|#
directive|define
name|SMC9432DMT
value|0xA010
end_define

begin_define
define|#
directive|define
name|SMC9432TX
value|0xA011
end_define

begin_define
define|#
directive|define
name|SMC9032TXM
value|0xA012
end_define

begin_define
define|#
directive|define
name|SMC9032TX
value|0xA013
end_define

begin_define
define|#
directive|define
name|SMC9432TXPWR
value|0xA014
end_define

begin_define
define|#
directive|define
name|SMC9432BTX
value|0xA015
end_define

begin_define
define|#
directive|define
name|SMC9432FTX
value|0xA016
end_define

begin_define
define|#
directive|define
name|SMC9432FTX_SC
value|0xA017
end_define

begin_define
define|#
directive|define
name|SMC9432TX_XG_ADHOC
value|0xA020
end_define

begin_define
define|#
directive|define
name|SMC9434TX_XG_ADHOC
value|0xA021
end_define

begin_define
define|#
directive|define
name|SMC9432FTX_ADHOC
value|0xA022
end_define

begin_define
define|#
directive|define
name|SMC9432BTX1
value|0xA024
end_define

begin_comment
comment|/* Driver status structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
name|mii_data_t
name|sc_mii
decl_stmt|;
name|struct
name|device
name|dev
decl_stmt|;
else|#
directive|else
comment|/* __FreeBSD__ */
name|struct
name|resource
modifier|*
name|res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|device_t
name|miibus
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|struct
name|callout_handle
name|stat_ch
decl_stmt|;
name|u_int32_t
name|unit
decl_stmt|;
endif|#
directive|endif
name|void
modifier|*
name|sc_ih
decl_stmt|;
name|bus_space_tag_t
name|sc_st
decl_stmt|;
name|bus_space_handle_t
name|sc_sh
decl_stmt|;
name|struct
name|epic_rx_buffer
name|rx_buffer
index|[
name|RX_RING_SIZE
index|]
decl_stmt|;
name|struct
name|epic_tx_buffer
name|tx_buffer
index|[
name|TX_RING_SIZE
index|]
decl_stmt|;
comment|/* Each element of array MUST be aligned on dword  */
comment|/* and bounded on PAGE_SIZE 			   */
name|struct
name|epic_rx_desc
modifier|*
name|rx_desc
decl_stmt|;
name|struct
name|epic_tx_desc
modifier|*
name|tx_desc
decl_stmt|;
name|struct
name|epic_frag_list
modifier|*
name|tx_flist
decl_stmt|;
name|u_int32_t
name|flags
decl_stmt|;
name|u_int32_t
name|tx_threshold
decl_stmt|;
name|u_int32_t
name|txcon
decl_stmt|;
name|u_int32_t
name|miicfg
decl_stmt|;
name|u_int32_t
name|cur_tx
decl_stmt|;
name|u_int32_t
name|cur_rx
decl_stmt|;
name|u_int32_t
name|dirty_tx
decl_stmt|;
name|u_int32_t
name|pending_txs
decl_stmt|;
name|u_int16_t
name|cardvend
decl_stmt|;
name|u_int16_t
name|cardid
decl_stmt|;
name|struct
name|mii_softc
modifier|*
name|physc
decl_stmt|;
name|u_int32_t
name|phyid
decl_stmt|;
name|int
name|serinst
decl_stmt|;
name|void
modifier|*
name|pool
decl_stmt|;
block|}
name|epic_softc_t
typedef|;
end_typedef

begin_struct
struct|struct
name|epic_type
block|{
name|u_int16_t
name|ven_id
decl_stmt|;
name|u_int16_t
name|dev_id
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EPIC_DEBUG
argument_list|)
end_if

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|a
parameter_list|)
value|printf a
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|dprintf
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|EPIC_FORMAT
value|"tx%d"
end_define

begin_define
define|#
directive|define
name|EPIC_ARGS
parameter_list|(
name|sc
parameter_list|)
value|(sc->unit)
end_define

begin_define
define|#
directive|define
name|EPIC_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|ifp
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __OpenBSD__ */
end_comment

begin_define
define|#
directive|define
name|EPIC_FORMAT
value|"%s"
end_define

begin_define
define|#
directive|define
name|EPIC_ARGS
parameter_list|(
name|sc
parameter_list|)
value|(sc->sc_dev.dv_xname)
end_define

begin_define
define|#
directive|define
name|EPIC_BPFTAP_ARG
parameter_list|(
name|ifp
parameter_list|)
value|(ifp)->if_bpf
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|sc_if
value|arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|sc_macaddr
value|arpcom.ac_enaddr
end_define

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
value|bus_space_write_4( (sc)->sc_st, (sc)->sc_sh, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_2( (sc)->sc_st, (sc)->sc_sh, (reg), (val) )
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_space_write_1( (sc)->sc_st, (sc)->sc_sh, (reg), (val) )
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
value|bus_space_read_4( (sc)->sc_st, (sc)->sc_sh, (reg) )
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2( (sc)->sc_st, (sc)->sc_sh, (reg) )
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_1( (sc)->sc_st, (sc)->sc_sh, (reg) )
end_define

begin_define
define|#
directive|define
name|PHY_READ_2
parameter_list|(
name|sc
parameter_list|,
name|phy
parameter_list|,
name|reg
parameter_list|)
define|\
value|epic_read_phy_reg((sc),(phy),(reg))
end_define

begin_define
define|#
directive|define
name|PHY_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|phy
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|epic_write_phy_reg((sc),(phy),(reg),(val))
end_define

begin_comment
comment|/* Macro to get either mbuf cluster or nothing */
end_comment

begin_define
define|#
directive|define
name|EPIC_MGETCLUSTER
parameter_list|(
name|m
parameter_list|)
define|\
value|{ MGETHDR((m),M_DONTWAIT,MT_DATA);				\ 	  if (m) {							\ 	    MCLGET((m),M_DONTWAIT);					\ 	    if( 0 == ((m)->m_flags& M_EXT) ) {				\ 	      m_freem(m);						\ 	      (m) = NULL;						\ 	    }								\ 	  }								\ 	}
end_define

end_unit

