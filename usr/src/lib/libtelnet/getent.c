begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getent.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_decl_stmt
specifier|static
name|char
modifier|*
name|area
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|getent
argument_list|(
argument|cp
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|,
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
modifier|*
name|dba
index|[
literal|2
index|]
decl_stmt|;
name|dba
index|[
literal|0
index|]
operator|=
literal|"/etc/gettytab"
expr_stmt|;
name|dba
index|[
literal|1
index|]
operator|=
literal|0
expr_stmt|;
return|return
operator|(
operator|(
name|cgetent
argument_list|(
operator|&
name|area
argument_list|,
name|dba
argument_list|,
name|name
argument_list|)
operator|==
literal|0
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_ifndef
ifndef|#
directive|ifndef
name|__svr4__
end_ifndef

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|char
modifier|*
name|getstr
parameter_list|(
name|id
parameter_list|,
name|cpp
parameter_list|)
name|char
modifier|*
name|id
decl_stmt|,
decl|*
modifier|*
name|cpp
decl_stmt|;
end_function

begin_block
block|{
name|char
modifier|*
name|answer
decl_stmt|;
return|return
operator|(
operator|(
name|cgetstr
argument_list|(
name|area
argument_list|,
name|id
argument_list|,
operator|&
name|answer
argument_list|)
operator|>
literal|0
operator|)
condition|?
name|answer
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

