begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Stephane E. Potvin<sepotvin@videotron.ca>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HDAC_H_
end_ifndef

begin_define
define|#
directive|define
name|_HDAC_H_
end_define

begin_include
include|#
directive|include
file|"hdac_if.h"
end_include

begin_comment
comment|/****************************************************************************  * Miscellanious defines  ****************************************************************************/
end_comment

begin_comment
comment|/* Controller models */
end_comment

begin_define
define|#
directive|define
name|HDA_MODEL_CONSTRUCT
parameter_list|(
name|vendor
parameter_list|,
name|model
parameter_list|)
define|\
value|(((uint32_t)(model)<< 16) | ((vendor##_VENDORID)& 0xffff))
end_define

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|INTEL_VENDORID
value|0x8086
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_OAK
value|HDA_MODEL_CONSTRUCT(INTEL, 0x080a)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_BAY
value|HDA_MODEL_CONSTRUCT(INTEL, 0x0f04)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_HSW1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x0a0c)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_HSW2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x0c0c)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_HSW3
value|HDA_MODEL_CONSTRUCT(INTEL, 0x0d0c)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_BDW1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x160c)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_CPT
value|HDA_MODEL_CONSTRUCT(INTEL, 0x1c20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_PATSBURG
value|HDA_MODEL_CONSTRUCT(INTEL, 0x1d20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_PPT1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x1e20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801F
value|HDA_MODEL_CONSTRUCT(INTEL, 0x2668)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_63XXESB
value|HDA_MODEL_CONSTRUCT(INTEL, 0x269a)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801G
value|HDA_MODEL_CONSTRUCT(INTEL, 0x27d8)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801H
value|HDA_MODEL_CONSTRUCT(INTEL, 0x284b)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801I
value|HDA_MODEL_CONSTRUCT(INTEL, 0x293e)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801JI
value|HDA_MODEL_CONSTRUCT(INTEL, 0x3a3e)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_82801JD
value|HDA_MODEL_CONSTRUCT(INTEL, 0x3a6e)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_PCH
value|HDA_MODEL_CONSTRUCT(INTEL, 0x3b56)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_PCH2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x3b57)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_MACBOOKPRO92
value|HDA_MODEL_CONSTRUCT(INTEL, 0x7270)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_SCH
value|HDA_MODEL_CONSTRUCT(INTEL, 0x811b)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_LPT1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x8c20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_LPT2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x8c21)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_WCPT
value|HDA_MODEL_CONSTRUCT(INTEL, 0x8ca0)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_WELLS1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x8d20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_WELLS2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x8d21)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_LPTLP1
value|HDA_MODEL_CONSTRUCT(INTEL, 0x9c20)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_LPTLP2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x9c21)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_BDW2
value|HDA_MODEL_CONSTRUCT(INTEL, 0x9ca0)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_SRPTLP
value|HDA_MODEL_CONSTRUCT(INTEL, 0x9d70)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_KBLKLP
value|HDA_MODEL_CONSTRUCT(INTEL, 0x9d71)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_SRPT
value|HDA_MODEL_CONSTRUCT(INTEL, 0xa170)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_KBLK
value|HDA_MODEL_CONSTRUCT(INTEL, 0xa171)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_KBLKH
value|HDA_MODEL_CONSTRUCT(INTEL, 0xa2f0)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_CFLK
value|HDA_MODEL_CONSTRUCT(INTEL, 0xa348)
end_define

begin_define
define|#
directive|define
name|HDA_INTEL_ALL
value|HDA_MODEL_CONSTRUCT(INTEL, 0xffff)
end_define

begin_comment
comment|/* Nvidia */
end_comment

begin_define
define|#
directive|define
name|NVIDIA_VENDORID
value|0x10de
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP51
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x026c)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP55
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0371)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP61_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x03e4)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP61_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x03f0)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP65_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x044a)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP65_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x044b)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP67_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x055c)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP67_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x055d)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP78_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0774)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP78_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0775)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP78_3
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0776)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP78_4
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0777)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP73_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x07fc)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP73_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x07fd)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP79_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0ac0)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP79_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0ac1)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP79_3
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0ac2)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP79_4
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0ac3)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_0BE2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0be2)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_0BE3
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0be3)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_0BE4
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0be4)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GT100
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0be5)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GT106
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0be9)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GT108
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0bea)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GT104
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0beb)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GT116
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0bee)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP89_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0d94)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP89_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0d95)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP89_3
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0d96)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_MCP89_4
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0d97)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GF119
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0e08)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GF110_1
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0e09)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_GF110_2
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0x0e0c)
end_define

begin_define
define|#
directive|define
name|HDA_NVIDIA_ALL
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0xffff)
end_define

begin_comment
comment|/* ATI */
end_comment

begin_define
define|#
directive|define
name|ATI_VENDORID
value|0x1002
end_define

