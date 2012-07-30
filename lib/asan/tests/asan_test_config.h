begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- asan_test_config.h ------------*- C++ -*-===//
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
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_expr_stmt
name|using
name|std
operator|::
name|string
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|vector
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|using
name|std
operator|::
name|map
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

begin_error
error|#
directive|error
literal|"please define ASAN_NEEDS_SEGV"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASAN_LOW_MEMORY
end_ifndef

begin_define
define|#
directive|define
name|ASAN_LOW_MEMORY
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

