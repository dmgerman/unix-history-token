begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)misc.h	8.1 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|UserNameRequested
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LocalHostName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|RemoteHostName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ConnectedCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ReservedPort
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"misc-proto.h"
end_include

end_unit

