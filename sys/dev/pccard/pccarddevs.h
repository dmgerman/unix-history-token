begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	NetBSD: pcmciadevs,v 1.33 1999/02/19 21:49:43 abs Exp   */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Christos Zoulas.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
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
name|PCCARD_VENDOR_COMPAQ1
value|0x0138
end_define

begin_comment
comment|/* Compaq Corporation (1) */
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
name|PCCARD_VENDOR_COMPAQ2
value|0x0183
end_define

begin_comment
comment|/* Compaq Corporation (2) */
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
name|PCCARD_VENDOR_IODATA
value|0x01bf
end_define

begin_comment
comment|/* I-O DATA */
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
name|PCCARD_VENDOR_COREGA
value|0xc00f
end_define

begin_comment
comment|/* Corega K.K. */
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
comment|/* IBM Products */
end_comment

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
name|PCCARD_CIS_IBM_PORTABLE_CDROM_DRIVE
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IBM_PORTABLE_CDROM_DRIVE
value|0x002d
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IBM_PORTABLE_CDROM_DRIVE
value|"PCMCIA Portable CD-ROM Drive"
end_define

begin_comment
comment|/* I-O DATA */
end_comment

begin_define
define|#
directive|define
name|PCCARD_CIS_IODATA_PCLAT
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_IODATA_PCLAT
value|0x2216
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_IODATA_PCLAT
value|"I-O DATA PCLA/T"
end_define

begin_comment
comment|/* Linksys corporation */
end_comment

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
name|PCCARD_CIS_TDK_XIR_CE3_100
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CE3_100
value|0x010a
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CE3_100
value|"Xircom CreditCard Ethernet 10/100"
end_define

begin_define
define|#
directive|define
name|PCCARD_CIS_TDK_XIR_CNW
value|{ NULL, NULL, NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_TDK_XIR_CNW
value|0x0802
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_TDK_XIR_CNW
value|"Xircom CreditCard Netwave"
end_define

begin_comment
comment|/* NewMedia Products */
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
value|"NewMedia BASICS Ethernet"
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
name|PCCARD_CIS_COREGA_PCC_2
value|{ "corega K.K.", "corega Ether PCC-T", NULL, NULL }
end_define

begin_define
define|#
directive|define
name|PCCARD_PRODUCT_COREGA_PCC_2
value|-1
end_define

begin_define
define|#
directive|define
name|PCCARD_STR_COREGA_PCC_2
value|"Corega"
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

end_unit

