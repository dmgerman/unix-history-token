begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Advanced Micro Devices, Inc.  * Copyright 2008 Red Hat Inc.  * Copyright 2009 Jerome Glisse.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * THE COPYRIGHT HOLDER(S) OR AUTHOR(S) BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie  *          Alex Deucher  *          Jerome Glisse  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__R100D_H__
end_ifndef

begin_define
define|#
directive|define
name|__R100D_H__
end_define

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

begin_define
define|#
directive|define
name|CP_PACKET0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|PACKET0_BASE_INDEX_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PACKET0_BASE_INDEX_MASK
value|(0x1ffff<< 0)
end_define

begin_define
define|#
directive|define
name|PACKET0_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PACKET0_COUNT_MASK
value|(0x3fff<< 16)
end_define

begin_define
define|#
directive|define
name|CP_PACKET1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CP_PACKET2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PACKET2_PAD_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PACKET2_PAD_MASK
value|(0x3fffffff<< 0)
end_define

begin_define
define|#
directive|define
name|CP_PACKET3
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|PACKET3_IT_OPCODE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PACKET3_IT_OPCODE_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|PACKET3_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PACKET3_COUNT_MASK
value|(0x3fff<< 16)
end_define

begin_comment
comment|/* PACKET3 op code */
end_comment

begin_define
define|#
directive|define
name|PACKET3_NOP
value|0x10
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_VBUF
value|0x28
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_IMMD
value|0x29
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_INDX
value|0x2A
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_LOAD_VBPNTR
value|0x2F
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_CLEAR_ZMASK
value|0x32
end_define

begin_define
define|#
directive|define
name|PACKET3_INDX_BUFFER
value|0x33
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_VBUF_2
value|0x34
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_IMMD_2
value|0x35
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_DRAW_INDX_2
value|0x36
end_define

begin_define
define|#
directive|define
name|PACKET3_3D_CLEAR_HIZ
value|0x37
end_define

begin_define
define|#
directive|define
name|PACKET3_BITBLT_MULTI
value|0x9B
end_define

begin_define
define|#
directive|define
name|PACKET0
parameter_list|(
name|reg
parameter_list|,
name|n
parameter_list|)
value|(CP_PACKET0 |					\ 			 REG_SET(PACKET0_BASE_INDEX, (reg)>> 2) |	\ 			 REG_SET(PACKET0_COUNT, (n)))
end_define

begin_define
define|#
directive|define
name|PACKET2
parameter_list|(
name|v
parameter_list|)
value|(CP_PACKET2 | REG_SET(PACKET2_PAD, (v)))
end_define

begin_define
define|#
directive|define
name|PACKET3
parameter_list|(
name|op
parameter_list|,
name|n
parameter_list|)
value|(CP_PACKET3 |					\ 			 REG_SET(PACKET3_IT_OPCODE, (op)) |		\ 			 REG_SET(PACKET3_COUNT, (n)))
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE0
value|0
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE1
value|1
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE2
value|2
end_define

begin_define
define|#
directive|define
name|PACKET_TYPE3
value|3
end_define

begin_define
define|#
directive|define
name|CP_PACKET_GET_TYPE
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 30)& 3)
end_define

begin_define
define|#
directive|define
name|CP_PACKET_GET_COUNT
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 16)& 0x3FFF)
end_define

begin_define
define|#
directive|define
name|CP_PACKET0_GET_REG
parameter_list|(
name|h
parameter_list|)
value|(((h)& 0x1FFF)<< 2)
end_define

begin_define
define|#
directive|define
name|CP_PACKET0_GET_ONE_REG_WR
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 15)& 1)
end_define

begin_define
define|#
directive|define
name|CP_PACKET3_GET_OPCODE
parameter_list|(
name|h
parameter_list|)
value|(((h)>> 8)& 0xFF)
end_define

begin_comment
comment|/* Registers */
end_comment

