begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XKeyClickCon.c,v 10.4 86/02/01 15:36:00 tony Rel $ */
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
comment|/*  * XKeyClickControl  -  Controls the volume of the "click" that the  * keyboard makes when a key is pressed.  0 if "off", 8 is the loudest  * volume.  Initially volume is set to 6.  */
end_comment

begin_macro
name|XKeyClickControl
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
name|X_KeyClick
argument_list|,
literal|0
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

