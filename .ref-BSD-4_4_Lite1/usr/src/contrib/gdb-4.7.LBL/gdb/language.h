begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Source-language-related definitions for GDB.    Copyright 1991, 1992 Free Software Foundation, Inc.    Contributed by the Department of Computer Science at the State University    of New York at Buffalo.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LANGUAGE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|LANGUAGE_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward decls for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_comment
comment|/* enum exp_opcode;	ANSI's `wisdom' didn't include forward enum decls. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This used to be included to configure GDB for one or more specific    languages.  Now it is shortcutted to configure for all of them.  FIXME.  */
end_comment

begin_comment
comment|/* #include "lang_def.h" */
end_comment

begin_define
define|#
directive|define
name|_LANG_c
end_define

begin_define
define|#
directive|define
name|_LANG_m2
end_define

begin_comment
comment|/* range_mode ==    range_mode_auto:   range_check set automatically to default of language.    range_mode_manual: range_check set manually by user.  */
end_comment

begin_enum
specifier|extern
enum|enum
name|range_mode
block|{
name|range_mode_auto
block|,
name|range_mode_manual
block|}
name|range_mode
enum|;
end_enum

begin_comment
comment|/* range_check ==    range_check_on:    Ranges are checked in GDB expressions, producing errors.    range_check_warn:  Ranges are checked, producing warnings.    range_check_off:   Ranges are not checked in GDB expressions.  */
end_comment

begin_enum
specifier|extern
enum|enum
name|range_check
block|{
name|range_check_off
block|,
name|range_check_warn
block|,
name|range_check_on
block|}
name|range_check
enum|;
end_enum

begin_comment
comment|/* type_mode ==    type_mode_auto:   type_check set automatically to default of language    type_mode_manual: type_check set manually by user. */
end_comment

begin_enum
specifier|extern
enum|enum
name|type_mode
block|{
name|type_mode_auto
block|,
name|type_mode_manual
block|}
name|type_mode
enum|;
end_enum

begin_comment
comment|/* type_check ==    type_check_on:    Types are checked in GDB expressions, producing errors.    type_check_warn:  Types are checked, producing warnings.    type_check_off:   Types are not checked in GDB expressions.  */
end_comment

begin_enum
specifier|extern
enum|enum
name|type_check
block|{
name|type_check_off
block|,
name|type_check_warn
block|,
name|type_check_on
block|}
name|type_check
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* Structure tying together assorted information about a language.  */
end_comment