begin_define
define|#
directive|define
name|R_0000F0_RBBM_SOFT_RESET
value|0x0000F0
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CP
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HI
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HI
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_SE
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RE
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_PP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_PP
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_E2
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_RB
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_HDP
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_MC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_MC
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_AIC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_AIC
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_VIP
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_DISP
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0000F0_SOFT_RESET_CG
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0000F0_SOFT_RESET_CG
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|R_000030_BUS_CNTL
value|0x000030
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_DBL_RESYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_DBL_RESYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_DBL_RESYNC
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MSTR_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MSTR_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MSTR_RESET
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_FLUSH_BUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_FLUSH_BUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_FLUSH_BUF
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_STOP_REQ_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_STOP_REQ_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_STOP_REQ_DIS
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_PM4_READ_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_PM4_READ_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_PM4_READ_COMBINE_EN
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_WRT_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_WRT_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_WRT_COMBINE_EN
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MASTER_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MASTER_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MASTER_DIS
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_000030_BIOS_ROM_WRT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_000030_BIOS_ROM_WRT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BIOS_ROM_WRT_EN
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_000030_BM_DAC_CRIPPLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000030_BM_DAC_CRIPPLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BM_DAC_CRIPPLE
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_NON_PM4_READ_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_NON_PM4_READ_COMBINE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_NON_PM4_READ_COMBINE_EN
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_XFERD_DISCARD_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_XFERD_DISCARD_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_XFERD_DISCARD_EN
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_SGL_READ_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_SGL_READ_DISABLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_SGL_READ_DISABLE
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000030_BIOS_DIS_ROM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000030_BIOS_DIS_ROM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BIOS_DIS_ROM
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_PCI_READ_RETRY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_PCI_READ_RETRY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_PCI_READ_RETRY_EN
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_AGP_AD_STEPPING_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_AGP_AD_STEPPING_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_AGP_AD_STEPPING_EN
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_PCI_WRT_RETRY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_PCI_WRT_RETRY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_PCI_WRT_RETRY_EN
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_RETRY_WS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_RETRY_WS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_RETRY_WS
value|0xFFF0FFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MSTR_RD_MULT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MSTR_RD_MULT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MSTR_RD_MULT
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MSTR_RD_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MSTR_RD_LINE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MSTR_RD_LINE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_SUSPEND
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_SUSPEND
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_SUSPEND
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_LAT_16X
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000030_LAT_16X
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_LAT_16X
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_RD_DISCARD_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_RD_DISCARD_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_RD_DISCARD_EN
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_ENFRCWRDY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000030_ENFRCWRDY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_ENFRCWRDY
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MSTR_WS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MSTR_WS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MSTR_WS
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_PARKING_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_PARKING_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_PARKING_DIS
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_MSTR_DISCONNECT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_MSTR_DISCONNECT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_MSTR_DISCONNECT_EN
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_SERR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000030_SERR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_SERR_EN
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_READ_BURST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_READ_BURST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_READ_BURST
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000030_BUS_RDY_READ_DLY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000030_BUS_RDY_READ_DLY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000030_BUS_RDY_READ_DLY
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000040_GEN_INT_CNTL
value|0x000040
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC_VBLANK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC_VBLANK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC_VBLANK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC_VLINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC_VLINE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC_VLINE
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC_VSYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC_VSYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC_VSYNC
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000040_SNAPSHOT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000040_SNAPSHOT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_SNAPSHOT
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000040_FP_DETECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000040_FP_DETECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_FP_DETECT
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC2_VLINE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC2_VLINE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC2_VLINE
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH0_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH0_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH0_INT_EN
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC2_VSYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC2_VSYNC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC2_VSYNC
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_000040_SNAPSHOT2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_000040_SNAPSHOT2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_SNAPSHOT2
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_000040_CRTC2_VBLANK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000040_CRTC2_VBLANK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_CRTC2_VBLANK
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000040_FP2_DETECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000040_FP2_DETECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_FP2_DETECT
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000040_VSYNC_DIFF_OVER_LIMIT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000040_VSYNC_DIFF_OVER_LIMIT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_VSYNC_DIFF_OVER_LIMIT
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH1_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH1_INT_EN
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH2_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH2_INT_EN
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DMA_VIPH3_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000040_DMA_VIPH3_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DMA_VIPH3_INT_EN
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000040_I2C_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000040_I2C_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_I2C_INT_EN
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GUI_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000040_GUI_IDLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GUI_IDLE
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000040_VIPH_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000040_VIPH_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_VIPH_INT_EN
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_SW_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000040_SW_INT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_SW_INT_EN
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GEYSERVILLE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000040_GEYSERVILLE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GEYSERVILLE
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_HDCP_AUTHORIZED_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000040_HDCP_AUTHORIZED_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_HDCP_AUTHORIZED_INT
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_DVI_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000040_DVI_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_DVI_I2C_INT
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_GUIDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000040_GUIDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_GUIDMA
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000040_VIDDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000040_VIDDMA
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000040_VIDDMA
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000044_GEN_INT_STATUS
value|0x000044
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VBLANK_STAT
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VBLANK_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VBLANK_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VBLANK_STAT_AK
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VLINE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VLINE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VLINE_STAT
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VLINE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VLINE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VLINE_STAT_AK
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VSYNC_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VSYNC_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VSYNC_STAT
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC_VSYNC_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC_VSYNC_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC_VSYNC_STAT_AK
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000044_SNAPSHOT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000044_SNAPSHOT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SNAPSHOT_STAT
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000044_SNAPSHOT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000044_SNAPSHOT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SNAPSHOT_STAT_AK
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000044_FP_DETECT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000044_FP_DETECT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_FP_DETECT_STAT
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000044_FP_DETECT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000044_FP_DETECT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_FP_DETECT_STAT_AK
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VLINE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VLINE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VLINE_STAT
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VLINE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VLINE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VLINE_STAT_AK
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VSYNC_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VSYNC_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VSYNC_STAT
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VSYNC_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VSYNC_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VSYNC_STAT_AK
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_000044_SNAPSHOT2_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_000044_SNAPSHOT2_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SNAPSHOT2_STAT
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_000044_SNAPSHOT2_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_000044_SNAPSHOT2_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SNAPSHOT2_STAT_AK
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_000044_CAP0_INT_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000044_CAP0_INT_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CAP0_INT_ACTIVE
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VBLANK_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VBLANK_STAT
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000044_CRTC2_VBLANK_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000044_CRTC2_VBLANK_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_CRTC2_VBLANK_STAT_AK
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000044_FP2_DETECT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000044_FP2_DETECT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_FP2_DETECT_STAT
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000044_FP2_DETECT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000044_FP2_DETECT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_FP2_DETECT_STAT_AK
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000044_VSYNC_DIFF_OVER_LIMIT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000044_VSYNC_DIFF_OVER_LIMIT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VSYNC_DIFF_OVER_LIMIT_STAT
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000044_VSYNC_DIFF_OVER_LIMIT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000044_VSYNC_DIFF_OVER_LIMIT_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VSYNC_DIFF_OVER_LIMIT_STAT_AK
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH0_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH0_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH0_INT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH0_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH0_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH0_INT_AK
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH1_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH1_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH1_INT
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH1_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH1_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH1_INT_AK
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH2_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH2_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH2_INT
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH2_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH2_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH2_INT_AK
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH3_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH3_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH3_INT
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000044_DMA_VIPH3_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000044_DMA_VIPH3_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DMA_VIPH3_INT_AK
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000044_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000044_I2C_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_I2C_INT
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_I2C_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000044_I2C_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_I2C_INT_AK
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUI_IDLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000044_GUI_IDLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUI_IDLE_STAT
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUI_IDLE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000044_GUI_IDLE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUI_IDLE_STAT_AK
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000044_VIPH_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000044_VIPH_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VIPH_INT
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SW_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000044_SW_INT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SW_INT
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SW_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000044_SW_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SW_INT_AK
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_SW_INT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000044_SW_INT_SET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_SW_INT_SET
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GEYSERVILLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000044_GEYSERVILLE_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GEYSERVILLE_STAT
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GEYSERVILLE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_000044_GEYSERVILLE_STAT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GEYSERVILLE_STAT_AK
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_HDCP_AUTHORIZED_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000044_HDCP_AUTHORIZED_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_HDCP_AUTHORIZED_INT_STAT
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_HDCP_AUTHORIZED_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000044_HDCP_AUTHORIZED_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_HDCP_AUTHORIZED_INT_AK
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DVI_I2C_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000044_DVI_I2C_INT_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DVI_I2C_INT_STAT
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_DVI_I2C_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000044_DVI_I2C_INT_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_DVI_I2C_INT_AK
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUIDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000044_GUIDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUIDMA_STAT
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_GUIDMA_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000044_GUIDMA_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_GUIDMA_AK
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_VIDDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000044_VIDDMA_STAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VIDDMA_STAT
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000044_VIDDMA_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000044_VIDDMA_AK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000044_VIDDMA_AK
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000050_CRTC_GEN_CNTL
value|0x000050
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_DBL_SCAN_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_DBL_SCAN_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_DBL_SCAN_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_INTERLACE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_INTERLACE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_INTERLACE_EN
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_C_SYNC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_C_SYNC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_C_SYNC_EN
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_PIX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_PIX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_PIX_WIDTH
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_ICON_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_ICON_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_ICON_EN
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_CUR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_CUR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_CUR_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_VSTAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_VSTAT_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_VSTAT_MODE
value|0xFFF9FFFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_CUR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_CUR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_CUR_MODE
value|0xFF8FFFFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_EXT_DISP_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_EXT_DISP_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_EXT_DISP_EN
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_EN
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000050_CRTC_DISP_REQ_EN_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000050_CRTC_DISP_REQ_EN_B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000050_CRTC_DISP_REQ_EN_B
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000054_CRTC_EXT_CNTL
value|0x000054
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_VGA_XOVERSCAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_VGA_XOVERSCAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_VGA_XOVERSCAN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_BLINK_RATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_BLINK_RATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_BLINK_RATE
value|0xFFFFFFF9
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_ATI_LINEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_ATI_LINEAR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_ATI_LINEAR
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_128KAP_PAGING
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_128KAP_PAGING
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_128KAP_PAGING
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_TEXT_132
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_TEXT_132
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_TEXT_132
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_XCRT_CNT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_XCRT_CNT_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_XCRT_CNT_EN
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_HSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_HSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_HSYNC_DIS
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_VSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_VSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_VSYNC_DIS
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_DISPLAY_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_DISPLAY_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_DISPLAY_DIS
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_SYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_SYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_SYNC_TRISTATE
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_HSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_HSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_HSYNC_TRISTATE
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000054_CRTC_VSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000054_CRTC_VSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRTC_VSYNC_TRISTATE
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000054_CRT_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000054_CRT_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_CRT_ON
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_CUR_B_TEST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_CUR_B_TEST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_CUR_B_TEST
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_PACK_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_PACK_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_PACK_DIS
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000054_VGA_MEM_PS_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000054_VGA_MEM_PS_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000054_VGA_MEM_PS_EN
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000054_VCRTC_IDX_MASTER
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000054_VCRTC_IDX_MASTER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_000054_VCRTC_IDX_MASTER
value|0x80FFFFFF
end_define