begin_define
define|#
directive|define
name|HDA_ATI_SB450
value|HDA_MODEL_CONSTRUCT(ATI, 0x437b)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_SB600
value|HDA_MODEL_CONSTRUCT(ATI, 0x4383)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RS600
value|HDA_MODEL_CONSTRUCT(ATI, 0x793b)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RS690
value|HDA_MODEL_CONSTRUCT(ATI, 0x7919)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RS780
value|HDA_MODEL_CONSTRUCT(ATI, 0x960f)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_R600
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa00)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV630
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa08)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV610
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa10)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV670
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa18)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV635
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa20)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV620
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa28)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV770
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa30)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV730
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa38)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV710
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa40)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV740
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa48)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV870
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa50)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV840
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa58)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV830
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa60)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV810
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa68)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV970
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa80)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV940
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa88)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV930
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa90)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_RV910
value|HDA_MODEL_CONSTRUCT(ATI, 0xaa98)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_R1000
value|HDA_MODEL_CONSTRUCT(ATI, 0xaaa0)
end_define

begin_define
define|#
directive|define
name|HDA_ATI_ALL
value|HDA_MODEL_CONSTRUCT(ATI, 0xffff)
end_define

begin_define
define|#
directive|define
name|AMD_VENDORID
value|0x1022
end_define

begin_define
define|#
directive|define
name|HDA_AMD_HUDSON2
value|HDA_MODEL_CONSTRUCT(AMD, 0x780d)
end_define

begin_define
define|#
directive|define
name|HDA_AMD_ALL
value|HDA_MODEL_CONSTRUCT(AMD, 0xffff)
end_define

begin_comment
comment|/* RDC */
end_comment

begin_define
define|#
directive|define
name|RDC_VENDORID
value|0x17f3
end_define

begin_define
define|#
directive|define
name|HDA_RDC_M3010
value|HDA_MODEL_CONSTRUCT(RDC, 0x3010)
end_define

begin_comment
comment|/* VIA */
end_comment

begin_define
define|#
directive|define
name|VIA_VENDORID
value|0x1106
end_define

begin_define
define|#
directive|define
name|HDA_VIA_VT82XX
value|HDA_MODEL_CONSTRUCT(VIA, 0x3288)
end_define

begin_define
define|#
directive|define
name|HDA_VIA_ALL
value|HDA_MODEL_CONSTRUCT(VIA, 0xffff)
end_define

begin_comment
comment|/* SiS */
end_comment

begin_define
define|#
directive|define
name|SIS_VENDORID
value|0x1039
end_define

begin_define
define|#
directive|define
name|HDA_SIS_966
value|HDA_MODEL_CONSTRUCT(SIS, 0x7502)
end_define

begin_define
define|#
directive|define
name|HDA_SIS_ALL
value|HDA_MODEL_CONSTRUCT(SIS, 0xffff)
end_define

begin_comment
comment|/* ULI */
end_comment

begin_define
define|#
directive|define
name|ULI_VENDORID
value|0x10b9
end_define

begin_define
define|#
directive|define
name|HDA_ULI_M5461
value|HDA_MODEL_CONSTRUCT(ULI, 0x5461)
end_define

begin_define
define|#
directive|define
name|HDA_ULI_ALL
value|HDA_MODEL_CONSTRUCT(ULI, 0xffff)
end_define

begin_comment
comment|/* OEM/subvendors */
end_comment

begin_comment
comment|/* Intel */
end_comment

begin_define
define|#
directive|define
name|INTEL_DH87RL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(INTEL, 0x204a)
end_define

begin_define
define|#
directive|define
name|INTEL_D101GGC_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(INTEL, 0xd600)
end_define

begin_comment
comment|/* HP/Compaq */
end_comment

begin_define
define|#
directive|define
name|HP_VENDORID
value|0x103c
end_define

begin_define
define|#
directive|define
name|HP_V3000_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x30b5)
end_define

begin_define
define|#
directive|define
name|HP_NX7400_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x30a2)
end_define

begin_define
define|#
directive|define
name|HP_NX6310_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x30aa)
end_define

begin_define
define|#
directive|define
name|HP_NX6325_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x30b0)
end_define

begin_define
define|#
directive|define
name|HP_XW4300_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x3013)
end_define

begin_define
define|#
directive|define
name|HP_3010_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x3010)
end_define

begin_define
define|#
directive|define
name|HP_DV5000_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x30a5)
end_define

begin_define
define|#
directive|define
name|HP_DC7700S_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x2801)
end_define

begin_define
define|#
directive|define
name|HP_DC7700_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0x2802)
end_define

begin_define
define|#
directive|define
name|HP_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(HP, 0xffff)
end_define

begin_comment
comment|/* What is wrong with XN 2563 anyway? (Got the picture ?) */
end_comment

begin_define
define|#
directive|define
name|HP_NX6325_SUBVENDORX
value|0x103c30b0
end_define

begin_comment
comment|/* Dell */
end_comment

begin_define
define|#
directive|define
name|DELL_VENDORID
value|0x1028
end_define

begin_define
define|#
directive|define
name|DELL_D630_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x01f9)
end_define

begin_define
define|#
directive|define
name|DELL_D820_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x01cc)
end_define

begin_define
define|#
directive|define
name|DELL_V1400_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x0227)
end_define

begin_define
define|#
directive|define
name|DELL_V1500_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x0228)
end_define

begin_define
define|#
directive|define
name|DELL_I1300_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x01c9)
end_define

begin_define
define|#
directive|define
name|DELL_XPSM1210_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x01d7)
end_define

begin_define
define|#
directive|define
name|DELL_OPLX745_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0x01da)
end_define

