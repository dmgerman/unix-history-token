begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCASPER_H_
end_ifndef

begin_define
define|#
directive|define
name|_LIBCASPER_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_NVLIST_T_DECLARED
end_ifndef

begin_define
define|#
directive|define
name|_NVLIST_T_DECLARED
end_define

begin_struct_decl
struct_decl|struct
name|nvlist
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|nvlist
name|nvlist_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PARENT_FILENO
value|3
end_define

begin_define
define|#
directive|define
name|EXECUTABLE_FILENO
value|4
end_define

begin_define
define|#
directive|define
name|PROC_FILENO
value|5
end_define

begin_struct_decl
struct_decl|struct
name|service
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|service_connection
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|service_limit_func_t
parameter_list|(
specifier|const
name|nvlist_t
modifier|*
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|service_command_func_t
parameter_list|(
specifier|const
name|char
modifier|*
name|cmd
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|struct
name|service_connection
modifier|*
name|service_connection_add
parameter_list|(
name|struct
name|service
modifier|*
name|service
parameter_list|,
name|int
name|sock
parameter_list|,
specifier|const
name|nvlist_t
modifier|*
name|limits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|service_connection_remove
parameter_list|(
name|struct
name|service
modifier|*
name|service
parameter_list|,
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|service_connection_clone
parameter_list|(
name|struct
name|service
modifier|*
name|service
parameter_list|,
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|service_connection
modifier|*
name|service_connection_first
parameter_list|(
name|struct
name|service
modifier|*
name|service
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|service_connection
modifier|*
name|service_connection_next
parameter_list|(
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|cap_channel_t
modifier|*
name|service_connection_get_chan
parameter_list|(
specifier|const
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|service_connection_get_sock
parameter_list|(
specifier|const
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|nvlist_t
modifier|*
name|service_connection_get_limits
parameter_list|(
specifier|const
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|service_connection_set_limits
parameter_list|(
name|struct
name|service_connection
modifier|*
name|sconn
parameter_list|,
name|nvlist_t
modifier|*
name|limits
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|service_start
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|sock
parameter_list|,
name|service_limit_func_t
modifier|*
name|limitfunc
parameter_list|,
name|service_command_func_t
modifier|*
name|commandfunc
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_LIBCASPER_H_ */
end_comment

end_unit

