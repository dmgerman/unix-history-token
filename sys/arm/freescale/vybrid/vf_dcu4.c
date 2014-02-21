begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Vybrid Family Display Control Unit (DCU4)  * Chapter 55, Vybrid Reference Manual, Rev. 5, 07/2013  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/timeet.h>
end_include

begin_include
include|#
directive|include
file|<sys/timetc.h>
end_include

begin_include
include|#
directive|include
file|<sys/watchdog.h>
end_include

begin_include
include|#
directive|include
file|<sys/fbio.h>
end_include

begin_include
include|#
directive|include
file|<sys/consio.h>
end_include

begin_include
include|#
directive|include
file|<sys/eventhandler.h>
end_include

begin_include
include|#
directive|include
file|<dev/fdt/fdt_common.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/openfirm.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_include
include|#
directive|include
file|<dev/vt/vt.h>
end_include

begin_include
include|#
directive|include
file|<dev/vt/colors/vt_termcolors.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/fdt.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_include
include|#
directive|include
file|<machine/intr.h>
end_include

begin_include
include|#
directive|include
file|"fb_if.h"
end_include

begin_include
include|#
directive|include
file|<arm/freescale/vybrid/vf_common.h>
end_include

begin_define
define|#
directive|define
name|DCU_CTRLDESCCURSOR1
value|0x000
end_define

begin_comment
comment|/* Control Descriptor Cursor 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_CTRLDESCCURSOR2
value|0x004
end_define

begin_comment
comment|/* Control Descriptor Cursor 2 */
end_comment

begin_define
define|#
directive|define
name|DCU_CTRLDESCCURSOR3
value|0x008
end_define

begin_comment
comment|/* Control Descriptor Cursor 3 */
end_comment

begin_define
define|#
directive|define
name|DCU_CTRLDESCCURSOR4
value|0x00C
end_define

begin_comment
comment|/* Control Descriptor Cursor 4 */
end_comment

begin_define
define|#
directive|define
name|DCU_DCU_MODE
value|0x010
end_define

begin_comment
comment|/* DCU4 Mode */
end_comment

begin_define
define|#
directive|define
name|DCU_MODE_M
value|0x3
end_define

begin_define
define|#
directive|define
name|DCU_MODE_S
value|0
end_define

begin_define
define|#
directive|define
name|DCU_MODE_NORMAL
value|0x1
end_define

begin_define
define|#
directive|define
name|DCU_MODE_TEST
value|0x2
end_define

begin_define
define|#
directive|define
name|DCU_MODE_COLBAR
value|0x3
end_define

begin_define
define|#
directive|define
name|RASTER_EN
value|(1<< 14)
end_define

begin_comment
comment|/* Raster scan of pixel data */
end_comment

begin_define
define|#
directive|define
name|DCU_BGND
value|0x014
end_define

begin_comment
comment|/* Background */
end_comment

begin_define
define|#
directive|define
name|DCU_DISP_SIZE
value|0x018
end_define

begin_comment
comment|/* Display Size */
end_comment

begin_define
define|#
directive|define
name|DELTA_M
value|0x7ff
end_define

begin_define
define|#
directive|define
name|DELTA_Y_S
value|16
end_define

begin_define
define|#
directive|define
name|DELTA_X_S
value|0
end_define

begin_define
define|#
directive|define
name|DCU_HSYN_PARA
value|0x01C
end_define

begin_comment
comment|/* Horizontal Sync Parameter */
end_comment

begin_define
define|#
directive|define
name|BP_H_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|PW_H_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|FP_H_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DCU_VSYN_PARA
value|0x020
end_define

begin_comment
comment|/* Vertical Sync Parameter */
end_comment

begin_define
define|#
directive|define
name|BP_V_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|PW_V_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|FP_V_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DCU_SYNPOL
value|0x024
end_define

begin_comment
comment|/* Synchronize Polarity */
end_comment

begin_define
define|#
directive|define
name|INV_HS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|INV_VS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DCU_THRESHOLD
value|0x028
end_define

begin_comment
comment|/* Threshold */
end_comment

begin_define
define|#
directive|define
name|LS_BF_VS_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|OUT_BUF_HIGH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|OUT_BUF_LOW_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DCU_INT_STATUS
value|0x02C
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|DCU_INT_MASK
value|0x030
end_define

begin_comment
comment|/* Interrupt Mask */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_1
value|0x034
end_define

