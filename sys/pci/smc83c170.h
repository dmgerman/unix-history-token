begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Semen Ustimenko  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * stable-165  *  */
end_comment

begin_comment
comment|/*  * smc83c170.h  */
end_comment

begin_comment
comment|/*  * Configuration  */
end_comment

begin_define
define|#
directive|define
name|EPIC_MAX_DEVICES
value|4
end_define

begin_comment
comment|/*#define	RX_TO_MBUF	1*/
end_comment

begin_comment
comment|/* IT IS BUGGY */
end_comment

begin_comment
comment|/*#define	EPIC_DEBUG	1*/
end_comment

begin_define
define|#
directive|define
name|TX_RING_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|RX_RING_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|ETHER_MAX_FRAME_LEN
value|(ETHER_MAX_LEN + ETHER_CRC_LEN)
end_define

begin_comment
comment|/* Shall be moved to ../net/if_mib.h */
end_comment

begin_define
define|#
directive|define
name|dot3VendorSMC
value|8
end_define

begin_define
define|#
directive|define
name|dot3ChipSetSMC83c170
value|1
end_define

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
name|CHIPID_83C170
value|0x0005
end_define

begin_define
define|#
directive|define
name|PCI_VENDORID
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|PCI_CHIPID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_comment
comment|/* PCI configuration */
end_comment

begin_define
define|#
directive|define
name|PCI_CFID
value|0x00
end_define

begin_comment
comment|/* Configuration ID */
end_comment

begin_define
define|#
directive|define
name|PCI_CFCS
value|0x04
end_define

begin_comment
comment|/* Configurtion Command/Status */
end_comment

begin_define
define|#
directive|define
name|PCI_CFRV
value|0x08
end_define

begin_comment
comment|/* Configuration Revision */
end_comment

begin_define
define|#
directive|define
name|PCI_CFLT
value|0x0c
end_define

begin_comment
comment|/* Configuration Latency Timer */
end_comment

begin_define
define|#
directive|define
name|PCI_CBIO
value|0x10
end_define

begin_comment
comment|/* Configuration Base IO Address */
end_comment

begin_define
define|#
directive|define
name|PCI_CBMA
value|0x14
end_define

begin_comment
comment|/* Configuration Base Memory Address */
end_comment

begin_define
define|#
directive|define
name|PCI_CFIT
value|0x3c
end_define

begin_comment
comment|/* Configuration Interrupt */
end_comment

begin_define
define|#
directive|define
name|PCI_CFDA
value|0x40
end_define

begin_comment
comment|/* Configuration Driver Area */
end_comment

begin_define
define|#
directive|define
name|PCI_CONF_WRITE
parameter_list|(
name|r
parameter_list|,
name|v
parameter_list|)
value|pci_conf_write(config_id, (r), (v))
end_define

begin_define
define|#
directive|define
name|PCI_CONF_READ
parameter_list|(
name|r
parameter_list|)
value|pci_conf_read(config_id, (r))
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
comment|/* Tx threshold */
end_comment

begin_define
define|#
directive|define
name|TX_FIFO_THRESH
value|0x80
end_define

begin_comment
comment|/* 0x40 or 0x10 */
end_comment

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
name|TXCON_LOOPBACK_MODE_FULL_DUPLEX
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
name|TXCON_DEFAULT
value|(TXCON_SLOT_TIME|TXCON_EARLY_TRANSMIT_ENABLE)
end_define

begin_comment
comment|/*  * National Semiconductor's DP83840A Registers and bits  */
end_comment

begin_define
define|#
directive|define
name|DP83840_BMCR
value|0x00
end_define

begin_comment
comment|/* Control register */
end_comment

begin_define
define|#
directive|define
name|DP83840_BMSR
value|0x01
end_define

begin_comment
comment|/* Status rgister */
end_comment

begin_define
define|#
directive|define
name|DP83840_ANAR
value|0x04
end_define

begin_comment
comment|/* Autonegotiation advertising register */
end_comment

begin_define
define|#
directive|define
name|DP83840_PHYIDR1
value|0x02
end_define

begin_define
define|#
directive|define
name|DP83840_PHYIDR2
value|0x03
end_define

begin_define
define|#
directive|define
name|BMCR_RESET
value|0x8000
end_define

begin_define
define|#
directive|define
name|BMCR_100MBPS
value|0x2000
end_define

begin_comment
comment|/* 10/100 Mbps */
end_comment

begin_define
define|#
directive|define
name|BMCR_AUTONEGOTIATION
value|0x1000
end_define

begin_comment
comment|/* ON/OFF */
end_comment

begin_define
define|#
directive|define
name|BMCR_RESTART_AUTONEG
value|0x0200
end_define