begin_struct
struct|struct
name|language_defn
block|{
name|char
modifier|*
name|la_name
decl_stmt|;
comment|/* Name of the language */
name|enum
name|language
name|la_language
decl_stmt|;
comment|/* its symtab language-enum (defs.h) */
name|struct
name|type
modifier|*
modifier|*
specifier|const
modifier|*
name|la_builtin_type_vector
decl_stmt|;
comment|/* Its builtin types */
name|enum
name|range_check
name|la_range_check
decl_stmt|;
comment|/* Default range checking */
name|enum
name|type_check
name|la_type_check
decl_stmt|;
comment|/* Default type checking */
name|int
argument_list|(
argument|*la_parser
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Parser function */
name|void
argument_list|(
argument|*la_error
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Parser error function */
name|struct
name|type
modifier|*
modifier|*
name|la_longest_int
decl_stmt|;
comment|/* Longest signed integral type */
name|struct
name|type
modifier|*
modifier|*
name|la_longest_unsigned_int
decl_stmt|;
comment|/* Longest uns integral type */
name|struct
name|type
modifier|*
modifier|*
name|la_longest_float
decl_stmt|;
comment|/* Longest floating point type */
name|char
modifier|*
name|la_hex_format
decl_stmt|;
comment|/* Hexadecimal printf format str */
name|char
modifier|*
name|la_hex_format_pre
decl_stmt|;
comment|/* Prefix for custom format string */
name|char
modifier|*
name|la_hex_format_suf
decl_stmt|;
comment|/* Suffix for custom format string */
name|char
modifier|*
name|la_octal_format
decl_stmt|;
comment|/* Octal printf format str */
name|char
modifier|*
name|la_octal_format_pre
decl_stmt|;
comment|/* Prefix for custom format string */
name|char
modifier|*
name|la_octal_format_suf
decl_stmt|;
comment|/* Suffix for custom format string */
specifier|const
name|struct
name|op_print
modifier|*
name|la_op_print_tab
decl_stmt|;
comment|/* Table for printing expressions */
comment|/* Add fields above this point, so the magic number is always last. */
name|long
name|la_magic
decl_stmt|;
comment|/* Magic number for compat checking */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LANG_MAGIC
value|910823L
end_define

begin_comment
comment|/* Pointer to the language_defn for our current language.  This pointer    always points to *some* valid struct; it can be used without checking    it for validity.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|language_defn
modifier|*
name|current_language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to the language_defn expected by the user, e.g. the language    of main(), or the language we last mentioned in a message, or C.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|language_defn
modifier|*
name|expected_language
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* language_mode ==     language_mode_auto:   current_language automatically set upon selection 			 of scope (e.g. stack frame)    language_mode_manual: current_language set only by user.  */
end_comment

begin_enum
specifier|extern
enum|enum
name|language_mode
block|{
name|language_mode_auto
block|,
name|language_mode_manual
block|}
name|language_mode
enum|;
end_enum

begin_escape
end_escape

begin_comment
comment|/* These macros define the behaviour of the expression     evaluator.  */
end_comment

begin_comment
comment|/* Should we strictly type check expressions? */
end_comment

begin_define
define|#
directive|define
name|STRICT_TYPE
value|(type_check != type_check_off)
end_define

begin_comment
comment|/* Should we range check values against the domain of their type? */
end_comment

begin_define
define|#
directive|define
name|RANGE_CHECK
value|(range_check != range_check_off)
end_define

begin_comment
comment|/* "cast" really means conversion */
end_comment

begin_comment
comment|/* FIXME -- should be a setting in language_defn */
end_comment

begin_define
define|#
directive|define
name|CAST_IS_CONVERSION
value|(current_language->la_language == language_c)
end_define

begin_decl_stmt
specifier|extern
name|void
name|language_info
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_language
name|PARAMS
argument_list|(
operator|(
expr|enum
name|language
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* This page contains functions that return things that are    specific to languages.  Each of these functions is based on    the current setting of working_lang, which the user sets    with the "set language" command. */
end_comment

begin_comment
comment|/* Returns some built-in types */
end_comment

begin_define
define|#
directive|define
name|longest_int
parameter_list|()
value|(*current_language->la_longest_int)
end_define

begin_define
define|#
directive|define
name|longest_unsigned_int
parameter_list|()
value|(*current_language->la_longest_unsigned_int)
end_define

begin_define
define|#
directive|define
name|longest_float
parameter_list|()
value|(*current_language->la_longest_float)
end_define

begin_comment
comment|/* Hexadecimal number formatting is in defs.h because it is so common    throughout GDB.  */
end_comment

begin_comment
comment|/* Return a format string for printf that will print a number in the local    (language-specific) octal format.  Result is static and is    overwritten by the next call.  local_octal_format_custom takes printf    options like "08" or "l" (to produce e.g. %08x or %lx).  */
end_comment

begin_define
define|#
directive|define
name|local_octal_format
parameter_list|()
value|(current_language->la_octal_format)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|local_octal_format_custom
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Type predicates */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|simple_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ordered_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|same_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|integral_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numeric_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|character_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|boolean_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|float_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pointer_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|structured_type
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Checks Binary and Unary operations for semantic type correctness */
end_comment

begin_comment
comment|/* FIXME:  Does not appear to be used */
end_comment

begin_define
define|#
directive|define
name|unop_type_check
parameter_list|(
name|v
parameter_list|,
name|o
parameter_list|)
value|binop_type_check((v),NULL,(o))
end_define

begin_decl_stmt
specifier|extern
name|void
name|binop_type_check
name|PARAMS
argument_list|(
operator|(
expr|struct
name|value
operator|*
operator|,
expr|struct
name|value
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Error messages */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|op_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|fmt
operator|,
expr|enum
name|exp_opcode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|type_op_error
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|)
define|\
value|op_error((f),(o),type_check==type_check_on ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|range_op_error
parameter_list|(
name|f
parameter_list|,
name|o
parameter_list|)
define|\
value|op_error((f),(o),range_check==range_check_on ? 1 : 0)
end_define

begin_function_decl
specifier|extern
name|void
name|type_error
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|range_error
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Data:  Does this value represent "truth" to the current language?  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|value_true
name|PARAMS
argument_list|(
operator|(
expr|struct
name|value
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Misc:  The string representing a particular enum language.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|language_str
name|PARAMS
argument_list|(
operator|(
expr|enum
name|language
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Add a language to the set known by GDB (at initialization time).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_language
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|language_defn
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|language
name|get_frame_language
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In stack.c */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (LANGUAGE_H) */
end_comment

end_unit

