begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	FreeBSD: src/sys/dev/mii/miidevs,v 1.4.2.18 2006/12/07 16:25:31 jhb Exp   */
end_comment

begin_comment
comment|/*$NetBSD: miidevs,v 1.6 1999/05/14 11:37:30 drochner Exp $*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998, 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * List of known MII OUIs.  * For a complete list see http://standards.ieee.org/regauth/oui/  *  * XXX Vendors do obviously not agree how OUIs (18 bit) are mapped  * to the 16 bits available in the id registers. The MII_OUI() macro  * in "mii.h" reflects the most obvious way. If a vendor uses a  * different mapping, an "xx" prefixed OUI is defined here which is  * mangled accordingly to compensate.  */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_ALTIMA
value|0x0010a9
end_define

begin_comment
comment|/* Altima Communications */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_AMD
value|0x00001a
end_define

begin_comment
comment|/* Advanced Micro Devices */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_BROADCOM
value|0x001018
end_define

begin_comment
comment|/* Broadcom Corporation */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_DAVICOM
value|0x00606e
end_define

begin_comment
comment|/* Davicom Semiconductor */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_ICS
value|0x00a0be
end_define

begin_comment
comment|/* Integrated Circuit Systems */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_INTEL
value|0x00aa00
end_define

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_JATO
value|0x00e083
end_define

begin_comment
comment|/* Jato Technologies */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_LEVEL1
value|0x00207b
end_define

begin_comment
comment|/* Level 1 */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_NATSEMI
value|0x080017
end_define

begin_comment
comment|/* National Semiconductor */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_QUALSEMI
value|0x006051
end_define

begin_comment
comment|/* Quality Semiconductor */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_REALTEK
value|0x000020
end_define

begin_comment
comment|/* RealTek Semicondctor */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_SEEQ
value|0x00a07d
end_define

begin_comment
comment|/* Seeq */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_SIS
value|0x00e006
end_define

begin_comment
comment|/* Silicon Integrated Systems */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_TDK
value|0x00c039
end_define

begin_comment
comment|/* TDK */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_TI
value|0x080028
end_define

begin_comment
comment|/* Texas Instruments */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_XAQTI
value|0x00e0ae
end_define

begin_comment
comment|/* XaQti Corp. */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_MARVELL
value|0x005043
end_define

begin_comment
comment|/* Marvell Semiconductor */
end_comment

begin_comment
comment|/* in the 79c873, AMD uses another OUI (which matches Davicom!) */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxAMD
value|0x00606e
end_define

begin_comment
comment|/* Advanced Micro Devices */
end_comment

begin_comment
comment|/* Intel 82553 A/B steppings */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxINTEL
value|0x00f800
end_define

begin_comment
comment|/* Intel */
end_comment

begin_comment
comment|/* some vendors have the bits swapped within bytes 	(ie, ordered as on the wire) */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxALTIMA
value|0x000895
end_define

begin_comment
comment|/* Altima Communications */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxBROADCOM
value|0x000818
end_define

begin_comment
comment|/* Broadcom Corporation */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxICS
value|0x00057d
end_define

begin_comment
comment|/* Integrated Circuit Systems */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxSEEQ
value|0x0005be
end_define

begin_comment
comment|/* Seeq */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxSIS
value|0x000760
end_define

begin_comment
comment|/* Silicon Integrated Systems */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxTI
value|0x100014
end_define

begin_comment
comment|/* Texas Instruments */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxXAQTI
value|0x350700
end_define

begin_comment
comment|/* XaQti Corp. */
end_comment

begin_comment
comment|/* Level 1 is completely different - from right to left. 	(Two bits get lost in the third OUI byte.) */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxLEVEL1
value|0x1e0400
end_define

begin_comment
comment|/* Level 1 */
end_comment

begin_comment
comment|/* Don't know what's going on here. */
end_comment

begin_define
define|#
directive|define
name|MII_OUI_xxDAVICOM
value|0x006040
end_define

begin_comment
comment|/* Davicom Semiconductor */
end_comment

begin_comment
comment|/*  * List of known models.  Grouped by oui.  */
end_comment

begin_comment
comment|/* Altima Communications PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxALTIMA_AC101
value|0x0021
end_define

begin_define
define|#
directive|define
name|MII_STR_xxALTIMA_AC101
value|"AC101 10/100 media interface"
end_define

begin_comment
comment|/* Advanced Micro Devices PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxAMD_79C873
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_xxAMD_79C873
value|"Am79C873 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_AMD_79c973phy
value|0x0036
end_define

begin_define
define|#
directive|define
name|MII_STR_AMD_79c973phy
value|"Am79c973 internal PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_AMD_79c978
value|0x0039
end_define

begin_define
define|#
directive|define
name|MII_STR_AMD_79c978
value|"Am79c978 HomePNA PHY"
end_define

begin_comment
comment|/* Broadcom Corp. PHYs. */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_BROADCOM_3c905Cphy
value|0x0017
end_define

begin_define
define|#
directive|define
name|MII_STR_BROADCOM_3c905Cphy
value|"3c905C 10/100 internal PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5400
value|0x0004
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5400
value|"Broadcom 1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5401
value|0x0005
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5401
value|"BCM5401 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5411
value|0x0007
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5411
value|"BCM5411 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5752
value|0x0010
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5752
value|"BCM5752 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5701
value|0x0011
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5701
value|"BCM5701 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5703
value|0x0016
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5703
value|"BCM5703 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5704
value|0x0019
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5704
value|"BCM5704 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5705
value|0x001a
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5705
value|"BCM5705 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5750
value|0x0018
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5750
value|"BCM5750 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5714
value|0x0034
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5714
value|"BCM5714 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5780
value|0x0035
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5780
value|"BCM5780 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5706C
value|0x0015
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5706C
value|"BCM5706C 10/100/1000baseTX PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxBROADCOM_BCM5708C
value|0x0036
end_define

