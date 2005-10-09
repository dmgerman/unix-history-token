begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for dealing with stack frames, for GDB, the GNU debugger.     Copyright 1986, 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1996,    1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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
comment|/* The following is the intended naming schema for frame functions.    It isn't 100% consistent, but it is aproaching that.  Frame naming    schema:     Prefixes:     get_frame_WHAT...(): Get WHAT from the THIS frame (functionaly    equivalent to THIS->next->unwind->what)     frame_unwind_WHAT...(): Unwind THIS frame's WHAT from the NEXT    frame.     put_frame_WHAT...(): Put a value into this frame (unsafe, need to    invalidate the frame / regcache afterwards) (better name more    strongly hinting at its unsafeness)     safe_....(): Safer version of various functions, doesn't throw an    error (leave this for later?).  Returns non-zero if the fetch    succeeds.   Return a freshly allocated error message?     Suffixes:     void /frame/_WHAT(): Read WHAT's value into the buffer parameter.     ULONGEST /frame/_WHAT_unsigned(): Return an unsigned value (the    alternative is *frame_unsigned_WHAT).     LONGEST /frame/_WHAT_signed(): Return WHAT signed value.     What:     /frame/_memory* (frame, coreaddr, len [, buf]): Extract/return    *memory.     /frame/_register* (frame, regnum [, buf]): extract/return register.     CORE_ADDR /frame/_{pc,sp,...} (frame): Resume address, innner most    stack *address, ...     */
end_comment

begin_struct_decl
struct_decl|struct
name|symtab_and_line
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_unwind
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_base
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|block
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

begin_comment
comment|/* A legacy unwinder to prop up architectures using the old style    saved regs array.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|frame_unwind
modifier|*
name|legacy_saved_regs_unwind
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The frame object.  */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* The frame object's ID.  This provides a per-frame unique identifier    that can be used to relocate a `struct frame_info' after a target    resume or a frame cache destruct.  It of course assumes that the    inferior hasn't unwound the stack past that frame.  */
end_comment

