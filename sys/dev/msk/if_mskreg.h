begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  *  * Name:	skgehw.h  * Project:	Gigabit Ethernet Adapters, Common Modules  * Version:	$Revision: 2.49 $  * Date:	$Date: 2005/01/20 13:01:35 $  * Purpose:	Defines and Macros for the Gigabit Ethernet Adapter Product Family  *  ******************************************************************************/
end_comment

begin_comment
comment|/******************************************************************************  *  *	LICENSE:  *	Copyright (C) Marvell International Ltd. and/or its affiliates  *  *	The computer program files contained in this folder ("Files")  *	are provided to you under the BSD-type license terms provided  *	below, and any use of such Files and any derivative works  *	thereof created by you shall be governed by the following terms  *	and conditions:  *  *	- Redistributions of source code must retain the above copyright  *	  notice, this list of conditions and the following disclaimer.  *	- Redistributions in binary form must reproduce the above  *	  copyright notice, this list of conditions and the following  *	  disclaimer in the documentation and/or other materials provided  *	  with the distribution.  *	- Neither the name of Marvell nor the names of its contributors  *	  may be used to endorse or promote products derived from this  *	  software without specific prior written permission.  *  *	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  *	"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  *	LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  *	FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  *	COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  *	INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  *	BUT NOT LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR SERVICES;  *	LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  *	HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  *	STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *	ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  *	OF THE POSSIBILITY OF SUCH DAMAGE.  *	/LICENSE  *  ******************************************************************************/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1997, 1998, 1999, 2000  *	Bill Paul<wpaul@ctr.columbia.edu>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Bill Paul.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY Bill Paul AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Bill Paul OR THE VOICES IN HIS HEAD  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Nathan L. Binkert<binkertn@umich.edu>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_comment
comment|/*  * SysKonnect PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_SK
value|0x1148
end_define

begin_comment
comment|/*  * Marvell PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_MARVELL
value|0x11AB
end_define

begin_comment
comment|/*  * D-Link PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDORID_DLINK
value|0x1186
end_define

begin_comment
comment|/*  * SysKonnect ethernet device IDs  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_SK_YUKON2
value|0x9000
end_define

begin_define
define|#
directive|define
name|DEVICEID_SK_YUKON2_EXPR
value|0x9e00
end_define

begin_comment
comment|/*  * Marvell gigabit ethernet device IDs  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8021CU
value|0x4340
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8022CU
value|0x4341
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8061CU
value|0x4342
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8062CU
value|0x4343
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8021X
value|0x4344
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8022X
value|0x4345
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8061X
value|0x4346
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8062X
value|0x4347
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8035
value|0x4350
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8036
value|0x4351
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_8038
value|0x4352
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_4360
value|0x4360
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_4361
value|0x4361
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_4362
value|0x4362
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_4363
value|0x4363
end_define

begin_define
define|#
directive|define
name|DEVICEID_MRVL_4364
value|0x4364
end_define

begin_comment
comment|/*  * D-Link gigabit ethernet device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_DLINK_DGE550SX
value|0x4001
end_define

begin_define
define|#
directive|define
name|DEVICEID_DLINK_DGE560T
value|0x4b00
end_define

begin_define
define|#
directive|define
name|BIT_31
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|BIT_30
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|BIT_29
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|BIT_28
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|BIT_27
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|BIT_26
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|BIT_25
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|BIT_24
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|BIT_23
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|BIT_22
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|BIT_21
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|BIT_20
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|BIT_19
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|BIT_18
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|BIT_17
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|BIT_16
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|BIT_15
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|BIT_14
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|BIT_13
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|BIT_12
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|BIT_11
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|BIT_10
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|BIT_9
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|BIT_8
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|BIT_7
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|BIT_6
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|BIT_5
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|BIT_4
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|BIT_3
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|BIT_2
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|BIT_1
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|BIT_0
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SHIFT31
parameter_list|(
name|x
parameter_list|)
value|((x)<< 31)
end_define

begin_define
define|#
directive|define
name|SHIFT30
parameter_list|(
name|x
parameter_list|)
value|((x)<< 30)
end_define

begin_define
define|#
directive|define
name|SHIFT29
parameter_list|(
name|x
parameter_list|)
value|((x)<< 29)
end_define

begin_define
define|#
directive|define
name|SHIFT28
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|SHIFT27
parameter_list|(
name|x
parameter_list|)
value|((x)<< 27)
end_define

begin_define
define|#
directive|define
name|SHIFT26
parameter_list|(
name|x
parameter_list|)
value|((x)<< 26)
end_define

begin_define
define|#
directive|define
name|SHIFT25
parameter_list|(
name|x
parameter_list|)
value|((x)<< 25)
end_define

begin_define
define|#
directive|define
name|SHIFT24
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|SHIFT23
parameter_list|(
name|x
parameter_list|)
value|((x)<< 23)
end_define

begin_define
define|#
directive|define
name|SHIFT22
parameter_list|(
name|x
parameter_list|)
value|((x)<< 22)
end_define

begin_define
define|#
directive|define
name|SHIFT21
parameter_list|(
name|x
parameter_list|)
value|((x)<< 21)
end_define

begin_define
define|#
directive|define
name|SHIFT20
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|SHIFT19
parameter_list|(
name|x
parameter_list|)
value|((x)<< 19)
end_define

begin_define
define|#
directive|define
name|SHIFT18
parameter_list|(
name|x
parameter_list|)
value|((x)<< 18)
end_define

begin_define
define|#
directive|define
name|SHIFT17
parameter_list|(
name|x
parameter_list|)
value|((x)<< 17)
end_define

begin_define
define|#
directive|define
name|SHIFT16
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|SHIFT15
parameter_list|(
name|x
parameter_list|)
value|((x)<< 15)
end_define

begin_define
define|#
directive|define
name|SHIFT14
parameter_list|(
name|x
parameter_list|)
value|((x)<< 14)
end_define

begin_define
define|#
directive|define
name|SHIFT13
parameter_list|(
name|x
parameter_list|)
value|((x)<< 13)
end_define

begin_define
define|#
directive|define
name|SHIFT12
parameter_list|(
name|x
parameter_list|)
value|((x)<< 12)
end_define

begin_define
define|#
directive|define
name|SHIFT11
parameter_list|(
name|x
parameter_list|)
value|((x)<< 11)
end_define

begin_define
define|#
directive|define
name|SHIFT10
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|SHIFT9
parameter_list|(
name|x
parameter_list|)
value|((x)<< 9)
end_define

begin_define
define|#
directive|define
name|SHIFT8
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|SHIFT7
parameter_list|(
name|x
parameter_list|)
value|((x)<< 7)
end_define

begin_define
define|#
directive|define
name|SHIFT6
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|SHIFT5
parameter_list|(
name|x
parameter_list|)
value|((x)<< 5)
end_define

begin_define
define|#
directive|define
name|SHIFT4
parameter_list|(
name|x
parameter_list|)
value|((x)<< 4)
end_define

begin_define
define|#
directive|define
name|SHIFT3
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|SHIFT2
parameter_list|(
name|x
parameter_list|)
value|((x)<< 2)
end_define

begin_define
define|#
directive|define
name|SHIFT1
parameter_list|(
name|x
parameter_list|)
value|((x)<< 1)
end_define

begin_define
define|#
directive|define
name|SHIFT0
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_comment
comment|/*  * PCI Configuration Space header  */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_1ST
value|0x10
end_define

begin_comment
comment|/* 32 bit 1st Base address */
end_comment

begin_define
define|#
directive|define
name|PCI_BASE_2ND
value|0x14
end_define

begin_comment
comment|/* 32 bit 2nd Base address */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_REG_1
value|0x40
end_define

begin_comment
comment|/* 32 bit Our Register 1 */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_REG_2
value|0x44
end_define

begin_comment
comment|/* 32 bit Our Register 2 */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_STATUS
value|0x7c
end_define

begin_comment
comment|/* 32 bit Adapter Status Register */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_REG_3
value|0x80
end_define

begin_comment
comment|/* 32 bit Our Register 3 */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_REG_4
value|0x84
end_define

begin_comment
comment|/* 32 bit Our Register 4 */
end_comment

begin_define
define|#
directive|define
name|PCI_OUR_REG_5
value|0x88
end_define

begin_comment
comment|/* 32 bit Our Register 5 */
end_comment

begin_comment
comment|/* PCI Express Capability */
end_comment

begin_define
define|#
directive|define
name|PEX_CAP_ID
value|0xe0
end_define

begin_comment
comment|/*  8 bit PEX Capability ID */
end_comment

begin_define
define|#
directive|define
name|PEX_NITEM
value|0xe1
end_define

begin_comment
comment|/*  8 bit PEX Next Item Pointer */
end_comment

begin_define
define|#
directive|define
name|PEX_CAP_REG
value|0xe2
end_define

begin_comment
comment|/* 16 bit PEX Capability Register */
end_comment

begin_define
define|#
directive|define
name|PEX_DEV_CAP
value|0xe4
end_define

begin_comment
comment|/* 32 bit PEX Device Capabilities */
end_comment

begin_define
define|#
directive|define
name|PEX_DEV_CTRL
value|0xe8
end_define

begin_comment
comment|/* 16 bit PEX Device Control */
end_comment

begin_define
define|#
directive|define
name|PEX_DEV_STAT
value|0xea
end_define

begin_comment
comment|/* 16 bit PEX Device Status */
end_comment

begin_define
define|#
directive|define
name|PEX_LNK_CAP
value|0xec
end_define

begin_comment
comment|/* 32 bit PEX Link Capabilities */
end_comment

begin_define
define|#
directive|define
name|PEX_LNK_CTRL
value|0xf0
end_define

begin_comment
comment|/* 16 bit PEX Link Control */
end_comment

begin_define
define|#
directive|define
name|PEX_LNK_STAT
value|0xf2
end_define

begin_comment
comment|/* 16 bit PEX Link Status */
end_comment

begin_comment
comment|/* PCI Express Extended Capabilities */
end_comment

begin_define
define|#
directive|define
name|PEX_ADV_ERR_REP
value|0x100
end_define

begin_comment
comment|/* 32 bit PEX Advanced Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PEX_UNC_ERR_STAT
value|0x104
end_define

begin_comment
comment|/* 32 bit PEX Uncorr. Errors Status */
end_comment

begin_define
define|#
directive|define
name|PEX_UNC_ERR_MASK
value|0x108
end_define

begin_comment
comment|/* 32 bit PEX Uncorr. Errors Mask */
end_comment

begin_define
define|#
directive|define
name|PEX_UNC_ERR_SEV
value|0x10c
end_define

begin_comment
comment|/* 32 bit PEX Uncorr. Errors Severity */
end_comment

begin_define
define|#
directive|define
name|PEX_COR_ERR_STAT
value|0x110
end_define

begin_comment
comment|/* 32 bit PEX Correc. Errors Status */
end_comment

begin_define
define|#
directive|define
name|PEX_COR_ERR_MASK
value|0x114
end_define

begin_comment
comment|/* 32 bit PEX Correc. Errors Mask */
end_comment

begin_define
define|#
directive|define
name|PEX_ADV_ERR_CAP_C
value|0x118
end_define

begin_comment
comment|/* 32 bit PEX Advanced Error Cap./Ctrl */
end_comment

begin_define
define|#
directive|define
name|PEX_HEADER_LOG
value|0x11c
end_define

begin_comment
comment|/* 4x32 bit PEX Header Log Register */
end_comment

begin_comment
comment|/*	PCI_OUR_REG_1	32 bit	Our Register 1 */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_PIG_ENA
value|BIT_31
end_define

begin_comment
comment|/* Enable Plug-in-Go (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_DLL_DIS
value|BIT_30
end_define

begin_comment
comment|/* Disable PCI DLL (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_PHY2_COMA
value|BIT_29
end_define

begin_comment
comment|/* Set PHY 2 to Coma Mode (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_PHY1_COMA
value|BIT_28
end_define

begin_comment
comment|/* Set PHY 1 to Coma Mode (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_PHY2_POWD
value|BIT_27
end_define

begin_comment
comment|/* Set PHY 2 to Power Down (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_Y2_PHY1_POWD
value|BIT_26
end_define

begin_comment
comment|/* Set PHY 1 to Power Down (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_DIS_BOOT
value|BIT_24
end_define

begin_comment
comment|/* Disable BOOT via ROM */
end_comment

begin_define
define|#
directive|define
name|PCI_EN_IO
value|BIT_23
end_define

begin_comment
comment|/* Mapping to I/O space */
end_comment

begin_define
define|#
directive|define
name|PCI_EN_FPROM
value|BIT_22
end_define

begin_comment
comment|/* Enable FLASH mapping to memory */
end_comment

begin_comment
comment|/* 1 = Map Flash to memory */
end_comment

begin_comment
comment|/* 0 = Disable addr. dec */
end_comment

begin_define
define|#
directive|define
name|PCI_PAGESIZE
value|(3L<<20)
end_define

begin_comment
comment|/* Bit 21..20:	FLASH Page Size	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PAGE_16
value|(0L<<20)
end_define

begin_comment
comment|/*		16 k pages	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PAGE_32K
value|(1L<<20)
end_define

begin_comment
comment|/*		32 k pages	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PAGE_64K
value|(2L<<20)
end_define

begin_comment
comment|/*		64 k pages	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PAGE_128K
value|(3L<<20)
end_define

begin_comment
comment|/*		128 k pages	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PAGEREG
value|(7L<<16)
end_define

begin_comment
comment|/* Bit 18..16:	Page Register	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PEX_LEGNAT
value|BIT_15
end_define

begin_comment
comment|/* PEX PM legacy/native mode (YUKON-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_FORCE_BE
value|BIT_14
end_define

begin_comment
comment|/* Assert all BEs on MR */
end_comment

begin_define
define|#
directive|define
name|PCI_DIS_MRL
value|BIT_13
end_define

begin_comment
comment|/* Disable Mem Read Line */
end_comment

begin_define
define|#
directive|define
name|PCI_DIS_MRM
value|BIT_12
end_define

begin_comment
comment|/* Disable Mem Read Multiple */
end_comment

begin_define
define|#
directive|define
name|PCI_DIS_MWI
value|BIT_11
end_define

begin_comment
comment|/* Disable Mem Write& Invalidate */
end_comment

begin_define
define|#
directive|define
name|PCI_DISC_CLS
value|BIT_10
end_define

begin_comment
comment|/* Disc: cacheLsz bound */
end_comment

begin_define
define|#
directive|define
name|PCI_BURST_DIS
value|BIT_9
end_define

begin_comment
comment|/* Burst Disable */
end_comment

begin_define
define|#
directive|define
name|PCI_DIS_PCI_CLK
value|BIT_8
end_define

begin_comment
comment|/* Disable PCI clock driving */
end_comment

begin_define
define|#
directive|define
name|PCI_SKEW_DAS
value|(0xfL<<4)
end_define

begin_comment
comment|/* Bit	7.. 4:	Skew Ctrl, DAS Ext */
end_comment

begin_define
define|#
directive|define
name|PCI_SKEW_BASE
value|0xfL
end_define

begin_comment
comment|/* Bit	3.. 0:	Skew Ctrl, Base	*/
end_comment

begin_define
define|#
directive|define
name|PCI_CLS_OPT
value|BIT_3
end_define

begin_comment
comment|/* Cache Line Size opt. PCI-X (YUKON-2) */
end_comment

begin_comment
comment|/*	PCI_OUR_REG_2	32 bit	Our Register 2 */
end_comment

begin_define
define|#
directive|define
name|PCI_VPD_WR_THR
value|(0xff<<24)
end_define

begin_comment
comment|/* Bit 31..24:	VPD Write Threshold */
end_comment

begin_define
define|#
directive|define
name|PCI_DEV_SEL
value|(0x7f<<17)
end_define

begin_comment
comment|/* Bit 23..17:	EEPROM Device Select */
end_comment

begin_define
define|#
directive|define
name|PCI_VPD_ROM_SZ
value|(0x07<<14)
end_define

begin_comment
comment|/* Bit 16..14:	VPD ROM Size	*/
end_comment

begin_comment
comment|/* Bit 13..12:	reserved	*/
end_comment

begin_define
define|#
directive|define
name|PCI_PATCH_DIR
value|(0x0f<<8)
end_define

begin_comment
comment|/* Bit 11.. 8:	Ext Patches dir 3..0 */
end_comment

begin_define
define|#
directive|define
name|PCI_PATCH_DIR_3
value|BIT_11
end_define

begin_define
define|#
directive|define
name|PCI_PATCH_DIR_2
value|BIT_10
end_define

begin_define
define|#
directive|define
name|PCI_PATCH_DIR_1
value|BIT_9
end_define

begin_define
define|#
directive|define
name|PCI_PATCH_DIR_0
value|BIT_8
end_define

begin_define
define|#
directive|define
name|PCI_EXT_PATCHS
value|(0x0f<<4)
end_define

begin_comment
comment|/* Bit	7.. 4:	Extended Patches 3..0 */
end_comment

begin_define
define|#
directive|define
name|PCI_EXT_PATCH_3
value|BIT_7
end_define

begin_define
define|#
directive|define
name|PCI_EXT_PATCH_2
value|BIT_6
end_define

begin_define
define|#
directive|define
name|PCI_EXT_PATCH_1
value|BIT_5
end_define

begin_define
define|#
directive|define
name|PCI_EXT_PATCH_0
value|BIT_4
end_define

begin_define
define|#
directive|define
name|PCI_EN_DUMMY_RD
value|BIT_3
end_define

begin_comment
comment|/* Enable Dummy Read */
end_comment

begin_define
define|#
directive|define
name|PCI_REV_DESC
value|BIT_2
end_define

begin_comment
comment|/* Reverse Desc. Bytes */
end_comment

begin_define
define|#
directive|define
name|PCI_USEDATA64
value|BIT_0
end_define

begin_comment
comment|/* Use 64Bit Data bus ext */
end_comment

begin_comment
comment|/* PCI_OUR_STATUS	32 bit	Adapter Status Register (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_PCI64B
value|BIT_31
end_define

begin_comment
comment|/* Conventional PCI 64 bits Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_PCIX
value|BIT_30
end_define

begin_comment
comment|/* PCI-X Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_MODE_MSK
value|(3<<28)
end_define

begin_comment
comment|/* Bit 29..28:	PCI-X Bus Mode Mask */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_PCI66M
value|BIT_27
end_define

begin_comment
comment|/* PCI 66 MHz Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_PCI_X
value|BIT_26
end_define

begin_comment
comment|/* PCI/PCI-X Bus (0 = PEX) */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_DLLE_MSK
value|(3<<24)
end_define

begin_comment
comment|/* Bit 25..24:	DLL Status Indication */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_DLLR_MSK
value|(0x0f<<20)
end_define

begin_comment
comment|/* Bit 23..20:	DLL Row Counters Values */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_DLLC_MSK
value|(0x0f<<16)
end_define

begin_comment
comment|/* Bit 19..16:	DLL Col. Counters Values */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_SPEED
parameter_list|(
name|val
parameter_list|)
value|((val& PCI_OS_MODE_MSK)>> 28)
end_define

begin_comment
comment|/* PCI-X Speed */
end_comment

begin_comment
comment|/* possible values for the speed field of the register */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_SPD_PCI
value|0
end_define

begin_comment
comment|/* PCI Conventional Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_SPD_X66
value|1
end_define

begin_comment
comment|/* PCI-X 66MHz Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_SPD_X100
value|2
end_define

begin_comment
comment|/* PCI-X 100MHz Bus */
end_comment

begin_define
define|#
directive|define
name|PCI_OS_SPD_X133
value|3
end_define

begin_comment
comment|/* PCI-X 133MHz Bus */
end_comment

begin_comment
comment|/* PCI_OUR_REG_4	32 bit	Our Register 4 (Yukon-ECU only) */
end_comment

begin_define
define|#
directive|define
name|PCI_TIMER_VALUE_MSK
value|(0xff<<16)
end_define

begin_comment
comment|/* Bit 23..16:	Timer Value Mask */
end_comment

begin_define
define|#
directive|define
name|PCI_FORCE_ASPM_REQUEST
value|BIT_15
end_define

begin_comment
comment|/* Force ASPM Request (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_GPHY_LINK_DOWN
value|BIT_14
end_define

begin_comment
comment|/* GPHY Link Down (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_INT_FIFO_EMPTY
value|BIT_13
end_define

begin_comment
comment|/* Internal FIFO Empty (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_CLKRUN_REQUEST
value|BIT_12
end_define

begin_comment
comment|/* CLKRUN Request (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_FORCE_CLKREQ_ENA
value|BIT_4
end_define

begin_comment
comment|/* Force CLKREQ Enable (A1b only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_CLKREQ_PAD_CTL
value|BIT_3
end_define

begin_comment
comment|/* CLKREQ PAD Control (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_ASPM_A1_MODE_SELECT
value|BIT_2
end_define

begin_comment
comment|/* A1 Mode Select (A1 only) */
end_comment

begin_define
define|#
directive|define
name|PCI_CLK_GATE_PEX_UNIT_ENA
value|BIT_1
end_define

begin_comment
comment|/* Enable Gate PEX Unit Clock */
end_comment

begin_define
define|#
directive|define
name|PCI_CLK_GATE_ROOT_COR_ENA
value|BIT_0
end_define

begin_comment
comment|/* Enable Gate Root Core Clock */
end_comment

begin_comment
comment|/* PEX_DEV_CTRL	16 bit	PEX Device Control (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_MAX_RRS_MSK
value|(7<<12)
end_define

begin_comment
comment|/* Bit 14..12:	Max. Read Request Size */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_NO_SNOOP
value|BIT_11
end_define

begin_comment
comment|/* Enable No Snoop */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_AUX_POW
value|BIT_10
end_define

begin_comment
comment|/* Enable AUX Power */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_PHANTOM
value|BIT_9
end_define

begin_comment
comment|/* Enable Phantom Functions */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_EXT_TAG
value|BIT_8
end_define

begin_comment
comment|/* Enable Extended Tag Field */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_MAX_PLS_MSK
value|(7<<5)
end_define

begin_comment
comment|/* Bit  7.. 5:	Max. Payload Size Mask */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_REL_ORD
value|BIT_4
end_define

begin_comment
comment|/* Enable Relaxed Ordering */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_UNS_RQ_RP
value|BIT_3
end_define

begin_comment
comment|/* Enable Unsupported Request Reporting */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_FAT_ER_RP
value|BIT_2
end_define

begin_comment
comment|/* Enable Fatal Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_NFA_ER_RP
value|BIT_1
end_define

begin_comment
comment|/* Enable Non-Fatal Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_EN_COR_ER_RP
value|BIT_0
end_define

begin_comment
comment|/* Enable Correctable Error Reporting */
end_comment

begin_define
define|#
directive|define
name|PEX_DC_MAX_RD_RQ_SIZE
parameter_list|(
name|x
parameter_list|)
value|(SHIFT12(x)& PEX_DC_MAX_RRS_MSK)
end_define

begin_comment
comment|/* PEX_LNK_STAT	16 bit	PEX Link Status (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|PEX_LS_SLOT_CLK_CFG
value|BIT_12
end_define

begin_comment
comment|/* Slot Clock Config */
end_comment

begin_define
define|#
directive|define
name|PEX_LS_LINK_TRAIN
value|BIT_11
end_define

begin_comment
comment|/* Link Training */
end_comment

begin_define
define|#
directive|define
name|PEX_LS_TRAIN_ERROR
value|BIT_10
end_define

begin_comment
comment|/* Training Error */
end_comment

begin_define
define|#
directive|define
name|PEX_LS_LINK_WI_MSK
value|(0x3f<<4)
end_define

begin_comment
comment|/* Bit  9.. 4: Neg. Link Width Mask */
end_comment

begin_define
define|#
directive|define
name|PEX_LS_LINK_SP_MSK
value|0x0f
end_define

begin_comment
comment|/* Bit  3.. 0:	Link Speed Mask */
end_comment

begin_comment
comment|/* PEX_UNC_ERR_STAT PEX Uncorrectable Errors Status Register (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|PEX_UNSUP_REQ
value|BIT_20
end_define

begin_comment
comment|/* Unsupported Request Error */
end_comment

begin_define
define|#
directive|define
name|PEX_MALFOR_TLP
value|BIT_18
end_define

begin_comment
comment|/* Malformed TLP */
end_comment

begin_define
define|#
directive|define
name|PEX_RX_OV
value|BIT_17
end_define

begin_comment
comment|/* Receiver Overflow (not supported) */
end_comment

begin_define
define|#
directive|define
name|PEX_UNEXP_COMP
value|BIT_16
end_define

begin_comment
comment|/* Unexpected Completion */
end_comment

begin_define
define|#
directive|define
name|PEX_COMP_TO
value|BIT_14
end_define

begin_comment
comment|/* Completion Timeout */
end_comment

begin_define
define|#
directive|define
name|PEX_FLOW_CTRL_P
value|BIT_13
end_define

begin_comment
comment|/* Flow Control Protocol Error */
end_comment

begin_define
define|#
directive|define
name|PEX_POIS_TLP
value|BIT_12
end_define

begin_comment
comment|/* Poisoned TLP */
end_comment

begin_define
define|#
directive|define
name|PEX_DATA_LINK_P
value|BIT_4
end_define

begin_comment
comment|/* Data Link Protocol Error */
end_comment

begin_define
define|#
directive|define
name|PEX_FATAL_ERRORS
value|(PEX_MALFOR_TLP | PEX_FLOW_CTRL_P | PEX_DATA_LINK_P)
end_define

begin_comment
comment|/*	Control Register File (Address Map) */
end_comment

begin_comment
comment|/*  *	Bank 0  */
end_comment

begin_define
define|#
directive|define
name|B0_RAP
value|0x0000
end_define

begin_comment
comment|/*  8 bit Register Address Port */
end_comment

begin_define
define|#
directive|define
name|B0_CTST
value|0x0004
end_define

begin_comment
comment|/* 16 bit Control/Status register */
end_comment

begin_define
define|#
directive|define
name|B0_LED
value|0x0006
end_define

begin_comment
comment|/*  8 Bit LED register */
end_comment

begin_define
define|#
directive|define
name|B0_POWER_CTRL
value|0x0007
end_define

begin_comment
comment|/*  8 Bit Power Control reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|B0_ISRC
value|0x0008
end_define

begin_comment
comment|/* 32 bit Interrupt Source Register */
end_comment

begin_define
define|#
directive|define
name|B0_IMSK
value|0x000c
end_define

begin_comment
comment|/* 32 bit Interrupt Mask Register */
end_comment

begin_define
define|#
directive|define
name|B0_HWE_ISRC
value|0x0010
end_define

begin_comment
comment|/* 32 bit HW Error Interrupt Src Reg */
end_comment

begin_define
define|#
directive|define
name|B0_HWE_IMSK
value|0x0014
end_define

begin_comment
comment|/* 32 bit HW Error Interrupt Mask Reg */
end_comment

begin_define
define|#
directive|define
name|B0_SP_ISRC
value|0x0018
end_define

begin_comment
comment|/* 32 bit Special Interrupt Source Reg 1 */
end_comment

begin_comment
comment|/* Special ISR registers (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|B0_Y2_SP_ISRC2
value|0x001c
end_define

begin_comment
comment|/* 32 bit Special Interrupt Source Reg 2 */
end_comment

begin_define
define|#
directive|define
name|B0_Y2_SP_ISRC3
value|0x0020
end_define

begin_comment
comment|/* 32 bit Special Interrupt Source Reg 3 */
end_comment

begin_define
define|#
directive|define
name|B0_Y2_SP_EISR
value|0x0024
end_define

begin_comment
comment|/* 32 bit Enter ISR Reg */
end_comment

begin_define
define|#
directive|define
name|B0_Y2_SP_LISR
value|0x0028
end_define

begin_comment
comment|/* 32 bit Leave ISR Reg */
end_comment

begin_define
define|#
directive|define
name|B0_Y2_SP_ICR
value|0x002c
end_define

begin_comment
comment|/* 32 bit Interrupt Control Reg */
end_comment

begin_comment
comment|/*  *	Bank 1  *	- completely empty (this is the RAP Block window)  *	Note: if RAP = 1 this page is reserved  */
end_comment

begin_comment
comment|/*  *	Bank 2  */
end_comment

