begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XCloseFont.c,v 10.4 86/02/01 15:30:35 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_macro
name|XCloseFont
argument_list|(
argument|info
argument_list|)
end_macro

begin_decl_stmt
name|FontInfo
modifier|*
name|info
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|XFreeFont
argument_list|(
name|info
operator|->
name|id
argument_list|)
expr_stmt|;
if|if
condition|(
name|info
operator|->
name|widths
condition|)
name|free
argument_list|(
name|info
operator|->
name|widths
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|info
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