begin_define
define|#
directive|define
name|R_000148_MC_FB_LOCATION
value|0x000148
end_define

begin_define
define|#
directive|define
name|S_000148_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000148_MC_FB_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000148_MC_FB_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_000148_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000148_MC_FB_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_000148_MC_FB_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_00014C_MC_AGP_LOCATION
value|0x00014C
end_define

begin_define
define|#
directive|define
name|S_00014C_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00014C_MC_AGP_START
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_00014C_MC_AGP_START
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|S_00014C_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFF)<< 16)
end_define

begin_define
define|#
directive|define
name|G_00014C_MC_AGP_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0xFFFF)
end_define

begin_define
define|#
directive|define
name|C_00014C_MC_AGP_TOP
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|R_000170_AGP_BASE
value|0x000170
end_define

begin_define
define|#
directive|define
name|S_000170_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000170_AGP_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000170_AGP_BASE_ADDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_00023C_DISPLAY_BASE_ADDR
value|0x00023C
end_define

begin_define
define|#
directive|define
name|S_00023C_DISPLAY_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00023C_DISPLAY_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_00023C_DISPLAY_BASE_ADDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000260_CUR_OFFSET
value|0x000260
end_define

begin_define
define|#
directive|define
name|S_000260_CUR_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000260_CUR_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000260_CUR_OFFSET
value|0xF8000000
end_define