begin_struct
struct|struct
name|frame_id
block|{
comment|/* The frame's stack address.  This shall be constant through out      the lifetime of a frame.  Note that this requirement applies to      not just the function body, but also the prologue and (in theory      at least) the epilogue.  Since that value needs to fall either on      the boundary, or within the frame's address range, the frame's      outer-most address (the inner-most address of the previous frame)      is used.  Watch out for all the legacy targets that still use the      function pointer register or stack pointer register.  They are      wrong.  */
name|CORE_ADDR
name|stack_addr
decl_stmt|;
comment|/* The frame's code address.  This shall be constant through out the      lifetime of the frame.  While the PC (a.k.a. resume address)      changes as the function is executed, this code address cannot.      Typically, it is set to the address of the entry point of the      frame's function (as returned by frame_func_unwind().  */
name|CORE_ADDR
name|code_addr
decl_stmt|;
comment|/* The frame's special address.  This shall be constant through out the      lifetime of the frame.  This is used for architectures that may have      frames that do not change the stack but are still distinct and have       some form of distinct identifier (e.g. the ia64 which uses a 2nd       stack for registers).  This field is treated as unordered - i.e. will      not be used in frame ordering comparisons such as frame_id_inner().      A zero in this field will be treated as a wild-card when comparing      frames for equality.  */
name|CORE_ADDR
name|special_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Methods for constructing and comparing Frame IDs.     NOTE: Given stackless functions A and B, where A calls B (and hence    B is inner-to A).  The relationships: !eq(A,B); !eq(B,A);    !inner(A,B); !inner(B,A); all hold.     This is because, while B is inner-to A, B is not strictly inner-to A.      Being stackless, they have an identical .stack_addr value, and differ     only by their unordered .code_addr and/or .special_addr values.     Because frame_id_inner is only used as a safety net (e.g.,    detect a corrupt stack) the lack of strictness is not a problem.    Code needing to determine an exact relationship between two frames    must instead use frame_id_eq and frame_id_unwind.  For instance,    in the above, to determine that A stepped-into B, the equation    "A.id != B.id&& A.id == id_unwind (B)" can be used.  */
end_comment

begin_comment
comment|/* For convenience.  All fields are zero.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|frame_id
name|null_frame_id
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Construct a frame ID.  The first parameter is the frame's constant    stack address (typically the outer-bound), and the second the    frame's constant code address (typically the entry point) (or zero,    to indicate a wild card).  The special identifier address is    defaulted to zero.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_id
name|frame_id_build
parameter_list|(
name|CORE_ADDR
name|stack_addr
parameter_list|,
name|CORE_ADDR
name|code_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Construct a special frame ID.  The first parameter is the frame's constant    stack address (typically the outer-bound), the second is the    frame's constant code address (typically the entry point) (or zero,    to indicate a wild card), and the third parameter is the frame's    special identifier address (or zero to indicate a wild card or     unused default).  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_id
name|frame_id_build_special
parameter_list|(
name|CORE_ADDR
name|stack_addr
parameter_list|,
name|CORE_ADDR
name|code_addr
parameter_list|,
name|CORE_ADDR
name|special_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns non-zero when L is a valid frame (a valid frame has a    non-zero .base).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_id_p
parameter_list|(
name|struct
name|frame_id
name|l
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns non-zero when L and R identify the same frame, or, if    either L or R have a zero .func, then the same frame base.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_id_eq
parameter_list|(
name|struct
name|frame_id
name|l
parameter_list|,
name|struct
name|frame_id
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Returns non-zero when L is strictly inner-than R (they have    different frame .bases).  Neither L, nor R can be `null'.  See note    above about frameless functions.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_id_inner
parameter_list|(
name|struct
name|frame_id
name|l
parameter_list|,
name|struct
name|frame_id
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write the internal representation of a frame ID on the specified    stream.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|fprint_frame_id
parameter_list|(
name|struct
name|ui_file
modifier|*
name|file
parameter_list|,
name|struct
name|frame_id
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For every stopped thread, GDB tracks two frames: current and    selected.  Current frame is the inner most frame of the selected    thread.  Selected frame is the one being examined by the the GDB    CLI (selected using `up', `down', ...).  The frames are created    on-demand (via get_prev_frame()) and then held in a frame cache.  */
end_comment

begin_comment
comment|/* FIXME: cagney/2002-11-28: Er, there is a lie here.  If you do the    sequence: `thread 1; up; thread 2; thread 1' you loose thread 1's    selected frame.  At present GDB only tracks the selected frame of    the current thread.  But be warned, that might change.  */
end_comment

begin_comment
comment|/* FIXME: cagney/2002-11-14: At any time, only one thread's selected    and current frame can be active.  Switching threads causes gdb to    discard all that cached frame information.  Ulgh!  Instead, current    and selected frame should be bound to a thread.  */
end_comment

begin_comment
comment|/* On demand, create the inner most frame using information found in    the inferior.  If the inner most frame can't be created, throw an    error.  */
end_comment

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

begin_comment
comment|/* Invalidates the frame cache (this function should have been called    invalidate_cached_frames).     FIXME: cagney/2002-11-28: The only difference between    flush_cached_frames() and reinit_frame_cache() is that the latter    explicitly sets the selected frame back to the current frame there    isn't any real difference (except that one delays the selection of    a new frame).  Code can instead simply rely on get_selected_frame()    to reinit's the selected frame as needed.  As for invalidating the    cache, there should be two methods one that reverts the thread's    selected frame back to current frame (for when the inferior    resumes) and one that does not (for when the user modifies the    target invalidating the frame cache).  */
end_comment

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

begin_comment
comment|/* On demand, create the selected frame and then return it.  If the    selected frame can not be created, this function throws an error.  */
end_comment

begin_comment
comment|/* FIXME: cagney/2002-11-28: At present, when there is no selected    frame, this function always returns the current (inner most) frame.    It should instead, when a thread has previously had its frame    selected (but not resumed) and the frame cache invalidated, find    and then return that thread's previously selected frame.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|get_selected_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Select a specific frame.  NULL, apparently implies re-select the    inner most frame.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|select_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a FRAME, return the next (more inner, younger) or previous    (more outer, older) frame.  */
end_comment

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
name|get_next_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a frame's ID, relocate the frame.  Returns NULL if the frame    is not found.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|frame_find_by_id
parameter_list|(
name|struct
name|frame_id
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Base attributes of a frame: */
end_comment

begin_comment
comment|/* The frame's `resume' address.  Where the program will resume in    this frame.     This replaced: frame->pc; */
end_comment

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

begin_comment
comment|/* An address (not necessarily alligned to an instruction boundary)    that falls within THIS frame's code block.     When a function call is the last statement in a block, the return    address for the call may land at the start of the next block.    Similarly, if a no-return function call is the last statement in    the function, the return address may end up pointing beyond the    function, and possibly at the start of the next function.     These methods make an allowance for this.  For call frames, this    function returns the frame's PC-1 which "should" be an address in    the frame's block.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_address_in_block
parameter_list|(
name|struct
name|frame_info
modifier|*
name|this_frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_unwind_address_in_block
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The frame's inner-most bound.  AKA the stack-pointer.  Confusingly    known as top-of-stack.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_sp
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
name|frame_sp_unwind
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Following on from the `resume' address.  Return the entry point    address of the function containing that resume address, or zero if    that function isn't known.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_func_unwind
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_func
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Closely related to the resume address, various symbol table    attributes that are determined by the PC.  Note that for a normal    frame, the PC refers to the resume address after the return, and    not the call instruction.  In such a case, the address is adjusted    so that it (approximatly) identifies the call site (and not return    site).     NOTE: cagney/2002-11-28: The frame cache could be used to cache the    computed value.  Working on the assumption that the bottle-neck is    in the single step code, and that code causes the frame cache to be    constantly flushed, caching things in a frame is probably of little    benefit.  As they say `show us the numbers'.     NOTE: cagney/2002-11-28: Plenty more where this one came from:    find_frame_block(), find_frame_partial_function(),    find_frame_symtab(), find_frame_function().  Each will need to be    carefully considered to determine if the real intent was for it to    apply to the PC or the adjusted PC.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|find_frame_sal
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|struct
name|symtab_and_line
modifier|*
name|sal
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the frame base (what ever that is) (DEPRECATED).     Old code was trying to use this single method for two conflicting    purposes.  Such code needs to be updated to use either of:     get_frame_id: A low level frame unique identifier, that consists of    both a stack and a function address, that can be used to uniquely    identify a frame.  This value is determined by the frame's    low-level unwinder, the stack part [typically] being the    top-of-stack of the previous frame, and the function part being the    function's start address.  Since the correct identification of a    frameless function requires both the a stack and function address,    the old get_frame_base method was not sufficient.     get_frame_base_address: get_frame_locals_address:    get_frame_args_address: A set of high-level debug-info dependant    addresses that fall within the frame.  These addresses almost    certainly will not match the stack address part of a frame ID (as    returned by get_frame_base).     This replaced: frame->frame; */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_base
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the per-frame unique identifer.  Can be used to relocate a    frame after a frame cache flush (and other similar operations).  If    FI is NULL, return the null_frame_id.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_id
name|get_frame_id
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assuming that a frame is `normal', return its base-address, or 0 if    the information isn't available.  NOTE: This address is really only    meaningful to the frame's high-level debug info.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_base_address
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assuming that a frame is `normal', return the base-address of the    local variables, or 0 if the information isn't available.  NOTE:    This address is really only meaningful to the frame's high-level    debug info.  Typically, the argument and locals share a single    base-address.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_locals_address
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assuming that a frame is `normal', return the base-address of the    parameter list, or 0 if that information isn't available.  NOTE:    This address is really only meaningful to the frame's high-level    debug info.  Typically, the argument and locals share a single    base-address.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|get_frame_args_address
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The frame's level: 0 for innermost, 1 for its caller, ...; or -1    for an invalid frame).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_relative_level
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the frame's type.  Some are real, some are signal    trampolines, and some are completely artificial (dummy).  */
end_comment

begin_enum
enum|enum
name|frame_type
block|{
comment|/* The frame's type hasn't yet been defined.  This is a catch-all      for legacy code that uses really strange technicques, such as      deprecated_set_frame_type, to set the frame's type.  New code      should not use this value.  */
name|UNKNOWN_FRAME
block|,
comment|/* A true stack frame, created by the target program during normal      execution.  */
name|NORMAL_FRAME
block|,
comment|/* A fake frame, created by GDB when performing an inferior function      call.  */
name|DUMMY_FRAME
block|,
comment|/* In a signal handler, various OSs handle this in various ways.      The main thing is that the frame may be far from normal.  */
name|SIGTRAMP_FRAME
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|enum
name|frame_type
name|get_frame_type
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2002-11-10: Some targets want to directly mark a    frame as being of a specific type.  This shouldn't be necessary.    PC_IN_SIGTRAMP() indicates a SIGTRAMP_FRAME and    DEPRECATED_PC_IN_CALL_DUMMY() indicates a DUMMY_FRAME.  I suspect    the real problem here is that get_prev_frame() only sets    initialized after DEPRECATED_INIT_EXTRA_FRAME_INFO as been called.    Consequently, some targets found that the frame's type was wrong    and tried to fix it.  The correct fix is to modify get_prev_frame()    so that it initializes the frame's type before calling any other    functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_set_frame_type
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|,
name|enum
name|frame_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unwind the stack frame so that the value of REGNUM, in the previous    (up, older) frame is returned.  If VALUEP is NULL, don't    fetch/compute the value.  Instead just return the location of the    value.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_register_unwind
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
modifier|*
name|optimizedp
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lvalp
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|int
modifier|*
name|realnump
parameter_list|,
name|void
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch a register from this, or unwind a register from the next    frame.  Note that the get_frame methods are wrappers to    frame->next->unwind.  They all [potentially] throw an error if the    fetch fails.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_unwind_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|get_frame_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|frame_unwind_register_signed
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|get_frame_register_signed
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ULONGEST
name|frame_unwind_register_unsigned
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ULONGEST
name|get_frame_register_unsigned
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use frame_unwind_register_signed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_unwind_unsigned_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|ULONGEST
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the value of the register that belongs to this FRAME.  This    function is a wrapper to the call sequence ``frame_unwind_register    (get_next_frame (FRAME))''.  As per frame_register_unwind(), if    VALUEP is NULL, the registers value is not fetched/computed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
modifier|*
name|optimizedp
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lvalp
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|int
modifier|*
name|realnump
parameter_list|,
name|void
modifier|*
name|valuep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The reverse.  Store a register value relative to the specified    frame.  Note: this call makes the frame's state undefined.  The    register and frame caches must be flushed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|put_frame_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Map between a frame register number and its name.  A frame register    space is a superset of the cooked register space --- it also    includes builtin registers.  If NAMELEN is negative, use the NAME's    length when doing the comparison.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_map_name_to_regnum
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|frame_map_regnum_to_name
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Unwind the PC.  Strictly speaking return the resume address of the    calling frame.  For GDB, `pc' is the resume address and not a    specific register.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_pc_unwind
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Discard the specified frame.  Restoring the registers to the state    of the caller.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_pop
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return memory from the specified frame.  A frame knows its thread /    LWP and hence can find its way down to a target.  The assumption    here is that the current and previous frame share a common address    space.     If the memory read fails, these methods throw an error.     NOTE: cagney/2003-06-03: Should there be unwind versions of these    methods?  That isn't clear.  Can code, for instance, assume that    this and the previous frame's memory or architecture are identical?    If architecture / memory changes are always separated by special    adaptor frames this should be ok.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|get_frame_memory
parameter_list|(
name|struct
name|frame_info
modifier|*
name|this_frame
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|LONGEST
name|get_frame_memory_signed
parameter_list|(
name|struct
name|frame_info
modifier|*
name|this_frame
parameter_list|,
name|CORE_ADDR
name|memaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ULONGEST
name|get_frame_memory_unsigned
parameter_list|(
name|struct
name|frame_info
modifier|*
name|this_frame
parameter_list|,
name|CORE_ADDR
name|memaddr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return this frame's architecture.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch
modifier|*
name|get_frame_arch
parameter_list|(
name|struct
name|frame_info
modifier|*
name|this_frame
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|/* Allocate zero initialized memory from the frame cache obstack.    Appendices to the frame info (such as the unwind cache) should    allocate memory using this method.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|frame_obstack_zalloc
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_OBSTACK_ZALLOC
parameter_list|(
name|TYPE
parameter_list|)
value|((TYPE *) frame_obstack_zalloc (sizeof (TYPE)))
end_define

begin_define
define|#
directive|define
name|FRAME_OBSTACK_CALLOC
parameter_list|(
name|NUMBER
parameter_list|,
name|TYPE
parameter_list|)
value|((TYPE *) frame_obstack_zalloc ((NUMBER) * sizeof (TYPE)))
end_define

begin_comment
comment|/* If legacy_frame_chain_valid() returns zero it means that the given    frame is the outermost one and has no caller.     This method has been superseeded by the per-architecture    frame_unwind_pc() (returns 0 to indicate an invalid return address)    and per-frame this_id() (returns a NULL frame ID to indicate an    invalid frame).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_frame_chain_valid
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
parameter_list|,
name|CORE_ADDR
modifier|*
name|addr_in_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the `struct block' that belongs to the selected thread's    selected frame.  If the inferior has no state, return NULL.     NOTE: cagney/2002-11-29:     No state?  Does the inferior have any execution state (a core file    does, an executable does not).  At present the code tests    `target_has_stack' but I'm left wondering if it should test    `target_has_registers' or, even, a merged target_has_state.     Should it look at the most recently specified SAL?  If the target    has no state, should this function try to extract a block from the    most recently selected SAL?  That way `list foo' would give it some    sort of reference point.  Then again, perhaphs that would confuse    things.     Calls to this function can be broken down into two categories: Code    that uses the selected block as an additional, but optional, data    point; Code that uses the selected block as a prop, when it should    have the relevant frame/block/pc explicitly passed in.     The latter can be eliminated by correctly parameterizing the code,    the former though is more interesting.  Per the "address" command,    it occures in the CLI code and makes it possible for commands to    work, even when the inferior has no state.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|block
modifier|*
name|get_selected_block
parameter_list|(
name|CORE_ADDR
modifier|*
name|addr_in_block
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
name|get_pc_function_start
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|legacy_frameless_look_for_prologue
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

begin_comment
comment|/* NOTE: cagney/2002-09-13: There is no need for this function.   */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|deprecated_read_register_dummy
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

begin_comment
comment|/* NOTE: cagney/2002-06-26: Targets should no longer use this    function.  Instead, the contents of a dummy frames registers can be    obtained by applying: frame_register_unwind to the dummy frame; or    frame_register_unwind() to the next outer frame.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|deprecated_generic_find_dummy_frame
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The DEPRECATED_GET_SAVED_REGISTER architecture interface is    entirely redundant.  New architectures should implement per-frame    unwinders (ref "frame-unwind.h").  */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_generic_get_saved_register
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
name|generic_save_call_dummy_addr
parameter_list|(
name|CORE_ADDR
name|lo
parameter_list|,
name|CORE_ADDR
name|hi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2003-02-02: Should be deprecated or replaced with a    function called get_frame_register_p().  This slightly weird (and    older) variant of get_frame_register() returns zero (indicating the    register is unavailable) if either: the register isn't cached; or    the register has been optimized out.  Problem is, neither check is    exactly correct.  A register can't be optimized out (it may not    have been saved as part of a function call); The fact that a    register isn't in the register cache doesn't mean that the register    isn't available (it could have been fetched from memory).  */
end_comment

begin_function_decl
specifier|extern
name|int
name|frame_register_read
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* From stack.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|args_info
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|locals_info
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
function_decl|(
modifier|*
name|selected_frame_level_changed_hook
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|return_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* NOTE: cagney/2002-11-27:     You might think that the below global can simply be replaced by a    call to either get_selected_frame() or select_frame().     Unfortunately, it isn't that easy.     The relevant code needs to be audited to determine if it is    possible (or pratical) to instead pass the applicable frame in as a    parameter.  For instance, DEPRECATED_DO_REGISTERS_INFO() relied on    the deprecated_selected_frame global, while its replacement,    PRINT_REGISTERS_INFO(), is parameterized with the selected frame.    The only real exceptions occure at the edge (in the CLI code) where    user commands need to pick up the selected frame before proceeding.     This is important.  GDB is trying to stamp out the hack:     saved_frame = deprecated_selected_frame;    deprecated_selected_frame = ...;    hack_using_global_selected_frame ();    deprecated_selected_frame = saved_frame;     Take care!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|deprecated_selected_frame
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NOTE: drow/2003-09-06:     This function is "a step sideways" for uses of deprecated_selected_frame.    They should be fixed as above, but meanwhile, we needed a solution for    cases where functions are called with a NULL frame meaning either "the    program is not running" or "use the selected frame".  Lazy building of    deprecated_selected_frame confuses the situation, because now    deprecated_selected_frame can be NULL even when the inferior is running.     This function calls get_selected_frame if the inferior should have a    frame, or returns NULL otherwise.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|deprecated_safe_get_selected_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create a frame using the specified BASE and PC.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|create_new_frame
parameter_list|(
name|CORE_ADDR
name|base
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create/access the frame's `extra info'.  The extra info is used by    older code to store information such as the analyzed prologue.  The    zalloc() should only be called by the INIT_EXTRA_INFO method.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_extra_info
modifier|*
name|frame_extra_info_zalloc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|frame_extra_info
modifier|*
name|get_frame_extra_info
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Create/access the frame's `saved_regs'.  The saved regs are used by    older code to store the address of each register (except for    SP_REGNUM where the value of the register in the previous frame is    stored).  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
modifier|*
name|frame_saved_regs_zalloc
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
modifier|*
name|deprecated_get_frame_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2002-12-06: Has the PC in the current frame changed?    "infrun.c", Thanks to DECR_PC_AFTER_BREAK, can change the PC after    the initial frame create.  This puts things back in sync.     This replaced: frame->pc = ....; */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_update_frame_pc_hack
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2002-12-18: Has the frame's base changed?  Or to be    more exact, was that initial guess at the frame's base as returned    by deprecated_read_fp() wrong?  If it was, fix it.  This shouldn't    be necessary since the code should be getting the frame's base    correct from the outset.     This replaced: frame->frame = ....; */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_update_frame_base_hack
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|CORE_ADDR
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: cagney/2003-01-05: Allocate a frame, along with the    saved_regs and extra_info.  Set up cleanups for all three.  Same as    for deprecated_frame_xmalloc, targets are calling this when    creating a scratch `struct frame_info'.  The frame overhaul makes    this unnecessary since all frame queries are parameterized with a    common cache parameter and a frame.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|deprecated_frame_xmalloc_with_cleanup
parameter_list|(
name|long
name|sizeof_saved_regs
parameter_list|,
name|long
name|sizeof_extra_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return non-zero if the architecture is relying on legacy frame    code.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|legacy_frame_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
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

