begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999-2000 Damien Miller.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id: bsd-misc.h,v 1.6 2002/06/13 21:34:58 mouring Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_MISC_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_MISC_H
end_define

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_function_decl
name|char
modifier|*
name|get_progname
parameter_list|(
name|char
modifier|*
name|argv0
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETSID
end_ifndef

begin_define
define|#
directive|define
name|setsid
parameter_list|()
value|setpgrp(0, getpid())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETSID */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETENV
end_ifndef

begin_function_decl
name|int
name|setenv
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|int
name|overwrite
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETENV */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SETLOGIN
end_ifndef

begin_function_decl
name|int
name|setlogin
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_SETLOGIN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_INNETGR
end_ifndef

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
name|netgroup
parameter_list|,
specifier|const
name|char
modifier|*
name|host
parameter_list|,
specifier|const
name|char
modifier|*
name|user
parameter_list|,
specifier|const
name|char
modifier|*
name|domain
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_INNETGR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETEUID
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETREUID
argument_list|)
end_if

begin_function_decl
name|int
name|seteuid
parameter_list|(
name|uid_t
name|euid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SETEUID)&& defined(HAVE_SETREUID) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETEGID
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SETRESGID
argument_list|)
end_if

begin_function_decl
name|int
name|setegid
parameter_list|(
name|uid_t
name|egid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_SETEGID)&& defined(HAVE_SETRESGID) */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_STRERROR
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_ERRLIST
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SYS_NERR
argument_list|)
end_if

begin_function_decl
specifier|const
name|char
modifier|*
name|strerror
parameter_list|(
name|int
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UTIMES
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_STRUCT_TIMEVAL
end_ifndef

begin_struct
struct|struct
name|timeval
block|{
name|long
name|tv_sec
decl_stmt|;
name|long
name|tv_usec
decl_stmt|;
block|}
endif|#
directive|endif
comment|/* HAVE_STRUCT_TIMEVAL */
name|int
name|utimes
argument_list|(
name|char
operator|*
name|filename
argument_list|,
expr|struct
name|timeval
operator|*
name|tvp
argument_list|)
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_UTIMES */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TRUNCATE
end_ifndef

begin_function_decl
name|int
name|truncate
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|off_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_TRUNCATE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SETGROUPS
argument_list|)
operator|&&
name|defined
argument_list|(
name|SETGROUPS_NOOP
argument_list|)
end_if

begin_function_decl
name|int
name|setgroups
parameter_list|(
name|size_t
name|size
parameter_list|,
specifier|const
name|gid_t
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_MISC_H */
end_comment

end_unit

