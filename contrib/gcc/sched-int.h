begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Instruction scheduling pass.  This file contains definitions used    internally in the scheduler.    Copyright (C) 1992, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000, 2001, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_SCHED_INT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_SCHED_INT_H
end_define

begin_comment
comment|/* For state_t.  */
end_comment

begin_include
include|#
directive|include
file|"insn-attr.h"
end_include

begin_comment
comment|/* For regset_head.  */
end_comment

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_comment
comment|/* For reg_note.  */
end_comment

begin_include
include|#
directive|include
file|"rtl.h"
end_include

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
comment|/* Type to represent status of a dependence.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|ds_t
typedef|;
end_typedef

begin_comment
comment|/* Type to represent weakness of speculative dependence.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|dw_t
typedef|;
end_typedef

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
enum|enum
block|{
name|not_post_call
block|,
name|post_call
block|,
name|post_call_initial
block|}
name|in_post_call_group_p
enum|;
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
name|void
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
comment|/* Called after an insn has all its hard dependencies resolved.       Adjusts status of instruction (which is passed through second parameter)      to indicate if instruction should be moved to the ready list or the      queue, or if it should silently discard it (until next resolved      dependence).  */
name|ds_t
function_decl|(
modifier|*
name|new_ready
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|ds_t
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
comment|/* Hooks to support speculative scheduling.  */
comment|/* Called to notify frontend that instruction is being added (second      parameter == 0) or removed (second parameter == 1).  */
name|void
function_decl|(
modifier|*
name|add_remove_insn
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
comment|/* Called to notify frontend that instruction is being scheduled.      The first parameter - instruction to scheduled, the second parameter -      last scheduled instruction.  */
name|void
function_decl|(
modifier|*
name|begin_schedule_ready
function_decl|)
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
comment|/* Called to notify frontend, that new basic block is being added.      The first parameter - new basic block.      The second parameter - block, after which new basic block is being added,      or EXIT_BLOCK_PTR, if recovery block is being added,      or NULL, if standalone block is being added.  */
name|void
function_decl|(
modifier|*
name|add_block
function_decl|)
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* If the second parameter is not NULL, return nonnull value, if the      basic block should be advanced.      If the second parameter is NULL, return the next basic block in EBB.      The first parameter is the current basic block in EBB.  */
name|basic_block
function_decl|(
modifier|*
name|advance_target_bb
function_decl|)
parameter_list|(
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
comment|/* Called after blocks were rearranged due to movement of jump instruction.      The first parameter - index of basic block, in which jump currently is.      The second parameter - index of basic block, in which jump used      to be.      The third parameter - index of basic block, that follows the second      parameter.  */
name|void
function_decl|(
modifier|*
name|fix_recovery_cfg
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
comment|/* If the second parameter is zero, return nonzero, if block is head of the      region.      If the second parameter is nonzero, return nonzero, if block is leaf of      the region.      global_live_at_start should not change in region heads and      global_live_at_end should not change in region leafs due to scheduling.  */
name|int
function_decl|(
modifier|*
name|region_head_or_leaf_p
function_decl|)
parameter_list|(
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
endif|#
directive|endif
comment|/* ??? FIXME: should use straight bitfields inside sched_info instead of      this flag field.  */
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* This structure holds description of the properties for speculative    scheduling.  */
end_comment

begin_struct
struct|struct
name|spec_info_def
block|{
comment|/* Holds types of allowed speculations: BEGIN_{DATA|CONTROL},      BE_IN_{DATA_CONTROL}.  */
name|int
name|mask
decl_stmt|;
comment|/* A dump file for additional information on speculative scheduling.  */
name|FILE
modifier|*
name|dump
decl_stmt|;
comment|/* Minimal cumulative weakness of speculative instruction's      dependencies, so that insn will be scheduled.  */
name|dw_t
name|weakness_cutoff
decl_stmt|;
comment|/* Flags from the enum SPEC_SCHED_FLAGS.  */
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|spec_info_def
modifier|*
name|spec_info_t
typedef|;
end_typedef

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
comment|/* A list of scheduled producers of the instruction.  Links are being moved      from LOG_LINKS to RESOLVED_DEPS during scheduling.  */
name|rtx
name|resolved_deps
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
comment|/* Number of instructions referring to this insn.  */
name|int
name|ref_count
decl_stmt|;
comment|/* The minimum clock tick at which the insn becomes ready.  This is      used to note timing constraints for the insns in the pending list.  */
name|int
name|tick
decl_stmt|;
comment|/* INTER_TICK is used to adjust INSN_TICKs of instructions from the      subsequent blocks in a region.  */
name|int
name|inter_tick
decl_stmt|;
comment|/* See comment on QUEUE_INDEX macro in haifa-sched.c.  */
name|int
name|queue_index
decl_stmt|;
name|short
name|cost
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
comment|/* Nonzero if instruction has internal dependence      (e.g. add_dependence was invoked with (insn == elem)).  */
name|unsigned
name|int
name|has_internal_dep
range|:
literal|1
decl_stmt|;
comment|/* What speculations are necessary to apply to schedule the instruction.  */
name|ds_t
name|todo_spec
decl_stmt|;
comment|/* What speculations were already applied.  */
name|ds_t
name|done_spec
decl_stmt|;
comment|/* What speculations are checked by this instruction.  */
name|ds_t
name|check_spec
decl_stmt|;
comment|/* Recovery block for speculation checks.  */
name|basic_block
name|recovery_block
decl_stmt|;
comment|/* Original pattern of the instruction.  */
name|rtx
name|orig_pat
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
comment|/* Used only if (current_sched_info->flags& USE_GLAT) != 0.    These regsets store global_live_at_{start, end} information    for each basic block.  */
end_comment

begin_decl_stmt
specifier|extern
name|regset
modifier|*
name|glat_start
decl_stmt|,
modifier|*
name|glat_end
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
name|RESOLVED_DEPS
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].resolved_deps)
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
name|INSN_REG_WEIGHT
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].reg_weight)
end_define

begin_define
define|#
directive|define
name|HAS_INTERNAL_DEP
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].has_internal_dep)
end_define

