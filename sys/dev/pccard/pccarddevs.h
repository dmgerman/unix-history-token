begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	FreeBSD: src/sys/dev/pccard/pccarddevs,v 1.3 1999/11/29 20:53:36 imp Exp   */
end_comment

begin_comment
comment|/* $NetBSD: pcmciadevs,v 1.85 2000/03/22 21:39:57 mycroft Exp $  /*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * List of known PCMCIA vendors  */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_FUJITSU
value|0x0004
end_define

begin_comment
comment|/* Fujitsu Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_PANASONIC
value|0x0032
end_define

begin_comment
comment|/* Matsushita Electric Industrial Co. */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_SANDISK
value|0x0045
end_define

begin_comment
comment|/* Sandisk Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_NEWMEDIA
value|0x0057
end_define

begin_comment
comment|/* NewMedia Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_INTEL
value|0x0089
end_define

begin_comment
comment|/* Intel Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_IBM
value|0x00a4
end_define

begin_comment
comment|/* IBM Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_MOTOROLA
value|0x0109
end_define

begin_comment
comment|/* Motorola Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_3COM
value|0x0101
end_define

begin_comment
comment|/* 3Com Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_MEGAHERTZ
value|0x0102
end_define

begin_comment
comment|/* Megahertz Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_SOCKET
value|0x0104
end_define

begin_comment
comment|/* Socket Communications */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_TDK
value|0x0105
end_define

begin_comment
comment|/* TDK Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_XIRCOM
value|0x0105
end_define

begin_comment
comment|/* Xircom */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_SMC
value|0x0108
end_define

begin_comment
comment|/* Standard Microsystems Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_USROBOTICS
value|0x0115
end_define

begin_comment
comment|/* US Robotics Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_MEGAHERTZ2
value|0x0128
end_define

begin_comment
comment|/* Megahertz Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_ADAPTEC
value|0x012f
end_define

begin_comment
comment|/* Adaptec Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_COMPAQ
value|0x0138
end_define

begin_comment
comment|/* Compaq */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_LINKSYS
value|0x0149
end_define

begin_comment
comment|/* Linksys Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_SIMPLETECH
value|0x014d
end_define

begin_comment
comment|/* Simple Technology */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_LUCENT
value|0x0156
end_define

begin_comment
comment|/* Lucent Technologies */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_AIRONET
value|0x015f
end_define

begin_comment
comment|/* Aironet Wireless Communications */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_COMPAQ2
value|0x0183
end_define

begin_comment
comment|/* Compaq */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_DAYNA
value|0x0194
end_define

begin_comment
comment|/* Dayna Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_RAYTHEON
value|0x01a6
end_define

begin_comment
comment|/* Raytheon */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_IODATA
value|0x01bf
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_BAY
value|0x01eb
end_define

begin_comment
comment|/* Bay Networks */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_NOKIA
value|0x023d
end_define

begin_comment
comment|/* Nokia Communications */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_LASAT
value|0x3401
end_define

begin_comment
comment|/* Lasat Communications A/S */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_LEXARMEDIA
value|0x4e01
end_define

begin_comment
comment|/* Lexar Media */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_COMPEX
value|0x8a01
end_define

begin_comment
comment|/* Compex Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_MELCO
value|0x8a01
end_define

begin_comment
comment|/* Melco Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_CONTEC
value|0xc001
end_define

begin_comment
comment|/* Contec */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_COREGA
value|0xc00f
end_define

begin_comment
comment|/* Corega K.K. */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_ALLIEDTELESIS
value|0xc00f
end_define

begin_comment
comment|/* Allied Telesis K.K. */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_HAGIWARASYSCOM
value|0xc012
end_define

begin_comment
comment|/* Hagiwara SYS-COM */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_RATOC
value|0xc015
end_define

begin_comment
comment|/* RATOC System Inc. */
end_comment

begin_comment
comment|/*  * List of known products.  Grouped by vendor.  */
end_comment

