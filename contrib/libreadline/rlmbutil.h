begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* rlmbutil.h -- utility functions for multibyte characters. */
end_comment

begin_comment
comment|/* Copyright (C) 2001 Free Software Foundation, Inc.     This file is part of the GNU Readline Library, a library for    reading lines of text with interactive input and history editing.     The GNU Readline Library is free software; you can redistribute it    and/or modify it under the terms of the GNU General Public License    as published by the Free Software Foundation; either version 2, or    (at your option) any later version.     The GNU Readline Library is distributed in the hope that it will be    useful, but WITHOUT ANY WARRANTY; without even the implied warranty    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     The GNU General Public License is often shipped with GNU software, and    is generally kept in a file called COPYING or LICENSE.  If you do not    have a copy of the license, write to the Free Software Foundation,    59 Temple Place, Suite 330, Boston, MA 02111 USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_RL_MBUTIL_H_
argument_list|)
end_if

begin_define
define|#
directive|define
name|_RL_MBUTIL_H_
end_define

begin_include
include|#
directive|include
file|"rlstdc.h"
end_include

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/* check multibyte capability for I18N code     */
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/* For platforms which support the ISO C amendement 1 functionality we    support user defined character classes.  */
end_comment

begin_comment
comment|/* Solaris 2.5 has a bug:<wchar.h> must be included before<wctype.h>.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_WCTYPE_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_WCHAR_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_LOCALE_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wchar.h>
end_include

begin_include
include|#
directive|include
file|<wctype.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ISWCTYPE
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_ISWLOWER
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_ISWUPPER
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_MBSRTOWCS
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_MBRTOWC
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_MBRLEN
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_TOWLOWER
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_TOWUPPER
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_WCHAR_T
argument_list|)
operator|&&
expr|\
name|defined
argument_list|(
name|HAVE_WCWIDTH
argument_list|)
end_if

begin_comment
comment|/* system is supposed to support XPG5 */
end_comment

begin_define
define|#
directive|define
name|HANDLE_MULTIBYTE
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
comment|/* If we don't want multibyte chars even on a system that supports them, let    the configuring user turn multibyte support off. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NO_MULTIBYTE_SUPPORT
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HANDLE_MULTIBYTE
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some systems, like BeOS, have multibyte encodings but lack mbstate_t.  */
end_comment

begin_if
if|#
directive|if
name|HANDLE_MULTIBYTE
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_MBSTATE_T
argument_list|)
end_if

begin_define
define|#
directive|define
name|wcsrtombs
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|,
name|ps
parameter_list|)
value|(wcsrtombs) (dest, src, len, 0)
end_define

begin_define
define|#
directive|define
name|mbsrtowcs
parameter_list|(
name|dest
parameter_list|,
name|src
parameter_list|,
name|len
parameter_list|,
name|ps
parameter_list|)
value|(mbsrtowcs) (dest, src, len, 0)
end_define

begin_define
define|#
directive|define
name|wcrtomb
parameter_list|(
name|s
parameter_list|,
name|wc
parameter_list|,
name|ps
parameter_list|)
value|(wcrtomb) (s, wc, 0)
end_define

begin_define
define|#
directive|define
name|mbrtowc
parameter_list|(
name|pwc
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|ps
parameter_list|)
value|(mbrtowc) (pwc, s, n, 0)
end_define

begin_define
define|#
directive|define
name|mbrlen
parameter_list|(
name|s
parameter_list|,
name|n
parameter_list|,
name|ps
parameter_list|)
value|(mbrlen) (s, n, 0)
end_define

begin_define
define|#
directive|define
name|mbstate_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make sure MB_LEN_MAX is at least 16 on systems that claim to be able to    handle multibyte chars (some systems define MB_LEN_MAX as 1) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_MULTIBYTE
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|MB_LEN_MAX
argument_list|)
operator|&&
operator|(
name|MB_LEN_MAX
operator|<
literal|16
operator|)
end_if

begin_undef
undef|#
directive|undef
name|MB_LEN_MAX
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MB_LEN_MAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|16
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
comment|/************************************************/
end_comment

begin_comment
comment|/* end of multibyte capability checks for I18N  */
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/*  * Flags for _rl_find_prev_mbchar and _rl_find_next_mbchar:  *  * MB_FIND_ANY		find any multibyte character  * MB_FIND_NONZERO	find a non-zero-width multibyte character  */
end_comment