begin_define
define|#
directive|define
name|TODO_SPEC
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].todo_spec)
end_define

begin_define
define|#
directive|define
name|DONE_SPEC
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].done_spec)
end_define

begin_define
define|#
directive|define
name|CHECK_SPEC
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].check_spec)
end_define

begin_define
define|#
directive|define
name|RECOVERY_BLOCK
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].recovery_block)
end_define

begin_define
define|#
directive|define
name|ORIG_PAT
parameter_list|(
name|INSN
parameter_list|)
value|(h_i_d[INSN_UID (INSN)].orig_pat)
end_define

begin_comment
comment|/* INSN is either a simple or a branchy speculation check.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPECULATION_CHECK_P
parameter_list|(
name|INSN
parameter_list|)
value|(RECOVERY_BLOCK (INSN) != NULL)
end_define

begin_comment
comment|/* INSN is a speculation check that will simply reexecute the speculatively    scheduled instruction if the speculation fails.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPECULATION_SIMPLE_CHECK_P
parameter_list|(
name|INSN
parameter_list|)
define|\
value|(RECOVERY_BLOCK (INSN) == EXIT_BLOCK_PTR)
end_define

begin_comment
comment|/* INSN is a speculation check that will branch to RECOVERY_BLOCK if the    speculation fails.  Insns in that block will reexecute the speculatively    scheduled code and then will return immediately after INSN thus preserving    semantics of the program.  */
end_comment

begin_define
define|#
directive|define
name|IS_SPECULATION_BRANCHY_CHECK_P
parameter_list|(
name|INSN
parameter_list|)
define|\
value|(RECOVERY_BLOCK (INSN) != NULL&& RECOVERY_BLOCK (INSN) != EXIT_BLOCK_PTR)
end_define

