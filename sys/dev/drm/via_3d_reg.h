begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 1998-2003 VIA Technologies, Inc. All Rights Reserved.  * Copyright 2001-2003 S3 Graphics, Inc. All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * VIA, S3 GRAPHICS, AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|VIA_3D_REG_H
end_ifndef

begin_define
define|#
directive|define
name|VIA_3D_REG_H
end_define

begin_define
define|#
directive|define
name|HC_REG_BASE
value|0x0400
end_define

begin_define
define|#
directive|define
name|HC_REG_TRANS_SPACE
value|0x0040
end_define

begin_define
define|#
directive|define
name|HC_ParaN_MASK
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|HC_Para_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|HC_SubA_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|HC_SubA_SHIFT
value|24
end_define

begin_comment
comment|/* Transmission Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_REG_TRANS_SET
value|0x003c
end_define

begin_define
define|#
directive|define
name|HC_ParaSubType_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|HC_ParaType_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_ParaOS_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_ParaAdr_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_ParaSubType_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HC_ParaType_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_ParaOS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_ParaAdr_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_ParaType_CmdVdata
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_ParaType_NotTex
value|0x0001
end_define

begin_define
define|#
directive|define
name|HC_ParaType_Tex
value|0x0002
end_define

begin_define
define|#
directive|define
name|HC_ParaType_Palette
value|0x0003
end_define

begin_define
define|#
directive|define
name|HC_ParaType_PreCR
value|0x0010
end_define

begin_define
define|#
directive|define
name|HC_ParaType_Auto
value|0x00fe
end_define

begin_comment
comment|/* Transmission Space  */
end_comment

begin_define
define|#
directive|define
name|HC_REG_Hpara0
value|0x0040
end_define

begin_define
define|#
directive|define
name|HC_REG_HpataAF
value|0x02fc
end_define

begin_comment
comment|/* Read  */
end_comment

begin_define
define|#
directive|define
name|HC_REG_HREngSt
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_REG_HRFIFOempty
value|0x0004
end_define

begin_define
define|#
directive|define
name|HC_REG_HRFIFOfull
value|0x0008
end_define

begin_define
define|#
directive|define
name|HC_REG_HRErr
value|0x000c
end_define

begin_define
define|#
directive|define
name|HC_REG_FIFOstatus
value|0x0010
end_define

begin_comment
comment|/* HC_REG_HREngSt          0x0000  */
end_comment

begin_define
define|#
directive|define
name|HC_HDASZC_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HSGEMI_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HLGEMISt_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HCRSt_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HSE0St_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HSE1St_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HPESt_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HXESt_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HBESt_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HE2St_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HE3St_MASK
value|0x00000001
end_define

begin_comment
comment|/* HC_REG_HRFIFOempty      0x0004  */
end_comment

begin_define
define|#
directive|define
name|HC_HRZDempty_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HRTXAempty_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HRTXDempty_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HWZDempty_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HWCDempty_MASK
value|0x00000001
end_define

begin_comment
comment|/* HC_REG_HRFIFOfull       0x0008  */
end_comment

begin_define
define|#
directive|define
name|HC_HRZDfull_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HRTXAfull_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HRTXDfull_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HWZDfull_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HWCDfull_MASK
value|0x00000001
end_define

begin_comment
comment|/* HC_REG_HRErr            0x000c  */
end_comment

begin_define
define|#
directive|define
name|HC_HAGPCMErr_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HC_HAGPCMErrC_MASK
value|0x70000000
end_define

begin_comment
comment|/* HC_REG_FIFOstatus       0x0010  */
end_comment

begin_define
define|#
directive|define
name|HC_HRFIFOATall_MASK
value|0x80000000
end_define

begin_define
define|#
directive|define
name|HC_HRFIFOATbusy_MASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|HC_HRATFGMDo_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HRATFGMDi_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HRATFRZD_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HRATFRTXA_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HRATFRTXD_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HRATFWZD_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HRATFWCD_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HRATTXTAG_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HRATTXCH_MASK
value|0x00000001
end_define

begin_comment
comment|/* AGP Command Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HAGPBstL
value|0x0060
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBendL
value|0x0061
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPCMNT
value|0x0062
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBpL
value|0x0063
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBpH
value|0x0064
end_define

begin_comment
comment|/* HC_SubA_HAGPCMNT        0x0062  */
end_comment

begin_define
define|#
directive|define
name|HC_HAGPCMNT_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HCmdErrClr_MASK
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HC_HAGPBendH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HAGPBstH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HAGPBendH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HAGPBstH_SHIFT
value|0
end_define

begin_comment
comment|/* HC_SubA_HAGPBpL         0x0063  */
end_comment

begin_define
define|#
directive|define
name|HC_HAGPBpL_MASK
value|0x00fffffc
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_PAUSE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_JUMP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_STOP
value|0x00000002
end_define

begin_comment
comment|/* HC_SubA_HAGPBpH         0x0064  */
end_comment

begin_define
define|#
directive|define
name|HC_HAGPBpH_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* Miscellaneous Settings  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HClipTB
value|0x0070
end_define

begin_define
define|#
directive|define
name|HC_SubA_HClipLR
value|0x0071
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipTL
value|0x0072
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipBL
value|0x0073
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipLL
value|0x0074
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipRL
value|0x0075
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipTBH
value|0x0076
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFPClipLRH
value|0x0077
end_define

begin_define
define|#
directive|define
name|HC_SubA_HLP
value|0x0078
end_define

begin_define
define|#
directive|define
name|HC_SubA_HLPRF
value|0x0079
end_define

begin_define
define|#
directive|define
name|HC_SubA_HSolidCL
value|0x007a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HPixGC
value|0x007b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HSPXYOS
value|0x007c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HVertexCNT
value|0x007d
end_define

begin_define
define|#
directive|define
name|HC_HClipT_MASK
value|0x00fff000
end_define

begin_define
define|#
directive|define
name|HC_HClipT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HClipB_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|HC_HClipB_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_HClipL_MASK
value|0x00fff000
end_define

begin_define
define|#
directive|define
name|HC_HClipL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HClipR_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|HC_HClipR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_HFPClipBH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HFPClipBH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HFPClipTH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HFPClipTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_HFPClipRH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HFPClipRH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HFPClipLH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HFPClipLH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_HSolidCH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HPixGC_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HSPXOS_MASK
value|0x00fff000
end_define

begin_define
define|#
directive|define
name|HC_HSPXOS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HSPYOS_MASK
value|0x00000fff
end_define

begin_comment
comment|/* Command  * Command A  */
end_comment

begin_define
define|#
directive|define
name|HC_HCmdHeader_MASK
value|0xfe000000
end_define

begin_comment
comment|/*0xffe00000 */
end_comment

begin_define
define|#
directive|define
name|HC_HE3Fire_MASK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HPMType_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HEFlag_MASK
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|HC_HShading_MASK
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|HC_HPMValidN_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HPLEND_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_Style_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_ChgA_MASK
value|0x00000030
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_ChgB_MASK
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_ChgC_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HPMType_Point
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HPMType_Line
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HPMType_Tri
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HPMType_TriWF
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HC_HEFlag_NoAA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HEFlag_ab
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HC_HEFlag_bc
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HEFlag_ca
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HC_HShading_Solid
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HShading_FlatA
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HShading_FlatB
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HShading_FlatC
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|HC_HShading_Gouraud
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_Full
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_AFP
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_One
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_NewA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_AA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_AB
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_AC
value|0x00000030
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_NewB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_BA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_BB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_BC
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_NewC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_CA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_CB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HVCycle_CC
value|0x00000003
end_define

begin_comment
comment|/* Command B  */
end_comment

begin_define
define|#
directive|define
name|HC_HLPrst_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HLLastP_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_MASK
value|0x00007f80
end_define

begin_define
define|#
directive|define
name|HC_HBFace_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_H2nd1VT_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_X
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_Y
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_Z
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_W
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_Cd
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_Cs
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_S
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HVPMSK_T
value|0x00000080
end_define

