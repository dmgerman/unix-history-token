begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compilation switch flag definitions for GCC.    Copyright (C) 1987, 1988, 1994, 1995, 1996, 1997, 1998, 1999, 2000, 2002,    2003    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|DWARF_DEBUG
block|,
comment|/* Write Dwarf debug info (using dwarfout.c).  */
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
comment|/* Nonzero means use GNU-only extensions in the generated symbolic    debugging information.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|use_gnu_debug_info_extensions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means emit debugging information only for symbols which are used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_debug_only_used_symbols
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
comment|/* Don't print functions as they are compiled and don't print    times taken by the various passes.  -quiet.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|quiet_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print memory still in use at end of compilation (which may have little    to do with peak memory consumption).  -fmem-report.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|mem_report
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't print warning messages.  -w.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|inhibit_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't suppress warnings from system headers.  -Wsystem-headers.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_system_headers
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
comment|/* If -Werror.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warnings_are_errors
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

begin_decl_stmt
specifier|extern
name|bool
name|warn_unused_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|warn_unused_label
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|warn_unused_parameter
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|warn_unused_variable
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|warn_unused_value
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to warn about code which is never reached.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_notreached
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn if inline function is too large.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to warn about variables used before they are initialized.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_uninitialized
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about all declarations which shadow others.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_shadow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a switch on an enum, that does not have a default case,    fails to have a case for every enum value.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_switch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a switch does not have a default case.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_switch_default
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a switch on an enum fails to have a case for every enum    value (regardless of the presence or otherwise of a default case).  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_switch_enum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about function definitions that default the return type    or that use a null return and have a return-type other than void.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_return_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn about functions which might be candidates for attribute noreturn.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_missing_noreturn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about pointer casts that increase the required    alignment of the target type (and might therefore lead to a crash    due to a misaligned access).  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_cast_align
decl_stmt|;
end_decl_stmt

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
comment|/* Warn if a function returns an aggregate,    since there are often incompatible calling conventions for doing this.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_aggregate_return
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if packed attribute on struct is unnecessary and inefficient.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_packed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn when gcc pads a structure to an alignment boundary.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_padded
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn when an optimization pass is disabled.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_disabled_optimization
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about uses of __attribute__((deprecated))     declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_deprecated_decl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about constructs which might not be strict    aliasing safe.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|warn_strict_aliasing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if generating code to do profiling.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profile_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if generating code to profile program flow graph arcs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profile_arc_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if value profile should be measured.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_profile_values
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if generating info for gcov to calculate line test coverage.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_test_coverage
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero indicates that branch taken probabilities should be calculated.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_branch_probabilities
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if basic blocks should be reordered.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_reorder_blocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if functions should be reordered.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_reorder_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if registers should be renamed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_rename_registers
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -pedantic switch: warn about anything    that standard C forbids.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pedantic
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
comment|/* Nonzero means give an enum type only as many bytes as it needs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_short_enums
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fcaller-saves: allocate values in regs that need to    be saved across function calls, if that produces overall better code.    Optional now, so people can test it.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_caller_saves
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
comment|/* Nonzero for -fforce-mem: load memory value into a register    before arithmetic on it.  This makes better cse but slower compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_force_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fforce-addr: load memory address into a register before    reference to memory.  This makes better cse but slower compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_force_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fdefer-pop: don't pop args after each function call;    instead save them up to pop many calls' args with one insns.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_defer_pop
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -ffloat-store: don't allocate floats and doubles    in extended-precision registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_float_store
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero enables strength-reduction in loop.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_strength_reduce
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero enables loop unrolling in unroll.c.  Only loops for which the    number of iterations can be calculated at compile-time (UNROLL_COMPLETELY,    UNROLL_MODULO) or at run-time (preconditioned to be UNROLL_MODULO) are    unrolled.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_old_unroll_loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero enables loop unrolling in unroll.c.  All loops are unrolled.    This is generally not a win.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_old_unroll_all_loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero forces all invariant computations in loops to be moved    outside the loop.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_move_all_movables
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero enables prefetch optimizations for arrays in loops.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_prefetch_loop_arrays
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero forces all general induction variables in loops to be    strength reduced.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_reduce_all_givs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fcse-follow-jumps:    have cse follow jumps to do a more extensive job.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cse_follow_jumps
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fcse-skip-blocks:    have cse follow a branch around a block.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_cse_skip_blocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fexpensive-optimizations:    perform miscellaneous relatively-expensive optimizations.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_expensive_optimizations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fwritable-strings:    store string constants in data segment and don't uniquize them.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_writable_strings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't put addresses of constant functions in registers.    Used for compiling the Unix kernel, where strange substitutions are    done on the assembly output.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_function_cse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fomit-frame-pointer:    don't make a frame pointer in simple functions that don't require one.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_omit_frame_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to inhibit use of define_optimization peephole opts.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_peephole
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero allows GCC to optimize sibling and tail recursive calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_optimize_sibling_calls
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means the front end generally wants `errno' maintained by math    operations, like built-in SQRT.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_errno_math
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that unsafe floating-point math optimizations are allowed    for the sake of speed.  IEEE compliance is not guaranteed, and operations    are allowed to assume that their arguments and results are "normal"    (e.g., nonnegative for SQRT).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_unsafe_math_optimizations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that no NaNs or +-Infs are expected.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_finite_math_only
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero means that floating-point math operations cannot generate a    (user-visible) trap.  This is the case, for example, in nonstop    IEEE 754 arithmetic.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_trapping_math
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means disable transformations that assume default floating    point rounding behavior.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_rounding_math
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 0 means straightforward implementation of complex divide acceptable.    1 means wide ranges of inputs must work for complex divide.    2 means C99-like requirements for complex divide (not yet implemented).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_complex_divide_method
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means to run loop optimizations twice.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_rerun_loop_opt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means make functions that look like good inline candidates    go inline.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_inline_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero for -fkeep-inline-functions: even if we make a function    go inline everywhere, keep its definition around for debugging    purposes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_keep_inline_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means that functions declared `inline' will be treated    as `static'.  Prevents generation of zillions of copies of unused    static inline functions; instead, `inlines' are written out    only when actually used.  Used in conjunction with -g.  Also    does the right thing with #pragma interface.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_inline
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
name|flag_syntax_only
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
comment|/* Nonzero means make the text shared if supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_shared_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag_schedule_insns means schedule insns within basic blocks (before    local_alloc).    flag_schedule_insns_after_reload means schedule insns after    global_alloc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_insns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_insns_after_reload
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_sched2_use_superblocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_sched2_use_traces
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following flags have effect only for scheduling before register    allocation:     flag_schedule_interblock means schedule insns across basic blocks.    flag_schedule_speculative means allow speculative motion of non-load insns.    flag_schedule_speculative_load means allow speculative motion of some    load insns.    flag_schedule_speculative_load_dangerous allows speculative motion of more    load insns.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_interblock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_speculative
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_speculative_load
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_schedule_speculative_load_dangerous
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following flags have an effect during scheduling after register    allocation:        sched_stalled_insns means that insns can be moved prematurely from the queue    of stalled insns into the ready list.     sched_stalled_insns_dep controls how many recently scheduled cycles will     be examined for a dependency on a stalled insn that is candidate for    premature removal from the queue of stalled insns into the ready list (has     an effect only if the flag 'sched_stalled_insns' is set).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_sched_stalled_insns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_sched_stalled_insns_dep
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* flag_branch_on_count_reg means try to replace add-1,compare,branch tupple    by a cheaper branch, on a count register.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_branch_on_count_reg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This option is set to 1 on -fsingle-precision-constant option which is    used to convert the floating point constants to single precision     constants.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_single_precision_constant
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means put things in delayed-branch slots if supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_delayed_branch
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
comment|/* Nonzero means generate position-independent code.  1 vs 2 for a     target-dependent "small" or "large" mode.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we are compiling position independent code for executable.    1 vs 2 for a target-dependent "small" or "large" mode.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pie
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
comment|/* Nonzero means generate extra code for exception handling and enable    exception handling.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate frame unwind info table when supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_unwind_tables
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate frame unwind info table exact at each insn boundary.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_asynchronous_unwind_tables
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means don't place uninitialized global data in common storage    by default.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_common
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -finhibit-size-directive inhibits output of .size for ELF.    This is used only for compiling crtstuff.c,    and it may be extended to other effects    needed for crtstuff.c on other systems.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_inhibit_size_directive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means place each function into its own section on those platforms    which support arbitrary section names and unlimited numbers of sections.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_function_sections
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ... and similar for data.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_data_sections
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -fverbose-asm causes extra commentary information to be produced in    the generated assembly code (to make it more readable).  This option    is generally only of use to those who actually need to read the    generated assembly code (perhaps while debugging the compiler itself).    -fno-verbose-asm, the default, causes the extra information    to not be added and is useful when comparing two assembler files.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_verbose_asm
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

begin_decl_stmt
specifier|extern
name|int
name|flag_dump_rtl_in_asm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Greater than zero if user symbols are prepended by a leading underscore    in generated assembly code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_leading_underscore
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tag all structures with __attribute__(packed) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pack_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This flag is only tested if alias checking is enabled.    0 if pointer arguments may alias each other.  True in C.    1 if pointer arguments may not alias each other but may alias    global variables.    2 if pointer arguments may not alias each other and may not    alias global variables.  True in Fortran.    The value is ignored if flag_alias_check is 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_argument_noalias
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we should do (language-dependent) alias analysis.    Typically, this analysis will assume that expressions of certain    types do not alias expressions of certain other types.  Only used    if alias analysis (in general) is enabled.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_strict_aliasing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit code to probe the stack, to help detect stack overflow; also    may cause large objects to be allocated dynamically.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_stack_check
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do the full regmove optimization pass.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_regmove
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Instrument functions with calls at entry and exit, for profiling.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_instrument_function_entry_exit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform a peephole pass before sched2.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_peephole2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Try to guess branch probabilities.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_guess_branch_prob
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -fcheck-bounds causes gcc to generate array bounds checks.    For C, C++ and ObjC: defaults off.    For Java: defaults to on.    For Fortran: defaults to off.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_bounds_check
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This will attempt to merge constant section constants, if 1 only    string constants and constants from constant pool, if 2 also constant    variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_merge_constants
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
comment|/* Nonzero if the generated code should trap on signed overflow    for PLUS / SUB / MULT.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_trapv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the signed arithmetic overflow should wrap around.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_wrapv
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
name|align_loops
decl_stmt|;
end_decl_stmt

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
name|align_jumps
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
name|align_labels
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
name|align_functions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|align_functions_log
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like align_functions_log above, but used by front-ends to force the    minimum function alignment.  Zero means no alignment is forced.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|force_align_functions_log
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
comment|/* Nonzero means ignore `#ident' directives.  0 means handle them.    On SVR4 targets, it also controls whether or not to emit a    string identifying the compiler.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_no_ident
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means perform global CSE.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gcse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to perform enhanced load motion during gcse.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gcse_lm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to perform store motion after gcse.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gcse_sm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if we want to perform redundant load-after-store elimination    in gcse.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_gcse_las
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if value histograms should be used to optimize code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_value_profile_transformations
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform branch target register optimization before prologue / epilogue    threading.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_branch_target_load_optimize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Perform branch target register optimization after prologue / epilogue    threading and jump2.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_branch_target_load_optimize2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should do dwarf2 duplicate elimination.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_eliminate_dwarf2_dups
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means we should do unused type elimination.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_eliminate_unused_debug_types
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
comment|/* Nonzero means enable synchronous exceptions for non-call instructions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_non_call_exceptions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means put zero initialized data in the bss section.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_zero_initialized_in_bss
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means disable transformations observable by signaling NaNs.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_signaling_nans
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_unit_at_a_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flag_web
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
comment|/*  The version of the C++ ABI in use.  The following values are     allowed:      0: The version of the ABI believed most conformant with the         C++ ABI specification.  This ABI may change as bugs are        discovered and fixed.  Therefore, 0 will not necessarily        indicate the same ABI in different versions of G++.      1: The version of the ABI first used in G++ 3.2.      Additional positive integers will be assigned as new versions of     the ABI become the default version of the ABI.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_abi_version
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
comment|/* True if the given mode has a NaN representation and the treatment of    NaN operands is important.  Certain optimizations, such as folding    x * 0 into x, are not correct for NaN operands, and are normally    disabled for modes with NaNs.  The user can ask for them to be    done anyway using the -funsafe-math-optimizations switch.  */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_FLAGS_H */
end_comment

end_unit

