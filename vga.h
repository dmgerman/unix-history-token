begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Tycho Nightingale<tycho.nightingale@pluribusnetworks.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VGA_H_
end_ifndef

begin_define
define|#
directive|define
name|_VGA_H_
end_define

begin_define
define|#
directive|define
name|VGA_IOPORT_START
value|0x3c0
end_define

begin_define
define|#
directive|define
name|VGA_IOPORT_END
value|0x3df
end_define

begin_comment
comment|/* General registers */
end_comment

begin_define
define|#
directive|define
name|GEN_INPUT_STS0_PORT
value|0x3c2
end_define

begin_define
define|#
directive|define
name|GEN_FEATURE_CTRL_PORT
value|0x3ca
end_define

begin_define
define|#
directive|define
name|GEN_MISC_OUTPUT_PORT
value|0x3cc
end_define

begin_define
define|#
directive|define
name|GEN_INPUT_STS1_MONO_PORT
value|0x3ba
end_define

begin_define
define|#
directive|define
name|GEN_INPUT_STS1_COLOR_PORT
value|0x3da
end_define

begin_define
define|#
directive|define
name|GEN_IS1_VR
value|0x08
end_define

begin_comment
comment|/* Vertical retrace */
end_comment

begin_define
define|#
directive|define
name|GEN_IS1_DE
value|0x01
end_define

begin_comment
comment|/* Display enable not */
end_comment

begin_comment
comment|/* Attribute controller registers. */
end_comment

begin_define
define|#
directive|define
name|ATC_IDX_PORT
value|0x3c0
end_define

begin_define
define|#
directive|define
name|ATC_DATA_PORT
value|0x3c1
end_define

begin_define
define|#
directive|define
name|ATC_IDX_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|ATC_PALETTE0
value|0
end_define

begin_define
define|#
directive|define
name|ATC_PALETTE15
value|15
end_define

begin_define
define|#
directive|define
name|ATC_MODE_CONTROL
value|16
end_define

begin_define
define|#
directive|define
name|ATC_MC_IPS
value|0x80
end_define

begin_comment
comment|/* Internal palette size */
end_comment

begin_define
define|#
directive|define
name|ATC_MC_GA
value|0x01
end_define

begin_comment
comment|/* Graphics/alphanumeric */
end_comment

begin_define
define|#
directive|define
name|ATC_OVERSCAN_COLOR
value|17
end_define

begin_define
define|#
directive|define
name|ATC_COLOR_PLANE_ENABLE
value|18
end_define

begin_define
define|#
directive|define
name|ATC_HORIZ_PIXEL_PANNING
value|19
end_define

begin_define
define|#
directive|define
name|ATC_COLOR_SELECT
value|20
end_define

begin_define
define|#
directive|define
name|ATC_CS_C67
value|0x0c
end_define

begin_comment
comment|/* Color select bits 6+7 */
end_comment

begin_define
define|#
directive|define
name|ATC_CS_C45
value|0x03
end_define

begin_comment
comment|/* Color select bits 4+5 */
end_comment

begin_comment
comment|/* Sequencer registers. */
end_comment

begin_define
define|#
directive|define
name|SEQ_IDX_PORT
value|0x3c4
end_define

begin_define
define|#
directive|define
name|SEQ_DATA_PORT
value|0x3c5
end_define

begin_define
define|#
directive|define
name|SEQ_RESET
value|0
end_define

begin_define
define|#
directive|define
name|SEQ_RESET_ASYNC
value|0x1
end_define

begin_define
define|#
directive|define
name|SEQ_RESET_SYNC
value|0x2
end_define

begin_define
define|#
directive|define
name|SEQ_CLOCKING_MODE
value|1
end_define

begin_define
define|#
directive|define
name|SEQ_CM_SO
value|0x20
end_define

begin_comment
comment|/* Screen off */
end_comment

begin_define
define|#
directive|define
name|SEQ_CM_89
value|0x01
end_define

begin_comment
comment|/* 8/9 dot clock */
end_comment

begin_define
define|#
directive|define
name|SEQ_MAP_MASK
value|2
end_define

begin_define
define|#
directive|define
name|SEQ_CHAR_MAP_SELECT
value|3
end_define

