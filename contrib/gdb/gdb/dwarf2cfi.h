begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Stack unwinding code based on dwarf2 frame info for GDB, the GNU debugger.    Copyright 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DWARF2CFI_H
end_ifndef

begin_define
define|#
directive|define
name|DWARF2CFI_H
end_define

begin_comment
comment|/* Return the frame address.  */
end_comment

begin_function_decl
name|CORE_ADDR
name|cfi_read_fp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Store the frame address.  */
end_comment

begin_function_decl
name|void
name|cfi_write_fp
parameter_list|(
name|CORE_ADDR
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Restore the machine to the state it had before the current frame    was created.  */
end_comment

begin_function_decl
name|void
name|cfi_pop_frame
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine the address of the calling function's frame.  */
end_comment

begin_function_decl
name|CORE_ADDR
name|cfi_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Sets the pc of the frame.  */
end_comment

begin_function_decl
name|void
name|cfi_init_frame_pc
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize unwind context informations of the frame.  */
end_comment

begin_function_decl
name|void
name|cfi_init_extra_frame_info
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obtain return address of the frame.  */
end_comment

begin_function_decl
name|CORE_ADDR
name|cfi_get_ra
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find register number REGNUM relative to FRAME and put its    (raw) contents in *RAW_BUFFER.  Set *OPTIMIZED if the variable    was optimized out (and thus can't be fetched).  If the variable    was fetched from memory, set *ADDRP to where it was fetched from,    otherwise it was fetched from a register.     The argument RAW_BUFFER must point to aligned memory.  */
end_comment

begin_function_decl
name|void
name|cfi_get_saved_register
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

begin_comment
comment|/*  Return the register that the function uses for a frame pointer,     plus any necessary offset to be applied to the register before     any frame pointer offsets.  */
end_comment

begin_function_decl
name|void
name|cfi_virtual_frame_pointer
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|int
modifier|*
name|frame_regnum
parameter_list|,
name|LONGEST
modifier|*
name|frame_offset
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

