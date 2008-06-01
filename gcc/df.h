begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Form lists of pseudo register references for autoinc optimization    for GNU compiler.  This is part of flow optimization.    Copyright (C) 1999, 2000, 2001, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.    Originally contributed by Michael P. Hayes               (m.hayes@elec.canterbury.ac.nz, mhayes@redhat.com)    Major rewrite contributed by Danny Berlin (dberlin@dberlin.org)              and Kenneth Zadeck (zadeck@naturalbridge.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DF_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DF_H
end_define

begin_include
include|#
directive|include
file|"bitmap.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_include
include|#
directive|include
file|"alloc-pool.h"
end_include

begin_struct_decl
struct_decl|struct
name|dataflow
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|df
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|df_problem
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|df_link
struct_decl|;
end_struct_decl

begin_comment
comment|/* Data flow problems.  All problems must have a unique here.  */
end_comment

begin_comment
comment|/* Scanning is not really a dataflow problem, but it is useful to have    the basic block functions in the vector so that things get done in    a uniform manner.  */
end_comment

begin_define
define|#
directive|define
name|DF_SCAN
value|0
end_define

begin_define
define|#
directive|define
name|DF_RU
value|1
end_define

begin_comment
comment|/* Reaching Uses. */
end_comment

begin_define
define|#
directive|define
name|DF_RD
value|2
end_define

begin_comment
comment|/* Reaching Defs. */
end_comment

begin_define
define|#
directive|define
name|DF_LR
value|3
end_define

begin_comment
comment|/* Live Registers. */
end_comment

begin_define
define|#
directive|define
name|DF_UR
value|4
end_define

begin_comment
comment|/* Uninitialized Registers. */
end_comment

begin_define
define|#
directive|define
name|DF_UREC
value|5
end_define

begin_comment
comment|/* Uninitialized Registers with Early Clobber. */
end_comment

begin_define
define|#
directive|define
name|DF_CHAIN
value|6
end_define

begin_comment
comment|/* Def-Use and/or Use-Def Chains. */
end_comment

begin_define
define|#
directive|define
name|DF_RI
value|7
end_define

begin_comment
comment|/* Register Info. */
end_comment

begin_define
define|#
directive|define
name|DF_LAST_PROBLEM_PLUS1
value|(DF_RI + 1)
end_define

begin_comment
comment|/* Dataflow direction.  */
end_comment

begin_enum
enum|enum
name|df_flow_dir
block|{
name|DF_NONE
block|,
name|DF_FORWARD
block|,
name|DF_BACKWARD
block|}
enum|;
end_enum

begin_comment
comment|/* The first of these is a set of a register.  The remaining three are    all uses of a register (the mem_load and mem_store relate to how    the register as an addressing operand).  */
end_comment

begin_enum
enum|enum
name|df_ref_type
block|{
name|DF_REF_REG_DEF
block|,
name|DF_REF_REG_USE
block|,
name|DF_REF_REG_MEM_LOAD
block|,
name|DF_REF_REG_MEM_STORE
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DF_REF_TYPE_NAMES
value|{"def", "use", "mem load", "mem store"}
end_define

begin_enum
enum|enum
name|df_ref_flags
block|{
comment|/* Read-modify-write refs generate both a use and a def and        these are marked with this flag to show that they are not        independent.  */
name|DF_REF_READ_WRITE
init|=
literal|1
block|,
comment|/* This flag is set, if we stripped the subreg from the reference.        In this case we must make conservative guesses, at what the        outer mode was.  */
name|DF_REF_STRIPPED
init|=
literal|2
block|,
comment|/* If this flag is set, this is not a real definition/use, but an        artificial one created to model always live registers, eh uses, etc.  */
name|DF_REF_ARTIFICIAL
init|=
literal|4
block|,
comment|/* If this flag is set for an artificial use or def, that ref        logically happens at the top of the block.  If it is not set        for an artificial use or def, that ref logically happens at the        bottom of the block.  This is never set for regular refs.  */
name|DF_REF_AT_TOP
init|=
literal|8
block|,
comment|/* This flag is set if the use is inside a REG_EQUAL note.  */
name|DF_REF_IN_NOTE
init|=
literal|16
block|,
comment|/* This flag is set if this ref, generally a def, may clobber the        referenced register.  This is generally only set for hard        registers that cross a call site.  With better information        about calls, some of these could be changed in the future to        DF_REF_MUST_CLOBBER.  */
name|DF_REF_MAY_CLOBBER
init|=
literal|32
block|,
comment|/* This flag is set if this ref, generally a def, is a real        clobber. This is not currently set for registers live across a        call because that clobbering may or may not happen.           Most of the uses of this are with sets that have a        GET_CODE(..)==CLOBBER.  Note that this is set even if the        clobber is to a subreg.  So in order to tell if the clobber        wipes out the entire register, it is necessary to also check        the DF_REF_PARTIAL flag.  */
name|DF_REF_MUST_CLOBBER
init|=
literal|64
block|,
comment|/* This bit is true if this ref is part of a multiword hardreg.  */
name|DF_REF_MW_HARDREG
init|=
literal|128
block|,
comment|/* This flag is set if this ref is a partial use or def of the        associated register.  */
name|DF_REF_PARTIAL
init|=
literal|256
block|}
enum|;
end_enum

begin_comment
comment|/* Function prototypes added to df_problem instance.  */
end_comment

begin_comment
comment|/* Allocate the problem specific data.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_alloc_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* This function is called if the problem has global data that needs    to be cleared when ever the set of blocks changes.  The bitmap    contains the set of blocks that may require special attention.    This call is only made if some of the blocks are going to change.    If everything is to be deleted, the wholesale deletion mechanisms    apply. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_reset_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Free the basic block info.  Called from the block reordering code    to get rid of the blocks that have been squished down.   */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_free_bb_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Local compute function.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_local_compute_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Init the solution specific data.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_init_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Iterative dataflow function.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_dataflow_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Confluence operator for blocks with 0 out (or in) edges.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_confluence_function_0
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Confluence operator for blocks with 1 or more out (or in) edges.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_confluence_function_n
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Transfer function for blocks.  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|df_transfer_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function to massage the information after the problem solving.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_finalizer_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function to free all of the problem specific datastructures.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_free_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function to dump results to FILE.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|df_dump_problem_function
function_decl|)
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Function to add problem a dataflow problem that must be solved    before this problem can be solved.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|dataflow
modifier|*
function_decl|(
modifier|*
name|df_dependent_problem_function
function_decl|)
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The static description of a dataflow problem to solve.  See above    typedefs for doc for the function fields.  */
end_comment

begin_struct
struct|struct
name|df_problem
block|{
comment|/* The unique id of the problem.  This is used it index into      df->defined_problems to make accessing the problem data easy.  */
name|unsigned
name|int
name|id
decl_stmt|;
name|enum
name|df_flow_dir
name|dir
decl_stmt|;
comment|/* Dataflow direction.  */
name|df_alloc_function
name|alloc_fun
decl_stmt|;
name|df_reset_function
name|reset_fun
decl_stmt|;
name|df_free_bb_function
name|free_bb_fun
decl_stmt|;
name|df_local_compute_function
name|local_compute_fun
decl_stmt|;
name|df_init_function
name|init_fun
decl_stmt|;
name|df_dataflow_function
name|dataflow_fun
decl_stmt|;
name|df_confluence_function_0
name|con_fun_0
decl_stmt|;
name|df_confluence_function_n
name|con_fun_n
decl_stmt|;
name|df_transfer_function
name|trans_fun
decl_stmt|;
name|df_finalizer_function
name|finalize_fun
decl_stmt|;
name|df_free_function
name|free_fun
decl_stmt|;
name|df_dump_problem_function
name|dump_fun
decl_stmt|;
name|df_dependent_problem_function
name|dependent_problem_fun
decl_stmt|;
comment|/* Flags can be changed after analysis starts.  */
name|int
name|changeable_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The specific instance of the problem to solve.  */
end_comment

begin_struct
struct|struct
name|dataflow
block|{
name|struct
name|df
modifier|*
name|df
decl_stmt|;
comment|/* Instance of df we are working in.  */
name|struct
name|df_problem
modifier|*
name|problem
decl_stmt|;
comment|/* The problem to be solved.  */
comment|/* Communication between iterative_dataflow and hybrid_search. */
name|sbitmap
name|visited
decl_stmt|,
name|pending
decl_stmt|,
name|considered
decl_stmt|;
comment|/* Array indexed by bb->index, that contains basic block problem and      solution specific information.  */
name|void
modifier|*
modifier|*
name|block_info
decl_stmt|;
name|unsigned
name|int
name|block_info_size
decl_stmt|;
comment|/* The pool to allocate the block_info from. */
name|alloc_pool
name|block_pool
decl_stmt|;
comment|/* Problem specific control information.  */
comment|/* Scanning flags.  */
define|#
directive|define
name|DF_HARD_REGS
value|1
comment|/* Mark hard registers.  */
define|#
directive|define
name|DF_EQUIV_NOTES
value|2
comment|/* Mark uses present in EQUIV/EQUAL notes.  */
define|#
directive|define
name|DF_SUBREGS
value|4
comment|/* Return subregs rather than the inner reg.  */
comment|/* Flags that control the building of chains.  */
define|#
directive|define
name|DF_DU_CHAIN
value|1
comment|/* Build DU chains.  */
define|#
directive|define
name|DF_UD_CHAIN
value|2
comment|/* Build UD chains.  */
comment|/* Flag to control the building of register info.  */
define|#
directive|define
name|DF_RI_LIFE
value|1
comment|/* Build register info.  */
name|int
name|flags
decl_stmt|;
comment|/* Other problem specific data that is not on a per basic block      basis.  The structure is generally defined privately for the      problem.  The exception being the scanning problem where it is      fully public.  */
name|void
modifier|*
name|problem_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The set of multiword hardregs used as operands to this    instruction. These are factored into individual uses and defs but    the aggregate is still needed to service the REG_DEAD and    REG_UNUSED notes.  */
end_comment

begin_struct
struct|struct
name|df_mw_hardreg
block|{
name|rtx
name|mw_reg
decl_stmt|;
comment|/* The multiword hardreg.  */
name|enum
name|df_ref_type
name|type
decl_stmt|;
comment|/* Used to see if the ref is read or write.  */
name|enum
name|df_ref_flags
name|flags
decl_stmt|;
comment|/* Various flags.  */
name|struct
name|df_link
modifier|*
name|regs
decl_stmt|;
comment|/* The individual regs that make up 				   this hardreg.  */
name|struct
name|df_mw_hardreg
modifier|*
name|next
decl_stmt|;
comment|/* The next mw_hardreg in this insn.  */
block|}
struct|;
end_struct

begin_comment
comment|/* One of these structures is allocated for every insn.  */
end_comment

begin_struct
struct|struct
name|df_insn_info
block|{
name|struct
name|df_ref
modifier|*
name|defs
decl_stmt|;
comment|/* Head of insn-def chain.  */
name|struct
name|df_ref
modifier|*
name|uses
decl_stmt|;
comment|/* Head of insn-use chain.  */
name|struct
name|df_mw_hardreg
modifier|*
name|mw_hardregs
decl_stmt|;
comment|/* ???? The following luid field should be considered private so that      we can change it on the fly to accommodate new insns?  */
name|int
name|luid
decl_stmt|;
comment|/* Logical UID.  */
name|bool
name|contains_asm
decl_stmt|;
comment|/* Contains an asm instruction.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Two of these structures are allocated for every pseudo reg, one for    the uses and one for the defs.  */
end_comment

begin_struct
struct|struct
name|df_reg_info
block|{
name|struct
name|df_ref
modifier|*
name|reg_chain
decl_stmt|;
comment|/* Head of reg-use or def chain.  */
name|unsigned
name|int
name|begin
decl_stmt|;
comment|/* First def_index for this pseudo.  */
name|unsigned
name|int
name|n_refs
decl_stmt|;
comment|/* Number of refs or defs for this pseudo.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Define a register reference structure.  One of these is allocated    for every register reference (use or def).  Note some register    references (e.g., post_inc, subreg) generate both a def and a use.  */
end_comment

begin_struct
struct|struct
name|df_ref
block|{
name|rtx
name|reg
decl_stmt|;
comment|/* The register referenced.  */
name|unsigned
name|int
name|regno
decl_stmt|;
comment|/* The register number referenced.  */
name|basic_block
name|bb
decl_stmt|;
comment|/* Basic block containing the instruction. */
comment|/* Insn containing ref. This will be null if this is an artificial      reference.  */
name|rtx
name|insn
decl_stmt|;
name|rtx
modifier|*
name|loc
decl_stmt|;
comment|/* The location of the reg.  */
name|struct
name|df_link
modifier|*
name|chain
decl_stmt|;
comment|/* Head of def-use, use-def.  */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/* Location in table.  */
name|enum
name|df_ref_type
name|type
decl_stmt|;
comment|/* Type of ref.  */
name|enum
name|df_ref_flags
name|flags
decl_stmt|;
comment|/* Various flags.  */
comment|/* For each regno, there are two chains of refs, one for the uses      and one for the defs.  These chains go thru the refs themselves      rather than using an external structure.  */
name|struct
name|df_ref
modifier|*
name|next_reg
decl_stmt|;
comment|/* Next ref with same regno and type.  */
name|struct
name|df_ref
modifier|*
name|prev_reg
decl_stmt|;
comment|/* Prev ref with same regno and type.  */
comment|/* Each insn has two lists, one for the uses and one for the      defs. This is the next field in either of these chains. */
name|struct
name|df_ref
modifier|*
name|next_ref
decl_stmt|;
name|void
modifier|*
name|data
decl_stmt|;
comment|/* The data assigned to it by user.  */
block|}
struct|;
end_struct

begin_comment
comment|/* These links are used for two purposes:    1) def-use or use-def chains.     2) Multiword hard registers that underly a single hardware register.  */
end_comment

begin_struct
struct|struct
name|df_link
block|{
name|struct
name|df_ref
modifier|*
name|ref
decl_stmt|;
name|struct
name|df_link
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Two of these structures are allocated, one for the uses and one for    the defs.  */
end_comment

begin_struct
struct|struct
name|df_ref_info
block|{
name|struct
name|df_reg_info
modifier|*
modifier|*
name|regs
decl_stmt|;
comment|/* Array indexed by pseudo regno. */
name|unsigned
name|int
name|regs_size
decl_stmt|;
comment|/* Size of currently allocated regs table.  */
name|unsigned
name|int
name|regs_inited
decl_stmt|;
comment|/* Number of regs with reg_infos allocated.  */
name|struct
name|df_ref
modifier|*
modifier|*
name|refs
decl_stmt|;
comment|/* Ref table, indexed by id.  */
name|unsigned
name|int
name|refs_size
decl_stmt|;
comment|/* Size of currently allocated refs table.  */
name|unsigned
name|int
name|bitmap_size
decl_stmt|;
comment|/* Number of refs seen.  */
comment|/* True if refs table is organized so that every reference for a      pseudo is contiguous.  */
name|bool
name|refs_organized
decl_stmt|;
comment|/* True if the next refs should be added immediately or false to      defer to later to reorganize the table.  */
name|bool
name|add_refs_inline
decl_stmt|;
block|}
struct|;
end_struct

begin_escape
end_escape

begin_comment
comment|/*----------------------------------------------------------------------------    Problem data for the scanning dataflow problem.  Unlike the other    dataflow problems, the problem data for scanning is fully exposed and    used by owners of the problem. ----------------------------------------------------------------------------*/
end_comment

begin_struct
struct|struct
name|df
block|{
comment|/* The set of problems to be solved is stored in two arrays.  In      PROBLEMS_IN_ORDER, the problems are stored in the order that they      are solved.  This is an internally dense array that may have      nulls at the end of it.  In PROBLEMS_BY_INDEX, the problem is      stored by the value in df_problem.id.  These are used to access      the problem local data without having to search the first      array.  */
name|struct
name|dataflow
modifier|*
name|problems_in_order
index|[
name|DF_LAST_PROBLEM_PLUS1
index|]
decl_stmt|;
name|struct
name|dataflow
modifier|*
name|problems_by_index
index|[
name|DF_LAST_PROBLEM_PLUS1
index|]
decl_stmt|;
name|int
name|num_problems_defined
decl_stmt|;
comment|/* Set after calls to df_scan_blocks, this contains all of the      blocks that higher level problems must rescan before solving the      dataflow equations.  If this is NULL, the blocks_to_analyze is      used. */
name|bitmap
name|blocks_to_scan
decl_stmt|;
comment|/* If not NULL, the subset of blocks of the program to be considered      for analysis.  */
name|bitmap
name|blocks_to_analyze
decl_stmt|;
comment|/* The following information is really the problem data for the      scanning instance but it is used too often by the other problems      to keep getting it from there.  */
name|struct
name|df_ref_info
name|def_info
decl_stmt|;
comment|/* Def info.  */
name|struct
name|df_ref_info
name|use_info
decl_stmt|;
comment|/* Use info.  */
name|struct
name|df_insn_info
modifier|*
modifier|*
name|insns
decl_stmt|;
comment|/* Insn table, indexed by insn UID.  */
name|unsigned
name|int
name|insns_size
decl_stmt|;
comment|/* Size of insn table.  */
name|bitmap
name|hardware_regs_used
decl_stmt|;
comment|/* The set of hardware registers used.  */
name|bitmap
name|entry_block_defs
decl_stmt|;
comment|/* The set of hardware registers live on entry to the function.  */
name|bitmap
name|exit_block_uses
decl_stmt|;
comment|/* The set of hardware registers used in exit block.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DF_SCAN_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_scan_get_bb_info((DF)->problems_by_index[DF_SCAN],(BB)->index))
end_define

begin_define
define|#
directive|define
name|DF_RU_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_ru_get_bb_info((DF)->problems_by_index[DF_RU],(BB)->index))
end_define

begin_define
define|#
directive|define
name|DF_RD_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_rd_get_bb_info((DF)->problems_by_index[DF_RD],(BB)->index))
end_define

begin_define
define|#
directive|define
name|DF_LR_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_lr_get_bb_info((DF)->problems_by_index[DF_LR],(BB)->index))
end_define

begin_define
define|#
directive|define
name|DF_UR_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_ur_get_bb_info((DF)->problems_by_index[DF_UR],(BB)->index))
end_define

begin_define
define|#
directive|define
name|DF_UREC_BB_INFO
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(df_urec_get_bb_info((DF)->problems_by_index[DF_UREC],(BB)->index))
end_define

begin_comment
comment|/* Most transformations that wish to use live register analysis will    use these macros.  The DF_UPWARD_LIVE* macros are only half of the    solution.  */
end_comment

begin_define
define|#
directive|define
name|DF_LIVE_IN
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_UR_BB_INFO(DF, BB)->in)
end_define

begin_define
define|#
directive|define
name|DF_LIVE_OUT
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_UR_BB_INFO(DF, BB)->out)
end_define

begin_comment
comment|/* Live in for register allocation also takes into account several other factors.  */
end_comment

begin_define
define|#
directive|define
name|DF_RA_LIVE_IN
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_UREC_BB_INFO(DF, BB)->in)
end_define

begin_define
define|#
directive|define
name|DF_RA_LIVE_OUT
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_UREC_BB_INFO(DF, BB)->out)
end_define

begin_comment
comment|/* These macros are currently used by only reg-stack since it is not    tolerant of uninitialized variables.  This intolerance should be    fixed because it causes other problems.  */
end_comment

begin_define
define|#
directive|define
name|DF_UPWARD_LIVE_IN
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_LR_BB_INFO(DF, BB)->in)
end_define

begin_define
define|#
directive|define
name|DF_UPWARD_LIVE_OUT
parameter_list|(
name|DF
parameter_list|,
name|BB
parameter_list|)
value|(DF_LR_BB_INFO(DF, BB)->out)
end_define

begin_comment
comment|/* Macros to access the elements within the ref structure.  */
end_comment

begin_define
define|#
directive|define
name|DF_REF_REAL_REG
parameter_list|(
name|REF
parameter_list|)
value|(GET_CODE ((REF)->reg) == SUBREG \ 				? SUBREG_REG ((REF)->reg) : ((REF)->reg))
end_define

begin_define
define|#
directive|define
name|DF_REF_REGNO
parameter_list|(
name|REF
parameter_list|)
value|((REF)->regno)
end_define

begin_define
define|#
directive|define
name|DF_REF_REAL_LOC
parameter_list|(
name|REF
parameter_list|)
value|(GET_CODE ((REF)->reg) == SUBREG \ 			        ?&SUBREG_REG ((REF)->reg) : ((REF)->loc))
end_define

begin_define
define|#
directive|define
name|DF_REF_REG
parameter_list|(
name|REF
parameter_list|)
value|((REF)->reg)
end_define

begin_define
define|#
directive|define
name|DF_REF_LOC
parameter_list|(
name|REF
parameter_list|)
value|((REF)->loc)
end_define

begin_define
define|#
directive|define
name|DF_REF_BB
parameter_list|(
name|REF
parameter_list|)
value|((REF)->bb)
end_define

begin_define
define|#
directive|define
name|DF_REF_BBNO
parameter_list|(
name|REF
parameter_list|)
value|(DF_REF_BB (REF)->index)
end_define

begin_define
define|#
directive|define
name|DF_REF_INSN
parameter_list|(
name|REF
parameter_list|)
value|((REF)->insn)
end_define

begin_define
define|#
directive|define
name|DF_REF_INSN_UID
parameter_list|(
name|REF
parameter_list|)
value|(INSN_UID ((REF)->insn))
end_define

begin_define
define|#
directive|define
name|DF_REF_TYPE
parameter_list|(
name|REF
parameter_list|)
value|((REF)->type)
end_define

begin_define
define|#
directive|define
name|DF_REF_CHAIN
parameter_list|(
name|REF
parameter_list|)
value|((REF)->chain)
end_define

begin_define
define|#
directive|define
name|DF_REF_ID
parameter_list|(
name|REF
parameter_list|)
value|((REF)->id)
end_define

begin_define
define|#
directive|define
name|DF_REF_FLAGS
parameter_list|(
name|REF
parameter_list|)
value|((REF)->flags)
end_define

begin_define
define|#
directive|define
name|DF_REF_NEXT_REG
parameter_list|(
name|REF
parameter_list|)
value|((REF)->next_reg)
end_define

begin_define
define|#
directive|define
name|DF_REF_PREV_REG
parameter_list|(
name|REF
parameter_list|)
value|((REF)->prev_reg)
end_define

begin_define
define|#
directive|define
name|DF_REF_NEXT_REF
parameter_list|(
name|REF
parameter_list|)
value|((REF)->next_ref)
end_define

begin_define
define|#
directive|define
name|DF_REF_DATA
parameter_list|(
name|REF
parameter_list|)
value|((REF)->data)
end_define

begin_comment
comment|/* Macros to determine the reference type.  */
end_comment

begin_define
define|#
directive|define
name|DF_REF_REG_DEF_P
parameter_list|(
name|REF
parameter_list|)
value|(DF_REF_TYPE (REF) == DF_REF_REG_DEF)
end_define

begin_define
define|#
directive|define
name|DF_REF_REG_USE_P
parameter_list|(
name|REF
parameter_list|)
value|((REF)&& !DF_REF_REG_DEF_P (REF))
end_define

begin_define
define|#
directive|define
name|DF_REF_REG_MEM_STORE_P
parameter_list|(
name|REF
parameter_list|)
value|(DF_REF_TYPE (REF) == DF_REF_REG_MEM_STORE)
end_define

begin_define
define|#
directive|define
name|DF_REF_REG_MEM_LOAD_P
parameter_list|(
name|REF
parameter_list|)
value|(DF_REF_TYPE (REF) == DF_REF_REG_MEM_LOAD)
end_define

begin_define
define|#
directive|define
name|DF_REF_REG_MEM_P
parameter_list|(
name|REF
parameter_list|)
value|(DF_REF_REG_MEM_STORE_P (REF) \                                || DF_REF_REG_MEM_LOAD_P (REF))
end_define

begin_comment
comment|/* Macros to get the refs out of def_info or use_info refs table.  */
end_comment

begin_define
define|#
directive|define
name|DF_DEFS_SIZE
parameter_list|(
name|DF
parameter_list|)
value|((DF)->def_info.bitmap_size)
end_define

begin_define
define|#
directive|define
name|DF_DEFS_GET
parameter_list|(
name|DF
parameter_list|,
name|ID
parameter_list|)
value|((DF)->def_info.refs[(ID)])
end_define

begin_define
define|#
directive|define
name|DF_DEFS_SET
parameter_list|(
name|DF
parameter_list|,
name|ID
parameter_list|,
name|VAL
parameter_list|)
value|((DF)->def_info.refs[(ID)]=(VAL))
end_define

begin_define
define|#
directive|define
name|DF_USES_SIZE
parameter_list|(
name|DF
parameter_list|)
value|((DF)->use_info.bitmap_size)
end_define

begin_define
define|#
directive|define
name|DF_USES_GET
parameter_list|(
name|DF
parameter_list|,
name|ID
parameter_list|)
value|((DF)->use_info.refs[(ID)])
end_define

begin_define
define|#
directive|define
name|DF_USES_SET
parameter_list|(
name|DF
parameter_list|,
name|ID
parameter_list|,
name|VAL
parameter_list|)
value|((DF)->use_info.refs[(ID)]=(VAL))
end_define

begin_comment
comment|/* Macros to access the register information from scan dataflow record.  */
end_comment

begin_define
define|#
directive|define
name|DF_REG_SIZE
parameter_list|(
name|DF
parameter_list|)
value|((DF)->def_info.regs_inited)
end_define

begin_define
define|#
directive|define
name|DF_REG_DEF_GET
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|)
value|((DF)->def_info.regs[(REG)])
end_define

begin_define
define|#
directive|define
name|DF_REG_DEF_SET
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|,
name|VAL
parameter_list|)
value|((DF)->def_info.regs[(REG)]=(VAL))
end_define

