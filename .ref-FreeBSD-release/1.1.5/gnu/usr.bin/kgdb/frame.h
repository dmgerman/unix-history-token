begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for dealing with stack frames, for GDB, the GNU debugger.    Copyright (C) 1986, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that frame.h requires param.h! */
end_comment

begin_comment
comment|/*  * FRAME is the type of the identifier of a specific stack frame.  It  * is a pointer to the frame cache item corresponding to this frame.  * Please note that frame id's are *not* constant over calls to the  * inferior.  Use frame addresses, which are.  *  * FRAME_ADDR is the type of the address of a specific frame.  I  * cannot imagine a case in which this would not be CORE_ADDR, so  * maybe it's silly to give it it's own type.  Life's rough.  *  * FRAME_FP is a macro which converts from a frame identifier into a  * frame_address.  *  * FRAME_INFO_ID is a macro which "converts" from a frame info pointer  * to a frame id.  This is here in case I or someone else decides to  * change the FRAME type again.  *  * This file and blockframe.c are the only places which are allowed to  * use the equivalence between FRAME and struct frame_info *.  EXCEPTION:  * value.h uses CORE_ADDR instead of FRAME_ADDR because the compiler  * will accept that in the absense of this file.  */
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
comment|/*  * Caching structure for stack frames.  This is also the structure  * used for extended info about stack frames.  May add more to this  * structure as it becomes necessary.  *  * Note that the first entry in the cache will always refer to the  * innermost executing frame.  This value should be set (is it?  * Check) in something like normal_stop.  */
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
comment|/* The stack frame that the user has specified for commands to act on.    Note that one cannot assume this is the address of valid data.  */
end_comment

begin_decl_stmt
specifier|extern
name|FRAME
name|selected_frame
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_frame_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_prev_frame_info
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FRAME
name|create_new_frame
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_frame_saved_regs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FRAME
name|get_prev_frame
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FRAME
name|get_current_frame
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FRAME
name|get_next_frame
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_frame_block
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_current_block
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_selected_block
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|get_frame_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|get_pc_function
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* In stack.c */
end_comment

begin_function_decl
specifier|extern
name|FRAME
name|find_relative_frame
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generic pointer value indicating "I don't know."  */
end_comment

begin_define
define|#
directive|define
name|Frame_unknown
value|(CORE_ADDR)-1
end_define

end_unit

