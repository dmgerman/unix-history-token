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
literal|"@(#)cont.c	5.2 (Berkeley) 4/30/85"
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
file|"bg.h"
end_include

begin_macro
name|cont
argument_list|(
argument|xi
argument_list|,
argument|yi
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xi
decl_stmt|,
name|yi
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|currentx
operator|=
name|scaleX
argument_list|(
name|xi
argument_list|)
expr_stmt|;
name|currenty
operator|=
name|scaleY
argument_list|(
name|yi
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|":%d;%dd"
argument_list|,
name|currentx
argument_list|,
name|currenty
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