begin_define
define|#
directive|define
name|DF_REG_DEF_COUNT
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|)
value|((DF)->def_info.regs[(REG)]->n_refs)
end_define

begin_define
define|#
directive|define
name|DF_REG_USE_GET
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|)
value|((DF)->use_info.regs[(REG)])
end_define

begin_define
define|#
directive|define
name|DF_REG_USE_SET
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|,
name|VAL
parameter_list|)
value|((DF)->use_info.regs[(REG)]=(VAL))
end_define

begin_define
define|#
directive|define
name|DF_REG_USE_COUNT
parameter_list|(
name|DF
parameter_list|,
name|REG
parameter_list|)
value|((DF)->use_info.regs[(REG)]->n_refs)
end_define

begin_comment
comment|/* Macros to access the elements within the reg_info structure table.  */
end_comment

begin_define
define|#
directive|define
name|DF_REGNO_FIRST_DEF
parameter_list|(
name|DF
parameter_list|,
name|REGNUM
parameter_list|)
define|\
value|(DF_REG_DEF_GET(DF, REGNUM) ? DF_REG_DEF_GET(DF, REGNUM) : 0)
end_define

begin_define
define|#
directive|define
name|DF_REGNO_LAST_USE
parameter_list|(
name|DF
parameter_list|,
name|REGNUM
parameter_list|)
define|\
value|(DF_REG_USE_GET(DF, REGNUM) ? DF_REG_USE_GET(DF, REGNUM) : 0)
end_define

