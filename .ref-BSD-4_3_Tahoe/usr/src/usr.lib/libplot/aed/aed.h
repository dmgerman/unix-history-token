begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)aed.h	5.2 (Berkeley) 6/5/85  */
end_comment

begin_comment
comment|/*  * Displays plot files on an AED512 graphics terminal.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_decl_stmt
specifier|extern
name|char
name|dbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to buffer display characters */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|sgttyb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to save terminal control bits */
end_comment

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
name|int
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of pixels per 2**12 units 				 * of world coordinates. 				 */
end_comment

begin_comment
comment|/* The following variables describe the screen. */
end_comment

begin_define
define|#
directive|define
name|GRXMAX
value|511
end_define

begin_comment
comment|/* Maximum x-coordinate of screen */
end_comment

begin_define
define|#
directive|define
name|GRYMAX
value|482
end_define

begin_comment
comment|/* Maximum y-coordinate of screen */
end_comment

end_unit