begin_comment
comment|/* Enable Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HEnable
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_HenTXEnvMap_MASK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HenVertexCNT_MASK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HenCPUDAZ_MASK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HenDASZWC_MASK
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HC_HenFBCull_MASK
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HenCW_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HenAA_MASK
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HC_HenST_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HenZT_MASK
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HC_HenZW_MASK
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HC_HenAT_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HenAW_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HenSP_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HenLP_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HenTXCH_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HenTXMP_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HenTXPP_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HenTXTR_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HenCS_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HenFOG_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HenABL_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HenDT_MASK
value|0x00000001
end_define

begin_comment
comment|/* Z Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HZWBBasL
value|0x0010
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWBBasH
value|0x0011
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWBType
value|0x0012
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZBiasL
value|0x0013
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWBend
value|0x0014
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWTMD
value|0x0015
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWCDL
value|0x0016
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWCTAGnum
value|0x0017
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZCYNum
value|0x0018
end_define

begin_define
define|#
directive|define
name|HC_SubA_HZWCFire
value|0x0019
end_define

begin_comment
comment|/* HC_SubA_HZWBType  */
end_comment

begin_define
define|#
directive|define
name|HC_HZWBType_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HZBiasedWB_MASK
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HC_HZONEasFF_MASK
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HZOONEasFF_MASK
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HZWBFM_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HZWBLoc_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HZWBPit_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|HC_HZWBFM_16
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HZWBFM_32
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HZWBFM_24
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HZWBLoc_Local
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HZWBLoc_SyS
value|0x00004000
end_define

begin_comment
comment|/* HC_SubA_HZWBend  */
end_comment

begin_define
define|#
directive|define
name|HC_HZWBend_MASK
value|0x00ffe000
end_define

begin_define
define|#
directive|define
name|HC_HZBiasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HZWBend_SHIFT
value|10
end_define

begin_comment
comment|/* HC_SubA_HZWTMD  */
end_comment

begin_define
define|#
directive|define
name|HC_HZWTMD_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HEBEBias_MASK
value|0x00007f00
end_define

begin_define
define|#
directive|define
name|HC_HZNF_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_NeverPass
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_LT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_EQ
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_LE
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_GT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_NE
value|0x00050000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_GE
value|0x00060000
end_define

begin_define
define|#
directive|define
name|HC_HZWTMD_AllPass
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HEBEBias_SHIFT
value|8
end_define

begin_comment
comment|/* HC_SubA_HZWCDL          0x0016  */
end_comment

begin_define
define|#
directive|define
name|HC_HZWCDL_MASK
value|0x00ffffff
end_define

begin_comment
comment|/* HC_SubA_HZWCTAGnum      0x0017  */
end_comment

begin_define
define|#
directive|define
name|HC_HZWCTAGnum_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HZWCTAGnum_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HZWCDH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HZWCDH_SHIFT
value|0
end_define

begin_comment
comment|/* HC_SubA_HZCYNum         0x0018  */
end_comment

begin_define
define|#
directive|define
name|HC_HZCYNum_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HZCYNum_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HZWCQWnum_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|HC_HZWCQWnum_SHIFT
value|0
end_define

begin_comment
comment|/* HC_SubA_HZWCFire        0x0019  */
end_comment

begin_define
define|#
directive|define
name|HC_ZWCFire_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HZWCQWnumLast_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|HC_HZWCQWnumLast_SHIFT
value|0
end_define

begin_comment
comment|/* Stencil Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HSTREF
value|0x0023
end_define

begin_define
define|#
directive|define
name|HC_SubA_HSTMD
value|0x0024
end_define

begin_comment
comment|/* HC_SubA_HSBFM  */
end_comment

begin_define
define|#
directive|define
name|HC_HSBFM_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HSBLoc_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HSBPit_MASK
value|0x00003fff
end_define

begin_comment
comment|/* HC_SubA_HSTREF  */
end_comment

begin_define
define|#
directive|define
name|HC_HSTREF_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPMSK_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HSTBMSK_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HSTREF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HSTOPMSK_SHIFT
value|8
end_define

begin_comment
comment|/* HC_SubA_HSTMD  */
end_comment

begin_define
define|#
directive|define
name|HC_HSTMD_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_MASK
value|0x000001c0
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_NeverPass
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_LT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_EQ
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_LE
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_GT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_NE
value|0x00050000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_GE
value|0x00060000
end_define

begin_define
define|#
directive|define
name|HC_HSTMD_AllPass
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_KEEP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_ZERO
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_REPLACE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_INCRSAT
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_DECRSAT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_INVERT
value|0x00000140
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_INCR
value|0x00000180
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSF_DECR
value|0x000001c0
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_KEEP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_ZERO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_REPLACE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_INCRSAT
value|0x00000018
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_DECRSAT
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_INVERT
value|0x00000028
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_INCR
value|0x00000030
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZF_DECR
value|0x00000038
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_KEEP
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_ZERO
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_REPLACE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_INCRSAT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_DECRSAT
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_INVERT
value|0x00000005
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_INCR
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_HSTOPSPZP_DECR
value|0x00000007
end_define

begin_comment
comment|/* Alpha Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HABBasL
value|0x0030
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABBasH
value|0x0031
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABFM
value|0x0032
end_define

begin_define
define|#
directive|define
name|HC_SubA_HATMD
value|0x0033
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLCsat
value|0x0034
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLCop
value|0x0035
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLAsat
value|0x0036
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLAop
value|0x0037
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRCa
value|0x0038
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRFCa
value|0x0039
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRCbias
value|0x003a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRCb
value|0x003b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRFCb
value|0x003c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRAa
value|0x003d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HABLRAb
value|0x003e
end_define

begin_comment
comment|/* HC_SubA_HABFM  */
end_comment

begin_define
define|#
directive|define
name|HC_HABFM_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HABLoc_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HABPit_MASK
value|0x000007ff
end_define

begin_comment
comment|/* HC_SubA_HATMD  */
end_comment

begin_define
define|#
directive|define
name|HC_HATMD_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|HC_HATREF_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HATMD_NeverPass
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HATMD_LT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HATMD_EQ
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HATMD_LE
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HC_HATMD_GT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HATMD_NE
value|0x00000500
end_define

begin_define
define|#
directive|define
name|HC_HATMD_GE
value|0x00000600
end_define

begin_define
define|#
directive|define
name|HC_HATMD_AllPass
value|0x00000700
end_define

begin_comment
comment|/* HC_SubA_HABLCsat  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLCsat_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_MASK
value|0x0000fc00
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_C_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_OPC_MASK
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_MASK
value|0x000003f0
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_C_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_OPC_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_C_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_OPC_MASK
value|0x00000007
end_define

begin_comment
comment|/*-- Define the input color.  */
end_comment

begin_define
define|#
directive|define
name|HC_XC_Csrc
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XC_Cdst
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_XC_Asrc
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_XC_Adst
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_XC_Fog
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_XC_HABLRC
value|0x00000005
end_define

begin_define
define|#
directive|define
name|HC_XC_minSrcDst
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_XC_maxSrcDst
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_XC_mimAsrcInvAdst
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_XC_OPC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XC_InvOPC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_XC_OPCp5
value|0x00000020
end_define

begin_comment
comment|/*-- Define the input Alpha  */
end_comment

begin_define
define|#
directive|define
name|HC_XA_OPA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XA_InvOPA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_XA_OPAp5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_XA_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XA_Asrc
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_XA_Adst
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_XA_Fog
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_XA_minAsrcFog
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_XA_minAsrcAdst
value|0x00000005
end_define

begin_define
define|#
directive|define
name|HC_XA_maxAsrcFog
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_XA_maxAsrcAdst
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_XA_HABLRA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_XA_minAsrcInvAdst
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_XA_HABLFRA
value|0x00000009
end_define

