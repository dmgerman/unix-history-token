begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for a frame base, for GDB, the GNU debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_BASE_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_BASE_H
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
name|frame_base
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

begin_comment
comment|/* Assuming the frame chain: (outer) prev<-> this<-> next (inner);    and that this is a `normal frame'; use the NEXT frame, and its    register unwind method, to determine the address of THIS frame's    `base'.     The exact meaning of `base' is highly dependant on the type of the    debug info.  It is assumed that dwarf2, stabs, ... will each    provide their own methods.     A typical implmentation will return the same value for base,    locals-base and args-base.  That value, however, will likely be    different to the frame ID's stack address.  */
end_comment

begin_comment
comment|/* A generic base address.  */
end_comment

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|frame_this_base_ftype
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
name|this_base_cache
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The base address of the frame's local variables.  */
end_comment

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|frame_this_locals_ftype
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
name|this_base_cache
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* The base address of the frame's arguments / parameters.  */
end_comment

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|frame_this_args_ftype
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
name|this_base_cache
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|frame_base
block|{
comment|/* If non-NULL, a low-level unwinder that shares its implementation      with this high-level frame-base method.  */
specifier|const
name|struct
name|frame_unwind
modifier|*
name|unwind
decl_stmt|;
name|frame_this_base_ftype
modifier|*
name|this_base
decl_stmt|;
name|frame_this_locals_ftype
modifier|*
name|this_locals
decl_stmt|;
name|frame_this_args_ftype
modifier|*
name|this_args
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Given the NEXT frame, return the frame base methods for THIS frame,    or NULL if it can't handle THIS frame.  */
end_comment

begin_typedef
typedef|typedef
specifier|const
name|struct
name|frame_base
modifier|*
function_decl|(
name|frame_base_sniffer_ftype
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
comment|/* Append a frame base sniffer to the list.  The sniffers are polled    in the order that they are appended.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_base_append_sniffer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|frame_base_sniffer_ftype
modifier|*
name|sniffer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Set the default frame base.  If all else fails, this one is    returned.  If this isn't set, the default is to use legacy code    that uses things like the frame ID's base (ulgh!).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|frame_base_set_default
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|struct
name|frame_base
modifier|*
name|def
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Iterate through the list of frame base handlers until one returns    an implementation.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|frame_base
modifier|*
name|frame_base_find_by_frame
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

