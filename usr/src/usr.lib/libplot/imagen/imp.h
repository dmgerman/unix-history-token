begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1985 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)imp.h	5.2 (Berkeley) 9/21/85  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_decl_stmt
specifier|extern
name|float
name|obotx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|boty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|botx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|oboty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scalex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|float
name|scaley
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|imPx
decl_stmt|,
name|imPy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|imPcsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|imP_charset
decl_stmt|;
end_decl_stmt

end_unit

