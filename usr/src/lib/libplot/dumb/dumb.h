begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  *  *	@(#)dumb.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * This accepts plot file formats and produces the appropriate plots  * for dumb terminals.  It can also be used for printing terminals and  * lineprinter listings, although there is no way to specify number of  * lines and columns different from your terminal.  This would be easy  * to change, and is left as an exercise for the reader.  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_define
define|#
directive|define
name|scale
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|y = LINES-1-(LINES*y/rangeY +minY); x = COLS*x/rangeX + minX
end_define

begin_decl_stmt
specifier|extern
name|int
name|minX
decl_stmt|,
name|rangeX
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min and range of x */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|minY
decl_stmt|,
name|rangeY
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* min and range of y */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|currentx
decl_stmt|,
name|currenty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|COLS
decl_stmt|,
name|LINES
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A very large screen! (probably should use malloc) */
end_comment

begin_define
define|#
directive|define
name|MAXCOLS
value|132
end_define

begin_define
define|#
directive|define
name|MAXLINES
value|90
end_define

begin_decl_stmt
specifier|extern
name|char
name|screenmat
index|[
name|MAXCOLS
index|]
index|[
name|MAXLINES
index|]
decl_stmt|;
end_decl_stmt

end_unit

