begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)dot.c	5.1 (Berkeley) 6/7/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_macro
name|dot_
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|,
argument|dx
argument_list|,
argument|n
argument_list|,
argument|pat
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|xi
decl_stmt|,
modifier|*
name|yi
decl_stmt|,
modifier|*
name|dx
decl_stmt|,
modifier|*
name|n
decl_stmt|,
modifier|*
name|pat
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|dot
argument_list|(
operator|*
name|xi
argument_list|,
operator|*
name|yi
argument_list|,
operator|*
name|dx
argument_list|,
operator|*
name|n
argument_list|,
name|pat
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

