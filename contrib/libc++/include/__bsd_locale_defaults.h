begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// -*- C++ -*-
end_comment

begin_comment
comment|//===---------------------- __bsd_locale_defaults.h -----------------------===//
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

begin_comment
comment|// The BSDs have lots of *_l functions.  We don't want to define those symbols
end_comment

begin_comment
comment|// on other platforms though, for fear of conflicts with user code.  So here,
end_comment

begin_comment
comment|// we will define the mapping from an internal macro to the real BSD symbol.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LIBCPP_BSD_LOCALE_DEFAULTS_H
end_ifndef

begin_define
define|#
directive|define
name|_LIBCPP_BSD_LOCALE_DEFAULTS_H
end_define

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

begin_define
define|#
directive|define
name|__libcpp_mb_cur_max_l
parameter_list|(
name|loc
parameter_list|)
value|MB_CUR_MAX_L(loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_btowc_l
parameter_list|(
name|ch
parameter_list|,
name|loc
parameter_list|)
value|btowc_l(ch, loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_wctob_l
parameter_list|(
name|wch
parameter_list|,
name|loc
parameter_list|)
value|wctob_l(wch, loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_wcsnrtombs_l
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|nwc
parameter_list|,
name|len
parameter_list|,
name|ps
parameter_list|,
name|loc
parameter_list|)
value|wcsnrtombs_l(dst, src, nwc, len, ps, loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_wcrtomb_l
parameter_list|(
name|src
parameter_list|,
name|wc
parameter_list|,
name|ps
parameter_list|,
name|loc
parameter_list|)
value|wcrtomb_l(src, wc, ps, loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_mbsnrtowcs_l
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|,
name|nms
parameter_list|,
name|len
parameter_list|,
name|ps
parameter_list|,
name|loc
parameter_list|)
value|mbsnrtowcs_l(dst, src, nms, len, ps, loc)
end_define

begin_define
define|#
directive|define
name|__libcpp_mbrtowc_l
parameter_list|(
name|pwc
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|ps
parameter_list|,
name|l
parameter_list|)
value|mbrtowc_l(pwc, s, n, ps, l)
end_define

begin_define
define|#
directive|define
name|__libcpp_mbtowc_l
parameter_list|(
name|pwc
parameter_list|,
name|pmb
parameter_list|,
name|max
parameter_list|,
name|l
parameter_list|)
value|mbtowc_l(pwc, pmb, max, l)
end_define

begin_define
define|#
directive|define
name|__libcpp_mbrlen_l
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|ps
parameter_list|,
name|l
parameter_list|)
value|mbrlen_l(s, n, ps, l)
end_define

begin_define
define|#
directive|define
name|__libcpp_localeconv_l
parameter_list|(
name|l
parameter_list|)
value|localeconv_l(l)
end_define

begin_define
define|#
directive|define
name|__libcpp_mbsrtowcs_l
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|,
name|ps
parameter_list|,
name|l
parameter_list|)
value|mbsrtowcs_l(dest, src, len, ps, l)
end_define

begin_define
define|#
directive|define
name|__libcpp_snprintf_l
parameter_list|(
modifier|...
parameter_list|)
value|snprintf_l(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__libcpp_asprintf_l
parameter_list|(
modifier|...
parameter_list|)
value|asprintf_l(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|__libcpp_sscanf_l
parameter_list|(
modifier|...
parameter_list|)
value|sscanf_l(__VA_ARGS__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _LIBCPP_BSD_LOCALE_DEFAULTS_H
end_comment

end_unit

