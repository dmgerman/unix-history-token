begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for insn-output.c.  These functions are defined in recog.c,    final.c, and varasm.c.    Copyright (C) 1987, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIO_PROTO
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|PROTO(ARGS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STDIO_PROTO
parameter_list|(
name|ARGS
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a string of assembler code, substituting insn operands.    Defined in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_asm_insn
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a string of assembler code, substituting numbers, strings    and fixed syntactic prefixes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|asm_fprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Print an integer constant expression in assembler syntax.    Addition and subtraction are the only arithmetic    that may appear in these expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_addr_const
name|STDIO_PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a name (as found inside a symbol_ref) in assembler syntax.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_name
name|STDIO_PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace a SUBREG with a REG or a MEM, based on the thing it is a    subreg of.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|alter_subreg
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When outputting assembler code, indicates which alternative    of the constraints was actually satisfied.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|which_alternative
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When outputting delayed branch sequences, this rtx holds the    sequence being output.  It is null when no delayed branch    sequence is being output, so it can be used as a test in the    insn output code.     This variable is defined  in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|final_sequence
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of bytes of args popped by function being compiled on its return.    Zero if no bytes are to be popped.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pops_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be given an address    where the value should be stored.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to    return the address of where it has put a structure value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pcc_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be passed a static chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_needs_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call setjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_setjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call longjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_longjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call alloca,    either as a subroutine or builtin.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled receives nonlocal gotos    from nested functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_has_nonlocal_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled contains nested functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_contains_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the current function returns a pointer type */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If function's args have a fixed size, this is that size, in bytes.    Otherwise, it is -1.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes the prologue should push and pretend that the caller pushed them.    The prologue must do this, but only if parms can be passed in registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pretend_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of bytes of outgoing arguments required to be pushed by the prologue.    If this is non-zero, it means that ACCUMULATE_OUTGOING_ARGS was defined    and no stack adjusts will be done on function calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if current function uses varargs.h or equivalent.    Zero for functions that use stdarg.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_varargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quantities of various kinds of registers    used for the current function's args.  */
end_comment

begin_decl_stmt
specifier|extern
name|CUMULATIVE_ARGS
name|current_function_args_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of function now being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If non-zero, an RTL expression for that location at which the current    function returns its result.  Usually equal to    DECL_RTL (DECL_RESULT (current_function_decl)).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_return_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If some insns can be deferred to the delay slots of the epilogue, the    delay list for them is recorded here.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_epilogue_delay_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero means generate position-independent code.    This is not fully implemented yet.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses pic_offset_table_rtx.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_pic_offset_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_const_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The line number of the beginning of the current function.    sdbout.c needs this so that it can output relative linenumbers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SDB_DEBUGGING_INFO
end_ifdef

begin_comment
comment|/* Avoid undef sym in certain broken linkers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_begin_function_line
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* File in which assembler code is being written.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|asm_out_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

