begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HASTD_H_
end_ifndef

begin_define
define|#
directive|define
name|_HASTD_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<libutil.h>
end_include

begin_include
include|#
directive|include
file|<nv.h>
end_include

begin_include
include|#
directive|include
file|"hast.h"
end_include

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|cfgpath
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|sigexit_received
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pidfh
modifier|*
name|pfh
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|descriptors_cleanup
parameter_list|(
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|descriptors_assert
parameter_list|(
specifier|const
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|,
name|int
name|pjdlogmode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hastd_primary
parameter_list|(
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hastd_secondary
parameter_list|(
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|,
name|struct
name|nv
modifier|*
name|nvin
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|primary_config_reload
parameter_list|(
name|struct
name|hast_resource
modifier|*
name|res
parameter_list|,
name|struct
name|nv
modifier|*
name|nv
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HASTD_H_ */
end_comment

end_unit

