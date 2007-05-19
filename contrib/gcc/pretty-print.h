begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for language-independent pretty-print subroutines.    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@integrable-solutions.net>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_PRETTY_PRINT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_PRETTY_PRINT_H
end_define

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"input.h"
end_include

begin_comment
comment|/* Maximum number of format string arguments.  */
end_comment

begin_define
define|#
directive|define
name|PP_NL_ARGMAX
value|30
end_define

begin_comment
comment|/* The type of a text to be formatted according a format specification    along with a list of things.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
specifier|const
name|char
modifier|*
name|format_spec
decl_stmt|;
name|va_list
modifier|*
name|args_ptr
decl_stmt|;
name|int
name|err_no
decl_stmt|;
comment|/* for %m */
name|location_t
modifier|*
name|locus
decl_stmt|;
block|}
name|text_info
typedef|;
end_typedef

begin_comment
comment|/* How often diagnostics are prefixed by their locations:    o DIAGNOSTICS_SHOW_PREFIX_NEVER: never - not yet supported;    o DIAGNOSTICS_SHOW_PREFIX_ONCE: emit only once;    o DIAGNOSTICS_SHOW_PREFIX_EVERY_LINE: emit each time a physical    line is started.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DIAGNOSTICS_SHOW_PREFIX_ONCE
init|=
literal|0x0
block|,
name|DIAGNOSTICS_SHOW_PREFIX_NEVER
init|=
literal|0x1
block|,
name|DIAGNOSTICS_SHOW_PREFIX_EVERY_LINE
init|=
literal|0x2
block|}
name|diagnostic_prefixing_rule_t
typedef|;
end_typedef

begin_comment
comment|/* The chunk_info data structure forms a stack of the results from the    first phase of formatting (pp_base_format) which have not yet been    output (pp_base_output_formatted_text).  A stack is necessary because    the diagnostic starter may decide to generate its own output by way    of the formatter.  */
end_comment

begin_struct
struct|struct
name|chunk_info
block|{
comment|/* Pointer to previous chunk on the stack.  */
name|struct
name|chunk_info
modifier|*
name|prev
decl_stmt|;
comment|/* Array of chunks to output.  Each chunk is a NUL-terminated string.      In the first phase of formatting, even-numbered chunks are      to be output verbatim, odd-numbered chunks are format specifiers.      The second phase replaces all odd-numbered chunks with formatted      text, and the third phase simply emits all the chunks in sequence      with appropriate line-wrapping.  */
specifier|const
name|char
modifier|*
name|args
index|[
name|PP_NL_ARGMAX
operator|*
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The output buffer datatype.  This is best seen as an abstract datatype    whose fields should not be accessed directly by clients.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Obstack where the text is built up.  */
name|struct
name|obstack
name|formatted_obstack
decl_stmt|;
comment|/* Obstack containing a chunked representation of the format      specification plus arguments.  */
name|struct
name|obstack
name|chunk_obstack
decl_stmt|;
comment|/* Currently active obstack: one of the above two.  This is used so      that the text formatters don't need to know which phase we're in.  */
name|struct
name|obstack
modifier|*
name|obstack
decl_stmt|;
comment|/* Stack of chunk arrays.  These come from the chunk_obstack.  */
name|struct
name|chunk_info
modifier|*
name|cur_chunk_array
decl_stmt|;
comment|/* Where to output formatted text.  */
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* The amount of characters output so far.  */
name|int
name|line_length
decl_stmt|;
comment|/* This must be large enough to hold any printed integer or      floating-point value.  */
name|char
name|digit_buffer
index|[
literal|128
index|]
decl_stmt|;
block|}
name|output_buffer
typedef|;
end_typedef

begin_comment
comment|/* The type of pretty-printer flags passed to clients.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|pp_flags
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|pp_none
block|,
name|pp_before
block|,
name|pp_after
block|}
name|pp_padding
typedef|;
end_typedef

begin_comment
comment|/* Structure for switching in and out of verbatim mode in a convenient    manner.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* Current prefixing rule.  */
name|diagnostic_prefixing_rule_t
name|rule
decl_stmt|;
comment|/* The ideal upper bound of number of characters per line, as suggested      by front-end.  */
name|int
name|line_cutoff
decl_stmt|;
block|}
name|pp_wrapping_mode_t
typedef|;
end_typedef

begin_comment
comment|/* Maximum characters per line in automatic line wrapping mode.    Zero means don't wrap lines.  */
end_comment

begin_define
define|#
directive|define
name|pp_line_cutoff
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->wrapping.line_cutoff
end_define

begin_comment
comment|/* Prefixing rule used in formatting a diagnostic message.  */
end_comment

