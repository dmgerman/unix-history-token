begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Instruction scheduling pass.  This file contains definitions used    internally in the scheduler.    Copyright (C) 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Forward declaration.  */
end_comment

begin_struct_decl
struct_decl|struct
name|ready_list
struct_decl|;
end_struct_decl

begin_comment
comment|/* Describe state of dependencies used during sched_analyze phase.  */
end_comment

begin_struct
struct|struct
name|deps
block|{
comment|/* The *_insns and *_mems are paired lists.  Each pending memory operation      will have a pointer to the MEM rtx on one list and a pointer to the      containing insn on the other list in the same place in the list.  */
comment|/* We can't use add_dependence like the old code did, because a single insn      may have multiple memory accesses, and hence needs to be on the list      once for each memory access.  Add_dependence won't let you add an insn      to a list more than once.  */
comment|/* An INSN_LIST containing all insns with pending read operations.  */
name|rtx
name|pending_read_insns
decl_stmt|;
comment|/* An EXPR_LIST containing all MEM rtx's which are pending reads.  */
name|rtx
name|pending_read_mems
decl_stmt|;
comment|/* An INSN_LIST containing all insns with pending write operations.  */
name|rtx
name|pending_write_insns
decl_stmt|;
comment|/* An EXPR_LIST containing all MEM rtx's which are pending writes.  */
name|rtx
name|pending_write_mems
decl_stmt|;
comment|/* Indicates the combined length of the two pending lists.  We must prevent      these lists from ever growing too large since the number of dependencies      produced is at least O(N*N), and execution time is at least O(4*N*N), as      a function of the length of these pending lists.  */
name|int
name|pending_lists_length
decl_stmt|;
comment|/* Length of the pending memory flush list. Large functions with no      calls may build up extremely large lists.  */
name|int
name|pending_flush_length
decl_stmt|;
comment|/* The last insn upon which all memory references must depend.      This is an insn which flushed the pending lists, creating a dependency      between it and all previously pending memory references.  This creates      a barrier (or a checkpoint) which no memory reference is allowed to cross.       This includes all non constant CALL_INSNs.  When we do interprocedural      alias analysis, this restriction can be relaxed.      This may also be an INSN that writes memory if the pending lists grow      too large.  */
name|rtx
name|last_pending_memory_flush
decl_stmt|;
comment|/* A list of the last function calls we have seen.  We use a list to      represent last function calls from multiple predecessor blocks.      Used to prevent register lifetimes from expanding unnecessarily.  */
name|rtx
name|last_function_call
decl_stmt|;
comment|/* A list of insns which use a pseudo register that does not already      cross a call.  We create dependencies between each of those insn      and the next call insn, to ensure that they won't cross a call after      scheduling is done.  */
name|rtx
name|sched_before_next_call
decl_stmt|;
comment|/* Used to keep post-call psuedo/hard reg movements together with      the call.  */
name|bool
name|in_post_call_group_p
decl_stmt|;
comment|/* The maximum register number for the following arrays.  Before reload      this is max_reg_num; after reload it is FIRST_PSEUDO_REGISTER.  */
name|int
name|max_reg
decl_stmt|;
comment|/* Element N is the next insn that sets (hard or pseudo) register      N within the current basic block; or zero, if there is no      such insn.  Needed for new registers which may be introduced      by splitting insns.  */
struct|struct
name|deps_reg
block|{
name|rtx
name|uses
decl_stmt|;
name|rtx
name|sets
decl_stmt|;
name|rtx
name|clobbers
decl_stmt|;
name|int
name|uses_length
decl_stmt|;
name|int
name|clobbers_length
decl_stmt|;
block|}
modifier|*
name|reg_last
struct|;
comment|/* Element N is set for each register that has any non-zero element      in reg_last[N].{uses,sets,clobbers}.  */
name|regset_head
name|reg_last_in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure holds some state of the current scheduling pass, and    contains some function pointers that abstract out some of the non-generic    functionality from functions such as schedule_block or schedule_insn.    There is one global variable, current_sched_info, which points to the    sched_info structure currently in use.  */
end_comment

begin_struct
struct|struct
name|sched_info
block|{
comment|/* Add all insns that are initially ready to the ready list.  Called once      before scheduling a set of insns.  */
name|void
argument_list|(
argument|*init_ready_list
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|ready_list
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* Called after taking an insn from the ready list.  Returns nonzero if      this insn can be scheduled, nonzero if we should silently discard it.  */
name|int
argument_list|(
argument|*can_schedule_ready_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
expr_stmt|;
comment|/* Return nonzero if there are more insns that should be scheduled.  */
name|int
argument_list|(
argument|*schedule_more_p
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
comment|/* Called after an insn has all its dependencies resolved.  Return nonzero      if it should be moved to the ready list or the queue, or zero if we      should silently discard it.  */
name|int
argument_list|(
argument|*new_ready
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
expr_stmt|;
comment|/* Compare priority of two insns.  Return a positive number if the second      insn is to be preferred for scheduling, and a negative one if the first      is to be preferred.  Zero if they are equally good.  */
name|int
argument_list|(
argument|*rank
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
expr_stmt|;
comment|/* Return a string that contains the insn uid and optionally anything else      necessary to identify this insn in an output.  It's valid to use a      static buffer for this.  The ALIGNED parameter should cause the string      to be formatted so that multiple output lines will line up nicely.  */
specifier|const
name|char
operator|*
operator|(
operator|*
name|print_insn
operator|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* Return nonzero if an insn should be included in priority      calculations.  */
name|int
argument_list|(
argument|*contributes_to_priority
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
expr_stmt|;
comment|/* Called when computing dependencies for a JUMP_INSN.  This function      should store the set of registers that must be considered as set by      the jump in the regset.  */
name|void
argument_list|(
argument|*compute_jump_reg_dependencies
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|regset
operator|)
argument_list|)
expr_stmt|;
comment|/* The boundaries of the set of insns to be scheduled.  */
name|rtx
name|prev_head
decl_stmt|,
name|next_tail
decl_stmt|;
comment|/* Filled in after the schedule is finished; the first and last scheduled      insns.  */
name|rtx
name|head
decl_stmt|,
name|tail
decl_stmt|;
comment|/* If nonzero, enables an additional sanity check in schedule_block.  */
name|unsigned
name|int
name|queue_must_finish_empty
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if we should use cselib for better alias analysis.  This      must be 0 if the dependency information is used after sched_analyze      has completed, e.g. if we're using it to initialize state for successor      blocks in region scheduling.  */
name|unsigned
name|int
name|use_cselib
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|sched_info
modifier|*
name|current_sched_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by INSN_UID, the collection of all data associated with    a single instruction.  */
end_comment

begin_struct
struct|struct
name|haifa_insn_data
block|{
comment|/* A list of insns which depend on the instruction.  Unlike LOG_LINKS,      it represents forward dependencies.  */
name|rtx
name|depend
decl_stmt|;
comment|/* The line number note in effect for each insn.  For line number      notes, this indicates whether the note may be reused.  */
name|rtx
name|line_note
decl_stmt|;
comment|/* Logical uid gives the original ordering of the insns.  */
name|int
name|luid
decl_stmt|;
comment|/* A priority for each insn.  */
name|int
name|priority
decl_stmt|;
comment|/* The number of incoming edges in the forward dependency graph.      As scheduling proceds, counts are decreased.  An insn moves to      the ready queue when its counter reaches zero.  */
name|int
name|dep_count
decl_stmt|;
comment|/* An encoding of the blockage range function.  Both unit and range      are coded.  */
name|unsigned
name|int
name|blockage
decl_stmt|;
comment|/* Number of instructions referring to this insn.  */
name|int
name|ref_count
decl_stmt|;
comment|/* The minimum clock tick at which the insn becomes ready.  This is      used to note timing constraints for the insns in the pending list.  */
name|int
name|tick
decl_stmt|;
name|short
name|cost
decl_stmt|;
comment|/* An encoding of the function units used.  */
name|short
name|units
decl_stmt|;
comment|/* This weight is an estimation of the insn's contribution to      register pressure.  */
name|short
name|reg_weight
decl_stmt|;
comment|/* Some insns (e.g. call) are not allowed to move across blocks.  */
name|unsigned
name|int
name|cant_move
range|:
literal|1
decl_stmt|;
comment|/* Set if there's DEF-USE dependence between some speculatively      moved load insn and this one.  */
name|unsigned
name|int
name|fed_by_spec_load
range|:
literal|1
decl_stmt|;
name|unsigned
name|int
name|is_load_insn
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if priority has been computed already.  */
name|unsigned
name|int
name|priority_known
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|haifa_insn_data
modifier|*
name|h_i_d
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accessor macros for h_i_d.  There are more in haifa-sched.c and    sched-rgn.c.  */
end_comment

begin_define
define|#
directive|define
name|INSN_DEPEND
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].depend)
end_define

begin_define
define|#
directive|define
name|INSN_LUID
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].luid)
end_define

begin_define
define|#
directive|define
name|CANT_MOVE
parameter_list|(
name|insn
parameter_list|)
value|(h_i_d[INSN_UID (insn)].cant_move)
end_define

begin_define
define|#
directive|define
name|INSN_DEP_COUNT
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].dep_count)
end_define

begin_define
define|#
directive|define
name|INSN_PRIORITY
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].priority)
end_define

begin_define
define|#
directive|define
name|INSN_PRIORITY_KNOWN
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].priority_known)
end_define

