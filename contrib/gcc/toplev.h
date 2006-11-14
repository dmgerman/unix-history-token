begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* toplev.h - Various declarations for functions found in toplev.c    Copyright (C) 1998, 1999, 2000, 2001, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TOPLEV_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TOPLEV_H
end_define

begin_comment
comment|/* If non-NULL, return one past-the-end of the matching SUBPART of    the WHOLE string.  */
end_comment

begin_define
define|#
directive|define
name|skip_leading_substring
parameter_list|(
name|whole
parameter_list|,
name|part
parameter_list|)
define|\
value|(strncmp (whole, part, strlen (part)) ? NULL : whole + strlen (part))
end_define

begin_function_decl
specifier|extern
name|int
name|toplev_main
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|read_integral_parameter
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
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|strip_off_ending
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|trim_filename
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|_fatal_insn_not_found
argument_list|(
name|rtx
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_fatal_insn
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
name|rtx
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|int
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|fatal_insn
parameter_list|(
name|msgid
parameter_list|,
name|insn
parameter_list|)
define|\
value|_fatal_insn (msgid, insn, __FILE__, __LINE__, __FUNCTION__)
end_define

begin_define
define|#
directive|define
name|fatal_insn_not_found
parameter_list|(
name|insn
parameter_list|)
define|\
value|_fatal_insn_not_found (insn, __FILE__, __LINE__, __FUNCTION__)
end_define

begin_comment
comment|/* If we haven't already defined a frontend specific diagnostics    style, use the generic one.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DIAG_STYLE
end_ifndef

begin_define
define|#
directive|define
name|GCC_DIAG_STYLE
value|__gcc_diag__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* None of these functions are suitable for ATTRIBUTE_PRINTF, because    each language front end can extend them with its own set of format    specifiers.  We must use custom format checks.  */
end_comment

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3004
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_DIAG
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (GCC_DIAG_STYLE, m, n))) ATTRIBUTE_NONNULL(m)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_GCC_DIAG
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

begin_decl_stmt
specifier|extern
name|void
name|internal_error
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_GCC_DIAG
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|warning
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
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|fatal_error
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_GCC_DIAG
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|ATTRIBUTE_NORETURN
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|pedwarn
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
name|void
name|sorry
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
name|void
name|inform
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_DIAG
parameter_list|(
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
name|rest_of_decl_compilation
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rest_of_type_compilation
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rest_of_compilation
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tree_rest_of_compilation
parameter_list|(
name|tree
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|announce_function
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|error_for_asm
parameter_list|(
name|rtx
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_DIAG
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
name|warning_for_asm
parameter_list|(
name|rtx
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_GCC_DIAG
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
name|warn_deprecated_use
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|output_quoted_string
parameter_list|(
name|FILE
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
name|output_file_directive
parameter_list|(
name|FILE
modifier|*
parameter_list|,
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

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_comment
comment|/* N.B. Unlike all the others, fnotice is just gettext+fprintf, and      therefore it can have ATTRIBUTE_PRINTF.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|fnotice
argument_list|(
name|FILE
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_2
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|wrapup_global_declarations
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_global_declarations
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|write_global_declarations
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A unique local time stamp, might be zero if none is available.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|local_tick
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dump_base_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|aux_base_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|aux_info_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|asm_file_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|exit_after_options
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|version_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|target_flags_explicit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* See toplev.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_loop_optimize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_crossjumping
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_if_conversion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_if_conversion2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_delete_null_pointer_checks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_keep_static_consts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_peel_loops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_rerun_cse_after_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_thread_jumps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_tracer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_unroll_loops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_unroll_all_loops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_unswitch_loops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_cprop_registers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|time_report
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_new_regalloc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Things to do with target switches.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|display_target_options
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_version
parameter_list|(
name|FILE
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
name|set_target_switch
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|default_get_pch_validity
parameter_list|(
name|size_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|default_pch_valid_p
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The hashtable, so that the C front ends can pass it to cpplib.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ht
modifier|*
name|ident_hash
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function can be used by targets to set the flags originally     implied by -ffast-math and -fno-fast-math.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_fast_math_flags
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Handle -d switch.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|decode_d_option
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true iff flags are set as if -ffast-math.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|fast_math_flags_set_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following functions accept a wide integer argument.  Rather    than having to cast on every function call, we use a macro instead.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|exact_log2
end_ifndef

begin_define
define|#
directive|define
name|exact_log2
parameter_list|(
name|N
parameter_list|)
value|exact_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_define
define|#
directive|define
name|floor_log2
parameter_list|(
name|N
parameter_list|)
value|floor_log2_wide ((unsigned HOST_WIDE_INT) (N))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|exact_log2_wide
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|floor_log2_wide
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions used to get and set GCC's notion of in what directory    compilation was started.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_src_pwd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|set_src_pwd
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
comment|/* ! GCC_TOPLEV_H */
end_comment

end_unit

