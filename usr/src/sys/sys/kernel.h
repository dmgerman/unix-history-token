begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)kernel.h	8.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/* Global variables for the kernel. */
end_comment

begin_comment
comment|/* 1.1 */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|hostid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1.2 */
end_comment

begin_decl_stmt
specifier|extern
specifier|volatile
name|struct
name|timeval
name|mono_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|boottime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timeval
name|runtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|volatile
name|struct
name|timeval
name|time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|timezone
name|tz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* XXX */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tick
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usec per tick (1000000 / hz) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* system clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|stathz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* statistics clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profhz
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* profiling clock's frequency */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|lbolt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* once a second sleep address */
end_comment

end_unit

