begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: lancereg.h,v 1.12 2005/12/11 12:21:27 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 2000 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Charles M. Hannum and Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell and Rick Macklem.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)if_lereg.h	8.1 (Berkeley) 6/10/93  */
end_comment

begin_comment
comment|/*  * Register description for the following Advanced Micro Devices  * Ethernet chips:  *  *	- Am7990 Local Area Network Controller for Ethernet (LANCE)  *	  (and its descendent Am79c90 C-LANCE).  *  *	- Am79c900 Integrated Local Area Communications Controller (ILACC)  *  *	- Am79c960 PCnet-ISA Single-Chip Ethernet Controller for ISA  *  *	- Am79c961 PCnet-ISA+ Jumperless Single-Chip Ethernet Controller  *	  for ISA  *  *	- Am79c961A PCnet-ISA II Jumperless Full-Duplex Single-Chip  *	  Ethernet Controller for ISA  *  *	- Am79c965A PCnet-32 Single-Chip 32-bit Ethernet Controller  *	  (for VESA and 486 local busses)  *  *	- Am79c970 PCnet-PCI Single-Chip Ethernet Controller for PCI  *	  Local Bus  *  *	- Am79c970A PCnet-PCI II Single-Chip Full-Duplex Ethernet Controller  *	  for PCI Local Bus  *  *	- Am79c971 PCnet-FAST Single-Chip Full-Duplex 10/100Mbps  *	  Ethernet Controller for PCI Local Bus  *  *	- Am79c972 PCnet-FAST+ Enhanced 10/100Mbps PCI Ethernet Controller  *	  with OnNow Support  *  *	- Am79c973/Am79c975 PCnet-FAST III Single-Chip 10/100Mbps PCI  *	  Ethernet Controller with Integrated PHY  *  *	- Am79c978 PCnet-Home Single-Chip 1/10 Mbps PCI Home  *	  Networking Controller.  *  * Initialization block, transmit descriptor, and receive descriptor  * formats are described in two separate files:  *  *	16-bit software model (LANCE)		am7990reg.h  *  *	32-bit software model (ILACC)		am79900reg.h  *  * Note that the vast majority of the registers described in this file  * belong to follow-on chips to the original LANCE.  Only CSR0-CSR3 are  * valid on the LANCE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_LE_LANCEREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_LE_LANCEREG_H_
end_define

begin_define
define|#
directive|define
name|LEBLEN
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN)
end_define

begin_comment
comment|/* LEMINSIZE should be ETHER_MIN_LEN when LE_MODE_DTCR is set. */
end_comment

begin_define
define|#
directive|define
name|LEMINSIZE
value|(ETHER_MIN_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|LE_INITADDR
parameter_list|(
name|sc
parameter_list|)
value|(sc->sc_initaddr)
end_define

begin_define
define|#
directive|define
name|LE_RMDADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_rmdaddr + sizeof(struct lermd) * (bix))
end_define

begin_define
define|#
directive|define
name|LE_TMDADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_tmdaddr + sizeof(struct letmd) * (bix))
end_define

begin_define
define|#
directive|define
name|LE_RBUFADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_rbufaddr + LEBLEN * (bix))
end_define

begin_define
define|#
directive|define
name|LE_TBUFADDR
parameter_list|(
name|sc
parameter_list|,
name|bix
parameter_list|)
value|(sc->sc_tbufaddr + LEBLEN * (bix))
end_define

begin_comment
comment|/*  * The byte count fields in descriptors are in two's complement.  * This macro does the conversion for us on unsigned numbers.  */
end_comment

begin_define
define|#
directive|define
name|LE_BCNT
parameter_list|(
name|x
parameter_list|)
value|(~(x) + 1)
end_define

begin_comment
comment|/*  * Control and Status Register addresses  */
end_comment

begin_define
define|#
directive|define
name|LE_CSR0
value|0x0000
end_define

begin_comment
comment|/* Control and status register */
end_comment

begin_define
define|#
directive|define
name|LE_CSR1
value|0x0001
end_define

begin_comment
comment|/* low address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR2
value|0x0002
end_define

begin_comment
comment|/* high address of init block */
end_comment

begin_define
define|#
directive|define
name|LE_CSR3
value|0x0003
end_define

begin_comment
comment|/* Bus master and control */
end_comment

begin_define
define|#
directive|define
name|LE_CSR4
value|0x0004
end_define

begin_comment
comment|/* Test and features control */
end_comment

begin_define
define|#
directive|define
name|LE_CSR5
value|0x0005
end_define

begin_comment
comment|/* Extended control and Interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR6
value|0x0006
end_define

begin_comment
comment|/* Rx/Tx Descriptor table length */
end_comment

begin_define
define|#
directive|define
name|LE_CSR7
value|0x0007
end_define

begin_comment
comment|/* Extended control and interrupt 2 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR8
value|0x0008
end_define

begin_comment
comment|/* Logical Address Filter 0 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR9
value|0x0009
end_define

begin_comment
comment|/* Logical Address Filter 1 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR10
value|0x000a
end_define

begin_comment
comment|/* Logical Address Filter 2 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR11
value|0x000b
end_define

begin_comment
comment|/* Logical Address Filter 3 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR12
value|0x000c
end_define

begin_comment
comment|/* Physical Address 0 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR13
value|0x000d
end_define

begin_comment
comment|/* Physical Address 1 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR14
value|0x000e
end_define

begin_comment
comment|/* Physical Address 2 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR15
value|0x000f
end_define

begin_comment
comment|/* Mode */
end_comment

begin_define
define|#
directive|define
name|LE_CSR16
value|0x0010
end_define

