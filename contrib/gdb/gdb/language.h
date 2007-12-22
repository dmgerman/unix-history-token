begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Source-language-related definitions for GDB.     Copyright 1991, 1992, 1993, 1994, 1995, 1998, 1999, 2000, 2003,    2004 Free Software Foundation, Inc.     Contributed by the Department of Computer Science at the State University    of New York at Buffalo.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_comment
comment|/* enum exp_opcode;     ANSI's `wisdom' didn't include forward enum decls. */
end_comment

begin_comment
comment|/* This used to be included to configure GDB for one or more specific    languages.  Now it is left out to configure for all of them.  FIXME.  */
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
name|_LANG_fortran
end_define

begin_define
define|#
directive|define
name|_LANG_pascal
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

begin_comment
comment|/* case_mode ==    case_mode_auto:   case_sensitivity set upon selection of scope     case_mode_manual: case_sensitivity set only by user.  */
end_comment

begin_enum
specifier|extern
enum|enum
name|case_mode
block|{
name|case_mode_auto
block|,
name|case_mode_manual
block|}
name|case_mode
enum|;
end_enum

begin_comment
comment|/* case_sensitivity ==    case_sensitive_on:   Case sensitivity in name matching is used    case_sensitive_off:  Case sensitivity in name matching is not used  */
end_comment

