begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_test_utils.h ---------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is a part of AddressSanitizer, an address sanity checker.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_TEST_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_TEST_UTILS_H
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ASAN_EXTERNAL_TEST_CONFIG
argument_list|)
end_if

begin_define
define|#
directive|define
name|INCLUDED_FROM_ASAN_TEST_UTILS_H
end_define

begin_include
include|#
directive|include
file|"asan_test_config.h"
end_include

begin_undef
undef|#
directive|undef
name|INCLUDED_FROM_ASAN_TEST_UTILS_H
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sanitizer_common/tests/sanitizer_test_utils.h"
end_include

begin_comment
comment|// Check that pthread_create/pthread_join return success.
end_comment

begin_define
define|#
directive|define
name|PTHREAD_CREATE
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ASSERT_EQ(0, pthread_create(a, b, c, d))
end_define

begin_define
define|#
directive|define
name|PTHREAD_JOIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|ASSERT_EQ(0, pthread_join(a, b))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_TEST_UTILS_H
end_comment

end_unit