begin_comment
comment|/* NA reg = 48 bit Network Address Register, 3x16 or 8x8 bit readable */
end_comment

begin_define
define|#
directive|define
name|B2_MAC_1
value|0x0100
end_define

begin_comment
comment|/* NA reg MAC Address 1 */
end_comment

begin_define
define|#
directive|define
name|B2_MAC_2
value|0x0108
end_define

begin_comment
comment|/* NA reg MAC Address 2 */
end_comment

begin_define
define|#
directive|define
name|B2_MAC_3
value|0x0110
end_define

begin_comment
comment|/* NA reg MAC Address 3 */
end_comment

begin_define
define|#
directive|define
name|B2_CONN_TYP
value|0x0118
end_define

begin_comment
comment|/*  8 bit Connector type */
end_comment

begin_define
define|#
directive|define
name|B2_PMD_TYP
value|0x0119
end_define

begin_comment
comment|/*  8 bit PMD type */
end_comment

begin_define
define|#
directive|define
name|B2_MAC_CFG
value|0x011a
end_define

begin_comment
comment|/*  8 bit MAC Configuration / Chip Revision */
end_comment

begin_define
define|#
directive|define
name|B2_CHIP_ID
value|0x011b
end_define

begin_comment
comment|/*  8 bit Chip Identification Number */
end_comment

begin_define
define|#
directive|define
name|B2_E_0
value|0x011c
end_define

begin_comment
comment|/*  8 bit EPROM Byte 0 (ext. SRAM size */
end_comment

begin_define
define|#
directive|define
name|B2_Y2_CLK_GATE
value|0x011d
end_define

begin_comment
comment|/*  8 bit Clock Gating (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|B2_Y2_HW_RES
value|0x011e
end_define

begin_comment
comment|/*  8 bit HW Resources (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|B2_E_3
value|0x011f
end_define

begin_comment
comment|/*  8 bit EPROM Byte 3 */
end_comment

begin_define
define|#
directive|define
name|B2_Y2_CLK_CTRL
value|0x0120
end_define

begin_comment
comment|/* 32 bit Core Clock Frequency Control */
end_comment

begin_define
define|#
directive|define
name|B2_TI_INI
value|0x0130
end_define

begin_comment
comment|/* 32 bit Timer Init Value */
end_comment

begin_define
define|#
directive|define
name|B2_TI_VAL
value|0x0134
end_define

begin_comment
comment|/* 32 bit Timer Value */
end_comment

begin_define
define|#
directive|define
name|B2_TI_CTRL
value|0x0138
end_define

begin_comment
comment|/*  8 bit Timer Control */
end_comment

begin_define
define|#
directive|define
name|B2_TI_TEST
value|0x0139
end_define

begin_comment
comment|/*  8 Bit Timer Test */
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_INI
value|0x0140
end_define

begin_comment
comment|/* 32 bit IRQ Moderation Timer Init Reg.*/
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_VAL
value|0x0144
end_define

begin_comment
comment|/* 32 bit IRQ Moderation Timer Value */
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_CTRL
value|0x0148
end_define

begin_comment
comment|/*  8 bit IRQ Moderation Timer Control */
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_TEST
value|0x0149
end_define

begin_comment
comment|/*  8 bit IRQ Moderation Timer Test */
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_MSK
value|0x014c
end_define

begin_comment
comment|/* 32 bit IRQ Moderation Mask */
end_comment

begin_define
define|#
directive|define
name|B2_IRQM_HWE_MSK
value|0x0150
end_define

begin_comment
comment|/* 32 bit IRQ Moderation HW Error Mask */
end_comment

begin_define
define|#
directive|define
name|B2_TST_CTRL1
value|0x0158
end_define

begin_comment
comment|/*  8 bit Test Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|B2_TST_CTRL2
value|0x0159
end_define

begin_comment
comment|/*  8 bit Test Control Register 2 */
end_comment

begin_define
define|#
directive|define
name|B2_GP_IO
value|0x015c
end_define

begin_comment
comment|/* 32 bit General Purpose I/O Register */
end_comment

begin_define
define|#
directive|define
name|B2_I2C_CTRL
value|0x0160
end_define

begin_comment
comment|/* 32 bit I2C HW Control Register */
end_comment

begin_define
define|#
directive|define
name|B2_I2C_DATA
value|0x0164
end_define

begin_comment
comment|/* 32 bit I2C HW Data Register */
end_comment

begin_define
define|#
directive|define
name|B2_I2C_IRQ
value|0x0168
end_define

begin_comment
comment|/* 32 bit I2C HW IRQ Register */
end_comment

begin_define
define|#
directive|define
name|B2_I2C_SW
value|0x016c
end_define

begin_comment
comment|/* 32 bit I2C SW Port Register */
end_comment

begin_define
define|#
directive|define
name|Y2_PEX_PHY_DATA
value|0x0170
end_define

begin_comment
comment|/* 16 bit PEX PHY Data Register */
end_comment

begin_define
define|#
directive|define
name|Y2_PEX_PHY_ADDR
value|0x0172
end_define

begin_comment
comment|/* 16 bit PEX PHY Address Register */
end_comment

begin_comment
comment|/*  *	Bank 3  */
end_comment

begin_comment
comment|/* RAM Random Registers */
end_comment

begin_define
define|#
directive|define
name|B3_RAM_ADDR
value|0x0180
end_define

begin_comment
comment|/* 32 bit RAM Address, to read or write */
end_comment

begin_define
define|#
directive|define
name|B3_RAM_DATA_LO
value|0x0184
end_define

begin_comment
comment|/* 32 bit RAM Data Word (low dWord) */
end_comment

begin_define
define|#
directive|define
name|B3_RAM_DATA_HI
value|0x0188
end_define

begin_comment
comment|/* 32 bit RAM Data Word (high dWord) */
end_comment

begin_define
define|#
directive|define
name|SELECT_RAM_BUFFER
parameter_list|(
name|rb
parameter_list|,
name|addr
parameter_list|)
value|(addr | (rb<< 6))
end_define

begin_comment
comment|/* Yukon-2 only */
end_comment

begin_comment
comment|/* RAM Interface Registers */
end_comment

begin_comment
comment|/* Yukon-2: use SELECT_RAM_BUFFER() to access the RAM buffer */
end_comment

begin_comment
comment|/*  * The HW-Spec. calls this registers Timeout Value 0..11. But this names are  * not usable in SW. Please notice these are NOT real timeouts, these are  * the number of qWords transferred continuously.  */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_R1
value|0x0190
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue R1 (TO0) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_XA1
value|0x0191
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue XA1 (TO1) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_XS1
value|0x0192
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue XS1 (TO2) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_R1
value|0x0193
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue R1 (TO3) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_XA1
value|0x0194
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue XA1 (TO4) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_XS1
value|0x0195
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue XS1 (TO5) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_R2
value|0x0196
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue R2 (TO6) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_XA2
value|0x0197
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue XA2 (TO7) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_WTO_XS2
value|0x0198
end_define

begin_comment
comment|/*  8 bit WR Timeout Queue XS2 (TO8) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_R2
value|0x0199
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue R2 (TO9) */
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_XA2
value|0x019a
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue XA2 (TO10)*/
end_comment

begin_define
define|#
directive|define
name|B3_RI_RTO_XS2
value|0x019b
end_define

begin_comment
comment|/*  8 bit RD Timeout Queue XS2 (TO11)*/
end_comment

begin_define
define|#
directive|define
name|B3_RI_TO_VAL
value|0x019c
end_define

begin_comment
comment|/*  8 bit Current Timeout Count Val */
end_comment

begin_define
define|#
directive|define
name|B3_RI_CTRL
value|0x01a0
end_define

begin_comment
comment|/* 16 bit RAM Interface Control Register */
end_comment

begin_define
define|#
directive|define
name|B3_RI_TEST
value|0x01a2
end_define

begin_comment
comment|/*  8 bit RAM Interface Test Register */
end_comment

begin_comment
comment|/*  *	Bank 4 - 5  */
end_comment

begin_comment
comment|/* Transmit Arbiter Registers MAC 1 and 2, use MR_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|TXA_ITI_INI
value|0x0200
end_define

begin_comment
comment|/* 32 bit Tx Arb Interval Timer Init Val*/
end_comment

begin_define
define|#
directive|define
name|TXA_ITI_VAL
value|0x0204
end_define

begin_comment
comment|/* 32 bit Tx Arb Interval Timer Value */
end_comment

begin_define
define|#
directive|define
name|TXA_LIM_INI
value|0x0208
end_define

begin_comment
comment|/* 32 bit Tx Arb Limit Counter Init Val */
end_comment

begin_define
define|#
directive|define
name|TXA_LIM_VAL
value|0x020c
end_define

begin_comment
comment|/* 32 bit Tx Arb Limit Counter Value */
end_comment

begin_define
define|#
directive|define
name|TXA_CTRL
value|0x0210
end_define

begin_comment
comment|/*  8 bit Tx Arbiter Control Register */
end_comment

begin_define
define|#
directive|define
name|TXA_TEST
value|0x0211
end_define

begin_comment
comment|/*  8 bit Tx Arbiter Test Register */
end_comment

begin_define
define|#
directive|define
name|TXA_STAT
value|0x0212
end_define

begin_comment
comment|/*  8 bit Tx Arbiter Status Register */
end_comment

begin_define
define|#
directive|define
name|MR_ADDR
parameter_list|(
name|Mac
parameter_list|,
name|Offs
parameter_list|)
value|(((Mac)<< 7) + (Offs))
end_define

begin_comment
comment|/* RSS key registers for Yukon-2 Family */
end_comment

begin_define
define|#
directive|define
name|B4_RSS_KEY
value|0x0220
end_define

begin_comment
comment|/* 4x32 bit RSS Key register (Yukon-2) */
end_comment

begin_comment
comment|/* RSS key register offsets */
end_comment

begin_define
define|#
directive|define
name|KEY_IDX_0
value|0
end_define

begin_comment
comment|/* offset for location of KEY 0 */
end_comment

begin_define
define|#
directive|define
name|KEY_IDX_1
value|4
end_define

begin_comment
comment|/* offset for location of KEY 1 */
end_comment

begin_define
define|#
directive|define
name|KEY_IDX_2
value|8
end_define

begin_comment
comment|/* offset for location of KEY 2 */
end_comment

begin_define
define|#
directive|define
name|KEY_IDX_3
value|12
end_define

begin_comment
comment|/* offset for location of KEY 3 */
end_comment

begin_comment
comment|/* 0x0280 - 0x0292:	MAC 2 */
end_comment

begin_define
define|#
directive|define
name|RSS_KEY_ADDR
parameter_list|(
name|Port
parameter_list|,
name|KeyIndex
parameter_list|)
define|\
value|((B4_RSS_KEY | ( ((Port) == 0) ? 0 : 0x80)) + (KeyIndex))
end_define

begin_comment
comment|/*  *	Bank 8 - 15  */
end_comment

begin_comment
comment|/* Receive and Transmit Queue Registers, use Q_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|B8_Q_REGS
value|0x0400
end_define

begin_comment
comment|/* Queue Register Offsets, use Q_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|Q_D
value|0x00
end_define

begin_comment
comment|/* 8*32	bit Current Descriptor */
end_comment

begin_define
define|#
directive|define
name|Q_DA_L
value|0x20
end_define

begin_comment
comment|/* 32 bit Current Descriptor Address Low dWord */
end_comment

begin_define
define|#
directive|define
name|Q_DONE
value|0x24
end_define

begin_comment
comment|/* 16 bit Done Index */
end_comment

begin_define
define|#
directive|define
name|Q_AC_L
value|0x28
end_define

begin_comment
comment|/* 32 bit Current Address Counter Low dWord */
end_comment

begin_define
define|#
directive|define
name|Q_AC_H
value|0x2c
end_define

begin_comment
comment|/* 32 bit Current Address Counter High dWord */
end_comment

begin_define
define|#
directive|define
name|Q_BC
value|0x30
end_define

begin_comment
comment|/* 32 bit Current Byte Counter */
end_comment

begin_define
define|#
directive|define
name|Q_CSR
value|0x34
end_define

begin_comment
comment|/* 32 bit BMU Control/Status Register */
end_comment

begin_define
define|#
directive|define
name|Q_F
value|0x38
end_define

begin_comment
comment|/* 32 bit Flag Register */
end_comment

begin_define
define|#
directive|define
name|Q_T1
value|0x3c
end_define

begin_comment
comment|/* 32 bit Test Register 1 */
end_comment

begin_define
define|#
directive|define
name|Q_T1_TR
value|0x3c
end_define

begin_comment
comment|/*  8 bit Test Register 1 Transfer SM */
end_comment

begin_define
define|#
directive|define
name|Q_T1_WR
value|0x3d
end_define

begin_comment
comment|/*  8 bit Test Register 1 Write Descriptor SM */
end_comment

begin_define
define|#
directive|define
name|Q_T1_RD
value|0x3e
end_define

begin_comment
comment|/*  8 bit Test Register 1 Read Descriptor SM */
end_comment

begin_define
define|#
directive|define
name|Q_T1_SV
value|0x3f
end_define

begin_comment
comment|/*  8 bit Test Register 1 Supervisor SM */
end_comment

begin_define
define|#
directive|define
name|Q_WM
value|0x40
end_define

begin_comment
comment|/* 16 bit FIFO Watermark */
end_comment

begin_define
define|#
directive|define
name|Q_AL
value|0x42
end_define

begin_comment
comment|/*  8 bit FIFO Alignment */
end_comment

begin_define
define|#
directive|define
name|Q_RSP
value|0x44
end_define

begin_comment
comment|/* 16 bit FIFO Read Shadow Pointer */
end_comment

begin_define
define|#
directive|define
name|Q_RSL
value|0x46
end_define

begin_comment
comment|/*  8 bit FIFO Read Shadow Level */
end_comment

begin_define
define|#
directive|define
name|Q_RP
value|0x48
end_define

begin_comment
comment|/*  8 bit FIFO Read Pointer */
end_comment

begin_define
define|#
directive|define
name|Q_RL
value|0x4a
end_define

begin_comment
comment|/*  8 bit FIFO Read Level */
end_comment

begin_define
define|#
directive|define
name|Q_WP
value|0x4c
end_define

begin_comment
comment|/*  8 bit FIFO Write Pointer */
end_comment

begin_define
define|#
directive|define
name|Q_WSP
value|0x4d
end_define

begin_comment
comment|/*  8 bit FIFO Write Shadow Pointer */
end_comment

begin_define
define|#
directive|define
name|Q_WL
value|0x4e
end_define

begin_comment
comment|/*  8 bit FIFO Write Level */
end_comment

begin_define
define|#
directive|define
name|Q_WSL
value|0x4f
end_define

begin_comment
comment|/*  8 bit FIFO Write Shadow Level */
end_comment

begin_define
define|#
directive|define
name|Q_ADDR
parameter_list|(
name|Queue
parameter_list|,
name|Offs
parameter_list|)
value|(B8_Q_REGS + (Queue) + (Offs))
end_define

begin_comment
comment|/* Queue Prefetch Unit Offsets, use Y2_PREF_Q_ADDR() to address */
end_comment

begin_define
define|#
directive|define
name|Y2_B8_PREF_REGS
value|0x0450
end_define

begin_define
define|#
directive|define
name|PREF_UNIT_CTRL_REG
value|0x00
end_define

begin_comment
comment|/* 32 bit Prefetch Control register */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_LAST_IDX_REG
value|0x04
end_define

begin_comment
comment|/* 16 bit Last Index */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_ADDR_LOW_REG
value|0x08
end_define

begin_comment
comment|/* 32 bit List start addr, low part */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_ADDR_HI_REG
value|0x0c
end_define

begin_comment
comment|/* 32 bit List start addr, high part*/
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_GET_IDX_REG
value|0x10
end_define

begin_comment
comment|/* 16 bit Get Index */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_PUT_IDX_REG
value|0x14
end_define

begin_comment
comment|/* 16 bit Put Index */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_FIFO_WP_REG
value|0x20
end_define

begin_comment
comment|/*  8 bit FIFO write pointer */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_FIFO_RP_REG
value|0x24
end_define

begin_comment
comment|/*  8 bit FIFO read pointer */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_FIFO_WM_REG
value|0x28
end_define

begin_comment
comment|/*  8 bit FIFO watermark */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_FIFO_LEV_REG
value|0x2c
end_define

begin_comment
comment|/*  8 bit FIFO level */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_MASK_IDX
value|0x0fff
end_define

begin_define
define|#
directive|define
name|Y2_PREF_Q_ADDR
parameter_list|(
name|Queue
parameter_list|,
name|Offs
parameter_list|)
value|(Y2_B8_PREF_REGS + (Queue) + (Offs))
end_define

begin_comment
comment|/*  *	Bank 16 - 23  */
end_comment

begin_comment
comment|/* RAM Buffer Registers */
end_comment

begin_define
define|#
directive|define
name|B16_RAM_REGS
value|0x0800
end_define

begin_comment
comment|/* RAM Buffer Register Offsets, use RB_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|RB_START
value|0x00
end_define

begin_comment
comment|/* 32 bit RAM Buffer Start Address */
end_comment

begin_define
define|#
directive|define
name|RB_END
value|0x04
end_define

begin_comment
comment|/* 32 bit RAM Buffer End Address */
end_comment

begin_define
define|#
directive|define
name|RB_WP
value|0x08
end_define

begin_comment
comment|/* 32 bit RAM Buffer Write Pointer */
end_comment

begin_define
define|#
directive|define
name|RB_RP
value|0x0c
end_define

begin_comment
comment|/* 32 bit RAM Buffer Read Pointer */
end_comment

begin_define
define|#
directive|define
name|RB_RX_UTPP
value|0x10
end_define

begin_comment
comment|/* 32 bit Rx Upper Threshold, Pause Packet */
end_comment

begin_define
define|#
directive|define
name|RB_RX_LTPP
value|0x14
end_define

begin_comment
comment|/* 32 bit Rx Lower Threshold, Pause Packet */
end_comment

begin_define
define|#
directive|define
name|RB_RX_UTHP
value|0x18
end_define

begin_comment
comment|/* 32 bit Rx Upper Threshold, High Prio */
end_comment

begin_define
define|#
directive|define
name|RB_RX_LTHP
value|0x1c
end_define

begin_comment
comment|/* 32 bit Rx Lower Threshold, High Prio */
end_comment

begin_define
define|#
directive|define
name|RB_PC
value|0x20
end_define

begin_comment
comment|/* 32 bit RAM Buffer Packet Counter */
end_comment

begin_define
define|#
directive|define
name|RB_LEV
value|0x24
end_define

begin_comment
comment|/* 32 bit RAM Buffer Level Register */
end_comment

begin_define
define|#
directive|define
name|RB_CTRL
value|0x28
end_define

begin_comment
comment|/*  8 bit RAM Buffer Control Register */
end_comment

begin_define
define|#
directive|define
name|RB_TST1
value|0x29
end_define

begin_comment
comment|/*  8 bit RAM Buffer Test Register 1 */
end_comment

begin_define
define|#
directive|define
name|RB_TST2
value|0x2a
end_define

begin_comment
comment|/*  8 bit RAM Buffer Test Register 2 */
end_comment

begin_comment
comment|/*  *	Bank 24  */
end_comment

begin_comment
comment|/* Receive GMAC FIFO (YUKON and Yukon-2), use MR_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_EA
value|0x0c40
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO End Address */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_AF_THR
value|0x0c44
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Almost Full Thresh. */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_CTRL_T
value|0x0c48
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Control/Test */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_FL_MSK
value|0x0c4c
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Flush Mask */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_FL_THR
value|0x0c50
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Flush Threshold */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_TR_THR
value|0x0c54
end_define

begin_comment
comment|/* 32 bit Rx Truncation Threshold (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_UP_THR
value|0x0c58
end_define

begin_comment
comment|/*  8 bit Rx Upper Pause Thr (Yukon-EC_U) */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_LP_THR
value|0x0c5a
end_define

begin_comment
comment|/*  8 bit Rx Lower Pause Thr (Yukon-EC_U) */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_VLAN
value|0x0c5c
end_define

begin_comment
comment|/* 32 bit Rx VLAN Type Register (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_WP
value|0x0c60
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Write Pointer */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_WLEV
value|0x0c68
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Write Level */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_RP
value|0x0c70
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Read Pointer */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_RLEV
value|0x0c78
end_define

begin_comment
comment|/* 32 bit Rx GMAC FIFO Read Level */
end_comment

begin_comment
comment|/*  *	Bank 25  */
end_comment

begin_comment
comment|/* 0x0c80 - 0x0cbf:	MAC 2 */
end_comment

begin_comment
comment|/* 0x0cc0 - 0x0cff:	reserved */
end_comment

begin_comment
comment|/*  *	Bank 26  */
end_comment

begin_comment
comment|/* Transmit GMAC FIFO (YUKON and Yukon-2), use MR_ADDR() to access */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_EA
value|0x0d40
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO End Address */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_AE_THR
value|0x0d44
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Almost Empty Thresh.*/
end_comment

begin_define
define|#
directive|define
name|TX_GMF_CTRL_T
value|0x0d48
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Control/Test */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_VLAN
value|0x0d5c
end_define

begin_comment
comment|/* 32 bit Tx VLAN Type Register (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_WP
value|0x0d60
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Write Pointer */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_WSP
value|0x0d64
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Write Shadow Pointer */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_WLEV
value|0x0d68
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Write Level */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_RP
value|0x0d70
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Read Pointer */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_RSTP
value|0x0d74
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Restart Pointer */
end_comment

begin_define
define|#
directive|define
name|TX_GMF_RLEV
value|0x0d78
end_define

begin_comment
comment|/* 32 bit Tx GMAC FIFO Read Level */
end_comment

begin_comment
comment|/*  *	Bank 27  */
end_comment

begin_comment
comment|/* 0x0d80 - 0x0dbf:	MAC 2 */
end_comment

begin_comment
comment|/* 0x0daa - 0x0dff:	reserved */
end_comment

begin_comment
comment|/*  *	Bank 28  */
end_comment

begin_comment
comment|/* Descriptor Poll Timer Registers */
end_comment

begin_define
define|#
directive|define
name|B28_DPT_INI
value|0x0e00
end_define

begin_comment
comment|/* 24 bit Descriptor Poll Timer Init Val */
end_comment

begin_define
define|#
directive|define
name|B28_DPT_VAL
value|0x0e04
end_define

begin_comment
comment|/* 24 bit Descriptor Poll Timer Curr Val */
end_comment

begin_define
define|#
directive|define
name|B28_DPT_CTRL
value|0x0e08
end_define

begin_comment
comment|/*  8 bit Descriptor Poll Timer Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|B28_DPT_TST
value|0x0e0a
end_define

begin_comment
comment|/*  8 bit Descriptor Poll Timer Test Reg */
end_comment

begin_comment
comment|/* Time Stamp Timer Registers (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GMAC_TI_ST_VAL
value|0x0e14
end_define

begin_comment
comment|/* 32 bit Time Stamp Timer Curr Val */
end_comment

begin_define
define|#
directive|define
name|GMAC_TI_ST_CTRL
value|0x0e18
end_define

begin_comment
comment|/*  8 bit Time Stamp Timer Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|GMAC_TI_ST_TST
value|0x0e1a
end_define

begin_comment
comment|/*  8 bit Time Stamp Timer Test Reg */
end_comment

begin_comment
comment|/* Polling Unit Registers (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|POLL_CTRL
value|0x0e20
end_define

begin_comment
comment|/* 32 bit Polling Unit Control Reg */
end_comment

begin_define
define|#
directive|define
name|POLL_LAST_IDX
value|0x0e24
end_define

begin_comment
comment|/* 16 bit Polling Unit List Last Index */
end_comment

begin_define
define|#
directive|define
name|POLL_LIST_ADDR_LO
value|0x0e28
end_define

begin_comment
comment|/* 32 bit Poll. List Start Addr (low) */
end_comment

begin_define
define|#
directive|define
name|POLL_LIST_ADDR_HI
value|0x0e2c
end_define

begin_comment
comment|/* 32 bit Poll. List Start Addr (high) */
end_comment

begin_comment
comment|/* ASF Subsystem Registers (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_SMB_CONFIG
value|0x0e40
end_define

begin_comment
comment|/* 32 bit ASF SMBus Config Register */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_SMB_CSD_REG
value|0x0e44
end_define

begin_comment
comment|/* 32 bit ASF SMB Control/Status/Data */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_ASF_IRQ_V_BASE
value|0x0e60
end_define

begin_comment
comment|/* 32 bit ASF IRQ Vector Base */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_ASF_STAT_CMD
value|0x0e68
end_define

begin_comment
comment|/* 32 bit ASF Status and Command Reg */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_ASF_HOST_COM
value|0x0e6c
end_define

begin_comment
comment|/* 32 bit ASF Host Communication Reg */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_DATA_REG_1
value|0x0e70
end_define

begin_comment
comment|/* 32 bit ASF/Host Data Register 1 */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_DATA_REG_2
value|0x0e74
end_define

begin_comment
comment|/* 32 bit ASF/Host Data Register 2 */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_DATA_REG_3
value|0x0e78
end_define

begin_comment
comment|/* 32 bit ASF/Host Data Register 3 */
end_comment

begin_define
define|#
directive|define
name|B28_Y2_DATA_REG_4
value|0x0e7c
end_define

begin_comment
comment|/* 32 bit ASF/Host Data Register 4 */
end_comment

begin_comment
comment|/*  *	Bank 29  */
end_comment

begin_comment
comment|/* Status BMU Registers (Yukon-2 only)*/
end_comment

begin_define
define|#
directive|define
name|STAT_CTRL
value|0x0e80
end_define

begin_comment
comment|/* 32 bit Status BMU Control Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_LAST_IDX
value|0x0e84
end_define

begin_comment
comment|/* 16 bit Status BMU Last Index */
end_comment

begin_define
define|#
directive|define
name|STAT_LIST_ADDR_LO
value|0x0e88
end_define

begin_comment
comment|/* 32 bit Status List Start Addr (low) */
end_comment

begin_define
define|#
directive|define
name|STAT_LIST_ADDR_HI
value|0x0e8c
end_define

begin_comment
comment|/* 32 bit Status List Start Addr (high) */
end_comment

begin_define
define|#
directive|define
name|STAT_TXA1_RIDX
value|0x0e90
end_define

begin_comment
comment|/* 16 bit Status TxA1 Report Index Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TXS1_RIDX
value|0x0e92
end_define

begin_comment
comment|/* 16 bit Status TxS1 Report Index Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TXA2_RIDX
value|0x0e94
end_define

begin_comment
comment|/* 16 bit Status TxA2 Report Index Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TXS2_RIDX
value|0x0e96
end_define

begin_comment
comment|/* 16 bit Status TxS2 Report Index Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TX_IDX_TH
value|0x0e98
end_define

begin_comment
comment|/* 16 bit Status Tx Index Threshold Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_PUT_IDX
value|0x0e9c
end_define

begin_comment
comment|/* 16 bit Status Put Index Reg */
end_comment

begin_comment
comment|/* FIFO Control/Status Registers (Yukon-2 only)*/
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_WP
value|0x0ea0
end_define

begin_comment
comment|/*  8 bit Status FIFO Write Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_RP
value|0x0ea4
end_define

begin_comment
comment|/*  8 bit Status FIFO Read Pointer Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_RSP
value|0x0ea6
end_define

begin_comment
comment|/*  8 bit Status FIFO Read Shadow Ptr */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_LEVEL
value|0x0ea8
end_define

begin_comment
comment|/*  8 bit Status FIFO Level Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_SHLVL
value|0x0eaa
end_define

begin_comment
comment|/*  8 bit Status FIFO Shadow Level Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_WM
value|0x0eac
end_define

begin_comment
comment|/*  8 bit Status FIFO Watermark Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_FIFO_ISR_WM
value|0x0ead
end_define

begin_comment
comment|/*  8 bit Status FIFO ISR Watermark Reg */
end_comment

begin_comment
comment|/* Level and ISR Timer Registers (Yukon-2 only)*/
end_comment

begin_define
define|#
directive|define
name|STAT_LEV_TIMER_INI
value|0x0eb0
end_define

