begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: bsd-cygwin_util.h,v 1.12 2009/03/08 00:40:28 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001, Corinna Vinschen<vinschen@cygnus.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * Created: Sat Sep 02 12:17:00 2000 cv  *  * This file contains functions for forcing opened file descriptors to  * binary mode on Windows systems.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD_CYGWIN_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|_BSD_CYGWIN_UTIL_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CYGWIN
end_ifdef

begin_undef
undef|#
directive|undef
name|ERROR
end_undef

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<sys/cygwin.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_function_decl
name|int
name|binary_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|binary_pipe
parameter_list|(
name|int
name|fd
index|[
literal|2
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|check_ntsec
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|fetch_windows_environment
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_windows_environment
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|open
value|binary_open
end_define

begin_define
define|#
directive|define
name|pipe
value|binary_pipe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CYGWIN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BSD_CYGWIN_UTIL_H */
end_comment

end_unit

