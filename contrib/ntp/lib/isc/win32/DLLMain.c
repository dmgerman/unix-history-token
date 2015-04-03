begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004, 2007  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: DLLMain.c,v 1.7 2007/06/18 23:47:49 tbox Exp $ */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Called when we enter the DLL  */
end_comment

begin_macro
name|__declspec
argument_list|(
argument|dllexport
argument_list|)
end_macro

begin_function
name|BOOL
name|WINAPI
name|DllMain
parameter_list|(
name|HINSTANCE
name|hinstDLL
parameter_list|,
name|DWORD
name|fdwReason
parameter_list|,
name|LPVOID
name|lpvReserved
parameter_list|)
block|{
switch|switch
condition|(
name|fdwReason
condition|)
block|{
comment|/* 	 * The DLL is loading due to process  	 * initialization or a call to LoadLibrary.  	 */
case|case
name|DLL_PROCESS_ATTACH
case|:
break|break;
comment|/* The attached process creates a new thread.  */
case|case
name|DLL_THREAD_ATTACH
case|:
break|break;
comment|/* The thread of the attached process terminates. */
case|case
name|DLL_THREAD_DETACH
case|:
break|break;
comment|/* 	 * The DLL is unloading from a process due to  	 * process termination or a call to FreeLibrary.  	 */
case|case
name|DLL_PROCESS_DETACH
case|:
break|break;
default|default:
break|break;
block|}
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

end_unit

