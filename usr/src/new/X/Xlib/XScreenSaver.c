begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XScreenSaver.c,v 10.6 86/04/22 15:27:55 jg Rel $ */
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
name|XScreenSaver
argument_list|(
argument|save_timeout
argument_list|,
argument|pattern_timeout
argument_list|,
argument|video
argument_list|)
end_macro

begin_decl_stmt
name|int
name|save_timeout
decl_stmt|,
name|pattern_timeout
decl_stmt|,
name|video
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
name|X_ScreenSaver
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|req
operator|->
name|func
operator|=
name|video
condition|?
literal|1
else|:
literal|0
expr_stmt|;
name|req
operator|->
name|params0
operator|=
name|save_timeout
expr_stmt|;
name|req
operator|->
name|params1
operator|=
name|pattern_timeout
expr_stmt|;
block|}
end_block

end_unit

