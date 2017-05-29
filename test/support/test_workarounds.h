begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
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
comment|// This file is dual licensed under the MIT and the University of Illinois Open
end_comment

begin_comment
comment|// Source Licenses. See LICENSE.TXT for details.
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
name|SUPPORT_TEST_WORKAROUNDS_H
end_ifndef

begin_define
define|#
directive|define
name|SUPPORT_TEST_WORKAROUNDS_H
end_define

begin_include
include|#
directive|include
file|"test_macros.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TEST_COMPILER_EDG
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_WORKAROUND_EDG_EXPLICIT_CONSTEXPR
end_define

begin_comment
comment|// VSO#424280
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TEST_COMPILER_C1XX
argument_list|)
end_if

begin_define
define|#
directive|define
name|TEST_WORKAROUND_C1XX_BROKEN_IS_TRIVIALLY_COPYABLE
end_define

begin_comment
comment|// VSO#117743
end_comment

begin_define
define|#
directive|define
name|TEST_WORKAROUND_C1XX_EMPTY_PARAMETER_PACK_EXPANSION
end_define

begin_comment
comment|// VSO#109062
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_EXTENSIONS
end_ifndef

begin_define
define|#
directive|define
name|TEST_WORKAROUND_C1XX_BROKEN_ZA_CTOR_CHECK
end_define

begin_comment
comment|// VSO#119998
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SUPPORT_TEST_WORKAROUNDS_H
end_comment

end_unit

