begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- stdbool.h --------------------------------===//
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
name|_LIBCPP_STDBOOL_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_STDBOOL_H
end_define

begin_comment
comment|/*     stdbool.h synopsis  Macros:      __bool_true_false_are_defined  */
end_comment

begin_include
include|#
directive|include
file|<__config>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_empty
empty|#include_next<stdbool.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_undef
undef|#
directive|undef
name|bool
end_undef

begin_undef
undef|#
directive|undef
name|true
end_undef

begin_undef
undef|#
directive|undef
name|false
end_undef

begin_undef
undef|#
directive|undef
name|__bool_true_false_are_defined
end_undef

begin_define
define|#
directive|define
name|__bool_true_false_are_defined
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

begin_comment
comment|// _LIBCPP_STDBOOL_H
end_comment

end_unit

