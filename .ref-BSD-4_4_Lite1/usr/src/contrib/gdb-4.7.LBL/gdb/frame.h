begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for dealing with stack frames, for GDB, the GNU debugger.    Copyright 1986, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* FRAME is the type of the identifier of a specific stack frame.  It    is a pointer to the frame cache item corresponding to this frame.    Please note that frame id's are *not* constant over calls to the    inferior.  Use frame addresses, which are.       FRAME_ADDR is the type of the address of a specific frame.  I    cannot imagine a case in which this would not be CORE_ADDR, so    maybe it's silly to give it it's own type.  Life's rough.       FRAME_FP is a macro which converts from a frame identifier into a    frame_address.       FRAME_INFO_ID is a macro which "converts" from a frame info pointer    to a frame id.  This is here in case I or someone else decides to    change the FRAME type again.       This file and blockframe.c are the only places which are allowed to    use the equivalence between FRAME and struct frame_info *.  EXCEPTION:    value.h uses CORE_ADDR instead of FRAME_ADDR because the compiler    will accept that in the absence of this file.    FIXME:  Prototypes in other files make use of the equivalence between            "FRAME" and "struct frame_info *" and the equivalence between 	   CORE_ADDR and FRAME_ADDR.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|frame_info
modifier|*
name|FRAME
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CORE_ADDR
name|FRAME_ADDR
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FRAME_FP
parameter_list|(
name|fr
parameter_list|)
value|((fr)->frame)
end_define

begin_define
define|#
directive|define
name|FRAME_INFO_ID
parameter_list|(
name|f
parameter_list|)
value|(f)
end_define

begin_comment
comment|/* Caching structure for stack frames.  This is also the structure    used for extended info about stack frames.  May add more to this    structure as it becomes necessary.       Note that the first entry in the cache will always refer to the    innermost executing frame.  This value is set in wait_for_inferior.  */
end_comment

begin_struct
struct|struct
name|frame_info
block|{
comment|/* Nominal address of the frame described.  */
name|FRAME_ADDR
name|frame
decl_stmt|;
comment|/* Address at which execution is occurring in this frame.        For the innermost frame, it's the current pc.        For other frames, it is a pc saved in the next frame.  */
name|CORE_ADDR
name|pc
decl_stmt|;
comment|/* The frame called by the frame we are describing, or 0.        This may be set even if there isn't a frame called by the one        we are describing (.->next == 0); in that case it is simply the        bottom of this frame */
name|FRAME_ADDR
name|next_frame
decl_stmt|;
comment|/* Anything extra for this structure that may have been defined        in the machine depedent files. */
ifdef|#
directive|ifdef
name|EXTRA_FRAME_INFO
name|EXTRA_FRAME_INFO
endif|#
directive|endif
comment|/* Pointers to the next and previous frame_info's in this stack.  */
name|FRAME
name|next
decl_stmt|,
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
comment|/* For each register, address of where it was saved on entry to the frame,        or zero if it was not saved on entry to this frame.  */
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
comment|/* If we encounter a request to use base register addressing of variables    on a machine for which gdb has not been configured to support such    access, report the failure to support this access mode. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_GET_BASEREG_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_GET_BASEREG_VALUE
parameter_list|(
name|frame
parameter_list|,
name|regno
parameter_list|)
define|\
value|(error ("Missing valid method for finding contents of base register."),0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The stack frame that the user has specified for commands to act on.    Note that one cannot assume this is the address of valid data.  */
end_comment

begin_decl_stmt
specifier|extern
name|FRAME
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
name|get_frame_info
name|PARAMS
argument_list|(
operator|(
name|FRAME
operator|)
argument_list|)
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
name|FRAME
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FRAME
name|create_new_frame
name|PARAMS
argument_list|(
operator|(
name|FRAME_ADDR
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
name|FRAME
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FRAME
name|get_prev_frame
name|PARAMS
argument_list|(
operator|(
name|FRAME
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FRAME
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
name|FRAME
name|get_next_frame
name|PARAMS
argument_list|(
operator|(
name|FRAME
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
name|FRAME
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
name|FRAME
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
name|FRAME
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
name|FRAME
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
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FRAME
name|find_relative_frame
name|PARAMS
argument_list|(
operator|(
name|FRAME
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
name|FRAME
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
name|FRAME
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
name|FRAME_ADDR
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
name|FRAME
operator|,
name|int
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

