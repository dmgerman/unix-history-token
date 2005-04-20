begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Traditional frame unwind support, for GDB the GNU Debugger.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRAD_FRAME_H
end_ifndef

begin_define
define|#
directive|define
name|TRAD_FRAME_H
end_define

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* A traditional saved regs table, indexed by REGNUM, encoding where    the value of REGNUM for the previous frame can be found in this    frame.     The table is initialized with an identity encoding (ADDR == -1,    REALREG == REGNUM) indicating that the value of REGNUM in the    previous frame can be found in register REGNUM (== REALREG) in this    frame.     The initial encoding can then be changed:     Modify ADDR (REALREG>= 0, ADDR != -1) to indicate that the value    of register REGNUM in the previous frame can be found in memory at    ADDR in this frame (addr_p, !realreg_p, !value_p).     Modify REALREG (REALREG>= 0, ADDR == -1) to indicate that the    value of register REGNUM in the previous frame is found in register    REALREG in this frame (!addr_p, realreg_p, !value_p).     Call trad_frame_set_value (REALREG == -1) to indicate that the    value of register REGNUM in the previous frame is found in ADDR    (!addr_p, !realreg_p, value_p).     Call trad_frame_set_unknown (REALREG == -2) to indicate that the    register's value is not known.  */
end_comment

begin_struct
struct|struct
name|trad_frame_saved_reg
block|{
name|LONGEST
name|addr
decl_stmt|;
comment|/* A CORE_ADDR fits in a longest.  */
name|int
name|realreg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Encode REGNUM value in the trad-frame.  */
end_comment

begin_function_decl
name|void
name|trad_frame_set_value
parameter_list|(
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
parameter_list|,
name|int
name|regnum
parameter_list|,
name|LONGEST
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mark REGNUM as unknown.  */
end_comment

begin_function_decl
name|void
name|trad_frame_set_unknown
parameter_list|(
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convenience functions, return non-zero if the register has been    encoded as specified.  */
end_comment

begin_function_decl
name|int
name|trad_frame_value_p
parameter_list|(
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trad_frame_addr_p
parameter_list|(
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|trad_frame_realreg_p
parameter_list|(
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a freshly allocated (and initialized) trad_frame array.  */
end_comment

begin_function_decl
name|struct
name|trad_frame_saved_reg
modifier|*
name|trad_frame_alloc_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given the trad_frame info, return the location of the specified    register.  */
end_comment

begin_function_decl
name|void
name|trad_frame_prev_register
parameter_list|(
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|,
name|struct
name|trad_frame_saved_reg
name|this_saved_regs
index|[]
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
name|realregp
parameter_list|,
name|void
modifier|*
name|bufferp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

