begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Licensed to the Apache Software Foundation (ASF) under one or more  * contributor license agreements.  See the NOTICE file distributed with  * this work for additional information regarding copyright ownership.  * The ASF licenses this file to You under the Apache License, Version 2.0  * (the "License"); you may not use this file except in compliance with  * the License.  You may obtain a copy of the License at  *  *     http://www.apache.org/licenses/LICENSE-2.0  *  * Unless required by applicable law or agreed to in writing, software  * distributed under the License is distributed on an "AS IS" BASIS,  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  * See the License for the specific language governing permissions and  * limitations under the License.  */
end_comment

begin_include
include|#
directive|include
file|"apr_pools.h"
end_include

begin_include
include|#
directive|include
file|"abts.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|APR_TEST_UTIL
end_ifndef

begin_define
define|#
directive|define
name|APR_TEST_UTIL
end_define

begin_comment
comment|/* XXX FIXME */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|EXTENSION
value|".exe"
end_define

begin_elif
elif|#
directive|elif
name|NETWARE
end_elif

begin_define
define|#
directive|define
name|EXTENSION
value|".nlm"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTENSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STRING_MAX
value|8096
end_define

begin_comment
comment|/* Some simple functions to make the test apps easier to write and  * a bit more consistent...  */
end_comment

begin_decl_stmt
specifier|extern
name|apr_pool_t
modifier|*
name|p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assert that RV is an APR_SUCCESS value; else fail giving strerror  * for RV and CONTEXT message. */
end_comment

begin_function_decl
name|void
name|apr_assert_success
parameter_list|(
name|abts_case
modifier|*
name|tc
parameter_list|,
specifier|const
name|char
modifier|*
name|context
parameter_list|,
name|apr_status_t
name|rv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|apr_assert_failure
parameter_list|(
name|abts_case
modifier|*
name|tc
parameter_list|,
specifier|const
name|char
modifier|*
name|context
parameter_list|,
name|apr_status_t
name|rv
parameter_list|,
name|int
name|lineno
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|APR_ASSERT_FAILURE
parameter_list|(
name|tc
parameter_list|,
name|ctxt
parameter_list|,
name|rv
parameter_list|)
define|\
value|apr_assert_failure(tc, ctxt, rv, __LINE__)
end_define

begin_function_decl
name|void
name|initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|teststrmatch
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testuri
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testuuid
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testbuckets
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testpass
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testmd4
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testmd5
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testcrypto
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testldap
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testdbd
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testdate
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testmemcache
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testreslist
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testqueue
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testxml
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testxlate
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testrmm
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|abts_suite
modifier|*
name|testdbm
parameter_list|(
name|abts_suite
modifier|*
name|suite
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* APR_TEST_INCLUDES */
end_comment

end_unit