begin_comment
comment|/* Initialization Block addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR17
value|0x0011
end_define

begin_comment
comment|/* Initialization Block addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR18
value|0x0012
end_define

begin_comment
comment|/* Current Rx Buffer addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR19
value|0x0013
end_define

begin_comment
comment|/* Current Rx Buffer addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR20
value|0x0014
end_define

begin_comment
comment|/* Current Tx Buffer addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR21
value|0x0015
end_define

begin_comment
comment|/* Current Tx Buffer addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR22
value|0x0016
end_define

begin_comment
comment|/* Next Rx Buffer addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR23
value|0x0017
end_define

begin_comment
comment|/* Next Rx Buffer addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR24
value|0x0018
end_define

begin_comment
comment|/* Base addr of Rx ring lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR25
value|0x0019
end_define

begin_comment
comment|/* Base addr of Rx ring upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR26
value|0x001a
end_define

begin_comment
comment|/* Next Rx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR27
value|0x001b
end_define

begin_comment
comment|/* Next Rx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR28
value|0x001c
end_define

begin_comment
comment|/* Current Rx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR29
value|0x001d
end_define

begin_comment
comment|/* Current Rx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR30
value|0x001e
end_define

begin_comment
comment|/* Base addr of Tx ring lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR31
value|0x001f
end_define

begin_comment
comment|/* Base addr of Tx ring upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR32
value|0x0020
end_define

begin_comment
comment|/* Next Tx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR33
value|0x0021
end_define

begin_comment
comment|/* Next Tx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR34
value|0x0022
end_define

begin_comment
comment|/* Current Tx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR35
value|0x0023
end_define

begin_comment
comment|/* Current Tx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR36
value|0x0024
end_define

begin_comment
comment|/* Next Next Rx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR37
value|0x0025
end_define

begin_comment
comment|/* Next Next Rx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR38
value|0x0026
end_define

begin_comment
comment|/* Next Next Tx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR39
value|0x0027
end_define

begin_comment
comment|/* Next Next Tx Desc adddr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR40
value|0x0028
end_define

begin_comment
comment|/* Current Rx Byte Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR41
value|0x0029
end_define

begin_comment
comment|/* Current Rx Status */
end_comment

begin_define
define|#
directive|define
name|LE_CSR42
value|0x002a
end_define

begin_comment
comment|/* Current Tx Byte Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR43
value|0x002b
end_define

begin_comment
comment|/* Current Tx Status */
end_comment

begin_define
define|#
directive|define
name|LE_CSR44
value|0x002c
end_define

begin_comment
comment|/* Next Rx Byte Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR45
value|0x002d
end_define

begin_comment
comment|/* Next Rx Status */
end_comment

begin_define
define|#
directive|define
name|LE_CSR46
value|0x002e
end_define

begin_comment
comment|/* Tx Poll Time Counter */
end_comment

begin_define
define|#
directive|define
name|LE_CSR47
value|0x002f
end_define

begin_comment
comment|/* Tx Polling Interval */
end_comment

begin_define
define|#
directive|define
name|LE_CSR48
value|0x0030
end_define

begin_comment
comment|/* Rx Poll Time Counter */
end_comment

begin_define
define|#
directive|define
name|LE_CSR49
value|0x0031
end_define

begin_comment
comment|/* Rx Polling Interval */
end_comment

begin_define
define|#
directive|define
name|LE_CSR58
value|0x003a
end_define

begin_comment
comment|/* Software Style */
end_comment

begin_define
define|#
directive|define
name|LE_CSR60
value|0x003c
end_define

begin_comment
comment|/* Previous Tx Desc addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR61
value|0x003d
end_define

begin_comment
comment|/* Previous Tx Desc addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR62
value|0x003e
end_define

begin_comment
comment|/* Previous Tx Byte Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR63
value|0x003f
end_define

begin_comment
comment|/* Previous Tx Status */
end_comment

begin_define
define|#
directive|define
name|LE_CSR64
value|0x0040
end_define

begin_comment
comment|/* Next Tx Buffer addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR65
value|0x0041
end_define

begin_comment
comment|/* Next Tx Buffer addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR66
value|0x0042
end_define

begin_comment
comment|/* Next Tx Byte Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR67
value|0x0043
end_define

begin_comment
comment|/* Next Tx Status */
end_comment

begin_define
define|#
directive|define
name|LE_CSR72
value|0x0048
end_define

begin_comment
comment|/* Receive Ring Counter */
end_comment

begin_define
define|#
directive|define
name|LE_CSR74
value|0x004a
end_define

begin_comment
comment|/* Transmit Ring Counter */
end_comment

begin_define
define|#
directive|define
name|LE_CSR76
value|0x004c
end_define

begin_comment
comment|/* Receive Ring Length */
end_comment

begin_define
define|#
directive|define
name|LE_CSR78
value|0x004e
end_define

begin_comment
comment|/* Transmit Ring Length */
end_comment

begin_define
define|#
directive|define
name|LE_CSR80
value|0x0050
end_define

begin_comment
comment|/* DMA Transfer Counter and FIFO 					   Threshold Control */
end_comment

begin_define
define|#
directive|define
name|LE_CSR82
value|0x0052
end_define

begin_comment
comment|/* Tx Desc addr Pointer lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR84
value|0x0054
end_define

begin_comment
comment|/* DMA addr register lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR85
value|0x0055
end_define

begin_comment
comment|/* DMA addr register upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR86
value|0x0056
end_define

begin_comment
comment|/* Buffer Byte Counter */
end_comment

begin_define
define|#
directive|define
name|LE_CSR88
value|0x0058
end_define

begin_comment
comment|/* Chip ID Register lower */
end_comment

begin_define
define|#
directive|define
name|LE_CSR89
value|0x0059
end_define

begin_comment
comment|/* Chip ID Register upper */
end_comment

begin_define
define|#
directive|define
name|LE_CSR92
value|0x005c
end_define

begin_comment
comment|/* Ring Length Conversion */
end_comment

begin_define
define|#
directive|define
name|LE_CSR100
value|0x0064
end_define

begin_comment
comment|/* Bus Timeout */
end_comment

begin_define
define|#
directive|define
name|LE_CSR112
value|0x0070
end_define

begin_comment
comment|/* Missed Frame Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR114
value|0x0072
end_define

begin_comment
comment|/* Receive Collision Count */
end_comment

begin_define
define|#
directive|define
name|LE_CSR116
value|0x0074
end_define

begin_comment
comment|/* OnNow Power Mode Register */
end_comment

begin_define
define|#
directive|define
name|LE_CSR122
value|0x007a
end_define

begin_comment
comment|/* Advanced Feature Control */
end_comment

begin_define
define|#
directive|define
name|LE_CSR124
value|0x007c
end_define

begin_comment
comment|/* Test Register 1 */
end_comment

begin_define
define|#
directive|define
name|LE_CSR125
value|0x007d
end_define

begin_comment
comment|/* MAC Enhanced Configuration Control */
end_comment

begin_comment
comment|/*  * Bus Configuration Register addresses  */
end_comment

begin_define
define|#
directive|define
name|LE_BCR0
value|0x0000
end_define

begin_comment
comment|/* Master Mode Read Active */
end_comment

begin_define
define|#
directive|define
name|LE_BCR1
value|0x0001
end_define

begin_comment
comment|/* Master Mode Write Active */
end_comment

begin_define
define|#
directive|define
name|LE_BCR2
value|0x0002
end_define

begin_comment
comment|/* Misc. Configuration */
end_comment

begin_define
define|#
directive|define
name|LE_BCR4
value|0x0004
end_define

