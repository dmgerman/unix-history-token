begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define per-register tables for data flow info and register allocation.    Copyright (C) 1987, 1993, 1994, 1995, 1996, 1997, 1998,    1999, 2000 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_define
define|#
directive|define
name|REG_BYTES
parameter_list|(
name|R
parameter_list|)
value|mode_size[(int) GET_MODE (R)]
end_define

begin_comment
comment|/* When you only have the mode of a pseudo register before it has a hard    register chosen for it, this reports the size of each hard register    a pseudo in such a mode would get allocated to.  A target may    override this.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGMODE_NATURAL_SIZE
end_ifndef

begin_define
define|#
directive|define
name|REGMODE_NATURAL_SIZE
parameter_list|(
name|MODE
parameter_list|)
value|UNITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SMALL_REGISTER_CLASSES
end_ifndef

begin_define
define|#
directive|define
name|SMALL_REGISTER_CLASSES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Maximum register number used in this function, plus one.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|max_regno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Register information indexed by register number */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|reg_info_def
block|{
comment|/* fields set by reg_scan */
name|int
name|first_uid
decl_stmt|;
comment|/* UID of first insn to use (REG n) */
name|int
name|last_uid
decl_stmt|;
comment|/* UID of last insn to use (REG n) */
name|int
name|last_note_uid
decl_stmt|;
comment|/* UID of last note to use (REG n) */
comment|/* fields set by reg_scan& flow_analysis */
name|int
name|sets
decl_stmt|;
comment|/* # of times (REG n) is set */
comment|/* fields set by flow_analysis */
name|int
name|refs
decl_stmt|;
comment|/* # of times (REG n) is used or set */
name|int
name|freq
decl_stmt|;
comment|/* # estimated frequency (REG n) is used or set */
name|int
name|deaths
decl_stmt|;
comment|/* # of times (REG n) dies */
name|int
name|live_length
decl_stmt|;
comment|/* # of instructions (REG n) is live */
name|int
name|calls_crossed
decl_stmt|;
comment|/* # of calls (REG n) is live across */
name|int
name|basic_block
decl_stmt|;
comment|/* # of basic blocks (REG n) is used in */
name|char
name|changes_mode
decl_stmt|;
comment|/* whether (SUBREG (REG n)) exists and  				   is illegal.  */
block|}
name|reg_info
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|varray_type
name|reg_n_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by n, gives number of times (REG n) is used or set.  */
end_comment

begin_define
define|#
directive|define
name|REG_N_REFS
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->refs)
end_define

begin_comment
comment|/* Estimate frequency of references to register N.  */
end_comment

begin_define
define|#
directive|define
name|REG_FREQ
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->freq)
end_define

begin_comment
comment|/* The weights for each insn varries from 0 to REG_FREQ_BASE.     This constant does not need to be high, as in infrequently executed    regions we want to count instructions equivalently to optimize for    size instead of speed.  */
end_comment

begin_define
define|#
directive|define
name|REG_FREQ_MAX
value|1000
end_define

begin_comment
comment|/* Compute register frequency from the BB frequency.  When optimizing for size,    or profile driven feedback is available and the function is never executed,    frequency is always equivalent.  Otherwise rescale the basic block    frequency.  */
end_comment

begin_define
define|#
directive|define
name|REG_FREQ_FROM_BB
parameter_list|(
name|bb
parameter_list|)
value|(optimize_size				      \ 			      || (flag_branch_probabilities		      \&& !ENTRY_BLOCK_PTR->count)		      \ 			      ? REG_FREQ_MAX				      \ 			      : ((bb)->frequency * REG_FREQ_MAX / BB_FREQ_MAX)\ 			      ? ((bb)->frequency * REG_FREQ_MAX / BB_FREQ_MAX)\ 			      : 1)
end_define

begin_comment
comment|/* Indexed by n, gives number of times (REG n) is set.    ??? both regscan and flow allocate space for this.  We should settle    on just copy.  */
end_comment

begin_define
define|#
directive|define
name|REG_N_SETS
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->sets)
end_define

begin_comment
comment|/* Indexed by N, gives number of insns in which register N dies.    Note that if register N is live around loops, it can die    in transitions between basic blocks, and that is not counted here.    So this is only a reliable indicator of how many regions of life there are    for registers that are contained in one basic block.  */
end_comment

begin_define
define|#
directive|define
name|REG_N_DEATHS
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->deaths)
end_define

begin_comment
comment|/* Indexed by N; says whether a pseudo register N was ever used    within a SUBREG that changes the mode of the reg in some way    that is illegal for a given class (usually floating-point)    of registers.  */
end_comment

begin_define
define|#
directive|define
name|REG_CHANGES_MODE
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->changes_mode)
end_define

