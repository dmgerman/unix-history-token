begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XFeepControl.c,v 10.4 86/02/01 15:33:24 tony Rel $ */
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
comment|/*  * XFeepControl - Define the base volume for XFeep requests.  The volume  * is in the range 0 to 7 with 7 being the loudest.  */
end_comment

begin_macro
name|XFeepControl
argument_list|(
argument|volume
argument_list|)
end_macro

begin_decl_stmt
name|int
name|volume
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|Display
modifier|*
name|dpy
init|=
name|_XlibCurrentDisplay
decl_stmt|;
specifier|register
name|XReq
modifier|*
name|req
decl_stmt|;
name|GetReq
argument_list|(
name|X_FeepControl
argument_list|,
name|dpy
operator|->
name|root
argument_list|)
expr_stmt|;
name|req
operator|->
name|func
operator|=
name|volume
expr_stmt|;
block|}
end_block

end_unit