begin_comment
comment|/* LED0 Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR5
value|0x0005
end_define

begin_comment
comment|/* LED1 Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR6
value|0x0006
end_define

begin_comment
comment|/* LED2 Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR7
value|0x0007
end_define

begin_comment
comment|/* LED3 Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR9
value|0x0009
end_define

begin_comment
comment|/* Full-duplex Control */
end_comment

begin_define
define|#
directive|define
name|LE_BCR16
value|0x0010
end_define

begin_comment
comment|/* I/O Base Address lower */
end_comment

begin_define
define|#
directive|define
name|LE_BCR17
value|0x0011
end_define

begin_comment
comment|/* I/O Base Address upper */
end_comment

begin_define
define|#
directive|define
name|LE_BCR18
value|0x0012
end_define

begin_comment
comment|/* Burst and Bus Control Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR19
value|0x0013
end_define

begin_comment
comment|/* EEPROM Control and Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR20
value|0x0014
end_define

begin_comment
comment|/* Software Style */
end_comment

begin_define
define|#
directive|define
name|LE_BCR22
value|0x0016
end_define

begin_comment
comment|/* PCI Latency Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR23
value|0x0017
end_define

begin_comment
comment|/* PCI Subsystem Vendor ID */
end_comment

begin_define
define|#
directive|define
name|LE_BCR24
value|0x0018
end_define

begin_comment
comment|/* PCI Subsystem ID */
end_comment

begin_define
define|#
directive|define
name|LE_BCR25
value|0x0019
end_define

begin_comment
comment|/* SRAM Size Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR26
value|0x001a
end_define

begin_comment
comment|/* SRAM Boundary Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR27
value|0x001b
end_define

begin_comment
comment|/* SRAM Interface Control Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR28
value|0x001c
end_define

begin_comment
comment|/* Exp. Bus Port Addr lower */
end_comment

begin_define
define|#
directive|define
name|LE_BCR29
value|0x001d
end_define

begin_comment
comment|/* Exp. Bus Port Addr upper */
end_comment

begin_define
define|#
directive|define
name|LE_BCR30
value|0x001e
end_define

begin_comment
comment|/* Exp. Bus Data Port */
end_comment

begin_define
define|#
directive|define
name|LE_BCR31
value|0x001f
end_define

begin_comment
comment|/* Software Timer Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR32
value|0x0020
end_define

begin_comment
comment|/* PHY Control and Status Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR33
value|0x0021
end_define

begin_comment
comment|/* PHY Address Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR34
value|0x0022
end_define

begin_comment
comment|/* PHY Management Data Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR35
value|0x0023
end_define

begin_comment
comment|/* PCI Vendor ID Register */
end_comment

begin_define
define|#
directive|define
name|LE_BCR36
value|0x0024
end_define

begin_comment
comment|/* PCI Power Management Cap. Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR37
value|0x0025
end_define

begin_comment
comment|/* PCI DATA0 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR38
value|0x0026
end_define

begin_comment
comment|/* PCI DATA1 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR39
value|0x0027
end_define

begin_comment
comment|/* PCI DATA2 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR40
value|0x0028
end_define

begin_comment
comment|/* PCI DATA3 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR41
value|0x0029
end_define

begin_comment
comment|/* PCI DATA4 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR42
value|0x002a
end_define

begin_comment
comment|/* PCI DATA5 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR43
value|0x002b
end_define

begin_comment
comment|/* PCI DATA6 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR44
value|0x002c
end_define

begin_comment
comment|/* PCI DATA7 Alias */
end_comment

begin_define
define|#
directive|define
name|LE_BCR45
value|0x002d
end_define

begin_comment
comment|/* OnNow Pattern Matching 1 */
end_comment

begin_define
define|#
directive|define
name|LE_BCR46
value|0x002e
end_define

begin_comment
comment|/* OnNow Pattern Matching 2 */
end_comment

begin_define
define|#
directive|define
name|LE_BCR47
value|0x002f
end_define

begin_comment
comment|/* OnNow Pattern Matching 3 */
end_comment

begin_define
define|#
directive|define
name|LE_BCR48
value|0x0030
end_define

begin_comment
comment|/* LED4 Status */
end_comment

begin_define
define|#
directive|define
name|LE_BCR49
value|0x0031
end_define

begin_comment
comment|/* PHY Select */
end_comment

begin_comment
comment|/* Control and status register 0 (csr0) */
end_comment

begin_define
define|#
directive|define
name|LE_C0_ERR
value|0x8000
end_define

begin_comment
comment|/* error summary */
end_comment

begin_define
define|#
directive|define
name|LE_C0_BABL
value|0x4000
end_define

begin_comment
comment|/* transmitter timeout error */
end_comment

begin_define
define|#
directive|define
name|LE_C0_CERR
value|0x2000
end_define

begin_comment
comment|/* collision */
end_comment

begin_define
define|#
directive|define
name|LE_C0_MISS
value|0x1000
end_define

begin_comment
comment|/* missed a packet */
end_comment

begin_define
define|#
directive|define
name|LE_C0_MERR
value|0x0800
end_define

begin_comment
comment|/* memory error */
end_comment

begin_define
define|#
directive|define
name|LE_C0_RINT
value|0x0400
end_define

begin_comment
comment|/* receiver interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TINT
value|0x0200
end_define

begin_comment
comment|/* transmitter interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C0_IDON
value|0x0100
end_define

begin_comment
comment|/* initialization done */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INTR
value|0x0080
end_define

begin_comment
comment|/* interrupt condition */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INEA
value|0x0040
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C0_RXON
value|0x0020
end_define

begin_comment
comment|/* receiver on */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TXON
value|0x0010
end_define

begin_comment
comment|/* transmitter on */
end_comment

begin_define
define|#
directive|define
name|LE_C0_TDMD
value|0x0008
end_define

begin_comment
comment|/* transmit demand */
end_comment

begin_define
define|#
directive|define
name|LE_C0_STOP
value|0x0004
end_define

begin_comment
comment|/* disable all external activity */
end_comment

begin_define
define|#
directive|define
name|LE_C0_STRT
value|0x0002
end_define

begin_comment
comment|/* enable external activity */
end_comment

begin_define
define|#
directive|define
name|LE_C0_INIT
value|0x0001
end_define

begin_comment
comment|/* begin initialization */
end_comment

begin_define
define|#
directive|define
name|LE_C0_BITS
define|\
value|"\20\20ERR\17BABL\16CERR\15MISS\14MERR\13RINT\ \12TINT\11IDON\10INTR\07INEA\06RXON\05TXON\04TDMD\03STOP\02STRT\01INIT"
end_define

begin_comment
comment|/* Control and status register 3 (csr3) */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BABLM
value|0x4000
end_define

