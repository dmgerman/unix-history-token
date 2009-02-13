begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MIB_H_
end_define

begin_function_decl
name|void
name|linux_get_osname
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_set_osname
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|osname
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|linux_get_osrelease
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|dst
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_set_osrelease
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|char
modifier|*
name|osrelease
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_get_oss_version
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_set_oss_version
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
name|oss_version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_use26
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MIB_H_ */
end_comment

end_unit

