begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_test_config.h --------------------------------------*- C++ -*-===//
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INCLUDED_FROM_ASAN_TEST_UTILS_H
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This file should be included into asan_test_utils.h only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_TEST_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|ASAN_TEST_CONFIG_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|string
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_UAR
end_ifndef

begin_error
error|#
directive|error
literal|"please define ASAN_UAR"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_HAS_EXCEPTIONS
end_ifndef

begin_error
error|#
directive|error
literal|"please define ASAN_HAS_EXCEPTIONS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_HAS_BLACKLIST
end_ifndef

begin_error
error|#
directive|error
literal|"please define ASAN_HAS_BLACKLIST"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_NEEDS_SEGV
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASAN_NEEDS_SEGV
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASAN_NEEDS_SEGV
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_AVOID_EXPENSIVE_TESTS
end_ifndef

begin_define
define|#
directive|define
name|ASAN_AVOID_EXPENSIVE_TESTS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASAN_PCRE_DOTALL
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// ASAN_TEST_CONFIG_H
end_comment

end_unit