begin_define
define|#
directive|define
name|DELL_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(DELL, 0xffff)
end_define

begin_comment
comment|/* Clevo */
end_comment

begin_define
define|#
directive|define
name|CLEVO_VENDORID
value|0x1558
end_define

begin_define
define|#
directive|define
name|CLEVO_D900T_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(CLEVO, 0x0900)
end_define

begin_define
define|#
directive|define
name|CLEVO_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(CLEVO, 0xffff)
end_define

begin_comment
comment|/* Acer */
end_comment

begin_define
define|#
directive|define
name|ACER_VENDORID
value|0x1025
end_define

begin_define
define|#
directive|define
name|ACER_A5050_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x010f)
end_define

begin_define
define|#
directive|define
name|ACER_A4520_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x0127)
end_define

begin_define
define|#
directive|define
name|ACER_A4710_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x012f)
end_define

begin_define
define|#
directive|define
name|ACER_A4715_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x0133)
end_define

begin_define
define|#
directive|define
name|ACER_3681WXM_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x0110)
end_define

begin_define
define|#
directive|define
name|ACER_T6292_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x011b)
end_define

begin_define
define|#
directive|define
name|ACER_T5320_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0x011f)
end_define

begin_define
define|#
directive|define
name|ACER_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ACER, 0xffff)
end_define

begin_comment
comment|/* Asus */
end_comment

begin_define
define|#
directive|define
name|ASUS_VENDORID
value|0x1043
end_define

begin_define
define|#
directive|define
name|ASUS_A8X_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1153)
end_define

begin_define
define|#
directive|define
name|ASUS_U5F_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1263)
end_define

begin_define
define|#
directive|define
name|ASUS_W6F_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1263)
end_define

begin_define
define|#
directive|define
name|ASUS_A7M_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1323)
end_define

begin_define
define|#
directive|define
name|ASUS_F3JC_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1338)
end_define

begin_define
define|#
directive|define
name|ASUS_G2K_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1339)
end_define

begin_define
define|#
directive|define
name|ASUS_A7T_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x13c2)
end_define

begin_define
define|#
directive|define
name|ASUS_UX31A_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1517)
end_define

begin_define
define|#
directive|define
name|ASUS_W2J_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1971)
end_define

begin_define
define|#
directive|define
name|ASUS_M5200_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x1993)
end_define

begin_define
define|#
directive|define
name|ASUS_P5PL2_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x817f)
end_define

begin_define
define|#
directive|define
name|ASUS_P1AH2_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x81cb)
end_define

begin_define
define|#
directive|define
name|ASUS_M2NPVMX_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x81cb)
end_define

begin_define
define|#
directive|define
name|ASUS_M2V_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x81e7)
end_define

begin_define
define|#
directive|define
name|ASUS_P5BWD_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x81ec)
end_define

begin_define
define|#
directive|define
name|ASUS_M2N_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0x8234)
end_define

begin_define
define|#
directive|define
name|ASUS_A8NVMCSM_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(NVIDIA, 0xcb84)
end_define

begin_define
define|#
directive|define
name|ASUS_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(ASUS, 0xffff)
end_define

begin_comment
comment|/* IBM / Lenovo */
end_comment

begin_define
define|#
directive|define
name|IBM_VENDORID
value|0x1014
end_define

begin_define
define|#
directive|define
name|IBM_M52_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(IBM, 0x02f6)
end_define

begin_define
define|#
directive|define
name|IBM_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(IBM, 0xffff)
end_define

begin_comment
comment|/* Lenovo */
end_comment

begin_define
define|#
directive|define
name|LENOVO_VENDORID
value|0x17aa
end_define

begin_define
define|#
directive|define
name|LENOVO_3KN100_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x2066)
end_define

begin_define
define|#
directive|define
name|LENOVO_3KN200_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x384e)
end_define

begin_define
define|#
directive|define
name|LENOVO_B450_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x3a0d)
end_define

begin_define
define|#
directive|define
name|LENOVO_TCA55_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x1015)
end_define

begin_define
define|#
directive|define
name|LENOVO_X1_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21e8)
end_define

begin_define
define|#
directive|define
name|LENOVO_X1CRBN_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21f9)
end_define

begin_define
define|#
directive|define
name|LENOVO_X120BS_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x2227)
end_define

begin_define
define|#
directive|define
name|LENOVO_X220_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21da)
end_define

begin_define
define|#
directive|define
name|LENOVO_X300_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x20ac)
end_define

begin_define
define|#
directive|define
name|LENOVO_T400_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x20f2)
end_define

begin_define
define|#
directive|define
name|LENOVO_T420_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21ce)
end_define

begin_define
define|#
directive|define
name|LENOVO_T430_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21f3)
end_define

begin_define
define|#
directive|define
name|LENOVO_T430S_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21fb)
end_define

begin_define
define|#
directive|define
name|LENOVO_T520_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21cf)
end_define

begin_define
define|#
directive|define
name|LENOVO_T530_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x21f6)
end_define

begin_define
define|#
directive|define
name|LENOVO_G580_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0x3977)
end_define

begin_define
define|#
directive|define
name|LENOVO_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LENOVO, 0xffff)
end_define

begin_comment
comment|/* Samsung */
end_comment

