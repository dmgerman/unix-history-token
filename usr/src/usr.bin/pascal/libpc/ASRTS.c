begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ASRTS.c	1.2 (Berkeley) %G%"
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
name|char
name|EASRTS
index|[]
init|=
literal|"Assertion failed: %s\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|ASRTS
argument_list|(
argument|cond
argument_list|,
argument|stmt
argument_list|)
end_macro

begin_decl_stmt
name|short
name|cond
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|stmt
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|cond
condition|)
return|return;
name|ERROR
argument_list|(
name|EASRTS
argument_list|,
name|stmt
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