begin_comment
comment|/* DEP_STATUS of the link encapsulates information, that is needed for    speculative scheduling.  Namely, it is 4 integers in the range    [0, MAX_DEP_WEAK] and 3 bits.    The integers correspond to the probability of the dependence to *not*    exist, it is the probability, that overcoming of this dependence will    not be followed by execution of the recovery code.  Nevertheless,    whatever high the probability of success is, recovery code should still    be generated to preserve semantics of the program.  To find a way to    get/set these integers, please refer to the {get, set}_dep_weak ()    functions in sched-deps.c .    The 3 bits in the DEP_STATUS correspond to 3 dependence types: true-,    output- and anti- dependence.  It is not enough for speculative scheduling    to know just the major type of all the dependence between two instructions,    as only true dependence can be overcome.    There also is the 4-th bit in the DEP_STATUS (HARD_DEP), that is reserved    for using to describe instruction's status.  It is set whenever instruction    has at least one dependence, that cannot be overcome.    See also: check_dep_status () in sched-deps.c .  */
end_comment

begin_define
define|#
directive|define
name|DEP_STATUS
parameter_list|(
name|LINK
parameter_list|)
value|XINT (LINK, 2)
end_define

begin_comment
comment|/* We exclude sign bit.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_DEP_STATUS
value|(HOST_BITS_PER_INT - 1)
end_define

begin_comment
comment|/* First '4' stands for 3 dep type bits and HARD_DEP bit.    Second '4' stands for BEGIN_{DATA, CONTROL}, BE_IN_{DATA, CONTROL}    dep weakness.  */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_DEP_WEAK
value|((BITS_PER_DEP_STATUS - 4) / 4)
end_define

begin_comment
comment|/* Mask of speculative weakness in dep_status.  */
end_comment

begin_define
define|#
directive|define
name|DEP_WEAK_MASK
value|((1<< BITS_PER_DEP_WEAK) - 1)
end_define

begin_comment
comment|/* This constant means that dependence is fake with 99.999...% probability.    This is the maximum value, that can appear in dep_status.    Note, that we don't want MAX_DEP_WEAK to be the same as DEP_WEAK_MASK for    debugging reasons.  Though, it can be set to DEP_WEAK_MASK, and, when    done so, we'll get fast (mul for)/(div by) NO_DEP_WEAK.  */
end_comment

begin_define
define|#
directive|define
name|MAX_DEP_WEAK
value|(DEP_WEAK_MASK - 1)
end_define

begin_comment
comment|/* This constant means that dependence is 99.999...% real and it is a really    bad idea to overcome it (though this can be done, preserving program    semantics).  */
end_comment

begin_define
define|#
directive|define
name|MIN_DEP_WEAK
value|1
end_define

begin_comment
comment|/* This constant represents 100% probability.    E.g. it is used to represent weakness of dependence, that doesn't exist.  */
end_comment

begin_define
define|#
directive|define
name|NO_DEP_WEAK
value|(MAX_DEP_WEAK + MIN_DEP_WEAK)
end_define

begin_comment
comment|/* Default weakness of speculative dependence.  Used when we can't say    neither bad nor good about the dependence.  */
end_comment

begin_define
define|#
directive|define
name|UNCERTAIN_DEP_WEAK
value|(MAX_DEP_WEAK - MAX_DEP_WEAK / 4)
end_define

begin_comment
comment|/* Offset for speculative weaknesses in dep_status.  */
end_comment

begin_enum
enum|enum
name|SPEC_TYPES_OFFSETS
block|{
name|BEGIN_DATA_BITS_OFFSET
init|=
literal|0
block|,
name|BE_IN_DATA_BITS_OFFSET
init|=
name|BEGIN_DATA_BITS_OFFSET
operator|+
name|BITS_PER_DEP_WEAK
block|,
name|BEGIN_CONTROL_BITS_OFFSET
init|=
name|BE_IN_DATA_BITS_OFFSET
operator|+
name|BITS_PER_DEP_WEAK
block|,
name|BE_IN_CONTROL_BITS_OFFSET
init|=
name|BEGIN_CONTROL_BITS_OFFSET
operator|+
name|BITS_PER_DEP_WEAK
block|}
enum|;
end_enum

