begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	FreeBSD: src/sys/dev/pccard/pccarddevs,v 1.30 2002/04/02 05:46:10 imp Exp   */
end_comment

begin_comment
comment|/* $NetBSD: pcmciadevs,v 1.163 2002/03/04 16:41:50 martin Exp $ */
end_comment

begin_comment
comment|/* $OpenBSD: pcmciadevs,v 1.85 2002/03/29 18:54:07 millert Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * List of known PCMCIA vendors, sorted by numeric ID.  */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_FUJITSU
value|0x0004
end_define

begin_comment
comment|/* Fujitsu Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PANASONIC
value|0x0032
end_define

begin_comment
comment|/* Matsushita Electric Industrial Co. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SANDISK
value|0x0045
end_define

begin_comment
comment|/* Sandisk Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NEWMEDIA
value|0x0057
end_define

begin_comment
comment|/* New Media Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_INTEL
value|0x0089
end_define

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_IBM
value|0x00a4
end_define

begin_comment
comment|/* IBM Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_3COM
value|0x0101
end_define

begin_comment
comment|/* 3Com Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_MEGAHERTZ
value|0x0102
end_define

begin_comment
comment|/* Megahertz Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SOCKET
value|0x0104
end_define

begin_comment
comment|/* Socket Communications */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_TDK
value|0x0105
end_define

begin_comment
comment|/* TDK Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_XIRCOM
value|0x0105
end_define

begin_comment
comment|/* Xircom */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SMC
value|0x0108
end_define

begin_comment
comment|/* Standard Microsystems Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_MOTOROLA
value|0x0109
end_define

begin_comment
comment|/* Motorola Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NI
value|0x010b
end_define

begin_comment
comment|/* National Instruments */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_USROBOTICS
value|0x0115
end_define

begin_comment
comment|/* US Robotics Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_OLICOM
value|0x0121
end_define

begin_comment
comment|/* Olicom */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PROXIM
value|0x0126
end_define

begin_comment
comment|/* Proxim */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_MEGAHERTZ2
value|0x0128
end_define

begin_comment
comment|/* Megahertz Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ADAPTEC
value|0x012f
end_define

begin_comment
comment|/* Adaptec Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_QUATECH
value|0x0137
end_define

begin_comment
comment|/* Quatech */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_COMPAQ
value|0x0138
end_define

begin_comment
comment|/* Compaq */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_DLINK_2
value|0x0143
end_define

begin_comment
comment|/* D-Link */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LINKSYS
value|0x0149
end_define

begin_comment
comment|/* Linksys Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NETGEAR
value|0x0149
end_define

begin_comment
comment|/* Netgear */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SIMPLETECH
value|0x014d
end_define

begin_comment
comment|/* Simple Technology */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SYMBOL2
value|0x014d
end_define

begin_comment
comment|/* Symbol */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LUCENT
value|0x0156
end_define

begin_comment
comment|/* Lucent Technologies */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_AIRONET
value|0x015f
end_define

begin_comment
comment|/* Aironet Wireless Communications */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ERICSSON
value|0x016b
end_define

begin_comment
comment|/* Ericsson */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PSION
value|0x016c
end_define

begin_comment
comment|/* Psion */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_COMPAQ2
value|0x0183
end_define

begin_comment
comment|/* Compaq */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_KINGSTON
value|0x0186
end_define

begin_comment
comment|/* Kingston */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_DAYNA
value|0x0194
end_define

begin_comment
comment|/* Dayna Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_RAYTHEON
value|0x01a6
end_define

begin_comment
comment|/* Raytheon */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_IODATA
value|0x01bf
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BAY
value|0x01eb
end_define

begin_comment
comment|/* Bay Networks */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_FARALLON
value|0x0200
end_define

begin_comment
comment|/* Farallon Communications */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_TELECOMDEVICE
value|0x021b
end_define

begin_comment
comment|/* Telecom Device */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NOKIA
value|0x023d
end_define

begin_comment
comment|/* Nokia Communications */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SAMSUNG
value|0x0250
end_define

begin_comment
comment|/* Samsung */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_HWN
value|0x0261
end_define

begin_comment
comment|/* Home Wireless Networks */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SYMBOL
value|0x026c
end_define

begin_comment
comment|/* Symbol */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BUFFALO
value|0x026f
end_define

begin_comment
comment|/* BUFFALO (Melco Corporation) */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LINKSYS2
value|0x0274
end_define

begin_comment
comment|/* The Linksys Group */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_IODATA2
value|0x028a
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NWN
value|0x0602
end_define

begin_comment
comment|/* No Wires Needed */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BREEZECOM
value|0x0a02
end_define

begin_comment
comment|/* BreezeCOM */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NEWMEDIA2
value|0x10cd
end_define

begin_comment
comment|/* NewMedia */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LASAT
value|0x3401
end_define

begin_comment
comment|/* Lasat Communications A/S */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BONDWELL
value|0x3b01
end_define

begin_comment
comment|/* Bondwell */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LEXARMEDIA
value|0x4e01
end_define

begin_comment
comment|/* Lexar Media */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ARCHOS
value|0x5241
end_define

begin_comment
comment|/* Archos */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_DUAL
value|0x890f
end_define

begin_comment
comment|/* Dual */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_EDIMAX
value|0x890f
end_define

begin_comment
comment|/* Edimax Technology Inc. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_COMPEX
value|0x8a01
end_define

begin_comment
comment|/* Compex Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_MELCO
value|0x8a01
end_define

begin_comment
comment|/* Melco Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ZONET
value|0x8a01
end_define

begin_comment
comment|/* Zonet Technology Inc. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_CONTEC
value|0xc001
end_define

begin_comment
comment|/* Contec */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_MACNICA
value|0xc00b
end_define