begin_define
define|#
directive|define
name|S_000260_CUR_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000260_CUR_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000260_CUR_LOCK
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_00033C_CRTC2_DISPLAY_BASE_ADDR
value|0x00033C
end_define

begin_define
define|#
directive|define
name|S_00033C_CRTC2_DISPLAY_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFFFFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00033C_CRTC2_DISPLAY_BASE_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_00033C_CRTC2_DISPLAY_BASE_ADDR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|R_000360_CUR2_OFFSET
value|0x000360
end_define

begin_define
define|#
directive|define
name|S_000360_CUR2_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFFFFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000360_CUR2_OFFSET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7FFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000360_CUR2_OFFSET
value|0xF8000000
end_define

begin_define
define|#
directive|define
name|S_000360_CUR2_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000360_CUR2_LOCK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000360_CUR2_LOCK
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_0003C2_GENMO_WT
value|0x0003C2
end_define

begin_define
define|#
directive|define
name|S_0003C2_GENMO_MONO_ADDRESS_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0003C2_GENMO_MONO_ADDRESS_B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003C2_GENMO_MONO_ADDRESS_B
value|0xFE
end_define

begin_define
define|#
directive|define
name|S_0003C2_VGA_RAM_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0003C2_VGA_RAM_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003C2_VGA_RAM_EN
value|0xFD
end_define

