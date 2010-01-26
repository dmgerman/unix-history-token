begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2010, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
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
name|E1000_MDICNFG
value|0x00E04
end_define

begin_comment
comment|/* MDI Config - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_REGISTER_SET_SIZE
value|0x20000
end_define

begin_comment
comment|/* CSR Size */
end_comment

begin_define
define|#
directive|define
name|E1000_EEPROM_INIT_CTRL_WORD_2
value|0x0F
end_define

begin_comment
comment|/* EEPROM Init Ctrl Word 2 */
end_comment

begin_define
define|#
directive|define
name|E1000_BARCTRL
value|0x5BBC
end_define

begin_comment
comment|/* BAR ctrl reg */
end_comment

begin_define
define|#
directive|define
name|E1000_BARCTRL_FLSIZE
value|0x0700
end_define

begin_comment
comment|/* BAR ctrl Flsize */
end_comment

begin_define
define|#
directive|define
name|E1000_BARCTRL_CSRSIZE
value|0x2000
end_define

begin_comment
comment|/* BAR ctrl CSR size */
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
name|E1000_FEXT
value|0x0002C
end_define

begin_comment
comment|/* Future Extended - RW */
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
name|E1000_IVAR
value|0x000E4
end_define

begin_comment
comment|/* Interrupt Vector Allocation Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_SVCR
value|0x000F0
end_define

begin_define
define|#
directive|define
name|E1000_SVT
value|0x000F4
end_define

begin_define
define|#
directive|define
name|E1000_RCTL
value|0x00100
end_define

begin_comment
comment|/* Rx Control - RW */
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
comment|/* Tx Configuration Word - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXCW
value|0x00180
end_define

begin_comment
comment|/* Rx Configuration Word - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_PBA_ECC
value|0x01100
end_define

begin_comment
comment|/* PBA ECC Register */
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
name|E1000_GPIE
value|0x01514
end_define

begin_comment
comment|/* General Purpose Interrupt Enable - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IVAR0
value|0x01700
end_define

begin_comment
comment|/* Interrupt Vector Allocation (array) - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IVAR_MISC
value|0x01740
end_define

begin_comment
comment|/* IVAR for "other" causes - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL
value|0x00400
end_define

begin_comment
comment|/* Tx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TCTL_EXT
value|0x00404
end_define

begin_comment
comment|/* Extended Tx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIPG
value|0x00410
end_define

begin_comment
comment|/* Tx Inter-packet gap -RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TBT
value|0x00448
end_define

begin_comment
comment|/* Tx Burst Timer - RW */
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
name|E1000_VPDDIAG
value|0x01060
end_define

begin_comment
comment|/* VPD Diagnostic - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_ICR_V2
value|0x01500
end_define

begin_comment
comment|/* Interrupt Cause - new location - RC */
end_comment

begin_define
define|#
directive|define
name|E1000_ICS_V2
value|0x01504
end_define

