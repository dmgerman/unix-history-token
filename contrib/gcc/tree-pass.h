begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for describing one tree-ssa optimization pass.    Copyright (C) 2004, 2005 Free Software Foundation, Inc.    Contributed by Richard Henderson<rth@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_PASS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_PASS_H
value|1
end_define

begin_comment
comment|/* In tree-dump.c */
end_comment

begin_comment
comment|/* Different tree dump places.  When you add new tree dump places,    extend the DUMP_FILES array in tree-dump.c.  */
end_comment

begin_enum
enum|enum
name|tree_dump_index
block|{
name|TDI_none
block|,
comment|/* No dump */
name|TDI_cgraph
block|,
comment|/* dump function call graph.  */
name|TDI_tu
block|,
comment|/* dump the whole translation unit.  */
name|TDI_class
block|,
comment|/* dump class hierarchy.  */
name|TDI_original
block|,
comment|/* dump each function before optimizing it */
name|TDI_generic
block|,
comment|/* dump each function after genericizing it */
name|TDI_nested
block|,
comment|/* dump each function after unnesting it */
name|TDI_inlined
block|,
comment|/* dump each function after inlining 				   within it.  */
name|TDI_vcg
block|,
comment|/* create a VCG graph file for each 				   function's flowgraph.  */
name|TDI_tree_all
block|,
comment|/* enable all the GENERIC/GIMPLE dumps.  */
name|TDI_rtl_all
block|,
comment|/* enable all the RTL dumps.  */
name|TDI_ipa_all
block|,
comment|/* enable all the IPA dumps.  */
name|TDI_end
block|}
enum|;
end_enum

begin_comment
comment|/* Bit masks to control dumping. Not all values are applicable to    all dumps. Add new ones at the end. When you define new    values, extend the DUMP_OPTIONS array in tree-dump.c */
end_comment

begin_define
define|#
directive|define
name|TDF_ADDRESS
value|(1<< 0)
end_define

begin_comment
comment|/* dump node addresses */
end_comment

begin_define
define|#
directive|define
name|TDF_SLIM
value|(1<< 1)
end_define

begin_comment
comment|/* don't go wild following links */
end_comment

begin_define
define|#
directive|define
name|TDF_RAW
value|(1<< 2)
end_define

begin_comment
comment|/* don't unparse the function */
end_comment

begin_define
define|#
directive|define
name|TDF_DETAILS
value|(1<< 3)
end_define

begin_comment
comment|/* show more detailed info about 					   each pass */
end_comment

begin_define
define|#
directive|define
name|TDF_STATS
value|(1<< 4)
end_define

begin_comment
comment|/* dump various statistics about 					   each pass */
end_comment

begin_define
define|#
directive|define
name|TDF_BLOCKS
value|(1<< 5)
end_define

begin_comment
comment|/* display basic block boundaries */
end_comment

begin_define
define|#
directive|define
name|TDF_VOPS
value|(1<< 6)
end_define

begin_comment
comment|/* display virtual operands */
end_comment

begin_define
define|#
directive|define
name|TDF_LINENO
value|(1<< 7)
end_define

begin_comment
comment|/* display statement line numbers */
end_comment

begin_define
define|#
directive|define
name|TDF_UID
value|(1<< 8)
end_define

begin_comment
comment|/* display decl UIDs */
end_comment

begin_define
define|#
directive|define
name|TDF_TREE
value|(1<< 9)
end_define

begin_comment
comment|/* is a tree dump */
end_comment

begin_define
define|#
directive|define
name|TDF_RTL
value|(1<< 10)
end_define

begin_comment
comment|/* is a RTL dump */
end_comment

begin_define
define|#
directive|define
name|TDF_IPA
value|(1<< 11)
end_define

begin_comment
comment|/* is an IPA dump */
end_comment

begin_define
define|#
directive|define
name|TDF_STMTADDR
value|(1<< 12)
end_define

begin_comment
comment|/* Address of stmt.  */
end_comment