begin_define
define|#
directive|define
name|pp_prefixing_rule
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->wrapping.rule
end_define

begin_comment
comment|/* Get or set the wrapping mode as a single entity.  */
end_comment

begin_define
define|#
directive|define
name|pp_wrapping_mode
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->wrapping
end_define

begin_comment
comment|/* The type of a hook that formats client-specific data onto a pretty_pinter.    A client-supplied formatter returns true if everything goes well,    otherwise it returns false.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pretty_print_info
name|pretty_printer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|printer_fn
function_decl|)
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
name|text_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Client supplied function used to decode formats.  */
end_comment

begin_define
define|#
directive|define
name|pp_format_decoder
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->format_decoder
end_define

begin_comment
comment|/* TRUE if a newline character needs to be added before further    formatting.  */
end_comment

begin_define
define|#
directive|define
name|pp_needs_newline
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->need_newline
end_define

begin_comment
comment|/* True if PRETTY-PTINTER is in line-wrapping mode.  */
end_comment

begin_define
define|#
directive|define
name|pp_is_wrapping_line
parameter_list|(
name|PP
parameter_list|)
value|(pp_line_cutoff (PP)> 0)
end_define

begin_comment
comment|/* The amount of whitespace to be emitted when starting a new line.  */
end_comment

begin_define
define|#
directive|define
name|pp_indentation
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->indent_skip
end_define

begin_comment
comment|/* The data structure that contains the bare minimum required to do    proper pretty-printing.  Clients may derived from this structure    and add additional fields they need.  */
end_comment

begin_struct
struct|struct
name|pretty_print_info
block|{
comment|/* Where we print external representation of ENTITY.  */
name|output_buffer
modifier|*
name|buffer
decl_stmt|;
comment|/* The prefix for each new line.  */
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* Where to put whitespace around the entity being formatted.  */
name|pp_padding
name|padding
decl_stmt|;
comment|/* The real upper bound of number of characters per line, taking into      account the case of a very very looong prefix.  */
name|int
name|maximum_length
decl_stmt|;
comment|/* Indentation count.  */
name|int
name|indent_skip
decl_stmt|;
comment|/* Current wrapping mode.  */
name|pp_wrapping_mode_t
name|wrapping
decl_stmt|;
comment|/* If non-NULL, this function formats a TEXT into the BUFFER.  When called,      TEXT->format_spec points to a format code.  FORMAT_DECODER should call      pp_string (and related functions) to add data to the BUFFER.      FORMAT_DECODER can read arguments from *TEXT->args_pts using VA_ARG.      If the BUFFER needs additional characters from the format string, it      should advance the TEXT->format_spec as it goes.  When FORMAT_DECODER      returns, TEXT->format_spec should point to the last character processed.   */
name|printer_fn
name|format_decoder
decl_stmt|;
comment|/* Nonzero if current PREFIX was emitted at least once.  */
name|bool
name|emitted_prefix
decl_stmt|;
comment|/* Nonzero means one should emit a newline before outputting anything.  */
name|bool
name|need_newline
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|pp_set_line_maximum_length
parameter_list|(
name|PP
parameter_list|,
name|L
parameter_list|)
define|\
value|pp_base_set_line_maximum_length (pp_base (PP), L)
end_define

begin_define
define|#
directive|define
name|pp_set_prefix
parameter_list|(
name|PP
parameter_list|,
name|P
parameter_list|)
value|pp_base_set_prefix (pp_base (PP), P)
end_define

begin_define
define|#
directive|define
name|pp_destroy_prefix
parameter_list|(
name|PP
parameter_list|)
value|pp_base_destroy_prefix (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_remaining_character_count_for_line
parameter_list|(
name|PP
parameter_list|)
define|\
value|pp_base_remaining_character_count_for_line (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_clear_output_area
parameter_list|(
name|PP
parameter_list|)
define|\
value|pp_base_clear_output_area (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_formatted_text
parameter_list|(
name|PP
parameter_list|)
value|pp_base_formatted_text (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_last_position_in_text
parameter_list|(
name|PP
parameter_list|)
define|\
value|pp_base_last_position_in_text (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_emit_prefix
parameter_list|(
name|PP
parameter_list|)
value|pp_base_emit_prefix (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_append_text
parameter_list|(
name|PP
parameter_list|,
name|B
parameter_list|,
name|E
parameter_list|)
define|\
value|pp_base_append_text (pp_base (PP), B, E)
end_define

begin_define
define|#
directive|define
name|pp_flush
parameter_list|(
name|PP
parameter_list|)
value|pp_base_flush (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_format
parameter_list|(
name|PP
parameter_list|,
name|TI
parameter_list|)
value|pp_base_format (pp_base (PP), TI)
end_define

begin_define
define|#
directive|define
name|pp_output_formatted_text
parameter_list|(
name|PP
parameter_list|)
define|\
value|pp_base_output_formatted_text (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_format_verbatim
parameter_list|(
name|PP
parameter_list|,
name|TI
parameter_list|)
define|\
value|pp_base_format_verbatim (pp_base (PP), TI)
end_define

begin_define
define|#
directive|define
name|pp_character
parameter_list|(
name|PP
parameter_list|,
name|C
parameter_list|)
value|pp_base_character (pp_base (PP), C)
end_define

begin_define
define|#
directive|define
name|pp_string
parameter_list|(
name|PP
parameter_list|,
name|S
parameter_list|)
value|pp_base_string (pp_base (PP), S)
end_define

begin_define
define|#
directive|define
name|pp_newline
parameter_list|(
name|PP
parameter_list|)
value|pp_base_newline (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_space
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, ' ')
end_define

begin_define
define|#
directive|define
name|pp_left_paren
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '(')
end_define

begin_define
define|#
directive|define
name|pp_right_paren
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, ')')
end_define

begin_define
define|#
directive|define
name|pp_left_bracket
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '[')
end_define

begin_define
define|#
directive|define
name|pp_right_bracket
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, ']')
end_define

begin_define
define|#
directive|define
name|pp_left_brace
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '{')
end_define

begin_define
define|#
directive|define
name|pp_right_brace
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '}')
end_define

begin_define
define|#
directive|define
name|pp_semicolon
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, ';')
end_define

begin_define
define|#
directive|define
name|pp_comma
parameter_list|(
name|PP
parameter_list|)
value|pp_string (PP, ", ")
end_define

begin_define
define|#
directive|define
name|pp_dot
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '.')
end_define

begin_define
define|#
directive|define
name|pp_colon
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, ':')
end_define

