begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Debug hooks for GCC.    Copyright (C) 2001, 2002, 2003 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DEBUG_H
end_define

begin_comment
comment|/* This structure contains hooks for the debug information output    functions, accessed through the global instance debug_hooks set in    toplev.c according to command line options.  */
end_comment

begin_struct
struct|struct
name|gcc_debug_hooks
block|{
comment|/* Initialize debug output.  MAIN_FILENAME is the name of the main      input file.  */
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|main_filename
parameter_list|)
function_decl|;
comment|/* Output debug symbols.  */
name|void
function_decl|(
modifier|*
name|finish
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|main_filename
parameter_list|)
function_decl|;
comment|/* Macro defined on line LINE with name and expansion TEXT.  */
name|void
function_decl|(
modifier|*
name|define
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|text
parameter_list|)
function_decl|;
comment|/* MACRO undefined on line LINE.  */
name|void
function_decl|(
modifier|*
name|undef
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|macro
parameter_list|)
function_decl|;
comment|/* Record the beginning of a new source file FILE from LINE number      in the previous one.  */
name|void
function_decl|(
modifier|*
name|start_source_file
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
comment|/* Record the resumption of a source file.  LINE is the line number      in the source file we are returning to.  */
name|void
function_decl|(
modifier|*
name|end_source_file
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|)
function_decl|;
comment|/* Record the beginning of block N, counting from 1 and not      including the function-scope block, at LINE.  */
name|void
function_decl|(
modifier|*
name|begin_block
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
comment|/* Record the end of a block.  Arguments as for begin_block.  */
name|void
function_decl|(
modifier|*
name|end_block
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
comment|/* Returns nonzero if it is appropriate not to emit any debugging      information for BLOCK, because it doesn't contain any      instructions.  This may not be the case for blocks containing      nested functions, since we may actually call such a function even      though the BLOCK information is messed up.  Defaults to true.  */
name|bool
function_decl|(
modifier|*
name|ignore_block
function_decl|)
parameter_list|(
name|tree
parameter_list|)
function_decl|;
comment|/* Record a source file location at (FILE, LINE).  */
name|void
function_decl|(
modifier|*
name|source_line
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
comment|/* Called at start of prologue code.  LINE is the first line in the      function.  This has been given the same prototype as source_line,      so that the source_line hook can be substituted if appropriate.  */
name|void
function_decl|(
modifier|*
name|begin_prologue
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
comment|/* Called at end of prologue code.  LINE is the first line in the      function.  */
name|void
function_decl|(
modifier|*
name|end_prologue
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
comment|/* Record end of epilogue code.  */
name|void
function_decl|(
modifier|*
name|end_epilogue
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|file
parameter_list|)
function_decl|;
comment|/* Called at start of function DECL, before it is declared.  */
name|void
function_decl|(
modifier|*
name|begin_function
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
comment|/* Record end of function.  LINE is highest line number in function.  */
name|void
function_decl|(
modifier|*
name|end_function
function_decl|)
parameter_list|(
name|unsigned
name|int
name|line
parameter_list|)
function_decl|;
comment|/* Debug information for a function DECL.  This might include the      function name (a symbol), its parameters, and the block that      makes up the function's body, and the local variables of the      function.  */
name|void
function_decl|(
modifier|*
name|function_decl
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
comment|/* Debug information for a global DECL.  Called from toplev.c after      compilation proper has finished.  */
name|void
function_decl|(
modifier|*
name|global_decl
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
comment|/* DECL is an inline function, whose body is present, but which is      not being output at this point.  */
name|void
function_decl|(
modifier|*
name|deferred_inline_function
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
comment|/* DECL is an inline function which is about to be emitted out of      line.  The hook is useful to, e.g., emit abstract debug info for      the inline before it gets mangled by optimization.  */
name|void
function_decl|(
modifier|*
name|outlining_inline_function
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
comment|/* Called from final_scan_insn for any CODE_LABEL insn whose      LABEL_NAME is non-null.  */
name|void
function_decl|(
modifier|*
name|label
function_decl|)
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
comment|/* Called after the start and before the end of writing a PCH file.      The parameter is 0 if after the start, 1 if before the end.  */
name|void
function_decl|(
modifier|*
name|handle_pch
function_decl|)
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
modifier|*
name|debug_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The do-nothing hooks.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|debug_nothing_void
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_nothing_charstar
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
name|debug_nothing_int_charstar
parameter_list|(
name|unsigned
name|int
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
name|debug_nothing_int
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_nothing_int_int
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_nothing_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|debug_true_tree
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_nothing_rtx
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Hooks for various debug formats.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|do_nothing_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|dbx_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|sdb_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|xcoff_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|dwarf_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|dwarf2_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcc_debug_hooks
name|vmsdbg_debug_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dwarf2 frame information.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|dwarf2out_begin_prologue
parameter_list|(
name|unsigned
name|int
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
name|dwarf2out_end_epilogue
parameter_list|(
name|unsigned
name|int
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
name|dwarf2out_frame_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dwarf2out_frame_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decide whether we want to emit frame unwind information for the current    translation unit.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|dwarf2out_do_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_flush_symbol_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_queue_symbol
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_free_queue
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|debug_nesting
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|symbol_queue_index
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !GCC_DEBUG_H  */
end_comment

end_unit