begin_comment
comment|/* 32 bit Level Timer Init. Value Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_LEV_TIMER_CNT
value|0x0eb4
end_define

begin_comment
comment|/* 32 bit Level Timer Counter Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_LEV_TIMER_CTRL
value|0x0eb8
end_define

begin_comment
comment|/*  8 bit Level Timer Control Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_LEV_TIMER_TEST
value|0x0eb9
end_define

begin_comment
comment|/*  8 bit Level Timer Test Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TX_TIMER_INI
value|0x0ec0
end_define

begin_comment
comment|/* 32 bit Tx Timer Init. Value Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TX_TIMER_CNT
value|0x0ec4
end_define

begin_comment
comment|/* 32 bit Tx Timer Counter Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TX_TIMER_CTRL
value|0x0ec8
end_define

begin_comment
comment|/*  8 bit Tx Timer Control Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_TX_TIMER_TEST
value|0x0ec9
end_define

begin_comment
comment|/*  8 bit Tx Timer Test Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_ISR_TIMER_INI
value|0x0ed0
end_define

begin_comment
comment|/* 32 bit ISR Timer Init. Value Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_ISR_TIMER_CNT
value|0x0ed4
end_define

begin_comment
comment|/* 32 bit ISR Timer Counter Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_ISR_TIMER_CTRL
value|0x0ed8
end_define

begin_comment
comment|/*  8 bit ISR Timer Control Reg */
end_comment

begin_define
define|#
directive|define
name|STAT_ISR_TIMER_TEST
value|0x0ed9
end_define

begin_comment
comment|/*  8 bit ISR Timer Test Reg */
end_comment

begin_define
define|#
directive|define
name|ST_LAST_IDX_MASK
value|0x007f
end_define

begin_comment
comment|/* Last Index Mask */
end_comment

begin_define
define|#
directive|define
name|ST_TXRP_IDX_MASK
value|0x0fff
end_define

begin_comment
comment|/* Tx Report Index Mask */
end_comment

begin_define
define|#
directive|define
name|ST_TXTH_IDX_MASK
value|0x0fff
end_define

begin_comment
comment|/* Tx Threshold Index Mask */
end_comment

begin_define
define|#
directive|define
name|ST_WM_IDX_MASK
value|0x3f
end_define

begin_comment
comment|/* FIFO Watermark Index Mask */
end_comment

begin_comment
comment|/*  *	Bank 30  */
end_comment

begin_comment
comment|/* GMAC and GPHY Control Registers (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GMAC_CTRL
value|0x0f00
end_define

begin_comment
comment|/* 32 bit GMAC Control Reg */
end_comment

begin_define
define|#
directive|define
name|GPHY_CTRL
value|0x0f04
end_define

begin_comment
comment|/* 32 bit GPHY Control Reg */
end_comment

begin_define
define|#
directive|define
name|GMAC_IRQ_SRC
value|0x0f08
end_define

begin_comment
comment|/*  8 bit GMAC Interrupt Source Reg */
end_comment

begin_define
define|#
directive|define
name|GMAC_IRQ_MSK
value|0x0f0c
end_define

begin_comment
comment|/*  8 bit GMAC Interrupt Mask Reg */
end_comment

begin_define
define|#
directive|define
name|GMAC_LINK_CTRL
value|0x0f10
end_define

begin_comment
comment|/* 16 bit Link Control Reg */
end_comment

begin_comment
comment|/* Wake-up Frame Pattern Match Control Registers (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|WOL_REG_OFFS
value|0x20
end_define

begin_comment
comment|/* HW-Bug: Address is + 0x20 against spec. */
end_comment

begin_define
define|#
directive|define
name|WOL_CTRL_STAT
value|0x0f20
end_define

begin_comment
comment|/* 16 bit WOL Control/Status Reg */
end_comment

begin_define
define|#
directive|define
name|WOL_MATCH_CTL
value|0x0f22
end_define

begin_comment
comment|/*  8 bit WOL Match Control Reg */
end_comment

begin_define
define|#
directive|define
name|WOL_MATCH_RES
value|0x0f23
end_define

begin_comment
comment|/*  8 bit WOL Match Result Reg */
end_comment

begin_define
define|#
directive|define
name|WOL_MAC_ADDR_LO
value|0x0f24
end_define

begin_comment
comment|/* 32 bit WOL MAC Address Low */
end_comment

begin_define
define|#
directive|define
name|WOL_MAC_ADDR_HI
value|0x0f28
end_define

begin_comment
comment|/* 16 bit WOL MAC Address High */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_PME
value|0x0f2a
end_define

begin_comment
comment|/*  8 bit WOL PME Match Enable (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_ASFM
value|0x0f2b
end_define

begin_comment
comment|/*  8 bit WOL ASF Match Enable (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_RPTR
value|0x0f2c
end_define

begin_comment
comment|/*  8 bit WOL Pattern Read Pointer */
end_comment

begin_comment
comment|/* WOL Pattern Length Registers (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_LEN_LO
value|0x0f30
end_define

begin_comment
comment|/* 32 bit WOL Pattern Length 3..0 */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_LEN_HI
value|0x0f34
end_define

begin_comment
comment|/* 24 bit WOL Pattern Length 6..4 */
end_comment

begin_comment
comment|/* WOL Pattern Counter Registers (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_CNT_0
value|0x0f38
end_define

begin_comment
comment|/* 32 bit WOL Pattern Counter 3..0 */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_CNT_4
value|0x0f3c
end_define

begin_comment
comment|/* 24 bit WOL Pattern Counter 6..4 */
end_comment

begin_comment
comment|/*  *	Bank 32	- 33  */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_RAM_1
value|0x1000
end_define

begin_comment
comment|/*  WOL Pattern RAM Link 1 */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_RAM_2
value|0x1400
end_define

begin_comment
comment|/*  WOL Pattern RAM Link 2 */
end_comment

begin_comment
comment|/* offset to configuration space on Yukon-2 */
end_comment

begin_define
define|#
directive|define
name|Y2_CFG_SPC
value|0x1c00
end_define

begin_define
define|#
directive|define
name|BASE_GMAC_1
value|0x2800
end_define

begin_comment
comment|/* GMAC 1 registers */
end_comment

begin_define
define|#
directive|define
name|BASE_GMAC_2
value|0x3800
end_define

begin_comment
comment|/* GMAC 2 registers */
end_comment

begin_comment
comment|/*  *	Control Register Bit Definitions:  */
end_comment

begin_comment
comment|/*	B0_CTST	24 bit	Control/Status register */
end_comment

begin_define
define|#
directive|define
name|Y2_VMAIN_AVAIL
value|BIT_17
end_define

begin_comment
comment|/* VMAIN available (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_VAUX_AVAIL
value|BIT_16
end_define

begin_comment
comment|/* VAUX available (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_HW_WOL_ON
value|BIT_15
end_define

begin_comment
comment|/* HW WOL On  (Yukon-EC Ultra A1 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_HW_WOL_OFF
value|BIT_14
end_define

begin_comment
comment|/* HW WOL Off (Yukon-EC Ultra A1 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_ENABLE
value|BIT_13
end_define

begin_comment
comment|/* ASF Unit Enable (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_DISABLE
value|BIT_12
end_define

begin_comment
comment|/* ASF Unit Disable (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_RUN_ENA
value|BIT_11
end_define

begin_comment
comment|/* CLK_RUN Enable  (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_RUN_DIS
value|BIT_10
end_define

begin_comment
comment|/* CLK_RUN Disable (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_LED_STAT_ON
value|BIT_9
end_define

begin_comment
comment|/* Status LED On  (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_LED_STAT_OFF
value|BIT_8
end_define

begin_comment
comment|/* Status LED Off (YUKON-2 only) */
end_comment

begin_define
define|#
directive|define
name|CS_ST_SW_IRQ
value|BIT_7
end_define

begin_comment
comment|/* Set IRQ SW Request */
end_comment

begin_define
define|#
directive|define
name|CS_CL_SW_IRQ
value|BIT_6
end_define

begin_comment
comment|/* Clear IRQ SW Request */
end_comment

begin_define
define|#
directive|define
name|CS_STOP_DONE
value|BIT_5
end_define

begin_comment
comment|/* Stop Master is finished */
end_comment

begin_define
define|#
directive|define
name|CS_STOP_MAST
value|BIT_4
end_define

begin_comment
comment|/* Command Bit to stop the master */
end_comment

begin_define
define|#
directive|define
name|CS_MRST_CLR
value|BIT_3
end_define

begin_comment
comment|/* Clear Master Reset */
end_comment

begin_define
define|#
directive|define
name|CS_MRST_SET
value|BIT_2
end_define

begin_comment
comment|/* Set   Master Reset */
end_comment

begin_define
define|#
directive|define
name|CS_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear Software Reset	*/
end_comment

begin_define
define|#
directive|define
name|CS_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   Software Reset	*/
end_comment

begin_define
define|#
directive|define
name|LED_STAT_ON
value|BIT_1
end_define

begin_comment
comment|/* Status LED On	*/
end_comment

begin_define
define|#
directive|define
name|LED_STAT_OFF
value|BIT_0
end_define

begin_comment
comment|/* Status LED Off	*/
end_comment

begin_comment
comment|/* B0_POWER_CTRL	 8 Bit	Power Control reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|PC_VAUX_ENA
value|BIT_7
end_define

begin_comment
comment|/* Switch VAUX Enable  */
end_comment

begin_define
define|#
directive|define
name|PC_VAUX_DIS
value|BIT_6
end_define

begin_comment
comment|/* Switch VAUX Disable */
end_comment

begin_define
define|#
directive|define
name|PC_VCC_ENA
value|BIT_5
end_define

begin_comment
comment|/* Switch VCC Enable  */
end_comment

begin_define
define|#
directive|define
name|PC_VCC_DIS
value|BIT_4
end_define

begin_comment
comment|/* Switch VCC Disable */
end_comment

begin_define
define|#
directive|define
name|PC_VAUX_ON
value|BIT_3
end_define

begin_comment
comment|/* Switch VAUX On  */
end_comment

begin_define
define|#
directive|define
name|PC_VAUX_OFF
value|BIT_2
end_define

begin_comment
comment|/* Switch VAUX Off */
end_comment

begin_define
define|#
directive|define
name|PC_VCC_ON
value|BIT_1
end_define

begin_comment
comment|/* Switch VCC On  */
end_comment

begin_define
define|#
directive|define
name|PC_VCC_OFF
value|BIT_0
end_define

begin_comment
comment|/* Switch VCC Off */
end_comment

begin_comment
comment|/*	B0_ISRC		32 bit	Interrupt Source Register */
end_comment

begin_comment
comment|/*	B0_IMSK		32 bit	Interrupt Mask Register */
end_comment

begin_comment
comment|/*	B0_SP_ISRC	32 bit	Special Interrupt Source Reg */
end_comment

begin_comment
comment|/*	B2_IRQM_MSK	32 bit	IRQ Moderation Mask */
end_comment

begin_comment
comment|/*	B0_Y2_SP_ISRC2	32 bit	Special Interrupt Source Reg 2 */
end_comment

begin_comment
comment|/*	B0_Y2_SP_ISRC3	32 bit	Special Interrupt Source Reg 3 */
end_comment

begin_comment
comment|/*	B0_Y2_SP_EISR	32 bit	Enter ISR Reg */
end_comment

begin_comment
comment|/*	B0_Y2_SP_LISR	32 bit	Leave ISR Reg */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PORT_MASK
parameter_list|(
name|Port
parameter_list|,
name|Mask
parameter_list|)
value|((Mask)<< (Port*8))
end_define

begin_define
define|#
directive|define
name|Y2_IS_HW_ERR
value|BIT_31
end_define

begin_comment
comment|/* Interrupt HW Error */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_STAT_BMU
value|BIT_30
end_define

begin_comment
comment|/* Status BMU Interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_ASF
value|BIT_29
end_define

begin_comment
comment|/* ASF subsystem Interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_POLL_CHK
value|BIT_27
end_define

begin_comment
comment|/* Check IRQ from polling unit */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TWSI_RDY
value|BIT_26
end_define

begin_comment
comment|/* IRQ on end of TWSI Tx */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_SW
value|BIT_25
end_define

begin_comment
comment|/* SW forced IRQ	*/
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TIMINT
value|BIT_24
end_define

begin_comment
comment|/* IRQ from Timer	*/
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_PHY2
value|BIT_12
end_define

begin_comment
comment|/* Interrupt from PHY 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_MAC2
value|BIT_11
end_define

begin_comment
comment|/* Interrupt from MAC 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_RX2
value|BIT_10
end_define

begin_comment
comment|/* Descriptor error Rx 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_TXS2
value|BIT_9
end_define

begin_comment
comment|/* Descriptor error TXS 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_TXA2
value|BIT_8
end_define

begin_comment
comment|/* Descriptor error TXA 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_PHY1
value|BIT_4
end_define

begin_comment
comment|/* Interrupt from PHY 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_MAC1
value|BIT_3
end_define

begin_comment
comment|/* Interrupt from MAC 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_RX1
value|BIT_2
end_define

begin_comment
comment|/* Descriptor error Rx 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_TXS1
value|BIT_1
end_define

begin_comment
comment|/* Descriptor error TXS 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_CHK_TXA1
value|BIT_0
end_define

begin_comment
comment|/* Descriptor error TXA 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_L1_MASK
value|0x0000001f
end_define

begin_comment
comment|/* IRQ Mask for port 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_L2_MASK
value|0x00001f00
end_define

begin_comment
comment|/* IRQ Mask for port 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_ALL_MSK
value|0xef001f1f
end_define

begin_comment
comment|/* All Interrupt bits */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PORT_A
define|\
value|(Y2_IS_IRQ_PHY1 | Y2_IS_IRQ_MAC1 | Y2_IS_CHK_TXA1 | Y2_IS_CHK_RX1)
end_define

begin_define
define|#
directive|define
name|Y2_IS_PORT_B
define|\
value|(Y2_IS_IRQ_PHY2 | Y2_IS_IRQ_MAC2 | Y2_IS_CHK_TXA2 | Y2_IS_CHK_RX2)
end_define

begin_comment
comment|/*	B0_HWE_ISRC	32 bit	HW Error Interrupt Src Reg */
end_comment

begin_comment
comment|/*	B0_HWE_IMSK	32 bit	HW Error Interrupt Mask Reg */
end_comment

begin_comment
comment|/*	B2_IRQM_HWE_MSK	32 bit	IRQ Moderation HW Error Mask */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TIST_OV
value|BIT_29
end_define

begin_comment
comment|/* Time Stamp Timer overflow interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_SENSOR
value|BIT_28
end_define

begin_comment
comment|/* Sensor interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_MST_ERR
value|BIT_27
end_define

begin_comment
comment|/* Master error interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_IRQ_STAT
value|BIT_26
end_define

begin_comment
comment|/* Status exception interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PCI_EXP
value|BIT_25
end_define

begin_comment
comment|/* PCI-Express interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PCI_NEXP
value|BIT_24
end_define

begin_comment
comment|/* PCI-Express error similar to PCI error */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_RD2
value|BIT_13
end_define

begin_comment
comment|/* Read RAM parity error interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_WR2
value|BIT_12
end_define

begin_comment
comment|/* Write RAM parity error interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_MAC2
value|BIT_11
end_define

begin_comment
comment|/* MAC hardware fault interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_RX2
value|BIT_10
end_define

begin_comment
comment|/* Parity Error Rx Queue 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TCP_TXS2
value|BIT_9
end_define

begin_comment
comment|/* TCP length mismatch sync Tx queue IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TCP_TXA2
value|BIT_8
end_define

begin_comment
comment|/* TCP length mismatch async Tx queue IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_RD1
value|BIT_5
end_define

begin_comment
comment|/* Read RAM parity error interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_WR1
value|BIT_4
end_define

begin_comment
comment|/* Write RAM parity error interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_MAC1
value|BIT_3
end_define

begin_comment
comment|/* MAC hardware fault interrupt */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_PAR_RX1
value|BIT_2
end_define

begin_comment
comment|/* Parity Error Rx Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TCP_TXS1
value|BIT_1
end_define

begin_comment
comment|/* TCP length mismatch sync Tx queue IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_IS_TCP_TXA1
value|BIT_0
end_define

begin_comment
comment|/* TCP length mismatch async Tx queue IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_HWE_L1_MASK
value|(Y2_IS_PAR_RD1 | Y2_IS_PAR_WR1 | Y2_IS_PAR_MAC1 |\ 			 Y2_IS_PAR_RX1 | Y2_IS_TCP_TXS1| Y2_IS_TCP_TXA1)
end_define

begin_define
define|#
directive|define
name|Y2_HWE_L2_MASK
value|(Y2_IS_PAR_RD2 | Y2_IS_PAR_WR2 | Y2_IS_PAR_MAC2 |\ 			 Y2_IS_PAR_RX2 | Y2_IS_TCP_TXS2| Y2_IS_TCP_TXA2)
end_define

begin_define
define|#
directive|define
name|Y2_HWE_ALL_MSK
value|(Y2_IS_TIST_OV |
comment|/* Y2_IS_SENSOR | */
value|Y2_IS_MST_ERR |\ 			 Y2_IS_IRQ_STAT | Y2_IS_PCI_EXP | Y2_IS_PCI_NEXP |\ 			 Y2_HWE_L1_MASK | Y2_HWE_L2_MASK)
end_define

begin_comment
comment|/*	B2_MAC_CFG	 8 bit	MAC Configuration / Chip Revision */
end_comment

begin_define
define|#
directive|define
name|CFG_CHIP_R_MSK
value|(0x0f<<4)
end_define

begin_comment
comment|/* Bit 7.. 4: Chip Revision */
end_comment

begin_define
define|#
directive|define
name|CFG_DIS_M2_CLK
value|BIT_1
end_define

begin_comment
comment|/* Disable Clock for 2nd MAC */
end_comment

begin_define
define|#
directive|define
name|CFG_SNG_MAC
value|BIT_0
end_define

begin_comment
comment|/* MAC Config: 0 = 2 MACs; 1 = 1 MAC */
end_comment

begin_comment
comment|/*	B2_CHIP_ID	 8 bit	Chip Identification Number */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_GENESIS
value|0x0a
end_define

begin_comment
comment|/* Chip ID for GENESIS */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON
value|0xb0
end_define

begin_comment
comment|/* Chip ID for YUKON */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_LITE
value|0xb1
end_define

begin_comment
comment|/* Chip ID for YUKON-Lite (Rev. A1-A3) */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_LP
value|0xb2
end_define

begin_comment
comment|/* Chip ID for YUKON-LP */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_XL
value|0xb3
end_define

begin_comment
comment|/* Chip ID for YUKON-2 XL */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_EC_U
value|0xb4
end_define

begin_comment
comment|/* Chip ID for YUKON-2 EC Ultra */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_EC
value|0xb6
end_define

begin_comment
comment|/* Chip ID for YUKON-2 EC */
end_comment

begin_define
define|#
directive|define
name|CHIP_ID_YUKON_FE
value|0xb7
end_define

begin_comment
comment|/* Chip ID for YUKON-2 FE */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_XL_A0
value|0
end_define

begin_comment
comment|/* Chip Rev. for Yukon-2 A0 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_XL_A1
value|1
end_define

begin_comment
comment|/* Chip Rev. for Yukon-2 A1 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_XL_A2
value|2
end_define

begin_comment
comment|/* Chip Rev. for Yukon-2 A2 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_XL_A3
value|3
end_define

begin_comment
comment|/* Chip Rev. for Yukon-2 A3 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_EC_A1
value|0
end_define

begin_comment
comment|/* Chip Rev. for Yukon-EC A1/A0 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_EC_A2
value|1
end_define

begin_comment
comment|/* Chip Rev. for Yukon-EC A2 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_EC_A3
value|2
end_define

begin_comment
comment|/* Chip Rev. for Yukon-EC A3 */
end_comment

begin_define
define|#
directive|define
name|CHIP_REV_YU_EC_U_A0
value|0
end_define

begin_define
define|#
directive|define
name|CHIP_REV_YU_EC_U_A1
value|1
end_define

begin_comment
comment|/*	B2_Y2_CLK_GATE	 8 bit	Clock Gating (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|Y2_STATUS_LNK2_INAC
value|BIT_7
end_define

begin_comment
comment|/* Status Link 2 inactiv (0 = activ) */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_GAT_LNK2_DIS
value|BIT_6
end_define

begin_comment
comment|/* Disable clock gating Link 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_COR_CLK_LNK2_DIS
value|BIT_5
end_define

begin_comment
comment|/* Disable Core clock Link 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_PCI_CLK_LNK2_DIS
value|BIT_4
end_define

begin_comment
comment|/* Disable PCI clock Link 2 */
end_comment

begin_define
define|#
directive|define
name|Y2_STATUS_LNK1_INAC
value|BIT_3
end_define

begin_comment
comment|/* Status Link 1 inactiv (0 = activ) */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_GAT_LNK1_DIS
value|BIT_2
end_define

begin_comment
comment|/* Disable clock gating Link 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_COR_CLK_LNK1_DIS
value|BIT_1
end_define

begin_comment
comment|/* Disable Core clock Link 1 */
end_comment

begin_define
define|#
directive|define
name|Y2_PCI_CLK_LNK1_DIS
value|BIT_0
end_define

begin_comment
comment|/* Disable PCI clock Link 1 */
end_comment

begin_comment
comment|/*	B2_Y2_HW_RES	8 bit	HW Resources (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|CFG_LED_MODE_MSK
value|(0x07<<2)
end_define

begin_comment
comment|/* Bit  4.. 2:	LED Mode Mask */
end_comment

begin_define
define|#
directive|define
name|CFG_LINK_2_AVAIL
value|BIT_1
end_define

begin_comment
comment|/* Link 2 available */
end_comment

begin_define
define|#
directive|define
name|CFG_LINK_1_AVAIL
value|BIT_0
end_define

begin_comment
comment|/* Link 1 available */
end_comment

begin_define
define|#
directive|define
name|CFG_LED_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& CFG_LED_MODE_MSK)>> 2)
end_define

begin_define
define|#
directive|define
name|CFG_DUAL_MAC_MSK
value|(CFG_LINK_2_AVAIL | CFG_LINK_1_AVAIL)
end_define

begin_comment
comment|/*	B2_E_3	 	8 bit	lower 4 bits used for HW self test result */
end_comment

begin_define
define|#
directive|define
name|B2_E3_RES_MASK
value|0x0f
end_define

begin_comment
comment|/*	B2_Y2_CLK_CTRL	32 bit	Core Clock Frequency Control Register (Yukon-2/EC) */
end_comment

begin_comment
comment|/* Yukon-EC/FE */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_DIV_VAL_MSK
value|(0xff<<16)
end_define

begin_comment
comment|/* Bit 23..16: Clock Divisor Value */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_DIV_VAL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT16(x)& Y2_CLK_DIV_VAL_MSK)
end_define

begin_comment
comment|/* Yukon-2 */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_DIV_VAL2_MSK
value|(0x07<<21)
end_define

begin_comment
comment|/* Bit 23..21: Clock Divisor Value */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_SELECT2_MSK
value|(0x1f<<16)
end_define

begin_comment
comment|/* Bit 20..16: Clock Select */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_DIV_VAL_2
parameter_list|(
name|x
parameter_list|)
value|(SHIFT21(x)& Y2_CLK_DIV_VAL2_MSK)
end_define

begin_define
define|#
directive|define
name|Y2_CLK_SEL_VAL_2
parameter_list|(
name|x
parameter_list|)
value|(SHIFT16(x)& Y2_CLK_SELECT2_MSK)
end_define

begin_define
define|#
directive|define
name|Y2_CLK_DIV_ENA
value|BIT_1
end_define

begin_comment
comment|/* Enable  Core Clock Division */
end_comment

begin_define
define|#
directive|define
name|Y2_CLK_DIV_DIS
value|BIT_0
end_define

begin_comment
comment|/* Disable Core Clock Division */
end_comment

begin_comment
comment|/*	B2_TI_CTRL	 8 bit	Timer control */
end_comment

begin_comment
comment|/*	B2_IRQM_CTRL	 8 bit	IRQ Moderation Timer Control */
end_comment

begin_define
define|#
directive|define
name|TIM_START
value|BIT_2
end_define

begin_comment
comment|/* Start Timer */
end_comment

begin_define
define|#
directive|define
name|TIM_STOP
value|BIT_1
end_define

begin_comment
comment|/* Stop  Timer */
end_comment

begin_define
define|#
directive|define
name|TIM_CLR_IRQ
value|BIT_0
end_define

begin_comment
comment|/* Clear Timer IRQ (!IRQM) */
end_comment

begin_comment
comment|/*	B2_TI_TEST	 8 Bit	Timer Test */
end_comment

begin_comment
comment|/*	B2_IRQM_TEST	 8 bit	IRQ Moderation Timer Test */
end_comment

begin_comment
comment|/*	B28_DPT_TST	 8 bit	Descriptor Poll Timer Test Reg */
end_comment

begin_define
define|#
directive|define
name|TIM_T_ON
value|BIT_2
end_define

begin_comment
comment|/* Test mode on */
end_comment

begin_define
define|#
directive|define
name|TIM_T_OFF
value|BIT_1
end_define

begin_comment
comment|/* Test mode off */
end_comment

begin_define
define|#
directive|define
name|TIM_T_STEP
value|BIT_0
end_define

begin_comment
comment|/* Test step */
end_comment

begin_comment
comment|/*	B28_DPT_INI	32 bit	Descriptor Poll Timer Init Val */
end_comment

begin_comment
comment|/*	B28_DPT_VAL	32 bit	Descriptor Poll Timer Curr Val */
end_comment

begin_define
define|#
directive|define
name|DPT_MSK
value|0x00ffffff
end_define

begin_comment
comment|/* Bit 23.. 0:	Desc Poll Timer Bits */
end_comment

begin_comment
comment|/*	B28_DPT_CTRL	 8 bit	Descriptor Poll Timer Ctrl Reg */
end_comment

begin_define
define|#
directive|define
name|DPT_START
value|BIT_1
end_define

begin_comment
comment|/* Start Descriptor Poll Timer */
end_comment

begin_define
define|#
directive|define
name|DPT_STOP
value|BIT_0
end_define

begin_comment
comment|/* Stop  Descriptor Poll Timer */
end_comment

begin_comment
comment|/*	B2_TST_CTRL1	 8 bit	Test Control Register 1 */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_DPERR_MR
value|BIT_7
end_define

begin_comment
comment|/* force DATAPERR on MST RD */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_DPERR_MW
value|BIT_6
end_define

begin_comment
comment|/* force DATAPERR on MST WR */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_DPERR_TR
value|BIT_5
end_define

begin_comment
comment|/* force DATAPERR on TRG RD */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_DPERR_TW
value|BIT_4
end_define

begin_comment
comment|/* force DATAPERR on TRG WR */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_APERR_M
value|BIT_3
end_define

begin_comment
comment|/* force ADDRPERR on MST */
end_comment

begin_define
define|#
directive|define
name|TST_FRC_APERR_T
value|BIT_2
end_define

begin_comment
comment|/* force ADDRPERR on TRG */
end_comment

begin_define
define|#
directive|define
name|TST_CFG_WRITE_ON
value|BIT_1
end_define

begin_comment
comment|/* Enable  Config Reg WR */
end_comment

begin_define
define|#
directive|define
name|TST_CFG_WRITE_OFF
value|BIT_0
end_define

begin_comment
comment|/* Disable Config Reg WR */
end_comment

begin_comment
comment|/*	B2_I2C_CTRL	32 bit	I2C HW Control Register */
end_comment

begin_define
define|#
directive|define
name|I2C_FLAG
value|BIT_31
end_define

begin_comment
comment|/* Start read/write if WR */
end_comment

begin_define
define|#
directive|define
name|I2C_ADDR
value|(0x7fff<<16)
end_define

begin_comment
comment|/* Bit 30..16:	Addr to be RD/WR */
end_comment

begin_define
define|#
directive|define
name|I2C_DEV_SEL
value|(0x7f<<9)
end_define

begin_comment
comment|/* Bit 15.. 9:	I2C Device Select */
end_comment

begin_define
define|#
directive|define
name|I2C_BURST_LEN
value|BIT_4
end_define

begin_comment
comment|/* Burst Len, 1/4 bytes */
end_comment