begin_comment
comment|/* COLBAR_1 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_2
value|0x038
end_define

begin_comment
comment|/* COLBAR_2 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_3
value|0x03C
end_define

begin_comment
comment|/* COLBAR_3 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_4
value|0x040
end_define

begin_comment
comment|/* COLBAR_4 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_5
value|0x044
end_define

begin_comment
comment|/* COLBAR_5 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_6
value|0x048
end_define

begin_comment
comment|/* COLBAR_6 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_7
value|0x04C
end_define

begin_comment
comment|/* COLBAR_7 */
end_comment

begin_define
define|#
directive|define
name|DCU_COLBAR_8
value|0x050
end_define

begin_comment
comment|/* COLBAR_8 */
end_comment

begin_define
define|#
directive|define
name|DCU_DIV_RATIO
value|0x054
end_define

begin_comment
comment|/* Divide Ratio */
end_comment

begin_define
define|#
directive|define
name|DCU_SIGN_CALC_1
value|0x058
end_define

begin_comment
comment|/* Sign Calculation 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_SIGN_CALC_2
value|0x05C
end_define

begin_comment
comment|/* Sign Calculation 2 */
end_comment

begin_define
define|#
directive|define
name|DCU_CRC_VAL
value|0x060
end_define

begin_comment
comment|/* CRC Value */
end_comment

begin_define
define|#
directive|define
name|DCU_PDI_STATUS
value|0x064
end_define

begin_comment
comment|/* PDI Status */
end_comment

begin_define
define|#
directive|define
name|DCU_PDI_STA_MSK
value|0x068
end_define

begin_comment
comment|/* PDI Status Mask */
end_comment

begin_define
define|#
directive|define
name|DCU_PARR_ERR_STATUS1
value|0x06C
end_define

begin_comment
comment|/* Parameter Error Status 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_PARR_ERR_STATUS2
value|0x070
end_define

begin_comment
comment|/* Parameter Error Status 2 */
end_comment

begin_define
define|#
directive|define
name|DCU_PARR_ERR_STATUS3
value|0x07C
end_define

begin_comment
comment|/* Parameter Error Status 3 */
end_comment

begin_define
define|#
directive|define
name|DCU_MASK_PARR_ERR_ST1
value|0x080
end_define

begin_comment
comment|/* Mask Parameter Error Status 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_MASK_PARR_ERR_ST2
value|0x084
end_define

begin_comment
comment|/* Mask Parameter Error Status 2 */
end_comment

begin_define
define|#
directive|define
name|DCU_MASK_PARR_ERR_ST3
value|0x090
end_define

begin_comment
comment|/* Mask Parameter Error Status 3 */
end_comment

begin_define
define|#
directive|define
name|DCU_THRESHOLD_INP_BUF_1
value|0x094
end_define

begin_comment
comment|/* Threshold Input 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_THRESHOLD_INP_BUF_2
value|0x098
end_define

begin_comment
comment|/* Threshold Input 2 */
end_comment

begin_define
define|#
directive|define
name|DCU_THRESHOLD_INP_BUF_3
value|0x09C
end_define

begin_comment
comment|/* Threshold Input 3 */
end_comment

begin_define
define|#
directive|define
name|DCU_LUMA_COMP
value|0x0A0
end_define

begin_comment
comment|/* LUMA Component */
end_comment

begin_define
define|#
directive|define
name|DCU_CHROMA_RED
value|0x0A4
end_define

begin_comment
comment|/* Red Chroma Components */
end_comment

begin_define
define|#
directive|define
name|DCU_CHROMA_GREEN
value|0x0A8
end_define

begin_comment
comment|/* Green Chroma Components */
end_comment

begin_define
define|#
directive|define
name|DCU_CHROMA_BLUE
value|0x0AC
end_define

begin_comment
comment|/* Blue Chroma Components */
end_comment

begin_define
define|#
directive|define
name|DCU_CRC_POS
value|0x0B0
end_define

begin_comment
comment|/* CRC Position */
end_comment

begin_define
define|#
directive|define
name|DCU_LYR_INTPOL_EN
value|0x0B4
end_define

begin_comment
comment|/* Layer Interpolation Enable */
end_comment

begin_define
define|#
directive|define
name|DCU_LYR_LUMA_COMP
value|0x0B8
end_define

begin_comment
comment|/* Layer Luminance Component */
end_comment

begin_define
define|#
directive|define
name|DCU_LYR_CHRM_RED
value|0x0BC
end_define

begin_comment
comment|/* Layer Chroma Red */
end_comment

begin_define
define|#
directive|define
name|DCU_LYR_CHRM_GRN
value|0x0C0
end_define

begin_comment
comment|/* Layer Chroma Green */
end_comment

