begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI video.h,v 2.2 1996/04/08 19:33:12 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * The VGA CRT Controller  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|VGA_CRTC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CRTC registers        We use the VGA register functions and don't care about the MDA. We also    leave out the undocumented registers at 0x22, 0x24, 0x3?. */
end_comment

begin_define
define|#
directive|define
name|CRTC_HorzTotal
value|0x00
end_define

begin_define
define|#
directive|define
name|CRTC_HorzDispEnd
value|0x01
end_define

begin_define
define|#
directive|define
name|CRTC_StartHorzBlank
value|0x02
end_define

begin_define
define|#
directive|define
name|CRTC_EndHorzBlank
value|0x03
end_define

begin_define
define|#
directive|define
name|CRTC_StartHorzRetrace
value|0x04
end_define

begin_define
define|#
directive|define
name|CRTC_EndHorzRetrace
value|0x05
end_define

begin_define
define|#
directive|define
name|CRTC_VertTotal
value|0x06
end_define

begin_define
define|#
directive|define
name|CRTC_Overflow
value|0x07
end_define

begin_define
define|#
directive|define
name|CRTC_ResetRowScan
value|0x08
end_define

begin_define
define|#
directive|define
name|CRTC_MaxScanLine
value|0x09
end_define

begin_define
define|#
directive|define
name|CRTC_CursStart
value|0x0a
end_define

begin_define
define|#
directive|define
name|CRTC_CursEnd
value|0x0b
end_define

begin_define
define|#
directive|define
name|CRTC_StartAddrHi
value|0x0c
end_define

begin_define
define|#
directive|define
name|CRTC_StartAddrLo
value|0x0d
end_define

begin_define
define|#
directive|define
name|CRTC_CurLocHi
value|0x0e
end_define

begin_define
define|#
directive|define
name|CRTC_CurLocLo
value|0x0f
end_define

begin_define
define|#
directive|define
name|CRTC_StartVertRetrace
value|0x10
end_define

begin_define
define|#
directive|define
name|CRTC_EndVertRetrace
value|0x11
end_define

begin_define
define|#
directive|define
name|CRTC_VertDispEnd
value|0x12
end_define

begin_define
define|#
directive|define
name|CRTC_Offset
value|0x13
end_define

begin_define
define|#
directive|define
name|CRTC_UnderlineLoc
value|0x14
end_define

begin_define
define|#
directive|define
name|CRTC_StartVertBlank
value|0x15
end_define

begin_define
define|#
directive|define
name|CRTC_EndVertBlank
value|0x16
end_define

begin_define
define|#
directive|define
name|CRTC_ModeCtrl
value|0x17
end_define

begin_define
define|#
directive|define
name|CRTC_LineCompare
value|0x18
end_define

begin_define
define|#
directive|define
name|CRTC_Size
value|0x19
end_define

begin_comment
comment|/* Port addresses for the CRTC     The registers are read by    	OUT index_port, reg_nr 	IN  data_port, res     They are written by    	OUT index_port, reg_nr 	OUT data_port, value */
end_comment

begin_define
define|#
directive|define
name|CRTC_IndexPortColor
value|0x03d4
end_define

begin_comment
comment|/* CRTC Address Register (Color) */
end_comment

begin_define
define|#
directive|define
name|CRTC_DataPortColor
value|0x03d5
end_define

begin_comment
comment|/* CRTC Data Register (Color) */
end_comment

begin_define
define|#
directive|define
name|CRTC_IndexPortMono
value|0x03b4
end_define

begin_comment
comment|/* CRTC Address Register (Mono) */
end_comment

begin_define
define|#
directive|define
name|CRTC_DataPortMono
value|0x03b5
end_define

begin_comment
comment|/* CRTC Data Register (Mono) */
end_comment

begin_comment
comment|/*  * VGA Attribute Controller  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|VGA_ATC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ATC registers     The palette registers are here for completeness. We'll always use a    separate array 'palette[]' to access them in our code. */
end_comment

begin_define
define|#
directive|define
name|ATC_Palette0
value|0x00
end_define

begin_define
define|#
directive|define
name|ATC_Palette1
value|0x01
end_define

begin_define
define|#
directive|define
name|ATC_Palette2
value|0x02
end_define

begin_define
define|#
directive|define
name|ATC_Palette3
value|0x03
end_define

begin_define
define|#
directive|define
name|ATC_Palette4
value|0x04
end_define

begin_define
define|#
directive|define
name|ATC_Palette5
value|0x05
end_define

begin_define
define|#
directive|define
name|ATC_Palette6
value|0x06
end_define