begin_define
define|#
directive|define
name|I2C_DEV_SIZE
value|(7<<1)
end_define

begin_comment
comment|/* Bit	3.. 1:	I2C Device Size	*/
end_comment

begin_define
define|#
directive|define
name|I2C_025K_DEV
value|(0<<1)
end_define

begin_comment
comment|/*		0: 256 Bytes or smal. */
end_comment

begin_define
define|#
directive|define
name|I2C_05K_DEV
value|(1<<1)
end_define

begin_comment
comment|/* 		1: 512	Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_1K_DEV
value|(2<<1)
end_define

begin_comment
comment|/*		2: 1024 Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_2K_DEV
value|(3<<1)
end_define

begin_comment
comment|/*		3: 2048	Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_4K_DEV
value|(4<<1)
end_define

begin_comment
comment|/*		4: 4096 Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_8K_DEV
value|(5<<1)
end_define

begin_comment
comment|/*		5: 8192 Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_16K_DEV
value|(6<<1)
end_define

begin_comment
comment|/*		6: 16384 Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_32K_DEV
value|(7<<1)
end_define

begin_comment
comment|/*		7: 32768 Bytes	*/
end_comment

begin_define
define|#
directive|define
name|I2C_STOP
value|BIT_0
end_define

begin_comment
comment|/* Interrupt I2C transfer */
end_comment

begin_comment
comment|/*	B2_I2C_IRQ	32 bit	I2C HW IRQ Register */
end_comment

begin_define
define|#
directive|define
name|I2C_CLR_IRQ
value|BIT_0
end_define

begin_comment
comment|/* Clear I2C IRQ */
end_comment

begin_comment
comment|/*	B2_I2C_SW	32 bit (8 bit access)	I2C HW SW Port Register */
end_comment

begin_define
define|#
directive|define
name|I2C_DATA_DIR
value|BIT_2
end_define

begin_comment
comment|/* direction of I2C_DATA */
end_comment

begin_define
define|#
directive|define
name|I2C_DATA
value|BIT_1
end_define

begin_comment
comment|/* I2C Data Port	*/
end_comment

begin_define
define|#
directive|define
name|I2C_CLK
value|BIT_0
end_define

begin_comment
comment|/* I2C Clock Port	*/
end_comment

begin_comment
comment|/* I2C Address */
end_comment

begin_define
define|#
directive|define
name|I2C_SENS_ADDR
value|LM80_ADDR
end_define

begin_comment
comment|/* I2C Sensor Address (Volt and Temp) */
end_comment

begin_comment
comment|/*	B2_BSC_CTRL	 8 bit	Blink Source Counter Control */
end_comment

begin_define
define|#
directive|define
name|BSC_START
value|BIT_1
end_define

begin_comment
comment|/* Start Blink Source Counter */
end_comment

begin_define
define|#
directive|define
name|BSC_STOP
value|BIT_0
end_define

begin_comment
comment|/* Stop  Blink Source Counter */
end_comment

begin_comment
comment|/*	B2_BSC_STAT	 8 bit	Blink Source Counter Status */
end_comment

begin_define
define|#
directive|define
name|BSC_SRC
value|BIT_0
end_define

begin_comment
comment|/* Blink Source, 0=Off / 1=On */
end_comment

begin_comment
comment|/*	B2_BSC_TST	16 bit	Blink Source Counter Test Reg */
end_comment

begin_define
define|#
directive|define
name|BSC_T_ON
value|BIT_2
end_define

begin_comment
comment|/* Test mode on */
end_comment

begin_define
define|#
directive|define
name|BSC_T_OFF
value|BIT_1
end_define

begin_comment
comment|/* Test mode off */
end_comment

begin_define
define|#
directive|define
name|BSC_T_STEP
value|BIT_0
end_define

begin_comment
comment|/* Test step */
end_comment

begin_comment
comment|/*	Y2_PEX_PHY_ADDR/DATA	PEX PHY address and data reg  (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|PEX_RD_ACCESS
value|BIT_31
end_define

begin_comment
comment|/* Access Mode Read = 1, Write = 0 */
end_comment

begin_define
define|#
directive|define
name|PEX_DB_ACCESS
value|BIT_30
end_define

begin_comment
comment|/* Access to debug register */
end_comment

begin_comment
comment|/*	B3_RAM_ADDR		32 bit	RAM Address, to read or write */
end_comment

begin_define
define|#
directive|define
name|RAM_ADR_RAN
value|0x0007ffff
end_define

begin_comment
comment|/* Bit 18.. 0:	RAM Address Range */
end_comment

begin_comment
comment|/* RAM Interface Registers */
end_comment

begin_comment
comment|/*	B3_RI_CTRL		16 bit	RAM Interface Control Register */
end_comment

begin_define
define|#
directive|define
name|RI_CLR_RD_PERR
value|BIT_9
end_define

begin_comment
comment|/* Clear IRQ RAM Read  Parity Err */
end_comment

begin_define
define|#
directive|define
name|RI_CLR_WR_PERR
value|BIT_8
end_define

begin_comment
comment|/* Clear IRQ RAM Write Parity Err */
end_comment

begin_define
define|#
directive|define
name|RI_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear RAM Interface Reset */
end_comment

begin_define
define|#
directive|define
name|RI_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   RAM Interface Reset */
end_comment

begin_define
define|#
directive|define
name|MSK_RI_TO_53
value|36
end_define

begin_comment
comment|/* RAM interface timeout */
end_comment

begin_comment
comment|/* Transmit Arbiter Registers MAC 1 and 2, use MR_ADDR() to access */
end_comment

begin_comment
comment|/*	TXA_ITI_INI	32 bit	Tx Arb Interval Timer Init Val */
end_comment

begin_comment
comment|/*	TXA_ITI_VAL	32 bit	Tx Arb Interval Timer Value */
end_comment

begin_comment
comment|/*	TXA_LIM_INI	32 bit	Tx Arb Limit Counter Init Val */
end_comment

begin_comment
comment|/*	TXA_LIM_VAL	32 bit	Tx Arb Limit Counter Value */
end_comment

begin_define
define|#
directive|define
name|TXA_MAX_VAL
value|0x00ffffff
end_define

begin_comment
comment|/* Bit 23.. 0:	Max TXA Timer/Cnt Val */
end_comment

begin_comment
comment|/*	TXA_CTRL	 8 bit	Tx Arbiter Control Register */
end_comment

begin_define
define|#
directive|define
name|TXA_ENA_FSYNC
value|BIT_7
end_define

begin_comment
comment|/* Enable  force of sync Tx queue */
end_comment

begin_define
define|#
directive|define
name|TXA_DIS_FSYNC
value|BIT_6
end_define

begin_comment
comment|/* Disable force of sync Tx queue */
end_comment

begin_define
define|#
directive|define
name|TXA_ENA_ALLOC
value|BIT_5
end_define

begin_comment
comment|/* Enable  alloc of free bandwidth */
end_comment

begin_define
define|#
directive|define
name|TXA_DIS_ALLOC
value|BIT_4
end_define

begin_comment
comment|/* Disable alloc of free bandwidth */
end_comment

begin_define
define|#
directive|define
name|TXA_START_RC
value|BIT_3
end_define

begin_comment
comment|/* Start sync Rate Control */
end_comment

begin_define
define|#
directive|define
name|TXA_STOP_RC
value|BIT_2
end_define

begin_comment
comment|/* Stop  sync Rate Control */
end_comment

begin_define
define|#
directive|define
name|TXA_ENA_ARB
value|BIT_1
end_define

begin_comment
comment|/* Enable  Tx Arbiter */
end_comment

begin_define
define|#
directive|define
name|TXA_DIS_ARB
value|BIT_0
end_define

begin_comment
comment|/* Disable Tx Arbiter */
end_comment

begin_comment
comment|/*	TXA_TEST	 8 bit	Tx Arbiter Test Register */
end_comment

begin_define
define|#
directive|define
name|TXA_INT_T_ON
value|BIT_5
end_define

begin_comment
comment|/* Tx Arb Interval Timer Test On */
end_comment

begin_define
define|#
directive|define
name|TXA_INT_T_OFF
value|BIT_4
end_define

begin_comment
comment|/* Tx Arb Interval Timer Test Off */
end_comment

begin_define
define|#
directive|define
name|TXA_INT_T_STEP
value|BIT_3
end_define

begin_comment
comment|/* Tx Arb Interval Timer Step */
end_comment

begin_define
define|#
directive|define
name|TXA_LIM_T_ON
value|BIT_2
end_define

begin_comment
comment|/* Tx Arb Limit Timer Test On */
end_comment

begin_define
define|#
directive|define
name|TXA_LIM_T_OFF
value|BIT_1
end_define

begin_comment
comment|/* Tx Arb Limit Timer Test Off */
end_comment

begin_define
define|#
directive|define
name|TXA_LIM_T_STEP
value|BIT_0
end_define

begin_comment
comment|/* Tx Arb Limit Timer Step */
end_comment

begin_comment
comment|/*	TXA_STAT	 8 bit	Tx Arbiter Status Register */
end_comment

begin_define
define|#
directive|define
name|TXA_PRIO_XS
value|BIT_0
end_define

begin_comment
comment|/* sync queue has prio to send */
end_comment

begin_comment
comment|/*	Q_BC		32 bit	Current Byte Counter */
end_comment

begin_define
define|#
directive|define
name|BC_MAX
value|0xffff
end_define

begin_comment
comment|/* Bit 15.. 0:	Byte counter */
end_comment

begin_comment
comment|/* Rx BMU Control / Status Registers (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|BMU_IDLE
value|BIT_31
end_define

begin_comment
comment|/* BMU Idle State */
end_comment

begin_define
define|#
directive|define
name|BMU_RX_TCP_PKT
value|BIT_30
end_define

begin_comment
comment|/* Rx TCP Packet (when RSS Hash enabled) */
end_comment

begin_define
define|#
directive|define
name|BMU_RX_IP_PKT
value|BIT_29
end_define

begin_comment
comment|/* Rx IP  Packet (when RSS Hash enabled) */
end_comment

begin_define
define|#
directive|define
name|BMU_ENA_RX_RSS_HASH
value|BIT_15
end_define

begin_comment
comment|/* Enable  Rx RSS Hash */
end_comment

begin_define
define|#
directive|define
name|BMU_DIS_RX_RSS_HASH
value|BIT_14
end_define

begin_comment
comment|/* Disable Rx RSS Hash */
end_comment

begin_define
define|#
directive|define
name|BMU_ENA_RX_CHKSUM
value|BIT_13
end_define

begin_comment
comment|/* Enable  Rx TCP/IP Checksum Check */
end_comment

begin_define
define|#
directive|define
name|BMU_DIS_RX_CHKSUM
value|BIT_12
end_define

begin_comment
comment|/* Disable Rx TCP/IP Checksum Check */
end_comment

begin_define
define|#
directive|define
name|BMU_CLR_IRQ_PAR
value|BIT_11
end_define

begin_comment
comment|/* Clear IRQ on Parity errors (Rx) */
end_comment

begin_define
define|#
directive|define
name|BMU_CLR_IRQ_TCP
value|BIT_11
end_define

begin_comment
comment|/* Clear IRQ on TCP segmen. error (Tx) */
end_comment

begin_define
define|#
directive|define
name|BMU_CLR_IRQ_CHK
value|BIT_10
end_define

begin_comment
comment|/* Clear IRQ Check */
end_comment

begin_define
define|#
directive|define
name|BMU_STOP
value|BIT_9
end_define

begin_comment
comment|/* Stop  Rx/Tx Queue */
end_comment

begin_define
define|#
directive|define
name|BMU_START
value|BIT_8
end_define

begin_comment
comment|/* Start Rx/Tx Queue */
end_comment

begin_define
define|#
directive|define
name|BMU_FIFO_OP_ON
value|BIT_7
end_define

begin_comment
comment|/* FIFO Operational On */
end_comment

begin_define
define|#
directive|define
name|BMU_FIFO_OP_OFF
value|BIT_6
end_define

begin_comment
comment|/* FIFO Operational Off */
end_comment

begin_define
define|#
directive|define
name|BMU_FIFO_ENA
value|BIT_5
end_define

begin_comment
comment|/* Enable FIFO */
end_comment

begin_define
define|#
directive|define
name|BMU_FIFO_RST
value|BIT_4
end_define

begin_comment
comment|/* Reset  FIFO */
end_comment

begin_define
define|#
directive|define
name|BMU_OP_ON
value|BIT_3
end_define

begin_comment
comment|/* BMU Operational On */
end_comment

begin_define
define|#
directive|define
name|BMU_OP_OFF
value|BIT_2
end_define

begin_comment
comment|/* BMU Operational Off */
end_comment

begin_define
define|#
directive|define
name|BMU_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear BMU Reset (Enable) */
end_comment

begin_define
define|#
directive|define
name|BMU_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   BMU Reset */
end_comment

begin_define
define|#
directive|define
name|BMU_CLR_RESET
value|(BMU_FIFO_RST | BMU_OP_OFF | BMU_RST_CLR)
end_define

begin_define
define|#
directive|define
name|BMU_OPER_INIT
value|(BMU_CLR_IRQ_PAR | BMU_CLR_IRQ_CHK | \ 				 BMU_START | BMU_FIFO_ENA | BMU_OP_ON)
end_define

begin_comment
comment|/* Tx BMU Control / Status Registers (Yukon-2) */
end_comment

begin_comment
comment|/* Bit 31: same as for Rx */
end_comment

begin_define
define|#
directive|define
name|BMU_TX_IPIDINCR_ON
value|BIT_13
end_define

begin_comment
comment|/* Enable  IP ID Increment */
end_comment

begin_define
define|#
directive|define
name|BMU_TX_IPIDINCR_OFF
value|BIT_12
end_define

begin_comment
comment|/* Disable IP ID Increment */
end_comment

begin_define
define|#
directive|define
name|BMU_TX_CLR_IRQ_TCP
value|BIT_11
end_define

begin_comment
comment|/* Clear IRQ on TCP segm. length mism. */
end_comment

begin_comment
comment|/* Bit 10..0: same as for Rx */
end_comment

begin_comment
comment|/*	Q_F		32 bit	Flag Register */
end_comment

begin_define
define|#
directive|define
name|F_ALM_FULL
value|BIT_27
end_define

begin_comment
comment|/* Rx FIFO: almost full */
end_comment

begin_define
define|#
directive|define
name|F_EMPTY
value|BIT_27
end_define

begin_comment
comment|/* Tx FIFO: empty flag */
end_comment

begin_define
define|#
directive|define
name|F_FIFO_EOF
value|BIT_26
end_define

begin_comment
comment|/* Tag (EOF Flag) bit in FIFO */
end_comment

begin_define
define|#
directive|define
name|F_WM_REACHED
value|BIT_25
end_define

begin_comment
comment|/* Watermark reached */
end_comment

begin_define
define|#
directive|define
name|F_M_RX_RAM_DIS
value|BIT_24
end_define

begin_comment
comment|/* MAC Rx RAM Read Port disable */
end_comment

begin_define
define|#
directive|define
name|F_FIFO_LEVEL
value|(0x1f<<16)
end_define

begin_comment
comment|/* Bit 23..16:	# of Qwords in FIFO */
end_comment

begin_define
define|#
directive|define
name|F_WATER_MARK
value|0x0007ff
end_define

begin_comment
comment|/* Bit 10.. 0:	Watermark */
end_comment

begin_comment
comment|/* Queue Prefetch Unit Offsets, use Y2_PREF_Q_ADDR() to address (Yukon-2 only)*/
end_comment

begin_comment
comment|/* PREF_UNIT_CTRL_REG	32 bit	Prefetch Control register */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_OP_ON
value|BIT_3
end_define

begin_comment
comment|/* prefetch unit operational */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_OP_OFF
value|BIT_2
end_define

begin_comment
comment|/* prefetch unit not operational */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear Prefetch Unit Reset */
end_comment

begin_define
define|#
directive|define
name|PREF_UNIT_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   Prefetch Unit Reset */
end_comment

begin_comment
comment|/* RAM Buffer Register Offsets, use RB_ADDR(Queue, Offs) to access */
end_comment

begin_comment
comment|/*	RB_START	32 bit	RAM Buffer Start Address */
end_comment

begin_comment
comment|/*	RB_END		32 bit	RAM Buffer End Address */
end_comment

begin_comment
comment|/*	RB_WP		32 bit	RAM Buffer Write Pointer */
end_comment

begin_comment
comment|/*	RB_RP		32 bit	RAM Buffer Read Pointer */
end_comment

begin_comment
comment|/*	RB_RX_UTPP	32 bit	Rx Upper Threshold, Pause Pack */
end_comment

begin_comment
comment|/*	RB_RX_LTPP	32 bit	Rx Lower Threshold, Pause Pack */
end_comment

begin_comment
comment|/*	RB_RX_UTHP	32 bit	Rx Upper Threshold, High Prio */
end_comment

begin_comment
comment|/*	RB_RX_LTHP	32 bit	Rx Lower Threshold, High Prio */
end_comment

begin_comment
comment|/*	RB_PC		32 bit	RAM Buffer Packet Counter */
end_comment

begin_comment
comment|/*	RB_LEV		32 bit	RAM Buffer Level Register */
end_comment

begin_define
define|#
directive|define
name|RB_MSK
value|0x0007ffff
end_define

begin_comment
comment|/* Bit 18.. 0:	RAM Buffer Pointer Bits */
end_comment

begin_comment
comment|/*	RB_TST2		 8 bit	RAM Buffer Test Register 2 */
end_comment

begin_define
define|#
directive|define
name|RB_PC_DEC
value|BIT_3
end_define

begin_comment
comment|/* Packet Counter Decrement */
end_comment

begin_define
define|#
directive|define
name|RB_PC_T_ON
value|BIT_2
end_define

begin_comment
comment|/* Packet Counter Test On */
end_comment

begin_define
define|#
directive|define
name|RB_PC_T_OFF
value|BIT_1
end_define

begin_comment
comment|/* Packet Counter Test Off */
end_comment

begin_define
define|#
directive|define
name|RB_PC_INC
value|BIT_0
end_define

begin_comment
comment|/* Packet Counter Increment */
end_comment

begin_comment
comment|/*	RB_TST1		 8 bit	RAM Buffer Test Register 1 */
end_comment

begin_define
define|#
directive|define
name|RB_WP_T_ON
value|BIT_6
end_define

begin_comment
comment|/* Write Pointer Test On */
end_comment

begin_define
define|#
directive|define
name|RB_WP_T_OFF
value|BIT_5
end_define

begin_comment
comment|/* Write Pointer Test Off */
end_comment

begin_define
define|#
directive|define
name|RB_WP_INC
value|BIT_4
end_define

begin_comment
comment|/* Write Pointer Increment */
end_comment

begin_define
define|#
directive|define
name|RB_RP_T_ON
value|BIT_2
end_define

begin_comment
comment|/* Read Pointer Test On */
end_comment

begin_define
define|#
directive|define
name|RB_RP_T_OFF
value|BIT_1
end_define

begin_comment
comment|/* Read Pointer Test Off */
end_comment

begin_define
define|#
directive|define
name|RB_RP_INC
value|BIT_0
end_define

begin_comment
comment|/* Read Pointer Increment */
end_comment

begin_comment
comment|/*	RB_CTRL		 8 bit	RAM Buffer Control Register */
end_comment

begin_define
define|#
directive|define
name|RB_ENA_STFWD
value|BIT_5
end_define

begin_comment
comment|/* Enable  Store& Forward */
end_comment

begin_define
define|#
directive|define
name|RB_DIS_STFWD
value|BIT_4
end_define

begin_comment
comment|/* Disable Store& Forward */
end_comment

begin_define
define|#
directive|define
name|RB_ENA_OP_MD
value|BIT_3
end_define

begin_comment
comment|/* Enable  Operation Mode */
end_comment

begin_define
define|#
directive|define
name|RB_DIS_OP_MD
value|BIT_2
end_define

begin_comment
comment|/* Disable Operation Mode */
end_comment

begin_define
define|#
directive|define
name|RB_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear RAM Buf STM Reset */
end_comment

begin_define
define|#
directive|define
name|RB_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   RAM Buf STM Reset */
end_comment

begin_comment
comment|/* RAM Buffer High Pause Threshold values */
end_comment

begin_define
define|#
directive|define
name|MSK_RB_ULPP
value|(8 * 1024)
end_define

begin_comment
comment|/* Upper Level in kB/8 */
end_comment

begin_define
define|#
directive|define
name|MSK_RB_LLPP_S
value|(10 * 1024)
end_define

begin_comment
comment|/* Lower Level for small Queues */
end_comment

begin_define
define|#
directive|define
name|MSK_RB_LLPP_B
value|(16 * 1024)
end_define

begin_comment
comment|/* Lower Level for big Queues */
end_comment

begin_comment
comment|/* Threshold values for Yukon-EC Ultra */
end_comment

begin_define
define|#
directive|define
name|MSK_ECU_ULPP
value|0x0080
end_define

begin_comment
comment|/* Upper Pause Threshold (multiples of 8) */
end_comment

begin_define
define|#
directive|define
name|MSK_ECU_LLPP
value|0x0060
end_define

begin_comment
comment|/* Lower Pause Threshold (multiples of 8) */
end_comment

begin_define
define|#
directive|define
name|MSK_ECU_AE_THR
value|0x0180
end_define

begin_comment
comment|/* Almost Empty Threshold */
end_comment

begin_define
define|#
directive|define
name|MSK_ECU_TXFF_LEV
value|0x01a0
end_define

begin_comment
comment|/* Tx BMU FIFO Level */
end_comment

begin_define
define|#
directive|define
name|MSK_BMU_RX_WM
value|0x600
end_define

begin_comment
comment|/* BMU Rx Watermark */
end_comment

begin_define
define|#
directive|define
name|MSK_BMU_TX_WM
value|0x600
end_define

begin_comment
comment|/* BMU Tx Watermark */
end_comment

begin_comment
comment|/* performance sensitive drivers should set this define to 0x80 */
end_comment

begin_define
define|#
directive|define
name|MSK_BMU_RX_WM_PEX
value|0x600
end_define

begin_comment
comment|/* BMU Rx Watermark for PEX */
end_comment

begin_comment
comment|/* Receive and Transmit Queues */
end_comment

begin_define
define|#
directive|define
name|Q_R1
value|0x0000
end_define

begin_comment
comment|/* Receive Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Q_R2
value|0x0080
end_define

begin_comment
comment|/* Receive Queue 2 */
end_comment

begin_define
define|#
directive|define
name|Q_XS1
value|0x0200
end_define

begin_comment
comment|/* Synchronous Transmit Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Q_XA1
value|0x0280
end_define

begin_comment
comment|/* Asynchronous Transmit Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Q_XS2
value|0x0300
end_define

begin_comment
comment|/* Synchronous Transmit Queue 2 */
end_comment

begin_define
define|#
directive|define
name|Q_XA2
value|0x0380
end_define

begin_comment
comment|/* Asynchronous Transmit Queue 2 */
end_comment

begin_define
define|#
directive|define
name|Q_ASF_R1
value|0x100
end_define

begin_comment
comment|/* ASF Rx Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Q_ASF_R2
value|0x180
end_define

begin_comment
comment|/* ASF Rx Queue 2 */
end_comment

begin_define
define|#
directive|define
name|Q_ASF_T1
value|0x140
end_define

begin_comment
comment|/* ASF Tx Queue 1 */
end_comment

begin_define
define|#
directive|define
name|Q_ASF_T2
value|0x1c0
end_define

begin_comment
comment|/* ASF Tx Queue 2 */
end_comment

begin_define
define|#
directive|define
name|RB_ADDR
parameter_list|(
name|Queue
parameter_list|,
name|Offs
parameter_list|)
value|(B16_RAM_REGS + (Queue) + (Offs))
end_define

begin_comment
comment|/* Minimum RAM Buffer Rx Queue Size */
end_comment

begin_define
define|#
directive|define
name|MSK_MIN_RXQ_SIZE
value|10
end_define

begin_comment
comment|/* Minimum RAM Buffer Tx Queue Size */
end_comment

begin_define
define|#
directive|define
name|MSK_MIN_TXQ_SIZE
value|10
end_define

begin_comment
comment|/* Percentage of queue size from whole memory. 80 % for receive */
end_comment

begin_define
define|#
directive|define
name|MSK_RAM_QUOTA_RX
value|80
end_define

begin_comment
comment|/*	WOL_CTRL_STAT	16 bit	WOL Control/Status Reg */
end_comment

begin_define
define|#
directive|define
name|WOL_CTL_LINK_CHG_OCC
value|BIT_15
end_define

begin_define
define|#
directive|define
name|WOL_CTL_MAGIC_PKT_OCC
value|BIT_14
end_define

begin_define
define|#
directive|define
name|WOL_CTL_PATTERN_OCC
value|BIT_13
end_define

begin_define
define|#
directive|define
name|WOL_CTL_CLEAR_RESULT
value|BIT_12
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_PME_ON_LINK_CHG
value|BIT_11
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_PME_ON_LINK_CHG
value|BIT_10
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_PME_ON_MAGIC_PKT
value|BIT_9
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_PME_ON_MAGIC_PKT
value|BIT_8
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_PME_ON_PATTERN
value|BIT_7
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_PME_ON_PATTERN
value|BIT_6
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_LINK_CHG_UNIT
value|BIT_5
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_LINK_CHG_UNIT
value|BIT_4
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_MAGIC_PKT_UNIT
value|BIT_3
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_MAGIC_PKT_UNIT
value|BIT_2
end_define

begin_define
define|#
directive|define
name|WOL_CTL_ENA_PATTERN_UNIT
value|BIT_1
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DIS_PATTERN_UNIT
value|BIT_0
end_define

begin_define
define|#
directive|define
name|WOL_CTL_DEFAULT
define|\
value|(WOL_CTL_DIS_PME_ON_LINK_CHG |	\ 	 WOL_CTL_DIS_PME_ON_PATTERN |	\ 	 WOL_CTL_DIS_PME_ON_MAGIC_PKT |	\ 	 WOL_CTL_DIS_LINK_CHG_UNIT |	\ 	 WOL_CTL_DIS_PATTERN_UNIT |		\ 	 WOL_CTL_DIS_MAGIC_PKT_UNIT)
end_define

begin_comment
comment|/*	WOL_MATCH_CTL	 8 bit	WOL Match Control Reg */
end_comment

begin_define
define|#
directive|define
name|WOL_CTL_PATT_ENA
parameter_list|(
name|x
parameter_list|)
value|(BIT_0<< (x))
end_define

begin_comment
comment|/*	WOL_PATT_PME	8 bit	WOL PME Match Enable (Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_FORCE_PME
value|BIT_7
end_define

begin_comment
comment|/* Generates a PME */
end_comment

begin_define
define|#
directive|define
name|WOL_PATT_MATCH_PME_ALL
value|0x7f
end_define

begin_comment
comment|/*  * Marvel-PHY Registers, indirect addressed over GMAC  */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_CTRL
value|0x00
end_define

begin_comment
comment|/* 16 bit r/w	PHY Control Register */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_STAT
value|0x01
end_define

begin_comment
comment|/* 16 bit r/o	PHY Status Register */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID0
value|0x02
end_define

begin_comment
comment|/* 16 bit r/o	PHY ID0 Register */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1
value|0x03
end_define

begin_comment
comment|/* 16 bit r/o	PHY ID1 Register */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_AUNE_ADV
value|0x04
end_define

begin_comment
comment|/* 16 bit r/w	Auto-Neg. Advertisement */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_AUNE_LP
value|0x05
end_define

begin_comment
comment|/* 16 bit r/o	Link Part Ability Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_AUNE_EXP
value|0x06
end_define

begin_comment
comment|/* 16 bit r/o	Auto-Neg. Expansion Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_NEPG
value|0x07
end_define

begin_comment
comment|/* 16 bit r/w	Next Page Register */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_NEPG_LP
value|0x08
end_define

begin_comment
comment|/* 16 bit r/o	Next Page Link Partner */
end_comment

begin_comment
comment|/* Marvel-specific registers */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_1000T_CTRL
value|0x09
end_define

begin_comment
comment|/* 16 bit r/w	1000Base-T Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_1000T_STAT
value|0x0a
end_define

begin_comment
comment|/* 16 bit r/o	1000Base-T Status Reg */
end_comment