begin_define
define|#
directive|define
name|INSN_COST
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].cost)
end_define

begin_define
define|#
directive|define
name|INSN_UNIT
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].units)
end_define

begin_define
define|#
directive|define
name|INSN_REG_WEIGHT
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].reg_weight)
end_define

begin_define
define|#
directive|define
name|INSN_BLOCKAGE
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].blockage)
end_define

begin_define
define|#
directive|define
name|UNIT_BITS
value|5
end_define

begin_define
define|#
directive|define
name|BLOCKAGE_MASK
value|((1<< BLOCKAGE_BITS) - 1)
end_define

begin_define
define|#
directive|define
name|ENCODE_BLOCKAGE
parameter_list|(
name|U
parameter_list|,
name|R
parameter_list|)
define|\
value|(((U)<< BLOCKAGE_BITS			\     | MIN_BLOCKAGE_COST (R))<< BLOCKAGE_BITS	\    | MAX_BLOCKAGE_COST (R))
end_define

begin_define
define|#
directive|define
name|UNIT_BLOCKED
parameter_list|(
name|B
parameter_list|)
value|((B)>> (2 * BLOCKAGE_BITS))
end_define

begin_define
define|#
directive|define
name|BLOCKAGE_RANGE
parameter_list|(
name|B
parameter_list|)
define|\
value|(((((B)>> BLOCKAGE_BITS)& BLOCKAGE_MASK)<< (HOST_BITS_PER_INT / 2)) \    | ((B)& BLOCKAGE_MASK))
end_define

