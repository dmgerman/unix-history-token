begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XCompEvents.c,v 10.4 86/02/01 15:30:42 tony Rel $ */
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
comment|/*  * XCompressEvents - Compress MouseMoved events such that only the last  * contiguous MouseMoved event is returned.  */
end_comment

begin_macro
name|XCompressEvents
argument_list|()
end_macro

begin_block
block|{
name|_XlibCurrentDisplay
operator|->
name|squish
operator|=
literal|1
expr_stmt|;
block|}
end_block

end_unit

