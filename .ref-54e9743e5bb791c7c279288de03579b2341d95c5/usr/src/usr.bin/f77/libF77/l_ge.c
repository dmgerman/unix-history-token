begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)l_ge.c	5.2 (Berkeley) %G%"
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
name|long
name|int
name|l_ge
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|la
parameter_list|,
name|lb
parameter_list|)
name|char
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_decl_stmt
name|long
name|int
name|la
decl_stmt|,
name|lb
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|s_cmp
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|la
argument_list|,
name|lb
argument_list|)
operator|>=
literal|0
operator|)
return|;
block|}
end_block

end_unit

