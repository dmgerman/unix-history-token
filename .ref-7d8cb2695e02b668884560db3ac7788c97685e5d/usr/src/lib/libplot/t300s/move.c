begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)move.c	8.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_macro
name|move
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_block
block|{
name|movep
argument_list|(
name|xconv
argument_list|(
name|xsc
argument_list|(
name|xi
argument_list|)
argument_list|)
argument_list|,
name|yconv
argument_list|(
name|ysc
argument_list|(
name|yi
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_block

end_unit

