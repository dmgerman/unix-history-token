begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)myhistedit.h	8.2 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<histedit.h>
end_include

begin_decl_stmt
specifier|extern
name|History
modifier|*
name|hist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EditLine
modifier|*
name|el
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|displayhist
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|histedit
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|sethistsize
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|histcmd
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
name|not_fcnumber
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
name|int
name|str_to_event
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

