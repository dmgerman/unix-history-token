begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)wwend.c	3.15 (Berkeley) %G%"
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
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|"tt.h"
end_include

begin_macro
name|wwend
argument_list|()
end_macro

begin_block
block|{
name|xxend
argument_list|()
expr_stmt|;
operator|(
name|void
operator|)
name|wwsettty
argument_list|(
literal|0
argument_list|,
operator|&
name|wwoldtty
argument_list|,
operator|&
name|wwnewtty
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

