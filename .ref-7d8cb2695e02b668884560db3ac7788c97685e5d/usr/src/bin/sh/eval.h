begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * %sccs.include.redist.c%  *  *	@(#)eval.h	8.1 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|commandname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* currently executing command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exitstatus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit status of last command */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|strlist
modifier|*
name|cmdenviron
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment for builtin command */
end_comment

begin_struct
struct|struct
name|backcmd
block|{
comment|/* result of evalbackcmd */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor to read from */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer */
name|int
name|nleft
decl_stmt|;
comment|/* number of chars in buffer */
name|struct
name|job
modifier|*
name|jp
decl_stmt|;
comment|/* job structure for command */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_function_decl
name|void
name|evalstring
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_comment
comment|/* BLETCH for ansi C */
end_comment

begin_function_decl
name|void
name|evaltree
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evalbackcmd
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|struct
name|backcmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|void
name|evalstring
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evaltree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evalbackcmd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* in_function returns nonzero if we are currently evaluating a function */
end_comment

begin_define
define|#
directive|define
name|in_function
parameter_list|()
value|funcnest
end_define

begin_decl_stmt
specifier|extern
name|int
name|funcnest
decl_stmt|;
end_decl_stmt

end_unit