begin_define
define|#
directive|define
name|DCU_LYR_CHRM_BLUE
value|0x0C4
end_define

begin_comment
comment|/* Layer Chroma Blue */
end_comment

begin_define
define|#
directive|define
name|DCU_COMP_IMSIZE
value|0x0C8
end_define

begin_comment
comment|/* Compression Image Size */
end_comment

begin_define
define|#
directive|define
name|DCU_UPDATE_MODE
value|0x0CC
end_define

begin_comment
comment|/* Update Mode */
end_comment

begin_define
define|#
directive|define
name|READREG
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|MODE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|DCU_UNDERRUN
value|0x0D0
end_define

begin_comment
comment|/* Underrun */
end_comment

begin_define
define|#
directive|define
name|DCU_GLBL_PROTECT
value|0x100
end_define

begin_comment
comment|/* Global Protection */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_BIT_L0
value|0x104
end_define

begin_comment
comment|/* Soft Lock Bit Layer 0 */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_BIT_L1
value|0x108
end_define

begin_comment
comment|/* Soft Lock Bit Layer 1 */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_DISP_SIZE
value|0x10C
end_define

begin_comment
comment|/* Soft Lock Display Size */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_HS_VS_PARA
value|0x110
end_define

begin_comment
comment|/* Soft Lock Hsync/Vsync Parameter */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_POL
value|0x114
end_define

begin_comment
comment|/* Soft Lock POL */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_L0_TRANSP
value|0x118
end_define

begin_comment
comment|/* Soft Lock L0 Transparency */
end_comment

begin_define
define|#
directive|define
name|DCU_SFT_LCK_L1_TRANSP
value|0x11C
end_define

begin_comment
comment|/* Soft Lock L1 Transparency */
end_comment

begin_comment
comment|/* Control Descriptor */
end_comment

begin_define
define|#
directive|define
name|DCU_CTRLDESCL
parameter_list|(
name|n
parameter_list|,
name|m
parameter_list|)
value|0x200 + (0x40 * n) + 0x4 * (m - 1)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_1
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 1)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_2
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 2)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_3
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 3)
end_define

begin_define
define|#
directive|define
name|TRANS_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_4
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 4)
end_define

begin_define
define|#
directive|define
name|BPP_MASK
value|0xf
end_define

begin_comment
comment|/* Bit per pixel Mask */
end_comment

begin_define
define|#
directive|define
name|BPP_SHIFT
value|16
end_define

begin_comment
comment|/* Bit per pixel Shift */
end_comment

begin_define
define|#
directive|define
name|BPP24
value|0x5
end_define

begin_define
define|#
directive|define
name|EN_LAYER
value|(1<< 31)
end_define

begin_comment
comment|/* Enable the layer */
end_comment

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_5
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 5)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_6
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 6)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_7
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 7)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_8
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 8)
end_define

begin_define
define|#
directive|define
name|DCU_CTRLDESCLn_9
parameter_list|(
name|n
parameter_list|)
value|DCU_CTRLDESCL(n, 9)
end_define

begin_define
define|#
directive|define
name|DISPLAY_WIDTH
value|480
end_define

begin_define
define|#
directive|define
name|DISPLAY_HEIGHT
value|272
end_define

