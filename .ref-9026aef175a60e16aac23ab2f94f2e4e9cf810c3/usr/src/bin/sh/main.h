begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)main.h	8.2 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rootpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of main shell */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rootshell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we aren't a child of the main shell */
end_comment

begin_decl_stmt
name|void
name|readcmdfile
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|cmdloop
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dotcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exitcmd
name|__P
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

