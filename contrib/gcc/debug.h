begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Debug hooks for GCC.    Copyright (C) 2001, 2002 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Initialise debug output.  MAIN_FILENAME is the name of the main      input file.  */
name|void
argument_list|(
argument|* init
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|main_filename
operator|)
argument_list|)
expr_stmt|;
comment|/* Output debug symbols.  */
name|void
argument_list|(
argument|* finish
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|main_filename
operator|)
argument_list|)
expr_stmt|;
comment|/* Macro defined on line LINE with name and expansion TEXT.  */
name|void
argument_list|(
argument|* define
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
specifier|const
name|char
operator|*
name|text
operator|)
argument_list|)
expr_stmt|;
comment|/* MACRO undefined on line LINE.  */
name|void
argument_list|(
argument|* undef
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
specifier|const
name|char
operator|*
name|macro
operator|)
argument_list|)
expr_stmt|;
comment|/* Record the beginning of a new source file FILE from LINE number      in the previous one.  */
name|void
argument_list|(
argument|* start_source_file
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
specifier|const
name|char
operator|*
name|file
operator|)
argument_list|)
expr_stmt|;
comment|/* Record the resumption of a source file.  LINE is the line number      in the source file we are returning to.  */
name|void
argument_list|(
argument|* end_source_file
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|)
argument_list|)
expr_stmt|;
comment|/* Record the beginning of block N, counting from 1 and not      including the function-scope block, at LINE.  */
name|void
argument_list|(
argument|* begin_block
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
name|unsigned
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* Record the end of a block.  Arguments as for begin_block.  */
name|void
argument_list|(
argument|* end_block
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
name|unsigned
name|int
name|n
operator|)
argument_list|)
expr_stmt|;
comment|/* Returns nonzero if it is appropriate not to emit any debugging      information for BLOCK, because it doesn't contain any      instructions.  This may not be the case for blocks containing      nested functions, since we may actually call such a function even      though the BLOCK information is messed up.  Defaults to true.  */
name|bool
argument_list|(
argument|* ignore_block
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
expr_stmt|;
comment|/* Record a source file location at (FILE, LINE).  */
name|void
argument_list|(
argument|* source_line
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
specifier|const
name|char
operator|*
name|file
operator|)
argument_list|)
expr_stmt|;
comment|/* Called at start of prologue code.  LINE is the first line in the      function.  This has been given the same prototype as source_line,      so that the source_line hook can be substituted if appropriate.  */
name|void
argument_list|(
argument|* begin_prologue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|,
specifier|const
name|char
operator|*
name|file
operator|)
argument_list|)
expr_stmt|;
comment|/* Called at end of prologue code.  LINE is the first line in the      function.  */
name|void
argument_list|(
argument|* end_prologue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|)
argument_list|)
expr_stmt|;
comment|/* Record end of epilogue code.  */
name|void
argument_list|(
argument|* end_epilogue
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Called at start of function DECL, before it is declared.  */
name|void
argument_list|(
argument|* begin_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|)
argument_list|)
expr_stmt|;
comment|/* Record end of function.  LINE is highest line number in function.  */
name|void
argument_list|(
argument|* end_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|line
operator|)
argument_list|)
expr_stmt|;
comment|/* Debug information for a function DECL.  This might include the      function name (a symbol), its parameters, and the block that      makes up the function's body, and the local variables of the      function.  */
name|void
argument_list|(
argument|* function_decl
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|)
argument_list|)
expr_stmt|;
comment|/* Debug information for a global DECL.  Called from toplev.c after      compilation proper has finished.  */
name|void
argument_list|(
argument|* global_decl
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|)
argument_list|)
expr_stmt|;
comment|/* DECL is an inline function, whose body is present, but which is      not being output at this point.  */
name|void
argument_list|(
argument|* deferred_inline_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|)
argument_list|)
expr_stmt|;
comment|/* DECL is an inline function which is about to be emitted out of      line.  The hook is useful to, e.g., emit abstract debug info for      the inline before it gets mangled by optimization.  */
name|void
argument_list|(
argument|* outlining_inline_function
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|tree
name|decl
operator|)
argument_list|)
expr_stmt|;
comment|/* Called from final_scan_insn for any CODE_LABEL insn whose      LABEL_NAME is non-null.  */
name|void
argument_list|(
argument|* label
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
modifier|*
name|debug_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The do-nothing hooks.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|debug_nothing_void
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
name|debug_nothing_charstar
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
name|void
name|debug_nothing_int_charstar
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
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
name|debug_nothing_int
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_nothing_int_int
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_nothing_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|debug_true_tree
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_nothing_rtx
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Hooks for various debug formats.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|do_nothing_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|dbx_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|sdb_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|xcoff_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|dwarf_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|dwarf2_debug_hooks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|gcc_debug_hooks
name|vmsdbg_debug_hooks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Dwarf2 frame information.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|dwarf2out_begin_prologue
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
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
name|dwarf2out_end_epilogue
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
name|dwarf2out_frame_init
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
name|dwarf2out_frame_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Decide whether we want to emit frame unwind information for the current    translation unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dwarf2out_do_frame
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When writing VMS debug info, output label after the prologue of the    function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|vmsdbgout_after_prologue
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
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