begin_define
define|#
directive|define
name|SAMSUNG_VENDORID
value|0x144d
end_define

begin_define
define|#
directive|define
name|SAMSUNG_Q1_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(SAMSUNG, 0xc027)
end_define

begin_define
define|#
directive|define
name|SAMSUNG_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(SAMSUNG, 0xffff)
end_define

begin_comment
comment|/* Medion ? */
end_comment

begin_define
define|#
directive|define
name|MEDION_VENDORID
value|0x161f
end_define

begin_define
define|#
directive|define
name|MEDION_MD95257_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(MEDION, 0x203d)
end_define

begin_define
define|#
directive|define
name|MEDION_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(MEDION, 0xffff)
end_define

begin_comment
comment|/* Apple Computer Inc. */
end_comment

begin_define
define|#
directive|define
name|APPLE_VENDORID
value|0x106b
end_define

begin_define
define|#
directive|define
name|APPLE_MB3_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(APPLE, 0x00a1)
end_define

begin_comment
comment|/* Sony */
end_comment

begin_define
define|#
directive|define
name|SONY_VENDORID
value|0x104d
end_define

begin_define
define|#
directive|define
name|SONY_S5_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(SONY, 0x81cc)
end_define

begin_define
define|#
directive|define
name|SONY_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(SONY, 0xffff)
end_define

begin_comment
comment|/*  * Apple Intel MacXXXX seems using Sigmatel codec/vendor id  * instead of their own, which is beyond my comprehension  * (see HDA_CODEC_STAC9221 below).  */
end_comment

begin_define
define|#
directive|define
name|APPLE_INTEL_MAC
value|0x76808384
end_define

begin_define
define|#
directive|define
name|APPLE_MACBOOKAIR31
value|0x0d9410de
end_define

begin_define
define|#
directive|define
name|APPLE_MACBOOKPRO55
value|0xcb7910de
end_define

begin_define
define|#
directive|define
name|APPLE_MACBOOKPRO71
value|0xcb8910de
end_define

begin_comment
comment|/* LG Electronics */
end_comment

begin_define
define|#
directive|define
name|LG_VENDORID
value|0x1854
end_define

begin_define
define|#
directive|define
name|LG_LW20_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LG, 0x0018)
end_define

begin_define
define|#
directive|define
name|LG_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(LG, 0xffff)
end_define

begin_comment
comment|/* Fujitsu Siemens */
end_comment

begin_define
define|#
directive|define
name|FS_VENDORID
value|0x1734
end_define

begin_define
define|#
directive|define
name|FS_PA1510_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FS, 0x10b8)
end_define

begin_define
define|#
directive|define
name|FS_SI1848_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FS, 0x10cd)
end_define

begin_define
define|#
directive|define
name|FS_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FS, 0xffff)
end_define

begin_comment
comment|/* Fujitsu Limited */
end_comment

begin_define
define|#
directive|define
name|FL_VENDORID
value|0x10cf
end_define

begin_define
define|#
directive|define
name|FL_S7020D_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FL, 0x1326)
end_define

begin_define
define|#
directive|define
name|FL_U1010_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FL, 0x142d)
end_define

begin_define
define|#
directive|define
name|FL_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(FL, 0xffff)
end_define

begin_comment
comment|/* Toshiba */
end_comment

begin_define
define|#
directive|define
name|TOSHIBA_VENDORID
value|0x1179
end_define

begin_define
define|#
directive|define
name|TOSHIBA_U200_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(TOSHIBA, 0x0001)
end_define

begin_define
define|#
directive|define
name|TOSHIBA_A135_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(TOSHIBA, 0xff01)
end_define

begin_define
define|#
directive|define
name|TOSHIBA_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(TOSHIBA, 0xffff)
end_define

begin_comment
comment|/* Micro-Star International (MSI) */
end_comment

begin_define
define|#
directive|define
name|MSI_VENDORID
value|0x1462
end_define

begin_define
define|#
directive|define
name|MSI_MS1034_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(MSI, 0x0349)
end_define

begin_define
define|#
directive|define
name|MSI_MS034A_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(MSI, 0x034a)
end_define

begin_define
define|#
directive|define
name|MSI_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(MSI, 0xffff)
end_define

begin_comment
comment|/* Giga-Byte Technology */
end_comment

begin_define
define|#
directive|define
name|GB_VENDORID
value|0x1458
end_define

begin_define
define|#
directive|define
name|GB_G33S2H_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(GB, 0xa022)
end_define

begin_define
define|#
directive|define
name|GP_ALL_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(GB, 0xffff)
end_define

begin_comment
comment|/* Uniwill ? */
end_comment

begin_define
define|#
directive|define
name|UNIWILL_VENDORID
value|0x1584
end_define

begin_define
define|#
directive|define
name|UNIWILL_9075_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(UNIWILL, 0x9075)
end_define

begin_define
define|#
directive|define
name|UNIWILL_9080_SUBVENDOR
value|HDA_MODEL_CONSTRUCT(UNIWILL, 0x9080)
end_define

begin_comment
comment|/* All codecs you can eat... */
end_comment

