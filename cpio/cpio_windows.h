begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Michihiro NAKAJIMA  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPIO_WINDOWS_H
end_ifndef

begin_define
define|#
directive|define
name|CPIO_WINDOWS_H
value|1
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|getgrgid
parameter_list|(
name|id
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|getgrnam
parameter_list|(
name|name
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|getpwnam
parameter_list|(
name|name
parameter_list|)
value|NULL
end_define

begin_define
define|#
directive|define
name|getpwuid
parameter_list|(
name|id
parameter_list|)
value|NULL
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
end_if

begin_if
if|#
directive|if
name|_MSC_VER
operator|<
literal|1900
end_if

begin_define
define|#
directive|define
name|snprintf
value|sprintf_s
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _MSC_VER< 1900
end_comment

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|passwd
block|{
name|char
modifier|*
name|pw_name
decl_stmt|;
name|uid_t
name|pw_uid
decl_stmt|;
name|gid_t
name|pw_gid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|group
block|{
name|char
modifier|*
name|gr_name
decl_stmt|;
name|gid_t
name|gr_gid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|_timeval64i32
block|{
name|time_t
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|__timeval
value|_timeval64i32
end_define

begin_function_decl
specifier|extern
name|int
name|futimes
parameter_list|(
name|int
name|fd
parameter_list|,
specifier|const
name|struct
name|__timeval
modifier|*
name|times
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_FUTIMES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_FUTIMES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|utimes
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|struct
name|__timeval
modifier|*
name|times
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTIMES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_UTIMES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPIO_WINDOWS_H */
end_comment

end_unit

