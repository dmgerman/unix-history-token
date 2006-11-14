begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-nextstep.h,v 1.9 2003/08/29 16:59:52 mouring Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000,2001 Ben Lindstrom.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NEXT_POSIX_H
end_ifndef

begin_define
define|#
directive|define
name|_NEXT_POSIX_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NEXT
end_ifdef

begin_include
include|#
directive|include
file|<sys/dir.h>
end_include

begin_comment
comment|/* NGROUPS_MAX is behind -lposix.  Use the BSD version which is NGROUPS */
end_comment

begin_undef
undef|#
directive|undef
name|NGROUPS_MAX
end_undef

begin_define
define|#
directive|define
name|NGROUPS_MAX
value|NGROUPS
end_define

begin_comment
comment|/* NeXT's readdir() is BSD (struct direct) not POSIX (struct dirent) */
end_comment

begin_define
define|#
directive|define
name|dirent
value|direct
end_define

begin_comment
comment|/* Swap out NeXT's BSD wait() for a more POSIX complient one */
end_comment

begin_function_decl
name|pid_t
name|posix_wait
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|wait
parameter_list|(
name|a
parameter_list|)
value|posix_wait(a)
end_define

begin_comment
comment|/* #ifdef wrapped functions that need defining for clean compiling */
end_comment

begin_function_decl
name|pid_t
name|getppid
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vhangup
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|innetgr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* TERMCAP */
end_comment

begin_function_decl
name|int
name|tcgetattr
parameter_list|(
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetattr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tcsetpgrp
parameter_list|(
name|int
parameter_list|,
name|pid_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|speed_t
name|cfgetospeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|speed_t
name|cfgetispeed
parameter_list|(
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetospeed
parameter_list|(
name|struct
name|termios
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfsetispeed
parameter_list|(
name|struct
name|termios
modifier|*
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
comment|/* HAVE_NEXT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NEXT_POSIX_H */
end_comment

end_unit

