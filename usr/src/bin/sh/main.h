begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)main.h	8.1 (Berkeley) %G%  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|readcmdfile
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmdloop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|readcmdfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmdloop
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

