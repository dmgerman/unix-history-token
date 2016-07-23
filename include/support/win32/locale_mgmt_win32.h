begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===----------------- support/win32/locale_mgmt_win32.h ------------------===//
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
name|_LIBCPP_SUPPORT_WIN32_LOCALE_MGMT_WIN32_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_WIN32_LOCALE_MGMT_WIN32_H
end_define

begin_include
include|#
directive|include
file|<xlocinfo.h>
end_include

begin_comment
comment|// _locale_t
end_comment

begin_define
define|#
directive|define
name|locale_t
value|_locale_t
end_define

begin_define
define|#
directive|define
name|LC_COLLATE_MASK
value|_M_COLLATE
end_define

begin_define
define|#
directive|define
name|LC_CTYPE_MASK
value|_M_CTYPE
end_define

begin_define
define|#
directive|define
name|LC_MONETARY_MASK
value|_M_MONETARY
end_define

begin_define
define|#
directive|define
name|LC_NUMERIC_MASK
value|_M_NUMERIC
end_define

begin_define
define|#
directive|define
name|LC_TIME_MASK
value|_M_TIME
end_define

begin_define
define|#
directive|define
name|LC_MESSAGES_MASK
value|_M_MESSAGES
end_define

begin_define
define|#
directive|define
name|LC_ALL_MASK
value|(  LC_COLLATE_MASK \                      | LC_CTYPE_MASK \                      | LC_MESSAGES_MASK \                      | LC_MONETARY_MASK \                      | LC_NUMERIC_MASK \                      | LC_TIME_MASK )
end_define

begin_define
define|#
directive|define
name|freelocale
value|_free_locale
end_define

begin_comment
comment|// FIXME: base currently unused. Needs manual work to construct the new locale
end_comment

begin_function_decl
name|locale_t
name|newlocale
parameter_list|(
name|int
name|mask
parameter_list|,
specifier|const
name|char
modifier|*
name|locale
parameter_list|,
name|locale_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|locale_t
name|uselocale
parameter_list|(
name|locale_t
name|newloc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_WIN32_LOCALE_MGMT_WIN32_H
end_comment

end_unit

