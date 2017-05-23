begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Gleb Kurtsou<gleb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEN_COMPAT_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEN_COMPAT_H_
end_define

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_define
define|#
directive|define
name|FREEBSD11_DIRSIZ
parameter_list|(
name|dp
parameter_list|)
define|\
value|(sizeof(struct freebsd11_dirent) - sizeof((dp)->d_name) +	\ 	    (((dp)->d_namlen + 1 + 3)&~ 3))
end_define

begin_struct_decl
struct_decl|struct
name|freebsd11_dirent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|freebsd11_stat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|freebsd11_statfs
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|freebsd11_dirent
modifier|*
name|freebsd11_readdir
parameter_list|(
name|DIR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_readdir_r
parameter_list|(
name|DIR
modifier|*
parameter_list|,
name|struct
name|freebsd11_dirent
modifier|*
parameter_list|,
name|struct
name|freebsd11_dirent
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_stat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_lstat
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_fstat
parameter_list|(
name|int
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_fstatat
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_stat
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_statfs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|freebsd11_statfs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_getfsstat
parameter_list|(
name|struct
name|freebsd11_statfs
modifier|*
parameter_list|,
name|long
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|freebsd11_getmntinfo
parameter_list|(
name|struct
name|freebsd11_statfs
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|freebsd11_devname
parameter_list|(
name|__uint32_t
name|dev
parameter_list|,
name|__mode_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|freebsd11_devname_r
parameter_list|(
name|__uint32_t
name|dev
parameter_list|,
name|__mode_t
name|type
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _GEN_COMPAT_H_ */
end_comment

end_unit

