begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)grnplot.h	6.1 (Berkeley) 8/29/86  *	modified to grnplot by Brad Rubenstein 8/29/86  */
end_comment

begin_comment
comment|/*  * Given a plot file, produces a grn file  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_extern
extern|extern curx
operator|,
extern|cury;
end_extern

begin_comment
comment|/* Current screen position */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xbot
decl_stmt|,
name|ybot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Coordinates of screen lower-left corner */
end_comment

begin_decl_stmt
specifier|extern
name|double
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of pixels per 2**12 units 				 * of world coordinates. 				 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|linestyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|invector
decl_stmt|,
name|ingrnfile
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FONTSIZE
value|1
end_define

begin_define
define|#
directive|define
name|FONTSTYLE
value|1
end_define

begin_define
define|#
directive|define
name|DEFAULTLINE
value|5
end_define

begin_define
define|#
directive|define
name|POINTSTRING
value|"."
end_define

begin_comment
comment|/* The following variables describe the screen. */
end_comment

begin_define
define|#
directive|define
name|GRXMAX
value|512
end_define

begin_comment
comment|/* Maximum x-coordinate of screen */
end_comment

begin_define
define|#
directive|define
name|GRYMAX
value|512
end_define

begin_comment
comment|/* Maximum y-coordinate of screen */
end_comment

end_unit

