begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===------------------- support/fuchsia/xlocale.h ------------------------===//
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
name|_LIBCPP_SUPPORT_FUCHSIA_XLOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_FUCHSIA_XLOCALE_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__Fuchsia__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<cwchar>
end_include

begin_include
include|#
directive|include
file|<support/xlocale/__posix_l_fallback.h>
end_include

begin_include
include|#
directive|include
file|<support/xlocale/__strtonum_fallback.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// defined(__Fuchsia__)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_FUCHSIA_XLOCALE_H
end_comment

end_unit

