begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2008 Yahoo!, Inc.  * All rights reserved.  * Written by: John Baldwin<jhb@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__TEST_H__
end_ifndef

begin_define
define|#
directive|define
name|__TEST_H__
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_struct
struct|struct
name|regression_test
block|{
name|void
function_decl|(
modifier|*
name|rt_function
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|rt_name
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TEST
parameter_list|(
name|function
parameter_list|,
name|name
parameter_list|)
define|\
value|static struct regression_test _regtest_##function = {		\ 		(function),						\ 		(name)							\ 	};								\ 	DATA_SET(regression_tests_set, _regtest_##function)
end_define

begin_function_decl
name|void
name|fail
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fail_err
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pass
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_tests
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|skip
parameter_list|(
specifier|const
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|todo
parameter_list|(
specifier|const
name|char
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fail_errno
parameter_list|(
name|tag
parameter_list|)
value|fail_err("%s: %s", (tag), strerror(errno))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__TEST_H__ */
end_comment

end_unit