begin_define
define|#
directive|define
name|pp_colon_colon
parameter_list|(
name|PP
parameter_list|)
value|pp_string (PP, "::")
end_define

begin_define
define|#
directive|define
name|pp_arrow
parameter_list|(
name|PP
parameter_list|)
value|pp_string (PP, "->")
end_define

begin_define
define|#
directive|define
name|pp_equal
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '=')
end_define

begin_define
define|#
directive|define
name|pp_question
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '?')
end_define

begin_define
define|#
directive|define
name|pp_bar
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '|')
end_define

begin_define
define|#
directive|define
name|pp_carret
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '^')
end_define

begin_define
define|#
directive|define
name|pp_ampersand
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '&')
end_define

begin_define
define|#
directive|define
name|pp_less
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '<')
end_define

begin_define
define|#
directive|define
name|pp_greater
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '>')
end_define

begin_define
define|#
directive|define
name|pp_plus
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '+')
end_define

begin_define
define|#
directive|define
name|pp_minus
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '-')
end_define

begin_define
define|#
directive|define
name|pp_star
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '*')
end_define

begin_define
define|#
directive|define
name|pp_slash
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '/')
end_define

begin_define
define|#
directive|define
name|pp_modulo
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '%')
end_define

begin_define
define|#
directive|define
name|pp_exclamation
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '!')
end_define

begin_define
define|#
directive|define
name|pp_complement
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '~')
end_define

begin_define
define|#
directive|define
name|pp_quote
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '\'')
end_define

begin_define
define|#
directive|define
name|pp_backquote
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '`')
end_define

begin_define
define|#
directive|define
name|pp_doublequote
parameter_list|(
name|PP
parameter_list|)
value|pp_character (PP, '"')
end_define

begin_define
define|#
directive|define
name|pp_newline_and_indent
parameter_list|(
name|PP
parameter_list|,
name|N
parameter_list|)
define|\
value|do {                               \     pp_indentation (PP) += N;        \     pp_newline (PP);                 \     pp_base_indent (pp_base (PP));   \     pp_needs_newline (PP) = false;   \   } while (0)
end_define

begin_define
define|#
directive|define
name|pp_maybe_newline_and_indent
parameter_list|(
name|PP
parameter_list|,
name|N
parameter_list|)
define|\
value|if (pp_needs_newline (PP)) pp_newline_and_indent (PP, N)
end_define

begin_define
define|#
directive|define
name|pp_maybe_space
parameter_list|(
name|PP
parameter_list|)
value|pp_base_maybe_space (pp_base (PP))
end_define

begin_define
define|#
directive|define
name|pp_separate_with
parameter_list|(
name|PP
parameter_list|,
name|C
parameter_list|)
define|\
value|do {                             \      pp_character (PP, C);          \      pp_space (PP);                 \    } while (0)
end_define

