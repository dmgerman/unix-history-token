begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for dealing with stack frames, for GDB, the GNU debugger.    Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1996, 1997,    1998, 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
comment|/* Describe the saved registers of a frame.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTRA_FRAME_INFO
argument_list|)
operator|||
name|defined
argument_list|(
name|FRAME_FIND_SAVED_REGS
argument_list|)
end_if

begin_comment
comment|/* XXXX - deprecated */
end_comment

begin_struct
struct|struct
name|frame_saved_regs
block|{
comment|/* For each register R (except the SP), regs[R] is the address at        which it was saved on entry to the frame, or zero if it was not        saved on entry to this frame.  This includes special registers        such as pc and fp saved in special ways in the stack frame.         regs[SP_REGNUM] is different.  It holds the actual SP, not the        address at which it was saved.  */
name|CORE_ADDR
name|regs
index|[
name|NUM_REGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We keep a cache of stack frames, each of which is a "struct    frame_info".  The innermost one gets allocated (in    wait_for_inferior) each time the inferior stops; current_frame    points to it.  Additional frames get allocated (in    get_prev_frame) as needed, and are chained through the next    and prev fields.  Any time that the frame cache becomes invalid    (most notably when we execute something, but also if we change how    we interpret the frames (e.g. "set heuristic-fence-post" in    mips-tdep.c, or anything which reads new symbols)), we should call    reinit_frame_cache.  */
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
comment|/* Nonzero if this is a frame associated with calling a signal handler.         Set by machine-dependent code.  On some machines, if        the machine-dependent code fails to check for this, the backtrace        will look relatively normal.  For example, on the i386        #3  0x158728 in sighold ()        On other machines (e.g. rs6000), the machine-dependent code better        set this to prevent us from trying to print it like a normal frame.  */
name|int
name|signal_handler_caller
decl_stmt|;
comment|/* For each register, address of where it was saved on entry to        the frame, or zero if it was not saved on entry to this frame.        This includes special registers such as pc and fp saved in        special ways in the stack frame.  The SP_REGNUM is even more        special, the address here is the sp for the previous frame, not        the address where the sp was saved.  */
comment|/* Allocated by frame_saved_regs_zalloc () which is called /        initialized by FRAME_INIT_SAVED_REGS(). */
name|CORE_ADDR
modifier|*
name|saved_regs
decl_stmt|;
comment|/*NUM_REGS + NUM_PSEUDO_REGS*/
ifdef|#
directive|ifdef
name|EXTRA_FRAME_INFO
comment|/* XXXX - deprecated */
comment|/* Anything extra for this structure that may have been defined        in the machine dependent files. */
name|EXTRA_FRAME_INFO
endif|#
directive|endif
comment|/* Anything extra for this structure that may have been defined        in the machine dependent files. */
comment|/* Allocated by frame_obstack_alloc () which is called /        initialized by INIT_EXTRA_FRAME_INFO */
name|struct
name|frame_extra_info
modifier|*
name|extra_info
decl_stmt|;
comment|/* If dwarf2 unwind frame informations is used, this structure holds all        related unwind data.  */
name|struct
name|unwind_contect
modifier|*
name|context
decl_stmt|;
comment|/* Pointers to the next (down, inner) and previous (up, outer)        frame_info's in the frame cache.  */
name|struct
name|frame_info
modifier|*
name|next
decl_stmt|;
comment|/* down, inner */
name|struct
name|frame_info
modifier|*
name|prev
decl_stmt|;
comment|/* up, outer */
block|}
struct|;
end_struct

begin_comment
comment|/* Values for the source flag to be used in print_frame_info_base(). */
end_comment

begin_enum
enum|enum
name|print_what
block|{
comment|/* Print only the source line, like in stepi. */
name|SRC_LINE
init|=
operator|-
literal|1
block|,
comment|/* Print only the location, i.e. level, address (sometimes)        function, args, file, line, line num. */
name|LOCATION
block|,
comment|/* Print both of the above. */
name|SRC_AND_LOC
block|,
comment|/* Print location only, but always include the address. */
name|LOC_AND_ADDRESS
block|}
enum|;
end_enum

begin_comment
comment|/* Allocate additional space for appendices to a struct frame_info.    NOTE: Much of GDB's code works on the assumption that the allocated    saved_regs[] array is the size specified below.  If you try to make    that array smaller, GDB will happily walk off its end. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIZEOF_FRAME_SAVED_REGS
end_ifdef

begin_error
error|#
directive|error
literal|"SIZEOF_FRAME_SAVED_REGS can not be re-defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIZEOF_FRAME_SAVED_REGS
define|\
value|(sizeof (CORE_ADDR) * (NUM_REGS+NUM_PSEUDO_REGS))
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|frame_obstack_alloc
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|frame_saved_regs_zalloc
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the frame address from FI.  Except in the machine-dependent    *FRAME* macros, a frame address has no defined meaning other than    as a magic cookie which identifies a frame over calls to the    inferior.  The only known exception is inferior.h    (PC_IN_CALL_DUMMY) [ON_STACK]; see comments there.  You cannot    assume that a frame address contains enough information to    reconstruct the frame; if you want more than just to identify the    frame (e.g. be able to fetch variables relative to that frame),    then save the whole struct frame_info (and the next struct    frame_info, since the latter is used for fetching variables on some    machines).  */
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
comment|/* Define a default FRAME_CHAIN_VALID, in the form that is suitable for most    targets.  If FRAME_CHAIN_VALID returns zero it means that the given frame    is the outermost one and has no caller.     XXXX - both default and alternate frame_chain_valid functions are    deprecated.  New code should use dummy frames and one of the    generic functions. */
end_comment

begin_function_decl
specifier|extern
name|int
name|file_frame_chain_valid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|func_frame_chain_valid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nonnull_frame_chain_valid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_file_frame_chain_valid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_func_frame_chain_valid
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_save_dummy_frame_tos
parameter_list|(
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|create_new_frame
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flush_cached_frames
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|reinit_frame_cache
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|FRAME_FIND_SAVED_REGS
end_ifdef

begin_comment
comment|/* XXX - deprecated */
end_comment

begin_define
define|#
directive|define
name|FRAME_INIT_SAVED_REGS
parameter_list|(
name|FI
parameter_list|)
value|get_frame_saved_regs (FI, NULL)
end_define

begin_function_decl
specifier|extern
name|void
name|get_frame_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|struct
name|frame_saved_regs
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|set_current_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_prev_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_current_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_next_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_frame_block
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_current_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_selected_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|symbol
modifier|*
name|get_frame_function
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_pc_function_start
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|block_for_pc
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|block_for_pc_sect
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|asection
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|frameless_look_for_prologue
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_frame_args
parameter_list|(
name|struct
name|symbol
modifier|*
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|ui_file
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|find_relative_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_and_print_stack_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|,
name|int
name|level
parameter_list|,
name|int
name|source
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_stack_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
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
name|print_only_stack_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
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
name|show_stack_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|select_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_selected_frame
parameter_list|(
name|CORE_ADDR
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|select_and_print_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_frame_info
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
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
name|show_frame_info
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|find_saved_register
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|block_innermost_frame
parameter_list|(
name|struct
name|block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|find_frame_addr_in_frame_chain
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sigtramp_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|generic_read_register_dummy
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fp
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_push_dummy_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_pop_current_frame
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_pop_dummy_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|generic_pc_in_call_dummy
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|generic_find_dummy_frame
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_fix_call_dummy
parameter_list|(
name|char
modifier|*
name|dummy
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fun
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|gcc_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|generic_get_saved_register
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|,
name|int
parameter_list|,
name|enum
name|lval_type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_saved_register
parameter_list|(
name|char
modifier|*
name|raw_buffer
parameter_list|,
name|int
modifier|*
name|optimized
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lval
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (FRAME_H)  */
end_comment

end_unit

