begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DIALOG_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DIALOG_UTIL_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|"dialogrc.h"
end_include

begin_define
define|#
directive|define
name|DIALOG_SPAWN_DEBUG
value|0
end_define

begin_comment
comment|/* Debug spawning of [X]dialog(1) */
end_comment

begin_comment
comment|/* dialog(3) and [X]dialog(1) characteristics */
end_comment

begin_define
define|#
directive|define
name|DIALOG
value|"dialog"
end_define

begin_define
define|#
directive|define
name|XDIALOG
value|"Xdialog"
end_define

begin_define
define|#
directive|define
name|PROMPT_MAX
value|16384
end_define

begin_define
define|#
directive|define
name|ENV_DIALOG
value|"DIALOG"
end_define

begin_define
define|#
directive|define
name|ENV_USE_COLOR
value|"USE_COLOR"
end_define

begin_define
define|#
directive|define
name|ENV_XDIALOG_HIGH_DIALOG_COMPAT
value|"XDIALOG_HIGH_DIALOG_COMPAT"
end_define

begin_decl_stmt
specifier|extern
name|uint8_t
name|dialog_test
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|use_libdialog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|use_dialog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|use_xdialog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|use_color
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|dialog
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* dialog(3) and [X]dialog(1) functionality */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|title
decl_stmt|,
modifier|*
name|backtitle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dheight
decl_stmt|,
name|dwidth
decl_stmt|;
end_decl_stmt

begin_function_decl
name|__BEGIN_DECLS
name|uint8_t
name|dialog_prompt_nlstate
parameter_list|(
specifier|const
name|char
modifier|*
name|_prompt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_gauge_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|dialog_maxsize_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|dialog_prompt_lastline
parameter_list|(
name|char
modifier|*
name|_prompt
parameter_list|,
name|uint8_t
name|_nlstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_maxcols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_maxrows
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_prompt_wrappedlines
parameter_list|(
name|char
modifier|*
name|_prompt
parameter_list|,
name|int
name|_ncols
parameter_list|,
name|uint8_t
name|_nlstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dialog_spawn_gauge
parameter_list|(
name|char
modifier|*
name|_init_prompt
parameter_list|,
name|pid_t
modifier|*
name|_pid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tty_maxcols
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|tty_maxrows
parameter_list|()
value|dialog_maxrows()
end_define

begin_function_decl
name|unsigned
name|int
name|dialog_prompt_longestline
parameter_list|(
specifier|const
name|char
modifier|*
name|_prompt
parameter_list|,
name|uint8_t
name|_nlstate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|int
name|dialog_prompt_numlines
parameter_list|(
specifier|const
name|char
modifier|*
name|_prompt
parameter_list|,
name|uint8_t
name|_nlstate
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
comment|/* !_DIALOG_UTIL_H_ */
end_comment

end_unit