begin_comment
comment|/* MACNICA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ROLAND
value|0xc00c
end_define

begin_comment
comment|/* Roland */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_COREGA
value|0xc00f
end_define

begin_comment
comment|/* Corega K.K. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ALLIEDTELESIS
value|0xc00f
end_define

begin_comment
comment|/* Allied Telesis K.K. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_HAGIWARASYSCOM
value|0xc012
end_define

begin_comment
comment|/* Hagiwara SYS-COM */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_RATOC
value|0xc015
end_define

begin_comment
comment|/* RATOC System Inc. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_EMTAC
value|0xc250
end_define

begin_comment
comment|/* EMTAC Technology Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ELSA
value|0xd601
end_define

begin_comment
comment|/* Elsa */
end_comment

begin_comment
comment|/*  * List of known products.  Grouped by vendor, sorted by number within the  * group.  */
end_comment

begin_comment
comment|/* 3COM Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CRWE737A
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CRWE737A
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CRWE737A
value|"3Com AirConnect Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CXM056BNW
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CXM056BNW
value|0x002f
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CXM056BNW
value|"3Com/NoteWorthy 3CXM056-BNW 56K Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CXEM556
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CXEM556
value|0x0035
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CXEM556
value|"3Com/Megahertz 3CXEM556 Ethernet/Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CXEM556INT
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CXEM556INT
value|0x003d
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CXEM556INT
value|"3Com/Megahertz 3CXEM556-INT Ethernet/Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CCFEM556BI
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CCFEM556BI
value|0x0556
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CCFEM556BI
value|"3Com/Megahertz 3CCFEM556BI Ethernet/Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3C562
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3C562
value|0x0562
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3C562
value|"3Com 3c562 33.6 Modem/10Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3C589
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3C589
value|0x0589
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3C589
value|"3Com 3c589 10Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3C574
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3C574
value|0x0574
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3C574
value|"3Com 3c574-TX 10/100Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3C1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3C1
value|0x0cf1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3C1
value|"3Com Megahertz 3C1 10Mbps LAN CF+ Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_3COM_3CRWE62092A
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_3COM_3CRWE62092A
value|0x2092
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_3COM_3CRWE62092A
value|"3Com 3CRWE62092A Wireless LAN"
end_define

begin_comment
comment|/* Adaptec Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ADAPTEC_APA1460
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ADAPTEC_APA1460
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ADAPTEC_APA1460
value|"Adaptec APA-1460 SlimSCSI"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ADAPTEC_APA1460A
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ADAPTEC_APA1460A
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ADAPTEC_APA1460A
value|"Adaptec APA-1460A SlimSCSI"
end_define

begin_comment
comment|/* Aironet */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_AIRONET_PC4500
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_AIRONET_PC4500
value|0x0005
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_AIRONET_PC4500
value|"Aironet PC4500 Wireless LAN Adapter"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_AIRONET_PC4800
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_AIRONET_PC4800
value|0x0007
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_AIRONET_PC4800
value|"Aironet PC4800 Wireless LAN Adapter"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_AIRONET_350
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_AIRONET_350
value|0x000a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_AIRONET_350
value|"Aironet 350 Wireless LAN Adapter"
end_define

begin_comment
comment|/* Allied Telesis K.K. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ALLIEDTELESIS_LA_PCM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ALLIEDTELESIS_LA_PCM
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ALLIEDTELESIS_LA_PCM
value|"Allied Telesis LA-PCM"
end_define

begin_comment
comment|/* Archos */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ARCHOS_ARC_ATAPI
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ARCHOS_ARC_ATAPI
value|0x0043
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ARCHOS_ARC_ATAPI
value|"MiniCD"
end_define

begin_comment
comment|/* Bay Networks */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_BAY_STACK_650
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BAY_STACK_650
value|0x0804
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BAY_STACK_650
value|"BayStack 650 Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_BAY_SURFER_PRO
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BAY_SURFER_PRO
value|0x0806
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BAY_SURFER_PRO
value|"AirSurfer Pro Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_BAY_STACK_660
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BAY_STACK_660
value|0x0807
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BAY_STACK_660
value|"BayStack 660 Wireless LAN"
end_define

begin_comment
comment|/* Bondwell */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_BONDWELL_B236
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BONDWELL_B236
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BONDWELL_B236
value|"Game Card Joystick"
end_define

begin_comment
comment|/* BreezeCOM */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_BREEZECOM_BREEZENET
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BREEZECOM_BREEZENET
value|0x0102
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BREEZECOM_BREEZENET
value|"BreezeCOM BreezeNET"
end_define

begin_comment
comment|/* BUFFALO */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_BUFFALO_WLI_PCM_S11
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BUFFALO_WLI_PCM_S11
value|0x0305
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BUFFALO_WLI_PCM_S11
value|"BUFFALO AirStation 11Mbps WLAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_BUFFALO_WLI_CF_S11G
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BUFFALO_WLI_CF_S11G
value|0x030b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BUFFALO_WLI_CF_S11G
value|"BUFFALO AirStation 11Mbps CF WLAN"
end_define

begin_comment
comment|/* Compaq Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_COMPAQ_NC5004
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COMPAQ_NC5004
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COMPAQ_NC5004
value|"Compaq Agency NC5004 Wireless Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COMPAQ2_CPQ_10_100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COMPAQ2_CPQ_10_100
value|0x010a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COMPAQ2_CPQ_10_100
value|"Compaq Netelligent 10/100 Ethernet"
end_define

begin_comment
comment|/* Compex Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_COMPEX_AMP_WIRELESS
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COMPEX_AMP_WIRELESS
value|0x0066
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COMPEX_AMP_WIRELESS
value|"AMP"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COMPEX_LINKPORT_ENET_B
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COMPEX_LINKPORT_ENET_B
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COMPEX_LINKPORT_ENET_B
value|"Compex Linkport ENET-B Ethernet"
end_define

begin_comment
comment|/* Contec C-NET(PC) */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_CONTEC_CNETPC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_CONTEC_CNETPC
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_CONTEC_CNETPC
value|"Contec C-NET(PC)C"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_CONTEC_FX_DS110_PCC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_CONTEC_FX_DS110_PCC
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_CONTEC_FX_DS110_PCC
value|"Contec FLEXLAN/FX-DS110-PCC"
end_define