begin_comment
comment|/*--  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLCa_OPC
value|(HC_XC_OPC<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_InvOPC
value|(HC_XC_InvOPC<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_OPCp5
value|(HC_XC_OPCp5<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_Csrc
value|(HC_XC_Csrc<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_Cdst
value|(HC_XC_Cdst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_Asrc
value|(HC_XC_Asrc<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_Adst
value|(HC_XC_Adst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_Fog
value|(HC_XC_Fog<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_HABLRCa
value|(HC_XC_HABLRC<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_minSrcDst
value|(HC_XC_minSrcDst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLCa_maxSrcDst
value|(HC_XC_maxSrcDst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_OPC
value|(HC_XC_OPC<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_InvOPC
value|(HC_XC_InvOPC<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_OPCp5
value|(HC_XC_OPCp5<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_Csrc
value|(HC_XC_Csrc<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_Cdst
value|(HC_XC_Cdst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_Asrc
value|(HC_XC_Asrc<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_Adst
value|(HC_XC_Adst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_Fog
value|(HC_XC_Fog<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_HABLRCa
value|(HC_XC_HABLRC<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_minSrcDst
value|(HC_XC_minSrcDst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_maxSrcDst
value|(HC_XC_maxSrcDst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCa_mimAsrcInvAdst
value|(HC_XC_mimAsrcInvAdst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_HABLRCbias
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_Asrc
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_Adst
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_Fog
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HABLCbias_Cin
value|0x00000004
end_define

begin_comment
comment|/* HC_SubA_HABLCop         0x0035  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLdot_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HABLCop_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_C_MASK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_OPC_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_MASK
value|0x000000fc
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_C_MASK
value|0x000000c0
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_OPC_MASK
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|HC_HABLCshift_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_OPC
value|(HC_XC_OPC<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_InvOPC
value|(HC_XC_InvOPC<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_OPCp5
value|(HC_XC_OPCp5<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_Csrc
value|(HC_XC_Csrc<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_Cdst
value|(HC_XC_Cdst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_Asrc
value|(HC_XC_Asrc<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_Adst
value|(HC_XC_Adst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_Fog
value|(HC_XC_Fog<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_HABLRCa
value|(HC_XC_HABLRC<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_minSrcDst
value|(HC_XC_minSrcDst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLCb_maxSrcDst
value|(HC_XC_maxSrcDst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_OPC
value|(HC_XC_OPC<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_InvOPC
value|(HC_XC_InvOPC<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_OPCp5
value|(HC_XC_OPCp5<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_Csrc
value|(HC_XC_Csrc<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_Cdst
value|(HC_XC_Cdst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_Asrc
value|(HC_XC_Asrc<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_Adst
value|(HC_XC_Adst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_Fog
value|(HC_XC_Fog<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_HABLRCb
value|(HC_XC_HABLRC<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_minSrcDst
value|(HC_XC_minSrcDst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_maxSrcDst
value|(HC_XC_maxSrcDst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFCb_mimAsrcInvAdst
value|(HC_XC_mimAsrcInvAdst<< 2)
end_define

begin_comment
comment|/* HC_SubA_HABLAsat        0x0036  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLAsat_MASK
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_MASK
value|0x0000fc00
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_A_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_OPA_MASK
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_MASK
value|0x000003f0
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_A_MASK
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_OPA_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_A_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_OPA_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_OPA
value|(HC_XA_OPA<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_InvOPA
value|(HC_XA_InvOPA<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_OPAp5
value|(HC_XA_OPAp5<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_0
value|(HC_XA_0<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_Asrc
value|(HC_XA_Asrc<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_Adst
value|(HC_XA_Adst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_Fog
value|(HC_XA_Fog<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_minAsrcFog
value|(HC_XA_minAsrcFog<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_minAsrcAdst
value|(HC_XA_minAsrcAdst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_maxAsrcFog
value|(HC_XA_maxAsrcFog<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_maxAsrcAdst
value|(HC_XA_maxAsrcAdst<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLAa_HABLRA
value|(HC_XA_HABLRA<< 10)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_OPA
value|(HC_XA_OPA<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_InvOPA
value|(HC_XA_InvOPA<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_OPAp5
value|(HC_XA_OPAp5<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_0
value|(HC_XA_0<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_Asrc
value|(HC_XA_Asrc<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_Adst
value|(HC_XA_Adst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_Fog
value|(HC_XA_Fog<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_minAsrcFog
value|(HC_XA_minAsrcFog<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_minAsrcAdst
value|(HC_XA_minAsrcAdst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_maxAsrcFog
value|(HC_XA_maxAsrcFog<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_maxAsrcAdst
value|(HC_XA_maxAsrcAdst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_minAsrcInvAdst
value|(HC_XA_minAsrcInvAdst<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAa_HABLFRA
value|(HC_XA_HABLFRA<< 4)
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_HABLRAbias
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_Asrc
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_Adst
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_Fog
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HABLAbias_Aaa
value|0x00000004
end_define

begin_comment
comment|/* HC_SubA_HABLAop         0x0037  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLAop_MASK
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_MASK
value|0x00003f00
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_OPA_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_MASK
value|0x000000fc
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_OPA_MASK
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|HC_HABLAshift_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_OPA
value|(HC_XA_OPA<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_InvOPA
value|(HC_XA_InvOPA<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_OPAp5
value|(HC_XA_OPAp5<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_0
value|(HC_XA_0<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_Asrc
value|(HC_XA_Asrc<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_Adst
value|(HC_XA_Adst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_Fog
value|(HC_XA_Fog<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_minAsrcFog
value|(HC_XA_minAsrcFog<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_minAsrcAdst
value|(HC_XA_minAsrcAdst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_maxAsrcFog
value|(HC_XA_maxAsrcFog<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_maxAsrcAdst
value|(HC_XA_maxAsrcAdst<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLAb_HABLRA
value|(HC_XA_HABLRA<< 8)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_OPA
value|(HC_XA_OPA<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_InvOPA
value|(HC_XA_InvOPA<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_OPAp5
value|(HC_XA_OPAp5<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_0
value|(HC_XA_0<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_Asrc
value|(HC_XA_Asrc<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_Adst
value|(HC_XA_Adst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_Fog
value|(HC_XA_Fog<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_minAsrcFog
value|(HC_XA_minAsrcFog<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_minAsrcAdst
value|(HC_XA_minAsrcAdst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_maxAsrcFog
value|(HC_XA_maxAsrcFog<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_maxAsrcAdst
value|(HC_XA_maxAsrcAdst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_minAsrcInvAdst
value|(HC_XA_minAsrcInvAdst<< 2)
end_define

begin_define
define|#
directive|define
name|HC_HABLFAb_HABLFRA
value|(HC_XA_HABLFRA<< 2)
end_define

begin_comment
comment|/* HC_SubA_HABLRAa         0x003d  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLRAa_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HABLRFAa_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HABLRAbias_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HABLRAa_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HABLRFAa_SHIFT
value|8
end_define

begin_comment
comment|/* HC_SubA_HABLRAb         0x003e  */
end_comment

begin_define
define|#
directive|define
name|HC_HABLRAb_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HABLRFAb_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HABLRAb_SHIFT
value|8
end_define

begin_comment
comment|/* Destination Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HDBBasL
value|0x0040
end_define

begin_define
define|#
directive|define
name|HC_SubA_HDBBasH
value|0x0041
end_define

begin_define
define|#
directive|define
name|HC_SubA_HDBFM
value|0x0042
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFBBMSKL
value|0x0043
end_define

begin_define
define|#
directive|define
name|HC_SubA_HROP
value|0x0044
end_define

begin_comment
comment|/* HC_SubA_HDBFM           0x0042  */
end_comment

begin_define
define|#
directive|define
name|HC_HDBFM_MASK
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|HC_HDBLoc_MASK
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HDBPit_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_RGB555
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_RGB565
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ARGB4444
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ARGB1555
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_BGR555
value|0x00040000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_BGR565
value|0x00050000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ABGR4444
value|0x00060000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ABGR1555
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ARGB0888
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ARGB8888
value|0x00090000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ABGR0888
value|0x000a0000
end_define

begin_define
define|#
directive|define
name|HC_HDBFM_ABGR8888
value|0x000b0000
end_define

begin_define
define|#
directive|define
name|HC_HDBLoc_Local
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HDBLoc_Sys
value|0x00004000
end_define

begin_comment
comment|/* HC_SubA_HROP            0x0044  */
end_comment

begin_define
define|#
directive|define
name|HC_HROP_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HFBBMSKH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HROP_BLACK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPon
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPna
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HROP_Pn
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HC_HROP_PDna
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HROP_Dn
value|0x00000500
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPx
value|0x00000600
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPan
value|0x00000700
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPa
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPxn
value|0x00000900
end_define

