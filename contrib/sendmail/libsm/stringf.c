begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  */
end_comment

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_macro
name|SM_RCSID
argument_list|(
literal|"@(#)$Id: stringf.c,v 1.15 2001/09/11 04:04:49 gshapiro Exp $"
argument_list|)
end_macro

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sm/exc.h>
end_include

begin_include
include|#
directive|include
file|<sm/heap.h>
end_include

begin_include
include|#
directive|include
file|<sm/string.h>
end_include

begin_include
include|#
directive|include
file|<sm/varargs.h>
end_include

begin_comment
comment|/* **  SM_STRINGF_X -- printf() to dynamically allocated string. ** **	Takes the same arguments as printf. **	It returns a pointer to a dynamically allocated string **	containing the text that printf would print to standard output. **	It raises an exception on error. **	The name comes from a PWB Unix function called stringf. ** **	Parameters: **		fmt -- format string. **		... -- arguments for format. ** **	Returns: **		Pointer to a dynamically allocated string. ** **	Exceptions: **		F:sm_heap -- out of memory (via sm_vstringf_x()). */
end_comment

begin_function
name|char
modifier|*
if|#
directive|if
name|SM_VA_STD
name|sm_stringf_x
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
comment|/* SM_VA_STD */
function|sm_stringf_x
parameter_list|(
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
comment|/* SM_VA_STD */
block|{
name|SM_VA_LOCAL_DECL
name|char
modifier|*
name|s
decl_stmt|;
name|SM_VA_START
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|s
operator|=
name|sm_vstringf_x
argument_list|(
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|SM_VA_END
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|s
return|;
block|}
end_function

begin_comment
comment|/* **  SM_VSTRINGF_X -- printf() to dynamically allocated string. ** **	Parameters: **		fmt -- format string. **		ap -- arguments for format. ** **	Returns: **		Pointer to a dynamically allocated string. ** **	Exceptions: **		F:sm_heap -- out of memory */
end_comment

begin_function
name|char
modifier|*
name|sm_vstringf_x
parameter_list|(
name|fmt
parameter_list|,
name|ap
parameter_list|)
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
function|SM_VA_LOCAL_DECL
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|sm_vasprintf
argument_list|(
operator|&
name|s
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
name|errno
operator|==
name|ENOMEM
condition|)
name|sm_exc_raise_x
argument_list|(
operator|&
name|SmHeapOutOfMemory
argument_list|)
expr_stmt|;
name|sm_exc_raisenew_x
argument_list|(
operator|&
name|SmEtypeOs
argument_list|,
name|errno
argument_list|,
literal|"sm_vasprintf"
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
block|}
return|return
name|s
return|;
block|}
end_function

end_unit