begin_comment
comment|/* 0x0b - 0x0e:		reserved */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_EXT_STAT
value|0x0f
end_define

begin_comment
comment|/* 16 bit r/o	Extended Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_PHY_CTRL
value|0x10
end_define

begin_comment
comment|/* 16 bit r/w	PHY Specific Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_PHY_STAT
value|0x11
end_define

begin_comment
comment|/* 16 bit r/o	PHY Specific Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_INT_MASK
value|0x12
end_define

begin_comment
comment|/* 16 bit r/w	Interrupt Mask Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_INT_STAT
value|0x13
end_define

begin_comment
comment|/* 16 bit r/o	Interrupt Status Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_EXT_CTRL
value|0x14
end_define

begin_comment
comment|/* 16 bit r/w	Ext. PHY Specific Ctrl */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_RXE_CNT
value|0x15
end_define

begin_comment
comment|/* 16 bit r/w	Receive Error Counter */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_EXT_ADR
value|0x16
end_define

begin_comment
comment|/* 16 bit r/w	Ext. Ad. for Cable Diag. */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_PORT_IRQ
value|0x17
end_define

begin_comment
comment|/* 16 bit r/o	Port 0 IRQ (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_LED_CTRL
value|0x18
end_define

begin_comment
comment|/* 16 bit r/w	LED Control Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_LED_OVER
value|0x19
end_define

begin_comment
comment|/* 16 bit r/w	Manual LED Override Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_EXT_CTRL_2
value|0x1a
end_define

begin_comment
comment|/* 16 bit r/w	Ext. PHY Specific Ctrl 2 */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_EXT_P_STAT
value|0x1b
end_define

begin_comment
comment|/* 16 bit r/w	Ext. PHY Spec. Stat Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_CABLE_DIAG
value|0x1c
end_define

begin_comment
comment|/* 16 bit r/o	Cable Diagnostic Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_PAGE_ADDR
value|0x1d
end_define

begin_comment
comment|/* 16 bit r/w	Extended Page Address Reg */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_PAGE_DATA
value|0x1e
end_define

begin_comment
comment|/* 16 bit r/w	Extended Page Data Reg */
end_comment

begin_comment
comment|/* for 10/100 Fast Ethernet PHY (88E3082 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_FE_LED_PAR
value|0x16
end_define

begin_comment
comment|/* 16 bit r/w	LED Parallel Select Reg. */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_FE_LED_SER
value|0x17
end_define

begin_comment
comment|/* 16 bit r/w	LED Stream Select S. LED */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_FE_VCT_TX
value|0x1a
end_define

begin_comment
comment|/* 16 bit r/w	VCT Reg. for TXP/N Pins */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_FE_VCT_RX
value|0x1b
end_define

begin_comment
comment|/* 16 bit r/o	VCT Reg. for RXP/N Pins */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_FE_SPEC_2
value|0x1c
end_define

begin_comment
comment|/* 16 bit r/w	Specific Control Reg. 2 */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_RESET
value|(1<<15)
end_define

begin_comment
comment|/* Bit 15: (sc)	clear all PHY related regs */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_LOOP
value|(1<<14)
end_define

begin_comment
comment|/* Bit 14:	enable Loopback over PHY */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_SPS_LSB
value|(1<<13)
end_define

begin_comment
comment|/* Bit 13:	Speed select, lower bit */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_ANE
value|(1<<12)
end_define

begin_comment
comment|/* Bit 12:	Auto-Negotiation Enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_PDOWN
value|(1<<11)
end_define

begin_comment
comment|/* Bit 11:	Power Down Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_ISOL
value|(1<<10)
end_define

begin_comment
comment|/* Bit 10:	Isolate Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_RE_CFG
value|(1<<9)
end_define

begin_comment
comment|/* Bit  9:	(sc) Restart Auto-Negotiation */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_DUP_MD
value|(1<<8)
end_define

begin_comment
comment|/* Bit  8:	Duplex Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_COL_TST
value|(1<<7)
end_define

begin_comment
comment|/* Bit  7:	Collision Test enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_SPS_MSB
value|(1<<6)
end_define

begin_comment
comment|/* Bit  6:	Speed select, upper bit */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_SP1000
value|PHY_CT_SPS_MSB
end_define

begin_comment
comment|/* enable speed of 1000 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_SP100
value|PHY_CT_SPS_LSB
end_define

begin_comment
comment|/* enable speed of  100 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_CT_SP10
value|(0)
end_define

begin_comment
comment|/* enable speed of   10 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_EXT_ST
value|(1<<8)
end_define

begin_comment
comment|/* Bit  8:	Extended Status Present */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_PRE_SUP
value|(1<<6)
end_define

begin_comment
comment|/* Bit  6:	Preamble Suppression */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_AN_OVER
value|(1<<5)
end_define

begin_comment
comment|/* Bit  5:	Auto-Negotiation Over */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_REM_FLT
value|(1<<4)
end_define

begin_comment
comment|/* Bit  4:	Remote Fault Condition Occured */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_AN_CAP
value|(1<<3)
end_define

begin_comment
comment|/* Bit  3:	Auto-Negotiation Capability */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_LSYNC
value|(1<<2)
end_define

begin_comment
comment|/* Bit  2:	Link Synchronized */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_JAB_DET
value|(1<<1)
end_define

begin_comment
comment|/* Bit  1:	Jabber Detected */
end_comment

begin_define
define|#
directive|define
name|PHY_ST_EXT_REG
value|(1<<0)
end_define

begin_comment
comment|/* Bit  0:	Extended Register available */
end_comment

begin_define
define|#
directive|define
name|PHY_I1_OUI_MSK
value|(0x3f<<10)
end_define

begin_comment
comment|/* Bit 15..10:	Organization Unique ID */
end_comment

begin_define
define|#
directive|define
name|PHY_I1_MOD_NUM
value|(0x3f<<4)
end_define

begin_comment
comment|/* Bit  9.. 4:	Model Number */
end_comment

begin_define
define|#
directive|define
name|PHY_I1_REV_MSK
value|0xf
end_define

begin_comment
comment|/* Bit  3.. 0:	Revision Number */
end_comment

begin_comment
comment|/* different Marvell PHY Ids */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID0_VAL
value|0x0141
end_define

begin_comment
comment|/* Marvell Unique Identifier */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_B0
value|0x0C23
end_define

begin_comment
comment|/* Yukon (PHY 88E1011) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_B2
value|0x0C25
end_define

begin_comment
comment|/* Yukon-Plus (PHY 88E1011) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_C2
value|0x0CC2
end_define

begin_comment
comment|/* Yukon-EC (PHY 88E1111) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_Y2
value|0x0C91
end_define

begin_comment
comment|/* Yukon-2 (PHY 88E1112) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_FE
value|0x0C83
end_define

begin_comment
comment|/* Yukon-FE (PHY 88E3082 Rev.A1) */
end_comment

begin_define
define|#
directive|define
name|PHY_MARV_ID1_ECU
value|0x0CB0
end_define

begin_comment
comment|/* Yukon-2 (PHY 88E1149 Rev.B2?) */
end_comment

begin_comment
comment|/*****  PHY_MARV_1000T_STAT	16 bit r/o	1000Base-T Status Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_MSF
value|(1<<15)
end_define

begin_comment
comment|/* Bit 15:	Master/Slave Fault */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_MSR
value|(1<<14)
end_define

begin_comment
comment|/* Bit 14:	Master/Slave Result */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_LRS
value|(1<<13)
end_define

begin_comment
comment|/* Bit 13:	Local Receiver Status */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_RRS
value|(1<<12)
end_define

begin_comment
comment|/* Bit 12:	Remote Receiver Status */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_LP_FD
value|(1<<11)
end_define

begin_comment
comment|/* Bit 11:	Link Partner can FD */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_LP_HD
value|(1<<10)
end_define

begin_comment
comment|/* Bit 10:	Link Partner can HD */
end_comment

begin_define
define|#
directive|define
name|PHY_B_1000S_IEC
value|0xff
end_define

begin_comment
comment|/* Bit  7..0:	Idle Error Count */
end_comment

begin_comment
comment|/*****  PHY_MARV_AUNE_ADV	16 bit r/w	Auto-Negotiation Advertisement *****/
end_comment

begin_comment
comment|/*****  PHY_MARV_AUNE_LP	16 bit r/w	Link Part Ability Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_NXT_PG
value|BIT_15
end_define

begin_comment
comment|/* Request Next Page */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_ACK
value|BIT_14
end_define

begin_comment
comment|/* (ro)	Acknowledge Received */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_RF
value|BIT_13
end_define

begin_comment
comment|/* Remote Fault */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_ASP
value|BIT_11
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_PC
value|BIT_10
end_define

begin_comment
comment|/* MAC Pause implemented */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_100_T4
value|BIT_9
end_define

begin_comment
comment|/* Not cap. 100Base-T4 (always 0) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_100_FD
value|BIT_8
end_define

begin_comment
comment|/* Advertise 100Base-TX Full Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_100_HD
value|BIT_7
end_define

begin_comment
comment|/* Advertise 100Base-TX Half Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_10_FD
value|BIT_6
end_define

begin_comment
comment|/* Advertise 10Base-TX Full Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_10_HD
value|BIT_5
end_define

begin_comment
comment|/* Advertise 10Base-TX Half Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_SEL_MSK
value|(0x1f<<4)
end_define

begin_comment
comment|/* Bit  4.. 0: Selector Field Mask */
end_comment

begin_comment
comment|/* special defines for FIBER (88E1011S only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_ASP_X
value|BIT_8
end_define

begin_comment
comment|/* Asymmetric Pause */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_PC_X
value|BIT_7
end_define

begin_comment
comment|/* MAC Pause implemented */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_1000X_AHD
value|BIT_6
end_define

begin_comment
comment|/* Advertise 10000Base-X Half Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_AN_1000X_AFD
value|BIT_5
end_define

begin_comment
comment|/* Advertise 10000Base-X Full Duplex */
end_comment

begin_comment
comment|/* Pause Bits (PHY_M_AN_ASP_X and PHY_M_AN_PC_X) encoding */
end_comment

begin_define
define|#
directive|define
name|PHY_M_P_NO_PAUSE_X
value|(0<<7)
end_define

begin_comment
comment|/* Bit  8.. 7:	no Pause Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_M_P_SYM_MD_X
value|(1<<7)
end_define

begin_comment
comment|/* Bit  8.. 7:	symmetric Pause Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_M_P_ASYM_MD_X
value|(2<<7)
end_define

begin_comment
comment|/* Bit  8.. 7:	asymmetric Pause Mode */
end_comment

begin_define
define|#
directive|define
name|PHY_M_P_BOTH_MD_X
value|(3<<7)
end_define

begin_comment
comment|/* Bit  8.. 7:	both Pause Mode */
end_comment

begin_comment
comment|/*****  PHY_MARV_1000T_CTRL	16 bit r/w	1000Base-T Control Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_TEST
value|(7<<13)
end_define

begin_comment
comment|/* Bit 15..13:	Test Modes */
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_MSE
value|BIT_12
end_define

begin_comment
comment|/* Manual Master/Slave Enable */
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_MSC
value|BIT_11
end_define

begin_comment
comment|/* M/S Configuration (1=Master) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_MPD
value|BIT_10
end_define

begin_comment
comment|/* Multi-Port Device */
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_AFD
value|BIT_9
end_define

begin_comment
comment|/* Advertise Full Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_1000C_AHD
value|BIT_8
end_define

begin_comment
comment|/* Advertise Half Duplex */
end_comment

begin_comment
comment|/*****  PHY_MARV_PHY_CTRL	16 bit r/w	PHY Specific Ctrl Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_TX_FFD_MSK
value|(3<<14)
end_define

begin_comment
comment|/* Bit 15..14: Tx FIFO Depth Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_RX_FFD_MSK
value|(3<<12)
end_define

begin_comment
comment|/* Bit 13..12: Rx FIFO Depth Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ASS_CRS_TX
value|BIT_11
end_define

begin_comment
comment|/* Assert CRS on Transmit */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_FL_GOOD
value|BIT_10
end_define

begin_comment
comment|/* Force Link Good */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_EN_DET_MSK
value|(3<<8)
end_define

begin_comment
comment|/* Bit  9.. 8: Energy Detect Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ENA_EXT_D
value|BIT_7
end_define

begin_comment
comment|/* Enable Ext. Distance (10BT) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_MDIX_MSK
value|(3<<5)
end_define

begin_comment
comment|/* Bit  6.. 5: MDI/MDIX Config. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_125CLK
value|BIT_4
end_define

begin_comment
comment|/* Disable 125 CLK */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_MAC_POW_UP
value|BIT_3
end_define

begin_comment
comment|/* MAC Power up */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_SQE_T_ENA
value|BIT_2
end_define

begin_comment
comment|/* SQE Test Enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_POL_R_DIS
value|BIT_1
end_define

begin_comment
comment|/* Polarity Reversal Disabled */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_JABBER
value|BIT_0
end_define

begin_comment
comment|/* Disable Jabber */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_EN_DET
value|SHIFT8(2)
end_define

begin_comment
comment|/* Energy Detect (Mode 1) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_EN_DET_PLUS
value|SHIFT8(3)
end_define

begin_comment
comment|/* Energy Detect Plus (Mode 2) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_MDI_XMODE
parameter_list|(
name|x
parameter_list|)
value|(SHIFT5(x)& PHY_M_PC_MDIX_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_PC_MAN_MDI
value|0
end_define

begin_comment
comment|/* 00 = Manual MDI configuration */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_MAN_MDIX
value|1
end_define

begin_comment
comment|/* 01 = Manual MDIX configuration */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ENA_AUTO
value|3
end_define

begin_comment
comment|/* 11 = Enable Automatic Crossover */
end_comment

begin_comment
comment|/* for Yukon-2 Gigabit Ethernet PHY (88E1112 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_LINK_P
value|BIT_15
end_define

begin_comment
comment|/* Disable Link Pulses */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DSC_MSK
value|(7<<12)
end_define

begin_comment
comment|/* Bit 14..12:	Downshift Counter */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DOWN_S_ENA
value|BIT_11
end_define

begin_comment
comment|/* Downshift Enable */
end_comment

begin_comment
comment|/* !!! Errata in spec. (1 = disable) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DSC
parameter_list|(
name|x
parameter_list|)
value|(SHIFT12(x)& PHY_M_PC_DSC_MSK)
end_define

begin_comment
comment|/* 000=1x; 001=2x; 010=3x; 011=4x */
end_comment

begin_comment
comment|/* 100=5x; 101=6x; 110=7x; 111=8x */
end_comment

begin_comment
comment|/* for 10/100 Fast Ethernet PHY (88E3082 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ENA_DTE_DT
value|BIT_15
end_define

begin_comment
comment|/* Enable Data Terminal Equ. (DTE) Detect */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ENA_ENE_DT
value|BIT_14
end_define

begin_comment
comment|/* Enable Energy Detect (sense& pulse) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_NLP_CK
value|BIT_13
end_define

begin_comment
comment|/* Disable Normal Link Puls (NLP) Check */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_ENA_LIP_NP
value|BIT_12
end_define

begin_comment
comment|/* Enable Link Partner Next Page Reg. */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_NLP_GN
value|BIT_11
end_define

begin_comment
comment|/* Disable Normal Link Puls Generation */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_SCRAMB
value|BIT_9
end_define

begin_comment
comment|/* Disable Scrambler */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_DIS_FEFI
value|BIT_8
end_define

begin_comment
comment|/* Disable Far End Fault Indic. (FEFI) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_SH_TP_SEL
value|BIT_6
end_define

begin_comment
comment|/* Shielded Twisted Pair Select */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PC_RX_FD_MSK
value|(3<<2)
end_define

begin_comment
comment|/* Bit  3.. 2: Rx FIFO Depth Mask */
end_comment

begin_comment
comment|/*****  PHY_MARV_PHY_STAT	16 bit r/o	PHY Specific Status Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_SPEED_MSK
value|(3<<14)
end_define

begin_comment
comment|/* Bit 15..14: Speed Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_SPEED_1000
value|BIT_15
end_define

begin_comment
comment|/*	10 = 1000 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_SPEED_100
value|BIT_14
end_define

begin_comment
comment|/*	01 =  100 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_SPEED_10
value|0
end_define

begin_comment
comment|/*	00 =   10 Mbps */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_FULL_DUP
value|BIT_13
end_define

begin_comment
comment|/* Full Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_PAGE_REC
value|BIT_12
end_define

begin_comment
comment|/* Page Received */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_SPDUP_RES
value|BIT_11
end_define

begin_comment
comment|/* Speed& Duplex Resolved */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_LINK_UP
value|BIT_10
end_define

begin_comment
comment|/* Link Up */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_CABLE_MSK
value|(7<<7)
end_define

begin_comment
comment|/* Bit  9.. 7: Cable Length Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_MDI_X_STAT
value|BIT_6
end_define

begin_comment
comment|/* MDI Crossover Stat (1=MDIX) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_DOWNS_STAT
value|BIT_5
end_define

begin_comment
comment|/* Downshift Status (1=downsh.) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_ENDET_STAT
value|BIT_4
end_define

begin_comment
comment|/* Energy Detect Status (1=act) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_TX_P_EN
value|BIT_3
end_define

begin_comment
comment|/* Tx Pause Enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_RX_P_EN
value|BIT_2
end_define

begin_comment
comment|/* Rx Pause Enabled */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_POL_REV
value|BIT_1
end_define

begin_comment
comment|/* Polarity Reversed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_JABBER
value|BIT_0
end_define

begin_comment
comment|/* Jabber */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_PAUSE_MSK
value|(PHY_M_PS_TX_P_EN | PHY_M_PS_RX_P_EN)
end_define

begin_comment
comment|/* for 10/100 Fast Ethernet PHY (88E3082 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_DTE_DETECT
value|BIT_15
end_define

begin_comment
comment|/* Data Terminal Equipment (DTE) Detected */
end_comment

begin_define
define|#
directive|define
name|PHY_M_PS_RES_SPEED
value|BIT_14
end_define

begin_comment
comment|/* Resolved Speed (1=100 Mbps, 0=10 Mbps */
end_comment

begin_comment
comment|/*****  PHY_MARV_INT_MASK	16 bit r/w	Interrupt Mask Reg *****/
end_comment

begin_comment
comment|/*****  PHY_MARV_INT_STAT	16 bit r/o	Interrupt Status Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_AN_ERROR
value|BIT_15
end_define

begin_comment
comment|/* Auto-Negotiation Error */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_LSP_CHANGE
value|BIT_14
end_define

begin_comment
comment|/* Link Speed Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_DUP_CHANGE
value|BIT_13
end_define

begin_comment
comment|/* Duplex Mode Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_AN_PR
value|BIT_12
end_define

begin_comment
comment|/* Page Received */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_AN_COMPL
value|BIT_11
end_define

begin_comment
comment|/* Auto-Negotiation Completed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_LST_CHANGE
value|BIT_10
end_define

begin_comment
comment|/* Link Status Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_SYMB_ERROR
value|BIT_9
end_define

begin_comment
comment|/* Symbol Error */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_FALSE_CARR
value|BIT_8
end_define

begin_comment
comment|/* False Carrier */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_FIFO_ERROR
value|BIT_7
end_define

begin_comment
comment|/* FIFO Overflow/Underrun Error */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_MDI_CHANGE
value|BIT_6
end_define

begin_comment
comment|/* MDI Crossover Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_DOWNSH_DET
value|BIT_5
end_define

begin_comment
comment|/* Downshift Detected */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_END_CHANGE
value|BIT_4
end_define

begin_comment
comment|/* Energy Detect Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_DTE_CHANGE
value|BIT_2
end_define

begin_comment
comment|/* DTE Power Det. Status Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_POL_CHANGE
value|BIT_1
end_define

begin_comment
comment|/* Polarity Changed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IS_JABBER
value|BIT_0
end_define

begin_comment
comment|/* Jabber */
end_comment

begin_define
define|#
directive|define
name|PHY_M_DEF_MSK
value|(PHY_M_IS_AN_ERROR | PHY_M_IS_AN_PR | \ 				PHY_M_IS_LST_CHANGE | PHY_M_IS_FIFO_ERROR)
end_define

begin_comment
comment|/*****  PHY_MARV_EXT_CTRL	16 bit r/w	Ext. PHY Specific Ctrl *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_ENA_BC_EXT
value|BIT_15
end_define

begin_comment
comment|/* Enable Block Carr. Ext. (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_ENA_LIN_LB
value|BIT_14
end_define

begin_comment
comment|/* Enable Line Loopback (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_DIS_LINK_P
value|BIT_12
end_define

begin_comment
comment|/* Disable Link Pulses (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_M_DSC_MSK
value|(3<<10)
end_define

begin_comment
comment|/* Bit 11..10:	Master Downshift Counter */
end_comment

begin_comment
comment|/* (88E1011 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_S_DSC_MSK
value|(3<<8)
end_define

begin_comment
comment|/* Bit  9.. 8:	Slave  Downshift Counter */
end_comment

begin_comment
comment|/* (88E1011 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_DSC_MSK_2
value|(7<<9)
end_define

begin_comment
comment|/* Bit 11.. 9:	Downshift Counter */
end_comment

begin_comment
comment|/* (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_DOWN_S_ENA
value|BIT_8
end_define

begin_comment
comment|/* Downshift Enable (88E1111 only) */
end_comment

begin_comment
comment|/* !!! Errata in spec. (1 = disable) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_RX_TIM_CT
value|BIT_7
end_define

begin_comment
comment|/* RGMII Rx Timing Control*/
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_MAC_S_MSK
value|(7<<4)
end_define

begin_comment
comment|/* Bit  6.. 4:	Def. MAC interface speed */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_FIB_AN_ENA
value|BIT_3
end_define

begin_comment
comment|/* Fiber Auto-Neg. Enable (88E1011S only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_DTE_D_ENA
value|BIT_2
end_define

begin_comment
comment|/* DTE Detect Enable (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_TX_TIM_CT
value|BIT_1
end_define

begin_comment
comment|/* RGMII Tx Timing Control */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_TRANS_DIS
value|BIT_0
end_define

begin_comment
comment|/* Transmitter Disable (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_M_DSC
parameter_list|(
name|x
parameter_list|)
value|(SHIFT10(x)& PHY_M_EC_M_DSC_MSK)
end_define

begin_comment
comment|/* 00=1x; 01=2x; 10=3x; 11=4x */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_S_DSC
parameter_list|(
name|x
parameter_list|)
value|(SHIFT8(x)& PHY_M_EC_S_DSC_MSK)
end_define

begin_comment
comment|/* 00=dis; 01=1x; 10=2x; 11=3x */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_MAC_S
parameter_list|(
name|x
parameter_list|)
value|(SHIFT4(x)& PHY_M_EC_MAC_S_MSK)
end_define

begin_comment
comment|/* 01X=0; 110=2.5; 111=25 (MHz) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC_DSC_2
parameter_list|(
name|x
parameter_list|)
value|(SHIFT9(x)& PHY_M_EC_DSC_MSK_2)
end_define

begin_comment
comment|/* 000=1x; 001=2x; 010=3x; 011=4x */
end_comment

begin_comment
comment|/* 100=5x; 101=6x; 110=7x; 111=8x */
end_comment

begin_define
define|#
directive|define
name|MAC_TX_CLK_0_MHZ
value|2
end_define

begin_define
define|#
directive|define
name|MAC_TX_CLK_2_5_MHZ
value|6
end_define

begin_define
define|#
directive|define
name|MAC_TX_CLK_25_MHZ
value|7
end_define

begin_comment
comment|/*****  PHY_MARV_LED_CTRL	16 bit r/w	LED Control Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_DIS_LED
value|BIT_15
end_define

begin_comment
comment|/* Disable LED */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_PULS_MSK
value|(7<<12)
end_define

begin_comment
comment|/* Bit 14..12: Pulse Stretch Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_F_INT
value|BIT_11
end_define

begin_comment
comment|/* Force Interrupt */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_BL_R_MSK
value|(7<<8)
end_define

begin_comment
comment|/* Bit 10.. 8: Blink Rate Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_DP_C_LSB
value|BIT_7
end_define

begin_comment
comment|/* Duplex Control (LSB, 88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_TX_C_LSB
value|BIT_6
end_define

begin_comment
comment|/* Tx Control (LSB, 88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_LK_C_MSK
value|(7<<3)
end_define

begin_comment
comment|/* Bit  5.. 3: Link Control Mask */
end_comment

begin_comment
comment|/* (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_LINK_MSK
value|(3<<3)
end_define

begin_comment
comment|/* Bit  4.. 3: Link Control Mask */
end_comment

begin_comment
comment|/* (88E1011 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_DP_CTRL
value|BIT_2
end_define

begin_comment
comment|/* Duplex Control */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_DP_C_MSB
value|BIT_2
end_define

begin_comment
comment|/* Duplex Control (MSB, 88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_RX_CTRL
value|BIT_1
end_define

begin_comment
comment|/* Rx Activity / Link */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_TX_CTRL
value|BIT_0
end_define

begin_comment
comment|/* Tx Activity / Link */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_TX_C_MSB
value|BIT_0
end_define

begin_comment
comment|/* Tx Control (MSB, 88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_PULS_DUR
parameter_list|(
name|x
parameter_list|)
value|(SHIFT12(x)& PHY_M_LEDC_PULS_MSK)
end_define

begin_define
define|#
directive|define
name|PULS_NO_STR
value|0
end_define

begin_comment
comment|/* no pulse stretching */
end_comment

begin_define
define|#
directive|define
name|PULS_21MS
value|1
end_define

begin_comment
comment|/* 21 ms to 42 ms */
end_comment

begin_define
define|#
directive|define
name|PULS_42MS
value|2
end_define

begin_comment
comment|/* 42 ms to 84 ms */
end_comment

begin_define
define|#
directive|define
name|PULS_84MS
value|3
end_define

begin_comment
comment|/* 84 ms to 170 ms */
end_comment

begin_define
define|#
directive|define
name|PULS_170MS
value|4
end_define

begin_comment
comment|/* 170 ms to 340 ms */
end_comment

begin_define
define|#
directive|define
name|PULS_340MS
value|5
end_define

begin_comment
comment|/* 340 ms to 670 ms */
end_comment

begin_define
define|#
directive|define
name|PULS_670MS
value|6
end_define

begin_comment
comment|/* 670 ms to 1.3 s */
end_comment

begin_define
define|#
directive|define
name|PULS_1300MS
value|7
end_define

begin_comment
comment|/* 1.3 s to 2.7 s */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_BLINK_RT
parameter_list|(
name|x
parameter_list|)
value|(SHIFT8(x)& PHY_M_LEDC_BL_R_MSK)
end_define

begin_define
define|#
directive|define
name|BLINK_42MS
value|0
end_define

begin_comment
comment|/* 42 ms */
end_comment

begin_define
define|#
directive|define
name|BLINK_84MS
value|1
end_define

begin_comment
comment|/* 84 ms */
end_comment

begin_define
define|#
directive|define
name|BLINK_170MS
value|2
end_define

begin_comment
comment|/* 170 ms */
end_comment

begin_define
define|#
directive|define
name|BLINK_340MS
value|3
end_define

begin_comment
comment|/* 340 ms */
end_comment

begin_define
define|#
directive|define
name|BLINK_670MS
value|4
end_define

begin_comment
comment|/* 670 ms */
end_comment

begin_comment
comment|/*****  PHY_MARV_LED_OVER	16 bit r/w	Manual LED Override Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_SGMII
parameter_list|(
name|x
parameter_list|)
value|SHIFT14(x)
end_define

begin_comment
comment|/* Bit 15..14:  SGMII AN Timer */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_DUP
parameter_list|(
name|x
parameter_list|)
value|SHIFT10(x)
end_define

begin_comment
comment|/* Bit 11..10:  Duplex */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_10
parameter_list|(
name|x
parameter_list|)
value|SHIFT8(x)
end_define

begin_comment
comment|/* Bit  9.. 8:  Link 10 */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_100
parameter_list|(
name|x
parameter_list|)
value|SHIFT6(x)
end_define

begin_comment
comment|/* Bit  7.. 6:  Link 100 */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_1000
parameter_list|(
name|x
parameter_list|)
value|SHIFT4(x)
end_define

begin_comment
comment|/* Bit  5.. 4:  Link 1000 */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_RX
parameter_list|(
name|x
parameter_list|)
value|SHIFT2(x)
end_define

