begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013-2014 Devin Teske<dteske@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DPV_PRIVATE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DPV_PRIVATE_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Debugging */
end_comment

begin_decl_stmt
specifier|extern
name|uint8_t
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Data to process */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|dpv_nfiles
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Extra display information */
end_comment

begin_decl_stmt
specifier|extern
name|uint8_t
name|no_labels
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint8_t
name|wide
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|msg_done
decl_stmt|,
modifier|*
name|msg_fail
decl_stmt|,
modifier|*
name|msg_pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pprompt
decl_stmt|,
modifier|*
name|aprompt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|status_format
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defaults */
end_comment

begin_define
define|#
directive|define
name|DIALOG_UPDATES_PER_SEC
value|16
end_define

begin_define
define|#
directive|define
name|XDIALOG_UPDATES_PER_SEC
value|4
end_define

begin_define
define|#
directive|define
name|DISPLAY_LIMIT_DEFAULT
value|0
end_define

begin_comment
comment|/* Auto-calculate */
end_comment

begin_define
define|#
directive|define
name|LABEL_SIZE_DEFAULT
value|28
end_define

begin_define
define|#
directive|define
name|PBAR_SIZE_DEFAULT
value|17
end_define

begin_define
define|#
directive|define
name|STATUS_UPDATES_PER_SEC
value|2
end_define

begin_comment
comment|/* states for dprompt_add_files() of dprompt.c */
end_comment

begin_enum
enum|enum
name|dprompt_state
block|{
name|DPROMPT_NONE
init|=
literal|0
block|,
comment|/* Default */
name|DPROMPT_PENDING
block|,
comment|/* Pending */
name|DPROMPT_PBAR
block|,
comment|/* Progress bar */
name|DPROMPT_END_STATE
block|,
comment|/* Done/Fail */
name|DPROMPT_DETAILS
block|,
comment|/* dpv_file_node->read */
name|DPROMPT_CUSTOM_MSG
block|,
comment|/* dpv_file_node->msg */
name|DPROMPT_MINIMAL
block|,
comment|/* whitespace */
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_DPV_PRIVATE_H_ */
end_comment

end_unit