begin_comment
comment|/* Interrupt Cause Set - new location - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_IMS_V2
value|0x01508
end_define

begin_comment
comment|/* Interrupt Mask Set/Read - new location - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IMC_V2
value|0x0150C
end_define

begin_comment
comment|/* Interrupt Mask Clear - new location - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_IAM_V2
value|0x01510
end_define

begin_comment
comment|/* Interrupt Ack Auto Mask - new location - RW */
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
comment|/* PB Rx Arbitration Threshold - RW */
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
comment|/* Split and Replication Rx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUMB
value|0x025CC
end_define

begin_comment
comment|/* DMA Rx Descriptor uC Mailbox - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUAD
value|0x025D0
end_define

begin_comment
comment|/* DMA Rx Descriptor uC Addr Command - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUWD
value|0x025D4
end_define

begin_comment
comment|/* DMA Rx Descriptor uC Data Write - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPURD
value|0x025D8
end_define

begin_comment
comment|/* DMA Rx Descriptor uC Data Read - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDPUCTL
value|0x025DC
end_define

begin_comment
comment|/* DMA Rx Descriptor uC Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_PBDIAG
value|0x02458
end_define

begin_comment
comment|/* Packet Buffer Diagnostic - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXPBS
value|0x02404
end_define

begin_comment
comment|/* Rx Packet Buffer Size - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IRPBS
value|0x02404
end_define

begin_comment
comment|/* Same as RXPBS, renamed for newer adapters - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RDTR
value|0x02820
end_define

begin_comment
comment|/* Rx Delay Timer - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RADV
value|0x0282C
end_define

begin_comment
comment|/* Rx Interrupt Absolute Delay Timer - RW */
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
value|((_n)< 4 ? (0x02800 + ((_n) * 0x100)) : \                                          (0x0C000 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02804 + ((_n) * 0x100)) : \                                          (0x0C004 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDLEN
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02808 + ((_n) * 0x100)) : \                                          (0x0C008 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_SRRCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x0280C + ((_n) * 0x100)) : \                                          (0x0C00C + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RDH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02810 + ((_n) * 0x100)) : \                                          (0x0C010 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RXCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02814 + ((_n) * 0x100)) : \                                          (0x0C014 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_DCA_RXCTRL
parameter_list|(
name|_n
parameter_list|)
value|E1000_RXCTL(_n)
end_define

begin_define
define|#
directive|define
name|E1000_RDT
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02818 + ((_n) * 0x100)) : \                                          (0x0C018 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RXDCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02828 + ((_n) * 0x100)) : \                                          (0x0C028 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_RQDPC
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x02830 + ((_n) * 0x100)) : \                                          (0x0C030 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDBAL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03800 + ((_n) * 0x100)) : \                                          (0x0E000 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03804 + ((_n) * 0x100)) : \                                          (0x0E004 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDLEN
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03808 + ((_n) * 0x100)) : \                                          (0x0E008 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03810 + ((_n) * 0x100)) : \                                          (0x0E010 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TXCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03814 + ((_n) * 0x100)) : \                                          (0x0E014 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_DCA_TXCTRL
parameter_list|(
name|_n
parameter_list|)
value|E1000_TXCTL(_n)
end_define

begin_define
define|#
directive|define
name|E1000_TDT
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03818 + ((_n) * 0x100)) : \                                          (0x0E018 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TXDCTL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03828 + ((_n) * 0x100)) : \                                          (0x0E028 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDWBAL
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x03838 + ((_n) * 0x100)) : \                                          (0x0E038 + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TDWBAH
parameter_list|(
name|_n
parameter_list|)
value|((_n)< 4 ? (0x0383C + ((_n) * 0x100)) : \                                          (0x0E03C + ((_n) * 0x40)))
end_define

begin_define
define|#
directive|define
name|E1000_TARC
parameter_list|(
name|_n
parameter_list|)
value|(0x03840 + ((_n) * 0x100))
end_define

begin_define
define|#
directive|define
name|E1000_RSRPD
value|0x02C00
end_define

begin_comment
comment|/* Rx Small Packet Detect - RW */
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
comment|/* Tx DMA Control - RW */
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
name|E1000_PSRTYPE
parameter_list|(
name|_i
parameter_list|)
value|(0x05480 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|E1000_RAL
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x05400 + ((_i) * 8)) : \                                        (0x054E0 + ((_i - 16) * 8)))
end_define

begin_define
define|#
directive|define
name|E1000_RAH
parameter_list|(
name|_i
parameter_list|)
value|(((_i)<= 15) ? (0x05404 + ((_i) * 8)) : \                                        (0x054E4 + ((_i - 16) * 8)))
end_define

begin_define
define|#
directive|define
name|E1000_IP4AT_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x05840 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_IP6AT_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x05880 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|E1000_WUPM_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x05A00 + ((_i) * 4))
end_define

begin_define
define|#
directive|define
name|E1000_FFMT_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x09000 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_FFVT_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x09800 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_FFLT_REG
parameter_list|(
name|_i
parameter_list|)
value|(0x05F00 + ((_i) * 8))
end_define

begin_define
define|#
directive|define
name|E1000_PBSLAC
value|0x03100
end_define

begin_comment
comment|/* Packet Buffer Slave Access Control */
end_comment

begin_define
define|#
directive|define
name|E1000_PBSLAD
parameter_list|(
name|_n
parameter_list|)
value|(0x03110 + (0x4 * (_n)))
end_define

begin_comment
comment|/* Packet Buffer DWORD (_n) */
end_comment

begin_define
define|#
directive|define
name|E1000_TXPBS
value|0x03404
end_define

