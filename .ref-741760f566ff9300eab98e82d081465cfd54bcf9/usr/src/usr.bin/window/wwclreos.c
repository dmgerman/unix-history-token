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
literal|"@(#)wwclreos.c	3.5 %G%"
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

begin_expr_stmt
name|wwclreos
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
specifier|register
expr|struct
name|ww
operator|*
name|w
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|i
expr_stmt|;
name|wwclreol
argument_list|(
name|w
argument_list|,
name|row
argument_list|,
name|col
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
name|row
operator|+
literal|1
init|;
name|i
operator|<
name|w
operator|->
name|ww_b
operator|.
name|b
condition|;
name|i
operator|++
control|)
name|wwclreol
argument_list|(
name|w
argument_list|,
name|i
argument_list|,
name|w
operator|->
name|ww_b
operator|.
name|l
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

