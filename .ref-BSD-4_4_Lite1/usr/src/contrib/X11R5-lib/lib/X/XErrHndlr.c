begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $XConsortium: XErrHndlr.c,v 11.15 91/01/24 11:10:03 rws Exp $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1986	*/
end_comment

begin_comment
comment|/* Permission to use, copy, modify, distribute, and sell this software and its documentation for any purpose is hereby granted without fee, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_include
include|#
directive|include
file|"Xlibint.h"
end_include

begin_function_decl
specifier|extern
name|int
name|_XDefaultError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|_XDefaultIOError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*   * XErrorHandler - This procedure sets the X non-fatal error handler  * (_XErrorFunction) to be the specified routine.  If NULL is passed in  * the original error handler is restored.  */
end_comment

begin_function
name|XErrorHandler
name|XSetErrorHandler
parameter_list|(
name|handler
parameter_list|)
specifier|register
name|XErrorHandler
name|handler
decl_stmt|;
block|{
name|int
function_decl|(
modifier|*
name|oldhandler
function_decl|)
parameter_list|()
init|=
name|_XErrorFunction
function_decl|;
if|if
condition|(
operator|!
name|oldhandler
condition|)
name|oldhandler
operator|=
name|_XDefaultError
expr_stmt|;
if|if
condition|(
name|handler
operator|!=
name|NULL
condition|)
block|{
name|_XErrorFunction
operator|=
name|handler
expr_stmt|;
block|}
else|else
block|{
name|_XErrorFunction
operator|=
name|_XDefaultError
expr_stmt|;
block|}
return|return
name|oldhandler
return|;
block|}
end_function

begin_comment
comment|/*   * XIOErrorHandler - This procedure sets the X fatal I/O error handler  * (_XIOErrorFunction) to be the specified routine.  If NULL is passed in   * the original error handler is restored.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|_XIOError
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|XIOErrorHandler
name|XSetIOErrorHandler
parameter_list|(
name|handler
parameter_list|)
specifier|register
name|XIOErrorHandler
name|handler
decl_stmt|;
block|{
name|int
function_decl|(
modifier|*
name|oldhandler
function_decl|)
parameter_list|()
init|=
name|_XIOErrorFunction
function_decl|;
if|if
condition|(
operator|!
name|oldhandler
condition|)
name|oldhandler
operator|=
name|_XDefaultIOError
expr_stmt|;
if|if
condition|(
name|handler
operator|!=
name|NULL
condition|)
block|{
name|_XIOErrorFunction
operator|=
name|handler
expr_stmt|;
block|}
else|else
block|{
name|_XIOErrorFunction
operator|=
name|_XDefaultIOError
expr_stmt|;
block|}
return|return
name|oldhandler
return|;
block|}
end_function

end_unit

