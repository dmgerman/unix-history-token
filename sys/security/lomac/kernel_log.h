begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Networks Associates Technology, Inc.  * All rights reserved.  *  * This software was developed for the FreeBSD Project by NAI Labs, the  * Security Research Division of Network Associates, Inc. under  * DARPA/SPAWAR contract N66001-01-C-8035 ("CBOSS"), as part of the DARPA  * CHATS research program.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote  *    products derived from this software without specific prior written  *    permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Id$  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL_LOG_H_
end_ifndef

begin_define
define|#
directive|define
name|_KERNEL_LOG_H_
end_define

begin_include
include|#
directive|include
file|"kernel_interface.h"
end_include

begin_comment
comment|/* Use this unsigned int and its constants to set the log output  *  * verbosity.  Use of the log_* functions should be surrounded by *  * if statements of the form "if( verbose& VERBOSE_FOO )" where  *  * VERBOSE_FOO is the constant below which corresponds to the     *  * type of event you're logging.                                  */
end_comment

begin_define
define|#
directive|define
name|VERBOSE_NOLOG
value|0x00000000
end_define

begin_comment
comment|/* no log output, please. */
end_comment

begin_define
define|#
directive|define
name|VERBOSE_DEMOTE_DENY
value|0x00000001
end_define

begin_comment
comment|/* log demotions and access denials. */
end_comment

begin_define
define|#
directive|define
name|VERBOSE_PIPE
value|0x00000002
end_define

begin_comment
comment|/* log changes to pipe "levels". */
end_comment

begin_define
define|#
directive|define
name|VERBOSE_LOG_SOCKETS
value|0x00000004
end_define

begin_comment
comment|/* log UNIX domain socket setup. */
end_comment

begin_define
define|#
directive|define
name|VERBOSE_LOG_OBJECTS
value|0x00000008
end_define

begin_comment
comment|/* log opening of objects. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRUST
end_ifdef

begin_define
define|#
directive|define
name|VERBOSE_TRUST
value|0x00000020
end_define

begin_comment
comment|/* log when trust stops demotion. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VERBOSITY_SETTING
end_ifndef

begin_define
define|#
directive|define
name|VERBOSITY_SETTING
parameter_list|(
name|level
parameter_list|)
value|extern unsigned int lomac_verbose_##level;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_expr_stmt
name|VERBOSITY_SETTING
argument_list|(
name|demote_deny
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERBOSITY_SETTING
argument_list|(
name|log_sockets
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|VERBOSITY_SETTING
argument_list|(
name|log_objects
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|LOMAC_DEBUG_PIPE
end_ifdef

begin_expr_stmt
name|VERBOSITY_SETTING
argument_list|(
name|pipe
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TRUST
end_ifdef

begin_expr_stmt
name|VERBOSITY_SETTING
argument_list|(
name|trust
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|lomac_log_t
modifier|*
name|log_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_append_string
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|char
modifier|*
name|data_s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_append_int
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
name|int
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_append_subject_id
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|lomac_subject_t
modifier|*
name|p_subject
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_append_object_id
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|,
specifier|const
name|lomac_object_t
modifier|*
name|p_object
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|log_print
parameter_list|(
name|lomac_log_t
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

