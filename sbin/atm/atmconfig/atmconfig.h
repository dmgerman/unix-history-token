begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATMCONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|_ATMCONFIG_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<netgraph/ng_message.h>
end_include

begin_define
define|#
directive|define
name|DEFAULT_INTERFACE
value|"hatm0"
end_define

begin_struct
struct|struct
name|cmdtab
block|{
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
specifier|const
name|struct
name|cmdtab
modifier|*
name|sub
decl_stmt|;
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
index|[]
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * client configuration info  */
end_comment

begin_struct
struct|struct
name|amodule
block|{
specifier|const
name|struct
name|cmdtab
modifier|*
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DEF_MODULE
parameter_list|(
name|CMDTAB
parameter_list|)
define|\
value|struct amodule amodule_1 = { CMDTAB }
end_define

begin_comment
comment|/* for compiled-in modules */
end_comment

begin_function_decl
name|void
name|register_module
parameter_list|(
specifier|const
name|struct
name|amodule
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* print a message if we are verbose */
end_comment

begin_function_decl
name|void
name|verb
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* print heading */
end_comment

begin_function_decl
name|void
name|heading
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* before starting output */
end_comment

begin_function_decl
name|void
name|heading_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* stringify an enumerated value */
end_comment

begin_struct
struct|struct
name|penum
block|{
name|int32_t
name|value
decl_stmt|;
specifier|const
name|char
modifier|*
name|str
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|const
name|char
modifier|*
name|penum
parameter_list|(
name|int32_t
name|value
parameter_list|,
specifier|const
name|struct
name|penum
modifier|*
name|strtab
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pparse
parameter_list|(
name|int32_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|penum
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|OPT_NONE
block|,
name|OPT_UINT
block|,
name|OPT_INT
block|,
name|OPT_UINT32
block|,
name|OPT_INT32
block|,
name|OPT_UINT64
block|,
name|OPT_INT64
block|,
name|OPT_FLAG
block|,
name|OPT_VCI
block|,
name|OPT_STRING
block|,
name|OPT_SIMPLE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|option
block|{
specifier|const
name|char
modifier|*
name|optstr
decl_stmt|;
name|int
name|opttype
decl_stmt|;
name|void
modifier|*
name|optarg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|parse_options
parameter_list|(
name|int
modifier|*
name|_pargc
parameter_list|,
name|char
modifier|*
modifier|*
modifier|*
name|_pargv
parameter_list|,
specifier|const
name|struct
name|option
modifier|*
name|_opts
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* XXX while this is compiled in */
end_comment

begin_function_decl
name|void
name|device_register
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATMCONFIG_H */
end_comment

end_unit