begin_comment
comment|/* Get the number of consecutive words required to hold pseudo-reg N.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_REGNO_SIZE
parameter_list|(
name|N
parameter_list|)
define|\
value|((GET_MODE_SIZE (PSEUDO_REGNO_MODE (N)) + UNITS_PER_WORD - 1)		\    / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Get the number of bytes required to hold pseudo-reg N.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_REGNO_BYTES
parameter_list|(
name|N
parameter_list|)
define|\
value|GET_MODE_SIZE (PSEUDO_REGNO_MODE (N))
end_define

begin_comment
comment|/* Get the machine mode of pseudo-reg N.  */
end_comment

begin_define
define|#
directive|define
name|PSEUDO_REGNO_MODE
parameter_list|(
name|N
parameter_list|)
value|GET_MODE (regno_reg_rtx[N])
end_define

begin_comment
comment|/* Indexed by N, gives number of CALL_INSNS across which (REG n) is live.  */
end_comment

begin_define
define|#
directive|define
name|REG_N_CALLS_CROSSED
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->calls_crossed)
end_define

begin_comment
comment|/* Total number of instructions at which (REG n) is live.    The larger this is, the less priority (REG n) gets for    allocation in a hard register (in global-alloc).    This is set in flow.c and remains valid for the rest of the compilation    of the function; it is used to control register allocation.     local-alloc.c may alter this number to change the priority.     Negative values are special.    -1 is used to mark a pseudo reg which has a constant or memory equivalent    and is used infrequently enough that it should not get a hard register.    -2 is used to mark a pseudo reg for a parameter, when a frame pointer    is not required.  global.c makes an allocno for this but does    not try to assign a hard register to it.  */
end_comment

begin_define
define|#
directive|define
name|REG_LIVE_LENGTH
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->live_length)
end_define

begin_comment
comment|/* Vector of substitutions of register numbers,    used to map pseudo regs into hardware regs.     This can't be folded into reg_n_info without changing all of the    machine dependent directories, since the reload functions    in the machine dependent files access it.  */
end_comment

begin_decl_stmt
specifier|extern
name|short
modifier|*
name|reg_renumber
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vector indexed by hardware reg    saying whether that reg is ever used.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|regs_ever_live
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vector indexed by hardware reg giving its name.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|reg_names
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* For each hard register, the widest mode object that it can contain.    This will be a MODE_INT mode if the register can hold integers.  Otherwise    it will be a MODE_FLOAT or a MODE_CC mode, whichever is valid for the    register.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|reg_raw_mode
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Vector indexed by regno; gives uid of first insn using that reg.    This is computed by reg_scan for use by cse and loop.    It is sometimes adjusted for subsequent changes during loop,    but not adjusted by cse even if cse invalidates it.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_FIRST_UID
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->first_uid)
end_define

begin_comment
comment|/* Vector indexed by regno; gives uid of last insn using that reg.    This is computed by reg_scan for use by cse and loop.    It is sometimes adjusted for subsequent changes during loop,    but not adjusted by cse even if cse invalidates it.    This is harmless since cse won't scan through a loop end.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_LAST_UID
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->last_uid)
end_define

begin_comment
comment|/* Similar, but includes insns that mention the reg in their notes.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_LAST_NOTE_UID
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_REG (reg_n_info, N)->last_note_uid)
end_define

begin_comment
comment|/* List made of EXPR_LIST rtx's which gives pairs of pseudo registers    that have to go in the same hard reg.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|regs_may_share
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flag set by local-alloc or global-alloc if they decide to allocate    something in a call-clobbered register.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|caller_save_needed
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Predicate to decide whether to give a hard reg to a pseudo which    is referenced REFS times and would need to be saved and restored    around a call CALLS times.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CALLER_SAVE_PROFITABLE
end_ifndef

begin_define
define|#
directive|define
name|CALLER_SAVE_PROFITABLE
parameter_list|(
name|REFS
parameter_list|,
name|CALLS
parameter_list|)
value|(4 * (CALLS)< (REFS))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On most machines a register class is likely to be spilled if it    only has one register.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLASS_LIKELY_SPILLED_P
end_ifndef

begin_define
define|#
directive|define
name|CLASS_LIKELY_SPILLED_P
parameter_list|(
name|CLASS
parameter_list|)
value|(reg_class_size[(int) (CLASS)] == 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Select a register mode required for caller save of hard regno REGNO.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HARD_REGNO_CALLER_SAVE_MODE
end_ifndef

begin_define
define|#
directive|define
name|HARD_REGNO_CALLER_SAVE_MODE
parameter_list|(
name|REGNO
parameter_list|,
name|NREGS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|choose_hard_reg_mode (REGNO, NREGS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Registers that get partially clobbered by a call in a given mode.     These must not be call used registers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HARD_REGNO_CALL_PART_CLOBBERED
end_ifndef

begin_define
define|#
directive|define
name|HARD_REGNO_CALL_PART_CLOBBERED
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allocate reg_n_info tables */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|allocate_reg_info
name|PARAMS
argument_list|(
operator|(
name|size_t
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

