begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  *  *	@(#)gigi.h	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Displays plot files on a gigi "graphics" terminal.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|PI
value|3.141592659
end_define

begin_comment
comment|/*  * The graphics address range is 0..XMAX, YMAX..0 where (0, YMAX) is the  * lower left corner.  */
end_comment

begin_define
define|#
directive|define
name|XMAX
value|767
end_define

begin_define
define|#
directive|define
name|YMAX
value|479
end_define

begin_define
define|#
directive|define
name|xsc
parameter_list|(
name|xi
parameter_list|)
value|((int) ((xi -lowx)*scalex +0.5))
end_define

begin_define
define|#
directive|define
name|ysc
parameter_list|(
name|yi
parameter_list|)
value|((int) (YMAX - (yi - lowy)*scaley +0.5))
end_define

begin_decl_stmt
specifier|extern
name|int
name|currentx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|currenty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|lowx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|lowy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|scalex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|scaley
decl_stmt|;
end_decl_stmt

end_unit

