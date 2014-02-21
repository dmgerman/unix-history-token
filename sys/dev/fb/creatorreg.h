begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2000 David S. Miller (davem@redhat.com)  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to deal  * in the Software without restriction, including without limitation the rights  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell  * copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * DAVID MILLER BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER  * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  *	from: XFree86: ffb_dac.h,v 1.1 2000/05/23 04:47:44 dawes Exp  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2003 Jake Burkholder.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_FB_CREATORREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_FB_CREATORREG_H_
end_define

begin_define
define|#
directive|define
name|FFB_NREG
value|24
end_define

begin_define
define|#
directive|define
name|FFB_PROM
value|0
end_define

begin_define
define|#
directive|define
name|FFB_DAC
value|1
end_define

begin_define
define|#
directive|define
name|FFB_FBC
value|2
end_define

begin_define
define|#
directive|define
name|FFB_DFB8R
value|3
end_define

begin_define
define|#
directive|define
name|FFB_DFB8G
value|4
end_define

begin_define
define|#
directive|define
name|FFB_DFB8B
value|5
end_define

begin_define
define|#
directive|define
name|FFB_DFB8X
value|6
end_define

begin_define
define|#
directive|define
name|FFB_DFB24
value|7
end_define

begin_define
define|#
directive|define
name|FFB_DFB32
value|8
end_define

begin_define
define|#
directive|define
name|FFB_SFB8R
value|9
end_define

begin_define
define|#
directive|define
name|FFB_SFB8G
value|10
end_define

begin_define
define|#
directive|define
name|FFB_SFB8B
value|11
end_define

begin_define
define|#
directive|define
name|FFB_SFB8X
value|12
end_define

begin_define
define|#
directive|define
name|FFB_SFB32
value|13
end_define

begin_define
define|#
directive|define
name|FFB_SFB64
value|14
end_define

begin_define
define|#
directive|define
name|FFB_DFB422A
value|15
end_define

begin_define
define|#
directive|define
name|FFB_DAC_TYPE
value|0x0
end_define

begin_define
define|#
directive|define
name|FFB_DAC_VALUE
value|0x4
end_define

begin_define
define|#
directive|define
name|FFB_DAC_TYPE2
value|0x8
end_define

begin_define
define|#
directive|define
name|FFB_DAC_VALUE2
value|0xc
end_define

begin_comment
comment|/* FFB_DAC_TYPE configuration and palette register addresses */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_UCTRL
value|0x1001
end_define

begin_comment
comment|/* User Control */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN
value|0x6000
end_define

begin_comment
comment|/* Timing Generator Control */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_DID
value|0x8000
end_define

begin_comment
comment|/* Device Identification */
end_comment

begin_comment
comment|/* FFB_DAC_CFG_UCTRL register */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_IPDISAB
value|0x0001
end_define

begin_comment
comment|/* Input Pullup Resistor Dis. */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_ABLANK
value|0x0002
end_define

begin_comment
comment|/* Asynchronous Blank */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_DBENAB
value|0x0004
end_define

begin_comment
comment|/* Double-Buffer Enable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_OVENAB
value|0x0008
end_define

begin_comment
comment|/* Overlay Enable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_WMODE
value|0x0030
end_define

begin_comment
comment|/* Window Mode */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_WM_COMB
value|0x0000
end_define

begin_comment
comment|/* Window Mode Combined */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_WM_S4
value|0x0010
end_define

begin_comment
comment|/* Window Mode Separate 4 */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_WM_S8
value|0x0020
end_define

begin_comment
comment|/* Window Mode Separate 8 */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_WM_RESV
value|0x0030
end_define

begin_comment
comment|/* Window Mode Reserved */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_UCTRL_MANREV
value|0x0f00
end_define

begin_comment
comment|/* Manufacturing Revision */
end_comment

begin_comment
comment|/* FFB_DAC_CFG_TGEN register */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_VIDE
value|0x01
end_define

begin_comment
comment|/* Video Enable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_TGE
value|0x02
end_define

begin_comment
comment|/* Timing Generator Enable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_HSD
value|0x04
end_define

begin_comment
comment|/* HSYNC* Disable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_VSD
value|0x08
end_define

begin_comment
comment|/* VSYNC* Disable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_EQD
value|0x10
end_define

begin_comment
comment|/* Equalization Disable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_MM
value|0x20
end_define

begin_comment
comment|/* 0 = Slave, 1 = Master */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_TGEN_IM
value|0x40
end_define

begin_comment
comment|/* 1 = Interlaced Mode */
end_comment

begin_comment
comment|/* FFB_DAC_CFG_DID register */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_DID_ONE
value|0x00000001
end_define

begin_comment
comment|/* Always Set */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_DID_MANUF
value|0x00000ffe
end_define

begin_comment
comment|/* DAC Manufacturer ID */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_DID_PNUM
value|0x0ffff000
end_define

begin_comment
comment|/* DAC Part Number */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CFG_DID_REV
value|0xf0000000
end_define

begin_comment
comment|/* DAC Revision */
end_comment

begin_comment
comment|/* FFB_DAC_TYPE2 cursor register addresses */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_BITMAP_P0
value|0x0
end_define

begin_comment
comment|/* Plane 0 Cursor Bitmap */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_BITMAP_P1
value|0x80
end_define

begin_comment
comment|/* Plane 1 Cursor Bitmap */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_CTRL
value|0x100
end_define

begin_comment
comment|/* Cursor Control */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_COLOR0
value|0x101
end_define