begin_comment
comment|/* Dayna Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_DAYNA_COMMUNICARD_E_1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DAYNA_COMMUNICARD_E_1
value|0x002d
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DAYNA_COMMUNICARD_E_1
value|"Dayna CommuniCard E"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_DAYNA_COMMUNICARD_E_2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DAYNA_COMMUNICARD_E_2
value|0x002f
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DAYNA_COMMUNICARD_E_2
value|"Dayna CommuniCard E"
end_define

begin_comment
comment|/* DIGITAL Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_DIGITAL_MOBILE_MEDIA_CDROM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DIGITAL_MOBILE_MEDIA_CDROM
value|0x0d00
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DIGITAL_MOBILE_MEDIA_CDROM
value|"Digital Mobile Media CD-ROM"
end_define

begin_comment
comment|/* D-Link Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_DLINK_2_DMF560TX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DLINK_2_DMF560TX
value|0xc0ab
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DLINK_2_DMF560TX
value|"D-Link DMF-650TX"
end_define

begin_comment
comment|/* Dual */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_DUAL_NE2000
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DUAL_NE2000
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DUAL_NE2000
value|"Dual NE2000"
end_define

begin_comment
comment|/* Edimax Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_EDIMAX_EP4000A
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_EDIMAX_EP4000A
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_EDIMAX_EP4000A
value|"Edimax EP4000A"
end_define

begin_comment
comment|/* ELSA Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ELSA_MC2_IEEE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ELSA_MC2_IEEE
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ELSA_MC2_IEEE
value|"AirLancer MC-2 IEEE"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ELSA_XI300_IEEE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ELSA_XI300_IEEE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ELSA_XI300_IEEE
value|"XI300 Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ELSA_XI800_IEEE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ELSA_XI800_IEEE
value|0x0004
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ELSA_XI800_IEEE
value|"XI800 CF Wireless LAN"
end_define

begin_comment
comment|/* EMTAC */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_EMTAC_WLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_EMTAC_WLAN
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_EMTAC_WLAN
value|"EMTAC A2424i 11Mbps WLAN Card"
end_define

begin_comment
comment|/* Ericsson */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ERICSSON_WIRELESSLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ERICSSON_WIRELESSLAN
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ERICSSON_WIRELESSLAN
value|"DSSS Wireless LAN PC Card"
end_define

begin_comment
comment|/* Farallon */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_FARALLON_SKYLINE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FARALLON_SKYLINE
value|0x0a01
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FARALLON_SKYLINE
value|"SkyLINE Wireless"
end_define

begin_comment
comment|/* Fujutsu Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_SCSI600
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_SCSI600
value|0x0401
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_SCSI600
value|"Fujitsu SCSI 600 Interface"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_LA10S
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_LA10S
value|0x1003
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_LA10S
value|"Fujitsu Compact Flash Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_LA501
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_LA501
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_LA501
value|"Fujitsu Towa LA501 Ethernet"
end_define

begin_comment
comment|/* Home Wireless Networks */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_HWN_AIRWAY80211
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_HWN_AIRWAY80211
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_HWN_AIRWAY80211
value|"HWN Airway Wireless PCMCIA Card"
end_define

begin_comment
comment|/* IBM Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_MICRODRIVE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_MICRODRIVE
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_MICRODRIVE
value|"IBM Microdrive"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_3270
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_3270
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_3270
value|"IBM 3270 Emulation"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_INFOMOVER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_INFOMOVER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_INFOMOVER
value|"IBM InfoMover"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_5250
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_5250
value|0x000b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_5250
value|"IBM 5250 Emulation"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_TROPIC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_TROPIC
value|0x001e
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_TROPIC
value|"IBM Token Ring 4/16"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_SCSI
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_SCSI
value|0x0026
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_SCSI
value|"IBM SCSI PCMCIA"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_PORTABLE_CDROM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_PORTABLE_CDROM
value|0x002d
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_PORTABLE_CDROM
value|"IBM PCMCIA Portable CD-ROM Drive"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_HOME_AND_AWAY
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_HOME_AND_AWAY
value|0x002e
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_HOME_AND_AWAY
value|"IBM Home and Away Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_WIRELESS_LAN_ENTRY
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_WIRELESS_LAN_ENTRY
value|0x0032
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_WIRELESS_LAN_ENTRY
value|"IBM Wireless LAN Entry"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_SMART_CAPTURE_II
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_SMART_CAPTURE_II
value|0x003c
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_SMART_CAPTURE_II
value|"IBM Smart Capture Card II"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IBM_ETHERJET
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IBM_ETHERJET
value|0x003f
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IBM_ETHERJET
value|"IBM EtherJet Ethernet"
end_define

begin_comment
comment|/* Intel Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_INTEL_PRO_WLAN_2011
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_INTEL_PRO_WLAN_2011
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_INTEL_PRO_WLAN_2011
value|"Intel PRO/Wireless 2011 LAN PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_INTEL_EEPRO100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_INTEL_EEPRO100
value|0x010a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_INTEL_EEPRO100
value|"Intel EtherExpress PRO/100"
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_IODATA_PCLATE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IODATA_PCLATE
value|0x2216
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IODATA_PCLATE
value|"I-O DATA PCLA/TE"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IODATA2_WNB11PCM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IODATA2_WNB11PCM
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IODATA2_WNB11PCM
value|"I-O DATA WN-B11/PCM"
end_define

begin_comment
comment|/* Kingston Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_KINGSTON_KNE2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_KINGSTON_KNE2
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_KINGSTON_KNE2
value|"Kingston KNE-PC2 Ethernet"
end_define

begin_comment
comment|/* Lasat Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_LASAT_CREDIT_288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LASAT_CREDIT_288
value|0x2811
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LASAT_CREDIT_288
value|"Lasat Credit 288 Modem"
end_define

begin_comment
comment|/* Lexar Media */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_LEXARMEDIA_COMPACTFLASH
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LEXARMEDIA_COMPACTFLASH
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LEXARMEDIA_COMPACTFLASH
value|"Lexar Media CompactFlash"
end_define

