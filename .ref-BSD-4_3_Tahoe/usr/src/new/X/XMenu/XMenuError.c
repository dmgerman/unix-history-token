begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: XMenuError.c,v 10.6 86/02/12 16:19:08 tony Rel $ */
end_comment

begin_comment
comment|/* Copyright    Massachusetts Institute of Technology    1985	*/
end_comment

begin_comment
comment|/*  * XMenu:	MIT Project Athena, X Window system menu package  *  * 	XMenuError -	Returns a string description of the current  *			XMenu error status flag.  *  *	Author:		Tony Della Fera, DEC  *			August, 1985  *  */
end_comment

begin_include
include|#
directive|include
file|"XMenuInternal.h"
end_include

begin_function
name|char
modifier|*
name|XMenuError
parameter_list|()
block|{
name|char
name|message
index|[
literal|128
index|]
decl_stmt|;
comment|/* Error message buffer. */
if|if
condition|(
operator|(
name|_XMErrorCode
operator|<
name|XME_CODE_COUNT
operator|)
operator|&&
operator|(
name|_XMErrorCode
operator|>=
literal|0
operator|)
condition|)
block|{
return|return
operator|(
name|_XMErrorList
index|[
name|_XMErrorCode
index|]
operator|)
return|;
block|}
name|sprintf
argument_list|(
name|message
argument_list|,
literal|"Unknown _XMErrorCode: %d"
argument_list|,
name|_XMErrorCode
argument_list|)
expr_stmt|;
return|return
operator|(
name|message
operator|)
return|;
block|}
end_function

end_unit

