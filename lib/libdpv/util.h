begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<paths.h>
end_include

begin_define
define|#
directive|define
name|SHELL_SPAWN_DEBUG
value|0
end_define

begin_comment
comment|/* Debug spawning of sh(1) commands */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_PATH_BSHELL
end_ifdef

begin_define
define|#
directive|define
name|PATH_SHELL
value|_PATH_BSHELL
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PATH_SHELL
value|"/bin/sh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CMDBUFMAX
value|4096
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|shell_spawn_pipecmd
parameter_list|(
specifier|const
name|char
modifier|*
name|_cmd
parameter_list|,
specifier|const
name|char
modifier|*
name|_label
parameter_list|,
name|pid_t
modifier|*
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_UTIL_H_ */
end_comment

end_unit

