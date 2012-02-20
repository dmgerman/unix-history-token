begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*$Header: /p/tcsh/cvsroot/tcsh/win32/dirent.h,v 1.6 2006/03/03 22:08:45 amold Exp $*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1980, 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * dirent.h  * directory interface functions. Sort of like dirent functions on unix.  * -amol  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DIRENT_H
end_ifndef

begin_define
define|#
directive|define
name|DIRENT_H
end_define

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_define
define|#
directive|define
name|heap_alloc
parameter_list|(
name|s
parameter_list|)
value|HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
end_define

begin_define
define|#
directive|define
name|heap_free
parameter_list|(
name|p
parameter_list|)
value|HeapFree(GetProcessHeap(),0,(p))
end_define

begin_define
define|#
directive|define
name|heap_realloc
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
value|HeapReAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(p),(s))
end_define

begin_define
define|#
directive|define
name|NAME_MAX
value|MAX_PATH
end_define

begin_define
define|#
directive|define
name|IS_ROOT
value|0x01
end_define

begin_define
define|#
directive|define
name|IS_NET
value|0x02
end_define

begin_struct
struct|struct
name|dirent
block|{
name|long
name|d_ino
decl_stmt|;
name|int
name|d_off
decl_stmt|;
name|unsigned
name|short
name|d_reclen
decl_stmt|;
name|char
name|d_name
index|[
name|NAME_MAX
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
block|{
name|HANDLE
name|dd_fd
decl_stmt|;
name|int
name|dd_loc
decl_stmt|;
name|int
name|dd_size
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|char
name|orig_dir_name
index|[
name|NAME_MAX
operator|+
literal|1
index|]
decl_stmt|;
name|struct
name|dirent
modifier|*
name|dd_buf
decl_stmt|;
block|}
name|DIR
typedef|;
end_typedef

begin_function_decl
name|DIR
modifier|*
name|opendir
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|dirent
modifier|*
name|readdir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|closedir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rewinddir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|DIRENT_H
end_endif

end_unit

