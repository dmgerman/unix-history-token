begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)getent.c	5.3 (Berkeley) %G%"
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
return|return
operator|(
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
name|cp
parameter_list|,
name|cpp
parameter_list|)
name|char
modifier|*
name|cp
decl_stmt|,
decl|*
modifier|*
name|cpp
decl_stmt|;
end_function

begin_block
block|{
return|return
operator|(
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

