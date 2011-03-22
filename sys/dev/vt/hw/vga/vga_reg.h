begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VT_HW_VGA_VGA_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VT_HW_VGA_VGA_REG_H_
end_define

begin_comment
comment|/*  * The VGA adapter uses two I/O port blocks. One of these blocks, the CRT  * controller registers, can be located either at 0x3B0 or at 0x3D0 in I/O  * port space. This allows compatibility with the monochrome adapter, which  * has the CRT controller registers at 0x3B0.  *  * It is assumed that compatibility with the monochrome adapter is not of  * interest anymore. As such, the CRT controller can be located at 0x3D0 in  * I/O port space unconditionally. This means that the 2 I/O blocks are  * always adjacent and can therefore be treated as a single logical I/O port  * range. In practical terms: there only has to be a single tag and handle  * to access all registers.  *  * The following definitions are taken from or inspired by:  *   Programmer's Guide to the EGA, VGA, and Super VGA Cards -- 3rd ed.,  *     Richard F. Ferraro, Addison-Wesley, ISBN 0-201-62490-7  */
end_comment

begin_define
define|#
directive|define
name|VGA_MEM_BASE
value|0xA0000
end_define

begin_define
define|#
directive|define
name|VGA_MEM_SIZE
value|0x10000
end_define

begin_define
define|#
directive|define
name|VGA_REG_BASE
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_REG_SIZE
value|0x10+0x0c
end_define

begin_comment
comment|/* Attribute controller registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_WRITE
value|0x00
end_define

begin_define
define|#
directive|define
name|VGA_AC_READ
value|0x01
end_define

begin_define
define|#
directive|define
name|VGA_AC_PALETTE
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_comment
comment|/* 0<= x<= 15 */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_SR
value|0x20
end_define

begin_comment
comment|/* Secondary red */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_SG
value|0x10
end_define

begin_comment
comment|/* Secondary green */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_SB
value|0x08
end_define

begin_comment
comment|/* Secondary blue */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_R
value|0x04
end_define

begin_comment
comment|/* Red */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_G
value|0x02
end_define

begin_comment
comment|/* Green */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_PAL_B
value|0x01
end_define

begin_comment
comment|/* Blue */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MODE_CONTROL
value|(32+16)
end_define

begin_define
define|#
directive|define
name|VGA_AC_MC_IPS
value|0x80
end_define

begin_comment
comment|/* Internal palette size */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_PCS
value|0x40
end_define

begin_comment
comment|/* Pixel clock select */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_PPC
value|0x20
end_define

begin_comment
comment|/* Pixel panning compat. */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_BI
value|0x08
end_define

begin_comment
comment|/* Blink/intensity */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_ELG
value|0x04
end_define

begin_comment
comment|/* Enable line graphics cc. */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_DT
value|0x02
end_define

begin_comment
comment|/* Display type */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_MC_GA
value|0x01
end_define

begin_comment
comment|/* Graphics/alphanumeric */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_OVERSCAN_COLOR
value|(32+17)
end_define

begin_define
define|#
directive|define
name|VGA_AC_COLOR_PLANE_ENABLE
value|(32+18)
end_define

begin_define
define|#
directive|define
name|VGA_AC_HORIZ_PIXEL_PANNING
value|(32+19)
end_define

begin_define
define|#
directive|define
name|VGA_AC_COLOR_SELECT
value|(32+20)
end_define

begin_define
define|#
directive|define
name|VGA_AC_CS_C67
value|0x0C
end_define

begin_comment
comment|/* Color reg. addr. bits 6+7 */
end_comment

begin_define
define|#
directive|define
name|VGA_AC_CS_C45
value|0x03
end_define

begin_comment
comment|/* Color reg. addr. bits 4+5 */
end_comment

begin_comment
comment|/* General registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MISC_OUTPUT_W
value|0x02
end_define

begin_comment
comment|/* Write only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MISC_OUTPUT_R
value|0x0c
end_define

begin_comment
comment|/* Read only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_VSP
value|0x80
end_define

begin_comment
comment|/* Vertical sync. polarity */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_HSP
value|0x40
end_define

begin_comment
comment|/* Horiz. sync. polarity */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_PB
value|0x20
end_define

begin_comment
comment|/* Page bit for odd/even */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_CS
value|0x0C
end_define

begin_comment
comment|/* Clock select */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_ER
value|0x02
end_define

begin_comment
comment|/* Enable RAM */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_MO_IOA
value|0x01
end_define

begin_comment
comment|/* Input/output address */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_INPUT_STAT_0
value|0x02
end_define

begin_comment
comment|/* Read only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_FEATURE_CTRL_W
value|0x1a
end_define

begin_comment
comment|/* Write only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_FEATURE_CTRL_R
value|0x0a
end_define

begin_comment
comment|/* Read only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_INPUT_STAT_1
value|0x1a
end_define

begin_comment
comment|/* Read only. */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_IS1_VR
value|0x08
end_define

begin_comment
comment|/* Vertical retrace */
end_comment

