begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)open.c	6.1 (Berkeley) 8/29/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * converts plot to grn  */
end_comment

begin_include
include|#
directive|include
file|"grnplot.h"
end_include

begin_decl_stmt
name|int
name|curx
decl_stmt|,
name|cury
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current world position */
end_comment

begin_decl_stmt
name|int
name|xbot
init|=
literal|0
decl_stmt|,
name|ybot
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Coordinates of screen lower-left corner */
end_comment

begin_decl_stmt
name|double
name|scale
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of pixels per 2**12 units 			 * of world coordinates. 			 */
end_comment

begin_decl_stmt
name|int
name|linestyle
init|=
literal|5
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ingrnfile
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|invector
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------  *	Openpl initializes the graphics display and clears its screen.  *  *	Results:	None.  *  *	Side Effects:  *  *	Errors:		None.  *---------------------------------------------------------  */
end_comment

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{}
end_block

end_unit

