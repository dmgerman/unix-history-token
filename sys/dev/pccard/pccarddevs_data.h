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

begin_decl_stmt
name|struct
name|pccard_knowndev
name|pccard_knowndevs
index|[]
init|=
block|{
block|{
name|PCCARD_VENDOR_ADAPTEC
block|,
name|PCCARD_PRODUCT_ADAPTEC_APA1460_1
block|,
name|PCCARD_CIS_ADAPTEC_APA1460_1
block|,
literal|0
block|,
literal|"Adaptec Corporation"
block|,
literal|"Adaptec APA-1460/A SCSI Host Adapter"
block|}
block|, 	}
decl_stmt|,
block|{
name|PCCARD_VENDOR_ADAPTEC
operator|,
name|PCCARD_PRODUCT_ADAPTEC_APA1460_2
operator|,
name|PCCARD_CIS_ADAPTEC_APA1460_2
operator|,
literal|0
operator|,
literal|"Adaptec Corporation"
operator|,
literal|"Adaptec APA-1460/B SCSI Host Adapter"
block|}
end_decl_stmt

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3C1
operator|,
name|PCCARD_CIS_3COM_3C1
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com Megahertz 3C1 10Mbps LAN CF+ Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3C562
operator|,
name|PCCARD_CIS_3COM_3C562
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com 3c562 33.6 Modem/10Mbps Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3C589
operator|,
name|PCCARD_CIS_3COM_3C589
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com 3c589 10Mbps Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3C574
operator|,
name|PCCARD_CIS_3COM_3C574
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com 3c574-TX 10/100Mbps Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3CXM056BNW
operator|,
name|PCCARD_CIS_3COM_3CXM056BNW
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com/NoteWorthy 3CXM056-BNW 56K Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3CXEM556
operator|,
name|PCCARD_CIS_3COM_3CXEM556
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com/Megahertz 3CXEM556 Ethernet/Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3CXEM556INT
operator|,
name|PCCARD_CIS_3COM_3CXEM556INT
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com/Megahertz 3CXEM556-INT Ethernet/Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_3COM
operator|,
name|PCCARD_PRODUCT_3COM_3CCFEM556BI
operator|,
name|PCCARD_CIS_3COM_3CCFEM556BI
operator|,
literal|0
operator|,
literal|"3Com Corporation"
operator|,
literal|"3Com/Megahertz 3CCFEM556BI Ethernet/Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_COMPEX
operator|,
name|PCCARD_PRODUCT_COMPEX_LINKPORT_ENET_B
operator|,
name|PCCARD_CIS_COMPEX_LINKPORT_ENET_B
operator|,
literal|0
operator|,
literal|"Compex Corporation"
operator|,
literal|"Compex Linkport ENET-B Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LASAT
operator|,
name|PCCARD_PRODUCT_LASAT_CREDIT_288
operator|,
name|PCCARD_CIS_LASAT_CREDIT_288
operator|,
literal|0
operator|,
literal|"Lasat Communications A/S"
operator|,
literal|"Lasat Credit 288 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_DAYNA
operator|,
name|PCCARD_PRODUCT_DAYNA_COMMUNICARD_E_1
operator|,
name|PCCARD_CIS_DAYNA_COMMUNICARD_E_1
operator|,
literal|0
operator|,
literal|"Dayna Corporation"
operator|,
literal|"Dayna CommuniCard E"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_DAYNA
operator|,
name|PCCARD_PRODUCT_DAYNA_COMMUNICARD_E_2
operator|,
name|PCCARD_CIS_DAYNA_COMMUNICARD_E_2
operator|,
literal|0
operator|,
literal|"Dayna Corporation"
operator|,
literal|"Dayna CommuniCard E"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_DIGITAL
operator|,
name|PCCARD_PRODUCT_DIGITAL_MOBILE_MEDIA_CDROM
operator|,
name|PCCARD_CIS_DIGITAL_MOBILE_MEDIA_CDROM
operator|,
literal|0
operator|,
literal|"Digital Equipment Corporation"
operator|,
literal|"Digital Mobile Media CD-ROM"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_FUJITSU
operator|,
name|PCCARD_PRODUCT_FUJITSU_SCSI600
operator|,
name|PCCARD_CIS_FUJITSU_SCSI600
operator|,
literal|0
operator|,
literal|"Fujitsu Corporation"
operator|,
literal|"Fujitsu SCSI 600 Interface"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MOTOROLA
operator|,
name|PCCARD_PRODUCT_MOTOROLA_POWER144
operator|,
name|PCCARD_CIS_MOTOROLA_POWER144
operator|,
literal|0
operator|,
literal|"Motorola Corporation"
operator|,
literal|"Motorola Power 14.4 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MOTOROLA
operator|,
name|PCCARD_PRODUCT_MOTOROLA_PM100C
operator|,
name|PCCARD_CIS_MOTOROLA_PM100C
operator|,
literal|0
operator|,
literal|"Motorola Corporation"
operator|,
literal|"Motorola Personal Messenger 100C CDPD Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_FUJITSU
operator|,
name|PCCARD_PRODUCT_FUJITSU_LA501
operator|,
name|PCCARD_CIS_FUJITSU_LA501
operator|,
literal|0
operator|,
literal|"Fujitsu Corporation"
operator|,
literal|"Fujitsu Towa LA501 Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_FUJITSU
operator|,
name|PCCARD_PRODUCT_FUJITSU_LA10S
operator|,
name|PCCARD_CIS_FUJITSU_LA10S
operator|,
literal|0
operator|,
literal|"Fujitsu Corporation"
operator|,
literal|"Fujitsu Compact Flash Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_3270
operator|,
name|PCCARD_CIS_IBM_3270
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"3270 Emulation"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_INFOMOVER
operator|,
name|PCCARD_CIS_IBM_INFOMOVER
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"National Semiconductor InfoMover"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_5250
operator|,
name|PCCARD_CIS_IBM_5250
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"5250 Emulation"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_TROPIC
operator|,
name|PCCARD_CIS_IBM_TROPIC
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"Token Ring 4/16"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_HOME_AND_AWAY
operator|,
name|PCCARD_CIS_IBM_HOME_AND_AWAY
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"IBM Home and Away Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_WIRELESS_LAN_ENTRY
operator|,
name|PCCARD_CIS_IBM_WIRELESS_LAN_ENTRY
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"Wireless LAN Entry"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_PORTABLE_CDROM
operator|,
name|PCCARD_CIS_IBM_PORTABLE_CDROM
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"PCMCIA Portable CD-ROM Drive"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IBM
operator|,
name|PCCARD_PRODUCT_IBM_ETHERJET
operator|,
name|PCCARD_CIS_IBM_ETHERJET
operator|,
literal|0
operator|,
literal|"IBM Corporation"
operator|,
literal|"IBM EtherJet Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_IODATA
operator|,
name|PCCARD_PRODUCT_IODATA_PCLATE
operator|,
name|PCCARD_CIS_IODATA_PCLATE
operator|,
literal|0
operator|,
literal|"I-O DATA"
operator|,
literal|"I-O DATA PCLA/TE"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LEXARMEDIA
operator|,
name|PCCARD_PRODUCT_LEXARMEDIA_COMPATFLASH
operator|,
name|PCCARD_CIS_LEXARMEDIA_COMPATFLASH
operator|,
literal|0
operator|,
literal|"Lexar Media"
operator|,
literal|"Lexar Media CompactFlash"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LINKSYS
operator|,
name|PCCARD_PRODUCT_LINKSYS_ETHERFAST
operator|,
name|PCCARD_CIS_LINKSYS_ETHERFAST
operator|,
literal|0
operator|,
literal|"Linksys Corporation"
operator|,
literal|"Linksys Etherfast 10/100 Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LINKSYS
operator|,
name|PCCARD_PRODUCT_LINKSYS_ECARD_1
operator|,
name|PCCARD_CIS_LINKSYS_ECARD_1
operator|,
literal|0
operator|,
literal|"Linksys Corporation"
operator|,
literal|"Linksys EthernetCard or D-Link DE-650"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LINKSYS
operator|,
name|PCCARD_PRODUCT_LINKSYS_COMBO_ECARD
operator|,
name|PCCARD_CIS_LINKSYS_COMBO_ECARD
operator|,
literal|0
operator|,
literal|"Linksys Corporation"
operator|,
literal|"Linksys Combo EthernetCard"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LINKSYS
operator|,
name|PCCARD_PRODUCT_LINKSYS_TRUST_COMBO_ECARD
operator|,
name|PCCARD_CIS_LINKSYS_TRUST_COMBO_ECARD
operator|,
literal|0
operator|,
literal|"Linksys Corporation"
operator|,
literal|"Trust (Linksys) Combo EthernetCard"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MEGAHERTZ
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ_XJ4288
operator|,
name|PCCARD_CIS_MEGAHERTZ_XJ4288
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz XJ4288 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MEGAHERTZ
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ_XJ4336
operator|,
name|PCCARD_CIS_MEGAHERTZ_XJ4336
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz XJ4336 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MEGAHERTZ
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ_XJ5560
operator|,
name|PCCARD_CIS_MEGAHERTZ_XJ5560
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz X-JACK 56kbps Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MEGAHERTZ2
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ2_XJACK
operator|,
name|PCCARD_CIS_MEGAHERTZ2_XJACK
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz X-JACK Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MEGAHERTZ
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ_XJEM3336
operator|,
name|PCCARD_CIS_MEGAHERTZ_XJEM3336
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz X-JACK Ethernet Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_MELCO
operator|,
name|PCCARD_PRODUCT_MELCO_LPC3_TX
operator|,
name|PCCARD_CIS_MELCO_LPC3_TX
operator|,
literal|0
operator|,
literal|"Melco Corporation"
operator|,
literal|"Melco LPC3-TX"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_NOKIA
operator|,
name|PCCARD_PRODUCT_NOKIA_C020_WLAN
operator|,
name|PCCARD_CIS_NOKIA_C020_WLAN
operator|,
literal|0
operator|,
literal|"Nokia Communications"
operator|,
literal|"Nokia C020 WLAN Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_PANASONIC
operator|,
name|PCCARD_PRODUCT_PANASONIC_KXLC002
operator|,
name|PCCARD_CIS_PANASONIC_KXLC002
operator|,
literal|0
operator|,
literal|"Matsushita Electric Industrial Co."
operator|,
literal|"Panasonic 4X CD-ROM Interface Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_USROBOTICS
operator|,
name|PCCARD_PRODUCT_USROBOTICS_WORLDPORT144
operator|,
name|PCCARD_CIS_USROBOTICS_WORLDPORT144
operator|,
literal|0
operator|,
literal|"US Robotics Corporation"
operator|,
literal|"US Robotics WorldPort 14.4 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SANDISK
operator|,
name|PCCARD_PRODUCT_SANDISK_SDCFB
operator|,
name|PCCARD_CIS_SANDISK_SDCFB
operator|,
literal|0
operator|,
literal|"Sandisk Corporation"
operator|,
literal|"Sandisk CompactFlash Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SIMPLETECH
operator|,
name|PCCARD_PRODUCT_SIMPLETECH_COMMUNICATOR288
operator|,
name|PCCARD_CIS_SIMPLETECH_COMMUNICATOR288
operator|,
literal|0
operator|,
literal|"Simple Technology"
operator|,
literal|"Simple Technology 28.8 Communicator"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SIMPLETECH
operator|,
name|PCCARD_PRODUCT_SIMPLETECH_SPECTRUM24
operator|,
name|PCCARD_CIS_SIMPLETECH_SPECTRUM24
operator|,
literal|0
operator|,
literal|"Simple Technology"
operator|,
literal|"Symbol Spectrum24 WLAN Adapter"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SOCKET
operator|,
name|PCCARD_PRODUCT_SOCKET_PAGECARD
operator|,
name|PCCARD_CIS_SOCKET_PAGECARD
operator|,
literal|0
operator|,
literal|"Socket Communications"
operator|,
literal|"Socket Communications PageCard"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SOCKET
operator|,
name|PCCARD_PRODUCT_SOCKET_DUAL_RS232
operator|,
name|PCCARD_CIS_SOCKET_DUAL_RS232
operator|,
literal|0
operator|,
literal|"Socket Communications"
operator|,
literal|"Socket Communications Dual RS232"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SOCEKT
operator|,
name|PCCARD_PRODUCT_SOCEKT_LP_ETHER_CF
operator|,
name|PCCARD_CIS_SOCEKT_LP_ETHER_CF
operator|,
literal|0
operator|,
literal|""
operator|,
literal|"Socket Communications Low Power Ethernet CF"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_LAK_CD021BX
operator|,
name|PCCARD_CIS_TDK_LAK_CD021BX
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"TDK LAK-CD021BX Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_DFL9610
operator|,
name|PCCARD_CIS_TDK_DFL9610
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"TDK DFL9610 Ethernet& Digital Cellular"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_LAK_CF010
operator|,
name|PCCARD_CIS_TDK_LAK_CF010
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"TDK LAC-CF010"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CE_10
operator|,
name|PCCARD_CIS_TDK_XIR_CE_10
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CEM_10
operator|,
name|PCCARD_CIS_TDK_XIR_CEM_10
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard Ethernet + Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CEM_28
operator|,
name|PCCARD_CIS_TDK_XIR_CEM_28
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard Ethernet + Modem 28.8"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_PS_CE2_10
operator|,
name|PCCARD_CIS_TDK_XIR_PS_CE2_10
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard CE2 Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CE3_10_100
operator|,
name|PCCARD_CIS_TDK_XIR_CE3_10_100
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard CE3 10/100 Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CNW_801
operator|,
name|PCCARD_CIS_TDK_XIR_CNW_801
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard Netwave (Canada)"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_TDK
operator|,
name|PCCARD_PRODUCT_TDK_XIR_CNW_802
operator|,
name|PCCARD_CIS_TDK_XIR_CNW_802
operator|,
literal|0
operator|,
literal|"TDK Corporation"
operator|,
literal|"Xircom CreditCard Netwave (US)"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_NEWMEDIA
operator|,
name|PCCARD_PRODUCT_NEWMEDIA_BASICS
operator|,
name|PCCARD_CIS_NEWMEDIA_BASICS
operator|,
literal|0
operator|,
literal|"NewMedia Corporation"
operator|,
literal|"New Media BASICS Ethernet"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_NEWMEDIA
operator|,
name|PCCARD_PRODUCT_NEWMEDIA_BUSTOASTER
operator|,
name|PCCARD_CIS_NEWMEDIA_BUSTOASTER
operator|,
literal|0
operator|,
literal|"NewMedia Corporation"
operator|,
literal|"New Media BusToaster SCSI Host Adapter"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SMC
operator|,
name|PCCARD_PRODUCT_SMC_8016
operator|,
name|PCCARD_CIS_SMC_8016
operator|,
literal|0
operator|,
literal|"Standard Microsystems Corporation"
operator|,
literal|"SMC 8016 EtherCard"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_SMC
operator|,
name|PCCARD_PRODUCT_SMC_EZCARD
operator|,
name|PCCARD_CIS_SMC_EZCARD
operator|,
literal|0
operator|,
literal|"Standard Microsystems Corporation"
operator|,
literal|"SMC EZCard 10 PCMCIA"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_CONTEC
operator|,
name|PCCARD_PRODUCT_CONTEC_CNETPC
operator|,
name|PCCARD_CIS_CONTEC_CNETPC
operator|,
literal|0
operator|,
literal|"Contec"
operator|,
literal|"Contec C-NET(PC)C"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_ALLIEDTELESIS
operator|,
name|PCCARD_PRODUCT_ALLIEDTELESIS_LA_PCM
operator|,
name|PCCARD_CIS_ALLIEDTELESIS_LA_PCM
operator|,
literal|0
operator|,
literal|"Allied Telesis K.K."
operator|,
literal|"Allied Telesis LA-PCM"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_RATOC
operator|,
name|PCCARD_PRODUCT_RATOC_REX_R280
operator|,
name|PCCARD_CIS_RATOC_REX_R280
operator|,
literal|0
operator|,
literal|"RATOC System Inc."
operator|,
literal|"RATOC REX-R280"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_LUCENT
operator|,
name|PCCARD_PRODUCT_LUCENT_WAVELAN_IEEE
operator|,
name|PCCARD_CIS_LUCENT_WAVELAN_IEEE
operator|,
literal|0
operator|,
literal|"Lucent Technologies"
operator|,
literal|"WaveLAN/IEEE"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_AIRONET
operator|,
name|PCCARD_PRODUCT_AIRONET_PC4500
operator|,
name|PCCARD_CIS_AIRONET_PC4500
operator|,
literal|0
operator|,
literal|"Aironet Wireless Communications"
operator|,
literal|"Aironet PC4500 Wireless LAN Adapter"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_AIRONET
operator|,
name|PCCARD_PRODUCT_AIRONET_PC4800
operator|,
name|PCCARD_CIS_AIRONET_PC4800
operator|,
literal|0
operator|,
literal|"Aironet Wireless Communications"
operator|,
literal|"Aironet PC4800 Wireless LAN Adapter"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_BAY
operator|,
name|PCCARD_PRODUCT_BAY_STACK_650
operator|,
name|PCCARD_CIS_BAY_STACK_650
operator|,
literal|0
operator|,
literal|"Bay Networks"
operator|,
literal|"BayStack 650 Wireless LAN"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_BAY
operator|,
name|PCCARD_PRODUCT_BAY_SURFER_PRO
operator|,
name|PCCARD_CIS_BAY_SURFER_PRO
operator|,
literal|0
operator|,
literal|"Bay Networks"
operator|,
literal|"AirSurfer Pro Wireless LAN"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_BAY
operator|,
name|PCCARD_PRODUCT_BAY_STACK_660
operator|,
name|PCCARD_CIS_BAY_STACK_660
operator|,
literal|0
operator|,
literal|"Bay Networks"
operator|,
literal|"BayStack 660 Wireless LAN"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_RAYTHEON
operator|,
name|PCCARD_PRODUCT_RAYTHEON_WLAN
operator|,
name|PCCARD_CIS_RAYTHEON_WLAN
operator|,
literal|0
operator|,
literal|"Raytheon"
operator|,
literal|"WLAN Adapter"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_MEGAHERTZ_XJ2288
operator|,
name|PCCARD_CIS_MEGAHERTZ_XJ2288
operator|,
literal|0
operator|,
literal|"Megahertz Corporation"
operator|,
literal|"Megahertz XJ2288 Modem"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_PREMAX_PE200
operator|,
name|PCCARD_CIS_PREMAX_PE200
operator|,
literal|0
operator|,
literal|"Premax"
operator|,
literal|"PreMax PE-200"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_PLANET_SMARTCOM2000
operator|,
name|PCCARD_CIS_PLANET_SMARTCOM2000
operator|,
literal|0
operator|,
literal|"Planet"
operator|,
literal|"Planet SmartCOM 2000"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_PLANEX_FNW3600T
operator|,
name|PCCARD_CIS_PLANEX_FNW3600T
operator|,
literal|0
operator|,
literal|"Planex Communications Inc"
operator|,
literal|"Planex FNW-3600-T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_PLANEX_FNW3700T
operator|,
name|PCCARD_CIS_PLANEX_FNW3700T
operator|,
literal|0
operator|,
literal|"Planex Communications Inc"
operator|,
literal|"Planex FNW-3700-T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_DLINK_DE650
operator|,
name|PCCARD_CIS_DLINK_DE650
operator|,
literal|0
operator|,
literal|"D-Link"
operator|,
literal|"D-Link DE-650"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_DLINK_DE660
operator|,
name|PCCARD_CIS_DLINK_DE660
operator|,
literal|0
operator|,
literal|"D-Link"
operator|,
literal|"D-Link DE-660"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_RPTI_EP400
operator|,
name|PCCARD_CIS_RPTI_EP400
operator|,
literal|0
operator|,
literal|"RPTI"
operator|,
literal|"RPTI EP400"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_RPTI_EP401
operator|,
name|PCCARD_CIS_RPTI_EP401
operator|,
literal|0
operator|,
literal|"RPTI"
operator|,
literal|"RPTI EP401"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_ACCTON_EN2212
operator|,
name|PCCARD_CIS_ACCTON_EN2212
operator|,
literal|0
operator|,
literal|"ACCTON"
operator|,
literal|"Accton EN2212"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_YEDATA_EXTERNAL_FDD
operator|,
name|PCCARD_CIS_YEDATA_EXTERNAL_FDD
operator|,
literal|0
operator|,
literal|"Y-E DATA"
operator|,
literal|"Y-E DATA External FDD"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_DIGITAL_DEPCMXX
operator|,
name|PCCARD_CIS_DIGITAL_DEPCMXX
operator|,
literal|0
operator|,
literal|"Digital Equipment Corporation"
operator|,
literal|"DEC DEPCM-BA"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_TEAC_IDECARDII
operator|,
name|PCCARD_CIS_TEAC_IDECARDII
operator|,
literal|0
operator|,
literal|"TEAC"
operator|,
literal|"TEAC IDE Card/II"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_LINKSYS_ECARD_2
operator|,
name|PCCARD_CIS_LINKSYS_ECARD_2
operator|,
literal|0
operator|,
literal|"Linksys Corporation"
operator|,
literal|"Linksys E-Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_COREGA_ETHER_PCC_T
operator|,
name|PCCARD_CIS_COREGA_ETHER_PCC_T
operator|,
literal|0
operator|,
literal|"Corega K.K."
operator|,
literal|"Corega Ether PCC-T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_COREGA_ETHER_II_PCC_T
operator|,
name|PCCARD_CIS_COREGA_ETHER_II_PCC_T
operator|,
literal|0
operator|,
literal|"Corega K.K."
operator|,
literal|"Corega EtherII PCC-T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_COREGA_FAST_ETHER_PCC_TX
operator|,
name|PCCARD_CIS_COREGA_FAST_ETHER_PCC_TX
operator|,
literal|0
operator|,
literal|"Corega K.K."
operator|,
literal|"Corega FastEther PCC-TX"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_SVEC_COMBOCARD
operator|,
name|PCCARD_CIS_SVEC_COMBOCARD
operator|,
literal|0
operator|,
literal|"SVEC/Hawking Technology"
operator|,
literal|"SVEC/Hawking Tech. Combo Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_SVEC_LANCARD
operator|,
name|PCCARD_CIS_SVEC_LANCARD
operator|,
literal|0
operator|,
literal|"SVEC/Hawking Technology"
operator|,
literal|"SVEC PCMCIA Lan Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_SVEC_PN650TX
operator|,
name|PCCARD_CIS_SVEC_PN650TX
operator|,
literal|0
operator|,
literal|"SVEC/Hawking Technology"
operator|,
literal|"SVEC PN650TX 10/100 Dual Speed Fast Ethernet PC Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_NAKAGAWAMETAL_LNT10TN
operator|,
name|PCCARD_CIS_NAKAGAWAMETAL_LNT10TN
operator|,
literal|0
operator|,
literal|"NAKAGAWA METAL"
operator|,
literal|"NAKAGAWA METAL LNT-10TN NE2000 Compatible Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_EPSON_EEN10B
operator|,
name|PCCARD_CIS_EPSON_EEN10B
operator|,
literal|0
operator|,
literal|"Seiko Epson Corporation"
operator|,
literal|"Epson EEN10B"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_EXP_EXPMULTIMEDIA
operator|,
name|PCCARD_CIS_EXP_EXPMULTIMEDIA
operator|,
literal|0
operator|,
literal|"EXP Computer Inc"
operator|,
literal|"EXP IDE/ATAPI DVD Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_AMD_AM79C930
operator|,
name|PCCARD_CIS_AMD_AM79C930
operator|,
literal|0
operator|,
literal|"AMD"
operator|,
literal|"AMD Am79C930"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_ICOM_SL200
operator|,
name|PCCARD_CIS_ICOM_SL200
operator|,
literal|0
operator|,
literal|"ICOM Inc"
operator|,
literal|"Icom SL-200"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_XIRCOM_CFE_10
operator|,
name|PCCARD_CIS_XIRCOM_CFE_10
operator|,
literal|0
operator|,
literal|"Xircom"
operator|,
literal|"Xircom CompactCard CFE-10"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_BILLIONTON_LNT10TN
operator|,
name|PCCARD_CIS_BILLIONTON_LNT10TN
operator|,
literal|0
operator|,
literal|"Billionton Systems Inc."
operator|,
literal|"Billionton Systems Inc. LNT-10TN NE2000 Compatible Card"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_AMBICOM_AMB8002T
operator|,
name|PCCARD_CIS_AMBICOM_AMB8002T
operator|,
literal|0
operator|,
literal|"AmbiCom Inc"
operator|,
literal|"AmbiCom AMB8002T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_UNKNOWN
operator|,
name|PCCARD_PRODUCT_IODATA_PCLAT
operator|,
name|PCCARD_CIS_IODATA_PCLAT
operator|,
literal|0
operator|,
literal|"I-O DATA"
operator|,
literal|"IO-DATA PCLA/T"
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|},
block|{
name|PCCARD_VENDOR_FUJITSU
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Fujitsu Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_PANASONIC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Matsushita Electric Industrial Co."
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_SANDISK
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Sandisk Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_NEWMEDIA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"NewMedia Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_INTEL
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Intel Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_IBM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"IBM Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_MOTOROLA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Motorola Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_3COM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"3Com Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_MEGAHERTZ
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Megahertz Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_SOCKET
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Socket Communications"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_TDK
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"TDK Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_XIRCOM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Xircom"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_SMC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Standard Microsystems Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_USROBOTICS
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"US Robotics Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_MEGAHERTZ2
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Megahertz Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_ADAPTEC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Adaptec Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_COMPAQ
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Compaq"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_LINKSYS
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Linksys Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_SIMPLETECH
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Simple Technology"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_LUCENT
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Lucent Technologies"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_AIRONET
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Aironet Wireless Communications"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_COMPAQ2
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Compaq"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_DAYNA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Dayna Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_RAYTHEON
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Raytheon"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_IODATA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"I-O DATA"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_BAY
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Bay Networks"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_NOKIA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Nokia Communications"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_LASAT
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Lasat Communications A/S"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_LEXARMEDIA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Lexar Media"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_COMPEX
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Compex Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_MELCO
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Melco Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_CONTEC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Contec"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_COREGA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Corega K.K."
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_ALLIEDTELESIS
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Allied Telesis K.K."
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_HAGIWARASYSCOM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Hagiwara SYS-COM"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_RATOC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"RATOC System Inc."
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_PREMAX
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Premax"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_PLANET
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Planet"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_PLANEX
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Planex Communications Inc"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_DLINK
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"D-Link"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_RPTI
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"RPTI"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_ACCTON
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"ACCTON"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_YEDATA
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Y-E DATA"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_DIGITAL
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Digital Equipment Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_TEAC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"TEAC"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_SVEC
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"SVEC/Hawking Technology"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_NAKAGAWAMETAL
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"NAKAGAWA METAL"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_AMBICOM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"AmbiCom Inc"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_EPSON
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Seiko Epson Corporation"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_EXP
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"EXP Computer Inc"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_ICOM
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"ICOM Inc"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_BILLIONTON
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"Billionton Systems Inc."
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
name|PCCARD_VENDOR_AMD
operator|,
literal|0
operator|,
name|PCCARD_KNOWNDEV_NOPROD
operator|,
name|PCCARD_CIS_INVALID
operator|,
literal|"AMD"
operator|,
name|NULL
operator|,
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|0
operator|,
literal|0
operator|,
block|{
name|NULL
block|,
name|NULL
block|,
name|NULL
block|,
name|NULL
block|}
operator|,
literal|0
operator|,
name|NULL
operator|,
name|NULL
operator|,
block|}
end_block

unit|};
end_unit