begin_define
define|#
directive|define
name|SEQ_CMS_SAH
value|0x20
end_define

begin_comment
comment|/* Char map A bit 2 */
end_comment

begin_define
define|#
directive|define
name|SEQ_CMS_SAH_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|SEQ_CMS_SA
value|0x0c
end_define

begin_comment
comment|/* Char map A bits 0+1 */
end_comment

begin_define
define|#
directive|define
name|SEQ_CMS_SA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SEQ_CMS_SBH
value|0x10
end_define

begin_comment
comment|/* Char map B bit 2 */
end_comment

begin_define
define|#
directive|define
name|SEQ_CMS_SBH_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SEQ_CMS_SB
value|0x03
end_define

begin_comment
comment|/* Char map B bits 0+1 */
end_comment

begin_define
define|#
directive|define
name|SEQ_CMS_SB_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SEQ_MEMORY_MODE
value|4
end_define

begin_define
define|#
directive|define
name|SEQ_MM_C4
value|0x08
end_define

begin_comment
comment|/* Chain 4 */
end_comment

begin_define
define|#
directive|define
name|SEQ_MM_OE
value|0x04
end_define

begin_comment
comment|/* Odd/even */
end_comment

begin_define
define|#
directive|define
name|SEQ_MM_EM
value|0x02
end_define

begin_comment
comment|/* Extended memory */
end_comment

begin_comment
comment|/* Graphics controller registers. */
end_comment

begin_define
define|#
directive|define
name|GC_IDX_PORT
value|0x3ce
end_define

begin_define
define|#
directive|define
name|GC_DATA_PORT
value|0x3cf
end_define

begin_define
define|#
directive|define
name|GC_SET_RESET
value|0
end_define

begin_define
define|#
directive|define
name|GC_ENABLE_SET_RESET
value|1
end_define

begin_define
define|#
directive|define
name|GC_COLOR_COMPARE
value|2
end_define

begin_define
define|#
directive|define
name|GC_DATA_ROTATE
value|3
end_define

begin_define
define|#
directive|define
name|GC_READ_MAP_SELECT
value|4
end_define

begin_define
define|#
directive|define
name|GC_MODE
value|5
end_define

begin_define
define|#
directive|define
name|GC_MODE_OE
value|0x10
end_define

begin_comment
comment|/* Odd/even */
end_comment

begin_define
define|#
directive|define
name|GC_MODE_C4
value|0x04
end_define

begin_comment
comment|/* Chain 4 */
end_comment

begin_define
define|#
directive|define
name|GC_MISCELLANEOUS
value|6
end_define

begin_define
define|#
directive|define
name|GC_MISC_GM
value|0x01
end_define

begin_comment
comment|/* Graphics/alphanumeric */
end_comment

begin_define
define|#
directive|define
name|GC_MISC_MM
value|0x0c
end_define

begin_comment
comment|/* memory map */
end_comment

begin_define
define|#
directive|define
name|GC_MISC_MM_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|GC_COLOR_DONT_CARE
value|7
end_define

begin_define
define|#
directive|define
name|GC_BIT_MASK
value|8
end_define

begin_comment
comment|/* CRT controller registers. */
end_comment

begin_define
define|#
directive|define
name|CRTC_IDX_MONO_PORT
value|0x3b4
end_define

begin_define
define|#
directive|define
name|CRTC_DATA_MONO_PORT
value|0x3b5
end_define

begin_define
define|#
directive|define
name|CRTC_IDX_COLOR_PORT
value|0x3d4
end_define

begin_define
define|#
directive|define
name|CRTC_DATA_COLOR_PORT
value|0x3d5
end_define

begin_define
define|#
directive|define
name|CRTC_HORIZ_TOTAL
value|0
end_define

begin_define
define|#
directive|define
name|CRTC_HORIZ_DISP_END
value|1
end_define

begin_define
define|#
directive|define
name|CRTC_START_HORIZ_BLANK
value|2
end_define

begin_define
define|#
directive|define
name|CRTC_END_HORIZ_BLANK
value|3
end_define

begin_define
define|#
directive|define
name|CRTC_START_HORIZ_RETRACE
value|4
end_define

