begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2000 ATI Technologies Inc., Markham, Ontario, and  *                VA Linux Systems Inc., Fremont, California.  *  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining  * a copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation on the rights to use, copy, modify, merge,  * publish, distribute, sublicense, and/or sell copies of the Software,  * and to permit persons to whom the Software is furnished to do so,  * subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial  * portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NON-INFRINGEMENT.  IN NO EVENT SHALL ATI, VA LINUX SYSTEMS AND/OR  * THEIR SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,  * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_comment
comment|/*  * Authors:  *   Kevin E. Martin<martin@xfree86.org>  *   Rickard E. Faith<faith@valinux.com>  *   Alan Hourihane<alanh@fairlite.demon.co.uk>  *  * References:  *  * !!!! FIXME !!!!  *   RAGE 128 VR/ RAGE 128 GL Register Reference Manual (Technical  *   Reference Manual P/N RRG-G04100-C Rev. 0.04), ATI Technologies: April  *   1999.  *  * !!!! FIXME !!!!  *   RAGE 128 Software Development Manual (Technical Reference Manual P/N  *   SDK-G04000 Rev. 0.01), ATI Technologies: June 1999.  *  */
end_comment

begin_comment
comment|/* !!!! FIXME !!!!  NOTE: THIS FILE HAS BEEN CONVERTED FROM r128_reg.h  * AND CONTAINS REGISTERS AND REGISTER DEFINITIONS THAT ARE NOT CORRECT  * ON THE RADEON.  A FULL AUDIT OF THIS CODE IS NEEDED!  */
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
name|_RADEON_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RADEON_REG_H_
end_define

begin_include
include|#
directive|include
file|"r300_reg.h"
end_include

begin_include
include|#
directive|include
file|"r500_reg.h"
end_include

begin_include
include|#
directive|include
file|"r600_reg.h"
end_include

begin_include
include|#
directive|include
file|"evergreen_reg.h"
end_include

begin_include
include|#
directive|include
file|"ni_reg.h"
end_include

begin_include
include|#
directive|include
file|"si_reg.h"
end_include

begin_define
define|#
directive|define
name|RADEON_MC_AGP_LOCATION
value|0x014c
end_define

begin_define
define|#
directive|define
name|RADEON_MC_AGP_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RADEON_MC_AGP_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_MC_AGP_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RADEON_MC_AGP_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_LOCATION
value|0x0148
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_START_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_TOP_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|RADEON_MC_FB_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_BASE_2
value|0x015c
end_define

begin_comment
comment|/* r200+ only */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_BASE
value|0x0170
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_VQ
value|0
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_CI4
value|1
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_CI8
value|2
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_RGB888
value|5
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_Y8
value|8
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_CI16
value|10
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_VYUY_422
value|11
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_YVYU_422
value|12
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_AYUV_444
value|14
end_define

begin_define
define|#
directive|define
name|ATI_DATATYPE_ARGB4444
value|15
end_define

begin_comment
comment|/* Registers for 2D/Video/Overlay */
end_comment