begin_comment
comment|/* Linksys corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_TRUST_COMBO_ECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_TRUST_COMBO_ECARD
value|0x021b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_TRUST_COMBO_ECARD
value|"Trust (Linksys) Combo EthernetCard"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_ETHERFAST
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_ETHERFAST
value|0x0230
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_ETHERFAST
value|"Linksys Etherfast 10/100 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_ECARD_1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_ECARD_1
value|0x0265
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_ECARD_1
value|"Linksys EthernetCard or D-Link DE-650"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_COMBO_ECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_COMBO_ECARD
value|0xc1ab
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_COMBO_ECARD
value|"Linksys Combo EthernetCard"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS2_IWN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS2_IWN
value|0x1612
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS2_IWN
value|"Instant Wireless Network PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS2_IWN2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS2_IWN2
value|0x1613
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS2_IWN2
value|"Instant Wireless Network PC Card"
end_define

begin_comment
comment|/* Lucent WaveLAN/IEEE */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_LUCENT_WAVELAN_IEEE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LUCENT_WAVELAN_IEEE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LUCENT_WAVELAN_IEEE
value|"WaveLAN/IEEE"
end_define

begin_comment
comment|/* MACNICA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_MACNICA_ME1_JEIDA
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MACNICA_ME1_JEIDA
value|0x3300
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MACNICA_ME1_JEIDA
value|"MACNICA ME1 for JEIDA"
end_define

begin_comment
comment|/* Megahertz Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ_XJEM3336
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ_XJEM3336
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ_XJEM3336
value|"Megahertz X-JACK Ethernet Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ_XJ4288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ_XJ4288
value|0x0023
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ_XJ4288
value|"Megahertz XJ4288 Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ_XJ4336
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ_XJ4336
value|0x0027
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ_XJ4336
value|"Megahertz XJ4336 Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ_XJ5560
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ_XJ5560
value|0x0034
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ_XJ5560
value|"Megahertz X-JACK 56kbps Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ2_XJEM1144
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ2_XJEM1144
value|0x0101
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ2_XJEM1144
value|"Megahertz X-JACK"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ2_XJACK
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ2_XJACK
value|0x0103
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ2_XJACK
value|"Megahertz X-JACK Ethernet"
end_define

begin_comment
comment|/* Melco Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_MELCO_LPC3_TX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MELCO_LPC3_TX
value|0xc1ab
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MELCO_LPC3_TX
value|"Melco LPC3-TX"
end_define

begin_comment
comment|/* Motorola Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_MOTOROLA_POWER144
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MOTOROLA_POWER144
value|0x0105
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MOTOROLA_POWER144
value|"Motorola Power 14.4 Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MOTOROLA_PM100C
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MOTOROLA_PM100C
value|0x0302
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MOTOROLA_PM100C
value|"Motorola Personal Messenger 100C CDPD Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MOTOROLA_MONTANA_336
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MOTOROLA_MONTANA_336
value|0x0505
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MOTOROLA_MONTANA_336
value|"Motorola Montana 33.6"
end_define

begin_comment
comment|/* New Media Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_BASICS
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_BASICS
value|0x0019
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_BASICS
value|"New Media BASICS Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_LANSURFER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_LANSURFER
value|0x0021
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_LANSURFER
value|"NewMedia LANSurfer"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_LIVEWIRE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_LIVEWIRE
value|0x1004
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_LIVEWIRE
value|"NewMedia LiveWire Ethernet LAN Adapter"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_MULTIMEDIA
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_MULTIMEDIA
value|0x100b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_MULTIMEDIA
value|"NewMedia Multimedia"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_BUSTOASTER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_BUSTOASTER
value|0xc102
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_BUSTOASTER
value|"New Media BusToaster SCSI Host Adapter"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA_WAVJAMMER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA_WAVJAMMER
value|0xe005
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA_WAVJAMMER
value|"NewMedia .WAVjammer"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEWMEDIA2_BUSTOASTER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEWMEDIA2_BUSTOASTER
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEWMEDIA2_BUSTOASTER
value|"NewMedia BusToaster"
end_define

begin_comment
comment|/* Netgear */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_NETGEAR_FA410TXC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NETGEAR_FA410TXC
value|0x4530
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NETGEAR_FA410TXC
value|"Netgear FA410TXC"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NETGEAR_FA411
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NETGEAR_FA411
value|0x0411
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NETGEAR_FA411
value|"Netgear FA411"
end_define

begin_comment
comment|/* National Instruments */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_NI_PCMCIA_GPIB
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NI_PCMCIA_GPIB
value|0x4882
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NI_PCMCIA_GPIB
value|"National Instruments PCMCIA-GPIB"
end_define

begin_comment
comment|/* Nokia Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_NOKIA_C020_WLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NOKIA_C020_WLAN
value|0x20c0
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NOKIA_C020_WLAN
value|"Nokia C020 WLAN Card"
end_define

begin_comment
comment|/* No Wires Needed */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_NWN_WLAN_550
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NWN_WLAN_550
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NWN_WLAN_550
value|"NWN 550 WLAN"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NWN_WLAN_1148
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NWN_WLAN_1148
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NWN_WLAN_1148
value|"NWN 1148 WLAN"
end_define

