begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
name|_LIBCPP_SUPPORT_NEWLIB_XLOCALE_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_NEWLIB_XLOCALE_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NEWLIB_VERSION
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
file|<clocale>
end_include

begin_include
include|#
directive|include
file|<cwctype>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__NEWLIB__
argument_list|)
operator|||
name|__NEWLIB__
operator|<
literal|2
operator|||
expr|\
name|__NEWLIB__
operator|==
literal|2
operator|&&
name|__NEWLIB_MINOR__
operator|<
literal|5
end_if

begin_include
include|#
directive|include
file|<support/xlocale/__nop_locale_mgmt.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
comment|// _NEWLIB_VERSION
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