begin_comment
comment|/* Macros to access the elements within the insn_info structure table.  */
end_comment

begin_define
define|#
directive|define
name|DF_INSN_SIZE
parameter_list|(
name|DF
parameter_list|)
value|((DF)->insns_size)
end_define

begin_define
define|#
directive|define
name|DF_INSN_GET
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|((DF)->insns[(INSN_UID(INSN))])
end_define

begin_define
define|#
directive|define
name|DF_INSN_SET
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|,
name|VAL
parameter_list|)
value|((DF)->insns[(INSN_UID (INSN))]=(VAL))
end_define

begin_define
define|#
directive|define
name|DF_INSN_CONTAINS_ASM
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_GET(DF,INSN)->contains_asm)
end_define

begin_define
define|#
directive|define
name|DF_INSN_LUID
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_GET(DF,INSN)->luid)
end_define

begin_define
define|#
directive|define
name|DF_INSN_DEFS
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_GET(DF,INSN)->defs)
end_define

begin_define
define|#
directive|define
name|DF_INSN_USES
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_GET(DF,INSN)->uses)
end_define

begin_define
define|#
directive|define
name|DF_INSN_UID_GET
parameter_list|(
name|DF
parameter_list|,
name|UID
parameter_list|)
value|((DF)->insns[(UID)])
end_define