begin_comment
comment|/* Adaptec Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_ADAPTEC_APA1460_1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_ADAPTEC_APA1460_1
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_ADAPTEC_APA1460_1
value|"Adaptec APA-1460/A SCSI Host Adapter"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_ADAPTEC_APA1460_2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_ADAPTEC_APA1460_2
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_ADAPTEC_APA1460_2
value|"Adaptec APA-1460/B SCSI Host Adapter"
end_define

begin_comment
comment|/* 3COM Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3C1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3C1
value|0x0cf1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3C1
value|"3Com Megahertz 3C1 10Mbps LAN CF+ Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3C562
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3C562
value|0x0562
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3C562
value|"3Com 3c562 33.6 Modem/10Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3C589
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3C589
value|0x0589
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3C589
value|"3Com 3c589 10Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3C574
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3C574
value|0x0574
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3C574
value|"3Com 3c574-TX 10/100Mbps Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3CXM056BNW
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3CXM056BNW
value|0x002f
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3CXM056BNW
value|"3Com/NoteWorthy 3CXM056-BNW 56K Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3CXEM556
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3CXEM556
value|0x0035
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3CXEM556
value|"3Com/Megahertz 3CXEM556 Ethernet/Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3CXEM556INT
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3CXEM556INT
value|0x003d
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3CXEM556INT
value|"3Com/Megahertz 3CXEM556-INT Ethernet/Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_3COM_3CCFEM556BI
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_3COM_3CCFEM556BI
value|0x0556
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_3COM_3CCFEM556BI
value|"3Com/Megahertz 3CCFEM556BI Ethernet/Modem"
end_define

begin_comment
comment|/* Compex Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_COMPEX_LINKPORT_ENET_B
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_COMPEX_LINKPORT_ENET_B
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_COMPEX_LINKPORT_ENET_B
value|"Compex Linkport ENET-B Ethernet"
end_define

begin_comment
comment|/* Lasat Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_LASAT_CREDIT_288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LASAT_CREDIT_288
value|0x2811
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LASAT_CREDIT_288
value|"Lasat Credit 288 Modem"
end_define

begin_comment
comment|/* Dayna Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_DAYNA_COMMUNICARD_E_1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DAYNA_COMMUNICARD_E_1
value|0x002d
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DAYNA_COMMUNICARD_E_1
value|"Dayna CommuniCard E"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_DAYNA_COMMUNICARD_E_2
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DAYNA_COMMUNICARD_E_2
value|0x002f
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DAYNA_COMMUNICARD_E_2
value|"Dayna CommuniCard E"
end_define

begin_comment
comment|/* DIGITAL Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_DIGITAL_MOBILE_MEDIA_CDROM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DIGITAL_MOBILE_MEDIA_CDROM
value|0x0d00
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DIGITAL_MOBILE_MEDIA_CDROM
value|"Digital Mobile Media CD-ROM"
end_define

begin_comment
comment|/* Fujutsu Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_FUJITSU_SCSI600
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_FUJITSU_SCSI600
value|0x0401
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_FUJITSU_SCSI600
value|"Fujitsu SCSI 600 Interface"
end_define

begin_comment
comment|/* Motorola Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_MOTOROLA_POWER144
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MOTOROLA_POWER144
value|0x0105
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MOTOROLA_POWER144
value|"Motorola Power 14.4 Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_MOTOROLA_PM100C
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MOTOROLA_PM100C
value|0x0302
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MOTOROLA_PM100C
value|"Motorola Personal Messenger 100C CDPD Modem"
end_define

begin_comment
comment|/* Fujitsu Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_FUJITSU_LA501
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_FUJITSU_LA501
value|0x2000
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_FUJITSU_LA501
value|"Fujitsu Towa LA501 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_FUJITSU_LA10S
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_FUJITSU_LA10S
value|0x1003
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_FUJITSU_LA10S
value|"Fujitsu Compact Flash Ethernet"
end_define

begin_comment
comment|/* IBM Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_3270
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_3270
value|0x0001
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_3270
value|"3270 Emulation"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_INFOMOVER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_INFOMOVER
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_INFOMOVER
value|"National Semiconductor InfoMover"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_5250
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_5250
value|0x000b
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_5250
value|"5250 Emulation"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_TROPIC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_TROPIC
value|0x001e
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_TROPIC
value|"Token Ring 4/16"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_HOME_AND_AWAY
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_HOME_AND_AWAY
value|0x002e
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_HOME_AND_AWAY
value|"IBM Home and Away Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_WIRELESS_LAN_ENTRY
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_WIRELESS_LAN_ENTRY
value|0x0032
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_WIRELESS_LAN_ENTRY
value|"Wireless LAN Entry"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_PORTABLE_CDROM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_PORTABLE_CDROM
value|0x002d
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_PORTABLE_CDROM
value|"PCMCIA Portable CD-ROM Drive"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IBM_ETHERJET
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_ETHERJET
value|0x003f
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_ETHERJET
value|"IBM EtherJet Ethernet"
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_IODATA_PCLATE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IODATA_PCLATE
value|0x2216
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IODATA_PCLATE
value|"I-O DATA PCLA/TE"
end_define

begin_comment
comment|/* Lexar Media */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_LEXARMEDIA_COMPATFLASH
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LEXARMEDIA_COMPATFLASH
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LEXARMEDIA_COMPATFLASH
value|"Lexar Media CompactFlash"
end_define