begin_define
define|#
directive|define
name|pp_scalar
parameter_list|(
name|PP
parameter_list|,
name|FORMAT
parameter_list|,
name|SCALAR
parameter_list|)
define|\
value|do					        	      \     {			         			      \       sprintf (pp_buffer (PP)->digit_buffer, FORMAT, SCALAR); \       pp_string (PP, pp_buffer (PP)->digit_buffer);           \     }						              \   while (0)
end_define

begin_define
define|#
directive|define
name|pp_decimal_int
parameter_list|(
name|PP
parameter_list|,
name|I
parameter_list|)
value|pp_scalar (PP, "%d", I)
end_define

begin_define
define|#
directive|define
name|pp_wide_integer
parameter_list|(
name|PP
parameter_list|,
name|I
parameter_list|)
define|\
value|pp_scalar (PP, HOST_WIDE_INT_PRINT_DEC, (HOST_WIDE_INT) I)
end_define

begin_define
define|#
directive|define
name|pp_widest_integer
parameter_list|(
name|PP
parameter_list|,
name|I
parameter_list|)
define|\
value|pp_scalar (PP, HOST_WIDEST_INT_PRINT_DEC, (HOST_WIDEST_INT) I)
end_define

begin_define
define|#
directive|define
name|pp_pointer
parameter_list|(
name|PP
parameter_list|,
name|P
parameter_list|)
value|pp_scalar (PP, "%p", P)
end_define

begin_define
define|#
directive|define
name|pp_identifier
parameter_list|(
name|PP
parameter_list|,
name|ID
parameter_list|)
value|pp_string (PP, ID)
end_define

begin_define
define|#
directive|define
name|pp_tree_identifier
parameter_list|(
name|PP
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_append_text(PP, IDENTIFIER_POINTER (T), \                  IDENTIFIER_POINTER (T) + IDENTIFIER_LENGTH (T))
end_define

begin_define
define|#
directive|define
name|pp_unsupported_tree
parameter_list|(
name|PP
parameter_list|,
name|T
parameter_list|)
define|\
value|pp_verbatim (pp_base (PP), "#%qs not supported by %s#", \                tree_code_name[(int) TREE_CODE (T)], __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|pp_buffer
parameter_list|(
name|PP
parameter_list|)
value|pp_base (PP)->buffer
end_define

begin_comment
comment|/* Clients that directly derive from pretty_printer need to override    this macro to return a pointer to the base pretty_printer structure.  */
end_comment

begin_define
define|#
directive|define
name|pp_base
parameter_list|(
name|PP
parameter_list|)
value|(PP)
end_define

begin_function_decl
specifier|extern
name|void
name|pp_construct
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_set_line_maximum_length
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_set_prefix
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_destroy_prefix
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pp_base_remaining_character_count_for_line
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_clear_output_area
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pp_base_formatted_text
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pp_base_last_position_in_text
parameter_list|(
specifier|const
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_emit_prefix
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_append_text
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This header may be included before toplev.h, hence the duplicate    definitions to allow for GCC-specific formats.  */
end_comment

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3005
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_PPDIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (__gcc_diag__, m ,n))) ATTRIBUTE_NONNULL(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_PPDIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|ATTRIBUTE_NONNULL(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|pp_printf
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_PPDIAG
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|pp_verbatim
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_PPDIAG
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
specifier|extern
name|void
name|pp_base_flush
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_format
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
name|text_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_output_formatted_text
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_format_verbatim
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
name|text_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_indent
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_newline
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_character
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_string
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_write_text_to_stream
parameter_list|(
name|pretty_printer
modifier|*
name|pp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pp_base_maybe_space
parameter_list|(
name|pretty_printer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Switch into verbatim mode and return the old mode.  */
end_comment

begin_function
specifier|static
specifier|inline
name|pp_wrapping_mode_t
name|pp_set_verbatim_wrapping_
parameter_list|(
name|pretty_printer
modifier|*
name|pp
parameter_list|)
block|{
name|pp_wrapping_mode_t
name|oldmode
init|=
name|pp_wrapping_mode
argument_list|(
name|pp
argument_list|)
decl_stmt|;
name|pp_line_cutoff
argument_list|(
name|pp
argument_list|)
operator|=
literal|0
expr_stmt|;
name|pp_prefixing_rule
argument_list|(
name|pp
argument_list|)
operator|=
name|DIAGNOSTICS_SHOW_PREFIX_NEVER
expr_stmt|;
return|return
name|oldmode
return|;
block|}
end_function

begin_define
define|#
directive|define
name|pp_set_verbatim_wrapping
parameter_list|(
name|PP
parameter_list|)
value|pp_set_verbatim_wrapping_ (pp_base (PP))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_PRETTY_PRINT_H */
end_comment

end_unit

