begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************    Copyright (c) 2001-2007, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_E1000_REGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_E1000_REGS_H_
end_define

begin_define
define|#
directive|define
name|E1000_CTRL
value|0x00000
end_define

begin_comment
comment|/* Device Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_DUP
value|0x00004
end_define

begin_comment
comment|/* Device Control Duplicate (Shadow) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_STATUS
value|0x00008
end_define

begin_comment
comment|/* Device Status - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_EECD
value|0x00010
end_define

begin_comment
comment|/* EEPROM/Flash Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EERD
value|0x00014
end_define

begin_comment
comment|/* EEPROM Read - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CTRL_EXT
value|0x00018
end_define

begin_comment
comment|/* Extended Device Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FLA
value|0x0001C
end_define

begin_comment
comment|/* Flash Access - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MDIC
value|0x00020
end_define

begin_comment
comment|/* MDI Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_SCTL
value|0x00024
end_define

begin_comment
comment|/* SerDes Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCAL
value|0x00028
end_define

begin_comment
comment|/* Flow Control Address Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCAH
value|0x0002C
end_define

begin_comment
comment|/* Flow Control Address High -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FEXTNVM
value|0x00028
end_define

begin_comment
comment|/* Future Extended NVM - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCT
value|0x00030
end_define

begin_comment
comment|/* Flow Control Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CONNSW
value|0x00034
end_define

begin_comment
comment|/* Copper/Fiber switch control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VET
value|0x00038
end_define

begin_comment
comment|/* VLAN Ether Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR
value|0x000C0
end_define

begin_comment
comment|/* Interrupt Cause Read - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ITR
value|0x000C4
end_define

begin_comment
comment|/* Interrupt Throttling Rate - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS
value|0x000C8
end_define

begin_comment
comment|/* Interrupt Cause Set - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS
value|0x000D0
end_define

begin_comment
comment|/* Interrupt Mask Set - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC
value|0x000D8
end_define

begin_comment
comment|/* Interrupt Mask Clear - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_IAM
value|0x000E0
end_define

begin_comment
comment|/* Interrupt Acknowledge Auto Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RCTL
value|0x00100
end_define

begin_comment
comment|/* RX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCTTV
value|0x00170
end_define

begin_comment
comment|/* Flow Control Transmit Timer Value - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXCW
value|0x00178
end_define

begin_comment
comment|/* TX Configuration Word - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW
value|0x00180
end_define

begin_comment
comment|/* RX Configuration Word - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_EICR
value|0x01580
end_define

begin_comment
comment|/* Ext. Interrupt Cause Read - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_EITR
parameter_list|(
name|_n
parameter_list|)
value|(0x01680 + (0x4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_EICS
value|0x01520
end_define

begin_comment
comment|/* Ext. Interrupt Cause Set - W0 */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMS
value|0x01524
end_define

begin_comment
comment|/* Ext. Interrupt Mask Set/Read - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EIMC
value|0x01528
end_define

begin_comment
comment|/* Ext. Interrupt Mask Clear - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_EIAC
value|0x0152C
end_define

begin_comment
comment|/* Ext. Interrupt Auto Clear - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EIAM
value|0x01530
end_define

begin_comment
comment|/* Ext. Interrupt Ack Auto Clear Mask - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL
value|0x00400
end_define

begin_comment
comment|/* TX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EXT
value|0x00404
end_define

begin_comment
comment|/* Extended TX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIPG
value|0x00410
end_define

begin_comment
comment|/* TX Inter-packet gap -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TBT
value|0x00448
end_define

begin_comment
comment|/* TX Burst Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_AIT
value|0x00458
end_define

begin_comment
comment|/* Adaptive Interframe Spacing Throttle - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LEDCTL
value|0x00E00
end_define

begin_comment
comment|/* LED Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_EXTCNF_CTRL
value|0x00F00
end_define

begin_comment
comment|/* Extended Configuration Control */
end_comment

begin_define
define|#
directive|define
name|E1000_EXTCNF_SIZE
value|0x00F08
end_define

