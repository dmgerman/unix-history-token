begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Source-language-related definitions for GDB.    Copyright 1991, 1992 Free Software Foundation, Inc.    Contributed by the Department of Computer Science at the State University    of New York at Buffalo.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|expression
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

begin_define
define|#
directive|define
name|_LANG_chill
end_define

begin_define
define|#
directive|define
name|_LANG_fortran
end_define

begin_define
define|#
directive|define
name|MAX_FORTRAN_DIMS
value|7
end_define

begin_comment
comment|/* Maximum number of F77 array dims */
end_comment

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
comment|/* Information for doing language dependent formatting of printed values. */
end_comment

begin_struct
struct|struct
name|language_format_info
block|{
comment|/* The format that can be passed directly to standard C printf functions      to generate a completely formatted value in the format appropriate for      the language. */
name|char
modifier|*
name|la_format
decl_stmt|;
comment|/* The prefix to be used when directly printing a value, or constructing      a standard C printf format.  This generally is everything up to the      conversion specification (the part introduced by the '%' character      and terminated by the conversion specifier character). */
name|char
modifier|*
name|la_format_prefix
decl_stmt|;
comment|/* The conversion specifier.  This is generally everything after the      field width and precision, typically only a single character such      as 'o' for octal format or 'x' for hexadecimal format. */
name|char
modifier|*
name|la_format_specifier
decl_stmt|;
comment|/* The suffix to be used when directly printing a value, or constructing      a standard C printf format.  This generally is everything after the      conversion specification (the part introduced by the '%' character      and terminated by the conversion specifier character). */
name|char
modifier|*
name|la_format_suffix
decl_stmt|;
comment|/* Suffix for custom format string */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure tying together assorted information about a language.  */
end_comment

begin_struct
struct|struct
name|language_defn
block|{
comment|/* Name of the language */
name|char
modifier|*
name|la_name
decl_stmt|;
comment|/* its symtab language-enum (defs.h) */
name|enum
name|language
name|la_language
decl_stmt|;
comment|/* Its builtin types.  This is a vector ended by a NULL pointer.  These      types can be specified by name in parsing types in expressions,      regardless of whether the program being debugged actually defines      such a type.  */
name|struct
name|type
modifier|*
modifier|*
specifier|const
modifier|*
name|la_builtin_type_vector
decl_stmt|;
comment|/* Default range checking */
name|enum
name|range_check
name|la_range_check
decl_stmt|;
comment|/* Default type checking */
name|enum
name|type_check
name|la_type_check
decl_stmt|;
comment|/* Parser function. */
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
comment|/* Parser error function */
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
comment|/* Evaluate an expression. */
name|struct
name|value
modifier|*
argument_list|(
operator|*
name|evaluate_exp
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
expr|struct
name|expression
operator|*
operator|,
name|int
operator|*
operator|,
expr|enum
name|noside
operator|)
argument_list|)
decl_stmt|;
name|void
argument_list|(
argument|*la_printchar
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|ch
operator|,
name|GDB_FILE
operator|*
name|stream
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*la_printstr
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|GDB_FILE
operator|*
name|stream
operator|,
name|char
operator|*
name|string
operator|,
name|unsigned
name|int
name|length
operator|,
name|int
name|width
operator|,
name|int
name|force_ellipses
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*la_emitchar
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
name|ch
operator|,
name|GDB_FILE
operator|*
name|stream
operator|,
name|int
name|quoter
operator|)
argument_list|)
expr_stmt|;
name|struct
name|type
modifier|*
argument_list|(
operator|*
name|la_fund_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
comment|/* Print a type using syntax appropriate for this language. */
name|void
argument_list|(
argument|*la_print_type
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Print a value using syntax appropriate for this language. */
name|int
argument_list|(
argument|*la_val_print
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|CORE_ADDR
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
expr_stmt|;
comment|/* Print a top-level value using syntax appropriate for this language. */
name|int
argument_list|(
argument|*la_value_print
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|value
operator|*
operator|,
name|GDB_FILE
operator|*
operator|,
name|int
operator|,
expr|enum
name|val_prettyprint
operator|)
argument_list|)
expr_stmt|;
comment|/* Base 2 (binary) formats. */
name|struct
name|language_format_info
name|la_binary_format
decl_stmt|;
comment|/* Base 8 (octal) formats. */
name|struct
name|language_format_info
name|la_octal_format
decl_stmt|;
comment|/* Base 10 (decimal) formats */
name|struct
name|language_format_info
name|la_decimal_format
decl_stmt|;
comment|/* Base 16 (hexadecimal) formats */
name|struct
name|language_format_info
name|la_hex_format
decl_stmt|;
comment|/* Table for printing expressions */
specifier|const
name|struct
name|op_print
modifier|*
name|la_op_print_tab
decl_stmt|;
comment|/* Zero if the language has first-class arrays.  True if there are no      array values, and array objects decay to pointers, as in C. */
name|char
name|c_style_arrays
decl_stmt|;
comment|/* Index to use for extracting the first element of a string. */
name|char
name|string_lower_bound
decl_stmt|;
comment|/* Type of elements of strings. */
name|struct
name|type
modifier|*
modifier|*
name|string_char_type
decl_stmt|;
comment|/* Add fields above this point, so the magic number is always last. */
comment|/* Magic number for compat checking */
name|long
name|la_magic
decl_stmt|;
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
comment|/* Pointer to the language_defn for our current language.  This pointer    always points to *some* valid struct; it can be used without checking    it for validity.     The current language affects expression parsing and evaluation    (FIXME: it might be cleaner to make the evaluation-related stuff    separate exp_opcodes for each different set of semantics.  We    should at least think this through more clearly with respect to    what happens if the language is changed between parsing and    evaluation) and printing of things like types and arrays.  It does    *not* affect symbol-reading-- each source file in a symbol-file has    its own language and we should keep track of that regardless of the    language when symbols are read.  If we want some manual setting for    the language of symbol files (e.g. detecting when ".c" files are    C++), it should be a seprate setting from the current_language.  */
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
value|(current_language->la_language == language_c  || \ 			    current_language->la_language == language_cplus)
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
name|enum
name|language
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

begin_define
define|#
directive|define
name|create_fundamental_type
parameter_list|(
name|objfile
parameter_list|,
name|typeid
parameter_list|)
define|\
value|(current_language->la_fund_type(objfile, typeid))
end_define

begin_define
define|#
directive|define
name|LA_PRINT_TYPE
parameter_list|(
name|type
parameter_list|,
name|varstring
parameter_list|,
name|stream
parameter_list|,
name|show
parameter_list|,
name|level
parameter_list|)
define|\
value|(current_language->la_print_type(type,varstring,stream,show,level))
end_define

begin_define
define|#
directive|define
name|LA_VAL_PRINT
parameter_list|(
name|type
parameter_list|,
name|valaddr
parameter_list|,
name|offset
parameter_list|,
name|addr
parameter_list|,
name|stream
parameter_list|,
name|fmt
parameter_list|,
name|deref
parameter_list|,
name|recurse
parameter_list|,
name|pretty
parameter_list|)
define|\
value|(current_language->la_val_print(type,valaddr,offset,addr,stream,fmt,deref, \ 				  recurse,pretty))
end_define

begin_define
define|#
directive|define
name|LA_VALUE_PRINT
parameter_list|(
name|val
parameter_list|,
name|stream
parameter_list|,
name|fmt
parameter_list|,
name|pretty
parameter_list|)
define|\
value|(current_language->la_value_print(val,stream,fmt,pretty))
end_define

begin_comment
comment|/* Return a format string for printf that will print a number in one of    the local (language-specific) formats.  Result is static and is    overwritten by the next call.  Takes printf options like "08" or "l"    (to produce e.g. %08x or %lx).  */
end_comment

begin_define
define|#
directive|define
name|local_binary_format
parameter_list|()
define|\
value|(current_language->la_binary_format.la_format)
end_define

begin_define
define|#
directive|define
name|local_binary_format_prefix
parameter_list|()
define|\
value|(current_language->la_binary_format.la_format_prefix)
end_define

begin_define
define|#
directive|define
name|local_binary_format_specifier
parameter_list|()
define|\
value|(current_language->la_binary_format.la_format_specifier)
end_define

begin_define
define|#
directive|define
name|local_binary_format_suffix
parameter_list|()
define|\
value|(current_language->la_binary_format.la_format_suffix)
end_define

begin_define
define|#
directive|define
name|local_octal_format
parameter_list|()
define|\
value|(current_language->la_octal_format.la_format)
end_define

begin_define
define|#
directive|define
name|local_octal_format_prefix
parameter_list|()
define|\
value|(current_language->la_octal_format.la_format_prefix)
end_define

begin_define
define|#
directive|define
name|local_octal_format_specifier
parameter_list|()
define|\
value|(current_language->la_octal_format.la_format_specifier)
end_define

begin_define
define|#
directive|define
name|local_octal_format_suffix
parameter_list|()
define|\
value|(current_language->la_octal_format.la_format_suffix)
end_define

begin_define
define|#
directive|define
name|local_decimal_format
parameter_list|()
define|\
value|(current_language->la_decimal_format.la_format)
end_define

begin_define
define|#
directive|define
name|local_decimal_format_prefix
parameter_list|()
define|\
value|(current_language->la_decimal_format.la_format_prefix)
end_define

begin_define
define|#
directive|define
name|local_decimal_format_specifier
parameter_list|()
define|\
value|(current_language->la_decimal_format.la_format_specifier)
end_define

begin_define
define|#
directive|define
name|local_decimal_format_suffix
parameter_list|()
define|\
value|(current_language->la_decimal_format.la_format_suffix)
end_define

begin_define
define|#
directive|define
name|local_hex_format
parameter_list|()
define|\
value|(current_language->la_hex_format.la_format)
end_define

begin_define
define|#
directive|define
name|local_hex_format_prefix
parameter_list|()
define|\
value|(current_language->la_hex_format.la_format_prefix)
end_define

begin_define
define|#
directive|define
name|local_hex_format_specifier
parameter_list|()
define|\
value|(current_language->la_hex_format.la_format_specifier)
end_define

begin_define
define|#
directive|define
name|local_hex_format_suffix
parameter_list|()
define|\
value|(current_language->la_hex_format.la_format_suffix)
end_define

begin_define
define|#
directive|define
name|LA_PRINT_CHAR
parameter_list|(
name|ch
parameter_list|,
name|stream
parameter_list|)
define|\
value|(current_language->la_printchar(ch, stream))
end_define

begin_define
define|#
directive|define
name|LA_PRINT_STRING
parameter_list|(
name|stream
parameter_list|,
name|string
parameter_list|,
name|length
parameter_list|,
name|width
parameter_list|,
name|force_ellipses
parameter_list|)
define|\
value|(current_language->la_printstr(stream, string, length, width, force_ellipses))
end_define

begin_define
define|#
directive|define
name|LA_EMIT_CHAR
parameter_list|(
name|ch
parameter_list|,
name|stream
parameter_list|,
name|quoter
parameter_list|)
define|\
value|(current_language->la_emitchar(ch, stream, quoter))
end_define

begin_comment
comment|/* Test a character to decide whether it can be printed in literal form    or needs to be printed in another representation.  For example,    in C the literal form of the character with octal value 141 is 'a'    and the "other representation" is '\141'.  The "other representation"    is program language dependent. */
end_comment

begin_define
define|#
directive|define
name|PRINT_LITERAL_FORM
parameter_list|(
name|c
parameter_list|)
define|\
value|((c)>= 0x20				\&& ((c)< 0x7F || (c)>= 0xA0)	\&& (!sevenbit_strings || (c)< 0x80))
end_define

begin_comment
comment|/* Return a format string for printf that will print a number in one of    the local (language-specific) formats.  Result is static and is    overwritten by the next call.  Takes printf options like "08" or "l"    (to produce e.g. %08x or %lx).  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|local_decimal_format_custom
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
comment|/* language.c */
end_comment

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
comment|/* language.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|local_hex_format_custom
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
comment|/* language.c */
end_comment

begin_comment
comment|/* Return a string that contains a number formatted in one of the local    (language-specific) formats.  Result is static and is overwritten by    the next call.  Takes printf options like "08" or "l".  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|local_hex_string
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* language.c */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|local_hex_string_custom
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|long
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* language.c */
end_comment

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

begin_decl_stmt
specifier|extern
name|void
name|type_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTR_FORMAT
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|range_error
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTR_FORMAT
argument_list|(
name|printf
argument_list|,
literal|1
argument_list|,
literal|2
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|struct
name|type
modifier|*
name|lang_bool_type
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The type used for Boolean values in the current language. */
end_comment

begin_define
define|#
directive|define
name|LA_BOOL_TYPE
value|lang_bool_type ()
end_define

begin_comment
comment|/* Misc:  The string representing a particular enum language.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|language_defn
modifier|*
name|language_def
name|PARAMS
argument_list|(
operator|(
expr|enum
name|language
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

