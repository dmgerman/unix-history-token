begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_macro
name|yerror
argument_list|(
argument|s
argument_list|,
argument|a1
argument_list|,
argument|a2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|error
argument_list|(
name|s
argument_list|,
name|a1
argument_list|,
name|a2
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