begin_comment
comment|/* Bit  3.. 2:  Rx */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LED_MO_TX
parameter_list|(
name|x
parameter_list|)
value|SHIFT0(x)
end_define

begin_comment
comment|/* Bit  1.. 0:  Tx */
end_comment

begin_define
define|#
directive|define
name|MO_LED_NORM
value|0
end_define

begin_define
define|#
directive|define
name|MO_LED_BLINK
value|1
end_define

begin_define
define|#
directive|define
name|MO_LED_OFF
value|2
end_define

begin_define
define|#
directive|define
name|MO_LED_ON
value|3
end_define

begin_comment
comment|/*****  PHY_MARV_EXT_CTRL_2	16 bit r/w	Ext. PHY Specific Ctrl 2 *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC2_FI_IMPED
value|BIT_6
end_define

begin_comment
comment|/* Fiber Input  Impedance */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC2_FO_IMPED
value|BIT_5
end_define

begin_comment
comment|/* Fiber Output Impedance */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC2_FO_M_CLK
value|BIT_4
end_define

begin_comment
comment|/* Fiber Mode Clock Enable */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC2_FO_BOOST
value|BIT_3
end_define

begin_comment
comment|/* Fiber Output Boost */
end_comment

begin_define
define|#
directive|define
name|PHY_M_EC2_FO_AM_MSK
value|7
end_define

begin_comment
comment|/* Bit  2.. 0:	Fiber Output Amplitude */
end_comment

begin_comment
comment|/*****  PHY_MARV_EXT_P_STAT 16 bit r/w	Ext. PHY Specific Status *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_FC_AUTO_SEL
value|BIT_15
end_define

begin_comment
comment|/* Fiber/Copper Auto Sel. Dis. */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FC_AN_REG_ACC
value|BIT_14
end_define

begin_comment
comment|/* Fiber/Copper AN Reg. Access */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FC_RESOLUTION
value|BIT_13
end_define

begin_comment
comment|/* Fiber/Copper Resolution */
end_comment

begin_define
define|#
directive|define
name|PHY_M_SER_IF_AN_BP
value|BIT_12
end_define

begin_comment
comment|/* Ser. IF AN Bypass Enable */
end_comment

begin_define
define|#
directive|define
name|PHY_M_SER_IF_BP_ST
value|BIT_11
end_define

begin_comment
comment|/* Ser. IF AN Bypass Status */
end_comment

begin_define
define|#
directive|define
name|PHY_M_IRQ_POLARITY
value|BIT_10
end_define

begin_comment
comment|/* IRQ polarity */
end_comment

begin_define
define|#
directive|define
name|PHY_M_DIS_AUT_MED
value|BIT_9
end_define

begin_comment
comment|/* Disable Aut. Medium Reg. Selection */
end_comment

begin_comment
comment|/* (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_UNDOC1
value|BIT_7
end_define

begin_comment
comment|/* undocumented bit !! */
end_comment

begin_define
define|#
directive|define
name|PHY_M_DTE_POW_STAT
value|BIT_4
end_define

begin_comment
comment|/* DTE Power Status (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_MODE_MASK
value|0xf
end_define

begin_comment
comment|/* Bit  3.. 0: copy of HWCFG MODE[3:0] */
end_comment

begin_comment
comment|/*****  PHY_MARV_CABLE_DIAG	16 bit r/o	Cable Diagnostic Reg *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_CABD_ENA_TEST
value|BIT_15
end_define

begin_comment
comment|/* Enable Test (Page 0) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_CABD_DIS_WAIT
value|BIT_15
end_define

begin_comment
comment|/* Disable Waiting Period (Page 1) */
end_comment

begin_comment
comment|/* (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_CABD_STAT_MSK
value|(3<<13)
end_define

begin_comment
comment|/* Bit 14..13: Status Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_CABD_AMPL_MSK
value|(0x1f<<8)
end_define

begin_comment
comment|/* Bit 12.. 8: Amplitude Mask */
end_comment

begin_comment
comment|/* (88E1111 only) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_CABD_DIST_MSK
value|0xff
end_define

begin_comment
comment|/* Bit  7.. 0: Distance Mask */
end_comment

begin_comment
comment|/* values for Cable Diagnostic Status (11=fail; 00=OK; 10=open; 01=short) */
end_comment

begin_define
define|#
directive|define
name|CABD_STAT_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|CABD_STAT_SHORT
value|1
end_define

begin_define
define|#
directive|define
name|CABD_STAT_OPEN
value|2
end_define

begin_define
define|#
directive|define
name|CABD_STAT_FAIL
value|3
end_define

begin_comment
comment|/* for 10/100 Fast Ethernet PHY (88E3082 only) */
end_comment

begin_comment
comment|/*****  PHY_MARV_FE_LED_PAR	16 bit r/w	LED Parallel Select Reg. *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_FELP_LED2_MSK
value|(0xf<<8)
end_define

begin_comment
comment|/* Bit 11.. 8: LED2 Mask (LINK) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FELP_LED1_MSK
value|(0xf<<4)
end_define

begin_comment
comment|/* Bit  7.. 4: LED1 Mask (ACT) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FELP_LED0_MSK
value|0xf
end_define

begin_comment
comment|/* Bit  3.. 0: LED0 Mask (SPEED) */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FELP_LED2_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT8(x)& PHY_M_FELP_LED2_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_FELP_LED1_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT4(x)& PHY_M_FELP_LED1_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_FELP_LED0_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT0(x)& PHY_M_FELP_LED0_MSK)
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_COLX
value|0x00
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_ERROR
value|0x01
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_DUPLEX
value|0x02
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_DP_COL
value|0x03
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_SPEED
value|0x04
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_LINK
value|0x05
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_TX
value|0x06
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_RX
value|0x07
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_ACT
value|0x08
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_LNK_RX
value|0x09
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_LNK_AC
value|0x0a
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_ACT_BL
value|0x0b
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_TX_BL
value|0x0c
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_RX_BL
value|0x0d
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_COL_BL
value|0x0e
end_define

begin_define
define|#
directive|define
name|LED_PAR_CTRL_INACT
value|0x0f
end_define

begin_comment
comment|/*****  PHY_MARV_FE_SPEC_2	16 bit r/w Specific Control Reg. 2 *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_FESC_DIS_WAIT
value|BIT_2
end_define

begin_comment
comment|/* Disable TDR Waiting Period */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FESC_ENA_MCLK
value|BIT_1
end_define

begin_comment
comment|/* Enable MAC Rx Clock in sleep mode */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FESC_SEL_CL_A
value|BIT_0
end_define

begin_comment
comment|/* Select Class A driver (100B-TX) */
end_comment

begin_comment
comment|/* for Yukon-2 Gigabit Ethernet PHY (88E1112 only) */
end_comment

begin_comment
comment|/*****  PHY_MARV_PHY_CTRL (page 1)	16 bit r/w Fiber Specific Ctrl *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_FIB_FORCE_LNK
value|BIT_10
end_define

begin_comment
comment|/* Force Link Good */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FIB_SIGD_POL
value|BIT_9
end_define

begin_comment
comment|/* SIGDET Polarity */
end_comment

begin_define
define|#
directive|define
name|PHY_M_FIB_TX_DIS
value|BIT_3
end_define

begin_comment
comment|/* Transmitter Disable */
end_comment

begin_comment
comment|/*****  PHY_MARV_PHY_CTRL (page 2)	16 bit r/w MAC Specific Ctrl *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_MAC_MD_MSK
value|(7<<7)
end_define

begin_comment
comment|/* Bit  9.. 7: Mode Select Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_MAC_MD_AUTO
value|3
end_define

begin_comment
comment|/* Auto Copper/1000Base-X */
end_comment

begin_define
define|#
directive|define
name|PHY_M_MAC_MD_COPPER
value|5
end_define

begin_comment
comment|/* Copper only */
end_comment

begin_define
define|#
directive|define
name|PHY_M_MAC_MD_1000BX
value|7
end_define

begin_comment
comment|/* 1000Base-X only */
end_comment

begin_define
define|#
directive|define
name|PHY_M_MAC_MODE_SEL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT7(x)& PHY_M_MAC_MD_MSK)
end_define

begin_comment
comment|/*****  PHY_MARV_PHY_CTRL (page 3)	16 bit r/w LED Control Reg. *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_LOS_MSK
value|(0xf<<12)
end_define

begin_comment
comment|/* Bit 15..12: LOS LED Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_INIT_MSK
value|(0xf<<8)
end_define

begin_comment
comment|/* Bit 11.. 8: INIT LED Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_STA1_MSK
value|(0xf<<4)
end_define

begin_comment
comment|/* Bit  7.. 4: STAT1 LED Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_STA0_MSK
value|0xf
end_define

begin_comment
comment|/* Bit  3.. 0: STAT0 LED Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_LEDC_LOS_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT12(x)& PHY_M_LEDC_LOS_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_LEDC_INIT_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT8(x)& PHY_M_LEDC_INIT_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_LEDC_STA1_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT4(x)& PHY_M_LEDC_STA1_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_LEDC_STA0_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT0(x)& PHY_M_LEDC_STA0_MSK)
end_define

begin_comment
comment|/*****  PHY_MARV_PHY_STAT (page 3)	16 bit r/w Polarity Control Reg. *****/
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_LS1M_MSK
value|(0xf<<12)
end_define

begin_comment
comment|/* Bit 15..12: LOS,STAT1 Mix % Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_IS0M_MSK
value|(0xf<<8)
end_define

begin_comment
comment|/* Bit 11.. 8: INIT,STAT0 Mix % Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_LOS_MSK
value|(0x3<<6)
end_define

begin_comment
comment|/* Bit  7.. 6: LOS Pol. Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_INIT_MSK
value|(0x3<<4)
end_define

begin_comment
comment|/* Bit  5.. 4: INIT Pol. Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_STA1_MSK
value|(0x3<<2)
end_define

begin_comment
comment|/* Bit  3.. 2: STAT1 Pol. Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_STA0_MSK
value|0x3
end_define

begin_comment
comment|/* Bit  1.. 0: STAT0 Pol. Ctrl. Mask */
end_comment

begin_define
define|#
directive|define
name|PHY_M_POLC_LS1_P_MIX
parameter_list|(
name|x
parameter_list|)
value|(SHIFT12(x)& PHY_M_POLC_LS1M_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_POLC_IS0_P_MIX
parameter_list|(
name|x
parameter_list|)
value|(SHIFT8(x)& PHY_M_POLC_IS0M_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_POLC_LOS_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT6(x)& PHY_M_POLC_LOS_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_POLC_INIT_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT4(x)& PHY_M_POLC_INIT_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_POLC_STA1_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT2(x)& PHY_M_POLC_STA1_MSK)
end_define

begin_define
define|#
directive|define
name|PHY_M_POLC_STA0_CTRL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT0(x)& PHY_M_POLC_STA0_MSK)
end_define

begin_comment
comment|/*  * GMAC registers  *  * The GMAC registers are 16 or 32 bits wide.  * The GMACs host processor interface is 16 bits wide,  * therefore ALL registers will be addressed with 16 bit accesses.  *  * Note:	NA reg	= Network Address e.g DA, SA etc.  */
end_comment

begin_comment
comment|/* Port Registers */
end_comment

begin_define
define|#
directive|define
name|GM_GP_STAT
value|0x0000
end_define

begin_comment
comment|/* 16 bit r/o	General Purpose Status */
end_comment

begin_define
define|#
directive|define
name|GM_GP_CTRL
value|0x0004
end_define

begin_comment
comment|/* 16 bit r/w	General Purpose Control */
end_comment

begin_define
define|#
directive|define
name|GM_TX_CTRL
value|0x0008
end_define

begin_comment
comment|/* 16 bit r/w	Transmit Control Reg. */
end_comment

begin_define
define|#
directive|define
name|GM_RX_CTRL
value|0x000c
end_define

begin_comment
comment|/* 16 bit r/w	Receive Control Reg. */
end_comment

begin_define
define|#
directive|define
name|GM_TX_FLOW_CTRL
value|0x0010
end_define

begin_comment
comment|/* 16 bit r/w	Transmit Flow-Control */
end_comment

begin_define
define|#
directive|define
name|GM_TX_PARAM
value|0x0014
end_define

begin_comment
comment|/* 16 bit r/w	Transmit Parameter Reg. */
end_comment

begin_define
define|#
directive|define
name|GM_SERIAL_MODE
value|0x0018
end_define

begin_comment
comment|/* 16 bit r/w	Serial Mode Register */
end_comment

begin_comment
comment|/* Source Address Registers */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_1L
value|0x001c
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 1 (low) */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_1M
value|0x0020
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 1 (middle) */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_1H
value|0x0024
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 1 (high) */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_2L
value|0x0028
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 2 (low) */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_2M
value|0x002c
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 2 (middle) */
end_comment

begin_define
define|#
directive|define
name|GM_SRC_ADDR_2H
value|0x0030
end_define

begin_comment
comment|/* 16 bit r/w	Source Address 2 (high) */
end_comment

begin_comment
comment|/* Multicast Address Hash Registers */
end_comment

begin_define
define|#
directive|define
name|GM_MC_ADDR_H1
value|0x0034
end_define

begin_comment
comment|/* 16 bit r/w	Multicast Address Hash 1 */
end_comment

begin_define
define|#
directive|define
name|GM_MC_ADDR_H2
value|0x0038
end_define

begin_comment
comment|/* 16 bit r/w	Multicast Address Hash 2 */
end_comment

begin_define
define|#
directive|define
name|GM_MC_ADDR_H3
value|0x003c
end_define

begin_comment
comment|/* 16 bit r/w	Multicast Address Hash 3 */
end_comment

begin_define
define|#
directive|define
name|GM_MC_ADDR_H4
value|0x0040
end_define

begin_comment
comment|/* 16 bit r/w	Multicast Address Hash 4 */
end_comment

begin_comment
comment|/* Interrupt Source Registers */
end_comment

begin_define
define|#
directive|define
name|GM_TX_IRQ_SRC
value|0x0044
end_define

begin_comment
comment|/* 16 bit r/o	Tx Overflow IRQ Source */
end_comment

begin_define
define|#
directive|define
name|GM_RX_IRQ_SRC
value|0x0048
end_define

begin_comment
comment|/* 16 bit r/o	Rx Overflow IRQ Source */
end_comment

begin_define
define|#
directive|define
name|GM_TR_IRQ_SRC
value|0x004c
end_define

begin_comment
comment|/* 16 bit r/o	Tx/Rx Over. IRQ Source */
end_comment

begin_comment
comment|/* Interrupt Mask Registers */
end_comment

begin_define
define|#
directive|define
name|GM_TX_IRQ_MSK
value|0x0050
end_define

begin_comment
comment|/* 16 bit r/w	Tx Overflow IRQ Mask */
end_comment

begin_define
define|#
directive|define
name|GM_RX_IRQ_MSK
value|0x0054
end_define

begin_comment
comment|/* 16 bit r/w	Rx Overflow IRQ Mask */
end_comment

begin_define
define|#
directive|define
name|GM_TR_IRQ_MSK
value|0x0058
end_define

begin_comment
comment|/* 16 bit r/w	Tx/Rx Over. IRQ Mask */
end_comment

begin_comment
comment|/* Serial Management Interface (SMI) Registers */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CTRL
value|0x0080
end_define

begin_comment
comment|/* 16 bit r/w	SMI Control Register */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_DATA
value|0x0084
end_define

begin_comment
comment|/* 16 bit r/w	SMI Data Register */
end_comment

begin_define
define|#
directive|define
name|GM_PHY_ADDR
value|0x0088
end_define

begin_comment
comment|/* 16 bit r/w	GPHY Address Register */
end_comment

begin_comment
comment|/* MIB Counters */
end_comment

begin_define
define|#
directive|define
name|GM_MIB_CNT_BASE
value|0x0100
end_define

begin_comment
comment|/* Base Address of MIB Counters */
end_comment

begin_define
define|#
directive|define
name|GM_MIB_CNT_SIZE
value|44
end_define

begin_comment
comment|/* Number of MIB Counters */
end_comment

begin_comment
comment|/*  * MIB Counters base address definitions (low word) -  * use offset 4 for access to high word	(32 bit r/o)  */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_UC_OK
define|\
value|(GM_MIB_CNT_BASE + 0)
end_define

begin_comment
comment|/* Unicast Frames Received OK */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_BC_OK
define|\
value|(GM_MIB_CNT_BASE + 8)
end_define

begin_comment
comment|/* Broadcast Frames Received OK */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_MPAUSE
define|\
value|(GM_MIB_CNT_BASE + 16)
end_define

begin_comment
comment|/* Pause MAC Ctrl Frames Received */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_MC_OK
define|\
value|(GM_MIB_CNT_BASE + 24)
end_define

begin_comment
comment|/* Multicast Frames Received OK */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_FCS_ERR
define|\
value|(GM_MIB_CNT_BASE + 32)
end_define

begin_comment
comment|/* Rx Frame Check Seq. Error */
end_comment

begin_define
define|#
directive|define
name|GM_RXO_OK_LO
define|\
value|(GM_MIB_CNT_BASE + 48)
end_define

begin_comment
comment|/* Octets Received OK Low */
end_comment

begin_define
define|#
directive|define
name|GM_RXO_OK_HI
define|\
value|(GM_MIB_CNT_BASE + 56)
end_define

begin_comment
comment|/* Octets Received OK High */
end_comment

begin_define
define|#
directive|define
name|GM_RXO_ERR_LO
define|\
value|(GM_MIB_CNT_BASE + 64)
end_define

begin_comment
comment|/* Octets Received Invalid Low */
end_comment

begin_define
define|#
directive|define
name|GM_RXO_ERR_HI
define|\
value|(GM_MIB_CNT_BASE + 72)
end_define

begin_comment
comment|/* Octets Received Invalid High */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_SHT
define|\
value|(GM_MIB_CNT_BASE + 80)
end_define

begin_comment
comment|/* Frames<64 Byte Received OK */
end_comment

begin_define
define|#
directive|define
name|GM_RXE_FRAG
define|\
value|(GM_MIB_CNT_BASE + 88)
end_define

begin_comment
comment|/* Frames<64 Byte Received with FCS Err */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_64B
define|\
value|(GM_MIB_CNT_BASE + 96)
end_define

begin_comment
comment|/* 64 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_127B
define|\
value|(GM_MIB_CNT_BASE + 104)
end_define

begin_comment
comment|/* 65-127 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_255B
define|\
value|(GM_MIB_CNT_BASE + 112)
end_define

begin_comment
comment|/* 128-255 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_511B
define|\
value|(GM_MIB_CNT_BASE + 120)
end_define

begin_comment
comment|/* 256-511 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_1023B
define|\
value|(GM_MIB_CNT_BASE + 128)
end_define

begin_comment
comment|/* 512-1023 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_1518B
define|\
value|(GM_MIB_CNT_BASE + 136)
end_define

begin_comment
comment|/* 1024-1518 Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_MAX_SZ
define|\
value|(GM_MIB_CNT_BASE + 144)
end_define

begin_comment
comment|/* 1519-MaxSize Byte Rx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_LNG_ERR
define|\
value|(GM_MIB_CNT_BASE + 152)
end_define

begin_comment
comment|/* Rx Frame too Long Error */
end_comment

begin_define
define|#
directive|define
name|GM_RXF_JAB_PKT
define|\
value|(GM_MIB_CNT_BASE + 160)
end_define

begin_comment
comment|/* Rx Jabber Packet Frame */
end_comment

begin_define
define|#
directive|define
name|GM_RXE_FIFO_OV
define|\
value|(GM_MIB_CNT_BASE + 176)
end_define

begin_comment
comment|/* Rx FIFO overflow Event */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_UC_OK
define|\
value|(GM_MIB_CNT_BASE + 192)
end_define

begin_comment
comment|/* Unicast Frames Xmitted OK */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_BC_OK
define|\
value|(GM_MIB_CNT_BASE + 200)
end_define

begin_comment
comment|/* Broadcast Frames Xmitted OK */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_MPAUSE
define|\
value|(GM_MIB_CNT_BASE + 208)
end_define

begin_comment
comment|/* Pause MAC Ctrl Frames Xmitted */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_MC_OK
define|\
value|(GM_MIB_CNT_BASE + 216)
end_define

begin_comment
comment|/* Multicast Frames Xmitted OK */
end_comment

begin_define
define|#
directive|define
name|GM_TXO_OK_LO
define|\
value|(GM_MIB_CNT_BASE + 224)
end_define

begin_comment
comment|/* Octets Transmitted OK Low */
end_comment

begin_define
define|#
directive|define
name|GM_TXO_OK_HI
define|\
value|(GM_MIB_CNT_BASE + 232)
end_define

begin_comment
comment|/* Octets Transmitted OK High */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_64B
define|\
value|(GM_MIB_CNT_BASE + 240)
end_define

begin_comment
comment|/* 64 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_127B
define|\
value|(GM_MIB_CNT_BASE + 248)
end_define

begin_comment
comment|/* 65-127 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_255B
define|\
value|(GM_MIB_CNT_BASE + 256)
end_define

begin_comment
comment|/* 128-255 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_511B
define|\
value|(GM_MIB_CNT_BASE + 264)
end_define

begin_comment
comment|/* 256-511 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_1023B
define|\
value|(GM_MIB_CNT_BASE + 272)
end_define

begin_comment
comment|/* 512-1023 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_1518B
define|\
value|(GM_MIB_CNT_BASE + 280)
end_define

begin_comment
comment|/* 1024-1518 Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_MAX_SZ
define|\
value|(GM_MIB_CNT_BASE + 288)
end_define

begin_comment
comment|/* 1519-MaxSize Byte Tx Frame */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_COL
define|\
value|(GM_MIB_CNT_BASE + 304)
end_define

begin_comment
comment|/* Tx Collision */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_LAT_COL
define|\
value|(GM_MIB_CNT_BASE + 312)
end_define

begin_comment
comment|/* Tx Late Collision */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_ABO_COL
define|\
value|(GM_MIB_CNT_BASE + 320)
end_define

begin_comment
comment|/* Tx aborted due to Exces. Col. */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_MUL_COL
define|\
value|(GM_MIB_CNT_BASE + 328)
end_define

begin_comment
comment|/* Tx Multiple Collision */
end_comment

begin_define
define|#
directive|define
name|GM_TXF_SNG_COL
define|\
value|(GM_MIB_CNT_BASE + 336)
end_define

begin_comment
comment|/* Tx Single Collision */
end_comment

begin_define
define|#
directive|define
name|GM_TXE_FIFO_UR
define|\
value|(GM_MIB_CNT_BASE + 344)
end_define

begin_comment
comment|/* Tx FIFO Underrun Event */
end_comment

begin_comment
comment|/*----------------------------------------------------------------------------*/
end_comment

begin_comment
comment|/*  * GMAC Bit Definitions  *  * If the bit access behaviour differs from the register access behaviour  * (r/w, r/o) this is documented after the bit number.  * The following bit access behaviours are used:  *	(sc)	self clearing  *	(r/o)	read only  */
end_comment

begin_comment
comment|/*	GM_GP_STAT	16 bit r/o	General Purpose Status Register */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_SPEED
value|BIT_15
end_define

begin_comment
comment|/* Port Speed (1 = 100 Mbps) */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_DUPLEX
value|BIT_14
end_define

begin_comment
comment|/* Duplex Mode (1 = Full) */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_FC_TX_DIS
value|BIT_13
end_define

begin_comment
comment|/* Tx Flow-Control Mode Disabled */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_LINK_UP
value|BIT_12
end_define

begin_comment
comment|/* Link Up Status */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_PAUSE
value|BIT_11
end_define

begin_comment
comment|/* Pause State */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_TX_ACTIVE
value|BIT_10
end_define

begin_comment
comment|/* Tx in Progress */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_EXC_COL
value|BIT_9
end_define

begin_comment
comment|/* Excessive Collisions Occured */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_LAT_COL
value|BIT_8
end_define

begin_comment
comment|/* Late Collisions Occured */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_PHY_ST_CH
value|BIT_5
end_define

begin_comment
comment|/* PHY Status Change */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_GIG_SPEED
value|BIT_4
end_define

begin_comment
comment|/* Gigabit Speed (1 = 1000 Mbps) */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_PART_MODE
value|BIT_3
end_define

begin_comment
comment|/* Partition mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPSR_FC_RX_DIS
value|BIT_2
end_define

begin_comment
comment|/* Rx Flow-Control Mode Disabled */
end_comment

begin_comment
comment|/*	GM_GP_CTRL	16 bit r/w	General Purpose Control Register */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_RMII_PH_ENA
value|BIT_15
end_define

begin_comment
comment|/* Enable RMII for PHY (Yukon-FE only) */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_RMII_LB_ENA
value|BIT_14
end_define

begin_comment
comment|/* Enable RMII Loopback (Yukon-FE only) */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_FC_TX_DIS
value|BIT_13
end_define

begin_comment
comment|/* Disable Tx Flow-Control Mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_TX_ENA
value|BIT_12
end_define

begin_comment
comment|/* Enable Transmit */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_RX_ENA
value|BIT_11
end_define

begin_comment
comment|/* Enable Receive */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_LOOP_ENA
value|BIT_9
end_define

begin_comment
comment|/* Enable MAC Loopback Mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_PART_ENA
value|BIT_8
end_define

begin_comment
comment|/* Enable Partition Mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_GIGS_ENA
value|BIT_7
end_define

begin_comment
comment|/* Gigabit Speed (1000 Mbps) */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_FL_PASS
value|BIT_6
end_define

begin_comment
comment|/* Force Link Pass */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_DUP_FULL
value|BIT_5
end_define

begin_comment
comment|/* Full Duplex Mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_FC_RX_DIS
value|BIT_4
end_define

begin_comment
comment|/* Disable Rx Flow-Control Mode */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_SPEED_100
value|BIT_3
end_define

begin_comment
comment|/* Port Speed 100 Mbps */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_AU_DUP_DIS
value|BIT_2
end_define

begin_comment
comment|/* Disable Auto-Update Duplex */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_AU_FCT_DIS
value|BIT_1
end_define

begin_comment
comment|/* Disable Auto-Update Flow-C. */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_AU_SPD_DIS
value|BIT_0
end_define

begin_comment
comment|/* Disable Auto-Update Speed */
end_comment

begin_define
define|#
directive|define
name|GM_GPCR_SPEED_1000
value|(GM_GPCR_GIGS_ENA | GM_GPCR_SPEED_100)
end_define

begin_define
define|#
directive|define
name|GM_GPCR_AU_ALL_DIS
value|(GM_GPCR_AU_DUP_DIS | GM_GPCR_AU_FCT_DIS |\ 				 GM_GPCR_AU_SPD_DIS)
end_define

begin_comment
comment|/*	GM_TX_CTRL	16 bit r/w	Transmit Control Register */
end_comment

begin_define
define|#
directive|define
name|GM_TXCR_FORCE_JAM
value|BIT_15
end_define

begin_comment
comment|/* Force Jam / Flow-Control */
end_comment

begin_define
define|#
directive|define
name|GM_TXCR_CRC_DIS
value|BIT_14
end_define

begin_comment
comment|/* Disable insertion of CRC */
end_comment

begin_define
define|#
directive|define
name|GM_TXCR_PAD_DIS
value|BIT_13
end_define

begin_comment
comment|/* Disable padding of packets */
end_comment

begin_define
define|#
directive|define
name|GM_TXCR_COL_THR_MSK
value|(7<<10)
end_define

begin_comment
comment|/* Bit 12..10: Collision Threshold Mask */
end_comment

begin_define
define|#
directive|define
name|GM_TXCR_PAD_PAT_MSK
value|0xff
end_define

begin_comment
comment|/* Bit  7.. 0: Padding Pattern Mask */
end_comment

begin_comment
comment|/* (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|TX_COL_THR
parameter_list|(
name|x
parameter_list|)
value|(SHIFT10(x)& GM_TXCR_COL_THR_MSK)
end_define

begin_define
define|#
directive|define
name|TX_COL_DEF
value|0x04
end_define

begin_comment
comment|/*	GM_RX_CTRL	16 bit r/w	Receive Control Register */
end_comment

begin_define
define|#
directive|define
name|GM_RXCR_UCF_ENA
value|BIT_15
end_define

