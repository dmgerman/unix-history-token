begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2004 Pawel Jakub Dawidek<pjd@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GEOM_H_
end_ifndef

begin_define
define|#
directive|define
name|_GEOM_H_
end_define

begin_define
define|#
directive|define
name|G_LIB_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|G_FLAG_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|G_FLAG_VERBOSE
value|0x0001
end_define

begin_define
define|#
directive|define
name|G_FLAG_LOADKLD
value|0x0002
end_define

begin_define
define|#
directive|define
name|G_TYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|G_TYPE_STRING
value|1
end_define

begin_define
define|#
directive|define
name|G_TYPE_NUMBER
value|2
end_define

begin_define
define|#
directive|define
name|G_OPT_MAX
value|16
end_define

begin_define
define|#
directive|define
name|G_OPT_DONE
parameter_list|(
name|opt
parameter_list|)
value|(opt)->go_char = '\0'
end_define

begin_define
define|#
directive|define
name|G_OPT_ISDONE
parameter_list|(
name|opt
parameter_list|)
value|((opt)->go_char == '\0')
end_define

begin_define
define|#
directive|define
name|G_OPT_SENTINEL
value|{ '\0', NULL, NULL, G_TYPE_NONE }
end_define

begin_define
define|#
directive|define
name|G_NULL_OPTS
value|{ G_OPT_SENTINEL }
end_define

begin_define
define|#
directive|define
name|G_CMD_SENTINEL
value|{ NULL, 0, NULL, G_NULL_OPTS, NULL }
end_define

begin_struct
struct|struct
name|g_option
block|{
name|char
name|go_char
decl_stmt|;
specifier|const
name|char
modifier|*
name|go_name
decl_stmt|;
name|void
modifier|*
name|go_val
decl_stmt|;
name|unsigned
name|go_type
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|g_command
block|{
specifier|const
name|char
modifier|*
name|gc_name
decl_stmt|;
name|unsigned
name|gc_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|gc_func
function_decl|)
parameter_list|(
name|struct
name|gctl_req
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
name|struct
name|g_option
name|gc_options
index|[
name|G_OPT_MAX
index|]
decl_stmt|;
specifier|const
name|char
modifier|*
name|gc_usage
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_GEOM_H_ */
end_comment

end_unit