begin_define
define|#
directive|define
name|MII_STR_xxBROADCOM_BCM5708C
value|"BCM5708C 10/100/1000baseTX PHY"
end_define

begin_comment
comment|/* Davicom Semiconductor PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxDAVICOM_DM9101
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_xxDAVICOM_DM9101
value|"DM9101 10/100 media interface"
end_define

begin_comment
comment|/* Integrated Circuit Systems PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxICS_1890
value|0x0002
end_define

begin_define
define|#
directive|define
name|MII_STR_xxICS_1890
value|"ICS1890 10/100 media interface"
end_define

begin_comment
comment|/* Intel PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxINTEL_I82553AB
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_xxINTEL_I82553AB
value|"i83553 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_INTEL_I82555
value|0x0015
end_define

begin_define
define|#
directive|define
name|MII_STR_INTEL_I82555
value|"i82555 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_INTEL_I82562EM
value|0x0032
end_define

begin_define
define|#
directive|define
name|MII_STR_INTEL_I82562EM
value|"i82562EM 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_INTEL_I82562ET
value|0x0033
end_define

begin_define
define|#
directive|define
name|MII_STR_INTEL_I82562ET
value|"i82562ET 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_INTEL_I82553C
value|0x0035
end_define

begin_define
define|#
directive|define
name|MII_STR_INTEL_I82553C
value|"i82553 10/100 media interface"
end_define

begin_comment
comment|/* Jato Technologies PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_JATO_BASEX
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_JATO_BASEX
value|"Jato 1000baseX media interface"
end_define

begin_comment
comment|/* Level 1 PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxLEVEL1_LXT970
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_xxLEVEL1_LXT970
value|"LXT970 10/100 media interface"
end_define

begin_comment
comment|/* National Semiconductor PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_NATSEMI_DP83840
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_NATSEMI_DP83840
value|"DP83840 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_NATSEMI_DP83843
value|0x0001
end_define

begin_define
define|#
directive|define
name|MII_STR_NATSEMI_DP83843
value|"DP83843 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_NATSEMI_DP83891
value|0x0005
end_define

begin_define
define|#
directive|define
name|MII_STR_NATSEMI_DP83891
value|"DP83891 10/100/1000 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_NATSEMI_DP83861
value|0x0006
end_define

begin_define
define|#
directive|define
name|MII_STR_NATSEMI_DP83861
value|"DP83861 10/100/1000 media interface"
end_define

begin_comment
comment|/* Quality Semiconductor PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_QUALSEMI_QS6612
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_QUALSEMI_QS6612
value|"QS6612 10/100 media interface"
end_define

begin_comment
comment|/* RealTek Semiconductor PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_REALTEK_RTL8201L
value|0x0020
end_define

begin_define
define|#
directive|define
name|MII_STR_REALTEK_RTL8201L
value|"RTL8201L 10/100 media interface"
end_define

begin_comment
comment|/* Seeq PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxSEEQ_80220
value|0x0003
end_define

begin_define
define|#
directive|define
name|MII_STR_xxSEEQ_80220
value|"Seeq 80220 10/100 media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxSEEQ_84220
value|0x0004
end_define

begin_define
define|#
directive|define
name|MII_STR_xxSEEQ_84220
value|"Seeq 84220 10/100 media interface"
end_define

begin_comment
comment|/* Silicon Integrated Systems PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxSIS_900
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_xxSIS_900
value|"SiS 900 10/100 media interface"
end_define

begin_comment
comment|/* TDK */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_TDK_78Q2120
value|0x0014
end_define

begin_define
define|#
directive|define
name|MII_STR_TDK_78Q2120
value|"TDK 78Q2120 media interface"
end_define

begin_comment
comment|/* Texas Instruments PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_xxTI_TLAN10T
value|0x0001
end_define

begin_define
define|#
directive|define
name|MII_STR_xxTI_TLAN10T
value|"ThunderLAN 10baseT media interface"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_xxTI_100VGPMI
value|0x0002
end_define

begin_define
define|#
directive|define
name|MII_STR_xxTI_100VGPMI
value|"ThunderLAN 100VG-AnyLan media interface"
end_define

begin_comment
comment|/* XaQti Corp. PHYs. */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_XAQTI_XMACII
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_XAQTI_XMACII
value|"XaQti Corp. XMAC II gigabit interface"
end_define

begin_comment
comment|/* Marvell Semiconductor PHYs */
end_comment

begin_define
define|#
directive|define
name|MII_MODEL_MARVELL_E1000
value|0x0000
end_define

begin_define
define|#
directive|define
name|MII_STR_MARVELL_E1000
value|"Marvell Semiconductor 88E1000* gigabit PHY"
end_define

begin_define
define|#
directive|define
name|MII_MODEL_MARVELL_E1011
value|0x0002
end_define

begin_define
define|#
directive|define
name|MII_STR_MARVELL_E1011
value|"Marvell Semiconductor 88E1011 Gigabit PHY"
end_define

end_unit

