begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FMAN_UCODE_H_
end_ifndef

begin_define
define|#
directive|define
name|FMAN_UCODE_H_
end_define

begin_comment
comment|/**  * @file  * Wrapper header for FMan uCode.  *  * We intentionally use the same uCode from p3041_r1.0.h file as all platforms  * we're currently supporting uses the same version of uCode marked rel_101_8.  */
end_comment

begin_comment
comment|/**  * Header with actual uCode rel_101_8.  */
end_comment

begin_include
include|#
directive|include
file|"P3041/fman_ctrl_code/p3041_r1.0.h"
end_include

begin_comment
comment|/**  * Generic macro.  */
end_comment

begin_define
define|#
directive|define
name|FMAN_UC_IMG
value|P3041_R1_0_UC_IMG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FMAN_UCODE_H_ */
end_comment

end_unit

