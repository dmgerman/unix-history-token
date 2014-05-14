begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * testcode/unitmain.h - unit test main program for unbound.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *  * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *  * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/**  * \file  * Declarations useful for the unit tests.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TESTCODE_UNITMAIN_H
end_ifndef

begin_define
define|#
directive|define
name|TESTCODE_UNITMAIN_H
end_define

begin_include
include|#
directive|include
file|"util/log.h"
end_include

begin_comment
comment|/** number of tests done */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|testcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/** test bool x, exits on failure, increases testcount. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_UNBOUND
end_ifdef

begin_define
define|#
directive|define
name|unit_assert
parameter_list|(
name|x
parameter_list|)
value|do {testcount++; log_assert(x);} while(0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|unit_assert
parameter_list|(
name|x
parameter_list|)
value|do {testcount++; if(!(x)) { fprintf(stderr, "assertion failure %s:%d\n", __FILE__, __LINE__); exit(1);}} while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** we are now testing this function */
end_comment

begin_function_decl
name|void
name|unit_show_func
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** we are testing this functionality */
end_comment

begin_function_decl
name|void
name|unit_show_feature
parameter_list|(
specifier|const
name|char
modifier|*
name|feature
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test lruhashtable implementation */
end_comment

begin_function_decl
name|void
name|lruhash_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test slabhashtable implementation */
end_comment

begin_function_decl
name|void
name|slabhash_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test for msgreply and msgparse */
end_comment

begin_function_decl
name|void
name|msgparse_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test dname handling functions */
end_comment

begin_function_decl
name|void
name|dname_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test trust anchor storage functions */
end_comment

begin_function_decl
name|void
name|anchors_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test for verification functions */
end_comment

begin_function_decl
name|void
name|verify_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test for negative cache functions */
end_comment

begin_function_decl
name|void
name|neg_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test for regional allocator functions */
end_comment

begin_function_decl
name|void
name|regional_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** unit test for ldns functions */
end_comment

begin_function_decl
name|void
name|ldns_test
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TESTCODE_UNITMAIN_H */
end_comment

end_unit

