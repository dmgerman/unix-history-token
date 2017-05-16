begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===---------------------------- ctype.h ---------------------------------===//
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
name|_LIBCPP_CTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_CTYPE_H
end_define

begin_comment
comment|/*     ctype.h synopsis  int isalnum(int c); int isalpha(int c); int isblank(int c);  // C99 int iscntrl(int c); int isdigit(int c); int isgraph(int c); int islower(int c); int isprint(int c); int ispunct(int c); int isspace(int c); int isupper(int c); int isxdigit(int c); int tolower(int c); int toupper(int c); */
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
empty|#include_next<ctype.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_undef
undef|#
directive|undef
name|isalnum
end_undef

begin_undef
undef|#
directive|undef
name|isalpha
end_undef

begin_undef
undef|#
directive|undef
name|isblank
end_undef

begin_undef
undef|#
directive|undef
name|iscntrl
end_undef

begin_undef
undef|#
directive|undef
name|isdigit
end_undef

begin_undef
undef|#
directive|undef
name|isgraph
end_undef

begin_undef
undef|#
directive|undef
name|islower
end_undef

begin_undef
undef|#
directive|undef
name|isprint
end_undef

begin_undef
undef|#
directive|undef
name|ispunct
end_undef

begin_undef
undef|#
directive|undef
name|isspace
end_undef

begin_undef
undef|#
directive|undef
name|isupper
end_undef

begin_undef
undef|#
directive|undef
name|isxdigit
end_undef

begin_undef
undef|#
directive|undef
name|tolower
end_undef

begin_undef
undef|#
directive|undef
name|toupper
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_CTYPE_H
end_comment

end_unit