begin_comment
comment|/* Extended Configuration Size */
end_comment

begin_define
define|#
directive|define
name|E1000_PHY_CTRL
value|0x00F10
end_define

begin_comment
comment|/* PHY Control Register in CSR */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA
value|0x01000
end_define

begin_comment
comment|/* Packet Buffer Allocation - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PBS
value|0x01008
end_define

begin_comment
comment|/* Packet Buffer Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EEMNGCTL
value|0x01010
end_define

begin_comment
comment|/* MNG EEprom Control */
end_comment

begin_define
define|#
directive|define
name|E1000_EEARBC
value|0x01024
end_define

begin_comment
comment|/* EEPROM Auto Read Bus Control */
end_comment

begin_define
define|#
directive|define
name|E1000_FLASHT
value|0x01028
end_define

begin_comment
comment|/* FLASH Timer Register */
end_comment

begin_define
define|#
directive|define
name|E1000_EEWR
value|0x0102C
end_define

begin_comment
comment|/* EEPROM Write Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWCTL
value|0x01030
end_define

begin_comment
comment|/* FLASH control register */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWDATA
value|0x01034
end_define

begin_comment
comment|/* FLASH data register */
end_comment

begin_define
define|#
directive|define
name|E1000_FLSWCNT
value|0x01038
end_define

begin_comment
comment|/* FLASH Access Counter */
end_comment

begin_define
define|#
directive|define
name|E1000_FLOP
value|0x0103C
end_define

begin_comment
comment|/* FLASH Opcode Register */
end_comment

begin_define
define|#
directive|define
name|E1000_I2CCMD
value|0x01028
end_define

begin_comment
comment|/* SFPI2C Command Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_I2CPARAMS
value|0x0102C
end_define

begin_comment
comment|/* SFPI2C Parameters Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WDSTP
value|0x01040
end_define

begin_comment
comment|/* Watchdog Setup - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_SWDSTS
value|0x01044
end_define

begin_comment
comment|/* SW Device Status - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FRTIMER
value|0x01048
end_define

begin_comment
comment|/* Free Running Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TCPTIMER
value|0x0104C
end_define

begin_comment
comment|/* TCP Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ERT
value|0x02008
end_define

begin_comment
comment|/* Early Rx Threshold - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTL
value|0x02160
end_define

begin_comment
comment|/* Flow Control Receive Threshold Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTH
value|0x02168
end_define

begin_comment
comment|/* Flow Control Receive Threshold High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRCTL
value|0x02170
end_define

begin_comment
comment|/* Packet Split Receive Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDFPCQ
parameter_list|(
name|_n
parameter_list|)
value|(0x02430 + (0x4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_PBRTH
value|0x02458
end_define

begin_comment
comment|/* PB RX Arbitration Threshold - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTV
value|0x02460
end_define

begin_comment
comment|/* Flow Control Refresh Timer Value - RW */
end_comment

begin_comment
comment|/* Split and Replication RX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUMB
value|0x025CC
end_define

begin_comment
comment|/* DMA RX Descriptor uC Mailbox - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUAD
value|0x025D0
end_define

begin_comment
comment|/* DMA RX Descriptor uC Addr Command - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUWD
value|0x025D4
end_define

begin_comment
comment|/* DMA RX Descriptor uC Data Write - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPURD
value|0x025D8
end_define

begin_comment
comment|/* DMA RX Descriptor uC Data Read - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUCTL
value|0x025DC
end_define

begin_comment
comment|/* DMA RX Descriptor uC Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDTR
value|0x02820
end_define

begin_comment
comment|/* RX Delay Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RADV
value|0x0282C
end_define

begin_comment
comment|/* RX Interrupt Absolute Delay Timer - RW */
end_comment

begin_comment
comment|/*  * Convenience macros  *  * Note: "_n" is the queue number of the register to be written to.  *  * Example usage:  * E1000_RDBAL_REG(current_rx_queue)  */
end_comment

