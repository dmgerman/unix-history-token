begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: aed.h,v 10.1 86/11/19 10:44:53 jg Exp $ */
end_comment

begin_comment
comment|/* aed.h - Defines and macros needed to support AED  *  *  	Author:  *		Scott Bates  *		Brown University  *		IRIS, Box 1946  *      	Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_include
include|#
directive|include
file|"../bitblt/bitblt_aed.h"
end_include

begin_define
define|#
directive|define
name|SCREEN_BASE
value|AED_BM_ADDR
end_define

begin_comment
comment|/* buffer address for bitmap structure */
end_comment

begin_define
define|#
directive|define
name|SCREEN_BM_SIZE
value|AED_BM_SIZE
end_define

begin_comment
comment|/* size of the aed screen bitmap */
end_comment

begin_define
define|#
directive|define
name|XDEV_ID
value|XDEV_IBMAED
end_define

begin_comment
comment|/* device id for info structure */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_WIDTH
value|AED_WIDTH
end_define

begin_comment
comment|/* number of bits/line for aed display */
end_comment

begin_define
define|#
directive|define
name|X_SCREEN_HEIGHT
value|AED_HEIGHT
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

begin_define
define|#
directive|define
name|REAL_SCREEN_HEIGHT
value|X_SCREEN_HEIGHT
end_define

begin_define
define|#
directive|define
name|CURSOR_TYPE
value|HARD_CURSOR
end_define

begin_comment
comment|/* aed uses hardware cursor */
end_comment

begin_define
define|#
directive|define
name|DISPLAY_INIT
parameter_list|()
value|aed_init()
end_define

begin_comment
comment|/* display initialization routine */
end_comment

begin_define
define|#
directive|define
name|SCREEN_DEVICE
value|"/dev/aed"
end_define

begin_comment
comment|/* device name of display */
end_comment

begin_define
define|#
directive|define
name|MOUSE_DEVICE
value|"/dev/msaed"
end_define

begin_comment
comment|/* device name of mouse for display */
end_comment

begin_comment
comment|/*  * Defines for default foreground/background  */
end_comment

begin_define
define|#
directive|define
name|WHITE_ON_BLACK
value|0
end_define

begin_define
define|#
directive|define
name|BLACK_ON_WHITE
value|1
end_define

begin_comment
comment|/*  * gets color of constant tile (black or white)  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_TILE_COLOR
parameter_list|(
name|blt
parameter_list|)
value|((blt->tile_ptr->tile[0])& 0xFFFF ? 1 : 0)
end_define

end_unit