begin_comment
comment|/* Olicom Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_OLICOM_TR
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_OLICOM_TR
value|0x2132
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_OLICOM_TR
value|"GoCard Token Ring 16/4"
end_define

begin_comment
comment|/* Panasonic Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_PANASONIC_KXLC002
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PANASONIC_KXLC002
value|0x0304
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PANASONIC_KXLC002
value|"Panasonic 4X CD-ROM Interface Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PANASONIC_KXLC003
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PANASONIC_KXLC003
value|0x0504
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PANASONIC_KXLC003
value|"Panasonic 8X CD-ROM Interface Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PANASONIC_KXLC005
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PANASONIC_KXLC005
value|0x2704
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PANASONIC_KXLC005
value|"Panasonic 16X CD-ROM Interface Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PANASONIC_KME
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PANASONIC_KME
value|0x2604
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PANASONIC_KME
value|"Panasonic CD-R/RW Interface"
end_define

begin_comment
comment|/* Proxim */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_PROXIM_ROAMABOUT_2400FH
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PROXIM_ROAMABOUT_2400FH
value|0x1058
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PROXIM_ROAMABOUT_2400FH
value|"Digital RoamAbout 2400FH"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PROXIM_RANGELAN2_7401
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PROXIM_RANGELAN2_7401
value|0x1158
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PROXIM_RANGELAN2_7401
value|"Proxim RangeLAN2 7401"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PROXIM_RANGELANDS_8430
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PROXIM_RANGELANDS_8430
value|0x8000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PROXIM_RANGELANDS_8430
value|"Proxim RangeLAN-DS 8430"
end_define

begin_comment
comment|/* Psion */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_PSION_GOLDCARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PSION_GOLDCARD
value|0x0020
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PSION_GOLDCARD
value|"Psion Gold Card"
end_define

begin_comment
comment|/* Quatech */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_QUATECH_DSP_225
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_QUATECH_DSP_225
value|0x0008
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_QUATECH_DSP_225
value|"Quatech Dual Serial Port"
end_define

begin_comment
comment|/* RATOC System Inc. Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_RATOC_REX_R280
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_RATOC_REX_R280
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_RATOC_REX_R280
value|"RATOC REX-R280"
end_define

begin_comment
comment|/* Raylink/WebGear */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_RAYTHEON_WLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_RAYTHEON_WLAN
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_RAYTHEON_WLAN
value|"WLAN Adapter"
end_define

begin_comment
comment|/* Roland */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ROLAND_SCP55
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ROLAND_SCP55
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ROLAND_SCP55
value|"Roland SCP-55"
end_define

begin_comment
comment|/* Samsung */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SAMSUNG_SWL_2000N
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SAMSUNG_SWL_2000N
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SAMSUNG_SWL_2000N
value|"Samsung MagicLAN SWL-2000N"
end_define

begin_comment
comment|/* Sandisk Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SANDISK_SDCFB
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SANDISK_SDCFB
value|0x0401
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SANDISK_SDCFB
value|"Sandisk CompactFlash Card"
end_define

begin_comment
comment|/* Simple Technology Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SIMPLETECH_COMMUNICATOR288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SIMPLETECH_COMMUNICATOR288
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SIMPLETECH_COMMUNICATOR288
value|"Simple Technology 28.8 Communicator"
end_define

begin_comment
comment|/* Simpletech ID also used by Symbol */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SIMPLETECH_SPECTRUM24
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SIMPLETECH_SPECTRUM24
value|0x801
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SIMPLETECH_SPECTRUM24
value|"Symbol Spectrum24 WLAN Adapter"
end_define

begin_comment
comment|/* Standard Microsystems Corporation Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SMC_8016
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SMC_8016
value|0x0105
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SMC_8016
value|"SMC 8016 EtherCard"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SMC_EZCARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SMC_EZCARD
value|0x8022
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SMC_EZCARD
value|"SMC EZCard 10 PCMCIA"
end_define

begin_comment
comment|/* Socket Communications Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_EA_ETHER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_EA_ETHER
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_EA_ETHER
value|"Socket Communications EA"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_LP_WLAN_CF
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_LP_WLAN_CF
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_LP_WLAN_CF
value|"Socket Communications Low Power WLAN Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_PAGECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_PAGECARD
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_PAGECARD
value|"Socket Communications PageCard"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_DUAL_RS232
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_DUAL_RS232
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_DUAL_RS232
value|"Socket Communications Dual RS232"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_LP_ETHER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_LP_ETHER
value|0x000d
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_LP_ETHER
value|"Socket Communications LP-E"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SOCKET_LP_ETHER_CF
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SOCKET_LP_ETHER_CF
value|0x0075
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SOCKET_LP_ETHER_CF
value|"Socket Communications LP-E CF"
end_define

begin_comment
comment|/* Symbol */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SYMBOL_LA4100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SYMBOL_LA4100
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SYMBOL_LA4100
value|"Symbol Spectrum24 LA4100 Series WLAN"
end_define

begin_comment
comment|/* TDK Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_TDK_LAK_CD011WL
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TDK_LAK_CD011WL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TDK_LAK_CD011WL
value|"TDK LAK-CD011WL"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_TDK_LAK_CD021BX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TDK_LAK_CD021BX
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TDK_LAK_CD021BX
value|"TDK LAK-CD021BX Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_TDK_LAK_CF010
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TDK_LAK_CF010
value|0x0900
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TDK_LAK_CF010
value|"TDK LAC-CF010"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_TDK_DFL9610
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TDK_DFL9610
value|0x0d0a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TDK_DFL9610
value|"TDK DFL9610 Ethernet& Digital Cellular"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_TDK_C6500012
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TDK_C6500012
value|0x410a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TDK_C6500012
value|"TDK ELSA MicroLink MC all"
end_define

begin_comment
comment|/* Telecom Device */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_TELECOMDEVICE_TCD_HPC100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TELECOMDEVICE_TCD_HPC100
value|0x0202
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TELECOMDEVICE_TCD_HPC100
value|"Telecom Device TCD-HPC100"
end_define

