begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XStoreName.c,v 10.5 86/04/22 15:30:11 jg Rel $ */
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
name|XStoreName
argument_list|(
argument|w
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|Window
name|w
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
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
name|int
name|len
decl_stmt|;
name|GetReq
argument_list|(
name|X_StoreName
argument_list|,
name|w
argument_list|)
expr_stmt|;
name|len
operator|=
name|req
operator|->
name|params0
operator|=
name|strlen
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|Data
argument_list|(
name|dpy
argument_list|,
name|name
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