begin_comment
comment|/* Enable Unicast filtering */
end_comment

begin_define
define|#
directive|define
name|GM_RXCR_MCF_ENA
value|BIT_14
end_define

begin_comment
comment|/* Enable Multicast filtering */
end_comment

begin_define
define|#
directive|define
name|GM_RXCR_CRC_DIS
value|BIT_13
end_define

begin_comment
comment|/* Remove 4-byte CRC */
end_comment

begin_define
define|#
directive|define
name|GM_RXCR_PASS_FC
value|BIT_12
end_define

begin_comment
comment|/* Pass FC packets to FIFO (Yukon-1 only) */
end_comment

begin_comment
comment|/*	GM_TX_PARAM	16 bit r/w	Transmit Parameter Register */
end_comment

begin_define
define|#
directive|define
name|GM_TXPA_JAMLEN_MSK
value|(3<<14)
end_define

begin_comment
comment|/* Bit 15..14: Jam Length Mask */
end_comment

begin_define
define|#
directive|define
name|GM_TXPA_JAMIPG_MSK
value|(0x1f<<9)
end_define

begin_comment
comment|/* Bit 13.. 9: Jam IPG Mask */
end_comment

begin_define
define|#
directive|define
name|GM_TXPA_JAMDAT_MSK
value|(0x1f<<4)
end_define

begin_comment
comment|/* Bit  8.. 4: IPG Jam to Data Mask */
end_comment

begin_define
define|#
directive|define
name|GM_TXPA_BO_LIM_MSK
value|0x0f
end_define

begin_comment
comment|/* Bit  3.. 0: Backoff Limit Mask */
end_comment

begin_comment
comment|/* (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|TX_JAM_LEN_VAL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT14(x)& GM_TXPA_JAMLEN_MSK)
end_define

begin_define
define|#
directive|define
name|TX_JAM_IPG_VAL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT9(x)& GM_TXPA_JAMIPG_MSK)
end_define

begin_define
define|#
directive|define
name|TX_IPG_JAM_DATA
parameter_list|(
name|x
parameter_list|)
value|(SHIFT4(x)& GM_TXPA_JAMDAT_MSK)
end_define

begin_define
define|#
directive|define
name|TX_BACK_OFF_LIM
parameter_list|(
name|x
parameter_list|)
value|((x)& GM_TXPA_BO_LIM_MSK)
end_define

begin_define
define|#
directive|define
name|TX_JAM_LEN_DEF
value|0x03
end_define

begin_define
define|#
directive|define
name|TX_JAM_IPG_DEF
value|0x0b
end_define

begin_define
define|#
directive|define
name|TX_IPG_JAM_DEF
value|0x1c
end_define

begin_define
define|#
directive|define
name|TX_BOF_LIM_DEF
value|0x04
end_define

begin_comment
comment|/*	GM_SERIAL_MODE	16 bit r/w	Serial Mode Register */
end_comment

begin_define
define|#
directive|define
name|GM_SMOD_DATABL_MSK
value|(0x1f<<11)
end_define

begin_comment
comment|/* Bit 15..11:	Data Blinder */
end_comment

begin_comment
comment|/* r/o on Yukon, r/w on Yukon-EC */
end_comment

begin_define
define|#
directive|define
name|GM_SMOD_LIMIT_4
value|BIT_10
end_define

begin_comment
comment|/* 4 consecutive Tx trials */
end_comment

begin_define
define|#
directive|define
name|GM_SMOD_VLAN_ENA
value|BIT_9
end_define

begin_comment
comment|/* Enable VLAN  (Max. Frame Len) */
end_comment

begin_define
define|#
directive|define
name|GM_SMOD_JUMBO_ENA
value|BIT_8
end_define

begin_comment
comment|/* Enable Jumbo (Max. Frame Len) */
end_comment

begin_define
define|#
directive|define
name|GM_SMOD_IPG_MSK
value|0x1f
end_define

begin_comment
comment|/* Bit  4.. 0:	Inter-Packet Gap (IPG) */
end_comment

begin_define
define|#
directive|define
name|DATA_BLIND_VAL
parameter_list|(
name|x
parameter_list|)
value|(SHIFT11(x)& GM_SMOD_DATABL_MSK)
end_define

begin_define
define|#
directive|define
name|IPG_DATA_VAL
parameter_list|(
name|x
parameter_list|)
value|((x)& GM_SMOD_IPG_MSK)
end_define

begin_define
define|#
directive|define
name|DATA_BLIND_DEF
value|0x04
end_define

begin_define
define|#
directive|define
name|IPG_DATA_DEF
value|0x1e
end_define

begin_comment
comment|/*	GM_SMI_CTRL	16 bit r/w	SMI Control Register */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_PHY_A_MSK
value|(0x1f<<11)
end_define

begin_comment
comment|/* Bit 15..11:	PHY Device Address */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_REG_A_MSK
value|(0x1f<<6)
end_define

begin_comment
comment|/* Bit 10.. 6:	PHY Register Address */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_OP_RD
value|BIT_5
end_define

begin_comment
comment|/* OpCode Read (0=Write)*/
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_RD_VAL
value|BIT_4
end_define

begin_comment
comment|/* Read Valid (Read completed) */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_BUSY
value|BIT_3
end_define

begin_comment
comment|/* Busy (Operation in progress) */
end_comment

begin_define
define|#
directive|define
name|GM_SMI_CT_PHY_AD
parameter_list|(
name|x
parameter_list|)
value|(SHIFT11(x)& GM_SMI_CT_PHY_A_MSK)
end_define

begin_define
define|#
directive|define
name|GM_SMI_CT_REG_AD
parameter_list|(
name|x
parameter_list|)
value|(SHIFT6(x)& GM_SMI_CT_REG_A_MSK)
end_define

begin_comment
comment|/*	GM_PHY_ADDR	16 bit r/w	GPHY Address Register */
end_comment

begin_define
define|#
directive|define
name|GM_PAR_MIB_CLR
value|BIT_5
end_define

begin_comment
comment|/* Set MIB Clear Counter Mode */
end_comment

begin_define
define|#
directive|define
name|GM_PAR_MIB_TST
value|BIT_4
end_define

begin_comment
comment|/* MIB Load Counter (Test Mode) */
end_comment

begin_comment
comment|/* Receive Frame Status Encoding */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_LEN_MSK
value|(0xffff<<16)
end_define

begin_comment
comment|/* Bit 31..16:	Rx Frame Length */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_VLAN
value|BIT_13
end_define

begin_comment
comment|/* VLAN Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_JABBER
value|BIT_12
end_define

begin_comment
comment|/* Jabber Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_UN_SIZE
value|BIT_11
end_define

begin_comment
comment|/* Undersize Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_MC
value|BIT_10
end_define

begin_comment
comment|/* Multicast Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_BC
value|BIT_9
end_define

begin_comment
comment|/* Broadcast Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_RX_OK
value|BIT_8
end_define

begin_comment
comment|/* Receive OK (Good Packet) */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_GOOD_FC
value|BIT_7
end_define

begin_comment
comment|/* Good Flow-Control Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_BAD_FC
value|BIT_6
end_define

begin_comment
comment|/* Bad  Flow-Control Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_MII_ERR
value|BIT_5
end_define

begin_comment
comment|/* MII Error */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_LONG_ERR
value|BIT_4
end_define

begin_comment
comment|/* Too Long Packet */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_FRAGMENT
value|BIT_3
end_define

begin_comment
comment|/* Fragment */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_CRC_ERR
value|BIT_1
end_define

begin_comment
comment|/* CRC Error */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_RX_FF_OV
value|BIT_0
end_define

begin_comment
comment|/* Rx FIFO Overflow */
end_comment

begin_define
define|#
directive|define
name|GMR_FS_LEN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GMR_FS_ANY_ERR
value|( \ 			GMR_FS_RX_FF_OV | \ 			GMR_FS_CRC_ERR | \ 			GMR_FS_FRAGMENT | \ 			GMR_FS_LONG_ERR | \ 			GMR_FS_MII_ERR | \ 			GMR_FS_BAD_FC | \ 			GMR_FS_UN_SIZE | \ 			GMR_FS_JABBER)
end_define

begin_comment
comment|/* Rx GMAC FIFO Flush Mask (default) */
end_comment

begin_define
define|#
directive|define
name|RX_FF_FL_DEF_MSK
value|GMR_FS_ANY_ERR
end_define

begin_comment
comment|/*	Receive and Transmit GMAC FIFO Registers (YUKON only) */
end_comment

begin_comment
comment|/*	RX_GMF_EA	32 bit	Rx GMAC FIFO End Address */
end_comment

begin_comment
comment|/*	RX_GMF_AF_THR	32 bit	Rx GMAC FIFO Almost Full Thresh. */
end_comment

begin_comment
comment|/*	RX_GMF_WP	32 bit	Rx GMAC FIFO Write Pointer */
end_comment

begin_comment
comment|/*	RX_GMF_WLEV	32 bit	Rx GMAC FIFO Write Level */
end_comment

begin_comment
comment|/*	RX_GMF_RP	32 bit	Rx GMAC FIFO Read Pointer */
end_comment

begin_comment
comment|/*	RX_GMF_RLEV	32 bit	Rx GMAC FIFO Read Level */
end_comment

begin_comment
comment|/*	TX_GMF_EA	32 bit	Tx GMAC FIFO End Address */
end_comment

begin_comment
comment|/*	TX_GMF_AE_THR	32 bit	Tx GMAC FIFO Almost Empty Thresh.*/
end_comment

begin_comment
comment|/*	TX_GMF_WP	32 bit	Tx GMAC FIFO Write Pointer */
end_comment

begin_comment
comment|/*	TX_GMF_WSP	32 bit	Tx GMAC FIFO Write Shadow Pointer */
end_comment

begin_comment
comment|/*	TX_GMF_WLEV	32 bit	Tx GMAC FIFO Write Level */
end_comment

begin_comment
comment|/*	TX_GMF_RP	32 bit	Tx GMAC FIFO Read Pointer */
end_comment

begin_comment
comment|/*	TX_GMF_RSTP	32 bit	Tx GMAC FIFO Restart Pointer */
end_comment

begin_comment
comment|/*	TX_GMF_RLEV	32 bit	Tx GMAC FIFO Read Level */
end_comment

begin_comment
comment|/*	RX_GMF_CTRL_T	32 bit	Rx GMAC FIFO Control/Test */
end_comment

begin_define
define|#
directive|define
name|RX_TRUNC_ON
value|BIT_27
end_define

begin_comment
comment|/* enable  packet truncation */
end_comment

begin_define
define|#
directive|define
name|RX_TRUNC_OFF
value|BIT_26
end_define

begin_comment
comment|/* disable packet truncation */
end_comment

begin_define
define|#
directive|define
name|RX_VLAN_STRIP_ON
value|BIT_25
end_define

begin_comment
comment|/* enable  VLAN stripping */
end_comment

begin_define
define|#
directive|define
name|RX_VLAN_STRIP_OFF
value|BIT_24
end_define

begin_comment
comment|/* disable VLAN stripping */
end_comment

begin_define
define|#
directive|define
name|GMF_WP_TST_ON
value|BIT_14
end_define

begin_comment
comment|/* Write Pointer Test On */
end_comment

begin_define
define|#
directive|define
name|GMF_WP_TST_OFF
value|BIT_13
end_define

begin_comment
comment|/* Write Pointer Test Off */
end_comment

begin_define
define|#
directive|define
name|GMF_WP_STEP
value|BIT_12
end_define

begin_comment
comment|/* Write Pointer Step/Increment */
end_comment

begin_define
define|#
directive|define
name|GMF_RP_TST_ON
value|BIT_10
end_define

begin_comment
comment|/* Read Pointer Test On */
end_comment

begin_define
define|#
directive|define
name|GMF_RP_TST_OFF
value|BIT_9
end_define

begin_comment
comment|/* Read Pointer Test Off */
end_comment

begin_define
define|#
directive|define
name|GMF_RP_STEP
value|BIT_8
end_define

begin_comment
comment|/* Read Pointer Step/Increment */
end_comment

begin_define
define|#
directive|define
name|GMF_RX_F_FL_ON
value|BIT_7
end_define

begin_comment
comment|/* Rx FIFO Flush Mode On */
end_comment

begin_define
define|#
directive|define
name|GMF_RX_F_FL_OFF
value|BIT_6
end_define

begin_comment
comment|/* Rx FIFO Flush Mode Off */
end_comment

begin_define
define|#
directive|define
name|GMF_CLI_RX_FO
value|BIT_5
end_define

begin_comment
comment|/* Clear IRQ Rx FIFO Overrun */
end_comment

begin_define
define|#
directive|define
name|GMF_CLI_RX_FC
value|BIT_4
end_define

begin_comment
comment|/* Clear IRQ Rx Frame Complete */
end_comment

begin_define
define|#
directive|define
name|GMF_OPER_ON
value|BIT_3
end_define

begin_comment
comment|/* Operational Mode On */
end_comment

begin_define
define|#
directive|define
name|GMF_OPER_OFF
value|BIT_2
end_define

begin_comment
comment|/* Operational Mode Off */
end_comment

begin_define
define|#
directive|define
name|GMF_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear GMAC FIFO Reset */
end_comment

begin_define
define|#
directive|define
name|GMF_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   GMAC FIFO Reset */
end_comment

begin_comment
comment|/*	TX_GMF_CTRL_T	32 bit	Tx GMAC FIFO Control/Test (YUKON and Yukon-2) */
end_comment

begin_define
define|#
directive|define
name|TX_STFW_DIS
value|BIT_31
end_define

begin_comment
comment|/* Disable Store& Forward (Yukon-EC Ultra) */
end_comment

begin_define
define|#
directive|define
name|TX_STFW_ENA
value|BIT_30
end_define

begin_comment
comment|/* Enable Store& Forward (Yukon-EC Ultra) */
end_comment

begin_define
define|#
directive|define
name|TX_VLAN_TAG_ON
value|BIT_25
end_define

begin_comment
comment|/* enable  VLAN tagging */
end_comment

begin_define
define|#
directive|define
name|TX_VLAN_TAG_OFF
value|BIT_24
end_define

begin_comment
comment|/* disable VLAN tagging */
end_comment

begin_define
define|#
directive|define
name|GMF_WSP_TST_ON
value|BIT_18
end_define

begin_comment
comment|/* Write Shadow Pointer Test On */
end_comment

begin_define
define|#
directive|define
name|GMF_WSP_TST_OFF
value|BIT_17
end_define

begin_comment
comment|/* Write Shadow Pointer Test Off */
end_comment

begin_define
define|#
directive|define
name|GMF_WSP_STEP
value|BIT_16
end_define

begin_comment
comment|/* Write Shadow Pointer Step/Increment */
end_comment

begin_comment
comment|/* Bits 15..8: same as for RX_GMF_CTRL_T */
end_comment

begin_define
define|#
directive|define
name|GMF_CLI_TX_FU
value|BIT_6
end_define

begin_comment
comment|/* Clear IRQ Tx FIFO Underrun */
end_comment

begin_define
define|#
directive|define
name|GMF_CLI_TX_FC
value|BIT_5
end_define

begin_comment
comment|/* Clear IRQ Tx Frame Complete */
end_comment

begin_define
define|#
directive|define
name|GMF_CLI_TX_PE
value|BIT_4
end_define

begin_comment
comment|/* Clear IRQ Tx Parity Error */
end_comment

begin_comment
comment|/* Bits 3..0: same as for RX_GMF_CTRL_T */
end_comment

begin_define
define|#
directive|define
name|GMF_RX_CTRL_DEF
value|(GMF_OPER_ON | GMF_RX_F_FL_ON)
end_define

begin_define
define|#
directive|define
name|GMF_TX_CTRL_DEF
value|GMF_OPER_ON
end_define

begin_define
define|#
directive|define
name|RX_GMF_AF_THR_MIN
value|0x0c
end_define

begin_comment
comment|/* Rx GMAC FIFO Almost Full Thresh. min. */
end_comment

begin_define
define|#
directive|define
name|RX_GMF_FL_THR_DEF
value|0x0a
end_define

begin_comment
comment|/* Rx GMAC FIFO Flush Threshold default */
end_comment

begin_comment
comment|/*	GMAC_TI_ST_CTRL	 8 bit	Time Stamp Timer Ctrl Reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GMT_ST_START
value|BIT_2
end_define

begin_comment
comment|/* Start Time Stamp Timer */
end_comment

begin_define
define|#
directive|define
name|GMT_ST_STOP
value|BIT_1
end_define

begin_comment
comment|/* Stop  Time Stamp Timer */
end_comment

begin_define
define|#
directive|define
name|GMT_ST_CLR_IRQ
value|BIT_0
end_define

begin_comment
comment|/* Clear Time Stamp Timer IRQ */
end_comment

begin_comment
comment|/*	POLL_CTRL	32 bit	Polling Unit control register (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|PC_CLR_IRQ_CHK
value|BIT_5
end_define

begin_comment
comment|/* Clear IRQ Check */
end_comment

begin_define
define|#
directive|define
name|PC_POLL_RQ
value|BIT_4
end_define

begin_comment
comment|/* Poll Request Start */
end_comment

begin_define
define|#
directive|define
name|PC_POLL_OP_ON
value|BIT_3
end_define

begin_comment
comment|/* Operational Mode On */
end_comment

begin_define
define|#
directive|define
name|PC_POLL_OP_OFF
value|BIT_2
end_define

begin_comment
comment|/* Operational Mode Off */
end_comment

begin_define
define|#
directive|define
name|PC_POLL_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear Polling Unit Reset (Enable) */
end_comment

begin_define
define|#
directive|define
name|PC_POLL_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   Polling Unit Reset */
end_comment

begin_comment
comment|/* B28_Y2_ASF_STAT_CMD		32 bit	ASF Status and Command Reg */
end_comment

begin_comment
comment|/* This register is used by the host driver software */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_OS_PRES
value|BIT_4
end_define

begin_comment
comment|/* ASF operation system present */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_RESET
value|BIT_3
end_define

begin_comment
comment|/* ASF system in reset state */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_RUNNING
value|BIT_2
end_define

begin_comment
comment|/* ASF system operational */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_CLR_HSTI
value|BIT_1
end_define

begin_comment
comment|/* Clear ASF IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_IRQ
value|BIT_0
end_define

begin_comment
comment|/* Issue an IRQ to ASF system */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_UC_STATE
value|(3<<2)
end_define

begin_comment
comment|/* ASF uC State */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_CLK_HALT
value|0
end_define

begin_comment
comment|/* ASF system clock stopped */
end_comment

begin_comment
comment|/* B28_Y2_ASF_HOST_COM	32 bit	ASF Host Communication Reg */
end_comment

begin_comment
comment|/* This register is used by the ASF firmware */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_CLR_ASFI
value|BIT_1
end_define

begin_comment
comment|/* Clear host IRQ */
end_comment

begin_define
define|#
directive|define
name|Y2_ASF_HOST_IRQ
value|BIT_0
end_define

begin_comment
comment|/* Issue an IRQ to HOST system */
end_comment

begin_comment
comment|/*	STAT_CTRL	32 bit	Status BMU control register (Yukon-2 only) */
end_comment

begin_define
define|#
directive|define
name|SC_STAT_CLR_IRQ
value|BIT_4
end_define

begin_comment
comment|/* Status Burst IRQ clear */
end_comment

begin_define
define|#
directive|define
name|SC_STAT_OP_ON
value|BIT_3
end_define

begin_comment
comment|/* Operational Mode On */
end_comment

begin_define
define|#
directive|define
name|SC_STAT_OP_OFF
value|BIT_2
end_define

begin_comment
comment|/* Operational Mode Off */
end_comment

begin_define
define|#
directive|define
name|SC_STAT_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear Status Unit Reset (Enable) */
end_comment

begin_define
define|#
directive|define
name|SC_STAT_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   Status Unit Reset */
end_comment

begin_comment
comment|/*	GMAC_CTRL	32 bit	GMAC Control Reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GMC_H_BURST_ON
value|BIT_7
end_define

begin_comment
comment|/* Half Duplex Burst Mode On */
end_comment

begin_define
define|#
directive|define
name|GMC_H_BURST_OFF
value|BIT_6
end_define

begin_comment
comment|/* Half Duplex Burst Mode Off */
end_comment

begin_define
define|#
directive|define
name|GMC_F_LOOPB_ON
value|BIT_5
end_define

begin_comment
comment|/* FIFO Loopback On */
end_comment

begin_define
define|#
directive|define
name|GMC_F_LOOPB_OFF
value|BIT_4
end_define

begin_comment
comment|/* FIFO Loopback Off */
end_comment

begin_define
define|#
directive|define
name|GMC_PAUSE_ON
value|BIT_3
end_define

begin_comment
comment|/* Pause On */
end_comment

begin_define
define|#
directive|define
name|GMC_PAUSE_OFF
value|BIT_2
end_define

begin_comment
comment|/* Pause Off */
end_comment

begin_define
define|#
directive|define
name|GMC_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear GMAC Reset */
end_comment

begin_define
define|#
directive|define
name|GMC_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   GMAC Reset */
end_comment

begin_comment
comment|/*	GPHY_CTRL	32 bit	GPHY Control Reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GPC_SEL_BDT
value|BIT_28
end_define

begin_comment
comment|/* Select Bi-Dir. Transfer for MDC/MDIO */
end_comment

begin_define
define|#
directive|define
name|GPC_INT_POL
value|BIT_27
end_define

begin_comment
comment|/* IRQ Polarity is Active Low */
end_comment

begin_define
define|#
directive|define
name|GPC_75_OHM
value|BIT_26
end_define

begin_comment
comment|/* Use 75 Ohm Termination instead of 50 */
end_comment

begin_define
define|#
directive|define
name|GPC_DIS_FC
value|BIT_25
end_define

begin_comment
comment|/* Disable Automatic Fiber/Copper Detection */
end_comment

begin_define
define|#
directive|define
name|GPC_DIS_SLEEP
value|BIT_24
end_define

begin_comment
comment|/* Disable Energy Detect */
end_comment

begin_define
define|#
directive|define
name|GPC_HWCFG_M_3
value|BIT_23
end_define

begin_comment
comment|/* HWCFG_MODE[3] */
end_comment

begin_define
define|#
directive|define
name|GPC_HWCFG_M_2
value|BIT_22
end_define

begin_comment
comment|/* HWCFG_MODE[2] */
end_comment

begin_define
define|#
directive|define
name|GPC_HWCFG_M_1
value|BIT_21
end_define

begin_comment
comment|/* HWCFG_MODE[1] */
end_comment

begin_define
define|#
directive|define
name|GPC_HWCFG_M_0
value|BIT_20
end_define

begin_comment
comment|/* HWCFG_MODE[0] */
end_comment

begin_define
define|#
directive|define
name|GPC_ANEG_0
value|BIT_19
end_define

begin_comment
comment|/* ANEG[0] */
end_comment

begin_define
define|#
directive|define
name|GPC_ENA_XC
value|BIT_18
end_define

begin_comment
comment|/* Enable MDI crossover */
end_comment

begin_define
define|#
directive|define
name|GPC_DIS_125
value|BIT_17
end_define

begin_comment
comment|/* Disable 125 MHz clock */
end_comment

begin_define
define|#
directive|define
name|GPC_ANEG_3
value|BIT_16
end_define

begin_comment
comment|/* ANEG[3] */
end_comment

begin_define
define|#
directive|define
name|GPC_ANEG_2
value|BIT_15
end_define

begin_comment
comment|/* ANEG[2] */
end_comment

begin_define
define|#
directive|define
name|GPC_ANEG_1
value|BIT_14
end_define

begin_comment
comment|/* ANEG[1] */
end_comment

begin_define
define|#
directive|define
name|GPC_ENA_PAUSE
value|BIT_13
end_define

begin_comment
comment|/* Enable Pause (SYM_OR_REM) */
end_comment

begin_define
define|#
directive|define
name|GPC_PHYADDR_4
value|BIT_12
end_define

begin_comment
comment|/* Bit 4 of Phy Addr */
end_comment

begin_define
define|#
directive|define
name|GPC_PHYADDR_3
value|BIT_11
end_define

begin_comment
comment|/* Bit 3 of Phy Addr */
end_comment

begin_define
define|#
directive|define
name|GPC_PHYADDR_2
value|BIT_10
end_define

begin_comment
comment|/* Bit 2 of Phy Addr */
end_comment

begin_define
define|#
directive|define
name|GPC_PHYADDR_1
value|BIT_9
end_define

begin_comment
comment|/* Bit 1 of Phy Addr */
end_comment

begin_define
define|#
directive|define
name|GPC_PHYADDR_0
value|BIT_8
end_define

begin_comment
comment|/* Bit 0 of Phy Addr */
end_comment

begin_define
define|#
directive|define
name|GPC_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear GPHY Reset */
end_comment

begin_define
define|#
directive|define
name|GPC_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   GPHY Reset */
end_comment

begin_comment
comment|/*	GMAC_IRQ_SRC	 8 bit	GMAC Interrupt Source Reg (YUKON only) */
end_comment

begin_comment
comment|/*	GMAC_IRQ_MSK	 8 bit	GMAC Interrupt Mask   Reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GM_IS_RX_CO_OV
value|BIT_5
end_define

begin_comment
comment|/* Receive Counter Overflow IRQ */
end_comment

begin_define
define|#
directive|define
name|GM_IS_TX_CO_OV
value|BIT_4
end_define

begin_comment
comment|/* Transmit Counter Overflow IRQ */
end_comment

begin_define
define|#
directive|define
name|GM_IS_TX_FF_UR
value|BIT_3
end_define

begin_comment
comment|/* Transmit FIFO Underrun */
end_comment

begin_define
define|#
directive|define
name|GM_IS_TX_COMPL
value|BIT_2
end_define

begin_comment
comment|/* Frame Transmission Complete */
end_comment

begin_define
define|#
directive|define
name|GM_IS_RX_FF_OR
value|BIT_1
end_define

begin_comment
comment|/* Receive FIFO Overrun */
end_comment

begin_define
define|#
directive|define
name|GM_IS_RX_COMPL
value|BIT_0
end_define

begin_comment
comment|/* Frame Reception Complete */
end_comment

begin_define
define|#
directive|define
name|GMAC_DEF_MSK
value|(GM_IS_RX_CO_OV | GM_IS_TX_CO_OV | GM_IS_TX_FF_UR)
end_define

begin_comment
comment|/*	GMAC_LINK_CTRL	16 bit	GMAC Link Control Reg (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|GMLC_RST_CLR
value|BIT_1
end_define

begin_comment
comment|/* Clear GMAC Link Reset */
end_comment

begin_define
define|#
directive|define
name|GMLC_RST_SET
value|BIT_0
end_define

begin_comment
comment|/* Set   GMAC Link Reset */
end_comment

begin_define
define|#
directive|define
name|MSK_PORT_A
value|0
end_define

begin_define
define|#
directive|define
name|MSK_PORT_B
value|1
end_define