begin_define
define|#
directive|define
name|MB_FIND_ANY
value|0x00
end_define

begin_define
define|#
directive|define
name|MB_FIND_NONZERO
value|0x01
end_define

begin_decl_stmt
specifier|extern
name|int
name|_rl_find_prev_mbchar
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_find_next_mbchar
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HANDLE_MULTIBYTE
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|_rl_compare_chars
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|mbstate_t
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|mbstate_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_get_char_len
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|mbstate_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_adjust_point
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|mbstate_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_read_mbchar
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_read_mbstring
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_is_mbchar_matched
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|wchar_t
name|_rl_char_value
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|_rl_walphabetic
name|PARAMS
argument_list|(
operator|(
name|wchar_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|_rl_to_wupper
parameter_list|(
name|wc
parameter_list|)
value|(iswlower (wc) ? towupper (wc) : (wc))
end_define

begin_define
define|#
directive|define
name|_rl_to_wlower
parameter_list|(
name|wc
parameter_list|)
value|(iswupper (wc) ? towlower (wc) : (wc))
end_define

begin_define
define|#
directive|define
name|MB_NEXTCHAR
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
define|\
value|((MB_CUR_MAX> 1&& rl_byte_oriented == 0) \ 		? _rl_find_next_mbchar ((b), (s), (c), (f)) \ 		: ((s) + (c)))
end_define

begin_define
define|#
directive|define
name|MB_PREVCHAR
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
define|\
value|((MB_CUR_MAX> 1&& rl_byte_oriented == 0) \ 		? _rl_find_prev_mbchar ((b), (s), (f)) \ 		: ((s) - 1))
end_define

begin_define
define|#
directive|define
name|MB_INVALIDCH
parameter_list|(
name|x
parameter_list|)
value|((x) == (size_t)-1 || (x) == (size_t)-2)
end_define

begin_define
define|#
directive|define
name|MB_NULLWCH
parameter_list|(
name|x
parameter_list|)
value|((x) == 0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HANDLE_MULTIBYTE */
end_comment

begin_undef
undef|#
directive|undef
name|MB_LEN_MAX
end_undef

begin_undef
undef|#
directive|undef
name|MB_CUR_MAX
end_undef

begin_define
define|#
directive|define
name|MB_LEN_MAX
value|1
end_define

begin_define
define|#
directive|define
name|MB_CUR_MAX
value|1
end_define

begin_define
define|#
directive|define
name|_rl_find_prev_mbchar
parameter_list|(
name|b
parameter_list|,
name|i
parameter_list|,
name|f
parameter_list|)
value|(((i) == 0) ? (i) : ((i) - 1))
end_define

begin_define
define|#
directive|define
name|_rl_find_next_mbchar
parameter_list|(
name|b
parameter_list|,
name|i1
parameter_list|,
name|i2
parameter_list|,
name|f
parameter_list|)
value|((i1) + (i2))
end_define

begin_define
define|#
directive|define
name|_rl_char_value
parameter_list|(
name|buf
parameter_list|,
name|ind
parameter_list|)
value|((buf)[(ind)])
end_define

begin_define
define|#
directive|define
name|_rl_walphabetic
parameter_list|(
name|c
parameter_list|)
value|(rl_alphabetic (c))
end_define

begin_define
define|#
directive|define
name|_rl_to_wupper
parameter_list|(
name|c
parameter_list|)
value|(_rl_to_upper (c))
end_define

begin_define
define|#
directive|define
name|_rl_to_wlower
parameter_list|(
name|c
parameter_list|)
value|(_rl_to_lower (c))
end_define

begin_define
define|#
directive|define
name|MB_NEXTCHAR
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|,
name|f
parameter_list|)
value|((s) + (c))
end_define

begin_define
define|#
directive|define
name|MB_PREVCHAR
parameter_list|(
name|b
parameter_list|,
name|s
parameter_list|,
name|f
parameter_list|)
value|((s) - 1)
end_define

begin_define
define|#
directive|define
name|MB_INVALIDCH
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|MB_NULLWCH
parameter_list|(
name|x
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HANDLE_MULTIBYTE */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rl_byte_oriented
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RL_MBUTIL_H_ */
end_comment

end_unit

