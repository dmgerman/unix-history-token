begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XExpandEvents.c,v 10.4 86/02/01 15:33:09 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_include
include|#
directive|include
file|"XlibInternal.h"
end_include

begin_comment
comment|/*  * XExpandEvents - Compress MouseMoved events such that all MouseMoved  * events that are recieved are returned.  */
end_comment

begin_macro
name|XExpandEvents
argument_list|()
end_macro

begin_block
block|{
name|_XlibCurrentDisplay
operator|->
name|squish
operator|=
literal|0
expr_stmt|;
block|}
end_block

end_unit