begin_comment
comment|/* The following defines provide numerous constants used to distinguish between    different types of speculative dependencies.  */
end_comment

begin_comment
comment|/* Dependence can be overcome with generation of new data speculative    instruction.  */
end_comment

begin_define
define|#
directive|define
name|BEGIN_DATA
value|(((ds_t) DEP_WEAK_MASK)<< BEGIN_DATA_BITS_OFFSET)
end_define

begin_comment
comment|/* This dependence is to the instruction in the recovery block, that was    formed to recover after data-speculation failure.    Thus, this dependence can overcome with generating of the copy of    this instruction in the recovery block.  */
end_comment

begin_define
define|#
directive|define
name|BE_IN_DATA
value|(((ds_t) DEP_WEAK_MASK)<< BE_IN_DATA_BITS_OFFSET)
end_define

begin_comment
comment|/* Dependence can be overcome with generation of new control speculative    instruction.  */
end_comment

begin_define
define|#
directive|define
name|BEGIN_CONTROL
value|(((ds_t) DEP_WEAK_MASK)<< BEGIN_CONTROL_BITS_OFFSET)
end_define

begin_comment
comment|/* This dependence is to the instruction in the recovery block, that was    formed to recover after control-speculation failure.    Thus, this dependence can be overcome with generating of the copy of    this instruction in the recovery block.  */
end_comment

begin_define
define|#
directive|define
name|BE_IN_CONTROL
value|(((ds_t) DEP_WEAK_MASK)<< BE_IN_CONTROL_BITS_OFFSET)
end_define

begin_comment
comment|/* A few convenient combinations.  */
end_comment

begin_define
define|#
directive|define
name|BEGIN_SPEC
value|(BEGIN_DATA | BEGIN_CONTROL)
end_define

begin_define
define|#
directive|define
name|DATA_SPEC
value|(BEGIN_DATA | BE_IN_DATA)
end_define

begin_define
define|#
directive|define
name|CONTROL_SPEC
value|(BEGIN_CONTROL | BE_IN_CONTROL)
end_define

begin_define
define|#
directive|define
name|SPECULATIVE
value|(DATA_SPEC | CONTROL_SPEC)
end_define

begin_define
define|#
directive|define
name|BE_IN_SPEC
value|(BE_IN_DATA | BE_IN_CONTROL)
end_define

begin_comment
comment|/* Constants, that are helpful in iterating through dep_status.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_SPEC_TYPE
value|BEGIN_DATA
end_define

begin_define
define|#
directive|define
name|LAST_SPEC_TYPE
value|BE_IN_CONTROL
end_define

begin_define
define|#
directive|define
name|SPEC_TYPE_SHIFT
value|BITS_PER_DEP_WEAK
end_define

begin_comment
comment|/* Dependence on instruction can be of multiple types    (e.g. true and output). This fields enhance REG_NOTE_KIND information    of the dependence.  */
end_comment

begin_define
define|#
directive|define
name|DEP_TRUE
value|(((ds_t) 1)<< (BE_IN_CONTROL_BITS_OFFSET + BITS_PER_DEP_WEAK))
end_define

begin_define
define|#
directive|define
name|DEP_OUTPUT
value|(DEP_TRUE<< 1)
end_define

begin_define
define|#
directive|define
name|DEP_ANTI
value|(DEP_OUTPUT<< 1)
end_define

begin_define
define|#
directive|define
name|DEP_TYPES
value|(DEP_TRUE | DEP_OUTPUT | DEP_ANTI)
end_define

begin_comment
comment|/* Instruction has non-speculative dependence.  This bit represents the    property of an instruction - not the one of a dependence.    Therefore, it can appear only in TODO_SPEC field of an instruction.  */
end_comment

begin_define
define|#
directive|define
name|HARD_DEP
value|(DEP_ANTI<< 1)
end_define

