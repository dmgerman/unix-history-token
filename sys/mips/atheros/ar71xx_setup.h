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
name|__AR71XX_SETUP_H__
end_ifndef

begin_define
define|#
directive|define
name|__AR71XX_SETUP_H__
end_define

begin_enum
enum|enum
name|ar71xx_soc_type
block|{
name|AR71XX_SOC_UNKNOWN
block|,
name|AR71XX_SOC_AR7130
block|,
name|AR71XX_SOC_AR7141
block|,
name|AR71XX_SOC_AR7161
block|,
name|AR71XX_SOC_AR7240
block|,
name|AR71XX_SOC_AR7241
block|,
name|AR71XX_SOC_AR7242
block|,
name|AR71XX_SOC_AR9130
block|,
name|AR71XX_SOC_AR9132
block|,
name|AR71XX_SOC_AR9330
block|,
name|AR71XX_SOC_AR9331
block|,
name|AR71XX_SOC_AR9341
block|,
name|AR71XX_SOC_AR9342
block|,
name|AR71XX_SOC_AR9344
block|,
name|AR71XX_SOC_QCA9556
block|,
name|AR71XX_SOC_QCA9558
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|ar71xx_soc_type
name|ar71xx_soc
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|ar71xx_detect_sys_type
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
name|ar71xx_get_system_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

