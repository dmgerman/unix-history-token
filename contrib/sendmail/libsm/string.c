begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Sendmail, Inc. and its suppliers.  *      All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: string.c,v 1.3 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sm/string.h>
end_include

begin_comment
comment|/* **  STRIPQUOTES -- Strip quotes& quote bits from a string. ** **	Runs through a string and strips off unquoted quote **	characters and quote bits.  This is done in place. ** **	Parameters: **		s -- the string to strip. ** **	Returns: **		none. ** **	Side Effects: **		none. */
end_comment

begin_function
name|void
name|stripquotes
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|;
specifier|register
name|char
modifier|*
name|q
decl_stmt|;
specifier|register
name|char
name|c
decl_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
return|return;
name|p
operator|=
name|q
operator|=
name|s
expr_stmt|;
do|do
block|{
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
if|if
condition|(
name|c
operator|==
literal|'\\'
condition|)
name|c
operator|=
operator|*
name|p
operator|++
expr_stmt|;
elseif|else
if|if
condition|(
name|c
operator|==
literal|'"'
condition|)
continue|continue;
operator|*
name|q
operator|++
operator|=
name|c
expr_stmt|;
block|}
do|while
condition|(
name|c
operator|!=
literal|'\0'
condition|)
do|;
block|}
end_function

end_unit

