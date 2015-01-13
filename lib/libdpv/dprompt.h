begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DPROMPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DPROMPT_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|"dpv.h"
end_include

begin_comment
comment|/* Display characteristics */
end_comment

begin_define
define|#
directive|define
name|ENV_MSG_DONE
value|"msg_done"
end_define

begin_define
define|#
directive|define
name|ENV_MSG_FAIL
value|"msg_fail"
end_define

begin_define
define|#
directive|define
name|ENV_MSG_PENDING
value|"msg_pending"
end_define

begin_decl_stmt
specifier|extern
name|int
name|display_limit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|label_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pbar_size
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|void
name|dprompt_clear
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprompt_dprint
parameter_list|(
name|int
name|_fd
parameter_list|,
specifier|const
name|char
modifier|*
name|_prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|_append
parameter_list|,
name|int
name|_overall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprompt_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprompt_init
parameter_list|(
name|struct
name|dpv_file_node
modifier|*
name|_file_list
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprompt_libprint
parameter_list|(
specifier|const
name|char
modifier|*
name|_prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|_append
parameter_list|,
name|int
name|_overall
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dprompt_recreate
parameter_list|(
name|struct
name|dpv_file_node
modifier|*
name|_file_list
parameter_list|,
name|struct
name|dpv_file_node
modifier|*
name|_curfile
parameter_list|,
name|int
name|_pct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dprompt_add
parameter_list|(
specifier|const
name|char
modifier|*
name|_format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dprompt_sprint
parameter_list|(
name|char
modifier|*
specifier|restrict
name|_str
parameter_list|,
specifier|const
name|char
modifier|*
name|_prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|_append
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
comment|/* !_DPROMPT_H_ */
end_comment

end_unit

