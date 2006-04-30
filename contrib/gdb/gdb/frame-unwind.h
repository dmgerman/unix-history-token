begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for a frame unwinder, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_UNWIND_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_UNWIND_H
value|1
end_define

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_id
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_unwind
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|gdbarch
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|"frame.h"
end_include

begin_comment
comment|/* For enum frame_type.  */
end_comment

begin_comment
comment|/* The following unwind functions assume a chain of frames forming the    sequence: (outer) prev<-> this<-> next (inner).  All the    functions are called with called with the next frame's `struct    frame_info' and and this frame's prologue cache.     THIS frame's register values can be obtained by unwinding NEXT    frame's registers (a recursive operation).     THIS frame's prologue cache can be used to cache information such    as where this frame's prologue stores the previous frame's    registers.  */
end_comment

begin_comment
comment|/* Assuming the frame chain: (outer) prev<-> this<-> next (inner);    use the NEXT frame, and its register unwind method, to determine    the frame ID of THIS frame.     A frame ID provides an invariant that can be used to re-identify an    instance of a frame.  It is a combination of the frame's `base' and    the frame's function's code address.     Traditionally, THIS frame's ID was determined by examining THIS    frame's function's prologue, and identifying the register/offset    used as THIS frame's base.     Example: An examination of THIS frame's prologue reveals that, on    entry, it saves the PC(+12), SP(+8), and R1(+4) registers    (decrementing the SP by 12).  Consequently, the frame ID's base can    be determined by adding 12 to the THIS frame's stack-pointer, and    the value of THIS frame's SP can be obtained by unwinding the NEXT    frame's SP.     THIS_PROLOGUE_CACHE can be used to share any prolog analysis data    with the other unwind methods.  Memory for that cache should be    allocated using frame_obstack_zalloc().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|frame_this_id_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|,
name|void
modifier|*
modifier|*
name|this_prologue_cache
parameter_list|,
name|struct
name|frame_id
modifier|*
name|this_id
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Assuming the frame chain: (outer) prev<-> this<-> next (inner);    use the NEXT frame, and its register unwind method, to unwind THIS    frame's registers (returning the value of the specified register    REGNUM in the previous frame).     Traditionally, THIS frame's registers were unwound by examining    THIS frame's function's prologue and identifying which registers    that prolog code saved on the stack.     Example: An examination of THIS frame's prologue reveals that, on    entry, it saves the PC(+12), SP(+8), and R1(+4) registers    (decrementing the SP by 12).  Consequently, the value of the PC    register in the previous frame is found in memory at SP+12, and    THIS frame's SP can be obtained by unwinding the NEXT frame's SP.     Why not pass in THIS_FRAME?  By passing in NEXT frame and THIS    cache, the supplied parameters are consistent with the sibling    function THIS_ID.     Can the code call ``frame_register (get_prev_frame (NEXT_FRAME))''?    Won't the call frame_register (THIS_FRAME) be faster?  Well,    ignoring the possability that the previous frame does not yet    exist, the ``frame_register (FRAME)'' function is expanded to    ``frame_register_unwind (get_next_frame (FRAME)'' and hence that    call will expand to ``frame_register_unwind (get_next_frame    (get_prev_frame (NEXT_FRAME)))''.  Might as well call    ``frame_register_unwind (NEXT_FRAME)'' directly.     THIS_PROLOGUE_CACHE can be used to share any prolog analysis data    with the other unwind methods.  Memory for that cache should be    allocated using frame_obstack_zalloc().  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|frame_prev_register_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|,
name|void
modifier|*
modifier|*
name|this_prologue_cache
parameter_list|,
name|int
name|prev_regnum
parameter_list|,
name|int
modifier|*
name|optimized
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
end_typedef

begin_struct
struct|struct
name|frame_unwind
block|{
comment|/* The frame's type.  Should this instead be a collection of      predicates that test the frame for various attributes?  */
name|enum
name|frame_type
name|type
decl_stmt|;
comment|/* Should an attribute indicating the frame's address-in-block go      here?  */
name|frame_this_id_ftype
modifier|*
name|this_id
decl_stmt|;
name|frame_prev_register_ftype
modifier|*
name|prev_register
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Given the NEXT frame, take a wiff of THIS frame's registers (namely    the PC and attributes) and if it is the applicable unwinder return    the unwind methods, or NULL if it is not.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|struct
name|frame_unwind
modifier|*
function_decl|(
name|frame_unwind_sniffer_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Add a frame sniffer to the list.  The predicates are polled in the    order that they are appended.  The initial list contains the dummy    frame sniffer.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_unwind_append_sniffer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|frame_unwind_sniffer_ftype
modifier|*
name|sniffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Iterate through the next frame's sniffers until one returns with an    unwinder implementation.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|frame_unwind
modifier|*
name|frame_unwind_find_by_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

