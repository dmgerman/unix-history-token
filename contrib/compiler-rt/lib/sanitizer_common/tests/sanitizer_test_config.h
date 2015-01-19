begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_test_config.h ---------------------------------*- C++ -*-===//
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
comment|// This file is a part of *Sanitizer runtime.
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
name|INCLUDED_FROM_SANITIZER_TEST_UTILS_H
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"This file should be included into sanitizer_test_utils.h only"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_TEST_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_TEST_CONFIG_H
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

begin_if
if|#
directive|if
name|SANITIZER_USE_DEJAGNU_GTEST
end_if

begin_include
include|#
directive|include
file|"dejagnu-gtest.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_TEST_CONFIG_H
end_comment

end_unit

