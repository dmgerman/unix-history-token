begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1979 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)TIME.c	1.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|ctime
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|TIME
argument_list|(
name|alfap
argument_list|)
specifier|register
name|char
operator|*
name|alfap
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|ap
decl_stmt|,
modifier|*
name|cp
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
name|long
name|a
decl_stmt|;
name|time
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|cp
operator|=
name|ctime
argument_list|(
operator|&
name|a
argument_list|)
expr_stmt|;
name|ap
operator|=
name|alfap
expr_stmt|;
for|for
control|(
name|cp
operator|=
name|cp
operator|+
literal|10
operator|,
name|i
operator|=
literal|10
init|;
name|i
condition|;
operator|*
name|ap
operator|++
operator|=
operator|*
name|cp
operator|++
operator|,
name|i
operator|--
control|)
empty_stmt|;
block|}
end_block

end_unit

