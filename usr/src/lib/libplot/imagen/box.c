begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)box.c	5.2 (Berkeley) %G%"
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
name|box
argument_list|(
argument|x0
argument_list|,
argument|y0
argument_list|,
argument|x1
argument_list|,
argument|y1
argument_list|)
end_macro

begin_block
block|{
name|move
argument_list|(
name|x0
argument_list|,
name|y0
argument_list|)
expr_stmt|;
name|cont
argument_list|(
name|x0
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|cont
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
name|cont
argument_list|(
name|x1
argument_list|,
name|y0
argument_list|)
expr_stmt|;
name|cont
argument_list|(
name|x0
argument_list|,
name|y0
argument_list|)
expr_stmt|;
name|move
argument_list|(
name|x1
argument_list|,
name|y1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

