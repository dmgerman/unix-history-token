begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: apa16.h,v 10.1 86/11/19 10:45:01 jg Exp $ */
end_comment

begin_comment
comment|/* apa16.h - Definitions and macros required to access APA16  *  *	Defines required to support APA16  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_BASE
value|(IO_ADDR | 0x4D80000)
end_define

begin_comment
comment|/* frame buffer address */
end_comment

begin_define
define|#
directive|define
name|XDEV_ID
value|XDEV_IBMAPA16
end_define

begin_comment
comment|/* device id for info structure */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_WIDTH
value|1024
end_define

begin_comment
comment|/* number of bits/line for apa16 */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_HEIGHT
value|768
end_define

begin_comment
comment|/* number of lines on the screen */
end_comment

begin_define
define|#
directive|define
name|REAL_SCREEN_WIDTH
value|X_SCREEN_WIDTH
end_define

begin_comment
comment|/* actual screen width */
end_comment

begin_define
define|#
directive|define
name|REAL_SCREEN_HEIGHT
value|X_SCREEN_HEIGHT
end_define

begin_comment
comment|/* actual screen height */
end_comment

begin_define
define|#
directive|define
name|CURSOR_TYPE
value|HARD_CURSOR
end_define

begin_comment
comment|/* apa16 uses hardware cursor */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_INIT
parameter_list|()
value|apa16_init()
end_define

begin_comment
comment|/* display initialization routine */
end_comment

begin_define
define|#
directive|define
name|SCREEN_DEVICE
value|"/dev/apa16"
end_define

begin_comment
comment|/* device number */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DEVICE
value|"/dev/msapa16"
end_define

begin_comment
comment|/* device name of mouse for display */
end_comment

begin_comment
comment|/*  * base I/O address  */
end_comment

begin_define
define|#
directive|define
name|IO_ADDR
value|0xF0000000
end_define

begin_comment
comment|/*  * Mode register.  */
end_comment

begin_define
define|#
directive|define
name|MR
value|(IO_ADDR | 0x0D10)
end_define

begin_define
define|#
directive|define
name|MR_DEFAULT
value|0x8090
end_define

begin_comment
comment|/*  * Control/Status register.  */
end_comment

begin_define
define|#
directive|define
name|CSR
value|(IO_ADDR | 0x0D12)
end_define

begin_define
define|#
directive|define
name|BACKGRND_BIT
value|0x0400
end_define

begin_define
define|#
directive|define
name|BLACK_ON_WHITE
value|(*(u_short *)(CSR) | BACKGRND_BIT)
end_define

begin_define
define|#
directive|define
name|WHITE_ON_BLACK
value|(*(u_short *)(CSR)& ~BACKGRND_BIT)
end_define

begin_define
define|#
directive|define
name|TOGGLE_BACKGRND
value|(*(u_short *)(CSR) ^ BACKGRND_BIT)
end_define

begin_comment
comment|/*  * Video data output.  */
end_comment

begin_define
define|#
directive|define
name|VD_OUT
value|(IO_ADDR | 0x0D1A)
end_define

begin_comment
comment|/*  * Enable video data output  */
end_comment

begin_define
define|#
directive|define
name|ENABLE_VD_OUT
parameter_list|()
value|*(u_short *)VD_OUT = 0
end_define

begin_comment
comment|/*  * Reset adaptor register.  */
end_comment

begin_define
define|#
directive|define
name|RA_R
value|(IO_ADDR | 0x0D20)
end_define

begin_define
define|#
directive|define
name|RESET_APA16
parameter_list|()
value|*(u_short *)RA_R = 0;
end_define

end_unit

