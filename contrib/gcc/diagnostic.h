begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for language-independent diagnostics subroutines.    Copyright (C) 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DIAGNOSTIC_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DIAGNOSTIC_H
end_define

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_comment
comment|/*  Forward declarations.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|output_buffer
name|output_buffer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|diagnostic_context
name|diagnostic_context
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
argument_list|(
argument|*diagnostic_starter_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|diagnostic_context
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|diagnostic_starter_fn
name|diagnostic_finalizer_fn
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
define|#
directive|define
name|DEFINE_DIAGNOSTIC_KIND
parameter_list|(
name|K
parameter_list|,
name|M
parameter_list|)
value|K,
include|#
directive|include
file|"diagnostic.def"
undef|#
directive|undef
name|DEFINE_DIAGNOSTIC_KIND
name|DK_LAST_DIAGNOSTIC_KIND
block|}
name|diagnostic_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|pedantic_error_kind
parameter_list|()
value|(flag_pedantic_errors ? DK_ERROR : DK_WARNING)
end_define

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
comment|/* The type of front-end specific hook that formats trees into an    output_buffer.  A language specific printer returns a truth value if    everything goes well.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*printer_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* This data structure encapsulates an output_buffer's state.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* The prefix for each new line.  */
specifier|const
name|char
modifier|*
name|prefix
decl_stmt|;
comment|/* The real upper bound of number of characters per line, taking into      account the case of a very very looong prefix.  */
name|int
name|maximum_length
decl_stmt|;
comment|/* The ideal upper bound of number of characters per line, as suggested      by front-end.  */
name|int
name|ideal_maximum_length
decl_stmt|;
comment|/* Indentation count.  */
name|int
name|indent_skip
decl_stmt|;
comment|/* Nonzero if current PREFIX was emitted at least once.  */
name|bool
name|emitted_prefix_p
decl_stmt|;
comment|/* Nonzero means one should emit a newline before outputing anything.  */
name|bool
name|need_newline_p
decl_stmt|;
comment|/* Current prefixing rule.  */
name|diagnostic_prefixing_rule_t
name|prefixing_rule
decl_stmt|;
comment|/* The current char to output.  Updated by front-end (*format_map) when      it is called to report front-end printer for a specified format.  */
specifier|const
name|char
modifier|*
name|cursor
decl_stmt|;
comment|/* A pointer to the variable argument-list for formatting.  */
name|va_list
modifier|*
name|format_args
decl_stmt|;
comment|/* The number of times we have issued diagnostics.  */
name|int
name|diagnostic_count
index|[
name|DK_LAST_DIAGNOSTIC_KIND
index|]
decl_stmt|;
block|}
name|output_state
typedef|;
end_typedef

begin_comment
comment|/* The output buffer datatype.  This is best seen as an abstract datatype.  */
end_comment

