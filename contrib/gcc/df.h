begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Form lists of pseudo register references for autoinc optimization    for GNU compiler.  This is part of flow optimization.    Copyright (C) 1999, 2000, 2001, 2003 Free Software Foundation, Inc.    Contributed by Michael P. Hayes (m.hayes@elec.canterbury.ac.nz)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|DF_RD
value|1
end_define

begin_comment
comment|/* Reaching definitions.  */
end_comment

begin_define
define|#
directive|define
name|DF_RU
value|2
end_define

begin_comment
comment|/* Reaching uses.  */
end_comment

begin_define
define|#
directive|define
name|DF_LR
value|4
end_define

begin_comment
comment|/* Live registers.  */
end_comment

begin_define
define|#
directive|define
name|DF_DU_CHAIN
value|8
end_define

begin_comment
comment|/* Def-use chain.  */
end_comment

begin_define
define|#
directive|define
name|DF_UD_CHAIN
value|16
end_define

begin_comment
comment|/* Use-def chain.  */
end_comment

begin_define
define|#
directive|define
name|DF_REG_INFO
value|32
end_define

begin_comment
comment|/* Register info.  */
end_comment

begin_define
define|#
directive|define
name|DF_RD_CHAIN
value|64
end_define

begin_comment
comment|/* Reg-def chain.  */
end_comment

begin_define
define|#
directive|define
name|DF_RU_CHAIN
value|128
end_define

begin_comment
comment|/* Reg-use chain.  */
end_comment

begin_define
define|#
directive|define
name|DF_ALL
value|255
end_define

begin_define
define|#
directive|define
name|DF_HARD_REGS
value|1024
end_define

begin_comment
comment|/* Mark hard registers.  */
end_comment

begin_define
define|#
directive|define
name|DF_EQUIV_NOTES
value|2048
end_define

begin_comment
comment|/* Mark uses present in EQUIV/EQUAL notes.  */
end_comment

begin_define
define|#
directive|define
name|DF_FOR_REGALLOC
value|4096
end_define

begin_comment
comment|/* If called for the register allocator.  */
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

begin_comment
comment|/* Link on a def-use or use-def chain.  */
end_comment