begin_comment
comment|/* babble mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_MISSM
value|0x1000
end_define

begin_comment
comment|/* missed frame mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_MERRM
value|0x0800
end_define

begin_comment
comment|/* memory error mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_RINTM
value|0x0400
end_define

begin_comment
comment|/* receive interrupt mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_TINTM
value|0x0200
end_define

begin_comment
comment|/* transmit interrupt mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_IDONM
value|0x0100
end_define

begin_comment
comment|/* initialization done mask */
end_comment

begin_define
define|#
directive|define
name|LE_C3_DXSUFLO
value|0x0040
end_define

begin_comment
comment|/* disable tx stop on underflow */
end_comment

begin_define
define|#
directive|define
name|LE_C3_LAPPEN
value|0x0020
end_define

begin_comment
comment|/* look ahead packet processing enbl */
end_comment

begin_define
define|#
directive|define
name|LE_C3_DXMT2PD
value|0x0010
end_define

begin_comment
comment|/* disable tx two part deferral */
end_comment

begin_define
define|#
directive|define
name|LE_C3_EMBA
value|0x0008
end_define

begin_comment
comment|/* enable modified backoff algorithm */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BSWP
value|0x0004
end_define

begin_comment
comment|/* byte swap */
end_comment

begin_define
define|#
directive|define
name|LE_C3_ACON
value|0x0002
end_define

begin_comment
comment|/* ALE control, eh? */
end_comment

begin_define
define|#
directive|define
name|LE_C3_BCON
value|0x0001
end_define

begin_comment
comment|/* byte control */
end_comment

begin_comment
comment|/* Control and status register 4 (csr4) */
end_comment

begin_define
define|#
directive|define
name|LE_C4_EN124
value|0x8000
end_define

begin_comment
comment|/* enable CSR124 */
end_comment

begin_define
define|#
directive|define
name|LE_C4_DMAPLUS
value|0x4000
end_define

begin_comment
comment|/* always set (PCnet-PCI) */
end_comment

begin_define
define|#
directive|define
name|LE_C4_TIMER
value|0x2000
end_define

begin_comment
comment|/* enable bus activity timer */
end_comment

begin_define
define|#
directive|define
name|LE_C4_TXDPOLL
value|0x1000
end_define

begin_comment
comment|/* disable transmit polling */
end_comment

begin_define
define|#
directive|define
name|LE_C4_APAD_XMT
value|0x0800
end_define

begin_comment
comment|/* auto pad transmit */
end_comment

begin_define
define|#
directive|define
name|LE_C4_ASTRP_RCV
value|0x0400
end_define

begin_comment
comment|/* auto strip receive */
end_comment

begin_define
define|#
directive|define
name|LE_C4_MFCO
value|0x0200
end_define

begin_comment
comment|/* missed frame counter overflow */
end_comment

begin_define
define|#
directive|define
name|LE_C4_MFCOM
value|0x0100
end_define

begin_comment
comment|/* missed frame coutner overflow mask */
end_comment

begin_define
define|#
directive|define
name|LE_C4_UINTCMD
value|0x0080
end_define

begin_comment
comment|/* user interrupt command */
end_comment

begin_define
define|#
directive|define
name|LE_C4_UINT
value|0x0040
end_define

begin_comment
comment|/* user interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C4_RCVCCO
value|0x0020
end_define

begin_comment
comment|/* receive collision counter overflow */
end_comment

begin_define
define|#
directive|define
name|LE_C4_RCVCCOM
value|0x0010
end_define

begin_comment
comment|/* receive collision counter overflow 					   mask */
end_comment

begin_define
define|#
directive|define
name|LE_C4_TXSTRT
value|0x0008
end_define

begin_comment
comment|/* transmit start status */
end_comment

begin_define
define|#
directive|define
name|LE_C4_TXSTRTM
value|0x0004
end_define

begin_comment
comment|/* transmit start mask */
end_comment

begin_comment
comment|/* Control and status register 5 (csr5) */
end_comment

begin_define
define|#
directive|define
name|LE_C5_TOKINTD
value|0x8000
end_define

begin_comment
comment|/* transmit ok interrupt disable */
end_comment

begin_define
define|#
directive|define
name|LE_C5_LTINTEN
value|0x4000
end_define

begin_comment
comment|/* last transmit interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C5_SINT
value|0x0800
end_define

begin_comment
comment|/* system interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C5_SINTE
value|0x0400
end_define

begin_comment
comment|/* system interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C5_EXDINT
value|0x0080
end_define

begin_comment
comment|/* excessive deferral interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C5_EXDINTE
value|0x0040
end_define

begin_comment
comment|/* excessive deferral interrupt enbl */
end_comment

begin_define
define|#
directive|define
name|LE_C5_MPPLBA
value|0x0020
end_define

begin_comment
comment|/* magic packet physical logical 					   broadcast accept */
end_comment

begin_define
define|#
directive|define
name|LE_C5_MPINT
value|0x0010
end_define

begin_comment
comment|/* magic packet interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C5_MPINTE
value|0x0008
end_define

begin_comment
comment|/* magic packet interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C5_MPEN
value|0x0004
end_define

begin_comment
comment|/* magic packet enable */
end_comment

begin_define
define|#
directive|define
name|LE_C5_MPMODE
value|0x0002
end_define

begin_comment
comment|/* magic packet mode */
end_comment

begin_define
define|#
directive|define
name|LE_C5_SPND
value|0x0001
end_define

begin_comment
comment|/* suspend */
end_comment

begin_comment
comment|/* Control and status register 6 (csr6) */
end_comment

begin_define
define|#
directive|define
name|LE_C6_TLEN
value|0xf000
end_define

begin_comment
comment|/* TLEN from init block */
end_comment

begin_define
define|#
directive|define
name|LE_C6_RLEN
value|0x0f00
end_define

begin_comment
comment|/* RLEN from init block */
end_comment

begin_comment
comment|/* Control and status register 7 (csr7) */
end_comment

begin_define
define|#
directive|define
name|LE_C7_FASTSPNDE
value|0x8000
end_define

begin_comment
comment|/* fast suspend enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_RDMD
value|0x2000
end_define

begin_comment
comment|/* receive demand */
end_comment

begin_define
define|#
directive|define
name|LE_C7_RDXPOLL
value|0x1000
end_define

begin_comment
comment|/* receive disable polling */
end_comment

begin_define
define|#
directive|define
name|LE_C7_STINT
value|0x0800
end_define

begin_comment
comment|/* software timer interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C7_STINTE
value|0x0400
end_define

begin_comment
comment|/* software timer interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MREINT
value|0x0200
end_define

begin_comment
comment|/* PHY management read error intr */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MREINTE
value|0x0100
end_define