begin_define
define|#
directive|define
name|E1000_RDBAL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02800 + ((_n) * 0x100)) : (0x0C000 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02804 + ((_n) * 0x100)) : (0x0C004 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDLEN
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02808 + ((_n) * 0x100)) : (0x0C008 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x0280C + ((_n) * 0x100)) : (0x0C00C + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02810 + ((_n) * 0x100)) : (0x0C010 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDT
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02818 + ((_n) * 0x100)) : (0x0C018 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RXDCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02828 + ((_n) * 0x100)) : (0x0C028 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDBAL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03800 + ((_n) * 0x100)) : (0x0E000 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03804 + ((_n) * 0x100)) : (0x0E004 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDLEN
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03808 + ((_n) * 0x100)) : (0x0E008 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03810 + ((_n) * 0x100)) : (0x0E010 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDT
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03818 + ((_n) * 0x100)) : (0x0E018 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TXDCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03828 + ((_n) * 0x100)) : (0x0E028 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TARC
parameter_list|(
name|_n
parameter_list|)
value|(0x03840 + (_n<< 8))
end_define

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL
parameter_list|(
name|_n
parameter_list|)
value|(0x03814 + (_n<< 8))
end_define

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL
parameter_list|(
name|_n
parameter_list|)
value|(0x02814 + (_n<< 8))
end_define

begin_define
define|#
directive|define
name|E1000_TDWBAL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03838 + ((_n) * 0x100)) : (0x0E038 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDWBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x0383C + ((_n) * 0x100)) : (0x0E03C + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RSRPD
value|0x02C00
end_define

begin_comment
comment|/* RX Small Packet Detect - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RAID
value|0x02C08
end_define

begin_comment
comment|/* Receive Ack Interrupt Delay - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TXDMAC
value|0x03000
end_define

begin_comment
comment|/* TX DMA Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_KABGTXD
value|0x03004
end_define

begin_comment
comment|/* AFE Band Gap Transmit Ref Data */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFH
value|0x03410
end_define

begin_comment
comment|/* TX Data FIFO Head - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFT
value|0x03418
end_define

begin_comment
comment|/* TX Data FIFO Tail - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFHS
value|0x03420
end_define

begin_comment
comment|/* TX Data FIFO Head Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFTS
value|0x03428
end_define

begin_comment
comment|/* TX Data FIFO Tail Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFPC
value|0x03430
end_define

begin_comment
comment|/* TX Data FIFO Packet Count - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUMB
value|0x0357C
end_define

begin_comment
comment|/* DMA TX Descriptor uC Mail Box - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUAD
value|0x03580
end_define

begin_comment
comment|/* DMA TX Descriptor uC Addr Command - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUWD
value|0x03584
end_define

begin_comment
comment|/* DMA TX Descriptor uC Data Write - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPURD
value|0x03588
end_define

begin_comment
comment|/* DMA TX Descriptor uC Data  Read  - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUCTL
value|0x0358C
end_define

begin_comment
comment|/* DMA TX Descriptor uC Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXCTL
value|0x03590
end_define

begin_comment
comment|/* DMA TX Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIDV
value|0x03820
end_define

begin_comment
comment|/* TX Interrupt Delay Value - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TADV
value|0x0382C
end_define

begin_comment
comment|/* TX Interrupt Absolute Delay Val - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TSPMT
value|0x03830
end_define

begin_comment
comment|/* TCP Segmentation PAD& Min Threshold - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CRCERRS
value|0x04000
end_define

begin_comment
comment|/* CRC Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ALGNERRC
value|0x04004
end_define

begin_comment
comment|/* Alignment Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SYMERRS
value|0x04008
end_define

begin_comment
comment|/* Symbol Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RXERRC
value|0x0400C
end_define

begin_comment
comment|/* Receive Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPC
value|0x04010
end_define

begin_comment
comment|/* Missed Packet Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SCC
value|0x04014
end_define

begin_comment
comment|/* Single Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ECOL
value|0x04018
end_define

begin_comment
comment|/* Excessive Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MCC
value|0x0401C
end_define

begin_comment
comment|/* Multiple Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_LATECOL
value|0x04020
end_define

begin_comment
comment|/* Late Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_COLC
value|0x04028
end_define

begin_comment
comment|/* Collision Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_DC
value|0x04030
end_define

begin_comment
comment|/* Defer Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TNCRS
value|0x04034
end_define

begin_comment
comment|/* TX-No CRS - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_SEC
value|0x04038
end_define

begin_comment
comment|/* Sequence Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_CEXTERR
value|0x0403C
end_define

begin_comment
comment|/* Carrier Extension Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RLEC
value|0x04040
end_define

begin_comment
comment|/* Receive Length Error Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XONRXC
value|0x04048
end_define

begin_comment
comment|/* XON RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XONTXC
value|0x0404C
end_define

begin_comment
comment|/* XON TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFRXC
value|0x04050
end_define

begin_comment
comment|/* XOFF RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFTXC
value|0x04054
end_define

begin_comment
comment|/* XOFF TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRUC
value|0x04058
end_define

begin_comment
comment|/* Flow Control RX Unsupported Count- R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC64
value|0x0405C
end_define

begin_comment
comment|/* Packets RX (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC127
value|0x04060
end_define

begin_comment
comment|/* Packets RX (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC255
value|0x04064
end_define

begin_comment
comment|/* Packets RX (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC511
value|0x04068
end_define

begin_comment
comment|/* Packets RX (255-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1023
value|0x0406C
end_define

begin_comment
comment|/* Packets RX (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1522
value|0x04070
end_define

begin_comment
comment|/* Packets RX (1024-1522 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPRC
value|0x04074
end_define

begin_comment
comment|/* Good Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPRC
value|0x04078
end_define

begin_comment
comment|/* Broadcast Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPRC
value|0x0407C
end_define

begin_comment
comment|/* Multicast Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPTC
value|0x04080
end_define

begin_comment
comment|/* Good Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCL
value|0x04088
end_define

begin_comment
comment|/* Good Octets RX Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCH
value|0x0408C
end_define

begin_comment
comment|/* Good Octets RX Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCL
value|0x04090
end_define

begin_comment
comment|/* Good Octets TX Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCH
value|0x04094
end_define

begin_comment
comment|/* Good Octets TX Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RNBC
value|0x040A0
end_define

begin_comment
comment|/* RX No Buffers Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RUC
value|0x040A4
end_define

begin_comment
comment|/* RX Undersize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RFC
value|0x040A8
end_define

begin_comment
comment|/* RX Fragment Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ROC
value|0x040AC
end_define

begin_comment
comment|/* RX Oversize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RJC
value|0x040B0
end_define

begin_comment
comment|/* RX Jabber Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPRC
value|0x040B4
end_define

begin_comment
comment|/* Management Packets RX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPDC
value|0x040B8
end_define

begin_comment
comment|/* Management Packets Dropped Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPTC
value|0x040BC
end_define

begin_comment
comment|/* Management Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORL
value|0x040C0
end_define

begin_comment
comment|/* Total Octets RX Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORH
value|0x040C4
end_define

begin_comment
comment|/* Total Octets RX High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTL
value|0x040C8
end_define

begin_comment
comment|/* Total Octets TX Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTH
value|0x040CC
end_define

begin_comment
comment|/* Total Octets TX High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPR
value|0x040D0
end_define

begin_comment
comment|/* Total Packets RX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPT
value|0x040D4
end_define

begin_comment
comment|/* Total Packets TX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC64
value|0x040D8
end_define

begin_comment
comment|/* Packets TX (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC127
value|0x040DC
end_define

begin_comment
comment|/* Packets TX (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC255
value|0x040E0
end_define

begin_comment
comment|/* Packets TX (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC511
value|0x040E4
end_define

begin_comment
comment|/* Packets TX (256-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1023
value|0x040E8
end_define

begin_comment
comment|/* Packets TX (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1522
value|0x040EC
end_define

begin_comment
comment|/* Packets TX (1024-1522 Bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPTC
value|0x040F0
end_define

begin_comment
comment|/* Multicast Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPTC
value|0x040F4
end_define

begin_comment
comment|/* Broadcast Packets TX Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTC
value|0x040F8
end_define

begin_comment
comment|/* TCP Segmentation Context TX - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTFC
value|0x040FC
end_define

begin_comment
comment|/* TCP Segmentation Context TX Fail - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_IAC
value|0x04100
end_define

begin_comment
comment|/* Interrupt Assertion Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXPTC
value|0x04104
end_define

begin_comment
comment|/* Interrupt Cause Rx Packet Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXATC
value|0x04108
end_define

begin_comment
comment|/* Interrupt Cause Rx Absolute Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXPTC
value|0x0410C
end_define

begin_comment
comment|/* Interrupt Cause Tx Packet Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXATC
value|0x04110
end_define

begin_comment
comment|/* Interrupt Cause Tx Absolute Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXQEC
value|0x04118
end_define

begin_comment
comment|/* Interrupt Cause Tx Queue Empty Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXQMTC
value|0x0411C
end_define

begin_comment
comment|/* Interrupt Cause Tx Queue Minimum Threshold Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXDMTC
value|0x04120
end_define

begin_comment
comment|/* Interrupt Cause Rx Descriptor Minimum Threshold Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXOC
value|0x04124
end_define

begin_comment
comment|/* Interrupt Cause Receiver Overrun Count */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_CFG0
value|0x04200
end_define

begin_comment
comment|/* PCS Configuration 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_LCTL
value|0x04208
end_define

begin_comment
comment|/* PCS Link Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_LSTAT
value|0x0420C
end_define

begin_comment
comment|/* PCS Link Status - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_CBTMPC
value|0x0402C
end_define

begin_comment
comment|/* Circuit Breaker TX Packet Count */
end_comment

begin_define
define|#
directive|define
name|E1000_HTDPMC
value|0x0403C
end_define

begin_comment
comment|/* Host Transmit Discarded Packets */
end_comment

begin_define
define|#
directive|define
name|E1000_CBRDPC
value|0x04044
end_define

begin_comment
comment|/* Circuit Breaker RX Dropped Count */
end_comment

begin_define
define|#
directive|define
name|E1000_CBRMPC
value|0x040FC
end_define

begin_comment
comment|/* Circuit Breaker RX Packet Count */
end_comment

begin_define
define|#
directive|define
name|E1000_RPTHC
value|0x04104
end_define

begin_comment
comment|/* Rx Packets To Host */
end_comment

begin_define
define|#
directive|define
name|E1000_HGPTC
value|0x04118
end_define

begin_comment
comment|/* Host Good Packets TX Count */
end_comment

begin_define
define|#
directive|define
name|E1000_HTCBDPC
value|0x04124
end_define

begin_comment
comment|/* Host TX Circuit Breaker Dropped Count */
end_comment

begin_define
define|#
directive|define
name|E1000_HGORCL
value|0x04128
end_define

begin_comment
comment|/* Host Good Octets Received Count Low */
end_comment

begin_define
define|#
directive|define
name|E1000_HGORCH
value|0x0412C
end_define

begin_comment
comment|/* Host Good Octets Received Count High */
end_comment

begin_define
define|#
directive|define
name|E1000_HGOTCL
value|0x04130
end_define

begin_comment
comment|/* Host Good Octets Transmit Count Low */
end_comment

begin_define
define|#
directive|define
name|E1000_HGOTCH
value|0x04134
end_define

begin_comment
comment|/* Host Good Octets Transmit Count High */
end_comment

begin_define
define|#
directive|define
name|E1000_LENERRS
value|0x04138
end_define

begin_comment
comment|/* Length Errors Count */
end_comment

begin_define
define|#
directive|define
name|E1000_SCVPC
value|0x04228
end_define

begin_comment
comment|/* SerDes/SGMII Code Violation Pkt Count */
end_comment

begin_define
define|#
directive|define
name|E1000_HRMPC
value|0x0A018
end_define

begin_comment
comment|/* Header Redirection Missed Packet Count */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_ANADV
value|0x04218
end_define

begin_comment
comment|/* AN advertisement - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_LPAB
value|0x0421C
end_define

begin_comment
comment|/* Link Partner Ability - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_NPTX
value|0x04220
end_define

begin_comment
comment|/* AN Next Page Transmit - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PCS_LPABNP
value|0x04224
end_define

begin_comment
comment|/* Link Partner Ability Next Page - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_1GSTAT_RCV
value|0x04228
end_define

begin_comment
comment|/* 1GSTAT Code Violation Packet Count - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCSUM
value|0x05000
end_define

begin_comment
comment|/* RX Checksum Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RLPML
value|0x05004
end_define

begin_comment
comment|/* RX Long Packet Max Length */
end_comment

begin_define
define|#
directive|define
name|E1000_RFCTL
value|0x05008
end_define

begin_comment
comment|/* Receive Filter Control*/
end_comment

begin_define
define|#
directive|define
name|E1000_MTA
value|0x05200
end_define

begin_comment
comment|/* Multicast Table Array - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RA
value|0x05400
end_define

begin_comment
comment|/* Receive Address - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_PSRTYPE
value|0x05480
end_define

begin_comment
comment|/* Packet Split Receive Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VFTA
value|0x05600
end_define

begin_comment
comment|/* VLAN Filter Table Array - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_VMD_CTL
value|0x0581C
end_define

begin_comment
comment|/* VMDq Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VFQA0
value|0x0B000
end_define

begin_comment
comment|/* VLAN Filter Queue Array 0 - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_VFQA1
value|0x0B200
end_define

begin_comment
comment|/* VLAN Filter Queue Array 1 - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_WUC
value|0x05800
end_define

begin_comment
comment|/* Wakeup Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUFC
value|0x05808
end_define

begin_comment
comment|/* Wakeup Filter Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUS
value|0x05810
end_define

begin_comment
comment|/* Wakeup Status - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC
value|0x05820
end_define

begin_comment
comment|/* Management Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPAV
value|0x05838
end_define

begin_comment
comment|/* IP Address Valid - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IP4AT
value|0x05840
end_define

begin_comment
comment|/* IPv4 Address Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_IP6AT
value|0x05880
end_define

begin_comment
comment|/* IPv6 Address Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPL
value|0x05900
end_define

begin_comment
comment|/* Wakeup Packet Length - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_WUPM
value|0x05A00
end_define

begin_comment
comment|/* Wakeup Packet Memory - RO A */
end_comment

begin_define
define|#
directive|define
name|E1000_PBACL
value|0x05B68
end_define

begin_comment
comment|/* MSIx PBA Clear - Read/Write 1's to clear */
end_comment

begin_define
define|#
directive|define
name|E1000_FFLT
value|0x05F00
end_define

begin_comment
comment|/* Flexible Filter Length Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_HOST_IF
value|0x08800
end_define

begin_comment
comment|/* Host Interface */
end_comment

begin_define
define|#
directive|define
name|E1000_FFMT
value|0x09000
end_define

begin_comment
comment|/* Flexible Filter Mask Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_FFVT
value|0x09800
end_define

begin_comment
comment|/* Flexible Filter Value Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_KMRNCTRLSTA
value|0x00034
end_define

begin_comment
comment|/* MAC-PHY interface - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MDPHYA
value|0x0003C
end_define

begin_comment
comment|/* PHY address - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MANC2H
value|0x05860
end_define

begin_comment
comment|/* Management Control To Host - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_SW_FW_SYNC
value|0x05B5C
end_define

begin_comment
comment|/* Software-Firmware Synchronization - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_CCMCTL
value|0x05B48
end_define

begin_comment
comment|/* CCM Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_GIOCTL
value|0x05B44
end_define

begin_comment
comment|/* GIO Analog Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_SCCTL
value|0x05B4C
end_define

begin_comment
comment|/* PCIc PLL Configuration Register */
end_comment

begin_define
define|#
directive|define
name|E1000_GCR
value|0x05B00
end_define

begin_comment
comment|/* PCI-Ex Control */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_1
value|0x05B10
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #1 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_2
value|0x05B14
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #2 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_3
value|0x05B18
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #3 */
end_comment

begin_define
define|#
directive|define
name|E1000_GSCL_4
value|0x05B1C
end_define

begin_comment
comment|/* PCI-Ex Statistic Control #4 */
end_comment

begin_define
define|#
directive|define
name|E1000_FACTPS
value|0x05B30
end_define

begin_comment
comment|/* Function Active and Power State to MNG */
end_comment

begin_define
define|#
directive|define
name|E1000_SWSM
value|0x05B50
end_define

begin_comment
comment|/* SW Semaphore */
end_comment

begin_define
define|#
directive|define
name|E1000_FWSM
value|0x05B54
end_define

begin_comment
comment|/* FW Semaphore */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_ID
value|0x05B70
end_define

begin_comment
comment|/* DCA Requester ID Information - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_DCA_CTRL
value|0x05B74
end_define

begin_comment
comment|/* DCA Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_FFLT_DBG
value|0x05F04
end_define

begin_comment
comment|/* Debug Register */
end_comment

begin_define
define|#
directive|define
name|E1000_HICR
value|0x08F00
end_define

begin_comment
comment|/* Host Inteface Control */
end_comment

begin_comment
comment|/* RSS registers */
end_comment

begin_define
define|#
directive|define
name|E1000_CPUVEC
value|0x02C10
end_define

begin_comment
comment|/* CPU Vector Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MRQC
value|0x05818
end_define

begin_comment
comment|/* Multiple Receive Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIR
parameter_list|(
name|_i
parameter_list|)
value|(0x05A80 + ((_i) * 4))
end_define

begin_comment
comment|/* Immediate Interrupt */
end_comment

begin_define
define|#
directive|define
name|E1000_IMIREXT
parameter_list|(
name|_i
parameter_list|)
value|(0x05AA0 + ((_i) * 4))
end_define

begin_comment
comment|/* Immediate Interrupt Ext*/
end_comment

begin_define
define|#
directive|define
name|E1000_IMIRVP
value|0x05AC0
end_define

begin_comment
comment|/* Immediate Interrupt RX VLAN Priority - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXBM
parameter_list|(
name|_i
parameter_list|)
value|(0x01600 + ((_i) * 4))
end_define

begin_comment
comment|/* MSI-X Allocation Register (_i) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXTADD
parameter_list|(
name|_i
parameter_list|)
value|(0x0C000 + ((_i) * 0x10))
end_define

begin_comment
comment|/* MSI-X Table entry addr low reg 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXTUADD
parameter_list|(
name|_i
parameter_list|)
value|(0x0C004 + ((_i) * 0x10))
end_define

begin_comment
comment|/* MSI-X Table entry addr upper reg 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXTMSG
parameter_list|(
name|_i
parameter_list|)
value|(0x0C008 + ((_i) * 0x10))
end_define

begin_comment
comment|/* MSI-X Table entry message reg 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXVCTRL
parameter_list|(
name|_i
parameter_list|)
value|(0x0C00C + ((_i) * 0x10))
end_define

begin_comment
comment|/* MSI-X Table entry vector ctrl reg 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MSIXPBA
value|0x0E000
end_define

begin_comment
comment|/* MSI-X Pending bit array */
end_comment

begin_define
define|#
directive|define
name|E1000_RETA
parameter_list|(
name|_i
parameter_list|)
value|(0x05C00 + ((_i) * 4))
end_define

begin_comment
comment|/* Redirection Table - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSRK
parameter_list|(
name|_i
parameter_list|)
value|(0x05C80 + ((_i) * 4))
end_define

begin_comment
comment|/* RSS Random Key - RW Array */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSIM
value|0x05864
end_define

begin_comment
comment|/* RSS Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|E1000_RSSIR
value|0x05868
end_define

begin_comment
comment|/* RSS Interrupt Request */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

