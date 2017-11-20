begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007-2009 Google Inc.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *   * * Redistributions of source code must retain the above copyright  *   notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above  *   copyright notice, this list of conditions and the following disclaimer  *   in the documentation and/or other materials provided with the  *   distribution.  * * Neither the name of Google Inc. nor the names of its  *   contributors may be used to endorse or promote products derived from  *   this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *   * Copyright (C) 2005 Csaba Henk.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_comment
comment|/* Debug related stuff */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUSE_DEBUG_MODULE
end_ifndef

begin_error
error|#
directive|error
literal|"FUSE_DEBUG_MODULE is not defined"
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FUSE_DEBUG_VAR
value|__CONCAT(FUSE_DEBUG_,FUSE_DEBUG_MODULE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FS_DEBUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|DEBUGX(FUSE_DEBUG_VAR>= 1, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|FS_DEBUG2G
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|DEBUGX(FUSE_DEBUG_VAR>= 2, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|debug_printf
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|FS_DEBUG(fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|kdebug_printf
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|FS_DEBUG(fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|fuse_trace_printf
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|DEBUGX(FUSE_DEBUG_VAR&& FUSE_TRACE, fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|fuse_trace_printf_func
parameter_list|()
define|\
value|fuse_trace_printf("%s:%d\n", __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|fuse_trace_printf_vfsop
parameter_list|()
value|fuse_trace_printf_func()
end_define

begin_define
define|#
directive|define
name|fuse_trace_printf_vnop
parameter_list|()
value|fuse_trace_printf_func()
end_define

end_unit

