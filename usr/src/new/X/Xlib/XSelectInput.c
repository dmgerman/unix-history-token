begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XSelectInput.c,v 10.5 86/04/22 15:16:52 jg Rel $ */
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
name|XSelectInput
argument_list|(
argument|w
argument_list|,
argument|mask
argument_list|)
end_macro

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|mask
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|Display
modifier|*
name|dpy
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
name|GetReq
argument_list|(
name|X_SelectInput
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|req
operator|->
name|param
operator|.
name|l
index|[
literal|0
index|]
operator|=
name|mask
expr_stmt|;
block|}
end_block

end_unit