begin_comment
comment|/* Linksys corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_LINKSYS_ETHERFAST
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LINKSYS_ETHERFAST
value|0x0230
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LINKSYS_ETHERFAST
value|"Linksys Etherfast 10/100 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_LINKSYS_ECARD_1
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LINKSYS_ECARD_1
value|0x0265
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LINKSYS_ECARD_1
value|"Linksys EthernetCard or D-Link DE-650"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_LINKSYS_COMBO_ECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LINKSYS_COMBO_ECARD
value|0xc1ab
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LINKSYS_COMBO_ECARD
value|"Linksys Combo EthernetCard"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_LINKSYS_TRUST_COMBO_ECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LINKSYS_TRUST_COMBO_ECARD
value|0x021b
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LINKSYS_TRUST_COMBO_ECARD
value|"Trust (Linksys) Combo EthernetCard"
end_define

begin_comment
comment|/* Megahertz Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ_XJ4288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ_XJ4288
value|0x0023
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ_XJ4288
value|"Megahertz XJ4288 Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ_XJ4336
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ_XJ4336
value|0x0027
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ_XJ4336
value|"Megahertz XJ4336 Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ_XJ5560
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ_XJ5560
value|0x0034
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ_XJ5560
value|"Megahertz X-JACK 56kbps Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ2_XJACK
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ2_XJACK
value|0x0103
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ2_XJACK
value|"Megahertz X-JACK Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ_XJEM3336
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ_XJEM3336
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ_XJEM3336
value|"Megahertz X-JACK Ethernet Modem"
end_define

begin_comment
comment|/* Melco Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_MELCO_LPC3_TX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MELCO_LPC3_TX
value|0xc1ab
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MELCO_LPC3_TX
value|"Melco LPC3-TX"
end_define

begin_comment
comment|/* Nokia Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_NOKIA_C020_WLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_NOKIA_C020_WLAN
value|0x20c0
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_NOKIA_C020_WLAN
value|"Nokia C020 WLAN Card"
end_define

begin_comment
comment|/* Panasonic Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_PANASONIC_KXLC002
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_PANASONIC_KXLC002
value|0x0304
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_PANASONIC_KXLC002
value|"Panasonic 4X CD-ROM Interface Card"
end_define

begin_comment
comment|/* US Robotics Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_USROBOTICS_WORLDPORT144
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_USROBOTICS_WORLDPORT144
value|0x3330
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_USROBOTICS_WORLDPORT144
value|"US Robotics WorldPort 14.4 Modem"
end_define

begin_comment
comment|/* Sandisk Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SANDISK_SDCFB
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SANDISK_SDCFB
value|0x0401
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SANDISK_SDCFB
value|"Sandisk CompactFlash Card"
end_define

begin_comment
comment|/* Simple Technology Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SIMPLETECH_COMMUNICATOR288
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SIMPLETECH_COMMUNICATOR288
value|0x0100
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SIMPLETECH_COMMUNICATOR288
value|"Simple Technology 28.8 Communicator"
end_define

begin_comment
comment|/* Simpletech ID also used by Symbol */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SIMPLETECH_SPECTRUM24
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SIMPLETECH_SPECTRUM24
value|0x801
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SIMPLETECH_SPECTRUM24
value|"Symbol Spectrum24 WLAN Adapter"
end_define