begin_comment
comment|/* Register access macros */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((sc)->msk_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((sc)->msk_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((sc)->msk_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((sc)->msk_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_2((sc)->msk_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_1((sc)->msk_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_WRITE_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((sc)->msk_res[0], Y2_CFG_SPC + (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((sc)->msk_res[0], Y2_CFG_SPC + (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_WRITE_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((sc)->msk_res[0], Y2_CFG_SPC + (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_READ_4
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((sc)->msk_res[0], Y2_CFG_SPC + (reg))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_READ_2
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_2((sc)->msk_res[0], Y2_CFG_SPC + (reg))
end_define

begin_define
define|#
directive|define
name|CSR_PCI_READ_1
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_1((sc)->msk_res[0], Y2_CFG_SPC + (reg))
end_define

begin_define
define|#
directive|define
name|MSK_IF_READ_4
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|)
define|\
value|CSR_READ_4((sc_if)->msk_softc, (reg))
end_define

begin_define
define|#
directive|define
name|MSK_IF_READ_2
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|)
define|\
value|CSR_READ_2((sc_if)->msk_softc, (reg))
end_define

begin_define
define|#
directive|define
name|MSK_IF_READ_1
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|)
define|\
value|CSR_READ_1((sc_if)->msk_softc, (reg))
end_define

begin_define
define|#
directive|define
name|MSK_IF_WRITE_4
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_4((sc_if)->msk_softc, (reg), (val))
end_define

begin_define
define|#
directive|define
name|MSK_IF_WRITE_2
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_2((sc_if)->msk_softc, (reg), (val))
end_define

begin_define
define|#
directive|define
name|MSK_IF_WRITE_1
parameter_list|(
name|sc_if
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_1((sc_if)->msk_softc, (reg), (val))
end_define

begin_define
define|#
directive|define
name|GMAC_REG
parameter_list|(
name|port
parameter_list|,
name|reg
parameter_list|)
define|\
value|((BASE_GMAC_1 + (port) * (BASE_GMAC_2 - BASE_GMAC_1)) | (reg))
end_define

begin_define
define|#
directive|define
name|GMAC_WRITE_2
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|CSR_WRITE_2((sc), GMAC_REG((port), (reg)), (val))
end_define

begin_define
define|#
directive|define
name|GMAC_READ_2
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|reg
parameter_list|)
define|\
value|CSR_READ_2((sc), GMAC_REG((port), (reg)))
end_define

begin_comment
comment|/* GPHY address (bits 15..11 of SMI control reg) */
end_comment

begin_define
define|#
directive|define
name|PHY_ADDR_MARV
value|0
end_define

begin_comment
comment|/*-RMV- DWORD 1: Deviations */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4200
value|0x10200000UL
end_define

begin_comment
comment|/*-RMV- 4.200 (D3 Blue Screen)*/
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4185CS
value|0x10100000UL
end_define

begin_comment
comment|/*-RMV- 4.185 (ECU 100 CS cal)*/
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4185
value|0x10080000UL
end_define

begin_comment
comment|/*-RMV- 4.185 (ECU Tx h check)*/
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4167
value|0x10040000UL
end_define

begin_comment
comment|/*-RMV- 4.167 (Rx OvSize Hang)*/
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4152
value|0x10020000UL
end_define

begin_comment
comment|/*-RMV- 4.152 (RSS issue) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4115
value|0x10010000UL
end_define

begin_comment
comment|/*-RMV- 4.115 (Rx MAC FIFO) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_4109
value|0x10008000UL
end_define

begin_comment
comment|/*-RMV- 4.109 (BIU hang) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_483
value|0x10004000UL
end_define

begin_comment
comment|/*-RMV- 4.83 (Rx TCP wrong) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_479
value|0x10002000UL
end_define

begin_comment
comment|/*-RMV- 4.79 (Rx BMU hang II) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_472
value|0x10001000UL
end_define

begin_comment
comment|/*-RMV- 4.72 (GPHY2 MDC clk) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_463
value|0x10000800UL
end_define

begin_comment
comment|/*-RMV- 4.63 (Rx BMU hang I) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_427
value|0x10000400UL
end_define

begin_comment
comment|/*-RMV- 4.27 (Tx Done Rep) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_42
value|0x10000200UL
end_define

begin_comment
comment|/*-RMV- 4.2 (pref unit burst) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_46
value|0x10000100UL
end_define

begin_comment
comment|/*-RMV- 4.6 (CPU crash II) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_43_418
value|0x10000080UL
end_define

begin_comment
comment|/*-RMV- 4.3& 4.18 (PCI unexp */
end_comment

begin_comment
comment|/*-RMV- compl&Stat BMU deadl) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_420
value|0x10000040UL
end_define

begin_comment
comment|/*-RMV- 4.20 (Status BMU ov) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_423
value|0x10000020UL
end_define

begin_comment
comment|/*-RMV- 4.23 (TCP Segm Hang) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_424
value|0x10000010UL
end_define

begin_comment
comment|/*-RMV- 4.24 (MAC reg overwr) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_425
value|0x10000008UL
end_define

begin_comment
comment|/*-RMV- 4.25 (Magic packet */
end_comment

begin_comment
comment|/*-RMV- with odd offset) */
end_comment

begin_define
define|#
directive|define
name|HWF_WA_DEV_428
value|0x10000004UL
end_define

begin_comment
comment|/*-RMV- 4.28 (Poll-U&BigEndi)*/
end_comment

begin_define
define|#
directive|define
name|HWF_WA_FIFO_FLUSH_YLA0
value|0x10000002UL
end_define

begin_comment
comment|/*-RMV- dis Rx GMAC FIFO Flush*/
end_comment

begin_define
define|#
directive|define
name|HW_FEATURE
parameter_list|(
name|sc
parameter_list|,
name|f
parameter_list|)
define|\
value|(((((sc)->msk_hw_feature& 0x30000000)>> 28)& ((f)& 0x0fffffff)) != 0)
end_define

begin_define
define|#
directive|define
name|MSK_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)& 0xffffffffUL)
end_define

begin_define
define|#
directive|define
name|MSK_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((uint64_t) (x)>> 32)
end_define

begin_comment
comment|/*  * At first I guessed 8 bytes, the size of a single descriptor, would be  * required alignment constraints. But, it seems that Yukon II have 4096  * bytes boundary alignment constraints.  */
end_comment

begin_define
define|#
directive|define
name|MSK_RING_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|MSK_STAT_ALIGN
value|4096
end_define

begin_comment
comment|/* Rx descriptor data structure */
end_comment

begin_struct
struct|struct
name|msk_rx_desc
block|{
name|uint32_t
name|msk_addr
decl_stmt|;
name|uint32_t
name|msk_control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Tx descriptor data structure */
end_comment

begin_struct
struct|struct
name|msk_tx_desc
block|{
name|uint32_t
name|msk_addr
decl_stmt|;
name|uint32_t
name|msk_control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Status descriptor data structure */
end_comment

begin_struct
struct|struct
name|msk_stat_desc
block|{
name|uint32_t
name|msk_status
decl_stmt|;
name|uint32_t
name|msk_control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* mask and shift value to get Tx async queue status for port 1 */
end_comment

begin_define
define|#
directive|define
name|STLE_TXA1_MSKL
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|STLE_TXA1_SHIFTL
value|0
end_define

begin_comment
comment|/* mask and shift value to get Tx sync queue status for port 1 */
end_comment

begin_define
define|#
directive|define
name|STLE_TXS1_MSKL
value|0x00fff000
end_define

begin_define
define|#
directive|define
name|STLE_TXS1_SHIFTL
value|12
end_define

begin_comment
comment|/* mask and shift value to get Tx async queue status for port 2 */
end_comment

begin_define
define|#
directive|define
name|STLE_TXA2_MSKL
value|0xff000000
end_define

begin_define
define|#
directive|define
name|STLE_TXA2_SHIFTL
value|24
end_define

begin_define
define|#
directive|define
name|STLE_TXA2_MSKH
value|0x000f
end_define

begin_comment
comment|/* this one shifts up */
end_comment

begin_define
define|#
directive|define
name|STLE_TXA2_SHIFTH
value|8
end_define

begin_comment
comment|/* mask and shift value to get Tx sync queue status for port 2 */
end_comment

begin_define
define|#
directive|define
name|STLE_TXS2_MSKL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|STLE_TXS2_SHIFTL
value|0
end_define

begin_define
define|#
directive|define
name|STLE_TXS2_MSKH
value|0xfff0
end_define

begin_define
define|#
directive|define
name|STLE_TXS2_SHIFTH
value|4
end_define

begin_comment
comment|/* YUKON-2 bit values */
end_comment

begin_define
define|#
directive|define
name|HW_OWNER
value|0x80000000
end_define

begin_define
define|#
directive|define
name|SW_OWNER
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PU_PUTIDX_VALID
value|0x10000000
end_define

begin_comment
comment|/* YUKON-2 Control flags */
end_comment

begin_define
define|#
directive|define
name|UDPTCP
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CALSUM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|WR_SUM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INIT_SUM
value|0x00080000
end_define

begin_define
define|#
directive|define
name|LOCK_SUM
value|0x00100000
end_define

begin_define
define|#
directive|define
name|INS_VLAN
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FRC_STAT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|EOP
value|0x00800000
end_define

begin_define
define|#
directive|define
name|TX_LOCK
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BUF_SEND
value|0x02000000
end_define

begin_define
define|#
directive|define
name|PACKET_SEND
value|0x04000000
end_define

begin_define
define|#
directive|define
name|NO_WARNING
value|0x40000000
end_define

begin_define
define|#
directive|define
name|NO_UPDATE
value|0x80000000
end_define

begin_comment
comment|/* YUKON-2 Rx/Tx opcodes defines */
end_comment

begin_define
define|#
directive|define
name|OP_TCPWRITE
value|0x11000000
end_define

begin_define
define|#
directive|define
name|OP_TCPSTART
value|0x12000000
end_define

begin_define
define|#
directive|define
name|OP_TCPINIT
value|0x14000000
end_define

begin_define
define|#
directive|define
name|OP_TCPLCK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|OP_TCPCHKSUM
value|OP_TCPSTART
end_define

begin_define
define|#
directive|define
name|OP_TCPIS
value|(OP_TCPINIT | OP_TCPSTART)
end_define

begin_define
define|#
directive|define
name|OP_TCPLW
value|(OP_TCPLCK | OP_TCPWRITE)
end_define

begin_define
define|#
directive|define
name|OP_TCPLSW
value|(OP_TCPLCK | OP_TCPSTART | OP_TCPWRITE)
end_define

begin_define
define|#
directive|define
name|OP_TCPLISW
value|(OP_TCPLCK | OP_TCPINIT | OP_TCPSTART | OP_TCPWRITE)
end_define

begin_define
define|#
directive|define
name|OP_ADDR64
value|0x21000000
end_define

begin_define
define|#
directive|define
name|OP_VLAN
value|0x22000000
end_define

begin_define
define|#
directive|define
name|OP_ADDR64VLAN
value|(OP_ADDR64 | OP_VLAN)
end_define

begin_define
define|#
directive|define
name|OP_LRGLEN
value|0x24000000
end_define

begin_define
define|#
directive|define
name|OP_LRGLENVLAN
value|(OP_LRGLEN | OP_VLAN)
end_define

begin_define
define|#
directive|define
name|OP_BUFFER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|OP_PACKET
value|0x41000000
end_define

begin_define
define|#
directive|define
name|OP_LARGESEND
value|0x43000000
end_define

begin_comment
comment|/* YUKON-2 STATUS opcodes defines */
end_comment

begin_define
define|#
directive|define
name|OP_RXSTAT
value|0x60000000
end_define

begin_define
define|#
directive|define
name|OP_RXTIMESTAMP
value|0x61000000
end_define

begin_define
define|#
directive|define
name|OP_RXVLAN
value|0x62000000
end_define

begin_define
define|#
directive|define
name|OP_RXCHKS
value|0x64000000
end_define

begin_define
define|#
directive|define
name|OP_RXCHKSVLAN
value|(OP_RXCHKS | OP_RXVLAN)
end_define

begin_define
define|#
directive|define
name|OP_RXTIMEVLAN
value|(OP_RXTIMESTAMP | OP_RXVLAN)
end_define

begin_define
define|#
directive|define
name|OP_RSS_HASH
value|0x65000000
end_define

begin_define
define|#
directive|define
name|OP_TXINDEXLE
value|0x68000000
end_define

begin_comment
comment|/* YUKON-2 SPECIAL opcodes defines */
end_comment

begin_define
define|#
directive|define
name|OP_PUTIDX
value|0x70000000
end_define

begin_define
define|#
directive|define
name|STLE_OP_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|STLE_LEN_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* Descriptor Bit Definition */
end_comment

begin_comment
comment|/*	TxCtrl		Transmit Buffer Control Field */
end_comment

begin_comment
comment|/*	RxCtrl		Receive  Buffer Control Field */
end_comment

begin_define
define|#
directive|define
name|BMU_OWN
value|BIT_31
end_define

begin_comment
comment|/* OWN bit: 0=host/1=BMU */
end_comment

begin_define
define|#
directive|define
name|BMU_STF
value|BIT_30
end_define

begin_comment
comment|/* Start of Frame */
end_comment

begin_define
define|#
directive|define
name|BMU_EOF
value|BIT_29
end_define

begin_comment
comment|/* End of Frame */
end_comment

begin_define
define|#
directive|define
name|BMU_IRQ_EOB
value|BIT_28
end_define

begin_comment
comment|/* Req "End of Buffer" IRQ */
end_comment

begin_define
define|#
directive|define
name|BMU_IRQ_EOF
value|BIT_27
end_define

begin_comment
comment|/* Req "End of Frame" IRQ */
end_comment

begin_comment
comment|/* TxCtrl specific bits */
end_comment

begin_define
define|#
directive|define
name|BMU_STFWD
value|BIT_26
end_define

begin_comment
comment|/* (Tx)	Store& Forward Frame */
end_comment

begin_define
define|#
directive|define
name|BMU_NO_FCS
value|BIT_25
end_define

begin_comment
comment|/* (Tx) Disable MAC FCS (CRC) generation */
end_comment

begin_define
define|#
directive|define
name|BMU_SW
value|BIT_24
end_define

begin_comment
comment|/* (Tx)	1 bit res. for SW use */
end_comment

begin_comment
comment|/* RxCtrl specific bits */
end_comment

begin_define
define|#
directive|define
name|BMU_DEV_0
value|BIT_26
end_define

begin_comment
comment|/* (Rx)	Transfer data to Dev0 */
end_comment

begin_define
define|#
directive|define
name|BMU_STAT_VAL
value|BIT_25
end_define

begin_comment
comment|/* (Rx)	Rx Status Valid */
end_comment

begin_define
define|#
directive|define
name|BMU_TIST_VAL
value|BIT_24
end_define

begin_comment
comment|/* (Rx)	Rx TimeStamp Valid */
end_comment

begin_comment
comment|/* Bit 23..16:	BMU Check Opcodes */
end_comment

begin_define
define|#
directive|define
name|BMU_CHECK
value|(0x55<<16)
end_define

begin_comment
comment|/* Default BMU check */
end_comment

begin_define
define|#
directive|define
name|BMU_TCP_CHECK
value|(0x56<<16)
end_define

begin_comment
comment|/* Descr with TCP ext */
end_comment

begin_define
define|#
directive|define
name|BMU_UDP_CHECK
value|(0x57<<16)
end_define

begin_comment
comment|/* Descr with UDP ext (YUKON only) */
end_comment

begin_define
define|#
directive|define
name|BMU_BBC
value|0xffff
end_define

begin_comment
comment|/* Bit 15.. 0:	Buffer Byte Counter */
end_comment

begin_define
define|#
directive|define
name|MSK_TX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|MSK_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|MSK_JUMBO_RX_RING_CNT
value|MSK_RX_RING_CNT
end_define

begin_define
define|#
directive|define
name|MSK_STAT_RING_CNT
value|((1 + 3) * (MSK_TX_RING_CNT + MSK_RX_RING_CNT))
end_define

begin_define
define|#
directive|define
name|MSK_MAXTXSEGS
value|32
end_define

begin_define
define|#
directive|define
name|MSK_MAXRXSEGS
value|32
end_define

begin_comment
comment|/*  * It seems that the hardware requires extra decriptors(LEs) to offload  * TCP/UDP checksum, VLAN hardware tag inserstion and TSO.  *  * 1 descriptor for TCP/UDP checksum offload.  * 1 descriptor VLAN hardware tag insertion.  * 1 descriptor for TSO(TCP Segmentation Offload)  * 1 descriptor for 64bits DMA : Not applicatable due to the use of  *  BUS_SPACE_MAXADDR_32BIT in parent DMA tag creation.  */
end_comment

begin_define
define|#
directive|define
name|MSK_RESERVED_TX_DESC_CNT
value|3
end_define

begin_comment
comment|/*  * Jumbo buffer stuff. Note that we must allocate more jumbo  * buffers than there are descriptors in the receive ring. This  * is because we don't know how long it will take for a packet  * to be released after we hand it off to the upper protocol  * layers. To be safe, we allocate 1.5 times the number of  * receive descriptors.  */
end_comment

begin_define
define|#
directive|define
name|MSK_JUMBO_FRAMELEN
value|9022
end_define

begin_define
define|#
directive|define
name|MSK_JUMBO_MTU
value|(MSK_JUMBO_FRAMELEN-ETHER_HDR_LEN-ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|MSK_MAX_FRAMELEN
define|\
value|(ETHER_MAX_LEN + ETHER_VLAN_ENCAP_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|MSK_MIN_FRAMELEN
value|(ETHER_MIN_LEN - ETHER_CRC_LEN)
end_define

begin_define
define|#
directive|define
name|MSK_JSLOTS
value|((MSK_RX_RING_CNT * 3) / 2)
end_define

begin_define
define|#
directive|define
name|MSK_JRAWLEN
value|(MSK_JUMBO_FRAMELEN + ETHER_ALIGN)
end_define

begin_define
define|#
directive|define
name|MSK_JLEN
value|(MSK_JRAWLEN + (sizeof(uint64_t) - \ 	(MSK_JRAWLEN % sizeof(uint64_t))))
end_define

begin_define
define|#
directive|define
name|MSK_JPAGESZ
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|MSK_RESID
define|\
value|(MSK_JPAGESZ - (MSK_JLEN * MSK_JSLOTS) % MSK_JPAGESZ)
end_define

begin_define
define|#
directive|define
name|MSK_JMEM
value|((MSK_JLEN * MSK_JSLOTS) + MSK_RESID)
end_define

begin_struct
struct|struct
name|msk_jpool_entry
block|{
name|int
name|slot
decl_stmt|;
name|SLIST_ENTRY
argument_list|(
argument|msk_jpool_entry
argument_list|)
name|jpool_entries
expr_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msk_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
name|struct
name|msk_tx_desc
modifier|*
name|tx_le
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msk_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
name|struct
name|msk_rx_desc
modifier|*
name|rx_le
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msk_chain_data
block|{
name|bus_dma_tag_t
name|msk_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|msk_tx_tag
decl_stmt|;
name|struct
name|msk_txdesc
name|msk_txdesc
index|[
name|MSK_TX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|msk_rx_tag
decl_stmt|;
name|struct
name|msk_rxdesc
name|msk_rxdesc
index|[
name|MSK_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|msk_tx_ring_tag
decl_stmt|;
name|bus_dma_tag_t
name|msk_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|msk_tx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|msk_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|msk_rx_sparemap
decl_stmt|;
name|bus_dma_tag_t
name|msk_jumbo_rx_tag
decl_stmt|;
name|bus_dma_tag_t
name|msk_jumbo_tag
decl_stmt|;
name|bus_dmamap_t
name|msk_jumbo_map
decl_stmt|;
name|bus_dma_tag_t
name|msk_jumbo_mtag
decl_stmt|;
name|caddr_t
name|msk_jslots
index|[
name|MSK_JSLOTS
index|]
decl_stmt|;
name|struct
name|msk_rxdesc
name|msk_jumbo_rxdesc
index|[
name|MSK_JUMBO_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|msk_jumbo_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|msk_jumbo_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|msk_jumbo_rx_sparemap
decl_stmt|;
name|uint16_t
name|msk_tso_mtu
decl_stmt|;
name|int
name|msk_tx_prod
decl_stmt|;
name|int
name|msk_tx_cons
decl_stmt|;
name|int
name|msk_tx_cnt
decl_stmt|;
name|int
name|msk_tx_put
decl_stmt|;
name|int
name|msk_rx_cons
decl_stmt|;
name|int
name|msk_rx_prod
decl_stmt|;
name|int
name|msk_rx_putwm
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|msk_ring_data
block|{
name|struct
name|msk_tx_desc
modifier|*
name|msk_tx_ring
decl_stmt|;
name|bus_addr_t
name|msk_tx_ring_paddr
decl_stmt|;
name|struct
name|msk_rx_desc
modifier|*
name|msk_rx_ring
decl_stmt|;
name|bus_addr_t
name|msk_rx_ring_paddr
decl_stmt|;
name|struct
name|msk_rx_desc
modifier|*
name|msk_jumbo_rx_ring
decl_stmt|;
name|bus_addr_t
name|msk_jumbo_rx_ring_paddr
decl_stmt|;
name|void
modifier|*
name|msk_jumbo_buf
decl_stmt|;
name|bus_addr_t
name|msk_jumbo_buf_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSK_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->msk_rdata.msk_tx_ring_paddr + sizeof(struct msk_tx_desc) * (i))
end_define

begin_define
define|#
directive|define
name|MSK_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->msk_rdata.msk_rx_ring_paddr + sizeof(struct msk_rx_desc) * (i))
end_define

begin_define
define|#
directive|define
name|MSK_JUMBO_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->msk_rdata.msk_jumbo_rx_ring_paddr + sizeof(struct msk_rx_desc) * (i))
end_define

begin_define
define|#
directive|define
name|MSK_TX_RING_SZ
define|\
value|(sizeof(struct msk_tx_desc) * MSK_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|MSK_RX_RING_SZ
define|\
value|(sizeof(struct msk_rx_desc) * MSK_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|MSK_JUMBO_RX_RING_SZ
define|\
value|(sizeof(struct msk_rx_desc) * MSK_JUMBO_RX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|MSK_STAT_RING_SZ
define|\
value|(sizeof(struct msk_stat_desc) * MSK_STAT_RING_CNT)
end_define

begin_define
define|#
directive|define
name|MSK_INC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x) = (x + 1) % y
end_define

begin_define
define|#
directive|define
name|MSK_PCI_BUS
value|0
end_define

begin_define
define|#
directive|define
name|MSK_PCIX_BUS
value|1
end_define

begin_define
define|#
directive|define
name|MSK_PEX_BUS
value|2
end_define

begin_define
define|#
directive|define
name|MSK_PROC_DEFAULT
value|(MSK_RX_RING_CNT / 2)
end_define

begin_define
define|#
directive|define
name|MSK_PROC_MIN
value|30
end_define

begin_define
define|#
directive|define
name|MSK_PROC_MAX
value|(MSK_RX_RING_CNT - 1)
end_define

begin_define
define|#
directive|define
name|MSK_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|MSK_PUT_WM
value|10
end_define

begin_comment
comment|/* Forward decl. */
end_comment

begin_struct_decl
struct_decl|struct
name|msk_if_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/* Softc for the Marvell Yukon II controller. */
end_comment

begin_struct
struct|struct
name|msk_softc
block|{
name|struct
name|resource
modifier|*
name|msk_res
index|[
literal|1
index|]
decl_stmt|;
comment|/* I/O resource */
name|int
name|msk_res_type
decl_stmt|;
name|int
name|msk_res_id
decl_stmt|;
name|struct
name|resource
modifier|*
name|msk_irq
index|[
literal|2
index|]
decl_stmt|;
comment|/* IRQ resources */
name|void
modifier|*
name|msk_intrhand
index|[
literal|2
index|]
decl_stmt|;
comment|/* irq handler handle */
name|device_t
name|msk_dev
decl_stmt|;
name|uint8_t
name|msk_hw_id
decl_stmt|;
name|uint8_t
name|msk_hw_rev
decl_stmt|;
name|uint8_t
name|msk_bustype
decl_stmt|;
name|uint8_t
name|msk_num_port
decl_stmt|;
name|int
name|msk_ramsize
decl_stmt|;
comment|/* amount of SRAM on NIC */
name|uint32_t
name|msk_pmd
decl_stmt|;
comment|/* physical media type */
name|uint32_t
name|msk_coppertype
decl_stmt|;
name|uint32_t
name|msk_intrmask
decl_stmt|;
name|uint32_t
name|msk_intrhwemask
decl_stmt|;
name|int
name|msk_suspended
decl_stmt|;
name|int
name|msk_hw_feature
decl_stmt|;
name|int
name|msk_clock
decl_stmt|;
name|int
name|msk_marvell_phy
decl_stmt|;
name|int
name|msk_msi
decl_stmt|;
name|struct
name|msk_if_softc
modifier|*
name|msk_if
index|[
literal|2
index|]
decl_stmt|;
name|device_t
name|msk_devs
index|[
literal|2
index|]
decl_stmt|;
name|int
name|msk_txqsize
decl_stmt|;
name|int
name|msk_rxqsize
decl_stmt|;
name|int
name|msk_txqstart
index|[
literal|2
index|]
decl_stmt|;
name|int
name|msk_txqend
index|[
literal|2
index|]
decl_stmt|;
name|int
name|msk_rxqstart
index|[
literal|2
index|]
decl_stmt|;
name|int
name|msk_rxqend
index|[
literal|2
index|]
decl_stmt|;
name|bus_dma_tag_t
name|msk_stat_tag
decl_stmt|;
name|bus_dmamap_t
name|msk_stat_map
decl_stmt|;
name|struct
name|msk_stat_desc
modifier|*
name|msk_stat_ring
decl_stmt|;
name|bus_addr_t
name|msk_stat_ring_paddr
decl_stmt|;
name|int
name|msk_process_limit
decl_stmt|;
name|int
name|msk_stat_cons
decl_stmt|;
name|struct
name|taskqueue
modifier|*
name|msk_tq
decl_stmt|;
name|struct
name|task
name|msk_int_task
decl_stmt|;
name|struct
name|mtx
name|msk_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSK_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->msk_mtx)
end_define

begin_define
define|#
directive|define
name|MSK_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->msk_mtx)
end_define

begin_define
define|#
directive|define
name|MSK_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->msk_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|MSK_IF_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|MSK_LOCK((_sc)->msk_softc)
end_define

begin_define
define|#
directive|define
name|MSK_IF_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|MSK_UNLOCK((_sc)->msk_softc)
end_define

begin_define
define|#
directive|define
name|MSK_IF_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|MSK_LOCK_ASSERT((_sc)->msk_softc)
end_define

begin_define
define|#
directive|define
name|MSK_USECS
parameter_list|(
name|sc
parameter_list|,
name|us
parameter_list|)
value|((sc)->msk_clock * (us))
end_define

begin_comment
comment|/* Softc for each logical interface. */
end_comment

begin_struct
struct|struct
name|msk_if_softc
block|{
name|struct
name|ifnet
modifier|*
name|msk_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|msk_miibus
decl_stmt|;
name|device_t
name|msk_if_dev
decl_stmt|;
name|int32_t
name|msk_port
decl_stmt|;
comment|/* port # on controller */
name|int
name|msk_framesize
decl_stmt|;
name|int
name|msk_phytype
decl_stmt|;
name|int
name|msk_phyaddr
decl_stmt|;
name|int
name|msk_link
decl_stmt|;
name|struct
name|callout
name|msk_tick_ch
decl_stmt|;
name|int
name|msk_watchdog_timer
decl_stmt|;
name|uint32_t
name|msk_txq
decl_stmt|;
comment|/* Tx. Async Queue offset */
name|uint32_t
name|msk_txsq
decl_stmt|;
comment|/* Tx. Syn Queue offset */
name|uint32_t
name|msk_rxq
decl_stmt|;
comment|/* Rx. Qeueue offset */
name|struct
name|msk_chain_data
name|msk_cdata
decl_stmt|;
name|struct
name|msk_ring_data
name|msk_rdata
decl_stmt|;
name|struct
name|msk_softc
modifier|*
name|msk_softc
decl_stmt|;
comment|/* parent controller */
name|struct
name|task
name|msk_link_task
decl_stmt|;
name|struct
name|task
name|msk_tx_task
decl_stmt|;
name|int
name|msk_if_flags
decl_stmt|;
name|int
name|msk_detach
decl_stmt|;
name|uint16_t
name|msk_vtag
decl_stmt|;
comment|/* VLAN tag id. */
name|SLIST_HEAD
argument_list|(
argument|__msk_jfreehead
argument_list|,
argument|msk_jpool_entry
argument_list|)
name|msk_jfree_listhead
expr_stmt|;
name|SLIST_HEAD
argument_list|(
argument|__msk_jinusehead
argument_list|,
argument|msk_jpool_entry
argument_list|)
name|msk_jinuse_listhead
expr_stmt|;
name|struct
name|mtx
name|msk_jlist_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MSK_JLIST_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->msk_jlist_mtx)
end_define

begin_define
define|#
directive|define
name|MSK_JLIST_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->msk_jlist_mtx)
end_define

begin_define
define|#
directive|define
name|MSK_TIMEOUT
value|1000
end_define

begin_define
define|#
directive|define
name|MSK_PHY_POWERUP
value|1
end_define

begin_define
define|#
directive|define
name|MSK_PHY_POWERDOWN
value|0
end_define

end_unit