begin_define
define|#
directive|define
name|S_0003C2_VGA_CKSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0003C2_VGA_CKSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_0003C2_VGA_CKSEL
value|0xF3
end_define

begin_define
define|#
directive|define
name|S_0003C2_ODD_EVEN_MD_PGSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_0003C2_ODD_EVEN_MD_PGSEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003C2_ODD_EVEN_MD_PGSEL
value|0xDF
end_define

begin_define
define|#
directive|define
name|S_0003C2_VGA_HSYNC_POL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_0003C2_VGA_HSYNC_POL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003C2_VGA_HSYNC_POL
value|0xBF
end_define

begin_define
define|#
directive|define
name|S_0003C2_VGA_VSYNC_POL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_0003C2_VGA_VSYNC_POL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003C2_VGA_VSYNC_POL
value|0x7F
end_define

begin_define
define|#
directive|define
name|R_0003F8_CRTC2_GEN_CNTL
value|0x0003F8
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_DBL_SCAN_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_DBL_SCAN_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_DBL_SCAN_EN
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_INTERLACE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_INTERLACE_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_INTERLACE_EN
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_SYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_SYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_SYNC_TRISTATE
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_HSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 5)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_HSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_HSYNC_TRISTATE
value|0xFFFFFFDF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_VSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 6)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_VSYNC_TRISTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_VSYNC_TRISTATE
value|0xFFFFFFBF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRT2_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 7)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRT2_ON
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 7)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRT2_ON
value|0xFFFFFF7F
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_PIX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_PIX_WIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_PIX_WIDTH
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_ICON_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_ICON_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_ICON_EN
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_CUR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_CUR_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_CUR_EN
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_CUR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 20)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_CUR_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_CUR_MODE
value|0xFF8FFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_DISPLAY_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_DISPLAY_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_DISPLAY_DIS
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_EN
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_DISP_REQ_EN_B
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_DISP_REQ_EN_B
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_DISP_REQ_EN_B
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_C_SYNC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_C_SYNC_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_C_SYNC_EN
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_HSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_HSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_HSYNC_DIS
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0003F8_CRTC2_VSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_0003F8_CRTC2_VSYNC_DIS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0003F8_CRTC2_VSYNC_DIS
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000420_OV0_SCALE_CNTL
value|0x000420
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_NO_READ_BEHIND_SCAN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_NO_READ_BEHIND_SCAN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_NO_READ_BEHIND_SCAN
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_HORZ_PICK_NEAREST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_HORZ_PICK_NEAREST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_HORZ_PICK_NEAREST
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_VERT_PICK_NEAREST
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_VERT_PICK_NEAREST
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_VERT_PICK_NEAREST
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_SIGNED_UV
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 4)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_SIGNED_UV
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_SIGNED_UV
value|0xFFFFFFEF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_GAMMA_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_GAMMA_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_GAMMA_SEL
value|0xFFFFFF1F
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_SURFACE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_SURFACE_FORMAT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_SURFACE_FORMAT
value|0xFFFFF0FF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_ADAPTIVE_DEINT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_ADAPTIVE_DEINT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_ADAPTIVE_DEINT
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_CRTC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_CRTC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_CRTC_SEL
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_BURST_PER_PLANE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_BURST_PER_PLANE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_BURST_PER_PLANE
value|0xFF80FFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_DOUBLE_BUFFER_REGS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_DOUBLE_BUFFER_REGS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_DOUBLE_BUFFER_REGS
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_BANDWIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_BANDWIDTH
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_BANDWIDTH
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_LIN_TRANS_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_LIN_TRANS_BYPASS
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_LIN_TRANS_BYPASS
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_INT_EMU
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_INT_EMU
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_INT_EMU
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_OVERLAY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_OVERLAY_EN
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_OVERLAY_EN
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000420_OV0_SOFT_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000420_OV0_SOFT_RESET
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000420_OV0_SOFT_RESET
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_00070C_CP_RB_RPTR_ADDR
value|0x00070C
end_define

