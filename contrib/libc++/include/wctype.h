begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------------- wctype.h ---------------------------------===//
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
name|_LIBCPP_WCTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_WCTYPE_H
end_define

begin_comment
comment|/*     wctype.h synopsis  Macros:      WEOF  Types:      wint_t     wctrans_t     wctype_t  int iswalnum(wint_t wc); int iswalpha(wint_t wc); int iswblank(wint_t wc);  // C99 int iswcntrl(wint_t wc); int iswdigit(wint_t wc); int iswgraph(wint_t wc); int iswlower(wint_t wc); int iswprint(wint_t wc); int iswpunct(wint_t wc); int iswspace(wint_t wc); int iswupper(wint_t wc); int iswxdigit(wint_t wc); int iswctype(wint_t wc, wctype_t desc); wctype_t wctype(const char* property); wint_t towlower(wint_t wc); wint_t towupper(wint_t wc); wint_t towctrans(wint_t wc, wctrans_t desc); wctrans_t wctrans(const char* property);  */
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
empty|#include_next<wctype.h>
end_empty

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_undef
undef|#
directive|undef
name|iswalnum
end_undef

begin_undef
undef|#
directive|undef
name|iswalpha
end_undef

begin_undef
undef|#
directive|undef
name|iswblank
end_undef

begin_undef
undef|#
directive|undef
name|iswcntrl
end_undef

begin_undef
undef|#
directive|undef
name|iswdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswgraph
end_undef

begin_undef
undef|#
directive|undef
name|iswlower
end_undef

begin_undef
undef|#
directive|undef
name|iswprint
end_undef

begin_undef
undef|#
directive|undef
name|iswpunct
end_undef

begin_undef
undef|#
directive|undef
name|iswspace
end_undef

begin_undef
undef|#
directive|undef
name|iswupper
end_undef

begin_undef
undef|#
directive|undef
name|iswxdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswctype
end_undef

begin_undef
undef|#
directive|undef
name|wctype
end_undef

begin_undef
undef|#
directive|undef
name|towlower
end_undef

begin_undef
undef|#
directive|undef
name|towupper
end_undef

begin_undef
undef|#
directive|undef
name|towctrans
end_undef

begin_undef
undef|#
directive|undef
name|wctrans
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_WCTYPE_H
end_comment

end_unit