begin_define
define|#
directive|define
name|HDA_CODEC_CONSTRUCT
parameter_list|(
name|vendor
parameter_list|,
name|id
parameter_list|)
define|\
value|(((uint32_t)(vendor##_VENDORID)<< 16) | ((id)& 0xffff))
end_define

begin_comment
comment|/* Cirrus Logic */
end_comment

begin_define
define|#
directive|define
name|CIRRUSLOGIC_VENDORID
value|0x1013
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CS4206
value|HDA_CODEC_CONSTRUCT(CIRRUSLOGIC, 0x4206)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CS4207
value|HDA_CODEC_CONSTRUCT(CIRRUSLOGIC, 0x4207)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CS4210
value|HDA_CODEC_CONSTRUCT(CIRRUSLOGIC, 0x4210)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CSXXXX
value|HDA_CODEC_CONSTRUCT(CIRRUSLOGIC, 0xffff)
end_define

begin_comment
comment|/* Realtek */
end_comment

begin_define
define|#
directive|define
name|REALTEK_VENDORID
value|0x10ec
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC221
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0221)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC225
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0225)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC231
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0231)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC233
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0233)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC234
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0234)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC235
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0235)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC255
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0255)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC256
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0256)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC260
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0260)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC262
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0262)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC267
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0267)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC268
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0268)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC269
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0269)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC270
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0270)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC272
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0272)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC273
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0273)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC274
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0274)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC275
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0275)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC276
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0276)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC280
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0280)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC282
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0282)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC283
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0283)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC284
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0284)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC285
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0285)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC286
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0286)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC288
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0288)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC290
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0290)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC292
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0292)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC293
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0293)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC294
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0294)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC295
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0295)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC298
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0298)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC299
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0299)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC292
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0292)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC295
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0295)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC660
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0660)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC662
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0662)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC663
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0663)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC665
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0665)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC670
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0670)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC671
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0671)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC680
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0680)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC700
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0700)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC701
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0701)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC703
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0703)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC861
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0861)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC861VD
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0862)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC880
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0880)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC882
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0882)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC883
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0883)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC885
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0885)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC887
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0887)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC888
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0888)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC889
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0889)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC892
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0892)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC899
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0899)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC1150
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x0900)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALC1220
value|HDA_CODEC_CONSTRUCT(REALTEK, 0x1220)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ALCXXXX
value|HDA_CODEC_CONSTRUCT(REALTEK, 0xffff)
end_define

begin_comment
comment|/* Motorola */
end_comment

begin_define
define|#
directive|define
name|MOTO_VENDORID
value|0x1057
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_MOTOXXXX
value|HDA_CODEC_CONSTRUCT(MOTO, 0xffff)
end_define

begin_comment
comment|/* Creative */
end_comment

begin_define
define|#
directive|define
name|CREATIVE_VENDORID
value|0x1102
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CA0110
value|HDA_CODEC_CONSTRUCT(CREATIVE, 0x000a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CA0110_2
value|HDA_CODEC_CONSTRUCT(CREATIVE, 0x000b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_SB0880
value|HDA_CODEC_CONSTRUCT(CREATIVE, 0x000d)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CA0132
value|HDA_CODEC_CONSTRUCT(CREATIVE, 0x0011)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CAXXXX
value|HDA_CODEC_CONSTRUCT(CREATIVE, 0xffff)
end_define

begin_comment
comment|/* Analog Devices */
end_comment

begin_define
define|#
directive|define
name|ANALOGDEVICES_VENDORID
value|0x11d4
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1884A
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x184a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1882
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1882)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1883
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1883)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1884
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1884)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1984A
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x194a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1984B
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x194b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1981HD
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1981)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1983
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1983)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1984
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1984)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1986A
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1986)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1987
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1987)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1988
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x1988)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1988B
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x198b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1882A
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x882a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1989A
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x989a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AD1989B
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0x989b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ADXXXX
value|HDA_CODEC_CONSTRUCT(ANALOGDEVICES, 0xffff)
end_define

begin_comment
comment|/* CMedia */
end_comment

begin_define
define|#
directive|define
name|CMEDIA_VENDORID
value|0x13f6
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CMI9880
value|HDA_CODEC_CONSTRUCT(CMEDIA, 0x9880)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CMIXXXX
value|HDA_CODEC_CONSTRUCT(CMEDIA, 0xffff)
end_define

begin_define
define|#
directive|define
name|CMEDIA2_VENDORID
value|0x434d
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CMI98802
value|HDA_CODEC_CONSTRUCT(CMEDIA2, 0x4980)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CMIXXXX2
value|HDA_CODEC_CONSTRUCT(CMEDIA2, 0xffff)
end_define

begin_comment
comment|/* Sigmatel */
end_comment

begin_define
define|#
directive|define
name|SIGMATEL_VENDORID
value|0x8384
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9230X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7612)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9230D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7613)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9229X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7614)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9229D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7615)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9228X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7616)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9228D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7617)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9227X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7618)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9227D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7619)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9274
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7620)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9274D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7621)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9273X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7622)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9273D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7623)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9272X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7624)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9272D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7625)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9271X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7626)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9271D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7627)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9274X5NH
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7628)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9274D5NH
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7629)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9250
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7634)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9251
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7636)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD700X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7638)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD700D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7639)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD206X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7645)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD206D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7646)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CXD9872RDK
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7661)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9872AK
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7662)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CXD9872AKD
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7664)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9221
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7680)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC922XD
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7681)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9221_A2
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7682)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9221D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7683)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9220
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7690)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9200D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7691)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD005
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7698)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD005D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7699)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9205X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a0)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9205D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9204X
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9204D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9255
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a4)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9255D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a5)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9254
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a6)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9254D
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x76a7)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9220_A2
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7880)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STAC9220_A1
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0x7882)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_STACXXXX
value|HDA_CODEC_CONSTRUCT(SIGMATEL, 0xffff)
end_define

