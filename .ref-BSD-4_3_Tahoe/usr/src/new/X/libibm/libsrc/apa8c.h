begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: apa8c.h,v 10.1 86/11/19 10:45:18 jg Exp $ */
end_comment

begin_comment
comment|/* apa8c.h - Definitions and macros required to access APA8C  *  *	Defines required to support APA8C  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_BASE
value|(0xF4D20000)
end_define

begin_comment
comment|/* base address for screen bitmap */
end_comment

begin_define
define|#
directive|define
name|XDEV_ID
value|XDEV_IBMAPA8C
end_define

begin_comment
comment|/* device id for info structure */
end_comment

begin_define
define|#
directive|define
name|REAL_SCREEN_WIDTH
value|1024
end_define

begin_comment
comment|/* number of bits/line for apa8c */
end_comment

begin_define
define|#
directive|define
name|REAL_SCREEN_HEIGHT
value|512
end_define

begin_comment
comment|/* Number of lines on apa8c */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_WIDTH
value|720
end_define

begin_comment
comment|/* number of bits/line for apa8c display */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_HEIGHT
value|512
end_define

begin_comment
comment|/* visible lines on the screen */
end_comment

begin_define
define|#
directive|define
name|SCREEN_DEVICE
value|"/dev/apa8c"
end_define

begin_comment
comment|/* device name */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DEVICE
value|"/dev/msapa8c"
end_define

begin_comment
comment|/* device name of mouse for display */
end_comment

begin_define
define|#
directive|define
name|CURSOR_TYPE
value|SOFT_CURSOR
end_define

begin_comment
comment|/* apa8c uses software cursor */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_INIT
parameter_list|()
value|apa8c_init()
end_define

begin_comment
comment|/* display initialization routine */
end_comment

begin_comment
comment|/*  * Control register (short)  */
end_comment

begin_define
define|#
directive|define
name|APA8C_FC
value|0xF0000150
end_define

begin_comment
comment|/*  * Data mask registers (2 each 8 bits)  */
end_comment

begin_define
define|#
directive|define
name|APA8C_DM
value|0xF0000152
end_define

begin_comment
comment|/*  * Color Plane Select register.  */
end_comment

begin_define
define|#
directive|define
name|CPS_REG
value|0xF0000154
end_define

begin_comment
comment|/*  * Foreground/ Background register.  */
end_comment

begin_define
define|#
directive|define
name|FGBG_REG
value|0xF0000156
end_define

begin_comment
comment|/*  * Video Look-up Table register.  */
end_comment

begin_define
define|#
directive|define
name|VLT_REG
value|0xF0000158
end_define

begin_comment
comment|/*  * bits 0-2  rotate count  */
end_comment

begin_define
define|#
directive|define
name|DCR_ROTMASK
value|0x0007
end_define

begin_comment
comment|/*  * bits 3-5  logic unit function control  */
end_comment

begin_define
define|#
directive|define
name|DCR_FCMASK
value|0x0038
end_define

begin_define
define|#
directive|define
name|DCR_FCOR
value|0x0028
end_define

begin_define
define|#
directive|define
name|DCR_FCNOR
value|0x0038
end_define

begin_define
define|#
directive|define
name|DCR_FCPA
value|0x0010
end_define

begin_define
define|#
directive|define
name|DCR_FCPB
value|0x0000
end_define

begin_define
define|#
directive|define
name|DCR_FCPNA
value|0x0030
end_define

begin_define
define|#
directive|define
name|DCR_FCPNB
value|0x0020
end_define

begin_define
define|#
directive|define
name|DEFAULT_FUNC
value|DCR_FCPNB
end_define

begin_define
define|#
directive|define
name|HIDDEN_FUNC
value|DCR_FCPA
end_define

begin_define
define|#
directive|define
name|RDWR_FUNC
value|DCR_FCPA
end_define

begin_comment
comment|/*  * 6-7 reserved  */
end_comment

begin_comment
comment|/*  * 8-9 memory mode  */
end_comment

begin_define
define|#
directive|define
name|DCR_MEMMODE
value|0x0300
end_define

begin_define
define|#
directive|define
name|DCR_SWR
value|0x0000
end_define

begin_define
define|#
directive|define
name|DCR_ISWR
value|0x0100
end_define

begin_define
define|#
directive|define
name|DCR_ADWR
value|0x0200
end_define

begin_define
define|#
directive|define
name|DCR_AURW
value|0x0300
end_define

begin_comment
comment|/*  * 10 inc/dec of the address counter  */
end_comment

begin_define
define|#
directive|define
name|DCR_DEC
value|0x0400
end_define

begin_define
define|#
directive|define
name|DCR_INC
value|~0x0400
end_define

begin_comment
comment|/*  * 11 x/y stepping  */
end_comment

begin_define
define|#
directive|define
name|DCR_X
value|0x0800
end_define

begin_define
define|#
directive|define
name|DCR_Y
value|~0x0800
end_define

begin_comment
comment|/*  * 12  1 means block transfer  */
end_comment