begin_struct
struct|struct
name|output_buffer
block|{
comment|/* Internal data.  These fields should not be accessed directly by      front-ends.  */
comment|/* The current state of the buffer.  */
name|output_state
name|state
decl_stmt|;
comment|/* Where to output formatted text.  */
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* The obstack where the text is built up.  */
name|struct
name|obstack
name|obstack
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
comment|/* If non-NULL, this function formats data in the BUFFER. When called,    output_buffer_text_cursor (BUFFER) points to a format code.    FORMAT_DECODER should call output_add_string (and related functions)    to add data to the BUFFER.  FORMAT_DECODER can read arguments from    output_buffer_format_args (BUFFER) using VA_ARG.  If the BUFFER needs    additional characters from the format string, it should advance    the output_buffer_text_cursor (BUFFER) as it goes.  When FORMAT_DECODER    returns, output_buffer_text_cursor (BUFFER) should point to the last    character processed.  */
name|printer_fn
name|format_decoder
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Current state of the diagnostic_context' output_buffer.  This macro    accepts both `diagnostic_context *' and `output_buffer *'.  */
end_comment

begin_define
define|#
directive|define
name|output_buffer_state
parameter_list|(
name|BUFFER
parameter_list|)
value|((output_buffer *)(BUFFER))->state
end_define

begin_comment
comment|/* The stream attached to the output_buffer, where the formatted    diagnostics will ultimately go.  Works only on `output_buffer *'.  */
end_comment

begin_define
define|#
directive|define
name|output_buffer_attached_stream
parameter_list|(
name|BUFFER
parameter_list|)
value|(BUFFER)->stream
end_define

begin_comment
comment|/* This points to the beginning of the rest of the diagnostic message    to be formatted.  Accepts only `output_buffer *'s.  */
end_comment

begin_define
define|#
directive|define
name|output_buffer_text_cursor
parameter_list|(
name|BUFFER
parameter_list|)
value|(BUFFER)->state.cursor
end_define

begin_comment
comment|/* The rest of the `variable argument list' not yet processed.    This macro works on both `output_state *' and `output_buffer *'.  */
end_comment

begin_define
define|#
directive|define
name|output_buffer_format_args
parameter_list|(
name|BUFFER
parameter_list|)
define|\
value|*(((output_state *)(BUFFER))->format_args)
end_define

begin_comment
comment|/* In line-wrapping mode, whether we should start a new line.  */
end_comment

begin_define
define|#
directive|define
name|output_needs_newline
parameter_list|(
name|BUFFER
parameter_list|)
value|(BUFFER)->state.need_newline_p
end_define

begin_comment
comment|/* The amount of whitespace to be emitted when starting a new line.  */
end_comment

begin_define
define|#
directive|define
name|output_indentation
parameter_list|(
name|BUFFER
parameter_list|)
value|(BUFFER)->state.indent_skip
end_define

begin_comment
comment|/* A pointer to the formatted diagonstic message.  */
end_comment

begin_define
define|#
directive|define
name|output_message_text
parameter_list|(
name|BUFFER
parameter_list|)
define|\
value|((const char *) obstack_base (&(BUFFER)->obstack))
end_define

begin_comment
comment|/* This data structure bundles altogether any information relevant to    the context of a diagnostic message.  */
end_comment

begin_struct
struct|struct
name|diagnostic_context
block|{
comment|/* Where most of the diagnostic formatting work is done.  In Object      Oriented terms, we'll say that diagnostic_context is a sub-class of      output_buffer.  */
name|output_buffer
name|buffer
decl_stmt|;
comment|/* The diagnostic message to output.  */
specifier|const
name|char
modifier|*
name|message
decl_stmt|;
comment|/* A pointer to a variable list of the arguments necessary for the      purpose of message formatting.  */
name|va_list
modifier|*
name|args_ptr
decl_stmt|;
comment|/* The name of the source file involved in the diiagnostic.  */
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
comment|/* The line-location in the source file.  */
name|int
name|line
decl_stmt|;
comment|/* Is this message a warning?  */
name|int
name|warn
decl_stmt|;
comment|/* This function is called before any message is printed out.  It is      responsible for preparing message prefix and such.  For example, it      might say:      In file included from "/usr/local/include/curses.h:5:                       from "/home/gdr/src/nifty_printer.h:56:                       ...   */
name|void
argument_list|(
argument|*begin_diagnostic
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|diagnostic_context
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* This function is called after the diagnostic message is printed.  */
name|void
argument_list|(
argument|*end_diagnostic
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|diagnostic_context
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Hook for front-end extensions.  */
name|void
modifier|*
name|x_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The diagnostic message being formatted.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_message
parameter_list|(
name|DC
parameter_list|)
value|(DC)->message
end_define

begin_comment
comment|/* A pointer to the variable argument list used in a call    to a diagonstic routine.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_argument_list
parameter_list|(
name|DC
parameter_list|)
value|(DC)->args_ptr
end_define

begin_comment
comment|/* The program file to which the diagnostic is referring to.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_file_location
parameter_list|(
name|DC
parameter_list|)
value|(DC)->file
end_define

begin_comment
comment|/* The program source line referred to in the diagnostic message.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_line_location
parameter_list|(
name|DC
parameter_list|)
value|(DC)->line
end_define

begin_comment
comment|/* Tell whether the diagnostic message is to be treated as a warning.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_is_warning
parameter_list|(
name|DC
parameter_list|)
value|(DC)->warn
end_define

begin_comment
comment|/* Client supplied function to announce a diagnostic.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_starter
parameter_list|(
name|DC
parameter_list|)
value|(DC)->begin_diagnostic
end_define

begin_comment
comment|/* Client supplied function called after a diagnostic message is    displayed.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_finalizer
parameter_list|(
name|DC
parameter_list|)
value|(DC)->end_diagnostic
end_define

begin_comment
comment|/* Extension hook for client.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_auxiliary_data
parameter_list|(
name|DC
parameter_list|)
value|(DC)->x_data
end_define

begin_comment
comment|/* Client supplied function used to decode formats.  Can operate on both  `output_buffer *' and `diagnostic_context *'.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_format_decoder
parameter_list|(
name|DC
parameter_list|)
value|((output_buffer *)(DC))->format_decoder
end_define

begin_comment
comment|/* Prefixing rule used in formatting a diagnostic message.  Accepts both    `output_buffer *' and `diagnostic_context *'.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_prefixing_rule
parameter_list|(
name|DC
parameter_list|)
define|\
value|((output_buffer *)(DC))->state.prefixing_rule
end_define

begin_comment
comment|/* Maximum characters per line in automatic line wrapping mode.    Zero means don't wrap lines.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_line_cutoff
parameter_list|(
name|DC
parameter_list|)
define|\
value|((output_buffer *)(DC))->state.ideal_maximum_length
end_define

begin_comment
comment|/* This diagnostic context is used by front-ends that directly output    diagnostic messages without going through `error', `warning',    and similar functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|diagnostic_context
modifier|*
name|global_dc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This will be removed shortly.  */
end_comment

begin_decl_stmt
specifier|extern
name|output_buffer
modifier|*
name|diagnostic_buffer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The total count of a KIND of diagnostics meitted so far.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_kind_count
parameter_list|(
name|DC
parameter_list|,
name|DK
parameter_list|)
define|\
value|((output_buffer *)(DC))->state.diagnostic_count[(int) (DK)]
end_define

begin_comment
comment|/* The number of errors that have been issued so far.  Ideally, these    would take an output_buffer as an argument.  */
end_comment

begin_define
define|#
directive|define
name|errorcount
value|diagnostic_kind_count (global_dc, DK_ERROR)
end_define

begin_comment
comment|/* Similarly, but for warnings.  */
end_comment

begin_define
define|#
directive|define
name|warningcount
value|diagnostic_kind_count (global_dc, DK_WARNING)
end_define

begin_comment
comment|/* Similarly, but for sorrys.  */
end_comment

begin_define
define|#
directive|define
name|sorrycount
value|diagnostic_kind_count (global_dc, DK_SORRY)
end_define

begin_comment
comment|/* Returns non-zero if warnings should be emitted.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_report_warnings_p
parameter_list|()
define|\
value|(!inhibit_warnings					\&& !(in_system_header&& !warn_system_headers))
end_define

begin_comment
comment|/* Prototypes */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|set_diagnostic_context
name|PARAMS
argument_list|(
operator|(
name|diagnostic_context
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|*
operator|,
specifier|const
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
name|void
name|set_internal_error_function
name|PARAMS
argument_list|(
operator|(
name|void
argument_list|(
argument|*
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|*
operator|)
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|report_diagnostic
name|PARAMS
argument_list|(
operator|(
name|diagnostic_context
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|diagnostic_initialize
name|PARAMS
argument_list|(
operator|(
name|diagnostic_context
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_output_buffer
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
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
name|void
name|flush_diagnostic_buffer
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_clear
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|output_get_prefix
name|PARAMS
argument_list|(
operator|(
specifier|const
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|output_last_position
name|PARAMS
argument_list|(
operator|(
specifier|const
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_set_prefix
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_destroy_prefix
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_set_maximum_length
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_emit_prefix
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_add_newline
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_add_space
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|output_space_left
name|PARAMS
argument_list|(
operator|(
specifier|const
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_append
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_add_character
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_decimal
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_add_string
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|output_finalize_message
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_clear_message_text
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_printf
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|output_is_line_wrapping
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|output_verbatim
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|,
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|verbatim
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|context_as_prefix
name|PARAMS
argument_list|(
operator|(
specifier|const
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
name|char
modifier|*
name|file_name_as_prefix
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|error_module_changed
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_last_error_module
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|error_function_changed
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_last_error_function
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|report_problematic_module
name|PARAMS
argument_list|(
operator|(
name|output_buffer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called by report_error_function to print out function name.  * Default may be overridden by language front-ends.  */
end_comment

begin_extern
extern|extern void (*print_error_function
end_extern

begin_expr_stmt
unit|)
name|PARAMS
argument_list|(
operator|(
name|diagnostic_context
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|void
name|default_print_error_function
name|PARAMS
argument_list|(
operator|(
name|diagnostic_context
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_DIAGNOSTIC_H */
end_comment

end_unit