begin_comment
comment|/* IDT */
end_comment

begin_define
define|#
directive|define
name|IDT_VENDORID
value|0x111d
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD75BX
value|HDA_CODEC_CONSTRUCT(IDT, 0x7603)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD83C1X
value|HDA_CODEC_CONSTRUCT(IDT, 0x7604)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD81B1X
value|HDA_CODEC_CONSTRUCT(IDT, 0x7605)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD75B3
value|HDA_CODEC_CONSTRUCT(IDT, 0x7608)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD73D1
value|HDA_CODEC_CONSTRUCT(IDT, 0x7674)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD73C1
value|HDA_CODEC_CONSTRUCT(IDT, 0x7675)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD73E1
value|HDA_CODEC_CONSTRUCT(IDT, 0x7676)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B8
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b0)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B8_2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B7
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B7_2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B6
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b4)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B6_2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b5)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b6)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD71B5_2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76b7)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89C3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c0)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89C2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89C1
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89B3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89B2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c4)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89B1
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c5)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89E3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c6)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89E2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c7)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89E1
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c8)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89D3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76c9)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89D2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ca)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89D1
value|HDA_CODEC_CONSTRUCT(IDT, 0x76cb)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89F3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76cc)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89F2
value|HDA_CODEC_CONSTRUCT(IDT, 0x76cd)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD89F1
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ce)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD87B1_3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76d1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD83C1C
value|HDA_CODEC_CONSTRUCT(IDT, 0x76d4)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD81B1C
value|HDA_CODEC_CONSTRUCT(IDT, 0x76d5)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD87B2_4
value|HDA_CODEC_CONSTRUCT(IDT, 0x76d9)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD93BXX
value|HDA_CODEC_CONSTRUCT(IDT, 0x76df)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD91BXX
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e0)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD98BXX
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD99BXX
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e5)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD90BXX
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e7)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B1X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e8)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B2X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76e9)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B3X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ea)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C1X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76eb)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C2X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ec)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C3X5
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ed)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B1X3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ee)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B2X3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76ef)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66B3X3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76f0)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C1X3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76f1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C2X3
value|HDA_CODEC_CONSTRUCT(IDT, 0x76f2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDT92HD66C3_65
value|HDA_CODEC_CONSTRUCT(IDT, 0x76f3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_IDTXXXX
value|HDA_CODEC_CONSTRUCT(IDT, 0xffff)
end_define

begin_comment
comment|/* Silicon Image */
end_comment

begin_define
define|#
directive|define
name|SII_VENDORID
value|0x1095
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_SII1390
value|HDA_CODEC_CONSTRUCT(SII, 0x1390)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_SII1392
value|HDA_CODEC_CONSTRUCT(SII, 0x1392)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_SIIXXXX
value|HDA_CODEC_CONSTRUCT(SII, 0xffff)
end_define

begin_comment
comment|/* Lucent/Agere */
end_comment

begin_define
define|#
directive|define
name|AGERE_VENDORID
value|0x11c1
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_AGEREXXXX
value|HDA_CODEC_CONSTRUCT(AGERE, 0xffff)
end_define

begin_comment
comment|/* Conexant */
end_comment

begin_define
define|#
directive|define
name|CONEXANT_VENDORID
value|0x14f1
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20549
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5045)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20551
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5047)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20561
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5051)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20582
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5066)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20583
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5067)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20584
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5068)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20585
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5069)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20588
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x506c)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20590
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x506e)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20631
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5097)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20632
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5098)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20641
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50a1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20642
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50a2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20651
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50ab)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20652
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50ac)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20664
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50b8)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20665
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50b9)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX21722
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50f1)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20722
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50f2)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX21724
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50f3)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20724
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x50f4)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20751
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x510f)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20751_2
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5110)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20753
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5111)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20755
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5113)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20756
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5114)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20757
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x5115)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CX20952
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0x51d7)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CXXXXX
value|HDA_CODEC_CONSTRUCT(CONEXANT, 0xffff)
end_define

