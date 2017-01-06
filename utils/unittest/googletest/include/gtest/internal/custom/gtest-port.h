begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2015, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Injection point for custom user configurations.
end_comment

begin_comment
comment|// The following macros can be defined:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Flag related macros:
end_comment

begin_comment
comment|//     GTEST_FLAG(flag_name)
end_comment

begin_comment
comment|//     GTEST_USE_OWN_FLAGFILE_FLAG_  - Define to 0 when the system provides its
end_comment

begin_comment
comment|//                                     own flagfile flag parsing.
end_comment

begin_comment
comment|//     GTEST_DECLARE_bool_(name)
end_comment

begin_comment
comment|//     GTEST_DECLARE_int32_(name)
end_comment

begin_comment
comment|//     GTEST_DECLARE_string_(name)
end_comment

begin_comment
comment|//     GTEST_DEFINE_bool_(name, default_val, doc)
end_comment

begin_comment
comment|//     GTEST_DEFINE_int32_(name, default_val, doc)
end_comment

begin_comment
comment|//     GTEST_DEFINE_string_(name, default_val, doc)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Test filtering:
end_comment

begin_comment
comment|//     GTEST_TEST_FILTER_ENV_VAR_ - The name of an environment variable that
end_comment

begin_comment
comment|//                                  will be used if --GTEST_FLAG(test_filter)
end_comment

begin_comment
comment|//                                  is not provided.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Logging:
end_comment

begin_comment
comment|//     GTEST_LOG_(severity)
end_comment

begin_comment
comment|//     GTEST_CHECK_(condition)
end_comment

begin_comment
comment|//     Functions LogToStderr() and FlushInfoLog() have to be provided too.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   Threading:
end_comment

begin_comment
comment|//     GTEST_HAS_NOTIFICATION_ - Enabled if Notification is already provided.
end_comment

begin_comment
comment|//     GTEST_HAS_MUTEX_AND_THREAD_LOCAL_ - Enabled if Mutex and ThreadLocal are
end_comment

begin_comment
comment|//                                         already provided.
end_comment

begin_comment
comment|//     Must also provide GTEST_DECLARE_STATIC_MUTEX_(mutex) and
end_comment

begin_comment
comment|//     GTEST_DEFINE_STATIC_MUTEX_(mutex)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     GTEST_EXCLUSIVE_LOCK_REQUIRED_(locks)
end_comment

begin_comment
comment|//     GTEST_LOCK_EXCLUDED_(locks)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ** Custom implementation starts here **
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_CUSTOM_GTEST_PORT_H_
end_comment

end_unit