begin_comment
comment|/* Tx Packet Buffer Size - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_ITPBS
value|0x03404
end_define

begin_comment
comment|/* Same as TXPBS, renamed for newer adpaters - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFH
value|0x03410
end_define

begin_comment
comment|/* Tx Data FIFO Head - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFT
value|0x03418
end_define

begin_comment
comment|/* Tx Data FIFO Tail - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFHS
value|0x03420
end_define

begin_comment
comment|/* Tx Data FIFO Head Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFTS
value|0x03428
end_define

begin_comment
comment|/* Tx Data FIFO Tail Saved - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDFPC
value|0x03430
end_define

begin_comment
comment|/* Tx Data FIFO Packet Count - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUMB
value|0x0357C
end_define

begin_comment
comment|/* DMA Tx Descriptor uC Mail Box - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUAD
value|0x03580
end_define

begin_comment
comment|/* DMA Tx Descriptor uC Addr Command - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUWD
value|0x03584
end_define

begin_comment
comment|/* DMA Tx Descriptor uC Data Write - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPURD
value|0x03588
end_define

begin_comment
comment|/* DMA Tx Descriptor uC Data  Read  - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TDPUCTL
value|0x0358C
end_define

begin_comment
comment|/* DMA Tx Descriptor uC Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXCTL
value|0x03590
end_define

begin_comment
comment|/* DMA Tx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXTCPFLGL
value|0x0359C
end_define

begin_comment
comment|/* DMA Tx Control flag low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXTCPFLGH
value|0x035A0
end_define

begin_comment
comment|/* DMA Tx Control flag high - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXMXSZRQ
value|0x03540
end_define

begin_comment
comment|/* DMA Tx Max Total Allow Size Requests - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TIDV
value|0x03820
end_define

begin_comment
comment|/* Tx Interrupt Delay Value - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TADV
value|0x0382C
end_define

begin_comment
comment|/* Tx Interrupt Absolute Delay Val - RW */
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
comment|/* Tx-No CRS - R/clr */
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
comment|/* XON Rx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XONTXC
value|0x0404C
end_define

begin_comment
comment|/* XON Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFRXC
value|0x04050
end_define

begin_comment
comment|/* XOFF Rx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_XOFFTXC
value|0x04054
end_define

begin_comment
comment|/* XOFF Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRUC
value|0x04058
end_define

begin_comment
comment|/* Flow Control Rx Unsupported Count- R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC64
value|0x0405C
end_define

begin_comment
comment|/* Packets Rx (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC127
value|0x04060
end_define

begin_comment
comment|/* Packets Rx (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC255
value|0x04064
end_define

begin_comment
comment|/* Packets Rx (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC511
value|0x04068
end_define

begin_comment
comment|/* Packets Rx (255-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1023
value|0x0406C
end_define

begin_comment
comment|/* Packets Rx (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PRC1522
value|0x04070
end_define

begin_comment
comment|/* Packets Rx (1024-1522 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPRC
value|0x04074
end_define

begin_comment
comment|/* Good Packets Rx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPRC
value|0x04078
end_define

begin_comment
comment|/* Broadcast Packets Rx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPRC
value|0x0407C
end_define

begin_comment
comment|/* Multicast Packets Rx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GPTC
value|0x04080
end_define

begin_comment
comment|/* Good Packets Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCL
value|0x04088
end_define

begin_comment
comment|/* Good Octets Rx Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GORCH
value|0x0408C
end_define

begin_comment
comment|/* Good Octets Rx Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCL
value|0x04090
end_define

begin_comment
comment|/* Good Octets Tx Count Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_GOTCH
value|0x04094
end_define

begin_comment
comment|/* Good Octets Tx Count High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RNBC
value|0x040A0
end_define

begin_comment
comment|/* Rx No Buffers Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RUC
value|0x040A4
end_define

begin_comment
comment|/* Rx Undersize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RFC
value|0x040A8
end_define

begin_comment
comment|/* Rx Fragment Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_ROC
value|0x040AC
end_define

begin_comment
comment|/* Rx Oversize Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_RJC
value|0x040B0
end_define

begin_comment
comment|/* Rx Jabber Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MGTPRC
value|0x040B4
end_define

begin_comment
comment|/* Management Packets Rx Count - R/clr */
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
comment|/* Management Packets Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORL
value|0x040C0
end_define

begin_comment
comment|/* Total Octets Rx Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TORH
value|0x040C4
end_define

begin_comment
comment|/* Total Octets Rx High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTL
value|0x040C8
end_define

begin_comment
comment|/* Total Octets Tx Low - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TOTH
value|0x040CC
end_define

begin_comment
comment|/* Total Octets Tx High - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPR
value|0x040D0
end_define

begin_comment
comment|/* Total Packets Rx - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TPT
value|0x040D4
end_define

begin_comment
comment|/* Total Packets Tx - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC64
value|0x040D8
end_define

begin_comment
comment|/* Packets Tx (64 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC127
value|0x040DC
end_define

begin_comment
comment|/* Packets Tx (65-127 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC255
value|0x040E0
end_define

begin_comment
comment|/* Packets Tx (128-255 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC511
value|0x040E4
end_define

begin_comment
comment|/* Packets Tx (256-511 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1023
value|0x040E8
end_define

begin_comment
comment|/* Packets Tx (512-1023 bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_PTC1522
value|0x040EC
end_define

begin_comment
comment|/* Packets Tx (1024-1522 Bytes) - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_MPTC
value|0x040F0
end_define

begin_comment
comment|/* Multicast Packets Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_BPTC
value|0x040F4
end_define

begin_comment
comment|/* Broadcast Packets Tx Count - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTC
value|0x040F8
end_define

begin_comment
comment|/* TCP Segmentation Context Tx - R/clr */
end_comment

