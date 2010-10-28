begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999  * NetGroup, Politecnico di Torino (Italy)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in the  * documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Politecnico di Torino nor the names of its  * contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINSOCKAPI_
end_ifndef

begin_define
define|#
directive|define
name|_WINSOCKAPI_
end_define

begin_comment
comment|/* Prevent inclusion of winsock.h in windows.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WINSOCKAPI_ */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|progress
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|wsockinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InitP
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|PrintCapBegins
parameter_list|(
name|char
modifier|*
name|program_name
parameter_list|,
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|AdapterName1
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|WIN95
end_ifndef

begin_function_decl
name|WCHAR
modifier|*
name|SChar2WChar
parameter_list|(
name|char
modifier|*
name|nome
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
name|BOOLEAN
name|StartPacketDriver
parameter_list|(
name|LPTSTR
name|ServiceName
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