begin_comment
comment|/* This represents the results of calling sched-deps.c functions,     which modify dependencies.  Possible choices are: a dependence    is already present and nothing has been changed; a dependence type    has been changed; brand new dependence has been created.  */
end_comment

begin_enum
enum|enum
name|DEPS_ADJUST_RESULT
block|{
name|DEP_PRESENT
init|=
literal|1
block|,
name|DEP_CHANGED
init|=
literal|2
block|,
name|DEP_CREATED
init|=
literal|3
block|}
enum|;
end_enum

begin_comment
comment|/* Represents the bits that can be set in the flags field of the     sched_info structure.  */
end_comment

begin_enum
enum|enum
name|SCHED_FLAGS
block|{
comment|/* If set, generate links between instruction as DEPS_LIST.      Otherwise, generate usual INSN_LIST links.  */
name|USE_DEPS_LIST
init|=
literal|1
block|,
comment|/* Perform data or control (or both) speculation.      Results in generation of data and control speculative dependencies.      Requires USE_DEPS_LIST set.  */
name|DO_SPECULATION
init|=
name|USE_DEPS_LIST
operator|<<
literal|1
block|,
name|SCHED_RGN
init|=
name|DO_SPECULATION
operator|<<
literal|1
block|,
name|SCHED_EBB
init|=
name|SCHED_RGN
operator|<<
literal|1
block|,
comment|/* Detach register live information from basic block headers.      This is necessary to invoke functions, that change CFG (e.g. split_edge).      Requires USE_GLAT.  */
name|DETACH_LIFE_INFO
init|=
name|SCHED_EBB
operator|<<
literal|1
block|,
comment|/* Save register live information from basic block headers to      glat_{start, end} arrays.  */
name|USE_GLAT
init|=
name|DETACH_LIFE_INFO
operator|<<
literal|1
block|}
enum|;
end_enum

begin_enum
enum|enum
name|SPEC_SCHED_FLAGS
block|{
name|COUNT_SPEC_IN_CRITICAL_PATH
init|=
literal|1
block|,
name|PREFER_NON_DATA_SPEC
init|=
name|COUNT_SPEC_IN_CRITICAL_PATH
operator|<<
literal|1
block|,
name|PREFER_NON_CONTROL_SPEC
init|=
name|PREFER_NON_DATA_SPEC
operator|<<
literal|1
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|NOTE_NOT_BB_P
parameter_list|(
name|NOTE
parameter_list|)
value|(NOTE_P (NOTE)&& (NOTE_LINE_NUMBER (NOTE)	\ 					       != NOTE_INSN_BASIC_BLOCK))
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

begin_comment
comment|/* Functions in sched-deps.c.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|sched_insns_conditions_mutex_p
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
name|add_forw_dep
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

begin_function_decl
specifier|extern
name|void
name|extend_dependency_caches
parameter_list|(
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|DEPS_ADJUST_RESULT
name|add_or_update_back_dep
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|reg_note
parameter_list|,
name|ds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_or_update_back_forw_dep
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|reg_note
parameter_list|,
name|ds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_back_forw_dep
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|reg_note
parameter_list|,
name|ds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_back_forw_dep
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|dw_t
name|get_dep_weak
parameter_list|(
name|ds_t
parameter_list|,
name|ds_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ds_t
name|set_dep_weak
parameter_list|(
name|ds_t
parameter_list|,
name|ds_t
parameter_list|,
name|dw_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ds_t
name|ds_merge
parameter_list|(
name|ds_t
parameter_list|,
name|ds_t
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
name|get_ebb_head_tail
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
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
name|void
name|schedule_block
parameter_list|(
name|basic_block
modifier|*
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
name|void
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
name|int
name|try_ready
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|xrecalloc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unlink_bb_notes
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_block
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|attach_life_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|bb_note
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
end_ifdef

begin_function_decl
specifier|extern
name|void
name|check_reg_live
parameter_list|(
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_SCHED_INT_H */
end_comment

end_unit

