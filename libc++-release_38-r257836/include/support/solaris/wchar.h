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

begin_define
define|#
directive|define
name|iswalpha
value|sun_iswalpha
end_define

begin_define
define|#
directive|define
name|iswupper
value|sun_iswupper
end_define

begin_define
define|#
directive|define
name|iswlower
value|sun_iswlower
end_define

begin_define
define|#
directive|define
name|iswdigit
value|sun_iswdigit
end_define

begin_define
define|#
directive|define
name|iswxdigit
value|sun_iswxdigit
end_define

begin_define
define|#
directive|define
name|iswalnum
value|sun_iswalnum
end_define

begin_define
define|#
directive|define
name|iswspace
value|sun_iswspace
end_define

begin_define
define|#
directive|define
name|iswpunct
value|sun_iswpunct
end_define

begin_define
define|#
directive|define
name|iswprint
value|sun_iswprint
end_define

begin_define
define|#
directive|define
name|iswgraph
value|sun_iswgraph
end_define

begin_define
define|#
directive|define
name|iswcntrl
value|sun_iswcntrl
end_define

begin_define
define|#
directive|define
name|iswctype
value|sun_iswctype
end_define

begin_define
define|#
directive|define
name|towlower
value|sun_towlower
end_define

begin_define
define|#
directive|define
name|towupper
value|sun_towupper
end_define

begin_define
define|#
directive|define
name|wcswcs
value|sun_wcswcs
end_define

begin_define
define|#
directive|define
name|wcswidth
value|sun_wcswidth
end_define

begin_define
define|#
directive|define
name|wcwidth
value|sun_wcwidth
end_define

begin_define
define|#
directive|define
name|wctype
value|sun_wctype
end_define

begin_define
define|#
directive|define
name|_WCHAR_T
value|1
end_define

begin_empty
empty|#include_next "wchar.h"
end_empty

begin_undef
undef|#
directive|undef
name|iswalpha
end_undef

begin_undef
undef|#
directive|undef
name|iswupper
end_undef

begin_undef
undef|#
directive|undef
name|iswlower
end_undef

begin_undef
undef|#
directive|undef
name|iswdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswxdigit
end_undef

begin_undef
undef|#
directive|undef
name|iswalnum
end_undef

begin_undef
undef|#
directive|undef
name|iswspace
end_undef

begin_undef
undef|#
directive|undef
name|iswpunct
end_undef

begin_undef
undef|#
directive|undef
name|iswprint
end_undef

begin_undef
undef|#
directive|undef
name|iswgraph
end_undef

begin_undef
undef|#
directive|undef
name|iswcntrl
end_undef

begin_undef
undef|#
directive|undef
name|iswctype
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
name|wcswcs
end_undef

begin_undef
undef|#
directive|undef
name|wcswidth
end_undef

begin_undef
undef|#
directive|undef
name|wcwidth
end_undef

begin_undef
undef|#
directive|undef
name|wctype
end_undef

end_unit