begin_define
define|#
directive|define
name|ATC_Palette7
value|0x07
end_define

begin_define
define|#
directive|define
name|ATC_Palette8
value|0x08
end_define

begin_define
define|#
directive|define
name|ATC_Palette9
value|0x09
end_define

begin_define
define|#
directive|define
name|ATC_PaletteA
value|0x0a
end_define

begin_define
define|#
directive|define
name|ATC_PaletteB
value|0x0b
end_define

begin_define
define|#
directive|define
name|ATC_PaletteC
value|0x0c
end_define

begin_define
define|#
directive|define
name|ATC_PaletteD
value|0x0d
end_define

begin_define
define|#
directive|define
name|ATC_PaletteE
value|0x0e
end_define

begin_define
define|#
directive|define
name|ATC_PaletteF
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATC_ModeCtrl
value|0x10
end_define

begin_define
define|#
directive|define
name|ATC_OverscanColor
value|0x11
end_define

begin_define
define|#
directive|define
name|ATC_ColorPlaneEnable
value|0x12
end_define

begin_define
define|#
directive|define
name|ATC_HorzPixelPanning
value|0x13
end_define

begin_define
define|#
directive|define
name|ATC_ColorSelect
value|0x14
end_define

begin_define
define|#
directive|define
name|ATC_Size
value|0x15
end_define

begin_comment
comment|/* Port addresses for the ATC     The ATC has a combined index/data port at 0x03c0. To quote from Ralf    Brown's ports list: ``Every write access to this register will toggle an    internal index/data selection flipflop, so that consecutive writes to index& data is possible through this port. To get a defined start condition,    each read access to the input status register #1 (3BAh in mono / 3DAh in    color) resets the flipflop to load index.'' */
end_comment

begin_define
define|#
directive|define
name|ATC_WritePort
value|0x03c0
end_define

begin_define
define|#
directive|define
name|ATC_ReadPort
value|0x03c1
end_define

begin_comment
comment|/*  * VGA Sequencer Controller  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|VGA_TSC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* TSC registers     We leave out the undocumented register at 0x07. */
end_comment

begin_define
define|#
directive|define
name|TSC_Reset
value|0x00
end_define

begin_define
define|#
directive|define
name|TSC_ClockingMode
value|0x01
end_define

begin_define
define|#
directive|define
name|TSC_MapMask
value|0x02
end_define

begin_define
define|#
directive|define
name|TSC_CharMapSelect
value|0x03
end_define

begin_define
define|#
directive|define
name|TSC_MemoryMode
value|0x04
end_define

begin_define
define|#
directive|define
name|TSC_Size
value|0x05
end_define

begin_comment
comment|/* Port addresses for the TSC */
end_comment

begin_define
define|#
directive|define
name|TSC_IndexPort
value|0x03c4
end_define

begin_define
define|#
directive|define
name|TSC_DataPort
value|0x03c5
end_define

begin_comment
comment|/*  * VGA Graphics Controller  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|VGA_GDC
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* GDC registers */
end_comment

begin_define
define|#
directive|define
name|GDC_SetReset
value|0x00
end_define

begin_define
define|#
directive|define
name|GDC_EnableSetReset
value|0x01
end_define

begin_define
define|#
directive|define
name|GDC_ColorCompare
value|0x02
end_define

begin_define
define|#
directive|define
name|GDC_DataRotate
value|0x03
end_define

begin_define
define|#
directive|define
name|GDC_ReadMapSelect
value|0x04
end_define

begin_define
define|#
directive|define
name|GDC_Mode
value|0x05
end_define

begin_define
define|#
directive|define
name|GDC_Misc
value|0x06
end_define

begin_define
define|#
directive|define
name|GDC_ColorDontCare
value|0x07
end_define

begin_define
define|#
directive|define
name|GDC_BitMask
value|0x08
end_define

begin_define
define|#
directive|define
name|GDC_Size
value|0x09
end_define

begin_comment
comment|/* Port addresses for the GDC */
end_comment

begin_define
define|#
directive|define
name|GDC_IndexPort
value|0x03ce
end_define

begin_define
define|#
directive|define
name|GDC_DataPort
value|0x03cf
end_define

begin_comment
comment|/*  * Miscellaneous VGA registers  */
end_comment

begin_decl_stmt
name|u_int8_t
name|VGA_InputStatus0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_InputStatus1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_MiscOutput
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_DAC_PELData
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_DAC_PELMask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_DAC_PELReadAddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_DAC_PELWriteAddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
name|VGA_DAC_State
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Port addresses for miscellaneous VGA registers */
end_comment

