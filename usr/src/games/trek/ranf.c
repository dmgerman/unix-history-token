begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)ranf.c	5.4 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_macro
name|ranf
argument_list|(
argument|max
argument_list|)
end_macro

begin_decl_stmt
name|int
name|max
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|t
decl_stmt|;
if|if
condition|(
name|max
operator|<=
literal|0
condition|)
return|return
operator|(
literal|0
operator|)
return|;
name|t
operator|=
name|rand
argument_list|()
operator|>>
literal|5
expr_stmt|;
return|return
operator|(
name|t
operator|%
name|max
operator|)
return|;
block|}
end_block

begin_function
name|double
name|franf
parameter_list|()
block|{
name|double
name|t
decl_stmt|;
name|t
operator|=
name|rand
argument_list|()
operator|&
literal|077777
expr_stmt|;
return|return
operator|(
name|t
operator|/
literal|32767.0
operator|)
return|;
block|}
end_function

end_unit