begin_comment
comment|/* US Robotics Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_USROBOTICS_WORLDPORT144
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_USROBOTICS_WORLDPORT144
value|0x3330
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_USROBOTICS_WORLDPORT144
value|"US Robotics WorldPort 14.4 Modem"
end_define

begin_comment
comment|/* Xircom Products */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CE
value|0x0108
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CE
value|"Xircom CreditCard Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CE3
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CE3
value|0x010a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CE3
value|"Xircom CreditCard 10/100 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CE2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CE2
value|0x010b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CE2
value|"Xircom CreditCard Ethernet II"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_XE2000
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_XE2000
value|0x0153
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_XE2000
value|"Xircom XE2000 10/100 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CNW_801
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CNW_801
value|0x0801
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CNW_801
value|"Xircom CreditCard Netwave (Canada)"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CNW_802
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CNW_802
value|0x0802
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CNW_802
value|"Xircom CreditCard Netwave (US)"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CT2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CT2
value|0x1101
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CT2
value|"Xircom CreditCard Token Ring II"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CEM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CEM
value|0x110a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CEM
value|"Xircom CreditCard Ethernet + Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_REM56
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_REM56
value|0x110a
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_REM56
value|"Xircom RealPort Ethernet 10/100 + Modem 56"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CEM28
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CEM28
value|0x110b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CEM28
value|"Xircom CreditCard Ethernet + Modem 28"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CEM33
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CEM33
value|0x110b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CEM33
value|"Xircom CreditCard Ethernet + Modem 33"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CEM56
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CEM56
value|0x110b
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CEM56
value|"Xircom CreditCard Ethernet + Modem 56"
end_define

begin_comment
comment|/* ZONET */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ZONET_ZEN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ZONET_ZEN
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ZONET_ZEN
value|"Zonet Zen 10/10"
end_define

begin_comment
comment|/*  * Cards we know only by their cis, sorted by name.  */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_AMBICOM
value|-1
end_define

begin_comment
comment|/* AmbiCom Inc */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ACCTON
value|-1
end_define

begin_comment
comment|/* ACCTON */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ADDTRON
value|-1
end_define

begin_comment
comment|/* Addtron */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_AMD
value|-1
end_define

begin_comment
comment|/* AMD */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BILLIONTON
value|-1
end_define

begin_comment
comment|/* Billionton Systems Inc. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_CNET
value|-1
end_define

begin_comment
comment|/* CNet */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_DIGITAL
value|-1
end_define

begin_comment
comment|/* Digital Equipment Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_DLINK
value|-1
end_define

begin_comment
comment|/* D-Link */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_EIGERLABS
value|-1
end_define

begin_comment
comment|/* Eiger labs,Inc. */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_EPSON
value|-1
end_define

begin_comment
comment|/* Seiko Epson Corporation */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_EXP
value|-1
end_define

begin_comment
comment|/* EXP Computer Inc */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_GEMTEK
value|-1
end_define

begin_comment
comment|/* Gem Tek */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ICOM
value|-1
end_define

begin_comment
comment|/* ICOM Inc */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_INTERSIL
value|-1
end_define

begin_comment
comment|/* Intersil */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_LANTECH
value|-1
end_define

begin_comment
comment|/* Lantech Computer Company */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NAKAGAWAMETAL
value|-1
end_define

begin_comment
comment|/* NAKAGAWA METAL */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_NDC
value|-1
end_define

begin_comment
comment|/* NDC */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PLANET
value|-1
end_define

begin_comment
comment|/* Planet */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PLANEX
value|-1
end_define

begin_comment
comment|/* Planex Communications Inc */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_PREMAX
value|-1
end_define

begin_comment
comment|/* Premax */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_RPTI
value|-1
end_define

begin_comment
comment|/* RPTI */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SVEC
value|-1
end_define

begin_comment
comment|/* SVEC/Hawking Technology */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_SYNERGY21
value|-1
end_define

begin_comment
comment|/* Synergy 21 */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_TEAC
value|-1
end_define

begin_comment
comment|/* TEAC */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_YEDATA
value|-1
end_define

begin_comment
comment|/* Y-E DATA */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_ZOOM
value|-1
end_define

