begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)kernel.h	7.1 (Berkeley) 6/4/86  */
end_comment

begin_comment
comment|/*  * Global variables for the kernel  */
end_comment

begin_function_decl
name|long
name|rmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 */
end_comment

begin_decl_stmt
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|phz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* alternate clock's frequency */
end_comment

begin_decl_stmt
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* awoken once a second */
end_comment

begin_function_decl
name|int
name|realitexpire
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|double
name|avenrun
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|GPROF
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|s_lowpc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_long
name|s_textsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|kcount
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

