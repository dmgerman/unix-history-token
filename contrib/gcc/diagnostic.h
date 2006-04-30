begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various declarations for language-independent diagnostics subroutines.    Copyright (C) 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"pretty-print.h"
end_include

begin_comment
comment|/* Constants used to discriminate diagnostics.  */
end_comment

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
name|msgid
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

begin_comment
comment|/* A diagnostic is described by the MESSAGE to send, the FILE and LINE of    its context and its KIND (ice, error, warning, note, ...)  See complete    list in diagnostic.def.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|text_info
name|message
decl_stmt|;
name|location_t
name|location
decl_stmt|;
comment|/* The kind of diagnostic it is about.  */
name|diagnostic_t
name|kind
decl_stmt|;
block|}
name|diagnostic_info
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
comment|/*  Forward declarations.  */
end_comment

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
function_decl|(
modifier|*
name|diagnostic_starter_fn
function_decl|)
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|,
name|diagnostic_info
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|diagnostic_starter_fn
name|diagnostic_finalizer_fn
typedef|;
end_typedef

begin_comment
comment|/* This data structure bundles altogether any information relevant to    the context of a diagnostic message.  */
end_comment

begin_struct
struct|struct
name|diagnostic_context
block|{
comment|/* Where most of the diagnostic formatting work is done.  */
name|pretty_printer
modifier|*
name|printer
decl_stmt|;
comment|/* The number of times we have issued diagnostics.  */
name|int
name|diagnostic_count
index|[
name|DK_LAST_DIAGNOSTIC_KIND
index|]
decl_stmt|;
comment|/* True if we should display the "warnings are being tread as error"      message, usually displayed once per compiler run.  */
name|bool
name|warnings_are_errors_message
decl_stmt|;
comment|/* True if we should raise a SIGABRT on errors.  */
name|bool
name|abort_on_error
decl_stmt|;
comment|/* This function is called before any message is printed out.  It is      responsible for preparing message prefix and such.  For example, it      might say:      In file included from "/usr/local/include/curses.h:5:                       from "/home/gdr/src/nifty_printer.h:56:                       ...   */
name|diagnostic_starter_fn
name|begin_diagnostic
decl_stmt|;
comment|/* This function is called after the diagnostic message is printed.  */
name|diagnostic_finalizer_fn
name|end_diagnostic
decl_stmt|;
comment|/* Client hook to report an internal error.  */
name|void
function_decl|(
modifier|*
name|internal_error
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
modifier|*
parameter_list|)
function_decl|;
comment|/* Function of last diagnostic message; more generally, function such that      if next diagnostic message is in it then we don't have to mention the      function name.  */
name|tree
name|last_function
decl_stmt|;
comment|/* Used to detect when input_file_stack has changed since last described.  */
name|int
name|last_module
decl_stmt|;
name|int
name|lock
decl_stmt|;
comment|/* Hook for front-end extensions.  */
name|void
modifier|*
name|x_data
decl_stmt|;
block|}
struct|;
end_struct

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
comment|/* Same as pp_format_decoder.  Works on 'diagnostic_context *'.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_format_decoder
parameter_list|(
name|DC
parameter_list|)
value|((DC)->printer->format_decoder)
end_define

begin_comment
comment|/* Same as output_prefixing_rule.  Works on 'diagnostic_context *'.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_prefixing_rule
parameter_list|(
name|DC
parameter_list|)
value|((DC)->printer->prefixing_rule)
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
value|((DC)->printer->ideal_maximum_length)
end_define

begin_define
define|#
directive|define
name|diagnostic_flush_buffer
parameter_list|(
name|DC
parameter_list|)
value|pp_base_flush ((DC)->printer)
end_define

begin_comment
comment|/* True if the last function in which a diagnostic was reported is    different from the current one.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_last_function_changed
parameter_list|(
name|DC
parameter_list|)
define|\
value|((DC)->last_function != current_function_decl)
end_define

begin_comment
comment|/* Remember the current function as being the last one in which we report    a diagnostic.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_set_last_function
parameter_list|(
name|DC
parameter_list|)
define|\
value|(DC)->last_function = current_function_decl
end_define

begin_comment
comment|/* True if the last module or file in which a diagnostic was reported is    different from the current one.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_last_module_changed
parameter_list|(
name|DC
parameter_list|)
define|\
value|((DC)->last_module != input_file_stack_tick)
end_define

begin_comment
comment|/* Remember the current module or file as being the last one in which we    report a diagnostic.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_set_last_module
parameter_list|(
name|DC
parameter_list|)
define|\
value|(DC)->last_module = input_file_stack_tick
end_define

begin_comment
comment|/* Raise SIGABRT on any diagnostic of severity DK_ERROR or higher.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_abort_on_error
parameter_list|(
name|DC
parameter_list|)
define|\
value|(DC)->abort_on_error = true
end_define

begin_comment
comment|/* This diagnostic_context is used by front-ends that directly output    diagnostic messages without going through `error', `warning',    and similar functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|diagnostic_context
modifier|*
name|global_dc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The total count of a KIND of diagnostics emitted so far.  */
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
value|(DC)->diagnostic_count[(int) (DK)]
end_define

begin_comment
comment|/* The number of errors that have been issued so far.  Ideally, these    would take a diagnostic_context as an argument.  */
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
comment|/* Returns nonzero if warnings should be emitted.  */
end_comment

begin_define
define|#
directive|define
name|diagnostic_report_warnings_p
parameter_list|()
define|\
value|(!inhibit_warnings					\&& !(in_system_header&& !warn_system_headers))
end_define

begin_define
define|#
directive|define
name|report_diagnostic
parameter_list|(
name|D
parameter_list|)
value|diagnostic_report_diagnostic (global_dc, D)
end_define

begin_comment
comment|/* Diagnostic related functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|diagnostic_initialize
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|diagnostic_report_current_module
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|diagnostic_report_current_function
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|diagnostic_report_diagnostic
parameter_list|(
name|diagnostic_context
modifier|*
parameter_list|,
name|diagnostic_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|diagnostic_set_info
parameter_list|(
name|diagnostic_info
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
modifier|*
parameter_list|,
name|location_t
parameter_list|,
name|diagnostic_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|diagnostic_build_prefix
parameter_list|(
name|diagnostic_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pure text formatting support functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|verbatim
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|file_name_as_prefix
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_DIAGNOSTIC_H */
end_comment

end_unit