begin_define
define|#
directive|define
name|S_00070C_RB_RPTR_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00070C_RB_RPTR_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_00070C_RB_RPTR_SWAP
value|0xFFFFFFFC
end_define

begin_define
define|#
directive|define
name|S_00070C_RB_RPTR_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3FFFFFFF)<< 2)
end_define

begin_define
define|#
directive|define
name|G_00070C_RB_RPTR_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x3FFFFFFF)
end_define

begin_define
define|#
directive|define
name|C_00070C_RB_RPTR_ADDR
value|0x00000003
end_define

begin_define
define|#
directive|define
name|R_000740_CP_CSQ_CNTL
value|0x000740
end_define

begin_define
define|#
directive|define
name|S_000740_CSQ_CNT_PRIMARY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000740_CSQ_CNT_PRIMARY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000740_CSQ_CNT_PRIMARY
value|0xFFFFFF00
end_define

begin_define
define|#
directive|define
name|S_000740_CSQ_CNT_INDIRECT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xFF)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000740_CSQ_CNT_INDIRECT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0xFF)
end_define

begin_define
define|#
directive|define
name|C_000740_CSQ_CNT_INDIRECT
value|0xFFFF00FF
end_define

begin_define
define|#
directive|define
name|S_000740_CSQ_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0xF)<< 28)
end_define

begin_define
define|#
directive|define
name|G_000740_CSQ_MODE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0xF)
end_define

begin_define
define|#
directive|define
name|C_000740_CSQ_MODE
value|0x0FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000770_SCRATCH_UMSK
value|0x000770
end_define

begin_define
define|#
directive|define
name|S_000770_SCRATCH_UMSK
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000770_SCRATCH_UMSK
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x3F)
end_define

begin_define
define|#
directive|define
name|C_000770_SCRATCH_UMSK
value|0xFFFFFFC0
end_define

begin_define
define|#
directive|define
name|S_000770_SCRATCH_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x3)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000770_SCRATCH_SWAP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x3)
end_define

begin_define
define|#
directive|define
name|C_000770_SCRATCH_SWAP
value|0xFFFCFFFF
end_define

begin_define
define|#
directive|define
name|R_000774_SCRATCH_ADDR
value|0x000774
end_define