begin_define
define|#
directive|define
name|BMCR_FULL_DUPLEX
value|0x0100
end_define

begin_define
define|#
directive|define
name|BMSR_100BASE_T4
value|0x8000
end_define

begin_define
define|#
directive|define
name|BMSR_100BASE_TX_FD
value|0x4000
end_define

begin_define
define|#
directive|define
name|BMSR_100BASE_TX
value|0x2000
end_define

begin_define
define|#
directive|define
name|BMSR_10BASE_T_FD
value|0x1000
end_define

begin_define
define|#
directive|define
name|BMSR_10BASE_T
value|0x0800
end_define

begin_define
define|#
directive|define
name|BMSR_AUTONEG_COMPLETE
value|0x0020
end_define

begin_define
define|#
directive|define
name|BMSR_AUTONEG_ABLE
value|0x0008
end_define

begin_define
define|#
directive|define
name|BMSR_LINK_STATUS
value|0x0004
end_define

begin_define
define|#
directive|define
name|ANAR_10
value|0x0020
end_define

begin_define
define|#
directive|define
name|ANAR_10_FD
value|0x0040
end_define

begin_define
define|#
directive|define
name|ANAR_100
value|0x0080
end_define

begin_define
define|#
directive|define
name|ANAR_100_FD
value|0x0100
end_define

begin_comment
comment|/*  * Structures definition and Functions prototypes  */
end_comment

begin_comment
comment|/* EPIC's descriptors */
end_comment

begin_struct
struct|struct
name|epic_tx_desc
block|{
name|u_int16_t
name|status
decl_stmt|;
name|u_int16_t
name|txlength
decl_stmt|;
name|u_int32_t
name|bufaddr
decl_stmt|;
name|u_int16_t
name|buflength
decl_stmt|;
name|u_int16_t
name|control
decl_stmt|;
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
name|u_int16_t
name|status
decl_stmt|;
name|u_int16_t
name|rxlength
decl_stmt|;
name|u_int32_t
name|bufaddr
decl_stmt|;
name|u_int32_t
name|buflength
decl_stmt|;
name|u_int32_t
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epic_rx_buffer
block|{
name|struct
name|epic_rx_desc
name|desc
decl_stmt|;
comment|/* EPIC's descriptor */
name|caddr_t
name|data
decl_stmt|;
comment|/* Rx buffer address */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|RX_TO_MBUF
argument_list|)
name|caddr_t
name|pool
decl_stmt|;
comment|/* Pool, allocated for buffer */
else|#
directive|else
name|struct
name|mbuf
modifier|*
name|mbuf
decl_stmt|;
comment|/* Or mbuf structure */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|epic_tx_buffer
block|{
name|struct
name|epic_tx_desc
name|desc
decl_stmt|;
comment|/* EPIC's descriptor */
name|caddr_t
name|data
decl_stmt|;
comment|/* Tx buffer address */
name|caddr_t
name|pool
decl_stmt|;
comment|/* Pool, allocated for buffer */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|unit
decl_stmt|;
name|struct
name|arpcom
name|epic_ac
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
name|u_int32_t
name|iobase
decl_stmt|;
name|u_int32_t
name|irq
decl_stmt|;
name|struct
name|ifmib_iso_8802_3
name|dot3stats
decl_stmt|;
block|}
name|epic_softc_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|epic_if
value|epic_ac.ac_if
end_define

begin_define
define|#
directive|define
name|epic_macaddr
value|epic_ac.ac_enaddr
end_define

begin_comment
comment|//extern epic_softc_t *epics[];
end_comment

begin_comment
comment|//extern u_long epic_pci_count;
end_comment

begin_function_decl
specifier|static
name|int
name|epic_ifioctl
parameter_list|(
specifier|register
name|struct
name|ifnet
modifier|*
parameter_list|,
name|int
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_intr_normal
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_rx_done
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_tx_done
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_ifstart
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_ifwatchdog
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|char
modifier|*
name|epic_pci_probe
parameter_list|(
name|pcici_t
parameter_list|,
name|pcidi_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_pci_attach
parameter_list|(
name|pcici_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_update_if_media_flags
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_init
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_stop
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_init_rings
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_set_rx_mode
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_set_mc_table
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_set_media_speed
parameter_list|(
name|epic_softc_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|epic_read_eeprom
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_output_eepromw
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int16_t
name|epic_input_eepromw
parameter_list|(
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int8_t
name|epic_eeprom_clock
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_write_eepromreg
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|u_int8_t
name|epic_read_eepromreg
parameter_list|(
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|epic_read_phy_register
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|epic_write_phy_register
parameter_list|(
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|,
name|u_int16_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

