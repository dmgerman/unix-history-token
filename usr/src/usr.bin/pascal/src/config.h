begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)config.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_comment
comment|/*      *	external declarations of things from       *		CONFIG.c      *      */
end_comment

begin_comment
comment|/*      *	the version of translator      */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|version
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the error strings      *	and the length of the path to it      *	(in case of execution of pc0 as a.out)      */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|err_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|err_pathlen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*      *	the location of the short explanation      *	and the length of the path to it      *	the null at the end is so pix can change it to pi'x' from pi.      */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|how_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|how_pathlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|px_header
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pi_comp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|px_intrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|px_debug
decl_stmt|;
end_decl_stmt

end_unit

