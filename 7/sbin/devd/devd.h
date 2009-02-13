begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * DEVD (Device action daemon)  *  * Copyright (c) 2002 M. Warner Losh<imp@freebsd.org>.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEVD_H
end_ifndef

begin_define
define|#
directive|define
name|DEVD_H
end_define

begin_comment
comment|/** @warning This file needs to be purely 'C' compatible.  */
end_comment

begin_struct_decl
struct_decl|struct
name|event_proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eps
struct_decl|;
end_struct_decl

begin_function_decl
name|__BEGIN_DECLS
name|void
name|add_attach
parameter_list|(
name|int
parameter_list|,
name|struct
name|event_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_detach
parameter_list|(
name|int
parameter_list|,
name|struct
name|event_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_directory
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_nomatch
parameter_list|(
name|int
parameter_list|,
name|struct
name|event_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|add_notify
parameter_list|(
name|int
parameter_list|,
name|struct
name|event_proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|event_proc
modifier|*
name|add_to_event_proc
parameter_list|(
name|struct
name|event_proc
modifier|*
parameter_list|,
name|struct
name|eps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|eps
modifier|*
name|new_match
parameter_list|(
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

begin_function_decl
name|struct
name|eps
modifier|*
name|new_media
parameter_list|(
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

begin_function_decl
name|struct
name|eps
modifier|*
name|new_action
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_pidfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|set_variable
parameter_list|(
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

begin_function_decl
name|void
name|yyerror
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yylex
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|yyparse
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_define
define|#
directive|define
name|PATH_DEVCTL
value|"/dev/devctl"
end_define

begin_define
define|#
directive|define
name|DEVCTL_MAXBUF
value|1025
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEVD_H */
end_comment

end_unit

