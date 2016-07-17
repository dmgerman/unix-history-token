begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Tim J. Robbins  * Copyright (c) 2002 Doug Rabson  * Copyright (c) 2000 Marcel Moolenaar  * Copyright (c) 1994-1995 SÃ¸ren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MMAP_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MMAP_H_
end_define

begin_comment
comment|/* mmap options */
end_comment

begin_define
define|#
directive|define
name|LINUX_MAP_SHARED
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_PRIVATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_FIXED
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_ANON
value|0x0020
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_GROWSDOWN
value|0x0100
end_define

begin_function_decl
name|int
name|linux_mmap_common
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|off_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|linux_mprotect_common
parameter_list|(
name|struct
name|thread
modifier|*
parameter_list|,
name|uintptr_t
parameter_list|,
name|size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MMAP_H_ */
end_comment

end_unit

