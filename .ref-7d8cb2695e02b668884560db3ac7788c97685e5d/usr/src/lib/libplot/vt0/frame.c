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
literal|"@(#)frame.c	8.1 (Berkeley) %G%"
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
name|frame
argument_list|(
argument|n
argument_list|)
end_macro

begin_block
block|{
extern|extern vti;
name|n
operator|=
name|n
operator|&
literal|0377
operator||
literal|02000
expr_stmt|;
name|write
argument_list|(
name|vti
argument_list|,
operator|&
name|n
argument_list|,
literal|2
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