begin_comment
comment|/* Cursor Color 0 */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_COLOR1
value|0x102
end_define

begin_comment
comment|/* Cursor Color 1 (bg) */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_COLOR2
value|0x103
end_define

begin_comment
comment|/* Cursor Color 2 (fg) */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_POS
value|0x104
end_define

begin_comment
comment|/* Active Cursor Position */
end_comment

begin_comment
comment|/* FFB_DAC_CUR_CTRL register (might be inverted on PAC1 DACs) */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_CTRL_P0
value|0x1
end_define

begin_comment
comment|/* Plane0 Display Disable */
end_comment

begin_define
define|#
directive|define
name|FFB_DAC_CUR_CTRL_P1
value|0x2
end_define

begin_comment
comment|/* Plane1 Display Disable */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_BY
value|0x60
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BX
value|0x64
end_define

begin_define
define|#
directive|define
name|FFB_FBC_DY
value|0x68
end_define

begin_define
define|#
directive|define
name|FFB_FBC_DX
value|0x6c
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BH
value|0x70
end_define

begin_define
define|#
directive|define
name|FFB_FBC_BW
value|0x74
end_define

begin_define
define|#
directive|define
name|FFB_FBC_PPC
value|0x200
end_define

begin_comment
comment|/* Pixel Processor Control */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FG
value|0x208
end_define

begin_comment
comment|/* Foreground */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_BG
value|0x20c
end_define

begin_comment
comment|/* Background */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FBC
value|0x254
end_define

begin_comment
comment|/* Frame Buffer Control */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_ROP
value|0x258
end_define

begin_comment
comment|/* Raster Operation */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_PMASK
value|0x290
end_define

begin_comment
comment|/* Pixel Mask */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_DRAWOP
value|0x300
end_define

begin_comment
comment|/* Draw Operation */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTXY
value|0x314
end_define

begin_comment
comment|/* Font X/Y */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTW
value|0x318
end_define

begin_comment
comment|/* Font Width */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONTINC
value|0x31c
end_define

begin_comment
comment|/* Font Increment */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_FONT
value|0x320
end_define

begin_comment
comment|/* Font Data */
end_comment

begin_define
define|#
directive|define
name|FFB_FBC_UCSR
value|0x900
end_define

begin_comment
comment|/* User Control& Status */
end_comment

begin_define
define|#
directive|define
name|FBC_PPC_VCE_DIS
value|0x00001000
end_define

begin_define
define|#
directive|define
name|FBC_PPC_APE_DIS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FBC_PPC_TBE_OPAQUE
value|0x00000200
end_define

begin_define
define|#
directive|define
name|FBC_PPC_CS_CONST
value|0x00000003
end_define

begin_define
define|#
directive|define
name|FFB_FBC_WB_A
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_RB_A
value|0x00004000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_SB_BOTH
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FFB_FBC_XE_OFF
value|0x00000040
end_define

begin_define
define|#
directive|define
name|FFB_FBC_RGBE_MASK
value|0x0000003f
end_define

begin_define
define|#
directive|define
name|FBC_ROP_NEW
value|0x83
end_define

begin_define
define|#
directive|define
name|FBC_DRAWOP_RECTANGLE
value|0x08
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FIFO_OVFL
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_READ_ERR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_RP_BUSY
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FB_BUSY
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FBC_UCSR_FIFO_MASK
value|0x00000fff
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8R
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8G
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8B
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8X
value|0x00c00000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB32
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB64
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC_BM
value|0x04002000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8R
value|0x04004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8G
value|0x04404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8B
value|0x04804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB8X
value|0x04c04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB24
value|0x05004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB32
value|0x06004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422A
value|0x07004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422AD
value|0x07804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB24B
value|0x08004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422B
value|0x09004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DFB422BD
value|0x09804000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB16Z
value|0x0a004000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB8Z
value|0x0a404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB422
value|0x0ac04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_SFB422D
value|0x0b404000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_FBC_KREG
value|0x0bc04000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_DAC
value|0x0bc06000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_PROM
value|0x0bc08000
end_define

begin_define
define|#
directive|define
name|FFB_VIRT_EXP
value|0x0bc18000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8R
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8G
value|0x04400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8B
value|0x04800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8X
value|0x04c00000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB32
value|0x05000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB64
value|0x06000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC
value|0x00600000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC_BM
value|0x00600000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8R
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8G
value|0x01400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8B
value|0x01800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB8X
value|0x01c00000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB24
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB32
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422A
value|0x09000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422AD
value|0x09800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB24B
value|0x0a000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422B
value|0x0b000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DFB422BD
value|0x0b800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB16Z
value|0x0c800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB8Z
value|0x0c000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB422
value|0x0d000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_SFB422D
value|0x0d800000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_FBC_KREG
value|0x00610000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_DAC
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_PROM
value|0x00000000
end_define

begin_define
define|#
directive|define
name|FFB_PHYS_EXP
value|0x00200000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB8R
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB8G
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB8B
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB8X
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB32
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB64
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_FBC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_FBC_BM
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB8R
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB8G
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB8B
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB8X
value|0x00400000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB24
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB32
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB422A
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB422AD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB24B
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB422B
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DFB422BD
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB16Z
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB8Z
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB422
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_SFB422D
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_FBC_KREG
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_DAC
value|0x00002000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_PROM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|FFB_SIZE_EXP
value|0x00002000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_FB_CREATORREG_H_ */
end_comment

end_unit