begin_define
define|#
directive|define
name|TDF_GRAPH
value|(1<< 13)
end_define

begin_comment
comment|/* a graph dump is being emitted */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|get_dump_file_name
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_enabled_p
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_initialized_p
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|dump_begin
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_end
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_node
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dump_switch_p
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|dump_flag_name
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global variables used to communicate with passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|dump_file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|dump_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|dump_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the dump_file_info for the given phase.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|dump_file_info
modifier|*
name|get_dump_file_info
parameter_list|(
name|enum
name|tree_dump_index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Describe one pass.  */
end_comment

begin_struct
struct|struct
name|tree_opt_pass
block|{
comment|/* Terse name of the pass used as a fragment of the dump file name.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* If non-null, this pass and all sub-passes are executed only if      the function returns true.  */
name|bool
function_decl|(
modifier|*
name|gate
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* This is the code to run.  If null, then there should be sub-passes      otherwise this pass does nothing.  The return value contains      TODOs to execute in addition to those in TODO_flags_finish.   */
name|unsigned
name|int
function_decl|(
modifier|*
name|execute
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* A list of sub-passes to run, dependent on gate predicate.  */
name|struct
name|tree_opt_pass
modifier|*
name|sub
decl_stmt|;
comment|/* Next in the list of passes to run, independent of gate predicate.  */
name|struct
name|tree_opt_pass
modifier|*
name|next
decl_stmt|;
comment|/* Static pass number, used as a fragment of the dump file name.  */
name|int
name|static_pass_number
decl_stmt|;
comment|/* The timevar id associated with this pass.  */
comment|/* ??? Ideally would be dynamically assigned.  */
name|unsigned
name|int
name|tv_id
decl_stmt|;
comment|/* Sets of properties input and output from this pass.  */
name|unsigned
name|int
name|properties_required
decl_stmt|;
name|unsigned
name|int
name|properties_provided
decl_stmt|;
name|unsigned
name|int
name|properties_destroyed
decl_stmt|;
comment|/* Flags indicating common sets things to do before and after.  */
name|unsigned
name|int
name|todo_flags_start
decl_stmt|;
name|unsigned
name|int
name|todo_flags_finish
decl_stmt|;
comment|/* Letter for RTL dumps.  */
name|char
name|letter
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Define a tree dump switch.  */
end_comment

begin_struct
struct|struct
name|dump_file_info
block|{
specifier|const
name|char
modifier|*
name|suffix
decl_stmt|;
comment|/* suffix to give output file.  */
specifier|const
name|char
modifier|*
name|swtch
decl_stmt|;
comment|/* command line switch */
specifier|const
name|char
modifier|*
name|glob
decl_stmt|;
comment|/* command line glob  */
name|int
name|flags
decl_stmt|;
comment|/* user flags */
name|int
name|state
decl_stmt|;
comment|/* state of play */
name|int
name|num
decl_stmt|;
comment|/* dump file number */
name|int
name|letter
decl_stmt|;
comment|/* enabling letter for RTL dumps */
block|}
struct|;
end_struct

begin_comment
comment|/* Pass properties.  */
end_comment

begin_define
define|#
directive|define
name|PROP_gimple_any
value|(1<< 0)
end_define

begin_comment
comment|/* entire gimple grammar */
end_comment

begin_define
define|#
directive|define
name|PROP_gimple_lcf
value|(1<< 1)
end_define

begin_comment
comment|/* lowered control flow */
end_comment

begin_define
define|#
directive|define
name|PROP_gimple_leh
value|(1<< 2)
end_define

begin_comment
comment|/* lowered eh */
end_comment

begin_define
define|#
directive|define
name|PROP_cfg
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|PROP_referenced_vars
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|PROP_pta
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|PROP_ssa
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|PROP_no_crit_edges
value|(1<< 7)
end_define

begin_define
define|#
directive|define
name|PROP_rtl
value|(1<< 8)
end_define

begin_define
define|#
directive|define
name|PROP_alias
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PROP_gimple_lomp
value|(1<< 10)
end_define

begin_comment
comment|/* lowered OpenMP directives */
end_comment

begin_define
define|#
directive|define
name|PROP_smt_usage
value|(1<< 11)
end_define

begin_comment
comment|/* which SMT's are 						   used alone.  */
end_comment

begin_define
define|#
directive|define
name|PROP_trees
define|\
value|(PROP_gimple_any | PROP_gimple_lcf | PROP_gimple_leh | PROP_gimple_lomp)
end_define

begin_comment
comment|/* To-do flags.  */
end_comment

begin_define
define|#
directive|define
name|TODO_dump_func
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|TODO_ggc_collect
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|TODO_verify_ssa
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|TODO_verify_flow
value|(1<< 3)
end_define

begin_define
define|#
directive|define
name|TODO_verify_stmts
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|TODO_cleanup_cfg
value|(1<< 5)
end_define

begin_define
define|#
directive|define
name|TODO_verify_loops
value|(1<< 6)
end_define

begin_define
define|#
directive|define
name|TODO_dump_cgraph
value|(1<< 7)
end_define

begin_comment
comment|/* To-do flags for calls to update_ssa.  */
end_comment

begin_comment
comment|/* Update the SSA form inserting PHI nodes for newly exposed symbols    and virtual names marked for updating.  When updating real names,    only insert PHI nodes for a real name O_j in blocks reached by all    the new and old definitions for O_j.  If the iterated dominance    frontier for O_j is not pruned, we may end up inserting PHI nodes    in blocks that have one or more edges with no incoming definition    for O_j.  This would lead to uninitialized warnings for O_j's    symbol.  */
end_comment

begin_define
define|#
directive|define
name|TODO_update_ssa
value|(1<< 8)
end_define

begin_comment
comment|/* Update the SSA form without inserting any new PHI nodes at all.    This is used by passes that have either inserted all the PHI nodes    themselves or passes that need only to patch use-def and def-def    chains for virtuals (e.g., DCE).  */
end_comment

begin_define
define|#
directive|define
name|TODO_update_ssa_no_phi
value|(1<< 9)
end_define

begin_comment
comment|/* Insert PHI nodes everywhere they are needed.  No pruning of the    IDF is done.  This is used by passes that need the PHI nodes for    O_j even if it means that some arguments will come from the default    definition of O_j's symbol (e.g., pass_linear_transform).        WARNING: If you need to use this flag, chances are that your pass    may be doing something wrong.  Inserting PHI nodes for an old name    where not all edges carry a new replacement may lead to silent    codegen errors or spurious uninitialized warnings.  */
end_comment

begin_define
define|#
directive|define
name|TODO_update_ssa_full_phi
value|(1<< 10)
end_define

begin_comment
comment|/* Passes that update the SSA form on their own may want to delegate    the updating of virtual names to the generic updater.  Since FUD    chains are easier to maintain, this simplifies the work they need    to do.  NOTE: If this flag is used, any OLD->NEW mappings for real    names are explicitly destroyed and only the symbols marked for    renaming are processed.  */
end_comment

begin_define
define|#
directive|define
name|TODO_update_ssa_only_virtuals
value|(1<< 11)
end_define

begin_comment
comment|/* Some passes leave unused local variables that can be removed from    cfun->unexpanded_var_list.  This reduces the size of dump files and    the memory footprint for VAR_DECLs.  */
end_comment

begin_define
define|#
directive|define
name|TODO_remove_unused_locals
value|(1<< 12)
end_define

begin_comment
comment|/* Internally used for the first in a sequence of passes.  It is set    for the passes that are handed to register_dump_files.  */
end_comment

begin_define
define|#
directive|define
name|TODO_set_props
value|(1<< 13)
end_define

begin_comment
comment|/* Set by passes that may make SMT's that were previously never used    in statements, used.  */
end_comment

begin_define
define|#
directive|define
name|TODO_update_smt_usage
value|(1<< 14)
end_define

begin_define
define|#
directive|define
name|TODO_update_ssa_any
define|\
value|(TODO_update_ssa			\      | TODO_update_ssa_no_phi		\      | TODO_update_ssa_full_phi		\      | TODO_update_ssa_only_virtuals)
end_define

begin_define
define|#
directive|define
name|TODO_verify_all
define|\
value|(TODO_verify_ssa | TODO_verify_flow | TODO_verify_stmts)
end_define

begin_function_decl
specifier|extern
name|void
name|tree_lowering_passes
parameter_list|(
name|tree
name|decl
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_mudflap_1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_mudflap_2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_remove_useless_stmts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_cf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_eh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_build_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tree_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_early_tree_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cleanup_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_referenced_vars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_sra
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tail_recursion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tail_calls
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tree_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tree_loop_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lim
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tree_unswitch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_iv_canon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_scev_cprop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_empty_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_record_bounds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_if_conversion
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_vectorize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_complete_unroll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_loop_prefetch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_iv_optimize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tree_loop_done
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ccp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_phi_only_cprop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_build_ssa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_del_ssa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_dominator
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_dce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_dce_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cd_dce
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_merge_phi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_may_alias
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_split_crit_edges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_pre
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_profile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_complex_O0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_complex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_vector
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_vector_ssa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_lower_omp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_expand_omp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_object_sizes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_fold_builtins
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_stdarg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_early_warn_uninitialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_late_warn_uninitialized
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cse_reciprocals
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_warn_function_return
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_warn_function_noreturn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_phiopt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_forwprop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_redundant_phi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_dse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_nrv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_mark_used_blocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rename_ssa_copies
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_expand
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rest_of_compilation
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_sink_code
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_fre
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_linear_transform
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_copy_prop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_store_ccp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_store_copy_prop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_vrp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_create_structure_vars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_uncprop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_return_slot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_reassoc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rebuild_cgraph_edges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_reset_cc_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IPA Passes */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_cp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_inline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_early_ipa_inline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_reference
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_pure_const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_type_escape
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_ipa_pta
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_early_local_passes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_all_optimizations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cleanup_cfg_post_optimizing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_free_cfg_annotations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_free_datastructures
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_init_datastructures
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_fixup_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_init_function
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_jump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_insn_locators_initialize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_eh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_initial_value_sets
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_unshare_all_rtl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_instantiate_virtual_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_jump2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_gcse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_jump_bypass
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_profiling
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_ifcvt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_tracer
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_loop2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_loop_init
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_move_loop_invariants
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_unswitch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_unroll_and_peel_loops
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_doloop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_loop_done
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_web
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cse2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_life
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_combine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_if_after_combine
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_partition_blocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_partition_blocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_regmove
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_split_all_insns
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_mode_switching
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_see
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_recompute_reg_usage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_sms
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_sched
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_local_alloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_global_alloc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_postreload
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_clean_state
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_branch_prob
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_value_profile_transformations
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_remove_death_notes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_postreload_cse
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_gcse2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_flow2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_stack_adjustments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_peephole2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_if_after_reload
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_regrename
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_reorder_blocks
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_branch_target_load_optimize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_leaf_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_sched2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_stack_regs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_compute_alignments
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_duplicate_computed_gotos
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_variable_tracking
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_free_cfg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_machine_reorg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_purge_lineno_notes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_cleanup_barriers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_delay_slots
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_split_for_shorten_branches
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_split_before_regstack
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_convert_to_eh_region_ranges
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_shorten_branches
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_set_nothrow_function_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_final
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
name|pass_rtl_seqabstr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The root of the compilation pass tree, once constructed.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tree_opt_pass
modifier|*
name|all_passes
decl_stmt|,
modifier|*
name|all_ipa_passes
decl_stmt|,
modifier|*
name|all_lowering_passes
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|execute_pass_list
parameter_list|(
name|struct
name|tree_opt_pass
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|execute_ipa_pass_list
parameter_list|(
name|struct
name|tree_opt_pass
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_PASS_H */
end_comment

end_unit

