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
literal|"@(#)PCLOSE.c	1.7 (Berkeley) %G%"
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
comment|/*  * Close all files associated with the topmost stack frame.  */
end_comment

begin_include
include|#
directive|include
file|"h00vars.h"
end_include

begin_include
include|#
directive|include
file|"libpc.h"
end_include

begin_macro
name|PCLOSE
argument_list|(
argument|level
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|iorec
modifier|*
name|level
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|iorec
modifier|*
name|next
decl_stmt|;
name|next
operator|=
name|_fchain
operator|.
name|fchain
expr_stmt|;
while|while
condition|(
name|next
operator|!=
name|FILNIL
operator|&&
name|next
operator|->
name|flev
operator|<=
name|level
condition|)
block|{
name|next
operator|=
name|PFCLOSE
argument_list|(
name|next
argument_list|,
name|TRUE
argument_list|)
expr_stmt|;
block|}
name|_fchain
operator|.
name|fchain
operator|=
name|next
expr_stmt|;
block|}
end_block

end_unit