begin_comment
comment|/* ZOOM */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_ACCTON_EN2212
value|{ "ACCTON", "EN2212", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ACCTON_EN2212
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ACCTON_EN2212
value|"Accton EN2212"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ADDTRON_AWP100
value|{ "Addtron", "AWP-100 Wireless PCMCIA", "Version 01.02", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ADDTRON_AWP100
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ADDTRON_AWP100
value|""
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_AMBICOM_AMB8002T
value|{ "AmbiCom Inc", "AMB8002T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_AMBICOM_AMB8002T
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_AMBICOM_AMB8002T
value|"AmbiCom AMB8002T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_AMD_AM79C930
value|{ "AMD", "Am79C930", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_AMD_AM79C930
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_AMD_AM79C930
value|"AMD Am79C930"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_BILLIONTON_LNT10TN
value|{ "PCMCIA", "LNT-10TN", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_BILLIONTON_LNT10TN
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_BILLIONTON_LNT10TN
value|"Billionton Systems Inc. LNT-10TN NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_CNET_NE2000
value|{ "CNet", "CN40BC Ethernet", "D", "NE2000" }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_CNET_NE2000
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_CNET_NE2000
value|"CNet CN40BC NE2000 Compatible"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_ETHER_PCC_T
value|{ "corega K.K.", "corega Ether PCC-T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_ETHER_PCC_T
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_ETHER_PCC_T
value|"Corega Ether PCC-T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_ETHER_PCC_TD
value|{ "corega K.K.", "corega Ether PCC-TD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_ETHER_PCC_TD
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_ETHER_PCC_TD
value|"Corega Ether PCC-TD"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_ETHER_II_PCC_T
value|{ "corega K.K.", "corega EtherII PCC-T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_ETHER_II_PCC_T
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_ETHER_II_PCC_T
value|"Corega EtherII PCC-T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_FAST_ETHER_PCC_TX
value|{ "corega K.K.", "corega FastEther PCC-TX", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_FAST_ETHER_PCC_TX
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_FAST_ETHER_PCC_TX
value|"Corega FastEther PCC-TX"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_FETHER_PCC_TXD
value|{ "corega K.K.", "corega FEther PCC-TXD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_FETHER_PCC_TXD
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_FETHER_PCC_TXD
value|"Corega FEther PCC-TXD"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_FETHER_PCC_TXF
value|{ "corega", "FEther PCC-TXF", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_FETHER_PCC_TXF
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_FETHER_PCC_TXF
value|"Corega FEther PCC-TXF"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_WIRELESS_LAN_PCC_11
value|{ "corega K.K.", "Wireless LAN PCC-11", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_WIRELESS_LAN_PCC_11
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_WIRELESS_LAN_PCC_11
value|"Corega Wireless LAN PCC-11"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_WIRELESS_LAN_PCCA_11
value|{ "corega K.K.", "Wireless LAN PCCA-11", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_WIRELESS_LAN_PCCA_11
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_WIRELESS_LAN_PCCA_11
value|"Corega Wireless LAN PCCA-11"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_COREGA_WIRELESS_LAN_PCCB_11
value|{ "corega_K.K.", "Wireless_LAN_PCCB-11", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_COREGA_WIRELESS_LAN_PCCB_11
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_COREGA_WIRELESS_LAN_PCCB_11
value|"Corega Wireless LAN PCCB-11"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_DIGITAL_DEPCMXX
value|{ "DIGITAL", "DEPCM-XX", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DIGITAL_DEPCMXX
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DIGITAL_DEPCMXX
value|"DEC DEPCM-BA"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_DLINK_DE650
value|{ "D-Link", "DE-650", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DLINK_DE650
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DLINK_DE650
value|"D-Link DE-650"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_DLINK_DE660
value|{ "D-Link", "DE-660", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DLINK_DE660
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DLINK_DE660
value|"D-Link DE-660"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_DLINK_DE660PLUS
value|{ "D-Link", "DE-660+", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_DLINK_DE660PLUS
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_DLINK_DE660PLUS
value|"D-Link DE-660+"
end_define

begin_comment
comment|/*  * vendor ID of EPX_AA2000 is Fujitsu (0x0004) and product ID is 0x2000, but  * it conflicts with Fujitsu Towa LA501 Ethernet.  */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_EIGERLABS_EPX_AA2000
value|{ "Eiger labs,Inc.", "EPX-AA2000 PC Sound Card", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_EIGERLABS_EPX_AA2000
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_EIGERLABS_EPX_AA2000
value|"EPX-AA2000 PC Sound Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_EPSON_EEN10B
value|{ "Seiko Epson Corp.", "Ethernet", "P/N: EEN10B Rev. 00", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_EPSON_EEN10B
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_EPSON_EEN10B
value|"Epson EEN10B"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_EXP_EXPMULTIMEDIA
value|{ "EXP   ", "PnPIDE", "F1", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_EXP_EXPMULTIMEDIA
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_EXP_EXPMULTIMEDIA
value|"EXP IDE/ATAPI DVD Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_FMV_J181
value|{ "PCMCIA MBH10302", "01", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_FMV_J181
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_FMV_J181
value|"FUJITSU FMV-J181 PCMCIA Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_FMV_J182
value|{ "FUJITSU", "LAN Card(FMV-J182)", "Ver.01", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_FMV_J182
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_FMV_J182
value|"FUJITSU FMV-J182 PCMCIA Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_FMV_J182A
value|{ "FUJITSU", "LAN Card(FMV-J182)", "Ver.02", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_FMV_J182A
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_FMV_J182A
value|"FUJITSU FMV-J182A PCMCIA Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_FUJITSU_ITCFJ182A
value|{ "FUJITSU", "LAN Card(ITCFJ182)", "Ver.01", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_FUJITSU_ITCFJ182A
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_FUJITSU_ITCFJ182A
value|"FUJITSU ITCFJ182A CompactCard"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_GEMTEK_WLAN
value|{ "Intersil", "PRISM 2_5 PCMCIA ADAPTER", "ISL37300P", "Eval-RevA" }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_GEMTEK_WLAN
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_GEMTEK_WLAN
value|"GEMTEK Prism2_5 WaveLAN Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ICOM_SL200
value|{ "Icom", "SL-200", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ICOM_SL200
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ICOM_SL200
value|"Icom SL-200"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_INTERSIL_PRISM2
value|{ "INTERSIL", "HFA384x/IEEE", "Version 01.02", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_INTERSIL_PRISM2
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_INTERSIL_PRISM2
value|"Intersil Prism II"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IODATA_CBIDE2
value|{ "IO DATA", "CBIDE2      ", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IODATA_CBIDE2
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IODATA_CBIDE2
value|"IO-DATA CBIDE2/16-bit mode"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_IODATA_PCLAT
value|{ "I-O DATA", "PCLA", "ETHERNET", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_IODATA_PCLAT
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_IODATA_PCLAT
value|"IO-DATA PCLA/T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LANTECH_FASTNETTX
value|{ "ASIX", "AX88190", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LANTECH_FASTNETTX
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LANTECH_FASTNETTX
value|"Lantech Fastnet/TX"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_ECARD_2
value|{ "LINKSYS", "E-CARD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_ECARD_2
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_ECARD_2
value|"Linksys E-Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_LINKSYS_PCM100
value|{ "Linksys", "EtherFast 10/100 Integrated PC Card (PCM100)", "Ver 1.0", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_LINKSYS_PCM100
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_LINKSYS_PCM100
value|""
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MEGAHERTZ_XJ2288
value|{ "MEGAHERTZ", "MODEM XJ2288", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MEGAHERTZ_XJ2288
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MEGAHERTZ_XJ2288
value|"Megahertz XJ2288 Modem"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_MELCO_LPC2_TX
value|{ "MELCO", "LPC2-TX", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_MELCO_LPC2_TX
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_MELCO_LPC2_TX
value|"Melco LPC2-TX"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NAKAGAWAMETAL_LNT10TN
value|{ "PCMCIA", "LNT-10TN", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NAKAGAWAMETAL_LNT10TN
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NAKAGAWAMETAL_LNT10TN
value|"NAKAGAWA METAL LNT-10TN NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NANOSPEED_PRISM2
value|{ "NANOSPEED", "HFA384x/IEEE", "Version 01.02", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NANOSPEED_PRISM2
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NANOSPEED_PRISM2
value|"NANOSPEED ROOT-RZ2000 WLAN Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NDC_ND5100_E
value|{ "NDC", "Ethernet", "A", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NDC_ND5100_E
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NDC_ND5100_E
value|"Sohoware ND5100E NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NEC_CMZ_RT_WP
value|{ "NEC", "Wireless Card CMZ-RT-WP", "Version 01.01", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NEC_CMZ_RT_WP
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NEC_CMZ_RT_WP
value|"NEC Wireless Card CMZ-RT-WP"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_NTT_ME_WLAN
value|{ "NTT-ME", "11Mbps Wireless LAN PC Card", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_NTT_ME_WLAN
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_NTT_ME_WLAN
value|"NTT-ME 11Mbps Wireless LAN PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PLANET_SMARTCOM2000
value|{ "PCMCIA", "UE2212", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PLANET_SMARTCOM2000
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PLANET_SMARTCOM2000
value|"Planet SmartCOM 2000"
end_define

begin_comment
comment|/*  * vendor ID of both FNW-3600-T and FNW-3700-T is LINKSYS (0x0149) and  * product ID is 0xc1ab, but it conflicts with LINKSYS Combo EthernetCard.  */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_PLANEX_FNW3600T
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PLANEX_FNW3600T
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PLANEX_FNW3600T
value|"Planex FNW-3600-T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PLANEX_FNW3700T
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PLANEX_FNW3700T
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PLANEX_FNW3700T
value|"Planex FNW-3700-T"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_RPTI_EP400
value|{ "RPTI LTD.", "EP400", "CISV100", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_RPTI_EP400
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_RPTI_EP400
value|"RPTI EP400"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_RPTI_EP401
value|{ "RPTI", "EP401 Ethernet NE2000 Compatible", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_RPTI_EP401
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_RPTI_EP401
value|"RPTI EP401"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_PREMAX_PE200
value|{ "PMX   ", "PE-200", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_PREMAX_PE200
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_PREMAX_PE200
value|"PreMax PE-200"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SIMPLETECH_SPECTRUM24_ALT
value|{ "Symbol Technologies", "LA4111 Spectrum24 Wireless LAN PC Card", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SIMPLETECH_SPECTRUM24_ALT
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SIMPLETECH_SPECTRUM24_ALT
value|"LA4111 Spectrum24 Wireless LAN PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SMC_2632W
value|{ "SMC", "SMC2632W", "Version 01.02", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SMC_2632W
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SMC_2632W
value|"SMC 2632 EZ Connect Wireless PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SVEC_COMBOCARD
value|{ "Ethernet", "Adapter", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SVEC_COMBOCARD
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SVEC_COMBOCARD
value|"SVEC/Hawking Tech. Combo Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SVEC_LANCARD
value|{ "SVEC", "FD605 PCMCIA EtherNet Card", "V1-1", NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SVEC_LANCARD
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SVEC_LANCARD
value|"SVEC PCMCIA Lan Card"
end_define

begin_comment
comment|/*  * vendor ID of PN650TX is LINKSYS (0x0149) and product ID is 0xc1ab, but  * it conflicts with LINKSYS Combo EthernetCard.  */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_CIS_SVEC_PN650TX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SVEC_PN650TX
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SVEC_PN650TX
value|"SVEC PN650TX 10/100 Dual Speed Fast Ethernet PC Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_SYNERGY21_S21810
value|{ "PCMCIA", "Ethernet", "A", "004743118001" }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_SYNERGY21_S21810
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_SYNERGY21_S21810
value|"Synergy 21 S21810+ NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_TEAC_IDECARDII
value|{ NULL, "NinjaATA-", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_TEAC_IDECARDII
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_TEAC_IDECARDII
value|"TEAC IDE Card/II"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_XIRCOM_CFE_10
value|{ "Xircom", "CompactCard Ethernet", "CFE-10", "1.00" }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_XIRCOM_CFE_10
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_XIRCOM_CFE_10
value|"Xircom CompactCard CFE-10"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_YEDATA_EXTERNAL_FDD
value|{ "Y-E DATA", "External FDD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_YEDATA_EXTERNAL_FDD
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_YEDATA_EXTERNAL_FDD
value|"Y-E DATA External FDD"
end_define

begin_define
define|#
directive|define
name|PCMCIA_CIS_ZOOM_AIR_4000
value|{ "Zoom", "Air-4000", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCMCIA_PRODUCT_ZOOM_AIR_4000
value|-1
end_define

begin_define
define|#
directive|define
name|PCMCIA_STR_ZOOM_AIR_4000
value|"Zoom Air-4000"
end_define

end_unit