begin_define
define|#
directive|define
name|HC_HROP_D
value|0x00000a00
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPno
value|0x00000b00
end_define

begin_define
define|#
directive|define
name|HC_HROP_P
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|HC_HROP_PDno
value|0x00000d00
end_define

begin_define
define|#
directive|define
name|HC_HROP_DPo
value|0x00000e00
end_define

begin_define
define|#
directive|define
name|HC_HROP_WHITE
value|0x00000f00
end_define

begin_comment
comment|/* Fog Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HFogLF
value|0x0050
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogCL
value|0x0051
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogCH
value|0x0052
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogStL
value|0x0053
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogStH
value|0x0054
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogOOdMF
value|0x0055
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogOOdEF
value|0x0056
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogEndL
value|0x0057
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFogDenst
value|0x0058
end_define

begin_comment
comment|/* HC_SubA_FogLF           0x0050  */
end_comment

begin_define
define|#
directive|define
name|HC_FogLF_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_FogEq_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_FogMD_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_FogMD_LocalFog
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_FogMD_LinearFog
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_FogMD_ExponentialFog
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_FogMD_Exponential2Fog
value|0x00000005
end_define

begin_comment
comment|/* #define HC_FogMD_FogTable       0x00000003 */
end_comment

begin_comment
comment|/* HC_SubA_HFogDenst        0x0058  */
end_comment

begin_define
define|#
directive|define
name|HC_FogDenst_MASK
value|0x001fff00
end_define

begin_define
define|#
directive|define
name|HC_FogEndL_MASK
value|0x000000ff
end_define

begin_comment
comment|/* Texture subtype definitions  */
end_comment

begin_define
define|#
directive|define
name|HC_SubType_Tex0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_SubType_Tex1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_SubType_TexGeneral
value|0x000000fe
end_define

begin_comment
comment|/* Attribute of texture n  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HTXnL0BasL
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL1BasL
value|0x0001
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL2BasL
value|0x0002
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL3BasL
value|0x0003
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL4BasL
value|0x0004
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL5BasL
value|0x0005
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL6BasL
value|0x0006
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL7BasL
value|0x0007
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL8BasL
value|0x0008
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL9BasL
value|0x0009
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLaBasL
value|0x000a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLbBasL
value|0x000b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLcBasL
value|0x000c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLdBasL
value|0x000d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLeBasL
value|0x000e
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLfBasL
value|0x000f
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL10BasL
value|0x0010
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL11BasL
value|0x0011
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL012BasH
value|0x0020
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL345BasH
value|0x0021
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL678BasH
value|0x0022
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL9abBasH
value|0x0023
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLcdeBasH
value|0x0024
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLf1011BasH
value|0x0025
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL0Pit
value|0x002b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL1Pit
value|0x002c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL2Pit
value|0x002d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL3Pit
value|0x002e
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL4Pit
value|0x002f
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL5Pit
value|0x0030
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL6Pit
value|0x0031
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL7Pit
value|0x0032
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL8Pit
value|0x0033
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL9Pit
value|0x0034
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLaPit
value|0x0035
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLbPit
value|0x0036
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLcPit
value|0x0037
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLdPit
value|0x0038
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLePit
value|0x0039
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLfPit
value|0x003a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL10Pit
value|0x003b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL11Pit
value|0x003c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL0_5WE
value|0x004b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL6_bWE
value|0x004c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLc_11WE
value|0x004d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL0_5HE
value|0x0051
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL6_bHE
value|0x0052
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLc_11HE
value|0x0053
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnL0OS
value|0x0077
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTB
value|0x0078
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnMPMD
value|0x0079
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnCLODu
value|0x007a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnFM
value|0x007b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTRCH
value|0x007c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTRCL
value|0x007d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBC
value|0x007e
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTRAH
value|0x007f
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLCsat
value|0x0080
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLCop
value|0x0081
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLMPfog
value|0x0082
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLAsat
value|0x0083
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRCa
value|0x0085
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRCb
value|0x0086
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRCc
value|0x0087
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRCbias
value|0x0088
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRAa
value|0x0089
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnTBLRFog
value|0x008a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnBumpM00
value|0x0090
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnBumpM01
value|0x0091
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnBumpM10
value|0x0092
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnBumpM11
value|0x0093
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXnLScale
value|0x0094
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTXSMD
value|0x0000
end_define

begin_comment
comment|/* HC_SubA_HTXnL012BasH    0x0020  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL0BasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1BasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2BasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1BasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2BasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnL345BasH    0x0021  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL3BasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4BasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5BasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4BasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5BasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnL678BasH    0x0022  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL6BasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7BasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8BasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7BasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8BasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnL9abBasH    0x0023  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL9BasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaBasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbBasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaBasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbBasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnLcdeBasH    0x0024  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLcBasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdBasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeBasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdBasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeBasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnLcdeBasH    0x0025  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLfBasH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10BasH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11BasH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10BasH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11BasH_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HTXnL0Pit       0x002b  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLnPit_MASK
value|0x00003fff
end_define

begin_define
define|#
directive|define
name|HC_HTXnEnPit_MASK
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLnPitE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLnPitE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnL0_5WE      0x004b  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL0WE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1WE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2WE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL3WE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4WE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5WE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1WE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2WE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL3WE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4WE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5WE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnL6_bWE      0x004c  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL6WE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7WE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8WE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL9WE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaWE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbWE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7WE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8WE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL9WE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaWE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbWE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnLc_11WE      0x004d  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLcWE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdWE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeWE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnLfWE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10WE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11WE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdWE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeWE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnLfWE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10WE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11WE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnL0_5HE      0x0051  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL0HE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1HE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2HE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL3HE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4HE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5HE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL1HE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnL2HE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL3HE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnL4HE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnL5HE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnL6_bHE      0x0052  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL6HE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7HE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8HE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnL9HE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaHE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbHE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL7HE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnL8HE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnL9HE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnLaHE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnLbHE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnLc_11HE      0x0053  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLcHE_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdHE_MASK
value|0x000000f0
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeHE_MASK
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|HC_HTXnLfHE_MASK
value|0x0000f000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10HE_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11HE_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLdHE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|HC_HTXnLeHE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnLfHE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnL10HE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnL11HE_SHIFT
value|20
end_define

begin_comment
comment|/* HC_SubA_HTXnL0OS        0x0077  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnL0OS_MASK
value|0x003ff000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLVmax_MASK
value|0x00000fc0
end_define

begin_define
define|#
directive|define
name|HC_HTXnLVmin_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|HC_HTXnL0OS_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_HTXnLVmax_SHIFT
value|6
end_define

begin_comment
comment|/* HC_SubA_HTXnTB          0x0078  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTB_MASK
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_MASK
value|0x0000e000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSs_MASK
value|0x00001c00
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_MASK
value|0x00000380
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTs_MASK
value|0x00000070
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_MASK
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|HC_HTXnTB_NoTB
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTB_TBC_S
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTB_TBC_T
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTB_TB_S
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTB_TB_T
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_Nearest
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_Linear
value|0x00002000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_NonLinear
value|0x00004000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_Sharp
value|0x00008000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSe_Flat_Gaussian_Cubic
value|0x0000c000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSs_Nearest
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSs_Linear
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSs_NonLinear
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLSs_Flat_Gaussian_Cubic
value|0x00001800
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_Nearest
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_Linear
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_NonLinear
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_Sharp
value|0x00000180
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTe_Flat_Gaussian_Cubic
value|0x00000300
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTs_Nearest
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTs_Linear
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTs_NonLinear
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLTs_Flat_Gaussian_Cubic
value|0x00000060
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_Tex0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_Nearest
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_Linear
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_NonLinear
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_Dither
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_ConstLOD
value|0x00000005
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_Ani
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_HTXnFLDs_AniDither
value|0x00000007
end_define

begin_comment
comment|/* HC_SubA_HTXnMPMD        0x0079  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnMPMD_SMASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_TMASK
value|0x00380000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLODDTf_MASK
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_HTXnXY2ST_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Tsingle
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Tclamp
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Trepeat
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Tmirror
value|0x00180000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Twrap
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Ssingle
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Sclamp
value|0x00010000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Srepeat
value|0x00020000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Smirror
value|0x00030000
end_define

begin_define
define|#
directive|define
name|HC_HTXnMPMD_Swrap
value|0x00040000
end_define

begin_comment
comment|/* HC_SubA_HTXnCLODu       0x007a  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnCLODu_MASK
value|0x000ffc00
end_define

begin_define
define|#
directive|define
name|HC_HTXnCLODd_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnCLODu_SHIFT
value|10
end_define

begin_comment
comment|/* HC_SubA_HTXnFM          0x007b  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnFM_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLoc_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_INDEX
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Intensity
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Lum
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Alpha
value|0x00180000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_DX
value|0x00280000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB16
value|0x00880000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB32
value|0x00980000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR16
value|0x00a80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR32
value|0x00b80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA16
value|0x00c80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA32
value|0x00d80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA16
value|0x00e80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA32
value|0x00f80000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BUMPMAP
value|0x00380000
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Index1
value|(HC_HTXnFM_INDEX     | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Index2
value|(HC_HTXnFM_INDEX     | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Index4
value|(HC_HTXnFM_INDEX     | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_Index8
value|(HC_HTXnFM_INDEX     | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_T1
value|(HC_HTXnFM_Intensity | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_T2
value|(HC_HTXnFM_Intensity | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_T4
value|(HC_HTXnFM_Intensity | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_T8
value|(HC_HTXnFM_Intensity | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_L1
value|(HC_HTXnFM_Lum       | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_L2
value|(HC_HTXnFM_Lum       | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_L4
value|(HC_HTXnFM_Lum       | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_L8
value|(HC_HTXnFM_Lum       | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_AL44
value|(HC_HTXnFM_Lum       | 0x00040000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_AL88
value|(HC_HTXnFM_Lum       | 0x00050000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_A1
value|(HC_HTXnFM_Alpha     | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_A2
value|(HC_HTXnFM_Alpha     | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_A4
value|(HC_HTXnFM_Alpha     | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_A8
value|(HC_HTXnFM_Alpha     | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_DX1
value|(HC_HTXnFM_DX        | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_DX23
value|(HC_HTXnFM_DX        | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_DX45
value|(HC_HTXnFM_DX        | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGB555
value|(HC_HTXnFM_ARGB16    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGB565
value|(HC_HTXnFM_ARGB16    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB1555
value|(HC_HTXnFM_ARGB16    | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB4444
value|(HC_HTXnFM_ARGB16    | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB0888
value|(HC_HTXnFM_ARGB32    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ARGB8888
value|(HC_HTXnFM_ARGB32    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGR555
value|(HC_HTXnFM_ABGR16    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGR565
value|(HC_HTXnFM_ABGR16    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR1555
value|(HC_HTXnFM_ABGR16    | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR4444
value|(HC_HTXnFM_ABGR16    | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR0888
value|(HC_HTXnFM_ABGR32    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_ABGR8888
value|(HC_HTXnFM_ABGR32    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA5550
value|(HC_HTXnFM_RGBA16    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA5551
value|(HC_HTXnFM_RGBA16    | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA4444
value|(HC_HTXnFM_RGBA16    | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA8880
value|(HC_HTXnFM_RGBA32    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_RGBA8888
value|(HC_HTXnFM_RGBA32    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA5550
value|(HC_HTXnFM_BGRA16    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA5551
value|(HC_HTXnFM_BGRA16    | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA4444
value|(HC_HTXnFM_BGRA16    | 0x00030000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA8880
value|(HC_HTXnFM_BGRA32    | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_BGRA8888
value|(HC_HTXnFM_BGRA32    | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_VU88
value|(HC_HTXnFM_BUMPMAP   | 0x00000000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_LVU655
value|(HC_HTXnFM_BUMPMAP   | 0x00010000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnFM_LVU888
value|(HC_HTXnFM_BUMPMAP   | 0x00020000)
end_define

begin_define
define|#
directive|define
name|HC_HTXnLoc_Local
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnLoc_Sys
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HTXnLoc_AGP
value|0x00000003
end_define

begin_comment
comment|/* HC_SubA_HTXnTRAH        0x007f  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTRAH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTRAL_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnTRAH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnTRAL_SHIFT
value|8
end_define

begin_comment
comment|/* HC_SubA_HTXnTBLCsat     0x0080  *-- Define the input texture.  */
end_comment