begin_define
define|#
directive|define
name|E1000_TSCTFC
value|0x040FC
end_define

begin_comment
comment|/* TCP Segmentation Context Tx Fail - R/clr */
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
comment|/* Interrupt Cause Rx Pkt Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXATC
value|0x04108
end_define

begin_comment
comment|/* Interrupt Cause Rx Abs Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXPTC
value|0x0410C
end_define

begin_comment
comment|/* Interrupt Cause Tx Pkt Timer Expire Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICTXATC
value|0x04110
end_define

begin_comment
comment|/* Interrupt Cause Tx Abs Timer Expire Count */
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
comment|/* Interrupt Cause Tx Queue Min Thresh Count */
end_comment

begin_define
define|#
directive|define
name|E1000_ICRXDMTC
value|0x04120
end_define

begin_comment
comment|/* Interrupt Cause Rx Desc Min Thresh Count */
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
name|E1000_CRC_OFFSET
value|0x05F50
end_define

begin_comment
comment|/* CRC Offset register */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXUT
value|0x04300
end_define

begin_comment
comment|/* LinkSec Tx Untagged Packet Count - OutPktsUntagged */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXPKTE
value|0x04304
end_define

begin_comment
comment|/* LinkSec Encrypted Tx Packets Count - OutPktsEncrypted */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXPKTP
value|0x04308
end_define

begin_comment
comment|/* LinkSec Protected Tx Packet Count - OutPktsProtected */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXOCTE
value|0x0430C
end_define

begin_comment
comment|/* LinkSec Encrypted Tx Octets Count - OutOctetsEncrypted */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXOCTP
value|0x04310
end_define

begin_comment
comment|/* LinkSec Protected Tx Octets Count - OutOctetsProtected */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXUT
value|0x04314
end_define

begin_comment
comment|/* LinkSec Untagged non-Strict Rx Packet Count - InPktsUntagged/InPktsNoTag */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXOCTD
value|0x0431C
end_define

begin_comment
comment|/* LinkSec Rx Octets Decrypted Count - InOctetsDecrypted */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXOCTV
value|0x04320
end_define

begin_comment
comment|/* LinkSec Rx Octets Validated - InOctetsValidated */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXBAD
value|0x04324
end_define

begin_comment
comment|/* LinkSec Rx Bad Tag - InPktsBadTag */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXNOSCI
value|0x04328
end_define

begin_comment
comment|/* LinkSec Rx Packet No SCI Count - InPktsNoSci */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXUNSCI
value|0x0432C
end_define

begin_comment
comment|/* LinkSec Rx Packet Unknown SCI Count - InPktsUnknownSci */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXUNCH
value|0x04330
end_define

begin_comment
comment|/* LinkSec Rx Unchecked Packets Count - InPktsUnchecked */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXDELAY
value|0x04340
end_define

begin_comment
comment|/* LinkSec Rx Delayed Packet Count - InPktsDelayed */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXLATE
value|0x04350
end_define