begin_define
define|#
directive|define
name|RADEON_ADAPTER_ID
value|0x0f2c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_BASE
value|0x0170
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_CNTL
value|0x0174
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_256MB
value|(0x00<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_128MB
value|(0x20<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_64MB
value|(0x30<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_32MB
value|(0x38<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_16MB
value|(0x3c<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_8MB
value|(0x3e<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_4MB
value|(0x3f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_APER_SIZE_MASK
value|(0x3f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_STATUS_PCI_CONFIG
value|0x06
end_define

begin_define
define|#
directive|define
name|RADEON_CAP_LIST
value|0x100000
end_define

begin_define
define|#
directive|define
name|RADEON_CAPABILITIES_PTR_PCI_CONFIG
value|0x34
end_define

begin_comment
comment|/* offset in PCI config*/
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP_PTR_MASK
value|0xfc
end_define

begin_comment
comment|/* mask off reserved bits of CAP_PTR */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP_ID_NULL
value|0x00
end_define

begin_comment
comment|/* End of capability list */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP_ID_AGP
value|0x02
end_define

begin_comment
comment|/* AGP capability ID */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP_ID_EXP
value|0x10
end_define

begin_comment
comment|/* PCI Express */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_COMMAND
value|0x0f60
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_COMMAND_PCI_CONFIG
value|0x0060
end_define

begin_comment
comment|/* offset in PCI config*/
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_ENABLE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_PLL_CNTL
value|0x000b
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_STATUS
value|0x0f5c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_AGP_1X_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_2X_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_4X_MODE
value|0x04
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_FW_MODE
value|0x10
end_define

begin_define
define|#
directive|define
name|RADEON_AGP_MODE_MASK
value|0x17
end_define

begin_define
define|#
directive|define
name|RADEON_AGPv3_MODE
value|0x08
end_define

begin_define
define|#
directive|define
name|RADEON_AGPv3_4X_MODE
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_AGPv3_8X_MODE
value|0x02
end_define

begin_define
define|#
directive|define
name|RADEON_ATTRDR
value|0x03c1
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_ATTRDW
value|0x03c0
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_ATTRX
value|0x03c0
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_AUX_SC_CNTL
value|0x1660
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_MODE_OR
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_MODE_NAND
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_MODE_OR
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_MODE_NAND
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_MODE_OR
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_MODE_NAND
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_BOTTOM
value|0x1670
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_LEFT
value|0x1664
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_RIGHT
value|0x1668
end_define

begin_define
define|#
directive|define
name|RADEON_AUX1_SC_TOP
value|0x166c
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_BOTTOM
value|0x1680
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_LEFT
value|0x1674
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_RIGHT
value|0x1678
end_define

begin_define
define|#
directive|define
name|RADEON_AUX2_SC_TOP
value|0x167c
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_BOTTOM
value|0x1690
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_LEFT
value|0x1684
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_RIGHT
value|0x1688
end_define

begin_define
define|#
directive|define
name|RADEON_AUX3_SC_TOP
value|0x168c
end_define

begin_define
define|#
directive|define
name|RADEON_AUX_WINDOW_HORZ_CNTL
value|0x02d8
end_define

begin_define
define|#
directive|define
name|RADEON_AUX_WINDOW_VERT_CNTL
value|0x02dc
end_define

begin_define
define|#
directive|define
name|RADEON_BASE_CODE
value|0x0f0b
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_0_SCRATCH
value|0x0010
end_define

begin_define
define|#
directive|define
name|RADEON_FP_PANEL_SCALABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_PANEL_SCALE_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CHIP_SCALE_EN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_DRIVER_BRIGHTNESS_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_ROT_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_ROT_00
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_ROT_90
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_ROT_180
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_ROT_270
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_1_SCRATCH
value|0x0014
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_2_SCRATCH
value|0x0018
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_3_SCRATCH
value|0x001c
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_4_SCRATCH
value|0x0020
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_ATTACHED_MASK
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_ATTACHED_MONO
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_ATTACHED_COLOR
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_LCD1_ATTACHED
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP1_ATTACHED
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_ATTACHED_MASK
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_ATTACHED_COMP
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_ATTACHED_SVIDEO
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_ATTACHED_MASK
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_ATTACHED_MONO
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_ATTACHED_COLOR
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP2_ATTACHED
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_5_SCRATCH
value|0x0024
end_define

begin_define
define|#
directive|define
name|RADEON_LCD1_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_ON
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_ON
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP1_ON
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_ON
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_CV1_ON
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP2_ON
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_LCD1_CRTC_MASK
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_LCD1_CRTC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_CRTC_MASK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT1_CRTC_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_CRTC_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_TV1_CRTC_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_DFP1_CRTC_MASK
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP1_CRTC_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_CRTC_MASK
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_CRTC_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_CV1_CRTC_MASK
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_CV1_CRTC_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|RADEON_DFP2_CRTC_MASK
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP2_CRTC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_LCD1
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_CRT1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_TV1
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_DFP1
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_CRT2
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_TV2
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_REQ_DFP2
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_6_SCRATCH
value|0x0028
end_define

begin_define
define|#
directive|define
name|RADEON_ACC_MODE_CHANGE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_EXT_DESKTOP_MODE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_LCD_DPMS_ON
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT_DPMS_ON
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DPMS_ON
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_DFP_DPMS_ON
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_DPMS_MASK
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DPMS_ON
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DPMS_STANDBY
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DPMS_SUSPEND
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DPMS_OFF
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_SCREEN_BLANKING
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_DRIVER_CRITICAL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY_SWITCHING_DIS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_7_SCRATCH
value|0x002c
end_define

begin_define
define|#
directive|define
name|RADEON_SYS_HOTKEY
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_DRV_LOADED
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_BIOS_ROM
value|0x0f30
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_BIST
value|0x0f0f
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA0
value|0x1480
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA1
value|0x1484
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA10
value|0x14a8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA11
value|0x14ac
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA12
value|0x14b0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA13
value|0x14b4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA14
value|0x14b8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA15
value|0x14bc
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA16
value|0x14c0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA17
value|0x14c4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA18
value|0x14c8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA19
value|0x14cc
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA2
value|0x1488
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA20
value|0x14d0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA21
value|0x14d4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA22
value|0x14d8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA23
value|0x14dc
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA24
value|0x14e0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA25
value|0x14e4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA26
value|0x14e8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA27
value|0x14ec
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA28
value|0x14f0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA29
value|0x14f4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA3
value|0x148c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA30
value|0x14f8
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA31
value|0x14fc
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA32
value|0x1500
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA33
value|0x1504
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA34
value|0x1508
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA35
value|0x150c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA36
value|0x1510
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA37
value|0x1514
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA38
value|0x1518
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA39
value|0x151c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA4
value|0x1490
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA40
value|0x1520
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA41
value|0x1524
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA42
value|0x1528
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA43
value|0x152c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA44
value|0x1530
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA45
value|0x1534
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA46
value|0x1538
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA47
value|0x153c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA48
value|0x1540
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA49
value|0x1544
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA5
value|0x1494
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA50
value|0x1548
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA51
value|0x154c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA52
value|0x1550
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA53
value|0x1554
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA54
value|0x1558
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA55
value|0x155c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA56
value|0x1560
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA57
value|0x1564
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA58
value|0x1568
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA59
value|0x156c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA6
value|0x1498
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA60
value|0x1570
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA61
value|0x1574
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA62
value|0x1578
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA63
value|0x157c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA7
value|0x149c
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA8
value|0x14a0
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_DATA9
value|0x14a4
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_SCALE
value|0x1470
end_define

begin_define
define|#
directive|define
name|RADEON_BRUSH_Y_X
value|0x1474
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_CNTL
value|0x0030
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_MASTER_DIS
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_BIOS_DIS_ROM
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RS600_BUS_MASTER_DIS
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RS600_MSI_REARM
value|(1<< 20)
end_define

begin_comment
comment|/* rs600/rs690/rs740 */
end_comment

begin_define
define|#
directive|define
name|RADEON_BUS_RD_DISCARD_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_RD_ABORT_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_MSTR_DISCONNECT_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_WRT_BURST
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_READ_BURST
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_CNTL1
value|0x0034
end_define

begin_define
define|#
directive|define
name|RADEON_BUS_WAIT_ON_LOCK_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RV370_BUS_CNTL
value|0x004c
end_define

begin_define
define|#
directive|define
name|RV370_BUS_BIOS_DIS_ROM
value|(1<< 2)
end_define

begin_comment
comment|/* rv370/rv380, rv410, r423/r430/r480, r5xx */
end_comment

begin_define
define|#
directive|define
name|RADEON_MSI_REARM_EN
value|0x0160
end_define

begin_define
define|#
directive|define
name|RV370_MSI_REARM_EN
value|(1<< 0)
end_define

begin_comment
comment|/* #define RADEON_PCIE_INDEX                   0x0030 */
end_comment

begin_comment
comment|/* #define RADEON_PCIE_DATA                    0x0034 */
end_comment

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_CNTL
value|0xa2
end_define

begin_comment
comment|/* PCIE */
end_comment

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X0
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X1
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X2
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X4
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X8
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X12
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_X16
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_RD_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_LINK_WIDTH_RD_MASK
value|0x70
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_RECONFIG_NOW
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_RECONFIG_LATER
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_LC_SHORT_RECONFIG_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_RECONFIG_ARC_MISSING_ESCAPE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_RENEGOTIATION_SUPPORT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_RENEGOTIATE_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_SHORT_RECONFIG_EN
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_UPCONFIGURE_SUPPORT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R600_PCIE_LC_UPCONFIGURE_DIS
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R600_TARGET_AND_CURRENT_PROFILE_INDEX
value|0x70c
end_define

begin_define
define|#
directive|define
name|R700_TARGET_AND_CURRENT_PROFILE_INDEX
value|0x66c
end_define

begin_define
define|#
directive|define
name|RADEON_CACHE_CNTL
value|0x1724
end_define

begin_define
define|#
directive|define
name|RADEON_CACHE_LINE
value|0x0f0c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAPABILITIES_ID
value|0x0f50
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAPABILITIES_PTR
value|0x0f34
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_CLK_PIN_CNTL
value|0x0001
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_DONT_USE_XTALIN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_DYN_START_CNTL
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CLOCK_CNTL_DATA
value|0x000c
end_define

begin_define
define|#
directive|define
name|RADEON_CLOCK_CNTL_INDEX
value|0x0008
end_define

begin_define
define|#
directive|define
name|RADEON_PLL_WR_EN
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_PLL_DIV_SEL
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_PLL2_DIV_SEL_MASK
value|(~(3<< 8))
end_define

begin_define
define|#
directive|define
name|RADEON_CLK_PWRMGT_CNTL
value|0x0014
end_define

begin_define
define|#
directive|define
name|RADEON_ENGIN_DYNCLK_MODE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_ACTIVE_HILO_LAT_MASK
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_ACTIVE_HILO_LAT_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DYN_STOP_LAT_MASK
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_MC_BUSY
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DLL_READY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_CG_NO1_DEBUG_0
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_CG_NO1_DEBUG_MASK
value|(0x1f<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DYN_STOP_MODE_MASK
value|(7<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPLL_PWRMGT_OFF
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_TVCLK_TURNOFF
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_PLL_PWRMGT_CNTL
value|0x0015
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PM_MODE_SEL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_BYPASS_DISABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_CLR_3D
value|0x1a24
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_CLR_DST
value|0x15c8
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_CLR_SRC
value|0x15c4
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_CNTL
value|0x15c0
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_CMP_EQ_COLOR
value|(4<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_CMP_NEQ_COLOR
value|(5<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_SRC_SOURCE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_MASK
value|0x15cc
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_MSK
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|RADEON_CLR_CMP_MASK_3D
value|0x1A28
end_define

begin_define
define|#
directive|define
name|RADEON_COMMAND
value|0x0f04
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_COMPOSITE_SHADOW_ID
value|0x1a0c
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_APER_0_BASE
value|0x0100
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_APER_1_BASE
value|0x0104
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_APER_SIZE
value|0x0108
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_BONDS
value|0x00e8
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_CNTL
value|0x00e0
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_VGA_RAM_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_VGA_IO_DIS
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_ATI_REV_A11
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_ATI_REV_A12
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_ATI_REV_A13
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CFG_ATI_REV_ID_MASK
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_MEMSIZE
value|0x00f8
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_MEMSIZE_EMBEDDED
value|0x0114
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_REG_1_BASE
value|0x010c
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_REG_APER_SIZE
value|0x0110
end_define

begin_define
define|#
directive|define
name|RADEON_CONFIG_XSTRAP
value|0x00e4
end_define

begin_define
define|#
directive|define
name|RADEON_CONSTANT_COLOR_C
value|0x1d34
end_define

begin_define
define|#
directive|define
name|RADEON_CONSTANT_COLOR_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|RADEON_CONSTANT_COLOR_ONE
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|RADEON_CONSTANT_COLOR_ZERO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CRC_CMDFIFO_ADDR
value|0x0740
end_define

begin_define
define|#
directive|define
name|RADEON_CRC_CMDFIFO_DOUT
value|0x0744
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_BUFFER_CNTL
value|0x02f0
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_START_REQ_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_START_REQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_STOP_REQ_MASK
value|(0x7f<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_STOP_REQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_CRITICAL_POINT_MASK
value|(0x7f<<16)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_CRITICAL_POINT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_CRITICAL_CNTL
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_BUFFER_SIZE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_CRITICAL_AT_SOF
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH_STOP_CNTL
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_BUFFER_CNTL
value|0x03f0
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_START_REQ_MASK
value|(0x7f)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_START_REQ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_STOP_REQ_MASK
value|(0x7f<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_STOP_REQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_CRITICAL_POINT_MASK
value|(0x7f<<16)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_CRITICAL_POINT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_CRITICAL_CNTL
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_BUFFER_SIZE
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_CRITICAL_AT_SOF
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RADEON_GRPH2_STOP_CNTL
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CRNT_FRAME
value|0x0214
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_EXT_CNTL
value|0x0054
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VGA_XOVERSCAN
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_VGA_ATI_LINEAR
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_XCRT_CNT_EN
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_HSYNC_DIS
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VSYNC_DIS
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_DISPLAY_DIS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_SYNC_TRISTAT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CRT_ON
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_EXT_CNTL_DPMS_BYTE
value|0x0055
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_HSYNC_DIS_BYTE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VSYNC_DIS_BYTE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_DISPLAY_DIS_BYTE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_GEN_CNTL
value|0x0050
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_DBL_SCAN_EN
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_INTERLACE_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CSYNC_EN
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_ICON_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CUR_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VSTAT_MODE_MASK
value|(3<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CUR_MODE_MASK
value|(7<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CUR_MODE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CUR_MODE_MONO
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CUR_MODE_24BPP
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_EXT_DISP_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_DISP_REQ_EN_B
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_GEN_CNTL
value|0x03f8
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_DBL_SCAN_EN
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_INTERLACE_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_SYNC_TRISTAT
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_HSYNC_TRISTAT
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VSYNC_TRISTAT
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CRT2_ON
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_PIX_WIDTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_PIX_WIDTH_MASK
value|(0xf<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_ICON_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CUR_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CUR_MODE_MASK
value|(7<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_DISP_DIS
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_DISP_REQ_EN_B
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CSYNC_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_HSYNC_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VSYNC_DIS
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_MORE_CNTL
value|0x27c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_AUTO_HORZ_CENTER_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_AUTO_VERT_CENTER_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_CUTOFF_ACTIVE_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_CUTOFF_ACTIVE_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_GUI_TRIG_VLINE
value|0x0218
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_STRT_WID
value|0x0204
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_STRT_PIX
value|(0x07<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_STRT_CHAR
value|(0x3ff<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_STRT_CHAR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_WID
value|(0x3f<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_WID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_SYNC_POL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_STRT_WID
value|0x0304
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_STRT_PIX
value|(0x07<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_STRT_CHAR
value|(0x3ff<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_STRT_CHAR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_WID
value|(0x3f<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_WID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_SYNC_POL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_TOTAL_DISP
value|0x0200
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_TOTAL
value|(0x03ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_TOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_DISP
value|(0x01ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_H_DISP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_TOTAL_DISP
value|0x0300
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_TOTAL
value|(0x03ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_TOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_DISP
value|(0x01ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_H_DISP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET_RIGHT
value|0x0220
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET
value|0x0224
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET__GUI_TRIG_OFFSET
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET__OFFSET_LOCK
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET
value|0x0324
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET__GUI_TRIG_OFFSET
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET__OFFSET_LOCK
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET_CNTL
value|0x0228
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_TILE_LINE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_TILE_LINE_RIGHT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R300_CRTC_X_Y_MODE_EN_RIGHT
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_RIGHT_MASK
value|(3<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_RIGHT_AUTO
value|(0<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_RIGHT_SINGLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_RIGHT_DOUBLE
value|(2<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_RIGHT_DIS
value|(3<< 7)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_X_Y_MODE_EN
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_AUTO
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_SINGLE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_DOUBLE
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_BUFFER_DIS
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_EN_RIGHT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MICRO_TILE_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MACRO_TILE_EN_RIGHT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_MACRO_TILE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_TILE_EN_RIGHT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_TILE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_OFFSET_FLIP_CNTL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_STEREO_OFFSET_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_GUI_TRIG_OFFSET_LEFT_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_GUI_TRIG_OFFSET_RIGHT_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|R300_CRTC_TILE_X0_Y0
value|0x0350
end_define

begin_define
define|#
directive|define
name|R300_CRTC2_TILE_X0_Y0
value|0x0358
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET_CNTL
value|0x0328
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_OFFSET_FLIP_CNTL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_TILE_EN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_PITCH
value|0x022c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_PITCH__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_PITCH__RIGHT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_PITCH
value|0x032c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_STATUS
value|0x005c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_CUR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_SAVE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_SAVE_CLEAR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_STATUS
value|0x03fc
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_CUR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_SAVE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_SAVE_CLEAR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_STRT_WID
value|0x020c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_STRT
value|(0x7ff<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_STRT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_WID
value|(0x1f<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_WID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_SYNC_POL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_STRT_WID
value|0x030c
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_STRT
value|(0x7ff<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_STRT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_WID
value|(0x1f<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_WID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_SYNC_POL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_TOTAL_DISP
value|0x0208
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_TOTAL
value|(0x07ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_TOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_DISP
value|(0x07ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_V_DISP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_TOTAL_DISP
value|0x0308
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_TOTAL
value|(0x07ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_TOTAL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_DISP
value|(0x07ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_V_DISP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VLINE_CRNT_VLINE
value|0x0210
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_CRNT_VLINE_MASK
value|(0x7ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_CRNT_FRAME
value|0x0314
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_GUI_TRIG_VLINE
value|0x0318
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VLINE_CRNT_VLINE
value|0x0310
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC8_DATA
value|0x03d5
end_define

begin_comment
comment|/* VGA, 0x3b5 */
end_comment

begin_define
define|#
directive|define
name|RADEON_CRTC8_IDX
value|0x03d4
end_define

begin_comment
comment|/* VGA, 0x3b4 */
end_comment

begin_define
define|#
directive|define
name|RADEON_CUR_CLR0
value|0x026c
end_define

begin_define
define|#
directive|define
name|RADEON_CUR_CLR1
value|0x0270
end_define

begin_define
define|#
directive|define
name|RADEON_CUR_HORZ_VERT_OFF
value|0x0268
end_define

begin_define
define|#
directive|define
name|RADEON_CUR_HORZ_VERT_POSN
value|0x0264
end_define

begin_define
define|#
directive|define
name|RADEON_CUR_OFFSET
value|0x0260
end_define

begin_define
define|#
directive|define
name|RADEON_CUR_LOCK
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_CLR0
value|0x036c
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_CLR1
value|0x0370
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_HORZ_VERT_OFF
value|0x0368
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_HORZ_VERT_POSN
value|0x0364
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_OFFSET
value|0x0360
end_define

begin_define
define|#
directive|define
name|RADEON_CUR2_LOCK
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_CNTL
value|0x0058
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_RANGE_CNTL
value|(3<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_RANGE_CNTL_PS2
value|(2<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_RANGE_CNTL_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_BLANKING
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_CMP_EN
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_CMP_OUTPUT
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_8BIT_EN
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_TVO_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_VGA_ADR_EN
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_PDWN
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_MASK_ALL
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_CNTL2
value|0x007c
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_TV_CLK_SEL
value|(0<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_DAC_CLK_SEL
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_DAC2_CLK_SEL
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_PALETTE_ACC_CTL
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_CMP_EN
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_CMP_OUT_R
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_CMP_OUT_G
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_CMP_OUT_B
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_CMP_OUTPUT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_EXT_CNTL
value|0x0280
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_FORCE_BLANK_OFF_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC2_FORCE_DATA_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_BLANK_OFF_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SEL_MASK
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SEL_R
value|(0<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SEL_G
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SEL_B
value|(2<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SEL_RGB
value|(3<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_MASK
value|0x0003ff00
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_FORCE_DATA_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_MACRO_CNTL
value|0x0d04
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_PDWN_R
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_PDWN_G
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_PDWN_B
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN
value|0x0d08
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_D3_CRTC_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_D3_CRTC2_EN
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_DPMS_ON
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_DPMS_STANDBY
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_DPMS_SUSPEND
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_PWR_MAN_DPMS_OFF
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D3_RST
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D3_REG_RST
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D3_GRPH_RST
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D3_SUBPIC_RST
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D3_OV0_RST
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D1D2_GRPH_RST
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D1D2_SUBPIC_RST
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_D1D2_OV0_RST
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_DIG_TMDS_ENABLE_RST
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_ENABLE_RST
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_AUTO_PWRUP_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_CNTL
value|0x088c
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_NBLANK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_NHOLD
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_PEDESTAL
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MONITOR_DETECT_EN
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_CMPOUT
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_STD_MASK
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_STD_PAL
value|(0<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_STD_NTSC
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_STD_PS2
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_STD_RS343
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_BGSLEEP
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_BGADJ_MASK
value|(0xf<<  16)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_BGADJ_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_DACADJ_MASK
value|(0xf<<  20)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_DACADJ_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_RDACPD
value|(1<<  24)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_GDACPD
value|(1<<  25)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_BDACPD
value|(1<<  26)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_RDACDET
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_GDACDET
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DAC_BDACDET
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R420_TV_DAC_DACADJ_MASK
value|(0x1f<<  20)
end_define

begin_define
define|#
directive|define
name|R420_TV_DAC_RDACPD
value|(1<<  25)
end_define

begin_define
define|#
directive|define
name|R420_TV_DAC_GDACPD
value|(1<<  26)
end_define

begin_define
define|#
directive|define
name|R420_TV_DAC_BDACPD
value|(1<<  27)
end_define

begin_define
define|#
directive|define
name|R420_TV_DAC_TVENABLE
value|(1<<  28)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_HW_DEBUG
value|0x0d14
end_define

begin_define
define|#
directive|define
name|RADEON_CRT2_DISP1_SEL
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_OUTPUT_CNTL
value|0x0d64
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC_SOURCE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC2_SOURCE_MASK
value|0x0c
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC_SOURCE_CRTC2
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC_SOURCE_RMX
value|0x02
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC_SOURCE_LTU
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_DAC2_SOURCE_CRTC2
value|0x04
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVDAC_SOURCE_MASK
value|(0x03<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVDAC_SOURCE_CRTC
value|0x0
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVDAC_SOURCE_CRTC2
value|(0x01<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVDAC_SOURCE_RMX
value|(0x02<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVDAC_SOURCE_LTU
value|(0x03<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TRANS_MATRIX_MASK
value|(0x03<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TRANS_MATRIX_ALPHA_MSB
value|(0x00<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TRANS_MATRIX_GRAPHICS
value|(0x01<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TRANS_MATRIX_VIDEO
value|(0x02<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TV_SOURCE_CRTC
value|(1<< 16)
end_define

begin_comment
comment|/* crtc1 or crtc2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_DISP_TV_SOURCE_LTU
value|(0<< 16)
end_define

begin_comment
comment|/* linear transform unit */
end_comment

begin_define
define|#
directive|define
name|RADEON_DISP_TV_OUT_CNTL
value|0x0d6c
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TV_PATH_SRC_CRTC2
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TV_PATH_SRC_CRTC1
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_CRC_SIG
value|0x02cc
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_DATA
value|0x03c9
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_DAC_MASK
value|0x03c6
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_DAC_R_INDEX
value|0x03c7
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_DAC_W_INDEX
value|0x03c8
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_DDA_CONFIG
value|0x02e0
end_define

begin_define
define|#
directive|define
name|RADEON_DDA_ON_OFF
value|0x02e4
end_define

begin_define
define|#
directive|define
name|RADEON_DEFAULT_OFFSET
value|0x16e0
end_define

begin_define
define|#
directive|define
name|RADEON_DEFAULT_PITCH
value|0x16e4
end_define

begin_define
define|#
directive|define
name|RADEON_DEFAULT_SC_BOTTOM_RIGHT
value|0x16e8
end_define

begin_define
define|#
directive|define
name|RADEON_DEFAULT_SC_RIGHT_MAX
value|(0x1fff<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEFAULT_SC_BOTTOM_MAX
value|(0x1fff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DESTINATION_3D_CLR_CMP_VAL
value|0x1820
end_define

begin_define
define|#
directive|define
name|RADEON_DESTINATION_3D_CLR_CMP_MSK
value|0x1824
end_define

begin_define
define|#
directive|define
name|RADEON_DEVICE_ID
value|0x0f02
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_DISP_MISC_CNTL
value|0x0d00
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_GRPH_PP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_MERGE_CNTL
value|0x0d60
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_ALPHA_MODE_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_ALPHA_MODE_KEY
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_ALPHA_MODE_PER_PIXEL
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_ALPHA_MODE_GLOBAL
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_RGB_OFFSET_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_GRPH_ALPHA_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_OV0_ALPHA_MASK
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_BYPASS
value|(0x01<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP2_MERGE_CNTL
value|0x0d68
end_define

begin_define
define|#
directive|define
name|RADEON_DISP2_RGB_OFFSET_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_A
value|0x0d80
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_B
value|0x0d84
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_C
value|0x0d88
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_D
value|0x0d8c
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_E
value|0x0d90
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_LIN_TRANS_GRPH_F
value|0x0d98
end_define

begin_define
define|#
directive|define
name|RADEON_DP_BRUSH_BKGD_CLR
value|0x1478
end_define

begin_define
define|#
directive|define
name|RADEON_DP_BRUSH_FRGD_CLR
value|0x147c
end_define

begin_define
define|#
directive|define
name|RADEON_DP_CNTL
value|0x16c0
end_define

begin_define
define|#
directive|define
name|RADEON_DST_X_LEFT_TO_RIGHT
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y_TOP_TO_BOTTOM
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_DST_TILE_LINEAR
value|(0<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_DST_TILE_MACRO
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_DST_TILE_MICRO
value|(2<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_DST_TILE_BOTH
value|(3<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_CNTL_XDIR_YDIR_YMAJOR
value|0x16d0
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y_MAJOR
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y_DIR_TOP_TO_BOTTOM
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_X_DIR_LEFT_TO_RIGHT
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_DATATYPE
value|0x16c4
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_BIG_ENDIAN_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_GUI_MASTER_CNTL
value|0x146c
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_PITCH_OFFSET_CNTL
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_PITCH_OFFSET_CNTL
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_CLIPPING
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_CLIPPING
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_DATATYPE_MASK
value|(0x0f<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_8X8_MONO_FG_BG
value|(0<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_8X8_MONO_FG_LA
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_1X8_MONO_FG_BG
value|(4<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_1X8_MONO_FG_LA
value|(5<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_32x1_MONO_FG_BG
value|(6<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_32x1_MONO_FG_LA
value|(7<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_32x32_MONO_FG_BG
value|(8<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_32x32_MONO_FG_LA
value|(9<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_8x8_COLOR
value|(10<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_1X8_COLOR
value|(12<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_SOLID_COLOR
value|(13<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BRUSH_NONE
value|(15<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_8BPP_CI
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_15BPP
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_16BPP
value|(4<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_24BPP
value|(5<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_32BPP
value|(6<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_8BPP_RGB
value|(7<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_Y8
value|(8<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_RGB8
value|(9<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_VYUY
value|(11<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_YVYU
value|(12<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_AYUV444
value|(14<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_ARGB4444
value|(15<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_DATATYPE_MASK
value|(0x0f<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_DST_DATATYPE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_DATATYPE_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_DATATYPE_MONO_FG_BG
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_DATATYPE_MONO_FG_LA
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_SRC_DATATYPE_COLOR
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BYTE_PIX_ORDER
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BYTE_MSB_TO_LSB
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_BYTE_LSB_TO_MSB
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_CONVERSION_TEMP
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_CONVERSION_TEMP_6500
value|(0<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_CONVERSION_TEMP_9300
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_ROP3_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_SOURCE_MASK
value|(7<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_SOURCE_MEMORY
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_SOURCE_HOST_DATA
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_3D_FCN_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_CLR_CMP_CNTL_DIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_AUX_CLIP_DIS
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_WR_MSK_DIS
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_GMC_LD_BRUSH_Y_X
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_ZERO
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSa
value|0x00880000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_SDna
value|0x00440000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_S
value|0x00cc0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSna
value|0x00220000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_D
value|0x00aa0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSx
value|0x00660000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSo
value|0x00ee0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSon
value|0x00110000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSxn
value|0x00990000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_Dn
value|0x00550000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_SDno
value|0x00dd0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_Sn
value|0x00330000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSno
value|0x00bb0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DSan
value|0x00770000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_ONE
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPa
value|0x00a00000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_PDna
value|0x00500000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_P
value|0x00f00000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPna
value|0x000a0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_D
value|0x00aa0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPx
value|0x005a0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPo
value|0x00fa0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPon
value|0x00050000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_PDxn
value|0x00a50000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_PDno
value|0x00f50000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_Pn
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPno
value|0x00af0000
end_define

begin_define
define|#
directive|define
name|RADEON_ROP3_DPan
value|0x005f0000
end_define

begin_define
define|#
directive|define
name|RADEON_DP_GUI_MASTER_CNTL_C
value|0x1c84
end_define

begin_define
define|#
directive|define
name|RADEON_DP_MIX
value|0x16c8
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_BKGD_CLR
value|0x15dc
end_define

begin_define
define|#
directive|define
name|RADEON_DP_SRC_FRGD_CLR
value|0x15d8
end_define

begin_define
define|#
directive|define
name|RADEON_DP_WRITE_MASK
value|0x16cc
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BRES_DEC
value|0x1630
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BRES_ERR
value|0x1628
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BRES_INC
value|0x162c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BRES_LNTH
value|0x1634
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BRES_LNTH_SUB
value|0x1638
end_define

begin_define
define|#
directive|define
name|RADEON_DST_HEIGHT
value|0x1410
end_define

begin_define
define|#
directive|define
name|RADEON_DST_HEIGHT_WIDTH
value|0x143c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_HEIGHT_WIDTH_8
value|0x158c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_HEIGHT_WIDTH_BW
value|0x15b4
end_define

begin_define
define|#
directive|define
name|RADEON_DST_HEIGHT_Y
value|0x15a0
end_define

begin_define
define|#
directive|define
name|RADEON_DST_LINE_START
value|0x1600
end_define

begin_define
define|#
directive|define
name|RADEON_DST_LINE_END
value|0x1604
end_define

begin_define
define|#
directive|define
name|RADEON_DST_LINE_PATCOUNT
value|0x1608
end_define

begin_define
define|#
directive|define
name|RADEON_BRES_CNTL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_DST_OFFSET
value|0x1404
end_define

begin_define
define|#
directive|define
name|RADEON_DST_PITCH
value|0x1408
end_define

begin_define
define|#
directive|define
name|RADEON_DST_PITCH_OFFSET
value|0x142c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_PITCH_OFFSET_C
value|0x1c80
end_define

begin_define
define|#
directive|define
name|RADEON_PITCH_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_LINEAR
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_MACRO
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_MICRO
value|(2<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_TILE_BOTH
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_WIDTH
value|0x140c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_WIDTH_HEIGHT
value|0x1598
end_define

begin_define
define|#
directive|define
name|RADEON_DST_WIDTH_X
value|0x1588
end_define

begin_define
define|#
directive|define
name|RADEON_DST_WIDTH_X_INCY
value|0x159c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_X
value|0x141c
end_define

begin_define
define|#
directive|define
name|RADEON_DST_X_SUB
value|0x15a4
end_define

begin_define
define|#
directive|define
name|RADEON_DST_X_Y
value|0x1594
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y
value|0x1420
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y_SUB
value|0x15a8
end_define

begin_define
define|#
directive|define
name|RADEON_DST_Y_X
value|0x1438
end_define

begin_define
define|#
directive|define
name|RADEON_FCP_CNTL
value|0x0910
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_PCICLK
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_PCLK
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_PCLKb
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_HREF
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_GND
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_FCP0_SRC_HREFb
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_1
value|0x1704
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_2
value|0x1708
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_3
value|0x170c
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_4
value|0x1710
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_5
value|0x1714
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_6
value|0x1718
end_define

begin_define
define|#
directive|define
name|RADEON_FLUSH_7
value|0x171c
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_3D_TABLE_START
value|0x1810
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_3D_TABLE_END
value|0x1814
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_3D_TABLE_DENSITY
value|0x181c
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_TABLE_INDEX
value|0x1a14
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_TABLE_DATA
value|0x1a18
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_H_TOTAL_DISP
value|0x0250
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_V_TOTAL_DISP
value|0x0254
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_H_TOTAL_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_H_DISP_MASK
value|0x01ff0000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_V_TOTAL_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_V_DISP_MASK
value|0x0fff0000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H_SYNC_STRT_CHAR_MASK
value|0x00001ff8
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H_SYNC_WID_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V_SYNC_STRT_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V_SYNC_WID_MASK
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_H_TOTAL_SHIFT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_H_DISP_SHIFT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_V_TOTAL_SHIFT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_V_DISP_SHIFT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H_SYNC_STRT_CHAR_SHIFT
value|0x00000003
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H_SYNC_WID_SHIFT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V_SYNC_STRT_SHIFT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V_SYNC_WID_SHIFT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_FP_GEN_CNTL
value|0x0284
end_define

begin_define
define|#
directive|define
name|RADEON_FP_FPON
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_BLANK_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_TMDS_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_PANEL_FORMAT
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_EN_TMDS
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DETECT_SENSE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DETECT_INT_POL
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|R200_FP_SOURCE_SEL_MASK
value|(3<<  10)
end_define

begin_define
define|#
directive|define
name|R200_FP_SOURCE_SEL_CRTC1
value|(0<<  10)
end_define

begin_define
define|#
directive|define
name|R200_FP_SOURCE_SEL_CRTC2
value|(1<<  10)
end_define

begin_define
define|#
directive|define
name|R200_FP_SOURCE_SEL_RMX
value|(2<<  10)
end_define

begin_define
define|#
directive|define
name|R200_FP_SOURCE_SEL_TRANS
value|(3<<  10)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_SEL_CRTC1
value|(0<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_SEL_CRTC2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_HPD_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_DONT_SHADOW_HPAR
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_DONT_SHADOW_VPAR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_DONT_SHADOW_HEND
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_USE_SHADOW_VEND
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_RMX_HVSYNC_CONTROL_EN
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DFP_SYNC_SEL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRTC_LOCK_8DOT
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRT_SYNC_SEL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_USE_SHADOW_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_CRT_SYNC_ALT
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_GEN_CNTL
value|0x0288
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_BLANK_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_ON
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_PANEL_FORMAT
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DETECT_SENSE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DETECT_INT_POL
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|R200_FP2_SOURCE_SEL_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|R200_FP2_SOURCE_SEL_CRTC1
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|R200_FP2_SOURCE_SEL_CRTC2
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R200_FP2_SOURCE_SEL_RMX
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|R200_FP2_SOURCE_SEL_TRANS_UNIT
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_SRC_SEL_MASK
value|(3<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_SRC_SEL_CRTC2
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_FP_POL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_LP_POL
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_SCK_POL
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_LCD_CNTL_MASK
value|(7<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_PAD_FLOP_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_CRC_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_CRC_READ_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DVO_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DVO_RATE_SEL_SDR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R200_FP2_DVO_RATE_SEL_SDR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R300_FP2_DVO_CLOCK_MODE_SINGLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R300_FP2_DVO_DUAL_CHANNEL_EN
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H_SYNC_STRT_WID
value|0x02c4
end_define

begin_define
define|#
directive|define
name|RADEON_FP_H2_SYNC_STRT_WID
value|0x03c4
end_define

begin_define
define|#
directive|define
name|RADEON_FP_HORZ_STRETCH
value|0x028c
end_define

begin_define
define|#
directive|define
name|RADEON_FP_HORZ2_STRETCH
value|0x038c
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_STRETCH_RATIO_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_STRETCH_RATIO_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_PANEL_SIZE
value|(0x1ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_PANEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_STRETCH_PIXREP
value|(0<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_STRETCH_BLEND
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_STRETCH_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_AUTO_RATIO
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_FP_LOOP_STRETCH
value|(0x7<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_HORZ_AUTO_RATIO_INC
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_HORZ_VERT_ACTIVE
value|0x0278
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V_SYNC_STRT_WID
value|0x02c8
end_define

begin_define
define|#
directive|define
name|RADEON_FP_VERT_STRETCH
value|0x0290
end_define

begin_define
define|#
directive|define
name|RADEON_FP_V2_SYNC_STRT_WID
value|0x03c8
end_define

begin_define
define|#
directive|define
name|RADEON_FP_VERT2_STRETCH
value|0x0390
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_PANEL_SIZE
value|(0xfff<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_PANEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_RATIO_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_RATIO_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_RATIO_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_LINEREP
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_BLEND
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_AUTO_RATIO_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_AUTO_RATIO_INC
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_VERT_STRETCH_RESERVED
value|0x71000000
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_GEN_CNTL
value|0x0384
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_ON
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_BLANK_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS400_TMDS_2ND_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RS400_PANEL_FORMAT_2ND
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_EN_TMDS
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_DETECT_SENSE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_SOURCE_SEL_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_SOURCE_SEL_CRTC1
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_SOURCE_SEL_CRTC2
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_SOURCE_SEL_RMX
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP_2ND_DETECT_EN
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RS400_HPD_2ND_SEL
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_GEN_CNTL
value|0x0388
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_BLANK_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_ON
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_PANEL_FORMAT
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_DETECT_SENSE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_SOURCE_SEL_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_SOURCE_SEL_CRTC1
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_SOURCE_SEL_CRTC2
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_SOURCE_SEL_RMX
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RS400_FP2_2_DVO2_EN
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RS400_TMDS2_CNTL
value|0x0394
end_define

begin_define
define|#
directive|define
name|RS400_TMDS2_TRANSMITTER_CNTL
value|0x03a4
end_define

begin_define
define|#
directive|define
name|RS400_TMDS2_PLLEN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RS400_TMDS2_PLLRST
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_GEN_INT_CNTL
value|0x0040
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_MASK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DETECT_MASK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_MASK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DETECT_MASK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_IDLE_MASK
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_GEN_INT_STATUS
value|0x0044
end_define

begin_define
define|#
directive|define
name|AVIVO_DISPLAY_INT_STATUS
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_STAT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC_VBLANK_STAT_ACK
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DETECT_STAT
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_FP_DETECT_STAT_ACK
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_STAT
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_CRTC2_VBLANK_STAT_ACK
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DETECT_STAT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_FP2_DETECT_STAT_ACK
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_IDLE_STAT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_IDLE_STAT_ACK
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_FIRE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_TEST
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_INT_TEST_ACK
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_GENENB
value|0x03c3
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENFC_RD
value|0x03ca
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENFC_WT
value|0x03da
end_define

begin_comment
comment|/* VGA, 0x03ba */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENMO_RD
value|0x03cc
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENMO_WT
value|0x03c2
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENS0
value|0x03c2
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GENS1
value|0x03da
end_define

begin_comment
comment|/* VGA, 0x03ba */
end_comment

begin_define
define|#
directive|define
name|RADEON_GPIO_MONID
value|0x0068
end_define

begin_comment
comment|/* DDC interface via I2C */
end_comment

begin_comment
comment|/* DDC3 */
end_comment

begin_define
define|#
directive|define
name|RADEON_GPIO_MONIDB
value|0x006c
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_CRT2_DDC
value|0x006c
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_DVI_DDC
value|0x0064
end_define

begin_comment
comment|/* DDC2 */
end_comment

begin_define
define|#
directive|define
name|RADEON_GPIO_VGA_DDC
value|0x0060
end_define

begin_comment
comment|/* DDC1 */
end_comment

begin_define
define|#
directive|define
name|RADEON_GPIO_A_0
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_A_1
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_Y_0
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_Y_1
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_Y_SHIFT_0
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_Y_SHIFT_1
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_EN_0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_EN_1
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIO_MASK_0
value|(1<< 24)
end_define

begin_comment
comment|/*??*/
end_comment

begin_define
define|#
directive|define
name|RADEON_GPIO_MASK_1
value|(1<< 25)
end_define

begin_comment
comment|/*??*/
end_comment

begin_define
define|#
directive|define
name|RADEON_GRPH8_DATA
value|0x03cf
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GRPH8_IDX
value|0x03ce
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG0
value|0x15e0
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG1
value|0x15e4
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG2
value|0x15e8
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG3
value|0x15ec
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG4
value|0x15f0
end_define

begin_define
define|#
directive|define
name|RADEON_GUI_SCRATCH_REG5
value|0x15f4
end_define

begin_define
define|#
directive|define
name|RADEON_HEADER
value|0x0f0e
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_HOST_DATA0
value|0x17c0
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA1
value|0x17c4
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA2
value|0x17c8
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA3
value|0x17cc
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA4
value|0x17d0
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA5
value|0x17d4
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA6
value|0x17d8
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA7
value|0x17dc
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_LAST
value|0x17e0
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_PATH_CNTL
value|0x0130
end_define

begin_define
define|#
directive|define
name|RADEON_HP_LIN_RD_CACHE_DIS
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_READ_BUFFER_INVALIDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_SOFT_RESET
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_HDP_APER_CNTL
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_HTOTAL_CNTL
value|0x0009
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_HTOT_CNTL_VGA_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_HTOTAL2_CNTL
value|0x002e
end_define

begin_comment
comment|/* PLL */
end_comment

begin_comment
comment|/* Multimedia I2C bus */
end_comment

begin_define
define|#
directive|define
name|RADEON_I2C_CNTL_0
value|0x0090
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_DONE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_NACK
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_HALT
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_SOFT_RST
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_DRIVE_EN
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_DRIVE_SEL
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_START
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_STOP
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_RECEIVE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_ABORT
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_GO
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_PRESCALE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_CNTL_1
value|0x0094
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_DATA_COUNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_ADDR_COUNT_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_INTRA_BYTE_DELAY_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_SEL
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_TIME_LIMIT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_I2C_DATA
value|0x0098
end_define

begin_define
define|#
directive|define
name|RADEON_DVI_I2C_CNTL_0
value|0x02e0
end_define

begin_define
define|#
directive|define
name|R200_DVI_I2C_PIN_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 3)
end_define

begin_define
define|#
directive|define
name|R200_SEL_DDC1
value|0
end_define

begin_comment
comment|/* depends on asic */
end_comment

begin_define
define|#
directive|define
name|R200_SEL_DDC2
value|1
end_define

begin_comment
comment|/* depends on asic */
end_comment

begin_define
define|#
directive|define
name|R200_SEL_DDC3
value|2
end_define

begin_comment
comment|/* depends on asic */
end_comment

begin_define
define|#
directive|define
name|RADEON_SW_WANTS_TO_USE_DVI_I2C
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_CAN_USE_DVI_I2C
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_SW_DONE_USING_DVI_I2C
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_HW_NEEDS_DVI_I2C
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_ABORT_HW_DVI_I2C
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_HW_USING_DVI_I2C
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_DVI_I2C_CNTL_1
value|0x02e4
end_define

begin_define
define|#
directive|define
name|RADEON_DVI_I2C_DATA
value|0x02e8
end_define

begin_define
define|#
directive|define
name|RADEON_INTERRUPT_LINE
value|0x0f3c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_INTERRUPT_PIN
value|0x0f3d
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_IO_BASE
value|0x0f14
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_LATENCY
value|0x0f0d
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_LEAD_BRES_DEC
value|0x1608
end_define

begin_define
define|#
directive|define
name|RADEON_LEAD_BRES_LNTH
value|0x161c
end_define

begin_define
define|#
directive|define
name|RADEON_LEAD_BRES_LNTH_SUB
value|0x1624
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_GEN_CNTL
value|0x02d0
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_ON
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_DISPLAY_DIS
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PANEL_TYPE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PANEL_FORMAT
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_NO_FM
value|(0<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_2_GREY
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_4_GREY
value|(2<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_RST_FM
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_EN
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_BL_MOD_LEVEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_BL_MOD_LEVEL_MASK
value|(0xff<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_BL_MOD_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_BL_CLK_SEL
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_DIGON
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_BLON
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_FP_POL_LOW
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_LP_POL_LOW
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_DTM_POL_LOW
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_SEL_CRTC2
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_FPDI_EN
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_HSYNC_DELAY_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PLL_CNTL
value|0x02d4
end_define

begin_define
define|#
directive|define
name|RADEON_HSYNC_DELAY_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_HSYNC_DELAY_MASK
value|(0xf<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PLL_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PLL_RESET
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R300_LVDS_SRC_SEL_MASK
value|(3<< 18)
end_define

begin_define
define|#
directive|define
name|R300_LVDS_SRC_SEL_CRTC1
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|R300_LVDS_SRC_SEL_CRTC2
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R300_LVDS_SRC_SEL_RMX
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_SS_GEN_CNTL
value|0x02ec
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PWRSEQ_DELAY1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_LVDS_PWRSEQ_DELAY2_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_LATENCY
value|0x0f3f
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_DISPLAY_BASE_ADDR
value|0x23c
end_define

begin_define
define|#
directive|define
name|RADEON_DISPLAY2_BASE_ADDR
value|0x33c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_BASE_ADDR
value|0x43c
end_define

begin_define
define|#
directive|define
name|RADEON_NB_TOM
value|0x15c
end_define

begin_define
define|#
directive|define
name|R300_MC_INIT_MISC_LAT_TIMER
value|0x180
end_define

begin_define
define|#
directive|define
name|R300_MC_DISP0R_INIT_LAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R300_MC_DISP0R_INIT_LAT_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|R300_MC_DISP1R_INIT_LAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R300_MC_DISP1R_INIT_LAT_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_MCLK_CNTL
value|0x0012
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_MCLKA_SRC_SEL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MCLKA
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MCLKB
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_YCLKA
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_YCLKB
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_MC
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCEON_AIC
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R300_DISABLE_MC_MCLKA
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R300_DISABLE_MC_MCLKB
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_MCLK_MISC
value|0x001f
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_MC_MCLK_MAX_DYN_STOP_LAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_IO_MCLK_MAX_DYN_STOP_LAT
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_MC_MCLK_DYN_ENABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_IO_MCLK_DYN_ENABLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_GPIOPAD_MASK
value|0x0198
end_define

begin_define
define|#
directive|define
name|RADEON_GPIOPAD_A
value|0x019c
end_define

begin_define
define|#
directive|define
name|RADEON_GPIOPAD_EN
value|0x01a0
end_define

begin_define
define|#
directive|define
name|RADEON_GPIOPAD_Y
value|0x01a4
end_define

begin_define
define|#
directive|define
name|RADEON_MDGPIO_MASK
value|0x01a8
end_define

begin_define
define|#
directive|define
name|RADEON_MDGPIO_A
value|0x01ac
end_define

begin_define
define|#
directive|define
name|RADEON_MDGPIO_EN
value|0x01b0
end_define

begin_define
define|#
directive|define
name|RADEON_MDGPIO_Y
value|0x01b4
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_ADDR_CONFIG
value|0x0148
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_BASE
value|0x0f10
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_MEM_CNTL
value|0x0140
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_NUM_CHANNELS_MASK
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_USE_B_CH_ONLY
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RV100_HALF_MODE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|R300_MEM_NUM_CHANNELS_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|R300_MEM_USE_CD_CH_ONLY
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_TIMING_CNTL
value|0x0144
end_define

begin_comment
comment|/* EXT_MEM_CNTL */
end_comment

begin_define
define|#
directive|define
name|RADEON_MEM_INIT_LAT_TIMER
value|0x0154
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_INTF_CNTL
value|0x014c
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_SDRAM_MODE_REG
value|0x0158
end_define

begin_define
define|#
directive|define
name|RADEON_SDRAM_MODE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|RADEON_B3MEM_RESET_MASK
value|0x6fffffff
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_CFG_TYPE_DDR
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_STR_CNTL
value|0x0150
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_PWRUP_COMPL_A
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_PWRUP_COMPL_B
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|R300_MEM_PWRUP_COMPL_C
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|R300_MEM_PWRUP_COMPL_D
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_PWRUP_COMPLETE
value|0x03
end_define

begin_define
define|#
directive|define
name|R300_MEM_PWRUP_COMPLETE
value|0x0f
end_define

begin_define
define|#
directive|define
name|RADEON_MC_STATUS
value|0x0150
end_define

begin_define
define|#
directive|define
name|RADEON_MC_IDLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R300_MC_IDLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_VGA_RP_SEL
value|0x003c
end_define

begin_define
define|#
directive|define
name|RADEON_MEM_VGA_WP_SEL
value|0x0038
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_GRANT
value|0x0f3e
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_MM_DATA
value|0x0004
end_define

begin_define
define|#
directive|define
name|RADEON_MM_INDEX
value|0x0000
end_define

begin_define
define|#
directive|define
name|RADEON_MM_APER
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_MPLL_CNTL
value|0x000e
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_MPP_TB_CONFIG
value|0x01c0
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|RADEON_MPP_GP_CONFIG
value|0x01c8
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|RADEON_SEPROM_CNTL1
value|0x01c0
end_define

begin_define
define|#
directive|define
name|RADEON_SCK_PRESCALE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_SCK_PRESCALE_MASK
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|R300_MC_IND_INDEX
value|0x01f8
end_define

begin_define
define|#
directive|define
name|R300_MC_IND_ADDR_MASK
value|0x3f
end_define

begin_define
define|#
directive|define
name|R300_MC_IND_WR_EN
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R300_MC_IND_DATA
value|0x01fc
end_define

begin_define
define|#
directive|define
name|R300_MC_READ_CNTL_AB
value|0x017c
end_define

begin_define
define|#
directive|define
name|R300_MEM_RBS_POSITION_A_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|R300_MC_READ_CNTL_CD_mcind
value|0x24
end_define

begin_define
define|#
directive|define
name|R300_MEM_RBS_POSITION_C_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_N_VIF_COUNT
value|0x0248
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL
value|0x0470
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SOFT_BUF_NUM
value|0x00000007
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SOFT_REPEAT_FIELD
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SOFT_BUF_ODD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_IGNORE_REPEAT_FIELD
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SOFT_EOF_TOGGLE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_VID_PORT_SELECT
value|0x00000300
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_P1_FIRST_LINE_EVEN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SHIFT_EVEN_DOWN
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_SHIFT_ODD_DOWN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_AUTO_FLIP_CNTL_FIELD_POL_SOURCE
value|0x00800000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_COLOUR_CNTL
value|0x04E0
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_DEINTERLACE_PATTERN
value|0x0474
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_EXCLUSIVE_HORZ
value|0x0408
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_HORZ_START_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_HORZ_END_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_HORZ_BACK_PORCH_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_HORZ_EXCLUSIVE_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_EXCLUSIVE_VERT
value|0x040C
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_VERT_START_MASK
value|0x000003ff
end_define

begin_define
define|#
directive|define
name|RADEON_EXCL_VERT_END_MASK
value|0x03ff0000
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FILTER_CNTL
value|0x04A0
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_PROGRAMMABLE_COEF
value|0x0
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_HC_COEF_HORZ_Y
value|0x1
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_HC_COEF_HORZ_UV
value|0x2
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_HC_COEF_VERT_Y
value|0x4
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_HC_COEF_VERT_UV
value|0x8
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_HARDCODED_COEF
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_FILTER_COEF_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FOUR_TAP_COEF_0
value|0x04B0
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FOUR_TAP_COEF_1
value|0x04B4
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FOUR_TAP_COEF_2
value|0x04B8
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FOUR_TAP_COEF_3
value|0x04BC
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FOUR_TAP_COEF_4
value|0x04C0
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_FLAG_CNTL
value|0x04DC
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_000_00F
value|0x0d40
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_010_01F
value|0x0d44
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_020_03F
value|0x0d48
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_040_07F
value|0x0d4c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_080_0BF
value|0x0e00
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_0C0_0FF
value|0x0e04
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_100_13F
value|0x0e08
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_140_17F
value|0x0e0c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_180_1BF
value|0x0e10
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_1C0_1FF
value|0x0e14
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_200_23F
value|0x0e18
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_240_27F
value|0x0e1c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_280_2BF
value|0x0e20
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_2C0_2FF
value|0x0e24
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_300_33F
value|0x0e28
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_340_37F
value|0x0e2c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_380_3BF
value|0x0d50
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GAMMA_3C0_3FF
value|0x0d54
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GRAPHICS_KEY_CLR_LOW
value|0x04EC
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_GRAPHICS_KEY_CLR_HIGH
value|0x04F0
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_H_INC
value|0x0480
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_KEY_CNTL
value|0x04F4
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEO_KEY_FN_MASK
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEO_KEY_FN_FALSE
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEO_KEY_FN_TRUE
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEO_KEY_FN_EQ
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEO_KEY_FN_NE
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|RADEON_GRAPHIC_KEY_FN_MASK
value|0x00000030L
end_define

begin_define
define|#
directive|define
name|RADEON_GRAPHIC_KEY_FN_FALSE
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RADEON_GRAPHIC_KEY_FN_TRUE
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|RADEON_GRAPHIC_KEY_FN_EQ
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|RADEON_GRAPHIC_KEY_FN_NE
value|0x00000030L
end_define

begin_define
define|#
directive|define
name|RADEON_CMP_MIX_MASK
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|RADEON_CMP_MIX_OR
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RADEON_CMP_MIX_AND
value|0x00000100L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_A
value|0x0d20
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_B
value|0x0d24
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_C
value|0x0d28
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_D
value|0x0d2c
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_E
value|0x0d30
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_LIN_TRANS_F
value|0x0d34
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_BLANK_LINES_AT_TOP
value|0x0430
end_define

begin_define
define|#
directive|define
name|RADEON_P1_BLNK_LN_AT_TOP_M1_MASK
value|0x00000fffL
end_define

begin_define
define|#
directive|define
name|RADEON_P1_ACTIVE_LINES_M1
value|0x0fff0000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_H_ACCUM_INIT
value|0x0488
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_V_ACCUM_INIT
value|0x0428
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_MAX_LN_IN_PER_LN_OUT
value|0x00000003L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_V_ACCUM_INIT_MASK
value|0x01ff8000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P1_X_START_END
value|0x0494
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P2_X_START_END
value|0x0498
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P23_BLANK_LINES_AT_TOP
value|0x0434
end_define

begin_define
define|#
directive|define
name|RADEON_P23_BLNK_LN_AT_TOP_M1_MASK
value|0x000007ffL
end_define

begin_define
define|#
directive|define
name|RADEON_P23_ACTIVE_LINES_M1
value|0x07ff0000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P23_H_ACCUM_INIT
value|0x048C
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P23_V_ACCUM_INIT
value|0x042C
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_P3_X_START_END
value|0x049C
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_REG_LOAD_CNTL
value|0x0410
end_define

begin_define
define|#
directive|define
name|RADEON_REG_LD_CTL_LOCK
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RADEON_REG_LD_CTL_VBLANK_DURING_LOCK
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RADEON_REG_LD_CTL_STALL_GUI_UNTIL_FLIP
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|RADEON_REG_LD_CTL_LOCK_READBACK
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|RADEON_REG_LD_CTL_FLIP_READBACK
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_SCALE_CNTL
value|0x0420
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_HORZ_PICK_NEAREST
value|0x00000004L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_VERT_PICK_NEAREST
value|0x00000008L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SIGNED_UV
value|0x00000010L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_GAMMA_SEL_MASK
value|0x00000060L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_GAMMA_SEL_BRIGHT
value|0x00000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_GAMMA_SEL_G22
value|0x00000020L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_GAMMA_SEL_G18
value|0x00000040L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_GAMMA_SEL_G14
value|0x00000060L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_COMCORE_SHIFT_UP_ONE
value|0x00000080L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SURFAC_FORMAT
value|0x00000f00L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_15BPP
value|0x00000300L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_16BPP
value|0x00000400L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_32BPP
value|0x00000600L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_YUV9
value|0x00000900L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_YUV12
value|0x00000A00L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_VYUY422
value|0x00000B00L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOURCE_YVYU422
value|0x00000C00L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_ADAPTIVE_DEINT
value|0x00001000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_TEMPORAL_DEINT
value|0x00002000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_CRTC_SEL
value|0x00004000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SMART_SWITCH
value|0x00008000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_BURST_PER_PLANE
value|0x007F0000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_DOUBLE_BUFFER
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_DIS_LIMIT
value|0x08000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_LIN_TRANS_BYPASS
value|0x10000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_INT_EMU
value|0x20000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_ENABLE
value|0x40000000L
end_define

begin_define
define|#
directive|define
name|RADEON_SCALER_SOFT_RESET
value|0x80000000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_STEP_BY
value|0x0484
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_TEST
value|0x04F8
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_V_INC
value|0x0424
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF_PITCH0_VALUE
value|0x0460
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF_PITCH1_VALUE
value|0x0464
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF0_BASE_ADRS
value|0x0440
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF0_PITCH_SEL
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF0_TILE_ADRS
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF0_BASE_ADRS_MASK
value|0x03fffff0L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF0_1ST_LINE_LSBS_MASK
value|0x48000000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF1_BASE_ADRS
value|0x0444
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF1_PITCH_SEL
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF1_TILE_ADRS
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF1_BASE_ADRS_MASK
value|0x03fffff0L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF1_1ST_LINE_LSBS_MASK
value|0x48000000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF2_BASE_ADRS
value|0x0448
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF2_PITCH_SEL
value|0x00000001L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF2_TILE_ADRS
value|0x00000002L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF2_BASE_ADRS_MASK
value|0x03fffff0L
end_define

begin_define
define|#
directive|define
name|RADEON_VIF_BUF2_1ST_LINE_LSBS_MASK
value|0x48000000L
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF3_BASE_ADRS
value|0x044C
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF4_BASE_ADRS
value|0x0450
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VID_BUF5_BASE_ADRS
value|0x0454
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VIDEO_KEY_CLR_HIGH
value|0x04E8
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_VIDEO_KEY_CLR_LOW
value|0x04E4
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_Y_X_START
value|0x0400
end_define

begin_define
define|#
directive|define
name|RADEON_OV0_Y_X_END
value|0x0404
end_define

begin_define
define|#
directive|define
name|RADEON_OV1_Y_X_START
value|0x0600
end_define

begin_define
define|#
directive|define
name|RADEON_OV1_Y_X_END
value|0x0604
end_define

begin_define
define|#
directive|define
name|RADEON_OVR_CLR
value|0x0230
end_define

begin_define
define|#
directive|define
name|RADEON_OVR_WID_LEFT_RIGHT
value|0x0234
end_define

begin_define
define|#
directive|define
name|RADEON_OVR_WID_TOP_BOTTOM
value|0x0238
end_define

begin_define
define|#
directive|define
name|RADEON_OVR2_CLR
value|0x0330
end_define

begin_define
define|#
directive|define
name|RADEON_OVR2_WID_LEFT_RIGHT
value|0x0334
end_define

begin_define
define|#
directive|define
name|RADEON_OVR2_WID_TOP_BOTTOM
value|0x0338
end_define

begin_comment
comment|/* first capture unit */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF0_OFFSET
value|0x0920
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF1_OFFSET
value|0x0924
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF0_EVEN_OFFSET
value|0x0928
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF1_EVEN_OFFSET
value|0x092C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF_PITCH
value|0x0930
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_V_WINDOW
value|0x0934
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_H_WINDOW
value|0x0938
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI0_OFFSET
value|0x093C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI1_OFFSET
value|0x0940
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI_V_WINDOW
value|0x0944
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI_H_WINDOW
value|0x0948
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_PORT_MODE_CNTL
value|0x094C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_TRIG_CNTL
value|0x0950
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_DEBUG
value|0x0954
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG
value|0x0958
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_CONTINUOS
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_START_FIELD_EVEN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_START_BUF_GET
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_START_BUF_SET
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_BUF_TYPE_ALT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_BUF_TYPE_FRAME
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_ONESHOT_MODE_FRAME
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_BUF_MODE_DOUBLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_BUF_MODE_TRIPLE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_MIRROR_EN
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_ONESHOT_MIRROR_EN
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VIDEO_SIGNED_UV
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_ANC_DECODE_EN
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VBI_EN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_SOFT_PULL_DOWN_EN
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VIP_EXTEND_FLAG_EN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FAKE_FIELD_EN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_ODD_ONE_MORE_LINE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_EVEN_ONE_MORE_LINE
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_HORZ_DIVIDE_2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_HORZ_DIVIDE_4
value|0x00100000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VERT_DIVIDE_2
value|0x00200000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VERT_DIVIDE_4
value|0x00400000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FORMAT_BROOKTREE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FORMAT_CCIR656
value|0x00800000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FORMAT_ZV
value|0x01000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FORMAT_VIP
value|0x01800000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_FORMAT_TRANSPORT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_HORZ_DECIMATOR
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VIDEO_IN_YVYU422
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VIDEO_IN_VYUY422
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VBI_DIVIDE_2
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_CONFIG_VBI_DIVIDE_4
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ANC_ODD_OFFSET
value|0x095C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ANC_EVEN_OFFSET
value|0x0960
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ANC_H_WINDOW
value|0x0964
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VIDEO_SYNC_TEST
value|0x0968
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ONESHOT_BUF_OFFSET
value|0x096C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_BUF_STATUS
value|0x0970
end_define

begin_comment
comment|/* #define RADEON_CAP0_DWNSC_XRATIO       0x0978 */
end_comment

begin_comment
comment|/* #define RADEON_CAP0_XSHARPNESS                 0x097C */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI2_OFFSET
value|0x0980
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_VBI3_OFFSET
value|0x0984
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ANC2_OFFSET
value|0x0988
end_define

begin_define
define|#
directive|define
name|RADEON_CAP0_ANC3_OFFSET
value|0x098C
end_define

begin_define
define|#
directive|define
name|RADEON_VID_BUFFER_CONTROL
value|0x0900
end_define

begin_comment
comment|/* second capture unit */
end_comment

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF0_OFFSET
value|0x0990
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF1_OFFSET
value|0x0994
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF0_EVEN_OFFSET
value|0x0998
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF1_EVEN_OFFSET
value|0x099C
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF_PITCH
value|0x09A0
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_V_WINDOW
value|0x09A4
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_H_WINDOW
value|0x09A8
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_VBI_ODD_OFFSET
value|0x09AC
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_VBI_EVEN_OFFSET
value|0x09B0
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_VBI_V_WINDOW
value|0x09B4
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_VBI_H_WINDOW
value|0x09B8
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_PORT_MODE_CNTL
value|0x09BC
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_TRIG_CNTL
value|0x09C0
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_DEBUG
value|0x09C4
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_CONFIG
value|0x09C8
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_ANC_ODD_OFFSET
value|0x09CC
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_ANC_EVEN_OFFSET
value|0x09D0
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_ANC_H_WINDOW
value|0x09D4
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_VIDEO_SYNC_TEST
value|0x09D8
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_ONESHOT_BUF_OFFSET
value|0x09DC
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_BUF_STATUS
value|0x09E0
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_DWNSC_XRATIO
value|0x09E8
end_define

begin_define
define|#
directive|define
name|RADEON_CAP1_XSHARPNESS
value|0x09EC
end_define

begin_comment
comment|/* misc multimedia registers */
end_comment

begin_define
define|#
directive|define
name|RADEON_IDCT_RUNS
value|0x1F80
end_define

begin_define
define|#
directive|define
name|RADEON_IDCT_LEVELS
value|0x1F84
end_define

begin_define
define|#
directive|define
name|RADEON_IDCT_CONTROL
value|0x1FBC
end_define

begin_define
define|#
directive|define
name|RADEON_IDCT_AUTH_CONTROL
value|0x1F88
end_define

begin_define
define|#
directive|define
name|RADEON_IDCT_AUTH
value|0x1F8C
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_CNTL
value|0x002a
end_define

begin_comment
comment|/* P2PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_P2PLL_RESET
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_SLEEP
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_PVG_MASK
value|(7<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_PVG_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_ATOMIC_UPDATE_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_VGA_ATOMIC_UPDATE_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_ATOMIC_UPDATE_VSYNC
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_DIV_0
value|0x002c
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_FB0_DIV_MASK
value|0x07ff
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_POST0_DIV_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_REF_DIV
value|0x002B
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_P2PLL_REF_DIV_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|RADEON_P2PLL_ATOMIC_UPDATE_R
value|(1<< 15)
end_define

begin_comment
comment|/* same as _W */
end_comment

begin_define
define|#
directive|define
name|RADEON_P2PLL_ATOMIC_UPDATE_W
value|(1<< 15)
end_define

begin_comment
comment|/* same as _R */
end_comment

begin_define
define|#
directive|define
name|R300_PPLL_REF_DIV_ACC_MASK
value|(0x3ff<< 18)
end_define

begin_define
define|#
directive|define
name|R300_PPLL_REF_DIV_ACC_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|RADEON_PALETTE_DATA
value|0x00b4
end_define

begin_define
define|#
directive|define
name|RADEON_PALETTE_30_DATA
value|0x00b8
end_define

begin_define
define|#
directive|define
name|RADEON_PALETTE_INDEX
value|0x00b0
end_define

begin_define
define|#
directive|define
name|RADEON_PCI_GART_PAGE
value|0x017c
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLKS_CNTL
value|0x002d
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_SRC_SEL_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_SRC_SEL_CPUCLK
value|0x00
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_SRC_SEL_PSCANCLK
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_SRC_SEL_BYTECLK
value|0x02
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_SRC_SEL_P2PLLCLK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_ALWAYS_ONb
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|RADEON_PIX2CLK_DAC_ALWAYS_ONb
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_TV_SRC_SEL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DISP_TVOUT_PIXCLK_TV_ALWAYS_ONb
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|R300_DVOCLK_ALWAYS_ONb
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_BLEND_ALWAYS_ONb
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_GV_ALWAYS_ONb
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_DIG_TMDS_ALWAYS_ONb
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|R300_PIXCLK_DVO_ALWAYS_ONb
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_LVDS_ALWAYS_ONb
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_TMDS_ALWAYS_ONb
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|R300_PIXCLK_TRANS_ALWAYS_ONb
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_PIXCLK_TVO_ALWAYS_ONb
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R300_P2G2CLK_ALWAYS_ONb
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R300_P2G2CLK_DAC_ALWAYS_ONb
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|R300_DISP_DAC_PIXCLK_DAC2_BLANK_OFF
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_PLANE_3D_MASK_C
value|0x1d44
end_define

begin_define
define|#
directive|define
name|RADEON_PLL_TEST_CNTL
value|0x0013
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PLL_MASK_READ_B
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_PMI_CAP_ID
value|0x0f5c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PMI_DATA
value|0x0f63
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PMI_NXT_CAP_PTR
value|0x0f5d
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PMI_PMC_REG
value|0x0f5e
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PMI_PMCSR_REG
value|0x0f60
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PMI_REGISTER
value|0x0f5c
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_CNTL
value|0x0002
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_RESET
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_SLEEP
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_PVG_MASK
value|(7<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_PVG_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_ATOMIC_UPDATE_EN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_VGA_ATOMIC_UPDATE_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_ATOMIC_UPDATE_VSYNC
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_DIV_0
value|0x0004
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_DIV_1
value|0x0005
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_DIV_2
value|0x0006
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_DIV_3
value|0x0007
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_FB3_DIV_MASK
value|0x07ff
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_POST3_DIV_MASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_REF_DIV
value|0x0003
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_REF_DIV_MASK
value|0x03ff
end_define

begin_define
define|#
directive|define
name|RADEON_PPLL_ATOMIC_UPDATE_R
value|(1<< 15)
end_define

begin_comment
comment|/* same as _W */
end_comment

begin_define
define|#
directive|define
name|RADEON_PPLL_ATOMIC_UPDATE_W
value|(1<< 15)
end_define

begin_comment
comment|/* same as _R */
end_comment

begin_define
define|#
directive|define
name|RADEON_PWR_MNGMT_CNTL_STATUS
value|0x0f60
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_RBBM_GUICNTL
value|0x172c
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_NONE
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_16BIT
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_32BIT
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_DATA_SWAP_HDW
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_SOFT_RESET
value|0x00f0
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_CP
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_HI
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_SE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_RE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_PP
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_E2
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_RB
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_SOFT_RESET_HDP
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_STATUS
value|0x0e40
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_FIFOCNT_MASK
value|0x007f
end_define

begin_define
define|#
directive|define
name|RADEON_RBBM_ACTIVE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DSTCACHE_CTLSTAT
value|0x342c
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FLUSH
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FREE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_FLUSH_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_RB2D_DSTCACHE_MODE
value|0x3428
end_define

begin_define
define|#
directive|define
name|RADEON_DSTCACHE_CTLSTAT
value|0x1714
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZCACHE_MODE
value|0x3250
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZCACHE_CTLSTAT
value|0x3254
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZC_FLUSH_ALL
value|0x5
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DSTCACHE_MODE
value|0x3258
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_CACHE_ENABLE
value|(0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_2D_CACHE_DISABLE
value|(1)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_3D_CACHE_DISABLE
value|(2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_CACHE_DISABLE
value|(3)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_2D_CACHE_LINESIZE_128
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_3D_CACHE_LINESIZE_128
value|(2<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_2D_CACHE_AUTOFLUSH
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_3D_CACHE_AUTOFLUSH
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|R200_RB3D_DC_2D_CACHE_AUTOFREE
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|R200_RB3D_DC_3D_CACHE_AUTOFREE
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FORCE_RMW
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_DISABLE_RI_FILL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_DISABLE_RI_READ
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DSTCACHE_CTLSTAT
value|0x325C
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FLUSH
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FREE
value|(3<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_FLUSH_ALL
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DC_BUSY
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_REG_BASE
value|0x0f18
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_REGPROG_INF
value|0x0f09
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_REVISION_ID
value|0x0f08
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_SC_BOTTOM
value|0x164c
end_define

begin_define
define|#
directive|define
name|RADEON_SC_BOTTOM_RIGHT
value|0x16f0
end_define

begin_define
define|#
directive|define
name|RADEON_SC_BOTTOM_RIGHT_C
value|0x1c8c
end_define

begin_define
define|#
directive|define
name|RADEON_SC_LEFT
value|0x1640
end_define

begin_define
define|#
directive|define
name|RADEON_SC_RIGHT
value|0x1644
end_define

begin_define
define|#
directive|define
name|RADEON_SC_TOP
value|0x1648
end_define

begin_define
define|#
directive|define
name|RADEON_SC_TOP_LEFT
value|0x16ec
end_define

begin_define
define|#
directive|define
name|RADEON_SC_TOP_LEFT_C
value|0x1c88
end_define

begin_define
define|#
directive|define
name|RADEON_SC_SIGN_MASK_LO
value|0x8000
end_define

begin_define
define|#
directive|define
name|RADEON_SC_SIGN_MASK_HI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_M_SPLL_REF_FB_DIV
value|0x000a
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_M_SPLL_REF_DIV_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_M_SPLL_REF_DIV_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|RADEON_MPLL_FB_DIV_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_MPLL_FB_DIV_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_FB_DIV_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_FB_DIV_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_CNTL
value|0x000c
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_SPLL_SLEEP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_RESET
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PCP_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PCP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PVG_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PVG_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PDC_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|RADEON_SPLL_PDC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_CNTL
value|0x000d
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_SCLK_SRC_SEL_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|RADEON_DYN_STOP_LAT_MASK
value|0x00007ff8
end_define

begin_define
define|#
directive|define
name|RADEON_CP_MAX_DYN_STOP_LAT
value|0x0008
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCEON_MASK
value|0xffff8000
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_DISP2
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_CP
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_HDP
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_DISP1
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_TOP
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_E2
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_SE
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_IDCT
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_VIP
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_RE
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_PB
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_TAM
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_TDM
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_RB
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_TV_SCLK
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_SUBPIC
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_FORCE_OV0
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_VAP
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_SR
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_PX
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_TX
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_US
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_SU
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_CNTL2
value|0x1e
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|R300_SCLK_TCL_MAX_DYN_STOP_LAT
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_GA_MAX_DYN_STOP_LAT
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_CBA_MAX_DYN_STOP_LAT
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_TCL
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_CBA
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|R300_SCLK_FORCE_GA
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_MORE_CNTL
value|0x0035
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_SCLK_MORE_MAX_DYN_STOP_LAT
value|0x0007
end_define

begin_define
define|#
directive|define
name|RADEON_SCLK_MORE_FORCEON
value|0x0700
end_define

begin_define
define|#
directive|define
name|RADEON_SDRAM_MODE_REG
value|0x0158
end_define

begin_define
define|#
directive|define
name|RADEON_SEQ8_DATA
value|0x03c5
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_SEQ8_IDX
value|0x03c4
end_define

begin_comment
comment|/* VGA */
end_comment

begin_define
define|#
directive|define
name|RADEON_SNAPSHOT_F_COUNT
value|0x0244
end_define

begin_define
define|#
directive|define
name|RADEON_SNAPSHOT_VH_COUNTS
value|0x0240
end_define

begin_define
define|#
directive|define
name|RADEON_SNAPSHOT_VIF_COUNT
value|0x024c
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_OFFSET
value|0x15ac
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_PITCH
value|0x15b0
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_PITCH_OFFSET
value|0x1428
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_SC_BOTTOM
value|0x165c
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_SC_BOTTOM_RIGHT
value|0x16f4
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_SC_RIGHT
value|0x1654
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_X
value|0x1414
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_X_Y
value|0x1590
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_Y
value|0x1418
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_Y_X
value|0x1434
end_define

begin_define
define|#
directive|define
name|RADEON_STATUS
value|0x0f06
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_SUBPIC_CNTL
value|0x0540
end_define

begin_comment
comment|/* ? */
end_comment

begin_define
define|#
directive|define
name|RADEON_SUB_CLASS
value|0x0f0a
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_SURFACE_CNTL
value|0x0b00
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TRANSLATION_DIS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_16BPP
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP0_SWP_32BPP
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_16BPP
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_NONSURF_AP1_SWP_32BPP
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_INFO
value|0x0b0c
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_COLOR_MACRO
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_COLOR_BOTH
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_DEPTH_32BPP
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_TILE_DEPTH_16BPP
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_NONE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_COLOR_MACRO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_COLOR_MICRO
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_COLOR_BOTH
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_DEPTH_32BPP
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|R200_SURF_TILE_DEPTH_16BPP
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|R300_SURF_TILE_NONE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R300_SURF_TILE_COLOR_MACRO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R300_SURF_TILE_DEPTH_32BPP
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_AP0_SWP_16BPP
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_AP0_SWP_32BPP
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_AP1_SWP_16BPP
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_SURF_AP1_SWP_32BPP
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_LOWER_BOUND
value|0x0b04
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE0_UPPER_BOUND
value|0x0b08
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_INFO
value|0x0b1c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_LOWER_BOUND
value|0x0b14
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE1_UPPER_BOUND
value|0x0b18
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_INFO
value|0x0b2c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_LOWER_BOUND
value|0x0b24
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE2_UPPER_BOUND
value|0x0b28
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_INFO
value|0x0b3c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_LOWER_BOUND
value|0x0b34
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE3_UPPER_BOUND
value|0x0b38
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_INFO
value|0x0b4c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_LOWER_BOUND
value|0x0b44
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE4_UPPER_BOUND
value|0x0b48
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_INFO
value|0x0b5c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_LOWER_BOUND
value|0x0b54
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE5_UPPER_BOUND
value|0x0b58
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_INFO
value|0x0b6c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_LOWER_BOUND
value|0x0b64
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE6_UPPER_BOUND
value|0x0b68
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_INFO
value|0x0b7c
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_LOWER_BOUND
value|0x0b74
end_define

begin_define
define|#
directive|define
name|RADEON_SURFACE7_UPPER_BOUND
value|0x0b78
end_define

begin_define
define|#
directive|define
name|RADEON_SW_SEMAPHORE
value|0x013c
end_define

begin_define
define|#
directive|define
name|RADEON_TEST_DEBUG_CNTL
value|0x0120
end_define

begin_define
define|#
directive|define
name|RADEON_TEST_DEBUG_CNTL__TEST_DEBUG_OUT_EN
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_TEST_DEBUG_MUX
value|0x0124
end_define

begin_define
define|#
directive|define
name|RADEON_TEST_DEBUG_OUT
value|0x012c
end_define

begin_define
define|#
directive|define
name|RADEON_TMDS_PLL_CNTL
value|0x02a8
end_define

begin_define
define|#
directive|define
name|RADEON_TMDS_TRANSMITTER_CNTL
value|0x02a4
end_define

begin_define
define|#
directive|define
name|RADEON_TMDS_TRANSMITTER_PLLEN
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_TMDS_TRANSMITTER_PLLRST
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_TRAIL_BRES_DEC
value|0x1614
end_define

begin_define
define|#
directive|define
name|RADEON_TRAIL_BRES_ERR
value|0x160c
end_define

begin_define
define|#
directive|define
name|RADEON_TRAIL_BRES_INC
value|0x1610
end_define

begin_define
define|#
directive|define
name|RADEON_TRAIL_X
value|0x1618
end_define

begin_define
define|#
directive|define
name|RADEON_TRAIL_X_SUB
value|0x1620
end_define

begin_define
define|#
directive|define
name|RADEON_VCLK_ECP_CNTL
value|0x0008
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_VCLK_SRC_SEL_MASK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_VCLK_SRC_SEL_CPUCLK
value|0x00
end_define

begin_define
define|#
directive|define
name|RADEON_VCLK_SRC_SEL_PSCANCLK
value|0x01
end_define

begin_define
define|#
directive|define
name|RADEON_VCLK_SRC_SEL_BYTECLK
value|0x02
end_define

begin_define
define|#
directive|define
name|RADEON_VCLK_SRC_SEL_PPLLCLK
value|0x03
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_ALWAYS_ONb
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|RADEON_PIXCLK_DAC_ALWAYS_ONb
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|R300_DISP_DAC_PIXCLK_DAC_BLANK_OFF
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|RADEON_VENDOR_ID
value|0x0f00
end_define

begin_comment
comment|/* PCI */
end_comment

begin_define
define|#
directive|define
name|RADEON_VGA_DDA_CONFIG
value|0x02e8
end_define

begin_define
define|#
directive|define
name|RADEON_VGA_DDA_ON_OFF
value|0x02ec
end_define

begin_define
define|#
directive|define
name|RADEON_VID_BUFFER_CONTROL
value|0x0900
end_define

begin_define
define|#
directive|define
name|RADEON_VIDEOMUX_CNTL
value|0x0190
end_define

begin_comment
comment|/* VIP bus */
end_comment

begin_define
define|#
directive|define
name|RADEON_VIPH_CH0_DATA
value|0x0c00
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH1_DATA
value|0x0c04
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH2_DATA
value|0x0c08
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH3_DATA
value|0x0c0c
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH0_ADDR
value|0x0c10
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH1_ADDR
value|0x0c14
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH2_ADDR
value|0x0c18
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH3_ADDR
value|0x0c1c
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH0_SBCNT
value|0x0c20
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH1_SBCNT
value|0x0c24
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH2_SBCNT
value|0x0c28
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH3_SBCNT
value|0x0c2c
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH0_ABCNT
value|0x0c30
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH1_ABCNT
value|0x0c34
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH2_ABCNT
value|0x0c38
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CH3_ABCNT
value|0x0c3c
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_CONTROL
value|0x0c40
end_define

begin_define
define|#
directive|define
name|RADEON_VIP_BUSY
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_VIP_IDLE
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_VIP_RESET
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_EN
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_DV_LAT
value|0x0c44
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_BM_CHUNK
value|0x0c48
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_DV_INT
value|0x0c4c
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_TIMEOUT_STAT
value|0x0c50
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_TIMEOUT_STAT__VIPH_REG_STAT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_TIMEOUT_STAT__VIPH_REG_AK
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_TIMEOUT_STAT__VIPH_REGR_DIS
value|0x01000000
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_REG_DATA
value|0x0084
end_define

begin_define
define|#
directive|define
name|RADEON_VIPH_REG_ADDR
value|0x0080
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_UNTIL
value|0x1720
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_CRTC_PFLIP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_RE_CRTC_VLINE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_FE_CRTC_VLINE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_CRTC_VLINE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_DMA_VID_IDLE
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_DMA_GUI_IDLE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_CMDFIFO
value|(1<< 10)
end_define

begin_comment
comment|/* wait for CMDFIFO_ENTRIES */
end_comment

begin_define
define|#
directive|define
name|RADEON_WAIT_OV0_FLIP
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_AGP_FLUSH
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_2D_IDLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_3D_IDLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_2D_IDLECLEAN
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_3D_IDLECLEAN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_HOST_IDLECLEAN
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_CMDFIFO_ENTRIES_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_CMDFIFO_ENTRIES_MASK
value|0x7f
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_VAP_IDLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_WAIT_BOTH_CRTC_PFLIP
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_ENG_DISPLAY_SELECT_CRTC0
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_ENG_DISPLAY_SELECT_CRTC1
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_X_MPLL_REF_FB_DIV
value|0x000a
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_XCLK_CNTL
value|0x000d
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_XDLL_CNTL
value|0x000c
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_XPLL_CNTL
value|0x000b
end_define

begin_comment
comment|/* PLL */
end_comment

begin_comment
comment|/* Registers for 3D/TCL */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_0
value|0x1d40
end_define

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_1
value|0x1d44
end_define

begin_define
define|#
directive|define
name|RADEON_PP_BORDER_COLOR_2
value|0x1d48
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CNTL
value|0x1c38
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_SCISSOR_ENABLE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_PATTERN_ENABLE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_ENABLE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_ENABLE_MASK
value|(0xf<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_0_ENABLE
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_1_ENABLE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_2_ENABLE
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_3_ENABLE
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_BLEND_ENABLE_MASK
value|(0xf<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_BLEND_0_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_BLEND_1_ENABLE
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_BLEND_2_ENABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_BLEND_3_ENABLE
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_PLANAR_YUV_ENABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_ENABLE
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_ENABLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_ENABLE
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_ANTI_ALIAS_NONE
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_ANTI_ALIAS_LINE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_ANTI_ALIAS_POLY
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_ANTI_ALIAS_LINE_POLY
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_BUMP_MAP_ENABLE
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_BUMPED_MAP_T0
value|(0<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_BUMPED_MAP_T1
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_BUMPED_MAP_T2
value|(2<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_3D_ENABLE_0
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_3D_ENABLE_1
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_MC_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_FOG_COLOR
value|0x1c18
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_COLOR_MASK
value|0x00ffffff
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_VERTEX
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_TABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_USE_DEPTH
value|(0<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_USE_DIFFUSE_ALPHA
value|(2<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_USE_SPEC_ALPHA
value|(3<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_LUM_MATRIX
value|0x1d00
end_define

begin_define
define|#
directive|define
name|RADEON_PP_MISC
value|0x1c14
end_define

begin_define
define|#
directive|define
name|RADEON_REF_ALPHA_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_FAIL
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_LESS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_LEQUAL
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_EQUAL
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_GEQUAL
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_GREATER
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_NEQUAL
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_PASS
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_TEST_OP_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_FUNC_FAIL
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_FUNC_PASS
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_FUNC_NEQUAL
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_FUNC_EQUAL
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_KEY_NEAREST
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_CHROMA_KEY_ZERO
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_ID_AUTO_INC
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_FUNC_EQUAL
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_FUNC_NEQUAL
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_PASS_1
value|(0<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_SHADOW_PASS_2
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_RIGHT_HAND_CUBE_D3D
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_RIGHT_HAND_CUBE_OGL
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_ROT_MATRIX_0
value|0x1d58
end_define

begin_define
define|#
directive|define
name|RADEON_PP_ROT_MATRIX_1
value|0x1d5c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_0
value|0x1c54
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_1
value|0x1c6c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFILTER_2
value|0x1c84
end_define

begin_define
define|#
directive|define
name|RADEON_MAG_FILTER_NEAREST
value|(0<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_MAG_FILTER_LINEAR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_MAG_FILTER_MASK
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_NEAREST
value|(0<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_LINEAR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_NEAREST_MIP_NEAREST
value|(2<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_NEAREST_MIP_LINEAR
value|(3<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_LINEAR_MIP_NEAREST
value|(6<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_LINEAR_MIP_LINEAR
value|(7<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_ANISO_NEAREST
value|(8<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_ANISO_LINEAR
value|(9<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_ANISO_NEAREST_MIP_NEAREST
value|(10<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_ANISO_NEAREST_MIP_LINEAR
value|(11<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MIN_FILTER_MASK
value|(15<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_1_TO_1
value|(0<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_2_TO_1
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_4_TO_1
value|(2<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_8_TO_1
value|(3<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_16_TO_1
value|(4<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_ANISO_MASK
value|(7<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_LOD_BIAS_MASK
value|(0xff<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_LOD_BIAS_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_MIP_LEVEL_MASK
value|(0x0f<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_MIP_LEVEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_YUV_TO_RGB
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_YUV_TEMPERATURE_COOL
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_YUV_TEMPERATURE_HOT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_YUV_TEMPERATURE_MASK
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_WRAPEN_S
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_WRAP
value|(0<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_MIRROR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_CLAMP_LAST
value|(2<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_MIRROR_CLAMP_LAST
value|(3<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_CLAMP_BORDER
value|(4<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_MIRROR_CLAMP_BORDER
value|(5<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_CLAMP_GL
value|(6<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_MIRROR_CLAMP_GL
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_S_MASK
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_WRAPEN_T
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_WRAP
value|(0<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_MIRROR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_CLAMP_LAST
value|(2<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_MIRROR_CLAMP_LAST
value|(3<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_CLAMP_BORDER
value|(4<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_MIRROR_CLAMP_BORDER
value|(5<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_CLAMP_GL
value|(6<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_MIRROR_CLAMP_GL
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_T_MASK
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_BORDER_MODE_OGL
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_BORDER_MODE_D3D
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFORMAT_0
value|0x1c58
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFORMAT_1
value|0x1c70
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXFORMAT_2
value|0x1c88
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_I8
value|(0<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_AI88
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGB332
value|(2<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB1555
value|(3<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGB565
value|(4<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB4444
value|(5<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ARGB8888
value|(6<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_RGBA8888
value|(7<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_Y8
value|(8<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_VYUY422
value|(10<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_YVYU422
value|(11<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT1
value|(12<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT23
value|(14<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DXT45
value|(15<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_SHADOW16
value|(16<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_SHADOW32
value|(17<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_DUDV88
value|(18<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_LDUDV655
value|(19<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_LDUDUV8888
value|(20<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_FORMAT_MASK
value|(31<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_FORMAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_APPLE_YUV_MODE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ALPHA_IN_MAP
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_NON_POWER2
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_WIDTH_MASK
value|(15<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_WIDTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_HEIGHT_MASK
value|(15<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_HEIGHT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_F5_WIDTH_MASK
value|(15<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_F5_WIDTH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_F5_HEIGHT_MASK
value|(15<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_F5_HEIGHT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ST_ROUTE_STQ0
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ST_ROUTE_MASK
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ST_ROUTE_STQ1
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ST_ROUTE_STQ2
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ENDIAN_NO_SWAP
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ENDIAN_16BPP_SWAP
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ENDIAN_32BPP_SWAP
value|(2<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ENDIAN_HALFDW_SWAP
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_ALPHA_MASK_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_CHROMA_KEY_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_CUBIC_MAP_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_TXFORMAT_PERSPECTIVE_ENABLE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_0
value|0x1d24
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_1
value|0x1d28
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_FACES_2
value|0x1d2c
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_1_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_1_MASK
value|(0xf<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_2_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_2_MASK
value|(0xf<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_2_MASK
value|(0xf<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_3_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_3_MASK
value|(0xf<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_3_MASK
value|(0xf<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_4_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_4_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_WIDTH_4_MASK
value|(0xf<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_FACE_HEIGHT_4_MASK
value|(0xf<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXOFFSET_0
value|0x1c5c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXOFFSET_1
value|0x1c74
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXOFFSET_2
value|0x1c8c
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_ENDIAN_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_ENDIAN_BYTE_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_ENDIAN_WORD_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_ENDIAN_HALFDW_SWAP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_MACRO_LINEAR
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_MACRO_TILE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_MICRO_LINEAR
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_MICRO_TILE_X2
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_MICRO_TILE_OPT
value|(2<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_OFFSET_MASK
value|0xffffffe0
end_define

begin_define
define|#
directive|define
name|RADEON_TXO_OFFSET_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_0
value|0x1dd0
end_define

begin_comment
comment|/* bits [31:5] */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_1
value|0x1dd4
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_2
value|0x1dd8
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_3
value|0x1ddc
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T0_4
value|0x1de0
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_0
value|0x1e00
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_1
value|0x1e04
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_2
value|0x1e08
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_3
value|0x1e0c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T1_4
value|0x1e10
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_0
value|0x1e14
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_1
value|0x1e18
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_2
value|0x1e1c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_3
value|0x1e20
end_define

begin_define
define|#
directive|define
name|RADEON_PP_CUBIC_OFFSET_T2_4
value|0x1e24
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_0
value|0x1d04
end_define

begin_comment
comment|/* NPOT */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_1
value|0x1d0c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TEX_SIZE_2
value|0x1d14
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_USIZE_MASK
value|(0x7ff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_USIZE_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_VSIZE_MASK
value|(0x7ff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX_VSIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SIGNED_RGB_MASK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_SIGNED_RGB_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|RADEON_SIGNED_ALPHA_MASK
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_SIGNED_ALPHA_SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TEX_PITCH_0
value|0x1d08
end_define

begin_comment
comment|/* NPOT */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_TEX_PITCH_1
value|0x1d10
end_define

begin_comment
comment|/* NPOT */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_TEX_PITCH_2
value|0x1d18
end_define

begin_comment
comment|/* NPOT */
end_comment

begin_comment
comment|/* note: bits 13-5: 32 byte aligned stride of texture map */
end_comment

begin_define
define|#
directive|define
name|RADEON_PP_TXCBLEND_0
value|0x1c60
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXCBLEND_1
value|0x1c78
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXCBLEND_2
value|0x1c90
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_ZERO
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_CURRENT_COLOR
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_CURRENT_ALPHA
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_DIFFUSE_COLOR
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_DIFFUSE_ALPHA
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_SPECULAR_COLOR
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_SPECULAR_ALPHA
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_TFACTOR_COLOR
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_TFACTOR_ALPHA
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T0_COLOR
value|(10<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T0_ALPHA
value|(11<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T1_COLOR
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T1_ALPHA
value|(13<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T2_COLOR
value|(14<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T2_ALPHA
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T3_COLOR
value|(16<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_A_T3_ALPHA
value|(17<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_MASK
value|(0x1f<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_ZERO
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_CURRENT_COLOR
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_CURRENT_ALPHA
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_DIFFUSE_COLOR
value|(4<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_DIFFUSE_ALPHA
value|(5<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_SPECULAR_COLOR
value|(6<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_SPECULAR_ALPHA
value|(7<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_TFACTOR_COLOR
value|(8<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_TFACTOR_ALPHA
value|(9<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T0_COLOR
value|(10<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T0_ALPHA
value|(11<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T1_COLOR
value|(12<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T1_ALPHA
value|(13<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T2_COLOR
value|(14<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T2_ALPHA
value|(15<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T3_COLOR
value|(16<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_B_T3_ALPHA
value|(17<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_MASK
value|(0x1f<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_ZERO
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_CURRENT_COLOR
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_CURRENT_ALPHA
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_DIFFUSE_COLOR
value|(4<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_DIFFUSE_ALPHA
value|(5<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_SPECULAR_COLOR
value|(6<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_SPECULAR_ALPHA
value|(7<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_TFACTOR_COLOR
value|(8<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_TFACTOR_ALPHA
value|(9<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T0_COLOR
value|(10<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T0_ALPHA
value|(11<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T1_COLOR
value|(12<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T1_ALPHA
value|(13<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T2_COLOR
value|(14<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T2_ALPHA
value|(15<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T3_COLOR
value|(16<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_C_T3_ALPHA
value|(17<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_A
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_A_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_B
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_B_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_C
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_C_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_MASK
value|(7<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_ADD
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_SUBTRACT
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_ADDSIGNED
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_BLEND
value|(3<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_CTL_DOT3
value|(4<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_MASK
value|(3<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_1X
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_2X
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_4X
value|(2<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_CLAMP_TX
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_T0_EQ_TCUR
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_T1_EQ_TCUR
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_T2_EQ_TCUR
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_T3_EQ_TCUR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ARG_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|RADEON_COMP_ARG_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXABLEND_0
value|0x1c64
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXABLEND_1
value|0x1c7c
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TXABLEND_2
value|0x1c94
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_ZERO
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_CURRENT_ALPHA
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_DIFFUSE_ALPHA
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_SPECULAR_ALPHA
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_TFACTOR_ALPHA
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_T0_ALPHA
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_T1_ALPHA
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_T2_ALPHA
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_A_T3_ALPHA
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_MASK
value|(0xf<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_ZERO
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_CURRENT_ALPHA
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_DIFFUSE_ALPHA
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_SPECULAR_ALPHA
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_TFACTOR_ALPHA
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_T0_ALPHA
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_T1_ALPHA
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_T2_ALPHA
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_B_T3_ALPHA
value|(8<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_MASK
value|(0xf<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_ZERO
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_CURRENT_ALPHA
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_DIFFUSE_ALPHA
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_SPECULAR_ALPHA
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_TFACTOR_ALPHA
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_T0_ALPHA
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_T1_ALPHA
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_T2_ALPHA
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_C_T3_ALPHA
value|(8<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_DOT_ALPHA_DONT_REPLICATE
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_ARG_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TFACTOR_0
value|0x1c68
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TFACTOR_1
value|0x1c80
end_define

begin_define
define|#
directive|define
name|RADEON_PP_TFACTOR_2
value|0x1c98
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_BLENDCNTL
value|0x1c20
end_define

begin_define
define|#
directive|define
name|RADEON_COMB_FCN_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_COMB_FCN_ADD_CLAMP
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_COMB_FCN_ADD_NOCLAMP
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_COMB_FCN_SUB_CLAMP
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_COMB_FCN_SUB_NOCLAMP
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ZERO
value|(32<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ONE
value|(33<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_SRC_COLOR
value|(34<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ONE_MINUS_SRC_COLOR
value|(35<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_DST_COLOR
value|(36<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ONE_MINUS_DST_COLOR
value|(37<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_SRC_ALPHA
value|(38<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ONE_MINUS_SRC_ALPHA
value|(39<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_DST_ALPHA
value|(40<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_ONE_MINUS_DST_ALPHA
value|(41<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_GL_SRC_ALPHA_SATURATE
value|(42<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_SRC_BLEND_MASK
value|(63<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ZERO
value|(32<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ONE
value|(33<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_SRC_COLOR
value|(34<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ONE_MINUS_SRC_COLOR
value|(35<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_DST_COLOR
value|(36<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ONE_MINUS_DST_COLOR
value|(37<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_SRC_ALPHA
value|(38<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ONE_MINUS_SRC_ALPHA
value|(39<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_DST_ALPHA
value|(40<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_GL_ONE_MINUS_DST_ALPHA
value|(41<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_DST_BLEND_MASK
value|(63<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_CNTL
value|0x1c3c
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_BLEND_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_PLANE_MASK_ENABLE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_DITHER_ENABLE
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_ENABLE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_SCALE_DITHER_ENABLE
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_DITHER_INIT
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_ENABLE
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ENABLE
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_ENABLE
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTHXY_OFFSET_ENABLE
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_COLOR_FORMAT_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB1555
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB565
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB8888
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB332
value|7
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_Y8
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_RGB8
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_YUV422_VYUY
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_YUV422_YVYU
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_aYUV444
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_FORMAT_ARGB4444
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_CLRCMP_FLIP_ENABLE
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_COLOROFFSET
value|0x1c40
end_define

begin_define
define|#
directive|define
name|RADEON_COLOROFFSET_MASK
value|0xfffffff0
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_COLORPITCH
value|0x1c48
end_define

begin_define
define|#
directive|define
name|RADEON_COLORPITCH_MASK
value|0x000001ff8
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_TILE_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_MICROTILE_ENABLE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ENDIAN_NO_SWAP
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ENDIAN_WORD_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_COLOR_ENDIAN_DWORD_SWAP
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DEPTHOFFSET
value|0x1c24
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_DEPTHPITCH
value|0x1c28
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTHPITCH_MASK
value|0x00001ff8
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_ENDIAN_NO_SWAP
value|(0<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_ENDIAN_WORD_SWAP
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_ENDIAN_DWORD_SWAP
value|(2<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_PLANEMASK
value|0x1d84
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ROPCNTL
value|0x1d80
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_MASK
value|(15<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_CLEAR
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_NOR
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_AND_INVERTED
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_COPY_INVERTED
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_AND_REVERSE
value|(4<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_INVERT
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_XOR
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_NAND
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_AND
value|(8<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_EQUIV
value|(9<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_NOOP
value|(10<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_OR_INVERTED
value|(11<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_COPY
value|(12<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_OR_REVERSE
value|(13<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_OR
value|(14<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_ROP_SET
value|(15<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_STENCILREFMASK
value|0x1d7c
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_REF_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_REF_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_VALUE_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_WRITEMASK_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_WRITE_MASK
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZSTENCILCNTL
value|0x1c2c
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_MASK
value|(0xf<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_16BIT_INT_Z
value|(0<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_24BIT_INT_Z
value|(2<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_24BIT_FLOAT_Z
value|(3<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_32BIT_INT_Z
value|(4<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_32BIT_FLOAT_Z
value|(5<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_16BIT_FLOAT_W
value|(7<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_24BIT_FLOAT_W
value|(9<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_DEPTH_FORMAT_32BIT_FLOAT_W
value|(11<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_NEVER
value|(0<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_LESS
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_LEQUAL
value|(2<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_EQUAL
value|(3<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_GEQUAL
value|(4<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_GREATER
value|(5<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_NEQUAL
value|(6<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_ALWAYS
value|(7<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_TEST_MASK
value|(7<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_NEVER
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_LESS
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_LEQUAL
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_EQUAL
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_GEQUAL
value|(4<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_GREATER
value|(5<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_NEQUAL
value|(6<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_ALWAYS
value|(7<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_TEST_MASK
value|(0x7<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_KEEP
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_ZERO
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_REPLACE
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_INC
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_DEC
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_INVERT
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_FAIL_MASK
value|(0x7<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_KEEP
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_ZERO
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_REPLACE
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_INC
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_DEC
value|(4<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_INVERT
value|(5<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZPASS_MASK
value|(0x7<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_KEEP
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_ZERO
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_REPLACE
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_INC
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_DEC
value|(4<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_INVERT
value|(5<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_STENCIL_ZFAIL_MASK
value|(0x7<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_COMPRESSION_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCE_Z_DIRTY
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_Z_WRITE_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_LINE_PATTERN
value|0x1cd0
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_PATTERN_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_REPEAT_COUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_PATTERN_START_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_PATTERN_LITTLE_BIT_ORDER
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_PATTERN_BIG_BIT_ORDER
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_PATTERN_AUTO_RESET
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_LINE_STATE
value|0x1cd4
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_CURRENT_PTR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LINE_CURRENT_COUNT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_RE_MISC
value|0x26c4
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_COORD_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_X_OFFSET_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_X_OFFSET_MASK
value|(0x1f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_Y_OFFSET_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_Y_OFFSET_MASK
value|(0x1f<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_LITTLE_BIT_ORDER
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_STIPPLE_BIG_BIT_ORDER
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_SOLID_COLOR
value|0x1c1c
end_define

begin_define
define|#
directive|define
name|RADEON_RE_TOP_LEFT
value|0x26c0
end_define

begin_define
define|#
directive|define
name|RADEON_RE_LEFT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_RE_TOP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_RE_WIDTH_HEIGHT
value|0x1c44
end_define

begin_define
define|#
directive|define
name|RADEON_RE_WIDTH_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_RE_HEIGHT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZPASS_DATA
value|0x3290
end_define

begin_define
define|#
directive|define
name|RADEON_RB3D_ZPASS_ADDR
value|0x3294
end_define

begin_define
define|#
directive|define
name|RADEON_SE_CNTL
value|0x1c4c
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL_CW
value|(0<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL_CCW
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL_DIR_MASK
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_BFACE_CULL
value|(0<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_BFACE_SOLID
value|(3<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL
value|(0<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_SOLID
value|(3<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_FFACE_CULL_MASK
value|(3<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_BADVTX_CULL_DISABLE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_FLAT_SHADE_VTX_0
value|(0<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_FLAT_SHADE_VTX_1
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_FLAT_SHADE_VTX_2
value|(2<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_FLAT_SHADE_VTX_LAST
value|(3<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_SOLID
value|(0<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_FLAT
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_GOURAUD
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SHADE_MASK
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_SOLID
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_FLAT
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_GOURAUD
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_ALPHA_SHADE_MASK
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_SOLID
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_FLAT
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_GOURAUD
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SHADE_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_SOLID
value|(0<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_FLAT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_GOURAUD
value|(2<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_FOG_SHADE_MASK
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_ZBIAS_ENABLE_POINT
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_ZBIAS_ENABLE_LINE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_ZBIAS_ENABLE_TRI
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_WIDELINE_ENABLE
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_VPORT_XY_XFORM_ENABLE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_VPORT_Z_XFORM_ENABLE
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_PIX_CENTER_D3D
value|(0<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_PIX_CENTER_OGL
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_MODE_TRUNC
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_MODE_ROUND
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_MODE_ROUND_EVEN
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_MODE_ROUND_ODD
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_PREC_16TH_PIX
value|(0<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_PREC_8TH_PIX
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_PREC_4TH_PIX
value|(2<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_ROUND_PREC_HALF_PIX
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|R200_RE_CNTL
value|0x1c50
end_define

begin_define
define|#
directive|define
name|R200_STIPPLE_ENABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|R200_SCISSOR_ENABLE
value|0x2
end_define

begin_define
define|#
directive|define
name|R200_PATTERN_ENABLE
value|0x4
end_define

begin_define
define|#
directive|define
name|R200_PERSPECTIVE_ENABLE
value|0x8
end_define

begin_define
define|#
directive|define
name|R200_POINT_SMOOTH
value|0x20
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ0_D3D
value|0x00010000
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ1_D3D
value|0x00040000
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ2_D3D
value|0x00100000
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ3_D3D
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ4_D3D
value|0x01000000
end_define

begin_define
define|#
directive|define
name|R200_VTX_STQ5_D3D
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_CNTL_STATUS
value|0x2140
end_define

begin_define
define|#
directive|define
name|RADEON_VC_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_VC_16BIT_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_VC_32BIT_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_VC_HALF_DWORD_SWAP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_BYPASS
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_SE_COORD_FMT
value|0x1c50
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_XY_PRE_MULT_1_OVER_W0
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_Z_PRE_MULT_1_OVER_W0
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST0_NONPARAMETRIC
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST1_NONPARAMETRIC
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST2_NONPARAMETRIC
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST3_NONPARAMETRIC
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_W0_NORMALIZE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_W0_IS_NOT_1_OVER_W0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST0_PRE_MULT_1_OVER_W0
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST1_PRE_MULT_1_OVER_W0
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST2_PRE_MULT_1_OVER_W0
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_VTX_ST3_PRE_MULT_1_OVER_W0
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX1_W_ROUTING_USE_W0
value|(0<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_TEX1_W_ROUTING_USE_Q1
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_SE_LINE_WIDTH
value|0x1db8
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_LIGHT_MODEL_CTL
value|0x226c
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHTING_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_IN_MODELSPACE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_LOCAL_VIEWER
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_NORMALIZE_NORMALS
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_RESCALE_NORMALS
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_LIGHTS
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SPECULAR_COMBINE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_ALPHA
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_LOCAL_LIGHT_VEC_GL
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_NO_NORMAL_AMBIENT_ONLY
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|RADEON_LM_SOURCE_STATE_PREMULT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LM_SOURCE_STATE_MULT
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_LM_SOURCE_VERTEX_DIFFUSE
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_LM_SOURCE_VERTEX_SPECULAR
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_EMISSIVE_SOURCE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_AMBIENT_SOURCE_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|RADEON_DIFFUSE_SOURCE_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_SPECULAR_SOURCE_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_AMBIENT_RED
value|0x2220
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_AMBIENT_GREEN
value|0x2224
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_AMBIENT_BLUE
value|0x2228
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_AMBIENT_ALPHA
value|0x222c
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_DIFFUSE_RED
value|0x2230
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_DIFFUSE_GREEN
value|0x2234
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_DIFFUSE_BLUE
value|0x2238
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_DIFFUSE_ALPHA
value|0x223c
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_EMMISSIVE_RED
value|0x2210
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_EMMISSIVE_GREEN
value|0x2214
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_EMMISSIVE_BLUE
value|0x2218
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_EMMISSIVE_ALPHA
value|0x221c
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_SPECULAR_RED
value|0x2240
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_SPECULAR_GREEN
value|0x2244
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_SPECULAR_BLUE
value|0x2248
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATERIAL_SPECULAR_ALPHA
value|0x224c
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATRIX_SELECT_0
value|0x225c
end_define

begin_define
define|#
directive|define
name|RADEON_MODELVIEW_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_MODELVIEW_1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_MODELVIEW_2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_MODELVIEW_3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_IT_MODELVIEW_0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_IT_MODELVIEW_1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_IT_MODELVIEW_2_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_IT_MODELVIEW_3_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_MATRIX_SELECT_1
value|0x2260
end_define

begin_define
define|#
directive|define
name|RADEON_MODELPROJECT_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_MODELPROJECT_1_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_MODELPROJECT_2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_MODELPROJECT_3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_1_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_2_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_3_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_OUTPUT_VTX_FMT
value|0x2254
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_W0
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_FP_DIFFUSE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_FP_ALPHA
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_PK_DIFFUSE
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_FP_SPEC
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_FP_FOG
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_PK_SPEC
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_ST0
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_ST1
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Q1
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_ST2
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Q2
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_ST3
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Q3
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Q0
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_WEIGHT_COUNT_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_NORM0
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_XY1
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Z1
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_W1
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_NORM1
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_VTX_Z0
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_OUTPUT_VTX_SEL
value|0x2258
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_COMPUTE_XYZW
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_COMPUTE_DIFFUSE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_COMPUTE_SPECULAR
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FORCE_NAN_IF_COLOR_NAN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FORCE_INORDER_PROC
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_INPUT_TEX_0
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_INPUT_TEX_1
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_INPUT_TEX_2
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_INPUT_TEX_3
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_COMPUTED_TEX_0
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_COMPUTED_TEX_1
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_COMPUTED_TEX_2
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_COMPUTED_TEX_3
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_0_OUTPUT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_1_OUTPUT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_2_OUTPUT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_TEX_3_OUTPUT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_PER_LIGHT_CTL_0
value|0x2270
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_ENABLE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_ENABLE_AMBIENT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_ENABLE_SPECULAR
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_IS_LOCAL
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_IS_SPOT
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_DUAL_CONE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_ENABLE_RANGE_ATTEN
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_CONSTANT_RANGE_ATTEN
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_ENABLE_AMBIENT
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_ENABLE_SPECULAR
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_IS_LOCAL
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_IS_SPOT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_DUAL_CONE
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_ENABLE_RANGE_ATTEN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_CONSTANT_RANGE_ATTEN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_1_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_PER_LIGHT_CTL_1
value|0x2274
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_2_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_PER_LIGHT_CTL_2
value|0x2278
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_4_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_5_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_PER_LIGHT_CTL_3
value|0x227c
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_6_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_7_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_SHININESS
value|0x2250
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_TEXTURE_PROC_CTL
value|0x2268
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_TEXMAT_0_ENABLE
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_TEXMAT_1_ENABLE
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_TEXMAT_2_ENABLE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_TEXMAT_3_ENABLE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_0_ENABLE
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_1_ENABLE
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_2_ENABLE
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXMAT_3_ENABLE
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_TEXCOORD_0
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_TEXCOORD_1
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_TEXCOORD_2
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_TEXCOORD_3
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_OBJ
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_EYE
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_EYE_NORMAL
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_EYE_REFLECT
value|7
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_INPUT_EYE_NORMALIZED
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_0_INPUT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_1_INPUT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_2_INPUT_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_TEXGEN_3_INPUT_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_SE_TCL_UCP_VERT_BLEND_CTL
value|0x2264
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_IN_CLIP_SPACE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_IN_MODEL_SPACE
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_0
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_1
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_2
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_3
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_4
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_UCP_ENABLE_5
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FOG_MASK
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FOG_DISABLE
value|(0<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FOG_EXP
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FOG_EXP2
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_TCL_FOG_LINEAR
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_RNG_BASED_FOG
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_LIGHT_TWOSIDE
value|(1<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_OP_COUNT_MASK
value|(7<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_BLEND_OP_COUNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_POSITION_BLEND_OP_ENABLE
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_NORMAL_BLEND_OP_ENABLE
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_0_PRIMARY
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_0_SECONDARY
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_1_PRIMARY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_1_SECONDARY
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_2_PRIMARY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_2_SECONDARY
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_3_PRIMARY
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_SRC_3_SECONDARY
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_VERTEX_BLEND_WGT_MINUS_ONE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|RADEON_CULL_FRONT_IS_CW
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CULL_FRONT_IS_CCW
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CULL_FRONT
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|RADEON_CULL_BACK
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCE_W_TO_ONE
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_XSCALE
value|0x1d98
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_XOFFSET
value|0x1d9c
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_YSCALE
value|0x1da0
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_YOFFSET
value|0x1da4
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_ZSCALE
value|0x1da8
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VPORT_ZOFFSET
value|0x1dac
end_define

begin_define
define|#
directive|define
name|RADEON_SE_ZBIAS_FACTOR
value|0x1db0
end_define

begin_define
define|#
directive|define
name|RADEON_SE_ZBIAS_CONSTANT
value|0x1db4
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT
value|0x2080
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_XY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_W0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_FPCOLOR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_FPALPHA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_PKCOLOR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_FPSPEC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_FPFOG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_PKSPEC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_ST0
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_ST1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Q1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_ST2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Q2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_ST3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Q3
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Q0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_BLND_WEIGHT_CNT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_N0
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_XY1
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Z1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_W1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_N1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VTX_FMT_Z
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_SE_VF_CNTL
value|0x2084
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_POINT_LIST
value|1
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_LINE_LIST
value|2
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_LINE_STRIP
value|3
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_TRIANGLE_LIST
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_TRIANGLE_FAN
value|5
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_TRIANGLE_STRIP
value|6
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_TRIANGLE_FLAG
value|7
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_RECTANGLE_LIST
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_POINT_LIST_3
value|9
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_LINE_LIST_3
value|10
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_SPIRIT_LIST
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_LINE_LOOP
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_QUAD_LIST
value|13
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_QUAD_STRIP
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_TYPE_POLYGON
value|15
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_WALK_STATE
value|(0<<4)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_WALK_INDEX
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_WALK_LIST
value|(2<<4)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PRIM_WALK_DATA
value|(3<<4)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_COLOR_ORDER_RGBA
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_RADEON_MODE
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_TCL_OUTPUT_CTL_ENA
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_PROG_STREAM_ENA
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|RADEON_VF_INDEX_SIZE_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_VF_NUM_VERTICES_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SE_PORT_DATA0
value|0x2000
end_define

begin_define
define|#
directive|define
name|R200_SE_VAP_CNTL
value|0x2080
end_define

begin_define
define|#
directive|define
name|R200_VAP_TCL_ENABLE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R200_VAP_SINGLE_BUF_STATE_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R200_VAP_FORCE_W_TO_ONE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|R200_VAP_D3D_TEX_DEFAULT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|R200_VAP_VF_MAX_VTX_NUM__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|R200_VAP_VF_MAX_VTX_NUM
value|(9<< 18)
end_define

begin_define
define|#
directive|define
name|R200_VAP_DX_CLIP_SPACE_DEF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|R200_VF_MAX_VTX_INDX
value|0x210c
end_define

begin_define
define|#
directive|define
name|R200_VF_MIN_VTX_INDX
value|0x2110
end_define

begin_define
define|#
directive|define
name|R200_SE_VTE_CNTL
value|0x20b0
end_define

begin_define
define|#
directive|define
name|R200_VPORT_X_SCALE_ENA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|R200_VPORT_X_OFFSET_ENA
value|0x00000002
end_define

begin_define
define|#
directive|define
name|R200_VPORT_Y_SCALE_ENA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|R200_VPORT_Y_OFFSET_ENA
value|0x00000008
end_define

begin_define
define|#
directive|define
name|R200_VPORT_Z_SCALE_ENA
value|0x00000010
end_define

begin_define
define|#
directive|define
name|R200_VPORT_Z_OFFSET_ENA
value|0x00000020
end_define

begin_define
define|#
directive|define
name|R200_VTX_XY_FMT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|R200_VTX_Z_FMT
value|0x00000200
end_define

begin_define
define|#
directive|define
name|R200_VTX_W0_FMT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|R200_VTX_W0_NORMALIZE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|R200_VTX_ST_DENORMALIZED
value|0x00001000
end_define

begin_define
define|#
directive|define
name|R200_SE_VAP_CNTL_STATUS
value|0x2140
end_define

begin_define
define|#
directive|define
name|R200_VC_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R200_VC_16BIT_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R200_VC_32BIT_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_0
value|0x2c00
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_1
value|0x2c20
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_2
value|0x2c40
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_3
value|0x2c60
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_4
value|0x2c80
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFILTER_5
value|0x2ca0
end_define

begin_define
define|#
directive|define
name|R200_MAG_FILTER_NEAREST
value|(0<<  0)
end_define

begin_define
define|#
directive|define
name|R200_MAG_FILTER_LINEAR
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R200_MAG_FILTER_MASK
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_NEAREST
value|(0<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_LINEAR
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_NEAREST_MIP_NEAREST
value|(2<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_NEAREST_MIP_LINEAR
value|(3<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_LINEAR_MIP_NEAREST
value|(6<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_LINEAR_MIP_LINEAR
value|(7<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_ANISO_NEAREST
value|(8<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_ANISO_LINEAR
value|(9<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_ANISO_NEAREST_MIP_NEAREST
value|(10<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_ANISO_NEAREST_MIP_LINEAR
value|(11<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MIN_FILTER_MASK
value|(15<<  1)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_1_TO_1
value|(0<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_2_TO_1
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_4_TO_1
value|(2<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_8_TO_1
value|(3<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_16_TO_1
value|(4<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_ANISO_MASK
value|(7<<  5)
end_define

begin_define
define|#
directive|define
name|R200_MAX_MIP_LEVEL_MASK
value|(0x0f<< 16)
end_define

begin_define
define|#
directive|define
name|R200_MAX_MIP_LEVEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R200_YUV_TO_RGB
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R200_YUV_TEMPERATURE_COOL
value|(0<< 21)
end_define

begin_define
define|#
directive|define
name|R200_YUV_TEMPERATURE_HOT
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R200_YUV_TEMPERATURE_MASK
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R200_WRAPEN_S
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_WRAP
value|(0<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_MIRROR
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_CLAMP_LAST
value|(2<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_MIRROR_CLAMP_LAST
value|(3<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_CLAMP_BORDER
value|(4<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_MIRROR_CLAMP_BORDER
value|(5<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_CLAMP_GL
value|(6<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_MIRROR_CLAMP_GL
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_S_MASK
value|(7<< 23)
end_define

begin_define
define|#
directive|define
name|R200_WRAPEN_T
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_WRAP
value|(0<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_MIRROR
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_CLAMP_LAST
value|(2<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_MIRROR_CLAMP_LAST
value|(3<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_CLAMP_BORDER
value|(4<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_MIRROR_CLAMP_BORDER
value|(5<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_CLAMP_GL
value|(6<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_MIRROR_CLAMP_GL
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|R200_CLAMP_T_MASK
value|(7<< 27)
end_define

begin_define
define|#
directive|define
name|R200_KILL_LT_ZERO
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R200_BORDER_MODE_OGL
value|(0<< 31)
end_define

begin_define
define|#
directive|define
name|R200_BORDER_MODE_D3D
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_0
value|0x2c04
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_1
value|0x2c24
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_2
value|0x2c44
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_3
value|0x2c64
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_4
value|0x2c84
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_5
value|0x2ca4
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_I8
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_AI88
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_RGB332
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ARGB1555
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_RGB565
value|(4<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ARGB4444
value|(5<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ARGB8888
value|(6<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_RGBA8888
value|(7<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_Y8
value|(8<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_AVYU4444
value|(9<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_VYUY422
value|(10<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_YVYU422
value|(11<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_DXT1
value|(12<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_DXT23
value|(14<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_DXT45
value|(15<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_DVDU88
value|(18<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_LDVDU655
value|(19<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_LDVDU8888
value|(20<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_GR1616
value|(21<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ABGR8888
value|(22<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_BGR111110
value|(23<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_FORMAT_MASK
value|(31<<	0)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_FORMAT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ALPHA_IN_MAP
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_NON_POWER2
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_WIDTH_MASK
value|(15<<	8)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_WIDTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_HEIGHT_MASK
value|(15<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_HEIGHT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_F5_WIDTH_MASK
value|(15<< 16)
end_define

begin_comment
comment|/* cube face 5 */
end_comment

begin_define
define|#
directive|define
name|R200_TXFORMAT_F5_WIDTH_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_F5_HEIGHT_MASK
value|(15<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_F5_HEIGHT_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ0
value|(0<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ1
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ2
value|(2<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ3
value|(3<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ4
value|(4<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_STQ5
value|(5<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_MASK
value|(7<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ST_ROUTE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_LOOKUP_DISABLE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_ALPHA_MASK_ENABLE
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_CHROMA_KEY_ENABLE
value|(1<< 29)
end_define

begin_define
define|#
directive|define
name|R200_TXFORMAT_CUBIC_MAP_ENABLE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_0
value|0x2c08
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_1
value|0x2c28
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_2
value|0x2c48
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_3
value|0x2c68
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_4
value|0x2c88
end_define

begin_define
define|#
directive|define
name|R200_PP_TXFORMAT_X_5
value|0x2ca8
end_define

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_0
value|0x2c0c
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_1
value|0x2c2c
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_2
value|0x2c4c
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_3
value|0x2c6c
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_4
value|0x2c8c
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXSIZE_5
value|0x2cac
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_0
value|0x2c10
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_1
value|0x2c30
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_2
value|0x2c50
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_3
value|0x2c70
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_4
value|0x2c90
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_TXPITCH_5
value|0x2cb0
end_define

begin_comment
comment|/* NPOT only */
end_comment

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_0
value|0x2c18
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_1
value|0x2c38
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_2
value|0x2c58
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_3
value|0x2c78
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_4
value|0x2c98
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_FACES_5
value|0x2cb8
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_0
value|0x2d00
end_define

begin_define
define|#
directive|define
name|R200_TXO_ENDIAN_NO_SWAP
value|(0<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXO_ENDIAN_BYTE_SWAP
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXO_ENDIAN_WORD_SWAP
value|(2<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXO_ENDIAN_HALFDW_SWAP
value|(3<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXO_MACRO_LINEAR
value|(0<< 2)
end_define

begin_define
define|#
directive|define
name|R200_TXO_MACRO_TILE
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|R200_TXO_MICRO_LINEAR
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|R200_TXO_MICRO_TILE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|R200_TXO_OFFSET_MASK
value|0xffffffe0
end_define

begin_define
define|#
directive|define
name|R200_TXO_OFFSET_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_0
value|0x2d04
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_0
value|0x2d08
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_0
value|0x2d0c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_0
value|0x2d10
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_0
value|0x2d14
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_1
value|0x2d18
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_1
value|0x2d1c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_1
value|0x2d20
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_1
value|0x2d24
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_1
value|0x2d28
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_1
value|0x2d2c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_2
value|0x2d30
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_2
value|0x2d34
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_2
value|0x2d38
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_2
value|0x2d3c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_2
value|0x2d40
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_2
value|0x2d44
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_3
value|0x2d48
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_3
value|0x2d4c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_3
value|0x2d50
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_3
value|0x2d54
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_3
value|0x2d58
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_3
value|0x2d5c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_4
value|0x2d60
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_4
value|0x2d64
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_4
value|0x2d68
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_4
value|0x2d6c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_4
value|0x2d70
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_4
value|0x2d74
end_define

begin_define
define|#
directive|define
name|R200_PP_TXOFFSET_5
value|0x2d78
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F1_5
value|0x2d7c
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F2_5
value|0x2d80
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F3_5
value|0x2d84
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F4_5
value|0x2d88
end_define

begin_define
define|#
directive|define
name|R200_PP_CUBIC_OFFSET_F5_5
value|0x2d8c
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_0
value|0x2ee0
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_1
value|0x2ee4
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_2
value|0x2ee8
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_3
value|0x2eec
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_4
value|0x2ef0
end_define

begin_define
define|#
directive|define
name|R200_PP_TFACTOR_5
value|0x2ef4
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND_0
value|0x2f00
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_ZERO
value|(0)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_CURRENT_COLOR
value|(2)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_CURRENT_ALPHA
value|(3)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_DIFFUSE_COLOR
value|(4)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_DIFFUSE_ALPHA
value|(5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_SPECULAR_COLOR
value|(6)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_SPECULAR_ALPHA
value|(7)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_TFACTOR_COLOR
value|(8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_TFACTOR_ALPHA
value|(9)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R0_COLOR
value|(10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R0_ALPHA
value|(11)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R1_COLOR
value|(12)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R1_ALPHA
value|(13)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R2_COLOR
value|(14)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R2_ALPHA
value|(15)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R3_COLOR
value|(16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R3_ALPHA
value|(17)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R4_COLOR
value|(18)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R4_ALPHA
value|(19)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R5_COLOR
value|(20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_R5_ALPHA
value|(21)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_TFACTOR1_COLOR
value|(26)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_TFACTOR1_ALPHA
value|(27)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_ZERO
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_CURRENT_COLOR
value|(2<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_CURRENT_ALPHA
value|(3<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_DIFFUSE_COLOR
value|(4<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_DIFFUSE_ALPHA
value|(5<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_SPECULAR_COLOR
value|(6<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_SPECULAR_ALPHA
value|(7<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_TFACTOR_COLOR
value|(8<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_TFACTOR_ALPHA
value|(9<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R0_COLOR
value|(10<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R0_ALPHA
value|(11<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R1_COLOR
value|(12<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R1_ALPHA
value|(13<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R2_COLOR
value|(14<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R2_ALPHA
value|(15<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R3_COLOR
value|(16<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R3_ALPHA
value|(17<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R4_COLOR
value|(18<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R4_ALPHA
value|(19<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R5_COLOR
value|(20<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_R5_ALPHA
value|(21<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_TFACTOR1_COLOR
value|(26<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_TFACTOR1_ALPHA
value|(27<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_MASK
value|(31<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_B_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_ZERO
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_CURRENT_COLOR
value|(2<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_CURRENT_ALPHA
value|(3<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_DIFFUSE_COLOR
value|(4<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_DIFFUSE_ALPHA
value|(5<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_SPECULAR_COLOR
value|(6<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_SPECULAR_ALPHA
value|(7<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_TFACTOR_COLOR
value|(8<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_TFACTOR_ALPHA
value|(9<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R0_COLOR
value|(10<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R0_ALPHA
value|(11<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R1_COLOR
value|(12<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R1_ALPHA
value|(13<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R2_COLOR
value|(14<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R2_ALPHA
value|(15<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R3_COLOR
value|(16<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R3_ALPHA
value|(17<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R4_COLOR
value|(18<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R4_ALPHA
value|(19<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R5_COLOR
value|(20<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_R5_ALPHA
value|(21<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_TFACTOR1_COLOR
value|(26<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_TFACTOR1_ALPHA
value|(27<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_MASK
value|(31<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXC_ARG_C_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_A
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_A_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_BIAS_ARG_A
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_ARG_A
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R200_TXC_NEG_ARG_A
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_B
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_B_SHIFT
value|(20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_BIAS_ARG_B
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_ARG_B
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|R200_TXC_NEG_ARG_B
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_C
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXC_COMP_ARG_C_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|R200_TXC_BIAS_ARG_C
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_ARG_C
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R200_TXC_NEG_ARG_C
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_MADD
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_CND0
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_LERP
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_DOT3
value|(4<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_DOT4
value|(5<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_CONDITIONAL
value|(6<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_DOT2_ADD
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OP_MASK
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXCBLEND2_0
value|0x2f04
end_define

begin_define
define|#
directive|define
name|R200_TXC_TFACTOR_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXC_TFACTOR_SEL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|R200_TXC_TFACTOR1_SEL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R200_TXC_TFACTOR1_SEL_MASK
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_1X
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_2X
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_4X
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_8X
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_INV2
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_INV4
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_SCALE_INV8
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXC_CLAMP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R200_TXC_CLAMP_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXC_CLAMP_WRAP
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXC_CLAMP_0_1
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXC_CLAMP_8_8
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_MASK
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_NONE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R1
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R2
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R3
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R4
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_REG_R5
value|(6<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_MASK
value|(7<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_RGB
value|(0<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_RG
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_RB
value|(2<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_R
value|(3<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_GB
value|(4<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_G
value|(5<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_B
value|(6<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_OUTPUT_MASK_NONE
value|(7<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_RED
value|1
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_BLUE
value|3
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_A_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_A_MASK
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_B_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_B_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_C_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|R200_TXC_REPL_ARG_C_MASK
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXABLEND_0
value|0x2f08
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_ZERO
value|(0)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_CURRENT_ALPHA
value|(2)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_CURRENT_BLUE
value|(3)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_DIFFUSE_ALPHA
value|(4)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_DIFFUSE_BLUE
value|(5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_SPECULAR_ALPHA
value|(6)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_SPECULAR_BLUE
value|(7)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_TFACTOR_ALPHA
value|(8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_TFACTOR_BLUE
value|(9)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R0_ALPHA
value|(10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R0_BLUE
value|(11)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R1_ALPHA
value|(12)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R1_BLUE
value|(13)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R2_ALPHA
value|(14)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R2_BLUE
value|(15)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R3_ALPHA
value|(16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R3_BLUE
value|(17)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R4_ALPHA
value|(18)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R4_BLUE
value|(19)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R5_ALPHA
value|(20)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_R5_BLUE
value|(21)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_TFACTOR1_ALPHA
value|(26)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_TFACTOR1_BLUE
value|(27)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_MASK
value|(31<< 0)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_A_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_ZERO
value|(0<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_CURRENT_ALPHA
value|(2<< 5)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_CURRENT_BLUE
value|(3<< 5)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_DIFFUSE_ALPHA
value|(4<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_DIFFUSE_BLUE
value|(5<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_SPECULAR_ALPHA
value|(6<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_SPECULAR_BLUE
value|(7<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_TFACTOR_ALPHA
value|(8<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_TFACTOR_BLUE
value|(9<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R0_ALPHA
value|(10<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R0_BLUE
value|(11<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R1_ALPHA
value|(12<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R1_BLUE
value|(13<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R2_ALPHA
value|(14<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R2_BLUE
value|(15<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R3_ALPHA
value|(16<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R3_BLUE
value|(17<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R4_ALPHA
value|(18<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R4_BLUE
value|(19<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R5_ALPHA
value|(20<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_R5_BLUE
value|(21<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_TFACTOR1_ALPHA
value|(26<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_TFACTOR1_BLUE
value|(27<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_MASK
value|(31<< 5)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_B_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_ZERO
value|(0<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_CURRENT_ALPHA
value|(2<< 10)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_CURRENT_BLUE
value|(3<< 10)
end_define

begin_comment
comment|/* guess */
end_comment

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_DIFFUSE_ALPHA
value|(4<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_DIFFUSE_BLUE
value|(5<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_SPECULAR_ALPHA
value|(6<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_SPECULAR_BLUE
value|(7<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_TFACTOR_ALPHA
value|(8<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_TFACTOR_BLUE
value|(9<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R0_ALPHA
value|(10<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R0_BLUE
value|(11<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R1_ALPHA
value|(12<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R1_BLUE
value|(13<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R2_ALPHA
value|(14<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R2_BLUE
value|(15<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R3_ALPHA
value|(16<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R3_BLUE
value|(17<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R4_ALPHA
value|(18<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R4_BLUE
value|(19<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R5_ALPHA
value|(20<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_R5_BLUE
value|(21<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_TFACTOR1_ALPHA
value|(26<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_TFACTOR1_BLUE
value|(27<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_MASK
value|(31<< 10)
end_define

begin_define
define|#
directive|define
name|R200_TXA_ARG_C_SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_A
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_A_SHIFT
value|(16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_BIAS_ARG_A
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_ARG_A
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|R200_TXA_NEG_ARG_A
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_B
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_B_SHIFT
value|(20)
end_define

begin_define
define|#
directive|define
name|R200_TXA_BIAS_ARG_B
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_ARG_B
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|R200_TXA_NEG_ARG_B
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_C
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|R200_TXA_COMP_ARG_C_SHIFT
value|(24)
end_define

begin_define
define|#
directive|define
name|R200_TXA_BIAS_ARG_C
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_ARG_C
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|R200_TXA_NEG_ARG_C
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OP_MADD
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OP_CND0
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OP_LERP
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OP_CONDITIONAL
value|(6<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OP_MASK
value|(7<< 28)
end_define

begin_define
define|#
directive|define
name|R200_PP_TXABLEND2_0
value|0x2f0c
end_define

begin_define
define|#
directive|define
name|R200_TXA_TFACTOR_SEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXA_TFACTOR_SEL_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|R200_TXA_TFACTOR1_SEL_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|R200_TXA_TFACTOR1_SEL_MASK
value|(0x7<< 4)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_1X
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_2X
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_4X
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_8X
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_INV2
value|(5<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_INV4
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_SCALE_INV8
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|R200_TXA_CLAMP_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R200_TXA_CLAMP_MASK
value|(3<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXA_CLAMP_WRAP
value|(0<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXA_CLAMP_0_1
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXA_CLAMP_8_8
value|(2<< 12)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_MASK
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_NONE
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R0
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R1
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R2
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R3
value|(4<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R4
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_OUTPUT_REG_R5
value|(6<< 16)
end_define

begin_define
define|#
directive|define
name|R200_TXA_DOT_ALPHA
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_RED
value|1
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_GREEN
value|2
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_A_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_A_MASK
value|(3<< 26)
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_B_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_B_MASK
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_C_SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|R200_TXA_REPL_ARG_C_MASK
value|(3<< 30)
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_FMT_0
value|0x2088
end_define

begin_define
define|#
directive|define
name|R200_VTX_XY
value|0
end_define

begin_comment
comment|/* always have xy */
end_comment

begin_define
define|#
directive|define
name|R200_VTX_Z0
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R200_VTX_W0
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|R200_VTX_WEIGHT_COUNT_SHIFT
value|(2)
end_define

begin_define
define|#
directive|define
name|R200_VTX_PV_MATRIX_SEL
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|R200_VTX_N0
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|R200_VTX_POINT_SIZE
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|R200_VTX_DISCRETE_FOG
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|R200_VTX_SHININESS_0
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|R200_VTX_SHININESS_1
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_NOT_PRESENT
value|0
end_define

begin_define
define|#
directive|define
name|R200_VTX_PK_RGBA
value|1
end_define

begin_define
define|#
directive|define
name|R200_VTX_FP_RGB
value|2
end_define

begin_define
define|#
directive|define
name|R200_VTX_FP_RGBA
value|3
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_MASK
value|3
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_0_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_1_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_2_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_3_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_4_SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_5_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_6_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|R200_VTX_COLOR_7_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|R200_VTX_XY1
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|R200_VTX_Z1
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|R200_VTX_W1
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|R200_VTX_N1
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_FMT_1
value|0x208c
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX0_COMP_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX1_COMP_CNT_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX2_COMP_CNT_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX3_COMP_CNT_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX4_COMP_CNT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|R200_VTX_TEX5_COMP_CNT_SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_OUTPUT_VTX_FMT_0
value|0x2090
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_OUTPUT_VTX_FMT_1
value|0x2094
end_define

begin_define
define|#
directive|define
name|R200_SE_TCL_OUTPUT_VTX_COMP_SEL
value|0x2250
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_XYZW
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_COLOR_0
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_COLOR_1
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_0
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_1
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_2
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_3
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_4
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_5
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_TEX_MASK
value|(0x3f<<16)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_DISCRETE_FOG
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|R200_OUTPUT_PT_SIZE
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|R200_FORCE_INORDER_PROC
value|(1<<31)
end_define

begin_define
define|#
directive|define
name|R200_PP_CNTL_X
value|0x2cc4
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_0
value|0x2c1c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_1
value|0x2c3c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_2
value|0x2c5c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_3
value|0x2c7c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_4
value|0x2c9c
end_define

begin_define
define|#
directive|define
name|R200_PP_TXMULTI_CTL_5
value|0x2cbc
end_define

begin_define
define|#
directive|define
name|R200_SE_VTX_STATE_CNTL
value|0x2180
end_define

begin_define
define|#
directive|define
name|R200_UPDATE_USER_COLOR_0_ENA_MASK
value|(1<<16)
end_define

begin_comment
comment|/* Registers for CP and Microcode Engine */
end_comment

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_ADDR
value|0x07d4
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_RADDR
value|0x07d8
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_DATAH
value|0x07dc
end_define

begin_define
define|#
directive|define
name|RADEON_CP_ME_RAM_DATAL
value|0x07e0
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_BASE
value|0x0700
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_CNTL
value|0x0704
end_define

begin_define
define|#
directive|define
name|RADEON_RB_BUFSZ_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_RB_BUFSZ_MASK
value|(0x3f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_RB_BLKSZ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_RB_BLKSZ_MASK
value|(0x3f<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_BUF_SWAP_32BIT
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_FETCH_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_FETCH_MASK
value|(0x3<< 18)
end_define

begin_define
define|#
directive|define
name|RADEON_RB_NO_UPDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|RADEON_RB_RPTR_WR_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_RPTR_ADDR
value|0x070c
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_RPTR
value|0x0710
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_WPTR
value|0x0714
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_RPTR_WR
value|0x071c
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_UMSK
value|0x0770
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_ADDR
value|0x0774
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_BASE
value|0xc100
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_CNTL
value|0xc104
end_define

begin_define
define|#
directive|define
name|R600_RB_BUFSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|R600_RB_BLKSZ
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|R600_RB_NO_UPDATE
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|R600_RB_RPTR_WR_ENA
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_WR
value|0xc108
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_ADDR
value|0xc10c
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR_ADDR_HI
value|0xc110
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR
value|0xc114
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_ADDR
value|0xc118
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_ADDR_HI
value|0xc11c
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_RPTR
value|0x8700
end_define

begin_define
define|#
directive|define
name|R600_CP_RB_WPTR_DELAY
value|0x8704
end_define

begin_define
define|#
directive|define
name|RADEON_CP_IB_BASE
value|0x0738
end_define

begin_define
define|#
directive|define
name|RADEON_CP_IB_BUFSZ
value|0x073c
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_CNTL
value|0x0740
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_CNT_PRIMARY_MASK
value|(0xff<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIDIS_INDDIS
value|(0<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDDIS
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIBM_INDDIS
value|(2<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDBM
value|(3<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIBM_INDBM
value|(4<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_PRIPIO_INDPIO
value|(15<< 28)
end_define

begin_define
define|#
directive|define
name|R300_CP_RESYNC_ADDR
value|0x778
end_define

begin_define
define|#
directive|define
name|R300_CP_RESYNC_DATA
value|0x77c
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_STAT
value|0x07f8
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_RPTR_PRIMARY_MASK
value|(0xff<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_WPTR_PRIMARY_MASK
value|(0xff<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_RPTR_INDIRECT_MASK
value|(0xff<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_CSQ_WPTR_INDIRECT_MASK
value|(0xff<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ2_STAT
value|0x07fc
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_ADDR
value|0x07f0
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_DATA
value|0x07f4
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_APER_PRIMARY
value|0x1000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_APER_INDIRECT
value|0x1300
end_define

begin_define
define|#
directive|define
name|RADEON_CP_RB_WPTR_DELAY
value|0x0718
end_define

begin_define
define|#
directive|define
name|RADEON_PRE_WRITE_TIMER_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_PRE_WRITE_LIMIT_SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|RADEON_CP_CSQ_MODE
value|0x0744
end_define

begin_define
define|#
directive|define
name|RADEON_INDIRECT2_START_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_INDIRECT2_START_MASK
value|(0x7f<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_INDIRECT1_START_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_INDIRECT1_START_MASK
value|(0x7f<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_CNTL
value|0x01d0
end_define

begin_define
define|#
directive|define
name|RADEON_PCIGART_TRANSLATE_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_DIS_OUT_OF_PCI_GART_ACCESS
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RS400_MSI_REARM
value|(1<< 3)
end_define

begin_comment
comment|/* rs400/rs480 */
end_comment

begin_define
define|#
directive|define
name|RADEON_AIC_LO_ADDR
value|0x01dc
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_PT_BASE
value|0x01d8
end_define

begin_define
define|#
directive|define
name|RADEON_AIC_HI_ADDR
value|0x01e0
end_define

begin_comment
comment|/* Constants */
end_comment

begin_comment
comment|/* #define RADEON_LAST_FRAME_REG               RADEON_GUI_SCRATCH_REG0 */
end_comment

begin_comment
comment|/* efine RADEON_LAST_CLEAR_REG               RADEON_GUI_SCRATCH_REG2 */
end_comment

begin_comment
comment|/* CP packet types */
end_comment

begin_define
define|#
directive|define
name|RADEON_CP_PACKET0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET2
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET_COUNT_MASK
value|0x3fff0000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET_MAX_DWORDS
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET0_REG_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|R300_CP_PACKET0_REG_MASK
value|0x00001fff
end_define

begin_define
define|#
directive|define
name|R600_CP_PACKET0_REG_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1_REG0_MASK
value|0x000007ff
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET1_REG1_MASK
value|0x003ff800
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET0_ONE_REG_WR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_NOP
value|0xC0001000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_NEXT_CHAR
value|0xC0001900
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_PLY_NEXTSCAN
value|0xC0001D00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_SET_SCISSORS
value|0xC0001E00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_3D_RNDR_GEN_INDX_PRIM
value|0xC0002300
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_LOAD_MICROCODE
value|0xC0002400
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_WAIT_FOR_IDLE
value|0xC0002600
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_3D_DRAW_VBUF
value|0xC0002800
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_3D_DRAW_IMMD
value|0xC0002900
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_3D_DRAW_INDX
value|0xC0002A00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_LOAD_PALETTE
value|0xC0002C00
end_define

begin_define
define|#
directive|define
name|R200_CP_PACKET3_3D_DRAW_IMMD_2
value|0xc0003500
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_3D_LOAD_VBPNTR
value|0xC0002F00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_PAINT
value|0xC0009100
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_BITBLT
value|0xC0009200
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_SMALLTEXT
value|0xC0009300
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_HOSTDATA_BLT
value|0xC0009400
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_POLYLINE
value|0xC0009500
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_POLYSCANLINES
value|0xC0009800
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_PAINT_MULTI
value|0xC0009A00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_BITBLT_MULTI
value|0xC0009B00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_PACKET3_CNTL_TRANS_BITBLT
value|0xC0009C00
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_XY
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_W0
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_FPCOLOR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_FPALPHA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_PKCOLOR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_FPSPEC
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_FPFOG
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_PKSPEC
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_ST0
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_ST1
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Q1
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_ST2
value|0x00000400
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Q2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_ST3
value|0x00001000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Q3
value|0x00002000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Q0
value|0x00004000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_BLND_WEIGHT_CNT_MASK
value|0x00038000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_N0
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_XY1
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Z1
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_W1
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_N1
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_FRMT_Z
value|0x80000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_NONE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_POINT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_LINE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_LINE_STRIP
value|0x00000003
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_TRI_LIST
value|0x00000004
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_TRI_FAN
value|0x00000005
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_TRI_STRIP
value|0x00000006
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_TRI_TYPE_2
value|0x00000007
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_RECT_LIST
value|0x00000008
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_3VRT_POINT_LIST
value|0x00000009
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_TYPE_3VRT_LINE_LIST
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_WALK_IND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_WALK_LIST
value|0x00000020
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_PRIM_WALK_RING
value|0x00000030
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_COLOR_ORDER_BGRA
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_COLOR_ORDER_RGBA
value|0x00000040
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_MAOS_ENABLE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_VTX_FMT_NON_RADEON_MODE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_VTX_FMT_RADEON_MODE
value|0x00000100
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_TCL_DISABLE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_TCL_ENABLE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|RADEON_CP_VC_CNTL_NUM_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_0_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_1_ADDR
value|4
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_2_ADDR
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_3_ADDR
value|12
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_4_ADDR
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_5_ADDR
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_6_ADDR
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_7_ADDR
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_8_ADDR
value|32
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_9_ADDR
value|36
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_10_ADDR
value|40
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_11_ADDR
value|44
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_12_ADDR
value|48
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_13_ADDR
value|52
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_14_ADDR
value|56
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_15_ADDR
value|60
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_AMBIENT_ADDR
value|64
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_DIFFUSE_ADDR
value|72
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_SPECULAR_ADDR
value|80
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_DIRPOS_ADDR
value|88
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_HWVSPOT_ADDR
value|96
end_define

begin_define
define|#
directive|define
name|RADEON_VS_LIGHT_ATTENUATION_ADDR
value|104
end_define

begin_define
define|#
directive|define
name|RADEON_VS_MATRIX_EYE2CLIP_ADDR
value|112
end_define

begin_define
define|#
directive|define
name|RADEON_VS_UCP_ADDR
value|116
end_define

begin_define
define|#
directive|define
name|RADEON_VS_GLOBAL_AMBIENT_ADDR
value|122
end_define

begin_define
define|#
directive|define
name|RADEON_VS_FOG_PARAM_ADDR
value|123
end_define

begin_define
define|#
directive|define
name|RADEON_VS_EYE_VECTOR_ADDR
value|124
end_define

begin_define
define|#
directive|define
name|RADEON_SS_LIGHT_DCD_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_SS_LIGHT_SPOT_EXPONENT_ADDR
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_SS_LIGHT_SPOT_CUTOFF_ADDR
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SS_LIGHT_SPECULAR_THRESH_ADDR
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_SS_LIGHT_RANGE_CUTOFF_ADDR
value|32
end_define

begin_define
define|#
directive|define
name|RADEON_SS_VERT_GUARD_CLIP_ADJ_ADDR
value|48
end_define

begin_define
define|#
directive|define
name|RADEON_SS_VERT_GUARD_DISCARD_ADJ_ADDR
value|49
end_define

begin_define
define|#
directive|define
name|RADEON_SS_HORZ_GUARD_CLIP_ADJ_ADDR
value|50
end_define

begin_define
define|#
directive|define
name|RADEON_SS_HORZ_GUARD_DISCARD_ADJ_ADDR
value|51
end_define

begin_define
define|#
directive|define
name|RADEON_SS_SHININESS
value|60
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MASTER_CNTL
value|0x0800
end_define

begin_define
define|#
directive|define
name|RADEON_TV_ASYNC_RST
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT_ASYNC_RST
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_RESTART_PHASE_FIX
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FIFO_ASYNC_RST
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_VIN_ASYNC_RST
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_AUD_ASYNC_RST
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_DVS_ASYNC_RST
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_CRT_FIFO_CE_EN
value|(1<<  9)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FIFO_CE_EN
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_RE_SYNC_NOW_SEL_MASK
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_TVCLK_ALWAYS_ONb
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_ON
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_PRE_DAC_MUX_CNTL
value|0x0888
end_define

begin_define
define|#
directive|define
name|RADEON_Y_RED_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_C_GRN_EN
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_CMP_BLU_EN
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|RADEON_DAC_DITHER_EN
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_RED_MX_FORCE_DAC_DATA
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|RADEON_GRN_MX_FORCE_DAC_DATA
value|(6<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_BLU_MX_FORCE_DAC_DATA
value|(6<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FORCE_DAC_DATA_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TV_RGB_CNTL
value|0x0804
end_define

begin_define
define|#
directive|define
name|RADEON_SWITCH_TO_BLUE
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_DITHER_EN
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_SRC_SEL_MASK
value|(3<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_SRC_SEL_CRTC1
value|(0<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_SRC_SEL_RMX
value|(1<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_SRC_SEL_CRTC2
value|(2<<  8)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_CONVERT_BY_PASS
value|(1<< 10)
end_define

begin_define
define|#
directive|define
name|RADEON_UVRAM_READ_MARGIN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_FIFORAM_FFMACRO_READ_MARGIN_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_ATTEN_SEL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_TVOUT_SCALE_EN
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|RADEON_RGB_ATTEN_VAL
parameter_list|(
name|x
parameter_list|)
value|((x)<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_SYNC_CNTL
value|0x0808
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_OE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_OUT
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_IN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_PUB
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_PD
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_SYNC_IO_DRIVE
value|(1<<  5)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HTOTAL
value|0x080c
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HDISP
value|0x0810
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HSTART
value|0x0818
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HCOUNT
value|0x081C
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VTOTAL
value|0x0820
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VDISP
value|0x0824
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VCOUNT
value|0x0828
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FTOTAL
value|0x082c
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FCOUNT
value|0x0830
end_define

begin_define
define|#
directive|define
name|RADEON_TV_FRESTART
value|0x0834
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HRESTART
value|0x0838
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VRESTART
value|0x083c
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HOST_READ_DATA
value|0x0840
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HOST_WRITE_DATA
value|0x0844
end_define

begin_define
define|#
directive|define
name|RADEON_TV_HOST_RD_WT_CNTL
value|0x0848
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_FIFO_RD
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_FIFO_RD_ACK
value|(1<< 13)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_FIFO_WT
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_HOST_FIFO_WT_ACK
value|(1<< 15)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VSCALER_CNTL1
value|0x084c
end_define

begin_define
define|#
directive|define
name|RADEON_UV_INC_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|RADEON_UV_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_Y_W_EN
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|RADEON_RESTART_FIELD
value|(1<< 29)
end_define

begin_comment
comment|/* restart on field 0 */
end_comment

begin_define
define|#
directive|define
name|RADEON_Y_DEL_W_SIG_SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|RADEON_TV_TIMING_CNTL
value|0x0850
end_define

begin_define
define|#
directive|define
name|RADEON_H_INC_MASK
value|0xfff
end_define

begin_define
define|#
directive|define
name|RADEON_H_INC_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_REQ_Y_FIRST
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|RADEON_FORCE_BURST_ALWAYS
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|RADEON_UV_POST_SCALE_BYPASS
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_UV_OUTPUT_POST_SCALE_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_TV_VSCALER_CNTL2
value|0x0854
end_define

begin_define
define|#
directive|define
name|RADEON_DITHER_MODE
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_Y_OUTPUT_DITHER_EN
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_UV_OUTPUT_DITHER_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_UV_TO_BUF_DITHER_EN
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_Y_FALL_CNTL
value|0x0858
end_define

begin_define
define|#
directive|define
name|RADEON_Y_FALL_PING_PONG
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_Y_COEF_EN
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_Y_RISE_CNTL
value|0x085c
end_define

begin_define
define|#
directive|define
name|RADEON_Y_RISE_PING_PONG
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_Y_SAW_TOOTH_CNTL
value|0x0860
end_define

begin_define
define|#
directive|define
name|RADEON_TV_UPSAMP_AND_GAIN_CNTL
value|0x0864
end_define

begin_define
define|#
directive|define
name|RADEON_YUPSAMP_EN
value|(1<<  0)
end_define

begin_define
define|#
directive|define
name|RADEON_UVUPSAMP_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_GAIN_LIMIT_SETTINGS
value|0x0868
end_define

begin_define
define|#
directive|define
name|RADEON_Y_GAIN_LIMIT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_UV_GAIN_LIMIT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TV_LINEAR_GAIN_SETTINGS
value|0x086c
end_define

begin_define
define|#
directive|define
name|RADEON_Y_GAIN_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_UV_GAIN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MODULATOR_CNTL1
value|0x0870
end_define

begin_define
define|#
directive|define
name|RADEON_YFLT_EN
value|(1<<  2)
end_define

begin_define
define|#
directive|define
name|RADEON_UVFLT_EN
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_ALT_PHASE_EN
value|(1<<  6)
end_define

begin_define
define|#
directive|define
name|RADEON_SYNC_TIP_LEVEL
value|(1<<  7)
end_define

begin_define
define|#
directive|define
name|RADEON_BLANK_LEVEL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_SET_UP_LEVEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_SLEW_RATE_LIMIT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_CY_FILT_BLEND_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MODULATOR_CNTL2
value|0x0874
end_define

begin_define
define|#
directive|define
name|RADEON_TV_U_BURST_LEVEL_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RADEON_TV_V_BURST_LEVEL_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RADEON_TV_V_BURST_LEVEL_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_TV_CRC_CNTL
value|0x0890
end_define

begin_define
define|#
directive|define
name|RADEON_TV_UV_ADR
value|0x08ac
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_UV_ADR_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|RADEON_MAX_UV_ADR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RADEON_TABLE1_BOT_ADR_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|RADEON_TABLE1_BOT_ADR_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TABLE3_TOP_ADR_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|RADEON_TABLE3_TOP_ADR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|RADEON_HCODE_TABLE_SEL_MASK
value|0x06000000
end_define

begin_define
define|#
directive|define
name|RADEON_HCODE_TABLE_SEL_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|RADEON_VCODE_TABLE_SEL_MASK
value|0x18000000
end_define

begin_define
define|#
directive|define
name|RADEON_VCODE_TABLE_SEL_SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MAX_FIFO_ADDR
value|0x1a7
end_define

begin_define
define|#
directive|define
name|RADEON_TV_MAX_FIFO_ADDR_INTERNAL
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RADEON_TV_PLL_FINE_CNTL
value|0x0020
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_TV_PLL_CNTL
value|0x0021
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_TV_M0LO_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|RADEON_TV_M0HI_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|RADEON_TV_M0HI_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|RADEON_TV_N0LO_MASK
value|0x1ff
end_define

begin_define
define|#
directive|define
name|RADEON_TV_N0LO_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TV_N0HI_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|RADEON_TV_N0HI_SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|RADEON_TV_P_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|RADEON_TV_P_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|RADEON_TV_SLIP_EN
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_DTO_EN
value|(1<< 28)
end_define

begin_define
define|#
directive|define
name|RADEON_TV_PLL_CNTL1
value|0x0022
end_define

begin_comment
comment|/* PLL */
end_comment

begin_define
define|#
directive|define
name|RADEON_TVPLL_RESET
value|(1<<  1)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPLL_SLEEP
value|(1<<  3)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPLL_REFCLK_SEL
value|(1<<  4)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPCP_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|RADEON_TVPCP_MASK
value|(7<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPVG_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|RADEON_TVPVG_MASK
value|(7<< 11)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPDC_SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|RADEON_TVPDC_MASK
value|(3<< 14)
end_define

begin_define
define|#
directive|define
name|RADEON_TVPLL_TEST_DIS
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|RADEON_TVCLK_SRC_SEL_TVPLL
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_REQ_CNTL1
value|0xe30
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_START_REQ_LEVEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_START_REQ_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_STOP_REQ_LEVEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_STOP_REQ_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_ALLOW_FID_LEVEL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_ALLOW_FID_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_REQ_CNTL2
value|0xe34
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_CRITICAL_POINT_START_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_CRITICAL_POINT_START_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_CRITICAL_POINT_STOP_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_CRITICAL_POINT_STOP_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DMIF_MEM_CNTL1
value|0xe38
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_START_ADR_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS400_DISP2_START_ADR_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_CRITICAL_POINT_START_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_CRITICAL_POINT_START_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_CRITICAL_POINT_STOP_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_CRITICAL_POINT_STOP_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_REQ_CNTL1
value|0xe3c
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_START_REQ_LEVEL_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_START_REQ_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_STOP_REQ_LEVEL_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_STOP_REQ_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_ALLOW_FID_LEVEL_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|RS400_DISP1_ALLOW_FID_LEVEL_MASK
value|0x3ff
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_INDEX
value|0x0030
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_DATA
value|0x0034
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_CNTL
value|0x10
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_EN
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_PASS_THRU
value|(0<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_CLAMP_LO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_UNMAPPED_ACCESS_DISCARD
value|(3<< 1)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_32_128_CACHE
value|(0<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_MODE_8_4_128_CACHE
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_CHK_RW_VALID_EN
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_INVALIDATE_TLB
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_DISCARD_RD_ADDR_LO
value|0x11
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_DISCARD_RD_ADDR_HI
value|0x12
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_BASE
value|0x13
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_START_LO
value|0x14
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_START_HI
value|0x15
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_END_LO
value|0x16
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_END_HI
value|0x17
end_define

begin_define
define|#
directive|define
name|RADEON_PCIE_TX_GART_ERROR
value|0x18
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG0
value|0x15e0
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG1
value|0x15e4
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG2
value|0x15e8
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG3
value|0x15ec
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG4
value|0x15f0
end_define

begin_define
define|#
directive|define
name|RADEON_SCRATCH_REG5
value|0x15f4
end_define

begin_define
define|#
directive|define
name|RV530_GB_PIPE_SELECT2
value|0x4124
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