begin_comment
comment|/* PHY management read error intr 					   enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MAPINT
value|0x0080
end_define

begin_comment
comment|/* PHY management auto-poll intr */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MAPINTE
value|0x0040
end_define

begin_comment
comment|/* PHY management auto-poll intr 					   enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MCCINT
value|0x0020
end_define

begin_comment
comment|/* PHY management command complete 					   interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MCCINTE
value|0x0010
end_define

begin_comment
comment|/* PHY management command complete 					   interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MCCIINT
value|0x0008
end_define

begin_comment
comment|/* PHY management command complete 					   internal interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MCCIINTE
value|0x0004
end_define

begin_comment
comment|/* PHY management command complete 					   internal interrupt enable */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MIIPDTINT
value|0x0002
end_define

begin_comment
comment|/* PHY management detect transition 					   interrupt */
end_comment

begin_define
define|#
directive|define
name|LE_C7_MIIPDTINTE
value|0x0001
end_define

begin_comment
comment|/* PHY management detect transition 					   interrupt enable */
end_comment

begin_comment
comment|/* Control and status register 15 (csr15) */
end_comment

begin_define
define|#
directive|define
name|LE_C15_PROM
value|0x8000
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DRCVBC
value|0x4000
end_define

begin_comment
comment|/* disable Rx of broadcast */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DRCVPA
value|0x2000
end_define

begin_comment
comment|/* disable Rx of physical address */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DLNKTST
value|0x1000
end_define

begin_comment
comment|/* disable link status */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DAPC
value|0x0800
end_define

begin_comment
comment|/* disable auto-polarity correction */
end_comment

begin_define
define|#
directive|define
name|LE_C15_MENDECL
value|0x0400
end_define

begin_comment
comment|/* MENDEC Loopback mode */
end_comment

begin_define
define|#
directive|define
name|LE_C15_LRT
value|0x0200
end_define

begin_comment
comment|/* low receive threshold (TMAU) */
end_comment

begin_define
define|#
directive|define
name|LE_C15_TSEL
value|0x0200
end_define

begin_comment
comment|/* transmit mode select (AUI) */
end_comment

begin_define
define|#
directive|define
name|LE_C15_PORTSEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 7)
end_define

begin_comment
comment|/* port select */
end_comment

begin_define
define|#
directive|define
name|LE_C15_INTL
value|0x0040
end_define

begin_comment
comment|/* internal loopback */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DRTY
value|0x0020
end_define

begin_comment
comment|/* disable retry */
end_comment

begin_define
define|#
directive|define
name|LE_C15_FCOLL
value|0x0010
end_define

begin_comment
comment|/* force collision */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DXMTFCS
value|0x0008
end_define

begin_comment
comment|/* disable Tx FCS (ADD_FCS overrides) */
end_comment

begin_define
define|#
directive|define
name|LE_C15_LOOP
value|0x0004
end_define

begin_comment
comment|/* loopback enable */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DTX
value|0x0002
end_define

begin_comment
comment|/* disable transmit */
end_comment

begin_define
define|#
directive|define
name|LE_C15_DRX
value|0x0001
end_define

begin_comment
comment|/* disable receiver */
end_comment

begin_define
define|#
directive|define
name|LE_PORTSEL_AUI
value|0
end_define

begin_define
define|#
directive|define
name|LE_PORTSEL_10T
value|1
end_define

begin_define
define|#
directive|define
name|LE_PORTSEL_GPSI
value|2
end_define

begin_define
define|#
directive|define
name|LE_PORTSEL_MII
value|3
end_define

begin_define
define|#
directive|define
name|LE_PORTSEL_MASK
value|3
end_define

begin_comment
comment|/* control and status register 80 (csr80) */
end_comment

begin_define
define|#
directive|define
name|LE_C80_RCVFW
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_comment
comment|/* Receive FIFO Watermark */
end_comment

begin_define
define|#
directive|define
name|LE_C80_RCVFW_MAX
value|3
end_define

begin_define
define|#
directive|define
name|LE_C80_XMTSP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_comment
comment|/* Transmit Start Point */
end_comment

begin_define
define|#
directive|define
name|LE_C80_XMTSP_MAX
value|3
end_define

begin_define
define|#
directive|define
name|LE_C80_XMTFW
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_comment
comment|/* Transmit FIFO Watermark */
end_comment

begin_define
define|#
directive|define
name|LE_C80_XMTFW_MAX
value|3
end_define

begin_define
define|#
directive|define
name|LE_C80_DMATC
value|0x00ff
end_define

begin_comment
comment|/* DMA transfer counter */
end_comment

begin_comment
comment|/* control and status register 116 (csr116) */
end_comment

begin_define
define|#
directive|define
name|LE_C116_PME_EN_OVR
value|0x0400
end_define

begin_comment
comment|/* PME_EN overwrite */
end_comment

begin_define
define|#
directive|define
name|LE_C116_LCDET
value|0x0200
end_define

begin_comment
comment|/* link change detected */
end_comment

begin_define
define|#
directive|define
name|LE_C116_LCMODE
value|0x0100
end_define

begin_comment
comment|/* link change wakeup mode */
end_comment

begin_define
define|#
directive|define
name|LE_C116_PMAT
value|0x0080
end_define

begin_comment
comment|/* pattern matched */
end_comment

begin_define
define|#
directive|define
name|LE_C116_EMPPLBA
value|0x0040
end_define

begin_comment
comment|/* magic packet physical logical 					   broadcast accept */
end_comment

begin_define
define|#
directive|define
name|LE_C116_MPMAT
value|0x0020
end_define

begin_comment
comment|/* magic packet match */
end_comment

begin_define
define|#
directive|define
name|LE_C116_MPPEN
value|0x0010
end_define

begin_comment
comment|/* magic packet pin enable */
end_comment

begin_define
define|#
directive|define
name|LE_C116_RST_POL
value|0x0001
end_define

begin_comment
comment|/* PHY_RST pin polarity */
end_comment

begin_comment
comment|/* control and status register 122 (csr122) */
end_comment

begin_define
define|#
directive|define
name|LE_C122_RCVALGN
value|0x0001
end_define

begin_comment
comment|/* receive packet align */
end_comment

begin_comment
comment|/* control and status register 124 (csr124) */
end_comment

begin_define
define|#
directive|define
name|LE_C124_RPA
value|0x0008
end_define

begin_comment
comment|/* runt packet accept */
end_comment

begin_comment
comment|/* control and status register 125 (csr125) */
end_comment

begin_define
define|#
directive|define
name|LE_C125_IPG
value|0xff00
end_define