begin_define
define|#
directive|define
name|S_000774_SCRATCH_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7FFFFFF)<< 5)
end_define

begin_define
define|#
directive|define
name|G_000774_SCRATCH_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 5)& 0x7FFFFFF)
end_define

begin_define
define|#
directive|define
name|C_000774_SCRATCH_ADDR
value|0x0000001F
end_define

begin_define
define|#
directive|define
name|R_0007C0_CP_STAT
value|0x0007C0
end_define

begin_define
define|#
directive|define
name|S_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 0)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MRU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MRU_BUSY
value|0xFFFFFFFE
end_define

begin_define
define|#
directive|define
name|S_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 1)
end_define

begin_define
define|#
directive|define
name|G_0007C0_MWU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 1)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_MWU_BUSY
value|0xFFFFFFFD
end_define

begin_define
define|#
directive|define
name|S_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 2)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RSIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 2)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RSIU_BUSY
value|0xFFFFFFFB
end_define

begin_define
define|#
directive|define
name|S_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 3)
end_define

begin_define
define|#
directive|define
name|G_0007C0_RCIU_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 3)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_RCIU_BUSY
value|0xFFFFFFF7
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_PRIMARY_BUSY
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSF_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSF_INDIRECT_BUSY
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_PRIMARY_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_PRIMARY_BUSY
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSQ_INDIRECT_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSQ_INDIRECT_BUSY
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CSI_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CSI_BUSY
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_0007C0_GUIDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_GUIDMA_BUSY
value|0xEFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 29)
end_define

begin_define
define|#
directive|define
name|G_0007C0_VIDDMA_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 29)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_VIDDMA_BUSY
value|0xDFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 30)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 30)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CMDSTRM_BUSY
value|0xBFFFFFFF
end_define

begin_define
define|#
directive|define
name|S_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_0007C0_CP_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_0007C0_CP_BUSY
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_000E40_RBBM_STATUS
value|0x000E40
end_define

begin_define
define|#
directive|define
name|S_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7F)<< 0)
end_define

begin_define
define|#
directive|define
name|G_000E40_CMDFIFO_AVAIL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7F)
end_define

begin_define
define|#
directive|define
name|C_000E40_CMDFIFO_AVAIL
value|0xFFFFFF80
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 8)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_ON_RBB
value|0xFFFFFEFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 9)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_ON_RBB
value|0xFFFFFDFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 10)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_ON_RBB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 10)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_ON_RBB
value|0xFFFFFBFF
end_define

begin_define
define|#
directive|define
name|S_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 11)
end_define

begin_define
define|#
directive|define
name|G_000E40_HIRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 11)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_HIRQ_IN_RTBUF
value|0xFFFFF7FF
end_define

begin_define
define|#
directive|define
name|S_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 12)
end_define

begin_define
define|#
directive|define
name|G_000E40_CPRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 12)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CPRQ_IN_RTBUF
value|0xFFFFEFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 13)
end_define

begin_define
define|#
directive|define
name|G_000E40_CFRQ_IN_RTBUF
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 13)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CFRQ_IN_RTBUF
value|0xFFFFDFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 14)
end_define

begin_define
define|#
directive|define
name|G_000E40_CF_PIPE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 14)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CF_PIPE_BUSY
value|0xFFFFBFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 15)
end_define

begin_define
define|#
directive|define
name|G_000E40_ENG_EV_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 15)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_ENG_EV_BUSY
value|0xFFFF7FFF
end_define

begin_define
define|#
directive|define
name|S_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_000E40_CP_CMDSTRM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_CP_CMDSTRM_BUSY
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_000E40_E2_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_E2_BUSY
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB2D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB2D_BUSY
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_000E40_RB3D_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RB3D_BUSY
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_SE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_000E40_SE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_SE_BUSY
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_000E40_RE_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_RE_BUSY
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_000E40_TAM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TAM_BUSY
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_000E40_TDM_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_TDM_BUSY
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_000E40_PB_BUSY
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_PB_BUSY
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 31)
end_define