begin_comment
comment|/* VIA */
end_comment

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708_8
value|HDA_CODEC_CONSTRUCT(VIA, 0x1708)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708_9
value|HDA_CODEC_CONSTRUCT(VIA, 0x1709)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708_A
value|HDA_CODEC_CONSTRUCT(VIA, 0x170a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708_B
value|HDA_CODEC_CONSTRUCT(VIA, 0x170b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_0
value|HDA_CODEC_CONSTRUCT(VIA, 0xe710)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_1
value|HDA_CODEC_CONSTRUCT(VIA, 0xe711)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_2
value|HDA_CODEC_CONSTRUCT(VIA, 0xe712)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_3
value|HDA_CODEC_CONSTRUCT(VIA, 0xe713)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_4
value|HDA_CODEC_CONSTRUCT(VIA, 0xe714)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_5
value|HDA_CODEC_CONSTRUCT(VIA, 0xe715)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_6
value|HDA_CODEC_CONSTRUCT(VIA, 0xe716)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1709_7
value|HDA_CODEC_CONSTRUCT(VIA, 0xe717)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_0
value|HDA_CODEC_CONSTRUCT(VIA, 0xe720)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_1
value|HDA_CODEC_CONSTRUCT(VIA, 0xe721)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_2
value|HDA_CODEC_CONSTRUCT(VIA, 0xe722)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_3
value|HDA_CODEC_CONSTRUCT(VIA, 0xe723)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_4
value|HDA_CODEC_CONSTRUCT(VIA, 0xe724)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_5
value|HDA_CODEC_CONSTRUCT(VIA, 0xe725)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_6
value|HDA_CODEC_CONSTRUCT(VIA, 0xe726)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708B_7
value|HDA_CODEC_CONSTRUCT(VIA, 0xe727)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_1
value|HDA_CODEC_CONSTRUCT(VIA, 0x1397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_2
value|HDA_CODEC_CONSTRUCT(VIA, 0x2397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_3
value|HDA_CODEC_CONSTRUCT(VIA, 0x3397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_4
value|HDA_CODEC_CONSTRUCT(VIA, 0x4397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_5
value|HDA_CODEC_CONSTRUCT(VIA, 0x5397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_6
value|HDA_CODEC_CONSTRUCT(VIA, 0x6397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1708S_7
value|HDA_CODEC_CONSTRUCT(VIA, 0x7397)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_1
value|HDA_CODEC_CONSTRUCT(VIA, 0x1398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_2
value|HDA_CODEC_CONSTRUCT(VIA, 0x2398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_3
value|HDA_CODEC_CONSTRUCT(VIA, 0x3398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_4
value|HDA_CODEC_CONSTRUCT(VIA, 0x4398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_5
value|HDA_CODEC_CONSTRUCT(VIA, 0x5398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_6
value|HDA_CODEC_CONSTRUCT(VIA, 0x6398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1702_7
value|HDA_CODEC_CONSTRUCT(VIA, 0x7398)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1716S_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0433)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1716S_1
value|HDA_CODEC_CONSTRUCT(VIA, 0xa721)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1718S_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0428)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1718S_1
value|HDA_CODEC_CONSTRUCT(VIA, 0x4428)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1802_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0446)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1802_1
value|HDA_CODEC_CONSTRUCT(VIA, 0x8446)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1812
value|HDA_CODEC_CONSTRUCT(VIA, 0x0448)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1818S
value|HDA_CODEC_CONSTRUCT(VIA, 0x0440)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT1828S
value|HDA_CODEC_CONSTRUCT(VIA, 0x4441)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT2002P_0
value|HDA_CODEC_CONSTRUCT(VIA, 0x0438)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT2002P_1
value|HDA_CODEC_CONSTRUCT(VIA, 0x4438)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VT2020
value|HDA_CODEC_CONSTRUCT(VIA, 0x0441)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_VTXXXX
value|HDA_CODEC_CONSTRUCT(VIA, 0xffff)
end_define

begin_comment
comment|/* ATI */
end_comment

begin_define
define|#
directive|define
name|HDA_CODEC_ATIRS600_1
value|HDA_CODEC_CONSTRUCT(ATI, 0x793c)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ATIRS600_2
value|HDA_CODEC_CONSTRUCT(ATI, 0x7919)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ATIRS690
value|HDA_CODEC_CONSTRUCT(ATI, 0x791a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ATIR6XX
value|HDA_CODEC_CONSTRUCT(ATI, 0xaa01)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_ATIXXXX
value|HDA_CODEC_CONSTRUCT(ATI, 0xffff)
end_define

begin_comment
comment|/* NVIDIA */
end_comment

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP78
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0002)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP78_2
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0003)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP78_3
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0005)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP78_4
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0006)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP7A
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0007)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGT220
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x000a)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGT21X
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x000b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP89
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x000c)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGT240
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x000d)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGTS450
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0011)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGT440
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0014)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGTX550
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0015)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAGTX570
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0018)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIATEGRA30
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0020)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIATEGRA114
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0022)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIATEGRA124
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0028)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIATEGRA210
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0029)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP67
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x0067)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAMCP73
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0x8001)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_NVIDIAXXXX
value|HDA_CODEC_CONSTRUCT(NVIDIA, 0xffff)
end_define

begin_comment
comment|/* Chrontel */
end_comment

begin_define
define|#
directive|define
name|CHRONTEL_VENDORID
value|0x17e8
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_CHXXXX
value|HDA_CODEC_CONSTRUCT(CHRONTEL, 0xffff)
end_define

begin_comment
comment|/* INTEL */
end_comment

begin_define
define|#
directive|define
name|HDA_CODEC_INTELIP
value|HDA_CODEC_CONSTRUCT(INTEL, 0x0054)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELBL
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2801)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELCA
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2802)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELEL
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2803)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELIP2
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2804)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELCPT
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2805)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELPPT
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2806)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELHSW
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2807)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELBDW
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2808)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELSKLK
value|HDA_CODEC_CONSTRUCT(INTEL, 0x2809)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELKBLK
value|HDA_CODEC_CONSTRUCT(INTEL, 0x280b)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELCL
value|HDA_CODEC_CONSTRUCT(INTEL, 0x29fb)
end_define