begin_define
define|#
directive|define
name|CRTC_END_HORIZ_RETRACE
value|5
end_define

begin_define
define|#
directive|define
name|CRTC_VERT_TOTAL
value|6
end_define

begin_define
define|#
directive|define
name|CRTC_OVERFLOW
value|7
end_define

begin_define
define|#
directive|define
name|CRTC_OF_VRS9
value|0x80
end_define

begin_comment
comment|/* VRS bit 9 */
end_comment

begin_define
define|#
directive|define
name|CRTC_OF_VRS9_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CRTC_OF_VDE9
value|0x40
end_define

begin_comment
comment|/* VDE bit 9 */
end_comment

begin_define
define|#
directive|define
name|CRTC_OF_VDE9_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|CRTC_OF_VRS8
value|0x04
end_define

begin_comment
comment|/* VRS bit 8 */
end_comment

begin_define
define|#
directive|define
name|CRTC_OF_VRS8_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|CRTC_OF_VDE8
value|0x02
end_define

begin_comment
comment|/* VDE bit 8 */
end_comment

begin_define
define|#
directive|define
name|CRTC_OF_VDE8_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|CRTC_PRESET_ROW_SCAN
value|8
end_define

begin_define
define|#
directive|define
name|CRTC_MAX_SCAN_LINE
value|9
end_define

begin_define
define|#
directive|define
name|CRTC_MSL_MSL
value|0x1f
end_define

begin_define
define|#
directive|define
name|CRTC_CURSOR_START
value|10
end_define

begin_define
define|#
directive|define
name|CRTC_CS_CO
value|0x20
end_define

begin_comment
comment|/* Cursor off */
end_comment

begin_define
define|#
directive|define
name|CRTC_CS_CS
value|0x1f
end_define

begin_comment
comment|/* Cursor start */
end_comment

begin_define
define|#
directive|define
name|CRTC_CURSOR_END
value|11
end_define

begin_define
define|#
directive|define
name|CRTC_CE_CE
value|0x1f
end_define

begin_comment
comment|/* Cursor end */
end_comment

begin_define
define|#
directive|define
name|CRTC_START_ADDR_HIGH
value|12
end_define

begin_define
define|#
directive|define
name|CRTC_START_ADDR_LOW
value|13
end_define

begin_define
define|#
directive|define
name|CRTC_CURSOR_LOC_HIGH
value|14
end_define

begin_define
define|#
directive|define
name|CRTC_CURSOR_LOC_LOW
value|15
end_define

begin_define
define|#
directive|define
name|CRTC_VERT_RETRACE_START
value|16
end_define

begin_define
define|#
directive|define
name|CRTC_VERT_RETRACE_END
value|17
end_define

begin_define
define|#
directive|define
name|CRTC_VRE_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|CRTC_VERT_DISP_END
value|18
end_define

begin_define
define|#
directive|define
name|CRTC_OFFSET
value|19
end_define

begin_define
define|#
directive|define
name|CRTC_UNDERLINE_LOC
value|20
end_define

begin_define
define|#
directive|define
name|CRTC_START_VERT_BLANK
value|21
end_define

begin_define
define|#
directive|define
name|CRTC_END_VERT_BLANK
value|22
end_define

begin_define
define|#
directive|define
name|CRTC_MODE_CONTROL
value|23
end_define

begin_define
define|#
directive|define
name|CRTC_MC_TE
value|0x80
end_define

begin_comment
comment|/* Timing enable */
end_comment

begin_define
define|#
directive|define
name|CRTC_LINE_COMPARE
value|24
end_define

begin_comment
comment|/* DAC registers */
end_comment

begin_define
define|#
directive|define
name|DAC_MASK
value|0x3c6
end_define

begin_define
define|#
directive|define
name|DAC_IDX_RD_PORT
value|0x3c7
end_define

begin_define
define|#
directive|define
name|DAC_IDX_WR_PORT
value|0x3c8
end_define

begin_define
define|#
directive|define
name|DAC_DATA_PORT
value|0x3c9
end_define

begin_function_decl
name|void
modifier|*
name|vga_init
parameter_list|(
name|int
name|io_only
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VGA_H_ */
end_comment

end_unit

