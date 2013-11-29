begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compilation switch flag definitions for GCC.    Copyright (C) 1987, 1988, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2002,    2003, 2004, 2005, 2006, 2007    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_FLAGS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_FLAGS_H
end_define

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_enum
enum|enum
name|debug_info_type
block|{
name|NO_DEBUG
block|,
comment|/* Write no debug info.  */
name|DBX_DEBUG
block|,
comment|/* Write BSD .stabs for DBX (using dbxout.c).  */
name|SDB_DEBUG
block|,
comment|/* Write COFF for (old) SDB (using sdbout.c).  */
name|DWARF2_DEBUG
block|,
comment|/* Write Dwarf v2 debug info (using dwarf2out.c).  */
name|XCOFF_DEBUG
block|,
comment|/* Write IBM/Xcoff debug info (using dbxout.c).  */
name|VMS_DEBUG
block|,
comment|/* Write VMS debug info (using vmsdbgout.c).  */
name|VMS_AND_DWARF2_DEBUG
comment|/* Write VMS debug info (using vmsdbgout.c).                           and DWARF v2 debug info (using dwarf2out.c).  */
block|}
enum|;
end_enum

begin_comment
comment|/* Specify which kind of debugging info to generate.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|debug_info_type
name|write_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Names of debug_info_type, for error messages.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|debug_type_names
index|[]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|debug_info_level
block|{
name|DINFO_LEVEL_NONE
block|,
comment|/* Write no debugging info.  */
name|DINFO_LEVEL_TERSE
block|,
comment|/* Write minimal info to support tracebacks only.  */
name|DINFO_LEVEL_NORMAL
block|,
comment|/* Write info for all declarations (and line table).  */
name|DINFO_LEVEL_VERBOSE
comment|/* Write normal info plus #define/#undef info.  */
block|}
enum|;
end_enum

begin_comment
comment|/* Specify how much debugging info to generate.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|debug_info_level
name|debug_info_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A major contribution to object and executable size is debug    information size.  A major contribution to debug information    size is struct descriptions replicated in several object files.    The following function determines whether or not debug information    should be generated for a given struct.  The indirect parameter    indicates that the struct is being handled indirectly, via    a pointer.  See opts.c for the implementation. */
end_comment

