begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)ikreg.h	7.2 (Berkeley) 12/22/87  */
end_comment

begin_struct
struct|struct
name|ikdevice
block|{
name|short
name|ik_wc
decl_stmt|;
comment|/* Unibus word count reg */
name|u_short
name|ik_ubaddr
decl_stmt|;
comment|/* Unibus address register */
name|u_short
name|ik_ustat
decl_stmt|;
comment|/* Unibus status/command reg */
name|u_short
name|ik_data
decl_stmt|;
comment|/* Data register */
name|u_short
name|ik_xaddr
decl_stmt|;
comment|/* X address in frame buffer */
name|u_short
name|ik_yaddr
decl_stmt|;
comment|/* Y address in frame buffer */
name|u_short
name|ik_istat
decl_stmt|;
comment|/* Ikonas status/command reg */
name|u_short
name|ik_chan
decl_stmt|;
comment|/* Channel control register */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IK_GETADDR
value|IKIOGETADDR
end_define

begin_define
define|#
directive|define
name|IK_WAITINT
value|IKIOWAITINT
end_define

begin_define
define|#
directive|define
name|IKIOGETADDR
value|_IOR('i', 0, caddr_t)
end_define

begin_comment
comment|/* get Unibus device address */
end_comment

begin_define
define|#
directive|define
name|IKIOWAITINT
value|_IO('i', 1)
end_define

begin_comment
comment|/* await device interrupt */
end_comment

begin_comment
comment|/*  * Unibus status/command register bits  */
end_comment

begin_define
define|#
directive|define
name|IK_GO
value|01
end_define

begin_define
define|#
directive|define
name|IK_IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|IK_READY
value|0200
end_define

begin_define
define|#
directive|define
name|IK_IKONAS_INTR
value|0100000
end_define

begin_comment
comment|/*  * Ikonas status/command register bits  */
end_comment

begin_define
define|#
directive|define
name|WORD32
value|0
end_define

begin_define
define|#
directive|define
name|RES512
value|2
end_define

begin_define
define|#
directive|define
name|RES1024
value|3
end_define

begin_define
define|#
directive|define
name|READ_SELECT
value|0
end_define

begin_define
define|#
directive|define
name|WRITE_MASK
value|010
end_define

begin_define
define|#
directive|define
name|WRITE_SELECT
value|020
end_define

begin_define
define|#
directive|define
name|HALFWORD
value|040
end_define

begin_define
define|#
directive|define
name|DMAENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|INVISIBLE_IO
value|0200
end_define

begin_define
define|#
directive|define
name|AUTOINCREMENT
value|0400
end_define

begin_define
define|#
directive|define
name|RUN_PROCESSOR
value|01000
end_define

begin_define
define|#
directive|define
name|CLEAR
value|02000
end_define

begin_define
define|#
directive|define
name|BYTE_MODE
value|04000
end_define

begin_define
define|#
directive|define
name|FRAME_ENABLE
value|010000
end_define

begin_define
define|#
directive|define
name|PROC_ENABLE
value|020000
end_define

begin_define
define|#
directive|define
name|RED_SELECT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_SELECT
value|040000
end_define

begin_define
define|#
directive|define
name|BLUE_SELECT
value|0100000
end_define

begin_define
define|#
directive|define
name|ALPHA_SELECT
value|0140000
end_define

begin_comment
comment|/*  * Frame buffer controller  */
end_comment

begin_define
define|#
directive|define
name|FBC0
value|060000000
end_define

begin_define
define|#
directive|define
name|FBC1
value|062000000
end_define

begin_define
define|#
directive|define
name|VIEWPORT_LOC
value|0
end_define

begin_define
define|#
directive|define
name|VIEWPORT_SIZE
value|1
end_define

begin_define
define|#
directive|define
name|WINDOW_LOC
value|2
end_define

begin_define
define|#
directive|define
name|ZOOM
value|3
end_define

begin_define
define|#
directive|define
name|DISPLAY_RATE
value|4
end_define

begin_define
define|#
directive|define
name|VIDEO_CONTROL
value|5
end_define

begin_define
define|#
directive|define
name|FORMAT_CONTROL_MASK
value|03
end_define

begin_define
define|#
directive|define
name|CURSOR_ON
value|04
end_define

begin_define
define|#
directive|define
name|LOW_RESOL
value|0
end_define

begin_define
define|#
directive|define
name|HIGH_RESOL
value|010
end_define

begin_define
define|#
directive|define
name|AUTO_CLEAR
value|040
end_define

begin_define
define|#
directive|define
name|EXT_SYNC
value|0100
end_define

begin_define
define|#
directive|define
name|COLOR_MAP_PAGES
value|0600
end_define

begin_define
define|#
directive|define
name|HIGH_RESOL_SYNC
value|01000
end_define

begin_define
define|#
directive|define
name|REPEAT_FIELD
value|02000
end_define

begin_define
define|#
directive|define
name|PIXEL_CLOCK_RATE_MASK
value|077
end_define

begin_define
define|#
directive|define
name|CURSOR_LOC
value|6
end_define

begin_define
define|#
directive|define
name|CURSOR_SHADE
value|7
end_define

begin_define
define|#
directive|define
name|CURSOR_MAP
value|0400
end_define

begin_comment
comment|/*  * Color map lookup table  */
end_comment

begin_define
define|#
directive|define
name|CMAP0
value|040600000
end_define

begin_define
define|#
directive|define
name|CMAP1
value|040610000
end_define

begin_define
define|#
directive|define
name|CHAN_SELECT
value|02000
end_define

begin_comment
comment|/*  * Frame buffer memories  */
end_comment

begin_define
define|#
directive|define
name|MEM0
value|000000000
end_define

begin_define
define|#
directive|define
name|MEM1
value|004000000
end_define

begin_comment
comment|/*  * Bit-slice processor  */
end_comment

begin_define
define|#
directive|define
name|UMEM
value|040000000
end_define

begin_define
define|#
directive|define
name|SCRPAD
value|040400000
end_define

begin_define
define|#
directive|define
name|PROC
value|041200000
end_define

begin_comment
comment|/*  * Frame grabber  */
end_comment

begin_define
define|#
directive|define
name|FMG0
value|060200000
end_define

end_unit

