begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XAppendBuffer.c,v 1.1 86/04/11 23:21:58 newman Rel $ */
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
name|XAppendToBuffer
argument_list|(
argument|str
argument_list|,
argument|length
argument_list|,
argument|buffer
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|length
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
name|GetReq
argument_list|(
name|X_AppendBytes
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|params0
operator|=
name|length
expr_stmt|;
name|req
operator|->
name|func
operator|=
name|buffer
expr_stmt|;
name|Data
argument_list|(
name|dpy
argument_list|,
name|str
argument_list|,
name|length
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