begin_enum
specifier|extern
enum|enum
name|case_sensitivity
block|{
name|case_sensitive_on
block|,
name|case_sensitive_off
block|}
name|case_sensitivity
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
comment|/* The format that can be passed directly to standard C printf functions        to generate a completely formatted value in the format appropriate for        the language. */
name|char
modifier|*
name|la_format
decl_stmt|;
comment|/* The prefix to be used when directly printing a value, or constructing        a standard C printf format.  This generally is everything up to the        conversion specification (the part introduced by the '%' character        and terminated by the conversion specifier character). */
name|char
modifier|*
name|la_format_prefix
decl_stmt|;
comment|/* The conversion specifier.  This is generally everything after the        field width and precision, typically only a single character such        as 'o' for octal format or 'x' for hexadecimal format. */
name|char
modifier|*
name|la_format_specifier
decl_stmt|;
comment|/* The suffix to be used when directly printing a value, or constructing        a standard C printf format.  This generally is everything after the        conversion specification (the part introduced by the '%' character        and terminated by the conversion specifier character). */
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
comment|/* Its builtin types.  This is a vector ended by a NULL pointer.  These        types can be specified by name in parsing types in expressions,        regardless of whether the program being debugged actually defines        such a type.  */
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
comment|/* Default case sensitivity */
name|enum
name|case_sensitivity
name|la_case_sensitivity
decl_stmt|;
comment|/* Definitions related to expression printing, prefixifying, and        dumping */
specifier|const
name|struct
name|exp_descriptor
modifier|*
name|la_exp_desc
decl_stmt|;
comment|/* Parser function. */
name|int
function_decl|(
modifier|*
name|la_parser
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Parser error function */
name|void
function_decl|(
modifier|*
name|la_error
function_decl|)
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|la_printchar
function_decl|)
parameter_list|(
name|int
name|ch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|la_printstr
function_decl|)
parameter_list|(
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|,
name|char
modifier|*
name|string
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|,
name|int
name|width
parameter_list|,
name|int
name|force_ellipses
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|la_emitchar
function_decl|)
parameter_list|(
name|int
name|ch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|stream
parameter_list|,
name|int
name|quoter
parameter_list|)
function_decl|;
name|struct
name|type
modifier|*
function_decl|(
modifier|*
name|la_fund_type
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Print a type using syntax appropriate for this language. */
name|void
function_decl|(
modifier|*
name|la_print_type
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Print a value using syntax appropriate for this language. */
name|int
function_decl|(
modifier|*
name|la_val_print
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|)
function_decl|;
comment|/* Print a top-level value using syntax appropriate for this language. */
name|int
function_decl|(
modifier|*
name|la_value_print
function_decl|)
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|val_prettyprint
parameter_list|)
function_decl|;
comment|/* PC is possibly an unknown languages trampoline.        If that PC falls in a trampoline belonging to this language,        return the address of the first pc in the real function, or 0        if it isn't a language tramp for this language.  */
name|CORE_ADDR
function_decl|(
modifier|*
name|skip_trampoline
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
comment|/* Now come some hooks for lookup_symbol.  */
comment|/* If this is non-NULL, lookup_symbol will do the 'field_of_this'        check, using this function to find the value of this.  */
comment|/* FIXME: carlton/2003-05-19: Audit all the language_defn structs        to make sure we're setting this appropriately: I'm sure it        could be NULL in more languages.  */
name|struct
name|value
modifier|*
function_decl|(
modifier|*
name|la_value_of_this
function_decl|)
parameter_list|(
name|int
name|complain
parameter_list|)
function_decl|;
comment|/* This is a function that lookup_symbol will call when it gets to        the part of symbol lookup where C looks up static and global        variables.  */
name|struct
name|symbol
modifier|*
function_decl|(
modifier|*
name|la_lookup_symbol_nonlocal
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|block
modifier|*
parameter_list|,
specifier|const
name|domain_enum
parameter_list|,
name|struct
name|symtab
modifier|*
modifier|*
parameter_list|)
function_decl|;
comment|/* Find the definition of the type with the given name.  */
name|struct
name|type
modifier|*
function_decl|(
modifier|*
name|la_lookup_transparent_type
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* Return demangled language symbol, or NULL.  */
name|char
modifier|*
function_decl|(
modifier|*
name|la_demangle
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|mangled
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
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
comment|/* Zero if the language has first-class arrays.  True if there are no        array values, and array objects decay to pointers, as in C. */
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
comment|/* The list of characters forming word boundaries.  */
name|char
modifier|*
function_decl|(
modifier|*
name|la_word_break_characters
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
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
comment|/* Pointer to the language_defn for our current language.  This pointer    always points to *some* valid struct; it can be used without checking    it for validity.     The current language affects expression parsing and evaluation    (FIXME: it might be cleaner to make the evaluation-related stuff    separate exp_opcodes for each different set of semantics.  We    should at least think this through more clearly with respect to    what happens if the language is changed between parsing and    evaluation) and printing of things like types and arrays.  It does    *not* affect symbol-reading-- each source file in a symbol-file has    its own language and we should keep track of that regardless of the    language when symbols are read.  If we want some manual setting for    the language of symbol files (e.g. detecting when ".c" files are    C++), it should be a separate setting from the current_language.  */
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
comment|/* language_mode ==     language_mode_auto:   current_language automatically set upon selection    of scope (e.g. stack frame)    language_mode_manual: current_language set only by user.  */
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
value|(current_language->la_language == language_c  || \ 			    current_language->la_language == language_cplus || \ 			    current_language->la_language == language_objc)
end_define

begin_function_decl
specifier|extern
name|void
name|language_info
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|language
name|set_language
parameter_list|(
name|enum
name|language
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|char
modifier|*
name|local_decimal_format_custom
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* language.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|local_octal_format_custom
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* language.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|local_hex_format_custom
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* language.c */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* FIXME: cagney/2000-03-04: This function does not appear to be used.    It can be deleted once 5.0 has been released. */
end_comment

begin_comment
comment|/* Return a string that contains the hex digits of the number.  No preceeding    "0x" */
end_comment

begin_endif
unit|extern char *longest_raw_hex_string (LONGEST);
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return a string that contains a number formatted in one of the local    (language-specific) formats.  Result is static and is overwritten by    the next call.  Takes printf options like "08l" or "l".  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|local_hex_string
parameter_list|(
name|LONGEST
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* language.c */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|local_hex_string_custom
parameter_list|(
name|LONGEST
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* language.c */
end_comment

begin_comment
comment|/* Type predicates */
end_comment

begin_function_decl
specifier|extern
name|int
name|simple_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ordered_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|same_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|integral_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|numeric_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|character_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|boolean_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|float_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pointer_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|structured_type
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|binop_type_check
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|,
name|struct
name|value
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Error messages */
end_comment

begin_function_decl
specifier|extern
name|void
name|op_error
parameter_list|(
specifier|const
name|char
modifier|*
name|lhs
parameter_list|,
name|enum
name|exp_opcode
parameter_list|,
specifier|const
name|char
modifier|*
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|type_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|range_error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTR_FORMAT
parameter_list|(
name|printf
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Data:  Does this value represent "truth" to the current language?  */
end_comment

begin_function_decl
specifier|extern
name|int
name|value_true
parameter_list|(
name|struct
name|value
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|lang_bool_type
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|enum
name|language
name|language_enum
parameter_list|(
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|struct
name|language_defn
modifier|*
name|language_def
parameter_list|(
name|enum
name|language
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|language_str
parameter_list|(
name|enum
name|language
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Add a language to the set known by GDB (at initialization time).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|add_language
parameter_list|(
specifier|const
name|struct
name|language_defn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|language
name|get_frame_language
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In stack.c */
end_comment

begin_comment
comment|/* Check for a language-specific trampoline. */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|skip_language_trampoline
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return demangled language symbol, or NULL.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|language_demangle
parameter_list|(
specifier|const
name|struct
name|language_defn
modifier|*
name|current_language
parameter_list|,
specifier|const
name|char
modifier|*
name|mangled
parameter_list|,
name|int
name|options
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Splitting strings into words.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|default_word_break_characters
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (LANGUAGE_H) */
end_comment

end_unit

