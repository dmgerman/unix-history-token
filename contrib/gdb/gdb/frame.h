begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for dealing with stack frames, for GDB, the GNU debugger.    Copyright 1986, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_H
value|1
end_define

begin_comment
comment|/* We keep a cache of stack frames, each of which is a "struct    frame_info".  The innermost one gets allocated (in    wait_for_inferior) each time the inferior stops; current_frame    points to it.  Additional frames get allocated (in    get_prev_frame_info) as needed, and are chained through the next    and prev fields.  Any time that the frame cache becomes invalid    (most notably when we execute something, but also if we change how    we interpret the frames (e.g. "set heuristic-fence-post" in    mips-tdep.c, or anything which reads new symbols)), we should call    reinit_frame_cache.  */
end_comment

begin_struct
struct|struct
name|frame_info
block|{
comment|/* Nominal address of the frame described.  See comments at FRAME_FP        about what this means outside the *FRAME* macros; in the *FRAME*        macros, it can mean whatever makes most sense for this machine.  */
name|CORE_ADDR
name|frame
decl_stmt|;
comment|/* Address at which execution is occurring in this frame.        For the innermost frame, it's the current pc.        For other frames, it is a pc saved in the next frame.  */
name|CORE_ADDR
name|pc
decl_stmt|;
comment|/* Nonzero if this is a frame associated with calling a signal handler.         Set by machine-dependent code.  On some machines, if        the machine-dependent code fails to check for this, the backtrace        will look relatively normal.  For example, on the i386          #3  0x158728 in sighold ()        On other machines (e.g. rs6000), the machine-dependent code better        set this to prevent us from trying to print it like a normal frame.  */
name|int
name|signal_handler_caller
decl_stmt|;
comment|/* Anything extra for this structure that may have been defined        in the machine dependent files. */
ifdef|#
directive|ifdef
name|EXTRA_FRAME_INFO
name|EXTRA_FRAME_INFO
endif|#
directive|endif
comment|/* We should probably also store a "struct frame_saved_regs" here.        This is already done by some machines (e.g. config/m88k/tm-m88k.h)        but there is no reason it couldn't be general.  */
comment|/* Pointers to the next and previous frame_info's in the frame cache.  */
name|struct
name|frame_info
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Describe the saved registers of a frame.  */
end_comment

begin_struct
struct|struct
name|frame_saved_regs
block|{
comment|/* For each register, address of where it was saved on entry to        the frame, or zero if it was not saved on entry to this frame.        This includes special registers such as pc and fp saved in        special ways in the stack frame.  The SP_REGNUM is even more        special, the address here is the sp for the next frame, not the        address where the sp was saved.  */
name|CORE_ADDR
name|regs
index|[
name|NUM_REGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Return the frame address from FR.  Except in the machine-dependent    *FRAME* macros, a frame address has no defined meaning other than    as a magic cookie which identifies a frame over calls to the    inferior.  The only known exception is inferior.h    (PC_IN_CALL_DUMMY) [ON_STACK]; see comments there.  You cannot    assume that a frame address contains enough information to    reconstruct the frame; if you want more than just to identify the    frame (e.g. be able to fetch variables relative to that frame),    then save the whole struct frame_info (and the next struct    frame_info, since the latter is used for fetching variables on some    machines).  */
end_comment

begin_define
define|#
directive|define
name|FRAME_FP
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
end_define

begin_comment
comment|/* Define a default FRAME_CHAIN_VALID, in the form that is suitable for most    targets.  If FRAME_CHAIN_VALID returns zero it means that the given frame    is the outermost one and has no caller.     If a particular target needs a different definition, then it can override    the definition here by providing one in the tm file. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_CHAIN_VALID
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FRAME_CHAIN_VALID_ALTERNATE
argument_list|)
end_if

begin_comment
comment|/* Use the alternate method of avoiding running up off the end of the frame    chain or following frames back into the startup code.  See the comments    in objfiles.h. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|((chain) != 0					\&& !inside_main_func ((thisframe) -> pc)	\&& !inside_entry_func ((thisframe) -> pc))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|((chain) != 0					\&& !inside_entry_file (FRAME_SAVED_PC (thisframe)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FRAME_CHAIN_VALID_ALTERNATE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FRAME_CHAIN_VALID */
end_comment

begin_comment
comment|/* The stack frame that the user has specified for commands to act on.    Note that one cannot assume this is the address of valid data.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|selected_frame
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Level of the selected frame:    0 for innermost, 1 for its caller, ...    or -1 for frame specified by address with no defined level.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|selected_frame_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_prev_frame_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|create_new_frame
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flush_cached_frames
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
name|reinit_frame_cache
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
name|get_frame_saved_regs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
expr|struct
name|frame_saved_regs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_current_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_prev_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_current_frame
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
name|struct
name|frame_info
modifier|*
name|get_next_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|get_frame_block
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|get_current_block
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
name|struct
name|block
modifier|*
name|get_selected_block
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
name|struct
name|symbol
modifier|*
name|get_frame_function
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|get_frame_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|get_pc_function_start
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|block
modifier|*
name|block_for_pc
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|frameless_look_for_prologue
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_frame_args
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
expr|struct
name|frame_info
operator|*
operator|,
name|int
operator|,
name|GDB_FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|find_relative_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_stack_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
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
name|select_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|record_selected_frame
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_frame_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|find_saved_register
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|block_innermost_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|block
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|find_frame_addr_in_frame_chain
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|sigtramp_saved_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (FRAME_H)  */
end_comment

end_unit