begin_define
define|#
directive|define
name|VGA_GEN_IS1_DE
value|0x01
end_define

begin_comment
comment|/* Display enable not */
end_comment

begin_comment
comment|/* Sequencer registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_ADDRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_RESET
value|0
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_RST_SR
value|0x02
end_define

begin_comment
comment|/* Synchronous reset */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_RST_NAR
value|0x01
end_define

begin_comment
comment|/* No async. reset */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CLOCKING_MODE
value|1
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_CM_SO
value|0x20
end_define

begin_comment
comment|/* Screen off */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CM_S4
value|0x10
end_define

begin_comment
comment|/* Shift four */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CM_DC
value|0x08
end_define

begin_comment
comment|/* Dot clock */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CM_SL
value|0x04
end_define

begin_comment
comment|/* Shift load */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CM_89
value|0x01
end_define

begin_comment
comment|/* 8/9 Dot clocks */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MAP_MASK
value|2
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_MM_EM3
value|0x08
end_define

begin_comment
comment|/* Enable memory plane 3 */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MM_EM2
value|0x04
end_define

begin_comment
comment|/* Enable memory plane 2 */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MM_EM1
value|0x02
end_define

begin_comment
comment|/* Enable memory plane 1 */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MM_EM0
value|0x01
end_define

begin_comment
comment|/* Enable memory plane 0 */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CHAR_MAP_SELECT
value|3
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_CMS_SAH
value|0x20
end_define

begin_comment
comment|/* Char. A (bit 2) */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CMS_SBH
value|0x10
end_define

begin_comment
comment|/* Char. B (bit 2) */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CMS_SA
value|0x0C
end_define

begin_comment
comment|/* Char. A (bit 0+1) */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_CMS_SB
value|0x03
end_define

begin_comment
comment|/* Char. B (bit 0+1) */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MEMORY_MODE
value|4
end_define

begin_define
define|#
directive|define
name|VGA_SEQ_MM_C4
value|0x08
end_define

begin_comment
comment|/* Chain four */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MM_OE
value|0x04
end_define

begin_comment
comment|/* Odd/even */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_MM_EM
value|0x02
end_define

begin_comment
comment|/* Extended memory */
end_comment

begin_define
define|#
directive|define
name|VGA_SEQ_DATA
value|0x05
end_define

begin_comment
comment|/* Color registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_PEL_MASK
value|0x06
end_define

begin_define
define|#
directive|define
name|VGA_PEL_ADDR_RD_MODE
value|0x07
end_define

begin_comment
comment|/* Write only. */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_STATE
value|0x07
end_define

begin_comment
comment|/* Read only. */
end_comment

begin_define
define|#
directive|define
name|VGA_PEL_ADDR_WR_MODE
value|0x08
end_define

begin_define
define|#
directive|define
name|VGA_PEL_DATA
value|0x09
end_define

begin_comment
comment|/* Graphics controller registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_ADDRESS
value|0x0e
end_define

begin_define
define|#
directive|define
name|VGA_GC_SET_RESET
value|0
end_define

begin_define
define|#
directive|define
name|VGA_GC_ENABLE_SET_RESET
value|1
end_define

begin_define
define|#
directive|define
name|VGA_GC_COLOR_COMPARE
value|2
end_define

begin_define
define|#
directive|define
name|VGA_GC_DATA_ROTATE
value|3
end_define

begin_define
define|#
directive|define
name|VGA_GC_DR_FS_XOR
value|0x18
end_define

begin_comment
comment|/* Function select - XOR */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_DR_FS_OR
value|0x10
end_define

begin_comment
comment|/* Function select - OR */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_DR_FS_AND
value|0x08
end_define

begin_comment
comment|/* Function select - AND */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_DR_RC
value|0x07
end_define

begin_comment
comment|/* Rotate count */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_READ_MAP_SELECT
value|4
end_define

begin_define
define|#
directive|define
name|VGA_GC_MODE
value|5
end_define

begin_define
define|#
directive|define
name|VGA_GC_MODE_SR
value|0x60
end_define

begin_comment
comment|/* Shift register */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MODE_OE
value|0x10
end_define

begin_comment
comment|/* Odd/even */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MODE_RM
value|0x08
end_define

begin_comment
comment|/* Read mode */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MODE_WM
value|0x03
end_define

begin_comment
comment|/* Write mode */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MISCELLANEOUS
value|6
end_define

begin_define
define|#
directive|define
name|VGA_GC_MISC_MM
value|0x0C
end_define

begin_comment
comment|/* memory map */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MISC_COE
value|0x02
end_define

begin_comment
comment|/* Chain odd/even */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_MISC_GA
value|0x01
end_define

begin_comment
comment|/* Graphics/text mode */
end_comment

begin_define
define|#
directive|define
name|VGA_GC_COLOR_DONT_CARE
value|7
end_define

begin_define
define|#
directive|define
name|VGA_GC_BIT_MASK
value|8
end_define

