begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XFeep.c,v 10.5 86/04/22 15:28:06 jg Rel $ */
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
comment|/*  * XFeep - Ring the display's bell.  The sound volume is in the range -7  * to 7 and is added to the base volume as defined by XFeepControl.  Large  * numbers represent louder volumes.  */
end_comment

begin_macro
name|XFeep
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
name|X_Feep
argument_list|,
name|dpy
operator|->
name|root
argument_list|)
expr_stmt|;
name|req
operator|->
name|params0
operator|=
name|volume
expr_stmt|;
block|}
end_block

end_unit