begin_comment
comment|/* inter-packet gap */
end_comment

begin_define
define|#
directive|define
name|LE_C125_IFS1
value|0x00ff
end_define

begin_comment
comment|/* inter-frame spacing part 1 */
end_comment

begin_comment
comment|/* bus configuration register 0 (bcr0) */
end_comment

begin_define
define|#
directive|define
name|LE_B0_MSRDA
value|0xffff
end_define

begin_comment
comment|/* reserved locations */
end_comment

begin_comment
comment|/* bus configuration register 1 (bcr1) */
end_comment

begin_define
define|#
directive|define
name|LE_B1_MSWRA
value|0xffff
end_define

begin_comment
comment|/* reserved locations */
end_comment

begin_comment
comment|/* bus configuration register 2 (bcr2) */
end_comment

begin_define
define|#
directive|define
name|LE_B2_PHYSSELEN
value|0x2000
end_define

begin_comment
comment|/* enable writes to BCR18[4:3] */
end_comment

begin_define
define|#
directive|define
name|LE_B2_LEDPE
value|0x1000
end_define

begin_comment
comment|/* LED program enable */
end_comment

begin_define
define|#
directive|define
name|LE_B2_APROMWE
value|0x0100
end_define

begin_comment
comment|/* Address PROM Write Enable */
end_comment

begin_define
define|#
directive|define
name|LE_B2_INTLEVEL
value|0x0080
end_define

begin_comment
comment|/* 1 == edge triggered */
end_comment

begin_define
define|#
directive|define
name|LE_B2_DXCVRCTL
value|0x0020
end_define

begin_comment
comment|/* DXCVR control */
end_comment

begin_define
define|#
directive|define
name|LE_B2_DXCVRPOL
value|0x0010
end_define

begin_comment
comment|/* DXCVR polarity */
end_comment

begin_define
define|#
directive|define
name|LE_B2_EADISEL
value|0x0008
end_define

begin_comment
comment|/* EADI select */
end_comment

begin_define
define|#
directive|define
name|LE_B2_AWAKE
value|0x0004
end_define

begin_comment
comment|/* power saving mode select */
end_comment

begin_define
define|#
directive|define
name|LE_B2_ASEL
value|0x0002
end_define

begin_comment
comment|/* auto-select PORTSEL */
end_comment

begin_define
define|#
directive|define
name|LE_B2_XMAUSEL
value|0x0001
end_define

begin_comment
comment|/* reserved location */
end_comment

begin_comment
comment|/* bus configuration register 4 (bcr4) */
end_comment

begin_comment
comment|/* bus configuration register 5 (bcr5) */
end_comment

begin_comment
comment|/* bus configuration register 6 (bcr6) */
end_comment

begin_comment
comment|/* bus configuration register 7 (bcr7) */
end_comment

begin_comment
comment|/* bus configuration register 48 (bcr48) */
end_comment

begin_define
define|#
directive|define
name|LE_B4_LEDOUT
value|0x8000
end_define

begin_comment
comment|/* LED output active */
end_comment

begin_define
define|#
directive|define
name|LE_B4_LEDPOL
value|0x4000
end_define

begin_comment
comment|/* LED polarity */
end_comment

begin_define
define|#
directive|define
name|LE_B4_LEDDIS
value|0x2000
end_define

begin_comment
comment|/* LED disable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_100E
value|0x1000
end_define

begin_comment
comment|/* 100Mb/s enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_MPSE
value|0x0200
end_define

begin_comment
comment|/* magic packet status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_FDLSE
value|0x0100
end_define

begin_comment
comment|/* full-duplex link status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_PSE
value|0x0080
end_define

begin_comment
comment|/* pulse stretcher enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_LNKSE
value|0x0040
end_define

begin_comment
comment|/* link status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_RCVME
value|0x0020
end_define

begin_comment
comment|/* receive match status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_XMTE
value|0x0010
end_define

begin_comment
comment|/* transmit status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_POWER
value|0x0008
end_define

begin_comment
comment|/* power enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_RCVE
value|0x0004
end_define

begin_comment
comment|/* receive status enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_SPEED
value|0x0002
end_define

begin_comment
comment|/* high speed enable */
end_comment

begin_define
define|#
directive|define
name|LE_B4_COLE
value|0x0001
end_define

begin_comment
comment|/* collision status enable */
end_comment

begin_comment
comment|/* bus configuration register 9 (bcr9) */
end_comment

begin_define
define|#
directive|define
name|LE_B9_FDRPAD
value|0x0004
end_define

begin_comment
comment|/* full-duplex runt packet accept 					   disable */
end_comment

begin_define
define|#
directive|define
name|LE_B9_AUIFD
value|0x0002
end_define

begin_comment
comment|/* AUI full-duplex */
end_comment

begin_define
define|#
directive|define
name|LE_B9_FDEN
value|0x0001
end_define

begin_comment
comment|/* full-duplex enable */
end_comment

begin_comment
comment|/* bus configuration register 18 (bcr18) */
end_comment

begin_define
define|#
directive|define
name|LE_B18_ROMTMG
value|0xf000
end_define

begin_comment
comment|/* expansion rom timing */
end_comment

begin_define
define|#
directive|define
name|LE_B18_NOUFLO
value|0x0800
end_define

begin_comment
comment|/* no underflow on transmit */
end_comment

begin_define
define|#
directive|define
name|LE_B18_MEMCMD
value|0x0200
end_define

begin_comment
comment|/* memory read multiple enable */
end_comment

begin_define
define|#
directive|define
name|LE_B18_EXTREQ
value|0x0100
end_define

begin_comment
comment|/* extended request */
end_comment

begin_define
define|#
directive|define
name|LE_B18_DWIO
value|0x0080
end_define

begin_comment
comment|/* double-word I/O */
end_comment

begin_define
define|#
directive|define
name|LE_B18_BREADE
value|0x0040
end_define

begin_comment
comment|/* burst read enable */
end_comment

begin_define
define|#
directive|define
name|LE_B18_BWRITE
value|0x0020
end_define

begin_comment
comment|/* burst write enable */
end_comment

begin_define
define|#
directive|define
name|LE_B18_PHYSEL1
value|0x0010
end_define

begin_comment
comment|/* PHYSEL 1 */
end_comment

begin_define
define|#
directive|define
name|LE_B18_PHYSEL0
value|0x0008
end_define

begin_comment
comment|/* PHYSEL 0 */
end_comment

begin_comment
comment|/*	00	ex ROM/Flash	*/
end_comment

begin_comment
comment|/*	01	EADI/MII snoop	*/
end_comment