begin_define
define|#
directive|define
name|HDA_CODEC_INTELXXXX
value|HDA_CODEC_CONSTRUCT(INTEL, 0xffff)
end_define

begin_comment
comment|/****************************************************************************  * Helper Macros  ****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HDA_DMA_ALIGNMENT
value|128
end_define

begin_define
define|#
directive|define
name|HDA_BDL_MIN
value|2
end_define

begin_define
define|#
directive|define
name|HDA_BDL_MAX
value|256
end_define

begin_define
define|#
directive|define
name|HDA_BDL_DEFAULT
value|HDA_BDL_MIN
end_define

begin_define
define|#
directive|define
name|HDA_BLK_MIN
value|HDA_DMA_ALIGNMENT
end_define

begin_define
define|#
directive|define
name|HDA_BLK_ALIGN
value|(~(HDA_BLK_MIN - 1))
end_define

begin_define
define|#
directive|define
name|HDA_BUFSZ_MIN
value|(HDA_BDL_MIN * HDA_BLK_MIN)
end_define

begin_define
define|#
directive|define
name|HDA_BUFSZ_MAX
value|262144
end_define

begin_define
define|#
directive|define
name|HDA_BUFSZ_DEFAULT
value|65536
end_define

begin_define
define|#
directive|define
name|HDA_GPIO_MAX
value|8
end_define

begin_define
define|#
directive|define
name|HDA_DEV_MATCH
parameter_list|(
name|fl
parameter_list|,
name|v
parameter_list|)
value|((fl) == (v) || \ 				(fl) == 0xffffffff || \ 				(((fl)& 0xffff0000) == 0xffff0000&& \ 				((fl)& 0x0000ffff) == ((v)& 0x0000ffff)) || \ 				(((fl)& 0x0000ffff) == 0x0000ffff&& \ 				((fl)& 0xffff0000) == ((v)& 0xffff0000)))
end_define

begin_define
define|#
directive|define
name|HDA_MATCH_ALL
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|HDA_INVALID
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|HDA_BOOTVERBOSE
parameter_list|(
name|stmt
parameter_list|)
value|do {			\ 	if (bootverbose != 0 || snd_verbose> 3) {	\ 		stmt					\ 	}						\ } while (0)
end_define

begin_define
define|#
directive|define
name|HDA_BOOTHVERBOSE
parameter_list|(
name|stmt
parameter_list|)
value|do {			\ 	if (snd_verbose> 3) {				\ 		stmt					\ 	}						\ } while (0)
end_define

begin_define
define|#
directive|define
name|hda_command
parameter_list|(
name|dev
parameter_list|,
name|verb
parameter_list|)
define|\
value|HDAC_CODEC_COMMAND(device_get_parent(dev), (dev), (verb))
end_define

begin_typedef
typedef|typedef
name|int
name|nid_t
typedef|;
end_typedef

begin_comment
comment|/****************************************************************************  * Simplified Accessors for HDA devices  ****************************************************************************/
end_comment

begin_enum
enum|enum
name|hdac_device_ivars
block|{
name|HDA_IVAR_CODEC_ID
block|,
name|HDA_IVAR_NODE_ID
block|,
name|HDA_IVAR_VENDOR_ID
block|,
name|HDA_IVAR_DEVICE_ID
block|,
name|HDA_IVAR_REVISION_ID
block|,
name|HDA_IVAR_STEPPING_ID
block|,
name|HDA_IVAR_SUBVENDOR_ID
block|,
name|HDA_IVAR_SUBDEVICE_ID
block|,
name|HDA_IVAR_SUBSYSTEM_ID
block|,
name|HDA_IVAR_NODE_TYPE
block|,
name|HDA_IVAR_DMA_NOCACHE
block|,
name|HDA_IVAR_STRIPES_MASK
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|HDA_ACCESSOR
parameter_list|(
name|var
parameter_list|,
name|ivar
parameter_list|,
name|type
parameter_list|)
define|\
value|__BUS_ACCESSOR(hda, var, HDA, ivar, type)
end_define

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|codec_id
argument_list|,
name|CODEC_ID
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|node_id
argument_list|,
name|NODE_ID
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|vendor_id
argument_list|,
name|VENDOR_ID
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|device_id
argument_list|,
name|DEVICE_ID
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|revision_id
argument_list|,
name|REVISION_ID
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|stepping_id
argument_list|,
name|STEPPING_ID
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|subvendor_id
argument_list|,
name|SUBVENDOR_ID
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|subdevice_id
argument_list|,
name|SUBDEVICE_ID
argument_list|,
name|uint16_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|subsystem_id
argument_list|,
name|SUBSYSTEM_ID
argument_list|,
name|uint32_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|node_type
argument_list|,
name|NODE_TYPE
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|dma_nocache
argument_list|,
name|DMA_NOCACHE
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|HDA_ACCESSOR
argument_list|(
name|stripes_mask
argument_list|,
name|STRIPES_MASK
argument_list|,
name|uint8_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|PCIS_MULTIMEDIA_HDA
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