begin_define
define|#
directive|define
name|VGA_InputStatus0Port
value|0x03c2
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_define
define|#
directive|define
name|VGA_InputStatus1Port
value|0x03da
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_define
define|#
directive|define
name|VGA_MiscOutputPortW
value|0x03c2
end_define

begin_comment
comment|/* Write-only */
end_comment

begin_define
define|#
directive|define
name|VGA_MiscOutputPortR
value|0x03cc
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_comment
comment|/* Port addresses for VGA DAC registers */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_PELDataPort
value|0x03c9
end_define

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_PELMaskPort
value|0x03c6
end_define

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_PELReadAddrPort
value|0x03c7
end_define

begin_comment
comment|/* Write-only */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_PELWriteAddrPort
value|0x03c8
end_define

begin_comment
comment|/* Read/Write */
end_comment

begin_define
define|#
directive|define
name|VGA_DAC_StatePortOut
value|0x03c7
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_comment
comment|/*  * Additional variables and type definitions  */
end_comment

begin_comment
comment|/* To ease access to the palette registers, 'palette[]' will overlay the    Attribute Controller space. */
end_comment

begin_decl_stmt
name|u_int8_t
modifier|*
name|palette
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Entry type for the DAC table. Each value is actually 6 bits wide. */
end_comment