begin_define
define|#
directive|define
name|HC_XTC_TOPC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XTC_InvTOPC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_XTC_TOPCp5
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_XTC_Cbias
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XTC_InvCbias
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_XTC_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XTC_Dif
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_XTC_Spec
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_XTC_Tex
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_XTC_Cur
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_XTC_Adif
value|0x00000005
end_define

begin_define
define|#
directive|define
name|HC_XTC_Fog
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_XTC_Atex
value|0x00000007
end_define

begin_define
define|#
directive|define
name|HC_XTC_Acur
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_XTC_HTXnTBLRC
value|0x00000009
end_define

begin_define
define|#
directive|define
name|HC_XTC_Ctexnext
value|0x0000000a
end_define

begin_comment
comment|/*--  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLCsat_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_MASK
value|0x000fc000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_MASK
value|0x00001f80
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_TOPC
value|(HC_XTC_TOPC<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_InvTOPC
value|(HC_XTC_InvTOPC<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_TOPCp5
value|(HC_XTC_TOPCp5<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_0
value|(HC_XTC_0<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Dif
value|(HC_XTC_Dif<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Spec
value|(HC_XTC_Spec<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Tex
value|(HC_XTC_Tex<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Cur
value|(HC_XTC_Cur<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Adif
value|(HC_XTC_Adif<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Fog
value|(HC_XTC_Fog<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Atex
value|(HC_XTC_Atex<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Acur
value|(HC_XTC_Acur<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_HTXnTBLRC
value|(HC_XTC_HTXnTBLRC<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCa_Ctexnext
value|(HC_XTC_Ctexnext<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_TOPC
value|(HC_XTC_TOPC<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_InvTOPC
value|(HC_XTC_InvTOPC<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_TOPCp5
value|(HC_XTC_TOPCp5<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_0
value|(HC_XTC_0<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Dif
value|(HC_XTC_Dif<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Spec
value|(HC_XTC_Spec<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Tex
value|(HC_XTC_Tex<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Cur
value|(HC_XTC_Cur<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Adif
value|(HC_XTC_Adif<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Fog
value|(HC_XTC_Fog<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Atex
value|(HC_XTC_Atex<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Acur
value|(HC_XTC_Acur<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_HTXnTBLRC
value|(HC_XTC_HTXnTBLRC<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCb_Ctexnext
value|(HC_XTC_Ctexnext<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_TOPC
value|(HC_XTC_TOPC<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_InvTOPC
value|(HC_XTC_InvTOPC<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_TOPCp5
value|(HC_XTC_TOPCp5<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_0
value|(HC_XTC_0<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Dif
value|(HC_XTC_Dif<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Spec
value|(HC_XTC_Spec<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Tex
value|(HC_XTC_Tex<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Cur
value|(HC_XTC_Cur<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Adif
value|(HC_XTC_Adif<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Fog
value|(HC_XTC_Fog<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Atex
value|(HC_XTC_Atex<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Acur
value|(HC_XTC_Acur<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_HTXnTBLRC
value|(HC_XTC_HTXnTBLRC<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCc_Ctexnext
value|(HC_XTC_Ctexnext<< 0)
end_define

begin_comment
comment|/* HC_SubA_HTXnTBLCop      0x0081  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLdot_MASK
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_MASK
value|0x00380000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_MASK
value|0x0007c000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCshift_MASK
value|0x00001800
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_MASK
value|0x00000380
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_MASK
value|0x00000078
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAshift_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_Add
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_Sub
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_Min
value|0x00100000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_Max
value|0x00180000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCop_Mask
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Cbias
value|(HC_XTC_Cbias<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_InvCbias
value|(HC_XTC_InvCbias<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_0
value|(HC_XTC_0<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Dif
value|(HC_XTC_Dif<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Spec
value|(HC_XTC_Spec<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Tex
value|(HC_XTC_Tex<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Cur
value|(HC_XTC_Cur<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Adif
value|(HC_XTC_Adif<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Fog
value|(HC_XTC_Fog<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Atex
value|(HC_XTC_Atex<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_Acur
value|(HC_XTC_Acur<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCbias_HTXnTBLRC
value|(HC_XTC_HTXnTBLRC<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCshift_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCshift_2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCshift_No
value|0x00001000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLCshift_DotP
value|0x00001800
end_define

begin_comment
comment|/*=* John Sheng [2003.7.18] texture combine *=*/
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLDOT3
value|0x00080000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLDOT4
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_Add
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_Sub
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_Min
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_Max
value|0x00000180
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAop_Mask
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_Inv
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_Adif
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_Fog
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_Acur
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_HTXnTBLRAbias
value|0x00000018
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAbias_Atex
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAshift_1
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAshift_2
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAshift_No
value|0x00000002
end_define

