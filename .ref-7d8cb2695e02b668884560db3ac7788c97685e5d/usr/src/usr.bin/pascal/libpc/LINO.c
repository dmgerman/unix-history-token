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
literal|"@(#)LINO.c	1.4 (Berkeley) %G%"
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
file|"h00vars.h"
end_include

begin_decl_stmt
name|char
name|ELINO
index|[]
init|=
literal|"Statement count limit of %D exceeded\n"
decl_stmt|;
end_decl_stmt

begin_macro
name|LINO
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|++
name|_stcnt
operator|>=
name|_stlim
condition|)
block|{
name|ERROR
argument_list|(
name|ELINO
argument_list|,
name|_stcnt
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
end_block

end_unit