begin_struct
struct|struct
name|dcu_softc
block|{
name|struct
name|resource
modifier|*
name|res
index|[
literal|2
index|]
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|void
modifier|*
name|ih
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|device_t
name|sc_fbd
decl_stmt|;
comment|/* fbd child */
name|struct
name|fb_info
name|sc_info
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|static
name|struct
name|resource_spec
name|dcu_spec
index|[]
init|=
block|{
block|{
name|SYS_RES_MEMORY
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
name|SYS_RES_IRQ
block|,
literal|0
block|,
name|RF_ACTIVE
block|}
block|,
block|{
operator|-
literal|1
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|dcu_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ofw_bus_status_okay
argument_list|(
name|dev
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
if|if
condition|(
operator|!
name|ofw_bus_is_compatible
argument_list|(
name|dev
argument_list|,
literal|"fsl,mvf600-dcu4"
argument_list|)
condition|)
return|return
operator|(
name|ENXIO
operator|)
return|;
name|device_set_desc
argument_list|(
name|dev
argument_list|,
literal|"Vybrid Family Display Control Unit (DCU4)"
argument_list|)
expr_stmt|;
return|return
operator|(
name|BUS_PROBE_DEFAULT
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|dcu_intr
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
block|{
name|struct
name|dcu_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|reg
decl_stmt|;
name|sc
operator|=
name|arg
expr_stmt|;
comment|/* Ack interrupts */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|DCU_INT_STATUS
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_INT_STATUS
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* TODO interrupt handler */
block|}
end_function

begin_function
specifier|static
name|int
name|dcu_init
parameter_list|(
name|struct
name|dcu_softc
modifier|*
name|sc
parameter_list|)
block|{
name|int
name|reg
decl_stmt|;
comment|/* Configure DCU */
name|reg
operator|=
operator|(
operator|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_height
operator|)
operator|<<
name|DELTA_Y_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_width
operator|/
literal|16
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_DISP_SIZE
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* TODO: export panel info to FDT */
name|reg
operator|=
operator|(
literal|2
operator|<<
name|BP_H_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|41
operator|<<
name|PW_H_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|2
operator|<<
name|FP_H_SHIFT
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_HSYN_PARA
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
literal|2
operator|<<
name|BP_V_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|10
operator|<<
name|PW_V_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|2
operator|<<
name|FP_V_SHIFT
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_VSYN_PARA
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_BGND
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_DIV_RATIO
argument_list|,
literal|30
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
name|INV_VS
operator||
name|INV_HS
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_SYNPOL
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
literal|0x3
operator|<<
name|LS_BF_VS_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|0x78
operator|<<
name|OUT_BUF_HIGH_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
literal|0
operator|<<
name|OUT_BUF_LOW_SHIFT
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_THRESHOLD
argument_list|,
name|reg
argument_list|)
expr_stmt|;
comment|/* Mask all the interrupts */
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_INT_MASK
argument_list|,
literal|0xffffffff
argument_list|)
expr_stmt|;
comment|/* Setup first layer */
name|reg
operator|=
operator|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_width
operator||
operator|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_height
operator|<<
literal|16
operator|)
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_1
argument_list|(
literal|0
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_2
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_3
argument_list|(
literal|0
argument_list|)
argument_list|,
name|sc
operator|->
name|sc_info
operator|.
name|fb_pbase
argument_list|)
expr_stmt|;
name|reg
operator|=
operator|(
name|BPP24
operator|<<
name|BPP_SHIFT
operator|)
expr_stmt|;
name|reg
operator||=
name|EN_LAYER
expr_stmt|;
name|reg
operator||=
operator|(
literal|0xFF
operator|<<
name|TRANS_SHIFT
operator|)
expr_stmt|;
comment|/* completely opaque */
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_4
argument_list|(
literal|0
argument_list|)
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_5
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0xffffff
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_6
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_7
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_8
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_CTRLDESCLn_9
argument_list|(
literal|0
argument_list|)
argument_list|,
literal|0x0
argument_list|)
expr_stmt|;
comment|/* Enable DCU in normal mode */
name|reg
operator|=
name|READ4
argument_list|(
name|sc
argument_list|,
name|DCU_DCU_MODE
argument_list|)
expr_stmt|;
name|reg
operator|&=
operator|~
operator|(
name|DCU_MODE_M
operator|<<
name|DCU_MODE_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|DCU_MODE_NORMAL
operator|<<
name|DCU_MODE_S
operator|)
expr_stmt|;
name|reg
operator||=
operator|(
name|RASTER_EN
operator|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_DCU_MODE
argument_list|,
name|reg
argument_list|)
expr_stmt|;
name|WRITE4
argument_list|(
name|sc
argument_list|,
name|DCU_UPDATE_MODE
argument_list|,
name|READREG
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|int
name|dcu_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|dcu_softc
modifier|*
name|sc
decl_stmt|;
name|int
name|err
decl_stmt|;
name|sc
operator|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
expr_stmt|;
if|if
condition|(
name|bus_alloc_resources
argument_list|(
name|dev
argument_list|,
name|dcu_spec
argument_list|,
name|sc
operator|->
name|res
argument_list|)
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"could not allocate resources\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Memory interface */
name|sc
operator|->
name|bst
operator|=
name|rman_get_bustag
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|sc
operator|->
name|bsh
operator|=
name|rman_get_bushandle
argument_list|(
name|sc
operator|->
name|res
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
comment|/* Setup interrupt handler */
name|err
operator|=
name|bus_setup_intr
argument_list|(
name|dev
argument_list|,
name|sc
operator|->
name|res
index|[
literal|1
index|]
argument_list|,
name|INTR_TYPE_BIO
operator||
name|INTR_MPSAFE
argument_list|,
name|NULL
argument_list|,
name|dcu_intr
argument_list|,
name|sc
argument_list|,
operator|&
name|sc
operator|->
name|ih
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
condition|)
block|{
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Unable to alloc interrupt resource.\n"
argument_list|)
expr_stmt|;
return|return
operator|(
name|ENXIO
operator|)
return|;
block|}
comment|/* Bypass timing control (used for raw lcd panels) */
name|tcon_bypass
argument_list|()
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_width
operator|=
name|DISPLAY_WIDTH
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_height
operator|=
name|DISPLAY_HEIGHT
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_stride
operator|=
name|sc
operator|->
name|sc_info
operator|.
name|fb_width
operator|*
literal|3
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_bpp
operator|=
name|sc
operator|->
name|sc_info
operator|.
name|fb_depth
operator|=
literal|24
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_size
operator|=
name|sc
operator|->
name|sc_info
operator|.
name|fb_height
operator|*
name|sc
operator|->
name|sc_info
operator|.
name|fb_stride
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_vbase
operator|=
operator|(
name|intptr_t
operator|)
name|contigmalloc
argument_list|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_size
argument_list|,
name|M_DEVBUF
argument_list|,
name|M_ZERO
argument_list|,
literal|0
argument_list|,
operator|~
literal|0
argument_list|,
name|PAGE_SIZE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_pbase
operator|=
operator|(
name|intptr_t
operator|)
name|vtophys
argument_list|(
name|sc
operator|->
name|sc_info
operator|.
name|fb_vbase
argument_list|)
expr_stmt|;
if|#
directive|if
literal|0
block|printf("%dx%d [%d]\n", sc->sc_info.fb_width, sc->sc_info.fb_height, 	    sc->sc_info.fb_stride); 	printf("pbase == 0x%08x\n", sc->sc_info.fb_pbase);
endif|#
directive|endif
name|memset
argument_list|(
operator|(
name|int8_t
operator|*
operator|)
name|sc
operator|->
name|sc_info
operator|.
name|fb_vbase
argument_list|,
literal|0x0
argument_list|,
name|sc
operator|->
name|sc_info
operator|.
name|fb_size
argument_list|)
expr_stmt|;
name|dcu_init
argument_list|(
name|sc
argument_list|)
expr_stmt|;
name|sc
operator|->
name|sc_info
operator|.
name|fb_name
operator|=
name|device_get_nameunit
argument_list|(
name|dev
argument_list|)
expr_stmt|;
comment|/* Ask newbus to attach framebuffer device to me. */
name|sc
operator|->
name|sc_fbd
operator|=
name|device_add_child
argument_list|(
name|dev
argument_list|,
literal|"fbd"
argument_list|,
name|device_get_unit
argument_list|(
name|dev
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|sc
operator|->
name|sc_fbd
operator|==
name|NULL
condition|)
name|device_printf
argument_list|(
name|dev
argument_list|,
literal|"Can't attach fbd device\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|device_probe_and_attach
argument_list|(
name|sc
operator|->
name|sc_fbd
argument_list|)
operator|!=
literal|0
condition|)
block|{
name|device_printf
argument_list|(
name|sc
operator|->
name|dev
argument_list|,
literal|"Failed to attach fbd device\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|struct
name|fb_info
modifier|*
name|dcu4_fb_getinfo
parameter_list|(
name|device_t
name|dev
parameter_list|)
block|{
name|struct
name|dcu_softc
modifier|*
name|sc
init|=
name|device_get_softc
argument_list|(
name|dev
argument_list|)
decl_stmt|;
return|return
operator|(
operator|&
name|sc
operator|->
name|sc_info
operator|)
return|;
block|}
end_function

begin_decl_stmt
specifier|static
name|device_method_t
name|dcu_methods
index|[]
init|=
block|{
name|DEVMETHOD
argument_list|(
name|device_probe
argument_list|,
name|dcu_probe
argument_list|)
block|,
name|DEVMETHOD
argument_list|(
name|device_attach
argument_list|,
name|dcu_attach
argument_list|)
block|,
comment|/* Framebuffer service methods */
name|DEVMETHOD
argument_list|(
name|fb_getinfo
argument_list|,
name|dcu4_fb_getinfo
argument_list|)
block|,
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|driver_t
name|dcu_driver
init|=
block|{
literal|"fb"
block|,
name|dcu_methods
block|,
sizeof|sizeof
argument_list|(
expr|struct
name|dcu_softc
argument_list|)
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|devclass_t
name|dcu_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|DRIVER_MODULE
argument_list|(
name|fb
argument_list|,
name|simplebus
argument_list|,
name|dcu_driver
argument_list|,
name|dcu_devclass
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

end_unit