begin_comment
comment|/* #define HC_HTXnTBLAshift_DotP   0x00000003 */
end_comment

begin_comment
comment|/* HC_SubA_HTXnTBLMPFog    0x0082  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_MASK
value|0x00e00000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_Adif
value|0x00200000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_Fog
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_Atex
value|0x00600000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_Acur
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLMPfog_GHTXnTBLRFog
value|0x00a00000
end_define

begin_comment
comment|/* HC_SubA_HTXnTBLAsat     0x0083  *-- Define the texture alpha input.  */
end_comment

begin_define
define|#
directive|define
name|HC_XTA_TOPA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XTA_InvTOPA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_XTA_TOPAp5
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_XTA_Adif
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_XTA_Fog
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_XTA_Acur
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_XTA_HTXnTBLRA
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_XTA_Atex
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_XTA_Atexnext
value|0x00000005
end_define

begin_comment
comment|/*--  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLAsat_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAMB_MASK
value|0x00700000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_MASK
value|0x0007c000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_MASK
value|0x00000f80
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_MASK
value|0x0000001f
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAMB_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_TOPA
value|(HC_XTA_TOPA<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_InvTOPA
value|(HC_XTA_InvTOPA<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_TOPAp5
value|(HC_XTA_TOPAp5<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_Adif
value|(HC_XTA_Adif<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_Fog
value|(HC_XTA_Fog<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_Acur
value|(HC_XTA_Acur<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_HTXnTBLRA
value|(HC_XTA_HTXnTBLRA<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_Atex
value|(HC_XTA_Atex<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAa_Atexnext
value|(HC_XTA_Atexnext<< 14)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_TOPA
value|(HC_XTA_TOPA<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_InvTOPA
value|(HC_XTA_InvTOPA<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_TOPAp5
value|(HC_XTA_TOPAp5<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_Adif
value|(HC_XTA_Adif<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_Fog
value|(HC_XTA_Fog<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_Acur
value|(HC_XTA_Acur<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_HTXnTBLRA
value|(HC_XTA_HTXnTBLRA<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_Atex
value|(HC_XTA_Atex<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAb_Atexnext
value|(HC_XTA_Atexnext<< 7)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_TOPA
value|(HC_XTA_TOPA<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_InvTOPA
value|(HC_XTA_InvTOPA<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_TOPAp5
value|(HC_XTA_TOPAp5<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_Adif
value|(HC_XTA_Adif<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_Fog
value|(HC_XTA_Fog<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_Acur
value|(HC_XTA_Acur<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_HTXnTBLRA
value|(HC_XTA_HTXnTBLRA<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_Atex
value|(HC_XTA_Atex<< 0)
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLAc_Atexnext
value|(HC_XTA_Atexnext<< 0)
end_define

begin_comment
comment|/* HC_SubA_HTXnTBLRAa      0x0089  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLRAa_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAb_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAc_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAa_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAb_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAc_SHIFT
value|0
end_define

begin_comment
comment|/* HC_SubA_HTXnTBLRFog     0x008a  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnTBLRFog_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAbias_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRFog_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HTXnTBLRAbias_SHIFT
value|0
end_define

begin_comment
comment|/* HC_SubA_HTXnLScale      0x0094  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXnLScale_MASK
value|0x0007fc00
end_define

begin_define
define|#
directive|define
name|HC_HTXnLOff_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|HC_HTXnLScale_SHIFT
value|10
end_define

begin_comment
comment|/* HC_SubA_HTXSMD          0x0000  */
end_comment

begin_define
define|#
directive|define
name|HC_HTXSMD_MASK
value|0x00000080
end_define

begin_define
define|#
directive|define
name|HC_HTXTMD_MASK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|HC_HTXNum_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|HC_HTXTRMD_MASK
value|0x00000006
end_define

begin_define
define|#
directive|define
name|HC_HTXCHCLR_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HTXNum_SHIFT
value|3
end_define

begin_comment
comment|/* Texture Palette n  */
end_comment

begin_define
define|#
directive|define
name|HC_SubType_TexPalette0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_SubType_TexPalette1
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_SubType_FogTable
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_SubType_Stipple
value|0x00000014
end_define

begin_comment
comment|/* HC_SubA_TexPalette0     0x0000  */
end_comment

begin_define
define|#
directive|define
name|HC_HTPnA_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|HC_HTPnR_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HTPnG_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HTPnB_MASK
value|0x000000ff
end_define

begin_comment
comment|/* HC_SubA_FogTable        0x0010  */
end_comment

begin_define
define|#
directive|define
name|HC_HFPn3_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|HC_HFPn2_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HFPn1_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HFPn_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HFPn3_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|HC_HFPn2_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HFPn1_SHIFT
value|8
end_define

begin_comment
comment|/* Auto Testing& Security  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HenFIFOAT
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFBDrawFirst
value|0x0004
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFBBasL
value|0x0005
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFBDst
value|0x0006
end_define

begin_comment
comment|/* HC_SubA_HenFIFOAT       0x0000  */
end_comment

begin_define
define|#
directive|define
name|HC_HenFIFOAT_MASK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|HC_HenGEMILock_MASK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|HC_HenFBASwap_MASK
value|0x00000008
end_define

begin_define
define|#
directive|define
name|HC_HenOT_MASK
value|0x00000004
end_define

begin_define
define|#
directive|define
name|HC_HenCMDQ_MASK
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HenTXCTSU_MASK
value|0x00000001
end_define

begin_comment
comment|/* HC_SubA_HFBDrawFirst    0x0004  */
end_comment

begin_define
define|#
directive|define
name|HC_HFBDrawFirst_MASK
value|0x00000800
end_define

begin_define
define|#
directive|define
name|HC_HFBQueue_MASK
value|0x00000400
end_define

begin_define
define|#
directive|define
name|HC_HFBLock_MASK
value|0x00000200
end_define

begin_define
define|#
directive|define
name|HC_HEOF_MASK
value|0x00000100
end_define

begin_define
define|#
directive|define
name|HC_HFBBasH_MASK
value|0x000000ff
end_define

begin_comment
comment|/* GEMI Setting  */
end_comment

begin_define
define|#
directive|define
name|HC_SubA_HTArbRCM
value|0x0008
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTArbRZ
value|0x000a
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTArbWZ
value|0x000b
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTArbRTX
value|0x000c
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTArbRCW
value|0x000d
end_define

begin_define
define|#
directive|define
name|HC_SubA_HTArbE2
value|0x000e
end_define

begin_define
define|#
directive|define
name|HC_SubA_HArbRQCM
value|0x0010
end_define

begin_define
define|#
directive|define
name|HC_SubA_HArbWQCM
value|0x0011
end_define

begin_define
define|#
directive|define
name|HC_SubA_HGEMITout
value|0x0020
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFthRTXD
value|0x0040
end_define

begin_define
define|#
directive|define
name|HC_SubA_HFthRTXA
value|0x0044
end_define

begin_define
define|#
directive|define
name|HC_SubA_HCMDQstL
value|0x0050
end_define

