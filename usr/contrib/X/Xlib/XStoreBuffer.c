begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XStoreBuffer.c,v 10.4 86/02/01 15:39:58 tony Rel $ */
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
name|XStoreBuffer
argument_list|(
argument|str
argument_list|,
argument|nbytes
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
name|nbytes
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
name|X_StoreBytes
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|param
operator|.
name|s
index|[
literal|0
index|]
operator|=
name|nbytes
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
name|nbytes
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

