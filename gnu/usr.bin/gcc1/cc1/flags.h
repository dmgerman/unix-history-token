begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Compilation switch flag definitions for GNU CC.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Name of the input .c file being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|main_input_filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 1 => write gdb debugging output (using symout.c).    2 => write dbx debugging output (using dbxout.c).    3 => write sdb debugging output (using sdbout.c).  */
end_comment

begin_enum
enum|enum
name|debugger
block|{
name|NO_DEBUG
init|=
literal|0
block|,
name|GDB_DEBUG
init|=
literal|1
block|,
name|DBX_DEBUG
init|=
literal|2
block|,
name|SDB_DEBUG
init|=
literal|3
block|,
name|EXTENDED_DBX_DEBUG
init|=
literal|4
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|debugger
name|write_symbols
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means use GDB-only extensions of DBX format.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|use_gdb_dbx_extensions
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
comment|/* Nonzero means do stupid register allocation.  -noreg.    This and `optimize' are controlled by different switches in cc1,    but normally cc controls them both with the -O switch.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|obey_regdecls
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
comment|/* Don't print warning messages.  -w.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|inhibit_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do print extra warnings (such as for uninitialized variables).  -W.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|extra_warnings
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero to warn about unused local variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_unused
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about all declarations which shadow others.   */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_shadow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Warn if a switch on an enum fails to have a case for every enum value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_switch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means warn about any identifiers that match in the first N    characters.  The value N is in `id_clash_len'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|warn_id_clash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|id_clash_len
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
comment|/* Nonzero if generating code to do profiling on the basis of basic blocks.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profile_block_flag
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
comment|/* Nonzero for -fcombine-regs:    allow instruction combiner to combine an insn    that just copies one reg to another.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_combine_regs
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
comment|/* This isn't a flag, but everyone who needs flag_omit_frame_pointer    also needs this.    Nonzero means current function must be given a frame pointer.    Set in stmt.c if anything is allocated on the stack there.    Set in reload1.c if anything is allocated on the stack there.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|frame_pointer_needed
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
comment|/* Nonzero means all references through pointers are volatile.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_volatile
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
comment|/* Nonzero for -fkeep-inline-functions: even if we make a function    go inline everywhere, keep its defintion around for debugging    purposes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_keep_inline_functions
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
comment|/* Nonzero means make the text shared if supported.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_shared_data
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means put things in delayed-branch slots if supported. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_delayed_branch
decl_stmt|;
end_decl_stmt

end_unit