begin_define
define|#
directive|define
name|HC_SubA_HCMDQendL
value|0x0051
end_define

begin_define
define|#
directive|define
name|HC_SubA_HCMDQLen
value|0x0052
end_define

begin_comment
comment|/* HC_SubA_HTArbRCM        0x0008  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbRCM_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HTArbRZ         0x000a  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbRZ_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HTArbWZ         0x000b  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbWZ_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HTArbRTX        0x000c  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbRTX_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HTArbRCW        0x000d  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbRCW_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HTArbE2         0x000e  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbE2_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HArbRQCM        0x0010  */
end_comment

begin_define
define|#
directive|define
name|HC_HTArbRQCM_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HArbWQCM        0x0011  */
end_comment

begin_define
define|#
directive|define
name|HC_HArbWQCM_MASK
value|0x0000ffff
end_define

begin_comment
comment|/* HC_SubA_HGEMITout       0x0020  */
end_comment

begin_define
define|#
directive|define
name|HC_HGEMITout_MASK
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|HC_HNPArbZC_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|HC_HGEMITout_SHIFT
value|16
end_define

begin_comment
comment|/* HC_SubA_HFthRTXD        0x0040  */
end_comment

begin_define
define|#
directive|define
name|HC_HFthRTXD_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|HC_HFthRZD_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HFthWZD_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HFthRTXD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|HC_HFthRZD_SHIFT
value|8
end_define

begin_comment
comment|/* HC_SubA_HFthRTXA        0x0044  */
end_comment

begin_define
define|#
directive|define
name|HC_HFthRTXA_MASK
value|0x000000ff
end_define

begin_comment
comment|/****************************************************************************** ** Define the Halcyon Internal register access constants. For simulator only. ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HAGPBstL
value|0x0000
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HAGPBendL
value|0x0001
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HAGPCMNT
value|0x0002
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HAGPBpL
value|0x0003
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HAGPBpH
value|0x0004
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HClipTB
value|0x0005
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HClipLR
value|0x0006
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipTL
value|0x0007
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipBL
value|0x0008
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipLL
value|0x0009
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipRL
value|0x000a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipTBH
value|0x000b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFPClipLRH
value|0x000c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HLP
value|0x000d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HLPRF
value|0x000e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HSolidCL
value|0x000f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HPixGC
value|0x0010
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HSPXYOS
value|0x0011
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HCmdA
value|0x0012
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HCmdB
value|0x0013
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HEnable
value|0x0014
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWBBasL
value|0x0015
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWBBasH
value|0x0016
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWBType
value|0x0017
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZBiasL
value|0x0018
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWBend
value|0x0019
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWTMD
value|0x001a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWCDL
value|0x001b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWCTAGnum
value|0x001c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZCYNum
value|0x001d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HZWCFire
value|0x001e
end_define

begin_comment
comment|/* #define HC_SIMA_HSBBasL         0x001d */
end_comment

begin_comment
comment|/* #define HC_SIMA_HSBBasH         0x001e */
end_comment

begin_comment
comment|/* #define HC_SIMA_HSBFM           0x001f */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HSTREF
value|0x0020
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HSTMD
value|0x0021
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABBasL
value|0x0022
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABBasH
value|0x0023
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABFM
value|0x0024
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HATMD
value|0x0025
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLCsat
value|0x0026
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLCop
value|0x0027
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLAsat
value|0x0028
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLAop
value|0x0029
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRCa
value|0x002a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRFCa
value|0x002b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRCbias
value|0x002c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRCb
value|0x002d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRFCb
value|0x002e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRAa
value|0x002f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HABLRAb
value|0x0030
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HDBBasL
value|0x0031
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HDBBasH
value|0x0032
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HDBFM
value|0x0033
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFBBMSKL
value|0x0034
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HROP
value|0x0035
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogLF
value|0x0036
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogCL
value|0x0037
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogCH
value|0x0038
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogStL
value|0x0039
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogStH
value|0x003a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogOOdMF
value|0x003b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogOOdEF
value|0x003c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogEndL
value|0x003d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFogDenst
value|0x003e
end_define

begin_comment
comment|/*---- start of texture 0 setting ----  */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L0BasL
value|0x0040
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L1BasL
value|0x0041
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L2BasL
value|0x0042
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L3BasL
value|0x0043
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L4BasL
value|0x0044
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L5BasL
value|0x0045
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L6BasL
value|0x0046
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L7BasL
value|0x0047
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L8BasL
value|0x0048
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L9BasL
value|0x0049
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LaBasL
value|0x004a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LbBasL
value|0x004b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LcBasL
value|0x004c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LdBasL
value|0x004d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LeBasL
value|0x004e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LfBasL
value|0x004f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L10BasL
value|0x0050
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L11BasL
value|0x0051
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L012BasH
value|0x0052
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L345BasH
value|0x0053
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L678BasH
value|0x0054
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L9abBasH
value|0x0055
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LcdeBasH
value|0x0056
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0Lf1011BasH
value|0x0057
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L0Pit
value|0x0058
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L1Pit
value|0x0059
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L2Pit
value|0x005a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L3Pit
value|0x005b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L4Pit
value|0x005c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L5Pit
value|0x005d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L6Pit
value|0x005e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L7Pit
value|0x005f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L8Pit
value|0x0060
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L9Pit
value|0x0061
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LaPit
value|0x0062
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LbPit
value|0x0063
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LcPit
value|0x0064
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LdPit
value|0x0065
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LePit
value|0x0066
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LfPit
value|0x0067
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L10Pit
value|0x0068
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L11Pit
value|0x0069
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L0_5WE
value|0x006a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L6_bWE
value|0x006b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0Lc_11WE
value|0x006c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L0_5HE
value|0x006d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L6_bHE
value|0x006e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0Lc_11HE
value|0x006f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0L0OS
value|0x0070
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TB
value|0x0071
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0MPMD
value|0x0072
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0CLODu
value|0x0073
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0FM
value|0x0074
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TRCH
value|0x0075
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TRCL
value|0x0076
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBC
value|0x0077
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TRAH
value|0x0078
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLCsat
value|0x0079
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLCop
value|0x007a
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLMPfog
value|0x007b
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLAsat
value|0x007c
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRCa
value|0x007d
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRCb
value|0x007e
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRCc
value|0x007f
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRCbias
value|0x0080
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRAa
value|0x0081
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0TBLRFog
value|0x0082
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0BumpM00
value|0x0083
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0BumpM01
value|0x0084
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0BumpM10
value|0x0085
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0BumpM11
value|0x0086
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX0LScale
value|0x0087
end_define

begin_comment
comment|/*---- end of texture 0 setting ----      0x008f  */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_TX0TX1_OFF
value|0x0050
end_define

