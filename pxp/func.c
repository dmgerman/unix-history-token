begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.0 August 1977  */
end_comment

begin_include
include|#
directive|include
file|"whoami"
end_include

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_comment
comment|/*  * A function call  */
end_comment

begin_macro
name|funccod
argument_list|(
argument|r
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|r
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|call
argument_list|(
name|r
index|[
literal|1
index|]
argument_list|,
name|r
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