begin_comment
comment|/*	10	reserved	*/
end_comment

begin_comment
comment|/*	11	reserved	*/
end_comment

begin_define
define|#
directive|define
name|LE_B18_LINBC
value|0x0007
end_define

begin_comment
comment|/* reserved locations */
end_comment

begin_comment
comment|/* bus configuration register 19 (bcr19) */
end_comment

begin_define
define|#
directive|define
name|LE_B19_PVALID
value|0x8000
end_define

begin_comment
comment|/* EEPROM status valid */
end_comment

begin_define
define|#
directive|define
name|LE_B19_PREAD
value|0x4000
end_define

begin_comment
comment|/* EEPROM read command */
end_comment

begin_define
define|#
directive|define
name|LE_B19_EEDET
value|0x2000
end_define

begin_comment
comment|/* EEPROM detect */
end_comment

begin_define
define|#
directive|define
name|LE_B19_EEN
value|0x0010
end_define

begin_comment
comment|/* EEPROM port enable */
end_comment

begin_define
define|#
directive|define
name|LE_B19_ECS
value|0x0004
end_define

begin_comment
comment|/* EEPROM chip select */
end_comment

begin_define
define|#
directive|define
name|LE_B19_ESK
value|0x0002
end_define

begin_comment
comment|/* EEPROM serial clock */
end_comment

begin_define
define|#
directive|define
name|LE_B19_EDI
value|0x0001
end_define

begin_comment
comment|/* EEPROM data in */
end_comment

begin_define
define|#
directive|define
name|LE_B19_EDO
value|0x0001
end_define

begin_comment
comment|/* EEPROM data out */
end_comment

begin_comment
comment|/* bus configuration register 20 (bcr20) */
end_comment

begin_define
define|#
directive|define
name|LE_B20_APERREN
value|0x0400
end_define

begin_comment
comment|/* Advanced parity error handling */
end_comment

begin_define
define|#
directive|define
name|LE_B20_CSRPCNET
value|0x0200
end_define

begin_comment
comment|/* PCnet-style CSRs (0 = ILACC) */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSIZE32
value|0x0100
end_define

begin_comment
comment|/* Software Size 32-bit */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSTYLE
value|0x0007
end_define

begin_comment
comment|/* Software Style */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSTYLE_LANCE
value|0
end_define

begin_comment
comment|/* LANCE/PCnet-ISA (16-bit) */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSTYLE_ILACC
value|1
end_define

begin_comment
comment|/* ILACC (32-bit) */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSTYLE_PCNETPCI2
value|2
end_define

begin_comment
comment|/* PCnet-PCI (32-bit) */
end_comment

begin_define
define|#
directive|define
name|LE_B20_SSTYLE_PCNETPCI3
value|3
end_define

begin_comment
comment|/* PCnet-PCI II (32-bit) */
end_comment

begin_comment
comment|/* bus configuration register 25 (bcr25) */
end_comment

begin_define
define|#
directive|define
name|LE_B25_SRAM_SIZE
value|0x00ff
end_define

begin_comment
comment|/* SRAM size */
end_comment

begin_comment
comment|/* bus configuration register 26 (bcr26) */
end_comment

begin_define
define|#
directive|define
name|LE_B26_SRAM_BND
value|0x00ff
end_define

begin_comment
comment|/* SRAM boundary */
end_comment

begin_comment
comment|/* bus configuration register 27 (bcr27) */
end_comment

begin_define
define|#
directive|define
name|LE_B27_PTRTST
value|0x8000
end_define

begin_comment
comment|/* reserved for manuf. tests */
end_comment

begin_define
define|#
directive|define
name|LE_B27_LOLATRX
value|0x4000
end_define

begin_comment
comment|/* low latency receive */
end_comment

begin_define
define|#
directive|define
name|LE_B27_EBCS
value|0x0038
end_define

begin_comment
comment|/* expansion bus clock source */
end_comment

begin_comment
comment|/*	000	CLK pin		*/
end_comment

begin_comment
comment|/*	001	time base clock	*/
end_comment

begin_comment
comment|/*	010	EBCLK pin	*/
end_comment

begin_comment
comment|/*	011	reserved	*/
end_comment

begin_comment
comment|/*	1xx	reserved	*/
end_comment

begin_define
define|#
directive|define
name|LE_B27_CLK_FAC
value|0x0007
end_define

begin_comment
comment|/* clock factor */
end_comment

begin_comment
comment|/*	000	1		*/
end_comment

begin_comment
comment|/*	001	1/2		*/
end_comment

begin_comment
comment|/*	010	reserved	*/
end_comment

begin_comment
comment|/*	011	1/4		*/
end_comment

begin_comment
comment|/*	1xx	reserved	*/
end_comment

begin_comment
comment|/* bus configuration register 28 (bcr28) */
end_comment

begin_define
define|#
directive|define
name|LE_B28_EADDRL
value|0xffff
end_define

begin_comment
comment|/* expansion port address lower */
end_comment

begin_comment
comment|/* bus configuration register 29 (bcr29) */
end_comment

begin_define
define|#
directive|define
name|LE_B29_FLASH
value|0x8000
end_define

begin_comment
comment|/* flash access */
end_comment

begin_define
define|#
directive|define
name|LE_B29_LAAINC
value|0x4000
end_define

begin_comment
comment|/* lower address auto increment */
end_comment

begin_define
define|#
directive|define
name|LE_B29_EPADDRU
value|0x0007
end_define

begin_comment
comment|/* expansion port address upper */
end_comment

begin_comment
comment|/* bus configuration register 30 (bcr30) */
end_comment

begin_define
define|#
directive|define
name|LE_B30_EBDATA
value|0xffff
end_define

begin_comment
comment|/* expansion bus data port */
end_comment

begin_comment
comment|/* bus configuration register 31 (bcr31) */
end_comment

begin_define
define|#
directive|define
name|LE_B31_STVAL
value|0xffff
end_define

begin_comment
comment|/* software timer value */
end_comment

begin_comment
comment|/* bus configuration register 32 (bcr32) */
end_comment

begin_define
define|#
directive|define
name|LE_B32_ANTST
value|0x8000
end_define

begin_comment
comment|/* reserved for manuf. tests */
end_comment

begin_define
define|#
directive|define
name|LE_B32_MIIPD
value|0x4000
end_define

begin_comment
comment|/* MII PHY Detect (manuf. tests) */
end_comment

begin_define
define|#
directive|define
name|LE_B32_FMDC
value|0x3000
end_define

begin_comment
comment|/* fast management data clock */
end_comment

begin_define
define|#
directive|define
name|LE_B32_APEP
value|0x0800
end_define