begin_comment
comment|/*---- start of texture 1 setting ----  */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L0BasL
value|(HC_SIMA_HTX0L0BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L1BasL
value|(HC_SIMA_HTX0L1BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L2BasL
value|(HC_SIMA_HTX0L2BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L3BasL
value|(HC_SIMA_HTX0L3BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L4BasL
value|(HC_SIMA_HTX0L4BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L5BasL
value|(HC_SIMA_HTX0L5BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L6BasL
value|(HC_SIMA_HTX0L6BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L7BasL
value|(HC_SIMA_HTX0L7BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L8BasL
value|(HC_SIMA_HTX0L8BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L9BasL
value|(HC_SIMA_HTX0L9BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LaBasL
value|(HC_SIMA_HTX0LaBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LbBasL
value|(HC_SIMA_HTX0LbBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LcBasL
value|(HC_SIMA_HTX0LcBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LdBasL
value|(HC_SIMA_HTX0LdBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LeBasL
value|(HC_SIMA_HTX0LeBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LfBasL
value|(HC_SIMA_HTX0LfBasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L10BasL
value|(HC_SIMA_HTX0L10BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L11BasL
value|(HC_SIMA_HTX0L11BasL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L012BasH
value|(HC_SIMA_HTX0L012BasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L345BasH
value|(HC_SIMA_HTX0L345BasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L678BasH
value|(HC_SIMA_HTX0L678BasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L9abBasH
value|(HC_SIMA_HTX0L9abBasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LcdeBasH
value|(HC_SIMA_HTX0LcdeBasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1Lf1011BasH
value|(HC_SIMA_HTX0Lf1011BasH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L0Pit
value|(HC_SIMA_HTX0L0Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L1Pit
value|(HC_SIMA_HTX0L1Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L2Pit
value|(HC_SIMA_HTX0L2Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L3Pit
value|(HC_SIMA_HTX0L3Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L4Pit
value|(HC_SIMA_HTX0L4Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L5Pit
value|(HC_SIMA_HTX0L5Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L6Pit
value|(HC_SIMA_HTX0L6Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L7Pit
value|(HC_SIMA_HTX0L7Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L8Pit
value|(HC_SIMA_HTX0L8Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L9Pit
value|(HC_SIMA_HTX0L9Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LaPit
value|(HC_SIMA_HTX0LaPit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LbPit
value|(HC_SIMA_HTX0LbPit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LcPit
value|(HC_SIMA_HTX0LcPit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LdPit
value|(HC_SIMA_HTX0LdPit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LePit
value|(HC_SIMA_HTX0LePit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LfPit
value|(HC_SIMA_HTX0LfPit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L10Pit
value|(HC_SIMA_HTX0L10Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L11Pit
value|(HC_SIMA_HTX0L11Pit + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L0_5WE
value|(HC_SIMA_HTX0L0_5WE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L6_bWE
value|(HC_SIMA_HTX0L6_bWE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1Lc_11WE
value|(HC_SIMA_HTX0Lc_11WE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L0_5HE
value|(HC_SIMA_HTX0L0_5HE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L6_bHE
value|(HC_SIMA_HTX0L6_bHE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1Lc_11HE
value|(HC_SIMA_HTX0Lc_11HE + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1L0OS
value|(HC_SIMA_HTX0L0OS + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TB
value|(HC_SIMA_HTX0TB + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1MPMD
value|(HC_SIMA_HTX0MPMD + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1CLODu
value|(HC_SIMA_HTX0CLODu + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1FM
value|(HC_SIMA_HTX0FM + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TRCH
value|(HC_SIMA_HTX0TRCH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TRCL
value|(HC_SIMA_HTX0TRCL + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBC
value|(HC_SIMA_HTX0TBC + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TRAH
value|(HC_SIMA_HTX0TRAH + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LTC
value|(HC_SIMA_HTX0LTC + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LTA
value|(HC_SIMA_HTX0LTA + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLCsat
value|(HC_SIMA_HTX0TBLCsat + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLCop
value|(HC_SIMA_HTX0TBLCop + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLMPfog
value|(HC_SIMA_HTX0TBLMPfog + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLAsat
value|(HC_SIMA_HTX0TBLAsat + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRCa
value|(HC_SIMA_HTX0TBLRCa + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRCb
value|(HC_SIMA_HTX0TBLRCb + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRCc
value|(HC_SIMA_HTX0TBLRCc + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRCbias
value|(HC_SIMA_HTX0TBLRCbias + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRAa
value|(HC_SIMA_HTX0TBLRAa + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1TBLRFog
value|(HC_SIMA_HTX0TBLRFog + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1BumpM00
value|(HC_SIMA_HTX0BumpM00 + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1BumpM01
value|(HC_SIMA_HTX0BumpM01 + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1BumpM10
value|(HC_SIMA_HTX0BumpM10 + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1BumpM11
value|(HC_SIMA_HTX0BumpM11 + HC_SIMA_TX0TX1_OFF)
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTX1LScale
value|(HC_SIMA_HTX0LScale + HC_SIMA_TX0TX1_OFF)
end_define

begin_comment
comment|/*---- end of texture 1 setting ---- 0xaf  */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HTXSMD
value|0x00b0
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HenFIFOAT
value|0x00b1
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFBDrawFirst
value|0x00b2
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFBBasL
value|0x00b3
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbRCM
value|0x00b4
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbRZ
value|0x00b5
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbWZ
value|0x00b6
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbRTX
value|0x00b7
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbRCW
value|0x00b8
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTArbE2
value|0x00b9
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HGEMITout
value|0x00ba
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFthRTXD
value|0x00bb
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HFthRTXA
value|0x00bc
end_define

begin_comment
comment|/* Define the texture palette 0  */
end_comment

begin_define
define|#
directive|define
name|HC_SIMA_HTP0
value|0x0100
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HTP1
value|0x0200
end_define

begin_define
define|#
directive|define
name|HC_SIMA_FOGTABLE
value|0x0300
end_define

begin_define
define|#
directive|define
name|HC_SIMA_STIPPLE
value|0x0400
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HE3Fire
value|0x0440
end_define

begin_define
define|#
directive|define
name|HC_SIMA_TRANS_SET
value|0x0441
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HREngSt
value|0x0442
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HRFIFOempty
value|0x0443
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HRFIFOfull
value|0x0444
end_define

begin_define
define|#
directive|define
name|HC_SIMA_HRErr
value|0x0445
end_define

begin_define
define|#
directive|define
name|HC_SIMA_FIFOstatus
value|0x0446
end_define

begin_comment
comment|/****************************************************************************** ** Define the AGP command header. ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HC_ACMD_MASK
value|0xfe000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_SUB_MASK
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_HCmdA
value|0xee000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_HCmdB
value|0xec000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_HCmdC
value|0xea000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H1
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H2
value|0xf2000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H3
value|0xf4000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H4
value|0xf6000000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H1IO_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H2IO1_MASK
value|0x001ff000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H2IO2_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H2IO1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H2IO2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H3IO_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H3COUNT_MASK
value|0x01fff000
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H3COUNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H4ID_MASK
value|0x000001ff
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H4COUNT_MASK
value|0x01fffe00
end_define

begin_define
define|#
directive|define
name|HC_ACMD_H4COUNT_SHIFT
value|9
end_define

begin_comment
comment|/******************************************************************************** ** Define Header ********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HC_HEADER2
value|0xF210F110
end_define

begin_comment
comment|/******************************************************************************** ** Define Dummy Value ********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HC_DUMMY
value|0xCCCCCCCC
end_define

begin_comment
comment|/******************************************************************************** ** Define for DMA use ********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|HALCYON_HEADER2
value|0XF210F110
end_define

begin_define
define|#
directive|define
name|HALCYON_FIRECMD
value|0XEE100000
end_define

begin_define
define|#
directive|define
name|HALCYON_FIREMASK
value|0XFFF00000
end_define

begin_define
define|#
directive|define
name|HALCYON_CMDB
value|0XEC000000
end_define

begin_define
define|#
directive|define
name|HALCYON_CMDBMASK
value|0XFFFE0000
end_define

begin_define
define|#
directive|define
name|HALCYON_SUB_ADDR0
value|0X00000000
end_define

begin_define
define|#
directive|define
name|HALCYON_HEADER1MASK
value|0XFFFFFC00
end_define

begin_define
define|#
directive|define
name|HALCYON_HEADER1
value|0XF0000000
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBstL
value|0x0060
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBendL
value|0x0061
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPCMNT
value|0x0062
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBpL
value|0x0063
end_define

begin_define
define|#
directive|define
name|HC_SubA_HAGPBpH
value|0x0064
end_define

begin_define
define|#
directive|define
name|HC_HAGPCMNT_MASK
value|0x00800000
end_define

begin_define
define|#
directive|define
name|HC_HCmdErrClr_MASK
value|0x00400000
end_define

begin_define
define|#
directive|define
name|HC_HAGPBendH_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|HC_HAGPBstH_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|HC_HAGPBendH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|HC_HAGPBstH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpL_MASK
value|0x00fffffc
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_MASK
value|0x00000003
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_PAUSE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_JUMP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpID_STOP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|HC_HAGPBpH_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|VIA_VIDEO_HEADER5
value|0xFE040000
end_define

begin_define
define|#
directive|define
name|VIA_VIDEO_HEADER6
value|0xFE050000
end_define

begin_define
define|#
directive|define
name|VIA_VIDEO_HEADER7
value|0xFE060000
end_define

begin_define
define|#
directive|define
name|VIA_VIDEOMASK
value|0xFFFF0000
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