begin_comment
comment|/* LinkSec Rx Late Packets Count - InPktsLate */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXOK
parameter_list|(
name|_n
parameter_list|)
value|(0x04360 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Rx Packet OK Count - InPktsOk */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXINV
parameter_list|(
name|_n
parameter_list|)
value|(0x04380 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Rx Invalid Count - InPktsInvalid */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXNV
parameter_list|(
name|_n
parameter_list|)
value|(0x043A0 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Rx Not Valid Count - InPktsNotValid */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXUNSA
value|0x043C0
end_define

begin_comment
comment|/* LinkSec Rx Unused SA Count - InPktsUnusedSa */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXNUSA
value|0x043D0
end_define

begin_comment
comment|/* LinkSec Rx Not Using SA Count - InPktsNotUsingSa */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXCAP
value|0x0B000
end_define

begin_comment
comment|/* LinkSec Tx Capabilities Register - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXCAP
value|0x0B300
end_define

begin_comment
comment|/* LinkSec Rx Capabilities Register - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXCTRL
value|0x0B004
end_define

begin_comment
comment|/* LinkSec Tx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXCTRL
value|0x0B304
end_define

begin_comment
comment|/* LinkSec Rx Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXSCL
value|0x0B008
end_define

begin_comment
comment|/* LinkSec Tx SCI Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXSCH
value|0x0B00C
end_define

begin_comment
comment|/* LinkSec Tx SCI High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXSA
value|0x0B010
end_define

begin_comment
comment|/* LinkSec Tx SA0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXPN0
value|0x0B018
end_define

begin_comment
comment|/* LinkSec Tx SA PN 0 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXPN1
value|0x0B01C
end_define

begin_comment
comment|/* LinkSec Tx SA PN 1 - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXSCL
value|0x0B3D0
end_define

begin_comment
comment|/* LinkSec Rx SCI Low - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXSCH
value|0x0B3E0
end_define

begin_comment
comment|/* LinkSec Rx SCI High - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXKEY0
parameter_list|(
name|_n
parameter_list|)
value|(0x0B020 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Tx 128-bit Key 0 - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECTXKEY1
parameter_list|(
name|_n
parameter_list|)
value|(0x0B030 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Tx 128-bit Key 1 - WO */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXSA
parameter_list|(
name|_n
parameter_list|)
value|(0x0B310 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Rx SAs - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXPN
parameter_list|(
name|_n
parameter_list|)
value|(0x0B330 + (0x04 * (_n)))
end_define

begin_comment
comment|/* LinkSec Rx SAs - RW */
end_comment

begin_comment
comment|/*  * LinkSec Rx Keys  - where _n is the SA no. and _m the 4 dwords of the 128 bit  * key - RW.  */
end_comment

begin_define
define|#
directive|define
name|E1000_LSECRXKEY
parameter_list|(
name|_n
parameter_list|,
name|_m
parameter_list|)
value|(0x0B350 + (0x10 * (_n)) + (0x04 * (_m)))
end_define

begin_define
define|#
directive|define
name|E1000_SSVPC
value|0x041A0
end_define

begin_comment
comment|/* Switch Security Violation Packet Count */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSCTRL
value|0xB430
end_define

begin_comment
comment|/* IpSec Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXCMD
value|0x0B408
end_define

begin_comment
comment|/* IPSec Rx Command Register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXIDX
value|0x0B400
end_define

begin_comment
comment|/* IPSec Rx Index - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXIPADDR
parameter_list|(
name|_n
parameter_list|)
value|(0x0B420+ (0x04 * (_n)))
end_define

begin_comment
comment|/* IPSec Rx IPv4/v6 Address - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXKEY
parameter_list|(
name|_n
parameter_list|)
value|(0x0B410 + (0x04 * (_n)))
end_define

begin_comment
comment|/* IPSec Rx 128-bit Key - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXSALT
value|0x0B404
end_define

begin_comment
comment|/* IPSec Rx Salt - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSRXSPI
value|0x0B40C
end_define

begin_comment
comment|/* IPSec Rx SPI - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSTXKEY
parameter_list|(
name|_n
parameter_list|)
value|(0x0B460 + (0x04 * (_n)))
end_define

begin_comment
comment|/* IPSec Tx 128-bit Key - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSTXSALT
value|0x0B454
end_define

begin_comment
comment|/* IPSec Tx Salt - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IPSTXIDX
value|0x0B450
end_define

begin_comment
comment|/* IPSec Tx SA IDX - RW */
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
comment|/* Circuit Breaker Tx Packet Count */
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
comment|/* Circuit Breaker Rx Dropped Count */
end_comment

begin_define
define|#
directive|define
name|E1000_CBRMPC
value|0x040FC
end_define

begin_comment
comment|/* Circuit Breaker Rx Packet Count */
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
comment|/* Host Good Packets Tx Count */
end_comment

begin_define
define|#
directive|define
name|E1000_HTCBDPC
value|0x04124
end_define

begin_comment
comment|/* Host Tx Circuit Breaker Dropped Count */
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
comment|/* Rx Checksum Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RLPML
value|0x05004
end_define

begin_comment
comment|/* Rx Long Packet Max Length */
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
name|E1000_RA2
value|0x054E0
end_define

begin_comment
comment|/* 2nd half of receive address array - RW Array */
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
name|E1000_VT_CTL
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
name|E1000_FHFT
parameter_list|(
name|_n
parameter_list|)
value|(0x09000 + (_n * 0x100))
end_define

begin_comment
comment|/* Flexible Host Filter Table */
end_comment

begin_define
define|#
directive|define
name|E1000_FHFT_EXT
parameter_list|(
name|_n
parameter_list|)
value|(0x09A00 + (_n * 0x100))
end_define

begin_comment
comment|/* Ext Flexible Host Filter Table */
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
name|E1000_GCR2
value|0x05B64
end_define

begin_comment
comment|/* PCI-Ex Control #2 */
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
name|E1000_SWSM2
value|0x05B58
end_define

begin_comment
comment|/* Driver-only SW semaphore (not used by BOOT agents) */
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
name|E1000_UFUSE
value|0x05B78
end_define

begin_comment
comment|/* UFUSE - RO */
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
comment|/* Host Interface Control */
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
comment|/* Immediate Interrupt Rx VLAN Priority - RW */
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
comment|/* MSI-X Allocation Register                                                     * (_i) - RW */
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
comment|/* MSI-X Table entry addr                                                        * low reg - RW */
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
comment|/* MSI-X Table entry addr                                                        * upper reg - RW */
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
comment|/* MSI-X Table entry                                                        * message reg - RW */
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
comment|/* MSI-X Table entry                                                        * vector ctrl reg - RW */
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
comment|/* Redirection Table - RW */
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
comment|/* RSS Random Key - RW */
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

begin_comment
comment|/* VT Registers */
end_comment

begin_define
define|#
directive|define
name|E1000_SWPBS
value|0x03004
end_define

begin_comment
comment|/* Switch Packet Buffer Size - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFICR
value|0x00C80
end_define

begin_comment
comment|/* Mailbox VF Cause - RWC */
end_comment

begin_define
define|#
directive|define
name|E1000_MBVFIMR
value|0x00C84
end_define

begin_comment
comment|/* Mailbox VF int Mask - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VFLRE
value|0x00C88
end_define

begin_comment
comment|/* VF Register Events - RWC */
end_comment

begin_define
define|#
directive|define
name|E1000_VFRE
value|0x00C8C
end_define

begin_comment
comment|/* VF Receive Enables */
end_comment

begin_define
define|#
directive|define
name|E1000_VFTE
value|0x00C90
end_define

begin_comment
comment|/* VF Transmit Enables */
end_comment

begin_define
define|#
directive|define
name|E1000_QDE
value|0x02408
end_define

begin_comment
comment|/* Queue Drop Enable - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_DTXSWC
value|0x03500
end_define

begin_comment
comment|/* DMA Tx Switch Control - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RPLOLR
value|0x05AF0
end_define

begin_comment
comment|/* Replication Offload - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_UTA
value|0x0A000
end_define

begin_comment
comment|/* Unicast Table Array - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_IOVTCL
value|0x05BBC
end_define

begin_comment
comment|/* IOV Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_VMRCTL
value|0X05D80
end_define

begin_comment
comment|/* Virtual Mirror Rule Control */
end_comment

begin_comment
comment|/* These act per VF so an array friendly macro is used */
end_comment

begin_define
define|#
directive|define
name|E1000_V2PMAILBOX
parameter_list|(
name|_n
parameter_list|)
value|(0x00C40 + (4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_P2VMAILBOX
parameter_list|(
name|_n
parameter_list|)
value|(0x00C00 + (4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_VMBMEM
parameter_list|(
name|_n
parameter_list|)
value|(0x00800 + (64 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_VFVMBMEM
parameter_list|(
name|_n
parameter_list|)
value|(0x00800 + (_n))
end_define

begin_define
define|#
directive|define
name|E1000_VMOLR
parameter_list|(
name|_n
parameter_list|)
value|(0x05AD0 + (4 * (_n)))
end_define

begin_define
define|#
directive|define
name|E1000_VLVF
parameter_list|(
name|_n
parameter_list|)
value|(0x05D00 + (4 * (_n)))
end_define

begin_comment
comment|/* VLAN Virtual Machine                                                        * Filter - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_VMVIR
parameter_list|(
name|_n
parameter_list|)
value|(0x03700 + (4 * (_n)))
end_define

begin_comment
comment|/* Time Sync */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCTL
value|0x0B620
end_define

begin_comment
comment|/* Rx Time Sync Control register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCTXCTL
value|0x0B614
end_define

begin_comment
comment|/* Tx Time Sync Control register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TSYNCRXCFG
value|0x05F50
end_define

begin_comment
comment|/* Time Sync Rx Configuration - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXSTMPL
value|0x0B624
end_define

begin_comment
comment|/* Rx timestamp Low - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_RXSTMPH
value|0x0B628
end_define

begin_comment
comment|/* Rx timestamp High - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_RXSATRL
value|0x0B62C
end_define

begin_comment
comment|/* Rx timestamp attribute low - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_RXSATRH
value|0x0B630
end_define

begin_comment
comment|/* Rx timestamp attribute high - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_TXSTMPL
value|0x0B618
end_define

begin_comment
comment|/* Tx timestamp value Low - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_TXSTMPH
value|0x0B61C
end_define

begin_comment
comment|/* Tx timestamp value High - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_SYSTIML
value|0x0B600
end_define

begin_comment
comment|/* System time register Low - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_SYSTIMH
value|0x0B604
end_define

begin_comment
comment|/* System time register High - RO */
end_comment

begin_define
define|#
directive|define
name|E1000_TIMINCA
value|0x0B608
end_define

begin_comment
comment|/* Increment attributes register - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_TSAUXC
value|0x0B640
end_define

begin_comment
comment|/* Timesync Auxiliary Control register */
end_comment

begin_define
define|#
directive|define
name|E1000_SYSTIMR
value|0x0B6F8
end_define

begin_comment
comment|/* System time register Residue */
end_comment

begin_define
define|#
directive|define
name|E1000_RXMTRL
value|0x0B634
end_define

begin_comment
comment|/* Time sync Rx EtherType and Msg Type - RW */
end_comment

begin_define
define|#
directive|define
name|E1000_RXUDP
value|0x0B638
end_define

begin_comment
comment|/* Time Sync Rx UDP Port - RW */
end_comment

begin_comment
comment|/* Filtering Registers */
end_comment

begin_define
define|#
directive|define
name|E1000_SAQF
parameter_list|(
name|_n
parameter_list|)
value|(0x05980 + (4 * (_n)))
end_define

begin_comment
comment|/* Source Address Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_DAQF
parameter_list|(
name|_n
parameter_list|)
value|(0x059A0 + (4 * (_n)))
end_define

begin_comment
comment|/* Dest Address Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_SPQF
parameter_list|(
name|_n
parameter_list|)
value|(0x059C0 + (4 * (_n)))
end_define

begin_comment
comment|/* Source Port Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_FTQF
parameter_list|(
name|_n
parameter_list|)
value|(0x059E0 + (4 * (_n)))
end_define

begin_comment
comment|/* 5-tuple Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_TTQF
parameter_list|(
name|_n
parameter_list|)
value|(0x059E0 + (4 * (_n)))
end_define

begin_comment
comment|/* 2-tuple Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_SYNQF
parameter_list|(
name|_n
parameter_list|)
value|(0x055FC + (4 * (_n)))
end_define

begin_comment
comment|/* SYN Packet Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_ETQF
parameter_list|(
name|_n
parameter_list|)
value|(0x05CB0 + (4 * (_n)))
end_define

begin_comment
comment|/* EType Queue Fltr */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDCS
value|0x3600
end_define

begin_comment
comment|/* Reedtown Tx Desc plane control and status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTPCS
value|0x3474
end_define

begin_comment
comment|/* Reedtown Tx Packet Plane control and status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRPCS
value|0x2474
end_define

begin_comment
comment|/* Rx packet plane control and status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRUP2TC
value|0x05AC4
end_define

begin_comment
comment|/* Rx User Priority to Traffic Class */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTUP2TC
value|0x0418
end_define

begin_comment
comment|/* Transmit User Priority to Traffic Class */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDTCRC
parameter_list|(
name|_n
parameter_list|)
value|(0x3610 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Desc plane TC Rate-scheduler config */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTPTCRC
parameter_list|(
name|_n
parameter_list|)
value|(0x3480 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Packet plane TC Rate-Scheduler Config */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRPTCRC
parameter_list|(
name|_n
parameter_list|)
value|(0x2480 + ((_n) * 4))
end_define

begin_comment
comment|/* Rx Packet plane TC Rate-Scheduler Config */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDTCRS
parameter_list|(
name|_n
parameter_list|)
value|(0x3630 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Desc Plane TC Rate-Scheduler Status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDTCRM
parameter_list|(
name|_n
parameter_list|)
value|(0x3650 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Desc Plane TC Rate-Scheduler MMW */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTPTCRS
parameter_list|(
name|_n
parameter_list|)
value|(0x34A0 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Packet plane TC Rate-Scheduler Status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTPTCRM
parameter_list|(
name|_n
parameter_list|)
value|(0x34C0 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Packet plane TC Rate-scheduler MMW */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRPTCRS
parameter_list|(
name|_n
parameter_list|)
value|(0x24A0 + ((_n) * 4))
end_define

begin_comment
comment|/* Rx Packet plane TC Rate-Scheduler Status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRPTCRM
parameter_list|(
name|_n
parameter_list|)
value|(0x24C0 + ((_n) * 4))
end_define

begin_comment
comment|/* Rx Packet plane TC Rate-Scheduler MMW */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDVMRM
parameter_list|(
name|_n
parameter_list|)
value|(0x3670 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx Desc plane VM Rate-Scheduler MMW*/
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNRM
parameter_list|(
name|_n
parameter_list|)
value|(0x3690 + ((_n) * 4))
end_define

begin_comment
comment|/* Tx BCN Rate-Scheduler MMW */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDQSEL
value|0x3604
end_define

begin_comment
comment|/* Tx Desc Plane Queue Select */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDVMRC
value|0x3608
end_define

begin_comment
comment|/* Tx Desc Plane VM Rate-Scheduler Config */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTDVMRS
value|0x360C
end_define

begin_comment
comment|/* Tx Desc Plane VM Rate-Scheduler Status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNRC
value|0x36B0
end_define

begin_comment
comment|/* Tx BCN Rate-Scheduler Config */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNRS
value|0x36B4
end_define

begin_comment
comment|/* Tx BCN Rate-Scheduler Status */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNCR
value|0xB200
end_define

begin_comment
comment|/* Tx BCN Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNTG
value|0x35A4
end_define

begin_comment
comment|/* Tx BCN Tagging */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNCP
value|0xB208
end_define

begin_comment
comment|/* Tx BCN Congestion point */
end_comment

begin_define
define|#
directive|define
name|E1000_RTRBCNCR
value|0xB20C
end_define

begin_comment
comment|/* Rx BCN Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNRD
value|0x36B8
end_define

begin_comment
comment|/* Tx BCN Rate Drift */
end_comment

begin_define
define|#
directive|define
name|E1000_PFCTOP
value|0x1080
end_define

begin_comment
comment|/* Priority Flow Control Type and Opcode */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNIDX
value|0xB204
end_define

begin_comment
comment|/* Tx BCN Congestion Point */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNACH
value|0x0B214
end_define

begin_comment
comment|/* Tx BCN Control High */
end_comment

begin_define
define|#
directive|define
name|E1000_RTTBCNACL
value|0x0B210
end_define

begin_comment
comment|/* Tx BCN Control Low */
end_comment

begin_comment
comment|/* DMA Coalescing registers */
end_comment

begin_define
define|#
directive|define
name|E1000_DMACR
value|0x02508
end_define

begin_comment
comment|/* Control Register */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCTXTH
value|0x03550
end_define

begin_comment
comment|/* Transmit Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCTLX
value|0x02514
end_define

begin_comment
comment|/* Time to Lx Request */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCRTRH
value|0x05DD0
end_define

begin_comment
comment|/* Receive Packet Rate Threshold */
end_comment

begin_define
define|#
directive|define
name|E1000_DMCCNT
value|0x05DD4
end_define

begin_comment
comment|/* Current RX Count */
end_comment

begin_define
define|#
directive|define
name|E1000_FCRTC
value|0x02170
end_define

begin_comment
comment|/* Flow Control Rx high watermark */
end_comment

begin_define
define|#
directive|define
name|E1000_PCIEMISC
value|0x05BB8
end_define

begin_comment
comment|/* PCIE misc config register */
end_comment

begin_comment
comment|/* PCIe Parity Status Register */
end_comment

begin_define
define|#
directive|define
name|E1000_PCIEERRSTS
value|0x05BA8
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

