begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)getarg_.c	5.2 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * return a specified command line argument  *  * calling sequence:  *	character*20 arg  *	call getarg(k, arg)  * where:  *	arg will receive the kth unix command argument */
end_comment

begin_macro
name|getarg_
argument_list|(
argument|n
argument_list|,
argument|s
argument_list|,
argument|ls
argument_list|)
end_macro

begin_decl_stmt
name|long
name|int
modifier|*
name|n
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|ls
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|extern
name|int
name|xargc
decl_stmt|;
specifier|extern
name|char
modifier|*
modifier|*
name|xargv
decl_stmt|;
specifier|register
name|char
modifier|*
name|t
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
if|if
condition|(
operator|*
name|n
operator|>=
literal|0
operator|&&
operator|*
name|n
operator|<
name|xargc
condition|)
name|t
operator|=
name|xargv
index|[
operator|*
name|n
index|]
expr_stmt|;
else|else
name|t
operator|=
literal|""
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|ls
operator|&&
operator|*
name|t
operator|!=
literal|'\0'
condition|;
operator|++
name|i
control|)
operator|*
name|s
operator|++
operator|=
operator|*
name|t
operator|++
expr_stmt|;
for|for
control|(
init|;
name|i
operator|<
name|ls
condition|;
operator|++
name|i
control|)
operator|*
name|s
operator|++
operator|=
literal|' '
expr_stmt|;
block|}
end_block

end_unit

