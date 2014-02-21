begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  * Copyright (c) 2009, Secure Endpoints Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * - Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  *  * - Redistributions in binary form must reproduce the above copyright  *   notice, this list of conditions and the following disclaimer in  *   the documentation and/or other materials provided with the  *   distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE  * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  *  **********************************************************************/
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_function
name|BOOL
name|WINAPI
name|DllMain
parameter_list|(
name|__in
name|HINSTANCE
name|hinstDLL
parameter_list|,
name|__in
name|DWORD
name|fdwReason
parameter_list|,
name|__in
name|LPVOID
name|lpvReserved
parameter_list|)
block|{
return|return
name|TRUE
return|;
block|}
end_function

end_unit

