begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINDLOCL_H_
end_ifndef

begin_define
define|#
directive|define
name|_WINDLOCL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<krb5-types.h>
end_include

begin_include
include|#
directive|include
file|<roken.h>
end_include

begin_include
include|#
directive|include
file|"wind.h"
end_include

begin_include
include|#
directive|include
file|"wind_err.h"
end_include

begin_function_decl
name|int
name|_wind_combining_class
parameter_list|(
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_stringprep_testbidi
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|wind_profile_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_stringprep_error
parameter_list|(
specifier|const
name|uint32_t
parameter_list|,
name|wind_profile_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_stringprep_prohibited
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|wind_profile_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_stringprep_map
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|,
name|wind_profile_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_stringprep_normalize
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|_wind_ldap_case_exact_attribute
parameter_list|(
specifier|const
name|uint32_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WINDLOCL_H_ */
end_comment

end_unit