begin_define
define|#
directive|define
name|DF_INSN_UID_LUID
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_UID_GET(DF,INSN)->luid)
end_define

begin_define
define|#
directive|define
name|DF_INSN_UID_DEFS
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_UID_GET(DF,INSN)->defs)
end_define

begin_define
define|#
directive|define
name|DF_INSN_UID_USES
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_UID_GET(DF,INSN)->uses)
end_define

begin_define
define|#
directive|define
name|DF_INSN_UID_MWS
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|(DF_INSN_UID_GET(DF,INSN)->mw_hardregs)
end_define

begin_comment
comment|/* This is a bitmap copy of regs_invalidated_by_call so that we can    easily add it into bitmaps, etc. */
end_comment

begin_decl_stmt
specifier|extern
name|bitmap
name|df_invalidated_by_call
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* One of these structures is allocated for every basic block.  */
end_comment

begin_struct
struct|struct
name|df_scan_bb_info
block|{
comment|/* Defs at the start of a basic block that is the target of an      exception edge.  */
name|struct
name|df_ref
modifier|*
name|artificial_defs
decl_stmt|;
comment|/* Uses of hard registers that are live at every block.  */
name|struct
name|df_ref
modifier|*
name|artificial_uses
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Reaching uses.  All bitmaps are indexed by the id field of the ref    except sparse_kill (see below).  */
end_comment

begin_struct
struct|struct
name|df_ru_bb_info
block|{
comment|/* Local sets to describe the basic blocks.  */
comment|/* The kill set is the set of uses that are killed in this block.      However, if the number of uses for this register is greater than      DF_SPARSE_THRESHOLD, the sparse_kill is used instead. In      sparse_kill, each register gets a slot and a 1 in this bitvector      means that all of the uses of that register are killed.  This is      a very useful efficiency hack in that it keeps from having push      around big groups of 1s.  This is implemented by the      bitmap_clear_range call.  */
name|bitmap
name|kill
decl_stmt|;
name|bitmap
name|sparse_kill
decl_stmt|;
name|bitmap
name|gen
decl_stmt|;
comment|/* The set of uses generated in this block.  */
comment|/* The results of the dataflow problem.  */
name|bitmap
name|in
decl_stmt|;
comment|/* At the top of the block.  */
name|bitmap
name|out
decl_stmt|;
comment|/* At the bottom of the block.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Reaching definitions.  All bitmaps are indexed by the id field of    the ref except sparse_kill (see above).  */
end_comment

begin_struct
struct|struct
name|df_rd_bb_info
block|{
comment|/* Local sets to describe the basic blocks.  See the note in the RU      datastructures for kill and sparse_kill.  */
name|bitmap
name|kill
decl_stmt|;
name|bitmap
name|sparse_kill
decl_stmt|;
name|bitmap
name|gen
decl_stmt|;
comment|/* The set of defs generated in this block.  */
comment|/* The results of the dataflow problem.  */
name|bitmap
name|in
decl_stmt|;
comment|/* At the top of the block.  */
name|bitmap
name|out
decl_stmt|;
comment|/* At the bottom of the block.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Live registers.  All bitmaps are referenced by the register number.  */
end_comment

begin_struct
struct|struct
name|df_lr_bb_info
block|{
comment|/* Local sets to describe the basic blocks.  */
name|bitmap
name|def
decl_stmt|;
comment|/* The set of registers set in this block.  */
name|bitmap
name|use
decl_stmt|;
comment|/* The set of registers used in this block.  */
comment|/* The results of the dataflow problem.  */
name|bitmap
name|in
decl_stmt|;
comment|/* At the top of the block.  */
name|bitmap
name|out
decl_stmt|;
comment|/* At the bottom of the block.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Uninitialized registers.  All bitmaps are referenced by the register number.  */
end_comment

begin_struct
struct|struct
name|df_ur_bb_info
block|{
comment|/* Local sets to describe the basic blocks.  */
name|bitmap
name|kill
decl_stmt|;
comment|/* The set of registers unset in this block.  Calls, 		   for instance, unset registers.  */
name|bitmap
name|gen
decl_stmt|;
comment|/* The set of registers set in this block.  */
comment|/* The results of the dataflow problem.  */
name|bitmap
name|in
decl_stmt|;
comment|/* At the top of the block.  */
name|bitmap
name|out
decl_stmt|;
comment|/* At the bottom of the block.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Uninitialized registers.  All bitmaps are referenced by the register number.  */
end_comment

begin_struct
struct|struct
name|df_urec_bb_info
block|{
comment|/* Local sets to describe the basic blocks.  */
name|bitmap
name|earlyclobber
decl_stmt|;
comment|/* The set of registers that are referenced 			   with an an early clobber mode.  */
comment|/* Kill and gen are defined as in the UR problem.  */
name|bitmap
name|kill
decl_stmt|;
name|bitmap
name|gen
decl_stmt|;
comment|/* The results of the dataflow problem.  */
name|bitmap
name|in
decl_stmt|;
comment|/* At the top of the block.  */
name|bitmap
name|out
decl_stmt|;
comment|/* At the bottom of the block.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|df_finish
parameter_list|(
name|df
parameter_list|)
value|{df_finish1(df); df=NULL;}
end_define

begin_comment
comment|/* Functions defined in df-core.c.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|df
modifier|*
name|df_init
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|df_problem
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_set_flags
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_clear_flags
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_set_blocks
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_delete_basic_block
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_finish1
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_analyze_problem
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_analyze
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_compact_blocks
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_bb_replace
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_bb_regno_last_use_find
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_bb_regno_first_def_find
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_bb_regno_last_def_find
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|df_insn_regno_def_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_find_def
parameter_list|(
name|struct
name|df
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
name|bool
name|df_reg_defined
parameter_list|(
name|struct
name|df
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
name|struct
name|df_ref
modifier|*
name|df_find_use
parameter_list|(
name|struct
name|df
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
name|bool
name|df_reg_used
parameter_list|(
name|struct
name|df
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
name|df_iterative_dataflow
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|int
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_dump
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_refs_chain_dump
parameter_list|(
name|struct
name|df_ref
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_regs_chain_dump
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_insn_debug
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|bool
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_insn_debug_regno
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_regno_debug
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_ref_debug
parameter_list|(
name|struct
name|df_ref
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_regno
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_reg
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_defno
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_useno
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_ref
parameter_list|(
name|struct
name|df_ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_df_chain
parameter_list|(
name|struct
name|df_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* An instance of df that can be shared between passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|df
modifier|*
name|shared_df
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions defined in df-problems.c. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|df_link
modifier|*
name|df_chain_create
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_chain_unlink
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|,
name|struct
name|df_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_chain_copy
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|,
name|struct
name|df_link
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bitmap
name|df_get_live_in
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bitmap
name|df_get_live_out
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_grow_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_chain_dump
parameter_list|(
name|struct
name|df_link
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_print_bb_index
parameter_list|(
name|basic_block
name|bb
parameter_list|,
name|FILE
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_ru_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ru_bb_info
modifier|*
name|df_ru_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_rd_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_rd_bb_info
modifier|*
name|df_rd_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_lr_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_lr_bb_info
modifier|*
name|df_lr_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_ur_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ur_bb_info
modifier|*
name|df_ur_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_urec_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_urec_bb_info
modifier|*
name|df_urec_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_chain_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_ri_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions defined in df-scan.c.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|df_scan_bb_info
modifier|*
name|df_scan_get_bb_info
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|dataflow
modifier|*
name|df_scan_add_problem
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_rescan_blocks
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_ref_create
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|,
name|enum
name|df_ref_type
parameter_list|,
name|enum
name|df_ref_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_get_artificial_defs
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_get_artificial_uses
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_reg_chain_create
parameter_list|(
name|struct
name|df_reg_info
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df_ref
modifier|*
name|df_reg_chain_unlink
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_ref_remove
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_insn_refs_delete
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_bb_refs_delete
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_refs_delete
parameter_list|(
name|struct
name|dataflow
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_reorganize_refs
parameter_list|(
name|struct
name|df_ref_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_hard_reg_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|df_read_modify_subreg_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* web */
end_comment

begin_comment
comment|/* This entry is allocated for each reference in the insn stream.  */
end_comment

begin_struct
struct|struct
name|web_entry
block|{
comment|/* Pointer to the parent in the union/find tree.  */
name|struct
name|web_entry
modifier|*
name|pred
decl_stmt|;
comment|/* Newly assigned register to the entry.  Set only for roots.  */
name|rtx
name|reg
decl_stmt|;
name|void
modifier|*
name|extra_info
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|struct
name|web_entry
modifier|*
name|unionfind_root
parameter_list|(
name|struct
name|web_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|unionfind_union
parameter_list|(
name|struct
name|web_entry
modifier|*
parameter_list|,
name|struct
name|web_entry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|union_defs
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|df_ref
modifier|*
parameter_list|,
name|struct
name|web_entry
modifier|*
parameter_list|,
name|struct
name|web_entry
modifier|*
parameter_list|,
name|bool
function_decl|(
modifier|*
name|fun
function_decl|)
parameter_list|(
name|struct
name|web_entry
modifier|*
parameter_list|,
name|struct
name|web_entry
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_DF_H */
end_comment

end_unit

