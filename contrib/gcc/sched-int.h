begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Instruction scheduling pass.  This file contains definitions used    internally in the scheduler.    Copyright (C) 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Pointer to data describing the current DFA state.  */
end_comment

begin_decl_stmt
specifier|extern
name|state_t
name|curr_state
decl_stmt|;
end_decl_stmt

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
comment|/* Used to keep post-call pseudo/hard reg movements together with      the call.  */
name|bool
name|in_post_call_group_p
decl_stmt|;
comment|/* Set to the tail insn of the outermost libcall block.       When nonzero, we will mark each insn processed by sched_analyze_insn      with SCHED_GROUP_P to ensure libcalls are scheduled as a unit.  */
name|rtx
name|libcall_block_tail_insn
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
comment|/* Element N is set for each register that has any nonzero element      in reg_last[N].{uses,sets,clobbers}.  */
name|regset_head
name|reg_last_in_use
decl_stmt|;
comment|/* Element N is set for each register that is conditionally set.  */
name|regset_head
name|reg_conditional_sets
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
function_decl|(
modifier|*
name|init_ready_list
function_decl|)
parameter_list|(
name|struct
name|ready_list
modifier|*
parameter_list|)
function_decl|;
comment|/* Called after taking an insn from the ready list.  Returns nonzero if      this insn can be scheduled, nonzero if we should silently discard it.  */
name|int
function_decl|(
modifier|*
name|can_schedule_ready_p
function_decl|)
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
comment|/* Return nonzero if there are more insns that should be scheduled.  */
name|int
function_decl|(
modifier|*
name|schedule_more_p
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* Called after an insn has all its dependencies resolved.  Return nonzero      if it should be moved to the ready list or the queue, or zero if we      should silently discard it.  */
name|int
function_decl|(
modifier|*
name|new_ready
function_decl|)
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
comment|/* Compare priority of two insns.  Return a positive number if the second      insn is to be preferred for scheduling, and a negative one if the first      is to be preferred.  Zero if they are equally good.  */
name|int
function_decl|(
modifier|*
name|rank
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
comment|/* Return a string that contains the insn uid and optionally anything else      necessary to identify this insn in an output.  It's valid to use a      static buffer for this.  The ALIGNED parameter should cause the string      to be formatted so that multiple output lines will line up nicely.  */
specifier|const
name|char
modifier|*
function_decl|(
modifier|*
name|print_insn
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Return nonzero if an insn should be included in priority      calculations.  */
name|int
function_decl|(
modifier|*
name|contributes_to_priority
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
comment|/* Called when computing dependencies for a JUMP_INSN.  This function      should store the set of registers that must be considered as set by      the jump in the regset.  */
name|void
function_decl|(
modifier|*
name|compute_jump_reg_dependencies
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|)
function_decl|;
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
comment|/* Maximum priority that has been assigned to an insn.  */
name|int
name|sched_max_insns_priority
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
comment|/* The number of incoming edges in the forward dependency graph.      As scheduling proceeds, counts are decreased.  An insn moves to      the ready queue when its counter reaches zero.  */
name|int
name|dep_count
decl_stmt|;
comment|/* An encoding of the blockage range function.  Both unit and range      are coded.  This member is used only for old pipeline interface.  */
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
comment|/* An encoding of the function units used.  This member is used only      for old pipeline interface.  */
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

begin_comment
comment|/* Exception Free Loads:     We define five classes of speculative loads: IFREE, IRISKY,    PFREE, PRISKY, and MFREE.     IFREE loads are loads that are proved to be exception-free, just    by examining the load insn.  Examples for such loads are loads    from TOC and loads of global data.     IRISKY loads are loads that are proved to be exception-risky,    just by examining the load insn.  Examples for such loads are    volatile loads and loads from shared memory.     PFREE loads are loads for which we can prove, by examining other    insns, that they are exception-free.  Currently, this class consists    of loads for which we are able to find a "similar load", either in    the target block, or, if only one split-block exists, in that split    block.  Load2 is similar to load1 if both have same single base    register.  We identify only part of the similar loads, by finding    an insn upon which both load1 and load2 have a DEF-USE dependence.     PRISKY loads are loads for which we can prove, by examining other    insns, that they are exception-risky.  Currently we have two proofs for    such loads.  The first proof detects loads that are probably guarded by a    test on the memory address.  This proof is based on the    backward and forward data dependence information for the region.    Let load-insn be the examined load.    Load-insn is PRISKY iff ALL the following hold:     - insn1 is not in the same block as load-insn    - there is a DEF-USE dependence chain (insn1, ..., load-insn)    - test-insn is either a compare or a branch, not in the same block      as load-insn    - load-insn is reachable from test-insn    - there is a DEF-USE dependence chain (insn1, ..., test-insn)     This proof might fail when the compare and the load are fed    by an insn not in the region.  To solve this, we will add to this    group all loads that have no input DEF-USE dependence.     The second proof detects loads that are directly or indirectly    fed by a speculative load.  This proof is affected by the    scheduling process.  We will use the flag  fed_by_spec_load.    Initially, all insns have this flag reset.  After a speculative    motion of an insn, if insn is either a load, or marked as    fed_by_spec_load, we will also mark as fed_by_spec_load every    insn1 for which a DEF-USE dependence (insn, insn1) exists.  A    load which is fed_by_spec_load is also PRISKY.     MFREE (maybe-free) loads are all the remaining loads. They may be    exception-free, but we cannot prove it.     Now, all loads in IFREE and PFREE classes are considered    exception-free, while all loads in IRISKY and PRISKY classes are    considered exception-risky.  As for loads in the MFREE class,    these are considered either exception-free or exception-risky,    depending on whether we are pessimistic or optimistic.  We have    to take the pessimistic approach to assure the safety of    speculative scheduling, but we can take the optimistic approach    by invoking the -fsched_spec_load_dangerous option.  */
end_comment

begin_enum
enum|enum
name|INSN_TRAP_CLASS
block|{
name|TRAP_FREE
init|=
literal|0
block|,
name|IFREE
init|=
literal|1
block|,
name|PFREE_CANDIDATE
init|=
literal|2
block|,
name|PRISKY_CANDIDATE
init|=
literal|3
block|,
name|IRISKY
init|=
literal|4
block|,
name|TRAP_RISKY
init|=
literal|5
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|WORST_CLASS
parameter_list|(
name|class1
parameter_list|,
name|class2
parameter_list|)
define|\
value|((class1> class2) ? class1 : class2)
end_define

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

begin_function_decl
specifier|extern
name|void
name|init_target_units
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insn_print_units
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_block_visualization
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_block_visualization
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
name|visualize_scheduled_insns
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|visualize_no_unit
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|visualize_stall_cycles
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|visualize_alloc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|visualize_free
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in sched-deps.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|add_dependence
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|reg_note
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_insn_mem_dependence
parameter_list|(
name|struct
name|deps
modifier|*
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sched_analyze
parameter_list|(
name|struct
name|deps
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_deps
parameter_list|(
name|struct
name|deps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_deps
parameter_list|(
name|struct
name|deps
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_deps_global
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|finish_deps_global
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_forward_dependence
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|reg_note
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compute_forward_dependences
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|find_insn_list
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_dependency_caches
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_dependency_caches
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in haifa-sched.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|haifa_classify_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_block_head_tail
parameter_list|(
name|int
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|no_real_insns_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rm_line_notes
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|save_line_notes
parameter_list|(
name|int
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|restore_line_notes
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rm_redundant_line_notes
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rm_other_notes
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|insn_issue_delay
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|set_priorities
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|sched_emit_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|schedule_block
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sched_init
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sched_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ready_add
parameter_list|(
name|struct
name|ready_list
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following are exported for the benefit of debugging functions.  It    would be nicer to keep them private to haifa-sched.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|insn_unit
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|insn_cost
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_unit_last_insn
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|actual_hazard_this_instance
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|rtx
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
name|print_insn
parameter_list|(
name|char
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

