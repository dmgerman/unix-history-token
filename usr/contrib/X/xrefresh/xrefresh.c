begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Copyright 1985, Massachusetts Institute of Technology.  * This program just throws up a window over the whole screen, causing  * exposure events to be generated on all windows.  This may be useful  * to cause the whole screen to be repainted when it has somehow gotten  * trashed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_xrefresh_c
init|=
literal|"$Header: xrefresh.c,v 10.5 86/02/01 16:16:40 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|Window
name|w
decl_stmt|;
if|if
condition|(
name|XOpenDisplay
argument_list|(
name|argc
condition|?
name|argv
index|[
literal|1
index|]
else|:
literal|"\0"
argument_list|)
operator|==
name|NULL
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Could not open Display!\n"
argument_list|)
expr_stmt|;
name|w
operator|=
name|XCreateWindow
argument_list|(
name|RootWindow
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
name|DisplayWidth
argument_list|()
argument_list|,
name|DisplayHeight
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|(
name|Pixmap
operator|)
literal|0
argument_list|,
operator|(
name|Pixmap
operator|)
literal|0
argument_list|)
expr_stmt|;
name|XMapWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|/* put it up on the screen 	*/
name|XDestroyWindow
argument_list|(
name|w
argument_list|)
expr_stmt|;
comment|/* throw it away		*/
name|XFlush
argument_list|()
expr_stmt|;
comment|/* and make sure the server sees it*/
block|}
end_function

end_unit

