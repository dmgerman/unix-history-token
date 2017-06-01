begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===--------------------- support/win32/locale_win32.h -------------------===//
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
name|_LIBCPP_SUPPORT_WIN32_LOCALE_WIN32_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_SUPPORT_WIN32_LOCALE_WIN32_H
end_define

begin_include
include|#
directive|include
file|<__config>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
name|locale_t
value|_locale_t
end_define

begin_comment
comment|// Locale management functions
end_comment

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

begin_function_decl
name|lconv
modifier|*
name|localeconv_l
parameter_list|(
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbrlen_l
parameter_list|(
specifier|const
name|char
modifier|*
name|__restrict
name|s
parameter_list|,
name|size_t
name|n
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbsrtowcs_l
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcrtomb_l
parameter_list|(
name|char
modifier|*
name|__restrict
name|s
parameter_list|,
name|wchar_t
name|wc
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbrtowc_l
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
name|pwc
parameter_list|,
specifier|const
name|char
modifier|*
name|__restrict
name|s
parameter_list|,
name|size_t
name|n
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|mbsnrtowcs_l
parameter_list|(
name|wchar_t
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|nms
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|wcsnrtombs_l
parameter_list|(
name|char
modifier|*
name|__restrict
name|dst
parameter_list|,
specifier|const
name|wchar_t
modifier|*
modifier|*
name|__restrict
name|src
parameter_list|,
name|size_t
name|nwc
parameter_list|,
name|size_t
name|len
parameter_list|,
name|mbstate_t
modifier|*
name|__restrict
name|ps
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|wint_t
name|btowc_l
parameter_list|(
name|int
name|c
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|wctob_l
parameter_list|(
name|wint_t
name|c
parameter_list|,
name|locale_t
name|loc
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|decltype
argument_list|(
argument|MB_CUR_MAX
argument_list|)
end_macro

begin_macro
name|MB_CUR_MAX_L
argument_list|(
argument|locale_t __l
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// the *_l functions are prefixed on Windows, only available for msvcr80+, VS2005+
end_comment

begin_define
define|#
directive|define
name|mbtowc_l
value|_mbtowc_l
end_define

begin_define
define|#
directive|define
name|strtoll_l
value|_strtoi64_l
end_define

begin_define
define|#
directive|define
name|strtoull_l
value|_strtoui64_l
end_define

begin_define
define|#
directive|define
name|strtod_l
value|_strtod_l
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_LIBCPP_MSVCRT
argument_list|)
end_if

begin_define
define|#
directive|define
name|strtof_l
value|_strtof_l
end_define

begin_define
define|#
directive|define
name|strtold_l
value|_strtold_l
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|float
name|strtof_l
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|double
name|strtold_l
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|locale_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|int
name|islower_l
parameter_list|(
name|int
name|c
parameter_list|,
name|_locale_t
name|loc
parameter_list|)
block|{
return|return
name|_islower_l
argument_list|(
operator|(
name|int
operator|)
name|c
argument_list|,
name|loc
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|_LIBCPP_INLINE_VISIBILITY
name|int
name|isupper_l
parameter_list|(
name|int
name|c
parameter_list|,
name|_locale_t
name|loc
parameter_list|)
block|{
return|return
name|_isupper_l
argument_list|(
operator|(
name|int
operator|)
name|c
argument_list|,
name|loc
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|isdigit_l
value|_isdigit_l
end_define

begin_define
define|#
directive|define
name|isxdigit_l
value|_isxdigit_l
end_define

begin_define
define|#
directive|define
name|strcoll_l
value|_strcoll_l
end_define

begin_define
define|#
directive|define
name|strxfrm_l
value|_strxfrm_l
end_define

begin_define
define|#
directive|define
name|wcscoll_l
value|_wcscoll_l
end_define

begin_define
define|#
directive|define
name|wcsxfrm_l
value|_wcsxfrm_l
end_define

begin_define
define|#
directive|define
name|toupper_l
value|_toupper_l
end_define

begin_define
define|#
directive|define
name|tolower_l
value|_tolower_l
end_define

begin_define
define|#
directive|define
name|iswspace_l
value|_iswspace_l
end_define

begin_define
define|#
directive|define
name|iswprint_l
value|_iswprint_l
end_define

begin_define
define|#
directive|define
name|iswcntrl_l
value|_iswcntrl_l
end_define

begin_define
define|#
directive|define
name|iswupper_l
value|_iswupper_l
end_define

begin_define
define|#
directive|define
name|iswlower_l
value|_iswlower_l
end_define

begin_define
define|#
directive|define
name|iswalpha_l
value|_iswalpha_l
end_define

begin_define
define|#
directive|define
name|iswdigit_l
value|_iswdigit_l
end_define

begin_define
define|#
directive|define
name|iswpunct_l
value|_iswpunct_l
end_define

begin_define
define|#
directive|define
name|iswxdigit_l
value|_iswxdigit_l
end_define

begin_define
define|#
directive|define
name|towupper_l
value|_towupper_l
end_define

begin_define
define|#
directive|define
name|towlower_l
value|_towlower_l
end_define

begin_define
define|#
directive|define
name|strftime_l
value|_strftime_l
end_define

begin_define
define|#
directive|define
name|sscanf_l
parameter_list|(
name|__s
parameter_list|,
name|__l
parameter_list|,
name|__f
parameter_list|,
modifier|...
parameter_list|)
value|_sscanf_l( __s, __f, __l, __VA_ARGS__ )
end_define

begin_define
define|#
directive|define
name|vsscanf_l
parameter_list|(
name|__s
parameter_list|,
name|__l
parameter_list|,
name|__f
parameter_list|,
modifier|...
parameter_list|)
value|_sscanf_l( __s, __f, __l, __VA_ARGS__ )
end_define

begin_define
define|#
directive|define
name|sprintf_l
parameter_list|(
name|__s
parameter_list|,
name|__l
parameter_list|,
name|__f
parameter_list|,
modifier|...
parameter_list|)
value|_sprintf_l( __s, __f, __l, __VA_ARGS__ )
end_define

begin_define
define|#
directive|define
name|vsprintf_l
parameter_list|(
name|__s
parameter_list|,
name|__l
parameter_list|,
name|__f
parameter_list|,
modifier|...
parameter_list|)
value|_vsprintf_l( __s, __f, __l, __VA_ARGS__ )
end_define

begin_define
define|#
directive|define
name|vsnprintf_l
parameter_list|(
name|__s
parameter_list|,
name|__n
parameter_list|,
name|__l
parameter_list|,
name|__f
parameter_list|,
modifier|...
parameter_list|)
value|_vsnprintf_l( __s, __n, __f, __l, __VA_ARGS__ )
end_define

begin_function_decl
name|_LIBCPP_FUNC_VIS
name|int
name|snprintf_l
parameter_list|(
name|char
modifier|*
name|ret
parameter_list|,
name|size_t
name|n
parameter_list|,
name|locale_t
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_LIBCPP_FUNC_VIS
name|int
name|asprintf_l
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|locale_t
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|_LIBCPP_FUNC_VIS
name|int
name|vasprintf_l
parameter_list|(
name|char
modifier|*
modifier|*
name|ret
parameter_list|,
name|locale_t
name|loc
parameter_list|,
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|ap
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// not-so-pressing FIXME: use locale to determine blank characters
end_comment

begin_function
specifier|inline
name|int
name|isblank_l
parameter_list|(
name|int
name|c
parameter_list|,
name|locale_t
comment|/*loc*/
parameter_list|)
block|{
return|return
operator|(
name|c
operator|==
literal|' '
operator|||
name|c
operator|==
literal|'\t'
operator|)
return|;
block|}
end_function

begin_function
specifier|inline
name|int
name|iswblank_l
parameter_list|(
name|wint_t
name|c
parameter_list|,
name|locale_t
comment|/*loc*/
parameter_list|)
block|{
return|return
operator|(
name|c
operator|==
literal|L'
expr|'
operator|||
name|c
operator|==
literal|L'
expr|\t'
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_SUPPORT_WIN32_LOCALE_WIN32_H
end_comment

end_unit