begin_struct
struct|struct
name|dac_colors
block|{
name|u_int8_t
name|red
decl_stmt|;
name|u_int8_t
name|green
decl_stmt|;
name|u_int8_t
name|blue
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* We need a working copy of the default DAC table. This is filled from    'dac_default{64,256}[]' in 'video.c:init_vga()'. */
end_comment

begin_decl_stmt
name|struct
name|dac_colors
modifier|*
name|dac_rgb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Video memory  *  * The video memory of a standard VGA card is 256K. For the standard modes,  * this is divided into four planes of 64K which are accessed according to the  * GDC state. Mode 0x13 will also fit within 64K. The higher resolution modes  * (VESA) require a bit more sophistication; we leave that for later  * implementation.  */
end_comment

begin_comment
comment|/* Video RAM */
end_comment

begin_decl_stmt
name|u_int8_t
modifier|*
name|vram
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointers to the four bit planes */
end_comment

begin_decl_stmt
name|u_int8_t
modifier|*
name|vplane0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
modifier|*
name|vplane1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
modifier|*
name|vplane2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_int8_t
modifier|*
name|vplane3
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the video memory. The base address varies with the video mode.    'vmem' is used directly only in the text modes; in the graphics modes, all    writes go to 'vram'. */
end_comment

begin_decl_stmt
name|u_int16_t
modifier|*
name|vmem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * VGA status information  *  * Int 10:1b returns a 64 byte block of status info for the VGA card. This  * block also contains a couple of BIOS variables, so we will use it for  * general housekeeping.  */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|vga_status
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Access to the VGA status fields. */
end_comment

begin_define
define|#
directive|define
name|StaticFuncTbl
value|*(u_int32_t *)&vga_status[0]
end_define

begin_define
define|#
directive|define
name|VideoMode
value|*(u_int8_t *)&vga_status[4]
end_define

begin_define
define|#
directive|define
name|DpyCols
value|*(u_int16_t *)&vga_status[5]
end_define

begin_define
define|#
directive|define
name|DpyPageSize
value|*(u_int16_t *)&vga_status[7]
end_define

begin_define
define|#
directive|define
name|ActivePageOfs
value|*(u_int16_t *)&vga_status[9]
end_define

begin_define
define|#
directive|define
name|CursCol0
value|*(u_int8_t *)&vga_status[11]
end_define

begin_define
define|#
directive|define
name|CursRow0
value|*(u_int8_t *)&vga_status[12]
end_define

begin_define
define|#
directive|define
name|CursCol1
value|*(u_int8_t *)&vga_status[13]
end_define

begin_define
define|#
directive|define
name|CursRow1
value|*(u_int8_t *)&vga_status[14]
end_define

begin_define
define|#
directive|define
name|CursCol2
value|*(u_int8_t *)&vga_status[15]
end_define

begin_define
define|#
directive|define
name|CursRow2
value|*(u_int8_t *)&vga_status[16]
end_define

begin_define
define|#
directive|define
name|CursCol3
value|*(u_int8_t *)&vga_status[17]
end_define

begin_define
define|#
directive|define
name|CursRow3
value|*(u_int8_t *)&vga_status[18]
end_define

begin_define
define|#
directive|define
name|CursCol4
value|*(u_int8_t *)&vga_status[19]
end_define

begin_define
define|#
directive|define
name|CursRow4
value|*(u_int8_t *)&vga_status[20]
end_define

begin_define
define|#
directive|define
name|CursCol5
value|*(u_int8_t *)&vga_status[21]
end_define

begin_define
define|#
directive|define
name|CursRow5
value|*(u_int8_t *)&vga_status[22]
end_define

begin_define
define|#
directive|define
name|CursCol6
value|*(u_int8_t *)&vga_status[23]
end_define

begin_define
define|#
directive|define
name|CursRow6
value|*(u_int8_t *)&vga_status[24]
end_define

begin_define
define|#
directive|define
name|CursCol7
value|*(u_int8_t *)&vga_status[25]
end_define

begin_define
define|#
directive|define
name|CursRow7
value|*(u_int8_t *)&vga_status[26]
end_define

begin_define
define|#
directive|define
name|CursStart
value|*(u_int8_t *)&vga_status[27]
end_define

begin_define
define|#
directive|define
name|CursEnd
value|*(u_int8_t *)&vga_status[28]
end_define

begin_define
define|#
directive|define
name|ActivePage
value|*(u_int8_t *)&vga_status[29]
end_define

begin_define
define|#
directive|define
name|CRTCPort
value|*(u_int16_t *)&vga_status[30]
end_define

begin_define
define|#
directive|define
name|CGA_ModeCtrl
value|*(u_int8_t *)&vga_status[32]
end_define

begin_define
define|#
directive|define
name|CGA_ColorSelect
value|*(u_int8_t *)&vga_status[33]
end_define

begin_define
define|#
directive|define
name|DpyRows
value|*(u_int8_t *)&vga_status[34]
end_define

begin_define
define|#
directive|define
name|CharHeight
value|*(u_int16_t *)&vga_status[35]
end_define

begin_define
define|#
directive|define
name|ActiveDCC
value|*(u_int8_t *)&vga_status[37]
end_define

begin_define
define|#
directive|define
name|SecondDCC
value|*(u_int8_t *)&vga_status[38]
end_define

begin_define
define|#
directive|define
name|NumColors
value|*(u_int16_t *)&vga_status[39]
end_define

begin_define
define|#
directive|define
name|NumPages
value|*(u_int8_t *)&vga_status[41]
end_define

begin_define
define|#
directive|define
name|VertResolution
value|*(u_int8_t *)&vga_status[42]
end_define

begin_define
define|#
directive|define
name|PrimaryCharset
value|*(u_int8_t *)&vga_status[43]
end_define

begin_define
define|#
directive|define
name|SecondaryCharset
value|*(u_int8_t *)&vga_status[44]
end_define

begin_define
define|#
directive|define
name|MiscStatus
value|*(u_int8_t *)&vga_status[45]
end_define

begin_comment
comment|/* #define Reserved1		*(u_int16_t *)&vga_status[46] #define Reserved2		*(u_int8_t *)&vga_status[48] */
end_comment

begin_define
define|#
directive|define
name|VMemSize
value|*(u_int8_t *)&vga_status[49]
end_define

begin_define
define|#
directive|define
name|SavePointerStatus
value|*(u_int8_t *)&vga_status[50]
end_define

begin_comment
comment|/* VGA Static Functionality Table     This table contains mode-independent VGA status information. It is actually    defined in 'vparam.h'; the declaration here is just for completeness. */
end_comment

begin_decl_stmt
specifier|extern
name|u_int8_t
name|static_functionality_tbl
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add some names for the VGA related BIOS variables. */
end_comment

begin_define
define|#
directive|define
name|BIOS_VideoMode
value|*(u_int8_t *)&BIOSDATA[0x49]
end_define

begin_define
define|#
directive|define
name|BIOS_DpyCols
value|*(u_int16_t *)&BIOSDATA[0x4a]
end_define

begin_define
define|#
directive|define
name|BIOS_DpyPageSize
value|*(u_int16_t *)&BIOSDATA[0x4c]
end_define

begin_define
define|#
directive|define
name|BIOS_ActivePageOfs
value|*(u_int16_t *)&BIOSDATA[0x4e]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol0
value|*(u_int8_t *)&BIOSDATA[0x50]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow0
value|*(u_int8_t *)&BIOSDATA[0x51]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol1
value|*(u_int8_t *)&BIOSDATA[0x52]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow1
value|*(u_int8_t *)&BIOSDATA[0x53]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol2
value|*(u_int8_t *)&BIOSDATA[0x54]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow2
value|*(u_int8_t *)&BIOSDATA[0x55]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol3
value|*(u_int8_t *)&BIOSDATA[0x56]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow3
value|*(u_int8_t *)&BIOSDATA[0x57]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol4
value|*(u_int8_t *)&BIOSDATA[0x58]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow4
value|*(u_int8_t *)&BIOSDATA[0x59]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol5
value|*(u_int8_t *)&BIOSDATA[0x5a]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow5
value|*(u_int8_t *)&BIOSDATA[0x5b]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol6
value|*(u_int8_t *)&BIOSDATA[0x5c]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow6
value|*(u_int8_t *)&BIOSDATA[0x5d]
end_define

begin_define
define|#
directive|define
name|BIOS_CursCol7
value|*(u_int8_t *)&BIOSDATA[0x5e]
end_define

begin_define
define|#
directive|define
name|BIOS_CursRow7
value|*(u_int8_t *)&BIOSDATA[0x5f]
end_define

begin_define
define|#
directive|define
name|BIOS_CursStart
value|*(u_int8_t *)&BIOSDATA[0x60]
end_define

begin_define
define|#
directive|define
name|BIOS_CursEnd
value|*(u_int8_t *)&BIOSDATA[0x61]
end_define

begin_define
define|#
directive|define
name|BIOS_ActivePage
value|*(u_int8_t *)&BIOSDATA[0x62]
end_define

begin_define
define|#
directive|define
name|BIOS_CRTCPort
value|*(u_int16_t *)&BIOSDATA[0x63]
end_define

begin_define
define|#
directive|define
name|BIOS_CGA_ModeCtrl
value|*(u_int8_t *)&BIOSDATA[0x65]
end_define

begin_define
define|#
directive|define
name|BIOS_CGA_ColorSelect
value|*(u_int8_t *)&BIOSDATA[0x66]
end_define

begin_define
define|#
directive|define
name|BIOS_DpyRows
value|*(u_int8_t *)&BIOSDATA[0x84]
end_define

begin_define
define|#
directive|define
name|BIOS_CharHeight
value|*(u_int16_t *)&BIOSDATA[0x85]
end_define

begin_define
define|#
directive|define
name|BIOS_SaveTablePointer
value|*(u_int32_t *)&BIOSDATA[0xa8]
end_define

begin_comment
comment|/*  * Video modes  *  * This started as a big 'switch' statement in 'video.c:init_mode()' which  * soon became too ugly and unmanagable. So, we collect all mode related  * information in one table and define a couple of helper function to access  * it. This will also benefit the VESA support, whenever we get to that.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|modenumber
decl_stmt|;
comment|/* Mode number */
name|int
name|paramindex
decl_stmt|;
comment|/* Index into the parameter table */
name|int
name|type
decl_stmt|;
comment|/* Text or Graphics */
name|int
name|numcolors
decl_stmt|;
comment|/* Number of colors */
name|int
name|numpages
decl_stmt|;
comment|/* Number of display pages */
name|int
name|vrescode
decl_stmt|;
comment|/* 0 = 200, 1 = 350, 2 = 400, 3 = 480 */
name|u_int32_t
name|vmemaddr
decl_stmt|;
comment|/* Video memory address */
name|char
modifier|*
name|fontname
decl_stmt|;
comment|/* Font name */
block|}
name|vmode_t
typedef|;
end_typedef

begin_comment
comment|/* Types. 'NOMODE' is one of the 'forbidden' internal modes. */
end_comment

begin_define
define|#
directive|define
name|TEXT
value|0
end_define

begin_define
define|#
directive|define
name|GRAPHICS
value|1
end_define

begin_define
define|#
directive|define
name|NOMODE
value|-1
end_define

begin_decl_stmt
specifier|extern
name|vmode_t
name|vmodelist
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Font names */
end_comment

begin_define
define|#
directive|define
name|FONTVGA
value|"vga"
end_define

begin_define
define|#
directive|define
name|FONT8x8
value|"vga8x8"
end_define

begin_define
define|#
directive|define
name|FONT8x14
value|"vga8x14"
end_define

begin_define
define|#
directive|define
name|FONT8x16
value|"vga8x16"
end_define

begin_comment
comment|/* same as FONTVGA */
end_comment

begin_comment
comment|/* External functions in 'video.c'. */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_mode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|find_vmode
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_write
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|video_bios_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|video_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vmem_pageflt
parameter_list|(
name|struct
name|sigframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Other external variables, mostly from tty.c. Needs to be cleaned up. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|vattr
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|write_vram
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

