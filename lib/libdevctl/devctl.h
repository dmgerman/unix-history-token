begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 John Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEVCTL_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEVCTL_H__
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_function_decl
name|int
name|devctl_attach
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devctl_detach
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devctl_enable
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devctl_disable
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|,
name|bool
name|force_detach
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|devctl_set_driver
parameter_list|(
specifier|const
name|char
modifier|*
name|device
parameter_list|,
specifier|const
name|char
modifier|*
name|driver
parameter_list|,
name|bool
name|force
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__DEVCTL_H__ */
end_comment

end_unit