begin_enum
enum|enum
name|debug_info_usage
block|{
name|DINFO_USAGE_DFN
block|,
comment|/* A struct definition. */
name|DINFO_USAGE_DIR_USE
block|,
comment|/* A direct use, such as the type of a variable. */
name|DINFO_USAGE_IND_USE
block|,
comment|/* An indirect use, such as through a pointer. */
name|DINFO_USAGE_NUM_ENUMS
comment|/* The number of enumerators. */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|bool
name|should_emit_struct_debug
parameter_list|(
name|tree
name|type_decl
parameter_list|,
name|enum
name|debug_info_usage
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_struct_debug_option
parameter_list|(
specifier|const
name|char
modifier|*
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero means use GNU-only extensions in the generated symbolic    debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|use_gnu_debug_info_extensions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Enumerate visibility settings.  This is deliberately ordered from most    to least visibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYMBOL_VISIBILITY_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|SYMBOL_VISIBILITY_DEFINED
end_define

begin_enum
enum|enum
name|symbol_visibility
block|{
name|VISIBILITY_DEFAULT
block|,
name|VISIBILITY_PROTECTED
block|,
name|VISIBILITY_HIDDEN
block|,
name|VISIBILITY_INTERNAL
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The default visibility for all symbols (unless overridden).  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|symbol_visibility
name|default_visibility
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|visibility_flags
block|{
name|unsigned
name|inpragma
range|:
literal|1
decl_stmt|;
comment|/* True when in #pragma GCC visibility.  */
name|unsigned
name|inlines_hidden
range|:
literal|1
decl_stmt|;
comment|/* True when -finlineshidden in effect.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Global visibility options.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|visibility_flags
name|visibility_options
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means do optimizations.  -opt.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optimize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means optimize for size.  -Os.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|optimize_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do print extra warnings (such as for uninitialized variables).    -W/-Wextra.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|extra_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to warn about unused variables, functions et.al.  Use    set_Wunused() to update the -Wunused-* flags that correspond to the    -Wunused option.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_Wunused
parameter_list|(
name|int
name|setting
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Used to set the level of -Wstrict-aliasing, when no level is specified.      The external way to set the default level is to use    -Wstrict-aliasing=level.      ONOFF is assumed to take value 1 when -Wstrict-aliasing is specified,    and 0 otherwise.  After calling this function, wstrict_aliasing will be    set to the default value of -Wstrict_aliasing=level.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_warn_strict_aliasing
parameter_list|(
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Nonzero means warn about any objects definitions whose size is larger    than N bytes.  Also want about function definitions whose returned    values are larger than N bytes. The value N is in `larger_than_size'.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_larger_than
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|larger_than_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about any function whose frame size is larger    than N bytes. */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_frame_larger_than
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|HOST_WIDE_INT
name|frame_larger_than_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about constructs which might not be strict    aliasing safe.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_aliasing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about optimizations which rely on undefined    signed overflow.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_strict_overflow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Temporarily suppress certain warnings.    This is set while reading code from a system header file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_system_header
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -dp: annotate the assembly with a comment describing the    pattern and alternative used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_print_asm_name
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Now the symbols that are set with `-f' switches.  */
end_comment

begin_comment
comment|/* Nonzero means `char' should be signed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signed_char
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means give an enum type only as many bytes as it needs.  A value    of 2 means it has not yet been initialized.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_short_enums
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fpcc-struct-return: return values the same way PCC does.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pcc_struct_return
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 means straightforward implementation of complex divide acceptable.    1 means wide ranges of inputs must work for complex divide.    2 means C99-like requirements for complex multiply and divide.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_complex_method
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we don't want inlining by virtue of -fno-inline,    not just because the tree inliner turned us off.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_really_no_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we are only using compiler to check syntax errors.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rtl_dump_and_exit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should save auxiliary info into a .X file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gen_aux_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means suppress output of instruction numbers and line number    notes in debugging dumps.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_dump_unnumbered
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means change certain warnings into errors.    Usually these are warnings about failure to conform to some standard.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pedantic_errors
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we are compiling code for a shared library, zero for    executable.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_shlib
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -dA causes debug information to be produced in    the generated assembly code (to make it more readable).  This option    is generally only of use to those who actually need to read the    generated assembly code (perhaps while debugging the compiler itself).    Currently, this switch is only used by dwarfout.c; however, it is intended    to be a catchall for printing debug information in the assembler file.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_debug_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generate code for GNU or NeXT Objective-C runtime environment.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_next_runtime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_dump_rtl_in_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If one, renumber instruction UIDs to reduce the number of    unused UIDs if there are a lot of instructions.  If greater than    one, unconditionally renumber instruction UIDs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_renumber_insns
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Other basic status info about current function.  */
end_comment

begin_comment
comment|/* Nonzero means current function must be given a frame pointer.    Set in stmt.c if anything is allocated on the stack there.    Set in reload1.c if anything is allocated on the stack there.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|frame_pointer_needed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if subexpressions must be evaluated from left-to-right.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_evaluation_order
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value of the -G xx switch, and whether it was passed or not.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|HOST_WIDE_INT
name|g_switch_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|g_switch_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Values of the -falign-* flags: how much to align labels in code.     0 means `use default', 1 means `don't align'.      For each variable, there is an _log variant which is the power    of two not less than the variable, for .align output.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|align_loops_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_loops_max_skip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_jumps_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_jumps_max_skip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_labels_log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_labels_max_skip
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_functions_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we dump in VCG format, not plain text.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dump_for_graph
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Selection of the graph form.  */
end_comment

begin_enum
enum|enum
name|graph_dump_types
block|{
name|no_graph
init|=
literal|0
block|,
name|vcg
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|graph_dump_types
name|graph_dump_format
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to collect statistics which might be expensive    and to print them when we are done.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_detailed_statistics
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that we defer emitting functions until they are actually    used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_remove_unreachable_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we should track variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_var_tracking
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* True if flag_speculative_prefetching was set by user.  Used to suppress    warning message in case flag was set by -fprofile-{generate,use}.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|flag_speculative_prefetching_set
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A string that's used when a random name is required.  NULL means    to make it really random.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|flag_random_seed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns TRUE if generated code should match ABI version N or    greater is in use.  */
end_comment

begin_define
define|#
directive|define
name|abi_version_at_least
parameter_list|(
name|N
parameter_list|)
define|\
value|(flag_abi_version == 0 || flag_abi_version>= (N))
end_define

begin_comment
comment|/* Return whether the function should be excluded from    instrumentation.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|flag_instrument_functions_exclude_p
parameter_list|(
name|tree
name|fndecl
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* True if the given mode has a NaN representation and the treatment of    NaN operands is important.  Certain optimizations, such as folding    x * 0 into 0, are not correct for NaN operands, and are normally    disabled for modes with NaNs.  The user can ask for them to be    done anyway using the -funsafe-math-optimizations switch.  */
end_comment

begin_define
define|#
directive|define
name|HONOR_NANS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(MODE_HAS_NANS (MODE)&& !flag_finite_math_only)
end_define

begin_comment
comment|/* Like HONOR_NANs, but true if we honor signaling NaNs (or sNaNs).  */
end_comment

begin_define
define|#
directive|define
name|HONOR_SNANS
parameter_list|(
name|MODE
parameter_list|)
value|(flag_signaling_nans&& HONOR_NANS (MODE))
end_define

begin_comment
comment|/* As for HONOR_NANS, but true if the mode can represent infinity and    the treatment of infinite values is important.  */
end_comment

begin_define
define|#
directive|define
name|HONOR_INFINITIES
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(MODE_HAS_INFINITIES (MODE)&& !flag_finite_math_only)
end_define

begin_comment
comment|/* Like HONOR_NANS, but true if the given mode distinguishes between    positive and negative zero, and the sign of zero is important.  */
end_comment

begin_define
define|#
directive|define
name|HONOR_SIGNED_ZEROS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(MODE_HAS_SIGNED_ZEROS (MODE)&& !flag_unsafe_math_optimizations)
end_define

begin_comment
comment|/* Like HONOR_NANS, but true if given mode supports sign-dependent rounding,    and the rounding mode is important.  */
end_comment

begin_define
define|#
directive|define
name|HONOR_SIGN_DEPENDENT_ROUNDING
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(MODE_HAS_SIGN_DEPENDENT_ROUNDING (MODE)&& flag_rounding_math)
end_define

begin_comment
comment|/* True if overflow wraps around for the given integral type.  That    is, TYPE_MAX + 1 == TYPE_MIN.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERFLOW_WRAPS
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_UNSIGNED (TYPE) || flag_wrapv)
end_define

begin_comment
comment|/* True if overflow is undefined for the given integral type.  We may    optimize on the assumption that values in the type never overflow.     IMPORTANT NOTE: Any optimization based on TYPE_OVERFLOW_UNDEFINED    must issue a warning based on warn_strict_overflow.  In some cases    it will be appropriate to issue the warning immediately, and in    other cases it will be appropriate to simply set a flag and let the    caller decide whether a warning is appropriate or not.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERFLOW_UNDEFINED
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(!TYPE_UNSIGNED (TYPE)&& !flag_wrapv&& !flag_trapv&& flag_strict_overflow)
end_define

begin_comment
comment|/* True if overflow for the given integral type should issue a    trap.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OVERFLOW_TRAPS
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(!TYPE_UNSIGNED (TYPE)&& flag_trapv)
end_define

begin_comment
comment|/* Names for the different levels of -Wstrict-overflow=N.  The numeric    values here correspond to N.  */
end_comment

begin_enum
enum|enum
name|warn_strict_overflow_code
block|{
comment|/* Overflow warning that should be issued with -Wall: a questionable      construct that is easy to avoid even when using macros.  Example:      folding (x + CONSTANT> x) to 1.  */
name|WARN_STRICT_OVERFLOW_ALL
init|=
literal|1
block|,
comment|/* Overflow warning about folding a comparison to a constant because      of undefined signed overflow, other than cases covered by      WARN_STRICT_OVERFLOW_ALL.  Example: folding (abs (x)>= 0) to 1      (this is false when x == INT_MIN).  */
name|WARN_STRICT_OVERFLOW_CONDITIONAL
init|=
literal|2
block|,
comment|/* Overflow warning about changes to comparisons other than folding      them to a constant.  Example: folding (x + 1> 1) to (x> 0).  */
name|WARN_STRICT_OVERFLOW_COMPARISON
init|=
literal|3
block|,
comment|/* Overflow warnings not covered by the above cases.  Example:      folding ((x * 10) / 5) to (x * 2).  */
name|WARN_STRICT_OVERFLOW_MISC
init|=
literal|4
block|,
comment|/* Overflow warnings about reducing magnitude of constants in      comparison.  Example: folding (x + 2> y) to (x + 1>= y).  */
name|WARN_STRICT_OVERFLOW_MAGNITUDE
init|=
literal|5
block|}
enum|;
end_enum

begin_comment
comment|/* Whether to emit an overflow warning whose code is C.  */
end_comment

begin_define
define|#
directive|define
name|issue_strict_overflow_warning
parameter_list|(
name|c
parameter_list|)
value|(warn_strict_overflow>= (int) (c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_FLAGS_H */
end_comment

end_unit