begin_comment
comment|/* Encodings of the `<name>_unit_blockage_range' function.  */
end_comment

begin_define
define|#
directive|define
name|MIN_BLOCKAGE_COST
parameter_list|(
name|R
parameter_list|)
value|((R)>> (HOST_BITS_PER_INT / 2))
end_define

begin_define
define|#
directive|define
name|MAX_BLOCKAGE_COST
parameter_list|(
name|R
parameter_list|)
value|((R)& ((1<< (HOST_BITS_PER_INT / 2)) - 1))
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|sched_dump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sched_verbose
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__GNUC__
end_ifndef

begin_define
define|#
directive|define
name|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAIFA_INLINE
end_ifndef

begin_define
define|#
directive|define
name|HAIFA_INLINE
value|__inline
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions in sched-vis.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_target_units
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
name|insn_print_units
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_block_visualization
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
name|print_block_visualization
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
name|visualize_scheduled_insns
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|visualize_no_unit
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|visualize_stall_cycles
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|visualize_alloc
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
name|visualize_free
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in sched-deps.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|add_dependence
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|reg_note
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_insn_mem_dependence
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sched_analyze
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_deps
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_deps
name|PARAMS
argument_list|(
operator|(
expr|struct
name|deps
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_deps_global
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
name|finish_deps_global
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
name|compute_forward_dependences
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|find_insn_list
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|init_dependency_caches
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_dependency_caches
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in haifa-sched.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|get_block_head_tail
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|no_real_insns_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rm_line_notes
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|save_line_notes
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|restore_line_notes
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|rm_redundant_line_notes
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
name|rm_other_notes
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insn_issue_delay
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|set_priorities
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|schedule_block
name|PARAMS
argument_list|(
operator|(
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
name|sched_init
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sched_finish
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
name|ready_add
name|PARAMS
argument_list|(
operator|(
expr|struct
name|ready_list
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The following are exported for the benefit of debugging functions.  It    would be nicer to keep them private to haifa-sched.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|insn_unit
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|insn_cost
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|get_unit_last_insn
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|actual_hazard_this_instance
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

