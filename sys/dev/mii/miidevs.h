begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$	*/
end_comment

begin_comment
comment|/*  * THIS FILE AUTOMATICALLY GENERATED.  DO NOT EDIT.  *  * generated from:  *	Id: miidevs,v 1.1 1999/08/21 17:40:43 wpaul Exp   */
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
name|MII_OUI_AMD
value|0x00001a
end_define

begin_comment
comment|/* Advanced Micro Devices */
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
name|MII_OUI_TI
value|0x080028
end_define

begin_comment
comment|/* Texas Instruments */
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
comment|/* some vendors have the bits swapped within bytes 	(ie, ordered as on the wire) */
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
name|MII_MODEL_INTEL_I82555
value|0x0015
end_define

begin_define
define|#
directive|define
name|MII_STR_INTEL_I82555
value|"i82555 10/100 media interface"
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

end_unit

