begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: pqd.h,v 10.1 86/11/19 10:46:07 jg Exp $ */
end_comment

begin_comment
comment|/* pqd.h - Definition and macros required to access PQD  *  *	Defines required to support PQD  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|SCREEN_BASE
value|0xF40C0000
end_define

begin_comment
comment|/* base address of frame buffer */
end_comment

begin_define
define|#
directive|define
name|XDEV_ID
value|XDEV_IBMPQD
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
comment|/* number of bits/line for pqd */
end_comment

begin_define
define|#
directive|define
name|REAL_SCREEN_HEIGHT
value|1024
end_define

begin_comment
comment|/* Number of lines on pqd */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_WIDTH
value|1024
end_define

begin_comment
comment|/* visible bits/line for pqd */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_HEIGHT
value|800
end_define

begin_comment
comment|/* visible lines on the screen */
end_comment

begin_define
define|#
directive|define
name|SCREEN_DEVICE
value|"/dev/pqd"
end_define

begin_comment
comment|/* device name */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DEVICE
value|"/dev/mspqd"
end_define

begin_comment
comment|/* device name of mouse for display */
end_comment

begin_define
define|#
directive|define
name|CURSOR_TYPE
value|HARD_CURSOR
end_define

begin_comment
comment|/* pqd uses hardware cursor */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_INIT
parameter_list|()
value|pqd_init()
end_define

begin_comment
comment|/* display initialization routine */
end_comment

begin_define
define|#
directive|define
name|PQD_IOADDR
value|0xF0000320
end_define

begin_comment
comment|/* base address for controller regs */
end_comment

begin_define
define|#
directive|define
name|PQD_WM1
value|(PQD_IOADDR | 0x00000006)
end_define

begin_define
define|#
directive|define
name|PQD_WM0
value|(PQD_IOADDR | 0x00000008)
end_define

begin_define
define|#
directive|define
name|PQD_PCR
value|(PQD_IOADDR | 0x0000000A)
end_define

begin_define
define|#
directive|define
name|PQD_VCR
value|(PQD_IOADDR | 0x0000000C)
end_define

begin_define
define|#
directive|define
name|PQD_WCR
value|(PQD_IOADDR | 0x0000000E)
end_define

begin_comment
comment|/*  * macros for controlling access to plane bitmaps  */
end_comment

begin_define
define|#
directive|define
name|SELECT_PLANE
parameter_list|(
name|n
parameter_list|)
value|*(unsigned short *)PQD_PCR = plane_no[n]
end_define

begin_define
define|#
directive|define
name|SET_PLANE
parameter_list|(
name|RW
parameter_list|)
value|*(unsigned short *)PQD_PCR = RW
end_define

begin_define
define|#
directive|define
name|RW_PLANE0
value|0x1000
end_define

begin_define
define|#
directive|define
name|RW_PLANE1
value|0x2100
end_define

begin_define
define|#
directive|define
name|RW_PLANE2
value|0x4200
end_define

begin_define
define|#
directive|define
name|RW_PLANE3
value|0x8300
end_define

begin_decl_stmt
specifier|static
name|unsigned
name|short
name|plane_no
index|[]
init|=
block|{
name|RW_PLANE0
block|,
name|RW_PLANE1
block|,
name|RW_PLANE2
block|,
name|RW_PLANE3
block|}
decl_stmt|;
end_decl_stmt

end_unit