begin_define
define|#
directive|define
name|VGA_GC_DATA
value|0x0f
end_define

begin_comment
comment|/* CRT controller registers. */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_ADDRESS
value|0x14
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_HORIZ_TOTAL
value|0
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_HORIZ_DISP_END
value|1
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_START_HORIZ_BLANK
value|2
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_END_HORIZ_BLANK
value|3
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_EHB_CR
value|0x80
end_define

begin_comment
comment|/* Compatible read */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_EHB_DES
value|0x60
end_define

begin_comment
comment|/* Display enable skew */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_EHB_EHB
value|0x1F
end_define

begin_comment
comment|/* End horizontal blank */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_START_HORIZ_RETRACE
value|4
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_END_HORIZ_RETRACE
value|5
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_EHR_EHB
value|0x80
end_define

begin_comment
comment|/* End horizontal blanking */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_EHR_HRD
value|0x60
end_define

begin_comment
comment|/* Horizontal retrace delay */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_EHR_EHR
value|0x1F
end_define

begin_comment
comment|/* End horizontal retrace */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_VERT_TOTAL
value|6
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_OVERFLOW
value|7
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VRS9
value|0x80
end_define

begin_comment
comment|/* Vertical retrace start */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VDE9
value|0x40
end_define

begin_comment
comment|/* Vertical disp. enable end */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VT9
value|0x20
end_define

begin_comment
comment|/* Vertical total (bit 9) */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_LC8
value|0x10
end_define

begin_comment
comment|/* Line compare */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VBS8
value|0x08
end_define

begin_comment
comment|/* Start vertical blanking */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VRS8
value|0x04
end_define

begin_comment
comment|/* Vertical retrace start */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VDE8
value|0x02
end_define

begin_comment
comment|/* Vertical disp. enable end */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_OF_VT8
value|0x01
end_define

begin_comment
comment|/* Vertical total (bit 8) */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_PRESET_ROW_SCAN
value|8
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_PRS_BP
value|0x60
end_define

begin_comment
comment|/* Byte panning */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_PRS_PRS
value|0x1F
end_define

begin_comment
comment|/* Preset row scan */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MAX_SCAN_LINE
value|9
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_MSL_2T4
value|0x80
end_define

begin_comment
comment|/* 200-to-400 line conversion */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MSL_LC9
value|0x40
end_define

begin_comment
comment|/* Line compare (bit 9) */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MSL_VBS9
value|0x20
end_define

begin_comment
comment|/* Start vertical blanking */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MSL_MSL
value|0x1F
end_define

begin_comment
comment|/* Maximum scan line */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_CURSOR_START
value|10
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_CS_COO
value|0x20
end_define

begin_comment
comment|/* Cursor on/off */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_CS_CS
value|0x1F
end_define

begin_comment
comment|/* Cursor start */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_CURSOR_END
value|11
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_CE_CSK
value|0x60
end_define

begin_comment
comment|/* Cursor skew */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_CE_CE
value|0x1F
end_define

begin_comment
comment|/* Cursor end */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_START_ADDR_HIGH
value|12
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_START_ADDR_LOW
value|13
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_CURSOR_LOC_HIGH
value|14
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_CURSOR_LOC_LOW
value|15
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_VERT_RETRACE_START
value|16
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_VERT_RETRACE_END
value|17
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_VRE_PR
value|0x80
end_define

begin_comment
comment|/* Protect register 0-7 */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_VRE_BW
value|0x40
end_define

begin_comment
comment|/* Bandwidth */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_VRE_VRE
value|0x1F
end_define

begin_comment
comment|/* Vertical retrace end */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_VERT_DISPLAY_END
value|18
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_OFFSET
value|19
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_UNDERLINE_LOC
value|20
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_UL_DW
value|0x40
end_define

begin_comment
comment|/* Double word mode */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_UL_CB4
value|0x20
end_define

begin_comment
comment|/* Count by four */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_UL_UL
value|0x1F
end_define

begin_comment
comment|/* Underline location */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_START_VERT_BLANK
value|21
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_END_VERT_BLANK
value|22
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_MODE_CONTROL
value|23
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_MC_HR
value|0x80
end_define

begin_comment
comment|/* hardware reset */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_WB
value|0x40
end_define

begin_comment
comment|/* Word/byte mode */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_AW
value|0x20
end_define

begin_comment
comment|/* Address wrap */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_CBT
value|0x08
end_define

begin_comment
comment|/* Count by two */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_HRS
value|0x04
end_define

begin_comment
comment|/* Horizontal retrace select */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_SRS
value|0x02
end_define

begin_comment
comment|/* Select row scan counter */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_MC_CMS
value|0x01
end_define

begin_comment
comment|/* Compatibility mode support */
end_comment

begin_define
define|#
directive|define
name|VGA_CRTC_LINE_COMPARE
value|24
end_define

begin_define
define|#
directive|define
name|VGA_CRTC_DATA
value|0x15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DEV_VT_HW_VGA_VGA_REG_H_ */
end_comment

end_unit

