begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)wwputc.c	3.4 %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Copyright (c) 1983 Regents of the University of California,  * All rights reserved.  Redistribution permitted subject to  * the terms of the Berkeley Software License Agreement.  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_macro
name|wwputc
argument_list|(
argument|c
argument_list|,
argument|w
argument_list|)
end_macro

begin_decl_stmt
name|char
name|c
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|w
decl_stmt|;
end_decl_stmt

begin_block
block|{
operator|(
name|void
operator|)
name|wwwrite
argument_list|(
name|w
argument_list|,
operator|&
name|c
argument_list|,
sizeof|sizeof
name|c
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