begin_comment
comment|/* Socket Communications Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SOCKET_PAGECARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SOCKET_PAGECARD
value|0x0003
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SOCKET_PAGECARD
value|"Socket Communications PageCard"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_SOCKET_DUAL_RS232
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SOCKET_DUAL_RS232
value|0x0006
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SOCKET_DUAL_RS232
value|"Socket Communications Dual RS232"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_SOCEKT_LP_ETHER_CF
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SOCEKT_LP_ETHER_CF
value|0x0075
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SOCEKT_LP_ETHER_CF
value|"Socket Communications Low Power Ethernet CF"
end_define

begin_comment
comment|/* TDK Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_LAK_CD021BX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_LAK_CD021BX
value|0x0200
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_LAK_CD021BX
value|"TDK LAK-CD021BX Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_DFL9610
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_DFL9610
value|0x0d0a
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_DFL9610
value|"TDK DFL9610 Ethernet& Digital Cellular"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_LAK_CF010
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_LAK_CF010
value|0x0900
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_LAK_CF010
value|"TDK LAC-CF010"
end_define

begin_comment
comment|/* TDK Vendor ID also used by Xircom! */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CE_10
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CE_10
value|0x0108
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CE_10
value|"Xircom CreditCard Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CEM_10
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CEM_10
value|0x110a
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CEM_10
value|"Xircom CreditCard Ethernet + Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CEM_28
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CEM_28
value|0x110b
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CEM_28
value|"Xircom CreditCard Ethernet + Modem 28.8"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_PS_CE2_10
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_PS_CE2_10
value|0x010b
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_PS_CE2_10
value|"Xircom CreditCard CE2 Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CE3_10_100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CE3_10_100
value|0x010a
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CE3_10_100
value|"Xircom CreditCard CE3 10/100 Ethernet"
end_define

begin_comment
comment|/* conflicts with above  * product TDK XIR_CFE_10	0x010a Xircom CompactCard CFE-10  */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CNW_801
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CNW_801
value|0x0801
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CNW_801
value|"Xircom CreditCard Netwave (Canada)"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CNW_802
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CNW_802
value|0x0802
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CNW_802
value|"Xircom CreditCard Netwave (US)"
end_define

begin_comment
comment|/* New Media Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_NEWMEDIA_BASICS
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_NEWMEDIA_BASICS
value|0x0019
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_NEWMEDIA_BASICS
value|"New Media BASICS Ethernet"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_NEWMEDIA_BUSTOASTER
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_NEWMEDIA_BUSTOASTER
value|0xc102
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_NEWMEDIA_BUSTOASTER
value|"New Media BusToaster SCSI Host Adapter"
end_define

begin_comment
comment|/* Standard Microsystems Corporation Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SMC_8016
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SMC_8016
value|0x0105
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SMC_8016
value|"SMC 8016 EtherCard"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_SMC_EZCARD
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SMC_EZCARD
value|0x8022
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SMC_EZCARD
value|"SMC EZCard 10 PCMCIA"
end_define

begin_comment
comment|/* Contec C-NET(PC) */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_CONTEC_CNETPC
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_CONTEC_CNETPC
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_CONTEC_CNETPC
value|"Contec C-NET(PC)C"
end_define

begin_comment
comment|/* Allied Telesis K.K. */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_ALLIEDTELESIS_LA_PCM
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_ALLIEDTELESIS_LA_PCM
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_ALLIEDTELESIS_LA_PCM
value|"Allied Telesis LA-PCM"
end_define

begin_comment
comment|/* RATOC System Inc. Products */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_RATOC_REX_R280
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_RATOC_REX_R280
value|0x1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_RATOC_REX_R280
value|"RATOC REX-R280"
end_define

begin_comment
comment|/* Lucent WaveLAN/IEEE */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_LUCENT_WAVELAN_IEEE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LUCENT_WAVELAN_IEEE
value|0x0002
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LUCENT_WAVELAN_IEEE
value|"WaveLAN/IEEE"
end_define

begin_comment
comment|/* Aironet */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_AIRONET_PC4500
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_AIRONET_PC4500
value|0x0005
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_AIRONET_PC4500
value|"Aironet PC4500 Wireless LAN Adapter"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_AIRONET_PC4800
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_AIRONET_PC4800
value|0x0007
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_AIRONET_PC4800
value|"Aironet PC4800 Wireless LAN Adapter"
end_define

begin_comment
comment|/* Bay Networks */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_BAY_STACK_650
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_BAY_STACK_650
value|0x0804
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_BAY_STACK_650
value|"BayStack 650 Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_BAY_SURFER_PRO
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_BAY_SURFER_PRO
value|0x0806
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_BAY_SURFER_PRO
value|"AirSurfer Pro Wireless LAN"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_BAY_STACK_660
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_BAY_STACK_660
value|0x0807
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_BAY_STACK_660
value|"BayStack 660 Wireless LAN"
end_define