begin_comment
comment|/* auto-poll PHY */
end_comment

begin_define
define|#
directive|define
name|LE_B32_APDW
value|0x0700
end_define

begin_comment
comment|/* auto-poll dwell time */
end_comment

begin_define
define|#
directive|define
name|LE_B32_DANAS
value|0x0080
end_define

begin_comment
comment|/* disable autonegotiation */
end_comment

begin_define
define|#
directive|define
name|LE_B32_XPHYRST
value|0x0040
end_define

begin_comment
comment|/* PHY reset */
end_comment

begin_define
define|#
directive|define
name|LE_B32_XPHYANE
value|0x0020
end_define

begin_comment
comment|/* PHY autonegotiation enable */
end_comment

begin_define
define|#
directive|define
name|LE_B32_XPHYFD
value|0x0010
end_define

begin_comment
comment|/* PHY full-duplex */
end_comment

begin_define
define|#
directive|define
name|LE_B32_XPHYSP
value|0x0008
end_define

begin_comment
comment|/* PHY speed */
end_comment

begin_define
define|#
directive|define
name|LE_B32_MIIILP
value|0x0002
end_define

begin_comment
comment|/* MII internal loopback */
end_comment

begin_comment
comment|/* bus configuration register 33 (bcr33) */
end_comment

begin_define
define|#
directive|define
name|LE_B33_SHADOW
value|0x8000
end_define

begin_comment
comment|/* shadow enable */
end_comment

begin_define
define|#
directive|define
name|LE_B33_MII_SEL
value|0x4000
end_define

begin_comment
comment|/* MII selected */
end_comment

begin_define
define|#
directive|define
name|LE_B33_ACOMP
value|0x2000
end_define

begin_comment
comment|/* internal PHY autonegotiation comp */
end_comment

begin_define
define|#
directive|define
name|LE_B33_LINK
value|0x1000
end_define

begin_comment
comment|/* link status */
end_comment

begin_define
define|#
directive|define
name|LE_B33_FDX
value|0x0800
end_define

begin_comment
comment|/* full-duplex */
end_comment

begin_define
define|#
directive|define
name|LE_B33_SPEED
value|0x0400
end_define

begin_comment
comment|/* 1 == high speed */
end_comment

begin_define
define|#
directive|define
name|LE_B33_PHYAD
value|0x03e0
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|PHYAD_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|LE_B33_REGAD
value|0x001f
end_define

begin_comment
comment|/* register address */
end_comment

begin_comment
comment|/* bus configuration register 34 (bcr34) */
end_comment

begin_define
define|#
directive|define
name|LE_B34_MIIMD
value|0xffff
end_define

begin_comment
comment|/* MII data */
end_comment

begin_comment
comment|/* bus configuration register 49 (bcr49) */
end_comment

begin_define
define|#
directive|define
name|LE_B49_PCNET
value|0x8000
end_define

begin_comment
comment|/* PCnet mode - Must Be One */
end_comment

begin_define
define|#
directive|define
name|LE_B49_PHYSEL_D
value|0x0300
end_define

begin_comment
comment|/* PHY_SEL_Default */
end_comment

begin_define
define|#
directive|define
name|LE_B49_PHYSEL_L
value|0x0010
end_define

begin_comment
comment|/* PHY_SEL_Lock */
end_comment

begin_define
define|#
directive|define
name|LE_B49_PHYSEL
value|0x0003
end_define

begin_comment
comment|/* PHYSEL */
end_comment

begin_comment
comment|/*	00	10baseT PHY	*/
end_comment

begin_comment
comment|/*	01	HomePNA PHY	*/
end_comment

begin_comment
comment|/*	10	external PHY	*/
end_comment

begin_comment
comment|/*	11	reserved	*/
end_comment

begin_comment
comment|/* Initialization block (mode) */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PROM
value|0x8000
end_define

begin_comment
comment|/* promiscuous mode */
end_comment

begin_comment
comment|/*			0x7f80		   reserved, must be zero */
end_comment

begin_comment
comment|/* 0x4000 - 0x0080 are not available on LANCE 7990. */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRCVBC
value|0x4000
end_define

begin_comment
comment|/* disable receive brodcast */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRCVPA
value|0x2000
end_define

begin_comment
comment|/* disable physical address detection */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DLNKTST
value|0x1000
end_define

begin_comment
comment|/* disable link status */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DAPC
value|0x0800
end_define

begin_comment
comment|/* disable automatic polarity correction */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_MENDECL
value|0x0400
end_define

begin_comment
comment|/* MENDEC loopback mode */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_LRTTSEL
value|0x0200
end_define

begin_comment
comment|/* lower receive threshold / 					   transmit mode selection */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PSEL1
value|0x0100
end_define

begin_comment
comment|/* port selection bit1 */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_PSEL0
value|0x0080
end_define

begin_comment
comment|/* port selection bit0 */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_INTL
value|0x0040
end_define

begin_comment
comment|/* internal loopback */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRTY
value|0x0020
end_define

begin_comment
comment|/* disable retry */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_COLL
value|0x0010
end_define

begin_comment
comment|/* force a collision */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DTCR
value|0x0008
end_define

begin_comment
comment|/* disable transmit CRC */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_LOOP
value|0x0004
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DTX
value|0x0002
end_define

begin_comment
comment|/* disable transmitter */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_DRX
value|0x0001
end_define

begin_comment
comment|/* disable receiver */
end_comment

begin_define
define|#
directive|define
name|LE_MODE_NORMAL
value|0
end_define

begin_comment
comment|/* none of the above */
end_comment

begin_comment
comment|/*  * Chip ID (CSR88 IDL, CSR89 IDU) values for various AMD PCnet parts  */
end_comment

begin_define
define|#
directive|define
name|CHIPID_MANFID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x3ff)
end_define

begin_define
define|#
directive|define
name|CHIPID_PARTID
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0xffff)
end_define

begin_define
define|#
directive|define
name|CHIPID_VER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x7)
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c960
value|0x0003
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c961
value|0x2260
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c961A
value|0x2261
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c965
value|0x2430
end_define

begin_comment
comment|/* yes, these... */
end_comment

begin_define
define|#
directive|define
name|PARTID_Am79c970
value|0x2430
end_define

begin_comment
comment|/* ...are the same */
end_comment

begin_define
define|#
directive|define
name|PARTID_Am79c970A
value|0x2621
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c971
value|0x2623
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c972
value|0x2624
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c973
value|0x2625
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c978
value|0x2626
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c975
value|0x2627
end_define

begin_define
define|#
directive|define
name|PARTID_Am79c976
value|0x2628
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_LE_LANCEREG_H_ */
end_comment

end_unit

