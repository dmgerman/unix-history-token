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
literal|"@(#)yycopy.c	5.1 (Berkeley) 6/5/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"whoami.h"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree_ty.h"
end_include

begin_comment
comment|/* must be included for yy.h */
end_comment

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_macro
name|OYcopy
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
modifier|*
name|r0
init|=
operator|(
operator|(
name|int
operator|*
operator|)
operator|&
name|OY
operator|)
decl_stmt|;
specifier|register
name|int
modifier|*
name|r1
init|=
operator|(
operator|(
name|int
operator|*
operator|)
operator|&
name|Y
operator|)
decl_stmt|;
specifier|register
name|int
name|r2
init|=
operator|(
sizeof|sizeof
argument_list|(
expr|struct
name|yytok
argument_list|)
operator|)
operator|/
operator|(
sizeof|sizeof
argument_list|(
name|int
argument_list|)
operator|)
decl_stmt|;
do|do
block|{
operator|*
name|r0
operator|++
operator|=
operator|*
name|r1
operator|++
expr_stmt|;
block|}
do|while
condition|(
operator|--
name|r2
operator|>
literal|0
condition|)
do|;
block|}
end_block

end_unit

