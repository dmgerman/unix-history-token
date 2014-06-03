begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Automated Testing Framework (atf)  *  * Copyright (c) 2008 The NetBSD Foundation, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND  * CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TESTS_ATF_ATF_C_TEST_HELPERS_H
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Cannot include test_helpers.h more than once."
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TESTS_ATF_ATF_C_TEST_HELPERS_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|"atf-c/error_fwd.h"
end_include

begin_struct_decl
struct_decl|struct
name|atf_dynstr
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|atf_fs_path
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|CE
parameter_list|(
name|stm
parameter_list|)
value|ATF_CHECK(!atf_is_error(stm))
end_define

begin_define
define|#
directive|define
name|RE
parameter_list|(
name|stm
parameter_list|)
value|ATF_REQUIRE(!atf_is_error(stm))
end_define

begin_define
define|#
directive|define
name|HEADER_TC
parameter_list|(
name|name
parameter_list|,
name|hdrname
parameter_list|)
define|\
value|ATF_TC(name); \     ATF_TC_HEAD(name, tc) \     { \         atf_tc_set_md_var(tc, "descr", "Tests that the " hdrname " file can " \             "be included on its own, without any prerequisites"); \     } \     ATF_TC_BODY(name, tc) \     { \         header_check(hdrname); \     }
end_define

begin_define
define|#
directive|define
name|BUILD_TC
parameter_list|(
name|name
parameter_list|,
name|sfile
parameter_list|,
name|descr
parameter_list|,
name|failmsg
parameter_list|)
define|\
value|ATF_TC(name); \     ATF_TC_HEAD(name, tc) \     { \         atf_tc_set_md_var(tc, "descr", descr); \     } \     ATF_TC_BODY(name, tc) \     { \         if (!build_check_c_o_srcdir(tc, sfile)) \             atf_tc_fail("%s", failmsg); \     }
end_define

begin_function_decl
name|bool
name|build_check_c_o
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|build_check_c_o_srcdir
parameter_list|(
specifier|const
name|atf_tc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|header_check
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_process_helpers_path
parameter_list|(
specifier|const
name|atf_tc_t
modifier|*
parameter_list|,
specifier|const
name|bool
parameter_list|,
name|struct
name|atf_fs_path
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|read_line
parameter_list|(
name|int
parameter_list|,
name|struct
name|atf_dynstr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|run_h_tc
parameter_list|(
name|atf_tc_t
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

