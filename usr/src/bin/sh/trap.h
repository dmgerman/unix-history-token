begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)trap.h	8.1 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pendingsigs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|clear_traps
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setsignal
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ignoresig
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dotrap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinteractive
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exitshell
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
name|clear_traps
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setsignal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ignoresig
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dotrap
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setinteractive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|exitshell
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

