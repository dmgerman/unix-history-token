begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 John Baldwin  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RTLD_UTRACE_H
end_ifndef

begin_define
define|#
directive|define
name|RTLD_UTRACE_H
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|UTRACE_DLOPEN_START
value|1
end_define

begin_define
define|#
directive|define
name|UTRACE_DLOPEN_STOP
value|2
end_define

begin_define
define|#
directive|define
name|UTRACE_DLCLOSE_START
value|3
end_define

begin_define
define|#
directive|define
name|UTRACE_DLCLOSE_STOP
value|4
end_define

begin_define
define|#
directive|define
name|UTRACE_LOAD_OBJECT
value|5
end_define

begin_define
define|#
directive|define
name|UTRACE_UNLOAD_OBJECT
value|6
end_define

begin_define
define|#
directive|define
name|UTRACE_ADD_RUNDEP
value|7
end_define

begin_define
define|#
directive|define
name|UTRACE_PRELOAD_FINISHED
value|8
end_define

begin_define
define|#
directive|define
name|UTRACE_INIT_CALL
value|9
end_define

begin_define
define|#
directive|define
name|UTRACE_FINI_CALL
value|10
end_define

begin_define
define|#
directive|define
name|UTRACE_DLSYM_START
value|11
end_define

begin_define
define|#
directive|define
name|UTRACE_DLSYM_STOP
value|12
end_define

begin_define
define|#
directive|define
name|UTRACE_RTLD_ERROR
value|13
end_define

begin_define
define|#
directive|define
name|RTLD_UTRACE_SIG_SZ
value|4
end_define

begin_define
define|#
directive|define
name|RTLD_UTRACE_SIG
value|"RTLD"
end_define

begin_struct
struct|struct
name|utrace_rtld
block|{
name|char
name|sig
index|[
name|RTLD_UTRACE_SIG_SZ
index|]
decl_stmt|;
name|int
name|event
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|void
modifier|*
name|mapbase
decl_stmt|;
comment|/* Used for 'parent' and 'init/fini' */
name|size_t
name|mapsize
decl_stmt|;
name|int
name|refcnt
decl_stmt|;
comment|/* Used for 'mode' */
name|char
name|name
index|[
name|MAXPATHLEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

