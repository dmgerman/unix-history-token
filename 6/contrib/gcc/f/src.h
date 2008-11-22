begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* src.h -- Public #include File    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Owning Modules:       src.c     Modifications: */
end_comment

begin_comment
comment|/* Allow multiple inclusion to work. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_F_SRC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_F_SRC_H
end_define

begin_include
include|#
directive|include
file|"bad.h"
end_include

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_decl_stmt
specifier|extern
name|char
name|ffesrc_char_match_init_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ffesrc_char_match_noninit_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ffesrc_char_source_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|ffesrc_char_internal_init_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffebad
name|ffesrc_bad_symbol_init_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|ffebad
name|ffesrc_bad_symbol_noninit_
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesrc_check_symbol_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesrc_ok_match_init_upper_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesrc_ok_match_init_lower_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesrc_ok_match_noninit_upper_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|ffesrc_ok_match_noninit_lower_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* These C-language-syntax modifiers could avoid the match arg if gcc's    extension allowing macros to generate dynamic labels was used.  They    could use the no_match arg (and the "caller's" label defs) if there    was a way to say "goto default" in a switch statement.  Oh well.     NOTE: These macro assume "case FFESRC_CASE_MATCH_[NON]INIT(...):" is used    to invoke them, and thus assume the "above" case does not fall through to    this one.  This syntax was chosen to keep indenting tools working.  */
end_comment

begin_define
define|#
directive|define
name|FFESRC_CASE_MATCH_INIT
parameter_list|(
name|upper
parameter_list|,
name|lower
parameter_list|,
name|match
parameter_list|,
name|no_match
parameter_list|)
define|\
value|upper: if (!ffesrc_ok_match_init_upper_) goto no_match; \   else goto match; \  case lower: if (!ffesrc_ok_match_init_lower_) goto no_match; \  match
end_define

begin_define
define|#
directive|define
name|FFESRC_CASE_MATCH_NONINIT
parameter_list|(
name|upper
parameter_list|,
name|lower
parameter_list|,
name|match
parameter_list|,
name|no_match
parameter_list|)
define|\
value|upper: if (!ffesrc_ok_match_noninit_upper_) goto no_match; \   else goto match; \  case lower: if (!ffesrc_ok_match_noninit_lower_) goto no_match; \  match
end_define

begin_comment
comment|/* If character is ok in a symbol name (not including intrinsic names),    returns FFEBAD, else returns something else, type ffebad.  */
end_comment

begin_define
define|#
directive|define
name|ffesrc_bad_char_symbol_init
parameter_list|(
name|c
parameter_list|)
define|\
value|(ffesrc_bad_symbol_init_[(unsigned int) (c)])
end_define

begin_define
define|#
directive|define
name|ffesrc_bad_char_symbol_noninit
parameter_list|(
name|c
parameter_list|)
define|\
value|(ffesrc_bad_symbol_noninit_[(unsigned int) (c)])
end_define

begin_comment
comment|/* Returns TRUE if character is ok in a symbol name (including    intrinsic names).  Doesn't care about case settings, this is    used just for parsing (before semantic complaints about symbol-    name casing and such).  One specific usage is to decide whether    an underscore is valid as the first or subsequent character in    some symbol name -- if not, an underscore is a separate token    (while lexing, for example).  Note that ffesrc_is_name_init    must return TRUE for a (not necessarily proper) subset of    characters for which ffelex_is_firstnamechar returns TRUE.  */
end_comment

begin_define
define|#
directive|define
name|ffesrc_is_name_init
parameter_list|(
name|c
parameter_list|)
define|\
value|((ISALPHA ((c))) || (! (1 || ffe_is_90 ())&& ((c) == '_')))
end_define

begin_define
define|#
directive|define
name|ffesrc_is_name_noninit
parameter_list|(
name|c
parameter_list|)
define|\
value|((ISALNUM ((c))) || (! (1 || ffe_is_90 ())&& ((c) == '_')))
end_define

begin_comment
comment|/* Test if source-translated character matches given alphabetic character    (passed in both uppercase and lowercase, to allow for custom speedup    of compilation in environments where compile-time options aren't needed    for casing).	 */
end_comment

begin_define
define|#
directive|define
name|ffesrc_char_match_init
parameter_list|(
name|c
parameter_list|,
name|up
parameter_list|,
name|low
parameter_list|)
define|\
value|(ffesrc_char_match_init_[(unsigned int) (c)] == up)
end_define

begin_define
define|#
directive|define
name|ffesrc_char_match_noninit
parameter_list|(
name|c
parameter_list|,
name|up
parameter_list|,
name|low
parameter_list|)
define|\
value|(ffesrc_char_match_noninit_[(unsigned int) (c)] == up)
end_define

begin_comment
comment|/* Translate character from input-file form to source form.  */
end_comment

begin_define
define|#
directive|define
name|ffesrc_char_source
parameter_list|(
name|c
parameter_list|)
value|(ffesrc_char_source_[(unsigned int) (c)])
end_define

begin_comment
comment|/* Translate internal character (upper/lower) to source form in an    initial-character context (i.e. ffesrc_char_match_init of the result    will always succeed).  */
end_comment

begin_define
define|#
directive|define
name|ffesrc_char_internal_init
parameter_list|(
name|up
parameter_list|,
name|low
parameter_list|)
define|\
value|(ffesrc_char_internal_init_[(unsigned int) (up)])
end_define

begin_comment
comment|/* Returns TRUE if a name representing a symbol should be checked for    validity according to compile-time options.	That is, if it is possible    that ffesrc_bad_char_symbol(c) can return something other than FFEBAD    for any valid character in an ffelex NAME(S) token.	*/
end_comment

begin_define
define|#
directive|define
name|ffesrc_check_symbol
parameter_list|()
value|ffesrc_check_symbol_
end_define

begin_define
define|#
directive|define
name|ffesrc_init_0
parameter_list|()
end_define

begin_function_decl
name|void
name|ffesrc_init_1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesrc_init_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_init_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_init_4
parameter_list|()
end_define

begin_function_decl
name|int
name|ffesrc_strcmp_1ns2i
parameter_list|(
name|ffeCase
name|mcase
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|,
name|int
name|len
parameter_list|,
specifier|const
name|char
modifier|*
name|str_ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffesrc_strcmp_2c
parameter_list|(
name|ffeCase
name|mcase
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|str_uc
parameter_list|,
specifier|const
name|char
modifier|*
name|str_lc
parameter_list|,
specifier|const
name|char
modifier|*
name|str_ic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ffesrc_strncmp_2c
parameter_list|(
name|ffeCase
name|mcase
parameter_list|,
specifier|const
name|char
modifier|*
name|var
parameter_list|,
specifier|const
name|char
modifier|*
name|str_uc
parameter_list|,
specifier|const
name|char
modifier|*
name|str_lc
parameter_list|,
specifier|const
name|char
modifier|*
name|str_ic
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ffesrc_terminate_0
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_terminate_1
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_terminate_2
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_terminate_3
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ffesrc_terminate_4
parameter_list|()
end_define

begin_comment
comment|/* End of #include file. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_F_SRC_H */
end_comment

end_unit