begin_comment
comment|/* Raylink/WebGear */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_RAYTHEON_WLAN
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_RAYTHEON_WLAN
value|0x0000
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_RAYTHEON_WLAN
value|"WLAN Adapter"
end_define

begin_comment
comment|/* Cards we know only by their cis */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_PREMAX
value|-1
end_define

begin_comment
comment|/* Premax */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_PLANET
value|-1
end_define

begin_comment
comment|/* Planet */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_PLANEX
value|-1
end_define

begin_comment
comment|/* Planex Communications Inc */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_DLINK
value|-1
end_define

begin_comment
comment|/* D-Link */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_RPTI
value|-1
end_define

begin_comment
comment|/* RPTI */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_ACCTON
value|-1
end_define

begin_comment
comment|/* ACCTON */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_YEDATA
value|-1
end_define

begin_comment
comment|/* Y-E DATA */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_DIGITAL
value|-1
end_define

begin_comment
comment|/* Digital Equipment Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_TEAC
value|-1
end_define

begin_comment
comment|/* TEAC */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_SVEC
value|-1
end_define

begin_comment
comment|/* SVEC/Hawking Technology */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_NAKAGAWAMETAL
value|-1
end_define

begin_comment
comment|/* NAKAGAWA METAL */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_AMBICOM
value|-1
end_define

begin_comment
comment|/* AmbiCom Inc */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_EPSON
value|-1
end_define

begin_comment
comment|/* Seiko Epson Corporation */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_EXP
value|-1
end_define

begin_comment
comment|/* EXP Computer Inc */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_ICOM
value|-1
end_define

begin_comment
comment|/* ICOM Inc */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_BILLIONTON
value|-1
end_define

begin_comment
comment|/* Billionton Systems Inc. */
end_comment

begin_define
define|#
directive|define
name|PCCARD_VENDOR_AMD
value|-1
end_define

