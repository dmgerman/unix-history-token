begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	misc.c	7.1	88/05/21	*/
end_comment

begin_include
include|#
directive|include
file|"../h/types.h"
end_include

begin_include
include|#
directive|include
file|"../tahoe/mtpr.h"
end_include

begin_comment
comment|/*  * make sure addr is not in cache  */
end_comment

begin_macro
name|uncache
argument_list|(
argument|addr
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|addr
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|mtpr
argument_list|(
name|PDCS
argument_list|,
name|addr
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

