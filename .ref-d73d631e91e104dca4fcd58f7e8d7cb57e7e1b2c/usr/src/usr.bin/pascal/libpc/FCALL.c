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
literal|"@(#)FCALL.c	1.5 (Berkeley) %G%"
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

begin_macro
name|FCALL
argument_list|(
argument|save
argument_list|,
argument|frtn
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|save
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|struct
name|formalrtn
modifier|*
name|frtn
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|blkcpy
argument_list|(
operator|&
name|_disply
index|[
literal|1
index|]
argument_list|,
name|save
argument_list|,
name|frtn
operator|->
name|fbn
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|display
argument_list|)
argument_list|)
expr_stmt|;
name|blkcpy
argument_list|(
operator|&
name|frtn
operator|->
name|fdisp
index|[
literal|0
index|]
argument_list|,
operator|&
name|_disply
index|[
literal|1
index|]
argument_list|,
name|frtn
operator|->
name|fbn
operator|*
sizeof|sizeof
argument_list|(
expr|struct
name|display
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

