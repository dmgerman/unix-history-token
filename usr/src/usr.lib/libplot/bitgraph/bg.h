begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)bg.h	5.1 (Berkeley) 4/30/85  */
end_comment

begin_comment
comment|/*  * Displays plot files on a bbn bitgraph terminal.  */
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
comment|/* The graphics address range is 0..XMAX, 0..YMAX. */
end_comment

begin_define
define|#
directive|define
name|XMAX
value|768
end_define

begin_define
define|#
directive|define
name|YMAX
value|1024
end_define

begin_define
define|#
directive|define
name|scaleX
parameter_list|(
name|xi
parameter_list|)
value|((int) ((xi - lowx)*scale +0.5))
end_define

begin_define
define|#
directive|define
name|scaleY
parameter_list|(
name|yi
parameter_list|)
value|((int) ((yi - lowy)*scale +0.5))
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
name|scale
decl_stmt|;
end_decl_stmt

end_unit