begin_define
define|#
directive|define
name|DCR_BT
value|0x1000
end_define

begin_comment
comment|/*  * 13  1 means interrupt enable  */
end_comment

begin_define
define|#
directive|define
name|DCR_IEN
value|0x2000
end_define

begin_comment
comment|/*  * 14  1 means Sync enable  */
end_comment

begin_define
define|#
directive|define
name|DCR_SEN
value|0x4000
end_define

begin_comment
comment|/*  * 15  1 means Video enable  */
end_comment

begin_define
define|#
directive|define
name|DCR_VEN
value|0x8000
end_define

begin_comment
comment|/*  * Data Mask Register masks (typically are the  * inverse of each other)  */
end_comment

begin_define
define|#
directive|define
name|DM_A
value|0xFF00
end_define

begin_define
define|#
directive|define
name|DM_B
value|0x00FF
end_define

begin_define
define|#
directive|define
name|CLEAR_DM
value|0x0000
end_define

begin_define
define|#
directive|define
name|DEFAULT_DM
value|DM_B
end_define

begin_define
define|#
directive|define
name|HIDDEN_DM
value|DM_A
end_define

begin_define
define|#
directive|define
name|RDWR_DM
value|DM_A
end_define

begin_comment
comment|/*  * Values for the writemask.  */
end_comment

begin_define
define|#
directive|define
name|NOMASK
value|0x0000
end_define

begin_define
define|#
directive|define
name|MASKBYTE2
value|0x00FF
end_define

begin_define
define|#
directive|define
name|MASKBYTE1
value|0xFF00
end_define

begin_comment
comment|/*  * Values for the color plane select register.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CPS
value|0x001F;
end_define

begin_comment
comment|/*  * Values for the foreground/background register.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_FGBG
value|0x00F0;
end_define

begin_comment
comment|/*  * Color definitions (not all colors are defined)  */
end_comment

begin_define
define|#
directive|define
name|DARK_RED
value|0x0100
end_define

begin_define
define|#
directive|define
name|DARK_GREEN
value|0x0400
end_define

begin_define
define|#
directive|define
name|DARK_BLUE
value|0x1000
end_define

begin_define
define|#
directive|define
name|RED
value|0x0200
end_define

begin_define
define|#
directive|define
name|GREEN
value|0x0800
end_define

begin_define
define|#
directive|define
name|BLUE
value|0x2000
end_define

begin_define
define|#
directive|define
name|LIGHT_RED
value|0x0300
end_define

begin_define
define|#
directive|define
name|LIGHT_GREEN
value|0x0C00
end_define

begin_define
define|#
directive|define
name|LIGHT_BLUE
value|0x3000
end_define

begin_define
define|#
directive|define
name|BLACK
value|0x0000
end_define

begin_define
define|#
directive|define
name|WHITE
value|0x3F00
end_define

begin_comment
comment|/*  * Defines to work with the Video Look-up table.  * foreground = 1 bits     background = 0 bits  * (Note: In "X" zero bits are black and one bits are white)  */
end_comment

begin_define
define|#
directive|define
name|VLT_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|FG_COLOR
value|WHITE
end_define

begin_define
define|#
directive|define
name|BG_COLOR
value|DARK_GREEN
end_define

begin_comment
comment|/*  * Bitmap to BUS address offsets.  All address offsets in the bitmap area  * must be multiplied by 2 before being used as BUS offsets.  */
end_comment

begin_define
define|#
directive|define
name|BM_TO_BUS
parameter_list|(
name|n
parameter_list|)
value|((n)<< 1)
end_define

begin_comment
comment|/*  * The physical bitmap addresses on the apa8C adaptor card  * go from 0000 to 0xFFFF. (the size of a short or word, 16 bits addresses  * these spots.  */
end_comment

begin_define
define|#
directive|define
name|MAXOFFSET
value|0xFFFF
end_define

begin_comment
comment|/*  * This is defined to be the last scan line in the hidden area.  * It is needed because the side affect of setting the writemask registers  * is the mask is also written to the bitmap.  */
end_comment

begin_define
define|#
directive|define
name|WRMASK_SCREEN_BASE
define|\
value|(*(u_short *)(SCREEN_BASE + BM_TO_BUS(MAXOFFSET - 1)))
end_define

begin_define
define|#
directive|define
name|SET_APA8C_FC
parameter_list|(
name|control_info
parameter_list|)
value|{			\ 	*(u_short *) APA8C_FC = (u_short)(control_info);	\ }
end_define

begin_define
define|#
directive|define
name|SET_APA8C_WRITEMASK
parameter_list|(
name|mask
parameter_list|)
value|{					\ 	SET_APA8C_FC(DCR_SEN | DCR_VEN | DCR_ISWR | DCR_X | DCR_FCOR);	\ 	WRMASK_SCREEN_BASE = (u_short) mask;				\ }
end_define

begin_define
define|#
directive|define
name|SET_APA8C_DATAMASK
parameter_list|(
name|mask
parameter_list|)
value|{		\ 	*(u_short *)APA8C_DM = (u_short) mask;	\ }
end_define

end_unit