begin_define
define|#
directive|define
name|G_000E40_GUI_ACTIVE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 31)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_000E40_GUI_ACTIVE
value|0x7FFFFFFF
end_define

begin_define
define|#
directive|define
name|R_00000D_SCLK_CNTL
value|0x00000D
end_define

begin_define
define|#
directive|define
name|S_00000D_SCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 0)
end_define

begin_define
define|#
directive|define
name|G_00000D_SCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 0)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_00000D_SCLK_SRC_SEL
value|0xFFFFFFF8
end_define

begin_define
define|#
directive|define
name|S_00000D_TCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x7)<< 8)
end_define

begin_define
define|#
directive|define
name|G_00000D_TCLK_SRC_SEL
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|C_00000D_TCLK_SRC_SEL
value|0xFFFFF8FF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 16)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_CP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 16)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_CP
value|0xFFFEFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 17)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_HDP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 17)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_HDP
value|0xFFFDFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 18)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_DISP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 18)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_DISP
value|0xFFFBFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 19)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TOP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 19)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TOP
value|0xFFF7FFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 20)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_E2
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 20)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_E2
value|0xFFEFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 21)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_SE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 21)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_SE
value|0xFFDFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 22)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_IDCT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 22)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_IDCT
value|0xFFBFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 23)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_VIP
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 23)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_VIP
value|0xFF7FFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 24)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_RE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 24)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_RE
value|0xFEFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_PB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 25)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_PB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 25)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_PB
value|0xFDFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TAM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 26)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TAM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 26)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TAM
value|0xFBFFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_TDM
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 27)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_TDM
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 27)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_TDM
value|0xF7FFFFFF
end_define

begin_define
define|#
directive|define
name|S_00000D_FORCE_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)& 0x1)<< 28)
end_define

begin_define
define|#
directive|define
name|G_00000D_FORCE_RB
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 28)& 0x1)
end_define

begin_define
define|#
directive|define
name|C_00000D_FORCE_RB
value|0xEFFFFFFF
end_define

begin_comment
comment|/* PLL regs */
end_comment

begin_define
define|#
directive|define
name|SCLK_CNTL
value|0xd
end_define

begin_define
define|#
directive|define
name|FORCE_HDP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|CLK_PWRMGT_CNTL
value|0x14
end_define

begin_define
define|#
directive|define
name|GLOBAL_PMAN_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|DISP_PM
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|PLL_PWRMGT_CNTL
value|0x15
end_define

begin_define
define|#
directive|define
name|MPLL_TURNOFF
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|SPLL_TURNOFF
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|PPLL_TURNOFF
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|P2PLL_TURNOFF
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TVPLL_TURNOFF
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|MOBILE_SU
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|SU_SCLK_USE_BCLK
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|SCLK_CNTL2
value|0x1e
end_define

begin_define
define|#
directive|define
name|REDUCED_SPEED_SCLK_MODE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|REDUCED_SPEED_SCLK_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 17)
end_define

begin_define
define|#
directive|define
name|MCLK_MISC
value|0x1f
end_define

begin_define
define|#
directive|define
name|EN_MCLK_TRISTATE_IN_SUSPEND
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|SCLK_MORE_CNTL
value|0x35
end_define

begin_define
define|#
directive|define
name|REDUCED_SPEED_SCLK_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IO_CG_VOLTAGE_DROP
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|VOLTAGE_DELAY_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|VOLTAGE_DROP_SYNC
value|(1<< 19)
end_define

begin_comment
comment|/* mmreg */
end_comment

begin_define
define|#
directive|define
name|DISP_PWR_MAN
value|0xd08
end_define

begin_define
define|#
directive|define
name|DISP_D3_GRPH_RST
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|DISP_D3_SUBPIC_RST
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|DISP_D3_OV0_RST
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|DISP_D1D2_GRPH_RST
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|DISP_D1D2_SUBPIC_RST
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|DISP_D1D2_OV0_RST
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|DISP_DVO_ENABLE_RST
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|TV_ENABLE_RST
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|AUTO_PWRUP_EN
value|(1<< 26)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