begin_comment
comment|/* AMD */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_MEGAHERTZ_XJ2288
value|{ "MEGAHERTZ", "MODEM XJ2288", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_MEGAHERTZ_XJ2288
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_MEGAHERTZ_XJ2288
value|"Megahertz XJ2288 Modem"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_PREMAX_PE200
value|{ "PMX   ", "PE-200", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_PREMAX_PE200
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_PREMAX_PE200
value|"PreMax PE-200"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_PLANET_SMARTCOM2000
value|{ "PCMCIA", "UE2212", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_PLANET_SMARTCOM2000
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_PLANET_SMARTCOM2000
value|"Planet SmartCOM 2000"
end_define

begin_comment
comment|/*  * vendor ID of both FNW-3600-T and FNW-3700-T is LINKSYS (0x0149) and  * product ID is 0xc1ab, but it conflicts with LINKSYS Combo EthernetCard.  */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_PLANEX_FNW3600T
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_PLANEX_FNW3600T
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_PLANEX_FNW3600T
value|"Planex FNW-3600-T"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_PLANEX_FNW3700T
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_PLANEX_FNW3700T
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_PLANEX_FNW3700T
value|"Planex FNW-3700-T"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_DLINK_DE650
value|{ "D-Link", "DE-650", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DLINK_DE650
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DLINK_DE650
value|"D-Link DE-650"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_DLINK_DE660
value|{ "D-Link", "DE-660", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DLINK_DE660
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DLINK_DE660
value|"D-Link DE-660"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_RPTI_EP400
value|{ "RPTI LTD.", "EP400", "CISV100", NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_RPTI_EP400
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_RPTI_EP400
value|"RPTI EP400"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_RPTI_EP401
value|{ "RPTI", "EP401 Ethernet NE2000 Compatible", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_RPTI_EP401
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_RPTI_EP401
value|"RPTI EP401"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_ACCTON_EN2212
value|{ "ACCTON", "EN2212", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_ACCTON_EN2212
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_ACCTON_EN2212
value|"Accton EN2212"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_YEDATA_EXTERNAL_FDD
value|{ "Y-E DATA", "External FDD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_YEDATA_EXTERNAL_FDD
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_YEDATA_EXTERNAL_FDD
value|"Y-E DATA External FDD"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_DIGITAL_DEPCMXX
value|{ "DIGITAL", "DEPCM-XX", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_DIGITAL_DEPCMXX
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_DIGITAL_DEPCMXX
value|"DEC DEPCM-BA"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TEAC_IDECARDII
value|{ NULL, "NinjaATA-", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TEAC_IDECARDII
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TEAC_IDECARDII
value|"TEAC IDE Card/II"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_LINKSYS_ECARD_2
value|{ "LINKSYS", "E-CARD", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_LINKSYS_ECARD_2
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_LINKSYS_ECARD_2
value|"Linksys E-Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_COREGA_ETHER_PCC_T
value|{ "corega K.K.", "corega Ether PCC-T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_COREGA_ETHER_PCC_T
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_COREGA_ETHER_PCC_T
value|"Corega Ether PCC-T"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_COREGA_ETHER_II_PCC_T
value|{ "corega K.K.", "corega EtherII PCC-T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_COREGA_ETHER_II_PCC_T
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_COREGA_ETHER_II_PCC_T
value|"Corega EtherII PCC-T"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_COREGA_FAST_ETHER_PCC_TX
value|{ "corega K.K.", "corega FastEther PCC-TX", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_COREGA_FAST_ETHER_PCC_TX
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_COREGA_FAST_ETHER_PCC_TX
value|"Corega FastEther PCC-TX"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_SVEC_COMBOCARD
value|{ "Ethernet", "Adapter", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SVEC_COMBOCARD
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SVEC_COMBOCARD
value|"SVEC/Hawking Tech. Combo Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_SVEC_LANCARD
value|{ "SVEC", "FD605 PCMCIA EtherNet Card", "V1-1", NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SVEC_LANCARD
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SVEC_LANCARD
value|"SVEC PCMCIA Lan Card"
end_define

begin_comment
comment|/*  * vendor ID of PN650TX is LINKSYS (0x0149) and product ID is 0xc1ab, but  * it conflicts with LINKSYS Combo EthernetCard.  */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_SVEC_PN650TX
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_SVEC_PN650TX
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_SVEC_PN650TX
value|"SVEC PN650TX 10/100 Dual Speed Fast Ethernet PC Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_NAKAGAWAMETAL_LNT10TN
value|{ "PCMCIA", "LNT-10TN", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_NAKAGAWAMETAL_LNT10TN
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_NAKAGAWAMETAL_LNT10TN
value|"NAKAGAWA METAL LNT-10TN NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_EPSON_EEN10B
value|{ "Seiko Epson Corp.", "Ethernet", "P/N: EEN10B Rev. 00", NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_EPSON_EEN10B
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_EPSON_EEN10B
value|"Epson EEN10B"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_EXP_EXPMULTIMEDIA
value|{ "EXP   ", "PnPIDE", "F1", NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_EXP_EXPMULTIMEDIA
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_EXP_EXPMULTIMEDIA
value|"EXP IDE/ATAPI DVD Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_AMD_AM79C930
value|{ "AMD", "Am79C930", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_AMD_AM79C930
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_AMD_AM79C930
value|"AMD Am79C930"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_ICOM_SL200
value|{ "Icom", "SL-200", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_ICOM_SL200
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_ICOM_SL200
value|"Icom SL-200"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_XIRCOM_CFE_10
value|{ "Xircom", "CompactCard Ethernet", "CFE-10", "1.00" }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_XIRCOM_CFE_10
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_XIRCOM_CFE_10
value|"Xircom CompactCard CFE-10"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_BILLIONTON_LNT10TN
value|{ "PCMCIA", "LNT-10TN", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_BILLIONTON_LNT10TN
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_BILLIONTON_LNT10TN
value|"Billionton Systems Inc. LNT-10TN NE2000 Compatible Card"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_AMBICOM_AMB8002T
value|{ "AmbiCom Inc", "AMB8002T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_AMBICOM_AMB8002T
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_AMBICOM_AMB8002T
value|"AmbiCom AMB8002T"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_IODATA_PCLAT
value|{ "I-O DATA", "PCLA", "ETHERNET", NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IODATA_PCLAT
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IODATA_PCLAT
value|"IO-DATA PCLA/T"
end_define

end_unit