begin_struct
struct|struct
name|df_link
block|{
name|struct
name|df_link
modifier|*
name|next
decl_stmt|;
name|struct
name|ref
modifier|*
name|ref
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|df_ref_flags
block|{
comment|/* Read-modify-write refs generate both a use and a def and        these are marked with this flag to show that they are not        independent.  */
name|DF_REF_READ_WRITE
init|=
literal|1
block|,
comment|/* This flag is set on register references inside a subreg on        machines which have CANNOT_CHANGE_MODE_CLASS.        Note, that this flag can also be set on df_refs representing        the REG itself (i.e., one might not see the subreg anyore).        Also note, that this flag is set also for hardreg refs, i.e.,        you must check yourself if it's a pseudo.  */
name|DF_REF_MODE_CHANGE
init|=
literal|2
block|,
comment|/* This flag is set, if we stripped the subreg from the reference.        In this case we must make conservative guesses, at what the        outer mode was.  */
name|DF_REF_STRIPPED
init|=
literal|4
block|,
comment|/* This flag is set during register allocation if it's okay for     the reference's INSN to have one of its operands replaced with a     memory reference.  */
name|DF_REF_MEM_OK
init|=
literal|8
block|}
enum|;
end_enum

begin_comment
comment|/* Define a register reference structure.  One of these is allocated    for every register reference (use or def).  Note some register    references (e.g., post_inc, subreg) generate both a def and a use.  */
end_comment

begin_struct
struct|struct
name|ref
block|{
name|rtx
name|reg
decl_stmt|;
comment|/* The register referenced.  */
name|rtx
name|insn
decl_stmt|;
comment|/* Insn containing ref.  */
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
comment|/* Head of def-use or use-def chain.  */
name|unsigned
name|int
name|id
decl_stmt|;
comment|/* Ref index.  */
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
block|}
struct|;
end_struct

begin_comment
comment|/* One of these structures is allocated for every insn.  */
end_comment

begin_struct
struct|struct
name|insn_info
block|{
name|struct
name|df_link
modifier|*
name|defs
decl_stmt|;
comment|/* Head of insn-def chain.  */
name|struct
name|df_link
modifier|*
name|uses
decl_stmt|;
comment|/* Head of insn-use chain.  */
comment|/* ???? The following luid field should be considered private so that      we can change it on the fly to accommodate new insns?  */
name|int
name|luid
decl_stmt|;
comment|/* Logical UID.  */
block|}
struct|;
end_struct

begin_comment
comment|/* One of these structures is allocated for every reg.  */
end_comment

begin_struct
struct|struct
name|reg_info
block|{
name|struct
name|df_link
modifier|*
name|defs
decl_stmt|;
comment|/* Head of reg-def chain.  */
name|struct
name|df_link
modifier|*
name|uses
decl_stmt|;
comment|/* Head of reg-use chain.  */
name|int
name|lifetime
decl_stmt|;
name|int
name|n_defs
decl_stmt|;
name|int
name|n_uses
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* One of these structures is allocated for every basic block.  */
end_comment

begin_struct
struct|struct
name|bb_info
block|{
comment|/* Reaching def bitmaps have def_id elements.  */
name|bitmap
name|rd_kill
decl_stmt|;
name|bitmap
name|rd_gen
decl_stmt|;
name|bitmap
name|rd_in
decl_stmt|;
name|bitmap
name|rd_out
decl_stmt|;
comment|/* Reaching use bitmaps have use_id elements.  */
name|bitmap
name|ru_kill
decl_stmt|;
name|bitmap
name|ru_gen
decl_stmt|;
name|bitmap
name|ru_in
decl_stmt|;
name|bitmap
name|ru_out
decl_stmt|;
comment|/* Live variable bitmaps have n_regs elements.  */
name|bitmap
name|lr_def
decl_stmt|;
name|bitmap
name|lr_use
decl_stmt|;
name|bitmap
name|lr_in
decl_stmt|;
name|bitmap
name|lr_out
decl_stmt|;
name|int
name|rd_valid
decl_stmt|;
name|int
name|ru_valid
decl_stmt|;
name|int
name|lr_valid
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|df
block|{
name|int
name|flags
decl_stmt|;
comment|/* Indicates what's recorded.  */
name|struct
name|bb_info
modifier|*
name|bbs
decl_stmt|;
comment|/* Basic block table.  */
name|struct
name|ref
modifier|*
modifier|*
name|defs
decl_stmt|;
comment|/* Def table, indexed by def_id.  */
name|struct
name|ref
modifier|*
modifier|*
name|uses
decl_stmt|;
comment|/* Use table, indexed by use_id.  */
name|struct
name|ref
modifier|*
modifier|*
name|reg_def_last
decl_stmt|;
comment|/* Indexed by regno.  */
name|struct
name|reg_info
modifier|*
name|regs
decl_stmt|;
comment|/* Regs table, index by regno.  */
name|unsigned
name|int
name|reg_size
decl_stmt|;
comment|/* Size of regs table.  */
name|struct
name|insn_info
modifier|*
name|insns
decl_stmt|;
comment|/* Insn table, indexed by insn UID.  */
name|unsigned
name|int
name|insn_size
decl_stmt|;
comment|/* Size of insn table.  */
name|unsigned
name|int
name|def_id
decl_stmt|;
comment|/* Next def ID.  */
name|unsigned
name|int
name|def_size
decl_stmt|;
comment|/* Size of def table.  */
name|unsigned
name|int
name|n_defs
decl_stmt|;
comment|/* Size of def bitmaps.  */
name|unsigned
name|int
name|use_id
decl_stmt|;
comment|/* Next use ID.  */
name|unsigned
name|int
name|use_size
decl_stmt|;
comment|/* Size of use table.  */
name|unsigned
name|int
name|n_uses
decl_stmt|;
comment|/* Size of use bitmaps.  */
name|unsigned
name|int
name|n_bbs
decl_stmt|;
comment|/* Number of basic blocks.  */
name|unsigned
name|int
name|n_regs
decl_stmt|;
comment|/* Number of regs.  */
name|unsigned
name|int
name|def_id_save
decl_stmt|;
comment|/* Saved next def ID.  */
name|unsigned
name|int
name|use_id_save
decl_stmt|;
comment|/* Saved next use ID.  */
name|bitmap
name|insns_modified
decl_stmt|;
comment|/* Insns that (may) have changed.  */
name|bitmap
name|bbs_modified
decl_stmt|;
comment|/* Blocks that (may) have changed.  */
name|bitmap
name|all_blocks
decl_stmt|;
comment|/* All blocks in CFG.  */
comment|/* The sbitmap vector of dominators or NULL if not computed.      Ideally, this should be a pointer to a CFG object.  */
name|sbitmap
modifier|*
name|dom
decl_stmt|;
name|int
modifier|*
name|dfs_order
decl_stmt|;
comment|/* DFS order -> block number.  */
name|int
modifier|*
name|rc_order
decl_stmt|;
comment|/* Reverse completion order -> block number.  */
name|int
modifier|*
name|rts_order
decl_stmt|;
comment|/* Reverse top sort order -> block number.  */
name|int
modifier|*
name|inverse_rc_map
decl_stmt|;
comment|/* Block number -> reverse completion order.  */
name|int
modifier|*
name|inverse_dfs_map
decl_stmt|;
comment|/* Block number -> DFS order.  */
name|int
modifier|*
name|inverse_rts_map
decl_stmt|;
comment|/* Block number -> reverse top-sort order.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|df_map
block|{
name|rtx
name|old
decl_stmt|;
name|rtx
name|new
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DF_BB_INFO
parameter_list|(
name|REFS
parameter_list|,
name|BB
parameter_list|)
value|(&REFS->bbs[(BB)->index])
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
value|REGNO (DF_REF_REAL_REG (REF))
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
value|(BLOCK_FOR_INSN ((REF)->insn))
end_define

begin_define
define|#
directive|define
name|DF_REF_BBNO
parameter_list|(
name|REF
parameter_list|)
value|(BLOCK_FOR_INSN ((REF)->insn)->index)
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
value|((REF)&& ! DF_REF_REG_DEF_P (REF))
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
value|((DF)->regs[REGNUM].defs ? (DF)->regs[REGNUM].defs->ref : 0)
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
value|((DF)->regs[REGNUM].uses ? (DF)->regs[REGNUM].uses->ref : 0)
end_define

begin_define
define|#
directive|define
name|DF_REGNO_FIRST_BB
parameter_list|(
name|DF
parameter_list|,
name|REGNUM
parameter_list|)
define|\
value|(DF_REGNO_FIRST_DEF (DF, REGNUM) \ ? DF_REF_BB (DF_REGNO_FIRST_DEF (DF, REGNUM)) : 0)
end_define

begin_define
define|#
directive|define
name|DF_REGNO_LAST_BB
parameter_list|(
name|DF
parameter_list|,
name|REGNUM
parameter_list|)
define|\
value|(DF_REGNO_LAST_USE (DF, REGNUM) \ ? DF_REF_BB (DF_REGNO_LAST_USE (DF, REGNUM)) : 0)
end_define

begin_comment
comment|/* Macros to access the elements within the insn_info structure table.  */
end_comment

begin_define
define|#
directive|define
name|DF_INSN_LUID
parameter_list|(
name|DF
parameter_list|,
name|INSN
parameter_list|)
value|((DF)->insns[INSN_UID (INSN)].luid)
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
value|((DF)->insns[INSN_UID (INSN)].defs)
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
value|((DF)->insns[INSN_UID (INSN)].uses)
end_define

begin_comment
comment|/* Functions to build and analyse dataflow information.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|df
modifier|*
name|df_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_analyse
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|df_finish
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
name|df_dump
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to modify insns.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|df_insn_modify
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|df_insn_delete
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|df_pattern_emit_before
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|df_jump_pattern_emit_after
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|df_pattern_emit_after
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|df_insn_move_before
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_reg_replace
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|bitmap
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
name|df_ref_reg_replace
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|ref
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
name|int
name|df_ref_remove
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|struct
name|ref
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_insn_reg_replace
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
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
name|df_insn_mem_replace
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
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
name|struct
name|ref
modifier|*
name|df_bb_def_use_swap
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions to query dataflow information.  */
end_comment

begin_function_decl
specifier|extern
name|basic_block
name|df_regno_bb
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
name|int
name|df_reg_lifetime
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_reg_global_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_insn_regno_def_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
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
name|int
name|df_insn_dominates_all_uses_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_insn_dominates_uses_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_bb_reg_live_start_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_bb_reg_live_end_p
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|df_bb_regs_lives_compare
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
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
name|df_bb_single_def_use_insn_find
parameter_list|(
name|struct
name|df
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions for debugging from GDB.  */
end_comment

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
name|ref
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

begin_comment
comment|/* Meet over any path (UNION) or meet over all paths (INTERSECTION).  */
end_comment

begin_enum
enum|enum
name|df_confluence_op
block|{
name|DF_UNION
block|,
name|DF_INTERSECTION
block|}
enum|;
end_enum

begin_comment
comment|/* Dataflow direction.  */
end_comment

begin_enum
enum|enum
name|df_flow_dir
block|{
name|DF_FORWARD
block|,
name|DF_BACKWARD
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|transfer_function_sbitmap
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|sbitmap
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|transfer_function_bitmap
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|bitmap
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|iterative_dataflow_sbitmap
parameter_list|(
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|enum
name|df_flow_dir
parameter_list|,
name|enum
name|df_confluence_op
parameter_list|,
name|transfer_function_sbitmap
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iterative_dataflow_bitmap
parameter_list|(
name|bitmap
modifier|*
parameter_list|,
name|bitmap
modifier|*
parameter_list|,
name|bitmap
modifier|*
parameter_list|,
name|bitmap
modifier|*
parameter_list|,
name|bitmap
parameter_list|,
name|enum
name|df_flow_dir
parameter_list|,
name|enum
name|df_confluence_op
parameter_list|,
name|transfer_function_bitmap
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|read_modify_subreg_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

end_unit

