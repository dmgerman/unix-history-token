begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Adrian Chadd  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AR5315_SETUP_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR5315_SETUP_H__
end_define

begin_enum
enum|enum
name|ar531x_soc_type
block|{
name|AR531X_SOC_UNKNOWN
block|,
name|AR531X_SOC_AR5311
block|,
name|AR531X_SOC_AR5312
block|,
name|AR531X_SOC_AR5313
block|,
name|AR531X_SOC_AR5314
block|,
name|AR531X_SOC_AR5315
block|,
name|AR531X_SOC_AR5316
block|,
name|AR531X_SOC_AR5317
block|,
name|AR531X_SOC_AR5318
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|ar531x_soc_type
name|ar531x_soc
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ar5315_detect_sys_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|ar5315_get_system_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|AR_FIRST_GEN
value|1
end_define

begin_define
define|#
directive|define
name|AR_SECOND_GEN
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

