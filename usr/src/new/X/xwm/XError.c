begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * 	XError - non-fatal error reporting routine.  Called when an  * 	X_Error packet is encountered in the input stream.  *  *	File:		XError.c  */
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
name|rcsid_XError_c
init|=
literal|"$Header: XError.c,v 10.3 86/02/01 16:10:25 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"xwm.h"
end_include

begin_macro
name|XError
argument_list|(
argument|dpy
argument_list|,
argument|rep
argument_list|)
end_macro

begin_decl_stmt
name|Display
modifier|*
name|dpy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|XErrorEvent
modifier|*
name|rep
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|Debug
condition|)
return|return;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"xwm: X error occured during an xwm operation.\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Description: '%s'\n"
argument_list|,
name|XErrDescrip
argument_list|(
name|rep
operator|->
name|error_code
argument_list|)
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Request code: %d\n"
argument_list|,
name|rep
operator|->
name|request_code
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Request function: %d\n"
argument_list|,
name|rep
operator|->
name|func
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Request window 0x%x\n"
argument_list|,
name|rep
operator|->
name|window
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Error Serial #%d\n"
argument_list|,
name|rep
operator|->
name|serial
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"     Current serial #%d\n"
argument_list|,
name|dpy
operator|->
name|request
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\n"
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

