begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)main.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|main
parameter_list|()
block|{
extern|extern yyparse(
block|)
function|;
end_function

begin_expr_stmt
operator|(
name|void
operator|)
name|yyparse
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|(
literal|0
operator|)
return|;
end_return

unit|}
end_unit

