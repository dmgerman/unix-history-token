begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001 Wind River Systems, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_PCPU_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_PCPU_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/globaldata.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|LOCORE
end_ifndef

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|cpuhead
argument_list|,
name|globaldata
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|cpuhead
name|cpuhead
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|globaldata_register
parameter_list|(
name|struct
name|globaldata
modifier|*
name|gd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|globaldata
modifier|*
name|globaldata_find
parameter_list|(
name|u_int
name|cpuid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !LOCORE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_PCPU_H_ */
end_comment

end_unit

